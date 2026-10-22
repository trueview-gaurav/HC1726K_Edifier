/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_IPLL_H_
#define CSR_TABLE_IPLL_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ipll[] = {
	// WORD ipll_enable0
	{ "rg_ipll_pll_rstb", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_pll_en", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_sscg_en", 0x00000000, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_ipll_frac_en", 0x00000000, 24, 24, CSR_RW, 0x00000000 },
	{ "IPLL_ENABLE0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_overwrite_enable
	{ "rg_ipll_kband_complete", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_zerostart", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_ic_ico", 0x00000004, 24, 24, CSR_RW, 0x00000000 },
	{ "IPLL_OVERWRITE_ENABLE", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_dig_en
	{ "rg_ipll_post_div1_en", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_post_div2_en", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_post_div3_en", 0x00000008, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_ipll_post_div4_halfdiv_en", 0x00000008, 24, 24, CSR_RW, 0x00000000 },
	{ "IPLL_DIG_EN", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_ref_gen
	{ "rg_ipll_v09_sel", 0x0000000C, 1, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_ref_iplus", 0x0000000C, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_ref_iminus", 0x0000000C, 16, 16, CSR_RW, 0x00000000 },
	{ "IPLL_REF_GEN", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_pfd_sel
	{ "rg_ipll_pfd_ckico_sel", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_pfd_clk_retimed_sel", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "IPLL_PFD_SEL", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_cp_sel
	{ "rg_ipll_ip_sel", 0x00000014, 3, 0, CSR_RW, 0x00000002 },
	{ "rg_ipll_ii_sel", 0x00000014, 11, 8, CSR_RW, 0x00000002 },
	{ "IPLL_CP_SEL", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_lf_sel
	{ "rg_ipll_rp_sel", 0x00000018, 3, 0, CSR_RW, 0x00000004 },
	{ "rg_ipll_ci_sel", 0x00000018, 9, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_cp_sel", 0x00000018, 17, 16, CSR_RW, 0x00000000 },
	{ "rg_ipll_pll_op_sel", 0x00000018, 27, 24, CSR_RW, 0x00000007 },
	{ "IPLL_LF_SEL", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_lpf_sel
	{ "rg_ipll_rlp_sel", 0x0000001C, 1, 0, CSR_RW, 0x00000001 },
	{ "rg_ipll_clp_sel", 0x0000001C, 9, 8, CSR_RW, 0x00000001 },
	{ "rg_ipll_rlp_sel_2", 0x0000001C, 17, 16, CSR_RW, 0x00000001 },
	{ "rg_ipll_clp_sel_2", 0x0000001C, 25, 24, CSR_RW, 0x00000001 },
	{ "IPLL_LPF_SEL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_kband_sel
	{ "rg_ipll_sq_bi_sel", 0x00000020, 4, 0, CSR_RW, 0x00000007 },
	{ "rg_ipll_enable_out_del_sel", 0x00000020, 9, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_freqm_count_ext_sel", 0x00000020, 18, 16, CSR_RW, 0x00000001 },
	{ "rg_ipll_pll_out_del_sel", 0x00000020, 25, 24, CSR_RW, 0x00000001 },
	{ "IPLL_KBAND_SEL", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_div_sel
	{ "rg_ipll_ref_div_sel", 0x00000024, 1, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_ffb_prediv_sel", 0x00000024, 6, 4, CSR_RW, 0x00000001 },
	{ "rg_ipll_ffb_halfdiv_sel", 0x00000024, 9, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_ffb_intdiv_sel", 0x00000024, 23, 16, CSR_RW, 0x00000001 },
	{ "IPLL_DIV_SEL", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_post_div_sel
	{ "rg_ipll_post_div1_sel", 0x00000028, 7, 0, CSR_RW, 0x00000001 },
	{ "rg_ipll_post_div2_sel", 0x00000028, 15, 8, CSR_RW, 0x00000001 },
	{ "rg_ipll_post_div3_sel", 0x00000028, 23, 16, CSR_RW, 0x00000001 },
	{ "rg_ipll_post_div4_halfdiv_sel", 0x00000028, 25, 24, CSR_RW, 0x00000000 },
	{ "IPLL_POST_DIV_SEL", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_postdiv_clkin_sel
	{ "rg_ipll_postdiv_clkin_sel_1", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_postdiv_clkin_sel_2", 0x0000002C, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_postdiv_clkin_sel_3", 0x0000002C, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_ipll_postdiv_clkin_sel_4", 0x0000002C, 24, 24, CSR_RW, 0x00000000 },
	{ "IPLL_POSTDIV_CLKIN_SEL", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_ckico_bypass
	{ "rg_ipll_ad_ckico_bypass", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "IPLL_CKICO_BYPASS", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_postdiv_bypass
	{ "rg_ipll_ad_ckpostdiv4_bypass", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_ad_ckpostdiv1_bypass", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_ad_ckpostdiv2_bypass", 0x00000034, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_ipll_ad_ckpostdiv3_bypass", 0x00000034, 24, 24, CSR_RW, 0x00000000 },
	{ "IPLL_POSTDIV_BYPASS", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_overwrite
	{ "rg_ipll_band", 0x00000038, 5, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_control_sel", 0x00000038, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_ipll_digital_control_sel", 0x00000038, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_ipll_ico_sel", 0x00000038, 24, 24, CSR_RW, 0x00000000 },
	{ "IPLL_OVERWRITE", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_mon_clk_sel
	{ "rg_ipll_mon_en", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_ipll_mon_clk_sel", 0x0000003C, 10, 8, CSR_RW, 0x00000000 },
	{ "IPLL_MON_CLK_SEL", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_reserved
	{ "rg_ipll_reserved", 0x00000040, 15, 0, CSR_RW, 0x00000000 },
	{ "IPLL_RESERVED", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD ipll_rgs_enable0
	{ "rgs_ipll_ldo_bias_en_d", 0x00000044, 0, 0, CSR_RO, 0x00000000 },
	{ "rgs_ipll_ldo_out_en_d", 0x00000044, 8, 8, CSR_RO, 0x00000000 },
	{ "rgs_ipll_ic_ico_en_d", 0x00000044, 16, 16, CSR_RO, 0x00000000 },
	{ "rgs_ipll_kband_en_d", 0x00000044, 24, 24, CSR_RO, 0x00000000 },
	{ "IPLL_RGS_ENABLE0", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD ipll_rgs_enable1
	{ "rgs_ipll_kband_complete_mux_d", 0x00000048, 0, 0, CSR_RO, 0x00000000 },
	{ "rgs_ipll_zerostart_mux_d", 0x00000048, 8, 8, CSR_RO, 0x00000000 },
	{ "rgs_ipll_pll_out_d", 0x00000048, 16, 16, CSR_RO, 0x00000000 },
	{ "rgs_ipll_band_mux_d", 0x00000048, 29, 24, CSR_RO, 0x00000000 },
	{ "IPLL_RGS_ENABLE1", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD ipll_ref_clk_sel
	{ "pll_ref_clk_sel", 0x0000004C, 1, 0, CSR_RW, 0x00000000 },
	{ "IPLL_REF_CLK_SEL", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_IPLL_H_
