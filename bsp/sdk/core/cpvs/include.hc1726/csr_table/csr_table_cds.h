/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CDS_H_
#define CSR_TABLE_CDS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_cds[] = {
	// WORD frame_st
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "FRAME_ST", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_status
	{ "status_frame_end", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_clr
	{ "irq_clear_frame_end", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLR", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000010, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000010, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mode_word
	{ "mode", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "MODE_WORD", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD color
	{ "color_space", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "COLOR", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg_mon_sel
	{ "debug_mon_sel", 0x0000001C, 1, 0, CSR_RW, 0x00000000 },
	{ "DBG_MON_SEL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CDS_H_
