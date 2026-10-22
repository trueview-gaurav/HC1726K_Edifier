/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_REFR_H_
#define CSR_TABLE_REFR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_refr[] = {
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
	// WORD rr_04
	{ "access_illegal_hang", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x00000010, 8, 8, CSR_RW, 0x00000001 },
	{ "fifo_ready_sel", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "RR_04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_05
	{ "col_addr_type", 0x00000014, 9, 8, CSR_RW, 0x00000000 },
	{ "RR_05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_06
	{ "target_burst_len", 0x00000018, 4, 0, CSR_RW, 0x00000010 },
	{ "access_end_sel", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "debug_mon_sel", 0x00000018, 24, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x00000018, 28, 28, CSR_RW, 0x00000001 },
	{ "RR_06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_07
	{ "target_fifo_level", 0x0000001C, 8, 0, CSR_RW, 0x00000020 },
	{ "fifo_full_level", 0x0000001C, 24, 16, CSR_RW, 0x00000100 },
	{ "RR_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_08
	{ "height", 0x00000020, 15, 0, CSR_RW, 0x00000000 },
	{ "width", 0x00000020, 31, 16, CSR_RW, 0x00000000 },
	{ "RR_08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_10
	{ "reserved", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	{ "RR_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_11
	{ "bank_interleave_type", 0x0000002C, 1, 0, CSR_RW, 0x00000002 },
	{ "bank_group_type", 0x0000002C, 5, 4, CSR_RW, 0x00000001 },
	{ "ini_addr_bank_offset", 0x0000002C, 10, 8, CSR_RW, 0x00000000 },
	{ "ini_addr_bank_offset_c", 0x0000002C, 14, 12, CSR_RW, 0x00000000 },
	{ "RR_11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_12
	{ "ini_addr_linear_y_0", 0x00000030, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_13
	{ "ini_addr_linear_y_1", 0x00000034, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_13", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_14
	{ "ini_addr_linear_y_2", 0x00000038, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_14", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_15
	{ "ini_addr_linear_y_3", 0x0000003C, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_15", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_16
	{ "ini_addr_linear_c_0", 0x00000040, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_17
	{ "ini_addr_linear_c_1", 0x00000044, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_18
	{ "ini_addr_linear_c_2", 0x00000048, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_18", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_19
	{ "ini_addr_linear_c_3", 0x0000004C, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_19", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_20
	{ "frmsync_addr_start_y_0", 0x00000050, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_20", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_21
	{ "frmsync_addr_start_y_1", 0x00000054, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_21", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_22
	{ "frmsync_addr_start_y_2", 0x00000058, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_22", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_23
	{ "frmsync_addr_start_y_3", 0x0000005C, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_23", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_24
	{ "frmsync_addr_start_c_0", 0x00000060, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_24", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_25
	{ "frmsync_addr_start_c_1", 0x00000064, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_25", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_26
	{ "frmsync_addr_start_c_2", 0x00000068, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_26", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_27
	{ "frmsync_addr_start_c_3", 0x0000006C, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_27", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_28
	{ "frmsync_addr_end_y", 0x00000070, 27, 0, CSR_RW, 0x00000000 },
	{ "frmsync_en", 0x00000070, 28, 28, CSR_RW, 0x00000000 },
	{ "RR_28", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_29
	{ "frmsync_addr_end_c", 0x00000074, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_29", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_30
	{ "start_addr", 0x00000078, 27, 0, CSR_RW, 0x00000000 },
	{ "RR_30", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD rr_31
	{ "end_addr", 0x0000007C, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "RR_31", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_REFR_H_
