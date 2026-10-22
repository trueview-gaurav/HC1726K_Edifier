#ifndef CSR_BANK_BSP_H_
#define CSR_BANK_BSP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from bsp  ***/
typedef struct csr_bank_bsp {
	/* WORD_FRAME_START 12'h000 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 12'h004 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 12'h008 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 12'h00C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO_FORMAT 12'h010 */
	union {
		uint32_t io_format; // word name
		struct {
			uint32_t cfa_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t bayer_ini_phase_i : 2;
			uint32_t : 6; // padding bits
			uint32_t bayer_ini_phase_o : 2;
			uint32_t : 6; // padding bits
			uint32_t mono_o : 1;
			uint32_t mode : 2;
			uint32_t ink_num : 4;
			uint32_t : 1; // padding bits
		};
	};
	/* WORD_CFA_PHASE_0 12'h014 */
	union {
		uint32_t word_cfa_phase_0; // word name
		struct {
			uint32_t cfa_phase_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_1 12'h018 */
	union {
		uint32_t word_cfa_phase_1; // word name
		struct {
			uint32_t cfa_phase_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_2 12'h01C */
	union {
		uint32_t word_cfa_phase_2; // word name
		struct {
			uint32_t cfa_phase_8 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_9 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_10 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_3 12'h020 */
	union {
		uint32_t word_cfa_phase_3; // word name
		struct {
			uint32_t cfa_phase_12 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_13 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_14 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* RESOLUTION 12'h024 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* DDPD_EN 12'h028 */
	union {
		uint32_t ddpd_en; // word name
		struct {
			uint32_t ddpd_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDPD_DIR_TH 12'h02C */
	union {
		uint32_t ddpd_dir_th; // word name
		struct {
			uint32_t ddpd_dir_straight_th : 7;
			uint32_t : 1; // padding bits
			uint32_t ddpd_dir_slash_th : 7;
			uint32_t : 1; // padding bits
			uint32_t ddpd_dir_pt_min_th : 7;
			uint32_t : 1; // padding bits
			uint32_t ddpd_dir_dp_th : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* DDPD_PLANAR_TH 12'h030 */
	union {
		uint32_t ddpd_planar_th; // word name
		struct {
			uint32_t ddpd_flat_dt_th : 7;
			uint32_t : 1; // padding bits
			uint32_t ddpd_flat_pix_th : 7;
			uint32_t : 1; // padding bits
			uint32_t ddpd_smooth_dt_th : 7;
			uint32_t : 1; // padding bits
			uint32_t ddpd_smooth_pix_th : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* WORD_DDPD_DP_NUM 12'h034 */
	union {
		uint32_t word_ddpd_dp_num; // word name
		struct {
			uint32_t ddpd_dp_num : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC_EN 12'h038 */
	union {
		uint32_t dpc_en; // word name
		struct {
			uint32_t dpc_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t dpc_avg_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTC_EN 12'h03C */
	union {
		uint32_t ctc_en; // word name
		struct {
			uint32_t ctc_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTC_AVG 12'h040 */
	union {
		uint32_t ctc_avg; // word name
		struct {
			uint32_t ctc_avg_lb : 16;
			uint32_t ctc_avg_ratio : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* CTC_STR 12'h044 */
	union {
		uint32_t ctc_str; // word name
		struct {
			uint32_t ctc_corr_region_th : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTC_CORR_VAL 12'h048 */
	union {
		uint32_t ctc_corr_val; // word name
		struct {
			uint32_t ctc_correct_val : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* CTC_STR_STAT 12'h04C */
	union {
		uint32_t ctc_str_stat; // word name
		struct {
			uint32_t ctc_smooth_str : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* CT_STR 12'h050 [Unused] */
	uint32_t empty_word_ct_str;
	/* CH_WEIGHT_0 12'h054 */
	union {
		uint32_t ch_weight_0; // word name
		struct {
			uint32_t channel_weight_00 : 5;
			uint32_t : 3; // padding bits
			uint32_t channel_weight_01 : 5;
			uint32_t : 3; // padding bits
			uint32_t channel_weight_02 : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CH_WEIGHT_1 12'h058 */
	union {
		uint32_t ch_weight_1; // word name
		struct {
			uint32_t channel_weight_11 : 7;
			uint32_t : 1; // padding bits
			uint32_t channel_weight_12 : 7;
			uint32_t : 1; // padding bits
			uint32_t channel_weight_22 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_REMOS_ENABLE 12'h05C */
	union {
		uint32_t word_remos_enable; // word name
		struct {
			uint32_t remos_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REMOS_COEFF_R_0 12'h060 */
	union {
		uint32_t remos_coeff_r_0; // word name
		struct {
			uint32_t remos_r_r_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_r_g_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_R_1 12'h064 */
	union {
		uint32_t remos_coeff_r_1; // word name
		struct {
			uint32_t remos_r_b_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_r_s_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_G_0 12'h068 */
	union {
		uint32_t remos_coeff_g_0; // word name
		struct {
			uint32_t remos_g_r_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_g_g_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_G_1 12'h06C */
	union {
		uint32_t remos_coeff_g_1; // word name
		struct {
			uint32_t remos_g_b_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_g_s_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_B_0 12'h070 */
	union {
		uint32_t remos_coeff_b_0; // word name
		struct {
			uint32_t remos_b_r_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_b_g_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_B_1 12'h074 */
	union {
		uint32_t remos_coeff_b_1; // word name
		struct {
			uint32_t remos_b_b_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_b_s_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_Y_EST_MODE 12'h078 */
	union {
		uint32_t word_y_est_mode; // word name
		struct {
			uint32_t y_est_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_EST_WEIGHT 12'h07C */
	union {
		uint32_t y_est_weight; // word name
		struct {
			uint32_t y_r_weight : 6;
			uint32_t : 2; // padding bits
			uint32_t y_g_weight : 6;
			uint32_t : 2; // padding bits
			uint32_t y_b_weight : 6;
			uint32_t : 2; // padding bits
			uint32_t y_s_weight : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_CONTRAST_Y_MODE 12'h080 */
	union {
		uint32_t word_contrast_y_mode; // word name
		struct {
			uint32_t contrast_y_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_Y_GAIN_0 12'h084 */
	union {
		uint32_t contrast_y_gain_0; // word name
		struct {
			uint32_t contrast_y_gain_th_max : 8;
			uint32_t : 8; // padding bits
			uint32_t contrast_y_gain_th_min : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_Y_GAIN_1 12'h088 */
	union {
		uint32_t contrast_y_gain_1; // word name
		struct {
			uint32_t contrast_y_gain_m : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_CFA_ENABLE_0 12'h08C */
	union {
		uint32_t contrast_cfa_enable_0; // word name
		struct {
			uint32_t contrast_cfa_phase_en_g0 : 1;
			uint32_t : 7; // padding bits
			uint32_t contrast_cfa_phase_en_r : 1;
			uint32_t : 7; // padding bits
			uint32_t contrast_cfa_phase_en_b : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_CFA_ENABLE_1 12'h090 */
	union {
		uint32_t contrast_cfa_enable_1; // word name
		struct {
			uint32_t contrast_cfa_phase_en_g1 : 1;
			uint32_t : 7; // padding bits
			uint32_t contrast_cfa_phase_en_s : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_H1_WEIGHT_0 12'h094 */
	union {
		uint32_t word_contrast_h1_weight_0; // word name
		struct {
			uint32_t contrast_h1_weight_0 : 9;
			uint32_t : 7; // padding bits
			uint32_t contrast_h1_weight_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_CONTRAST_H1_WEIGHT_1 12'h098 */
	union {
		uint32_t word_contrast_h1_weight_1; // word name
		struct {
			uint32_t contrast_h1_weight_2 : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_H2_WEIGHT_0 12'h09C */
	union {
		uint32_t word_contrast_h2_weight_0; // word name
		struct {
			uint32_t contrast_h2_weight_0 : 9;
			uint32_t : 7; // padding bits
			uint32_t contrast_h2_weight_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_CONTRAST_H2_WEIGHT_1 12'h0A0 */
	union {
		uint32_t word_contrast_h2_weight_1; // word name
		struct {
			uint32_t contrast_h2_weight_2 : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_V1_WEIGHT_0 12'h0A4 */
	union {
		uint32_t word_contrast_v1_weight_0; // word name
		struct {
			uint32_t contrast_v1_weight_0 : 9;
			uint32_t : 7; // padding bits
			uint32_t contrast_v1_weight_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_CONTRAST_V1_WEIGHT_1 12'h0A8 */
	union {
		uint32_t word_contrast_v1_weight_1; // word name
		struct {
			uint32_t contrast_v1_weight_2 : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_V2_WEIGHT_0 12'h0AC */
	union {
		uint32_t word_contrast_v2_weight_0; // word name
		struct {
			uint32_t contrast_v2_weight_0 : 9;
			uint32_t : 7; // padding bits
			uint32_t contrast_v2_weight_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_CONTRAST_V2_WEIGHT_1 12'h0B0 */
	union {
		uint32_t word_contrast_v2_weight_1; // word name
		struct {
			uint32_t contrast_v2_weight_2 : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_CORING_TH 12'h0B4 */
	union {
		uint32_t word_contrast_coring_th; // word name
		struct {
			uint32_t contrast_coring_th : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AWB_GWD_Y_MODE 12'h0B8 */
	union {
		uint32_t word_awb_gwd_y_mode; // word name
		struct {
			uint32_t awb_gwd_y_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_Y_GAIN_0 12'h0BC */
	union {
		uint32_t awb_gwd_y_gain_0; // word name
		struct {
			uint32_t awb_gwd_y_th_max : 8;
			uint32_t awb_gwd_y_th_min : 8;
			uint32_t awb_gwd_y_slope_max : 5;
			uint32_t : 3; // padding bits
			uint32_t awb_gwd_y_slope_min : 8;
		};
	};
	/* AWB_GWD_Y_GAIN_1 12'h0C0 */
	union {
		uint32_t awb_gwd_y_gain_1; // word name
		struct {
			uint32_t awb_gwd_resample_saturation : 1;
			uint32_t : 7; // padding bits
			uint32_t awb_gwd_saturation_th : 6;
			uint32_t : 2; // padding bits
			uint32_t awb_gwd_rto_gray_level_slope : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_RTO_SAT_0 12'h0C4 */
	union {
		uint32_t awb_gwd_rto_sat_0; // word name
		struct {
			uint32_t awb_gwd_r_bias : 12;
			uint32_t : 4; // padding bits
			uint32_t awb_gwd_g_bias : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AWB_GWD_RTO_SAT_1 12'h0C8 */
	union {
		uint32_t awb_gwd_rto_sat_1; // word name
		struct {
			uint32_t awb_gwd_b_bias : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_GAIN_PREV_0 12'h0CC */
	union {
		uint32_t awb_gwd_gain_prev_0; // word name
		struct {
			uint32_t awb_gwd_gain_prev_r : 12;
			uint32_t : 4; // padding bits
			uint32_t awb_gwd_gain_prev_g : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AWB_GWD_GAIN_PREV_1 12'h0D0 */
	union {
		uint32_t awb_gwd_gain_prev_1; // word name
		struct {
			uint32_t awb_gwd_gain_prev_b : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AWB_RTX_Y_MODE 12'h0D4 */
	union {
		uint32_t word_awb_rtx_y_mode; // word name
		struct {
			uint32_t awb_rtx_y_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_CFA_PHASE_EN_0 12'h0D8 */
	union {
		uint32_t awb_rtx_cfa_phase_en_0; // word name
		struct {
			uint32_t awb_cfa_peform_rtx_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t awb_cfa_peform_rtx_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t awb_cfa_peform_rtx_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t awb_cfa_peform_rtx_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* AWB_RTX_CFA_PHASE_EN_1 12'h0DC */
	union {
		uint32_t awb_rtx_cfa_phase_en_1; // word name
		struct {
			uint32_t awb_cfa_peform_rtx_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t awb_rtx_force_performed_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_Y_GAIN_0 12'h0E0 */
	union {
		uint32_t awb_rtx_y_gain_0; // word name
		struct {
			uint32_t awb_rtx_y_th_min : 8;
			uint32_t : 8; // padding bits
			uint32_t awb_rtx_y_th_max : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_Y_GAIN_1 12'h0E4 */
	union {
		uint32_t awb_rtx_y_gain_1; // word name
		struct {
			uint32_t awb_rtx_y_m : 5;
			uint32_t : 3; // padding bits
			uint32_t awb_rtx_dyn_range_th : 5;
			uint32_t : 3; // padding bits
			uint32_t awb_rtx_dyn_range_slope : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TM_EN 12'h0E8 */
	union {
		uint32_t tm_en; // word name
		struct {
			uint32_t tm_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t y_lpf_str : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TM_STRL_0 12'h0EC */
	union {
		uint32_t tm_strl_0; // word name
		struct {
			uint32_t tone_curve_0 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_1 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_1 12'h0F0 */
	union {
		uint32_t tm_strl_1; // word name
		struct {
			uint32_t tone_curve_2 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_3 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_2 12'h0F4 */
	union {
		uint32_t tm_strl_2; // word name
		struct {
			uint32_t tone_curve_4 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_5 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_3 12'h0F8 */
	union {
		uint32_t tm_strl_3; // word name
		struct {
			uint32_t tone_curve_6 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_7 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_4 12'h0FC */
	union {
		uint32_t tm_strl_4; // word name
		struct {
			uint32_t tone_curve_8 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_9 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_5 12'h100 */
	union {
		uint32_t tm_strl_5; // word name
		struct {
			uint32_t tone_curve_10 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_11 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_6 12'h104 */
	union {
		uint32_t tm_strl_6; // word name
		struct {
			uint32_t tone_curve_12 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_13 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_7 12'h108 */
	union {
		uint32_t tm_strl_7; // word name
		struct {
			uint32_t tone_curve_14 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_15 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_8 12'h10C */
	union {
		uint32_t tm_strl_8; // word name
		struct {
			uint32_t tone_curve_16 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_17 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_9 12'h110 */
	union {
		uint32_t tm_strl_9; // word name
		struct {
			uint32_t tone_curve_18 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_19 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_10 12'h114 */
	union {
		uint32_t tm_strl_10; // word name
		struct {
			uint32_t tone_curve_20 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_21 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_11 12'h118 */
	union {
		uint32_t tm_strl_11; // word name
		struct {
			uint32_t tone_curve_22 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_23 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_12 12'h11C */
	union {
		uint32_t tm_strl_12; // word name
		struct {
			uint32_t tone_curve_24 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_25 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_13 12'h120 */
	union {
		uint32_t tm_strl_13; // word name
		struct {
			uint32_t tone_curve_26 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_27 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_14 12'h124 */
	union {
		uint32_t tm_strl_14; // word name
		struct {
			uint32_t tone_curve_28 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_29 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_15 12'h128 */
	union {
		uint32_t tm_strl_15; // word name
		struct {
			uint32_t tone_curve_30 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_31 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_16 12'h12C */
	union {
		uint32_t tm_strl_16; // word name
		struct {
			uint32_t tone_curve_32 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_33 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_17 12'h130 */
	union {
		uint32_t tm_strl_17; // word name
		struct {
			uint32_t tone_curve_34 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_35 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_18 12'h134 */
	union {
		uint32_t tm_strl_18; // word name
		struct {
			uint32_t tone_curve_36 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_37 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_19 12'h138 */
	union {
		uint32_t tm_strl_19; // word name
		struct {
			uint32_t tone_curve_38 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_39 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_20 12'h13C */
	union {
		uint32_t tm_strl_20; // word name
		struct {
			uint32_t tone_curve_40 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_41 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_21 12'h140 */
	union {
		uint32_t tm_strl_21; // word name
		struct {
			uint32_t tone_curve_42 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_43 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_22 12'h144 */
	union {
		uint32_t tm_strl_22; // word name
		struct {
			uint32_t tone_curve_44 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_45 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_23 12'h148 */
	union {
		uint32_t tm_strl_23; // word name
		struct {
			uint32_t tone_curve_46 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_47 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_24 12'h14C */
	union {
		uint32_t tm_strl_24; // word name
		struct {
			uint32_t tone_curve_48 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_49 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_25 12'h150 */
	union {
		uint32_t tm_strl_25; // word name
		struct {
			uint32_t tone_curve_50 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_51 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_26 12'h154 */
	union {
		uint32_t tm_strl_26; // word name
		struct {
			uint32_t tone_curve_52 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_53 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_27 12'h158 */
	union {
		uint32_t tm_strl_27; // word name
		struct {
			uint32_t tone_curve_54 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_55 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_28 12'h15C */
	union {
		uint32_t tm_strl_28; // word name
		struct {
			uint32_t tone_curve_56 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_57 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_29 12'h160 */
	union {
		uint32_t tm_strl_29; // word name
		struct {
			uint32_t tone_curve_58 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_59 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_WB_ENABLE 12'h164 */
	union {
		uint32_t word_wb_enable; // word name
		struct {
			uint32_t wb_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_BILINEAR_0 12'h168 */
	union {
		uint32_t awb_bilinear_0; // word name
		struct {
			uint32_t awb_bilinear_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_BILINEAR_1 12'h16C */
	union {
		uint32_t awb_bilinear_1; // word name
		struct {
			uint32_t awb_bi_rgl_x_cnt_ini : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* AWB_BILINEAR_2 12'h170 */
	union {
		uint32_t awb_bilinear_2; // word name
		struct {
			uint32_t awb_bi_rgl_y_cnt_ini : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* AWB_BILINEAR_3 12'h174 */
	union {
		uint32_t awb_bilinear_3; // word name
		struct {
			uint32_t awb_binear_rgl_x_cnt_step : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_BILINEAR_4 12'h178 */
	union {
		uint32_t awb_bilinear_4; // word name
		struct {
			uint32_t awb_binear_rgl_y_cnt_step : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_BILINEAR_5 12'h17C */
	union {
		uint32_t awb_bilinear_5; // word name
		struct {
			uint32_t awb_binear_rgl_size_x : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_BILINEAR_6 12'h180 */
	union {
		uint32_t awb_bilinear_6; // word name
		struct {
			uint32_t awb_binear_rgl_size_y : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WB_GAIN_0_0 12'h184 */
	union {
		uint32_t wb_gain_0_0; // word name
		struct {
			uint32_t wb_gain_g0_0 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_0 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_0_1 12'h188 */
	union {
		uint32_t wb_gain_0_1; // word name
		struct {
			uint32_t wb_gain_b_0 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_0 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_1_0 12'h18C */
	union {
		uint32_t wb_gain_1_0; // word name
		struct {
			uint32_t wb_gain_g0_1 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_1_1 12'h190 */
	union {
		uint32_t wb_gain_1_1; // word name
		struct {
			uint32_t wb_gain_b_1 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_2_0 12'h194 */
	union {
		uint32_t wb_gain_2_0; // word name
		struct {
			uint32_t wb_gain_g0_2 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_2 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_2_1 12'h198 */
	union {
		uint32_t wb_gain_2_1; // word name
		struct {
			uint32_t wb_gain_b_2 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_2 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_3_0 12'h19C */
	union {
		uint32_t wb_gain_3_0; // word name
		struct {
			uint32_t wb_gain_g0_3 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_3 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_3_1 12'h1A0 */
	union {
		uint32_t wb_gain_3_1; // word name
		struct {
			uint32_t wb_gain_b_3 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_3 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_4_0 12'h1A4 */
	union {
		uint32_t wb_gain_4_0; // word name
		struct {
			uint32_t wb_gain_g0_4 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_4 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_4_1 12'h1A8 */
	union {
		uint32_t wb_gain_4_1; // word name
		struct {
			uint32_t wb_gain_b_4 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_4 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_5_0 12'h1AC */
	union {
		uint32_t wb_gain_5_0; // word name
		struct {
			uint32_t wb_gain_g0_5 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_5 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_5_1 12'h1B0 */
	union {
		uint32_t wb_gain_5_1; // word name
		struct {
			uint32_t wb_gain_b_5 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_5 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_6_0 12'h1B4 */
	union {
		uint32_t wb_gain_6_0; // word name
		struct {
			uint32_t wb_gain_g0_6 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_6 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_6_1 12'h1B8 */
	union {
		uint32_t wb_gain_6_1; // word name
		struct {
			uint32_t wb_gain_b_6 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_6 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_7_0 12'h1BC */
	union {
		uint32_t wb_gain_7_0; // word name
		struct {
			uint32_t wb_gain_g0_7 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_7 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_7_1 12'h1C0 */
	union {
		uint32_t wb_gain_7_1; // word name
		struct {
			uint32_t wb_gain_b_7 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_7 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_8_0 12'h1C4 */
	union {
		uint32_t wb_gain_8_0; // word name
		struct {
			uint32_t wb_gain_g0_8 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_8 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_8_1 12'h1C8 */
	union {
		uint32_t wb_gain_8_1; // word name
		struct {
			uint32_t wb_gain_b_8 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_8 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_9_0 12'h1CC */
	union {
		uint32_t wb_gain_9_0; // word name
		struct {
			uint32_t wb_gain_g0_9 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_9 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_9_1 12'h1D0 */
	union {
		uint32_t wb_gain_9_1; // word name
		struct {
			uint32_t wb_gain_b_9 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_9 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_10_0 12'h1D4 */
	union {
		uint32_t wb_gain_10_0; // word name
		struct {
			uint32_t wb_gain_g0_10 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_10 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_10_1 12'h1D8 */
	union {
		uint32_t wb_gain_10_1; // word name
		struct {
			uint32_t wb_gain_b_10 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_10 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_11_0 12'h1DC */
	union {
		uint32_t wb_gain_11_0; // word name
		struct {
			uint32_t wb_gain_g0_11 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_11 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_11_1 12'h1E0 */
	union {
		uint32_t wb_gain_11_1; // word name
		struct {
			uint32_t wb_gain_b_11 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_11 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_12_0 12'h1E4 */
	union {
		uint32_t wb_gain_12_0; // word name
		struct {
			uint32_t wb_gain_g0_12 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_12 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_12_1 12'h1E8 */
	union {
		uint32_t wb_gain_12_1; // word name
		struct {
			uint32_t wb_gain_b_12 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_12 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_13_0 12'h1EC */
	union {
		uint32_t wb_gain_13_0; // word name
		struct {
			uint32_t wb_gain_g0_13 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_13 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_13_1 12'h1F0 */
	union {
		uint32_t wb_gain_13_1; // word name
		struct {
			uint32_t wb_gain_b_13 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_13 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_14_0 12'h1F4 */
	union {
		uint32_t wb_gain_14_0; // word name
		struct {
			uint32_t wb_gain_g0_14 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_14 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_14_1 12'h1F8 */
	union {
		uint32_t wb_gain_14_1; // word name
		struct {
			uint32_t wb_gain_b_14 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_14 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_15_0 12'h1FC */
	union {
		uint32_t wb_gain_15_0; // word name
		struct {
			uint32_t wb_gain_g0_15 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r_15 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_15_1 12'h200 */
	union {
		uint32_t wb_gain_15_1; // word name
		struct {
			uint32_t wb_gain_b_15 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1_15 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* Y_HIST_MODE 12'h204 */
	union {
		uint32_t y_hist_mode; // word name
		struct {
			uint32_t y_hist_in_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t y_hist_roi_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_Y_HIST_OVERFLOW 12'h208 */
	union {
		uint32_t word_y_hist_overflow; // word name
		struct {
			uint32_t y_hist_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_ROI_X 12'h20C */
	union {
		uint32_t y_hist_roi_x; // word name
		struct {
			uint32_t y_hist_roi_sx : 16;
			uint32_t y_hist_roi_ex : 16;
		};
	};
	/* Y_HIST_ROI_Y 12'h210 */
	union {
		uint32_t y_hist_roi_y; // word name
		struct {
			uint32_t y_hist_roi_sy : 16;
			uint32_t y_hist_roi_ey : 16;
		};
	};
	/* WORD_Y_HIST_OFFSET 12'h214 */
	union {
		uint32_t word_y_hist_offset; // word name
		struct {
			uint32_t y_hist_offset : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_0 12'h218 */
	union {
		uint32_t y_hist_0; // word name
		struct {
			uint32_t y_hist_hist_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_1 12'h21C */
	union {
		uint32_t y_hist_1; // word name
		struct {
			uint32_t y_hist_hist_1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_2 12'h220 */
	union {
		uint32_t y_hist_2; // word name
		struct {
			uint32_t y_hist_hist_2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_3 12'h224 */
	union {
		uint32_t y_hist_3; // word name
		struct {
			uint32_t y_hist_hist_3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_4 12'h228 */
	union {
		uint32_t y_hist_4; // word name
		struct {
			uint32_t y_hist_hist_4 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_5 12'h22C */
	union {
		uint32_t y_hist_5; // word name
		struct {
			uint32_t y_hist_hist_5 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_6 12'h230 */
	union {
		uint32_t y_hist_6; // word name
		struct {
			uint32_t y_hist_hist_6 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_7 12'h234 */
	union {
		uint32_t y_hist_7; // word name
		struct {
			uint32_t y_hist_hist_7 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_8 12'h238 */
	union {
		uint32_t y_hist_8; // word name
		struct {
			uint32_t y_hist_hist_8 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_9 12'h23C */
	union {
		uint32_t y_hist_9; // word name
		struct {
			uint32_t y_hist_hist_9 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_10 12'h240 */
	union {
		uint32_t y_hist_10; // word name
		struct {
			uint32_t y_hist_hist_10 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_11 12'h244 */
	union {
		uint32_t y_hist_11; // word name
		struct {
			uint32_t y_hist_hist_11 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_12 12'h248 */
	union {
		uint32_t y_hist_12; // word name
		struct {
			uint32_t y_hist_hist_12 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_13 12'h24C */
	union {
		uint32_t y_hist_13; // word name
		struct {
			uint32_t y_hist_hist_13 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_14 12'h250 */
	union {
		uint32_t y_hist_14; // word name
		struct {
			uint32_t y_hist_hist_14 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_15 12'h254 */
	union {
		uint32_t y_hist_15; // word name
		struct {
			uint32_t y_hist_hist_15 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_16 12'h258 */
	union {
		uint32_t y_hist_16; // word name
		struct {
			uint32_t y_hist_hist_16 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_17 12'h25C */
	union {
		uint32_t y_hist_17; // word name
		struct {
			uint32_t y_hist_hist_17 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_18 12'h260 */
	union {
		uint32_t y_hist_18; // word name
		struct {
			uint32_t y_hist_hist_18 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_19 12'h264 */
	union {
		uint32_t y_hist_19; // word name
		struct {
			uint32_t y_hist_hist_19 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_20 12'h268 */
	union {
		uint32_t y_hist_20; // word name
		struct {
			uint32_t y_hist_hist_20 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_21 12'h26C */
	union {
		uint32_t y_hist_21; // word name
		struct {
			uint32_t y_hist_hist_21 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_22 12'h270 */
	union {
		uint32_t y_hist_22; // word name
		struct {
			uint32_t y_hist_hist_22 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_23 12'h274 */
	union {
		uint32_t y_hist_23; // word name
		struct {
			uint32_t y_hist_hist_23 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_24 12'h278 */
	union {
		uint32_t y_hist_24; // word name
		struct {
			uint32_t y_hist_hist_24 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_25 12'h27C */
	union {
		uint32_t y_hist_25; // word name
		struct {
			uint32_t y_hist_hist_25 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_26 12'h280 */
	union {
		uint32_t y_hist_26; // word name
		struct {
			uint32_t y_hist_hist_26 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_27 12'h284 */
	union {
		uint32_t y_hist_27; // word name
		struct {
			uint32_t y_hist_hist_27 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_28 12'h288 */
	union {
		uint32_t y_hist_28; // word name
		struct {
			uint32_t y_hist_hist_28 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_29 12'h28C */
	union {
		uint32_t y_hist_29; // word name
		struct {
			uint32_t y_hist_hist_29 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_30 12'h290 */
	union {
		uint32_t y_hist_30; // word name
		struct {
			uint32_t y_hist_hist_30 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_31 12'h294 */
	union {
		uint32_t y_hist_31; // word name
		struct {
			uint32_t y_hist_hist_31 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_32 12'h298 */
	union {
		uint32_t y_hist_32; // word name
		struct {
			uint32_t y_hist_hist_32 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_33 12'h29C */
	union {
		uint32_t y_hist_33; // word name
		struct {
			uint32_t y_hist_hist_33 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_34 12'h2A0 */
	union {
		uint32_t y_hist_34; // word name
		struct {
			uint32_t y_hist_hist_34 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_35 12'h2A4 */
	union {
		uint32_t y_hist_35; // word name
		struct {
			uint32_t y_hist_hist_35 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_36 12'h2A8 */
	union {
		uint32_t y_hist_36; // word name
		struct {
			uint32_t y_hist_hist_36 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_37 12'h2AC */
	union {
		uint32_t y_hist_37; // word name
		struct {
			uint32_t y_hist_hist_37 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_38 12'h2B0 */
	union {
		uint32_t y_hist_38; // word name
		struct {
			uint32_t y_hist_hist_38 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_39 12'h2B4 */
	union {
		uint32_t y_hist_39; // word name
		struct {
			uint32_t y_hist_hist_39 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_40 12'h2B8 */
	union {
		uint32_t y_hist_40; // word name
		struct {
			uint32_t y_hist_hist_40 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_41 12'h2BC */
	union {
		uint32_t y_hist_41; // word name
		struct {
			uint32_t y_hist_hist_41 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_42 12'h2C0 */
	union {
		uint32_t y_hist_42; // word name
		struct {
			uint32_t y_hist_hist_42 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_43 12'h2C4 */
	union {
		uint32_t y_hist_43; // word name
		struct {
			uint32_t y_hist_hist_43 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_44 12'h2C8 */
	union {
		uint32_t y_hist_44; // word name
		struct {
			uint32_t y_hist_hist_44 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_45 12'h2CC */
	union {
		uint32_t y_hist_45; // word name
		struct {
			uint32_t y_hist_hist_45 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_46 12'h2D0 */
	union {
		uint32_t y_hist_46; // word name
		struct {
			uint32_t y_hist_hist_46 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_47 12'h2D4 */
	union {
		uint32_t y_hist_47; // word name
		struct {
			uint32_t y_hist_hist_47 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_48 12'h2D8 */
	union {
		uint32_t y_hist_48; // word name
		struct {
			uint32_t y_hist_hist_48 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_49 12'h2DC */
	union {
		uint32_t y_hist_49; // word name
		struct {
			uint32_t y_hist_hist_49 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_50 12'h2E0 */
	union {
		uint32_t y_hist_50; // word name
		struct {
			uint32_t y_hist_hist_50 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_51 12'h2E4 */
	union {
		uint32_t y_hist_51; // word name
		struct {
			uint32_t y_hist_hist_51 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_52 12'h2E8 */
	union {
		uint32_t y_hist_52; // word name
		struct {
			uint32_t y_hist_hist_52 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_53 12'h2EC */
	union {
		uint32_t y_hist_53; // word name
		struct {
			uint32_t y_hist_hist_53 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_54 12'h2F0 */
	union {
		uint32_t y_hist_54; // word name
		struct {
			uint32_t y_hist_hist_54 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_55 12'h2F4 */
	union {
		uint32_t y_hist_55; // word name
		struct {
			uint32_t y_hist_hist_55 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_56 12'h2F8 */
	union {
		uint32_t y_hist_56; // word name
		struct {
			uint32_t y_hist_hist_56 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_57 12'h2FC */
	union {
		uint32_t y_hist_57; // word name
		struct {
			uint32_t y_hist_hist_57 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_58 12'h300 */
	union {
		uint32_t y_hist_58; // word name
		struct {
			uint32_t y_hist_hist_58 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_59 12'h304 */
	union {
		uint32_t y_hist_59; // word name
		struct {
			uint32_t y_hist_hist_59 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROI_Y_AVG_MODE 12'h308 */
	union {
		uint32_t roi_y_avg_mode; // word name
		struct {
			uint32_t roi_y_avg_in_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROI_Y_AVG_ENABLE 12'h30C */
	union {
		uint32_t roi_y_avg_enable; // word name
		struct {
			uint32_t roi_0_y_avg_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_1_y_avg_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_2_y_avg_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_3_y_avg_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* Y_AVG_ROI_0_X 12'h310 */
	union {
		uint32_t y_avg_roi_0_x; // word name
		struct {
			uint32_t roi_0_y_avg_sx : 16;
			uint32_t roi_0_y_avg_ex : 16;
		};
	};
	/* Y_AVG_ROI_0_Y 12'h314 */
	union {
		uint32_t y_avg_roi_0_y; // word name
		struct {
			uint32_t roi_0_y_avg_sy : 16;
			uint32_t roi_0_y_avg_ey : 16;
		};
	};
	/* Y_AVG_ROI_1_X 12'h318 */
	union {
		uint32_t y_avg_roi_1_x; // word name
		struct {
			uint32_t roi_1_y_avg_sx : 16;
			uint32_t roi_1_y_avg_ex : 16;
		};
	};
	/* Y_AVG_ROI_1_Y 12'h31C */
	union {
		uint32_t y_avg_roi_1_y; // word name
		struct {
			uint32_t roi_1_y_avg_sy : 16;
			uint32_t roi_1_y_avg_ey : 16;
		};
	};
	/* Y_AVG_ROI_2_X 12'h320 */
	union {
		uint32_t y_avg_roi_2_x; // word name
		struct {
			uint32_t roi_2_y_avg_sx : 16;
			uint32_t roi_2_y_avg_ex : 16;
		};
	};
	/* Y_AVG_ROI_2_Y 12'h324 */
	union {
		uint32_t y_avg_roi_2_y; // word name
		struct {
			uint32_t roi_2_y_avg_sy : 16;
			uint32_t roi_2_y_avg_ey : 16;
		};
	};
	/* Y_AVG_ROI_3_X 12'h328 */
	union {
		uint32_t y_avg_roi_3_x; // word name
		struct {
			uint32_t roi_3_y_avg_sx : 16;
			uint32_t roi_3_y_avg_ex : 16;
		};
	};
	/* Y_AVG_ROI_3_Y 12'h32C */
	union {
		uint32_t y_avg_roi_3_y; // word name
		struct {
			uint32_t roi_3_y_avg_sy : 16;
			uint32_t roi_3_y_avg_ey : 16;
		};
	};
	/* Y_AVG_ROI_PIX_NUM_0 12'h330 */
	union {
		uint32_t y_avg_roi_pix_num_0; // word name
		struct {
			uint32_t roi_0_y_avg_pix_num : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_NUM_1 12'h334 */
	union {
		uint32_t y_avg_roi_pix_num_1; // word name
		struct {
			uint32_t roi_1_y_avg_pix_num : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_NUM_2 12'h338 */
	union {
		uint32_t y_avg_roi_pix_num_2; // word name
		struct {
			uint32_t roi_2_y_avg_pix_num : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_NUM_3 12'h33C */
	union {
		uint32_t y_avg_roi_pix_num_3; // word name
		struct {
			uint32_t roi_3_y_avg_pix_num : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_REMAINDER_0 12'h340 */
	union {
		uint32_t y_avg_roi_remainder_0; // word name
		struct {
			uint32_t roi_0_y_avg_remainder : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_REMAINDER_1 12'h344 */
	union {
		uint32_t y_avg_roi_remainder_1; // word name
		struct {
			uint32_t roi_1_y_avg_remainder : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_REMAINDER_2 12'h348 */
	union {
		uint32_t y_avg_roi_remainder_2; // word name
		struct {
			uint32_t roi_2_y_avg_remainder : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_REMAINDER_3 12'h34C */
	union {
		uint32_t y_avg_roi_remainder_3; // word name
		struct {
			uint32_t roi_3_y_avg_remainder : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_AVG_0 12'h350 */
	union {
		uint32_t y_avg_roi_pix_avg_0; // word name
		struct {
			uint32_t roi_0_y_avg_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_y_avg_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_AVG_1 12'h354 */
	union {
		uint32_t y_avg_roi_pix_avg_1; // word name
		struct {
			uint32_t roi_2_y_avg_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_y_avg_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* ROI_CONTRAST_ENABLE 12'h358 */
	union {
		uint32_t roi_contrast_enable; // word name
		struct {
			uint32_t roi_0_contrast_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_1_contrast_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_2_contrast_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_3_contrast_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CONTRAST_ROI_0_X 12'h35C */
	union {
		uint32_t contrast_roi_0_x; // word name
		struct {
			uint32_t roi_0_contrast_sx : 16;
			uint32_t roi_0_contrast_ex : 16;
		};
	};
	/* CONTRAST_ROI_0_Y 12'h360 */
	union {
		uint32_t contrast_roi_0_y; // word name
		struct {
			uint32_t roi_0_contrast_sy : 16;
			uint32_t roi_0_contrast_ey : 16;
		};
	};
	/* CONTRAST_ROI_1_X 12'h364 */
	union {
		uint32_t contrast_roi_1_x; // word name
		struct {
			uint32_t roi_1_contrast_sx : 16;
			uint32_t roi_1_contrast_ex : 16;
		};
	};
	/* CONTRAST_ROI_1_Y 12'h368 */
	union {
		uint32_t contrast_roi_1_y; // word name
		struct {
			uint32_t roi_1_contrast_sy : 16;
			uint32_t roi_1_contrast_ey : 16;
		};
	};
	/* CONTRAST_ROI_2_X 12'h36C */
	union {
		uint32_t contrast_roi_2_x; // word name
		struct {
			uint32_t roi_2_contrast_sx : 16;
			uint32_t roi_2_contrast_ex : 16;
		};
	};
	/* CONTRAST_ROI_2_Y 12'h370 */
	union {
		uint32_t contrast_roi_2_y; // word name
		struct {
			uint32_t roi_2_contrast_sy : 16;
			uint32_t roi_2_contrast_ey : 16;
		};
	};
	/* CONTRAST_ROI_3_X 12'h374 */
	union {
		uint32_t contrast_roi_3_x; // word name
		struct {
			uint32_t roi_3_contrast_sx : 16;
			uint32_t roi_3_contrast_ex : 16;
		};
	};
	/* CONTRAST_ROI_3_Y 12'h378 */
	union {
		uint32_t contrast_roi_3_y; // word name
		struct {
			uint32_t roi_3_contrast_sy : 16;
			uint32_t roi_3_contrast_ey : 16;
		};
	};
	/* CONTRAST_PIX_NUM_0 12'h37C */
	union {
		uint32_t contrast_pix_num_0; // word name
		struct {
			uint32_t roi_0_contrast_pix_num : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_PIX_NUM_1 12'h380 */
	union {
		uint32_t contrast_pix_num_1; // word name
		struct {
			uint32_t roi_1_contrast_pix_num : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_PIX_NUM_2 12'h384 */
	union {
		uint32_t contrast_pix_num_2; // word name
		struct {
			uint32_t roi_2_contrast_pix_num : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_PIX_NUM_3 12'h388 */
	union {
		uint32_t contrast_pix_num_3; // word name
		struct {
			uint32_t roi_3_contrast_pix_num : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_H1_AVG_0 12'h38C */
	union {
		uint32_t contrast_h1_avg_0; // word name
		struct {
			uint32_t roi_0_contrast_h1_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_contrast_h1_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_H1_AVG_1 12'h390 */
	union {
		uint32_t contrast_h1_avg_1; // word name
		struct {
			uint32_t roi_2_contrast_h1_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_contrast_h1_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_H2_AVG_0 12'h394 */
	union {
		uint32_t contrast_h2_avg_0; // word name
		struct {
			uint32_t roi_0_contrast_h2_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_contrast_h2_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_H2_AVG_1 12'h398 */
	union {
		uint32_t contrast_h2_avg_1; // word name
		struct {
			uint32_t roi_2_contrast_h2_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_contrast_h2_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_V1_AVG_0 12'h39C */
	union {
		uint32_t contrast_v1_avg_0; // word name
		struct {
			uint32_t roi_0_contrast_v1_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_contrast_v1_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_V1_AVG_1 12'h3A0 */
	union {
		uint32_t contrast_v1_avg_1; // word name
		struct {
			uint32_t roi_2_contrast_v1_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_contrast_v1_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_V2_AVG_0 12'h3A4 */
	union {
		uint32_t contrast_v2_avg_0; // word name
		struct {
			uint32_t roi_0_contrast_v2_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_contrast_v2_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_V2_AVG_1 12'h3A8 */
	union {
		uint32_t contrast_v2_avg_1; // word name
		struct {
			uint32_t roi_2_contrast_v2_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_contrast_v2_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* ROI_AWB_GWD_ENABLE 12'h3AC */
	union {
		uint32_t roi_awb_gwd_enable; // word name
		struct {
			uint32_t roi_0_awb_gwd_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_ROI_0_X 12'h3B0 */
	union {
		uint32_t awb_gwd_roi_0_x; // word name
		struct {
			uint32_t roi_0_awb_gwd_sx : 16;
			uint32_t roi_0_awb_gwd_ex : 16;
		};
	};
	/* AWB_GWD_ROI_0_Y 12'h3B4 */
	union {
		uint32_t awb_gwd_roi_0_y; // word name
		struct {
			uint32_t roi_0_awb_gwd_sy : 16;
			uint32_t roi_0_awb_gwd_ey : 16;
		};
	};
	/* AWB_GWD_SUM_G0_0 12'h3B8 */
	union {
		uint32_t awb_gwd_sum_g0_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_sum_g0 : 32;
		};
	};
	/* AWB_GWD_SUM_R_0 12'h3BC */
	union {
		uint32_t awb_gwd_sum_r_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_sum_r : 32;
		};
	};
	/* AWB_GWD_SUM_B_0 12'h3C0 */
	union {
		uint32_t awb_gwd_sum_b_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_sum_b : 32;
		};
	};
	/* AWB_GWD_SUM_G1_0 12'h3C4 */
	union {
		uint32_t awb_gwd_sum_g1_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_sum_g1 : 32;
		};
	};
	/* AWB_GWD_NORM_G0_0 12'h3C8 */
	union {
		uint32_t awb_gwd_norm_g0_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_norm_g0 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_NORM_R_0 12'h3CC */
	union {
		uint32_t awb_gwd_norm_r_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_norm_r : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_NORM_B_0 12'h3D0 */
	union {
		uint32_t awb_gwd_norm_b_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_norm_b : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_NORM_G1_0 12'h3D4 */
	union {
		uint32_t awb_gwd_norm_g1_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_norm_g1 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_AVG_MODE 12'h3D8 */
	union {
		uint32_t rgl_y_avg_mode; // word name
		struct {
			uint32_t rgl_y_avg_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rgl_y_avg_in_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_AVG_BLK 12'h3DC */
	union {
		uint32_t rgl_y_avg_blk; // word name
		struct {
			uint32_t rgl_y_avg_blk_ht : 14;
			uint32_t : 2; // padding bits
			uint32_t rgl_y_avg_blk_wd : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_RGL_Y_AVG_PIX_NUM 12'h3E0 */
	union {
		uint32_t word_rgl_y_avg_pix_num; // word name
		struct {
			uint32_t rgl_y_avg_pix_num : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_AVG_X 12'h3E4 */
	union {
		uint32_t rgl_y_avg_x; // word name
		struct {
			uint32_t rgl_y_avg_sx : 16;
			uint32_t rgl_y_avg_ex : 16;
		};
	};
	/* RGL_Y_AVG_Y 12'h3E8 */
	union {
		uint32_t rgl_y_avg_y; // word name
		struct {
			uint32_t rgl_y_avg_sy : 16;
			uint32_t rgl_y_avg_ey : 16;
		};
	};
	/* RGL_CONTRAST_MODE 12'h3EC */
	union {
		uint32_t rgl_contrast_mode; // word name
		struct {
			uint32_t rgl_contrast_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_CONTRAST_BLK 12'h3F0 */
	union {
		uint32_t rgl_contrast_blk; // word name
		struct {
			uint32_t rgl_contrast_blk_ht : 14;
			uint32_t : 2; // padding bits
			uint32_t rgl_contrast_blk_wd : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_RGL_CONTRAST_PIX_NUM 12'h3F4 */
	union {
		uint32_t word_rgl_contrast_pix_num; // word name
		struct {
			uint32_t rgl_contrast_pix_num : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_CONTRAST_X 12'h3F8 */
	union {
		uint32_t rgl_contrast_x; // word name
		struct {
			uint32_t rgl_contrast_sx : 16;
			uint32_t rgl_contrast_ex : 16;
		};
	};
	/* RGL_CONTRAST_Y 12'h3FC */
	union {
		uint32_t rgl_contrast_y; // word name
		struct {
			uint32_t rgl_contrast_sy : 16;
			uint32_t rgl_contrast_ey : 16;
		};
	};
	/* RGL_AWB_RTX_MODE 12'h400 */
	union {
		uint32_t rgl_awb_rtx_mode; // word name
		struct {
			uint32_t rgl_awb_rtx_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_AWB_RTX_BLK 12'h404 */
	union {
		uint32_t rgl_awb_rtx_blk; // word name
		struct {
			uint32_t rgl_awb_rtx_blk_ht : 14;
			uint32_t : 2; // padding bits
			uint32_t rgl_awb_rtx_blk_wd : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* RGL_AWB_RTX_X 12'h408 */
	union {
		uint32_t rgl_awb_rtx_x; // word name
		struct {
			uint32_t rgl_awb_rtx_sx : 16;
			uint32_t rgl_awb_rtx_ex : 16;
		};
	};
	/* RGL_AWB_RTX_Y 12'h40C */
	union {
		uint32_t rgl_awb_rtx_y; // word name
		struct {
			uint32_t rgl_awb_rtx_sy : 16;
			uint32_t rgl_awb_rtx_ey : 16;
		};
	};
	/* WORD_CSR2SRAM_SEL 12'h410 */
	union {
		uint32_t word_csr2sram_sel; // word name
		struct {
			uint32_t csr2sram_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AE_RGL_ADDR 12'h414 */
	union {
		uint32_t ae_rgl_addr; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_addr : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AF_RGL_ADDR 12'h418 */
	union {
		uint32_t af_rgl_addr; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_addr : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RGL_RTX_ADDR 12'h41C */
	union {
		uint32_t awb_rgl_rtx_addr; // word name
		struct {
			uint32_t awb_rtx_avg_r_addr : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AE_RGL_R_DATA 12'h420 */
	union {
		uint32_t ae_rgl_r_data; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AF_RGL_R_DATA 12'h424 */
	union {
		uint32_t af_rgl_r_data; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RGL_RTX_R_DATA 12'h428 */
	union {
		uint32_t awb_rgl_rtx_r_data; // word name
		struct {
			uint32_t awb_rtx_avg_r_data : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* CFA_PHASE_EN_SET_0 12'h42C */
	union {
		uint32_t cfa_phase_en_set_0; // word name
		struct {
			uint32_t cfa_phase_en_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CFA_PHASE_EN_SET_1 12'h430 */
	union {
		uint32_t cfa_phase_en_set_1; // word name
		struct {
			uint32_t cfa_phase_en_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_6 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_7 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CFA_PHASE_EN_SET_2 12'h434 */
	union {
		uint32_t cfa_phase_en_set_2; // word name
		struct {
			uint32_t cfa_phase_en_8 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_9 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_10 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_11 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CFA_PHASE_EN_SET_3 12'h438 */
	union {
		uint32_t cfa_phase_en_set_3; // word name
		struct {
			uint32_t cfa_phase_en_12 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_13 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_14 : 1;
			uint32_t : 7; // padding bits
			uint32_t cfa_phase_en_15 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RGB_HIST_CTRL 12'h43C */
	union {
		uint32_t rgb_hist_ctrl; // word name
		struct {
			uint32_t rgb_hist_roi_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rgb_hist_offset : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* RGB_HIST_STAT 12'h440 */
	union {
		uint32_t rgb_hist_stat; // word name
		struct {
			uint32_t r_hist_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t g_hist_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t b_hist_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGB_HIST_ROI_X 12'h444 */
	union {
		uint32_t rgb_hist_roi_x; // word name
		struct {
			uint32_t rgb_hist_roi_sx : 16;
			uint32_t rgb_hist_roi_ex : 16;
		};
	};
	/* RGB_HIST_ROI_Y 12'h448 */
	union {
		uint32_t rgb_hist_roi_y; // word name
		struct {
			uint32_t rgb_hist_roi_sy : 16;
			uint32_t rgb_hist_roi_ey : 16;
		};
	};
	/* R_HIST_0 12'h44C */
	union {
		uint32_t r_hist_0; // word name
		struct {
			uint32_t r_hist_hist_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_1 12'h450 */
	union {
		uint32_t r_hist_1; // word name
		struct {
			uint32_t r_hist_hist_1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_2 12'h454 */
	union {
		uint32_t r_hist_2; // word name
		struct {
			uint32_t r_hist_hist_2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_3 12'h458 */
	union {
		uint32_t r_hist_3; // word name
		struct {
			uint32_t r_hist_hist_3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_4 12'h45C */
	union {
		uint32_t r_hist_4; // word name
		struct {
			uint32_t r_hist_hist_4 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_5 12'h460 */
	union {
		uint32_t r_hist_5; // word name
		struct {
			uint32_t r_hist_hist_5 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_6 12'h464 */
	union {
		uint32_t r_hist_6; // word name
		struct {
			uint32_t r_hist_hist_6 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_7 12'h468 */
	union {
		uint32_t r_hist_7; // word name
		struct {
			uint32_t r_hist_hist_7 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_8 12'h46C */
	union {
		uint32_t r_hist_8; // word name
		struct {
			uint32_t r_hist_hist_8 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_9 12'h470 */
	union {
		uint32_t r_hist_9; // word name
		struct {
			uint32_t r_hist_hist_9 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_10 12'h474 */
	union {
		uint32_t r_hist_10; // word name
		struct {
			uint32_t r_hist_hist_10 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_11 12'h478 */
	union {
		uint32_t r_hist_11; // word name
		struct {
			uint32_t r_hist_hist_11 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_12 12'h47C */
	union {
		uint32_t r_hist_12; // word name
		struct {
			uint32_t r_hist_hist_12 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_13 12'h480 */
	union {
		uint32_t r_hist_13; // word name
		struct {
			uint32_t r_hist_hist_13 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_14 12'h484 */
	union {
		uint32_t r_hist_14; // word name
		struct {
			uint32_t r_hist_hist_14 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_15 12'h488 */
	union {
		uint32_t r_hist_15; // word name
		struct {
			uint32_t r_hist_hist_15 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_16 12'h48C */
	union {
		uint32_t r_hist_16; // word name
		struct {
			uint32_t r_hist_hist_16 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_17 12'h490 */
	union {
		uint32_t r_hist_17; // word name
		struct {
			uint32_t r_hist_hist_17 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_18 12'h494 */
	union {
		uint32_t r_hist_18; // word name
		struct {
			uint32_t r_hist_hist_18 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_19 12'h498 */
	union {
		uint32_t r_hist_19; // word name
		struct {
			uint32_t r_hist_hist_19 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_20 12'h49C */
	union {
		uint32_t r_hist_20; // word name
		struct {
			uint32_t r_hist_hist_20 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_21 12'h4A0 */
	union {
		uint32_t r_hist_21; // word name
		struct {
			uint32_t r_hist_hist_21 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_22 12'h4A4 */
	union {
		uint32_t r_hist_22; // word name
		struct {
			uint32_t r_hist_hist_22 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_23 12'h4A8 */
	union {
		uint32_t r_hist_23; // word name
		struct {
			uint32_t r_hist_hist_23 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_24 12'h4AC */
	union {
		uint32_t r_hist_24; // word name
		struct {
			uint32_t r_hist_hist_24 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_25 12'h4B0 */
	union {
		uint32_t r_hist_25; // word name
		struct {
			uint32_t r_hist_hist_25 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_26 12'h4B4 */
	union {
		uint32_t r_hist_26; // word name
		struct {
			uint32_t r_hist_hist_26 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_27 12'h4B8 */
	union {
		uint32_t r_hist_27; // word name
		struct {
			uint32_t r_hist_hist_27 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_28 12'h4BC */
	union {
		uint32_t r_hist_28; // word name
		struct {
			uint32_t r_hist_hist_28 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_29 12'h4C0 */
	union {
		uint32_t r_hist_29; // word name
		struct {
			uint32_t r_hist_hist_29 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_30 12'h4C4 */
	union {
		uint32_t r_hist_30; // word name
		struct {
			uint32_t r_hist_hist_30 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_31 12'h4C8 */
	union {
		uint32_t r_hist_31; // word name
		struct {
			uint32_t r_hist_hist_31 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_32 12'h4CC */
	union {
		uint32_t r_hist_32; // word name
		struct {
			uint32_t r_hist_hist_32 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_33 12'h4D0 */
	union {
		uint32_t r_hist_33; // word name
		struct {
			uint32_t r_hist_hist_33 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_34 12'h4D4 */
	union {
		uint32_t r_hist_34; // word name
		struct {
			uint32_t r_hist_hist_34 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_35 12'h4D8 */
	union {
		uint32_t r_hist_35; // word name
		struct {
			uint32_t r_hist_hist_35 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_36 12'h4DC */
	union {
		uint32_t r_hist_36; // word name
		struct {
			uint32_t r_hist_hist_36 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_37 12'h4E0 */
	union {
		uint32_t r_hist_37; // word name
		struct {
			uint32_t r_hist_hist_37 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_38 12'h4E4 */
	union {
		uint32_t r_hist_38; // word name
		struct {
			uint32_t r_hist_hist_38 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_39 12'h4E8 */
	union {
		uint32_t r_hist_39; // word name
		struct {
			uint32_t r_hist_hist_39 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_40 12'h4EC */
	union {
		uint32_t r_hist_40; // word name
		struct {
			uint32_t r_hist_hist_40 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_41 12'h4F0 */
	union {
		uint32_t r_hist_41; // word name
		struct {
			uint32_t r_hist_hist_41 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_42 12'h4F4 */
	union {
		uint32_t r_hist_42; // word name
		struct {
			uint32_t r_hist_hist_42 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_43 12'h4F8 */
	union {
		uint32_t r_hist_43; // word name
		struct {
			uint32_t r_hist_hist_43 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_44 12'h4FC */
	union {
		uint32_t r_hist_44; // word name
		struct {
			uint32_t r_hist_hist_44 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_45 12'h500 */
	union {
		uint32_t r_hist_45; // word name
		struct {
			uint32_t r_hist_hist_45 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_46 12'h504 */
	union {
		uint32_t r_hist_46; // word name
		struct {
			uint32_t r_hist_hist_46 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_47 12'h508 */
	union {
		uint32_t r_hist_47; // word name
		struct {
			uint32_t r_hist_hist_47 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_48 12'h50C */
	union {
		uint32_t r_hist_48; // word name
		struct {
			uint32_t r_hist_hist_48 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_49 12'h510 */
	union {
		uint32_t r_hist_49; // word name
		struct {
			uint32_t r_hist_hist_49 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_50 12'h514 */
	union {
		uint32_t r_hist_50; // word name
		struct {
			uint32_t r_hist_hist_50 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_51 12'h518 */
	union {
		uint32_t r_hist_51; // word name
		struct {
			uint32_t r_hist_hist_51 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_52 12'h51C */
	union {
		uint32_t r_hist_52; // word name
		struct {
			uint32_t r_hist_hist_52 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_53 12'h520 */
	union {
		uint32_t r_hist_53; // word name
		struct {
			uint32_t r_hist_hist_53 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_54 12'h524 */
	union {
		uint32_t r_hist_54; // word name
		struct {
			uint32_t r_hist_hist_54 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_55 12'h528 */
	union {
		uint32_t r_hist_55; // word name
		struct {
			uint32_t r_hist_hist_55 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_56 12'h52C */
	union {
		uint32_t r_hist_56; // word name
		struct {
			uint32_t r_hist_hist_56 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_57 12'h530 */
	union {
		uint32_t r_hist_57; // word name
		struct {
			uint32_t r_hist_hist_57 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_58 12'h534 */
	union {
		uint32_t r_hist_58; // word name
		struct {
			uint32_t r_hist_hist_58 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_HIST_59 12'h538 */
	union {
		uint32_t r_hist_59; // word name
		struct {
			uint32_t r_hist_hist_59 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_0 12'h53C */
	union {
		uint32_t g_hist_0; // word name
		struct {
			uint32_t g_hist_hist_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_1 12'h540 */
	union {
		uint32_t g_hist_1; // word name
		struct {
			uint32_t g_hist_hist_1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_2 12'h544 */
	union {
		uint32_t g_hist_2; // word name
		struct {
			uint32_t g_hist_hist_2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_3 12'h548 */
	union {
		uint32_t g_hist_3; // word name
		struct {
			uint32_t g_hist_hist_3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_4 12'h54C */
	union {
		uint32_t g_hist_4; // word name
		struct {
			uint32_t g_hist_hist_4 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_5 12'h550 */
	union {
		uint32_t g_hist_5; // word name
		struct {
			uint32_t g_hist_hist_5 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_6 12'h554 */
	union {
		uint32_t g_hist_6; // word name
		struct {
			uint32_t g_hist_hist_6 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_7 12'h558 */
	union {
		uint32_t g_hist_7; // word name
		struct {
			uint32_t g_hist_hist_7 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_8 12'h55C */
	union {
		uint32_t g_hist_8; // word name
		struct {
			uint32_t g_hist_hist_8 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_9 12'h560 */
	union {
		uint32_t g_hist_9; // word name
		struct {
			uint32_t g_hist_hist_9 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_10 12'h564 */
	union {
		uint32_t g_hist_10; // word name
		struct {
			uint32_t g_hist_hist_10 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_11 12'h568 */
	union {
		uint32_t g_hist_11; // word name
		struct {
			uint32_t g_hist_hist_11 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_12 12'h56C */
	union {
		uint32_t g_hist_12; // word name
		struct {
			uint32_t g_hist_hist_12 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_13 12'h570 */
	union {
		uint32_t g_hist_13; // word name
		struct {
			uint32_t g_hist_hist_13 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_14 12'h574 */
	union {
		uint32_t g_hist_14; // word name
		struct {
			uint32_t g_hist_hist_14 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_15 12'h578 */
	union {
		uint32_t g_hist_15; // word name
		struct {
			uint32_t g_hist_hist_15 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_16 12'h57C */
	union {
		uint32_t g_hist_16; // word name
		struct {
			uint32_t g_hist_hist_16 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_17 12'h580 */
	union {
		uint32_t g_hist_17; // word name
		struct {
			uint32_t g_hist_hist_17 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_18 12'h584 */
	union {
		uint32_t g_hist_18; // word name
		struct {
			uint32_t g_hist_hist_18 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_19 12'h588 */
	union {
		uint32_t g_hist_19; // word name
		struct {
			uint32_t g_hist_hist_19 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_20 12'h58C */
	union {
		uint32_t g_hist_20; // word name
		struct {
			uint32_t g_hist_hist_20 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_21 12'h590 */
	union {
		uint32_t g_hist_21; // word name
		struct {
			uint32_t g_hist_hist_21 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_22 12'h594 */
	union {
		uint32_t g_hist_22; // word name
		struct {
			uint32_t g_hist_hist_22 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_23 12'h598 */
	union {
		uint32_t g_hist_23; // word name
		struct {
			uint32_t g_hist_hist_23 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_24 12'h59C */
	union {
		uint32_t g_hist_24; // word name
		struct {
			uint32_t g_hist_hist_24 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_25 12'h5A0 */
	union {
		uint32_t g_hist_25; // word name
		struct {
			uint32_t g_hist_hist_25 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_26 12'h5A4 */
	union {
		uint32_t g_hist_26; // word name
		struct {
			uint32_t g_hist_hist_26 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_27 12'h5A8 */
	union {
		uint32_t g_hist_27; // word name
		struct {
			uint32_t g_hist_hist_27 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_28 12'h5AC */
	union {
		uint32_t g_hist_28; // word name
		struct {
			uint32_t g_hist_hist_28 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_29 12'h5B0 */
	union {
		uint32_t g_hist_29; // word name
		struct {
			uint32_t g_hist_hist_29 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_30 12'h5B4 */
	union {
		uint32_t g_hist_30; // word name
		struct {
			uint32_t g_hist_hist_30 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_31 12'h5B8 */
	union {
		uint32_t g_hist_31; // word name
		struct {
			uint32_t g_hist_hist_31 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_32 12'h5BC */
	union {
		uint32_t g_hist_32; // word name
		struct {
			uint32_t g_hist_hist_32 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_33 12'h5C0 */
	union {
		uint32_t g_hist_33; // word name
		struct {
			uint32_t g_hist_hist_33 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_34 12'h5C4 */
	union {
		uint32_t g_hist_34; // word name
		struct {
			uint32_t g_hist_hist_34 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_35 12'h5C8 */
	union {
		uint32_t g_hist_35; // word name
		struct {
			uint32_t g_hist_hist_35 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_36 12'h5CC */
	union {
		uint32_t g_hist_36; // word name
		struct {
			uint32_t g_hist_hist_36 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_37 12'h5D0 */
	union {
		uint32_t g_hist_37; // word name
		struct {
			uint32_t g_hist_hist_37 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_38 12'h5D4 */
	union {
		uint32_t g_hist_38; // word name
		struct {
			uint32_t g_hist_hist_38 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_39 12'h5D8 */
	union {
		uint32_t g_hist_39; // word name
		struct {
			uint32_t g_hist_hist_39 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_40 12'h5DC */
	union {
		uint32_t g_hist_40; // word name
		struct {
			uint32_t g_hist_hist_40 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_41 12'h5E0 */
	union {
		uint32_t g_hist_41; // word name
		struct {
			uint32_t g_hist_hist_41 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_42 12'h5E4 */
	union {
		uint32_t g_hist_42; // word name
		struct {
			uint32_t g_hist_hist_42 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_43 12'h5E8 */
	union {
		uint32_t g_hist_43; // word name
		struct {
			uint32_t g_hist_hist_43 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_44 12'h5EC */
	union {
		uint32_t g_hist_44; // word name
		struct {
			uint32_t g_hist_hist_44 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_45 12'h5F0 */
	union {
		uint32_t g_hist_45; // word name
		struct {
			uint32_t g_hist_hist_45 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_46 12'h5F4 */
	union {
		uint32_t g_hist_46; // word name
		struct {
			uint32_t g_hist_hist_46 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_47 12'h5F8 */
	union {
		uint32_t g_hist_47; // word name
		struct {
			uint32_t g_hist_hist_47 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_48 12'h5FC */
	union {
		uint32_t g_hist_48; // word name
		struct {
			uint32_t g_hist_hist_48 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_49 12'h600 */
	union {
		uint32_t g_hist_49; // word name
		struct {
			uint32_t g_hist_hist_49 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_50 12'h604 */
	union {
		uint32_t g_hist_50; // word name
		struct {
			uint32_t g_hist_hist_50 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_51 12'h608 */
	union {
		uint32_t g_hist_51; // word name
		struct {
			uint32_t g_hist_hist_51 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_52 12'h60C */
	union {
		uint32_t g_hist_52; // word name
		struct {
			uint32_t g_hist_hist_52 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_53 12'h610 */
	union {
		uint32_t g_hist_53; // word name
		struct {
			uint32_t g_hist_hist_53 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_54 12'h614 */
	union {
		uint32_t g_hist_54; // word name
		struct {
			uint32_t g_hist_hist_54 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_55 12'h618 */
	union {
		uint32_t g_hist_55; // word name
		struct {
			uint32_t g_hist_hist_55 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_56 12'h61C */
	union {
		uint32_t g_hist_56; // word name
		struct {
			uint32_t g_hist_hist_56 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_57 12'h620 */
	union {
		uint32_t g_hist_57; // word name
		struct {
			uint32_t g_hist_hist_57 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_58 12'h624 */
	union {
		uint32_t g_hist_58; // word name
		struct {
			uint32_t g_hist_hist_58 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_HIST_59 12'h628 */
	union {
		uint32_t g_hist_59; // word name
		struct {
			uint32_t g_hist_hist_59 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_0 12'h62C */
	union {
		uint32_t b_hist_0; // word name
		struct {
			uint32_t b_hist_hist_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_1 12'h630 */
	union {
		uint32_t b_hist_1; // word name
		struct {
			uint32_t b_hist_hist_1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_2 12'h634 */
	union {
		uint32_t b_hist_2; // word name
		struct {
			uint32_t b_hist_hist_2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_3 12'h638 */
	union {
		uint32_t b_hist_3; // word name
		struct {
			uint32_t b_hist_hist_3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_4 12'h63C */
	union {
		uint32_t b_hist_4; // word name
		struct {
			uint32_t b_hist_hist_4 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_5 12'h640 */
	union {
		uint32_t b_hist_5; // word name
		struct {
			uint32_t b_hist_hist_5 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_6 12'h644 */
	union {
		uint32_t b_hist_6; // word name
		struct {
			uint32_t b_hist_hist_6 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_7 12'h648 */
	union {
		uint32_t b_hist_7; // word name
		struct {
			uint32_t b_hist_hist_7 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_8 12'h64C */
	union {
		uint32_t b_hist_8; // word name
		struct {
			uint32_t b_hist_hist_8 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_9 12'h650 */
	union {
		uint32_t b_hist_9; // word name
		struct {
			uint32_t b_hist_hist_9 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_10 12'h654 */
	union {
		uint32_t b_hist_10; // word name
		struct {
			uint32_t b_hist_hist_10 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_11 12'h658 */
	union {
		uint32_t b_hist_11; // word name
		struct {
			uint32_t b_hist_hist_11 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_12 12'h65C */
	union {
		uint32_t b_hist_12; // word name
		struct {
			uint32_t b_hist_hist_12 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_13 12'h660 */
	union {
		uint32_t b_hist_13; // word name
		struct {
			uint32_t b_hist_hist_13 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_14 12'h664 */
	union {
		uint32_t b_hist_14; // word name
		struct {
			uint32_t b_hist_hist_14 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_15 12'h668 */
	union {
		uint32_t b_hist_15; // word name
		struct {
			uint32_t b_hist_hist_15 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_16 12'h66C */
	union {
		uint32_t b_hist_16; // word name
		struct {
			uint32_t b_hist_hist_16 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_17 12'h670 */
	union {
		uint32_t b_hist_17; // word name
		struct {
			uint32_t b_hist_hist_17 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_18 12'h674 */
	union {
		uint32_t b_hist_18; // word name
		struct {
			uint32_t b_hist_hist_18 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_19 12'h678 */
	union {
		uint32_t b_hist_19; // word name
		struct {
			uint32_t b_hist_hist_19 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_20 12'h67C */
	union {
		uint32_t b_hist_20; // word name
		struct {
			uint32_t b_hist_hist_20 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_21 12'h680 */
	union {
		uint32_t b_hist_21; // word name
		struct {
			uint32_t b_hist_hist_21 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_22 12'h684 */
	union {
		uint32_t b_hist_22; // word name
		struct {
			uint32_t b_hist_hist_22 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_23 12'h688 */
	union {
		uint32_t b_hist_23; // word name
		struct {
			uint32_t b_hist_hist_23 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_24 12'h68C */
	union {
		uint32_t b_hist_24; // word name
		struct {
			uint32_t b_hist_hist_24 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_25 12'h690 */
	union {
		uint32_t b_hist_25; // word name
		struct {
			uint32_t b_hist_hist_25 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_26 12'h694 */
	union {
		uint32_t b_hist_26; // word name
		struct {
			uint32_t b_hist_hist_26 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_27 12'h698 */
	union {
		uint32_t b_hist_27; // word name
		struct {
			uint32_t b_hist_hist_27 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_28 12'h69C */
	union {
		uint32_t b_hist_28; // word name
		struct {
			uint32_t b_hist_hist_28 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_29 12'h6A0 */
	union {
		uint32_t b_hist_29; // word name
		struct {
			uint32_t b_hist_hist_29 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_30 12'h6A4 */
	union {
		uint32_t b_hist_30; // word name
		struct {
			uint32_t b_hist_hist_30 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_31 12'h6A8 */
	union {
		uint32_t b_hist_31; // word name
		struct {
			uint32_t b_hist_hist_31 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_32 12'h6AC */
	union {
		uint32_t b_hist_32; // word name
		struct {
			uint32_t b_hist_hist_32 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_33 12'h6B0 */
	union {
		uint32_t b_hist_33; // word name
		struct {
			uint32_t b_hist_hist_33 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_34 12'h6B4 */
	union {
		uint32_t b_hist_34; // word name
		struct {
			uint32_t b_hist_hist_34 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_35 12'h6B8 */
	union {
		uint32_t b_hist_35; // word name
		struct {
			uint32_t b_hist_hist_35 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_36 12'h6BC */
	union {
		uint32_t b_hist_36; // word name
		struct {
			uint32_t b_hist_hist_36 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_37 12'h6C0 */
	union {
		uint32_t b_hist_37; // word name
		struct {
			uint32_t b_hist_hist_37 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_38 12'h6C4 */
	union {
		uint32_t b_hist_38; // word name
		struct {
			uint32_t b_hist_hist_38 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_39 12'h6C8 */
	union {
		uint32_t b_hist_39; // word name
		struct {
			uint32_t b_hist_hist_39 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_40 12'h6CC */
	union {
		uint32_t b_hist_40; // word name
		struct {
			uint32_t b_hist_hist_40 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_41 12'h6D0 */
	union {
		uint32_t b_hist_41; // word name
		struct {
			uint32_t b_hist_hist_41 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_42 12'h6D4 */
	union {
		uint32_t b_hist_42; // word name
		struct {
			uint32_t b_hist_hist_42 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_43 12'h6D8 */
	union {
		uint32_t b_hist_43; // word name
		struct {
			uint32_t b_hist_hist_43 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_44 12'h6DC */
	union {
		uint32_t b_hist_44; // word name
		struct {
			uint32_t b_hist_hist_44 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_45 12'h6E0 */
	union {
		uint32_t b_hist_45; // word name
		struct {
			uint32_t b_hist_hist_45 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_46 12'h6E4 */
	union {
		uint32_t b_hist_46; // word name
		struct {
			uint32_t b_hist_hist_46 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_47 12'h6E8 */
	union {
		uint32_t b_hist_47; // word name
		struct {
			uint32_t b_hist_hist_47 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_48 12'h6EC */
	union {
		uint32_t b_hist_48; // word name
		struct {
			uint32_t b_hist_hist_48 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_49 12'h6F0 */
	union {
		uint32_t b_hist_49; // word name
		struct {
			uint32_t b_hist_hist_49 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_50 12'h6F4 */
	union {
		uint32_t b_hist_50; // word name
		struct {
			uint32_t b_hist_hist_50 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_51 12'h6F8 */
	union {
		uint32_t b_hist_51; // word name
		struct {
			uint32_t b_hist_hist_51 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_52 12'h6FC */
	union {
		uint32_t b_hist_52; // word name
		struct {
			uint32_t b_hist_hist_52 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_53 12'h700 */
	union {
		uint32_t b_hist_53; // word name
		struct {
			uint32_t b_hist_hist_53 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_54 12'h704 */
	union {
		uint32_t b_hist_54; // word name
		struct {
			uint32_t b_hist_hist_54 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_55 12'h708 */
	union {
		uint32_t b_hist_55; // word name
		struct {
			uint32_t b_hist_hist_55 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_56 12'h70C */
	union {
		uint32_t b_hist_56; // word name
		struct {
			uint32_t b_hist_hist_56 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_57 12'h710 */
	union {
		uint32_t b_hist_57; // word name
		struct {
			uint32_t b_hist_hist_57 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_58 12'h714 */
	union {
		uint32_t b_hist_58; // word name
		struct {
			uint32_t b_hist_hist_58 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_HIST_59 12'h718 */
	union {
		uint32_t b_hist_59; // word name
		struct {
			uint32_t b_hist_hist_59 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_SEL 12'h71C */
	union {
		uint32_t dbg_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ATPG_CTRL 12'h720 */
	union {
		uint32_t word_atpg_ctrl; // word name
		struct {
			uint32_t atpg_ctrl : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EFUSE_STATUS 12'h724 */
	union {
		uint32_t efuse_status; // word name
		struct {
			uint32_t efuse_sensor_cfa_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_0 12'h728 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_0; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_0 : 8;
			uint32_t ae_rgl_y_avg_r_data_1 : 8;
			uint32_t ae_rgl_y_avg_r_data_2 : 8;
			uint32_t ae_rgl_y_avg_r_data_3 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_1 12'h72C */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_1; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_4 : 8;
			uint32_t ae_rgl_y_avg_r_data_5 : 8;
			uint32_t ae_rgl_y_avg_r_data_6 : 8;
			uint32_t ae_rgl_y_avg_r_data_7 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_2 12'h730 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_2; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_8 : 8;
			uint32_t ae_rgl_y_avg_r_data_9 : 8;
			uint32_t ae_rgl_y_avg_r_data_10 : 8;
			uint32_t ae_rgl_y_avg_r_data_11 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_3 12'h734 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_3; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_12 : 8;
			uint32_t ae_rgl_y_avg_r_data_13 : 8;
			uint32_t ae_rgl_y_avg_r_data_14 : 8;
			uint32_t ae_rgl_y_avg_r_data_15 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_4 12'h738 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_4; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_16 : 8;
			uint32_t ae_rgl_y_avg_r_data_17 : 8;
			uint32_t ae_rgl_y_avg_r_data_18 : 8;
			uint32_t ae_rgl_y_avg_r_data_19 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_5 12'h73C */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_5; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_20 : 8;
			uint32_t ae_rgl_y_avg_r_data_21 : 8;
			uint32_t ae_rgl_y_avg_r_data_22 : 8;
			uint32_t ae_rgl_y_avg_r_data_23 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_6 12'h740 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_6; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_24 : 8;
			uint32_t ae_rgl_y_avg_r_data_25 : 8;
			uint32_t ae_rgl_y_avg_r_data_26 : 8;
			uint32_t ae_rgl_y_avg_r_data_27 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_7 12'h744 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_7; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_28 : 8;
			uint32_t ae_rgl_y_avg_r_data_29 : 8;
			uint32_t ae_rgl_y_avg_r_data_30 : 8;
			uint32_t ae_rgl_y_avg_r_data_31 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_8 12'h748 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_8; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_32 : 8;
			uint32_t ae_rgl_y_avg_r_data_33 : 8;
			uint32_t ae_rgl_y_avg_r_data_34 : 8;
			uint32_t ae_rgl_y_avg_r_data_35 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_9 12'h74C */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_9; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_36 : 8;
			uint32_t ae_rgl_y_avg_r_data_37 : 8;
			uint32_t ae_rgl_y_avg_r_data_38 : 8;
			uint32_t ae_rgl_y_avg_r_data_39 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_10 12'h750 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_10; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_40 : 8;
			uint32_t ae_rgl_y_avg_r_data_41 : 8;
			uint32_t ae_rgl_y_avg_r_data_42 : 8;
			uint32_t ae_rgl_y_avg_r_data_43 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_11 12'h754 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_11; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_44 : 8;
			uint32_t ae_rgl_y_avg_r_data_45 : 8;
			uint32_t ae_rgl_y_avg_r_data_46 : 8;
			uint32_t ae_rgl_y_avg_r_data_47 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_12 12'h758 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_12; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_48 : 8;
			uint32_t ae_rgl_y_avg_r_data_49 : 8;
			uint32_t ae_rgl_y_avg_r_data_50 : 8;
			uint32_t ae_rgl_y_avg_r_data_51 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_13 12'h75C */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_13; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_52 : 8;
			uint32_t ae_rgl_y_avg_r_data_53 : 8;
			uint32_t ae_rgl_y_avg_r_data_54 : 8;
			uint32_t ae_rgl_y_avg_r_data_55 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_14 12'h760 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_14; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_56 : 8;
			uint32_t ae_rgl_y_avg_r_data_57 : 8;
			uint32_t ae_rgl_y_avg_r_data_58 : 8;
			uint32_t ae_rgl_y_avg_r_data_59 : 8;
		};
	};
	/* FPGA_AE_RGL_Y_AVG_R_DATA_15 12'h764 */
	union {
		uint32_t fpga_ae_rgl_y_avg_r_data_15; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data_60 : 8;
			uint32_t ae_rgl_y_avg_r_data_61 : 8;
			uint32_t ae_rgl_y_avg_r_data_62 : 8;
			uint32_t ae_rgl_y_avg_r_data_63 : 8;
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_0 12'h768 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_0; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_0 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_1 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_1 12'h76C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_1; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_2 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_3 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_2 12'h770 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_2; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_4 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_5 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_3 12'h774 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_3; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_6 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_7 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_4 12'h778 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_4; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_8 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_9 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_5 12'h77C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_5; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_10 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_11 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_6 12'h780 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_6; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_12 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_13 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_7 12'h784 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_7; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_14 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_15 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_8 12'h788 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_8; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_16 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_17 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_9 12'h78C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_9; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_18 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_19 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_10 12'h790 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_10; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_20 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_21 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_11 12'h794 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_11; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_22 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_23 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_12 12'h798 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_12; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_24 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_25 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_13 12'h79C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_13; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_26 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_27 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_14 12'h7A0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_14; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_28 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_29 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_15 12'h7A4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_15; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_30 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_31 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_16 12'h7A8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_16; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_32 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_33 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_17 12'h7AC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_17; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_34 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_35 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_18 12'h7B0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_18; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_36 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_37 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_19 12'h7B4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_19; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_38 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_39 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_20 12'h7B8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_20; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_40 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_41 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_21 12'h7BC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_21; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_42 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_43 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_22 12'h7C0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_22; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_44 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_45 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_23 12'h7C4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_23; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_46 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_47 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_24 12'h7C8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_24; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_48 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_49 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_25 12'h7CC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_25; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_50 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_51 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_26 12'h7D0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_26; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_52 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_53 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_27 12'h7D4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_27; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_54 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_55 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_28 12'h7D8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_28; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_56 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_57 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_29 12'h7DC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_29; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_58 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_59 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_30 12'h7E0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_30; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_60 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_61 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_31 12'h7E4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_31; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_62 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_63 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_32 12'h7E8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_32; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_64 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_65 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_33 12'h7EC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_33; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_66 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_67 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_34 12'h7F0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_34; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_68 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_69 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_35 12'h7F4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_35; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_70 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_71 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_36 12'h7F8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_36; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_72 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_73 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_37 12'h7FC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_37; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_74 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_75 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_38 12'h800 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_38; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_76 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_77 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_39 12'h804 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_39; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_78 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_79 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_40 12'h808 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_40; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_80 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_81 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_41 12'h80C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_41; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_82 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_83 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_42 12'h810 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_42; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_84 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_85 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_43 12'h814 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_43; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_86 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_87 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_44 12'h818 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_44; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_88 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_89 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_45 12'h81C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_45; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_90 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_91 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_46 12'h820 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_46; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_92 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_93 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_47 12'h824 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_47; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_94 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_95 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_48 12'h828 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_48; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_96 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_97 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_49 12'h82C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_49; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_98 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_99 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_50 12'h830 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_50; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_100 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_101 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_51 12'h834 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_51; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_102 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_103 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_52 12'h838 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_52; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_104 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_105 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_53 12'h83C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_53; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_106 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_107 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_54 12'h840 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_54; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_108 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_109 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_55 12'h844 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_55; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_110 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_111 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_56 12'h848 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_56; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_112 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_113 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_57 12'h84C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_57; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_114 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_115 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_58 12'h850 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_58; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_116 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_117 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_59 12'h854 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_59; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_118 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_119 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_60 12'h858 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_60; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_120 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_121 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_61 12'h85C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_61; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_122 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_123 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_62 12'h860 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_62; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_124 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_125 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_63 12'h864 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_63; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_126 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_127 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_64 12'h868 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_64; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_128 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_129 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_65 12'h86C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_65; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_130 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_131 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_66 12'h870 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_66; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_132 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_133 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_67 12'h874 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_67; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_134 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_135 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_68 12'h878 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_68; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_136 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_137 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_69 12'h87C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_69; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_138 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_139 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_70 12'h880 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_70; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_140 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_141 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_71 12'h884 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_71; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_142 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_143 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_72 12'h888 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_72; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_144 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_145 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_73 12'h88C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_73; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_146 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_147 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_74 12'h890 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_74; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_148 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_149 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_75 12'h894 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_75; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_150 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_151 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_76 12'h898 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_76; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_152 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_153 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_77 12'h89C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_77; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_154 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_155 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_78 12'h8A0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_78; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_156 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_157 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_79 12'h8A4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_79; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_158 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_159 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_80 12'h8A8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_80; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_160 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_161 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_81 12'h8AC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_81; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_162 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_163 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_82 12'h8B0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_82; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_164 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_165 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_83 12'h8B4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_83; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_166 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_167 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_84 12'h8B8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_84; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_168 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_169 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_85 12'h8BC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_85; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_170 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_171 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_86 12'h8C0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_86; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_172 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_173 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_87 12'h8C4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_87; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_174 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_175 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_88 12'h8C8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_88; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_176 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_177 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_89 12'h8CC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_89; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_178 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_179 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_90 12'h8D0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_90; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_180 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_181 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_91 12'h8D4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_91; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_182 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_183 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_92 12'h8D8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_92; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_184 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_185 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_93 12'h8DC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_93; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_186 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_187 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_94 12'h8E0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_94; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_188 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_189 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_95 12'h8E4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_95; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_190 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_191 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_96 12'h8E8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_96; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_192 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_193 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_97 12'h8EC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_97; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_194 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_195 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_98 12'h8F0 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_98; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_196 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_197 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_99 12'h8F4 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_99; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_198 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_199 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_100 12'h8F8 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_100; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_200 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_201 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_101 12'h8FC */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_101; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_202 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_203 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_102 12'h900 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_102; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_204 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_205 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_103 12'h904 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_103; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_206 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_207 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_104 12'h908 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_104; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_208 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_209 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_105 12'h90C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_105; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_210 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_211 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_106 12'h910 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_106; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_212 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_213 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_107 12'h914 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_107; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_214 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_215 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_108 12'h918 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_108; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_216 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_217 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_109 12'h91C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_109; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_218 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_219 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_110 12'h920 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_110; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_220 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_221 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_111 12'h924 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_111; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_222 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_223 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_112 12'h928 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_112; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_224 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_225 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_113 12'h92C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_113; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_226 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_227 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_114 12'h930 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_114; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_228 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_229 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_115 12'h934 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_115; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_230 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_231 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_116 12'h938 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_116; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_232 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_233 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_117 12'h93C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_117; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_234 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_235 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_118 12'h940 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_118; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_236 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_237 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_119 12'h944 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_119; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_238 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_239 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_120 12'h948 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_120; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_240 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_241 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_121 12'h94C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_121; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_242 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_243 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_122 12'h950 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_122; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_244 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_245 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_123 12'h954 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_123; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_246 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_247 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_124 12'h958 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_124; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_248 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_249 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_125 12'h95C */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_125; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_250 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_251 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_126 12'h960 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_126; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_252 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_253 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AF_RGL_H1H2V1V2_AVG_R_DATA_127 12'h964 */
	union {
		uint32_t fpga_af_rgl_h1h2v1v2_avg_r_data_127; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data_254 : 14;
			uint32_t : 2; // padding bits
			uint32_t af_rgl_h1h2v1v2_avg_r_data_255 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_0 12'h968 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_0; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_0 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_1 12'h96C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_1; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_1 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_2 12'h970 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_2; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_2 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_3 12'h974 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_3; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_3 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_4 12'h978 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_4; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_4 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_5 12'h97C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_5; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_5 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_6 12'h980 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_6; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_6 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_7 12'h984 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_7; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_7 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_8 12'h988 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_8; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_8 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_9 12'h98C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_9; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_9 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_10 12'h990 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_10; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_10 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_11 12'h994 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_11; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_11 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_12 12'h998 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_12; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_12 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_13 12'h99C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_13; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_13 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_14 12'h9A0 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_14; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_14 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_15 12'h9A4 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_15; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_15 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_16 12'h9A8 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_16; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_16 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_17 12'h9AC */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_17; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_17 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_18 12'h9B0 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_18; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_18 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_19 12'h9B4 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_19; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_19 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_20 12'h9B8 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_20; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_20 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_21 12'h9BC */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_21; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_21 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_22 12'h9C0 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_22; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_22 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_23 12'h9C4 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_23; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_23 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_24 12'h9C8 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_24; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_24 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_25 12'h9CC */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_25; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_25 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_26 12'h9D0 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_26; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_26 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_27 12'h9D4 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_27; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_27 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_28 12'h9D8 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_28; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_28 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_29 12'h9DC */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_29; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_29 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_30 12'h9E0 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_30; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_30 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_31 12'h9E4 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_31; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_31 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_32 12'h9E8 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_32; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_32 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_33 12'h9EC */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_33; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_33 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_34 12'h9F0 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_34; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_34 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_35 12'h9F4 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_35; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_35 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_36 12'h9F8 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_36; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_36 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_37 12'h9FC */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_37; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_37 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_38 12'hA00 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_38; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_38 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_39 12'hA04 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_39; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_39 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_40 12'hA08 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_40; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_40 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_41 12'hA0C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_41; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_41 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_42 12'hA10 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_42; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_42 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_43 12'hA14 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_43; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_43 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_44 12'hA18 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_44; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_44 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_45 12'hA1C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_45; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_45 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_46 12'hA20 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_46; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_46 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_47 12'hA24 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_47; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_47 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_48 12'hA28 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_48; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_48 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_49 12'hA2C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_49; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_49 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_50 12'hA30 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_50; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_50 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_51 12'hA34 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_51; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_51 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_52 12'hA38 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_52; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_52 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_53 12'hA3C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_53; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_53 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_54 12'hA40 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_54; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_54 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_55 12'hA44 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_55; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_55 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_56 12'hA48 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_56; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_56 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_57 12'hA4C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_57; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_57 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_58 12'hA50 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_58; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_58 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_59 12'hA54 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_59; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_59 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_60 12'hA58 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_60; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_60 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_61 12'hA5C */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_61; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_61 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_62 12'hA60 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_62; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_62 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_AWB_RTX_AVG_R_DATA_63 12'hA64 */
	union {
		uint32_t fpga_awb_rtx_avg_r_data_63; // word name
		struct {
			uint32_t awb_rtx_avg_r_data_63 : 30;
			uint32_t : 2; // padding bits
		};
	};
} CsrBankBsp;

#endif