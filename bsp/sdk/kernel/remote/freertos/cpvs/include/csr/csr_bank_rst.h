#ifndef CSR_BANK_RST_H_
#define CSR_BANK_RST_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from rst  ***/
typedef struct csr_bank_rst {
	/* RST_AXI 10'h000 */
	union {
		uint32_t rst_axi; // word name
		struct {
			uint32_t sw_rst_axi_cpu : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_axi_sys : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_axi_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_APB 10'h004 */
	union {
		uint32_t rst_apb; // word name
		struct {
			uint32_t sw_rst_apb_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_apb_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_apb_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_apb_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST_USB 10'h008 */
	union {
		uint32_t rst_usb; // word name
		struct {
			uint32_t sw_rst_apb_usb : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_usb_utmi : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_usb_phy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_DDR 10'h00C */
	union {
		uint32_t rst_ddr; // word name
		struct {
			uint32_t sw_rst_dramc_hdr : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_ddrphy : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_ddrphy_dll : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_ddrphy_hdr : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST_EMAC 10'h010 */
	union {
		uint32_t rst_emac; // word name
		struct {
			uint32_t sw_rst_apb_emac : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_SDC 10'h014 */
	union {
		uint32_t rst_sdc; // word name
		struct {
			uint32_t sw_rst_sdc_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_sdc_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_qspi : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_SDC_1 10'h018 */
	union {
		uint32_t rst_sdc_1; // word name
		struct {
			uint32_t sw_rst_apb_sdc_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_apb_sdc_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_SNSR 10'h01C */
	union {
		uint32_t rst_snsr; // word name
		struct {
			uint32_t sw_rst_sensor : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_ENC 10'h020 */
	union {
		uint32_t rst_enc; // word name
		struct {
			uint32_t sw_rst_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_IS 10'h024 */
	union {
		uint32_t rst_is; // word name
		struct {
			uint32_t sw_rst_is : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_DMA 10'h028 */
	union {
		uint32_t rst_dma; // word name
		struct {
			uint32_t sw_rst_dma : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_ISPVP 10'h02C */
	union {
		uint32_t rst_ispvp; // word name
		struct {
			uint32_t sw_rst_isp : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_vp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_DISP 10'h030 */
	union {
		uint32_t rst_disp; // word name
		struct {
			uint32_t sw_rst_disp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_DDR_1 10'h034 */
	union {
		uint32_t rst_ddr_1; // word name
		struct {
			uint32_t sw_rst_apb_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_apb_ddrphy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_AUDIO 10'h038 */
	union {
		uint32_t rst_audio; // word name
		struct {
			uint32_t sw_rst_audio_in : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_audio_out : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_PLAT0 10'h03C */
	union {
		uint32_t rst_plat0; // word name
		struct {
			uint32_t sw_rst_i2c_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_i2c_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_spi_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_spi_1 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST_PLAT1 10'h040 */
	union {
		uint32_t rst_plat1; // word name
		struct {
			uint32_t sw_rst_uart_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_uart_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_uart_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_uart_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST_PLAT2 10'h044 */
	union {
		uint32_t rst_plat2; // word name
		struct {
			uint32_t sw_rst_uart_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_uart_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_timer_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_timer_1 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST_PLAT3 10'h048 */
	union {
		uint32_t rst_plat3; // word name
		struct {
			uint32_t sw_rst_timer_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_timer_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_pwm_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_pwm_1 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST_PLAT4 10'h04C */
	union {
		uint32_t rst_plat4; // word name
		struct {
			uint32_t sw_rst_pwm_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_pwm_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_pwm_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_pwm_5 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST0 10'h050 [Unused] */
	uint32_t empty_word_rst0;
	/* RST1 10'h054 [Unused] */
	uint32_t empty_word_rst1;
	/* RST2 10'h058 [Unused] */
	uint32_t empty_word_rst2;
	/* RST3 10'h05C [Unused] */
	uint32_t empty_word_rst3;
	/* RST4 10'h060 [Unused] */
	uint32_t empty_word_rst4;
	/* RST5 10'h064 [Unused] */
	uint32_t empty_word_rst5;
	/* RST6 10'h068 [Unused] */
	uint32_t empty_word_rst6;
	/* RST7 10'h06C [Unused] */
	uint32_t empty_word_rst7;
	/* RST8 10'h070 [Unused] */
	uint32_t empty_word_rst8;
	/* RST9 10'h074 [Unused] */
	uint32_t empty_word_rst9;
	/* RST10 10'h078 [Unused] */
	uint32_t empty_word_rst10;
	/* RST11 10'h07C [Unused] */
	uint32_t empty_word_rst11;
	/* RST12 10'h080 [Unused] */
	uint32_t empty_word_rst12;
	/* RST13 10'h084 [Unused] */
	uint32_t empty_word_rst13;
	/* RST14 10'h088 [Unused] */
	uint32_t empty_word_rst14;
	/* RST15 10'h08C [Unused] */
	uint32_t empty_word_rst15;
	/* RST16 10'h090 [Unused] */
	uint32_t empty_word_rst16;
	/* RST17 10'h094 [Unused] */
	uint32_t empty_word_rst17;
	/* RST18 10'h098 [Unused] */
	uint32_t empty_word_rst18;
	/* RST19 10'h09C [Unused] */
	uint32_t empty_word_rst19;
	/* undefined word 0xA0 [Undefined] */
	uint32_t undefined_word_0xA0;
	/* undefined word 0xA4 [Undefined] */
	uint32_t undefined_word_0xA4;
	/* undefined word 0xA8 [Undefined] */
	uint32_t undefined_word_0xA8;
	/* undefined word 0xAC [Undefined] */
	uint32_t undefined_word_0xAC;
	/* undefined word 0xB0 [Undefined] */
	uint32_t undefined_word_0xB0;
	/* undefined word 0xB4 [Undefined] */
	uint32_t undefined_word_0xB4;
	/* undefined word 0xB8 [Undefined] */
	uint32_t undefined_word_0xB8;
	/* undefined word 0xBC [Undefined] */
	uint32_t undefined_word_0xBC;
	/* undefined word 0xC0 [Undefined] */
	uint32_t undefined_word_0xC0;
	/* undefined word 0xC4 [Undefined] */
	uint32_t undefined_word_0xC4;
	/* undefined word 0xC8 [Undefined] */
	uint32_t undefined_word_0xC8;
	/* undefined word 0xCC [Undefined] */
	uint32_t undefined_word_0xCC;
	/* undefined word 0xD0 [Undefined] */
	uint32_t undefined_word_0xD0;
	/* undefined word 0xD4 [Undefined] */
	uint32_t undefined_word_0xD4;
	/* undefined word 0xD8 [Undefined] */
	uint32_t undefined_word_0xD8;
	/* undefined word 0xDC [Undefined] */
	uint32_t undefined_word_0xDC;
	/* undefined word 0xE0 [Undefined] */
	uint32_t undefined_word_0xE0;
	/* undefined word 0xE4 [Undefined] */
	uint32_t undefined_word_0xE4;
	/* undefined word 0xE8 [Undefined] */
	uint32_t undefined_word_0xE8;
	/* undefined word 0xEC [Undefined] */
	uint32_t undefined_word_0xEC;
	/* undefined word 0xF0 [Undefined] */
	uint32_t undefined_word_0xF0;
	/* undefined word 0xF4 [Undefined] */
	uint32_t undefined_word_0xF4;
	/* undefined word 0xF8 [Undefined] */
	uint32_t undefined_word_0xF8;
	/* undefined word 0xFC [Undefined] */
	uint32_t undefined_word_0xFC;
	/* RST_EIRQ 10'h100 */
	union {
		uint32_t rst_eirq; // word name
		struct {
			uint32_t sw_rst_eirq : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_AXI 10'h104 */
	union {
		uint32_t lvrst_axi; // word name
		struct {
			uint32_t lv_rst_axi_cpu : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_axi_sys : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_axi_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_APB 10'h108 */
	union {
		uint32_t lvrst_apb; // word name
		struct {
			uint32_t lv_rst_apb_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_apb_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_apb_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_apb_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVRST_USB 10'h10C */
	union {
		uint32_t lvrst_usb; // word name
		struct {
			uint32_t lv_rst_apb_usb : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_usb_utmi : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_usb_phy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_DDR 10'h110 */
	union {
		uint32_t lvrst_ddr; // word name
		struct {
			uint32_t lv_rst_dramc_hdr : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ddrphy : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ddrphy_dll : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ddrphy_hdr : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVRST_EMAC 10'h114 */
	union {
		uint32_t lvrst_emac; // word name
		struct {
			uint32_t lv_rst_apb_emac : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_SDC 10'h118 */
	union {
		uint32_t lvrst_sdc; // word name
		struct {
			uint32_t lv_rst_sdc_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_sdc_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_qspi : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_SDC_1 10'h11C */
	union {
		uint32_t lvrst_sdc_1; // word name
		struct {
			uint32_t lv_rst_apb_sdc_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_apb_sdc_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_SNSR 10'h120 */
	union {
		uint32_t lvrst_snsr; // word name
		struct {
			uint32_t lv_rst_sensor : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_ENC 10'h124 */
	union {
		uint32_t lvrst_enc; // word name
		struct {
			uint32_t lv_rst_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_IS 10'h128 */
	union {
		uint32_t lvrst_is; // word name
		struct {
			uint32_t lv_rst_is : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_DMA 10'h12C */
	union {
		uint32_t lvrst_dma; // word name
		struct {
			uint32_t lv_rst_dma : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_ISPVP 10'h130 */
	union {
		uint32_t lvrst_ispvp; // word name
		struct {
			uint32_t lv_rst_isp : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_vp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_DISP 10'h134 */
	union {
		uint32_t lvrst_disp; // word name
		struct {
			uint32_t lv_rst_disp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_DDR_1 10'h138 */
	union {
		uint32_t lvrst_ddr_1; // word name
		struct {
			uint32_t lv_rst_apb_dramc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_apb_ddrphy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_AUDIO 10'h13C */
	union {
		uint32_t lvrst_audio; // word name
		struct {
			uint32_t lv_rst_audio_in : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_audio_out : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_PLAT0 10'h140 */
	union {
		uint32_t lvrst_plat0; // word name
		struct {
			uint32_t lv_rst_i2c_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_i2c_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_spi_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_spi_1 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVRST_PLAT1 10'h144 */
	union {
		uint32_t lvrst_plat1; // word name
		struct {
			uint32_t lv_rst_uart_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_uart_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_uart_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_uart_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVRST_PLAT2 10'h148 */
	union {
		uint32_t lvrst_plat2; // word name
		struct {
			uint32_t lv_rst_uart_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_uart_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_timer_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_timer_1 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVRST_PLAT3 10'h14C */
	union {
		uint32_t lvrst_plat3; // word name
		struct {
			uint32_t lv_rst_timer_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_timer_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pwm_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pwm_1 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVRST_PLAT4 10'h150 */
	union {
		uint32_t lvrst_plat4; // word name
		struct {
			uint32_t lv_rst_pwm_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pwm_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pwm_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_pwm_5 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVRST_EIRQ 10'h154 */
	union {
		uint32_t lvrst_eirq; // word name
		struct {
			uint32_t lv_rst_eirq : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankRst;

#endif