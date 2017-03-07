/*******************************************************************************
* File Name: Ref_Clock_Counter2.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Ref_Clock_Counter2
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

#if !defined(CY_TCPWM_Ref_Clock_Counter2_H)
#define CY_TCPWM_Ref_Clock_Counter2_H


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
} Ref_Clock_Counter2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Ref_Clock_Counter2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Ref_Clock_Counter2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Ref_Clock_Counter2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Ref_Clock_Counter2_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Ref_Clock_Counter2_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Ref_Clock_Counter2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Ref_Clock_Counter2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Ref_Clock_Counter2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Ref_Clock_Counter2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Ref_Clock_Counter2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Ref_Clock_Counter2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Ref_Clock_Counter2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Ref_Clock_Counter2_TC_RUN_MODE                    (0lu)
#define Ref_Clock_Counter2_TC_COUNTER_MODE                (0lu)
#define Ref_Clock_Counter2_TC_COMP_CAP_MODE               (2lu)
#define Ref_Clock_Counter2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Ref_Clock_Counter2_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Ref_Clock_Counter2_TC_COUNT_SIGNAL_MODE           (0lu)
#define Ref_Clock_Counter2_TC_START_SIGNAL_MODE           (0lu)
#define Ref_Clock_Counter2_TC_STOP_SIGNAL_MODE            (0lu)
#define Ref_Clock_Counter2_TC_CAPTURE_SIGNAL_MODE         (1lu)

/* Signal present */
#define Ref_Clock_Counter2_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define Ref_Clock_Counter2_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define Ref_Clock_Counter2_TC_START_SIGNAL_PRESENT        (0lu)
#define Ref_Clock_Counter2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define Ref_Clock_Counter2_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define Ref_Clock_Counter2_TC_INTERRUPT_MASK              (0lu)

/* PWM Mode */
/* Parameters */
#define Ref_Clock_Counter2_PWM_KILL_EVENT                 (0lu)
#define Ref_Clock_Counter2_PWM_STOP_EVENT                 (0lu)
#define Ref_Clock_Counter2_PWM_MODE                       (4lu)
#define Ref_Clock_Counter2_PWM_OUT_N_INVERT               (0lu)
#define Ref_Clock_Counter2_PWM_OUT_INVERT                 (0lu)
#define Ref_Clock_Counter2_PWM_ALIGN                      (0lu)
#define Ref_Clock_Counter2_PWM_RUN_MODE                   (0lu)
#define Ref_Clock_Counter2_PWM_DEAD_TIME_CYCLE            (0lu)
#define Ref_Clock_Counter2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Ref_Clock_Counter2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Ref_Clock_Counter2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Ref_Clock_Counter2_PWM_START_SIGNAL_MODE          (0lu)
#define Ref_Clock_Counter2_PWM_STOP_SIGNAL_MODE           (0lu)
#define Ref_Clock_Counter2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Ref_Clock_Counter2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Ref_Clock_Counter2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Ref_Clock_Counter2_PWM_START_SIGNAL_PRESENT       (0lu)
#define Ref_Clock_Counter2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Ref_Clock_Counter2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Ref_Clock_Counter2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Ref_Clock_Counter2_TC_PERIOD_VALUE                (65535lu)
#define Ref_Clock_Counter2_TC_COMPARE_VALUE               (65535lu)
#define Ref_Clock_Counter2_TC_COMPARE_BUF_VALUE           (65535lu)
#define Ref_Clock_Counter2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Ref_Clock_Counter2_PWM_PERIOD_VALUE               (65535lu)
#define Ref_Clock_Counter2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Ref_Clock_Counter2_PWM_PERIOD_SWAP                (0lu)
#define Ref_Clock_Counter2_PWM_COMPARE_VALUE              (65535lu)
#define Ref_Clock_Counter2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Ref_Clock_Counter2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Ref_Clock_Counter2__LEFT 0
#define Ref_Clock_Counter2__RIGHT 1
#define Ref_Clock_Counter2__CENTER 2
#define Ref_Clock_Counter2__ASYMMETRIC 3

#define Ref_Clock_Counter2__X1 0
#define Ref_Clock_Counter2__X2 1
#define Ref_Clock_Counter2__X4 2

#define Ref_Clock_Counter2__PWM 4
#define Ref_Clock_Counter2__PWM_DT 5
#define Ref_Clock_Counter2__PWM_PR 6

#define Ref_Clock_Counter2__INVERSE 1
#define Ref_Clock_Counter2__DIRECT 0

#define Ref_Clock_Counter2__CAPTURE 2
#define Ref_Clock_Counter2__COMPARE 0

#define Ref_Clock_Counter2__TRIG_LEVEL 3
#define Ref_Clock_Counter2__TRIG_RISING 0
#define Ref_Clock_Counter2__TRIG_FALLING 1
#define Ref_Clock_Counter2__TRIG_BOTH 2

#define Ref_Clock_Counter2__INTR_MASK_TC 1
#define Ref_Clock_Counter2__INTR_MASK_CC_MATCH 2
#define Ref_Clock_Counter2__INTR_MASK_NONE 0
#define Ref_Clock_Counter2__INTR_MASK_TC_CC 3

#define Ref_Clock_Counter2__UNCONFIG 8
#define Ref_Clock_Counter2__TIMER 1
#define Ref_Clock_Counter2__QUAD 3
#define Ref_Clock_Counter2__PWM_SEL 7

#define Ref_Clock_Counter2__COUNT_UP 0
#define Ref_Clock_Counter2__COUNT_DOWN 1
#define Ref_Clock_Counter2__COUNT_UPDOWN0 2
#define Ref_Clock_Counter2__COUNT_UPDOWN1 3


/* Prescaler */
#define Ref_Clock_Counter2_PRESCALE_DIVBY1                ((uint32)(0u << Ref_Clock_Counter2_PRESCALER_SHIFT))
#define Ref_Clock_Counter2_PRESCALE_DIVBY2                ((uint32)(1u << Ref_Clock_Counter2_PRESCALER_SHIFT))
#define Ref_Clock_Counter2_PRESCALE_DIVBY4                ((uint32)(2u << Ref_Clock_Counter2_PRESCALER_SHIFT))
#define Ref_Clock_Counter2_PRESCALE_DIVBY8                ((uint32)(3u << Ref_Clock_Counter2_PRESCALER_SHIFT))
#define Ref_Clock_Counter2_PRESCALE_DIVBY16               ((uint32)(4u << Ref_Clock_Counter2_PRESCALER_SHIFT))
#define Ref_Clock_Counter2_PRESCALE_DIVBY32               ((uint32)(5u << Ref_Clock_Counter2_PRESCALER_SHIFT))
#define Ref_Clock_Counter2_PRESCALE_DIVBY64               ((uint32)(6u << Ref_Clock_Counter2_PRESCALER_SHIFT))
#define Ref_Clock_Counter2_PRESCALE_DIVBY128              ((uint32)(7u << Ref_Clock_Counter2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Ref_Clock_Counter2_MODE_TIMER_COMPARE             ((uint32)(Ref_Clock_Counter2__COMPARE         <<  \
                                                                  Ref_Clock_Counter2_MODE_SHIFT))
#define Ref_Clock_Counter2_MODE_TIMER_CAPTURE             ((uint32)(Ref_Clock_Counter2__CAPTURE         <<  \
                                                                  Ref_Clock_Counter2_MODE_SHIFT))
#define Ref_Clock_Counter2_MODE_QUAD                      ((uint32)(Ref_Clock_Counter2__QUAD            <<  \
                                                                  Ref_Clock_Counter2_MODE_SHIFT))
#define Ref_Clock_Counter2_MODE_PWM                       ((uint32)(Ref_Clock_Counter2__PWM             <<  \
                                                                  Ref_Clock_Counter2_MODE_SHIFT))
#define Ref_Clock_Counter2_MODE_PWM_DT                    ((uint32)(Ref_Clock_Counter2__PWM_DT          <<  \
                                                                  Ref_Clock_Counter2_MODE_SHIFT))
#define Ref_Clock_Counter2_MODE_PWM_PR                    ((uint32)(Ref_Clock_Counter2__PWM_PR          <<  \
                                                                  Ref_Clock_Counter2_MODE_SHIFT))

/* Quad Modes */
#define Ref_Clock_Counter2_MODE_X1                        ((uint32)(Ref_Clock_Counter2__X1              <<  \
                                                                  Ref_Clock_Counter2_QUAD_MODE_SHIFT))
#define Ref_Clock_Counter2_MODE_X2                        ((uint32)(Ref_Clock_Counter2__X2              <<  \
                                                                  Ref_Clock_Counter2_QUAD_MODE_SHIFT))
#define Ref_Clock_Counter2_MODE_X4                        ((uint32)(Ref_Clock_Counter2__X4              <<  \
                                                                  Ref_Clock_Counter2_QUAD_MODE_SHIFT))

/* Counter modes */
#define Ref_Clock_Counter2_COUNT_UP                       ((uint32)(Ref_Clock_Counter2__COUNT_UP        <<  \
                                                                  Ref_Clock_Counter2_UPDOWN_SHIFT))
#define Ref_Clock_Counter2_COUNT_DOWN                     ((uint32)(Ref_Clock_Counter2__COUNT_DOWN      <<  \
                                                                  Ref_Clock_Counter2_UPDOWN_SHIFT))
#define Ref_Clock_Counter2_COUNT_UPDOWN0                  ((uint32)(Ref_Clock_Counter2__COUNT_UPDOWN0   <<  \
                                                                  Ref_Clock_Counter2_UPDOWN_SHIFT))
#define Ref_Clock_Counter2_COUNT_UPDOWN1                  ((uint32)(Ref_Clock_Counter2__COUNT_UPDOWN1   <<  \
                                                                  Ref_Clock_Counter2_UPDOWN_SHIFT))

/* PWM output invert */
#define Ref_Clock_Counter2_INVERT_LINE                    ((uint32)(Ref_Clock_Counter2__INVERSE         <<  \
                                                                  Ref_Clock_Counter2_INV_OUT_SHIFT))
#define Ref_Clock_Counter2_INVERT_LINE_N                  ((uint32)(Ref_Clock_Counter2__INVERSE         <<  \
                                                                  Ref_Clock_Counter2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Ref_Clock_Counter2_TRIG_RISING                    ((uint32)Ref_Clock_Counter2__TRIG_RISING)
#define Ref_Clock_Counter2_TRIG_FALLING                   ((uint32)Ref_Clock_Counter2__TRIG_FALLING)
#define Ref_Clock_Counter2_TRIG_BOTH                      ((uint32)Ref_Clock_Counter2__TRIG_BOTH)
#define Ref_Clock_Counter2_TRIG_LEVEL                     ((uint32)Ref_Clock_Counter2__TRIG_LEVEL)

/* Interrupt mask */
#define Ref_Clock_Counter2_INTR_MASK_TC                   ((uint32)Ref_Clock_Counter2__INTR_MASK_TC)
#define Ref_Clock_Counter2_INTR_MASK_CC_MATCH             ((uint32)Ref_Clock_Counter2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Ref_Clock_Counter2_CC_MATCH_SET                   (0x00u)
#define Ref_Clock_Counter2_CC_MATCH_CLEAR                 (0x01u)
#define Ref_Clock_Counter2_CC_MATCH_INVERT                (0x02u)
#define Ref_Clock_Counter2_CC_MATCH_NO_CHANGE             (0x03u)
#define Ref_Clock_Counter2_OVERLOW_SET                    (0x00u)
#define Ref_Clock_Counter2_OVERLOW_CLEAR                  (0x04u)
#define Ref_Clock_Counter2_OVERLOW_INVERT                 (0x08u)
#define Ref_Clock_Counter2_OVERLOW_NO_CHANGE              (0x0Cu)
#define Ref_Clock_Counter2_UNDERFLOW_SET                  (0x00u)
#define Ref_Clock_Counter2_UNDERFLOW_CLEAR                (0x10u)
#define Ref_Clock_Counter2_UNDERFLOW_INVERT               (0x20u)
#define Ref_Clock_Counter2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Ref_Clock_Counter2_PWM_MODE_LEFT                  (Ref_Clock_Counter2_CC_MATCH_CLEAR        |   \
                                                         Ref_Clock_Counter2_OVERLOW_SET           |   \
                                                         Ref_Clock_Counter2_UNDERFLOW_NO_CHANGE)
#define Ref_Clock_Counter2_PWM_MODE_RIGHT                 (Ref_Clock_Counter2_CC_MATCH_SET          |   \
                                                         Ref_Clock_Counter2_OVERLOW_NO_CHANGE     |   \
                                                         Ref_Clock_Counter2_UNDERFLOW_CLEAR)
#define Ref_Clock_Counter2_PWM_MODE_ASYM                  (Ref_Clock_Counter2_CC_MATCH_INVERT       |   \
                                                         Ref_Clock_Counter2_OVERLOW_SET           |   \
                                                         Ref_Clock_Counter2_UNDERFLOW_CLEAR)

#if (Ref_Clock_Counter2_CY_TCPWM_V2)
    #if(Ref_Clock_Counter2_CY_TCPWM_4000)
        #define Ref_Clock_Counter2_PWM_MODE_CENTER                (Ref_Clock_Counter2_CC_MATCH_INVERT       |   \
                                                                 Ref_Clock_Counter2_OVERLOW_NO_CHANGE     |   \
                                                                 Ref_Clock_Counter2_UNDERFLOW_CLEAR)
    #else
        #define Ref_Clock_Counter2_PWM_MODE_CENTER                (Ref_Clock_Counter2_CC_MATCH_INVERT       |   \
                                                                 Ref_Clock_Counter2_OVERLOW_SET           |   \
                                                                 Ref_Clock_Counter2_UNDERFLOW_CLEAR)
    #endif /* (Ref_Clock_Counter2_CY_TCPWM_4000) */
#else
    #define Ref_Clock_Counter2_PWM_MODE_CENTER                (Ref_Clock_Counter2_CC_MATCH_INVERT       |   \
                                                             Ref_Clock_Counter2_OVERLOW_NO_CHANGE     |   \
                                                             Ref_Clock_Counter2_UNDERFLOW_CLEAR)
#endif /* (Ref_Clock_Counter2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Ref_Clock_Counter2_CMD_CAPTURE                    (0u)
#define Ref_Clock_Counter2_CMD_RELOAD                     (8u)
#define Ref_Clock_Counter2_CMD_STOP                       (16u)
#define Ref_Clock_Counter2_CMD_START                      (24u)

/* Status */
#define Ref_Clock_Counter2_STATUS_DOWN                    (1u)
#define Ref_Clock_Counter2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Ref_Clock_Counter2_Init(void);
void   Ref_Clock_Counter2_Enable(void);
void   Ref_Clock_Counter2_Start(void);
void   Ref_Clock_Counter2_Stop(void);

void   Ref_Clock_Counter2_SetMode(uint32 mode);
void   Ref_Clock_Counter2_SetCounterMode(uint32 counterMode);
void   Ref_Clock_Counter2_SetPWMMode(uint32 modeMask);
void   Ref_Clock_Counter2_SetQDMode(uint32 qdMode);

void   Ref_Clock_Counter2_SetPrescaler(uint32 prescaler);
void   Ref_Clock_Counter2_TriggerCommand(uint32 mask, uint32 command);
void   Ref_Clock_Counter2_SetOneShot(uint32 oneShotEnable);
uint32 Ref_Clock_Counter2_ReadStatus(void);

void   Ref_Clock_Counter2_SetPWMSyncKill(uint32 syncKillEnable);
void   Ref_Clock_Counter2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Ref_Clock_Counter2_SetPWMDeadTime(uint32 deadTime);
void   Ref_Clock_Counter2_SetPWMInvert(uint32 mask);

void   Ref_Clock_Counter2_SetInterruptMode(uint32 interruptMask);
uint32 Ref_Clock_Counter2_GetInterruptSourceMasked(void);
uint32 Ref_Clock_Counter2_GetInterruptSource(void);
void   Ref_Clock_Counter2_ClearInterrupt(uint32 interruptMask);
void   Ref_Clock_Counter2_SetInterrupt(uint32 interruptMask);

void   Ref_Clock_Counter2_WriteCounter(uint32 count);
uint32 Ref_Clock_Counter2_ReadCounter(void);

uint32 Ref_Clock_Counter2_ReadCapture(void);
uint32 Ref_Clock_Counter2_ReadCaptureBuf(void);

void   Ref_Clock_Counter2_WritePeriod(uint32 period);
uint32 Ref_Clock_Counter2_ReadPeriod(void);
void   Ref_Clock_Counter2_WritePeriodBuf(uint32 periodBuf);
uint32 Ref_Clock_Counter2_ReadPeriodBuf(void);

void   Ref_Clock_Counter2_WriteCompare(uint32 compare);
uint32 Ref_Clock_Counter2_ReadCompare(void);
void   Ref_Clock_Counter2_WriteCompareBuf(uint32 compareBuf);
uint32 Ref_Clock_Counter2_ReadCompareBuf(void);

void   Ref_Clock_Counter2_SetPeriodSwap(uint32 swapEnable);
void   Ref_Clock_Counter2_SetCompareSwap(uint32 swapEnable);

void   Ref_Clock_Counter2_SetCaptureMode(uint32 triggerMode);
void   Ref_Clock_Counter2_SetReloadMode(uint32 triggerMode);
void   Ref_Clock_Counter2_SetStartMode(uint32 triggerMode);
void   Ref_Clock_Counter2_SetStopMode(uint32 triggerMode);
void   Ref_Clock_Counter2_SetCountMode(uint32 triggerMode);

void   Ref_Clock_Counter2_SaveConfig(void);
void   Ref_Clock_Counter2_RestoreConfig(void);
void   Ref_Clock_Counter2_Sleep(void);
void   Ref_Clock_Counter2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Ref_Clock_Counter2_BLOCK_CONTROL_REG              (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Ref_Clock_Counter2_BLOCK_CONTROL_PTR              ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Ref_Clock_Counter2_COMMAND_REG                    (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Ref_Clock_Counter2_COMMAND_PTR                    ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Ref_Clock_Counter2_INTRRUPT_CAUSE_REG             (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Ref_Clock_Counter2_INTRRUPT_CAUSE_PTR             ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Ref_Clock_Counter2_CONTROL_REG                    (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__CTRL )
#define Ref_Clock_Counter2_CONTROL_PTR                    ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__CTRL )
#define Ref_Clock_Counter2_STATUS_REG                     (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__STATUS )
#define Ref_Clock_Counter2_STATUS_PTR                     ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__STATUS )
#define Ref_Clock_Counter2_COUNTER_REG                    (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__COUNTER )
#define Ref_Clock_Counter2_COUNTER_PTR                    ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__COUNTER )
#define Ref_Clock_Counter2_COMP_CAP_REG                   (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__CC )
#define Ref_Clock_Counter2_COMP_CAP_PTR                   ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__CC )
#define Ref_Clock_Counter2_COMP_CAP_BUF_REG               (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__CC_BUFF )
#define Ref_Clock_Counter2_COMP_CAP_BUF_PTR               ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__CC_BUFF )
#define Ref_Clock_Counter2_PERIOD_REG                     (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__PERIOD )
#define Ref_Clock_Counter2_PERIOD_PTR                     ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__PERIOD )
#define Ref_Clock_Counter2_PERIOD_BUF_REG                 (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Ref_Clock_Counter2_PERIOD_BUF_PTR                 ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Ref_Clock_Counter2_TRIG_CONTROL0_REG              (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Ref_Clock_Counter2_TRIG_CONTROL0_PTR              ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Ref_Clock_Counter2_TRIG_CONTROL1_REG              (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Ref_Clock_Counter2_TRIG_CONTROL1_PTR              ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Ref_Clock_Counter2_TRIG_CONTROL2_REG              (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Ref_Clock_Counter2_TRIG_CONTROL2_PTR              ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Ref_Clock_Counter2_INTERRUPT_REQ_REG              (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__INTR )
#define Ref_Clock_Counter2_INTERRUPT_REQ_PTR              ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__INTR )
#define Ref_Clock_Counter2_INTERRUPT_SET_REG              (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__INTR_SET )
#define Ref_Clock_Counter2_INTERRUPT_SET_PTR              ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__INTR_SET )
#define Ref_Clock_Counter2_INTERRUPT_MASK_REG             (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__INTR_MASK )
#define Ref_Clock_Counter2_INTERRUPT_MASK_PTR             ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__INTR_MASK )
#define Ref_Clock_Counter2_INTERRUPT_MASKED_REG           (*(reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Ref_Clock_Counter2_INTERRUPT_MASKED_PTR           ( (reg32 *) Ref_Clock_Counter2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Ref_Clock_Counter2_MASK                           ((uint32)Ref_Clock_Counter2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Ref_Clock_Counter2_RELOAD_CC_SHIFT                (0u)
#define Ref_Clock_Counter2_RELOAD_PERIOD_SHIFT            (1u)
#define Ref_Clock_Counter2_PWM_SYNC_KILL_SHIFT            (2u)
#define Ref_Clock_Counter2_PWM_STOP_KILL_SHIFT            (3u)
#define Ref_Clock_Counter2_PRESCALER_SHIFT                (8u)
#define Ref_Clock_Counter2_UPDOWN_SHIFT                   (16u)
#define Ref_Clock_Counter2_ONESHOT_SHIFT                  (18u)
#define Ref_Clock_Counter2_QUAD_MODE_SHIFT                (20u)
#define Ref_Clock_Counter2_INV_OUT_SHIFT                  (20u)
#define Ref_Clock_Counter2_INV_COMPL_OUT_SHIFT            (21u)
#define Ref_Clock_Counter2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Ref_Clock_Counter2_RELOAD_CC_MASK                 ((uint32)(Ref_Clock_Counter2_1BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_RELOAD_CC_SHIFT))
#define Ref_Clock_Counter2_RELOAD_PERIOD_MASK             ((uint32)(Ref_Clock_Counter2_1BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_RELOAD_PERIOD_SHIFT))
#define Ref_Clock_Counter2_PWM_SYNC_KILL_MASK             ((uint32)(Ref_Clock_Counter2_1BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_PWM_SYNC_KILL_SHIFT))
#define Ref_Clock_Counter2_PWM_STOP_KILL_MASK             ((uint32)(Ref_Clock_Counter2_1BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_PWM_STOP_KILL_SHIFT))
#define Ref_Clock_Counter2_PRESCALER_MASK                 ((uint32)(Ref_Clock_Counter2_8BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_PRESCALER_SHIFT))
#define Ref_Clock_Counter2_UPDOWN_MASK                    ((uint32)(Ref_Clock_Counter2_2BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_UPDOWN_SHIFT))
#define Ref_Clock_Counter2_ONESHOT_MASK                   ((uint32)(Ref_Clock_Counter2_1BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_ONESHOT_SHIFT))
#define Ref_Clock_Counter2_QUAD_MODE_MASK                 ((uint32)(Ref_Clock_Counter2_3BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_QUAD_MODE_SHIFT))
#define Ref_Clock_Counter2_INV_OUT_MASK                   ((uint32)(Ref_Clock_Counter2_2BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_INV_OUT_SHIFT))
#define Ref_Clock_Counter2_MODE_MASK                      ((uint32)(Ref_Clock_Counter2_3BIT_MASK        <<  \
                                                                            Ref_Clock_Counter2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Ref_Clock_Counter2_CAPTURE_SHIFT                  (0u)
#define Ref_Clock_Counter2_COUNT_SHIFT                    (2u)
#define Ref_Clock_Counter2_RELOAD_SHIFT                   (4u)
#define Ref_Clock_Counter2_STOP_SHIFT                     (6u)
#define Ref_Clock_Counter2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Ref_Clock_Counter2_CAPTURE_MASK                   ((uint32)(Ref_Clock_Counter2_2BIT_MASK        <<  \
                                                                  Ref_Clock_Counter2_CAPTURE_SHIFT))
#define Ref_Clock_Counter2_COUNT_MASK                     ((uint32)(Ref_Clock_Counter2_2BIT_MASK        <<  \
                                                                  Ref_Clock_Counter2_COUNT_SHIFT))
#define Ref_Clock_Counter2_RELOAD_MASK                    ((uint32)(Ref_Clock_Counter2_2BIT_MASK        <<  \
                                                                  Ref_Clock_Counter2_RELOAD_SHIFT))
#define Ref_Clock_Counter2_STOP_MASK                      ((uint32)(Ref_Clock_Counter2_2BIT_MASK        <<  \
                                                                  Ref_Clock_Counter2_STOP_SHIFT))
#define Ref_Clock_Counter2_START_MASK                     ((uint32)(Ref_Clock_Counter2_2BIT_MASK        <<  \
                                                                  Ref_Clock_Counter2_START_SHIFT))

/* MASK */
#define Ref_Clock_Counter2_1BIT_MASK                      ((uint32)0x01u)
#define Ref_Clock_Counter2_2BIT_MASK                      ((uint32)0x03u)
#define Ref_Clock_Counter2_3BIT_MASK                      ((uint32)0x07u)
#define Ref_Clock_Counter2_6BIT_MASK                      ((uint32)0x3Fu)
#define Ref_Clock_Counter2_8BIT_MASK                      ((uint32)0xFFu)
#define Ref_Clock_Counter2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Ref_Clock_Counter2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Ref_Clock_Counter2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Ref_Clock_Counter2_QUAD_ENCODING_MODES     << Ref_Clock_Counter2_QUAD_MODE_SHIFT))       |\
         ((uint32)(Ref_Clock_Counter2_CONFIG                  << Ref_Clock_Counter2_MODE_SHIFT)))

#define Ref_Clock_Counter2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Ref_Clock_Counter2_PWM_STOP_EVENT          << Ref_Clock_Counter2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Ref_Clock_Counter2_PWM_OUT_INVERT          << Ref_Clock_Counter2_INV_OUT_SHIFT))         |\
         ((uint32)(Ref_Clock_Counter2_PWM_OUT_N_INVERT        << Ref_Clock_Counter2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Ref_Clock_Counter2_PWM_MODE                << Ref_Clock_Counter2_MODE_SHIFT)))

#define Ref_Clock_Counter2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Ref_Clock_Counter2_PWM_RUN_MODE         << Ref_Clock_Counter2_ONESHOT_SHIFT))
            
#define Ref_Clock_Counter2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Ref_Clock_Counter2_PWM_ALIGN            << Ref_Clock_Counter2_UPDOWN_SHIFT))

#define Ref_Clock_Counter2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Ref_Clock_Counter2_PWM_KILL_EVENT      << Ref_Clock_Counter2_PWM_SYNC_KILL_SHIFT))

#define Ref_Clock_Counter2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Ref_Clock_Counter2_PWM_DEAD_TIME_CYCLE  << Ref_Clock_Counter2_PRESCALER_SHIFT))

#define Ref_Clock_Counter2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Ref_Clock_Counter2_PWM_PRESCALER        << Ref_Clock_Counter2_PRESCALER_SHIFT))

#define Ref_Clock_Counter2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Ref_Clock_Counter2_TC_PRESCALER            << Ref_Clock_Counter2_PRESCALER_SHIFT))       |\
         ((uint32)(Ref_Clock_Counter2_TC_COUNTER_MODE         << Ref_Clock_Counter2_UPDOWN_SHIFT))          |\
         ((uint32)(Ref_Clock_Counter2_TC_RUN_MODE             << Ref_Clock_Counter2_ONESHOT_SHIFT))         |\
         ((uint32)(Ref_Clock_Counter2_TC_COMP_CAP_MODE        << Ref_Clock_Counter2_MODE_SHIFT)))
        
#define Ref_Clock_Counter2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Ref_Clock_Counter2_QUAD_PHIA_SIGNAL_MODE   << Ref_Clock_Counter2_COUNT_SHIFT))           |\
         ((uint32)(Ref_Clock_Counter2_QUAD_INDEX_SIGNAL_MODE  << Ref_Clock_Counter2_RELOAD_SHIFT))          |\
         ((uint32)(Ref_Clock_Counter2_QUAD_STOP_SIGNAL_MODE   << Ref_Clock_Counter2_STOP_SHIFT))            |\
         ((uint32)(Ref_Clock_Counter2_QUAD_PHIB_SIGNAL_MODE   << Ref_Clock_Counter2_START_SHIFT)))

#define Ref_Clock_Counter2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Ref_Clock_Counter2_PWM_SWITCH_SIGNAL_MODE  << Ref_Clock_Counter2_CAPTURE_SHIFT))         |\
         ((uint32)(Ref_Clock_Counter2_PWM_COUNT_SIGNAL_MODE   << Ref_Clock_Counter2_COUNT_SHIFT))           |\
         ((uint32)(Ref_Clock_Counter2_PWM_RELOAD_SIGNAL_MODE  << Ref_Clock_Counter2_RELOAD_SHIFT))          |\
         ((uint32)(Ref_Clock_Counter2_PWM_STOP_SIGNAL_MODE    << Ref_Clock_Counter2_STOP_SHIFT))            |\
         ((uint32)(Ref_Clock_Counter2_PWM_START_SIGNAL_MODE   << Ref_Clock_Counter2_START_SHIFT)))

#define Ref_Clock_Counter2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Ref_Clock_Counter2_TC_CAPTURE_SIGNAL_MODE  << Ref_Clock_Counter2_CAPTURE_SHIFT))         |\
         ((uint32)(Ref_Clock_Counter2_TC_COUNT_SIGNAL_MODE    << Ref_Clock_Counter2_COUNT_SHIFT))           |\
         ((uint32)(Ref_Clock_Counter2_TC_RELOAD_SIGNAL_MODE   << Ref_Clock_Counter2_RELOAD_SHIFT))          |\
         ((uint32)(Ref_Clock_Counter2_TC_STOP_SIGNAL_MODE     << Ref_Clock_Counter2_STOP_SHIFT))            |\
         ((uint32)(Ref_Clock_Counter2_TC_START_SIGNAL_MODE    << Ref_Clock_Counter2_START_SHIFT)))
        
#define Ref_Clock_Counter2_TIMER_UPDOWN_CNT_USED                                                          \
                ((Ref_Clock_Counter2__COUNT_UPDOWN0 == Ref_Clock_Counter2_TC_COUNTER_MODE)                  ||\
                 (Ref_Clock_Counter2__COUNT_UPDOWN1 == Ref_Clock_Counter2_TC_COUNTER_MODE))

#define Ref_Clock_Counter2_PWM_UPDOWN_CNT_USED                                                            \
                ((Ref_Clock_Counter2__CENTER == Ref_Clock_Counter2_PWM_ALIGN)                               ||\
                 (Ref_Clock_Counter2__ASYMMETRIC == Ref_Clock_Counter2_PWM_ALIGN))               
        
#define Ref_Clock_Counter2_PWM_PR_INIT_VALUE              (1u)
#define Ref_Clock_Counter2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Ref_Clock_Counter2_H */

/* [] END OF FILE */
