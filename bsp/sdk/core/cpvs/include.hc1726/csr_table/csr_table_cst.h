/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CST_H_
#define CSR_TABLE_CST_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_cst[] = {
	// WORD y_para_0
	{ "coeff_00_2s", 0x00000000, 13, 0, CSR_RW, 0x00000177 },
	{ "coeff_01_2s", 0x00000000, 29, 16, CSR_RW, 0x000004E9 },
	{ "Y_PARA_0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD y_para_1
	{ "coeff_02_2s", 0x00000004, 13, 0, CSR_RW, 0x0000007F },
	{ "offset_o_0_2s", 0x00000004, 26, 16, CSR_RW, 0x00000040 },
	{ "Y_PARA_1", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD u_para_0
	{ "coeff_10_2s", 0x00000008, 13, 0, CSR_RW, 0x00003F31 },
	{ "coeff_11_2s", 0x00000008, 29, 16, CSR_RW, 0x00003D4C },
	{ "U_PARA_0", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD u_para_1
	{ "coeff_12_2s", 0x0000000C, 13, 0, CSR_RW, 0x00000383 },
	{ "offset_o_1_2s", 0x0000000C, 26, 16, CSR_RW, 0x00000200 },
	{ "U_PARA_1", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD v_para_0
	{ "coeff_20_2s", 0x00000010, 13, 0, CSR_RW, 0x00000383 },
	{ "coeff_21_2s", 0x00000010, 29, 16, CSR_RW, 0x00003CCF },
	{ "V_PARA_0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD v_para_1
	{ "coeff_22_2s", 0x00000014, 13, 0, CSR_RW, 0x00003FAE },
	{ "offset_o_2_2s", 0x00000014, 26, 16, CSR_RW, 0x00000200 },
	{ "V_PARA_1", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CST_H_
