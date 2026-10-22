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
#include <linux/interrupt.h>
#include <linux/of_irq.h>

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

#define PIN_BORDER 49

#define PINMUX_OFFS 0x4
#define PINCONF_OFFS 0x4
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
	void __iomem *io_pd_base;
	void __iomem *io_pmu_base;
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
	PINCTRL_PIN(0, "PAD_GPIO_0"), PINCTRL_PIN(1, "PAD_GPIO_1"), PINCTRL_PIN(2, "PAD_GPIO_2"),
	PINCTRL_PIN(3, "PAD_GPIO_3"), PINCTRL_PIN(4, "PAD_GPIO_4"), PINCTRL_PIN(5, "PAD_GPIO_5"),
	PINCTRL_PIN(6, "PAD_GPIO_6"), PINCTRL_PIN(7, "PAD_GPIO_7"), PINCTRL_PIN(8, "PAD_GPIO_8"),
	PINCTRL_PIN(9, "PAD_GPIO_9"), PINCTRL_PIN(10, "PAD_GPIO_10"), PINCTRL_PIN(11, "PAD_GPIO_11"),
	PINCTRL_PIN(12, "PAD_GPIO_12"), PINCTRL_PIN(13, "PAD_GPIO_13"), PINCTRL_PIN(14, "PAD_GPIO_14"),
	PINCTRL_PIN(15, "PAD_GPIO_15"), PINCTRL_PIN(16, "PAD_GPIO_16"), PINCTRL_PIN(17, "PAD_GPIO_17"),
	PINCTRL_PIN(18, "PAD_GPIO_18"), PINCTRL_PIN(19, "PAD_GPIO_19"), PINCTRL_PIN(20, "PAD_GPIO_20"),
	PINCTRL_PIN(21, "PAD_GPIO_21"), PINCTRL_PIN(22, "PAD_GPIO_22"), PINCTRL_PIN(23, "PAD_GPIO_23"),
	PINCTRL_PIN(24, "PAD_GPIO_24"), PINCTRL_PIN(25, "PAD_GPIO_25"), PINCTRL_PIN(26, "PAD_GPIO_26"),
	PINCTRL_PIN(27, "PAD_GPIO_27"), PINCTRL_PIN(28, "PAD_GPIO_28"), PINCTRL_PIN(29, "PAD_GPIO_29"),
	PINCTRL_PIN(30, "PAD_GPIO_30"), PINCTRL_PIN(31, "PAD_GPIO_31"), PINCTRL_PIN(32, "PAD_GPIO_32"),
	PINCTRL_PIN(33, "PAD_GPIO_33"), PINCTRL_PIN(34, "PAD_GPIO_34"), PINCTRL_PIN(35, "PAD_GPIO_35"),
	PINCTRL_PIN(36, "PAD_GPIO_36"), PINCTRL_PIN(37, "PAD_GPIO_37"), PINCTRL_PIN(38, "PAD_GPIO_38"),
	PINCTRL_PIN(39, "PAD_GPIO_39"), PINCTRL_PIN(40, "PAD_GPIO_40"), PINCTRL_PIN(41, "PAD_GPIO_41"),
	PINCTRL_PIN(42, "PAD_GPIO_42"), PINCTRL_PIN(43, "PAD_GPIO_43"), PINCTRL_PIN(44, "PAD_GPIO_44"),
	PINCTRL_PIN(45, "PAD_GPIO_45"), PINCTRL_PIN(46, "PAD_GPIO_46"), PINCTRL_PIN(47, "PAD_GPIO_47"),
	PINCTRL_PIN(48, "PAD_GPIO_48"), PINCTRL_PIN(49, "PAD_PMU_PWR_CTRL"), PINCTRL_PIN(50, "PAD_PMU_WAKEUP"),
	PINCTRL_PIN(51, "PAD_PMU_BUTTON"),
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

static void __iomem *get_pinmux_addr(struct augentix_pctl_drvdata *d, uint32_t pin_id)
{
	void __iomem *mux_addr = 0;
	const uint8_t border = PIN_BORDER;

	if (pin_id >= ARRAY_SIZE(g_augentix_pins))
		return 0;

	if (pin_id < border) {
		// 0 ~ 48 starts from io_pd_base + 0xC8
		mux_addr = d->io_pd_base + 0xC8 + (pin_id * PINMUX_OFFS);
	} else if (pin_id == border) {
		// 49
		mux_addr = d->io_pmu_base + 0x20;
	} else {
		// 50 ~ 51 starts from io_pmu_base + 0x18
		mux_addr = d->io_pmu_base + 0x18 + ((pin_id - border - 1) * PINMUX_OFFS);
	}
	return mux_addr;
}

static int augentix_set_mux(struct pinctrl_dev *pctldev, unsigned func_selector, unsigned group_selector)
{
	struct augentix_pctl_drvdata *d = pinctrl_dev_get_drvdata(pctldev);
	struct augentix_pin_group *g = &d->groups[group_selector];
	void __iomem *mux_addr;
	int i;
	unsigned long flags;

	spin_lock_irqsave(&d->lock, flags);
	for (i = 0; i < g->npins; i++) {
		mux_addr = get_pinmux_addr(d, g->pins[i]);
		/* If no muxsel and addr, skip the operation */
		if (g->muxsel[i] != 0xFFFFFFFF && mux_addr != 0) {
			writel(g->muxsel[i], mux_addr);
		}
	}
	spin_unlock_irqrestore(&d->lock, flags);

	return 0;
}

static void augentix_pinmux_reset(struct augentix_pctl_drvdata *pctl)
{
	void __iomem *mux_addr;
	int i = 0;

	for (i = 0; i < PIN_BORDER; i++) {
		mux_addr = get_pinmux_addr(pctl, i);
		writel(0, mux_addr);
	}
}

static irqreturn_t pinctrl_wdt_irq_handler(int irq, void *dev_id)
{
	struct augentix_pctl_drvdata *pctl = (struct augentix_pctl_drvdata *)dev_id;

	augentix_pinmux_reset(pctl);

	return IRQ_HANDLED;
}

static const struct pinmux_ops augentix_pinmux_ops = {
	.get_functions_count = augentix_get_functions_count,
	.get_function_name = augentix_get_function_name,
	.get_function_groups = augentix_get_function_groups,
	.set_mux = augentix_set_mux,
};

/* PART 3: Pinconf operation */

static void __iomem *get_pinconf_addr(struct augentix_pctl_drvdata *d, uint32_t pin_id)
{
	void __iomem *conf_addr = 0;
	const uint8_t border = PIN_BORDER;

	if (pin_id < border) {
		// 0 ~ 48 starts from io_pd_base + 0x4
		conf_addr = d->io_pd_base + 0x4 + (pin_id * PINCONF_OFFS);
	} else if (pin_id == border) {
		// 49
		conf_addr = d->io_pmu_base + 0x10;
	} else {
		// 50 ~ 51 starts from io_pmu_base + 0x8
		conf_addr = d->io_pmu_base + 0x8 + ((pin_id - border - 1) * PINCONF_OFFS);
	}
	return conf_addr;
}

typedef enum {
	PD_3V3, //0~30, 40~48
	PD_1V8, //31~39
	PMU_1V8, //49~53
} PINCFG_CELL;

static PINCFG_CELL get_pinconf_cell_type(uint32_t pin_id)
{
	const uint8_t border = PIN_BORDER;

	if (pin_id >= border) { //49~53
		return PMU_1V8;
	} else if (pin_id >= 31 && pin_id <= 39) { //31~39
		return PD_1V8;
	} else { //0~30, 40~48
		return PD_3V3;
	}
}

static int augentix_pinconf_set_one(struct augentix_pctl_drvdata *d, u32 pin, enum pin_config_param param, u32 arg)
{
	u32 reg_val;
	unsigned long flags;
	void __iomem *conf_addr = get_pinconf_addr(d, pin);
	PINCFG_CELL cell_type;
	uint32_t mask;
	uint32_t bias;
	uint8_t ds_bias = 16;
	uint8_t ds_bit = 0;
	uint8_t st_bit = 0;
	uint8_t sl_bit = 0;
	uint8_t he_bit = 0;

	if (pin >= ARRAY_SIZE(g_augentix_pins)) {
		pr_err("Invalid pin %u\n", pin);
		return -1;
	}

	cell_type = get_pinconf_cell_type(pin);
	if ((cell_type == PMU_1V8) || (cell_type == PD_1V8)) {
		ds_bit = 2;
		st_bit = 2;
		sl_bit = 1;
		he_bit = 1;
	} else if (cell_type == PD_3V3) {
		ds_bit = 3;
		st_bit = 1;
	}

	spin_lock_irqsave(&d->lock, flags);
	reg_val = readl_relaxed(conf_addr);

	switch (param) {
	case PIN_CONFIG_BIAS_PULL_UP:
		reg_val &= ~0x03;
		if (arg) {
			reg_val |= 0x01;
			if (cell_type == PMU_1V8 || cell_type == PD_1V8)
				reg_val |= 0x02;
		}
		break;
	case PIN_CONFIG_BIAS_PULL_DOWN:
		reg_val &= ~0x03;
		if (arg) {
			if (cell_type == PMU_1V8 || cell_type == PD_1V8) {
				reg_val |= 0x01;
			} else {
				reg_val |= 0x02;
			}
		}
		break;
	case PIN_CONFIG_BIAS_DISABLE:
	case PIN_CONFIG_BIAS_PULL_PIN_DEFAULT:
		reg_val &= ~0x03;
		break;
	case PIN_CONFIG_DRIVE_STRENGTH:
		bias = ds_bias;
		mask = (1 << ds_bit) - 1;
		reg_val &= (~(mask << bias));
		reg_val |= ((arg & mask) << bias);
		break;
	case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
		if (st_bit) {
			bias = ds_bias + ds_bit;
			mask = (1 << st_bit) - 1;
			reg_val &= (~(mask << bias));
			reg_val |= ((arg & mask) << bias);
		}
		break;
	case PIN_CONFIG_SLEW_RATE:
		if (sl_bit) {
			bias = ds_bias + ds_bit + st_bit;
			mask = (1 << sl_bit) - 1;
			reg_val &= (~(mask << bias));
			reg_val |= ((arg & mask) << bias);
		}
		break;
	default:
		spin_unlock_irqrestore(&d->lock, flags);
		return -ENOTSUPP;
	}

	writel(reg_val, conf_addr);
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
	int irq;

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
	pctl->io_pd_base = devm_ioremap_resource(dev, res);
	if (IS_ERR(pctl->io_pd_base)) {
		dev_err(dev, "Failed to map I/O address!\n");
		return PTR_ERR(pctl->io_pd_base);
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	pctl->io_pmu_base = devm_ioremap_resource(dev, res);
	if (IS_ERR(pctl->io_pmu_base)) {
		dev_err(dev, "Failed to map I/O address!\n");
		return PTR_ERR(pctl->io_pmu_base);
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

	irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
	ret = devm_request_irq(&pdev->dev, irq, pinctrl_wdt_irq_handler, IRQF_SHARED, pdev->name, pctl);
	if (ret != 0) {
		dev_err(dev, "failed to install irq(%d)", ret);
		return -EINVAL;
	}

	platform_set_drvdata(pdev, pctl);

	dev_info(dev, "Augentix pin control driver initialized\n");
	return 0;
}

static struct of_device_id augentix_pinctrl_of_match[] = {
	{ .compatible = "augentix,pinctrl" },
	{},
};

static void augentix_pinctrl_shutdown(struct platform_device *pdev)
{
	struct augentix_pctl_drvdata *pctl = platform_get_drvdata(pdev);

	augentix_pinmux_reset(pctl);
}

static struct platform_driver augentix_pinctrl_driver =
{
	.driver = {
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.of_match_table = augentix_pinctrl_of_match,
	},
	.probe = augentix_pinctrl_probe,
	.shutdown = augentix_pinctrl_shutdown,
};

static int __init augentix_pinctrl_init(void)
{
	return platform_driver_register(&augentix_pinctrl_driver);
}
arch_initcall(augentix_pinctrl_init);

MODULE_AUTHOR("Eddie Lee, Augentix <eddie.lee@augentix.com>");
MODULE_DESCRIPTION("Augentix pin control driver");
MODULE_LICENSE("GPL");
