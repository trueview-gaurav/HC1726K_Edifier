/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ENH_H_
#define CSR_BANK_ENH_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from enh  ***/
typedef struct csr_bank_enh {
	/* WORD_FRAME_START 8'h00 */
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
	/* IRQ_CLEAR 8'h04 */
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
	/* STATUS 8'h08 */
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
	/* IRQ_MASK 8'h0C */
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
	/* MODE 8'h10 */
	union {
		uint32_t mode; // word name
		struct {
			uint32_t y_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t c_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t sample_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t cac_enable : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* FRAME_SIZE 8'h14 */
	union {
		uint32_t frame_size; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* RADIUS 8'h18 */
	union {
		uint32_t radius; // word name
		struct {
			uint32_t y_l_r : 3;
			uint32_t : 5; // padding bits
			uint32_t c_r : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EDGE_STRENGTH 8'h1C */
	union {
		uint32_t edge_strength; // word name
		struct {
			uint32_t y_l_edge_strength : 6;
			uint32_t : 2; // padding bits
			uint32_t y_s_edge_strength : 6;
			uint32_t : 2; // padding bits
			uint32_t c_edge_y_strength : 6;
			uint32_t : 2; // padding bits
			uint32_t c_edge_c_strength : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* EPS_Y_L 8'h20 */
	union {
		uint32_t eps_y_l; // word name
		struct {
			uint32_t y_l_eps : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* MEAN_NORM_Y_L 8'h24 */
	union {
		uint32_t mean_norm_y_l; // word name
		struct {
			uint32_t y_l_mean_norm : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DT_NORM_Y_L 8'h28 */
	union {
		uint32_t dt_norm_y_l; // word name
		struct {
			uint32_t y_l_dt_mean_norm : 16;
			uint32_t y_l_dt_corr_norm : 16;
		};
	};
	/* EPS_Y_S 8'h2C */
	union {
		uint32_t eps_y_s; // word name
		struct {
			uint32_t y_s_eps : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* MEAN_NORM_Y_S 8'h30 */
	union {
		uint32_t mean_norm_y_s; // word name
		struct {
			uint32_t y_s_mean_norm : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DT_NORM_Y_S 8'h34 */
	union {
		uint32_t dt_norm_y_s; // word name
		struct {
			uint32_t y_s_dt_mean_norm : 9;
			uint32_t : 7; // padding bits
			uint32_t y_s_dt_corr_norm : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* BLENDING 8'h38 */
	union {
		uint32_t blending; // word name
		struct {
			uint32_t y_blend_lut_x_0 : 8;
			uint32_t y_blend_lut_x_1 : 8;
			uint32_t y_blend_lut_y_0 : 8;
			uint32_t y_blend_lut_y_1 : 8;
		};
	};
	/* BLENDING_M 8'h3C */
	union {
		uint32_t blending_m; // word name
		struct {
			uint32_t y_blend_lut_m_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EPS_C_Y 8'h40 */
	union {
		uint32_t eps_c_y; // word name
		struct {
			uint32_t c_eps_y : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EPS_C_C 8'h44 */
	union {
		uint32_t eps_c_c; // word name
		struct {
			uint32_t c_eps_c : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MEAN_NORM_C 8'h48 */
	union {
		uint32_t mean_norm_c; // word name
		struct {
			uint32_t c_mean_norm : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DT_NORM_C 8'h4C */
	union {
		uint32_t dt_norm_c; // word name
		struct {
			uint32_t c_dt_mean_norm : 15;
			uint32_t : 1; // padding bits
			uint32_t c_dt_corr_norm : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* CAC_CENTER 8'h50 */
	union {
		uint32_t cac_center; // word name
		struct {
			uint32_t cac_center_x : 16;
			uint32_t cac_center_y : 16;
		};
	};
	/* TILE_X 8'h54 */
	union {
		uint32_t tile_x; // word name
		struct {
			uint32_t tile_sx : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CENTER_NORM 8'h58 */
	union {
		uint32_t center_norm; // word name
		struct {
			uint32_t cac_center_diff_norm_x : 11;
			uint32_t : 5; // padding bits
			uint32_t cac_center_diff_norm_y : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* CAC_COLOR 8'h5C */
	union {
		uint32_t cac_color; // word name
		struct {
			uint32_t cac_color_u : 10;
			uint32_t : 6; // padding bits
			uint32_t cac_color_v : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* COLOR_NORM 8'h60 */
	union {
		uint32_t color_norm; // word name
		struct {
			uint32_t cac_color_diff_norm_u : 11;
			uint32_t : 5; // padding bits
			uint32_t cac_color_diff_norm_v : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* TABLE_LUMA_LUT_Y_0 8'h64 */
	union {
		uint32_t table_luma_lut_y_0; // word name
		struct {
			uint32_t luma_lut_y_ini : 6;
			uint32_t : 2; // padding bits
			uint32_t luma_lut_y_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t luma_lut_y_1 : 6;
			uint32_t : 2; // padding bits
			uint32_t luma_lut_y_2 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* TABLE_LUMA_LUT_Y_1 8'h68 */
	union {
		uint32_t table_luma_lut_y_1; // word name
		struct {
			uint32_t luma_lut_y_3 : 6;
			uint32_t : 2; // padding bits
			uint32_t luma_lut_y_4 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_LUMA_LUT_X_0 8'h6C */
	union {
		uint32_t table_luma_lut_x_0; // word name
		struct {
			uint32_t luma_lut_x_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_x_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_LUMA_LUT_X_1 8'h70 */
	union {
		uint32_t table_luma_lut_x_1; // word name
		struct {
			uint32_t luma_lut_x_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_x_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_LUMA_LUT_X_2 8'h74 */
	union {
		uint32_t table_luma_lut_x_2; // word name
		struct {
			uint32_t luma_lut_x_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_LUMA_LUT_M_0 8'h78 */
	union {
		uint32_t table_luma_lut_m_0; // word name
		struct {
			uint32_t luma_lut_m_0_2s : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_m_1_2s : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_LUMA_LUT_M_1 8'h7C */
	union {
		uint32_t table_luma_lut_m_1; // word name
		struct {
			uint32_t luma_lut_m_2_2s : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_m_3_2s : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_LUMA_LUT_M_2 8'h80 */
	union {
		uint32_t table_luma_lut_m_2; // word name
		struct {
			uint32_t luma_lut_m_4_2s : 10;
			uint32_t : 6; // padding bits
			uint32_t luma_lut_m_5_2s : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* EDGE_0 8'h84 */
	union {
		uint32_t edge_0; // word name
		struct {
			uint32_t cac_edge_lut_x_0 : 12;
			uint32_t : 4; // padding bits
			uint32_t cac_edge_lut_x_1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* EDGE_1 8'h88 */
	union {
		uint32_t edge_1; // word name
		struct {
			uint32_t cac_edge_lut_y_0 : 11;
			uint32_t : 5; // padding bits
			uint32_t cac_edge_lut_y_1 : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* EDGE_2 8'h8C */
	union {
		uint32_t edge_2; // word name
		struct {
			uint32_t cac_edge_lut_m_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 8'h90 */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DETAIL_GAIN 8'h94 */
	union {
		uint32_t detail_gain; // word name
		struct {
			uint32_t y_l_detail_gain : 7;
			uint32_t : 1; // padding bits
			uint32_t y_s_detail_gain : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ATPG_CTRL 8'h98 */
	union {
		uint32_t word_atpg_ctrl; // word name
		struct {
			uint32_t atpg_ctrl : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankEnh;

#endif