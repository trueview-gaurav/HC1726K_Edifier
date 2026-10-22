#ifndef CSR_BANK_AES_DEC_H_
#define CSR_BANK_AES_DEC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from aes_dec  ***/
typedef struct csr_bank_aes_dec {
	/* AES_DEC_00 10'h000 [Unused] */
	uint32_t empty_word_aes_dec_00;
	/* AES_DEC_01 10'h004 [Unused] */
	uint32_t empty_word_aes_dec_01;
	/* AES_DEC_02 10'h008 [Unused] */
	uint32_t empty_word_aes_dec_02;
	/* AES_DEC_03 10'h00C */
	union {
		uint32_t aes_dec_03; // word name
		struct {
			uint32_t key_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AES_DEC_04 10'h010 */
	union {
		uint32_t aes_dec_04; // word name
		struct {
			uint32_t key_0 : 32;
		};
	};
	/* AES_DEC_05 10'h014 */
	union {
		uint32_t aes_dec_05; // word name
		struct {
			uint32_t key_1 : 32;
		};
	};
	/* AES_DEC_06 10'h018 */
	union {
		uint32_t aes_dec_06; // word name
		struct {
			uint32_t key_2 : 32;
		};
	};
	/* AES_DEC_07 10'h01C */
	union {
		uint32_t aes_dec_07; // word name
		struct {
			uint32_t key_3 : 32;
		};
	};
	/* AES_DEC_08 10'h020 */
	union {
		uint32_t aes_dec_08; // word name
		struct {
			uint32_t key_4 : 32;
		};
	};
	/* AES_DEC_09 10'h024 */
	union {
		uint32_t aes_dec_09; // word name
		struct {
			uint32_t key_5 : 32;
		};
	};
	/* AES_DEC_10 10'h028 */
	union {
		uint32_t aes_dec_10; // word name
		struct {
			uint32_t key_6 : 32;
		};
	};
	/* AES_DEC_11 10'h02C */
	union {
		uint32_t aes_dec_11; // word name
		struct {
			uint32_t key_7 : 32;
		};
	};
	/* AES_DEC_12 10'h030 */
	union {
		uint32_t aes_dec_12; // word name
		struct {
			uint32_t intermediate_0 : 32;
		};
	};
	/* AES_DEC_13 10'h034 */
	union {
		uint32_t aes_dec_13; // word name
		struct {
			uint32_t intermediate_1 : 32;
		};
	};
	/* AES_DEC_14 10'h038 */
	union {
		uint32_t aes_dec_14; // word name
		struct {
			uint32_t intermediate_2 : 32;
		};
	};
	/* AES_DEC_15 10'h03C */
	union {
		uint32_t aes_dec_15; // word name
		struct {
			uint32_t intermediate_3 : 32;
		};
	};
	/* AES_DEC_16 10'h040 */
	union {
		uint32_t aes_dec_16; // word name
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
	/* AES_DEC_17 10'h044 */
	union {
		uint32_t aes_dec_17; // word name
		struct {
			uint32_t initial_vector_0 : 32;
		};
	};
	/* AES_DEC_18 10'h048 */
	union {
		uint32_t aes_dec_18; // word name
		struct {
			uint32_t initial_vector_1 : 32;
		};
	};
	/* AES_DEC_19 10'h04C */
	union {
		uint32_t aes_dec_19; // word name
		struct {
			uint32_t initial_vector_2 : 32;
		};
	};
	/* AES_DEC_20 10'h050 */
	union {
		uint32_t aes_dec_20; // word name
		struct {
			uint32_t initial_vector_3 : 32;
		};
	};
	/* AES_DEC_21 10'h054 */
	union {
		uint32_t aes_dec_21; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AES_DEC_22 10'h058 */
	union {
		uint32_t aes_dec_22; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankAes_dec;

#endif