/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AMIC_H_
#define CSR_TABLE_AMIC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_amic[] = {
	// WORD audio_agc_mode
	{ "auto_gain_control_mode", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "noise_suppress_en", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "agc_digital_gain_en", 0x00000000, 16, 16, CSR_RW, 0x00000001 },
	{ "delay_compensate_en", 0x00000000, 24, 24, CSR_RW, 0x00000001 },
	{ "AUDIO_AGC_MODE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_sw_control
	{ "sw_agc_analog_gain_index", 0x00000004, 2, 0, CSR_RW, 0x00000004 },
	{ "sw_agc_digital_gain", 0x00000004, 19, 8, CSR_RW, 0x00000100 },
	{ "AUDIO_AGC_SW_CONTROL", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_control_gain
	{ "control_digital_gain", 0x00000008, 6, 0, CSR_RW, 0x00000040 },
	{ "AUDIO_AGC_CONTROL_GAIN", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_index
	{ "gain_medium_bw", 0x0000000C, 3, 0, CSR_RW, 0x00000007 },
	{ "agc_gain_high_index", 0x0000000C, 10, 8, CSR_RW, 0x00000006 },
	{ "agc_gain_medium_index", 0x0000000C, 18, 16, CSR_RW, 0x00000004 },
	{ "agc_gain_low_index", 0x0000000C, 26, 24, CSR_RW, 0x00000002 },
	{ "AUDIO_AGC_INDEX", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_hold_time
	{ "hold_time", 0x00000010, 10, 0, CSR_RW, 0x00000120 },
	{ "noise_hold_time_increase", 0x00000010, 20, 16, CSR_RW, 0x00000001 },
	{ "noise_hold_time_decrease", 0x00000010, 28, 24, CSR_RW, 0x00000002 },
	{ "AUDIO_AGC_HOLD_TIME", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_gain_step
	{ "digital_gain_step_upward", 0x00000014, 7, 0, CSR_RW, 0x00000008 },
	{ "digital_gain_step_downward", 0x00000014, 15, 8, CSR_RW, 0x00000002 },
	{ "AUDIO_AGC_GAIN_STEP", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_attack_step
	{ "attack_step", 0x00000018, 8, 0, CSR_RW, 0x00000001 },
	{ "release_step", 0x00000018, 24, 16, CSR_RW, 0x00000008 },
	{ "AUDIO_AGC_ATTACK_STEP", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_detect_th_0
	{ "zero_crossing_number_th", 0x0000001C, 9, 0, CSR_RW, 0x000000C8 },
	{ "overflow_number_th", 0x0000001C, 25, 16, CSR_RW, 0x00000005 },
	{ "AUDIO_AGC_DETECT_TH_0", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_detect_th_1
	{ "overflow_th", 0x00000020, 15, 0, CSR_RW, 0x000061A8 },
	{ "AUDIO_AGC_DETECT_TH_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_signal_th_0
	{ "signal_high_th", 0x00000024, 14, 0, CSR_RW, 0x00000800 },
	{ "signal_medium_th", 0x00000024, 30, 16, CSR_RW, 0x00000040 },
	{ "AUDIO_AGC_SIGNAL_TH_0", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_signal_th_1
	{ "signal_low_th", 0x00000028, 14, 0, CSR_RW, 0x00000010 },
	{ "AUDIO_AGC_SIGNAL_TH_1", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_hpf_0
	{ "coeff_forward", 0x0000002C, 15, 0, CSR_RW, 0x00003F80 },
	{ "coeff_delay", 0x0000002C, 31, 16, CSR_RW, 0x0000C080 },
	{ "AUDIO_AGC_HPF_0", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_hpf_1
	{ "coeff_feedback", 0x00000030, 15, 0, CSR_RW, 0x00003F01 },
	{ "AUDIO_AGC_HPF_1", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_delay
	{ "agc_sample_delay", 0x00000034, 7, 0, CSR_RW, 0x00000001 },
	{ "AUDIO_AGC_DELAY", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD comb_gain
	{ "csr_gain", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	{ "COMB_GAIN", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD comb_down
	{ "downsample_rate", 0x0000003C, 15, 0, CSR_RW, 0x00000000 },
	{ "inverse", 0x0000003C, 24, 24, CSR_RW, 0x00000000 },
	{ "COMB_DOWN", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_sel
	{ "debug_mon_sel", 0x00000040, 0, 0, CSR_RW, 0x00000000 },
	{ "DEBUG_SEL", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_agc_atpg
	{ "atpg_ctrl", 0x00000044, 1, 0, CSR_RW, 0x00000000 },
	{ "AUDIO_AGC_ATPG", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AMIC_H_
