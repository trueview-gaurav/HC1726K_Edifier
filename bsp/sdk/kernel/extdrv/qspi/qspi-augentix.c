#include <linux/clk.h>
#include <linux/err.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/spi/spi.h>
#include <linux/scatterlist.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/of_platform.h>
#include <linux/dma-mapping.h>
#include <linux/delay.h>
#include <linux/version.h>
#include <asm/barrier.h>

#include <linux/spi/qspi-augentix.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
#include <linux/spi/spi-mem.h>
#endif

#define RX_BUFFER_SIZE 512
#define TX_BUFFER_SIZE 256

#define DRIVER_NAME "auge_spi"

#define IS_DMA 1
#define IS_POLL_MODE 0

static volatile uint32_t transfer_state = 0; // 0=idle, 1=transfering, 2=irq handled
static struct auge_spi_s * g_auge_spi = NULL;
int auge_qspi_get_irq_status(struct spi_master *master);

static irqreturn_t auge_spi_irq(int irq, void *dev_id)
{
	struct spi_master *master = dev_id;
	struct auge_spi_s *auge_spi = spi_master_get_devdata(master);
	u32 irq_status = auge_readl(auge_spi, WORD_IRQ_STATUS);

	if (!irq_status)
		return IRQ_NONE;

	if (irq_status & (1 << SPI_STATUS_DONE_OFFSET)) {
		auge_writel(auge_spi, WORD_IRQ_CLEAR, ~0); // irq clear
		transfer_state = 2;
		complete(&auge_spi->xfer_completion);
		return IRQ_HANDLED;
	} else {
		if (transfer_state == 2) {
			// The HW has chance trigger IRQ twice.
			return IRQ_HANDLED;
		}
	}

	if (!master->cur_msg) {
		spi_mask_intr(auge_spi, ~0);
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

/* Restart the controller, disable all interrupts, clean rx fifo */
static void spi_hw_init(struct device *dev, struct auge_spi_s *auge_spi)
{
	u32 val __attribute__((unused));
	//u32 qw10;
	spi_reset_chip(auge_spi);

	/* QSPI10 */
	/*
	qw10 = auge_readl(auge_spi, AGTX_SPI_WORD10);
	qw10 = (qw10 & 0xFFFFFF00) | (auge_spi->clk_div << SPI_SCK_DV_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD10, qw10);
	*/

#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
	/* DARB QSPIR*/
	val = __raw_readl(auge_spi->regs_darb + 0x58) & ~0x03;
	val |= 0x01;
	__raw_writel(val, auge_spi->regs_darb + 0x58);
	/* DARB QSPIW*/
	val = __raw_readl(auge_spi->regs_darb + 0x38) & ~0x03;
	val |= 0x01;
	__raw_writel(val, auge_spi->regs_darb + 0x38);

	/* QSPIR TARGET_FIFO_LEVEL */
	val = __raw_readl(auge_spi->regs_qspir + 0x20) & ~0x07f;
	val |= 48;
	__raw_writel(val, auge_spi->regs_qspir + 0x20);
#endif
}

/* This may be called twice for each spi dev */
static int auge_spi_setup(struct spi_device *spi)
{
	struct chip_data *chip;

	/* Only alloc on first setup */
	chip = spi_get_ctldata(spi);
	if (!chip) {
		chip = kzalloc(sizeof(struct chip_data), GFP_KERNEL);
		if (!chip) {
			pr_err("alloc chip data failure\n");
			return -ENOMEM;
		}
		spi_set_ctldata(spi, chip);
	}

	chip->poll_mode = IS_POLL_MODE;
	chip->data_frame_size = QSPI_DFS__32_BIT;
	chip->dma_mode = 0;

	pr_notice("run auge_spi_setup done\n");
	return 0;
}

static void auge_spi_cleanup(struct spi_device *spi)
{
	struct chip_data *chip = spi_get_ctldata(spi);

	kfree(chip);
	spi_set_ctldata(spi, NULL);
}

static void auge_writer_fifo(struct auge_spi_s *auge_spi, const void *buf, int write_len)
{
	u32 txw;

	while (write_len > 0) {
		txw = 0;
		memcpy(&txw, buf, 4);
		auge_write_io_reg(auge_spi, WORD_TX_FIFO, txw);
		buf += 4;
		write_len -= 4;
	}
}

static void auge_read_fifo(struct auge_spi_s *auge_spi, void *buf, uint32_t read_len)
{
	u32 rxw;

	while (read_len) {
		rxw = auge_read_io_reg(auge_spi, WORD_RX_FIFO);
		if (read_len < 4) {
			while (read_len) {
				*(u8 *)buf = rxw & 0xff;
				buf++;
				read_len--;
				rxw >>= 8;
			}
		} else {
			*(u32 *)buf = rxw;
			buf += 4;
			read_len -= 4;
		}
	}
}

static int wait_done(struct auge_spi_s *auge_spi, struct chip_data *chip)
{
	u32 status;
	u32 expect;
	int ms;

	if (chip->poll_mode == 1) {
		auge_writel(auge_spi, AGTX_SPI_WORD0, 1); //Action start

		/* Wait for TX FIFO empty and DONE flag raised */
		expect = (1 << SPI_STATUS_DONE_OFFSET); // expect DONE = 1

		do {
			status = auge_readl(auge_spi, WORD_IRQ_STATUS);
			if (status & (1 << SPI_STATUS_ERROR_OFFSET)) {
				pr_err("\n\nQSPI error!\n\n");
				auge_qspi_get_irq_status(auge_spi->master);
				auge_writel(auge_spi, WORD_IRQ_CLEAR, ~0); // irq clear
				return -EIO;
			}
			if (status & expect) {
				break;
			}
		} while (1);
		auge_writel(auge_spi, WORD_IRQ_CLEAR, ~0); // irq clear
	} else {
		reinit_completion(&auge_spi->xfer_completion);
		smp_wmb(); // Avoid race condition (#101146)
		auge_writel(auge_spi, AGTX_SPI_WORD0, 1); //Action start
		ms = wait_for_completion_timeout(&auge_spi->xfer_completion, msecs_to_jiffies(1000));

		status = auge_readl(auge_spi, WORD_IRQ_STATUS);
		if (status & (1 << SPI_STATUS_ERROR_OFFSET)) {
			pr_err("\n\nQSPI error!\n\n");
			auge_qspi_get_irq_status(auge_spi->master);
			auge_writel(auge_spi, WORD_IRQ_CLEAR, ~0); // irq clear
			return -EIO;
		}
#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
		if (readl_relaxed(auge_spi->regs_qspiw + 8) & 0x100) {
			pr_err("\n\nQSPI Read BW Insufficient\n\n");
			auge_qspi_get_irq_status(auge_spi->master);
			return -EIO;
		}
		if (readl_relaxed(auge_spi->regs_qspir + 8) & 0x100) {
			pr_err("\n\nQSPI Write BW Insufficient\n\n");
			auge_qspi_get_irq_status(auge_spi->master);
			return -EIO;
		}
#endif
		if (ms == 0) {
			pr_err("\n\nQSPI time out\n\n");
			auge_qspi_get_irq_status(auge_spi->master);
			return -ETIMEDOUT;
		}
	}

	return 0;
}

static int transfer_write(struct auge_spi_s *auge_spi, struct chip_data *chip, const void *buf, uint32_t len)
{
	dma_addr_t dma_dest;
	void __iomem *reg;
	u32 flush_len = (len + 7) >> 3;
	int ret;
#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
	u32 val;
#endif

	if (chip->dma_mode == 0) {
		auge_writer_fifo(auge_spi, buf, len);
		ret = wait_done(auge_spi, chip);
	} else {
		dma_dest = dma_map_single(auge_spi->dev, (void *)buf, len, DMA_TO_DEVICE);

		reg = auge_spi->regs_qspir;

		writel_relaxed(0x101, reg + LR032_01); //IRQ_CLEAR_FRAME_END, IRQ_CLEAR_BW_INSUFFICIENT
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		writel_relaxed((len + 3) >> 2, reg + LR032_11); //PIXEL_FLUSH_LEN
		writel_relaxed(flush_len, reg + LR032_12); //FIFO_FLUSH_LEN
#else
		writel_relaxed(len >> 2, reg + LR032_11); //PIXEL_FLUSH_LEN
		writel_relaxed(flush_len, reg + LR032_12); //FIFO_FLUSH_LEN
#endif
		writel_relaxed(dma_dest >> 3, reg + LR032_40); //INI_ADDR_LINEAR

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		writel_relaxed(1, reg + LR032_00); //FRAME_START
#else
		auge_writel(auge_spi, 0x168, 2); //QSPI.QSPI.debug_mon_sel  = 2

		val = readl_relaxed(auge_spi->regs_pc_syscfg_dbg_mon) & ~0x1f;
		val |= 7;
		writel_relaxed(val, auge_spi->regs_pc_syscfg_dbg_mon); //PC.SYSCFG.debug_mon_sel = 7

		val = readl_relaxed(auge_spi->regs_qspir + 0x10) & ~0x1000000;
		val |= 1 << 24;
		writel_relaxed(val, auge_spi->regs_qspir + 0x10); //QSPIR.QSPIR.debug_mon_sel = 1

		writel_relaxed(1, reg + LR032_00); //FRAME_START

		while ((readl_relaxed(auge_spi->regs_pc_syscfg_dbg_mon + 4) & 0x3f) != (flush_len - 1)) {
		}
#endif
		ret = wait_done(auge_spi, chip);
		dma_unmap_single(auge_spi->dev, dma_dest, len, DMA_TO_DEVICE);
	}

	return ret;
}

static int transfer_read(struct auge_spi_s *auge_spi, struct chip_data *chip, void *buf, uint32_t len)
{
	dma_addr_t dma_dest;
	void __iomem *reg;
	int ret;

	if (chip->dma_mode == 0) {
		ret = wait_done(auge_spi, chip);
		auge_read_fifo(auge_spi, buf, len);
	} else {
		dma_dest = dma_map_single(auge_spi->dev, buf, len, DMA_FROM_DEVICE);
		reg = auge_spi->regs_qspiw;

		writel_relaxed(0x101, reg + LR032_01); //IRQ_CLEAR_FRAME_END, IRQ_CLEAR_BW_INSUFFICIENT
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		writel_relaxed((len + 3) >> 2, reg + LR032_11); //PIXEL_FLUSH_LEN
#else
		writel_relaxed(len >> 2, reg + LR032_11); //PIXEL_FLUSH_LEN
#endif
		writel_relaxed(dma_dest >> 3, reg + LR032_40); //INI_ADDR_LINEAR

		writel_relaxed(1, reg + LR032_00); //FRAME_START

		ret = wait_done(auge_spi, chip);
		dma_unmap_single(auge_spi->dev, dma_dest, len, DMA_FROM_DEVICE);
	}

	return ret;
}

#ifdef CONFIG_OPTEE
/* Peterson Algo. implemented using the following CSRs (#91613):
 *   QSPI W18: sck_wr_state_gating_en: OPTEE flag (Confirmed with Jason.
 *   Tsai that the functionality of this CSR has been removed, and it can
 *   be used without affecting HW functionality)
 *   QSPI W19: qspi_debug_mon_sel: Linux flag
 *   QSPIR W13: turn (Confirmed with Molly that it is approved for use.)
 */
static void set_spi_lock_flag(struct auge_spi_s *auge_spi)
{
	u32 qw18 = 0;
	u32 qrw13 = 0;
	int ms;

	/* 1. Set lock flag */
	writel(SPI_LOCK_FLAG_LINUX, auge_spi->regs_qspi + AGTX_SPI_WORD19);

	/* 2. Set turn to OP-TEE */
	writel(SPI_LOCK_TURN_OPTEE, auge_spi->regs_qspir + LR032_13);

	/* 3. Check turn to determine whether to access the SPI controller 
	 * (critical section).
	 * OP-TEE's turn: wait for completion
	 * Linux's turn: directly access the SPI controller
	 */
	reinit_completion(&auge_spi->xfer_completion);
	qw18 = readl(auge_spi->regs_qspi + AGTX_SPI_WORD18);
	qrw13 = readl(auge_spi->regs_qspir + LR032_13);
	while ((qw18 & SPI_LOCK_FLAG_OPTEE) && (qrw13 == SPI_LOCK_TURN_OPTEE)) {
		ms = wait_for_completion_timeout(&auge_spi->xfer_completion, msecs_to_jiffies(20));

		qw18 = readl(auge_spi->regs_qspi + AGTX_SPI_WORD18);
		qrw13 = readl(auge_spi->regs_qspir + LR032_13);
	}

	/* 4. Unset lock flag after all messages had transferred */
}

void auge_spi_lock_optee(void)
{
	set_spi_lock_flag(g_auge_spi);
}

static inline void unset_spi_lock_flag(struct auge_spi_s *auge_spi)
{
	writel(0, auge_spi->regs_qspi + AGTX_SPI_WORD19);
}

void auge_spi_unlock_optee(void)
{
	unset_spi_lock_flag(g_auge_spi);
}
#endif /* CONFIG_OPTEE */

static void setup_ssi_controller(struct auge_spi_s *auge_spi, struct chip_data *chip)
{
#if defined(CONFIG_OSAKA)
	u32 csr08 = 0;
	u32 csr09 = 0;
	u32 csr11 = 0;

	if (chip->dma_mode == 1)
		csr08 |= (QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	else
		csr08 &= ~(QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);

	/* In QSPIv4, data_format is equivalent to frame_format */
	csr08 |= (chip->tmode << SPI_TRANSFER_MODE_OFFSET) | (0 << SPI_INST_FORMAT_OFFSET) |
	         (0 << SPI_ADDR_FORMAT_OFFSET) | (chip->frame_format << SPI_FRAME_FORMAT_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD8, csr08);

	csr09 = (1 << SPI_INST_MSB_FRIST_OFFSET) | (1 << SPI_ADDR_MSB_FRIST_OFFSET) | (0 << SPI_WR_MSB_FRIST_OFFSET) |
	        (0 << SPI_RD_MSB_FRIST_OFFSET) | (0 << SPI_TX_NIB_SWAP_EN_OFFSET) | (0 << SPI_RX_NIB_SWAP_EN_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD9, csr09);

	auge_writel(auge_spi, AGTX_SPI_WORD10, chip->inst_set);

	csr11 = (chip->ndf << SPI_NDF_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD11, csr11);
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
	u32 qw07 = 0;
	u32 qw08 = 0;
	u32 qw09 = 0;
	u32 qw10 = 0;

	if (chip->dma_mode == 1) {
		qw07 |= (QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	} else {
		qw07 &= ~(QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	}

	qw07 |= (chip->tmode << SPI_TRANSFER_MODE_OFFSET) | (0 << SPI_TRANSFER_TYPE_OFFSET) |
	        (chip->frame_format << SPI_FRAME_FORMAT_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD7, qw07);

	qw08 = (1 << SPI_MSB_FIRST_OFFSET) | (0 << SPI_ENDIAN_SEL_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD8, qw08);

	qw09 = (chip->inst_set) | (chip->data_frame_size << SPI_DATA_FRAME_SIZE_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD9, qw09);

	/* QSPI10 - Number of Data Frames */
	qw10 = (chip->ndf << SPI_NDF_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD10, qw10);
#else
	u32 qw08, qw09, qw14, qw08_len;

	/* QSPI14 - DMA mode selection */
	qw14 = auge_readl(auge_spi, AGTX_SPI_WORD14);
	if (chip->dma_mode == 1) {
		qw14 |= (QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	} else {
		qw14 &= ~(QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	}
	auge_writel(auge_spi, AGTX_SPI_WORD14, qw14);

	/* QSPI08 */
	qw08_len = (1 << 10) | (0 << 12) | (0 << 14);
	qw08 = (chip->tmode << SPI_TRANSFER_MODE_OFFSET) | (chip->frame_format << SPI_FRAME_FORMAT_OFFSET) |
	       (chip->data_frame_size << SPI_DATA_FRAME_SIZE_OFFSET) | qw08_len | (chip->inst_set);
	auge_writel(auge_spi, AGTX_SPI_WORD8, qw08);

	/* QSPI09 - Number of Data Frames */
	if (chip->tmode == QSPI_TMOD__READ) {
		qw09 = (chip->ndf << SPI_NDF_OFFSET);
	} else {
		qw09 = (chip->ndfw << SPI_NDFW_OFFSET);
	}
	auge_writel(auge_spi, AGTX_SPI_WORD9, qw09);
#endif //CONFIG_SAPPORO
}

static int augespi_transfer_one_message(struct spi_master *master, struct spi_message *msg)
{
	struct auge_spi_s *auge_spi = spi_master_get_devdata(master);
	struct chip_data *chip = spi_get_ctldata(msg->spi);
	struct spi_transfer *transfer;
	int ret = 0;

	//spin_lock(&auge_spi->lock);
	transfer_state = 1;
	setup_ssi_controller(auge_spi, chip);

	list_for_each_entry (transfer, &msg->transfers, transfer_list) {
		if (transfer->tx_buf || transfer->rx_buf) {
			if (transfer->tx_buf && transfer->cs_change) {
				auge_writer_fifo(auge_spi, transfer->tx_buf, transfer->len);
			}

			if (!transfer->cs_change) {
				if (transfer->rx_buf) {
					ret = transfer_read(auge_spi, chip, transfer->rx_buf, transfer->len);
				} else {
					ret = transfer_write(auge_spi, chip, transfer->tx_buf, transfer->len);
				}
			}
		} else {
			if (transfer->len)
				dev_err(&msg->spi->dev, "Bufferless transfer has length %u\n", transfer->len);
		}
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
		if (transfer->delay_usecs)
			udelay(transfer->delay_usecs);
#endif
	}
	//spin_unlock(&auge_spi->lock);
	transfer_state = 0;
	msg->status = ret;

	spi_finalize_current_message(master);

	return ret;
}

#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 19, 0)

static bool auge_qspi_supports_op(struct spi_mem *mem, const struct spi_mem_op *op)
{
	if ((op->cmd.buswidth > 1) || (op->addr.nbytes && op->addr.buswidth > 1) ||
	    (op->dummy.nbytes && op->dummy.buswidth > 1) || (op->dummy.nbytes > 8)) {
		return false;
	}
	if (op->data.dir == SPI_MEM_DATA_OUT) {
		if ((op->data.buswidth == 2) || ((op->data.buswidth == 4) && ((mem->spi->mode & SPI_TX_QUAD) == 0))) {
			return false;
		}
	}

	if (op->data.dir == SPI_MEM_DATA_IN) {
		if (((op->data.buswidth == 2) && ((mem->spi->mode & SPI_RX_DUAL) == 0)) ||
		    ((op->data.buswidth == 4) && ((mem->spi->mode & SPI_RX_QUAD) == 0))) {
			return false;
		}
	}

	return true;
}

static int auge_qspi_exec_op(struct spi_mem *mem, const struct spi_mem_op *op)
{
	struct auge_spi_s *auge_spi = spi_controller_get_devdata(mem->spi->controller);
	struct chip_data *chip = spi_get_ctldata(mem->spi);
	uint32_t tmp;
	uint32_t ret;
	uint32_t cmd_l;

	/* TODO: Use mutex instead of spinlock because the following operations
	 * involve sleeping while waiting for TEE and Linux communication.
	 */
	spin_lock(&auge_spi->lock);

	transfer_state = 1;
	if (op->data.nbytes >= 16) {
		chip->dma_mode = 1;
	} else {
		chip->dma_mode = 0;
	}

	switch (op->data.buswidth) {
	case 1:
		chip->frame_format = AGTX_QSPI_FRF__SSPI;
		tmp = op->data.nbytes;
		break;
	case 2:
		chip->frame_format = AGTX_QSPI_FRF__DSPI;
#if defined(CONFIG_OSAKA)
		tmp = op->data.nbytes;
#else
		tmp = op->data.nbytes >> 1;
#endif /* CONFIG_OSAKA */
		break;
	case 4:
		chip->frame_format = AGTX_QSPI_FRF__QSPI;
#if defined(CONFIG_OSAKA)
		tmp = op->data.nbytes;
#else
		tmp = op->data.nbytes >> 2;
#endif /* CONFIG_OSAKA */
		break;
	default:
		chip->frame_format = AGTX_QSPI_FRF__SSPI;
		tmp = 0;
	}

	if (op->data.dir == SPI_MEM_DATA_IN) {
		chip->tmode = 0;
		chip->ndf = tmp;
	} else {
		chip->tmode = 1;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		chip->ndf = tmp;
#else
		chip->ndfw = tmp;
#endif
	}

	chip->data_frame_size = AGTX_QSPI_DFS__32_BIT;

	cmd_l = (op->cmd.nbytes == 2) ? QSPI_INST_L__16_BIT : QSPI_INST_L__8_BIT;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	tmp = (op->dummy.nbytes > 0) ? (op->dummy.nbytes << 3) : 0;
	/* In QSPIv4, wait_2_l is equivalent to wait_l, and wait_1_l is implicitly set to zero */
	chip->inst_set = (cmd_l << AGTX_QSPI_INST_L_OFFSET) | ((op->addr.nbytes * 2) << AGTX_QSPI_ADDR_L_OFFSET) |
	                 (tmp << AGTX_QSPI_WAIT_L_OFFSET);
#else /* Kyoto */
	tmp = (op->dummy.nbytes > 0) ? ((op->dummy.nbytes << 3) - 1) : 0;
	chip->inst_set = (cmd_l << AGTX_QSPI_INST_L_OFFSET) | ((op->addr.nbytes * 2) << AGTX_QSPI_ADDR_L_OFFSET) |
	                 (tmp << AGTX_QSPI_WAIT_L_OFFSET);
#endif /* defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) */

	setup_ssi_controller(auge_spi, chip);

	auge_writer_fifo(auge_spi, &op->cmd.opcode, op->cmd.nbytes);

	auge_writer_fifo(auge_spi, &op->addr.val, op->addr.nbytes);

	if (op->data.dir == SPI_MEM_DATA_IN) {
		ret = transfer_read(auge_spi, chip, op->data.buf.in, op->data.nbytes);
	} else {
		ret = transfer_write(auge_spi, chip, op->data.buf.out, op->data.nbytes);
	}

	transfer_state = 0;
	spin_unlock(&auge_spi->lock);
	return ret;
}

static const char *auge_qspi_get_name(struct spi_mem *spimem)
{
	printk("auge_qspi_get_name\n");
#ifdef CONFIG_MTD_SPI_NOR
	return "nor_flash";
#else
	return "nand_flash";
#endif
}

static int auge_adjust_op_size(struct spi_mem *mem, struct spi_mem_op *op)
{
	if (op->data.dir == SPI_MEM_DATA_IN) {
		if (op->data.nbytes > RX_BUFFER_SIZE) {
			op->data.nbytes = RX_BUFFER_SIZE;
		}
	} else {
		if (op->data.nbytes > TX_BUFFER_SIZE) {
			op->data.nbytes = TX_BUFFER_SIZE;
		}
	}
	return 0;
}

static const struct spi_controller_mem_ops auge_qspi_mem_ops = { .supports_op = auge_qspi_supports_op,
	                                                         .exec_op = auge_qspi_exec_op,
	                                                         .get_name = auge_qspi_get_name,
	                                                         .adjust_op_size = auge_adjust_op_size };
#endif

int auge_spi_add_host(struct device *dev, struct auge_spi_s *auge_spi)
{
	struct spi_master *master;
	int ret;

	BUG_ON(auge_spi == NULL);

	/* Basic HW init */
	spi_hw_init(dev, auge_spi);

	/* For poll mode just disable all interrupts */
	//spi_mask_intr(auge_spi, 0xff);

	master = spi_alloc_master(dev, 0);
	if (!master)
		return -ENOMEM;

	auge_spi->master = master;

	/* the clock configuration is done in SPL phase, by calling the interface from cpvs
	auge_spi->max_freq = QSPI_REF_CLK_187500KHZ;
	auge_spi->freq = QSPI_IF_CLK_46875KHZ;
	auge_spi->clk_div = auge_spi->max_freq / auge_spi->freq;
	*/
	snprintf(auge_spi->name, sizeof(auge_spi->name), "auge_spi%d", auge_spi->bus_num);

#if (IS_POLL_MODE == 0)
	ret = request_irq(auge_spi->irq, auge_spi_irq, IRQF_SHARED, auge_spi->name, master);
	if (ret < 0) {
		dev_err(dev, "can not get IRQ\n");
		goto err_free_master;
	}
#endif
	master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_TX_QUAD | SPI_RX_QUAD | SPI_RX_DUAL;
	master->bits_per_word_mask = SPI_BPW_MASK(8) | SPI_BPW_MASK(16) | SPI_BPW_MASK(32);
	master->bus_num = auge_spi->bus_num;
	master->num_chipselect = 1;
	master->setup = auge_spi_setup;
	master->cleanup = auge_spi_cleanup;
	master->transfer_one_message = augespi_transfer_one_message;
	master->max_speed_hz = auge_spi->max_freq;
	master->dev.of_node = dev->of_node;

#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 19, 0)
	master->mem_ops = &auge_qspi_mem_ops;
#endif

	spi_master_set_devdata(master, auge_spi);
	ret = devm_spi_register_master(dev, master);
	if (ret) {
		dev_err(&master->dev, "problem registering spi master\n");
		goto err_free_irq;
	}

	return 0;

err_free_irq:
	spi_enable_chip(auge_spi, 0);
#if (IS_POLL_MODE == 0)
	free_irq(auge_spi->irq, master);
#endif
err_free_master:
	spi_master_put(master);
	return ret;
}

void auge_spi_remove_host(struct auge_spi_s *auge_spi)
{
	spi_shutdown_chip(auge_spi);
	free_irq(auge_spi->irq, auge_spi->master);
}

static int auge_spi_probe(struct platform_device *pdev)
{
	struct auge_spi_s *auge_spi;
	struct resource *mem;
	int ret;

	auge_spi = devm_kzalloc(&pdev->dev, sizeof(struct auge_spi_s), GFP_KERNEL);
	if (!auge_spi)
		return -ENOMEM;
	g_auge_spi = auge_spi;

	auge_spi->dev = &pdev->dev;

	/* Get basic io resource and map it */
	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!mem) {
		dev_err(&pdev->dev, "no mem resource?\n");
		return -EINVAL;
	}

	auge_spi->regs_qspi = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(auge_spi->regs_qspi)) {
		dev_err(&pdev->dev, "QSPI region map failed\n");
		return PTR_ERR(auge_spi->regs_qspi);
	}

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	if (!mem) {
		dev_err(&pdev->dev, "no mem resource?\n");
		return -EINVAL;
	}
	auge_spi->regs_qspir = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(auge_spi->regs_qspir)) {
		dev_err(&pdev->dev, "QSPIR region map failed\n");
		return PTR_ERR(auge_spi->regs_qspir);
	}

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 2);
	if (!mem) {
		dev_err(&pdev->dev, "no mem resource?\n");
		return -EINVAL;
	}
	auge_spi->regs_qspiw = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(auge_spi->regs_qspiw)) {
		dev_err(&pdev->dev, "QSPIR region map failed\n");
		return PTR_ERR(auge_spi->regs_qspiw);
	}
#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
	mem = platform_get_resource(pdev, IORESOURCE_MEM, 3);
	if (!mem) {
		dev_err(&pdev->dev, "no mem resource?\n");
		return -EINVAL;
	}
	auge_spi->regs_darb = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(auge_spi->regs_darb)) {
		dev_err(&pdev->dev, "QSPIR_DARB region map failed\n");
		return PTR_ERR(auge_spi->regs_darb);
	}

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 4);
	if (!mem) {
		dev_err(&pdev->dev, "no mem resource?\n");
		return -EINVAL;
	}
	auge_spi->regs_pc_syscfg_dbg_mon = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(auge_spi->regs_pc_syscfg_dbg_mon)) {
		dev_err(&pdev->dev, "regs_pc_syscfg_dbg_mon region map failed\n");
		return PTR_ERR(auge_spi->regs_pc_syscfg_dbg_mon);
	}
#endif

#if (IS_POLL_MODE == 0)
	auge_spi->irq = platform_get_irq(pdev, 0);
	if (auge_spi->irq < 0) {
		dev_err(&pdev->dev, "no irq resource?\n");
		return auge_spi->irq; /* -ENXIO */
	}
#endif

	auge_spi->bus_num = pdev->id;

	spin_lock_init(&auge_spi->lock);
	init_completion(&auge_spi->xfer_completion);

	// IOSEL: QSPI
	//__raw_writel(0x00000001, 0x80001598);
	//__raw_writel(0x00000001, 0x8000159C);
	//__raw_writel(0x00000001, 0x800015A0);
	//__raw_writel(0x00000001, 0x800015A4);
	//__raw_writel(0x00000001, 0x800015A8);
	//__raw_writel(0x00000001, 0x800015AC);
	// QSPI_D2, QSPI_D3: ST enable, pull-up enable
	//__raw_writel(0x00080001, 0x8000145C);
	//__raw_writel(0x00080001, 0x80001460);

	ret = auge_spi_add_host(&pdev->dev, auge_spi);
	if (ret)
		goto out;


#if (IS_POLL_MODE == 1)
	/* For poll mode just disable all interrupts */
	spi_mask_intr(auge_spi, ~0);
	pr_info("auge_spi_probe irq = %d\n", auge_spi->irq);
#endif
	platform_set_drvdata(pdev, g_auge_spi);

	return 0;

out:
	return ret;
}

int auge_qspi_get_irq_status(struct spi_master *master)
{
	struct auge_spi_s *auge_spi = spi_master_get_devdata(master);

	u32 irq_status = auge_readl(auge_spi, AGTX_SPI_WORD3) & 0x5555;
	pr_warn("IRQ status:\nQSPI 03:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x10);
	pr_warn("QSPI 04:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x14);
	pr_warn("QSPI 05:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x18);
	pr_warn("QSPI 06:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x1c);
	pr_warn("QSPI 07:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x20);
	pr_warn("QSPI 08:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x24);
	pr_warn("QSPI 09:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x28);
	pr_warn("QSPI 10:0x%08x\n", irq_status);
	/*	irq_status = auge_readl(auge_spi, 0x2c);
	pr_warn("QSPI 11:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x30);
	pr_warn("QSPI 12:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, 0x34);
	pr_warn("QSPI 13:0x%08x\n", irq_status);*/
	irq_status = auge_readl(auge_spi, 0x38);
	pr_warn("QSPI 14:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, AGTX_SPI_WORD18);
	pr_warn("QSPI 18:0x%08x\n", irq_status);
	irq_status = auge_readl(auge_spi, AGTX_SPI_WORD19);
	pr_warn("QSPI 19:0x%08x\n", irq_status);

	irq_status = readl_relaxed(auge_spi->regs_qspir + 8);
	pr_warn("QSPIR 02:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x10);
	pr_warn("QSPIR 04:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x18);
	pr_warn("QSPIR 06:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x1c);
	pr_warn("QSPIR 07:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x20);
	pr_warn("QSPIR 08:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x24);
	pr_warn("QSPIR 09:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x28);
	pr_warn("QSPIR 10:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x2c);
	pr_warn("QSPIR 11:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x30);
	pr_warn("QSPIR 12:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x34);
	printk("QSPIR 13:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x38);
	pr_warn("QSPIR 14:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0xA0);
	pr_warn("QSPIR 40:0x%08x\n", irq_status);

	irq_status = readl_relaxed(auge_spi->regs_qspiw + 8);
	pr_warn("QSPIW 02:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspiw + 0x10);
	pr_warn("QSPIW 04:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspiw + 0x2c);
	pr_warn("QSPIW 11:0x%08x\n", irq_status);
	irq_status = readl_relaxed(auge_spi->regs_qspiw + 0xA0);
	pr_warn("QSPIW 40:0x%08x\n", irq_status);

#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
	irq_status = readl_relaxed(auge_spi->regs_qspir + 0x10) & 0xF0FFFFFF;
	irq_status |= 1 << 24;
	writel_relaxed(irq_status, auge_spi->regs_qspir + 0x10);

	irq_status = readl_relaxed(auge_spi->regs_pc_syscfg_dbg_mon) & ~0x1f;
	irq_status |= 7;
	writel_relaxed(irq_status, auge_spi->regs_pc_syscfg_dbg_mon);

	auge_writel(auge_spi, 0x168, 1);
	irq_status = readl_relaxed(auge_spi->regs_pc_syscfg_dbg_mon + 4);
	pr_warn("QSPI.QSPI.debug_mon_sel = QSPI Engine, PC.SYSCFG.debug_mon = 0x%08x\n", irq_status);

	auge_writel(auge_spi, 0x168, 2);
	irq_status = readl_relaxed(auge_spi->regs_pc_syscfg_dbg_mon + 4);
	pr_warn("QSPI.QSPI.debug_mon_sel = DRAM Read Agent, PC.SYSCFG.debug_mon = 0x%08x\n", irq_status);
#endif
	return irq_status;
}

static int auge_spi_remove(struct platform_device *pdev)
{
	struct auge_spi_s *auge_spi = platform_get_drvdata(pdev);

	auge_spi_remove_host(auge_spi);

	return 0;
}

static const struct of_device_id auge_spi_of_match[] = {
	{ .compatible = "augentix,qspi", },
	{ /* end of table */}
};
MODULE_DEVICE_TABLE(of, auge_spi_of_match);

static struct platform_driver auge_spi_driver = {
	.probe		= auge_spi_probe,
	.remove		= auge_spi_remove,
	.driver		= {
		.name	= DRIVER_NAME,
		.of_match_table = auge_spi_of_match,
	},
};
module_platform_driver(auge_spi_driver);

MODULE_AUTHOR("Nick Lin <nick.lin@augentix.com>");
MODULE_DESCRIPTION("Auge SPI driver");
MODULE_LICENSE("GPL v2");
