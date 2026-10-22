/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_NR_H_
#define CSR_BANK_NR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from nr  ***/
typedef struct csr_bank_nr {
	/* WORD_MODE 10'h000 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIR_MODE 10'h004 */
	union {
		uint32_t fir_mode; // word name
		struct {
			uint32_t fir_kernel_sel_y : 1;
			uint32_t : 7; // padding bits
			uint32_t fir_weight_y : 5;
			uint32_t : 3; // padding bits
			uint32_t fir_weight_c : 5;
			uint32_t : 3; // padding bits
			uint32_t fir_diff_tolerance_thd : 8;
		};
	};
	/* FIR_SETTING 10'h008 */
	union {
		uint32_t fir_setting; // word name
		struct {
			uint32_t fir_stronger_level : 4;
			uint32_t : 4; // padding bits
			uint32_t fir_stronger_by_frame : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IIR_MODE 10'h00C */
	union {
		uint32_t iir_mode; // word name
		struct {
			uint32_t iir_alpha_y_offset : 7;
			uint32_t : 1; // padding bits
			uint32_t iir_alpha_c_offset : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IIR_STRENGTH 10'h010 */
	union {
		uint32_t iir_strength; // word name
		struct {
			uint32_t iir_ma_max_strength : 7;
			uint32_t : 1; // padding bits
			uint32_t iir_mc_max_strength : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ATTRIBUTES1 10'h014 */
	union {
		uint32_t attributes1; // word name
		struct {
			uint32_t moving_coring_th : 2;
			uint32_t : 6; // padding bits
			uint32_t moving_perblk_max : 4;
			uint32_t : 4; // padding bits
			uint32_t mv_consist_coring : 3;
			uint32_t : 5; // padding bits
			uint32_t mv_consist_perblk_max : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* ATTRIBUTES2 10'h018 */
	union {
		uint32_t attributes2; // word name
		struct {
			uint32_t texture_coring_bits : 3;
			uint32_t : 5; // padding bits
			uint32_t mv_consist_round_bit : 2;
			uint32_t : 6; // padding bits
			uint32_t force_mv_consist_en : 1;
			uint32_t : 7; // padding bits
			uint32_t force_mv_consist : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_STRENGTH_ADAPTIVE1 10'h01C */
	union {
		uint32_t ma_strength_adaptive1; // word name
		struct {
			uint32_t ma_edge_thd : 5;
			uint32_t : 3; // padding bits
			uint32_t ma_still_lvl_moving_upper_bnd : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_still_edge_add_weight_max : 7;
			uint32_t : 1; // padding bits
			uint32_t ma_smooth_texture_upper_bnd : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_STRENGTH_ADAPTIVE2 10'h020 */
	union {
		uint32_t ma_strength_adaptive2; // word name
		struct {
			uint32_t ma_sad_norm_texture_shift_bit : 2;
			uint32_t : 6; // padding bits
			uint32_t ma_nonstill_moving_thd : 4;
			uint32_t : 4; // padding bits
			uint32_t ma_nonstill_smooth_fb_discard_match : 1;
			uint32_t : 7; // padding bits
			uint32_t ma_nonstill_smooth_sub_wei_rto : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_STRENGTH_ADAPTIVE3 10'h024 */
	union {
		uint32_t ma_strength_adaptive3; // word name
		struct {
			uint32_t ma_still_consistency_thd : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MC_STRENGTH_ADAPTIVE1 10'h028 */
	union {
		uint32_t mc_strength_adaptive1; // word name
		struct {
			uint32_t mc_texture_thd : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t iir_mc_conf_edge_add_weight_max : 7;
			uint32_t : 1; // padding bits
			uint32_t mc_mixing_fir_level : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* MC_STRENGTH_ADAPTIVE2 10'h02C */
	union {
		uint32_t mc_strength_adaptive2; // word name
		struct {
			uint32_t mc_consistency_thd : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_Y_LUT_I_0_1 10'h030 */
	union {
		uint32_t ma_y_lut_i_0_1; // word name
		struct {
			uint32_t ma_y_lut_i_0 : 11;
			uint32_t : 5; // padding bits
			uint32_t ma_y_lut_i_1 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MA_Y_LUT_I_2_3 10'h034 */
	union {
		uint32_t ma_y_lut_i_2_3; // word name
		struct {
			uint32_t ma_y_lut_i_2 : 11;
			uint32_t : 5; // padding bits
			uint32_t ma_y_lut_i_3 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MA_Y_LUT_I_4_5 10'h038 */
	union {
		uint32_t ma_y_lut_i_4_5; // word name
		struct {
			uint32_t ma_y_lut_i_4 : 11;
			uint32_t : 5; // padding bits
			uint32_t ma_y_lut_i_5 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MA_Y_LUT_I_6_7 10'h03C */
	union {
		uint32_t ma_y_lut_i_6_7; // word name
		struct {
			uint32_t ma_y_lut_i_6 : 11;
			uint32_t : 5; // padding bits
			uint32_t ma_y_lut_i_7 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MA_Y_LUT_I_8_8 10'h040 */
	union {
		uint32_t ma_y_lut_i_8_8; // word name
		struct {
			uint32_t ma_y_lut_i_8 : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_Y_LUT_O_0_3 10'h044 */
	union {
		uint32_t ma_y_lut_o_0_3; // word name
		struct {
			uint32_t ma_y_lut_o_0 : 8;
			uint32_t ma_y_lut_o_1 : 8;
			uint32_t ma_y_lut_o_2 : 8;
			uint32_t ma_y_lut_o_3 : 8;
		};
	};
	/* MA_Y_LUT_O_4_7 10'h048 */
	union {
		uint32_t ma_y_lut_o_4_7; // word name
		struct {
			uint32_t ma_y_lut_o_4 : 8;
			uint32_t ma_y_lut_o_5 : 8;
			uint32_t ma_y_lut_o_6 : 8;
			uint32_t ma_y_lut_o_7 : 8;
		};
	};
	/* MA_Y_LUT_O_8_8 10'h04C */
	union {
		uint32_t ma_y_lut_o_8_8; // word name
		struct {
			uint32_t ma_y_lut_o_8 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_Y_LUT_SLOPE_0_1 10'h050 */
	union {
		uint32_t ma_y_lut_slope_0_1; // word name
		struct {
			uint32_t ma_y_lut_slope_0 : 16;
			uint32_t ma_y_lut_slope_1 : 16;
		};
	};
	/* MA_Y_LUT_SLOPE_2_3 10'h054 */
	union {
		uint32_t ma_y_lut_slope_2_3; // word name
		struct {
			uint32_t ma_y_lut_slope_2 : 16;
			uint32_t ma_y_lut_slope_3 : 16;
		};
	};
	/* MA_Y_LUT_SLOPE_4_5 10'h058 */
	union {
		uint32_t ma_y_lut_slope_4_5; // word name
		struct {
			uint32_t ma_y_lut_slope_4 : 16;
			uint32_t ma_y_lut_slope_5 : 16;
		};
	};
	/* MA_Y_LUT_SLOPE_6_7 10'h05C */
	union {
		uint32_t ma_y_lut_slope_6_7; // word name
		struct {
			uint32_t ma_y_lut_slope_6 : 16;
			uint32_t ma_y_lut_slope_7 : 16;
		};
	};
	/* MA_Y_LP_DYN_GAIN_0 10'h060 */
	union {
		uint32_t ma_y_lp_dyn_gain_0; // word name
		struct {
			uint32_t ma_y_lp_dyn_gain_th_min : 8;
			uint32_t ma_y_lp_dyn_gain_th_max : 8;
			uint32_t ma_y_lp_dyn_gain_min : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lp_dyn_gain_max : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_Y_LP_DYN_GAIN_1 10'h064 */
	union {
		uint32_t ma_y_lp_dyn_gain_1; // word name
		struct {
			uint32_t ma_y_lp_dyn_gain_slope : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MC_Y_LUT_I_0_1 10'h068 */
	union {
		uint32_t mc_y_lut_i_0_1; // word name
		struct {
			uint32_t mc_y_lut_i_0 : 11;
			uint32_t : 5; // padding bits
			uint32_t mc_y_lut_i_1 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MC_Y_LUT_I_2_3 10'h06C */
	union {
		uint32_t mc_y_lut_i_2_3; // word name
		struct {
			uint32_t mc_y_lut_i_2 : 11;
			uint32_t : 5; // padding bits
			uint32_t mc_y_lut_i_3 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MC_Y_LUT_I_4_5 10'h070 */
	union {
		uint32_t mc_y_lut_i_4_5; // word name
		struct {
			uint32_t mc_y_lut_i_4 : 11;
			uint32_t : 5; // padding bits
			uint32_t mc_y_lut_i_5 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MC_Y_LUT_I_6_7 10'h074 */
	union {
		uint32_t mc_y_lut_i_6_7; // word name
		struct {
			uint32_t mc_y_lut_i_6 : 11;
			uint32_t : 5; // padding bits
			uint32_t mc_y_lut_i_7 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MC_Y_LUT_I_8_8 10'h078 */
	union {
		uint32_t mc_y_lut_i_8_8; // word name
		struct {
			uint32_t mc_y_lut_i_8 : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MC_Y_LUT_O_0_3 10'h07C */
	union {
		uint32_t mc_y_lut_o_0_3; // word name
		struct {
			uint32_t mc_y_lut_o_0 : 8;
			uint32_t mc_y_lut_o_1 : 8;
			uint32_t mc_y_lut_o_2 : 8;
			uint32_t mc_y_lut_o_3 : 8;
		};
	};
	/* MC_Y_LUT_O_4_7 10'h080 */
	union {
		uint32_t mc_y_lut_o_4_7; // word name
		struct {
			uint32_t mc_y_lut_o_4 : 8;
			uint32_t mc_y_lut_o_5 : 8;
			uint32_t mc_y_lut_o_6 : 8;
			uint32_t mc_y_lut_o_7 : 8;
		};
	};
	/* MC_Y_LUT_O_8_8 10'h084 */
	union {
		uint32_t mc_y_lut_o_8_8; // word name
		struct {
			uint32_t mc_y_lut_o_8 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MC_Y_LUT_SLOPE_0_1 10'h088 */
	union {
		uint32_t mc_y_lut_slope_0_1; // word name
		struct {
			uint32_t mc_y_lut_slope_0 : 16;
			uint32_t mc_y_lut_slope_1 : 16;
		};
	};
	/* MC_Y_LUT_SLOPE_2_3 10'h08C */
	union {
		uint32_t mc_y_lut_slope_2_3; // word name
		struct {
			uint32_t mc_y_lut_slope_2 : 16;
			uint32_t mc_y_lut_slope_3 : 16;
		};
	};
	/* MC_Y_LUT_SLOPE_4_5 10'h090 */
	union {
		uint32_t mc_y_lut_slope_4_5; // word name
		struct {
			uint32_t mc_y_lut_slope_4 : 16;
			uint32_t mc_y_lut_slope_5 : 16;
		};
	};
	/* MC_Y_LUT_SLOPE_6_7 10'h094 */
	union {
		uint32_t mc_y_lut_slope_6_7; // word name
		struct {
			uint32_t mc_y_lut_slope_6 : 16;
			uint32_t mc_y_lut_slope_7 : 16;
		};
	};
	/* MC_RATIO1 10'h098 */
	union {
		uint32_t mc_ratio1; // word name
		struct {
			uint32_t force_mc_ratio_en : 1;
			uint32_t : 7; // padding bits
			uint32_t force_mc_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t mc_ratio_moving_thd : 4;
			uint32_t : 4; // padding bits
			uint32_t mc_ratio_texture_thd : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* MC_RATIO2 10'h09C */
	union {
		uint32_t mc_ratio2; // word name
		struct {
			uint32_t mc_ratio_texture_round_bit : 2;
			uint32_t : 6; // padding bits
			uint32_t mc_ratio_ignore_mcmatcher_lvl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_C_LUT_I_0_1 10'h0A0 */
	union {
		uint32_t ma_c_lut_i_0_1; // word name
		struct {
			uint32_t ma_c_lut_i_0 : 11;
			uint32_t : 5; // padding bits
			uint32_t ma_c_lut_i_1 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MA_C_LUT_I_2_3 10'h0A4 */
	union {
		uint32_t ma_c_lut_i_2_3; // word name
		struct {
			uint32_t ma_c_lut_i_2 : 11;
			uint32_t : 5; // padding bits
			uint32_t ma_c_lut_i_3 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MA_C_LUT_I_4_5 10'h0A8 */
	union {
		uint32_t ma_c_lut_i_4_5; // word name
		struct {
			uint32_t ma_c_lut_i_4 : 11;
			uint32_t : 5; // padding bits
			uint32_t ma_c_lut_i_5 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MA_C_LUT_I_6_7 10'h0AC */
	union {
		uint32_t ma_c_lut_i_6_7; // word name
		struct {
			uint32_t ma_c_lut_i_6 : 11;
			uint32_t : 5; // padding bits
			uint32_t ma_c_lut_i_7 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* MA_C_LUT_I_8_8 10'h0B0 */
	union {
		uint32_t ma_c_lut_i_8_8; // word name
		struct {
			uint32_t ma_c_lut_i_8 : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_C_LUT_O_0_3 10'h0B4 */
	union {
		uint32_t ma_c_lut_o_0_3; // word name
		struct {
			uint32_t ma_c_lut_o_0 : 8;
			uint32_t ma_c_lut_o_1 : 8;
			uint32_t ma_c_lut_o_2 : 8;
			uint32_t ma_c_lut_o_3 : 8;
		};
	};
	/* MA_C_LUT_O_4_7 10'h0B8 */
	union {
		uint32_t ma_c_lut_o_4_7; // word name
		struct {
			uint32_t ma_c_lut_o_4 : 8;
			uint32_t ma_c_lut_o_5 : 8;
			uint32_t ma_c_lut_o_6 : 8;
			uint32_t ma_c_lut_o_7 : 8;
		};
	};
	/* MA_C_LUT_O_8_8 10'h0BC */
	union {
		uint32_t ma_c_lut_o_8_8; // word name
		struct {
			uint32_t ma_c_lut_o_8 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_C_LUT_SLOPE_0_1 10'h0C0 */
	union {
		uint32_t ma_c_lut_slope_0_1; // word name
		struct {
			uint32_t ma_c_lut_slope_0 : 16;
			uint32_t ma_c_lut_slope_1 : 16;
		};
	};
	/* MA_C_LUT_SLOPE_2_3 10'h0C4 */
	union {
		uint32_t ma_c_lut_slope_2_3; // word name
		struct {
			uint32_t ma_c_lut_slope_2 : 16;
			uint32_t ma_c_lut_slope_3 : 16;
		};
	};
	/* MA_C_LUT_SLOPE_4_5 10'h0C8 */
	union {
		uint32_t ma_c_lut_slope_4_5; // word name
		struct {
			uint32_t ma_c_lut_slope_4 : 16;
			uint32_t ma_c_lut_slope_5 : 16;
		};
	};
	/* MA_C_LUT_SLOPE_6_7 10'h0CC */
	union {
		uint32_t ma_c_lut_slope_6_7; // word name
		struct {
			uint32_t ma_c_lut_slope_6 : 16;
			uint32_t ma_c_lut_slope_7 : 16;
		};
	};
	/* MA_C_Y_STRENGTH_SEL 10'h0D0 */
	union {
		uint32_t ma_c_y_strength_sel; // word name
		struct {
			uint32_t ma_c_weight_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_EN 10'h0D4 */
	union {
		uint32_t word_abs_diff_hist_en; // word name
		struct {
			uint32_t abs_diff_hist_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t abs_diff_hist_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_MODE 10'h0D8 */
	union {
		uint32_t word_abs_diff_hist_mode; // word name
		struct {
			uint32_t abs_diff_hist_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t abs_diff_hist_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t abs_diff_hist_step : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ABS_DIFF_HIST_SXSY 10'h0DC */
	union {
		uint32_t abs_diff_hist_sxsy; // word name
		struct {
			uint32_t abs_diff_hist_sx : 16;
			uint32_t abs_diff_hist_sy : 16;
		};
	};
	/* ABS_DIFF_HIST_EXEY 10'h0E0 */
	union {
		uint32_t abs_diff_hist_exey; // word name
		struct {
			uint32_t abs_diff_hist_ex : 16;
			uint32_t abs_diff_hist_ey : 16;
		};
	};
	/* WORD_ABS_DIFF_HIST_OVERFLOW 10'h0E4 */
	union {
		uint32_t word_abs_diff_hist_overflow; // word name
		struct {
			uint32_t abs_diff_hist_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_0 10'h0E8 */
	union {
		uint32_t word_abs_diff_hist_0; // word name
		struct {
			uint32_t abs_diff_hist_0 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_1 10'h0EC */
	union {
		uint32_t word_abs_diff_hist_1; // word name
		struct {
			uint32_t abs_diff_hist_1 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_2 10'h0F0 */
	union {
		uint32_t word_abs_diff_hist_2; // word name
		struct {
			uint32_t abs_diff_hist_2 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_3 10'h0F4 */
	union {
		uint32_t word_abs_diff_hist_3; // word name
		struct {
			uint32_t abs_diff_hist_3 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_4 10'h0F8 */
	union {
		uint32_t word_abs_diff_hist_4; // word name
		struct {
			uint32_t abs_diff_hist_4 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_5 10'h0FC */
	union {
		uint32_t word_abs_diff_hist_5; // word name
		struct {
			uint32_t abs_diff_hist_5 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_6 10'h100 */
	union {
		uint32_t word_abs_diff_hist_6; // word name
		struct {
			uint32_t abs_diff_hist_6 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_7 10'h104 */
	union {
		uint32_t word_abs_diff_hist_7; // word name
		struct {
			uint32_t abs_diff_hist_7 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_8 10'h108 */
	union {
		uint32_t word_abs_diff_hist_8; // word name
		struct {
			uint32_t abs_diff_hist_8 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_9 10'h10C */
	union {
		uint32_t word_abs_diff_hist_9; // word name
		struct {
			uint32_t abs_diff_hist_9 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_10 10'h110 */
	union {
		uint32_t word_abs_diff_hist_10; // word name
		struct {
			uint32_t abs_diff_hist_10 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_11 10'h114 */
	union {
		uint32_t word_abs_diff_hist_11; // word name
		struct {
			uint32_t abs_diff_hist_11 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_12 10'h118 */
	union {
		uint32_t word_abs_diff_hist_12; // word name
		struct {
			uint32_t abs_diff_hist_12 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_13 10'h11C */
	union {
		uint32_t word_abs_diff_hist_13; // word name
		struct {
			uint32_t abs_diff_hist_13 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_14 10'h120 */
	union {
		uint32_t word_abs_diff_hist_14; // word name
		struct {
			uint32_t abs_diff_hist_14 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_15 10'h124 */
	union {
		uint32_t word_abs_diff_hist_15; // word name
		struct {
			uint32_t abs_diff_hist_15 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_16 10'h128 */
	union {
		uint32_t word_abs_diff_hist_16; // word name
		struct {
			uint32_t abs_diff_hist_16 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_17 10'h12C */
	union {
		uint32_t word_abs_diff_hist_17; // word name
		struct {
			uint32_t abs_diff_hist_17 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_18 10'h130 */
	union {
		uint32_t word_abs_diff_hist_18; // word name
		struct {
			uint32_t abs_diff_hist_18 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_TDIFF_ROI_0_EN 10'h134 */
	union {
		uint32_t word_tdiff_roi_0_en; // word name
		struct {
			uint32_t tdiff_roi_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tdiff_roi_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TDIFF_ROI_0_SXSY 10'h138 */
	union {
		uint32_t tdiff_roi_0_sxsy; // word name
		struct {
			uint32_t tdiff_roi_0_sx : 16;
			uint32_t tdiff_roi_0_sy : 16;
		};
	};
	/* TDIFF_ROI_0_EXEY 10'h13C */
	union {
		uint32_t tdiff_roi_0_exey; // word name
		struct {
			uint32_t tdiff_roi_0_ex : 16;
			uint32_t tdiff_roi_0_ey : 16;
		};
	};
	/* TDIFF_ROI_0_TH_Y 10'h140 */
	union {
		uint32_t tdiff_roi_0_th_y; // word name
		struct {
			uint32_t tdiff_roi_0_acc_th_y : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_0_TH_C 10'h144 */
	union {
		uint32_t tdiff_roi_0_th_c; // word name
		struct {
			uint32_t tdiff_roi_0_acc_th_c : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_0_STAT 10'h148 */
	union {
		uint32_t tdiff_roi_0_stat; // word name
		struct {
			uint32_t tdiff_roi_0_avg_y : 16;
			uint32_t tdiff_roi_0_avg_c : 16;
		};
	};
	/* WORD_TDIFF_ROI_1_EN 10'h14C */
	union {
		uint32_t word_tdiff_roi_1_en; // word name
		struct {
			uint32_t tdiff_roi_1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tdiff_roi_1_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TDIFF_ROI_1_SXSY 10'h150 */
	union {
		uint32_t tdiff_roi_1_sxsy; // word name
		struct {
			uint32_t tdiff_roi_1_sx : 16;
			uint32_t tdiff_roi_1_sy : 16;
		};
	};
	/* TDIFF_ROI_1_EXEY 10'h154 */
	union {
		uint32_t tdiff_roi_1_exey; // word name
		struct {
			uint32_t tdiff_roi_1_ex : 16;
			uint32_t tdiff_roi_1_ey : 16;
		};
	};
	/* TDIFF_ROI_1_TH_Y 10'h158 */
	union {
		uint32_t tdiff_roi_1_th_y; // word name
		struct {
			uint32_t tdiff_roi_1_acc_th_y : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_1_TH_C 10'h15C */
	union {
		uint32_t tdiff_roi_1_th_c; // word name
		struct {
			uint32_t tdiff_roi_1_acc_th_c : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_1_STAT 10'h160 */
	union {
		uint32_t tdiff_roi_1_stat; // word name
		struct {
			uint32_t tdiff_roi_1_avg_y : 16;
			uint32_t tdiff_roi_1_avg_c : 16;
		};
	};
	/* WORD_TDIFF_ROI_2_EN 10'h164 */
	union {
		uint32_t word_tdiff_roi_2_en; // word name
		struct {
			uint32_t tdiff_roi_2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tdiff_roi_2_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TDIFF_ROI_2_SXSY 10'h168 */
	union {
		uint32_t tdiff_roi_2_sxsy; // word name
		struct {
			uint32_t tdiff_roi_2_sx : 16;
			uint32_t tdiff_roi_2_sy : 16;
		};
	};
	/* TDIFF_ROI_2_EXEY 10'h16C */
	union {
		uint32_t tdiff_roi_2_exey; // word name
		struct {
			uint32_t tdiff_roi_2_ex : 16;
			uint32_t tdiff_roi_2_ey : 16;
		};
	};
	/* TDIFF_ROI_2_TH_Y 10'h170 */
	union {
		uint32_t tdiff_roi_2_th_y; // word name
		struct {
			uint32_t tdiff_roi_2_acc_th_y : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_2_TH_C 10'h174 */
	union {
		uint32_t tdiff_roi_2_th_c; // word name
		struct {
			uint32_t tdiff_roi_2_acc_th_c : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_2_STAT 10'h178 */
	union {
		uint32_t tdiff_roi_2_stat; // word name
		struct {
			uint32_t tdiff_roi_2_avg_y : 16;
			uint32_t tdiff_roi_2_avg_c : 16;
		};
	};
	/* WORD_TDIFF_ROI_3_EN 10'h17C */
	union {
		uint32_t word_tdiff_roi_3_en; // word name
		struct {
			uint32_t tdiff_roi_3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tdiff_roi_3_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TDIFF_ROI_3_SXSY 10'h180 */
	union {
		uint32_t tdiff_roi_3_sxsy; // word name
		struct {
			uint32_t tdiff_roi_3_sx : 16;
			uint32_t tdiff_roi_3_sy : 16;
		};
	};
	/* TDIFF_ROI_3_EXEY 10'h184 */
	union {
		uint32_t tdiff_roi_3_exey; // word name
		struct {
			uint32_t tdiff_roi_3_ex : 16;
			uint32_t tdiff_roi_3_ey : 16;
		};
	};
	/* TDIFF_ROI_3_TH_Y 10'h188 */
	union {
		uint32_t tdiff_roi_3_th_y; // word name
		struct {
			uint32_t tdiff_roi_3_acc_th_y : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_3_TH_C 10'h18C */
	union {
		uint32_t tdiff_roi_3_th_c; // word name
		struct {
			uint32_t tdiff_roi_3_acc_th_c : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_3_STAT 10'h190 */
	union {
		uint32_t tdiff_roi_3_stat; // word name
		struct {
			uint32_t tdiff_roi_3_avg_y : 16;
			uint32_t tdiff_roi_3_avg_c : 16;
		};
	};
	/* DEMO_ROI_MODE 10'h194 */
	union {
		uint32_t demo_roi_mode; // word name
		struct {
			uint32_t demo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t demo_mode : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEMO_ROI_SXSY 10'h198 */
	union {
		uint32_t demo_roi_sxsy; // word name
		struct {
			uint32_t demo_sx : 16;
			uint32_t demo_sy : 16;
		};
	};
	/* DEMO_ROI_EXEY 10'h19C */
	union {
		uint32_t demo_roi_exey; // word name
		struct {
			uint32_t demo_ex : 16;
			uint32_t demo_ey : 16;
		};
	};
	/* WORD_INK_MODE 10'h1A0 */
	union {
		uint32_t word_ink_mode; // word name
		struct {
			uint32_t ink_en : 1;
			uint32_t ink_nrw_en : 1;
			uint32_t : 2; // padding bits
			uint32_t nr_disp_en : 1;
			uint32_t : 3; // padding bits
			uint32_t ink_odd_pxl_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ink_odd_line_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ink_mode : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* WORD_RESERVED_0 10'h1A4 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* WORD_RESERVED_1 10'h1A8 */
	union {
		uint32_t word_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
} CsrBankNr;

#endif