/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ISK_CFG_H_
#define CSR_TABLE_ISK_CFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_isk_cfg[] = {
	// WORD cken0
	{ "cken_cvs_k", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_crop_k", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_bsp_k", 0x00000000, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_fsc_k", 0x00000000, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken1
	{ "cken_cvs_p_clk_g", 0x00000004, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_crop_p_clk_g", 0x00000004, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_bsp_p_clk_g", 0x00000004, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_fsc_p_clk_g", 0x00000004, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN1", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst0
	{ "lv_rst_cvs_k", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_crop_k", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_dbc_k", 0x00000008, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_dcc_k", 0x00000008, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST0", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst1
	{ "lv_rst_lsc_k", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_dfk_k", 0x0000000C, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_bsp_k", 0x0000000C, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_fsc_k", 0x0000000C, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST1", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst2
	{ "lv_rst_cvs_p_clk_g", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_crop_p_clk_g", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_dbc_p_clk_g", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_dcc_p_clk_g", 0x00000010, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST2", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst3
	{ "lv_rst_lsc_p_clk_g", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_dfk_p_clk_g", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_bsp_p_clk_g", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_fsc_p_clk_g", 0x00000014, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST3", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD swrst0
	{ "sw_rst_cvs_k", 0x00000018, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_crop_k", 0x00000018, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_dbc_k", 0x00000018, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_dcc_k", 0x00000018, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST0", 0x00000018, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst1
	{ "sw_rst_lsc_k", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_dfk_k", 0x0000001C, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_bsp_k", 0x0000001C, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_fsc_k", 0x0000001C, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST1", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst2
	{ "sw_rst_cvs_p_clk_g", 0x00000020, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_crop_p_clk_g", 0x00000020, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_dbc_p_clk_g", 0x00000020, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_dcc_p_clk_g", 0x00000020, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST2", 0x00000020, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst3
	{ "sw_rst_lsc_p_clk_g", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_dfk_p_clk_g", 0x00000024, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_bsp_p_clk_g", 0x00000024, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_fsc_p_clk_g", 0x00000024, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST3", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ISK_CFG_H_
