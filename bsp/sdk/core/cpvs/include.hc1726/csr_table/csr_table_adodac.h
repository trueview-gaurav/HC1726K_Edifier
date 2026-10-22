/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ADODAC_H_
#define CSR_TABLE_ADODAC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_adodac[] = {
	// WORD sine_gen_div
	{ "pos_cnt_num_m1", 0x00000000, 9, 0, CSR_RW, 0x00000049 },
	{ "neg_cnt_num_m1", 0x00000000, 25, 16, CSR_RW, 0x00000048 },
	{ "SINE_GEN_DIV", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD sine_gen_pulse
	{ "sine_gen_start", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "sine_gen_stop", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "SINE_GEN_PULSE", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD sine_gen_mode
	{ "sine_gen_fin", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "bist_mode", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "SINE_GEN_MODE", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD sdm_pulse
	{ "sdm_start", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sdm_stop", 0x0000000C, 8, 8, CSR_W1P, 0x00000000 },
	{ "SDM_PULSE", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD sdm_kernel
	{ "sdm_up_sample_rate", 0x00000010, 15, 0, CSR_RW, 0x00000000 },
	{ "sdm_input_bw", 0x00000010, 21, 16, CSR_RW, 0x00000010 },
	{ "SDM_KERNEL", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD dac_en
	{ "rg_adac_din", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_adac_vref_en", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_adac_dac_en", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_adac_clk_inv_en", 0x00000014, 24, 24, CSR_RW, 0x00000000 },
	{ "DAC_EN", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD dac_vref_fs
	{ "rg_adac_vref_fs", 0x00000018, 3, 0, CSR_RW, 0x00000000 },
	{ "DAC_VREF_FS", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug
	{ "debug_mon_sel", 0x0000001C, 1, 0, CSR_RW, 0x00000000 },
	{ "rg_adac_reserved", 0x0000001C, 15, 8, CSR_RW, 0x00000000 },
	{ "DEBUG", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ADODAC_H_
