/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ADODEC_H_
#define CSR_TABLE_ADODEC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_adodec[] = {
	// WORD adoenc_clear
	{ "clear", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "ADOENC_CLEAR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD adoenc_mode
	{ "decoder_ch_mode", 0x00000004, 2, 0, CSR_RW, 0x00000000 },
	{ "ADOENC_MODE", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoenc_adj_pre
	{ "pre_shift_2s", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	{ "ADOENC_ADJ_PRE", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoenc_adj_post
	{ "post_shift_2s", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	{ "ADOENC_ADJ_POST", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoenc_adj_gain
	{ "gain", 0x00000010, 15, 0, CSR_RW, 0x00000100 },
	{ "ADOENC_ADJ_GAIN", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoenc_reserved
	{ "reserved", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	{ "ADOENC_RESERVED", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoenc_debug_sel
	{ "debug_mon_sel", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "ADOENC_DEBUG_SEL", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ADODEC_H_
