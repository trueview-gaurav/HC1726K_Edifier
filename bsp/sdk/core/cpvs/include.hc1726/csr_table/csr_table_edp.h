/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_EDP_H_
#define CSR_TABLE_EDP_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_edp[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_double_buf_update
	{ "double_buf_update", 0x00000010, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_DOUBLE_BUF_UPDATE", 0x00000010, 31, 0, CSR_W1P, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000014, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000014, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mode
	{ "mode", 0x00000018, 3, 0, CSR_RW, 0x00000000 },
	{ "target", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "broadcast_ack_not_sel", 0x00000018, 16, 16, CSR_RW, 0x00000001 },
	{ "idle_stall", 0x00000018, 24, 24, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_switch_offset
	{ "switch_offset", 0x0000001C, 14, 0, CSR_RW, 0x00000000 },
	{ "WORD_SWITCH_OFFSET", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi0_crop_x
	{ "roi0_crop_x_start", 0x00000020, 15, 0, CSR_RW, 0x00000000 },
	{ "roi0_crop_x_end", 0x00000020, 31, 16, CSR_RW, 0x0000077F },
	{ "ROI0_CROP_X", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi0_crop_y
	{ "roi0_crop_y_start", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "roi0_crop_y_end", 0x00000024, 31, 16, CSR_RW, 0x00000437 },
	{ "ROI0_CROP_Y", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi1_crop_x
	{ "roi1_crop_x_start", 0x00000028, 15, 0, CSR_RW, 0x00000000 },
	{ "roi1_crop_x_end", 0x00000028, 31, 16, CSR_RW, 0x0000077F },
	{ "ROI1_CROP_X", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi1_crop_y
	{ "roi1_crop_y_start", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "roi1_crop_y_end", 0x0000002C, 31, 16, CSR_RW, 0x00000437 },
	{ "ROI1_CROP_Y", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_EDP_H_
