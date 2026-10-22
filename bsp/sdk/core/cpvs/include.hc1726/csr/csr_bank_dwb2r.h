/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DWB2R_H_
#define CSR_BANK_DWB2R_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dwb2r  ***/
typedef struct csr_bank_dwb2r {
	/* DWB2R000 10'h000 */
	union {
		uint32_t dwb2r000; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DWB2R001 10'h004 */
	union {
		uint32_t dwb2r001; // word name
		struct {
			uint32_t y_block_h_num : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t y_block_v_num : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* DWB2R002 10'h008 */
	union {
		uint32_t dwb2r002; // word name
		struct {
			uint32_t c_block_h_num : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t c_block_v_num : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* DWB2R003 10'h00c */
	union {
		uint32_t dwb2r003; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DWB2R004 10'h010 */
	union {
		uint32_t dwb2r004; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DWB2R005 10'h014 */
	union {
		uint32_t dwb2r005; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DWB2R006 10'h018 [Unused] */
	uint32_t empty_word_dwb2r006;
} CsrBankDwb2r;

#endif