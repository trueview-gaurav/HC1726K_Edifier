/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ISPIN_CHECKSUM_H_
#define CSR_TABLE_ISPIN_CHECKSUM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ispin_checksum[] = {
	// WORD clr
	{ "clear", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "CLR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ispr0_0
	{ "checksum_ispr0", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPR0_0", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD ispr0_1
	{ "checksum_ispr0_data_0", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPR0_1", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD ispr0_2
	{ "checksum_ispr0_data_1", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPR0_2", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD ispr0_3
	{ "checksum_ispr0_data_2", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPR0_3", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD ispr1_0
	{ "checksum_ispr1", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPR1_0", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD ispr1_1
	{ "checksum_ispr1_data_0", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPR1_1", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD ispr1_2
	{ "checksum_ispr1_data_1", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPR1_2", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD ispr1_3
	{ "checksum_ispr1_data_2", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPR1_3", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD pg0
	{ "checksum_pg0", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "PG0", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD pg1
	{ "checksum_pg1", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "PG1", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD gfx0
	{ "checksum_gfx0", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	{ "GFX0", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD cs0
	{ "checksum_cs0", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	{ "CS0", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD cs1
	{ "checksum_cs1", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	{ "CS1", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD prd1
	{ "checksum_prd1", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	{ "PRD1", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ISPIN_CHECKSUM_H_
