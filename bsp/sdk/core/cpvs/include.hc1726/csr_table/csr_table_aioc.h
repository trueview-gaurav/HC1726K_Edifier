/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AIOC_H_
#define CSR_TABLE_AIOC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_aioc[] = {
	// WORD test_sel
	{ "tst_sel", 0x00000000, 2, 0, CSR_RW, 0x00000000 },
	{ "TEST_SEL", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_resetb_pcfg
	{ "pad_resetb_pcfg", 0x00000004, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_RESETB_PCFG", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_xin_pcfg
	{ "pad_xin_pcfg", 0x00000008, 18, 16, CSR_RW, 0x00000001 },
	{ "WORD_PAD_XIN_PCFG", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AIOC_H_
