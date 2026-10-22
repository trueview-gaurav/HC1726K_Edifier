/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_IS_CFG_H_
#define CSR_BANK_IS_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from is_cfg  ***/
typedef struct csr_bank_is_cfg {
	/* CKEN0 10'h000 */
	union {
		uint32_t cken0; // word name
		struct {
			uint32_t cken_isr0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isr1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_fe0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_fe1_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN1 10'h004 */
	union {
		uint32_t cken1; // word name
		struct {
			uint32_t cken_isk0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isk1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_bspshb_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_fscshb_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN2 10'h008 */
	union {
		uint32_t cken2; // word name
		struct {
			uint32_t cken_isw0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw2_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw3_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN3 10'h00C */
	union {
		uint32_t cken3; // word name
		struct {
			uint32_t cken_checksum_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_ctrl_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_csr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVLRST0 10'h010 */
	union {
		uint32_t lvlrst0; // word name
		struct {
			uint32_t lv_rst_isr0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isr1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fe0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fe1_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST1 10'h014 */
	union {
		uint32_t lvlrst1; // word name
		struct {
			uint32_t lv_rst_isk0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isk1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bspshb_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fscshb_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST2 10'h018 */
	union {
		uint32_t lvlrst2; // word name
		struct {
			uint32_t lv_rst_isw0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw2_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw3_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST3 10'h01C */
	union {
		uint32_t lvlrst3; // word name
		struct {
			uint32_t lv_rst_checksum_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ctrl_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_csr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWRST0 10'h020 */
	union {
		uint32_t swrst0; // word name
		struct {
			uint32_t sw_rst_isr0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isr1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_fe0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_fe1_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST1 10'h024 */
	union {
		uint32_t swrst1; // word name
		struct {
			uint32_t sw_rst_isk0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isk1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_bspshb_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_fscshb_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST2 10'h028 */
	union {
		uint32_t swrst2; // word name
		struct {
			uint32_t sw_rst_isw0_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw1_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw2_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw3_k : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST3 10'h02C */
	union {
		uint32_t swrst3; // word name
		struct {
			uint32_t sw_rst_checksum_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_ctrl_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_csr_k : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKEN4 10'h030 */
	union {
		uint32_t cken4; // word name
		struct {
			uint32_t cken_isr0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isr1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isk0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isk1_d : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN5 10'h034 */
	union {
		uint32_t cken5; // word name
		struct {
			uint32_t cken_isw0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw2_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw3_d : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN6 10'h038 */
	union {
		uint32_t cken6; // word name
		struct {
			uint32_t cken_checksum_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVLRST4 10'h03C */
	union {
		uint32_t lvlrst4; // word name
		struct {
			uint32_t lv_rst_isr0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isr1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isk0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isk1_d : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST5 10'h040 */
	union {
		uint32_t lvlrst5; // word name
		struct {
			uint32_t lv_rst_isw0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw2_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw3_d : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST6 10'h044 */
	union {
		uint32_t lvlrst6; // word name
		struct {
			uint32_t lv_rst_checksum_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWRST4 10'h048 */
	union {
		uint32_t swrst4; // word name
		struct {
			uint32_t sw_rst_isr0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isr1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isk0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isk1_d : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST5 10'h04C */
	union {
		uint32_t swrst5; // word name
		struct {
			uint32_t sw_rst_isw0_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw1_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw2_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw3_d : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST6 10'h050 */
	union {
		uint32_t swrst6; // word name
		struct {
			uint32_t sw_rst_checksum_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKEN7 10'h054 */
	union {
		uint32_t cken7; // word name
		struct {
			uint32_t cken_isr0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isr1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_fe0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_fe1_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN8 10'h058 */
	union {
		uint32_t cken8; // word name
		struct {
			uint32_t cken_isk0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isk1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_checksum_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_csr_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN9 10'h05C */
	union {
		uint32_t cken9; // word name
		struct {
			uint32_t cken_isw0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw2_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw3_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST7 10'h060 */
	union {
		uint32_t lvlrst7; // word name
		struct {
			uint32_t lv_rst_isr0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isr1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fe0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fe1_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST8 10'h064 */
	union {
		uint32_t lvlrst8; // word name
		struct {
			uint32_t lv_rst_isk0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isk1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_checksum_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_csr_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST9 10'h068 */
	union {
		uint32_t lvlrst9; // word name
		struct {
			uint32_t lv_rst_isw0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw2_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw3_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST7 10'h06C */
	union {
		uint32_t swrst7; // word name
		struct {
			uint32_t sw_rst_isr0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isr1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_fe0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_fe1_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST8 10'h070 */
	union {
		uint32_t swrst8; // word name
		struct {
			uint32_t sw_rst_isk0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isk1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_checksum_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_csr_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST9 10'h074 */
	union {
		uint32_t swrst9; // word name
		struct {
			uint32_t sw_rst_isw0_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw1_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw2_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw3_p_clk_g : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKEN10 10'h078 */
	union {
		uint32_t cken10; // word name
		struct {
			uint32_t cken_fe0_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_fe1_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKEN11 10'h07C */
	union {
		uint32_t cken11; // word name
		struct {
			uint32_t cken_isw0_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw1_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw2_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_isw3_ref : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVLRST10 10'h080 */
	union {
		uint32_t lvlrst10; // word name
		struct {
			uint32_t lv_rst_fe0_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fe1_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVLRST11 10'h084 */
	union {
		uint32_t lvlrst11; // word name
		struct {
			uint32_t lv_rst_isw0_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw1_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw2_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw3_ref : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SWRST10 10'h088 */
	union {
		uint32_t swrst10; // word name
		struct {
			uint32_t sw_rst_fe0_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_fe1_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWRST11 10'h08C */
	union {
		uint32_t swrst11; // word name
		struct {
			uint32_t sw_rst_isw0_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw1_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw2_ref : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_isw3_ref : 1;
			uint32_t : 7; // padding bits
		};
	};
} CsrBankIs_cfg;

#endif