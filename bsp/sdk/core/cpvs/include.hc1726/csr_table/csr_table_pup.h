/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PUP_H_
#define CSR_TABLE_PUP_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pup[] = {
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
	// WORD resolution
	{ "width", 0x00000010, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000010, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD color
	{ "color_space", 0x00000014, 1, 0, CSR_RW, 0x00000000 },
	{ "COLOR", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD pix_state
	{ "pix_0_state", 0x00000018, 1, 0, CSR_RW, 0x00000000 },
	{ "pix_1_state", 0x00000018, 8, 7, CSR_RW, 0x00000001 },
	{ "pix_2_state", 0x00000018, 16, 15, CSR_RW, 0x00000002 },
	{ "PIX_STATE", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD adj
	{ "pix_adj", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "ADJ", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD swap
	{ "pix_swap", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "SWAP", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD unmerge
	{ "pix_unmerge", 0x00000024, 15, 15, CSR_RW, 0x00000000 },
	{ "UNMERGE", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug
	{ "debug_mon_sel", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "DEBUG", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PUP_H_
