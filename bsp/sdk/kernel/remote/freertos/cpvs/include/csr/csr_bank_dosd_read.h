#ifndef CSR_BANK_DOSD_READ_H_
#define CSR_BANK_DOSD_READ_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dosd_read  ***/
typedef struct csr_bank_dosd_read {
	/* LR016_00 10'h000 */
	union {
		uint32_t lr016_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_01 10'h004 */
	union {
		uint32_t lr016_01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_02 10'h008 */
	union {
		uint32_t lr016_02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t status_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_03 10'h00C */
	union {
		uint32_t lr016_03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_04 10'h010 */
	union {
		uint32_t lr016_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LR016_05 10'h014 [Unused] */
	uint32_t empty_word_lr016_05;
	/* LR016_06 10'h018 */
	union {
		uint32_t lr016_06; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_07 10'h01C */
	union {
		uint32_t lr016_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_08 10'h020 */
	union {
		uint32_t lr016_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_09 10'h024 */
	union {
		uint32_t lr016_09; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR016_10 10'h028 */
	union {
		uint32_t lr016_10; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR016_11 10'h02C */
	union {
		uint32_t lr016_11; // word name
		struct {
			uint32_t pixel_flush_len : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_12 10'h030 */
	union {
		uint32_t lr016_12; // word name
		struct {
			uint32_t fifo_flush_len : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_13 10'h034 */
	union {
		uint32_t lr016_13; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LR016_14 10'h038 */
	union {
		uint32_t lr016_14; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ini_addr_word : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR016_15 10'h03C [Unused] */
	uint32_t empty_word_lr016_15;
	/* LR016_16 10'h040 [Unused] */
	uint32_t empty_word_lr016_16;
	/* LR016_17 10'h044 [Unused] */
	uint32_t empty_word_lr016_17;
	/* LR016_18 10'h048 [Unused] */
	uint32_t empty_word_lr016_18;
	/* LR016_19 10'h04C [Unused] */
	uint32_t empty_word_lr016_19;
	/* LR016_20 10'h050 [Unused] */
	uint32_t empty_word_lr016_20;
	/* LR016_21 10'h054 [Unused] */
	uint32_t empty_word_lr016_21;
	/* LR016_22 10'h058 [Unused] */
	uint32_t empty_word_lr016_22;
	/* LR016_23 10'h05C [Unused] */
	uint32_t empty_word_lr016_23;
	/* LR016_24 10'h060 [Unused] */
	uint32_t empty_word_lr016_24;
	/* LR016_25 10'h064 [Unused] */
	uint32_t empty_word_lr016_25;
	/* LR016_26 10'h068 [Unused] */
	uint32_t empty_word_lr016_26;
	/* LR016_27 10'h06C [Unused] */
	uint32_t empty_word_lr016_27;
	/* LR016_28 10'h070 [Unused] */
	uint32_t empty_word_lr016_28;
	/* LR016_29 10'h074 [Unused] */
	uint32_t empty_word_lr016_29;
	/* LR016_30 10'h078 [Unused] */
	uint32_t empty_word_lr016_30;
	/* LR016_31 10'h07C [Unused] */
	uint32_t empty_word_lr016_31;
	/* LR016_32 10'h080 [Unused] */
	uint32_t empty_word_lr016_32;
	/* LR016_33 10'h084 [Unused] */
	uint32_t empty_word_lr016_33;
	/* LR016_34 10'h088 [Unused] */
	uint32_t empty_word_lr016_34;
	/* LR016_35 10'h08C [Unused] */
	uint32_t empty_word_lr016_35;
	/* LR016_36 10'h090 [Unused] */
	uint32_t empty_word_lr016_36;
	/* LR016_37 10'h094 [Unused] */
	uint32_t empty_word_lr016_37;
	/* LR016_38 10'h098 [Unused] */
	uint32_t empty_word_lr016_38;
	/* LR016_39 10'h09C [Unused] */
	uint32_t empty_word_lr016_39;
	/* LR016_40 10'h0A0 */
	union {
		uint32_t lr016_40; // word name
		struct {
			uint32_t ini_addr_linear : 28;
			uint32_t : 4; // padding bits
		};
	};
} CsrBankDosd_read;

#endif