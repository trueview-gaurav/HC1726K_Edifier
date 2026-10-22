#ifndef CSR_BANK_FPGA_CFG_H_
#define CSR_BANK_FPGA_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from fpga_cfg  ***/
typedef struct csr_bank_fpga_cfg {
	/* FPGA_VER 16'h0000 */
	union {
		uint32_t fpga_ver; // word name
		struct {
			uint32_t fpga_version : 32;
		};
	};
	/* FPGA_MODULE 16'h0004 */
	union {
		uint32_t fpga_module; // word name
		struct {
			uint32_t fpga_module_en : 32;
		};
	};
	/* FPGA_GPIO_O 16'h0008 */
	union {
		uint32_t fpga_gpio_o; // word name
		struct {
			uint32_t fpga_gpio_o_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_GPIO_OE 16'h000C */
	union {
		uint32_t fpga_gpio_oe; // word name
		struct {
			uint32_t fpga_gpio_oe_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPGA_GPIO_I 16'h0010 */
	union {
		uint32_t fpga_gpio_i; // word name
		struct {
			uint32_t fpga_gpio_i_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_MDC_IOSEL 16'h0014 */
	union {
		uint32_t emac_mdc_iosel; // word name
		struct {
			uint32_t pad_emac_mdc_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_CTL_IOSEL 16'h0018 */
	union {
		uint32_t emac_tx_ctl_iosel; // word name
		struct {
			uint32_t pad_emac_tx_ctl_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_O_CLK_IOSEL 16'h001C */
	union {
		uint32_t emac_tx_o_clk_iosel; // word name
		struct {
			uint32_t pad_emac_tx_o_clk_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D0_IOSEL 16'h0020 */
	union {
		uint32_t emac_tx_d0_iosel; // word name
		struct {
			uint32_t pad_emac_tx_d0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D1_IOSEL 16'h0024 */
	union {
		uint32_t emac_tx_d1_iosel; // word name
		struct {
			uint32_t pad_emac_tx_d1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO82_IOSEL 16'h0028 */
	union {
		uint32_t io82_iosel; // word name
		struct {
			uint32_t pad_io82_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO81_IOSEL 16'h002C */
	union {
		uint32_t io81_iosel; // word name
		struct {
			uint32_t pad_io81_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO80_IOSEL 16'h0030 */
	union {
		uint32_t io80_iosel; // word name
		struct {
			uint32_t pad_io80_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO79_IOSEL 16'h0034 */
	union {
		uint32_t io79_iosel; // word name
		struct {
			uint32_t pad_io79_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO78_IOSEL 16'h0038 */
	union {
		uint32_t io78_iosel; // word name
		struct {
			uint32_t pad_io78_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO77_IOSEL 16'h003C */
	union {
		uint32_t io77_iosel; // word name
		struct {
			uint32_t pad_io77_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO48_IOSEL 16'h0040 */
	union {
		uint32_t io48_iosel; // word name
		struct {
			uint32_t pad_io48_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO47_IOSEL 16'h0044 */
	union {
		uint32_t io47_iosel; // word name
		struct {
			uint32_t pad_io47_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO46_IOSEL 16'h0048 */
	union {
		uint32_t io46_iosel; // word name
		struct {
			uint32_t pad_io46_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO45_IOSEL 16'h004C */
	union {
		uint32_t io45_iosel; // word name
		struct {
			uint32_t pad_io45_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO76_IOSEL 16'h0050 */
	union {
		uint32_t io76_iosel; // word name
		struct {
			uint32_t pad_io76_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO75_IOSEL 16'h0054 */
	union {
		uint32_t io75_iosel; // word name
		struct {
			uint32_t pad_io75_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO74_IOSEL 16'h0058 */
	union {
		uint32_t io74_iosel; // word name
		struct {
			uint32_t pad_io74_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO73_IOSEL 16'h005C */
	union {
		uint32_t io73_iosel; // word name
		struct {
			uint32_t pad_io73_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO72_IOSEL 16'h0060 */
	union {
		uint32_t io72_iosel; // word name
		struct {
			uint32_t pad_io72_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO71_IOSEL 16'h0064 */
	union {
		uint32_t io71_iosel; // word name
		struct {
			uint32_t pad_io71_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO70_IOSEL 16'h0068 */
	union {
		uint32_t io70_iosel; // word name
		struct {
			uint32_t pad_io70_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO69_IOSEL 16'h006C */
	union {
		uint32_t io69_iosel; // word name
		struct {
			uint32_t pad_io69_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO44_IOSEL 16'h0070 */
	union {
		uint32_t io44_iosel; // word name
		struct {
			uint32_t pad_io44_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO43_IOSEL 16'h0074 */
	union {
		uint32_t io43_iosel; // word name
		struct {
			uint32_t pad_io43_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO42_IOSEL 16'h0078 */
	union {
		uint32_t io42_iosel; // word name
		struct {
			uint32_t pad_io42_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO41_IOSEL 16'h007C */
	union {
		uint32_t io41_iosel; // word name
		struct {
			uint32_t pad_io41_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO40_IOSEL 16'h0080 */
	union {
		uint32_t io40_iosel; // word name
		struct {
			uint32_t pad_io40_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO39_IOSEL 16'h0084 */
	union {
		uint32_t io39_iosel; // word name
		struct {
			uint32_t pad_io39_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TC_SENSOR_CLK_IOSEL 16'h0088 */
	union {
		uint32_t tc_sensor_clk_iosel; // word name
		struct {
			uint32_t pad_tc_sensor_clk_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO83_IOSEL 16'h008C */
	union {
		uint32_t io83_iosel; // word name
		struct {
			uint32_t pad_io83_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO84_IOSEL 16'h0090 */
	union {
		uint32_t io84_iosel; // word name
		struct {
			uint32_t pad_io84_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TC_DISP_RESET_IOSEL 16'h0094 */
	union {
		uint32_t tc_disp_reset_iosel; // word name
		struct {
			uint32_t pad_tc_disp_reset_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO7_IOSEL 16'h0098 */
	union {
		uint32_t io7_iosel; // word name
		struct {
			uint32_t pad_io7_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO14_IOSEL 16'h009C */
	union {
		uint32_t io14_iosel; // word name
		struct {
			uint32_t pad_io14_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO13_IOSEL 16'h00A0 */
	union {
		uint32_t io13_iosel; // word name
		struct {
			uint32_t pad_io13_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO12_IOSEL 16'h00A4 */
	union {
		uint32_t io12_iosel; // word name
		struct {
			uint32_t pad_io12_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO11_IOSEL 16'h00A8 */
	union {
		uint32_t io11_iosel; // word name
		struct {
			uint32_t pad_io11_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO10_IOSEL 16'h00AC */
	union {
		uint32_t io10_iosel; // word name
		struct {
			uint32_t pad_io10_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO9_IOSEL 16'h00B0 */
	union {
		uint32_t io9_iosel; // word name
		struct {
			uint32_t pad_io9_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO8_IOSEL 16'h00B4 */
	union {
		uint32_t io8_iosel; // word name
		struct {
			uint32_t pad_io8_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO68_IOSEL 16'h00B8 */
	union {
		uint32_t io68_iosel; // word name
		struct {
			uint32_t pad_io68_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO67_IOSEL 16'h00BC */
	union {
		uint32_t io67_iosel; // word name
		struct {
			uint32_t pad_io67_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO66_IOSEL 16'h00C0 */
	union {
		uint32_t io66_iosel; // word name
		struct {
			uint32_t pad_io66_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO65_IOSEL 16'h00C4 */
	union {
		uint32_t io65_iosel; // word name
		struct {
			uint32_t pad_io65_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO64_IOSEL 16'h00C8 */
	union {
		uint32_t io64_iosel; // word name
		struct {
			uint32_t pad_io64_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO63_IOSEL 16'h00CC */
	union {
		uint32_t io63_iosel; // word name
		struct {
			uint32_t pad_io63_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO62_IOSEL 16'h00D0 */
	union {
		uint32_t io62_iosel; // word name
		struct {
			uint32_t pad_io62_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO61_IOSEL 16'h00D4 */
	union {
		uint32_t io61_iosel; // word name
		struct {
			uint32_t pad_io61_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO60_IOSEL 16'h00D8 */
	union {
		uint32_t io60_iosel; // word name
		struct {
			uint32_t pad_io60_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO59_IOSEL 16'h00DC */
	union {
		uint32_t io59_iosel; // word name
		struct {
			uint32_t pad_io59_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO38_IOSEL 16'h00E0 */
	union {
		uint32_t io38_iosel; // word name
		struct {
			uint32_t pad_io38_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO37_IOSEL 16'h00E4 */
	union {
		uint32_t io37_iosel; // word name
		struct {
			uint32_t pad_io37_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO36_IOSEL 16'h00E8 */
	union {
		uint32_t io36_iosel; // word name
		struct {
			uint32_t pad_io36_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO35_IOSEL 16'h00EC */
	union {
		uint32_t io35_iosel; // word name
		struct {
			uint32_t pad_io35_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO34_IOSEL 16'h00F0 */
	union {
		uint32_t io34_iosel; // word name
		struct {
			uint32_t pad_io34_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO33_IOSEL 16'h00F4 */
	union {
		uint32_t io33_iosel; // word name
		struct {
			uint32_t pad_io33_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO32_IOSEL 16'h00F8 */
	union {
		uint32_t io32_iosel; // word name
		struct {
			uint32_t pad_io32_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO31_IOSEL 16'h00FC */
	union {
		uint32_t io31_iosel; // word name
		struct {
			uint32_t pad_io31_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO30_IOSEL 16'h0100 */
	union {
		uint32_t io30_iosel; // word name
		struct {
			uint32_t pad_io30_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO29_IOSEL 16'h0104 */
	union {
		uint32_t io29_iosel; // word name
		struct {
			uint32_t pad_io29_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO28_IOSEL 16'h0108 */
	union {
		uint32_t io28_iosel; // word name
		struct {
			uint32_t pad_io28_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO27_IOSEL 16'h010C */
	union {
		uint32_t io27_iosel; // word name
		struct {
			uint32_t pad_io27_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO58_IOSEL 16'h0110 */
	union {
		uint32_t io58_iosel; // word name
		struct {
			uint32_t pad_io58_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO57_IOSEL 16'h0114 */
	union {
		uint32_t io57_iosel; // word name
		struct {
			uint32_t pad_io57_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO56_IOSEL 16'h0118 */
	union {
		uint32_t io56_iosel; // word name
		struct {
			uint32_t pad_io56_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO55_IOSEL 16'h011C */
	union {
		uint32_t io55_iosel; // word name
		struct {
			uint32_t pad_io55_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO54_IOSEL 16'h0120 */
	union {
		uint32_t io54_iosel; // word name
		struct {
			uint32_t pad_io54_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO53_IOSEL 16'h0124 */
	union {
		uint32_t io53_iosel; // word name
		struct {
			uint32_t pad_io53_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO52_IOSEL 16'h0128 */
	union {
		uint32_t io52_iosel; // word name
		struct {
			uint32_t pad_io52_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO51_IOSEL 16'h012C */
	union {
		uint32_t io51_iosel; // word name
		struct {
			uint32_t pad_io51_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO50_IOSEL 16'h0130 */
	union {
		uint32_t io50_iosel; // word name
		struct {
			uint32_t pad_io50_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO49_IOSEL 16'h0134 */
	union {
		uint32_t io49_iosel; // word name
		struct {
			uint32_t pad_io49_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO26_IOSEL 16'h0138 */
	union {
		uint32_t io26_iosel; // word name
		struct {
			uint32_t pad_io26_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO25_IOSEL 16'h013C */
	union {
		uint32_t io25_iosel; // word name
		struct {
			uint32_t pad_io25_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO24_IOSEL 16'h0140 */
	union {
		uint32_t io24_iosel; // word name
		struct {
			uint32_t pad_io24_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO23_IOSEL 16'h0144 */
	union {
		uint32_t io23_iosel; // word name
		struct {
			uint32_t pad_io23_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO22_IOSEL 16'h0148 */
	union {
		uint32_t io22_iosel; // word name
		struct {
			uint32_t pad_io22_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO21_IOSEL 16'h014C */
	union {
		uint32_t io21_iosel; // word name
		struct {
			uint32_t pad_io21_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO20_IOSEL 16'h0150 */
	union {
		uint32_t io20_iosel; // word name
		struct {
			uint32_t pad_io20_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO19_IOSEL 16'h0154 */
	union {
		uint32_t io19_iosel; // word name
		struct {
			uint32_t pad_io19_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO18_IOSEL 16'h0158 */
	union {
		uint32_t io18_iosel; // word name
		struct {
			uint32_t pad_io18_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO17_IOSEL 16'h015C */
	union {
		uint32_t io17_iosel; // word name
		struct {
			uint32_t pad_io17_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO16_IOSEL 16'h0160 */
	union {
		uint32_t io16_iosel; // word name
		struct {
			uint32_t pad_io16_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO15_IOSEL 16'h0164 */
	union {
		uint32_t io15_iosel; // word name
		struct {
			uint32_t pad_io15_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO6_IOSEL 16'h0168 */
	union {
		uint32_t io6_iosel; // word name
		struct {
			uint32_t pad_io6_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO5_IOSEL 16'h016C */
	union {
		uint32_t io5_iosel; // word name
		struct {
			uint32_t pad_io5_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO4_IOSEL 16'h0170 */
	union {
		uint32_t io4_iosel; // word name
		struct {
			uint32_t pad_io4_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO3_IOSEL 16'h0174 */
	union {
		uint32_t io3_iosel; // word name
		struct {
			uint32_t pad_io3_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO2_IOSEL 16'h0178 */
	union {
		uint32_t io2_iosel; // word name
		struct {
			uint32_t pad_io2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO1_IOSEL 16'h017C */
	union {
		uint32_t io1_iosel; // word name
		struct {
			uint32_t pad_io1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IO0_IOSEL 16'h0180 */
	union {
		uint32_t io0_iosel; // word name
		struct {
			uint32_t pad_io0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO0_IOSEL 16'h0184 */
	union {
		uint32_t gpio0_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO1_IOSEL 16'h0188 */
	union {
		uint32_t gpio1_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO2_IOSEL 16'h018C */
	union {
		uint32_t gpio2_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO3_IOSEL 16'h0190 */
	union {
		uint32_t gpio3_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio3_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO4_IOSEL 16'h0194 */
	union {
		uint32_t gpio4_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio4_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO5_IOSEL 16'h0198 */
	union {
		uint32_t gpio5_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio5_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO10_IOSEL 16'h019C */
	union {
		uint32_t gpio10_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio10_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO11_IOSEL 16'h01A0 */
	union {
		uint32_t gpio11_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio11_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO12_IOSEL 16'h01A4 */
	union {
		uint32_t gpio12_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio12_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO13_IOSEL 16'h01A8 */
	union {
		uint32_t gpio13_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio13_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO14_IOSEL 16'h01AC */
	union {
		uint32_t gpio14_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio14_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO15_IOSEL 16'h01B0 */
	union {
		uint32_t gpio15_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio15_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO16_IOSEL 16'h01B4 */
	union {
		uint32_t gpio16_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio16_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO17_IOSEL 16'h01B8 */
	union {
		uint32_t gpio17_iosel; // word name
		struct {
			uint32_t pad_fpga_gpio17_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D3_IOSEL 16'h01BC */
	union {
		uint32_t qspi_d3_iosel; // word name
		struct {
			uint32_t pad_qspi_d3_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D2_IOSEL 16'h01C0 */
	union {
		uint32_t qspi_d2_iosel; // word name
		struct {
			uint32_t pad_qspi_d2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D1_IOSEL 16'h01C4 */
	union {
		uint32_t qspi_d1_iosel; // word name
		struct {
			uint32_t pad_qspi_d1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D0_IOSEL 16'h01C8 */
	union {
		uint32_t qspi_d0_iosel; // word name
		struct {
			uint32_t pad_qspi_d0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_CK_IOSEL 16'h01CC */
	union {
		uint32_t qspi_ck_iosel; // word name
		struct {
			uint32_t pad_qspi_ck_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD0_D3_IOSEL 16'h01D0 */
	union {
		uint32_t sd0_d3_iosel; // word name
		struct {
			uint32_t pad_sd0_d3_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD0_D2_IOSEL 16'h01D4 */
	union {
		uint32_t sd0_d2_iosel; // word name
		struct {
			uint32_t pad_sd0_d2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART0_TXD_IOSEL 16'h01D8 */
	union {
		uint32_t uart0_txd_iosel; // word name
		struct {
			uint32_t pad_uart0_txd_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART0_RXD_IOSEL 16'h01DC */
	union {
		uint32_t uart0_rxd_iosel; // word name
		struct {
			uint32_t pad_uart0_rxd_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART0_RTS_IOSEL 16'h01E0 */
	union {
		uint32_t uart0_rts_iosel; // word name
		struct {
			uint32_t pad_uart0_rts_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART0_CTS_IOSEL 16'h01E4 */
	union {
		uint32_t uart0_cts_iosel; // word name
		struct {
			uint32_t pad_uart0_cts_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankFpga_cfg;

#endif