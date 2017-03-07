/*******************************************************************************
* File Name: Comp_NegInput.h  
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

#if !defined(CY_PINS_Comp_NegInput_H) /* Pins Comp_NegInput_H */
#define CY_PINS_Comp_NegInput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Comp_NegInput_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Comp_NegInput_Write(uint8 value) ;
void    Comp_NegInput_SetDriveMode(uint8 mode) ;
uint8   Comp_NegInput_ReadDataReg(void) ;
uint8   Comp_NegInput_Read(void) ;
uint8   Comp_NegInput_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Comp_NegInput_DRIVE_MODE_BITS        (3)
#define Comp_NegInput_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Comp_NegInput_DRIVE_MODE_BITS))

#define Comp_NegInput_DM_ALG_HIZ         (0x00u)
#define Comp_NegInput_DM_DIG_HIZ         (0x01u)
#define Comp_NegInput_DM_RES_UP          (0x02u)
#define Comp_NegInput_DM_RES_DWN         (0x03u)
#define Comp_NegInput_DM_OD_LO           (0x04u)
#define Comp_NegInput_DM_OD_HI           (0x05u)
#define Comp_NegInput_DM_STRONG          (0x06u)
#define Comp_NegInput_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Comp_NegInput_MASK               Comp_NegInput__MASK
#define Comp_NegInput_SHIFT              Comp_NegInput__SHIFT
#define Comp_NegInput_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Comp_NegInput_PS                     (* (reg32 *) Comp_NegInput__PS)
/* Port Configuration */
#define Comp_NegInput_PC                     (* (reg32 *) Comp_NegInput__PC)
/* Data Register */
#define Comp_NegInput_DR                     (* (reg32 *) Comp_NegInput__DR)
/* Input Buffer Disable Override */
#define Comp_NegInput_INP_DIS                (* (reg32 *) Comp_NegInput__PC2)


#if defined(Comp_NegInput__INTSTAT)  /* Interrupt Registers */

    #define Comp_NegInput_INTSTAT                (* (reg32 *) Comp_NegInput__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Comp_NegInput_DRIVE_MODE_SHIFT       (0x00u)
#define Comp_NegInput_DRIVE_MODE_MASK        (0x07u << Comp_NegInput_DRIVE_MODE_SHIFT)


#endif /* End Pins Comp_NegInput_H */


/* [] END OF FILE */
