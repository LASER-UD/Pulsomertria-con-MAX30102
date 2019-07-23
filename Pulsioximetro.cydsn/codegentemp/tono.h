/*******************************************************************************
* File Name: tono.h  
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

#if !defined(CY_PINS_tono_H) /* Pins tono_H */
#define CY_PINS_tono_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "tono_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 tono__PORT == 15 && ((tono__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    tono_Write(uint8 value);
void    tono_SetDriveMode(uint8 mode);
uint8   tono_ReadDataReg(void);
uint8   tono_Read(void);
void    tono_SetInterruptMode(uint16 position, uint16 mode);
uint8   tono_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the tono_SetDriveMode() function.
     *  @{
     */
        #define tono_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define tono_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define tono_DM_RES_UP          PIN_DM_RES_UP
        #define tono_DM_RES_DWN         PIN_DM_RES_DWN
        #define tono_DM_OD_LO           PIN_DM_OD_LO
        #define tono_DM_OD_HI           PIN_DM_OD_HI
        #define tono_DM_STRONG          PIN_DM_STRONG
        #define tono_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define tono_MASK               tono__MASK
#define tono_SHIFT              tono__SHIFT
#define tono_WIDTH              1u

/* Interrupt constants */
#if defined(tono__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in tono_SetInterruptMode() function.
     *  @{
     */
        #define tono_INTR_NONE      (uint16)(0x0000u)
        #define tono_INTR_RISING    (uint16)(0x0001u)
        #define tono_INTR_FALLING   (uint16)(0x0002u)
        #define tono_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define tono_INTR_MASK      (0x01u) 
#endif /* (tono__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define tono_PS                     (* (reg8 *) tono__PS)
/* Data Register */
#define tono_DR                     (* (reg8 *) tono__DR)
/* Port Number */
#define tono_PRT_NUM                (* (reg8 *) tono__PRT) 
/* Connect to Analog Globals */                                                  
#define tono_AG                     (* (reg8 *) tono__AG)                       
/* Analog MUX bux enable */
#define tono_AMUX                   (* (reg8 *) tono__AMUX) 
/* Bidirectional Enable */                                                        
#define tono_BIE                    (* (reg8 *) tono__BIE)
/* Bit-mask for Aliased Register Access */
#define tono_BIT_MASK               (* (reg8 *) tono__BIT_MASK)
/* Bypass Enable */
#define tono_BYP                    (* (reg8 *) tono__BYP)
/* Port wide control signals */                                                   
#define tono_CTL                    (* (reg8 *) tono__CTL)
/* Drive Modes */
#define tono_DM0                    (* (reg8 *) tono__DM0) 
#define tono_DM1                    (* (reg8 *) tono__DM1)
#define tono_DM2                    (* (reg8 *) tono__DM2) 
/* Input Buffer Disable Override */
#define tono_INP_DIS                (* (reg8 *) tono__INP_DIS)
/* LCD Common or Segment Drive */
#define tono_LCD_COM_SEG            (* (reg8 *) tono__LCD_COM_SEG)
/* Enable Segment LCD */
#define tono_LCD_EN                 (* (reg8 *) tono__LCD_EN)
/* Slew Rate Control */
#define tono_SLW                    (* (reg8 *) tono__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define tono_PRTDSI__CAPS_SEL       (* (reg8 *) tono__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define tono_PRTDSI__DBL_SYNC_IN    (* (reg8 *) tono__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define tono_PRTDSI__OE_SEL0        (* (reg8 *) tono__PRTDSI__OE_SEL0) 
#define tono_PRTDSI__OE_SEL1        (* (reg8 *) tono__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define tono_PRTDSI__OUT_SEL0       (* (reg8 *) tono__PRTDSI__OUT_SEL0) 
#define tono_PRTDSI__OUT_SEL1       (* (reg8 *) tono__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define tono_PRTDSI__SYNC_OUT       (* (reg8 *) tono__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(tono__SIO_CFG)
    #define tono_SIO_HYST_EN        (* (reg8 *) tono__SIO_HYST_EN)
    #define tono_SIO_REG_HIFREQ     (* (reg8 *) tono__SIO_REG_HIFREQ)
    #define tono_SIO_CFG            (* (reg8 *) tono__SIO_CFG)
    #define tono_SIO_DIFF           (* (reg8 *) tono__SIO_DIFF)
#endif /* (tono__SIO_CFG) */

/* Interrupt Registers */
#if defined(tono__INTSTAT)
    #define tono_INTSTAT            (* (reg8 *) tono__INTSTAT)
    #define tono_SNAP               (* (reg8 *) tono__SNAP)
    
	#define tono_0_INTTYPE_REG 		(* (reg8 *) tono__0__INTTYPE)
#endif /* (tono__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_tono_H */


/* [] END OF FILE */
