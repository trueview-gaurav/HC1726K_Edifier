/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_BSP_H_
#define CSR_TABLE_BSP_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_bsp[] = {
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
	// WORD io_format
	{ "cfa_mode", 0x00000010, 1, 0, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase_i", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase_o", 0x00000010, 17, 16, CSR_RW, 0x00000000 },
	{ "mono_o", 0x00000010, 24, 24, CSR_RW, 0x00000000 },
	{ "mode", 0x00000010, 26, 25, CSR_RW, 0x00000000 },
	{ "ink_num", 0x00000010, 30, 27, CSR_RW, 0x00000000 },
	{ "IO_FORMAT", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
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
	{ "WORD_CFA_PHASE_1", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_2
	{ "cfa_phase_8", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_9", 0x0000001C, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_10", 0x0000001C, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_11", 0x0000001C, 26, 24, CSR_RW, 0x00000000 },
	{ "WORD_CFA_PHASE_2", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_3
	{ "cfa_phase_12", 0x00000020, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_13", 0x00000020, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_14", 0x00000020, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_15", 0x00000020, 26, 24, CSR_RW, 0x00000000 },
	{ "WORD_CFA_PHASE_3", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000024, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000024, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD ddpd_en
	{ "ddpd_enable", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "DDPD_EN", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD ddpd_dir_th
	{ "ddpd_dir_straight_th", 0x0000002C, 6, 0, CSR_RW, 0x0000000D },
	{ "ddpd_dir_slash_th", 0x0000002C, 14, 8, CSR_RW, 0x00000010 },
	{ "ddpd_dir_pt_min_th", 0x0000002C, 22, 16, CSR_RW, 0x00000010 },
	{ "ddpd_dir_dp_th", 0x0000002C, 30, 24, CSR_RW, 0x00000028 },
	{ "DDPD_DIR_TH", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ddpd_planar_th
	{ "ddpd_flat_dt_th", 0x00000030, 6, 0, CSR_RW, 0x00000047 },
	{ "ddpd_flat_pix_th", 0x00000030, 14, 8, CSR_RW, 0x0000002E },
	{ "ddpd_smooth_dt_th", 0x00000030, 22, 16, CSR_RW, 0x00000015 },
	{ "ddpd_smooth_pix_th", 0x00000030, 30, 24, CSR_RW, 0x00000000 },
	{ "DDPD_PLANAR_TH", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ddpd_dp_num
	{ "ddpd_dp_num", 0x00000034, 15, 0, CSR_RO, 0x00000000 },
	{ "WORD_DDPD_DP_NUM", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD dpc_en
	{ "dpc_enable", 0x00000038, 0, 0, CSR_RW, 0x00000000 },
	{ "dpc_avg_ratio", 0x00000038, 21, 16, CSR_RW, 0x00000000 },
	{ "DPC_EN", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctc_en
	{ "ctc_enable", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "CTC_EN", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctc_avg
	{ "ctc_avg_lb", 0x00000040, 15, 0, CSR_RW, 0x00000100 },
	{ "ctc_avg_ratio", 0x00000040, 24, 16, CSR_RW, 0x00000020 },
	{ "CTC_AVG", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctc_str
	{ "ctc_corr_region_th", 0x00000044, 6, 0, CSR_RW, 0x00000000 },
	{ "CTC_STR", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctc_corr_val
	{ "ctc_correct_val", 0x00000048, 24, 0, CSR_RO, 0x00000000 },
	{ "CTC_CORR_VAL", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD ctc_str_stat
	{ "ctc_smooth_str", 0x0000004C, 24, 0, CSR_RO, 0x00000000 },
	{ "CTC_STR_STAT", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD ch_weight_0
	{ "channel_weight_00", 0x00000054, 4, 0, CSR_RW, 0x00000001 },
	{ "channel_weight_01", 0x00000054, 12, 8, CSR_RW, 0x00000004 },
	{ "channel_weight_02", 0x00000054, 20, 16, CSR_RW, 0x00000006 },
	{ "CH_WEIGHT_0", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD ch_weight_1
	{ "channel_weight_11", 0x00000058, 6, 0, CSR_RW, 0x00000010 },
	{ "channel_weight_12", 0x00000058, 14, 8, CSR_RW, 0x00000018 },
	{ "channel_weight_22", 0x00000058, 22, 16, CSR_RW, 0x00000024 },
	{ "CH_WEIGHT_1", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_remos_enable
	{ "remos_enable", 0x0000005C, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_REMOS_ENABLE", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD remos_coeff_r_0
	{ "remos_r_r_coeff_2s", 0x00000060, 13, 0, CSR_RW, 0x00000000 },
	{ "remos_r_g_coeff_2s", 0x00000060, 29, 16, CSR_RW, 0x00000000 },
	{ "REMOS_COEFF_R_0", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD remos_coeff_r_1
	{ "remos_r_b_coeff_2s", 0x00000064, 13, 0, CSR_RW, 0x00000000 },
	{ "remos_r_s_coeff_2s", 0x00000064, 29, 16, CSR_RW, 0x00000000 },
	{ "REMOS_COEFF_R_1", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD remos_coeff_g_0
	{ "remos_g_r_coeff_2s", 0x00000068, 13, 0, CSR_RW, 0x00000000 },
	{ "remos_g_g_coeff_2s", 0x00000068, 29, 16, CSR_RW, 0x00000000 },
	{ "REMOS_COEFF_G_0", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD remos_coeff_g_1
	{ "remos_g_b_coeff_2s", 0x0000006C, 13, 0, CSR_RW, 0x00000000 },
	{ "remos_g_s_coeff_2s", 0x0000006C, 29, 16, CSR_RW, 0x00000000 },
	{ "REMOS_COEFF_G_1", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD remos_coeff_b_0
	{ "remos_b_r_coeff_2s", 0x00000070, 13, 0, CSR_RW, 0x00000000 },
	{ "remos_b_g_coeff_2s", 0x00000070, 29, 16, CSR_RW, 0x00000000 },
	{ "REMOS_COEFF_B_0", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD remos_coeff_b_1
	{ "remos_b_b_coeff_2s", 0x00000074, 13, 0, CSR_RW, 0x00000000 },
	{ "remos_b_s_coeff_2s", 0x00000074, 29, 16, CSR_RW, 0x00000000 },
	{ "REMOS_COEFF_B_1", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_y_est_mode
	{ "y_est_mode", 0x00000078, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_Y_EST_MODE", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_est_weight
	{ "y_r_weight", 0x0000007C, 5, 0, CSR_RW, 0x00000007 },
	{ "y_g_weight", 0x0000007C, 13, 8, CSR_RW, 0x00000017 },
	{ "y_b_weight", 0x0000007C, 21, 16, CSR_RW, 0x00000002 },
	{ "y_s_weight", 0x0000007C, 29, 24, CSR_RW, 0x00000000 },
	{ "Y_EST_WEIGHT", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_y_mode
	{ "contrast_y_mode", 0x00000080, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_CONTRAST_Y_MODE", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_y_gain_0
	{ "contrast_y_gain_th_max", 0x00000084, 7, 0, CSR_RW, 0x000000C0 },
	{ "contrast_y_gain_th_min", 0x00000084, 23, 16, CSR_RW, 0x00000040 },
	{ "CONTRAST_Y_GAIN_0", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_y_gain_1
	{ "contrast_y_gain_m", 0x00000088, 4, 0, CSR_RW, 0x00000010 },
	{ "CONTRAST_Y_GAIN_1", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_cfa_enable_0
	{ "contrast_cfa_phase_en_g0", 0x0000008C, 0, 0, CSR_RW, 0x00000001 },
	{ "contrast_cfa_phase_en_r", 0x0000008C, 8, 8, CSR_RW, 0x00000001 },
	{ "contrast_cfa_phase_en_b", 0x0000008C, 16, 16, CSR_RW, 0x00000001 },
	{ "CONTRAST_CFA_ENABLE_0", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_cfa_enable_1
	{ "contrast_cfa_phase_en_g1", 0x00000090, 0, 0, CSR_RW, 0x00000001 },
	{ "contrast_cfa_phase_en_s", 0x00000090, 8, 8, CSR_RW, 0x00000000 },
	{ "CONTRAST_CFA_ENABLE_1", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_h1_weight_0
	{ "contrast_h1_weight_0", 0x00000094, 8, 0, CSR_RW, 0x000000E0 },
	{ "contrast_h1_weight_1", 0x00000094, 24, 16, CSR_RW, 0x00000000 },
	{ "WORD_CONTRAST_H1_WEIGHT_0", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_h1_weight_1
	{ "contrast_h1_weight_2", 0x00000098, 8, 0, CSR_RW, 0x00000020 },
	{ "WORD_CONTRAST_H1_WEIGHT_1", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_h2_weight_0
	{ "contrast_h2_weight_0", 0x0000009C, 8, 0, CSR_RW, 0x000000E0 },
	{ "contrast_h2_weight_1", 0x0000009C, 24, 16, CSR_RW, 0x00000000 },
	{ "WORD_CONTRAST_H2_WEIGHT_0", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_h2_weight_1
	{ "contrast_h2_weight_2", 0x000000A0, 8, 0, CSR_RW, 0x00000020 },
	{ "WORD_CONTRAST_H2_WEIGHT_1", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_v1_weight_0
	{ "contrast_v1_weight_0", 0x000000A4, 8, 0, CSR_RW, 0x000000E0 },
	{ "contrast_v1_weight_1", 0x000000A4, 24, 16, CSR_RW, 0x00000000 },
	{ "WORD_CONTRAST_V1_WEIGHT_0", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_v1_weight_1
	{ "contrast_v1_weight_2", 0x000000A8, 8, 0, CSR_RW, 0x00000020 },
	{ "WORD_CONTRAST_V1_WEIGHT_1", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_v2_weight_0
	{ "contrast_v2_weight_0", 0x000000AC, 8, 0, CSR_RW, 0x000000E0 },
	{ "contrast_v2_weight_1", 0x000000AC, 24, 16, CSR_RW, 0x00000000 },
	{ "WORD_CONTRAST_V2_WEIGHT_0", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_v2_weight_1
	{ "contrast_v2_weight_2", 0x000000B0, 8, 0, CSR_RW, 0x00000020 },
	{ "WORD_CONTRAST_V2_WEIGHT_1", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_contrast_coring_th
	{ "contrast_coring_th", 0x000000B4, 13, 0, CSR_RW, 0x00000020 },
	{ "WORD_CONTRAST_CORING_TH", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_awb_gwd_y_mode
	{ "awb_gwd_y_mode", 0x000000B8, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_AWB_GWD_Y_MODE", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_y_gain_0
	{ "awb_gwd_y_th_max", 0x000000BC, 7, 0, CSR_RW, 0x000000C0 },
	{ "awb_gwd_y_th_min", 0x000000BC, 15, 8, CSR_RW, 0x00000040 },
	{ "awb_gwd_y_slope_max", 0x000000BC, 20, 16, CSR_RW, 0x00000008 },
	{ "awb_gwd_y_slope_min", 0x000000BC, 31, 24, CSR_RW, 0x00000040 },
	{ "AWB_GWD_Y_GAIN_0", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_y_gain_1
	{ "awb_gwd_resample_saturation", 0x000000C0, 0, 0, CSR_RW, 0x00000000 },
	{ "awb_gwd_saturation_th", 0x000000C0, 13, 8, CSR_RW, 0x0000001A },
	{ "awb_gwd_rto_gray_level_slope", 0x000000C0, 18, 16, CSR_RW, 0x00000004 },
	{ "AWB_GWD_Y_GAIN_1", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_rto_sat_0
	{ "awb_gwd_r_bias", 0x000000C4, 11, 0, CSR_RW, 0x00000100 },
	{ "awb_gwd_g_bias", 0x000000C4, 27, 16, CSR_RW, 0x00000100 },
	{ "AWB_GWD_RTO_SAT_0", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_rto_sat_1
	{ "awb_gwd_b_bias", 0x000000C8, 11, 0, CSR_RW, 0x00000100 },
	{ "AWB_GWD_RTO_SAT_1", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_gain_prev_0
	{ "awb_gwd_gain_prev_r", 0x000000CC, 11, 0, CSR_RW, 0x00000100 },
	{ "awb_gwd_gain_prev_g", 0x000000CC, 27, 16, CSR_RW, 0x00000100 },
	{ "AWB_GWD_GAIN_PREV_0", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_gain_prev_1
	{ "awb_gwd_gain_prev_b", 0x000000D0, 11, 0, CSR_RW, 0x00000100 },
	{ "AWB_GWD_GAIN_PREV_1", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_awb_rtx_y_mode
	{ "awb_rtx_y_mode", 0x000000D4, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_AWB_RTX_Y_MODE", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_rtx_cfa_phase_en_0
	{ "awb_cfa_peform_rtx_0", 0x000000D8, 0, 0, CSR_RW, 0x00000000 },
	{ "awb_cfa_peform_rtx_1", 0x000000D8, 8, 8, CSR_RW, 0x00000000 },
	{ "awb_cfa_peform_rtx_2", 0x000000D8, 16, 16, CSR_RW, 0x00000000 },
	{ "awb_cfa_peform_rtx_3", 0x000000D8, 24, 24, CSR_RW, 0x00000000 },
	{ "AWB_RTX_CFA_PHASE_EN_0", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_rtx_cfa_phase_en_1
	{ "awb_cfa_peform_rtx_4", 0x000000DC, 0, 0, CSR_RW, 0x00000000 },
	{ "awb_rtx_force_performed_phase", 0x000000DC, 8, 8, CSR_RW, 0x00000000 },
	{ "AWB_RTX_CFA_PHASE_EN_1", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_rtx_y_gain_0
	{ "awb_rtx_y_th_min", 0x000000E0, 7, 0, CSR_RW, 0x000000C0 },
	{ "awb_rtx_y_th_max", 0x000000E0, 23, 16, CSR_RW, 0x00000040 },
	{ "AWB_RTX_Y_GAIN_0", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_rtx_y_gain_1
	{ "awb_rtx_y_m", 0x000000E4, 4, 0, CSR_RW, 0x00000010 },
	{ "awb_rtx_dyn_range_th", 0x000000E4, 12, 8, CSR_RW, 0x00000010 },
	{ "awb_rtx_dyn_range_slope", 0x000000E4, 19, 16, CSR_RW, 0x00000008 },
	{ "AWB_RTX_Y_GAIN_1", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_en
	{ "tm_enable", 0x000000E8, 0, 0, CSR_RW, 0x00000000 },
	{ "y_lpf_str", 0x000000E8, 20, 16, CSR_RW, 0x00000010 },
	{ "TM_EN", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_0
	{ "tone_curve_0", 0x000000EC, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_1", 0x000000EC, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_0", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_1
	{ "tone_curve_2", 0x000000F0, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_3", 0x000000F0, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_1", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_2
	{ "tone_curve_4", 0x000000F4, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_5", 0x000000F4, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_2", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_3
	{ "tone_curve_6", 0x000000F8, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_7", 0x000000F8, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_3", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_4
	{ "tone_curve_8", 0x000000FC, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_9", 0x000000FC, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_4", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_5
	{ "tone_curve_10", 0x00000100, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_11", 0x00000100, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_5", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_6
	{ "tone_curve_12", 0x00000104, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_13", 0x00000104, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_6", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_7
	{ "tone_curve_14", 0x00000108, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_15", 0x00000108, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_7", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_8
	{ "tone_curve_16", 0x0000010C, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_17", 0x0000010C, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_8", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_9
	{ "tone_curve_18", 0x00000110, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_19", 0x00000110, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_9", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_10
	{ "tone_curve_20", 0x00000114, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_21", 0x00000114, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_10", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_11
	{ "tone_curve_22", 0x00000118, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_23", 0x00000118, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_11", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_12
	{ "tone_curve_24", 0x0000011C, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_25", 0x0000011C, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_12", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_13
	{ "tone_curve_26", 0x00000120, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_27", 0x00000120, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_13", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_14
	{ "tone_curve_28", 0x00000124, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_29", 0x00000124, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_14", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_15
	{ "tone_curve_30", 0x00000128, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_31", 0x00000128, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_15", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_16
	{ "tone_curve_32", 0x0000012C, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_33", 0x0000012C, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_16", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_17
	{ "tone_curve_34", 0x00000130, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_35", 0x00000130, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_17", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_18
	{ "tone_curve_36", 0x00000134, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_37", 0x00000134, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_18", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_19
	{ "tone_curve_38", 0x00000138, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_39", 0x00000138, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_19", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_20
	{ "tone_curve_40", 0x0000013C, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_41", 0x0000013C, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_20", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_21
	{ "tone_curve_42", 0x00000140, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_43", 0x00000140, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_21", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_22
	{ "tone_curve_44", 0x00000144, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_45", 0x00000144, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_22", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_23
	{ "tone_curve_46", 0x00000148, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_47", 0x00000148, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_23", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_24
	{ "tone_curve_48", 0x0000014C, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_49", 0x0000014C, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_24", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_25
	{ "tone_curve_50", 0x00000150, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_51", 0x00000150, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_25", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_26
	{ "tone_curve_52", 0x00000154, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_53", 0x00000154, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_26", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_27
	{ "tone_curve_54", 0x00000158, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_55", 0x00000158, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_27", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_28
	{ "tone_curve_56", 0x0000015C, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_57", 0x0000015C, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_28", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD tm_strl_29
	{ "tone_curve_58", 0x00000160, 13, 0, CSR_RW, 0x00000100 },
	{ "tone_curve_59", 0x00000160, 29, 16, CSR_RW, 0x00000100 },
	{ "TM_STRL_29", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_wb_enable
	{ "wb_enable", 0x00000164, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_WB_ENABLE", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_bilinear_0
	{ "awb_bilinear_en", 0x00000168, 0, 0, CSR_RW, 0x00000001 },
	{ "AWB_BILINEAR_0", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_bilinear_1
	{ "awb_bi_rgl_x_cnt_ini", 0x0000016C, 24, 0, CSR_RW, 0x00000000 },
	{ "AWB_BILINEAR_1", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_bilinear_2
	{ "awb_bi_rgl_y_cnt_ini", 0x00000170, 24, 0, CSR_RW, 0x00000000 },
	{ "AWB_BILINEAR_2", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_bilinear_3
	{ "awb_binear_rgl_x_cnt_step", 0x00000174, 21, 0, CSR_RW, 0x00000000 },
	{ "AWB_BILINEAR_3", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_bilinear_4
	{ "awb_binear_rgl_y_cnt_step", 0x00000178, 21, 0, CSR_RW, 0x00000000 },
	{ "AWB_BILINEAR_4", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_bilinear_5
	{ "awb_binear_rgl_size_x", 0x0000017C, 10, 0, CSR_RW, 0x00000000 },
	{ "AWB_BILINEAR_5", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_bilinear_6
	{ "awb_binear_rgl_size_y", 0x00000180, 10, 0, CSR_RW, 0x00000000 },
	{ "AWB_BILINEAR_6", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_0_0
	{ "wb_gain_g0_0", 0x00000184, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_0", 0x00000184, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_0_0", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_0_1
	{ "wb_gain_b_0", 0x00000188, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_0", 0x00000188, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_0_1", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_1_0
	{ "wb_gain_g0_1", 0x0000018C, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_1", 0x0000018C, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_1_0", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_1_1
	{ "wb_gain_b_1", 0x00000190, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_1", 0x00000190, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_1_1", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_2_0
	{ "wb_gain_g0_2", 0x00000194, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_2", 0x00000194, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_2_0", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_2_1
	{ "wb_gain_b_2", 0x00000198, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_2", 0x00000198, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_2_1", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_3_0
	{ "wb_gain_g0_3", 0x0000019C, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_3", 0x0000019C, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_3_0", 0x0000019C, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_3_1
	{ "wb_gain_b_3", 0x000001A0, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_3", 0x000001A0, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_3_1", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_4_0
	{ "wb_gain_g0_4", 0x000001A4, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_4", 0x000001A4, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_4_0", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_4_1
	{ "wb_gain_b_4", 0x000001A8, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_4", 0x000001A8, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_4_1", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_5_0
	{ "wb_gain_g0_5", 0x000001AC, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_5", 0x000001AC, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_5_0", 0x000001AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_5_1
	{ "wb_gain_b_5", 0x000001B0, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_5", 0x000001B0, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_5_1", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_6_0
	{ "wb_gain_g0_6", 0x000001B4, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_6", 0x000001B4, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_6_0", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_6_1
	{ "wb_gain_b_6", 0x000001B8, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_6", 0x000001B8, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_6_1", 0x000001B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_7_0
	{ "wb_gain_g0_7", 0x000001BC, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_7", 0x000001BC, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_7_0", 0x000001BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_7_1
	{ "wb_gain_b_7", 0x000001C0, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_7", 0x000001C0, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_7_1", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_8_0
	{ "wb_gain_g0_8", 0x000001C4, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_8", 0x000001C4, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_8_0", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_8_1
	{ "wb_gain_b_8", 0x000001C8, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_8", 0x000001C8, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_8_1", 0x000001C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_9_0
	{ "wb_gain_g0_9", 0x000001CC, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_9", 0x000001CC, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_9_0", 0x000001CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_9_1
	{ "wb_gain_b_9", 0x000001D0, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_9", 0x000001D0, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_9_1", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_10_0
	{ "wb_gain_g0_10", 0x000001D4, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_10", 0x000001D4, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_10_0", 0x000001D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_10_1
	{ "wb_gain_b_10", 0x000001D8, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_10", 0x000001D8, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_10_1", 0x000001D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_11_0
	{ "wb_gain_g0_11", 0x000001DC, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_11", 0x000001DC, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_11_0", 0x000001DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_11_1
	{ "wb_gain_b_11", 0x000001E0, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_11", 0x000001E0, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_11_1", 0x000001E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_12_0
	{ "wb_gain_g0_12", 0x000001E4, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_12", 0x000001E4, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_12_0", 0x000001E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_12_1
	{ "wb_gain_b_12", 0x000001E8, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_12", 0x000001E8, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_12_1", 0x000001E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_13_0
	{ "wb_gain_g0_13", 0x000001EC, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_13", 0x000001EC, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_13_0", 0x000001EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_13_1
	{ "wb_gain_b_13", 0x000001F0, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_13", 0x000001F0, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_13_1", 0x000001F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_14_0
	{ "wb_gain_g0_14", 0x000001F4, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_14", 0x000001F4, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_14_0", 0x000001F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_14_1
	{ "wb_gain_b_14", 0x000001F8, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_14", 0x000001F8, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_14_1", 0x000001F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_15_0
	{ "wb_gain_g0_15", 0x000001FC, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_r_15", 0x000001FC, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_15_0", 0x000001FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wb_gain_15_1
	{ "wb_gain_b_15", 0x00000200, 11, 0, CSR_RW, 0x00000100 },
	{ "wb_gain_g1_15", 0x00000200, 27, 16, CSR_RW, 0x00000100 },
	{ "WB_GAIN_15_1", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_hist_mode
	{ "y_hist_in_mode", 0x00000204, 1, 0, CSR_RW, 0x00000000 },
	{ "y_hist_roi_en", 0x00000204, 16, 16, CSR_RW, 0x00000000 },
	{ "Y_HIST_MODE", 0x00000204, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_y_hist_overflow
	{ "y_hist_overflow", 0x00000208, 0, 0, CSR_RO, 0x00000000 },
	{ "WORD_Y_HIST_OVERFLOW", 0x00000208, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_roi_x
	{ "y_hist_roi_sx", 0x0000020C, 15, 0, CSR_RW, 0x00000000 },
	{ "y_hist_roi_ex", 0x0000020C, 31, 16, CSR_RW, 0x00000780 },
	{ "Y_HIST_ROI_X", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_hist_roi_y
	{ "y_hist_roi_sy", 0x00000210, 15, 0, CSR_RW, 0x00000000 },
	{ "y_hist_roi_ey", 0x00000210, 31, 16, CSR_RW, 0x00000438 },
	{ "Y_HIST_ROI_Y", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_y_hist_offset
	{ "y_hist_offset", 0x00000214, 13, 0, CSR_RW, 0x00000000 },
	{ "WORD_Y_HIST_OFFSET", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_hist_0
	{ "y_hist_hist_0", 0x00000218, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_0", 0x00000218, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_1
	{ "y_hist_hist_1", 0x0000021C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_1", 0x0000021C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_2
	{ "y_hist_hist_2", 0x00000220, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_2", 0x00000220, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_3
	{ "y_hist_hist_3", 0x00000224, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_3", 0x00000224, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_4
	{ "y_hist_hist_4", 0x00000228, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_4", 0x00000228, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_5
	{ "y_hist_hist_5", 0x0000022C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_5", 0x0000022C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_6
	{ "y_hist_hist_6", 0x00000230, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_6", 0x00000230, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_7
	{ "y_hist_hist_7", 0x00000234, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_7", 0x00000234, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_8
	{ "y_hist_hist_8", 0x00000238, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_8", 0x00000238, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_9
	{ "y_hist_hist_9", 0x0000023C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_9", 0x0000023C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_10
	{ "y_hist_hist_10", 0x00000240, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_10", 0x00000240, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_11
	{ "y_hist_hist_11", 0x00000244, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_11", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_12
	{ "y_hist_hist_12", 0x00000248, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_12", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_13
	{ "y_hist_hist_13", 0x0000024C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_13", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_14
	{ "y_hist_hist_14", 0x00000250, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_14", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_15
	{ "y_hist_hist_15", 0x00000254, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_15", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_16
	{ "y_hist_hist_16", 0x00000258, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_16", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_17
	{ "y_hist_hist_17", 0x0000025C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_17", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_18
	{ "y_hist_hist_18", 0x00000260, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_18", 0x00000260, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_19
	{ "y_hist_hist_19", 0x00000264, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_19", 0x00000264, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_20
	{ "y_hist_hist_20", 0x00000268, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_20", 0x00000268, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_21
	{ "y_hist_hist_21", 0x0000026C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_21", 0x0000026C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_22
	{ "y_hist_hist_22", 0x00000270, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_22", 0x00000270, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_23
	{ "y_hist_hist_23", 0x00000274, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_23", 0x00000274, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_24
	{ "y_hist_hist_24", 0x00000278, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_24", 0x00000278, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_25
	{ "y_hist_hist_25", 0x0000027C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_25", 0x0000027C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_26
	{ "y_hist_hist_26", 0x00000280, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_26", 0x00000280, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_27
	{ "y_hist_hist_27", 0x00000284, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_27", 0x00000284, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_28
	{ "y_hist_hist_28", 0x00000288, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_28", 0x00000288, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_29
	{ "y_hist_hist_29", 0x0000028C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_29", 0x0000028C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_30
	{ "y_hist_hist_30", 0x00000290, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_30", 0x00000290, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_31
	{ "y_hist_hist_31", 0x00000294, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_31", 0x00000294, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_32
	{ "y_hist_hist_32", 0x00000298, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_32", 0x00000298, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_33
	{ "y_hist_hist_33", 0x0000029C, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_33", 0x0000029C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_34
	{ "y_hist_hist_34", 0x000002A0, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_34", 0x000002A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_35
	{ "y_hist_hist_35", 0x000002A4, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_35", 0x000002A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_36
	{ "y_hist_hist_36", 0x000002A8, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_36", 0x000002A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_37
	{ "y_hist_hist_37", 0x000002AC, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_37", 0x000002AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_38
	{ "y_hist_hist_38", 0x000002B0, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_38", 0x000002B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_39
	{ "y_hist_hist_39", 0x000002B4, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_39", 0x000002B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_40
	{ "y_hist_hist_40", 0x000002B8, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_40", 0x000002B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_41
	{ "y_hist_hist_41", 0x000002BC, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_41", 0x000002BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_42
	{ "y_hist_hist_42", 0x000002C0, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_42", 0x000002C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_43
	{ "y_hist_hist_43", 0x000002C4, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_43", 0x000002C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_44
	{ "y_hist_hist_44", 0x000002C8, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_44", 0x000002C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_45
	{ "y_hist_hist_45", 0x000002CC, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_45", 0x000002CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_46
	{ "y_hist_hist_46", 0x000002D0, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_46", 0x000002D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_47
	{ "y_hist_hist_47", 0x000002D4, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_47", 0x000002D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_48
	{ "y_hist_hist_48", 0x000002D8, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_48", 0x000002D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_49
	{ "y_hist_hist_49", 0x000002DC, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_49", 0x000002DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_50
	{ "y_hist_hist_50", 0x000002E0, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_50", 0x000002E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_51
	{ "y_hist_hist_51", 0x000002E4, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_51", 0x000002E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_52
	{ "y_hist_hist_52", 0x000002E8, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_52", 0x000002E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_53
	{ "y_hist_hist_53", 0x000002EC, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_53", 0x000002EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_54
	{ "y_hist_hist_54", 0x000002F0, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_54", 0x000002F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_55
	{ "y_hist_hist_55", 0x000002F4, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_55", 0x000002F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_56
	{ "y_hist_hist_56", 0x000002F8, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_56", 0x000002F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_57
	{ "y_hist_hist_57", 0x000002FC, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_57", 0x000002FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_58
	{ "y_hist_hist_58", 0x00000300, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_58", 0x00000300, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_hist_59
	{ "y_hist_hist_59", 0x00000304, 17, 0, CSR_RO, 0x00000000 },
	{ "Y_HIST_59", 0x00000304, 31, 0, CSR_RO, 0x00000000 },
	// WORD roi_y_avg_mode
	{ "roi_y_avg_in_mode", 0x00000308, 1, 0, CSR_RW, 0x00000000 },
	{ "ROI_Y_AVG_MODE", 0x00000308, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_y_avg_enable
	{ "roi_0_y_avg_en", 0x0000030C, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_1_y_avg_en", 0x0000030C, 8, 8, CSR_RW, 0x00000000 },
	{ "roi_2_y_avg_en", 0x0000030C, 16, 16, CSR_RW, 0x00000000 },
	{ "roi_3_y_avg_en", 0x0000030C, 24, 24, CSR_RW, 0x00000000 },
	{ "ROI_Y_AVG_ENABLE", 0x0000030C, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_0_x
	{ "roi_0_y_avg_sx", 0x00000310, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_0_y_avg_ex", 0x00000310, 31, 16, CSR_RW, 0x00000780 },
	{ "Y_AVG_ROI_0_X", 0x00000310, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_0_y
	{ "roi_0_y_avg_sy", 0x00000314, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_0_y_avg_ey", 0x00000314, 31, 16, CSR_RW, 0x00000438 },
	{ "Y_AVG_ROI_0_Y", 0x00000314, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_1_x
	{ "roi_1_y_avg_sx", 0x00000318, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_1_y_avg_ex", 0x00000318, 31, 16, CSR_RW, 0x00000780 },
	{ "Y_AVG_ROI_1_X", 0x00000318, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_1_y
	{ "roi_1_y_avg_sy", 0x0000031C, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_1_y_avg_ey", 0x0000031C, 31, 16, CSR_RW, 0x00000438 },
	{ "Y_AVG_ROI_1_Y", 0x0000031C, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_2_x
	{ "roi_2_y_avg_sx", 0x00000320, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_2_y_avg_ex", 0x00000320, 31, 16, CSR_RW, 0x00000780 },
	{ "Y_AVG_ROI_2_X", 0x00000320, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_2_y
	{ "roi_2_y_avg_sy", 0x00000324, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_2_y_avg_ey", 0x00000324, 31, 16, CSR_RW, 0x00000438 },
	{ "Y_AVG_ROI_2_Y", 0x00000324, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_3_x
	{ "roi_3_y_avg_sx", 0x00000328, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_3_y_avg_ex", 0x00000328, 31, 16, CSR_RW, 0x00000780 },
	{ "Y_AVG_ROI_3_X", 0x00000328, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_3_y
	{ "roi_3_y_avg_sy", 0x0000032C, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_3_y_avg_ey", 0x0000032C, 31, 16, CSR_RW, 0x00000438 },
	{ "Y_AVG_ROI_3_Y", 0x0000032C, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_pix_num_0
	{ "roi_0_y_avg_pix_num", 0x00000330, 22, 0, CSR_RW, 0x00000000 },
	{ "Y_AVG_ROI_PIX_NUM_0", 0x00000330, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_pix_num_1
	{ "roi_1_y_avg_pix_num", 0x00000334, 22, 0, CSR_RW, 0x00000000 },
	{ "Y_AVG_ROI_PIX_NUM_1", 0x00000334, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_pix_num_2
	{ "roi_2_y_avg_pix_num", 0x00000338, 22, 0, CSR_RW, 0x00000000 },
	{ "Y_AVG_ROI_PIX_NUM_2", 0x00000338, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_pix_num_3
	{ "roi_3_y_avg_pix_num", 0x0000033C, 22, 0, CSR_RW, 0x00000000 },
	{ "Y_AVG_ROI_PIX_NUM_3", 0x0000033C, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_avg_roi_remainder_0
	{ "roi_0_y_avg_remainder", 0x00000340, 22, 0, CSR_RO, 0x00000000 },
	{ "Y_AVG_ROI_REMAINDER_0", 0x00000340, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_avg_roi_remainder_1
	{ "roi_1_y_avg_remainder", 0x00000344, 22, 0, CSR_RO, 0x00000000 },
	{ "Y_AVG_ROI_REMAINDER_1", 0x00000344, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_avg_roi_remainder_2
	{ "roi_2_y_avg_remainder", 0x00000348, 22, 0, CSR_RO, 0x00000000 },
	{ "Y_AVG_ROI_REMAINDER_2", 0x00000348, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_avg_roi_remainder_3
	{ "roi_3_y_avg_remainder", 0x0000034C, 22, 0, CSR_RO, 0x00000000 },
	{ "Y_AVG_ROI_REMAINDER_3", 0x0000034C, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_avg_roi_pix_avg_0
	{ "roi_0_y_avg_avg", 0x00000350, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_1_y_avg_avg", 0x00000350, 29, 16, CSR_RO, 0x00000000 },
	{ "Y_AVG_ROI_PIX_AVG_0", 0x00000350, 31, 0, CSR_RO, 0x00000000 },
	// WORD y_avg_roi_pix_avg_1
	{ "roi_2_y_avg_avg", 0x00000354, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_3_y_avg_avg", 0x00000354, 29, 16, CSR_RO, 0x00000000 },
	{ "Y_AVG_ROI_PIX_AVG_1", 0x00000354, 31, 0, CSR_RO, 0x00000000 },
	// WORD roi_contrast_enable
	{ "roi_0_contrast_en", 0x00000358, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_1_contrast_en", 0x00000358, 8, 8, CSR_RW, 0x00000000 },
	{ "roi_2_contrast_en", 0x00000358, 16, 16, CSR_RW, 0x00000000 },
	{ "roi_3_contrast_en", 0x00000358, 24, 24, CSR_RW, 0x00000000 },
	{ "ROI_CONTRAST_ENABLE", 0x00000358, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_roi_0_x
	{ "roi_0_contrast_sx", 0x0000035C, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_0_contrast_ex", 0x0000035C, 31, 16, CSR_RW, 0x00000780 },
	{ "CONTRAST_ROI_0_X", 0x0000035C, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_roi_0_y
	{ "roi_0_contrast_sy", 0x00000360, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_0_contrast_ey", 0x00000360, 31, 16, CSR_RW, 0x00000438 },
	{ "CONTRAST_ROI_0_Y", 0x00000360, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_roi_1_x
	{ "roi_1_contrast_sx", 0x00000364, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_1_contrast_ex", 0x00000364, 31, 16, CSR_RW, 0x00000780 },
	{ "CONTRAST_ROI_1_X", 0x00000364, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_roi_1_y
	{ "roi_1_contrast_sy", 0x00000368, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_1_contrast_ey", 0x00000368, 31, 16, CSR_RW, 0x00000438 },
	{ "CONTRAST_ROI_1_Y", 0x00000368, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_roi_2_x
	{ "roi_2_contrast_sx", 0x0000036C, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_2_contrast_ex", 0x0000036C, 31, 16, CSR_RW, 0x00000780 },
	{ "CONTRAST_ROI_2_X", 0x0000036C, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_roi_2_y
	{ "roi_2_contrast_sy", 0x00000370, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_2_contrast_ey", 0x00000370, 31, 16, CSR_RW, 0x00000438 },
	{ "CONTRAST_ROI_2_Y", 0x00000370, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_roi_3_x
	{ "roi_3_contrast_sx", 0x00000374, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_3_contrast_ex", 0x00000374, 31, 16, CSR_RW, 0x00000780 },
	{ "CONTRAST_ROI_3_X", 0x00000374, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_roi_3_y
	{ "roi_3_contrast_sy", 0x00000378, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_3_contrast_ey", 0x00000378, 31, 16, CSR_RW, 0x00000438 },
	{ "CONTRAST_ROI_3_Y", 0x00000378, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_pix_num_0
	{ "roi_0_contrast_pix_num", 0x0000037C, 22, 0, CSR_RW, 0x00000000 },
	{ "CONTRAST_PIX_NUM_0", 0x0000037C, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_pix_num_1
	{ "roi_1_contrast_pix_num", 0x00000380, 22, 0, CSR_RW, 0x00000000 },
	{ "CONTRAST_PIX_NUM_1", 0x00000380, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_pix_num_2
	{ "roi_2_contrast_pix_num", 0x00000384, 22, 0, CSR_RW, 0x00000000 },
	{ "CONTRAST_PIX_NUM_2", 0x00000384, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_pix_num_3
	{ "roi_3_contrast_pix_num", 0x00000388, 22, 0, CSR_RW, 0x00000000 },
	{ "CONTRAST_PIX_NUM_3", 0x00000388, 31, 0, CSR_RW, 0x00000000 },
	// WORD contrast_h1_avg_0
	{ "roi_0_contrast_h1_avg", 0x0000038C, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_1_contrast_h1_avg", 0x0000038C, 29, 16, CSR_RO, 0x00000000 },
	{ "CONTRAST_H1_AVG_0", 0x0000038C, 31, 0, CSR_RO, 0x00000000 },
	// WORD contrast_h1_avg_1
	{ "roi_2_contrast_h1_avg", 0x00000390, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_3_contrast_h1_avg", 0x00000390, 29, 16, CSR_RO, 0x00000000 },
	{ "CONTRAST_H1_AVG_1", 0x00000390, 31, 0, CSR_RO, 0x00000000 },
	// WORD contrast_h2_avg_0
	{ "roi_0_contrast_h2_avg", 0x00000394, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_1_contrast_h2_avg", 0x00000394, 29, 16, CSR_RO, 0x00000000 },
	{ "CONTRAST_H2_AVG_0", 0x00000394, 31, 0, CSR_RO, 0x00000000 },
	// WORD contrast_h2_avg_1
	{ "roi_2_contrast_h2_avg", 0x00000398, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_3_contrast_h2_avg", 0x00000398, 29, 16, CSR_RO, 0x00000000 },
	{ "CONTRAST_H2_AVG_1", 0x00000398, 31, 0, CSR_RO, 0x00000000 },
	// WORD contrast_v1_avg_0
	{ "roi_0_contrast_v1_avg", 0x0000039C, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_1_contrast_v1_avg", 0x0000039C, 29, 16, CSR_RO, 0x00000000 },
	{ "CONTRAST_V1_AVG_0", 0x0000039C, 31, 0, CSR_RO, 0x00000000 },
	// WORD contrast_v1_avg_1
	{ "roi_2_contrast_v1_avg", 0x000003A0, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_3_contrast_v1_avg", 0x000003A0, 29, 16, CSR_RO, 0x00000000 },
	{ "CONTRAST_V1_AVG_1", 0x000003A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD contrast_v2_avg_0
	{ "roi_0_contrast_v2_avg", 0x000003A4, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_1_contrast_v2_avg", 0x000003A4, 29, 16, CSR_RO, 0x00000000 },
	{ "CONTRAST_V2_AVG_0", 0x000003A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD contrast_v2_avg_1
	{ "roi_2_contrast_v2_avg", 0x000003A8, 13, 0, CSR_RO, 0x00000000 },
	{ "roi_3_contrast_v2_avg", 0x000003A8, 29, 16, CSR_RO, 0x00000000 },
	{ "CONTRAST_V2_AVG_1", 0x000003A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD roi_awb_gwd_enable
	{ "roi_0_awb_gwd_en", 0x000003AC, 0, 0, CSR_RW, 0x00000000 },
	{ "ROI_AWB_GWD_ENABLE", 0x000003AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_roi_0_x
	{ "roi_0_awb_gwd_sx", 0x000003B0, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_0_awb_gwd_ex", 0x000003B0, 31, 16, CSR_RW, 0x00000780 },
	{ "AWB_GWD_ROI_0_X", 0x000003B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_roi_0_y
	{ "roi_0_awb_gwd_sy", 0x000003B4, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_0_awb_gwd_ey", 0x000003B4, 31, 16, CSR_RW, 0x00000438 },
	{ "AWB_GWD_ROI_0_Y", 0x000003B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_gwd_sum_g0_0
	{ "roi_0_awb_gwd_sum_g0", 0x000003B8, 31, 0, CSR_RO, 0x00000000 },
	{ "AWB_GWD_SUM_G0_0", 0x000003B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD awb_gwd_sum_r_0
	{ "roi_0_awb_gwd_sum_r", 0x000003BC, 31, 0, CSR_RO, 0x00000000 },
	{ "AWB_GWD_SUM_R_0", 0x000003BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD awb_gwd_sum_b_0
	{ "roi_0_awb_gwd_sum_b", 0x000003C0, 31, 0, CSR_RO, 0x00000000 },
	{ "AWB_GWD_SUM_B_0", 0x000003C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD awb_gwd_sum_g1_0
	{ "roi_0_awb_gwd_sum_g1", 0x000003C4, 31, 0, CSR_RO, 0x00000000 },
	{ "AWB_GWD_SUM_G1_0", 0x000003C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD awb_gwd_norm_g0_0
	{ "roi_0_awb_gwd_norm_g0", 0x000003C8, 23, 0, CSR_RO, 0x00000000 },
	{ "AWB_GWD_NORM_G0_0", 0x000003C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD awb_gwd_norm_r_0
	{ "roi_0_awb_gwd_norm_r", 0x000003CC, 23, 0, CSR_RO, 0x00000000 },
	{ "AWB_GWD_NORM_R_0", 0x000003CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD awb_gwd_norm_b_0
	{ "roi_0_awb_gwd_norm_b", 0x000003D0, 23, 0, CSR_RO, 0x00000000 },
	{ "AWB_GWD_NORM_B_0", 0x000003D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD awb_gwd_norm_g1_0
	{ "roi_0_awb_gwd_norm_g1", 0x000003D4, 23, 0, CSR_RO, 0x00000000 },
	{ "AWB_GWD_NORM_G1_0", 0x000003D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD rgl_y_avg_mode
	{ "rgl_y_avg_en", 0x000003D8, 0, 0, CSR_RW, 0x00000000 },
	{ "rgl_y_avg_in_mode", 0x000003D8, 17, 16, CSR_RW, 0x00000000 },
	{ "RGL_Y_AVG_MODE", 0x000003D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_avg_blk
	{ "rgl_y_avg_blk_ht", 0x000003DC, 13, 0, CSR_RW, 0x0000005A },
	{ "rgl_y_avg_blk_wd", 0x000003DC, 29, 16, CSR_RW, 0x00000078 },
	{ "RGL_Y_AVG_BLK", 0x000003DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_y_avg_pix_num
	{ "rgl_y_avg_pix_num", 0x000003E0, 17, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_Y_AVG_PIX_NUM", 0x000003E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_avg_x
	{ "rgl_y_avg_sx", 0x000003E4, 15, 0, CSR_RW, 0x00000000 },
	{ "rgl_y_avg_ex", 0x000003E4, 31, 16, CSR_RW, 0x00000780 },
	{ "RGL_Y_AVG_X", 0x000003E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_avg_y
	{ "rgl_y_avg_sy", 0x000003E8, 15, 0, CSR_RW, 0x00000000 },
	{ "rgl_y_avg_ey", 0x000003E8, 31, 16, CSR_RW, 0x00000438 },
	{ "RGL_Y_AVG_Y", 0x000003E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_contrast_mode
	{ "rgl_contrast_en", 0x000003EC, 0, 0, CSR_RW, 0x00000000 },
	{ "RGL_CONTRAST_MODE", 0x000003EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_contrast_blk
	{ "rgl_contrast_blk_ht", 0x000003F0, 13, 0, CSR_RW, 0x0000005A },
	{ "rgl_contrast_blk_wd", 0x000003F0, 29, 16, CSR_RW, 0x00000078 },
	{ "RGL_CONTRAST_BLK", 0x000003F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_contrast_pix_num
	{ "rgl_contrast_pix_num", 0x000003F4, 17, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_CONTRAST_PIX_NUM", 0x000003F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_contrast_x
	{ "rgl_contrast_sx", 0x000003F8, 15, 0, CSR_RW, 0x00000000 },
	{ "rgl_contrast_ex", 0x000003F8, 31, 16, CSR_RW, 0x00000780 },
	{ "RGL_CONTRAST_X", 0x000003F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_contrast_y
	{ "rgl_contrast_sy", 0x000003FC, 15, 0, CSR_RW, 0x00000000 },
	{ "rgl_contrast_ey", 0x000003FC, 31, 16, CSR_RW, 0x00000438 },
	{ "RGL_CONTRAST_Y", 0x000003FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_awb_rtx_mode
	{ "rgl_awb_rtx_en", 0x00000400, 0, 0, CSR_RW, 0x00000000 },
	{ "RGL_AWB_RTX_MODE", 0x00000400, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_awb_rtx_blk
	{ "rgl_awb_rtx_blk_ht", 0x00000404, 13, 0, CSR_RW, 0x0000005A },
	{ "rgl_awb_rtx_blk_wd", 0x00000404, 29, 16, CSR_RW, 0x00000078 },
	{ "RGL_AWB_RTX_BLK", 0x00000404, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_awb_rtx_x
	{ "rgl_awb_rtx_sx", 0x00000408, 15, 0, CSR_RW, 0x00000000 },
	{ "rgl_awb_rtx_ex", 0x00000408, 31, 16, CSR_RW, 0x00000780 },
	{ "RGL_AWB_RTX_X", 0x00000408, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_awb_rtx_y
	{ "rgl_awb_rtx_sy", 0x0000040C, 15, 0, CSR_RW, 0x00000000 },
	{ "rgl_awb_rtx_ey", 0x0000040C, 31, 16, CSR_RW, 0x00000438 },
	{ "RGL_AWB_RTX_Y", 0x0000040C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_csr2sram_sel
	{ "csr2sram_sel", 0x00000410, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_CSR2SRAM_SEL", 0x00000410, 31, 0, CSR_RW, 0x00000000 },
	// WORD ae_rgl_addr
	{ "ae_rgl_y_avg_r_addr", 0x00000414, 5, 0, CSR_RW, 0x00000000 },
	{ "AE_RGL_ADDR", 0x00000414, 31, 0, CSR_RW, 0x00000000 },
	// WORD af_rgl_addr
	{ "af_rgl_h1h2v1v2_avg_r_addr", 0x00000418, 5, 0, CSR_RW, 0x00000000 },
	{ "AF_RGL_ADDR", 0x00000418, 31, 0, CSR_RW, 0x00000000 },
	// WORD awb_rgl_rtx_addr
	{ "awb_rtx_avg_r_addr", 0x0000041C, 5, 0, CSR_RW, 0x00000000 },
	{ "AWB_RGL_RTX_ADDR", 0x0000041C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ae_rgl_r_data
	{ "ae_rgl_y_avg_r_data", 0x00000420, 7, 0, CSR_RO, 0x00000000 },
	{ "AE_RGL_R_DATA", 0x00000420, 31, 0, CSR_RO, 0x00000000 },
	// WORD af_rgl_r_data
	{ "af_rgl_h1h2v1v2_avg_r_data", 0x00000424, 13, 0, CSR_RO, 0x00000000 },
	{ "AF_RGL_R_DATA", 0x00000424, 31, 0, CSR_RO, 0x00000000 },
	// WORD awb_rgl_rtx_r_data
	{ "awb_rtx_avg_r_data", 0x00000428, 29, 0, CSR_RO, 0x00000000 },
	{ "AWB_RGL_RTX_R_DATA", 0x00000428, 31, 0, CSR_RO, 0x00000000 },
	// WORD cfa_phase_en_set_0
	{ "cfa_phase_en_0", 0x0000042C, 0, 0, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_1", 0x0000042C, 8, 8, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_2", 0x0000042C, 16, 16, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_3", 0x0000042C, 24, 24, CSR_RW, 0x00000001 },
	{ "CFA_PHASE_EN_SET_0", 0x0000042C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_phase_en_set_1
	{ "cfa_phase_en_4", 0x00000430, 0, 0, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_5", 0x00000430, 8, 8, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_6", 0x00000430, 16, 16, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_7", 0x00000430, 24, 24, CSR_RW, 0x00000001 },
	{ "CFA_PHASE_EN_SET_1", 0x00000430, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_phase_en_set_2
	{ "cfa_phase_en_8", 0x00000434, 0, 0, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_9", 0x00000434, 8, 8, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_10", 0x00000434, 16, 16, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_11", 0x00000434, 24, 24, CSR_RW, 0x00000001 },
	{ "CFA_PHASE_EN_SET_2", 0x00000434, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_phase_en_set_3
	{ "cfa_phase_en_12", 0x00000438, 0, 0, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_13", 0x00000438, 8, 8, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_14", 0x00000438, 16, 16, CSR_RW, 0x00000001 },
	{ "cfa_phase_en_15", 0x00000438, 24, 24, CSR_RW, 0x00000001 },
	{ "CFA_PHASE_EN_SET_3", 0x00000438, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgb_hist_ctrl
	{ "rgb_hist_roi_en", 0x0000043C, 0, 0, CSR_RW, 0x00000000 },
	{ "rgb_hist_offset", 0x0000043C, 29, 16, CSR_RW, 0x00000000 },
	{ "RGB_HIST_CTRL", 0x0000043C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgb_hist_stat
	{ "r_hist_overflow", 0x00000440, 0, 0, CSR_RO, 0x00000000 },
	{ "g_hist_overflow", 0x00000440, 8, 8, CSR_RO, 0x00000000 },
	{ "b_hist_overflow", 0x00000440, 16, 16, CSR_RO, 0x00000000 },
	{ "RGB_HIST_STAT", 0x00000440, 31, 0, CSR_RO, 0x00000000 },
	// WORD rgb_hist_roi_x
	{ "rgb_hist_roi_sx", 0x00000444, 15, 0, CSR_RW, 0x00000000 },
	{ "rgb_hist_roi_ex", 0x00000444, 31, 16, CSR_RW, 0x00000780 },
	{ "RGB_HIST_ROI_X", 0x00000444, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgb_hist_roi_y
	{ "rgb_hist_roi_sy", 0x00000448, 15, 0, CSR_RW, 0x00000000 },
	{ "rgb_hist_roi_ey", 0x00000448, 31, 16, CSR_RW, 0x00000438 },
	{ "RGB_HIST_ROI_Y", 0x00000448, 31, 0, CSR_RW, 0x00000000 },
	// WORD r_hist_0
	{ "r_hist_hist_0", 0x0000044C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_0", 0x0000044C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_1
	{ "r_hist_hist_1", 0x00000450, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_1", 0x00000450, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_2
	{ "r_hist_hist_2", 0x00000454, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_2", 0x00000454, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_3
	{ "r_hist_hist_3", 0x00000458, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_3", 0x00000458, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_4
	{ "r_hist_hist_4", 0x0000045C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_4", 0x0000045C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_5
	{ "r_hist_hist_5", 0x00000460, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_5", 0x00000460, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_6
	{ "r_hist_hist_6", 0x00000464, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_6", 0x00000464, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_7
	{ "r_hist_hist_7", 0x00000468, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_7", 0x00000468, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_8
	{ "r_hist_hist_8", 0x0000046C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_8", 0x0000046C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_9
	{ "r_hist_hist_9", 0x00000470, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_9", 0x00000470, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_10
	{ "r_hist_hist_10", 0x00000474, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_10", 0x00000474, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_11
	{ "r_hist_hist_11", 0x00000478, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_11", 0x00000478, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_12
	{ "r_hist_hist_12", 0x0000047C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_12", 0x0000047C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_13
	{ "r_hist_hist_13", 0x00000480, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_13", 0x00000480, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_14
	{ "r_hist_hist_14", 0x00000484, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_14", 0x00000484, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_15
	{ "r_hist_hist_15", 0x00000488, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_15", 0x00000488, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_16
	{ "r_hist_hist_16", 0x0000048C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_16", 0x0000048C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_17
	{ "r_hist_hist_17", 0x00000490, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_17", 0x00000490, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_18
	{ "r_hist_hist_18", 0x00000494, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_18", 0x00000494, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_19
	{ "r_hist_hist_19", 0x00000498, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_19", 0x00000498, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_20
	{ "r_hist_hist_20", 0x0000049C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_20", 0x0000049C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_21
	{ "r_hist_hist_21", 0x000004A0, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_21", 0x000004A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_22
	{ "r_hist_hist_22", 0x000004A4, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_22", 0x000004A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_23
	{ "r_hist_hist_23", 0x000004A8, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_23", 0x000004A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_24
	{ "r_hist_hist_24", 0x000004AC, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_24", 0x000004AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_25
	{ "r_hist_hist_25", 0x000004B0, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_25", 0x000004B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_26
	{ "r_hist_hist_26", 0x000004B4, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_26", 0x000004B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_27
	{ "r_hist_hist_27", 0x000004B8, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_27", 0x000004B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_28
	{ "r_hist_hist_28", 0x000004BC, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_28", 0x000004BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_29
	{ "r_hist_hist_29", 0x000004C0, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_29", 0x000004C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_30
	{ "r_hist_hist_30", 0x000004C4, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_30", 0x000004C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_31
	{ "r_hist_hist_31", 0x000004C8, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_31", 0x000004C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_32
	{ "r_hist_hist_32", 0x000004CC, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_32", 0x000004CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_33
	{ "r_hist_hist_33", 0x000004D0, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_33", 0x000004D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_34
	{ "r_hist_hist_34", 0x000004D4, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_34", 0x000004D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_35
	{ "r_hist_hist_35", 0x000004D8, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_35", 0x000004D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_36
	{ "r_hist_hist_36", 0x000004DC, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_36", 0x000004DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_37
	{ "r_hist_hist_37", 0x000004E0, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_37", 0x000004E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_38
	{ "r_hist_hist_38", 0x000004E4, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_38", 0x000004E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_39
	{ "r_hist_hist_39", 0x000004E8, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_39", 0x000004E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_40
	{ "r_hist_hist_40", 0x000004EC, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_40", 0x000004EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_41
	{ "r_hist_hist_41", 0x000004F0, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_41", 0x000004F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_42
	{ "r_hist_hist_42", 0x000004F4, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_42", 0x000004F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_43
	{ "r_hist_hist_43", 0x000004F8, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_43", 0x000004F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_44
	{ "r_hist_hist_44", 0x000004FC, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_44", 0x000004FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_45
	{ "r_hist_hist_45", 0x00000500, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_45", 0x00000500, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_46
	{ "r_hist_hist_46", 0x00000504, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_46", 0x00000504, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_47
	{ "r_hist_hist_47", 0x00000508, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_47", 0x00000508, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_48
	{ "r_hist_hist_48", 0x0000050C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_48", 0x0000050C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_49
	{ "r_hist_hist_49", 0x00000510, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_49", 0x00000510, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_50
	{ "r_hist_hist_50", 0x00000514, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_50", 0x00000514, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_51
	{ "r_hist_hist_51", 0x00000518, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_51", 0x00000518, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_52
	{ "r_hist_hist_52", 0x0000051C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_52", 0x0000051C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_53
	{ "r_hist_hist_53", 0x00000520, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_53", 0x00000520, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_54
	{ "r_hist_hist_54", 0x00000524, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_54", 0x00000524, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_55
	{ "r_hist_hist_55", 0x00000528, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_55", 0x00000528, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_56
	{ "r_hist_hist_56", 0x0000052C, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_56", 0x0000052C, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_57
	{ "r_hist_hist_57", 0x00000530, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_57", 0x00000530, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_58
	{ "r_hist_hist_58", 0x00000534, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_58", 0x00000534, 31, 0, CSR_RO, 0x00000000 },
	// WORD r_hist_59
	{ "r_hist_hist_59", 0x00000538, 17, 0, CSR_RO, 0x00000000 },
	{ "R_HIST_59", 0x00000538, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_0
	{ "g_hist_hist_0", 0x0000053C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_0", 0x0000053C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_1
	{ "g_hist_hist_1", 0x00000540, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_1", 0x00000540, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_2
	{ "g_hist_hist_2", 0x00000544, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_2", 0x00000544, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_3
	{ "g_hist_hist_3", 0x00000548, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_3", 0x00000548, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_4
	{ "g_hist_hist_4", 0x0000054C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_4", 0x0000054C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_5
	{ "g_hist_hist_5", 0x00000550, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_5", 0x00000550, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_6
	{ "g_hist_hist_6", 0x00000554, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_6", 0x00000554, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_7
	{ "g_hist_hist_7", 0x00000558, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_7", 0x00000558, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_8
	{ "g_hist_hist_8", 0x0000055C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_8", 0x0000055C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_9
	{ "g_hist_hist_9", 0x00000560, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_9", 0x00000560, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_10
	{ "g_hist_hist_10", 0x00000564, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_10", 0x00000564, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_11
	{ "g_hist_hist_11", 0x00000568, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_11", 0x00000568, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_12
	{ "g_hist_hist_12", 0x0000056C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_12", 0x0000056C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_13
	{ "g_hist_hist_13", 0x00000570, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_13", 0x00000570, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_14
	{ "g_hist_hist_14", 0x00000574, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_14", 0x00000574, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_15
	{ "g_hist_hist_15", 0x00000578, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_15", 0x00000578, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_16
	{ "g_hist_hist_16", 0x0000057C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_16", 0x0000057C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_17
	{ "g_hist_hist_17", 0x00000580, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_17", 0x00000580, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_18
	{ "g_hist_hist_18", 0x00000584, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_18", 0x00000584, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_19
	{ "g_hist_hist_19", 0x00000588, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_19", 0x00000588, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_20
	{ "g_hist_hist_20", 0x0000058C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_20", 0x0000058C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_21
	{ "g_hist_hist_21", 0x00000590, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_21", 0x00000590, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_22
	{ "g_hist_hist_22", 0x00000594, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_22", 0x00000594, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_23
	{ "g_hist_hist_23", 0x00000598, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_23", 0x00000598, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_24
	{ "g_hist_hist_24", 0x0000059C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_24", 0x0000059C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_25
	{ "g_hist_hist_25", 0x000005A0, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_25", 0x000005A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_26
	{ "g_hist_hist_26", 0x000005A4, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_26", 0x000005A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_27
	{ "g_hist_hist_27", 0x000005A8, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_27", 0x000005A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_28
	{ "g_hist_hist_28", 0x000005AC, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_28", 0x000005AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_29
	{ "g_hist_hist_29", 0x000005B0, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_29", 0x000005B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_30
	{ "g_hist_hist_30", 0x000005B4, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_30", 0x000005B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_31
	{ "g_hist_hist_31", 0x000005B8, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_31", 0x000005B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_32
	{ "g_hist_hist_32", 0x000005BC, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_32", 0x000005BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_33
	{ "g_hist_hist_33", 0x000005C0, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_33", 0x000005C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_34
	{ "g_hist_hist_34", 0x000005C4, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_34", 0x000005C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_35
	{ "g_hist_hist_35", 0x000005C8, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_35", 0x000005C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_36
	{ "g_hist_hist_36", 0x000005CC, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_36", 0x000005CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_37
	{ "g_hist_hist_37", 0x000005D0, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_37", 0x000005D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_38
	{ "g_hist_hist_38", 0x000005D4, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_38", 0x000005D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_39
	{ "g_hist_hist_39", 0x000005D8, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_39", 0x000005D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_40
	{ "g_hist_hist_40", 0x000005DC, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_40", 0x000005DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_41
	{ "g_hist_hist_41", 0x000005E0, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_41", 0x000005E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_42
	{ "g_hist_hist_42", 0x000005E4, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_42", 0x000005E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_43
	{ "g_hist_hist_43", 0x000005E8, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_43", 0x000005E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_44
	{ "g_hist_hist_44", 0x000005EC, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_44", 0x000005EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_45
	{ "g_hist_hist_45", 0x000005F0, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_45", 0x000005F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_46
	{ "g_hist_hist_46", 0x000005F4, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_46", 0x000005F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_47
	{ "g_hist_hist_47", 0x000005F8, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_47", 0x000005F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_48
	{ "g_hist_hist_48", 0x000005FC, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_48", 0x000005FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_49
	{ "g_hist_hist_49", 0x00000600, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_49", 0x00000600, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_50
	{ "g_hist_hist_50", 0x00000604, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_50", 0x00000604, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_51
	{ "g_hist_hist_51", 0x00000608, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_51", 0x00000608, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_52
	{ "g_hist_hist_52", 0x0000060C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_52", 0x0000060C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_53
	{ "g_hist_hist_53", 0x00000610, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_53", 0x00000610, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_54
	{ "g_hist_hist_54", 0x00000614, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_54", 0x00000614, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_55
	{ "g_hist_hist_55", 0x00000618, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_55", 0x00000618, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_56
	{ "g_hist_hist_56", 0x0000061C, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_56", 0x0000061C, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_57
	{ "g_hist_hist_57", 0x00000620, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_57", 0x00000620, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_58
	{ "g_hist_hist_58", 0x00000624, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_58", 0x00000624, 31, 0, CSR_RO, 0x00000000 },
	// WORD g_hist_59
	{ "g_hist_hist_59", 0x00000628, 17, 0, CSR_RO, 0x00000000 },
	{ "G_HIST_59", 0x00000628, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_0
	{ "b_hist_hist_0", 0x0000062C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_0", 0x0000062C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_1
	{ "b_hist_hist_1", 0x00000630, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_1", 0x00000630, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_2
	{ "b_hist_hist_2", 0x00000634, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_2", 0x00000634, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_3
	{ "b_hist_hist_3", 0x00000638, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_3", 0x00000638, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_4
	{ "b_hist_hist_4", 0x0000063C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_4", 0x0000063C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_5
	{ "b_hist_hist_5", 0x00000640, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_5", 0x00000640, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_6
	{ "b_hist_hist_6", 0x00000644, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_6", 0x00000644, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_7
	{ "b_hist_hist_7", 0x00000648, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_7", 0x00000648, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_8
	{ "b_hist_hist_8", 0x0000064C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_8", 0x0000064C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_9
	{ "b_hist_hist_9", 0x00000650, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_9", 0x00000650, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_10
	{ "b_hist_hist_10", 0x00000654, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_10", 0x00000654, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_11
	{ "b_hist_hist_11", 0x00000658, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_11", 0x00000658, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_12
	{ "b_hist_hist_12", 0x0000065C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_12", 0x0000065C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_13
	{ "b_hist_hist_13", 0x00000660, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_13", 0x00000660, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_14
	{ "b_hist_hist_14", 0x00000664, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_14", 0x00000664, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_15
	{ "b_hist_hist_15", 0x00000668, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_15", 0x00000668, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_16
	{ "b_hist_hist_16", 0x0000066C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_16", 0x0000066C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_17
	{ "b_hist_hist_17", 0x00000670, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_17", 0x00000670, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_18
	{ "b_hist_hist_18", 0x00000674, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_18", 0x00000674, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_19
	{ "b_hist_hist_19", 0x00000678, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_19", 0x00000678, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_20
	{ "b_hist_hist_20", 0x0000067C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_20", 0x0000067C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_21
	{ "b_hist_hist_21", 0x00000680, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_21", 0x00000680, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_22
	{ "b_hist_hist_22", 0x00000684, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_22", 0x00000684, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_23
	{ "b_hist_hist_23", 0x00000688, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_23", 0x00000688, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_24
	{ "b_hist_hist_24", 0x0000068C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_24", 0x0000068C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_25
	{ "b_hist_hist_25", 0x00000690, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_25", 0x00000690, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_26
	{ "b_hist_hist_26", 0x00000694, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_26", 0x00000694, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_27
	{ "b_hist_hist_27", 0x00000698, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_27", 0x00000698, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_28
	{ "b_hist_hist_28", 0x0000069C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_28", 0x0000069C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_29
	{ "b_hist_hist_29", 0x000006A0, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_29", 0x000006A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_30
	{ "b_hist_hist_30", 0x000006A4, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_30", 0x000006A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_31
	{ "b_hist_hist_31", 0x000006A8, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_31", 0x000006A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_32
	{ "b_hist_hist_32", 0x000006AC, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_32", 0x000006AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_33
	{ "b_hist_hist_33", 0x000006B0, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_33", 0x000006B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_34
	{ "b_hist_hist_34", 0x000006B4, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_34", 0x000006B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_35
	{ "b_hist_hist_35", 0x000006B8, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_35", 0x000006B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_36
	{ "b_hist_hist_36", 0x000006BC, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_36", 0x000006BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_37
	{ "b_hist_hist_37", 0x000006C0, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_37", 0x000006C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_38
	{ "b_hist_hist_38", 0x000006C4, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_38", 0x000006C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_39
	{ "b_hist_hist_39", 0x000006C8, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_39", 0x000006C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_40
	{ "b_hist_hist_40", 0x000006CC, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_40", 0x000006CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_41
	{ "b_hist_hist_41", 0x000006D0, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_41", 0x000006D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_42
	{ "b_hist_hist_42", 0x000006D4, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_42", 0x000006D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_43
	{ "b_hist_hist_43", 0x000006D8, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_43", 0x000006D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_44
	{ "b_hist_hist_44", 0x000006DC, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_44", 0x000006DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_45
	{ "b_hist_hist_45", 0x000006E0, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_45", 0x000006E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_46
	{ "b_hist_hist_46", 0x000006E4, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_46", 0x000006E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_47
	{ "b_hist_hist_47", 0x000006E8, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_47", 0x000006E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_48
	{ "b_hist_hist_48", 0x000006EC, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_48", 0x000006EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_49
	{ "b_hist_hist_49", 0x000006F0, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_49", 0x000006F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_50
	{ "b_hist_hist_50", 0x000006F4, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_50", 0x000006F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_51
	{ "b_hist_hist_51", 0x000006F8, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_51", 0x000006F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_52
	{ "b_hist_hist_52", 0x000006FC, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_52", 0x000006FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_53
	{ "b_hist_hist_53", 0x00000700, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_53", 0x00000700, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_54
	{ "b_hist_hist_54", 0x00000704, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_54", 0x00000704, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_55
	{ "b_hist_hist_55", 0x00000708, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_55", 0x00000708, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_56
	{ "b_hist_hist_56", 0x0000070C, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_56", 0x0000070C, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_57
	{ "b_hist_hist_57", 0x00000710, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_57", 0x00000710, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_58
	{ "b_hist_hist_58", 0x00000714, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_58", 0x00000714, 31, 0, CSR_RO, 0x00000000 },
	// WORD b_hist_59
	{ "b_hist_hist_59", 0x00000718, 17, 0, CSR_RO, 0x00000000 },
	{ "B_HIST_59", 0x00000718, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg_sel
	{ "debug_mon_sel", 0x0000071C, 1, 0, CSR_RW, 0x00000000 },
	{ "DBG_SEL", 0x0000071C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_atpg_ctrl
	{ "atpg_ctrl", 0x00000720, 3, 0, CSR_RW, 0x00000000 },
	{ "WORD_ATPG_CTRL", 0x00000720, 31, 0, CSR_RW, 0x00000000 },
	// WORD efuse_status
	{ "efuse_sensor_cfa_violation", 0x00000724, 0, 0, CSR_RO, 0x00000000 },
	{ "EFUSE_STATUS", 0x00000724, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_0
	{ "ae_rgl_y_avg_r_data_0", 0x00000728, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_1", 0x00000728, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_2", 0x00000728, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_3", 0x00000728, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_0", 0x00000728, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_1
	{ "ae_rgl_y_avg_r_data_4", 0x0000072C, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_5", 0x0000072C, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_6", 0x0000072C, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_7", 0x0000072C, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_1", 0x0000072C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_2
	{ "ae_rgl_y_avg_r_data_8", 0x00000730, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_9", 0x00000730, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_10", 0x00000730, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_11", 0x00000730, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_2", 0x00000730, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_3
	{ "ae_rgl_y_avg_r_data_12", 0x00000734, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_13", 0x00000734, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_14", 0x00000734, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_15", 0x00000734, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_3", 0x00000734, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_4
	{ "ae_rgl_y_avg_r_data_16", 0x00000738, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_17", 0x00000738, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_18", 0x00000738, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_19", 0x00000738, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_4", 0x00000738, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_5
	{ "ae_rgl_y_avg_r_data_20", 0x0000073C, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_21", 0x0000073C, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_22", 0x0000073C, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_23", 0x0000073C, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_5", 0x0000073C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_6
	{ "ae_rgl_y_avg_r_data_24", 0x00000740, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_25", 0x00000740, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_26", 0x00000740, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_27", 0x00000740, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_6", 0x00000740, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_7
	{ "ae_rgl_y_avg_r_data_28", 0x00000744, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_29", 0x00000744, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_30", 0x00000744, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_31", 0x00000744, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_7", 0x00000744, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_8
	{ "ae_rgl_y_avg_r_data_32", 0x00000748, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_33", 0x00000748, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_34", 0x00000748, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_35", 0x00000748, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_8", 0x00000748, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_9
	{ "ae_rgl_y_avg_r_data_36", 0x0000074C, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_37", 0x0000074C, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_38", 0x0000074C, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_39", 0x0000074C, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_9", 0x0000074C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_10
	{ "ae_rgl_y_avg_r_data_40", 0x00000750, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_41", 0x00000750, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_42", 0x00000750, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_43", 0x00000750, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_10", 0x00000750, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_11
	{ "ae_rgl_y_avg_r_data_44", 0x00000754, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_45", 0x00000754, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_46", 0x00000754, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_47", 0x00000754, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_11", 0x00000754, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_12
	{ "ae_rgl_y_avg_r_data_48", 0x00000758, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_49", 0x00000758, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_50", 0x00000758, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_51", 0x00000758, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_12", 0x00000758, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_13
	{ "ae_rgl_y_avg_r_data_52", 0x0000075C, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_53", 0x0000075C, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_54", 0x0000075C, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_55", 0x0000075C, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_13", 0x0000075C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_14
	{ "ae_rgl_y_avg_r_data_56", 0x00000760, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_57", 0x00000760, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_58", 0x00000760, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_59", 0x00000760, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_14", 0x00000760, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_ae_rgl_y_avg_r_data_15
	{ "ae_rgl_y_avg_r_data_60", 0x00000764, 7, 0, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_61", 0x00000764, 15, 8, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_62", 0x00000764, 23, 16, CSR_RO, 0x00000000 },
	{ "ae_rgl_y_avg_r_data_63", 0x00000764, 31, 24, CSR_RO, 0x00000000 },
	{ "FPGA_AE_RGL_Y_AVG_R_DATA_15", 0x00000764, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_0
	{ "af_rgl_h1h2v1v2_avg_r_data_0", 0x00000768, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_1", 0x00000768, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_0", 0x00000768, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_1
	{ "af_rgl_h1h2v1v2_avg_r_data_2", 0x0000076C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_3", 0x0000076C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_1", 0x0000076C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_2
	{ "af_rgl_h1h2v1v2_avg_r_data_4", 0x00000770, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_5", 0x00000770, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_2", 0x00000770, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_3
	{ "af_rgl_h1h2v1v2_avg_r_data_6", 0x00000774, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_7", 0x00000774, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_3", 0x00000774, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_4
	{ "af_rgl_h1h2v1v2_avg_r_data_8", 0x00000778, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_9", 0x00000778, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_4", 0x00000778, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_5
	{ "af_rgl_h1h2v1v2_avg_r_data_10", 0x0000077C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_11", 0x0000077C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_5", 0x0000077C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_6
	{ "af_rgl_h1h2v1v2_avg_r_data_12", 0x00000780, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_13", 0x00000780, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_6", 0x00000780, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_7
	{ "af_rgl_h1h2v1v2_avg_r_data_14", 0x00000784, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_15", 0x00000784, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_7", 0x00000784, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_8
	{ "af_rgl_h1h2v1v2_avg_r_data_16", 0x00000788, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_17", 0x00000788, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_8", 0x00000788, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_9
	{ "af_rgl_h1h2v1v2_avg_r_data_18", 0x0000078C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_19", 0x0000078C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_9", 0x0000078C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_10
	{ "af_rgl_h1h2v1v2_avg_r_data_20", 0x00000790, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_21", 0x00000790, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_10", 0x00000790, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_11
	{ "af_rgl_h1h2v1v2_avg_r_data_22", 0x00000794, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_23", 0x00000794, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_11", 0x00000794, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_12
	{ "af_rgl_h1h2v1v2_avg_r_data_24", 0x00000798, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_25", 0x00000798, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_12", 0x00000798, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_13
	{ "af_rgl_h1h2v1v2_avg_r_data_26", 0x0000079C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_27", 0x0000079C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_13", 0x0000079C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_14
	{ "af_rgl_h1h2v1v2_avg_r_data_28", 0x000007A0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_29", 0x000007A0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_14", 0x000007A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_15
	{ "af_rgl_h1h2v1v2_avg_r_data_30", 0x000007A4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_31", 0x000007A4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_15", 0x000007A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_16
	{ "af_rgl_h1h2v1v2_avg_r_data_32", 0x000007A8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_33", 0x000007A8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_16", 0x000007A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_17
	{ "af_rgl_h1h2v1v2_avg_r_data_34", 0x000007AC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_35", 0x000007AC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_17", 0x000007AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_18
	{ "af_rgl_h1h2v1v2_avg_r_data_36", 0x000007B0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_37", 0x000007B0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_18", 0x000007B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_19
	{ "af_rgl_h1h2v1v2_avg_r_data_38", 0x000007B4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_39", 0x000007B4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_19", 0x000007B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_20
	{ "af_rgl_h1h2v1v2_avg_r_data_40", 0x000007B8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_41", 0x000007B8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_20", 0x000007B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_21
	{ "af_rgl_h1h2v1v2_avg_r_data_42", 0x000007BC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_43", 0x000007BC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_21", 0x000007BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_22
	{ "af_rgl_h1h2v1v2_avg_r_data_44", 0x000007C0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_45", 0x000007C0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_22", 0x000007C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_23
	{ "af_rgl_h1h2v1v2_avg_r_data_46", 0x000007C4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_47", 0x000007C4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_23", 0x000007C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_24
	{ "af_rgl_h1h2v1v2_avg_r_data_48", 0x000007C8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_49", 0x000007C8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_24", 0x000007C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_25
	{ "af_rgl_h1h2v1v2_avg_r_data_50", 0x000007CC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_51", 0x000007CC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_25", 0x000007CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_26
	{ "af_rgl_h1h2v1v2_avg_r_data_52", 0x000007D0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_53", 0x000007D0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_26", 0x000007D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_27
	{ "af_rgl_h1h2v1v2_avg_r_data_54", 0x000007D4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_55", 0x000007D4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_27", 0x000007D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_28
	{ "af_rgl_h1h2v1v2_avg_r_data_56", 0x000007D8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_57", 0x000007D8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_28", 0x000007D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_29
	{ "af_rgl_h1h2v1v2_avg_r_data_58", 0x000007DC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_59", 0x000007DC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_29", 0x000007DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_30
	{ "af_rgl_h1h2v1v2_avg_r_data_60", 0x000007E0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_61", 0x000007E0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_30", 0x000007E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_31
	{ "af_rgl_h1h2v1v2_avg_r_data_62", 0x000007E4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_63", 0x000007E4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_31", 0x000007E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_32
	{ "af_rgl_h1h2v1v2_avg_r_data_64", 0x000007E8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_65", 0x000007E8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_32", 0x000007E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_33
	{ "af_rgl_h1h2v1v2_avg_r_data_66", 0x000007EC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_67", 0x000007EC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_33", 0x000007EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_34
	{ "af_rgl_h1h2v1v2_avg_r_data_68", 0x000007F0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_69", 0x000007F0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_34", 0x000007F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_35
	{ "af_rgl_h1h2v1v2_avg_r_data_70", 0x000007F4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_71", 0x000007F4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_35", 0x000007F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_36
	{ "af_rgl_h1h2v1v2_avg_r_data_72", 0x000007F8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_73", 0x000007F8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_36", 0x000007F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_37
	{ "af_rgl_h1h2v1v2_avg_r_data_74", 0x000007FC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_75", 0x000007FC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_37", 0x000007FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_38
	{ "af_rgl_h1h2v1v2_avg_r_data_76", 0x00000800, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_77", 0x00000800, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_38", 0x00000800, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_39
	{ "af_rgl_h1h2v1v2_avg_r_data_78", 0x00000804, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_79", 0x00000804, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_39", 0x00000804, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_40
	{ "af_rgl_h1h2v1v2_avg_r_data_80", 0x00000808, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_81", 0x00000808, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_40", 0x00000808, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_41
	{ "af_rgl_h1h2v1v2_avg_r_data_82", 0x0000080C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_83", 0x0000080C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_41", 0x0000080C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_42
	{ "af_rgl_h1h2v1v2_avg_r_data_84", 0x00000810, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_85", 0x00000810, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_42", 0x00000810, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_43
	{ "af_rgl_h1h2v1v2_avg_r_data_86", 0x00000814, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_87", 0x00000814, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_43", 0x00000814, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_44
	{ "af_rgl_h1h2v1v2_avg_r_data_88", 0x00000818, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_89", 0x00000818, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_44", 0x00000818, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_45
	{ "af_rgl_h1h2v1v2_avg_r_data_90", 0x0000081C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_91", 0x0000081C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_45", 0x0000081C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_46
	{ "af_rgl_h1h2v1v2_avg_r_data_92", 0x00000820, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_93", 0x00000820, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_46", 0x00000820, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_47
	{ "af_rgl_h1h2v1v2_avg_r_data_94", 0x00000824, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_95", 0x00000824, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_47", 0x00000824, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_48
	{ "af_rgl_h1h2v1v2_avg_r_data_96", 0x00000828, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_97", 0x00000828, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_48", 0x00000828, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_49
	{ "af_rgl_h1h2v1v2_avg_r_data_98", 0x0000082C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_99", 0x0000082C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_49", 0x0000082C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_50
	{ "af_rgl_h1h2v1v2_avg_r_data_100", 0x00000830, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_101", 0x00000830, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_50", 0x00000830, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_51
	{ "af_rgl_h1h2v1v2_avg_r_data_102", 0x00000834, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_103", 0x00000834, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_51", 0x00000834, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_52
	{ "af_rgl_h1h2v1v2_avg_r_data_104", 0x00000838, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_105", 0x00000838, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_52", 0x00000838, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_53
	{ "af_rgl_h1h2v1v2_avg_r_data_106", 0x0000083C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_107", 0x0000083C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_53", 0x0000083C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_54
	{ "af_rgl_h1h2v1v2_avg_r_data_108", 0x00000840, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_109", 0x00000840, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_54", 0x00000840, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_55
	{ "af_rgl_h1h2v1v2_avg_r_data_110", 0x00000844, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_111", 0x00000844, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_55", 0x00000844, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_56
	{ "af_rgl_h1h2v1v2_avg_r_data_112", 0x00000848, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_113", 0x00000848, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_56", 0x00000848, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_57
	{ "af_rgl_h1h2v1v2_avg_r_data_114", 0x0000084C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_115", 0x0000084C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_57", 0x0000084C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_58
	{ "af_rgl_h1h2v1v2_avg_r_data_116", 0x00000850, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_117", 0x00000850, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_58", 0x00000850, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_59
	{ "af_rgl_h1h2v1v2_avg_r_data_118", 0x00000854, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_119", 0x00000854, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_59", 0x00000854, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_60
	{ "af_rgl_h1h2v1v2_avg_r_data_120", 0x00000858, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_121", 0x00000858, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_60", 0x00000858, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_61
	{ "af_rgl_h1h2v1v2_avg_r_data_122", 0x0000085C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_123", 0x0000085C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_61", 0x0000085C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_62
	{ "af_rgl_h1h2v1v2_avg_r_data_124", 0x00000860, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_125", 0x00000860, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_62", 0x00000860, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_63
	{ "af_rgl_h1h2v1v2_avg_r_data_126", 0x00000864, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_127", 0x00000864, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_63", 0x00000864, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_64
	{ "af_rgl_h1h2v1v2_avg_r_data_128", 0x00000868, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_129", 0x00000868, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_64", 0x00000868, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_65
	{ "af_rgl_h1h2v1v2_avg_r_data_130", 0x0000086C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_131", 0x0000086C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_65", 0x0000086C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_66
	{ "af_rgl_h1h2v1v2_avg_r_data_132", 0x00000870, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_133", 0x00000870, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_66", 0x00000870, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_67
	{ "af_rgl_h1h2v1v2_avg_r_data_134", 0x00000874, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_135", 0x00000874, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_67", 0x00000874, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_68
	{ "af_rgl_h1h2v1v2_avg_r_data_136", 0x00000878, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_137", 0x00000878, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_68", 0x00000878, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_69
	{ "af_rgl_h1h2v1v2_avg_r_data_138", 0x0000087C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_139", 0x0000087C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_69", 0x0000087C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_70
	{ "af_rgl_h1h2v1v2_avg_r_data_140", 0x00000880, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_141", 0x00000880, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_70", 0x00000880, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_71
	{ "af_rgl_h1h2v1v2_avg_r_data_142", 0x00000884, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_143", 0x00000884, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_71", 0x00000884, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_72
	{ "af_rgl_h1h2v1v2_avg_r_data_144", 0x00000888, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_145", 0x00000888, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_72", 0x00000888, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_73
	{ "af_rgl_h1h2v1v2_avg_r_data_146", 0x0000088C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_147", 0x0000088C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_73", 0x0000088C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_74
	{ "af_rgl_h1h2v1v2_avg_r_data_148", 0x00000890, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_149", 0x00000890, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_74", 0x00000890, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_75
	{ "af_rgl_h1h2v1v2_avg_r_data_150", 0x00000894, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_151", 0x00000894, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_75", 0x00000894, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_76
	{ "af_rgl_h1h2v1v2_avg_r_data_152", 0x00000898, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_153", 0x00000898, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_76", 0x00000898, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_77
	{ "af_rgl_h1h2v1v2_avg_r_data_154", 0x0000089C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_155", 0x0000089C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_77", 0x0000089C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_78
	{ "af_rgl_h1h2v1v2_avg_r_data_156", 0x000008A0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_157", 0x000008A0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_78", 0x000008A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_79
	{ "af_rgl_h1h2v1v2_avg_r_data_158", 0x000008A4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_159", 0x000008A4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_79", 0x000008A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_80
	{ "af_rgl_h1h2v1v2_avg_r_data_160", 0x000008A8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_161", 0x000008A8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_80", 0x000008A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_81
	{ "af_rgl_h1h2v1v2_avg_r_data_162", 0x000008AC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_163", 0x000008AC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_81", 0x000008AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_82
	{ "af_rgl_h1h2v1v2_avg_r_data_164", 0x000008B0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_165", 0x000008B0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_82", 0x000008B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_83
	{ "af_rgl_h1h2v1v2_avg_r_data_166", 0x000008B4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_167", 0x000008B4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_83", 0x000008B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_84
	{ "af_rgl_h1h2v1v2_avg_r_data_168", 0x000008B8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_169", 0x000008B8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_84", 0x000008B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_85
	{ "af_rgl_h1h2v1v2_avg_r_data_170", 0x000008BC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_171", 0x000008BC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_85", 0x000008BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_86
	{ "af_rgl_h1h2v1v2_avg_r_data_172", 0x000008C0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_173", 0x000008C0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_86", 0x000008C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_87
	{ "af_rgl_h1h2v1v2_avg_r_data_174", 0x000008C4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_175", 0x000008C4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_87", 0x000008C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_88
	{ "af_rgl_h1h2v1v2_avg_r_data_176", 0x000008C8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_177", 0x000008C8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_88", 0x000008C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_89
	{ "af_rgl_h1h2v1v2_avg_r_data_178", 0x000008CC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_179", 0x000008CC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_89", 0x000008CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_90
	{ "af_rgl_h1h2v1v2_avg_r_data_180", 0x000008D0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_181", 0x000008D0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_90", 0x000008D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_91
	{ "af_rgl_h1h2v1v2_avg_r_data_182", 0x000008D4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_183", 0x000008D4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_91", 0x000008D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_92
	{ "af_rgl_h1h2v1v2_avg_r_data_184", 0x000008D8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_185", 0x000008D8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_92", 0x000008D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_93
	{ "af_rgl_h1h2v1v2_avg_r_data_186", 0x000008DC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_187", 0x000008DC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_93", 0x000008DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_94
	{ "af_rgl_h1h2v1v2_avg_r_data_188", 0x000008E0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_189", 0x000008E0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_94", 0x000008E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_95
	{ "af_rgl_h1h2v1v2_avg_r_data_190", 0x000008E4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_191", 0x000008E4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_95", 0x000008E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_96
	{ "af_rgl_h1h2v1v2_avg_r_data_192", 0x000008E8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_193", 0x000008E8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_96", 0x000008E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_97
	{ "af_rgl_h1h2v1v2_avg_r_data_194", 0x000008EC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_195", 0x000008EC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_97", 0x000008EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_98
	{ "af_rgl_h1h2v1v2_avg_r_data_196", 0x000008F0, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_197", 0x000008F0, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_98", 0x000008F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_99
	{ "af_rgl_h1h2v1v2_avg_r_data_198", 0x000008F4, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_199", 0x000008F4, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_99", 0x000008F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_100
	{ "af_rgl_h1h2v1v2_avg_r_data_200", 0x000008F8, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_201", 0x000008F8, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_100", 0x000008F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_101
	{ "af_rgl_h1h2v1v2_avg_r_data_202", 0x000008FC, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_203", 0x000008FC, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_101", 0x000008FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_102
	{ "af_rgl_h1h2v1v2_avg_r_data_204", 0x00000900, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_205", 0x00000900, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_102", 0x00000900, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_103
	{ "af_rgl_h1h2v1v2_avg_r_data_206", 0x00000904, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_207", 0x00000904, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_103", 0x00000904, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_104
	{ "af_rgl_h1h2v1v2_avg_r_data_208", 0x00000908, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_209", 0x00000908, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_104", 0x00000908, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_105
	{ "af_rgl_h1h2v1v2_avg_r_data_210", 0x0000090C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_211", 0x0000090C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_105", 0x0000090C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_106
	{ "af_rgl_h1h2v1v2_avg_r_data_212", 0x00000910, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_213", 0x00000910, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_106", 0x00000910, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_107
	{ "af_rgl_h1h2v1v2_avg_r_data_214", 0x00000914, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_215", 0x00000914, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_107", 0x00000914, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_108
	{ "af_rgl_h1h2v1v2_avg_r_data_216", 0x00000918, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_217", 0x00000918, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_108", 0x00000918, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_109
	{ "af_rgl_h1h2v1v2_avg_r_data_218", 0x0000091C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_219", 0x0000091C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_109", 0x0000091C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_110
	{ "af_rgl_h1h2v1v2_avg_r_data_220", 0x00000920, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_221", 0x00000920, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_110", 0x00000920, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_111
	{ "af_rgl_h1h2v1v2_avg_r_data_222", 0x00000924, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_223", 0x00000924, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_111", 0x00000924, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_112
	{ "af_rgl_h1h2v1v2_avg_r_data_224", 0x00000928, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_225", 0x00000928, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_112", 0x00000928, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_113
	{ "af_rgl_h1h2v1v2_avg_r_data_226", 0x0000092C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_227", 0x0000092C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_113", 0x0000092C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_114
	{ "af_rgl_h1h2v1v2_avg_r_data_228", 0x00000930, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_229", 0x00000930, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_114", 0x00000930, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_115
	{ "af_rgl_h1h2v1v2_avg_r_data_230", 0x00000934, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_231", 0x00000934, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_115", 0x00000934, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_116
	{ "af_rgl_h1h2v1v2_avg_r_data_232", 0x00000938, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_233", 0x00000938, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_116", 0x00000938, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_117
	{ "af_rgl_h1h2v1v2_avg_r_data_234", 0x0000093C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_235", 0x0000093C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_117", 0x0000093C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_118
	{ "af_rgl_h1h2v1v2_avg_r_data_236", 0x00000940, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_237", 0x00000940, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_118", 0x00000940, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_119
	{ "af_rgl_h1h2v1v2_avg_r_data_238", 0x00000944, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_239", 0x00000944, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_119", 0x00000944, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_120
	{ "af_rgl_h1h2v1v2_avg_r_data_240", 0x00000948, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_241", 0x00000948, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_120", 0x00000948, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_121
	{ "af_rgl_h1h2v1v2_avg_r_data_242", 0x0000094C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_243", 0x0000094C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_121", 0x0000094C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_122
	{ "af_rgl_h1h2v1v2_avg_r_data_244", 0x00000950, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_245", 0x00000950, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_122", 0x00000950, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_123
	{ "af_rgl_h1h2v1v2_avg_r_data_246", 0x00000954, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_247", 0x00000954, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_123", 0x00000954, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_124
	{ "af_rgl_h1h2v1v2_avg_r_data_248", 0x00000958, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_249", 0x00000958, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_124", 0x00000958, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_125
	{ "af_rgl_h1h2v1v2_avg_r_data_250", 0x0000095C, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_251", 0x0000095C, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_125", 0x0000095C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_126
	{ "af_rgl_h1h2v1v2_avg_r_data_252", 0x00000960, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_253", 0x00000960, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_126", 0x00000960, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_af_rgl_h1h2v1v2_avg_r_data_127
	{ "af_rgl_h1h2v1v2_avg_r_data_254", 0x00000964, 13, 0, CSR_RO, 0x00000000 },
	{ "af_rgl_h1h2v1v2_avg_r_data_255", 0x00000964, 29, 16, CSR_RO, 0x00000000 },
	{ "FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_127", 0x00000964, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_0
	{ "awb_rtx_avg_r_data_0", 0x00000968, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_0", 0x00000968, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_1
	{ "awb_rtx_avg_r_data_1", 0x0000096C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_1", 0x0000096C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_2
	{ "awb_rtx_avg_r_data_2", 0x00000970, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_2", 0x00000970, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_3
	{ "awb_rtx_avg_r_data_3", 0x00000974, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_3", 0x00000974, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_4
	{ "awb_rtx_avg_r_data_4", 0x00000978, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_4", 0x00000978, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_5
	{ "awb_rtx_avg_r_data_5", 0x0000097C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_5", 0x0000097C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_6
	{ "awb_rtx_avg_r_data_6", 0x00000980, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_6", 0x00000980, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_7
	{ "awb_rtx_avg_r_data_7", 0x00000984, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_7", 0x00000984, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_8
	{ "awb_rtx_avg_r_data_8", 0x00000988, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_8", 0x00000988, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_9
	{ "awb_rtx_avg_r_data_9", 0x0000098C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_9", 0x0000098C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_10
	{ "awb_rtx_avg_r_data_10", 0x00000990, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_10", 0x00000990, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_11
	{ "awb_rtx_avg_r_data_11", 0x00000994, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_11", 0x00000994, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_12
	{ "awb_rtx_avg_r_data_12", 0x00000998, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_12", 0x00000998, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_13
	{ "awb_rtx_avg_r_data_13", 0x0000099C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_13", 0x0000099C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_14
	{ "awb_rtx_avg_r_data_14", 0x000009A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_14", 0x000009A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_15
	{ "awb_rtx_avg_r_data_15", 0x000009A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_15", 0x000009A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_16
	{ "awb_rtx_avg_r_data_16", 0x000009A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_16", 0x000009A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_17
	{ "awb_rtx_avg_r_data_17", 0x000009AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_17", 0x000009AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_18
	{ "awb_rtx_avg_r_data_18", 0x000009B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_18", 0x000009B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_19
	{ "awb_rtx_avg_r_data_19", 0x000009B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_19", 0x000009B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_20
	{ "awb_rtx_avg_r_data_20", 0x000009B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_20", 0x000009B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_21
	{ "awb_rtx_avg_r_data_21", 0x000009BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_21", 0x000009BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_22
	{ "awb_rtx_avg_r_data_22", 0x000009C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_22", 0x000009C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_23
	{ "awb_rtx_avg_r_data_23", 0x000009C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_23", 0x000009C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_24
	{ "awb_rtx_avg_r_data_24", 0x000009C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_24", 0x000009C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_25
	{ "awb_rtx_avg_r_data_25", 0x000009CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_25", 0x000009CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_26
	{ "awb_rtx_avg_r_data_26", 0x000009D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_26", 0x000009D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_27
	{ "awb_rtx_avg_r_data_27", 0x000009D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_27", 0x000009D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_28
	{ "awb_rtx_avg_r_data_28", 0x000009D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_28", 0x000009D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_29
	{ "awb_rtx_avg_r_data_29", 0x000009DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_29", 0x000009DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_30
	{ "awb_rtx_avg_r_data_30", 0x000009E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_30", 0x000009E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_31
	{ "awb_rtx_avg_r_data_31", 0x000009E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_31", 0x000009E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_32
	{ "awb_rtx_avg_r_data_32", 0x000009E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_32", 0x000009E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_33
	{ "awb_rtx_avg_r_data_33", 0x000009EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_33", 0x000009EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_34
	{ "awb_rtx_avg_r_data_34", 0x000009F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_34", 0x000009F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_35
	{ "awb_rtx_avg_r_data_35", 0x000009F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_35", 0x000009F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_36
	{ "awb_rtx_avg_r_data_36", 0x000009F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_36", 0x000009F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_37
	{ "awb_rtx_avg_r_data_37", 0x000009FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_37", 0x000009FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_38
	{ "awb_rtx_avg_r_data_38", 0x00000A00, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_38", 0x00000A00, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_39
	{ "awb_rtx_avg_r_data_39", 0x00000A04, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_39", 0x00000A04, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_40
	{ "awb_rtx_avg_r_data_40", 0x00000A08, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_40", 0x00000A08, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_41
	{ "awb_rtx_avg_r_data_41", 0x00000A0C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_41", 0x00000A0C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_42
	{ "awb_rtx_avg_r_data_42", 0x00000A10, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_42", 0x00000A10, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_43
	{ "awb_rtx_avg_r_data_43", 0x00000A14, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_43", 0x00000A14, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_44
	{ "awb_rtx_avg_r_data_44", 0x00000A18, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_44", 0x00000A18, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_45
	{ "awb_rtx_avg_r_data_45", 0x00000A1C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_45", 0x00000A1C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_46
	{ "awb_rtx_avg_r_data_46", 0x00000A20, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_46", 0x00000A20, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_47
	{ "awb_rtx_avg_r_data_47", 0x00000A24, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_47", 0x00000A24, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_48
	{ "awb_rtx_avg_r_data_48", 0x00000A28, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_48", 0x00000A28, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_49
	{ "awb_rtx_avg_r_data_49", 0x00000A2C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_49", 0x00000A2C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_50
	{ "awb_rtx_avg_r_data_50", 0x00000A30, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_50", 0x00000A30, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_51
	{ "awb_rtx_avg_r_data_51", 0x00000A34, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_51", 0x00000A34, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_52
	{ "awb_rtx_avg_r_data_52", 0x00000A38, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_52", 0x00000A38, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_53
	{ "awb_rtx_avg_r_data_53", 0x00000A3C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_53", 0x00000A3C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_54
	{ "awb_rtx_avg_r_data_54", 0x00000A40, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_54", 0x00000A40, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_55
	{ "awb_rtx_avg_r_data_55", 0x00000A44, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_55", 0x00000A44, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_56
	{ "awb_rtx_avg_r_data_56", 0x00000A48, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_56", 0x00000A48, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_57
	{ "awb_rtx_avg_r_data_57", 0x00000A4C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_57", 0x00000A4C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_58
	{ "awb_rtx_avg_r_data_58", 0x00000A50, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_58", 0x00000A50, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_59
	{ "awb_rtx_avg_r_data_59", 0x00000A54, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_59", 0x00000A54, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_60
	{ "awb_rtx_avg_r_data_60", 0x00000A58, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_60", 0x00000A58, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_61
	{ "awb_rtx_avg_r_data_61", 0x00000A5C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_61", 0x00000A5C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_62
	{ "awb_rtx_avg_r_data_62", 0x00000A60, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_62", 0x00000A60, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_awb_rtx_avg_r_data_63
	{ "awb_rtx_avg_r_data_63", 0x00000A64, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_AWB_RTX_AVG_R_DATA_63", 0x00000A64, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_BSP_H_
