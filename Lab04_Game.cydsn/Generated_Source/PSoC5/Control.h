/*******************************************************************************
* File Name: Control.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Control_H) /* Pins Control_H */
#define CY_PINS_Control_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Control_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Control__PORT == 15 && ((Control__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Control_Write(uint8 value);
void    Control_SetDriveMode(uint8 mode);
uint8   Control_ReadDataReg(void);
uint8   Control_Read(void);
void    Control_SetInterruptMode(uint16 position, uint16 mode);
uint8   Control_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Control_SetDriveMode() function.
     *  @{
     */
        #define Control_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Control_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Control_DM_RES_UP          PIN_DM_RES_UP
        #define Control_DM_RES_DWN         PIN_DM_RES_DWN
        #define Control_DM_OD_LO           PIN_DM_OD_LO
        #define Control_DM_OD_HI           PIN_DM_OD_HI
        #define Control_DM_STRONG          PIN_DM_STRONG
        #define Control_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Control_MASK               Control__MASK
#define Control_SHIFT              Control__SHIFT
#define Control_WIDTH              2u

/* Interrupt constants */
#if defined(Control__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Control_SetInterruptMode() function.
     *  @{
     */
        #define Control_INTR_NONE      (uint16)(0x0000u)
        #define Control_INTR_RISING    (uint16)(0x0001u)
        #define Control_INTR_FALLING   (uint16)(0x0002u)
        #define Control_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Control_INTR_MASK      (0x01u) 
#endif /* (Control__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Control_PS                     (* (reg8 *) Control__PS)
/* Data Register */
#define Control_DR                     (* (reg8 *) Control__DR)
/* Port Number */
#define Control_PRT_NUM                (* (reg8 *) Control__PRT) 
/* Connect to Analog Globals */                                                  
#define Control_AG                     (* (reg8 *) Control__AG)                       
/* Analog MUX bux enable */
#define Control_AMUX                   (* (reg8 *) Control__AMUX) 
/* Bidirectional Enable */                                                        
#define Control_BIE                    (* (reg8 *) Control__BIE)
/* Bit-mask for Aliased Register Access */
#define Control_BIT_MASK               (* (reg8 *) Control__BIT_MASK)
/* Bypass Enable */
#define Control_BYP                    (* (reg8 *) Control__BYP)
/* Port wide control signals */                                                   
#define Control_CTL                    (* (reg8 *) Control__CTL)
/* Drive Modes */
#define Control_DM0                    (* (reg8 *) Control__DM0) 
#define Control_DM1                    (* (reg8 *) Control__DM1)
#define Control_DM2                    (* (reg8 *) Control__DM2) 
/* Input Buffer Disable Override */
#define Control_INP_DIS                (* (reg8 *) Control__INP_DIS)
/* LCD Common or Segment Drive */
#define Control_LCD_COM_SEG            (* (reg8 *) Control__LCD_COM_SEG)
/* Enable Segment LCD */
#define Control_LCD_EN                 (* (reg8 *) Control__LCD_EN)
/* Slew Rate Control */
#define Control_SLW                    (* (reg8 *) Control__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Control_PRTDSI__CAPS_SEL       (* (reg8 *) Control__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Control_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Control__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Control_PRTDSI__OE_SEL0        (* (reg8 *) Control__PRTDSI__OE_SEL0) 
#define Control_PRTDSI__OE_SEL1        (* (reg8 *) Control__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Control_PRTDSI__OUT_SEL0       (* (reg8 *) Control__PRTDSI__OUT_SEL0) 
#define Control_PRTDSI__OUT_SEL1       (* (reg8 *) Control__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Control_PRTDSI__SYNC_OUT       (* (reg8 *) Control__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Control__SIO_CFG)
    #define Control_SIO_HYST_EN        (* (reg8 *) Control__SIO_HYST_EN)
    #define Control_SIO_REG_HIFREQ     (* (reg8 *) Control__SIO_REG_HIFREQ)
    #define Control_SIO_CFG            (* (reg8 *) Control__SIO_CFG)
    #define Control_SIO_DIFF           (* (reg8 *) Control__SIO_DIFF)
#endif /* (Control__SIO_CFG) */

/* Interrupt Registers */
#if defined(Control__INTSTAT)
    #define Control_INTSTAT            (* (reg8 *) Control__INTSTAT)
    #define Control_SNAP               (* (reg8 *) Control__SNAP)
    
	#define Control_0_INTTYPE_REG 		(* (reg8 *) Control__0__INTTYPE)
	#define Control_1_INTTYPE_REG 		(* (reg8 *) Control__1__INTTYPE)
#endif /* (Control__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Control_H */


/* [] END OF FILE */
