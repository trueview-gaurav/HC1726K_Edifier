/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DBC_H_
#define CSR_TABLE_DBC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dbc[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_format
	{ "cfa_mode", 0x00000010, 1, 0, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "CFA_FORMAT", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_0
	{ "cfa_phase_0", 0x00000014, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_1", 0x00000014, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_2", 0x00000014, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_3", 0x00000014, 26, 24, CSR_RW, 0x00000000 },
	{ "WORD_CFA_PHASE_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_1
	{ "cfa_phase_4", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_5", 0x00000018, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_6", 0x00000018, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_7", 0x00000018, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_1", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_2
	{ "cfa_phase_8", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_9", 0x0000001C, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_10", 0x0000001C, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_11", 0x0000001C, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_2", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_3
	{ "cfa_phase_12", 0x00000020, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_13", 0x00000020, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_14", 0x00000020, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_15", 0x00000020, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_3", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000024, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000024, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mode
	{ "mode", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_0
	{ "level_g0", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "level_r", 0x0000002C, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_0", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_1
	{ "level_b", 0x00000030, 15, 0, CSR_RW, 0x00000000 },
	{ "level_g1", 0x00000030, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_1", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_2
	{ "level_s", 0x00000034, 15, 0, CSR_RW, 0x00000000 },
	{ "LEVEL_2", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000038, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DBC_H_
