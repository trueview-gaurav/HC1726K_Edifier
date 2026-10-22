/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_CS_H_
#define CSR_BANK_CS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from cs  ***/
typedef struct csr_bank_cs {
	/* CS00 12'h000 */
	union {
		uint32_t cs00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS01 12'h004 */
	union {
		uint32_t cs01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS02 12'h008 */
	union {
		uint32_t cs02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS03 12'h00C */
	union {
		uint32_t cs03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS04 12'h010 */
	union {
		uint32_t cs04; // word name
		struct {
			uint32_t legacy_420 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS05 12'h014 */
	union {
		uint32_t cs05; // word name
		struct {
			uint32_t chroma_shift_sampling : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS06 12'h018 */
	union {
		uint32_t cs06; // word name
		struct {
			uint32_t chroma_even_line : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS07 12'h01C */
	union {
		uint32_t cs07; // word name
		struct {
			uint32_t width : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS08 12'h020 */
	union {
		uint32_t cs08; // word name
		struct {
			uint32_t height : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS09 12'h024 */
	union {
		uint32_t cs09; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS10 12'h028 [Unused] */
	uint32_t empty_word_cs10;
	/* CS11 12'h02C [Unused] */
	uint32_t empty_word_cs11;
	/* CS12 12'h030 [Unused] */
	uint32_t empty_word_cs12;
	/* CS13 12'h034 [Unused] */
	uint32_t empty_word_cs13;
	/* CS14 12'h038 [Unused] */
	uint32_t empty_word_cs14;
	/* CS15 12'h03C [Unused] */
	uint32_t empty_word_cs15;
	/* CS16 12'h040 [Unused] */
	uint32_t empty_word_cs16;
	/* CS17 12'h044 [Unused] */
	uint32_t empty_word_cs17;
	/* CS18 12'h048 [Unused] */
	uint32_t empty_word_cs18;
	/* CS19 12'h04C [Unused] */
	uint32_t empty_word_cs19;
	/* CS20 12'h050 [Unused] */
	uint32_t empty_word_cs20;
	/* CS21 12'h054 [Unused] */
	uint32_t empty_word_cs21;
	/* CS22 12'h058 [Unused] */
	uint32_t empty_word_cs22;
	/* CS23 12'h05C [Unused] */
	uint32_t empty_word_cs23;
	/* CS24 12'h060 [Unused] */
	uint32_t empty_word_cs24;
	/* CS25 12'h064 [Unused] */
	uint32_t empty_word_cs25;
	/* CS26 12'h068 [Unused] */
	uint32_t empty_word_cs26;
	/* CS27 12'h06C [Unused] */
	uint32_t empty_word_cs27;
	/* CS28 12'h070 [Unused] */
	uint32_t empty_word_cs28;
	/* CS29 12'h074 [Unused] */
	uint32_t empty_word_cs29;
	/* CS30 12'h078 [Unused] */
	uint32_t empty_word_cs30;
	/* CS31 12'h07C [Unused] */
	uint32_t empty_word_cs31;
	/* WORD_FREE_RUN 12'h080 */
	union {
		uint32_t word_free_run; // word name
		struct {
			uint32_t frame_start_free_run : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_frame_end_free_run : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCs;

#endif