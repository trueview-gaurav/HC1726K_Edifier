/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ISP_CFG_H_
#define CSR_BANK_ISP_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isp_cfg  ***/
typedef struct csr_bank_isp_cfg {
	/* ISPR0_RW_K 10'h000 */
	union {
		uint32_t ispr0_rw_k; // word name
		struct {
			uint32_t cken_ispr0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ispr0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR0_W1P_K 10'h004 */
	union {
		uint32_t ispr0_w1p_k; // word name
		struct {
			uint32_t sw_rst_ispr0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR0_WR_D 10'h008 */
	union {
		uint32_t ispr0_wr_d; // word name
		struct {
			uint32_t cken_ispr0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ispr0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR0_W1P_D 10'h00C */
	union {
		uint32_t ispr0_w1p_d; // word name
		struct {
			uint32_t sw_rst_ispr0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR0_RW_P 10'h010 */
	union {
		uint32_t ispr0_rw_p; // word name
		struct {
			uint32_t cken_ispr0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ispr0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR0_W1P_P 10'h014 */
	union {
		uint32_t ispr0_w1p_p; // word name
		struct {
			uint32_t sw_rst_ispr0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR1_RW_K 10'h018 */
	union {
		uint32_t ispr1_rw_k; // word name
		struct {
			uint32_t cken_ispr1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ispr1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR1_W1P_K 10'h01C */
	union {
		uint32_t ispr1_w1p_k; // word name
		struct {
			uint32_t sw_rst_ispr1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR1_WR_D 10'h020 */
	union {
		uint32_t ispr1_wr_d; // word name
		struct {
			uint32_t cken_ispr1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ispr1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR1_W1P_D 10'h024 */
	union {
		uint32_t ispr1_w1p_d; // word name
		struct {
			uint32_t sw_rst_ispr1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR1_RW_P 10'h028 */
	union {
		uint32_t ispr1_rw_p; // word name
		struct {
			uint32_t cken_ispr1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ispr1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR1_W1P_P 10'h02C */
	union {
		uint32_t ispr1_w1p_p; // word name
		struct {
			uint32_t sw_rst_ispr1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX0_RW_K 10'h030 */
	union {
		uint32_t gfx0_rw_k; // word name
		struct {
			uint32_t cken_gfx0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_gfx0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX0_W1P_K 10'h034 */
	union {
		uint32_t gfx0_w1p_k; // word name
		struct {
			uint32_t sw_rst_gfx0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX0_WR_D 10'h038 */
	union {
		uint32_t gfx0_wr_d; // word name
		struct {
			uint32_t cken_gfx0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_gfx0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX0_W1P_D 10'h03C */
	union {
		uint32_t gfx0_w1p_d; // word name
		struct {
			uint32_t sw_rst_gfx0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX0_RW_P 10'h040 */
	union {
		uint32_t gfx0_rw_p; // word name
		struct {
			uint32_t cken_gfx0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_gfx0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX0_W1P_P 10'h044 */
	union {
		uint32_t gfx0_w1p_p; // word name
		struct {
			uint32_t sw_rst_gfx0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD_RW_K 10'h048 */
	union {
		uint32_t bld_rw_k; // word name
		struct {
			uint32_t cken_bld_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bld_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD_W1P_K 10'h04C */
	union {
		uint32_t bld_w1p_k; // word name
		struct {
			uint32_t sw_rst_bld_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD_WR_D 10'h050 */
	union {
		uint32_t bld_wr_d; // word name
		struct {
			uint32_t cken_bld_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bld_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD_W1P_D 10'h054 */
	union {
		uint32_t bld_w1p_d; // word name
		struct {
			uint32_t sw_rst_bld_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD_RW_P 10'h058 */
	union {
		uint32_t bld_rw_p; // word name
		struct {
			uint32_t cken_bld_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bld_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD_W1P_P 10'h05C */
	union {
		uint32_t bld_w1p_p; // word name
		struct {
			uint32_t sw_rst_bld_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG0_RW_K 10'h060 */
	union {
		uint32_t pg0_rw_k; // word name
		struct {
			uint32_t cken_pg0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pg0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG0_W1P_K 10'h064 */
	union {
		uint32_t pg0_w1p_k; // word name
		struct {
			uint32_t sw_rst_pg0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG0_RW_P 10'h068 */
	union {
		uint32_t pg0_rw_p; // word name
		struct {
			uint32_t cken_pg0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pg0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG0_W1P_P 10'h06C */
	union {
		uint32_t pg0_w1p_p; // word name
		struct {
			uint32_t sw_rst_pg0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG1_RW_K 10'h070 */
	union {
		uint32_t pg1_rw_k; // word name
		struct {
			uint32_t cken_pg1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pg1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG1_W1P_K 10'h074 */
	union {
		uint32_t pg1_w1p_k; // word name
		struct {
			uint32_t sw_rst_pg1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG1_RW_P 10'h078 */
	union {
		uint32_t pg1_rw_p; // word name
		struct {
			uint32_t cken_pg1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pg1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG1_W1P_P 10'h07C */
	union {
		uint32_t pg1_w1p_p; // word name
		struct {
			uint32_t sw_rst_pg1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS0_RW_K 10'h080 */
	union {
		uint32_t cs0_rw_k; // word name
		struct {
			uint32_t cken_cs0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cs0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS0_W1P_K 10'h084 */
	union {
		uint32_t cs0_w1p_k; // word name
		struct {
			uint32_t sw_rst_cs0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS0_RW_P 10'h088 */
	union {
		uint32_t cs0_rw_p; // word name
		struct {
			uint32_t cken_cs0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cs0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS0_W1P_P 10'h08C */
	union {
		uint32_t cs0_w1p_p; // word name
		struct {
			uint32_t sw_rst_cs0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS1_RW_K 10'h090 */
	union {
		uint32_t cs1_rw_k; // word name
		struct {
			uint32_t cken_cs1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cs1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS1_W1P_K 10'h094 */
	union {
		uint32_t cs1_w1p_k; // word name
		struct {
			uint32_t sw_rst_cs1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS1_RW_P 10'h098 */
	union {
		uint32_t cs1_rw_p; // word name
		struct {
			uint32_t cken_cs1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cs1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS1_W1P_P 10'h09C */
	union {
		uint32_t cs1_w1p_p; // word name
		struct {
			uint32_t sw_rst_cs1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR_RW_K 10'h0A0 */
	union {
		uint32_t hdr_rw_k; // word name
		struct {
			uint32_t cken_hdr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_hdr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR_W1P_K 10'h0A4 */
	union {
		uint32_t hdr_w1p_k; // word name
		struct {
			uint32_t sw_rst_hdr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR_RW_P 10'h0A8 */
	union {
		uint32_t hdr_rw_p; // word name
		struct {
			uint32_t cken_hdr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_hdr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR_W1P_P 10'h0AC */
	union {
		uint32_t hdr_w1p_p; // word name
		struct {
			uint32_t sw_rst_hdr_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_RW_K 10'h0B0 */
	union {
		uint32_t rgbp_rw_k; // word name
		struct {
			uint32_t cken_rgbp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_rgbp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_W1P_K 10'h0B4 */
	union {
		uint32_t rgbp_w1p_k; // word name
		struct {
			uint32_t sw_rst_rgbp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_RW_P 10'h0B8 */
	union {
		uint32_t rgbp_rw_p; // word name
		struct {
			uint32_t cken_rgbp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_rgbp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_W1P_P 10'h0BC */
	union {
		uint32_t rgbp_w1p_p; // word name
		struct {
			uint32_t sw_rst_rgbp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_RW_K 10'h0C0 */
	union {
		uint32_t nr2d_rw_k; // word name
		struct {
			uint32_t cken_nr2d_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_nr2d_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_W1P_K 10'h0C4 */
	union {
		uint32_t nr2d_w1p_k; // word name
		struct {
			uint32_t sw_rst_nr2d_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_RW_P 10'h0C8 */
	union {
		uint32_t nr2d_rw_p; // word name
		struct {
			uint32_t cken_nr2d_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_nr2d_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_W1P_P 10'h0CC */
	union {
		uint32_t nr2d_w1p_p; // word name
		struct {
			uint32_t sw_rst_nr2d_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CCM_RW_K 10'h0D0 */
	union {
		uint32_t ccm_rw_k; // word name
		struct {
			uint32_t cken_ccm_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ccm_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CCM_W1P_K 10'h0D4 */
	union {
		uint32_t ccm_w1p_k; // word name
		struct {
			uint32_t sw_rst_ccm_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CCM_RW_P 10'h0D8 */
	union {
		uint32_t ccm_rw_p; // word name
		struct {
			uint32_t cken_ccm_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ccm_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CCM_W1P_P 10'h0DC */
	union {
		uint32_t ccm_w1p_p; // word name
		struct {
			uint32_t sw_rst_ccm_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_RW_K 10'h0E0 */
	union {
		uint32_t shp_rw_k; // word name
		struct {
			uint32_t cken_shp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_shp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_W1P_K 10'h0E4 */
	union {
		uint32_t shp_w1p_k; // word name
		struct {
			uint32_t sw_rst_shp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_RW_P 10'h0E8 */
	union {
		uint32_t shp_rw_p; // word name
		struct {
			uint32_t cken_shp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_shp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_W1P_P 10'h0EC */
	union {
		uint32_t shp_w1p_p; // word name
		struct {
			uint32_t sw_rst_shp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_RW_K 10'h0F0 */
	union {
		uint32_t sc_rw_k; // word name
		struct {
			uint32_t cken_sc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_sc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_W1P_K 10'h0F4 */
	union {
		uint32_t sc_w1p_k; // word name
		struct {
			uint32_t sw_rst_sc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_RW_P 10'h0F8 */
	union {
		uint32_t sc_rw_p; // word name
		struct {
			uint32_t cken_sc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_sc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_W1P_P 10'h0FC */
	union {
		uint32_t sc_w1p_p; // word name
		struct {
			uint32_t sw_rst_sc_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PCA_RW_K 10'h100 */
	union {
		uint32_t pca_rw_k; // word name
		struct {
			uint32_t cken_pca_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pca_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PCA_W1P_K 10'h104 */
	union {
		uint32_t pca_w1p_k; // word name
		struct {
			uint32_t sw_rst_pca_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PCA_RW_P 10'h108 */
	union {
		uint32_t pca_rw_p; // word name
		struct {
			uint32_t cken_pca_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pca_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PCA_W1P_P 10'h10C */
	union {
		uint32_t pca_w1p_p; // word name
		struct {
			uint32_t sw_rst_pca_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_RW_K 10'h110 */
	union {
		uint32_t cus_rw_k; // word name
		struct {
			uint32_t cken_cus_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cus_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_W1P_K 10'h114 */
	union {
		uint32_t cus_w1p_k; // word name
		struct {
			uint32_t sw_rst_cus_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_RW_P 10'h118 */
	union {
		uint32_t cus_rw_p; // word name
		struct {
			uint32_t cken_cus_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cus_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_W1P_P 10'h11C */
	union {
		uint32_t cus_w1p_p; // word name
		struct {
			uint32_t sw_rst_cus_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_RW_K 10'h120 */
	union {
		uint32_t cds_rw_k; // word name
		struct {
			uint32_t cken_cds_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cds_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_W1P_K 10'h124 */
	union {
		uint32_t cds_w1p_k; // word name
		struct {
			uint32_t sw_rst_cds_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_RW_P 10'h128 */
	union {
		uint32_t cds_rw_p; // word name
		struct {
			uint32_t cken_cds_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cds_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_W1P_P 10'h12C */
	union {
		uint32_t cds_w1p_p; // word name
		struct {
			uint32_t sw_rst_cds_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL_RW_K 10'h130 */
	union {
		uint32_t ctrl_rw_k; // word name
		struct {
			uint32_t cken_ctrl_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ctrl_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL_W1P_K 10'h134 */
	union {
		uint32_t ctrl_w1p_k; // word name
		struct {
			uint32_t sw_rst_ctrl_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankIsp_cfg;

#endif