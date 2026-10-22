/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DMIC_H_
#define CSR_BANK_DMIC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dmic  ***/
typedef struct csr_bank_dmic {
	/* AUDIO_DMIC_DR_MODE 16'h0000 */
	union {
		uint32_t audio_dmic_dr_mode; // word name
		struct {
			uint32_t dr_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t dmic_data_case : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_DMIC_DR_MODE_PULSE 16'h0004 */
	union {
		uint32_t audio_dmic_dr_mode_pulse; // word name
		struct {
			uint32_t dr_start : 1;
			uint32_t : 7; // padding bits
			uint32_t dr_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_DMIC_DR_CNT_INI 16'h0008 */
	union {
		uint32_t audio_dmic_dr_cnt_ini; // word name
		struct {
			uint32_t data_valid_time : 10;
			uint32_t : 6; // padding bits
			uint32_t cycle_time_ini : 16;
		};
	};
	/* AUDIO_DMIC_DR_DATA_TRI_TIME 16'h000C */
	union {
		uint32_t audio_dmic_dr_data_tri_time; // word name
		struct {
			uint32_t data_trigger_time_small : 16;
			uint32_t data_trigger_time_large : 16;
		};
	};
	/* AUDIO_DMIC_COMB_GAIN_LSB 16'h0010 */
	union {
		uint32_t audio_dmic_comb_gain_lsb; // word name
		struct {
			uint32_t csr_gain_lsb : 32;
		};
	};
	/* AUDIO_DMIC_COMB_GAIN_MSB 16'h0014 */
	union {
		uint32_t audio_dmic_comb_gain_msb; // word name
		struct {
			uint32_t csr_gain_msb : 32;
		};
	};
	/* AUDIO_DMIC_COMB_DOWN 16'h0018 */
	union {
		uint32_t audio_dmic_comb_down; // word name
		struct {
			uint32_t downsample_rate : 16;
			uint32_t : 8; // padding bits
			uint32_t inverse : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* AUDIO_DMIC_COMB_ATPG 16'h001C */
	union {
		uint32_t audio_dmic_comb_atpg; // word name
		struct {
			uint32_t atpg_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDmic;

#endif