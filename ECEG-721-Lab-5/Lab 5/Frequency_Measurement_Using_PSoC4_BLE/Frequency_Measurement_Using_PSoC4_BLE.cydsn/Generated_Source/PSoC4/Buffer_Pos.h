/*******************************************************************************
* File Name: Buffer_Pos.h  
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

#if !defined(CY_PINS_Buffer_Pos_H) /* Pins Buffer_Pos_H */
#define CY_PINS_Buffer_Pos_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Buffer_Pos_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Buffer_Pos_Write(uint8 value) ;
void    Buffer_Pos_SetDriveMode(uint8 mode) ;
uint8   Buffer_Pos_ReadDataReg(void) ;
uint8   Buffer_Pos_Read(void) ;
uint8   Buffer_Pos_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Buffer_Pos_DRIVE_MODE_BITS        (3)
#define Buffer_Pos_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Buffer_Pos_DRIVE_MODE_BITS))

#define Buffer_Pos_DM_ALG_HIZ         (0x00u)
#define Buffer_Pos_DM_DIG_HIZ         (0x01u)
#define Buffer_Pos_DM_RES_UP          (0x02u)
#define Buffer_Pos_DM_RES_DWN         (0x03u)
#define Buffer_Pos_DM_OD_LO           (0x04u)
#define Buffer_Pos_DM_OD_HI           (0x05u)
#define Buffer_Pos_DM_STRONG          (0x06u)
#define Buffer_Pos_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Buffer_Pos_MASK               Buffer_Pos__MASK
#define Buffer_Pos_SHIFT              Buffer_Pos__SHIFT
#define Buffer_Pos_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Buffer_Pos_PS                     (* (reg32 *) Buffer_Pos__PS)
/* Port Configuration */
#define Buffer_Pos_PC                     (* (reg32 *) Buffer_Pos__PC)
/* Data Register */
#define Buffer_Pos_DR                     (* (reg32 *) Buffer_Pos__DR)
/* Input Buffer Disable Override */
#define Buffer_Pos_INP_DIS                (* (reg32 *) Buffer_Pos__PC2)


#if defined(Buffer_Pos__INTSTAT)  /* Interrupt Registers */

    #define Buffer_Pos_INTSTAT                (* (reg32 *) Buffer_Pos__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Buffer_Pos_DRIVE_MODE_SHIFT       (0x00u)
#define Buffer_Pos_DRIVE_MODE_MASK        (0x07u << Buffer_Pos_DRIVE_MODE_SHIFT)


#endif /* End Pins Buffer_Pos_H */


/* [] END OF FILE */
