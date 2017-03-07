/*******************************************************************************
* File Name: Input_Signal_Counter1_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Input_Signal_Counter1.h"

static Input_Signal_Counter1_BACKUP_STRUCT Input_Signal_Counter1_backup;


/*******************************************************************************
* Function Name: Input_Signal_Counter1_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Input_Signal_Counter1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Input_Signal_Counter1_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Input_Signal_Counter1_Sleep(void)
{
    if(0u != (Input_Signal_Counter1_BLOCK_CONTROL_REG & Input_Signal_Counter1_MASK))
    {
        Input_Signal_Counter1_backup.enableState = 1u;
    }
    else
    {
        Input_Signal_Counter1_backup.enableState = 0u;
    }

    Input_Signal_Counter1_Stop();
    Input_Signal_Counter1_SaveConfig();
}


/*******************************************************************************
* Function Name: Input_Signal_Counter1_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Input_Signal_Counter1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Input_Signal_Counter1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Input_Signal_Counter1_Wakeup(void)
{
    Input_Signal_Counter1_RestoreConfig();

    if(0u != Input_Signal_Counter1_backup.enableState)
    {
        Input_Signal_Counter1_Enable();
    }
}


/* [] END OF FILE */
