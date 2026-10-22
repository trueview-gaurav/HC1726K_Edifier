#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/of_irq.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/slab.h>

#define DRV_NAME "eirq_test"

#define SYS_TEST_LOG(fmt, args...) printk("[EIRQ][%d]" fmt "...", ##args);
#define SYS_TEST_OK()              \
	printk("\e[0;92mOK\033[0m" \
	       "\n");
#define SYS_TEST_FAIL()              \
	printk("\e[0;91mFAIL\033[0m" \
	       "\n");

#define EIRQ_NUM 5
#define EIRQ_NUM_FOR_TEST 0

#if defined(CONFIG_OSAKA)
#define EIRQ_BASE 0x811C0000
#define IOMUX_BASE 0x82010000
#define FPGA_ROUTE_BASE 0x82100400
#elif defined(CONFIG_SAPPORO)
#define EIRQ_BASE 0x80002000
#define IOMUX_BASE 0x80001000
#define FPGA_ROUTE_BASE 0x80FF0400
#endif

#define RISING 0
#define FALLING 1
#define BOTH 2
#define LEVEL 3

#ifdef CONFIG_KAMO
#define GPIO_PINMUX_OFFFSET(x) (0xD0 + x * 4)
uint32_t EIRQ_IOMUX_OFFSET[] = { 0xE4, 0x118, 0x198, 0x10C, 0xD0 };
#else /* Sapporo */
#define GPIO_PINMUX_OFFFSET(x) (0xC8 + x * 4)
uint32_t EIRQ_IOMUX_OFFSET[] = { 0xDC, 0x110, 0x188, 0x104, 0xC8 };
#endif /* CONFIG_KAMO */
uint8_t EIRQ_IOMUX_SEL[] = { 2, 1, 4, 2, 2 };

struct eirq_test_data {
	uint32_t eirq[EIRQ_NUM]; /* Index of actual EIRQ submodule */
	int irq[EIRQ_NUM]; /* Linux IRQ number of each EIRQ submodule */
	struct device *dev;
	struct gpio_desc *test_gpio;
	volatile unsigned int __iomem *eirq_base;
	volatile unsigned int __iomem *iomux_base;
#ifdef CONFIG_FPGA
	volatile unsigned int __iomem *fpga_route_base;
	uint32_t old_gpio_fpga_route;
	uint32_t old_eirq_fpga_route;
#endif
	uint32_t old_gpio_pinmux;
	uint32_t old_eirq_pinmux;
	volatile uint32_t test_flag;
	volatile uint32_t trigger;
	volatile uint32_t invert;
};

static irqreturn_t eirq_handler(int irq, void *d)
{
	struct eirq_test_data *eirq_test = (struct eirq_test_data *)d;

	/* Clear EIRQ IRQ status or Set GPIO High/Low */
	if (eirq_test->trigger == RISING) {
		writel((1 << EIRQ_NUM_FOR_TEST), eirq_test->eirq_base);
	} else if (eirq_test->trigger == FALLING) {
		writel((1 << (EIRQ_NUM_FOR_TEST + 5)), eirq_test->eirq_base);
	} else if (eirq_test->trigger == BOTH) {
		writel((1 << EIRQ_NUM_FOR_TEST), eirq_test->eirq_base);
		writel((1 << (EIRQ_NUM_FOR_TEST + 5)), eirq_test->eirq_base);
	} else {
		if (eirq_test->invert == 1) {
			gpiod_set_value(eirq_test->test_gpio, 1);
		} else {
			gpiod_set_value(eirq_test->test_gpio, 0);
		}
	}

	eirq_test->test_flag = 1;
	return IRQ_HANDLED;
}

static int eirq_test_probe(struct platform_device *pdev)
{
	struct eirq_test_data *eirq_test = NULL;
	struct device *dev;
	int i, ret;
	uint32_t tmp = 0;
	const void *ret_p = 0;
	uint32_t gpio_num = 0;

	SYS_TEST_LOG("Test EIRQ With GIC ...", 3);
	printk("EIRQ%d\n", EIRQ_NUM_FOR_TEST);

	eirq_test = kzalloc(sizeof(eirq_test), GFP_KERNEL);
	if (!eirq_test) {
		return -ENOMEM;
	}
	eirq_test->dev = &pdev->dev;
	dev = eirq_test->dev;

	eirq_test->test_flag = 0;
	eirq_test->trigger = 0;
	eirq_test->invert = 0;

	eirq_test->eirq_base = ioremap(EIRQ_BASE, 0x40);
	ret_p = (const void *)eirq_test->eirq_base;
	if (IS_ERR(ret_p)) {
		printk("error code = %ld\n", PTR_ERR(ret_p));
		SYS_TEST_LOG("Ioremap EIRQ base ", 3);
		goto fail;
	}
	eirq_test->iomux_base = ioremap(IOMUX_BASE, 0x100);
	ret_p = (const void *)eirq_test->iomux_base;
	if (IS_ERR(ret_p)) {
		printk("error code = %ld\n", PTR_ERR(ret_p));
		SYS_TEST_LOG("Ioremap iomux base ", 3);
		goto fail;
	}
#ifdef CONFIG_FPGA
	eirq_test->fpga_route_base = ioremap(FPGA_ROUTE_BASE, 0x100);
	ret_p = (const void *)eirq_test->fpga_route_base;
	if (IS_ERR(ret_p)) {
		printk("error code = %ld\n", PTR_ERR(ret_p));
		SYS_TEST_LOG("Ioremap FPGA route base ", 3);
		goto fail;
	}
#endif
	/* Get IRQ number form DTS */
	of_property_read_u32_array(dev->of_node, "interrupts", eirq_test->eirq, EIRQ_NUM);
	for (i = 0; i < EIRQ_NUM; i++) {
		eirq_test->irq[i] = irq_of_parse_and_map(dev->of_node, i);
	}

	/* GIC = level high trigger */
	printk("\nGIC = level high trigger ");

	/* Set handler for GIC = level high trigger */
	ret = request_irq(eirq_test->irq[EIRQ_NUM_FOR_TEST], &eirq_handler, (IRQF_SHARED | IRQF_TRIGGER_HIGH), DRV_NAME,
	                  eirq_test);
	if (ret) {
		SYS_TEST_LOG("Request IRQ for GIC = level high trigger ", 3);
		goto fail;
	}

	/* Get test GPIO form DTS */
	eirq_test->test_gpio = gpiod_get(&pdev->dev, "eirq", GPIOD_OUT_LOW);
	if (IS_ERR(eirq_test->test_gpio)) {
		printk("error code = %ld\n", PTR_ERR(eirq_test->test_gpio));
		SYS_TEST_LOG("Cannot get test gpio ", 3);
		goto fail;
	}
	gpio_num = desc_to_gpio(eirq_test->test_gpio);

	/* Set GPIO IOMUX & FPGA Route */
	eirq_test->old_gpio_pinmux = readl(eirq_test->iomux_base + (GPIO_PINMUX_OFFFSET(gpio_num) / 4));
	writel(0x0, (eirq_test->iomux_base + (GPIO_PINMUX_OFFFSET(gpio_num) / 4)));
#ifdef CONFIG_FPGA
	eirq_test->old_gpio_fpga_route = readl(eirq_test->fpga_route_base + (0x18 / 4));
	writel(0x1, (eirq_test->fpga_route_base + (0x18 / 4)));
#endif
	/* Set Sensitive time */
	writel(200000, (eirq_test->eirq_base + ((0x14 + (EIRQ_NUM_FOR_TEST * 8)) / 4)));
	/* Set hold time */
	writel(0, (eirq_test->eirq_base + ((0x18 + (EIRQ_NUM_FOR_TEST * 8)) / 4)));

	/* Enable debouncing */
	tmp = readl(eirq_test->eirq_base + (0x10 / 4));
	tmp |= (1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0x10 / 4));

	/* Unmask EIRQ */
	tmp = readl(eirq_test->eirq_base + (0x8 / 4));
	tmp &= ~((1 << EIRQ_NUM_FOR_TEST) | (1 << (EIRQ_NUM_FOR_TEST + 5)));
	writel(tmp, eirq_test->eirq_base + (0x8 / 4));

	/* Set EIRQ FPGA Route & IOMUX */
#ifdef CONFIG_FPGA
	eirq_test->old_eirq_fpga_route = readl(eirq_test->fpga_route_base + (0x08 / 4));
	writel(0x1, (eirq_test->fpga_route_base + (0x08 / 4))); //EIRQ0
#endif
	eirq_test->old_eirq_pinmux = readl(eirq_test->iomux_base + (EIRQ_IOMUX_OFFSET[EIRQ_NUM_FOR_TEST] / 4));
	writel(EIRQ_IOMUX_SEL[EIRQ_NUM_FOR_TEST],
	       (eirq_test->iomux_base + (EIRQ_IOMUX_OFFSET[EIRQ_NUM_FOR_TEST] / 4))); //EIRQ0

	/* Test start */

	/* EIRQ = Rising */
	eirq_test->test_flag = 0;
	eirq_test->trigger = RISING;

	tmp = readl(eirq_test->eirq_base + (0xC / 4));
	tmp |= (1 << EIRQ_NUM_FOR_TEST);
	tmp &= ~(1 << (EIRQ_NUM_FOR_TEST + 5));
	writel(tmp, eirq_test->eirq_base + (0xC / 4));

	/* Set rising trigger */
	gpiod_set_value(eirq_test->test_gpio, 1);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Rising", 3);
		goto fail;
	}

	/* EIRQ = Falling */
	eirq_test->test_flag = 0;
	eirq_test->trigger = FALLING;

	tmp = readl(eirq_test->eirq_base + (0xC / 4));
	tmp &= ~(1 << EIRQ_NUM_FOR_TEST);
	tmp |= (1 << (EIRQ_NUM_FOR_TEST + 5));
	writel(tmp, eirq_test->eirq_base + (0xC / 4));

	/* Set falling trigger */
	gpiod_set_value(eirq_test->test_gpio, 0);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Falling", 3);
		goto fail;
	}

	/* EIRQ = Both*/
	eirq_test->test_flag = 0;
	eirq_test->trigger = BOTH;

	tmp = readl(eirq_test->eirq_base + (0xC / 4));
	tmp |= (1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0xC / 4));

	/* Set rising trigger*/
	gpiod_set_value(eirq_test->test_gpio, 1);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Both (Rising)", 3);
		goto fail;
	}

	eirq_test->test_flag = 0;

	/* Set falling trigger*/
	gpiod_set_value(eirq_test->test_gpio, 0);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Both (Falling)", 3);
		goto fail;
	}

	/* EIRQ = Level */
	eirq_test->test_flag = 0;
	eirq_test->trigger = LEVEL;
	eirq_test->invert = 0;

	tmp = readl(eirq_test->eirq_base + (0xC / 4));
	tmp &= ~(1 << EIRQ_NUM_FOR_TEST);
	tmp &= ~(1 << (EIRQ_NUM_FOR_TEST + 5));
	writel(tmp, eirq_test->eirq_base + (0xC / 4));

	tmp = readl(eirq_test->eirq_base + (0x3C / 4));
	tmp &= ~(1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0x3C / 4));

	/* Set Level trigger*/
	gpiod_set_value(eirq_test->test_gpio, 1);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Level", 3);
		goto fail;
	}

	/* EIRQ = Level(Invert) */
	eirq_test->test_flag = 0;
	eirq_test->trigger = LEVEL;
	eirq_test->invert = 1;

	tmp = readl(eirq_test->eirq_base + (0x3C / 4));
	tmp |= (1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0x3C / 4));

	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Level (invert)", 3);
		goto fail;
	}

	SYS_TEST_OK();

	/* Set handler for GIC = rising trigger */
	printk("GIC = Rising trigger ");
	irq_set_irq_type(eirq_test->irq[EIRQ_NUM_FOR_TEST], IRQ_TYPE_EDGE_RISING);

	/* EIRQ = Rising */
	eirq_test->test_flag = 0;
	eirq_test->trigger = RISING;

	tmp = readl(eirq_test->eirq_base + (0xC / 4));
	tmp |= (1 << EIRQ_NUM_FOR_TEST);
	tmp &= ~(1 << (EIRQ_NUM_FOR_TEST + 5));
	writel(tmp, eirq_test->eirq_base + (0xC / 4));

	/* Set rising trigger */
	gpiod_set_value(eirq_test->test_gpio, 1);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Rising", 3);
		goto fail;
	}

	/* EIRQ = Falling */
	eirq_test->test_flag = 0;
	eirq_test->trigger = FALLING;

	tmp = readl(eirq_test->eirq_base + (0xC / 4));
	tmp &= ~(1 << EIRQ_NUM_FOR_TEST);
	tmp |= (1 << (EIRQ_NUM_FOR_TEST + 5));
	writel(tmp, eirq_test->eirq_base + (0xC / 4));

	/* Set falling trigger */
	gpiod_set_value(eirq_test->test_gpio, 0);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Falling", 3);
		goto fail;
	}

	/* EIRQ = Both*/
	eirq_test->test_flag = 0;
	eirq_test->trigger = BOTH;

	tmp = readl(eirq_test->eirq_base + (0xC / 4));
	tmp |= (1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0xC / 4));

	/* Set rising trigger */
	gpiod_set_value(eirq_test->test_gpio, 1);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Both (Rising)", 3);
		goto fail;
	}

	eirq_test->test_flag = 0;

	/* Set falling trigger */
	gpiod_set_value(eirq_test->test_gpio, 0);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Both (Falling)", 3);
		goto fail;
	}

	/* EIRQ = Level */
	eirq_test->test_flag = 0;
	eirq_test->trigger = LEVEL;
	eirq_test->invert = 0;

	tmp = readl(eirq_test->eirq_base + (0xC / 4));
	tmp &= ~(1 << EIRQ_NUM_FOR_TEST);
	tmp &= ~(1 << (EIRQ_NUM_FOR_TEST + 5));
	writel(tmp, eirq_test->eirq_base + (0xC / 4));

	tmp = readl(eirq_test->eirq_base + (0x3C / 4));
	tmp &= ~(1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0x3C / 4));

	/* Set Level trigger */
	gpiod_set_value(eirq_test->test_gpio, 1);
	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Level", 3);
		goto fail;
	}

	/* EIRQ = Level(Invert) */
	eirq_test->test_flag = 0;
	eirq_test->trigger = LEVEL;
	eirq_test->invert = 1;

	tmp = readl(eirq_test->eirq_base + (0x3C / 4));
	tmp |= (1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0x3C / 4));

	mdelay(20);
	if (eirq_test->test_flag == 0) {
		SYS_TEST_LOG("EIRQ = Level (invert)", 3);
		goto fail;
	}

	platform_set_drvdata(pdev, eirq_test);

	SYS_TEST_OK();
	return 0;
fail:
	SYS_TEST_FAIL();
	return -EINVAL;
}

static int eirq_test_remove(struct platform_device *pdev)
{
	struct eirq_test_data *eirq_test = platform_get_drvdata(pdev);
	uint32_t tmp = 0;
	uint32_t gpio_num = 0;

	/* Get GPIO number */
	gpio_num = desc_to_gpio(eirq_test->test_gpio);

	/* Free GPIO */
	gpiod_put(eirq_test->test_gpio);

	/* Mask EIRQ */
	tmp = readl(eirq_test->eirq_base + (0x8 / 4));
	tmp |= ((1 << EIRQ_NUM_FOR_TEST) | (1 << (EIRQ_NUM_FOR_TEST + 5)));
	writel(tmp, eirq_test->eirq_base + (0x8 / 4));

	/* Disable debouncing */
	tmp = readl(eirq_test->eirq_base + (0x10 / 4));
	tmp &= ~(1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0x10 / 4));

	/* Disable inverter */
	tmp = readl(eirq_test->eirq_base + (0x3C / 4));
	tmp &= ~(1 << EIRQ_NUM_FOR_TEST);
	writel(tmp, eirq_test->eirq_base + (0x3C / 4));

	/* Recover setting */
	writel(eirq_test->old_gpio_pinmux, (eirq_test->iomux_base + (GPIO_PINMUX_OFFFSET(gpio_num) / 4)));
#ifdef CONFIG_FPGA
	writel(eirq_test->old_gpio_fpga_route, (eirq_test->fpga_route_base + (0x18 / 4)));
	writel(eirq_test->old_eirq_fpga_route, (eirq_test->fpga_route_base + (0x08 / 4))); //EIRQ0
#endif
	writel(eirq_test->old_eirq_pinmux,
	       (eirq_test->iomux_base + (EIRQ_IOMUX_OFFSET[EIRQ_NUM_FOR_TEST] / 4))); //EIRQ0

	/* Free IRQ */
	free_irq(eirq_test->irq[EIRQ_NUM_FOR_TEST], eirq_test);

	/* Free IO mapping */
	iounmap(eirq_test->iomux_base);
#ifdef CONFIG_FPGA
	iounmap(eirq_test->fpga_route_base);
#endif
	iounmap(eirq_test->eirq_base);

	/* Free memory space */
	kfree(eirq_test);

	platform_set_drvdata(pdev, NULL);

	return 0;
}

static const struct of_device_id eirq_test_dt_ids[] = {
	{ .compatible = "augentix,eirq-test" },
	{},
};
MODULE_DEVICE_TABLE(of, eirq_test_dt_ids);

static struct platform_driver eirq_test_driver = {
	.probe = eirq_test_probe,
	.remove = eirq_test_remove,
	.driver =
	        {
	                .owner = THIS_MODULE,
	                .name = DRV_NAME,
	                .of_match_table = eirq_test_dt_ids,
	        },
};
module_platform_driver(eirq_test_driver);

MODULE_DESCRIPTION("EIRQ test module");
MODULE_AUTHOR("<Jay.Tung@augentix.com>");
MODULE_LICENSE("GPL");
