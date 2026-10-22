/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ADOIN_SYSCFG_H_
#define CSR_TABLE_ADOIN_SYSCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_adoin_syscfg[] = {
	// WORD aadc_l_rw_k
	{ "cken_aadc_l_k_x20", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_aadc_l_k_x20", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "AADC_L_RW_K", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_l_w1p_k
	{ "sw_rst_aadc_l_k_x20", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "AADC_L_W1P_K", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD aadc_l_rw_p
	{ "cken_aadc_l_p", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_aadc_l_p", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "AADC_L_RW_P", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_l_w1p_p
	{ "sw_rst_aadc_l_p", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "AADC_L_W1P_P", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD aadc_r_rw_k
	{ "cken_aadc_r_k_x20", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_aadc_r_k_x20", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "AADC_R_RW_K", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_r_w1p_k
	{ "sw_rst_aadc_r_k_x20", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "AADC_R_W1P_K", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD aadc_r_rw_p
	{ "cken_aadc_r_p", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_aadc_r_p", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "AADC_R_RW_P", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD aadc_r_w1p_p
	{ "sw_rst_aadc_r_p", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "AADC_R_W1P_P", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD amic_comb_l_rw_k
	{ "cken_amic_comb_l_k", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_amic_comb_l_k", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "AMIC_COMB_L_RW_K", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD amic_comb_l_w1p_k
	{ "sw_rst_amic_comb_l_k", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "AMIC_COMB_L_W1P_K", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// WORD amic_comb_r_rw_k
	{ "cken_amic_comb_r_k", 0x00000028, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_amic_comb_r_k", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "AMIC_COMB_R_RW_K", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD amic_comb_r_w1p_k
	{ "sw_rst_amic_comb_r_k", 0x0000002C, 0, 0, CSR_W1P, 0x00000000 },
	{ "AMIC_COMB_R_W1P_K", 0x0000002C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD amic_agc_l_rw_k
	{ "cken_amic_agc_l_k", 0x00000030, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_amic_agc_l_k", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "AMIC_AGC_L_RW_K", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD amic_agc_l_w1p_k
	{ "sw_rst_amic_agc_l_k", 0x00000034, 0, 0, CSR_W1P, 0x00000000 },
	{ "AMIC_AGC_L_W1P_K", 0x00000034, 31, 0, CSR_W1P, 0x00000000 },
	// WORD amic_agc_r_rw_k
	{ "cken_amic_agc_r_k", 0x00000038, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_amic_agc_r_k", 0x00000038, 8, 8, CSR_RW, 0x00000000 },
	{ "AMIC_AGC_R_RW_K", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD amic_agc_r_w1p_k
	{ "sw_rst_amic_agc_r_k", 0x0000003C, 0, 0, CSR_W1P, 0x00000000 },
	{ "AMIC_AGC_R_W1P_K", 0x0000003C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD amic_l_rw_p
	{ "cken_amic_l_p", 0x00000040, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_amic_l_p", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "AMIC_L_RW_P", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD amic_l_w1p_p
	{ "sw_rst_amic_l_p", 0x00000044, 0, 0, CSR_W1P, 0x00000000 },
	{ "AMIC_L_W1P_P", 0x00000044, 31, 0, CSR_W1P, 0x00000000 },
	// WORD amic_r_rw_p
	{ "cken_amic_r_p", 0x00000048, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_amic_r_p", 0x00000048, 8, 8, CSR_RW, 0x00000000 },
	{ "AMIC_R_RW_P", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD amic_r_w1p_p
	{ "sw_rst_amic_r_p", 0x0000004C, 0, 0, CSR_W1P, 0x00000000 },
	{ "AMIC_R_W1P_P", 0x0000004C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dmic_dr_l_rw_k
	{ "cken_dmic_dr_l_k_x20", 0x00000050, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dmic_dr_l_k_x20", 0x00000050, 8, 8, CSR_RW, 0x00000000 },
	{ "DMIC_DR_L_RW_K", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD dmic_dr_l_w1p_k
	{ "sw_rst_dmic_dr_l_k_x20", 0x00000054, 0, 0, CSR_W1P, 0x00000000 },
	{ "DMIC_DR_L_W1P_K", 0x00000054, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dmic_dr_r_rw_k
	{ "cken_dmic_dr_r_k_x20", 0x00000058, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dmic_dr_r_k_x20", 0x00000058, 8, 8, CSR_RW, 0x00000000 },
	{ "DMIC_DR_R_RW_K", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD dmic_dr_r_w1p_k
	{ "sw_rst_dmic_dr_r_k_x20", 0x0000005C, 0, 0, CSR_W1P, 0x00000000 },
	{ "DMIC_DR_R_W1P_K", 0x0000005C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dmic_comb_l_rw_k
	{ "cken_dmic_comb_l_k", 0x00000060, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dmic_comb_l_k", 0x00000060, 8, 8, CSR_RW, 0x00000000 },
	{ "DMIC_COMB_L_RW_K", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD dmic_comb_l_w1p_k
	{ "sw_rst_dmic_comb_l_k", 0x00000064, 0, 0, CSR_W1P, 0x00000000 },
	{ "DMIC_COMB_L_W1P_K", 0x00000064, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dmic_comb_r_rw_k
	{ "cken_dmic_comb_r_k", 0x00000068, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dmic_comb_r_k", 0x00000068, 8, 8, CSR_RW, 0x00000000 },
	{ "DMIC_COMB_R_RW_K", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD dmic_comb_r_w1p_k
	{ "sw_rst_dmic_comb_r_k", 0x0000006C, 0, 0, CSR_W1P, 0x00000000 },
	{ "DMIC_COMB_R_W1P_K", 0x0000006C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dmic_l_rw_p
	{ "cken_dmic_l_p", 0x00000070, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dmic_l_p", 0x00000070, 8, 8, CSR_RW, 0x00000000 },
	{ "DMIC_L_RW_P", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD dmic_l_w1p_p
	{ "sw_rst_dmic_l_p", 0x00000074, 0, 0, CSR_W1P, 0x00000000 },
	{ "DMIC_L_W1P_P", 0x00000074, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dmic_r_rw_p
	{ "cken_dmic_r_p", 0x00000078, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dmic_r_p", 0x00000078, 8, 8, CSR_RW, 0x00000000 },
	{ "DMIC_R_RW_P", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD dmic_r_w1p_p
	{ "sw_rst_dmic_r_p", 0x0000007C, 0, 0, CSR_W1P, 0x00000000 },
	{ "DMIC_R_W1P_P", 0x0000007C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swap_rw_k
	{ "cken_swap_k", 0x00000080, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_swap_k", 0x00000080, 8, 8, CSR_RW, 0x00000000 },
	{ "SWAP_RW_K", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD swap_w1p_k
	{ "sw_rst_swap_k", 0x00000084, 0, 0, CSR_W1P, 0x00000000 },
	{ "SWAP_W1P_K", 0x00000084, 31, 0, CSR_W1P, 0x00000000 },
	// WORD packer_rw_k
	{ "cken_packer_k", 0x00000088, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_packer_k", 0x00000088, 8, 8, CSR_RW, 0x00000000 },
	{ "PACKER_RW_K", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD packer_w1p_k
	{ "sw_rst_packer_k", 0x0000008C, 0, 0, CSR_W1P, 0x00000000 },
	{ "PACKER_W1P_K", 0x0000008C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD i2s_rw_k
	{ "cken_i2s_k_x20", 0x00000090, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_i2s_k_x20", 0x00000090, 8, 8, CSR_RW, 0x00000000 },
	{ "I2S_RW_K", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD i2s_w1p_k
	{ "sw_rst_i2s_k_x20", 0x00000094, 0, 0, CSR_W1P, 0x00000000 },
	{ "I2S_W1P_K", 0x00000094, 31, 0, CSR_W1P, 0x00000000 },
	// WORD i2s_rw_p
	{ "cken_i2s_p", 0x00000098, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_i2s_p", 0x00000098, 8, 8, CSR_RW, 0x00000000 },
	{ "I2S_RW_P", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD i2s_w1p_p
	{ "sw_rst_i2s_p", 0x0000009C, 0, 0, CSR_W1P, 0x00000000 },
	{ "I2S_W1P_P", 0x0000009C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD write_rw_k
	{ "cken_write_k", 0x000000A0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_write_k", 0x000000A0, 8, 8, CSR_RW, 0x00000000 },
	{ "WRITE_RW_K", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD write_w1p_k
	{ "sw_rst_write_k", 0x000000A4, 0, 0, CSR_W1P, 0x00000000 },
	{ "WRITE_W1P_K", 0x000000A4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD write_rw_d
	{ "cken_write_d", 0x000000A8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_write_d", 0x000000A8, 8, 8, CSR_RW, 0x00000000 },
	{ "WRITE_RW_D", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD write_w1p_d
	{ "sw_rst_write_d", 0x000000AC, 0, 0, CSR_W1P, 0x00000000 },
	{ "WRITE_W1P_D", 0x000000AC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD write_rw_p
	{ "cken_write_p", 0x000000B0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_write_p", 0x000000B0, 8, 8, CSR_RW, 0x00000000 },
	{ "WRITE_RW_P", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD write_w1p_p
	{ "sw_rst_write_p", 0x000000B4, 0, 0, CSR_W1P, 0x00000000 },
	{ "WRITE_W1P_P", 0x000000B4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD saadc_rw_k
	{ "cken_saadc_k", 0x000000B8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_saadc_k", 0x000000B8, 8, 8, CSR_RW, 0x00000000 },
	{ "SAADC_RW_K", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD saadc_w1p_k
	{ "sw_rst_saadc_k", 0x000000BC, 0, 0, CSR_W1P, 0x00000000 },
	{ "SAADC_W1P_K", 0x000000BC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD saadc_rw_p
	{ "cken_saadc_p", 0x000000C0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_saadc_p", 0x000000C0, 8, 8, CSR_RW, 0x00000000 },
	{ "SAADC_RW_P", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD saadc_w1p_p
	{ "sw_rst_saadc_p", 0x000000C4, 0, 0, CSR_W1P, 0x00000000 },
	{ "SAADC_W1P_P", 0x000000C4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD st_rw_k
	{ "cken_st_k", 0x000000C8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_st_k", 0x000000C8, 8, 8, CSR_RW, 0x00000000 },
	{ "ST_RW_K", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD st_w1p_k
	{ "sw_rst_st_k", 0x000000CC, 0, 0, CSR_W1P, 0x00000000 },
	{ "ST_W1P_K", 0x000000CC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD st_rw_p
	{ "cken_st_p", 0x000000D0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_st_p", 0x000000D0, 8, 8, CSR_RW, 0x00000000 },
	{ "ST_RW_P", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD st_w1p_p
	{ "sw_rst_st_p", 0x000000D4, 0, 0, CSR_W1P, 0x00000000 },
	{ "ST_W1P_P", 0x000000D4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ldo_rw_p
	{ "cken_ldo_p", 0x000000D8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ldo_p", 0x000000D8, 8, 8, CSR_RW, 0x00000000 },
	{ "LDO_RW_P", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD ldo_w1p_p
	{ "sw_rst_ldo_p", 0x000000DC, 0, 0, CSR_W1P, 0x00000000 },
	{ "LDO_W1P_P", 0x000000DC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD g2c_rw_k
	{ "cken_g2c_k", 0x000000E0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_g2c_k", 0x000000E0, 8, 8, CSR_RW, 0x00000000 },
	{ "G2C_RW_K", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD g2c_w1p_k
	{ "sw_rst_g2c_k", 0x000000E4, 0, 0, CSR_W1P, 0x00000000 },
	{ "G2C_W1P_K", 0x000000E4, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ADOIN_SYSCFG_H_
