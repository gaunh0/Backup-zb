/*******************************************************************************
  Filename:       zcl_samplethermostat.h
  Revised:        $Date: 2013-04-22 14:49:05 -0700 (Mon, 22 Apr 2013) $
  Revision:       $Revision: 33994 $

  Description:    This file contains the Zigbee Cluster Library Home
                  Automation Sample Application.


  Copyright 2013 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED �AS IS� WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
********************************************************************************/

#ifndef ZCL_SAMPLETHERMOSTAT_H
#define ZCL_SAMPLETHERMOSTAT_H

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * INCLUDES
 */
#include "zcl.h"

/* MY INCLUDES */
#include "MS_GLOBAL.h"

/*******************************************************************************
 * CONSTANTS
 */
#ifdef COORDINATOR
#define SAMPLETHERMOSTAT_ENDPOINT							APP_COORDINATOR_ENDPOINT
#elif (defined ROUTER)
#define SAMPLETHERMOSTAT_ENDPOINT							APP_ROUTER_ENDPOINT
#endif

#define SAMPLETHERMOSTAT_MAX_ATTRIBUTES      22

#define LIGHT_OFF                       0x00
#define LIGHT_ON                        0x01

// Application Events
#define SAMPLETHERMOSTAT_IDENTIFY_TIMEOUT_EVT     	  0x0001
#define SAMPLETHERMOSTAT_POLL_CONTROL_TIMEOUT_EVT     0x0002
#define SAMPLETHERMOSTAT_EZMODE_TIMEOUT_EVT           0x0004
#define SAMPLETHERMOSTAT_EZMODE_NEXTSTATE_EVT         0x0008
#define SAMPLETHERMOSTAT_MAIN_SCREEN_EVT              0x0010

#define SAMPLETHERMOSTAT_JOIN_SETUP_EVT								0x0020
#define SAMPLETHERMOSTAT_UART_REPLY_CMD_EVT						0x0040
#define SAMPLETHERMOSTAT_CHECK_SYSTEM_EVT								0x0080


// Application Display Modes
#define THERMOSTAT_MAINMODE         0x00
#define THERMOSTAT_HELPMODE         0x01
#define THERMOSTAT_HEATMODE         0x02
#define THERMOSTAT_COOLMODE         0x03

/*******************************************************************************
 * MACROS
 */
/*******************************************************************************
 * TYPEDEFS
 */

/*******************************************************************************
 * VARIABLES
 */
extern SimpleDescriptionFormat_t zclSampleThermostat_SimpleDesc;

extern CONST zclAttrRec_t zclSampleThermostat_Attrs[];

extern uint8  zclSampleThermostat_OnOff;

extern uint16 zclSampleThermostat_IdentifyTime;

extern int16 zclSampleThermostat_OccupiedCoolingSetpoint;

extern int16 zclSampleThermostat_OccupiedHeatingSetpoint;

extern int16 zclSampleThermostat_LocalTemperature;

extern int16 zclSampleThermostat_MinHeatSetpointLimit;

extern int16 zclSampleThermostat_MaxHeatSetpointLimit;

extern int16 zclSampleThermostat_MinCoolSetpointLimit;

extern int16 zclSampleThermostat_MaxCoolSetpointLimit;

extern uint8 zclSampleThermostat_CoolingDemand;

extern uint8 zclSampleThermostat_HeatingDemand;

extern uint8 zclSampleThermostat_ControlSequenceOfOperation;

extern uint8 zclSampleThermostat_SystemMode;

/*******************************************************************************
 * FUNCTIONS
 */

 /*
  * Initialization for the task
  */
extern void zclSampleThermostat_Init( byte task_id );

/*
 *  Event Process for the task
 */
extern UINT16 zclSampleThermostat_event_loop( byte task_id, UINT16 events );


/*******************************************************************************
********************************************************************************/
extern void zclSampleThermostat_BindingProcess(void);
extern void zclSampleThermostat_SendFreeData(void);
extern void zclSampleThermostat_SendC(void);
extern void zclSampleThermostat_CheckAll(void);

#ifdef __cplusplus
}
#endif

#endif /* ZCL_SAMPLETHERMOSTAT_H */
