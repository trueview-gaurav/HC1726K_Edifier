/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_TX_PHYCFG_H_
#define CSR_BANK_TX_PHYCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from tx_phycfg  ***/
typedef struct csr_bank_tx_phycfg {
	/* MIPI_TX_PHY00 10'h000 */
	union {
		uint32_t mipi_tx_phy00; // word name
		struct {
			uint32_t rg_mipi_tx_ck2p5g_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY01 10'h004 */
	union {
		uint32_t mipi_tx_phy01; // word name
		struct {
			uint32_t rg_mipi_tx_lev09_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_ref09_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_ref09_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY02 10'h008 */
	union {
		uint32_t mipi_tx_phy02; // word name
		struct {
			uint32_t rg_mipi_tx_lprx_lpf_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_lprx__cd_vth_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_lprx_disp_vth_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY03 10'h00C */
	union {
		uint32_t mipi_tx_phy03; // word name
		struct {
			uint32_t rg_mipi_tx_ln0_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY04 10'h010 */
	union {
		uint32_t mipi_tx_phy04; // word name
		struct {
			uint32_t rg_mipi_tx_ln0_gpo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY05 10'h014 */
	union {
		uint32_t mipi_tx_phy05; // word name
		struct {
			uint32_t rg_mipi_tx_ln0_ref_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln0_ref_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY06 10'h018 */
	union {
		uint32_t mipi_tx_phy06; // word name
		struct {
			uint32_t rg_mipi_tx_ln0_hs_rminus : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln0_hs_rplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY07 10'h01C */
	union {
		uint32_t mipi_tx_phy07; // word name
		struct {
			uint32_t rg_mipi_tx_ln0_lp_rminus : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_ln0_lp_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_ln0_lp_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY08 10'h020 */
	union {
		uint32_t mipi_tx_phy08; // word name
		struct {
			uint32_t rg_mipi_tx_ln0_lev04_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln0_lev12_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY09 10'h024 */
	union {
		uint32_t mipi_tx_phy09; // word name
		struct {
			uint32_t rg_mipi_tx_ln1_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY10 10'h028 */
	union {
		uint32_t mipi_tx_phy10; // word name
		struct {
			uint32_t rg_mipi_tx_ln1_gpo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY11 10'h02C */
	union {
		uint32_t mipi_tx_phy11; // word name
		struct {
			uint32_t rg_mipi_tx_ln1_ref_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln1_ref_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY12 10'h030 */
	union {
		uint32_t mipi_tx_phy12; // word name
		struct {
			uint32_t rg_mipi_tx_ln1_hs_rminus : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln1_hs_rplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY13 10'h034 */
	union {
		uint32_t mipi_tx_phy13; // word name
		struct {
			uint32_t rg_mipi_tx_ln1_lp_rminus : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_ln1_lp_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_ln1_lp_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY14 10'h038 */
	union {
		uint32_t mipi_tx_phy14; // word name
		struct {
			uint32_t rg_mipi_tx_ln1_lev04_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln1_lev12_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY15 10'h03C */
	union {
		uint32_t mipi_tx_phy15; // word name
		struct {
			uint32_t rg_mipi_tx_ln2_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY16 10'h040 */
	union {
		uint32_t mipi_tx_phy16; // word name
		struct {
			uint32_t rg_mipi_tx_ln2_gpo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY17 10'h044 */
	union {
		uint32_t mipi_tx_phy17; // word name
		struct {
			uint32_t rg_mipi_tx_ln2_ref_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln2_ref_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY18 10'h048 */
	union {
		uint32_t mipi_tx_phy18; // word name
		struct {
			uint32_t rg_mipi_tx_ln2_hs_rminus : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln2_hs_rplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY19 10'h04C */
	union {
		uint32_t mipi_tx_phy19; // word name
		struct {
			uint32_t rg_mipi_tx_ln2_lp_rminus : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_ln2_lp_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_ln2_lp_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY20 10'h050 */
	union {
		uint32_t mipi_tx_phy20; // word name
		struct {
			uint32_t rg_mipi_tx_ln2_lev04_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln2_lev12_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY21 10'h054 */
	union {
		uint32_t mipi_tx_phy21; // word name
		struct {
			uint32_t rg_mipi_tx_ln3_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY22 10'h058 */
	union {
		uint32_t mipi_tx_phy22; // word name
		struct {
			uint32_t rg_mipi_tx_ln3_gpo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY23 10'h05C */
	union {
		uint32_t mipi_tx_phy23; // word name
		struct {
			uint32_t rg_mipi_tx_ln3_ref_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln3_ref_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY24 10'h060 */
	union {
		uint32_t mipi_tx_phy24; // word name
		struct {
			uint32_t rg_mipi_tx_ln3_hs_rminus : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln3_hs_rplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY25 10'h064 */
	union {
		uint32_t mipi_tx_phy25; // word name
		struct {
			uint32_t rg_mipi_tx_ln3_lp_rminus : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_ln3_lp_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_ln3_lp_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY26 10'h068 */
	union {
		uint32_t mipi_tx_phy26; // word name
		struct {
			uint32_t rg_mipi_tx_ln3_lev04_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln3_lev12_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY27 10'h06C */
	union {
		uint32_t mipi_tx_phy27; // word name
		struct {
			uint32_t rg_mipi_tx_ln4_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY28 10'h070 */
	union {
		uint32_t mipi_tx_phy28; // word name
		struct {
			uint32_t rg_mipi_tx_ln4_gpo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY29 10'h074 */
	union {
		uint32_t mipi_tx_phy29; // word name
		struct {
			uint32_t rg_mipi_tx_ln4_ref_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln4_ref_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY30 10'h078 */
	union {
		uint32_t mipi_tx_phy30; // word name
		struct {
			uint32_t rg_mipi_tx_ln4_hs_rminus : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln4_hs_rplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY31 10'h07C */
	union {
		uint32_t mipi_tx_phy31; // word name
		struct {
			uint32_t rg_mipi_tx_ln4_lp_rminus : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_ln4_lp_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_ln4_lp_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY32 10'h080 */
	union {
		uint32_t mipi_tx_phy32; // word name
		struct {
			uint32_t rg_mipi_tx_ln4_lev04_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_mipi_tx_ln4_lev12_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY33 10'h084 */
	union {
		uint32_t mipi_tx_phy33; // word name
		struct {
			uint32_t rg_mipi_tx_reserved : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_PHY34 10'h088 */
	union {
		uint32_t mipi_tx_phy34; // word name
		struct {
			uint32_t rg_mipi_tx_lane_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_FPLL_ENABLE0 10'h08C */
	union {
		uint32_t mipi_tx_fpll_enable0; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_pll_rstb : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_pll_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_sscg_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_frac_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MIPI_TX_FPLL_ENABLE1 10'h090 */
	union {
		uint32_t mipi_tx_fpll_enable1; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_ldo_bias_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_ldo_out_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_ic_ico_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_kband_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MIPI_TX_FPLL_OVERWRITE_ENABLE 10'h094 */
	union {
		uint32_t mipi_tx_fpll_overwrite_enable; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_kband_complete : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_zerostart : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_pll_out : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_ic_ico : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MIPI_TX_FPLL_DIG_EN 10'h098 */
	union {
		uint32_t mipi_tx_fpll_dig_en; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_post_div1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_post_div2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_post_div3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_post_div4_halfdiv_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MIPI_TX_FPLL_REF_GEN 10'h09C */
	union {
		uint32_t mipi_tx_fpll_ref_gen; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_v09_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_fpll_ref_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_ref_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_FPLL_PFD_SEL 10'h0A0 */
	union {
		uint32_t mipi_tx_fpll_pfd_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_pfd_ckico_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_pfd_clk_retimed_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_FPLL_CP_SEL 10'h0A4 */
	union {
		uint32_t mipi_tx_fpll_cp_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_ip_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t rg_mipi_tx_fpll_ii_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_FPLL_LF_SEL 10'h0A8 */
	union {
		uint32_t mipi_tx_fpll_lf_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_rp_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t rg_mipi_tx_fpll_ci_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_fpll_cp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_fpll_pll_op_sel : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* MIPI_TX_FPLL_LPF_SEL 10'h0AC */
	union {
		uint32_t mipi_tx_fpll_lpf_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_rlp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_fpll_clp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_fpll_rlp_sel_2 : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_fpll_clp_sel_2 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* MIPI_TX_FPLL_KBAND_SEL 10'h0B0 */
	union {
		uint32_t mipi_tx_fpll_kband_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_sq_bi_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t rg_mipi_tx_fpll_enable_out_del_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_fpll_freqm_count_ext_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t rg_mipi_tx_fpll_pll_out_del_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* MIPI_TX_FPLL_DIV_SEL 10'h0B4 */
	union {
		uint32_t mipi_tx_fpll_div_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_ref_div_sel : 2;
			uint32_t : 2; // padding bits
			uint32_t rg_mipi_tx_fpll_ffb_prediv_sel : 3;
			uint32_t : 1; // padding bits
			uint32_t rg_mipi_tx_fpll_ffb_halfdiv_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_mipi_tx_fpll_ffb_intdiv_sel : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_FPLL_POST_DIV_SEL 10'h0B8 */
	union {
		uint32_t mipi_tx_fpll_post_div_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_post_div1_sel : 8;
			uint32_t rg_mipi_tx_fpll_post_div2_sel : 8;
			uint32_t rg_mipi_tx_fpll_post_div3_sel : 8;
			uint32_t rg_mipi_tx_fpll_post_div4_halfdiv_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* MIPI_TX_FPLL_POSTDIV_CLKIN_SEL 10'h0BC */
	union {
		uint32_t mipi_tx_fpll_postdiv_clkin_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_postdiv_clkin_sel_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_postdiv_clkin_sel_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_postdiv_clkin_sel_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_postdiv_clkin_sel_4 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MIPI_TX_FPLL_OVERWRITE 10'h0C0 */
	union {
		uint32_t mipi_tx_fpll_overwrite; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_band : 6;
			uint32_t : 2; // padding bits
			uint32_t rg_mipi_tx_fpll_control_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_digital_control_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_ico_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MIPI_TX_FPLL_MON_CLK_SEL 10'h0C4 */
	union {
		uint32_t mipi_tx_fpll_mon_clk_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_mon_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_mipi_tx_fpll_mon_clk_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_FPLL_RESERVED 10'h0C8 */
	union {
		uint32_t mipi_tx_fpll_reserved; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_reserved : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_FPLL_SSCG_F 10'h0CC */
	union {
		uint32_t mipi_tx_fpll_sscg_f; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_sscg_f : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_TX_FPLL_SSCG_SEL 10'h0D0 */
	union {
		uint32_t mipi_tx_fpll_sscg_sel; // word name
		struct {
			uint32_t rg_mipi_tx_fpll_sscg_deviation_unit : 11;
			uint32_t : 5; // padding bits
			uint32_t rg_mipi_tx_fpll_sscg_freq_count : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* MIPI_TX_FPLL_RGS_ENABLE0 10'h0D4 */
	union {
		uint32_t mipi_tx_fpll_rgs_enable0; // word name
		struct {
			uint32_t rgs_mipi_tx_fpll_ldo_bias_en_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_mipi_tx_fpll_ldo_out_en_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_mipi_tx_fpll_ic_ico_en_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_mipi_tx_fpll_kband_en_mux_d : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MIPI_TX_FPLL_RGS_ENABLE1 10'h0D8 */
	union {
		uint32_t mipi_tx_fpll_rgs_enable1; // word name
		struct {
			uint32_t rgs_mipi_tx_fpll_kband_complete_mux_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_mipi_tx_fpll_zerostart_mux_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_mipi_tx_fpll_pll_out_mux_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_mipi_tx_fpll_band_mux_d : 6;
			uint32_t : 2; // padding bits
		};
	};
} CsrBankTx_phycfg;

#endif