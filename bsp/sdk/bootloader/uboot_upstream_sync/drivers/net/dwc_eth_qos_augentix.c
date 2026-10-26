// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2026 Augentix Inc.
 *
 * Ported from drivers/net/dwc_eth_qos.c of the v2016.03 tree.
 */

#include <dm.h>
#include <env.h>
#include <net.h>
#include <phy.h>
#include <asm/gpio.h>
#include <linux/delay.h>
#include <linux/io.h>

#include "dwc_eth_qos.h"

/* EQOS_CFG is the second reg range, as linux_6.1.102 dwmac-augentix.h states. */
#define EPHY_INTF_SEL		0x00

/* Osaka encodes the interface in three bits; sapporo and kyoto in one. */
#if defined(CONFIG_AUGENTIX_SOC_OSAKA)
#define PHY_INTF_SEL_RGMII	0x1
#define PHY_INTF_SEL_RMII	0x4
#else
#define PHY_INTF_SEL_RMII	0x1
#endif

static int eqos_set_intf_mode(struct udevice *dev, void __iomem *cfg)
{
	struct eqos_priv *eqos = dev_get_priv(dev);
	u32 val;

	switch (eqos->config->interface(dev)) {
#if defined(CONFIG_AUGENTIX_SOC_OSAKA)
	case PHY_INTERFACE_MODE_RGMII:
	case PHY_INTERFACE_MODE_RGMII_ID:
	case PHY_INTERFACE_MODE_RGMII_RXID:
	case PHY_INTERFACE_MODE_RGMII_TXID:
		val = PHY_INTF_SEL_RGMII;
		break;
#endif
	case PHY_INTERFACE_MODE_RMII:
		val = PHY_INTF_SEL_RMII;
		break;
	default:
		return -EINVAL;
	}

	writel(val, cfg + EPHY_INTF_SEL);

	return 0;
}

static int eqos_start_resets_augentix(struct udevice *dev)
{
	struct eqos_priv *eqos = dev_get_priv(dev);
	void __iomem *cfg;

	cfg = dev_read_addr_index_ptr(dev, 1);
	if (!cfg)
		return -EINVAL;

	dm_gpio_set_value(&eqos->phy_reset_gpio, 0);
	mdelay(20);	/* reset hold time */
	dm_gpio_set_value(&eqos->phy_reset_gpio, 1);
	mdelay(150);	/* mdio ready after reset */

	return eqos_set_intf_mode(dev, cfg);
}

static int eqos_probe_resources_augentix(struct udevice *dev)
{
	struct eqos_priv *eqos = dev_get_priv(dev);
	int ret;

	ret = eqos_get_base_addr_dt(dev);
	if (ret)
		return ret;

	return gpio_request_by_name(dev, "phy-reset-gpios", 0,
				    &eqos->phy_reset_gpio, GPIOD_IS_OUT);
}

/* Inverted from the 0xF9 the v2016.03 driver wrote to us_tic_counter. */
static ulong eqos_get_tick_clk_rate_augentix(struct udevice *dev)
{
	return 250 * 1000000;
}

static int eqos_get_enetaddr_augentix(struct udevice *dev)
{
	struct eth_pdata *pdata = dev_get_plat(dev);

	/* eth_env_get_enetaddr() returns 1 on success, the ops contract 0. */
	if (!eth_env_get_enetaddr("ethaddr", pdata->enetaddr))
		return -EINVAL;

	return 0;
}

static struct eqos_ops eqos_augentix_ops = {
	.eqos_inval_desc = eqos_inval_desc_generic,
	.eqos_flush_desc = eqos_flush_desc_generic,
	.eqos_inval_buffer = eqos_inval_buffer_generic,
	.eqos_flush_buffer = eqos_flush_buffer_generic,
	.eqos_probe_resources = eqos_probe_resources_augentix,
	.eqos_remove_resources = eqos_null_ops,
	.eqos_start_resets = eqos_start_resets_augentix,
	.eqos_stop_resets = eqos_null_ops,
	.eqos_start_clks = eqos_null_ops,
	.eqos_stop_clks = eqos_null_ops,
	.eqos_calibrate_pads = eqos_null_ops,
	.eqos_disable_calibration = eqos_null_ops,
	.eqos_set_tx_clk_speed = eqos_null_ops,
	.eqos_get_enetaddr = eqos_get_enetaddr_augentix,
	.eqos_get_tick_clk_rate = eqos_get_tick_clk_rate_augentix,
};

struct eqos_config __maybe_unused eqos_augentix_sapporo_config = {
	.reg_access_always_ok = true,
	.mdio_wait = 20,
	.swr_wait = 50,
	.config_mac = EQOS_MAC_RXQ_CTRL0_RXQ0EN_ENABLED_DCB,
	.config_mac_mdio = EQOS_MAC_MDIO_ADDRESS_CR_250_300,
	.axi_bus_width = EQOS_AXI_WIDTH_64,
	.interface = dev_read_phy_mode,
	.ops = &eqos_augentix_ops,
};

struct eqos_config __maybe_unused eqos_augentix_kyoto_config = {
	.reg_access_always_ok = true,
	.mdio_wait = 20,
	.swr_wait = 50,
	.config_mac = EQOS_MAC_RXQ_CTRL0_RXQ0EN_ENABLED_DCB,
	.config_mac_mdio = EQOS_MAC_MDIO_ADDRESS_CR_250_300,
	.axi_bus_width = EQOS_AXI_WIDTH_64,
	.interface = dev_read_phy_mode,
	.ops = &eqos_augentix_ops,
};
