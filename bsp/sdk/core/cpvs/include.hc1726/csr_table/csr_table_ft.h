/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_FT_H_
#define CSR_TABLE_FT_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ft[] = {
	// WORD fti00
	{ "trans_size", 0x00000000, 1, 0, CSR_RW, 0x00000002 },
	{ "debug_mon_sel", 0x00000000, 9, 8, CSR_RW, 0x00000000 },
	{ "FTI00", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD fti01
	{ "reserved", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	{ "FTI01", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_FT_H_
