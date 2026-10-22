#ifndef CSR_BANK_BSP_H_
#define CSR_BANK_BSP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from bsp  ***/
typedef struct csr_bank_bsp {
	/* WORD_FRAME_START 11'h000 */
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
	/* IRQ_CLEAR 11'h004 */
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
	/* STATUS 11'h008 */
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
	/* IRQ_MASK 11'h00C */
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
	/* IO_FORMAT 11'h010 */
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
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_CFA_PHASE_0 11'h014 */
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
	/* WORD_CFA_PHASE_1 11'h018 */
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
	/* WORD_CFA_PHASE_2 11'h01C */
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
	/* WORD_CFA_PHASE_3 11'h020 */
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
	/* RESOLUTION 11'h024 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* SDPD_EN 11'h028 */
	union {
		uint32_t sdpd_en; // word name
		struct {
			uint32_t sdpd_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SDPD_OFFSET 11'h02C */
	union {
		uint32_t sdpd_offset; // word name
		struct {
			uint32_t sdpd_offset_x : 16;
			uint32_t sdpd_offset_y : 16;
		};
	};
	/* DDPD_MODE 11'h030 */
	union {
		uint32_t ddpd_mode; // word name
		struct {
			uint32_t ddpd_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ddpd_g_pattern_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t ddpd_pix_num_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDPD_RATIO 11'h034 */
	union {
		uint32_t ddpd_ratio; // word name
		struct {
			uint32_t ddpd_diff_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t ddpd_avg_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t ddpd_edge_diff_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t ddpd_edge_avg_ratio : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* DDPD_EDGE 11'h038 */
	union {
		uint32_t ddpd_edge; // word name
		struct {
			uint32_t ddpd_edge_m : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DDPD_DP_NUM 11'h03C */
	union {
		uint32_t word_ddpd_dp_num; // word name
		struct {
			uint32_t ddpd_dp_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* DPC_MODE 11'h040 */
	union {
		uint32_t dpc_mode; // word name
		struct {
			uint32_t dpc_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t dpc_dir_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC_DIR 11'h044 */
	union {
		uint32_t dpc_dir; // word name
		struct {
			uint32_t dpc_dir_th_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t dpc_dir_str_m : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CT_ENABLE 11'h048 */
	union {
		uint32_t word_ct_enable; // word name
		struct {
			uint32_t ct_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CT_AVG 11'h04C */
	union {
		uint32_t ct_avg; // word name
		struct {
			uint32_t ct_avg_lb : 16;
			uint32_t ct_avg_ratio : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* CT_STR 11'h050 */
	union {
		uint32_t ct_str; // word name
		struct {
			uint32_t ct_str_lb : 16;
			uint32_t ct_str_ratio : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_CT_STR_M 11'h054 */
	union {
		uint32_t word_ct_str_m; // word name
		struct {
			uint32_t ct_str_m : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CH_WEIGHT_0 11'h058 */
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
	/* CH_WEIGHT_1 11'h05C */
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
	/* WORD_REMOS_ENABLE 11'h060 */
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
	/* REMOS_COEFF_R_0 11'h064 */
	union {
		uint32_t remos_coeff_r_0; // word name
		struct {
			uint32_t remos_r_r_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_r_g_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_R_1 11'h068 */
	union {
		uint32_t remos_coeff_r_1; // word name
		struct {
			uint32_t remos_r_b_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_r_s_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_G_0 11'h06C */
	union {
		uint32_t remos_coeff_g_0; // word name
		struct {
			uint32_t remos_g_r_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_g_g_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_G_1 11'h070 */
	union {
		uint32_t remos_coeff_g_1; // word name
		struct {
			uint32_t remos_g_b_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_g_s_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_B_0 11'h074 */
	union {
		uint32_t remos_coeff_b_0; // word name
		struct {
			uint32_t remos_b_r_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_b_g_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* REMOS_COEFF_B_1 11'h078 */
	union {
		uint32_t remos_coeff_b_1; // word name
		struct {
			uint32_t remos_b_b_coeff_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t remos_b_s_coeff_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_Y_EST_MODE 11'h07C */
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
	/* Y_EST_WEIGHT 11'h080 */
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
	/* WORD_CONTRAST_Y_MODE 11'h084 */
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
	/* CONTRAST_Y_GAIN_0 11'h088 */
	union {
		uint32_t contrast_y_gain_0; // word name
		struct {
			uint32_t contrast_y_gain_th_max : 8;
			uint32_t : 8; // padding bits
			uint32_t contrast_y_gain_th_min : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_Y_GAIN_1 11'h08C */
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
	/* CONTRAST_CFA_ENABLE_0 11'h090 */
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
	/* CONTRAST_CFA_ENABLE_1 11'h094 */
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
	/* WORD_CONTRAST_H1_WEIGHT_0 11'h098 */
	union {
		uint32_t word_contrast_h1_weight_0; // word name
		struct {
			uint32_t contrast_h1_weight_0 : 8;
			uint32_t contrast_h1_weight_1 : 8;
			uint32_t contrast_h1_weight_2 : 8;
			uint32_t contrast_h1_weight_3 : 8;
		};
	};
	/* WORD_CONTRAST_H1_WEIGHT_1 11'h09C */
	union {
		uint32_t word_contrast_h1_weight_1; // word name
		struct {
			uint32_t contrast_h1_weight_4 : 8;
			uint32_t contrast_h1_weight_5 : 8;
			uint32_t contrast_h1_weight_6 : 8;
			uint32_t contrast_h1_weight_7 : 8;
		};
	};
	/* WORD_CONTRAST_H1_WEIGHT_2 11'h0A0 */
	union {
		uint32_t word_contrast_h1_weight_2; // word name
		struct {
			uint32_t contrast_h1_weight_8 : 8;
			uint32_t contrast_h1_weight_9 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_H2_WEIGHT_0 11'h0A4 */
	union {
		uint32_t word_contrast_h2_weight_0; // word name
		struct {
			uint32_t contrast_h2_weight_0 : 8;
			uint32_t contrast_h2_weight_1 : 8;
			uint32_t contrast_h2_weight_2 : 8;
			uint32_t contrast_h2_weight_3 : 8;
		};
	};
	/* WORD_CONTRAST_H2_WEIGHT_1 11'h0A8 */
	union {
		uint32_t word_contrast_h2_weight_1; // word name
		struct {
			uint32_t contrast_h2_weight_4 : 8;
			uint32_t contrast_h2_weight_5 : 8;
			uint32_t contrast_h2_weight_6 : 8;
			uint32_t contrast_h2_weight_7 : 8;
		};
	};
	/* WORD_CONTRAST_H2_WEIGHT_2 11'h0AC */
	union {
		uint32_t word_contrast_h2_weight_2; // word name
		struct {
			uint32_t contrast_h2_weight_8 : 8;
			uint32_t contrast_h2_weight_9 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_V1_WEIGHT_0 11'h0B0 */
	union {
		uint32_t word_contrast_v1_weight_0; // word name
		struct {
			uint32_t contrast_v1_weight_0 : 9;
			uint32_t : 7; // padding bits
			uint32_t contrast_v1_weight_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_CONTRAST_V1_WEIGHT_1 11'h0B4 */
	union {
		uint32_t word_contrast_v1_weight_1; // word name
		struct {
			uint32_t contrast_v1_weight_2 : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_V2_WEIGHT_0 11'h0B8 */
	union {
		uint32_t word_contrast_v2_weight_0; // word name
		struct {
			uint32_t contrast_v2_weight_0 : 9;
			uint32_t : 7; // padding bits
			uint32_t contrast_v2_weight_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_CONTRAST_V2_WEIGHT_1 11'h0BC */
	union {
		uint32_t word_contrast_v2_weight_1; // word name
		struct {
			uint32_t contrast_v2_weight_2 : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CONTRAST_CORING_TH 11'h0C0 */
	union {
		uint32_t word_contrast_coring_th; // word name
		struct {
			uint32_t contrast_coring_th : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AWB_GWD_Y_MODE 11'h0C4 */
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
	/* AWB_GWD_Y_GAIN_0 11'h0C8 */
	union {
		uint32_t awb_gwd_y_gain_0; // word name
		struct {
			uint32_t awb_gwd_y_th_max : 8;
			uint32_t : 8; // padding bits
			uint32_t awb_gwd_y_th_min : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_Y_GAIN_1 11'h0CC */
	union {
		uint32_t awb_gwd_y_gain_1; // word name
		struct {
			uint32_t awb_gwd_y_m : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_RTO_RG_0 11'h0D0 */
	union {
		uint32_t awb_gwd_rto_rg_0; // word name
		struct {
			uint32_t awb_gwd_rg_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t awb_gwd_rg_1 : 6;
			uint32_t : 2; // padding bits
			uint32_t awb_gwd_rg_2 : 6;
			uint32_t : 2; // padding bits
			uint32_t awb_gwd_rg_3 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* AWB_GWD_RTO_RG_1 11'h0D4 */
	union {
		uint32_t awb_gwd_rto_rg_1; // word name
		struct {
			uint32_t awb_gwd_rg_4 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_RTO_BG_0 11'h0D8 */
	union {
		uint32_t awb_gwd_rto_bg_0; // word name
		struct {
			uint32_t awb_gwd_bg_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t awb_gwd_bg_1 : 6;
			uint32_t : 2; // padding bits
			uint32_t awb_gwd_bg_2 : 6;
			uint32_t : 2; // padding bits
			uint32_t awb_gwd_bg_3 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* AWB_GWD_RTO_BG_1 11'h0DC */
	union {
		uint32_t awb_gwd_rto_bg_1; // word name
		struct {
			uint32_t awb_gwd_bg_4 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_GWD_RTO_A_0 11'h0E0 */
	union {
		uint32_t awb_gwd_rto_a_0; // word name
		struct {
			uint32_t awb_gwd_a_2s_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t awb_gwd_a_2s_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* AWB_GWD_RTO_A_1 11'h0E4 */
	union {
		uint32_t awb_gwd_rto_a_1; // word name
		struct {
			uint32_t awb_gwd_a_2s_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t awb_gwd_a_2s_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* AWB_GWD_RTO_B_0 11'h0E8 */
	union {
		uint32_t awb_gwd_rto_b_0; // word name
		struct {
			uint32_t awb_gwd_b_2s_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t awb_gwd_b_2s_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* AWB_GWD_RTO_B_1 11'h0EC */
	union {
		uint32_t awb_gwd_rto_b_1; // word name
		struct {
			uint32_t awb_gwd_b_2s_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t awb_gwd_b_2s_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* AWB_GWD_RTO_C_0 11'h0F0 */
	union {
		uint32_t awb_gwd_rto_c_0; // word name
		struct {
			uint32_t awb_gwd_c_2s_0 : 16;
			uint32_t awb_gwd_c_2s_1 : 16;
		};
	};
	/* AWB_GWD_RTO_C_1 11'h0F4 */
	union {
		uint32_t awb_gwd_rto_c_1; // word name
		struct {
			uint32_t awb_gwd_c_2s_2 : 16;
			uint32_t awb_gwd_c_2s_3 : 16;
		};
	};
	/* AWB_GWD_RTO_TH 11'h0F8 */
	union {
		uint32_t awb_gwd_rto_th; // word name
		struct {
			uint32_t awb_gwd_rto_bg_th_0 : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_gwd_rto_bg_th_1 : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_gwd_rto_bg_th_2 : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_gwd_rto_bg_th_3 : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* AWB_GWD_RTO_TH_M 11'h0FC */
	union {
		uint32_t awb_gwd_rto_th_m; // word name
		struct {
			uint32_t awb_gwd_rto_bg_m_0 : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_gwd_rto_bg_m_1 : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_gwd_rto_bg_m_2 : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_gwd_rto_bg_m_3 : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* WORD_AWB_RTX_Y_MODE 11'h100 */
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
	/* AWB_RTX_Y_GAIN_0 11'h104 */
	union {
		uint32_t awb_rtx_y_gain_0; // word name
		struct {
			uint32_t awb_rtx_y_th_min : 8;
			uint32_t : 8; // padding bits
			uint32_t awb_rtx_y_th_max : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_Y_GAIN_1 11'h108 */
	union {
		uint32_t awb_rtx_y_gain_1; // word name
		struct {
			uint32_t awb_rtx_y_m : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AWB_RTX_REGION_MODE 11'h10C */
	union {
		uint32_t word_awb_rtx_region_mode; // word name
		struct {
			uint32_t awb_rtx_region_mode : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_TM_ENABLE 11'h110 */
	union {
		uint32_t word_tm_enable; // word name
		struct {
			uint32_t tm_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TM_STRL_0 11'h114 */
	union {
		uint32_t tm_strl_0; // word name
		struct {
			uint32_t tone_curve_1 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_2 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_1 11'h118 */
	union {
		uint32_t tm_strl_1; // word name
		struct {
			uint32_t tone_curve_3 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_4 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_2 11'h11C */
	union {
		uint32_t tm_strl_2; // word name
		struct {
			uint32_t tone_curve_5 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_6 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_3 11'h120 */
	union {
		uint32_t tm_strl_3; // word name
		struct {
			uint32_t tone_curve_7 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_8 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_4 11'h124 */
	union {
		uint32_t tm_strl_4; // word name
		struct {
			uint32_t tone_curve_9 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_10 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_5 11'h128 */
	union {
		uint32_t tm_strl_5; // word name
		struct {
			uint32_t tone_curve_11 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_12 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_6 11'h12C */
	union {
		uint32_t tm_strl_6; // word name
		struct {
			uint32_t tone_curve_13 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_14 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_7 11'h130 */
	union {
		uint32_t tm_strl_7; // word name
		struct {
			uint32_t tone_curve_15 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_16 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_8 11'h134 */
	union {
		uint32_t tm_strl_8; // word name
		struct {
			uint32_t tone_curve_17 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_18 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_9 11'h138 */
	union {
		uint32_t tm_strl_9; // word name
		struct {
			uint32_t tone_curve_19 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_20 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_10 11'h13C */
	union {
		uint32_t tm_strl_10; // word name
		struct {
			uint32_t tone_curve_21 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_22 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_11 11'h140 */
	union {
		uint32_t tm_strl_11; // word name
		struct {
			uint32_t tone_curve_23 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_24 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_12 11'h144 */
	union {
		uint32_t tm_strl_12; // word name
		struct {
			uint32_t tone_curve_25 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_26 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_13 11'h148 */
	union {
		uint32_t tm_strl_13; // word name
		struct {
			uint32_t tone_curve_27 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_28 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_14 11'h14C */
	union {
		uint32_t tm_strl_14; // word name
		struct {
			uint32_t tone_curve_29 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_30 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_15 11'h150 */
	union {
		uint32_t tm_strl_15; // word name
		struct {
			uint32_t tone_curve_31 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_32 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_16 11'h154 */
	union {
		uint32_t tm_strl_16; // word name
		struct {
			uint32_t tone_curve_33 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_34 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_17 11'h158 */
	union {
		uint32_t tm_strl_17; // word name
		struct {
			uint32_t tone_curve_35 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_36 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_18 11'h15C */
	union {
		uint32_t tm_strl_18; // word name
		struct {
			uint32_t tone_curve_37 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_38 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_19 11'h160 */
	union {
		uint32_t tm_strl_19; // word name
		struct {
			uint32_t tone_curve_39 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_40 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_20 11'h164 */
	union {
		uint32_t tm_strl_20; // word name
		struct {
			uint32_t tone_curve_41 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_42 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_21 11'h168 */
	union {
		uint32_t tm_strl_21; // word name
		struct {
			uint32_t tone_curve_43 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_44 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_22 11'h16C */
	union {
		uint32_t tm_strl_22; // word name
		struct {
			uint32_t tone_curve_45 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_46 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_23 11'h170 */
	union {
		uint32_t tm_strl_23; // word name
		struct {
			uint32_t tone_curve_47 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_48 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_24 11'h174 */
	union {
		uint32_t tm_strl_24; // word name
		struct {
			uint32_t tone_curve_49 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_50 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_25 11'h178 */
	union {
		uint32_t tm_strl_25; // word name
		struct {
			uint32_t tone_curve_51 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_52 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_26 11'h17C */
	union {
		uint32_t tm_strl_26; // word name
		struct {
			uint32_t tone_curve_53 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_54 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_27 11'h180 */
	union {
		uint32_t tm_strl_27; // word name
		struct {
			uint32_t tone_curve_55 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_56 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* TM_STRL_28 11'h184 */
	union {
		uint32_t tm_strl_28; // word name
		struct {
			uint32_t tone_curve_57 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_58 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_WB_ENABLE 11'h188 */
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
	/* WB_GAIN_0 11'h18C */
	union {
		uint32_t wb_gain_0; // word name
		struct {
			uint32_t wb_gain_g0 : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_r : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* WB_GAIN_1 11'h190 */
	union {
		uint32_t wb_gain_1; // word name
		struct {
			uint32_t wb_gain_b : 12;
			uint32_t : 4; // padding bits
			uint32_t wb_gain_g1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* Y_HIST_MODE 11'h194 */
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
	/* WORD_Y_HIST_OVERFLOW 11'h198 */
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
	/* Y_HIST_ROI_X 11'h19C */
	union {
		uint32_t y_hist_roi_x; // word name
		struct {
			uint32_t y_hist_roi_sx : 16;
			uint32_t y_hist_roi_ex : 16;
		};
	};
	/* Y_HIST_ROI_Y 11'h1A0 */
	union {
		uint32_t y_hist_roi_y; // word name
		struct {
			uint32_t y_hist_roi_sy : 16;
			uint32_t y_hist_roi_ey : 16;
		};
	};
	/* WORD_Y_HIST_OFFSET 11'h1A4 */
	union {
		uint32_t word_y_hist_offset; // word name
		struct {
			uint32_t y_hist_offset : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_0 11'h1A8 */
	union {
		uint32_t y_hist_0; // word name
		struct {
			uint32_t y_hist_hist_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_1 11'h1AC */
	union {
		uint32_t y_hist_1; // word name
		struct {
			uint32_t y_hist_hist_1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_2 11'h1B0 */
	union {
		uint32_t y_hist_2; // word name
		struct {
			uint32_t y_hist_hist_2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_3 11'h1B4 */
	union {
		uint32_t y_hist_3; // word name
		struct {
			uint32_t y_hist_hist_3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_4 11'h1B8 */
	union {
		uint32_t y_hist_4; // word name
		struct {
			uint32_t y_hist_hist_4 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_5 11'h1BC */
	union {
		uint32_t y_hist_5; // word name
		struct {
			uint32_t y_hist_hist_5 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_6 11'h1C0 */
	union {
		uint32_t y_hist_6; // word name
		struct {
			uint32_t y_hist_hist_6 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_7 11'h1C4 */
	union {
		uint32_t y_hist_7; // word name
		struct {
			uint32_t y_hist_hist_7 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_8 11'h1C8 */
	union {
		uint32_t y_hist_8; // word name
		struct {
			uint32_t y_hist_hist_8 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_9 11'h1CC */
	union {
		uint32_t y_hist_9; // word name
		struct {
			uint32_t y_hist_hist_9 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_10 11'h1D0 */
	union {
		uint32_t y_hist_10; // word name
		struct {
			uint32_t y_hist_hist_10 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_11 11'h1D4 */
	union {
		uint32_t y_hist_11; // word name
		struct {
			uint32_t y_hist_hist_11 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_12 11'h1D8 */
	union {
		uint32_t y_hist_12; // word name
		struct {
			uint32_t y_hist_hist_12 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_13 11'h1DC */
	union {
		uint32_t y_hist_13; // word name
		struct {
			uint32_t y_hist_hist_13 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_14 11'h1E0 */
	union {
		uint32_t y_hist_14; // word name
		struct {
			uint32_t y_hist_hist_14 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_15 11'h1E4 */
	union {
		uint32_t y_hist_15; // word name
		struct {
			uint32_t y_hist_hist_15 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_16 11'h1E8 */
	union {
		uint32_t y_hist_16; // word name
		struct {
			uint32_t y_hist_hist_16 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_17 11'h1EC */
	union {
		uint32_t y_hist_17; // word name
		struct {
			uint32_t y_hist_hist_17 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_18 11'h1F0 */
	union {
		uint32_t y_hist_18; // word name
		struct {
			uint32_t y_hist_hist_18 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_19 11'h1F4 */
	union {
		uint32_t y_hist_19; // word name
		struct {
			uint32_t y_hist_hist_19 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_20 11'h1F8 */
	union {
		uint32_t y_hist_20; // word name
		struct {
			uint32_t y_hist_hist_20 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_21 11'h1FC */
	union {
		uint32_t y_hist_21; // word name
		struct {
			uint32_t y_hist_hist_21 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_22 11'h200 */
	union {
		uint32_t y_hist_22; // word name
		struct {
			uint32_t y_hist_hist_22 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_23 11'h204 */
	union {
		uint32_t y_hist_23; // word name
		struct {
			uint32_t y_hist_hist_23 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_24 11'h208 */
	union {
		uint32_t y_hist_24; // word name
		struct {
			uint32_t y_hist_hist_24 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_25 11'h20C */
	union {
		uint32_t y_hist_25; // word name
		struct {
			uint32_t y_hist_hist_25 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_26 11'h210 */
	union {
		uint32_t y_hist_26; // word name
		struct {
			uint32_t y_hist_hist_26 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_27 11'h214 */
	union {
		uint32_t y_hist_27; // word name
		struct {
			uint32_t y_hist_hist_27 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_28 11'h218 */
	union {
		uint32_t y_hist_28; // word name
		struct {
			uint32_t y_hist_hist_28 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_29 11'h21C */
	union {
		uint32_t y_hist_29; // word name
		struct {
			uint32_t y_hist_hist_29 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_30 11'h220 */
	union {
		uint32_t y_hist_30; // word name
		struct {
			uint32_t y_hist_hist_30 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_31 11'h224 */
	union {
		uint32_t y_hist_31; // word name
		struct {
			uint32_t y_hist_hist_31 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_32 11'h228 */
	union {
		uint32_t y_hist_32; // word name
		struct {
			uint32_t y_hist_hist_32 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_33 11'h22C */
	union {
		uint32_t y_hist_33; // word name
		struct {
			uint32_t y_hist_hist_33 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_34 11'h230 */
	union {
		uint32_t y_hist_34; // word name
		struct {
			uint32_t y_hist_hist_34 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_35 11'h234 */
	union {
		uint32_t y_hist_35; // word name
		struct {
			uint32_t y_hist_hist_35 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_36 11'h238 */
	union {
		uint32_t y_hist_36; // word name
		struct {
			uint32_t y_hist_hist_36 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_37 11'h23C */
	union {
		uint32_t y_hist_37; // word name
		struct {
			uint32_t y_hist_hist_37 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_38 11'h240 */
	union {
		uint32_t y_hist_38; // word name
		struct {
			uint32_t y_hist_hist_38 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_39 11'h244 */
	union {
		uint32_t y_hist_39; // word name
		struct {
			uint32_t y_hist_hist_39 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_40 11'h248 */
	union {
		uint32_t y_hist_40; // word name
		struct {
			uint32_t y_hist_hist_40 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_41 11'h24C */
	union {
		uint32_t y_hist_41; // word name
		struct {
			uint32_t y_hist_hist_41 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_42 11'h250 */
	union {
		uint32_t y_hist_42; // word name
		struct {
			uint32_t y_hist_hist_42 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_43 11'h254 */
	union {
		uint32_t y_hist_43; // word name
		struct {
			uint32_t y_hist_hist_43 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_44 11'h258 */
	union {
		uint32_t y_hist_44; // word name
		struct {
			uint32_t y_hist_hist_44 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_45 11'h25C */
	union {
		uint32_t y_hist_45; // word name
		struct {
			uint32_t y_hist_hist_45 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_46 11'h260 */
	union {
		uint32_t y_hist_46; // word name
		struct {
			uint32_t y_hist_hist_46 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_47 11'h264 */
	union {
		uint32_t y_hist_47; // word name
		struct {
			uint32_t y_hist_hist_47 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_48 11'h268 */
	union {
		uint32_t y_hist_48; // word name
		struct {
			uint32_t y_hist_hist_48 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_49 11'h26C */
	union {
		uint32_t y_hist_49; // word name
		struct {
			uint32_t y_hist_hist_49 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_50 11'h270 */
	union {
		uint32_t y_hist_50; // word name
		struct {
			uint32_t y_hist_hist_50 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_51 11'h274 */
	union {
		uint32_t y_hist_51; // word name
		struct {
			uint32_t y_hist_hist_51 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_52 11'h278 */
	union {
		uint32_t y_hist_52; // word name
		struct {
			uint32_t y_hist_hist_52 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_53 11'h27C */
	union {
		uint32_t y_hist_53; // word name
		struct {
			uint32_t y_hist_hist_53 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_54 11'h280 */
	union {
		uint32_t y_hist_54; // word name
		struct {
			uint32_t y_hist_hist_54 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_55 11'h284 */
	union {
		uint32_t y_hist_55; // word name
		struct {
			uint32_t y_hist_hist_55 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_56 11'h288 */
	union {
		uint32_t y_hist_56; // word name
		struct {
			uint32_t y_hist_hist_56 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_57 11'h28C */
	union {
		uint32_t y_hist_57; // word name
		struct {
			uint32_t y_hist_hist_57 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_58 11'h290 */
	union {
		uint32_t y_hist_58; // word name
		struct {
			uint32_t y_hist_hist_58 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_59 11'h294 */
	union {
		uint32_t y_hist_59; // word name
		struct {
			uint32_t y_hist_hist_59 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_MODE 11'h298 */
	union {
		uint32_t awb_rtx_mode; // word name
		struct {
			uint32_t awb_rtx_roi_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_ROI_X 11'h29C */
	union {
		uint32_t awb_rtx_roi_x; // word name
		struct {
			uint32_t awb_rtx_roi_sx : 16;
			uint32_t awb_rtx_roi_ex : 16;
		};
	};
	/* AWB_RTX_ROI_Y 11'h2A0 */
	union {
		uint32_t awb_rtx_roi_y; // word name
		struct {
			uint32_t awb_rtx_roi_sy : 16;
			uint32_t awb_rtx_roi_ey : 16;
		};
	};
	/* WORD_AWB_RTX_SUM_G0 11'h2A4 */
	union {
		uint32_t word_awb_rtx_sum_g0; // word name
		struct {
			uint32_t awb_rtx_sum_g0 : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AWB_RTX_SUM_R 11'h2A8 */
	union {
		uint32_t word_awb_rtx_sum_r; // word name
		struct {
			uint32_t awb_rtx_sum_r : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AWB_RTX_SUM_B 11'h2AC */
	union {
		uint32_t word_awb_rtx_sum_b; // word name
		struct {
			uint32_t awb_rtx_sum_b : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AWB_RTX_SUM_G1 11'h2B0 */
	union {
		uint32_t word_awb_rtx_sum_g1; // word name
		struct {
			uint32_t awb_rtx_sum_g1 : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_WEIGHT_SUM 11'h2B4 */
	union {
		uint32_t awb_rtx_weight_sum; // word name
		struct {
			uint32_t awb_rtx_norm_g0 : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_rtx_norm_r : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_rtx_norm_b : 7;
			uint32_t : 1; // padding bits
			uint32_t awb_rtx_norm_g1 : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* ROI_Y_AVG_MODE 11'h2B8 */
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
	/* ROI_Y_AVG_ENABLE 11'h2BC */
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
	/* Y_AVG_ROI_0_X 11'h2C0 */
	union {
		uint32_t y_avg_roi_0_x; // word name
		struct {
			uint32_t roi_0_y_avg_sx : 16;
			uint32_t roi_0_y_avg_ex : 16;
		};
	};
	/* Y_AVG_ROI_0_Y 11'h2C4 */
	union {
		uint32_t y_avg_roi_0_y; // word name
		struct {
			uint32_t roi_0_y_avg_sy : 16;
			uint32_t roi_0_y_avg_ey : 16;
		};
	};
	/* Y_AVG_ROI_1_X 11'h2C8 */
	union {
		uint32_t y_avg_roi_1_x; // word name
		struct {
			uint32_t roi_1_y_avg_sx : 16;
			uint32_t roi_1_y_avg_ex : 16;
		};
	};
	/* Y_AVG_ROI_1_Y 11'h2CC */
	union {
		uint32_t y_avg_roi_1_y; // word name
		struct {
			uint32_t roi_1_y_avg_sy : 16;
			uint32_t roi_1_y_avg_ey : 16;
		};
	};
	/* Y_AVG_ROI_2_X 11'h2D0 */
	union {
		uint32_t y_avg_roi_2_x; // word name
		struct {
			uint32_t roi_2_y_avg_sx : 16;
			uint32_t roi_2_y_avg_ex : 16;
		};
	};
	/* Y_AVG_ROI_2_Y 11'h2D4 */
	union {
		uint32_t y_avg_roi_2_y; // word name
		struct {
			uint32_t roi_2_y_avg_sy : 16;
			uint32_t roi_2_y_avg_ey : 16;
		};
	};
	/* Y_AVG_ROI_3_X 11'h2D8 */
	union {
		uint32_t y_avg_roi_3_x; // word name
		struct {
			uint32_t roi_3_y_avg_sx : 16;
			uint32_t roi_3_y_avg_ex : 16;
		};
	};
	/* Y_AVG_ROI_3_Y 11'h2DC */
	union {
		uint32_t y_avg_roi_3_y; // word name
		struct {
			uint32_t roi_3_y_avg_sy : 16;
			uint32_t roi_3_y_avg_ey : 16;
		};
	};
	/* Y_AVG_ROI_PIX_NUM_0 11'h2E0 */
	union {
		uint32_t y_avg_roi_pix_num_0; // word name
		struct {
			uint32_t roi_0_y_avg_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_NUM_1 11'h2E4 */
	union {
		uint32_t y_avg_roi_pix_num_1; // word name
		struct {
			uint32_t roi_1_y_avg_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_NUM_2 11'h2E8 */
	union {
		uint32_t y_avg_roi_pix_num_2; // word name
		struct {
			uint32_t roi_2_y_avg_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_NUM_3 11'h2EC */
	union {
		uint32_t y_avg_roi_pix_num_3; // word name
		struct {
			uint32_t roi_3_y_avg_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_REMAINDER_0 11'h2F0 */
	union {
		uint32_t y_avg_roi_remainder_0; // word name
		struct {
			uint32_t roi_0_y_avg_remainder : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_REMAINDER_1 11'h2F4 */
	union {
		uint32_t y_avg_roi_remainder_1; // word name
		struct {
			uint32_t roi_1_y_avg_remainder : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_REMAINDER_2 11'h2F8 */
	union {
		uint32_t y_avg_roi_remainder_2; // word name
		struct {
			uint32_t roi_2_y_avg_remainder : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_REMAINDER_3 11'h2FC */
	union {
		uint32_t y_avg_roi_remainder_3; // word name
		struct {
			uint32_t roi_3_y_avg_remainder : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_AVG_0 11'h300 */
	union {
		uint32_t y_avg_roi_pix_avg_0; // word name
		struct {
			uint32_t roi_0_y_avg_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_y_avg_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* Y_AVG_ROI_PIX_AVG_1 11'h304 */
	union {
		uint32_t y_avg_roi_pix_avg_1; // word name
		struct {
			uint32_t roi_2_y_avg_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_y_avg_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* ROI_CONTRAST_ENABLE 11'h308 */
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
	/* CONTRAST_ROI_0_X 11'h30C */
	union {
		uint32_t contrast_roi_0_x; // word name
		struct {
			uint32_t roi_0_contrast_sx : 16;
			uint32_t roi_0_contrast_ex : 16;
		};
	};
	/* CONTRAST_ROI_0_Y 11'h310 */
	union {
		uint32_t contrast_roi_0_y; // word name
		struct {
			uint32_t roi_0_contrast_sy : 16;
			uint32_t roi_0_contrast_ey : 16;
		};
	};
	/* CONTRAST_ROI_1_X 11'h314 */
	union {
		uint32_t contrast_roi_1_x; // word name
		struct {
			uint32_t roi_1_contrast_sx : 16;
			uint32_t roi_1_contrast_ex : 16;
		};
	};
	/* CONTRAST_ROI_1_Y 11'h318 */
	union {
		uint32_t contrast_roi_1_y; // word name
		struct {
			uint32_t roi_1_contrast_sy : 16;
			uint32_t roi_1_contrast_ey : 16;
		};
	};
	/* CONTRAST_ROI_2_X 11'h31C */
	union {
		uint32_t contrast_roi_2_x; // word name
		struct {
			uint32_t roi_2_contrast_sx : 16;
			uint32_t roi_2_contrast_ex : 16;
		};
	};
	/* CONTRAST_ROI_2_Y 11'h320 */
	union {
		uint32_t contrast_roi_2_y; // word name
		struct {
			uint32_t roi_2_contrast_sy : 16;
			uint32_t roi_2_contrast_ey : 16;
		};
	};
	/* CONTRAST_ROI_3_X 11'h324 */
	union {
		uint32_t contrast_roi_3_x; // word name
		struct {
			uint32_t roi_3_contrast_sx : 16;
			uint32_t roi_3_contrast_ex : 16;
		};
	};
	/* CONTRAST_ROI_3_Y 11'h328 */
	union {
		uint32_t contrast_roi_3_y; // word name
		struct {
			uint32_t roi_3_contrast_sy : 16;
			uint32_t roi_3_contrast_ey : 16;
		};
	};
	/* CONTRAST_PIX_NUM_0 11'h32C */
	union {
		uint32_t contrast_pix_num_0; // word name
		struct {
			uint32_t roi_0_contrast_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_PIX_NUM_1 11'h330 */
	union {
		uint32_t contrast_pix_num_1; // word name
		struct {
			uint32_t roi_1_contrast_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_PIX_NUM_2 11'h334 */
	union {
		uint32_t contrast_pix_num_2; // word name
		struct {
			uint32_t roi_2_contrast_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_PIX_NUM_3 11'h338 */
	union {
		uint32_t contrast_pix_num_3; // word name
		struct {
			uint32_t roi_3_contrast_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* CONTRAST_H1_AVG_0 11'h33C */
	union {
		uint32_t contrast_h1_avg_0; // word name
		struct {
			uint32_t roi_0_contrast_h1_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_contrast_h1_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_H1_AVG_1 11'h340 */
	union {
		uint32_t contrast_h1_avg_1; // word name
		struct {
			uint32_t roi_2_contrast_h1_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_contrast_h1_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_H2_AVG_0 11'h344 */
	union {
		uint32_t contrast_h2_avg_0; // word name
		struct {
			uint32_t roi_0_contrast_h2_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_contrast_h2_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_H2_AVG_1 11'h348 */
	union {
		uint32_t contrast_h2_avg_1; // word name
		struct {
			uint32_t roi_2_contrast_h2_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_contrast_h2_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_V1_AVG_0 11'h34C */
	union {
		uint32_t contrast_v1_avg_0; // word name
		struct {
			uint32_t roi_0_contrast_v1_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_contrast_v1_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_V1_AVG_1 11'h350 */
	union {
		uint32_t contrast_v1_avg_1; // word name
		struct {
			uint32_t roi_2_contrast_v1_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_contrast_v1_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_V2_AVG_0 11'h354 */
	union {
		uint32_t contrast_v2_avg_0; // word name
		struct {
			uint32_t roi_0_contrast_v2_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_1_contrast_v2_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CONTRAST_V2_AVG_1 11'h358 */
	union {
		uint32_t contrast_v2_avg_1; // word name
		struct {
			uint32_t roi_2_contrast_v2_avg : 14;
			uint32_t : 2; // padding bits
			uint32_t roi_3_contrast_v2_avg : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* ROI_AWB_GWD_ENABLE 11'h35C */
	union {
		uint32_t roi_awb_gwd_enable; // word name
		struct {
			uint32_t roi_0_awb_gwd_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_1_awb_gwd_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_2_awb_gwd_en : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_3_awb_gwd_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* AWB_GWD_ROI_0_X 11'h360 */
	union {
		uint32_t awb_gwd_roi_0_x; // word name
		struct {
			uint32_t roi_0_awb_gwd_sx : 16;
			uint32_t roi_0_awb_gwd_ex : 16;
		};
	};
	/* AWB_GWD_ROI_0_Y 11'h364 */
	union {
		uint32_t awb_gwd_roi_0_y; // word name
		struct {
			uint32_t roi_0_awb_gwd_sy : 16;
			uint32_t roi_0_awb_gwd_ey : 16;
		};
	};
	/* AWB_GWD_ROI_1_X 11'h368 */
	union {
		uint32_t awb_gwd_roi_1_x; // word name
		struct {
			uint32_t roi_1_awb_gwd_sx : 16;
			uint32_t roi_1_awb_gwd_ex : 16;
		};
	};
	/* AWB_GWD_ROI_1_Y 11'h36C */
	union {
		uint32_t awb_gwd_roi_1_y; // word name
		struct {
			uint32_t roi_1_awb_gwd_sy : 16;
			uint32_t roi_1_awb_gwd_ey : 16;
		};
	};
	/* AWB_GWD_ROI_2_X 11'h370 */
	union {
		uint32_t awb_gwd_roi_2_x; // word name
		struct {
			uint32_t roi_2_awb_gwd_sx : 16;
			uint32_t roi_2_awb_gwd_ex : 16;
		};
	};
	/* AWB_GWD_ROI_2_Y 11'h374 */
	union {
		uint32_t awb_gwd_roi_2_y; // word name
		struct {
			uint32_t roi_2_awb_gwd_sy : 16;
			uint32_t roi_2_awb_gwd_ey : 16;
		};
	};
	/* AWB_GWD_ROI_3_X 11'h378 */
	union {
		uint32_t awb_gwd_roi_3_x; // word name
		struct {
			uint32_t roi_3_awb_gwd_sx : 16;
			uint32_t roi_3_awb_gwd_ex : 16;
		};
	};
	/* AWB_GWD_ROI_3_Y 11'h37C */
	union {
		uint32_t awb_gwd_roi_3_y; // word name
		struct {
			uint32_t roi_3_awb_gwd_sy : 16;
			uint32_t roi_3_awb_gwd_ey : 16;
		};
	};
	/* AWB_GWD_SUM_G0_0 11'h380 */
	union {
		uint32_t awb_gwd_sum_g0_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_sum_g0 : 32;
		};
	};
	/* AWB_GWD_SUM_G0_1 11'h384 */
	union {
		uint32_t awb_gwd_sum_g0_1; // word name
		struct {
			uint32_t roi_1_awb_gwd_sum_g0 : 32;
		};
	};
	/* AWB_GWD_SUM_G0_2 11'h388 */
	union {
		uint32_t awb_gwd_sum_g0_2; // word name
		struct {
			uint32_t roi_2_awb_gwd_sum_g0 : 32;
		};
	};
	/* AWB_GWD_SUM_G0_3 11'h38C */
	union {
		uint32_t awb_gwd_sum_g0_3; // word name
		struct {
			uint32_t roi_3_awb_gwd_sum_g0 : 32;
		};
	};
	/* AWB_GWD_SUM_R_0 11'h390 */
	union {
		uint32_t awb_gwd_sum_r_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_sum_r : 32;
		};
	};
	/* AWB_GWD_SUM_R_1 11'h394 */
	union {
		uint32_t awb_gwd_sum_r_1; // word name
		struct {
			uint32_t roi_1_awb_gwd_sum_r : 32;
		};
	};
	/* AWB_GWD_SUM_R_2 11'h398 */
	union {
		uint32_t awb_gwd_sum_r_2; // word name
		struct {
			uint32_t roi_2_awb_gwd_sum_r : 32;
		};
	};
	/* AWB_GWD_SUM_R_3 11'h39C */
	union {
		uint32_t awb_gwd_sum_r_3; // word name
		struct {
			uint32_t roi_3_awb_gwd_sum_r : 32;
		};
	};
	/* AWB_GWD_SUM_B_0 11'h3A0 */
	union {
		uint32_t awb_gwd_sum_b_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_sum_b : 32;
		};
	};
	/* AWB_GWD_SUM_B_1 11'h3A4 */
	union {
		uint32_t awb_gwd_sum_b_1; // word name
		struct {
			uint32_t roi_1_awb_gwd_sum_b : 32;
		};
	};
	/* AWB_GWD_SUM_B_2 11'h3A8 */
	union {
		uint32_t awb_gwd_sum_b_2; // word name
		struct {
			uint32_t roi_2_awb_gwd_sum_b : 32;
		};
	};
	/* AWB_GWD_SUM_B_3 11'h3AC */
	union {
		uint32_t awb_gwd_sum_b_3; // word name
		struct {
			uint32_t roi_3_awb_gwd_sum_b : 32;
		};
	};
	/* AWB_GWD_SUM_G1_0 11'h3B0 */
	union {
		uint32_t awb_gwd_sum_g1_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_sum_g1 : 32;
		};
	};
	/* AWB_GWD_SUM_G1_1 11'h3B4 */
	union {
		uint32_t awb_gwd_sum_g1_1; // word name
		struct {
			uint32_t roi_1_awb_gwd_sum_g1 : 32;
		};
	};
	/* AWB_GWD_SUM_G1_2 11'h3B8 */
	union {
		uint32_t awb_gwd_sum_g1_2; // word name
		struct {
			uint32_t roi_2_awb_gwd_sum_g1 : 32;
		};
	};
	/* AWB_GWD_SUM_G1_3 11'h3BC */
	union {
		uint32_t awb_gwd_sum_g1_3; // word name
		struct {
			uint32_t roi_3_awb_gwd_sum_g1 : 32;
		};
	};
	/* AWB_GWD_NORM_G0_0 11'h3C0 */
	union {
		uint32_t awb_gwd_norm_g0_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_norm_g0 : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_G0_1 11'h3C4 */
	union {
		uint32_t awb_gwd_norm_g0_1; // word name
		struct {
			uint32_t roi_1_awb_gwd_norm_g0 : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_G0_2 11'h3C8 */
	union {
		uint32_t awb_gwd_norm_g0_2; // word name
		struct {
			uint32_t roi_2_awb_gwd_norm_g0 : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_G0_3 11'h3CC */
	union {
		uint32_t awb_gwd_norm_g0_3; // word name
		struct {
			uint32_t roi_3_awb_gwd_norm_g0 : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_R_0 11'h3D0 */
	union {
		uint32_t awb_gwd_norm_r_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_norm_r : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_R_1 11'h3D4 */
	union {
		uint32_t awb_gwd_norm_r_1; // word name
		struct {
			uint32_t roi_1_awb_gwd_norm_r : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_R_2 11'h3D8 */
	union {
		uint32_t awb_gwd_norm_r_2; // word name
		struct {
			uint32_t roi_2_awb_gwd_norm_r : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_R_3 11'h3DC */
	union {
		uint32_t awb_gwd_norm_r_3; // word name
		struct {
			uint32_t roi_3_awb_gwd_norm_r : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_B_0 11'h3E0 */
	union {
		uint32_t awb_gwd_norm_b_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_norm_b : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_B_1 11'h3E4 */
	union {
		uint32_t awb_gwd_norm_b_1; // word name
		struct {
			uint32_t roi_1_awb_gwd_norm_b : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_B_2 11'h3E8 */
	union {
		uint32_t awb_gwd_norm_b_2; // word name
		struct {
			uint32_t roi_2_awb_gwd_norm_b : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_B_3 11'h3EC */
	union {
		uint32_t awb_gwd_norm_b_3; // word name
		struct {
			uint32_t roi_3_awb_gwd_norm_b : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_G1_0 11'h3F0 */
	union {
		uint32_t awb_gwd_norm_g1_0; // word name
		struct {
			uint32_t roi_0_awb_gwd_norm_g1 : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_G1_1 11'h3F4 */
	union {
		uint32_t awb_gwd_norm_g1_1; // word name
		struct {
			uint32_t roi_1_awb_gwd_norm_g1 : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_G1_2 11'h3F8 */
	union {
		uint32_t awb_gwd_norm_g1_2; // word name
		struct {
			uint32_t roi_2_awb_gwd_norm_g1 : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* AWB_GWD_NORM_G1_3 11'h3FC */
	union {
		uint32_t awb_gwd_norm_g1_3; // word name
		struct {
			uint32_t roi_3_awb_gwd_norm_g1 : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* RGL_Y_AVG_MODE 11'h400 */
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
	/* RGL_Y_AVG_BLK 11'h404 */
	union {
		uint32_t rgl_y_avg_blk; // word name
		struct {
			uint32_t rgl_y_avg_blk_ht : 14;
			uint32_t : 2; // padding bits
			uint32_t rgl_y_avg_blk_wd : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_RGL_Y_AVG_PIX_NUM 11'h408 */
	union {
		uint32_t word_rgl_y_avg_pix_num; // word name
		struct {
			uint32_t rgl_y_avg_pix_num : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_AVG_X 11'h40C */
	union {
		uint32_t rgl_y_avg_x; // word name
		struct {
			uint32_t rgl_y_avg_sx : 16;
			uint32_t rgl_y_avg_ex : 16;
		};
	};
	/* RGL_Y_AVG_Y 11'h410 */
	union {
		uint32_t rgl_y_avg_y; // word name
		struct {
			uint32_t rgl_y_avg_sy : 16;
			uint32_t rgl_y_avg_ey : 16;
		};
	};
	/* RGL_CONTRAST_MODE 11'h414 */
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
	/* RGL_CONTRAST_BLK 11'h418 */
	union {
		uint32_t rgl_contrast_blk; // word name
		struct {
			uint32_t rgl_contrast_blk_ht : 14;
			uint32_t : 2; // padding bits
			uint32_t rgl_contrast_blk_wd : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_RGL_CONTRAST_PIX_NUM 11'h41C */
	union {
		uint32_t word_rgl_contrast_pix_num; // word name
		struct {
			uint32_t rgl_contrast_pix_num : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_CONTRAST_X 11'h420 */
	union {
		uint32_t rgl_contrast_x; // word name
		struct {
			uint32_t rgl_contrast_sx : 16;
			uint32_t rgl_contrast_ex : 16;
		};
	};
	/* RGL_CONTRAST_Y 11'h424 */
	union {
		uint32_t rgl_contrast_y; // word name
		struct {
			uint32_t rgl_contrast_sy : 16;
			uint32_t rgl_contrast_ey : 16;
		};
	};
	/* RGL_AWB_RTX_MODE 11'h428 */
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
	/* RGL_AWB_RTX_BLK 11'h42C */
	union {
		uint32_t rgl_awb_rtx_blk; // word name
		struct {
			uint32_t rgl_awb_rtx_blk_ht : 14;
			uint32_t : 2; // padding bits
			uint32_t rgl_awb_rtx_blk_wd : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* RGL_AWB_RTX_X 11'h430 */
	union {
		uint32_t rgl_awb_rtx_x; // word name
		struct {
			uint32_t rgl_awb_rtx_sx : 16;
			uint32_t rgl_awb_rtx_ex : 16;
		};
	};
	/* RGL_AWB_RTX_Y 11'h434 */
	union {
		uint32_t rgl_awb_rtx_y; // word name
		struct {
			uint32_t rgl_awb_rtx_sy : 16;
			uint32_t rgl_awb_rtx_ey : 16;
		};
	};
	/* RGL_AWB_GWD_MODE 11'h438 */
	union {
		uint32_t rgl_awb_gwd_mode; // word name
		struct {
			uint32_t rgl_awb_gwd_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_AWB_GWD_BLK 11'h43C */
	union {
		uint32_t rgl_awb_gwd_blk; // word name
		struct {
			uint32_t rgl_awb_gwd_blk_ht : 14;
			uint32_t : 2; // padding bits
			uint32_t rgl_awb_gwd_blk_wd : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* RGL_AWB_GWD_X 11'h440 */
	union {
		uint32_t rgl_awb_gwd_x; // word name
		struct {
			uint32_t rgl_awb_gwd_sx : 16;
			uint32_t rgl_awb_gwd_ex : 16;
		};
	};
	/* RGL_AWB_GWD_Y 11'h444 */
	union {
		uint32_t rgl_awb_gwd_y; // word name
		struct {
			uint32_t rgl_awb_gwd_sy : 16;
			uint32_t rgl_awb_gwd_ey : 16;
		};
	};
	/* WORD_CSR2SRAM_SEL 11'h448 */
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
	/* AE_RGL_ADDR 11'h44C */
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
	/* AF_RGL_ADDR 11'h450 */
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
	/* AWB_RGL_GWD_ADDR 11'h454 */
	union {
		uint32_t awb_rgl_gwd_addr; // word name
		struct {
			uint32_t awb_rgl_gwd_pix_avg_r_addr : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RGL_RTX_ADDR 11'h458 */
	union {
		uint32_t awb_rgl_rtx_addr; // word name
		struct {
			uint32_t awb_rgl_rtx_max_weight_r_addr : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_SORTING_ADDR 11'h45C */
	union {
		uint32_t awb_rtx_sorting_addr; // word name
		struct {
			uint32_t awb_rtx_sorting_r_addr : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AE_RGL_R_DATA 11'h460 */
	union {
		uint32_t ae_rgl_r_data; // word name
		struct {
			uint32_t ae_rgl_y_avg_r_data : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AF_RGL_R_DATA 11'h464 */
	union {
		uint32_t af_rgl_r_data; // word name
		struct {
			uint32_t af_rgl_h1h2v1v2_avg_r_data : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RGL_GWD_R_DATA 11'h468 */
	union {
		uint32_t awb_rgl_gwd_r_data; // word name
		struct {
			uint32_t awb_rgl_gwd_pix_avg_r_data : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RGL_RTX_R_DATA 11'h46C */
	union {
		uint32_t awb_rgl_rtx_r_data; // word name
		struct {
			uint32_t awb_rgl_rtx_max_value_weight_r_data : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_RTX_SORTING_DATA 11'h470 */
	union {
		uint32_t awb_rtx_sorting_data; // word name
		struct {
			uint32_t awb_rtx_sorting_r_data : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFA_PHASE_EN_SET_0 11'h474 */
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
	/* CFA_PHASE_EN_SET_1 11'h478 */
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
	/* CFA_PHASE_EN_SET_2 11'h47C */
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
	/* CFA_PHASE_EN_SET_3 11'h480 */
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
	/* DBG_SEL 11'h484 */
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
	/* WORD_ATPG_CTRL 11'h488 */
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
	/* EFUSE_STATUS 11'h48C */
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
} CsrBankBsp;

#endif