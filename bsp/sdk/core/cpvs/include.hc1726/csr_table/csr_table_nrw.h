/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_NRW_H_
#define CSR_TABLE_NRW_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_nrw[] = {
	// WORD frm_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "FRM_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_bw_insufficient", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_access_violation", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_resp_error", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_bw_insufficient", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "status_access_violation", 0x00000008, 16, 16, CSR_RO, 0x00000000 },
	{ "status_resp_error", 0x00000008, 24, 24, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_bw_insufficient", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_access_violation", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_resp_error", 0x0000000C, 24, 24, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_04
	{ "access_illegal_hang", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x00000010, 8, 8, CSR_RW, 0x00000001 },
	{ "BW0_04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_05
	{ "col_addr_type", 0x00000014, 9, 8, CSR_RW, 0x00000000 },
	{ "debug_mon_sel", 0x00000014, 24, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x00000014, 28, 28, CSR_RW, 0x00000001 },
	{ "BW0_05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_07
	{ "target_burst_len", 0x0000001C, 4, 0, CSR_RW, 0x00000010 },
	{ "access_end_sel", 0x0000001C, 8, 8, CSR_RW, 0x00000001 },
	{ "BW0_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_08
	{ "target_fifo_level", 0x00000020, 8, 0, CSR_RW, 0x00000020 },
	{ "fifo_full_level", 0x00000020, 24, 16, CSR_RW, 0x00000100 },
	{ "BW0_08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_09
	{ "height", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "block_cnt_hor", 0x00000024, 28, 16, CSR_RW, 0x00000000 },
	{ "BW0_09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_10
	{ "y_only", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "msb_only", 0x00000028, 16, 16, CSR_RW, 0x00000000 },
	{ "BW0_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_12
	{ "fifo_flush_len", 0x00000030, 17, 0, CSR_RW, 0x00000000 },
	{ "BW0_12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_16
	{ "pixel_flush_len", 0x00000040, 18, 0, CSR_RW, 0x00000000 },
	{ "BW0_16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_17
	{ "h_start", 0x00000044, 12, 0, CSR_RW, 0x00000000 },
	{ "h_end", 0x00000044, 28, 16, CSR_RW, 0x00000000 },
	{ "BW0_17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_18
	{ "v_start", 0x00000048, 15, 0, CSR_RW, 0x00000000 },
	{ "v_end", 0x00000048, 31, 16, CSR_RW, 0x00000000 },
	{ "BW0_18", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_19
	{ "flush_addr_skip", 0x0000004C, 17, 0, CSR_RW, 0x00000000 },
	{ "BW0_19", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_21
	{ "reserved", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	{ "BW0_21", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_25
	{ "bank_interleave_type", 0x00000064, 1, 0, CSR_RW, 0x00000002 },
	{ "bank_group_type", 0x00000064, 9, 8, CSR_RW, 0x00000001 },
	{ "BW0_25", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_40
	{ "ini_addr_linear_0", 0x000000A0, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_40", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_41
	{ "ini_addr_linear_1", 0x000000A4, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_41", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_42
	{ "ini_addr_linear_2", 0x000000A8, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_42", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_43
	{ "ini_addr_linear_3", 0x000000AC, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_43", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_44
	{ "ini_addr_linear_4", 0x000000B0, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_44", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_45
	{ "ini_addr_linear_5", 0x000000B4, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_45", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_46
	{ "ini_addr_linear_6", 0x000000B8, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_46", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_47
	{ "ini_addr_linear_7", 0x000000BC, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_47", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_48
	{ "ini_addr_bank_offset", 0x000000C0, 2, 0, CSR_RW, 0x00000000 },
	{ "BW0_48", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_49
	{ "start_addr", 0x000000C4, 27, 0, CSR_RW, 0x00000000 },
	{ "BW0_49", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD bw0_50
	{ "end_addr", 0x000000C8, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "BW0_50", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_NRW_H_
