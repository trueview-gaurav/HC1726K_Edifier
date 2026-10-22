/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_TG_H_
#define CSR_TABLE_TG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_tg[] = {
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
	// WORD word_free_run
	{ "frame_start_free_run", 0x00000010, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_end_free_run", 0x00000010, 8, 8, CSR_W1P, 0x00000000 },
	{ "WORD_FREE_RUN", 0x00000010, 31, 0, CSR_W1P, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000014, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000014, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000018, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_TG_H_
