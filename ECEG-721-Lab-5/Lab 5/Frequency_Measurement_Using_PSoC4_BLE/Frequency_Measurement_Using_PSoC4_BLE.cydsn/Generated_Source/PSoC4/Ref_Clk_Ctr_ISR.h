/*******************************************************************************
* File Name: Ref_Clk_Ctr_ISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Ref_Clk_Ctr_ISR_H)
#define CY_ISR_Ref_Clk_Ctr_ISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Ref_Clk_Ctr_ISR_Start(void);
void Ref_Clk_Ctr_ISR_StartEx(cyisraddress address);
void Ref_Clk_Ctr_ISR_Stop(void);

CY_ISR_PROTO(Ref_Clk_Ctr_ISR_Interrupt);

void Ref_Clk_Ctr_ISR_SetVector(cyisraddress address);
cyisraddress Ref_Clk_Ctr_ISR_GetVector(void);

void Ref_Clk_Ctr_ISR_SetPriority(uint8 priority);
uint8 Ref_Clk_Ctr_ISR_GetPriority(void);

void Ref_Clk_Ctr_ISR_Enable(void);
uint8 Ref_Clk_Ctr_ISR_GetState(void);
void Ref_Clk_Ctr_ISR_Disable(void);

void Ref_Clk_Ctr_ISR_SetPending(void);
void Ref_Clk_Ctr_ISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Ref_Clk_Ctr_ISR ISR. */
#define Ref_Clk_Ctr_ISR_INTC_VECTOR            ((reg32 *) Ref_Clk_Ctr_ISR__INTC_VECT)

/* Address of the Ref_Clk_Ctr_ISR ISR priority. */
#define Ref_Clk_Ctr_ISR_INTC_PRIOR             ((reg32 *) Ref_Clk_Ctr_ISR__INTC_PRIOR_REG)

/* Priority of the Ref_Clk_Ctr_ISR interrupt. */
#define Ref_Clk_Ctr_ISR_INTC_PRIOR_NUMBER      Ref_Clk_Ctr_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Ref_Clk_Ctr_ISR interrupt. */
#define Ref_Clk_Ctr_ISR_INTC_SET_EN            ((reg32 *) Ref_Clk_Ctr_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Ref_Clk_Ctr_ISR interrupt. */
#define Ref_Clk_Ctr_ISR_INTC_CLR_EN            ((reg32 *) Ref_Clk_Ctr_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Ref_Clk_Ctr_ISR interrupt state to pending. */
#define Ref_Clk_Ctr_ISR_INTC_SET_PD            ((reg32 *) Ref_Clk_Ctr_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Ref_Clk_Ctr_ISR interrupt. */
#define Ref_Clk_Ctr_ISR_INTC_CLR_PD            ((reg32 *) Ref_Clk_Ctr_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_Ref_Clk_Ctr_ISR_H */


/* [] END OF FILE */
