/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CCQR_H_
#define CSR_TABLE_CCQR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ccqr[] = {
	// WORD lr064_00
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "LR064_00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lr064_01
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_bw_insufficient", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_access_violation", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_resp_error", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "LR064_01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lr064_02
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_bw_insufficient", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "status_access_violation", 0x00000008, 16, 16, CSR_RO, 0x00000000 },
	{ "status_resp_error", 0x00000008, 24, 24, CSR_RO, 0x00000000 },
	{ "LR064_02", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD lr064_03
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_bw_insufficient", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_access_violation", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_resp_error", 0x0000000C, 24, 24, CSR_RW, 0x00000001 },
	{ "LR064_03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_04
	{ "col_addr_type", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "debug_mon_sel", 0x00000010, 24, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x00000010, 28, 28, CSR_RW, 0x00000001 },
	{ "LR064_04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_06
	{ "access_illegal_hang", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "fifo_ready_sel", 0x00000018, 16, 16, CSR_RW, 0x00000000 },
	{ "LR064_06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_07
	{ "target_burst_len", 0x0000001C, 4, 0, CSR_RW, 0x00000010 },
	{ "access_end_sel", 0x0000001C, 8, 8, CSR_RW, 0x00000001 },
	{ "bank_addr_type", 0x0000001C, 16, 16, CSR_RW, 0x00000001 },
	{ "LR064_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_08
	{ "target_fifo_level", 0x00000020, 6, 0, CSR_RW, 0x00000020 },
	{ "fifo_full_level", 0x00000020, 22, 16, CSR_RW, 0x00000040 },
	{ "LR064_08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_09
	{ "start_addr", 0x00000024, 27, 0, CSR_RW, 0x00000000 },
	{ "LR064_09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_10
	{ "end_addr", 0x00000028, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "LR064_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_11
	{ "pixel_flush_len", 0x0000002C, 21, 0, CSR_RW, 0x00000000 },
	{ "LR064_11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_12
	{ "fifo_flush_len", 0x00000030, 21, 0, CSR_RW, 0x00000000 },
	{ "LR064_12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_13
	{ "reserved", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	{ "LR064_13", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_14
	{ "ini_addr_word", 0x00000038, 18, 16, CSR_RW, 0x00000000 },
	{ "LR064_14", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr064_40
	{ "ini_addr_linear", 0x000000A0, 27, 0, CSR_RW, 0x00000000 },
	{ "LR064_40", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CCQR_H_
