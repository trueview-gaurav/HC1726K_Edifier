/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_NR_H_
#define CSR_TABLE_NR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_nr[] = {
	// WORD word_mode
	{ "mode", 0x00000000, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD fir_mode
	{ "fir_kernel_sel_y", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "fir_weight_y", 0x00000004, 12, 8, CSR_RW, 0x00000010 },
	{ "fir_weight_c", 0x00000004, 20, 16, CSR_RW, 0x00000010 },
	{ "fir_diff_tolerance_thd", 0x00000004, 31, 24, CSR_RW, 0x00000060 },
	{ "FIR_MODE", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD fir_setting
	{ "fir_stronger_level", 0x00000008, 3, 0, CSR_RW, 0x00000000 },
	{ "fir_stronger_by_frame", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "FIR_SETTING", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD iir_mode
	{ "iir_alpha_y_offset", 0x0000000C, 6, 0, CSR_RW, 0x00000008 },
	{ "iir_alpha_c_offset", 0x0000000C, 14, 8, CSR_RW, 0x00000008 },
	{ "IIR_MODE", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD iir_strength
	{ "iir_ma_max_strength", 0x00000010, 6, 0, CSR_RW, 0x00000078 },
	{ "iir_mc_max_strength", 0x00000010, 14, 8, CSR_RW, 0x0000007C },
	{ "IIR_STRENGTH", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD attributes1
	{ "moving_coring_th", 0x00000014, 1, 0, CSR_RW, 0x00000000 },
	{ "moving_perblk_max", 0x00000014, 11, 8, CSR_RW, 0x00000008 },
	{ "mv_consist_coring", 0x00000014, 18, 16, CSR_RW, 0x00000002 },
	{ "mv_consist_perblk_max", 0x00000014, 27, 24, CSR_RW, 0x00000008 },
	{ "ATTRIBUTES1", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD attributes2
	{ "texture_coring_bits", 0x00000018, 2, 0, CSR_RW, 0x00000005 },
	{ "mv_consist_round_bit", 0x00000018, 9, 8, CSR_RW, 0x00000000 },
	{ "force_mv_consist_en", 0x00000018, 16, 16, CSR_RW, 0x00000000 },
	{ "force_mv_consist", 0x00000018, 29, 24, CSR_RW, 0x00000020 },
	{ "ATTRIBUTES2", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_strength_adaptive1
	{ "ma_edge_thd", 0x0000001C, 4, 0, CSR_RW, 0x0000000E },
	{ "ma_still_lvl_moving_upper_bnd", 0x0000001C, 13, 8, CSR_RW, 0x00000020 },
	{ "ma_still_edge_add_weight_max", 0x0000001C, 22, 16, CSR_RW, 0x00000060 },
	{ "ma_smooth_texture_upper_bnd", 0x0000001C, 29, 24, CSR_RW, 0x00000018 },
	{ "MA_STRENGTH_ADAPTIVE1", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_strength_adaptive2
	{ "ma_sad_norm_texture_shift_bit", 0x00000020, 1, 0, CSR_RW, 0x00000001 },
	{ "ma_nonstill_moving_thd", 0x00000020, 11, 8, CSR_RW, 0x00000008 },
	{ "ma_nonstill_smooth_fb_discard_match", 0x00000020, 16, 16, CSR_RW, 0x00000001 },
	{ "ma_nonstill_smooth_sub_wei_rto", 0x00000020, 29, 24, CSR_RW, 0x0000000E },
	{ "MA_STRENGTH_ADAPTIVE2", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_strength_adaptive3
	{ "ma_still_consistency_thd", 0x00000024, 4, 0, CSR_RW, 0x00000015 },
	{ "MA_STRENGTH_ADAPTIVE3", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_strength_adaptive1
	{ "mc_texture_thd", 0x00000028, 4, 0, CSR_RW, 0x0000000C },
	{ "iir_mc_conf_edge_add_weight_max", 0x00000028, 22, 16, CSR_RW, 0x00000040 },
	{ "mc_mixing_fir_level", 0x00000028, 27, 24, CSR_RW, 0x00000000 },
	{ "MC_STRENGTH_ADAPTIVE1", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_strength_adaptive2
	{ "mc_consistency_thd", 0x0000002C, 4, 0, CSR_RW, 0x00000015 },
	{ "MC_STRENGTH_ADAPTIVE2", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_i_0_1
	{ "ma_y_lut_i_0", 0x00000030, 10, 0, CSR_RW, 0x00000000 },
	{ "ma_y_lut_i_1", 0x00000030, 26, 16, CSR_RW, 0x00000014 },
	{ "MA_Y_LUT_I_0_1", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_i_2_3
	{ "ma_y_lut_i_2", 0x00000034, 10, 0, CSR_RW, 0x0000002C },
	{ "ma_y_lut_i_3", 0x00000034, 26, 16, CSR_RW, 0x0000004A },
	{ "MA_Y_LUT_I_2_3", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_i_4_5
	{ "ma_y_lut_i_4", 0x00000038, 10, 0, CSR_RW, 0x00000064 },
	{ "ma_y_lut_i_5", 0x00000038, 26, 16, CSR_RW, 0x00000084 },
	{ "MA_Y_LUT_I_4_5", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_i_6_7
	{ "ma_y_lut_i_6", 0x0000003C, 10, 0, CSR_RW, 0x0000009A },
	{ "ma_y_lut_i_7", 0x0000003C, 26, 16, CSR_RW, 0x000000D4 },
	{ "MA_Y_LUT_I_6_7", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_i_8_8
	{ "ma_y_lut_i_8", 0x00000040, 10, 0, CSR_RW, 0x00000148 },
	{ "MA_Y_LUT_I_8_8", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_o_0_3
	{ "ma_y_lut_o_0", 0x00000044, 7, 0, CSR_RW, 0x00000060 },
	{ "ma_y_lut_o_1", 0x00000044, 15, 8, CSR_RW, 0x00000078 },
	{ "ma_y_lut_o_2", 0x00000044, 23, 16, CSR_RW, 0x00000074 },
	{ "ma_y_lut_o_3", 0x00000044, 31, 24, CSR_RW, 0x00000068 },
	{ "MA_Y_LUT_O_0_3", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_o_4_7
	{ "ma_y_lut_o_4", 0x00000048, 7, 0, CSR_RW, 0x00000060 },
	{ "ma_y_lut_o_5", 0x00000048, 15, 8, CSR_RW, 0x00000050 },
	{ "ma_y_lut_o_6", 0x00000048, 23, 16, CSR_RW, 0x00000040 },
	{ "ma_y_lut_o_7", 0x00000048, 31, 24, CSR_RW, 0x00000018 },
	{ "MA_Y_LUT_O_4_7", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_o_8_8
	{ "ma_y_lut_o_8", 0x0000004C, 7, 0, CSR_RW, 0x00000000 },
	{ "MA_Y_LUT_O_8_8", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_slope_0_1
	{ "ma_y_lut_slope_0", 0x00000050, 15, 0, CSR_RW, 0x00000000 },
	{ "ma_y_lut_slope_1", 0x00000050, 31, 16, CSR_RW, 0x00000000 },
	{ "MA_Y_LUT_SLOPE_0_1", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_slope_2_3
	{ "ma_y_lut_slope_2", 0x00000054, 15, 0, CSR_RW, 0x00000000 },
	{ "ma_y_lut_slope_3", 0x00000054, 31, 16, CSR_RW, 0x00000000 },
	{ "MA_Y_LUT_SLOPE_2_3", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_slope_4_5
	{ "ma_y_lut_slope_4", 0x00000058, 15, 0, CSR_RW, 0x00000000 },
	{ "ma_y_lut_slope_5", 0x00000058, 31, 16, CSR_RW, 0x00000000 },
	{ "MA_Y_LUT_SLOPE_4_5", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lut_slope_6_7
	{ "ma_y_lut_slope_6", 0x0000005C, 15, 0, CSR_RW, 0x00000000 },
	{ "ma_y_lut_slope_7", 0x0000005C, 31, 16, CSR_RW, 0x00000000 },
	{ "MA_Y_LUT_SLOPE_6_7", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lp_dyn_gain_0
	{ "ma_y_lp_dyn_gain_th_min", 0x00000060, 7, 0, CSR_RW, 0x00000004 },
	{ "ma_y_lp_dyn_gain_th_max", 0x00000060, 15, 8, CSR_RW, 0x0000000A },
	{ "ma_y_lp_dyn_gain_min", 0x00000060, 21, 16, CSR_RW, 0x0000000C },
	{ "ma_y_lp_dyn_gain_max", 0x00000060, 29, 24, CSR_RW, 0x00000010 },
	{ "MA_Y_LP_DYN_GAIN_0", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_y_lp_dyn_gain_1
	{ "ma_y_lp_dyn_gain_slope", 0x00000064, 13, 0, CSR_RW, 0x00000000 },
	{ "MA_Y_LP_DYN_GAIN_1", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_i_0_1
	{ "mc_y_lut_i_0", 0x00000068, 10, 0, CSR_RW, 0x00000000 },
	{ "mc_y_lut_i_1", 0x00000068, 26, 16, CSR_RW, 0x00000014 },
	{ "MC_Y_LUT_I_0_1", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_i_2_3
	{ "mc_y_lut_i_2", 0x0000006C, 10, 0, CSR_RW, 0x0000002C },
	{ "mc_y_lut_i_3", 0x0000006C, 26, 16, CSR_RW, 0x0000004A },
	{ "MC_Y_LUT_I_2_3", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_i_4_5
	{ "mc_y_lut_i_4", 0x00000070, 10, 0, CSR_RW, 0x00000064 },
	{ "mc_y_lut_i_5", 0x00000070, 26, 16, CSR_RW, 0x00000084 },
	{ "MC_Y_LUT_I_4_5", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_i_6_7
	{ "mc_y_lut_i_6", 0x00000074, 10, 0, CSR_RW, 0x0000009A },
	{ "mc_y_lut_i_7", 0x00000074, 26, 16, CSR_RW, 0x000000D4 },
	{ "MC_Y_LUT_I_6_7", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_i_8_8
	{ "mc_y_lut_i_8", 0x00000078, 10, 0, CSR_RW, 0x00000148 },
	{ "MC_Y_LUT_I_8_8", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_o_0_3
	{ "mc_y_lut_o_0", 0x0000007C, 7, 0, CSR_RW, 0x00000060 },
	{ "mc_y_lut_o_1", 0x0000007C, 15, 8, CSR_RW, 0x00000078 },
	{ "mc_y_lut_o_2", 0x0000007C, 23, 16, CSR_RW, 0x00000074 },
	{ "mc_y_lut_o_3", 0x0000007C, 31, 24, CSR_RW, 0x00000068 },
	{ "MC_Y_LUT_O_0_3", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_o_4_7
	{ "mc_y_lut_o_4", 0x00000080, 7, 0, CSR_RW, 0x00000060 },
	{ "mc_y_lut_o_5", 0x00000080, 15, 8, CSR_RW, 0x00000050 },
	{ "mc_y_lut_o_6", 0x00000080, 23, 16, CSR_RW, 0x00000040 },
	{ "mc_y_lut_o_7", 0x00000080, 31, 24, CSR_RW, 0x00000018 },
	{ "MC_Y_LUT_O_4_7", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_o_8_8
	{ "mc_y_lut_o_8", 0x00000084, 7, 0, CSR_RW, 0x00000000 },
	{ "MC_Y_LUT_O_8_8", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_slope_0_1
	{ "mc_y_lut_slope_0", 0x00000088, 15, 0, CSR_RW, 0x00000000 },
	{ "mc_y_lut_slope_1", 0x00000088, 31, 16, CSR_RW, 0x00000000 },
	{ "MC_Y_LUT_SLOPE_0_1", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_slope_2_3
	{ "mc_y_lut_slope_2", 0x0000008C, 15, 0, CSR_RW, 0x00000000 },
	{ "mc_y_lut_slope_3", 0x0000008C, 31, 16, CSR_RW, 0x00000000 },
	{ "MC_Y_LUT_SLOPE_2_3", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_slope_4_5
	{ "mc_y_lut_slope_4", 0x00000090, 15, 0, CSR_RW, 0x00000000 },
	{ "mc_y_lut_slope_5", 0x00000090, 31, 16, CSR_RW, 0x00000000 },
	{ "MC_Y_LUT_SLOPE_4_5", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_y_lut_slope_6_7
	{ "mc_y_lut_slope_6", 0x00000094, 15, 0, CSR_RW, 0x00000000 },
	{ "mc_y_lut_slope_7", 0x00000094, 31, 16, CSR_RW, 0x00000000 },
	{ "MC_Y_LUT_SLOPE_6_7", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_ratio1
	{ "force_mc_ratio_en", 0x00000098, 0, 0, CSR_RW, 0x00000000 },
	{ "force_mc_ratio", 0x00000098, 13, 8, CSR_RW, 0x00000010 },
	{ "mc_ratio_moving_thd", 0x00000098, 19, 16, CSR_RW, 0x00000008 },
	{ "mc_ratio_texture_thd", 0x00000098, 28, 24, CSR_RW, 0x00000008 },
	{ "MC_RATIO1", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD mc_ratio2
	{ "mc_ratio_texture_round_bit", 0x0000009C, 1, 0, CSR_RW, 0x00000000 },
	{ "mc_ratio_ignore_mcmatcher_lvl", 0x0000009C, 8, 8, CSR_RW, 0x00000000 },
	{ "MC_RATIO2", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_i_0_1
	{ "ma_c_lut_i_0", 0x000000A0, 10, 0, CSR_RW, 0x00000000 },
	{ "ma_c_lut_i_1", 0x000000A0, 26, 16, CSR_RW, 0x00000014 },
	{ "MA_C_LUT_I_0_1", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_i_2_3
	{ "ma_c_lut_i_2", 0x000000A4, 10, 0, CSR_RW, 0x0000002C },
	{ "ma_c_lut_i_3", 0x000000A4, 26, 16, CSR_RW, 0x0000004A },
	{ "MA_C_LUT_I_2_3", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_i_4_5
	{ "ma_c_lut_i_4", 0x000000A8, 10, 0, CSR_RW, 0x00000064 },
	{ "ma_c_lut_i_5", 0x000000A8, 26, 16, CSR_RW, 0x00000084 },
	{ "MA_C_LUT_I_4_5", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_i_6_7
	{ "ma_c_lut_i_6", 0x000000AC, 10, 0, CSR_RW, 0x0000009A },
	{ "ma_c_lut_i_7", 0x000000AC, 26, 16, CSR_RW, 0x000000D4 },
	{ "MA_C_LUT_I_6_7", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_i_8_8
	{ "ma_c_lut_i_8", 0x000000B0, 10, 0, CSR_RW, 0x00000148 },
	{ "MA_C_LUT_I_8_8", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_o_0_3
	{ "ma_c_lut_o_0", 0x000000B4, 7, 0, CSR_RW, 0x00000060 },
	{ "ma_c_lut_o_1", 0x000000B4, 15, 8, CSR_RW, 0x00000078 },
	{ "ma_c_lut_o_2", 0x000000B4, 23, 16, CSR_RW, 0x00000074 },
	{ "ma_c_lut_o_3", 0x000000B4, 31, 24, CSR_RW, 0x00000068 },
	{ "MA_C_LUT_O_0_3", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_o_4_7
	{ "ma_c_lut_o_4", 0x000000B8, 7, 0, CSR_RW, 0x00000060 },
	{ "ma_c_lut_o_5", 0x000000B8, 15, 8, CSR_RW, 0x00000050 },
	{ "ma_c_lut_o_6", 0x000000B8, 23, 16, CSR_RW, 0x00000040 },
	{ "ma_c_lut_o_7", 0x000000B8, 31, 24, CSR_RW, 0x00000018 },
	{ "MA_C_LUT_O_4_7", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_o_8_8
	{ "ma_c_lut_o_8", 0x000000BC, 7, 0, CSR_RW, 0x00000000 },
	{ "MA_C_LUT_O_8_8", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_slope_0_1
	{ "ma_c_lut_slope_0", 0x000000C0, 15, 0, CSR_RW, 0x00000000 },
	{ "ma_c_lut_slope_1", 0x000000C0, 31, 16, CSR_RW, 0x00000000 },
	{ "MA_C_LUT_SLOPE_0_1", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_slope_2_3
	{ "ma_c_lut_slope_2", 0x000000C4, 15, 0, CSR_RW, 0x00000000 },
	{ "ma_c_lut_slope_3", 0x000000C4, 31, 16, CSR_RW, 0x00000000 },
	{ "MA_C_LUT_SLOPE_2_3", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_slope_4_5
	{ "ma_c_lut_slope_4", 0x000000C8, 15, 0, CSR_RW, 0x00000000 },
	{ "ma_c_lut_slope_5", 0x000000C8, 31, 16, CSR_RW, 0x00000000 },
	{ "MA_C_LUT_SLOPE_4_5", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_lut_slope_6_7
	{ "ma_c_lut_slope_6", 0x000000CC, 15, 0, CSR_RW, 0x00000000 },
	{ "ma_c_lut_slope_7", 0x000000CC, 31, 16, CSR_RW, 0x00000000 },
	{ "MA_C_LUT_SLOPE_6_7", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD ma_c_y_strength_sel
	{ "ma_c_weight_sel", 0x000000D0, 0, 0, CSR_RW, 0x00000001 },
	{ "MA_C_Y_STRENGTH_SEL", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_abs_diff_hist_en
	{ "abs_diff_hist_en", 0x000000D4, 0, 0, CSR_RW, 0x00000000 },
	{ "abs_diff_hist_clear", 0x000000D4, 16, 16, CSR_RW, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_EN", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_abs_diff_hist_mode
	{ "abs_diff_hist_sel", 0x000000D8, 1, 0, CSR_RW, 0x00000000 },
	{ "abs_diff_hist_mode", 0x000000D8, 8, 8, CSR_RW, 0x00000000 },
	{ "abs_diff_hist_step", 0x000000D8, 18, 16, CSR_RW, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_MODE", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD abs_diff_hist_sxsy
	{ "abs_diff_hist_sx", 0x000000DC, 15, 0, CSR_RW, 0x00000000 },
	{ "abs_diff_hist_sy", 0x000000DC, 31, 16, CSR_RW, 0x00000000 },
	{ "ABS_DIFF_HIST_SXSY", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD abs_diff_hist_exey
	{ "abs_diff_hist_ex", 0x000000E0, 15, 0, CSR_RW, 0x00000000 },
	{ "abs_diff_hist_ey", 0x000000E0, 31, 16, CSR_RW, 0x00000000 },
	{ "ABS_DIFF_HIST_EXEY", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_abs_diff_hist_overflow
	{ "abs_diff_hist_overflow", 0x000000E4, 0, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_OVERFLOW", 0x000000E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_0
	{ "abs_diff_hist_0", 0x000000E8, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_0", 0x000000E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_1
	{ "abs_diff_hist_1", 0x000000EC, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_1", 0x000000EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_2
	{ "abs_diff_hist_2", 0x000000F0, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_2", 0x000000F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_3
	{ "abs_diff_hist_3", 0x000000F4, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_3", 0x000000F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_4
	{ "abs_diff_hist_4", 0x000000F8, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_4", 0x000000F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_5
	{ "abs_diff_hist_5", 0x000000FC, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_5", 0x000000FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_6
	{ "abs_diff_hist_6", 0x00000100, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_6", 0x00000100, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_7
	{ "abs_diff_hist_7", 0x00000104, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_7", 0x00000104, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_8
	{ "abs_diff_hist_8", 0x00000108, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_8", 0x00000108, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_9
	{ "abs_diff_hist_9", 0x0000010C, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_9", 0x0000010C, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_10
	{ "abs_diff_hist_10", 0x00000110, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_10", 0x00000110, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_11
	{ "abs_diff_hist_11", 0x00000114, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_11", 0x00000114, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_12
	{ "abs_diff_hist_12", 0x00000118, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_12", 0x00000118, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_13
	{ "abs_diff_hist_13", 0x0000011C, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_13", 0x0000011C, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_14
	{ "abs_diff_hist_14", 0x00000120, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_14", 0x00000120, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_15
	{ "abs_diff_hist_15", 0x00000124, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_15", 0x00000124, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_16
	{ "abs_diff_hist_16", 0x00000128, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_16", 0x00000128, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_17
	{ "abs_diff_hist_17", 0x0000012C, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_17", 0x0000012C, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_abs_diff_hist_18
	{ "abs_diff_hist_18", 0x00000130, 24, 0, CSR_RO, 0x00000000 },
	{ "WORD_ABS_DIFF_HIST_18", 0x00000130, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_tdiff_roi_0_en
	{ "tdiff_roi_0_en", 0x00000134, 0, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_0_clear", 0x00000134, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD_TDIFF_ROI_0_EN", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_0_sxsy
	{ "tdiff_roi_0_sx", 0x00000138, 15, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_0_sy", 0x00000138, 31, 16, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_0_SXSY", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_0_exey
	{ "tdiff_roi_0_ex", 0x0000013C, 15, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_0_ey", 0x0000013C, 31, 16, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_0_EXEY", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_0_th_y
	{ "tdiff_roi_0_acc_th_y", 0x00000140, 24, 0, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_0_TH_Y", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_0_th_c
	{ "tdiff_roi_0_acc_th_c", 0x00000144, 24, 0, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_0_TH_C", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_0_stat
	{ "tdiff_roi_0_avg_y", 0x00000148, 15, 0, CSR_RO, 0x00000000 },
	{ "tdiff_roi_0_avg_c", 0x00000148, 31, 16, CSR_RO, 0x00000000 },
	{ "TDIFF_ROI_0_STAT", 0x00000148, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_tdiff_roi_1_en
	{ "tdiff_roi_1_en", 0x0000014C, 0, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_1_clear", 0x0000014C, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD_TDIFF_ROI_1_EN", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_1_sxsy
	{ "tdiff_roi_1_sx", 0x00000150, 15, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_1_sy", 0x00000150, 31, 16, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_1_SXSY", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_1_exey
	{ "tdiff_roi_1_ex", 0x00000154, 15, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_1_ey", 0x00000154, 31, 16, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_1_EXEY", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_1_th_y
	{ "tdiff_roi_1_acc_th_y", 0x00000158, 24, 0, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_1_TH_Y", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_1_th_c
	{ "tdiff_roi_1_acc_th_c", 0x0000015C, 24, 0, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_1_TH_C", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_1_stat
	{ "tdiff_roi_1_avg_y", 0x00000160, 15, 0, CSR_RO, 0x00000000 },
	{ "tdiff_roi_1_avg_c", 0x00000160, 31, 16, CSR_RO, 0x00000000 },
	{ "TDIFF_ROI_1_STAT", 0x00000160, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_tdiff_roi_2_en
	{ "tdiff_roi_2_en", 0x00000164, 0, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_2_clear", 0x00000164, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD_TDIFF_ROI_2_EN", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_2_sxsy
	{ "tdiff_roi_2_sx", 0x00000168, 15, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_2_sy", 0x00000168, 31, 16, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_2_SXSY", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_2_exey
	{ "tdiff_roi_2_ex", 0x0000016C, 15, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_2_ey", 0x0000016C, 31, 16, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_2_EXEY", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_2_th_y
	{ "tdiff_roi_2_acc_th_y", 0x00000170, 24, 0, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_2_TH_Y", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_2_th_c
	{ "tdiff_roi_2_acc_th_c", 0x00000174, 24, 0, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_2_TH_C", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_2_stat
	{ "tdiff_roi_2_avg_y", 0x00000178, 15, 0, CSR_RO, 0x00000000 },
	{ "tdiff_roi_2_avg_c", 0x00000178, 31, 16, CSR_RO, 0x00000000 },
	{ "TDIFF_ROI_2_STAT", 0x00000178, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_tdiff_roi_3_en
	{ "tdiff_roi_3_en", 0x0000017C, 0, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_3_clear", 0x0000017C, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD_TDIFF_ROI_3_EN", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_3_sxsy
	{ "tdiff_roi_3_sx", 0x00000180, 15, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_3_sy", 0x00000180, 31, 16, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_3_SXSY", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_3_exey
	{ "tdiff_roi_3_ex", 0x00000184, 15, 0, CSR_RW, 0x00000000 },
	{ "tdiff_roi_3_ey", 0x00000184, 31, 16, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_3_EXEY", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_3_th_y
	{ "tdiff_roi_3_acc_th_y", 0x00000188, 24, 0, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_3_TH_Y", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_3_th_c
	{ "tdiff_roi_3_acc_th_c", 0x0000018C, 24, 0, CSR_RW, 0x00000000 },
	{ "TDIFF_ROI_3_TH_C", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tdiff_roi_3_stat
	{ "tdiff_roi_3_avg_y", 0x00000190, 15, 0, CSR_RO, 0x00000000 },
	{ "tdiff_roi_3_avg_c", 0x00000190, 31, 16, CSR_RO, 0x00000000 },
	{ "TDIFF_ROI_3_STAT", 0x00000190, 31, 0, CSR_RO, 0x00000000 },
	// WORD demo_roi_mode
	{ "demo_en", 0x00000194, 0, 0, CSR_RW, 0x00000000 },
	{ "demo_mode", 0x00000194, 18, 16, CSR_RW, 0x00000000 },
	{ "DEMO_ROI_MODE", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD demo_roi_sxsy
	{ "demo_sx", 0x00000198, 15, 0, CSR_RW, 0x00000000 },
	{ "demo_sy", 0x00000198, 31, 16, CSR_RW, 0x00000000 },
	{ "DEMO_ROI_SXSY", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	// WORD demo_roi_exey
	{ "demo_ex", 0x0000019C, 15, 0, CSR_RW, 0x00000000 },
	{ "demo_ey", 0x0000019C, 31, 16, CSR_RW, 0x00000000 },
	{ "DEMO_ROI_EXEY", 0x0000019C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ink_mode
	{ "ink_en", 0x000001A0, 0, 0, CSR_RW, 0x00000000 },
	{ "ink_nrw_en", 0x000001A0, 1, 1, CSR_RW, 0x00000000 },
	{ "nr_disp_en", 0x000001A0, 4, 4, CSR_RW, 0x00000001 },
	{ "ink_odd_pxl_sel", 0x000001A0, 8, 8, CSR_RW, 0x00000000 },
	{ "ink_odd_line_sel", 0x000001A0, 16, 16, CSR_RW, 0x00000000 },
	{ "ink_mode", 0x000001A0, 28, 24, CSR_RW, 0x00000000 },
	{ "WORD_INK_MODE", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved_0
	{ "reserved_0", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED_0", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved_1
	{ "reserved_1", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED_1", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_NR_H_
