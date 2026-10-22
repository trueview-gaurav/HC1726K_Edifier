#ifndef CSR_BANK_SHP_H_
#define CSR_BANK_SHP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from shp  ***/
typedef struct csr_bank_shp {
	/* WORD_FRAME_START 9'h000 */
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
	/* IRQ_CLEAR 9'h004 */
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
	/* STATUS 9'h008 */
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
	/* IRQ_MASK 9'h00C */
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
	/* WORD_MODE 9'h010 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t sample_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESOLUTION 9'h014 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORD_LEVEL_GAIN 9'h018 */
	union {
		uint32_t word_level_gain; // word name
		struct {
			uint32_t level_gain : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LEVEL_GAIN_ROI_0_SET 9'h01C */
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
	/* LEVEL_GAIN_ROI_0_SXSY 9'h020 */
	union {
		uint32_t level_gain_roi_0_sxsy; // word name
		struct {
			uint32_t level_gain_roi0_sx : 16;
			uint32_t level_gain_roi0_sy : 16;
		};
	};
	/* LEVEL_GAIN_ROI_0_EXEY 9'h024 */
	union {
		uint32_t level_gain_roi_0_exey; // word name
		struct {
			uint32_t level_gain_roi0_ex : 16;
			uint32_t level_gain_roi0_ey : 16;
		};
	};
	/* LEVEL_GAIN_ROI_1_SET 9'h028 */
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
	/* LEVEL_GAIN_ROI_1_SXSY 9'h02C */
	union {
		uint32_t level_gain_roi_1_sxsy; // word name
		struct {
			uint32_t level_gain_roi1_sx : 16;
			uint32_t level_gain_roi1_sy : 16;
		};
	};
	/* LEVEL_GAIN_ROI_1_EXEY 9'h030 */
	union {
		uint32_t level_gain_roi_1_exey; // word name
		struct {
			uint32_t level_gain_roi1_ex : 16;
			uint32_t level_gain_roi1_ey : 16;
		};
	};
	/* LEVEL_GAIN_ROI_2_SET 9'h034 */
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
	/* LEVEL_GAIN_ROI_2_SXSY 9'h038 */
	union {
		uint32_t level_gain_roi_2_sxsy; // word name
		struct {
			uint32_t level_gain_roi2_sx : 16;
			uint32_t level_gain_roi2_sy : 16;
		};
	};
	/* LEVEL_GAIN_ROI_2_EXEY 9'h03C */
	union {
		uint32_t level_gain_roi_2_exey; // word name
		struct {
			uint32_t level_gain_roi2_ex : 16;
			uint32_t level_gain_roi2_ey : 16;
		};
	};
	/* LEVEL_GAIN_ROI_3_SET 9'h040 */
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
	/* LEVEL_GAIN_ROI_3_SXSY 9'h044 */
	union {
		uint32_t level_gain_roi_3_sxsy; // word name
		struct {
			uint32_t level_gain_roi3_sx : 16;
			uint32_t level_gain_roi3_sy : 16;
		};
	};
	/* LEVEL_GAIN_ROI_3_EXEY 9'h048 */
	union {
		uint32_t level_gain_roi_3_exey; // word name
		struct {
			uint32_t level_gain_roi3_ex : 16;
			uint32_t level_gain_roi3_ey : 16;
		};
	};
	/* GAIN 9'h04C */
	union {
		uint32_t gain; // word name
		struct {
			uint32_t bpf_gain : 8;
			uint32_t hpf_gain : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_CURVE_INI 9'h050 */
	union {
		uint32_t gain_curve_ini; // word name
		struct {
			uint32_t gain_curve_y_ini : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_CURVE_0 9'h054 */
	union {
		uint32_t gain_curve_0; // word name
		struct {
			uint32_t gain_curve_x_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t gain_curve_y_0 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_1 9'h058 */
	union {
		uint32_t gain_curve_1; // word name
		struct {
			uint32_t gain_curve_x_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t gain_curve_y_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_2 9'h05C */
	union {
		uint32_t gain_curve_2; // word name
		struct {
			uint32_t gain_curve_x_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t gain_curve_y_2 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_3 9'h060 */
	union {
		uint32_t gain_curve_3; // word name
		struct {
			uint32_t gain_curve_x_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t gain_curve_y_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_4 9'h064 */
	union {
		uint32_t gain_curve_4; // word name
		struct {
			uint32_t gain_curve_x_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t gain_curve_y_4 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* GAIN_CURVE_M_0 9'h068 */
	union {
		uint32_t gain_curve_m_0; // word name
		struct {
			uint32_t gain_curve_m_0_2s : 6;
			uint32_t : 2; // padding bits
			uint32_t gain_curve_m_1_2s : 6;
			uint32_t : 2; // padding bits
			uint32_t gain_curve_m_2_2s : 6;
			uint32_t : 2; // padding bits
			uint32_t gain_curve_m_3_2s : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* GAIN_CURVE_M_1 9'h06C */
	union {
		uint32_t gain_curve_m_1; // word name
		struct {
			uint32_t gain_curve_m_4_2s : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_INI 9'h070 */
	union {
		uint32_t luma_lut_ini; // word name
		struct {
			uint32_t luma_lut_y_ini : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LUMA_LUT_0_XY 9'h074 */
	union {
		uint32_t luma_lut_0_xy; // word name
		struct {
			uint32_t luma_lut_x_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_0 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_0_M 9'h078 */
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
	/* LUMA_LUT_1_XY 9'h07C */
	union {
		uint32_t luma_lut_1_xy; // word name
		struct {
			uint32_t luma_lut_x_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_1_M 9'h080 */
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
	/* LUMA_LUT_2_XY 9'h084 */
	union {
		uint32_t luma_lut_2_xy; // word name
		struct {
			uint32_t luma_lut_x_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_2 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_2_M 9'h088 */
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
	/* LUMA_LUT_3_XY 9'h08C */
	union {
		uint32_t luma_lut_3_xy; // word name
		struct {
			uint32_t luma_lut_x_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_3_M 9'h090 */
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
	/* LUMA_LUT_4_XY 9'h094 */
	union {
		uint32_t luma_lut_4_xy; // word name
		struct {
			uint32_t luma_lut_x_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_4 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_4_M 9'h098 */
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
	/* LUMA_LUT_5_XY 9'h09C */
	union {
		uint32_t luma_lut_5_xy; // word name
		struct {
			uint32_t luma_lut_x_5 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_5 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_5_M 9'h0A0 */
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
	/* LUMA_LUT_6_XY 9'h0A4 */
	union {
		uint32_t luma_lut_6_xy; // word name
		struct {
			uint32_t luma_lut_x_6 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_6 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_6_M 9'h0A8 */
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
	/* LUMA_LUT_7_XY 9'h0AC */
	union {
		uint32_t luma_lut_7_xy; // word name
		struct {
			uint32_t luma_lut_x_7 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_7 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_7_M 9'h0B0 */
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
	/* LUMA_LUT_8_XY 9'h0B4 */
	union {
		uint32_t luma_lut_8_xy; // word name
		struct {
			uint32_t luma_lut_x_8 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_y_8 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* LUMA_LUT_8_M 9'h0B8 */
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
	/* LUMA_LUT_9_M 9'h0BC */
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
	/* SOFT_CLIP 9'h0C0 */
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
	/* RGL_Y_LPF_SET 9'h0C4 */
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
	/* RGL_Y_LPF_RGL_WH 9'h0C8 */
	union {
		uint32_t rgl_y_lpf_rgl_wh; // word name
		struct {
			uint32_t rgl_y_lpf_rgl_wd : 13;
			uint32_t : 3; // padding bits
			uint32_t rgl_y_lpf_rgl_ht : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* RGL_Y_LPF_SXSY 9'h0CC */
	union {
		uint32_t rgl_y_lpf_sxsy; // word name
		struct {
			uint32_t rgl_y_lpf_sx : 16;
			uint32_t rgl_y_lpf_sy : 16;
		};
	};
	/* RGL_Y_LPF_EXEY 9'h0D0 */
	union {
		uint32_t rgl_y_lpf_exey; // word name
		struct {
			uint32_t rgl_y_lpf_ex : 16;
			uint32_t rgl_y_lpf_ey : 16;
		};
	};
	/* RGL_Y_LPF_XY_CNT_INI 9'h0D4 */
	union {
		uint32_t rgl_y_lpf_xy_cnt_ini; // word name
		struct {
			uint32_t rgl_y_lpf_x_cnt_ini : 13;
			uint32_t : 3; // padding bits
			uint32_t rgl_y_lpf_y_cnt_ini : 16;
		};
	};
	/* RGL_Y_LPF_R_CNT_SET 9'h0D8 */
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
	/* WORD_RGL_Y_LPF_PIX_NUM 9'h0DC */
	union {
		uint32_t word_rgl_y_lpf_pix_num; // word name
		struct {
			uint32_t rgl_y_lpf_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* ROI_Y_LPF_AVG_0_SET 9'h0E0 */
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
	/* ROI_Y_LPF_AVG_0_SXSY 9'h0E4 */
	union {
		uint32_t roi_y_lpf_avg_0_sxsy; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_sx : 16;
			uint32_t roi_y_lpf_avg_0_sy : 16;
		};
	};
	/* ROI_Y_LPF_AVG_0_EXEY 9'h0E8 */
	union {
		uint32_t roi_y_lpf_avg_0_exey; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_ex : 16;
			uint32_t roi_y_lpf_avg_0_ey : 16;
		};
	};
	/* WORD_ROI_Y_LPF_AVG_0_PIX_NUM 9'h0EC */
	union {
		uint32_t word_roi_y_lpf_avg_0_pix_num; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ROI_Y_LPF_AVG_0_AVG 9'h0F0 */
	union {
		uint32_t word_roi_y_lpf_avg_0_avg; // word name
		struct {
			uint32_t roi_y_lpf_avg_0_avg : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGL_Y_STAT_CTRL 9'h0F4 */
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
	/* WORD_RGL_Y_STAT_R_ADDR 9'h0F8 */
	union {
		uint32_t word_rgl_y_stat_r_addr; // word name
		struct {
			uint32_t rgl_y_stat_r_addr : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGL_Y_STAT_R_DATA 9'h0FC */
	union {
		uint32_t word_rgl_y_stat_r_data; // word name
		struct {
			uint32_t rgl_y_stat_r_data : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEMO_SET 9'h100 */
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
	/* DEMO_X 9'h104 */
	union {
		uint32_t demo_x; // word name
		struct {
			uint32_t demo_x_min : 16;
			uint32_t demo_x_max : 16;
		};
	};
	/* DEMO_Y 9'h108 */
	union {
		uint32_t demo_y; // word name
		struct {
			uint32_t demo_y_min : 16;
			uint32_t demo_y_max : 16;
		};
	};
	/* DEBUG_MON 9'h10C */
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
	/* WORD_RESERVED 9'h110 */
	union {
		uint32_t word_reserved; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* ATPG_CTRL 9'h114 */
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
} CsrBankShp;

#endif