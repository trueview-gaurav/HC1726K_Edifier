/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_HDR_H_
#define CSR_TABLE_HDR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_hdr[] = {
	// WORD hdr00
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "HDR00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD hdr01
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "HDR01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD hdr02
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "HDR02", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD hdr03
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "HDR03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr05
	{ "width", 0x00000014, 15, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000014, 31, 16, CSR_RW, 0x00000438 },
	{ "HDR05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr06
	{ "mode", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase_i", 0x00000018, 9, 8, CSR_RW, 0x00000000 },
	{ "exp_long_early", 0x00000018, 16, 16, CSR_RW, 0x00000000 },
	{ "hdr_merge_en", 0x00000018, 24, 24, CSR_RW, 0x00000001 },
	{ "HDR06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr07
	{ "exp_ratio", 0x0000001C, 8, 0, CSR_RW, 0x00000010 },
	{ "exp_ratio_inv", 0x0000001C, 24, 16, CSR_RW, 0x00000100 },
	{ "HDR07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr08
	{ "se_anti_gamma_mode", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "le_anti_gamma_mode", 0x00000020, 8, 8, CSR_RW, 0x00000001 },
	{ "ink_num", 0x00000020, 19, 16, CSR_RW, 0x00000000 },
	{ "weight_mode", 0x00000020, 24, 24, CSR_RW, 0x00000001 },
	{ "HDR08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr09
	{ "le_weight_th_max", 0x00000024, 11, 0, CSR_RW, 0x00000F40 },
	{ "le_weight_slope", 0x00000024, 23, 16, CSR_RW, 0x00000010 },
	{ "HDR09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr10
	{ "le_weight_min", 0x00000028, 6, 0, CSR_RW, 0x00000000 },
	{ "le_weight_max", 0x00000028, 22, 16, CSR_RW, 0x00000040 },
	{ "HDR10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr11
	{ "le_overflow_protect_en", 0x0000002C, 0, 0, CSR_RW, 0x00000001 },
	{ "fallback_mode", 0x0000002C, 1, 1, CSR_RW, 0x00000000 },
	{ "le_overflow_protect_r_th", 0x0000002C, 14, 3, CSR_RW, 0x00000017 },
	{ "le_overflow_protect_g_th", 0x0000002C, 27, 16, CSR_RW, 0x00000017 },
	{ "HDR11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr12
	{ "le_overflow_protect_b_th", 0x00000030, 11, 0, CSR_RW, 0x00000017 },
	{ "le_overflow_ratio", 0x00000030, 21, 16, CSR_RW, 0x00000010 },
	{ "HDR12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr13
	{ "mismatch_var_gain_2s", 0x00000034, 5, 0, CSR_RW, 0x00000001 },
	{ "hdr_en", 0x00000034, 8, 8, CSR_RW, 0x00000001 },
	{ "HDR13", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr14
	{ "local_fb_th", 0x00000038, 11, 0, CSR_RW, 0x00000180 },
	{ "local_fb_slope", 0x00000038, 23, 16, CSR_RW, 0x00000007 },
	{ "HDR14", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr15
	{ "local_fb_min", 0x0000003C, 6, 0, CSR_RW, 0x00000000 },
	{ "local_fb_max", 0x0000003C, 22, 16, CSR_RW, 0x00000010 },
	{ "le_var_weight", 0x0000003C, 28, 24, CSR_RW, 0x0000000A },
	{ "HDR15", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr16
	{ "frame_fb_strength", 0x00000040, 6, 0, CSR_RW, 0x00000000 },
	{ "fb_target", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "fb_alpha", 0x00000040, 22, 16, CSR_RW, 0x00000000 },
	{ "HDR16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr17
	{ "se_exp_ratio_min_int", 0x00000044, 4, 0, CSR_RW, 0x0000000B },
	{ "ltm_en", 0x00000044, 8, 8, CSR_RW, 0x00000001 },
	{ "ltm_bilinear_en", 0x00000044, 16, 16, CSR_RW, 0x00000001 },
	{ "HDR17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr18
	{ "rgl_h_num_cuv", 0x00000048, 3, 0, CSR_RW, 0x00000008 },
	{ "rgl_v_num_cuv", 0x00000048, 19, 16, CSR_RW, 0x00000008 },
	{ "HDR18", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr19
	{ "rgl_h_num_hist", 0x0000004C, 3, 0, CSR_RW, 0x00000008 },
	{ "rgl_v_num_hist", 0x0000004C, 19, 16, CSR_RW, 0x00000008 },
	{ "HDR19", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr20
	{ "rgl_x_cnt_ini_cuv", 0x00000050, 24, 0, CSR_RW, 0x00000000 },
	{ "HDR20", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr21
	{ "rgl_y_cnt_ini_cuv", 0x00000054, 24, 0, CSR_RW, 0x00000000 },
	{ "HDR21", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr22
	{ "rgl_x_cnt_ini_hist", 0x00000058, 24, 0, CSR_RW, 0x00000000 },
	{ "HDR22", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr23
	{ "rgl_y_cnt_ini_hist", 0x0000005C, 24, 0, CSR_RW, 0x00000000 },
	{ "HDR23", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr24
	{ "rgl_x_cnt_step_cuv", 0x00000060, 21, 0, CSR_RW, 0x00000000 },
	{ "HDR24", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr25
	{ "rgl_y_cnt_step_cuv", 0x00000064, 21, 0, CSR_RW, 0x00000000 },
	{ "HDR25", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr26
	{ "rgl_x_cnt_step_hist", 0x00000068, 21, 0, CSR_RW, 0x00000000 },
	{ "HDR26", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr27
	{ "rgl_y_cnt_step_hist", 0x0000006C, 21, 0, CSR_RW, 0x00000000 },
	{ "HDR27", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr28
	{ "awb_enable", 0x00000070, 0, 0, CSR_RW, 0x00000001 },
	{ "HDR28", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr29
	{ "awb_gain_0", 0x00000074, 11, 0, CSR_RW, 0x00000100 },
	{ "awb_gain_1", 0x00000074, 27, 16, CSR_RW, 0x00000100 },
	{ "HDR29", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr30
	{ "awb_gain_2", 0x00000078, 11, 0, CSR_RW, 0x00000100 },
	{ "awb_gain_3", 0x00000078, 27, 16, CSR_RW, 0x00000100 },
	{ "HDR30", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr31
	{ "gamma_en", 0x0000007C, 0, 0, CSR_RW, 0x00000000 },
	{ "HDR31", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr32
	{ "efuse_dis_hdr_violation", 0x00000080, 0, 0, CSR_RO, 0x00000000 },
	{ "HDR32", 0x00000080, 31, 0, CSR_RO, 0x00000000 },
	// WORD hdr33
	{ "reserved_0", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	{ "HDR33", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr34
	{ "reserved_1", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	{ "HDR34", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr35
	{ "debug_mon_sel", 0x0000008C, 1, 0, CSR_RW, 0x00000000 },
	{ "HDR35", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD histogram_en
	{ "hist_en", 0x00000090, 0, 0, CSR_RW, 0x00000001 },
	{ "HISTOGRAM_EN", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD histogram_clear
	{ "hist_clear", 0x00000094, 0, 0, CSR_RW, 0x00000000 },
	{ "HISTOGRAM_CLEAR", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD histogram_x
	{ "hist_sx", 0x00000098, 8, 0, CSR_RW, 0x00000000 },
	{ "hist_ex", 0x00000098, 24, 16, CSR_RW, 0x000001FF },
	{ "HISTOGRAM_X", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD histogram_y
	{ "hist_sy", 0x0000009C, 12, 0, CSR_RW, 0x00000000 },
	{ "hist_ey", 0x0000009C, 28, 16, CSR_RW, 0x00000437 },
	{ "HISTOGRAM_Y", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD histogram_offset
	{ "y_hist_offset", 0x000000A0, 15, 0, CSR_RW, 0x00000000 },
	{ "HISTOGRAM_OFFSET", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr_csr2sram_sel
	{ "csr2sram_enable", 0x000000A4, 0, 0, CSR_RW, 0x00000000 },
	{ "HDR_CSR2SRAM_SEL", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD histogram_e_r_addr
	{ "hist_e_r_addr", 0x000000A8, 10, 0, CSR_RW, 0x00000000 },
	{ "HISTOGRAM_E_R_ADDR", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD histogram_e_r_data
	{ "hist_e_r_data", 0x000000AC, 17, 0, CSR_RO, 0x00000000 },
	{ "HISTOGRAM_E_R_DATA", 0x000000AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD histogram_o_r_addr
	{ "hist_o_r_addr", 0x000000B0, 10, 0, CSR_RW, 0x00000000 },
	{ "HISTOGRAM_O_R_ADDR", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD histogram_o_r_data
	{ "hist_o_r_data", 0x000000B4, 17, 0, CSR_RO, 0x00000000 },
	{ "HISTOGRAM_O_R_DATA", 0x000000B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD tone_offset_0_0
	{ "y_tone_offset_0_0", 0x000000B8, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_0_1", 0x000000B8, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_0_0", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_0_1
	{ "y_tone_offset_0_2", 0x000000BC, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_0_3", 0x000000BC, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_0_1", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_0_2
	{ "y_tone_offset_0_4", 0x000000C0, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_0_5", 0x000000C0, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_0_2", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_0_3
	{ "y_tone_offset_0_6", 0x000000C4, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_0_7", 0x000000C4, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_0_3", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_1_0
	{ "y_tone_offset_1_0", 0x000000C8, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_1_1", 0x000000C8, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_1_0", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_1_1
	{ "y_tone_offset_1_2", 0x000000CC, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_1_3", 0x000000CC, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_1_1", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_1_2
	{ "y_tone_offset_1_4", 0x000000D0, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_1_5", 0x000000D0, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_1_2", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_1_3
	{ "y_tone_offset_1_6", 0x000000D4, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_1_7", 0x000000D4, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_1_3", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_2_0
	{ "y_tone_offset_2_0", 0x000000D8, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_2_1", 0x000000D8, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_2_0", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_2_1
	{ "y_tone_offset_2_2", 0x000000DC, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_2_3", 0x000000DC, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_2_1", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_2_2
	{ "y_tone_offset_2_4", 0x000000E0, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_2_5", 0x000000E0, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_2_2", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_2_3
	{ "y_tone_offset_2_6", 0x000000E4, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_2_7", 0x000000E4, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_2_3", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_3_0
	{ "y_tone_offset_3_0", 0x000000E8, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_3_1", 0x000000E8, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_3_0", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_3_1
	{ "y_tone_offset_3_2", 0x000000EC, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_3_3", 0x000000EC, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_3_1", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_3_2
	{ "y_tone_offset_3_4", 0x000000F0, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_3_5", 0x000000F0, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_3_2", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_offset_3_3
	{ "y_tone_offset_3_6", 0x000000F4, 15, 0, CSR_RW, 0x00000000 },
	{ "y_tone_offset_3_7", 0x000000F4, 31, 16, CSR_RW, 0x00000000 },
	{ "TONE_OFFSET_3_3", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_ee_e_w_addr
	{ "tcuv_ee_e_w_addr", 0x000000F8, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EE_E_W_ADDR", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_ee_e_w_data
	{ "tcuv_ee_e_w_data", 0x000000FC, 27, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EE_E_W_DATA", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_ee_e_r_addr
	{ "tcuv_ee_e_r_addr", 0x00000100, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EE_E_R_ADDR", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_ee_e_r_data
	{ "tcuv_ee_e_r_data", 0x00000104, 27, 0, CSR_RO, 0x00000000 },
	{ "TONE_CURVE_EE_E_R_DATA", 0x00000104, 31, 0, CSR_RO, 0x00000000 },
	// WORD tone_curve_ee_o_w_addr
	{ "tcuv_ee_o_w_addr", 0x00000108, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EE_O_W_ADDR", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_ee_o_w_data
	{ "tcuv_ee_o_w_data", 0x0000010C, 27, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EE_O_W_DATA", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_ee_o_r_addr
	{ "tcuv_ee_o_r_addr", 0x00000110, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EE_O_R_ADDR", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_ee_o_r_data
	{ "tcuv_ee_o_r_data", 0x00000114, 27, 0, CSR_RO, 0x00000000 },
	{ "TONE_CURVE_EE_O_R_DATA", 0x00000114, 31, 0, CSR_RO, 0x00000000 },
	// WORD tone_curve_eo_e_w_addr
	{ "tcuv_eo_e_w_addr", 0x00000118, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EO_E_W_ADDR", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_eo_e_w_data
	{ "tcuv_eo_e_w_data", 0x0000011C, 27, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EO_E_W_DATA", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_eo_e_r_addr
	{ "tcuv_eo_e_r_addr", 0x00000120, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EO_E_R_ADDR", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_eo_e_r_data
	{ "tcuv_eo_e_r_data", 0x00000124, 27, 0, CSR_RO, 0x00000000 },
	{ "TONE_CURVE_EO_E_R_DATA", 0x00000124, 31, 0, CSR_RO, 0x00000000 },
	// WORD tone_curve_eo_o_w_addr
	{ "tcuv_eo_o_w_addr", 0x00000128, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EO_O_W_ADDR", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_eo_o_w_data
	{ "tcuv_eo_o_w_data", 0x0000012C, 27, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EO_O_W_DATA", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_eo_o_r_addr
	{ "tcuv_eo_o_r_addr", 0x00000130, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_EO_O_R_ADDR", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_eo_o_r_data
	{ "tcuv_eo_o_r_data", 0x00000134, 27, 0, CSR_RO, 0x00000000 },
	{ "TONE_CURVE_EO_O_R_DATA", 0x00000134, 31, 0, CSR_RO, 0x00000000 },
	// WORD tone_curve_oe_e_w_addr
	{ "tcuv_oe_e_w_addr", 0x00000138, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OE_E_W_ADDR", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oe_e_w_data
	{ "tcuv_oe_e_w_data", 0x0000013C, 27, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OE_E_W_DATA", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oe_e_r_addr
	{ "tcuv_oe_e_r_addr", 0x00000140, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OE_E_R_ADDR", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oe_e_r_data
	{ "tcuv_oe_e_r_data", 0x00000144, 27, 0, CSR_RO, 0x00000000 },
	{ "TONE_CURVE_OE_E_R_DATA", 0x00000144, 31, 0, CSR_RO, 0x00000000 },
	// WORD tone_curve_oe_o_w_addr
	{ "tcuv_oe_o_w_addr", 0x00000148, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OE_O_W_ADDR", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oe_o_w_data
	{ "tcuv_oe_o_w_data", 0x0000014C, 27, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OE_O_W_DATA", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oe_o_r_addr
	{ "tcuv_oe_o_r_addr", 0x00000150, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OE_O_R_ADDR", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oe_o_r_data
	{ "tcuv_oe_o_r_data", 0x00000154, 27, 0, CSR_RO, 0x00000000 },
	{ "TONE_CURVE_OE_O_R_DATA", 0x00000154, 31, 0, CSR_RO, 0x00000000 },
	// WORD tone_curve_oo_e_w_addr
	{ "tcuv_oo_e_w_addr", 0x00000158, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OO_E_W_ADDR", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oo_e_w_data
	{ "tcuv_oo_e_w_data", 0x0000015C, 27, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OO_E_W_DATA", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oo_e_r_addr
	{ "tcuv_oo_e_r_addr", 0x00000160, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OO_E_R_ADDR", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oo_e_r_data
	{ "tcuv_oo_e_r_data", 0x00000164, 27, 0, CSR_RO, 0x00000000 },
	{ "TONE_CURVE_OO_E_R_DATA", 0x00000164, 31, 0, CSR_RO, 0x00000000 },
	// WORD tone_curve_oo_o_w_addr
	{ "tcuv_oo_o_w_addr", 0x00000168, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OO_O_W_ADDR", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oo_o_w_data
	{ "tcuv_oo_o_w_data", 0x0000016C, 27, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OO_O_W_DATA", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oo_o_r_addr
	{ "tcuv_oo_o_r_addr", 0x00000170, 8, 0, CSR_RW, 0x00000000 },
	{ "TONE_CURVE_OO_O_R_ADDR", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD tone_curve_oo_o_r_data
	{ "tcuv_oo_o_r_data", 0x00000174, 27, 0, CSR_RO, 0x00000000 },
	{ "TONE_CURVE_OO_O_R_DATA", 0x00000174, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_0
	{ "y_hist_out_0", 0x00000178, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_0", 0x00000178, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_1
	{ "y_hist_out_1", 0x0000017C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_1", 0x0000017C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_2
	{ "y_hist_out_2", 0x00000180, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_2", 0x00000180, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_3
	{ "y_hist_out_3", 0x00000184, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_3", 0x00000184, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_4
	{ "y_hist_out_4", 0x00000188, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_4", 0x00000188, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_5
	{ "y_hist_out_5", 0x0000018C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_5", 0x0000018C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_6
	{ "y_hist_out_6", 0x00000190, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_6", 0x00000190, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_7
	{ "y_hist_out_7", 0x00000194, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_7", 0x00000194, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_8
	{ "y_hist_out_8", 0x00000198, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_8", 0x00000198, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_9
	{ "y_hist_out_9", 0x0000019C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_9", 0x0000019C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_10
	{ "y_hist_out_10", 0x000001A0, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_10", 0x000001A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_11
	{ "y_hist_out_11", 0x000001A4, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_11", 0x000001A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_12
	{ "y_hist_out_12", 0x000001A8, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_12", 0x000001A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_13
	{ "y_hist_out_13", 0x000001AC, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_13", 0x000001AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_14
	{ "y_hist_out_14", 0x000001B0, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_14", 0x000001B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_15
	{ "y_hist_out_15", 0x000001B4, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_15", 0x000001B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_16
	{ "y_hist_out_16", 0x000001B8, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_16", 0x000001B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_17
	{ "y_hist_out_17", 0x000001BC, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_17", 0x000001BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_18
	{ "y_hist_out_18", 0x000001C0, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_18", 0x000001C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_19
	{ "y_hist_out_19", 0x000001C4, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_19", 0x000001C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_20
	{ "y_hist_out_20", 0x000001C8, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_20", 0x000001C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_21
	{ "y_hist_out_21", 0x000001CC, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_21", 0x000001CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_22
	{ "y_hist_out_22", 0x000001D0, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_22", 0x000001D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_23
	{ "y_hist_out_23", 0x000001D4, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_23", 0x000001D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_24
	{ "y_hist_out_24", 0x000001D8, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_24", 0x000001D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_25
	{ "y_hist_out_25", 0x000001DC, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_25", 0x000001DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_26
	{ "y_hist_out_26", 0x000001E0, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_26", 0x000001E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_27
	{ "y_hist_out_27", 0x000001E4, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_27", 0x000001E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_28
	{ "y_hist_out_28", 0x000001E8, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_28", 0x000001E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_29
	{ "y_hist_out_29", 0x000001EC, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_29", 0x000001EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_30
	{ "y_hist_out_30", 0x000001F0, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_30", 0x000001F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_31
	{ "y_hist_out_31", 0x000001F4, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_31", 0x000001F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_32
	{ "y_hist_out_32", 0x000001F8, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_32", 0x000001F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_33
	{ "y_hist_out_33", 0x000001FC, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_33", 0x000001FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_34
	{ "y_hist_out_34", 0x00000200, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_34", 0x00000200, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_35
	{ "y_hist_out_35", 0x00000204, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_35", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_36
	{ "y_hist_out_36", 0x00000208, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_36", 0x00000208, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_37
	{ "y_hist_out_37", 0x0000020C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_37", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_38
	{ "y_hist_out_38", 0x00000210, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_38", 0x00000210, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_39
	{ "y_hist_out_39", 0x00000214, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_39", 0x00000214, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_40
	{ "y_hist_out_40", 0x00000218, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_40", 0x00000218, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_41
	{ "y_hist_out_41", 0x0000021C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_41", 0x0000021C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_42
	{ "y_hist_out_42", 0x00000220, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_42", 0x00000220, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_43
	{ "y_hist_out_43", 0x00000224, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_43", 0x00000224, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_44
	{ "y_hist_out_44", 0x00000228, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_44", 0x00000228, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_45
	{ "y_hist_out_45", 0x0000022C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_45", 0x0000022C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_46
	{ "y_hist_out_46", 0x00000230, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_46", 0x00000230, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_47
	{ "y_hist_out_47", 0x00000234, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_47", 0x00000234, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_48
	{ "y_hist_out_48", 0x00000238, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_48", 0x00000238, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_49
	{ "y_hist_out_49", 0x0000023C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_49", 0x0000023C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_50
	{ "y_hist_out_50", 0x00000240, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_50", 0x00000240, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_51
	{ "y_hist_out_51", 0x00000244, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_51", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_52
	{ "y_hist_out_52", 0x00000248, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_52", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_53
	{ "y_hist_out_53", 0x0000024C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_53", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_54
	{ "y_hist_out_54", 0x00000250, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_54", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_55
	{ "y_hist_out_55", 0x00000254, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_55", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_56
	{ "y_hist_out_56", 0x00000258, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_56", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_57
	{ "y_hist_out_57", 0x0000025C, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_57", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_58
	{ "y_hist_out_58", 0x00000260, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_58", 0x00000260, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_59
	{ "y_hist_out_59", 0x00000264, 23, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_59", 0x00000264, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_ctrl_0
	{ "y_hist_out_en", 0x00000268, 0, 0, CSR_RW, 0x00000000 },
	{ "y_hist_out_clear", 0x00000268, 8, 8, CSR_RW, 0x00000000 },
	{ "y_hist_out_offset", 0x00000268, 31, 16, CSR_RW, 0x00000000 },
	{ "Y_HIST_CTRL_0", 0x00000268, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_hist_ctrl_1
	{ "y_hist_out_overflow", 0x0000026C, 0, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_CTRL_1", 0x0000026C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_out_roi_x
	{ "y_hist_out_roi_sx", 0x00000270, 8, 0, CSR_RW, 0x00000000 },
	{ "y_hist_out_roi_ex", 0x00000270, 24, 16, CSR_RW, 0x000000FF },
	{ "Y_HIST_OUT_ROI_X", 0x00000270, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_hist_out_roi_y
	{ "y_hist_out_roi_sy", 0x00000274, 15, 0, CSR_RW, 0x00000000 },
	{ "y_hist_out_roi_ey", 0x00000274, 31, 16, CSR_RW, 0x00000AA9 },
	{ "Y_HIST_OUT_ROI_Y", 0x00000274, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_HDR_H_
