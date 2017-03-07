/*******************************************************************************
* File Name: Input_Signal_Counter2.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Input_Signal_Counter2
*  component.
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

#if !defined(CY_TCPWM_Input_Signal_Counter2_H)
#define CY_TCPWM_Input_Signal_Counter2_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Input_Signal_Counter2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Input_Signal_Counter2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Input_Signal_Counter2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Input_Signal_Counter2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Input_Signal_Counter2_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Input_Signal_Counter2_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Input_Signal_Counter2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Input_Signal_Counter2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Input_Signal_Counter2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Input_Signal_Counter2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Input_Signal_Counter2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Input_Signal_Counter2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Input_Signal_Counter2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Input_Signal_Counter2_TC_RUN_MODE                    (0lu)
#define Input_Signal_Counter2_TC_COUNTER_MODE                (0lu)
#define Input_Signal_Counter2_TC_COMP_CAP_MODE               (2lu)
#define Input_Signal_Counter2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Input_Signal_Counter2_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Input_Signal_Counter2_TC_COUNT_SIGNAL_MODE           (0lu)
#define Input_Signal_Counter2_TC_START_SIGNAL_MODE           (0lu)
#define Input_Signal_Counter2_TC_STOP_SIGNAL_MODE            (0lu)
#define Input_Signal_Counter2_TC_CAPTURE_SIGNAL_MODE         (1lu)

/* Signal present */
#define Input_Signal_Counter2_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define Input_Signal_Counter2_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define Input_Signal_Counter2_TC_START_SIGNAL_PRESENT        (0lu)
#define Input_Signal_Counter2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define Input_Signal_Counter2_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define Input_Signal_Counter2_TC_INTERRUPT_MASK              (0lu)

/* PWM Mode */
/* Parameters */
#define Input_Signal_Counter2_PWM_KILL_EVENT                 (0lu)
#define Input_Signal_Counter2_PWM_STOP_EVENT                 (0lu)
#define Input_Signal_Counter2_PWM_MODE                       (4lu)
#define Input_Signal_Counter2_PWM_OUT_N_INVERT               (0lu)
#define Input_Signal_Counter2_PWM_OUT_INVERT                 (0lu)
#define Input_Signal_Counter2_PWM_ALIGN                      (0lu)
#define Input_Signal_Counter2_PWM_RUN_MODE                   (0lu)
#define Input_Signal_Counter2_PWM_DEAD_TIME_CYCLE            (0lu)
#define Input_Signal_Counter2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Input_Signal_Counter2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Input_Signal_Counter2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Input_Signal_Counter2_PWM_START_SIGNAL_MODE          (0lu)
#define Input_Signal_Counter2_PWM_STOP_SIGNAL_MODE           (0lu)
#define Input_Signal_Counter2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Input_Signal_Counter2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Input_Signal_Counter2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Input_Signal_Counter2_PWM_START_SIGNAL_PRESENT       (0lu)
#define Input_Signal_Counter2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Input_Signal_Counter2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Input_Signal_Counter2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Input_Signal_Counter2_TC_PERIOD_VALUE                (65535lu)
#define Input_Signal_Counter2_TC_COMPARE_VALUE               (65535lu)
#define Input_Signal_Counter2_TC_COMPARE_BUF_VALUE           (65535lu)
#define Input_Signal_Counter2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Input_Signal_Counter2_PWM_PERIOD_VALUE               (65535lu)
#define Input_Signal_Counter2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Input_Signal_Counter2_PWM_PERIOD_SWAP                (0lu)
#define Input_Signal_Counter2_PWM_COMPARE_VALUE              (65535lu)
#define Input_Signal_Counter2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Input_Signal_Counter2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Input_Signal_Counter2__LEFT 0
#define Input_Signal_Counter2__RIGHT 1
#define Input_Signal_Counter2__CENTER 2
#define Input_Signal_Counter2__ASYMMETRIC 3

#define Input_Signal_Counter2__X1 0
#define Input_Signal_Counter2__X2 1
#define Input_Signal_Counter2__X4 2

#define Input_Signal_Counter2__PWM 4
#define Input_Signal_Counter2__PWM_DT 5
#define Input_Signal_Counter2__PWM_PR 6

#define Input_Signal_Counter2__INVERSE 1
#define Input_Signal_Counter2__DIRECT 0

#define Input_Signal_Counter2__CAPTURE 2
#define Input_Signal_Counter2__COMPARE 0

#define Input_Signal_Counter2__TRIG_LEVEL 3
#define Input_Signal_Counter2__TRIG_RISING 0
#define Input_Signal_Counter2__TRIG_FALLING 1
#define Input_Signal_Counter2__TRIG_BOTH 2

#define Input_Signal_Counter2__INTR_MASK_TC 1
#define Input_Signal_Counter2__INTR_MASK_CC_MATCH 2
#define Input_Signal_Counter2__INTR_MASK_NONE 0
#define Input_Signal_Counter2__INTR_MASK_TC_CC 3

#define Input_Signal_Counter2__UNCONFIG 8
#define Input_Signal_Counter2__TIMER 1
#define Input_Signal_Counter2__QUAD 3
#define Input_Signal_Counter2__PWM_SEL 7

#define Input_Signal_Counter2__COUNT_UP 0
#define Input_Signal_Counter2__COUNT_DOWN 1
#define Input_Signal_Counter2__COUNT_UPDOWN0 2
#define Input_Signal_Counter2__COUNT_UPDOWN1 3


/* Prescaler */
#define Input_Signal_Counter2_PRESCALE_DIVBY1                ((uint32)(0u << Input_Signal_Counter2_PRESCALER_SHIFT))
#define Input_Signal_Counter2_PRESCALE_DIVBY2                ((uint32)(1u << Input_Signal_Counter2_PRESCALER_SHIFT))
#define Input_Signal_Counter2_PRESCALE_DIVBY4                ((uint32)(2u << Input_Signal_Counter2_PRESCALER_SHIFT))
#define Input_Signal_Counter2_PRESCALE_DIVBY8                ((uint32)(3u << Input_Signal_Counter2_PRESCALER_SHIFT))
#define Input_Signal_Counter2_PRESCALE_DIVBY16               ((uint32)(4u << Input_Signal_Counter2_PRESCALER_SHIFT))
#define Input_Signal_Counter2_PRESCALE_DIVBY32               ((uint32)(5u << Input_Signal_Counter2_PRESCALER_SHIFT))
#define Input_Signal_Counter2_PRESCALE_DIVBY64               ((uint32)(6u << Input_Signal_Counter2_PRESCALER_SHIFT))
#define Input_Signal_Counter2_PRESCALE_DIVBY128              ((uint32)(7u << Input_Signal_Counter2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Input_Signal_Counter2_MODE_TIMER_COMPARE             ((uint32)(Input_Signal_Counter2__COMPARE         <<  \
                                                                  Input_Signal_Counter2_MODE_SHIFT))
#define Input_Signal_Counter2_MODE_TIMER_CAPTURE             ((uint32)(Input_Signal_Counter2__CAPTURE         <<  \
                                                                  Input_Signal_Counter2_MODE_SHIFT))
#define Input_Signal_Counter2_MODE_QUAD                      ((uint32)(Input_Signal_Counter2__QUAD            <<  \
                                                                  Input_Signal_Counter2_MODE_SHIFT))
#define Input_Signal_Counter2_MODE_PWM                       ((uint32)(Input_Signal_Counter2__PWM             <<  \
                                                                  Input_Signal_Counter2_MODE_SHIFT))
#define Input_Signal_Counter2_MODE_PWM_DT                    ((uint32)(Input_Signal_Counter2__PWM_DT          <<  \
                                                                  Input_Signal_Counter2_MODE_SHIFT))
#define Input_Signal_Counter2_MODE_PWM_PR                    ((uint32)(Input_Signal_Counter2__PWM_PR          <<  \
                                                                  Input_Signal_Counter2_MODE_SHIFT))

/* Quad Modes */
#define Input_Signal_Counter2_MODE_X1                        ((uint32)(Input_Signal_Counter2__X1              <<  \
                                                                  Input_Signal_Counter2_QUAD_MODE_SHIFT))
#define Input_Signal_Counter2_MODE_X2                        ((uint32)(Input_Signal_Counter2__X2              <<  \
                                                                  Input_Signal_Counter2_QUAD_MODE_SHIFT))
#define Input_Signal_Counter2_MODE_X4                        ((uint32)(Input_Signal_Counter2__X4              <<  \
                                                                  Input_Signal_Counter2_QUAD_MODE_SHIFT))

/* Counter modes */
#define Input_Signal_Counter2_COUNT_UP                       ((uint32)(Input_Signal_Counter2__COUNT_UP        <<  \
                                                                  Input_Signal_Counter2_UPDOWN_SHIFT))
#define Input_Signal_Counter2_COUNT_DOWN                     ((uint32)(Input_Signal_Counter2__COUNT_DOWN      <<  \
                                                                  Input_Signal_Counter2_UPDOWN_SHIFT))
#define Input_Signal_Counter2_COUNT_UPDOWN0                  ((uint32)(Input_Signal_Counter2__COUNT_UPDOWN0   <<  \
                                                                  Input_Signal_Counter2_UPDOWN_SHIFT))
#define Input_Signal_Counter2_COUNT_UPDOWN1                  ((uint32)(Input_Signal_Counter2__COUNT_UPDOWN1   <<  \
                                                                  Input_Signal_Counter2_UPDOWN_SHIFT))

/* PWM output invert */
#define Input_Signal_Counter2_INVERT_LINE                    ((uint32)(Input_Signal_Counter2__INVERSE         <<  \
                                                                  Input_Signal_Counter2_INV_OUT_SHIFT))
#define Input_Signal_Counter2_INVERT_LINE_N                  ((uint32)(Input_Signal_Counter2__INVERSE         <<  \
                                                                  Input_Signal_Counter2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Input_Signal_Counter2_TRIG_RISING                    ((uint32)Input_Signal_Counter2__TRIG_RISING)
#define Input_Signal_Counter2_TRIG_FALLING                   ((uint32)Input_Signal_Counter2__TRIG_FALLING)
#define Input_Signal_Counter2_TRIG_BOTH                      ((uint32)Input_Signal_Counter2__TRIG_BOTH)
#define Input_Signal_Counter2_TRIG_LEVEL                     ((uint32)Input_Signal_Counter2__TRIG_LEVEL)

/* Interrupt mask */
#define Input_Signal_Counter2_INTR_MASK_TC                   ((uint32)Input_Signal_Counter2__INTR_MASK_TC)
#define Input_Signal_Counter2_INTR_MASK_CC_MATCH             ((uint32)Input_Signal_Counter2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Input_Signal_Counter2_CC_MATCH_SET                   (0x00u)
#define Input_Signal_Counter2_CC_MATCH_CLEAR                 (0x01u)
#define Input_Signal_Counter2_CC_MATCH_INVERT                (0x02u)
#define Input_Signal_Counter2_CC_MATCH_NO_CHANGE             (0x03u)
#define Input_Signal_Counter2_OVERLOW_SET                    (0x00u)
#define Input_Signal_Counter2_OVERLOW_CLEAR                  (0x04u)
#define Input_Signal_Counter2_OVERLOW_INVERT                 (0x08u)
#define Input_Signal_Counter2_OVERLOW_NO_CHANGE              (0x0Cu)
#define Input_Signal_Counter2_UNDERFLOW_SET                  (0x00u)
#define Input_Signal_Counter2_UNDERFLOW_CLEAR                (0x10u)
#define Input_Signal_Counter2_UNDERFLOW_INVERT               (0x20u)
#define Input_Signal_Counter2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Input_Signal_Counter2_PWM_MODE_LEFT                  (Input_Signal_Counter2_CC_MATCH_CLEAR        |   \
                                                         Input_Signal_Counter2_OVERLOW_SET           |   \
                                                         Input_Signal_Counter2_UNDERFLOW_NO_CHANGE)
#define Input_Signal_Counter2_PWM_MODE_RIGHT                 (Input_Signal_Counter2_CC_MATCH_SET          |   \
                                                         Input_Signal_Counter2_OVERLOW_NO_CHANGE     |   \
                                                         Input_Signal_Counter2_UNDERFLOW_CLEAR)
#define Input_Signal_Counter2_PWM_MODE_ASYM                  (Input_Signal_Counter2_CC_MATCH_INVERT       |   \
                                                         Input_Signal_Counter2_OVERLOW_SET           |   \
                                                         Input_Signal_Counter2_UNDERFLOW_CLEAR)

#if (Input_Signal_Counter2_CY_TCPWM_V2)
    #if(Input_Signal_Counter2_CY_TCPWM_4000)
        #define Input_Signal_Counter2_PWM_MODE_CENTER                (Input_Signal_Counter2_CC_MATCH_INVERT       |   \
                                                                 Input_Signal_Counter2_OVERLOW_NO_CHANGE     |   \
                                                                 Input_Signal_Counter2_UNDERFLOW_CLEAR)
    #else
        #define Input_Signal_Counter2_PWM_MODE_CENTER                (Input_Signal_Counter2_CC_MATCH_INVERT       |   \
                                                                 Input_Signal_Counter2_OVERLOW_SET           |   \
                                                                 Input_Signal_Counter2_UNDERFLOW_CLEAR)
    #endif /* (Input_Signal_Counter2_CY_TCPWM_4000) */
#else
    #define Input_Signal_Counter2_PWM_MODE_CENTER                (Input_Signal_Counter2_CC_MATCH_INVERT       |   \
                                                             Input_Signal_Counter2_OVERLOW_NO_CHANGE     |   \
                                                             Input_Signal_Counter2_UNDERFLOW_CLEAR)
#endif /* (Input_Signal_Counter2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Input_Signal_Counter2_CMD_CAPTURE                    (0u)
#define Input_Signal_Counter2_CMD_RELOAD                     (8u)
#define Input_Signal_Counter2_CMD_STOP                       (16u)
#define Input_Signal_Counter2_CMD_START                      (24u)

/* Status */
#define Input_Signal_Counter2_STATUS_DOWN                    (1u)
#define Input_Signal_Counter2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Input_Signal_Counter2_Init(void);
void   Input_Signal_Counter2_Enable(void);
void   Input_Signal_Counter2_Start(void);
void   Input_Signal_Counter2_Stop(void);

void   Input_Signal_Counter2_SetMode(uint32 mode);
void   Input_Signal_Counter2_SetCounterMode(uint32 counterMode);
void   Input_Signal_Counter2_SetPWMMode(uint32 modeMask);
void   Input_Signal_Counter2_SetQDMode(uint32 qdMode);

void   Input_Signal_Counter2_SetPrescaler(uint32 prescaler);
void   Input_Signal_Counter2_TriggerCommand(uint32 mask, uint32 command);
void   Input_Signal_Counter2_SetOneShot(uint32 oneShotEnable);
uint32 Input_Signal_Counter2_ReadStatus(void);

void   Input_Signal_Counter2_SetPWMSyncKill(uint32 syncKillEnable);
void   Input_Signal_Counter2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Input_Signal_Counter2_SetPWMDeadTime(uint32 deadTime);
void   Input_Signal_Counter2_SetPWMInvert(uint32 mask);

void   Input_Signal_Counter2_SetInterruptMode(uint32 interruptMask);
uint32 Input_Signal_Counter2_GetInterruptSourceMasked(void);
uint32 Input_Signal_Counter2_GetInterruptSource(void);
void   Input_Signal_Counter2_ClearInterrupt(uint32 interruptMask);
void   Input_Signal_Counter2_SetInterrupt(uint32 interruptMask);

void   Input_Signal_Counter2_WriteCounter(uint32 count);
uint32 Input_Signal_Counter2_ReadCounter(void);

uint32 Input_Signal_Counter2_ReadCapture(void);
uint32 Input_Signal_Counter2_ReadCaptureBuf(void);

void   Input_Signal_Counter2_WritePeriod(uint32 period);
uint32 Input_Signal_Counter2_ReadPeriod(void);
void   Input_Signal_Counter2_WritePeriodBuf(uint32 periodBuf);
uint32 Input_Signal_Counter2_ReadPeriodBuf(void);

void   Input_Signal_Counter2_WriteCompare(uint32 compare);
uint32 Input_Signal_Counter2_ReadCompare(void);
void   Input_Signal_Counter2_WriteCompareBuf(uint32 compareBuf);
uint32 Input_Signal_Counter2_ReadCompareBuf(void);

void   Input_Signal_Counter2_SetPeriodSwap(uint32 swapEnable);
void   Input_Signal_Counter2_SetCompareSwap(uint32 swapEnable);

void   Input_Signal_Counter2_SetCaptureMode(uint32 triggerMode);
void   Input_Signal_Counter2_SetReloadMode(uint32 triggerMode);
void   Input_Signal_Counter2_SetStartMode(uint32 triggerMode);
void   Input_Signal_Counter2_SetStopMode(uint32 triggerMode);
void   Input_Signal_Counter2_SetCountMode(uint32 triggerMode);

void   Input_Signal_Counter2_SaveConfig(void);
void   Input_Signal_Counter2_RestoreConfig(void);
void   Input_Signal_Counter2_Sleep(void);
void   Input_Signal_Counter2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Input_Signal_Counter2_BLOCK_CONTROL_REG              (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Input_Signal_Counter2_BLOCK_CONTROL_PTR              ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Input_Signal_Counter2_COMMAND_REG                    (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Input_Signal_Counter2_COMMAND_PTR                    ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Input_Signal_Counter2_INTRRUPT_CAUSE_REG             (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Input_Signal_Counter2_INTRRUPT_CAUSE_PTR             ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Input_Signal_Counter2_CONTROL_REG                    (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__CTRL )
#define Input_Signal_Counter2_CONTROL_PTR                    ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__CTRL )
#define Input_Signal_Counter2_STATUS_REG                     (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__STATUS )
#define Input_Signal_Counter2_STATUS_PTR                     ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__STATUS )
#define Input_Signal_Counter2_COUNTER_REG                    (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__COUNTER )
#define Input_Signal_Counter2_COUNTER_PTR                    ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__COUNTER )
#define Input_Signal_Counter2_COMP_CAP_REG                   (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__CC )
#define Input_Signal_Counter2_COMP_CAP_PTR                   ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__CC )
#define Input_Signal_Counter2_COMP_CAP_BUF_REG               (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__CC_BUFF )
#define Input_Signal_Counter2_COMP_CAP_BUF_PTR               ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__CC_BUFF )
#define Input_Signal_Counter2_PERIOD_REG                     (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__PERIOD )
#define Input_Signal_Counter2_PERIOD_PTR                     ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__PERIOD )
#define Input_Signal_Counter2_PERIOD_BUF_REG                 (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Input_Signal_Counter2_PERIOD_BUF_PTR                 ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Input_Signal_Counter2_TRIG_CONTROL0_REG              (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Input_Signal_Counter2_TRIG_CONTROL0_PTR              ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Input_Signal_Counter2_TRIG_CONTROL1_REG              (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Input_Signal_Counter2_TRIG_CONTROL1_PTR              ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Input_Signal_Counter2_TRIG_CONTROL2_REG              (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Input_Signal_Counter2_TRIG_CONTROL2_PTR              ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Input_Signal_Counter2_INTERRUPT_REQ_REG              (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__INTR )
#define Input_Signal_Counter2_INTERRUPT_REQ_PTR              ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__INTR )
#define Input_Signal_Counter2_INTERRUPT_SET_REG              (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__INTR_SET )
#define Input_Signal_Counter2_INTERRUPT_SET_PTR              ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__INTR_SET )
#define Input_Signal_Counter2_INTERRUPT_MASK_REG             (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__INTR_MASK )
#define Input_Signal_Counter2_INTERRUPT_MASK_PTR             ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__INTR_MASK )
#define Input_Signal_Counter2_INTERRUPT_MASKED_REG           (*(reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Input_Signal_Counter2_INTERRUPT_MASKED_PTR           ( (reg32 *) Input_Signal_Counter2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Input_Signal_Counter2_MASK                           ((uint32)Input_Signal_Counter2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Input_Signal_Counter2_RELOAD_CC_SHIFT                (0u)
#define Input_Signal_Counter2_RELOAD_PERIOD_SHIFT            (1u)
#define Input_Signal_Counter2_PWM_SYNC_KILL_SHIFT            (2u)
#define Input_Signal_Counter2_PWM_STOP_KILL_SHIFT            (3u)
#define Input_Signal_Counter2_PRESCALER_SHIFT                (8u)
#define Input_Signal_Counter2_UPDOWN_SHIFT                   (16u)
#define Input_Signal_Counter2_ONESHOT_SHIFT                  (18u)
#define Input_Signal_Counter2_QUAD_MODE_SHIFT                (20u)
#define Input_Signal_Counter2_INV_OUT_SHIFT                  (20u)
#define Input_Signal_Counter2_INV_COMPL_OUT_SHIFT            (21u)
#define Input_Signal_Counter2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Input_Signal_Counter2_RELOAD_CC_MASK                 ((uint32)(Input_Signal_Counter2_1BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_RELOAD_CC_SHIFT))
#define Input_Signal_Counter2_RELOAD_PERIOD_MASK             ((uint32)(Input_Signal_Counter2_1BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_RELOAD_PERIOD_SHIFT))
#define Input_Signal_Counter2_PWM_SYNC_KILL_MASK             ((uint32)(Input_Signal_Counter2_1BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_PWM_SYNC_KILL_SHIFT))
#define Input_Signal_Counter2_PWM_STOP_KILL_MASK             ((uint32)(Input_Signal_Counter2_1BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_PWM_STOP_KILL_SHIFT))
#define Input_Signal_Counter2_PRESCALER_MASK                 ((uint32)(Input_Signal_Counter2_8BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_PRESCALER_SHIFT))
#define Input_Signal_Counter2_UPDOWN_MASK                    ((uint32)(Input_Signal_Counter2_2BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_UPDOWN_SHIFT))
#define Input_Signal_Counter2_ONESHOT_MASK                   ((uint32)(Input_Signal_Counter2_1BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_ONESHOT_SHIFT))
#define Input_Signal_Counter2_QUAD_MODE_MASK                 ((uint32)(Input_Signal_Counter2_3BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_QUAD_MODE_SHIFT))
#define Input_Signal_Counter2_INV_OUT_MASK                   ((uint32)(Input_Signal_Counter2_2BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_INV_OUT_SHIFT))
#define Input_Signal_Counter2_MODE_MASK                      ((uint32)(Input_Signal_Counter2_3BIT_MASK        <<  \
                                                                            Input_Signal_Counter2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Input_Signal_Counter2_CAPTURE_SHIFT                  (0u)
#define Input_Signal_Counter2_COUNT_SHIFT                    (2u)
#define Input_Signal_Counter2_RELOAD_SHIFT                   (4u)
#define Input_Signal_Counter2_STOP_SHIFT                     (6u)
#define Input_Signal_Counter2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Input_Signal_Counter2_CAPTURE_MASK                   ((uint32)(Input_Signal_Counter2_2BIT_MASK        <<  \
                                                                  Input_Signal_Counter2_CAPTURE_SHIFT))
#define Input_Signal_Counter2_COUNT_MASK                     ((uint32)(Input_Signal_Counter2_2BIT_MASK        <<  \
                                                                  Input_Signal_Counter2_COUNT_SHIFT))
#define Input_Signal_Counter2_RELOAD_MASK                    ((uint32)(Input_Signal_Counter2_2BIT_MASK        <<  \
                                                                  Input_Signal_Counter2_RELOAD_SHIFT))
#define Input_Signal_Counter2_STOP_MASK                      ((uint32)(Input_Signal_Counter2_2BIT_MASK        <<  \
                                                                  Input_Signal_Counter2_STOP_SHIFT))
#define Input_Signal_Counter2_START_MASK                     ((uint32)(Input_Signal_Counter2_2BIT_MASK        <<  \
                                                                  Input_Signal_Counter2_START_SHIFT))

/* MASK */
#define Input_Signal_Counter2_1BIT_MASK                      ((uint32)0x01u)
#define Input_Signal_Counter2_2BIT_MASK                      ((uint32)0x03u)
#define Input_Signal_Counter2_3BIT_MASK                      ((uint32)0x07u)
#define Input_Signal_Counter2_6BIT_MASK                      ((uint32)0x3Fu)
#define Input_Signal_Counter2_8BIT_MASK                      ((uint32)0xFFu)
#define Input_Signal_Counter2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Input_Signal_Counter2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Input_Signal_Counter2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Input_Signal_Counter2_QUAD_ENCODING_MODES     << Input_Signal_Counter2_QUAD_MODE_SHIFT))       |\
         ((uint32)(Input_Signal_Counter2_CONFIG                  << Input_Signal_Counter2_MODE_SHIFT)))

#define Input_Signal_Counter2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Input_Signal_Counter2_PWM_STOP_EVENT          << Input_Signal_Counter2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Input_Signal_Counter2_PWM_OUT_INVERT          << Input_Signal_Counter2_INV_OUT_SHIFT))         |\
         ((uint32)(Input_Signal_Counter2_PWM_OUT_N_INVERT        << Input_Signal_Counter2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Input_Signal_Counter2_PWM_MODE                << Input_Signal_Counter2_MODE_SHIFT)))

#define Input_Signal_Counter2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Input_Signal_Counter2_PWM_RUN_MODE         << Input_Signal_Counter2_ONESHOT_SHIFT))
            
#define Input_Signal_Counter2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Input_Signal_Counter2_PWM_ALIGN            << Input_Signal_Counter2_UPDOWN_SHIFT))

#define Input_Signal_Counter2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Input_Signal_Counter2_PWM_KILL_EVENT      << Input_Signal_Counter2_PWM_SYNC_KILL_SHIFT))

#define Input_Signal_Counter2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Input_Signal_Counter2_PWM_DEAD_TIME_CYCLE  << Input_Signal_Counter2_PRESCALER_SHIFT))

#define Input_Signal_Counter2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Input_Signal_Counter2_PWM_PRESCALER        << Input_Signal_Counter2_PRESCALER_SHIFT))

#define Input_Signal_Counter2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Input_Signal_Counter2_TC_PRESCALER            << Input_Signal_Counter2_PRESCALER_SHIFT))       |\
         ((uint32)(Input_Signal_Counter2_TC_COUNTER_MODE         << Input_Signal_Counter2_UPDOWN_SHIFT))          |\
         ((uint32)(Input_Signal_Counter2_TC_RUN_MODE             << Input_Signal_Counter2_ONESHOT_SHIFT))         |\
         ((uint32)(Input_Signal_Counter2_TC_COMP_CAP_MODE        << Input_Signal_Counter2_MODE_SHIFT)))
        
#define Input_Signal_Counter2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Input_Signal_Counter2_QUAD_PHIA_SIGNAL_MODE   << Input_Signal_Counter2_COUNT_SHIFT))           |\
         ((uint32)(Input_Signal_Counter2_QUAD_INDEX_SIGNAL_MODE  << Input_Signal_Counter2_RELOAD_SHIFT))          |\
         ((uint32)(Input_Signal_Counter2_QUAD_STOP_SIGNAL_MODE   << Input_Signal_Counter2_STOP_SHIFT))            |\
         ((uint32)(Input_Signal_Counter2_QUAD_PHIB_SIGNAL_MODE   << Input_Signal_Counter2_START_SHIFT)))

#define Input_Signal_Counter2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Input_Signal_Counter2_PWM_SWITCH_SIGNAL_MODE  << Input_Signal_Counter2_CAPTURE_SHIFT))         |\
         ((uint32)(Input_Signal_Counter2_PWM_COUNT_SIGNAL_MODE   << Input_Signal_Counter2_COUNT_SHIFT))           |\
         ((uint32)(Input_Signal_Counter2_PWM_RELOAD_SIGNAL_MODE  << Input_Signal_Counter2_RELOAD_SHIFT))          |\
         ((uint32)(Input_Signal_Counter2_PWM_STOP_SIGNAL_MODE    << Input_Signal_Counter2_STOP_SHIFT))            |\
         ((uint32)(Input_Signal_Counter2_PWM_START_SIGNAL_MODE   << Input_Signal_Counter2_START_SHIFT)))

#define Input_Signal_Counter2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Input_Signal_Counter2_TC_CAPTURE_SIGNAL_MODE  << Input_Signal_Counter2_CAPTURE_SHIFT))         |\
         ((uint32)(Input_Signal_Counter2_TC_COUNT_SIGNAL_MODE    << Input_Signal_Counter2_COUNT_SHIFT))           |\
         ((uint32)(Input_Signal_Counter2_TC_RELOAD_SIGNAL_MODE   << Input_Signal_Counter2_RELOAD_SHIFT))          |\
         ((uint32)(Input_Signal_Counter2_TC_STOP_SIGNAL_MODE     << Input_Signal_Counter2_STOP_SHIFT))            |\
         ((uint32)(Input_Signal_Counter2_TC_START_SIGNAL_MODE    << Input_Signal_Counter2_START_SHIFT)))
        
#define Input_Signal_Counter2_TIMER_UPDOWN_CNT_USED                                                          \
                ((Input_Signal_Counter2__COUNT_UPDOWN0 == Input_Signal_Counter2_TC_COUNTER_MODE)                  ||\
                 (Input_Signal_Counter2__COUNT_UPDOWN1 == Input_Signal_Counter2_TC_COUNTER_MODE))

#define Input_Signal_Counter2_PWM_UPDOWN_CNT_USED                                                            \
                ((Input_Signal_Counter2__CENTER == Input_Signal_Counter2_PWM_ALIGN)                               ||\
                 (Input_Signal_Counter2__ASYMMETRIC == Input_Signal_Counter2_PWM_ALIGN))               
        
#define Input_Signal_Counter2_PWM_PR_INIT_VALUE              (1u)
#define Input_Signal_Counter2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Input_Signal_Counter2_H */

/* [] END OF FILE */
