/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AES_DEC_H_
#define CSR_TABLE_AES_DEC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_aes_dec[] = {
	// WORD aes_dec_03
	{ "key_mode", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "AES_DEC_03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD aes_dec_04
	{ "key_0", 0x00000010, 31, 0, CSR_WO, 0x00000000 },
	{ "AES_DEC_04", 0x00000010, 31, 0, CSR_WO, 0x00000000 },
	// WORD aes_dec_05
	{ "key_1", 0x00000014, 31, 0, CSR_WO, 0x00000000 },
	{ "AES_DEC_05", 0x00000014, 31, 0, CSR_WO, 0x00000000 },
	// WORD aes_dec_06
	{ "key_2", 0x00000018, 31, 0, CSR_WO, 0x00000000 },
	{ "AES_DEC_06", 0x00000018, 31, 0, CSR_WO, 0x00000000 },
	// WORD aes_dec_07
	{ "key_3", 0x0000001C, 31, 0, CSR_WO, 0x00000000 },
	{ "AES_DEC_07", 0x0000001C, 31, 0, CSR_WO, 0x00000000 },
	// WORD aes_dec_08
	{ "key_4", 0x00000020, 31, 0, CSR_WO, 0x00000000 },
	{ "AES_DEC_08", 0x00000020, 31, 0, CSR_WO, 0x00000000 },
	// WORD aes_dec_09
	{ "key_5", 0x00000024, 31, 0, CSR_WO, 0x00000000 },
	{ "AES_DEC_09", 0x00000024, 31, 0, CSR_WO, 0x00000000 },
	// WORD aes_dec_10
	{ "key_6", 0x00000028, 31, 0, CSR_WO, 0x00000000 },
	{ "AES_DEC_10", 0x00000028, 31, 0, CSR_WO, 0x00000000 },
	// WORD aes_dec_11
	{ "key_7", 0x0000002C, 31, 0, CSR_WO, 0x00000000 },
	{ "AES_DEC_11", 0x0000002C, 31, 0, CSR_WO, 0x00000000 },
	// WORD aes_dec_12
	{ "intermediate_0", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	{ "AES_DEC_12", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD aes_dec_13
	{ "intermediate_1", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	{ "AES_DEC_13", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD aes_dec_14
	{ "intermediate_2", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	{ "AES_DEC_14", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD aes_dec_15
	{ "intermediate_3", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	{ "AES_DEC_15", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD aes_dec_16
	{ "mode", 0x00000040, 2, 0, CSR_RW, 0x00000001 },
	{ "byte_swap", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "word_swap", 0x00000040, 9, 9, CSR_RW, 0x00000000 },
	{ "AES_DEC_16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD aes_dec_17
	{ "initial_vector_0", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	{ "AES_DEC_17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD aes_dec_18
	{ "initial_vector_1", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	{ "AES_DEC_18", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD aes_dec_19
	{ "initial_vector_2", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	{ "AES_DEC_19", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD aes_dec_20
	{ "initial_vector_3", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	{ "AES_DEC_20", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD aes_dec_21
	{ "debug_mon_sel", 0x00000054, 0, 0, CSR_RW, 0x00000000 },
	{ "AES_DEC_21", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD aes_dec_22
	{ "reserved", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	{ "AES_DEC_22", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AES_DEC_H_
