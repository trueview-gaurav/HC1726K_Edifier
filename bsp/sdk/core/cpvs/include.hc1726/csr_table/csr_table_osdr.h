/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_OSDR_H_
#define CSR_TABLE_OSDR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_osdr[] = {
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
	// WORD lr564_04
	{ "access_illegal_hang", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x00000010, 8, 8, CSR_RW, 0x00000001 },
	{ "fifo_ready_sel", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "LR564_04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_05
	{ "bank_addr_type", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "col_addr_type", 0x00000014, 9, 8, CSR_RW, 0x00000000 },
	{ "LR564_05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_06
	{ "target_burst_len", 0x00000018, 4, 0, CSR_RW, 0x00000010 },
	{ "access_end_sel", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "debug_mon_sel", 0x00000018, 24, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x00000018, 28, 28, CSR_RW, 0x00000001 },
	{ "LR564_06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_07
	{ "target_fifo_level", 0x0000001C, 6, 0, CSR_RW, 0x00000020 },
	{ "fifo_full_level", 0x0000001C, 22, 16, CSR_RW, 0x00000040 },
	{ "LR564_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_08
	{ "reserved", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	{ "LR564_08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_09
	{ "ini_addr_linear_tag_0", 0x00000024, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_10
	{ "ini_addr_linear_tag_1", 0x00000028, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_11
	{ "ini_addr_linear_tag_2", 0x0000002C, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_12
	{ "ini_addr_linear_tag_3", 0x00000030, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_13
	{ "ini_addr_linear_tag_4", 0x00000034, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_13", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_14
	{ "ini_addr_linear_tag_5", 0x00000038, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_14", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_15
	{ "ini_addr_linear_tag_6", 0x0000003C, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_15", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_16
	{ "ini_addr_linear_tag_7", 0x00000040, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_17
	{ "start_addr", 0x00000044, 27, 0, CSR_RW, 0x00000000 },
	{ "LR564_17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD lr564_18
	{ "end_addr", 0x00000048, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "LR564_18", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_OSDR_H_
