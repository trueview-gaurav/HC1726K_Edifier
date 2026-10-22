/*
 * MTD SPI driver for ST M25Pxx (and similar) serial flash chips
 *
 * Author: Mike Lavender, mike@steroidmicros.com
 *
 * Copyright (c) 2005, Intec Automation Inc.
 *
 * Some parts are based on lart.c by Abraham Van Der Merwe
 *
 * Cleaned up and generalized based on mtd_dataflash.c
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include <linux/err.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/version.h>
#include <linux/delay.h>

#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>

#include <linux/spi/spi.h>
#include <linux/spi/flash.h>
#include <linux/mtd/spi-nor.h>
#include <linux/spi/augentix_serial_flash.h>
#include <linux/spi/qspi-augentix.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 0, 0)
#define addr_width addr_nbytes
#endif

#define IS_DMA 1

#if (IS_DMA == 0)
#define RX_BUFFER_SIZE 64
#define TX_BUFFER_SIZE 52
#else
#define RX_BUFFER_SIZE 512
#define TX_BUFFER_SIZE 256
#endif

#define	MAX_CMD_SIZE		6

struct m25p {
	struct spi_device	*spi;
	struct spi_nor		spi_nor;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0)
	struct mtd_info		mtd;
#else
	struct mtd_info *mtd;
#endif
	struct mutex transfer_lock;
	u8			command[MAX_CMD_SIZE];
	u32			lcmd[MAX_CMD_SIZE];
	u8	addr[4];
	u32	laddr[0];
};

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 5, 0)
static int m25p80_read_reg(struct spi_nor *nor, u8 code, u8 *val, size_t len)
#else
static int m25p80_read_reg(struct spi_nor *nor, u8 code, u8 *val, int len)
#endif
{
	struct m25p *flash = nor->priv;
	struct spi_device *spi = flash->spi;
	int ret;

	struct chip_data *chip = (struct chip_data *)spi->controller_state;
	/* RDSR, RDCR, RDFSR, RDID, addr_l & wait_l = 0 */
	u32 addr_l = 0;
	u32 wait_l = 0;
	struct spi_transfer t[2];
	struct spi_message m;

	mutex_lock(&flash->transfer_lock);

	/* AGTX QSPI - CSR setting */
	chip->dma_mode = 0;
	chip->frame_format = AGTX_QSPI_FRF__SSPI;
	chip->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	chip->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                 (wait_l << AGTX_QSPI_WAIT_L_OFFSET);
	// Read
	chip->tmode = AGTX_SPI_TMOD_RO;
	chip->ndf = len;

	spi_message_init(&m);
	memset(t, 0, (sizeof t));

	//CMD
	t[0].tx_nbits = SPI_NBITS_SINGLE;
	t[0].bits_per_word = 8;
	t[0].len = 1;
	t[0].tx_buf = &code;
	t[0].cs_change = 1;
	spi_message_add_tail(&t[0], &m);

	//rx
	t[1].rx_nbits = SPI_NBITS_SINGLE;
	t[1].bits_per_word = 8;
	t[1].len = len;
	t[1].rx_buf = val;
	t[1].cs_change = 0;
	spi_message_add_tail(&t[1], &m);

	ret = spi_sync(spi, &m);
	mutex_unlock(&flash->transfer_lock);

	return ret;
}

static void m25p_off2addr(struct spi_nor *nor, unsigned int off, u8 *addr)
{
	addr[0] = (u8)((off & 0x000000ff) >> 0);
	addr[1] = (u8)((off & 0x0000ff00) >> 8);
	addr[2] = (u8)((off & 0x00ff0000) >> 16);
	addr[3] = (u8)((off & 0xff000000) >> 24);
}

static int m25p_cmdsz(struct spi_nor *nor)
{
	return 1 + nor->addr_width;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 5, 0)
static int m25p80_write_reg(struct spi_nor *nor, u8 opcode, const u8 *buf, size_t len)
#else
static int m25p80_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len, int wr_en)
#endif
{
	struct m25p *flash = nor->priv;
	struct spi_device *spi = flash->spi;
	int ret;

	struct chip_data* chip = ( struct chip_data*)spi->controller_state;
	/* WRSR, WREN, WRDI, EN4B, EX4B, BRWR, CHIP_ERASE, addr_l & wait_l = 0 */
	u32 addr_l = 0;
	u32 wait_l = 0;
	struct spi_transfer t[2];
	struct spi_message m;

	mutex_lock(&flash->transfer_lock);

	/* AGTX QSPI - CSR setting */
	chip->dma_mode = 0;
	chip->frame_format = AGTX_QSPI_FRF__SSPI;
	chip->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	chip->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                 (wait_l << AGTX_QSPI_WAIT_L_OFFSET);

	// Write
	chip->tmode = AGTX_SPI_TMOD_TO;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	chip->ndf = len;
#else
	chip->ndfw = len;
#endif

	spi_message_init(&m);
	memset(t, 0, (sizeof t));

	//CMD
	t[0].tx_nbits = SPI_NBITS_SINGLE;
	t[0].bits_per_word = 8;
	t[0].len = 1;
	t[0].tx_buf = &opcode;
	t[0].cs_change = len ? 1: 0;
	spi_message_add_tail(&t[0], &m);

	//tx
	if (len) {
		t[1].tx_nbits = SPI_NBITS_SINGLE;
		t[1].bits_per_word = 8;
		t[1].len = len;
		t[1].tx_buf = buf;
		t[1].cs_change = 0;
		spi_message_add_tail(&t[1], &m);
	}

	ret = spi_sync(spi, &m);
	mutex_unlock(&flash->transfer_lock);

	return ret;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
static void m25p80_write(struct spi_nor *nor, loff_t to, size_t len, size_t *retlen, const u_char *buf)
#else
static ssize_t m25p80_write(struct spi_nor *nor, loff_t to, size_t len, const u8 *buf)
#endif
{
	struct m25p *flash = nor->priv;
	struct spi_device *spi = flash->spi;
	struct spi_transfer t[3] = {};
	struct spi_message m;
	int cmd_sz = m25p_cmdsz(nor);
	u_char *k_buf = NULL;
	int max_tx_size;
	int len_padding = 0;

	struct chip_data* chip = ( struct chip_data*)spi->controller_state;
	/* wait_l = 0,
	 * BP, AAI_WP, PP, addr_l = 3;
	 * PP_4B, addr_l = 4;
	 * from spi_nor_scan() determined */
	u32 addr_l = 0;
	u32 wait_l = 0;
	u32 tx_bytes = 0;
	int trans_bytes = len;

	if (nor->program_opcode == SPINOR_OP_AAI_WP && nor->sst_write_second)
		cmd_sz = 1;
	flash->command[0] = nor->program_opcode;

	if (trans_bytes % 4 != 0) {
		len_padding = (4 - (trans_bytes % 4));
		trans_bytes += len_padding;
	}

#if (IS_DMA == 1)
	if (len > 8) {
		k_buf = devm_kzalloc(&spi->dev, TX_BUFFER_SIZE, GFP_KERNEL);
	}
#endif

	mutex_lock(&flash->transfer_lock);

	if (!k_buf) {
		chip->dma_mode = 0;
		max_tx_size = 52;
	} else {
		chip->dma_mode = 1;
		max_tx_size = TX_BUFFER_SIZE;
		memcpy(k_buf, buf, len);
	}

	while (trans_bytes > 0) {
		tx_bytes = (trans_bytes >= max_tx_size) ? max_tx_size : trans_bytes;
		spi_message_init(&m);
		memset(t, 0, (sizeof t));

		m25p_off2addr(nor, to, flash->addr);
		addr_l = (nor->addr_width << 1) & 0xFF;

		/* AGTX QSPI - CSR setting */

		if (flash->command[0] == 0x32 || flash->command[0] == 0x34) {
			chip->frame_format = AGTX_QSPI_FRF__QSPI;
		} else {
			chip->frame_format = AGTX_QSPI_FRF__SSPI;
		}
		chip->data_frame_size = AGTX_QSPI_DFS__32_BIT;
		chip->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) |
		                 (addr_l << AGTX_QSPI_ADDR_L_OFFSET) | (wait_l << AGTX_QSPI_WAIT_L_OFFSET);
		// Write
		chip->tmode = AGTX_SPI_TMOD_TO;
#if defined(CONFIG_OSAKA)
		chip->ndf = tx_bytes;
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
		chip->ndf = tx_bytes >> chip->frame_format;
#else
		chip->ndfw = tx_bytes >> chip->frame_format;
#endif /* CONFIG_OSAKA */

		//CMD
		t[0].tx_nbits = SPI_NBITS_SINGLE;
		t[0].bits_per_word = 8;
		t[0].len = 1;
		t[0].tx_buf = flash->command;
		t[0].cs_change = 1;
		spi_message_add_tail(&t[0], &m);

		//Addr
		t[1].tx_nbits = SPI_NBITS_SINGLE;
		t[1].bits_per_word = 32;
		t[1].len = 4;
		t[1].tx_buf = flash->addr;
		t[1].cs_change = 1;
		spi_message_add_tail(&t[1], &m);

		//tx
		t[2].tx_nbits = SPI_NBITS_SINGLE;
		t[2].bits_per_word = 32;
		t[2].len = tx_bytes;
		t[2].tx_buf = (chip->dma_mode) ? k_buf : buf;
		t[2].cs_change = 0;

		spi_message_add_tail(&t[2], &m);

		spi_sync(spi, &m);

		trans_bytes -= tx_bytes;
		to += tx_bytes;
		buf += tx_bytes;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
		*retlen += tx_bytes;
#endif
	}
	mutex_unlock(&flash->transfer_lock);
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
	*retlen -= len_padding;
#endif
	if (k_buf)
		devm_kfree(&spi->dev, k_buf);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 5, 0)
	return len;
#endif
}

/*
 * Read an address range from the nor chip.  The address range
 * may be any size provided it is within the physical boundaries.
 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
static int m25p80_read(struct spi_nor *nor, loff_t from, size_t len, size_t *retlen, u_char *buf)
#else
static ssize_t m25p80_read(struct spi_nor *nor, loff_t from, size_t len, u8 *buf)
#endif
{
	struct m25p *flash = nor->priv;
	struct spi_device *spi = flash->spi;
	struct spi_transfer t[4];
	struct spi_message m;
	int dummy = nor->read_dummy / 8;
	u_char *k_buf;

	struct chip_data* chip = ( struct chip_data*)spi->controller_state;
	/* wait_l = dummy, from spi_nor_read_dummy_cycles(),
	 * READ_1_1_4, READ_1_1_2, READ_FAST, READ, addr_l = 3;
	 * READ4_1_1_4, READ4_1_1_2, READ4_FAST, READ4, addr_l = 4;
	 * from spi_nor_scan() determined */
	u32 addr_l = 0;
	u32 wait_l = 0;
	u32 rx_bytes = 0;
	int trans_bytes = len;
	int align_4;
	__maybe_unused int ret;

	flash->command[0] = nor->read_opcode;

	k_buf = devm_kzalloc(&spi->dev, RX_BUFFER_SIZE + 16, GFP_KERNEL);
	if (!k_buf)
		return -ENOMEM;

	while (trans_bytes > 0) {
		rx_bytes = (trans_bytes >= RX_BUFFER_SIZE) ? RX_BUFFER_SIZE : trans_bytes;

		if (rx_bytes % 4) {
			align_4 = rx_bytes - (rx_bytes % 4) + 4;
		} else {
			align_4 = rx_bytes;
		}
#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 19, 0)
		/* Wait till previous write/erase is done. */
		ret = nor->wait_till_ready(nor);
		if (ret) {
			devm_kfree(&spi->dev, k_buf);
			return ret;
		}
#endif
		m25p_off2addr(nor, from, flash->addr);

		spi_message_init(&m);
		memset(t, 0, (sizeof t));

		addr_l = (nor->addr_width << 1) & 0xFF;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		wait_l = (dummy > 0) ? (dummy << 3) & 0xFF : 0;
#else
		wait_l = (dummy > 0) ? ((dummy << 3) - 1) & 0xFF : 0;
#endif /* Sapporo, Kamo, or Osaka */
		/* AGTX QSPI - CSR setting */

		mutex_lock(&flash->transfer_lock);

		chip->dma_mode = IS_DMA;

		if ((flash->command[0] == 0x6b) || (flash->command[0] == 0x6c)) {
			chip->frame_format = AGTX_QSPI_FRF__QSPI;
		} else if ((flash->command[0] == 0x3b) || (flash->command[0] == 0x3c)) {
			chip->frame_format = AGTX_QSPI_FRF__DSPI;
		} else {
			chip->frame_format = AGTX_QSPI_FRF__SSPI;
		}
		chip->data_frame_size = AGTX_QSPI_DFS__32_BIT;
		chip->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) |
		                 (addr_l << AGTX_QSPI_ADDR_L_OFFSET) | (wait_l << AGTX_QSPI_WAIT_L_OFFSET);
		// Read
		chip->tmode = AGTX_SPI_TMOD_RO;
#if defined(CONFIG_OSAKA)
		chip->ndf = align_4;
#else
		chip->ndf = align_4 >> chip->frame_format;
#endif /* CONFIG_OSAKA */
		//CMD
		t[0].tx_nbits = SPI_NBITS_SINGLE;
		t[0].bits_per_word = 8;
		t[0].len = 1;
		t[0].tx_buf = flash->command;
		t[0].cs_change = 1;
		spi_message_add_tail(&t[0], &m);

		//Addr
		t[1].tx_nbits = SPI_NBITS_SINGLE;
		t[1].bits_per_word = 32;
		t[1].len = 4;
		t[1].tx_buf = flash->addr;
		t[1].cs_change = 1;
		spi_message_add_tail(&t[1], &m);

		//rx
		t[3].rx_nbits = SPI_NBITS_SINGLE;
		t[3].bits_per_word = 32;
		t[3].len = align_4;
		t[3].rx_buf = k_buf;
		t[3].cs_change = 0;

		spi_message_add_tail(&t[3], &m);

		spi_sync(spi, &m);

		mutex_unlock(&flash->transfer_lock);

		memcpy(buf, k_buf, rx_bytes);

		trans_bytes -= rx_bytes;
		from += rx_bytes;
		buf += rx_bytes;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
		*retlen += rx_bytes;
#endif
	}

	devm_kfree(&spi->dev, k_buf);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 5, 0)
	return len;
#else
	return 0;
#endif
}

static int m25p80_erase(struct spi_nor *nor, loff_t offset)
{
	struct m25p *flash = nor->priv;
	struct spi_device *spi = flash->spi;
	struct spi_transfer t[2];
	struct spi_message m;

	struct chip_data* chip = ( struct chip_data*)spi->controller_state;
	u32 addr_l = 0;
	u32 wait_l = 0;
	__maybe_unused int ret;

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0)
	dev_dbg(nor->dev, "%dKiB at 0x%08x\n", flash->mtd.erasesize / 1024, (u32)offset);
#else
	dev_dbg(nor->dev, "%dKiB at 0x%08x\n", flash->mtd->erasesize / 1024, (u32)offset);
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 19, 0)
	/* Wait until finished previous write command. */
	ret = nor->wait_till_ready(nor);
	if (ret)
		return ret;

	/* Send write enable, then erase commands. */
	ret = nor->write_reg(nor, SPINOR_OP_WREN, NULL, 0, 0);
	if (ret)
		return ret;
#endif
	mutex_lock(&flash->transfer_lock);

	/* Set up command buffer. */
	flash->command[0] = nor->erase_opcode;
	m25p_off2addr(nor, offset, flash->addr);

	spi_message_init(&m);
	memset(t, 0, sizeof(t));

	/* All wait_l = 0; SE, BE_4K, BE_4K_PMC: addr_l = 3; SE_4B: addr_l = 4 */
	addr_l = (nor->addr_width << 1) & 0xFF;

	/* AGTX QSPI - CSR setting */
	chip->dma_mode = 0;
	chip->frame_format = AGTX_QSPI_FRF__SSPI;
	chip->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	chip->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                 (wait_l << AGTX_QSPI_WAIT_L_OFFSET);
	// Read
	chip->tmode = AGTX_SPI_TMOD_TO;
	chip->ndf = 0;

	//CMD
	t[0].tx_nbits = SPI_NBITS_SINGLE;
	t[0].bits_per_word = 8;
	t[0].len = 1;
	t[0].tx_buf = flash->command;
	t[0].cs_change = 1;
	spi_message_add_tail(&t[0], &m);

	//Addr
	t[1].tx_nbits = SPI_NBITS_SINGLE;
	t[1].bits_per_word = 32;
	t[1].len = 4;
	t[1].tx_buf = flash->addr;
	t[1].cs_change = 0;

	spi_message_add_tail(&t[1], &m);

	spi_sync(spi, &m);

	mutex_unlock(&flash->transfer_lock);

	return 0;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 5, 0)
static int agtx_spi_prepare(struct spi_nor *nor)
{
#if defined(CONFIG_OPTEE)
	/* For OP-TEE */
	auge_spi_lock_optee();
#endif /* CONFIG_OPTEE */
	return 0;
}

static void agtx_spi_unprepare(struct spi_nor *nor)
{
#if defined(CONFIG_OPTEE)
	/* For OP-TEE */
	auge_spi_unlock_optee();
#endif /* CONFIG_OPTEE */
}

static const struct spi_nor_controller_ops augentix_controller_ops = {
	.prepare = agtx_spi_prepare,
	.unprepare = agtx_spi_unprepare,
	.read_reg = m25p80_read_reg,
	.write_reg = m25p80_write_reg,
	.read = m25p80_read,
	.write = m25p80_write,
	.erase = m25p80_erase,
};
#endif

/*
 * board specific setup should have ensured the SPI clock used here
 * matches what the READ command supports, at least until this driver
 * understands FAST_READ (for clocks over 25 MHz).
 */
static int m25p_probe(struct spi_device *spi)
{
	struct mtd_part_parser_data	ppdata;
	struct flash_platform_data	*data;
	struct m25p *flash;
	struct spi_nor *nor;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 13, 0)
	enum read_mode rmode = SPI_NOR_NORMAL;
	enum write_mode wmode = SPI_NOR_WRITE_SINGLE;
#else
	struct spi_nor_hwcaps hwcaps = { .mask = SNOR_HWCAPS_READ | SNOR_HWCAPS_READ_FAST | SNOR_HWCAPS_PP };
#endif
	char *flash_name = NULL;
	int ret;

	data = dev_get_platdata(&spi->dev);

	flash = devm_kzalloc(&spi->dev, sizeof(*flash), GFP_KERNEL);
	if (!flash)
		return -ENOMEM;

	nor = &flash->spi_nor;

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0)
	/* install the hooks */
	nor->read = m25p80_read;
	nor->write = m25p80_write;
	nor->write_reg = m25p80_write_reg;
	nor->read_reg = m25p80_read_reg;
#endif
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 5, 0)
	nor->erase = m25p80_erase;
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 5, 0)
	nor->controller_ops = &augentix_controller_ops;
#endif
	nor->dev = &spi->dev;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0)
	nor->mtd = &flash->mtd;
	flash->mtd.priv = nor;
#else
	flash->mtd = &nor->mtd;
	flash->mtd->priv = nor;
#endif
	nor->priv = flash;

	spi_set_drvdata(spi, flash);
	flash->spi = spi;

	mutex_init(&flash->transfer_lock);
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 13, 0)
	if (spi->mode & SPI_RX_QUAD)
		rmode = SPI_NOR_QUAD;
	else if (spi->mode & SPI_RX_DUAL)
		rmode = SPI_NOR_DUAL;

	if (spi->mode & SPI_TX_QUAD)
		wmode = SPI_NOR_WRITE_QUAD;

	if (data && data->name)
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0)
		flash->mtd.name = data->name;
#else
		flash->mtd->name = data->name;
#endif
#else
	if (spi->mode & SPI_RX_QUAD)
		hwcaps.mask |= SNOR_HWCAPS_READ_1_1_2 | SNOR_HWCAPS_READ_1_1_4;
	else if (spi->mode & SPI_RX_DUAL)
		hwcaps.mask |= SNOR_HWCAPS_READ_1_1_2;

	if (spi->mode & SPI_TX_QUAD)
		hwcaps.mask |= SNOR_HWCAPS_PP_1_1_4;

	nor->mtd.name = "nor_flash";
#endif
	/* For some (historical?) reason many platforms provide two different
	 * names in flash_platform_data: "name" and "type". Quite often name is
	 * set to "m25p80" and then "type" provides a real chip name.
	 * If that's the case, respect "type" and ignore a "name".
	 */
	if (data && data->type)
		flash_name = data->type;
	else
		flash_name = spi->modalias;

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 13, 0)
	ret = spi_nor_scan(nor, flash_name, rmode, wmode);
#else
	ret = spi_nor_scan(nor, flash_name, &hwcaps);
#endif
	if (ret)
		return ret;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 5, 0)
	ppdata.of_node = spi->dev.of_node;
#else
	spi_nor_set_flash_node(nor, spi->dev.of_node);
#endif
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0)
	return mtd_device_parse_register(&flash->mtd, NULL, &ppdata,
			data ? data->parts : NULL,
			data ? data->nr_parts : 0);
#else
	return mtd_device_parse_register(&nor->mtd, NULL, &ppdata, data ? data->parts : NULL,
	                                 data ? data->nr_parts : 0);
#endif
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 18, 0)
static int m25p_remove(struct spi_device *spi)
{
	struct m25p	*flash = spi_get_drvdata(spi);
	/* Clean up MTD stuff. */
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0)
	return mtd_device_unregister(&flash->mtd);
#else
	return mtd_device_unregister(flash->mtd);
#endif
}
#else
static void m25p_remove(struct spi_device *spi)
{
	struct m25p *flash = spi_get_drvdata(spi);
	/* Clean up MTD stuff. */
	mtd_device_unregister(flash->mtd);
}
#endif

/*
 * XXX This needs to be kept in sync with spi_nor_ids.  We can't share
 * it with spi-nor, because if this is built as a module then modpost
 * won't be able to read it and add appropriate aliases.
 */
static const struct spi_device_id m25p_ids[] = {
	{ "at25fs010" },       { "at25fs040" },       { "at25df041a" },       { "at25df321a" },
	{ "at25df641" },       { "at26f004" },        { "at26df081a" },       { "at26df161a" },
	{ "at26df321" },       { "at45db081d" },      { "by25q64es" },        { "by25q128es" },
	{ "en25f32" },         { "en25p32" },         { "en25q32b" },         { "en25p64" },
	{ "en25q64" },         { "en25qh128" },       { "en25qx128" },        { "en25qh256" },
	{ "f25l32pa" },        { "mr25h256" },        { "mr25h10" },          { "gd25q32" },
	{ "gd25q64e" },        { "160s33b" },         { "320s33b" },          { "640s33b" },
	{ "mx25l2005a" },      { "mx25l4005a" },      { "mx25l8005" },        { "mx25l1606e" },
	{ "mx25l3205d" },      { "mx25l3255e" },      { "mx25l6405d" },       { "mx25l12805d" },
	{ "mx25l12855e" },     { "mx25l25645g" },     { "mx25l25635e" },      { "mx25l25655e" },
	{ "mx66l51235l" },     { "mx66l1g55g" },      { "n25q064" },          { "n25q128a11" },
	{ "n25q128a13" },      { "n25q256a" },        { "n25q512a" },         { "n25q512ax3" },
	{ "n25q00" },          { "pm25lv512" },       { "pm25lv010" },        { "pm25lq032" },
	{ "nm25q128evb" },     { "zb25vq128a" },      { "zb25vq64a" },        { "gm25q128a" },
	{ "gm25q64a" },        { "s25sl032p" },       { "s25sl064p" },        { "s25fl256s0" },
	{ "s25fl256s1" },      { "s25fl512s" },       { "s70fl01gs" },        { "s25sl12800" },
	{ "s25sl12801" },      { "s25fl129p0" },      { "s25fl129p1" },       { "s25sl004a" },
	{ "s25sl008a" },       { "s25sl016a" },       { "s25sl032a" },        { "s25sl064a" },
	{ "s25fl008k" },       { "s25fl016k" },       { "s25fl064k" },        { "sst25vf040b" },
	{ "sst25vf080b" },     { "sst25vf016b" },     { "sst25vf032b" },      { "sst25vf064c" },
	{ "sst25wf512" },      { "sst25wf010" },      { "sst25wf020" },       { "sst25wf040" },
	{ "m25p05" },          { "m25p10" },          { "m25p20" },           { "m25p40" },
	{ "m25p80" },          { "m25p16" },          { "m25p32" },           { "m25p64" },
	{ "m25p128" },         { "n25q032" },         { "m25p05-nonjedec" },  { "m25p10-nonjedec" },
	{ "m25p20-nonjedec" }, { "m25p40-nonjedec" }, { "m25p80-nonjedec" },  { "m25p16-nonjedec" },
	{ "m25p32-nonjedec" }, { "m25p64-nonjedec" }, { "m25p128-nonjedec" }, { "m45pe10" },
	{ "m45pe80" },         { "m45pe16" },         { "m25pe20" },          { "m25pe80" },
	{ "m25pe16" },         { "m25px16" },         { "m25px32" },          { "m25px32-s0" },
	{ "m25px32-s1" },      { "m25px64" },         { "m25px80" },          { "xm25qh64c" },
	{ "xm25qh128a" },      { "xm25qh128c" },      { "w25x10" },           { "w25x20" },
	{ "w25x40" },          { "w25x80" },          { "w25x16" },           { "w25x32" },
	{ "w25q32" },          { "w25q32dw" },        { "w25x64" },           { "w25q64" },
	{ "w25q80" },          { "w25q80bl" },        { "w25q128" },          { "w25q256" },
	{ "cat25c11" },        { "cat25c03" },        { "cat25c09" },         { "cat25c17" },
	{ "cat25128" },        { "p25q64ha" },        { "fm25q128a" },        { "xm25qh64d" },
	{ "s25fl128l" },       { "s25fl256l" },
};
MODULE_DEVICE_TABLE(spi, m25p_ids);

static struct spi_driver m25p80_driver = {
    .driver =
        {
            .name = "m25p80",
            .owner = THIS_MODULE,
        },
    .id_table = m25p_ids,
    .probe = m25p_probe,
    .remove = m25p_remove,

    /* REVISIT: many of these chips have deep power-down modes, which
     * should clearly be entered on suspend() to minimize power use.
     * And also when they're otherwise idle...
     */
};

module_spi_driver(m25p80_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mike Lavender");
MODULE_DESCRIPTION("MTD SPI driver for ST M25Pxx flash chips");
