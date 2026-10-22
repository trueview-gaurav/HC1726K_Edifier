/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_I2S_H_
#define CSR_BANK_I2S_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from i2s  ***/
typedef struct csr_bank_i2s {
	/* SWITCH 16'h0000 */
	union {
		uint32_t _switch; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* INTERCLK 16'h0004 */
	union {
		uint32_t interclk; // word name
		struct {
			uint32_t sd_format : 1;
			uint32_t : 7; // padding bits
			uint32_t master_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t use_sck_inter : 1;
			uint32_t : 7; // padding bits
			uint32_t use_ws_inter : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* OUT_EN 16'h0008 */
	union {
		uint32_t out_en; // word name
		struct {
			uint32_t output_sck_inter : 1;
			uint32_t : 7; // padding bits
			uint32_t output_ws_inter : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CYCLE_DEF 16'h000C */
	union {
		uint32_t cycle_def; // word name
		struct {
			uint32_t master_sck_0_cycle : 8;
			uint32_t : 8; // padding bits
			uint32_t master_sck_1_cycle : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* CYCLE_CNT 16'h0010 */
	union {
		uint32_t cycle_cnt; // word name
		struct {
			uint32_t master_ws_len : 9;
			uint32_t master_sd_len : 9;
			uint32_t tx_data_len : 6;
			uint32_t : 8; // padding bits
		};
	};
	/* DEG 16'h0014 */
	union {
		uint32_t deg; // word name
		struct {
			uint32_t sck_deglitch_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ws_deglitch_en : 1;
			uint32_t : 7; // padding bits
			uint32_t sd_deglitch_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEG_BY 16'h0018 */
	union {
		uint32_t deg_by; // word name
		struct {
			uint32_t sck_deglitch_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t ws_deglitch_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t sd_deglitch_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEG_TH 16'h001C */
	union {
		uint32_t deg_th; // word name
		struct {
			uint32_t sck_deglitch_th : 6;
			uint32_t : 2; // padding bits
			uint32_t ws_deglitch_th : 6;
			uint32_t : 2; // padding bits
			uint32_t sd_deglitch_th : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG 16'h0020 */
	union {
		uint32_t debug; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t mute : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV 16'h0024 */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankI2s;

#endif
