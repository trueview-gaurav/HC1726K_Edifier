/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_CK_H_
#define CSR_BANK_CK_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ck  ***/
typedef struct csr_bank_ck {
	/* HW_CG_APB0 10'h000 */
	union {
		uint32_t hw_cg_apb0; // word name
		struct {
			uint32_t dis_cg_apb0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cg_delay_m1_apb0 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_AXI_CPU 10'h004 */
	union {
		uint32_t cg_axi_cpu; // word name
		struct {
			uint32_t cken_axi_rom : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_axi_ram : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_AXI_DRAM 10'h008 */
	union {
		uint32_t cg_axi_dram; // word name
		struct {
			uint32_t cken_axi_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_DRAM 10'h00C */
	union {
		uint32_t cg_dram; // word name
		struct {
			uint32_t cken_apb_ddrphy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t cken_apb_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_I2CS 10'h010 [Unused] */
	uint32_t empty_word_cg_i2cs;
	/* CG_SYS 10'h014 */
	union {
		uint32_t cg_sys; // word name
		struct {
			uint32_t cken_efuse : 1;
			uint32_t cken_eirq : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_TIMER 10'h018 */
	union {
		uint32_t cg_timer; // word name
		struct {
			uint32_t cken_timer0 : 1;
			uint32_t cken_timer1 : 1;
			uint32_t cken_timer2 : 1;
			uint32_t cken_timer3 : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_TRNG 10'h01C */
	union {
		uint32_t cg_trng; // word name
		struct {
			uint32_t cken_trng : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_I2CM 10'h020 */
	union {
		uint32_t cg_i2cm; // word name
		struct {
			uint32_t cken_i2cm0 : 1;
			uint32_t cken_i2cm1 : 1;
			uint32_t cken_i2cm2 : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_SPI 10'h024 */
	union {
		uint32_t cg_spi; // word name
		struct {
			uint32_t cken_spi0 : 1;
			uint32_t cken_spi1 : 1;
			uint32_t cken_spi_slave : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_PWM 10'h028 */
	union {
		uint32_t cg_pwm; // word name
		struct {
			uint32_t cken_pwm0 : 1;
			uint32_t cken_pwm1 : 1;
			uint32_t cken_pwm2 : 1;
			uint32_t cken_pwm3 : 1;
			uint32_t cken_pwm4 : 1;
			uint32_t cken_pwm5 : 1;
			uint32_t cken_pwm6 : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_UART 10'h02C */
	union {
		uint32_t cg_uart; // word name
		struct {
			uint32_t cken_uart0 : 1;
			uint32_t cken_uart1 : 1;
			uint32_t cken_uart2 : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_QSPI 10'h030 */
	union {
		uint32_t cg_qspi; // word name
		struct {
			uint32_t cken_qspi : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_SDC 10'h034 */
	union {
		uint32_t cg_sdc; // word name
		struct {
			uint32_t cken_sdc0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_sdc1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_EMAC 10'h038 */
	union {
		uint32_t cg_emac; // word name
		struct {
			uint32_t cken_emac : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_USB 10'h03C */
	union {
		uint32_t cg_usb; // word name
		struct {
			uint32_t cken_ahb_usb : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_usb_utmi : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_SENSOR 10'h040 */
	union {
		uint32_t cg_sensor; // word name
		struct {
			uint32_t cken_sensor : 1;
			uint32_t cken_senif : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_MIPI_CHOP 10'h044 */
	union {
		uint32_t cg_mipi_chop; // word name
		struct {
			uint32_t cken_mipi_chop0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_IS 10'h048 */
	union {
		uint32_t cg_is; // word name
		struct {
			uint32_t cken_is : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_ISP_VP 10'h04C */
	union {
		uint32_t cg_isp_vp; // word name
		struct {
			uint32_t cken_isp : 1;
			uint32_t cken_vp : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_ENC 10'h050 */
	union {
		uint32_t cg_enc; // word name
		struct {
			uint32_t cken_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_AUDIO 10'h054 */
	union {
		uint32_t cg_audio; // word name
		struct {
			uint32_t cken_audio_in : 1;
			uint32_t cken_audio_adc : 1;
			uint32_t cken_audio_dmic : 1;
			uint32_t cken_audio_out : 1;
			uint32_t cken_audio_dac : 1;
			uint32_t cken_saadc : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_FM 10'h058 */
	union {
		uint32_t cg_fm; // word name
		struct {
			uint32_t cken_usb_fm : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_DDR 10'h05C */
	union {
		uint32_t def_ddr; // word name
		struct {
			uint32_t dramc_hdr_div2_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ddr_phy_ref_div_num : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_AXI_DRAM 10'h060 */
	union {
		uint32_t def_axi_dram; // word name
		struct {
			uint32_t axi_dramc_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_CPU_0 10'h064 */
	union {
		uint32_t def_cpu_0; // word name
		struct {
			uint32_t aclkenm_num_m1 : 2;
			uint32_t : 6; // padding bits
			uint32_t aclkenm_init : 1;
			uint32_t : 7; // padding bits
			uint32_t pclkendbg_num_m1 : 2;
			uint32_t : 6; // padding bits
			uint32_t pclkendbg_init : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DEF_CPU_1 10'h068 */
	union {
		uint32_t def_cpu_1; // word name
		struct {
			uint32_t cpu_src_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t enm_mask_end_cnt : 8;
			uint32_t cpu_div_num : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* DEF_AXI_SYS 10'h06C */
	union {
		uint32_t def_axi_sys; // word name
		struct {
			uint32_t axi_sys_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t axi_sys_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_APB_0 10'h070 */
	union {
		uint32_t def_apb_0; // word name
		struct {
			uint32_t apb0_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t apb1_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t apb2_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t apb3_div_num : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DEF_AHB_0 10'h074 */
	union {
		uint32_t def_ahb_0; // word name
		struct {
			uint32_t ahb_usb_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_AHB_1 10'h078 */
	union {
		uint32_t def_ahb_1; // word name
		struct {
			uint32_t ahb_usb_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_PWM_0 10'h07C */
	union {
		uint32_t def_pwm_0; // word name
		struct {
			uint32_t pwm0_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t pwm1_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t pwm2_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t pwm3_src_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DEF_PWM_1 10'h080 */
	union {
		uint32_t def_pwm_1; // word name
		struct {
			uint32_t pwm4_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t pwm5_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t pwm6_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_PWM_2 10'h084 */
	union {
		uint32_t def_pwm_2; // word name
		struct {
			uint32_t pwm0_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t pwm1_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t pwm2_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t pwm3_div_num : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* DEF_PWM_3 10'h088 */
	union {
		uint32_t def_pwm_3; // word name
		struct {
			uint32_t pwm4_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t pwm5_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t pwm6_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_UART_0 10'h08C */
	union {
		uint32_t def_uart_0; // word name
		struct {
			uint32_t uart0_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t uart0_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t uart1_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t uart1_div_num : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* DEF_UART_1 10'h090 */
	union {
		uint32_t def_uart_1; // word name
		struct {
			uint32_t uart2_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t uart2_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_QSPI 10'h094 */
	union {
		uint32_t def_qspi; // word name
		struct {
			uint32_t qspi_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t qspi_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_SDC0 10'h098 */
	union {
		uint32_t def_sdc0; // word name
		struct {
			uint32_t sdc0_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t sdc0_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_SDC1 10'h09C */
	union {
		uint32_t def_sdc1; // word name
		struct {
			uint32_t sdc1_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t sdc1_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_EMAC_0 10'h0A0 */
	union {
		uint32_t def_emac_0; // word name
		struct {
			uint32_t emac_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t emac_div_num : 9;
			uint32_t : 7; // padding bits
			uint32_t emac_phy_rx_div_num : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* DEF_USB 10'h0A4 */
	union {
		uint32_t def_usb; // word name
		struct {
			uint32_t usb_utmi_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_SENSOR 10'h0A8 */
	union {
		uint32_t def_sensor; // word name
		struct {
			uint32_t sensor_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t sensor_div_num : 2;
			uint32_t : 6; // padding bits
			uint32_t senif_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t senif_div_num : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DEF_MIPI_CHOP 10'h0AC */
	union {
		uint32_t def_mipi_chop; // word name
		struct {
			uint32_t mipi_chop0_src_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t mipi_chop0_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_IS 10'h0B0 */
	union {
		uint32_t def_is; // word name
		struct {
			uint32_t is_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t is_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_ISP_VP 10'h0B4 */
	union {
		uint32_t def_isp_vp; // word name
		struct {
			uint32_t isp_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t isp_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t vp_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t vp_div_num : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DEF_VENC 10'h0B8 */
	union {
		uint32_t def_venc; // word name
		struct {
			uint32_t enc_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t enc_div_num : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_AUDIO_IN 10'h0BC */
	union {
		uint32_t def_audio_in; // word name
		struct {
			uint32_t audio_in_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t audio_in_div_num : 2;
			uint32_t : 6; // padding bits
			uint32_t audio_adc_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_AUDIO_OUT 10'h0C0 */
	union {
		uint32_t def_audio_out; // word name
		struct {
			uint32_t audio_out_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t audio_out_div_num : 2;
			uint32_t : 6; // padding bits
			uint32_t audio_dac_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_SAADC 10'h0C4 */
	union {
		uint32_t def_saadc; // word name
		struct {
			uint32_t saadc_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t saadc_div_num : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_FM_0 10'h0C8 */
	union {
		uint32_t def_fm_0; // word name
		struct {
			uint32_t cas_pll_fm_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t ddr_pll_fm_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t cpu_pll_fm_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t venc_pll_fm_src_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DEF_FM_1 10'h0CC */
	union {
		uint32_t def_fm_1; // word name
		struct {
			uint32_t epll_fm_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t sensor_pll_fm_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t audio_pll_fm_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_FM_2 10'h0D0 */
	union {
		uint32_t def_fm_2; // word name
		struct {
			uint32_t usb_fm_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_PVT 10'h0D4 */
	union {
		uint32_t cg_pvt; // word name
		struct {
			uint32_t cken_pvt : 1;
			uint32_t cken_pvt_sys : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_PVT 10'h0D8 */
	union {
		uint32_t def_pvt; // word name
		struct {
			uint32_t pvt_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_SPI 10'h0DC */
	union {
		uint32_t def_spi; // word name
		struct {
			uint32_t spi0_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t spi0_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t spi1_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t spi1_div_num : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* DEF_SPI_SLAVE 10'h0E0 */
	union {
		uint32_t def_spi_slave; // word name
		struct {
			uint32_t spi_slave_src_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t spi_slave_div_num : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEF_SYS 10'h0E4 */
	union {
		uint32_t def_sys; // word name
		struct {
			uint32_t sys_div_num : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESERVED_0 10'h0E8 */
	union {
		uint32_t reserved_0; // word name
		struct {
			uint32_t reserved0 : 32;
		};
	};
	/* DEF_AUDIO_DMIC 10'h0EC */
	union {
		uint32_t def_audio_dmic; // word name
		struct {
			uint32_t audio_dmic_div_num : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCk;

#endif