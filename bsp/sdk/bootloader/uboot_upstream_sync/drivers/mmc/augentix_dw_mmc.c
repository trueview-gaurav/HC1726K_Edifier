// SPDX-License-Identifier: GPL-2.0+
/*
 * Augentix SDC host, a Synopsys DesignWare Mobile Storage instance.
 *
 * Copyright (C) 2026 Augentix Inc.
 */

#include <dm.h>
#include <dwmmc.h>
#include <errno.h>
#include <malloc.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <dm/device_compat.h>

#define SDC_CFG_CORE_CKEN	0x0
#define SDC_CFG_PHASE_SHIFT	0x4

#define DEGREE_90		1
#define DRV_PHASE_OFFSET	8

#define SDC_GPI_CD_SHIFT	8
#define SDC_GPI_SLOT0_MASK	0xffff0000
#define SDC_GPI_UNROUTED	63

#define CLOCK_MIN		400000

struct augentix_dwmmc_plat {
	struct mmc_config	cfg;
	struct mmc		mmc;
};

struct augentix_dwmmc_priv {
	struct dwmci_host	host;
	void __iomem		*cfg_base;
	void __iomem		*gpi_base;
	u32			cd_pin;
	u32			wp_pin;
	u32			f_max;
	struct gpio_desc	pwr_gpio;
};

static void augentix_dwmmc_board_init(struct dwmci_host *host)
{
	struct augentix_dwmmc_priv *priv =
		container_of(host, struct augentix_dwmmc_priv, host);
	u32 reg;

	writel(1, priv->cfg_base + SDC_CFG_CORE_CKEN);
	writel(DEGREE_90 << DRV_PHASE_OFFSET,
	       priv->cfg_base + SDC_CFG_PHASE_SHIFT);

	/* The GPI pin-select mux is a Sapporo register. Kyoto's gpioc bank
	 * has no counterpart, so a node with no third range has nothing to
	 * route rather than a missing one.
	 */
	if (priv->gpi_base) {
		reg = readl(priv->gpi_base);
		reg = (reg & SDC_GPI_SLOT0_MASK) | (priv->cd_pin << SDC_GPI_CD_SHIFT) | priv->wp_pin;
		writel(reg, priv->gpi_base);
	}

	if (dm_gpio_is_valid(&priv->pwr_gpio))
		dm_gpio_set_value(&priv->pwr_gpio, 1);
}

static int augentix_dwmmc_of_to_plat(struct udevice *dev)
{
	struct augentix_dwmmc_priv *priv = dev_get_priv(dev);
	struct dwmci_host *host = &priv->host;
	u32 fifo_depth;

	host->ioaddr = dev_read_addr_index_ptr(dev, 0);
	priv->cfg_base = dev_read_addr_index_ptr(dev, 1);
	priv->gpi_base = dev_read_addr_index_ptr(dev, 2);
	if (!host->ioaddr || !priv->cfg_base)
		return -EINVAL;

	if (!dev_read_u32(dev, "fifo-depth", &fifo_depth))
		host->fifo_depth = fifo_depth;

	host->buswidth = dev_read_u32_default(dev, "bus-width", 4);
	if (host->buswidth != 1 && host->buswidth != 4)
		return -EINVAL;

	host->bus_hz = dev_read_u32_default(dev, "clock-frequency", 0);
	if (host->bus_hz < CLOCK_MIN)
		return -EINVAL;

	priv->f_max = dev_read_u32_default(dev, "max-frequency", host->bus_hz);
	if (priv->f_max < CLOCK_MIN)
		return -EINVAL;

	priv->cd_pin = dev_read_u32_default(dev, "sdc-cd-gpio-num",
					    SDC_GPI_UNROUTED);
	priv->wp_pin = dev_read_u32_default(dev, "sdc-wp-gpio-num",
					    SDC_GPI_UNROUTED);

	gpio_request_by_name(dev, "sdpwren-gpios", 0, &priv->pwr_gpio,
			     GPIOD_IS_OUT);

	host->fifo_mode = dev_read_bool(dev, "fifo-mode");
	host->name = dev->name;
	host->dev_index = 0;
	host->board_init = augentix_dwmmc_board_init;
	host->priv = priv;

	return 0;
}

static int augentix_dwmmc_probe(struct udevice *dev)
{
	struct augentix_dwmmc_plat *plat = dev_get_plat(dev);
	struct mmc_uclass_priv *upriv = dev_get_uclass_priv(dev);
	struct augentix_dwmmc_priv *priv = dev_get_priv(dev);
	struct dwmci_host *host = &priv->host;

	dwmci_setup_cfg(&plat->cfg, host, priv->f_max, CLOCK_MIN);
	host->mmc = &plat->mmc;
	host->mmc->priv = host;
	host->mmc->dev = dev;
	upriv->mmc = host->mmc;

	return dwmci_probe(dev);
}

static int augentix_dwmmc_bind(struct udevice *dev)
{
	struct augentix_dwmmc_plat *plat = dev_get_plat(dev);

	return dwmci_bind(dev, &plat->mmc, &plat->cfg);
}

static const struct udevice_id augentix_dwmmc_ids[] = {
	{ .compatible = "augentix,sdc" },
	{ }
};

U_BOOT_DRIVER(augentix_dwmmc) = {
	.name		= "augentix_dw_mmc",
	.id		= UCLASS_MMC,
	.of_match	= augentix_dwmmc_ids,
	.of_to_plat	= augentix_dwmmc_of_to_plat,
	.ops		= &dm_dwmci_ops,
	.bind		= augentix_dwmmc_bind,
	.probe		= augentix_dwmmc_probe,
	.priv_auto	= sizeof(struct augentix_dwmmc_priv),
	.plat_auto	= sizeof(struct augentix_dwmmc_plat),
};
