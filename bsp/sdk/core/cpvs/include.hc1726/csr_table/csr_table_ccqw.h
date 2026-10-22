/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CCQW_H_
#define CSR_TABLE_CCQW_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ccqw[] = {
	// WORD lw432_00
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "buffer_set_0", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "buffer_set_1", 0x00000000, 16, 16, CSR_W1P, 0x00000000 },
	{ "LW432_00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lw432_01
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_bw_insufficient", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_access_violation", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_resp_error", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "LW432_01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lw432_02
	{ "irq_clear_buffer_full_0", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_buffer_full_1", 0x00000008, 8, 8, CSR_W1P, 0x00000000 },
	{ "LW432_02", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lw432_03
	{ "status_frame_end", 0x0000000C, 0, 0, CSR_RO, 0x00000000 },
	{ "status_bw_insufficient", 0x0000000C, 8, 8, CSR_RO, 0x00000000 },
	{ "status_access_violation", 0x0000000C, 16, 16, CSR_RO, 0x00000000 },
	{ "status_resp_error", 0x0000000C, 24, 24, CSR_RO, 0x00000000 },
	{ "LW432_03", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD lw432_04
	{ "status_buffer_full_0", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "status_buffer_full_1", 0x00000010, 8, 8, CSR_RO, 0x00000000 },
	{ "LW432_04", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD lw432_05
	{ "irq_mask_frame_end", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_bw_insufficient", 0x00000014, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_access_violation", 0x00000014, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_resp_error", 0x00000014, 24, 24, CSR_RW, 0x00000001 },
	{ "LW432_05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_06
	{ "irq_mask_buffer_full_0", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_buffer_full_1", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "LW432_06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_07
	{ "access_illegal_hang", 0x0000001C, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x0000001C, 8, 8, CSR_RW, 0x00000001 },
	{ "LW432_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_10
	{ "bank_addr_type", 0x00000028, 0, 0, CSR_RW, 0x00000001 },
	{ "col_addr_type", 0x00000028, 9, 8, CSR_RW, 0x00000000 },
	{ "LW432_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_11
	{ "buffer_available_0", 0x0000002C, 0, 0, CSR_RO, 0x00000000 },
	{ "buffer_available_1", 0x0000002C, 8, 8, CSR_RO, 0x00000000 },
	{ "current_buffer", 0x0000002C, 16, 16, CSR_RO, 0x00000000 },
	{ "LW432_11", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD lw432_12
	{ "access_end_sel", 0x00000030, 8, 8, CSR_RW, 0x00000001 },
	{ "LW432_12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_13
	{ "target_fifo_level", 0x00000034, 5, 0, CSR_RW, 0x00000010 },
	{ "target_burst_len", 0x00000034, 12, 8, CSR_RW, 0x00000010 },
	{ "fifo_full_level", 0x00000034, 21, 16, CSR_RW, 0x00000020 },
	{ "debug_mon_sel", 0x00000034, 25, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x00000034, 28, 28, CSR_RW, 0x00000001 },
	{ "LW432_13", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_14
	{ "buffer_size", 0x00000038, 23, 0, CSR_RW, 0x00000000 },
	{ "LW432_14", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_15
	{ "start_addr", 0x0000003C, 27, 0, CSR_RW, 0x00000000 },
	{ "LW432_15", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_16
	{ "end_addr", 0x00000040, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "LW432_16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_17
	{ "reserved", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	{ "LW432_17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_40
	{ "ini_addr_linear_0", 0x000000A0, 27, 0, CSR_RW, 0x00000000 },
	{ "LW432_40", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_41
	{ "ini_addr_linear_1", 0x000000A4, 27, 0, CSR_RW, 0x00000000 },
	{ "LW432_41", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD lw432_42
	{ "sample_count", 0x000000A8, 23, 0, CSR_RO, 0x00000000 },
	{ "LW432_42", 0x000000A8, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CCQW_H_
