/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_IPLL_H_
#define CSR_BANK_IPLL_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ipll  ***/
typedef struct csr_bank_ipll {
	/* IPLL_ENABLE0 7'h00 */
	union {
		uint32_t ipll_enable0; // word name
		struct {
			uint32_t rg_ipll_pll_rstb : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_pll_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_sscg_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_frac_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IPLL_OVERWRITE_ENABLE 7'h04 */
	union {
		uint32_t ipll_overwrite_enable; // word name
		struct {
			uint32_t rg_ipll_kband_complete : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_zerostart : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_ipll_ic_ico : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IPLL_DIG_EN 7'h08 */
	union {
		uint32_t ipll_dig_en; // word name
		struct {
			uint32_t rg_ipll_post_div1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_post_div2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_post_div3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_post_div4_halfdiv_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IPLL_REF_GEN 7'h0C */
	union {
		uint32_t ipll_ref_gen; // word name
		struct {
			uint32_t rg_ipll_v09_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_ipll_ref_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_ref_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IPLL_PFD_SEL 7'h10 */
	union {
		uint32_t ipll_pfd_sel; // word name
		struct {
			uint32_t rg_ipll_pfd_ckico_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_pfd_clk_retimed_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IPLL_CP_SEL 7'h14 */
	union {
		uint32_t ipll_cp_sel; // word name
		struct {
			uint32_t rg_ipll_ip_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t rg_ipll_ii_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IPLL_LF_SEL 7'h18 */
	union {
		uint32_t ipll_lf_sel; // word name
		struct {
			uint32_t rg_ipll_rp_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t rg_ipll_ci_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_ipll_cp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_ipll_pll_op_sel : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* IPLL_LPF_SEL 7'h1C */
	union {
		uint32_t ipll_lpf_sel; // word name
		struct {
			uint32_t rg_ipll_rlp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_ipll_clp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_ipll_rlp_sel_2 : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_ipll_clp_sel_2 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* IPLL_KBAND_SEL 7'h20 */
	union {
		uint32_t ipll_kband_sel; // word name
		struct {
			uint32_t rg_ipll_sq_bi_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t rg_ipll_enable_out_del_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_ipll_freqm_count_ext_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t rg_ipll_pll_out_del_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* IPLL_DIV_SEL 7'h24 */
	union {
		uint32_t ipll_div_sel; // word name
		struct {
			uint32_t rg_ipll_ref_div_sel : 2;
			uint32_t : 2; // padding bits
			uint32_t rg_ipll_ffb_prediv_sel : 3;
			uint32_t : 1; // padding bits
			uint32_t rg_ipll_ffb_halfdiv_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_ipll_ffb_intdiv_sel : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* IPLL_POST_DIV_SEL 7'h28 */
	union {
		uint32_t ipll_post_div_sel; // word name
		struct {
			uint32_t rg_ipll_post_div1_sel : 8;
			uint32_t rg_ipll_post_div2_sel : 8;
			uint32_t rg_ipll_post_div3_sel : 8;
			uint32_t rg_ipll_post_div4_halfdiv_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* IPLL_POSTDIV_CLKIN_SEL 7'h2C */
	union {
		uint32_t ipll_postdiv_clkin_sel; // word name
		struct {
			uint32_t rg_ipll_postdiv_clkin_sel_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_postdiv_clkin_sel_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_postdiv_clkin_sel_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_postdiv_clkin_sel_4 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IPLL_CKICO_BYPASS 7'h30 */
	union {
		uint32_t ipll_ckico_bypass; // word name
		struct {
			uint32_t rg_ipll_ad_ckico_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IPLL_POSTDIV_BYPASS 7'h34 */
	union {
		uint32_t ipll_postdiv_bypass; // word name
		struct {
			uint32_t rg_ipll_ad_ckpostdiv4_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_ad_ckpostdiv1_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_ad_ckpostdiv2_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_ad_ckpostdiv3_bypass : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IPLL_OVERWRITE 7'h38 */
	union {
		uint32_t ipll_overwrite; // word name
		struct {
			uint32_t rg_ipll_band : 6;
			uint32_t : 2; // padding bits
			uint32_t rg_ipll_control_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_digital_control_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_ico_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IPLL_MON_CLK_SEL 7'h3C */
	union {
		uint32_t ipll_mon_clk_sel; // word name
		struct {
			uint32_t rg_ipll_mon_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_ipll_mon_clk_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IPLL_RESERVED 7'h40 */
	union {
		uint32_t ipll_reserved; // word name
		struct {
			uint32_t rg_ipll_reserved : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IPLL_RGS_ENABLE0 7'h44 */
	union {
		uint32_t ipll_rgs_enable0; // word name
		struct {
			uint32_t rgs_ipll_ldo_bias_en_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_ipll_ldo_out_en_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_ipll_ic_ico_en_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_ipll_kband_en_d : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IPLL_RGS_ENABLE1 7'h48 */
	union {
		uint32_t ipll_rgs_enable1; // word name
		struct {
			uint32_t rgs_ipll_kband_complete_mux_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_ipll_zerostart_mux_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_ipll_pll_out_d : 1;
			uint32_t : 7; // padding bits
			uint32_t rgs_ipll_band_mux_d : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* IPLL_REF_CLK_SEL 7'h4C */
	union {
		uint32_t ipll_ref_clk_sel; // word name
		struct {
			uint32_t pll_ref_clk_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankIpll;

#endif