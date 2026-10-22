/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ISK_CFG_H_
#define CSR_BANK_ISK_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isk_cfg  ***/
typedef struct csr_bank_isk_cfg {
	/* CKEN0 10'h000 */
	union {
		uint32_t cken0; // word name
		struct {
			uint32_t cken_cvs_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_crop_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_bsp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_fsc_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN1 10'h004 */
	union {
		uint32_t cken1; // word name
		struct {
			uint32_t cken_cvs_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_crop_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_bsp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_fsc_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST0 10'h008 */
	union {
		uint32_t lvlrst0; // word name
		struct {
			uint32_t lv_rst_cvs_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_crop_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dbc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dcc_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST1 10'h00C */
	union {
		uint32_t lvlrst1; // word name
		struct {
			uint32_t lv_rst_lsc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dfk_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bsp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fsc_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST2 10'h010 */
	union {
		uint32_t lvlrst2; // word name
		struct {
			uint32_t lv_rst_cvs_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_crop_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dbc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dcc_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST3 10'h014 */
	union {
		uint32_t lvlrst3; // word name
		struct {
			uint32_t lv_rst_lsc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dfk_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bsp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fsc_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST0 10'h018 */
	union {
		uint32_t swrst0; // word name
		struct {
			uint32_t sw_rst_cvs_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_crop_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dbc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dcc_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST1 10'h01C */
	union {
		uint32_t swrst1; // word name
		struct {
			uint32_t sw_rst_lsc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dfk_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_bsp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_fsc_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST2 10'h020 */
	union {
		uint32_t swrst2; // word name
		struct {
			uint32_t sw_rst_cvs_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_crop_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dbc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dcc_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST3 10'h024 */
	union {
		uint32_t swrst3; // word name
		struct {
			uint32_t sw_rst_lsc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dfk_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_bsp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_fsc_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
} CsrBankIsk_cfg;

#endif