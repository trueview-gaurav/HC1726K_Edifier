#ifndef CSR_BANK_OSDR_H_
#define CSR_BANK_OSDR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from osdr  ***/
typedef struct csr_bank_osdr {
	/* LR064_00 10'h000 */
	union {
		uint32_t lr064_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR064_01 10'h004 */
	union {
		uint32_t lr064_01; // word name
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
	/* LR064_02 10'h008 */
	union {
		uint32_t lr064_02; // word name
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
	/* LR064_03 10'h00C */
	union {
		uint32_t lr064_03; // word name
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
	/* LR064_04 10'h010 */
	union {
		uint32_t lr064_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LR064_05 10'h014 [Unused] */
	uint32_t empty_word_lr064_05;
	/* LR064_06 10'h018 */
	union {
		uint32_t lr064_06; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR064_07 10'h01C */
	union {
		uint32_t lr064_07; // word name
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
	/* LR064_08 10'h020 */
	union {
		uint32_t lr064_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR064_09 10'h024 */
	union {
		uint32_t lr064_09; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR064_10 10'h028 */
	union {
		uint32_t lr064_10; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR064_11 10'h02C */
	union {
		uint32_t lr064_11; // word name
		struct {
			uint32_t pixel_flush_len : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR064_12 10'h030 */
	union {
		uint32_t lr064_12; // word name
		struct {
			uint32_t fifo_flush_len : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR064_13 10'h034 */
	union {
		uint32_t lr064_13; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LR064_14 10'h038 */
	union {
		uint32_t lr064_14; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ini_addr_word : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR064_15 10'h03C [Unused] */
	uint32_t empty_word_lr064_15;
	/* LR064_16 10'h040 [Unused] */
	uint32_t empty_word_lr064_16;
	/* LR064_17 10'h044 [Unused] */
	uint32_t empty_word_lr064_17;
	/* LR064_18 10'h048 [Unused] */
	uint32_t empty_word_lr064_18;
	/* LR064_19 10'h04C [Unused] */
	uint32_t empty_word_lr064_19;
	/* LR064_20 10'h050 [Unused] */
	uint32_t empty_word_lr064_20;
	/* LR064_21 10'h054 [Unused] */
	uint32_t empty_word_lr064_21;
	/* LR064_22 10'h058 [Unused] */
	uint32_t empty_word_lr064_22;
	/* LR064_23 10'h05C [Unused] */
	uint32_t empty_word_lr064_23;
	/* LR064_24 10'h060 [Unused] */
	uint32_t empty_word_lr064_24;
	/* LR064_25 10'h064 [Unused] */
	uint32_t empty_word_lr064_25;
	/* LR064_26 10'h068 [Unused] */
	uint32_t empty_word_lr064_26;
	/* LR064_27 10'h06C [Unused] */
	uint32_t empty_word_lr064_27;
	/* LR064_28 10'h070 [Unused] */
	uint32_t empty_word_lr064_28;
	/* LR064_29 10'h074 [Unused] */
	uint32_t empty_word_lr064_29;
	/* LR064_30 10'h078 [Unused] */
	uint32_t empty_word_lr064_30;
	/* LR064_31 10'h07C [Unused] */
	uint32_t empty_word_lr064_31;
	/* LR064_32 10'h080 [Unused] */
	uint32_t empty_word_lr064_32;
	/* LR064_33 10'h084 [Unused] */
	uint32_t empty_word_lr064_33;
	/* LR064_34 10'h088 [Unused] */
	uint32_t empty_word_lr064_34;
	/* LR064_35 10'h08C [Unused] */
	uint32_t empty_word_lr064_35;
	/* LR064_36 10'h090 [Unused] */
	uint32_t empty_word_lr064_36;
	/* LR064_37 10'h094 [Unused] */
	uint32_t empty_word_lr064_37;
	/* LR064_38 10'h098 [Unused] */
	uint32_t empty_word_lr064_38;
	/* LR064_39 10'h09C [Unused] */
	uint32_t empty_word_lr064_39;
	/* LR064_40 10'h0A0 */
	union {
		uint32_t lr064_40; // word name
		struct {
			uint32_t ini_addr_linear : 28;
			uint32_t : 4; // padding bits
		};
	};
} CsrBankOsdr;

#endif