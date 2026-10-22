/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ENC_SYSCFG_H_
#define CSR_TABLE_ENC_SYSCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_enc_syscfg[] = {
	// WORD cfg_cg_sp
	{ "cken_sp_k", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_sp_p_clk_g", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "CFG_CG_SP", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_sp
	{ "lv_rst_sp_k", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_sp_p_clk_g", 0x00000004, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_SP", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_sp
	{ "sw_rst_sp_k", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_sp_p_clk_g", 0x00000008, 8, 8, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_SP", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_jpeg
	{ "cken_jpeg", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_jpeg_p_clk_g", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "CFG_CG_JPEG", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_jpeg
	{ "lv_rst_jpeg", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_jpeg_p_clk_g", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_JPEG", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_jpeg
	{ "sw_rst_jpeg", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_jpeg_p_clk_g", 0x00000014, 8, 8, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_JPEG", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_venc
	{ "cken_venc", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_venc_p_clk_g", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "CFG_CG_VENC", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_venc
	{ "lv_rst_venc", 0x0000001C, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_venc_p_clk_g", 0x0000001C, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_VENC", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_venc
	{ "sw_rst_venc", 0x00000020, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_venc_p_clk_g", 0x00000020, 8, 8, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_VENC", 0x00000020, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_srcr
	{ "cken_srcr_k", 0x00000024, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_srcr_d", 0x00000024, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_srcr_p_clk_g", 0x00000024, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_SRCR", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_srcr
	{ "lv_rst_srcr_k", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_srcr_d", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_srcr_p_clk_g", 0x00000028, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_SRCR", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_srcr
	{ "sw_rst_srcr_k", 0x0000002C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_srcr_d", 0x0000002C, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_srcr_p_clk_g", 0x0000002C, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_SRCR", 0x0000002C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_bsw
	{ "cken_bsw_k", 0x00000030, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_bsw_d", 0x00000030, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_bsw_p_clk_g", 0x00000030, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_BSW", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_bsw
	{ "lv_rst_bsw_k", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_bsw_d", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_bsw_p_clk_g", 0x00000034, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_BSW", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_bsw
	{ "sw_rst_bsw_k", 0x00000038, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_bsw_d", 0x00000038, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_bsw_p_clk_g", 0x00000038, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_BSW", 0x00000038, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_osdr_0
	{ "cken_osdr_0_k", 0x0000003C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_osdr_0_d", 0x0000003C, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_osdr_0_p_clk_g", 0x0000003C, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_OSDR_0", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_osdr_0
	{ "lv_rst_osdr_0_k", 0x00000040, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_osdr_0_d", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_osdr_0_p_clk_g", 0x00000040, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_OSDR_0", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_osdr_0
	{ "sw_rst_osdr_0_k", 0x00000044, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_osdr_0_d", 0x00000044, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_osdr_0_p_clk_g", 0x00000044, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_OSDR_0", 0x00000044, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_osdr_1
	{ "cken_osdr_1_k", 0x00000048, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_osdr_1_d", 0x00000048, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_osdr_1_p_clk_g", 0x00000048, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_OSDR_1", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_osdr_1
	{ "lv_rst_osdr_1_k", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_osdr_1_d", 0x0000004C, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_osdr_1_p_clk_g", 0x0000004C, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_OSDR_1", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_osdr_1
	{ "sw_rst_osdr_1_k", 0x00000050, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_osdr_1_d", 0x00000050, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_osdr_1_p_clk_g", 0x00000050, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_OSDR_1", 0x00000050, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_refr
	{ "cken_refr_k", 0x00000054, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_refr_d", 0x00000054, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_refr_p_clk_g", 0x00000054, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_REFR", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_refr
	{ "lv_rst_refr_k", 0x00000058, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_refr_d", 0x00000058, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_refr_p_clk_g", 0x00000058, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_REFR", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_refr
	{ "sw_rst_refr_k", 0x0000005C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_refr_d", 0x0000005C, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_refr_p_clk_g", 0x0000005C, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_REFR", 0x0000005C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_refw
	{ "cken_refw_k", 0x00000060, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_refw_d", 0x00000060, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_refw_p_clk_g", 0x00000060, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_REFW", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_refw
	{ "lv_rst_refw_k", 0x00000064, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_refw_d", 0x00000064, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_refw_p_clk_g", 0x00000064, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_REFW", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_refw
	{ "sw_rst_refw_k", 0x00000068, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_refw_d", 0x00000068, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_refw_p_clk_g", 0x00000068, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_REFW", 0x00000068, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_cg_mvr
	{ "cken_mvr_k", 0x0000006C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_mvr_d", 0x0000006C, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_mvr_p_clk_g", 0x0000006C, 16, 16, CSR_RW, 0x00000001 },
	{ "CFG_CG_MVR", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_lv_rst_mvr
	{ "lv_rst_mvr_k", 0x00000070, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_mvr_d", 0x00000070, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_mvr_p_clk_g", 0x00000070, 16, 16, CSR_RW, 0x00000000 },
	{ "CFG_LV_RST_MVR", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_sw_rst_mvr
	{ "sw_rst_mvr_k", 0x00000074, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_mvr_d", 0x00000074, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_mvr_p_clk_g", 0x00000074, 16, 16, CSR_W1P, 0x00000000 },
	{ "CFG_SW_RST_MVR", 0x00000074, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ENC_SYSCFG_H_
