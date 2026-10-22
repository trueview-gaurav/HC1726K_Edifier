/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PIOC_H_
#define CSR_TABLE_PIOC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pioc[] = {
	// WORD test_sel
	{ "tst_sel", 0x00000000, 2, 0, CSR_RW, 0x00000000 },
	{ "TEST_SEL", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pwm0_pcfg
	{ "pad_pwm0_pu", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_pwm0_pd", 0x00000004, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_pwm0_pcfg", 0x00000004, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_PWM0_PCFG", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pwm1_pcfg
	{ "pad_pwm1_pu", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_pwm1_pd", 0x00000008, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_pwm1_pcfg", 0x00000008, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_PWM1_PCFG", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pwm3_pcfg
	{ "pad_pwm3_pu", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_pwm3_pd", 0x0000000C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_pwm3_pcfg", 0x0000000C, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_PWM3_PCFG", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart1_txd_pcfg
	{ "pad_uart1_txd_pu", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_uart1_txd_pd", 0x00000010, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_uart1_txd_pcfg", 0x00000010, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_UART1_TXD_PCFG", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart1_rxd_pcfg
	{ "pad_uart1_rxd_pu", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_uart1_rxd_pd", 0x00000014, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_uart1_rxd_pcfg", 0x00000014, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_UART1_RXD_PCFG", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_cd_pcfg
	{ "pad_sd_cd_pu", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_sd_cd_pd", 0x00000018, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_sd_cd_pcfg", 0x00000018, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_SD_CD_PCFG", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d2_pcfg
	{ "pad_sd_d2_pu", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_sd_d2_pd", 0x0000001C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_sd_d2_pcfg", 0x0000001C, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_SD_D2_PCFG", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d3_pcfg
	{ "pad_sd_d3_pu", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_sd_d3_pd", 0x00000020, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_sd_d3_pcfg", 0x00000020, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_SD_D3_PCFG", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_cmd_pcfg
	{ "pad_sd_cmd_pu", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_sd_cmd_pd", 0x00000024, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_sd_cmd_pcfg", 0x00000024, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_SD_CMD_PCFG", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_ck_pcfg
	{ "pad_sd_ck_pu", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_sd_ck_pd", 0x00000028, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_sd_ck_pcfg", 0x00000028, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_SD_CK_PCFG", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d0_pcfg
	{ "pad_sd_d0_pu", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_sd_d0_pd", 0x0000002C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_sd_d0_pcfg", 0x0000002C, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_SD_D0_PCFG", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d1_pcfg
	{ "pad_sd_d1_pu", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_sd_d1_pd", 0x00000030, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_sd_d1_pcfg", 0x00000030, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_SD_D1_PCFG", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_ce_n_pcfg
	{ "pad_qspi_ce_n_pu", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_qspi_ce_n_pd", 0x00000034, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_qspi_ce_n_pcfg", 0x00000034, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_QSPI_CE_N_PCFG", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_d1_pcfg
	{ "pad_qspi_d1_pu", 0x00000038, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_qspi_d1_pd", 0x00000038, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_qspi_d1_pcfg", 0x00000038, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_QSPI_D1_PCFG", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_d2_pcfg
	{ "pad_qspi_d2_pu", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_qspi_d2_pd", 0x0000003C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_qspi_d2_pcfg", 0x0000003C, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_QSPI_D2_PCFG", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_d3_pcfg
	{ "pad_qspi_d3_pu", 0x00000040, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_qspi_d3_pd", 0x00000040, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_qspi_d3_pcfg", 0x00000040, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_QSPI_D3_PCFG", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_ck_pcfg
	{ "pad_qspi_ck_pu", 0x00000044, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_qspi_ck_pd", 0x00000044, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_qspi_ck_pcfg", 0x00000044, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_QSPI_CK_PCFG", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_d0_pcfg
	{ "pad_qspi_d0_pu", 0x00000048, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_qspi_d0_pd", 0x00000048, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_qspi_d0_pcfg", 0x00000048, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_QSPI_D0_PCFG", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_ephy_rst_pcfg
	{ "pad_ephy_rst_pu", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_ephy_rst_pd", 0x0000004C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_ephy_rst_pcfg", 0x0000004C, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EPHY_RST_PCFG", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_ck_pcfg
	{ "pad_emac_tx_ck_pu", 0x00000050, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_tx_ck_pd", 0x00000050, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_tx_ck_pcfg", 0x00000050, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_TX_CK_PCFG", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_ctl_pcfg
	{ "pad_emac_tx_ctl_pu", 0x00000054, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_tx_ctl_pd", 0x00000054, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_tx_ctl_pcfg", 0x00000054, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_TX_CTL_PCFG", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_d1_pcfg
	{ "pad_emac_tx_d1_pu", 0x00000058, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_tx_d1_pd", 0x00000058, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_tx_d1_pcfg", 0x00000058, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_TX_D1_PCFG", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_d0_pcfg
	{ "pad_emac_tx_d0_pu", 0x0000005C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_tx_d0_pd", 0x0000005C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_tx_d0_pcfg", 0x0000005C, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_TX_D0_PCFG", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_ck_pcfg
	{ "pad_emac_rx_ck_pu", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_rx_ck_pd", 0x00000060, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_rx_ck_pcfg", 0x00000060, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_RX_CK_PCFG", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_d0_pcfg
	{ "pad_emac_rx_d0_pu", 0x00000064, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_rx_d0_pd", 0x00000064, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_rx_d0_pcfg", 0x00000064, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_RX_D0_PCFG", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_d1_pcfg
	{ "pad_emac_rx_d1_pu", 0x00000068, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_rx_d1_pd", 0x00000068, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_rx_d1_pcfg", 0x00000068, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_RX_D1_PCFG", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_ctl_pcfg
	{ "pad_emac_rx_ctl_pu", 0x0000006C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_rx_ctl_pd", 0x0000006C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_rx_ctl_pcfg", 0x0000006C, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_RX_CTL_PCFG", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_mdc_pcfg
	{ "pad_emac_mdc_pu", 0x00000070, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_mdc_pd", 0x00000070, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_mdc_pcfg", 0x00000070, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_MDC_PCFG", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_mdio_pcfg
	{ "pad_emac_mdio_pu", 0x00000074, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_emac_mdio_pd", 0x00000074, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_emac_mdio_pcfg", 0x00000074, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_EMAC_MDIO_PCFG", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c2_scl_pcfg
	{ "pad_i2c2_scl_pu", 0x00000078, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_i2c2_scl_pd", 0x00000078, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_i2c2_scl_pcfg", 0x00000078, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_I2C2_SCL_PCFG", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c2_sda_pcfg
	{ "pad_i2c2_sda_pu", 0x0000007C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_i2c2_sda_pd", 0x0000007C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_i2c2_sda_pcfg", 0x0000007C, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_I2C2_SDA_PCFG", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_gpio31_pcfg
	{ "pad_gpio31_pu", 0x00000080, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_gpio31_pd", 0x00000080, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_gpio31_pcfg", 0x00000080, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_GPIO31_PCFG", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_dvp_hsync_pcfg
	{ "pad_dvp_hsync_pu", 0x00000084, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_dvp_hsync_pd", 0x00000084, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_dvp_hsync_pcfg", 0x00000084, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_DVP_HSYNC_PCFG", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_dvp_vsync_pcfg
	{ "pad_dvp_vsync_pu", 0x00000088, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_dvp_vsync_pd", 0x00000088, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_dvp_vsync_pcfg", 0x00000088, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_DVP_VSYNC_PCFG", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_dvp_d7_pcfg
	{ "pad_dvp_d7_pu", 0x0000008C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_dvp_d7_pd", 0x0000008C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_dvp_d7_pcfg", 0x0000008C, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_DVP_D7_PCFG", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_dvp_d6_pcfg
	{ "pad_dvp_d6_pu", 0x00000090, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_dvp_d6_pd", 0x00000090, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_dvp_d6_pcfg", 0x00000090, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_DVP_D6_PCFG", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_mipi_sel0_pcfg
	{ "pad_mipi_sel0_pu", 0x00000094, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_mipi_sel0_pd", 0x00000094, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_mipi_sel0_pcfg", 0x00000094, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_MIPI_SEL0_PCFG", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sensor_clk_pcfg
	{ "pad_sensor_clk_pu", 0x00000098, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_sensor_clk_pd", 0x00000098, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_sensor_clk_pcfg", 0x00000098, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_SENSOR_CLK_PCFG", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c0_scl_pcfg
	{ "pad_i2c0_scl_pu", 0x0000009C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_i2c0_scl_pd", 0x0000009C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_i2c0_scl_pcfg", 0x0000009C, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_I2C0_SCL_PCFG", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c0_sda_pcfg
	{ "pad_i2c0_sda_pu", 0x000000A0, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_i2c0_sda_pd", 0x000000A0, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_i2c0_sda_pcfg", 0x000000A0, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_I2C0_SDA_PCFG", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_adc_ch0_pcfg
	{ "pad_adc_ch0_pu", 0x000000A4, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_adc_ch0_pd", 0x000000A4, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_adc_ch0_pcfg", 0x000000A4, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_ADC_CH0_PCFG", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_gpio41_pcfg
	{ "pad_gpio41_pu", 0x000000A8, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_gpio41_pd", 0x000000A8, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_gpio41_pcfg", 0x000000A8, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_GPIO41_PCFG", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_gpio42_pcfg
	{ "pad_gpio42_pu", 0x000000AC, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_gpio42_pd", 0x000000AC, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_gpio42_pcfg", 0x000000AC, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_GPIO42_PCFG", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c1_scl_pcfg
	{ "pad_i2c1_scl_pu", 0x000000B0, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_i2c1_scl_pd", 0x000000B0, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_i2c1_scl_pcfg", 0x000000B0, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_I2C1_SCL_PCFG", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c1_sda_pcfg
	{ "pad_i2c1_sda_pu", 0x000000B4, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_i2c1_sda_pd", 0x000000B4, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_i2c1_sda_pcfg", 0x000000B4, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_I2C1_SDA_PCFG", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_txd_pcfg
	{ "pad_uart0_txd_pu", 0x000000B8, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_uart0_txd_pd", 0x000000B8, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_uart0_txd_pcfg", 0x000000B8, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_UART0_TXD_PCFG", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_rxd_pcfg
	{ "pad_uart0_rxd_pu", 0x000000BC, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_uart0_rxd_pd", 0x000000BC, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_uart0_rxd_pcfg", 0x000000BC, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_UART0_RXD_PCFG", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_rts_pcfg
	{ "pad_uart0_rts_pu", 0x000000C0, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_uart0_rts_pd", 0x000000C0, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_uart0_rts_pcfg", 0x000000C0, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_UART0_RTS_PCFG", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_cts_pcfg
	{ "pad_uart0_cts_pu", 0x000000C4, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_uart0_cts_pd", 0x000000C4, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_uart0_cts_pcfg", 0x000000C4, 19, 16, CSR_RW, 0x00000009 },
	{ "WORD_PAD_UART0_CTS_PCFG", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pwm0_iosel
	{ "pad_pwm0_iosel", 0x000000C8, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_PWM0_IOSEL", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pwm1_iosel
	{ "pad_pwm1_iosel", 0x000000CC, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_PWM1_IOSEL", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pwm3_iosel
	{ "pad_pwm3_iosel", 0x000000D0, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_PWM3_IOSEL", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart1_txd_iosel
	{ "pad_uart1_txd_iosel", 0x000000D4, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_UART1_TXD_IOSEL", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart1_rxd_iosel
	{ "pad_uart1_rxd_iosel", 0x000000D8, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_UART1_RXD_IOSEL", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_cd_iosel
	{ "pad_sd_cd_iosel", 0x000000DC, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_CD_IOSEL", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d2_iosel
	{ "pad_sd_d2_iosel", 0x000000E0, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_D2_IOSEL", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d3_iosel
	{ "pad_sd_d3_iosel", 0x000000E4, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_D3_IOSEL", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_cmd_iosel
	{ "pad_sd_cmd_iosel", 0x000000E8, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_CMD_IOSEL", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_ck_iosel
	{ "pad_sd_ck_iosel", 0x000000EC, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_CK_IOSEL", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d0_iosel
	{ "pad_sd_d0_iosel", 0x000000F0, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_D0_IOSEL", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sd_d1_iosel
	{ "pad_sd_d1_iosel", 0x000000F4, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SD_D1_IOSEL", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_ce_n_iosel
	{ "pad_qspi_ce_n_iosel", 0x000000F8, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_QSPI_CE_N_IOSEL", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_d1_iosel
	{ "pad_qspi_d1_iosel", 0x000000FC, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_QSPI_D1_IOSEL", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_d2_iosel
	{ "pad_qspi_d2_iosel", 0x00000100, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_QSPI_D2_IOSEL", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_d3_iosel
	{ "pad_qspi_d3_iosel", 0x00000104, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_QSPI_D3_IOSEL", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_ck_iosel
	{ "pad_qspi_ck_iosel", 0x00000108, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_QSPI_CK_IOSEL", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_qspi_d0_iosel
	{ "pad_qspi_d0_iosel", 0x0000010C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_QSPI_D0_IOSEL", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_ephy_rst_iosel
	{ "pad_ephy_rst_iosel", 0x00000110, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EPHY_RST_IOSEL", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_ck_iosel
	{ "pad_emac_tx_ck_iosel", 0x00000114, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_TX_CK_IOSEL", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_ctl_iosel
	{ "pad_emac_tx_ctl_iosel", 0x00000118, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_TX_CTL_IOSEL", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_d1_iosel
	{ "pad_emac_tx_d1_iosel", 0x0000011C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_TX_D1_IOSEL", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_tx_d0_iosel
	{ "pad_emac_tx_d0_iosel", 0x00000120, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_TX_D0_IOSEL", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_ck_iosel
	{ "pad_emac_rx_ck_iosel", 0x00000124, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_RX_CK_IOSEL", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_d0_iosel
	{ "pad_emac_rx_d0_iosel", 0x00000128, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_RX_D0_IOSEL", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_d1_iosel
	{ "pad_emac_rx_d1_iosel", 0x0000012C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_RX_D1_IOSEL", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_rx_ctl_iosel
	{ "pad_emac_rx_ctl_iosel", 0x00000130, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_RX_CTL_IOSEL", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_mdc_iosel
	{ "pad_emac_mdc_iosel", 0x00000134, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_MDC_IOSEL", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_emac_mdio_iosel
	{ "pad_emac_mdio_iosel", 0x00000138, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_EMAC_MDIO_IOSEL", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c2_scl_iosel
	{ "pad_i2c2_scl_iosel", 0x0000013C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_I2C2_SCL_IOSEL", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c2_sda_iosel
	{ "pad_i2c2_sda_iosel", 0x00000140, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_I2C2_SDA_IOSEL", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_gpio31_iosel
	{ "pad_gpio31_iosel", 0x00000144, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_GPIO31_IOSEL", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_dvp_hsync_iosel
	{ "pad_dvp_hsync_iosel", 0x00000148, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_DVP_HSYNC_IOSEL", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_dvp_vsync_iosel
	{ "pad_dvp_vsync_iosel", 0x0000014C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_DVP_VSYNC_IOSEL", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_dvp_d7_iosel
	{ "pad_dvp_d7_iosel", 0x00000150, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_DVP_D7_IOSEL", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_dvp_d6_iosel
	{ "pad_dvp_d6_iosel", 0x00000154, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_DVP_D6_IOSEL", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_mipi_sel0_iosel
	{ "pad_mipi_sel0_iosel", 0x00000158, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_MIPI_SEL0_IOSEL", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_sensor_clk_iosel
	{ "pad_sensor_clk_iosel", 0x0000015C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_SENSOR_CLK_IOSEL", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c0_scl_iosel
	{ "pad_i2c0_scl_iosel", 0x00000160, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_I2C0_SCL_IOSEL", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c0_sda_iosel
	{ "pad_i2c0_sda_iosel", 0x00000164, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_I2C0_SDA_IOSEL", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_adc_ch0_iosel
	{ "pad_adc_ch0_iosel", 0x00000168, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_ADC_CH0_IOSEL", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_gpio41_iosel
	{ "pad_gpio41_iosel", 0x0000016C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_GPIO41_IOSEL", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_gpio42_iosel
	{ "pad_gpio42_iosel", 0x00000170, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_GPIO42_IOSEL", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c1_scl_iosel
	{ "pad_i2c1_scl_iosel", 0x00000174, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_I2C1_SCL_IOSEL", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_i2c1_sda_iosel
	{ "pad_i2c1_sda_iosel", 0x00000178, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_I2C1_SDA_IOSEL", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_txd_iosel
	{ "pad_uart0_txd_iosel", 0x0000017C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_UART0_TXD_IOSEL", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_rxd_iosel
	{ "pad_uart0_rxd_iosel", 0x00000180, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_UART0_RXD_IOSEL", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_rts_iosel
	{ "pad_uart0_rts_iosel", 0x00000184, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_UART0_RTS_IOSEL", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_uart0_cts_iosel
	{ "pad_uart0_cts_iosel", 0x00000188, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_PAD_UART0_CTS_IOSEL", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PIOC_H_
