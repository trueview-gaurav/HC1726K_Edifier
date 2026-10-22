/*
 * augentix master QSPI core controller driver
 *
 * Copyright (C) 2017 Nick Lin<nick.lin@augentix.com>
 *
 */

#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <spi.h>
#include <fdtdec.h>
#include <linux/compat.h>
#include <asm/io.h>
#include <asm/cache.h>

DECLARE_GLOBAL_DATA_PTR;

/* Register offsets */
#define AGTX_SPI_WORD0 0x00
#define AGTX_SPI_WORD1 0x04
#define AGTX_SPI_WORD2 0x08
#define AGTX_SPI_WORD3 0x0C
#define AGTX_SPI_WORD4 0x10
#define AGTX_SPI_WORD5 0x14
#define AGTX_SPI_WORD6 0x18
#define AGTX_SPI_WORD7 0x1C
#define AGTX_SPI_WORD8 0x20
#define AGTX_SPI_WORD9 0x24
#define AGTX_SPI_WORD10 0x28
#define AGTX_SPI_WORD11 0x2C
#define AGTX_SPI_WORD12 0x30
#define AGTX_SPI_WORD13 0x34
#define AGTX_SPI_WORD14 0x38
#define AGTX_SPI_WORD15 0x3C
#define AGTX_SPI_WORD16 0x40
#define AGTX_SPI_WORD17 0x44
#define AGTX_SPI_WORD18 0x48
#define AGTX_SPI_WORD19 0x4C

#if defined(CONFIG_OSAKA)
#define WORD_IRQ_CLEAR AGTX_SPI_WORD3
#define WORD_IRQ_STATUS AGTX_SPI_WORD4
#define WORD_IRQ_MASK AGTX_SPI_WORD5
#define WORD_TX_FIFO AGTX_SPI_WORD12
#define WORD_RX_FIFO AGTX_SPI_WORD13
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define WORD_IRQ_CLEAR AGTX_SPI_WORD2
#define WORD_IRQ_STATUS AGTX_SPI_WORD3
#define WORD_IRQ_MASK AGTX_SPI_WORD4
#define WORD_TX_FIFO AGTX_SPI_WORD14
#define WORD_RX_FIFO AGTX_SPI_WORD15
#else
#define WORD_IRQ_CLEAR AGTX_SPI_WORD2
#define WORD_IRQ_STATUS AGTX_SPI_WORD3
#define WORD_IRQ_MASK AGTX_SPI_WORD4
#define WORD_TX_FIFO AGTX_SPI_WORD11
#define WORD_RX_FIFO AGTX_SPI_WORD12
#endif /* CONFIG_OSAKA */

/* QSPIR Register offsets */
#define LR032_00 0x00
#define LR032_01 0x04
#define LR032_02 0x08
#define LR032_04 0x10
#define LR032_11 0x2c
#define LR032_12 0x30
#define LR032_40 0xA0

/* Bit fields in WORD QSPI00 */
#define SPI_START_OFFSET 0

/* Bit fields in WORD QSPI01 */
#define SPI_ENABLE_OFFSET 0
#define SPI_SD_OFFSET 8

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define SPI_SLP_OFFSET 16
#else
#define SPI_SLP_OFFSET 9
#endif

/* Bit fields in WORD QSPI02 */
#define SPI_IRQ_CLR_SPI_DONE_OFFSET 0
#ifdef CONFIG_HC1703_1723_1753_1783S
#define SPI_IRQ_CLR_AUTO_DONE_OFFSET 2
#endif
#define SPI_IRQ_CLR_DONE_OFFSET 4
#define SPI_IRQ_CLR_ERROR_OFFSET 6
#define SPI_IRQ_CLR_TX_FIFO_FULL_OFFSET 8
#define SPI_IRQ_CLR_TX_FIFO_EMPTY_OFFSET 10
#define SPI_IRQ_CLR_RX_FIFO_FULL_OFFSET 12
#define SPI_IRQ_CLR_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI03 */
#define SPI_STATUS_CLR_SPI_DONE_OFFSET 0
#ifdef CONFIG_HC1703_1723_1753_1783S
#define SPI_STATUS_CLR_AUTO_DONE_OFFSET 2
#endif
#define SPI_STATUS_CLR_DONE_OFFSET 4
#define SPI_STATUS_CLR_ERROR_OFFSET 6
#define SPI_STATUS_CLR_TX_FIFO_FULL_OFFSET 8
#define SPI_STATUS_CLR_TX_FIFO_EMPTY_OFFSET 10
#define SPI_STATUS_CLR_RX_FIFO_FULL_OFFSET 12
#define SPI_STATUS_CLR_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI04 */
#define SPI_IRQ_MASK_CLR_SPI_DONE_OFFSET 0
#ifdef CONFIG_HC1703_1723_1753_1783S
#define SPI_IRQ_MASK_CLR_AUTO_DONE_OFFSET 2
#endif
#define SPI_IRQ_MASK_CLR_DONE_OFFSET 4
#define SPI_IRQ_MASK_CLR_ERROR_OFFSET 6
#define SPI_IRQ_MASK_CLR_TX_FIFO_FULL_OFFSET 8
#define SPI_IRQ_MASK_CLR_TX_FIFO_EMPTY_OFFSET 10
#define SPI_IRQ_MASK_CLR_RX_FIFO_FULL_OFFSET 12
#define SPI_IRQ_MASK_CLR_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI05 */
#define SPI_SPI_BUSY_OFFSET 0
#define SPI_SPI_DONE_OFFSET 2
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define SPI_ERROR_OFFSET 4
#define SPI_TX_FIFO_FULL_OFFSET 6
#define SPI_TX_FIFO_EMPTY_OFFSET 8
#define SPI_RX_FIFO_FULL_OFFSET 10
#define SPI_RX_FIFO_EMPTY_OFFSET 12
#else
#define SPI_AUTO_BUSY_OFFSET 4
#define SPI_AUTO_DONE_OFFSET 6
#define SPI_DONE_OFFSET 8
#define SPI_ERROR_OFFSET 10
#define SPI_TX_FIFO_FULL_OFFSET 16
#define SPI_TX_FIFO_EMPTY_OFFSET 18
#define SPI_RX_FIFO_FULL_OFFSET 20
#define SPI_RX_FIFO_EMPTY_OFFSET 22
#endif // CONFIG_SAPPORO

/* Bit fields in WORD QSPI06 */
#define SPI_MST_STATE_OFFSET 0
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define SPI_CNT_FRAME_OFFSET 8
#else
#define SPI_AUTO_STATE_OFFSET 4
#define SPI_CNT_FRAME_OFFSET 16
#endif // CONFIG_SAPPORO

/* Bit fields in WORD QSPI07 */
#if defined(CONFIG_OSAKA)
#define SPI_QSPI_STATE_OFFSET 0
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define SPI_TRANSFER_MODE_OFFSET 0
#define SPI_TRANSFER_TYPE_OFFSET 8
#define SPI_DMA_MODE_EN_OFFSET 16
#define SPI_FRAME_FORMAT_OFFSET 24
#else
#define SPI_DF_CNT_OFFSET 0
#define SPI_TDF_CNT_OFFSET 16
#endif /* CONFIG_OSAKA */

/* Bit fields in WORD QSPI08 */
#if defined(CONFIG_OSAKA)
#define SPI_TRANSFER_MODE_OFFSET 0
#define SPI_DMA_MODE_EN_OFFSET 4
#define SPI_INST_FORMAT_OFFSET 8
#define SPI_ADDR_FORMAT_OFFSET 16
#define SPI_FRAME_FORMAT_OFFSET 24
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define SPI_MSB_FIRST_OFFSET 0
#define SPI_ENDIAN_SEL_OFFSET 8
#else
#define SPI_TRANSFER_MODE_OFFSET 0
#define SPI_FRAME_FORMAT_OFFSET 2
#define SPI_DATA_FRAME_SIZE_OFFSET 4
#define SPI_MSB_FIRST_OFFSET 10
#define SPI_ENDIAN_SEL_OFFSET 12
#define SPI_TRANSFER_TYPE_OFFSET 14
#define SPI_INST_L_OFFSET 16
#define SPI_ADDR_L_OFFSET 18
#define SPI_WAIT_L_OFFSET 24
#endif // CONFIG_SAPPORO

/* Bit fields in WORD QSPI09 */
#if defined(CONFIG_OSAKA)
#define SPI_INST_MSB_FRIST_OFFSET 0
#define SPI_ADDR_MSB_FRIST_OFFSET 4
#define SPI_WR_MSB_FRIST_OFFSET 8
#define SPI_RD_MSB_FRIST_OFFSET 12
#define SPI_TX_NIB_SWAP_EN_OFFSET 16
#define SPI_RX_NIB_SWAP_EN_OFFSET 24
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define SPI_INST_L_OFFSET 0
#define SPI_ADDR_L_OFFSET 8
#define SPI_WAIT_L_OFFSET 16
#define SPI_DATA_FRAME_SIZE_OFFSET 24
#else
#define SPI_NDF_OFFSET 0
#define SPI_NDFW_OFFSET 16
#endif /* CONFIG_OSAKA */

/* Bit fields in WORD QSPI10 */
#if defined(CONFIG_OSAKA)
#define SPI_INST_L_OFFSET 0
#define SPI_ADDR_L_OFFSET 8
#define SPI_WAIT_1_L_OFFSET 16
#define SPI_WAIT_2_L_OFFSET 24
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define SPI_NDF_OFFSET 0
#else
#define SPI_SCK_DV_OFFSET 0
#define SPI_SCK_POL_OFFSET 8
#define SPI_SCK_POL_LOW 0x0
#define SPI_SCK_POL_HIGH 0x1
#define SPI_SCK_PHA_OFFSET 10
#define SPI_SCK_PHA_LOW 0x0
#define SPI_SCK_PHA_HIGH 0x1
#define SPI_SCK_DLY_OFFSET 16
#define SPI_RX_DELAY_OFFSET 24
#endif /* CONFIG_OSAKA */

/* Bit fields in WORD QSPI11 */
#if defined(CONFIG_OSAKA)
#define SPI_NDF_OFFSET 0
#define SPI_SWITCH_INST_ADDR_STATE_OFFSET 24
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define SPI_WR_CYCLE_OFFSET 0
#define SPI_RD_CYCLE_OFFSET 8
#else
#define SPI_WR_DATA_OFFSET 0
#endif /* CONFIG_OSAKA */

/* Bit fields in WORD QSPI12 */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define SPI_SCK_DV_OFFSET 0
#define SPI_SCK_POL_OFFSET 8
#define SPI_SCK_PHA_OFFSET 10
#define SPI_SCK_PHASE_SEL 16
#define SPI_SCK_DLY_OFFSET 24
#else
#define SPI_RD_DATA_OFFSET 0
#endif // CONFIG_SAPPORO

/* Bit fields in WORD QSPI13 */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define SPI_RX_DELAY_OFFSET 0
#define SPI_RX_SMPL_PHASE_SEL 8
#else
#define SPI_RD_DATA_R_OFFSET 0
#endif // CONFIG_SAPPORO

/* Bit fields in WORD QSPI14 */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define SPI_WR_DATA_OFFSET 0
#else
#define SPI_DMA_MODE_EN_OFFSET 0
#define SPI_AUTO_MODE_EN_OFFSET 8
#define SPI_STATUS_BO_SEL_OFFSET 10
#define SPI_TIMEOUT_FREE_OFFSET 12
#define SPI_PRE_SCALER_TH_OFFSET 16
#endif // CONFIG_SAPPORO

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
/* Bit fields in WORD QSPI15 */
#define SPI_RD_DATA_OFFSET 0
/* Bit fields in WORD QSPI16 */
#define SPI_RD_DATA_INV_OFFSET 0
/* Bit fields in WORD QSPI19 */
#define SPI_DEBUG_MON_SEL_OFFSET 0
#endif // CONFIG_SAPPORO

/* transfer mode */
#define QSPI_TMOD__READ 0
#define QSPI_TMOD__WRITE 1

/* frame format */
#define QSPI_FRF__SSPI 0x0
#define QSPI_FRF__DSPI 0x1
#define QSPI_FRF__QSPI 0x2

/* data frame size */
#define QSPI_DFS__4_BIT 0x3
#define QSPI_DFS__8_BIT 0x7
#define QSPI_DFS__16_BIT 0xF
#define QSPI_DFS__32_BIT 0x1F

/* msb first */
#define QSPI_FMT__LSB_FIRST 0
#define QSPI_FMT__MSB_FIRST 1

/* endian sel */
#define QSPI_SEL__L_ENDIAN 0
#define QSPI_SEL__B_ENDIAN 1

/* transfer type */
#define QSPI_TTYPE__SPI_SPI 0x0
#define QSPI_TTYPE__SPI_FRF 0x1
#define QSPI_TTYPE__FRF_FRF 0x2

/* instruction length */
#define QSPI_INST_L__4_BIT 0x1
#define QSPI_INST_L__8_BIT 0x2
#define QSPI_INST_L__16_BIT 0x3

/* address length */
#define QSPI_ADDR_L__0_BIT 0x0
#define QSPI_ADDR_L__4_BIT 0x1
#define QSPI_ADDR_L__8_BIT 0x2
#define QSPI_ADDR_L__12_BIT 0x3
#define QSPI_ADDR_L__16_BIT 0x4
#define QSPI_ADDR_L__20_BIT 0x5
#define QSPI_ADDR_L__24_BIT 0x6
#define QSPI_ADDR_L__28_BIT 0x7
#define QSPI_ADDR_L__32_BIT 0x8

/* wait length */
#define QSPI_WAIT_L__0_CYCLE 0x0
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define QSPI_WAIT_L__8_CYCLE 0x8
#else
#define QSPI_WAIT_L__8_CYCLE 0x7
#endif // CONFIG_SAPPORO

/* dma mode selection */
#define QSPI_DMA_M__DIS 0
#define QSPI_DMA_M__EN 1

#define QSPI_WAIT_SPI_DONE 0x01

/* IP definition */
/* FIFO size in byte */
#define QSPI_RX_FIFO_DEPTH 16

#ifdef CONFIG_FPGA
#define QSPI_TX_FIFO_DEPTH 13
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define QSPI_TX_FIFO_DEPTH 16
#else
#define QSPI_TX_FIFO_DEPTH 15
#endif

#define QSPI_RX_FIFO_SIZE (QSPI_RX_FIFO_DEPTH << 2) /*FIFO_DEPTH x 4Bytes*/
#define QSPI_TX_FIFO_SIZE (QSPI_TX_FIFO_DEPTH << 2)

#define pages_per_blk(x) (1 << (x))
#define pages_per_sector(x) pages_per_blk(x)
#define nand_addr_to_block(x, y, z) ((x) >> ((y) + (z)))

#define QSPI_TIMEOUT_TIME 32768
#define FLASH_TIMEOUT_TIME (256 * 16)

#define SINGLE_MODE 1
#define DUAL_MODE 2
#define QUAD_MODE 4

#define QSPI_REF_CLK_187500KHZ 187500000
#define QSPI_IF_CLK_93750KHZ 93750000
#define QSPI_IF_CLK_46875KHZ 46875000

struct augentix_qspi_slave {
	struct spi_slave slave;
	void __iomem *regs_qspi;
	void __iomem *regs_qspir;
	void __iomem *regs_qspiw;
	void __iomem *regs_pc_syscfg_dbg_mon;
	void *tx;
	void *tx_end;
	void *rx;
	void *rx_end;
	int len;
	u16 clk_div;
	u32 freq;
	u32 mode;
	u32 n_bytes;
};

static inline u8 hc_readb(struct augentix_qspi_slave *priv, u32 offset)
{
	return __raw_readb(priv->regs_qspi + offset);
}

static inline u16 hc_readw(struct augentix_qspi_slave *priv, u32 offset)
{
	return __raw_readw(priv->regs_qspi + offset);
}

static inline u32 hc_readl(struct augentix_qspi_slave *priv, u32 offset)
{
	return __raw_readl(priv->regs_qspi + offset);
}

static inline void hc_writeb(struct augentix_qspi_slave *priv, u32 offset, u8 val)
{
	__raw_writeb(val, priv->regs_qspi + offset);
}

static inline void hc_writew(struct augentix_qspi_slave *priv, u32 offset, u16 val)
{
	__raw_writew(val, priv->regs_qspi + offset);
}

static inline void hc_writel(struct augentix_qspi_slave *priv, u32 offset, u32 val)
{
	writel(val, priv->regs_qspi + offset);
}

static inline void show_reg(struct augentix_qspi_slave *priv)
{
	u32 reg = 0;
#if defined(CONFIG_OSAKA)
	reg = hc_readl(priv, AGTX_SPI_WORD4);
	printf("%s: IRQ status = %#010x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD6);
	printf("%s: SPI status = %#010x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD7);
	printf("%s: QSPI state = %#010x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD8);
	printf("%s: QSPI_TRANS_CTRL = %#010x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD10);
	printf("%s: QSPI_FSM_CTRL_0 = %#010x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD11);
	printf("%s: QSPI_FSM_CTRL_1 = %#010x\n", __func__, reg);
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
	reg = hc_readl(priv, AGTX_SPI_WORD3);
	printf("[G] %s: AGTX_SPI_WORD03 = 0x%08x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD7);
	printf("[G] %s: AGTX_SPI_WORD08 = 0x%08x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD9);
	printf("[G] %s: AGTX_SPI_WORD09 = 0x%08x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD10);
	printf("[G] %s: AGTX_SPI_WORD14 = 0x%08x\n", __func__, reg);

#else
	reg = hc_readl(priv, AGTX_SPI_WORD3);
	printf("[G] %s: AGTX_SPI_WORD03 = 0x%08x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD8);
	printf("[G] %s: AGTX_SPI_WORD08 = 0x%08x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD9);
	printf("[G] %s: AGTX_SPI_WORD09 = 0x%08x\n", __func__, reg);
	reg = hc_readl(priv, AGTX_SPI_WORD14);
	printf("[G] %s: AGTX_SPI_WORD14 = 0x%08x\n", __func__, reg);
#endif
}

static void hc_writer(struct augentix_qspi_slave *priv)
{
	u32 txw = 0;

	while ((priv->tx_end - priv->tx) > 0) {
		if (priv->n_bytes == 1) {
			txw = *(u8 *)(priv->tx);
		} else if (priv->n_bytes == 2) {
			txw = *(u16 *)(priv->tx);
		} else {
			txw = *(u32 *)(priv->tx);
		}
		hc_writel(priv, WORD_TX_FIFO, txw);
		priv->tx += priv->n_bytes;
	}
}

static void hc_reader(struct augentix_qspi_slave *priv)
{
	u32 rxw = 0;

	while (((priv->len + 3) >> 2) > 0) {
		rxw = hc_readl(priv, WORD_RX_FIFO);
		if (priv->len < 4) {
			*(u8 *)(priv->rx) = rxw;
			priv->rx++;
			priv->len--;
		} else {
			*(u32 *)(priv->rx) = rxw;
			priv->rx += 4;
			priv->len -= 4;
		}
	}
}

static void wait_done(struct augentix_qspi_slave *priv)
{
	u32 status;
	u32 umask;
	u32 expect;

	umask = (1 << SPI_IRQ_MASK_CLR_DONE_OFFSET); // check DONE
	expect = (1 << SPI_IRQ_MASK_CLR_DONE_OFFSET); // expect DONE = 1

	do {
		status = hc_readl(priv, WORD_IRQ_STATUS);
		if ((status & umask) == expect) {
			break;
		}

		barrier();
	} while (1);

	/* Clear all IRQ */
	hc_writel(priv, WORD_IRQ_CLEAR, ~0);
}

static int poll_transfer_tx(struct augentix_qspi_slave *priv, struct spi_slave *slave)
{
	void __iomem *regs_qspir = priv->regs_qspir;
	dma_addr_t dma_dest = (dma_addr_t)priv->tx;
	u32 len = priv->len;
	u32 flush_len;
	u32 val __attribute__((unused));

	if (slave->dma_mode == 0) {
		hc_writel(priv, AGTX_SPI_WORD0, 1); // Action start
		wait_done(priv);
	} else {
		flush_dcache_range((u32)dma_dest & ~(CONFIG_SYS_CACHELINE_SIZE - 1),
		                   ((u32)dma_dest + len + CONFIG_SYS_CACHELINE_SIZE + 1) &
		                           ~(CONFIG_SYS_CACHELINE_SIZE - 1));

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
		writel((len + 3) >> 2, regs_qspir + LR032_11); // PIXEL_FLUSH_LEN

		flush_len = (len + 7) >> 3;
		writel(flush_len, regs_qspir + LR032_12); // FIFO_FLUSH_LEN
#else
		writel(len >> 2, regs_qspir + LR032_11); // PIXEL_FLUSH_LEN
		flush_len = len >> 3;

		if (len % 8)
			flush_len++;
		writel(flush_len, regs_qspir + LR032_12); // FIFO_FLUSH_LEN
#endif /* CONFIG_SAPPORO */

		writel(dma_dest >> 3, regs_qspir + LR032_40); // INI_ADDR_LINEAR

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
		writel(0x1, regs_qspir + LR032_00); // FRAME_START
#else
		writel(2, priv->regs_qspi + 0x168); // QSPI.QSPI.debug_mon_sel  = 2

		val = __raw_readl(priv->regs_pc_syscfg_dbg_mon) & ~0x1f;
		val |= 7;
		writel(val, priv->regs_pc_syscfg_dbg_mon); // PC.SYSCFG.debug_mon_sel = 7

		val = __raw_readl(regs_qspir + 0x10) & ~0x1000000;
		val |= 1 << 24;

		writel(val, regs_qspir + 0x10); // QSPIR.QSPIR.debug_mon_sel = 1
		writel(1, regs_qspir + LR032_00); // FRAME_START

		while ((__raw_readl(priv->regs_pc_syscfg_dbg_mon + 4) & 0x3f) != (flush_len - 1)) {
		}
#endif /* CONFIG_SAPPORO */

		hc_writel(priv, AGTX_SPI_WORD0, 1); // Action start
		wait_done(priv);
	}

	return 0;
}

static int poll_transfer_rx(struct augentix_qspi_slave *priv, struct spi_slave *slave)
{
	void __iomem *reg;
	void *dma_dest = priv->rx;
	u32 len = priv->len;
	u8 *buf;

	if (slave->dma_mode == 0) {
		hc_writel(priv, AGTX_SPI_WORD0, 1); // Action start
		wait_done(priv);
		hc_reader(priv);
	} else {
		reg = priv->regs_qspiw;

		if ((((uintptr_t)dma_dest & 0xf) != 0) || (len & 0xf) != 0) {
			/* The DRAM bus width is 16 bytes, when the access is not align
			   There will have a change on DRAM outside the range we want */
			buf = malloc(len + 16);
			if (!buf) {
				return -ENOMEM;
			}
		} else {
			buf = dma_dest;
		}
		flush_dcache_range((uintptr_t)buf & ~(CONFIG_SYS_CACHELINE_SIZE - 1),
		                   ((uintptr_t)buf + len + CONFIG_SYS_CACHELINE_SIZE + 1) &
		                           ~(CONFIG_SYS_CACHELINE_SIZE - 1));

		/* Make sure all data will be flushed. */
		writel((len + 3) >> 2, reg + LR032_11); // PIXEL_FLUSH_LEN
		writel((uintptr_t)buf >> 3, reg + LR032_40); // INI_ADDR_LINEAR

		writel(1, reg + LR032_00); // FRAME_START
		hc_writel(priv, AGTX_SPI_WORD0, 1); // Action start

		wait_done(priv);

		if ((((uintptr_t)dma_dest & 0xf) != 0) || (len & 0xf) != 0) {
			invalidate_dcache_range((uintptr_t)buf & ~(CONFIG_SYS_CACHELINE_SIZE - 1),
			                        ((uintptr_t)buf + len + CONFIG_SYS_CACHELINE_SIZE + 1) &
			                                ~(CONFIG_SYS_CACHELINE_SIZE - 1));

			memcpy(dma_dest, buf, len);
			free(buf);
		}
	}

	return 0;
}

static int setup_ssi_controller(struct augentix_qspi_slave *priv, struct spi_slave *slave)
{
#if defined(CONFIG_OSAKA)
	u32 csr08 = 0;
	u32 csr09 = 0;
	u32 csr11 = 0;

	if (slave->dma_mode == 1)
		csr08 |= (QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	else
		csr08 &= ~(QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);

	csr08 |= (slave->tmode << SPI_TRANSFER_MODE_OFFSET) | (0 << SPI_INST_FORMAT_OFFSET) |
	         (0 << SPI_ADDR_FORMAT_OFFSET) | (slave->frame_format << SPI_FRAME_FORMAT_OFFSET);
	hc_writel(priv, AGTX_SPI_WORD8, csr08);

	csr09 = (1 << SPI_INST_MSB_FRIST_OFFSET) | (1 << SPI_ADDR_MSB_FRIST_OFFSET) | (0 << SPI_WR_MSB_FRIST_OFFSET) |
	        (0 << SPI_RD_MSB_FRIST_OFFSET) | (0 << SPI_TX_NIB_SWAP_EN_OFFSET) | (0 << SPI_RX_NIB_SWAP_EN_OFFSET);
	hc_writel(priv, AGTX_SPI_WORD9, csr09);

	hc_writel(priv, AGTX_SPI_WORD10, slave->inst_set);

	csr11 = (slave->ndf << SPI_NDF_OFFSET);
	hc_writel(priv, AGTX_SPI_WORD11, csr11);
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
	u32 qw07 = 0;
	u32 qw08 = 0;
	u32 qw09 = 0;
	u32 qw10 = 0;

	if (slave->dma_mode == 1) {
		qw07 |= (QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	} else {
		qw07 &= ~(QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	}

	qw07 |= (slave->tmode << SPI_TRANSFER_MODE_OFFSET) | (0 << SPI_TRANSFER_TYPE_OFFSET) |
	        (slave->frame_format << SPI_FRAME_FORMAT_OFFSET);
	hc_writel(priv, AGTX_SPI_WORD7, qw07);

	qw08 = (1 << SPI_MSB_FIRST_OFFSET) | (0 << SPI_ENDIAN_SEL_OFFSET);
	hc_writel(priv, AGTX_SPI_WORD8, qw08);

	qw09 = (slave->inst_set) | (slave->data_frame_size << SPI_DATA_FRAME_SIZE_OFFSET);
	hc_writel(priv, AGTX_SPI_WORD9, qw09);

	/* QSPI10 - Number of Data Frames */
	qw10 = (slave->ndf << SPI_NDF_OFFSET);
	hc_writel(priv, AGTX_SPI_WORD10, qw10);
#else
	u32 qw08, qw09, qw14, qw08_len;

	/* QSPI14 - DMA mode selection */
	qw14 = hc_readl(priv, AGTX_SPI_WORD14);

	if (slave->dma_mode == 1) {
		qw14 |= QSPI_DMA_M__EN;
	} else {
		qw14 &= ~QSPI_DMA_M__EN;
	}

	hc_writel(priv, AGTX_SPI_WORD14, qw14);

	/* QSPI08 */
	qw08_len = (1 << 10) | (0 << 12) | (0 << 14);
	qw08 = (slave->tmode << SPI_TRANSFER_MODE_OFFSET) | (slave->frame_format << SPI_FRAME_FORMAT_OFFSET) |
	       (slave->data_frame_size << SPI_DATA_FRAME_SIZE_OFFSET) | qw08_len | (slave->inst_set);
	hc_writel(priv, AGTX_SPI_WORD8, qw08);

	/* QSPI09 - Number of Data Frames */
	if (slave->tmode == QSPI_TMOD__READ) {
		qw09 = (slave->ndf << SPI_NDF_OFFSET);
	} else {
		qw09 = (slave->ndfw << SPI_NDFW_OFFSET);
	}
	hc_writel(priv, AGTX_SPI_WORD9, qw09);

#endif //CONFIG_SAPPORO

	return 0;
}

static inline struct augentix_qspi_slave *to_augentix_qspi_priv(struct spi_slave *slave)
{
	return container_of(slave, struct augentix_qspi_slave, slave);
}

void spi_init(void)
{
}

int spi_cs_is_valid(unsigned int bus, unsigned int cs)
{
	return 1;
}

void agtx_qspi_init(struct augentix_qspi_slave *priv)
{
	//u32 qw10;

	/* QSPI01 - Engine enable */
	hc_writel(priv, AGTX_SPI_WORD1, 1);

	/* QSPI10 */
	/* the clock configuration is done in SPL phase, by calling the interface from cpvs
	priv->freq = CONFIG_AGTX_QSPI_FREQ;
	//priv->freq = QSPI_IF_CLK_46875KHZ;
	//priv->freq = QSPI_IF_CLK_93750KHZ;
	priv->clk_div = QSPI_REF_CLK_187500KHZ / priv->freq;
	qw10 = hc_readl(priv, AGTX_SPI_WORD10);
	qw10 = (qw10 & 0xFFFFFF00) | (priv->clk_div << SPI_SCK_DV_OFFSET);
	hc_writel(priv, AGTX_SPI_WORD10, qw10);
	*/
	/* Clear all IRQ */
	hc_writel(priv, WORD_IRQ_CLEAR, ~0);
}

struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs, unsigned int max_hz, unsigned int mode)
{
	struct augentix_qspi_slave *priv;

	if (!spi_cs_is_valid(bus, cs)) {
		printf("cs is not valid\n");
		return NULL;
	}

	priv = spi_alloc_slave(struct augentix_qspi_slave, bus, cs);
	if (!priv) {
		printf("cs is not valid\n");
		return NULL;
	}

	priv->regs_qspi = (void *)QSPI_BASE;
	priv->regs_qspir = (void *)QSPIR_BASE;
	priv->regs_qspiw = (void *)QSPIW_BASE;
	priv->regs_pc_syscfg_dbg_mon = (void *)PC_SYSCFG_DBG_MON_BASE;
	priv->mode = mode;
	priv->slave.mode_rx = CONFIG_AGTX_QSPI_WIRES << 1;	/* receive with 4 wires */
	//priv->slave.max_write_size = (CONFIG_AGTX_QSPI_TX_FIFO - 2) * 4;	// QSPI_TX_FIFO_DEPTH = 15

	// IOSEL: QSPI
	//writel(0x00000001, 0x80001598);
	//writel(0x00000001, 0x8000159C);
	//writel(0x00000001, 0x800015A0);
	//writel(0x00000001, 0x800015A4);
	//writel(0x00000001, 0x800015A8);
	//writel(0x00000001, 0x800015AC);
	// QSPI_D2, QSPI_D3: ST enable, pull-up enable
	//writel(0x00080001, 0x8000145C);
	//writel(0x00080001, 0x80001460);

	agtx_qspi_init(priv);

	return &priv->slave;
}

void spi_free_slave(struct spi_slave *slave)
{
	struct augentix_qspi_slave *ss = to_augentix_qspi_priv(slave);
	free(ss);
}

int spi_claim_bus(struct spi_slave *slave)
{
	struct augentix_qspi_slave *priv = to_augentix_qspi_priv(slave);

	setup_ssi_controller(priv, slave);

	return 0;
}

void spi_release_bus(struct spi_slave *slave)
{
}

/*
 * dout: 	data from DRAM
 * din:		data from Flash
 */
int spi_xfer(struct spi_slave *slave, unsigned int bitlen, const void *dout, void *din, unsigned long flags)
{
	struct augentix_qspi_slave *priv = to_augentix_qspi_priv(slave);
	const u8 *tx = dout;
	u8 *rx = din;

	priv->len = bitlen;

	if (tx) {
		priv->tx = (void *)tx;
		priv->tx_end = priv->tx + priv->len;
	} else if (rx) {
		priv->rx = rx;
		priv->rx_end = priv->rx + priv->len;
	} else {
		printf("Don't support tx=NULL and rx=NULL\n");
		return -EINVAL;
	}

	if (slave->bits_per_word == 8) {
		priv->n_bytes = 1;
	} else if (slave->bits_per_word == 16) {
		priv->n_bytes = 2;
	} else if (slave->bits_per_word == 32) {
		priv->n_bytes = 4;
	}

	if (tx && (flags || slave->dma_mode == 0)) {
		hc_writer(priv);
	}

	if (!flags) {
		if (rx) {
			poll_transfer_rx(priv, slave);
		} else {
			poll_transfer_tx(priv, slave);
		}
	}

	flags = 0;

	return 0;
}
