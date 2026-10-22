#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/clk.h>
#include <linux/clk-provider.h>
#include <linux/clkdev.h>
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/spinlock.h>
#include "clk.h"

//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)                                                       \
	do {                                                                    \
		printk("[CLK_TEST] (%d, %s) " fmt, __LINE__, __func__, ##args); \
	} while (0)
#endif

struct augentix_clk_desc {
	const char *name;
	const char *parent;
	uint32_t offset;
	uint8_t bit;
};

/*
 * hw: clk_hw for mux/rate clock
 * gate: clk_gate for gate-type clock
 */
struct augentix_clk_drvdata {
	void __iomem *base;
	struct clk_hw hw;
	spinlock_t lock;

	struct clk **clks;
	struct clk_onecell_data onecell;
	struct augentix_clk_desc *descs;

	const char *name;
	u32 disp_div;
	u32 pwm2_sel;
	u32 pwm3_sel;
};

#define MAX_CLK_NUM 53
#define DIV_SHIFT 0x98
#define PWM2_SEL_SHIFT 0x90
#define PWM3_SEL_SHIFT 0x94
#define DISP_CLK_ID 29
#define PWM2_CLK_ID 46
#define PWM3_CLK_ID 47

#define CKG_DDR 0xC
#define CKG_AXI_DRAMC 0x10
#define CKG_DMA 0x14
#define CKG_APB_SPI 0x18
#define CKG_APB_UART03 0x1C
#define CKG_APB_UART45 0x20
#define CKG_APB_SDC 0x24
#define CKG_APB_EMAC 0x28
#define CKG_AXI_ROM 0x2C
#define CKG_AXI_RAM 0x30
#define CKG_AHB0 0x34
#define CKG_AHB1 0x38
#define CKG_EMAC 0x3C
#define CKG_QSPI 0x40
#define CKG_ISP 0x44
#define CKG_SNSR 0x48
#define CKG_IS 0x4C
#define CKG_DISP 0x50
#define CKG_SDC 0x54
#define CKG_ENC 0x58
#define CKG_EIRQ 0x5C
#define CKG_EFUSE 0x60
#define CKG_ISLP 0x64
#define CKG_I2CM 0x68
#define CKG_SPI 0x6C
#define CKG_TIMER 0x70
#define CKG_PWM0 0x74
#define CKG_PWM1 0x78
#define CKG_ADO 0x7C
#define CKG_USB 0x80

// clang-format off
static struct augentix_clk_desc agtx_clk_desc[MAX_CLK_NUM] = {
	{"clk_dramc",  "ddr_pll_dclk0",  CKG_DDR,  0},
	{"clk_dramc_hdr", "ddr_pll_dclk0_div2", CKG_DDR, 8},
	{"clk_axi_dramc", "ddr_pll_dclk4", CKG_AXI_DRAMC, 0},
	{"clk_dma", "ddr_pll_dclk4_div4", CKG_DMA, 0},
	{"clk_apb_spi0", "cpu_pll_dclk0_div4", CKG_APB_SPI, 0},
	{"clk_apb_spi1", "cpu_pll_dclk0_div4", CKG_APB_SPI, 8},
	{"clk_apb_uart0", "cpu_pll_dclk0_div4", CKG_APB_UART03, 0},
	{"clk_apb_uart1", "cpu_pll_dclk0_div4", CKG_APB_UART03, 8},
	{"clk_apb_uart2", "cpu_pll_dclk0_div4", CKG_APB_UART03, 16},
	{"clk_apb_uart3", "cpu_pll_dclk0_div4", CKG_APB_UART03, 24},
	{"clk_apb_uart4", "cpu_pll_dclk0_div4", CKG_APB_UART45, 0},
	{"clk_apb_uart5", "cpu_pll_dclk0_div4", CKG_APB_UART45, 8},
	{"clk_apb_sdc0", "emac_pll_dclk3", CKG_APB_SDC, 0},
	{"clk_apb_sdc1", "emac_pll_dclk3", CKG_APB_SDC, 8},
	{"clk_apb_emac", "emac_pll_dclk3", CKG_APB_EMAC, 0},
	{"clk_axi_rom", "cpu_pll_dclk0_div4", CKG_AXI_ROM, 0},
	{"clk_axi_ram", "cpu_pll_dclk0_div4", CKG_AXI_RAM, 0},
	{"clk_ahb_master", "cpu_pll_dclk0_div4", CKG_AHB0, 0},
	{"clk_ahb_usb", "cpu_pll_dclk0_div4", CKG_AHB0, 8},
	{"clk_ahb_sdc_0", "cpu_pll_dclk0_div4", CKG_AHB1, 0},
	{"clk_ahb_sdc_1", "cpu_pll_dclk0_div4", CKG_AHB1, 8},
	{"clk_emac_rgmii", "emac_pll_dclk3", CKG_EMAC, 0},
	{"clk_emac_rmii", "emac_pll_dclk3_div5", CKG_EMAC, 8},
	{"clk_qspi", "emac_pll_dclk4", CKG_QSPI, 0},
	{"clk_isp", "emac_pll_dclk5", CKG_ISP, 0},
	{"clk_vp", "emac_pll_dclk5", CKG_ISP, 8},
	{"clk_sensor", "sensor_pll_dclk3", CKG_SNSR, 0},
	{"clk_senif", "sensor_pll_dclk5", CKG_SNSR, 8},
	{"clk_is", "sensor_pll_dclk4", CKG_IS, 8},
	{"clk_disp", "sensor_pll_dclk4", CKG_DISP, 0},
	{"clk_sdc_0", "venc_pll_dclk3", CKG_SDC, 0},
	{"clk_sdc_1", "venc_pll_dclk4", CKG_SDC, 8},
	{"clk_enc", "venc_pll_dclk5", CKG_ENC, 0},
	{"clk_efuse", "sys_clk", CKG_EFUSE, 0},
	{"clk_eirq", "sys_clk", CKG_EIRQ, 0},
	{"clk_is_lp", "sys_clk", CKG_ISLP, 0},
	{"clk_i2cm0", "sys_clk", CKG_I2CM, 0},
	{"clk_i2cm1", "sys_clk", CKG_I2CM, 8},
	{"clk_spi0", "sys_clk", CKG_SPI, 0},
	{"clk_spi1", "sys_clk", CKG_SPI, 8},
	{"clk_timer0", "sys_clk", CKG_TIMER, 0},
	{"clk_timer1", "sys_clk", CKG_TIMER, 8},
	{"clk_timer2", "sys_clk", CKG_TIMER, 16},
	{"clk_timer3", "sys_clk", CKG_TIMER, 24},
	{"clk_pwm_0", "sys_clk", CKG_PWM0, 0},
	{"clk_pwm_1", "sys_clk", CKG_PWM0, 8},
	{"clk_pwm_2", "audio_pll_dclk3", CKG_PWM0, 16},
	{"clk_pwm_3", "audio_pll_dclk3", CKG_PWM0, 24},
	{"clk_pwm_4", "sys_clk", CKG_PWM1, 0},
	{"clk_pwm_5", "sys_clk", CKG_PWM1, 8},
	{"clk_audio_in", "audio_pll_dclk4", CKG_ADO, 0},
	{"clk_audio_out", "audio_pll_dclk5", CKG_ADO, 8},
	{"clk_usb_utmi", "usbphy_clk", CKG_USB, 8},
};
// clang-format on

static int __init augentix_clocks_init(struct augentix_clk_drvdata *clkdata)
{
	struct clk **clks = clkdata->clks;
	struct augentix_clk_desc *descs = clkdata->descs;
	struct clk_gate gate = { .lock = &clkdata->lock };
	const char *parent;
	const char *name;
	int i;

	for (i = 0; i < MAX_CLK_NUM; i++) {
		/* gate clock */
		gate.reg = clkdata->base + descs[i].offset;
		gate.bit_idx = descs[i].bit;
		parent = descs[i].parent;
		name = descs[i].name;

		if (i == DISP_CLK_ID && clkdata->disp_div == 2) {
			parent = "sensor_pll_dclk4_div2";
		} else if (i == DISP_CLK_ID && clkdata->disp_div == 4) {
			parent = "sensor_pll_dclk4_div4";
		} else if ((i == PWM2_CLK_ID && !clkdata->pwm2_sel) || (i == PWM3_CLK_ID && !clkdata->pwm3_sel)) {
			parent = "sys_clk";
		}
		clks[i] = clk_register_gate(NULL, name, parent, 0, gate.reg, gate.bit_idx, 0, gate.lock);
		if (IS_ERR(clks[i])) {
			pr_err("Error: Failed to register clk[%d]: %s!\n", i, name);
			return -ENODEV;
		}

		clk_register_clkdev(clks[i], name, NULL);
	}
	return 0;
}

static void __init augentix_clkctrl_init(struct device_node *np)
{
	struct augentix_clk_drvdata *clkdata;
	int ret;

	/* clkdata content initialization */
	clkdata = kzalloc(sizeof(*clkdata), GFP_KERNEL);
	if (!clkdata) {
		pr_err("Error: Failed to alloc clkdata!\n");
		return;
	}

	spin_lock_init(&clkdata->lock);

	clkdata->base = of_iomap(np, 0);
	if (!clkdata->base) {
		pr_err("Error: Failed to iomap!\n");
		goto err_clkdata_free;
	}

	clkdata->descs = agtx_clk_desc;
	clkdata->name = np->name;
	clkdata->clks = kzalloc(MAX_CLK_NUM * sizeof(*clkdata->clks), GFP_KERNEL);
	if (!clkdata->clks) {
		pr_err("Error: Failed to iomap!\n");
		goto err_iounmap;
	}

	/* set disp divider */
	ret = of_property_read_u32(np, "disp-div", &clkdata->disp_div);
	if (ret) {
		pr_warn("DISP divider not defined!\n");
		clkdata->disp_div = 0;
	}
	writel(clkdata->disp_div, clkdata->base + DIV_SHIFT);

	/* set pwm selector */
	ret = of_property_read_u32(np, "pwm2-sel", &clkdata->pwm2_sel);
	if (ret) {
		pr_warn("PWM2 selector not defined!\n");
		clkdata->pwm2_sel = 0;
	}
	writel(clkdata->pwm2_sel, clkdata->base + PWM2_SEL_SHIFT);

	ret = of_property_read_u32(np, "pwm3-sel", &clkdata->pwm3_sel);
	if (ret) {
		pr_warn("PWM3 selector not defined!\n");
		clkdata->pwm3_sel = 0;
	}
	writel(clkdata->pwm3_sel, clkdata->base + PWM3_SEL_SHIFT);

	ret = augentix_clocks_init(clkdata);
	if (ret) {
		pr_err("Error: Failed to initialize clks!\n");
		return;
	}

	clkdata->onecell.clks = clkdata->clks;
	clkdata->onecell.clk_num = MAX_CLK_NUM;

	of_clk_add_provider(np, of_clk_src_onecell_get, &clkdata->onecell);

	printk("CLK: clk add provider finish\n");

	return;

err_iounmap:
	iounmap(clkdata->base);

err_clkdata_free:
	kfree(clkdata);

	return;
}
CLK_OF_DECLARE(augentix_clkctrl, "augentix-clkctrl", augentix_clkctrl_init);

/* HC1703_1723_1753_1783S generic PLL receives one input clock (sys_clk), and outputs several clocks */
static void __init augentix_pll_init(struct device_node *np)
{
	void __iomem *base;
	const char *parent, *clk_name;
	const char **output_names;
	u32 *freq;
	struct clk_onecell_data *onecell;
	int i;
	int pll_out_num;

	base = of_iomap(np, 0);
	WARN_ON(!base);

	/* get clk node name from device node */
	clk_name = np->name;
#ifdef DEBUG
	pr_info("Augentix PLL: %s\n", clk_name);
#endif

	pll_out_num = of_property_count_u32_elems(np, "clock-frequency");

	/* get parent node name from device node */
	parent = of_clk_get_parent_name(np, 0);
	WARN_ON(!parent);

	output_names = kzalloc(pll_out_num * sizeof(*output_names), GFP_KERNEL);
	WARN_ON(!output_names);

	onecell = kzalloc(sizeof(onecell), GFP_KERNEL);
	WARN_ON(!onecell);

	onecell->clk_num = pll_out_num;
	onecell->clks = kzalloc(pll_out_num * sizeof(*onecell->clks), GFP_KERNEL);
	WARN_ON(!onecell->clks);

	freq = kzalloc(pll_out_num * sizeof(*freq), GFP_KERNEL);
	WARN_ON(!freq);

	/* get output clock names and frequency from device tree */
	of_property_read_u32_array(np, "clock-frequency", freq, pll_out_num);
	for (i = 0; i < pll_out_num; i++) {
		of_property_read_string_index(np, "clock-output-names", i, &output_names[i]);
#ifdef DEBUG
		pr_info(" - output clk %2d: %10s,\tfreq: %10d\n", i, output_names[i], freq[i]);
#endif
		/* setup and register output clocks */
		onecell->clks[i] = clk_register_fixed_rate(NULL, output_names[i], parent, 0, freq[i]);
	}

	/* clock lookup registration */
	for (i = 0; i < pll_out_num; i++) {
		WARN_ON(IS_ERR(onecell->clks[i]));
		clk_register_clkdev(onecell->clks[i], output_names[i], NULL);
	}

	of_clk_add_provider(np, of_clk_src_onecell_get, onecell);
}
CLK_OF_DECLARE(augentix_pll, "augentix-pll", augentix_pll_init);

MODULE_AUTHOR("Louis Yang, Augentix <louis.yang@augentix.com>");
MODULE_DESCRIPTION("Augentix clock driver");
MODULE_LICENSE("GPL");
