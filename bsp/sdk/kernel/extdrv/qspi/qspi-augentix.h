#ifndef AUGE_SPI_HEADER_H
#define AUGE_SPI_HEADER_H
#include <linux/io.h>
#include <linux/version.h>
#include <linux/interrupt.h>

#include <linux/spi/augentix_serial_flash.h>

/* QSPI Register offsets */
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

/* QSPIR Register offsets */
#define LR032_00 0x00
#define LR032_01 0x04
#define LR032_03 0x0C
#define LR032_04 0x10
#define LR032_11 0x2c
#define LR032_12 0x30
#define LR032_13 0x34
#define LR032_40 0xA0

#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
#define WORD_IRQ_CLEAR AGTX_SPI_WORD2
#define WORD_IRQ_STATUS AGTX_SPI_WORD3
#define WORD_IRQ_MASK AGTX_SPI_WORD4
#define WORD_TX_FIFO AGTX_SPI_WORD11
#define WORD_RX_FIFO AGTX_SPI_WORD12

/* Bit fields in WORD QSPI00 */
#define SPI_START_OFFSET 0

/* Bit fields in WORD QSPI01 */
#define SPI_ENABLE_OFFSET 0
#define SPI_SD_OFFSET 8
#define SPI_SLP_OFFSET 9

/* Bit fields in WORD QSPI02 */
#define SPI_IRQ_CLR_SPI_DONE_OFFSET 0
#define SPI_IRQ_CLR_AUTO_DONE_OFFSET 2
#define SPI_IRQ_CLR_DONE_OFFSET 4
#define SPI_IRQ_CLR_ERROR_OFFSET 6
#define SPI_IRQ_CLR_TX_FIFO_FULL_OFFSET 8
#define SPI_IRQ_CLR_TX_FIFO_EMPTY_OFFSET 10
#define SPI_IRQ_CLR_RX_FIFO_FULL_OFFSET 12
#define SPI_IRQ_CLR_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI03 */
#define SPI_STATUS_SPI_DONE_OFFSET 0
#define SPI_STATUS_AUTO_DONE_OFFSET 2
#define SPI_STATUS_DONE_OFFSET 4
#define SPI_STATUS_ERROR_OFFSET 6
#define SPI_STATUS_TX_FIFO_FULL_OFFSET 8
#define SPI_STATUS_TX_FIFO_EMPTY_OFFSET 10
#define SPI_STATUS_RX_FIFO_FULL_OFFSET 12
#define SPI_STATUS_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI04 */
#define SPI_IRQ_MASK_SPI_DONE_OFFSET 0
#define SPI_IRQ_MASK_AUTO_DONE_OFFSET 2
#define SPI_IRQ_MASK_DONE_OFFSET 4
#define SPI_IRQ_MASK_ERROR_OFFSET 6
#define SPI_IRQ_MASK_TX_FIFO_FULL_OFFSET 8
#define SPI_IRQ_MASK_TX_FIFO_EMPTY_OFFSET 10
#define SPI_IRQ_MASK_RX_FIFO_FULL_OFFSET 12
#define SPI_IRQ_MASK_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI05 */
#define SPI_SPI_BUSY_OFFSET 0
#define SPI_SPI_DONE_OFFSET 2
#define SPI_AUTO_BUSY_OFFSET 4
#define SPI_AUTO_DONE_OFFSET 6
#define SPI_DONE_OFFSET 8
#define SPI_ERROR_OFFSET 10
#define SPI_TX_FIFO_FULL_OFFSET 16
#define SPI_TX_FIFO_EMPTY_OFFSET 18
#define SPI_RX_FIFO_FULL_OFFSET 20
#define SPI_RX_FIFO_EMPTY_OFFSET 22

/* Bit fields in WORD QSPI06 */
#define SPI_MST_STATE_OFFSET 0
#define SPI_AUTO_STATE_OFFSET 4
#define SPI_CNT_FRAME_OFFSET 16

/* Bit fields in WORD QSPI07 */
#define SPI_DF_CNT_OFFSET 0
#define SPI_TDF_CNT_OFFSET 16

/* Bit fields in WORD QSPI08 */
#define SPI_TRANSFER_MODE_OFFSET 0
#define SPI_FRAME_FORMAT_OFFSET 2
#define SPI_DATA_FRAME_SIZE_OFFSET 4
#define SPI_MSB_FIRST_OFFSET 10
#define SPI_ENDIAN_SEL_OFFSET 12
#define SPI_TRANSFER_TYPE_OFFSET 14
#define SPI_INST_L_OFFSET 16
#define SPI_ADDR_L_OFFSET 18
#define SPI_WAIT_L_OFFSET 24

/* Bit fields in WORD QSPI09 */
#define SPI_NDF_OFFSET 0
#define SPI_NDFW_OFFSET 16

/* Bit fields in WORD QSPI10 */
#define SPI_SCK_DV_OFFSET 0
#define SPI_SCK_POL_OFFSET 8
#define SPI_SCK_POL_LOW 0x0
#define SPI_SCK_POL_HIGH 0x1
#define SPI_SCK_PHA_OFFSET 10
#define SPI_SCK_PHA_LOW 0x0
#define SPI_SCK_PHA_HIGH 0x1
#define SPI_SCK_DLY_OFFSET 16
#define SPI_RX_DELAY_OFFSET 24

/* Bit fields in WORD QSPI11 */
#define SPI_WR_DATA_OFFSET 0
/* Bit fields in WORD QSPI12 */
#define SPI_RD_DATA_OFFSET 0
/* Bit fields in WORD QSPI13 */
#define SPI_RD_DATA_R_OFFSET 0

/* Bit fields in WORD QSPI14 */
#define SPI_DMA_MODE_EN_OFFSET 0
#define SPI_AUTO_MODE_EN_OFFSET 8
#define SPI_STATUS_BO_SEL_OFFSET 10
#define SPI_TIMEOUT_FREE_OFFSET 12
#define SPI_PRE_SCALER_TH_OFFSET 16

#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define WORD_IRQ_CLEAR AGTX_SPI_WORD2
#define WORD_IRQ_STATUS AGTX_SPI_WORD3
#define WORD_IRQ_MASK AGTX_SPI_WORD4
#define WORD_TX_FIFO AGTX_SPI_WORD14
#define WORD_RX_FIFO AGTX_SPI_WORD15

/* Bit fields in WORD QSPI00 */
#define SPI_START_OFFSET 0

/* Bit fields in WORD QSPI01 */
#define SPI_ENABLE_OFFSET 0
#define SPI_SD_OFFSET 8
#define SPI_SLP_OFFSET 16

/* Bit fields in WORD QSPI02 */
#define SPI_IRQ_CLR_SPI_DONE_OFFSET 0
#define SPI_IRQ_CLR_DONE_OFFSET 4
#define SPI_IRQ_CLR_ERROR_OFFSET 6
#define SPI_IRQ_CLR_TX_FIFO_FULL_OFFSET 8
#define SPI_IRQ_CLR_TX_FIFO_EMPTY_OFFSET 10
#define SPI_IRQ_CLR_RX_FIFO_FULL_OFFSET 12
#define SPI_IRQ_CLR_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI03 */
#define SPI_STATUS_SPI_DONE_OFFSET 0
#define SPI_STATUS_DONE_OFFSET 4
#define SPI_STATUS_ERROR_OFFSET 6
#define SPI_STATUS_TX_FIFO_FULL_OFFSET 8
#define SPI_STATUS_TX_FIFO_EMPTY_OFFSET 10
#define SPI_STATUS_RX_FIFO_FULL_OFFSET 12
#define SPI_STATUS_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI04 */
#define SPI_IRQ_MASK_SPI_DONE_OFFSET 0
#define SPI_IRQ_MASK_DONE_OFFSET 4
#define SPI_IRQ_MASK_ERROR_OFFSET 6
#define SPI_IRQ_MASK_TX_FIFO_FULL_OFFSET 8
#define SPI_IRQ_MASK_TX_FIFO_EMPTY_OFFSET 10
#define SPI_IRQ_MASK_RX_FIFO_FULL_OFFSET 12
#define SPI_IRQ_MASK_RX_FIFO_EMPTY_OFFSET 14

/* Bit fields in WORD QSPI05 */
#define SPI_SPI_BUSY_OFFSET 0
#define SPI_SPI_DONE_OFFSET 2
#define SPI_ERROR_OFFSET 4
#define SPI_TX_FIFO_FULL_OFFSET 6
#define SPI_TX_FIFO_EMPTY_OFFSET 8
#define SPI_RX_FIFO_FULL_OFFSET 10
#define SPI_RX_FIFO_EMPTY_OFFSET 12

/* Bit fields in WORD QSPI06 */
#define SPI_MST_STATE_OFFSET 0
#define SPI_CNT_FRAME_OFFSET 8

/* Bit fields in WORD QSPI07 */
#define SPI_TRANSFER_MODE_OFFSET 0
#define SPI_TRANSFER_TYPE_OFFSET 8
#define SPI_DMA_MODE_EN_OFFSET 16
#define SPI_FRAME_FORMAT_OFFSET 24

/* Bit fields in WORD QSPI08 */
#define SPI_MSB_FIRST_OFFSET 0
#define SPI_ENDIAN_SEL_OFFSET 8

/* Bit fields in WORD QSPI09 */
#define SPI_INST_L_OFFSET 0
#define SPI_ADDR_L_OFFSET 8
#define SPI_WAIT_L_OFFSET 16
#define SPI_DATA_FRAME_SIZE_OFFSET 24

/* Bit fields in WORD QSPI10 */
#define SPI_NDF_OFFSET 0

/* Bit fields in WORD QSPI11 */
#define SPI_WR_CYCLE_OFFSET 0
#define SPI_RD_CYCLE_OFFSET 8

/* Bit fields in WORD QSPI12 */
#define SPI_SCK_DV_OFFSET 0
#define SPI_SCK_POL_OFFSET 8
#define SPI_SCK_PHA_OFFSET 10
#define SPI_SCK_PHASE_SEL 16
#define SPI_SCK_DLY_OFFSET 24

/* Bit fields in WORD QSPI13 */
#define SPI_RX_DELAY_OFFSET 0
#define SPI_RX_SMPL_PHASE_SEL 8

/* Bit fields in WORD QSPI14 */
#define SPI_WR_DATA_OFFSET 0
/* Bit fields in WORD QSPI15 */
#define SPI_RD_DATA_OFFSET 0
/* Bit fields in WORD QSPI16 */
#define SPI_RD_DATA_INV_OFFSET 0

#ifdef CONFIG_OPTEE
/* Bit fields in WORD QSPI18 (QSPI_SCK_GATING_FUNC_CTRL)
 * Check #91613 for details 
 */
#define SPI_LOCK_FLAG_OPTEE 0x1
/* Bit fields in WORD QSPI19 (QSPI_DEBUG_MON_SEL)
 * Check #91613 for details 
 */
#define SPI_LOCK_FLAG_LINUX 0x1

/* Bit fields in WORD QSPIR13 (LR032_13)
 * Check #91613 for details 
 */
#define SPI_LOCK_TURN_OPTEE 0x0
#define SPI_LOCK_TURN_LINUX 0x1
#endif /* CONFIG_OPTEE */
#elif defined(CONFIG_OSAKA)
#define WORD_IRQ_CLEAR AGTX_SPI_WORD3
#define WORD_IRQ_STATUS AGTX_SPI_WORD4
#define WORD_IRQ_MASK AGTX_SPI_WORD5
#define WORD_TX_FIFO AGTX_SPI_WORD12
#define WORD_RX_FIFO AGTX_SPI_WORD13

/* Bit fields in WORD QSPI04 */
#define SPI_STATUS_SPI_DONE_OFFSET 0
#define SPI_STATUS_DONE_OFFSET 4
#define SPI_STATUS_ERROR_OFFSET 8
#define SPI_STATUS_TX_FIFO_FULL_OFFSET 16
#define SPI_STATUS_TX_FIFO_EMPTY_OFFSET 18
#define SPI_STATUS_RX_FIFO_FULL_OFFSET 20
#define SPI_STATUS_RX_FIFO_EMPTY_OFFSET 22
#define SPI_STATUS_TX_BUF_FULL_OFFSET 24
#define SPI_STATUS_TX_BUF_EMPTY_OFFSET 26
#define SPI_STATUS_RX_BUF_FULL_OFFSET 28
#define SPI_STATUS_RX_BUF_EMPTY_OFFSET 30
/* Bit fields in WORD QSPI08 */
#define SPI_TRANSFER_MODE_OFFSET 0
#define SPI_DMA_MODE_EN_OFFSET 4
#define SPI_INST_FORMAT_OFFSET 8
#define SPI_ADDR_FORMAT_OFFSET 16
#define SPI_FRAME_FORMAT_OFFSET 24
/* Bit fields in WORD QSPI09 */
#define SPI_INST_MSB_FRIST_OFFSET 0
#define SPI_ADDR_MSB_FRIST_OFFSET 4
#define SPI_WR_MSB_FRIST_OFFSET 8
#define SPI_RD_MSB_FRIST_OFFSET 12
#define SPI_TX_NIB_SWAP_EN_OFFSET 16
#define SPI_RX_NIB_SWAP_EN_OFFSET 24
/* Bit fields in WORD QSPI11 */
#define SPI_NDF_OFFSET 0
#define SPI_SWITCH_INST_ADDR_STATE_OFFSET 24
#endif /* Kyoto, Sapporo, or Osaka */

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
#define QSPI_WAIT_L__8_CYCLE 0x7

/* dma mode selection */
#define QSPI_DMA_M__DIS 0
#define QSPI_DMA_M__EN 1

#define QSPI_WAIT_DONE 0x01

/* IP definition */
/* FIFO size in byte */
#define QSPI_RX_FIFO_DEPTH 16

#ifdef CONFIG_FPGA
#define QSPI_TX_FIFO_DEPTH 13
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define QSPI_TX_FIFO_DEPTH 13
#else
#define QSPI_TX_FIFO_DEPTH 14
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

/*Hardware Settings*/
#define HW_SSI_FIFO_DEPTH 16

struct auge_spi_s {
	struct device *dev;
	struct spi_master *master;
	struct spi_device *cur_dev;
	char name[16];

	void __iomem *regs_qspi;
	void __iomem *regs_qspir;
	void __iomem *regs_qspiw;
	void __iomem *regs_darb;
	void __iomem *regs_pc_syscfg_dbg_mon;

	unsigned long paddr;
	int irq;
	u32 fifo_len; /* depth of the FIFO buffer */
	u32 max_freq; /* max bus freq supported */
	u32 freq;
	u32 clk_div; /* calculate the clk_div for qspi */

	u16 bus_num;

	struct completion xfer_completion;

	/* Message Transfer pump */
	struct tasklet_struct pump_transfers;

	/* Current message transfer state info */
	struct spi_message *cur_msg;
	struct spi_transfer *cur_transfer;
	struct chip_data *cur_chip;
	struct chip_data *prev_chip;
	size_t len;
	void *tx;
	void *tx_end;
	void *rx;
	void *rx_end;
	dma_addr_t rx_dma;
	dma_addr_t tx_dma;
	size_t rx_map_len;
	size_t tx_map_len;
	u8 max_bits_per_word; /* maxim is 16b */
	u32 dma_width;
	u8 fifo_entry;
	irqreturn_t (*transfer_handler)(struct auge_spi_s *auge_spi);
	void (*cs_control)(u32 command);
	spinlock_t lock;

	/* Dma info */
	int dma_inited;
	struct dma_chan *txchan;
	struct scatterlist tx_sgl;
	struct dma_chan *rxchan;
	struct scatterlist rx_sgl;
	int dma_chan_done;
	struct device *dma_dev;
	dma_addr_t dma_addr; /* phy address of the Data register */
	struct dw_spi_dma_ops *dma_ops;
	void *dma_priv; /* platform relate info */

	/* Bus interface info */
	void *priv;
#ifdef CONFIG_DEBUG_FS
	struct dentry *debugfs;
#endif
};

static inline u32 auge_readl(struct auge_spi_s *auge_spi, u32 offset)
{
	return __raw_readl(auge_spi->regs_qspi + offset);
}

static inline u16 auge_readw(struct auge_spi_s *auge_spi, u32 offset)
{
	return __raw_readw(auge_spi->regs_qspi + offset);
}

static inline void auge_writel(struct auge_spi_s *auge_spi, u32 offset, u32 val)
{
	__raw_writel(val, auge_spi->regs_qspi + offset);
}

static inline void auge_writew(struct auge_spi_s *auge_spi, u32 offset, u16 val)
{
	__raw_writew(val, auge_spi->regs_qspi + offset);
}

static inline u32 auge_read_io_reg(struct auge_spi_s *auge_spi, u32 offset)
{
	return auge_readl(auge_spi, offset);
}

static inline void auge_write_io_reg(struct auge_spi_s *auge_spi, u32 offset, u32 val)
{
	auge_writel(auge_spi, offset, val);
}

static inline void spi_set_clk(struct auge_spi_s *auge_spi, u32 div)
{
	auge_writel(auge_spi, AGTX_SPI_WORD10, div);
}

static inline void spi_enable_chip(struct auge_spi_s *auge_spi, int enable)
{
	auge_writel(auge_spi, AGTX_SPI_WORD1, (enable ? 1 : 0));
}

static inline void spi_shutdown_chip(struct auge_spi_s *auge_spi)
{
	spi_enable_chip(auge_spi, 0);
}

/* Disable IRQ bits */
static inline void spi_mask_intr(struct auge_spi_s *auge_spi, u32 mask)
{
	u32 new_mask;

	new_mask = auge_readl(auge_spi, WORD_IRQ_MASK) | mask;
	auge_writel(auge_spi, WORD_IRQ_MASK, new_mask);
}

/* Enable IRQ bits */
static inline void spi_umask_intr(struct auge_spi_s *auge_spi, u32 mask)
{
	u32 new_mask;

	new_mask = auge_readl(auge_spi, WORD_IRQ_MASK) & ~mask;
	auge_writel(auge_spi, WORD_IRQ_MASK, new_mask);
}

/*
 * This does disable the SPI controller, interrupts, and re-enable the
 * controller back. Transmit and receive FIFO buffers are cleared when the
 * device is disabled.
 */
static inline void spi_reset_chip(struct auge_spi_s *auge_spi)
{
	spi_enable_chip(auge_spi, 0); // QSPI01 - Engine disable
	auge_writel(auge_spi, WORD_IRQ_CLEAR, ~0); // irq clear
	spi_mask_intr(auge_spi, ~0); // Disable all
	// Enable DONE
	spi_umask_intr(auge_spi, (1 << SPI_STATUS_DONE_OFFSET));

	/* software reset */
	//hc18xx_sw_rst(SW_RST_QSPI); // 0x80000414 bit16
	spi_enable_chip(auge_spi, 1); // QSPI01 - Engine enable
}

#if defined(CONFIG_OPTEE)
void auge_spi_lock_optee(void);
void auge_spi_unlock_optee(void);
#endif /* CONFIG_OPTEE */

#endif
