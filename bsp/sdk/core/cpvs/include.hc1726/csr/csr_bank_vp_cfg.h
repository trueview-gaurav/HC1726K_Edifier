/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_VP_CFG_H_
#define CSR_BANK_VP_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from vp_cfg  ***/
typedef struct csr_bank_vp_cfg {
	/* DHZ_RW_K 10'h000 */
	union {
		uint32_t dhz_rw_k; // word name
		struct {
			uint32_t cken_dhz_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dhz_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DHZ_W1P_K 10'h004 */
	union {
		uint32_t dhz_w1p_k; // word name
		struct {
			uint32_t sw_rst_dhz_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DHZ_RW_P 10'h008 */
	union {
		uint32_t dhz_rw_p; // word name
		struct {
			uint32_t cken_dhz_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dhz_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DHZ_W1P_P 10'h00C */
	union {
		uint32_t dhz_w1p_p; // word name
		struct {
			uint32_t sw_rst_dhz_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_RW_K 10'h010 */
	union {
		uint32_t mcvp_rw_k; // word name
		struct {
			uint32_t cken_mcvp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mcvp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_W1P_K 10'h014 */
	union {
		uint32_t mcvp_w1p_k; // word name
		struct {
			uint32_t sw_rst_mcvp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_RW_P 10'h018 */
	union {
		uint32_t mcvp_rw_p; // word name
		struct {
			uint32_t cken_mcvp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mcvp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_W1P_P 10'h01C */
	union {
		uint32_t mcvp_w1p_p; // word name
		struct {
			uint32_t sw_rst_mcvp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MER_RW_K 10'h020 */
	union {
		uint32_t mer_rw_k; // word name
		struct {
			uint32_t cken_mer_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mer_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MER_W1P_K 10'h024 */
	union {
		uint32_t mer_w1p_k; // word name
		struct {
			uint32_t sw_rst_mer_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MER_WR_D 10'h028 */
	union {
		uint32_t mer_wr_d; // word name
		struct {
			uint32_t cken_mer_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mer_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MER_W1P_D 10'h02C */
	union {
		uint32_t mer_w1p_d; // word name
		struct {
			uint32_t sw_rst_mer_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MER_RW_P 10'h030 */
	union {
		uint32_t mer_rw_p; // word name
		struct {
			uint32_t cken_mer_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mer_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MER_W1P_P 10'h034 */
	union {
		uint32_t mer_w1p_p; // word name
		struct {
			uint32_t sw_rst_mer_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NRW_RW_K 10'h038 */
	union {
		uint32_t nrw_rw_k; // word name
		struct {
			uint32_t cken_nrw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_nrw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NRW_W1P_K 10'h03C */
	union {
		uint32_t nrw_w1p_k; // word name
		struct {
			uint32_t sw_rst_nrw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NRW_WR_D 10'h040 */
	union {
		uint32_t nrw_wr_d; // word name
		struct {
			uint32_t cken_nrw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_nrw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NRW_W1P_D 10'h044 */
	union {
		uint32_t nrw_w1p_d; // word name
		struct {
			uint32_t sw_rst_nrw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NRW_RW_P 10'h048 */
	union {
		uint32_t nrw_rw_p; // word name
		struct {
			uint32_t cken_nrw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_nrw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NRW_W1P_P 10'h04C */
	union {
		uint32_t nrw_w1p_p; // word name
		struct {
			uint32_t sw_rst_nrw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8R_RW_K 10'h050 */
	union {
		uint32_t mv8r_rw_k; // word name
		struct {
			uint32_t cken_mv8r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mv8r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8R_W1P_K 10'h054 */
	union {
		uint32_t mv8r_w1p_k; // word name
		struct {
			uint32_t sw_rst_mv8r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8R_WR_D 10'h058 */
	union {
		uint32_t mv8r_wr_d; // word name
		struct {
			uint32_t cken_mv8r_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mv8r_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8R_W1P_D 10'h05C */
	union {
		uint32_t mv8r_w1p_d; // word name
		struct {
			uint32_t sw_rst_mv8r_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8R_RW_P 10'h060 */
	union {
		uint32_t mv8r_rw_p; // word name
		struct {
			uint32_t cken_mv8r_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mv8r_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8R_W1P_P 10'h064 */
	union {
		uint32_t mv8r_w1p_p; // word name
		struct {
			uint32_t sw_rst_mv8r_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8W_RW_K 10'h068 */
	union {
		uint32_t mv8w_rw_k; // word name
		struct {
			uint32_t cken_mv8w_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mv8w_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8W_W1P_K 10'h06C */
	union {
		uint32_t mv8w_w1p_k; // word name
		struct {
			uint32_t sw_rst_mv8w_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8W_WR_D 10'h070 */
	union {
		uint32_t mv8w_wr_d; // word name
		struct {
			uint32_t cken_mv8w_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mv8w_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8W_W1P_D 10'h074 */
	union {
		uint32_t mv8w_w1p_d; // word name
		struct {
			uint32_t sw_rst_mv8w_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8W_RW_P 10'h078 */
	union {
		uint32_t mv8w_rw_p; // word name
		struct {
			uint32_t cken_mv8w_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_mv8w_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MV8W_W1P_P 10'h07C */
	union {
		uint32_t mv8w_w1p_p; // word name
		struct {
			uint32_t sw_rst_mv8w_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MVW_RW_K 10'h080 */
	union {
		uint32_t venc_mvw_rw_k; // word name
		struct {
			uint32_t cken_venc_mvw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_venc_mvw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MVW_W1P_K 10'h084 */
	union {
		uint32_t venc_mvw_w1p_k; // word name
		struct {
			uint32_t sw_rst_venc_mvw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MVW_WR_D 10'h088 */
	union {
		uint32_t venc_mvw_wr_d; // word name
		struct {
			uint32_t cken_venc_mvw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_venc_mvw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MVW_W1P_D 10'h08C */
	union {
		uint32_t venc_mvw_w1p_d; // word name
		struct {
			uint32_t sw_rst_venc_mvw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MVW_RW_P 10'h090 */
	union {
		uint32_t venc_mvw_rw_p; // word name
		struct {
			uint32_t cken_venc_mvw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_venc_mvw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MVW_W1P_P 10'h094 */
	union {
		uint32_t venc_mvw_w1p_p; // word name
		struct {
			uint32_t sw_rst_venc_mvw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UNPACKER_RW_K 10'h098 */
	union {
		uint32_t unpacker_rw_k; // word name
		struct {
			uint32_t cken_unpacker_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_unpacker_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UNPACKER_W1P_K 10'h09C */
	union {
		uint32_t unpacker_w1p_k; // word name
		struct {
			uint32_t sw_rst_unpacker_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B2R_RW_K 10'h0A0 */
	union {
		uint32_t b2r_rw_k; // word name
		struct {
			uint32_t cken_b2r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_b2r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B2R_W1P_K 10'h0A4 */
	union {
		uint32_t b2r_w1p_k; // word name
		struct {
			uint32_t sw_rst_b2r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B2R_RW_P 10'h0A8 */
	union {
		uint32_t b2r_rw_p; // word name
		struct {
			uint32_t cken_b2r_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_b2r_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B2R_W1P_P 10'h0AC */
	union {
		uint32_t b2r_w1p_p; // word name
		struct {
			uint32_t sw_rst_b2r_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPPUP_RW_K 10'h0B0 */
	union {
		uint32_t vppup_rw_k; // word name
		struct {
			uint32_t cken_vppup_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vppup_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPPUP_W1P_K 10'h0B4 */
	union {
		uint32_t vppup_w1p_k; // word name
		struct {
			uint32_t sw_rst_vppup_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPPUP_RW_P 10'h0B8 */
	union {
		uint32_t vppup_rw_p; // word name
		struct {
			uint32_t cken_vppup_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vppup_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPPUP_W1P_P 10'h0BC */
	union {
		uint32_t vppup_w1p_p; // word name
		struct {
			uint32_t sw_rst_vppup_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPLP_RW_K 10'h0C0 */
	union {
		uint32_t vplp_rw_k; // word name
		struct {
			uint32_t cken_vplp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vplp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPLP_W1P_K 10'h0C4 */
	union {
		uint32_t vplp_w1p_k; // word name
		struct {
			uint32_t sw_rst_vplp_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPLP_RW_P 10'h0C8 */
	union {
		uint32_t vplp_rw_p; // word name
		struct {
			uint32_t cken_vplp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vplp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPLP_W1P_P 10'h0CC */
	union {
		uint32_t vplp_w1p_p; // word name
		struct {
			uint32_t sw_rst_vplp_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW0_RW_K 10'h0D0 */
	union {
		uint32_t vpw0_rw_k; // word name
		struct {
			uint32_t cken_vpw0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW0_W1P_K 10'h0D4 */
	union {
		uint32_t vpw0_w1p_k; // word name
		struct {
			uint32_t sw_rst_vpw0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW0_WR_D 10'h0D8 */
	union {
		uint32_t vpw0_wr_d; // word name
		struct {
			uint32_t cken_vpw0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW0_W1P_D 10'h0DC */
	union {
		uint32_t vpw0_w1p_d; // word name
		struct {
			uint32_t sw_rst_vpw0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW0_RW_P 10'h0E0 */
	union {
		uint32_t vpw0_rw_p; // word name
		struct {
			uint32_t cken_vpw0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW0_W1P_P 10'h0E4 */
	union {
		uint32_t vpw0_w1p_p; // word name
		struct {
			uint32_t sw_rst_vpw0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW1_RW_K 10'h0E8 */
	union {
		uint32_t vpw1_rw_k; // word name
		struct {
			uint32_t cken_vpw1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW1_W1P_K 10'h0EC */
	union {
		uint32_t vpw1_w1p_k; // word name
		struct {
			uint32_t sw_rst_vpw1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW1_WR_D 10'h0F0 */
	union {
		uint32_t vpw1_wr_d; // word name
		struct {
			uint32_t cken_vpw1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW1_W1P_D 10'h0F4 */
	union {
		uint32_t vpw1_w1p_d; // word name
		struct {
			uint32_t sw_rst_vpw1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW1_RW_P 10'h0F8 */
	union {
		uint32_t vpw1_rw_p; // word name
		struct {
			uint32_t cken_vpw1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW1_W1P_P 10'h0FC */
	union {
		uint32_t vpw1_w1p_p; // word name
		struct {
			uint32_t sw_rst_vpw1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW2_RW_K 10'h100 */
	union {
		uint32_t vpw2_rw_k; // word name
		struct {
			uint32_t cken_vpw2_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw2_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW2_W1P_K 10'h104 */
	union {
		uint32_t vpw2_w1p_k; // word name
		struct {
			uint32_t sw_rst_vpw2_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW2_WR_D 10'h108 */
	union {
		uint32_t vpw2_wr_d; // word name
		struct {
			uint32_t cken_vpw2_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw2_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW2_W1P_D 10'h10C */
	union {
		uint32_t vpw2_w1p_d; // word name
		struct {
			uint32_t sw_rst_vpw2_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW2_RW_P 10'h110 */
	union {
		uint32_t vpw2_rw_p; // word name
		struct {
			uint32_t cken_vpw2_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vpw2_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW2_W1P_P 10'h114 */
	union {
		uint32_t vpw2_w1p_p; // word name
		struct {
			uint32_t sw_rst_vpw2_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL_RW_K 10'h118 */
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
	/* CTRL_W1P_K 10'h11C */
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
} CsrBankVp_cfg;

#endif