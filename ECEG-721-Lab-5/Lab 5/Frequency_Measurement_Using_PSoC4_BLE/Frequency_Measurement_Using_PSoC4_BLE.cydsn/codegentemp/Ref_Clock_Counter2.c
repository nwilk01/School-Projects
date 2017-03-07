/*******************************************************************************
* File Name: Ref_Clock_Counter2.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the Ref_Clock_Counter2
*  component
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

#include "Ref_Clock_Counter2.h"

uint8 Ref_Clock_Counter2_initVar = 0u;


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default Ref_Clock_Counter2 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (Ref_Clock_Counter2__QUAD == Ref_Clock_Counter2_CONFIG)
        Ref_Clock_Counter2_CONTROL_REG = Ref_Clock_Counter2_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        Ref_Clock_Counter2_TRIG_CONTROL1_REG  = Ref_Clock_Counter2_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        Ref_Clock_Counter2_SetInterruptMode(Ref_Clock_Counter2_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        Ref_Clock_Counter2_SetCounterMode(Ref_Clock_Counter2_COUNT_DOWN);
        Ref_Clock_Counter2_WritePeriod(Ref_Clock_Counter2_QUAD_PERIOD_INIT_VALUE);
        Ref_Clock_Counter2_WriteCounter(Ref_Clock_Counter2_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (Ref_Clock_Counter2__QUAD == Ref_Clock_Counter2_CONFIG) */

    #if (Ref_Clock_Counter2__TIMER == Ref_Clock_Counter2_CONFIG)
        Ref_Clock_Counter2_CONTROL_REG = Ref_Clock_Counter2_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        Ref_Clock_Counter2_TRIG_CONTROL1_REG  = Ref_Clock_Counter2_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        Ref_Clock_Counter2_SetInterruptMode(Ref_Clock_Counter2_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        Ref_Clock_Counter2_WritePeriod(Ref_Clock_Counter2_TC_PERIOD_VALUE );

        #if (Ref_Clock_Counter2__COMPARE == Ref_Clock_Counter2_TC_COMP_CAP_MODE)
            Ref_Clock_Counter2_WriteCompare(Ref_Clock_Counter2_TC_COMPARE_VALUE);

            #if (1u == Ref_Clock_Counter2_TC_COMPARE_SWAP)
                Ref_Clock_Counter2_SetCompareSwap(1u);
                Ref_Clock_Counter2_WriteCompareBuf(Ref_Clock_Counter2_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == Ref_Clock_Counter2_TC_COMPARE_SWAP) */
        #endif  /* (Ref_Clock_Counter2__COMPARE == Ref_Clock_Counter2_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (Ref_Clock_Counter2_CY_TCPWM_V2 && Ref_Clock_Counter2_TIMER_UPDOWN_CNT_USED && !Ref_Clock_Counter2_CY_TCPWM_4000)
            Ref_Clock_Counter2_WriteCounter(1u);
        #elif(Ref_Clock_Counter2__COUNT_DOWN == Ref_Clock_Counter2_TC_COUNTER_MODE)
            Ref_Clock_Counter2_WriteCounter(Ref_Clock_Counter2_TC_PERIOD_VALUE);
        #else
            Ref_Clock_Counter2_WriteCounter(0u);
        #endif /* (Ref_Clock_Counter2_CY_TCPWM_V2 && Ref_Clock_Counter2_TIMER_UPDOWN_CNT_USED && !Ref_Clock_Counter2_CY_TCPWM_4000) */
    #endif  /* (Ref_Clock_Counter2__TIMER == Ref_Clock_Counter2_CONFIG) */

    #if (Ref_Clock_Counter2__PWM_SEL == Ref_Clock_Counter2_CONFIG)
        Ref_Clock_Counter2_CONTROL_REG = Ref_Clock_Counter2_CTRL_PWM_BASE_CONFIG;

        #if (Ref_Clock_Counter2__PWM_PR == Ref_Clock_Counter2_PWM_MODE)
            Ref_Clock_Counter2_CONTROL_REG |= Ref_Clock_Counter2_CTRL_PWM_RUN_MODE;
            Ref_Clock_Counter2_WriteCounter(Ref_Clock_Counter2_PWM_PR_INIT_VALUE);
        #else
            Ref_Clock_Counter2_CONTROL_REG |= Ref_Clock_Counter2_CTRL_PWM_ALIGN | Ref_Clock_Counter2_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (Ref_Clock_Counter2_CY_TCPWM_V2 && Ref_Clock_Counter2_PWM_UPDOWN_CNT_USED && !Ref_Clock_Counter2_CY_TCPWM_4000)
                Ref_Clock_Counter2_WriteCounter(1u);
            #elif (Ref_Clock_Counter2__RIGHT == Ref_Clock_Counter2_PWM_ALIGN)
                Ref_Clock_Counter2_WriteCounter(Ref_Clock_Counter2_PWM_PERIOD_VALUE);
            #else 
                Ref_Clock_Counter2_WriteCounter(0u);
            #endif  /* (Ref_Clock_Counter2_CY_TCPWM_V2 && Ref_Clock_Counter2_PWM_UPDOWN_CNT_USED && !Ref_Clock_Counter2_CY_TCPWM_4000) */
        #endif  /* (Ref_Clock_Counter2__PWM_PR == Ref_Clock_Counter2_PWM_MODE) */

        #if (Ref_Clock_Counter2__PWM_DT == Ref_Clock_Counter2_PWM_MODE)
            Ref_Clock_Counter2_CONTROL_REG |= Ref_Clock_Counter2_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (Ref_Clock_Counter2__PWM_DT == Ref_Clock_Counter2_PWM_MODE) */

        #if (Ref_Clock_Counter2__PWM == Ref_Clock_Counter2_PWM_MODE)
            Ref_Clock_Counter2_CONTROL_REG |= Ref_Clock_Counter2_CTRL_PWM_PRESCALER;
        #endif  /* (Ref_Clock_Counter2__PWM == Ref_Clock_Counter2_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        Ref_Clock_Counter2_TRIG_CONTROL1_REG  = Ref_Clock_Counter2_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        Ref_Clock_Counter2_SetInterruptMode(Ref_Clock_Counter2_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (Ref_Clock_Counter2__PWM_PR == Ref_Clock_Counter2_PWM_MODE)
            Ref_Clock_Counter2_TRIG_CONTROL2_REG =
                    (Ref_Clock_Counter2_CC_MATCH_NO_CHANGE    |
                    Ref_Clock_Counter2_OVERLOW_NO_CHANGE      |
                    Ref_Clock_Counter2_UNDERFLOW_NO_CHANGE);
        #else
            #if (Ref_Clock_Counter2__LEFT == Ref_Clock_Counter2_PWM_ALIGN)
                Ref_Clock_Counter2_TRIG_CONTROL2_REG = Ref_Clock_Counter2_PWM_MODE_LEFT;
            #endif  /* ( Ref_Clock_Counter2_PWM_LEFT == Ref_Clock_Counter2_PWM_ALIGN) */

            #if (Ref_Clock_Counter2__RIGHT == Ref_Clock_Counter2_PWM_ALIGN)
                Ref_Clock_Counter2_TRIG_CONTROL2_REG = Ref_Clock_Counter2_PWM_MODE_RIGHT;
            #endif  /* ( Ref_Clock_Counter2_PWM_RIGHT == Ref_Clock_Counter2_PWM_ALIGN) */

            #if (Ref_Clock_Counter2__CENTER == Ref_Clock_Counter2_PWM_ALIGN)
                Ref_Clock_Counter2_TRIG_CONTROL2_REG = Ref_Clock_Counter2_PWM_MODE_CENTER;
            #endif  /* ( Ref_Clock_Counter2_PWM_CENTER == Ref_Clock_Counter2_PWM_ALIGN) */

            #if (Ref_Clock_Counter2__ASYMMETRIC == Ref_Clock_Counter2_PWM_ALIGN)
                Ref_Clock_Counter2_TRIG_CONTROL2_REG = Ref_Clock_Counter2_PWM_MODE_ASYM;
            #endif  /* (Ref_Clock_Counter2__ASYMMETRIC == Ref_Clock_Counter2_PWM_ALIGN) */
        #endif  /* (Ref_Clock_Counter2__PWM_PR == Ref_Clock_Counter2_PWM_MODE) */

        /* Set other values from customizer */
        Ref_Clock_Counter2_WritePeriod(Ref_Clock_Counter2_PWM_PERIOD_VALUE );
        Ref_Clock_Counter2_WriteCompare(Ref_Clock_Counter2_PWM_COMPARE_VALUE);

        #if (1u == Ref_Clock_Counter2_PWM_COMPARE_SWAP)
            Ref_Clock_Counter2_SetCompareSwap(1u);
            Ref_Clock_Counter2_WriteCompareBuf(Ref_Clock_Counter2_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == Ref_Clock_Counter2_PWM_COMPARE_SWAP) */

        #if (1u == Ref_Clock_Counter2_PWM_PERIOD_SWAP)
            Ref_Clock_Counter2_SetPeriodSwap(1u);
            Ref_Clock_Counter2_WritePeriodBuf(Ref_Clock_Counter2_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == Ref_Clock_Counter2_PWM_PERIOD_SWAP) */
    #endif  /* (Ref_Clock_Counter2__PWM_SEL == Ref_Clock_Counter2_CONFIG) */
    
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_Enable
********************************************************************************
*
* Summary:
*  Enables the Ref_Clock_Counter2.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    Ref_Clock_Counter2_BLOCK_CONTROL_REG |= Ref_Clock_Counter2_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (Ref_Clock_Counter2__PWM_SEL == Ref_Clock_Counter2_CONFIG)
        #if (0u == Ref_Clock_Counter2_PWM_START_SIGNAL_PRESENT)
            Ref_Clock_Counter2_TriggerCommand(Ref_Clock_Counter2_MASK, Ref_Clock_Counter2_CMD_START);
        #endif /* (0u == Ref_Clock_Counter2_PWM_START_SIGNAL_PRESENT) */
    #endif /* (Ref_Clock_Counter2__PWM_SEL == Ref_Clock_Counter2_CONFIG) */

    #if (Ref_Clock_Counter2__TIMER == Ref_Clock_Counter2_CONFIG)
        #if (0u == Ref_Clock_Counter2_TC_START_SIGNAL_PRESENT)
            Ref_Clock_Counter2_TriggerCommand(Ref_Clock_Counter2_MASK, Ref_Clock_Counter2_CMD_START);
        #endif /* (0u == Ref_Clock_Counter2_TC_START_SIGNAL_PRESENT) */
    #endif /* (Ref_Clock_Counter2__TIMER == Ref_Clock_Counter2_CONFIG) */
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_Start
********************************************************************************
*
* Summary:
*  Initializes the Ref_Clock_Counter2 with default customizer
*  values when called the first time and enables the Ref_Clock_Counter2.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Ref_Clock_Counter2_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time Ref_Clock_Counter2_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the Ref_Clock_Counter2_Start() routine.
*
*******************************************************************************/
void Ref_Clock_Counter2_Start(void)
{
    if (0u == Ref_Clock_Counter2_initVar)
    {
        Ref_Clock_Counter2_Init();
        Ref_Clock_Counter2_initVar = 1u;
    }

    Ref_Clock_Counter2_Enable();
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_Stop
********************************************************************************
*
* Summary:
*  Disables the Ref_Clock_Counter2.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_BLOCK_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the Ref_Clock_Counter2. This function is used when
*  configured as a generic Ref_Clock_Counter2 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the Ref_Clock_Counter2 to operate in
*   Values:
*   - Ref_Clock_Counter2_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - Ref_Clock_Counter2_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - Ref_Clock_Counter2_MODE_QUAD - Quadrature decoder
*         - Ref_Clock_Counter2_MODE_PWM - PWM
*         - Ref_Clock_Counter2_MODE_PWM_DT - PWM with dead time
*         - Ref_Clock_Counter2_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_MODE_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - Ref_Clock_Counter2_MODE_X1 - Counts on phi 1 rising
*         - Ref_Clock_Counter2_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - Ref_Clock_Counter2_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_QUAD_MODE_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - Ref_Clock_Counter2_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - Ref_Clock_Counter2_PRESCALE_DIVBY2    - Divide by 2
*         - Ref_Clock_Counter2_PRESCALE_DIVBY4    - Divide by 4
*         - Ref_Clock_Counter2_PRESCALE_DIVBY8    - Divide by 8
*         - Ref_Clock_Counter2_PRESCALE_DIVBY16   - Divide by 16
*         - Ref_Clock_Counter2_PRESCALE_DIVBY32   - Divide by 32
*         - Ref_Clock_Counter2_PRESCALE_DIVBY64   - Divide by 64
*         - Ref_Clock_Counter2_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_PRESCALER_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the Ref_Clock_Counter2 runs
*  continuously or stops when terminal count is reached.  By default the
*  Ref_Clock_Counter2 operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_ONESHOT_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= ((uint32)((oneShotEnable & Ref_Clock_Counter2_1BIT_MASK) <<
                                                               Ref_Clock_Counter2_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetPWMMode(uint32 modeMask)
{
    Ref_Clock_Counter2_TRIG_CONTROL2_REG = (modeMask & Ref_Clock_Counter2_6BIT_MASK);
}



/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_PWM_SYNC_KILL_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= ((uint32)((syncKillEnable & Ref_Clock_Counter2_1BIT_MASK)  <<
                                               Ref_Clock_Counter2_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_PWM_STOP_KILL_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= ((uint32)((stopOnKillEnable & Ref_Clock_Counter2_1BIT_MASK)  <<
                                                         Ref_Clock_Counter2_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_PRESCALER_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= ((uint32)((deadTime & Ref_Clock_Counter2_8BIT_MASK) <<
                                                          Ref_Clock_Counter2_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - Ref_Clock_Counter2_INVERT_LINE   - Inverts the line output
*         - Ref_Clock_Counter2_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_INV_OUT_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: Ref_Clock_Counter2_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_WriteCounter(uint32 count)
{
    Ref_Clock_Counter2_COUNTER_REG = (count & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_ReadCounter(void)
{
    return (Ref_Clock_Counter2_COUNTER_REG & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - Ref_Clock_Counter2_COUNT_UP       - Counts up
*     - Ref_Clock_Counter2_COUNT_DOWN     - Counts down
*     - Ref_Clock_Counter2_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - Ref_Clock_Counter2_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_UPDOWN_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_WritePeriod(uint32 period)
{
    Ref_Clock_Counter2_PERIOD_REG = (period & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_ReadPeriod(void)
{
    return (Ref_Clock_Counter2_PERIOD_REG & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_RELOAD_CC_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= (swapEnable & Ref_Clock_Counter2_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_WritePeriodBuf(uint32 periodBuf)
{
    Ref_Clock_Counter2_PERIOD_BUF_REG = (periodBuf & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_ReadPeriodBuf(void)
{
    return (Ref_Clock_Counter2_PERIOD_BUF_REG & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_CONTROL_REG &= (uint32)~Ref_Clock_Counter2_RELOAD_PERIOD_MASK;
    Ref_Clock_Counter2_CONTROL_REG |= ((uint32)((swapEnable & Ref_Clock_Counter2_1BIT_MASK) <<
                                                            Ref_Clock_Counter2_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_WriteCompare(uint32 compare)
{
    #if (Ref_Clock_Counter2_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */

    #if (Ref_Clock_Counter2_CY_TCPWM_4000)
        currentMode = ((Ref_Clock_Counter2_CONTROL_REG & Ref_Clock_Counter2_UPDOWN_MASK) >> Ref_Clock_Counter2_UPDOWN_SHIFT);

        if (((uint32)Ref_Clock_Counter2__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)Ref_Clock_Counter2__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */
    
    Ref_Clock_Counter2_COMP_CAP_REG = (compare & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_ReadCompare(void)
{
    #if (Ref_Clock_Counter2_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */

    #if (Ref_Clock_Counter2_CY_TCPWM_4000)
        currentMode = ((Ref_Clock_Counter2_CONTROL_REG & Ref_Clock_Counter2_UPDOWN_MASK) >> Ref_Clock_Counter2_UPDOWN_SHIFT);
        
        regVal = Ref_Clock_Counter2_COMP_CAP_REG;
        
        if (((uint32)Ref_Clock_Counter2__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)Ref_Clock_Counter2__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & Ref_Clock_Counter2_16BIT_MASK);
    #else
        return (Ref_Clock_Counter2_COMP_CAP_REG & Ref_Clock_Counter2_16BIT_MASK);
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_WriteCompareBuf(uint32 compareBuf)
{
    #if (Ref_Clock_Counter2_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */

    #if (Ref_Clock_Counter2_CY_TCPWM_4000)
        currentMode = ((Ref_Clock_Counter2_CONTROL_REG & Ref_Clock_Counter2_UPDOWN_MASK) >> Ref_Clock_Counter2_UPDOWN_SHIFT);

        if (((uint32)Ref_Clock_Counter2__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)Ref_Clock_Counter2__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */
    
    Ref_Clock_Counter2_COMP_CAP_BUF_REG = (compareBuf & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_ReadCompareBuf(void)
{
    #if (Ref_Clock_Counter2_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */

    #if (Ref_Clock_Counter2_CY_TCPWM_4000)
        currentMode = ((Ref_Clock_Counter2_CONTROL_REG & Ref_Clock_Counter2_UPDOWN_MASK) >> Ref_Clock_Counter2_UPDOWN_SHIFT);

        regVal = Ref_Clock_Counter2_COMP_CAP_BUF_REG;
        
        if (((uint32)Ref_Clock_Counter2__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)Ref_Clock_Counter2__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & Ref_Clock_Counter2_16BIT_MASK);
    #else
        return (Ref_Clock_Counter2_COMP_CAP_BUF_REG & Ref_Clock_Counter2_16BIT_MASK);
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_ReadCapture(void)
{
    return (Ref_Clock_Counter2_COMP_CAP_REG & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_ReadCaptureBuf(void)
{
    return (Ref_Clock_Counter2_COMP_CAP_BUF_REG & Ref_Clock_Counter2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Ref_Clock_Counter2_TRIG_LEVEL     - Level
*     - Ref_Clock_Counter2_TRIG_RISING    - Rising edge
*     - Ref_Clock_Counter2_TRIG_FALLING   - Falling edge
*     - Ref_Clock_Counter2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_TRIG_CONTROL1_REG &= (uint32)~Ref_Clock_Counter2_CAPTURE_MASK;
    Ref_Clock_Counter2_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Ref_Clock_Counter2_TRIG_LEVEL     - Level
*     - Ref_Clock_Counter2_TRIG_RISING    - Rising edge
*     - Ref_Clock_Counter2_TRIG_FALLING   - Falling edge
*     - Ref_Clock_Counter2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_TRIG_CONTROL1_REG &= (uint32)~Ref_Clock_Counter2_RELOAD_MASK;
    Ref_Clock_Counter2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Ref_Clock_Counter2_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Ref_Clock_Counter2_TRIG_LEVEL     - Level
*     - Ref_Clock_Counter2_TRIG_RISING    - Rising edge
*     - Ref_Clock_Counter2_TRIG_FALLING   - Falling edge
*     - Ref_Clock_Counter2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_TRIG_CONTROL1_REG &= (uint32)~Ref_Clock_Counter2_START_MASK;
    Ref_Clock_Counter2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Ref_Clock_Counter2_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Ref_Clock_Counter2_TRIG_LEVEL     - Level
*     - Ref_Clock_Counter2_TRIG_RISING    - Rising edge
*     - Ref_Clock_Counter2_TRIG_FALLING   - Falling edge
*     - Ref_Clock_Counter2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_TRIG_CONTROL1_REG &= (uint32)~Ref_Clock_Counter2_STOP_MASK;
    Ref_Clock_Counter2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Ref_Clock_Counter2_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Ref_Clock_Counter2_TRIG_LEVEL     - Level
*     - Ref_Clock_Counter2_TRIG_RISING    - Rising edge
*     - Ref_Clock_Counter2_TRIG_FALLING   - Falling edge
*     - Ref_Clock_Counter2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_TRIG_CONTROL1_REG &= (uint32)~Ref_Clock_Counter2_COUNT_MASK;
    Ref_Clock_Counter2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Ref_Clock_Counter2_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - Ref_Clock_Counter2_CMD_CAPTURE    - Trigger Capture command
*     - Ref_Clock_Counter2_CMD_RELOAD     - Trigger Reload command
*     - Ref_Clock_Counter2_CMD_STOP       - Trigger Stop command
*     - Ref_Clock_Counter2_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Ref_Clock_Counter2_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the Ref_Clock_Counter2.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - Ref_Clock_Counter2_STATUS_DOWN    - Set if counting down
*     - Ref_Clock_Counter2_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_ReadStatus(void)
{
    return ((Ref_Clock_Counter2_STATUS_REG >> Ref_Clock_Counter2_RUNNING_STATUS_SHIFT) |
            (Ref_Clock_Counter2_STATUS_REG & Ref_Clock_Counter2_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - Ref_Clock_Counter2_INTR_MASK_TC       - Terminal count mask
*     - Ref_Clock_Counter2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetInterruptMode(uint32 interruptMask)
{
    Ref_Clock_Counter2_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - Ref_Clock_Counter2_INTR_MASK_TC       - Terminal count mask
*     - Ref_Clock_Counter2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_GetInterruptSourceMasked(void)
{
    return (Ref_Clock_Counter2_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - Ref_Clock_Counter2_INTR_MASK_TC       - Terminal count mask
*     - Ref_Clock_Counter2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 Ref_Clock_Counter2_GetInterruptSource(void)
{
    return (Ref_Clock_Counter2_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - Ref_Clock_Counter2_INTR_MASK_TC       - Terminal count mask
*     - Ref_Clock_Counter2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_ClearInterrupt(uint32 interruptMask)
{
    Ref_Clock_Counter2_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: Ref_Clock_Counter2_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - Ref_Clock_Counter2_INTR_MASK_TC       - Terminal count mask
*     - Ref_Clock_Counter2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Ref_Clock_Counter2_SetInterrupt(uint32 interruptMask)
{
    Ref_Clock_Counter2_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
