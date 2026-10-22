// SPDX-License-Identifier: GPL-2.0-only
/*
* Copyright (c) 2015-2025 Augentix Inc. All rights reserved.
*/

#include <linux/module.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/platform_device.h>

#include <linux/interrupt.h>

#include <linux/slab.h>

#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_device.h>

#define DRV_NAME "eint_test"

#define EINTC_DEBUG

#ifdef EINTC_DEBUG
#define DBG(fmt, args...)                                                                                              \
	do {                                                                                                           \
		printk("[EIRQ_TEST] (%d, %s) " fmt, __LINE__, __func__, ##args);                                       \
	} while (0)
#else
#define DBG(fmt, args...)                                                                                              \
	do {                                                                                                           \
		;                                                                                                      \
	} while (0)
#endif /* EINTC_DEBUG */

#define IRQ_NUM 2
struct eintc_test_data {
	//void __iomem *base;
	uint32_t eirq[IRQ_NUM]; /* Index of actual EIRQ submodule */
	int irq[IRQ_NUM]; /* Linux IRQ number of each EIRQ submodule */
	struct device *dev;
};

static irqreturn_t eintc_test_vert_irq_handler(int irq, void *d)
{
	struct eintc_test_data *eintc_test = (struct eintc_test_data *)d;
	DBG("EIRQ[%d] / IRQ %d: Vertical motor IRQ\n", eintc_test->eirq[0], irq);
	return IRQ_HANDLED;
}

static irqreturn_t eintc_test_hori_irq_handler(int irq, void *d)
{
	struct eintc_test_data *eintc_test = (struct eintc_test_data *)d;
	DBG("EIRQ[%d] / IRQ %d: Horizontal motor IRQ\n", eintc_test->eirq[1], irq);
	return IRQ_HANDLED;
}

static int eint_test_probe(struct platform_device *pdev)
{
	struct eintc_test_data *eintc_test = NULL;
	//struct resource *res;
	struct device *dev;
	int i, ret;

	eintc_test = devm_kzalloc(&pdev->dev, sizeof(*eintc_test), GFP_KERNEL);
	if (!eintc_test)
		return -ENOMEM;
	eintc_test->dev = &pdev->dev;
	dev = eintc_test->dev;

	/*
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	eintc_test->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(eintc_test->base)) {
		return PTR_ERR(eintc_test->base);
	}
	*/

	of_property_read_u32_array(dev->of_node, "interrupts", eintc_test->eirq, IRQ_NUM);
	DBG("IRQ numbers:\n");
	for (i = 0; i < IRQ_NUM; ++i) {
		eintc_test->irq[i] = irq_of_parse_and_map(dev->of_node, i);
		DBG("\t%d: EIRQ[%d]: irq %d\n", i, eintc_test->eirq[i], eintc_test->irq[i]);
	}
	ret = devm_request_irq(dev, eintc_test->irq[0], eintc_test_vert_irq_handler, IRQF_SHARED, DRV_NAME, eintc_test);
	if (ret) {
		dev_err(dev, "Failed to request IRQ for EIRQ[%d]: Error %d\n", eintc_test->eirq[0], ret);
		return -EINVAL;
	}
	ret = devm_request_irq(dev, eintc_test->irq[1], eintc_test_hori_irq_handler, IRQF_SHARED, DRV_NAME, eintc_test);
	if (ret) {
		dev_err(dev, "Failed to request IRQ for EIRQ[%d]: Error %d\n", eintc_test->eirq[1], ret);
		return -EINVAL;
	}

	platform_set_drvdata(pdev, eintc_test);
	DBG("EIRQ test module probed.\n");
	return 0;
}

static int eint_test_remove(struct platform_device *pdev)
{
	struct eintc_test_data *eintc_test = platform_get_drvdata(pdev);
	devm_kfree(&pdev->dev, eintc_test);
	platform_set_drvdata(pdev, NULL);
	return 0;
}

static const struct of_device_id eintc_test_dt_ids[] = {
	{.compatible = "augentix,eirq-test" },
	{},
};
MODULE_DEVICE_TABLE(of, eintc_test_dt_ids);

static struct platform_driver eintc_test_driver = {
	.probe = eint_test_probe,
	.remove = eint_test_remove,
	.driver =
	        {
	                .owner = THIS_MODULE,
	                .name = DRV_NAME,
	                .of_match_table = eintc_test_dt_ids,
	        },
};
module_platform_driver(eintc_test_driver);

MODULE_DESCRIPTION("EIRQ test module");
MODULE_AUTHOR("<shihchieh.lin@augentix.com>");
MODULE_LICENSE("GPL");
