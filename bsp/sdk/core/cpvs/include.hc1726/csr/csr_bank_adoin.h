/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ADOIN_H_
#define CSR_BANK_ADOIN_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adoin  ***/
typedef struct csr_bank_adoin {
	/* ADOIN_I2S_IRQ_CLEAR 10'h000 */
	union {
		uint32_t adoin_i2s_irq_clear; // word name
		struct {
			uint32_t i2s_irq_clear_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_irq_clear_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN_I2S_STATUS 10'h004 */
	union {
		uint32_t adoin_i2s_status; // word name
		struct {
			uint32_t i2s_status_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_status_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN_I2S_IRQ_MASK 10'h008 */
	union {
		uint32_t adoin_i2s_irq_mask; // word name
		struct {
			uint32_t i2s_irq_mask_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_irq_mask_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN_ADC_BIST_CNT_L 10'h00C */
	union {
		uint32_t adoin_adc_bist_cnt_l; // word name
		struct {
			uint32_t adc_status_env_de_l : 10;
			uint32_t : 6; // padding bits
			uint32_t aadc_bist_l : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN_ADC_BIST_CNT_R 10'h010 */
	union {
		uint32_t adoin_adc_bist_cnt_r; // word name
		struct {
			uint32_t adc_status_env_de_r : 10;
			uint32_t : 6; // padding bits
			uint32_t aadc_bist_r : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN_ADC_BIST_MAX_MIN 10'h014 */
	union {
		uint32_t adoin_adc_bist_max_min; // word name
		struct {
			uint32_t bist_max : 10;
			uint32_t : 6; // padding bits
			uint32_t bist_min : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ADOIN_ADC_BIST_START 10'h018 */
	union {
		uint32_t adoin_adc_bist_start; // word name
		struct {
			uint32_t aadc_bist_start_l : 1;
			uint32_t : 7; // padding bits
			uint32_t aadc_bist_start_r : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN_DEBUG_MON_SEL 10'h01C */
	union {
		uint32_t adoin_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN_DEBUG_MON 10'h020 */
	union {
		uint32_t adoin_debug_mon; // word name
		struct {
			uint32_t debug_mon_reg : 32;
		};
	};
	/* ADOIN_MEM 10'h024 */
	union {
		uint32_t adoin_mem; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN_RESERVED 10'h028 */
	union {
		uint32_t adoin_reserved; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* AUDIO_SWAP_EN 10'h02C */
	union {
		uint32_t audio_swap_en; // word name
		struct {
			uint32_t audio_ch_en : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_SWAP_SAMPLE 10'h030 */
	union {
		uint32_t audio_swap_sample; // word name
		struct {
			uint32_t sample_number : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_SWAP_CH_MUX_0 10'h034 */
	union {
		uint32_t audio_swap_ch_mux_0; // word name
		struct {
			uint32_t ch_mux_time_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t ch_mux_time_2 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* AUDIO_SWAP_CH_MUX_1 10'h038 */
	union {
		uint32_t audio_swap_ch_mux_1; // word name
		struct {
			uint32_t ch_mux_time_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_SWAP_DATA_TRIGR 10'h03C */
	union {
		uint32_t audio_swap_data_trigr; // word name
		struct {
			uint32_t data_trigger_time : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_PACKER_I2S_MODE 10'h040 */
	union {
		uint32_t audio_packer_i2s_mode; // word name
		struct {
			uint32_t i2s_ch_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t i2s_16bw : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_PACKER_DATA_CNT 10'h044 */
	union {
		uint32_t audio_packer_data_cnt; // word name
		struct {
			uint32_t data_cnt_start : 1;
			uint32_t : 7; // padding bits
			uint32_t data_cnt_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_DMIC_CLK_DIV 10'h048 */
	union {
		uint32_t audio_dmic_clk_div; // word name
		struct {
			uint32_t div_num : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_LINER_WRITE 10'h04C */
	union {
		uint32_t audio_liner_write; // word name
		struct {
			uint32_t frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_AGC_ANALOG_GAIN_READ_0 10'h050 */
	union {
		uint32_t audio_agc_analog_gain_read_0; // word name
		struct {
			uint32_t analog_gain_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* AUDIO_AGC_ANALOG_GAIN_READ_1 10'h054 */
	union {
		uint32_t audio_agc_analog_gain_read_1; // word name
		struct {
			uint32_t analog_gain_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* AUDIO_AGC_ANALOG_GAIN_READ_2 10'h058 */
	union {
		uint32_t audio_agc_analog_gain_read_2; // word name
		struct {
			uint32_t analog_gain_8 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_9 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_10 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* AUDIO_AGC_ANALOG_GAIN_READ_3 10'h05C */
	union {
		uint32_t audio_agc_analog_gain_read_3; // word name
		struct {
			uint32_t analog_gain_12 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_13 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_14 : 3;
			uint32_t : 5; // padding bits
			uint32_t analog_gain_15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* AUDIO_AGC_DIGITAL_GAIN_READ_0 10'h060 */
	union {
		uint32_t audio_agc_digital_gain_read_0; // word name
		struct {
			uint32_t digital_gain_0 : 12;
			uint32_t : 4; // padding bits
			uint32_t digital_gain_1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DIGITAL_GAIN_READ_1 10'h064 */
	union {
		uint32_t audio_agc_digital_gain_read_1; // word name
		struct {
			uint32_t digital_gain_2 : 12;
			uint32_t : 4; // padding bits
			uint32_t digital_gain_3 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DIGITAL_GAIN_READ_2 10'h068 */
	union {
		uint32_t audio_agc_digital_gain_read_2; // word name
		struct {
			uint32_t digital_gain_4 : 12;
			uint32_t : 4; // padding bits
			uint32_t digital_gain_5 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DIGITAL_GAIN_READ_3 10'h06C */
	union {
		uint32_t audio_agc_digital_gain_read_3; // word name
		struct {
			uint32_t digital_gain_6 : 12;
			uint32_t : 4; // padding bits
			uint32_t digital_gain_7 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DIGITAL_GAIN_READ_4 10'h070 */
	union {
		uint32_t audio_agc_digital_gain_read_4; // word name
		struct {
			uint32_t digital_gain_8 : 12;
			uint32_t : 4; // padding bits
			uint32_t digital_gain_9 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DIGITAL_GAIN_READ_5 10'h074 */
	union {
		uint32_t audio_agc_digital_gain_read_5; // word name
		struct {
			uint32_t digital_gain_10 : 12;
			uint32_t : 4; // padding bits
			uint32_t digital_gain_11 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DIGITAL_GAIN_READ_6 10'h078 */
	union {
		uint32_t audio_agc_digital_gain_read_6; // word name
		struct {
			uint32_t digital_gain_12 : 12;
			uint32_t : 4; // padding bits
			uint32_t digital_gain_13 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DIGITAL_GAIN_READ_7 10'h07C */
	union {
		uint32_t audio_agc_digital_gain_read_7; // word name
		struct {
			uint32_t digital_gain_14 : 12;
			uint32_t : 4; // padding bits
			uint32_t digital_gain_15 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_0 10'h080 */
	union {
		uint32_t audio_agc_data_cnt_read_0; // word name
		struct {
			uint32_t data_cnt_0 : 12;
			uint32_t : 4; // padding bits
			uint32_t data_cnt_1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_1 10'h084 */
	union {
		uint32_t audio_agc_data_cnt_read_1; // word name
		struct {
			uint32_t data_cnt_2 : 12;
			uint32_t : 4; // padding bits
			uint32_t data_cnt_3 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_2 10'h088 */
	union {
		uint32_t audio_agc_data_cnt_read_2; // word name
		struct {
			uint32_t data_cnt_4 : 12;
			uint32_t : 4; // padding bits
			uint32_t data_cnt_5 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_3 10'h08C */
	union {
		uint32_t audio_agc_data_cnt_read_3; // word name
		struct {
			uint32_t data_cnt_6 : 12;
			uint32_t : 4; // padding bits
			uint32_t data_cnt_7 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_4 10'h090 */
	union {
		uint32_t audio_agc_data_cnt_read_4; // word name
		struct {
			uint32_t data_cnt_8 : 12;
			uint32_t : 4; // padding bits
			uint32_t data_cnt_9 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_5 10'h094 */
	union {
		uint32_t audio_agc_data_cnt_read_5; // word name
		struct {
			uint32_t data_cnt_10 : 12;
			uint32_t : 4; // padding bits
			uint32_t data_cnt_11 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_6 10'h098 */
	union {
		uint32_t audio_agc_data_cnt_read_6; // word name
		struct {
			uint32_t data_cnt_12 : 12;
			uint32_t : 4; // padding bits
			uint32_t data_cnt_13 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_7 10'h09C */
	union {
		uint32_t audio_agc_data_cnt_read_7; // word name
		struct {
			uint32_t data_cnt_14 : 12;
			uint32_t : 4; // padding bits
			uint32_t data_cnt_15 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* AUDIO_AGC_DATA_CNT_READ_8 10'h0A0 [Unused] */
	uint32_t empty_word_audio_agc_data_cnt_read_8;
	/* AUDIO_AGC_DATA_CNT_READ_9 10'h0A4 [Unused] */
	uint32_t empty_word_audio_agc_data_cnt_read_9;
	/* AUDIO_AGC_DATA_CNT_READ_10 10'h0A8 [Unused] */
	uint32_t empty_word_audio_agc_data_cnt_read_10;
	/* AUDIO_AGC_DATA_CNT_READ_11 10'h0AC [Unused] */
	uint32_t empty_word_audio_agc_data_cnt_read_11;
	/* AUDIO_AGC_DATA_CNT_READ_12 10'h0B0 [Unused] */
	uint32_t empty_word_audio_agc_data_cnt_read_12;
	/* AUDIO_AGC_DATA_CNT_READ_13 10'h0B4 [Unused] */
	uint32_t empty_word_audio_agc_data_cnt_read_13;
	/* AUDIO_AGC_DATA_CNT_READ_14 10'h0B8 [Unused] */
	uint32_t empty_word_audio_agc_data_cnt_read_14;
	/* AUDIO_AGC_DATA_CNT_READ_15 10'h0BC [Unused] */
	uint32_t empty_word_audio_agc_data_cnt_read_15;
	/* AUDIO_GAIN_2_CSR 10'h0C0 */
	union {
		uint32_t audio_gain_2_csr; // word name
		struct {
			uint32_t amic_ch_num : 2;
			uint32_t : 6; // padding bits
			uint32_t sample_rate_osr : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_GAIN_2_CSR_AGC_INFO 10'h0C4 */
	union {
		uint32_t audio_gain_2_csr_agc_info; // word name
		struct {
			uint32_t agc_length : 10;
			uint32_t : 6; // padding bits
			uint32_t gain_interleave_time : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* AUDIO_GAIN_2_CSR_W1P 10'h0C8 */
	union {
		uint32_t audio_gain_2_csr_w1p; // word name
		struct {
			uint32_t g2c_start : 1;
			uint32_t : 7; // padding bits
			uint32_t g2c_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_W1P_START 10'h0CC */
	union {
		uint32_t audio_w1p_start; // word name
		struct {
			uint32_t amic_left_start : 1;
			uint32_t : 7; // padding bits
			uint32_t amic_right_start : 1;
			uint32_t : 7; // padding bits
			uint32_t dmic_left_start : 1;
			uint32_t : 7; // padding bits
			uint32_t dmic_right_start : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* AUDIO_W1P_STOP 10'h0D0 */
	union {
		uint32_t audio_w1p_stop; // word name
		struct {
			uint32_t amic_left_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t amic_right_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t dmic_left_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t dmic_right_stop : 1;
			uint32_t : 7; // padding bits
		};
	};
} CsrBankAdoin;

#endif