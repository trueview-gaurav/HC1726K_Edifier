/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SENIF_SYSCFG_H_
#define CSR_TABLE_SENIF_SYSCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_senif_syscfg[] = {
	// WORD cken0
	{ "cken_rx0_senif", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_ps_senif", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_dec0_senif", 0x00000000, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_dec1_senif", 0x00000000, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken1
	{ "cken_ps_out", 0x00000004, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_spi_out", 0x00000004, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_dec0_out", 0x00000004, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_dec1_out", 0x00000004, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN1", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken2
	{ "cken_slb0_out", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_slb1_out", 0x00000008, 8, 8, CSR_RW, 0x00000001 },
	{ "CKEN2", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken3
	{ "cken_rx0_p_clk_g", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_ps_p_clk_g", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_dec0_p_clk_g", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "cken_dec1_p_clk_g", 0x0000000C, 24, 24, CSR_RW, 0x00000001 },
	{ "CKEN3", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cken4
	{ "cken_spi_p_clk_g", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_slb0_p_clk_g", 0x00000010, 8, 8, CSR_RW, 0x00000001 },
	{ "cken_slb1_p_clk_g", 0x00000010, 16, 16, CSR_RW, 0x00000001 },
	{ "CKEN4", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD swrst0
	{ "sw_rst_rx0_senif", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_ps_senif", 0x00000014, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_dec0_senif", 0x00000014, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_dec1_senif", 0x00000014, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST0", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst1
	{ "sw_rst_ps_out", 0x00000018, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_spi_out", 0x00000018, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_dec0_out", 0x00000018, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_dec1_out", 0x00000018, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST1", 0x00000018, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst2
	{ "sw_rst_slb0_out", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_slb1_out", 0x0000001C, 8, 8, CSR_W1P, 0x00000000 },
	{ "SWRST2", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst3
	{ "sw_rst_rx0_p_clk_g", 0x00000020, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_ps_p_clk_g", 0x00000020, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_dec0_p_clk_g", 0x00000020, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_dec1_p_clk_g", 0x00000020, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST3", 0x00000020, 31, 0, CSR_W1P, 0x00000000 },
	// WORD swrst4
	{ "sw_rst_spi_p_clk_g", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_slb0_p_clk_g", 0x00000024, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_slb1_p_clk_g", 0x00000024, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_ctrl_p_clk_g", 0x00000024, 24, 24, CSR_W1P, 0x00000000 },
	{ "SWRST4", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lvlrst0
	{ "lv_rst_rx0_senif", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_ps_senif", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_dec0_senif", 0x00000028, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_dec1_senif", 0x00000028, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST0", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst1
	{ "lv_rst_ps_out", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_spi_out", 0x0000002C, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_dec0_out", 0x0000002C, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_dec1_out", 0x0000002C, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST1", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst2
	{ "lv_rst_slb0_out", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_slb1_out", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "LVLRST2", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst3
	{ "lv_rst_rx0_p_clk_g", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_ps_p_clk_g", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_dec0_p_clk_g", 0x00000034, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_dec1_p_clk_g", 0x00000034, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST3", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvlrst4
	{ "lv_rst_spi_p_clk_g", 0x00000038, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_slb0_p_clk_g", 0x00000038, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_slb1_p_clk_g", 0x00000038, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_ctrl_p_clk_g", 0x00000038, 24, 24, CSR_RW, 0x00000000 },
	{ "LVLRST4", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SENIF_SYSCFG_H_
