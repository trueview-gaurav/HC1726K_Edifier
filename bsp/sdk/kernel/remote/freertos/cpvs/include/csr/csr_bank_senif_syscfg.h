#ifndef CSR_BANK_SENIF_SYSCFG_H_
#define CSR_BANK_SENIF_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from senif_syscfg  ***/
typedef struct csr_bank_senif_syscfg {
	/* CKG_RX0 10'h000 */
	union {
		uint32_t ckg_rx0; // word name
		struct {
			uint32_t cken_rx0 : 1;
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
			uint32_t cken_rx1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DEC0 10'h008 */
	union {
		uint32_t ckg_dec0; // word name
		struct {
			uint32_t cken_dec0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DEC1 10'h00C */
	union {
		uint32_t ckg_dec1; // word name
		struct {
			uint32_t cken_dec1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_PS 10'h010 */
	union {
		uint32_t ckg_ps; // word name
		struct {
			uint32_t cken_ps : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_SLB0 10'h014 */
	union {
		uint32_t ckg_slb0; // word name
		struct {
			uint32_t cken_slb0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_SLB1 10'h018 */
	union {
		uint32_t ckg_slb1; // word name
		struct {
			uint32_t cken_slb1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_CTRL 10'h01C */
	union {
		uint32_t ckg_ctrl; // word name
		struct {
			uint32_t cken_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
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
			uint32_t sw_rst_rx0_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_rx0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_RX1 10'h044 */
	union {
		uint32_t rst_rx1; // word name
		struct {
			uint32_t sw_rst_rx1_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_rx1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_DEC0 10'h048 */
	union {
		uint32_t rst_dec0; // word name
		struct {
			uint32_t sw_rst_dec0_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dec0_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_dec0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_DEC1 10'h04C */
	union {
		uint32_t rst_dec1; // word name
		struct {
			uint32_t sw_rst_dec1_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dec1_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_dec1 : 1;
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
			uint32_t sw_rst_ps_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_ps_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_ps : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_SLB0 10'h064 */
	union {
		uint32_t rst_slb0; // word name
		struct {
			uint32_t sw_rst_slb0_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_slb0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_SLB1 10'h068 */
	union {
		uint32_t rst_slb1; // word name
		struct {
			uint32_t sw_rst_slb1_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_slb1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_CTRL 10'h06C */
	union {
		uint32_t rst_ctrl; // word name
		struct {
			uint32_t sw_rst_ctrl_sensor_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
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
			uint32_t lv_rst_rx0_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_RX1 10'h084 */
	union {
		uint32_t lvrst_rx1; // word name
		struct {
			uint32_t lv_rst_rx1_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_DEC0 10'h088 */
	union {
		uint32_t lvrst_dec0; // word name
		struct {
			uint32_t lv_rst_dec0_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec0_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_DEC1 10'h08C */
	union {
		uint32_t lvrst_dec1; // word name
		struct {
			uint32_t lv_rst_dec1_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec1_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_PS 10'h090 */
	union {
		uint32_t lvrst_ps; // word name
		struct {
			uint32_t lv_rst_ps_senif_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ps_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_SLB0 10'h094 */
	union {
		uint32_t lvrst_slb0; // word name
		struct {
			uint32_t lv_rst_slb0_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_SLB1 10'h098 */
	union {
		uint32_t lvrst_slb1; // word name
		struct {
			uint32_t lv_rst_slb1_out_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_CTRL 10'h09C */
	union {
		uint32_t lvrst_ctrl; // word name
		struct {
			uint32_t lv_rst_ctrl_sensor_clk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENIFSYS40 10'h0A0 [Unused] */
	uint32_t empty_word_senifsys40;
	/* SENIFSYS41 10'h0A4 [Unused] */
	uint32_t empty_word_senifsys41;
	/* SENIFSYS42 10'h0A8 [Unused] */
	uint32_t empty_word_senifsys42;
	/* SENIFSYS43 10'h0AC [Unused] */
	uint32_t empty_word_senifsys43;
	/* SENIFSYS44 10'h0B0 [Unused] */
	uint32_t empty_word_senifsys44;
	/* SENIFSYS45 10'h0B4 [Unused] */
	uint32_t empty_word_senifsys45;
	/* SENIFSYS46 10'h0B8 [Unused] */
	uint32_t empty_word_senifsys46;
	/* SENIFSYS47 10'h0BC [Unused] */
	uint32_t empty_word_senifsys47;
	/* SENIFSYS48 10'h0C0 [Unused] */
	uint32_t empty_word_senifsys48;
	/* SENIFSYS49 10'h0C4 [Unused] */
	uint32_t empty_word_senifsys49;
	/* SENIFSYS50 10'h0C8 [Unused] */
	uint32_t empty_word_senifsys50;
	/* SENIFSYS51 10'h0CC [Unused] */
	uint32_t empty_word_senifsys51;
	/* SENIFSYS52 10'h0D0 [Unused] */
	uint32_t empty_word_senifsys52;
	/* SENIFSYS53 10'h0D4 [Unused] */
	uint32_t empty_word_senifsys53;
	/* SENIFSYS54 10'h0D8 [Unused] */
	uint32_t empty_word_senifsys54;
	/* SENIFSYS55 10'h0DC [Unused] */
	uint32_t empty_word_senifsys55;
	/* SENIFSYS56 10'h0E0 [Unused] */
	uint32_t empty_word_senifsys56;
	/* SENIFSYS57 10'h0E4 [Unused] */
	uint32_t empty_word_senifsys57;
	/* SENIFSYS58 10'h0E8 [Unused] */
	uint32_t empty_word_senifsys58;
	/* SENIFSYS59 10'h0EC [Unused] */
	uint32_t empty_word_senifsys59;
	/* SENIFSYS60 10'h0F0 [Unused] */
	uint32_t empty_word_senifsys60;
	/* SENIFSYS61 10'h0F4 [Unused] */
	uint32_t empty_word_senifsys61;
	/* SENIFSYS62 10'h0F8 [Unused] */
	uint32_t empty_word_senifsys62;
	/* SENIFSYS63 10'h0FC [Unused] */
	uint32_t empty_word_senifsys63;
	/* MEM_WRAPPER 10'h100 */
	union {
		uint32_t mem_wrapper; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankSenif_syscfg;

#endif