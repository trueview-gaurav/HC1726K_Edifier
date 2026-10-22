/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_AMIC_H_
#define CSR_BANK_AMIC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from amic  ***/
typedef struct csr_bank_amic {
	/* AUDIO_AGC_MODE 16'h0000 */
	union {
		uint32_t audio_agc_mode; // word name
		struct {
			uint32_t auto_gain_control_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t noise_suppress_en : 1;
			uint32_t : 7; // padding bits
			uint32_t agc_digital_gain_en : 1;
			uint32_t : 7; // padding bits
			uint32_t delay_compensate_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* AUDIO_AGC_SW_CONTROL 16'h0004 */
	union {
		uint32_t audio_agc_sw_control; // word name
		struct {
			uint32_t sw_agc_analog_gain_index : 3;
			uint32_t : 5; // padding bits
			uint32_t sw_agc_digital_gain : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_CONTROL_GAIN 16'h0008 */
	union {
		uint32_t audio_agc_control_gain; // word name
		struct {
			uint32_t control_digital_gain : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_INDEX 16'h000C */
	union {
		uint32_t audio_agc_index; // word name
		struct {
			uint32_t gain_medium_bw : 4;
			uint32_t : 4; // padding bits
			uint32_t agc_gain_high_index : 3;
			uint32_t : 5; // padding bits
			uint32_t agc_gain_medium_index : 3;
			uint32_t : 5; // padding bits
			uint32_t agc_gain_low_index : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* AUDIO_AGC_HOLD_TIME 16'h0010 */
	union {
		uint32_t audio_agc_hold_time; // word name
		struct {
			uint32_t hold_time : 11;
			uint32_t : 5; // padding bits
			uint32_t noise_hold_time_increase : 5;
			uint32_t : 3; // padding bits
			uint32_t noise_hold_time_decrease : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* AUDIO_AGC_GAIN_STEP 16'h0014 */
	union {
		uint32_t audio_agc_gain_step; // word name
		struct {
			uint32_t digital_gain_step_upward : 8;
			uint32_t digital_gain_step_downward : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_ATTACK_STEP 16'h0018 */
	union {
		uint32_t audio_agc_attack_step; // word name
		struct {
			uint32_t attack_step : 9;
			uint32_t : 7; // padding bits
			uint32_t release_step : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* AUDIO_AGC_DETECT_TH_0 16'h001C */
	union {
		uint32_t audio_agc_detect_th_0; // word name
		struct {
			uint32_t zero_crossing_number_th : 10;
			uint32_t : 6; // padding bits
			uint32_t overflow_number_th : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* AUDIO_AGC_DETECT_TH_1 16'h0020 */
	union {
		uint32_t audio_agc_detect_th_1; // word name
		struct {
			uint32_t overflow_th : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_SIGNAL_TH_0 16'h0024 */
	union {
		uint32_t audio_agc_signal_th_0; // word name
		struct {
			uint32_t signal_high_th : 15;
			uint32_t : 1; // padding bits
			uint32_t signal_medium_th : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* AUDIO_AGC_SIGNAL_TH_1 16'h0028 */
	union {
		uint32_t audio_agc_signal_th_1; // word name
		struct {
			uint32_t signal_low_th : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_HPF_0 16'h002C */
	union {
		uint32_t audio_agc_hpf_0; // word name
		struct {
			uint32_t coeff_forward : 16;
			uint32_t coeff_delay : 16;
		};
	};
	/* AUDIO_AGC_HPF_1 16'h0030 */
	union {
		uint32_t audio_agc_hpf_1; // word name
		struct {
			uint32_t coeff_feedback : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_DELAY 16'h0034 */
	union {
		uint32_t audio_agc_delay; // word name
		struct {
			uint32_t agc_sample_delay : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* COMB_GAIN 16'h0038 */
	union {
		uint32_t comb_gain; // word name
		struct {
			uint32_t csr_gain : 32;
		};
	};
	/* COMB_DOWN 16'h003C */
	union {
		uint32_t comb_down; // word name
		struct {
			uint32_t downsample_rate : 16;
			uint32_t : 8; // padding bits
			uint32_t inverse : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DEBUG_SEL 16'h0040 */
	union {
		uint32_t debug_sel; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_ATPG 16'h0044 */
	union {
		uint32_t audio_agc_atpg; // word name
		struct {
			uint32_t atpg_ctrl : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAmic;

#endif