/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_RST_H_
#define CSR_TABLE_RST_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_rst[] = {
	// WORD w1p_sys
	{ "sw_rst_efuse", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_eirq", 0x00000000, 1, 1, CSR_W1P, 0x00000000 },
	{ "W1P_SYS", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_timer
	{ "sw_rst_timer0", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_timer1", 0x00000004, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_timer2", 0x00000004, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_timer3", 0x00000004, 3, 3, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_timer", 0x00000004, 4, 4, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_wdt", 0x00000004, 5, 5, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_wdt_stable", 0x00000004, 6, 6, CSR_W1P, 0x00000000 },
	{ "W1P_TIMER", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_trng
	{ "sw_rst_trng", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_trng", 0x00000008, 1, 1, CSR_W1P, 0x00000000 },
	{ "W1P_TRNG", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_cpu
	{ "sw_rst_cpu", 0x00000010, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_corepor0", 0x00000010, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_corepor1", 0x00000010, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_corepor2", 0x00000010, 3, 3, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_corepor3", 0x00000010, 4, 4, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_core0", 0x00000010, 5, 5, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_core1", 0x00000010, 6, 6, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_core2", 0x00000010, 7, 7, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_core3", 0x00000010, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_dbg0", 0x00000010, 9, 9, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_dbg1", 0x00000010, 10, 10, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_dbg2", 0x00000010, 11, 11, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_dbg3", 0x00000010, 12, 12, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_l2", 0x00000010, 13, 13, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_socdbg", 0x00000010, 14, 14, CSR_W1P, 0x00000000 },
	{ "sw_rst_cpu_sys_cntr", 0x00000010, 15, 15, CSR_W1P, 0x00000000 },
	{ "W1P_CPU", 0x00000010, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_axi_cpu
	{ "sw_rst_axi_cpu", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_axi_sys", 0x00000014, 8, 8, CSR_W1P, 0x00000000 },
	{ "W1P_AXI_CPU", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_apb
	{ "sw_rst_apb0", 0x00000018, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb1", 0x00000018, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb2", 0x00000018, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb3", 0x00000018, 24, 24, CSR_W1P, 0x00000000 },
	{ "W1P_APB", 0x00000018, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_dram
	{ "sw_rst_ddrphy_dll", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_ddrphy", 0x0000001C, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_ddrphy_hdr", 0x0000001C, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_dramc_hdr", 0x0000001C, 3, 3, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_ddrphy", 0x0000001C, 4, 4, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_dramc", 0x0000001C, 5, 5, CSR_W1P, 0x00000000 },
	{ "W1P_DRAM", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_axi_dramc
	{ "sw_rst_axi_dramc", 0x00000020, 0, 0, CSR_W1P, 0x00000000 },
	{ "W1P_AXI_DRAMC", 0x00000020, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_i2cs
	{ "sw_rst_apb_i2cs", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "W1P_I2CS", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_i2cm
	{ "sw_rst_i2cm0", 0x00000028, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_i2cm0", 0x00000028, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_i2cm1", 0x00000028, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_i2cm1", 0x00000028, 3, 3, CSR_W1P, 0x00000000 },
	{ "sw_rst_i2cm2", 0x00000028, 4, 4, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_i2cm2", 0x00000028, 5, 5, CSR_W1P, 0x00000000 },
	{ "W1P_I2CM", 0x00000028, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_spi
	{ "sw_rst_spi0", 0x0000002C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_spi0", 0x0000002C, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_spi1", 0x0000002C, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_spi1", 0x0000002C, 3, 3, CSR_W1P, 0x00000000 },
	{ "sw_rst_spi_slave", 0x0000002C, 4, 4, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_spi_slave", 0x0000002C, 5, 5, CSR_W1P, 0x00000000 },
	{ "W1P_SPI", 0x0000002C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_uart
	{ "sw_rst_uart0", 0x00000030, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_uart0", 0x00000030, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_uart1", 0x00000030, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_uart1", 0x00000030, 3, 3, CSR_W1P, 0x00000000 },
	{ "sw_rst_uart2", 0x00000030, 4, 4, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_uart2", 0x00000030, 5, 5, CSR_W1P, 0x00000000 },
	{ "W1P_UART", 0x00000030, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_pwm
	{ "sw_rst_pwm0", 0x00000034, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_pwm0", 0x00000034, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_pwm1", 0x00000034, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_pwm2", 0x00000034, 3, 3, CSR_W1P, 0x00000000 },
	{ "sw_rst_pwm3", 0x00000034, 4, 4, CSR_W1P, 0x00000000 },
	{ "sw_rst_pwm4", 0x00000034, 5, 5, CSR_W1P, 0x00000000 },
	{ "sw_rst_pwm5", 0x00000034, 6, 6, CSR_W1P, 0x00000000 },
	{ "sw_rst_pwm6", 0x00000034, 7, 7, CSR_W1P, 0x00000000 },
	{ "W1P_PWM", 0x00000034, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_emac
	{ "sw_rst_apb_emac", 0x00000038, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_emac_rx", 0x00000038, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_emac_axi_dramc", 0x00000038, 2, 2, CSR_W1P, 0x00000000 },
	{ "W1P_EMAC", 0x00000038, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_qspi
	{ "sw_rst_qspi", 0x0000003C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_qspi", 0x0000003C, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_qspi_axi_dramc", 0x0000003C, 2, 2, CSR_W1P, 0x00000000 },
	{ "W1P_QSPI", 0x0000003C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_pvt
	{ "sw_rst_pvt", 0x00000040, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_pvt", 0x00000040, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_pvt_sys", 0x00000040, 2, 2, CSR_W1P, 0x00000000 },
	{ "W1P_PVT", 0x00000040, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_sdc
	{ "sw_rst_sdc0", 0x00000044, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_sdc0", 0x00000044, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_sdc1", 0x00000044, 8, 8, CSR_W1P, 0x00000000 },
	{ "sw_rst_apb_sdc1", 0x00000044, 9, 9, CSR_W1P, 0x00000000 },
	{ "W1P_SDC", 0x00000044, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_usb
	{ "sw_rst_apb_usb", 0x00000048, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_ahb_usb", 0x00000048, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_usb_utmi", 0x00000048, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_usb_phy", 0x00000048, 3, 3, CSR_W1P, 0x00000000 },
	{ "W1P_USB", 0x00000048, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_sensor
	{ "sw_rst_sensor", 0x0000004C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_mipi_chop0", 0x0000004C, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_senif", 0x0000004C, 2, 2, CSR_W1P, 0x00000000 },
	{ "W1P_SENSOR", 0x0000004C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_is
	{ "sw_rst_is", 0x00000050, 0, 0, CSR_W1P, 0x00000000 },
	{ "W1P_IS", 0x00000050, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_ispvp
	{ "sw_rst_isp", 0x00000054, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_vp", 0x00000054, 1, 1, CSR_W1P, 0x00000000 },
	{ "W1P_ISPVP", 0x00000054, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_enc
	{ "sw_rst_enc", 0x00000058, 0, 0, CSR_W1P, 0x00000000 },
	{ "W1P_ENC", 0x00000058, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_audio
	{ "sw_rst_audio_in", 0x0000005C, 0, 0, CSR_W1P, 0x00000000 },
	{ "sw_rst_audio_adc", 0x0000005C, 1, 1, CSR_W1P, 0x00000000 },
	{ "sw_rst_audio_dmic", 0x0000005C, 2, 2, CSR_W1P, 0x00000000 },
	{ "sw_rst_saadc", 0x0000005C, 3, 3, CSR_W1P, 0x00000000 },
	{ "sw_rst_audio_out", 0x0000005C, 16, 16, CSR_W1P, 0x00000000 },
	{ "sw_rst_audio_dac", 0x0000005C, 17, 17, CSR_W1P, 0x00000000 },
	{ "W1P_AUDIO", 0x0000005C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD w1p_x2p_ip
	{ "sw_rst_x2p_ip0", 0x00000060, 0, 0, CSR_W1P, 0x00000000 },
	{ "W1P_X2P_IP", 0x00000060, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lv_sys
	{ "lv_rst_efuse", 0x00000064, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_eirq", 0x00000064, 1, 1, CSR_RW, 0x00000000 },
	{ "LV_SYS", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_timer
	{ "lv_rst_timer0", 0x00000068, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_timer1", 0x00000068, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_timer2", 0x00000068, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_timer3", 0x00000068, 3, 3, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_timer", 0x00000068, 4, 4, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_wdt", 0x00000068, 5, 5, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_wdt_stable", 0x00000068, 6, 6, CSR_RW, 0x00000000 },
	{ "LV_TIMER", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_trng
	{ "lv_rst_trng", 0x0000006C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_trng", 0x0000006C, 1, 1, CSR_RW, 0x00000000 },
	{ "LV_TRNG", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_cpu
	{ "lv_rst_cpu", 0x00000074, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_corepor0", 0x00000074, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_corepor1", 0x00000074, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_corepor2", 0x00000074, 3, 3, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_corepor3", 0x00000074, 4, 4, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_core0", 0x00000074, 5, 5, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_core1", 0x00000074, 6, 6, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_core2", 0x00000074, 7, 7, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_core3", 0x00000074, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_dbg0", 0x00000074, 9, 9, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_dbg1", 0x00000074, 10, 10, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_dbg2", 0x00000074, 11, 11, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_dbg3", 0x00000074, 12, 12, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_l2", 0x00000074, 13, 13, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_socdbg", 0x00000074, 14, 14, CSR_RW, 0x00000000 },
	{ "lv_rst_cpu_sys_cntr", 0x00000074, 15, 15, CSR_RW, 0x00000000 },
	{ "LV_CPU", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_axi_cpu
	{ "lv_rst_axi_cpu", 0x00000078, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_axi_sys", 0x00000078, 8, 8, CSR_RW, 0x00000000 },
	{ "LV_AXI_CPU", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_apb
	{ "lv_rst_apb0", 0x0000007C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb1", 0x0000007C, 8, 8, CSR_RW, 0x00000000 },
	{ "lv_rst_apb2", 0x0000007C, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_apb3", 0x0000007C, 24, 24, CSR_RW, 0x00000000 },
	{ "LV_APB", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_dram
	{ "lv_rst_ddrphy_dll", 0x00000080, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_ddrphy", 0x00000080, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_ddrphy_hdr", 0x00000080, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_dramc_hdr", 0x00000080, 3, 3, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_ddrphy", 0x00000080, 4, 4, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_dramc", 0x00000080, 5, 5, CSR_RW, 0x00000000 },
	{ "LV_DRAM", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_axi_dramc
	{ "lv_rst_axi_dramc", 0x00000084, 0, 0, CSR_RW, 0x00000000 },
	{ "LV_AXI_DRAMC", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_i2cs
	{ "lv_rst_apb_i2cs", 0x00000088, 0, 0, CSR_RW, 0x00000000 },
	{ "LV_I2CS", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_i2cm
	{ "lv_rst_i2cm0", 0x0000008C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_i2cm0", 0x0000008C, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_i2cm1", 0x0000008C, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_i2cm1", 0x0000008C, 3, 3, CSR_RW, 0x00000000 },
	{ "lv_rst_i2cm2", 0x0000008C, 4, 4, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_i2cm2", 0x0000008C, 5, 5, CSR_RW, 0x00000000 },
	{ "LV_I2CM", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_spi
	{ "lv_rst_spi0", 0x00000090, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_spi0", 0x00000090, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_spi1", 0x00000090, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_spi1", 0x00000090, 3, 3, CSR_RW, 0x00000000 },
	{ "lv_rst_spi_slave", 0x00000090, 4, 4, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_spi_slave", 0x00000090, 5, 5, CSR_RW, 0x00000000 },
	{ "LV_SPI", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_uart
	{ "lv_rst_uart0", 0x00000094, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_uart0", 0x00000094, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_uart1", 0x00000094, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_uart1", 0x00000094, 3, 3, CSR_RW, 0x00000000 },
	{ "lv_rst_uart2", 0x00000094, 4, 4, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_uart2", 0x00000094, 5, 5, CSR_RW, 0x00000000 },
	{ "LV_UART", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_pwm
	{ "lv_rst_pwm0", 0x00000098, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_pwm0", 0x00000098, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_pwm1", 0x00000098, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_pwm2", 0x00000098, 3, 3, CSR_RW, 0x00000000 },
	{ "lv_rst_pwm3", 0x00000098, 4, 4, CSR_RW, 0x00000000 },
	{ "lv_rst_pwm4", 0x00000098, 5, 5, CSR_RW, 0x00000000 },
	{ "lv_rst_pwm5", 0x00000098, 6, 6, CSR_RW, 0x00000000 },
	{ "lv_rst_pwm6", 0x00000098, 7, 7, CSR_RW, 0x00000000 },
	{ "LV_PWM", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_emac
	{ "lv_rst_apb_emac", 0x0000009C, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_emac_rx", 0x0000009C, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_emac_axi_dramc", 0x0000009C, 2, 2, CSR_RW, 0x00000000 },
	{ "LV_EMAC", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_qspi
	{ "lv_rst_qspi", 0x000000A0, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_qspi", 0x000000A0, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_qspi_axi_dramc", 0x000000A0, 2, 2, CSR_RW, 0x00000000 },
	{ "LV_QSPI", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_pvt
	{ "lv_rst_pvt", 0x000000A4, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_pvt", 0x000000A4, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_pvt_sys", 0x000000A4, 2, 2, CSR_RW, 0x00000000 },
	{ "LV_PVT", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_sdc
	{ "lv_rst_sdc0", 0x000000A8, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_sdc0", 0x000000A8, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_sdc1", 0x000000A8, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_apb_sdc1", 0x000000A8, 17, 17, CSR_RW, 0x00000000 },
	{ "LV_SDC", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_usb
	{ "lv_rst_apb_usb", 0x000000AC, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_ahb_usb", 0x000000AC, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_usb_utmi", 0x000000AC, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_usb_phy", 0x000000AC, 3, 3, CSR_RW, 0x00000000 },
	{ "LV_USB", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_sensor
	{ "lv_rst_sensor", 0x000000B0, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_mipi_chop0", 0x000000B0, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_senif", 0x000000B0, 2, 2, CSR_RW, 0x00000000 },
	{ "LV_SENSOR", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_is
	{ "lv_rst_is", 0x000000B4, 0, 0, CSR_RW, 0x00000000 },
	{ "LV_IS", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_ispvp
	{ "lv_rst_isp", 0x000000B8, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_vp", 0x000000B8, 1, 1, CSR_RW, 0x00000000 },
	{ "LV_ISPVP", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_enc
	{ "lv_rst_enc", 0x000000BC, 0, 0, CSR_RW, 0x00000000 },
	{ "LV_ENC", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_audio
	{ "lv_rst_audio_in", 0x000000C0, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_audio_adc", 0x000000C0, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_audio_dmic", 0x000000C0, 2, 2, CSR_RW, 0x00000000 },
	{ "lv_rst_saadc", 0x000000C0, 3, 3, CSR_RW, 0x00000000 },
	{ "lv_rst_audio_out", 0x000000C0, 16, 16, CSR_RW, 0x00000000 },
	{ "lv_rst_audio_dac", 0x000000C0, 17, 17, CSR_RW, 0x00000000 },
	{ "LV_AUDIO", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD lv_x2p_ip
	{ "lv_rst_x2p_ip1", 0x000000C4, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_x2p_ip2", 0x000000C4, 1, 1, CSR_RW, 0x00000000 },
	{ "lv_rst_x2p_ip3", 0x000000C4, 2, 2, CSR_RW, 0x00000000 },
	{ "LV_X2P_IP", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD reserved
	{ "reserved_0", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	{ "RESERVED", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_RST_H_
