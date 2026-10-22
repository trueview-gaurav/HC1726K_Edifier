/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AADC_H_
#define CSR_TABLE_AADC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_aadc[] = {
	// WORD aadc_ctrl_mode
	{ "power_on_ctrl_mode", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "AADC_CTRL_MODE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_ctrl_power_on_off
	{ "start", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "stop", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "AADC_CTRL_POWER_ON_OFF", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD aadc_ctrl_enable
	{ "ph_enable", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "bgchop_enable", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "chpa_enable", 0x00000008, 16, 16, CSR_RW, 0x00000000 },
	{ "ref_chpa_enable", 0x00000008, 24, 24, CSR_RW, 0x00000000 },
	{ "AADC_CTRL_ENABLE", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_ctrl_cycle
	{ "ph_cycle", 0x0000000C, 7, 0, CSR_RW, 0x00000005 },
	{ "ph_prolong_cycle", 0x0000000C, 15, 8, CSR_RW, 0x00000001 },
	{ "chpa_cycle", 0x0000000C, 23, 16, CSR_RW, 0x0000000E },
	{ "refchpa_cycle", 0x0000000C, 31, 24, CSR_RW, 0x0000000E },
	{ "AADC_CTRL_CYCLE", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_ctrl0
	{ "enbgp", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "enbias", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "enref", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "ensdm", 0x00000010, 24, 24, CSR_RW, 0x00000000 },
	{ "AADC_CTRL0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_ctrl1
	{ "resetb", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "AADC_CTRL1", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_ctrl_irq_mask
	{ "irq_mask_aadc_real_stop", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_no_ack", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "AADC_CTRL_IRQ_MASK", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_ctrl_irq_clear
	{ "irq_clear_aadc_real_stop", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_no_ack", 0x0000001C, 8, 8, CSR_W1P, 0x00000000 },
	{ "AADC_CTRL_IRQ_CLEAR", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD aadc_ctrl_status
	{ "status_aadc_real_stop", 0x00000020, 0, 0, CSR_RO, 0x00000000 },
	{ "status_no_ack", 0x00000020, 8, 8, CSR_RO, 0x00000000 },
	{ "AADC_CTRL_STATUS", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD aadc_ctrl_period0
	{ "period_10us", 0x00000024, 15, 0, CSR_RW, 0x00000B06 },
	{ "period_20us", 0x00000024, 31, 16, CSR_RW, 0x0000160C },
	{ "AADC_CTRL_PERIOD0", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_ctrl_period1
	{ "period_30us", 0x00000028, 15, 0, CSR_RW, 0x00002113 },
	{ "period_40us", 0x00000028, 31, 16, CSR_RW, 0x00002C1A },
	{ "AADC_CTRL_PERIOD1", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_ctrl_period2
	{ "period_50us", 0x0000002C, 15, 0, CSR_RW, 0x00003720 },
	{ "AADC_CTRL_PERIOD2", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_phy_reg00
	{ "rg_aadc_bsel1", 0x00000030, 1, 0, CSR_RW, 0x00000001 },
	{ "rg_aadc_bsel2", 0x00000030, 9, 8, CSR_RW, 0x00000001 },
	{ "rg_aadc_vrefpsel", 0x00000030, 18, 16, CSR_RW, 0x00000003 },
	{ "rg_aadc_vcmsel", 0x00000030, 26, 24, CSR_RW, 0x00000003 },
	{ "AADC_PHY_REG00", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_phy_reg01
	{ "rg_aadc_enbgchop", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_aadc_iminus", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_aadc_iplus", 0x00000034, 16, 16, CSR_RW, 0x00000000 },
	{ "AADC_PHY_REG01", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_reserved00
	{ "reserved", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	{ "AADC_RESERVED00", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD preamp_reg0
	{ "rg_apreamp_cal_en", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_apreamp_cal_sel", 0x0000003C, 15, 8, CSR_RW, 0x00000000 },
	{ "rg_apreamp_sw1_en", 0x0000003C, 16, 16, CSR_RW, 0x00000000 },
	{ "PREAMP_REG0", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD preamp_reg1
	{ "rg_apreamp_en", 0x00000040, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_apreamp_bias_en", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_apreamp_gain_sel", 0x00000040, 18, 16, CSR_RW, 0x00000007 },
	{ "apreamp_gain_sel", 0x00000040, 24, 24, CSR_RW, 0x00000000 },
	{ "PREAMP_REG1", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AADC_H_
