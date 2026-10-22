/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_TX_CTRL_H_
#define CSR_BANK_TX_CTRL_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from tx_ctrl  ***/
typedef struct csr_bank_tx_ctrl {
	/* CTRL_0 10'h000 */
	union {
		uint32_t ctrl_0; // word name
		struct {
			uint32_t tx_lev_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_bias_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_out_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_1 10'h004 */
	union {
		uint32_t ctrl_1; // word name
		struct {
			uint32_t tx_clk_en : 1;
			uint32_t : 3; // padding bits
			uint32_t pwr_ctrl_sel : 6;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL_2 10'h008 */
	union {
		uint32_t ctrl_2; // word name
		struct {
			uint32_t base_pwron_start : 1;
			uint32_t ln0_pwron_start : 1;
			uint32_t ln1_pwron_start : 1;
			uint32_t ln2_pwron_start : 1;
			uint32_t ln3_pwron_start : 1;
			uint32_t ln4_pwron_start : 1;
			uint32_t all_pwron_start : 1;
			uint32_t : 1; // padding bits
			uint32_t gpo_base_pwron_start : 1;
			uint32_t gpo_ln0_pwron_start : 1;
			uint32_t gpo_ln1_pwron_start : 1;
			uint32_t gpo_ln2_pwron_start : 1;
			uint32_t gpo_ln3_pwron_start : 1;
			uint32_t gpo_ln4_pwron_start : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL_LN0_A 10'h00C */
	union {
		uint32_t ctrl_ln0_a; // word name
		struct {
			uint32_t tx_ln0_lev_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln0_ref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln0_bias04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln0_bias12_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN0_B 10'h010 */
	union {
		uint32_t ctrl_ln0_b; // word name
		struct {
			uint32_t tx_ln0_out12_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln0_lp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln0_hs_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln0_oen_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN1_A 10'h014 */
	union {
		uint32_t ctrl_ln1_a; // word name
		struct {
			uint32_t tx_ln1_lev_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln1_ref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln1_bias04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln1_bias12_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN1_B 10'h018 */
	union {
		uint32_t ctrl_ln1_b; // word name
		struct {
			uint32_t tx_ln1_out12_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln1_lp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln1_hs_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln1_oen_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN2_A 10'h01C */
	union {
		uint32_t ctrl_ln2_a; // word name
		struct {
			uint32_t tx_ln2_lev_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln2_ref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln2_bias04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln2_bias12_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN2_B 10'h020 */
	union {
		uint32_t ctrl_ln2_b; // word name
		struct {
			uint32_t tx_ln2_out12_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln2_lp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln2_hs_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln2_oen_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN3_A 10'h024 */
	union {
		uint32_t ctrl_ln3_a; // word name
		struct {
			uint32_t tx_ln3_lev_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln3_ref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln3_bias04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln3_bias12_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN3_B 10'h028 */
	union {
		uint32_t ctrl_ln3_b; // word name
		struct {
			uint32_t tx_ln3_out12_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln3_lp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln3_hs_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln3_oen_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN4_A 10'h02C */
	union {
		uint32_t ctrl_ln4_a; // word name
		struct {
			uint32_t tx_ln4_lev_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln4_ref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln4_bias04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln4_bias12_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN4_B 10'h030 */
	union {
		uint32_t ctrl_ln4_b; // word name
		struct {
			uint32_t tx_ln4_out12_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln4_lp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln4_hs_en : 1;
			uint32_t : 7; // padding bits
			uint32_t tx_ln4_oen_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_BIST_START 10'h034 */
	union {
		uint32_t word_bist_start; // word name
		struct {
			uint32_t bist_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL_0 10'h038 */
	union {
		uint32_t bist_ctrl_0; // word name
		struct {
			uint32_t bist_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t bist_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t bist_crc_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* BIST_CTRL_1 10'h03C */
	union {
		uint32_t bist_ctrl_1; // word name
		struct {
			uint32_t bist_pac_di : 8;
			uint32_t bist_pac_wc : 16;
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_TIME_0 10'h040 */
	union {
		uint32_t bist_time_0; // word name
		struct {
			uint32_t t_lpx : 8;
			uint32_t t_prep : 8;
			uint32_t t_zero : 8;
			uint32_t t_trial : 8;
		};
	};
	/* BIST_TIME_1 10'h044 */
	union {
		uint32_t bist_time_1; // word name
		struct {
			uint32_t t_clk_pre : 8;
			uint32_t t_clk_post : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_LN0 10'h048 */
	union {
		uint32_t bist_ln0; // word name
		struct {
			uint32_t bist_ln0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln0_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln0_pat : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_LN1 10'h04C */
	union {
		uint32_t bist_ln1; // word name
		struct {
			uint32_t bist_ln1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln1_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln1_pat : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_LN2 10'h050 */
	union {
		uint32_t bist_ln2; // word name
		struct {
			uint32_t bist_ln2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln2_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln2_pat : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_LN3 10'h054 */
	union {
		uint32_t bist_ln3; // word name
		struct {
			uint32_t bist_ln3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln3_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln3_pat : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_LN4 10'h058 */
	union {
		uint32_t bist_ln4; // word name
		struct {
			uint32_t bist_ln4_en : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln4_clk_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_ln4_pat : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_STA_0 10'h05C */
	union {
		uint32_t bist_sta_0; // word name
		struct {
			uint32_t bist_busy : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_done : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_STA_1 10'h060 */
	union {
		uint32_t bist_sta_1; // word name
		struct {
			uint32_t bist_status : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_STA_LN0 10'h064 */
	union {
		uint32_t bist_sta_ln0; // word name
		struct {
			uint32_t bist_ln0_crc : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_STA_LN1 10'h068 */
	union {
		uint32_t bist_sta_ln1; // word name
		struct {
			uint32_t bist_ln1_crc : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_STA_LN2 10'h06C */
	union {
		uint32_t bist_sta_ln2; // word name
		struct {
			uint32_t bist_ln2_crc : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_STA_LN3 10'h070 */
	union {
		uint32_t bist_sta_ln3; // word name
		struct {
			uint32_t bist_ln3_crc : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_STA_LN4 10'h074 */
	union {
		uint32_t bist_sta_ln4; // word name
		struct {
			uint32_t bist_ln4_crc : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWR_ST0 10'h078 */
	union {
		uint32_t word_pwr_st0; // word name
		struct {
			uint32_t pwr_st0 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWR_ST1 10'h07C */
	union {
		uint32_t word_pwr_st1; // word name
		struct {
			uint32_t pwr_st1 : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* RESV 10'h080 */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankTx_ctrl;

#endif