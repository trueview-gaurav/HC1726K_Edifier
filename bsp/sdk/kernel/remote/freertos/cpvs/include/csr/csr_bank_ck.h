#ifndef CSR_BANK_CK_H_
#define CSR_BANK_CK_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ck  ***/
typedef struct csr_bank_ck {
	/* HW_CKG_APB0 8'h00 */
	union {
		uint32_t hw_ckg_apb0; // word name
		struct {
			uint32_t dis_cg_apb_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cg_delay_m1_apb_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CA7_AXI_ENM 8'h04 */
	union {
		uint32_t ca7_axi_enm; // word name
		struct {
			uint32_t aclkenm_num_m1 : 2;
			uint32_t : 6; // padding bits
			uint32_t aclkenm_init : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CA7_APB_ENM 8'h08 */
	union {
		uint32_t ca7_apb_enm; // word name
		struct {
			uint32_t pclkendbg_num_m1 : 2;
			uint32_t : 6; // padding bits
			uint32_t pclkendbg_init : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DDR 8'h0C */
	union {
		uint32_t ckg_ddr; // word name
		struct {
			uint32_t cken_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dramc_hdr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_AXI_DRAMC 8'h10 */
	union {
		uint32_t ckg_axi_dramc; // word name
		struct {
			uint32_t cken_axi_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DMA 8'h14 */
	union {
		uint32_t ckg_dma; // word name
		struct {
			uint32_t cken_dma_ado_codec : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_APB_SPI 8'h18 */
	union {
		uint32_t ckg_apb_spi; // word name
		struct {
			uint32_t cken_apb_spi0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_apb_spi1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_APB_UART03 8'h1C */
	union {
		uint32_t ckg_apb_uart03; // word name
		struct {
			uint32_t cken_apb_uart0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_apb_uart1 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_apb_uart2 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_apb_uart3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKG_APB_UART45 8'h20 */
	union {
		uint32_t ckg_apb_uart45; // word name
		struct {
			uint32_t cken_apb_uart4 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_apb_uart5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_APB_SDC 8'h24 */
	union {
		uint32_t ckg_apb_sdc; // word name
		struct {
			uint32_t cken_apb_sdc0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_apb_sdc1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_APB_EMAC 8'h28 */
	union {
		uint32_t ckg_apb_emac; // word name
		struct {
			uint32_t cken_apb_emac : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_AXI_ROM 8'h2C */
	union {
		uint32_t ckg_axi_rom; // word name
		struct {
			uint32_t cken_axi_rom : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_AXI_RAM 8'h30 */
	union {
		uint32_t ckg_axi_ram; // word name
		struct {
			uint32_t cken_axi_ram : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_AHB0 8'h34 */
	union {
		uint32_t ckg_ahb0; // word name
		struct {
			uint32_t cken_ahb_master : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_ahb_usb : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_AHB1 8'h38 */
	union {
		uint32_t ckg_ahb1; // word name
		struct {
			uint32_t cken_ahb_sdc_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_ahb_sdc_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_EMAC 8'h3C */
	union {
		uint32_t ckg_emac; // word name
		struct {
			uint32_t cken_emac_rgmii : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_emac_rmii : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_QSPI 8'h40 */
	union {
		uint32_t ckg_qspi; // word name
		struct {
			uint32_t cken_qspi : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_ISP 8'h44 */
	union {
		uint32_t ckg_isp; // word name
		struct {
			uint32_t cken_isp : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_vp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_SNSR 8'h48 */
	union {
		uint32_t ckg_snsr; // word name
		struct {
			uint32_t cken_sensor : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_IS 8'h4C */
	union {
		uint32_t ckg_is; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t cken_is : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DISP 8'h50 */
	union {
		uint32_t ckg_disp; // word name
		struct {
			uint32_t cken_disp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_SDC 8'h54 */
	union {
		uint32_t ckg_sdc; // word name
		struct {
			uint32_t cken_sdc_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_sdc_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_ENC 8'h58 */
	union {
		uint32_t ckg_enc; // word name
		struct {
			uint32_t cken_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_EFUSE 8'h5C */
	union {
		uint32_t ckg_efuse; // word name
		struct {
			uint32_t cken_efuse : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_EIRQ 8'h60 */
	union {
		uint32_t ckg_eirq; // word name
		struct {
			uint32_t cken_eirq : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_ISLP 8'h64 */
	union {
		uint32_t ckg_islp; // word name
		struct {
			uint32_t cken_is_lp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_I2CM 8'h68 */
	union {
		uint32_t ckg_i2cm; // word name
		struct {
			uint32_t cken_i2cm0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_i2cm1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_SPI 8'h6C */
	union {
		uint32_t ckg_spi; // word name
		struct {
			uint32_t cken_spi0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_spi1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_TIMER 8'h70 */
	union {
		uint32_t ckg_timer; // word name
		struct {
			uint32_t cken_timer0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_timer1 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_timer2 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_timer3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKG_PWM0 8'h74 */
	union {
		uint32_t ckg_pwm0; // word name
		struct {
			uint32_t cken_pwm_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_pwm_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_pwm_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_pwm_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKG_PWM1 8'h78 */
	union {
		uint32_t ckg_pwm1; // word name
		struct {
			uint32_t cken_pwm_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_pwm_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_ADO 8'h7C */
	union {
		uint32_t ckg_ado; // word name
		struct {
			uint32_t cken_audio_in : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_audio_out : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_USB 8'h80 */
	union {
		uint32_t ckg_usb; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t cken_usb_utmi : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CLK_DEF_DDR 8'h84 */
	union {
		uint32_t clk_def_ddr; // word name
		struct {
			uint32_t dramc_src_sel_dummy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CLK_DEF_DDR_AXI 8'h88 */
	union {
		uint32_t clk_def_ddr_axi; // word name
		struct {
			uint32_t axi_dramc_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CLK_DEF_ARM 8'h8C */
	union {
		uint32_t clk_def_arm; // word name
		struct {
			uint32_t arm_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t bus_src_sel_dummy : 1;
			uint32_t : 7; // padding bits
			uint32_t enm_mask_end_cnt : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* CLK_DEF_PWM2 8'h90 */
	union {
		uint32_t clk_def_pwm2; // word name
		struct {
			uint32_t pwm_2_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CLK_DEF_PWM3 8'h94 */
	union {
		uint32_t clk_def_pwm3; // word name
		struct {
			uint32_t pwm_3_src_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DISP_CLK_DIV_SEL 8'h98 */
	union {
		uint32_t word_disp_clk_div_sel; // word name
		struct {
			uint32_t disp_clk_div_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV_0 8'h9C */
	union {
		uint32_t resv_0; // word name
		struct {
			uint32_t reserved0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV_1 8'hA0 */
	union {
		uint32_t resv_1; // word name
		struct {
			uint32_t qspi_src_sel : 1;
			uint32_t reserved1 : 15;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV_2 8'hA4 */
	union {
		uint32_t resv_2; // word name
		struct {
			uint32_t reserved2 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCk;

#endif