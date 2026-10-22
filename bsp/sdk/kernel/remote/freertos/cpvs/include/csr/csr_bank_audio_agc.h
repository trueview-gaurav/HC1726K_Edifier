#ifndef CSR_BANK_AUDIO_AGC_H_
#define CSR_BANK_AUDIO_AGC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from audio_agc  ***/
typedef struct csr_bank_audio_agc {
	/* AUDIO_HPF_B0 16'h0000 */
	union {
		uint32_t audio_hpf_b0; // word name
		struct {
			uint32_t hpf_b0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_HPF_B1 16'h0004 */
	union {
		uint32_t audio_hpf_b1; // word name
		struct {
			uint32_t hpf_b1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_HPF_A 16'h0008 */
	union {
		uint32_t audio_hpf_a; // word name
		struct {
			uint32_t hpf_a : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_PD 16'h000C */
	union {
		uint32_t audio_pd; // word name
		struct {
			uint32_t pd_th : 7;
			uint32_t : 1; // padding bits
			uint32_t pd_filtered_alpha : 6;
			uint32_t : 2; // padding bits
			uint32_t pd_env_alpha : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* AUDIO_AGC_MODE 16'h0010 */
	union {
		uint32_t audio_agc_mode; // word name
		struct {
			uint32_t agc_gain_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t pre_amp_mod : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_BOND0 16'h0014 */
	union {
		uint32_t audio_agc_bond0; // word name
		struct {
			uint32_t agc_upper_bond : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_BOND1 16'h0018 */
	union {
		uint32_t audio_agc_bond1; // word name
		struct {
			uint32_t agc_lower_bond : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_BOND2 16'h001C */
	union {
		uint32_t audio_agc_bond2; // word name
		struct {
			uint32_t agc_noise_gate : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AGC_GAIN_H 16'h0020 */
	union {
		uint32_t agc_gain_h; // word name
		struct {
			uint32_t agc_gain_h_v : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AGC_GAIN_L 16'h0024 */
	union {
		uint32_t agc_gain_l; // word name
		struct {
			uint32_t agc_gain_l_v : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AGC_GAIN_LL 16'h0028 */
	union {
		uint32_t agc_gain_ll; // word name
		struct {
			uint32_t agc_gain_ll_v : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ANA_AGC_GAIN_H 16'h002C */
	union {
		uint32_t ana_agc_gain_h; // word name
		struct {
			uint32_t agc_analog_gain_delta_h : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ANA_AGC_GAIN_L 16'h0030 */
	union {
		uint32_t ana_agc_gain_l; // word name
		struct {
			uint32_t agc_analog_gain_delta_l : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ANA_AGC_GAIN_LL 16'h0034 */
	union {
		uint32_t ana_agc_gain_ll; // word name
		struct {
			uint32_t agc_analog_gain_delta_ll : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DOUBLE_BUF_UPDATE 16'h0038 */
	union {
		uint32_t word_double_buf_update; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_CURVE_0 16'h003C */
	union {
		uint32_t gain_curve_0; // word name
		struct {
			uint32_t gain_0 : 8;
			uint32_t gain_1 : 8;
			uint32_t gain_2 : 8;
			uint32_t gain_3 : 8;
		};
	};
	/* GAIN_CURVE_1 16'h0040 */
	union {
		uint32_t gain_curve_1; // word name
		struct {
			uint32_t gain_4 : 8;
			uint32_t gain_5 : 8;
			uint32_t gain_6 : 8;
			uint32_t gain_7 : 8;
		};
	};
	/* GAIN_CURVE_2 16'h0044 */
	union {
		uint32_t gain_curve_2; // word name
		struct {
			uint32_t gain_8 : 8;
			uint32_t gain_9 : 8;
			uint32_t gain_10 : 8;
			uint32_t gain_11 : 8;
		};
	};
	/* GAIN_CURVE_3 16'h0048 */
	union {
		uint32_t gain_curve_3; // word name
		struct {
			uint32_t gain_12 : 8;
			uint32_t gain_13 : 8;
			uint32_t gain_14 : 8;
			uint32_t gain_15 : 8;
		};
	};
	/* GAIN_CURVE_4 16'h004C */
	union {
		uint32_t gain_curve_4; // word name
		struct {
			uint32_t gain_16 : 8;
			uint32_t gain_17 : 8;
			uint32_t gain_18 : 8;
			uint32_t gain_19 : 8;
		};
	};
	/* GAIN_CURVE_5 16'h0050 */
	union {
		uint32_t gain_curve_5; // word name
		struct {
			uint32_t gain_20 : 8;
			uint32_t gain_21 : 8;
			uint32_t gain_22 : 8;
			uint32_t gain_23 : 8;
		};
	};
	/* GAIN_CURVE_6 16'h0054 */
	union {
		uint32_t gain_curve_6; // word name
		struct {
			uint32_t gain_24 : 8;
			uint32_t gain_25 : 8;
			uint32_t gain_26 : 8;
			uint32_t gain_27 : 8;
		};
	};
	/* GAIN_CURVE_7 16'h0058 */
	union {
		uint32_t gain_curve_7; // word name
		struct {
			uint32_t gain_28 : 8;
			uint32_t gain_29 : 8;
			uint32_t gain_30 : 8;
			uint32_t gain_31 : 8;
		};
	};
	/* GAIN_CURVE_8 16'h005C */
	union {
		uint32_t gain_curve_8; // word name
		struct {
			uint32_t gain_32 : 8;
			uint32_t gain_33 : 8;
			uint32_t gain_34 : 8;
			uint32_t gain_35 : 8;
		};
	};
	/* GAIN_CURVE_9 16'h0060 */
	union {
		uint32_t gain_curve_9; // word name
		struct {
			uint32_t gain_36 : 8;
			uint32_t gain_37 : 8;
			uint32_t gain_38 : 8;
			uint32_t gain_39 : 8;
		};
	};
	/* GAIN_CURVE_10 16'h0064 */
	union {
		uint32_t gain_curve_10; // word name
		struct {
			uint32_t gain_40 : 8;
			uint32_t gain_41 : 8;
			uint32_t gain_42 : 8;
			uint32_t gain_43 : 8;
		};
	};
	/* GAIN_CURVE_11 16'h0068 */
	union {
		uint32_t gain_curve_11; // word name
		struct {
			uint32_t gain_44 : 8;
			uint32_t gain_45 : 8;
			uint32_t gain_46 : 8;
			uint32_t gain_47 : 8;
		};
	};
	/* GAIN_CURVE_12 16'h006C */
	union {
		uint32_t gain_curve_12; // word name
		struct {
			uint32_t gain_48 : 8;
			uint32_t gain_49 : 8;
			uint32_t gain_50 : 8;
			uint32_t gain_51 : 8;
		};
	};
	/* GAIN_CURVE_13 16'h0070 */
	union {
		uint32_t gain_curve_13; // word name
		struct {
			uint32_t gain_52 : 8;
			uint32_t gain_53 : 8;
			uint32_t gain_54 : 8;
			uint32_t gain_55 : 8;
		};
	};
	/* GAIN_CURVE_14 16'h0074 */
	union {
		uint32_t gain_curve_14; // word name
		struct {
			uint32_t gain_56 : 8;
			uint32_t gain_57 : 8;
			uint32_t gain_58 : 8;
			uint32_t gain_59 : 8;
		};
	};
	/* GAIN_CURVE_15 16'h0078 */
	union {
		uint32_t gain_curve_15; // word name
		struct {
			uint32_t gain_60 : 8;
			uint32_t gain_61 : 8;
			uint32_t gain_62 : 8;
			uint32_t gain_63 : 8;
		};
	};
} CsrBankAudio_agc;

#endif