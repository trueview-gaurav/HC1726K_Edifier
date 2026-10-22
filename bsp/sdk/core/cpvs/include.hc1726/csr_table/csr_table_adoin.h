/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ADOIN_H_
#define CSR_TABLE_ADOIN_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_adoin[] = {
	// WORD adoin_i2s_irq_clear
	{ "i2s_irq_clear_real_stop", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "i2s_irq_clear_error", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "ADOIN_I2S_IRQ_CLEAR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD adoin_i2s_status
	{ "i2s_status_real_stop", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "i2s_status_error", 0x00000004, 8, 8, CSR_RO, 0x00000000 },
	{ "ADOIN_I2S_STATUS", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD adoin_i2s_irq_mask
	{ "i2s_irq_mask_real_stop", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "i2s_irq_mask_error", 0x00000008, 8, 8, CSR_RW, 0x00000001 },
	{ "ADOIN_I2S_IRQ_MASK", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoin_adc_bist_cnt_l
	{ "adc_status_env_de_l", 0x0000000C, 9, 0, CSR_RO, 0x00000000 },
	{ "aadc_bist_l", 0x0000000C, 16, 16, CSR_RO, 0x00000000 },
	{ "ADOIN_ADC_BIST_CNT_L", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD adoin_adc_bist_cnt_r
	{ "adc_status_env_de_r", 0x00000010, 9, 0, CSR_RO, 0x00000000 },
	{ "aadc_bist_r", 0x00000010, 16, 16, CSR_RO, 0x00000000 },
	{ "ADOIN_ADC_BIST_CNT_R", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD adoin_adc_bist_max_min
	{ "bist_max", 0x00000014, 9, 0, CSR_RW, 0x00000233 },
	{ "bist_min", 0x00000014, 25, 16, CSR_RW, 0x000001CC },
	{ "ADOIN_ADC_BIST_MAX_MIN", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoin_adc_bist_start
	{ "aadc_bist_start_l", 0x00000018, 0, 0, CSR_W1P, 0x00000000 },
	{ "aadc_bist_start_r", 0x00000018, 8, 8, CSR_W1P, 0x00000000 },
	{ "ADOIN_ADC_BIST_START", 0x00000018, 31, 0, CSR_W1P, 0x00000000 },
	// WORD adoin_debug_mon_sel
	{ "debug_mon_sel", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "ADOIN_DEBUG_MON_SEL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoin_debug_mon
	{ "debug_mon_reg", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "ADOIN_DEBUG_MON", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD adoin_mem
	{ "sd", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "slp", 0x00000024, 8, 8, CSR_RW, 0x00000000 },
	{ "ADOIN_MEM", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoin_reserved
	{ "reserved", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	{ "ADOIN_RESERVED", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_swap_en
	{ "audio_ch_en", 0x0000002C, 4, 0, CSR_RW, 0x00000000 },
	{ "AUDIO_SWAP_EN", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_swap_sample
	{ "sample_number", 0x00000030, 9, 0, CSR_RW, 0x00000092 },
	{ "AUDIO_SWAP_SAMPLE", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_swap_ch_mux_0
	{ "ch_mux_time_1", 0x00000034, 9, 0, CSR_RW, 0x00000024 },
	{ "ch_mux_time_2", 0x00000034, 25, 16, CSR_RW, 0x00000049 },
	{ "AUDIO_SWAP_CH_MUX_0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_swap_ch_mux_1
	{ "ch_mux_time_3", 0x00000038, 9, 0, CSR_RW, 0x0000006E },
	{ "AUDIO_SWAP_CH_MUX_1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_swap_data_trigr
	{ "data_trigger_time", 0x0000003C, 9, 0, CSR_RW, 0x00000002 },
	{ "AUDIO_SWAP_DATA_TRIGR", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_packer_i2s_mode
	{ "i2s_ch_mode", 0x00000040, 1, 0, CSR_RW, 0x00000000 },
	{ "i2s_16bw", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "AUDIO_PACKER_I2S_MODE", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_packer_data_cnt
	{ "data_cnt_start", 0x00000044, 0, 0, CSR_W1P, 0x00000000 },
	{ "data_cnt_stop", 0x00000044, 8, 8, CSR_W1P, 0x00000000 },
	{ "AUDIO_PACKER_DATA_CNT", 0x00000044, 31, 0, CSR_W1P, 0x00000000 },
	// WORD audio_dmic_clk_div
	{ "div_num", 0x00000048, 9, 0, CSR_RW, 0x00000030 },
	{ "AUDIO_DMIC_CLK_DIV", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_liner_write
	{ "frame_end", 0x0000004C, 0, 0, CSR_W1P, 0x00000000 },
	{ "AUDIO_LINER_WRITE", 0x0000004C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD audio_agc_analog_gain_read_0
	{ "analog_gain_0", 0x00000050, 2, 0, CSR_RO, 0x00000000 },
	{ "analog_gain_1", 0x00000050, 10, 8, CSR_RO, 0x00000000 },
	{ "analog_gain_2", 0x00000050, 18, 16, CSR_RO, 0x00000000 },
	{ "analog_gain_3", 0x00000050, 26, 24, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_ANALOG_GAIN_READ_0", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_analog_gain_read_1
	{ "analog_gain_4", 0x00000054, 2, 0, CSR_RO, 0x00000000 },
	{ "analog_gain_5", 0x00000054, 10, 8, CSR_RO, 0x00000000 },
	{ "analog_gain_6", 0x00000054, 18, 16, CSR_RO, 0x00000000 },
	{ "analog_gain_7", 0x00000054, 26, 24, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_ANALOG_GAIN_READ_1", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_analog_gain_read_2
	{ "analog_gain_8", 0x00000058, 2, 0, CSR_RO, 0x00000000 },
	{ "analog_gain_9", 0x00000058, 10, 8, CSR_RO, 0x00000000 },
	{ "analog_gain_10", 0x00000058, 18, 16, CSR_RO, 0x00000000 },
	{ "analog_gain_11", 0x00000058, 26, 24, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_ANALOG_GAIN_READ_2", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_analog_gain_read_3
	{ "analog_gain_12", 0x0000005C, 2, 0, CSR_RO, 0x00000000 },
	{ "analog_gain_13", 0x0000005C, 10, 8, CSR_RO, 0x00000000 },
	{ "analog_gain_14", 0x0000005C, 18, 16, CSR_RO, 0x00000000 },
	{ "analog_gain_15", 0x0000005C, 26, 24, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_ANALOG_GAIN_READ_3", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_digital_gain_read_0
	{ "digital_gain_0", 0x00000060, 11, 0, CSR_RO, 0x00000000 },
	{ "digital_gain_1", 0x00000060, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DIGITAL_GAIN_READ_0", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_digital_gain_read_1
	{ "digital_gain_2", 0x00000064, 11, 0, CSR_RO, 0x00000000 },
	{ "digital_gain_3", 0x00000064, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DIGITAL_GAIN_READ_1", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_digital_gain_read_2
	{ "digital_gain_4", 0x00000068, 11, 0, CSR_RO, 0x00000000 },
	{ "digital_gain_5", 0x00000068, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DIGITAL_GAIN_READ_2", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_digital_gain_read_3
	{ "digital_gain_6", 0x0000006C, 11, 0, CSR_RO, 0x00000000 },
	{ "digital_gain_7", 0x0000006C, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DIGITAL_GAIN_READ_3", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_digital_gain_read_4
	{ "digital_gain_8", 0x00000070, 11, 0, CSR_RO, 0x00000000 },
	{ "digital_gain_9", 0x00000070, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DIGITAL_GAIN_READ_4", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_digital_gain_read_5
	{ "digital_gain_10", 0x00000074, 11, 0, CSR_RO, 0x00000000 },
	{ "digital_gain_11", 0x00000074, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DIGITAL_GAIN_READ_5", 0x00000074, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_digital_gain_read_6
	{ "digital_gain_12", 0x00000078, 11, 0, CSR_RO, 0x00000000 },
	{ "digital_gain_13", 0x00000078, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DIGITAL_GAIN_READ_6", 0x00000078, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_digital_gain_read_7
	{ "digital_gain_14", 0x0000007C, 11, 0, CSR_RO, 0x00000000 },
	{ "digital_gain_15", 0x0000007C, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DIGITAL_GAIN_READ_7", 0x0000007C, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_data_cnt_read_0
	{ "data_cnt_0", 0x00000080, 11, 0, CSR_RO, 0x00000000 },
	{ "data_cnt_1", 0x00000080, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DATA_CNT_READ_0", 0x00000080, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_data_cnt_read_1
	{ "data_cnt_2", 0x00000084, 11, 0, CSR_RO, 0x00000000 },
	{ "data_cnt_3", 0x00000084, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DATA_CNT_READ_1", 0x00000084, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_data_cnt_read_2
	{ "data_cnt_4", 0x00000088, 11, 0, CSR_RO, 0x00000000 },
	{ "data_cnt_5", 0x00000088, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DATA_CNT_READ_2", 0x00000088, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_data_cnt_read_3
	{ "data_cnt_6", 0x0000008C, 11, 0, CSR_RO, 0x00000000 },
	{ "data_cnt_7", 0x0000008C, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DATA_CNT_READ_3", 0x0000008C, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_data_cnt_read_4
	{ "data_cnt_8", 0x00000090, 11, 0, CSR_RO, 0x00000000 },
	{ "data_cnt_9", 0x00000090, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DATA_CNT_READ_4", 0x00000090, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_data_cnt_read_5
	{ "data_cnt_10", 0x00000094, 11, 0, CSR_RO, 0x00000000 },
	{ "data_cnt_11", 0x00000094, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DATA_CNT_READ_5", 0x00000094, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_data_cnt_read_6
	{ "data_cnt_12", 0x00000098, 11, 0, CSR_RO, 0x00000000 },
	{ "data_cnt_13", 0x00000098, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DATA_CNT_READ_6", 0x00000098, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_agc_data_cnt_read_7
	{ "data_cnt_14", 0x0000009C, 11, 0, CSR_RO, 0x00000000 },
	{ "data_cnt_15", 0x0000009C, 27, 16, CSR_RO, 0x00000000 },
	{ "AUDIO_AGC_DATA_CNT_READ_7", 0x0000009C, 31, 0, CSR_RO, 0x00000000 },
	// WORD audio_gain_2_csr
	{ "amic_ch_num", 0x000000C0, 1, 0, CSR_RW, 0x00000000 },
	{ "sample_rate_osr", 0x000000C0, 15, 8, CSR_RW, 0x00000092 },
	{ "AUDIO_GAIN_2_CSR", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_gain_2_csr_agc_info
	{ "agc_length", 0x000000C4, 9, 0, CSR_RW, 0x000003FF },
	{ "gain_interleave_time", 0x000000C4, 25, 16, CSR_RW, 0x000001FF },
	{ "AUDIO_GAIN_2_CSR_AGC_INFO", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_gain_2_csr_w1p
	{ "g2c_start", 0x000000C8, 0, 0, CSR_RW, 0x00000000 },
	{ "g2c_stop", 0x000000C8, 8, 8, CSR_RW, 0x00000000 },
	{ "AUDIO_GAIN_2_CSR_W1P", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_w1p_start
	{ "amic_left_start", 0x000000CC, 0, 0, CSR_W1P, 0x00000000 },
	{ "amic_right_start", 0x000000CC, 8, 8, CSR_W1P, 0x00000000 },
	{ "dmic_left_start", 0x000000CC, 16, 16, CSR_W1P, 0x00000000 },
	{ "dmic_right_start", 0x000000CC, 24, 24, CSR_W1P, 0x00000000 },
	{ "AUDIO_W1P_START", 0x000000CC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD audio_w1p_stop
	{ "amic_left_stop", 0x000000D0, 0, 0, CSR_W1P, 0x00000000 },
	{ "amic_right_stop", 0x000000D0, 8, 8, CSR_W1P, 0x00000000 },
	{ "dmic_left_stop", 0x000000D0, 16, 16, CSR_W1P, 0x00000000 },
	{ "dmic_right_stop", 0x000000D0, 24, 24, CSR_W1P, 0x00000000 },
	{ "AUDIO_W1P_STOP", 0x000000D0, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ADOIN_H_
