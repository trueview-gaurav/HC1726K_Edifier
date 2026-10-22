/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_CUS_H_
#define CSR_BANK_CUS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from cus  ***/
typedef struct csr_bank_cus {
	/* FRAME_ST 16'h0000 */
	union {
		uint32_t frame_st; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STATUS 16'h0004 */
	union {
		uint32_t irq_status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLR 16'h0008 */
	union {
		uint32_t irq_clr; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 16'h000C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESOLUTION 16'h0010 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* COLOR 16'h0014 */
	union {
		uint32_t color; // word name
		struct {
			uint32_t color_space : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_MON_SEL 16'h0018 */
	union {
		uint32_t dbg_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RSV00 16'h001C [Unused] */
	uint32_t empty_word_rsv00;
	/* RSV01 16'h0020 [Unused] */
	uint32_t empty_word_rsv01;
	/* RSV02 16'h0024 [Unused] */
	uint32_t empty_word_rsv02;
	/* RSV03 16'h0028 [Unused] */
	uint32_t empty_word_rsv03;
	/* RSV04 16'h002C [Unused] */
	uint32_t empty_word_rsv04;
	/* RSV05 16'h0030 [Unused] */
	uint32_t empty_word_rsv05;
	/* RSV06 16'h0034 [Unused] */
	uint32_t empty_word_rsv06;
	/* RSV07 16'h0038 [Unused] */
	uint32_t empty_word_rsv07;
	/* RSV08 16'h003C [Unused] */
	uint32_t empty_word_rsv08;
	/* RSV09 16'h0040 [Unused] */
	uint32_t empty_word_rsv09;
	/* RSV10 16'h0044 [Unused] */
	uint32_t empty_word_rsv10;
	/* RSV11 16'h0048 [Unused] */
	uint32_t empty_word_rsv11;
	/* RSV12 16'h004C [Unused] */
	uint32_t empty_word_rsv12;
	/* RSV13 16'h0050 [Unused] */
	uint32_t empty_word_rsv13;
	/* RSV14 16'h0054 [Unused] */
	uint32_t empty_word_rsv14;
	/* RSV15 16'h0058 [Unused] */
	uint32_t empty_word_rsv15;
	/* RSV16 16'h005C [Unused] */
	uint32_t empty_word_rsv16;
	/* RSV17 16'h0060 [Unused] */
	uint32_t empty_word_rsv17;
	/* RSV18 16'h0064 [Unused] */
	uint32_t empty_word_rsv18;
	/* RSV19 16'h0068 [Unused] */
	uint32_t empty_word_rsv19;
	/* RSV20 16'h006C [Unused] */
	uint32_t empty_word_rsv20;
	/* RSV21 16'h0070 [Unused] */
	uint32_t empty_word_rsv21;
	/* RSV22 16'h0074 [Unused] */
	uint32_t empty_word_rsv22;
	/* RSV23 16'h0078 [Unused] */
	uint32_t empty_word_rsv23;
	/* RSV24 16'h007C [Unused] */
	uint32_t empty_word_rsv24;
} CsrBankCus;

#endif