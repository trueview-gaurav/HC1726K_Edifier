/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ADODAC_H_
#define CSR_BANK_ADODAC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adodac  ***/
typedef struct csr_bank_adodac {
	/* SINE_GEN_DIV 10'h000 */
	union {
		uint32_t sine_gen_div; // word name
		struct {
			uint32_t pos_cnt_num_m1 : 10;
			uint32_t : 6; // padding bits
			uint32_t neg_cnt_num_m1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* SINE_GEN_PULSE 10'h004 */
	union {
		uint32_t sine_gen_pulse; // word name
		struct {
			uint32_t sine_gen_start : 1;
			uint32_t : 7; // padding bits
			uint32_t sine_gen_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SINE_GEN_MODE 10'h008 */
	union {
		uint32_t sine_gen_mode; // word name
		struct {
			uint32_t sine_gen_fin : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SDM_PULSE 10'h00C */
	union {
		uint32_t sdm_pulse; // word name
		struct {
			uint32_t sdm_start : 1;
			uint32_t : 7; // padding bits
			uint32_t sdm_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SDM_KERNEL 10'h010 */
	union {
		uint32_t sdm_kernel; // word name
		struct {
			uint32_t sdm_up_sample_rate : 16;
			uint32_t sdm_input_bw : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DAC_EN 10'h014 */
	union {
		uint32_t dac_en; // word name
		struct {
			uint32_t rg_adac_din : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_adac_vref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_adac_dac_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_adac_clk_inv_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DAC_VREF_FS 10'h018 */
	union {
		uint32_t dac_vref_fs; // word name
		struct {
			uint32_t rg_adac_vref_fs : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG 10'h01C */
	union {
		uint32_t debug; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_adac_reserved : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdodac;

#endif