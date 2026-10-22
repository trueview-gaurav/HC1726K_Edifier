/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PXR_H_
#define CSR_TABLE_PXR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pxr[] = {
	// WORD pr0_00
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "PR0_00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pr0_01
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_bw_insufficient", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_access_violation", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_resp_error", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "PR0_01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pr0_02
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_bw_insufficient", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "status_access_violation", 0x00000008, 16, 16, CSR_RO, 0x00000000 },
	{ "status_resp_error", 0x00000008, 24, 24, CSR_RO, 0x00000000 },
	{ "PR0_02", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD pr0_03
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_bw_insufficient", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_access_violation", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_resp_error", 0x0000000C, 24, 24, CSR_RW, 0x00000001 },
	{ "PR0_03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_04
	{ "col_addr_type", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "PR0_04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_05
	{ "frame_start_free_run", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_end_free_run", 0x00000014, 16, 16, CSR_W1P, 0x00000000 },
	{ "db_en_cpu", 0x00000014, 24, 24, CSR_W1P, 0x00000000 },
	{ "PR0_05", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pr0_06
	{ "access_illegal_hang", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "fifo_ready_sel", 0x00000018, 16, 16, CSR_RW, 0x00000000 },
	{ "PR0_06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_07
	{ "target_burst_len", 0x0000001C, 4, 0, CSR_RW, 0x00000010 },
	{ "access_end_sel", 0x0000001C, 8, 8, CSR_RW, 0x00000001 },
	{ "debug_mon_sel", 0x0000001C, 24, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x0000001C, 28, 28, CSR_RW, 0x00000001 },
	{ "PR0_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_08
	{ "target_fifo_level", 0x00000020, 8, 0, CSR_RW, 0x00000020 },
	{ "fifo_full_level", 0x00000020, 24, 16, CSR_RW, 0x00000100 },
	{ "PR0_08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_09
	{ "height", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "width", 0x00000024, 31, 16, CSR_RW, 0x00000000 },
	{ "PR0_09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_10
	{ "y_only_e", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "y_only_o", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "msb_only", 0x00000028, 16, 16, CSR_RW, 0x00000000 },
	{ "channel_swap", 0x00000028, 24, 24, CSR_RW, 0x00000000 },
	{ "PR0_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_11
	{ "bank_interleave_type", 0x0000002C, 1, 0, CSR_RW, 0x00000002 },
	{ "bank_group_type", 0x0000002C, 9, 8, CSR_RW, 0x00000001 },
	{ "PR0_11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_13
	{ "fifo_flush_len", 0x00000034, 13, 0, CSR_RW, 0x00000000 },
	{ "PR0_13", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_16
	{ "pixel_flush_len", 0x00000040, 15, 0, CSR_RW, 0x00000000 },
	{ "PR0_16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_18
	{ "flush_addr_skip_e", 0x00000048, 13, 0, CSR_RW, 0x00000000 },
	{ "flush_addr_skip_sign_e", 0x00000048, 16, 16, CSR_RW, 0x00000000 },
	{ "PR0_18", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_19
	{ "flush_addr_skip_o", 0x0000004C, 13, 0, CSR_RW, 0x00000000 },
	{ "flush_addr_skip_sign_o", 0x0000004C, 16, 16, CSR_RW, 0x00000000 },
	{ "PR0_19", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_20
	{ "fifo_start_phase", 0x00000050, 4, 0, CSR_RW, 0x00000000 },
	{ "fifo_end_phase", 0x00000050, 12, 8, CSR_RW, 0x00000000 },
	{ "PR0_20", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_21
	{ "fifo_flush_len_last", 0x00000054, 2, 0, CSR_RW, 0x00000000 },
	{ "PR0_21", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_22
	{ "package_size_last", 0x00000058, 2, 0, CSR_RW, 0x00000000 },
	{ "block_mode", 0x00000058, 4, 4, CSR_RW, 0x00000000 },
	{ "PR0_22", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_23
	{ "addr_per_row", 0x0000005C, 11, 0, CSR_RW, 0x00000000 },
	{ "lsb_append_mode", 0x0000005C, 17, 16, CSR_RW, 0x00000003 },
	{ "PR0_23", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_24
	{ "reserved", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	{ "PR0_24", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_40
	{ "ini_addr_linear_0", 0x000000A0, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_40", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_41
	{ "ini_addr_linear_1", 0x000000A4, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_41", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_42
	{ "ini_addr_linear_2", 0x000000A8, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_42", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_43
	{ "ini_addr_linear_3", 0x000000AC, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_43", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_44
	{ "ini_addr_linear_4", 0x000000B0, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_44", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_45
	{ "ini_addr_linear_5", 0x000000B4, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_45", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_46
	{ "ini_addr_linear_6", 0x000000B8, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_46", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_47
	{ "ini_addr_linear_7", 0x000000BC, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_47", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_48
	{ "ini_addr_bank_offset", 0x000000C0, 2, 0, CSR_RW, 0x00000000 },
	{ "ini_addr_bank_add_sub", 0x000000C0, 8, 8, CSR_RW, 0x00000000 },
	{ "PR0_48", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_49
	{ "mirror_mode", 0x000000C4, 0, 0, CSR_RW, 0x00000000 },
	{ "flip_mode", 0x000000C4, 8, 8, CSR_RW, 0x00000000 },
	{ "PR0_49", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_50
	{ "start_addr", 0x000000C8, 27, 0, CSR_RW, 0x00000000 },
	{ "PR0_50", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pr0_51
	{ "end_addr", 0x000000CC, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "PR0_51", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PXR_H_
