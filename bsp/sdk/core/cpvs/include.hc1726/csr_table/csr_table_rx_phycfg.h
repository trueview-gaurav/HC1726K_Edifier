/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_RX_PHYCFG_H_
#define CSR_TABLE_RX_PHYCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_rx_phycfg[] = {
	// WORD mipi_rx_refgen00
	{ "ln0_ib10u_miuns", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "ln0_ib10u_plus", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "ln0_vth_sel", 0x00000000, 17, 16, CSR_RW, 0x00000001 },
	{ "MIPI_RX_REFGEN00", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_hs00
	{ "ln0_delay_sel", 0x00000004, 5, 0, CSR_RW, 0x00000000 },
	{ "ln0_term_sel", 0x00000004, 19, 16, CSR_RW, 0x0000000A },
	{ "MIPI_RX_HS00", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_lp00
	{ "ln0_lpf_p", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "ln0_lpf_n", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "MIPI_RX_LP00", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_refgen01
	{ "ln1_ib10u_miuns", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "ln1_ib10u_plus", 0x0000000C, 8, 8, CSR_RW, 0x00000000 },
	{ "ln1_vth_sel", 0x0000000C, 17, 16, CSR_RW, 0x00000001 },
	{ "MIPI_RX_REFGEN01", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_hs01
	{ "ln1_delay_sel", 0x00000010, 5, 0, CSR_RW, 0x00000000 },
	{ "ln1_term_sel", 0x00000010, 19, 16, CSR_RW, 0x0000000A },
	{ "MIPI_RX_HS01", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_lp01
	{ "ln1_lpf_p", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "ln1_lpf_n", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "MIPI_RX_LP01", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_refgen02
	{ "ln2_ib10u_miuns", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "ln2_ib10u_plus", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "ln2_vth_sel", 0x00000018, 17, 16, CSR_RW, 0x00000001 },
	{ "MIPI_RX_REFGEN02", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_hs02
	{ "ln2_delay_sel", 0x0000001C, 5, 0, CSR_RW, 0x00000000 },
	{ "ln2_term_sel", 0x0000001C, 19, 16, CSR_RW, 0x0000000A },
	{ "MIPI_RX_HS02", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_lp02
	{ "ln2_lpf_p", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "ln2_lpf_n", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "MIPI_RX_LP02", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_refgen03
	{ "ln3_ib10u_miuns", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "ln3_ib10u_plus", 0x00000024, 8, 8, CSR_RW, 0x00000000 },
	{ "ln3_vth_sel", 0x00000024, 17, 16, CSR_RW, 0x00000001 },
	{ "MIPI_RX_REFGEN03", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_hs03
	{ "ln3_delay_sel", 0x00000028, 5, 0, CSR_RW, 0x00000000 },
	{ "ln3_term_sel", 0x00000028, 19, 16, CSR_RW, 0x0000000A },
	{ "MIPI_RX_HS03", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_lp03
	{ "ln3_lpf_p", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "ln3_lpf_n", 0x0000002C, 8, 8, CSR_RW, 0x00000000 },
	{ "MIPI_RX_LP03", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_ck
	{ "ln0_ck_en", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "ln1_ck_en", 0x00000030, 4, 4, CSR_RW, 0x00000001 },
	{ "ln2_ck_en", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "ln3_ck_en", 0x00000030, 12, 12, CSR_RW, 0x00000000 },
	{ "ch0_clk_xor", 0x00000030, 24, 24, CSR_RW, 0x00000001 },
	{ "ch1_clk_xor", 0x00000030, 28, 28, CSR_RW, 0x00000001 },
	{ "MIPI_RX_CK", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_func00
	{ "ln0_lvds_en", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "ln0_chop_en", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "ln0_lb_en", 0x00000034, 16, 16, CSR_RW, 0x00000000 },
	{ "MIPI_RX_FUNC00", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_sel00
	{ "ln0_ch_sel", 0x00000038, 0, 0, CSR_RW, 0x00000000 },
	{ "ln0_clk_sel", 0x00000038, 8, 8, CSR_RW, 0x00000001 },
	{ "ln0_ldov_sel", 0x00000038, 17, 16, CSR_RW, 0x00000001 },
	{ "MIPI_RX_SEL00", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_func01
	{ "ln1_lvds_en", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "ln1_chop_en", 0x0000003C, 8, 8, CSR_RW, 0x00000000 },
	{ "ln1_lb_en", 0x0000003C, 16, 16, CSR_RW, 0x00000000 },
	{ "MIPI_RX_FUNC01", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_sel01
	{ "ln1_ch_sel", 0x00000040, 0, 0, CSR_RW, 0x00000000 },
	{ "ln1_clk_sel", 0x00000040, 8, 8, CSR_RW, 0x00000000 },
	{ "ln1_ldov_sel", 0x00000040, 17, 16, CSR_RW, 0x00000001 },
	{ "MIPI_RX_SEL01", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_func02
	{ "ln2_lvds_en", 0x00000044, 0, 0, CSR_RW, 0x00000000 },
	{ "ln2_chop_en", 0x00000044, 8, 8, CSR_RW, 0x00000000 },
	{ "ln2_lb_en", 0x00000044, 16, 16, CSR_RW, 0x00000000 },
	{ "MIPI_RX_FUNC02", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_sel02
	{ "ln2_ch_sel", 0x00000048, 0, 0, CSR_RW, 0x00000000 },
	{ "ln2_clk_sel", 0x00000048, 8, 8, CSR_RW, 0x00000000 },
	{ "ln2_ldov_sel", 0x00000048, 17, 16, CSR_RW, 0x00000001 },
	{ "MIPI_RX_SEL02", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_func03
	{ "ln3_lvds_en", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "ln3_chop_en", 0x0000004C, 8, 8, CSR_RW, 0x00000000 },
	{ "ln3_lb_en", 0x0000004C, 16, 16, CSR_RW, 0x00000000 },
	{ "MIPI_RX_FUNC03", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi_rx_sel03
	{ "ln3_ch_sel", 0x00000050, 0, 0, CSR_RW, 0x00000000 },
	{ "ln3_clk_sel", 0x00000050, 8, 8, CSR_RW, 0x00000000 },
	{ "ln3_ldov_sel", 0x00000050, 17, 16, CSR_RW, 0x00000001 },
	{ "MIPI_RX_SEL03", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_RX_PHYCFG_H_
