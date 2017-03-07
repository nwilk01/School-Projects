/*******************************************************************************
* File Name: Buffer_Out.h  
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

#if !defined(CY_PINS_Buffer_Out_H) /* Pins Buffer_Out_H */
#define CY_PINS_Buffer_Out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Buffer_Out_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Buffer_Out_Write(uint8 value) ;
void    Buffer_Out_SetDriveMode(uint8 mode) ;
uint8   Buffer_Out_ReadDataReg(void) ;
uint8   Buffer_Out_Read(void) ;
uint8   Buffer_Out_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Buffer_Out_DRIVE_MODE_BITS        (3)
#define Buffer_Out_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Buffer_Out_DRIVE_MODE_BITS))

#define Buffer_Out_DM_ALG_HIZ         (0x00u)
#define Buffer_Out_DM_DIG_HIZ         (0x01u)
#define Buffer_Out_DM_RES_UP          (0x02u)
#define Buffer_Out_DM_RES_DWN         (0x03u)
#define Buffer_Out_DM_OD_LO           (0x04u)
#define Buffer_Out_DM_OD_HI           (0x05u)
#define Buffer_Out_DM_STRONG          (0x06u)
#define Buffer_Out_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Buffer_Out_MASK               Buffer_Out__MASK
#define Buffer_Out_SHIFT              Buffer_Out__SHIFT
#define Buffer_Out_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Buffer_Out_PS                     (* (reg32 *) Buffer_Out__PS)
/* Port Configuration */
#define Buffer_Out_PC                     (* (reg32 *) Buffer_Out__PC)
/* Data Register */
#define Buffer_Out_DR                     (* (reg32 *) Buffer_Out__DR)
/* Input Buffer Disable Override */
#define Buffer_Out_INP_DIS                (* (reg32 *) Buffer_Out__PC2)


#if defined(Buffer_Out__INTSTAT)  /* Interrupt Registers */

    #define Buffer_Out_INTSTAT                (* (reg32 *) Buffer_Out__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Buffer_Out_DRIVE_MODE_SHIFT       (0x00u)
#define Buffer_Out_DRIVE_MODE_MASK        (0x07u << Buffer_Out_DRIVE_MODE_SHIFT)


#endif /* End Pins Buffer_Out_H */


/* [] END OF FILE */
