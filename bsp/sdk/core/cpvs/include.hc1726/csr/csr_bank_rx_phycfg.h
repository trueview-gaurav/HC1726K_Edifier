/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_RX_PHYCFG_H_
#define CSR_BANK_RX_PHYCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from rx_phycfg  ***/
typedef struct csr_bank_rx_phycfg {
	/* MIPI_RX_REFGEN00 10'h000 */
	union {
		uint32_t mipi_rx_refgen00; // word name
		struct {
			uint32_t ln0_ib10u_miuns : 1;
			uint32_t : 7; // padding bits
			uint32_t ln0_ib10u_plus : 1;
			uint32_t : 7; // padding bits
			uint32_t ln0_vth_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_HS00 10'h004 */
	union {
		uint32_t mipi_rx_hs00; // word name
		struct {
			uint32_t ln0_delay_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ln0_term_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_LP00 10'h008 */
	union {
		uint32_t mipi_rx_lp00; // word name
		struct {
			uint32_t ln0_lpf_p : 1;
			uint32_t : 7; // padding bits
			uint32_t ln0_lpf_n : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_REFGEN01 10'h00C */
	union {
		uint32_t mipi_rx_refgen01; // word name
		struct {
			uint32_t ln1_ib10u_miuns : 1;
			uint32_t : 7; // padding bits
			uint32_t ln1_ib10u_plus : 1;
			uint32_t : 7; // padding bits
			uint32_t ln1_vth_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_HS01 10'h010 */
	union {
		uint32_t mipi_rx_hs01; // word name
		struct {
			uint32_t ln1_delay_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ln1_term_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_LP01 10'h014 */
	union {
		uint32_t mipi_rx_lp01; // word name
		struct {
			uint32_t ln1_lpf_p : 1;
			uint32_t : 7; // padding bits
			uint32_t ln1_lpf_n : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_REFGEN02 10'h018 */
	union {
		uint32_t mipi_rx_refgen02; // word name
		struct {
			uint32_t ln2_ib10u_miuns : 1;
			uint32_t : 7; // padding bits
			uint32_t ln2_ib10u_plus : 1;
			uint32_t : 7; // padding bits
			uint32_t ln2_vth_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_HS02 10'h01C */
	union {
		uint32_t mipi_rx_hs02; // word name
		struct {
			uint32_t ln2_delay_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ln2_term_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_LP02 10'h020 */
	union {
		uint32_t mipi_rx_lp02; // word name
		struct {
			uint32_t ln2_lpf_p : 1;
			uint32_t : 7; // padding bits
			uint32_t ln2_lpf_n : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_REFGEN03 10'h024 */
	union {
		uint32_t mipi_rx_refgen03; // word name
		struct {
			uint32_t ln3_ib10u_miuns : 1;
			uint32_t : 7; // padding bits
			uint32_t ln3_ib10u_plus : 1;
			uint32_t : 7; // padding bits
			uint32_t ln3_vth_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_HS03 10'h028 */
	union {
		uint32_t mipi_rx_hs03; // word name
		struct {
			uint32_t ln3_delay_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ln3_term_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_LP03 10'h02C */
	union {
		uint32_t mipi_rx_lp03; // word name
		struct {
			uint32_t ln3_lpf_p : 1;
			uint32_t : 7; // padding bits
			uint32_t ln3_lpf_n : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_CK 10'h030 */
	union {
		uint32_t mipi_rx_ck; // word name
		struct {
			uint32_t ln0_ck_en : 1;
			uint32_t : 3; // padding bits
			uint32_t ln1_ck_en : 1;
			uint32_t : 3; // padding bits
			uint32_t ln2_ck_en : 1;
			uint32_t : 3; // padding bits
			uint32_t ln3_ck_en : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ch0_clk_xor : 1;
			uint32_t : 3; // padding bits
			uint32_t ch1_clk_xor : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* MIPI_RX_FUNC00 10'h034 */
	union {
		uint32_t mipi_rx_func00; // word name
		struct {
			uint32_t ln0_lvds_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln0_chop_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln0_lb_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_SEL00 10'h038 */
	union {
		uint32_t mipi_rx_sel00; // word name
		struct {
			uint32_t ln0_ch_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ln0_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ln0_ldov_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_FUNC01 10'h03C */
	union {
		uint32_t mipi_rx_func01; // word name
		struct {
			uint32_t ln1_lvds_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln1_chop_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln1_lb_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_SEL01 10'h040 */
	union {
		uint32_t mipi_rx_sel01; // word name
		struct {
			uint32_t ln1_ch_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ln1_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ln1_ldov_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_FUNC02 10'h044 */
	union {
		uint32_t mipi_rx_func02; // word name
		struct {
			uint32_t ln2_lvds_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln2_chop_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln2_lb_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_SEL02 10'h048 */
	union {
		uint32_t mipi_rx_sel02; // word name
		struct {
			uint32_t ln2_ch_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ln2_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ln2_ldov_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_FUNC03 10'h04C */
	union {
		uint32_t mipi_rx_func03; // word name
		struct {
			uint32_t ln3_lvds_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln3_chop_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln3_lb_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_SEL03 10'h050 */
	union {
		uint32_t mipi_rx_sel03; // word name
		struct {
			uint32_t ln3_ch_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ln3_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ln3_ldov_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankRx_phycfg;

#endif