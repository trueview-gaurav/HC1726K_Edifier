/*
 * SPI flash interface
 *
 * Copyright (C) 2008 Atmel Corporation
 * Copyright (C) 2010 Reinhard Meyer, EMK Elektronik
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <spi.h>
#include <spi_flash.h>
#include "agtx_sf_internal.h"

/* Does not work in SDK - Start */
static int spi_flash_read_write(struct spi_slave *spi,
				const u8 *cmd, size_t cmd_len,
				const u8 *data_out, u8 *data_in,
				size_t data_len)
{
	unsigned long flags = SPI_XFER_BEGIN;
	int ret;

	if (data_len == 0)
		flags |= SPI_XFER_END;

	ret = spi_xfer(spi, cmd_len * 8, cmd, NULL, flags);
	if (ret) {
		debug("SF: Failed to send command (%zu bytes): %d\n",
		      cmd_len, ret);
	} else if (data_len != 0) {
		ret = spi_xfer(spi, data_len * 8, data_out, data_in,
					SPI_XFER_END);
		if (ret)
			debug("SF: Failed to transfer %zu bytes of data: %d\n",
			      data_len, ret);
	}

	return ret;
}

int spi_flash_cmd_read(struct spi_slave *spi, const u8 *cmd,
		size_t cmd_len, void *data, size_t data_len)
{
	return spi_flash_read_write(spi, cmd, cmd_len, NULL, data, data_len);
}

int spi_flash_cmd(struct spi_slave *spi, u8 cmd, void *response, size_t len)
{
	return spi_flash_cmd_read(spi, &cmd, 1, response, len);
}

int spi_flash_cmd_write(struct spi_slave *spi, const u8 *cmd, size_t cmd_len,
		const void *data, size_t data_len)
{
	return spi_flash_read_write(spi, cmd, cmd_len, data, NULL, data_len);
}
/* Does not work in SDK - End */

void spi_flash_off2addr(u32 off, u8 *addr)
{
	addr[0] = (u8)((off & 0x000000ff) >> 0);
	addr[1] = (u8)((off & 0x0000ff00) >> 8);
	addr[2] = (u8)((off & 0x00ff0000) >> 16);
	addr[3] = (u8)((off & 0xff000000) >> 24);
}

/* RDSR, RDCR, RDFSR, RDID, addr_l & wait_l = 0 */
int agtx_read_reg(struct spi_slave *spi, u8 cmd, u8 *val, u32 len)
{
	u32 addr_l = 0;
	u32 wait_l = 0;

	/* AGTX QSPI - CSR setting */
	spi->dma_mode = 0;
	spi->frame_format = AGTX_QSPI_FRF__SSPI;
	spi->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	spi->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                (wait_l << AGTX_QSPI_WAIT_L_OFFSET);
	// Read
	spi->tmode = AGTX_SPI_TMOD_RO;
	spi->ndf = len;

	spi_claim_bus(spi);

	/* CMD */
	spi->bits_per_word = 8;
	spi_xfer(spi, 1, &cmd, NULL, 1);

	/* RX */
	spi->bits_per_word = 8;
	spi_xfer(spi, len, NULL, val, 0);

	return 0;
}

/* WRSR, WREN, WRDI, EN4B, EX4B, BRWR, CHIP_ERASE, addr_l & wait_l = 0 */
int agtx_write_reg(struct spi_slave *spi, u8 cmd, u8 *buf, u32 len)
{
	u32 addr_l = 0;
	u32 wait_l = 0;
	u32 flags = 0;

	/* AGTX QSPI - CSR setting */
	spi->dma_mode = 0;
	spi->frame_format = AGTX_QSPI_FRF__SSPI;
	spi->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	spi->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                (wait_l << AGTX_QSPI_WAIT_L_OFFSET);
	// Write
	spi->tmode = AGTX_SPI_TMOD_TO;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	spi->ndf = len;
#elif defined(CONFIG_HC1703_1723_1753_1783S)
	spi->ndfw = len;
#endif /* Sapporo, Osaka, or Kamo */

	spi_claim_bus(spi);

	/* CMD */
	spi->bits_per_word = 8;
	flags = len ? 1 : 0; 
	spi_xfer(spi, 1, &cmd, NULL, flags);

	/* TX */
	if (len) {
		spi->bits_per_word = 8;
		spi_xfer(spi, len, buf, NULL, 0);
	}

	return 0;
}

/* All wait_l = 0; SE, BE_4K, BE_4K_PMC: addr_l = 3; SE_4B: addr_l = 4 */
int agtx_erase_ops(struct spi_flash *flash, u8 cmd, u32 offset)
{
	struct spi_slave *spi_slave = flash->spi;
	u32 addr_l = 0;
	u32 wait_l = 0;
	u8 addr[4];

	spi_flash_off2addr(offset, addr);

	addr_l = (flash->addr_width << 1) & 0xFF;

	/* AGTX QSPI - CSR setting */
	spi_slave->dma_mode = 0;
	spi_slave->frame_format = AGTX_QSPI_FRF__SSPI;
	spi_slave->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	spi_slave->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) |
	                      (addr_l << AGTX_QSPI_ADDR_L_OFFSET) | (wait_l << AGTX_QSPI_WAIT_L_OFFSET);

	// Read
	spi_slave->tmode = AGTX_SPI_TMOD_TO;
	spi_slave->ndf = 0;

	spi_claim_bus(spi_slave);

	/* CMD */
	spi_slave->bits_per_word = 8;
	spi_xfer(spi_slave, 1, &cmd, NULL, 1);

	/* Addr */
	spi_slave->bits_per_word = 32;
	spi_xfer(spi_slave, flash->addr_width, &addr, NULL, 0);

	return 0;
}

/*
 * Read an address range from the nor chip.  The address range
 * may be any size provided it is within the physical boundaries.
 */
int agtx_read_ops(struct spi_flash *flash, u32 from, size_t len,
			void *buf)
{
	struct spi_slave *spi_slave = flash->spi;
	int dummy = flash->dummy_byte;
	u32 addr_l = 0;
	u32 wait_l = 0;
	u8 addr[4];

	/* wait_l = dummy, from spi_nor_read_dummy_cycles(),
	 * READ_1_1_4, READ_1_1_2, READ_FAST, READ, addr_l = 3;
	 * READ4_1_1_4, READ4_1_1_2, READ4_FAST, READ4, addr_l = 4;
	 * from spi_nor_scan() determined */
	
	spi_flash_off2addr(from, addr);

	addr_l = (flash->addr_width << 1) & 0xFF;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	wait_l = (dummy > 0) ? (dummy << 3) & 0xFF : 0;
#elif defined(CONFIG_HC1703_1723_1753_1783S)
	wait_l = (dummy > 0) ? ((dummy << 3) - 1) & 0xFF : 0;
#endif /* Sapporo, Osaka, or Kamo */
	/* AGTX QSPI - CSR setting */
	spi_slave->dma_mode = IS_DMA;

	if ((flash->read_cmd == 0x6b) || (flash->read_cmd == 0x6c)) {
		spi_slave->frame_format = AGTX_QSPI_FRF__QSPI;
	} else if ((flash->read_cmd == 0x3b) || (flash->read_cmd == 0x3c)) {
		spi_slave->frame_format = AGTX_QSPI_FRF__DSPI;
	} else {
		spi_slave->frame_format = AGTX_QSPI_FRF__SSPI;
	}

	spi_slave->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	spi_slave->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) |
	                      (addr_l << AGTX_QSPI_ADDR_L_OFFSET) | (wait_l << AGTX_QSPI_WAIT_L_OFFSET);
#if defined(CONFIG_OSAKA)
	spi_slave->ndf = len;
#else
	spi_slave->ndf = len >> spi_slave->frame_format;
#endif /* CONFIG_OSAKA */
	// Read
	spi_slave->tmode = AGTX_SPI_TMOD_RO;

	spi_claim_bus(spi_slave);

	/* CMD */
	spi_slave->bits_per_word = 8;
	spi_xfer(spi_slave, 1, &flash->read_cmd, NULL, 1);

	/* ADDR */
	spi_slave->bits_per_word = 32;
	spi_xfer(spi_slave, 4, &addr, NULL, 1);

	/* RX */
	spi_slave->bits_per_word = 8;
	spi_xfer(spi_slave, len, NULL, buf, 0);

	return 0;
}

/*
 * to:	data destination (Flash)
 * len:	chunk length
 * buf:	data source
 */
int agtx_write_ops(struct spi_flash *flash, u32 to, size_t len,
			const void *buf)
{
	struct spi_slave *spi_slave = flash->spi;
	u32 addr_l = 0;
	u32 wait_l = 0;
	u8 addr[4];

	/* wait_l = 0,
	 * BP, AAI_WP, PP, addr_l = 3;
	 * PP_4B, addr_l = 4;
	 * from spi_nor_scan() determined */
	
	spi_flash_off2addr(to, addr);
	addr_l = (flash->addr_width << 1) & 0xFF;

	/* AGTX QSPI - CSR setting */
	spi_slave->dma_mode = IS_DMA;

	if (flash->write_cmd == 0x32 || flash->write_cmd == 0x34) {
		spi_slave->frame_format = AGTX_QSPI_FRF__QSPI;
	} else {
		spi_slave->frame_format = AGTX_QSPI_FRF__SSPI;
	}
	spi_slave->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	spi_slave->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) |
	                      (addr_l << AGTX_QSPI_ADDR_L_OFFSET) | (wait_l << AGTX_QSPI_WAIT_L_OFFSET);

	// Write
	spi_slave->tmode = AGTX_SPI_TMOD_TO;

#if defined(CONFIG_OSAKA)
	spi_slave->ndf = len;
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
	spi_slave->ndf = len >> spi_slave->frame_format;
#else
	spi_slave->ndfw = len >> spi_slave->frame_format;
#endif /* CONFIG_OSAKA */
	spi_claim_bus(spi_slave);

	/* CMD */
	spi_slave->bits_per_word = 8;
	spi_xfer(spi_slave, 1, &flash->write_cmd, NULL, 1);

	/* ADDR */
	spi_slave->bits_per_word = 32;
	spi_xfer(spi_slave, 4, &addr, NULL, 1);

	/* TX */
	spi_slave->bits_per_word = 32;
	spi_xfer(spi_slave, len, buf, NULL, 0);

	return 0;
}
