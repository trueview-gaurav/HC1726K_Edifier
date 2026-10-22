/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_USBCFG_H_
#define CSR_TABLE_USBCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_usbcfg[] = {
	// WORD usbc00
	{ "debug_sel", 0x00000000, 2, 0, CSR_RW, 0x00000000 },
	{ "debug_en", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "USBC00", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc01
	{ "sd", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "slp", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "USBC01", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc02
	{ "ss_scaledown_mode", 0x00000008, 1, 0, CSR_RW, 0x00000000 },
	{ "USBC02", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc03
	{ "dbnce_fltr_bypass", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "test_bypass_lp", 0x0000000C, 8, 8, CSR_RW, 0x00000000 },
	{ "USBC03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc04
	{ "sys_dma_done_trig", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "sys_dma_done_auto", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "sys_dma_done_cnt", 0x00000010, 23, 16, CSR_RW, 0x00000000 },
	{ "USBC04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc05
	{ "int_dma_req", 0x00000014, 0, 0, CSR_RO, 0x00000000 },
	{ "int_dma_done_flag", 0x00000014, 8, 8, CSR_RO, 0x00000000 },
	{ "chep_number", 0x00000014, 19, 16, CSR_RO, 0x00000000 },
	{ "chep_last_trans", 0x00000014, 24, 24, CSR_RO, 0x00000000 },
	{ "USBC05", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD usbc06
	{ "sof_toggle_out", 0x00000018, 0, 0, CSR_RO, 0x00000000 },
	{ "sof_sent_rcvd_tgl", 0x00000018, 8, 8, CSR_RO, 0x00000000 },
	{ "USBC06", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD usbc07
	{ "rg_phy_pllitune", 0x0000001C, 1, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_pllptune", 0x0000001C, 11, 8, CSR_RW, 0x0000000C },
	{ "rg_phy_pllbtune", 0x0000001C, 16, 16, CSR_RW, 0x00000001 },
	{ "rg_phy_compdistune", 0x0000001C, 26, 24, CSR_RW, 0x00000003 },
	{ "USBC07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc08
	{ "rg_phy_sqrxtune", 0x00000020, 2, 0, CSR_RW, 0x00000003 },
	{ "rg_phy_vdatreftune", 0x00000020, 9, 8, CSR_RW, 0x00000001 },
	{ "rg_phy_otgtune", 0x00000020, 18, 16, CSR_RW, 0x00000003 },
	{ "rg_phy_txhsxvtune", 0x00000020, 25, 24, CSR_RW, 0x00000003 },
	{ "USBC08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc09
	{ "rg_phy_txfslstune", 0x00000024, 3, 0, CSR_RW, 0x00000003 },
	{ "rg_phy_txvreftune", 0x00000024, 11, 8, CSR_RW, 0x00000003 },
	{ "rg_phy_txrisetune", 0x00000024, 17, 16, CSR_RW, 0x00000001 },
	{ "rg_phy_txrestune", 0x00000024, 25, 24, CSR_RW, 0x00000001 },
	{ "USBC09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc10
	{ "rg_phy_txpreempamptune", 0x00000028, 1, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_txpreemppulsetune", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "USBC10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc11
	{ "rg_phy_fsel", 0x0000002C, 2, 0, CSR_RW, 0x00000002 },
	{ "rg_phy_refclksel", 0x0000002C, 9, 8, CSR_RW, 0x00000002 },
	{ "rg_phy_refclk_en", 0x0000002C, 16, 16, CSR_RW, 0x00000001 },
	{ "USBC11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc12
	{ "rg_phy_commononn", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_vregbypass", 0x00000030, 16, 16, CSR_RW, 0x00000000 },
	{ "USBC12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc13
	{ "dev_hird_vld_tgl", 0x00000034, 0, 0, CSR_RO, 0x00000000 },
	{ "dev_hird_rcvd", 0x00000034, 19, 16, CSR_RO, 0x00000000 },
	{ "USBC13", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD usbc14
	{ "reserved", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	{ "USBC14", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc15
	{ "rg_phy_atereset", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "USBC15", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc16
	{ "rg_phy_testdatain", 0x00000040, 7, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_testaddr", 0x00000040, 19, 16, CSR_RW, 0x00000000 },
	{ "USBC16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc17
	{ "rg_phy_testdataoutsel", 0x00000044, 0, 0, CSR_RW, 0x00000000 },
	{ "USBC17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc18
	{ "phy_testdataout", 0x00000048, 3, 0, CSR_RO, 0x00000000 },
	{ "phy_resackout", 0x00000048, 16, 16, CSR_RO, 0x00000000 },
	{ "USBC18", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD usbc19
	{ "rg_phy_testclk", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "USBC19", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc20
	{ "rg_phy_siddq", 0x00000050, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_loopbackenb", 0x00000050, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_phy_testburnin", 0x00000050, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_phy_resreqin", 0x00000050, 24, 24, CSR_RW, 0x00000000 },
	{ "USBC20", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc21
	{ "rg_phy_otgdisable", 0x00000054, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_vbusvldextsel", 0x00000054, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_phy_vbusvldext", 0x00000054, 16, 16, CSR_RW, 0x00000000 },
	{ "USBC21", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbc22
	{ "rg_phy_port_rst", 0x00000058, 0, 0, CSR_RW, 0x00000000 },
	{ "USBC22", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD usbphy_utmi_sel
	{ "phy_utmi_sel", 0x0000005C, 0, 0, CSR_RW, 0x00000000 },
	{ "USBPHY_UTMI_SEL", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_utmi_in_0
	{ "rg_phy_utmi_idpullup", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_drvvbus", 0x00000060, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_dppulldown", 0x00000060, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_dmpulldown", 0x00000060, 24, 24, CSR_RW, 0x00000000 },
	{ "PHY_UTMI_IN_0", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_utmi_in_1
	{ "rg_phy_utmi_suspendm", 0x00000064, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_sleepm", 0x00000064, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_opmode", 0x00000064, 17, 16, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_termsel", 0x00000064, 24, 24, CSR_RW, 0x00000000 },
	{ "PHY_UTMI_IN_1", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_utmi_in_2
	{ "rg_phy_utmi_xcvrsel", 0x00000068, 1, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_wordinterface", 0x00000068, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_datain", 0x00000068, 23, 16, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_datainh", 0x00000068, 31, 24, CSR_RW, 0x00000000 },
	{ "PHY_UTMI_IN_2", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_utmi_in_3
	{ "rg_phy_utmi_txvalid", 0x0000006C, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_txvalidh", 0x0000006C, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_phy_utmi_fsxcvrowner", 0x0000006C, 16, 16, CSR_RW, 0x00000000 },
	{ "PHY_UTMI_IN_3", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_utmi_out_0
	{ "phy_utmi_iddig", 0x00000070, 0, 0, CSR_RO, 0x00000000 },
	{ "phy_utmi_vbusvalid", 0x00000070, 8, 8, CSR_RO, 0x00000000 },
	{ "phy_utmi_linestate", 0x00000070, 17, 16, CSR_RO, 0x00000000 },
	{ "phy_utmi_txready", 0x00000070, 24, 24, CSR_RO, 0x00000000 },
	{ "PHY_UTMI_OUT_0", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	// WORD phy_utmi_out_1
	{ "phy_utmi_dataout", 0x00000074, 7, 0, CSR_RO, 0x00000000 },
	{ "phy_utmi_dataouth", 0x00000074, 15, 8, CSR_RO, 0x00000000 },
	{ "phy_utmi_rxactive", 0x00000074, 16, 16, CSR_RO, 0x00000000 },
	{ "phy_utmi_rxvalid", 0x00000074, 24, 24, CSR_RO, 0x00000000 },
	{ "PHY_UTMI_OUT_1", 0x00000074, 31, 0, CSR_RO, 0x00000000 },
	// WORD phy_utmi_out_2
	{ "phy_utmi_rxvalidh", 0x00000078, 0, 0, CSR_RO, 0x00000000 },
	{ "phy_utmi_rxerror", 0x00000078, 8, 8, CSR_RO, 0x00000000 },
	{ "phy_utmi_hostdisconnect", 0x00000078, 16, 16, CSR_RO, 0x00000000 },
	{ "PHY_UTMI_OUT_2", 0x00000078, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_USBCFG_H_
