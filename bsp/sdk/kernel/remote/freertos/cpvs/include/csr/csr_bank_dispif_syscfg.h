#ifndef CSR_BANK_DISPIF_SYSCFG_H_
#define CSR_BANK_DISPIF_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dispif_syscfg  ***/
typedef struct csr_bank_dispif_syscfg {
	/* CKG_RX0 10'h000 */
	union {
		uint32_t ckg_rx0; // word name
		struct {
			uint32_t cken_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_RX1 10'h004 */
	union {
		uint32_t ckg_rx1; // word name
		struct {
			uint32_t cken_tx_pix : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_tx_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DEC0 10'h008 */
	union {
		uint32_t ckg_dec0; // word name
		struct {
			uint32_t cken_tx_sys_phy : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_tx_phy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DEC1 10'h00C [Unused] */
	uint32_t empty_word_ckg_dec1;
	/* CKG_PS 10'h010 */
	union {
		uint32_t ckg_ps; // word name
		struct {
			uint32_t cken_pd : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_SLB0 10'h014 [Unused] */
	uint32_t empty_word_ckg_slb0;
	/* CKG_SLB1 10'h018 [Unused] */
	uint32_t empty_word_ckg_slb1;
	/* CKG_CTRL 10'h01C [Unused] */
	uint32_t empty_word_ckg_ctrl;
	/* SENIFSYS8 10'h020 [Unused] */
	uint32_t empty_word_senifsys8;
	/* SENIFSYS9 10'h024 [Unused] */
	uint32_t empty_word_senifsys9;
	/* SENIFSYS10 10'h028 [Unused] */
	uint32_t empty_word_senifsys10;
	/* SENIFSYS11 10'h02C [Unused] */
	uint32_t empty_word_senifsys11;
	/* SENIFSYS12 10'h030 [Unused] */
	uint32_t empty_word_senifsys12;
	/* SENIFSYS13 10'h034 [Unused] */
	uint32_t empty_word_senifsys13;
	/* SENIFSYS14 10'h038 [Unused] */
	uint32_t empty_word_senifsys14;
	/* RESV 10'h03C */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_RX0 10'h040 */
	union {
		uint32_t rst_rx0; // word name
		struct {
			uint32_t sw_rst_tx_enc_pix_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_tx_enc_enc_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t csr_rst_tx_enc_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST_RX1 10'h044 */
	union {
		uint32_t rst_rx1; // word name
		struct {
			uint32_t csr_rst_tx_output_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_DEC0 10'h048 */
	union {
		uint32_t rst_dec0; // word name
		struct {
			uint32_t sw_rst_tx_phy_sys_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_tx_phy_phy_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_tx_phy_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_DEC1 10'h04C */
	union {
		uint32_t rst_dec1; // word name
		struct {
			uint32_t sw_rst_pd_pix_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_pd_tx_pll_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_pd_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENIFSYS20 10'h050 [Unused] */
	uint32_t empty_word_senifsys20;
	/* SENIFSYS21 10'h054 [Unused] */
	uint32_t empty_word_senifsys21;
	/* SENIFSYS22 10'h058 [Unused] */
	uint32_t empty_word_senifsys22;
	/* SENIFSYS23 10'h05C [Unused] */
	uint32_t empty_word_senifsys23;
	/* RST_PS 10'h060 */
	union {
		uint32_t rst_ps; // word name
		struct {
			uint32_t csr_rst_ctrl_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_SLB0 10'h064 [Unused] */
	uint32_t empty_word_rst_slb0;
	/* RST_SLB1 10'h068 [Unused] */
	uint32_t empty_word_rst_slb1;
	/* RST_CTRL 10'h06C [Unused] */
	uint32_t empty_word_rst_ctrl;
	/* SENIFSYS28 10'h070 [Unused] */
	uint32_t empty_word_senifsys28;
	/* SENIFSYS29 10'h074 [Unused] */
	uint32_t empty_word_senifsys29;
	/* SENIFSYS30 10'h078 [Unused] */
	uint32_t empty_word_senifsys30;
	/* SENIFSYS31 10'h07C [Unused] */
	uint32_t empty_word_senifsys31;
	/* LVRST_RX0 10'h080 */
	union {
		uint32_t lvrst_rx0; // word name
		struct {
			uint32_t lvl_rst_tx_enc_pix_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t lvl_rst_tx_enc_enc_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_RX1 10'h084 [Unused] */
	uint32_t empty_word_lvrst_rx1;
	/* LVRST_DEC0 10'h088 */
	union {
		uint32_t lvrst_dec0; // word name
		struct {
			uint32_t lvl_rst_tx_phy_sys_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t lvl_rst_tx_phy_phy_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_DEC1 10'h08C */
	union {
		uint32_t lvrst_dec1; // word name
		struct {
			uint32_t lvl_rst_pd_pix_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t lvl_rst_pd_tx_pll_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDispif_syscfg;

#endif