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
} CsrBankDbf;

#endif