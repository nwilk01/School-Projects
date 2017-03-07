/*******************************************************************************
* File Name: Comparator_PM.c
* Version 1.10
*
* Description:
*  This file provides the power management source code to the API for the
*  Opamp (Analog Buffer) component.
*
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Comparator.h"

#if(!Comparator_CHECK_DEEPSLEEP_SUPPORT)
    static Comparator_BACKUP_STRUCT Comparator_backup =
    {
        0u, /* enableState */
    };
#endif /* (Comparator_CHECK_DEEPSLEEP_SUPPORT) */


/*******************************************************************************
* Function Name: Comparator_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Comparator_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Comparator_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Comparator_RestoreConfig(void)
{
    
}


/*******************************************************************************
* Function Name: Comparator_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. The Sleep() API 
*  saves the current component state. Call the Sleep() function before calling the 
*  CySysPmDeepSleep() or the CySysPmHibernate() functions. The "Deep sleep operation" 
*  option has an influence on this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Comparator_backup: The structure field 'enableState' is modified
*  depending on the enable state of the block before entering the sleep mode.
*
*******************************************************************************/
void Comparator_Sleep(void)
{
#if(!Comparator_CHECK_DEEPSLEEP_SUPPORT)
    if(Comparator_CHECK_PWR_MODE_OFF)
    {
        Comparator_backup.enableState = 1u;
        Comparator_Stop();
    }
    else /* The component is disabled */
    {
        Comparator_backup.enableState = 0u;
    }
#endif /* (Comparator_CHECK_DEEPSLEEP_SUPPORT) */
}


/*******************************************************************************
* Function Name: Comparator_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when Sleep() 
*  is called. If the component has been enabled before the Sleep() function is 
*  called, the Wakeup() function will also re-enable the component.
*  The "Deep sleep operation" option has an influence on this function
*  implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Comparator_backup: The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Comparator_Wakeup(void)
{
#if(!Comparator_CHECK_DEEPSLEEP_SUPPORT)
    if(0u != Comparator_backup.enableState)
    {
        /* Enable Opamp's operation */
        Comparator_Enable();
    } /* Do nothing if Opamp was disabled before */
#endif /* (Comparator_CHECK_DEEPSLEEP_SUPPORT) */
}


/* [] END OF FILE */
