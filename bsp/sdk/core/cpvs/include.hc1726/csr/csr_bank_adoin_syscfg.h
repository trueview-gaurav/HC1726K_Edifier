/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ADOIN_SYSCFG_H_
#define CSR_BANK_ADOIN_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adoin_syscfg  ***/
typedef struct csr_bank_adoin_syscfg {
	/* AADC_L_RW_K 10'h000 */
	union {
		uint32_t aadc_l_rw_k; // word name
		struct {
			uint32_t cken_aadc_l_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_aadc_l_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_L_W1P_K 10'h004 */
	union {
		uint32_t aadc_l_w1p_k; // word name
		struct {
			uint32_t sw_rst_aadc_l_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_L_RW_P 10'h008 */
	union {
		uint32_t aadc_l_rw_p; // word name
		struct {
			uint32_t cken_aadc_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_aadc_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_L_W1P_P 10'h00C */
	union {
		uint32_t aadc_l_w1p_p; // word name
		struct {
			uint32_t sw_rst_aadc_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_R_RW_K 10'h010 */
	union {
		uint32_t aadc_r_rw_k; // word name
		struct {
			uint32_t cken_aadc_r_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_aadc_r_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_R_W1P_K 10'h014 */
	union {
		uint32_t aadc_r_w1p_k; // word name
		struct {
			uint32_t sw_rst_aadc_r_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_R_RW_P 10'h018 */
	union {
		uint32_t aadc_r_rw_p; // word name
		struct {
			uint32_t cken_aadc_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_aadc_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_R_W1P_P 10'h01C */
	union {
		uint32_t aadc_r_w1p_p; // word name
		struct {
			uint32_t sw_rst_aadc_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_COMB_L_RW_K 10'h020 */
	union {
		uint32_t amic_comb_l_rw_k; // word name
		struct {
			uint32_t cken_amic_comb_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_amic_comb_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_COMB_L_W1P_K 10'h024 */
	union {
		uint32_t amic_comb_l_w1p_k; // word name
		struct {
			uint32_t sw_rst_amic_comb_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_COMB_R_RW_K 10'h028 */
	union {
		uint32_t amic_comb_r_rw_k; // word name
		struct {
			uint32_t cken_amic_comb_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_amic_comb_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_COMB_R_W1P_K 10'h02C */
	union {
		uint32_t amic_comb_r_w1p_k; // word name
		struct {
			uint32_t sw_rst_amic_comb_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_AGC_L_RW_K 10'h030 */
	union {
		uint32_t amic_agc_l_rw_k; // word name
		struct {
			uint32_t cken_amic_agc_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_amic_agc_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_AGC_L_W1P_K 10'h034 */
	union {
		uint32_t amic_agc_l_w1p_k; // word name
		struct {
			uint32_t sw_rst_amic_agc_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_AGC_R_RW_K 10'h038 */
	union {
		uint32_t amic_agc_r_rw_k; // word name
		struct {
			uint32_t cken_amic_agc_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_amic_agc_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_AGC_R_W1P_K 10'h03C */
	union {
		uint32_t amic_agc_r_w1p_k; // word name
		struct {
			uint32_t sw_rst_amic_agc_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_L_RW_P 10'h040 */
	union {
		uint32_t amic_l_rw_p; // word name
		struct {
			uint32_t cken_amic_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_amic_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_L_W1P_P 10'h044 */
	union {
		uint32_t amic_l_w1p_p; // word name
		struct {
			uint32_t sw_rst_amic_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_R_RW_P 10'h048 */
	union {
		uint32_t amic_r_rw_p; // word name
		struct {
			uint32_t cken_amic_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_amic_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMIC_R_W1P_P 10'h04C */
	union {
		uint32_t amic_r_w1p_p; // word name
		struct {
			uint32_t sw_rst_amic_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_DR_L_RW_K 10'h050 */
	union {
		uint32_t dmic_dr_l_rw_k; // word name
		struct {
			uint32_t cken_dmic_dr_l_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmic_dr_l_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_DR_L_W1P_K 10'h054 */
	union {
		uint32_t dmic_dr_l_w1p_k; // word name
		struct {
			uint32_t sw_rst_dmic_dr_l_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_DR_R_RW_K 10'h058 */
	union {
		uint32_t dmic_dr_r_rw_k; // word name
		struct {
			uint32_t cken_dmic_dr_r_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmic_dr_r_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_DR_R_W1P_K 10'h05C */
	union {
		uint32_t dmic_dr_r_w1p_k; // word name
		struct {
			uint32_t sw_rst_dmic_dr_r_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_COMB_L_RW_K 10'h060 */
	union {
		uint32_t dmic_comb_l_rw_k; // word name
		struct {
			uint32_t cken_dmic_comb_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmic_comb_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_COMB_L_W1P_K 10'h064 */
	union {
		uint32_t dmic_comb_l_w1p_k; // word name
		struct {
			uint32_t sw_rst_dmic_comb_l_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_COMB_R_RW_K 10'h068 */
	union {
		uint32_t dmic_comb_r_rw_k; // word name
		struct {
			uint32_t cken_dmic_comb_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmic_comb_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_COMB_R_W1P_K 10'h06C */
	union {
		uint32_t dmic_comb_r_w1p_k; // word name
		struct {
			uint32_t sw_rst_dmic_comb_r_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_L_RW_P 10'h070 */
	union {
		uint32_t dmic_l_rw_p; // word name
		struct {
			uint32_t cken_dmic_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmic_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_L_W1P_P 10'h074 */
	union {
		uint32_t dmic_l_w1p_p; // word name
		struct {
			uint32_t sw_rst_dmic_l_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_R_RW_P 10'h078 */
	union {
		uint32_t dmic_r_rw_p; // word name
		struct {
			uint32_t cken_dmic_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmic_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMIC_R_W1P_P 10'h07C */
	union {
		uint32_t dmic_r_w1p_p; // word name
		struct {
			uint32_t sw_rst_dmic_r_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWAP_RW_K 10'h080 */
	union {
		uint32_t swap_rw_k; // word name
		struct {
			uint32_t cken_swap_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_swap_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWAP_W1P_K 10'h084 */
	union {
		uint32_t swap_w1p_k; // word name
		struct {
			uint32_t sw_rst_swap_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PACKER_RW_K 10'h088 */
	union {
		uint32_t packer_rw_k; // word name
		struct {
			uint32_t cken_packer_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_packer_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PACKER_W1P_K 10'h08C */
	union {
		uint32_t packer_w1p_k; // word name
		struct {
			uint32_t sw_rst_packer_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_RW_K 10'h090 */
	union {
		uint32_t i2s_rw_k; // word name
		struct {
			uint32_t cken_i2s_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_i2s_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_W1P_K 10'h094 */
	union {
		uint32_t i2s_w1p_k; // word name
		struct {
			uint32_t sw_rst_i2s_k_x20 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_RW_P 10'h098 */
	union {
		uint32_t i2s_rw_p; // word name
		struct {
			uint32_t cken_i2s_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_i2s_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_W1P_P 10'h09C */
	union {
		uint32_t i2s_w1p_p; // word name
		struct {
			uint32_t sw_rst_i2s_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WRITE_RW_K 10'h0A0 */
	union {
		uint32_t write_rw_k; // word name
		struct {
			uint32_t cken_write_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_write_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WRITE_W1P_K 10'h0A4 */
	union {
		uint32_t write_w1p_k; // word name
		struct {
			uint32_t sw_rst_write_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WRITE_RW_D 10'h0A8 */
	union {
		uint32_t write_rw_d; // word name
		struct {
			uint32_t cken_write_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_write_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WRITE_W1P_D 10'h0AC */
	union {
		uint32_t write_w1p_d; // word name
		struct {
			uint32_t sw_rst_write_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WRITE_RW_P 10'h0B0 */
	union {
		uint32_t write_rw_p; // word name
		struct {
			uint32_t cken_write_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_write_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WRITE_W1P_P 10'h0B4 */
	union {
		uint32_t write_w1p_p; // word name
		struct {
			uint32_t sw_rst_write_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SAADC_RW_K 10'h0B8 */
	union {
		uint32_t saadc_rw_k; // word name
		struct {
			uint32_t cken_saadc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_saadc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SAADC_W1P_K 10'h0BC */
	union {
		uint32_t saadc_w1p_k; // word name
		struct {
			uint32_t sw_rst_saadc_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SAADC_RW_P 10'h0C0 */
	union {
		uint32_t saadc_rw_p; // word name
		struct {
			uint32_t cken_saadc_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_saadc_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SAADC_W1P_P 10'h0C4 */
	union {
		uint32_t saadc_w1p_p; // word name
		struct {
			uint32_t sw_rst_saadc_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ST_RW_K 10'h0C8 */
	union {
		uint32_t st_rw_k; // word name
		struct {
			uint32_t cken_st_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_st_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ST_W1P_K 10'h0CC */
	union {
		uint32_t st_w1p_k; // word name
		struct {
			uint32_t sw_rst_st_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ST_RW_P 10'h0D0 */
	union {
		uint32_t st_rw_p; // word name
		struct {
			uint32_t cken_st_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_st_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ST_W1P_P 10'h0D4 */
	union {
		uint32_t st_w1p_p; // word name
		struct {
			uint32_t sw_rst_st_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LDO_RW_P 10'h0D8 */
	union {
		uint32_t ldo_rw_p; // word name
		struct {
			uint32_t cken_ldo_p : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ldo_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LDO_W1P_P 10'h0DC */
	union {
		uint32_t ldo_w1p_p; // word name
		struct {
			uint32_t sw_rst_ldo_p : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G2C_RW_K 10'h0E0 */
	union {
		uint32_t g2c_rw_k; // word name
		struct {
			uint32_t cken_g2c_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_g2c_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G2C_W1P_K 10'h0E4 */
	union {
		uint32_t g2c_w1p_k; // word name
		struct {
			uint32_t sw_rst_g2c_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdoin_syscfg;

#endif
