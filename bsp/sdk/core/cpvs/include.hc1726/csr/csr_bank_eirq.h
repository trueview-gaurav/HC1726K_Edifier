/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_EIRQ_H_
#define CSR_BANK_EIRQ_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from eirq  ***/
typedef struct csr_bank_eirq {
	/* IRQ_CLR 12'h0000 */
	union {
		uint32_t irq_clr; // word name
		struct {
			uint32_t irq_clear_pos_0 : 1;
			uint32_t irq_clear_pos_1 : 1;
			uint32_t irq_clear_pos_2 : 1;
			uint32_t irq_clear_pos_3 : 1;
			uint32_t irq_clear_pos_4 : 1;
			uint32_t irq_clear_neg_0 : 1;
			uint32_t irq_clear_neg_1 : 1;
			uint32_t irq_clear_neg_2 : 1;
			uint32_t irq_clear_neg_3 : 1;
			uint32_t irq_clear_neg_4 : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 12'h0004 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_pos_0 : 1;
			uint32_t status_pos_1 : 1;
			uint32_t status_pos_2 : 1;
			uint32_t status_pos_3 : 1;
			uint32_t status_pos_4 : 1;
			uint32_t status_neg_0 : 1;
			uint32_t status_neg_1 : 1;
			uint32_t status_neg_2 : 1;
			uint32_t status_neg_3 : 1;
			uint32_t status_neg_4 : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 12'h0008 */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_pos_0 : 1;
			uint32_t irq_mask_pos_1 : 1;
			uint32_t irq_mask_pos_2 : 1;
			uint32_t irq_mask_pos_3 : 1;
			uint32_t irq_mask_pos_4 : 1;
			uint32_t irq_mask_neg_0 : 1;
			uint32_t irq_mask_neg_1 : 1;
			uint32_t irq_mask_neg_2 : 1;
			uint32_t irq_mask_neg_3 : 1;
			uint32_t irq_mask_neg_4 : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EDGE_EN 12'h000C */
	union {
		uint32_t edge_en; // word name
		struct {
			uint32_t pos_en_0 : 1;
			uint32_t pos_en_1 : 1;
			uint32_t pos_en_2 : 1;
			uint32_t pos_en_3 : 1;
			uint32_t pos_en_4 : 1;
			uint32_t neg_en_0 : 1;
			uint32_t neg_en_1 : 1;
			uint32_t neg_en_2 : 1;
			uint32_t neg_en_3 : 1;
			uint32_t neg_en_4 : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBNC_EN 12'h0010 */
	union {
		uint32_t dbnc_en; // word name
		struct {
			uint32_t dbnc_en_0 : 1;
			uint32_t dbnc_en_1 : 1;
			uint32_t dbnc_en_2 : 1;
			uint32_t dbnc_en_3 : 1;
			uint32_t dbnc_en_4 : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SENS_NUM_0 12'h0014 */
	union {
		uint32_t word_sens_num_0; // word name
		struct {
			uint32_t sens_num_0 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_HOLD_NUM_0 12'h0018 */
	union {
		uint32_t word_hold_num_0; // word name
		struct {
			uint32_t hold_num_0 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SENS_NUM_1 12'h001C */
	union {
		uint32_t word_sens_num_1; // word name
		struct {
			uint32_t sens_num_1 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_HOLD_NUM_1 12'h0020 */
	union {
		uint32_t word_hold_num_1; // word name
		struct {
			uint32_t hold_num_1 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SENS_NUM_2 12'h0024 */
	union {
		uint32_t word_sens_num_2; // word name
		struct {
			uint32_t sens_num_2 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_HOLD_NUM_2 12'h0028 */
	union {
		uint32_t word_hold_num_2; // word name
		struct {
			uint32_t hold_num_2 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SENS_NUM_3 12'h002C */
	union {
		uint32_t word_sens_num_3; // word name
		struct {
			uint32_t sens_num_3 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_HOLD_NUM_3 12'h0030 */
	union {
		uint32_t word_hold_num_3; // word name
		struct {
			uint32_t hold_num_3 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SENS_NUM_4 12'h0034 */
	union {
		uint32_t word_sens_num_4; // word name
		struct {
			uint32_t sens_num_4 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_HOLD_NUM_4 12'h0038 */
	union {
		uint32_t word_hold_num_4; // word name
		struct {
			uint32_t hold_num_4 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankEirq;

#endif