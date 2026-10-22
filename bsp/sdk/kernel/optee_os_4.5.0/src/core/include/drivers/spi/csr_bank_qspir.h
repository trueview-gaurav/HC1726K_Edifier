/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_QSPIR_H_
#define CSR_BANK_QSPIR_H_

#include <stdint.h>

/***  C struct generated from qspir  ***/
typedef struct csr_bank_qspir {
	/* LR032_00 10'h000 */
	union {
		uint32_t lr032_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR032_01 10'h004 */
	union {
		uint32_t lr032_01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LR032_02 10'h008 */
	union {
		uint32_t lr032_02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t status_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t status_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LR032_03 10'h00C */
	union {
		uint32_t lr032_03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LR032_04 10'h010 */
	union {
		uint32_t lr032_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 3; // padding bits
			uint32_t axi_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* LR032_05 10'h014 [Unused] */
	uint32_t empty_word_lr032_05;
	/* LR032_06 10'h018 */
	union {
		uint32_t lr032_06; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t fifo_ready_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR032_07 10'h01C */
	union {
		uint32_t lr032_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR032_08 10'h020 */
	union {
		uint32_t lr032_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR032_09 10'h024 */
	union {
		uint32_t lr032_09; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR032_10 10'h028 */
	union {
		uint32_t lr032_10; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR032_11 10'h02C */
	union {
		uint32_t lr032_11; // word name
		struct {
			uint32_t pixel_flush_len : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR032_12 10'h030 */
	union {
		uint32_t lr032_12; // word name
		struct {
			uint32_t fifo_flush_len : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR032_13 10'h034 */
	union {
		uint32_t lr032_13; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LR032_14 10'h038 */
	union {
		uint32_t lr032_14; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ini_addr_word : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR032_15 10'h03C */
	union {
		uint32_t lr032_15; // word name
		struct {
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR032_16 10'h040 [Unused] */
	uint32_t empty_word_lr032_16;
	/* LR032_17 10'h044 [Unused] */
	uint32_t empty_word_lr032_17;
	/* LR032_18 10'h048 [Unused] */
	uint32_t empty_word_lr032_18;
	/* LR032_19 10'h04C [Unused] */
	uint32_t empty_word_lr032_19;
	/* LR032_20 10'h050 [Unused] */
	uint32_t empty_word_lr032_20;
	/* LR032_21 10'h054 [Unused] */
	uint32_t empty_word_lr032_21;
	/* LR032_22 10'h058 [Unused] */
	uint32_t empty_word_lr032_22;
	/* LR032_23 10'h05C [Unused] */
	uint32_t empty_word_lr032_23;
	/* LR032_24 10'h060 [Unused] */
	uint32_t empty_word_lr032_24;
	/* LR032_25 10'h064 [Unused] */
	uint32_t empty_word_lr032_25;
	/* LR032_26 10'h068 [Unused] */
	uint32_t empty_word_lr032_26;
	/* LR032_27 10'h06C [Unused] */
	uint32_t empty_word_lr032_27;
	/* LR032_28 10'h070 [Unused] */
	uint32_t empty_word_lr032_28;
	/* LR032_29 10'h074 [Unused] */
	uint32_t empty_word_lr032_29;
	/* LR032_30 10'h078 [Unused] */
	uint32_t empty_word_lr032_30;
	/* LR032_31 10'h07C [Unused] */
	uint32_t empty_word_lr032_31;
	/* LR032_32 10'h080 [Unused] */
	uint32_t empty_word_lr032_32;
	/* LR032_33 10'h084 [Unused] */
	uint32_t empty_word_lr032_33;
	/* LR032_34 10'h088 [Unused] */
	uint32_t empty_word_lr032_34;
	/* LR032_35 10'h08C [Unused] */
	uint32_t empty_word_lr032_35;
	/* LR032_36 10'h090 [Unused] */
	uint32_t empty_word_lr032_36;
	/* LR032_37 10'h094 [Unused] */
	uint32_t empty_word_lr032_37;
	/* LR032_38 10'h098 [Unused] */
	uint32_t empty_word_lr032_38;
	/* LR032_39 10'h09C [Unused] */
	uint32_t empty_word_lr032_39;
	/* LR032_40 10'h0A0 */
	union {
		uint32_t lr032_40; // word name
		struct {
			uint32_t ini_addr_linear : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR032_41 10'h0A4 [Unused] */
	uint32_t empty_word_lr032_41;
	/* LR032_42 10'h0A8 [Unused] */
	uint32_t empty_word_lr032_42;
	/* LR032_43 10'h0AC [Unused] */
	uint32_t empty_word_lr032_43;
	/* LR032_44 10'h0B0 [Unused] */
	uint32_t empty_word_lr032_44;
	/* LR032_45 10'h0B4 [Unused] */
	uint32_t empty_word_lr032_45;
	/* LR032_46 10'h0B8 [Unused] */
	uint32_t empty_word_lr032_46;
	/* LR032_47 10'h0BC [Unused] */
	uint32_t empty_word_lr032_47;
	/* LR032_48 10'h0C0 [Unused] */
	uint32_t empty_word_lr032_48;
} CsrBankQspir;

#endif
