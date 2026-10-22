/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_CVS_H_
#define CSR_BANK_CVS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from cvs  ***/
typedef struct csr_bank_cvs {
	/* CVS00 12'h000 */
	union {
		uint32_t cvs00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS01 12'h004 */
	union {
		uint32_t cvs01; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS02 12'h008 */
	union {
		uint32_t cvs02; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS03 12'h00C */
	union {
		uint32_t cvs03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS04 12'h010 */
	union {
		uint32_t cvs04; // word name
		struct {
			uint32_t width : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS05 12'h014 */
	union {
		uint32_t cvs05; // word name
		struct {
			uint32_t height : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS06 12'h018 */
	union {
		uint32_t cvs06; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS07 12'h01C */
	union {
		uint32_t cvs07; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS08 12'h020 [Unused] */
	uint32_t empty_word_cvs08;
	/* CVS09 12'h024 [Unused] */
	uint32_t empty_word_cvs09;
	/* CVS10 12'h028 [Unused] */
	uint32_t empty_word_cvs10;
	/* CVS11 12'h02C [Unused] */
	uint32_t empty_word_cvs11;
	/* CVS12 12'h030 [Unused] */
	uint32_t empty_word_cvs12;
	/* CVS13 12'h034 [Unused] */
	uint32_t empty_word_cvs13;
	/* CVS14 12'h038 [Unused] */
	uint32_t empty_word_cvs14;
	/* CVS15 12'h03C [Unused] */
	uint32_t empty_word_cvs15;
	/* CVS16 12'h040 [Unused] */
	uint32_t empty_word_cvs16;
	/* CVS17 12'h044 [Unused] */
	uint32_t empty_word_cvs17;
	/* CVS18 12'h048 [Unused] */
	uint32_t empty_word_cvs18;
	/* CVS19 12'h04C [Unused] */
	uint32_t empty_word_cvs19;
	/* CVS20 12'h050 [Unused] */
	uint32_t empty_word_cvs20;
	/* CVS21 12'h054 [Unused] */
	uint32_t empty_word_cvs21;
	/* CVS22 12'h058 [Unused] */
	uint32_t empty_word_cvs22;
	/* CVS23 12'h05C [Unused] */
	uint32_t empty_word_cvs23;
	/* CVS24 12'h060 [Unused] */
	uint32_t empty_word_cvs24;
	/* CVS25 12'h064 [Unused] */
	uint32_t empty_word_cvs25;
	/* CVS26 12'h068 [Unused] */
	uint32_t empty_word_cvs26;
	/* CVS27 12'h06C [Unused] */
	uint32_t empty_word_cvs27;
	/* CVS28 12'h070 [Unused] */
	uint32_t empty_word_cvs28;
	/* CVS29 12'h074 [Unused] */
	uint32_t empty_word_cvs29;
	/* CVS30 12'h078 [Unused] */
	uint32_t empty_word_cvs30;
	/* CVS31 12'h07C [Unused] */
	uint32_t empty_word_cvs31;
} CsrBankCvs;

#endif