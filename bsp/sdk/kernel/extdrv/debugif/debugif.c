/*
 * AUGENTIX INC. - OPEN-SOURCE UNDER GPL LICENSE
 *
 * debugif.c - Tokyo debugging interface
 * Copyright 2018 ShihChieh Lin, Augentix Inc. <shihchieh.lin@augentix.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, incorporated herein by reference.
 *
 * * Brief: Tokyo debugging interface
 * *
 * * Author: ShihChieh Lin
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/clk.h>

#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_platform.h>

#include "debugif_internal.h"
#include "spi_hc18xx.h"

#define DRV_NAME "debugif"

/* Debugging GPIO interface */
extern int hc_trigger_gpio(int pin_id, int level);

struct debugif_dev {
	char *name;
	struct device *dev;
	struct clk *clk;
	void __iomem *regs;
	phys_addr_t paddr;
	size_t size;
};

static struct debugif_dev * g_debugif = NULL;

int debugif_writeb(uint8_t value)
{
	if (g_debugif == NULL) {
		pr_err("%s: [Error] debugif no assigned!\n", __func__);
		return -ENODEV;
	}

	return spi_writeb(g_debugif->regs, value);
}
EXPORT_SYMBOL_GPL(debugif_writeb);

static int debugif_hw_init(struct debugif_dev* debugif)
{
	spi_init_ssi(debugif->regs);
	dev_info(debugif->dev, "Debug interface initialized.\n");
	return 0;
}

static void debugif_hw_exit(struct debugif_dev* debugif)
{
	spi_shutdown(debugif->regs);
	return;
}

static int debugif_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct resource *res;
	struct device *dev = &pdev->dev;
	struct debugif_dev *debugif;

	debugif = devm_kzalloc(dev, sizeof(*debugif), GFP_KERNEL);
	if (!debugif)
		return -ENOMEM;
	debugif->dev = dev;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(dev, "No resource specified!\n");
		ret = -EINVAL;
		goto res_read_fail;
	}
	debugif->paddr = res->start;
	debugif->size = resource_size(res);
	debugif->regs = devm_ioremap_resource(dev, res);
	if (IS_ERR(debugif->regs)) {
		dev_err(dev, "Failed to map %s!\n", DRV_NAME);
		ret = PTR_ERR(debugif->regs);
		goto ioremap_fail;
	}

	debugif->clk = devm_clk_get(dev, NULL);
	if (!debugif->clk) {
		ret = -ENODEV;
		goto clk_get_error;
	}
	clk_prepare_enable(debugif->clk);

	debugif_hw_init(debugif);

	g_debugif = debugif;
	platform_set_drvdata(pdev, g_debugif);
	return 0;

clk_get_error:
ioremap_fail:
res_read_fail:
	devm_kfree(&pdev->dev, debugif);
	debugif = NULL;
	return ret;
}

static int debugif_remove(struct platform_device *pdev)
{
	struct debugif_dev *debugif = platform_get_drvdata(pdev);

	debugif_hw_exit(debugif);
	debugif->regs = NULL;
	clk_disable_unprepare(debugif->clk);

	platform_set_drvdata(pdev, NULL);
	devm_kfree(&pdev->dev, debugif);
	g_debugif = NULL;
	debugif = NULL;
	return 0;
}

static const struct of_device_id debugif_of_ids[] = {
	{ .compatible = "augentix,debugif", },
	{ /* end of table */ },
};
MODULE_DEVICE_TABLE(of, debugif_of_ids);

static struct platform_driver debugif_driver = {
	.probe  = debugif_probe,
	.remove = debugif_remove,
	.driver = {
		.name = DRV_NAME,
		.of_match_table = debugif_of_ids,
	},
};
module_platform_driver(debugif_driver);

MODULE_DESCRIPTION("");
MODULE_AUTHOR("ShihChieh Lin, Augentix Inc. <shihchieh.lin@augentix.com>");
MODULE_LICENSE("GPL");
