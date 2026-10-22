#ifndef CSR_BANK_GFX_H_
#define CSR_BANK_GFX_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from gfx  ***/
typedef struct csr_bank_gfx {
	/* GFX000 10'h000 */
	union {
		uint32_t gfx000; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX001 10'h004 */
	union {
		uint32_t gfx001; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t irq_clear_cache_overflow : 1;
			uint32_t irq_clear_coordr_frame_end : 1;
			uint32_t irq_clear_coordr_bw_insufficient : 1;
			uint32_t irq_clear_coordr_access_violation : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX002 10'h008 */
	union {
		uint32_t gfx002; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t status_cache_overflow : 1;
			uint32_t status_coordr_frame_end : 1;
			uint32_t status_coordr_bw_insufficient : 1;
			uint32_t status_coordr_access_violation : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX003 10'h00C */
	union {
		uint32_t gfx003; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t irq_mask_cache_overflow : 1;
			uint32_t irq_mask_coordr_frame_end : 1;
			uint32_t irq_mask_coordr_bw_insufficient : 1;
			uint32_t irq_mask_coordr_access_violation : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX004 10'h010 [Unused] */
	uint32_t empty_word_gfx004;
	/* GFX005 10'h014 */
	union {
		uint32_t gfx005; // word name
		struct {
			uint32_t dot_by_dot : 1;
			uint32_t : 7; // padding bits
			uint32_t mono_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t interp_range_x : 2;
			uint32_t : 6; // padding bits
			uint32_t interp_range_y : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* GFX006 10'h018 */
	union {
		uint32_t gfx006; // word name
		struct {
			uint32_t window_all_access : 1;
			uint32_t : 7; // padding bits
			uint32_t statistic_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t src_ini_bayer_phase : 2;
			uint32_t : 6; // padding bits
			uint32_t dst_ini_bayer_phase : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* GFX007 10'h01C */
	union {
		uint32_t gfx007; // word name
		struct {
			uint32_t dst_first_x_int : 13;
			uint32_t : 3; // padding bits
			uint32_t dst_first_y_int : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* GFX008 10'h020 */
	union {
		uint32_t gfx008; // word name
		struct {
			uint32_t width : 9;
			uint32_t : 7; // padding bits
			uint32_t height : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GFX009 10'h024 */
	union {
		uint32_t gfx009; // word name
		struct {
			uint32_t src_region_x_min_int : 13;
			uint32_t : 3; // padding bits
			uint32_t src_region_x_max_int : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* GFX010 10'h028 */
	union {
		uint32_t gfx010; // word name
		struct {
			uint32_t src_region_y_min_int : 13;
			uint32_t : 3; // padding bits
			uint32_t src_region_y_max_int : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* GFX011 10'h02C */
	union {
		uint32_t gfx011; // word name
		struct {
			uint32_t dst_region_x_min_int : 13;
			uint32_t : 3; // padding bits
			uint32_t dst_region_x_max_int : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* GFX012 10'h030 */
	union {
		uint32_t gfx012; // word name
		struct {
			uint32_t dst_region_y_min_int : 13;
			uint32_t : 3; // padding bits
			uint32_t dst_region_y_max_int : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* GFX013 10'h034 */
	union {
		uint32_t gfx013; // word name
		struct {
			uint32_t invalid_r : 10;
			uint32_t : 6; // padding bits
			uint32_t invalid_g : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GFX014 10'h038 */
	union {
		uint32_t gfx014; // word name
		struct {
			uint32_t invalid_b : 10;
			uint32_t : 6; // padding bits
			uint32_t cache_overflow_clip : 1;
			uint32_t : 7; // padding bits
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* GFX015 10'h03C */
	union {
		uint32_t gfx015; // word name
		struct {
			uint32_t shift_nus_x_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX016 10'h040 */
	union {
		uint32_t gfx016; // word name
		struct {
			uint32_t shift_nus_y_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX017 10'h044 */
	union {
		uint32_t gfx017; // word name
		struct {
			uint32_t shift_sph_x_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX018 10'h048 */
	union {
		uint32_t gfx018; // word name
		struct {
			uint32_t shift_sph_y_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX019 10'h04C */
	union {
		uint32_t gfx019; // word name
		struct {
			uint32_t shift_pol_x_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX020 10'h050 */
	union {
		uint32_t gfx020; // word name
		struct {
			uint32_t shift_pol_y_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX021 10'h054 */
	union {
		uint32_t gfx021; // word name
		struct {
			uint32_t shift_squ_x_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX022 10'h058 */
	union {
		uint32_t gfx022; // word name
		struct {
			uint32_t shift_squ_y_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX023 10'h05C */
	union {
		uint32_t gfx023; // word name
		struct {
			uint32_t shift_ldc_x_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX024 10'h060 */
	union {
		uint32_t gfx024; // word name
		struct {
			uint32_t shift_ldc_y_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX025 10'h064 */
	union {
		uint32_t gfx025; // word name
		struct {
			uint32_t nus_x_slope_sign : 1;
			uint32_t : 7; // padding bits
			uint32_t nus_y_slope_sign : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX026 10'h068 */
	union {
		uint32_t gfx026; // word name
		struct {
			uint32_t nus_x_in_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX027 10'h06C */
	union {
		uint32_t gfx027; // word name
		struct {
			uint32_t nus_x_in_2 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX028 10'h070 */
	union {
		uint32_t gfx028; // word name
		struct {
			uint32_t nus_x_out_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX029 10'h074 */
	union {
		uint32_t gfx029; // word name
		struct {
			uint32_t nus_x_out_2 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX030 10'h078 */
	union {
		uint32_t gfx030; // word name
		struct {
			uint32_t nus_x_slope_base_0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX031 10'h07C */
	union {
		uint32_t gfx031; // word name
		struct {
			uint32_t nus_x_slope_base_1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX032 10'h080 */
	union {
		uint32_t gfx032; // word name
		struct {
			uint32_t nus_x_slope_base_2 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX033 10'h084 */
	union {
		uint32_t gfx033; // word name
		struct {
			uint32_t nus_x_slope_step_0 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX034 10'h088 */
	union {
		uint32_t gfx034; // word name
		struct {
			uint32_t nus_x_slope_step_1 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX035 10'h08C */
	union {
		uint32_t gfx035; // word name
		struct {
			uint32_t nus_x_slope_step_2 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX036 10'h090 */
	union {
		uint32_t gfx036; // word name
		struct {
			uint32_t nus_y_in_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX037 10'h094 */
	union {
		uint32_t gfx037; // word name
		struct {
			uint32_t nus_y_in_2 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX038 10'h098 */
	union {
		uint32_t gfx038; // word name
		struct {
			uint32_t nus_y_out_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX039 10'h09C */
	union {
		uint32_t gfx039; // word name
		struct {
			uint32_t nus_y_out_2 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX040 10'h0A0 */
	union {
		uint32_t gfx040; // word name
		struct {
			uint32_t nus_y_slope_base_0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX041 10'h0A4 */
	union {
		uint32_t gfx041; // word name
		struct {
			uint32_t nus_y_slope_base_1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX042 10'h0A8 */
	union {
		uint32_t gfx042; // word name
		struct {
			uint32_t nus_y_slope_base_2 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX043 10'h0AC */
	union {
		uint32_t gfx043; // word name
		struct {
			uint32_t nus_y_slope_step_0 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX044 10'h0B0 */
	union {
		uint32_t gfx044; // word name
		struct {
			uint32_t nus_y_slope_step_1 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX045 10'h0B4 */
	union {
		uint32_t gfx045; // word name
		struct {
			uint32_t nus_y_slope_step_2 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX046 10'h0B8 */
	union {
		uint32_t gfx046; // word name
		struct {
			uint32_t sph_en : 1;
			uint32_t : 7; // padding bits
			uint32_t sph_view_index : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX047 10'h0BC */
	union {
		uint32_t gfx047; // word name
		struct {
			uint32_t sph_view_x_min_int : 13;
			uint32_t : 3; // padding bits
			uint32_t sph_view_x_max_int : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* GFX048 10'h0C0 */
	union {
		uint32_t gfx048; // word name
		struct {
			uint32_t sph_dst_width : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX049 10'h0C4 */
	union {
		uint32_t gfx049; // word name
		struct {
			uint32_t sph_theta_step_0 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX050 10'h0C8 */
	union {
		uint32_t gfx050; // word name
		struct {
			uint32_t sph_theta_step_1 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX051 10'h0CC */
	union {
		uint32_t gfx051; // word name
		struct {
			uint32_t sph_phi_step_0 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX052 10'h0D0 */
	union {
		uint32_t gfx052; // word name
		struct {
			uint32_t sph_phi_step_1 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX053 10'h0D4 */
	union {
		uint32_t gfx053; // word name
		struct {
			uint32_t sph_stitch_r_0 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX054 10'h0D8 */
	union {
		uint32_t gfx054; // word name
		struct {
			uint32_t sph_stitch_r_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX055 10'h0DC */
	union {
		uint32_t gfx055; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t sph_r_ratio_adj_01_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_02_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_03_2s : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* GFX056 10'h0E0 */
	union {
		uint32_t gfx056; // word name
		struct {
			uint32_t sph_r_ratio_adj_04_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_05_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_06_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_07_2s : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* GFX057 10'h0E4 */
	union {
		uint32_t gfx057; // word name
		struct {
			uint32_t sph_r_ratio_adj_08_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_09_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_10_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_11_2s : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* GFX058 10'h0E8 */
	union {
		uint32_t gfx058; // word name
		struct {
			uint32_t sph_r_ratio_adj_12_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_13_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_14_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_15_2s : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* GFX059 10'h0EC */
	union {
		uint32_t gfx059; // word name
		struct {
			uint32_t sph_r_ratio_adj_16_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_17_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_18_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_19_2s : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* GFX060 10'h0F0 */
	union {
		uint32_t gfx060; // word name
		struct {
			uint32_t sph_r_ratio_adj_20_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_21_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_22_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_23_2s : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* GFX061 10'h0F4 */
	union {
		uint32_t gfx061; // word name
		struct {
			uint32_t sph_r_ratio_adj_24_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_25_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_26_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_27_2s : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* GFX062 10'h0F8 */
	union {
		uint32_t gfx062; // word name
		struct {
			uint32_t sph_r_ratio_adj_28_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_29_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_30_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t sph_r_ratio_adj_31_2s : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* GFX063 10'h0FC */
	union {
		uint32_t gfx063; // word name
		struct {
			uint32_t pol_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX064 10'h100 */
	union {
		uint32_t gfx064; // word name
		struct {
			uint32_t pol_r_center : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX065 10'h104 */
	union {
		uint32_t gfx065; // word name
		struct {
			uint32_t pol_r_step : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX066 10'h108 */
	union {
		uint32_t gfx066; // word name
		struct {
			uint32_t pol_theta_step : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX067 10'h10C */
	union {
		uint32_t gfx067; // word name
		struct {
			uint32_t squ_x_strength : 7;
			uint32_t : 1; // padding bits
			uint32_t squ_y_strength : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX068 10'h110 */
	union {
		uint32_t gfx068; // word name
		struct {
			uint32_t ldc_strength : 7;
			uint32_t : 1; // padding bits
			uint32_t ldc_ratio_origin : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX068_0 10'h114 */
	union {
		uint32_t gfx068_0; // word name
		struct {
			uint32_t squ_inv_r : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_I_0 10'h118 */
	union {
		uint32_t word_ldc_entry_lut_i_0; // word name
		struct {
			uint32_t ldc_entry_lut_i_0 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_I_1 10'h11C */
	union {
		uint32_t word_ldc_entry_lut_i_1; // word name
		struct {
			uint32_t ldc_entry_lut_i_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_I_2 10'h120 */
	union {
		uint32_t word_ldc_entry_lut_i_2; // word name
		struct {
			uint32_t ldc_entry_lut_i_2 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_I_3 10'h124 */
	union {
		uint32_t word_ldc_entry_lut_i_3; // word name
		struct {
			uint32_t ldc_entry_lut_i_3 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_I_4 10'h128 */
	union {
		uint32_t word_ldc_entry_lut_i_4; // word name
		struct {
			uint32_t ldc_entry_lut_i_4 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_I_5 10'h12C */
	union {
		uint32_t word_ldc_entry_lut_i_5; // word name
		struct {
			uint32_t ldc_entry_lut_i_5 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_I_6 10'h130 */
	union {
		uint32_t word_ldc_entry_lut_i_6; // word name
		struct {
			uint32_t ldc_entry_lut_i_6 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_I_7 10'h134 */
	union {
		uint32_t word_ldc_entry_lut_i_7; // word name
		struct {
			uint32_t ldc_entry_lut_i_7 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_O_0 10'h138 */
	union {
		uint32_t word_ldc_entry_lut_o_0; // word name
		struct {
			uint32_t ldc_entry_lut_o_0 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_O_1 10'h13C */
	union {
		uint32_t word_ldc_entry_lut_o_1; // word name
		struct {
			uint32_t ldc_entry_lut_o_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_O_2 10'h140 */
	union {
		uint32_t word_ldc_entry_lut_o_2; // word name
		struct {
			uint32_t ldc_entry_lut_o_2 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_O_3 10'h144 */
	union {
		uint32_t word_ldc_entry_lut_o_3; // word name
		struct {
			uint32_t ldc_entry_lut_o_3 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_O_4 10'h148 */
	union {
		uint32_t word_ldc_entry_lut_o_4; // word name
		struct {
			uint32_t ldc_entry_lut_o_4 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_O_5 10'h14C */
	union {
		uint32_t word_ldc_entry_lut_o_5; // word name
		struct {
			uint32_t ldc_entry_lut_o_5 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_O_6 10'h150 */
	union {
		uint32_t word_ldc_entry_lut_o_6; // word name
		struct {
			uint32_t ldc_entry_lut_o_6 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_O_7 10'h154 */
	union {
		uint32_t word_ldc_entry_lut_o_7; // word name
		struct {
			uint32_t ldc_entry_lut_o_7 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_M_0 10'h158 */
	union {
		uint32_t word_ldc_entry_lut_m_0; // word name
		struct {
			uint32_t ldc_entry_lut_m_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t ldc_entry_lut_m_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_M_1 10'h15C */
	union {
		uint32_t word_ldc_entry_lut_m_1; // word name
		struct {
			uint32_t ldc_entry_lut_m_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t ldc_entry_lut_m_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_M_2 10'h160 */
	union {
		uint32_t word_ldc_entry_lut_m_2; // word name
		struct {
			uint32_t ldc_entry_lut_m_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t ldc_entry_lut_m_5 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_M_3 10'h164 */
	union {
		uint32_t word_ldc_entry_lut_m_3; // word name
		struct {
			uint32_t ldc_entry_lut_m_6 : 10;
			uint32_t : 6; // padding bits
			uint32_t ldc_entry_lut_m_7 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* WORD_LDC_ENTRY_LUT_M_4 10'h168 */
	union {
		uint32_t word_ldc_entry_lut_m_4; // word name
		struct {
			uint32_t ldc_entry_lut_m_8 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX069 10'h16C */
	union {
		uint32_t gfx069; // word name
		struct {
			uint32_t ldc_curvature : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX070 10'h170 [Unused] */
	uint32_t empty_word_gfx070;
	/* GFX071 10'h174 [Unused] */
	uint32_t empty_word_gfx071;
	/* GFX072 10'h178 [Unused] */
	uint32_t empty_word_gfx072;
	/* GFX073 10'h17C [Unused] */
	uint32_t empty_word_gfx073;
	/* GFX074 10'h180 [Unused] */
	uint32_t empty_word_gfx074;
	/* GFX075 10'h184 [Unused] */
	uint32_t empty_word_gfx075;
	/* GFX076 10'h188 [Unused] */
	uint32_t empty_word_gfx076;
	/* GFX077 10'h18C [Unused] */
	uint32_t empty_word_gfx077;
	/* GFX078 10'h190 [Unused] */
	uint32_t empty_word_gfx078;
	/* GFX079 10'h194 [Unused] */
	uint32_t empty_word_gfx079;
	/* GFX080 10'h198 [Unused] */
	uint32_t empty_word_gfx080;
	/* GFX081 10'h19C [Unused] */
	uint32_t empty_word_gfx081;
	/* GFX082 10'h1A0 */
	union {
		uint32_t gfx082; // word name
		struct {
			uint32_t dst_0_aff_matrix_00_2s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX083 10'h1A4 */
	union {
		uint32_t gfx083; // word name
		struct {
			uint32_t dst_0_aff_matrix_01_2s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX084 10'h1A8 */
	union {
		uint32_t gfx084; // word name
		struct {
			uint32_t dst_0_aff_matrix_10_2s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX085 10'h1AC */
	union {
		uint32_t gfx085; // word name
		struct {
			uint32_t dst_0_aff_matrix_11_2s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX086 10'h1B0 */
	union {
		uint32_t gfx086; // word name
		struct {
			uint32_t dst_0_aff_shift_x_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX087 10'h1B4 */
	union {
		uint32_t gfx087; // word name
		struct {
			uint32_t dst_0_aff_shift_y_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX088 10'h1B8 */
	union {
		uint32_t gfx088; // word name
		struct {
			uint32_t dst_1_aff_matrix_00_2s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX089 10'h1BC */
	union {
		uint32_t gfx089; // word name
		struct {
			uint32_t dst_1_aff_matrix_01_2s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX090 10'h1C0 */
	union {
		uint32_t gfx090; // word name
		struct {
			uint32_t dst_1_aff_matrix_10_2s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX091 10'h1C4 */
	union {
		uint32_t gfx091; // word name
		struct {
			uint32_t dst_1_aff_matrix_11_2s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX092 10'h1C8 */
	union {
		uint32_t gfx092; // word name
		struct {
			uint32_t dst_1_aff_shift_x_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX093 10'h1CC */
	union {
		uint32_t gfx093; // word name
		struct {
			uint32_t dst_1_aff_shift_y_2s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_U_0 10'h1D0 */
	union {
		uint32_t src_psp_0_u_0; // word name
		struct {
			uint32_t src_psp_0_u_x_coeff_2s_l : 32;
		};
	};
	/* SRC_PSP_0_U_1 10'h1D4 */
	union {
		uint32_t src_psp_0_u_1; // word name
		struct {
			uint32_t src_psp_0_u_x_coeff_2s_h : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_U_2 10'h1D8 */
	union {
		uint32_t src_psp_0_u_2; // word name
		struct {
			uint32_t src_psp_0_u_y_coeff_2s_l : 32;
		};
	};
	/* SRC_PSP_0_U_3 10'h1DC */
	union {
		uint32_t src_psp_0_u_3; // word name
		struct {
			uint32_t src_psp_0_u_y_coeff_2s_h : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_U_4 10'h1E0 */
	union {
		uint32_t src_psp_0_u_4; // word name
		struct {
			uint32_t src_psp_0_u_offset_2s_l : 32;
		};
	};
	/* SRC_PSP_0_U_5 10'h1E4 */
	union {
		uint32_t src_psp_0_u_5; // word name
		struct {
			uint32_t src_psp_0_u_offset_2s_h : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_V_0 10'h1E8 */
	union {
		uint32_t src_psp_0_v_0; // word name
		struct {
			uint32_t src_psp_0_v_x_coeff_2s_l : 32;
		};
	};
	/* SRC_PSP_0_V_1 10'h1EC */
	union {
		uint32_t src_psp_0_v_1; // word name
		struct {
			uint32_t src_psp_0_v_x_coeff_2s_h : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_V_2 10'h1F0 */
	union {
		uint32_t src_psp_0_v_2; // word name
		struct {
			uint32_t src_psp_0_v_y_coeff_2s_l : 32;
		};
	};
	/* SRC_PSP_0_V_3 10'h1F4 */
	union {
		uint32_t src_psp_0_v_3; // word name
		struct {
			uint32_t src_psp_0_v_y_coeff_2s_h : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_V_4 10'h1F8 */
	union {
		uint32_t src_psp_0_v_4; // word name
		struct {
			uint32_t src_psp_0_v_offset_2s_l : 32;
		};
	};
	/* SRC_PSP_0_V_5 10'h1FC */
	union {
		uint32_t src_psp_0_v_5; // word name
		struct {
			uint32_t src_psp_0_v_offset_2s_h : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_W_0 10'h200 */
	union {
		uint32_t src_psp_0_w_0; // word name
		struct {
			uint32_t src_psp_0_w_x_coeff_2s : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_W_1 10'h204 */
	union {
		uint32_t src_psp_0_w_1; // word name
		struct {
			uint32_t src_psp_0_w_y_coeff_2s : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_0_W_2 10'h208 */
	union {
		uint32_t src_psp_0_w_2; // word name
		struct {
			uint32_t src_psp_0_w_offset_2s : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SRC_PSP_1_U_0 10'h20C */
	union {
		uint32_t src_psp_1_u_0; // word name
		struct {
			uint32_t src_psp_1_u_x_coeff_2s_l : 32;
		};
	};
	/* SRC_PSP_1_U_1 10'h210 */
	union {
		uint32_t src_psp_1_u_1; // word name
		struct {
			uint32_t src_psp_1_u_x_coeff_2s_h : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_1_U_2 10'h214 */
	union {
		uint32_t src_psp_1_u_2; // word name
		struct {
			uint32_t src_psp_1_u_y_coeff_2s_l : 32;
		};
	};
	/* SRC_PSP_1_U_3 10'h218 */
	union {
		uint32_t src_psp_1_u_3; // word name
		struct {
			uint32_t src_psp_1_u_y_coeff_2s_h : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_1_U_4 10'h21C */
	union {
		uint32_t src_psp_1_u_4; // word name
		struct {
			uint32_t src_psp_1_u_offset_2s_l : 32;
		};
	};
	/* SRC_PSP_1_U_5 10'h220 */
	union {
		uint32_t src_psp_1_u_5; // word name
		struct {
			uint32_t src_psp_1_u_offset_2s_h : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_1_V_0 10'h224 */
	union {
		uint32_t src_psp_1_v_0; // word name
		struct {
			uint32_t src_psp_1_v_x_coeff_2s_l : 32;
		};
	};
	/* SRC_PSP_1_V_1 10'h228 */
	union {
		uint32_t src_psp_1_v_1; // word name
		struct {
			uint32_t src_psp_1_v_x_coeff_2s_h : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_1_V_2 10'h22C */
	union {
		uint32_t src_psp_1_v_2; // word name
		struct {
			uint32_t src_psp_1_v_y_coeff_2s_l : 32;
		};
	};
	/* SRC_PSP_1_V_3 10'h230 */
	union {
		uint32_t src_psp_1_v_3; // word name
		struct {
			uint32_t src_psp_1_v_y_coeff_2s_h : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_1_V_4 10'h234 */
	union {
		uint32_t src_psp_1_v_4; // word name
		struct {
			uint32_t src_psp_1_v_offset_2s_l : 32;
		};
	};
	/* SRC_PSP_1_V_5 10'h238 */
	union {
		uint32_t src_psp_1_v_5; // word name
		struct {
			uint32_t src_psp_1_v_offset_2s_h : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_1_W_0 10'h23C */
	union {
		uint32_t src_psp_1_w_0; // word name
		struct {
			uint32_t src_psp_1_w_x_coeff_2s : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_1_W_1 10'h240 */
	union {
		uint32_t src_psp_1_w_1; // word name
		struct {
			uint32_t src_psp_1_w_y_coeff_2s : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC_PSP_1_W_2 10'h244 */
	union {
		uint32_t src_psp_1_w_2; // word name
		struct {
			uint32_t src_psp_1_w_offset_2s : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* TABLE 10'h248 */
	union {
		uint32_t table; // word name
		struct {
			uint32_t table_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX094 10'h24C */
	union {
		uint32_t gfx094; // word name
		struct {
			uint32_t status_x_min_int_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t status_x_max_int_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GFX095 10'h250 */
	union {
		uint32_t gfx095; // word name
		struct {
			uint32_t status_y_min_int_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t status_y_max_int_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GFX096 10'h254 */
	union {
		uint32_t gfx096; // word name
		struct {
			uint32_t efuse_dis_gfx_sph_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t efuse_dis_gfx_pol_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t efuse_dis_gfx_squ_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t efuse_dis_gfx_ldc_violation : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* GFX097 10'h258 */
	union {
		uint32_t gfx097; // word name
		struct {
			uint32_t demo_ldc_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX098 10'h25C */
	union {
		uint32_t gfx098; // word name
		struct {
			uint32_t demo_x_min_int : 13;
			uint32_t : 3; // padding bits
			uint32_t demo_x_max_int : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* GFX099 10'h260 */
	union {
		uint32_t gfx099; // word name
		struct {
			uint32_t demo_y_min_int : 13;
			uint32_t : 3; // padding bits
			uint32_t demo_y_max_int : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* GFX100 10'h264 */
	union {
		uint32_t gfx100; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* GFX101 10'h268 */
	union {
		uint32_t gfx101; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
} CsrBankGfx;

#endif