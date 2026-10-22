/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CS_H_
#define CSR_TABLE_CS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_cs[] = {
	// WORD cs00
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "CS00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cs01
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "CS01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cs02
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "CS02", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD cs03
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "CS03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs04
	{ "legacy_420", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "CS04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs05
	{ "chroma_shift_sampling", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "CS05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs06
	{ "chroma_even_line", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "CS06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs07
	{ "width", 0x0000001C, 15, 0, CSR_RW, 0x00000780 },
	{ "CS07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs08
	{ "height", 0x00000020, 15, 0, CSR_RW, 0x00000438 },
	{ "CS08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs09
	{ "debug_mon_sel", 0x00000024, 1, 0, CSR_RW, 0x00000000 },
	{ "CS09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_free_run
	{ "frame_start_free_run", 0x00000080, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_end_free_run", 0x00000080, 8, 8, CSR_W1P, 0x00000000 },
	{ "WORD_FREE_RUN", 0x00000080, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CS_H_
