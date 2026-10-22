/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_SHP_H_
#define CSR_BANK_SHP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from shp  ***/
typedef struct csr_bank_shp {
	/* SHP_FRAME_START 10'h000 */
	union {
		uint32_t shp_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 10'h004 */
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
	/* STATUS 10'h008 */
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
	/* IRQ_MASK 10'h00C */
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
	/* SHP_MODE 10'h010 */
	union {
		uint32_t shp_mode; // word name
		struct {
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t ink_num : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESOLUTION 10'h014 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* SHP_LEVEL_GAIN 10'h018 */
	union {
		uint32_t shp_level_gain; // word name
		struct {
			uint32_t level_gain : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LEVEL_GAIN_ROI_0_SET 10'h01C */
	union {
		uint32_t level_gain_roi_0_set; // word name
		struct {
			uint32_t level_gain_roi_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t level_gain_roi_0 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* LEVEL_GAIN_ROI_0_SXSY 10'h020 */
	union {
		uint32_t level_gain_roi_0_sxsy; // word name
		struct {
			uint32_t level_gain_roi0_sx : 16;
			uint32_t level_gain_roi0_sy : 16;
		};
	};
	/* LEVEL_GAIN_ROI_0_EXEY 10'h024 */
	union {
		uint32_t level_gain_roi_0_exey; // word name
		struct {
			uint32_t level_gain_roi0_ex : 16;
			uint32_t level_gain_roi0_ey : 16;
		};
	};
	/* LEVEL_GAIN_ROI_1_SET 10'h028 */
	union {
		uint32_t level_gain_roi_1_set; // word name
		struct {
			uint32_t level_gain_roi_1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t level_gain_roi_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* LEVEL_GAIN_ROI_1_SXSY 10'h02C */
	union {
		uint32_t level_gain_roi_1_sxsy; // word name
		struct {
			uint32_t level_gain_roi1_sx : 16;
			uint32_t level_gain_roi1_sy : 16;
		};
	};
	/* LEVEL_GAIN_ROI_1_EXEY 10'h030 */
	union {
		uint32_t level_gain_roi_1_exey; // word name
		struct {
			uint32_t level_gain_roi1_ex : 16;
			uint32_t level_gain_roi1_ey : 16;
		};
	};
	/* LEVEL_GAIN_ROI_2_SET 10'h034 */
	union {
		uint32_t level_gain_roi_2_set; // word name
		struct {
			uint32_t level_gain_roi_2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t level_gain_roi_2 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* LEVEL_GAIN_ROI_2_SXSY 10'h038 */
	union {
		uint32_t level_gain_roi_2_sxsy; // word name
		struct {
			uint32_t level_gain_roi2_sx : 16;
			uint32_t level_gain_roi2_sy : 16;
		};
	};
	/* LEVEL_GAIN_ROI_2_EXEY 10'h03C */
	union {
		uint32_t level_gain_roi_2_exey; // word name
		struct {
			uint32_t level_gain_roi2_ex : 16;
			uint32_t level_gain_roi2_ey : 16;
		};
	};
	/* LEVEL_GAIN_ROI_3_SET 10'h040 */
	union {
		uint32_t level_gain_roi_3_set; // word name
		struct {
			uint32_t level_gain_roi_3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t level_gain_roi_3 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* LEVEL_GAIN_ROI_3_SXSY 10'h044 */
	union {
		uint32_t level_gain_roi_3_sxsy; // word name
		struct {
			uint32_t level_gain_roi3_sx : 16;
			uint32_t level_gain_roi3_sy : 16;
		};
	};
	/* LEVEL_GAIN_ROI_3_EXEY 10'h048 */
	union {
		uint32_t level_gain_roi_3_exey; // word name
		struct {
			uint32_t level_gain_roi3_ex : 16;
			uint32_t level_gain_roi3_ey : 16;
		};
	};
	/* RING_CONTROL 10'h04C */
	union {
		uint32_t ring_control; // word name
		struct {
			uint32_t ring_control_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BOUNDARY 10'h050 */
	union {
		uint32_t boundary; // word name
		struct {
			uint32_t minmax_outer_bound : 3;
			uint32_t : 5; // padding bits
			uint32_t minmax_central_bound : 3;
			uint32_t : 5; // padding bits
			uint32_t var_central_bound : 3;
			uint32_t : 5; // padding bits
			uint32_t var_edge_bound : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* VARIANCE_NORM_0 10'h054 */
	union {
		uint32_t variance_norm_0; // word name
		struct {
			uint32_t var_central_norm : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VARIANCE_NORM_1 10'h058 */
	union {
		uint32_t variance_norm_1; // word name
		struct {
			uint32_t var_edge_norm : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_1 10'h05C */
	union {
		uint32_t gain_1; // word name
		struct {
			uint32_t hpf_hpf_gain : 8;
			uint32_t hpf_bpf_gain : 8;
			uint32_t hpf_lpf_gain : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_2 10'h060 */
	union {
		uint32_t gain_2; // word name
		struct {
			uint32_t bpf_bpf_gain : 8;
			uint32_t bpf_lpf_gain : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_CURVE_INI 10'h064 */
	union {
		uint32_t gain_curve_ini; // word name
		struct {
			uint32_t high_band_gain_curve_y_ini : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_ini : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_0 10'h068 */
	union {
		uint32_t gain_curve_0; // word name
		struct {
			uint32_t high_band_gain_curve_x_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_0 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_1 10'h06C */
	union {
		uint32_t gain_curve_1; // word name
		struct {
			uint32_t high_band_gain_curve_x_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_2 10'h070 */
	union {
		uint32_t gain_curve_2; // word name
		struct {
			uint32_t high_band_gain_curve_x_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_2 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_3 10'h074 */
	union {
		uint32_t gain_curve_3; // word name
		struct {
			uint32_t high_band_gain_curve_x_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_4 10'h078 */
	union {
		uint32_t gain_curve_4; // word name
		struct {
			uint32_t high_band_gain_curve_x_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_4 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_5 10'h07C */
	union {
		uint32_t gain_curve_5; // word name
		struct {
			uint32_t high_band_gain_curve_x_5 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_5 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_6 10'h080 */
	union {
		uint32_t gain_curve_6; // word name
		struct {
			uint32_t high_band_gain_curve_x_6 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_6 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_7 10'h084 */
	union {
		uint32_t gain_curve_7; // word name
		struct {
			uint32_t high_band_gain_curve_x_7 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_7 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_8 10'h088 */
	union {
		uint32_t gain_curve_8; // word name
		struct {
			uint32_t high_band_gain_curve_x_8 : 10;
			uint32_t : 6; // padding bits
			uint32_t high_band_gain_curve_y_8 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_9 10'h08C */
	union {
		uint32_t gain_curve_9; // word name
		struct {
			uint32_t middle_band_gain_curve_x_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_0 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_10 10'h090 */
	union {
		uint32_t gain_curve_10; // word name
		struct {
			uint32_t middle_band_gain_curve_x_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_11 10'h094 */
	union {
		uint32_t gain_curve_11; // word name
		struct {
			uint32_t middle_band_gain_curve_x_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_2 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_12 10'h098 */
	union {
		uint32_t gain_curve_12; // word name
		struct {
			uint32_t middle_band_gain_curve_x_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_13 10'h09C */
	union {
		uint32_t gain_curve_13; // word name
		struct {
			uint32_t middle_band_gain_curve_x_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_4 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_14 10'h0A0 */
	union {
		uint32_t gain_curve_14; // word name
		struct {
			uint32_t middle_band_gain_curve_x_5 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_5 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_15 10'h0A4 */
	union {
		uint32_t gain_curve_15; // word name
		struct {
			uint32_t middle_band_gain_curve_x_6 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_6 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_16 10'h0A8 */
	union {
		uint32_t gain_curve_16; // word name
		struct {
			uint32_t middle_band_gain_curve_x_7 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_7 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_17 10'h0AC */
	union {
		uint32_t gain_curve_17; // word name
		struct {
			uint32_t middle_band_gain_curve_x_8 : 10;
			uint32_t : 6; // padding bits
			uint32_t middle_band_gain_curve_y_8 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_M_0 10'h0B0 */
	union {
		uint32_t gain_curve_m_0; // word name
		struct {
			uint32_t high_band_gain_curve_m_0_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t high_band_gain_curve_m_1_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_1 10'h0B4 */
	union {
		uint32_t gain_curve_m_1; // word name
		struct {
			uint32_t high_band_gain_curve_m_2_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t high_band_gain_curve_m_3_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_2 10'h0B8 */
	union {
		uint32_t gain_curve_m_2; // word name
		struct {
			uint32_t high_band_gain_curve_m_4_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t high_band_gain_curve_m_5_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_3 10'h0BC */
	union {
		uint32_t gain_curve_m_3; // word name
		struct {
			uint32_t high_band_gain_curve_m_6_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t high_band_gain_curve_m_7_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_4 10'h0C0 */
	union {
		uint32_t gain_curve_m_4; // word name
		struct {
			uint32_t high_band_gain_curve_m_8_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t middle_band_gain_curve_m_8_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_5 10'h0C4 */
	union {
		uint32_t gain_curve_m_5; // word name
		struct {
			uint32_t middle_band_gain_curve_m_0_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t middle_band_gain_curve_m_1_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_6 10'h0C8 */
	union {
		uint32_t gain_curve_m_6; // word name
		struct {
			uint32_t middle_band_gain_curve_m_2_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t middle_band_gain_curve_m_3_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_7 10'h0CC */
	union {
		uint32_t gain_curve_m_7; // word name
		struct {
			uint32_t middle_band_gain_curve_m_4_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t middle_band_gain_curve_m_5_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_8 10'h0D0 */
	union {
		uint32_t gain_curve_m_8; // word name
		struct {
			uint32_t middle_band_gain_curve_m_6_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t middle_band_gain_curve_m_7_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* LUMA_LUT_INI 10'h0D4 */
	union {
		uint32_t luma_lut_ini; // word name
		struct {
			uint32_t luma_lut_y_ini : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_0_XY 10'h0D8 */
	union {
		uint32_t luma_lut_0_xy; // word name
		struct {
			uint32_t luma_lut_x_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_0 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_0_M 10'h0DC */
	union {
		uint32_t luma_lut_0_m; // word name
		struct {
			uint32_t luma_lut_m_0_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_1_XY 10'h0E0 */
	union {
		uint32_t luma_lut_1_xy; // word name
		struct {
			uint32_t luma_lut_x_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_1_M 10'h0E4 */
	union {
		uint32_t luma_lut_1_m; // word name
		struct {
			uint32_t luma_lut_m_1_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_2_XY 10'h0E8 */
	union {
		uint32_t luma_lut_2_xy; // word name
		struct {
			uint32_t luma_lut_x_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_2 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_2_M 10'h0EC */
	union {
		uint32_t luma_lut_2_m; // word name
		struct {
			uint32_t luma_lut_m_2_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_3_XY 10'h0F0 */
	union {
		uint32_t luma_lut_3_xy; // word name
		struct {
			uint32_t luma_lut_x_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_3_M 10'h0F4 */
	union {
		uint32_t luma_lut_3_m; // word name
		struct {
			uint32_t luma_lut_m_3_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_4_XY 10'h0F8 */
	union {
		uint32_t luma_lut_4_xy; // word name
		struct {
			uint32_t luma_lut_x_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_4 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_4_M 10'h0FC */
	union {
		uint32_t luma_lut_4_m; // word name
		struct {
			uint32_t luma_lut_m_4_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_5_XY 10'h100 */
	union {
		uint32_t luma_lut_5_xy; // word name
		struct {
			uint32_t luma_lut_x_5 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_5 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_5_M 10'h104 */
	union {
		uint32_t luma_lut_5_m; // word name
		struct {
			uint32_t luma_lut_m_5_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_6_XY 10'h108 */
	union {
		uint32_t luma_lut_6_xy; // word name
		struct {
			uint32_t luma_lut_x_6 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_6 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_6_M 10'h10C */
	union {
		uint32_t luma_lut_6_m; // word name
		struct {
			uint32_t luma_lut_m_6_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_7_XY 10'h110 */
	union {
		uint32_t luma_lut_7_xy; // word name
		struct {
			uint32_t luma_lut_x_7 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_7 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_7_M 10'h114 */
	union {
		uint32_t luma_lut_7_m; // word name
		struct {
			uint32_t luma_lut_m_7_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_8_XY 10'h118 */
	union {
		uint32_t luma_lut_8_xy; // word name
		struct {
			uint32_t luma_lut_x_8 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_8 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_8_M 10'h11C */
	union {
		uint32_t luma_lut_8_m; // word name
		struct {
			uint32_t luma_lut_m_8_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_9_M 10'h120 */
	union {
		uint32_t luma_lut_9_m; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t luma_lut_m_9_2s : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SOFT_CLIP 10'h124 */
	union {
		uint32_t soft_clip; // word name
		struct {
			uint32_t soft_clip_slope : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_LPF_SET 10'h128 */
	union {
		uint32_t rgl_y_lpf_set; // word name
		struct {
			uint32_t rgl_y_lpf_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rgl_y_lpf_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_LPF_RGL_WH 10'h12C */
	union {
		uint32_t rgl_y_lpf_rgl_wh; // word name
		struct {
			uint32_t rgl_y_lpf_rgl_wd : 13;
			uint32_t : 3; // padding bits
			uint32_t rgl_y_lpf_rgl_ht : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* RGL_Y_LPF_X 10'h130 */
	union {
		uint32_t rgl_y_lpf_x; // word name
		struct {
			uint32_t rgl_y_lpf_sx : 16;
			uint32_t rgl_y_lpf_ex : 16;
		};
	};
	/* RGL_Y_LPF_Y 10'h134 */
	union {
		uint32_t rgl_y_lpf_y; // word name
		struct {
			uint32_t rgl_y_lpf_sy : 16;
			uint32_t rgl_y_lpf_ey : 16;
		};
	};
	/* RGL_Y_LPF_XY_CNT_INI 10'h138 */
	union {
		uint32_t rgl_y_lpf_xy_cnt_ini; // word name
		struct {
			uint32_t rgl_y_lpf_x_cnt_ini : 13;
			uint32_t : 3; // padding bits
			uint32_t rgl_y_lpf_y_cnt_ini : 16;
		};
	};
	/* RGL_Y_LPF_R_CNT_SET 10'h13C */
	union {
		uint32_t rgl_y_lpf_r_cnt_set; // word name
		struct {
			uint32_t rgl_y_lpf_r_cnt_ini : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_LPF_PIX_NUMBER 10'h140 */
	union {
		uint32_t rgl_y_lpf_pix_number; // word name
		struct {
			uint32_t rgl_y_lpf_pix_num : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* ROI_Y_LPF_AVG_0_SET 10'h144 */
	union {
		uint32_t roi_y_lpf_avg_0_set; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_y_lpf_avg_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROI_Y_LPF_AVG_0_SXSY 10'h148 */
	union {
		uint32_t roi_y_lpf_avg_0_sxsy; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_sx : 16;
			uint32_t roi_y_lpf_avg_0_sy : 16;
		};
	};
	/* ROI_Y_LPF_AVG_0_EXEY 10'h14C */
	union {
		uint32_t roi_y_lpf_avg_0_exey; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_ex : 16;
			uint32_t roi_y_lpf_avg_0_ey : 16;
		};
	};
	/* ROI_Y_LPF_AVG_0_PIX_NUMBER 10'h150 */
	union {
		uint32_t roi_y_lpf_avg_0_pix_number; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_pix_num : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* ROI_Y_LPF_AVG_0_AVERAGE 10'h154 */
	union {
		uint32_t roi_y_lpf_avg_0_average; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_avg : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_STAT_CTRL 10'h158 */
	union {
		uint32_t rgl_y_stat_ctrl; // word name
		struct {
			uint32_t rgl_y_stat_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_STAT_READ_ADDR 10'h15C */
	union {
		uint32_t rgl_y_stat_read_addr; // word name
		struct {
			uint32_t rgl_y_stat_r_addr : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_STAT_READ_DATA 10'h160 */
	union {
		uint32_t rgl_y_stat_read_data; // word name
		struct {
			uint32_t rgl_y_stat_r_data : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEMO_SET 10'h164 */
	union {
		uint32_t demo_set; // word name
		struct {
			uint32_t demo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEMO_X 10'h168 */
	union {
		uint32_t demo_x; // word name
		struct {
			uint32_t demo_x_min : 16;
			uint32_t demo_x_max : 16;
		};
	};
	/* DEMO_Y 10'h16C */
	union {
		uint32_t demo_y; // word name
		struct {
			uint32_t demo_y_min : 16;
			uint32_t demo_y_max : 16;
		};
	};
	/* DEBUG_MON 10'h170 */
	union {
		uint32_t debug_mon; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_RESERVED 10'h174 */
	union {
		uint32_t shp_reserved; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SHP_EDGE_GAIN 10'h178 */
	union {
		uint32_t shp_edge_gain; // word name
		struct {
			uint32_t edge_gain : 5;
			uint32_t : 3; // padding bits
			uint32_t edge_variance_tolarance : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PEAK_GAIN_1 10'h17C */
	union {
		uint32_t peak_gain_1; // word name
		struct {
			uint32_t peak_gain : 6;
			uint32_t : 2; // padding bits
			uint32_t overshoot_gain : 5;
			uint32_t : 3; // padding bits
			uint32_t undershoot_gain : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PEAK_GAIN_2 10'h180 */
	union {
		uint32_t peak_gain_2; // word name
		struct {
			uint32_t peak_variance_tolarance : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ATPG_CTRL 10'h184 */
	union {
		uint32_t atpg_ctrl; // word name
		struct {
			uint32_t atpg_ctrl_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t atpg_ctrl_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
#ifdef CONFIG_FPGA
	/* FPGA_RGL_Y_STAT_R_DATA_0 10'h188 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_0; // word name
		struct {
			uint32_t rgl_y_stat_r_data_0 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_1 10'h18C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_1; // word name
		struct {
			uint32_t rgl_y_stat_r_data_1 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_2 10'h190 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_2; // word name
		struct {
			uint32_t rgl_y_stat_r_data_2 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_3 10'h194 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_3; // word name
		struct {
			uint32_t rgl_y_stat_r_data_3 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_4 10'h198 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_4; // word name
		struct {
			uint32_t rgl_y_stat_r_data_4 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_5 10'h19C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_5; // word name
		struct {
			uint32_t rgl_y_stat_r_data_5 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_6 10'h1A0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_6; // word name
		struct {
			uint32_t rgl_y_stat_r_data_6 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_7 10'h1A4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_7; // word name
		struct {
			uint32_t rgl_y_stat_r_data_7 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_8 10'h1A8 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_8; // word name
		struct {
			uint32_t rgl_y_stat_r_data_8 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_9 10'h1AC */
	union {
		uint32_t fpga_rgl_y_stat_r_data_9; // word name
		struct {
			uint32_t rgl_y_stat_r_data_9 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_10 10'h1B0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_10; // word name
		struct {
			uint32_t rgl_y_stat_r_data_10 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_11 10'h1B4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_11; // word name
		struct {
			uint32_t rgl_y_stat_r_data_11 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_12 10'h1B8 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_12; // word name
		struct {
			uint32_t rgl_y_stat_r_data_12 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_13 10'h1BC */
	union {
		uint32_t fpga_rgl_y_stat_r_data_13; // word name
		struct {
			uint32_t rgl_y_stat_r_data_13 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_14 10'h1C0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_14; // word name
		struct {
			uint32_t rgl_y_stat_r_data_14 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_15 10'h1C4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_15; // word name
		struct {
			uint32_t rgl_y_stat_r_data_15 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_16 10'h1C8 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_16; // word name
		struct {
			uint32_t rgl_y_stat_r_data_16 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_17 10'h1CC */
	union {
		uint32_t fpga_rgl_y_stat_r_data_17; // word name
		struct {
			uint32_t rgl_y_stat_r_data_17 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_18 10'h1D0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_18; // word name
		struct {
			uint32_t rgl_y_stat_r_data_18 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_19 10'h1D4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_19; // word name
		struct {
			uint32_t rgl_y_stat_r_data_19 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_20 10'h1D8 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_20; // word name
		struct {
			uint32_t rgl_y_stat_r_data_20 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_21 10'h1DC */
	union {
		uint32_t fpga_rgl_y_stat_r_data_21; // word name
		struct {
			uint32_t rgl_y_stat_r_data_21 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_22 10'h1E0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_22; // word name
		struct {
			uint32_t rgl_y_stat_r_data_22 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_23 10'h1E4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_23; // word name
		struct {
			uint32_t rgl_y_stat_r_data_23 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_24 10'h1E8 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_24; // word name
		struct {
			uint32_t rgl_y_stat_r_data_24 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_25 10'h1EC */
	union {
		uint32_t fpga_rgl_y_stat_r_data_25; // word name
		struct {
			uint32_t rgl_y_stat_r_data_25 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_26 10'h1F0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_26; // word name
		struct {
			uint32_t rgl_y_stat_r_data_26 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_27 10'h1F4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_27; // word name
		struct {
			uint32_t rgl_y_stat_r_data_27 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_28 10'h1F8 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_28; // word name
		struct {
			uint32_t rgl_y_stat_r_data_28 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_29 10'h1FC */
	union {
		uint32_t fpga_rgl_y_stat_r_data_29; // word name
		struct {
			uint32_t rgl_y_stat_r_data_29 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_30 10'h200 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_30; // word name
		struct {
			uint32_t rgl_y_stat_r_data_30 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_31 10'h204 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_31; // word name
		struct {
			uint32_t rgl_y_stat_r_data_31 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_32 10'h208 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_32; // word name
		struct {
			uint32_t rgl_y_stat_r_data_32 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_33 10'h20C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_33; // word name
		struct {
			uint32_t rgl_y_stat_r_data_33 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_34 10'h210 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_34; // word name
		struct {
			uint32_t rgl_y_stat_r_data_34 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_35 10'h214 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_35; // word name
		struct {
			uint32_t rgl_y_stat_r_data_35 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_36 10'h218 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_36; // word name
		struct {
			uint32_t rgl_y_stat_r_data_36 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_37 10'h21C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_37; // word name
		struct {
			uint32_t rgl_y_stat_r_data_37 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_38 10'h220 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_38; // word name
		struct {
			uint32_t rgl_y_stat_r_data_38 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_39 10'h224 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_39; // word name
		struct {
			uint32_t rgl_y_stat_r_data_39 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_40 10'h228 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_40; // word name
		struct {
			uint32_t rgl_y_stat_r_data_40 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_41 10'h22C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_41; // word name
		struct {
			uint32_t rgl_y_stat_r_data_41 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_42 10'h230 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_42; // word name
		struct {
			uint32_t rgl_y_stat_r_data_42 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_43 10'h234 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_43; // word name
		struct {
			uint32_t rgl_y_stat_r_data_43 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_44 10'h238 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_44; // word name
		struct {
			uint32_t rgl_y_stat_r_data_44 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_45 10'h23C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_45; // word name
		struct {
			uint32_t rgl_y_stat_r_data_45 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_46 10'h240 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_46; // word name
		struct {
			uint32_t rgl_y_stat_r_data_46 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_47 10'h244 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_47; // word name
		struct {
			uint32_t rgl_y_stat_r_data_47 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_48 10'h248 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_48; // word name
		struct {
			uint32_t rgl_y_stat_r_data_48 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_49 10'h24C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_49; // word name
		struct {
			uint32_t rgl_y_stat_r_data_49 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_50 10'h250 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_50; // word name
		struct {
			uint32_t rgl_y_stat_r_data_50 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_51 10'h254 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_51; // word name
		struct {
			uint32_t rgl_y_stat_r_data_51 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_52 10'h258 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_52; // word name
		struct {
			uint32_t rgl_y_stat_r_data_52 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_53 10'h25C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_53; // word name
		struct {
			uint32_t rgl_y_stat_r_data_53 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_54 10'h260 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_54; // word name
		struct {
			uint32_t rgl_y_stat_r_data_54 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_55 10'h264 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_55; // word name
		struct {
			uint32_t rgl_y_stat_r_data_55 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_56 10'h268 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_56; // word name
		struct {
			uint32_t rgl_y_stat_r_data_56 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_57 10'h26C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_57; // word name
		struct {
			uint32_t rgl_y_stat_r_data_57 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_58 10'h270 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_58; // word name
		struct {
			uint32_t rgl_y_stat_r_data_58 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_59 10'h274 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_59; // word name
		struct {
			uint32_t rgl_y_stat_r_data_59 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_60 10'h278 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_60; // word name
		struct {
			uint32_t rgl_y_stat_r_data_60 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_61 10'h27C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_61; // word name
		struct {
			uint32_t rgl_y_stat_r_data_61 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_62 10'h280 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_62; // word name
		struct {
			uint32_t rgl_y_stat_r_data_62 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_63 10'h284 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_63; // word name
		struct {
			uint32_t rgl_y_stat_r_data_63 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_64 10'h288 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_64; // word name
		struct {
			uint32_t rgl_y_stat_r_data_64 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_65 10'h28C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_65; // word name
		struct {
			uint32_t rgl_y_stat_r_data_65 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_66 10'h290 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_66; // word name
		struct {
			uint32_t rgl_y_stat_r_data_66 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_67 10'h294 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_67; // word name
		struct {
			uint32_t rgl_y_stat_r_data_67 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_68 10'h298 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_68; // word name
		struct {
			uint32_t rgl_y_stat_r_data_68 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_69 10'h29C */
	union {
		uint32_t fpga_rgl_y_stat_r_data_69; // word name
		struct {
			uint32_t rgl_y_stat_r_data_69 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_70 10'h2A0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_70; // word name
		struct {
			uint32_t rgl_y_stat_r_data_70 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_71 10'h2A4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_71; // word name
		struct {
			uint32_t rgl_y_stat_r_data_71 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_72 10'h2A8 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_72; // word name
		struct {
			uint32_t rgl_y_stat_r_data_72 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_73 10'h2AC */
	union {
		uint32_t fpga_rgl_y_stat_r_data_73; // word name
		struct {
			uint32_t rgl_y_stat_r_data_73 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_74 10'h2B0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_74; // word name
		struct {
			uint32_t rgl_y_stat_r_data_74 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_75 10'h2B4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_75; // word name
		struct {
			uint32_t rgl_y_stat_r_data_75 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_76 10'h2B8 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_76; // word name
		struct {
			uint32_t rgl_y_stat_r_data_76 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_77 10'h2BC */
	union {
		uint32_t fpga_rgl_y_stat_r_data_77; // word name
		struct {
			uint32_t rgl_y_stat_r_data_77 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_78 10'h2C0 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_78; // word name
		struct {
			uint32_t rgl_y_stat_r_data_78 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_RGL_Y_STAT_R_DATA_79 10'h2C4 */
	union {
		uint32_t fpga_rgl_y_stat_r_data_79; // word name
		struct {
			uint32_t rgl_y_stat_r_data_79 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
#endif /* CONFIG_FPGA */
} CsrBankShp;

#endif
