// SPDX-License-Identifier: GPL-2.0-only
/*
* Copyright (c) 2015-2025 Augentix Inc. All rights reserved.
*/

#include <linux/module.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <linux/completion.h>
#include <linux/cdev.h>

#include <linux/interrupt.h>

#include <linux/slab.h>

#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_device.h>
#include <linux/delay.h>
#include <linux/uaccess.h>

#include "eirq-pir-augentix.h"

#define DRV_NAME "augentix_eint_pir"
#define JIFFIES_TIMEOUT 500
#define SENSITIVITY_PERIOD_MS 50

DECLARE_COMPLETION(pir_trigger);

extern int hc_trigger_gpio(int pin_id, int level);

//#define EINTC_DEBUG

#ifdef EINTC_DEBUG
#define DBG(fmt, args...)                                                       \
	do {                                                                    \
		printk("[EIRQ_PIR] (%d, %s) " fmt, __LINE__, __func__, ##args); \
	} while (0)
#else
#define DBG(fmt, args...) \
	do {              \
		;         \
	} while (0)
#endif /* EINTC_DEBUG */

struct eintc_pir_data {
	uint32_t eirq; /* Index of actual EIRQ submodule */
	int irq; /* Linux IRQ number of each EIRQ submodule */
	int gpio_sensitivity_id; /* Gpio pin for control sensitivity */
	int pir_timeout;
	struct device *dev;
	struct cdev cdev;
	struct class *pir_class;
	dev_t pir_devt;
};

static int hc_pir_setsentivity(unsigned int time_ms, int gpio_pin)
{
	DBG("hc_pir_setsentivity: set setsentivity, time_ms = %d, gpio_pin = %d\n", time_ms, gpio_pin);
	hc_trigger_gpio(gpio_pin, 0);
	msleep(SENSITIVITY_PERIOD_MS);
	hc_trigger_gpio(gpio_pin, 1);
	msleep(time_ms);
	hc_trigger_gpio(gpio_pin, 0);
	msleep(SENSITIVITY_PERIOD_MS);
	hc_trigger_gpio(gpio_pin, 1);
	return 0;
}

/* Whent user space call read, wait for pir trigger */
static int hc18xx_eint_pir_open(struct inode *inode, struct file *filp)
{
	struct eintc_pir_data *id = container_of(inode->i_cdev, struct eintc_pir_data, cdev);
	filp->private_data = id;
	DBG("hc18xx_eint_pir_open: open\n");
	return 0;
}

static int hc18xx_eint_pir_close(struct inode *inode, struct file *filp)
{
	DBG("hc18xx_eint_pir_close: close\n");
	return 0;
}

static ssize_t hc18xx_eint_pir_read(struct file *filp, char *buf, size_t size, loff_t *f_pos)
{
	struct eintc_pir_data *fd = filp->private_data;
	int ret;
	DBG("hc18xx_eint_pir_read: read  (size=%zu)\n", size);
	ret = wait_for_completion_interruptible_timeout(&pir_trigger, fd->pir_timeout);

	if (copy_to_user(buf, &ret, sizeof(ret))) {
		return -EFAULT;
	}

	return sizeof(ret);
}

static ssize_t hc18xx_eint_pir_write(struct file *filp, const char *buf, size_t size, loff_t *f_pos)
{
	DBG("hc18xx_eint_pir_write: write  (size=%zu)\n", size);
	return size;
}

static long hc18xx_eint_pir_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct eintc_pir_data *fd = filp->private_data;
	void __user *argp = (void __user *)arg;
	int __user *p = argp;
	int new_value;

	switch (cmd) {
	case IOC_PIR_SETTIMEOUT:
		DBG("hc18xx_eint_pir_ioctl: IOC_PIR_SETTIMEOUT\n");
		if (get_user(new_value, p))
			return -EFAULT;
		fd->pir_timeout = new_value;
		DBG("hc18xx_eint_pir_ioctl: set timeout = %d\n", fd->pir_timeout);
		return 0;
	case IOC_PIR_SENSITIVITY:
		DBG("hc18xx_eint_pir_ioctl: IOC_PIR_SENSITIVITY\n");
		if (get_user(new_value, p))
			return -EFAULT;
		hc_pir_setsentivity(new_value, fd->gpio_sensitivity_id);
		return 0;
	default:
		return -ENOTTY;
	}
}

static struct file_operations eint_pir_fops = {
	.open = hc18xx_eint_pir_open,
	.release = hc18xx_eint_pir_close,
	.read = hc18xx_eint_pir_read,
	.write = hc18xx_eint_pir_write,
	.unlocked_ioctl = hc18xx_eint_pir_ioctl,
};

static int dev_register(struct eintc_pir_data *drv)
{
	int err;

	/* Allocate cdev Number */
	err = alloc_chrdev_region(&drv->pir_devt, 0, 1, DRV_NAME);

	if (err) {
		return -EBUSY;
	}

	/* Fill cdev Data Structure */
	cdev_init(&drv->cdev, &eint_pir_fops);
	drv->cdev.owner = THIS_MODULE;
	drv->cdev.ops = &eint_pir_fops;

	if (cdev_add(&drv->cdev, drv->pir_devt, 1)) {
		unregister_chrdev_region(drv->pir_devt, 1);
		return -EBUSY;
	}

	/* Generate Class */
	drv->pir_class = class_create(THIS_MODULE, DRV_NAME);

	if (IS_ERR(drv->pir_class)) {
		cdev_del(&drv->cdev);
		unregister_chrdev_region(drv->pir_devt, 1);
		return PTR_ERR(drv->pir_class);
	}

	/* Create Device Node in Sys File System */
	device_create(drv->pir_class, NULL, drv->pir_devt, NULL, DRV_NAME);

	return 0;
}

static int dev_unregister(struct eintc_pir_data *drv)
{
	device_destroy(drv->pir_class, drv->pir_devt);
	class_destroy(drv->pir_class);
	cdev_del(&drv->cdev);
	unregister_chrdev_region(drv->pir_devt, 1);

	return 0;
}

static irqreturn_t hc18xx_eintc_pir_irq_handler(int irq, void *d)
{
	struct eintc_pir_data *eintc_pir = (struct eintc_pir_data *)d;
	DBG("EIRQ[%d] / IRQ %d: Pir motor IRQ\n", eintc_pir->eirq, irq);
	complete(&pir_trigger);
	return IRQ_HANDLED;
}

static int hc18xx_eint_pir_probe(struct platform_device *pdev)
{
	struct eintc_pir_data *eintc_pir = NULL;
	struct device *dev;
	int ret;

	eintc_pir = devm_kzalloc(&pdev->dev, sizeof(*eintc_pir), GFP_KERNEL);
	if (!eintc_pir)
		return -ENOMEM;
	eintc_pir->dev = &pdev->dev;
	dev = eintc_pir->dev;

	eintc_pir->pir_timeout = JIFFIES_TIMEOUT;

	of_property_read_u32_array(dev->of_node, "gpio-pinctrl", &eintc_pir->gpio_sensitivity_id, 1);
	DBG("\t: gpio-pinctrl = %d\n", eintc_pir->gpio_sensitivity_id);
	of_property_read_u32_array(dev->of_node, "interrupts", &eintc_pir->eirq, 1);
	DBG("IRQ numbers:\n");
	eintc_pir->irq = irq_of_parse_and_map(dev->of_node, 0);
	DBG("\t: EIRQ[%d]: irq %d\n", eintc_pir->eirq, eintc_pir->irq);

	ret = devm_request_irq(dev, eintc_pir->irq, hc18xx_eintc_pir_irq_handler, IRQF_SHARED, DRV_NAME, eintc_pir);
	if (ret) {
		dev_err(dev, "Failed to request IRQ for EIRQ[%d]: Error %d\n", eintc_pir->eirq, ret);
		return -EINVAL;
	}

	ret = dev_register(eintc_pir);

	if (ret) {
		dev_err(dev, "Unable to register chdev !\n");
		return -EINVAL;
	}

	platform_set_drvdata(pdev, eintc_pir);
	DBG("EIRQ pir module probed.\n");
	return 0;
}

static int hc18xx_eint_pir_remove(struct platform_device *pdev)
{
	struct eintc_pir_data *eintc_pir = platform_get_drvdata(pdev);
	platform_set_drvdata(pdev, NULL);
	dev_unregister(eintc_pir);
	devm_kfree(&pdev->dev, eintc_pir);
	return 0;
}

static const struct of_device_id hc18xx_eintc_pir_dt_ids[] = {
	{ .compatible = "augentix,eirq-pir" },
	{},
};
MODULE_DEVICE_TABLE(of, hc18xx_eintc_pir_dt_ids);

static struct platform_driver hc18xx_eintc_pir_driver = {
	.probe = hc18xx_eint_pir_probe,
	.remove = hc18xx_eint_pir_remove,
	.driver =
	        {
	                .owner = THIS_MODULE,
	                .name = DRV_NAME,
	                .of_match_table = hc18xx_eintc_pir_dt_ids,
	        },
};
module_platform_driver(hc18xx_eintc_pir_driver);

MODULE_DESCRIPTION("EIRQ pir module");
MODULE_AUTHOR("<louis.yang@augentix.com>");
MODULE_LICENSE("GPL");
