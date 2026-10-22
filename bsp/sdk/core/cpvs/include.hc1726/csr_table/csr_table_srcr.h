/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SRCR_H_
#define CSR_TABLE_SRCR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_srcr[] = {
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
	// WORD br1_04
	{ "col_addr_type", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "debug_mon_sel", 0x00000010, 24, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x00000010, 28, 28, CSR_RW, 0x00000001 },
	{ "BR1_04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_05
	{ "access_illegal_hang", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x00000014, 8, 8, CSR_RW, 0x00000001 },
	{ "fifo_ready_sel", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "BR1_05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_07
	{ "target_burst_len", 0x0000001C, 4, 0, CSR_RW, 0x00000010 },
	{ "access_end_sel", 0x0000001C, 8, 8, CSR_RW, 0x00000001 },
	{ "BR1_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_08
	{ "target_fifo_level", 0x00000020, 8, 0, CSR_RW, 0x00000020 },
	{ "fifo_full_level", 0x00000020, 24, 16, CSR_RW, 0x00000100 },
	{ "BR1_08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_09
	{ "total_fifo_flush_cnt", 0x00000024, 25, 0, CSR_RW, 0x00000000 },
	{ "BR1_09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_10
	{ "y_only", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "msb_only", 0x00000028, 16, 16, CSR_RW, 0x00000000 },
	{ "BR1_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_11
	{ "block_size", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "BR1_11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_12
	{ "block_cnt_per_row", 0x00000030, 12, 0, CSR_RW, 0x00000000 },
	{ "total_block_row", 0x00000030, 28, 16, CSR_RW, 0x00000000 },
	{ "BR1_12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_16
	{ "flush_addr_skip", 0x00000040, 16, 0, CSR_RW, 0x00000000 },
	{ "BR1_16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_17
	{ "reserved", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	{ "BR1_17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_18
	{ "bank_interleave_type", 0x00000048, 1, 0, CSR_RW, 0x00000002 },
	{ "bank_group_type", 0x00000048, 9, 8, CSR_RW, 0x00000001 },
	{ "BR1_18", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_19
	{ "flush_addr_skip_extra", 0x0000004C, 16, 0, CSR_RW, 0x00000000 },
	{ "BR1_19", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_20
	{ "lcu_32x32", 0x00000050, 0, 0, CSR_RW, 0x00000000 },
	{ "BR1_20", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_40
	{ "ini_addr_linear_0", 0x000000A0, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_40", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_41
	{ "ini_addr_linear_1", 0x000000A4, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_41", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_42
	{ "ini_addr_linear_2", 0x000000A8, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_42", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_43
	{ "ini_addr_linear_3", 0x000000AC, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_43", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_44
	{ "ini_addr_linear_4", 0x000000B0, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_44", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_45
	{ "ini_addr_linear_5", 0x000000B4, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_45", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_46
	{ "ini_addr_linear_6", 0x000000B8, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_46", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_47
	{ "ini_addr_linear_7", 0x000000BC, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_47", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_48
	{ "ini_addr_bank_offset", 0x000000C0, 2, 0, CSR_RW, 0x00000000 },
	{ "BR1_48", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_49
	{ "start_addr", 0x000000C4, 27, 0, CSR_RW, 0x00000000 },
	{ "BR1_49", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD br1_50
	{ "end_addr", 0x000000C8, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "BR1_50", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SRCR_H_
