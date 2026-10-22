/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_VP_CFG_H_
#define CSR_TABLE_VP_CFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_vp_cfg[] = {
	// WORD dhz_rw_k
	{ "cken_dhz_k", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dhz_k", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "DHZ_RW_K", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD dhz_w1p_k
	{ "sw_rst_dhz_k", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "DHZ_W1P_K", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dhz_rw_p
	{ "cken_dhz_p_clk_g", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dhz_p_clk_g", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "DHZ_RW_P", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD dhz_w1p_p
	{ "sw_rst_dhz_p_clk_g", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "DHZ_W1P_P", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mcvp_rw_k
	{ "cken_mcvp_k", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mcvp_k", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "MCVP_RW_K", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp_w1p_k
	{ "sw_rst_mcvp_k", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "MCVP_W1P_K", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mcvp_rw_p
	{ "cken_mcvp_p_clk_g", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mcvp_p_clk_g", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "MCVP_RW_P", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp_w1p_p
	{ "sw_rst_mcvp_p_clk_g", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "MCVP_W1P_P", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mer_rw_k
	{ "cken_mer_k", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mer_k", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "MER_RW_K", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD mer_w1p_k
	{ "sw_rst_mer_k", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "MER_W1P_K", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mer_wr_d
	{ "cken_mer_d", 0x00000028, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mer_d", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "MER_WR_D", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD mer_w1p_d
	{ "sw_rst_mer_d", 0x0000002C, 0, 0, CSR_W1P, 0x00000000 },
	{ "MER_W1P_D", 0x0000002C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mer_rw_p
	{ "cken_mer_p_clk_g", 0x00000030, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mer_p_clk_g", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "MER_RW_P", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD mer_w1p_p
	{ "sw_rst_mer_p_clk_g", 0x00000034, 0, 0, CSR_W1P, 0x00000000 },
	{ "MER_W1P_P", 0x00000034, 31, 0, CSR_W1P, 0x00000000 },
	// WORD nrw_rw_k
	{ "cken_nrw_k", 0x00000038, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_nrw_k", 0x00000038, 8, 8, CSR_RW, 0x00000000 },
	{ "NRW_RW_K", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD nrw_w1p_k
	{ "sw_rst_nrw_k", 0x0000003C, 0, 0, CSR_W1P, 0x00000000 },
	{ "NRW_W1P_K", 0x0000003C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD nrw_wr_d
	{ "cken_nrw_d", 0x00000040, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_nrw_d", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "NRW_WR_D", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD nrw_w1p_d
	{ "sw_rst_nrw_d", 0x00000044, 0, 0, CSR_W1P, 0x00000000 },
	{ "NRW_W1P_D", 0x00000044, 31, 0, CSR_W1P, 0x00000000 },
	// WORD nrw_rw_p
	{ "cken_nrw_p_clk_g", 0x00000048, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_nrw_p_clk_g", 0x00000048, 8, 8, CSR_RW, 0x00000000 },
	{ "NRW_RW_P", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD nrw_w1p_p
	{ "sw_rst_nrw_p_clk_g", 0x0000004C, 0, 0, CSR_W1P, 0x00000000 },
	{ "NRW_W1P_P", 0x0000004C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mv8r_rw_k
	{ "cken_mv8r_k", 0x00000050, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mv8r_k", 0x00000050, 8, 8, CSR_RW, 0x00000000 },
	{ "MV8R_RW_K", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD mv8r_w1p_k
	{ "sw_rst_mv8r_k", 0x00000054, 0, 0, CSR_W1P, 0x00000000 },
	{ "MV8R_W1P_K", 0x00000054, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mv8r_wr_d
	{ "cken_mv8r_d", 0x00000058, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mv8r_d", 0x00000058, 8, 8, CSR_RW, 0x00000000 },
	{ "MV8R_WR_D", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD mv8r_w1p_d
	{ "sw_rst_mv8r_d", 0x0000005C, 0, 0, CSR_W1P, 0x00000000 },
	{ "MV8R_W1P_D", 0x0000005C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mv8r_rw_p
	{ "cken_mv8r_p_clk_g", 0x00000060, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mv8r_p_clk_g", 0x00000060, 8, 8, CSR_RW, 0x00000000 },
	{ "MV8R_RW_P", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD mv8r_w1p_p
	{ "sw_rst_mv8r_p_clk_g", 0x00000064, 0, 0, CSR_W1P, 0x00000000 },
	{ "MV8R_W1P_P", 0x00000064, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mv8w_rw_k
	{ "cken_mv8w_k", 0x00000068, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mv8w_k", 0x00000068, 8, 8, CSR_RW, 0x00000000 },
	{ "MV8W_RW_K", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD mv8w_w1p_k
	{ "sw_rst_mv8w_k", 0x0000006C, 0, 0, CSR_W1P, 0x00000000 },
	{ "MV8W_W1P_K", 0x0000006C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mv8w_wr_d
	{ "cken_mv8w_d", 0x00000070, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mv8w_d", 0x00000070, 8, 8, CSR_RW, 0x00000000 },
	{ "MV8W_WR_D", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD mv8w_w1p_d
	{ "sw_rst_mv8w_d", 0x00000074, 0, 0, CSR_W1P, 0x00000000 },
	{ "MV8W_W1P_D", 0x00000074, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mv8w_rw_p
	{ "cken_mv8w_p_clk_g", 0x00000078, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_mv8w_p_clk_g", 0x00000078, 8, 8, CSR_RW, 0x00000000 },
	{ "MV8W_RW_P", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD mv8w_w1p_p
	{ "sw_rst_mv8w_p_clk_g", 0x0000007C, 0, 0, CSR_W1P, 0x00000000 },
	{ "MV8W_W1P_P", 0x0000007C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD venc_mvw_rw_k
	{ "cken_venc_mvw_k", 0x00000080, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_venc_mvw_k", 0x00000080, 8, 8, CSR_RW, 0x00000000 },
	{ "VENC_MVW_RW_K", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mvw_w1p_k
	{ "sw_rst_venc_mvw_k", 0x00000084, 0, 0, CSR_W1P, 0x00000000 },
	{ "VENC_MVW_W1P_K", 0x00000084, 31, 0, CSR_W1P, 0x00000000 },
	// WORD venc_mvw_wr_d
	{ "cken_venc_mvw_d", 0x00000088, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_venc_mvw_d", 0x00000088, 8, 8, CSR_RW, 0x00000000 },
	{ "VENC_MVW_WR_D", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mvw_w1p_d
	{ "sw_rst_venc_mvw_d", 0x0000008C, 0, 0, CSR_W1P, 0x00000000 },
	{ "VENC_MVW_W1P_D", 0x0000008C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD venc_mvw_rw_p
	{ "cken_venc_mvw_p_clk_g", 0x00000090, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_venc_mvw_p_clk_g", 0x00000090, 8, 8, CSR_RW, 0x00000000 },
	{ "VENC_MVW_RW_P", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD venc_mvw_w1p_p
	{ "sw_rst_venc_mvw_p_clk_g", 0x00000094, 0, 0, CSR_W1P, 0x00000000 },
	{ "VENC_MVW_W1P_P", 0x00000094, 31, 0, CSR_W1P, 0x00000000 },
	// WORD unpacker_rw_k
	{ "cken_unpacker_k", 0x00000098, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_unpacker_k", 0x00000098, 8, 8, CSR_RW, 0x00000000 },
	{ "UNPACKER_RW_K", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD unpacker_w1p_k
	{ "sw_rst_unpacker_k", 0x0000009C, 0, 0, CSR_W1P, 0x00000000 },
	{ "UNPACKER_W1P_K", 0x0000009C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD b2r_rw_k
	{ "cken_b2r_k", 0x000000A0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_b2r_k", 0x000000A0, 8, 8, CSR_RW, 0x00000000 },
	{ "B2R_RW_K", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD b2r_w1p_k
	{ "sw_rst_b2r_k", 0x000000A4, 0, 0, CSR_W1P, 0x00000000 },
	{ "B2R_W1P_K", 0x000000A4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD b2r_rw_p
	{ "cken_b2r_p_clk_g", 0x000000A8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_b2r_p_clk_g", 0x000000A8, 8, 8, CSR_RW, 0x00000000 },
	{ "B2R_RW_P", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD b2r_w1p_p
	{ "sw_rst_b2r_p_clk_g", 0x000000AC, 0, 0, CSR_W1P, 0x00000000 },
	{ "B2R_W1P_P", 0x000000AC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vppup_rw_k
	{ "cken_vppup_k", 0x000000B0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vppup_k", 0x000000B0, 8, 8, CSR_RW, 0x00000000 },
	{ "VPPUP_RW_K", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD vppup_w1p_k
	{ "sw_rst_vppup_k", 0x000000B4, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPPUP_W1P_K", 0x000000B4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vppup_rw_p
	{ "cken_vppup_p_clk_g", 0x000000B8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vppup_p_clk_g", 0x000000B8, 8, 8, CSR_RW, 0x00000000 },
	{ "VPPUP_RW_P", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD vppup_w1p_p
	{ "sw_rst_vppup_p_clk_g", 0x000000BC, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPPUP_W1P_P", 0x000000BC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vplp_rw_k
	{ "cken_vplp_k", 0x000000C0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vplp_k", 0x000000C0, 8, 8, CSR_RW, 0x00000000 },
	{ "VPLP_RW_K", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD vplp_w1p_k
	{ "sw_rst_vplp_k", 0x000000C4, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPLP_W1P_K", 0x000000C4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vplp_rw_p
	{ "cken_vplp_p_clk_g", 0x000000C8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vplp_p_clk_g", 0x000000C8, 8, 8, CSR_RW, 0x00000000 },
	{ "VPLP_RW_P", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD vplp_w1p_p
	{ "sw_rst_vplp_p_clk_g", 0x000000CC, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPLP_W1P_P", 0x000000CC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw0_rw_k
	{ "cken_vpw0_k", 0x000000D0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw0_k", 0x000000D0, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW0_RW_K", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw0_w1p_k
	{ "sw_rst_vpw0_k", 0x000000D4, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW0_W1P_K", 0x000000D4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw0_wr_d
	{ "cken_vpw0_d", 0x000000D8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw0_d", 0x000000D8, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW0_WR_D", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw0_w1p_d
	{ "sw_rst_vpw0_d", 0x000000DC, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW0_W1P_D", 0x000000DC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw0_rw_p
	{ "cken_vpw0_p_clk_g", 0x000000E0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw0_p_clk_g", 0x000000E0, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW0_RW_P", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw0_w1p_p
	{ "sw_rst_vpw0_p_clk_g", 0x000000E4, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW0_W1P_P", 0x000000E4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw1_rw_k
	{ "cken_vpw1_k", 0x000000E8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw1_k", 0x000000E8, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW1_RW_K", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw1_w1p_k
	{ "sw_rst_vpw1_k", 0x000000EC, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW1_W1P_K", 0x000000EC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw1_wr_d
	{ "cken_vpw1_d", 0x000000F0, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw1_d", 0x000000F0, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW1_WR_D", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw1_w1p_d
	{ "sw_rst_vpw1_d", 0x000000F4, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW1_W1P_D", 0x000000F4, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw1_rw_p
	{ "cken_vpw1_p_clk_g", 0x000000F8, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw1_p_clk_g", 0x000000F8, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW1_RW_P", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw1_w1p_p
	{ "sw_rst_vpw1_p_clk_g", 0x000000FC, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW1_W1P_P", 0x000000FC, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw2_rw_k
	{ "cken_vpw2_k", 0x00000100, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw2_k", 0x00000100, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW2_RW_K", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw2_w1p_k
	{ "sw_rst_vpw2_k", 0x00000104, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW2_W1P_K", 0x00000104, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw2_wr_d
	{ "cken_vpw2_d", 0x00000108, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw2_d", 0x00000108, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW2_WR_D", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw2_w1p_d
	{ "sw_rst_vpw2_d", 0x0000010C, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW2_W1P_D", 0x0000010C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD vpw2_rw_p
	{ "cken_vpw2_p_clk_g", 0x00000110, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_vpw2_p_clk_g", 0x00000110, 8, 8, CSR_RW, 0x00000000 },
	{ "VPW2_RW_P", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw2_w1p_p
	{ "sw_rst_vpw2_p_clk_g", 0x00000114, 0, 0, CSR_W1P, 0x00000000 },
	{ "VPW2_W1P_P", 0x00000114, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ctrl_rw_k
	{ "cken_ctrl_k", 0x00000118, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_ctrl_k", 0x00000118, 8, 8, CSR_RW, 0x00000000 },
	{ "CTRL_RW_K", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl_w1p_k
	{ "sw_rst_ctrl_k", 0x0000011C, 0, 0, CSR_W1P, 0x00000000 },
	{ "CTRL_W1P_K", 0x0000011C, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_VP_CFG_H_
