/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_AES_CODEC_H_
#define CSR_BANK_AES_CODEC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from aes_codec  ***/
typedef struct csr_bank_aes_codec {
	/* WORD_FRAME_START 10'h000 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_IRQ_CLEAR 10'h004 */
	union {
		uint32_t word_irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_STATUS 10'h008 */
	union {
		uint32_t word_status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_IRQ_MASK 10'h00C */
	union {
		uint32_t word_irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_MODE 10'h010 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DATA_SWAP 10'h014 */
	union {
		uint32_t word_data_swap; // word name
		struct {
			uint32_t word_swap : 1;
			uint32_t : 7; // padding bits
			uint32_t byte_swap : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LEN 10'h018 */
	union {
		uint32_t word_len; // word name
		struct {
			uint32_t length : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUR_LENGTH 10'h01C */
	union {
		uint32_t cur_length; // word name
		struct {
			uint32_t ack_i_cnt : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REVERSED 10'h020 */
	union {
		uint32_t reversed; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankAes_codec;

#endif