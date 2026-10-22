/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SDMA_SYSCFG_H_
#define CSR_TABLE_SDMA_SYSCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_sdma_syscfg[] = {
	// WORD cfg_cg_dmar
	{ "cken_dmar_k", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_dmar_d", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_dmar_p_clk_g", 0x00000000, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_DMAR", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_dmar
	{ "lv_rst_dmar_k", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_dmar_d", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_dmar_p_clk_g", 0x00000004, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_DMAR", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_dmar
	{ "sw_rst_dmar_k", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_dmar_d", 0x00000008, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_dmar_p_clk_g", 0x00000008, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_DMAR", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_dmaw
	{ "cken_dmaw_k", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_dmaw_d", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_dmaw_p_clk_g", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_DMAW", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_dmaw
	{ "lv_rst_dmaw_k", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_dmaw_d", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_dmaw_p_clk_g", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_DMAW", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_dmaw
	{ "sw_rst_dmaw_k", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_dmaw_d", 0x00000014, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_dmaw_p_clk_g", 0x00000014, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_DMAW", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_aes
	{ "cken_aes_k", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_aes_p_clk_g", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "CFG_CG_AES", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_aes
	{ "lv_rst_aes_k", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_aes_p_clk_g", 0x0000001C, 8, 8, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_AES", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_aes
	{ "sw_rst_aes_k", 0x00000020, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_aes_p_clk_g", 0x00000020, 8, 8, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_AES", 0x00000020, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_lli
	{ "cken_lli_k", 0x00000024, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_lli_p_clk_g", 0x00000024, 8, 8, CSR_RW, 0x00000001 },
	{ "CFG_CG_LLI", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_lli
	{ "lv_rst_lli_k", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_lli_p_clk_g", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_LLI", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_lli
	{ "sw_rst_lli_k", 0x0000002C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_lli_p_clk_g", 0x0000002C, 8, 8, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_LLI", 0x0000002C, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SDMA_SYSCFG_H_
