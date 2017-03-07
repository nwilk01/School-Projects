/*******************************************************************************
* File Name: Comp_Out.h  
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

#if !defined(CY_PINS_Comp_Out_H) /* Pins Comp_Out_H */
#define CY_PINS_Comp_Out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Comp_Out_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Comp_Out_Write(uint8 value) ;
void    Comp_Out_SetDriveMode(uint8 mode) ;
uint8   Comp_Out_ReadDataReg(void) ;
uint8   Comp_Out_Read(void) ;
uint8   Comp_Out_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Comp_Out_DRIVE_MODE_BITS        (3)
#define Comp_Out_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Comp_Out_DRIVE_MODE_BITS))

#define Comp_Out_DM_ALG_HIZ         (0x00u)
#define Comp_Out_DM_DIG_HIZ         (0x01u)
#define Comp_Out_DM_RES_UP          (0x02u)
#define Comp_Out_DM_RES_DWN         (0x03u)
#define Comp_Out_DM_OD_LO           (0x04u)
#define Comp_Out_DM_OD_HI           (0x05u)
#define Comp_Out_DM_STRONG          (0x06u)
#define Comp_Out_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Comp_Out_MASK               Comp_Out__MASK
#define Comp_Out_SHIFT              Comp_Out__SHIFT
#define Comp_Out_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Comp_Out_PS                     (* (reg32 *) Comp_Out__PS)
/* Port Configuration */
#define Comp_Out_PC                     (* (reg32 *) Comp_Out__PC)
/* Data Register */
#define Comp_Out_DR                     (* (reg32 *) Comp_Out__DR)
/* Input Buffer Disable Override */
#define Comp_Out_INP_DIS                (* (reg32 *) Comp_Out__PC2)


#if defined(Comp_Out__INTSTAT)  /* Interrupt Registers */

    #define Comp_Out_INTSTAT                (* (reg32 *) Comp_Out__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Comp_Out_DRIVE_MODE_SHIFT       (0x00u)
#define Comp_Out_DRIVE_MODE_MASK        (0x07u << Comp_Out_DRIVE_MODE_SHIFT)


#endif /* End Pins Comp_Out_H */


/* [] END OF FILE */
