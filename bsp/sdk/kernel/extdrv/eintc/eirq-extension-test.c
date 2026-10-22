#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/io.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/ktime.h>

// #define EIRQ_EXT_TEST_DEBUG
#ifdef EIRQ_EXT_TEST_DEBUG
#define DBG(fmt, ...)                                                                   \
	do {                                                                            \
		printk("[EIRQ-TEST] (%d, %s) " fmt, __LINE__, __func__, ##__VA_ARGS__); \
	} while (0)
#else
#define DBG(fmt, ...) \
	do {          \
	} while (0)
#endif /* EIRQ_EXT_TEST_DEBUG */

#define GPIO_BASE 0x80001400
#define GPIO_O_0 0x10
#define GPIO_OE_0 0x14
#define GPIO_O_1 0x20
#define GPIO_OE_1 0x24
#define GPIO_INI_VAL 0x00000000

#define MAX_EIRQ_PINS 5
#define TEST_IRQ_DEFAULT -1

/* Revise it to be GPIO_X X = number */
#define TEST_GPIO_PIN 7
#define TEST_GPIO_PIN_IN_HANDLER 8

#define DRV_NAME "eirq_ext_test"

static void __iomem *gpio_base;
static struct platform_device *eirq_test_pdev;
static int eirq_test_irq = TEST_IRQ_DEFAULT;

extern struct eirq_pin_status eirq_get_pin_status(u32 pin_id);
extern void eirq_clear_irq_neg(u32 pin_id);
extern void eirq_clear_irq_pos(u32 pin_id);
extern u32 eirq_get_status(void);

struct eirq_pin_status {
	bool pos;
	bool neg;
};

static void eirq_test_eirq_clear(void)
{
	int i;

	for (i = 0; i < MAX_EIRQ_PINS; i++) {
		eirq_clear_irq_pos(i);
		eirq_clear_irq_neg(i);
	}
}

static void eirq_test_gpio_set_dir(u32 pin, bool output)
{
	void __iomem *reg;
	u32 shift, val;

	if (pin < 32) {
		reg = gpio_base + GPIO_OE_0;
		shift = pin;
	} else if (pin < 64) {
		reg = gpio_base + GPIO_OE_1;
		shift = pin - 32;
	} else {
		pr_err("Invalid GPIO pin %u\n", pin);
		return;
	}

	val = readl(reg);
	if (output)
		val |= BIT(shift);
	else
		val &= ~BIT(shift);
	writel(val, reg);
}

static void eirq_test_gpio_set_level(u32 pin, bool high)
{
	void __iomem *reg;
	u32 shift, val;

	if (pin < 32) {
		reg = gpio_base + GPIO_O_0;
		shift = pin;
	} else if (pin < 64) {
		reg = gpio_base + GPIO_O_1;
		shift = pin - 32;
	} else {
		pr_err("Invalid GPIO pin %u\n", pin);
		return;
	}

	val = readl(reg);
	if (high)
		val |= BIT(shift);
	else
		val &= ~BIT(shift);
	writel(val, reg);
}

static irqreturn_t eirq_test_gpio_irq_handler(int irq, void *dev_id)
{
	DBG("IRQ %d triggered\n", irq);
	struct eirq_pin_status s;
	u32 i;

	eirq_test_gpio_set_level(TEST_GPIO_PIN_IN_HANDLER, true);
	eirq_test_gpio_set_level(TEST_GPIO_PIN_IN_HANDLER, false);

	for (i = 0; i < MAX_EIRQ_PINS; i++) {
		s = eirq_get_pin_status(i);
		if (s.pos || s.neg) {
			if (s.pos) {
				eirq_clear_irq_pos(i);
			}

			if (s.neg) {
				eirq_clear_irq_neg(i);
			}
			DBG("Pin %u triggered! POS=%d NEG=%d\n", i, s.pos, s.neg);
		}
	}
	return IRQ_HANDLED;
}

static void eirq_test_level_high_trigger(void)
{
	DBG("=== Level Trigger Test (high) start ===\n");

	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	msleep(50);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);

	DBG("=== Level Trigger Test (high) done ===\n\n\n\n");
}

static void eirq_test_level_low_trigger(void)
{
	DBG("=== Level Trigger Test (low) start ===\n");

	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);
	msleep(50);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);

	DBG("=== Level Trigger Test (low) done ===\n\n\n\n");
}

static void eirq_test_rising_edge(void)
{
	DBG("=== Rising Edge Trigger Test start ===\n");

	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);
	msleep(10);

	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	msleep(10);

	DBG("=== Rising Edge Trigger Test done ===\n\n\n\n");
}

static void eirq_test_falling_edge(void)
{
	DBG("=== Falling Edge Trigger Test start ===\n");

	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	msleep(10);

	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);
	msleep(10);

	DBG("=== Falling Edge Trigger Test done ===\n\n\n\n");
}

static void eirq_test_both_edge(void)
{
	DBG("=== Both Edge Trigger Test start ===\n");

	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);
	msleep(10);

	DBG("Rising edge part\n");
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	msleep(10);

	DBG("Falling edge part\n");
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);
	msleep(10);

	DBG("=== Both Edge Trigger Test done ===\n\n\n\n");
}

static void eirq_test_gpio_reset(void)
{
	DBG("=== GPIO Reset Test start ===\n");

	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);
	eirq_test_gpio_set_dir(TEST_GPIO_PIN, true);

	eirq_test_gpio_set_level(TEST_GPIO_PIN_IN_HANDLER, false);
	eirq_test_gpio_set_dir(TEST_GPIO_PIN_IN_HANDLER, true);

	DBG("=== GPIO Reset Test done ===\n\n\n\n");
}

/* Debounce verification */
static void eirq_test_gpio_prepare(void)
{
	eirq_test_gpio_reset();
	msleep(20);
	DBG("=== eirq_test_gpio_prepare done ===\n\n\n\n");
}

static void eirq_udelay_us(unsigned long usecs)
{
	/* split into 1000us chunks (constant) to avoid __bad_udelay issues */
	while (usecs >= 1000) {
		udelay(1000);
		usecs -= 1000;
	}

	/* now usecs < 1000 */
	if (usecs) {
		udelay(usecs);
	}
}

/* === A. Sensitive verification (default sens = 300000) === */
static void eirq_test_sensitive_short_default(void)
{
	DBG("=== A1: Sensitive (short pulse, debounce ON) start ===\n");
	eirq_test_gpio_prepare();

	/* pulse < sens (300000 cycles is about 12.5 ms)，用 5ms */
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	eirq_udelay_us(5000);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);

	DBG("=== A1 done ===\n\n");
}

static void eirq_test_sensitive_long_default(void)
{
	DBG("=== A2: Sensitive (long pulse, debounce ON) start ===\n");
	eirq_test_gpio_prepare();

	/* pulse > sens (300000 cycles is about 12.5 ms)，用 20 ms */
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	eirq_udelay_us(20000);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);

	DBG("=== A2 done ===\n\n");
}

/* === B. Sensitive verification (sens = 1048575) === */
static void eirq_test_sensitive_short_max(void)
{
	DBG("=== B1: Sensitive (short pulse, debounce ON, max sens) start ===\n");
	eirq_test_gpio_prepare();

	/* pulse < sens (1048575 cycles is around 43ms) use 20ms */
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	eirq_udelay_us(20000);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);

	DBG("=== B1 done ===\n\n");
}

static void eirq_test_sensitive_long_max(void)
{
	DBG("=== B2: Sensitive (long pulse, debounce ON, max sens) start ===\n");
	eirq_test_gpio_prepare();

	/* pulse > sens (1048576 cycles is around 43ms) use 60ms */
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	eirq_udelay_us(60000);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);

	DBG("=== B2 done ===\n\n");
}

/* === C. Hold verification (hold = 1048575) === */
static void eirq_test_hold_block(void)
{
	DBG("=== C1: Hold block test start ===\n");
	eirq_test_gpio_prepare();

	/* First pulse > sens (20ms) */
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	eirq_udelay_us(20000);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);
	eirq_udelay_us(5000);

	/* wait < hold (43ms) use 5ms here should not signal pulse twice */
	eirq_udelay_us(5000);

	/* Try to signal pulse again */
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	eirq_udelay_us(20000);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);

	DBG("=== C1 done ===\n\n");
}

static void eirq_test_hold_release(void)
{
	DBG("=== C2: Hold release test start ===\n");
	eirq_test_gpio_prepare();

	/* First pulse > sens (20ms) */
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	eirq_udelay_us(20000);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);
	eirq_udelay_us(5000);

	/* wait > hold (43ms) use 100ms here should signal pulse twice */
	eirq_udelay_us(100000);

	/* Try to signal pulse again */
	eirq_test_gpio_set_level(TEST_GPIO_PIN, true);
	eirq_udelay_us(20000);
	eirq_test_gpio_set_level(TEST_GPIO_PIN, false);

	DBG("=== C2 done ===\n\n");
}

static int eirq_test_gpio_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	int ret;

	DBG("[EIRQ-TEST] === probe start ===\n\n\n\n");

	/* To support insmod and test efficiently, we clean eirq status in the beginning */
	eirq_test_eirq_clear();

	gpio_base = ioremap(GPIO_BASE, 0x38);
	if (!gpio_base) {
		dev_err(dev, "Failed to ioremap GPIO base\n");
		return -ENOMEM;
	}

	/* IRQ handling
	 * Get "interrupts" fisrt specifier
	 */
	eirq_test_irq = platform_get_irq(pdev, 0);
	if (eirq_test_irq <= 0) {
		dev_err(dev, "Failed to do eirq_test_irq\n");
		return -EINVAL;
	}

	ret = devm_request_irq(dev, eirq_test_irq, eirq_test_gpio_irq_handler, IRQ_TYPE_EDGE_RISING, DRV_NAME, NULL);

	if (ret) {
		dev_err(dev, "Failed to request IRQ %d (ret=%d)\n", eirq_test_irq, ret);
		return ret;
	} else {
		dev_info(dev, "IRQ %d requested OK\n", eirq_test_irq);
	}

	/* Set initial GPIO status. Default at low voltage. */
	eirq_test_gpio_reset();

	/* TEST start */
	// eirq_test_rising_edge();
	// eirq_test_falling_edge();
	// eirq_test_level_high_trigger();
	// eirq_test_level_low_trigger();
	// eirq_test_both_edge();

	// eirq_test_sensitive_short_default();
	// eirq_test_sensitive_long_default();
	// eirq_test_sensitive_short_max();
	// eirq_test_sensitive_long_max();
	// eirq_test_hold_block();
	// eirq_test_hold_release();

	DBG("Probe done\n");
	return 0;
}

static int eirq_test_gpio_remove(struct platform_device *pdev)
{
	if (gpio_base)
		iounmap(gpio_base);

	eirq_test_irq = TEST_IRQ_DEFAULT;
	gpio_base = NULL;
	DBG("Remove done\n");
	return 0;
}

static const struct of_device_id eirq_test_of_match[] = {
	{ .compatible = "augentix,eirq-ext-test" },
	{},
};
MODULE_DEVICE_TABLE(of, eirq_test_of_match);

static struct platform_driver eirq_test_driver = {
    .probe = eirq_test_gpio_probe,
    .remove = eirq_test_gpio_remove,
    .driver = {
        .name = DRV_NAME,
        .of_match_table = eirq_test_of_match,
    },
};

/* Module init/exit for insmod support */
static int __init eirq_test_init(void)
{
	int ret;

	DBG("[EIRQ-TEST] module init\n");

	ret = platform_driver_register(&eirq_test_driver);
	if (ret) {
		pr_err("[EIRQ-TEST] failed to register driver: %d\n", ret);
		return ret;
	}

	// eirq_test_pdev = platform_device_register_simple(DRV_NAME, -1, NULL, 0);
	// if (IS_ERR(eirq_test_pdev)) {
	// 	pr_warn("[EIRQ-TEST] no DT node, dummy device create failed\n");
	// } else {
	// 	pr_info("[EIRQ-TEST] dummy device registered\n");
	// }

	return 0;
}

static void __exit eirq_test_exit(void)
{
	DBG("Module exit\n");

	if (eirq_test_pdev && !IS_ERR(eirq_test_pdev)) {
		platform_device_unregister(eirq_test_pdev);
		DBG("Dummy device unregistered\n");
	}

	platform_driver_unregister(&eirq_test_driver);
}

module_init(eirq_test_init);
module_exit(eirq_test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yan Chen <Yan.Chen@augentix.com>");
MODULE_DESCRIPTION("Augentix EIRQ Extension Test Driver");