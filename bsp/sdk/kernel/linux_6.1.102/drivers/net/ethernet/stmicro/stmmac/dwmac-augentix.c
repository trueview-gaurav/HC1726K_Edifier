// SPDX-License-Identifier: GPL-2.0-only
/*
 * dwmac-augentix.c - Augentix DWMAC Specific Glue Layer
 *
 * Copyright (C) 2025 Augentix Inc.
 *
 * This driver supports Augentix SoC EMAC controllers (dwmac-5.10a/dwmac):
 * - Osaka: RGMII (1000/100/10 Mbps) and RMII (100/10 Mbps)
 *
 * Hardware Features:
 * - EMAC Controller: Synopsys DWC Ethernet QoS v5.10a (Osaka
 * - RX FIFO: 2048 bytes
 * - TX FIFO: 4096 bytes
 * - Pinmux: Configured in u-boot-spl stage
 *
 * Author: Will Chuang <will.chuang@augentix.com>
 */

#include <linux/clk.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_net.h>
#include <linux/phy.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/stmmac.h>
#include <linux/io.h>
#include <linux/gpio/consumer.h>

#include "stmmac_platform.h"
#include "dwmac-augentix.h"

struct augentix_dwmac_ops {
	u32 addr_width;
	int (*set_intf_mode)(struct plat_stmmacenet_data *plat_dat);
};

struct augentix_priv_data {
	struct device *dev;
	void __iomem *eqos_cfg_base; /* EQOS_CFG registers */

	const struct augentix_dwmac_ops *ops;
	struct plat_stmmacenet_data *plat_dat;
#ifndef CONFIG_FPGA
	struct clk *emac_rx_clk;
#endif
};

/**
 * augentix_set_intf_mode - Configure EMAC interface mode
 * @plat_dat: Platform data structure
 *
 * Configures the PHY interface mode (RGMII/RMII) based on platform.
 * Uses EPHY_INTF_SEL register from EQOS_CFG base.
 *
 * Return: 0 on success, negative error code on failure
 */
static int augentix_set_intf_mode(struct plat_stmmacenet_data *plat_dat)
{
	struct augentix_priv_data *dwmac = plat_dat->bsp_priv;
	u32 intf_sel_val;

#if defined(CONFIG_OSAKA)
	/* Osaka: Support RGMII and RMII */
	switch (plat_dat->interface) {
	case PHY_INTERFACE_MODE_RGMII:
	case PHY_INTERFACE_MODE_RGMII_ID:
	case PHY_INTERFACE_MODE_RGMII_RXID:
	case PHY_INTERFACE_MODE_RGMII_TXID:
		intf_sel_val = PHY_INTF_SEL_RGMII;
		break;

	case PHY_INTERFACE_MODE_RMII:
		intf_sel_val = PHY_INTF_SEL_RMII;
		break;

	default:
		dev_err(dwmac->dev, "Unsupported interface mode %d\n", plat_dat->interface);
		return -EINVAL;
	}

	writel(intf_sel_val, dwmac->eqos_cfg_base + EPHY_INTF_SEL);
#endif

	return 0;
}

/**
 * augentix_dwmac_clks_config - Clock configuration callback
 * @priv: Private data structure
 * @enabled: true to enable, false to disable
 *
 * RMII mode: Manages emac_rx_clk for RX sampling (any chip)
 * RGMII mode: RX/TX clocks are provided by PHY XTAL, no action needed
 *
 * Return: 0 on success, negative error code on failure
 */
static int augentix_dwmac_clks_config(void *priv, bool enabled)
{
	struct augentix_priv_data *dwmac = priv;
	int ret = 0;

#ifndef CONFIG_FPGA
	/* RMII mode requires emac_rx_clk management for any chip */
	if (!IS_ERR_OR_NULL(dwmac->emac_rx_clk)) {
		if (enabled) {
			ret = clk_prepare_enable(dwmac->emac_rx_clk);
			if (ret)
				dev_err(dwmac->dev, "failed to enable emac_rx_clk: %d\n", ret);
		} else {
			clk_disable_unprepare(dwmac->emac_rx_clk);
		}
	}
#endif

	return ret;
}

/**
 * augentix_dwmac_init - Initialize EMAC controller
 * @pdev: Platform device
 * @priv: Private data structure
 *
 * Return: 0 on success, negative error code on failure
 */
static int augentix_dwmac_init(struct platform_device *pdev, void *priv)
{
	struct augentix_priv_data *dwmac = priv;
	struct plat_stmmacenet_data *plat_dat = dwmac->plat_dat;
	struct gpio_desc *phy_rst = NULL;
	int ret;

	if (dwmac->ops->set_intf_mode) {
		ret = dwmac->ops->set_intf_mode(plat_dat);
		if (ret)
			return ret;
	}

	phy_rst = devm_gpiod_get(&pdev->dev, "phy-reset", GPIOD_OUT_LOW);
	if (IS_ERR(phy_rst)) {
		dev_err(&pdev->dev, "Cannot get phy rst, aborting.\n");
		return -EINVAL;
	}

	mdelay(10); //assert reset
	gpiod_direction_output(phy_rst, 1);
	mdelay(10); //deassert reset

	return 0;
}

/**
 * augentix_dwmac_exit - Clean up EMAC controller
 * @pdev: Platform device
 * @priv: Private data structure
 */
static void augentix_dwmac_exit(struct platform_device *pdev, void *priv)
{
	/* Nothing to do for now */
}

/**
 * augentix_dwmac_fix_speed - Adjust clock speed based on link speed
 * @priv: Private data structure
 * @speed: Link speed (SPEED_1000, SPEED_100, SPEED_10)
 *
 * RGMII Mode (Osaka only):
 * - RX/TX clocks are automatically provided by PHY XTAL based on negotiated speed
 * - PHY generates: 125MHz (1000M), 25MHz (100M), 2.5MHz (10M)
 * - No software configuration needed
 *
 * RMII Mode (any chip):
 * - Uses 50MHz reference clock from board (fixed)
 * - Adjusts emac_rx_clk for RX sampling: 25MHz (100M), 2.5MHz (10M)
 * - Determined by device tree phy-mode, not chip type
 */
static void augentix_dwmac_fix_speed(void *priv, unsigned int speed)
{
	struct augentix_priv_data *dwmac = priv;
	struct plat_stmmacenet_data *plat_dat = dwmac->plat_dat;
	unsigned long rate;
	/* int err; */ /* Unused in FPGA environment */

#ifndef CONFIG_OSAKA
	if (plat_dat->interface == PHY_INTERFACE_MODE_RGMII || plat_dat->interface == PHY_INTERFACE_MODE_RGMII_ID ||
	    plat_dat->interface == PHY_INTERFACE_MODE_RGMII_RXID ||
	    plat_dat->interface == PHY_INTERFACE_MODE_RGMII_TXID)
		return;
#endif

	switch (speed) {
#ifdef CONFIG_OSAKA
	case SPEED_1000:
		rate = AUGENTIX_CLK_1000M;
		break;
#endif
	case SPEED_100:
		rate = AUGENTIX_CLK_100M;
		break;
	case SPEED_10:
		rate = AUGENTIX_CLK_10M;
		break;
	default:
		dev_err(dwmac->dev, "invalid speed %u\n", speed);
		return;
	}

#ifdef CONFIG_OSAKA
	/*
	 * FPGA Environment: TXC = RXC (routed internally)
	 * Clock adjustment not needed - PHY provides correct frequency automatically
	 * Uncomment below for ASIC environment if TX clock needs software adjustment
	 */
	/* err = clk_set_rate(dwmac->clk_tx, rate); */
	/* if (err < 0) */
	/*	dev_err(dwmac->dev, "failed to set tx rate %lu\n", rate); */

	dev_dbg(dwmac->dev, "Link speed %u Mbps, expected clock: %lu Hz (FPGA: auto-adjusted by PHY)\n", speed, rate);
#endif

	return;
}

/**
 * augentix_dwmac_parse_dt - Parse device tree properties
 * @dwmac: Private data structure
 * @dev: Device structure
 *
 * Return: 0 on success, negative error code on failure
 */
static int augentix_dwmac_parse_dt(struct augentix_priv_data *dwmac, struct device *dev)
{
	struct resource *res;
	struct platform_device *pdev = to_platform_device(dev);

	/* Get EQOS_CFG register base */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	if (!res) {
		dev_err(dev, "failed to get EQOS_CFG register resource\n");
		return -ENODEV;
	}

	dwmac->eqos_cfg_base = devm_ioremap_resource(dev, res);
	if (IS_ERR(dwmac->eqos_cfg_base)) {
		dev_err(dev, "failed to map EQOS_CFG registers\n");
		return PTR_ERR(dwmac->eqos_cfg_base);
	}

#ifndef CONFIG_FPGA
	dwmac->emac_rx_clk = devm_clk_get(dev, "emac_rx_clk");
	if (IS_ERR(dwmac->emac_rx_clk)) {
		dev_warn(dev, "emac_rx_clk not found in DT, RMII speed adjustment disabled\n");
		/* Non-fatal: Continue without clock adjustment capability */
	} else {
		unsigned long rate = clk_get_rate(dwmac->emac_rx_clk);
		dev_info(dev, "[CLK] emac_rx_clk acquired: %lu Hz (for RMII speed adjustment)\n", rate);
	}
#endif

	return 0;
}

/**
 * augentix_dwmac_probe - Probe function for Augentix DWMAC driver
 * @pdev: Platform device
 *
 * Return: 0 on success, negative error code on failure
 */
static int augentix_dwmac_probe(struct platform_device *pdev)
{
	struct plat_stmmacenet_data *plat_dat;
	struct stmmac_resources stmmac_res;
	struct augentix_priv_data *dwmac;
	const struct augentix_dwmac_ops *data;
	int ret;

	ret = stmmac_get_platform_resources(pdev, &stmmac_res);
	if (ret)
		return ret;

	dwmac = devm_kzalloc(&pdev->dev, sizeof(*dwmac), GFP_KERNEL);
	if (!dwmac)
		return -ENOMEM;

	plat_dat = stmmac_probe_config_dt(pdev, stmmac_res.mac);
	if (IS_ERR(plat_dat))
		return PTR_ERR(plat_dat);

	data = of_device_get_match_data(&pdev->dev);
	if (!data) {
		dev_err(&pdev->dev, "failed to get match data\n");
		ret = -EINVAL;
		goto err_match_data;
	}

	dwmac->ops = data;
	dwmac->dev = &pdev->dev;

	ret = augentix_dwmac_parse_dt(dwmac, &pdev->dev);
	if (ret) {
		dev_err(&pdev->dev, "failed to parse device tree: %d\n", ret);
		goto err_parse_dt;
	}

	/* Configure platform data */
	plat_dat->host_dma_width = dwmac->ops->addr_width;
	plat_dat->init = augentix_dwmac_init;
	plat_dat->exit = augentix_dwmac_exit;
	plat_dat->clks_config = augentix_dwmac_clks_config;
	plat_dat->fix_mac_speed = augentix_dwmac_fix_speed;
	plat_dat->bsp_priv = dwmac;
	dwmac->plat_dat = plat_dat;

	/* Set Augentix FIFO sizes */
	plat_dat->rx_fifo_size = AUGENTIX_RX_FIFO_SIZE;
	plat_dat->tx_fifo_size = AUGENTIX_TX_FIFO_SIZE;

	/* Disable SPH feature for augentix */
	plat_dat->sph_disable = 1;

	/* Enable clocks */
	ret = augentix_dwmac_clks_config(dwmac, true);
	if (ret)
		goto err_clks_config;

	/* Initialize EMAC controller */
	ret = augentix_dwmac_init(pdev, dwmac);
	if (ret)
		goto err_dwmac_init;

	/* Probe STMMAC driver */
	ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
	if (ret)
		goto err_drv_probe;

	return 0;

err_drv_probe:
	augentix_dwmac_exit(pdev, plat_dat->bsp_priv);
err_dwmac_init:
	augentix_dwmac_clks_config(dwmac, false);
err_clks_config:
err_parse_dt:
err_match_data:
	stmmac_remove_config_dt(pdev, plat_dat);
	return ret;
}

static struct augentix_dwmac_ops augentix_dwmac_data = {
	.addr_width = 32,
	.set_intf_mode = augentix_set_intf_mode,
};

/* Device tree compatible strings */
static const struct of_device_id augentix_dwmac_match[] = {
#if defined(CONFIG_OSAKA)
	{ .compatible = "augentix,osaka-dwmac", .data = &augentix_dwmac_data },
#endif
	{}
};
MODULE_DEVICE_TABLE(of, augentix_dwmac_match);

/* Platform driver structure */
static struct platform_driver augentix_dwmac_driver = {
	.probe  = augentix_dwmac_probe,
	.remove = stmmac_pltfr_remove,
	.driver = {
		.name		= "augentix-dwmac",
		.pm		= &stmmac_pltfr_pm_ops,
		.of_match_table	= augentix_dwmac_match,
	},
};
module_platform_driver(augentix_dwmac_driver);

MODULE_AUTHOR("Will Chuang <will.chuang@augentix.com>");
MODULE_DESCRIPTION("Augentix DWMAC Specific Glue Layer");
MODULE_LICENSE("GPL");
