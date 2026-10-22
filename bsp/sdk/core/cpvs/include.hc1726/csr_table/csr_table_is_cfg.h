/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_IS_CFG_H_
#define CSR_TABLE_IS_CFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_is_cfg[] = {
	// WORD cken0
	{ "cken_isr0_k", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isr1_k", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_fe0_k", 0x00000000, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_fe1_k", 0x00000000, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken1
	{ "cken_isk0_k", 0x00000004, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isk1_k", 0x00000004, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_bspshb_k", 0x00000004, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_fscshb_k", 0x00000004, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN1", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken2
	{ "cken_isw0_k", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isw1_k", 0x00000008, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_isw2_k", 0x00000008, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_isw3_k", 0x00000008, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN2", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken3
	{ "cken_checksum_k", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_ctrl_k", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_csr_k", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "CKEN3", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst0
	{ "lv_rst_isr0_k", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isr1_k", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_fe0_k", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_fe1_k", 0x00000010, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst1
	{ "lv_rst_isk0_k", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isk1_k", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_bspshb_k", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_fscshb_k", 0x00000014, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST1", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst2
	{ "lv_rst_isw0_k", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isw1_k", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_isw2_k", 0x00000018, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_isw3_k", 0x00000018, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST2", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst3
	{ "lv_rst_checksum_k", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_ctrl_k", 0x0000001C, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_csr_k", 0x0000001C, 16, 16, CSR_RW, 0x00000000 },
	{ "LVLRST3", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD swrst0
	{ "sw_rst_isr0_k", 0x00000020, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isr1_k", 0x00000020, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_fe0_k", 0x00000020, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_fe1_k", 0x00000020, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST0", 0x00000020, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst1
	{ "sw_rst_isk0_k", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isk1_k", 0x00000024, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_bspshb_k", 0x00000024, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_fscshb_k", 0x00000024, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST1", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst2
	{ "sw_rst_isw0_k", 0x00000028, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw1_k", 0x00000028, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw2_k", 0x00000028, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw3_k", 0x00000028, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST2", 0x00000028, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst3
	{ "sw_rst_checksum_k", 0x0000002C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_ctrl_k", 0x0000002C, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_csr_k", 0x0000002C, 16, 16, CSR_W1P, 0x00000000 },
	{ "SWRST3", 0x0000002C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cken4
	{ "cken_isr0_d", 0x00000030, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isr1_d", 0x00000030, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_isk0_d", 0x00000030, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_isk1_d", 0x00000030, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN4", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken5
	{ "cken_isw0_d", 0x00000034, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isw1_d", 0x00000034, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_isw2_d", 0x00000034, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_isw3_d", 0x00000034, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN5", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken6
	{ "cken_checksum_d", 0x00000038, 0, 0, CSR_RW, 0x00000001 },
	{ "CKEN6", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst4
	{ "lv_rst_isr0_d", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isr1_d", 0x0000003C, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_isk0_d", 0x0000003C, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_isk1_d", 0x0000003C, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST4", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst5
	{ "lv_rst_isw0_d", 0x00000040, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isw1_d", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_isw2_d", 0x00000040, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_isw3_d", 0x00000040, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST5", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst6
	{ "lv_rst_checksum_d", 0x00000044, 0, 0, CSR_RW, 0x00000000 },
	{ "LVLRST6", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD swrst4
	{ "sw_rst_isr0_d", 0x00000048, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isr1_d", 0x00000048, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_isk0_d", 0x00000048, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_isk1_d", 0x00000048, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST4", 0x00000048, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst5
	{ "sw_rst_isw0_d", 0x0000004C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw1_d", 0x0000004C, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw2_d", 0x0000004C, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw3_d", 0x0000004C, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST5", 0x0000004C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst6
	{ "sw_rst_checksum_d", 0x00000050, 0, 0, CSR_W1P, 0x00000000 },
	{ "SWRST6", 0x00000050, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cken7
	{ "cken_isr0_p_clk_g", 0x00000054, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isr1_p_clk_g", 0x00000054, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_fe0_p_clk_g", 0x00000054, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_fe1_p_clk_g", 0x00000054, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN7", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken8
	{ "cken_isk0_p_clk_g", 0x00000058, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isk1_p_clk_g", 0x00000058, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_checksum_p_clk_g", 0x00000058, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_csr_p_clk_g", 0x00000058, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN8", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken9
	{ "cken_isw0_p_clk_g", 0x0000005C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isw1_p_clk_g", 0x0000005C, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_isw2_p_clk_g", 0x0000005C, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_isw3_p_clk_g", 0x0000005C, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN9", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst7
	{ "lv_rst_isr0_p_clk_g", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isr1_p_clk_g", 0x00000060, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_fe0_p_clk_g", 0x00000060, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_fe1_p_clk_g", 0x00000060, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST7", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst8
	{ "lv_rst_isk0_p_clk_g", 0x00000064, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isk1_p_clk_g", 0x00000064, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_checksum_p_clk_g", 0x00000064, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_csr_p_clk_g", 0x00000064, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST8", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst9
	{ "lv_rst_isw0_p_clk_g", 0x00000068, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isw1_p_clk_g", 0x00000068, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_isw2_p_clk_g", 0x00000068, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_isw3_p_clk_g", 0x00000068, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST9", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD swrst7
	{ "sw_rst_isr0_p_clk_g", 0x0000006C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isr1_p_clk_g", 0x0000006C, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_fe0_p_clk_g", 0x0000006C, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_fe1_p_clk_g", 0x0000006C, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST7", 0x0000006C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst8
	{ "sw_rst_isk0_p_clk_g", 0x00000070, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isk1_p_clk_g", 0x00000070, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_checksum_p_clk_g", 0x00000070, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_csr_p_clk_g", 0x00000070, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST8", 0x00000070, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst9
	{ "sw_rst_isw0_p_clk_g", 0x00000074, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw1_p_clk_g", 0x00000074, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw2_p_clk_g", 0x00000074, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw3_p_clk_g", 0x00000074, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST9", 0x00000074, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cken10
	{ "cken_fe0_ref", 0x00000078, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_fe1_ref", 0x00000078, 8, 8, CSR_RW, 0x00000001 },
	{ "CKEN10", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken11
	{ "cken_isw0_ref", 0x0000007C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_isw1_ref", 0x0000007C, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_isw2_ref", 0x0000007C, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_isw3_ref", 0x0000007C, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN11", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst10
	{ "lv_rst_fe0_ref", 0x00000080, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_fe1_ref", 0x00000080, 8, 8, CSR_RW, 0x00000000 },
	{ "LVLRST10", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst11
	{ "lv_rst_isw0_ref", 0x00000084, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_isw1_ref", 0x00000084, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_isw2_ref", 0x00000084, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_isw3_ref", 0x00000084, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST11", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD swrst10
	{ "sw_rst_fe0_ref", 0x00000088, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_fe1_ref", 0x00000088, 8, 8, CSR_W1P, 0x00000000 },
	{ "SWRST10", 0x00000088, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst11
	{ "sw_rst_isw0_ref", 0x0000008C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw1_ref", 0x0000008C, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw2_ref", 0x0000008C, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_isw3_ref", 0x0000008C, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST11", 0x0000008C, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_IS_CFG_H_
