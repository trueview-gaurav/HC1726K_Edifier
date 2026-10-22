#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/of.h>
#include <linux/version.h>
#include <linux/pinctrl/pinconf.h>
#include <linux/pinctrl/pinmux.h>
#include <linux/pinctrl/pinconf-generic.h>

//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)                                \
	do {                                             \
		pr_err("[PINCTRL_DRIVER] " fmt, ##args); \
	} while (0)
#else
#define DBG(fmt, args...) \
	do {              \
	} while (0)
#endif

#define PWR_MODE_ADDR 0x80530068
#define PINMUX_OFFS 0x4
#define PINCONF_OFFS 0x4
#define PINCONF_BIAS 16
#define DT_PIN_NAME "augentix,pins"
#define DT_PMX_NAME "augentix,pmx"
#define DRIVER_NAME "augentix_pinctrl"
#define GROUP_NAME_LEN 24

/*
 * struct augentix_pin_group: describes a pin group
 * @name: name of pin group
 * @pins: an array of pins used in this group
 * @npins: total amount of pins in this group
 * @muxsel: optional, used in groups which show mux settings
 */
struct augentix_pin_group {
	const char *name;
	uint32_t *pins;
	unsigned npins;
	uint32_t *muxsel;
};

/*
 * @name: name of function
 * @groups: an array of pin group names in this function
 * @ngroups: total amount of pin groups in this function
 */
struct augentix_pmx_func {
	const char *name;
	const char **groups;
	unsigned ngroups;
};

struct augentix_pctl_drvdata {
	struct device *dev;
	struct pinctrl_dev *pctldev;
	struct pinctrl_desc *pctldesc;
	void __iomem *base;
	spinlock_t lock;

	// dts hierarchy : pinctrl → function → group
	struct augentix_pmx_func *functions; // infor. of all functions
	int nfuncs;
	struct augentix_pin_group *groups; // infor. of all groups
	int ngroups;
};

// clang-format off
const struct pinctrl_pin_desc g_augentix_pins[] = {
	/* PIOC */
	PINCTRL_PIN(0, "PAD_SPI0_SCK"),	PINCTRL_PIN(1, "PAD_SPI0_SDI"),	PINCTRL_PIN(2, "PAD_SPI0_SDO"),
	PINCTRL_PIN(3, "PAD_EIRQ0"), PINCTRL_PIN(4, "PAD_SD_CD"), PINCTRL_PIN(5, "PAD_SD_D2"),
	PINCTRL_PIN(6, "PAD_SD_D3"), PINCTRL_PIN(7, "PAD_SD_CMD"), PINCTRL_PIN(8, "PAD_SD_CK"),
	PINCTRL_PIN(9, "PAD_SD_D0"), PINCTRL_PIN(10, "PAD_SD_D1"), PINCTRL_PIN(11, "PAD_GPIO3"),
	PINCTRL_PIN(12, "PAD_PWM1"), PINCTRL_PIN(13, "PAD_PWM4"), PINCTRL_PIN(14, "PAD_I2C1_SCL"),
	PINCTRL_PIN(15, "PAD_I2C1_SDA"), PINCTRL_PIN(16, "PAD_UART1_TXD"), PINCTRL_PIN(17, "PAD_UART1_RXD"),
	PINCTRL_PIN(18, "PAD_UART2_TXD"), PINCTRL_PIN(19, "PAD_UART2_RXD"), PINCTRL_PIN(20, "PAD_QSPI_CE_N"),
	PINCTRL_PIN(21, "PAD_QSPI_D1"), PINCTRL_PIN(22, "PAD_QSPI_D2"), PINCTRL_PIN(23, "PAD_QSPI_D3"),
	PINCTRL_PIN(24, "PAD_QSPI_CK"), PINCTRL_PIN(25, "PAD_QSPI_D0"), PINCTRL_PIN(26, "PAD_EPHY_RST"),
	PINCTRL_PIN(27, "PAD_EMAC_TX_CK"), PINCTRL_PIN(28, "PAD_EMAC_TX_CTL"), PINCTRL_PIN(29, "PAD_EMAC_TX_D3"),
	PINCTRL_PIN(30, "PAD_EMAC_TX_D2"), PINCTRL_PIN(31, "PAD_EMAC_TX_D1"), PINCTRL_PIN(32, "PAD_EMAC_TX_D0"),
	PINCTRL_PIN(33, "PAD_EMAC_RX_CK"), PINCTRL_PIN(34, "PAD_EMAC_RX_D0"), PINCTRL_PIN(35, "PAD_EMAC_RX_D1"),
	PINCTRL_PIN(36, "PAD_EMAC_RX_D2"), PINCTRL_PIN(37, "PAD_EMAC_RX_D3"), PINCTRL_PIN(38, "PAD_EMAC_RX_CTL"),
	PINCTRL_PIN(39, "PAD_EMAC_MDC"), PINCTRL_PIN(40, "PAD_EMAC_MDIO"), PINCTRL_PIN(41, "PAD_SPI1_SDI"),
	PINCTRL_PIN(42, "PAD_SPI1_SDO"), PINCTRL_PIN(43, "PAD_SPI1_SCK"), PINCTRL_PIN(44, "PAD_GPIO7"),
	PINCTRL_PIN(45, "PAD_I2C0_SDA"), PINCTRL_PIN(46, "PAD_I2C0_SCL"), PINCTRL_PIN(47, "PAD_SENSOR_CLK"),
	PINCTRL_PIN(48, "PAD_PWM2"), PINCTRL_PIN(49, "PAD_SENSOR_RSTB"), PINCTRL_PIN(50, "PAD_SENSOR_PWDN"),
	PINCTRL_PIN(51, "PAD_GPIO4"), PINCTRL_PIN(52, "PAD_GPIO5"), PINCTRL_PIN(53, "PAD_GPIO6"),
	PINCTRL_PIN(54, "PAD_I2S_TX_CK"), PINCTRL_PIN(55, "PAD_I2S_RX_CK"), PINCTRL_PIN(56, "PAD_I2S_RX_SD"),
	PINCTRL_PIN(57, "PAD_I2S_TX_SD"), PINCTRL_PIN(58, "PAD_I2S_RX_WS"), PINCTRL_PIN(59, "PAD_I2S_TX_WS"),
	PINCTRL_PIN(60, "PAD_GPIO2"), PINCTRL_PIN(61, "PAD_UART0_TXD"), PINCTRL_PIN(62, "PAD_UART0_RXD"),
	PINCTRL_PIN(63, "PAD_EIRQ1"), PINCTRL_PIN(64, "PAD_PWM3"), PINCTRL_PIN(65, "PAD_PWM0"),
	PINCTRL_PIN(66, "PAD_GPIO0"), PINCTRL_PIN(67, "PAD_GPIO1"), 
	/* AIOC */
	PINCTRL_PIN(68, "PAD_DVP_0"), PINCTRL_PIN(69, "PAD_DVP_1"), PINCTRL_PIN(70, "PAD_DVP_2"),
	PINCTRL_PIN(71, "PAD_DVP_3"), PINCTRL_PIN(72, "PAD_DVP_4"), PINCTRL_PIN(73, "PAD_DVP_5"),
	PINCTRL_PIN(74, "PAD_DVP_6"), PINCTRL_PIN(75, "PAD_DVP_7"), PINCTRL_PIN(76, "PAD_DVP_8"),
	PINCTRL_PIN(77, "PAD_POWER_CTRL_0"), PINCTRL_PIN(78, "PAD_POWER_CTRL_1"), 
	PINCTRL_PIN(79, "PAD_AO_BUTTON"), PINCTRL_PIN(80, "PAD_AO_WAKEUP"),
};
// clang-format on

/* PART 1: Pinctrl operation */
static int augentix_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);
	return d->ngroups;
}

static const char *augentix_pinctrl_get_group_name(struct pinctrl_dev *pctldev, unsigned selector)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);
	return d->groups[selector].name;
}

static int augentix_pinctrl_get_group_pins(struct pinctrl_dev *pctldev, unsigned selector, const unsigned **pins,
                                           unsigned *num_pins)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);

	*pins = d->groups[selector].pins;
	*num_pins = d->groups[selector].npins;

	return 0;
}

static int augentix_pinctrl_dt_node_to_map(struct pinctrl_dev *pctldev, struct device_node *np_config,
                                           struct pinctrl_map **map, unsigned *num_maps)
{
	return pinconf_generic_dt_node_to_map(pctldev, np_config, map, num_maps, PIN_MAP_TYPE_CONFIGS_PIN);
}

static void augentix_pinctrl_dt_free_map(struct pinctrl_dev *pctldev, struct pinctrl_map *map, unsigned num_maps)
{
	kfree(map);
}

static const struct pinctrl_ops augentix_pinctrl_ops = {
	.get_groups_count = augentix_pinctrl_get_groups_count,
	.get_group_name = augentix_pinctrl_get_group_name,
	.get_group_pins = augentix_pinctrl_get_group_pins,
	.dt_node_to_map = augentix_pinctrl_dt_node_to_map,
	.dt_free_map = augentix_pinctrl_dt_free_map,
};

/* PART 2: Pinmux operation */
static int augentix_get_functions_count(struct pinctrl_dev *pctldev)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);
	return d->nfuncs;
}

static const char *augentix_get_function_name(struct pinctrl_dev *pctldev, unsigned selector)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);
	return d->functions[selector].name;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 2, 0)
static int augentix_get_function_groups(struct pinctrl_dev *pctldev, unsigned selector, const char *const **groups,
                                        unsigned *const num_groups)
#else
static int augentix_get_function_groups(struct pinctrl_dev *pctldev, unsigned selector, const char *const **groups,
                                        unsigned *num_groups)
#endif
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);

	*groups = d->functions[selector].groups;
	*num_groups = d->functions[selector].ngroups;
	return 0;
}

static int get_pinmux_bias(uint32_t pin)
{
	uint32_t bias = 0;

	if (pin >= ARRAY_SIZE(g_augentix_pins))
		return -1;

	if (pin <= 19) {
		// 0 ~ 19 starts from 0x514
		bias = 0x514 + ((pin - 0) * PINMUX_OFFS);
	} else if (pin <= 67) {
		// 20 ~ 67 starts from 0x598
		bias = 0x598 + ((pin - 20) * PINMUX_OFFS);
	} else if (pin <= 76) {
		// 68 ~ 76 starts from 0x44
		bias = 0x44 + ((pin - 68) * PINMUX_OFFS);
	} else if (pin <= 78) {
		// 77 ~ 78 starts from 0x3C
		bias = 0x3C + ((pin - 77) * PINMUX_OFFS);
	} else {
		// 79 ~ 80 starts from 0x68
		bias = 0x68 + ((pin - 79) * PINMUX_OFFS);
	}
	return bias;
}

/* HW workaround, #50970 */
static void set_pwr_button_mode(int value)
{
	void __iomem *mapped_pwr_mode;
	uint32_t reg_val = 0;

	mapped_pwr_mode = ioremap(PWR_MODE_ADDR, 4);
	if (IS_ERR(mapped_pwr_mode)) {
		pr_err("ioremap for power button failed\n");
		return;
	};
	reg_val = readl_relaxed(mapped_pwr_mode);
	reg_val &= ~(1 << 8);
	reg_val |= (value << 8);

	writel(reg_val, mapped_pwr_mode);

	iounmap(mapped_pwr_mode);
}
/* === */

static int augentix_set_mux(struct pinctrl_dev *pctldev, unsigned func_selector, unsigned group_selector)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);
	struct augentix_pin_group *g = &d->groups[group_selector];
	uint32_t mux_bias = 0;
	int i;
	unsigned long flags;

	spin_lock_irqsave(&d->lock, flags);
	for (i = 0; i < g->npins; i++) {
		mux_bias = get_pinmux_bias(g->pins[i]);
		/* If no muxsel or bias, skip the operation */
		if (g->muxsel[i] != 0xFFFFFFFF && mux_bias != -1) {
			/* HW workaround, #50970 */
			if (g->pins[i] == 79) {
				if (g->muxsel[i]) {
					set_pwr_button_mode(0);
				} else {
					set_pwr_button_mode(1);
				}
			}
			/* === */

			writel(g->muxsel[i], d->base + mux_bias);
		}
	}
	spin_unlock_irqrestore(&d->lock, flags);

	return 0;
}

static const struct pinmux_ops augentix_pinmux_ops = {
	.get_functions_count = augentix_get_functions_count,
	.get_function_name = augentix_get_function_name,
	.get_function_groups = augentix_get_function_groups,
	.set_mux = augentix_set_mux,
};

/* PART 3: Pinconf operation */

static int get_pinconf_bias(uint32_t pin)
{
	uint32_t bias = 0;

	if (pin >= ARRAY_SIZE(g_augentix_pins))
		return -1;

	if (pin <= 10) {
		// 0 ~ 10 starts from 0x400
		bias = 0x400 + ((pin - 0) * PINCONF_OFFS);
	} else if (pin <= 67) {
		// 11 ~ 67 starts from 0x430
		bias = 0x430 + ((pin - 11) * PINCONF_OFFS);
	} else if (pin <= 76) {
		// 68 ~ 76 starts from 0x10
		bias = 0x10 + ((pin - 68) * PINCONF_OFFS);
	} else if (pin <= 78) {
		// 77 ~ 78 starts from 0x08
		bias = 0x08 + ((pin - 77) * PINCONF_OFFS);
	} else {
		// 79 ~ 80 starts from 0x34
		bias = 0x34 + ((pin - 79) * PINCONF_OFFS);
	}
	return bias;
}

static int get_drvstr_bit(uint32_t pin)
{
	uint32_t bit = 0;

	if (pin >= ARRAY_SIZE(g_augentix_pins)) {
		return -1;
	} else if ((pin >= 45 && pin <= 50) || (pin >= 68)) {
		// 45~50 & 68~80 drvstr_bit = 2
		bit = 2;
	} else {
		bit = 3;
	}
	return bit;
}

static int augentix_pinconf_set_one(struct augentix_pctl_drvdata *d, u32 pin, enum pin_config_param param, u32 arg)
{
	u32 reg_val;
	int conf_bias = get_pinconf_bias(pin);
	int drvstr_bit = get_drvstr_bit(pin);
	unsigned long flags;

	if (conf_bias < 0)
		return -EINVAL;
	spin_lock_irqsave(&d->lock, flags);
	reg_val = readl_relaxed(d->base + conf_bias);

	switch (param) {
	case PIN_CONFIG_BIAS_PULL_UP:
		reg_val &= ~(3);
		reg_val |= 1;
		break;
	case PIN_CONFIG_BIAS_PULL_DOWN:
		reg_val &= ~(3);
		reg_val |= 2;
		break;
	case PIN_CONFIG_BIAS_DISABLE:
	case PIN_CONFIG_BIAS_PULL_PIN_DEFAULT:
		reg_val &= ~(3);
		break;
	case PIN_CONFIG_DRIVE_STRENGTH:
		//drvstr_bit = 2, mask is 0x3 << drvstr_bias, starts at bit[16]
		reg_val &= ~(((1 << drvstr_bit) - 1) << PINCONF_BIAS);
		reg_val |= (arg << PINCONF_BIAS);
		break;
	case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
		//st_bit = 1, starts at bit[16 + drvstr_bit]
		reg_val &= ~(1 << (PINCONF_BIAS + drvstr_bit));
		if (arg)
			reg_val |= (arg << (PINCONF_BIAS + drvstr_bit));
		break;
	case PIN_CONFIG_SLEW_RATE:
		//sr_bit = 1, starts at bit[16 + drvstr_bit + 1(ST)]
		reg_val &= ~(1 << (PINCONF_BIAS + drvstr_bit + 1));
		if (arg)
			reg_val |= (arg << (PINCONF_BIAS + drvstr_bit + 1));
		break;
	default:
		spin_unlock_irqrestore(&d->lock, flags);
		return -ENOTSUPP;
	}

	writel(reg_val, d->base + conf_bias);
	spin_unlock_irqrestore(&d->lock, flags);

	return 0;
}

static int augentix_pinconf_set(struct pinctrl_dev *pctldev, unsigned pin, unsigned long *configs, unsigned num_configs)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);
	enum pin_config_param param;
	u32 arg;
	int idx, ret;

	for (idx = 0; idx < num_configs; idx++) {
		param = pinconf_to_config_param(configs[idx]);
		arg = pinconf_to_config_argument(configs[idx]);
		DBG("Pin%d [%s] param:%d arg:%d\n", pin, g_augentix_pins[pin].name, param, arg);

		ret = augentix_pinconf_set_one(d, pin, param, arg);
		if (ret)
			return ret;
	}

	return 0;
}

static int augentix_pinconf_group_set(struct pinctrl_dev *pctldev, unsigned group, unsigned long *configs,
                                      unsigned num_configs)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);
	const unsigned int *pins;
	unsigned int i;

	pins = d->groups[group].pins;

	for (i = 0; i < d->groups[group].npins; i++)
		augentix_pinconf_set(pctldev, pins[i], configs, num_configs);

	return 0;
}

static const struct pinconf_ops augentix_pinconf_ops = {
	.pin_config_set = augentix_pinconf_set,
	.pin_config_group_set = augentix_pinconf_group_set,
	.is_generic = true,
};

/* PART 3: Pinctrl driver registration */

/* pinctrl descriptor; to be registered to pinctrl subsystem */
struct pinctrl_desc augentix_pinctrl_desc = {
	.name = DRIVER_NAME,
	.pins = g_augentix_pins,
	.npins = ARRAY_SIZE(g_augentix_pins),
	.owner = THIS_MODULE,
	.pctlops = &augentix_pinctrl_ops,
	.pmxops = &augentix_pinmux_ops,
	.confops = &augentix_pinconf_ops,
};

static int augentix_pinctrl_parse_function(struct augentix_pctl_drvdata *d, struct augentix_pmx_func *f,
                                           struct device_node *child, int idx_g)
{
	struct device *dev = d->dev;
	struct device_node *grand_child;
	char *groups_buf = NULL;
	int ret, n = 0;
	struct augentix_pin_group *g;

	// this buff is for strcpy, "const" type used in strcpy will be a warning
	groups_buf = devm_kzalloc(dev, f->ngroups * GROUP_NAME_LEN * sizeof(char), GFP_KERNEL);
	if (!groups_buf)
		goto no_mem;

	for_each_child_of_node (child, grand_child) {
		// fill members for pinctrl_ops
		g = d->groups + (idx_g + n);

		// assign group name for get_group_name & get_function_name
		strcpy(groups_buf + n * GROUP_NAME_LEN, grand_child->name);
		g->name = f->groups[n] = groups_buf + n * GROUP_NAME_LEN;

		// assign pin index and pin mux for get_group_pins & set_mux
		g->npins = of_property_count_u32_elems(grand_child, DT_PIN_NAME);
		g->pins = devm_kzalloc(dev, g->npins * sizeof(uint32_t), GFP_KERNEL);
		g->muxsel = devm_kzalloc(dev, g->npins * sizeof(uint32_t), GFP_KERNEL);
		if (!g->pins || !g->muxsel)
			goto no_mem;

		// read from dts should be u32, or dts format should add prefix, ex: pmx = /bits/ 8 <0x12>;
		of_property_read_u32_array(grand_child, DT_PIN_NAME, g->pins, g->npins);
		ret = of_property_read_bool(grand_child, DT_PMX_NAME);
		if (ret) {
			of_property_read_u32_array(grand_child, DT_PMX_NAME, g->muxsel, g->npins);
		} else {
			// fill array for group w/o DT_PMX_NAME attribute
			memset(g->muxsel, 0xFFFFFFFF, g->npins * sizeof(uint32_t));
		}
		DBG("groups %s, npins %u\n", f->groups[n], g->npins);
		n++;
#ifdef DEBUG
		for (ret = 0; ret < g->npins; ret++) {
			DBG("pins %u, mux 0x%x\n", g->pins[ret], g->muxsel[ret]);
		}
#endif
	};
	return 0;
no_mem:
	dev_err(dev, "Allocating drvdata member failed\n");
	return -ENOMEM;
}

static int augentix_pinctrl_probe_dt(struct platform_device *pdev, struct augentix_pctl_drvdata *d)
{
	struct device_node *np = pdev->dev.of_node;
	struct device_node *child;
	struct device *dev = &pdev->dev;
	struct augentix_pmx_func *f;
	int idx_f = 0;
	int idx_g = 0;
	int ret;

	child = of_get_next_child(np, NULL);
	if (!child) {
		dev_err(dev, "no group is defined\n");
		return -ENOENT;
	}

	/* Count total functions and groups */
	for_each_child_of_node (np, child) {
		d->nfuncs++;
		d->ngroups += of_get_child_count(child);
	}
	DBG("total nfunction %u, ngroups: %u\n", d->nfuncs, d->ngroups);

	/* Allocate memory for group and functions */
	d->functions = devm_kzalloc(dev, d->nfuncs * sizeof(struct augentix_pmx_func), GFP_KERNEL);
	d->groups = devm_kzalloc(dev, d->ngroups * sizeof(struct augentix_pin_group), GFP_KERNEL);
	if (!d->functions || !d->groups)
		goto no_mem;

	// parsing each function
	for_each_child_of_node (np, child) {
		f = d->functions + idx_f;
		f->name = child->name;
		f->ngroups = of_get_child_count(child);
		f->groups = devm_kzalloc(dev, f->ngroups * sizeof(char *), GFP_KERNEL);
		if (!f->groups)
			goto no_mem;
		DBG("child function name %s, ngroups: %u\n", f->name, f->ngroups);
		// parsing each group in a function
		ret = augentix_pinctrl_parse_function(d, f, child, idx_g);
		if (ret) {
			dev_err(dev, "augentix_pinctrl_parse_function failed\n");
			return ret;
		}
		idx_f++;
		idx_g += f->ngroups;
	};

	return 0;
no_mem:
	dev_err(dev, "Allocating drvdata member failed\n");
	return -ENOMEM;
}

static int augentix_pinctrl_probe(struct platform_device *pdev)
{
	struct augentix_pctl_drvdata *pctl;
	struct resource *res;
	struct device *dev = &pdev->dev;
	int ret;

	dev_info(dev, "Initializing Augentix pin control driver...\n");

	/* Create state holders etc for this driver */
	pctl = devm_kzalloc(dev, sizeof(*pctl), GFP_KERNEL);
	if (!pctl) {
		dev_err(&pdev->dev, "Failed to allocate drvdata\n");
		return -ENOMEM;
	}

	pctl->dev = dev;
	pctl->pctldesc = &augentix_pinctrl_desc;
	spin_lock_init(&pctl->lock);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	pctl->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(pctl->base)) {
		dev_err(dev, "Failed to map I/O address!\n");
		return PTR_ERR(pctl->base);
	}

	ret = augentix_pinctrl_probe_dt(pdev, pctl);
	if (ret) {
		dev_err(dev, "Device tree probe failed: %d\n", ret);
		return -EINVAL;
	}

	pctl->pctldev = pinctrl_register(&augentix_pinctrl_desc, dev, pctl);
	if (IS_ERR(pctl->pctldev)) {
		dev_err(dev, "Failed to register augentix pin control device\n");
		return PTR_ERR(pctl->pctldev);
	}

	dev_info(dev, "Augentix pin control driver initialized\n");
	return 0;
}

static struct of_device_id augentix_pinctrl_of_match[] = {
	{ .compatible = "augentix,pinctrl" },
	{},
};

static struct platform_driver augentix_pinctrl_driver =
{
	.driver = {
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.of_match_table = augentix_pinctrl_of_match,
	},
	.probe = augentix_pinctrl_probe,
};

static int __init augentix_pinctrl_init(void)
{
	return platform_driver_register(&augentix_pinctrl_driver);
}
arch_initcall(augentix_pinctrl_init);

MODULE_AUTHOR("Louis Yang, Augentix <louis.yang@augentix.com>");
MODULE_DESCRIPTION("Augentix pin control driver");
MODULE_LICENSE("GPL v2");
