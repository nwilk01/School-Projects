/*******************************************************************************
* File Name: Comp_PosInput.h  
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

#if !defined(CY_PINS_Comp_PosInput_H) /* Pins Comp_PosInput_H */
#define CY_PINS_Comp_PosInput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Comp_PosInput_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Comp_PosInput_Write(uint8 value) ;
void    Comp_PosInput_SetDriveMode(uint8 mode) ;
uint8   Comp_PosInput_ReadDataReg(void) ;
uint8   Comp_PosInput_Read(void) ;
uint8   Comp_PosInput_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Comp_PosInput_DRIVE_MODE_BITS        (3)
#define Comp_PosInput_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Comp_PosInput_DRIVE_MODE_BITS))

#define Comp_PosInput_DM_ALG_HIZ         (0x00u)
#define Comp_PosInput_DM_DIG_HIZ         (0x01u)
#define Comp_PosInput_DM_RES_UP          (0x02u)
#define Comp_PosInput_DM_RES_DWN         (0x03u)
#define Comp_PosInput_DM_OD_LO           (0x04u)
#define Comp_PosInput_DM_OD_HI           (0x05u)
#define Comp_PosInput_DM_STRONG          (0x06u)
#define Comp_PosInput_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Comp_PosInput_MASK               Comp_PosInput__MASK
#define Comp_PosInput_SHIFT              Comp_PosInput__SHIFT
#define Comp_PosInput_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Comp_PosInput_PS                     (* (reg32 *) Comp_PosInput__PS)
/* Port Configuration */
#define Comp_PosInput_PC                     (* (reg32 *) Comp_PosInput__PC)
/* Data Register */
#define Comp_PosInput_DR                     (* (reg32 *) Comp_PosInput__DR)
/* Input Buffer Disable Override */
#define Comp_PosInput_INP_DIS                (* (reg32 *) Comp_PosInput__PC2)


#if defined(Comp_PosInput__INTSTAT)  /* Interrupt Registers */

    #define Comp_PosInput_INTSTAT                (* (reg32 *) Comp_PosInput__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Comp_PosInput_DRIVE_MODE_SHIFT       (0x00u)
#define Comp_PosInput_DRIVE_MODE_MASK        (0x07u << Comp_PosInput_DRIVE_MODE_SHIFT)


#endif /* End Pins Comp_PosInput_H */


/* [] END OF FILE */
