/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AUDIOR_H_
#define CSR_TABLE_AUDIOR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_audior[] = {
	// WORD lr432_00
	{ "start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "buffer_set_0", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "buffer_set_1", 0x00000000, 16, 16, CSR_W1P, 0x00000000 },
	{ "read_end_req", 0x00000000, 24, 24, CSR_W1P, 0x00000000 },
	{ "LR432_00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lr432_01
	{ "access_illegal_hang", 0x00000004, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x00000004, 8, 8, CSR_RW, 0x00000001 },
	{ "fifo_ready_sel", 0x00000004, 16, 16, CSR_RW, 0x00000000 },
	{ "LR432_01", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_04
	{ "col_addr_type", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "debug_mon_sel", 0x00000010, 24, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x00000010, 28, 28, CSR_RW, 0x00000001 },
	{ "LR432_04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_05
	{ "buffer_available_0", 0x00000014, 0, 0, CSR_RO, 0x00000000 },
	{ "buffer_available_1", 0x00000014, 8, 8, CSR_RO, 0x00000000 },
	{ "current_buffer", 0x00000014, 16, 16, CSR_RO, 0x00000000 },
	{ "LR432_05", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD lr432_06
	{ "target_burst_len", 0x00000018, 4, 0, CSR_RW, 0x00000008 },
	{ "access_end_sel", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "bank_addr_type", 0x00000018, 16, 16, CSR_RW, 0x00000001 },
	{ "LR432_06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_07
	{ "target_fifo_level", 0x0000001C, 5, 0, CSR_RW, 0x00000010 },
	{ "fifo_full_level", 0x0000001C, 21, 16, CSR_RW, 0x00000020 },
	{ "LR432_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_08
	{ "buffer_size", 0x00000020, 23, 0, CSR_RW, 0x00000000 },
	{ "LR432_08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_09
	{ "start_addr", 0x00000024, 27, 0, CSR_RW, 0x00000000 },
	{ "LR432_09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_10
	{ "end_addr", 0x00000028, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "LR432_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_11
	{ "reserved", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	{ "LR432_11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_12
	{ "ini_addr_linear_0", 0x00000030, 27, 0, CSR_RW, 0x00000000 },
	{ "LR432_12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_13
	{ "ini_addr_linear_1", 0x00000034, 27, 0, CSR_RW, 0x00000000 },
	{ "LR432_13", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr432_14
	{ "sample_count", 0x00000038, 23, 0, CSR_RO, 0x00000000 },
	{ "LR432_14", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000078, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_bw_insufficient", 0x00000078, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_access_violation", 0x00000078, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_resp_error", 0x00000078, 24, 24, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000078, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear_1
	{ "irq_clear_buffer_full_0", 0x0000007C, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_buffer_full_1", 0x0000007C, 8, 8, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR_1", 0x0000007C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000080, 0, 0, CSR_RO, 0x00000000 },
	{ "status_bw_insufficient", 0x00000080, 8, 8, CSR_RO, 0x00000000 },
	{ "status_access_violation", 0x00000080, 16, 16, CSR_RO, 0x00000000 },
	{ "status_resp_error", 0x00000080, 24, 24, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000080, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_1
	{ "status_buffer_full_0", 0x00000084, 0, 0, CSR_RO, 0x00000000 },
	{ "status_buffer_full_1", 0x00000084, 8, 8, CSR_RO, 0x00000000 },
	{ "STATUS_1", 0x00000084, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x00000088, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_bw_insufficient", 0x00000088, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_access_violation", 0x00000088, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_resp_error", 0x00000088, 24, 24, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_mask_1
	{ "irq_mask_buffer_full_0", 0x0000008C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_buffer_full_1", 0x0000008C, 8, 8, CSR_RW, 0x00000001 },
	{ "IRQ_MASK_1", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AUDIOR_H_
