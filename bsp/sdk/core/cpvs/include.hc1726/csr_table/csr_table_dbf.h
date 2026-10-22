/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DBF_H_
#define CSR_TABLE_DBF_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dbf[] = {
	// WORD dbf05
	{ "enable", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "filter_type", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "DBF05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbf06
	{ "width", 0x00000018, 15, 0, CSR_RW, 0x00000100 },
	{ "block_x", 0x00000018, 31, 16, CSR_RW, 0x00000080 },
	{ "DBF06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbf07
	{ "range", 0x0000001C, 4, 0, CSR_RW, 0x0000000C },
	{ "alpha_slope", 0x0000001C, 12, 8, CSR_RW, 0x00000008 },
	{ "alpha_max", 0x0000001C, 20, 16, CSR_RW, 0x00000010 },
	{ "DBF07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbf08
	{ "debug_mon_sel", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "DBF08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DBF_H_
