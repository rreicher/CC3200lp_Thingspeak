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

#pragma once

#ifdef    __cplusplus
extern "C" {
#endif

#define CC_SSID_NAME          "Your AP SSID"         /* AP SSID */
#define CC_SECURITY_TYPE      SL_SEC_TYPE_WPA_WPA2     /* Security type (OPEN or WEP or WPA */
#define CC_SECURITY_KEY       "Your Password" /* Password of the secured AP */
#define CC_SSID_LEN_MAX       32
#define CC_BSSID_LEN_MAX      6

#ifdef NOTERM
#define UART_PRINT(x,...)
#define DBG_PRINT(x,...)
#define ERR_PRINT(x)
#else
#define UART_PRINT Report
#define DBG_PRINT  Report
#define ERR_PRINT(x) Report("Error [%d] at line [%d] in function [%s]  \n\r", x ,__LINE__, __FUNCTION__)
#endif

// Loop forever, user can change it as per application's requirement
#define LOOP_FOREVER()                                              \
                    {                                               \
                        while(1);                                   \
                    }

// check the error code and handle it
#define ASSERT_ON_ERROR(error_code)                                 \
                                    {                               \
                                         if(error_code < 0)         \
                                         {                          \
                                             ERR_PRINT(error_code); \
                                             return error_code;     \
                                         }                          \
                                    }

#define SPAWN_TASK_PRIORITY     9
#define SL_STOP_TIMEOUT         200
#define UNUSED(x)               ((x) = (x))
#define SUCCESS                 0
#define FAILURE                 -1


// Status bits - These are used to set/reset the corresponding bits in
// given variable
typedef enum {
    STATUS_BIT_NWP_INIT = 0, // If this bit is set: Network Processor is
                             // powered up

    STATUS_BIT_CONNECTION,   // If this bit is set: the device is connected to
                             // the AP or client is connected to device (AP)

    STATUS_BIT_IP_LEASED,    // If this bit is set: the device has leased IP to
                             // any connected client

    STATUS_BIT_IP_AQUIRED,   // If this bit is set: the device has acquired an IP

    STATUS_BIT_SMARTCONFIG_START, // If this bit is set: the SmartConfiguration
                                  // process is started from SmartConfig app

    STATUS_BIT_P2P_DEV_FOUND,    // If this bit is set: the device (P2P mode)
                                 // found any p2p-device in scan

    STATUS_BIT_P2P_REQ_RECEIVED, // If this bit is set: the device (P2P mode)
                                 // found any p2p-negotiation request

    STATUS_BIT_CONNECTION_FAILED, // If this bit is set: the device(P2P mode)
                                  // connection to client(or reverse way) is failed

    STATUS_BIT_PING_DONE         // If this bit is set: the device has completed
                                 // the ping operation

} e_StatusBits;


#define CLR_STATUS_BIT_ALL(status_variable)  (status_variable = 0)
#define SET_STATUS_BIT(status_variable, bit) status_variable |= (1<<(bit))
#define CLR_STATUS_BIT(status_variable, bit) status_variable &= ~(1<<(bit))
#define CLR_STATUS_BIT_ALL(status_variable)   (status_variable = 0)
#define GET_STATUS_BIT(status_variable, bit) (0 != (status_variable & (1<<(bit))))

#define IS_NW_PROCSR_ON(status_variable)     GET_STATUS_BIT(status_variable,    \
                                                            STATUS_BIT_NWP_INIT)
#define IS_CONNECTED(status_variable)        GET_STATUS_BIT(status_variable,    \
                                                         STATUS_BIT_CONNECTION)
#define IS_IP_LEASED(status_variable)        GET_STATUS_BIT(status_variable,    \
                                                           STATUS_BIT_IP_LEASED)
#define IS_IP_ACQUIRED(status_variable)       GET_STATUS_BIT(status_variable,   \
                                                          STATUS_BIT_IP_AQUIRED)
#define IS_SMART_CFG_START(status_variable)  GET_STATUS_BIT(status_variable,    \
                                                   STATUS_BIT_SMARTCONFIG_START)
#define IS_P2P_DEV_FOUND(status_variable)    GET_STATUS_BIT(status_variable,    \
                                                       STATUS_BIT_P2P_DEV_FOUND)
#define IS_P2P_REQ_RCVD(status_variable)     GET_STATUS_BIT(status_variable,    \
                                                    STATUS_BIT_P2P_REQ_RECEIVED)
#define IS_CONNECT_FAILED(status_variable)   GET_STATUS_BIT(status_variable,    \
                                                   STATUS_BIT_CONNECTION_FAILED)
#define IS_PING_DONE(status_variable)        GET_STATUS_BIT(status_variable,    \
                                                           STATUS_BIT_PING_DONE)

#ifdef  __cplusplus
}
#endif /* __cplusplus */

