// SPDX-License-Identifier: GPL-2.0-only
/*
* Copyright (c) 2015-2025 Augentix Inc. All rights reserved.
*/

#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>

#include <asm/io.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/interrupt.h>

#include <linux/gpio/consumer.h>
#include <linux/gpio.h>

#include <linux/timer.h>
#include <linux/spinlock.h>

#include "gpio-augentix-timer.h"

//#define TIMER_TEST_DEBUG

#ifdef TIMER_TEST_DEBUG
#define DBG(fmt, args...)            \
	do {                         \
		pr_err(fmt, ##args); \
	} while (0)
#else
#define DBG(fmt, args...) \
	do {              \
	} while (0)
#endif

struct agtx_timer_test_data {
	struct device *dev;
	struct gpio_desc *p_gpio[MAX_PIOC0_NUM];
	struct timer_list gpio_timer;
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

struct gpio_group_desc test_gpio_map[] = {
	{ PIOC0, "pioc0", MAX_PIOC0_NUM },
};

spinlock_t lock;

static irqreturn_t agtx_timer_interrupt(int irq, void *dev_id)
{
	struct agtx_motor_device *mdev = dev_id;

	int val_1, val_2;
	struct gpio_desc *dp_1 = mdev->p_gpio[PIOC0];
	struct gpio_desc *dp_2 = mdev->p_gpio[PIOC1];

	spin_lock(&mdev->slock);

	val_1 = gpiod_get_value(dp_1);
	val_2 = gpiod_get_value(dp_2);

	gpiod_set_value(dp_1, (val_1 ^ 1));
	gpiod_set_value(dp_2, (val_2 ^ 1));

	spin_unlock(&mdev->slock);

	DBG("GPIO flipped: val_1:%d, val_2:%d\n", val_1, val_2);

	agtx_timer_clear_IRQ(mdev->timer_handle);

	return IRQ_HANDLED;
}

static int gpio_timer_flip(struct agtx_motor_device *timer_test)
{
	int ret;
	struct gpio_desc *dp_1 = timer_test->p_gpio[PIOC0];
	struct gpio_desc *dp_2 = timer_test->p_gpio[PIOC1];

	ret = gpiod_direction_output(dp_1, 0);
	if (ret < 0) {
		pr_err("[FAIL] Cannot set output direction , errno=%d\n", ret);
		return -1;
	}

	ret = gpiod_direction_output(dp_2, 1);
	if (ret < 0) {
		pr_err("[FAIL] Cannot set output direction , errno=%d\n", ret);
		return -1;
	}

	agtx_timer_start(timer_test->timer_handle); //test. real case should be call byioctl
	return 0;
}

static int agtx_timer_test_probe(struct platform_device *pdev)
{
	int i, ret = 0;
	struct agtx_motor_device *mdev;

	printk("AGTX TIMER Module Start\n");

	mdev = devm_kzalloc(&pdev->dev, sizeof(struct agtx_motor_device), GFP_KERNEL);
	if (!mdev) {
		ret = -ENOMEM;
		dev_err(&pdev->dev, "Failed to allocate memory\n");
		goto error_devm_kzalloc;
	}

	mdev->dev = &pdev->dev;
	mdev->timer_handle = agtx_timer_request(2);

	mdev->timer_speed = 200;
	agtx_timer_set_period(mdev->timer_handle, 24000000 / 64 / mdev->timer_speed);

	mutex_init(&mdev->dev_mutex);
	spin_lock_init(&mdev->slock);

	platform_set_drvdata(pdev, mdev);

	/* Setup gpio */
	for (i = 0; i < test_gpio_map[PIOC0].num; i++) {
		mdev->p_gpio[i] = devm_gpiod_get_index(mdev->dev, test_gpio_map[PIOC0].name, i, GPIOD_OUT_LOW);

		if (IS_ERR(mdev->p_gpio[i])) {
			dev_err(&pdev->dev, "[PIOC0] GPIO driver not available: %s[%d]\n", test_gpio_map[PIOC0].name,
			        i);
		}
	}

	mdev->run_step_irq = platform_get_irq(pdev, 0);
	if (mdev->run_step_irq < 0) {
		ret = mdev->run_step_irq;
		dev_err(&pdev->dev, "Failed to get platform irq: %d\n", ret);
		goto error_get_irq;
	}

	ret = request_irq(mdev->run_step_irq, agtx_timer_interrupt, 0, "agtx_timer_interrupt", mdev);
	if (ret) {
		dev_err(&pdev->dev, "Failed to run request_irq() !\n");
		goto error_request_irq;
	}

	gpio_timer_flip(mdev);
	return 0;

error_request_irq:
error_get_irq:
	kfree(mdev);
error_devm_kzalloc:
	return ret;
}

static int agtx_timer_test_remove(struct platform_device *pdev)
{
	struct agtx_timer_test_data *mdev = platform_get_drvdata(pdev);
	devm_kfree(&pdev->dev, mdev);
	platform_set_drvdata(pdev, NULL);
	return 0;
}

static const struct of_device_id timer_test_dt_ids[] = {
	{ .compatible = "augentix,timer-test" },
	{},
};
MODULE_DEVICE_TABLE(of, timer_test_dt_ids);

static struct platform_driver agtx_timer_test_driver = { .probe = agtx_timer_test_probe,
	                                                 .remove = agtx_timer_test_remove,
	                                                 .driver = {
	                                                         .owner = THIS_MODULE,
	                                                         .name = "timer_test",
	                                                         .of_match_table = timer_test_dt_ids,
	                                                 } };
module_platform_driver(agtx_timer_test_driver);

MODULE_AUTHOR("Dream Yeh, Augentix <Dream.Yeh@augentix.com>");
MODULE_DESCRIPTION("Augentix timer test driver");
MODULE_LICENSE("GPL");
