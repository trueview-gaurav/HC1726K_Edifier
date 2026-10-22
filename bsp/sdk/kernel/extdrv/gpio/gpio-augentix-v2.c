#include <linux/module.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>

#include <linux/spinlock.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/interrupt.h>

#include <linux/gpio/driver.h>
#include <linux/gpio.h>
#include <linux/version.h>

#define DRIVER_NAME "augentix_gpio"

#if defined(CONFIG_OSAKA)
#define PIOC0_BASE_NUM 0
#define PIOC1_BASE_NUM 32
#define PIOC2_BASE_NUM 54
#define PIOC3_BASE_NUM 86
#define GPIO_AMOUNT 111

#define PMU_IOC_O_OFFSET 0x0
#define PMU_IOC_OE_OFFSET 0x4
#define PMU_IOC_I_OFFSET 0x8

#define AIOC0_O_OFFSET 0xC
#define AIOC0_OE_OFFSET 0x10
#define AIOC0_I_OFFSET 0x14

#define PIOC0_O_OFFSET 0x18
#define PIOC0_OE_OFFSET 0x1C
#define PIOC0_I_OFFSET 0x20
#define PIOC0_IE_OFFSET 0x24
#define PIOC1_O_OFFSET 0x28
#define PIOC1_OE_OFFSET 0x2C
#define PIOC1_I_OFFSET 0x30
#define PIOC1_IE_OFFSET 0x34
#define PIOC2_O_OFFSET 0x38
#define PIOC2_OE_OFFSET 0x3C
#define PIOC2_I_OFFSET 0x40
#define PIOC2_IE_OFFSET 0x44
#define PIOC3_O_OFFSET 0x48
#define PIOC3_OE_OFFSET 0x4C
#define PIOC3_I_OFFSET 0x50
#define PIOC3_IE_OFFSET 0x54
#else
/*
 * GPIO domain define
 *      PIOC0: 0~31, PIOC1: 32~48, PMU_IOC: 49~51
 */
#define PIOC0_BASE_NUM 0
#define PIOC1_BASE_NUM 32

#define PMU_IOC_BASE_NUM 49
#define GPIO_AMOUNT 52
#define PMU_IOC_GPO 49
#define PMU_IOC_GPI    \
	{              \
		50, 51 \
	}

#define PMU_IOC_O_OFFSET 0x0
#define PMU_IOC_OE_OFFSET 0x4
#define PMU_IOC_I_OFFSET 0x8
#define PIOC0_O_OFFSET 0x10
#define PIOC0_OE_OFFSET 0x14
#define PIOC0_I_OFFSET 0x18
#define PIOC0_IE_OFFSET 0x1C
#define PIOC1_O_OFFSET 0x20
#define PIOC1_OE_OFFSET 0x24
#define PIOC1_I_OFFSET 0x28
#define PIOC1_IE_OFFSET 0x2C
#endif

//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)                      \
	do {                                   \
		printk("[GPIO] " fmt, ##args); \
	} while (0)
#else
#define DBG(fmt, args...)
#endif

struct augentix_gpio_drvdata {
	struct device *dev;
	void __iomem *base;
	struct gpio_chip gpio_chip;
	struct pinctrl_gpio_range grange;
	spinlock_t lock;
};

#if defined(CONFIG_OSAKA)
typedef enum { PIOC0, PIOC1, PIOC2, PIOC3, BANK_NUM } AGTX_GPIO_DOMAIN;

static int offset_to_domain(unsigned gpio)
{
	AGTX_GPIO_DOMAIN domain;

	if (gpio < PIOC1_BASE_NUM) {
		domain = PIOC0;
	} else if ((gpio >= PIOC1_BASE_NUM) && (gpio < PIOC2_BASE_NUM)) {
		domain = PIOC1;
	} else if ((gpio >= PIOC2_BASE_NUM) && (gpio < PIOC3_BASE_NUM)) {
		domain = PIOC2;
	} else if ((gpio >= PIOC3_BASE_NUM) && (gpio < GPIO_AMOUNT)) {
		domain = PIOC3;
	} else {
		return -1;
	}

	return domain;
}
#else
typedef enum { PIOC0, PIOC1, PMU_IOC, BANK_NUM } AGTX_GPIO_DOMAIN;

static int offset_to_domain(unsigned gpio)
{
	AGTX_GPIO_DOMAIN domain;

	if (gpio < PIOC1_BASE_NUM) {
		domain = PIOC0;
	} else if ((gpio >= PIOC1_BASE_NUM) && (gpio < PMU_IOC_BASE_NUM)) {
		domain = PIOC1;
	} else if ((gpio >= PMU_IOC_BASE_NUM) && (gpio < GPIO_AMOUNT)) {
		domain = PMU_IOC;
	} else {
		return -1;
	}

	return domain;
}
#endif

typedef struct augentix_gpio_desc {
	AGTX_GPIO_DOMAIN domain;
	uint8_t pin_offset;
	uint32_t i_offset;
	uint32_t ie_offset;
	uint32_t o_offset;
	uint32_t oe_offset;
	const char *dts_name;
	int init_cells;
} AGTX_GPIO_DESC;

#if defined(CONFIG_OSAKA)
static AGTX_GPIO_DESC g_desc[] = {
	{ PIOC0, PIOC0_BASE_NUM, PIOC0_I_OFFSET, PIOC0_IE_OFFSET, PIOC0_O_OFFSET, PIOC0_OE_OFFSET, "pioc0_gpio", 2 },
	{ PIOC1, PIOC1_BASE_NUM, PIOC1_I_OFFSET, PIOC1_IE_OFFSET, PIOC1_O_OFFSET, PIOC1_OE_OFFSET, "pioc1_gpio", 2 },
	{ PIOC2, PIOC2_BASE_NUM, PIOC2_I_OFFSET, PIOC2_IE_OFFSET, PIOC2_O_OFFSET, PIOC2_OE_OFFSET, "pioc2_gpio", 2 },
	{ PIOC3, PIOC3_BASE_NUM, PIOC3_I_OFFSET, PIOC3_IE_OFFSET, PIOC3_O_OFFSET, PIOC3_OE_OFFSET, "pioc3_gpio", 2 },
};
#else
static AGTX_GPIO_DESC g_desc[] = {
	{ PIOC0, PIOC0_BASE_NUM, PIOC0_I_OFFSET, PIOC0_IE_OFFSET, PIOC0_O_OFFSET, PIOC0_OE_OFFSET, "pioc0_gpio", 2 },
	{ PIOC1, PIOC1_BASE_NUM, PIOC1_I_OFFSET, PIOC1_IE_OFFSET, PIOC1_O_OFFSET, PIOC1_OE_OFFSET, "pioc1_gpio", 2 },
	{ PMU_IOC, PMU_IOC_BASE_NUM, PMU_IOC_I_OFFSET, 0xFFFFFFFF, PMU_IOC_O_OFFSET, PMU_IOC_OE_OFFSET, "pmu_gpio", 1 },
};
#endif

static int augentix_gpio_get_value(struct gpio_chip *gc, unsigned int offset)
{
	struct augentix_gpio_drvdata *drvdata = container_of(gc, struct augentix_gpio_drvdata, gpio_chip);
	void __iomem *reg;
	u32 reg_val, domain;
	u32 o_off, oe_off, i_off, pin_off;

	domain = offset_to_domain(offset);
	if (domain < 0)
		return -EINVAL;

	o_off = g_desc[domain].o_offset;
	oe_off = g_desc[domain].oe_offset;
	i_off = g_desc[domain].i_offset;
	pin_off = g_desc[domain].pin_offset;

	reg = drvdata->base + oe_off;
	reg_val = (readl_relaxed(reg) & (1 << (offset - pin_off)));
	if (reg_val) {
		reg = drvdata->base + o_off;
	} else {
		reg = drvdata->base + i_off;
	}
	reg_val = (readl(reg) & (1 << (offset - pin_off)));

	DBG("pin %u, pin_off %u, o_off 0x%x, oe_off 0x%x, i_off 0x%x, val %u\n", offset, pin_off, o_off, oe_off, i_off,
	    !!reg_val);

	return !!reg_val;
}

static void augentix_gpio_set_value(struct gpio_chip *gc, unsigned int offset, int val)
{
	struct augentix_gpio_drvdata *drvdata = container_of(gc, struct augentix_gpio_drvdata, gpio_chip);
	void __iomem *reg;
	unsigned long flags;
	u32 reg_val, domain, o_off, pin_off;
#if defined(CONFIG_SAPPORO)
	unsigned int pmu_gpi[] = PMU_IOC_GPI;

	domain = offset_to_domain(offset);
	if (domain < 0 || offset == pmu_gpi[0] || offset == pmu_gpi[1])
		return;
#elif defined(CONFIG_OSAKA)
	domain = offset_to_domain(offset);
	if (domain < 0)
		return;
#endif

	o_off = g_desc[domain].o_offset;
	pin_off = g_desc[domain].pin_offset;
	reg = drvdata->base + o_off;

	spin_lock_irqsave(&drvdata->lock, flags);

	reg_val = readl_relaxed(reg);
	reg_val &= ~(1 << (offset - pin_off));
	if (val)
		reg_val |= (1 << (offset - pin_off));
	writel(reg_val, reg);
	DBG("pin %u, pin_off %u, o_off 0x%x, reg_val 0x%x\n", offset, pin_off, o_off, reg_val);

	spin_unlock_irqrestore(&drvdata->lock, flags);
}

static int augentix_gpio_set_direction(struct gpio_chip *gc, unsigned int offset, u8 oe)
{
	struct augentix_gpio_drvdata *drvdata = container_of(gc, struct augentix_gpio_drvdata, gpio_chip);
	unsigned long flags;
	u32 oe_val, domain, oe_off, pin_off;
	u32 ie_val, ie_off;

#if defined(CONFIG_SAPPORO)
	domain = offset_to_domain(offset);
	if (domain < 0) {
		return -EINVAL;
	} else if (domain == PMU_IOC) { //Fix pmu gpio direction
		return 0;
	}
#elif defined(CONFIG_OSAKA)
	domain = offset_to_domain(offset);
	if (domain < 0)
		return -EINVAL;
#endif

	oe_off = g_desc[domain].oe_offset;
	pin_off = g_desc[domain].pin_offset;
	ie_off = g_desc[domain].ie_offset;

	spin_lock_irqsave(&drvdata->lock, flags);

	oe_val = readl_relaxed(drvdata->base + oe_off);
	oe_val &= ~(1 << (offset - pin_off));
	ie_val = readl_relaxed(drvdata->base + ie_off);
	ie_val &= ~(1 << (offset - pin_off));

	if (oe) {
		oe_val |= (1 << (offset - pin_off));
	} else {
		ie_val |= (1 << (offset - pin_off));
	}
	writel(oe_val, drvdata->base + oe_off);
	writel(ie_val, drvdata->base + ie_off);

	DBG("pin %u, pin_off %u, ie_off 0x%x, ie_val 0x%x, oe_off 0x%x, oe_val 0x%x\n", offset, pin_off, ie_off, ie_val,
	    oe_off, oe_val);

	spin_unlock_irqrestore(&drvdata->lock, flags);

	return 0;
}

static int augentix_gpio_get_direction(struct gpio_chip *gc, unsigned int offset)
{
	struct augentix_gpio_drvdata *drvdata = container_of(gc, struct augentix_gpio_drvdata, gpio_chip);
	void __iomem *reg;
	u32 reg_val, domain, oe_off, pin_off;

	domain = offset_to_domain(offset);
	if (domain < 0)
		return -EINVAL;

	oe_off = g_desc[domain].oe_offset;
	pin_off = g_desc[domain].pin_offset;
	reg = drvdata->base + oe_off;

	reg_val = readl(reg);
	DBG("pin %u, pin_off %u, oe_off 0x%x, val 0x%x\n", offset, pin_off, oe_off,
	    reg_val & (1 << (offset - pin_off)));

	if (reg_val & (1 << (offset - pin_off)))
		return 0; //GPIO_LINE_DIRECTION_OUT

	return 1; //GPIO_LINE_DIRECTION_IN;
}

static int augentix_gpio_direction_input(struct gpio_chip *gc, unsigned int offset)
{
	return augentix_gpio_set_direction(gc, offset, 0);
}

static int augentix_gpio_direction_output(struct gpio_chip *gc, unsigned int offset, int value)
{
	augentix_gpio_set_value(gc, offset, value);
	return augentix_gpio_set_direction(gc, offset, 1);
}

static void augentix_gpio_reset(struct gpio_chip *gc)
{
	int i = 0;
	for (i = 0; i < GPIO_AMOUNT; i++) {
		augentix_gpio_direction_input(gc, i);
	}
}

static irqreturn_t gpio_wdt_irq_handler(int irq, void *dev_id)
{
	struct gpio_chip *gc = (struct gpio_chip *)dev_id;

	augentix_gpio_reset(gc);

	return IRQ_HANDLED;
}

static struct gpio_chip augentix_gpio_chip = {
	.set = augentix_gpio_set_value,
	.get = augentix_gpio_get_value,
	.direction_input = augentix_gpio_direction_input,
	.direction_output = augentix_gpio_direction_output,
	.get_direction = augentix_gpio_get_direction,
	.owner = THIS_MODULE,
	.base = 0,
	.ngpio = GPIO_AMOUNT,
	.label = DRIVER_NAME,
};

static int augentix_gpio_chip_register(struct platform_device *pdev, struct augentix_gpio_drvdata *drvdata)
{
	struct gpio_chip *gc = &drvdata->gpio_chip;
	int ret;

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 5, 0)
	gc->dev = drvdata->dev;
	gc->of_node = gc->dev->of_node;
#else
	gc->parent = drvdata->dev;
	gc->of_node = gc->parent->of_node;
#endif

	ret = gpiochip_add(gc);
	if (ret) {
		dev_err(&pdev->dev, "Failed to register gpio_chip, %d\n", ret);
		return ret;
	}

	return 0;
}

static int augentix_gpio_chip_init(struct platform_device *pdev, struct augentix_gpio_drvdata *drvdata)
{
	/*
	 * conf_from_dts are used as initial values
	 * conf[0] set for output_value
	 * conf[1] set for output_enable
	 * there's no output_enable reg for mipi_tx
	 * there's no output related reg for mipi_rx
	 */
	struct device *dev = &pdev->dev;
	struct device_node *np = pdev->dev.of_node;
	uint32_t conf_from_dts[2];
	int i;

	/* assign default setting to conf array */
	for (i = 0; i < BANK_NUM; i++) {
		if (of_property_read_u32_array(np, g_desc[i].dts_name, conf_from_dts, g_desc[i].init_cells) == 0) {
#if defined(CONFIG_SAPPORO)
			if (g_desc[i].domain == PMU_IOC) {
				writel(0x1,
				       drvdata->base + g_desc[i].oe_offset); // set PMU_PWR_CTRL output, others input
				if (conf_from_dts[0] == 0x1) { //for PMU_PWR_CTRL output value
					writel(0x1, drvdata->base + g_desc[i].o_offset);
				}
				dev_info(dev, "'%s' property found, 0x%x", g_desc[i].dts_name, conf_from_dts[0]);
				DBG("0x%x = 0x%x\n", g_desc[i].o_offset, readl(drvdata->base + g_desc[i].o_offset));
				DBG("0x%x = 0x%x\n", g_desc[i].oe_offset, readl(drvdata->base + g_desc[i].oe_offset));
			} else {
				writel(conf_from_dts[0], drvdata->base + g_desc[i].o_offset);
				writel(conf_from_dts[1], drvdata->base + g_desc[i].oe_offset);
				writel(~conf_from_dts[1], drvdata->base + g_desc[i].ie_offset);
				dev_info(dev, "'%s' property found, 0x%x, 0x%x", g_desc[i].dts_name, conf_from_dts[0],
				         conf_from_dts[1]);
				DBG("0x%x = 0x%x\n", g_desc[i].o_offset, readl(drvdata->base + g_desc[i].o_offset));
				DBG("0x%x = 0x%x\n", g_desc[i].oe_offset, readl(drvdata->base + g_desc[i].oe_offset));
				DBG("0x%x = 0x%x\n", g_desc[i].ie_offset, readl(drvdata->base + g_desc[i].ie_offset));
			}
#elif defined(CONFIG_OSAKA)
			writel(conf_from_dts[0], drvdata->base + g_desc[i].o_offset);
			writel(conf_from_dts[1], drvdata->base + g_desc[i].oe_offset);
			writel(~conf_from_dts[1], drvdata->base + g_desc[i].ie_offset);
			dev_info(dev, "'%s' property found, 0x%x, 0x%x", g_desc[i].dts_name, conf_from_dts[0],
			         conf_from_dts[1]);
			DBG("0x%x = 0x%x\n", g_desc[i].o_offset, readl(drvdata->base + g_desc[i].o_offset));
			DBG("0x%x = 0x%x\n", g_desc[i].oe_offset, readl(drvdata->base + g_desc[i].oe_offset));
			DBG("0x%x = 0x%x\n", g_desc[i].ie_offset, readl(drvdata->base + g_desc[i].ie_offset));
#endif
		}
	}

	return 0;
}

static int augentix_gpio_probe(struct platform_device *pdev)
{
	struct augentix_gpio_drvdata *drvdata;
	struct resource *res;
	struct device *dev = &pdev->dev;
	int ret;
	int irq;

	dev_info(&pdev->dev, "Initializing Augentix gpio driver...\n");

	drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
	if (!drvdata)
		return -ENOMEM;
	drvdata->dev = &pdev->dev;
	drvdata->gpio_chip = augentix_gpio_chip;
	spin_lock_init(&drvdata->lock);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	drvdata->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(drvdata->base)) {
		dev_err(dev, "Failed to map I/O address!\n");
	}

	ret = augentix_gpio_chip_init(pdev, drvdata);
	if (ret) {
		dev_err(dev, "GPIO initialization failed: %d\n", ret);
		return ret;
	}

	ret = augentix_gpio_chip_register(pdev, drvdata);
	if (ret) {
		dev_err(dev, "GPIO registration failed: %d\n", ret);
		return ret;
	}

	irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
	ret = devm_request_irq(&pdev->dev, irq, gpio_wdt_irq_handler, IRQF_SHARED, pdev->name, &drvdata->gpio_chip);
	if (ret != 0) {
		dev_err(dev, "failed to install irq(%d)", ret);
		return -EINVAL;
	}

	platform_set_drvdata(pdev, drvdata);

	dev_info(dev, "Augentix gpio driver initialized\n");

	return 0;
}

static void augentix_gpio_shutdown(struct platform_device *pdev)
{
	struct augentix_gpio_drvdata *drvdata = platform_get_drvdata(pdev);
	struct gpio_chip *gc = &drvdata->gpio_chip;

	augentix_gpio_reset(gc);
}

static const struct of_device_id augentix_gpio_of_match[] = {
	{ .compatible = "augentix,gpio" },
	{},
};

MODULE_DEVICE_TABLE(of, augentix_gpio_of_match);

static struct platform_driver augentix_gpio_driver = {
	.driver = {
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.of_match_table = augentix_gpio_of_match,
	},
	.probe = augentix_gpio_probe,
	.shutdown = augentix_gpio_shutdown,
};

module_platform_driver(augentix_gpio_driver);

MODULE_AUTHOR("Eddie Lee, Augentix <eddie.lee@augentix.com>");
MODULE_DESCRIPTION("Augentix gpio control driver");
MODULE_LICENSE("GPL");
