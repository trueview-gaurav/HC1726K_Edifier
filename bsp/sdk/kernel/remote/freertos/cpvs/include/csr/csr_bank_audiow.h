#ifndef CSR_BANK_AUDIOW_H_
#define CSR_BANK_AUDIOW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from audiow  ***/
typedef struct csr_bank_audiow {
	/* LW332_00 10'h000 */
	union {
		uint32_t lw332_00; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t buffer_switch : 1;
			uint32_t : 7; // padding bits
			uint32_t write_end_req : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_01 10'h004 */
	union {
		uint32_t lw332_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_02 10'h008 [Unused] */
	uint32_t empty_word_lw332_02;
	/* LW332_03 10'h00C [Unused] */
	uint32_t empty_word_lw332_03;
	/* LW332_04 10'h010 */
	union {
		uint32_t lw332_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* LW332_05 10'h014 [Unused] */
	uint32_t empty_word_lw332_05;
	/* LW332_06 10'h018 [Unused] */
	uint32_t empty_word_lw332_06;
	/* LW332_07 10'h01C */
	union {
		uint32_t lw332_07; // word name
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
	/* LW332_08 10'h020 */
	union {
		uint32_t lw332_08; // word name
		struct {
			uint32_t target_fifo_level : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_09 10'h024 */
	union {
		uint32_t lw332_09; // word name
		struct {
			uint32_t access_length : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_10 10'h028 */
	union {
		uint32_t lw332_10; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW332_11 10'h02C */
	union {
		uint32_t lw332_11; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW332_12 10'h030 [Unused] */
	uint32_t empty_word_lw332_12;
	/* LW332_13 10'h034 */
	union {
		uint32_t lw332_13; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LW332_14 10'h038 */
	union {
		uint32_t lw332_14; // word name
		struct {
			uint32_t ini_addr_linear : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW332_15 10'h03C */
	union {
		uint32_t lw332_15; // word name
		struct {
			uint32_t sample_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_16 10'h040 */
	union {
		uint32_t lw332_16; // word name
		struct {
			uint32_t time_stamp_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_buffer_full_pulse_avail : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_17 10'h044 */
	union {
		uint32_t lw332_17; // word name
		struct {
			uint32_t sample_target : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_18 10'h048 */
	union {
		uint32_t lw332_18; // word name
		struct {
			uint32_t capture_time_stamp : 32;
		};
	};
	/* LW332_19 10'h04C */
	union {
		uint32_t lw332_19; // word name
		struct {
			uint32_t irq_mask_buffer_full_pulse_avail : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_20 10'h050 */
	union {
		uint32_t lw332_20; // word name
		struct {
			uint32_t status_buffer_full_pulse_avail : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_21 10'h054 */
	union {
		uint32_t lw332_21; // word name
		struct {
			uint32_t scaler_factor : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_22 10'h058 */
	union {
		uint32_t lw332_22; // word name
		struct {
			uint32_t capture_time_stamp_last : 32;
		};
	};
	/* LW332_23 10'h05C */
	union {
		uint32_t lw332_23; // word name
		struct {
			uint32_t time_stamp_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_24 10'h060 */
	union {
		uint32_t lw332_24; // word name
		struct {
			uint32_t time_stamp_clear_value : 32;
		};
	};
	/* LW332_25 10'h064 */
	union {
		uint32_t lw332_25; // word name
		struct {
			uint32_t capture_sample_cnt : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_26 10'h068 */
	union {
		uint32_t lw332_26; // word name
		struct {
			uint32_t irq_clear_fifo_empty : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_27 10'h06C */
	union {
		uint32_t lw332_27; // word name
		struct {
			uint32_t status_fifo_empty : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW332_28 10'h070 */
	union {
		uint32_t lw332_28; // word name
		struct {
			uint32_t irq_mask_fifo_empty : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAudiow;

#endif