/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_LSC_H_
#define CSR_TABLE_LSC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_lsc[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_format
	{ "cfa_mode", 0x00000010, 1, 0, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "CFA_FORMAT", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_0
	{ "cfa_phase_0", 0x00000014, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_1", 0x00000014, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_2", 0x00000014, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_3", 0x00000014, 26, 24, CSR_RW, 0x00000000 },
	{ "WORD_CFA_PHASE_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_1
	{ "cfa_phase_4", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_5", 0x00000018, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_6", 0x00000018, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_7", 0x00000018, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_1", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_2
	{ "cfa_phase_8", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_9", 0x0000001C, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_10", 0x0000001C, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_11", 0x0000001C, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_2", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_3
	{ "cfa_phase_12", 0x00000020, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_13", 0x00000020, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_14", 0x00000020, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_15", 0x00000020, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_3", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000024, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000024, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mode
	{ "mode", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "bayer_phase_srep", 0x00000028, 9, 8, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_mode
	{ "curve_enable", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "CURVE_MODE", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_r_0
	{ "curve_gain_origin_r", 0x00000030, 17, 0, CSR_RW, 0x00010000 },
	{ "CURVE_GAIN_R_0", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_r_1
	{ "curve_gain_x_trend_2s_r", 0x00000034, 19, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_R_1", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_r_2
	{ "curve_gain_y_trend_2s_r", 0x00000038, 19, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_R_2", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_r_3
	{ "curve_gain_x_curvature_r", 0x0000003C, 25, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_R_3", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_r_4
	{ "curve_gain_y_curvature_r", 0x00000040, 25, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_R_4", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_r_5
	{ "curve_gain_tilt_2s_r", 0x00000044, 26, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_R_5", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_g_0
	{ "curve_gain_origin_g", 0x00000048, 17, 0, CSR_RW, 0x00010000 },
	{ "CURVE_GAIN_G_0", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_g_1
	{ "curve_gain_x_trend_2s_g", 0x0000004C, 19, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_G_1", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_g_2
	{ "curve_gain_y_trend_2s_g", 0x00000050, 19, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_G_2", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_g_3
	{ "curve_gain_x_curvature_g", 0x00000054, 25, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_G_3", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_g_4
	{ "curve_gain_y_curvature_g", 0x00000058, 25, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_G_4", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_g_5
	{ "curve_gain_tilt_2s_g", 0x0000005C, 26, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_G_5", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_b_0
	{ "curve_gain_origin_b", 0x00000060, 17, 0, CSR_RW, 0x00010000 },
	{ "CURVE_GAIN_B_0", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_b_1
	{ "curve_gain_x_trend_2s_b", 0x00000064, 19, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_B_1", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_b_2
	{ "curve_gain_y_trend_2s_b", 0x00000068, 19, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_B_2", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_b_3
	{ "curve_gain_x_curvature_b", 0x0000006C, 25, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_B_3", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_b_4
	{ "curve_gain_y_curvature_b", 0x00000070, 25, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_B_4", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_b_5
	{ "curve_gain_tilt_2s_b", 0x00000074, 26, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_B_5", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_s_0
	{ "curve_gain_origin_s", 0x00000078, 17, 0, CSR_RW, 0x00010000 },
	{ "CURVE_GAIN_S_0", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_s_1
	{ "curve_gain_x_trend_2s_s", 0x0000007C, 19, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_S_1", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_s_2
	{ "curve_gain_y_trend_2s_s", 0x00000080, 19, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_S_2", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_s_3
	{ "curve_gain_x_curvature_s", 0x00000084, 25, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_S_3", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_s_4
	{ "curve_gain_y_curvature_s", 0x00000088, 25, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_S_4", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_gain_s_5
	{ "curve_gain_tilt_2s_s", 0x0000008C, 26, 0, CSR_RW, 0x00000000 },
	{ "CURVE_GAIN_S_5", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_mode
	{ "table_enable", 0x00000090, 0, 0, CSR_RW, 0x00000000 },
	{ "table_gain_prec_m8", 0x00000090, 10, 8, CSR_RW, 0x00000000 },
	{ "table_merge_en", 0x00000090, 16, 16, CSR_RW, 0x00000001 },
	{ "TABLE_MODE", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_gain_mod
	{ "gain_mod", 0x00000094, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_GAIN_MOD", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_pos_h_0
	{ "hori_start_int", 0x00000098, 4, 0, CSR_RW, 0x00000000 },
	{ "hori_start_frac", 0x00000098, 29, 8, CSR_RW, 0x00000000 },
	{ "TABLE_POS_H_0", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_pos_h_1
	{ "hori_step", 0x0000009C, 21, 0, CSR_RW, 0x00000000 },
	{ "TABLE_POS_H_1", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_pos_v_0
	{ "verti_start_int", 0x000000A0, 4, 0, CSR_RW, 0x00000000 },
	{ "verti_start_frac", 0x000000A0, 29, 8, CSR_RW, 0x00000000 },
	{ "TABLE_POS_V_0", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_pos_v_1
	{ "verti_step", 0x000000A4, 21, 0, CSR_RW, 0x00000000 },
	{ "TABLE_POS_V_1", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD csr2sram_sel
	{ "lsc_csr_2_sram_enable", 0x000000A8, 0, 0, CSR_RW, 0x00000000 },
	{ "CSR2SRAM_SEL", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ee_w_addr
	{ "lsc_table_ee_w_addr", 0x000000AC, 9, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EE_W_ADDR", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ee_w_data
	{ "lsc_table_ee_w_data", 0x000000B0, 11, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EE_W_DATA", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ee_r_addr
	{ "lsc_table_ee_r_addr", 0x000000B4, 9, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EE_R_ADDR", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ee_r_data
	{ "lsc_table_ee_r_data", 0x000000B8, 11, 0, CSR_RO, 0x00000000 },
	{ "TABLE_EE_R_DATA", 0x000000B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x000000BC, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_LSC_H_
