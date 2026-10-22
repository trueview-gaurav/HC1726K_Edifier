/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * dwmac-augentix.h - Augentix DWMAC Glue Layer Header
 *
 * Copyright (C) 2025 Augentix Inc.
 *
 * Supports both Sapporo (RMII only) and Osaka (RGMII/RMII) SoCs
 *
 * Author: Will Chuang <will.chuang@augentix.com>
 */

#ifndef __DWMAC_AUGENTIX_H__
#define __DWMAC_AUGENTIX_H__

/* EQOS_CFG Register Offsets (from CSR specification)
 * Base addresses defined in device tree:
 *   reg = <EMAC_QOS_CONTROLLER_BASE 0x4000>, <EMAC_QOS_CFG_BASE 0x50>;
 */
#define EPHY_INTF_SEL 0x0000
#define AXI_LP_ENTER 0x0004
#define AXI_LP_EXIT 0x0008
#define AXI_LP_AUTO 0x000C
#define AXI_LP_STATUS 0x0010
#define CFG_IRQ_STA_0 0x0014
#define CFG_IRQ_STA_1 0x0018
#define CFG_IRQ_MSK_0 0x001C
#define CFG_IRQ_MSK_1 0x0020
#define CFG_IRQ_ACK_0 0x0024
#define CFG_IRQ_ACK_1 0x0028
#define DEBUG_MON_SEL 0x002C
#define DEBUG_MON_STATUS 0x0030
#define MEM_WRAPPER 0x0034

/* Osaka-specific registers */
#if defined(CONFIG_OSAKA)
#define MEM_WRAPPER_STA 0x0038
#define CLOCK_PHASE 0x003C
#define MEM_WRAPPER_T12 0x0040
#endif

/* EPHY_INTF_SEL Register - Platform dependent */
#if defined(CONFIG_OSAKA)
#define PHY_INTF_SEL_MASK GENMASK(2, 0)
#define PHY_INTF_SEL_MII 0x0 /* GMII or MII */
#define PHY_INTF_SEL_RGMII 0x1 /* RGMII */
#define PHY_INTF_SEL_SGMII 0x2 /* SGMII */
#define PHY_INTF_SEL_TBI 0x3 /* TBI */
#define PHY_INTF_SEL_RMII 0x4 /* RMII (default) */
#define PHY_INTF_SEL_RTMI 0x5 /* RTMI */
#define PHY_INTF_SEL_SMII 0x6 /* SMII */
#define PHY_INTF_SEL_REVMII 0x7 /* RevMII */
#elif defined(CONFIG_SAPPORO)
#define PHY_INTF_SEL_MASK BIT(0)
#define PHY_INTF_SEL_RMII 0x1 /* RMII only */
#endif

/* Clock frequencies (Hz) */
#define AUGENTIX_CLK_1000M 125000000 /* 1000 Mbps */
#define AUGENTIX_CLK_100M 25000000 /* 100 Mbps */
#define AUGENTIX_CLK_10M 2500000 /* 10 Mbps */

/* FIFO sizes - Same for both platforms */
#define AUGENTIX_RX_FIFO_SIZE 2048
#define AUGENTIX_TX_FIFO_SIZE 4096

#endif /* __DWMAC_AUGENTIX_H__ */
