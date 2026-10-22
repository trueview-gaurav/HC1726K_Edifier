/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ISK_CHECKSUM_H_
#define CSR_TABLE_ISK_CHECKSUM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_isk_checksum[] = {
	// WORD clr
	{ "clear", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "CLR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD crop
	{ "checksum_crop", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	{ "CROP", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbc
	{ "checksum_dbc", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	{ "DBC", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD dcc
	{ "checksum_dcc", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	{ "DCC", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD lsc
	{ "checksum_lsc", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	{ "LSC", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD bsp
	{ "checksum_bsp", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	{ "BSP", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fgma
	{ "checksum_fgma", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "FGMA", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD fsc
	{ "checksum_fsc", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "FSC", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD yuv422to420
	{ "checksum_yuv422to420", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "YUV422TO420", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD cs
	{ "checksum_cs", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	{ "CS", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ISK_CHECKSUM_H_
