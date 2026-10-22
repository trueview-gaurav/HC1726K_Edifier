/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_FCS_H_
#define CSR_TABLE_FCS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_fcs[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mode
	{ "fcs_mode", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "cac_mode", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000014, 15, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000014, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD trans
	{ "trans_diff_level_max", 0x00000018, 5, 0, CSR_RW, 0x00000008 },
	{ "trans_gain", 0x00000018, 12, 8, CSR_RW, 0x00000004 },
	{ "TRANS", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD grid_cnt
	{ "grid_cnt_th_high", 0x0000001C, 2, 0, CSR_RW, 0x00000005 },
	{ "grid_cnt_th_low", 0x0000001C, 10, 8, CSR_RW, 0x00000001 },
	{ "GRID_CNT", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD grid_cnt_th
	{ "grid_cnt_raw_th", 0x00000020, 2, 0, CSR_RW, 0x00000004 },
	{ "GRID_CNT_TH", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD grid_trans
	{ "grid_trans_level_th", 0x00000024, 8, 0, CSR_RW, 0x00000018 },
	{ "grid_trans_round_bit_high", 0x00000024, 17, 16, CSR_RW, 0x00000002 },
	{ "grid_trans_round_bit_low", 0x00000024, 25, 24, CSR_RW, 0x00000001 },
	{ "GRID_TRANS", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD color
	{ "color_diff_self_th", 0x00000028, 5, 0, CSR_RW, 0x00000006 },
	{ "color_diff_neighbor_th", 0x00000028, 13, 8, CSR_RW, 0x00000000 },
	{ "color_coring_th", 0x00000028, 21, 16, CSR_RW, 0x00000002 },
	{ "COLOR", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD correction
	{ "correction_gain", 0x0000002C, 4, 0, CSR_RW, 0x00000008 },
	{ "CORRECTION", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD target_ratio
	{ "target_bg_ratio", 0x00000030, 8, 0, CSR_RW, 0x00000080 },
	{ "target_rg_ratio", 0x00000030, 24, 16, CSR_RW, 0x00000080 },
	{ "TARGET_RATIO", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD atpg_test
	{ "atpg_test_enable_0", 0x00000034, 1, 0, CSR_RW, 0x00000000 },
	{ "atpg_test_enable_1", 0x00000034, 9, 8, CSR_RW, 0x00000000 },
	{ "ATPG_TEST", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_mon
	{ "debug_mon_sel", 0x00000038, 1, 0, CSR_RW, 0x00000000 },
	{ "DEBUG_MON", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved
	{ "reserved", 0x0000003C, 15, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ti_hpf_r
	{ "hpf_coeff_0_r_2s", 0x00000040, 5, 0, CSR_RW, 0x0000003C },
	{ "hpf_coeff_1_r_2s", 0x00000040, 13, 8, CSR_RW, 0x00000006 },
	{ "hpf_coeff_2_r_2s", 0x00000040, 21, 16, CSR_RW, 0x0000003E },
	{ "TI_HPF_R", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD ti_hpf_b
	{ "hpf_coeff_0_b_2s", 0x00000044, 5, 0, CSR_RW, 0x0000003C },
	{ "hpf_coeff_1_b_2s", 0x00000044, 13, 8, CSR_RW, 0x00000006 },
	{ "hpf_coeff_2_b_2s", 0x00000044, 21, 16, CSR_RW, 0x0000003E },
	{ "TI_HPF_B", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD ti_hpf_g
	{ "hpf_coeff_0_g_2s", 0x00000048, 5, 0, CSR_RW, 0x0000003D },
	{ "hpf_coeff_1_g_2s", 0x00000048, 13, 8, CSR_RW, 0x00000008 },
	{ "hpf_coeff_2_g_2s", 0x00000048, 21, 16, CSR_RW, 0x0000003B },
	{ "TI_HPF_G", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD lcac_achroma_conf
	{ "achromatic_th", 0x0000004C, 9, 0, CSR_RW, 0x0000003C },
	{ "achroma_conf_slope", 0x0000004C, 20, 16, CSR_RW, 0x0000001F },
	{ "LCAC_ACHROMA_CONF", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lcac_avg
	{ "r_g_diff_alpha", 0x00000050, 3, 0, CSR_RW, 0x00000004 },
	{ "b_g_diff_alpha", 0x00000050, 11, 8, CSR_RW, 0x00000008 },
	{ "m_g_diff_soft_clip_slope", 0x00000050, 20, 16, CSR_RW, 0x00000004 },
	{ "LCAC_AVG", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD lcac_luma_cal
	{ "luma_coeff_r_y", 0x00000054, 4, 0, CSR_RW, 0x00000005 },
	{ "luma_coeff_g_y", 0x00000054, 12, 8, CSR_RW, 0x00000009 },
	{ "luma_coeff_b_y", 0x00000054, 20, 16, CSR_RW, 0x00000002 },
	{ "LCAC_LUMA_CAL", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD lcac_level
	{ "lcac_r_level", 0x00000058, 4, 0, CSR_RW, 0x00000010 },
	{ "lcac_b_level", 0x00000058, 12, 8, CSR_RW, 0x00000010 },
	{ "LCAC_LEVEL", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD arbitration
	{ "arbitration_chromatic_constraint_r", 0x0000005C, 3, 0, CSR_RW, 0x00000008 },
	{ "arbitration_chromatic_constraint_b", 0x0000005C, 11, 8, CSR_RW, 0x00000002 },
	{ "arbitration_func_parameter", 0x0000005C, 19, 16, CSR_RW, 0x00000009 },
	{ "ARBITRATION", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD output_alpha
	{ "alpha_lcac_fcs", 0x00000060, 3, 0, CSR_RW, 0x00000000 },
	{ "OUTPUT_ALPHA", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_FCS_H_
