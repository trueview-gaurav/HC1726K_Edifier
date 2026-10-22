#ifndef CSR_BANK_RX_H_
#define CSR_BANK_RX_H_

#include <linux/types.h>

/***  C struct generated from rx  ***/
typedef struct csr_bank_rx {
	/* ENABLE 10'h000 */
	union {
		uint32_t enable; // word name
		struct {
			uint32_t rx_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MAIN 10'h004 */
	union {
		uint32_t main; // word name
		struct {
			uint32_t lane_en : 5;
			uint32_t : 3; // padding bits
			uint32_t spec_mipi : 1;
			uint32_t : 3; // padding bits
			uint32_t lane_ck_en : 5;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWAP 10'h008 */
	union {
		uint32_t swap; // word name
		struct {
			uint32_t ln0_rx_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t ln1_rx_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t ln2_rx_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t ln3_rx_sel : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* TIME_0 10'h00C */
	union {
		uint32_t time_0; // word name
		struct {
			uint32_t t_da_settle : 8;
			uint32_t t_da_term_en : 8;
			uint32_t t_da_rst_src : 1;
			uint32_t : 7; // padding bits
			uint32_t t_da_rst_settle : 8;
		};
	};
	/* TIME_1 10'h010 */
	union {
		uint32_t time_1; // word name
		struct {
			uint32_t t_ck_settle : 8;
			uint32_t t_ck_term_en : 8;
			uint32_t t_ck_rst_src : 1;
			uint32_t : 7; // padding bits
			uint32_t t_ck_rst_settle : 8;
		};
	};
	/* PHY_LN0 10'h014 */
	union {
		uint32_t phy_ln0; // word name
		struct {
			uint32_t phy_ln0_hsrx_en_ctrl : 1;
			uint32_t phy_ln0_term_en_ctrl : 1;
			uint32_t phy_ln0_hssw_en_ctrl : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t phy_ln0_hsrx_en_sel : 1;
			uint32_t phy_ln0_term_en_sel : 1;
			uint32_t phy_ln0_hssw_en_sel : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PHY_LN1 10'h018 */
	union {
		uint32_t phy_ln1; // word name
		struct {
			uint32_t phy_ln1_hsrx_en_ctrl : 1;
			uint32_t phy_ln1_term_en_ctrl : 1;
			uint32_t phy_ln1_hssw_en_ctrl : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t phy_ln1_hsrx_en_sel : 1;
			uint32_t phy_ln1_term_en_sel : 1;
			uint32_t phy_ln1_hssw_en_sel : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PHY_LN2 10'h01C */
	union {
		uint32_t phy_ln2; // word name
		struct {
			uint32_t phy_ln2_hsrx_en_ctrl : 1;
			uint32_t phy_ln2_term_en_ctrl : 1;
			uint32_t phy_ln2_hssw_en_ctrl : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t phy_ln2_hsrx_en_sel : 1;
			uint32_t phy_ln2_term_en_sel : 1;
			uint32_t phy_ln2_hssw_en_sel : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PHY_LN3 10'h020 */
	union {
		uint32_t phy_ln3; // word name
		struct {
			uint32_t phy_ln3_hsrx_en_ctrl : 1;
			uint32_t phy_ln3_term_en_ctrl : 1;
			uint32_t phy_ln3_hssw_en_ctrl : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t phy_ln3_hsrx_en_sel : 1;
			uint32_t phy_ln3_term_en_sel : 1;
			uint32_t phy_ln3_hssw_en_sel : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PHY_LN4 10'h024 */
	union {
		uint32_t phy_ln4; // word name
		struct {
			uint32_t phy_ln4_hsrx_en_ctrl : 1;
			uint32_t phy_ln4_term_en_ctrl : 1;
			uint32_t phy_ln4_hssw_en_ctrl : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t phy_ln4_hsrx_en_sel : 1;
			uint32_t phy_ln4_term_en_sel : 1;
			uint32_t phy_ln4_hssw_en_sel : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PHY_HS 10'h028 */
	union {
		uint32_t phy_hs; // word name
		struct {
			uint32_t phy_clk_rstb_ctrl : 1;
			uint32_t phy_data_rstb_ctrl : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t phy_clk_rstb_sel : 1;
			uint32_t phy_data_rstb_sel : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PHY_PN 10'h02C */
	union {
		uint32_t phy_pn; // word name
		struct {
			uint32_t phy_ln0_pn_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t phy_ln1_pn_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t phy_ln2_pn_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t phy_ln3_pn_sel : 1;
			uint32_t phy_ln4_pn_sel : 1;
			uint32_t : 6; // padding bits
		};
	};
	/* BIST_0 10'h030 */
	union {
		uint32_t bist_0; // word name
		struct {
			uint32_t bist_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_crc_en : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_pac_di : 8;
			uint32_t bist_lane_en : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* BIST_1 10'h034 */
	union {
		uint32_t bist_1; // word name
		struct {
			uint32_t bist_pac_wc : 16;
			uint32_t bist_pac_crc : 16;
		};
	};
	/* BIST_2 10'h038 */
	union {
		uint32_t bist_2; // word name
		struct {
			uint32_t bist_pac_ecc : 8;
			uint32_t bist_pac_src : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_3 10'h03C [Unused] */
	uint32_t empty_word_bist_3;
	/* BIST_LN0_A 10'h040 */
	union {
		uint32_t bist_ln0_a; // word name
		struct {
			uint32_t ln0_bist_done : 1;
			uint32_t : 3; // padding bits
			uint32_t ln0_bist_fail : 4;
			uint32_t ln0_offset : 8;
			uint32_t ln0_bist_sta : 16;
		};
	};
	/* BIST_LN0_B 10'h044 */
	union {
		uint32_t bist_ln0_b; // word name
		struct {
			uint32_t ln0_bist_wc : 16;
			uint32_t ln0_bist_crc : 16;
		};
	};
	/* BIST_LN0_C 10'h048 */
	union {
		uint32_t bist_ln0_c; // word name
		struct {
			uint32_t ln0_calc_wc : 16;
			uint32_t ln0_calc_crc : 16;
		};
	};
	/* BIST_LN1_A 10'h04C */
	union {
		uint32_t bist_ln1_a; // word name
		struct {
			uint32_t ln1_bist_done : 1;
			uint32_t : 3; // padding bits
			uint32_t ln1_bist_fail : 4;
			uint32_t ln1_offset : 8;
			uint32_t ln1_bist_sta : 16;
		};
	};
	/* BIST_LN1_B 10'h050 */
	union {
		uint32_t bist_ln1_b; // word name
		struct {
			uint32_t ln1_bist_wc : 16;
			uint32_t ln1_bist_crc : 16;
		};
	};
	/* BIST_LN1_C 10'h054 */
	union {
		uint32_t bist_ln1_c; // word name
		struct {
			uint32_t ln1_calc_wc : 16;
			uint32_t ln1_calc_crc : 16;
		};
	};
	/* BIST_LN2_A 10'h058 */
	union {
		uint32_t bist_ln2_a; // word name
		struct {
			uint32_t ln2_bist_done : 1;
			uint32_t : 3; // padding bits
			uint32_t ln2_bist_fail : 4;
			uint32_t ln2_offset : 8;
			uint32_t ln2_bist_sta : 16;
		};
	};
	/* BIST_LN2_B 10'h05C */
	union {
		uint32_t bist_ln2_b; // word name
		struct {
			uint32_t ln2_bist_wc : 16;
			uint32_t ln2_bist_crc : 16;
		};
	};
	/* BIST_LN2_C 10'h060 */
	union {
		uint32_t bist_ln2_c; // word name
		struct {
			uint32_t ln2_calc_wc : 16;
			uint32_t ln2_calc_crc : 16;
		};
	};
	/* BIST_LN3_A 10'h064 */
	union {
		uint32_t bist_ln3_a; // word name
		struct {
			uint32_t ln3_bist_done : 1;
			uint32_t : 3; // padding bits
			uint32_t ln3_bist_fail : 4;
			uint32_t ln3_offset : 8;
			uint32_t ln3_bist_sta : 16;
		};
	};
	/* BIST_LN3_B 10'h068 */
	union {
		uint32_t bist_ln3_b; // word name
		struct {
			uint32_t ln3_bist_wc : 16;
			uint32_t ln3_bist_crc : 16;
		};
	};
	/* BIST_LN3_C 10'h06C */
	union {
		uint32_t bist_ln3_c; // word name
		struct {
			uint32_t ln3_calc_wc : 16;
			uint32_t ln3_calc_crc : 16;
		};
	};
	/* BIST_STA 10'h070 */
	union {
		uint32_t bist_sta; // word name
		struct {
			uint32_t bist_done : 1;
			uint32_t bist_fail : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LP_LN0_STA 10'h074 */
	union {
		uint32_t lp_ln0_sta; // word name
		struct {
			uint32_t ln0_lprx_sta : 10;
			uint32_t : 6; // padding bits
			uint32_t ln0_esc_cmd_sta : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LP_LN1_STA 10'h078 */
	union {
		uint32_t lp_ln1_sta; // word name
		struct {
			uint32_t ln1_lprx_sta : 10;
			uint32_t : 6; // padding bits
			uint32_t ln1_esc_cmd_sta : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LP_LN2_STA 10'h07C */
	union {
		uint32_t lp_ln2_sta; // word name
		struct {
			uint32_t ln2_lprx_sta : 10;
			uint32_t : 6; // padding bits
			uint32_t ln2_esc_cmd_sta : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LP_LN3_STA 10'h080 */
	union {
		uint32_t lp_ln3_sta; // word name
		struct {
			uint32_t ln3_lprx_sta : 10;
			uint32_t : 6; // padding bits
			uint32_t ln3_esc_cmd_sta : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LP_LN4_STA 10'h084 */
	union {
		uint32_t lp_ln4_sta; // word name
		struct {
			uint32_t ln4_lprx_sta : 10;
			uint32_t : 6; // padding bits
			uint32_t ln4_esc_cmd_sta : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LP_MON 10'h088 */
	union {
		uint32_t lp_mon; // word name
		struct {
			uint32_t lprx_mon : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HS_STA 10'h08C */
	union {
		uint32_t hs_sta; // word name
		struct {
			uint32_t hsrx_sta : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STA 10'h090 */
	union {
		uint32_t irq_sta; // word name
		struct {
			uint32_t status_fifo_full_err : 1;
			uint32_t status_ln0_lprx_err : 1;
			uint32_t status_ln1_lprx_err : 1;
			uint32_t status_ln2_lprx_err : 1;
			uint32_t status_ln3_lprx_err : 1;
			uint32_t status_ln4_lprx_err : 1;
			uint32_t status_ln0_ulps_req : 1;
			uint32_t status_ln1_ulps_req : 1;
			uint32_t status_ln2_ulps_req : 1;
			uint32_t status_ln3_ulps_req : 1;
			uint32_t status_ln4_ulps_req : 1;
			uint32_t status_ln0_ulps_exit : 1;
			uint32_t status_ln1_ulps_exit : 1;
			uint32_t status_ln2_ulps_exit : 1;
			uint32_t status_ln3_ulps_exit : 1;
			uint32_t status_ln4_ulps_exit : 1;
			uint32_t status_ln0_esc_cmd : 1;
			uint32_t status_ln1_esc_cmd : 1;
			uint32_t status_ln2_esc_cmd : 1;
			uint32_t status_ln3_esc_cmd : 1;
			uint32_t status_ln4_esc_cmd : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MSK 10'h094 */
	union {
		uint32_t irq_msk; // word name
		struct {
			uint32_t irq_mask_fifo_full_err : 1;
			uint32_t irq_mask_ln0_lprx_err : 1;
			uint32_t irq_mask_ln1_lprx_err : 1;
			uint32_t irq_mask_ln2_lprx_err : 1;
			uint32_t irq_mask_ln3_lprx_err : 1;
			uint32_t irq_mask_ln4_lprx_err : 1;
			uint32_t irq_mask_ln0_ulps_req : 1;
			uint32_t irq_mask_ln1_ulps_req : 1;
			uint32_t irq_mask_ln2_ulps_req : 1;
			uint32_t irq_mask_ln3_ulps_req : 1;
			uint32_t irq_mask_ln4_ulps_req : 1;
			uint32_t irq_mask_ln0_ulps_exit : 1;
			uint32_t irq_mask_ln1_ulps_exit : 1;
			uint32_t irq_mask_ln2_ulps_exit : 1;
			uint32_t irq_mask_ln3_ulps_exit : 1;
			uint32_t irq_mask_ln4_ulps_exit : 1;
			uint32_t irq_mask_ln0_esc_cmd : 1;
			uint32_t irq_mask_ln1_esc_cmd : 1;
			uint32_t irq_mask_ln2_esc_cmd : 1;
			uint32_t irq_mask_ln3_esc_cmd : 1;
			uint32_t irq_mask_ln4_esc_cmd : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_ACK 10'h098 */
	union {
		uint32_t irq_ack; // word name
		struct {
			uint32_t irq_clear_fifo_full_err : 1;
			uint32_t irq_clear_ln0_lprx_err : 1;
			uint32_t irq_clear_ln1_lprx_err : 1;
			uint32_t irq_clear_ln2_lprx_err : 1;
			uint32_t irq_clear_ln3_lprx_err : 1;
			uint32_t irq_clear_ln4_lprx_err : 1;
			uint32_t irq_clear_ln0_ulps_req : 1;
			uint32_t irq_clear_ln1_ulps_req : 1;
			uint32_t irq_clear_ln2_ulps_req : 1;
			uint32_t irq_clear_ln3_ulps_req : 1;
			uint32_t irq_clear_ln4_ulps_req : 1;
			uint32_t irq_clear_ln0_ulps_exit : 1;
			uint32_t irq_clear_ln1_ulps_exit : 1;
			uint32_t irq_clear_ln2_ulps_exit : 1;
			uint32_t irq_clear_ln3_ulps_exit : 1;
			uint32_t irq_clear_ln4_ulps_exit : 1;
			uint32_t irq_clear_ln0_esc_cmd : 1;
			uint32_t irq_clear_ln1_esc_cmd : 1;
			uint32_t irq_clear_ln2_esc_cmd : 1;
			uint32_t irq_clear_ln3_esc_cmd : 1;
			uint32_t irq_clear_ln4_esc_cmd : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVDS_RX39 10'h09C [Unused] */
	uint32_t empty_word_lvds_rx39;
	/* DBG_CTRL 10'h0A0 */
	union {
		uint32_t dbg_ctrl; // word name
		struct {
			uint32_t debug_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_MON 10'h0A4 */
	union {
		uint32_t dbg_mon; // word name
		struct {
			uint32_t debug_sta : 32;
		};
	};
	/* LVDS_RX42 10'h0A8 [Unused] */
	uint32_t empty_word_lvds_rx42;
	/* LVDS_RX43 10'h0AC [Unused] */
	uint32_t empty_word_lvds_rx43;
	/* LVDS_RX44 10'h0B0 [Unused] */
	uint32_t empty_word_lvds_rx44;
	/* LVDS_RX45 10'h0B4 [Unused] */
	uint32_t empty_word_lvds_rx45;
	/* RESV_0 10'h0B8 */
	union {
		uint32_t resv_0; // word name
		struct {
			uint32_t reserved_0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV_1 10'h0BC */
	union {
		uint32_t resv_1; // word name
		struct {
			uint32_t reserved_1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankRx;

#endif