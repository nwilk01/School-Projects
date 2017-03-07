/*******************************************************************************
* File Name: Comparator.h
* Version 1.10
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Opamp (Analog Buffer) Component.
*
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_OPAMP_Comparator_H)
#define CY_OPAMP_Comparator_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*       Type Definitions
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Comparator_BACKUP_STRUCT;


/**************************************
*        Function Prototypes
**************************************/
void Comparator_Init(void);
void Comparator_Enable(void);
void Comparator_Start(void);
void Comparator_Stop(void);
void Comparator_SetPower(uint32 power);
void Comparator_PumpControl(uint32 onOff);
void Comparator_Sleep(void);
void Comparator_Wakeup(void);
void Comparator_SaveConfig(void);
void Comparator_RestoreConfig(void);


/**************************************
*           API Constants
**************************************/

/* Parameters for SetPower() function */
#define Comparator_LOW_POWER      (1u)
#define Comparator_MED_POWER      (2u)
#define Comparator_HIGH_POWER     (3u)


/* Parameters for PumpControl() function */
#define Comparator_PUMP_ON        (1u)
#define Comparator_PUMP_OFF       (0u)


/***************************************
*   Initial Parameter Constants
****************************************/

#define Comparator_OUTPUT_CURRENT         (1u)
#define Comparator_POWER                  (3u)
#define Comparator_MODE                   (0u)
#define Comparator_OA_COMP_TRIM_VALUE     (3u)
#define Comparator_DEEPSLEEP_SUPPORT      (0u)


/***************************************
*    Variables with External Linkage
***************************************/

extern uint8  Comparator_initVar;


/**************************************
*             Registers
**************************************/
#define Comparator_CTB_CTRL_REG       (*(reg32 *) Comparator_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define Comparator_CTB_CTRL_PTR       ( (reg32 *) Comparator_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define Comparator_OA_RES_CTRL_REG    (*(reg32 *) Comparator_cy_psoc4_abuf__OA_RES_CTRL)
#define Comparator_OA_RES_CTRL_PTR    ( (reg32 *) Comparator_cy_psoc4_abuf__OA_RES_CTRL)
#define Comparator_OA_COMP_TRIM_REG   (*(reg32 *) Comparator_cy_psoc4_abuf__OA_COMP_TRIM)
#define Comparator_OA_COMP_TRIM_PTR   ( (reg32 *) Comparator_cy_psoc4_abuf__OA_COMP_TRIM)


/***************************************
*        Registers Constants
***************************************/

/* Comparator_CTB_CTRL_REG */
#define Comparator_CTB_CTRL_DEEPSLEEP_ON_SHIFT    (30u)   /* [30] Selects behavior CTB IP in the DeepSleep power mode */
#define Comparator_CTB_CTRL_ENABLED_SHIFT         (31u)   /* [31] Enable of the CTB IP */


#define Comparator_CTB_CTRL_DEEPSLEEP_ON          ((uint32) 0x01u << Comparator_CTB_CTRL_DEEPSLEEP_ON_SHIFT)
#define Comparator_CTB_CTRL_ENABLED               ((uint32) 0x01u << Comparator_CTB_CTRL_ENABLED_SHIFT)


/* Comparator_OA_RES_CTRL_REG */
#define Comparator_OA_PWR_MODE_SHIFT          (0u)    /* [1:0]    Power level */
#define Comparator_OA_DRIVE_STR_SEL_SHIFT     (2u)    /* [2]      Opamp output strenght select: 0 - 1x, 1 - 10x */
#define Comparator_OA_COMP_EN_SHIFT           (4u)    /* [4]      CTB IP mode: 0 - Opamp, 1 - Comparator  */
#define Comparator_OA_PUMP_EN_SHIFT           (11u)   /* [11]     Pump enable */


#define Comparator_OA_PWR_MODE                ((uint32) 0x02u << Comparator_OA_PWR_MODE_SHIFT)
#define Comparator_OA_PWR_MODE_MASK           ((uint32) 0x03u << Comparator_OA_PWR_MODE_SHIFT)
#define Comparator_OA_DRIVE_STR_SEL_1X        ((uint32) 0x00u << Comparator_OA_DRIVE_STR_SEL_SHIFT)
#define Comparator_OA_DRIVE_STR_SEL_10X       ((uint32) 0x01u << Comparator_OA_DRIVE_STR_SEL_SHIFT)
#define Comparator_OA_DRIVE_STR_SEL_MASK      ((uint32) 0x01u << Comparator_OA_DRIVE_STR_SEL_SHIFT)
#define Comparator_OA_COMP_EN                 ((uint32) 0x00u << Comparator_OA_COMP_EN_SHIFT)
#define Comparator_OA_PUMP_EN                 ((uint32) 0x01u << Comparator_OA_PUMP_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define Comparator_GET_DEEPSLEEP_ON(deepSleep)    ((0u != (deepSleep)) ? (Comparator_CTB_CTRL_DEEPSLEEP_ON) : (0u))
#define Comparator_GET_OA_DRIVE_STR(current)      ((0u != (current)) ? (Comparator_OA_DRIVE_STR_SEL_10X) : \
                                                                             (Comparator_OA_DRIVE_STR_SEL_1X))
#define Comparator_GET_OA_PWR_MODE(mode)          ((mode) & Comparator_OA_PWR_MODE_MASK)
#define Comparator_CHECK_PWR_MODE_OFF             (0u != (Comparator_OA_RES_CTRL_REG & \
                                                                Comparator_OA_PWR_MODE_MASK))

/* Returns true if component available in Deep Sleep power mode*/ 
#define Comparator_CHECK_DEEPSLEEP_SUPPORT        (0u != Comparator_DEEPSLEEP_SUPPORT) 

#define Comparator_DEFAULT_CTB_CTRL (Comparator_GET_DEEPSLEEP_ON(Comparator_DEEPSLEEP_SUPPORT) | \
                                           Comparator_CTB_CTRL_ENABLED)

#define Comparator_DEFAULT_OA_RES_CTRL (Comparator_OA_COMP_EN | \
                                              Comparator_GET_OA_DRIVE_STR(Comparator_OUTPUT_CURRENT))

#define Comparator_DEFAULT_OA_COMP_TRIM_REG (Comparator_OA_COMP_TRIM_VALUE)


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define Comparator_LOWPOWER                   (Comparator_LOW_POWER)
#define Comparator_MEDPOWER                   (Comparator_MED_POWER)
#define Comparator_HIGHPOWER                  (Comparator_HIGH_POWER)

/* PUMP ON/OFF defines */
#define Comparator_PUMPON                     (Comparator_PUMP_ON)
#define Comparator_PUMPOFF                    (Comparator_PUMP_OFF)

#define Comparator_OA_CTRL                    (Comparator_CTB_CTRL_REG)
#define Comparator_OA_RES_CTRL                (Comparator_OA_RES_CTRL_REG)

/* Bit Field  OA_CTRL */
#define Comparator_OA_CTB_EN_SHIFT            (Comparator_CTB_CTRL_ENABLED_SHIFT)
#define Comparator_OA_PUMP_CTRL_SHIFT         (Comparator_OA_PUMP_EN_SHIFT)
#define Comparator_OA_PUMP_EN_MASK            (0x800u)
#define Comparator_PUMP_PROTECT_MASK          (1u)


#endif    /* CY_OPAMP_Comparator_H */


/* [] END OF FILE */
