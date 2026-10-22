/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PS_H_
#define CSR_TABLE_PS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ps[] = {
	// WORD main
	{ "ps_en", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "MAIN", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD irqsta
	{ "status_frame_done", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "status_frame_end", 0x00000004, 1, 1, CSR_RO, 0x00000000 },
	{ "status_frame_start", 0x00000004, 2, 2, CSR_RO, 0x00000000 },
	{ "status_frame_size_err", 0x00000004, 3, 3, CSR_RO, 0x00000000 },
	{ "status_fifo_over_err", 0x00000004, 4, 4, CSR_RO, 0x00000000 },
	{ "status_sync_code_err", 0x00000004, 5, 5, CSR_RO, 0x00000000 },
	{ "status_out_over_err", 0x00000004, 6, 6, CSR_RO, 0x00000000 },
	{ "IRQSTA", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD irqmsk
	{ "irq_mask_frame_done", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_end", 0x00000008, 1, 1, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_start", 0x00000008, 2, 2, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_size_err", 0x00000008, 3, 3, CSR_RW, 0x00000000 },
	{ "irq_mask_fifo_over_err", 0x00000008, 4, 4, CSR_RW, 0x00000000 },
	{ "irq_mask_sync_code_err", 0x00000008, 5, 5, CSR_RW, 0x00000000 },
	{ "irq_mask_out_over_err", 0x00000008, 6, 6, CSR_RW, 0x00000000 },
	{ "IRQMSK", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD irqack
	{ "irq_clear_frame_done", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_end", 0x0000000C, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_start", 0x0000000C, 2, 2, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_size_err", 0x0000000C, 3, 3, CSR_W1P, 0x00000000 },
	{ "irq_clear_fifo_over_err", 0x0000000C, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_sync_code_err", 0x0000000C, 5, 5, CSR_W1P, 0x00000000 },
	{ "irq_clear_out_over_err", 0x0000000C, 6, 6, CSR_W1P, 0x00000000 },
	{ "IRQACK", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD rst
	{ "ps_reset", 0x00000010, 0, 0, CSR_W1P, 0x00000000 },
	{ "frame_reset", 0x00000010, 16, 16, CSR_W1P, 0x00000000 },
	{ "RST", 0x00000010, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg
	{ "dec_mode", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "lp_mode", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "CFG", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word
	{ "word_size", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "word_shift", 0x00000018, 11, 8, CSR_RW, 0x00000000 },
	{ "word_order", 0x00000018, 16, 16, CSR_RW, 0x00000000 },
	{ "WORD", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD size
	{ "width", 0x0000001C, 15, 0, CSR_RW, 0x00000000 },
	{ "height", 0x0000001C, 31, 16, CSR_RW, 0x00000000 },
	{ "SIZE", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ec
	{ "dis_ec", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "EC", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD hv
	{ "hsync_polar", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "vsync_polar", 0x00000024, 8, 8, CSR_RW, 0x00000000 },
	{ "HV", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD desr
	{ "des_en", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "des_bit_size", 0x00000028, 9, 8, CSR_RW, 0x00000000 },
	{ "des_unpac_num", 0x00000028, 19, 16, CSR_RW, 0x00000000 },
	{ "des_order", 0x00000028, 24, 24, CSR_RW, 0x00000000 },
	{ "DESR", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD fmt
	{ "data_type", 0x0000002C, 2, 0, CSR_RW, 0x00000000 },
	{ "FMT", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sctrl
	{ "sof_en", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "eof_en", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "eol_en", 0x00000030, 16, 16, CSR_RW, 0x00000000 },
	{ "sov_en", 0x00000030, 24, 24, CSR_RW, 0x00000000 },
	{ "SCTRL", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD scode0
	{ "sync_code_0", 0x00000034, 15, 0, CSR_RW, 0x0000FFFF },
	{ "sync_code_1", 0x00000034, 31, 16, CSR_RW, 0x00000000 },
	{ "SCODE0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD scode1
	{ "sync_code_2", 0x00000038, 15, 0, CSR_RW, 0x00000000 },
	{ "SCODE1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD fcode
	{ "sof_code", 0x0000003C, 15, 0, CSR_RW, 0x00000000 },
	{ "eof_code", 0x0000003C, 31, 16, CSR_RW, 0x00000000 },
	{ "FCODE", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lcode
	{ "sol_code", 0x00000040, 15, 0, CSR_RW, 0x00000000 },
	{ "eol_code", 0x00000040, 31, 16, CSR_RW, 0x00000000 },
	{ "LCODE", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD vcode
	{ "sov_code", 0x00000044, 15, 0, CSR_RW, 0x00000000 },
	{ "eov_code", 0x00000044, 31, 16, CSR_RW, 0x00000000 },
	{ "VCODE", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD fcnt
	{ "frame_count", 0x00000050, 15, 0, CSR_RO, 0x00000000 },
	{ "FCNT", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD sta0
	{ "active_line_count", 0x00000054, 15, 0, CSR_RO, 0x00000000 },
	{ "blank_line_count", 0x00000054, 31, 16, CSR_RO, 0x00000000 },
	{ "STA0", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD sta1
	{ "word_count", 0x00000058, 15, 0, CSR_RO, 0x00000000 },
	{ "STA1", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg0
	{ "debug_sel", 0x00000060, 1, 0, CSR_RW, 0x00000000 },
	{ "DBG0", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg1
	{ "debug_mon", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG1", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PS_H_
