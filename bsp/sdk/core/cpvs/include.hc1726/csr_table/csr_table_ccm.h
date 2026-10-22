/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CCM_H_
#define CSR_TABLE_CCM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ccm[] = {
	// WORD r_para_0
	{ "coeff_00_2s", 0x00000000, 15, 0, CSR_RW, 0x0000081C },
	{ "R_PARA_0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD r_para_1
	{ "coeff_01_2s", 0x00000004, 15, 0, CSR_RW, 0x0000FB3F },
	{ "R_PARA_1", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD r_para_2
	{ "coeff_02_2s", 0x00000008, 15, 0, CSR_RW, 0x0000022E },
	{ "R_PARA_2", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD r_para_3
	{ "offset_o_0_2s", 0x0000000C, 21, 0, CSR_RW, 0x00000400 },
	{ "R_PARA_3", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_para_0
	{ "coeff_10_2s", 0x00000010, 15, 0, CSR_RW, 0x0000FC56 },
	{ "G_PARA_0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_para_1
	{ "coeff_11_2s", 0x00000014, 15, 0, CSR_RW, 0x00000CD8 },
	{ "G_PARA_1", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_para_2
	{ "coeff_12_2s", 0x00000018, 15, 0, CSR_RW, 0x0000FED4 },
	{ "G_PARA_2", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_para_3
	{ "offset_o_1_2s", 0x0000001C, 21, 0, CSR_RW, 0x00002000 },
	{ "G_PARA_3", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD b_para_0
	{ "coeff_20_2s", 0x00000020, 15, 0, CSR_RW, 0x0000FF11 },
	{ "B_PARA_0", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD b_para_1
	{ "coeff_21_2s", 0x00000024, 15, 0, CSR_RW, 0x0000F9C8 },
	{ "B_PARA_1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD b_para_2
	{ "coeff_22_2s", 0x00000028, 15, 0, CSR_RW, 0x00000F28 },
	{ "B_PARA_2", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD b_para_3
	{ "offset_o_2_2s", 0x0000002C, 21, 0, CSR_RW, 0x00002000 },
	{ "B_PARA_3", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_coring_en
	{ "coring_en", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_CORING_EN", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_coring_th_0
	{ "coring_th_0", 0x00000034, 9, 0, CSR_RW, 0x00000040 },
	{ "WORD_CORING_TH_0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_coring_th_1
	{ "coring_th_1", 0x00000038, 9, 0, CSR_RW, 0x00000040 },
	{ "WORD_CORING_TH_1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_coring_th_2
	{ "coring_th_2", 0x0000003C, 9, 0, CSR_RW, 0x00000040 },
	{ "WORD_CORING_TH_2", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_coring_th_3
	{ "coring_th_3", 0x00000040, 9, 0, CSR_RW, 0x00000040 },
	{ "WORD_CORING_TH_3", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_coring_prec
	{ "coring_th_prec_0", 0x00000044, 3, 0, CSR_RW, 0x00000008 },
	{ "coring_th_prec_1", 0x00000044, 7, 4, CSR_RW, 0x00000007 },
	{ "coring_th_prec_2", 0x00000044, 11, 8, CSR_RW, 0x00000006 },
	{ "coring_th_prec_3", 0x00000044, 15, 12, CSR_RW, 0x00000005 },
	{ "WORD_CORING_PREC", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_alpha_ini
	{ "alpha_ini", 0x00000048, 8, 0, CSR_RW, 0x00000032 },
	{ "WORD_ALPHA_INI", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mode_ctrl
	{ "mode", 0x00000050, 1, 0, CSR_RW, 0x00000000 },
	{ "atpg_test_enable", 0x00000050, 9, 8, CSR_RW, 0x00000000 },
	{ "MODE_CTRL", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CCM_H_
