/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_TZPC_H_
#define CSR_TABLE_TZPC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_tzpc[] = {
	// WORD tzpcrosize
	{ "r0size", 0x00000000, 9, 0, CSR_RW, 0x00000200 },
	{ "TZPCROSIZE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD tzpcdecprot0stat
	{ "decprot0stat", 0x00000800, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCDECPROT0Stat", 0x00000800, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcdecprot0set
	{ "decprot0set", 0x00000804, 7, 0, CSR_W1P, 0x00000000 },
	{ "TZPCDECPROT0Set", 0x00000804, 31, 0, CSR_W1P, 0x00000000 },
	// WORD tzpcdecprot0clr
	{ "decprot0clr", 0x00000808, 7, 0, CSR_W1P, 0x00000000 },
	{ "TZPCDECPROT0Clr", 0x00000808, 31, 0, CSR_W1P, 0x00000000 },
	// WORD tzpcdecprot1stat
	{ "decprot1stat", 0x0000080C, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCDECPROT1Stat", 0x0000080C, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcdecprot1set
	{ "decprot1set", 0x00000810, 7, 0, CSR_W1P, 0x00000000 },
	{ "TZPCDECPROT1Set", 0x00000810, 31, 0, CSR_W1P, 0x00000000 },
	// WORD tzpcdecprot1clr
	{ "decprot1clr", 0x00000814, 7, 0, CSR_W1P, 0x00000000 },
	{ "TZPCDECPROT1Clr", 0x00000814, 31, 0, CSR_W1P, 0x00000000 },
	// WORD tzpcdecprot2stat
	{ "decprot2stat", 0x00000818, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCDECPROT2Stat", 0x00000818, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcdecprot2set
	{ "decprot2set", 0x0000081C, 7, 0, CSR_W1P, 0x00000000 },
	{ "TZPCDECPROT2Set", 0x0000081C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD tzpcdecprot2clr
	{ "decprot2clr", 0x00000820, 7, 0, CSR_W1P, 0x00000000 },
	{ "TZPCDECPROT2Clr", 0x00000820, 31, 0, CSR_W1P, 0x00000000 },
	// WORD tzpcperiphid0
	{ "partnumber0", 0x00000FE0, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCPERIPHID0", 0x00000FE0, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcperiphid1
	{ "partnumber1", 0x00000FE4, 3, 0, CSR_RO, 0x00000000 },
	{ "designer0", 0x00000FE4, 7, 4, CSR_RO, 0x00000000 },
	{ "TZPCPERIPHID1", 0x00000FE4, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcperiphid2
	{ "designer1", 0x00000FE8, 3, 0, CSR_RO, 0x00000000 },
	{ "revision", 0x00000FE8, 7, 4, CSR_RO, 0x00000000 },
	{ "TZPCPERIPHID2", 0x00000FE8, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcperiphid3
	{ "configuration", 0x00000FEC, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCPERIPHID3", 0x00000FEC, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcpcellid0
	{ "pcellid0", 0x00000FF0, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCPCELLID0", 0x00000FF0, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcpcellid1
	{ "pcellid1", 0x00000FF4, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCPCELLID1", 0x00000FF4, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcpcellid2
	{ "pcellid2", 0x00000FF8, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCPCELLID2", 0x00000FF8, 31, 0, CSR_RO, 0x00000000 },
	// WORD tzpcpcellid3
	{ "pcellid3", 0x00000FFC, 7, 0, CSR_RO, 0x00000000 },
	{ "TZPCPCELLID3", 0x00000FFC, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_TZPC_H_
