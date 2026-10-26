// SPDX-License-Identifier: GPL-2.0+
#include <clk.h>
#include <cpu_func.h>
#include <dm.h>
#include <spi.h>
#include <spi-mem.h>
#include <asm/cache.h>
#include <asm/io.h>
#include <time.h>
#include <linux/string.h>
#include <linux/bitops.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/iopoll.h>
#include <linux/kernel.h>
#include <dm/device_compat.h>

#include "augentix_qspi.h"

#define RX_BUFFER_SIZE 512
#define TX_BUFFER_SIZE 256

#define QSPI_POLL_TIMEOUT_MS 1000

/* The DMA engine takes the buffer address in 8-byte units and the cache
 * maintenance below works on whole lines, so both constraints apply.
 */
#define QSPI_DMA_ALIGN (ARCH_DMA_MINALIGN > 8 ? ARCH_DMA_MINALIGN : 8)

/* Bounce for callers whose buffer does not meet QSPI_DMA_ALIGN. Sized to the
 * larger adjust_op_size() cap, so one op always fits.
 */
static u8 auge_dma_bounce[RX_BUFFER_SIZE] __aligned(QSPI_DMA_ALIGN);

static bool auge_dma_capable(const void *buf)
{
	return !((uintptr_t)buf & (QSPI_DMA_ALIGN - 1));
}

static void spi_hw_init(struct auge_spi_s *auge_spi)
{
	u32 val __attribute__((unused));

	spi_reset_chip(auge_spi);

#if !defined(CONFIG_AUGENTIX_SOC_SAPPORO) && !defined(CONFIG_AUGENTIX_SOC_OSAKA)
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

static void auge_writer_fifo(struct auge_spi_s *auge_spi, const void *buf, int write_len)
{
	u32 txw;

	while (write_len > 0) {
		txw = 0;
		memcpy(&txw, buf, write_len < 4 ? write_len : 4);
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

static int wait_done(struct auge_spi_s *auge_spi)
{
	u32 status;
	u32 expect;
	ulong start;

	auge_writel(auge_spi, AGTX_SPI_WORD0, 1); /* Action start */

	/* Wait for TX FIFO empty and DONE flag raised */
	expect = (1 << SPI_STATUS_DONE_OFFSET);

	start = get_timer(0);
	do {
		status = auge_readl(auge_spi, WORD_IRQ_STATUS);
		if (status & (1 << SPI_STATUS_ERROR_OFFSET)) {
			auge_writel(auge_spi, WORD_IRQ_CLEAR, ~0);
			return -EIO;
		}
		if (status & expect)
			break;
		if (get_timer(start) > QSPI_POLL_TIMEOUT_MS) {
			auge_writel(auge_spi, WORD_IRQ_CLEAR, ~0);
			return -ETIMEDOUT;
		}
	} while (1);
	auge_writel(auge_spi, WORD_IRQ_CLEAR, ~0);

	return 0;
}

static int transfer_write(struct auge_spi_s *auge_spi, struct chip_data *chip, const void *buf,
			  uint32_t len)
{
	void __iomem *reg = auge_spi->regs_qspir;
	const void *src = buf;
	uintptr_t addr;
#if !defined(CONFIG_AUGENTIX_SOC_SAPPORO) && !defined(CONFIG_AUGENTIX_SOC_OSAKA)
	u32 val;
#endif

	if (chip->dma_mode == 0) {
		auge_writer_fifo(auge_spi, buf, len);
		return wait_done(auge_spi);
	}

	if (!auge_dma_capable(src)) {
		memcpy(auge_dma_bounce, buf, len);
		src = auge_dma_bounce;
	}

	addr = (uintptr_t)src;
	flush_dcache_range(addr, ALIGN(addr + len, ARCH_DMA_MINALIGN));

	writel(0x101, reg + LR032_01);
#if defined(CONFIG_AUGENTIX_SOC_SAPPORO) || defined(CONFIG_AUGENTIX_SOC_OSAKA)
	writel((len + 3) >> 2, reg + LR032_11);
	writel((len + 7) >> 3, reg + LR032_12);
#else
	writel(len >> 2, reg + LR032_11);
	writel((len + 7) >> 3, reg + LR032_12);
#endif
	writel(virt_to_phys((void *)addr) >> 3, reg + LR032_40);

#if !defined(CONFIG_AUGENTIX_SOC_SAPPORO) && !defined(CONFIG_AUGENTIX_SOC_OSAKA)
	auge_writel(auge_spi, 0x168, 2);

	val = readl(auge_spi->regs_pc_syscfg_dbg_mon) & ~0x1f;
	val |= 7;
	writel(val, auge_spi->regs_pc_syscfg_dbg_mon);

	val = readl(auge_spi->regs_qspir + 0x10) & ~0x1000000;
	val |= 1 << 24;
	writel(val, auge_spi->regs_qspir + 0x10);
#endif

	writel(1, reg + LR032_00);

#if !defined(CONFIG_AUGENTIX_SOC_SAPPORO) && !defined(CONFIG_AUGENTIX_SOC_OSAKA)
	while ((readl(auge_spi->regs_pc_syscfg_dbg_mon + 4) & 0x3f) != (((len + 7) >> 3) - 1))
		;
#endif

	return wait_done(auge_spi);
}

static int transfer_read(struct auge_spi_s *auge_spi, struct chip_data *chip, void *buf,
			 uint32_t len)
{
	void __iomem *reg = auge_spi->regs_qspiw;
	void *dst = buf;
	uintptr_t addr, end;
	int ret;

	if (chip->dma_mode == 0) {
		ret = wait_done(auge_spi);
		if (ret)
			return ret;
		auge_read_fifo(auge_spi, buf, len);

		return 0;
	}

	/* A 16-byte DMA burst writes past a tail shorter than 16 bytes. */
	if (!auge_dma_capable(dst) || (len & 0xf))
		dst = auge_dma_bounce;

	addr = (uintptr_t)dst;
	end = ALIGN(addr + len, ARCH_DMA_MINALIGN);
	invalidate_dcache_range(addr, end);

	writel(0x101, reg + LR032_01);
#if defined(CONFIG_AUGENTIX_SOC_SAPPORO) || defined(CONFIG_AUGENTIX_SOC_OSAKA)
	writel((len + 3) >> 2, reg + LR032_11);
#else
	writel(len >> 2, reg + LR032_11);
#endif
	writel(virt_to_phys((void *)addr) >> 3, reg + LR032_40);
	writel(1, reg + LR032_00);

	ret = wait_done(auge_spi);
	invalidate_dcache_range(addr, end);

	if (dst != buf)
		memcpy(buf, auge_dma_bounce, len);

	return ret;
}

static void setup_ssi_controller(struct auge_spi_s *auge_spi, struct chip_data *chip)
{
#if defined(CONFIG_AUGENTIX_SOC_OSAKA)
	u32 csr08 = 0;
	u32 csr09 = 0;
	u32 csr11 = 0;

	spi_umask_intr(auge_spi, 1 << SPI_STATUS_DONE_OFFSET);

	if (chip->dma_mode == 1)
		csr08 |= (QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);
	else
		csr08 &= ~(QSPI_DMA_M__EN << SPI_DMA_MODE_EN_OFFSET);

	/* In QSPIv4, data_format is equivalent to frame_format */
	csr08 |= (chip->tmode << SPI_TRANSFER_MODE_OFFSET) | (0 << SPI_INST_FORMAT_OFFSET) |
	         (0 << SPI_ADDR_FORMAT_OFFSET) | (chip->frame_format << SPI_FRAME_FORMAT_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD8, csr08);

	csr09 = (1 << SPI_INST_MSB_FRIST_OFFSET) | (1 << SPI_ADDR_MSB_FRIST_OFFSET) |
	        (0 << SPI_WR_MSB_FRIST_OFFSET) | (0 << SPI_RD_MSB_FRIST_OFFSET) |
	        (0 << SPI_TX_NIB_SWAP_EN_OFFSET) | (0 << SPI_RX_NIB_SWAP_EN_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD9, csr09);

	auge_writel(auge_spi, AGTX_SPI_WORD10, chip->inst_set);

	csr11 = (chip->ndf << SPI_NDF_OFFSET);
	auge_writel(auge_spi, AGTX_SPI_WORD11, csr11);
#elif defined(CONFIG_AUGENTIX_SOC_SAPPORO)
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
	qw08 = (chip->tmode << SPI_TRANSFER_MODE_OFFSET) |
	       (chip->frame_format << SPI_FRAME_FORMAT_OFFSET) |
	       (chip->data_frame_size << SPI_DATA_FRAME_SIZE_OFFSET) | qw08_len | (chip->inst_set);
	auge_writel(auge_spi, AGTX_SPI_WORD8, qw08);

	/* QSPI09 - Number of Data Frames */
	if (chip->tmode == QSPI_TMOD__READ) {
		qw09 = (chip->ndf << SPI_NDF_OFFSET);
	} else {
		qw09 = (chip->ndfw << SPI_NDFW_OFFSET);
	}
	auge_writel(auge_spi, AGTX_SPI_WORD9, qw09);
#endif
}

static bool auge_qspi_supports_op(struct spi_slave *slave, const struct spi_mem_op *op)
{
	if ((op->cmd.buswidth > 1) || (op->addr.nbytes && op->addr.buswidth > 1) ||
	    (op->dummy.nbytes && op->dummy.buswidth > 1) || (op->dummy.nbytes > 8)) {
		return false;
	}
	if (op->data.dir == SPI_MEM_DATA_OUT) {
		if ((op->data.buswidth == 2) ||
		    ((op->data.buswidth == 4) && ((slave->mode & SPI_TX_QUAD) == 0))) {
			return false;
		}
	}

	if (op->data.dir == SPI_MEM_DATA_IN) {
		if (((op->data.buswidth == 2) && ((slave->mode & SPI_RX_DUAL) == 0)) ||
		    ((op->data.buswidth == 4) && ((slave->mode & SPI_RX_QUAD) == 0))) {
			return false;
		}
	}

	return true;
}

static int auge_qspi_exec_op(struct spi_slave *slave, const struct spi_mem_op *op)
{
	struct auge_spi_s *auge_spi = dev_get_priv(slave->dev->parent);
	struct chip_data chip_data = { 0 };
	struct chip_data *chip = &chip_data;
	uint32_t tmp;
	uint32_t cmd_l;

	chip->poll_mode = 1;
	chip->dma_mode = (op->data.nbytes >= 16) ? 1 : 0;

	switch (op->data.buswidth) {
	case 1:
		chip->frame_format = QSPI_FRF__SSPI;
		tmp = op->data.nbytes;
		break;
	case 2:
		chip->frame_format = QSPI_FRF__DSPI;
#if defined(CONFIG_AUGENTIX_SOC_OSAKA)
		tmp = op->data.nbytes;
#else
		tmp = op->data.nbytes >> 1;
#endif /* CONFIG_AUGENTIX_SOC_OSAKA */
		break;
	case 4:
		chip->frame_format = QSPI_FRF__QSPI;
#if defined(CONFIG_AUGENTIX_SOC_OSAKA)
		tmp = op->data.nbytes;
#else
		tmp = op->data.nbytes >> 2;
#endif /* CONFIG_AUGENTIX_SOC_OSAKA */
		break;
	default:
		chip->frame_format = QSPI_FRF__SSPI;
		tmp = 0;
	}

	if (op->data.dir == SPI_MEM_DATA_IN) {
		chip->tmode = 0;
		chip->ndf = tmp;
	} else {
		chip->tmode = 1;
#if defined(CONFIG_AUGENTIX_SOC_SAPPORO) || defined(CONFIG_AUGENTIX_SOC_OSAKA)
		chip->ndf = tmp;
#else
		chip->ndfw = tmp;
#endif
	}

	chip->data_frame_size = QSPI_DFS__32_BIT;

	cmd_l = (op->cmd.nbytes == 2) ? QSPI_INST_L__16_BIT : QSPI_INST_L__8_BIT;
#if defined(CONFIG_AUGENTIX_SOC_SAPPORO) || defined(CONFIG_AUGENTIX_SOC_OSAKA)
	tmp = (op->dummy.nbytes > 0) ? (op->dummy.nbytes << 3) : 0;
	/* In QSPIv4, wait_2_l is equivalent to wait_l, and wait_1_l is implicitly set to zero */
	chip->inst_set = (cmd_l << SPI_INST_L_OFFSET) |
	                 ((op->addr.nbytes * 2) << SPI_ADDR_L_OFFSET) |
	                 (tmp << SPI_WAIT_L_OFFSET);
#else /* Kyoto */
	tmp = (op->dummy.nbytes > 0) ? ((op->dummy.nbytes << 3) - 1) : 0;
	chip->inst_set = (cmd_l << SPI_INST_L_OFFSET) |
	                 ((op->addr.nbytes * 2) << SPI_ADDR_L_OFFSET) |
	                 (tmp << SPI_WAIT_L_OFFSET);
#endif

	setup_ssi_controller(auge_spi, chip);

	auge_writer_fifo(auge_spi, &op->cmd.opcode, min_t(int, op->cmd.nbytes, sizeof(op->cmd.opcode)));

	auge_writer_fifo(auge_spi, &op->addr.val, op->addr.nbytes);

	if (op->data.dir == SPI_MEM_DATA_IN)
		return transfer_read(auge_spi, chip, op->data.buf.in, op->data.nbytes);

	return transfer_write(auge_spi, chip, op->data.buf.out, op->data.nbytes);
}

static int auge_adjust_op_size(struct spi_slave *slave, struct spi_mem_op *op)
{
	if (op->data.dir == SPI_MEM_DATA_IN) {
		if (op->data.nbytes > RX_BUFFER_SIZE)
			op->data.nbytes = RX_BUFFER_SIZE;
	} else {
		if (op->data.nbytes > TX_BUFFER_SIZE)
			op->data.nbytes = TX_BUFFER_SIZE;
	}

	return 0;
}

/* The spi-mem ops are ported from linux_6.1.102 (GPL-2.0+).
 * Polled, with the Linux driver's 16-byte PIO and DMA split.
 */
static const struct spi_controller_mem_ops auge_qspi_mem_ops = {
	.adjust_op_size = auge_adjust_op_size,
	.supports_op = auge_qspi_supports_op,
	.exec_op = auge_qspi_exec_op,
};

static int auge_qspi_set_speed(struct udevice *bus, uint speed)
{
	struct auge_spi_s *auge_spi = dev_get_priv(bus);

	auge_spi->freq = speed;

	return 0;
}

static int auge_qspi_set_mode(struct udevice *bus, uint mode)
{
	return 0;
}

static int auge_qspi_probe(struct udevice *bus)
{
	struct auge_spi_s *auge_spi = dev_get_priv(bus);

	auge_spi->regs_qspi = dev_remap_addr_index(bus, 0);
	if (!auge_spi->regs_qspi)
		return -EINVAL;

	auge_spi->regs_qspir = dev_remap_addr_index(bus, 1);
	if (!auge_spi->regs_qspir)
		return -EINVAL;

	auge_spi->regs_qspiw = dev_remap_addr_index(bus, 2);
	if (!auge_spi->regs_qspiw)
		return -EINVAL;

#if !defined(CONFIG_AUGENTIX_SOC_SAPPORO) && !defined(CONFIG_AUGENTIX_SOC_OSAKA)
	auge_spi->regs_darb = dev_remap_addr_index(bus, 3);
	if (!auge_spi->regs_darb)
		return -EINVAL;

	auge_spi->regs_pc_syscfg_dbg_mon = dev_remap_addr_index(bus, 4);
	if (!auge_spi->regs_pc_syscfg_dbg_mon)
		return -EINVAL;
#endif

#if defined(CONFIG_AUGENTIX_SOC_OSAKA)
	writel(0, auge_spi->regs_qspi + AGTX_SPI_WORD18);
#endif

	spi_hw_init(auge_spi);

	/* spi_reset_chip() leaves DONE unmasked; nothing services it here. */
	spi_mask_intr(auge_spi, ~0U);

	return 0;
}

static const struct dm_spi_ops auge_qspi_ops = {
	.set_speed = auge_qspi_set_speed,
	.set_mode = auge_qspi_set_mode,
	.mem_ops = &auge_qspi_mem_ops,
};

static const struct udevice_id auge_qspi_ids[] = {
	{ .compatible = "augentix,qspi" },
	{ }
};

U_BOOT_DRIVER(auge_qspi) = {
	.name = "auge_qspi",
	.id = UCLASS_SPI,
	.of_match = auge_qspi_ids,
	.ops = &auge_qspi_ops,
	.priv_auto = sizeof(struct auge_spi_s),
	.probe = auge_qspi_probe,
};
