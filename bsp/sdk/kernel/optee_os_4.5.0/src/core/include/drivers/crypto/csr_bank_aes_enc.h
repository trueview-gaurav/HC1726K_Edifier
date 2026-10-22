/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_AES_ENC_H_
#define CSR_BANK_AES_ENC_H_

#include <stdint.h>

/***  C struct generated from aes_enc  ***/
typedef struct csr_bank_aes_enc {
	/* AES_ENC_00 10'h000 [Unused] */
	uint32_t empty_word_aes_enc_00;
	/* AES_ENC_01 10'h004 [Unused] */
	uint32_t empty_word_aes_enc_01;
	/* AES_ENC_02 10'h008 [Unused] */
	uint32_t empty_word_aes_enc_02;
	/* AES_ENC_03 10'h00C */
	union {
		uint32_t aes_enc_03; // word name
		struct {
			uint32_t key_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AES_ENC_04 10'h010 */
	union {
		uint32_t aes_enc_04; // word name
		struct {
			uint32_t key_0 : 32;
		};
	};
	/* AES_ENC_05 10'h014 */
	union {
		uint32_t aes_enc_05; // word name
		struct {
			uint32_t key_1 : 32;
		};
	};
	/* AES_ENC_06 10'h018 */
	union {
		uint32_t aes_enc_06; // word name
		struct {
			uint32_t key_2 : 32;
		};
	};
	/* AES_ENC_07 10'h01C */
	union {
		uint32_t aes_enc_07; // word name
		struct {
			uint32_t key_3 : 32;
		};
	};
	/* AES_ENC_08 10'h020 */
	union {
		uint32_t aes_enc_08; // word name
		struct {
			uint32_t key_4 : 32;
		};
	};
	/* AES_ENC_09 10'h024 */
	union {
		uint32_t aes_enc_09; // word name
		struct {
			uint32_t key_5 : 32;
		};
	};
	/* AES_ENC_10 10'h028 */
	union {
		uint32_t aes_enc_10; // word name
		struct {
			uint32_t key_6 : 32;
		};
	};
	/* AES_ENC_11 10'h02C */
	union {
		uint32_t aes_enc_11; // word name
		struct {
			uint32_t key_7 : 32;
		};
	};
	/* AES_ENC_12 10'h030 */
	union {
		uint32_t aes_enc_12; // word name
		struct {
			uint32_t intermediate_0 : 32;
		};
	};
	/* AES_ENC_13 10'h034 */
	union {
		uint32_t aes_enc_13; // word name
		struct {
			uint32_t intermediate_1 : 32;
		};
	};
	/* AES_ENC_14 10'h038 */
	union {
		uint32_t aes_enc_14; // word name
		struct {
			uint32_t intermediate_2 : 32;
		};
	};
	/* AES_ENC_15 10'h03C */
	union {
		uint32_t aes_enc_15; // word name
		struct {
			uint32_t intermediate_3 : 32;
		};
	};
	/* AES_ENC_16 10'h040 */
	union {
		uint32_t aes_enc_16; // word name
		struct {
			uint32_t mode : 3;
			uint32_t : 5; // padding bits
			uint32_t byte_swap : 1;
			uint32_t word_swap : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AES_ENC_17 10'h044 */
	union {
		uint32_t aes_enc_17; // word name
		struct {
			uint32_t initial_vector_0 : 32;
		};
	};
	/* AES_ENC_18 10'h048 */
	union {
		uint32_t aes_enc_18; // word name
		struct {
			uint32_t initial_vector_1 : 32;
		};
	};
	/* AES_ENC_19 10'h04C */
	union {
		uint32_t aes_enc_19; // word name
		struct {
			uint32_t initial_vector_2 : 32;
		};
	};
	/* AES_ENC_20 10'h050 */
	union {
		uint32_t aes_enc_20; // word name
		struct {
			uint32_t initial_vector_3 : 32;
		};
	};
	/* AES_ENC_21 10'h054 */
	union {
		uint32_t aes_enc_21; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AES_ENC_22 10'h058 */
	union {
		uint32_t aes_enc_22; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* AES_ENC_23 10'h05C [Unused] */
	uint32_t empty_word_aes_enc_23;
} CsrBankAes_enc;

#endif
