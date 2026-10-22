/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_GFX_H_
#define CSR_TABLE_GFX_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_gfx[] = {
	// WORD gfx000
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "GFX000", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD gfx001
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_cache_overflow", 0x00000004, 1, 1, CSR_W1P, 0x00000000 },
	{ "GFX001", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD gfx002
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_cache_overflow", 0x00000008, 1, 1, CSR_RO, 0x00000000 },
	{ "GFX002", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD gfx003
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_cache_overflow", 0x0000000C, 1, 1, CSR_RW, 0x00000001 },
	{ "GFX003", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx005
	{ "dot_by_dot", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "mono_mode", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "interp_range_x", 0x00000014, 17, 16, CSR_RW, 0x00000002 },
	{ "interp_range_y", 0x00000014, 25, 24, CSR_RW, 0x00000002 },
	{ "GFX005", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx006
	{ "window_all_access", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "statistic_valid", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "src_ini_bayer_phase", 0x00000018, 17, 16, CSR_RW, 0x00000000 },
	{ "dst_ini_bayer_phase", 0x00000018, 25, 24, CSR_RW, 0x00000000 },
	{ "GFX006", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx007
	{ "dst_first_x_int", 0x0000001C, 12, 0, CSR_RW, 0x00000000 },
	{ "dst_first_y_int", 0x0000001C, 28, 16, CSR_RW, 0x00000000 },
	{ "GFX007", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx008
	{ "width", 0x00000020, 9, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000020, 29, 16, CSR_RW, 0x00000438 },
	{ "GFX008", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx009
	{ "src_region_x_min_int", 0x00000024, 12, 0, CSR_RW, 0x00000000 },
	{ "src_region_x_max_int", 0x00000024, 28, 16, CSR_RW, 0x0000077F },
	{ "GFX009", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx010
	{ "src_region_y_min_int", 0x00000028, 12, 0, CSR_RW, 0x00000000 },
	{ "src_region_y_max_int", 0x00000028, 28, 16, CSR_RW, 0x00000437 },
	{ "GFX010", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx011
	{ "dst_region_x_min_int", 0x0000002C, 12, 0, CSR_RW, 0x00000000 },
	{ "dst_region_x_max_int", 0x0000002C, 28, 16, CSR_RW, 0x0000077F },
	{ "GFX011", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx012
	{ "dst_region_y_min_int", 0x00000030, 12, 0, CSR_RW, 0x00000000 },
	{ "dst_region_y_max_int", 0x00000030, 28, 16, CSR_RW, 0x00000437 },
	{ "GFX012", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx013
	{ "invalid_r", 0x00000034, 9, 0, CSR_RW, 0x00000000 },
	{ "invalid_g", 0x00000034, 25, 16, CSR_RW, 0x00000000 },
	{ "GFX013", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx014
	{ "invalid_b", 0x00000038, 9, 0, CSR_RW, 0x00000000 },
	{ "cache_overflow_clip", 0x00000038, 16, 16, CSR_RW, 0x00000001 },
	{ "debug_mon_sel", 0x00000038, 26, 24, CSR_RW, 0x00000000 },
	{ "GFX014", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx015
	{ "shift_nus_x_2s", 0x0000003C, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX015", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx016
	{ "shift_nus_y_2s", 0x00000040, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX016", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx017
	{ "shift_sph_x_2s", 0x00000044, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX017", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx018
	{ "shift_sph_y_2s", 0x00000048, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX018", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx019
	{ "shift_pol_x_2s", 0x0000004C, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX019", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx020
	{ "shift_pol_y_2s", 0x00000050, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX020", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx021
	{ "shift_squ_x_2s", 0x00000054, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX021", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx022
	{ "shift_squ_y_2s", 0x00000058, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX022", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx023
	{ "shift_ldc_x_2s", 0x0000005C, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX023", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx024
	{ "shift_ldc_y_2s", 0x00000060, 17, 0, CSR_RW, 0x00000000 },
	{ "GFX024", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx025
	{ "nus_x_slope_sign", 0x00000064, 0, 0, CSR_RW, 0x00000000 },
	{ "nus_y_slope_sign", 0x00000064, 8, 8, CSR_RW, 0x00000000 },
	{ "GFX025", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx026
	{ "nus_x_in_1", 0x00000068, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX026", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx027
	{ "nus_x_in_2", 0x0000006C, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX027", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx028
	{ "nus_x_out_1", 0x00000070, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX028", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx029
	{ "nus_x_out_2", 0x00000074, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX029", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx030
	{ "nus_x_slope_base_0", 0x00000078, 15, 0, CSR_RW, 0x00008000 },
	{ "GFX030", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx031
	{ "nus_x_slope_base_1", 0x0000007C, 15, 0, CSR_RW, 0x00008000 },
	{ "GFX031", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx032
	{ "nus_x_slope_base_2", 0x00000080, 15, 0, CSR_RW, 0x00008000 },
	{ "GFX032", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx033
	{ "nus_x_slope_step_0", 0x00000084, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX033", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx034
	{ "nus_x_slope_step_1", 0x00000088, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX034", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx035
	{ "nus_x_slope_step_2", 0x0000008C, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX035", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx036
	{ "nus_y_in_1", 0x00000090, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX036", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx037
	{ "nus_y_in_2", 0x00000094, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX037", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx038
	{ "nus_y_out_1", 0x00000098, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX038", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx039
	{ "nus_y_out_2", 0x0000009C, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX039", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx040
	{ "nus_y_slope_base_0", 0x000000A0, 15, 0, CSR_RW, 0x00008000 },
	{ "GFX040", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx041
	{ "nus_y_slope_base_1", 0x000000A4, 15, 0, CSR_RW, 0x00008000 },
	{ "GFX041", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx042
	{ "nus_y_slope_base_2", 0x000000A8, 15, 0, CSR_RW, 0x00008000 },
	{ "GFX042", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx043
	{ "nus_y_slope_step_0", 0x000000AC, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX043", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx044
	{ "nus_y_slope_step_1", 0x000000B0, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX044", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx045
	{ "nus_y_slope_step_2", 0x000000B4, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX045", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx046
	{ "sph_en", 0x000000B8, 0, 0, CSR_RW, 0x00000000 },
	{ "sph_view_index", 0x000000B8, 8, 8, CSR_RW, 0x00000000 },
	{ "GFX046", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx047
	{ "sph_view_x_min_int", 0x000000BC, 12, 0, CSR_RW, 0x000001E0 },
	{ "sph_view_x_max_int", 0x000000BC, 28, 16, CSR_RW, 0x0000059F },
	{ "GFX047", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx048
	{ "sph_dst_width", 0x000000C0, 12, 0, CSR_RW, 0x00000780 },
	{ "GFX048", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx049
	{ "sph_theta_step_0", 0x000000C4, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX049", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx050
	{ "sph_theta_step_1", 0x000000C8, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX050", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx051
	{ "sph_phi_step_0", 0x000000CC, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX051", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx052
	{ "sph_phi_step_1", 0x000000D0, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX052", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx053
	{ "sph_stitch_r_0", 0x000000D4, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX053", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx054
	{ "sph_stitch_r_1", 0x000000D8, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX054", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx055
	{ "sph_r_ratio_adj_01_2s", 0x000000DC, 14, 8, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_02_2s", 0x000000DC, 22, 16, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_03_2s", 0x000000DC, 30, 24, CSR_RW, 0x00000000 },
	{ "GFX055", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx056
	{ "sph_r_ratio_adj_04_2s", 0x000000E0, 6, 0, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_05_2s", 0x000000E0, 14, 8, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_06_2s", 0x000000E0, 22, 16, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_07_2s", 0x000000E0, 30, 24, CSR_RW, 0x00000000 },
	{ "GFX056", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx057
	{ "sph_r_ratio_adj_08_2s", 0x000000E4, 6, 0, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_09_2s", 0x000000E4, 14, 8, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_10_2s", 0x000000E4, 22, 16, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_11_2s", 0x000000E4, 30, 24, CSR_RW, 0x00000000 },
	{ "GFX057", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx058
	{ "sph_r_ratio_adj_12_2s", 0x000000E8, 6, 0, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_13_2s", 0x000000E8, 14, 8, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_14_2s", 0x000000E8, 22, 16, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_15_2s", 0x000000E8, 30, 24, CSR_RW, 0x00000000 },
	{ "GFX058", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx059
	{ "sph_r_ratio_adj_16_2s", 0x000000EC, 6, 0, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_17_2s", 0x000000EC, 14, 8, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_18_2s", 0x000000EC, 22, 16, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_19_2s", 0x000000EC, 30, 24, CSR_RW, 0x00000000 },
	{ "GFX059", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx060
	{ "sph_r_ratio_adj_20_2s", 0x000000F0, 6, 0, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_21_2s", 0x000000F0, 14, 8, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_22_2s", 0x000000F0, 22, 16, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_23_2s", 0x000000F0, 30, 24, CSR_RW, 0x00000000 },
	{ "GFX060", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx061
	{ "sph_r_ratio_adj_24_2s", 0x000000F4, 6, 0, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_25_2s", 0x000000F4, 14, 8, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_26_2s", 0x000000F4, 22, 16, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_27_2s", 0x000000F4, 30, 24, CSR_RW, 0x00000000 },
	{ "GFX061", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx062
	{ "sph_r_ratio_adj_28_2s", 0x000000F8, 6, 0, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_29_2s", 0x000000F8, 14, 8, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_30_2s", 0x000000F8, 22, 16, CSR_RW, 0x00000000 },
	{ "sph_r_ratio_adj_31_2s", 0x000000F8, 30, 24, CSR_RW, 0x00000000 },
	{ "GFX062", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx063
	{ "pol_en", 0x000000FC, 0, 0, CSR_RW, 0x00000000 },
	{ "GFX063", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx064
	{ "pol_r_center", 0x00000100, 16, 0, CSR_RW, 0x00000000 },
	{ "GFX064", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx065
	{ "pol_r_step", 0x00000104, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX065", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx066
	{ "pol_theta_step", 0x00000108, 18, 0, CSR_RW, 0x00000000 },
	{ "GFX066", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx067
	{ "squ_x_strength", 0x0000010C, 6, 0, CSR_RW, 0x00000000 },
	{ "squ_y_strength", 0x0000010C, 14, 8, CSR_RW, 0x00000000 },
	{ "GFX067", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx068
	{ "ldc_strength", 0x00000110, 6, 0, CSR_RW, 0x00000000 },
	{ "ldc_ratio_origin", 0x00000110, 15, 8, CSR_RW, 0x00000040 },
	{ "GFX068", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx068_0
	{ "squ_inv_r", 0x00000114, 20, 0, CSR_RW, 0x00000000 },
	{ "GFX068_0", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_i_0
	{ "ldc_entry_lut_i_0", 0x00000118, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_I_0", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_i_1
	{ "ldc_entry_lut_i_1", 0x0000011C, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_I_1", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_i_2
	{ "ldc_entry_lut_i_2", 0x00000120, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_I_2", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_i_3
	{ "ldc_entry_lut_i_3", 0x00000124, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_I_3", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_i_4
	{ "ldc_entry_lut_i_4", 0x00000128, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_I_4", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_i_5
	{ "ldc_entry_lut_i_5", 0x0000012C, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_I_5", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_i_6
	{ "ldc_entry_lut_i_6", 0x00000130, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_I_6", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_i_7
	{ "ldc_entry_lut_i_7", 0x00000134, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_I_7", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_o_0
	{ "ldc_entry_lut_o_0", 0x00000138, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_O_0", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_o_1
	{ "ldc_entry_lut_o_1", 0x0000013C, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_O_1", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_o_2
	{ "ldc_entry_lut_o_2", 0x00000140, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_O_2", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_o_3
	{ "ldc_entry_lut_o_3", 0x00000144, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_O_3", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_o_4
	{ "ldc_entry_lut_o_4", 0x00000148, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_O_4", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_o_5
	{ "ldc_entry_lut_o_5", 0x0000014C, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_O_5", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_o_6
	{ "ldc_entry_lut_o_6", 0x00000150, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_O_6", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_o_7
	{ "ldc_entry_lut_o_7", 0x00000154, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_LDC_ENTRY_LUT_O_7", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_m_0
	{ "ldc_entry_lut_m_0", 0x00000158, 9, 0, CSR_RW, 0x00000100 },
	{ "ldc_entry_lut_m_1", 0x00000158, 25, 16, CSR_RW, 0x00000100 },
	{ "WORD_LDC_ENTRY_LUT_M_0", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_m_1
	{ "ldc_entry_lut_m_2", 0x0000015C, 9, 0, CSR_RW, 0x00000100 },
	{ "ldc_entry_lut_m_3", 0x0000015C, 25, 16, CSR_RW, 0x00000100 },
	{ "LDC_ENTRY_LUT_M_1", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_m_2
	{ "ldc_entry_lut_m_4", 0x00000160, 9, 0, CSR_RW, 0x00000100 },
	{ "ldc_entry_lut_m_5", 0x00000160, 25, 16, CSR_RW, 0x00000100 },
	{ "LDC_ENTRY_LUT_M_2", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_m_3
	{ "ldc_entry_lut_m_6", 0x00000164, 9, 0, CSR_RW, 0x00000100 },
	{ "ldc_entry_lut_m_7", 0x00000164, 25, 16, CSR_RW, 0x00000100 },
	{ "LDC_ENTRY_LUT_M_3", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ldc_entry_lut_m_4
	{ "ldc_entry_lut_m_8", 0x00000168, 9, 0, CSR_RW, 0x00000100 },
	{ "LDC_ENTRY_LUT_M_4", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx069
	{ "ldc_curvature", 0x0000016C, 15, 0, CSR_RW, 0x00000000 },
	{ "GFX069", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx082
	{ "dst_0_aff_matrix_00_2s", 0x000001A0, 19, 0, CSR_RW, 0x00020000 },
	{ "GFX082", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx083
	{ "dst_0_aff_matrix_01_2s", 0x000001A4, 19, 0, CSR_RW, 0x00000000 },
	{ "GFX083", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx084
	{ "dst_0_aff_matrix_10_2s", 0x000001A8, 19, 0, CSR_RW, 0x00000000 },
	{ "GFX084", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx085
	{ "dst_0_aff_matrix_11_2s", 0x000001AC, 19, 0, CSR_RW, 0x00020000 },
	{ "GFX085", 0x000001AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx086
	{ "dst_0_aff_shift_x_2s", 0x000001B0, 17, 0, CSR_RW, 0x0003C408 },
	{ "GFX086", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx087
	{ "dst_0_aff_shift_y_2s", 0x000001B4, 17, 0, CSR_RW, 0x0003DE48 },
	{ "GFX087", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx088
	{ "dst_1_aff_matrix_00_2s", 0x000001B8, 19, 0, CSR_RW, 0x00020000 },
	{ "GFX088", 0x000001B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx089
	{ "dst_1_aff_matrix_01_2s", 0x000001BC, 19, 0, CSR_RW, 0x00000000 },
	{ "GFX089", 0x000001BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx090
	{ "dst_1_aff_matrix_10_2s", 0x000001C0, 19, 0, CSR_RW, 0x00000000 },
	{ "GFX090", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx091
	{ "dst_1_aff_matrix_11_2s", 0x000001C4, 19, 0, CSR_RW, 0x00020000 },
	{ "GFX091", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx092
	{ "dst_1_aff_shift_x_2s", 0x000001C8, 17, 0, CSR_RW, 0x0003C408 },
	{ "GFX092", 0x000001C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx093
	{ "dst_1_aff_shift_y_2s", 0x000001CC, 17, 0, CSR_RW, 0x0003DE48 },
	{ "GFX093", 0x000001CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_u_0
	{ "src_psp_0_u_x_coeff_2s_l", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_U_0", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_u_1
	{ "src_psp_0_u_x_coeff_2s_h", 0x000001D4, 5, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_U_1", 0x000001D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_u_2
	{ "src_psp_0_u_y_coeff_2s_l", 0x000001D8, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_U_2", 0x000001D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_u_3
	{ "src_psp_0_u_y_coeff_2s_h", 0x000001DC, 5, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_U_3", 0x000001DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_u_4
	{ "src_psp_0_u_offset_2s_l", 0x000001E0, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_U_4", 0x000001E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_u_5
	{ "src_psp_0_u_offset_2s_h", 0x000001E4, 10, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_U_5", 0x000001E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_v_0
	{ "src_psp_0_v_x_coeff_2s_l", 0x000001E8, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_V_0", 0x000001E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_v_1
	{ "src_psp_0_v_x_coeff_2s_h", 0x000001EC, 5, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_V_1", 0x000001EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_v_2
	{ "src_psp_0_v_y_coeff_2s_l", 0x000001F0, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_V_2", 0x000001F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_v_3
	{ "src_psp_0_v_y_coeff_2s_h", 0x000001F4, 5, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_V_3", 0x000001F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_v_4
	{ "src_psp_0_v_offset_2s_l", 0x000001F8, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_V_4", 0x000001F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_v_5
	{ "src_psp_0_v_offset_2s_h", 0x000001FC, 10, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_V_5", 0x000001FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_w_0
	{ "src_psp_0_w_x_coeff_2s", 0x00000200, 22, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_W_0", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_w_1
	{ "src_psp_0_w_y_coeff_2s", 0x00000204, 22, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_W_1", 0x00000204, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_0_w_2
	{ "src_psp_0_w_offset_2s", 0x00000208, 27, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_0_W_2", 0x00000208, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_u_0
	{ "src_psp_1_u_x_coeff_2s_l", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_U_0", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_u_1
	{ "src_psp_1_u_x_coeff_2s_h", 0x00000210, 5, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_U_1", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_u_2
	{ "src_psp_1_u_y_coeff_2s_l", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_U_2", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_u_3
	{ "src_psp_1_u_y_coeff_2s_h", 0x00000218, 5, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_U_3", 0x00000218, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_u_4
	{ "src_psp_1_u_offset_2s_l", 0x0000021C, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_U_4", 0x0000021C, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_u_5
	{ "src_psp_1_u_offset_2s_h", 0x00000220, 10, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_U_5", 0x00000220, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_v_0
	{ "src_psp_1_v_x_coeff_2s_l", 0x00000224, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_V_0", 0x00000224, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_v_1
	{ "src_psp_1_v_x_coeff_2s_h", 0x00000228, 5, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_V_1", 0x00000228, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_v_2
	{ "src_psp_1_v_y_coeff_2s_l", 0x0000022C, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_V_2", 0x0000022C, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_v_3
	{ "src_psp_1_v_y_coeff_2s_h", 0x00000230, 5, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_V_3", 0x00000230, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_v_4
	{ "src_psp_1_v_offset_2s_l", 0x00000234, 31, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_V_4", 0x00000234, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_v_5
	{ "src_psp_1_v_offset_2s_h", 0x00000238, 10, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_V_5", 0x00000238, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_w_0
	{ "src_psp_1_w_x_coeff_2s", 0x0000023C, 22, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_W_0", 0x0000023C, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_w_1
	{ "src_psp_1_w_y_coeff_2s", 0x00000240, 22, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_W_1", 0x00000240, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_psp_1_w_2
	{ "src_psp_1_w_offset_2s", 0x00000244, 27, 0, CSR_RW, 0x00000000 },
	{ "SRC_PSP_1_W_2", 0x00000244, 31, 0, CSR_RW, 0x00000000 },
	// WORD table
	{ "table_en", 0x00000248, 0, 0, CSR_RW, 0x00000001 },
	{ "TABLE", 0x00000248, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx094
	{ "status_x_min_int_2s", 0x0000024C, 13, 0, CSR_RO, 0x00000000 },
	{ "status_x_max_int_2s", 0x0000024C, 29, 16, CSR_RO, 0x00000000 },
	{ "GFX094", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	// WORD gfx095
	{ "status_y_min_int_2s", 0x00000250, 13, 0, CSR_RO, 0x00000000 },
	{ "status_y_max_int_2s", 0x00000250, 29, 16, CSR_RO, 0x00000000 },
	{ "GFX095", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	// WORD gfx096
	{ "efuse_dis_gfx_sph_violation", 0x00000254, 0, 0, CSR_RO, 0x00000000 },
	{ "efuse_dis_gfx_pol_violation", 0x00000254, 8, 8, CSR_RO, 0x00000000 },
	{ "efuse_dis_gfx_squ_violation", 0x00000254, 16, 16, CSR_RO, 0x00000000 },
	{ "efuse_dis_gfx_ldc_violation", 0x00000254, 24, 24, CSR_RO, 0x00000000 },
	{ "GFX096", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	// WORD gfx097
	{ "demo_ldc_en", 0x00000258, 0, 0, CSR_RW, 0x00000000 },
	{ "GFX097", 0x00000258, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx098
	{ "demo_x_min_int", 0x0000025C, 12, 0, CSR_RW, 0x00000000 },
	{ "demo_x_max_int", 0x0000025C, 28, 16, CSR_RW, 0x000003BF },
	{ "GFX098", 0x0000025C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx099
	{ "demo_y_min_int", 0x00000260, 12, 0, CSR_RW, 0x00000000 },
	{ "demo_y_max_int", 0x00000260, 28, 16, CSR_RW, 0x00000437 },
	{ "GFX099", 0x00000260, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx100
	{ "reserved_0", 0x00000264, 31, 0, CSR_RW, 0x00000000 },
	{ "GFX100", 0x00000264, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx101
	{ "reserved_1", 0x00000268, 31, 0, CSR_RW, 0x00000000 },
	{ "GFX101", 0x00000268, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_GFX_H_
