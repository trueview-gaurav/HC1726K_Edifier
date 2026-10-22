/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ADCCTR_H_
#define CSR_BANK_ADCCTR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adcctr  ***/
typedef struct csr_bank_adcctr {
	/* ADC00 10'h000 */
	union {
		uint32_t adc00; // word name
		struct {
			uint32_t adc_clk_start : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_clk_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_start : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_stop : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC01 10'h004 */
	union {
		uint32_t adc01; // word name
		struct {
			uint32_t env_query_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t env_query_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t env_query_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t env_query_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC02 10'h008 */
	union {
		uint32_t adc02; // word name
		struct {
			uint32_t env_query_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t env_query_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t env_init : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC03 10'h00C */
	union {
		uint32_t adc03; // word name
		struct {
			uint32_t init_phy_reset_en : 16;
			uint32_t init_phy_soc_en : 8;
			uint32_t phy_serial_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC04 10'h010 */
	union {
		uint32_t adc04; // word name
		struct {
			uint32_t clk_0_cycle : 8;
			uint32_t : 8; // padding bits
			uint32_t clk_1_cycle : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* ADC05 10'h014 */
	union {
		uint32_t adc05; // word name
		struct {
			uint32_t length : 8;
			uint32_t : 8; // padding bits
			uint32_t latency : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* ADC06 10'h018 */
	union {
		uint32_t adc06; // word name
		struct {
			uint32_t ch_0_type : 1;
			uint32_t : 7; // padding bits
			uint32_t ch_1_type : 1;
			uint32_t : 7; // padding bits
			uint32_t ch_2_type : 1;
			uint32_t : 7; // padding bits
			uint32_t ch_3_type : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC07 10'h01C */
	union {
		uint32_t adc07; // word name
		struct {
			uint32_t ch_4_type : 1;
			uint32_t : 7; // padding bits
			uint32_t ch_5_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC08 10'h020 [Unused] */
	uint32_t empty_word_adc08;
	/* ADC09 10'h024 */
	union {
		uint32_t adc09; // word name
		struct {
			uint32_t ch_num : 5;
			uint32_t : 3; // padding bits
			uint32_t adc_format : 1;
			uint32_t : 7; // padding bits
			uint32_t audio_lsb_repeat : 1;
			uint32_t : 7; // padding bits
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* ADC10 10'h028 */
	union {
		uint32_t adc10; // word name
		struct {
			uint32_t adc_selres_reg : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC11 10'h02C */
	union {
		uint32_t adc11; // word name
		struct {
			uint32_t mute : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC12 10'h030 */
	union {
		uint32_t adc12; // word name
		struct {
			uint32_t env_data_0 : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC13 10'h034 */
	union {
		uint32_t adc13; // word name
		struct {
			uint32_t env_data_1 : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC14 10'h038 */
	union {
		uint32_t adc14; // word name
		struct {
			uint32_t env_data_2 : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC15 10'h03C */
	union {
		uint32_t adc15; // word name
		struct {
			uint32_t env_data_3 : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC16 10'h040 */
	union {
		uint32_t adc16; // word name
		struct {
			uint32_t env_data_4 : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC17 10'h044 */
	union {
		uint32_t adc17; // word name
		struct {
			uint32_t env_data_5 : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC18 10'h048 */
	union {
		uint32_t adc18; // word name
		struct {
			uint32_t adc_b_reg : 12;
			uint32_t : 4; // padding bits
			uint32_t adc_eoc_reg : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC19 10'h04C */
	union {
		uint32_t adc19; // word name
		struct {
			uint32_t virtual_ch_cnt : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC20 10'h050 */
	union {
		uint32_t adc20; // word name
		struct {
			uint32_t virtual_ch_0_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_0_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_0_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_0_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC21 10'h054 */
	union {
		uint32_t adc21; // word name
		struct {
			uint32_t virtual_ch_1_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_1_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_1_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_1_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC22 10'h058 */
	union {
		uint32_t adc22; // word name
		struct {
			uint32_t virtual_ch_2_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_2_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_2_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_2_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC23 10'h05C */
	union {
		uint32_t adc23; // word name
		struct {
			uint32_t virtual_ch_3_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_3_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_3_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_3_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC24 10'h060 */
	union {
		uint32_t adc24; // word name
		struct {
			uint32_t virtual_ch_4_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_4_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_4_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_4_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC25 10'h064 */
	union {
		uint32_t adc25; // word name
		struct {
			uint32_t virtual_ch_5_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_5_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_5_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_5_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC26 10'h068 */
	union {
		uint32_t adc26; // word name
		struct {
			uint32_t virtual_ch_6_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_6_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_6_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_6_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC27 10'h06C */
	union {
		uint32_t adc27; // word name
		struct {
			uint32_t virtual_ch_7_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_7_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_7_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_7_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC28 10'h070 */
	union {
		uint32_t adc28; // word name
		struct {
			uint32_t virtual_ch_8_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_8_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_8_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_8_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC29 10'h074 */
	union {
		uint32_t adc29; // word name
		struct {
			uint32_t virtual_ch_9_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_9_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_9_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_9_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC30 10'h078 */
	union {
		uint32_t adc30; // word name
		struct {
			uint32_t virtual_ch_a_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_a_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_a_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_a_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC31 10'h07C */
	union {
		uint32_t adc31; // word name
		struct {
			uint32_t virtual_ch_b_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_b_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_b_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_b_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC32 10'h080 */
	union {
		uint32_t adc32; // word name
		struct {
			uint32_t virtual_ch_c_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_c_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_c_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_c_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC33 10'h084 */
	union {
		uint32_t adc33; // word name
		struct {
			uint32_t virtual_ch_d_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_d_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_d_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_d_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC34 10'h088 */
	union {
		uint32_t adc34; // word name
		struct {
			uint32_t virtual_ch_e_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_e_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_e_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_e_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC35 10'h08C */
	union {
		uint32_t adc35; // word name
		struct {
			uint32_t virtual_ch_f_num : 3;
			uint32_t : 5; // padding bits
			uint32_t virtual_ch_f_seldiff : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_f_selref : 1;
			uint32_t : 7; // padding bits
			uint32_t virtual_ch_f_selbg : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC36 10'h090 */
	union {
		uint32_t adc36; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankAdcctr;

#endif