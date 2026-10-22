/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DHZ_H_
#define CSR_TABLE_DHZ_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dhz[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD word_irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD word_status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "WORD_STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "WORD_IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_resolution
	{ "width", 0x00000010, 15, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000010, 31, 16, CSR_RW, 0x00000438 },
	{ "WORD_RESOLUTION", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mode
	{ "mode", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "y_protect", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_strength
	{ "strength", 0x00000018, 7, 0, CSR_RW, 0x00000080 },
	{ "WORD_STRENGTH", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_gain
	{ "y_gain_max", 0x0000001C, 9, 0, CSR_RW, 0x00000100 },
	{ "c_gain_max", 0x0000001C, 25, 16, CSR_RW, 0x00000100 },
	{ "WORD_GAIN", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_y_dc
	{ "y_dc", 0x00000020, 9, 0, CSR_RW, 0x00000000 },
	{ "WORD_Y_DC", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_c_dc
	{ "u_dc", 0x00000024, 9, 0, CSR_RW, 0x00000200 },
	{ "v_dc", 0x00000024, 25, 16, CSR_RW, 0x00000200 },
	{ "WORD_C_DC", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_num
	{ "rgl_x_num", 0x00000028, 3, 0, CSR_RW, 0x00000008 },
	{ "rgl_y_num", 0x00000028, 11, 8, CSR_RW, 0x00000008 },
	{ "WORD_RGL_NUM", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_x_cnt
	{ "rgl_x_cnt_ini", 0x0000002C, 24, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_X_CNT", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_y_cnt
	{ "rgl_y_cnt_ini", 0x00000030, 24, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_Y_CNT", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_x_cnt_step
	{ "rgl_x_cnt_step", 0x00000034, 21, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_X_CNT_STEP", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_y_cnt_step
	{ "rgl_y_cnt_step", 0x00000038, 21, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_Y_CNT_STEP", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_attr_ctrl
	{ "rgl_attr_clk_sel", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_ATTR_CTRL", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_attr_waddr
	{ "rgl_attr_w_addr", 0x00000040, 5, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_ATTR_WADDR", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_attr_wdata
	{ "rgl_attr_w_data", 0x00000044, 19, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_ATTR_WDATA", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_attr_raddr
	{ "rgl_attr_r_addr", 0x00000048, 5, 0, CSR_RW, 0x00000000 },
	{ "WORD_RGL_ATTR_RADDR", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rgl_attr_rdata
	{ "rgl_attr_r_data", 0x0000004C, 19, 0, CSR_RO, 0x00000000 },
	{ "WORD_RGL_ATTR_RDATA", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_roi_y_avg_ctrl
	{ "roi_y_avg_0_clear", 0x00000050, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_y_avg_0_en", 0x00000050, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD_ROI_Y_AVG_CTRL", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_roi_y_avg_sxex
	{ "roi_y_avg_0_sx", 0x00000054, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_y_avg_0_ex", 0x00000054, 31, 16, CSR_RW, 0x0000077F },
	{ "WORD_ROI_Y_AVG_SXEX", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_roi_y_avg_syey
	{ "roi_y_avg_0_sy", 0x00000058, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_y_avg_0_ey", 0x00000058, 31, 16, CSR_RW, 0x00000437 },
	{ "WORD_ROI_Y_AVG_SYEY", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_roi_y_avg_pix_num
	{ "roi_y_avg_0_pix_num", 0x0000005C, 25, 0, CSR_RW, 0x001FA400 },
	{ "WORD_ROI_Y_AVG_PIX_NUM", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_roi_y_avg_avg
	{ "roi_y_avg_0_avg", 0x00000060, 9, 0, CSR_RO, 0x00000000 },
	{ "WORD_ROI_Y_AVG_AVG", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000064, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DHZ_H_
