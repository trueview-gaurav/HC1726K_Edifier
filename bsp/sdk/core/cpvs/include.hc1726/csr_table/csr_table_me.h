/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ME_H_
#define CSR_TABLE_ME_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_me[] = {
	// WORD me000
	{ "mode", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "ME000", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD me001
	{ "scene_change", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "ME001", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD me002
	{ "gmv_x", 0x00000008, 9, 0, CSR_RW, 0x00000000 },
	{ "gmv_y", 0x00000008, 25, 16, CSR_RW, 0x00000000 },
	{ "ME002", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD me003
	{ "gmv_cand_valid", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "ME003", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me004
	{ "bottom_left_dist_x", 0x00000010, 3, 0, CSR_RW, 0x00000004 },
	{ "bottom_left_dist_y", 0x00000010, 10, 8, CSR_RW, 0x00000002 },
	{ "bottom_right_dist_x", 0x00000010, 19, 16, CSR_RW, 0x00000004 },
	{ "bottom_right_dist_y", 0x00000010, 26, 24, CSR_RW, 0x00000002 },
	{ "ME004", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD me005
	{ "mode_left_mv_diff_th", 0x00000014, 10, 0, CSR_RW, 0x00000020 },
	{ "ME005", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD me006
	{ "mode_top_left_mv_diff_th", 0x00000018, 10, 0, CSR_RW, 0x00000020 },
	{ "ME006", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD me007
	{ "mode_top_right_mv_diff_th", 0x0000001C, 10, 0, CSR_RW, 0x00000020 },
	{ "ME007", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me008
	{ "search_texture_th", 0x00000020, 15, 0, CSR_RW, 0x00000190 },
	{ "ME008", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD me009
	{ "sw_ix", 0x00000024, 4, 0, CSR_RW, 0x0000001F },
	{ "sw_iy", 0x00000024, 11, 8, CSR_RW, 0x0000000D },
	{ "sw_ix_size", 0x00000024, 21, 16, CSR_RW, 0x0000003F },
	{ "sw_iy_size", 0x00000024, 28, 24, CSR_RW, 0x0000001B },
	{ "ME009", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD me010
	{ "sw_center_mode", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "sw_center_weight", 0x00000028, 10, 8, CSR_RW, 0x00000001 },
	{ "ME010", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD me011
	{ "sw_center_x_sw", 0x0000002C, 9, 0, CSR_RW, 0x00000000 },
	{ "sw_center_y_sw", 0x0000002C, 25, 16, CSR_RW, 0x00000000 },
	{ "ME011", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me012
	{ "ime_penalty_gain_x_sel", 0x00000030, 1, 0, CSR_RW, 0x00000003 },
	{ "ime_penalty_gain_y_sel", 0x00000030, 9, 8, CSR_RW, 0x00000003 },
	{ "ime_penalty_bound_x_ini", 0x00000030, 23, 16, CSR_RW, 0x00000020 },
	{ "ime_penalty_bound_y_ini", 0x00000030, 31, 24, CSR_RW, 0x00000020 },
	{ "ME012", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD me013
	{ "matching_weight", 0x00000034, 1, 0, CSR_RW, 0x00000003 },
	{ "range_weight", 0x00000034, 13, 8, CSR_RW, 0x00000001 },
	{ "singularity_weight", 0x00000034, 22, 16, CSR_RW, 0x0000000A },
	{ "ME013", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD me014
	{ "m_cost_quarter_gain", 0x00000038, 5, 0, CSR_RW, 0x00000020 },
	{ "m_cost_half_gain", 0x00000038, 13, 8, CSR_RW, 0x00000023 },
	{ "m_cost_frac_offset", 0x00000038, 25, 16, CSR_RW, 0x00000000 },
	{ "ME014", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD me015
	{ "texture_gain_low_th", 0x0000003C, 12, 0, CSR_RW, 0x0000001E },
	{ "texture_gain_high_th", 0x0000003C, 28, 16, CSR_RW, 0x0000012C },
	{ "ME015", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me016
	{ "texture_gain_low", 0x00000040, 5, 0, CSR_RW, 0x0000000C },
	{ "texture_gain_high", 0x00000040, 21, 16, CSR_RW, 0x00000020 },
	{ "ME016", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD me017
	{ "range_min_x_th", 0x00000044, 9, 0, CSR_RW, 0x00000000 },
	{ "range_max_x_th", 0x00000044, 25, 16, CSR_RW, 0x00000020 },
	{ "ME017", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD me018
	{ "singularity_min_th", 0x00000048, 11, 0, CSR_RW, 0x00000002 },
	{ "singularity_max_th", 0x00000048, 27, 16, CSR_RW, 0x00000100 },
	{ "ME018", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD me019
	{ "non_zero_mv_cost_offset", 0x0000004C, 9, 0, CSR_RW, 0x00000081 },
	{ "singularity_type_bias_en", 0x0000004C, 16, 16, CSR_RW, 0x00000001 },
	{ "singularity_type_wei_sp", 0x0000004C, 26, 24, CSR_RW, 0x00000003 },
	{ "ME019", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me020
	{ "spatial_cost_offset", 0x00000050, 9, 0, CSR_RW, 0x00000000 },
	{ "temporal_cost_offset", 0x00000050, 25, 16, CSR_RW, 0x00000015 },
	{ "ME020", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD me021
	{ "search_weak_cost_offset", 0x00000054, 9, 0, CSR_RW, 0x0000012D },
	{ "search_cost_offset", 0x00000054, 25, 16, CSR_RW, 0x00000033 },
	{ "ME021", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD me022
	{ "refine_cost_offset", 0x00000058, 9, 0, CSR_RW, 0x0000005B },
	{ "gmv_cost_offset", 0x00000058, 25, 16, CSR_RW, 0x00000000 },
	{ "ME022", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD me023
	{ "valid_true_mv_th", 0x0000005C, 15, 0, CSR_RW, 0x0000FFFF },
	{ "valid_true_mv_cost_mode", 0x0000005C, 16, 16, CSR_RW, 0x00000000 },
	{ "ME023", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me024
	{ "mvr_left_extend_dist", 0x00000060, 3, 0, CSR_RW, 0x00000004 },
	{ "mvr_right_extend_dist", 0x00000060, 19, 16, CSR_RW, 0x00000004 },
	{ "ME024", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD me025
	{ "texture_gain_slope", 0x00000064, 7, 0, CSR_RW, 0x000000BF },
	{ "ME025", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD me026
	{ "range_min_y_th", 0x00000068, 9, 0, CSR_RW, 0x00000000 },
	{ "range_max_y_th", 0x00000068, 25, 16, CSR_RW, 0x00000020 },
	{ "ME026", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD me027
	{ "tr_cost_en", 0x0000006C, 0, 0, CSR_RW, 0x00000001 },
	{ "tr_texture_crop", 0x0000006C, 17, 8, CSR_RW, 0x00000000 },
	{ "tr_base_min", 0x0000006C, 31, 30, CSR_RW, 0x00000001 },
	{ "ME027", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me028
	{ "tr_base_max", 0x00000070, 3, 0, CSR_RW, 0x00000008 },
	{ "tr_base_rto", 0x00000070, 10, 8, CSR_RW, 0x00000002 },
	{ "tr_non_zero_mv_cost_offset_ratio", 0x00000070, 21, 16, CSR_RW, 0x00000004 },
	{ "tr_spatial_cost_offset_ratio", 0x00000070, 29, 24, CSR_RW, 0x00000000 },
	{ "ME028", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD me029
	{ "mv_roi_0_en", 0x00000074, 0, 0, CSR_RW, 0x00000000 },
	{ "mv_hist_only_texture_en", 0x00000074, 8, 8, CSR_RW, 0x00000000 },
	{ "mv_hist_texture_th", 0x00000074, 25, 16, CSR_RW, 0x00000200 },
	{ "ME029", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD me030
	{ "mv_roi_0_clear", 0x00000078, 0, 0, CSR_RW, 0x00000000 },
	{ "ME030", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD me031
	{ "mv_roi_0_sx", 0x0000007C, 15, 0, CSR_RW, 0x00000000 },
	{ "mv_roi_0_sy", 0x0000007C, 31, 16, CSR_RW, 0x00000000 },
	{ "ME031", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me032
	{ "mv_roi_0_ex", 0x00000080, 15, 0, CSR_RW, 0x00000000 },
	{ "mv_roi_0_ey", 0x00000080, 31, 16, CSR_RW, 0x00000000 },
	{ "ME032", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD me033
	{ "mv_roi_0_x_accuracy", 0x00000084, 2, 0, CSR_RW, 0x00000000 },
	{ "mv_roi_0_y_accuracy", 0x00000084, 18, 16, CSR_RW, 0x00000000 },
	{ "ME033", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD me034
	{ "mv_roi_0_step", 0x00000088, 2, 0, CSR_RW, 0x00000003 },
	{ "ME034", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD me035
	{ "mv_roi_0_hist_0", 0x0000008C, 31, 0, CSR_RO, 0x00000000 },
	{ "ME035", 0x0000008C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me036
	{ "mv_roi_0_hist_1", 0x00000090, 31, 0, CSR_RO, 0x00000000 },
	{ "ME036", 0x00000090, 31, 0, CSR_RO, 0x00000000 },
	// WORD me037
	{ "mv_roi_0_hist_2", 0x00000094, 31, 0, CSR_RO, 0x00000000 },
	{ "ME037", 0x00000094, 31, 0, CSR_RO, 0x00000000 },
	// WORD me038
	{ "mv_roi_0_hist_3", 0x00000098, 31, 0, CSR_RO, 0x00000000 },
	{ "ME038", 0x00000098, 31, 0, CSR_RO, 0x00000000 },
	// WORD me039
	{ "mv_roi_0_hist_4", 0x0000009C, 31, 0, CSR_RO, 0x00000000 },
	{ "ME039", 0x0000009C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me040
	{ "mv_roi_0_hist_5", 0x000000A0, 31, 0, CSR_RO, 0x00000000 },
	{ "ME040", 0x000000A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me041
	{ "mv_roi_0_hist_6", 0x000000A4, 31, 0, CSR_RO, 0x00000000 },
	{ "ME041", 0x000000A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me042
	{ "mv_roi_0_hist_7", 0x000000A8, 31, 0, CSR_RO, 0x00000000 },
	{ "ME042", 0x000000A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me043
	{ "mv_roi_0_hist_8", 0x000000AC, 31, 0, CSR_RO, 0x00000000 },
	{ "ME043", 0x000000AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me044
	{ "mv_roi_0_hist_9", 0x000000B0, 31, 0, CSR_RO, 0x00000000 },
	{ "ME044", 0x000000B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me045
	{ "mv_roi_0_hist_10", 0x000000B4, 31, 0, CSR_RO, 0x00000000 },
	{ "ME045", 0x000000B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me046
	{ "mv_roi_0_hist_11", 0x000000B8, 31, 0, CSR_RO, 0x00000000 },
	{ "ME046", 0x000000B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me047
	{ "mv_roi_0_hist_12", 0x000000BC, 31, 0, CSR_RO, 0x00000000 },
	{ "ME047", 0x000000BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me048
	{ "mv_roi_0_hist_13", 0x000000C0, 31, 0, CSR_RO, 0x00000000 },
	{ "ME048", 0x000000C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me049
	{ "mv_roi_0_hist_14", 0x000000C4, 31, 0, CSR_RO, 0x00000000 },
	{ "ME049", 0x000000C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me050
	{ "mv_roi_0_hist_15", 0x000000C8, 31, 0, CSR_RO, 0x00000000 },
	{ "ME050", 0x000000C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me051
	{ "mv_roi_0_hist_16", 0x000000CC, 31, 0, CSR_RO, 0x00000000 },
	{ "ME051", 0x000000CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me052
	{ "mv_roi_0_hist_17", 0x000000D0, 31, 0, CSR_RO, 0x00000000 },
	{ "ME052", 0x000000D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me053
	{ "mv_roi_0_hist_18", 0x000000D4, 31, 0, CSR_RO, 0x00000000 },
	{ "ME053", 0x000000D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me054
	{ "mv_roi_0_hist_19", 0x000000D8, 31, 0, CSR_RO, 0x00000000 },
	{ "ME054", 0x000000D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me055
	{ "mv_roi_0_hist_20", 0x000000DC, 31, 0, CSR_RO, 0x00000000 },
	{ "ME055", 0x000000DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me056
	{ "mv_roi_0_hist_21", 0x000000E0, 31, 0, CSR_RO, 0x00000000 },
	{ "ME056", 0x000000E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me057
	{ "mv_roi_0_hist_22", 0x000000E4, 31, 0, CSR_RO, 0x00000000 },
	{ "ME057", 0x000000E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me058
	{ "mv_roi_0_hist_23", 0x000000E8, 31, 0, CSR_RO, 0x00000000 },
	{ "ME058", 0x000000E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me059
	{ "mv_roi_0_hist_24", 0x000000EC, 31, 0, CSR_RO, 0x00000000 },
	{ "ME059", 0x000000EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me060
	{ "mv_roi_0_hist_25", 0x000000F0, 31, 0, CSR_RO, 0x00000000 },
	{ "ME060", 0x000000F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me061
	{ "mv_roi_0_hist_26", 0x000000F4, 31, 0, CSR_RO, 0x00000000 },
	{ "ME061", 0x000000F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me062
	{ "mv_roi_0_hist_27", 0x000000F8, 31, 0, CSR_RO, 0x00000000 },
	{ "ME062", 0x000000F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me063
	{ "mv_roi_0_hist_28", 0x000000FC, 31, 0, CSR_RO, 0x00000000 },
	{ "ME063", 0x000000FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me064
	{ "mv_roi_0_hist_29", 0x00000100, 31, 0, CSR_RO, 0x00000000 },
	{ "ME064", 0x00000100, 31, 0, CSR_RO, 0x00000000 },
	// WORD me065
	{ "mv_roi_0_hist_30", 0x00000104, 31, 0, CSR_RO, 0x00000000 },
	{ "ME065", 0x00000104, 31, 0, CSR_RO, 0x00000000 },
	// WORD me066
	{ "mv_roi_0_hist_31", 0x00000108, 31, 0, CSR_RO, 0x00000000 },
	{ "ME066", 0x00000108, 31, 0, CSR_RO, 0x00000000 },
	// WORD me067
	{ "mv_roi_0_valid_cnt", 0x0000010C, 19, 0, CSR_RO, 0x00000000 },
	{ "ME067", 0x0000010C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me068
	{ "texture_roi_0_blk_num", 0x00000110, 19, 0, CSR_RO, 0x00000000 },
	{ "ME068", 0x00000110, 31, 0, CSR_RO, 0x00000000 },
	// WORD me069
	{ "tr_temporal_cost_offset_ratio", 0x00000114, 5, 0, CSR_RW, 0x00000003 },
	{ "tr_search_cost_offset_ratio", 0x00000114, 13, 8, CSR_RW, 0x00000028 },
	{ "tr_refine_cost_offset_ratio", 0x00000114, 21, 16, CSR_RW, 0x0000001E },
	{ "tr_gmv_cost_offset_ratio", 0x00000114, 29, 24, CSR_RW, 0x0000000A },
	{ "ME069", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD me070
	{ "strip_motion_0_en", 0x00000118, 0, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_0_mode", 0x00000118, 8, 8, CSR_RW, 0x00000000 },
	{ "strip_motion_0_th", 0x00000118, 23, 16, CSR_RW, 0x00000000 },
	{ "strip_motion_0_qs", 0x00000118, 26, 24, CSR_RW, 0x00000000 },
	{ "ME070", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD me071
	{ "strip_motion_0_sx", 0x0000011C, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_0_sy", 0x0000011C, 31, 16, CSR_RW, 0x00000000 },
	{ "ME071", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me072
	{ "strip_motion_0_ex", 0x00000120, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_0_ey", 0x00000120, 31, 16, CSR_RW, 0x00000000 },
	{ "ME072", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD me073
	{ "strip_motion_1_en", 0x00000124, 0, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_1_mode", 0x00000124, 8, 8, CSR_RW, 0x00000000 },
	{ "strip_motion_1_th", 0x00000124, 23, 16, CSR_RW, 0x00000000 },
	{ "strip_motion_1_qs", 0x00000124, 26, 24, CSR_RW, 0x00000000 },
	{ "ME073", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD me074
	{ "strip_motion_1_sx", 0x00000128, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_1_sy", 0x00000128, 31, 16, CSR_RW, 0x00000000 },
	{ "ME074", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD me075
	{ "strip_motion_1_ex", 0x0000012C, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_1_ey", 0x0000012C, 31, 16, CSR_RW, 0x00000000 },
	{ "ME075", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me076
	{ "strip_motion_2_en", 0x00000130, 0, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_2_mode", 0x00000130, 8, 8, CSR_RW, 0x00000000 },
	{ "strip_motion_2_th", 0x00000130, 23, 16, CSR_RW, 0x00000000 },
	{ "strip_motion_2_qs", 0x00000130, 26, 24, CSR_RW, 0x00000000 },
	{ "ME076", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD me077
	{ "strip_motion_2_sx", 0x00000134, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_2_sy", 0x00000134, 31, 16, CSR_RW, 0x00000000 },
	{ "ME077", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD me078
	{ "strip_motion_2_ex", 0x00000138, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_2_ey", 0x00000138, 31, 16, CSR_RW, 0x00000000 },
	{ "ME078", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD me079
	{ "strip_motion_3_en", 0x0000013C, 0, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_3_mode", 0x0000013C, 8, 8, CSR_RW, 0x00000000 },
	{ "strip_motion_3_th", 0x0000013C, 23, 16, CSR_RW, 0x00000000 },
	{ "strip_motion_3_qs", 0x0000013C, 26, 24, CSR_RW, 0x00000000 },
	{ "ME079", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me080
	{ "strip_motion_3_sx", 0x00000140, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_3_sy", 0x00000140, 31, 16, CSR_RW, 0x00000000 },
	{ "ME080", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD me081
	{ "strip_motion_3_ex", 0x00000144, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_3_ey", 0x00000144, 31, 16, CSR_RW, 0x00000000 },
	{ "ME081", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD me082
	{ "strip_motion_4_en", 0x00000148, 0, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_4_mode", 0x00000148, 8, 8, CSR_RW, 0x00000000 },
	{ "strip_motion_4_th", 0x00000148, 23, 16, CSR_RW, 0x00000000 },
	{ "strip_motion_4_qs", 0x00000148, 26, 24, CSR_RW, 0x00000000 },
	{ "ME082", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD me083
	{ "strip_motion_4_sx", 0x0000014C, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_4_sy", 0x0000014C, 31, 16, CSR_RW, 0x00000000 },
	{ "ME083", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me084
	{ "strip_motion_4_ex", 0x00000150, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_4_ey", 0x00000150, 31, 16, CSR_RW, 0x00000000 },
	{ "ME084", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD me085
	{ "strip_motion_5_en", 0x00000154, 0, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_5_mode", 0x00000154, 8, 8, CSR_RW, 0x00000000 },
	{ "strip_motion_5_th", 0x00000154, 23, 16, CSR_RW, 0x00000000 },
	{ "strip_motion_5_qs", 0x00000154, 26, 24, CSR_RW, 0x00000000 },
	{ "ME085", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD me086
	{ "strip_motion_5_sx", 0x00000158, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_5_sy", 0x00000158, 31, 16, CSR_RW, 0x00000000 },
	{ "ME086", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD me087
	{ "strip_motion_5_ex", 0x0000015C, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_5_ey", 0x0000015C, 31, 16, CSR_RW, 0x00000000 },
	{ "ME087", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me088
	{ "strip_motion_6_en", 0x00000160, 0, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_6_mode", 0x00000160, 8, 8, CSR_RW, 0x00000000 },
	{ "strip_motion_6_th", 0x00000160, 23, 16, CSR_RW, 0x00000000 },
	{ "strip_motion_6_qs", 0x00000160, 26, 24, CSR_RW, 0x00000000 },
	{ "ME088", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD me089
	{ "strip_motion_6_sx", 0x00000164, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_6_sy", 0x00000164, 31, 16, CSR_RW, 0x00000000 },
	{ "ME089", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD me090
	{ "strip_motion_6_ex", 0x00000168, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_6_ey", 0x00000168, 31, 16, CSR_RW, 0x00000000 },
	{ "ME090", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD me091
	{ "strip_motion_7_en", 0x0000016C, 0, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_7_mode", 0x0000016C, 8, 8, CSR_RW, 0x00000000 },
	{ "strip_motion_7_th", 0x0000016C, 23, 16, CSR_RW, 0x00000000 },
	{ "strip_motion_7_qs", 0x0000016C, 26, 24, CSR_RW, 0x00000000 },
	{ "ME091", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me092
	{ "strip_motion_7_sx", 0x00000170, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_7_sy", 0x00000170, 31, 16, CSR_RW, 0x00000000 },
	{ "ME092", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD me093
	{ "strip_motion_7_ex", 0x00000174, 15, 0, CSR_RW, 0x00000000 },
	{ "strip_motion_7_ey", 0x00000174, 31, 16, CSR_RW, 0x00000000 },
	{ "ME093", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD me094
	{ "strip_motion_0_index", 0x00000178, 11, 0, CSR_RO, 0x00000000 },
	{ "strip_motion_1_index", 0x00000178, 27, 16, CSR_RO, 0x00000000 },
	{ "ME094", 0x00000178, 31, 0, CSR_RO, 0x00000000 },
	// WORD me095
	{ "strip_motion_2_index", 0x0000017C, 11, 0, CSR_RO, 0x00000000 },
	{ "strip_motion_3_index", 0x0000017C, 27, 16, CSR_RO, 0x00000000 },
	{ "ME095", 0x0000017C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me096
	{ "strip_motion_4_index", 0x00000180, 11, 0, CSR_RO, 0x00000000 },
	{ "strip_motion_5_index", 0x00000180, 27, 16, CSR_RO, 0x00000000 },
	{ "ME096", 0x00000180, 31, 0, CSR_RO, 0x00000000 },
	// WORD me097
	{ "strip_motion_6_index", 0x00000184, 11, 0, CSR_RO, 0x00000000 },
	{ "strip_motion_7_index", 0x00000184, 27, 16, CSR_RO, 0x00000000 },
	{ "ME097", 0x00000184, 31, 0, CSR_RO, 0x00000000 },
	// WORD me098
	{ "tr_r_cost_max_ratio", 0x00000188, 4, 0, CSR_RW, 0x00000004 },
	{ "tr_s_cost_max_ratio", 0x00000188, 12, 8, CSR_RW, 0x0000000C },
	{ "tr_range_ratio", 0x00000188, 19, 16, CSR_RW, 0x00000004 },
	{ "tr_singularity_ratio", 0x00000188, 27, 24, CSR_RW, 0x00000005 },
	{ "ME098", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD me099
	{ "qualification_matching_level_round", 0x0000018C, 3, 0, CSR_RW, 0x00000006 },
	{ "qualification_aim_mode", 0x0000018C, 8, 8, CSR_RW, 0x00000001 },
	{ "qualification_ignore_gmv", 0x0000018C, 16, 16, CSR_RW, 0x00000000 },
	{ "qualification_mv_coring", 0x0000018C, 26, 24, CSR_RW, 0x00000004 },
	{ "ME099", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me100
	{ "tone_curve_0", 0x00000190, 9, 0, CSR_RW, 0x00000000 },
	{ "tone_curve_1", 0x00000190, 25, 16, CSR_RW, 0x00000020 },
	{ "ME100", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD me101
	{ "tone_curve_2", 0x00000194, 9, 0, CSR_RW, 0x00000040 },
	{ "tone_curve_3", 0x00000194, 25, 16, CSR_RW, 0x00000060 },
	{ "ME101", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD me102
	{ "tone_curve_4", 0x00000198, 9, 0, CSR_RW, 0x00000080 },
	{ "tone_curve_5", 0x00000198, 25, 16, CSR_RW, 0x000000A0 },
	{ "ME102", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	// WORD me103
	{ "tone_curve_6", 0x0000019C, 9, 0, CSR_RW, 0x000000C0 },
	{ "tone_curve_7", 0x0000019C, 25, 16, CSR_RW, 0x000000E0 },
	{ "ME103", 0x0000019C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me104
	{ "tone_curve_8", 0x000001A0, 9, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_9", 0x000001A0, 25, 16, CSR_RW, 0x00000120 },
	{ "ME104", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD me105
	{ "tone_curve_10", 0x000001A4, 9, 0, CSR_RW, 0x00000140 },
	{ "tone_curve_11", 0x000001A4, 25, 16, CSR_RW, 0x00000160 },
	{ "ME105", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD me106
	{ "tone_curve_12", 0x000001A8, 9, 0, CSR_RW, 0x00000180 },
	{ "tone_curve_13", 0x000001A8, 25, 16, CSR_RW, 0x000001A0 },
	{ "ME106", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD me107
	{ "tone_curve_14", 0x000001AC, 9, 0, CSR_RW, 0x000001C0 },
	{ "tone_curve_15", 0x000001AC, 25, 16, CSR_RW, 0x000001E0 },
	{ "ME107", 0x000001AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD me108
	{ "tone_curve_16", 0x000001B0, 9, 0, CSR_RW, 0x00000200 },
	{ "tone_curve_17", 0x000001B0, 25, 16, CSR_RW, 0x00000220 },
	{ "ME108", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD me109
	{ "tone_curve_18", 0x000001B4, 9, 0, CSR_RW, 0x00000240 },
	{ "tone_curve_19", 0x000001B4, 25, 16, CSR_RW, 0x00000260 },
	{ "ME109", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD me110
	{ "tone_curve_20", 0x000001B8, 9, 0, CSR_RW, 0x00000280 },
	{ "tone_curve_21", 0x000001B8, 25, 16, CSR_RW, 0x000002A0 },
	{ "ME110", 0x000001B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD me111
	{ "tone_curve_22", 0x000001BC, 9, 0, CSR_RW, 0x000002C0 },
	{ "tone_curve_23", 0x000001BC, 25, 16, CSR_RW, 0x000002E0 },
	{ "ME111", 0x000001BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD me112
	{ "tone_curve_24", 0x000001C0, 9, 0, CSR_RW, 0x00000300 },
	{ "tone_curve_25", 0x000001C0, 25, 16, CSR_RW, 0x00000320 },
	{ "ME112", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD me113
	{ "tone_curve_26", 0x000001C4, 9, 0, CSR_RW, 0x00000340 },
	{ "tone_curve_27", 0x000001C4, 25, 16, CSR_RW, 0x00000360 },
	{ "ME113", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD me114
	{ "tone_curve_28", 0x000001C8, 9, 0, CSR_RW, 0x00000380 },
	{ "tone_curve_29", 0x000001C8, 25, 16, CSR_RW, 0x000003A0 },
	{ "ME114", 0x000001C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD me115
	{ "tone_curve_30", 0x000001CC, 9, 0, CSR_RW, 0x000003C0 },
	{ "tone_curve_31", 0x000001CC, 25, 16, CSR_RW, 0x000003E0 },
	{ "ME115", 0x000001CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD me116
	{ "tone_curve_32", 0x000001D0, 10, 0, CSR_RW, 0x000003FD },
	{ "ME116", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD me124
	{ "y_avg_roi_0_en", 0x000001F0, 0, 0, CSR_RW, 0x00000000 },
	{ "ME124", 0x000001F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD me125
	{ "y_avg_roi_0_clear", 0x000001F4, 0, 0, CSR_RW, 0x00000000 },
	{ "ME125", 0x000001F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD me126
	{ "y_avg_roi_0_sx", 0x000001F8, 15, 0, CSR_RW, 0x00000000 },
	{ "y_avg_roi_0_sy", 0x000001F8, 31, 16, CSR_RW, 0x00000000 },
	{ "ME126", 0x000001F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD me127
	{ "y_avg_roi_0_ex", 0x000001FC, 15, 0, CSR_RW, 0x00000000 },
	{ "y_avg_roi_0_ey", 0x000001FC, 31, 16, CSR_RW, 0x00000000 },
	{ "ME127", 0x000001FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD me128
	{ "y_avg_roi_0_total_pix_cnt", 0x00000200, 23, 0, CSR_RW, 0x00000000 },
	{ "ME128", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	// WORD me129
	{ "y_avg_roi_0_before_cte", 0x00000204, 9, 0, CSR_RO, 0x00000000 },
	{ "y_avg_roi_0_after_cte", 0x00000204, 25, 16, CSR_RO, 0x00000000 },
	{ "ME129", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	// WORD me130
	{ "texture_roi_0_clear", 0x00000208, 0, 0, CSR_RW, 0x00000000 },
	{ "ME130", 0x00000208, 31, 0, CSR_RW, 0x00000000 },
	// WORD me131
	{ "texture_roi_0_sx", 0x0000020C, 15, 0, CSR_RW, 0x00000000 },
	{ "texture_roi_0_sy", 0x0000020C, 31, 16, CSR_RW, 0x00000000 },
	{ "ME131", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me132
	{ "texture_roi_0_ex", 0x00000210, 15, 0, CSR_RW, 0x00000000 },
	{ "texture_roi_0_ey", 0x00000210, 31, 16, CSR_RW, 0x00000000 },
	{ "ME132", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	// WORD me133
	{ "texture_roi_0_hor", 0x00000214, 25, 0, CSR_RO, 0x00000000 },
	{ "ME133", 0x00000214, 31, 0, CSR_RO, 0x00000000 },
	// WORD me134
	{ "texture_roi_0_ver", 0x00000218, 25, 0, CSR_RO, 0x00000000 },
	{ "ME134", 0x00000218, 31, 0, CSR_RO, 0x00000000 },
	// WORD me135
	{ "texture_roi_0_hor_ver", 0x0000021C, 26, 0, CSR_RO, 0x00000000 },
	{ "ME135", 0x0000021C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me136
	{ "texture_roi_0_en", 0x00000220, 0, 0, CSR_RW, 0x00000000 },
	{ "ME136", 0x00000220, 31, 0, CSR_RW, 0x00000000 },
	// WORD me139
	{ "fg_y_roi_0_en", 0x0000022C, 0, 0, CSR_RW, 0x00000000 },
	{ "ME139", 0x0000022C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me140
	{ "fg_y_roi_0_clear", 0x00000230, 0, 0, CSR_RW, 0x00000000 },
	{ "ME140", 0x00000230, 31, 0, CSR_RW, 0x00000000 },
	// WORD me141
	{ "fg_y_roi_0_sx", 0x00000234, 15, 0, CSR_RW, 0x00000000 },
	{ "fg_y_roi_0_sy", 0x00000234, 31, 16, CSR_RW, 0x00000000 },
	{ "ME141", 0x00000234, 31, 0, CSR_RW, 0x00000000 },
	// WORD me142
	{ "fg_y_roi_0_ex", 0x00000238, 15, 0, CSR_RW, 0x00000000 },
	{ "fg_y_roi_0_ey", 0x00000238, 31, 16, CSR_RW, 0x00000000 },
	{ "ME142", 0x00000238, 31, 0, CSR_RW, 0x00000000 },
	// WORD me143
	{ "fg_y_roi_0_soft_clip_slope", 0x0000023C, 7, 0, CSR_RW, 0x00000020 },
	{ "fg_y_roi_0_soft_clip_th", 0x0000023C, 23, 16, CSR_RW, 0x00000000 },
	{ "ME143", 0x0000023C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me144
	{ "fg_y_roi_0_gmv_x", 0x00000240, 9, 0, CSR_RW, 0x00000000 },
	{ "fg_y_roi_0_gmv_y", 0x00000240, 25, 16, CSR_RW, 0x00000000 },
	{ "ME144", 0x00000240, 31, 0, CSR_RW, 0x00000000 },
	// WORD me145
	{ "fg_y_roi_0_conf", 0x00000244, 21, 0, CSR_RO, 0x00000000 },
	{ "ME145", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	// WORD me146
	{ "fg_y_roi_0_pix_sum", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	{ "ME146", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	// WORD me147
	{ "fg_y_roi_0_hist_0", 0x0000024C, 17, 0, CSR_RO, 0x00000000 },
	{ "ME147", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me148
	{ "fg_y_roi_0_hist_1", 0x00000250, 17, 0, CSR_RO, 0x00000000 },
	{ "ME148", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	// WORD me149
	{ "fg_y_roi_0_hist_2", 0x00000254, 17, 0, CSR_RO, 0x00000000 },
	{ "ME149", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	// WORD me150
	{ "fg_y_roi_0_hist_3", 0x00000258, 17, 0, CSR_RO, 0x00000000 },
	{ "ME150", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	// WORD me151
	{ "fg_y_roi_0_hist_4", 0x0000025C, 17, 0, CSR_RO, 0x00000000 },
	{ "ME151", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me152
	{ "fg_y_roi_0_hist_5", 0x00000260, 17, 0, CSR_RO, 0x00000000 },
	{ "ME152", 0x00000260, 31, 0, CSR_RO, 0x00000000 },
	// WORD me153
	{ "fg_y_roi_0_hist_6", 0x00000264, 17, 0, CSR_RO, 0x00000000 },
	{ "ME153", 0x00000264, 31, 0, CSR_RO, 0x00000000 },
	// WORD me154
	{ "fg_y_roi_0_hist_7", 0x00000268, 17, 0, CSR_RO, 0x00000000 },
	{ "ME154", 0x00000268, 31, 0, CSR_RO, 0x00000000 },
	// WORD me155
	{ "fg_y_roi_0_hist_8", 0x0000026C, 17, 0, CSR_RO, 0x00000000 },
	{ "ME155", 0x0000026C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me156
	{ "fg_y_roi_0_hist_9", 0x00000270, 17, 0, CSR_RO, 0x00000000 },
	{ "ME156", 0x00000270, 31, 0, CSR_RO, 0x00000000 },
	// WORD me157
	{ "fg_y_roi_0_hist_10", 0x00000274, 17, 0, CSR_RO, 0x00000000 },
	{ "ME157", 0x00000274, 31, 0, CSR_RO, 0x00000000 },
	// WORD me158
	{ "fg_y_roi_0_hist_11", 0x00000278, 17, 0, CSR_RO, 0x00000000 },
	{ "ME158", 0x00000278, 31, 0, CSR_RO, 0x00000000 },
	// WORD me159
	{ "fg_y_roi_0_hist_12", 0x0000027C, 17, 0, CSR_RO, 0x00000000 },
	{ "ME159", 0x0000027C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me160
	{ "fg_y_roi_0_hist_13", 0x00000280, 17, 0, CSR_RO, 0x00000000 },
	{ "ME160", 0x00000280, 31, 0, CSR_RO, 0x00000000 },
	// WORD me161
	{ "fg_y_roi_0_hist_14", 0x00000284, 17, 0, CSR_RO, 0x00000000 },
	{ "ME161", 0x00000284, 31, 0, CSR_RO, 0x00000000 },
	// WORD me162
	{ "fg_y_roi_0_hist_15", 0x00000288, 17, 0, CSR_RO, 0x00000000 },
	{ "ME162", 0x00000288, 31, 0, CSR_RO, 0x00000000 },
	// WORD me163
	{ "fg_y_roi_0_hist_16", 0x0000028C, 17, 0, CSR_RO, 0x00000000 },
	{ "ME163", 0x0000028C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me164
	{ "fg_y_roi_0_hist_17", 0x00000290, 17, 0, CSR_RO, 0x00000000 },
	{ "ME164", 0x00000290, 31, 0, CSR_RO, 0x00000000 },
	// WORD me165
	{ "fg_y_roi_0_hist_18", 0x00000294, 17, 0, CSR_RO, 0x00000000 },
	{ "ME165", 0x00000294, 31, 0, CSR_RO, 0x00000000 },
	// WORD me166
	{ "fg_y_roi_0_hist_19", 0x00000298, 17, 0, CSR_RO, 0x00000000 },
	{ "ME166", 0x00000298, 31, 0, CSR_RO, 0x00000000 },
	// WORD me167
	{ "fg_y_roi_0_hist_20", 0x0000029C, 17, 0, CSR_RO, 0x00000000 },
	{ "ME167", 0x0000029C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me168
	{ "fg_y_roi_0_hist_21", 0x000002A0, 17, 0, CSR_RO, 0x00000000 },
	{ "ME168", 0x000002A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me169
	{ "fg_y_roi_0_hist_22", 0x000002A4, 17, 0, CSR_RO, 0x00000000 },
	{ "ME169", 0x000002A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me170
	{ "fg_y_roi_0_hist_23", 0x000002A8, 17, 0, CSR_RO, 0x00000000 },
	{ "ME170", 0x000002A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me171
	{ "fg_y_roi_0_hist_24", 0x000002AC, 17, 0, CSR_RO, 0x00000000 },
	{ "ME171", 0x000002AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me172
	{ "fg_y_roi_0_hist_25", 0x000002B0, 17, 0, CSR_RO, 0x00000000 },
	{ "ME172", 0x000002B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me173
	{ "fg_y_roi_0_hist_26", 0x000002B4, 17, 0, CSR_RO, 0x00000000 },
	{ "ME173", 0x000002B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me174
	{ "fg_y_roi_0_hist_27", 0x000002B8, 17, 0, CSR_RO, 0x00000000 },
	{ "ME174", 0x000002B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me175
	{ "fg_y_roi_0_hist_28", 0x000002BC, 17, 0, CSR_RO, 0x00000000 },
	{ "ME175", 0x000002BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me176
	{ "fg_y_roi_0_hist_29", 0x000002C0, 17, 0, CSR_RO, 0x00000000 },
	{ "ME176", 0x000002C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me177
	{ "fg_y_roi_0_hist_30", 0x000002C4, 17, 0, CSR_RO, 0x00000000 },
	{ "ME177", 0x000002C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me178
	{ "fg_y_roi_0_hist_31", 0x000002C8, 17, 0, CSR_RO, 0x00000000 },
	{ "ME178", 0x000002C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me179
	{ "fg_y_roi_0_hist_32", 0x000002CC, 17, 0, CSR_RO, 0x00000000 },
	{ "ME179", 0x000002CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me180
	{ "fg_texture_roi_0_clear", 0x000002D0, 0, 0, CSR_RW, 0x00000000 },
	{ "ME180", 0x000002D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD me181
	{ "fg_texture_roi_0_sx", 0x000002D4, 15, 0, CSR_RW, 0x00000000 },
	{ "fg_texture_roi_0_sy", 0x000002D4, 31, 16, CSR_RW, 0x00000000 },
	{ "ME181", 0x000002D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD me182
	{ "fg_texture_roi_0_ex", 0x000002D8, 15, 0, CSR_RW, 0x00000000 },
	{ "fg_texture_roi_0_ey", 0x000002D8, 31, 16, CSR_RW, 0x00000000 },
	{ "ME182", 0x000002D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD me183
	{ "fg_texture_roi_0_soft_clip_slope", 0x000002DC, 7, 0, CSR_RW, 0x00000020 },
	{ "fg_texture_roi_0_soft_clip_th", 0x000002DC, 23, 16, CSR_RW, 0x00000000 },
	{ "ME183", 0x000002DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD me184
	{ "fg_texture_roi_0_gmv_x", 0x000002E0, 9, 0, CSR_RW, 0x00000000 },
	{ "fg_texture_roi_0_gmv_y", 0x000002E0, 25, 16, CSR_RW, 0x00000000 },
	{ "ME184", 0x000002E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD me185
	{ "fg_texture_roi_0_conf", 0x000002E4, 21, 0, CSR_RO, 0x00000000 },
	{ "ME185", 0x000002E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me186
	{ "fg_texture_roi_0_hor", 0x000002E8, 29, 0, CSR_RO, 0x00000000 },
	{ "ME186", 0x000002E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me187
	{ "fg_texture_roi_0_ver", 0x000002EC, 29, 0, CSR_RO, 0x00000000 },
	{ "ME187", 0x000002EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me188
	{ "fg_texture_roi_0_hor_ver", 0x000002F0, 30, 0, CSR_RO, 0x00000000 },
	{ "ME188", 0x000002F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me189
	{ "fg_texture_roi_0_en", 0x000002F4, 0, 0, CSR_RW, 0x00000000 },
	{ "ME189", 0x000002F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD me190
	{ "reserved_0", 0x000002F8, 31, 0, CSR_RW, 0x00000000 },
	{ "ME190", 0x000002F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD me191
	{ "reserved_1", 0x000002FC, 31, 0, CSR_RW, 0x00000000 },
	{ "ME191", 0x000002FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD me192
	{ "reserved_2", 0x00000300, 31, 0, CSR_RW, 0x00000000 },
	{ "ME192", 0x00000300, 31, 0, CSR_RW, 0x00000000 },
	// WORD me193
	{ "reserved_3", 0x00000304, 31, 0, CSR_RW, 0x00000000 },
	{ "ME193", 0x00000304, 31, 0, CSR_RW, 0x00000000 },
	// WORD me194
	{ "mv_ink_range_sel", 0x00000308, 1, 0, CSR_RW, 0x00000000 },
	{ "ME194", 0x00000308, 31, 0, CSR_RW, 0x00000000 },
	// WORD me195
	{ "probe_en", 0x0000030C, 0, 0, CSR_RW, 0x00000000 },
	{ "probe_debug_mode", 0x0000030C, 8, 8, CSR_RW, 0x00000000 },
	{ "ME195", 0x0000030C, 31, 0, CSR_RW, 0x00000000 },
	// WORD me196
	{ "probe_x", 0x00000310, 15, 0, CSR_RW, 0x00000000 },
	{ "probe_y", 0x00000310, 31, 16, CSR_RW, 0x00000000 },
	{ "ME196", 0x00000310, 31, 0, CSR_RW, 0x00000000 },
	// WORD me197
	{ "probe_cur_zero_texture", 0x00000314, 15, 0, CSR_RO, 0x00000000 },
	{ "ME197", 0x00000314, 31, 0, CSR_RO, 0x00000000 },
	// WORD me198
	{ "probe_searched_mv_x", 0x00000318, 9, 0, CSR_RO, 0x00000000 },
	{ "probe_searched_mv_y", 0x00000318, 25, 16, CSR_RO, 0x00000000 },
	{ "ME198", 0x00000318, 31, 0, CSR_RO, 0x00000000 },
	// WORD me199
	{ "probe_searched_mv_valid", 0x0000031C, 0, 0, CSR_RO, 0x00000000 },
	{ "probe_searched_mv_type", 0x0000031C, 16, 16, CSR_RO, 0x00000000 },
	{ "ME199", 0x0000031C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me200
	{ "probe_searched_ref_texture_clip", 0x00000320, 12, 0, CSR_RO, 0x00000000 },
	{ "probe_searched_m_cost_raw", 0x00000320, 30, 16, CSR_RO, 0x00000000 },
	{ "ME200", 0x00000320, 31, 0, CSR_RO, 0x00000000 },
	// WORD me201
	{ "probe_spatial_0_mv_x", 0x00000324, 9, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_0_mv_y", 0x00000324, 25, 16, CSR_RO, 0x00000000 },
	{ "ME201", 0x00000324, 31, 0, CSR_RO, 0x00000000 },
	// WORD me202
	{ "probe_spatial_0_mv_valid", 0x00000328, 0, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_0_mv_type", 0x00000328, 16, 16, CSR_RO, 0x00000000 },
	{ "ME202", 0x00000328, 31, 0, CSR_RO, 0x00000000 },
	// WORD me203
	{ "probe_spatial_0_ref_texture_clip", 0x0000032C, 12, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_0_m_cost_raw", 0x0000032C, 30, 16, CSR_RO, 0x00000000 },
	{ "ME203", 0x0000032C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me204
	{ "probe_spatial_1_mv_x", 0x00000330, 9, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_1_mv_y", 0x00000330, 25, 16, CSR_RO, 0x00000000 },
	{ "ME204", 0x00000330, 31, 0, CSR_RO, 0x00000000 },
	// WORD me205
	{ "probe_spatial_1_mv_valid", 0x00000334, 0, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_1_mv_type", 0x00000334, 16, 16, CSR_RO, 0x00000000 },
	{ "ME205", 0x00000334, 31, 0, CSR_RO, 0x00000000 },
	// WORD me206
	{ "probe_spatial_1_ref_texture_clip", 0x00000338, 12, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_1_m_cost_raw", 0x00000338, 30, 16, CSR_RO, 0x00000000 },
	{ "ME206", 0x00000338, 31, 0, CSR_RO, 0x00000000 },
	// WORD me207
	{ "probe_spatial_2_mv_x", 0x0000033C, 9, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_2_mv_y", 0x0000033C, 25, 16, CSR_RO, 0x00000000 },
	{ "ME207", 0x0000033C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me208
	{ "probe_spatial_2_mv_valid", 0x00000340, 0, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_2_mv_type", 0x00000340, 16, 16, CSR_RO, 0x00000000 },
	{ "ME208", 0x00000340, 31, 0, CSR_RO, 0x00000000 },
	// WORD me209
	{ "probe_spatial_2_ref_texture_clip", 0x00000344, 12, 0, CSR_RO, 0x00000000 },
	{ "probe_spatial_2_m_cost_raw", 0x00000344, 30, 16, CSR_RO, 0x00000000 },
	{ "ME209", 0x00000344, 31, 0, CSR_RO, 0x00000000 },
	// WORD me210
	{ "probe_temporal_0_mv_x", 0x00000348, 9, 0, CSR_RO, 0x00000000 },
	{ "probe_temporal_0_mv_y", 0x00000348, 25, 16, CSR_RO, 0x00000000 },
	{ "ME210", 0x00000348, 31, 0, CSR_RO, 0x00000000 },
	// WORD me211
	{ "probe_temporal_0_mv_valid", 0x0000034C, 0, 0, CSR_RO, 0x00000000 },
	{ "probe_temporal_0_mv_type", 0x0000034C, 16, 16, CSR_RO, 0x00000000 },
	{ "ME211", 0x0000034C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me212
	{ "probe_temporal_0_ref_texture_clip", 0x00000350, 12, 0, CSR_RO, 0x00000000 },
	{ "probe_temporal_0_m_cost_raw", 0x00000350, 30, 16, CSR_RO, 0x00000000 },
	{ "ME212", 0x00000350, 31, 0, CSR_RO, 0x00000000 },
	// WORD me213
	{ "probe_temporal_1_mv_x", 0x00000354, 9, 0, CSR_RO, 0x00000000 },
	{ "probe_temporal_1_mv_y", 0x00000354, 25, 16, CSR_RO, 0x00000000 },
	{ "ME213", 0x00000354, 31, 0, CSR_RO, 0x00000000 },
	// WORD me214
	{ "probe_temporal_1_mv_valid", 0x00000358, 0, 0, CSR_RO, 0x00000000 },
	{ "probe_temporal_1_mv_type", 0x00000358, 16, 16, CSR_RO, 0x00000000 },
	{ "ME214", 0x00000358, 31, 0, CSR_RO, 0x00000000 },
	// WORD me215
	{ "probe_temporal_1_ref_texture_clip", 0x0000035C, 12, 0, CSR_RO, 0x00000000 },
	{ "probe_temporal_1_m_cost_raw", 0x0000035C, 30, 16, CSR_RO, 0x00000000 },
	{ "ME215", 0x0000035C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me216
	{ "probe_refined_mv_x", 0x00000360, 9, 0, CSR_RO, 0x00000000 },
	{ "probe_refined_mv_y", 0x00000360, 25, 16, CSR_RO, 0x00000000 },
	{ "ME216", 0x00000360, 31, 0, CSR_RO, 0x00000000 },
	// WORD me217
	{ "probe_refined_mv_valid", 0x00000364, 0, 0, CSR_RO, 0x00000000 },
	{ "ME217", 0x00000364, 31, 0, CSR_RO, 0x00000000 },
	// WORD me218
	{ "probe_refined_ref_texture_clip", 0x00000368, 12, 0, CSR_RO, 0x00000000 },
	{ "probe_refined_m_cost_raw", 0x00000368, 30, 16, CSR_RO, 0x00000000 },
	{ "ME218", 0x00000368, 31, 0, CSR_RO, 0x00000000 },
	// WORD me219
	{ "probe_gmv_ref_texture_clip", 0x0000036C, 12, 0, CSR_RO, 0x00000000 },
	{ "probe_gmv_m_cost_raw", 0x0000036C, 30, 16, CSR_RO, 0x00000000 },
	{ "ME219", 0x0000036C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me220
	{ "best_sad_roi_0_hist_0", 0x00000370, 23, 0, CSR_RO, 0x00000000 },
	{ "ME220", 0x00000370, 31, 0, CSR_RO, 0x00000000 },
	// WORD me221
	{ "best_sad_roi_0_hist_1", 0x00000374, 23, 0, CSR_RO, 0x00000000 },
	{ "ME221", 0x00000374, 31, 0, CSR_RO, 0x00000000 },
	// WORD me222
	{ "best_sad_roi_0_hist_2", 0x00000378, 23, 0, CSR_RO, 0x00000000 },
	{ "ME222", 0x00000378, 31, 0, CSR_RO, 0x00000000 },
	// WORD me223
	{ "best_sad_roi_0_hist_3", 0x0000037C, 23, 0, CSR_RO, 0x00000000 },
	{ "ME223", 0x0000037C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me224
	{ "best_sad_roi_0_hist_4", 0x00000380, 23, 0, CSR_RO, 0x00000000 },
	{ "ME224", 0x00000380, 31, 0, CSR_RO, 0x00000000 },
	// WORD me225
	{ "best_sad_roi_0_hist_5", 0x00000384, 23, 0, CSR_RO, 0x00000000 },
	{ "ME225", 0x00000384, 31, 0, CSR_RO, 0x00000000 },
	// WORD me226
	{ "best_sad_roi_0_hist_6", 0x00000388, 23, 0, CSR_RO, 0x00000000 },
	{ "ME226", 0x00000388, 31, 0, CSR_RO, 0x00000000 },
	// WORD me227
	{ "best_sad_roi_0_hist_7", 0x0000038C, 23, 0, CSR_RO, 0x00000000 },
	{ "ME227", 0x0000038C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me228
	{ "best_sad_roi_0_hist_8", 0x00000390, 23, 0, CSR_RO, 0x00000000 },
	{ "ME228", 0x00000390, 31, 0, CSR_RO, 0x00000000 },
	// WORD me229
	{ "best_sad_roi_0_hist_9", 0x00000394, 23, 0, CSR_RO, 0x00000000 },
	{ "ME229", 0x00000394, 31, 0, CSR_RO, 0x00000000 },
	// WORD me230
	{ "best_sad_roi_0_hist_10", 0x00000398, 23, 0, CSR_RO, 0x00000000 },
	{ "ME230", 0x00000398, 31, 0, CSR_RO, 0x00000000 },
	// WORD me231
	{ "best_sad_roi_0_hist_11", 0x0000039C, 23, 0, CSR_RO, 0x00000000 },
	{ "ME231", 0x0000039C, 31, 0, CSR_RO, 0x00000000 },
	// WORD me232
	{ "best_sad_roi_0_hist_12", 0x000003A0, 23, 0, CSR_RO, 0x00000000 },
	{ "ME232", 0x000003A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me233
	{ "best_sad_roi_0_hist_13", 0x000003A4, 23, 0, CSR_RO, 0x00000000 },
	{ "ME233", 0x000003A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me234
	{ "best_sad_roi_0_hist_14", 0x000003A8, 23, 0, CSR_RO, 0x00000000 },
	{ "ME234", 0x000003A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me235
	{ "best_sad_roi_0_hist_15", 0x000003AC, 23, 0, CSR_RO, 0x00000000 },
	{ "ME235", 0x000003AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me236
	{ "best_sad_roi_0_hist_16", 0x000003B0, 23, 0, CSR_RO, 0x00000000 },
	{ "ME236", 0x000003B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me237
	{ "best_sad_roi_0_hist_17", 0x000003B4, 23, 0, CSR_RO, 0x00000000 },
	{ "ME237", 0x000003B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me238
	{ "best_sad_roi_0_hist_18", 0x000003B8, 23, 0, CSR_RO, 0x00000000 },
	{ "ME238", 0x000003B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me239
	{ "best_sad_roi_0_hist_19", 0x000003BC, 23, 0, CSR_RO, 0x00000000 },
	{ "ME239", 0x000003BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me240
	{ "best_sad_roi_0_hist_20", 0x000003C0, 23, 0, CSR_RO, 0x00000000 },
	{ "ME240", 0x000003C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me241
	{ "best_sad_roi_0_hist_21", 0x000003C4, 23, 0, CSR_RO, 0x00000000 },
	{ "ME241", 0x000003C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me242
	{ "best_sad_roi_0_hist_22", 0x000003C8, 23, 0, CSR_RO, 0x00000000 },
	{ "ME242", 0x000003C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me243
	{ "best_sad_roi_0_hist_23", 0x000003CC, 23, 0, CSR_RO, 0x00000000 },
	{ "ME243", 0x000003CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me244
	{ "best_sad_roi_0_hist_24", 0x000003D0, 23, 0, CSR_RO, 0x00000000 },
	{ "ME244", 0x000003D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me245
	{ "best_sad_roi_0_hist_25", 0x000003D4, 23, 0, CSR_RO, 0x00000000 },
	{ "ME245", 0x000003D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me246
	{ "best_sad_roi_0_hist_26", 0x000003D8, 23, 0, CSR_RO, 0x00000000 },
	{ "ME246", 0x000003D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me247
	{ "best_sad_roi_0_hist_27", 0x000003DC, 23, 0, CSR_RO, 0x00000000 },
	{ "ME247", 0x000003DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me248
	{ "best_sad_roi_0_hist_28", 0x000003E0, 23, 0, CSR_RO, 0x00000000 },
	{ "ME248", 0x000003E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD me249
	{ "best_sad_roi_0_hist_29", 0x000003E4, 23, 0, CSR_RO, 0x00000000 },
	{ "ME249", 0x000003E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD me250
	{ "best_sad_roi_0_hist_30", 0x000003E8, 23, 0, CSR_RO, 0x00000000 },
	{ "ME250", 0x000003E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD me251
	{ "best_sad_roi_0_hist_31", 0x000003EC, 23, 0, CSR_RO, 0x00000000 },
	{ "ME251", 0x000003EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD me252
	{ "best_sad_roi_0_hist_32", 0x000003F0, 23, 0, CSR_RO, 0x00000000 },
	{ "ME252", 0x000003F0, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ME_H_
