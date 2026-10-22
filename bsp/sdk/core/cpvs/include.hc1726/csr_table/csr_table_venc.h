/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_VENC_H_
#define CSR_TABLE_VENC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_venc[] = {
	// WORD frm_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "FRM_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_seq_hdr_cont", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_seq_hdr_cont", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_seq_hdr_cont", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_frame_size
	{ "frm_mb_hor_num_m1", 0x00000010, 11, 0, CSR_RW, 0x00000077 },
	{ "frm_mb_ver_num_m1", 0x00000010, 27, 16, CSR_RW, 0x00000043 },
	{ "VENC_FRAME_SIZE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_frame_type
	{ "slice_type", 0x00000014, 1, 0, CSR_RW, 0x00000000 },
	{ "is_seq_header", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "VENC_FRAME_TYPE", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_frame_byte
	{ "frame_bs_byte_length", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_FRAME_BYTE", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_enc_tool_0
	{ "entropy_coding_mode", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "transform_8x8_mode_flag", 0x0000001C, 16, 16, CSR_RW, 0x00000000 },
	{ "enable_long_term_ref_frm", 0x0000001C, 24, 24, CSR_RW, 0x00000000 },
	{ "VENC_ENC_TOOL_0", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_enc_tool_1
	{ "enable_sao", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "hevc_seq_rc_enable", 0x00000020, 8, 8, CSR_RW, 0x00000001 },
	{ "VENC_ENC_TOOL_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_deblk_tool
	{ "disable_deblocking_filter", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "alpha_c0_offset_div2", 0x00000024, 11, 8, CSR_RW, 0x00000000 },
	{ "beta_offset_div2", 0x00000024, 19, 16, CSR_RW, 0x00000000 },
	{ "VENC_DEBLK_TOOL", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coef_cut
	{ "luma_coef_cost_cut_th", 0x00000028, 7, 0, CSR_RW, 0x00000004 },
	{ "luma_8x8_coef_cost_cut_th", 0x00000028, 15, 8, CSR_RW, 0x0000000A },
	{ "VENC_COEF_CUT", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mb_still
	{ "set_normal_mb_still", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "set_roi_mb_still", 0x0000002C, 23, 16, CSR_RW, 0x00000000 },
	{ "VENC_MB_STILL", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_hdr_setting
	{ "hdr_data_length", 0x00000030, 7, 0, CSR_RW, 0x00000000 },
	{ "hdr_data_last", 0x00000030, 16, 16, CSR_RW, 0x00000001 },
	{ "VENC_HDR_SETTING", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_sr_up_set
	{ "sr_up_mv_range", 0x00000034, 2, 0, CSR_RW, 0x00000000 },
	{ "sr_up_mv_disable", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "VENC_SR_UP_SET", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_sr_search_set
	{ "sr_max_hor_range", 0x00000038, 7, 0, CSR_RW, 0x00000070 },
	{ "sr_max_ver_range", 0x00000038, 14, 8, CSR_RW, 0x00000040 },
	{ "sr_max_levelc_ver_range", 0x00000038, 22, 16, CSR_RW, 0x00000040 },
	{ "sr_extend_refr", 0x00000038, 24, 24, CSR_RW, 0x00000000 },
	{ "VENC_SR_SEARCH_SET", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_merge_mv_cand
	{ "max_num_merge_cand", 0x0000003C, 2, 0, CSR_RW, 0x00000005 },
	{ "VENC_MERGE_MV_CAND", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mv_quality
	{ "texture_minmax_threshold", 0x00000040, 3, 0, CSR_RW, 0x00000004 },
	{ "apply_mv_valid", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "VENC_MV_QUALITY", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_intra_mode_param
	{ "intra_cip_offset_enable", 0x00000048, 0, 0, CSR_RW, 0x00000001 },
	{ "VENC_INTRA_MODE_PARAM", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_hdr_data_0
	{ "hdr_data_0", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	{ "VENC_HDR_DATA_0", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_hdr_data_1
	{ "hdr_data_1", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	{ "VENC_HDR_DATA_1", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_hdr_data_2
	{ "hdr_data_2", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	{ "VENC_HDR_DATA_2", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_hdr_data_3
	{ "hdr_data_3", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	{ "VENC_HDR_DATA_3", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_minmax_ratio_0
	{ "minmax_0_ratio", 0x0000005C, 4, 0, CSR_RW, 0x00000010 },
	{ "minmax_1_ratio", 0x0000005C, 12, 8, CSR_RW, 0x00000010 },
	{ "minmax_2_ratio", 0x0000005C, 20, 16, CSR_RW, 0x0000000C },
	{ "minmax_3_ratio", 0x0000005C, 28, 24, CSR_RW, 0x0000000A },
	{ "VENC_MINMAX_RATIO_0", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_minmax_ratio_1
	{ "minmax_4_ratio", 0x00000060, 4, 0, CSR_RW, 0x00000008 },
	{ "minmax_5_ratio", 0x00000060, 12, 8, CSR_RW, 0x00000007 },
	{ "minmax_6_ratio", 0x00000060, 20, 16, CSR_RW, 0x00000006 },
	{ "minmax_7_ratio", 0x00000060, 28, 24, CSR_RW, 0x00000006 },
	{ "VENC_MINMAX_RATIO_1", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_minmax_ratio_2
	{ "minmax_8_ratio", 0x00000064, 4, 0, CSR_RW, 0x00000006 },
	{ "minmax_9_ratio", 0x00000064, 12, 8, CSR_RW, 0x00000005 },
	{ "minmax_10_ratio", 0x00000064, 20, 16, CSR_RW, 0x00000005 },
	{ "minmax_11_ratio", 0x00000064, 28, 24, CSR_RW, 0x00000004 },
	{ "VENC_MINMAX_RATIO_2", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_minmax_ratio_3
	{ "minmax_12_ratio", 0x00000068, 4, 0, CSR_RW, 0x00000004 },
	{ "minmax_13_ratio", 0x00000068, 12, 8, CSR_RW, 0x00000003 },
	{ "minmax_14_ratio", 0x00000068, 20, 16, CSR_RW, 0x00000003 },
	{ "minmax_15_ratio", 0x00000068, 28, 24, CSR_RW, 0x00000002 },
	{ "VENC_MINMAX_RATIO_3", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_minmax_ratio_4
	{ "minmax_16_ratio", 0x0000006C, 4, 0, CSR_RW, 0x00000002 },
	{ "minmax_other_ratio", 0x0000006C, 12, 8, CSR_RW, 0x00000001 },
	{ "VENC_MINMAX_RATIO_4", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_hevc_intra_mode
	{ "hevc_i8_mode_num_m1", 0x00000070, 5, 0, CSR_RW, 0x00000006 },
	{ "hevc_i16_mode_num_m1", 0x00000070, 13, 8, CSR_RW, 0x00000006 },
	{ "hevc_i32_mode_num_m1", 0x00000070, 21, 16, CSR_RW, 0x00000006 },
	{ "hevc_cip_mode_num_m1", 0x00000070, 26, 24, CSR_RW, 0x00000004 },
	{ "VENC_HEVC_INTRA_MODE", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_type9
	{ "roi_type9_enable", 0x00000074, 0, 0, CSR_RW, 0x00000000 },
	{ "VENC_ROI_TYPE9", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_enable
	{ "mbrc_ink_en", 0x00000078, 0, 0, CSR_RW, 0x00000000 },
	{ "mbrc_en", 0x00000078, 8, 8, CSR_RW, 0x00000000 },
	{ "VENC_MBRC_ENABLE", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_th
	{ "mbrc_spatial_complexity_th", 0x0000007C, 9, 0, CSR_RW, 0x00000080 },
	{ "mbrc_var_coring_th", 0x0000007C, 29, 16, CSR_RW, 0x00000400 },
	{ "VENC_MBRC_COMPLEX_TH", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_0_info_qp
	{ "mbrc_complex_level_0_qp", 0x00000080, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_0_INFO_QP", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_0_info_lambda
	{ "mbrc_complex_level_0_lambda", 0x00000084, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_0_sao_lambda", 0x00000084, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_0_INFO_LAMBDA", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_1_info_qp
	{ "mbrc_complex_level_1_qp", 0x00000088, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_1_INFO_QP", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_1_info_lambda
	{ "mbrc_complex_level_1_lambda", 0x0000008C, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_1_sao_lambda", 0x0000008C, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_1_INFO_LAMBDA", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_2_info_qp
	{ "mbrc_complex_level_2_qp", 0x00000090, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_2_INFO_QP", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_2_info_lambda
	{ "mbrc_complex_level_2_lambda", 0x00000094, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_2_sao_lambda", 0x00000094, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_2_INFO_LAMBDA", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_3_info_qp
	{ "mbrc_complex_level_3_qp", 0x00000098, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_3_INFO_QP", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_3_info_lambda
	{ "mbrc_complex_level_3_lambda", 0x0000009C, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_3_sao_lambda", 0x0000009C, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_3_INFO_LAMBDA", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_4_info_qp
	{ "mbrc_complex_level_4_qp", 0x000000A0, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_4_INFO_QP", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_4_info_lambda
	{ "mbrc_complex_level_4_lambda", 0x000000A4, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_4_sao_lambda", 0x000000A4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_4_INFO_LAMBDA", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_5_info_qp
	{ "mbrc_complex_level_5_qp", 0x000000A8, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_5_INFO_QP", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_5_info_lambda
	{ "mbrc_complex_level_5_lambda", 0x000000AC, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_5_sao_lambda", 0x000000AC, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_5_INFO_LAMBDA", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_6_info_qp
	{ "mbrc_complex_level_6_qp", 0x000000B0, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_6_INFO_QP", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_6_info_lambda
	{ "mbrc_complex_level_6_lambda", 0x000000B4, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_6_sao_lambda", 0x000000B4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_6_INFO_LAMBDA", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_7_info_qp
	{ "mbrc_complex_level_7_qp", 0x000000B8, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_7_INFO_QP", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_7_info_lambda
	{ "mbrc_complex_level_7_lambda", 0x000000BC, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_7_sao_lambda", 0x000000BC, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_7_INFO_LAMBDA", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_8_info_qp
	{ "mbrc_complex_level_8_qp", 0x000000C0, 5, 0, CSR_RW, 0x0000001E },
	{ "VENC_MBRC_COMPLEX_LEVEL_8_INFO_QP", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_level_8_info_lambda
	{ "mbrc_complex_level_8_lambda", 0x000000C4, 8, 0, CSR_RW, 0x00000014 },
	{ "mbrc_complex_level_8_sao_lambda", 0x000000C4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_MBRC_COMPLEX_LEVEL_8_INFO_LAMBDA", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mbrc_complex_alpha
	{ "mbrc_complex_alpha_parti_min", 0x000000C8, 6, 0, CSR_RW, 0x00000000 },
	{ "mbrc_complex_alpha_dir_min", 0x000000C8, 22, 16, CSR_RW, 0x00000000 },
	{ "VENC_MBRC_COMPLEX_ALPHA", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_complex_dir_th_i32
	{ "md_mode_dir_th_i32", 0x000000CC, 17, 0, CSR_RW, 0x00000400 },
	{ "VENC_MD_COMPLEX_DIR_TH_I32", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_complex_dir_th_i16
	{ "md_mode_dir_th_i16", 0x000000D0, 15, 0, CSR_RW, 0x00000400 },
	{ "VENC_MD_COMPLEX_DIR_TH_I16", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_complex_dir_th_i8
	{ "md_mode_dir_th_i8", 0x000000D4, 13, 0, CSR_RW, 0x00000100 },
	{ "VENC_MD_COMPLEX_DIR_TH_I8", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_i32_strong_smooth
	{ "strong_intra_smoothing_enable", 0x000000D8, 0, 0, CSR_RW, 0x00000001 },
	{ "VENC_MD_I32_STRONG_SMOOTH", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i32_dc
	{ "md_mode_cost_offset_i32_dc", 0x000000DC, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I32_DC", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i32_plane
	{ "md_mode_cost_offset_i32_plane", 0x000000E0, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I32_PLANE", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i32_ang_hv
	{ "md_mode_cost_offset_i32_ang_hv", 0x000000E4, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I32_ANG_HV", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i32_ang_slash
	{ "md_mode_cost_offset_i32_ang_slash", 0x000000E8, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I32_ANG_SLASH", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i16_dc
	{ "md_mode_cost_offset_i16_dc", 0x000000EC, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I16_DC", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i16_plane
	{ "md_mode_cost_offset_i16_plane", 0x000000F0, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I16_PLANE", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i16_ang_hv
	{ "md_mode_cost_offset_i16_ang_hv", 0x000000F4, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I16_ANG_HV", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i16_ang_slash
	{ "md_mode_cost_offset_i16_ang_slash", 0x000000F8, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I16_ANG_SLASH", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i8_dc
	{ "md_mode_cost_offset_i8_dc", 0x000000FC, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I8_DC", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i8_plane
	{ "md_mode_cost_offset_i8_plane", 0x00000100, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I8_PLANE", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i8_ang_hv
	{ "md_mode_cost_offset_i8_ang_hv", 0x00000104, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I8_ANG_HV", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i8_ang_slash
	{ "md_mode_cost_offset_i8_ang_slash", 0x00000108, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I8_ANG_SLASH", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i4_dc
	{ "md_mode_cost_offset_i4_dc", 0x0000010C, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I4_DC", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i4_ang_hv
	{ "md_mode_cost_offset_i4_ang_hv", 0x00000110, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I4_ANG_HV", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_i4_ang_slash
	{ "md_mode_cost_offset_i4_ang_slash", 0x00000114, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_I4_ANG_SLASH", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_p32x32
	{ "md_mode_cost_offset_p32x32", 0x00000118, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_P32x32", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_p32x16
	{ "md_mode_cost_offset_p32x16", 0x0000011C, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_P32x16", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_p16x32
	{ "md_mode_cost_offset_p16x32", 0x00000120, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_P16x32", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_p16x16
	{ "md_mode_cost_offset_p16x16", 0x00000124, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_P16x16", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_p16x8
	{ "md_mode_cost_offset_p16x8", 0x00000128, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_P16x8", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_p8x16
	{ "md_mode_cost_offset_p8x16", 0x0000012C, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_P8x16", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_p8x8
	{ "md_mode_cost_offset_p8x8", 0x00000130, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_P8x8", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_dist_bias_i32_cost
	{ "md_dist_bias_i32", 0x00000134, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_DIST_BIAS_I32_COST", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_dist_bias_i16_cost
	{ "md_dist_bias_i16", 0x00000138, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_DIST_BIAS_I16_COST", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_dist_bias_i8_cost
	{ "md_dist_bias_i8", 0x0000013C, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_DIST_BIAS_I8_COST", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_dist_bias_i4_cost
	{ "md_dist_bias_i4", 0x00000140, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_DIST_BIAS_I4_COST", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_dist_transform_4x4_fallback_offset
	{ "md_dist_tr4_fallback_offset", 0x00000144, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_DIST_TRANSFORM_4X4_FALLBACK_OFFSET", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_merge_alpha
	{ "md_mode_cost_merge_alpha_i16", 0x00000148, 6, 0, CSR_RW, 0x00000000 },
	{ "md_mode_cost_merge_alpha_i8", 0x00000148, 14, 8, CSR_RW, 0x00000000 },
	{ "md_mode_cost_merge_alpha_i4", 0x00000148, 22, 16, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_MERGE_ALPHA", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_sse_cost_factor
	{ "md_factor_cost_sse", 0x0000014C, 8, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_SSE_COST_FACTOR", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_weight_cost_0
	{ "md_weight_cost_sse_complex_level_0", 0x00000150, 6, 0, CSR_RW, 0x00000000 },
	{ "md_weight_cost_sse_complex_level_1", 0x00000150, 14, 8, CSR_RW, 0x00000000 },
	{ "md_weight_cost_sse_complex_level_2", 0x00000150, 22, 16, CSR_RW, 0x00000000 },
	{ "md_weight_cost_sse_complex_level_3", 0x00000150, 30, 24, CSR_RW, 0x00000000 },
	{ "VENC_MD_WEIGHT_COST_0", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_weight_cost_1
	{ "md_weight_cost_sse_complex_level_4", 0x00000154, 6, 0, CSR_RW, 0x00000000 },
	{ "md_weight_cost_sse_complex_level_5", 0x00000154, 14, 8, CSR_RW, 0x00000000 },
	{ "md_weight_cost_sse_complex_level_6", 0x00000154, 22, 16, CSR_RW, 0x00000000 },
	{ "md_weight_cost_sse_complex_level_7", 0x00000154, 30, 24, CSR_RW, 0x00000000 },
	{ "VENC_MD_WEIGHT_COST_1", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_weight_cost_2
	{ "md_weight_cost_sse_complex_level_8", 0x00000158, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_WEIGHT_COST_2", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_cost_offset_c_osd
	{ "md_mode_cost_offset_chroma_osd", 0x0000015C, 6, 0, CSR_RW, 0x00000000 },
	{ "VENC_MD_COST_OFFSET_C_OSD", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_md_mode_cost_offset_mv_non_valid
	{ "csr_md_mode_cost_offset_mv_non_valid_level_0", 0x00000160, 6, 0, CSR_RW, 0x00000000 },
	{ "csr_md_mode_cost_offset_mv_non_valid_level_1", 0x00000160, 14, 8, CSR_RW, 0x00000000 },
	{ "csr_md_mode_cost_offset_mv_non_valid_level_2", 0x00000160, 22, 16, CSR_RW, 0x00000000 },
	{ "VENC_MD_MODE_COST_OFFSET_MV_NON_VALID", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_rd_factor_c
	{ "rd_factor_offset_c", 0x00000164, 4, 0, CSR_RW, 0x00000000 },
	{ "VENC_RD_FACTOR_C", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_qp_osd_offset_minus
	{ "qp_osd_offset", 0x00000168, 5, 0, CSR_RW, 0x00000000 },
	{ "VENC_QP_OSD_OFFSET_MINUS", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_qp_chroma_offset_2s
	{ "qp_chroma_offset_2s", 0x0000016C, 4, 0, CSR_RW, 0x00000000 },
	{ "VENC_QP_CHROMA_OFFSET_2S", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_scaling_list
	{ "scaling_list_sel", 0x00000170, 1, 0, CSR_RW, 0x00000000 },
	{ "scaling_list_en", 0x00000170, 16, 16, CSR_RW, 0x00000000 },
	{ "VENC_SCALING_LIST", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dist_th_mv_0
	{ "cut_coef_dist_th_y_blk16_mv_0", 0x00000174, 9, 0, CSR_RW, 0x00000000 },
	{ "cut_coef_dist_th_c_blk16_mv_0", 0x00000174, 25, 16, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DIST_TH_MV_0", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dist_th_y_tr16
	{ "cut_coef_dist_th_y_tr16", 0x00000178, 9, 0, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DIST_TH_Y_TR16", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dist_th_y_tr8
	{ "cut_coef_dist_th_y_tr8", 0x0000017C, 9, 0, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DIST_TH_Y_TR8", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dist_th_y_tr4
	{ "cut_coef_dist_th_y_tr4", 0x00000180, 9, 0, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DIST_TH_Y_TR4", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dist_th_c_tr8
	{ "cut_coef_dist_th_c_tr8", 0x00000184, 9, 0, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DIST_TH_C_TR8", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dist_th_c_tr4
	{ "cut_coef_dist_th_c_tr4", 0x00000188, 9, 0, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DIST_TH_C_TR4", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dc_th_mv_0
	{ "cut_coef_dc_th_y_blk16_mv_0", 0x0000018C, 5, 0, CSR_RW, 0x00000000 },
	{ "cut_coef_dc_th_c_blk16_mv_0", 0x0000018C, 21, 16, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DC_TH_MV_0", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dc_th_y
	{ "cut_coef_dc_th_y_tr16", 0x00000190, 5, 0, CSR_RW, 0x00000000 },
	{ "cut_coef_dc_th_y_tr8", 0x00000190, 13, 8, CSR_RW, 0x00000000 },
	{ "cut_coef_dc_th_y_tr4", 0x00000190, 21, 16, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DC_TH_Y", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_coeff_cut_dc_th_c
	{ "cut_coef_dc_th_c_tr8", 0x00000194, 5, 0, CSR_RW, 0x00000000 },
	{ "cut_coef_dc_th_c_tr4", 0x00000194, 21, 16, CSR_RW, 0x00000000 },
	{ "VENC_COEFF_CUT_DC_TH_C", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mode_num_inter_32x32_skip
	{ "mode_num_inter_32x32_skip", 0x0000019C, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_32x32_SKIP", 0x0000019C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_inter_32x32
	{ "mode_num_inter_32x32", 0x000001A0, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_32X32", 0x000001A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_inter_32x16
	{ "mode_num_inter_32x16", 0x000001A4, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_32X16", 0x000001A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_inter_16x32
	{ "mode_num_inter_16x32", 0x000001A8, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_16X32", 0x000001A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_inter_16x16_skip
	{ "mode_num_inter_16x16_skip", 0x000001AC, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_16x16_SKIP", 0x000001AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_inter_16x16
	{ "mode_num_inter_16x16", 0x000001B0, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_16X16", 0x000001B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_inter_16x8
	{ "mode_num_inter_16x8", 0x000001B4, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_16X8", 0x000001B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_inter_8x16
	{ "mode_num_inter_8x16", 0x000001B8, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_8X16", 0x000001B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_inter_8x8
	{ "mode_num_inter_8x8", 0x000001BC, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTER_8X8", 0x000001BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_intra_32x32
	{ "mode_num_intra_32x32", 0x000001C0, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTRA_32X32", 0x000001C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_intra_16x16
	{ "mode_num_intra_16x16", 0x000001C4, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTRA_16X16", 0x000001C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mode_num_intra_8x8
	{ "mode_num_intra_8x8", 0x000001C8, 18, 0, CSR_RO, 0x00000000 },
	{ "VENC_MODE_NUM_INTRA_8X8", 0x000001C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_roi_0_bit
	{ "roi_0_frame_bit_length", 0x000001CC, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_ROI_0_BIT", 0x000001CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_roi_1_bit
	{ "roi_1_frame_bit_length", 0x000001D0, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_ROI_1_BIT", 0x000001D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_roi_2_bit
	{ "roi_2_frame_bit_length", 0x000001D4, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_ROI_2_BIT", 0x000001D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_roi_3_bit
	{ "roi_3_frame_bit_length", 0x000001D8, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_ROI_3_BIT", 0x000001D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_roi_4_bit
	{ "roi_4_frame_bit_length", 0x000001DC, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_ROI_4_BIT", 0x000001DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_roi_5_bit
	{ "roi_5_frame_bit_length", 0x000001E0, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_ROI_5_BIT", 0x000001E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_roi_6_bit
	{ "roi_6_frame_bit_length", 0x000001E4, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_ROI_6_BIT", 0x000001E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_roi_7_bit
	{ "roi_7_frame_bit_length", 0x000001E8, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_ROI_7_BIT", 0x000001E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_normal_bit
	{ "nor_frame_bit_length", 0x000001EC, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_NORMAL_BIT", 0x000001EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_osd_bit
	{ "osd_frame_bit_length", 0x000001F0, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_OSD_BIT", 0x000001F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_0_bit
	{ "complex_level_0_bit_num", 0x000001F4, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_0_BIT", 0x000001F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_1_bit
	{ "complex_level_1_bit_num", 0x000001F8, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_1_BIT", 0x000001F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_2_bit
	{ "complex_level_2_bit_num", 0x000001FC, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_2_BIT", 0x000001FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_3_bit
	{ "complex_level_3_bit_num", 0x00000200, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_3_BIT", 0x00000200, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_4_bit
	{ "complex_level_4_bit_num", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_4_BIT", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_5_bit
	{ "complex_level_5_bit_num", 0x00000208, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_5_BIT", 0x00000208, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_6_bit
	{ "complex_level_6_bit_num", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_6_BIT", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_7_bit
	{ "complex_level_7_bit_num", 0x00000210, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_7_BIT", 0x00000210, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_8_bit
	{ "complex_level_8_bit_num", 0x00000214, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_8_BIT", 0x00000214, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_0_qp_sum
	{ "complex_level_0_qp_sum", 0x00000218, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_0_QP_SUM", 0x00000218, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_1_qp_sum
	{ "complex_level_1_qp_sum", 0x0000021C, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_1_QP_SUM", 0x0000021C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_2_qp_sum
	{ "complex_level_2_qp_sum", 0x00000220, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_2_QP_SUM", 0x00000220, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_3_qp_sum
	{ "complex_level_3_qp_sum", 0x00000224, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_3_QP_SUM", 0x00000224, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_4_qp_sum
	{ "complex_level_4_qp_sum", 0x00000228, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_4_QP_SUM", 0x00000228, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_5_qp_sum
	{ "complex_level_5_qp_sum", 0x0000022C, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_5_QP_SUM", 0x0000022C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_6_qp_sum
	{ "complex_level_6_qp_sum", 0x00000230, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_6_QP_SUM", 0x00000230, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_7_qp_sum
	{ "complex_level_7_qp_sum", 0x00000234, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_7_QP_SUM", 0x00000234, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_8_qp_sum
	{ "complex_level_8_qp_sum", 0x00000238, 20, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_8_QP_SUM", 0x00000238, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_0_complexity_sum
	{ "complex_level_0_complexity", 0x0000023C, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_0_COMPLEXITY_SUM", 0x0000023C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_1_complexity_sum
	{ "complex_level_1_complexity", 0x00000240, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_1_COMPLEXITY_SUM", 0x00000240, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_2_complexity_sum
	{ "complex_level_2_complexity", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_2_COMPLEXITY_SUM", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_3_complexity_sum
	{ "complex_level_3_complexity", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_3_COMPLEXITY_SUM", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_4_complexity_sum
	{ "complex_level_4_complexity", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_4_COMPLEXITY_SUM", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_5_complexity_sum
	{ "complex_level_5_complexity", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_5_COMPLEXITY_SUM", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_6_complexity_sum
	{ "complex_level_6_complexity", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_6_COMPLEXITY_SUM", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_7_complexity_sum
	{ "complex_level_7_complexity", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_7_COMPLEXITY_SUM", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_8_complexity_sum
	{ "complex_level_8_complexity", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_8_COMPLEXITY_SUM", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_0_blk16_num
	{ "complex_level_0_blk16_num", 0x00000260, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_0_BLK16_NUM", 0x00000260, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_1_blk16_num
	{ "complex_level_1_blk16_num", 0x00000264, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_1_BLK16_NUM", 0x00000264, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_2_blk16_num
	{ "complex_level_2_blk16_num", 0x00000268, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_2_BLK16_NUM", 0x00000268, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_3_blk16_num
	{ "complex_level_3_blk16_num", 0x0000026C, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_3_BLK16_NUM", 0x0000026C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_4_blk16_num
	{ "complex_level_4_blk16_num", 0x00000270, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_4_BLK16_NUM", 0x00000270, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_5_blk16_num
	{ "complex_level_5_blk16_num", 0x00000274, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_5_BLK16_NUM", 0x00000274, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_6_blk16_num
	{ "complex_level_6_blk16_num", 0x00000278, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_6_BLK16_NUM", 0x00000278, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_7_blk16_num
	{ "complex_level_7_blk16_num", 0x0000027C, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_7_BLK16_NUM", 0x0000027C, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_complex_level_8_blk16_num
	{ "complex_level_8_blk16_num", 0x00000280, 14, 0, CSR_RO, 0x00000000 },
	{ "VENC_COMPLEX_LEVEL_8_BLK16_NUM", 0x00000280, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_mv_scaling
	{ "mv_scaling_en", 0x00000284, 0, 0, CSR_RW, 0x00000000 },
	{ "mv_scaling_ratio", 0x00000284, 20, 16, CSR_RW, 0x00000000 },
	{ "VENC_MV_SCALING", 0x00000284, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_osd_0_info
	{ "osd_0_en_qp", 0x00000288, 0, 0, CSR_RW, 0x00000000 },
	{ "osd_0_mode", 0x00000288, 9, 8, CSR_RW, 0x00000000 },
	{ "osd_0_qp", 0x00000288, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_OSD_0_INFO", 0x00000288, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_osd_0_lambda
	{ "osd_0_lambda", 0x0000028C, 8, 0, CSR_RW, 0x00000014 },
	{ "osd_0_sao_lambda", 0x0000028C, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_OSD_0_LAMBDA", 0x0000028C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_osd_1_info
	{ "osd_1_en_qp", 0x00000290, 0, 0, CSR_RW, 0x00000000 },
	{ "osd_1_mode", 0x00000290, 9, 8, CSR_RW, 0x00000000 },
	{ "osd_1_qp", 0x00000290, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_OSD_1_INFO", 0x00000290, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_osd_1_lambda
	{ "osd_1_lambda", 0x00000294, 8, 0, CSR_RW, 0x00000014 },
	{ "osd_1_sao_lambda", 0x00000294, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_OSD_1_LAMBDA", 0x00000294, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_osd_2_info
	{ "osd_2_en_qp", 0x00000298, 0, 0, CSR_RW, 0x00000000 },
	{ "osd_2_mode", 0x00000298, 9, 8, CSR_RW, 0x00000000 },
	{ "osd_2_qp", 0x00000298, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_OSD_2_INFO", 0x00000298, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_osd_2_lambda
	{ "osd_2_lambda", 0x0000029C, 8, 0, CSR_RW, 0x00000014 },
	{ "osd_2_sao_lambda", 0x0000029C, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_OSD_2_LAMBDA", 0x0000029C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_osd_3_info
	{ "osd_3_en_qp", 0x000002A0, 0, 0, CSR_RW, 0x00000000 },
	{ "osd_3_mode", 0x000002A0, 9, 8, CSR_RW, 0x00000000 },
	{ "osd_3_qp", 0x000002A0, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_OSD_3_INFO", 0x000002A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_osd_3_lambda
	{ "osd_3_lambda", 0x000002A4, 8, 0, CSR_RW, 0x00000014 },
	{ "osd_3_sao_lambda", 0x000002A4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_OSD_3_LAMBDA", 0x000002A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_0_info
	{ "roi_0_enable", 0x000002A8, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_0_mode", 0x000002A8, 9, 8, CSR_RW, 0x00000000 },
	{ "roi_0_qp", 0x000002A8, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_ROI_0_INFO", 0x000002A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_0_x
	{ "roi_0_sx", 0x000002AC, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_0_ex", 0x000002AC, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_0_X", 0x000002AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_0_y
	{ "roi_0_sy", 0x000002B0, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_0_ey", 0x000002B0, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_0_Y", 0x000002B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_0_lambda
	{ "roi_0_lambda", 0x000002B4, 8, 0, CSR_RW, 0x00000014 },
	{ "roi_0_sao_lambda", 0x000002B4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_ROI_0_LAMBDA", 0x000002B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_1_info
	{ "roi_1_enable", 0x000002B8, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_1_mode", 0x000002B8, 9, 8, CSR_RW, 0x00000000 },
	{ "roi_1_qp", 0x000002B8, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_ROI_1_INFO", 0x000002B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_1_x
	{ "roi_1_sx", 0x000002BC, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_1_ex", 0x000002BC, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_1_X", 0x000002BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_1_y
	{ "roi_1_sy", 0x000002C0, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_1_ey", 0x000002C0, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_1_Y", 0x000002C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_1_lambda
	{ "roi_1_lambda", 0x000002C4, 8, 0, CSR_RW, 0x00000014 },
	{ "roi_1_sao_lambda", 0x000002C4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_ROI_1_LAMBDA", 0x000002C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_2_info
	{ "roi_2_enable", 0x000002C8, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_2_mode", 0x000002C8, 9, 8, CSR_RW, 0x00000000 },
	{ "roi_2_qp", 0x000002C8, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_ROI_2_INFO", 0x000002C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_2_x
	{ "roi_2_sx", 0x000002CC, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_2_ex", 0x000002CC, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_2_X", 0x000002CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_2_y
	{ "roi_2_sy", 0x000002D0, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_2_ey", 0x000002D0, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_2_Y", 0x000002D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_2_lambda
	{ "roi_2_lambda", 0x000002D4, 8, 0, CSR_RW, 0x00000014 },
	{ "roi_2_sao_lambda", 0x000002D4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_ROI_2_LAMBDA", 0x000002D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_3_info
	{ "roi_3_enable", 0x000002D8, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_3_mode", 0x000002D8, 9, 8, CSR_RW, 0x00000000 },
	{ "roi_3_qp", 0x000002D8, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_ROI_3_INFO", 0x000002D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_3_x
	{ "roi_3_sx", 0x000002DC, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_3_ex", 0x000002DC, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_3_X", 0x000002DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_3_y
	{ "roi_3_sy", 0x000002E0, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_3_ey", 0x000002E0, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_3_Y", 0x000002E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_3_lambda
	{ "roi_3_lambda", 0x000002E4, 8, 0, CSR_RW, 0x00000014 },
	{ "roi_3_sao_lambda", 0x000002E4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_ROI_3_LAMBDA", 0x000002E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_4_info
	{ "roi_4_enable", 0x000002E8, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_4_mode", 0x000002E8, 9, 8, CSR_RW, 0x00000000 },
	{ "roi_4_qp", 0x000002E8, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_ROI_4_INFO", 0x000002E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_4_x
	{ "roi_4_sx", 0x000002EC, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_4_ex", 0x000002EC, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_4_X", 0x000002EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_4_y
	{ "roi_4_sy", 0x000002F0, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_4_ey", 0x000002F0, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_4_Y", 0x000002F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_4_lambda
	{ "roi_4_lambda", 0x000002F4, 8, 0, CSR_RW, 0x00000014 },
	{ "roi_4_sao_lambda", 0x000002F4, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_ROI_4_LAMBDA", 0x000002F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_5_info
	{ "roi_5_enable", 0x000002F8, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_5_mode", 0x000002F8, 9, 8, CSR_RW, 0x00000000 },
	{ "roi_5_qp", 0x000002F8, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_ROI_5_INFO", 0x000002F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_5_x
	{ "roi_5_sx", 0x000002FC, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_5_ex", 0x000002FC, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_5_X", 0x000002FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_5_y
	{ "roi_5_sy", 0x00000300, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_5_ey", 0x00000300, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_5_Y", 0x00000300, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_5_lambda
	{ "roi_5_lambda", 0x00000304, 8, 0, CSR_RW, 0x00000014 },
	{ "roi_5_sao_lambda", 0x00000304, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_ROI_5_LAMBDA", 0x00000304, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_6_info
	{ "roi_6_enable", 0x00000308, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_6_mode", 0x00000308, 9, 8, CSR_RW, 0x00000000 },
	{ "roi_6_qp", 0x00000308, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_ROI_6_INFO", 0x00000308, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_6_x
	{ "roi_6_sx", 0x0000030C, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_6_ex", 0x0000030C, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_6_X", 0x0000030C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_6_y
	{ "roi_6_sy", 0x00000310, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_6_ey", 0x00000310, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_6_Y", 0x00000310, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_6_lambda
	{ "roi_6_lambda", 0x00000314, 8, 0, CSR_RW, 0x00000014 },
	{ "roi_6_sao_lambda", 0x00000314, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_ROI_6_LAMBDA", 0x00000314, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_7_info
	{ "roi_7_enable", 0x00000318, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_7_mode", 0x00000318, 9, 8, CSR_RW, 0x00000000 },
	{ "roi_7_qp", 0x00000318, 21, 16, CSR_RW, 0x0000001A },
	{ "VENC_ROI_7_INFO", 0x00000318, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_7_x
	{ "roi_7_sx", 0x0000031C, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_7_ex", 0x0000031C, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_7_X", 0x0000031C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_7_y
	{ "roi_7_sy", 0x00000320, 11, 0, CSR_RW, 0x00000000 },
	{ "roi_7_ey", 0x00000320, 27, 16, CSR_RW, 0x00000000 },
	{ "VENC_ROI_7_Y", 0x00000320, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_roi_7_lambda
	{ "roi_7_lambda", 0x00000324, 8, 0, CSR_RW, 0x00000014 },
	{ "roi_7_sao_lambda", 0x00000324, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_ROI_7_LAMBDA", 0x00000324, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_slice_qp
	{ "slice_qp", 0x00000338, 5, 0, CSR_RW, 0x0000001A },
	{ "VENC_SLICE_QP", 0x00000338, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_slice_qp_lambda
	{ "slice_qp_lambda", 0x0000033C, 8, 0, CSR_RW, 0x00000014 },
	{ "slice_qp_sao_lambda", 0x0000033C, 28, 16, CSR_RW, 0x0000000C },
	{ "VENC_SLICE_QP_LAMBDA", 0x0000033C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_debug_mon_sel
	{ "debug_mon_sel", 0x00000340, 2, 0, CSR_RW, 0x00000000 },
	{ "atpg_ctrl", 0x00000340, 9, 8, CSR_RW, 0x00000000 },
	{ "VENC_DEBUG_MON_SEL", 0x00000340, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_debug_mon_reg
	{ "debug_mon_reg", 0x00000344, 31, 0, CSR_RO, 0x00000000 },
	{ "VENC_DEBUG_MON_REG", 0x00000344, 31, 0, CSR_RO, 0x00000000 },
	// WORD venc_reserved_0
	{ "reserved_0", 0x00000348, 31, 0, CSR_RW, 0x00000000 },
	{ "VENC_RESERVED_0", 0x00000348, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_reserved_1
	{ "reserved_1", 0x0000034C, 31, 0, CSR_RW, 0x00000000 },
	{ "VENC_RESERVED_1", 0x0000034C, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_reserved_2
	{ "reserved_2", 0x00000350, 31, 0, CSR_RW, 0x00000000 },
	{ "VENC_RESERVED_2", 0x00000350, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_reserved_3
	{ "reserved_3", 0x00000354, 31, 0, CSR_RW, 0x00000000 },
	{ "VENC_RESERVED_3", 0x00000354, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_VENC_H_
