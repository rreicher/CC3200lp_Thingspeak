//******************************************************************************
//  Copyright (C) 2021  romain reicher
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
//  About
//  ---------------------------------------------------------------------------
//
//  ---------------------------------------------------------------------------
//
//  Date     :
//  Revision :
//*****************************************************************************

/* Compiler standard includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Simplelink includes */
#include "device.h"

/* Driverlib includes */
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_ints.h"
#include "interrupt.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
#include "timer.h"
#include "utils.h"

/* User application includes */
#include "app_conf.h"
#include "app_cloud.h"

/* Freertos/ti-rtos includes */
#include "osi.h"

/* Common interface includes */
#ifndef NOTERM
#include "uart_if.h"
#endif
#include "gpio_if.h"
#include "timer_if.h"
#include "network_if.h"
#include "udma_if.h"
#include "i2c_if.h"
#include "pin_mux_config.h"

/* CC3200 LaunchPad includes */
#include "tmp006drv.h"

/* Private define */
#define APPLICATION_VERSION     "1.0.0"
#define APP_NAME                "CC3200-Launchxl Thingspeak"

#define SLEEP_TIME              60                      // Approximatively in seconds
#define SEC_TO_LOOP(x)          ((80000000 / 5) * x)    // CPU cycle waste vs Freq computation

#define SPAWN_TASK_PRIORITY     9
#define OSI_STACK_SIZE          6000

#define TX_BUFF_SIZE            512
#define RX_BUFF_SIZE            512

#define HOST_NAME               "api.thingspeak.com"
#define HOST_PORT               80

#define THINGSPEAK_APIKEY       "ERT5ERGTIB5ER6DC"
#define THINGSPEAK_HEADER       "GET /update?api_key=%s"
#define THINGSPEAK_FIELD        "&field%d=%u"

/* Private variables */
SlSecParams_t SecurityParams = {0};

char acSendBuff[TX_BUFF_SIZE];
char acRecvbuff[RX_BUFF_SIZE];

/* Private functions prototypes */
static void DisplayBanner(char * AppName);
static long ConnectWlanAP(void);
static int CreateTCPConnection(unsigned long ulDestinationIP);
static void ThingspeakSendMulti(char * apiKey, int nbField, uint16_t value[]);

/*
 * Application startup display on UART
 * @param: Pointer to string to display
 * @return: None
 */
static void DisplayBanner(char * AppName)
{
    UART_PRINT("\n\n\n\r");
    UART_PRINT("\t\t *************************************************\n\r");
    UART_PRINT("\t\t      CC3200 %s Application       \n\r", AppName);
    UART_PRINT("\t\t *************************************************\n\r");
    UART_PRINT("\n\n\n\r");
}

/*
 * Connect device to defined Access Point
 * @param: None
 * @return: 0 if success, otherwise negative number if error.
 */
static long ConnectWlanAP(void)
{
    /* Reset The state of the machine */
    Network_IF_ResetMCUStateMachine();

    /* Start the driver */
    Network_IF_InitDriver(ROLE_STA);

    /* Initialize AP security params */
    SecurityParams.Key = (signed char *) CC_SECURITY_KEY;
    SecurityParams.KeyLen = strlen(CC_SECURITY_KEY);
    SecurityParams.Type = CC_SECURITY_TYPE;

    /* Connect to the Access Point */
    return (Network_IF_ConnectAP(CC_SSID_NAME, SecurityParams));
}

/*
 *  Function to create a TCP Socket connection to specified IP adress
 *  @param: Host IP Adress
 *  @return: Socket number if success, otherwise negative number if error
 */
static int CreateTCPConnection(unsigned long ulDestinationIP)
{
    int iLenorError;
    int iSockIDorError;
    SlSockAddrIn_t sAddr;
    int iAddrSize;

    sAddr.sin_family = SL_AF_INET;
    sAddr.sin_port = sl_Htons(80);

    /* Reorder the bytes of a 32-bit unsigned value endian */
    sAddr.sin_addr.s_addr = sl_Htonl(ulDestinationIP);

    iAddrSize = sizeof(SlSockAddrIn_t);

    /* Create TCP socket */
    iSockIDorError = sl_Socket(SL_AF_INET, SL_SOCK_STREAM, 0);

    if (iSockIDorError < 0)
    {
        DBG_PRINT("Error: Error Number = %d .\n\r", iSockIDorError );
        return iSockIDorError;
    }

    /* Connect with server */
    iLenorError = sl_Connect(iSockIDorError, ( SlSockAddr_t *)&sAddr, iAddrSize);
    if( iLenorError < 0 )
    {
        // error
        DBG_PRINT("Error: Error Number = %d\n\r", iLenorError );
        return iLenorError;
    }

    DBG_PRINT("Socket Id: %d was created.", iSockIDorError);

    return iSockIDorError;
}


/*
 * Function to send datas to Thingspeak using Post method
 * @param: Thingspeak Channel API Key
 * @param: Number of field value to send
 * @param: Array of Field Value to send
 * @return: None
 */
static void ThingspeakSendMulti(char * apiKey, int nbField, uint16_t value[])
{
    int iSocketDesc;
    long ulStatus;
    unsigned long ulDestinationIP;
    int iRetVal;
    int l_contentLen;

//    char local_buf[512] = {0};
    char fieldBuff[64] = {0};

    while (1)
    {
        /* Get the serverhost IP address using the DNS lookup */
        ulStatus = Network_IF_GetHostIP(HOST_NAME, &ulDestinationIP);
        if (ulStatus < 0)
        {
            DBG_PRINT("Thingspeak DNS Lookup Error. \n\r");
            break;
        }

        /* Create a TCP connection to the server */
        iSocketDesc = CreateTCPConnection(ulDestinationIP);
        if (iSocketDesc < 0)
        {
            DBG_PRINT("TCP Socket Creation Error.\n\r");
            break ;
        }

        /* Construct Rest API Command */
        sprintf(acSendBuff, THINGSPEAK_HEADER, apiKey);

        /* Add and concatenate Field[n] value */
        for (uint8_t i = 0; i < nbField; i++)
        {
            sprintf(fieldBuff, THINGSPEAK_FIELD, i + 1, value[i]);
            strcat(acSendBuff, fieldBuff);
        }
        /* Terminate Command */
        strcat(acSendBuff, "\r\n");
        /* Get command lenght */
        l_contentLen = strlen (acSendBuff);
        /* Display complete command string */
        DBG_PRINT(acSendBuff);

        /* Send the HTTP POST string to the open TCP/IP socket */
        DBG_PRINT("Sent HTTP POST request\n\r");
        iRetVal = sl_Send(iSocketDesc, acSendBuff, l_contentLen, 0);
        if (iRetVal < 0)
        {
            DBG_PRINT("TCP Socket Writing Data Error\n\r");
            break ;
        }
        else
        {
            DBG_PRINT("Return value: %d\n\r", iRetVal);
        }

#if (0)
        MAP_UtilsDelay(80000000 *2);
#endif

        /* Store the reply from the server in buffer. */
        DBG_PRINT("Received HTTP POST response data\n\r");

        iRetVal = sl_Recv(iSocketDesc, &acRecvbuff[0], sizeof(acRecvbuff), 0);

        if (iRetVal < 0)
        {
           DBG_PRINT("TCP Socket Receiving Data Error\n\r");
           break ;
        }
        else
        {
           DBG_PRINT("Return value: %d\n\r", iRetVal);
           acRecvbuff[sizeof(acRecvbuff) - 1] = 0;
           DBG_PRINT(acRecvbuff);
        }

        /* Close the TCP socket */
        close(iSocketDesc);
        DBG_PRINT("Socket Thingspeak closed\n\r");
        break;
    }

    /* Close connection and De-Init Driver */
    Network_IF_DeInitDriver();
    DBG_PRINT("Update Data End\n\r");
}

/*
 * Task function implementing Thingspeak features
 * @param: None
 * @return: None
 */
void mainTask(void *pvParameters)
{
    long apConnection;
    float fCurrentTemp;
    uint16_t valArray[4];
    char cTempChar[5];
    UART_PRINT("Main Task Entry\n\r");

    while (1)
    {
        /* Connect to defined Wifi Access Point */
        apConnection = ConnectWlanAP();

        if (apConnection < 0)
        {
            DBG_PRINT("Can't connect to %s AP\n\r", CC_SSID_NAME);
            break;
        }

        /* Read TMP006 temperature */
        DBG_PRINT("Read Temperature\r\n");
        TMP006DrvGetTemp(&fCurrentTemp);
        /* Compute temperature */
        float cCurrentTemp = (((fCurrentTemp - 32) * 5) / 9) - 5;
        sprintf(cTempChar, "%.2f", cCurrentTemp);
        DBG_PRINT("TMP006 Temperature: %s\n\r", cTempChar);

        /* Get SNTP Time */
        //TODO

        valArray[0] = (int16_t)cCurrentTemp;
        valArray[1] = valArray[0] + 10;

        /* Connect and Post 2 integer datas to Thingspeak Channel */
        ThingspeakSendMulti((char *)THINGSPEAK_APIKEY, 2, valArray);

        /* Suspend task for a specified time in ms */
#ifdef USE_FREERTOS
        osi_Sleep(60000);
#else
        MAP_UtilsDelay(SEC_TO_LOOP(SLEEP_TIME));  // UtilsDelay block CPU execution, do not use it with RTOS
#endif
        }
}

/*
 * Program entry function
 * @param: None
 * @return: None
 */
void appTskCreate(void)
{
    long lRetVal = -1;

    /* Init DMA */
    UDMAInit();
#ifndef NOTERM
    /* Init UART */
    InitTerm();
#endif
    /* Display Application Banner */
    DisplayBanner(APP_NAME);

    /* Init I2C */
    lRetVal = I2C_IF_Open(I2C_MASTER_MODE_FST);
    if(lRetVal < 0)
    {
        ERR_PRINT(lRetVal);
        DBG_PRINT("I2C Init Error\n\r");
    }
    else
    {
        /* Init Temprature Sensor */
        lRetVal = TMP006DrvOpen();
        if(lRetVal < 0)
        {
            ERR_PRINT(lRetVal);
            DBG_PRINT("TMP006 Sensor Error\n\r");
        }
        else
        {
            DBG_PRINT("TMP006 Init Done\n\r");
        }
    }

    /* Start the SimpleLink Host task */
    lRetVal = VStartSimpleLinkSpawnTask(SPAWN_TASK_PRIORITY);
    if (lRetVal < 0)
    {
        ERR_PRINT(lRetVal);
        LOOP_FOREVER();
    }

    /* Start the Thingspeak task */
    osi_TaskCreate(mainTask,
                  (const signed char *)"mainTaskEntry",
                  OSI_STACK_SIZE,
                  NULL,
                  1,
                  NULL);
}



