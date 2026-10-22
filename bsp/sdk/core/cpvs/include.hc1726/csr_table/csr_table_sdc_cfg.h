/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SDC_CFG_H_
#define CSR_TABLE_SDC_CFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_sdc_cfg[] = {
	// WORD sdc_core_cg
	{ "cken_sdc", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "SDC_CORE_CG", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD sdc_clk_phase_shift_ctrl
	{ "sdc_spl_phase_sel", 0x00000004, 1, 0, CSR_RW, 0x00000000 },
	{ "sdc_drv_phase_sel", 0x00000004, 9, 8, CSR_RW, 0x00000000 },
	{ "SDC_CLK_PHASE_SHIFT_CTRL", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD sdc_intf_signal_ctrl_0
	{ "sd2_wp_from_csr", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "sd_wp_from_csr", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "sd2_cd_from_csr", 0x00000008, 16, 16, CSR_RW, 0x00000000 },
	{ "sd_cd_from_csr", 0x00000008, 24, 24, CSR_RW, 0x00000000 },
	{ "SDC_INTF_SIGNAL_CTRL_0", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD sdc_intf_signal_ctrl_1
	{ "en_sd2_wp_from_csr", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "en_sd_wp_from_csr", 0x0000000C, 8, 8, CSR_RW, 0x00000000 },
	{ "en_sd2_cd_from_csr", 0x0000000C, 16, 16, CSR_RW, 0x00000000 },
	{ "en_sd_cd_from_csr", 0x0000000C, 24, 24, CSR_RW, 0x00000000 },
	{ "SDC_INTF_SIGNAL_CTRL_1", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sdc_cmd_data_force_ctrl
	{ "sdc_cmd_data_tie0_en", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "SDC_CMD_DATA_FORCE_CTRL", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mem_wrapper
	{ "sd", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "slp", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "MEM_WRAPPER", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SDC_CFG_H_
