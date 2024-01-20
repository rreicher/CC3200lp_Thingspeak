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
#include <pin_mux_config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* simplelink includes */
#include "device.h"

/* driverlib includes */
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_ints.h"
#include "interrupt.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
#include "timer.h"
#include "utils.h"
#include "app_cloud.h"

/* Free_rtos/ti-rtos includes */
#include "osi.h"

/* Private defines */
#if defined(ccs)
extern void (* const g_pfnVectors[])(void);
#endif
#if defined(ewarm)
extern uVectorEntry __vector_table;
#endif

/* Private variables */

/* Private functions prototypes */
static void BoardInit(void);

/*
 * CC3200-LAUNCHXL Board configuration
 * @param: None
 * @return: None
 */
static void BoardInit(void)
{
    /* Configure NVIC Vector Table */
    MAP_IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);
    /* Enables the processor interrupt */
    MAP_IntMasterEnable();
    /* Enable Systick interrupt */
    MAP_IntEnable(FAULT_SYSTICK);
    /* SoC Initialization */
    PRCMCC3200MCUInit();
}

/*
 * Main function declaration
 */
int main(void)
{
    /* Configure Peripherals */
    BoardInit();

    /* Configure Pin */
    PinMuxConfig();

    /* Create main task */
    appTskCreate();

    /* Start the task scheduler */
    osi_start();

    return 0;
}
