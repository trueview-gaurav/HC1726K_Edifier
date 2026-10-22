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

#if defined(CONFIG_OSAKA)
#include "osaka-clk-enum.h"
#else
#include "sapporo-clk-enum.h"
#endif

//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)                \
	do {                             \
		printk(" " fmt, ##args); \
	} while (0)
#else
#define DBG(fmt, args...)
#endif

/* clang-format off */
#if defined(CONFIG_OSAKA)
#define MAX_CLK_NUM 39
#define GAT_AXI_DRAM_OFS	0x08
#define GAT_EIRQ_OFS		0x14
#define GAT_TIMER_OFS		0x1C
#define GAT_TRNG_OFS		0x20
#define GAT_I2CM_OFS		0x24
#define GAT_SPI_OFS		0x28
#define GAT_PWM_OFS		0x2C
#define GAT_UART_OFS		0x30
#define GAT_QSPI_OFS		0x34
#define GAT_SDC_OFS		0x38
#define GAT_EMAC_OFS		0x3C
#define GAT_USB_OFS		0x40
#define GAT_SEN_OFS		0x44
#define GAT_ADO_OFS		0x4C

#define MUX_AXI_DRAM_OFS	0x58
#define MUX_AHB_USB_OFS		0x70
#define MUX_PWM_0_3_OFS		0x74
#define MUX_PWM_4_6_OFS		0x78
#define MUX_UART_0_1_OFS	0x8C
#define MUX_UART_2_OFS		0x90
#define MUX_QSPI_OFS		0xA0
#define MUX_SDC0_OFS		0xA4
#define MUX_SDC1_OFS		0xA8
#define MUX_EMAC_OFS		0xAC
#define MUX_USB_OFS		0xB4
#define MUX_SEN_OFS		0xB8
#define MUX_ADO_IN_OFS		0xC0
#define MUX_ADO_OUT_OFS		0xC4
#define MUX_SAADC_OFS		0xC8
#define MUX_USB_FM_OFS		0xD4
#define MUX_SPI_OFS		0xE0
#define MUX_SPI_SLAVE_OFS	0xEC

#define DIV_AHB_USB_OFS		0x70
#define DIV_PWM_0_3_OFS		0x74
#define DIV_PWM_4_6_OFS		0x78
#define DIV_UART_0_1_OFS	0x8C
#define DIV_UART_2_OFS		0x90
#define DIV_QSPI_OFS		0xA0
#define DIV_SDC0_OFS		0xA4
#define DIV_SDC1_OFS		0xA8
#define DIV_EMAC_OFS		0xAC
#define DIV_SEN_OFS		0xB8
#define DIV_ADO_IN_OFS		0xC0
#define DIV_ADO_OUT_OFS		0xC4
#define DIV_SAADC_OFS		0xC8
#define DIV_SPI_OFS		0xE0
#define DIV_SPI_SLAVE_OFS	0xEC
#define DIV_ADO_DMIC_OFS	0xF8

#else //SAPPORO

#define MAX_CLK_NUM 43
#define GAT_AXI_DRAM_OFS	0x08
#define GAT_EIRQ_OFS		0x14
#define GAT_TIMER_OFS		0x18
#define GAT_TRNG_OFS		0x1C
#define GAT_I2CM_OFS		0x20
#define GAT_SPI_OFS		0x24
#define GAT_PWM_OFS		0x28
#define GAT_UART_OFS		0x2C
#define GAT_QSPI_OFS		0x30
#define GAT_SDC_OFS		0x34
#define GAT_EMAC_OFS		0x38
#define GAT_USB_OFS		0x3C
#define GAT_SEN_OFS		0x40
#define GAT_IS_OFS		0x48
#define GAT_ISP_VP_OFS		0x4C
#define GAT_ENC_OFS		0x50
#define GAT_ADO_OFS		0x54
#define GAT_FM_OFS		0x58

#define MUX_AXI_DRAM_OFS	0x60
#define MUX_AHB_USB_OFS		0x74
#define MUX_PWM_0_3_OFS		0x7C
#define MUX_PWM_4_6_OFS		0x80
#define MUX_UART_0_1_OFS	0x8C
#define MUX_UART_2_OFS		0x90
#define MUX_QSPI_OFS		0x94
#define MUX_SDC0_OFS		0x98
#define MUX_SDC1_OFS		0x9C
#define MUX_EMAC_OFS		0xA0
#define MUX_USB_OFS		0xA4
#define MUX_SEN_OFS		0xA8
#define MUX_IS_OFS		0xB0
#define MUX_ISP_VP_OFS		0xB4
#define MUX_VENC_OFS		0xB8
#define MUX_ADO_IN_OFS		0xBC
#define MUX_ADO_OUT_OFS		0xC0
#define MUX_SAADC_OFS		0xC4
#define MUX_SPI_OFS		0xDC
#define MUX_SPI_SLAVE_OFS	0xE0

#define DIV_AHB_USB_OFS		0x78
#define DIV_PWM_0_3_OFS		0x84
#define DIV_PWM_4_6_OFS		0x88
#define DIV_UART_0_1_OFS	0x8C
#define DIV_UART_2_OFS		0x90
#define DIV_QSPI_OFS		0x94
#define DIV_SDC0_OFS		0x98
#define DIV_SDC1_OFS		0x9C
#define DIV_EMAC_OFS		0xA0
#define DIV_SEN_OFS		0xA8
#define DIV_IS_OFS		0xB0
#define DIV_ISP_VP_OFS		0xB4
#define DIV_VENC_OFS		0xB8
#define DIV_ADO_IN_OFS		0xBC
#define DIV_ADO_OUT_OFS		0xC0
#define DIV_SAADC_OFS		0xC4
#define DIV_SPI_OFS		0xDC
#define DIV_SPI_SLAVE_OFS	0xE0
#define DIV_ADO_DMIC_OFS	0xEC
#endif /* CONFIG_OSAKA */

/* Clock attribute which doesn't exist */
#define GAT_NULL_OFS		0xFFFF
#define MUX_NULL_OFS		0xFFFF
#define DIV_NULL_OFS		0xFFFF

struct augentix_clk_desc {
	int index;
	const char *clk_name;
	const char **parent_names;
	int num_parents;
	uint32_t  mux_offset;
	uint8_t  mux_shift;
	uint32_t  mux_mask;
	uint32_t gate_offset;
	uint8_t gate_bit;
	uint32_t div_offset;
	uint8_t div_shift;
	uint8_t div_width;
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
};

static const char *pname0[] = { "sys_clk", "ddr_pll_dclk3" };
static const char *pname1[] = { "sys_clk" };
static const char *pname2[] = {"sys_clk", "cpu_pll_dclk3", "sys_clk", "sys_clk", "cpu_pll_dclk6", "cpu_pll_dclk4"};
static const char *pname3[] = {"sys_clk", "cpu_pll_dclk6", "sen_pll_dclk4", "cas_pll_dclk3"};
static const char *pname4[] = {"sys_clk", "cas_pll_dclk3", "cpu_pll_dclk6" };
static const char *pname5[] = {"sys_clk", "cpu_pll_dclk3", "cpu_pll_dclk4", "cpu_pll_dclk6"};
static const char *pname6[] = {"sys_clk", "cpu_pll_dclk6"};
static const char *pname7[] = {"sys_clk", "cas_pll_dclk6"};
static const char *pname8[] = {"cpu_pll_dclk3"};
static const char *pname9[] = {"emac_phy_rx_clk"};
static const char *pname10[] = {"sys_clk", "cpu_pll_dclk3"};
static const char *pname11[] = {"sys_clk", "usbphy_clk"};
static const char *pname12[] = {"sys_clk", "sen_pll_dclk3"};
static const char *pname13[] = {"sys_clk", "sen_pll_dclk5", "sys_clk", "cpu_pll_dclk4"};
#if !defined(CONFIG_OSAKA)
static const char *pname14[] = {"sys_clk", "sen_pll_dclk4"};
static const char *pname15[] = {"sys_clk", "cpu_pll_dclk3", "sys_clk", "cpu_pll_dclk6"};
#endif
static const char *pname16[] = {"sys_clk", "ado_pll_dclk3", "ado_pll_dclk4", "ado_pll_dclk5", "ado_pll_dclk6"};
static const char *pname17[] = {"clk_ado_in"};
static const char *pname18[] = {"clk_ado_out"};

#define CLK_MASK(x) ((1 << x) - 1)
static struct augentix_clk_desc agtx_clk_desc[] = {
       /*  clk_name,		parent_names,	       num_par,   mux_offset, mux_shift, mux_mask, gate_offset,  gate_bit, div_offset,  	  div_shift,  div_len */
	{CLK_AXI_DRAMC,	 "clk_axi_dram", pname0	, 2,	MUX_AXI_DRAM_OFS, 0, CLK_MASK(1),	GAT_AXI_DRAM_OFS, 0,	DIV_NULL_OFS,		0,	0},
	{CLK_EIRQ,     	 "clk_eirq",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_EIRQ_OFS,	  1,	DIV_NULL_OFS,		0,	0},
	{CLK_TIMER0,   	 "clk_timer0",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_TIMER_OFS,	  0,	DIV_NULL_OFS,		0,	0},
	{CLK_TIMER1,   	 "clk_timer1",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_TIMER_OFS,	  1,	DIV_NULL_OFS,		0,	0},
	{CLK_TIMER2,   	 "clk_timer2",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_TIMER_OFS,	  2,	DIV_NULL_OFS,		0,	0},
	{CLK_TIMER3,   	 "clk_timer3",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_TIMER_OFS,	  3,	DIV_NULL_OFS,		0,	0},
	{CLK_TRNG,     	 "clk_trng",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_TRNG_OFS,	  0,	DIV_NULL_OFS,		0,	0},
	{CLK_I2CM0,    	 "clk_i2cm0",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_I2CM_OFS,	  0,	DIV_NULL_OFS,		0,	0},
	{CLK_I2CM1,    	 "clk_i2cm1",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_I2CM_OFS,	  1,	DIV_NULL_OFS,		0,	0},
	{CLK_I2CM2,    	 "clk_i2cm2",	pname1,	 1,	MUX_NULL_OFS, 0, 	0,		GAT_I2CM_OFS,	  2,	DIV_NULL_OFS,		0,	0},
	{CLK_SPI0,     	 "clk_spi0",	pname2,	 6,	MUX_SPI_OFS, 0,	   CLK_MASK(3),		GAT_SPI_OFS,	  0,	DIV_SPI_OFS,		8,	4},
	{CLK_SPI1,     	 "clk_spi1",	pname2,	 6,	MUX_SPI_OFS, 16,   CLK_MASK(3),		GAT_SPI_OFS,	  1,	DIV_SPI_OFS,		24,	4},
	{CLK_SPI_SLAVE,	 "clk_spi_slave",pname2, 6,	MUX_SPI_SLAVE_OFS, 0, CLK_MASK(3),	GAT_SPI_OFS,	  2,	DIV_SPI_SLAVE_OFS,	8,	4},
	{CLK_PWM0,     	 "clk_pwm0",	pname3,	 4,	MUX_PWM_0_3_OFS, 0,   CLK_MASK(2),	GAT_PWM_OFS,	  0,	DIV_PWM_0_3_OFS,	0,	4},
	{CLK_PWM1,     	 "clk_pwm1",	pname3,	 4,	MUX_PWM_0_3_OFS, 8,   CLK_MASK(2),	GAT_PWM_OFS,	  1,	DIV_PWM_0_3_OFS,	8,	4},
	{CLK_PWM2,     	 "clk_pwm2",	pname3,	 4,	MUX_PWM_0_3_OFS, 16,   CLK_MASK(2),	GAT_PWM_OFS,	  2,	DIV_PWM_0_3_OFS,	16,	4},
	{CLK_PWM3,     	 "clk_pwm3",	pname3,	 4,	MUX_PWM_0_3_OFS, 24,   CLK_MASK(2),	GAT_PWM_OFS,	  3,	DIV_PWM_0_3_OFS,	24,	4},
	{CLK_PWM4,     	 "clk_pwm4",	pname3,	 4,	MUX_PWM_4_6_OFS, 0,   CLK_MASK(2),	GAT_PWM_OFS,	  4,	DIV_PWM_4_6_OFS,	0,	4},
	{CLK_PWM5,     	 "clk_pwm5",	pname3,	 4,	MUX_PWM_4_6_OFS, 8,   CLK_MASK(2),	GAT_PWM_OFS,	  5,	DIV_PWM_4_6_OFS,	8,	4},
	{CLK_PWM6,     	 "clk_pwm6",	pname3,	 4,	MUX_PWM_4_6_OFS, 16,   CLK_MASK(2),	GAT_PWM_OFS,	  6,	DIV_PWM_4_6_OFS,	16,	4},
	{CLK_UART0,    	 "clk_uart0",	pname4,	 3,	MUX_UART_0_1_OFS, 0,   CLK_MASK(2),	GAT_UART_OFS,	  0,	DIV_UART_0_1_OFS,	8,	4},
	{CLK_UART1,    	 "clk_uart1",	pname4,	 3,	MUX_UART_0_1_OFS, 16,  CLK_MASK(2),	GAT_UART_OFS,	  1,	DIV_UART_0_1_OFS,	24,	4},
	{CLK_UART2,    	 "clk_uart2",	pname4,	 3,	MUX_UART_2_OFS, 0,   CLK_MASK(2),	GAT_UART_OFS,	  2,	DIV_UART_2_OFS,		8,	4},
	{CLK_QSPI,     	 "clk_qspi",	pname5,	 4,	MUX_QSPI_OFS, 0,   CLK_MASK(3),		GAT_QSPI_OFS,	  0,	DIV_QSPI_OFS,		8,	4},
	{CLK_SDC0,     	 "clk_sdc0",	pname6,	 2,	MUX_SDC0_OFS, 0,   CLK_MASK(1),		GAT_SDC_OFS,	  0,	DIV_SDC0_OFS,		8,	4},
	{CLK_SDC1,     	 "clk_sdc1",	pname6,	 2,	MUX_SDC1_OFS, 0,  CLK_MASK(1),		GAT_SDC_OFS,	  8,	DIV_SDC1_OFS,		8,	4},
	{CLK_ETH,      	 "clk_eth",	pname7,	 2,	MUX_EMAC_OFS, 0,   CLK_MASK(1),		GAT_EMAC_OFS,	  0,	DIV_EMAC_OFS,		8,	9},
	{APB_PCLK,     	 "apb_pclk",	pname8,	 1,	MUX_NULL_OFS, 0,	0,		GAT_NULL_OFS,	  0,	DIV_NULL_OFS,		0,	0},
	{EMAC_RX_CLK,  	 "emac_rx_clk",	pname9, 1,	MUX_NULL_OFS, 0,	0,		GAT_NULL_OFS,	  0,	DIV_EMAC_OFS,		24,	5},
	{CLK_AHB_USB,  	 "clk_ahb_usb",	pname10, 2,	MUX_AHB_USB_OFS, 0, CLK_MASK(1),	GAT_USB_OFS,	  0,	DIV_AHB_USB_OFS,	0,	3},
	{CLK_USB_UTMI, 	 "clk_usb_utmi",pname11, 2,	MUX_USB_OFS, 0,	   CLK_MASK(1),		GAT_USB_OFS,	  8,	DIV_NULL_OFS,		0,	0},
	{CLK_SENSOR,   	 "clk_sensor",	pname12, 2,	MUX_SEN_OFS, 0,	   CLK_MASK(1),		GAT_SEN_OFS,	  0,	DIV_SEN_OFS,		8,	2},
	{CLK_SENIF,    	 "clk_senif",	pname13, 4,	MUX_SEN_OFS, 16,   CLK_MASK(3),		GAT_SEN_OFS,	  1,	DIV_SEN_OFS,		24,	2},
#if !defined(CONFIG_OSAKA)
	{CLK_IS,       	 "clk_is",	pname14, 2,	MUX_IS_OFS, 0,	   CLK_MASK(3),		GAT_IS_OFS,	  0,	DIV_IS_OFS,		8,	3},
	{CLK_ISP,      	 "clk_isp",	pname15, 4,	MUX_ISP_VP_OFS, 0, CLK_MASK(3),		GAT_ISP_VP_OFS,	  0,	DIV_ISP_VP_OFS,		8,	3},
	{CLK_VP,       	 "clk_vp",	pname15, 4,	MUX_ISP_VP_OFS, 16, CLK_MASK(3),	GAT_ISP_VP_OFS,	  1,	DIV_ISP_VP_OFS,		24,	3},
	{CLK_ENC,      	 "clk_enc",	pname15, 4,	MUX_VENC_OFS, 0,   CLK_MASK(3),		GAT_ENC_OFS,	  0,	DIV_VENC_OFS,		8,	3},
#endif
	{CLK_ADO_IN,   	 "clk_ado_in",	pname16, 5,	MUX_ADO_IN_OFS, 0, CLK_MASK(3),		GAT_ADO_OFS,	  0,	DIV_ADO_IN_OFS,		8,	2},
	{CLK_ADO_ADC,  	 "clk_ado_adc",	pname17, 1,	MUX_NULL_OFS, 0,	0,		GAT_ADO_OFS,	  1,	DIV_ADO_IN_OFS,		16,	4},
	{CLK_ADO_DMIC, 	 "clk_ado_dmic",pname17, 1,	MUX_NULL_OFS, 0,	0,		GAT_ADO_OFS,	  2,	DIV_ADO_DMIC_OFS,	0,	10},
	{CLK_ADO_OUT,  	 "clk_ado_out",	pname16, 5,	MUX_ADO_OUT_OFS, 0, CLK_MASK(3),	GAT_ADO_OFS,	  3,	DIV_ADO_OUT_OFS,	8,	2},
	{CLK_ADO_DAC,   "clk_ado_dac",	pname18, 1,	MUX_NULL_OFS, 0,	0,		GAT_ADO_OFS,	  4,	DIV_ADO_OUT_OFS,	16,	4},
	{CLK_SAADC,     "clk_saadc",	pname6,	 2,	MUX_SAADC_OFS, 0,   CLK_MASK(1),	GAT_ADO_OFS,	  5,	DIV_SAADC_OFS,		8,	1},
};
// clang-format on
#define to_clk_divider(_hw) container_of(_hw, struct clk_divider, hw)
#define div_mask(d) ((1 << ((d)->width)) - 1)

static unsigned long augentix_clk_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
	struct clk_divider *divider = to_clk_divider(hw);
	unsigned int div, val;

	val = readl(divider->reg) >> divider->shift;
	val &= div_mask(divider);

	if (val == 0) {
		div = 1;
	} else {
		div = val << 1;
	}

	return DIV_ROUND_UP(parent_rate, div);
}

static long augentix_clk_round_rate(struct clk_hw *hw, unsigned long rate, unsigned long *prate)
{
	struct clk_divider *divider = to_clk_divider(hw);
	unsigned long bestdiv, maxdiv;

	if (!rate)
		rate = 1;

	maxdiv = div_mask(divider) << 1;

	bestdiv = DIV_ROUND_UP(*prate, rate);
	bestdiv = bestdiv == 0 ? 1 : bestdiv;
	bestdiv = bestdiv > maxdiv ? maxdiv : bestdiv;
	DBG("parent_rate %lu, rate %lu, div %lu\n", *prate, rate, bestdiv);
	return DIV_ROUND_UP(*prate, bestdiv);
}

static int augentix_clk_set_rate(struct clk_hw *hw, unsigned long rate, unsigned long parent_rate)
{
	struct clk_divider *divider = to_clk_divider(hw);
	unsigned int div, value;
	unsigned long flags = 0;
	u32 val;

	div = DIV_ROUND_UP(parent_rate, rate);

	value = (div + 1) >> 1;
	if (value > div_mask(divider))
		value = div_mask(divider);

	spin_lock_irqsave(divider->lock, flags);

	val = readl(divider->reg);
	val &= ~(div_mask(divider) << divider->shift);
	val |= value << divider->shift;
	writel(val, divider->reg);

	spin_unlock_irqrestore(divider->lock, flags);

	return 0;
}

static const struct clk_ops augentix_div_ops = {
	.recalc_rate = augentix_clk_recalc_rate,
	.round_rate = augentix_clk_round_rate,
	.set_rate = augentix_clk_set_rate,
};

static struct clk *augentix_clocks_register(void __iomem *base, const char *clk_name, const char **parent_names,
                                            int num_parents, uint32_t mux_offset, uint8_t mux_shift, uint32_t mux_mask,
                                            uint32_t gate_offset, uint8_t gate_bit, uint32_t div_offset,
                                            uint8_t div_shift, uint8_t div_width, spinlock_t *lock)
{
	struct clk *clk;
	const struct clk_ops *gate_ops = NULL, *div_ops = NULL, *mux_ops = NULL;
	struct clk_gate *gate = NULL;
	struct clk_divider *div = NULL;
	struct clk_mux *mux = NULL;

	DBG("clk_name %s, parent %s\n", clk_name, parent_name);
	if (gate_offset != GAT_NULL_OFS) {
		gate = kzalloc(sizeof(*gate), GFP_KERNEL);
		gate->reg = base + gate_offset;
		gate->bit_idx = gate_bit;
		gate->lock = lock;
		gate_ops = &clk_gate_ops;
	}
	if (div_offset != DIV_NULL_OFS) {
		div = kzalloc(sizeof(*div), GFP_KERNEL);
		div->reg = base + div_offset;
		div->shift = div_shift;
		div->width = div_width;
		div->lock = lock;
		div_ops = &augentix_div_ops;
	}
	if (mux_offset != MUX_NULL_OFS) {
		mux = kzalloc(sizeof(*mux), GFP_KERNEL);
		mux->reg = base + mux_offset;
		mux->shift = mux_shift;
		mux->mask = mux_mask;
		mux->lock = lock;
		mux_ops = &clk_mux_ops;
	}
	clk = clk_register_composite(NULL, clk_name, parent_names, num_parents, mux ? &mux->hw : NULL, mux_ops,
	                             div ? &div->hw : NULL, div_ops, gate ? &gate->hw : NULL, gate_ops, 0);
	return clk;
}

static void __init augentix_clkctrl_init(struct device_node *np)
{
	struct augentix_clk_drvdata *clkdata;
	int i;
	struct augentix_clk_desc *d = agtx_clk_desc;

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

	clkdata->descs = d;
	clkdata->name = np->name;
	clkdata->clks = kzalloc(MAX_CLK_NUM * sizeof(*clkdata->clks), GFP_KERNEL);
	if (!clkdata->clks) {
		pr_err("Error: Failed to iomap!\n");
		goto err_iounmap;
	}

	for (i = 0; i < MAX_CLK_NUM; i++) {
		clkdata->clks[i] = augentix_clocks_register(clkdata->base, d[i].clk_name, d[i].parent_names,
		                                            d[i].num_parents, d[i].mux_offset, d[i].mux_shift,
		                                            d[i].mux_mask, d[i].gate_offset, d[i].gate_bit,
		                                            d[i].div_offset, d[i].div_shift, d[i].div_width,
		                                            &clkdata->lock);
		clk_register_clkdev(clkdata->clks[i], d[i].clk_name, NULL);
	}

	clkdata->onecell.clks = clkdata->clks;
	clkdata->onecell.clk_num = MAX_CLK_NUM;

	of_clk_add_provider(np, of_clk_src_onecell_get, &clkdata->onecell);

	pr_info("clk driver init success\n");

	return;

err_iounmap:
	iounmap(clkdata->base);

err_clkdata_free:
	kfree(clkdata);

	return;
}
CLK_OF_DECLARE(augentix_clkctrl, "augentix-clkctrl", augentix_clkctrl_init);

MODULE_AUTHOR("Eddie Lee, Augentix <eddie.lee@augentix.com>");
MODULE_DESCRIPTION("Augentix clock driver V2");
MODULE_LICENSE("GPL");
