/*******************************************************************************
* File Name: Comparator.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the Opamp (Analog Buffer)
*  Component.
*
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Comparator.h"

uint8 Comparator_initVar = 0u; /* Defines if component was initialized */
static uint32 Comparator_internalPower = 0u; /* Defines component Power value */


/*******************************************************************************
* Function Name: Comparator_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the customizer Configure 
*  dialog settings. It is not necessary to call Init() because the Start() API 
*  calls this function and is the preferred method to begin the component operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Comparator_Init(void)
{
    Comparator_internalPower = Comparator_POWER;
    Comparator_CTB_CTRL_REG = Comparator_DEFAULT_CTB_CTRL;
    Comparator_OA_RES_CTRL_REG = Comparator_DEFAULT_OA_RES_CTRL;
    Comparator_OA_COMP_TRIM_REG = Comparator_DEFAULT_OA_COMP_TRIM_REG;
}


/*******************************************************************************
* Function Name: Comparator_Enable
********************************************************************************
*
* Summary:
*  Activates the hardware and begins the component operation. It is not necessary to 
*  call Enable() because the Start() API calls this function, which is the 
*  preferred method to begin the component operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Comparator_Enable(void)
{
    Comparator_OA_RES_CTRL_REG |= Comparator_internalPower | \
                                        Comparator_OA_PUMP_EN;
}


/*******************************************************************************
* Function Name: Comparator_Start
********************************************************************************
*
* Summary:
*  Performs all of the required initialization for the component and enables power 
*  to the block. The first time the routine is executed, the Power level, Mode, 
*  and Output mode are set. When called to restart the Opamp following a Stop() call, 
*  the current component parameter settings are retained.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Comparator_initVar: Used to check the initial configuration, modified
*  when this function is called for the first time.
*
*******************************************************************************/
void Comparator_Start(void)
{
    if( 0u == Comparator_initVar)
    {
        Comparator_Init();
        Comparator_initVar = 1u;
    }
    Comparator_Enable();
}


/*******************************************************************************
* Function Name: Comparator_Stop
********************************************************************************
*
* Summary:
*  Turn off the Opamp block.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Comparator_Stop(void)
{
    Comparator_OA_RES_CTRL_REG &= ((uint32)~(Comparator_OA_PWR_MODE_MASK | \
                                                   Comparator_OA_PUMP_EN));
}


/*******************************************************************************
* Function Name: Comparator_SetPower
********************************************************************************
*
* Summary:
*  Sets the Opamp to one of the three power levels.
*
* Parameters:
*  power: power levels.
*   Comparator_LOW_POWER - Lowest active power
*   Comparator_MED_POWER - Medium power
*   Comparator_HIGH_POWER - Highest active power
*
* Return:
*  None
*
**********************************************************************************/
void Comparator_SetPower(uint32 power)
{
    uint32 tmp;
    
    Comparator_internalPower = Comparator_GET_OA_PWR_MODE(power);
    tmp = Comparator_OA_RES_CTRL_REG & \
           (uint32)~Comparator_OA_PWR_MODE_MASK;
    Comparator_OA_RES_CTRL_REG = tmp | Comparator_internalPower;
}


/*******************************************************************************
* Function Name: Comparator_PumpControl
********************************************************************************
*
* Summary:
*  Allows the user to turn the Opamp's boost pump on or off. By Default the Start() 
*  function turns on the pump. Use this API to turn it off. The boost must be 
*  turned on when the supply is less than 2.7 volts and off if the supply is more 
*  than 4 volts.
*
* Parameters:
*  onOff: Control the pump.
*   Comparator_PUMP_OFF - Turn off the pump
*   Comparator_PUMP_ON - Turn on the pump
*
* Return:
*  None
*
**********************************************************************************/
void Comparator_PumpControl(uint32 onOff)
{
    
    if(0u != onOff)
    {
        Comparator_OA_RES_CTRL |= Comparator_OA_PUMP_EN;    
    }
    else
    {
        Comparator_OA_RES_CTRL &= (uint32)~Comparator_OA_PUMP_EN;
    }
}


/* [] END OF FILE */
