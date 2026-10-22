/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ISP_CFG_H_
#define CSR_TABLE_ISP_CFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_isp_cfg[] = {
	// WORD ispr0_rw_k
	{ "cken_ispr0_k", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ispr0_k", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "ISPR0_RW_K", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispr0_w1p_k
	{ "sw_rst_ispr0_k", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "ISPR0_W1P_K", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ispr0_wr_d
	{ "cken_ispr0_d", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ispr0_d", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "ISPR0_WR_D", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispr0_w1p_d
	{ "sw_rst_ispr0_d", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "ISPR0_W1P_D", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ispr0_rw_p
	{ "cken_ispr0_p_clk_g", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ispr0_p_clk_g", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "ISPR0_RW_P", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispr0_w1p_p
	{ "sw_rst_ispr0_p_clk_g", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "ISPR0_W1P_P", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ispr1_rw_k
	{ "cken_ispr1_k", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ispr1_k", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "ISPR1_RW_K", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispr1_w1p_k
	{ "sw_rst_ispr1_k", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "ISPR1_W1P_K", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ispr1_wr_d
	{ "cken_ispr1_d", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ispr1_d", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "ISPR1_WR_D", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispr1_w1p_d
	{ "sw_rst_ispr1_d", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "ISPR1_W1P_D", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ispr1_rw_p
	{ "cken_ispr1_p_clk_g", 0x00000028, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ispr1_p_clk_g", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "ISPR1_RW_P", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispr1_w1p_p
	{ "sw_rst_ispr1_p_clk_g", 0x0000002C, 0, 0, CSR_W1P, 0x00000000 },
	{ "ISPR1_W1P_P", 0x0000002C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD gfx0_rw_k
	{ "cken_gfx0_k", 0x00000030, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_gfx0_k", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "GFX0_RW_K", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx0_w1p_k
	{ "sw_rst_gfx0_k", 0x00000034, 0, 0, CSR_W1P, 0x00000000 },
	{ "GFX0_W1P_K", 0x00000034, 31, 0, CSR_W1P, 0x00000000 },
	// WORD gfx0_wr_d
	{ "cken_gfx0_d", 0x00000038, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_gfx0_d", 0x00000038, 8, 8, CSR_RW, 0x00000000 },
	{ "GFX0_WR_D", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx0_w1p_d
	{ "sw_rst_gfx0_d", 0x0000003C, 0, 0, CSR_W1P, 0x00000000 },
	{ "GFX0_W1P_D", 0x0000003C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD gfx0_rw_p
	{ "cken_gfx0_p_clk_g", 0x00000040, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_gfx0_p_clk_g", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "GFX0_RW_P", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD gfx0_w1p_p
	{ "sw_rst_gfx0_p_clk_g", 0x00000044, 0, 0, CSR_W1P, 0x00000000 },
	{ "GFX0_W1P_P", 0x00000044, 31, 0, CSR_W1P, 0x00000000 },
	// WORD bld_rw_k
	{ "cken_bld_k", 0x00000048, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_bld_k", 0x00000048, 8, 8, CSR_RW, 0x00000000 },
	{ "BLD_RW_K", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld_w1p_k
	{ "sw_rst_bld_k", 0x0000004C, 0, 0, CSR_W1P, 0x00000000 },
	{ "BLD_W1P_K", 0x0000004C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD bld_wr_d
	{ "cken_bld_d", 0x00000050, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_bld_d", 0x00000050, 8, 8, CSR_RW, 0x00000000 },
	{ "BLD_WR_D", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld_w1p_d
	{ "sw_rst_bld_d", 0x00000054, 0, 0, CSR_W1P, 0x00000000 },
	{ "BLD_W1P_D", 0x00000054, 31, 0, CSR_W1P, 0x00000000 },
	// WORD bld_rw_p
	{ "cken_bld_p_clk_g", 0x00000058, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_bld_p_clk_g", 0x00000058, 8, 8, CSR_RW, 0x00000000 },
	{ "BLD_RW_P", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld_w1p_p
	{ "sw_rst_bld_p_clk_g", 0x0000005C, 0, 0, CSR_W1P, 0x00000000 },
	{ "BLD_W1P_P", 0x0000005C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pg0_rw_k
	{ "cken_pg0_k", 0x00000060, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_pg0_k", 0x00000060, 8, 8, CSR_RW, 0x00000000 },
	{ "PG0_RW_K", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD pg0_w1p_k
	{ "sw_rst_pg0_k", 0x00000064, 0, 0, CSR_W1P, 0x00000000 },
	{ "PG0_W1P_K", 0x00000064, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pg0_rw_p
	{ "cken_pg0_p_clk_g", 0x00000068, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_pg0_p_clk_g", 0x00000068, 8, 8, CSR_RW, 0x00000000 },
	{ "PG0_RW_P", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD pg0_w1p_p
	{ "sw_rst_pg0_p_clk_g", 0x0000006C, 0, 0, CSR_W1P, 0x00000000 },
	{ "PG0_W1P_P", 0x0000006C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pg1_rw_k
	{ "cken_pg1_k", 0x00000070, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_pg1_k", 0x00000070, 8, 8, CSR_RW, 0x00000000 },
	{ "PG1_RW_K", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD pg1_w1p_k
	{ "sw_rst_pg1_k", 0x00000074, 0, 0, CSR_W1P, 0x00000000 },
	{ "PG1_W1P_K", 0x00000074, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pg1_rw_p
	{ "cken_pg1_p_clk_g", 0x00000078, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_pg1_p_clk_g", 0x00000078, 8, 8, CSR_RW, 0x00000000 },
	{ "PG1_RW_P", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD pg1_w1p_p
	{ "sw_rst_pg1_p_clk_g", 0x0000007C, 0, 0, CSR_W1P, 0x00000000 },
	{ "PG1_W1P_P", 0x0000007C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cs0_rw_k
	{ "cken_cs0_k", 0x00000080, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_cs0_k", 0x00000080, 8, 8, CSR_RW, 0x00000000 },
	{ "CS0_RW_K", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs0_w1p_k
	{ "sw_rst_cs0_k", 0x00000084, 0, 0, CSR_W1P, 0x00000000 },
	{ "CS0_W1P_K", 0x00000084, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cs0_rw_p
	{ "cken_cs0_p_clk_g", 0x00000088, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_cs0_p_clk_g", 0x00000088, 8, 8, CSR_RW, 0x00000000 },
	{ "CS0_RW_P", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs0_w1p_p
	{ "sw_rst_cs0_p_clk_g", 0x0000008C, 0, 0, CSR_W1P, 0x00000000 },
	{ "CS0_W1P_P", 0x0000008C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cs1_rw_k
	{ "cken_cs1_k", 0x00000090, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_cs1_k", 0x00000090, 8, 8, CSR_RW, 0x00000000 },
	{ "CS1_RW_K", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs1_w1p_k
	{ "sw_rst_cs1_k", 0x00000094, 0, 0, CSR_W1P, 0x00000000 },
	{ "CS1_W1P_K", 0x00000094, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cs1_rw_p
	{ "cken_cs1_p_clk_g", 0x00000098, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_cs1_p_clk_g", 0x00000098, 8, 8, CSR_RW, 0x00000000 },
	{ "CS1_RW_P", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD cs1_w1p_p
	{ "sw_rst_cs1_p_clk_g", 0x0000009C, 0, 0, CSR_W1P, 0x00000000 },
	{ "CS1_W1P_P", 0x0000009C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD hdr_rw_k
	{ "cken_hdr_k", 0x000000A0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_hdr_k", 0x000000A0, 8, 8, CSR_RW, 0x00000000 },
	{ "HDR_RW_K", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr_w1p_k
	{ "sw_rst_hdr_k", 0x000000A4, 0, 0, CSR_W1P, 0x00000000 },
	{ "HDR_W1P_K", 0x000000A4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD hdr_rw_p
	{ "cken_hdr_p_clk_g", 0x000000A8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_hdr_p_clk_g", 0x000000A8, 8, 8, CSR_RW, 0x00000000 },
	{ "HDR_RW_P", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr_w1p_p
	{ "sw_rst_hdr_p_clk_g", 0x000000AC, 0, 0, CSR_W1P, 0x00000000 },
	{ "HDR_W1P_P", 0x000000AC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD rgbp_rw_k
	{ "cken_rgbp_k", 0x000000B0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_rgbp_k", 0x000000B0, 8, 8, CSR_RW, 0x00000000 },
	{ "RGBP_RW_K", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_w1p_k
	{ "sw_rst_rgbp_k", 0x000000B4, 0, 0, CSR_W1P, 0x00000000 },
	{ "RGBP_W1P_K", 0x000000B4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD rgbp_rw_p
	{ "cken_rgbp_p_clk_g", 0x000000B8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_rgbp_p_clk_g", 0x000000B8, 8, 8, CSR_RW, 0x00000000 },
	{ "RGBP_RW_P", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_w1p_p
	{ "sw_rst_rgbp_p_clk_g", 0x000000BC, 0, 0, CSR_W1P, 0x00000000 },
	{ "RGBP_W1P_P", 0x000000BC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD nr2d_rw_k
	{ "cken_nr2d_k", 0x000000C0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_nr2d_k", 0x000000C0, 8, 8, CSR_RW, 0x00000000 },
	{ "NR2D_RW_K", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_w1p_k
	{ "sw_rst_nr2d_k", 0x000000C4, 0, 0, CSR_W1P, 0x00000000 },
	{ "NR2D_W1P_K", 0x000000C4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD nr2d_rw_p
	{ "cken_nr2d_p_clk_g", 0x000000C8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_nr2d_p_clk_g", 0x000000C8, 8, 8, CSR_RW, 0x00000000 },
	{ "NR2D_RW_P", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_w1p_p
	{ "sw_rst_nr2d_p_clk_g", 0x000000CC, 0, 0, CSR_W1P, 0x00000000 },
	{ "NR2D_W1P_P", 0x000000CC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ccm_rw_k
	{ "cken_ccm_k", 0x000000D0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ccm_k", 0x000000D0, 8, 8, CSR_RW, 0x00000000 },
	{ "CCM_RW_K", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD ccm_w1p_k
	{ "sw_rst_ccm_k", 0x000000D4, 0, 0, CSR_W1P, 0x00000000 },
	{ "CCM_W1P_K", 0x000000D4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ccm_rw_p
	{ "cken_ccm_p_clk_g", 0x000000D8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ccm_p_clk_g", 0x000000D8, 8, 8, CSR_RW, 0x00000000 },
	{ "CCM_RW_P", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD ccm_w1p_p
	{ "sw_rst_ccm_p_clk_g", 0x000000DC, 0, 0, CSR_W1P, 0x00000000 },
	{ "CCM_W1P_P", 0x000000DC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD shp_rw_k
	{ "cken_shp_k", 0x000000E0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_shp_k", 0x000000E0, 8, 8, CSR_RW, 0x00000000 },
	{ "SHP_RW_K", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_w1p_k
	{ "sw_rst_shp_k", 0x000000E4, 0, 0, CSR_W1P, 0x00000000 },
	{ "SHP_W1P_K", 0x000000E4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD shp_rw_p
	{ "cken_shp_p_clk_g", 0x000000E8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_shp_p_clk_g", 0x000000E8, 8, 8, CSR_RW, 0x00000000 },
	{ "SHP_RW_P", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_w1p_p
	{ "sw_rst_shp_p_clk_g", 0x000000EC, 0, 0, CSR_W1P, 0x00000000 },
	{ "SHP_W1P_P", 0x000000EC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD sc_rw_k
	{ "cken_sc_k", 0x000000F0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_sc_k", 0x000000F0, 8, 8, CSR_RW, 0x00000000 },
	{ "SC_RW_K", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_w1p_k
	{ "sw_rst_sc_k", 0x000000F4, 0, 0, CSR_W1P, 0x00000000 },
	{ "SC_W1P_K", 0x000000F4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD sc_rw_p
	{ "cken_sc_p_clk_g", 0x000000F8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_sc_p_clk_g", 0x000000F8, 8, 8, CSR_RW, 0x00000000 },
	{ "SC_RW_P", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_w1p_p
	{ "sw_rst_sc_p_clk_g", 0x000000FC, 0, 0, CSR_W1P, 0x00000000 },
	{ "SC_W1P_P", 0x000000FC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pca_rw_k
	{ "cken_pca_k", 0x00000100, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_pca_k", 0x00000100, 8, 8, CSR_RW, 0x00000000 },
	{ "PCA_RW_K", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD pca_w1p_k
	{ "sw_rst_pca_k", 0x00000104, 0, 0, CSR_W1P, 0x00000000 },
	{ "PCA_W1P_K", 0x00000104, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pca_rw_p
	{ "cken_pca_p_clk_g", 0x00000108, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_pca_p_clk_g", 0x00000108, 8, 8, CSR_RW, 0x00000000 },
	{ "PCA_RW_P", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD pca_w1p_p
	{ "sw_rst_pca_p_clk_g", 0x0000010C, 0, 0, CSR_W1P, 0x00000000 },
	{ "PCA_W1P_P", 0x0000010C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cus_rw_k
	{ "cken_cus_k", 0x00000110, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_cus_k", 0x00000110, 8, 8, CSR_RW, 0x00000000 },
	{ "CUS_RW_K", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_w1p_k
	{ "sw_rst_cus_k", 0x00000114, 0, 0, CSR_W1P, 0x00000000 },
	{ "CUS_W1P_K", 0x00000114, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cus_rw_p
	{ "cken_cus_p_clk_g", 0x00000118, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_cus_p_clk_g", 0x00000118, 8, 8, CSR_RW, 0x00000000 },
	{ "CUS_RW_P", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_w1p_p
	{ "sw_rst_cus_p_clk_g", 0x0000011C, 0, 0, CSR_W1P, 0x00000000 },
	{ "CUS_W1P_P", 0x0000011C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cds_rw_k
	{ "cken_cds_k", 0x00000120, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_cds_k", 0x00000120, 8, 8, CSR_RW, 0x00000000 },
	{ "CDS_RW_K", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_w1p_k
	{ "sw_rst_cds_k", 0x00000124, 0, 0, CSR_W1P, 0x00000000 },
	{ "CDS_W1P_K", 0x00000124, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cds_rw_p
	{ "cken_cds_p_clk_g", 0x00000128, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_cds_p_clk_g", 0x00000128, 8, 8, CSR_RW, 0x00000000 },
	{ "CDS_RW_P", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_w1p_p
	{ "sw_rst_cds_p_clk_g", 0x0000012C, 0, 0, CSR_W1P, 0x00000000 },
	{ "CDS_W1P_P", 0x0000012C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ctrl_rw_k
	{ "cken_ctrl_k", 0x00000130, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ctrl_k", 0x00000130, 8, 8, CSR_RW, 0x00000000 },
	{ "CTRL_RW_K", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl_w1p_k
	{ "sw_rst_ctrl_k", 0x00000134, 0, 0, CSR_W1P, 0x00000000 },
	{ "CTRL_W1P_K", 0x00000134, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ISP_CFG_H_
