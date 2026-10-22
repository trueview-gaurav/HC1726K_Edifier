/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DMIC_H_
#define CSR_TABLE_DMIC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dmic[] = {
	// WORD audio_dmic_dr_mode
	{ "dr_mode", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "dmic_data_case", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "AUDIO_DMIC_DR_MODE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_dmic_dr_mode_pulse
	{ "dr_start", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "dr_stop", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "AUDIO_DMIC_DR_MODE_PULSE", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD audio_dmic_dr_cnt_ini
	{ "data_valid_time", 0x00000008, 9, 0, CSR_RW, 0x00000000 },
	{ "cycle_time_ini", 0x00000008, 31, 16, CSR_RW, 0x00000000 },
	{ "AUDIO_DMIC_DR_CNT_INI", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_dmic_dr_data_tri_time
	{ "data_trigger_time_small", 0x0000000C, 15, 0, CSR_RW, 0x00000000 },
	{ "data_trigger_time_large", 0x0000000C, 31, 16, CSR_RW, 0x00000000 },
	{ "AUDIO_DMIC_DR_DATA_TRI_TIME", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_dmic_comb_gain_lsb
	{ "csr_gain_lsb", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	{ "AUDIO_DMIC_COMB_GAIN_LSB", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_dmic_comb_gain_msb
	{ "csr_gain_msb", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	{ "AUDIO_DMIC_COMB_GAIN_MSB", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_dmic_comb_down
	{ "downsample_rate", 0x00000018, 15, 0, CSR_RW, 0x00000000 },
	{ "AUDIO_DMIC_COMB_DOWN", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DMIC_H_
