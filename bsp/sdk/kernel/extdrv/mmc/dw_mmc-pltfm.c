/*
 * Synopsys DesignWare Multimedia Card Interface driver
 *
 * Copyright (C) 2009 NXP Semiconductors
 * Copyright (C) 2009, 2010 Imagination Technologies Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/err.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/delay.h>

#include <linux/pinctrl/consumer.h>
#include <linux/gpio/consumer.h>

#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/mmc/host.h>
#include <linux/mmc/mmc.h>
#include <linux/mmc/dw_mmc.h>
#include <linux/of.h>
#include <linux/clk.h>

#include "dw_mmc.h"
#include "dw_mmc-pltfm.h"

#define GPIO_HIGH_AT_PROBE "highatprobe"
#define GPIO_SD_PWR_EN "sdpwren"

#define SDC_CFG_CORE_CKEN 0x0
#define SDC_CFG_PHASE_SHIFT 0x4

#define ENABLE 0x1
#define DISABLE 0x0
#define DEGREE_0 0
#define DEGREE_90 1
#define DEGREE_180 2
#define DEGREE_270 3
#define SPL_PHASE_OFFSET 0
#define DRV_PHASE_OFFSET 8

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
static void __iomem *g_sdcgpi_base;
#endif

static DEFINE_MUTEX(sdc_shared_lock);

int dw_mci_init(struct dw_mci *host)
{
	//printk("dw_mci_init...for IOMUX init\n ");
	host->pdata->quirks |= DW_MCI_QUIRK_BROKEN_DTO;
	return 0;
}

static void dw_mci_pltfm_prepare_command(struct dw_mci *host, u32 *cmdr)
{
	*cmdr |= SDMMC_CMD_USE_HOLD_REG;
}

static const struct dw_mci_drv_data socfpga_drv_data = {
	.prepare_command	= dw_mci_pltfm_prepare_command,
};

static const struct dw_mci_drv_data pistachio_drv_data = {
	.prepare_command	= dw_mci_pltfm_prepare_command,
};

static const struct dw_mci_drv_data auge_sdc_drv_data = {
    .init               = dw_mci_init,
	.prepare_command	= dw_mci_pltfm_prepare_command,
};

/* Initialize AGTX SDC config */
int agtx_sdc_config_init(struct platform_device *pdev)
{
	void __iomem *base;
	struct resource *regs;

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	base = devm_ioremap_resource(&pdev->dev, regs);
	if (IS_ERR(base))
		return PTR_ERR(base);

	/* SDC_CORE_CG */
	writel_relaxed(ENABLE, base + SDC_CFG_CORE_CKEN); // enable SDC Core clock

	/* SDC_CLK_PHASE_SHIFT_CTRL */
	writel_relaxed(DEGREE_90 << DRV_PHASE_OFFSET, base + SDC_CFG_PHASE_SHIFT); // set drive phase 90 degree

	return 0;
}

int dw_mci_pltfm_register(struct platform_device *pdev,
			  const struct dw_mci_drv_data *drv_data)
{
	struct dw_mci *host;
	struct resource	*regs;
	int ret;
	int msec = 0;
	struct gpio_desc *gpio_highatprobe;
	struct device_node *np = pdev->dev.of_node;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	struct resource *gpioc_regs;
	int sdc_cd, sdc_wp;
	u32 t_reg;
#endif

	host = devm_kzalloc(&pdev->dev, sizeof(struct dw_mci), GFP_KERNEL);
	if (!host)
		return -ENOMEM;

	host->irq = platform_get_irq(pdev, 0);
	if (host->irq < 0)
		return host->irq;

	host->drv_data = drv_data;
	host->dev = &pdev->dev;
	host->irq_flags = 0;
	host->pdata = pdev->dev.platform_data;

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	host->regs = devm_ioremap_resource(&pdev->dev, regs);
	if (IS_ERR(host->regs))
		return PTR_ERR(host->regs);

	/* Get registers' physical base address */
	host->phy_regs = regs->start;
	//printk("host->phy_regs...%11x\n ",host->phy_regs);

	gpio_highatprobe = devm_gpiod_get(host->dev, GPIO_HIGH_AT_PROBE, GPIOD_OUT_LOW);
	if (!IS_ERR(gpio_highatprobe)) {
		printk("Import GPIO_HIGH_AT_PROBE solution\n");
		gpiod_set_value(gpio_highatprobe, 1);
		if (!of_property_read_u32(pdev->dev.of_node, "delay-after-gpioh", &msec)) {
			printk("Request delay time for %d ms after gpio pull high\n", msec);
			mdelay(msec);
		}
	}

	host->gpio = devm_gpiod_get(host->dev, GPIO_SD_PWR_EN, GPIOD_IN);
	if (!IS_ERR(host->gpio)) {
		printk("Import GPIO_SD_PWR_EN solution\n");
	}

	if (strcmp(np->name, "sdc") == 0) {
		host->dev->init_name = "SDC0";
	} else if (strcmp(np->name, "sdc1_p0") == 0) {
		host->dev->init_name = "SDC1P0";
	} else if (strcmp(np->name, "sdc1_p1") == 0) {
		host->dev->init_name = "SDC1P1";
	}

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	mutex_lock(&sdc_shared_lock);
	if (!g_sdcgpi_base) {
		gpioc_regs = platform_get_resource(pdev, IORESOURCE_MEM, 2);
		if (!gpioc_regs) {
			mutex_unlock(&sdc_shared_lock);
			dev_err(&pdev->dev, "no gpioc resource\n");
			return -ENODEV;
		}
		g_sdcgpi_base = devm_ioremap_resource(&pdev->dev, gpioc_regs);
		if (IS_ERR(g_sdcgpi_base)) {
			void __iomem *err = g_sdcgpi_base;
			g_sdcgpi_base = NULL;
			mutex_unlock(&sdc_shared_lock);
			return PTR_ERR(err);
		}
	}
	mutex_unlock(&sdc_shared_lock);

	if (of_property_read_u32(pdev->dev.of_node, "sdc-cd-gpio-num", &sdc_cd)) {
		dev_warn(&pdev->dev, "sdc-cd-gpio-num undefined, use default 63\n");
		sdc_cd = 63;
	}

	if (of_property_read_u32(pdev->dev.of_node, "sdc-wp-gpio-num", &sdc_wp)) {
		dev_warn(&pdev->dev, "sdc-wp-gpio-num undefined, use default 63\n");
		sdc_wp = 63;
	}

	mutex_lock(&sdc_shared_lock);
	t_reg = readl_relaxed(g_sdcgpi_base);
	if (strcmp(host->dev->init_name, "SDC0") == 0) {
		t_reg = (t_reg & 0xffff0000) | (sdc_cd << 8) | sdc_wp;
	} else {
		t_reg = (t_reg & 0x0000ffff) | (sdc_cd << 24) | (sdc_wp << 16);
	}
	writel_relaxed(t_reg, g_sdcgpi_base);
	mutex_unlock(&sdc_shared_lock);
#endif

	platform_set_drvdata(pdev, host);

	ret = agtx_sdc_config_init(pdev);
	if (ret)
	{
		dev_err(&pdev->dev, "Failed to initialize AGTX SDC node\n");
		return ret;
	}

	return dw_mci_probe(host);
}
EXPORT_SYMBOL_GPL(dw_mci_pltfm_register);

#ifdef CONFIG_PM_SLEEP
/*
 * TODO: we should probably disable the clock to the card in the suspend path.
 */
static int dw_mci_pltfm_suspend(struct device *dev)
{
	struct dw_mci *host = dev_get_drvdata(dev);

	return dw_mci_suspend(host);
}

static int dw_mci_pltfm_resume(struct device *dev)
{
	struct dw_mci *host = dev_get_drvdata(dev);

	return dw_mci_resume(host);
}
#endif /* CONFIG_PM_SLEEP */

SIMPLE_DEV_PM_OPS(dw_mci_pltfm_pmops, dw_mci_pltfm_suspend, dw_mci_pltfm_resume);
EXPORT_SYMBOL_GPL(dw_mci_pltfm_pmops);


static const struct of_device_id dw_mci_pltfm_match[] = {
	{ .compatible = "snps,dw-mshc", },
	{ .compatible = "altr,socfpga-dw-mshc",
		.data = &socfpga_drv_data },
	{ .compatible = "img,pistachio-dw-mshc",
		.data = &pistachio_drv_data },
	{ .compatible = "augentix,sdc",
		.data = &auge_sdc_drv_data },
	{},
};
MODULE_DEVICE_TABLE(of, dw_mci_pltfm_match);

static int dw_mci_pltfm_probe(struct platform_device *pdev)
{
	const struct dw_mci_drv_data *drv_data = NULL;
	const struct of_device_id *match;

	if (pdev->dev.of_node) {
		match = of_match_node(dw_mci_pltfm_match, pdev->dev.of_node);
		drv_data = match->data;
	}

	return dw_mci_pltfm_register(pdev, drv_data);
}

int dw_mci_pltfm_remove(struct platform_device *pdev)
{
	struct dw_mci *host = platform_get_drvdata(pdev);

	dw_mci_remove(host);
	return 0;
}
EXPORT_SYMBOL_GPL(dw_mci_pltfm_remove);

static struct platform_driver dw_mci_pltfm_driver = {
	.probe		= dw_mci_pltfm_probe,
	.remove		= dw_mci_pltfm_remove,
	.driver		= {
		.name		= "dw_mmc",
		.of_match_table	= dw_mci_pltfm_match,
		.pm		= &dw_mci_pltfm_pmops,
	},
};

module_platform_driver(dw_mci_pltfm_driver);

MODULE_DESCRIPTION("DW Multimedia Card Interface driver");
MODULE_AUTHOR("NXP Semiconductor VietNam");
MODULE_AUTHOR("Imagination Technologies Ltd");
MODULE_LICENSE("GPL v2");
