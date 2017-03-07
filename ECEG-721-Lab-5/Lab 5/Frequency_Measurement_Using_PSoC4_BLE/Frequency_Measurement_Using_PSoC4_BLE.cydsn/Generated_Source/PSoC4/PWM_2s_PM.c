/*******************************************************************************
* File Name: PWM_2s_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_2s.h"

static PWM_2s_backupStruct PWM_2s_backup;


/*******************************************************************************
* Function Name: PWM_2s_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_2s_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_2s_SaveConfig(void) 
{

    #if(!PWM_2s_UsingFixedFunction)
        #if(!PWM_2s_PWMModeIsCenterAligned)
            PWM_2s_backup.PWMPeriod = PWM_2s_ReadPeriod();
        #endif /* (!PWM_2s_PWMModeIsCenterAligned) */
        PWM_2s_backup.PWMUdb = PWM_2s_ReadCounter();
        #if (PWM_2s_UseStatus)
            PWM_2s_backup.InterruptMaskValue = PWM_2s_STATUS_MASK;
        #endif /* (PWM_2s_UseStatus) */

        #if(PWM_2s_DeadBandMode == PWM_2s__B_PWM__DBM_256_CLOCKS || \
            PWM_2s_DeadBandMode == PWM_2s__B_PWM__DBM_2_4_CLOCKS)
            PWM_2s_backup.PWMdeadBandValue = PWM_2s_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_2s_KillModeMinTime)
             PWM_2s_backup.PWMKillCounterPeriod = PWM_2s_ReadKillTime();
        #endif /* (PWM_2s_KillModeMinTime) */

        #if(PWM_2s_UseControl)
            PWM_2s_backup.PWMControlRegister = PWM_2s_ReadControlRegister();
        #endif /* (PWM_2s_UseControl) */
    #endif  /* (!PWM_2s_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_2s_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_2s_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_2s_RestoreConfig(void) 
{
        #if(!PWM_2s_UsingFixedFunction)
            #if(!PWM_2s_PWMModeIsCenterAligned)
                PWM_2s_WritePeriod(PWM_2s_backup.PWMPeriod);
            #endif /* (!PWM_2s_PWMModeIsCenterAligned) */

            PWM_2s_WriteCounter(PWM_2s_backup.PWMUdb);

            #if (PWM_2s_UseStatus)
                PWM_2s_STATUS_MASK = PWM_2s_backup.InterruptMaskValue;
            #endif /* (PWM_2s_UseStatus) */

            #if(PWM_2s_DeadBandMode == PWM_2s__B_PWM__DBM_256_CLOCKS || \
                PWM_2s_DeadBandMode == PWM_2s__B_PWM__DBM_2_4_CLOCKS)
                PWM_2s_WriteDeadTime(PWM_2s_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_2s_KillModeMinTime)
                PWM_2s_WriteKillTime(PWM_2s_backup.PWMKillCounterPeriod);
            #endif /* (PWM_2s_KillModeMinTime) */

            #if(PWM_2s_UseControl)
                PWM_2s_WriteControlRegister(PWM_2s_backup.PWMControlRegister);
            #endif /* (PWM_2s_UseControl) */
        #endif  /* (!PWM_2s_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_2s_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_2s_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_2s_Sleep(void) 
{
    #if(PWM_2s_UseControl)
        if(PWM_2s_CTRL_ENABLE == (PWM_2s_CONTROL & PWM_2s_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_2s_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_2s_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_2s_UseControl) */

    /* Stop component */
    PWM_2s_Stop();

    /* Save registers configuration */
    PWM_2s_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_2s_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_2s_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_2s_Wakeup(void) 
{
     /* Restore registers values */
    PWM_2s_RestoreConfig();

    if(PWM_2s_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_2s_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
