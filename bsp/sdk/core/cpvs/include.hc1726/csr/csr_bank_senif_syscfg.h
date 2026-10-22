/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_SENIF_SYSCFG_H_
#define CSR_BANK_SENIF_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from senif_syscfg  ***/
typedef struct csr_bank_senif_syscfg {
	/* CKEN0 10'h000 */
	union {
		uint32_t cken0; // word name
		struct {
			uint32_t cken_rx0_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_ps_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dec0_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dec1_senif : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN1 10'h004 */
	union {
		uint32_t cken1; // word name
		struct {
			uint32_t cken_ps_out : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_spi_out : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dec0_out : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dec1_out : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN2 10'h008 */
	union {
		uint32_t cken2; // word name
		struct {
			uint32_t cken_slb0_out : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_slb1_out : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKEN3 10'h00C */
	union {
		uint32_t cken3; // word name
		struct {
			uint32_t cken_rx0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_ps_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dec0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dec1_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN4 10'h010 */
	union {
		uint32_t cken4; // word name
		struct {
			uint32_t cken_spi_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_slb0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_slb1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWRST0 10'h014 */
	union {
		uint32_t swrst0; // word name
		struct {
			uint32_t sw_rst_rx0_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_ps_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dec0_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dec1_senif : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST1 10'h018 */
	union {
		uint32_t swrst1; // word name
		struct {
			uint32_t sw_rst_ps_out : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_spi_out : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dec0_out : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dec1_out : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST2 10'h01C */
	union {
		uint32_t swrst2; // word name
		struct {
			uint32_t sw_rst_slb0_out : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_slb1_out : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWRST3 10'h020 */
	union {
		uint32_t swrst3; // word name
		struct {
			uint32_t sw_rst_rx0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_ps_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dec0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dec1_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST4 10'h024 */
	union {
		uint32_t swrst4; // word name
		struct {
			uint32_t sw_rst_spi_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_slb0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_slb1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_ctrl_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST0 10'h028 */
	union {
		uint32_t lvlrst0; // word name
		struct {
			uint32_t lv_rst_rx0_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ps_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec0_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec1_senif : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST1 10'h02C */
	union {
		uint32_t lvlrst1; // word name
		struct {
			uint32_t lv_rst_ps_out : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_spi_out : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec0_out : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec1_out : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST2 10'h030 */
	union {
		uint32_t lvlrst2; // word name
		struct {
			uint32_t lv_rst_slb0_out : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_slb1_out : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVLRST3 10'h034 */
	union {
		uint32_t lvlrst3; // word name
		struct {
			uint32_t lv_rst_rx0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ps_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec1_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST4 10'h038 */
	union {
		uint32_t lvlrst4; // word name
		struct {
			uint32_t lv_rst_spi_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_slb0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_slb1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ctrl_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
} CsrBankSenif_syscfg;

#endif