/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_FPGA_ROUTE_H_
#define CSR_TABLE_FPGA_ROUTE_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_fpga_route[] = {
	// WORD fpga_ver
	{ "fpga_version", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	{ "FPGA_VER", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_module
	{ "fpga_module_en", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	{ "FPGA_MODULE", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_pad_sd_cd_route_sel
	{ "pad_sd_cd_route_sel", 0x00000008, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_CD_ROUTE_SEL", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d0_route_sel
	{ "pad_sd_d0_route_sel", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_D0_ROUTE_SEL", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d1_route_sel
	{ "pad_sd_d1_route_sel", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_D1_ROUTE_SEL", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d2_route_sel
	{ "pad_sd_d2_route_sel", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_D2_ROUTE_SEL", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d3_route_sel
	{ "pad_sd_d3_route_sel", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_D3_ROUTE_SEL", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_ck_route_sel
	{ "pad_sd_ck_route_sel", 0x0000001C, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_SD_CK_ROUTE_SEL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_cmd_route_sel
	{ "pad_sd_cmd_route_sel", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_CMD_ROUTE_SEL", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c0_scl_route_sel
	{ "pad_i2c0_scl_route_sel", 0x00000024, 0, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_I2C0_SCL_ROUTE_SEL", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c1_scl_route_sel
	{ "pad_i2c1_scl_route_sel", 0x00000028, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_I2C1_SCL_ROUTE_SEL", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c0_sda_route_sel
	{ "pad_i2c0_sda_route_sel", 0x0000002C, 0, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_I2C0_SDA_ROUTE_SEL", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c1_sda_route_sel
	{ "pad_i2c1_sda_route_sel", 0x00000030, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_I2C1_SDA_ROUTE_SEL", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_d0_route_sel
	{ "pad_emac_rx_d0_route_sel", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_RX_D0_ROUTE_SEL", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_d1_route_sel
	{ "pad_emac_rx_d1_route_sel", 0x00000038, 0, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_EMAC_RX_D1_ROUTE_SEL", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_d1_route_sel
	{ "pad_emac_tx_d1_route_sel", 0x0000003C, 0, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_EMAC_TX_D1_ROUTE_SEL", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_d0_route_sel
	{ "pad_emac_tx_d0_route_sel", 0x00000040, 0, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_EMAC_TX_D0_ROUTE_SEL", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pwm3_route_sel
	{ "pad_pwm3_route_sel", 0x00000044, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_PWM3_ROUTE_SEL", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pwm1_route_sel
	{ "pad_pwm1_route_sel", 0x00000048, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_PWM1_ROUTE_SEL", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_rts_route_sel
	{ "pad_uart0_rts_route_sel", 0x0000004C, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_UART0_RTS_ROUTE_SEL", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_cts_route_sel
	{ "pad_uart0_cts_route_sel", 0x00000050, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_UART0_CTS_ROUTE_SEL", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_ephy_rst_route_sel
	{ "pad_ephy_rst_route_sel", 0x00000054, 1, 0, CSR_RW, 0x00000002 },
	{ "WORD_PAD_EPHY_RST_ROUTE_SEL", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_ck_route_sel
	{ "pad_qspi_ck_route_sel", 0x00000058, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_QSPI_CK_ROUTE_SEL", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_i2c_scl_route_sel
	{ "fpga_i2c_scl_route_sel", 0x0000005C, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_I2C_SCL_ROUTE_SEL", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_i2c_sda_route_sel
	{ "fpga_i2c_sda_route_sel", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_I2C_SDA_ROUTE_SEL", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_uart2_txd_route_sel
	{ "fpga_uart2_txd_route_sel", 0x00000064, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_UART2_TXD_ROUTE_SEL", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_uart2_rxd_route_sel
	{ "fpga_uart2_rxd_route_sel", 0x00000068, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_UART2_RXD_ROUTE_SEL", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_uart2_cts_route_sel
	{ "fpga_uart2_cts_route_sel", 0x0000006C, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_UART2_CTS_ROUTE_SEL", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_uart2_rts_route_sel
	{ "fpga_uart2_rts_route_sel", 0x00000070, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_UART2_RTS_ROUTE_SEL", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_FPGA_ROUTE_H_
