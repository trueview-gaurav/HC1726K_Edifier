/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CK_H_
#define CSR_TABLE_CK_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ck[] = {
	// WORD hw_cg_apb0
	{ "dis_cg_apb0", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cg_delay_m1_apb0", 0x00000000, 10, 8, CSR_RW, 0x00000002 },
	{ "HW_CG_APB0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_axi_cpu
	{ "cken_axi_rom", 0x00000004, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_axi_ram", 0x00000004, 8, 8, CSR_RW, 0x00000001 },
	{ "CG_AXI_CPU", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_axi_dram
	{ "cken_axi_dramc", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "CG_AXI_DRAM", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_dram
	{ "cken_apb_ddrphy", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_apb_dramc", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "CG_DRAM", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_sys
	{ "cken_efuse", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_eirq", 0x00000014, 1, 1, CSR_RW, 0x00000001 },
	{ "CG_SYS", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_timer
	{ "cken_timer0", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_timer1", 0x00000018, 1, 1, CSR_RW, 0x00000001 },
	{ "cken_timer2", 0x00000018, 2, 2, CSR_RW, 0x00000001 },
	{ "cken_timer3", 0x00000018, 3, 3, CSR_RW, 0x00000001 },
	{ "CG_TIMER", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_trng
	{ "cken_trng", 0x0000001C, 0, 0, CSR_RW, 0x00000001 },
	{ "CG_TRNG", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_i2cm
	{ "cken_i2cm0", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_i2cm1", 0x00000020, 1, 1, CSR_RW, 0x00000001 },
	{ "cken_i2cm2", 0x00000020, 2, 2, CSR_RW, 0x00000001 },
	{ "CG_I2CM", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_spi
	{ "cken_spi0", 0x00000024, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_spi1", 0x00000024, 1, 1, CSR_RW, 0x00000001 },
	{ "cken_spi_slave", 0x00000024, 2, 2, CSR_RW, 0x00000001 },
	{ "CG_SPI", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_pwm
	{ "cken_pwm0", 0x00000028, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_pwm1", 0x00000028, 1, 1, CSR_RW, 0x00000001 },
	{ "cken_pwm2", 0x00000028, 2, 2, CSR_RW, 0x00000001 },
	{ "cken_pwm3", 0x00000028, 3, 3, CSR_RW, 0x00000001 },
	{ "cken_pwm4", 0x00000028, 4, 4, CSR_RW, 0x00000001 },
	{ "cken_pwm5", 0x00000028, 5, 5, CSR_RW, 0x00000001 },
	{ "cken_pwm6", 0x00000028, 6, 6, CSR_RW, 0x00000001 },
	{ "CG_PWM", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_uart
	{ "cken_uart0", 0x0000002C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_uart1", 0x0000002C, 1, 1, CSR_RW, 0x00000001 },
	{ "cken_uart2", 0x0000002C, 2, 2, CSR_RW, 0x00000001 },
	{ "CG_UART", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_qspi
	{ "cken_qspi", 0x00000030, 0, 0, CSR_RW, 0x00000001 },
	{ "CG_QSPI", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_sdc
	{ "cken_sdc0", 0x00000034, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_sdc1", 0x00000034, 8, 8, CSR_RW, 0x00000001 },
	{ "CG_SDC", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_emac
	{ "cken_emac", 0x00000038, 0, 0, CSR_RW, 0x00000001 },
	{ "CG_EMAC", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_usb
	{ "cken_ahb_usb", 0x0000003C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_usb_utmi", 0x0000003C, 8, 8, CSR_RW, 0x00000001 },
	{ "CG_USB", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_sensor
	{ "cken_sensor", 0x00000040, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_senif", 0x00000040, 1, 1, CSR_RW, 0x00000001 },
	{ "CG_SENSOR", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_mipi_chop
	{ "cken_mipi_chop0", 0x00000044, 0, 0, CSR_RW, 0x00000001 },
	{ "CG_MIPI_CHOP", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_is
	{ "cken_is", 0x00000048, 0, 0, CSR_RW, 0x00000001 },
	{ "CG_IS", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_isp_vp
	{ "cken_isp", 0x0000004C, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_vp", 0x0000004C, 1, 1, CSR_RW, 0x00000001 },
	{ "CG_ISP_VP", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_enc
	{ "cken_enc", 0x00000050, 0, 0, CSR_RW, 0x00000001 },
	{ "CG_ENC", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_audio
	{ "cken_audio_in", 0x00000054, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_audio_adc", 0x00000054, 1, 1, CSR_RW, 0x00000001 },
	{ "cken_audio_dmic", 0x00000054, 2, 2, CSR_RW, 0x00000001 },
	{ "cken_audio_out", 0x00000054, 3, 3, CSR_RW, 0x00000001 },
	{ "cken_audio_dac", 0x00000054, 4, 4, CSR_RW, 0x00000001 },
	{ "cken_saadc", 0x00000054, 5, 5, CSR_RW, 0x00000001 },
	{ "CG_AUDIO", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_fm
	{ "cken_usb_fm", 0x00000058, 0, 0, CSR_RW, 0x00000001 },
	{ "CG_FM", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_ddr
	{ "dramc_hdr_div2_sel", 0x0000005C, 0, 0, CSR_RW, 0x00000001 },
	{ "ddr_phy_ref_div_num", 0x0000005C, 17, 8, CSR_RW, 0x00000000 },
	{ "DEF_DDR", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_axi_dram
	{ "axi_dramc_src_sel", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "DEF_AXI_DRAM", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_cpu_0
	{ "aclkenm_num_m1", 0x00000064, 1, 0, CSR_RW, 0x00000003 },
	{ "aclkenm_init", 0x00000064, 8, 8, CSR_RW, 0x00000001 },
	{ "pclkendbg_num_m1", 0x00000064, 17, 16, CSR_RW, 0x00000000 },
	{ "pclkendbg_init", 0x00000064, 24, 24, CSR_RW, 0x00000001 },
	{ "DEF_CPU_0", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_cpu_1
	{ "cpu_src_sel", 0x00000068, 3, 0, CSR_RW, 0x00000001 },
	{ "enm_mask_end_cnt", 0x00000068, 15, 8, CSR_RW, 0x00000010 },
	{ "cpu_div_num", 0x00000068, 25, 16, CSR_RW, 0x00000000 },
	{ "DEF_CPU_1", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_axi_sys
	{ "axi_sys_src_sel", 0x0000006C, 0, 0, CSR_RW, 0x00000000 },
	{ "axi_sys_div_num", 0x0000006C, 10, 8, CSR_RW, 0x00000000 },
	{ "DEF_AXI_SYS", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_apb_0
	{ "apb0_div_num", 0x00000070, 2, 0, CSR_RW, 0x00000000 },
	{ "apb1_div_num", 0x00000070, 10, 8, CSR_RW, 0x00000000 },
	{ "apb2_div_num", 0x00000070, 18, 16, CSR_RW, 0x00000000 },
	{ "apb3_div_num", 0x00000070, 26, 24, CSR_RW, 0x00000000 },
	{ "DEF_APB_0", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_ahb_0
	{ "ahb_usb_src_sel", 0x00000074, 0, 0, CSR_RW, 0x00000000 },
	{ "DEF_AHB_0", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_ahb_1
	{ "ahb_usb_div_num", 0x00000078, 2, 0, CSR_RW, 0x00000000 },
	{ "DEF_AHB_1", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_pwm_0
	{ "pwm0_src_sel", 0x0000007C, 1, 0, CSR_RW, 0x00000000 },
	{ "pwm1_src_sel", 0x0000007C, 9, 8, CSR_RW, 0x00000000 },
	{ "pwm2_src_sel", 0x0000007C, 17, 16, CSR_RW, 0x00000000 },
	{ "pwm3_src_sel", 0x0000007C, 25, 24, CSR_RW, 0x00000000 },
	{ "DEF_PWM_0", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_pwm_1
	{ "pwm4_src_sel", 0x00000080, 1, 0, CSR_RW, 0x00000000 },
	{ "pwm5_src_sel", 0x00000080, 9, 8, CSR_RW, 0x00000000 },
	{ "pwm6_src_sel", 0x00000080, 17, 16, CSR_RW, 0x00000000 },
	{ "DEF_PWM_1", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_pwm_2
	{ "pwm0_div_num", 0x00000084, 3, 0, CSR_RW, 0x00000000 },
	{ "pwm1_div_num", 0x00000084, 11, 8, CSR_RW, 0x00000000 },
	{ "pwm2_div_num", 0x00000084, 19, 16, CSR_RW, 0x00000000 },
	{ "pwm3_div_num", 0x00000084, 27, 24, CSR_RW, 0x00000000 },
	{ "DEF_PWM_2", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_pwm_3
	{ "pwm4_div_num", 0x00000088, 3, 0, CSR_RW, 0x00000000 },
	{ "pwm5_div_num", 0x00000088, 11, 8, CSR_RW, 0x00000000 },
	{ "pwm6_div_num", 0x00000088, 19, 16, CSR_RW, 0x00000000 },
	{ "DEF_PWM_3", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_uart_0
	{ "uart0_src_sel", 0x0000008C, 1, 0, CSR_RW, 0x00000000 },
	{ "uart0_div_num", 0x0000008C, 11, 8, CSR_RW, 0x00000000 },
	{ "uart1_src_sel", 0x0000008C, 17, 16, CSR_RW, 0x00000000 },
	{ "uart1_div_num", 0x0000008C, 27, 24, CSR_RW, 0x00000000 },
	{ "DEF_UART_0", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_uart_1
	{ "uart2_src_sel", 0x00000090, 1, 0, CSR_RW, 0x00000000 },
	{ "uart2_div_num", 0x00000090, 11, 8, CSR_RW, 0x00000000 },
	{ "DEF_UART_1", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_qspi
	{ "qspi_src_sel", 0x00000094, 2, 0, CSR_RW, 0x00000000 },
	{ "qspi_div_num", 0x00000094, 11, 8, CSR_RW, 0x00000000 },
	{ "DEF_QSPI", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_sdc0
	{ "sdc0_src_sel", 0x00000098, 0, 0, CSR_RW, 0x00000000 },
	{ "sdc0_div_num", 0x00000098, 11, 8, CSR_RW, 0x00000000 },
	{ "DEF_SDC0", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_sdc1
	{ "sdc1_src_sel", 0x0000009C, 0, 0, CSR_RW, 0x00000000 },
	{ "sdc1_div_num", 0x0000009C, 11, 8, CSR_RW, 0x00000000 },
	{ "DEF_SDC1", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_emac_0
	{ "emac_src_sel", 0x000000A0, 0, 0, CSR_RW, 0x00000001 },
	{ "emac_div_num", 0x000000A0, 16, 8, CSR_RW, 0x00000009 },
	{ "emac_phy_rx_div_num", 0x000000A0, 28, 24, CSR_RW, 0x00000001 },
	{ "DEF_EMAC_0", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_usb
	{ "usb_utmi_src_sel", 0x000000A4, 0, 0, CSR_RW, 0x00000000 },
	{ "DEF_USB", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_sensor
	{ "sensor_src_sel", 0x000000A8, 0, 0, CSR_RW, 0x00000000 },
	{ "sensor_div_num", 0x000000A8, 9, 8, CSR_RW, 0x00000000 },
	{ "senif_src_sel", 0x000000A8, 18, 16, CSR_RW, 0x00000000 },
	{ "senif_div_num", 0x000000A8, 25, 24, CSR_RW, 0x00000000 },
	{ "DEF_SENSOR", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_mipi_chop
	{ "mipi_chop0_src_sel", 0x000000AC, 1, 0, CSR_RW, 0x00000000 },
	{ "mipi_chop0_div_num", 0x000000AC, 10, 8, CSR_RW, 0x00000000 },
	{ "DEF_MIPI_CHOP", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_is
	{ "is_src_sel", 0x000000B0, 2, 0, CSR_RW, 0x00000000 },
	{ "is_div_num", 0x000000B0, 10, 8, CSR_RW, 0x00000000 },
	{ "DEF_IS", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_isp_vp
	{ "isp_src_sel", 0x000000B4, 2, 0, CSR_RW, 0x00000000 },
	{ "isp_div_num", 0x000000B4, 10, 8, CSR_RW, 0x00000000 },
	{ "vp_src_sel", 0x000000B4, 18, 16, CSR_RW, 0x00000000 },
	{ "vp_div_num", 0x000000B4, 26, 24, CSR_RW, 0x00000000 },
	{ "DEF_ISP_VP", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_venc
	{ "enc_src_sel", 0x000000B8, 2, 0, CSR_RW, 0x00000000 },
	{ "enc_div_num", 0x000000B8, 10, 8, CSR_RW, 0x00000000 },
	{ "DEF_VENC", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_audio_in
	{ "audio_in_src_sel", 0x000000BC, 2, 0, CSR_RW, 0x00000000 },
	{ "audio_in_div_num", 0x000000BC, 9, 8, CSR_RW, 0x00000000 },
	{ "audio_adc_div_num", 0x000000BC, 19, 16, CSR_RW, 0x00000000 },
	{ "DEF_AUDIO_IN", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_audio_out
	{ "audio_out_src_sel", 0x000000C0, 2, 0, CSR_RW, 0x00000000 },
	{ "audio_out_div_num", 0x000000C0, 9, 8, CSR_RW, 0x00000000 },
	{ "audio_dac_div_num", 0x000000C0, 19, 16, CSR_RW, 0x00000000 },
	{ "DEF_AUDIO_OUT", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_saadc
	{ "saadc_src_sel", 0x000000C4, 0, 0, CSR_RW, 0x00000000 },
	{ "saadc_div_num", 0x000000C4, 8, 8, CSR_RW, 0x00000000 },
	{ "DEF_SAADC", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_fm_0
	{ "cas_pll_fm_src_sel", 0x000000C8, 0, 0, CSR_RW, 0x00000001 },
	{ "ddr_pll_fm_src_sel", 0x000000C8, 8, 8, CSR_RW, 0x00000001 },
	{ "cpu_pll_fm_src_sel", 0x000000C8, 16, 16, CSR_RW, 0x00000001 },
	{ "venc_pll_fm_src_sel", 0x000000C8, 24, 24, CSR_RW, 0x00000001 },
	{ "DEF_FM_0", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_fm_1
	{ "epll_fm_src_sel", 0x000000CC, 0, 0, CSR_RW, 0x00000001 },
	{ "sensor_pll_fm_src_sel", 0x000000CC, 8, 8, CSR_RW, 0x00000001 },
	{ "audio_pll_fm_src_sel", 0x000000CC, 16, 16, CSR_RW, 0x00000001 },
	{ "DEF_FM_1", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_fm_2
	{ "usb_fm_src_sel", 0x000000D0, 0, 0, CSR_RW, 0x00000000 },
	{ "DEF_FM_2", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD cg_pvt
	{ "cken_pvt", 0x000000D4, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_pvt_sys", 0x000000D4, 1, 1, CSR_RW, 0x00000001 },
	{ "CG_PVT", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_pvt
	{ "pvt_src_sel", 0x000000D8, 0, 0, CSR_RW, 0x00000000 },
	{ "DEF_PVT", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_spi
	{ "spi0_src_sel", 0x000000DC, 2, 0, CSR_RW, 0x00000000 },
	{ "spi0_div_num", 0x000000DC, 11, 8, CSR_RW, 0x00000000 },
	{ "spi1_src_sel", 0x000000DC, 18, 16, CSR_RW, 0x00000000 },
	{ "spi1_div_num", 0x000000DC, 27, 24, CSR_RW, 0x00000000 },
	{ "DEF_SPI", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_spi_slave
	{ "spi_slave_src_sel", 0x000000E0, 2, 0, CSR_RW, 0x00000000 },
	{ "spi_slave_div_num", 0x000000E0, 11, 8, CSR_RW, 0x00000000 },
	{ "DEF_SPI_SLAVE", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_sys
	{ "sys_div_num", 0x000000E4, 9, 0, CSR_RW, 0x00000000 },
	{ "DEF_SYS", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD reserved_0
	{ "reserved0", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	{ "RESERVED_0", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD def_audio_dmic
	{ "audio_dmic_div_num", 0x000000EC, 9, 0, CSR_RW, 0x00000000 },
	{ "DEF_AUDIO_DMIC", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CK_H_
