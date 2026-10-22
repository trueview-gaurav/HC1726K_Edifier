/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_RX_H_
#define CSR_TABLE_RX_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_rx[] = {
	// WORD enable
	{ "rx_en", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "ENABLE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD main
	{ "lane_en", 0x00000004, 3, 0, CSR_RW, 0x00000005 },
	{ "spec_mipi", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "lane_ck_en", 0x00000004, 15, 12, CSR_RW, 0x00000002 },
	{ "MAIN", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD swap
	{ "ln0_rx_sel", 0x00000008, 1, 0, CSR_RW, 0x00000000 },
	{ "ln1_rx_sel", 0x00000008, 9, 8, CSR_RW, 0x00000001 },
	{ "SWAP", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD time_0
	{ "t_da_settle", 0x0000000C, 7, 0, CSR_RW, 0x00000011 },
	{ "t_da_term_en", 0x0000000C, 15, 8, CSR_RW, 0x00000001 },
	{ "t_da_rst_src", 0x0000000C, 16, 16, CSR_RW, 0x00000000 },
	{ "t_da_rst_settle", 0x0000000C, 31, 24, CSR_RW, 0x00000005 },
	{ "TIME_0", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD time_1
	{ "t_ck_settle", 0x00000010, 7, 0, CSR_RW, 0x00000025 },
	{ "t_ck_term_en", 0x00000010, 15, 8, CSR_RW, 0x00000001 },
	{ "t_ck_rst_src", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "t_ck_rst_settle", 0x00000010, 31, 24, CSR_RW, 0x00000016 },
	{ "TIME_1", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_ln0
	{ "phy_ln0_hsrx_en_ctrl", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "phy_ln0_term_en_ctrl", 0x00000014, 1, 1, CSR_RW, 0x00000000 },
	{ "phy_ln0_hssw_en_ctrl", 0x00000014, 2, 2, CSR_RW, 0x00000000 },
	{ "phy_ln0_hsrx_en_sel", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "phy_ln0_term_en_sel", 0x00000014, 17, 17, CSR_RW, 0x00000000 },
	{ "phy_ln0_hssw_en_sel", 0x00000014, 18, 18, CSR_RW, 0x00000000 },
	{ "PHY_LN0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_ln1
	{ "phy_ln1_hsrx_en_ctrl", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "phy_ln1_term_en_ctrl", 0x00000018, 1, 1, CSR_RW, 0x00000000 },
	{ "phy_ln1_hssw_en_ctrl", 0x00000018, 2, 2, CSR_RW, 0x00000000 },
	{ "phy_ln1_hsrx_en_sel", 0x00000018, 16, 16, CSR_RW, 0x00000000 },
	{ "phy_ln1_term_en_sel", 0x00000018, 17, 17, CSR_RW, 0x00000000 },
	{ "phy_ln1_hssw_en_sel", 0x00000018, 18, 18, CSR_RW, 0x00000000 },
	{ "PHY_LN1", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_ln2
	{ "phy_ln2_hsrx_en_ctrl", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "phy_ln2_term_en_ctrl", 0x0000001C, 1, 1, CSR_RW, 0x00000000 },
	{ "phy_ln2_hssw_en_ctrl", 0x0000001C, 2, 2, CSR_RW, 0x00000000 },
	{ "phy_ln2_hsrx_en_sel", 0x0000001C, 16, 16, CSR_RW, 0x00000000 },
	{ "phy_ln2_term_en_sel", 0x0000001C, 17, 17, CSR_RW, 0x00000000 },
	{ "phy_ln2_hssw_en_sel", 0x0000001C, 18, 18, CSR_RW, 0x00000000 },
	{ "PHY_LN2", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_ln3
	{ "phy_ln3_hsrx_en_ctrl", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "phy_ln3_term_en_ctrl", 0x00000020, 1, 1, CSR_RW, 0x00000000 },
	{ "phy_ln3_hssw_en_ctrl", 0x00000020, 2, 2, CSR_RW, 0x00000000 },
	{ "phy_ln3_hsrx_en_sel", 0x00000020, 16, 16, CSR_RW, 0x00000000 },
	{ "phy_ln3_term_en_sel", 0x00000020, 17, 17, CSR_RW, 0x00000000 },
	{ "phy_ln3_hssw_en_sel", 0x00000020, 18, 18, CSR_RW, 0x00000000 },
	{ "PHY_LN3", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_hs
	{ "phy_clk0_rstb_ctrl", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "phy_data0_rstb_ctrl", 0x00000024, 1, 1, CSR_RW, 0x00000000 },
	{ "phy_clk1_rstb_ctrl", 0x00000024, 4, 4, CSR_RW, 0x00000000 },
	{ "phy_data1_rstb_ctrl", 0x00000024, 5, 5, CSR_RW, 0x00000000 },
	{ "phy_clk0_rstb_sel", 0x00000024, 16, 16, CSR_RW, 0x00000000 },
	{ "phy_data0_rstb_sel", 0x00000024, 17, 17, CSR_RW, 0x00000000 },
	{ "phy_clk1_rstb_sel", 0x00000024, 20, 20, CSR_RW, 0x00000000 },
	{ "phy_data1_rstb_sel", 0x00000024, 21, 21, CSR_RW, 0x00000000 },
	{ "PHY_HS", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD phy_pn
	{ "phy_ln0_pn_sel", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "phy_ln1_pn_sel", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "phy_ln2_pn_sel", 0x00000028, 16, 16, CSR_RW, 0x00000000 },
	{ "phy_ln3_pn_sel", 0x00000028, 24, 24, CSR_RW, 0x00000000 },
	{ "PHY_PN", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_0
	{ "bist_mode", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "bist_crc_en", 0x0000002C, 8, 8, CSR_RW, 0x00000001 },
	{ "bist_pac_di", 0x0000002C, 23, 16, CSR_RW, 0x00000029 },
	{ "bist_lane_en", 0x0000002C, 27, 24, CSR_RW, 0x00000000 },
	{ "BIST_0", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_1
	{ "bist_pac_wc", 0x00000030, 15, 0, CSR_RW, 0x00000400 },
	{ "bist_pac_crc", 0x00000030, 31, 16, CSR_RW, 0x0000FFFF },
	{ "BIST_1", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_2
	{ "bist_pac_ecc", 0x00000034, 7, 0, CSR_RW, 0x000000FF },
	{ "bist_pac_src", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "BIST_2", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_ln0_a
	{ "ln0_bist_done", 0x00000038, 0, 0, CSR_RO, 0x00000000 },
	{ "ln0_bist_fail", 0x00000038, 7, 4, CSR_RO, 0x00000000 },
	{ "ln0_offset", 0x00000038, 15, 8, CSR_RO, 0x00000000 },
	{ "ln0_bist_sta", 0x00000038, 31, 16, CSR_RO, 0x00000000 },
	{ "BIST_LN0_A", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD bist_ln0_b
	{ "ln0_bist_wc", 0x0000003C, 15, 0, CSR_RO, 0x00000000 },
	{ "ln0_bist_crc", 0x0000003C, 31, 16, CSR_RO, 0x00000000 },
	{ "BIST_LN0_B", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD bist_ln0_c
	{ "ln0_calc_wc", 0x00000040, 15, 0, CSR_RO, 0x00000000 },
	{ "ln0_calc_crc", 0x00000040, 31, 16, CSR_RO, 0x00000000 },
	{ "BIST_LN0_C", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD bist_ln1_a
	{ "ln1_bist_done", 0x00000044, 0, 0, CSR_RO, 0x00000000 },
	{ "ln1_bist_fail", 0x00000044, 7, 4, CSR_RO, 0x00000000 },
	{ "ln1_offset", 0x00000044, 15, 8, CSR_RO, 0x00000000 },
	{ "ln1_bist_sta", 0x00000044, 31, 16, CSR_RO, 0x00000000 },
	{ "BIST_LN1_A", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD bist_ln1_b
	{ "ln1_bist_wc", 0x00000048, 15, 0, CSR_RO, 0x00000000 },
	{ "ln1_bist_crc", 0x00000048, 31, 16, CSR_RO, 0x00000000 },
	{ "BIST_LN1_B", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD bist_ln1_c
	{ "ln1_calc_wc", 0x0000004C, 15, 0, CSR_RO, 0x00000000 },
	{ "ln1_calc_crc", 0x0000004C, 31, 16, CSR_RO, 0x00000000 },
	{ "BIST_LN1_C", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD bist_sta
	{ "bist_done", 0x00000050, 0, 0, CSR_RO, 0x00000000 },
	{ "bist_fail", 0x00000050, 1, 1, CSR_RO, 0x00000000 },
	{ "BIST_STA", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD lp_ln0_sta
	{ "ln0_lprx_sta", 0x00000054, 9, 0, CSR_RO, 0x00000000 },
	{ "ln0_esc_cmd_sta", 0x00000054, 27, 16, CSR_RO, 0x00000000 },
	{ "LP_LN0_STA", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD lp_ln1_sta
	{ "ln1_lprx_sta", 0x00000058, 9, 0, CSR_RO, 0x00000000 },
	{ "ln1_esc_cmd_sta", 0x00000058, 27, 16, CSR_RO, 0x00000000 },
	{ "LP_LN1_STA", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD lp_ln2_sta
	{ "ln2_lprx_sta", 0x0000005C, 9, 0, CSR_RO, 0x00000000 },
	{ "ln2_esc_cmd_sta", 0x0000005C, 27, 16, CSR_RO, 0x00000000 },
	{ "LP_LN2_STA", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD lp_ln3_sta
	{ "ln3_lprx_sta", 0x00000060, 9, 0, CSR_RO, 0x00000000 },
	{ "ln3_esc_cmd_sta", 0x00000060, 27, 16, CSR_RO, 0x00000000 },
	{ "LP_LN3_STA", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD lp_mon
	{ "lprx_mon", 0x00000064, 23, 0, CSR_RO, 0x00000000 },
	{ "LP_MON", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// WORD hs_sta
	{ "hsrx_sta0", 0x00000068, 6, 0, CSR_RO, 0x00000000 },
	{ "hsrx_sta1", 0x00000068, 14, 8, CSR_RO, 0x00000000 },
	{ "fifo_full_err", 0x00000068, 16, 16, CSR_RO, 0x00000000 },
	{ "HS_STA", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_sta
	{ "status_fifo_full_err", 0x0000006C, 0, 0, CSR_RO, 0x00000000 },
	{ "status_ln0_lprx_err", 0x0000006C, 1, 1, CSR_RO, 0x00000000 },
	{ "status_ln1_lprx_err", 0x0000006C, 2, 2, CSR_RO, 0x00000000 },
	{ "status_ln2_lprx_err", 0x0000006C, 3, 3, CSR_RO, 0x00000000 },
	{ "status_ln3_lprx_err", 0x0000006C, 4, 4, CSR_RO, 0x00000000 },
	{ "status_ln0_ulps_req", 0x0000006C, 7, 7, CSR_RO, 0x00000000 },
	{ "status_ln1_ulps_req", 0x0000006C, 8, 8, CSR_RO, 0x00000000 },
	{ "status_ln2_ulps_req", 0x0000006C, 9, 9, CSR_RO, 0x00000000 },
	{ "status_ln3_ulps_req", 0x0000006C, 10, 10, CSR_RO, 0x00000000 },
	{ "status_ln0_ulps_exit", 0x0000006C, 13, 13, CSR_RO, 0x00000000 },
	{ "status_ln1_ulps_exit", 0x0000006C, 14, 14, CSR_RO, 0x00000000 },
	{ "status_ln2_ulps_exit", 0x0000006C, 15, 15, CSR_RO, 0x00000000 },
	{ "status_ln3_ulps_exit", 0x0000006C, 16, 16, CSR_RO, 0x00000000 },
	{ "status_ln0_esc_cmd", 0x0000006C, 19, 19, CSR_RO, 0x00000000 },
	{ "status_ln1_esc_cmd", 0x0000006C, 20, 20, CSR_RO, 0x00000000 },
	{ "status_ln2_esc_cmd", 0x0000006C, 21, 21, CSR_RO, 0x00000000 },
	{ "status_ln3_esc_cmd", 0x0000006C, 22, 22, CSR_RO, 0x00000000 },
	{ "IRQ_STA", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_msk
	{ "irq_mask_fifo_full_err", 0x00000070, 0, 0, CSR_RW, 0x00000000 },
	{ "irq_mask_ln0_lprx_err", 0x00000070, 1, 1, CSR_RW, 0x00000000 },
	{ "irq_mask_ln1_lprx_err", 0x00000070, 2, 2, CSR_RW, 0x00000000 },
	{ "irq_mask_ln2_lprx_err", 0x00000070, 3, 3, CSR_RW, 0x00000000 },
	{ "irq_mask_ln3_lprx_err", 0x00000070, 4, 4, CSR_RW, 0x00000000 },
	{ "irq_mask_ln0_ulps_req", 0x00000070, 7, 7, CSR_RW, 0x00000000 },
	{ "irq_mask_ln1_ulps_req", 0x00000070, 8, 8, CSR_RW, 0x00000000 },
	{ "irq_mask_ln2_ulps_req", 0x00000070, 9, 9, CSR_RW, 0x00000000 },
	{ "irq_mask_ln3_ulps_req", 0x00000070, 10, 10, CSR_RW, 0x00000000 },
	{ "irq_mask_ln0_ulps_exit", 0x00000070, 13, 13, CSR_RW, 0x00000000 },
	{ "irq_mask_ln1_ulps_exit", 0x00000070, 14, 14, CSR_RW, 0x00000000 },
	{ "irq_mask_ln2_ulps_exit", 0x00000070, 15, 15, CSR_RW, 0x00000000 },
	{ "irq_mask_ln3_ulps_exit", 0x00000070, 16, 16, CSR_RW, 0x00000000 },
	{ "irq_mask_ln0_esc_cmd", 0x00000070, 19, 19, CSR_RW, 0x00000000 },
	{ "irq_mask_ln1_esc_cmd", 0x00000070, 20, 20, CSR_RW, 0x00000000 },
	{ "irq_mask_ln2_esc_cmd", 0x00000070, 21, 21, CSR_RW, 0x00000000 },
	{ "irq_mask_ln3_esc_cmd", 0x00000070, 22, 22, CSR_RW, 0x00000000 },
	{ "IRQ_MSK", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_ack
	{ "irq_clear_fifo_full_err", 0x00000074, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln0_lprx_err", 0x00000074, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln1_lprx_err", 0x00000074, 2, 2, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln2_lprx_err", 0x00000074, 3, 3, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln3_lprx_err", 0x00000074, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln0_ulps_req", 0x00000074, 7, 7, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln1_ulps_req", 0x00000074, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln2_ulps_req", 0x00000074, 9, 9, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln3_ulps_req", 0x00000074, 10, 10, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln0_ulps_exit", 0x00000074, 13, 13, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln1_ulps_exit", 0x00000074, 14, 14, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln2_ulps_exit", 0x00000074, 15, 15, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln3_ulps_exit", 0x00000074, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln0_esc_cmd", 0x00000074, 19, 19, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln1_esc_cmd", 0x00000074, 20, 20, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln2_esc_cmd", 0x00000074, 21, 21, CSR_W1P, 0x00000000 },
	{ "irq_clear_ln3_esc_cmd", 0x00000074, 22, 22, CSR_W1P, 0x00000000 },
	{ "IRQ_ACK", 0x00000074, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dbg_ctrl
	{ "debug_sel", 0x00000078, 3, 0, CSR_RW, 0x00000000 },
	{ "DBG_CTRL", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg_mon
	{ "debug_sta", 0x0000007C, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG_MON", 0x0000007C, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_RX_H_
