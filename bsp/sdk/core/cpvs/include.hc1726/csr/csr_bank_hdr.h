/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_HDR_H_
#define CSR_BANK_HDR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from hdr  ***/
typedef struct csr_bank_hdr {
	/* HDR00 14'h0000 */
	union {
		uint32_t hdr00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR01 14'h0004 */
	union {
		uint32_t hdr01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR02 14'h0008 */
	union {
		uint32_t hdr02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR03 14'h000C */
	union {
		uint32_t hdr03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR04 14'h0010 [Unused] */
	uint32_t empty_word_hdr04;
	/* HDR05 14'h0014 */
	union {
		uint32_t hdr05; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* HDR06 14'h0018 */
	union {
		uint32_t hdr06; // word name
		struct {
			uint32_t mode : 3;
			uint32_t : 5; // padding bits
			uint32_t bayer_ini_phase_i : 2;
			uint32_t : 6; // padding bits
			uint32_t exp_long_early : 1;
			uint32_t : 7; // padding bits
			uint32_t hdr_merge_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR07 14'h001C */
	union {
		uint32_t hdr07; // word name
		struct {
			uint32_t exp_ratio : 9;
			uint32_t : 7; // padding bits
			uint32_t exp_ratio_inv : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR08 14'h0020 */
	union {
		uint32_t hdr08; // word name
		struct {
			uint32_t se_anti_gamma_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t le_anti_gamma_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t ink_num : 4;
			uint32_t : 4; // padding bits
			uint32_t weight_mode : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR09 14'h0024 */
	union {
		uint32_t hdr09; // word name
		struct {
			uint32_t le_weight_th_max : 12;
			uint32_t : 4; // padding bits
			uint32_t le_weight_slope : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* HDR10 14'h0028 */
	union {
		uint32_t hdr10; // word name
		struct {
			uint32_t le_weight_min : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t le_weight_max : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR11 14'h002C */
	union {
		uint32_t hdr11; // word name
		struct {
			uint32_t le_overflow_protect_en : 1;
			uint32_t fallback_mode : 1;
			uint32_t : 1; // padding bits
			uint32_t le_overflow_protect_r_th : 12;
			uint32_t : 1; // padding bits
			uint32_t le_overflow_protect_g_th : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* HDR12 14'h0030 */
	union {
		uint32_t hdr12; // word name
		struct {
			uint32_t le_overflow_protect_b_th : 12;
			uint32_t : 4; // padding bits
			uint32_t le_overflow_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR13 14'h0034 */
	union {
		uint32_t hdr13; // word name
		struct {
			uint32_t mismatch_var_gain_2s : 6;
			uint32_t : 2; // padding bits
			uint32_t hdr_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR14 14'h0038 */
	union {
		uint32_t hdr14; // word name
		struct {
			uint32_t local_fb_th : 12;
			uint32_t : 4; // padding bits
			uint32_t local_fb_slope : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* HDR15 14'h003C */
	union {
		uint32_t hdr15; // word name
		struct {
			uint32_t local_fb_min : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t local_fb_max : 7;
			uint32_t : 1; // padding bits
			uint32_t le_var_weight : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* HDR16 14'h0040 */
	union {
		uint32_t hdr16; // word name
		struct {
			uint32_t frame_fb_strength : 7;
			uint32_t : 1; // padding bits
			uint32_t fb_target : 1;
			uint32_t : 7; // padding bits
			uint32_t fb_alpha : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR17 14'h0044 */
	union {
		uint32_t hdr17; // word name
		struct {
			uint32_t se_exp_ratio_min_int : 5;
			uint32_t : 3; // padding bits
			uint32_t ltm_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ltm_bilinear_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR18 14'h0048 */
	union {
		uint32_t hdr18; // word name
		struct {
			uint32_t rgl_h_num_cuv : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rgl_v_num_cuv : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR19 14'h004C */
	union {
		uint32_t hdr19; // word name
		struct {
			uint32_t rgl_h_num_hist : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rgl_v_num_hist : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR20 14'h0050 */
	union {
		uint32_t hdr20; // word name
		struct {
			uint32_t rgl_x_cnt_ini_cuv : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR21 14'h0054 */
	union {
		uint32_t hdr21; // word name
		struct {
			uint32_t rgl_y_cnt_ini_cuv : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR22 14'h0058 */
	union {
		uint32_t hdr22; // word name
		struct {
			uint32_t rgl_x_cnt_ini_hist : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR23 14'h005C */
	union {
		uint32_t hdr23; // word name
		struct {
			uint32_t rgl_y_cnt_ini_hist : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR24 14'h0060 */
	union {
		uint32_t hdr24; // word name
		struct {
			uint32_t rgl_x_cnt_step_cuv : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR25 14'h0064 */
	union {
		uint32_t hdr25; // word name
		struct {
			uint32_t rgl_y_cnt_step_cuv : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR26 14'h0068 */
	union {
		uint32_t hdr26; // word name
		struct {
			uint32_t rgl_x_cnt_step_hist : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR27 14'h006C */
	union {
		uint32_t hdr27; // word name
		struct {
			uint32_t rgl_y_cnt_step_hist : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR28 14'h0070 */
	union {
		uint32_t hdr28; // word name
		struct {
			uint32_t awb_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR29 14'h0074 */
	union {
		uint32_t hdr29; // word name
		struct {
			uint32_t awb_gain_0 : 12;
			uint32_t : 4; // padding bits
			uint32_t awb_gain_1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* HDR30 14'h0078 */
	union {
		uint32_t hdr30; // word name
		struct {
			uint32_t awb_gain_2 : 12;
			uint32_t : 4; // padding bits
			uint32_t awb_gain_3 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* HDR31 14'h007C */
	union {
		uint32_t hdr31; // word name
		struct {
			uint32_t gamma_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR32 14'h0080 */
	union {
		uint32_t hdr32; // word name
		struct {
			uint32_t efuse_dis_hdr_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR33 14'h0084 */
	union {
		uint32_t hdr33; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* HDR34 14'h0088 */
	union {
		uint32_t hdr34; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* HDR35 14'h008C */
	union {
		uint32_t hdr35; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HISTOGRAM_EN 14'h0090 */
	union {
		uint32_t histogram_en; // word name
		struct {
			uint32_t hist_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HISTOGRAM_CLEAR 14'h0094 */
	union {
		uint32_t histogram_clear; // word name
		struct {
			uint32_t hist_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HISTOGRAM_X 14'h0098 */
	union {
		uint32_t histogram_x; // word name
		struct {
			uint32_t hist_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t hist_ex : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* HISTOGRAM_Y 14'h009C */
	union {
		uint32_t histogram_y; // word name
		struct {
			uint32_t hist_sy : 13;
			uint32_t : 3; // padding bits
			uint32_t hist_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* HISTOGRAM_OFFSET 14'h00A0 */
	union {
		uint32_t histogram_offset; // word name
		struct {
			uint32_t y_hist_offset : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR_CSR2SRAM_SEL 14'h00A4 */
	union {
		uint32_t hdr_csr2sram_sel; // word name
		struct {
			uint32_t csr2sram_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HISTOGRAM_E_R_ADDR 14'h00A8 */
	union {
		uint32_t histogram_e_r_addr; // word name
		struct {
			uint32_t hist_e_r_addr : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HISTOGRAM_E_R_DATA 14'h00AC */
	union {
		uint32_t histogram_e_r_data; // word name
		struct {
			uint32_t hist_e_r_data : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HISTOGRAM_O_R_ADDR 14'h00B0 */
	union {
		uint32_t histogram_o_r_addr; // word name
		struct {
			uint32_t hist_o_r_addr : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HISTOGRAM_O_R_DATA 14'h00B4 */
	union {
		uint32_t histogram_o_r_data; // word name
		struct {
			uint32_t hist_o_r_data : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_OFFSET_0_0 14'h00B8 */
	union {
		uint32_t tone_offset_0_0; // word name
		struct {
			uint32_t y_tone_offset_0_0 : 16;
			uint32_t y_tone_offset_0_1 : 16;
		};
	};
	/* TONE_OFFSET_0_1 14'h00BC */
	union {
		uint32_t tone_offset_0_1; // word name
		struct {
			uint32_t y_tone_offset_0_2 : 16;
			uint32_t y_tone_offset_0_3 : 16;
		};
	};
	/* TONE_OFFSET_0_2 14'h00C0 */
	union {
		uint32_t tone_offset_0_2; // word name
		struct {
			uint32_t y_tone_offset_0_4 : 16;
			uint32_t y_tone_offset_0_5 : 16;
		};
	};
	/* TONE_OFFSET_0_3 14'h00C4 */
	union {
		uint32_t tone_offset_0_3; // word name
		struct {
			uint32_t y_tone_offset_0_6 : 16;
			uint32_t y_tone_offset_0_7 : 16;
		};
	};
	/* TONE_OFFSET_1_0 14'h00C8 */
	union {
		uint32_t tone_offset_1_0; // word name
		struct {
			uint32_t y_tone_offset_1_0 : 16;
			uint32_t y_tone_offset_1_1 : 16;
		};
	};
	/* TONE_OFFSET_1_1 14'h00CC */
	union {
		uint32_t tone_offset_1_1; // word name
		struct {
			uint32_t y_tone_offset_1_2 : 16;
			uint32_t y_tone_offset_1_3 : 16;
		};
	};
	/* TONE_OFFSET_1_2 14'h00D0 */
	union {
		uint32_t tone_offset_1_2; // word name
		struct {
			uint32_t y_tone_offset_1_4 : 16;
			uint32_t y_tone_offset_1_5 : 16;
		};
	};
	/* TONE_OFFSET_1_3 14'h00D4 */
	union {
		uint32_t tone_offset_1_3; // word name
		struct {
			uint32_t y_tone_offset_1_6 : 16;
			uint32_t y_tone_offset_1_7 : 16;
		};
	};
	/* TONE_OFFSET_2_0 14'h00D8 */
	union {
		uint32_t tone_offset_2_0; // word name
		struct {
			uint32_t y_tone_offset_2_0 : 16;
			uint32_t y_tone_offset_2_1 : 16;
		};
	};
	/* TONE_OFFSET_2_1 14'h00DC */
	union {
		uint32_t tone_offset_2_1; // word name
		struct {
			uint32_t y_tone_offset_2_2 : 16;
			uint32_t y_tone_offset_2_3 : 16;
		};
	};
	/* TONE_OFFSET_2_2 14'h00E0 */
	union {
		uint32_t tone_offset_2_2; // word name
		struct {
			uint32_t y_tone_offset_2_4 : 16;
			uint32_t y_tone_offset_2_5 : 16;
		};
	};
	/* TONE_OFFSET_2_3 14'h00E4 */
	union {
		uint32_t tone_offset_2_3; // word name
		struct {
			uint32_t y_tone_offset_2_6 : 16;
			uint32_t y_tone_offset_2_7 : 16;
		};
	};
	/* TONE_OFFSET_3_0 14'h00E8 */
	union {
		uint32_t tone_offset_3_0; // word name
		struct {
			uint32_t y_tone_offset_3_0 : 16;
			uint32_t y_tone_offset_3_1 : 16;
		};
	};
	/* TONE_OFFSET_3_1 14'h00EC */
	union {
		uint32_t tone_offset_3_1; // word name
		struct {
			uint32_t y_tone_offset_3_2 : 16;
			uint32_t y_tone_offset_3_3 : 16;
		};
	};
	/* TONE_OFFSET_3_2 14'h00F0 */
	union {
		uint32_t tone_offset_3_2; // word name
		struct {
			uint32_t y_tone_offset_3_4 : 16;
			uint32_t y_tone_offset_3_5 : 16;
		};
	};
	/* TONE_OFFSET_3_3 14'h00F4 */
	union {
		uint32_t tone_offset_3_3; // word name
		struct {
			uint32_t y_tone_offset_3_6 : 16;
			uint32_t y_tone_offset_3_7 : 16;
		};
	};
	/* TONE_CURVE_EE_E_W_ADDR 14'h00F8 */
	union {
		uint32_t tone_curve_ee_e_w_addr; // word name
		struct {
			uint32_t tcuv_ee_e_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_EE_E_W_DATA 14'h00FC */
	union {
		uint32_t tone_curve_ee_e_w_data; // word name
		struct {
			uint32_t tcuv_ee_e_w_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_EE_E_R_ADDR 14'h0100 */
	union {
		uint32_t tone_curve_ee_e_r_addr; // word name
		struct {
			uint32_t tcuv_ee_e_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_EE_E_R_DATA 14'h0104 */
	union {
		uint32_t tone_curve_ee_e_r_data; // word name
		struct {
			uint32_t tcuv_ee_e_r_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_EE_O_W_ADDR 14'h0108 */
	union {
		uint32_t tone_curve_ee_o_w_addr; // word name
		struct {
			uint32_t tcuv_ee_o_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_EE_O_W_DATA 14'h010C */
	union {
		uint32_t tone_curve_ee_o_w_data; // word name
		struct {
			uint32_t tcuv_ee_o_w_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_EE_O_R_ADDR 14'h0110 */
	union {
		uint32_t tone_curve_ee_o_r_addr; // word name
		struct {
			uint32_t tcuv_ee_o_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_EE_O_R_DATA 14'h0114 */
	union {
		uint32_t tone_curve_ee_o_r_data; // word name
		struct {
			uint32_t tcuv_ee_o_r_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_EO_E_W_ADDR 14'h0118 */
	union {
		uint32_t tone_curve_eo_e_w_addr; // word name
		struct {
			uint32_t tcuv_eo_e_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_EO_E_W_DATA 14'h011C */
	union {
		uint32_t tone_curve_eo_e_w_data; // word name
		struct {
			uint32_t tcuv_eo_e_w_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_EO_E_R_ADDR 14'h0120 */
	union {
		uint32_t tone_curve_eo_e_r_addr; // word name
		struct {
			uint32_t tcuv_eo_e_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_EO_E_R_DATA 14'h0124 */
	union {
		uint32_t tone_curve_eo_e_r_data; // word name
		struct {
			uint32_t tcuv_eo_e_r_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_EO_O_W_ADDR 14'h0128 */
	union {
		uint32_t tone_curve_eo_o_w_addr; // word name
		struct {
			uint32_t tcuv_eo_o_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_EO_O_W_DATA 14'h012C */
	union {
		uint32_t tone_curve_eo_o_w_data; // word name
		struct {
			uint32_t tcuv_eo_o_w_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_EO_O_R_ADDR 14'h0130 */
	union {
		uint32_t tone_curve_eo_o_r_addr; // word name
		struct {
			uint32_t tcuv_eo_o_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_EO_O_R_DATA 14'h0134 */
	union {
		uint32_t tone_curve_eo_o_r_data; // word name
		struct {
			uint32_t tcuv_eo_o_r_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_OE_E_W_ADDR 14'h0138 */
	union {
		uint32_t tone_curve_oe_e_w_addr; // word name
		struct {
			uint32_t tcuv_oe_e_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_OE_E_W_DATA 14'h013C */
	union {
		uint32_t tone_curve_oe_e_w_data; // word name
		struct {
			uint32_t tcuv_oe_e_w_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_OE_E_R_ADDR 14'h0140 */
	union {
		uint32_t tone_curve_oe_e_r_addr; // word name
		struct {
			uint32_t tcuv_oe_e_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_OE_E_R_DATA 14'h0144 */
	union {
		uint32_t tone_curve_oe_e_r_data; // word name
		struct {
			uint32_t tcuv_oe_e_r_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_OE_O_W_ADDR 14'h0148 */
	union {
		uint32_t tone_curve_oe_o_w_addr; // word name
		struct {
			uint32_t tcuv_oe_o_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_OE_O_W_DATA 14'h014C */
	union {
		uint32_t tone_curve_oe_o_w_data; // word name
		struct {
			uint32_t tcuv_oe_o_w_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_OE_O_R_ADDR 14'h0150 */
	union {
		uint32_t tone_curve_oe_o_r_addr; // word name
		struct {
			uint32_t tcuv_oe_o_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_OE_O_R_DATA 14'h0154 */
	union {
		uint32_t tone_curve_oe_o_r_data; // word name
		struct {
			uint32_t tcuv_oe_o_r_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_OO_E_W_ADDR 14'h0158 */
	union {
		uint32_t tone_curve_oo_e_w_addr; // word name
		struct {
			uint32_t tcuv_oo_e_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_OO_E_W_DATA 14'h015C */
	union {
		uint32_t tone_curve_oo_e_w_data; // word name
		struct {
			uint32_t tcuv_oo_e_w_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_OO_E_R_ADDR 14'h0160 */
	union {
		uint32_t tone_curve_oo_e_r_addr; // word name
		struct {
			uint32_t tcuv_oo_e_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_OO_E_R_DATA 14'h0164 */
	union {
		uint32_t tone_curve_oo_e_r_data; // word name
		struct {
			uint32_t tcuv_oo_e_r_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_OO_O_W_ADDR 14'h0168 */
	union {
		uint32_t tone_curve_oo_o_w_addr; // word name
		struct {
			uint32_t tcuv_oo_o_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_OO_O_W_DATA 14'h016C */
	union {
		uint32_t tone_curve_oo_o_w_data; // word name
		struct {
			uint32_t tcuv_oo_o_w_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TONE_CURVE_OO_O_R_ADDR 14'h0170 */
	union {
		uint32_t tone_curve_oo_o_r_addr; // word name
		struct {
			uint32_t tcuv_oo_o_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TONE_CURVE_OO_O_R_DATA 14'h0174 */
	union {
		uint32_t tone_curve_oo_o_r_data; // word name
		struct {
			uint32_t tcuv_oo_o_r_data : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* Y_HIST_0 14'h0178 */
	union {
		uint32_t y_hist_0; // word name
		struct {
			uint32_t y_hist_out_0 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_1 14'h017C */
	union {
		uint32_t y_hist_1; // word name
		struct {
			uint32_t y_hist_out_1 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_2 14'h0180 */
	union {
		uint32_t y_hist_2; // word name
		struct {
			uint32_t y_hist_out_2 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_3 14'h0184 */
	union {
		uint32_t y_hist_3; // word name
		struct {
			uint32_t y_hist_out_3 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_4 14'h0188 */
	union {
		uint32_t y_hist_4; // word name
		struct {
			uint32_t y_hist_out_4 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_5 14'h018C */
	union {
		uint32_t y_hist_5; // word name
		struct {
			uint32_t y_hist_out_5 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_6 14'h0190 */
	union {
		uint32_t y_hist_6; // word name
		struct {
			uint32_t y_hist_out_6 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_7 14'h0194 */
	union {
		uint32_t y_hist_7; // word name
		struct {
			uint32_t y_hist_out_7 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_8 14'h0198 */
	union {
		uint32_t y_hist_8; // word name
		struct {
			uint32_t y_hist_out_8 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_9 14'h019C */
	union {
		uint32_t y_hist_9; // word name
		struct {
			uint32_t y_hist_out_9 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_10 14'h01A0 */
	union {
		uint32_t y_hist_10; // word name
		struct {
			uint32_t y_hist_out_10 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_11 14'h01A4 */
	union {
		uint32_t y_hist_11; // word name
		struct {
			uint32_t y_hist_out_11 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_12 14'h01A8 */
	union {
		uint32_t y_hist_12; // word name
		struct {
			uint32_t y_hist_out_12 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_13 14'h01AC */
	union {
		uint32_t y_hist_13; // word name
		struct {
			uint32_t y_hist_out_13 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_14 14'h01B0 */
	union {
		uint32_t y_hist_14; // word name
		struct {
			uint32_t y_hist_out_14 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_15 14'h01B4 */
	union {
		uint32_t y_hist_15; // word name
		struct {
			uint32_t y_hist_out_15 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_16 14'h01B8 */
	union {
		uint32_t y_hist_16; // word name
		struct {
			uint32_t y_hist_out_16 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_17 14'h01BC */
	union {
		uint32_t y_hist_17; // word name
		struct {
			uint32_t y_hist_out_17 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_18 14'h01C0 */
	union {
		uint32_t y_hist_18; // word name
		struct {
			uint32_t y_hist_out_18 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_19 14'h01C4 */
	union {
		uint32_t y_hist_19; // word name
		struct {
			uint32_t y_hist_out_19 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_20 14'h01C8 */
	union {
		uint32_t y_hist_20; // word name
		struct {
			uint32_t y_hist_out_20 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_21 14'h01CC */
	union {
		uint32_t y_hist_21; // word name
		struct {
			uint32_t y_hist_out_21 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_22 14'h01D0 */
	union {
		uint32_t y_hist_22; // word name
		struct {
			uint32_t y_hist_out_22 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_23 14'h01D4 */
	union {
		uint32_t y_hist_23; // word name
		struct {
			uint32_t y_hist_out_23 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_24 14'h01D8 */
	union {
		uint32_t y_hist_24; // word name
		struct {
			uint32_t y_hist_out_24 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_25 14'h01DC */
	union {
		uint32_t y_hist_25; // word name
		struct {
			uint32_t y_hist_out_25 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_26 14'h01E0 */
	union {
		uint32_t y_hist_26; // word name
		struct {
			uint32_t y_hist_out_26 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_27 14'h01E4 */
	union {
		uint32_t y_hist_27; // word name
		struct {
			uint32_t y_hist_out_27 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_28 14'h01E8 */
	union {
		uint32_t y_hist_28; // word name
		struct {
			uint32_t y_hist_out_28 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_29 14'h01EC */
	union {
		uint32_t y_hist_29; // word name
		struct {
			uint32_t y_hist_out_29 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_30 14'h01F0 */
	union {
		uint32_t y_hist_30; // word name
		struct {
			uint32_t y_hist_out_30 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_31 14'h01F4 */
	union {
		uint32_t y_hist_31; // word name
		struct {
			uint32_t y_hist_out_31 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_32 14'h01F8 */
	union {
		uint32_t y_hist_32; // word name
		struct {
			uint32_t y_hist_out_32 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_33 14'h01FC */
	union {
		uint32_t y_hist_33; // word name
		struct {
			uint32_t y_hist_out_33 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_34 14'h0200 */
	union {
		uint32_t y_hist_34; // word name
		struct {
			uint32_t y_hist_out_34 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_35 14'h0204 */
	union {
		uint32_t y_hist_35; // word name
		struct {
			uint32_t y_hist_out_35 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_36 14'h0208 */
	union {
		uint32_t y_hist_36; // word name
		struct {
			uint32_t y_hist_out_36 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_37 14'h020C */
	union {
		uint32_t y_hist_37; // word name
		struct {
			uint32_t y_hist_out_37 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_38 14'h0210 */
	union {
		uint32_t y_hist_38; // word name
		struct {
			uint32_t y_hist_out_38 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_39 14'h0214 */
	union {
		uint32_t y_hist_39; // word name
		struct {
			uint32_t y_hist_out_39 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_40 14'h0218 */
	union {
		uint32_t y_hist_40; // word name
		struct {
			uint32_t y_hist_out_40 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_41 14'h021C */
	union {
		uint32_t y_hist_41; // word name
		struct {
			uint32_t y_hist_out_41 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_42 14'h0220 */
	union {
		uint32_t y_hist_42; // word name
		struct {
			uint32_t y_hist_out_42 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_43 14'h0224 */
	union {
		uint32_t y_hist_43; // word name
		struct {
			uint32_t y_hist_out_43 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_44 14'h0228 */
	union {
		uint32_t y_hist_44; // word name
		struct {
			uint32_t y_hist_out_44 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_45 14'h022C */
	union {
		uint32_t y_hist_45; // word name
		struct {
			uint32_t y_hist_out_45 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_46 14'h0230 */
	union {
		uint32_t y_hist_46; // word name
		struct {
			uint32_t y_hist_out_46 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_47 14'h0234 */
	union {
		uint32_t y_hist_47; // word name
		struct {
			uint32_t y_hist_out_47 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_48 14'h0238 */
	union {
		uint32_t y_hist_48; // word name
		struct {
			uint32_t y_hist_out_48 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_49 14'h023C */
	union {
		uint32_t y_hist_49; // word name
		struct {
			uint32_t y_hist_out_49 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_50 14'h0240 */
	union {
		uint32_t y_hist_50; // word name
		struct {
			uint32_t y_hist_out_50 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_51 14'h0244 */
	union {
		uint32_t y_hist_51; // word name
		struct {
			uint32_t y_hist_out_51 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_52 14'h0248 */
	union {
		uint32_t y_hist_52; // word name
		struct {
			uint32_t y_hist_out_52 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_53 14'h024C */
	union {
		uint32_t y_hist_53; // word name
		struct {
			uint32_t y_hist_out_53 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_54 14'h0250 */
	union {
		uint32_t y_hist_54; // word name
		struct {
			uint32_t y_hist_out_54 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_55 14'h0254 */
	union {
		uint32_t y_hist_55; // word name
		struct {
			uint32_t y_hist_out_55 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_56 14'h0258 */
	union {
		uint32_t y_hist_56; // word name
		struct {
			uint32_t y_hist_out_56 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_57 14'h025C */
	union {
		uint32_t y_hist_57; // word name
		struct {
			uint32_t y_hist_out_57 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_58 14'h0260 */
	union {
		uint32_t y_hist_58; // word name
		struct {
			uint32_t y_hist_out_58 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_59 14'h0264 */
	union {
		uint32_t y_hist_59; // word name
		struct {
			uint32_t y_hist_out_59 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_CTRL_0 14'h0268 */
	union {
		uint32_t y_hist_ctrl_0; // word name
		struct {
			uint32_t y_hist_out_en : 1;
			uint32_t : 7; // padding bits
			uint32_t y_hist_out_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t y_hist_out_offset : 16;
		};
	};
	/* Y_HIST_CTRL_1 14'h026C */
	union {
		uint32_t y_hist_ctrl_1; // word name
		struct {
			uint32_t y_hist_out_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_HIST_OUT_ROI_X 14'h0270 */
	union {
		uint32_t y_hist_out_roi_x; // word name
		struct {
			uint32_t y_hist_out_roi_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t y_hist_out_roi_ex : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* Y_HIST_OUT_ROI_Y 14'h0274 */
	union {
		uint32_t y_hist_out_roi_y; // word name
		struct {
			uint32_t y_hist_out_roi_sy : 16;
			uint32_t y_hist_out_roi_ey : 16;
		};
	};
#ifdef CONFIG_FPGA
	/* FPGA_HISTOGRAM_R_DATA_0 14'h0278 */
	union {
		uint32_t fpga_histogram_r_data_0; // word name
		struct {
			uint32_t hist_r_data_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1 14'h027C */
	union {
		uint32_t fpga_histogram_r_data_1; // word name
		struct {
			uint32_t hist_r_data_1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_2 14'h0280 */
	union {
		uint32_t fpga_histogram_r_data_2; // word name
		struct {
			uint32_t hist_r_data_2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_3 14'h0284 */
	union {
		uint32_t fpga_histogram_r_data_3; // word name
		struct {
			uint32_t hist_r_data_3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_4 14'h0288 */
	union {
		uint32_t fpga_histogram_r_data_4; // word name
		struct {
			uint32_t hist_r_data_4 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_5 14'h028C */
	union {
		uint32_t fpga_histogram_r_data_5; // word name
		struct {
			uint32_t hist_r_data_5 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_6 14'h0290 */
	union {
		uint32_t fpga_histogram_r_data_6; // word name
		struct {
			uint32_t hist_r_data_6 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_7 14'h0294 */
	union {
		uint32_t fpga_histogram_r_data_7; // word name
		struct {
			uint32_t hist_r_data_7 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_8 14'h0298 */
	union {
		uint32_t fpga_histogram_r_data_8; // word name
		struct {
			uint32_t hist_r_data_8 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_9 14'h029C */
	union {
		uint32_t fpga_histogram_r_data_9; // word name
		struct {
			uint32_t hist_r_data_9 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_10 14'h02A0 */
	union {
		uint32_t fpga_histogram_r_data_10; // word name
		struct {
			uint32_t hist_r_data_10 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_11 14'h02A4 */
	union {
		uint32_t fpga_histogram_r_data_11; // word name
		struct {
			uint32_t hist_r_data_11 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_12 14'h02A8 */
	union {
		uint32_t fpga_histogram_r_data_12; // word name
		struct {
			uint32_t hist_r_data_12 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_13 14'h02AC */
	union {
		uint32_t fpga_histogram_r_data_13; // word name
		struct {
			uint32_t hist_r_data_13 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_14 14'h02B0 */
	union {
		uint32_t fpga_histogram_r_data_14; // word name
		struct {
			uint32_t hist_r_data_14 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_15 14'h02B4 */
	union {
		uint32_t fpga_histogram_r_data_15; // word name
		struct {
			uint32_t hist_r_data_15 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_16 14'h02B8 */
	union {
		uint32_t fpga_histogram_r_data_16; // word name
		struct {
			uint32_t hist_r_data_16 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_17 14'h02BC */
	union {
		uint32_t fpga_histogram_r_data_17; // word name
		struct {
			uint32_t hist_r_data_17 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_18 14'h02C0 */
	union {
		uint32_t fpga_histogram_r_data_18; // word name
		struct {
			uint32_t hist_r_data_18 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_19 14'h02C4 */
	union {
		uint32_t fpga_histogram_r_data_19; // word name
		struct {
			uint32_t hist_r_data_19 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_20 14'h02C8 */
	union {
		uint32_t fpga_histogram_r_data_20; // word name
		struct {
			uint32_t hist_r_data_20 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_21 14'h02CC */
	union {
		uint32_t fpga_histogram_r_data_21; // word name
		struct {
			uint32_t hist_r_data_21 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_22 14'h02D0 */
	union {
		uint32_t fpga_histogram_r_data_22; // word name
		struct {
			uint32_t hist_r_data_22 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_23 14'h02D4 */
	union {
		uint32_t fpga_histogram_r_data_23; // word name
		struct {
			uint32_t hist_r_data_23 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_24 14'h02D8 */
	union {
		uint32_t fpga_histogram_r_data_24; // word name
		struct {
			uint32_t hist_r_data_24 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_25 14'h02DC */
	union {
		uint32_t fpga_histogram_r_data_25; // word name
		struct {
			uint32_t hist_r_data_25 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_26 14'h02E0 */
	union {
		uint32_t fpga_histogram_r_data_26; // word name
		struct {
			uint32_t hist_r_data_26 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_27 14'h02E4 */
	union {
		uint32_t fpga_histogram_r_data_27; // word name
		struct {
			uint32_t hist_r_data_27 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_28 14'h02E8 */
	union {
		uint32_t fpga_histogram_r_data_28; // word name
		struct {
			uint32_t hist_r_data_28 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_29 14'h02EC */
	union {
		uint32_t fpga_histogram_r_data_29; // word name
		struct {
			uint32_t hist_r_data_29 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_30 14'h02F0 */
	union {
		uint32_t fpga_histogram_r_data_30; // word name
		struct {
			uint32_t hist_r_data_30 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_31 14'h02F4 */
	union {
		uint32_t fpga_histogram_r_data_31; // word name
		struct {
			uint32_t hist_r_data_31 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_32 14'h02F8 */
	union {
		uint32_t fpga_histogram_r_data_32; // word name
		struct {
			uint32_t hist_r_data_32 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_33 14'h02FC */
	union {
		uint32_t fpga_histogram_r_data_33; // word name
		struct {
			uint32_t hist_r_data_33 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_34 14'h0300 */
	union {
		uint32_t fpga_histogram_r_data_34; // word name
		struct {
			uint32_t hist_r_data_34 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_35 14'h0304 */
	union {
		uint32_t fpga_histogram_r_data_35; // word name
		struct {
			uint32_t hist_r_data_35 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_36 14'h0308 */
	union {
		uint32_t fpga_histogram_r_data_36; // word name
		struct {
			uint32_t hist_r_data_36 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_37 14'h030C */
	union {
		uint32_t fpga_histogram_r_data_37; // word name
		struct {
			uint32_t hist_r_data_37 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_38 14'h0310 */
	union {
		uint32_t fpga_histogram_r_data_38; // word name
		struct {
			uint32_t hist_r_data_38 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_39 14'h0314 */
	union {
		uint32_t fpga_histogram_r_data_39; // word name
		struct {
			uint32_t hist_r_data_39 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_40 14'h0318 */
	union {
		uint32_t fpga_histogram_r_data_40; // word name
		struct {
			uint32_t hist_r_data_40 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_41 14'h031C */
	union {
		uint32_t fpga_histogram_r_data_41; // word name
		struct {
			uint32_t hist_r_data_41 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_42 14'h0320 */
	union {
		uint32_t fpga_histogram_r_data_42; // word name
		struct {
			uint32_t hist_r_data_42 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_43 14'h0324 */
	union {
		uint32_t fpga_histogram_r_data_43; // word name
		struct {
			uint32_t hist_r_data_43 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_44 14'h0328 */
	union {
		uint32_t fpga_histogram_r_data_44; // word name
		struct {
			uint32_t hist_r_data_44 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_45 14'h032C */
	union {
		uint32_t fpga_histogram_r_data_45; // word name
		struct {
			uint32_t hist_r_data_45 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_46 14'h0330 */
	union {
		uint32_t fpga_histogram_r_data_46; // word name
		struct {
			uint32_t hist_r_data_46 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_47 14'h0334 */
	union {
		uint32_t fpga_histogram_r_data_47; // word name
		struct {
			uint32_t hist_r_data_47 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_48 14'h0338 */
	union {
		uint32_t fpga_histogram_r_data_48; // word name
		struct {
			uint32_t hist_r_data_48 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_49 14'h033C */
	union {
		uint32_t fpga_histogram_r_data_49; // word name
		struct {
			uint32_t hist_r_data_49 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_50 14'h0340 */
	union {
		uint32_t fpga_histogram_r_data_50; // word name
		struct {
			uint32_t hist_r_data_50 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_51 14'h0344 */
	union {
		uint32_t fpga_histogram_r_data_51; // word name
		struct {
			uint32_t hist_r_data_51 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_52 14'h0348 */
	union {
		uint32_t fpga_histogram_r_data_52; // word name
		struct {
			uint32_t hist_r_data_52 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_53 14'h034C */
	union {
		uint32_t fpga_histogram_r_data_53; // word name
		struct {
			uint32_t hist_r_data_53 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_54 14'h0350 */
	union {
		uint32_t fpga_histogram_r_data_54; // word name
		struct {
			uint32_t hist_r_data_54 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_55 14'h0354 */
	union {
		uint32_t fpga_histogram_r_data_55; // word name
		struct {
			uint32_t hist_r_data_55 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_56 14'h0358 */
	union {
		uint32_t fpga_histogram_r_data_56; // word name
		struct {
			uint32_t hist_r_data_56 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_57 14'h035C */
	union {
		uint32_t fpga_histogram_r_data_57; // word name
		struct {
			uint32_t hist_r_data_57 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_58 14'h0360 */
	union {
		uint32_t fpga_histogram_r_data_58; // word name
		struct {
			uint32_t hist_r_data_58 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_59 14'h0364 */
	union {
		uint32_t fpga_histogram_r_data_59; // word name
		struct {
			uint32_t hist_r_data_59 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_60 14'h0368 */
	union {
		uint32_t fpga_histogram_r_data_60; // word name
		struct {
			uint32_t hist_r_data_60 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_61 14'h036C */
	union {
		uint32_t fpga_histogram_r_data_61; // word name
		struct {
			uint32_t hist_r_data_61 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_62 14'h0370 */
	union {
		uint32_t fpga_histogram_r_data_62; // word name
		struct {
			uint32_t hist_r_data_62 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_63 14'h0374 */
	union {
		uint32_t fpga_histogram_r_data_63; // word name
		struct {
			uint32_t hist_r_data_63 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_64 14'h0378 */
	union {
		uint32_t fpga_histogram_r_data_64; // word name
		struct {
			uint32_t hist_r_data_64 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_65 14'h037C */
	union {
		uint32_t fpga_histogram_r_data_65; // word name
		struct {
			uint32_t hist_r_data_65 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_66 14'h0380 */
	union {
		uint32_t fpga_histogram_r_data_66; // word name
		struct {
			uint32_t hist_r_data_66 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_67 14'h0384 */
	union {
		uint32_t fpga_histogram_r_data_67; // word name
		struct {
			uint32_t hist_r_data_67 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_68 14'h0388 */
	union {
		uint32_t fpga_histogram_r_data_68; // word name
		struct {
			uint32_t hist_r_data_68 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_69 14'h038C */
	union {
		uint32_t fpga_histogram_r_data_69; // word name
		struct {
			uint32_t hist_r_data_69 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_70 14'h0390 */
	union {
		uint32_t fpga_histogram_r_data_70; // word name
		struct {
			uint32_t hist_r_data_70 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_71 14'h0394 */
	union {
		uint32_t fpga_histogram_r_data_71; // word name
		struct {
			uint32_t hist_r_data_71 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_72 14'h0398 */
	union {
		uint32_t fpga_histogram_r_data_72; // word name
		struct {
			uint32_t hist_r_data_72 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_73 14'h039C */
	union {
		uint32_t fpga_histogram_r_data_73; // word name
		struct {
			uint32_t hist_r_data_73 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_74 14'h03A0 */
	union {
		uint32_t fpga_histogram_r_data_74; // word name
		struct {
			uint32_t hist_r_data_74 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_75 14'h03A4 */
	union {
		uint32_t fpga_histogram_r_data_75; // word name
		struct {
			uint32_t hist_r_data_75 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_76 14'h03A8 */
	union {
		uint32_t fpga_histogram_r_data_76; // word name
		struct {
			uint32_t hist_r_data_76 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_77 14'h03AC */
	union {
		uint32_t fpga_histogram_r_data_77; // word name
		struct {
			uint32_t hist_r_data_77 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_78 14'h03B0 */
	union {
		uint32_t fpga_histogram_r_data_78; // word name
		struct {
			uint32_t hist_r_data_78 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_79 14'h03B4 */
	union {
		uint32_t fpga_histogram_r_data_79; // word name
		struct {
			uint32_t hist_r_data_79 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_80 14'h03B8 */
	union {
		uint32_t fpga_histogram_r_data_80; // word name
		struct {
			uint32_t hist_r_data_80 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_81 14'h03BC */
	union {
		uint32_t fpga_histogram_r_data_81; // word name
		struct {
			uint32_t hist_r_data_81 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_82 14'h03C0 */
	union {
		uint32_t fpga_histogram_r_data_82; // word name
		struct {
			uint32_t hist_r_data_82 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_83 14'h03C4 */
	union {
		uint32_t fpga_histogram_r_data_83; // word name
		struct {
			uint32_t hist_r_data_83 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_84 14'h03C8 */
	union {
		uint32_t fpga_histogram_r_data_84; // word name
		struct {
			uint32_t hist_r_data_84 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_85 14'h03CC */
	union {
		uint32_t fpga_histogram_r_data_85; // word name
		struct {
			uint32_t hist_r_data_85 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_86 14'h03D0 */
	union {
		uint32_t fpga_histogram_r_data_86; // word name
		struct {
			uint32_t hist_r_data_86 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_87 14'h03D4 */
	union {
		uint32_t fpga_histogram_r_data_87; // word name
		struct {
			uint32_t hist_r_data_87 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_88 14'h03D8 */
	union {
		uint32_t fpga_histogram_r_data_88; // word name
		struct {
			uint32_t hist_r_data_88 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_89 14'h03DC */
	union {
		uint32_t fpga_histogram_r_data_89; // word name
		struct {
			uint32_t hist_r_data_89 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_90 14'h03E0 */
	union {
		uint32_t fpga_histogram_r_data_90; // word name
		struct {
			uint32_t hist_r_data_90 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_91 14'h03E4 */
	union {
		uint32_t fpga_histogram_r_data_91; // word name
		struct {
			uint32_t hist_r_data_91 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_92 14'h03E8 */
	union {
		uint32_t fpga_histogram_r_data_92; // word name
		struct {
			uint32_t hist_r_data_92 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_93 14'h03EC */
	union {
		uint32_t fpga_histogram_r_data_93; // word name
		struct {
			uint32_t hist_r_data_93 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_94 14'h03F0 */
	union {
		uint32_t fpga_histogram_r_data_94; // word name
		struct {
			uint32_t hist_r_data_94 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_95 14'h03F4 */
	union {
		uint32_t fpga_histogram_r_data_95; // word name
		struct {
			uint32_t hist_r_data_95 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_96 14'h03F8 */
	union {
		uint32_t fpga_histogram_r_data_96; // word name
		struct {
			uint32_t hist_r_data_96 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_97 14'h03FC */
	union {
		uint32_t fpga_histogram_r_data_97; // word name
		struct {
			uint32_t hist_r_data_97 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_98 14'h0400 */
	union {
		uint32_t fpga_histogram_r_data_98; // word name
		struct {
			uint32_t hist_r_data_98 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_99 14'h0404 */
	union {
		uint32_t fpga_histogram_r_data_99; // word name
		struct {
			uint32_t hist_r_data_99 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_100 14'h0408 */
	union {
		uint32_t fpga_histogram_r_data_100; // word name
		struct {
			uint32_t hist_r_data_100 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_101 14'h040C */
	union {
		uint32_t fpga_histogram_r_data_101; // word name
		struct {
			uint32_t hist_r_data_101 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_102 14'h0410 */
	union {
		uint32_t fpga_histogram_r_data_102; // word name
		struct {
			uint32_t hist_r_data_102 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_103 14'h0414 */
	union {
		uint32_t fpga_histogram_r_data_103; // word name
		struct {
			uint32_t hist_r_data_103 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_104 14'h0418 */
	union {
		uint32_t fpga_histogram_r_data_104; // word name
		struct {
			uint32_t hist_r_data_104 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_105 14'h041C */
	union {
		uint32_t fpga_histogram_r_data_105; // word name
		struct {
			uint32_t hist_r_data_105 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_106 14'h0420 */
	union {
		uint32_t fpga_histogram_r_data_106; // word name
		struct {
			uint32_t hist_r_data_106 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_107 14'h0424 */
	union {
		uint32_t fpga_histogram_r_data_107; // word name
		struct {
			uint32_t hist_r_data_107 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_108 14'h0428 */
	union {
		uint32_t fpga_histogram_r_data_108; // word name
		struct {
			uint32_t hist_r_data_108 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_109 14'h042C */
	union {
		uint32_t fpga_histogram_r_data_109; // word name
		struct {
			uint32_t hist_r_data_109 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_110 14'h0430 */
	union {
		uint32_t fpga_histogram_r_data_110; // word name
		struct {
			uint32_t hist_r_data_110 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_111 14'h0434 */
	union {
		uint32_t fpga_histogram_r_data_111; // word name
		struct {
			uint32_t hist_r_data_111 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_112 14'h0438 */
	union {
		uint32_t fpga_histogram_r_data_112; // word name
		struct {
			uint32_t hist_r_data_112 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_113 14'h043C */
	union {
		uint32_t fpga_histogram_r_data_113; // word name
		struct {
			uint32_t hist_r_data_113 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_114 14'h0440 */
	union {
		uint32_t fpga_histogram_r_data_114; // word name
		struct {
			uint32_t hist_r_data_114 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_115 14'h0444 */
	union {
		uint32_t fpga_histogram_r_data_115; // word name
		struct {
			uint32_t hist_r_data_115 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_116 14'h0448 */
	union {
		uint32_t fpga_histogram_r_data_116; // word name
		struct {
			uint32_t hist_r_data_116 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_117 14'h044C */
	union {
		uint32_t fpga_histogram_r_data_117; // word name
		struct {
			uint32_t hist_r_data_117 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_118 14'h0450 */
	union {
		uint32_t fpga_histogram_r_data_118; // word name
		struct {
			uint32_t hist_r_data_118 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_119 14'h0454 */
	union {
		uint32_t fpga_histogram_r_data_119; // word name
		struct {
			uint32_t hist_r_data_119 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_120 14'h0458 */
	union {
		uint32_t fpga_histogram_r_data_120; // word name
		struct {
			uint32_t hist_r_data_120 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_121 14'h045C */
	union {
		uint32_t fpga_histogram_r_data_121; // word name
		struct {
			uint32_t hist_r_data_121 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_122 14'h0460 */
	union {
		uint32_t fpga_histogram_r_data_122; // word name
		struct {
			uint32_t hist_r_data_122 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_123 14'h0464 */
	union {
		uint32_t fpga_histogram_r_data_123; // word name
		struct {
			uint32_t hist_r_data_123 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_124 14'h0468 */
	union {
		uint32_t fpga_histogram_r_data_124; // word name
		struct {
			uint32_t hist_r_data_124 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_125 14'h046C */
	union {
		uint32_t fpga_histogram_r_data_125; // word name
		struct {
			uint32_t hist_r_data_125 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_126 14'h0470 */
	union {
		uint32_t fpga_histogram_r_data_126; // word name
		struct {
			uint32_t hist_r_data_126 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_127 14'h0474 */
	union {
		uint32_t fpga_histogram_r_data_127; // word name
		struct {
			uint32_t hist_r_data_127 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_128 14'h0478 */
	union {
		uint32_t fpga_histogram_r_data_128; // word name
		struct {
			uint32_t hist_r_data_128 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_129 14'h047C */
	union {
		uint32_t fpga_histogram_r_data_129; // word name
		struct {
			uint32_t hist_r_data_129 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_130 14'h0480 */
	union {
		uint32_t fpga_histogram_r_data_130; // word name
		struct {
			uint32_t hist_r_data_130 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_131 14'h0484 */
	union {
		uint32_t fpga_histogram_r_data_131; // word name
		struct {
			uint32_t hist_r_data_131 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_132 14'h0488 */
	union {
		uint32_t fpga_histogram_r_data_132; // word name
		struct {
			uint32_t hist_r_data_132 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_133 14'h048C */
	union {
		uint32_t fpga_histogram_r_data_133; // word name
		struct {
			uint32_t hist_r_data_133 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_134 14'h0490 */
	union {
		uint32_t fpga_histogram_r_data_134; // word name
		struct {
			uint32_t hist_r_data_134 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_135 14'h0494 */
	union {
		uint32_t fpga_histogram_r_data_135; // word name
		struct {
			uint32_t hist_r_data_135 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_136 14'h0498 */
	union {
		uint32_t fpga_histogram_r_data_136; // word name
		struct {
			uint32_t hist_r_data_136 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_137 14'h049C */
	union {
		uint32_t fpga_histogram_r_data_137; // word name
		struct {
			uint32_t hist_r_data_137 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_138 14'h04A0 */
	union {
		uint32_t fpga_histogram_r_data_138; // word name
		struct {
			uint32_t hist_r_data_138 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_139 14'h04A4 */
	union {
		uint32_t fpga_histogram_r_data_139; // word name
		struct {
			uint32_t hist_r_data_139 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_140 14'h04A8 */
	union {
		uint32_t fpga_histogram_r_data_140; // word name
		struct {
			uint32_t hist_r_data_140 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_141 14'h04AC */
	union {
		uint32_t fpga_histogram_r_data_141; // word name
		struct {
			uint32_t hist_r_data_141 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_142 14'h04B0 */
	union {
		uint32_t fpga_histogram_r_data_142; // word name
		struct {
			uint32_t hist_r_data_142 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_143 14'h04B4 */
	union {
		uint32_t fpga_histogram_r_data_143; // word name
		struct {
			uint32_t hist_r_data_143 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_144 14'h04B8 */
	union {
		uint32_t fpga_histogram_r_data_144; // word name
		struct {
			uint32_t hist_r_data_144 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_145 14'h04BC */
	union {
		uint32_t fpga_histogram_r_data_145; // word name
		struct {
			uint32_t hist_r_data_145 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_146 14'h04C0 */
	union {
		uint32_t fpga_histogram_r_data_146; // word name
		struct {
			uint32_t hist_r_data_146 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_147 14'h04C4 */
	union {
		uint32_t fpga_histogram_r_data_147; // word name
		struct {
			uint32_t hist_r_data_147 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_148 14'h04C8 */
	union {
		uint32_t fpga_histogram_r_data_148; // word name
		struct {
			uint32_t hist_r_data_148 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_149 14'h04CC */
	union {
		uint32_t fpga_histogram_r_data_149; // word name
		struct {
			uint32_t hist_r_data_149 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_150 14'h04D0 */
	union {
		uint32_t fpga_histogram_r_data_150; // word name
		struct {
			uint32_t hist_r_data_150 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_151 14'h04D4 */
	union {
		uint32_t fpga_histogram_r_data_151; // word name
		struct {
			uint32_t hist_r_data_151 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_152 14'h04D8 */
	union {
		uint32_t fpga_histogram_r_data_152; // word name
		struct {
			uint32_t hist_r_data_152 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_153 14'h04DC */
	union {
		uint32_t fpga_histogram_r_data_153; // word name
		struct {
			uint32_t hist_r_data_153 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_154 14'h04E0 */
	union {
		uint32_t fpga_histogram_r_data_154; // word name
		struct {
			uint32_t hist_r_data_154 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_155 14'h04E4 */
	union {
		uint32_t fpga_histogram_r_data_155; // word name
		struct {
			uint32_t hist_r_data_155 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_156 14'h04E8 */
	union {
		uint32_t fpga_histogram_r_data_156; // word name
		struct {
			uint32_t hist_r_data_156 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_157 14'h04EC */
	union {
		uint32_t fpga_histogram_r_data_157; // word name
		struct {
			uint32_t hist_r_data_157 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_158 14'h04F0 */
	union {
		uint32_t fpga_histogram_r_data_158; // word name
		struct {
			uint32_t hist_r_data_158 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_159 14'h04F4 */
	union {
		uint32_t fpga_histogram_r_data_159; // word name
		struct {
			uint32_t hist_r_data_159 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_160 14'h04F8 */
	union {
		uint32_t fpga_histogram_r_data_160; // word name
		struct {
			uint32_t hist_r_data_160 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_161 14'h04FC */
	union {
		uint32_t fpga_histogram_r_data_161; // word name
		struct {
			uint32_t hist_r_data_161 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_162 14'h0500 */
	union {
		uint32_t fpga_histogram_r_data_162; // word name
		struct {
			uint32_t hist_r_data_162 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_163 14'h0504 */
	union {
		uint32_t fpga_histogram_r_data_163; // word name
		struct {
			uint32_t hist_r_data_163 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_164 14'h0508 */
	union {
		uint32_t fpga_histogram_r_data_164; // word name
		struct {
			uint32_t hist_r_data_164 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_165 14'h050C */
	union {
		uint32_t fpga_histogram_r_data_165; // word name
		struct {
			uint32_t hist_r_data_165 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_166 14'h0510 */
	union {
		uint32_t fpga_histogram_r_data_166; // word name
		struct {
			uint32_t hist_r_data_166 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_167 14'h0514 */
	union {
		uint32_t fpga_histogram_r_data_167; // word name
		struct {
			uint32_t hist_r_data_167 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_168 14'h0518 */
	union {
		uint32_t fpga_histogram_r_data_168; // word name
		struct {
			uint32_t hist_r_data_168 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_169 14'h051C */
	union {
		uint32_t fpga_histogram_r_data_169; // word name
		struct {
			uint32_t hist_r_data_169 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_170 14'h0520 */
	union {
		uint32_t fpga_histogram_r_data_170; // word name
		struct {
			uint32_t hist_r_data_170 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_171 14'h0524 */
	union {
		uint32_t fpga_histogram_r_data_171; // word name
		struct {
			uint32_t hist_r_data_171 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_172 14'h0528 */
	union {
		uint32_t fpga_histogram_r_data_172; // word name
		struct {
			uint32_t hist_r_data_172 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_173 14'h052C */
	union {
		uint32_t fpga_histogram_r_data_173; // word name
		struct {
			uint32_t hist_r_data_173 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_174 14'h0530 */
	union {
		uint32_t fpga_histogram_r_data_174; // word name
		struct {
			uint32_t hist_r_data_174 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_175 14'h0534 */
	union {
		uint32_t fpga_histogram_r_data_175; // word name
		struct {
			uint32_t hist_r_data_175 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_176 14'h0538 */
	union {
		uint32_t fpga_histogram_r_data_176; // word name
		struct {
			uint32_t hist_r_data_176 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_177 14'h053C */
	union {
		uint32_t fpga_histogram_r_data_177; // word name
		struct {
			uint32_t hist_r_data_177 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_178 14'h0540 */
	union {
		uint32_t fpga_histogram_r_data_178; // word name
		struct {
			uint32_t hist_r_data_178 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_179 14'h0544 */
	union {
		uint32_t fpga_histogram_r_data_179; // word name
		struct {
			uint32_t hist_r_data_179 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_180 14'h0548 */
	union {
		uint32_t fpga_histogram_r_data_180; // word name
		struct {
			uint32_t hist_r_data_180 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_181 14'h054C */
	union {
		uint32_t fpga_histogram_r_data_181; // word name
		struct {
			uint32_t hist_r_data_181 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_182 14'h0550 */
	union {
		uint32_t fpga_histogram_r_data_182; // word name
		struct {
			uint32_t hist_r_data_182 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_183 14'h0554 */
	union {
		uint32_t fpga_histogram_r_data_183; // word name
		struct {
			uint32_t hist_r_data_183 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_184 14'h0558 */
	union {
		uint32_t fpga_histogram_r_data_184; // word name
		struct {
			uint32_t hist_r_data_184 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_185 14'h055C */
	union {
		uint32_t fpga_histogram_r_data_185; // word name
		struct {
			uint32_t hist_r_data_185 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_186 14'h0560 */
	union {
		uint32_t fpga_histogram_r_data_186; // word name
		struct {
			uint32_t hist_r_data_186 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_187 14'h0564 */
	union {
		uint32_t fpga_histogram_r_data_187; // word name
		struct {
			uint32_t hist_r_data_187 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_188 14'h0568 */
	union {
		uint32_t fpga_histogram_r_data_188; // word name
		struct {
			uint32_t hist_r_data_188 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_189 14'h056C */
	union {
		uint32_t fpga_histogram_r_data_189; // word name
		struct {
			uint32_t hist_r_data_189 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_190 14'h0570 */
	union {
		uint32_t fpga_histogram_r_data_190; // word name
		struct {
			uint32_t hist_r_data_190 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_191 14'h0574 */
	union {
		uint32_t fpga_histogram_r_data_191; // word name
		struct {
			uint32_t hist_r_data_191 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_192 14'h0578 */
	union {
		uint32_t fpga_histogram_r_data_192; // word name
		struct {
			uint32_t hist_r_data_192 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_193 14'h057C */
	union {
		uint32_t fpga_histogram_r_data_193; // word name
		struct {
			uint32_t hist_r_data_193 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_194 14'h0580 */
	union {
		uint32_t fpga_histogram_r_data_194; // word name
		struct {
			uint32_t hist_r_data_194 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_195 14'h0584 */
	union {
		uint32_t fpga_histogram_r_data_195; // word name
		struct {
			uint32_t hist_r_data_195 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_196 14'h0588 */
	union {
		uint32_t fpga_histogram_r_data_196; // word name
		struct {
			uint32_t hist_r_data_196 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_197 14'h058C */
	union {
		uint32_t fpga_histogram_r_data_197; // word name
		struct {
			uint32_t hist_r_data_197 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_198 14'h0590 */
	union {
		uint32_t fpga_histogram_r_data_198; // word name
		struct {
			uint32_t hist_r_data_198 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_199 14'h0594 */
	union {
		uint32_t fpga_histogram_r_data_199; // word name
		struct {
			uint32_t hist_r_data_199 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_200 14'h0598 */
	union {
		uint32_t fpga_histogram_r_data_200; // word name
		struct {
			uint32_t hist_r_data_200 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_201 14'h059C */
	union {
		uint32_t fpga_histogram_r_data_201; // word name
		struct {
			uint32_t hist_r_data_201 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_202 14'h05A0 */
	union {
		uint32_t fpga_histogram_r_data_202; // word name
		struct {
			uint32_t hist_r_data_202 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_203 14'h05A4 */
	union {
		uint32_t fpga_histogram_r_data_203; // word name
		struct {
			uint32_t hist_r_data_203 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_204 14'h05A8 */
	union {
		uint32_t fpga_histogram_r_data_204; // word name
		struct {
			uint32_t hist_r_data_204 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_205 14'h05AC */
	union {
		uint32_t fpga_histogram_r_data_205; // word name
		struct {
			uint32_t hist_r_data_205 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_206 14'h05B0 */
	union {
		uint32_t fpga_histogram_r_data_206; // word name
		struct {
			uint32_t hist_r_data_206 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_207 14'h05B4 */
	union {
		uint32_t fpga_histogram_r_data_207; // word name
		struct {
			uint32_t hist_r_data_207 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_208 14'h05B8 */
	union {
		uint32_t fpga_histogram_r_data_208; // word name
		struct {
			uint32_t hist_r_data_208 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_209 14'h05BC */
	union {
		uint32_t fpga_histogram_r_data_209; // word name
		struct {
			uint32_t hist_r_data_209 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_210 14'h05C0 */
	union {
		uint32_t fpga_histogram_r_data_210; // word name
		struct {
			uint32_t hist_r_data_210 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_211 14'h05C4 */
	union {
		uint32_t fpga_histogram_r_data_211; // word name
		struct {
			uint32_t hist_r_data_211 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_212 14'h05C8 */
	union {
		uint32_t fpga_histogram_r_data_212; // word name
		struct {
			uint32_t hist_r_data_212 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_213 14'h05CC */
	union {
		uint32_t fpga_histogram_r_data_213; // word name
		struct {
			uint32_t hist_r_data_213 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_214 14'h05D0 */
	union {
		uint32_t fpga_histogram_r_data_214; // word name
		struct {
			uint32_t hist_r_data_214 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_215 14'h05D4 */
	union {
		uint32_t fpga_histogram_r_data_215; // word name
		struct {
			uint32_t hist_r_data_215 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_216 14'h05D8 */
	union {
		uint32_t fpga_histogram_r_data_216; // word name
		struct {
			uint32_t hist_r_data_216 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_217 14'h05DC */
	union {
		uint32_t fpga_histogram_r_data_217; // word name
		struct {
			uint32_t hist_r_data_217 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_218 14'h05E0 */
	union {
		uint32_t fpga_histogram_r_data_218; // word name
		struct {
			uint32_t hist_r_data_218 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_219 14'h05E4 */
	union {
		uint32_t fpga_histogram_r_data_219; // word name
		struct {
			uint32_t hist_r_data_219 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_220 14'h05E8 */
	union {
		uint32_t fpga_histogram_r_data_220; // word name
		struct {
			uint32_t hist_r_data_220 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_221 14'h05EC */
	union {
		uint32_t fpga_histogram_r_data_221; // word name
		struct {
			uint32_t hist_r_data_221 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_222 14'h05F0 */
	union {
		uint32_t fpga_histogram_r_data_222; // word name
		struct {
			uint32_t hist_r_data_222 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_223 14'h05F4 */
	union {
		uint32_t fpga_histogram_r_data_223; // word name
		struct {
			uint32_t hist_r_data_223 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_224 14'h05F8 */
	union {
		uint32_t fpga_histogram_r_data_224; // word name
		struct {
			uint32_t hist_r_data_224 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_225 14'h05FC */
	union {
		uint32_t fpga_histogram_r_data_225; // word name
		struct {
			uint32_t hist_r_data_225 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_226 14'h0600 */
	union {
		uint32_t fpga_histogram_r_data_226; // word name
		struct {
			uint32_t hist_r_data_226 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_227 14'h0604 */
	union {
		uint32_t fpga_histogram_r_data_227; // word name
		struct {
			uint32_t hist_r_data_227 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_228 14'h0608 */
	union {
		uint32_t fpga_histogram_r_data_228; // word name
		struct {
			uint32_t hist_r_data_228 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_229 14'h060C */
	union {
		uint32_t fpga_histogram_r_data_229; // word name
		struct {
			uint32_t hist_r_data_229 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_230 14'h0610 */
	union {
		uint32_t fpga_histogram_r_data_230; // word name
		struct {
			uint32_t hist_r_data_230 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_231 14'h0614 */
	union {
		uint32_t fpga_histogram_r_data_231; // word name
		struct {
			uint32_t hist_r_data_231 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_232 14'h0618 */
	union {
		uint32_t fpga_histogram_r_data_232; // word name
		struct {
			uint32_t hist_r_data_232 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_233 14'h061C */
	union {
		uint32_t fpga_histogram_r_data_233; // word name
		struct {
			uint32_t hist_r_data_233 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_234 14'h0620 */
	union {
		uint32_t fpga_histogram_r_data_234; // word name
		struct {
			uint32_t hist_r_data_234 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_235 14'h0624 */
	union {
		uint32_t fpga_histogram_r_data_235; // word name
		struct {
			uint32_t hist_r_data_235 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_236 14'h0628 */
	union {
		uint32_t fpga_histogram_r_data_236; // word name
		struct {
			uint32_t hist_r_data_236 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_237 14'h062C */
	union {
		uint32_t fpga_histogram_r_data_237; // word name
		struct {
			uint32_t hist_r_data_237 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_238 14'h0630 */
	union {
		uint32_t fpga_histogram_r_data_238; // word name
		struct {
			uint32_t hist_r_data_238 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_239 14'h0634 */
	union {
		uint32_t fpga_histogram_r_data_239; // word name
		struct {
			uint32_t hist_r_data_239 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_240 14'h0638 */
	union {
		uint32_t fpga_histogram_r_data_240; // word name
		struct {
			uint32_t hist_r_data_240 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_241 14'h063C */
	union {
		uint32_t fpga_histogram_r_data_241; // word name
		struct {
			uint32_t hist_r_data_241 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_242 14'h0640 */
	union {
		uint32_t fpga_histogram_r_data_242; // word name
		struct {
			uint32_t hist_r_data_242 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_243 14'h0644 */
	union {
		uint32_t fpga_histogram_r_data_243; // word name
		struct {
			uint32_t hist_r_data_243 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_244 14'h0648 */
	union {
		uint32_t fpga_histogram_r_data_244; // word name
		struct {
			uint32_t hist_r_data_244 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_245 14'h064C */
	union {
		uint32_t fpga_histogram_r_data_245; // word name
		struct {
			uint32_t hist_r_data_245 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_246 14'h0650 */
	union {
		uint32_t fpga_histogram_r_data_246; // word name
		struct {
			uint32_t hist_r_data_246 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_247 14'h0654 */
	union {
		uint32_t fpga_histogram_r_data_247; // word name
		struct {
			uint32_t hist_r_data_247 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_248 14'h0658 */
	union {
		uint32_t fpga_histogram_r_data_248; // word name
		struct {
			uint32_t hist_r_data_248 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_249 14'h065C */
	union {
		uint32_t fpga_histogram_r_data_249; // word name
		struct {
			uint32_t hist_r_data_249 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_250 14'h0660 */
	union {
		uint32_t fpga_histogram_r_data_250; // word name
		struct {
			uint32_t hist_r_data_250 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_251 14'h0664 */
	union {
		uint32_t fpga_histogram_r_data_251; // word name
		struct {
			uint32_t hist_r_data_251 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_252 14'h0668 */
	union {
		uint32_t fpga_histogram_r_data_252; // word name
		struct {
			uint32_t hist_r_data_252 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_253 14'h066C */
	union {
		uint32_t fpga_histogram_r_data_253; // word name
		struct {
			uint32_t hist_r_data_253 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_254 14'h0670 */
	union {
		uint32_t fpga_histogram_r_data_254; // word name
		struct {
			uint32_t hist_r_data_254 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_255 14'h0674 */
	union {
		uint32_t fpga_histogram_r_data_255; // word name
		struct {
			uint32_t hist_r_data_255 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_256 14'h0678 */
	union {
		uint32_t fpga_histogram_r_data_256; // word name
		struct {
			uint32_t hist_r_data_256 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_257 14'h067C */
	union {
		uint32_t fpga_histogram_r_data_257; // word name
		struct {
			uint32_t hist_r_data_257 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_258 14'h0680 */
	union {
		uint32_t fpga_histogram_r_data_258; // word name
		struct {
			uint32_t hist_r_data_258 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_259 14'h0684 */
	union {
		uint32_t fpga_histogram_r_data_259; // word name
		struct {
			uint32_t hist_r_data_259 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_260 14'h0688 */
	union {
		uint32_t fpga_histogram_r_data_260; // word name
		struct {
			uint32_t hist_r_data_260 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_261 14'h068C */
	union {
		uint32_t fpga_histogram_r_data_261; // word name
		struct {
			uint32_t hist_r_data_261 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_262 14'h0690 */
	union {
		uint32_t fpga_histogram_r_data_262; // word name
		struct {
			uint32_t hist_r_data_262 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_263 14'h0694 */
	union {
		uint32_t fpga_histogram_r_data_263; // word name
		struct {
			uint32_t hist_r_data_263 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_264 14'h0698 */
	union {
		uint32_t fpga_histogram_r_data_264; // word name
		struct {
			uint32_t hist_r_data_264 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_265 14'h069C */
	union {
		uint32_t fpga_histogram_r_data_265; // word name
		struct {
			uint32_t hist_r_data_265 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_266 14'h06A0 */
	union {
		uint32_t fpga_histogram_r_data_266; // word name
		struct {
			uint32_t hist_r_data_266 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_267 14'h06A4 */
	union {
		uint32_t fpga_histogram_r_data_267; // word name
		struct {
			uint32_t hist_r_data_267 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_268 14'h06A8 */
	union {
		uint32_t fpga_histogram_r_data_268; // word name
		struct {
			uint32_t hist_r_data_268 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_269 14'h06AC */
	union {
		uint32_t fpga_histogram_r_data_269; // word name
		struct {
			uint32_t hist_r_data_269 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_270 14'h06B0 */
	union {
		uint32_t fpga_histogram_r_data_270; // word name
		struct {
			uint32_t hist_r_data_270 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_271 14'h06B4 */
	union {
		uint32_t fpga_histogram_r_data_271; // word name
		struct {
			uint32_t hist_r_data_271 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_272 14'h06B8 */
	union {
		uint32_t fpga_histogram_r_data_272; // word name
		struct {
			uint32_t hist_r_data_272 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_273 14'h06BC */
	union {
		uint32_t fpga_histogram_r_data_273; // word name
		struct {
			uint32_t hist_r_data_273 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_274 14'h06C0 */
	union {
		uint32_t fpga_histogram_r_data_274; // word name
		struct {
			uint32_t hist_r_data_274 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_275 14'h06C4 */
	union {
		uint32_t fpga_histogram_r_data_275; // word name
		struct {
			uint32_t hist_r_data_275 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_276 14'h06C8 */
	union {
		uint32_t fpga_histogram_r_data_276; // word name
		struct {
			uint32_t hist_r_data_276 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_277 14'h06CC */
	union {
		uint32_t fpga_histogram_r_data_277; // word name
		struct {
			uint32_t hist_r_data_277 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_278 14'h06D0 */
	union {
		uint32_t fpga_histogram_r_data_278; // word name
		struct {
			uint32_t hist_r_data_278 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_279 14'h06D4 */
	union {
		uint32_t fpga_histogram_r_data_279; // word name
		struct {
			uint32_t hist_r_data_279 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_280 14'h06D8 */
	union {
		uint32_t fpga_histogram_r_data_280; // word name
		struct {
			uint32_t hist_r_data_280 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_281 14'h06DC */
	union {
		uint32_t fpga_histogram_r_data_281; // word name
		struct {
			uint32_t hist_r_data_281 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_282 14'h06E0 */
	union {
		uint32_t fpga_histogram_r_data_282; // word name
		struct {
			uint32_t hist_r_data_282 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_283 14'h06E4 */
	union {
		uint32_t fpga_histogram_r_data_283; // word name
		struct {
			uint32_t hist_r_data_283 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_284 14'h06E8 */
	union {
		uint32_t fpga_histogram_r_data_284; // word name
		struct {
			uint32_t hist_r_data_284 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_285 14'h06EC */
	union {
		uint32_t fpga_histogram_r_data_285; // word name
		struct {
			uint32_t hist_r_data_285 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_286 14'h06F0 */
	union {
		uint32_t fpga_histogram_r_data_286; // word name
		struct {
			uint32_t hist_r_data_286 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_287 14'h06F4 */
	union {
		uint32_t fpga_histogram_r_data_287; // word name
		struct {
			uint32_t hist_r_data_287 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_288 14'h06F8 */
	union {
		uint32_t fpga_histogram_r_data_288; // word name
		struct {
			uint32_t hist_r_data_288 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_289 14'h06FC */
	union {
		uint32_t fpga_histogram_r_data_289; // word name
		struct {
			uint32_t hist_r_data_289 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_290 14'h0700 */
	union {
		uint32_t fpga_histogram_r_data_290; // word name
		struct {
			uint32_t hist_r_data_290 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_291 14'h0704 */
	union {
		uint32_t fpga_histogram_r_data_291; // word name
		struct {
			uint32_t hist_r_data_291 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_292 14'h0708 */
	union {
		uint32_t fpga_histogram_r_data_292; // word name
		struct {
			uint32_t hist_r_data_292 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_293 14'h070C */
	union {
		uint32_t fpga_histogram_r_data_293; // word name
		struct {
			uint32_t hist_r_data_293 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_294 14'h0710 */
	union {
		uint32_t fpga_histogram_r_data_294; // word name
		struct {
			uint32_t hist_r_data_294 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_295 14'h0714 */
	union {
		uint32_t fpga_histogram_r_data_295; // word name
		struct {
			uint32_t hist_r_data_295 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_296 14'h0718 */
	union {
		uint32_t fpga_histogram_r_data_296; // word name
		struct {
			uint32_t hist_r_data_296 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_297 14'h071C */
	union {
		uint32_t fpga_histogram_r_data_297; // word name
		struct {
			uint32_t hist_r_data_297 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_298 14'h0720 */
	union {
		uint32_t fpga_histogram_r_data_298; // word name
		struct {
			uint32_t hist_r_data_298 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_299 14'h0724 */
	union {
		uint32_t fpga_histogram_r_data_299; // word name
		struct {
			uint32_t hist_r_data_299 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_300 14'h0728 */
	union {
		uint32_t fpga_histogram_r_data_300; // word name
		struct {
			uint32_t hist_r_data_300 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_301 14'h072C */
	union {
		uint32_t fpga_histogram_r_data_301; // word name
		struct {
			uint32_t hist_r_data_301 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_302 14'h0730 */
	union {
		uint32_t fpga_histogram_r_data_302; // word name
		struct {
			uint32_t hist_r_data_302 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_303 14'h0734 */
	union {
		uint32_t fpga_histogram_r_data_303; // word name
		struct {
			uint32_t hist_r_data_303 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_304 14'h0738 */
	union {
		uint32_t fpga_histogram_r_data_304; // word name
		struct {
			uint32_t hist_r_data_304 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_305 14'h073C */
	union {
		uint32_t fpga_histogram_r_data_305; // word name
		struct {
			uint32_t hist_r_data_305 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_306 14'h0740 */
	union {
		uint32_t fpga_histogram_r_data_306; // word name
		struct {
			uint32_t hist_r_data_306 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_307 14'h0744 */
	union {
		uint32_t fpga_histogram_r_data_307; // word name
		struct {
			uint32_t hist_r_data_307 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_308 14'h0748 */
	union {
		uint32_t fpga_histogram_r_data_308; // word name
		struct {
			uint32_t hist_r_data_308 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_309 14'h074C */
	union {
		uint32_t fpga_histogram_r_data_309; // word name
		struct {
			uint32_t hist_r_data_309 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_310 14'h0750 */
	union {
		uint32_t fpga_histogram_r_data_310; // word name
		struct {
			uint32_t hist_r_data_310 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_311 14'h0754 */
	union {
		uint32_t fpga_histogram_r_data_311; // word name
		struct {
			uint32_t hist_r_data_311 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_312 14'h0758 */
	union {
		uint32_t fpga_histogram_r_data_312; // word name
		struct {
			uint32_t hist_r_data_312 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_313 14'h075C */
	union {
		uint32_t fpga_histogram_r_data_313; // word name
		struct {
			uint32_t hist_r_data_313 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_314 14'h0760 */
	union {
		uint32_t fpga_histogram_r_data_314; // word name
		struct {
			uint32_t hist_r_data_314 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_315 14'h0764 */
	union {
		uint32_t fpga_histogram_r_data_315; // word name
		struct {
			uint32_t hist_r_data_315 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_316 14'h0768 */
	union {
		uint32_t fpga_histogram_r_data_316; // word name
		struct {
			uint32_t hist_r_data_316 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_317 14'h076C */
	union {
		uint32_t fpga_histogram_r_data_317; // word name
		struct {
			uint32_t hist_r_data_317 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_318 14'h0770 */
	union {
		uint32_t fpga_histogram_r_data_318; // word name
		struct {
			uint32_t hist_r_data_318 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_319 14'h0774 */
	union {
		uint32_t fpga_histogram_r_data_319; // word name
		struct {
			uint32_t hist_r_data_319 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_320 14'h0778 */
	union {
		uint32_t fpga_histogram_r_data_320; // word name
		struct {
			uint32_t hist_r_data_320 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_321 14'h077C */
	union {
		uint32_t fpga_histogram_r_data_321; // word name
		struct {
			uint32_t hist_r_data_321 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_322 14'h0780 */
	union {
		uint32_t fpga_histogram_r_data_322; // word name
		struct {
			uint32_t hist_r_data_322 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_323 14'h0784 */
	union {
		uint32_t fpga_histogram_r_data_323; // word name
		struct {
			uint32_t hist_r_data_323 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_324 14'h0788 */
	union {
		uint32_t fpga_histogram_r_data_324; // word name
		struct {
			uint32_t hist_r_data_324 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_325 14'h078C */
	union {
		uint32_t fpga_histogram_r_data_325; // word name
		struct {
			uint32_t hist_r_data_325 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_326 14'h0790 */
	union {
		uint32_t fpga_histogram_r_data_326; // word name
		struct {
			uint32_t hist_r_data_326 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_327 14'h0794 */
	union {
		uint32_t fpga_histogram_r_data_327; // word name
		struct {
			uint32_t hist_r_data_327 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_328 14'h0798 */
	union {
		uint32_t fpga_histogram_r_data_328; // word name
		struct {
			uint32_t hist_r_data_328 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_329 14'h079C */
	union {
		uint32_t fpga_histogram_r_data_329; // word name
		struct {
			uint32_t hist_r_data_329 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_330 14'h07A0 */
	union {
		uint32_t fpga_histogram_r_data_330; // word name
		struct {
			uint32_t hist_r_data_330 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_331 14'h07A4 */
	union {
		uint32_t fpga_histogram_r_data_331; // word name
		struct {
			uint32_t hist_r_data_331 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_332 14'h07A8 */
	union {
		uint32_t fpga_histogram_r_data_332; // word name
		struct {
			uint32_t hist_r_data_332 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_333 14'h07AC */
	union {
		uint32_t fpga_histogram_r_data_333; // word name
		struct {
			uint32_t hist_r_data_333 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_334 14'h07B0 */
	union {
		uint32_t fpga_histogram_r_data_334; // word name
		struct {
			uint32_t hist_r_data_334 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_335 14'h07B4 */
	union {
		uint32_t fpga_histogram_r_data_335; // word name
		struct {
			uint32_t hist_r_data_335 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_336 14'h07B8 */
	union {
		uint32_t fpga_histogram_r_data_336; // word name
		struct {
			uint32_t hist_r_data_336 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_337 14'h07BC */
	union {
		uint32_t fpga_histogram_r_data_337; // word name
		struct {
			uint32_t hist_r_data_337 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_338 14'h07C0 */
	union {
		uint32_t fpga_histogram_r_data_338; // word name
		struct {
			uint32_t hist_r_data_338 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_339 14'h07C4 */
	union {
		uint32_t fpga_histogram_r_data_339; // word name
		struct {
			uint32_t hist_r_data_339 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_340 14'h07C8 */
	union {
		uint32_t fpga_histogram_r_data_340; // word name
		struct {
			uint32_t hist_r_data_340 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_341 14'h07CC */
	union {
		uint32_t fpga_histogram_r_data_341; // word name
		struct {
			uint32_t hist_r_data_341 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_342 14'h07D0 */
	union {
		uint32_t fpga_histogram_r_data_342; // word name
		struct {
			uint32_t hist_r_data_342 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_343 14'h07D4 */
	union {
		uint32_t fpga_histogram_r_data_343; // word name
		struct {
			uint32_t hist_r_data_343 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_344 14'h07D8 */
	union {
		uint32_t fpga_histogram_r_data_344; // word name
		struct {
			uint32_t hist_r_data_344 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_345 14'h07DC */
	union {
		uint32_t fpga_histogram_r_data_345; // word name
		struct {
			uint32_t hist_r_data_345 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_346 14'h07E0 */
	union {
		uint32_t fpga_histogram_r_data_346; // word name
		struct {
			uint32_t hist_r_data_346 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_347 14'h07E4 */
	union {
		uint32_t fpga_histogram_r_data_347; // word name
		struct {
			uint32_t hist_r_data_347 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_348 14'h07E8 */
	union {
		uint32_t fpga_histogram_r_data_348; // word name
		struct {
			uint32_t hist_r_data_348 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_349 14'h07EC */
	union {
		uint32_t fpga_histogram_r_data_349; // word name
		struct {
			uint32_t hist_r_data_349 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_350 14'h07F0 */
	union {
		uint32_t fpga_histogram_r_data_350; // word name
		struct {
			uint32_t hist_r_data_350 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_351 14'h07F4 */
	union {
		uint32_t fpga_histogram_r_data_351; // word name
		struct {
			uint32_t hist_r_data_351 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_352 14'h07F8 */
	union {
		uint32_t fpga_histogram_r_data_352; // word name
		struct {
			uint32_t hist_r_data_352 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_353 14'h07FC */
	union {
		uint32_t fpga_histogram_r_data_353; // word name
		struct {
			uint32_t hist_r_data_353 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_354 14'h0800 */
	union {
		uint32_t fpga_histogram_r_data_354; // word name
		struct {
			uint32_t hist_r_data_354 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_355 14'h0804 */
	union {
		uint32_t fpga_histogram_r_data_355; // word name
		struct {
			uint32_t hist_r_data_355 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_356 14'h0808 */
	union {
		uint32_t fpga_histogram_r_data_356; // word name
		struct {
			uint32_t hist_r_data_356 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_357 14'h080C */
	union {
		uint32_t fpga_histogram_r_data_357; // word name
		struct {
			uint32_t hist_r_data_357 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_358 14'h0810 */
	union {
		uint32_t fpga_histogram_r_data_358; // word name
		struct {
			uint32_t hist_r_data_358 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_359 14'h0814 */
	union {
		uint32_t fpga_histogram_r_data_359; // word name
		struct {
			uint32_t hist_r_data_359 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_360 14'h0818 */
	union {
		uint32_t fpga_histogram_r_data_360; // word name
		struct {
			uint32_t hist_r_data_360 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_361 14'h081C */
	union {
		uint32_t fpga_histogram_r_data_361; // word name
		struct {
			uint32_t hist_r_data_361 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_362 14'h0820 */
	union {
		uint32_t fpga_histogram_r_data_362; // word name
		struct {
			uint32_t hist_r_data_362 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_363 14'h0824 */
	union {
		uint32_t fpga_histogram_r_data_363; // word name
		struct {
			uint32_t hist_r_data_363 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_364 14'h0828 */
	union {
		uint32_t fpga_histogram_r_data_364; // word name
		struct {
			uint32_t hist_r_data_364 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_365 14'h082C */
	union {
		uint32_t fpga_histogram_r_data_365; // word name
		struct {
			uint32_t hist_r_data_365 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_366 14'h0830 */
	union {
		uint32_t fpga_histogram_r_data_366; // word name
		struct {
			uint32_t hist_r_data_366 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_367 14'h0834 */
	union {
		uint32_t fpga_histogram_r_data_367; // word name
		struct {
			uint32_t hist_r_data_367 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_368 14'h0838 */
	union {
		uint32_t fpga_histogram_r_data_368; // word name
		struct {
			uint32_t hist_r_data_368 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_369 14'h083C */
	union {
		uint32_t fpga_histogram_r_data_369; // word name
		struct {
			uint32_t hist_r_data_369 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_370 14'h0840 */
	union {
		uint32_t fpga_histogram_r_data_370; // word name
		struct {
			uint32_t hist_r_data_370 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_371 14'h0844 */
	union {
		uint32_t fpga_histogram_r_data_371; // word name
		struct {
			uint32_t hist_r_data_371 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_372 14'h0848 */
	union {
		uint32_t fpga_histogram_r_data_372; // word name
		struct {
			uint32_t hist_r_data_372 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_373 14'h084C */
	union {
		uint32_t fpga_histogram_r_data_373; // word name
		struct {
			uint32_t hist_r_data_373 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_374 14'h0850 */
	union {
		uint32_t fpga_histogram_r_data_374; // word name
		struct {
			uint32_t hist_r_data_374 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_375 14'h0854 */
	union {
		uint32_t fpga_histogram_r_data_375; // word name
		struct {
			uint32_t hist_r_data_375 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_376 14'h0858 */
	union {
		uint32_t fpga_histogram_r_data_376; // word name
		struct {
			uint32_t hist_r_data_376 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_377 14'h085C */
	union {
		uint32_t fpga_histogram_r_data_377; // word name
		struct {
			uint32_t hist_r_data_377 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_378 14'h0860 */
	union {
		uint32_t fpga_histogram_r_data_378; // word name
		struct {
			uint32_t hist_r_data_378 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_379 14'h0864 */
	union {
		uint32_t fpga_histogram_r_data_379; // word name
		struct {
			uint32_t hist_r_data_379 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_380 14'h0868 */
	union {
		uint32_t fpga_histogram_r_data_380; // word name
		struct {
			uint32_t hist_r_data_380 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_381 14'h086C */
	union {
		uint32_t fpga_histogram_r_data_381; // word name
		struct {
			uint32_t hist_r_data_381 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_382 14'h0870 */
	union {
		uint32_t fpga_histogram_r_data_382; // word name
		struct {
			uint32_t hist_r_data_382 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_383 14'h0874 */
	union {
		uint32_t fpga_histogram_r_data_383; // word name
		struct {
			uint32_t hist_r_data_383 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_384 14'h0878 */
	union {
		uint32_t fpga_histogram_r_data_384; // word name
		struct {
			uint32_t hist_r_data_384 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_385 14'h087C */
	union {
		uint32_t fpga_histogram_r_data_385; // word name
		struct {
			uint32_t hist_r_data_385 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_386 14'h0880 */
	union {
		uint32_t fpga_histogram_r_data_386; // word name
		struct {
			uint32_t hist_r_data_386 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_387 14'h0884 */
	union {
		uint32_t fpga_histogram_r_data_387; // word name
		struct {
			uint32_t hist_r_data_387 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_388 14'h0888 */
	union {
		uint32_t fpga_histogram_r_data_388; // word name
		struct {
			uint32_t hist_r_data_388 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_389 14'h088C */
	union {
		uint32_t fpga_histogram_r_data_389; // word name
		struct {
			uint32_t hist_r_data_389 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_390 14'h0890 */
	union {
		uint32_t fpga_histogram_r_data_390; // word name
		struct {
			uint32_t hist_r_data_390 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_391 14'h0894 */
	union {
		uint32_t fpga_histogram_r_data_391; // word name
		struct {
			uint32_t hist_r_data_391 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_392 14'h0898 */
	union {
		uint32_t fpga_histogram_r_data_392; // word name
		struct {
			uint32_t hist_r_data_392 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_393 14'h089C */
	union {
		uint32_t fpga_histogram_r_data_393; // word name
		struct {
			uint32_t hist_r_data_393 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_394 14'h08A0 */
	union {
		uint32_t fpga_histogram_r_data_394; // word name
		struct {
			uint32_t hist_r_data_394 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_395 14'h08A4 */
	union {
		uint32_t fpga_histogram_r_data_395; // word name
		struct {
			uint32_t hist_r_data_395 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_396 14'h08A8 */
	union {
		uint32_t fpga_histogram_r_data_396; // word name
		struct {
			uint32_t hist_r_data_396 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_397 14'h08AC */
	union {
		uint32_t fpga_histogram_r_data_397; // word name
		struct {
			uint32_t hist_r_data_397 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_398 14'h08B0 */
	union {
		uint32_t fpga_histogram_r_data_398; // word name
		struct {
			uint32_t hist_r_data_398 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_399 14'h08B4 */
	union {
		uint32_t fpga_histogram_r_data_399; // word name
		struct {
			uint32_t hist_r_data_399 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_400 14'h08B8 */
	union {
		uint32_t fpga_histogram_r_data_400; // word name
		struct {
			uint32_t hist_r_data_400 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_401 14'h08BC */
	union {
		uint32_t fpga_histogram_r_data_401; // word name
		struct {
			uint32_t hist_r_data_401 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_402 14'h08C0 */
	union {
		uint32_t fpga_histogram_r_data_402; // word name
		struct {
			uint32_t hist_r_data_402 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_403 14'h08C4 */
	union {
		uint32_t fpga_histogram_r_data_403; // word name
		struct {
			uint32_t hist_r_data_403 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_404 14'h08C8 */
	union {
		uint32_t fpga_histogram_r_data_404; // word name
		struct {
			uint32_t hist_r_data_404 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_405 14'h08CC */
	union {
		uint32_t fpga_histogram_r_data_405; // word name
		struct {
			uint32_t hist_r_data_405 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_406 14'h08D0 */
	union {
		uint32_t fpga_histogram_r_data_406; // word name
		struct {
			uint32_t hist_r_data_406 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_407 14'h08D4 */
	union {
		uint32_t fpga_histogram_r_data_407; // word name
		struct {
			uint32_t hist_r_data_407 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_408 14'h08D8 */
	union {
		uint32_t fpga_histogram_r_data_408; // word name
		struct {
			uint32_t hist_r_data_408 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_409 14'h08DC */
	union {
		uint32_t fpga_histogram_r_data_409; // word name
		struct {
			uint32_t hist_r_data_409 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_410 14'h08E0 */
	union {
		uint32_t fpga_histogram_r_data_410; // word name
		struct {
			uint32_t hist_r_data_410 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_411 14'h08E4 */
	union {
		uint32_t fpga_histogram_r_data_411; // word name
		struct {
			uint32_t hist_r_data_411 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_412 14'h08E8 */
	union {
		uint32_t fpga_histogram_r_data_412; // word name
		struct {
			uint32_t hist_r_data_412 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_413 14'h08EC */
	union {
		uint32_t fpga_histogram_r_data_413; // word name
		struct {
			uint32_t hist_r_data_413 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_414 14'h08F0 */
	union {
		uint32_t fpga_histogram_r_data_414; // word name
		struct {
			uint32_t hist_r_data_414 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_415 14'h08F4 */
	union {
		uint32_t fpga_histogram_r_data_415; // word name
		struct {
			uint32_t hist_r_data_415 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_416 14'h08F8 */
	union {
		uint32_t fpga_histogram_r_data_416; // word name
		struct {
			uint32_t hist_r_data_416 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_417 14'h08FC */
	union {
		uint32_t fpga_histogram_r_data_417; // word name
		struct {
			uint32_t hist_r_data_417 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_418 14'h0900 */
	union {
		uint32_t fpga_histogram_r_data_418; // word name
		struct {
			uint32_t hist_r_data_418 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_419 14'h0904 */
	union {
		uint32_t fpga_histogram_r_data_419; // word name
		struct {
			uint32_t hist_r_data_419 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_420 14'h0908 */
	union {
		uint32_t fpga_histogram_r_data_420; // word name
		struct {
			uint32_t hist_r_data_420 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_421 14'h090C */
	union {
		uint32_t fpga_histogram_r_data_421; // word name
		struct {
			uint32_t hist_r_data_421 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_422 14'h0910 */
	union {
		uint32_t fpga_histogram_r_data_422; // word name
		struct {
			uint32_t hist_r_data_422 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_423 14'h0914 */
	union {
		uint32_t fpga_histogram_r_data_423; // word name
		struct {
			uint32_t hist_r_data_423 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_424 14'h0918 */
	union {
		uint32_t fpga_histogram_r_data_424; // word name
		struct {
			uint32_t hist_r_data_424 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_425 14'h091C */
	union {
		uint32_t fpga_histogram_r_data_425; // word name
		struct {
			uint32_t hist_r_data_425 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_426 14'h0920 */
	union {
		uint32_t fpga_histogram_r_data_426; // word name
		struct {
			uint32_t hist_r_data_426 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_427 14'h0924 */
	union {
		uint32_t fpga_histogram_r_data_427; // word name
		struct {
			uint32_t hist_r_data_427 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_428 14'h0928 */
	union {
		uint32_t fpga_histogram_r_data_428; // word name
		struct {
			uint32_t hist_r_data_428 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_429 14'h092C */
	union {
		uint32_t fpga_histogram_r_data_429; // word name
		struct {
			uint32_t hist_r_data_429 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_430 14'h0930 */
	union {
		uint32_t fpga_histogram_r_data_430; // word name
		struct {
			uint32_t hist_r_data_430 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_431 14'h0934 */
	union {
		uint32_t fpga_histogram_r_data_431; // word name
		struct {
			uint32_t hist_r_data_431 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_432 14'h0938 */
	union {
		uint32_t fpga_histogram_r_data_432; // word name
		struct {
			uint32_t hist_r_data_432 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_433 14'h093C */
	union {
		uint32_t fpga_histogram_r_data_433; // word name
		struct {
			uint32_t hist_r_data_433 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_434 14'h0940 */
	union {
		uint32_t fpga_histogram_r_data_434; // word name
		struct {
			uint32_t hist_r_data_434 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_435 14'h0944 */
	union {
		uint32_t fpga_histogram_r_data_435; // word name
		struct {
			uint32_t hist_r_data_435 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_436 14'h0948 */
	union {
		uint32_t fpga_histogram_r_data_436; // word name
		struct {
			uint32_t hist_r_data_436 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_437 14'h094C */
	union {
		uint32_t fpga_histogram_r_data_437; // word name
		struct {
			uint32_t hist_r_data_437 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_438 14'h0950 */
	union {
		uint32_t fpga_histogram_r_data_438; // word name
		struct {
			uint32_t hist_r_data_438 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_439 14'h0954 */
	union {
		uint32_t fpga_histogram_r_data_439; // word name
		struct {
			uint32_t hist_r_data_439 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_440 14'h0958 */
	union {
		uint32_t fpga_histogram_r_data_440; // word name
		struct {
			uint32_t hist_r_data_440 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_441 14'h095C */
	union {
		uint32_t fpga_histogram_r_data_441; // word name
		struct {
			uint32_t hist_r_data_441 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_442 14'h0960 */
	union {
		uint32_t fpga_histogram_r_data_442; // word name
		struct {
			uint32_t hist_r_data_442 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_443 14'h0964 */
	union {
		uint32_t fpga_histogram_r_data_443; // word name
		struct {
			uint32_t hist_r_data_443 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_444 14'h0968 */
	union {
		uint32_t fpga_histogram_r_data_444; // word name
		struct {
			uint32_t hist_r_data_444 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_445 14'h096C */
	union {
		uint32_t fpga_histogram_r_data_445; // word name
		struct {
			uint32_t hist_r_data_445 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_446 14'h0970 */
	union {
		uint32_t fpga_histogram_r_data_446; // word name
		struct {
			uint32_t hist_r_data_446 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_447 14'h0974 */
	union {
		uint32_t fpga_histogram_r_data_447; // word name
		struct {
			uint32_t hist_r_data_447 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_448 14'h0978 */
	union {
		uint32_t fpga_histogram_r_data_448; // word name
		struct {
			uint32_t hist_r_data_448 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_449 14'h097C */
	union {
		uint32_t fpga_histogram_r_data_449; // word name
		struct {
			uint32_t hist_r_data_449 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_450 14'h0980 */
	union {
		uint32_t fpga_histogram_r_data_450; // word name
		struct {
			uint32_t hist_r_data_450 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_451 14'h0984 */
	union {
		uint32_t fpga_histogram_r_data_451; // word name
		struct {
			uint32_t hist_r_data_451 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_452 14'h0988 */
	union {
		uint32_t fpga_histogram_r_data_452; // word name
		struct {
			uint32_t hist_r_data_452 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_453 14'h098C */
	union {
		uint32_t fpga_histogram_r_data_453; // word name
		struct {
			uint32_t hist_r_data_453 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_454 14'h0990 */
	union {
		uint32_t fpga_histogram_r_data_454; // word name
		struct {
			uint32_t hist_r_data_454 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_455 14'h0994 */
	union {
		uint32_t fpga_histogram_r_data_455; // word name
		struct {
			uint32_t hist_r_data_455 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_456 14'h0998 */
	union {
		uint32_t fpga_histogram_r_data_456; // word name
		struct {
			uint32_t hist_r_data_456 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_457 14'h099C */
	union {
		uint32_t fpga_histogram_r_data_457; // word name
		struct {
			uint32_t hist_r_data_457 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_458 14'h09A0 */
	union {
		uint32_t fpga_histogram_r_data_458; // word name
		struct {
			uint32_t hist_r_data_458 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_459 14'h09A4 */
	union {
		uint32_t fpga_histogram_r_data_459; // word name
		struct {
			uint32_t hist_r_data_459 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_460 14'h09A8 */
	union {
		uint32_t fpga_histogram_r_data_460; // word name
		struct {
			uint32_t hist_r_data_460 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_461 14'h09AC */
	union {
		uint32_t fpga_histogram_r_data_461; // word name
		struct {
			uint32_t hist_r_data_461 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_462 14'h09B0 */
	union {
		uint32_t fpga_histogram_r_data_462; // word name
		struct {
			uint32_t hist_r_data_462 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_463 14'h09B4 */
	union {
		uint32_t fpga_histogram_r_data_463; // word name
		struct {
			uint32_t hist_r_data_463 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_464 14'h09B8 */
	union {
		uint32_t fpga_histogram_r_data_464; // word name
		struct {
			uint32_t hist_r_data_464 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_465 14'h09BC */
	union {
		uint32_t fpga_histogram_r_data_465; // word name
		struct {
			uint32_t hist_r_data_465 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_466 14'h09C0 */
	union {
		uint32_t fpga_histogram_r_data_466; // word name
		struct {
			uint32_t hist_r_data_466 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_467 14'h09C4 */
	union {
		uint32_t fpga_histogram_r_data_467; // word name
		struct {
			uint32_t hist_r_data_467 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_468 14'h09C8 */
	union {
		uint32_t fpga_histogram_r_data_468; // word name
		struct {
			uint32_t hist_r_data_468 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_469 14'h09CC */
	union {
		uint32_t fpga_histogram_r_data_469; // word name
		struct {
			uint32_t hist_r_data_469 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_470 14'h09D0 */
	union {
		uint32_t fpga_histogram_r_data_470; // word name
		struct {
			uint32_t hist_r_data_470 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_471 14'h09D4 */
	union {
		uint32_t fpga_histogram_r_data_471; // word name
		struct {
			uint32_t hist_r_data_471 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_472 14'h09D8 */
	union {
		uint32_t fpga_histogram_r_data_472; // word name
		struct {
			uint32_t hist_r_data_472 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_473 14'h09DC */
	union {
		uint32_t fpga_histogram_r_data_473; // word name
		struct {
			uint32_t hist_r_data_473 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_474 14'h09E0 */
	union {
		uint32_t fpga_histogram_r_data_474; // word name
		struct {
			uint32_t hist_r_data_474 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_475 14'h09E4 */
	union {
		uint32_t fpga_histogram_r_data_475; // word name
		struct {
			uint32_t hist_r_data_475 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_476 14'h09E8 */
	union {
		uint32_t fpga_histogram_r_data_476; // word name
		struct {
			uint32_t hist_r_data_476 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_477 14'h09EC */
	union {
		uint32_t fpga_histogram_r_data_477; // word name
		struct {
			uint32_t hist_r_data_477 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_478 14'h09F0 */
	union {
		uint32_t fpga_histogram_r_data_478; // word name
		struct {
			uint32_t hist_r_data_478 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_479 14'h09F4 */
	union {
		uint32_t fpga_histogram_r_data_479; // word name
		struct {
			uint32_t hist_r_data_479 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_480 14'h09F8 */
	union {
		uint32_t fpga_histogram_r_data_480; // word name
		struct {
			uint32_t hist_r_data_480 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_481 14'h09FC */
	union {
		uint32_t fpga_histogram_r_data_481; // word name
		struct {
			uint32_t hist_r_data_481 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_482 14'h0A00 */
	union {
		uint32_t fpga_histogram_r_data_482; // word name
		struct {
			uint32_t hist_r_data_482 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_483 14'h0A04 */
	union {
		uint32_t fpga_histogram_r_data_483; // word name
		struct {
			uint32_t hist_r_data_483 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_484 14'h0A08 */
	union {
		uint32_t fpga_histogram_r_data_484; // word name
		struct {
			uint32_t hist_r_data_484 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_485 14'h0A0C */
	union {
		uint32_t fpga_histogram_r_data_485; // word name
		struct {
			uint32_t hist_r_data_485 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_486 14'h0A10 */
	union {
		uint32_t fpga_histogram_r_data_486; // word name
		struct {
			uint32_t hist_r_data_486 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_487 14'h0A14 */
	union {
		uint32_t fpga_histogram_r_data_487; // word name
		struct {
			uint32_t hist_r_data_487 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_488 14'h0A18 */
	union {
		uint32_t fpga_histogram_r_data_488; // word name
		struct {
			uint32_t hist_r_data_488 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_489 14'h0A1C */
	union {
		uint32_t fpga_histogram_r_data_489; // word name
		struct {
			uint32_t hist_r_data_489 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_490 14'h0A20 */
	union {
		uint32_t fpga_histogram_r_data_490; // word name
		struct {
			uint32_t hist_r_data_490 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_491 14'h0A24 */
	union {
		uint32_t fpga_histogram_r_data_491; // word name
		struct {
			uint32_t hist_r_data_491 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_492 14'h0A28 */
	union {
		uint32_t fpga_histogram_r_data_492; // word name
		struct {
			uint32_t hist_r_data_492 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_493 14'h0A2C */
	union {
		uint32_t fpga_histogram_r_data_493; // word name
		struct {
			uint32_t hist_r_data_493 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_494 14'h0A30 */
	union {
		uint32_t fpga_histogram_r_data_494; // word name
		struct {
			uint32_t hist_r_data_494 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_495 14'h0A34 */
	union {
		uint32_t fpga_histogram_r_data_495; // word name
		struct {
			uint32_t hist_r_data_495 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_496 14'h0A38 */
	union {
		uint32_t fpga_histogram_r_data_496; // word name
		struct {
			uint32_t hist_r_data_496 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_497 14'h0A3C */
	union {
		uint32_t fpga_histogram_r_data_497; // word name
		struct {
			uint32_t hist_r_data_497 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_498 14'h0A40 */
	union {
		uint32_t fpga_histogram_r_data_498; // word name
		struct {
			uint32_t hist_r_data_498 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_499 14'h0A44 */
	union {
		uint32_t fpga_histogram_r_data_499; // word name
		struct {
			uint32_t hist_r_data_499 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_500 14'h0A48 */
	union {
		uint32_t fpga_histogram_r_data_500; // word name
		struct {
			uint32_t hist_r_data_500 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_501 14'h0A4C */
	union {
		uint32_t fpga_histogram_r_data_501; // word name
		struct {
			uint32_t hist_r_data_501 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_502 14'h0A50 */
	union {
		uint32_t fpga_histogram_r_data_502; // word name
		struct {
			uint32_t hist_r_data_502 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_503 14'h0A54 */
	union {
		uint32_t fpga_histogram_r_data_503; // word name
		struct {
			uint32_t hist_r_data_503 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_504 14'h0A58 */
	union {
		uint32_t fpga_histogram_r_data_504; // word name
		struct {
			uint32_t hist_r_data_504 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_505 14'h0A5C */
	union {
		uint32_t fpga_histogram_r_data_505; // word name
		struct {
			uint32_t hist_r_data_505 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_506 14'h0A60 */
	union {
		uint32_t fpga_histogram_r_data_506; // word name
		struct {
			uint32_t hist_r_data_506 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_507 14'h0A64 */
	union {
		uint32_t fpga_histogram_r_data_507; // word name
		struct {
			uint32_t hist_r_data_507 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_508 14'h0A68 */
	union {
		uint32_t fpga_histogram_r_data_508; // word name
		struct {
			uint32_t hist_r_data_508 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_509 14'h0A6C */
	union {
		uint32_t fpga_histogram_r_data_509; // word name
		struct {
			uint32_t hist_r_data_509 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_510 14'h0A70 */
	union {
		uint32_t fpga_histogram_r_data_510; // word name
		struct {
			uint32_t hist_r_data_510 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_511 14'h0A74 */
	union {
		uint32_t fpga_histogram_r_data_511; // word name
		struct {
			uint32_t hist_r_data_511 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_512 14'h0A78 */
	union {
		uint32_t fpga_histogram_r_data_512; // word name
		struct {
			uint32_t hist_r_data_512 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_513 14'h0A7C */
	union {
		uint32_t fpga_histogram_r_data_513; // word name
		struct {
			uint32_t hist_r_data_513 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_514 14'h0A80 */
	union {
		uint32_t fpga_histogram_r_data_514; // word name
		struct {
			uint32_t hist_r_data_514 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_515 14'h0A84 */
	union {
		uint32_t fpga_histogram_r_data_515; // word name
		struct {
			uint32_t hist_r_data_515 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_516 14'h0A88 */
	union {
		uint32_t fpga_histogram_r_data_516; // word name
		struct {
			uint32_t hist_r_data_516 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_517 14'h0A8C */
	union {
		uint32_t fpga_histogram_r_data_517; // word name
		struct {
			uint32_t hist_r_data_517 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_518 14'h0A90 */
	union {
		uint32_t fpga_histogram_r_data_518; // word name
		struct {
			uint32_t hist_r_data_518 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_519 14'h0A94 */
	union {
		uint32_t fpga_histogram_r_data_519; // word name
		struct {
			uint32_t hist_r_data_519 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_520 14'h0A98 */
	union {
		uint32_t fpga_histogram_r_data_520; // word name
		struct {
			uint32_t hist_r_data_520 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_521 14'h0A9C */
	union {
		uint32_t fpga_histogram_r_data_521; // word name
		struct {
			uint32_t hist_r_data_521 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_522 14'h0AA0 */
	union {
		uint32_t fpga_histogram_r_data_522; // word name
		struct {
			uint32_t hist_r_data_522 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_523 14'h0AA4 */
	union {
		uint32_t fpga_histogram_r_data_523; // word name
		struct {
			uint32_t hist_r_data_523 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_524 14'h0AA8 */
	union {
		uint32_t fpga_histogram_r_data_524; // word name
		struct {
			uint32_t hist_r_data_524 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_525 14'h0AAC */
	union {
		uint32_t fpga_histogram_r_data_525; // word name
		struct {
			uint32_t hist_r_data_525 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_526 14'h0AB0 */
	union {
		uint32_t fpga_histogram_r_data_526; // word name
		struct {
			uint32_t hist_r_data_526 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_527 14'h0AB4 */
	union {
		uint32_t fpga_histogram_r_data_527; // word name
		struct {
			uint32_t hist_r_data_527 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_528 14'h0AB8 */
	union {
		uint32_t fpga_histogram_r_data_528; // word name
		struct {
			uint32_t hist_r_data_528 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_529 14'h0ABC */
	union {
		uint32_t fpga_histogram_r_data_529; // word name
		struct {
			uint32_t hist_r_data_529 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_530 14'h0AC0 */
	union {
		uint32_t fpga_histogram_r_data_530; // word name
		struct {
			uint32_t hist_r_data_530 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_531 14'h0AC4 */
	union {
		uint32_t fpga_histogram_r_data_531; // word name
		struct {
			uint32_t hist_r_data_531 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_532 14'h0AC8 */
	union {
		uint32_t fpga_histogram_r_data_532; // word name
		struct {
			uint32_t hist_r_data_532 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_533 14'h0ACC */
	union {
		uint32_t fpga_histogram_r_data_533; // word name
		struct {
			uint32_t hist_r_data_533 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_534 14'h0AD0 */
	union {
		uint32_t fpga_histogram_r_data_534; // word name
		struct {
			uint32_t hist_r_data_534 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_535 14'h0AD4 */
	union {
		uint32_t fpga_histogram_r_data_535; // word name
		struct {
			uint32_t hist_r_data_535 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_536 14'h0AD8 */
	union {
		uint32_t fpga_histogram_r_data_536; // word name
		struct {
			uint32_t hist_r_data_536 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_537 14'h0ADC */
	union {
		uint32_t fpga_histogram_r_data_537; // word name
		struct {
			uint32_t hist_r_data_537 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_538 14'h0AE0 */
	union {
		uint32_t fpga_histogram_r_data_538; // word name
		struct {
			uint32_t hist_r_data_538 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_539 14'h0AE4 */
	union {
		uint32_t fpga_histogram_r_data_539; // word name
		struct {
			uint32_t hist_r_data_539 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_540 14'h0AE8 */
	union {
		uint32_t fpga_histogram_r_data_540; // word name
		struct {
			uint32_t hist_r_data_540 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_541 14'h0AEC */
	union {
		uint32_t fpga_histogram_r_data_541; // word name
		struct {
			uint32_t hist_r_data_541 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_542 14'h0AF0 */
	union {
		uint32_t fpga_histogram_r_data_542; // word name
		struct {
			uint32_t hist_r_data_542 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_543 14'h0AF4 */
	union {
		uint32_t fpga_histogram_r_data_543; // word name
		struct {
			uint32_t hist_r_data_543 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_544 14'h0AF8 */
	union {
		uint32_t fpga_histogram_r_data_544; // word name
		struct {
			uint32_t hist_r_data_544 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_545 14'h0AFC */
	union {
		uint32_t fpga_histogram_r_data_545; // word name
		struct {
			uint32_t hist_r_data_545 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_546 14'h0B00 */
	union {
		uint32_t fpga_histogram_r_data_546; // word name
		struct {
			uint32_t hist_r_data_546 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_547 14'h0B04 */
	union {
		uint32_t fpga_histogram_r_data_547; // word name
		struct {
			uint32_t hist_r_data_547 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_548 14'h0B08 */
	union {
		uint32_t fpga_histogram_r_data_548; // word name
		struct {
			uint32_t hist_r_data_548 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_549 14'h0B0C */
	union {
		uint32_t fpga_histogram_r_data_549; // word name
		struct {
			uint32_t hist_r_data_549 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_550 14'h0B10 */
	union {
		uint32_t fpga_histogram_r_data_550; // word name
		struct {
			uint32_t hist_r_data_550 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_551 14'h0B14 */
	union {
		uint32_t fpga_histogram_r_data_551; // word name
		struct {
			uint32_t hist_r_data_551 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_552 14'h0B18 */
	union {
		uint32_t fpga_histogram_r_data_552; // word name
		struct {
			uint32_t hist_r_data_552 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_553 14'h0B1C */
	union {
		uint32_t fpga_histogram_r_data_553; // word name
		struct {
			uint32_t hist_r_data_553 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_554 14'h0B20 */
	union {
		uint32_t fpga_histogram_r_data_554; // word name
		struct {
			uint32_t hist_r_data_554 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_555 14'h0B24 */
	union {
		uint32_t fpga_histogram_r_data_555; // word name
		struct {
			uint32_t hist_r_data_555 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_556 14'h0B28 */
	union {
		uint32_t fpga_histogram_r_data_556; // word name
		struct {
			uint32_t hist_r_data_556 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_557 14'h0B2C */
	union {
		uint32_t fpga_histogram_r_data_557; // word name
		struct {
			uint32_t hist_r_data_557 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_558 14'h0B30 */
	union {
		uint32_t fpga_histogram_r_data_558; // word name
		struct {
			uint32_t hist_r_data_558 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_559 14'h0B34 */
	union {
		uint32_t fpga_histogram_r_data_559; // word name
		struct {
			uint32_t hist_r_data_559 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_560 14'h0B38 */
	union {
		uint32_t fpga_histogram_r_data_560; // word name
		struct {
			uint32_t hist_r_data_560 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_561 14'h0B3C */
	union {
		uint32_t fpga_histogram_r_data_561; // word name
		struct {
			uint32_t hist_r_data_561 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_562 14'h0B40 */
	union {
		uint32_t fpga_histogram_r_data_562; // word name
		struct {
			uint32_t hist_r_data_562 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_563 14'h0B44 */
	union {
		uint32_t fpga_histogram_r_data_563; // word name
		struct {
			uint32_t hist_r_data_563 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_564 14'h0B48 */
	union {
		uint32_t fpga_histogram_r_data_564; // word name
		struct {
			uint32_t hist_r_data_564 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_565 14'h0B4C */
	union {
		uint32_t fpga_histogram_r_data_565; // word name
		struct {
			uint32_t hist_r_data_565 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_566 14'h0B50 */
	union {
		uint32_t fpga_histogram_r_data_566; // word name
		struct {
			uint32_t hist_r_data_566 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_567 14'h0B54 */
	union {
		uint32_t fpga_histogram_r_data_567; // word name
		struct {
			uint32_t hist_r_data_567 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_568 14'h0B58 */
	union {
		uint32_t fpga_histogram_r_data_568; // word name
		struct {
			uint32_t hist_r_data_568 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_569 14'h0B5C */
	union {
		uint32_t fpga_histogram_r_data_569; // word name
		struct {
			uint32_t hist_r_data_569 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_570 14'h0B60 */
	union {
		uint32_t fpga_histogram_r_data_570; // word name
		struct {
			uint32_t hist_r_data_570 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_571 14'h0B64 */
	union {
		uint32_t fpga_histogram_r_data_571; // word name
		struct {
			uint32_t hist_r_data_571 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_572 14'h0B68 */
	union {
		uint32_t fpga_histogram_r_data_572; // word name
		struct {
			uint32_t hist_r_data_572 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_573 14'h0B6C */
	union {
		uint32_t fpga_histogram_r_data_573; // word name
		struct {
			uint32_t hist_r_data_573 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_574 14'h0B70 */
	union {
		uint32_t fpga_histogram_r_data_574; // word name
		struct {
			uint32_t hist_r_data_574 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_575 14'h0B74 */
	union {
		uint32_t fpga_histogram_r_data_575; // word name
		struct {
			uint32_t hist_r_data_575 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_576 14'h0B78 */
	union {
		uint32_t fpga_histogram_r_data_576; // word name
		struct {
			uint32_t hist_r_data_576 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_577 14'h0B7C */
	union {
		uint32_t fpga_histogram_r_data_577; // word name
		struct {
			uint32_t hist_r_data_577 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_578 14'h0B80 */
	union {
		uint32_t fpga_histogram_r_data_578; // word name
		struct {
			uint32_t hist_r_data_578 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_579 14'h0B84 */
	union {
		uint32_t fpga_histogram_r_data_579; // word name
		struct {
			uint32_t hist_r_data_579 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_580 14'h0B88 */
	union {
		uint32_t fpga_histogram_r_data_580; // word name
		struct {
			uint32_t hist_r_data_580 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_581 14'h0B8C */
	union {
		uint32_t fpga_histogram_r_data_581; // word name
		struct {
			uint32_t hist_r_data_581 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_582 14'h0B90 */
	union {
		uint32_t fpga_histogram_r_data_582; // word name
		struct {
			uint32_t hist_r_data_582 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_583 14'h0B94 */
	union {
		uint32_t fpga_histogram_r_data_583; // word name
		struct {
			uint32_t hist_r_data_583 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_584 14'h0B98 */
	union {
		uint32_t fpga_histogram_r_data_584; // word name
		struct {
			uint32_t hist_r_data_584 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_585 14'h0B9C */
	union {
		uint32_t fpga_histogram_r_data_585; // word name
		struct {
			uint32_t hist_r_data_585 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_586 14'h0BA0 */
	union {
		uint32_t fpga_histogram_r_data_586; // word name
		struct {
			uint32_t hist_r_data_586 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_587 14'h0BA4 */
	union {
		uint32_t fpga_histogram_r_data_587; // word name
		struct {
			uint32_t hist_r_data_587 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_588 14'h0BA8 */
	union {
		uint32_t fpga_histogram_r_data_588; // word name
		struct {
			uint32_t hist_r_data_588 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_589 14'h0BAC */
	union {
		uint32_t fpga_histogram_r_data_589; // word name
		struct {
			uint32_t hist_r_data_589 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_590 14'h0BB0 */
	union {
		uint32_t fpga_histogram_r_data_590; // word name
		struct {
			uint32_t hist_r_data_590 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_591 14'h0BB4 */
	union {
		uint32_t fpga_histogram_r_data_591; // word name
		struct {
			uint32_t hist_r_data_591 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_592 14'h0BB8 */
	union {
		uint32_t fpga_histogram_r_data_592; // word name
		struct {
			uint32_t hist_r_data_592 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_593 14'h0BBC */
	union {
		uint32_t fpga_histogram_r_data_593; // word name
		struct {
			uint32_t hist_r_data_593 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_594 14'h0BC0 */
	union {
		uint32_t fpga_histogram_r_data_594; // word name
		struct {
			uint32_t hist_r_data_594 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_595 14'h0BC4 */
	union {
		uint32_t fpga_histogram_r_data_595; // word name
		struct {
			uint32_t hist_r_data_595 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_596 14'h0BC8 */
	union {
		uint32_t fpga_histogram_r_data_596; // word name
		struct {
			uint32_t hist_r_data_596 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_597 14'h0BCC */
	union {
		uint32_t fpga_histogram_r_data_597; // word name
		struct {
			uint32_t hist_r_data_597 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_598 14'h0BD0 */
	union {
		uint32_t fpga_histogram_r_data_598; // word name
		struct {
			uint32_t hist_r_data_598 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_599 14'h0BD4 */
	union {
		uint32_t fpga_histogram_r_data_599; // word name
		struct {
			uint32_t hist_r_data_599 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_600 14'h0BD8 */
	union {
		uint32_t fpga_histogram_r_data_600; // word name
		struct {
			uint32_t hist_r_data_600 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_601 14'h0BDC */
	union {
		uint32_t fpga_histogram_r_data_601; // word name
		struct {
			uint32_t hist_r_data_601 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_602 14'h0BE0 */
	union {
		uint32_t fpga_histogram_r_data_602; // word name
		struct {
			uint32_t hist_r_data_602 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_603 14'h0BE4 */
	union {
		uint32_t fpga_histogram_r_data_603; // word name
		struct {
			uint32_t hist_r_data_603 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_604 14'h0BE8 */
	union {
		uint32_t fpga_histogram_r_data_604; // word name
		struct {
			uint32_t hist_r_data_604 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_605 14'h0BEC */
	union {
		uint32_t fpga_histogram_r_data_605; // word name
		struct {
			uint32_t hist_r_data_605 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_606 14'h0BF0 */
	union {
		uint32_t fpga_histogram_r_data_606; // word name
		struct {
			uint32_t hist_r_data_606 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_607 14'h0BF4 */
	union {
		uint32_t fpga_histogram_r_data_607; // word name
		struct {
			uint32_t hist_r_data_607 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_608 14'h0BF8 */
	union {
		uint32_t fpga_histogram_r_data_608; // word name
		struct {
			uint32_t hist_r_data_608 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_609 14'h0BFC */
	union {
		uint32_t fpga_histogram_r_data_609; // word name
		struct {
			uint32_t hist_r_data_609 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_610 14'h0C00 */
	union {
		uint32_t fpga_histogram_r_data_610; // word name
		struct {
			uint32_t hist_r_data_610 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_611 14'h0C04 */
	union {
		uint32_t fpga_histogram_r_data_611; // word name
		struct {
			uint32_t hist_r_data_611 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_612 14'h0C08 */
	union {
		uint32_t fpga_histogram_r_data_612; // word name
		struct {
			uint32_t hist_r_data_612 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_613 14'h0C0C */
	union {
		uint32_t fpga_histogram_r_data_613; // word name
		struct {
			uint32_t hist_r_data_613 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_614 14'h0C10 */
	union {
		uint32_t fpga_histogram_r_data_614; // word name
		struct {
			uint32_t hist_r_data_614 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_615 14'h0C14 */
	union {
		uint32_t fpga_histogram_r_data_615; // word name
		struct {
			uint32_t hist_r_data_615 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_616 14'h0C18 */
	union {
		uint32_t fpga_histogram_r_data_616; // word name
		struct {
			uint32_t hist_r_data_616 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_617 14'h0C1C */
	union {
		uint32_t fpga_histogram_r_data_617; // word name
		struct {
			uint32_t hist_r_data_617 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_618 14'h0C20 */
	union {
		uint32_t fpga_histogram_r_data_618; // word name
		struct {
			uint32_t hist_r_data_618 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_619 14'h0C24 */
	union {
		uint32_t fpga_histogram_r_data_619; // word name
		struct {
			uint32_t hist_r_data_619 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_620 14'h0C28 */
	union {
		uint32_t fpga_histogram_r_data_620; // word name
		struct {
			uint32_t hist_r_data_620 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_621 14'h0C2C */
	union {
		uint32_t fpga_histogram_r_data_621; // word name
		struct {
			uint32_t hist_r_data_621 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_622 14'h0C30 */
	union {
		uint32_t fpga_histogram_r_data_622; // word name
		struct {
			uint32_t hist_r_data_622 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_623 14'h0C34 */
	union {
		uint32_t fpga_histogram_r_data_623; // word name
		struct {
			uint32_t hist_r_data_623 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_624 14'h0C38 */
	union {
		uint32_t fpga_histogram_r_data_624; // word name
		struct {
			uint32_t hist_r_data_624 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_625 14'h0C3C */
	union {
		uint32_t fpga_histogram_r_data_625; // word name
		struct {
			uint32_t hist_r_data_625 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_626 14'h0C40 */
	union {
		uint32_t fpga_histogram_r_data_626; // word name
		struct {
			uint32_t hist_r_data_626 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_627 14'h0C44 */
	union {
		uint32_t fpga_histogram_r_data_627; // word name
		struct {
			uint32_t hist_r_data_627 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_628 14'h0C48 */
	union {
		uint32_t fpga_histogram_r_data_628; // word name
		struct {
			uint32_t hist_r_data_628 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_629 14'h0C4C */
	union {
		uint32_t fpga_histogram_r_data_629; // word name
		struct {
			uint32_t hist_r_data_629 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_630 14'h0C50 */
	union {
		uint32_t fpga_histogram_r_data_630; // word name
		struct {
			uint32_t hist_r_data_630 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_631 14'h0C54 */
	union {
		uint32_t fpga_histogram_r_data_631; // word name
		struct {
			uint32_t hist_r_data_631 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_632 14'h0C58 */
	union {
		uint32_t fpga_histogram_r_data_632; // word name
		struct {
			uint32_t hist_r_data_632 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_633 14'h0C5C */
	union {
		uint32_t fpga_histogram_r_data_633; // word name
		struct {
			uint32_t hist_r_data_633 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_634 14'h0C60 */
	union {
		uint32_t fpga_histogram_r_data_634; // word name
		struct {
			uint32_t hist_r_data_634 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_635 14'h0C64 */
	union {
		uint32_t fpga_histogram_r_data_635; // word name
		struct {
			uint32_t hist_r_data_635 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_636 14'h0C68 */
	union {
		uint32_t fpga_histogram_r_data_636; // word name
		struct {
			uint32_t hist_r_data_636 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_637 14'h0C6C */
	union {
		uint32_t fpga_histogram_r_data_637; // word name
		struct {
			uint32_t hist_r_data_637 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_638 14'h0C70 */
	union {
		uint32_t fpga_histogram_r_data_638; // word name
		struct {
			uint32_t hist_r_data_638 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_639 14'h0C74 */
	union {
		uint32_t fpga_histogram_r_data_639; // word name
		struct {
			uint32_t hist_r_data_639 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_640 14'h0C78 */
	union {
		uint32_t fpga_histogram_r_data_640; // word name
		struct {
			uint32_t hist_r_data_640 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_641 14'h0C7C */
	union {
		uint32_t fpga_histogram_r_data_641; // word name
		struct {
			uint32_t hist_r_data_641 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_642 14'h0C80 */
	union {
		uint32_t fpga_histogram_r_data_642; // word name
		struct {
			uint32_t hist_r_data_642 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_643 14'h0C84 */
	union {
		uint32_t fpga_histogram_r_data_643; // word name
		struct {
			uint32_t hist_r_data_643 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_644 14'h0C88 */
	union {
		uint32_t fpga_histogram_r_data_644; // word name
		struct {
			uint32_t hist_r_data_644 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_645 14'h0C8C */
	union {
		uint32_t fpga_histogram_r_data_645; // word name
		struct {
			uint32_t hist_r_data_645 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_646 14'h0C90 */
	union {
		uint32_t fpga_histogram_r_data_646; // word name
		struct {
			uint32_t hist_r_data_646 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_647 14'h0C94 */
	union {
		uint32_t fpga_histogram_r_data_647; // word name
		struct {
			uint32_t hist_r_data_647 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_648 14'h0C98 */
	union {
		uint32_t fpga_histogram_r_data_648; // word name
		struct {
			uint32_t hist_r_data_648 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_649 14'h0C9C */
	union {
		uint32_t fpga_histogram_r_data_649; // word name
		struct {
			uint32_t hist_r_data_649 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_650 14'h0CA0 */
	union {
		uint32_t fpga_histogram_r_data_650; // word name
		struct {
			uint32_t hist_r_data_650 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_651 14'h0CA4 */
	union {
		uint32_t fpga_histogram_r_data_651; // word name
		struct {
			uint32_t hist_r_data_651 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_652 14'h0CA8 */
	union {
		uint32_t fpga_histogram_r_data_652; // word name
		struct {
			uint32_t hist_r_data_652 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_653 14'h0CAC */
	union {
		uint32_t fpga_histogram_r_data_653; // word name
		struct {
			uint32_t hist_r_data_653 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_654 14'h0CB0 */
	union {
		uint32_t fpga_histogram_r_data_654; // word name
		struct {
			uint32_t hist_r_data_654 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_655 14'h0CB4 */
	union {
		uint32_t fpga_histogram_r_data_655; // word name
		struct {
			uint32_t hist_r_data_655 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_656 14'h0CB8 */
	union {
		uint32_t fpga_histogram_r_data_656; // word name
		struct {
			uint32_t hist_r_data_656 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_657 14'h0CBC */
	union {
		uint32_t fpga_histogram_r_data_657; // word name
		struct {
			uint32_t hist_r_data_657 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_658 14'h0CC0 */
	union {
		uint32_t fpga_histogram_r_data_658; // word name
		struct {
			uint32_t hist_r_data_658 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_659 14'h0CC4 */
	union {
		uint32_t fpga_histogram_r_data_659; // word name
		struct {
			uint32_t hist_r_data_659 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_660 14'h0CC8 */
	union {
		uint32_t fpga_histogram_r_data_660; // word name
		struct {
			uint32_t hist_r_data_660 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_661 14'h0CCC */
	union {
		uint32_t fpga_histogram_r_data_661; // word name
		struct {
			uint32_t hist_r_data_661 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_662 14'h0CD0 */
	union {
		uint32_t fpga_histogram_r_data_662; // word name
		struct {
			uint32_t hist_r_data_662 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_663 14'h0CD4 */
	union {
		uint32_t fpga_histogram_r_data_663; // word name
		struct {
			uint32_t hist_r_data_663 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_664 14'h0CD8 */
	union {
		uint32_t fpga_histogram_r_data_664; // word name
		struct {
			uint32_t hist_r_data_664 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_665 14'h0CDC */
	union {
		uint32_t fpga_histogram_r_data_665; // word name
		struct {
			uint32_t hist_r_data_665 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_666 14'h0CE0 */
	union {
		uint32_t fpga_histogram_r_data_666; // word name
		struct {
			uint32_t hist_r_data_666 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_667 14'h0CE4 */
	union {
		uint32_t fpga_histogram_r_data_667; // word name
		struct {
			uint32_t hist_r_data_667 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_668 14'h0CE8 */
	union {
		uint32_t fpga_histogram_r_data_668; // word name
		struct {
			uint32_t hist_r_data_668 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_669 14'h0CEC */
	union {
		uint32_t fpga_histogram_r_data_669; // word name
		struct {
			uint32_t hist_r_data_669 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_670 14'h0CF0 */
	union {
		uint32_t fpga_histogram_r_data_670; // word name
		struct {
			uint32_t hist_r_data_670 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_671 14'h0CF4 */
	union {
		uint32_t fpga_histogram_r_data_671; // word name
		struct {
			uint32_t hist_r_data_671 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_672 14'h0CF8 */
	union {
		uint32_t fpga_histogram_r_data_672; // word name
		struct {
			uint32_t hist_r_data_672 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_673 14'h0CFC */
	union {
		uint32_t fpga_histogram_r_data_673; // word name
		struct {
			uint32_t hist_r_data_673 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_674 14'h0D00 */
	union {
		uint32_t fpga_histogram_r_data_674; // word name
		struct {
			uint32_t hist_r_data_674 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_675 14'h0D04 */
	union {
		uint32_t fpga_histogram_r_data_675; // word name
		struct {
			uint32_t hist_r_data_675 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_676 14'h0D08 */
	union {
		uint32_t fpga_histogram_r_data_676; // word name
		struct {
			uint32_t hist_r_data_676 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_677 14'h0D0C */
	union {
		uint32_t fpga_histogram_r_data_677; // word name
		struct {
			uint32_t hist_r_data_677 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_678 14'h0D10 */
	union {
		uint32_t fpga_histogram_r_data_678; // word name
		struct {
			uint32_t hist_r_data_678 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_679 14'h0D14 */
	union {
		uint32_t fpga_histogram_r_data_679; // word name
		struct {
			uint32_t hist_r_data_679 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_680 14'h0D18 */
	union {
		uint32_t fpga_histogram_r_data_680; // word name
		struct {
			uint32_t hist_r_data_680 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_681 14'h0D1C */
	union {
		uint32_t fpga_histogram_r_data_681; // word name
		struct {
			uint32_t hist_r_data_681 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_682 14'h0D20 */
	union {
		uint32_t fpga_histogram_r_data_682; // word name
		struct {
			uint32_t hist_r_data_682 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_683 14'h0D24 */
	union {
		uint32_t fpga_histogram_r_data_683; // word name
		struct {
			uint32_t hist_r_data_683 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_684 14'h0D28 */
	union {
		uint32_t fpga_histogram_r_data_684; // word name
		struct {
			uint32_t hist_r_data_684 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_685 14'h0D2C */
	union {
		uint32_t fpga_histogram_r_data_685; // word name
		struct {
			uint32_t hist_r_data_685 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_686 14'h0D30 */
	union {
		uint32_t fpga_histogram_r_data_686; // word name
		struct {
			uint32_t hist_r_data_686 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_687 14'h0D34 */
	union {
		uint32_t fpga_histogram_r_data_687; // word name
		struct {
			uint32_t hist_r_data_687 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_688 14'h0D38 */
	union {
		uint32_t fpga_histogram_r_data_688; // word name
		struct {
			uint32_t hist_r_data_688 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_689 14'h0D3C */
	union {
		uint32_t fpga_histogram_r_data_689; // word name
		struct {
			uint32_t hist_r_data_689 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_690 14'h0D40 */
	union {
		uint32_t fpga_histogram_r_data_690; // word name
		struct {
			uint32_t hist_r_data_690 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_691 14'h0D44 */
	union {
		uint32_t fpga_histogram_r_data_691; // word name
		struct {
			uint32_t hist_r_data_691 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_692 14'h0D48 */
	union {
		uint32_t fpga_histogram_r_data_692; // word name
		struct {
			uint32_t hist_r_data_692 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_693 14'h0D4C */
	union {
		uint32_t fpga_histogram_r_data_693; // word name
		struct {
			uint32_t hist_r_data_693 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_694 14'h0D50 */
	union {
		uint32_t fpga_histogram_r_data_694; // word name
		struct {
			uint32_t hist_r_data_694 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_695 14'h0D54 */
	union {
		uint32_t fpga_histogram_r_data_695; // word name
		struct {
			uint32_t hist_r_data_695 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_696 14'h0D58 */
	union {
		uint32_t fpga_histogram_r_data_696; // word name
		struct {
			uint32_t hist_r_data_696 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_697 14'h0D5C */
	union {
		uint32_t fpga_histogram_r_data_697; // word name
		struct {
			uint32_t hist_r_data_697 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_698 14'h0D60 */
	union {
		uint32_t fpga_histogram_r_data_698; // word name
		struct {
			uint32_t hist_r_data_698 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_699 14'h0D64 */
	union {
		uint32_t fpga_histogram_r_data_699; // word name
		struct {
			uint32_t hist_r_data_699 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_700 14'h0D68 */
	union {
		uint32_t fpga_histogram_r_data_700; // word name
		struct {
			uint32_t hist_r_data_700 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_701 14'h0D6C */
	union {
		uint32_t fpga_histogram_r_data_701; // word name
		struct {
			uint32_t hist_r_data_701 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_702 14'h0D70 */
	union {
		uint32_t fpga_histogram_r_data_702; // word name
		struct {
			uint32_t hist_r_data_702 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_703 14'h0D74 */
	union {
		uint32_t fpga_histogram_r_data_703; // word name
		struct {
			uint32_t hist_r_data_703 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_704 14'h0D78 */
	union {
		uint32_t fpga_histogram_r_data_704; // word name
		struct {
			uint32_t hist_r_data_704 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_705 14'h0D7C */
	union {
		uint32_t fpga_histogram_r_data_705; // word name
		struct {
			uint32_t hist_r_data_705 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_706 14'h0D80 */
	union {
		uint32_t fpga_histogram_r_data_706; // word name
		struct {
			uint32_t hist_r_data_706 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_707 14'h0D84 */
	union {
		uint32_t fpga_histogram_r_data_707; // word name
		struct {
			uint32_t hist_r_data_707 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_708 14'h0D88 */
	union {
		uint32_t fpga_histogram_r_data_708; // word name
		struct {
			uint32_t hist_r_data_708 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_709 14'h0D8C */
	union {
		uint32_t fpga_histogram_r_data_709; // word name
		struct {
			uint32_t hist_r_data_709 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_710 14'h0D90 */
	union {
		uint32_t fpga_histogram_r_data_710; // word name
		struct {
			uint32_t hist_r_data_710 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_711 14'h0D94 */
	union {
		uint32_t fpga_histogram_r_data_711; // word name
		struct {
			uint32_t hist_r_data_711 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_712 14'h0D98 */
	union {
		uint32_t fpga_histogram_r_data_712; // word name
		struct {
			uint32_t hist_r_data_712 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_713 14'h0D9C */
	union {
		uint32_t fpga_histogram_r_data_713; // word name
		struct {
			uint32_t hist_r_data_713 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_714 14'h0DA0 */
	union {
		uint32_t fpga_histogram_r_data_714; // word name
		struct {
			uint32_t hist_r_data_714 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_715 14'h0DA4 */
	union {
		uint32_t fpga_histogram_r_data_715; // word name
		struct {
			uint32_t hist_r_data_715 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_716 14'h0DA8 */
	union {
		uint32_t fpga_histogram_r_data_716; // word name
		struct {
			uint32_t hist_r_data_716 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_717 14'h0DAC */
	union {
		uint32_t fpga_histogram_r_data_717; // word name
		struct {
			uint32_t hist_r_data_717 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_718 14'h0DB0 */
	union {
		uint32_t fpga_histogram_r_data_718; // word name
		struct {
			uint32_t hist_r_data_718 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_719 14'h0DB4 */
	union {
		uint32_t fpga_histogram_r_data_719; // word name
		struct {
			uint32_t hist_r_data_719 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_720 14'h0DB8 */
	union {
		uint32_t fpga_histogram_r_data_720; // word name
		struct {
			uint32_t hist_r_data_720 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_721 14'h0DBC */
	union {
		uint32_t fpga_histogram_r_data_721; // word name
		struct {
			uint32_t hist_r_data_721 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_722 14'h0DC0 */
	union {
		uint32_t fpga_histogram_r_data_722; // word name
		struct {
			uint32_t hist_r_data_722 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_723 14'h0DC4 */
	union {
		uint32_t fpga_histogram_r_data_723; // word name
		struct {
			uint32_t hist_r_data_723 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_724 14'h0DC8 */
	union {
		uint32_t fpga_histogram_r_data_724; // word name
		struct {
			uint32_t hist_r_data_724 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_725 14'h0DCC */
	union {
		uint32_t fpga_histogram_r_data_725; // word name
		struct {
			uint32_t hist_r_data_725 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_726 14'h0DD0 */
	union {
		uint32_t fpga_histogram_r_data_726; // word name
		struct {
			uint32_t hist_r_data_726 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_727 14'h0DD4 */
	union {
		uint32_t fpga_histogram_r_data_727; // word name
		struct {
			uint32_t hist_r_data_727 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_728 14'h0DD8 */
	union {
		uint32_t fpga_histogram_r_data_728; // word name
		struct {
			uint32_t hist_r_data_728 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_729 14'h0DDC */
	union {
		uint32_t fpga_histogram_r_data_729; // word name
		struct {
			uint32_t hist_r_data_729 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_730 14'h0DE0 */
	union {
		uint32_t fpga_histogram_r_data_730; // word name
		struct {
			uint32_t hist_r_data_730 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_731 14'h0DE4 */
	union {
		uint32_t fpga_histogram_r_data_731; // word name
		struct {
			uint32_t hist_r_data_731 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_732 14'h0DE8 */
	union {
		uint32_t fpga_histogram_r_data_732; // word name
		struct {
			uint32_t hist_r_data_732 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_733 14'h0DEC */
	union {
		uint32_t fpga_histogram_r_data_733; // word name
		struct {
			uint32_t hist_r_data_733 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_734 14'h0DF0 */
	union {
		uint32_t fpga_histogram_r_data_734; // word name
		struct {
			uint32_t hist_r_data_734 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_735 14'h0DF4 */
	union {
		uint32_t fpga_histogram_r_data_735; // word name
		struct {
			uint32_t hist_r_data_735 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_736 14'h0DF8 */
	union {
		uint32_t fpga_histogram_r_data_736; // word name
		struct {
			uint32_t hist_r_data_736 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_737 14'h0DFC */
	union {
		uint32_t fpga_histogram_r_data_737; // word name
		struct {
			uint32_t hist_r_data_737 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_738 14'h0E00 */
	union {
		uint32_t fpga_histogram_r_data_738; // word name
		struct {
			uint32_t hist_r_data_738 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_739 14'h0E04 */
	union {
		uint32_t fpga_histogram_r_data_739; // word name
		struct {
			uint32_t hist_r_data_739 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_740 14'h0E08 */
	union {
		uint32_t fpga_histogram_r_data_740; // word name
		struct {
			uint32_t hist_r_data_740 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_741 14'h0E0C */
	union {
		uint32_t fpga_histogram_r_data_741; // word name
		struct {
			uint32_t hist_r_data_741 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_742 14'h0E10 */
	union {
		uint32_t fpga_histogram_r_data_742; // word name
		struct {
			uint32_t hist_r_data_742 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_743 14'h0E14 */
	union {
		uint32_t fpga_histogram_r_data_743; // word name
		struct {
			uint32_t hist_r_data_743 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_744 14'h0E18 */
	union {
		uint32_t fpga_histogram_r_data_744; // word name
		struct {
			uint32_t hist_r_data_744 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_745 14'h0E1C */
	union {
		uint32_t fpga_histogram_r_data_745; // word name
		struct {
			uint32_t hist_r_data_745 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_746 14'h0E20 */
	union {
		uint32_t fpga_histogram_r_data_746; // word name
		struct {
			uint32_t hist_r_data_746 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_747 14'h0E24 */
	union {
		uint32_t fpga_histogram_r_data_747; // word name
		struct {
			uint32_t hist_r_data_747 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_748 14'h0E28 */
	union {
		uint32_t fpga_histogram_r_data_748; // word name
		struct {
			uint32_t hist_r_data_748 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_749 14'h0E2C */
	union {
		uint32_t fpga_histogram_r_data_749; // word name
		struct {
			uint32_t hist_r_data_749 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_750 14'h0E30 */
	union {
		uint32_t fpga_histogram_r_data_750; // word name
		struct {
			uint32_t hist_r_data_750 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_751 14'h0E34 */
	union {
		uint32_t fpga_histogram_r_data_751; // word name
		struct {
			uint32_t hist_r_data_751 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_752 14'h0E38 */
	union {
		uint32_t fpga_histogram_r_data_752; // word name
		struct {
			uint32_t hist_r_data_752 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_753 14'h0E3C */
	union {
		uint32_t fpga_histogram_r_data_753; // word name
		struct {
			uint32_t hist_r_data_753 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_754 14'h0E40 */
	union {
		uint32_t fpga_histogram_r_data_754; // word name
		struct {
			uint32_t hist_r_data_754 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_755 14'h0E44 */
	union {
		uint32_t fpga_histogram_r_data_755; // word name
		struct {
			uint32_t hist_r_data_755 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_756 14'h0E48 */
	union {
		uint32_t fpga_histogram_r_data_756; // word name
		struct {
			uint32_t hist_r_data_756 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_757 14'h0E4C */
	union {
		uint32_t fpga_histogram_r_data_757; // word name
		struct {
			uint32_t hist_r_data_757 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_758 14'h0E50 */
	union {
		uint32_t fpga_histogram_r_data_758; // word name
		struct {
			uint32_t hist_r_data_758 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_759 14'h0E54 */
	union {
		uint32_t fpga_histogram_r_data_759; // word name
		struct {
			uint32_t hist_r_data_759 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_760 14'h0E58 */
	union {
		uint32_t fpga_histogram_r_data_760; // word name
		struct {
			uint32_t hist_r_data_760 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_761 14'h0E5C */
	union {
		uint32_t fpga_histogram_r_data_761; // word name
		struct {
			uint32_t hist_r_data_761 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_762 14'h0E60 */
	union {
		uint32_t fpga_histogram_r_data_762; // word name
		struct {
			uint32_t hist_r_data_762 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_763 14'h0E64 */
	union {
		uint32_t fpga_histogram_r_data_763; // word name
		struct {
			uint32_t hist_r_data_763 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_764 14'h0E68 */
	union {
		uint32_t fpga_histogram_r_data_764; // word name
		struct {
			uint32_t hist_r_data_764 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_765 14'h0E6C */
	union {
		uint32_t fpga_histogram_r_data_765; // word name
		struct {
			uint32_t hist_r_data_765 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_766 14'h0E70 */
	union {
		uint32_t fpga_histogram_r_data_766; // word name
		struct {
			uint32_t hist_r_data_766 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_767 14'h0E74 */
	union {
		uint32_t fpga_histogram_r_data_767; // word name
		struct {
			uint32_t hist_r_data_767 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_768 14'h0E78 */
	union {
		uint32_t fpga_histogram_r_data_768; // word name
		struct {
			uint32_t hist_r_data_768 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_769 14'h0E7C */
	union {
		uint32_t fpga_histogram_r_data_769; // word name
		struct {
			uint32_t hist_r_data_769 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_770 14'h0E80 */
	union {
		uint32_t fpga_histogram_r_data_770; // word name
		struct {
			uint32_t hist_r_data_770 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_771 14'h0E84 */
	union {
		uint32_t fpga_histogram_r_data_771; // word name
		struct {
			uint32_t hist_r_data_771 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_772 14'h0E88 */
	union {
		uint32_t fpga_histogram_r_data_772; // word name
		struct {
			uint32_t hist_r_data_772 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_773 14'h0E8C */
	union {
		uint32_t fpga_histogram_r_data_773; // word name
		struct {
			uint32_t hist_r_data_773 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_774 14'h0E90 */
	union {
		uint32_t fpga_histogram_r_data_774; // word name
		struct {
			uint32_t hist_r_data_774 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_775 14'h0E94 */
	union {
		uint32_t fpga_histogram_r_data_775; // word name
		struct {
			uint32_t hist_r_data_775 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_776 14'h0E98 */
	union {
		uint32_t fpga_histogram_r_data_776; // word name
		struct {
			uint32_t hist_r_data_776 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_777 14'h0E9C */
	union {
		uint32_t fpga_histogram_r_data_777; // word name
		struct {
			uint32_t hist_r_data_777 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_778 14'h0EA0 */
	union {
		uint32_t fpga_histogram_r_data_778; // word name
		struct {
			uint32_t hist_r_data_778 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_779 14'h0EA4 */
	union {
		uint32_t fpga_histogram_r_data_779; // word name
		struct {
			uint32_t hist_r_data_779 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_780 14'h0EA8 */
	union {
		uint32_t fpga_histogram_r_data_780; // word name
		struct {
			uint32_t hist_r_data_780 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_781 14'h0EAC */
	union {
		uint32_t fpga_histogram_r_data_781; // word name
		struct {
			uint32_t hist_r_data_781 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_782 14'h0EB0 */
	union {
		uint32_t fpga_histogram_r_data_782; // word name
		struct {
			uint32_t hist_r_data_782 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_783 14'h0EB4 */
	union {
		uint32_t fpga_histogram_r_data_783; // word name
		struct {
			uint32_t hist_r_data_783 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_784 14'h0EB8 */
	union {
		uint32_t fpga_histogram_r_data_784; // word name
		struct {
			uint32_t hist_r_data_784 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_785 14'h0EBC */
	union {
		uint32_t fpga_histogram_r_data_785; // word name
		struct {
			uint32_t hist_r_data_785 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_786 14'h0EC0 */
	union {
		uint32_t fpga_histogram_r_data_786; // word name
		struct {
			uint32_t hist_r_data_786 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_787 14'h0EC4 */
	union {
		uint32_t fpga_histogram_r_data_787; // word name
		struct {
			uint32_t hist_r_data_787 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_788 14'h0EC8 */
	union {
		uint32_t fpga_histogram_r_data_788; // word name
		struct {
			uint32_t hist_r_data_788 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_789 14'h0ECC */
	union {
		uint32_t fpga_histogram_r_data_789; // word name
		struct {
			uint32_t hist_r_data_789 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_790 14'h0ED0 */
	union {
		uint32_t fpga_histogram_r_data_790; // word name
		struct {
			uint32_t hist_r_data_790 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_791 14'h0ED4 */
	union {
		uint32_t fpga_histogram_r_data_791; // word name
		struct {
			uint32_t hist_r_data_791 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_792 14'h0ED8 */
	union {
		uint32_t fpga_histogram_r_data_792; // word name
		struct {
			uint32_t hist_r_data_792 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_793 14'h0EDC */
	union {
		uint32_t fpga_histogram_r_data_793; // word name
		struct {
			uint32_t hist_r_data_793 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_794 14'h0EE0 */
	union {
		uint32_t fpga_histogram_r_data_794; // word name
		struct {
			uint32_t hist_r_data_794 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_795 14'h0EE4 */
	union {
		uint32_t fpga_histogram_r_data_795; // word name
		struct {
			uint32_t hist_r_data_795 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_796 14'h0EE8 */
	union {
		uint32_t fpga_histogram_r_data_796; // word name
		struct {
			uint32_t hist_r_data_796 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_797 14'h0EEC */
	union {
		uint32_t fpga_histogram_r_data_797; // word name
		struct {
			uint32_t hist_r_data_797 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_798 14'h0EF0 */
	union {
		uint32_t fpga_histogram_r_data_798; // word name
		struct {
			uint32_t hist_r_data_798 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_799 14'h0EF4 */
	union {
		uint32_t fpga_histogram_r_data_799; // word name
		struct {
			uint32_t hist_r_data_799 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_800 14'h0EF8 */
	union {
		uint32_t fpga_histogram_r_data_800; // word name
		struct {
			uint32_t hist_r_data_800 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_801 14'h0EFC */
	union {
		uint32_t fpga_histogram_r_data_801; // word name
		struct {
			uint32_t hist_r_data_801 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_802 14'h0F00 */
	union {
		uint32_t fpga_histogram_r_data_802; // word name
		struct {
			uint32_t hist_r_data_802 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_803 14'h0F04 */
	union {
		uint32_t fpga_histogram_r_data_803; // word name
		struct {
			uint32_t hist_r_data_803 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_804 14'h0F08 */
	union {
		uint32_t fpga_histogram_r_data_804; // word name
		struct {
			uint32_t hist_r_data_804 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_805 14'h0F0C */
	union {
		uint32_t fpga_histogram_r_data_805; // word name
		struct {
			uint32_t hist_r_data_805 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_806 14'h0F10 */
	union {
		uint32_t fpga_histogram_r_data_806; // word name
		struct {
			uint32_t hist_r_data_806 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_807 14'h0F14 */
	union {
		uint32_t fpga_histogram_r_data_807; // word name
		struct {
			uint32_t hist_r_data_807 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_808 14'h0F18 */
	union {
		uint32_t fpga_histogram_r_data_808; // word name
		struct {
			uint32_t hist_r_data_808 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_809 14'h0F1C */
	union {
		uint32_t fpga_histogram_r_data_809; // word name
		struct {
			uint32_t hist_r_data_809 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_810 14'h0F20 */
	union {
		uint32_t fpga_histogram_r_data_810; // word name
		struct {
			uint32_t hist_r_data_810 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_811 14'h0F24 */
	union {
		uint32_t fpga_histogram_r_data_811; // word name
		struct {
			uint32_t hist_r_data_811 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_812 14'h0F28 */
	union {
		uint32_t fpga_histogram_r_data_812; // word name
		struct {
			uint32_t hist_r_data_812 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_813 14'h0F2C */
	union {
		uint32_t fpga_histogram_r_data_813; // word name
		struct {
			uint32_t hist_r_data_813 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_814 14'h0F30 */
	union {
		uint32_t fpga_histogram_r_data_814; // word name
		struct {
			uint32_t hist_r_data_814 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_815 14'h0F34 */
	union {
		uint32_t fpga_histogram_r_data_815; // word name
		struct {
			uint32_t hist_r_data_815 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_816 14'h0F38 */
	union {
		uint32_t fpga_histogram_r_data_816; // word name
		struct {
			uint32_t hist_r_data_816 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_817 14'h0F3C */
	union {
		uint32_t fpga_histogram_r_data_817; // word name
		struct {
			uint32_t hist_r_data_817 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_818 14'h0F40 */
	union {
		uint32_t fpga_histogram_r_data_818; // word name
		struct {
			uint32_t hist_r_data_818 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_819 14'h0F44 */
	union {
		uint32_t fpga_histogram_r_data_819; // word name
		struct {
			uint32_t hist_r_data_819 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_820 14'h0F48 */
	union {
		uint32_t fpga_histogram_r_data_820; // word name
		struct {
			uint32_t hist_r_data_820 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_821 14'h0F4C */
	union {
		uint32_t fpga_histogram_r_data_821; // word name
		struct {
			uint32_t hist_r_data_821 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_822 14'h0F50 */
	union {
		uint32_t fpga_histogram_r_data_822; // word name
		struct {
			uint32_t hist_r_data_822 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_823 14'h0F54 */
	union {
		uint32_t fpga_histogram_r_data_823; // word name
		struct {
			uint32_t hist_r_data_823 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_824 14'h0F58 */
	union {
		uint32_t fpga_histogram_r_data_824; // word name
		struct {
			uint32_t hist_r_data_824 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_825 14'h0F5C */
	union {
		uint32_t fpga_histogram_r_data_825; // word name
		struct {
			uint32_t hist_r_data_825 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_826 14'h0F60 */
	union {
		uint32_t fpga_histogram_r_data_826; // word name
		struct {
			uint32_t hist_r_data_826 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_827 14'h0F64 */
	union {
		uint32_t fpga_histogram_r_data_827; // word name
		struct {
			uint32_t hist_r_data_827 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_828 14'h0F68 */
	union {
		uint32_t fpga_histogram_r_data_828; // word name
		struct {
			uint32_t hist_r_data_828 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_829 14'h0F6C */
	union {
		uint32_t fpga_histogram_r_data_829; // word name
		struct {
			uint32_t hist_r_data_829 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_830 14'h0F70 */
	union {
		uint32_t fpga_histogram_r_data_830; // word name
		struct {
			uint32_t hist_r_data_830 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_831 14'h0F74 */
	union {
		uint32_t fpga_histogram_r_data_831; // word name
		struct {
			uint32_t hist_r_data_831 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_832 14'h0F78 */
	union {
		uint32_t fpga_histogram_r_data_832; // word name
		struct {
			uint32_t hist_r_data_832 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_833 14'h0F7C */
	union {
		uint32_t fpga_histogram_r_data_833; // word name
		struct {
			uint32_t hist_r_data_833 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_834 14'h0F80 */
	union {
		uint32_t fpga_histogram_r_data_834; // word name
		struct {
			uint32_t hist_r_data_834 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_835 14'h0F84 */
	union {
		uint32_t fpga_histogram_r_data_835; // word name
		struct {
			uint32_t hist_r_data_835 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_836 14'h0F88 */
	union {
		uint32_t fpga_histogram_r_data_836; // word name
		struct {
			uint32_t hist_r_data_836 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_837 14'h0F8C */
	union {
		uint32_t fpga_histogram_r_data_837; // word name
		struct {
			uint32_t hist_r_data_837 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_838 14'h0F90 */
	union {
		uint32_t fpga_histogram_r_data_838; // word name
		struct {
			uint32_t hist_r_data_838 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_839 14'h0F94 */
	union {
		uint32_t fpga_histogram_r_data_839; // word name
		struct {
			uint32_t hist_r_data_839 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_840 14'h0F98 */
	union {
		uint32_t fpga_histogram_r_data_840; // word name
		struct {
			uint32_t hist_r_data_840 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_841 14'h0F9C */
	union {
		uint32_t fpga_histogram_r_data_841; // word name
		struct {
			uint32_t hist_r_data_841 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_842 14'h0FA0 */
	union {
		uint32_t fpga_histogram_r_data_842; // word name
		struct {
			uint32_t hist_r_data_842 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_843 14'h0FA4 */
	union {
		uint32_t fpga_histogram_r_data_843; // word name
		struct {
			uint32_t hist_r_data_843 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_844 14'h0FA8 */
	union {
		uint32_t fpga_histogram_r_data_844; // word name
		struct {
			uint32_t hist_r_data_844 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_845 14'h0FAC */
	union {
		uint32_t fpga_histogram_r_data_845; // word name
		struct {
			uint32_t hist_r_data_845 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_846 14'h0FB0 */
	union {
		uint32_t fpga_histogram_r_data_846; // word name
		struct {
			uint32_t hist_r_data_846 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_847 14'h0FB4 */
	union {
		uint32_t fpga_histogram_r_data_847; // word name
		struct {
			uint32_t hist_r_data_847 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_848 14'h0FB8 */
	union {
		uint32_t fpga_histogram_r_data_848; // word name
		struct {
			uint32_t hist_r_data_848 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_849 14'h0FBC */
	union {
		uint32_t fpga_histogram_r_data_849; // word name
		struct {
			uint32_t hist_r_data_849 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_850 14'h0FC0 */
	union {
		uint32_t fpga_histogram_r_data_850; // word name
		struct {
			uint32_t hist_r_data_850 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_851 14'h0FC4 */
	union {
		uint32_t fpga_histogram_r_data_851; // word name
		struct {
			uint32_t hist_r_data_851 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_852 14'h0FC8 */
	union {
		uint32_t fpga_histogram_r_data_852; // word name
		struct {
			uint32_t hist_r_data_852 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_853 14'h0FCC */
	union {
		uint32_t fpga_histogram_r_data_853; // word name
		struct {
			uint32_t hist_r_data_853 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_854 14'h0FD0 */
	union {
		uint32_t fpga_histogram_r_data_854; // word name
		struct {
			uint32_t hist_r_data_854 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_855 14'h0FD4 */
	union {
		uint32_t fpga_histogram_r_data_855; // word name
		struct {
			uint32_t hist_r_data_855 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_856 14'h0FD8 */
	union {
		uint32_t fpga_histogram_r_data_856; // word name
		struct {
			uint32_t hist_r_data_856 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_857 14'h0FDC */
	union {
		uint32_t fpga_histogram_r_data_857; // word name
		struct {
			uint32_t hist_r_data_857 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_858 14'h0FE0 */
	union {
		uint32_t fpga_histogram_r_data_858; // word name
		struct {
			uint32_t hist_r_data_858 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_859 14'h0FE4 */
	union {
		uint32_t fpga_histogram_r_data_859; // word name
		struct {
			uint32_t hist_r_data_859 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_860 14'h0FE8 */
	union {
		uint32_t fpga_histogram_r_data_860; // word name
		struct {
			uint32_t hist_r_data_860 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_861 14'h0FEC */
	union {
		uint32_t fpga_histogram_r_data_861; // word name
		struct {
			uint32_t hist_r_data_861 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_862 14'h0FF0 */
	union {
		uint32_t fpga_histogram_r_data_862; // word name
		struct {
			uint32_t hist_r_data_862 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_863 14'h0FF4 */
	union {
		uint32_t fpga_histogram_r_data_863; // word name
		struct {
			uint32_t hist_r_data_863 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_864 14'h0FF8 */
	union {
		uint32_t fpga_histogram_r_data_864; // word name
		struct {
			uint32_t hist_r_data_864 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_865 14'h0FFC */
	union {
		uint32_t fpga_histogram_r_data_865; // word name
		struct {
			uint32_t hist_r_data_865 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_866 14'h1000 */
	union {
		uint32_t fpga_histogram_r_data_866; // word name
		struct {
			uint32_t hist_r_data_866 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_867 14'h1004 */
	union {
		uint32_t fpga_histogram_r_data_867; // word name
		struct {
			uint32_t hist_r_data_867 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_868 14'h1008 */
	union {
		uint32_t fpga_histogram_r_data_868; // word name
		struct {
			uint32_t hist_r_data_868 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_869 14'h100C */
	union {
		uint32_t fpga_histogram_r_data_869; // word name
		struct {
			uint32_t hist_r_data_869 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_870 14'h1010 */
	union {
		uint32_t fpga_histogram_r_data_870; // word name
		struct {
			uint32_t hist_r_data_870 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_871 14'h1014 */
	union {
		uint32_t fpga_histogram_r_data_871; // word name
		struct {
			uint32_t hist_r_data_871 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_872 14'h1018 */
	union {
		uint32_t fpga_histogram_r_data_872; // word name
		struct {
			uint32_t hist_r_data_872 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_873 14'h101C */
	union {
		uint32_t fpga_histogram_r_data_873; // word name
		struct {
			uint32_t hist_r_data_873 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_874 14'h1020 */
	union {
		uint32_t fpga_histogram_r_data_874; // word name
		struct {
			uint32_t hist_r_data_874 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_875 14'h1024 */
	union {
		uint32_t fpga_histogram_r_data_875; // word name
		struct {
			uint32_t hist_r_data_875 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_876 14'h1028 */
	union {
		uint32_t fpga_histogram_r_data_876; // word name
		struct {
			uint32_t hist_r_data_876 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_877 14'h102C */
	union {
		uint32_t fpga_histogram_r_data_877; // word name
		struct {
			uint32_t hist_r_data_877 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_878 14'h1030 */
	union {
		uint32_t fpga_histogram_r_data_878; // word name
		struct {
			uint32_t hist_r_data_878 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_879 14'h1034 */
	union {
		uint32_t fpga_histogram_r_data_879; // word name
		struct {
			uint32_t hist_r_data_879 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_880 14'h1038 */
	union {
		uint32_t fpga_histogram_r_data_880; // word name
		struct {
			uint32_t hist_r_data_880 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_881 14'h103C */
	union {
		uint32_t fpga_histogram_r_data_881; // word name
		struct {
			uint32_t hist_r_data_881 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_882 14'h1040 */
	union {
		uint32_t fpga_histogram_r_data_882; // word name
		struct {
			uint32_t hist_r_data_882 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_883 14'h1044 */
	union {
		uint32_t fpga_histogram_r_data_883; // word name
		struct {
			uint32_t hist_r_data_883 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_884 14'h1048 */
	union {
		uint32_t fpga_histogram_r_data_884; // word name
		struct {
			uint32_t hist_r_data_884 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_885 14'h104C */
	union {
		uint32_t fpga_histogram_r_data_885; // word name
		struct {
			uint32_t hist_r_data_885 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_886 14'h1050 */
	union {
		uint32_t fpga_histogram_r_data_886; // word name
		struct {
			uint32_t hist_r_data_886 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_887 14'h1054 */
	union {
		uint32_t fpga_histogram_r_data_887; // word name
		struct {
			uint32_t hist_r_data_887 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_888 14'h1058 */
	union {
		uint32_t fpga_histogram_r_data_888; // word name
		struct {
			uint32_t hist_r_data_888 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_889 14'h105C */
	union {
		uint32_t fpga_histogram_r_data_889; // word name
		struct {
			uint32_t hist_r_data_889 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_890 14'h1060 */
	union {
		uint32_t fpga_histogram_r_data_890; // word name
		struct {
			uint32_t hist_r_data_890 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_891 14'h1064 */
	union {
		uint32_t fpga_histogram_r_data_891; // word name
		struct {
			uint32_t hist_r_data_891 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_892 14'h1068 */
	union {
		uint32_t fpga_histogram_r_data_892; // word name
		struct {
			uint32_t hist_r_data_892 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_893 14'h106C */
	union {
		uint32_t fpga_histogram_r_data_893; // word name
		struct {
			uint32_t hist_r_data_893 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_894 14'h1070 */
	union {
		uint32_t fpga_histogram_r_data_894; // word name
		struct {
			uint32_t hist_r_data_894 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_895 14'h1074 */
	union {
		uint32_t fpga_histogram_r_data_895; // word name
		struct {
			uint32_t hist_r_data_895 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_896 14'h1078 */
	union {
		uint32_t fpga_histogram_r_data_896; // word name
		struct {
			uint32_t hist_r_data_896 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_897 14'h107C */
	union {
		uint32_t fpga_histogram_r_data_897; // word name
		struct {
			uint32_t hist_r_data_897 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_898 14'h1080 */
	union {
		uint32_t fpga_histogram_r_data_898; // word name
		struct {
			uint32_t hist_r_data_898 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_899 14'h1084 */
	union {
		uint32_t fpga_histogram_r_data_899; // word name
		struct {
			uint32_t hist_r_data_899 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_900 14'h1088 */
	union {
		uint32_t fpga_histogram_r_data_900; // word name
		struct {
			uint32_t hist_r_data_900 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_901 14'h108C */
	union {
		uint32_t fpga_histogram_r_data_901; // word name
		struct {
			uint32_t hist_r_data_901 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_902 14'h1090 */
	union {
		uint32_t fpga_histogram_r_data_902; // word name
		struct {
			uint32_t hist_r_data_902 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_903 14'h1094 */
	union {
		uint32_t fpga_histogram_r_data_903; // word name
		struct {
			uint32_t hist_r_data_903 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_904 14'h1098 */
	union {
		uint32_t fpga_histogram_r_data_904; // word name
		struct {
			uint32_t hist_r_data_904 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_905 14'h109C */
	union {
		uint32_t fpga_histogram_r_data_905; // word name
		struct {
			uint32_t hist_r_data_905 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_906 14'h10A0 */
	union {
		uint32_t fpga_histogram_r_data_906; // word name
		struct {
			uint32_t hist_r_data_906 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_907 14'h10A4 */
	union {
		uint32_t fpga_histogram_r_data_907; // word name
		struct {
			uint32_t hist_r_data_907 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_908 14'h10A8 */
	union {
		uint32_t fpga_histogram_r_data_908; // word name
		struct {
			uint32_t hist_r_data_908 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_909 14'h10AC */
	union {
		uint32_t fpga_histogram_r_data_909; // word name
		struct {
			uint32_t hist_r_data_909 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_910 14'h10B0 */
	union {
		uint32_t fpga_histogram_r_data_910; // word name
		struct {
			uint32_t hist_r_data_910 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_911 14'h10B4 */
	union {
		uint32_t fpga_histogram_r_data_911; // word name
		struct {
			uint32_t hist_r_data_911 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_912 14'h10B8 */
	union {
		uint32_t fpga_histogram_r_data_912; // word name
		struct {
			uint32_t hist_r_data_912 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_913 14'h10BC */
	union {
		uint32_t fpga_histogram_r_data_913; // word name
		struct {
			uint32_t hist_r_data_913 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_914 14'h10C0 */
	union {
		uint32_t fpga_histogram_r_data_914; // word name
		struct {
			uint32_t hist_r_data_914 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_915 14'h10C4 */
	union {
		uint32_t fpga_histogram_r_data_915; // word name
		struct {
			uint32_t hist_r_data_915 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_916 14'h10C8 */
	union {
		uint32_t fpga_histogram_r_data_916; // word name
		struct {
			uint32_t hist_r_data_916 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_917 14'h10CC */
	union {
		uint32_t fpga_histogram_r_data_917; // word name
		struct {
			uint32_t hist_r_data_917 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_918 14'h10D0 */
	union {
		uint32_t fpga_histogram_r_data_918; // word name
		struct {
			uint32_t hist_r_data_918 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_919 14'h10D4 */
	union {
		uint32_t fpga_histogram_r_data_919; // word name
		struct {
			uint32_t hist_r_data_919 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_920 14'h10D8 */
	union {
		uint32_t fpga_histogram_r_data_920; // word name
		struct {
			uint32_t hist_r_data_920 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_921 14'h10DC */
	union {
		uint32_t fpga_histogram_r_data_921; // word name
		struct {
			uint32_t hist_r_data_921 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_922 14'h10E0 */
	union {
		uint32_t fpga_histogram_r_data_922; // word name
		struct {
			uint32_t hist_r_data_922 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_923 14'h10E4 */
	union {
		uint32_t fpga_histogram_r_data_923; // word name
		struct {
			uint32_t hist_r_data_923 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_924 14'h10E8 */
	union {
		uint32_t fpga_histogram_r_data_924; // word name
		struct {
			uint32_t hist_r_data_924 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_925 14'h10EC */
	union {
		uint32_t fpga_histogram_r_data_925; // word name
		struct {
			uint32_t hist_r_data_925 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_926 14'h10F0 */
	union {
		uint32_t fpga_histogram_r_data_926; // word name
		struct {
			uint32_t hist_r_data_926 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_927 14'h10F4 */
	union {
		uint32_t fpga_histogram_r_data_927; // word name
		struct {
			uint32_t hist_r_data_927 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_928 14'h10F8 */
	union {
		uint32_t fpga_histogram_r_data_928; // word name
		struct {
			uint32_t hist_r_data_928 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_929 14'h10FC */
	union {
		uint32_t fpga_histogram_r_data_929; // word name
		struct {
			uint32_t hist_r_data_929 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_930 14'h1100 */
	union {
		uint32_t fpga_histogram_r_data_930; // word name
		struct {
			uint32_t hist_r_data_930 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_931 14'h1104 */
	union {
		uint32_t fpga_histogram_r_data_931; // word name
		struct {
			uint32_t hist_r_data_931 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_932 14'h1108 */
	union {
		uint32_t fpga_histogram_r_data_932; // word name
		struct {
			uint32_t hist_r_data_932 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_933 14'h110C */
	union {
		uint32_t fpga_histogram_r_data_933; // word name
		struct {
			uint32_t hist_r_data_933 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_934 14'h1110 */
	union {
		uint32_t fpga_histogram_r_data_934; // word name
		struct {
			uint32_t hist_r_data_934 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_935 14'h1114 */
	union {
		uint32_t fpga_histogram_r_data_935; // word name
		struct {
			uint32_t hist_r_data_935 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_936 14'h1118 */
	union {
		uint32_t fpga_histogram_r_data_936; // word name
		struct {
			uint32_t hist_r_data_936 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_937 14'h111C */
	union {
		uint32_t fpga_histogram_r_data_937; // word name
		struct {
			uint32_t hist_r_data_937 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_938 14'h1120 */
	union {
		uint32_t fpga_histogram_r_data_938; // word name
		struct {
			uint32_t hist_r_data_938 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_939 14'h1124 */
	union {
		uint32_t fpga_histogram_r_data_939; // word name
		struct {
			uint32_t hist_r_data_939 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_940 14'h1128 */
	union {
		uint32_t fpga_histogram_r_data_940; // word name
		struct {
			uint32_t hist_r_data_940 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_941 14'h112C */
	union {
		uint32_t fpga_histogram_r_data_941; // word name
		struct {
			uint32_t hist_r_data_941 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_942 14'h1130 */
	union {
		uint32_t fpga_histogram_r_data_942; // word name
		struct {
			uint32_t hist_r_data_942 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_943 14'h1134 */
	union {
		uint32_t fpga_histogram_r_data_943; // word name
		struct {
			uint32_t hist_r_data_943 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_944 14'h1138 */
	union {
		uint32_t fpga_histogram_r_data_944; // word name
		struct {
			uint32_t hist_r_data_944 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_945 14'h113C */
	union {
		uint32_t fpga_histogram_r_data_945; // word name
		struct {
			uint32_t hist_r_data_945 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_946 14'h1140 */
	union {
		uint32_t fpga_histogram_r_data_946; // word name
		struct {
			uint32_t hist_r_data_946 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_947 14'h1144 */
	union {
		uint32_t fpga_histogram_r_data_947; // word name
		struct {
			uint32_t hist_r_data_947 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_948 14'h1148 */
	union {
		uint32_t fpga_histogram_r_data_948; // word name
		struct {
			uint32_t hist_r_data_948 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_949 14'h114C */
	union {
		uint32_t fpga_histogram_r_data_949; // word name
		struct {
			uint32_t hist_r_data_949 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_950 14'h1150 */
	union {
		uint32_t fpga_histogram_r_data_950; // word name
		struct {
			uint32_t hist_r_data_950 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_951 14'h1154 */
	union {
		uint32_t fpga_histogram_r_data_951; // word name
		struct {
			uint32_t hist_r_data_951 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_952 14'h1158 */
	union {
		uint32_t fpga_histogram_r_data_952; // word name
		struct {
			uint32_t hist_r_data_952 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_953 14'h115C */
	union {
		uint32_t fpga_histogram_r_data_953; // word name
		struct {
			uint32_t hist_r_data_953 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_954 14'h1160 */
	union {
		uint32_t fpga_histogram_r_data_954; // word name
		struct {
			uint32_t hist_r_data_954 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_955 14'h1164 */
	union {
		uint32_t fpga_histogram_r_data_955; // word name
		struct {
			uint32_t hist_r_data_955 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_956 14'h1168 */
	union {
		uint32_t fpga_histogram_r_data_956; // word name
		struct {
			uint32_t hist_r_data_956 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_957 14'h116C */
	union {
		uint32_t fpga_histogram_r_data_957; // word name
		struct {
			uint32_t hist_r_data_957 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_958 14'h1170 */
	union {
		uint32_t fpga_histogram_r_data_958; // word name
		struct {
			uint32_t hist_r_data_958 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_959 14'h1174 */
	union {
		uint32_t fpga_histogram_r_data_959; // word name
		struct {
			uint32_t hist_r_data_959 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_960 14'h1178 */
	union {
		uint32_t fpga_histogram_r_data_960; // word name
		struct {
			uint32_t hist_r_data_960 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_961 14'h117C */
	union {
		uint32_t fpga_histogram_r_data_961; // word name
		struct {
			uint32_t hist_r_data_961 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_962 14'h1180 */
	union {
		uint32_t fpga_histogram_r_data_962; // word name
		struct {
			uint32_t hist_r_data_962 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_963 14'h1184 */
	union {
		uint32_t fpga_histogram_r_data_963; // word name
		struct {
			uint32_t hist_r_data_963 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_964 14'h1188 */
	union {
		uint32_t fpga_histogram_r_data_964; // word name
		struct {
			uint32_t hist_r_data_964 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_965 14'h118C */
	union {
		uint32_t fpga_histogram_r_data_965; // word name
		struct {
			uint32_t hist_r_data_965 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_966 14'h1190 */
	union {
		uint32_t fpga_histogram_r_data_966; // word name
		struct {
			uint32_t hist_r_data_966 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_967 14'h1194 */
	union {
		uint32_t fpga_histogram_r_data_967; // word name
		struct {
			uint32_t hist_r_data_967 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_968 14'h1198 */
	union {
		uint32_t fpga_histogram_r_data_968; // word name
		struct {
			uint32_t hist_r_data_968 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_969 14'h119C */
	union {
		uint32_t fpga_histogram_r_data_969; // word name
		struct {
			uint32_t hist_r_data_969 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_970 14'h11A0 */
	union {
		uint32_t fpga_histogram_r_data_970; // word name
		struct {
			uint32_t hist_r_data_970 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_971 14'h11A4 */
	union {
		uint32_t fpga_histogram_r_data_971; // word name
		struct {
			uint32_t hist_r_data_971 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_972 14'h11A8 */
	union {
		uint32_t fpga_histogram_r_data_972; // word name
		struct {
			uint32_t hist_r_data_972 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_973 14'h11AC */
	union {
		uint32_t fpga_histogram_r_data_973; // word name
		struct {
			uint32_t hist_r_data_973 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_974 14'h11B0 */
	union {
		uint32_t fpga_histogram_r_data_974; // word name
		struct {
			uint32_t hist_r_data_974 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_975 14'h11B4 */
	union {
		uint32_t fpga_histogram_r_data_975; // word name
		struct {
			uint32_t hist_r_data_975 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_976 14'h11B8 */
	union {
		uint32_t fpga_histogram_r_data_976; // word name
		struct {
			uint32_t hist_r_data_976 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_977 14'h11BC */
	union {
		uint32_t fpga_histogram_r_data_977; // word name
		struct {
			uint32_t hist_r_data_977 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_978 14'h11C0 */
	union {
		uint32_t fpga_histogram_r_data_978; // word name
		struct {
			uint32_t hist_r_data_978 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_979 14'h11C4 */
	union {
		uint32_t fpga_histogram_r_data_979; // word name
		struct {
			uint32_t hist_r_data_979 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_980 14'h11C8 */
	union {
		uint32_t fpga_histogram_r_data_980; // word name
		struct {
			uint32_t hist_r_data_980 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_981 14'h11CC */
	union {
		uint32_t fpga_histogram_r_data_981; // word name
		struct {
			uint32_t hist_r_data_981 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_982 14'h11D0 */
	union {
		uint32_t fpga_histogram_r_data_982; // word name
		struct {
			uint32_t hist_r_data_982 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_983 14'h11D4 */
	union {
		uint32_t fpga_histogram_r_data_983; // word name
		struct {
			uint32_t hist_r_data_983 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_984 14'h11D8 */
	union {
		uint32_t fpga_histogram_r_data_984; // word name
		struct {
			uint32_t hist_r_data_984 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_985 14'h11DC */
	union {
		uint32_t fpga_histogram_r_data_985; // word name
		struct {
			uint32_t hist_r_data_985 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_986 14'h11E0 */
	union {
		uint32_t fpga_histogram_r_data_986; // word name
		struct {
			uint32_t hist_r_data_986 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_987 14'h11E4 */
	union {
		uint32_t fpga_histogram_r_data_987; // word name
		struct {
			uint32_t hist_r_data_987 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_988 14'h11E8 */
	union {
		uint32_t fpga_histogram_r_data_988; // word name
		struct {
			uint32_t hist_r_data_988 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_989 14'h11EC */
	union {
		uint32_t fpga_histogram_r_data_989; // word name
		struct {
			uint32_t hist_r_data_989 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_990 14'h11F0 */
	union {
		uint32_t fpga_histogram_r_data_990; // word name
		struct {
			uint32_t hist_r_data_990 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_991 14'h11F4 */
	union {
		uint32_t fpga_histogram_r_data_991; // word name
		struct {
			uint32_t hist_r_data_991 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_992 14'h11F8 */
	union {
		uint32_t fpga_histogram_r_data_992; // word name
		struct {
			uint32_t hist_r_data_992 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_993 14'h11FC */
	union {
		uint32_t fpga_histogram_r_data_993; // word name
		struct {
			uint32_t hist_r_data_993 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_994 14'h1200 */
	union {
		uint32_t fpga_histogram_r_data_994; // word name
		struct {
			uint32_t hist_r_data_994 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_995 14'h1204 */
	union {
		uint32_t fpga_histogram_r_data_995; // word name
		struct {
			uint32_t hist_r_data_995 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_996 14'h1208 */
	union {
		uint32_t fpga_histogram_r_data_996; // word name
		struct {
			uint32_t hist_r_data_996 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_997 14'h120C */
	union {
		uint32_t fpga_histogram_r_data_997; // word name
		struct {
			uint32_t hist_r_data_997 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_998 14'h1210 */
	union {
		uint32_t fpga_histogram_r_data_998; // word name
		struct {
			uint32_t hist_r_data_998 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_999 14'h1214 */
	union {
		uint32_t fpga_histogram_r_data_999; // word name
		struct {
			uint32_t hist_r_data_999 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1000 14'h1218 */
	union {
		uint32_t fpga_histogram_r_data_1000; // word name
		struct {
			uint32_t hist_r_data_1000 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1001 14'h121C */
	union {
		uint32_t fpga_histogram_r_data_1001; // word name
		struct {
			uint32_t hist_r_data_1001 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1002 14'h1220 */
	union {
		uint32_t fpga_histogram_r_data_1002; // word name
		struct {
			uint32_t hist_r_data_1002 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1003 14'h1224 */
	union {
		uint32_t fpga_histogram_r_data_1003; // word name
		struct {
			uint32_t hist_r_data_1003 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1004 14'h1228 */
	union {
		uint32_t fpga_histogram_r_data_1004; // word name
		struct {
			uint32_t hist_r_data_1004 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1005 14'h122C */
	union {
		uint32_t fpga_histogram_r_data_1005; // word name
		struct {
			uint32_t hist_r_data_1005 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1006 14'h1230 */
	union {
		uint32_t fpga_histogram_r_data_1006; // word name
		struct {
			uint32_t hist_r_data_1006 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1007 14'h1234 */
	union {
		uint32_t fpga_histogram_r_data_1007; // word name
		struct {
			uint32_t hist_r_data_1007 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1008 14'h1238 */
	union {
		uint32_t fpga_histogram_r_data_1008; // word name
		struct {
			uint32_t hist_r_data_1008 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1009 14'h123C */
	union {
		uint32_t fpga_histogram_r_data_1009; // word name
		struct {
			uint32_t hist_r_data_1009 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1010 14'h1240 */
	union {
		uint32_t fpga_histogram_r_data_1010; // word name
		struct {
			uint32_t hist_r_data_1010 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1011 14'h1244 */
	union {
		uint32_t fpga_histogram_r_data_1011; // word name
		struct {
			uint32_t hist_r_data_1011 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1012 14'h1248 */
	union {
		uint32_t fpga_histogram_r_data_1012; // word name
		struct {
			uint32_t hist_r_data_1012 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1013 14'h124C */
	union {
		uint32_t fpga_histogram_r_data_1013; // word name
		struct {
			uint32_t hist_r_data_1013 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1014 14'h1250 */
	union {
		uint32_t fpga_histogram_r_data_1014; // word name
		struct {
			uint32_t hist_r_data_1014 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1015 14'h1254 */
	union {
		uint32_t fpga_histogram_r_data_1015; // word name
		struct {
			uint32_t hist_r_data_1015 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1016 14'h1258 */
	union {
		uint32_t fpga_histogram_r_data_1016; // word name
		struct {
			uint32_t hist_r_data_1016 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1017 14'h125C */
	union {
		uint32_t fpga_histogram_r_data_1017; // word name
		struct {
			uint32_t hist_r_data_1017 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1018 14'h1260 */
	union {
		uint32_t fpga_histogram_r_data_1018; // word name
		struct {
			uint32_t hist_r_data_1018 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1019 14'h1264 */
	union {
		uint32_t fpga_histogram_r_data_1019; // word name
		struct {
			uint32_t hist_r_data_1019 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1020 14'h1268 */
	union {
		uint32_t fpga_histogram_r_data_1020; // word name
		struct {
			uint32_t hist_r_data_1020 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1021 14'h126C */
	union {
		uint32_t fpga_histogram_r_data_1021; // word name
		struct {
			uint32_t hist_r_data_1021 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1022 14'h1270 */
	union {
		uint32_t fpga_histogram_r_data_1022; // word name
		struct {
			uint32_t hist_r_data_1022 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1023 14'h1274 */
	union {
		uint32_t fpga_histogram_r_data_1023; // word name
		struct {
			uint32_t hist_r_data_1023 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1024 14'h1278 */
	union {
		uint32_t fpga_histogram_r_data_1024; // word name
		struct {
			uint32_t hist_r_data_1024 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1025 14'h127C */
	union {
		uint32_t fpga_histogram_r_data_1025; // word name
		struct {
			uint32_t hist_r_data_1025 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1026 14'h1280 */
	union {
		uint32_t fpga_histogram_r_data_1026; // word name
		struct {
			uint32_t hist_r_data_1026 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1027 14'h1284 */
	union {
		uint32_t fpga_histogram_r_data_1027; // word name
		struct {
			uint32_t hist_r_data_1027 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1028 14'h1288 */
	union {
		uint32_t fpga_histogram_r_data_1028; // word name
		struct {
			uint32_t hist_r_data_1028 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1029 14'h128C */
	union {
		uint32_t fpga_histogram_r_data_1029; // word name
		struct {
			uint32_t hist_r_data_1029 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1030 14'h1290 */
	union {
		uint32_t fpga_histogram_r_data_1030; // word name
		struct {
			uint32_t hist_r_data_1030 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1031 14'h1294 */
	union {
		uint32_t fpga_histogram_r_data_1031; // word name
		struct {
			uint32_t hist_r_data_1031 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1032 14'h1298 */
	union {
		uint32_t fpga_histogram_r_data_1032; // word name
		struct {
			uint32_t hist_r_data_1032 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1033 14'h129C */
	union {
		uint32_t fpga_histogram_r_data_1033; // word name
		struct {
			uint32_t hist_r_data_1033 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1034 14'h12A0 */
	union {
		uint32_t fpga_histogram_r_data_1034; // word name
		struct {
			uint32_t hist_r_data_1034 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1035 14'h12A4 */
	union {
		uint32_t fpga_histogram_r_data_1035; // word name
		struct {
			uint32_t hist_r_data_1035 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1036 14'h12A8 */
	union {
		uint32_t fpga_histogram_r_data_1036; // word name
		struct {
			uint32_t hist_r_data_1036 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1037 14'h12AC */
	union {
		uint32_t fpga_histogram_r_data_1037; // word name
		struct {
			uint32_t hist_r_data_1037 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1038 14'h12B0 */
	union {
		uint32_t fpga_histogram_r_data_1038; // word name
		struct {
			uint32_t hist_r_data_1038 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1039 14'h12B4 */
	union {
		uint32_t fpga_histogram_r_data_1039; // word name
		struct {
			uint32_t hist_r_data_1039 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1040 14'h12B8 */
	union {
		uint32_t fpga_histogram_r_data_1040; // word name
		struct {
			uint32_t hist_r_data_1040 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1041 14'h12BC */
	union {
		uint32_t fpga_histogram_r_data_1041; // word name
		struct {
			uint32_t hist_r_data_1041 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1042 14'h12C0 */
	union {
		uint32_t fpga_histogram_r_data_1042; // word name
		struct {
			uint32_t hist_r_data_1042 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1043 14'h12C4 */
	union {
		uint32_t fpga_histogram_r_data_1043; // word name
		struct {
			uint32_t hist_r_data_1043 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1044 14'h12C8 */
	union {
		uint32_t fpga_histogram_r_data_1044; // word name
		struct {
			uint32_t hist_r_data_1044 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1045 14'h12CC */
	union {
		uint32_t fpga_histogram_r_data_1045; // word name
		struct {
			uint32_t hist_r_data_1045 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1046 14'h12D0 */
	union {
		uint32_t fpga_histogram_r_data_1046; // word name
		struct {
			uint32_t hist_r_data_1046 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1047 14'h12D4 */
	union {
		uint32_t fpga_histogram_r_data_1047; // word name
		struct {
			uint32_t hist_r_data_1047 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1048 14'h12D8 */
	union {
		uint32_t fpga_histogram_r_data_1048; // word name
		struct {
			uint32_t hist_r_data_1048 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1049 14'h12DC */
	union {
		uint32_t fpga_histogram_r_data_1049; // word name
		struct {
			uint32_t hist_r_data_1049 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1050 14'h12E0 */
	union {
		uint32_t fpga_histogram_r_data_1050; // word name
		struct {
			uint32_t hist_r_data_1050 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1051 14'h12E4 */
	union {
		uint32_t fpga_histogram_r_data_1051; // word name
		struct {
			uint32_t hist_r_data_1051 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1052 14'h12E8 */
	union {
		uint32_t fpga_histogram_r_data_1052; // word name
		struct {
			uint32_t hist_r_data_1052 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1053 14'h12EC */
	union {
		uint32_t fpga_histogram_r_data_1053; // word name
		struct {
			uint32_t hist_r_data_1053 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1054 14'h12F0 */
	union {
		uint32_t fpga_histogram_r_data_1054; // word name
		struct {
			uint32_t hist_r_data_1054 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1055 14'h12F4 */
	union {
		uint32_t fpga_histogram_r_data_1055; // word name
		struct {
			uint32_t hist_r_data_1055 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1056 14'h12F8 */
	union {
		uint32_t fpga_histogram_r_data_1056; // word name
		struct {
			uint32_t hist_r_data_1056 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1057 14'h12FC */
	union {
		uint32_t fpga_histogram_r_data_1057; // word name
		struct {
			uint32_t hist_r_data_1057 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1058 14'h1300 */
	union {
		uint32_t fpga_histogram_r_data_1058; // word name
		struct {
			uint32_t hist_r_data_1058 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1059 14'h1304 */
	union {
		uint32_t fpga_histogram_r_data_1059; // word name
		struct {
			uint32_t hist_r_data_1059 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1060 14'h1308 */
	union {
		uint32_t fpga_histogram_r_data_1060; // word name
		struct {
			uint32_t hist_r_data_1060 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1061 14'h130C */
	union {
		uint32_t fpga_histogram_r_data_1061; // word name
		struct {
			uint32_t hist_r_data_1061 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1062 14'h1310 */
	union {
		uint32_t fpga_histogram_r_data_1062; // word name
		struct {
			uint32_t hist_r_data_1062 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1063 14'h1314 */
	union {
		uint32_t fpga_histogram_r_data_1063; // word name
		struct {
			uint32_t hist_r_data_1063 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1064 14'h1318 */
	union {
		uint32_t fpga_histogram_r_data_1064; // word name
		struct {
			uint32_t hist_r_data_1064 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1065 14'h131C */
	union {
		uint32_t fpga_histogram_r_data_1065; // word name
		struct {
			uint32_t hist_r_data_1065 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1066 14'h1320 */
	union {
		uint32_t fpga_histogram_r_data_1066; // word name
		struct {
			uint32_t hist_r_data_1066 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1067 14'h1324 */
	union {
		uint32_t fpga_histogram_r_data_1067; // word name
		struct {
			uint32_t hist_r_data_1067 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1068 14'h1328 */
	union {
		uint32_t fpga_histogram_r_data_1068; // word name
		struct {
			uint32_t hist_r_data_1068 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1069 14'h132C */
	union {
		uint32_t fpga_histogram_r_data_1069; // word name
		struct {
			uint32_t hist_r_data_1069 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1070 14'h1330 */
	union {
		uint32_t fpga_histogram_r_data_1070; // word name
		struct {
			uint32_t hist_r_data_1070 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1071 14'h1334 */
	union {
		uint32_t fpga_histogram_r_data_1071; // word name
		struct {
			uint32_t hist_r_data_1071 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1072 14'h1338 */
	union {
		uint32_t fpga_histogram_r_data_1072; // word name
		struct {
			uint32_t hist_r_data_1072 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1073 14'h133C */
	union {
		uint32_t fpga_histogram_r_data_1073; // word name
		struct {
			uint32_t hist_r_data_1073 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1074 14'h1340 */
	union {
		uint32_t fpga_histogram_r_data_1074; // word name
		struct {
			uint32_t hist_r_data_1074 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1075 14'h1344 */
	union {
		uint32_t fpga_histogram_r_data_1075; // word name
		struct {
			uint32_t hist_r_data_1075 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1076 14'h1348 */
	union {
		uint32_t fpga_histogram_r_data_1076; // word name
		struct {
			uint32_t hist_r_data_1076 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1077 14'h134C */
	union {
		uint32_t fpga_histogram_r_data_1077; // word name
		struct {
			uint32_t hist_r_data_1077 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1078 14'h1350 */
	union {
		uint32_t fpga_histogram_r_data_1078; // word name
		struct {
			uint32_t hist_r_data_1078 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1079 14'h1354 */
	union {
		uint32_t fpga_histogram_r_data_1079; // word name
		struct {
			uint32_t hist_r_data_1079 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1080 14'h1358 */
	union {
		uint32_t fpga_histogram_r_data_1080; // word name
		struct {
			uint32_t hist_r_data_1080 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1081 14'h135C */
	union {
		uint32_t fpga_histogram_r_data_1081; // word name
		struct {
			uint32_t hist_r_data_1081 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1082 14'h1360 */
	union {
		uint32_t fpga_histogram_r_data_1082; // word name
		struct {
			uint32_t hist_r_data_1082 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1083 14'h1364 */
	union {
		uint32_t fpga_histogram_r_data_1083; // word name
		struct {
			uint32_t hist_r_data_1083 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1084 14'h1368 */
	union {
		uint32_t fpga_histogram_r_data_1084; // word name
		struct {
			uint32_t hist_r_data_1084 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1085 14'h136C */
	union {
		uint32_t fpga_histogram_r_data_1085; // word name
		struct {
			uint32_t hist_r_data_1085 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1086 14'h1370 */
	union {
		uint32_t fpga_histogram_r_data_1086; // word name
		struct {
			uint32_t hist_r_data_1086 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1087 14'h1374 */
	union {
		uint32_t fpga_histogram_r_data_1087; // word name
		struct {
			uint32_t hist_r_data_1087 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1088 14'h1378 */
	union {
		uint32_t fpga_histogram_r_data_1088; // word name
		struct {
			uint32_t hist_r_data_1088 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1089 14'h137C */
	union {
		uint32_t fpga_histogram_r_data_1089; // word name
		struct {
			uint32_t hist_r_data_1089 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1090 14'h1380 */
	union {
		uint32_t fpga_histogram_r_data_1090; // word name
		struct {
			uint32_t hist_r_data_1090 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1091 14'h1384 */
	union {
		uint32_t fpga_histogram_r_data_1091; // word name
		struct {
			uint32_t hist_r_data_1091 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1092 14'h1388 */
	union {
		uint32_t fpga_histogram_r_data_1092; // word name
		struct {
			uint32_t hist_r_data_1092 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1093 14'h138C */
	union {
		uint32_t fpga_histogram_r_data_1093; // word name
		struct {
			uint32_t hist_r_data_1093 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1094 14'h1390 */
	union {
		uint32_t fpga_histogram_r_data_1094; // word name
		struct {
			uint32_t hist_r_data_1094 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1095 14'h1394 */
	union {
		uint32_t fpga_histogram_r_data_1095; // word name
		struct {
			uint32_t hist_r_data_1095 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1096 14'h1398 */
	union {
		uint32_t fpga_histogram_r_data_1096; // word name
		struct {
			uint32_t hist_r_data_1096 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1097 14'h139C */
	union {
		uint32_t fpga_histogram_r_data_1097; // word name
		struct {
			uint32_t hist_r_data_1097 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1098 14'h13A0 */
	union {
		uint32_t fpga_histogram_r_data_1098; // word name
		struct {
			uint32_t hist_r_data_1098 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1099 14'h13A4 */
	union {
		uint32_t fpga_histogram_r_data_1099; // word name
		struct {
			uint32_t hist_r_data_1099 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1100 14'h13A8 */
	union {
		uint32_t fpga_histogram_r_data_1100; // word name
		struct {
			uint32_t hist_r_data_1100 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1101 14'h13AC */
	union {
		uint32_t fpga_histogram_r_data_1101; // word name
		struct {
			uint32_t hist_r_data_1101 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1102 14'h13B0 */
	union {
		uint32_t fpga_histogram_r_data_1102; // word name
		struct {
			uint32_t hist_r_data_1102 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1103 14'h13B4 */
	union {
		uint32_t fpga_histogram_r_data_1103; // word name
		struct {
			uint32_t hist_r_data_1103 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1104 14'h13B8 */
	union {
		uint32_t fpga_histogram_r_data_1104; // word name
		struct {
			uint32_t hist_r_data_1104 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1105 14'h13BC */
	union {
		uint32_t fpga_histogram_r_data_1105; // word name
		struct {
			uint32_t hist_r_data_1105 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1106 14'h13C0 */
	union {
		uint32_t fpga_histogram_r_data_1106; // word name
		struct {
			uint32_t hist_r_data_1106 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1107 14'h13C4 */
	union {
		uint32_t fpga_histogram_r_data_1107; // word name
		struct {
			uint32_t hist_r_data_1107 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1108 14'h13C8 */
	union {
		uint32_t fpga_histogram_r_data_1108; // word name
		struct {
			uint32_t hist_r_data_1108 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1109 14'h13CC */
	union {
		uint32_t fpga_histogram_r_data_1109; // word name
		struct {
			uint32_t hist_r_data_1109 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1110 14'h13D0 */
	union {
		uint32_t fpga_histogram_r_data_1110; // word name
		struct {
			uint32_t hist_r_data_1110 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1111 14'h13D4 */
	union {
		uint32_t fpga_histogram_r_data_1111; // word name
		struct {
			uint32_t hist_r_data_1111 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1112 14'h13D8 */
	union {
		uint32_t fpga_histogram_r_data_1112; // word name
		struct {
			uint32_t hist_r_data_1112 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1113 14'h13DC */
	union {
		uint32_t fpga_histogram_r_data_1113; // word name
		struct {
			uint32_t hist_r_data_1113 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1114 14'h13E0 */
	union {
		uint32_t fpga_histogram_r_data_1114; // word name
		struct {
			uint32_t hist_r_data_1114 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1115 14'h13E4 */
	union {
		uint32_t fpga_histogram_r_data_1115; // word name
		struct {
			uint32_t hist_r_data_1115 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1116 14'h13E8 */
	union {
		uint32_t fpga_histogram_r_data_1116; // word name
		struct {
			uint32_t hist_r_data_1116 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1117 14'h13EC */
	union {
		uint32_t fpga_histogram_r_data_1117; // word name
		struct {
			uint32_t hist_r_data_1117 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1118 14'h13F0 */
	union {
		uint32_t fpga_histogram_r_data_1118; // word name
		struct {
			uint32_t hist_r_data_1118 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1119 14'h13F4 */
	union {
		uint32_t fpga_histogram_r_data_1119; // word name
		struct {
			uint32_t hist_r_data_1119 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1120 14'h13F8 */
	union {
		uint32_t fpga_histogram_r_data_1120; // word name
		struct {
			uint32_t hist_r_data_1120 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1121 14'h13FC */
	union {
		uint32_t fpga_histogram_r_data_1121; // word name
		struct {
			uint32_t hist_r_data_1121 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1122 14'h1400 */
	union {
		uint32_t fpga_histogram_r_data_1122; // word name
		struct {
			uint32_t hist_r_data_1122 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1123 14'h1404 */
	union {
		uint32_t fpga_histogram_r_data_1123; // word name
		struct {
			uint32_t hist_r_data_1123 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1124 14'h1408 */
	union {
		uint32_t fpga_histogram_r_data_1124; // word name
		struct {
			uint32_t hist_r_data_1124 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1125 14'h140C */
	union {
		uint32_t fpga_histogram_r_data_1125; // word name
		struct {
			uint32_t hist_r_data_1125 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1126 14'h1410 */
	union {
		uint32_t fpga_histogram_r_data_1126; // word name
		struct {
			uint32_t hist_r_data_1126 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1127 14'h1414 */
	union {
		uint32_t fpga_histogram_r_data_1127; // word name
		struct {
			uint32_t hist_r_data_1127 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1128 14'h1418 */
	union {
		uint32_t fpga_histogram_r_data_1128; // word name
		struct {
			uint32_t hist_r_data_1128 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1129 14'h141C */
	union {
		uint32_t fpga_histogram_r_data_1129; // word name
		struct {
			uint32_t hist_r_data_1129 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1130 14'h1420 */
	union {
		uint32_t fpga_histogram_r_data_1130; // word name
		struct {
			uint32_t hist_r_data_1130 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1131 14'h1424 */
	union {
		uint32_t fpga_histogram_r_data_1131; // word name
		struct {
			uint32_t hist_r_data_1131 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1132 14'h1428 */
	union {
		uint32_t fpga_histogram_r_data_1132; // word name
		struct {
			uint32_t hist_r_data_1132 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1133 14'h142C */
	union {
		uint32_t fpga_histogram_r_data_1133; // word name
		struct {
			uint32_t hist_r_data_1133 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1134 14'h1430 */
	union {
		uint32_t fpga_histogram_r_data_1134; // word name
		struct {
			uint32_t hist_r_data_1134 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1135 14'h1434 */
	union {
		uint32_t fpga_histogram_r_data_1135; // word name
		struct {
			uint32_t hist_r_data_1135 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1136 14'h1438 */
	union {
		uint32_t fpga_histogram_r_data_1136; // word name
		struct {
			uint32_t hist_r_data_1136 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1137 14'h143C */
	union {
		uint32_t fpga_histogram_r_data_1137; // word name
		struct {
			uint32_t hist_r_data_1137 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1138 14'h1440 */
	union {
		uint32_t fpga_histogram_r_data_1138; // word name
		struct {
			uint32_t hist_r_data_1138 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1139 14'h1444 */
	union {
		uint32_t fpga_histogram_r_data_1139; // word name
		struct {
			uint32_t hist_r_data_1139 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1140 14'h1448 */
	union {
		uint32_t fpga_histogram_r_data_1140; // word name
		struct {
			uint32_t hist_r_data_1140 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1141 14'h144C */
	union {
		uint32_t fpga_histogram_r_data_1141; // word name
		struct {
			uint32_t hist_r_data_1141 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1142 14'h1450 */
	union {
		uint32_t fpga_histogram_r_data_1142; // word name
		struct {
			uint32_t hist_r_data_1142 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1143 14'h1454 */
	union {
		uint32_t fpga_histogram_r_data_1143; // word name
		struct {
			uint32_t hist_r_data_1143 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1144 14'h1458 */
	union {
		uint32_t fpga_histogram_r_data_1144; // word name
		struct {
			uint32_t hist_r_data_1144 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1145 14'h145C */
	union {
		uint32_t fpga_histogram_r_data_1145; // word name
		struct {
			uint32_t hist_r_data_1145 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1146 14'h1460 */
	union {
		uint32_t fpga_histogram_r_data_1146; // word name
		struct {
			uint32_t hist_r_data_1146 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1147 14'h1464 */
	union {
		uint32_t fpga_histogram_r_data_1147; // word name
		struct {
			uint32_t hist_r_data_1147 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1148 14'h1468 */
	union {
		uint32_t fpga_histogram_r_data_1148; // word name
		struct {
			uint32_t hist_r_data_1148 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1149 14'h146C */
	union {
		uint32_t fpga_histogram_r_data_1149; // word name
		struct {
			uint32_t hist_r_data_1149 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1150 14'h1470 */
	union {
		uint32_t fpga_histogram_r_data_1150; // word name
		struct {
			uint32_t hist_r_data_1150 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1151 14'h1474 */
	union {
		uint32_t fpga_histogram_r_data_1151; // word name
		struct {
			uint32_t hist_r_data_1151 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1152 14'h1478 */
	union {
		uint32_t fpga_histogram_r_data_1152; // word name
		struct {
			uint32_t hist_r_data_1152 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1153 14'h147C */
	union {
		uint32_t fpga_histogram_r_data_1153; // word name
		struct {
			uint32_t hist_r_data_1153 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1154 14'h1480 */
	union {
		uint32_t fpga_histogram_r_data_1154; // word name
		struct {
			uint32_t hist_r_data_1154 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1155 14'h1484 */
	union {
		uint32_t fpga_histogram_r_data_1155; // word name
		struct {
			uint32_t hist_r_data_1155 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1156 14'h1488 */
	union {
		uint32_t fpga_histogram_r_data_1156; // word name
		struct {
			uint32_t hist_r_data_1156 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1157 14'h148C */
	union {
		uint32_t fpga_histogram_r_data_1157; // word name
		struct {
			uint32_t hist_r_data_1157 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1158 14'h1490 */
	union {
		uint32_t fpga_histogram_r_data_1158; // word name
		struct {
			uint32_t hist_r_data_1158 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1159 14'h1494 */
	union {
		uint32_t fpga_histogram_r_data_1159; // word name
		struct {
			uint32_t hist_r_data_1159 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1160 14'h1498 */
	union {
		uint32_t fpga_histogram_r_data_1160; // word name
		struct {
			uint32_t hist_r_data_1160 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1161 14'h149C */
	union {
		uint32_t fpga_histogram_r_data_1161; // word name
		struct {
			uint32_t hist_r_data_1161 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1162 14'h14A0 */
	union {
		uint32_t fpga_histogram_r_data_1162; // word name
		struct {
			uint32_t hist_r_data_1162 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1163 14'h14A4 */
	union {
		uint32_t fpga_histogram_r_data_1163; // word name
		struct {
			uint32_t hist_r_data_1163 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1164 14'h14A8 */
	union {
		uint32_t fpga_histogram_r_data_1164; // word name
		struct {
			uint32_t hist_r_data_1164 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1165 14'h14AC */
	union {
		uint32_t fpga_histogram_r_data_1165; // word name
		struct {
			uint32_t hist_r_data_1165 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1166 14'h14B0 */
	union {
		uint32_t fpga_histogram_r_data_1166; // word name
		struct {
			uint32_t hist_r_data_1166 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1167 14'h14B4 */
	union {
		uint32_t fpga_histogram_r_data_1167; // word name
		struct {
			uint32_t hist_r_data_1167 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1168 14'h14B8 */
	union {
		uint32_t fpga_histogram_r_data_1168; // word name
		struct {
			uint32_t hist_r_data_1168 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1169 14'h14BC */
	union {
		uint32_t fpga_histogram_r_data_1169; // word name
		struct {
			uint32_t hist_r_data_1169 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1170 14'h14C0 */
	union {
		uint32_t fpga_histogram_r_data_1170; // word name
		struct {
			uint32_t hist_r_data_1170 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1171 14'h14C4 */
	union {
		uint32_t fpga_histogram_r_data_1171; // word name
		struct {
			uint32_t hist_r_data_1171 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1172 14'h14C8 */
	union {
		uint32_t fpga_histogram_r_data_1172; // word name
		struct {
			uint32_t hist_r_data_1172 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1173 14'h14CC */
	union {
		uint32_t fpga_histogram_r_data_1173; // word name
		struct {
			uint32_t hist_r_data_1173 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1174 14'h14D0 */
	union {
		uint32_t fpga_histogram_r_data_1174; // word name
		struct {
			uint32_t hist_r_data_1174 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1175 14'h14D4 */
	union {
		uint32_t fpga_histogram_r_data_1175; // word name
		struct {
			uint32_t hist_r_data_1175 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1176 14'h14D8 */
	union {
		uint32_t fpga_histogram_r_data_1176; // word name
		struct {
			uint32_t hist_r_data_1176 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1177 14'h14DC */
	union {
		uint32_t fpga_histogram_r_data_1177; // word name
		struct {
			uint32_t hist_r_data_1177 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1178 14'h14E0 */
	union {
		uint32_t fpga_histogram_r_data_1178; // word name
		struct {
			uint32_t hist_r_data_1178 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1179 14'h14E4 */
	union {
		uint32_t fpga_histogram_r_data_1179; // word name
		struct {
			uint32_t hist_r_data_1179 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1180 14'h14E8 */
	union {
		uint32_t fpga_histogram_r_data_1180; // word name
		struct {
			uint32_t hist_r_data_1180 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1181 14'h14EC */
	union {
		uint32_t fpga_histogram_r_data_1181; // word name
		struct {
			uint32_t hist_r_data_1181 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1182 14'h14F0 */
	union {
		uint32_t fpga_histogram_r_data_1182; // word name
		struct {
			uint32_t hist_r_data_1182 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1183 14'h14F4 */
	union {
		uint32_t fpga_histogram_r_data_1183; // word name
		struct {
			uint32_t hist_r_data_1183 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1184 14'h14F8 */
	union {
		uint32_t fpga_histogram_r_data_1184; // word name
		struct {
			uint32_t hist_r_data_1184 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1185 14'h14FC */
	union {
		uint32_t fpga_histogram_r_data_1185; // word name
		struct {
			uint32_t hist_r_data_1185 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1186 14'h1500 */
	union {
		uint32_t fpga_histogram_r_data_1186; // word name
		struct {
			uint32_t hist_r_data_1186 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1187 14'h1504 */
	union {
		uint32_t fpga_histogram_r_data_1187; // word name
		struct {
			uint32_t hist_r_data_1187 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1188 14'h1508 */
	union {
		uint32_t fpga_histogram_r_data_1188; // word name
		struct {
			uint32_t hist_r_data_1188 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1189 14'h150C */
	union {
		uint32_t fpga_histogram_r_data_1189; // word name
		struct {
			uint32_t hist_r_data_1189 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1190 14'h1510 */
	union {
		uint32_t fpga_histogram_r_data_1190; // word name
		struct {
			uint32_t hist_r_data_1190 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1191 14'h1514 */
	union {
		uint32_t fpga_histogram_r_data_1191; // word name
		struct {
			uint32_t hist_r_data_1191 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1192 14'h1518 */
	union {
		uint32_t fpga_histogram_r_data_1192; // word name
		struct {
			uint32_t hist_r_data_1192 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1193 14'h151C */
	union {
		uint32_t fpga_histogram_r_data_1193; // word name
		struct {
			uint32_t hist_r_data_1193 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1194 14'h1520 */
	union {
		uint32_t fpga_histogram_r_data_1194; // word name
		struct {
			uint32_t hist_r_data_1194 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1195 14'h1524 */
	union {
		uint32_t fpga_histogram_r_data_1195; // word name
		struct {
			uint32_t hist_r_data_1195 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1196 14'h1528 */
	union {
		uint32_t fpga_histogram_r_data_1196; // word name
		struct {
			uint32_t hist_r_data_1196 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1197 14'h152C */
	union {
		uint32_t fpga_histogram_r_data_1197; // word name
		struct {
			uint32_t hist_r_data_1197 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1198 14'h1530 */
	union {
		uint32_t fpga_histogram_r_data_1198; // word name
		struct {
			uint32_t hist_r_data_1198 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1199 14'h1534 */
	union {
		uint32_t fpga_histogram_r_data_1199; // word name
		struct {
			uint32_t hist_r_data_1199 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1200 14'h1538 */
	union {
		uint32_t fpga_histogram_r_data_1200; // word name
		struct {
			uint32_t hist_r_data_1200 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1201 14'h153C */
	union {
		uint32_t fpga_histogram_r_data_1201; // word name
		struct {
			uint32_t hist_r_data_1201 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1202 14'h1540 */
	union {
		uint32_t fpga_histogram_r_data_1202; // word name
		struct {
			uint32_t hist_r_data_1202 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1203 14'h1544 */
	union {
		uint32_t fpga_histogram_r_data_1203; // word name
		struct {
			uint32_t hist_r_data_1203 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1204 14'h1548 */
	union {
		uint32_t fpga_histogram_r_data_1204; // word name
		struct {
			uint32_t hist_r_data_1204 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1205 14'h154C */
	union {
		uint32_t fpga_histogram_r_data_1205; // word name
		struct {
			uint32_t hist_r_data_1205 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1206 14'h1550 */
	union {
		uint32_t fpga_histogram_r_data_1206; // word name
		struct {
			uint32_t hist_r_data_1206 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1207 14'h1554 */
	union {
		uint32_t fpga_histogram_r_data_1207; // word name
		struct {
			uint32_t hist_r_data_1207 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1208 14'h1558 */
	union {
		uint32_t fpga_histogram_r_data_1208; // word name
		struct {
			uint32_t hist_r_data_1208 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1209 14'h155C */
	union {
		uint32_t fpga_histogram_r_data_1209; // word name
		struct {
			uint32_t hist_r_data_1209 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1210 14'h1560 */
	union {
		uint32_t fpga_histogram_r_data_1210; // word name
		struct {
			uint32_t hist_r_data_1210 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1211 14'h1564 */
	union {
		uint32_t fpga_histogram_r_data_1211; // word name
		struct {
			uint32_t hist_r_data_1211 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1212 14'h1568 */
	union {
		uint32_t fpga_histogram_r_data_1212; // word name
		struct {
			uint32_t hist_r_data_1212 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1213 14'h156C */
	union {
		uint32_t fpga_histogram_r_data_1213; // word name
		struct {
			uint32_t hist_r_data_1213 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1214 14'h1570 */
	union {
		uint32_t fpga_histogram_r_data_1214; // word name
		struct {
			uint32_t hist_r_data_1214 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1215 14'h1574 */
	union {
		uint32_t fpga_histogram_r_data_1215; // word name
		struct {
			uint32_t hist_r_data_1215 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1216 14'h1578 */
	union {
		uint32_t fpga_histogram_r_data_1216; // word name
		struct {
			uint32_t hist_r_data_1216 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1217 14'h157C */
	union {
		uint32_t fpga_histogram_r_data_1217; // word name
		struct {
			uint32_t hist_r_data_1217 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1218 14'h1580 */
	union {
		uint32_t fpga_histogram_r_data_1218; // word name
		struct {
			uint32_t hist_r_data_1218 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1219 14'h1584 */
	union {
		uint32_t fpga_histogram_r_data_1219; // word name
		struct {
			uint32_t hist_r_data_1219 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1220 14'h1588 */
	union {
		uint32_t fpga_histogram_r_data_1220; // word name
		struct {
			uint32_t hist_r_data_1220 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1221 14'h158C */
	union {
		uint32_t fpga_histogram_r_data_1221; // word name
		struct {
			uint32_t hist_r_data_1221 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1222 14'h1590 */
	union {
		uint32_t fpga_histogram_r_data_1222; // word name
		struct {
			uint32_t hist_r_data_1222 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1223 14'h1594 */
	union {
		uint32_t fpga_histogram_r_data_1223; // word name
		struct {
			uint32_t hist_r_data_1223 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1224 14'h1598 */
	union {
		uint32_t fpga_histogram_r_data_1224; // word name
		struct {
			uint32_t hist_r_data_1224 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1225 14'h159C */
	union {
		uint32_t fpga_histogram_r_data_1225; // word name
		struct {
			uint32_t hist_r_data_1225 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1226 14'h15A0 */
	union {
		uint32_t fpga_histogram_r_data_1226; // word name
		struct {
			uint32_t hist_r_data_1226 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1227 14'h15A4 */
	union {
		uint32_t fpga_histogram_r_data_1227; // word name
		struct {
			uint32_t hist_r_data_1227 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1228 14'h15A8 */
	union {
		uint32_t fpga_histogram_r_data_1228; // word name
		struct {
			uint32_t hist_r_data_1228 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1229 14'h15AC */
	union {
		uint32_t fpga_histogram_r_data_1229; // word name
		struct {
			uint32_t hist_r_data_1229 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1230 14'h15B0 */
	union {
		uint32_t fpga_histogram_r_data_1230; // word name
		struct {
			uint32_t hist_r_data_1230 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1231 14'h15B4 */
	union {
		uint32_t fpga_histogram_r_data_1231; // word name
		struct {
			uint32_t hist_r_data_1231 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1232 14'h15B8 */
	union {
		uint32_t fpga_histogram_r_data_1232; // word name
		struct {
			uint32_t hist_r_data_1232 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1233 14'h15BC */
	union {
		uint32_t fpga_histogram_r_data_1233; // word name
		struct {
			uint32_t hist_r_data_1233 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1234 14'h15C0 */
	union {
		uint32_t fpga_histogram_r_data_1234; // word name
		struct {
			uint32_t hist_r_data_1234 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1235 14'h15C4 */
	union {
		uint32_t fpga_histogram_r_data_1235; // word name
		struct {
			uint32_t hist_r_data_1235 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1236 14'h15C8 */
	union {
		uint32_t fpga_histogram_r_data_1236; // word name
		struct {
			uint32_t hist_r_data_1236 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1237 14'h15CC */
	union {
		uint32_t fpga_histogram_r_data_1237; // word name
		struct {
			uint32_t hist_r_data_1237 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1238 14'h15D0 */
	union {
		uint32_t fpga_histogram_r_data_1238; // word name
		struct {
			uint32_t hist_r_data_1238 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1239 14'h15D4 */
	union {
		uint32_t fpga_histogram_r_data_1239; // word name
		struct {
			uint32_t hist_r_data_1239 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1240 14'h15D8 */
	union {
		uint32_t fpga_histogram_r_data_1240; // word name
		struct {
			uint32_t hist_r_data_1240 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1241 14'h15DC */
	union {
		uint32_t fpga_histogram_r_data_1241; // word name
		struct {
			uint32_t hist_r_data_1241 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1242 14'h15E0 */
	union {
		uint32_t fpga_histogram_r_data_1242; // word name
		struct {
			uint32_t hist_r_data_1242 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1243 14'h15E4 */
	union {
		uint32_t fpga_histogram_r_data_1243; // word name
		struct {
			uint32_t hist_r_data_1243 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1244 14'h15E8 */
	union {
		uint32_t fpga_histogram_r_data_1244; // word name
		struct {
			uint32_t hist_r_data_1244 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1245 14'h15EC */
	union {
		uint32_t fpga_histogram_r_data_1245; // word name
		struct {
			uint32_t hist_r_data_1245 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1246 14'h15F0 */
	union {
		uint32_t fpga_histogram_r_data_1246; // word name
		struct {
			uint32_t hist_r_data_1246 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1247 14'h15F4 */
	union {
		uint32_t fpga_histogram_r_data_1247; // word name
		struct {
			uint32_t hist_r_data_1247 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1248 14'h15F8 */
	union {
		uint32_t fpga_histogram_r_data_1248; // word name
		struct {
			uint32_t hist_r_data_1248 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1249 14'h15FC */
	union {
		uint32_t fpga_histogram_r_data_1249; // word name
		struct {
			uint32_t hist_r_data_1249 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1250 14'h1600 */
	union {
		uint32_t fpga_histogram_r_data_1250; // word name
		struct {
			uint32_t hist_r_data_1250 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1251 14'h1604 */
	union {
		uint32_t fpga_histogram_r_data_1251; // word name
		struct {
			uint32_t hist_r_data_1251 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1252 14'h1608 */
	union {
		uint32_t fpga_histogram_r_data_1252; // word name
		struct {
			uint32_t hist_r_data_1252 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1253 14'h160C */
	union {
		uint32_t fpga_histogram_r_data_1253; // word name
		struct {
			uint32_t hist_r_data_1253 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1254 14'h1610 */
	union {
		uint32_t fpga_histogram_r_data_1254; // word name
		struct {
			uint32_t hist_r_data_1254 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1255 14'h1614 */
	union {
		uint32_t fpga_histogram_r_data_1255; // word name
		struct {
			uint32_t hist_r_data_1255 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1256 14'h1618 */
	union {
		uint32_t fpga_histogram_r_data_1256; // word name
		struct {
			uint32_t hist_r_data_1256 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1257 14'h161C */
	union {
		uint32_t fpga_histogram_r_data_1257; // word name
		struct {
			uint32_t hist_r_data_1257 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1258 14'h1620 */
	union {
		uint32_t fpga_histogram_r_data_1258; // word name
		struct {
			uint32_t hist_r_data_1258 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1259 14'h1624 */
	union {
		uint32_t fpga_histogram_r_data_1259; // word name
		struct {
			uint32_t hist_r_data_1259 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1260 14'h1628 */
	union {
		uint32_t fpga_histogram_r_data_1260; // word name
		struct {
			uint32_t hist_r_data_1260 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1261 14'h162C */
	union {
		uint32_t fpga_histogram_r_data_1261; // word name
		struct {
			uint32_t hist_r_data_1261 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1262 14'h1630 */
	union {
		uint32_t fpga_histogram_r_data_1262; // word name
		struct {
			uint32_t hist_r_data_1262 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1263 14'h1634 */
	union {
		uint32_t fpga_histogram_r_data_1263; // word name
		struct {
			uint32_t hist_r_data_1263 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1264 14'h1638 */
	union {
		uint32_t fpga_histogram_r_data_1264; // word name
		struct {
			uint32_t hist_r_data_1264 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1265 14'h163C */
	union {
		uint32_t fpga_histogram_r_data_1265; // word name
		struct {
			uint32_t hist_r_data_1265 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1266 14'h1640 */
	union {
		uint32_t fpga_histogram_r_data_1266; // word name
		struct {
			uint32_t hist_r_data_1266 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1267 14'h1644 */
	union {
		uint32_t fpga_histogram_r_data_1267; // word name
		struct {
			uint32_t hist_r_data_1267 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1268 14'h1648 */
	union {
		uint32_t fpga_histogram_r_data_1268; // word name
		struct {
			uint32_t hist_r_data_1268 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1269 14'h164C */
	union {
		uint32_t fpga_histogram_r_data_1269; // word name
		struct {
			uint32_t hist_r_data_1269 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1270 14'h1650 */
	union {
		uint32_t fpga_histogram_r_data_1270; // word name
		struct {
			uint32_t hist_r_data_1270 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1271 14'h1654 */
	union {
		uint32_t fpga_histogram_r_data_1271; // word name
		struct {
			uint32_t hist_r_data_1271 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1272 14'h1658 */
	union {
		uint32_t fpga_histogram_r_data_1272; // word name
		struct {
			uint32_t hist_r_data_1272 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1273 14'h165C */
	union {
		uint32_t fpga_histogram_r_data_1273; // word name
		struct {
			uint32_t hist_r_data_1273 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1274 14'h1660 */
	union {
		uint32_t fpga_histogram_r_data_1274; // word name
		struct {
			uint32_t hist_r_data_1274 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1275 14'h1664 */
	union {
		uint32_t fpga_histogram_r_data_1275; // word name
		struct {
			uint32_t hist_r_data_1275 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1276 14'h1668 */
	union {
		uint32_t fpga_histogram_r_data_1276; // word name
		struct {
			uint32_t hist_r_data_1276 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1277 14'h166C */
	union {
		uint32_t fpga_histogram_r_data_1277; // word name
		struct {
			uint32_t hist_r_data_1277 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1278 14'h1670 */
	union {
		uint32_t fpga_histogram_r_data_1278; // word name
		struct {
			uint32_t hist_r_data_1278 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1279 14'h1674 */
	union {
		uint32_t fpga_histogram_r_data_1279; // word name
		struct {
			uint32_t hist_r_data_1279 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1280 14'h1678 */
	union {
		uint32_t fpga_histogram_r_data_1280; // word name
		struct {
			uint32_t hist_r_data_1280 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1281 14'h167C */
	union {
		uint32_t fpga_histogram_r_data_1281; // word name
		struct {
			uint32_t hist_r_data_1281 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1282 14'h1680 */
	union {
		uint32_t fpga_histogram_r_data_1282; // word name
		struct {
			uint32_t hist_r_data_1282 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1283 14'h1684 */
	union {
		uint32_t fpga_histogram_r_data_1283; // word name
		struct {
			uint32_t hist_r_data_1283 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1284 14'h1688 */
	union {
		uint32_t fpga_histogram_r_data_1284; // word name
		struct {
			uint32_t hist_r_data_1284 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1285 14'h168C */
	union {
		uint32_t fpga_histogram_r_data_1285; // word name
		struct {
			uint32_t hist_r_data_1285 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1286 14'h1690 */
	union {
		uint32_t fpga_histogram_r_data_1286; // word name
		struct {
			uint32_t hist_r_data_1286 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1287 14'h1694 */
	union {
		uint32_t fpga_histogram_r_data_1287; // word name
		struct {
			uint32_t hist_r_data_1287 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1288 14'h1698 */
	union {
		uint32_t fpga_histogram_r_data_1288; // word name
		struct {
			uint32_t hist_r_data_1288 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1289 14'h169C */
	union {
		uint32_t fpga_histogram_r_data_1289; // word name
		struct {
			uint32_t hist_r_data_1289 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1290 14'h16A0 */
	union {
		uint32_t fpga_histogram_r_data_1290; // word name
		struct {
			uint32_t hist_r_data_1290 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1291 14'h16A4 */
	union {
		uint32_t fpga_histogram_r_data_1291; // word name
		struct {
			uint32_t hist_r_data_1291 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1292 14'h16A8 */
	union {
		uint32_t fpga_histogram_r_data_1292; // word name
		struct {
			uint32_t hist_r_data_1292 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1293 14'h16AC */
	union {
		uint32_t fpga_histogram_r_data_1293; // word name
		struct {
			uint32_t hist_r_data_1293 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1294 14'h16B0 */
	union {
		uint32_t fpga_histogram_r_data_1294; // word name
		struct {
			uint32_t hist_r_data_1294 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1295 14'h16B4 */
	union {
		uint32_t fpga_histogram_r_data_1295; // word name
		struct {
			uint32_t hist_r_data_1295 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1296 14'h16B8 */
	union {
		uint32_t fpga_histogram_r_data_1296; // word name
		struct {
			uint32_t hist_r_data_1296 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1297 14'h16BC */
	union {
		uint32_t fpga_histogram_r_data_1297; // word name
		struct {
			uint32_t hist_r_data_1297 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1298 14'h16C0 */
	union {
		uint32_t fpga_histogram_r_data_1298; // word name
		struct {
			uint32_t hist_r_data_1298 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1299 14'h16C4 */
	union {
		uint32_t fpga_histogram_r_data_1299; // word name
		struct {
			uint32_t hist_r_data_1299 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1300 14'h16C8 */
	union {
		uint32_t fpga_histogram_r_data_1300; // word name
		struct {
			uint32_t hist_r_data_1300 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1301 14'h16CC */
	union {
		uint32_t fpga_histogram_r_data_1301; // word name
		struct {
			uint32_t hist_r_data_1301 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1302 14'h16D0 */
	union {
		uint32_t fpga_histogram_r_data_1302; // word name
		struct {
			uint32_t hist_r_data_1302 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1303 14'h16D4 */
	union {
		uint32_t fpga_histogram_r_data_1303; // word name
		struct {
			uint32_t hist_r_data_1303 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1304 14'h16D8 */
	union {
		uint32_t fpga_histogram_r_data_1304; // word name
		struct {
			uint32_t hist_r_data_1304 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1305 14'h16DC */
	union {
		uint32_t fpga_histogram_r_data_1305; // word name
		struct {
			uint32_t hist_r_data_1305 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1306 14'h16E0 */
	union {
		uint32_t fpga_histogram_r_data_1306; // word name
		struct {
			uint32_t hist_r_data_1306 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1307 14'h16E4 */
	union {
		uint32_t fpga_histogram_r_data_1307; // word name
		struct {
			uint32_t hist_r_data_1307 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1308 14'h16E8 */
	union {
		uint32_t fpga_histogram_r_data_1308; // word name
		struct {
			uint32_t hist_r_data_1308 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1309 14'h16EC */
	union {
		uint32_t fpga_histogram_r_data_1309; // word name
		struct {
			uint32_t hist_r_data_1309 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1310 14'h16F0 */
	union {
		uint32_t fpga_histogram_r_data_1310; // word name
		struct {
			uint32_t hist_r_data_1310 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1311 14'h16F4 */
	union {
		uint32_t fpga_histogram_r_data_1311; // word name
		struct {
			uint32_t hist_r_data_1311 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1312 14'h16F8 */
	union {
		uint32_t fpga_histogram_r_data_1312; // word name
		struct {
			uint32_t hist_r_data_1312 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1313 14'h16FC */
	union {
		uint32_t fpga_histogram_r_data_1313; // word name
		struct {
			uint32_t hist_r_data_1313 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1314 14'h1700 */
	union {
		uint32_t fpga_histogram_r_data_1314; // word name
		struct {
			uint32_t hist_r_data_1314 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1315 14'h1704 */
	union {
		uint32_t fpga_histogram_r_data_1315; // word name
		struct {
			uint32_t hist_r_data_1315 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1316 14'h1708 */
	union {
		uint32_t fpga_histogram_r_data_1316; // word name
		struct {
			uint32_t hist_r_data_1316 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1317 14'h170C */
	union {
		uint32_t fpga_histogram_r_data_1317; // word name
		struct {
			uint32_t hist_r_data_1317 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1318 14'h1710 */
	union {
		uint32_t fpga_histogram_r_data_1318; // word name
		struct {
			uint32_t hist_r_data_1318 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1319 14'h1714 */
	union {
		uint32_t fpga_histogram_r_data_1319; // word name
		struct {
			uint32_t hist_r_data_1319 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1320 14'h1718 */
	union {
		uint32_t fpga_histogram_r_data_1320; // word name
		struct {
			uint32_t hist_r_data_1320 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1321 14'h171C */
	union {
		uint32_t fpga_histogram_r_data_1321; // word name
		struct {
			uint32_t hist_r_data_1321 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1322 14'h1720 */
	union {
		uint32_t fpga_histogram_r_data_1322; // word name
		struct {
			uint32_t hist_r_data_1322 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1323 14'h1724 */
	union {
		uint32_t fpga_histogram_r_data_1323; // word name
		struct {
			uint32_t hist_r_data_1323 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1324 14'h1728 */
	union {
		uint32_t fpga_histogram_r_data_1324; // word name
		struct {
			uint32_t hist_r_data_1324 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1325 14'h172C */
	union {
		uint32_t fpga_histogram_r_data_1325; // word name
		struct {
			uint32_t hist_r_data_1325 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1326 14'h1730 */
	union {
		uint32_t fpga_histogram_r_data_1326; // word name
		struct {
			uint32_t hist_r_data_1326 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1327 14'h1734 */
	union {
		uint32_t fpga_histogram_r_data_1327; // word name
		struct {
			uint32_t hist_r_data_1327 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1328 14'h1738 */
	union {
		uint32_t fpga_histogram_r_data_1328; // word name
		struct {
			uint32_t hist_r_data_1328 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1329 14'h173C */
	union {
		uint32_t fpga_histogram_r_data_1329; // word name
		struct {
			uint32_t hist_r_data_1329 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1330 14'h1740 */
	union {
		uint32_t fpga_histogram_r_data_1330; // word name
		struct {
			uint32_t hist_r_data_1330 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1331 14'h1744 */
	union {
		uint32_t fpga_histogram_r_data_1331; // word name
		struct {
			uint32_t hist_r_data_1331 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1332 14'h1748 */
	union {
		uint32_t fpga_histogram_r_data_1332; // word name
		struct {
			uint32_t hist_r_data_1332 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1333 14'h174C */
	union {
		uint32_t fpga_histogram_r_data_1333; // word name
		struct {
			uint32_t hist_r_data_1333 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1334 14'h1750 */
	union {
		uint32_t fpga_histogram_r_data_1334; // word name
		struct {
			uint32_t hist_r_data_1334 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1335 14'h1754 */
	union {
		uint32_t fpga_histogram_r_data_1335; // word name
		struct {
			uint32_t hist_r_data_1335 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1336 14'h1758 */
	union {
		uint32_t fpga_histogram_r_data_1336; // word name
		struct {
			uint32_t hist_r_data_1336 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1337 14'h175C */
	union {
		uint32_t fpga_histogram_r_data_1337; // word name
		struct {
			uint32_t hist_r_data_1337 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1338 14'h1760 */
	union {
		uint32_t fpga_histogram_r_data_1338; // word name
		struct {
			uint32_t hist_r_data_1338 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1339 14'h1764 */
	union {
		uint32_t fpga_histogram_r_data_1339; // word name
		struct {
			uint32_t hist_r_data_1339 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1340 14'h1768 */
	union {
		uint32_t fpga_histogram_r_data_1340; // word name
		struct {
			uint32_t hist_r_data_1340 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1341 14'h176C */
	union {
		uint32_t fpga_histogram_r_data_1341; // word name
		struct {
			uint32_t hist_r_data_1341 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1342 14'h1770 */
	union {
		uint32_t fpga_histogram_r_data_1342; // word name
		struct {
			uint32_t hist_r_data_1342 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1343 14'h1774 */
	union {
		uint32_t fpga_histogram_r_data_1343; // word name
		struct {
			uint32_t hist_r_data_1343 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1344 14'h1778 */
	union {
		uint32_t fpga_histogram_r_data_1344; // word name
		struct {
			uint32_t hist_r_data_1344 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1345 14'h177C */
	union {
		uint32_t fpga_histogram_r_data_1345; // word name
		struct {
			uint32_t hist_r_data_1345 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1346 14'h1780 */
	union {
		uint32_t fpga_histogram_r_data_1346; // word name
		struct {
			uint32_t hist_r_data_1346 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1347 14'h1784 */
	union {
		uint32_t fpga_histogram_r_data_1347; // word name
		struct {
			uint32_t hist_r_data_1347 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1348 14'h1788 */
	union {
		uint32_t fpga_histogram_r_data_1348; // word name
		struct {
			uint32_t hist_r_data_1348 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1349 14'h178C */
	union {
		uint32_t fpga_histogram_r_data_1349; // word name
		struct {
			uint32_t hist_r_data_1349 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1350 14'h1790 */
	union {
		uint32_t fpga_histogram_r_data_1350; // word name
		struct {
			uint32_t hist_r_data_1350 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1351 14'h1794 */
	union {
		uint32_t fpga_histogram_r_data_1351; // word name
		struct {
			uint32_t hist_r_data_1351 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1352 14'h1798 */
	union {
		uint32_t fpga_histogram_r_data_1352; // word name
		struct {
			uint32_t hist_r_data_1352 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1353 14'h179C */
	union {
		uint32_t fpga_histogram_r_data_1353; // word name
		struct {
			uint32_t hist_r_data_1353 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1354 14'h17A0 */
	union {
		uint32_t fpga_histogram_r_data_1354; // word name
		struct {
			uint32_t hist_r_data_1354 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1355 14'h17A4 */
	union {
		uint32_t fpga_histogram_r_data_1355; // word name
		struct {
			uint32_t hist_r_data_1355 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1356 14'h17A8 */
	union {
		uint32_t fpga_histogram_r_data_1356; // word name
		struct {
			uint32_t hist_r_data_1356 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1357 14'h17AC */
	union {
		uint32_t fpga_histogram_r_data_1357; // word name
		struct {
			uint32_t hist_r_data_1357 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1358 14'h17B0 */
	union {
		uint32_t fpga_histogram_r_data_1358; // word name
		struct {
			uint32_t hist_r_data_1358 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1359 14'h17B4 */
	union {
		uint32_t fpga_histogram_r_data_1359; // word name
		struct {
			uint32_t hist_r_data_1359 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1360 14'h17B8 */
	union {
		uint32_t fpga_histogram_r_data_1360; // word name
		struct {
			uint32_t hist_r_data_1360 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1361 14'h17BC */
	union {
		uint32_t fpga_histogram_r_data_1361; // word name
		struct {
			uint32_t hist_r_data_1361 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1362 14'h17C0 */
	union {
		uint32_t fpga_histogram_r_data_1362; // word name
		struct {
			uint32_t hist_r_data_1362 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1363 14'h17C4 */
	union {
		uint32_t fpga_histogram_r_data_1363; // word name
		struct {
			uint32_t hist_r_data_1363 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1364 14'h17C8 */
	union {
		uint32_t fpga_histogram_r_data_1364; // word name
		struct {
			uint32_t hist_r_data_1364 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1365 14'h17CC */
	union {
		uint32_t fpga_histogram_r_data_1365; // word name
		struct {
			uint32_t hist_r_data_1365 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1366 14'h17D0 */
	union {
		uint32_t fpga_histogram_r_data_1366; // word name
		struct {
			uint32_t hist_r_data_1366 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1367 14'h17D4 */
	union {
		uint32_t fpga_histogram_r_data_1367; // word name
		struct {
			uint32_t hist_r_data_1367 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1368 14'h17D8 */
	union {
		uint32_t fpga_histogram_r_data_1368; // word name
		struct {
			uint32_t hist_r_data_1368 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1369 14'h17DC */
	union {
		uint32_t fpga_histogram_r_data_1369; // word name
		struct {
			uint32_t hist_r_data_1369 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1370 14'h17E0 */
	union {
		uint32_t fpga_histogram_r_data_1370; // word name
		struct {
			uint32_t hist_r_data_1370 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1371 14'h17E4 */
	union {
		uint32_t fpga_histogram_r_data_1371; // word name
		struct {
			uint32_t hist_r_data_1371 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1372 14'h17E8 */
	union {
		uint32_t fpga_histogram_r_data_1372; // word name
		struct {
			uint32_t hist_r_data_1372 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1373 14'h17EC */
	union {
		uint32_t fpga_histogram_r_data_1373; // word name
		struct {
			uint32_t hist_r_data_1373 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1374 14'h17F0 */
	union {
		uint32_t fpga_histogram_r_data_1374; // word name
		struct {
			uint32_t hist_r_data_1374 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1375 14'h17F4 */
	union {
		uint32_t fpga_histogram_r_data_1375; // word name
		struct {
			uint32_t hist_r_data_1375 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1376 14'h17F8 */
	union {
		uint32_t fpga_histogram_r_data_1376; // word name
		struct {
			uint32_t hist_r_data_1376 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1377 14'h17FC */
	union {
		uint32_t fpga_histogram_r_data_1377; // word name
		struct {
			uint32_t hist_r_data_1377 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1378 14'h1800 */
	union {
		uint32_t fpga_histogram_r_data_1378; // word name
		struct {
			uint32_t hist_r_data_1378 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1379 14'h1804 */
	union {
		uint32_t fpga_histogram_r_data_1379; // word name
		struct {
			uint32_t hist_r_data_1379 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1380 14'h1808 */
	union {
		uint32_t fpga_histogram_r_data_1380; // word name
		struct {
			uint32_t hist_r_data_1380 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1381 14'h180C */
	union {
		uint32_t fpga_histogram_r_data_1381; // word name
		struct {
			uint32_t hist_r_data_1381 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1382 14'h1810 */
	union {
		uint32_t fpga_histogram_r_data_1382; // word name
		struct {
			uint32_t hist_r_data_1382 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1383 14'h1814 */
	union {
		uint32_t fpga_histogram_r_data_1383; // word name
		struct {
			uint32_t hist_r_data_1383 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1384 14'h1818 */
	union {
		uint32_t fpga_histogram_r_data_1384; // word name
		struct {
			uint32_t hist_r_data_1384 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1385 14'h181C */
	union {
		uint32_t fpga_histogram_r_data_1385; // word name
		struct {
			uint32_t hist_r_data_1385 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1386 14'h1820 */
	union {
		uint32_t fpga_histogram_r_data_1386; // word name
		struct {
			uint32_t hist_r_data_1386 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1387 14'h1824 */
	union {
		uint32_t fpga_histogram_r_data_1387; // word name
		struct {
			uint32_t hist_r_data_1387 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1388 14'h1828 */
	union {
		uint32_t fpga_histogram_r_data_1388; // word name
		struct {
			uint32_t hist_r_data_1388 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1389 14'h182C */
	union {
		uint32_t fpga_histogram_r_data_1389; // word name
		struct {
			uint32_t hist_r_data_1389 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1390 14'h1830 */
	union {
		uint32_t fpga_histogram_r_data_1390; // word name
		struct {
			uint32_t hist_r_data_1390 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1391 14'h1834 */
	union {
		uint32_t fpga_histogram_r_data_1391; // word name
		struct {
			uint32_t hist_r_data_1391 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1392 14'h1838 */
	union {
		uint32_t fpga_histogram_r_data_1392; // word name
		struct {
			uint32_t hist_r_data_1392 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1393 14'h183C */
	union {
		uint32_t fpga_histogram_r_data_1393; // word name
		struct {
			uint32_t hist_r_data_1393 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1394 14'h1840 */
	union {
		uint32_t fpga_histogram_r_data_1394; // word name
		struct {
			uint32_t hist_r_data_1394 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1395 14'h1844 */
	union {
		uint32_t fpga_histogram_r_data_1395; // word name
		struct {
			uint32_t hist_r_data_1395 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1396 14'h1848 */
	union {
		uint32_t fpga_histogram_r_data_1396; // word name
		struct {
			uint32_t hist_r_data_1396 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1397 14'h184C */
	union {
		uint32_t fpga_histogram_r_data_1397; // word name
		struct {
			uint32_t hist_r_data_1397 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1398 14'h1850 */
	union {
		uint32_t fpga_histogram_r_data_1398; // word name
		struct {
			uint32_t hist_r_data_1398 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1399 14'h1854 */
	union {
		uint32_t fpga_histogram_r_data_1399; // word name
		struct {
			uint32_t hist_r_data_1399 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1400 14'h1858 */
	union {
		uint32_t fpga_histogram_r_data_1400; // word name
		struct {
			uint32_t hist_r_data_1400 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1401 14'h185C */
	union {
		uint32_t fpga_histogram_r_data_1401; // word name
		struct {
			uint32_t hist_r_data_1401 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1402 14'h1860 */
	union {
		uint32_t fpga_histogram_r_data_1402; // word name
		struct {
			uint32_t hist_r_data_1402 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1403 14'h1864 */
	union {
		uint32_t fpga_histogram_r_data_1403; // word name
		struct {
			uint32_t hist_r_data_1403 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1404 14'h1868 */
	union {
		uint32_t fpga_histogram_r_data_1404; // word name
		struct {
			uint32_t hist_r_data_1404 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1405 14'h186C */
	union {
		uint32_t fpga_histogram_r_data_1405; // word name
		struct {
			uint32_t hist_r_data_1405 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1406 14'h1870 */
	union {
		uint32_t fpga_histogram_r_data_1406; // word name
		struct {
			uint32_t hist_r_data_1406 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1407 14'h1874 */
	union {
		uint32_t fpga_histogram_r_data_1407; // word name
		struct {
			uint32_t hist_r_data_1407 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1408 14'h1878 */
	union {
		uint32_t fpga_histogram_r_data_1408; // word name
		struct {
			uint32_t hist_r_data_1408 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1409 14'h187C */
	union {
		uint32_t fpga_histogram_r_data_1409; // word name
		struct {
			uint32_t hist_r_data_1409 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1410 14'h1880 */
	union {
		uint32_t fpga_histogram_r_data_1410; // word name
		struct {
			uint32_t hist_r_data_1410 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1411 14'h1884 */
	union {
		uint32_t fpga_histogram_r_data_1411; // word name
		struct {
			uint32_t hist_r_data_1411 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1412 14'h1888 */
	union {
		uint32_t fpga_histogram_r_data_1412; // word name
		struct {
			uint32_t hist_r_data_1412 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1413 14'h188C */
	union {
		uint32_t fpga_histogram_r_data_1413; // word name
		struct {
			uint32_t hist_r_data_1413 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1414 14'h1890 */
	union {
		uint32_t fpga_histogram_r_data_1414; // word name
		struct {
			uint32_t hist_r_data_1414 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1415 14'h1894 */
	union {
		uint32_t fpga_histogram_r_data_1415; // word name
		struct {
			uint32_t hist_r_data_1415 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1416 14'h1898 */
	union {
		uint32_t fpga_histogram_r_data_1416; // word name
		struct {
			uint32_t hist_r_data_1416 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1417 14'h189C */
	union {
		uint32_t fpga_histogram_r_data_1417; // word name
		struct {
			uint32_t hist_r_data_1417 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1418 14'h18A0 */
	union {
		uint32_t fpga_histogram_r_data_1418; // word name
		struct {
			uint32_t hist_r_data_1418 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1419 14'h18A4 */
	union {
		uint32_t fpga_histogram_r_data_1419; // word name
		struct {
			uint32_t hist_r_data_1419 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1420 14'h18A8 */
	union {
		uint32_t fpga_histogram_r_data_1420; // word name
		struct {
			uint32_t hist_r_data_1420 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1421 14'h18AC */
	union {
		uint32_t fpga_histogram_r_data_1421; // word name
		struct {
			uint32_t hist_r_data_1421 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1422 14'h18B0 */
	union {
		uint32_t fpga_histogram_r_data_1422; // word name
		struct {
			uint32_t hist_r_data_1422 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1423 14'h18B4 */
	union {
		uint32_t fpga_histogram_r_data_1423; // word name
		struct {
			uint32_t hist_r_data_1423 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1424 14'h18B8 */
	union {
		uint32_t fpga_histogram_r_data_1424; // word name
		struct {
			uint32_t hist_r_data_1424 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1425 14'h18BC */
	union {
		uint32_t fpga_histogram_r_data_1425; // word name
		struct {
			uint32_t hist_r_data_1425 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1426 14'h18C0 */
	union {
		uint32_t fpga_histogram_r_data_1426; // word name
		struct {
			uint32_t hist_r_data_1426 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1427 14'h18C4 */
	union {
		uint32_t fpga_histogram_r_data_1427; // word name
		struct {
			uint32_t hist_r_data_1427 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1428 14'h18C8 */
	union {
		uint32_t fpga_histogram_r_data_1428; // word name
		struct {
			uint32_t hist_r_data_1428 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1429 14'h18CC */
	union {
		uint32_t fpga_histogram_r_data_1429; // word name
		struct {
			uint32_t hist_r_data_1429 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1430 14'h18D0 */
	union {
		uint32_t fpga_histogram_r_data_1430; // word name
		struct {
			uint32_t hist_r_data_1430 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1431 14'h18D4 */
	union {
		uint32_t fpga_histogram_r_data_1431; // word name
		struct {
			uint32_t hist_r_data_1431 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1432 14'h18D8 */
	union {
		uint32_t fpga_histogram_r_data_1432; // word name
		struct {
			uint32_t hist_r_data_1432 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1433 14'h18DC */
	union {
		uint32_t fpga_histogram_r_data_1433; // word name
		struct {
			uint32_t hist_r_data_1433 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1434 14'h18E0 */
	union {
		uint32_t fpga_histogram_r_data_1434; // word name
		struct {
			uint32_t hist_r_data_1434 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1435 14'h18E4 */
	union {
		uint32_t fpga_histogram_r_data_1435; // word name
		struct {
			uint32_t hist_r_data_1435 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1436 14'h18E8 */
	union {
		uint32_t fpga_histogram_r_data_1436; // word name
		struct {
			uint32_t hist_r_data_1436 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1437 14'h18EC */
	union {
		uint32_t fpga_histogram_r_data_1437; // word name
		struct {
			uint32_t hist_r_data_1437 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1438 14'h18F0 */
	union {
		uint32_t fpga_histogram_r_data_1438; // word name
		struct {
			uint32_t hist_r_data_1438 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1439 14'h18F4 */
	union {
		uint32_t fpga_histogram_r_data_1439; // word name
		struct {
			uint32_t hist_r_data_1439 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1440 14'h18F8 */
	union {
		uint32_t fpga_histogram_r_data_1440; // word name
		struct {
			uint32_t hist_r_data_1440 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1441 14'h18FC */
	union {
		uint32_t fpga_histogram_r_data_1441; // word name
		struct {
			uint32_t hist_r_data_1441 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1442 14'h1900 */
	union {
		uint32_t fpga_histogram_r_data_1442; // word name
		struct {
			uint32_t hist_r_data_1442 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1443 14'h1904 */
	union {
		uint32_t fpga_histogram_r_data_1443; // word name
		struct {
			uint32_t hist_r_data_1443 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1444 14'h1908 */
	union {
		uint32_t fpga_histogram_r_data_1444; // word name
		struct {
			uint32_t hist_r_data_1444 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1445 14'h190C */
	union {
		uint32_t fpga_histogram_r_data_1445; // word name
		struct {
			uint32_t hist_r_data_1445 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1446 14'h1910 */
	union {
		uint32_t fpga_histogram_r_data_1446; // word name
		struct {
			uint32_t hist_r_data_1446 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1447 14'h1914 */
	union {
		uint32_t fpga_histogram_r_data_1447; // word name
		struct {
			uint32_t hist_r_data_1447 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1448 14'h1918 */
	union {
		uint32_t fpga_histogram_r_data_1448; // word name
		struct {
			uint32_t hist_r_data_1448 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1449 14'h191C */
	union {
		uint32_t fpga_histogram_r_data_1449; // word name
		struct {
			uint32_t hist_r_data_1449 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1450 14'h1920 */
	union {
		uint32_t fpga_histogram_r_data_1450; // word name
		struct {
			uint32_t hist_r_data_1450 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1451 14'h1924 */
	union {
		uint32_t fpga_histogram_r_data_1451; // word name
		struct {
			uint32_t hist_r_data_1451 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1452 14'h1928 */
	union {
		uint32_t fpga_histogram_r_data_1452; // word name
		struct {
			uint32_t hist_r_data_1452 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1453 14'h192C */
	union {
		uint32_t fpga_histogram_r_data_1453; // word name
		struct {
			uint32_t hist_r_data_1453 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1454 14'h1930 */
	union {
		uint32_t fpga_histogram_r_data_1454; // word name
		struct {
			uint32_t hist_r_data_1454 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1455 14'h1934 */
	union {
		uint32_t fpga_histogram_r_data_1455; // word name
		struct {
			uint32_t hist_r_data_1455 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1456 14'h1938 */
	union {
		uint32_t fpga_histogram_r_data_1456; // word name
		struct {
			uint32_t hist_r_data_1456 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1457 14'h193C */
	union {
		uint32_t fpga_histogram_r_data_1457; // word name
		struct {
			uint32_t hist_r_data_1457 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1458 14'h1940 */
	union {
		uint32_t fpga_histogram_r_data_1458; // word name
		struct {
			uint32_t hist_r_data_1458 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1459 14'h1944 */
	union {
		uint32_t fpga_histogram_r_data_1459; // word name
		struct {
			uint32_t hist_r_data_1459 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1460 14'h1948 */
	union {
		uint32_t fpga_histogram_r_data_1460; // word name
		struct {
			uint32_t hist_r_data_1460 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1461 14'h194C */
	union {
		uint32_t fpga_histogram_r_data_1461; // word name
		struct {
			uint32_t hist_r_data_1461 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1462 14'h1950 */
	union {
		uint32_t fpga_histogram_r_data_1462; // word name
		struct {
			uint32_t hist_r_data_1462 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1463 14'h1954 */
	union {
		uint32_t fpga_histogram_r_data_1463; // word name
		struct {
			uint32_t hist_r_data_1463 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1464 14'h1958 */
	union {
		uint32_t fpga_histogram_r_data_1464; // word name
		struct {
			uint32_t hist_r_data_1464 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1465 14'h195C */
	union {
		uint32_t fpga_histogram_r_data_1465; // word name
		struct {
			uint32_t hist_r_data_1465 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1466 14'h1960 */
	union {
		uint32_t fpga_histogram_r_data_1466; // word name
		struct {
			uint32_t hist_r_data_1466 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1467 14'h1964 */
	union {
		uint32_t fpga_histogram_r_data_1467; // word name
		struct {
			uint32_t hist_r_data_1467 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1468 14'h1968 */
	union {
		uint32_t fpga_histogram_r_data_1468; // word name
		struct {
			uint32_t hist_r_data_1468 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1469 14'h196C */
	union {
		uint32_t fpga_histogram_r_data_1469; // word name
		struct {
			uint32_t hist_r_data_1469 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1470 14'h1970 */
	union {
		uint32_t fpga_histogram_r_data_1470; // word name
		struct {
			uint32_t hist_r_data_1470 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1471 14'h1974 */
	union {
		uint32_t fpga_histogram_r_data_1471; // word name
		struct {
			uint32_t hist_r_data_1471 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1472 14'h1978 */
	union {
		uint32_t fpga_histogram_r_data_1472; // word name
		struct {
			uint32_t hist_r_data_1472 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1473 14'h197C */
	union {
		uint32_t fpga_histogram_r_data_1473; // word name
		struct {
			uint32_t hist_r_data_1473 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1474 14'h1980 */
	union {
		uint32_t fpga_histogram_r_data_1474; // word name
		struct {
			uint32_t hist_r_data_1474 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1475 14'h1984 */
	union {
		uint32_t fpga_histogram_r_data_1475; // word name
		struct {
			uint32_t hist_r_data_1475 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1476 14'h1988 */
	union {
		uint32_t fpga_histogram_r_data_1476; // word name
		struct {
			uint32_t hist_r_data_1476 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1477 14'h198C */
	union {
		uint32_t fpga_histogram_r_data_1477; // word name
		struct {
			uint32_t hist_r_data_1477 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1478 14'h1990 */
	union {
		uint32_t fpga_histogram_r_data_1478; // word name
		struct {
			uint32_t hist_r_data_1478 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1479 14'h1994 */
	union {
		uint32_t fpga_histogram_r_data_1479; // word name
		struct {
			uint32_t hist_r_data_1479 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1480 14'h1998 */
	union {
		uint32_t fpga_histogram_r_data_1480; // word name
		struct {
			uint32_t hist_r_data_1480 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1481 14'h199C */
	union {
		uint32_t fpga_histogram_r_data_1481; // word name
		struct {
			uint32_t hist_r_data_1481 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1482 14'h19A0 */
	union {
		uint32_t fpga_histogram_r_data_1482; // word name
		struct {
			uint32_t hist_r_data_1482 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1483 14'h19A4 */
	union {
		uint32_t fpga_histogram_r_data_1483; // word name
		struct {
			uint32_t hist_r_data_1483 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1484 14'h19A8 */
	union {
		uint32_t fpga_histogram_r_data_1484; // word name
		struct {
			uint32_t hist_r_data_1484 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1485 14'h19AC */
	union {
		uint32_t fpga_histogram_r_data_1485; // word name
		struct {
			uint32_t hist_r_data_1485 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1486 14'h19B0 */
	union {
		uint32_t fpga_histogram_r_data_1486; // word name
		struct {
			uint32_t hist_r_data_1486 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1487 14'h19B4 */
	union {
		uint32_t fpga_histogram_r_data_1487; // word name
		struct {
			uint32_t hist_r_data_1487 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1488 14'h19B8 */
	union {
		uint32_t fpga_histogram_r_data_1488; // word name
		struct {
			uint32_t hist_r_data_1488 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1489 14'h19BC */
	union {
		uint32_t fpga_histogram_r_data_1489; // word name
		struct {
			uint32_t hist_r_data_1489 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1490 14'h19C0 */
	union {
		uint32_t fpga_histogram_r_data_1490; // word name
		struct {
			uint32_t hist_r_data_1490 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1491 14'h19C4 */
	union {
		uint32_t fpga_histogram_r_data_1491; // word name
		struct {
			uint32_t hist_r_data_1491 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1492 14'h19C8 */
	union {
		uint32_t fpga_histogram_r_data_1492; // word name
		struct {
			uint32_t hist_r_data_1492 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1493 14'h19CC */
	union {
		uint32_t fpga_histogram_r_data_1493; // word name
		struct {
			uint32_t hist_r_data_1493 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1494 14'h19D0 */
	union {
		uint32_t fpga_histogram_r_data_1494; // word name
		struct {
			uint32_t hist_r_data_1494 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1495 14'h19D4 */
	union {
		uint32_t fpga_histogram_r_data_1495; // word name
		struct {
			uint32_t hist_r_data_1495 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1496 14'h19D8 */
	union {
		uint32_t fpga_histogram_r_data_1496; // word name
		struct {
			uint32_t hist_r_data_1496 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1497 14'h19DC */
	union {
		uint32_t fpga_histogram_r_data_1497; // word name
		struct {
			uint32_t hist_r_data_1497 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1498 14'h19E0 */
	union {
		uint32_t fpga_histogram_r_data_1498; // word name
		struct {
			uint32_t hist_r_data_1498 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1499 14'h19E4 */
	union {
		uint32_t fpga_histogram_r_data_1499; // word name
		struct {
			uint32_t hist_r_data_1499 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1500 14'h19E8 */
	union {
		uint32_t fpga_histogram_r_data_1500; // word name
		struct {
			uint32_t hist_r_data_1500 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1501 14'h19EC */
	union {
		uint32_t fpga_histogram_r_data_1501; // word name
		struct {
			uint32_t hist_r_data_1501 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1502 14'h19F0 */
	union {
		uint32_t fpga_histogram_r_data_1502; // word name
		struct {
			uint32_t hist_r_data_1502 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1503 14'h19F4 */
	union {
		uint32_t fpga_histogram_r_data_1503; // word name
		struct {
			uint32_t hist_r_data_1503 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1504 14'h19F8 */
	union {
		uint32_t fpga_histogram_r_data_1504; // word name
		struct {
			uint32_t hist_r_data_1504 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1505 14'h19FC */
	union {
		uint32_t fpga_histogram_r_data_1505; // word name
		struct {
			uint32_t hist_r_data_1505 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1506 14'h1A00 */
	union {
		uint32_t fpga_histogram_r_data_1506; // word name
		struct {
			uint32_t hist_r_data_1506 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1507 14'h1A04 */
	union {
		uint32_t fpga_histogram_r_data_1507; // word name
		struct {
			uint32_t hist_r_data_1507 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1508 14'h1A08 */
	union {
		uint32_t fpga_histogram_r_data_1508; // word name
		struct {
			uint32_t hist_r_data_1508 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1509 14'h1A0C */
	union {
		uint32_t fpga_histogram_r_data_1509; // word name
		struct {
			uint32_t hist_r_data_1509 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1510 14'h1A10 */
	union {
		uint32_t fpga_histogram_r_data_1510; // word name
		struct {
			uint32_t hist_r_data_1510 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1511 14'h1A14 */
	union {
		uint32_t fpga_histogram_r_data_1511; // word name
		struct {
			uint32_t hist_r_data_1511 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1512 14'h1A18 */
	union {
		uint32_t fpga_histogram_r_data_1512; // word name
		struct {
			uint32_t hist_r_data_1512 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1513 14'h1A1C */
	union {
		uint32_t fpga_histogram_r_data_1513; // word name
		struct {
			uint32_t hist_r_data_1513 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1514 14'h1A20 */
	union {
		uint32_t fpga_histogram_r_data_1514; // word name
		struct {
			uint32_t hist_r_data_1514 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1515 14'h1A24 */
	union {
		uint32_t fpga_histogram_r_data_1515; // word name
		struct {
			uint32_t hist_r_data_1515 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1516 14'h1A28 */
	union {
		uint32_t fpga_histogram_r_data_1516; // word name
		struct {
			uint32_t hist_r_data_1516 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1517 14'h1A2C */
	union {
		uint32_t fpga_histogram_r_data_1517; // word name
		struct {
			uint32_t hist_r_data_1517 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1518 14'h1A30 */
	union {
		uint32_t fpga_histogram_r_data_1518; // word name
		struct {
			uint32_t hist_r_data_1518 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1519 14'h1A34 */
	union {
		uint32_t fpga_histogram_r_data_1519; // word name
		struct {
			uint32_t hist_r_data_1519 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1520 14'h1A38 */
	union {
		uint32_t fpga_histogram_r_data_1520; // word name
		struct {
			uint32_t hist_r_data_1520 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1521 14'h1A3C */
	union {
		uint32_t fpga_histogram_r_data_1521; // word name
		struct {
			uint32_t hist_r_data_1521 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1522 14'h1A40 */
	union {
		uint32_t fpga_histogram_r_data_1522; // word name
		struct {
			uint32_t hist_r_data_1522 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1523 14'h1A44 */
	union {
		uint32_t fpga_histogram_r_data_1523; // word name
		struct {
			uint32_t hist_r_data_1523 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1524 14'h1A48 */
	union {
		uint32_t fpga_histogram_r_data_1524; // word name
		struct {
			uint32_t hist_r_data_1524 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1525 14'h1A4C */
	union {
		uint32_t fpga_histogram_r_data_1525; // word name
		struct {
			uint32_t hist_r_data_1525 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1526 14'h1A50 */
	union {
		uint32_t fpga_histogram_r_data_1526; // word name
		struct {
			uint32_t hist_r_data_1526 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1527 14'h1A54 */
	union {
		uint32_t fpga_histogram_r_data_1527; // word name
		struct {
			uint32_t hist_r_data_1527 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1528 14'h1A58 */
	union {
		uint32_t fpga_histogram_r_data_1528; // word name
		struct {
			uint32_t hist_r_data_1528 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1529 14'h1A5C */
	union {
		uint32_t fpga_histogram_r_data_1529; // word name
		struct {
			uint32_t hist_r_data_1529 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1530 14'h1A60 */
	union {
		uint32_t fpga_histogram_r_data_1530; // word name
		struct {
			uint32_t hist_r_data_1530 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1531 14'h1A64 */
	union {
		uint32_t fpga_histogram_r_data_1531; // word name
		struct {
			uint32_t hist_r_data_1531 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1532 14'h1A68 */
	union {
		uint32_t fpga_histogram_r_data_1532; // word name
		struct {
			uint32_t hist_r_data_1532 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1533 14'h1A6C */
	union {
		uint32_t fpga_histogram_r_data_1533; // word name
		struct {
			uint32_t hist_r_data_1533 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1534 14'h1A70 */
	union {
		uint32_t fpga_histogram_r_data_1534; // word name
		struct {
			uint32_t hist_r_data_1534 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1535 14'h1A74 */
	union {
		uint32_t fpga_histogram_r_data_1535; // word name
		struct {
			uint32_t hist_r_data_1535 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1536 14'h1A78 */
	union {
		uint32_t fpga_histogram_r_data_1536; // word name
		struct {
			uint32_t hist_r_data_1536 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1537 14'h1A7C */
	union {
		uint32_t fpga_histogram_r_data_1537; // word name
		struct {
			uint32_t hist_r_data_1537 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1538 14'h1A80 */
	union {
		uint32_t fpga_histogram_r_data_1538; // word name
		struct {
			uint32_t hist_r_data_1538 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1539 14'h1A84 */
	union {
		uint32_t fpga_histogram_r_data_1539; // word name
		struct {
			uint32_t hist_r_data_1539 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1540 14'h1A88 */
	union {
		uint32_t fpga_histogram_r_data_1540; // word name
		struct {
			uint32_t hist_r_data_1540 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1541 14'h1A8C */
	union {
		uint32_t fpga_histogram_r_data_1541; // word name
		struct {
			uint32_t hist_r_data_1541 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1542 14'h1A90 */
	union {
		uint32_t fpga_histogram_r_data_1542; // word name
		struct {
			uint32_t hist_r_data_1542 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1543 14'h1A94 */
	union {
		uint32_t fpga_histogram_r_data_1543; // word name
		struct {
			uint32_t hist_r_data_1543 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1544 14'h1A98 */
	union {
		uint32_t fpga_histogram_r_data_1544; // word name
		struct {
			uint32_t hist_r_data_1544 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1545 14'h1A9C */
	union {
		uint32_t fpga_histogram_r_data_1545; // word name
		struct {
			uint32_t hist_r_data_1545 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1546 14'h1AA0 */
	union {
		uint32_t fpga_histogram_r_data_1546; // word name
		struct {
			uint32_t hist_r_data_1546 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1547 14'h1AA4 */
	union {
		uint32_t fpga_histogram_r_data_1547; // word name
		struct {
			uint32_t hist_r_data_1547 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1548 14'h1AA8 */
	union {
		uint32_t fpga_histogram_r_data_1548; // word name
		struct {
			uint32_t hist_r_data_1548 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1549 14'h1AAC */
	union {
		uint32_t fpga_histogram_r_data_1549; // word name
		struct {
			uint32_t hist_r_data_1549 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1550 14'h1AB0 */
	union {
		uint32_t fpga_histogram_r_data_1550; // word name
		struct {
			uint32_t hist_r_data_1550 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1551 14'h1AB4 */
	union {
		uint32_t fpga_histogram_r_data_1551; // word name
		struct {
			uint32_t hist_r_data_1551 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1552 14'h1AB8 */
	union {
		uint32_t fpga_histogram_r_data_1552; // word name
		struct {
			uint32_t hist_r_data_1552 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1553 14'h1ABC */
	union {
		uint32_t fpga_histogram_r_data_1553; // word name
		struct {
			uint32_t hist_r_data_1553 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1554 14'h1AC0 */
	union {
		uint32_t fpga_histogram_r_data_1554; // word name
		struct {
			uint32_t hist_r_data_1554 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1555 14'h1AC4 */
	union {
		uint32_t fpga_histogram_r_data_1555; // word name
		struct {
			uint32_t hist_r_data_1555 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1556 14'h1AC8 */
	union {
		uint32_t fpga_histogram_r_data_1556; // word name
		struct {
			uint32_t hist_r_data_1556 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1557 14'h1ACC */
	union {
		uint32_t fpga_histogram_r_data_1557; // word name
		struct {
			uint32_t hist_r_data_1557 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1558 14'h1AD0 */
	union {
		uint32_t fpga_histogram_r_data_1558; // word name
		struct {
			uint32_t hist_r_data_1558 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1559 14'h1AD4 */
	union {
		uint32_t fpga_histogram_r_data_1559; // word name
		struct {
			uint32_t hist_r_data_1559 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1560 14'h1AD8 */
	union {
		uint32_t fpga_histogram_r_data_1560; // word name
		struct {
			uint32_t hist_r_data_1560 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1561 14'h1ADC */
	union {
		uint32_t fpga_histogram_r_data_1561; // word name
		struct {
			uint32_t hist_r_data_1561 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1562 14'h1AE0 */
	union {
		uint32_t fpga_histogram_r_data_1562; // word name
		struct {
			uint32_t hist_r_data_1562 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1563 14'h1AE4 */
	union {
		uint32_t fpga_histogram_r_data_1563; // word name
		struct {
			uint32_t hist_r_data_1563 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1564 14'h1AE8 */
	union {
		uint32_t fpga_histogram_r_data_1564; // word name
		struct {
			uint32_t hist_r_data_1564 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1565 14'h1AEC */
	union {
		uint32_t fpga_histogram_r_data_1565; // word name
		struct {
			uint32_t hist_r_data_1565 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1566 14'h1AF0 */
	union {
		uint32_t fpga_histogram_r_data_1566; // word name
		struct {
			uint32_t hist_r_data_1566 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1567 14'h1AF4 */
	union {
		uint32_t fpga_histogram_r_data_1567; // word name
		struct {
			uint32_t hist_r_data_1567 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1568 14'h1AF8 */
	union {
		uint32_t fpga_histogram_r_data_1568; // word name
		struct {
			uint32_t hist_r_data_1568 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1569 14'h1AFC */
	union {
		uint32_t fpga_histogram_r_data_1569; // word name
		struct {
			uint32_t hist_r_data_1569 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1570 14'h1B00 */
	union {
		uint32_t fpga_histogram_r_data_1570; // word name
		struct {
			uint32_t hist_r_data_1570 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1571 14'h1B04 */
	union {
		uint32_t fpga_histogram_r_data_1571; // word name
		struct {
			uint32_t hist_r_data_1571 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1572 14'h1B08 */
	union {
		uint32_t fpga_histogram_r_data_1572; // word name
		struct {
			uint32_t hist_r_data_1572 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1573 14'h1B0C */
	union {
		uint32_t fpga_histogram_r_data_1573; // word name
		struct {
			uint32_t hist_r_data_1573 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1574 14'h1B10 */
	union {
		uint32_t fpga_histogram_r_data_1574; // word name
		struct {
			uint32_t hist_r_data_1574 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1575 14'h1B14 */
	union {
		uint32_t fpga_histogram_r_data_1575; // word name
		struct {
			uint32_t hist_r_data_1575 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1576 14'h1B18 */
	union {
		uint32_t fpga_histogram_r_data_1576; // word name
		struct {
			uint32_t hist_r_data_1576 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1577 14'h1B1C */
	union {
		uint32_t fpga_histogram_r_data_1577; // word name
		struct {
			uint32_t hist_r_data_1577 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1578 14'h1B20 */
	union {
		uint32_t fpga_histogram_r_data_1578; // word name
		struct {
			uint32_t hist_r_data_1578 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1579 14'h1B24 */
	union {
		uint32_t fpga_histogram_r_data_1579; // word name
		struct {
			uint32_t hist_r_data_1579 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1580 14'h1B28 */
	union {
		uint32_t fpga_histogram_r_data_1580; // word name
		struct {
			uint32_t hist_r_data_1580 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1581 14'h1B2C */
	union {
		uint32_t fpga_histogram_r_data_1581; // word name
		struct {
			uint32_t hist_r_data_1581 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1582 14'h1B30 */
	union {
		uint32_t fpga_histogram_r_data_1582; // word name
		struct {
			uint32_t hist_r_data_1582 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1583 14'h1B34 */
	union {
		uint32_t fpga_histogram_r_data_1583; // word name
		struct {
			uint32_t hist_r_data_1583 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1584 14'h1B38 */
	union {
		uint32_t fpga_histogram_r_data_1584; // word name
		struct {
			uint32_t hist_r_data_1584 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1585 14'h1B3C */
	union {
		uint32_t fpga_histogram_r_data_1585; // word name
		struct {
			uint32_t hist_r_data_1585 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1586 14'h1B40 */
	union {
		uint32_t fpga_histogram_r_data_1586; // word name
		struct {
			uint32_t hist_r_data_1586 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1587 14'h1B44 */
	union {
		uint32_t fpga_histogram_r_data_1587; // word name
		struct {
			uint32_t hist_r_data_1587 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1588 14'h1B48 */
	union {
		uint32_t fpga_histogram_r_data_1588; // word name
		struct {
			uint32_t hist_r_data_1588 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1589 14'h1B4C */
	union {
		uint32_t fpga_histogram_r_data_1589; // word name
		struct {
			uint32_t hist_r_data_1589 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1590 14'h1B50 */
	union {
		uint32_t fpga_histogram_r_data_1590; // word name
		struct {
			uint32_t hist_r_data_1590 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1591 14'h1B54 */
	union {
		uint32_t fpga_histogram_r_data_1591; // word name
		struct {
			uint32_t hist_r_data_1591 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1592 14'h1B58 */
	union {
		uint32_t fpga_histogram_r_data_1592; // word name
		struct {
			uint32_t hist_r_data_1592 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1593 14'h1B5C */
	union {
		uint32_t fpga_histogram_r_data_1593; // word name
		struct {
			uint32_t hist_r_data_1593 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1594 14'h1B60 */
	union {
		uint32_t fpga_histogram_r_data_1594; // word name
		struct {
			uint32_t hist_r_data_1594 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1595 14'h1B64 */
	union {
		uint32_t fpga_histogram_r_data_1595; // word name
		struct {
			uint32_t hist_r_data_1595 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1596 14'h1B68 */
	union {
		uint32_t fpga_histogram_r_data_1596; // word name
		struct {
			uint32_t hist_r_data_1596 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1597 14'h1B6C */
	union {
		uint32_t fpga_histogram_r_data_1597; // word name
		struct {
			uint32_t hist_r_data_1597 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1598 14'h1B70 */
	union {
		uint32_t fpga_histogram_r_data_1598; // word name
		struct {
			uint32_t hist_r_data_1598 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1599 14'h1B74 */
	union {
		uint32_t fpga_histogram_r_data_1599; // word name
		struct {
			uint32_t hist_r_data_1599 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1600 14'h1B78 */
	union {
		uint32_t fpga_histogram_r_data_1600; // word name
		struct {
			uint32_t hist_r_data_1600 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1601 14'h1B7C */
	union {
		uint32_t fpga_histogram_r_data_1601; // word name
		struct {
			uint32_t hist_r_data_1601 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1602 14'h1B80 */
	union {
		uint32_t fpga_histogram_r_data_1602; // word name
		struct {
			uint32_t hist_r_data_1602 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1603 14'h1B84 */
	union {
		uint32_t fpga_histogram_r_data_1603; // word name
		struct {
			uint32_t hist_r_data_1603 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1604 14'h1B88 */
	union {
		uint32_t fpga_histogram_r_data_1604; // word name
		struct {
			uint32_t hist_r_data_1604 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1605 14'h1B8C */
	union {
		uint32_t fpga_histogram_r_data_1605; // word name
		struct {
			uint32_t hist_r_data_1605 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1606 14'h1B90 */
	union {
		uint32_t fpga_histogram_r_data_1606; // word name
		struct {
			uint32_t hist_r_data_1606 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1607 14'h1B94 */
	union {
		uint32_t fpga_histogram_r_data_1607; // word name
		struct {
			uint32_t hist_r_data_1607 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1608 14'h1B98 */
	union {
		uint32_t fpga_histogram_r_data_1608; // word name
		struct {
			uint32_t hist_r_data_1608 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1609 14'h1B9C */
	union {
		uint32_t fpga_histogram_r_data_1609; // word name
		struct {
			uint32_t hist_r_data_1609 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1610 14'h1BA0 */
	union {
		uint32_t fpga_histogram_r_data_1610; // word name
		struct {
			uint32_t hist_r_data_1610 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1611 14'h1BA4 */
	union {
		uint32_t fpga_histogram_r_data_1611; // word name
		struct {
			uint32_t hist_r_data_1611 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1612 14'h1BA8 */
	union {
		uint32_t fpga_histogram_r_data_1612; // word name
		struct {
			uint32_t hist_r_data_1612 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1613 14'h1BAC */
	union {
		uint32_t fpga_histogram_r_data_1613; // word name
		struct {
			uint32_t hist_r_data_1613 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1614 14'h1BB0 */
	union {
		uint32_t fpga_histogram_r_data_1614; // word name
		struct {
			uint32_t hist_r_data_1614 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1615 14'h1BB4 */
	union {
		uint32_t fpga_histogram_r_data_1615; // word name
		struct {
			uint32_t hist_r_data_1615 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1616 14'h1BB8 */
	union {
		uint32_t fpga_histogram_r_data_1616; // word name
		struct {
			uint32_t hist_r_data_1616 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1617 14'h1BBC */
	union {
		uint32_t fpga_histogram_r_data_1617; // word name
		struct {
			uint32_t hist_r_data_1617 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1618 14'h1BC0 */
	union {
		uint32_t fpga_histogram_r_data_1618; // word name
		struct {
			uint32_t hist_r_data_1618 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1619 14'h1BC4 */
	union {
		uint32_t fpga_histogram_r_data_1619; // word name
		struct {
			uint32_t hist_r_data_1619 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1620 14'h1BC8 */
	union {
		uint32_t fpga_histogram_r_data_1620; // word name
		struct {
			uint32_t hist_r_data_1620 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1621 14'h1BCC */
	union {
		uint32_t fpga_histogram_r_data_1621; // word name
		struct {
			uint32_t hist_r_data_1621 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1622 14'h1BD0 */
	union {
		uint32_t fpga_histogram_r_data_1622; // word name
		struct {
			uint32_t hist_r_data_1622 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1623 14'h1BD4 */
	union {
		uint32_t fpga_histogram_r_data_1623; // word name
		struct {
			uint32_t hist_r_data_1623 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1624 14'h1BD8 */
	union {
		uint32_t fpga_histogram_r_data_1624; // word name
		struct {
			uint32_t hist_r_data_1624 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1625 14'h1BDC */
	union {
		uint32_t fpga_histogram_r_data_1625; // word name
		struct {
			uint32_t hist_r_data_1625 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1626 14'h1BE0 */
	union {
		uint32_t fpga_histogram_r_data_1626; // word name
		struct {
			uint32_t hist_r_data_1626 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1627 14'h1BE4 */
	union {
		uint32_t fpga_histogram_r_data_1627; // word name
		struct {
			uint32_t hist_r_data_1627 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1628 14'h1BE8 */
	union {
		uint32_t fpga_histogram_r_data_1628; // word name
		struct {
			uint32_t hist_r_data_1628 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1629 14'h1BEC */
	union {
		uint32_t fpga_histogram_r_data_1629; // word name
		struct {
			uint32_t hist_r_data_1629 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1630 14'h1BF0 */
	union {
		uint32_t fpga_histogram_r_data_1630; // word name
		struct {
			uint32_t hist_r_data_1630 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1631 14'h1BF4 */
	union {
		uint32_t fpga_histogram_r_data_1631; // word name
		struct {
			uint32_t hist_r_data_1631 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1632 14'h1BF8 */
	union {
		uint32_t fpga_histogram_r_data_1632; // word name
		struct {
			uint32_t hist_r_data_1632 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1633 14'h1BFC */
	union {
		uint32_t fpga_histogram_r_data_1633; // word name
		struct {
			uint32_t hist_r_data_1633 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1634 14'h1C00 */
	union {
		uint32_t fpga_histogram_r_data_1634; // word name
		struct {
			uint32_t hist_r_data_1634 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1635 14'h1C04 */
	union {
		uint32_t fpga_histogram_r_data_1635; // word name
		struct {
			uint32_t hist_r_data_1635 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1636 14'h1C08 */
	union {
		uint32_t fpga_histogram_r_data_1636; // word name
		struct {
			uint32_t hist_r_data_1636 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1637 14'h1C0C */
	union {
		uint32_t fpga_histogram_r_data_1637; // word name
		struct {
			uint32_t hist_r_data_1637 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1638 14'h1C10 */
	union {
		uint32_t fpga_histogram_r_data_1638; // word name
		struct {
			uint32_t hist_r_data_1638 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1639 14'h1C14 */
	union {
		uint32_t fpga_histogram_r_data_1639; // word name
		struct {
			uint32_t hist_r_data_1639 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1640 14'h1C18 */
	union {
		uint32_t fpga_histogram_r_data_1640; // word name
		struct {
			uint32_t hist_r_data_1640 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1641 14'h1C1C */
	union {
		uint32_t fpga_histogram_r_data_1641; // word name
		struct {
			uint32_t hist_r_data_1641 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1642 14'h1C20 */
	union {
		uint32_t fpga_histogram_r_data_1642; // word name
		struct {
			uint32_t hist_r_data_1642 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1643 14'h1C24 */
	union {
		uint32_t fpga_histogram_r_data_1643; // word name
		struct {
			uint32_t hist_r_data_1643 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1644 14'h1C28 */
	union {
		uint32_t fpga_histogram_r_data_1644; // word name
		struct {
			uint32_t hist_r_data_1644 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1645 14'h1C2C */
	union {
		uint32_t fpga_histogram_r_data_1645; // word name
		struct {
			uint32_t hist_r_data_1645 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1646 14'h1C30 */
	union {
		uint32_t fpga_histogram_r_data_1646; // word name
		struct {
			uint32_t hist_r_data_1646 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1647 14'h1C34 */
	union {
		uint32_t fpga_histogram_r_data_1647; // word name
		struct {
			uint32_t hist_r_data_1647 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1648 14'h1C38 */
	union {
		uint32_t fpga_histogram_r_data_1648; // word name
		struct {
			uint32_t hist_r_data_1648 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1649 14'h1C3C */
	union {
		uint32_t fpga_histogram_r_data_1649; // word name
		struct {
			uint32_t hist_r_data_1649 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1650 14'h1C40 */
	union {
		uint32_t fpga_histogram_r_data_1650; // word name
		struct {
			uint32_t hist_r_data_1650 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1651 14'h1C44 */
	union {
		uint32_t fpga_histogram_r_data_1651; // word name
		struct {
			uint32_t hist_r_data_1651 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1652 14'h1C48 */
	union {
		uint32_t fpga_histogram_r_data_1652; // word name
		struct {
			uint32_t hist_r_data_1652 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1653 14'h1C4C */
	union {
		uint32_t fpga_histogram_r_data_1653; // word name
		struct {
			uint32_t hist_r_data_1653 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1654 14'h1C50 */
	union {
		uint32_t fpga_histogram_r_data_1654; // word name
		struct {
			uint32_t hist_r_data_1654 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1655 14'h1C54 */
	union {
		uint32_t fpga_histogram_r_data_1655; // word name
		struct {
			uint32_t hist_r_data_1655 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1656 14'h1C58 */
	union {
		uint32_t fpga_histogram_r_data_1656; // word name
		struct {
			uint32_t hist_r_data_1656 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1657 14'h1C5C */
	union {
		uint32_t fpga_histogram_r_data_1657; // word name
		struct {
			uint32_t hist_r_data_1657 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1658 14'h1C60 */
	union {
		uint32_t fpga_histogram_r_data_1658; // word name
		struct {
			uint32_t hist_r_data_1658 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1659 14'h1C64 */
	union {
		uint32_t fpga_histogram_r_data_1659; // word name
		struct {
			uint32_t hist_r_data_1659 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1660 14'h1C68 */
	union {
		uint32_t fpga_histogram_r_data_1660; // word name
		struct {
			uint32_t hist_r_data_1660 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1661 14'h1C6C */
	union {
		uint32_t fpga_histogram_r_data_1661; // word name
		struct {
			uint32_t hist_r_data_1661 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1662 14'h1C70 */
	union {
		uint32_t fpga_histogram_r_data_1662; // word name
		struct {
			uint32_t hist_r_data_1662 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1663 14'h1C74 */
	union {
		uint32_t fpga_histogram_r_data_1663; // word name
		struct {
			uint32_t hist_r_data_1663 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1664 14'h1C78 */
	union {
		uint32_t fpga_histogram_r_data_1664; // word name
		struct {
			uint32_t hist_r_data_1664 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1665 14'h1C7C */
	union {
		uint32_t fpga_histogram_r_data_1665; // word name
		struct {
			uint32_t hist_r_data_1665 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1666 14'h1C80 */
	union {
		uint32_t fpga_histogram_r_data_1666; // word name
		struct {
			uint32_t hist_r_data_1666 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1667 14'h1C84 */
	union {
		uint32_t fpga_histogram_r_data_1667; // word name
		struct {
			uint32_t hist_r_data_1667 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1668 14'h1C88 */
	union {
		uint32_t fpga_histogram_r_data_1668; // word name
		struct {
			uint32_t hist_r_data_1668 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1669 14'h1C8C */
	union {
		uint32_t fpga_histogram_r_data_1669; // word name
		struct {
			uint32_t hist_r_data_1669 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1670 14'h1C90 */
	union {
		uint32_t fpga_histogram_r_data_1670; // word name
		struct {
			uint32_t hist_r_data_1670 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1671 14'h1C94 */
	union {
		uint32_t fpga_histogram_r_data_1671; // word name
		struct {
			uint32_t hist_r_data_1671 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1672 14'h1C98 */
	union {
		uint32_t fpga_histogram_r_data_1672; // word name
		struct {
			uint32_t hist_r_data_1672 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1673 14'h1C9C */
	union {
		uint32_t fpga_histogram_r_data_1673; // word name
		struct {
			uint32_t hist_r_data_1673 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1674 14'h1CA0 */
	union {
		uint32_t fpga_histogram_r_data_1674; // word name
		struct {
			uint32_t hist_r_data_1674 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1675 14'h1CA4 */
	union {
		uint32_t fpga_histogram_r_data_1675; // word name
		struct {
			uint32_t hist_r_data_1675 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1676 14'h1CA8 */
	union {
		uint32_t fpga_histogram_r_data_1676; // word name
		struct {
			uint32_t hist_r_data_1676 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1677 14'h1CAC */
	union {
		uint32_t fpga_histogram_r_data_1677; // word name
		struct {
			uint32_t hist_r_data_1677 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1678 14'h1CB0 */
	union {
		uint32_t fpga_histogram_r_data_1678; // word name
		struct {
			uint32_t hist_r_data_1678 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1679 14'h1CB4 */
	union {
		uint32_t fpga_histogram_r_data_1679; // word name
		struct {
			uint32_t hist_r_data_1679 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1680 14'h1CB8 */
	union {
		uint32_t fpga_histogram_r_data_1680; // word name
		struct {
			uint32_t hist_r_data_1680 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1681 14'h1CBC */
	union {
		uint32_t fpga_histogram_r_data_1681; // word name
		struct {
			uint32_t hist_r_data_1681 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1682 14'h1CC0 */
	union {
		uint32_t fpga_histogram_r_data_1682; // word name
		struct {
			uint32_t hist_r_data_1682 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1683 14'h1CC4 */
	union {
		uint32_t fpga_histogram_r_data_1683; // word name
		struct {
			uint32_t hist_r_data_1683 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1684 14'h1CC8 */
	union {
		uint32_t fpga_histogram_r_data_1684; // word name
		struct {
			uint32_t hist_r_data_1684 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1685 14'h1CCC */
	union {
		uint32_t fpga_histogram_r_data_1685; // word name
		struct {
			uint32_t hist_r_data_1685 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1686 14'h1CD0 */
	union {
		uint32_t fpga_histogram_r_data_1686; // word name
		struct {
			uint32_t hist_r_data_1686 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1687 14'h1CD4 */
	union {
		uint32_t fpga_histogram_r_data_1687; // word name
		struct {
			uint32_t hist_r_data_1687 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1688 14'h1CD8 */
	union {
		uint32_t fpga_histogram_r_data_1688; // word name
		struct {
			uint32_t hist_r_data_1688 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1689 14'h1CDC */
	union {
		uint32_t fpga_histogram_r_data_1689; // word name
		struct {
			uint32_t hist_r_data_1689 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1690 14'h1CE0 */
	union {
		uint32_t fpga_histogram_r_data_1690; // word name
		struct {
			uint32_t hist_r_data_1690 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1691 14'h1CE4 */
	union {
		uint32_t fpga_histogram_r_data_1691; // word name
		struct {
			uint32_t hist_r_data_1691 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1692 14'h1CE8 */
	union {
		uint32_t fpga_histogram_r_data_1692; // word name
		struct {
			uint32_t hist_r_data_1692 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1693 14'h1CEC */
	union {
		uint32_t fpga_histogram_r_data_1693; // word name
		struct {
			uint32_t hist_r_data_1693 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1694 14'h1CF0 */
	union {
		uint32_t fpga_histogram_r_data_1694; // word name
		struct {
			uint32_t hist_r_data_1694 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1695 14'h1CF4 */
	union {
		uint32_t fpga_histogram_r_data_1695; // word name
		struct {
			uint32_t hist_r_data_1695 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1696 14'h1CF8 */
	union {
		uint32_t fpga_histogram_r_data_1696; // word name
		struct {
			uint32_t hist_r_data_1696 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1697 14'h1CFC */
	union {
		uint32_t fpga_histogram_r_data_1697; // word name
		struct {
			uint32_t hist_r_data_1697 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1698 14'h1D00 */
	union {
		uint32_t fpga_histogram_r_data_1698; // word name
		struct {
			uint32_t hist_r_data_1698 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1699 14'h1D04 */
	union {
		uint32_t fpga_histogram_r_data_1699; // word name
		struct {
			uint32_t hist_r_data_1699 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1700 14'h1D08 */
	union {
		uint32_t fpga_histogram_r_data_1700; // word name
		struct {
			uint32_t hist_r_data_1700 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1701 14'h1D0C */
	union {
		uint32_t fpga_histogram_r_data_1701; // word name
		struct {
			uint32_t hist_r_data_1701 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1702 14'h1D10 */
	union {
		uint32_t fpga_histogram_r_data_1702; // word name
		struct {
			uint32_t hist_r_data_1702 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1703 14'h1D14 */
	union {
		uint32_t fpga_histogram_r_data_1703; // word name
		struct {
			uint32_t hist_r_data_1703 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1704 14'h1D18 */
	union {
		uint32_t fpga_histogram_r_data_1704; // word name
		struct {
			uint32_t hist_r_data_1704 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1705 14'h1D1C */
	union {
		uint32_t fpga_histogram_r_data_1705; // word name
		struct {
			uint32_t hist_r_data_1705 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1706 14'h1D20 */
	union {
		uint32_t fpga_histogram_r_data_1706; // word name
		struct {
			uint32_t hist_r_data_1706 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1707 14'h1D24 */
	union {
		uint32_t fpga_histogram_r_data_1707; // word name
		struct {
			uint32_t hist_r_data_1707 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1708 14'h1D28 */
	union {
		uint32_t fpga_histogram_r_data_1708; // word name
		struct {
			uint32_t hist_r_data_1708 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1709 14'h1D2C */
	union {
		uint32_t fpga_histogram_r_data_1709; // word name
		struct {
			uint32_t hist_r_data_1709 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1710 14'h1D30 */
	union {
		uint32_t fpga_histogram_r_data_1710; // word name
		struct {
			uint32_t hist_r_data_1710 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1711 14'h1D34 */
	union {
		uint32_t fpga_histogram_r_data_1711; // word name
		struct {
			uint32_t hist_r_data_1711 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1712 14'h1D38 */
	union {
		uint32_t fpga_histogram_r_data_1712; // word name
		struct {
			uint32_t hist_r_data_1712 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1713 14'h1D3C */
	union {
		uint32_t fpga_histogram_r_data_1713; // word name
		struct {
			uint32_t hist_r_data_1713 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1714 14'h1D40 */
	union {
		uint32_t fpga_histogram_r_data_1714; // word name
		struct {
			uint32_t hist_r_data_1714 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1715 14'h1D44 */
	union {
		uint32_t fpga_histogram_r_data_1715; // word name
		struct {
			uint32_t hist_r_data_1715 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1716 14'h1D48 */
	union {
		uint32_t fpga_histogram_r_data_1716; // word name
		struct {
			uint32_t hist_r_data_1716 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1717 14'h1D4C */
	union {
		uint32_t fpga_histogram_r_data_1717; // word name
		struct {
			uint32_t hist_r_data_1717 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1718 14'h1D50 */
	union {
		uint32_t fpga_histogram_r_data_1718; // word name
		struct {
			uint32_t hist_r_data_1718 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1719 14'h1D54 */
	union {
		uint32_t fpga_histogram_r_data_1719; // word name
		struct {
			uint32_t hist_r_data_1719 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1720 14'h1D58 */
	union {
		uint32_t fpga_histogram_r_data_1720; // word name
		struct {
			uint32_t hist_r_data_1720 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1721 14'h1D5C */
	union {
		uint32_t fpga_histogram_r_data_1721; // word name
		struct {
			uint32_t hist_r_data_1721 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1722 14'h1D60 */
	union {
		uint32_t fpga_histogram_r_data_1722; // word name
		struct {
			uint32_t hist_r_data_1722 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1723 14'h1D64 */
	union {
		uint32_t fpga_histogram_r_data_1723; // word name
		struct {
			uint32_t hist_r_data_1723 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1724 14'h1D68 */
	union {
		uint32_t fpga_histogram_r_data_1724; // word name
		struct {
			uint32_t hist_r_data_1724 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1725 14'h1D6C */
	union {
		uint32_t fpga_histogram_r_data_1725; // word name
		struct {
			uint32_t hist_r_data_1725 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1726 14'h1D70 */
	union {
		uint32_t fpga_histogram_r_data_1726; // word name
		struct {
			uint32_t hist_r_data_1726 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1727 14'h1D74 */
	union {
		uint32_t fpga_histogram_r_data_1727; // word name
		struct {
			uint32_t hist_r_data_1727 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1728 14'h1D78 */
	union {
		uint32_t fpga_histogram_r_data_1728; // word name
		struct {
			uint32_t hist_r_data_1728 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1729 14'h1D7C */
	union {
		uint32_t fpga_histogram_r_data_1729; // word name
		struct {
			uint32_t hist_r_data_1729 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1730 14'h1D80 */
	union {
		uint32_t fpga_histogram_r_data_1730; // word name
		struct {
			uint32_t hist_r_data_1730 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1731 14'h1D84 */
	union {
		uint32_t fpga_histogram_r_data_1731; // word name
		struct {
			uint32_t hist_r_data_1731 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1732 14'h1D88 */
	union {
		uint32_t fpga_histogram_r_data_1732; // word name
		struct {
			uint32_t hist_r_data_1732 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1733 14'h1D8C */
	union {
		uint32_t fpga_histogram_r_data_1733; // word name
		struct {
			uint32_t hist_r_data_1733 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1734 14'h1D90 */
	union {
		uint32_t fpga_histogram_r_data_1734; // word name
		struct {
			uint32_t hist_r_data_1734 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1735 14'h1D94 */
	union {
		uint32_t fpga_histogram_r_data_1735; // word name
		struct {
			uint32_t hist_r_data_1735 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1736 14'h1D98 */
	union {
		uint32_t fpga_histogram_r_data_1736; // word name
		struct {
			uint32_t hist_r_data_1736 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1737 14'h1D9C */
	union {
		uint32_t fpga_histogram_r_data_1737; // word name
		struct {
			uint32_t hist_r_data_1737 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1738 14'h1DA0 */
	union {
		uint32_t fpga_histogram_r_data_1738; // word name
		struct {
			uint32_t hist_r_data_1738 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1739 14'h1DA4 */
	union {
		uint32_t fpga_histogram_r_data_1739; // word name
		struct {
			uint32_t hist_r_data_1739 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1740 14'h1DA8 */
	union {
		uint32_t fpga_histogram_r_data_1740; // word name
		struct {
			uint32_t hist_r_data_1740 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1741 14'h1DAC */
	union {
		uint32_t fpga_histogram_r_data_1741; // word name
		struct {
			uint32_t hist_r_data_1741 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1742 14'h1DB0 */
	union {
		uint32_t fpga_histogram_r_data_1742; // word name
		struct {
			uint32_t hist_r_data_1742 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1743 14'h1DB4 */
	union {
		uint32_t fpga_histogram_r_data_1743; // word name
		struct {
			uint32_t hist_r_data_1743 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1744 14'h1DB8 */
	union {
		uint32_t fpga_histogram_r_data_1744; // word name
		struct {
			uint32_t hist_r_data_1744 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1745 14'h1DBC */
	union {
		uint32_t fpga_histogram_r_data_1745; // word name
		struct {
			uint32_t hist_r_data_1745 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1746 14'h1DC0 */
	union {
		uint32_t fpga_histogram_r_data_1746; // word name
		struct {
			uint32_t hist_r_data_1746 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1747 14'h1DC4 */
	union {
		uint32_t fpga_histogram_r_data_1747; // word name
		struct {
			uint32_t hist_r_data_1747 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1748 14'h1DC8 */
	union {
		uint32_t fpga_histogram_r_data_1748; // word name
		struct {
			uint32_t hist_r_data_1748 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1749 14'h1DCC */
	union {
		uint32_t fpga_histogram_r_data_1749; // word name
		struct {
			uint32_t hist_r_data_1749 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1750 14'h1DD0 */
	union {
		uint32_t fpga_histogram_r_data_1750; // word name
		struct {
			uint32_t hist_r_data_1750 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1751 14'h1DD4 */
	union {
		uint32_t fpga_histogram_r_data_1751; // word name
		struct {
			uint32_t hist_r_data_1751 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1752 14'h1DD8 */
	union {
		uint32_t fpga_histogram_r_data_1752; // word name
		struct {
			uint32_t hist_r_data_1752 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1753 14'h1DDC */
	union {
		uint32_t fpga_histogram_r_data_1753; // word name
		struct {
			uint32_t hist_r_data_1753 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1754 14'h1DE0 */
	union {
		uint32_t fpga_histogram_r_data_1754; // word name
		struct {
			uint32_t hist_r_data_1754 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1755 14'h1DE4 */
	union {
		uint32_t fpga_histogram_r_data_1755; // word name
		struct {
			uint32_t hist_r_data_1755 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1756 14'h1DE8 */
	union {
		uint32_t fpga_histogram_r_data_1756; // word name
		struct {
			uint32_t hist_r_data_1756 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1757 14'h1DEC */
	union {
		uint32_t fpga_histogram_r_data_1757; // word name
		struct {
			uint32_t hist_r_data_1757 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1758 14'h1DF0 */
	union {
		uint32_t fpga_histogram_r_data_1758; // word name
		struct {
			uint32_t hist_r_data_1758 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1759 14'h1DF4 */
	union {
		uint32_t fpga_histogram_r_data_1759; // word name
		struct {
			uint32_t hist_r_data_1759 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1760 14'h1DF8 */
	union {
		uint32_t fpga_histogram_r_data_1760; // word name
		struct {
			uint32_t hist_r_data_1760 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1761 14'h1DFC */
	union {
		uint32_t fpga_histogram_r_data_1761; // word name
		struct {
			uint32_t hist_r_data_1761 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1762 14'h1E00 */
	union {
		uint32_t fpga_histogram_r_data_1762; // word name
		struct {
			uint32_t hist_r_data_1762 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1763 14'h1E04 */
	union {
		uint32_t fpga_histogram_r_data_1763; // word name
		struct {
			uint32_t hist_r_data_1763 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1764 14'h1E08 */
	union {
		uint32_t fpga_histogram_r_data_1764; // word name
		struct {
			uint32_t hist_r_data_1764 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1765 14'h1E0C */
	union {
		uint32_t fpga_histogram_r_data_1765; // word name
		struct {
			uint32_t hist_r_data_1765 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1766 14'h1E10 */
	union {
		uint32_t fpga_histogram_r_data_1766; // word name
		struct {
			uint32_t hist_r_data_1766 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1767 14'h1E14 */
	union {
		uint32_t fpga_histogram_r_data_1767; // word name
		struct {
			uint32_t hist_r_data_1767 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1768 14'h1E18 */
	union {
		uint32_t fpga_histogram_r_data_1768; // word name
		struct {
			uint32_t hist_r_data_1768 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1769 14'h1E1C */
	union {
		uint32_t fpga_histogram_r_data_1769; // word name
		struct {
			uint32_t hist_r_data_1769 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1770 14'h1E20 */
	union {
		uint32_t fpga_histogram_r_data_1770; // word name
		struct {
			uint32_t hist_r_data_1770 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1771 14'h1E24 */
	union {
		uint32_t fpga_histogram_r_data_1771; // word name
		struct {
			uint32_t hist_r_data_1771 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1772 14'h1E28 */
	union {
		uint32_t fpga_histogram_r_data_1772; // word name
		struct {
			uint32_t hist_r_data_1772 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1773 14'h1E2C */
	union {
		uint32_t fpga_histogram_r_data_1773; // word name
		struct {
			uint32_t hist_r_data_1773 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1774 14'h1E30 */
	union {
		uint32_t fpga_histogram_r_data_1774; // word name
		struct {
			uint32_t hist_r_data_1774 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1775 14'h1E34 */
	union {
		uint32_t fpga_histogram_r_data_1775; // word name
		struct {
			uint32_t hist_r_data_1775 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1776 14'h1E38 */
	union {
		uint32_t fpga_histogram_r_data_1776; // word name
		struct {
			uint32_t hist_r_data_1776 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1777 14'h1E3C */
	union {
		uint32_t fpga_histogram_r_data_1777; // word name
		struct {
			uint32_t hist_r_data_1777 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1778 14'h1E40 */
	union {
		uint32_t fpga_histogram_r_data_1778; // word name
		struct {
			uint32_t hist_r_data_1778 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1779 14'h1E44 */
	union {
		uint32_t fpga_histogram_r_data_1779; // word name
		struct {
			uint32_t hist_r_data_1779 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1780 14'h1E48 */
	union {
		uint32_t fpga_histogram_r_data_1780; // word name
		struct {
			uint32_t hist_r_data_1780 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1781 14'h1E4C */
	union {
		uint32_t fpga_histogram_r_data_1781; // word name
		struct {
			uint32_t hist_r_data_1781 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1782 14'h1E50 */
	union {
		uint32_t fpga_histogram_r_data_1782; // word name
		struct {
			uint32_t hist_r_data_1782 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1783 14'h1E54 */
	union {
		uint32_t fpga_histogram_r_data_1783; // word name
		struct {
			uint32_t hist_r_data_1783 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1784 14'h1E58 */
	union {
		uint32_t fpga_histogram_r_data_1784; // word name
		struct {
			uint32_t hist_r_data_1784 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1785 14'h1E5C */
	union {
		uint32_t fpga_histogram_r_data_1785; // word name
		struct {
			uint32_t hist_r_data_1785 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1786 14'h1E60 */
	union {
		uint32_t fpga_histogram_r_data_1786; // word name
		struct {
			uint32_t hist_r_data_1786 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1787 14'h1E64 */
	union {
		uint32_t fpga_histogram_r_data_1787; // word name
		struct {
			uint32_t hist_r_data_1787 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1788 14'h1E68 */
	union {
		uint32_t fpga_histogram_r_data_1788; // word name
		struct {
			uint32_t hist_r_data_1788 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1789 14'h1E6C */
	union {
		uint32_t fpga_histogram_r_data_1789; // word name
		struct {
			uint32_t hist_r_data_1789 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1790 14'h1E70 */
	union {
		uint32_t fpga_histogram_r_data_1790; // word name
		struct {
			uint32_t hist_r_data_1790 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1791 14'h1E74 */
	union {
		uint32_t fpga_histogram_r_data_1791; // word name
		struct {
			uint32_t hist_r_data_1791 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1792 14'h1E78 */
	union {
		uint32_t fpga_histogram_r_data_1792; // word name
		struct {
			uint32_t hist_r_data_1792 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1793 14'h1E7C */
	union {
		uint32_t fpga_histogram_r_data_1793; // word name
		struct {
			uint32_t hist_r_data_1793 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1794 14'h1E80 */
	union {
		uint32_t fpga_histogram_r_data_1794; // word name
		struct {
			uint32_t hist_r_data_1794 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1795 14'h1E84 */
	union {
		uint32_t fpga_histogram_r_data_1795; // word name
		struct {
			uint32_t hist_r_data_1795 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1796 14'h1E88 */
	union {
		uint32_t fpga_histogram_r_data_1796; // word name
		struct {
			uint32_t hist_r_data_1796 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1797 14'h1E8C */
	union {
		uint32_t fpga_histogram_r_data_1797; // word name
		struct {
			uint32_t hist_r_data_1797 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1798 14'h1E90 */
	union {
		uint32_t fpga_histogram_r_data_1798; // word name
		struct {
			uint32_t hist_r_data_1798 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1799 14'h1E94 */
	union {
		uint32_t fpga_histogram_r_data_1799; // word name
		struct {
			uint32_t hist_r_data_1799 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1800 14'h1E98 */
	union {
		uint32_t fpga_histogram_r_data_1800; // word name
		struct {
			uint32_t hist_r_data_1800 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1801 14'h1E9C */
	union {
		uint32_t fpga_histogram_r_data_1801; // word name
		struct {
			uint32_t hist_r_data_1801 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1802 14'h1EA0 */
	union {
		uint32_t fpga_histogram_r_data_1802; // word name
		struct {
			uint32_t hist_r_data_1802 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1803 14'h1EA4 */
	union {
		uint32_t fpga_histogram_r_data_1803; // word name
		struct {
			uint32_t hist_r_data_1803 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1804 14'h1EA8 */
	union {
		uint32_t fpga_histogram_r_data_1804; // word name
		struct {
			uint32_t hist_r_data_1804 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1805 14'h1EAC */
	union {
		uint32_t fpga_histogram_r_data_1805; // word name
		struct {
			uint32_t hist_r_data_1805 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1806 14'h1EB0 */
	union {
		uint32_t fpga_histogram_r_data_1806; // word name
		struct {
			uint32_t hist_r_data_1806 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1807 14'h1EB4 */
	union {
		uint32_t fpga_histogram_r_data_1807; // word name
		struct {
			uint32_t hist_r_data_1807 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1808 14'h1EB8 */
	union {
		uint32_t fpga_histogram_r_data_1808; // word name
		struct {
			uint32_t hist_r_data_1808 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1809 14'h1EBC */
	union {
		uint32_t fpga_histogram_r_data_1809; // word name
		struct {
			uint32_t hist_r_data_1809 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1810 14'h1EC0 */
	union {
		uint32_t fpga_histogram_r_data_1810; // word name
		struct {
			uint32_t hist_r_data_1810 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1811 14'h1EC4 */
	union {
		uint32_t fpga_histogram_r_data_1811; // word name
		struct {
			uint32_t hist_r_data_1811 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1812 14'h1EC8 */
	union {
		uint32_t fpga_histogram_r_data_1812; // word name
		struct {
			uint32_t hist_r_data_1812 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1813 14'h1ECC */
	union {
		uint32_t fpga_histogram_r_data_1813; // word name
		struct {
			uint32_t hist_r_data_1813 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1814 14'h1ED0 */
	union {
		uint32_t fpga_histogram_r_data_1814; // word name
		struct {
			uint32_t hist_r_data_1814 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1815 14'h1ED4 */
	union {
		uint32_t fpga_histogram_r_data_1815; // word name
		struct {
			uint32_t hist_r_data_1815 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1816 14'h1ED8 */
	union {
		uint32_t fpga_histogram_r_data_1816; // word name
		struct {
			uint32_t hist_r_data_1816 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1817 14'h1EDC */
	union {
		uint32_t fpga_histogram_r_data_1817; // word name
		struct {
			uint32_t hist_r_data_1817 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1818 14'h1EE0 */
	union {
		uint32_t fpga_histogram_r_data_1818; // word name
		struct {
			uint32_t hist_r_data_1818 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1819 14'h1EE4 */
	union {
		uint32_t fpga_histogram_r_data_1819; // word name
		struct {
			uint32_t hist_r_data_1819 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1820 14'h1EE8 */
	union {
		uint32_t fpga_histogram_r_data_1820; // word name
		struct {
			uint32_t hist_r_data_1820 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1821 14'h1EEC */
	union {
		uint32_t fpga_histogram_r_data_1821; // word name
		struct {
			uint32_t hist_r_data_1821 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1822 14'h1EF0 */
	union {
		uint32_t fpga_histogram_r_data_1822; // word name
		struct {
			uint32_t hist_r_data_1822 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1823 14'h1EF4 */
	union {
		uint32_t fpga_histogram_r_data_1823; // word name
		struct {
			uint32_t hist_r_data_1823 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1824 14'h1EF8 */
	union {
		uint32_t fpga_histogram_r_data_1824; // word name
		struct {
			uint32_t hist_r_data_1824 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1825 14'h1EFC */
	union {
		uint32_t fpga_histogram_r_data_1825; // word name
		struct {
			uint32_t hist_r_data_1825 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1826 14'h1F00 */
	union {
		uint32_t fpga_histogram_r_data_1826; // word name
		struct {
			uint32_t hist_r_data_1826 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1827 14'h1F04 */
	union {
		uint32_t fpga_histogram_r_data_1827; // word name
		struct {
			uint32_t hist_r_data_1827 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1828 14'h1F08 */
	union {
		uint32_t fpga_histogram_r_data_1828; // word name
		struct {
			uint32_t hist_r_data_1828 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1829 14'h1F0C */
	union {
		uint32_t fpga_histogram_r_data_1829; // word name
		struct {
			uint32_t hist_r_data_1829 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1830 14'h1F10 */
	union {
		uint32_t fpga_histogram_r_data_1830; // word name
		struct {
			uint32_t hist_r_data_1830 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1831 14'h1F14 */
	union {
		uint32_t fpga_histogram_r_data_1831; // word name
		struct {
			uint32_t hist_r_data_1831 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1832 14'h1F18 */
	union {
		uint32_t fpga_histogram_r_data_1832; // word name
		struct {
			uint32_t hist_r_data_1832 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1833 14'h1F1C */
	union {
		uint32_t fpga_histogram_r_data_1833; // word name
		struct {
			uint32_t hist_r_data_1833 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1834 14'h1F20 */
	union {
		uint32_t fpga_histogram_r_data_1834; // word name
		struct {
			uint32_t hist_r_data_1834 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1835 14'h1F24 */
	union {
		uint32_t fpga_histogram_r_data_1835; // word name
		struct {
			uint32_t hist_r_data_1835 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1836 14'h1F28 */
	union {
		uint32_t fpga_histogram_r_data_1836; // word name
		struct {
			uint32_t hist_r_data_1836 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1837 14'h1F2C */
	union {
		uint32_t fpga_histogram_r_data_1837; // word name
		struct {
			uint32_t hist_r_data_1837 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1838 14'h1F30 */
	union {
		uint32_t fpga_histogram_r_data_1838; // word name
		struct {
			uint32_t hist_r_data_1838 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1839 14'h1F34 */
	union {
		uint32_t fpga_histogram_r_data_1839; // word name
		struct {
			uint32_t hist_r_data_1839 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1840 14'h1F38 */
	union {
		uint32_t fpga_histogram_r_data_1840; // word name
		struct {
			uint32_t hist_r_data_1840 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1841 14'h1F3C */
	union {
		uint32_t fpga_histogram_r_data_1841; // word name
		struct {
			uint32_t hist_r_data_1841 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1842 14'h1F40 */
	union {
		uint32_t fpga_histogram_r_data_1842; // word name
		struct {
			uint32_t hist_r_data_1842 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1843 14'h1F44 */
	union {
		uint32_t fpga_histogram_r_data_1843; // word name
		struct {
			uint32_t hist_r_data_1843 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1844 14'h1F48 */
	union {
		uint32_t fpga_histogram_r_data_1844; // word name
		struct {
			uint32_t hist_r_data_1844 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1845 14'h1F4C */
	union {
		uint32_t fpga_histogram_r_data_1845; // word name
		struct {
			uint32_t hist_r_data_1845 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1846 14'h1F50 */
	union {
		uint32_t fpga_histogram_r_data_1846; // word name
		struct {
			uint32_t hist_r_data_1846 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1847 14'h1F54 */
	union {
		uint32_t fpga_histogram_r_data_1847; // word name
		struct {
			uint32_t hist_r_data_1847 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1848 14'h1F58 */
	union {
		uint32_t fpga_histogram_r_data_1848; // word name
		struct {
			uint32_t hist_r_data_1848 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1849 14'h1F5C */
	union {
		uint32_t fpga_histogram_r_data_1849; // word name
		struct {
			uint32_t hist_r_data_1849 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1850 14'h1F60 */
	union {
		uint32_t fpga_histogram_r_data_1850; // word name
		struct {
			uint32_t hist_r_data_1850 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1851 14'h1F64 */
	union {
		uint32_t fpga_histogram_r_data_1851; // word name
		struct {
			uint32_t hist_r_data_1851 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1852 14'h1F68 */
	union {
		uint32_t fpga_histogram_r_data_1852; // word name
		struct {
			uint32_t hist_r_data_1852 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1853 14'h1F6C */
	union {
		uint32_t fpga_histogram_r_data_1853; // word name
		struct {
			uint32_t hist_r_data_1853 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1854 14'h1F70 */
	union {
		uint32_t fpga_histogram_r_data_1854; // word name
		struct {
			uint32_t hist_r_data_1854 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1855 14'h1F74 */
	union {
		uint32_t fpga_histogram_r_data_1855; // word name
		struct {
			uint32_t hist_r_data_1855 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1856 14'h1F78 */
	union {
		uint32_t fpga_histogram_r_data_1856; // word name
		struct {
			uint32_t hist_r_data_1856 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1857 14'h1F7C */
	union {
		uint32_t fpga_histogram_r_data_1857; // word name
		struct {
			uint32_t hist_r_data_1857 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1858 14'h1F80 */
	union {
		uint32_t fpga_histogram_r_data_1858; // word name
		struct {
			uint32_t hist_r_data_1858 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1859 14'h1F84 */
	union {
		uint32_t fpga_histogram_r_data_1859; // word name
		struct {
			uint32_t hist_r_data_1859 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1860 14'h1F88 */
	union {
		uint32_t fpga_histogram_r_data_1860; // word name
		struct {
			uint32_t hist_r_data_1860 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1861 14'h1F8C */
	union {
		uint32_t fpga_histogram_r_data_1861; // word name
		struct {
			uint32_t hist_r_data_1861 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1862 14'h1F90 */
	union {
		uint32_t fpga_histogram_r_data_1862; // word name
		struct {
			uint32_t hist_r_data_1862 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1863 14'h1F94 */
	union {
		uint32_t fpga_histogram_r_data_1863; // word name
		struct {
			uint32_t hist_r_data_1863 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1864 14'h1F98 */
	union {
		uint32_t fpga_histogram_r_data_1864; // word name
		struct {
			uint32_t hist_r_data_1864 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1865 14'h1F9C */
	union {
		uint32_t fpga_histogram_r_data_1865; // word name
		struct {
			uint32_t hist_r_data_1865 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1866 14'h1FA0 */
	union {
		uint32_t fpga_histogram_r_data_1866; // word name
		struct {
			uint32_t hist_r_data_1866 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1867 14'h1FA4 */
	union {
		uint32_t fpga_histogram_r_data_1867; // word name
		struct {
			uint32_t hist_r_data_1867 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1868 14'h1FA8 */
	union {
		uint32_t fpga_histogram_r_data_1868; // word name
		struct {
			uint32_t hist_r_data_1868 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1869 14'h1FAC */
	union {
		uint32_t fpga_histogram_r_data_1869; // word name
		struct {
			uint32_t hist_r_data_1869 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1870 14'h1FB0 */
	union {
		uint32_t fpga_histogram_r_data_1870; // word name
		struct {
			uint32_t hist_r_data_1870 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1871 14'h1FB4 */
	union {
		uint32_t fpga_histogram_r_data_1871; // word name
		struct {
			uint32_t hist_r_data_1871 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1872 14'h1FB8 */
	union {
		uint32_t fpga_histogram_r_data_1872; // word name
		struct {
			uint32_t hist_r_data_1872 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1873 14'h1FBC */
	union {
		uint32_t fpga_histogram_r_data_1873; // word name
		struct {
			uint32_t hist_r_data_1873 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1874 14'h1FC0 */
	union {
		uint32_t fpga_histogram_r_data_1874; // word name
		struct {
			uint32_t hist_r_data_1874 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1875 14'h1FC4 */
	union {
		uint32_t fpga_histogram_r_data_1875; // word name
		struct {
			uint32_t hist_r_data_1875 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1876 14'h1FC8 */
	union {
		uint32_t fpga_histogram_r_data_1876; // word name
		struct {
			uint32_t hist_r_data_1876 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1877 14'h1FCC */
	union {
		uint32_t fpga_histogram_r_data_1877; // word name
		struct {
			uint32_t hist_r_data_1877 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1878 14'h1FD0 */
	union {
		uint32_t fpga_histogram_r_data_1878; // word name
		struct {
			uint32_t hist_r_data_1878 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1879 14'h1FD4 */
	union {
		uint32_t fpga_histogram_r_data_1879; // word name
		struct {
			uint32_t hist_r_data_1879 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1880 14'h1FD8 */
	union {
		uint32_t fpga_histogram_r_data_1880; // word name
		struct {
			uint32_t hist_r_data_1880 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1881 14'h1FDC */
	union {
		uint32_t fpga_histogram_r_data_1881; // word name
		struct {
			uint32_t hist_r_data_1881 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1882 14'h1FE0 */
	union {
		uint32_t fpga_histogram_r_data_1882; // word name
		struct {
			uint32_t hist_r_data_1882 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1883 14'h1FE4 */
	union {
		uint32_t fpga_histogram_r_data_1883; // word name
		struct {
			uint32_t hist_r_data_1883 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1884 14'h1FE8 */
	union {
		uint32_t fpga_histogram_r_data_1884; // word name
		struct {
			uint32_t hist_r_data_1884 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1885 14'h1FEC */
	union {
		uint32_t fpga_histogram_r_data_1885; // word name
		struct {
			uint32_t hist_r_data_1885 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1886 14'h1FF0 */
	union {
		uint32_t fpga_histogram_r_data_1886; // word name
		struct {
			uint32_t hist_r_data_1886 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1887 14'h1FF4 */
	union {
		uint32_t fpga_histogram_r_data_1887; // word name
		struct {
			uint32_t hist_r_data_1887 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1888 14'h1FF8 */
	union {
		uint32_t fpga_histogram_r_data_1888; // word name
		struct {
			uint32_t hist_r_data_1888 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1889 14'h1FFC */
	union {
		uint32_t fpga_histogram_r_data_1889; // word name
		struct {
			uint32_t hist_r_data_1889 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1890 14'h2000 */
	union {
		uint32_t fpga_histogram_r_data_1890; // word name
		struct {
			uint32_t hist_r_data_1890 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1891 14'h2004 */
	union {
		uint32_t fpga_histogram_r_data_1891; // word name
		struct {
			uint32_t hist_r_data_1891 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1892 14'h2008 */
	union {
		uint32_t fpga_histogram_r_data_1892; // word name
		struct {
			uint32_t hist_r_data_1892 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1893 14'h200C */
	union {
		uint32_t fpga_histogram_r_data_1893; // word name
		struct {
			uint32_t hist_r_data_1893 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1894 14'h2010 */
	union {
		uint32_t fpga_histogram_r_data_1894; // word name
		struct {
			uint32_t hist_r_data_1894 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1895 14'h2014 */
	union {
		uint32_t fpga_histogram_r_data_1895; // word name
		struct {
			uint32_t hist_r_data_1895 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1896 14'h2018 */
	union {
		uint32_t fpga_histogram_r_data_1896; // word name
		struct {
			uint32_t hist_r_data_1896 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1897 14'h201C */
	union {
		uint32_t fpga_histogram_r_data_1897; // word name
		struct {
			uint32_t hist_r_data_1897 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1898 14'h2020 */
	union {
		uint32_t fpga_histogram_r_data_1898; // word name
		struct {
			uint32_t hist_r_data_1898 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1899 14'h2024 */
	union {
		uint32_t fpga_histogram_r_data_1899; // word name
		struct {
			uint32_t hist_r_data_1899 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1900 14'h2028 */
	union {
		uint32_t fpga_histogram_r_data_1900; // word name
		struct {
			uint32_t hist_r_data_1900 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1901 14'h202C */
	union {
		uint32_t fpga_histogram_r_data_1901; // word name
		struct {
			uint32_t hist_r_data_1901 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1902 14'h2030 */
	union {
		uint32_t fpga_histogram_r_data_1902; // word name
		struct {
			uint32_t hist_r_data_1902 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1903 14'h2034 */
	union {
		uint32_t fpga_histogram_r_data_1903; // word name
		struct {
			uint32_t hist_r_data_1903 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1904 14'h2038 */
	union {
		uint32_t fpga_histogram_r_data_1904; // word name
		struct {
			uint32_t hist_r_data_1904 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1905 14'h203C */
	union {
		uint32_t fpga_histogram_r_data_1905; // word name
		struct {
			uint32_t hist_r_data_1905 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1906 14'h2040 */
	union {
		uint32_t fpga_histogram_r_data_1906; // word name
		struct {
			uint32_t hist_r_data_1906 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1907 14'h2044 */
	union {
		uint32_t fpga_histogram_r_data_1907; // word name
		struct {
			uint32_t hist_r_data_1907 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1908 14'h2048 */
	union {
		uint32_t fpga_histogram_r_data_1908; // word name
		struct {
			uint32_t hist_r_data_1908 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1909 14'h204C */
	union {
		uint32_t fpga_histogram_r_data_1909; // word name
		struct {
			uint32_t hist_r_data_1909 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1910 14'h2050 */
	union {
		uint32_t fpga_histogram_r_data_1910; // word name
		struct {
			uint32_t hist_r_data_1910 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1911 14'h2054 */
	union {
		uint32_t fpga_histogram_r_data_1911; // word name
		struct {
			uint32_t hist_r_data_1911 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1912 14'h2058 */
	union {
		uint32_t fpga_histogram_r_data_1912; // word name
		struct {
			uint32_t hist_r_data_1912 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1913 14'h205C */
	union {
		uint32_t fpga_histogram_r_data_1913; // word name
		struct {
			uint32_t hist_r_data_1913 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1914 14'h2060 */
	union {
		uint32_t fpga_histogram_r_data_1914; // word name
		struct {
			uint32_t hist_r_data_1914 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1915 14'h2064 */
	union {
		uint32_t fpga_histogram_r_data_1915; // word name
		struct {
			uint32_t hist_r_data_1915 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1916 14'h2068 */
	union {
		uint32_t fpga_histogram_r_data_1916; // word name
		struct {
			uint32_t hist_r_data_1916 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1917 14'h206C */
	union {
		uint32_t fpga_histogram_r_data_1917; // word name
		struct {
			uint32_t hist_r_data_1917 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1918 14'h2070 */
	union {
		uint32_t fpga_histogram_r_data_1918; // word name
		struct {
			uint32_t hist_r_data_1918 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_HISTOGRAM_R_DATA_1919 14'h2074 */
	union {
		uint32_t fpga_histogram_r_data_1919; // word name
		struct {
			uint32_t hist_r_data_1919 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
#endif /* CONFIG_FPGA */
} CsrBankHdr;

#endif
