#ifndef CSR_BANK_ADODEC_H_
#define CSR_BANK_ADODEC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adodec  ***/
typedef struct csr_bank_adodec {
	/* ADODEC00 16'h0000 */
	union {
		uint32_t adodec00; // word name
		struct {
			uint32_t clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADODEC01 16'h0004 [Unused] */
	uint32_t empty_word_adodec01;
	/* ADODEC02 16'h0008 [Unused] */
	uint32_t empty_word_adodec02;
	/* ADODEC03 16'h000C [Unused] */
	uint32_t empty_word_adodec03;
	/* ADODEC04 16'h0010 */
	union {
		uint32_t adodec04; // word name
		struct {
			uint32_t decoder_ch_mode : 3;
			uint32_t : 5; // padding bits
			uint32_t compress_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t g711_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t g726_mode : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADODEC05 16'h0014 */
	union {
		uint32_t adodec05; // word name
		struct {
			uint32_t pack_mode : 3;
			uint32_t : 5; // padding bits
			uint32_t little_endian : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ADODEC06 16'h0018 */
	union {
		uint32_t adodec06; // word name
		struct {
			uint32_t pre_shift_2s : 32;
		};
	};
	/* ADODEC07 16'h001C */
	union {
		uint32_t adodec07; // word name
		struct {
			uint32_t post_shift_2s : 32;
		};
	};
	/* ADODEC08 16'h0020 */
	union {
		uint32_t adodec08; // word name
		struct {
			uint32_t gain : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADODEC09 16'h0024 */
	union {
		uint32_t adodec09; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankAdodec;

#endif