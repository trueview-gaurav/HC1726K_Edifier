/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SLB_H_
#define CSR_TABLE_SLB_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_slb[] = {
	// WORD main
	{ "enable", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "MAIN", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD irqsta_0
	{ "status_frame_end", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "status_lbuf_over_err", 0x00000004, 8, 8, CSR_RO, 0x00000000 },
	{ "status_lbuf_drop_err", 0x00000004, 16, 16, CSR_RO, 0x00000000 },
	{ "status_frame_comp", 0x00000004, 24, 24, CSR_RO, 0x00000000 },
	{ "IRQSTA_0", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD irqsta_1
	{ "status_frame_drop", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_src_err", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "IRQSTA_1", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irqmsk_0
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "irq_mask_lbuf_over_err", 0x0000000C, 8, 8, CSR_RW, 0x00000000 },
	{ "irq_mask_lbuf_drop_err", 0x0000000C, 16, 16, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_comp", 0x0000000C, 24, 24, CSR_RW, 0x00000000 },
	{ "IRQMSK_0", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD irqmsk_1
	{ "irq_mask_frame_drop", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "irq_mask_src_err", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "IRQMSK_1", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD irqack_0
	{ "irq_clear_frame_end", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_lbuf_over_err", 0x00000014, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_lbuf_drop_err", 0x00000014, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_comp", 0x00000014, 24, 24, CSR_W1P, 0x00000000 },
	{ "IRQACK_0", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irqack_1
	{ "irq_clear_frame_drop", 0x00000018, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_src_err", 0x00000018, 8, 8, CSR_W1P, 0x00000000 },
	{ "IRQACK_1", 0x00000018, 31, 0, CSR_W1P, 0x00000000 },
	// WORD rst
	{ "frame_reset", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "RST", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg
	{ "lbuf_en", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "crop_en", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "comp_en", 0x00000020, 16, 16, CSR_RW, 0x00000000 },
	{ "frame_drop_ack", 0x00000020, 24, 24, CSR_RW, 0x00000001 },
	{ "CFG", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD src
	{ "src_width", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "src_height", 0x00000024, 31, 16, CSR_RW, 0x00000000 },
	{ "SRC", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD dst
	{ "dst_width", 0x00000028, 15, 0, CSR_RW, 0x00000000 },
	{ "dst_height", 0x00000028, 31, 16, CSR_RW, 0x00000000 },
	{ "DST", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD cropx
	{ "cord_x_left", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "cord_x_right", 0x0000002C, 31, 16, CSR_RW, 0x00000000 },
	{ "CROPX", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cropy
	{ "cord_y_top", 0x00000030, 15, 0, CSR_RW, 0x00000000 },
	{ "cord_y_bottom", 0x00000030, 31, 16, CSR_RW, 0x00000000 },
	{ "CROPY", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word
	{ "data_type", 0x00000034, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD fcnt
	{ "frame_count", 0x00000040, 15, 0, CSR_RO, 0x00000000 },
	{ "frame_drop_count", 0x00000040, 31, 16, CSR_RO, 0x00000000 },
	{ "FCNT", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg0
	{ "debug_sel", 0x00000044, 3, 0, CSR_RW, 0x00000000 },
	{ "DBG0", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg1
	{ "debug_mon", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG1", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD sta0
	{ "src_width_count", 0x0000004C, 15, 0, CSR_RO, 0x00000000 },
	{ "src_height_count", 0x0000004C, 31, 16, CSR_RO, 0x00000000 },
	{ "STA0", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD sta1
	{ "lbuf_wr_width_count", 0x00000050, 15, 0, CSR_RO, 0x00000000 },
	{ "lbuf_wr_height_count", 0x00000050, 31, 16, CSR_RO, 0x00000000 },
	{ "STA1", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD sta2
	{ "lbuf_rd_width_count", 0x00000054, 15, 0, CSR_RO, 0x00000000 },
	{ "lbuf_rd_height_count", 0x00000054, 31, 16, CSR_RO, 0x00000000 },
	{ "STA2", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD sta3
	{ "dst_width_count", 0x00000058, 15, 0, CSR_RO, 0x00000000 },
	{ "dst_height_count", 0x00000058, 31, 16, CSR_RO, 0x00000000 },
	{ "STA3", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SLB_H_
