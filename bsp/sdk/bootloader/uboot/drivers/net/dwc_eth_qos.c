/*
 * (C) Copyright 2017
 * Nick Lin, augentix, nick.lin@augentix.com.
 *
 */

/*
 * augentix ethernet IP driver for U-Boot
 */

#include <common.h>
#include <dm.h>
#include <errno.h>
#include <miiphy.h>
#include <malloc.h>
#include <pci.h>
#include <linux/compiler.h>
#include <linux/err.h>
#include <asm/io.h>
#include <wait_bit.h>
#include "dwc_eth_qos.h"

DECLARE_GLOBAL_DATA_PTR;

enum PLL_SRC_NUM { PLL_XTAL = 0, PLL_MAIN_VCO, PLL_MAIN_P0, PLL_MAIN_P1, PLL_SUB_VCO, PLL_SUB_P0, PLL_SUB_P1, PLL_USB };

/* SPLL always output 800/400/200 MHz, and EMAC uses 200/8 = 25MHz */
#define EMAC_CLK_SRC (PLL_SUB_P1)
#define EMAC_CLK_DIV (4) //0:1, 1:2, 2:4, 3:6, 4:8, 5:10, 6:12, 7:14

static int eqos_eth_hw_init(struct eth_device *dev)
{
	phys_addr_t eqos_cfg_base = EQOS_CFG_BASE;

#ifdef CONFIG_HC1703_1723_1753_1783S
	u32 tmp;
	tmp = readl(eqos_cfg_base + 0x04);
	tmp &= 0xFF;
	writel((10 << 16) | (1 << 8) | tmp, eqos_cfg_base + 0x04);
#endif

#if defined(CONFIG_OSAKA)
	/* Set RMII mode */
	writel(0x4, eqos_cfg_base);
#else
	writel(0x1, eqos_cfg_base);
#endif /* CONFIG_OSAKA */

	return 0;
}

static int eqos_reset_hw(struct eth_device *dev)
{
	int i = 5000;
	u32 reg = 0;
	struct eqos_priv *eqos = dev->priv;

	writel(0x1, &eqos->dma_regs->mode);

	do {
		udelay(100);
		i--;
		reg = readl(&eqos->dma_regs->mode);
	} while ((reg & 0x1) && i);

	if (!i) {
		printf("eth reset timed out!\n");
		return -ETIMEDOUT;
	}

	return 0;
}

static int eqos_mdio_wait_idle(struct eqos_priv *eqos)
{
	return wait_for_bit(__func__, &eqos->mac_regs->mdio_address,
			    EQOS_MAC_MDIO_ADDRESS_GB, false, 1000000, true);
}

static void eqos_inval_buffer(void *buf, size_t size)
{
	unsigned long start = (unsigned long)buf & ~(ARCH_DMA_MINALIGN - 1);
	unsigned long end = ALIGN(start + size + 1, ARCH_DMA_MINALIGN);

	invalidate_dcache_range(start, end);
}

static void eqos_inval_desc(void *desc)
{
#ifndef CONFIG_SYS_NONCACHED_MEMORY
	unsigned long start = (unsigned long)desc & ~(ARCH_DMA_MINALIGN - 1);
	unsigned long end = ALIGN(start + EQOS_DESCRIPTOR_SIZE, ARCH_DMA_MINALIGN);

	invalidate_dcache_range(start, end);
#endif
}

static void eqos_flush_desc(void *desc)
{
#ifndef CONFIG_SYS_NONCACHED_MEMORY
	flush_cache((unsigned long)desc, EQOS_DESCRIPTOR_SIZE);
#endif
}

static void eqos_flush_buffer(void *buf, size_t size)
{
	flush_cache((unsigned long)buf, size);
}


static int eqos_mdio_read(struct mii_dev *bus, int mdio_addr, int mdio_devad, int mdio_reg)
{
	struct eqos_priv *eqos = bus->priv;
	u32 val;
	int ret;

	debug("%s(dev=%p, addr=%x, reg=%d):\n", __func__, eqos->dev, mdio_addr, mdio_reg);

	ret = eqos_mdio_wait_idle(eqos);
	if (ret) {
		error("MDIO not idle at entry");
		return ret;
	}

	val = readl(&eqos->mac_regs->mdio_address);
	val &= EQOS_MAC_MDIO_ADDRESS_SKAP | EQOS_MAC_MDIO_ADDRESS_C45E;
	val |= (mdio_addr << EQOS_MAC_MDIO_ADDRESS_PA_SHIFT) | (mdio_reg << EQOS_MAC_MDIO_ADDRESS_RDA_SHIFT) |
	       (EQOS_MAC_MDIO_ADDRESS_CR_250 << EQOS_MAC_MDIO_ADDRESS_CR_SHIFT) |
	       (EQOS_MAC_MDIO_ADDRESS_GOC_READ << EQOS_MAC_MDIO_ADDRESS_GOC_SHIFT) | EQOS_MAC_MDIO_ADDRESS_GB;
	writel(val, &eqos->mac_regs->mdio_address);

	udelay(10);

	ret = eqos_mdio_wait_idle(eqos);
	if (ret) {
		error("MDIO read didn't complete");
		return ret;
	}

	val = readl(&eqos->mac_regs->mdio_data);
	val &= EQOS_MAC_MDIO_DATA_GD_MASK;

	return val;
}

static int eqos_mdio_write(struct mii_dev *bus, int mdio_addr, int mdio_devad, int mdio_reg, u16 mdio_val)
{
	struct eqos_priv *eqos = bus->priv;
	u32 val;
	int ret;

	debug("%s(dev=%p, addr=%x, reg=%d, val=%x):\n", __func__, eqos->dev, mdio_addr, mdio_reg, mdio_val);

	ret = eqos_mdio_wait_idle(eqos);
	if (ret) {
		error("MDIO not idle at entry");
		return ret;
	}

	writel(mdio_val, &eqos->mac_regs->mdio_data);

	val = readl(&eqos->mac_regs->mdio_address);
	val &= EQOS_MAC_MDIO_ADDRESS_SKAP | EQOS_MAC_MDIO_ADDRESS_C45E;
	val |= (mdio_addr << EQOS_MAC_MDIO_ADDRESS_PA_SHIFT) | (mdio_reg << EQOS_MAC_MDIO_ADDRESS_RDA_SHIFT) |
	       (EQOS_MAC_MDIO_ADDRESS_CR_250 << EQOS_MAC_MDIO_ADDRESS_CR_SHIFT) |
	       (EQOS_MAC_MDIO_ADDRESS_GOC_WRITE << EQOS_MAC_MDIO_ADDRESS_GOC_SHIFT) | EQOS_MAC_MDIO_ADDRESS_GB;
	writel(val, &eqos->mac_regs->mdio_address);

	udelay(10);

	ret = eqos_mdio_wait_idle(eqos);
	if (ret) {
		error("MDIO read didn't complete");
		return ret;
	}

	return 0;
}

static int eqos_mdio_init(const char *name, struct eqos_priv *eqos)
{
	struct mii_dev *bus = mdio_alloc();

	if (!bus) {
		printf("Failed to allocate MDIO bus\n");
		return -ENOMEM;
	}

	bus->read = eqos_mdio_read;
	bus->write = eqos_mdio_write;
	snprintf(bus->name, sizeof(bus->name), "%s", name);

	bus->priv = (void *)eqos;

	return mdio_register(bus);
}

static int eqos_phy_init(struct eqos_priv *eqos, void *dev)
{
	struct phy_device *phydev;
	int mask = 0xffffffff, ret;

#ifdef CONFIG_PHY_ADDR
	mask = 1 << CONFIG_PHY_ADDR;
#endif

	phydev = phy_find_by_mask(eqos->mii, mask, eqos->interface);
	if (!phydev) {
		printf("Ethernet phy not found\n");
		return -ENODEV;
	}

	phy_connect_dev(phydev, dev);

	phydev->supported &= PHY_GBIT_FEATURES;
	if (eqos->max_speed) {
		ret = phy_set_supported(phydev, eqos->max_speed);
		if (ret)
			return ret;
	}
	phydev->advertising = phydev->supported;

	eqos->phy = phydev;
	phy_config(phydev);

	return 0;
}

static int eqos_free_pkt(struct eth_device *dev, uchar *packet, int length)
{
	struct eqos_priv *eqos = dev->priv;
	uchar *packet_expected;
	struct eqos_desc *rx_desc;

	debug("%s(packet=%p, length=%d)\n", __func__, packet, length);

	packet_expected = (uchar *)(eqos->rx_dma_buf + (eqos->rx_desc_idx * EQOS_MAX_PACKET_SIZE));
	if (packet != packet_expected) {
		debug("%s: Unexpected packet (expected %p)\n", __func__, packet_expected);
		return -EINVAL;
	}

	rx_desc = &(eqos->rx_descs[eqos->rx_desc_idx]);
	mb();
	eqos_flush_desc(rx_desc);
	eqos_inval_buffer(packet, length);

	rx_desc->des0 = (u32)(ulong)packet;
	rx_desc->des1 = 0;
	rx_desc->des2 = 0;
	/*
		 * Make sure that if HW sees the _OWN write below, it will see all the
		 * writes to the rest of the descriptor too.
		 */
	mb();
	rx_desc->des3 |= EQOS_DESC3_OWN | EQOS_DESC3_BUF1V;
	eqos_flush_desc(rx_desc);

	writel((ulong)rx_desc, &eqos->dma_regs->ch0_rxdesc_tail_pointer);

	eqos->rx_desc_idx++;
	eqos->rx_desc_idx %= EQOS_DESCRIPTORS_RX;

	return 0;
}

static int eqos_set_full_duplex(struct eth_device *dev)
{
	struct eqos_priv *eqos = dev->priv;

	debug("%s(dev=%p):\n", __func__, dev);

	setbits_le32(&eqos->mac_regs->configuration, EQOS_MAC_CONFIGURATION_DM);

	return 0;
}

static int eqos_set_half_duplex(struct eth_device *dev)
{
	struct eqos_priv *eqos = dev->priv;

	debug("%s(dev=%p):\n", __func__, dev);

	clrbits_le32(&eqos->mac_regs->configuration, EQOS_MAC_CONFIGURATION_DM);

	/* WAR: Flush TX queue when switching to half-duplex */
	setbits_le32(&eqos->mtl_regs->txq0_operation_mode,
		     EQOS_MTL_TXQ0_OPERATION_MODE_FTQ);

	return 0;
}

static int eqos_set_gmii_speed(struct eth_device *dev)
{
	struct eqos_priv *eqos = dev->priv;

	debug("%s(dev=%p):\n", __func__, dev);

	clrbits_le32(&eqos->mac_regs->configuration,
		     EQOS_MAC_CONFIGURATION_PS | EQOS_MAC_CONFIGURATION_FES);

	return 0;
}

static int eqos_set_mii_speed_100(struct eth_device *dev)
{
	struct eqos_priv *eqos = dev->priv;

	debug("%s(dev=%p):\n", __func__, dev);

	setbits_le32(&eqos->mac_regs->configuration,
		     EQOS_MAC_CONFIGURATION_PS | EQOS_MAC_CONFIGURATION_FES);

	return 0;
}

static int eqos_set_mii_speed_10(struct eth_device *dev)
{
	struct eqos_priv *eqos = dev->priv;

	debug("%s(dev=%p):\n", __func__, dev);

	clrsetbits_le32(&eqos->mac_regs->configuration,
			EQOS_MAC_CONFIGURATION_FES, EQOS_MAC_CONFIGURATION_PS);

	return 0;
}

static int eqos_adjust_link(struct eth_device *dev)
{
	struct eqos_priv *eqos = dev->priv;
	int ret = 0;

	debug("%s(dev=%p):\n", __func__, dev);

	if (eqos->phy->duplex)
		ret = eqos_set_full_duplex(dev);
	else
		ret = eqos_set_half_duplex(dev);
	if (ret < 0) {
		error("eqos_set_*_duplex() failed: %d", ret);
		return ret;
	}

	switch (eqos->phy->speed) {
	case SPEED_1000:
		ret = eqos_set_gmii_speed(dev);
		break;
	case SPEED_100:
		ret = eqos_set_mii_speed_100(dev);
		break;
	case SPEED_10:
		ret = eqos_set_mii_speed_10(dev);
		break;
	default:
		error("invalid speed %d", eqos->phy->speed);
		return -EINVAL;
	}
	if (ret < 0) {
		error("eqos_set_*mii_speed*() failed: %d", ret);
		return ret;
	}

	writel(0x00020000, &eqos->mac_regs->unused_0ac[ (0xd0 - 0xac) / 4]); //phy link up
	return 0;
}

static int eqos_write_hwaddr(struct eth_device *dev)
{
	unsigned char *enetaddr = dev->enetaddr;
	struct eqos_priv *eqos = dev->priv;
	uint32_t val;

	/*
	 * This function may be called before start() or after stop(). At that
	 * time, on at least some configurations of the EQoS HW, all clocks to
	 * the EQoS HW block will be stopped, and a reset signal applied. If
	 * any register access is attempted in this state, bus timeouts or CPU
	 * hangs may occur. This check prevents that.
	 *
	 * A simple solution to this problem would be to not implement
	 * write_hwaddr(), since start() always writes the MAC address into HW
	 * anyway. However, it is desirable to implement write_hwaddr() to
	 * support the case of SW that runs subsequent to U-Boot which expects
	 * the MAC address to already be programmed into the EQoS registers,
	 * which must happen irrespective of whether the U-Boot user (or
	 * scripts) actually made use of the EQoS device, and hence
	 * irrespective of whether start() was ever called.
	 *
	 * Note that this requirement by subsequent SW is not valid for
	 * Tegra186, and is likely not valid for any non-PCI instantiation of
	 * the EQoS HW block. This function is implemented solely as
	 * future-proofing with the expectation the driver will eventually be
	 * ported to some system where the expectation above is true.
	 */

	/* Update the MAC address */
	val = (enetaddr[5] << 8) |
		(enetaddr[4]);
	writel(val, &eqos->mac_regs->address0_high);
	val = (enetaddr[3] << 24) |
		(enetaddr[2] << 16) |
		(enetaddr[1] << 8) |
		(enetaddr[0]);
	writel(val, &eqos->mac_regs->address0_low);

	return 0;
}

static int eqos_eth_send(struct eth_device *dev, void *packet, int length)
{
	struct eqos_priv *eqos = dev->priv;
	struct eqos_desc *tx_desc;
	int i;

	debug("%s(dev=%p, packet=%p, length=%d):\n", __func__, dev, packet,
	      length);

	memcpy(eqos->tx_dma_buf, packet, length);
	eqos_flush_buffer(eqos->tx_dma_buf, (length + (ARCH_DMA_MINALIGN - 1)) / ARCH_DMA_MINALIGN * ARCH_DMA_MINALIGN);

	tx_desc = &(eqos->tx_descs[eqos->tx_desc_idx]);
	eqos_flush_desc(tx_desc);
	eqos->tx_desc_idx++;
	eqos->tx_desc_idx %= EQOS_DESCRIPTORS_TX;

	tx_desc->des0 = (ulong)eqos->tx_dma_buf;
	tx_desc->des1 = 0;
	tx_desc->des2 = length;
	/*
	 * Make sure that if HW sees the _OWN write below, it will see all the
	 * writes to the rest of the descriptor too.
	 */
	mb();
	tx_desc->des3 = EQOS_DESC3_OWN | EQOS_DESC3_FD | EQOS_DESC3_LD | length;
	eqos_flush_desc(tx_desc);

	writel((ulong)(tx_desc + 1), &eqos->dma_regs->ch0_txdesc_tail_pointer);

	for (i = 0; i < 1000000; i++) {
		eqos_inval_desc(tx_desc);
		if (!(readl(&tx_desc->des3) & EQOS_DESC3_OWN)) {
			return 0;
		}
		udelay(1);
	}

	debug("%s: TX timeout\n", __func__);

	return -ETIMEDOUT;
}

static int eqos_eth_recv(struct eth_device *dev)
{
	struct eqos_priv *eqos = dev->priv;
	struct eqos_desc *rx_desc;
	int length = 0;
	uchar *packetp = NULL;

	rx_desc = &(eqos->rx_descs[eqos->rx_desc_idx]);
	eqos_inval_desc(rx_desc);
	if (rx_desc->des3 & EQOS_DESC3_OWN) {
		debug("%s: RX packet not available\n", __func__);
		return -EAGAIN;
	}

	packetp = (uchar *)(eqos->rx_dma_buf +
		(eqos->rx_desc_idx * EQOS_MAX_PACKET_SIZE));
	length = rx_desc->des3 & 0x7fff;
	debug("%s: *packetp=%p, length=%d\n", __func__, packetp, length);

	eqos_inval_buffer(packetp, length);
#if 0 //dump packet
	int i = 0;
	printf("\n");
	for (i = 0; i < length; i++) {
		printf("%02x ", packetp[i]);
		if (!(i % 16) && (i != 0)) {
			printf("\n");
		}
	}
	printf("\n");
#endif
	net_process_received_packet(packetp, length);

	eqos_free_pkt(dev, packetp, length);

	return 0;
}

static int eqos_eth_init(struct eth_device *dev, bd_t *bis)
{
	struct eqos_priv *eqos = dev->priv;
	int ret = 0;
	int i = 0;
	u32 val, tx_fifo_sz, rx_fifo_sz, tqs, rqs, pbl;
	ulong last_rx_desc;

	debug("%s(dev=%p):\n", __func__, dev);

	dcache_disable();

	if (!eqos->phy) {
		printf("Ethernet phy not found\n");
		return -ENODEV;
	}

	ret = eqos_reset_hw(dev);
	if (ret < 0) {
		return ret;
	}

	udelay(10);

	eqos->tx_desc_idx = 0;
	eqos->rx_desc_idx = 0;

	ret = wait_for_bit(__func__, &eqos->dma_regs->mode, EQOS_DMA_MODE_SWR, false, 10, false);
	if (ret) {
		error("EQOS_DMA_MODE_SWR stuck");
		goto err_stop_resets;
	}

	ret = phy_startup(eqos->phy);
	if (ret < 0) {
		error("phy_startup() failed: %d", ret);
		goto err_shutdown_phy;
	}

	if (!eqos->phy->link) {
		error("No link");
		goto err_shutdown_phy;
	}

	ret = eqos_adjust_link(dev);
	if (ret < 0) {
		error("eqos_adjust_link() failed: %d", ret);
		goto err_shutdown_phy;
	}

	writel(0x000000F9, &eqos->mac_regs->us_tic_counter);

	/* Configure MTL */

	/* Enable Store and Forward mode for TX */
	/* Program Tx operating mode */
	setbits_le32(&eqos->mtl_regs->txq0_operation_mode,
	             EQOS_MTL_TXQ0_OPERATION_MODE_TSF |
	                     (EQOS_MTL_TXQ0_OPERATION_MODE_TXQEN_ENABLED << EQOS_MTL_TXQ0_OPERATION_MODE_TXQEN_SHIFT));

	/* Transmit Queue weight */
	writel(0x10, &eqos->mtl_regs->txq0_quantum_weight);

	/* Enable Store and Forward mode for RX, since no jumbo frame */
	setbits_le32(&eqos->mtl_regs->rxq0_operation_mode, EQOS_MTL_RXQ0_OPERATION_MODE_RSF);

	/* Transmit/Receive queue fifo size; use all RAM for 1 queue */
	val = readl(&eqos->mac_regs->hw_feature1);
	tx_fifo_sz = (val >> EQOS_MAC_HW_FEATURE1_TXFIFOSIZE_SHIFT) & EQOS_MAC_HW_FEATURE1_TXFIFOSIZE_MASK;
	rx_fifo_sz = (val >> EQOS_MAC_HW_FEATURE1_RXFIFOSIZE_SHIFT) & EQOS_MAC_HW_FEATURE1_RXFIFOSIZE_MASK;

	/*
		 * r/tx_fifo_sz is encoded as log2(n / 128). Undo that by shifting.
		 * r/tqs is encoded as (n / 256) - 1.
		 */
	tqs = (128 << tx_fifo_sz) / 256 - 1;
	rqs = (128 << rx_fifo_sz) / 256 - 1;

	clrsetbits_le32(&eqos->mtl_regs->txq0_operation_mode,
	                EQOS_MTL_TXQ0_OPERATION_MODE_TQS_MASK << EQOS_MTL_TXQ0_OPERATION_MODE_TQS_SHIFT,
	                tqs << EQOS_MTL_TXQ0_OPERATION_MODE_TQS_SHIFT);
	clrsetbits_le32(&eqos->mtl_regs->rxq0_operation_mode,
	                EQOS_MTL_RXQ0_OPERATION_MODE_RQS_MASK << EQOS_MTL_RXQ0_OPERATION_MODE_RQS_SHIFT,
	                rqs << EQOS_MTL_RXQ0_OPERATION_MODE_RQS_SHIFT);

	/* Flow control used only if each channel gets 4KB or more FIFO */
	if (rqs >= ((4096 / 256) - 1)) {
		u32 rfd, rfa;

		setbits_le32(&eqos->mtl_regs->rxq0_operation_mode, EQOS_MTL_RXQ0_OPERATION_MODE_EHFC);

		/*
			 * Set Threshold for Activating Flow Contol space for min 2
			 * frames ie, (1500 * 1) = 1500 bytes.
			 *
			 * Set Threshold for Deactivating Flow Contol for space of
			 * min 1 frame (frame size 1500bytes) in receive fifo
			 */
		if (rqs == ((4096 / 256) - 1)) {
			/*
				 * This violates the above formula because of FIFO size
				 * limit therefore overflow may occur inspite of this.
				 */
			rfd = 0x3; /* Full-3K */
			rfa = 0x1; /* Full-1.5K */
		} else if (rqs == ((8192 / 256) - 1)) {
			rfd = 0x6; /* Full-4K */
			rfa = 0xa; /* Full-6K */
		} else if (rqs == ((16384 / 256) - 1)) {
			rfd = 0x6; /* Full-4K */
			rfa = 0x12; /* Full-10K */
		} else {
			rfd = 0x6; /* Full-4K */
			rfa = 0x1E; /* Full-16K */
		}

		clrsetbits_le32(&eqos->mtl_regs->rxq0_operation_mode,
		                (EQOS_MTL_RXQ0_OPERATION_MODE_RFD_MASK << EQOS_MTL_RXQ0_OPERATION_MODE_RFD_SHIFT) |
		                        (EQOS_MTL_RXQ0_OPERATION_MODE_RFA_MASK
		                         << EQOS_MTL_RXQ0_OPERATION_MODE_RFA_SHIFT),
		                (rfd << EQOS_MTL_RXQ0_OPERATION_MODE_RFD_SHIFT) |
		                        (rfa << EQOS_MTL_RXQ0_OPERATION_MODE_RFA_SHIFT));
	}

	/* Configure MAC */

	clrsetbits_le32(&eqos->mac_regs->rxq_ctrl0, EQOS_MAC_RXQ_CTRL0_RXQ0EN_MASK << EQOS_MAC_RXQ_CTRL0_RXQ0EN_SHIFT,
	                EQOS_MAC_RXQ_CTRL0_RXQ0EN_ENABLED_DCB << EQOS_MAC_RXQ_CTRL0_RXQ0EN_SHIFT);

	/* Set TX flow control parameters */
	/* Set Pause Time */
	setbits_le32(&eqos->mac_regs->q0_tx_flow_ctrl, 0xffff << EQOS_MAC_Q0_TX_FLOW_CTRL_PT_SHIFT);
	/* Assign priority for TX flow control */
	clrbits_le32(&eqos->mac_regs->txq_prty_map0, EQOS_MAC_TXQ_PRTY_MAP0_PSTQ0_MASK
	                                                     << EQOS_MAC_TXQ_PRTY_MAP0_PSTQ0_SHIFT);
	/* Assign priority for RX flow control */
	clrbits_le32(&eqos->mac_regs->rxq_ctrl2, EQOS_MAC_RXQ_CTRL2_PSRQ0_MASK << EQOS_MAC_RXQ_CTRL2_PSRQ0_SHIFT);
	/* Enable flow control */
	setbits_le32(&eqos->mac_regs->q0_tx_flow_ctrl, EQOS_MAC_Q0_TX_FLOW_CTRL_TFE);
	setbits_le32(&eqos->mac_regs->rx_flow_ctrl, EQOS_MAC_RX_FLOW_CTRL_RFE);

	clrsetbits_le32(&eqos->mac_regs->configuration, EQOS_MAC_CONFIGURATION_GPSLCE | EQOS_MAC_CONFIGURATION_WD |
	                                                        EQOS_MAC_CONFIGURATION_JD | EQOS_MAC_CONFIGURATION_JE,
	                EQOS_MAC_CONFIGURATION_CST | EQOS_MAC_CONFIGURATION_ACS);

	eqos_write_hwaddr(dev);

	/* Configure DMA */

	/* Enable OSP mode */
	setbits_le32(&eqos->dma_regs->ch0_tx_control, EQOS_DMA_CH0_TX_CONTROL_OSP);

	/* RX buffer size. Must be a multiple of bus width */
	clrsetbits_le32(&eqos->dma_regs->ch0_rx_control,
	                EQOS_DMA_CH0_RX_CONTROL_RBSZ_MASK << EQOS_DMA_CH0_RX_CONTROL_RBSZ_SHIFT,
	                EQOS_MAX_PACKET_SIZE << EQOS_DMA_CH0_RX_CONTROL_RBSZ_SHIFT);

	setbits_le32(&eqos->dma_regs->ch0_control, EQOS_DMA_CH0_CONTROL_PBLX8);
	setbits_le32(&eqos->dma_regs->ch0_control, 2 << EQOS_DMA_CH0_CONTROL_DSL_SHIFT);

	/*
		 * Burst length must be < 1/2 FIFO size.
		 * FIFO size in tqs is encoded as (n / 256) - 1.
		 * Each burst is n * 8 (PBLX8) * 16 (AXI width) == 128 bytes.
		 * Half of n * 256 is n * 128, so pbl == tqs, modulo the -1.
		 */
	pbl = tqs + 1;
	if (pbl > 32)
		pbl = 32;
	clrsetbits_le32(&eqos->dma_regs->ch0_tx_control,
	                EQOS_DMA_CH0_TX_CONTROL_TXPBL_MASK << EQOS_DMA_CH0_TX_CONTROL_TXPBL_SHIFT,
	                pbl << EQOS_DMA_CH0_TX_CONTROL_TXPBL_SHIFT);

	clrsetbits_le32(&eqos->dma_regs->ch0_rx_control,
	                EQOS_DMA_CH0_RX_CONTROL_RXPBL_MASK << EQOS_DMA_CH0_RX_CONTROL_RXPBL_SHIFT,
	                8 << EQOS_DMA_CH0_RX_CONTROL_RXPBL_SHIFT);

	/* DMA performance configuration */
	val = (0 << EQOS_DMA_SYSBUS_MODE_RD_OSR_LMT_SHIFT) |
		EQOS_DMA_SYSBUS_MODE_EAME | EQOS_DMA_SYSBUS_MODE_BLEN16 |
		EQOS_DMA_SYSBUS_MODE_BLEN8 | EQOS_DMA_SYSBUS_MODE_BLEN4;
	writel(val, &eqos->dma_regs->sysbus_mode);

	/* Set up descriptors */

	memset(eqos->descs, 0, EQOS_DESCRIPTORS_SIZE);
	for (i = 0; i < EQOS_DESCRIPTORS_RX; i++) {
		struct eqos_desc *rx_desc = &(eqos->rx_descs[i]);
		rx_desc->des0 = (u32)(ulong)(eqos->rx_dma_buf + (i * EQOS_MAX_PACKET_SIZE));
		rx_desc->des3 |= EQOS_DESC3_OWN | EQOS_DESC3_BUF1V;
	}
	flush_cache((unsigned long)eqos->descs, EQOS_DESCRIPTORS_SIZE);

	writel(0, &eqos->dma_regs->ch0_txdesc_list_haddress);
	writel((ulong)eqos->tx_descs, &eqos->dma_regs->ch0_txdesc_list_address);
	writel(EQOS_DESCRIPTORS_TX - 1, &eqos->dma_regs->ch0_txdesc_ring_length);

	writel(0, &eqos->dma_regs->ch0_rxdesc_list_haddress);
	writel((ulong)eqos->rx_descs, &eqos->dma_regs->ch0_rxdesc_list_address);
	writel(EQOS_DESCRIPTORS_RX - 1, &eqos->dma_regs->ch0_rxdesc_ring_length);

	/* Enable everything */

	setbits_le32(&eqos->mac_regs->configuration, EQOS_MAC_CONFIGURATION_TE | EQOS_MAC_CONFIGURATION_RE);

	setbits_le32(&eqos->dma_regs->ch0_tx_control, EQOS_DMA_CH0_TX_CONTROL_ST);
	setbits_le32(&eqos->dma_regs->ch0_rx_control, EQOS_DMA_CH0_RX_CONTROL_SR);

	/* TX tail pointer not written until we need to TX a packet */
	/*
		 * Point RX tail pointer at last descriptor. Ideally, we'd point at the
		 * first descriptor, implying all descriptors were available. However,
		 * that's not distinguishable from none of the descriptors being
		 * available.
		 */
	last_rx_desc = (ulong) & (eqos->rx_descs[(EQOS_DESCRIPTORS_RX - 1)]);
	writel(last_rx_desc, &eqos->dma_regs->ch0_rxdesc_tail_pointer);
	dcache_enable();

	debug("%s: OK\n", __func__);
	return 0;

err_shutdown_phy:
	phy_shutdown(eqos->phy);
	eqos->phy = NULL;
err_stop_resets:
	error("FAILED: %d", ret);
	return ret;
}

static void eqos_eth_halt(struct eth_device *dev)
{
	struct eqos_priv *eqos = dev->priv;

	if (!eqos->phy) {
		printf("Ethernet phy not found\n");
		return ;
	}

	clrbits_le32(&eqos->mac_regs->configuration, EQOS_MAC_CONFIGURATION_TE | EQOS_MAC_CONFIGURATION_RE);

	phy_shutdown(eqos->phy);
}

int eqos_emac_initialize(u32 interface)
{
	struct eth_device *dev;
	struct eqos_priv *eqos = NULL;

	dev = (struct eth_device *)malloc(sizeof(struct eth_device));
	if (!dev)
		return -ENOMEM;

	/*
	 * Since the priv structure contains the descriptors which need a strict
	 * buswidth alignment, memalign is used to allocate memory
	 */
	eqos = (struct eqos_priv *)memalign(ARCH_DMA_MINALIGN, sizeof(struct eqos_priv));
	if (!eqos) {
		free(dev);
		return -ENOMEM;
	}

	memset(dev, 0, sizeof(struct eth_device));
	memset(eqos, 0, sizeof(struct eqos_priv));

	sprintf(dev->name, "eqos_eth");

	dev->priv = eqos;

	eqos->tx_descs = eqos->descs;
	eqos->rx_descs = &eqos->descs[EQOS_DESCRIPTORS_TX];

	eqos->dev = dev;
	eqos->regs = EQOS_CONTROLLER_BASE;
	eqos->mac_regs = (void *)(eqos->regs + EQOS_MAC_REGS_BASE);
	eqos->mtl_regs = (void *)(eqos->regs + EQOS_MTL_REGS_BASE);
	eqos->dma_regs = (void *)(eqos->regs + EQOS_DMA_REGS_BASE);

	dev->init = eqos_eth_init;
	dev->send = eqos_eth_send;
	dev->recv = eqos_eth_recv;
	dev->halt = eqos_eth_halt;
	dev->write_hwaddr = eqos_write_hwaddr;

	eqos_eth_hw_init(dev);

	//eqos_reset_hw(dev);

	eth_register(dev);

	eqos->interface = interface;

	eqos_mdio_init(dev->name, eqos);
	eqos->mii = miiphy_get_dev_by_name(dev->name);

	return eqos_phy_init(eqos, dev);
}
