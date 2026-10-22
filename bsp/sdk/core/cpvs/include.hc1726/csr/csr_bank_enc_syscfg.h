/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ENC_SYSCFG_H_
#define CSR_BANK_ENC_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from enc_syscfg  ***/
typedef struct csr_bank_enc_syscfg {
	/* CFG_CG_SP 8'h00 */
	union {
		uint32_t cfg_cg_sp; // word name
		struct {
			uint32_t cken_sp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_sp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_SP 8'h04 */
	union {
		uint32_t cfg_lv_rst_sp; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t lv_rst_sp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_sp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_SP 8'h08 */
	union {
		uint32_t cfg_sw_rst_sp; // word name
		struct {
			uint32_t sw_rst_sp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_sp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_JPEG 8'h0C */
	union {
		uint32_t cfg_cg_jpeg; // word name
		struct {
			uint32_t cken_jpeg : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_jpeg_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_JPEG 8'h10 */
	union {
		uint32_t cfg_lv_rst_jpeg; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t lv_rst_jpeg : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_jpeg_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_JPEG 8'h14 */
	union {
		uint32_t cfg_sw_rst_jpeg; // word name
		struct {
			uint32_t sw_rst_jpeg : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_jpeg_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_VENC 8'h18 */
	union {
		uint32_t cfg_cg_venc; // word name
		struct {
			uint32_t cken_venc : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_venc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_VENC 8'h1C */
	union {
		uint32_t cfg_lv_rst_venc; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t lv_rst_venc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_venc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_VENC 8'h20 */
	union {
		uint32_t cfg_sw_rst_venc; // word name
		struct {
			uint32_t sw_rst_venc : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_venc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_SRCR 8'h24 */
	union {
		uint32_t cfg_cg_srcr; // word name
		struct {
			uint32_t cken_srcr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_srcr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_srcr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_SRCR 8'h28 */
	union {
		uint32_t cfg_lv_rst_srcr; // word name
		struct {
			uint32_t lv_rst_srcr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_srcr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_srcr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_SRCR 8'h2C */
	union {
		uint32_t cfg_sw_rst_srcr; // word name
		struct {
			uint32_t sw_rst_srcr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_srcr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_srcr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_BSW 8'h30 */
	union {
		uint32_t cfg_cg_bsw; // word name
		struct {
			uint32_t cken_bsw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_bsw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_bsw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_BSW 8'h34 */
	union {
		uint32_t cfg_lv_rst_bsw; // word name
		struct {
			uint32_t lv_rst_bsw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bsw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bsw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_BSW 8'h38 */
	union {
		uint32_t cfg_sw_rst_bsw; // word name
		struct {
			uint32_t sw_rst_bsw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_bsw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_bsw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_OSDR_0 8'h3C */
	union {
		uint32_t cfg_cg_osdr_0; // word name
		struct {
			uint32_t cken_osdr_0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_osdr_0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_osdr_0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_OSDR_0 8'h40 */
	union {
		uint32_t cfg_lv_rst_osdr_0; // word name
		struct {
			uint32_t lv_rst_osdr_0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_osdr_0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_osdr_0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_OSDR_0 8'h44 */
	union {
		uint32_t cfg_sw_rst_osdr_0; // word name
		struct {
			uint32_t sw_rst_osdr_0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_osdr_0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_osdr_0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_OSDR_1 8'h48 */
	union {
		uint32_t cfg_cg_osdr_1; // word name
		struct {
			uint32_t cken_osdr_1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_osdr_1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_osdr_1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_OSDR_1 8'h4C */
	union {
		uint32_t cfg_lv_rst_osdr_1; // word name
		struct {
			uint32_t lv_rst_osdr_1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_osdr_1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_osdr_1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_OSDR_1 8'h50 */
	union {
		uint32_t cfg_sw_rst_osdr_1; // word name
		struct {
			uint32_t sw_rst_osdr_1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_osdr_1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_osdr_1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_REFR 8'h54 */
	union {
		uint32_t cfg_cg_refr; // word name
		struct {
			uint32_t cken_refr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_refr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_refr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_REFR 8'h58 */
	union {
		uint32_t cfg_lv_rst_refr; // word name
		struct {
			uint32_t lv_rst_refr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_refr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_refr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_REFR 8'h5C */
	union {
		uint32_t cfg_sw_rst_refr; // word name
		struct {
			uint32_t sw_rst_refr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_refr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_refr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_REFW 8'h60 */
	union {
		uint32_t cfg_cg_refw; // word name
		struct {
			uint32_t cken_refw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_refw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_refw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_REFW 8'h64 */
	union {
		uint32_t cfg_lv_rst_refw; // word name
		struct {
			uint32_t lv_rst_refw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_refw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_refw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_REFW 8'h68 */
	union {
		uint32_t cfg_sw_rst_refw; // word name
		struct {
			uint32_t sw_rst_refw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_refw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_refw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_MVR 8'h6C */
	union {
		uint32_t cfg_cg_mvr; // word name
		struct {
			uint32_t cken_mvr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_mvr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_mvr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_MVR 8'h70 */
	union {
		uint32_t cfg_lv_rst_mvr; // word name
		struct {
			uint32_t lv_rst_mvr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mvr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mvr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_MVR 8'h74 */
	union {
		uint32_t cfg_sw_rst_mvr; // word name
		struct {
			uint32_t sw_rst_mvr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_mvr_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_mvr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankEnc_syscfg;

#endif