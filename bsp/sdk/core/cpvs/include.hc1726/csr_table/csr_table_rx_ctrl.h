/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_RX_CTRL_H_
#define CSR_TABLE_RX_CTRL_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_rx_ctrl[] = {
	// WORD ctrl_0
	{ "pwr_ctrl_sel", 0x00000000, 3, 0, CSR_RW, 0x0000000F },
	{ "ctrl_sel", 0x00000000, 16, 16, CSR_RW, 0x00000000 },
	{ "CTRL_0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl_1
	{ "ln0_pwron_start", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "ln1_pwron_start", 0x00000004, 1, 1, CSR_W1P, 0x00000000 },
	{ "ln2_pwron_start", 0x00000004, 2, 2, CSR_W1P, 0x00000000 },
	{ "ln3_pwron_start", 0x00000004, 3, 3, CSR_W1P, 0x00000000 },
	{ "all_pwron_start", 0x00000004, 6, 6, CSR_W1P, 0x00000000 },
	{ "ln0_gpi_pwron_start", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "ln1_gpi_pwron_start", 0x00000004, 9, 9, CSR_W1P, 0x00000000 },
	{ "ln2_gpi_pwron_start", 0x00000004, 10, 10, CSR_W1P, 0x00000000 },
	{ "ln3_gpi_pwron_start", 0x00000004, 11, 11, CSR_W1P, 0x00000000 },
	{ "CTRL_1", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ctrl_ln0
	{ "rx_ln0_ib10u_en", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "rx_ln0_bias_en", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "rx_ln0_bias_out_en", 0x00000008, 16, 16, CSR_RW, 0x00000000 },
	{ "rx_ln0_lprx_en", 0x00000008, 24, 24, CSR_RW, 0x00000000 },
	{ "CTRL_LN0", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl_ln1
	{ "rx_ln1_ib10u_en", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "rx_ln1_bias_en", 0x0000000C, 8, 8, CSR_RW, 0x00000000 },
	{ "rx_ln1_bias_out_en", 0x0000000C, 16, 16, CSR_RW, 0x00000000 },
	{ "rx_ln1_lprx_en", 0x0000000C, 24, 24, CSR_RW, 0x00000000 },
	{ "CTRL_LN1", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl_ln2
	{ "rx_ln2_ib10u_en", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "rx_ln2_bias_en", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "rx_ln2_bias_out_en", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "rx_ln2_lprx_en", 0x00000010, 24, 24, CSR_RW, 0x00000000 },
	{ "CTRL_LN2", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl_ln3
	{ "rx_ln3_ib10u_en", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "rx_ln3_bias_en", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "rx_ln3_bias_out_en", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "rx_ln3_lprx_en", 0x00000014, 24, 24, CSR_RW, 0x00000000 },
	{ "CTRL_LN3", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD cal_en
	{ "cal_start", 0x00000018, 0, 0, CSR_W1P, 0x00000000 },
	{ "CAL_EN", 0x00000018, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cal_ctrl
	{ "cal_enable", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "cal_style_sel", 0x0000001C, 4, 4, CSR_RW, 0x00000000 },
	{ "cal_time_sel", 0x0000001C, 7, 6, CSR_RW, 0x00000000 },
	{ "cal_lane_en", 0x0000001C, 19, 16, CSR_RW, 0x00000000 },
	{ "CAL_CTRL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cal_ln0_st
	{ "cal_ln0_done", 0x00000020, 0, 0, CSR_RO, 0x00000000 },
	{ "cal_ln0_fail", 0x00000020, 1, 1, CSR_RO, 0x00000000 },
	{ "cal_ln0_sta", 0x00000020, 11, 8, CSR_RO, 0x00000000 },
	{ "cal_ln0_cnt", 0x00000020, 19, 16, CSR_RO, 0x00000000 },
	{ "CAL_LN0_ST", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD cal_ln1_st
	{ "cal_ln1_done", 0x00000024, 0, 0, CSR_RO, 0x00000000 },
	{ "cal_ln1_fail", 0x00000024, 1, 1, CSR_RO, 0x00000000 },
	{ "cal_ln1_sta", 0x00000024, 11, 8, CSR_RO, 0x00000000 },
	{ "cal_ln1_cnt", 0x00000024, 19, 16, CSR_RO, 0x00000000 },
	{ "CAL_LN1_ST", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD cal_ln2_st
	{ "cal_ln2_done", 0x00000028, 0, 0, CSR_RO, 0x00000000 },
	{ "cal_ln2_fail", 0x00000028, 1, 1, CSR_RO, 0x00000000 },
	{ "cal_ln2_sta", 0x00000028, 11, 8, CSR_RO, 0x00000000 },
	{ "cal_ln2_cnt", 0x00000028, 19, 16, CSR_RO, 0x00000000 },
	{ "CAL_LN2_ST", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD cal_ln3_st
	{ "cal_ln3_done", 0x0000002C, 0, 0, CSR_RO, 0x00000000 },
	{ "cal_ln3_fail", 0x0000002C, 1, 1, CSR_RO, 0x00000000 },
	{ "cal_ln3_sta", 0x0000002C, 11, 8, CSR_RO, 0x00000000 },
	{ "cal_ln3_cnt", 0x0000002C, 19, 16, CSR_RO, 0x00000000 },
	{ "CAL_LN3_ST", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD pwr_st_mon
	{ "pwr_st", 0x00000030, 19, 0, CSR_RO, 0x00000000 },
	{ "PWR_ST_MON", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_RX_CTRL_H_
