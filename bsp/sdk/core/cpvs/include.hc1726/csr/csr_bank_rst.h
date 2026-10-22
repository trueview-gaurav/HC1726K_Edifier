/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_RST_H_
#define CSR_BANK_RST_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from rst  ***/
typedef struct csr_bank_rst {
	/* W1P_SYS 10'h000 */
	union {
		uint32_t w1p_sys; // word name
		struct {
			uint32_t sw_rst_efuse : 1;
			uint32_t sw_rst_eirq : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_TIMER 10'h004 */
	union {
		uint32_t w1p_timer; // word name
		struct {
			uint32_t sw_rst_timer0 : 1;
			uint32_t sw_rst_timer1 : 1;
			uint32_t sw_rst_timer2 : 1;
			uint32_t sw_rst_timer3 : 1;
			uint32_t sw_rst_apb_timer : 1;
			uint32_t sw_rst_apb_wdt : 1;
			uint32_t sw_rst_apb_wdt_stable : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_TRNG 10'h008 */
	union {
		uint32_t w1p_trng; // word name
		struct {
			uint32_t sw_rst_trng : 1;
			uint32_t sw_rst_apb_trng : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_AON 10'h00C [Unused] */
	uint32_t empty_word_w1p_aon;
	/* W1P_CPU 10'h010 */
	union {
		uint32_t w1p_cpu; // word name
		struct {
			uint32_t sw_rst_cpu : 1;
			uint32_t sw_rst_cpu_corepor0 : 1;
			uint32_t sw_rst_cpu_corepor1 : 1;
			uint32_t sw_rst_cpu_corepor2 : 1;
			uint32_t sw_rst_cpu_corepor3 : 1;
			uint32_t sw_rst_cpu_core0 : 1;
			uint32_t sw_rst_cpu_core1 : 1;
			uint32_t sw_rst_cpu_core2 : 1;
			uint32_t sw_rst_cpu_core3 : 1;
			uint32_t sw_rst_cpu_dbg0 : 1;
			uint32_t sw_rst_cpu_dbg1 : 1;
			uint32_t sw_rst_cpu_dbg2 : 1;
			uint32_t sw_rst_cpu_dbg3 : 1;
			uint32_t sw_rst_cpu_l2 : 1;
			uint32_t sw_rst_cpu_socdbg : 1;
			uint32_t sw_rst_cpu_sys_cntr : 1;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_AXI_CPU 10'h014 */
	union {
		uint32_t w1p_axi_cpu; // word name
		struct {
			uint32_t sw_rst_axi_cpu : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_axi_sys : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_APB 10'h018 */
	union {
		uint32_t w1p_apb; // word name
		struct {
			uint32_t sw_rst_apb0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_apb1 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_apb2 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_apb3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* W1P_DRAM 10'h01C */
	union {
		uint32_t w1p_dram; // word name
		struct {
			uint32_t sw_rst_ddrphy_dll : 1;
			uint32_t sw_rst_ddrphy : 1;
			uint32_t sw_rst_ddrphy_hdr : 1;
			uint32_t sw_rst_dramc_hdr : 1;
			uint32_t sw_rst_apb_ddrphy : 1;
			uint32_t sw_rst_apb_dramc : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_AXI_DRAMC 10'h020 */
	union {
		uint32_t w1p_axi_dramc; // word name
		struct {
			uint32_t sw_rst_axi_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_I2CS 10'h024 */
	union {
		uint32_t w1p_i2cs; // word name
		struct {
			uint32_t sw_rst_apb_i2cs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_I2CM 10'h028 */
	union {
		uint32_t w1p_i2cm; // word name
		struct {
			uint32_t sw_rst_i2cm0 : 1;
			uint32_t sw_rst_apb_i2cm0 : 1;
			uint32_t sw_rst_i2cm1 : 1;
			uint32_t sw_rst_apb_i2cm1 : 1;
			uint32_t sw_rst_i2cm2 : 1;
			uint32_t sw_rst_apb_i2cm2 : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_SPI 10'h02C */
	union {
		uint32_t w1p_spi; // word name
		struct {
			uint32_t sw_rst_spi0 : 1;
			uint32_t sw_rst_apb_spi0 : 1;
			uint32_t sw_rst_spi1 : 1;
			uint32_t sw_rst_apb_spi1 : 1;
			uint32_t sw_rst_spi_slave : 1;
			uint32_t sw_rst_apb_spi_slave : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_UART 10'h030 */
	union {
		uint32_t w1p_uart; // word name
		struct {
			uint32_t sw_rst_uart0 : 1;
			uint32_t sw_rst_apb_uart0 : 1;
			uint32_t sw_rst_uart1 : 1;
			uint32_t sw_rst_apb_uart1 : 1;
			uint32_t sw_rst_uart2 : 1;
			uint32_t sw_rst_apb_uart2 : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_PWM 10'h034 */
	union {
		uint32_t w1p_pwm; // word name
		struct {
			uint32_t sw_rst_pwm0 : 1;
			uint32_t sw_rst_apb_pwm0 : 1;
			uint32_t sw_rst_pwm1 : 1;
			uint32_t sw_rst_pwm2 : 1;
			uint32_t sw_rst_pwm3 : 1;
			uint32_t sw_rst_pwm4 : 1;
			uint32_t sw_rst_pwm5 : 1;
			uint32_t sw_rst_pwm6 : 1;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_EMAC 10'h038 */
	union {
		uint32_t w1p_emac; // word name
		struct {
			uint32_t sw_rst_apb_emac : 1;
			uint32_t sw_rst_emac_rx : 1;
			uint32_t sw_rst_emac_axi_dramc : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_QSPI 10'h03C */
	union {
		uint32_t w1p_qspi; // word name
		struct {
			uint32_t sw_rst_qspi : 1;
			uint32_t sw_rst_apb_qspi : 1;
			uint32_t sw_rst_qspi_axi_dramc : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_PVT 10'h040 */
	union {
		uint32_t w1p_pvt; // word name
		struct {
			uint32_t sw_rst_pvt : 1;
			uint32_t sw_rst_apb_pvt : 1;
			uint32_t sw_rst_pvt_sys : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_SDC 10'h044 */
	union {
		uint32_t w1p_sdc; // word name
		struct {
			uint32_t sw_rst_sdc0 : 1;
			uint32_t sw_rst_apb_sdc0 : 1;
			uint32_t : 6; // padding bits
			uint32_t sw_rst_sdc1 : 1;
			uint32_t sw_rst_apb_sdc1 : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_USB 10'h048 */
	union {
		uint32_t w1p_usb; // word name
		struct {
			uint32_t sw_rst_apb_usb : 1;
			uint32_t sw_rst_ahb_usb : 1;
			uint32_t sw_rst_usb_utmi : 1;
			uint32_t sw_rst_usb_phy : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_SENSOR 10'h04C */
	union {
		uint32_t w1p_sensor; // word name
		struct {
			uint32_t sw_rst_sensor : 1;
			uint32_t sw_rst_mipi_chop0 : 1;
			uint32_t sw_rst_senif : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_IS 10'h050 */
	union {
		uint32_t w1p_is; // word name
		struct {
			uint32_t sw_rst_is : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_ISPVP 10'h054 */
	union {
		uint32_t w1p_ispvp; // word name
		struct {
			uint32_t sw_rst_isp : 1;
			uint32_t sw_rst_vp : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_ENC 10'h058 */
	union {
		uint32_t w1p_enc; // word name
		struct {
			uint32_t sw_rst_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_AUDIO 10'h05C */
	union {
		uint32_t w1p_audio; // word name
		struct {
			uint32_t sw_rst_audio_in : 1;
			uint32_t sw_rst_audio_adc : 1;
			uint32_t sw_rst_audio_dmic : 1;
			uint32_t sw_rst_saadc : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t sw_rst_audio_out : 1;
			uint32_t sw_rst_audio_dac : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* W1P_X2P_IP 10'h060 */
	union {
		uint32_t w1p_x2p_ip; // word name
		struct {
			uint32_t sw_rst_x2p_ip0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_SYS 10'h064 */
	union {
		uint32_t lv_sys; // word name
		struct {
			uint32_t lv_rst_efuse : 1;
			uint32_t lv_rst_eirq : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_TIMER 10'h068 */
	union {
		uint32_t lv_timer; // word name
		struct {
			uint32_t lv_rst_timer0 : 1;
			uint32_t lv_rst_timer1 : 1;
			uint32_t lv_rst_timer2 : 1;
			uint32_t lv_rst_timer3 : 1;
			uint32_t lv_rst_apb_timer : 1;
			uint32_t lv_rst_apb_wdt : 1;
			uint32_t lv_rst_apb_wdt_stable : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_TRNG 10'h06C */
	union {
		uint32_t lv_trng; // word name
		struct {
			uint32_t lv_rst_trng : 1;
			uint32_t lv_rst_apb_trng : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_AON 10'h070 [Unused] */
	uint32_t empty_word_lv_aon;
	/* LV_CPU 10'h074 */
	union {
		uint32_t lv_cpu; // word name
		struct {
			uint32_t lv_rst_cpu : 1;
			uint32_t lv_rst_cpu_corepor0 : 1;
			uint32_t lv_rst_cpu_corepor1 : 1;
			uint32_t lv_rst_cpu_corepor2 : 1;
			uint32_t lv_rst_cpu_corepor3 : 1;
			uint32_t lv_rst_cpu_core0 : 1;
			uint32_t lv_rst_cpu_core1 : 1;
			uint32_t lv_rst_cpu_core2 : 1;
			uint32_t lv_rst_cpu_core3 : 1;
			uint32_t lv_rst_cpu_dbg0 : 1;
			uint32_t lv_rst_cpu_dbg1 : 1;
			uint32_t lv_rst_cpu_dbg2 : 1;
			uint32_t lv_rst_cpu_dbg3 : 1;
			uint32_t lv_rst_cpu_l2 : 1;
			uint32_t lv_rst_cpu_socdbg : 1;
			uint32_t lv_rst_cpu_sys_cntr : 1;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_AXI_CPU 10'h078 */
	union {
		uint32_t lv_axi_cpu; // word name
		struct {
			uint32_t lv_rst_axi_cpu : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_axi_sys : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_APB 10'h07C */
	union {
		uint32_t lv_apb; // word name
		struct {
			uint32_t lv_rst_apb0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_apb1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_apb2 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_apb3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LV_DRAM 10'h080 */
	union {
		uint32_t lv_dram; // word name
		struct {
			uint32_t lv_rst_ddrphy_dll : 1;
			uint32_t lv_rst_ddrphy : 1;
			uint32_t lv_rst_ddrphy_hdr : 1;
			uint32_t lv_rst_dramc_hdr : 1;
			uint32_t lv_rst_apb_ddrphy : 1;
			uint32_t lv_rst_apb_dramc : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_AXI_DRAMC 10'h084 */
	union {
		uint32_t lv_axi_dramc; // word name
		struct {
			uint32_t lv_rst_axi_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_I2CS 10'h088 */
	union {
		uint32_t lv_i2cs; // word name
		struct {
			uint32_t lv_rst_apb_i2cs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_I2CM 10'h08C */
	union {
		uint32_t lv_i2cm; // word name
		struct {
			uint32_t lv_rst_i2cm0 : 1;
			uint32_t lv_rst_apb_i2cm0 : 1;
			uint32_t lv_rst_i2cm1 : 1;
			uint32_t lv_rst_apb_i2cm1 : 1;
			uint32_t lv_rst_i2cm2 : 1;
			uint32_t lv_rst_apb_i2cm2 : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_SPI 10'h090 */
	union {
		uint32_t lv_spi; // word name
		struct {
			uint32_t lv_rst_spi0 : 1;
			uint32_t lv_rst_apb_spi0 : 1;
			uint32_t lv_rst_spi1 : 1;
			uint32_t lv_rst_apb_spi1 : 1;
			uint32_t lv_rst_spi_slave : 1;
			uint32_t lv_rst_apb_spi_slave : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_UART 10'h094 */
	union {
		uint32_t lv_uart; // word name
		struct {
			uint32_t lv_rst_uart0 : 1;
			uint32_t lv_rst_apb_uart0 : 1;
			uint32_t lv_rst_uart1 : 1;
			uint32_t lv_rst_apb_uart1 : 1;
			uint32_t lv_rst_uart2 : 1;
			uint32_t lv_rst_apb_uart2 : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_PWM 10'h098 */
	union {
		uint32_t lv_pwm; // word name
		struct {
			uint32_t lv_rst_pwm0 : 1;
			uint32_t lv_rst_apb_pwm0 : 1;
			uint32_t lv_rst_pwm1 : 1;
			uint32_t lv_rst_pwm2 : 1;
			uint32_t lv_rst_pwm3 : 1;
			uint32_t lv_rst_pwm4 : 1;
			uint32_t lv_rst_pwm5 : 1;
			uint32_t lv_rst_pwm6 : 1;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_EMAC 10'h09C */
	union {
		uint32_t lv_emac; // word name
		struct {
			uint32_t lv_rst_apb_emac : 1;
			uint32_t lv_rst_emac_rx : 1;
			uint32_t lv_rst_emac_axi_dramc : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_QSPI 10'h0A0 */
	union {
		uint32_t lv_qspi; // word name
		struct {
			uint32_t lv_rst_qspi : 1;
			uint32_t lv_rst_apb_qspi : 1;
			uint32_t lv_rst_qspi_axi_dramc : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_PVT 10'h0A4 */
	union {
		uint32_t lv_pvt; // word name
		struct {
			uint32_t lv_rst_pvt : 1;
			uint32_t lv_rst_apb_pvt : 1;
			uint32_t lv_rst_pvt_sys : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_SDC 10'h0A8 */
	union {
		uint32_t lv_sdc; // word name
		struct {
			uint32_t lv_rst_sdc0 : 1;
			uint32_t lv_rst_apb_sdc0 : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t lv_rst_sdc1 : 1;
			uint32_t lv_rst_apb_sdc1 : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_USB 10'h0AC */
	union {
		uint32_t lv_usb; // word name
		struct {
			uint32_t lv_rst_apb_usb : 1;
			uint32_t lv_rst_ahb_usb : 1;
			uint32_t lv_rst_usb_utmi : 1;
			uint32_t lv_rst_usb_phy : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_SENSOR 10'h0B0 */
	union {
		uint32_t lv_sensor; // word name
		struct {
			uint32_t lv_rst_sensor : 1;
			uint32_t lv_rst_mipi_chop0 : 1;
			uint32_t lv_rst_senif : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_IS 10'h0B4 */
	union {
		uint32_t lv_is; // word name
		struct {
			uint32_t lv_rst_is : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_ISPVP 10'h0B8 */
	union {
		uint32_t lv_ispvp; // word name
		struct {
			uint32_t lv_rst_isp : 1;
			uint32_t lv_rst_vp : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_ENC 10'h0BC */
	union {
		uint32_t lv_enc; // word name
		struct {
			uint32_t lv_rst_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_AUDIO 10'h0C0 */
	union {
		uint32_t lv_audio; // word name
		struct {
			uint32_t lv_rst_audio_in : 1;
			uint32_t lv_rst_audio_adc : 1;
			uint32_t lv_rst_audio_dmic : 1;
			uint32_t lv_rst_saadc : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t lv_rst_audio_out : 1;
			uint32_t lv_rst_audio_dac : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LV_X2P_IP 10'h0C4 */
	union {
		uint32_t lv_x2p_ip; // word name
		struct {
			uint32_t lv_rst_x2p_ip1 : 1;
			uint32_t lv_rst_x2p_ip2 : 1;
			uint32_t lv_rst_x2p_ip3 : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESERVED 10'h0C8 */
	union {
		uint32_t reserved; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
} CsrBankRst;

#endif