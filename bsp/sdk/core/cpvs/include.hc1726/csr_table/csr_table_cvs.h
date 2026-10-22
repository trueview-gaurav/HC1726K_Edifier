/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CVS_H_
#define CSR_TABLE_CVS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_cvs[] = {
	// WORD cvs00
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "CVS00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cvs01
	{ "status_frame_end", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "CVS01", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD cvs02
	{ "irq_clear_frame_end", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "CVS02", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cvs03
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "CVS03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cvs04
	{ "width", 0x00000010, 15, 0, CSR_RW, 0x00000780 },
	{ "CVS04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD cvs05
	{ "height", 0x00000014, 15, 0, CSR_RW, 0x00000438 },
	{ "CVS05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD cvs06
	{ "mode", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "CVS06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cvs07
	{ "debug_mon_sel", 0x0000001C, 1, 0, CSR_RW, 0x00000000 },
	{ "CVS07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CVS_H_
