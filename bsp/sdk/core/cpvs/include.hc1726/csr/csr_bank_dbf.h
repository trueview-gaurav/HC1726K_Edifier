/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DBF_H_
#define CSR_BANK_DBF_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dbf  ***/
typedef struct csr_bank_dbf {
	/* DBF00 8'h00 [Unused] */
	uint32_t empty_word_dbf00;
	/* DBF01 8'h04 [Unused] */
	uint32_t empty_word_dbf01;
	/* DBF02 8'h08 [Unused] */
	uint32_t empty_word_dbf02;
	/* DBF03 8'h0C [Unused] */
	uint32_t empty_word_dbf03;
	/* DBF04 8'h10 [Unused] */
	uint32_t empty_word_dbf04;
	/* DBF05 8'h14 */
	union {
		uint32_t dbf05; // word name
		struct {
			uint32_t enable : 1;
			uint32_t : 7; // padding bits
			uint32_t filter_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBF06 8'h18 */
	union {
		uint32_t dbf06; // word name
		struct {
			uint32_t width : 16;
			uint32_t block_x : 16;
		};
	};
	/* DBF07 8'h1C */
	union {
		uint32_t dbf07; // word name
		struct {
			uint32_t range : 5;
			uint32_t : 3; // padding bits
			uint32_t alpha_slope : 5;
			uint32_t : 3; // padding bits
			uint32_t alpha_max : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBF08 8'h20 */
	union {
		uint32_t dbf08; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBF09 8'h24 [Unused] */
	uint32_t empty_word_dbf09;
	/* DBF10 8'h28 [Unused] */
	uint32_t empty_word_dbf10;
	/* DBF11 8'h2C [Unused] */
	uint32_t empty_word_dbf11;
	/* DBF12 8'h30 [Unused] */
	uint32_t empty_word_dbf12;
	/* DBF13 8'h34 [Unused] */
	uint32_t empty_word_dbf13;
	/* DBF14 8'h38 [Unused] */
	uint32_t empty_word_dbf14;
	/* DBF15 8'h3C [Unused] */
	uint32_t empty_word_dbf15;
	/* DBF16 8'h40 [Unused] */
	uint32_t empty_word_dbf16;
	/* DBF17 8'h44 [Unused] */
	uint32_t empty_word_dbf17;
	/* DBF18 8'h48 [Unused] */
	uint32_t empty_word_dbf18;
	/* DBF19 8'h4C [Unused] */
	uint32_t empty_word_dbf19;
	/* DBF20 8'h50 [Unused] */
	uint32_t empty_word_dbf20;
	/* DBF21 8'h54 [Unused] */
	uint32_t empty_word_dbf21;
	/* DBF22 8'h58 [Unused] */
	uint32_t empty_word_dbf22;
	/* DBF23 8'h5C [Unused] */
	uint32_t empty_word_dbf23;
	/* DBF24 8'h60 [Unused] */
	uint32_t empty_word_dbf24;
	/* DBF25 8'h64 [Unused] */
	uint32_t empty_word_dbf25;
	/* DBF26 8'h68 [Unused] */
	uint32_t empty_word_dbf26;
	/* DBF27 8'h6C [Unused] */
	uint32_t empty_word_dbf27;
	/* DBF28 8'h70 [Unused] */
	uint32_t empty_word_dbf28;
	/* DBF29 8'h74 [Unused] */
	uint32_t empty_word_dbf29;
	/* DBF30 8'h78 [Unused] */
	uint32_t empty_word_dbf30;
	/* DBF31 8'h7C [Unused] */
	uint32_t empty_word_dbf31;
	/* DBF32 8'h80 [Unused] */
	uint32_t empty_word_dbf32;
	/* DBF33 8'h84 [Unused] */
	uint32_t empty_word_dbf33;
	/* DBF34 8'h88 [Unused] */
	uint32_t empty_word_dbf34;
	/* DBF35 8'h8C [Unused] */
	uint32_t empty_word_dbf35;
	/* DBF36 8'h90 [Unused] */
	uint32_t empty_word_dbf36;
	/* DBF37 8'h94 [Unused] */
	uint32_t empty_word_dbf37;
	/* DBF38 8'h98 [Unused] */
	uint32_t empty_word_dbf38;
	/* DBF39 8'h9C [Unused] */
	uint32_t empty_word_dbf39;
	/* DBF40 8'hA0 [Unused] */
	uint32_t empty_word_dbf40;
	/* DBF41 8'hA4 [Unused] */
	uint32_t empty_word_dbf41;
	/* DBF42 8'hA8 [Unused] */
	uint32_t empty_word_dbf42;
	/* DBF43 8'hAC [Unused] */
	uint32_t empty_word_dbf43;
	/* DBF44 8'hB0 [Unused] */
	uint32_t empty_word_dbf44;
	/* DBF45 8'hB4 [Unused] */
	uint32_t empty_word_dbf45;
	/* DBF46 8'hB8 [Unused] */
	uint32_t empty_word_dbf46;
	/* DBF47 8'hBC [Unused] */
	uint32_t empty_word_dbf47;
	/* DBF48 8'hC0 [Unused] */
	uint32_t empty_word_dbf48;
	/* DBF49 8'hC4 [Unused] */
	uint32_t empty_word_dbf49;
	/* DBF50 8'hC8 [Unused] */
	uint32_t empty_word_dbf50;
	/* DBF51 8'hCC [Unused] */
	uint32_t empty_word_dbf51;
	/* DBF52 8'hD0 [Unused] */
	uint32_t empty_word_dbf52;
	/* DBF53 8'hD4 [Unused] */
	uint32_t empty_word_dbf53;
	/* DBF54 8'hD8 [Unused] */
	uint32_t empty_word_dbf54;
	/* DBF55 8'hDC [Unused] */
	uint32_t empty_word_dbf55;
	/* DBF56 8'hE0 [Unused] */
	uint32_t empty_word_dbf56;
	/* DBF57 8'hE4 [Unused] */
	uint32_t empty_word_dbf57;
	/* DBF58 8'hE8 [Unused] */
	uint32_t empty_word_dbf58;
	/* DBF59 8'hEC [Unused] */
	uint32_t empty_word_dbf59;
	/* DBF60 8'hF0 [Unused] */
	uint32_t empty_word_dbf60;
	/* DBF61 8'hF4 [Unused] */
	uint32_t empty_word_dbf61;
	/* DBF62 8'hF8 [Unused] */
	uint32_t empty_word_dbf62;
	/* DBF63 8'hFC [Unused] */
	uint32_t empty_word_dbf63;
} CsrBankDbf;

#endif