/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ADODEC_H_
#define CSR_BANK_ADODEC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adodec  ***/
typedef struct csr_bank_adodec {
	/* ADOENC_CLEAR 16'h0000 */
	union {
		uint32_t adoenc_clear; // word name
		struct {
			uint32_t clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOENC_MODE 16'h0004 */
	union {
		uint32_t adoenc_mode; // word name
		struct {
			uint32_t decoder_ch_mode : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOENC_ADJ_PRE 16'h0008 */
	union {
		uint32_t adoenc_adj_pre; // word name
		struct {
			uint32_t pre_shift_2s : 32;
		};
	};
	/* ADOENC_ADJ_POST 16'h000C */
	union {
		uint32_t adoenc_adj_post; // word name
		struct {
			uint32_t post_shift_2s : 32;
		};
	};
	/* ADOENC_ADJ_GAIN 16'h0010 */
	union {
		uint32_t adoenc_adj_gain; // word name
		struct {
			uint32_t gain : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOENC_RESERVED 16'h0014 */
	union {
		uint32_t adoenc_reserved; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* ADOENC_DEBUG_SEL 16'h0018 */
	union {
		uint32_t adoenc_debug_sel; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdodec;

#endif