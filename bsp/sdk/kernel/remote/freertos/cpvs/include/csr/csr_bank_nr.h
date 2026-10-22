#ifndef CSR_BANK_NR_H_
#define CSR_BANK_NR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from nr  ***/
typedef struct csr_bank_nr {
	/* NR000 10'h0000 [Unused] */
	uint32_t empty_word_nr000;
	/* NR001 10'h0004 [Unused] */
	uint32_t empty_word_nr001;
	/* NR002 10'h0008 [Unused] */
	uint32_t empty_word_nr002;
	/* NR003 10'h000C [Unused] */
	uint32_t empty_word_nr003;
	/* WORD_MODE 10'h0010 */
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
	/* FIR_MODE 10'h0014 */
	union {
		uint32_t fir_mode; // word name
		struct {
			uint32_t fir_kernel_sel_y : 1;
			uint32_t : 7; // padding bits
			uint32_t fir_weight_y : 5;
			uint32_t : 3; // padding bits
			uint32_t fir_weight_c : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR006 10'h0018 [Unused] */
	uint32_t empty_word_nr006;
	/* NR007 10'h001C [Unused] */
	uint32_t empty_word_nr007;
	/* IIR_MODE 10'h0020 */
	union {
		uint32_t iir_mode; // word name
		struct {
			uint32_t iir_y_conf_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t iir_alpha_y_gain : 3;
			uint32_t : 5; // padding bits
			uint32_t iir_alpha_c_gain : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR009 10'h0024 [Unused] */
	uint32_t empty_word_nr009;
	/* NR010 10'h0028 [Unused] */
	uint32_t empty_word_nr010;
	/* NR011 10'h002C [Unused] */
	uint32_t empty_word_nr011;
	/* NR012 10'h0030 [Unused] */
	uint32_t empty_word_nr012;
	/* NR013 10'h0034 [Unused] */
	uint32_t empty_word_nr013;
	/* NR014 10'h0038 [Unused] */
	uint32_t empty_word_nr014;
	/* MA_Y_LUT_MODE 10'h003C */
	union {
		uint32_t ma_y_lut_mode; // word name
		struct {
			uint32_t ma_y_lut_step : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_Y_LUT_I_0_3 10'h0040 */
	union {
		uint32_t ma_y_lut_i_0_3; // word name
		struct {
			uint32_t ma_y_lut_i_0 : 8;
			uint32_t ma_y_lut_i_1 : 8;
			uint32_t ma_y_lut_i_2 : 8;
			uint32_t ma_y_lut_i_3 : 8;
		};
	};
	/* MA_Y_LUT_I_4_7 10'h0044 */
	union {
		uint32_t ma_y_lut_i_4_7; // word name
		struct {
			uint32_t ma_y_lut_i_4 : 8;
			uint32_t ma_y_lut_i_5 : 8;
			uint32_t ma_y_lut_i_6 : 8;
			uint32_t ma_y_lut_i_7 : 8;
		};
	};
	/* MA_Y_LUT_I_8_8 10'h0048 */
	union {
		uint32_t ma_y_lut_i_8_8; // word name
		struct {
			uint32_t ma_y_lut_i_8 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_Y_LUT_O_0_3 10'h004C */
	union {
		uint32_t ma_y_lut_o_0_3; // word name
		struct {
			uint32_t ma_y_lut_o_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_o_1 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_o_2 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_o_3 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_Y_LUT_O_4_7 10'h0050 */
	union {
		uint32_t ma_y_lut_o_4_7; // word name
		struct {
			uint32_t ma_y_lut_o_4 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_o_5 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_o_6 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_o_7 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_Y_LUT_O_8_8 10'h0054 */
	union {
		uint32_t ma_y_lut_o_8_8; // word name
		struct {
			uint32_t ma_y_lut_o_8 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_Y_LUT_SLOPE_0_1 10'h0058 */
	union {
		uint32_t ma_y_lut_slope_0_1; // word name
		struct {
			uint32_t ma_y_lut_slope_0 : 14;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_slope_1 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_Y_LUT_SLOPE_2_3 10'h005C */
	union {
		uint32_t ma_y_lut_slope_2_3; // word name
		struct {
			uint32_t ma_y_lut_slope_2 : 14;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_slope_3 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_Y_LUT_SLOPE_4_5 10'h0060 */
	union {
		uint32_t ma_y_lut_slope_4_5; // word name
		struct {
			uint32_t ma_y_lut_slope_4 : 14;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_slope_5 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_Y_LUT_SLOPE_6_7 10'h0064 */
	union {
		uint32_t ma_y_lut_slope_6_7; // word name
		struct {
			uint32_t ma_y_lut_slope_6 : 14;
			uint32_t : 2; // padding bits
			uint32_t ma_y_lut_slope_7 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_Y_LP_DYN_GAIN_0 10'h0068 */
	union {
		uint32_t ma_y_lp_dyn_gain_0; // word name
		struct {
			uint32_t ma_y_lp_dyn_gain_th_min : 8;
			uint32_t ma_y_lp_dyn_gain_th_max : 8;
			uint32_t ma_y_lp_dyn_gain_min : 5;
			uint32_t : 3; // padding bits
			uint32_t ma_y_lp_dyn_gain_max : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* MA_Y_LP_DYN_GAIN_1 10'h006C */
	union {
		uint32_t ma_y_lp_dyn_gain_1; // word name
		struct {
			uint32_t ma_y_lp_dyn_gain_slope : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_Y_LP_DIFF_GAIN 10'h0070 */
	union {
		uint32_t ma_y_lp_diff_gain; // word name
		struct {
			uint32_t ma_y_lp_diff_gain_th_min : 8;
			uint32_t ma_y_lp_diff_gain_th_range : 4;
			uint32_t : 4; // padding bits
			uint32_t ma_y_lp_diff_gain_min : 5;
			uint32_t : 3; // padding bits
			uint32_t ma_y_lp_diff_gain_max : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* NR029 10'h0074 [Unused] */
	uint32_t empty_word_nr029;
	/* MC_Y_LUT_MODE 10'h0078 */
	union {
		uint32_t mc_y_lut_mode; // word name
		struct {
			uint32_t mc_y_lut_step : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MC_Y_LUT_I_0_3 10'h007C */
	union {
		uint32_t mc_y_lut_i_0_3; // word name
		struct {
			uint32_t mc_y_lut_i_0 : 8;
			uint32_t mc_y_lut_i_1 : 8;
			uint32_t mc_y_lut_i_2 : 8;
			uint32_t mc_y_lut_i_3 : 8;
		};
	};
	/* MC_Y_LUT_I_4_7 10'h0080 */
	union {
		uint32_t mc_y_lut_i_4_7; // word name
		struct {
			uint32_t mc_y_lut_i_4 : 8;
			uint32_t mc_y_lut_i_5 : 8;
			uint32_t mc_y_lut_i_6 : 8;
			uint32_t mc_y_lut_i_7 : 8;
		};
	};
	/* MC_Y_LUT_I_8_8 10'h0084 */
	union {
		uint32_t mc_y_lut_i_8_8; // word name
		struct {
			uint32_t mc_y_lut_i_8 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MC_Y_LUT_O_0_3 10'h0088 */
	union {
		uint32_t mc_y_lut_o_0_3; // word name
		struct {
			uint32_t mc_y_lut_o_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_o_1 : 6;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_o_2 : 6;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_o_3 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MC_Y_LUT_O_4_7 10'h008C */
	union {
		uint32_t mc_y_lut_o_4_7; // word name
		struct {
			uint32_t mc_y_lut_o_4 : 6;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_o_5 : 6;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_o_6 : 6;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_o_7 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MC_Y_LUT_O_8_8 10'h0090 */
	union {
		uint32_t mc_y_lut_o_8_8; // word name
		struct {
			uint32_t mc_y_lut_o_8 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MC_Y_LUT_SLOPE_0_1 10'h0094 */
	union {
		uint32_t mc_y_lut_slope_0_1; // word name
		struct {
			uint32_t mc_y_lut_slope_0 : 14;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_slope_1 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MC_Y_LUT_SLOPE_2_3 10'h0098 */
	union {
		uint32_t mc_y_lut_slope_2_3; // word name
		struct {
			uint32_t mc_y_lut_slope_2 : 14;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_slope_3 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MC_Y_LUT_SLOPE_4_5 10'h009C */
	union {
		uint32_t mc_y_lut_slope_4_5; // word name
		struct {
			uint32_t mc_y_lut_slope_4 : 14;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_slope_5 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MC_Y_LUT_SLOPE_6_7 10'h00A0 */
	union {
		uint32_t mc_y_lut_slope_6_7; // word name
		struct {
			uint32_t mc_y_lut_slope_6 : 14;
			uint32_t : 2; // padding bits
			uint32_t mc_y_lut_slope_7 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MC_Y_LP_DYN_GAIN_0 10'h00A4 */
	union {
		uint32_t mc_y_lp_dyn_gain_0; // word name
		struct {
			uint32_t mc_y_lp_dyn_gain_th_min : 8;
			uint32_t mc_y_lp_dyn_gain_th_max : 8;
			uint32_t mc_y_lp_dyn_gain_min : 5;
			uint32_t : 3; // padding bits
			uint32_t mc_y_lp_dyn_gain_max : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* MC_Y_LP_DYN_GAIN_1 10'h00A8 */
	union {
		uint32_t mc_y_lp_dyn_gain_1; // word name
		struct {
			uint32_t mc_y_lp_dyn_gain_slope : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MC_Y_LP_DIFF_GAIN 10'h00AC */
	union {
		uint32_t mc_y_lp_diff_gain; // word name
		struct {
			uint32_t mc_y_lp_diff_gain_th_min : 8;
			uint32_t mc_y_lp_diff_gain_th_range : 4;
			uint32_t : 4; // padding bits
			uint32_t mc_y_lp_diff_gain_min : 5;
			uint32_t : 3; // padding bits
			uint32_t mc_y_lp_diff_gain_max : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* MC_Y_RATIO 10'h00B0 */
	union {
		uint32_t mc_y_ratio; // word name
		struct {
			uint32_t mc_y_base_ratio : 4;
			uint32_t : 4; // padding bits
			uint32_t mc_y_base_dyn : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_C_LUT_MODE 10'h00B4 */
	union {
		uint32_t ma_c_lut_mode; // word name
		struct {
			uint32_t ma_c_lut_step : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_C_LUT_I_0_3 10'h00B8 */
	union {
		uint32_t ma_c_lut_i_0_3; // word name
		struct {
			uint32_t ma_c_lut_i_0 : 8;
			uint32_t ma_c_lut_i_1 : 8;
			uint32_t ma_c_lut_i_2 : 8;
			uint32_t ma_c_lut_i_3 : 8;
		};
	};
	/* MA_C_LUT_I_4_7 10'h00BC */
	union {
		uint32_t ma_c_lut_i_4_7; // word name
		struct {
			uint32_t ma_c_lut_i_4 : 8;
			uint32_t ma_c_lut_i_5 : 8;
			uint32_t ma_c_lut_i_6 : 8;
			uint32_t ma_c_lut_i_7 : 8;
		};
	};
	/* MA_C_LUT_I_8_8 10'h00C0 */
	union {
		uint32_t ma_c_lut_i_8_8; // word name
		struct {
			uint32_t ma_c_lut_i_8 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_C_LUT_O_0_3 10'h00C4 */
	union {
		uint32_t ma_c_lut_o_0_3; // word name
		struct {
			uint32_t ma_c_lut_o_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_o_1 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_o_2 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_o_3 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_C_LUT_O_4_7 10'h00C8 */
	union {
		uint32_t ma_c_lut_o_4_7; // word name
		struct {
			uint32_t ma_c_lut_o_4 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_o_5 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_o_6 : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_o_7 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_C_LUT_O_8_8 10'h00CC */
	union {
		uint32_t ma_c_lut_o_8_8; // word name
		struct {
			uint32_t ma_c_lut_o_8 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_C_LUT_SLOPE_0_1 10'h00D0 */
	union {
		uint32_t ma_c_lut_slope_0_1; // word name
		struct {
			uint32_t ma_c_lut_slope_0 : 14;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_slope_1 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_C_LUT_SLOPE_2_3 10'h00D4 */
	union {
		uint32_t ma_c_lut_slope_2_3; // word name
		struct {
			uint32_t ma_c_lut_slope_2 : 14;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_slope_3 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_C_LUT_SLOPE_4_5 10'h00D8 */
	union {
		uint32_t ma_c_lut_slope_4_5; // word name
		struct {
			uint32_t ma_c_lut_slope_4 : 14;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_slope_5 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_C_LUT_SLOPE_6_7 10'h00DC */
	union {
		uint32_t ma_c_lut_slope_6_7; // word name
		struct {
			uint32_t ma_c_lut_slope_6 : 14;
			uint32_t : 2; // padding bits
			uint32_t ma_c_lut_slope_7 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_C_Y_REF_SEL 10'h00E0 */
	union {
		uint32_t ma_c_y_ref_sel; // word name
		struct {
			uint32_t ma_c_weight_y_ref_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MA_C_Y_GAIN_0 10'h00E4 */
	union {
		uint32_t ma_c_y_gain_0; // word name
		struct {
			uint32_t ma_c_weight_y_gain_th_min : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_weight_y_gain_th_max : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_weight_y_gain_min : 6;
			uint32_t : 2; // padding bits
			uint32_t ma_c_weight_y_gain_max : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* MA_C_Y_GAIN_1 10'h00E8 */
	union {
		uint32_t ma_c_y_gain_1; // word name
		struct {
			uint32_t ma_c_weight_y_gain_slope : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR059 10'h00EC [Unused] */
	uint32_t empty_word_nr059;
	/* CORING_TH 10'h00F0 [Unused] */
	uint32_t empty_word_coring_th;
	/* CORING_SLOPE 10'h00F4 [Unused] */
	uint32_t empty_word_coring_slope;
	/* NR062 10'h00F8 [Unused] */
	uint32_t empty_word_nr062;
	/* NR063 10'h00FC [Unused] */
	uint32_t empty_word_nr063;
	/* NR064 10'h0100 [Unused] */
	uint32_t empty_word_nr064;
	/* WORD_ABS_DIFF_HIST_EN 10'h0104 */
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
	/* WORD_ABS_DIFF_HIST_MODE 10'h0108 */
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
	/* ABS_DIFF_HIST_SXSY 10'h010C */
	union {
		uint32_t abs_diff_hist_sxsy; // word name
		struct {
			uint32_t abs_diff_hist_sx : 16;
			uint32_t abs_diff_hist_sy : 16;
		};
	};
	/* ABS_DIFF_HIST_EXEY 10'h0110 */
	union {
		uint32_t abs_diff_hist_exey; // word name
		struct {
			uint32_t abs_diff_hist_ex : 16;
			uint32_t abs_diff_hist_ey : 16;
		};
	};
	/* NR069 10'h0114 [Unused] */
	uint32_t empty_word_nr069;
	/* NR070 10'h0118 [Unused] */
	uint32_t empty_word_nr070;
	/* WORD_ABS_DIFF_HIST_OVERFLOW 10'h011C */
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
	/* WORD_ABS_DIFF_HIST_0 10'h0120 */
	union {
		uint32_t word_abs_diff_hist_0; // word name
		struct {
			uint32_t abs_diff_hist_0 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_1 10'h0124 */
	union {
		uint32_t word_abs_diff_hist_1; // word name
		struct {
			uint32_t abs_diff_hist_1 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_2 10'h0128 */
	union {
		uint32_t word_abs_diff_hist_2; // word name
		struct {
			uint32_t abs_diff_hist_2 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_3 10'h012C */
	union {
		uint32_t word_abs_diff_hist_3; // word name
		struct {
			uint32_t abs_diff_hist_3 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_4 10'h0130 */
	union {
		uint32_t word_abs_diff_hist_4; // word name
		struct {
			uint32_t abs_diff_hist_4 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_5 10'h0134 */
	union {
		uint32_t word_abs_diff_hist_5; // word name
		struct {
			uint32_t abs_diff_hist_5 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_6 10'h0138 */
	union {
		uint32_t word_abs_diff_hist_6; // word name
		struct {
			uint32_t abs_diff_hist_6 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_7 10'h013C */
	union {
		uint32_t word_abs_diff_hist_7; // word name
		struct {
			uint32_t abs_diff_hist_7 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_8 10'h0140 */
	union {
		uint32_t word_abs_diff_hist_8; // word name
		struct {
			uint32_t abs_diff_hist_8 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_9 10'h0144 */
	union {
		uint32_t word_abs_diff_hist_9; // word name
		struct {
			uint32_t abs_diff_hist_9 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_10 10'h0148 */
	union {
		uint32_t word_abs_diff_hist_10; // word name
		struct {
			uint32_t abs_diff_hist_10 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_11 10'h014C */
	union {
		uint32_t word_abs_diff_hist_11; // word name
		struct {
			uint32_t abs_diff_hist_11 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_12 10'h0150 */
	union {
		uint32_t word_abs_diff_hist_12; // word name
		struct {
			uint32_t abs_diff_hist_12 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_13 10'h0154 */
	union {
		uint32_t word_abs_diff_hist_13; // word name
		struct {
			uint32_t abs_diff_hist_13 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_14 10'h0158 */
	union {
		uint32_t word_abs_diff_hist_14; // word name
		struct {
			uint32_t abs_diff_hist_14 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_15 10'h015C */
	union {
		uint32_t word_abs_diff_hist_15; // word name
		struct {
			uint32_t abs_diff_hist_15 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_16 10'h0160 */
	union {
		uint32_t word_abs_diff_hist_16; // word name
		struct {
			uint32_t abs_diff_hist_16 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_17 10'h0164 */
	union {
		uint32_t word_abs_diff_hist_17; // word name
		struct {
			uint32_t abs_diff_hist_17 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_ABS_DIFF_HIST_18 10'h0168 */
	union {
		uint32_t word_abs_diff_hist_18; // word name
		struct {
			uint32_t abs_diff_hist_18 : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_TDIFF_ROI_0_EN 10'h016C */
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
	/* TDIFF_ROI_0_SXSY 10'h0170 */
	union {
		uint32_t tdiff_roi_0_sxsy; // word name
		struct {
			uint32_t tdiff_roi_0_sx : 16;
			uint32_t tdiff_roi_0_sy : 16;
		};
	};
	/* TDIFF_ROI_0_EXEY 10'h0174 */
	union {
		uint32_t tdiff_roi_0_exey; // word name
		struct {
			uint32_t tdiff_roi_0_ex : 16;
			uint32_t tdiff_roi_0_ey : 16;
		};
	};
	/* TDIFF_ROI_0_TH_Y 10'h0178 */
	union {
		uint32_t tdiff_roi_0_th_y; // word name
		struct {
			uint32_t tdiff_roi_0_acc_th_y : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_0_TH_C 10'h017C */
	union {
		uint32_t tdiff_roi_0_th_c; // word name
		struct {
			uint32_t tdiff_roi_0_acc_th_c : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_0_STAT 10'h0180 */
	union {
		uint32_t tdiff_roi_0_stat; // word name
		struct {
			uint32_t tdiff_roi_0_avg_y : 16;
			uint32_t tdiff_roi_0_avg_c : 16;
		};
	};
	/* WORD_TDIFF_ROI_1_EN 10'h0184 */
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
	/* TDIFF_ROI_1_SXSY 10'h0188 */
	union {
		uint32_t tdiff_roi_1_sxsy; // word name
		struct {
			uint32_t tdiff_roi_1_sx : 16;
			uint32_t tdiff_roi_1_sy : 16;
		};
	};
	/* TDIFF_ROI_1_EXEY 10'h018C */
	union {
		uint32_t tdiff_roi_1_exey; // word name
		struct {
			uint32_t tdiff_roi_1_ex : 16;
			uint32_t tdiff_roi_1_ey : 16;
		};
	};
	/* TDIFF_ROI_1_TH_Y 10'h0190 */
	union {
		uint32_t tdiff_roi_1_th_y; // word name
		struct {
			uint32_t tdiff_roi_1_acc_th_y : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_1_TH_C 10'h0194 */
	union {
		uint32_t tdiff_roi_1_th_c; // word name
		struct {
			uint32_t tdiff_roi_1_acc_th_c : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_1_STAT 10'h0198 */
	union {
		uint32_t tdiff_roi_1_stat; // word name
		struct {
			uint32_t tdiff_roi_1_avg_y : 16;
			uint32_t tdiff_roi_1_avg_c : 16;
		};
	};
	/* WORD_TDIFF_ROI_2_EN 10'h019C */
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
	/* TDIFF_ROI_2_SXSY 10'h01A0 */
	union {
		uint32_t tdiff_roi_2_sxsy; // word name
		struct {
			uint32_t tdiff_roi_2_sx : 16;
			uint32_t tdiff_roi_2_sy : 16;
		};
	};
	/* TDIFF_ROI_2_EXEY 10'h01A4 */
	union {
		uint32_t tdiff_roi_2_exey; // word name
		struct {
			uint32_t tdiff_roi_2_ex : 16;
			uint32_t tdiff_roi_2_ey : 16;
		};
	};
	/* TDIFF_ROI_2_TH_Y 10'h01A8 */
	union {
		uint32_t tdiff_roi_2_th_y; // word name
		struct {
			uint32_t tdiff_roi_2_acc_th_y : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_2_TH_C 10'h01AC */
	union {
		uint32_t tdiff_roi_2_th_c; // word name
		struct {
			uint32_t tdiff_roi_2_acc_th_c : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_2_STAT 10'h01B0 */
	union {
		uint32_t tdiff_roi_2_stat; // word name
		struct {
			uint32_t tdiff_roi_2_avg_y : 16;
			uint32_t tdiff_roi_2_avg_c : 16;
		};
	};
	/* WORD_TDIFF_ROI_3_EN 10'h01B4 */
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
	/* TDIFF_ROI_3_SXSY 10'h01B8 */
	union {
		uint32_t tdiff_roi_3_sxsy; // word name
		struct {
			uint32_t tdiff_roi_3_sx : 16;
			uint32_t tdiff_roi_3_sy : 16;
		};
	};
	/* TDIFF_ROI_3_EXEY 10'h01BC */
	union {
		uint32_t tdiff_roi_3_exey; // word name
		struct {
			uint32_t tdiff_roi_3_ex : 16;
			uint32_t tdiff_roi_3_ey : 16;
		};
	};
	/* TDIFF_ROI_3_TH_Y 10'h01C0 */
	union {
		uint32_t tdiff_roi_3_th_y; // word name
		struct {
			uint32_t tdiff_roi_3_acc_th_y : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_3_TH_C 10'h01C4 */
	union {
		uint32_t tdiff_roi_3_th_c; // word name
		struct {
			uint32_t tdiff_roi_3_acc_th_c : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* TDIFF_ROI_3_STAT 10'h01C8 */
	union {
		uint32_t tdiff_roi_3_stat; // word name
		struct {
			uint32_t tdiff_roi_3_avg_y : 16;
			uint32_t tdiff_roi_3_avg_c : 16;
		};
	};
	/* NR115 10'h01CC [Unused] */
	uint32_t empty_word_nr115;
	/* NR116 10'h01D0 [Unused] */
	uint32_t empty_word_nr116;
	/* NR117 10'h01D4 [Unused] */
	uint32_t empty_word_nr117;
	/* NR118 10'h01D8 [Unused] */
	uint32_t empty_word_nr118;
	/* NR119 10'h01DC [Unused] */
	uint32_t empty_word_nr119;
	/* DEMO_ROI_MODE 10'h01E0 */
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
	/* DEMO_ROI_SXSY 10'h01E4 */
	union {
		uint32_t demo_roi_sxsy; // word name
		struct {
			uint32_t demo_sx : 16;
			uint32_t demo_sy : 16;
		};
	};
	/* DEMO_ROI_EXEY 10'h01E8 */
	union {
		uint32_t demo_roi_exey; // word name
		struct {
			uint32_t demo_ex : 16;
			uint32_t demo_ey : 16;
		};
	};
	/* NR123 10'h01EC [Unused] */
	uint32_t empty_word_nr123;
	/* NR124 10'h01F0 [Unused] */
	uint32_t empty_word_nr124;
	/* NR125 10'h01F4 [Unused] */
	uint32_t empty_word_nr125;
	/* WORD_INK_MODE 10'h01F8 */
	union {
		uint32_t word_ink_mode; // word name
		struct {
			uint32_t ink_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ink_mode : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR127 10'h01FC [Unused] */
	uint32_t empty_word_nr127;
	/* NR128 10'h0200 [Unused] */
	uint32_t empty_word_nr128;
	/* NR129 10'h0204 [Unused] */
	uint32_t empty_word_nr129;
	/* WORD_RESERVED_0 10'h0208 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* WORD_RESERVED_1 10'h020C */
	union {
		uint32_t word_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
} CsrBankNr;

#endif