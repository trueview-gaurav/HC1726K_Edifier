#include <linux/module.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>

#include <linux/spinlock.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>

#include <linux/gpio/driver.h>
#include <linux/gpio.h>
#include <linux/version.h>

#define DRIVER_NAME "augentix_gpio"

/*
 * GPIO domain define
 *	PLAT_HC1703_1723_1753_1783S(Linux 3.18) || MACH_HC17XX(Linux 6.1) for HC1703_1723_1753_1783S
 *		PIOC0: 0~31, PIOC1: 32~63, PIOC2: 64~67, AIOC: 68~80
 *		MIPI_TX: 81~90, MIPI_RX0: 91~100, MIPI_RX1: 101~110
 */
#define PIOC0_BASE_NUM 0
#define PIOC1_BASE_NUM 32
#define PIOC2_BASE_NUM 64

#define AIOC_BASE_NUM 68
#define MIPI_TX_BASE_NUM 81
#define MIPI_RX0_BASE_NUM 91
#define MIPI_RX1_BASE_NUM 101
#define GPIO_AMOUNT 111

#define AIOC_O_OFFSET 0x0
#define AIOC_OE_OFFSET 0x4
#define AIOC_I_OFFSET 0x8
#define PIOC0_O_OFFSET 0xC
#define PIOC0_OE_OFFSET 0x10
#define PIOC0_I_OFFSET 0x14
#define PIOC1_O_OFFSET 0x18
#define PIOC1_OE_OFFSET 0x1C
#define PIOC1_I_OFFSET 0x20
#define PIOC2_O_OFFSET 0x24
#define PIOC2_OE_OFFSET 0x28
#define PIOC2_I_OFFSET 0x30
#define MIPI_TX_O_OFFSET 0x34
#define MIPI_RX0_I_OFFSET 0x38
#define MIPI_RX1_I_OFFSET 0x3C

//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)                                                          \
	do {                                                                       \
		printk("[GPIO_DRIVER] (%d, %s) " fmt, __LINE__, __func__, ##args); \
	} while (0)
#endif

struct augentix_gpio_drvdata {
	struct device *dev;
	void __iomem *base;
	struct gpio_chip gpio_chip;
	struct pinctrl_gpio_range grange;
	spinlock_t lock;
};

typedef enum { AIOC, PIOC0, PIOC1, PIOC2, MIPI_TX, MIPI_RX0, MIPI_RX1, BANK_NUM } AGTX_GPIO_DOMAIN;

struct augentix_gpio_desc {
	AGTX_GPIO_DOMAIN domain;
	uint8_t pin_offset;
	uint32_t i_offset;
	uint32_t o_offset;
	uint32_t oe_offset;
	const char *dts_name;
	int init_cells;
};

struct augentix_gpio_desc g_desc[] = {
	{ AIOC, AIOC_BASE_NUM, AIOC_I_OFFSET, AIOC_O_OFFSET, AIOC_OE_OFFSET, "aioc_gpio", 2 },
	{ PIOC0, PIOC0_BASE_NUM, PIOC0_I_OFFSET, PIOC0_O_OFFSET, PIOC0_OE_OFFSET, "pioc0_gpio", 2 },
	{ PIOC1, PIOC1_BASE_NUM, PIOC1_I_OFFSET, PIOC1_O_OFFSET, PIOC1_OE_OFFSET, "pioc1_gpio", 2 },
	{ PIOC2, PIOC2_BASE_NUM, PIOC2_I_OFFSET, PIOC2_O_OFFSET, PIOC2_OE_OFFSET, "pioc2_gpio", 2 },
	{ MIPI_TX, MIPI_TX_BASE_NUM, 0, MIPI_TX_O_OFFSET, 0, "mipi_tx_gpio_o_0", 1 },
	{ MIPI_RX0, MIPI_RX0_BASE_NUM, MIPI_RX0_I_OFFSET, 0, 0, NULL, 0 },
	{ MIPI_RX1, MIPI_RX1_BASE_NUM, MIPI_RX1_I_OFFSET, 0, 0, NULL, 0 },
};

static int offset_to_domain(unsigned int offset)
{
	AGTX_GPIO_DOMAIN domain;

	if (offset < PIOC1_BASE_NUM) {
		domain = PIOC0;
	} else if ((offset >= PIOC1_BASE_NUM) && (offset < PIOC2_BASE_NUM)) {
		domain = PIOC1;
	} else if ((offset >= PIOC2_BASE_NUM) && (offset < AIOC_BASE_NUM)) {
		domain = PIOC2;
	} else if ((offset >= AIOC_BASE_NUM) && (offset < MIPI_TX_BASE_NUM)) {
		domain = AIOC;
	} else if ((offset >= MIPI_TX_BASE_NUM) && (offset < MIPI_RX0_BASE_NUM)) {
		domain = MIPI_TX;
	} else if ((offset >= MIPI_RX0_BASE_NUM) && (offset < MIPI_RX1_BASE_NUM)) {
		domain = MIPI_RX0;
	} else if ((offset >= MIPI_RX1_BASE_NUM) && (offset < GPIO_AMOUNT)) {
		domain = MIPI_RX1;
	} else {
		return -EINVAL;
	}

	return domain;
}

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

	if (domain == MIPI_TX) {
		reg = drvdata->base + o_off;
	} else if (domain == MIPI_RX0 || domain == MIPI_RX1) {
		reg = drvdata->base + i_off;
	} else {
		reg = drvdata->base + oe_off;
		reg_val = (readl_relaxed(reg) & (1 << (offset - pin_off)));
		if (reg_val) {
			reg = drvdata->base + o_off;
		} else {
			reg = drvdata->base + i_off;
		}
	}
	reg_val = (readl(reg) & (1 << (offset - pin_off)));
	return !!reg_val;
}

static void augentix_gpio_set_value(struct gpio_chip *gc, unsigned int offset, int val)
{
	struct augentix_gpio_drvdata *drvdata = container_of(gc, struct augentix_gpio_drvdata, gpio_chip);
	void __iomem *reg;
	unsigned long flags;
	u32 reg_val, domain, o_off, pin_off;

	domain = offset_to_domain(offset);
	if (domain < 0 || domain == MIPI_RX0 || domain == MIPI_RX1)
		return;

	o_off = g_desc[domain].o_offset;
	pin_off = g_desc[domain].pin_offset;
	reg = drvdata->base + o_off;

	spin_lock_irqsave(&drvdata->lock, flags);

	reg_val = readl_relaxed(reg);
	reg_val &= ~(1 << (offset - pin_off));
	if (val)
		reg_val |= (1 << (offset - pin_off));
	writel(reg_val, reg);

	spin_unlock_irqrestore(&drvdata->lock, flags);
}

static int augentix_gpio_set_direction(struct gpio_chip *gc, unsigned int offset, u8 oe)
{
	struct augentix_gpio_drvdata *drvdata = container_of(gc, struct augentix_gpio_drvdata, gpio_chip);
	unsigned long flags;
	u32 oe_val, domain, oe_off, pin_off;

	domain = offset_to_domain(offset);
	if (domain < 0) {
		return -EINVAL;
	} else if (domain == MIPI_RX0 || domain == MIPI_RX1 || domain == MIPI_TX) {
		return 0;
	}

	oe_off = g_desc[domain].oe_offset;
	pin_off = g_desc[domain].pin_offset;

	spin_lock_irqsave(&drvdata->lock, flags);

	oe_val = readl_relaxed(drvdata->base + oe_off);
	oe_val &= ~(1 << (offset - pin_off));
	if (oe) {
		oe_val |= (1 << (offset - pin_off));
	}
	writel(oe_val, drvdata->base + oe_off);

	spin_unlock_irqrestore(&drvdata->lock, flags);

	return 0;
}

static int augentix_gpio_get_direction(struct gpio_chip *gc, unsigned int offset)
{
	struct augentix_gpio_drvdata *drvdata = container_of(gc, struct augentix_gpio_drvdata, gpio_chip);
	void __iomem *reg;
	u32 reg_val, domain, oe_off, pin_off;

	domain = offset_to_domain(offset);
	if (domain < 0 || domain == MIPI_RX0 || domain == MIPI_RX1 || domain == MIPI_TX)
		return -EINVAL;

	oe_off = g_desc[domain].oe_offset;
	pin_off = g_desc[domain].pin_offset;
	reg = drvdata->base + oe_off;

	reg_val = readl(reg);

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
		if (g_desc[i].init_cells) {
			if (of_property_read_u32_array(np, g_desc[i].dts_name, conf_from_dts, g_desc[i].init_cells) ==
			    0) {
				writel(conf_from_dts[0], drvdata->base + g_desc[i].o_offset);
				if (g_desc[i].init_cells == 1) {
					dev_info(dev, "'%s' property found, 0x%x", g_desc[i].dts_name,
					         conf_from_dts[0]);
				} else if (g_desc[i].init_cells == 2) {
					writel(conf_from_dts[1], drvdata->base + g_desc[i].oe_offset);
					dev_info(dev, "'%s' property found, 0x%x, 0x%x", g_desc[i].dts_name,
					         conf_from_dts[0], conf_from_dts[1]);
				}
			}
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

	platform_set_drvdata(pdev, drvdata);

	dev_info(dev, "Augentix gpio driver initialized\n");

	return 0;
}

static int augentix_gpio_remove(struct platform_device *pdev)
{
	struct augentix_gpio_drvdata *drvdata;

	drvdata = platform_get_drvdata(pdev);
	gpiochip_remove(&drvdata->gpio_chip);

	return 0;
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
	.remove = augentix_gpio_remove,
};

module_platform_driver(augentix_gpio_driver);

MODULE_AUTHOR("Louis Yang, Augentix <louis.yang@augentix.com>");
MODULE_DESCRIPTION("Augentix gpio control driver");
MODULE_LICENSE("GPL v2");
