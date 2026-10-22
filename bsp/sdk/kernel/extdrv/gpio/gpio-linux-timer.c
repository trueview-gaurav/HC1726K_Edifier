#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>

#include <asm/io.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/gpio/consumer.h>
#include <linux/gpio.h>

#include <linux/timer.h>
#include <linux/spinlock.h>

#define DRV_NAME "gpio_test"

#define MAX_PIOC0_NUM 2

#define FLIP_DELAY 50
#define STOP_DELAY 1000

#define GPIO_TEST_DEBUG (1)

#ifdef GPIO_TEST_DEBUG
#define DBG(fmt, args...)                                                        \
	do {                                                                     \
		printk("[GPIO_TEST] (%d, %s) " fmt, __LINE__, __func__, ##args); \
	} while (0)
#endif

struct gpio_test_data {
	struct device *dev;
	struct gpio_desc *p_gpio[MAX_PIOC0_NUM];
	struct timer_list gpio_timer;
	struct timer_list stop_timer;
	spinlock_t lock;
};

enum gpio_group {
	PIOC0,
	PIOC1,
	GROUP_NUM,
};

struct gpio_group_desc {
	enum gpio_group id;
	const char *name;
	int num;
};

struct gpio_group_desc gpio_map[] = {
	{ PIOC0, "pioc0", MAX_PIOC0_NUM },
};

static void stop_do_timer(unsigned long arg)
{
	struct gpio_test_data *data = (struct gpio_test_data *)(arg);
	struct timer_list *stop_timer = &data->stop_timer;
	struct timer_list *gpio_timer = &data->gpio_timer;

	del_timer(gpio_timer);
	del_timer(stop_timer);
}

static void gpio_do_timer(unsigned long arg)
{
	int val_1, val_2;

	struct gpio_test_data *data = (struct gpio_test_data *)(arg);
	struct gpio_desc *dp_1 = data->p_gpio[PIOC0];
	struct gpio_desc *dp_2 = data->p_gpio[PIOC1];
	struct timer_list *gpio_timer = &data->gpio_timer;

	unsigned long flags;
	spin_lock_irqsave(&data->lock, flags);

	val_1 = gpiod_get_value(dp_1);
	val_2 = gpiod_get_value(dp_2);

	gpiod_set_value(dp_1, (val_1 ^ 1));
	gpiod_set_value(dp_2, (val_2 ^ 1));

	spin_unlock_irqrestore(&data->lock, flags);

	DBG("\tval_1:%d, val_2:%d\n", val_1, val_2);

	gpio_timer->expires = jiffies + FLIP_DELAY;
	add_timer(gpio_timer);
}

static int gpio_flip(struct gpio_test_data *gpio_test)
{
	int ret;
	struct gpio_desc *dp_1 = gpio_test->p_gpio[PIOC0];
	struct gpio_desc *dp_2 = gpio_test->p_gpio[PIOC1];
	struct timer_list *gpio_timer = &gpio_test->gpio_timer;
	struct timer_list *stop_timer = &gpio_test->stop_timer;

	ret = gpiod_direction_output(dp_1, GPIOF_DIR_OUT);
	if (ret < 0) {
		DBG("[FAIL] Cannot set output direction , errno=%d\n", ret);
		return -1;
	}

	ret = gpiod_direction_output(dp_2, GPIOF_DIR_IN);
	if (ret < 0) {
		DBG("[FAIL] Cannot set output direction , errno=%d\n", ret);
		return -1;
	}

	/* Initilize spinlock */
	spin_lock_init(&gpio_test->lock);

	/* register timer */

	init_timer(gpio_timer);
	gpio_timer->function = gpio_do_timer;
	gpio_timer->data = (unsigned long)gpio_test;
	gpio_timer->expires = jiffies + FLIP_DELAY;
	add_timer(gpio_timer);

	init_timer(stop_timer);
	stop_timer->function = stop_do_timer;
	stop_timer->data = (unsigned long)gpio_test;
	stop_timer->expires = jiffies + STOP_DELAY;
	add_timer(stop_timer);

	return 0;
}

static int gpio_test_probe(struct platform_device *pdev)
{
	struct gpio_test_data *gpio_test = NULL;
	int i;

	printk("Module Start\n");

	gpio_test = devm_kzalloc(&pdev->dev, sizeof(struct gpio_test_data), GFP_KERNEL);
	if (!gpio_test)
		return -ENOMEM;
	gpio_test->dev = &pdev->dev;

	platform_set_drvdata(pdev, gpio_test);

	/* Setup gpio */
	for (i = 0; i < gpio_map[PIOC0].num; i++) {
		gpio_test->p_gpio[i] = devm_gpiod_get_index(gpio_test->dev, gpio_map[PIOC0].name, i, GPIOD_OUT_LOW);

		if (IS_ERR(gpio_test->p_gpio[i])) {
			DBG("[PIOC0]GPIO driver not available: %s[%d]\n", gpio_map[PIOC0].name, i);
		}
	}

	gpio_flip(gpio_test);
	DBG("GPIO test module probed.\n");
	return 0;
}

static int gpio_test_remove(struct platform_device *pdev)
{
	struct gpio_test_data *gpio_test = platform_get_drvdata(pdev);
	devm_kfree(&pdev->dev, gpio_test);
	platform_set_drvdata(pdev, NULL);
	return 0;
}

static const struct of_device_id gpio_test_dt_ids[] = {
	{ .compatible = "augentix,gpio-test" },
	{},
};
MODULE_DEVICE_TABLE(of, gpio_test_dt_ids);

static struct platform_driver gpio_test_driver = { .probe = gpio_test_probe,
	                                           .remove = gpio_test_remove,
	                                           .driver = {
	                                                   .owner = THIS_MODULE,
	                                                   .name = DRV_NAME,
	                                                   .of_match_table = gpio_test_dt_ids,
	                                           } };
module_platform_driver(gpio_test_driver);

MODULE_AUTHOR("BoSyun Cheng, Augentix <Bosyun.Cheng@augentix.com>");
MODULE_DESCRIPTION("gpio test driver");
MODULE_LICENSE("GPL");
