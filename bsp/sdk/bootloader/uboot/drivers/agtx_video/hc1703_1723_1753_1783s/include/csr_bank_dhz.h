/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DHZ_H_
#define CSR_BANK_DHZ_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dhz  ***/
typedef struct csr_bank_dhz {
	/* WORD_FRAME_START 7'h00 */
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
	/* WORD_IRQ_CLEAR 7'h04 */
	union {
		uint32_t word_irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_STATUS 7'h08 */
	union {
		uint32_t word_status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_IRQ_MASK 7'h0C */
	union {
		uint32_t word_irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESOLUTION 7'h10 */
	union {
		uint32_t word_resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORD_STRENGTH 7'h14 */
	union {
		uint32_t word_strength; // word name
		struct {
			uint32_t strength : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GAIN 7'h18 */
	union {
		uint32_t word_gain; // word name
		struct {
			uint32_t y_gain_max : 10;
			uint32_t : 6; // padding bits
			uint32_t c_gain_max : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* WORD_Y_DC 7'h1C */
	union {
		uint32_t word_y_dc; // word name
		struct {
			uint32_t y_dc : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_C_DC 7'h20 */
	union {
		uint32_t word_c_dc; // word name
		struct {
			uint32_t u_dc : 10;
			uint32_t : 6; // padding bits
			uint32_t v_dc : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* WORD_RGL_NUM 7'h24 */
	union {
		uint32_t word_rgl_num; // word name
		struct {
			uint32_t rgl_x_num : 4;
			uint32_t : 4; // padding bits
			uint32_t rgl_y_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGL_X_CNT 7'h28 */
	union {
		uint32_t word_rgl_x_cnt; // word name
		struct {
			uint32_t rgl_x_cnt_ini : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_RGL_Y_CNT 7'h2C */
	union {
		uint32_t word_rgl_y_cnt; // word name
		struct {
			uint32_t rgl_y_cnt_ini : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_RGL_X_CNT_STEP 7'h30 */
	union {
		uint32_t word_rgl_x_cnt_step; // word name
		struct {
			uint32_t rgl_x_cnt_step : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGL_Y_CNT_STEP 7'h34 */
	union {
		uint32_t word_rgl_y_cnt_step; // word name
		struct {
			uint32_t rgl_y_cnt_step : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGL_ATTR_CTRL 7'h38 */
	union {
		uint32_t word_rgl_attr_ctrl; // word name
		struct {
			uint32_t rgl_attr_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGL_ATTR_WADDR 7'h3C */
	union {
		uint32_t word_rgl_attr_waddr; // word name
		struct {
			uint32_t rgl_attr_w_addr : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGL_ATTR_WDATA 7'h40 */
	union {
		uint32_t word_rgl_attr_wdata; // word name
		struct {
			uint32_t rgl_attr_w_data : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGL_ATTR_RADDR 7'h44 */
	union {
		uint32_t word_rgl_attr_raddr; // word name
		struct {
			uint32_t rgl_attr_r_addr : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGL_ATTR_RDATA 7'h48 */
	union {
		uint32_t word_rgl_attr_rdata; // word name
		struct {
			uint32_t rgl_attr_r_data : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ROI_Y_AVG_CTRL 7'h4C */
	union {
		uint32_t word_roi_y_avg_ctrl; // word name
		struct {
			uint32_t roi_y_avg_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_y_avg_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ROI_Y_AVG_SXEX 7'h50 */
	union {
		uint32_t word_roi_y_avg_sxex; // word name
		struct {
			uint32_t roi_y_avg_0_sx : 16;
			uint32_t roi_y_avg_0_ex : 16;
		};
	};
	/* WORD_ROI_Y_AVG_SYEY 7'h54 */
	union {
		uint32_t word_roi_y_avg_syey; // word name
		struct {
			uint32_t roi_y_avg_0_sy : 16;
			uint32_t roi_y_avg_0_ey : 16;
		};
	};
	/* WORD_ROI_Y_AVG_PIX_NUM 7'h58 */
	union {
		uint32_t word_roi_y_avg_pix_num; // word name
		struct {
			uint32_t roi_y_avg_0_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ROI_Y_AVG_AVG 7'h5C */
	union {
		uint32_t word_roi_y_avg_avg; // word name
		struct {
			uint32_t roi_y_avg_0_avg : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 7'h60 */
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
} CsrBankDhz;

#endif