/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* I2C */
.set I2C_I2C_FF__ADR, CYREG_I2C_ADR
.set I2C_I2C_FF__CFG, CYREG_I2C_CFG
.set I2C_I2C_FF__CLK_DIV1, CYREG_I2C_CLK_DIV1
.set I2C_I2C_FF__CLK_DIV2, CYREG_I2C_CLK_DIV2
.set I2C_I2C_FF__CSR, CYREG_I2C_CSR
.set I2C_I2C_FF__D, CYREG_I2C_D
.set I2C_I2C_FF__MCSR, CYREG_I2C_MCSR
.set I2C_I2C_FF__PM_ACT_CFG, CYREG_PM_ACT_CFG5
.set I2C_I2C_FF__PM_ACT_MSK, 0x04
.set I2C_I2C_FF__PM_STBY_CFG, CYREG_PM_STBY_CFG5
.set I2C_I2C_FF__PM_STBY_MSK, 0x04
.set I2C_I2C_FF__TMOUT_CFG0, CYREG_I2C_TMOUT_CFG0
.set I2C_I2C_FF__TMOUT_CFG1, CYREG_I2C_TMOUT_CFG1
.set I2C_I2C_FF__TMOUT_CSR, CYREG_I2C_TMOUT_CSR
.set I2C_I2C_FF__TMOUT_SR, CYREG_I2C_TMOUT_SR
.set I2C_I2C_FF__XCFG, CYREG_I2C_XCFG
.set I2C_I2C_IRQ__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set I2C_I2C_IRQ__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set I2C_I2C_IRQ__INTC_MASK, 0x8000
.set I2C_I2C_IRQ__INTC_NUMBER, 15
.set I2C_I2C_IRQ__INTC_PRIOR_NUM, 7
.set I2C_I2C_IRQ__INTC_PRIOR_REG, CYREG_NVIC_PRI_15
.set I2C_I2C_IRQ__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set I2C_I2C_IRQ__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* LCD */
.set LCD_LCDPort__0__INTTYPE, CYREG_PICU12_INTTYPE0
.set LCD_LCDPort__0__MASK, 0x01
.set LCD_LCDPort__0__PC, CYREG_PRT12_PC0
.set LCD_LCDPort__0__PORT, 12
.set LCD_LCDPort__0__SHIFT, 0
.set LCD_LCDPort__1__INTTYPE, CYREG_PICU12_INTTYPE1
.set LCD_LCDPort__1__MASK, 0x02
.set LCD_LCDPort__1__PC, CYREG_PRT12_PC1
.set LCD_LCDPort__1__PORT, 12
.set LCD_LCDPort__1__SHIFT, 1
.set LCD_LCDPort__2__INTTYPE, CYREG_PICU12_INTTYPE2
.set LCD_LCDPort__2__MASK, 0x04
.set LCD_LCDPort__2__PC, CYREG_PRT12_PC2
.set LCD_LCDPort__2__PORT, 12
.set LCD_LCDPort__2__SHIFT, 2
.set LCD_LCDPort__3__INTTYPE, CYREG_PICU12_INTTYPE3
.set LCD_LCDPort__3__MASK, 0x08
.set LCD_LCDPort__3__PC, CYREG_PRT12_PC3
.set LCD_LCDPort__3__PORT, 12
.set LCD_LCDPort__3__SHIFT, 3
.set LCD_LCDPort__4__INTTYPE, CYREG_PICU12_INTTYPE4
.set LCD_LCDPort__4__MASK, 0x10
.set LCD_LCDPort__4__PC, CYREG_PRT12_PC4
.set LCD_LCDPort__4__PORT, 12
.set LCD_LCDPort__4__SHIFT, 4
.set LCD_LCDPort__5__INTTYPE, CYREG_PICU12_INTTYPE5
.set LCD_LCDPort__5__MASK, 0x20
.set LCD_LCDPort__5__PC, CYREG_PRT12_PC5
.set LCD_LCDPort__5__PORT, 12
.set LCD_LCDPort__5__SHIFT, 5
.set LCD_LCDPort__6__INTTYPE, CYREG_PICU12_INTTYPE6
.set LCD_LCDPort__6__MASK, 0x40
.set LCD_LCDPort__6__PC, CYREG_PRT12_PC6
.set LCD_LCDPort__6__PORT, 12
.set LCD_LCDPort__6__SHIFT, 6
.set LCD_LCDPort__AG, CYREG_PRT12_AG
.set LCD_LCDPort__BIE, CYREG_PRT12_BIE
.set LCD_LCDPort__BIT_MASK, CYREG_PRT12_BIT_MASK
.set LCD_LCDPort__BYP, CYREG_PRT12_BYP
.set LCD_LCDPort__DM0, CYREG_PRT12_DM0
.set LCD_LCDPort__DM1, CYREG_PRT12_DM1
.set LCD_LCDPort__DM2, CYREG_PRT12_DM2
.set LCD_LCDPort__DR, CYREG_PRT12_DR
.set LCD_LCDPort__INP_DIS, CYREG_PRT12_INP_DIS
.set LCD_LCDPort__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set LCD_LCDPort__MASK, 0x7F
.set LCD_LCDPort__PORT, 12
.set LCD_LCDPort__PRT, CYREG_PRT12_PRT
.set LCD_LCDPort__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set LCD_LCDPort__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set LCD_LCDPort__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set LCD_LCDPort__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set LCD_LCDPort__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set LCD_LCDPort__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set LCD_LCDPort__PS, CYREG_PRT12_PS
.set LCD_LCDPort__SHIFT, 0
.set LCD_LCDPort__SIO_CFG, CYREG_PRT12_SIO_CFG
.set LCD_LCDPort__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set LCD_LCDPort__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set LCD_LCDPort__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set LCD_LCDPort__SLW, CYREG_PRT12_SLW

/* SCL */
.set SCL__0__INTTYPE, CYREG_PICU2_INTTYPE5
.set SCL__0__MASK, 0x20
.set SCL__0__PC, CYREG_PRT2_PC5
.set SCL__0__PORT, 2
.set SCL__0__SHIFT, 5
.set SCL__AG, CYREG_PRT2_AG
.set SCL__AMUX, CYREG_PRT2_AMUX
.set SCL__BIE, CYREG_PRT2_BIE
.set SCL__BIT_MASK, CYREG_PRT2_BIT_MASK
.set SCL__BYP, CYREG_PRT2_BYP
.set SCL__CTL, CYREG_PRT2_CTL
.set SCL__DM0, CYREG_PRT2_DM0
.set SCL__DM1, CYREG_PRT2_DM1
.set SCL__DM2, CYREG_PRT2_DM2
.set SCL__DR, CYREG_PRT2_DR
.set SCL__INP_DIS, CYREG_PRT2_INP_DIS
.set SCL__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set SCL__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set SCL__LCD_EN, CYREG_PRT2_LCD_EN
.set SCL__MASK, 0x20
.set SCL__PORT, 2
.set SCL__PRT, CYREG_PRT2_PRT
.set SCL__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set SCL__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set SCL__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set SCL__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set SCL__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set SCL__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set SCL__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set SCL__PS, CYREG_PRT2_PS
.set SCL__SHIFT, 5
.set SCL__SLW, CYREG_PRT2_SLW

/* SDA */
.set SDA__0__INTTYPE, CYREG_PICU2_INTTYPE6
.set SDA__0__MASK, 0x40
.set SDA__0__PC, CYREG_PRT2_PC6
.set SDA__0__PORT, 2
.set SDA__0__SHIFT, 6
.set SDA__AG, CYREG_PRT2_AG
.set SDA__AMUX, CYREG_PRT2_AMUX
.set SDA__BIE, CYREG_PRT2_BIE
.set SDA__BIT_MASK, CYREG_PRT2_BIT_MASK
.set SDA__BYP, CYREG_PRT2_BYP
.set SDA__CTL, CYREG_PRT2_CTL
.set SDA__DM0, CYREG_PRT2_DM0
.set SDA__DM1, CYREG_PRT2_DM1
.set SDA__DM2, CYREG_PRT2_DM2
.set SDA__DR, CYREG_PRT2_DR
.set SDA__INP_DIS, CYREG_PRT2_INP_DIS
.set SDA__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set SDA__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set SDA__LCD_EN, CYREG_PRT2_LCD_EN
.set SDA__MASK, 0x40
.set SDA__PORT, 2
.set SDA__PRT, CYREG_PRT2_PRT
.set SDA__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set SDA__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set SDA__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set SDA__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set SDA__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set SDA__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set SDA__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set SDA__PS, CYREG_PRT2_PS
.set SDA__SHIFT, 6
.set SDA__SLW, CYREG_PRT2_SLW

/* Rx_1 */
.set Rx_1__0__INTTYPE, CYREG_PICU3_INTTYPE0
.set Rx_1__0__MASK, 0x01
.set Rx_1__0__PC, CYREG_PRT3_PC0
.set Rx_1__0__PORT, 3
.set Rx_1__0__SHIFT, 0
.set Rx_1__AG, CYREG_PRT3_AG
.set Rx_1__AMUX, CYREG_PRT3_AMUX
.set Rx_1__BIE, CYREG_PRT3_BIE
.set Rx_1__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Rx_1__BYP, CYREG_PRT3_BYP
.set Rx_1__CTL, CYREG_PRT3_CTL
.set Rx_1__DM0, CYREG_PRT3_DM0
.set Rx_1__DM1, CYREG_PRT3_DM1
.set Rx_1__DM2, CYREG_PRT3_DM2
.set Rx_1__DR, CYREG_PRT3_DR
.set Rx_1__INP_DIS, CYREG_PRT3_INP_DIS
.set Rx_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set Rx_1__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Rx_1__LCD_EN, CYREG_PRT3_LCD_EN
.set Rx_1__MASK, 0x01
.set Rx_1__PORT, 3
.set Rx_1__PRT, CYREG_PRT3_PRT
.set Rx_1__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Rx_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Rx_1__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Rx_1__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Rx_1__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Rx_1__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Rx_1__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Rx_1__PS, CYREG_PRT3_PS
.set Rx_1__SHIFT, 0
.set Rx_1__SLW, CYREG_PRT3_SLW

/* Tx_1 */
.set Tx_1__0__INTTYPE, CYREG_PICU3_INTTYPE1
.set Tx_1__0__MASK, 0x02
.set Tx_1__0__PC, CYREG_PRT3_PC1
.set Tx_1__0__PORT, 3
.set Tx_1__0__SHIFT, 1
.set Tx_1__AG, CYREG_PRT3_AG
.set Tx_1__AMUX, CYREG_PRT3_AMUX
.set Tx_1__BIE, CYREG_PRT3_BIE
.set Tx_1__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Tx_1__BYP, CYREG_PRT3_BYP
.set Tx_1__CTL, CYREG_PRT3_CTL
.set Tx_1__DM0, CYREG_PRT3_DM0
.set Tx_1__DM1, CYREG_PRT3_DM1
.set Tx_1__DM2, CYREG_PRT3_DM2
.set Tx_1__DR, CYREG_PRT3_DR
.set Tx_1__INP_DIS, CYREG_PRT3_INP_DIS
.set Tx_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set Tx_1__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Tx_1__LCD_EN, CYREG_PRT3_LCD_EN
.set Tx_1__MASK, 0x02
.set Tx_1__PORT, 3
.set Tx_1__PRT, CYREG_PRT3_PRT
.set Tx_1__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Tx_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Tx_1__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Tx_1__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Tx_1__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Tx_1__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Tx_1__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Tx_1__PS, CYREG_PRT3_PS
.set Tx_1__SHIFT, 1
.set Tx_1__SLW, CYREG_PRT3_SLW

/* UART */
.set UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG, CYREG_B1_UDB07_08_ACTL
.set UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG, CYREG_B1_UDB07_08_CTL
.set UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG, CYREG_B1_UDB07_08_CTL
.set UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG, CYREG_B1_UDB07_08_CTL
.set UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG, CYREG_B1_UDB07_08_CTL
.set UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG, CYREG_B1_UDB07_08_MSK
.set UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG, CYREG_B1_UDB07_08_MSK
.set UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG, CYREG_B1_UDB07_08_MSK
.set UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG, CYREG_B1_UDB07_08_MSK
.set UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG, CYREG_B1_UDB07_ACTL
.set UART_BUART_sRX_RxBitCounter__CONTROL_REG, CYREG_B1_UDB07_CTL
.set UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG, CYREG_B1_UDB07_ST_CTL
.set UART_BUART_sRX_RxBitCounter__COUNT_REG, CYREG_B1_UDB07_CTL
.set UART_BUART_sRX_RxBitCounter__COUNT_ST_REG, CYREG_B1_UDB07_ST_CTL
.set UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set UART_BUART_sRX_RxBitCounter__PERIOD_REG, CYREG_B1_UDB07_MSK
.set UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB07_08_ACTL
.set UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG, CYREG_B1_UDB07_08_ST
.set UART_BUART_sRX_RxBitCounter_ST__MASK_REG, CYREG_B1_UDB07_MSK
.set UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG, CYREG_B1_UDB07_ACTL
.set UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG, CYREG_B1_UDB07_ST_CTL
.set UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG, CYREG_B1_UDB07_ST_CTL
.set UART_BUART_sRX_RxBitCounter_ST__STATUS_REG, CYREG_B1_UDB07_ST
.set UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG, CYREG_B1_UDB04_05_A0
.set UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG, CYREG_B1_UDB04_05_A1
.set UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG, CYREG_B1_UDB04_05_D0
.set UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG, CYREG_B1_UDB04_05_D1
.set UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB04_05_ACTL
.set UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG, CYREG_B1_UDB04_05_F0
.set UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG, CYREG_B1_UDB04_05_F1
.set UART_BUART_sRX_RxShifter_u0__A0_A1_REG, CYREG_B1_UDB04_A0_A1
.set UART_BUART_sRX_RxShifter_u0__A0_REG, CYREG_B1_UDB04_A0
.set UART_BUART_sRX_RxShifter_u0__A1_REG, CYREG_B1_UDB04_A1
.set UART_BUART_sRX_RxShifter_u0__D0_D1_REG, CYREG_B1_UDB04_D0_D1
.set UART_BUART_sRX_RxShifter_u0__D0_REG, CYREG_B1_UDB04_D0
.set UART_BUART_sRX_RxShifter_u0__D1_REG, CYREG_B1_UDB04_D1
.set UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG, CYREG_B1_UDB04_ACTL
.set UART_BUART_sRX_RxShifter_u0__F0_F1_REG, CYREG_B1_UDB04_F0_F1
.set UART_BUART_sRX_RxShifter_u0__F0_REG, CYREG_B1_UDB04_F0
.set UART_BUART_sRX_RxShifter_u0__F1_REG, CYREG_B1_UDB04_F1
.set UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB05_06_ACTL
.set UART_BUART_sRX_RxSts__16BIT_STATUS_REG, CYREG_B1_UDB05_06_ST
.set UART_BUART_sRX_RxSts__3__MASK, 0x08
.set UART_BUART_sRX_RxSts__3__POS, 3
.set UART_BUART_sRX_RxSts__4__MASK, 0x10
.set UART_BUART_sRX_RxSts__4__POS, 4
.set UART_BUART_sRX_RxSts__5__MASK, 0x20
.set UART_BUART_sRX_RxSts__5__POS, 5
.set UART_BUART_sRX_RxSts__MASK, 0x38
.set UART_BUART_sRX_RxSts__MASK_REG, CYREG_B1_UDB05_MSK
.set UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG, CYREG_B1_UDB05_ACTL
.set UART_BUART_sRX_RxSts__STATUS_REG, CYREG_B1_UDB05_ST
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG, CYREG_B1_UDB06_07_A0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG, CYREG_B1_UDB06_07_A1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG, CYREG_B1_UDB06_07_D0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG, CYREG_B1_UDB06_07_D1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB06_07_ACTL
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG, CYREG_B1_UDB06_07_F0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG, CYREG_B1_UDB06_07_F1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG, CYREG_B1_UDB06_A0_A1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG, CYREG_B1_UDB06_A0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG, CYREG_B1_UDB06_A1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG, CYREG_B1_UDB06_D0_D1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG, CYREG_B1_UDB06_D0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG, CYREG_B1_UDB06_D1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG, CYREG_B1_UDB06_ACTL
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG, CYREG_B1_UDB06_F0_F1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG, CYREG_B1_UDB06_F0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG, CYREG_B1_UDB06_F1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__MSK_DP_AUX_CTL_REG, CYREG_B1_UDB06_MSK_ACTL
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__PER_DP_AUX_CTL_REG, CYREG_B1_UDB06_MSK_ACTL
.set UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG, CYREG_B1_UDB07_08_A0
.set UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG, CYREG_B1_UDB07_08_A1
.set UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG, CYREG_B1_UDB07_08_D0
.set UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG, CYREG_B1_UDB07_08_D1
.set UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB07_08_ACTL
.set UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG, CYREG_B1_UDB07_08_F0
.set UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG, CYREG_B1_UDB07_08_F1
.set UART_BUART_sTX_TxShifter_u0__A0_A1_REG, CYREG_B1_UDB07_A0_A1
.set UART_BUART_sTX_TxShifter_u0__A0_REG, CYREG_B1_UDB07_A0
.set UART_BUART_sTX_TxShifter_u0__A1_REG, CYREG_B1_UDB07_A1
.set UART_BUART_sTX_TxShifter_u0__D0_D1_REG, CYREG_B1_UDB07_D0_D1
.set UART_BUART_sTX_TxShifter_u0__D0_REG, CYREG_B1_UDB07_D0
.set UART_BUART_sTX_TxShifter_u0__D1_REG, CYREG_B1_UDB07_D1
.set UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG, CYREG_B1_UDB07_ACTL
.set UART_BUART_sTX_TxShifter_u0__F0_F1_REG, CYREG_B1_UDB07_F0_F1
.set UART_BUART_sTX_TxShifter_u0__F0_REG, CYREG_B1_UDB07_F0
.set UART_BUART_sTX_TxShifter_u0__F1_REG, CYREG_B1_UDB07_F1
.set UART_BUART_sTX_TxShifter_u0__MSK_DP_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set UART_BUART_sTX_TxShifter_u0__PER_DP_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set UART_BUART_sTX_TxSts__0__MASK, 0x01
.set UART_BUART_sTX_TxSts__0__POS, 0
.set UART_BUART_sTX_TxSts__1__MASK, 0x02
.set UART_BUART_sTX_TxSts__1__POS, 1
.set UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB04_05_ACTL
.set UART_BUART_sTX_TxSts__16BIT_STATUS_REG, CYREG_B1_UDB04_05_ST
.set UART_BUART_sTX_TxSts__2__MASK, 0x04
.set UART_BUART_sTX_TxSts__2__POS, 2
.set UART_BUART_sTX_TxSts__3__MASK, 0x08
.set UART_BUART_sTX_TxSts__3__POS, 3
.set UART_BUART_sTX_TxSts__MASK, 0x0F
.set UART_BUART_sTX_TxSts__MASK_REG, CYREG_B1_UDB04_MSK
.set UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG, CYREG_B1_UDB04_ACTL
.set UART_BUART_sTX_TxSts__STATUS_REG, CYREG_B1_UDB04_ST
.set UART_IntClock__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set UART_IntClock__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set UART_IntClock__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set UART_IntClock__CFG2_SRC_SEL_MASK, 0x07
.set UART_IntClock__INDEX, 0x00
.set UART_IntClock__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set UART_IntClock__PM_ACT_MSK, 0x01
.set UART_IntClock__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set UART_IntClock__PM_STBY_MSK, 0x01

/* tono */
.set tono__0__INTTYPE, CYREG_PICU2_INTTYPE0
.set tono__0__MASK, 0x01
.set tono__0__PC, CYREG_PRT2_PC0
.set tono__0__PORT, 2
.set tono__0__SHIFT, 0
.set tono__AG, CYREG_PRT2_AG
.set tono__AMUX, CYREG_PRT2_AMUX
.set tono__BIE, CYREG_PRT2_BIE
.set tono__BIT_MASK, CYREG_PRT2_BIT_MASK
.set tono__BYP, CYREG_PRT2_BYP
.set tono__CTL, CYREG_PRT2_CTL
.set tono__DM0, CYREG_PRT2_DM0
.set tono__DM1, CYREG_PRT2_DM1
.set tono__DM2, CYREG_PRT2_DM2
.set tono__DR, CYREG_PRT2_DR
.set tono__INP_DIS, CYREG_PRT2_INP_DIS
.set tono__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set tono__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set tono__LCD_EN, CYREG_PRT2_LCD_EN
.set tono__MASK, 0x01
.set tono__PORT, 2
.set tono__PRT, CYREG_PRT2_PRT
.set tono__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set tono__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set tono__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set tono__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set tono__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set tono__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set tono__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set tono__PS, CYREG_PRT2_PS
.set tono__SHIFT, 0
.set tono__SLW, CYREG_PRT2_SLW

/* IRQRX */
.set IRQRX__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set IRQRX__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set IRQRX__INTC_MASK, 0x01
.set IRQRX__INTC_NUMBER, 0
.set IRQRX__INTC_PRIOR_NUM, 7
.set IRQRX__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set IRQRX__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set IRQRX__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* Control */
.set Control_Sync_ctrl_reg__0__MASK, 0x01
.set Control_Sync_ctrl_reg__0__POS, 0
.set Control_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B1_UDB06_07_ACTL
.set Control_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG, CYREG_B1_UDB06_07_CTL
.set Control_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG, CYREG_B1_UDB06_07_CTL
.set Control_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG, CYREG_B1_UDB06_07_CTL
.set Control_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG, CYREG_B1_UDB06_07_CTL
.set Control_Sync_ctrl_reg__16BIT_MASK_MASK_REG, CYREG_B1_UDB06_07_MSK
.set Control_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG, CYREG_B1_UDB06_07_MSK
.set Control_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG, CYREG_B1_UDB06_07_MSK
.set Control_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG, CYREG_B1_UDB06_07_MSK
.set Control_Sync_ctrl_reg__CONTROL_AUX_CTL_REG, CYREG_B1_UDB06_ACTL
.set Control_Sync_ctrl_reg__CONTROL_REG, CYREG_B1_UDB06_CTL
.set Control_Sync_ctrl_reg__CONTROL_ST_REG, CYREG_B1_UDB06_ST_CTL
.set Control_Sync_ctrl_reg__COUNT_REG, CYREG_B1_UDB06_CTL
.set Control_Sync_ctrl_reg__COUNT_ST_REG, CYREG_B1_UDB06_ST_CTL
.set Control_Sync_ctrl_reg__MASK, 0x01
.set Control_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG, CYREG_B1_UDB06_MSK_ACTL
.set Control_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG, CYREG_B1_UDB06_MSK_ACTL
.set Control_Sync_ctrl_reg__PERIOD_REG, CYREG_B1_UDB06_MSK

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 18
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E161069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 18
.set CYDEV_CHIP_MEMBER_4D, 13
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 19
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 17
.set CYDEV_CHIP_MEMBER_4I, 23
.set CYDEV_CHIP_MEMBER_4J, 14
.set CYDEV_CHIP_MEMBER_4K, 15
.set CYDEV_CHIP_MEMBER_4L, 22
.set CYDEV_CHIP_MEMBER_4M, 21
.set CYDEV_CHIP_MEMBER_4N, 10
.set CYDEV_CHIP_MEMBER_4O, 7
.set CYDEV_CHIP_MEMBER_4P, 20
.set CYDEV_CHIP_MEMBER_4Q, 12
.set CYDEV_CHIP_MEMBER_4R, 8
.set CYDEV_CHIP_MEMBER_4S, 11
.set CYDEV_CHIP_MEMBER_4T, 9
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 16
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 24
.set CYDEV_CHIP_MEMBER_FM3, 28
.set CYDEV_CHIP_MEMBER_FM4, 29
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 25
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 26
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 27
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00008001
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
