/*******************************************************************************
* File Name: Frequency_Input.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Frequency_Input_H) /* Pins Frequency_Input_H */
#define CY_PINS_Frequency_Input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Frequency_Input_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Frequency_Input_Write(uint8 value) ;
void    Frequency_Input_SetDriveMode(uint8 mode) ;
uint8   Frequency_Input_ReadDataReg(void) ;
uint8   Frequency_Input_Read(void) ;
uint8   Frequency_Input_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Frequency_Input_DRIVE_MODE_BITS        (3)
#define Frequency_Input_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Frequency_Input_DRIVE_MODE_BITS))

#define Frequency_Input_DM_ALG_HIZ         (0x00u)
#define Frequency_Input_DM_DIG_HIZ         (0x01u)
#define Frequency_Input_DM_RES_UP          (0x02u)
#define Frequency_Input_DM_RES_DWN         (0x03u)
#define Frequency_Input_DM_OD_LO           (0x04u)
#define Frequency_Input_DM_OD_HI           (0x05u)
#define Frequency_Input_DM_STRONG          (0x06u)
#define Frequency_Input_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Frequency_Input_MASK               Frequency_Input__MASK
#define Frequency_Input_SHIFT              Frequency_Input__SHIFT
#define Frequency_Input_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Frequency_Input_PS                     (* (reg32 *) Frequency_Input__PS)
/* Port Configuration */
#define Frequency_Input_PC                     (* (reg32 *) Frequency_Input__PC)
/* Data Register */
#define Frequency_Input_DR                     (* (reg32 *) Frequency_Input__DR)
/* Input Buffer Disable Override */
#define Frequency_Input_INP_DIS                (* (reg32 *) Frequency_Input__PC2)


#if defined(Frequency_Input__INTSTAT)  /* Interrupt Registers */

    #define Frequency_Input_INTSTAT                (* (reg32 *) Frequency_Input__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Frequency_Input_DRIVE_MODE_SHIFT       (0x00u)
#define Frequency_Input_DRIVE_MODE_MASK        (0x07u << Frequency_Input_DRIVE_MODE_SHIFT)


#endif /* End Pins Frequency_Input_H */


/* [] END OF FILE */
