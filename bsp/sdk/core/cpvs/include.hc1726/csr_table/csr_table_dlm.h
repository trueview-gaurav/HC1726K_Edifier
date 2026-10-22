/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DLM_H_
#define CSR_TABLE_DLM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dlm[] = {
	// WORD word_start
	{ "start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD word_clr
	{ "clear", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_CLR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD word_end
	{ "status_delay_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "WORD_END", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_cnt
	{ "count", 0x0000000C, 10, 0, CSR_RO, 0x00000000 },
	{ "WORD_CNT", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DLM_H_
