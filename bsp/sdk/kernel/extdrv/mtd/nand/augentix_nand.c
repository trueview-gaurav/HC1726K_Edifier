/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * 2025 Augentix, Inc.
 */

/*
 * Copyright (c) 2003-2013 Broadcom Corporation
 *
 * Copyright (c) 2009-2010 Micron Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/spi/spi.h>
#include <linux/version.h>

#include <linux/mtd/nand.h>
#include <linux/spi/augentix_serial_flash.h>
#include "augentix_nand_hw_ecc.h"

#include <linux/random.h>

#define CONFIG_MTD_SPINAND_ONDIEECC 1
#define BUFSIZE 2112
#define CACHE_BUF 2112

/* cmd */
#define CMD_RESET 0xFF
#define CMD_READ_ID 0x9f
#define CMD_READ_REG 0x0f
#define CMD_WRITE_REG 0x1f
#define CMD_WR_ENABLE 0x06
#define CMD_WR_DISABLE 0x04
#define CMD_ERASE_BLK 0xD8
#define CMD_PROG_PAGE_CLRCACHE 0x02
#define CMD_PROG_PAGE 0x84
#define CMD_PROG_PAGE_QUAD_CLRCACHE 0x32
#define CMD_PROG_PAGE_QUAD 0x34
#define CMD_PROG_PAGE_EXC 0x10
#define CMD_READ 0x13
#define CMD_READ_RDM 0x0B
#define CMD_READ_DRDM 0x3B
#define CMD_READ_QRDM 0x6B

/* feature/ status reg */
#define REG_BLOCK_LOCK 0xA0
#define REG_OTP 0xB0
#define REG_STATUS 0xC0 /* timing */

/* status */
#define STATUS_OIP_MASK 0x01
#define STATUS_READY (0 << 0)
#define STATUS_BUSY (1 << 0)

#define STATUS_E_FAIL_MASK 0x04
#define STATUS_E_FAIL (1 << 2)

#define STATUS_P_FAIL_MASK 0x08
#define STATUS_P_FAIL (1 << 3)

#define STATUS_ECC_MASK 0x30
#define STATUS_ECC_1BIT_CORRECTED (1 << 4)
#define STATUS_ECC_ERROR (2 << 4)
#define STATUS_ECC_RESERVED (3 << 4)

/*ECC enable defines*/
#define OTP_ECC_MASK 0x10
#define OTP_ECC_OFF 0
#define OTP_ECC_ON 1

/*block lock*/
#define BL_ALL_UNLOCKED 0

struct spinand_info {
	struct nand_ecclayout *ecclayout;
	struct spi_device *spi;
	void *priv;
};

struct spinand_state {
	uint32_t col;
	uint32_t row;
	int buf_ptr;
	u8 *buf;
};

//spi command structure
struct spinand_cmd {
	u8 cmd;
	u8 bDFS_32; /* 32 bits per word */
	u32 n_addr; /* Number of address */
	u8 addr[4]; /* Reg Offset */
	u32 n_dummy; /* Dummy use */
	u32 n_tx; /* Number of tx bytes */
	u8 *tx_buf; /* Tx buf */
	u32 n_rx; /* Number of rx bytes */
	u8 *rx_buf; /* Rx buf */
};

static inline struct spinand_state *mtd_to_state(struct mtd_info *mtd)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 19, 0)
	struct nand_chip *chip = (struct nand_chip *)mtd->priv;
#endif
	struct spinand_info *info = (struct spinand_info *)chip->priv;
	struct spinand_state *state = (struct spinand_state *)info->priv;

	return state;
}

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
static int enable_hw_ecc;
static int enable_read_hw_ecc;
#endif

static uint32_t chip_ver;

uint32_t get_chip_ver(void)
{
	void __iomem *addr;
	uint32_t ver;

	addr = ioremap(0x80010004, 4);

	ver = ioread32(addr) & 0xFF;

	iounmap(addr);

	return ver;
}

static int spinand_cmd(struct spi_device *spi, struct spinand_cmd *cmd)
{
	/* TODO: Use bDFS_32 to remove spinand_cmd() and SPI_BITS_PER_WORD */
	//#define SPI_BITS_PER_WORD        8

	struct spi_message message;
	struct spi_transfer x[4];
	struct chip_data *chip = (struct chip_data *)spi->controller_state;
	u8 dummy = 0xFF;
	u32 addr_l = (cmd->n_addr << 1) & 0xFF;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	u32 wait_l = (cmd->n_dummy > 0) ? (cmd->n_dummy << 3) & 0xFF : 0;
#else
	u32 wait_l = (cmd->n_dummy > 0) ? ((cmd->n_dummy << 3) - 1) & 0xFF : 0;
#endif

	chip->dma_mode = 0;
	chip->frame_format = AGTX_QSPI_FRF__SSPI;
	chip->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	chip->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                 (wait_l << AGTX_QSPI_WAIT_L_OFFSET);

	if (cmd->n_rx) {
		chip->tmode = AGTX_SPI_TMOD_RO;
		chip->ndf = cmd->n_rx;
	} else {
		chip->tmode = AGTX_SPI_TMOD_TO;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		chip->ndf = cmd->n_tx;
#else
		chip->ndfw = cmd->n_tx;
#endif
	}

	spi_message_init(&message);
	memset(x, 0, sizeof(x));

	//CMD
	x[0].tx_nbits = SPI_NBITS_SINGLE;
	x[0].bits_per_word = 8;
	x[0].len = 1;
	x[0].tx_buf = &cmd->cmd;
	x[0].cs_change = (cmd->n_addr || cmd->n_dummy || cmd->n_tx || cmd->n_rx) ? 1 : 0;

	spi_message_add_tail(&x[0], &message);

	//Addr
	if (cmd->n_addr) {
		x[1].tx_nbits = SPI_NBITS_SINGLE;
		if (cmd->n_addr == 3) {
			x[1].bits_per_word = 32;
			x[1].len = 4;
		} else if (cmd->n_addr == 2) {
			x[1].bits_per_word = 16;
			x[1].len = cmd->n_addr;
		} else {
			x[1].bits_per_word = 8;
			x[1].len = cmd->n_addr;
		}
		x[1].tx_buf = cmd->addr;
		x[1].cs_change = (cmd->n_dummy || cmd->n_tx || cmd->n_rx) ? 1 : 0;

		spi_message_add_tail(&x[1], &message);
	}

	//dummy
	if (cmd->n_dummy) {
		x[2].tx_nbits = SPI_NBITS_SINGLE;
		x[2].bits_per_word = 8;
		x[2].len = cmd->n_dummy;
		x[2].tx_buf = &dummy;
		x[2].cs_change = (cmd->n_tx || cmd->n_rx) ? 1 : 0;

		spi_message_add_tail(&x[2], &message);
	}

	//tx
	if (cmd->n_tx) {
		x[3].tx_nbits = SPI_NBITS_SINGLE;
		x[3].bits_per_word = 8;
		x[3].len = cmd->n_tx;
		x[3].tx_buf = cmd->tx_buf;
		x[3].cs_change = 0; //set 0 to start transmission
		spi_message_add_tail(&x[3], &message);
	}

	//rx
	if (cmd->n_rx) {
		x[3].rx_nbits = SPI_NBITS_SINGLE;
		x[3].bits_per_word = 8;
		x[3].len = cmd->n_rx;
		x[3].rx_buf = cmd->rx_buf;
		x[3].cs_change = 0; //set 0 to start receive

		spi_message_add_tail(&x[3], &message);
	}

	return spi_sync(spi, &message);
}

static int qspinand_cmd(struct spi_device *spi, struct spinand_cmd *cmd)
{
	struct spi_message message;
	struct spi_transfer x[4];
	struct chip_data *chip = (struct chip_data *)spi->controller_state;
	u8 dummy = 0xFF;
	u32 addr_l = (cmd->n_addr << 1) & 0xFF;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	u32 wait_l = (cmd->n_dummy > 0) ? (cmd->n_dummy << 3) & 0xFF : 0;
#else
	u32 wait_l = (cmd->n_dummy > 0) ? ((cmd->n_dummy << 3) - 1) & 0xFF : 0;
#endif
	u8 agtx_qspi_frf = AGTX_QSPI_FRF__SSPI;

	if ((cmd->cmd == CMD_READ_QRDM) || (cmd->cmd == CMD_PROG_PAGE_QUAD_CLRCACHE) ||
	    (cmd->cmd == CMD_PROG_PAGE_QUAD)) {
		agtx_qspi_frf = AGTX_QSPI_FRF__QSPI;
	} else if (cmd->cmd == CMD_READ_DRDM) {
		agtx_qspi_frf = AGTX_QSPI_FRF__DSPI;
	} else if ((cmd->cmd == CMD_READ_RDM) || (cmd->cmd == CMD_PROG_PAGE_CLRCACHE) || (cmd->cmd == CMD_PROG_PAGE)) {
		agtx_qspi_frf = AGTX_QSPI_FRF__SSPI;
	}

	chip->dma_mode = 0;
	chip->frame_format = agtx_qspi_frf;
	chip->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	chip->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                 (wait_l << AGTX_QSPI_WAIT_L_OFFSET);

	if (cmd->n_rx) {
		chip->tmode = AGTX_SPI_TMOD_RO;
#if defined(CONFIG_OSAKA)
		chip->ndf = cmd->n_tx;
#else
		chip->ndf = (cmd->n_rx) >> agtx_qspi_frf;
#endif /* CONFIG_OSAKA */
	} else { /* for tx */
		chip->tmode = AGTX_SPI_TMOD_TO;
#if defined(CONFIG_OSAKA)
		chip->ndf = cmd->n_tx;
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
		chip->ndf = (cmd->n_tx) >> agtx_qspi_frf;
#else
		chip->ndfw = (cmd->n_tx) >> agtx_qspi_frf;
#endif /* CONFIG_OSAKA */
	}

	spi_message_init(&message);
	memset(x, 0, sizeof(x));

	//CMD
	x[0].tx_nbits = SPI_NBITS_SINGLE; //1 bit transfer
	x[0].bits_per_word = 8;
	x[0].len = 1;
	x[0].tx_buf = &cmd->cmd; //flash opcode
	x[0].cs_change = 1; //set 1 to wait

	spi_message_add_tail(&x[0], &message);

	//Addr
	if (cmd->n_addr) {
		x[1].tx_nbits = SPI_NBITS_SINGLE;
		x[1].bits_per_word = 16;
		x[1].len = cmd->n_addr;
		x[1].tx_buf = cmd->addr; //flash column address
		x[1].cs_change = (cmd->n_dummy || cmd->n_tx || cmd->n_rx) ? 1 : 0;

		spi_message_add_tail(&x[1], &message);
	}

	//dummy
	if (cmd->n_dummy) {
		x[2].tx_nbits = SPI_NBITS_SINGLE;
		x[2].bits_per_word = 8;
		x[2].len = cmd->n_dummy;
		x[2].tx_buf = &dummy;
		x[2].cs_change = (cmd->n_tx || cmd->n_rx) ? 1 : 0;

		spi_message_add_tail(&x[2], &message);
	}

	//tx
	if (cmd->n_tx) {
		x[3].tx_nbits = SPI_NBITS_SINGLE;
		x[3].bits_per_word = cmd->bDFS_32 ? 32 : 8;
		x[3].len = cmd->n_tx;
		x[3].tx_buf = cmd->tx_buf;
		x[3].cs_change = 0; //set 0 to start transmission
		chip->dma_mode = 1;
		spi_message_add_tail(&x[3], &message);
	}

	//rx
	if (cmd->n_rx) {
		//	x[3].rx_nbits      = SPI_NBITS_QUAD;
		x[3].bits_per_word = cmd->bDFS_32 ? 32 : 8;
		x[3].len = cmd->n_rx;
		x[3].rx_buf = cmd->rx_buf;
		x[3].cs_change = 0; //set 0 to start receive
		chip->dma_mode = 1;
		spi_message_add_tail(&x[3], &message);
	}

	return spi_sync(spi, &message);
}

/*
 * spinand_id_has_period - Check if an ID string has a given wraparound period
 * @id_data: the ID string
 * @arrlen: the length of the @id_data array
 * @period: the period of repitition
 *
 * Check if an ID string is repeated within a given sequence of bytes at
 * specific repetition interval period (e.g., {0x20,0x01,0x7F,0x20} has a
 * period of 3). This is a helper function for nand_id_len(). Returns non-zero
 * if the repetition has a period of @period; otherwise, returns zero.
 */
static int spinand_id_has_period(u8 *id_data, int arrlen, int period)
{
	int i, j;
	for (i = 0; i < period; i++)
		for (j = i + period; j < arrlen; j += period)
			if (id_data[i] != id_data[j])
				return 0;
	return 1;
}

/*
 * spinand_id_len - Get the length of an ID string returned by CMD_READID
 * @id_data: the ID string
 * @arrlen: the length of the @id_data array

 * Returns the length of the ID string, according to known wraparound/trailing
 * zero patterns. If no pattern exists, returns the length of the array.
 */
static int spinand_id_len(u8 *id_data, int arrlen)
{
	int last_nonzero, period;

	/* Find last non-zero byte */
	for (last_nonzero = arrlen - 1; last_nonzero >= 0; last_nonzero--)
		if (id_data[last_nonzero])
			break;

	/* All zeros */
	if (last_nonzero < 0)
		return 0;

	/* Filter JEDEC Maker Code Continuation Code, 7Fh */
	if (id_data[0] == 0xC8 && id_data[1] == 0x01) {
		arrlen = 2;
		return arrlen;
	}

	/* Calculate wraparound period */
	for (period = 1; period < arrlen; period++)
		if (spinand_id_has_period(id_data, arrlen, period))
			break;

	/* There's a repeated pattern */
	if (period < arrlen)
		return period;

	/* There are trailing zeros */
	if (last_nonzero < arrlen - 1)
		return last_nonzero + 1;

	/* No pattern detected */
	return arrlen;
}

/*
 * spinand_read_id- Read SPI Nand ID
 * Description:
 *    Read ID: read two ID bytes from the SPI Nand device
 */
static int spinand_read_id(struct spi_device *spi_nand, u8 *id)
{
	int ret;
	u8 nand_id[4] = { 0, 0, 0, 0 };
	struct spinand_cmd cmd;
	int i = 0, id_len = 0;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	cmd.cmd = CMD_READ_ID;
	cmd.n_addr = 1;
	cmd.addr[0] = 0x00;
	cmd.n_rx = 4;
	cmd.rx_buf = &nand_id[0];

	ret = spinand_cmd(spi_nand, &cmd);
	if (ret < 0) {
		dev_err(&spi_nand->dev, "error %d reading id\n", ret);
		return ret;
	}

	id_len = spinand_id_len(nand_id, 4);
	for (i = 0; i < id_len; i++) {
		id[i] = nand_id[i];
	}

	return ret;
}

/*
 * spinand_read_status- send command 0xf to the SPI Nand status register
 * Description:
 *    After read, write, or erase, the Nand device is expected to set the
 *    busy status.
 *    This function is to allow reading the status of the command: read,
 *    write, and erase.
 *    Once the status turns to be ready, the other status bits also are
 *    valid status bits.
 */
static int spinand_read_status(struct spi_device *spi_nand, uint8_t *status)
{
	int ret;
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	cmd.cmd = CMD_READ_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_STATUS;
	cmd.n_rx = 1;
	cmd.rx_buf = status;

	ret = spinand_cmd(spi_nand, &cmd);
	if (ret < 0)
		dev_err(&spi_nand->dev, "err: %d read status register\n", ret);

	return ret;
}

#define MAX_WAIT_JIFFIES (40 * HZ)
static int wait_till_ready(struct spi_device *spi_nand)
{
	unsigned long deadline;
	int retval;
	u8 stat = 0;

	deadline = jiffies + MAX_WAIT_JIFFIES;
	do {
		retval = spinand_read_status(spi_nand, &stat);

		if (retval < 0)
			return -1;
		else if (!(stat & 0x1))
			break;

		cond_resched();
	} while (!time_after_eq(jiffies, deadline));

	if ((stat & 0x1) == 0)
		return 0;

	return -1;
}

/**
 * spinand_get_otp- send command 0xf to read the SPI Nand OTP register
 * Description:
 *   There is one bit( bit 0x10 ) to set or to clear the internal ECC.
 *   Enable chip internal ECC, set the bit to 1
 *   Disable chip internal ECC, clear the bit to 0
 */
static int spinand_get_otp(struct spi_device *spi_nand, u8 *otp)
{
	int ret;
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	cmd.cmd = CMD_READ_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_OTP;
	cmd.n_rx = 1;
	cmd.rx_buf = otp;

	ret = spinand_cmd(spi_nand, &cmd);
	if (ret < 0)
		dev_err(&spi_nand->dev, "error %d get otp\n", ret);

	return ret;
}

/**
 * spinand_set_otp- send command 0x1f to write the SPI Nand OTP register
 * Description:
 *   There is one bit( bit 0x10 ) to set or to clear the internal ECC.
 *   Enable chip internal ECC, set the bit to 1
 *   Disable chip internal ECC, clear the bit to 0
 */
static int spinand_set_otp(struct spi_device *spi_nand, u8 *otp)
{
	int ret;
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	cmd.cmd = CMD_WRITE_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_OTP;
	cmd.n_tx = 1;
	cmd.tx_buf = otp;

	ret = spinand_cmd(spi_nand, &cmd);
	if (ret < 0)
		dev_err(&spi_nand->dev, "error %d set otp\n", ret);

	return ret;
}

#if 0
/**
 * spinand_enable_ecc- send command 0x1f to write the SPI Nand OTP register
 * Description:
 *   There is one bit( bit 0x10 ) to set or to clear the internal ECC.
 *   Enable chip internal ECC, set the bit to 1
 *   Disable chip internal ECC, clear the bit to 0
 */
static int spinand_enable_ecc(struct spi_device *spi_nand)
{
	int retval;
	u8 otp = 0;

	retval = spinand_get_otp(spi_nand, &otp);
	if (retval < 0)
		return retval;

	if ((otp & OTP_ECC_MASK) == OTP_ECC_MASK)
		return 0;
	otp |= OTP_ECC_MASK;
	retval = spinand_set_otp(spi_nand, &otp);
	if (retval < 0)
		return retval;
	return spinand_get_otp(spi_nand, &otp);
}

static int spinand_disable_ecc(struct spi_device *spi_nand)
{
	int retval;
	u8 otp = 0;

	retval = spinand_get_otp(spi_nand, &otp);
	if (retval < 0)
		return retval;

	if ((otp & OTP_ECC_MASK) == OTP_ECC_MASK) {
		otp &= ~OTP_ECC_MASK;

		retval = spinand_set_otp(spi_nand, &otp);
		if (retval < 0)
			return retval;
		return spinand_get_otp(spi_nand, &otp);
	}

	return 0;
}
#endif

/**
 * spinand_write_enable- send command 0x06 to enable write or erase the
 * Nand cells
 * Description:
 *   Before write and erase the Nand cells, the write enable has to be set.
 *   After the write or erase, the write enable bit is automatically
 *   cleared (status register bit 2)
 *   Set the bit 2 of the status register has the same effect
 */
static int spinand_write_enable(struct spi_device *spi_nand)
{
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	cmd.cmd = CMD_WR_ENABLE;
	cmd.n_addr = 0; //for consistent with bare-metal implementation

	return spinand_cmd(spi_nand, &cmd);
}

static int spinand_read_page_to_cache(struct spi_device *spi_nand, u32 page_id)
{
	u32 row;
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	row = page_id;
	cmd.cmd = CMD_READ;
	cmd.n_addr = 3;
	cmd.addr[0] = (u8)((row & 0x000000ff) >> 0);
	cmd.addr[1] = (u8)((row & 0x0000ff00) >> 8);
	cmd.addr[2] = (u8)((row & 0x00ff0000) >> 16);

	return spinand_cmd(spi_nand, &cmd);
}

/*
 * spinand_read_from_cache- send command 0x03 to read out the data from the
 * cache register(2112 bytes max)
 * Description:
 *   The read can specify 1 to 2112 bytes of data read at the corresponding
 *   locations.
 *   No tRd delay.
 */
static int spinand_read_from_cache(struct spi_device *spi_nand, u32 page_id, u32 byte_id, u32 len, u8 *rbuf)
{
	int ret = 0;
	u32 col_addr = byte_id;
	struct spinand_cmd cmd;
	u32 rx_bytes = 0;
	int trans_bytes = len;
	u8 r_cmd = CMD_READ_RDM;
	u8 set_bDFS = 0;

	if (spi_nand->mode & SPI_RX_QUAD) {
		r_cmd = CMD_READ_QRDM;
		set_bDFS = 1;
	} else if (spi_nand->mode & SPI_RX_DUAL) {
		r_cmd = CMD_READ_DRDM;
	}

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	while (trans_bytes > 0) {
		rx_bytes = (trans_bytes > 512) ? 512 : trans_bytes;
		cmd.cmd = r_cmd;
		cmd.n_addr = 2; //NADDR_RAED_QRDM
		cmd.addr[0] = (u8)((col_addr & 0x00ff) >> 0);
		cmd.addr[1] = (u8)((col_addr & 0xff00) >> 8);
		cmd.n_dummy = 1; //NDUMMY_READ_QRDM
		cmd.n_rx = rx_bytes;
		cmd.rx_buf = rbuf; //DRAM address
		cmd.bDFS_32 = set_bDFS;

		ret = qspinand_cmd(spi_nand, &cmd);
		if (ret) {
			printk("fail to send qspi cmd\n");
		}

		col_addr = col_addr + rx_bytes;
		rbuf = rbuf + rx_bytes;
		trans_bytes = trans_bytes - rx_bytes;
	}

	return ret;
}

/*
 * spinand_read_page-to read a page with:
 * @page_id: the physical page number
 * @offset:  the location from 0 to 2111
 * @len:     number of bytes to read
 * @rbuf:    read buffer to hold @len bytes
 *
 * Description:
 *   The read includes two commands to the Nand: 0x13 and 0x03 commands
 *   Poll to read status to wait for tRD time.
 */
static int spinand_read_page(struct spi_device *spi_nand, u32 page_id, u32 offset, u32 len, u8 *rbuf)
{
	int ret;
	u8 status = 0;

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	if (enable_read_hw_ecc) {
		//if (spinand_enable_ecc(spi_nand) < 0)
		if (0)
			dev_err(&spi_nand->dev, "enable HW ECC failed!");
	}
#endif
	/* Read one page data from flash main array to data buffer */
	ret = spinand_read_page_to_cache(spi_nand, page_id);
	if (ret < 0) {
		return ret;
	}

	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "WAIT timedout!!!\n");

	while (1) {
		ret = spinand_read_status(spi_nand, &status);
		if (ret < 0) {
			dev_err(&spi_nand->dev, "err %d read status register\n", ret);
			return ret;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_ECC_MASK) == STATUS_ECC_ERROR) {
				dev_err(&spi_nand->dev, "ecc error, page=%d\n", page_id);
				//Don't return here. This function is called to read OOB
				//Finish the reading these mtd layer can get correct OOB info
				//return 0;
			}
			break;
		}
	}

	ret = spinand_read_from_cache(spi_nand, page_id, offset, len, rbuf);
	if (ret < 0) {
		printk("read from cache failed!!\n");
		return ret;
	}

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	if (enable_read_hw_ecc) {
		//ret = spinand_disable_ecc(spi_nand);
		ret = 1;
		if (ret < 0) {
			dev_err(&spi_nand->dev, "disable ecc failed!!\n");
			return ret;
		}
		enable_read_hw_ecc = 0;
	}
#endif

	return ret;
}

static int spinand_program_data_to_cache(struct spi_device *spi_nand, u32 page_id, u32 byte_id, u32 len, u8 *wbuf)
{
	int ret = 0;
	u8 bIsfisrt = 1;
	u32 column = byte_id;
	u32 tx_bytes = 0;
	int trans_bytes = len;
	struct spinand_cmd cmd;
	u8 w_cmd_clr = 0x02, w_cmd = 0x84;
	u8 set_bDFS = 0;

	if (spi_nand->mode & SPI_TX_QUAD) {
		w_cmd_clr = 0x32;
		w_cmd = 0x34;
		set_bDFS = 1;
	}

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	if (trans_bytes % 4 != 0)
		trans_bytes += (4 - (trans_bytes % 4));

	while (trans_bytes > 0) {
		tx_bytes = (trans_bytes > 256) ? 256 : trans_bytes;

		cmd.cmd = bIsfisrt ? w_cmd_clr : w_cmd;
		cmd.n_addr = 2;
		cmd.addr[0] = (u8)(column & 0x00ff);
		cmd.addr[1] = (u8)((column & 0xff00) >> 8);
		cmd.n_tx = tx_bytes;
		if (byte_id == 2048)
			cmd.tx_buf = wbuf + column;
		else
			cmd.tx_buf = wbuf;
		cmd.bDFS_32 = set_bDFS;
		ret = qspinand_cmd(spi_nand, &cmd);
		if (ret)
			return ret;

		column = column + tx_bytes;
		wbuf = wbuf + tx_bytes;
		trans_bytes = trans_bytes - tx_bytes;
		bIsfisrt = 0;
	}

	return 0;
}

/**
 * spinand_program_execute--to write a page from cache to the Nand array with
 * @page_id: the physical page location to write the page.
 *
 * Description:
 *   The write command used here is 0x10--indicating the cache is writing to
 *   the Nand array.
 *   Need to wait for tPROG time to finish the transaction.
 */
static int spinand_program_execute(struct spi_device *spi_nand, u32 page_id)
{
	u32 row;
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	row = page_id;
	cmd.cmd = CMD_PROG_PAGE_EXC;
	cmd.n_addr = 3;
	cmd.addr[0] = (u8)((row & 0x000000ff) >> 0);
	cmd.addr[1] = (u8)((row & 0x0000ff00) >> 8);
	cmd.addr[2] = (u8)((row & 0x00ff0000) >> 16);

	return spinand_cmd(spi_nand, &cmd);
}

/**
 * spinand_program_page--to write a page with:
 * @page_id: the physical page location to write the page.
 * @offset:  the location from the cache starting from 0 to 2111
 * @len:     the number of bytes to write
 * @wbuf:    the buffer to hold the number of bytes
 *
 * Description:
 *   The commands used here are 0x06, 0x84, and 0x10--indicating that
 *   the write enable is first sent, the write cache command, and the
 *   write execute command.
 *   Poll to wait for the tPROG time to finish the transaction.
 */
static int spinand_program_page(struct spi_device *spi_nand, u32 page_id, u32 offset, u32 len, u8 *buf)
{
	int retval;
	u8 status = 0;
	u8 *wbuf;

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	unsigned int i, j;

	enable_read_hw_ecc = 0;
	wbuf = devm_kzalloc(&spi_nand->dev, CACHE_BUF, GFP_KERNEL);
	spinand_read_page(spi_nand, page_id, 0, CACHE_BUF, wbuf);

	for (i = offset, j = 0; j < len; i++, j++)
		wbuf[i] &= buf[j];

	if (enable_hw_ecc) {
		//retval = spinand_enable_ecc(spi_nand);
		retval = 1;
		if (retval < 0) {
			dev_err(&spi_nand->dev, "enable ecc failed!!\n");
			return retval;
		}
	}
#else
	wbuf = buf;
#endif

	//0x06
	retval = spinand_write_enable(spi_nand);
	if (retval < 0) {
		dev_err(&spi_nand->dev, "write enable failed!!\n");
		return retval;
	}

	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "wait timedout!!!\n");

	//0x02/0x82, 0x32/0x34
	retval = spinand_program_data_to_cache(spi_nand, page_id, offset, len, wbuf);
	if (retval < 0)
		return retval;

	//0x10
	retval = spinand_program_execute(spi_nand, page_id);
	if (retval < 0)
		return retval;

	while (1) {
		retval = spinand_read_status(spi_nand, &status);
		if (retval < 0) {
			dev_err(&spi_nand->dev, "error %d reading status register\n", retval);
			return retval;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_P_FAIL_MASK) == STATUS_P_FAIL) {
				dev_err(&spi_nand->dev, "program error, page %d\n", page_id);
				return -1;
			}
			break;
		}
	}

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	if (enable_hw_ecc) {
		//retval = spinand_disable_ecc(spi_nand);
		retval = 1;
		if (retval < 0) {
			dev_err(&spi_nand->dev, "disable ecc failed!!\n");
			return retval;
		}
		enable_hw_ecc = 0;
	}
	devm_kfree(&spi_nand->dev, wbuf);
#endif
	return 0;
}

/**
 * spinand_erase_block_erase--to erase a page with:
 * @block_id: the physical block location to erase.
 *
 * Description:
 *   The command used here is 0xd8--indicating an erase command to erase
 *   one block--64 pages
 *   Need to wait for tERS.
 */
static int spinand_erase_block_erase(struct spi_device *spi_nand, u32 block_id)
{
	u32 row;
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	row = block_id;
	cmd.cmd = CMD_ERASE_BLK;
	cmd.n_addr = 3;
	cmd.addr[0] = (u8)((row & 0x000000ff) >> 0);
	cmd.addr[1] = (u8)((row & 0x0000ff00) >> 8);
	cmd.addr[2] = (u8)((row & 0x00ff0000) >> 16);

	return spinand_cmd(spi_nand, &cmd);
}

/**
 * spinand_erase_block--to erase a page with:
 * @block_id: the physical block location to erase.
 *
 * Description:
 *   The commands used here are 0x06 and 0xd8--indicating an erase
 *   command to erase one block--64 pages
 *   It will first to enable the write enable bit (0x06 command),
 *   and then send the 0xd8 erase command
 *   Poll to wait for the tERS time to complete the tranaction.
 */
static int spinand_erase_block(struct spi_device *spi_nand, u32 block_id)
{
	int retval;
	u8 status = 0;

	retval = spinand_write_enable(spi_nand);
	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "wait timedout!!!\n");

	retval = spinand_erase_block_erase(spi_nand, block_id);
	while (1) {
		retval = spinand_read_status(spi_nand, &status);
		if (retval < 0) {
			dev_err(&spi_nand->dev, "error %d reading status register\n", (int)retval);
			return retval;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_E_FAIL_MASK) == STATUS_E_FAIL) {
				dev_err(&spi_nand->dev, "erase error, block %d\n", block_id);
				return -1;
			}
			break;
		}
	}
	return 0;
}

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
static int spinand_write_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip, const uint8_t *buf, int oob_required)
{
	const uint8_t *p = buf;
	int eccsize = chip->ecc.size;
	int eccsteps = chip->ecc.steps;

	enable_hw_ecc = 1;
	chip->write_buf(mtd, p, eccsize * eccsteps);
	return 0;
}

static int spinand_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip, uint8_t *buf, int oob_required,
                                   int page)
{
	u8 retval, status;
	uint8_t *p = buf;
	int eccsize = chip->ecc.size;
	int eccsteps = chip->ecc.steps;
	struct spinand_info *info = (struct spinand_info *)chip->priv;

	enable_read_hw_ecc = 1;

	chip->read_buf(mtd, p, eccsize * eccsteps);
	if (oob_required)
		chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);

	while (1) {
		retval = spinand_read_status(info->spi, &status);
		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_ECC_MASK) == STATUS_ECC_ERROR) {
				pr_info("spinand: ECC error\n");
				mtd->ecc_stats.failed++;
			} else if ((status & STATUS_ECC_MASK) == STATUS_ECC_1BIT_CORRECTED)
				mtd->ecc_stats.corrected++;
			break;
		}
	}
	return 0;
}
#endif
static void spinand_select_chip(struct mtd_info *mtd, int dev)
{
	/*donothing*/
}
//NICK say: Need to check this function
static int spinand_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
	struct spinand_info *info = (struct spinand_info *)chip->priv;

	unsigned long timeo = jiffies;
	int retval, state = chip->state;
	u8 status;

	if (state == FL_ERASING)
		timeo += (HZ * 400) / 1000;
	else
		timeo += (HZ * 20) / 1000;

	while (time_before(jiffies, timeo)) {
		retval = spinand_read_status(info->spi, &status);
		if (retval < 0) {
			dev_err(&mtd->dev, "error %d reading status register\n", retval);
			return NAND_STATUS_FAIL;
		}
		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if (status & (STATUS_E_FAIL | STATUS_P_FAIL)) {
				return NAND_STATUS_FAIL;
			} else {
				return NAND_STATUS_READY;
			}
		}

		cond_resched();
	}
	return 0;
}

static uint8_t spinand_read_byte(struct mtd_info *mtd)
{
	struct spinand_state *state = mtd_to_state(mtd);
	u8 data;

	data = state->buf[state->buf_ptr];
	state->buf_ptr++;
	return data;
}

static void spinand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
	struct spinand_state *state = mtd_to_state(mtd);

	memcpy(state->buf + state->buf_ptr, buf, len);
	state->buf_ptr += len;
}

static void spinand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
	struct spinand_state *state = mtd_to_state(mtd);

	memcpy(buf, state->buf + state->buf_ptr, len);
	state->buf_ptr += len;
}

/*
 * spinand_reset- send RESET command "0xff" to the Nand device.
 */
static void spinand_reset(struct spi_device *spi_nand)
{
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	cmd.cmd = CMD_RESET;

	if (spinand_cmd(spi_nand, &cmd) < 0)
		pr_info("spinand reset failed!\n");

	/* elapse 1ms before issuing any other command */
	udelay(1000);

	if (wait_till_ready(spi_nand))
		dev_err(&spi_nand->dev, "wait timedout!\n");
}

static void spinand_cmdfunc(struct mtd_info *mtd, unsigned int command, int column, int page)
{
	struct nand_chip *chip = (struct nand_chip *)mtd->priv;
	struct spinand_info *info = (struct spinand_info *)chip->priv;
	struct spinand_state *state = (struct spinand_state *)info->priv;

	switch (command) {
		/* READ0 - read in first  0x800 bytes*/
	case NAND_CMD_READ1:
	case NAND_CMD_READ0:
		state->buf_ptr = 0;
		//	 printk("case READ0/1, page_num: %d, buf=%p \n", page, state->buf);
		spinand_read_page(info->spi, page, 0x0, 0x840, state->buf);
		break;
	/* READOOB reads only the OOB because no ECC is performed. */
	case NAND_CMD_READOOB:
		state->buf_ptr = 0;
		//	 printk("case READOOB\n");
		spinand_read_page(info->spi, page, 0x800, 0x40, state->buf);
		break;
	case NAND_CMD_RNDOUT:
		state->buf_ptr = column;
		break;
	case NAND_CMD_READID:
		state->buf_ptr = 0;
		spinand_read_id(info->spi, (u8 *)state->buf);
		break;
	case NAND_CMD_PARAM:
		state->buf_ptr = 0;
		break;
	/* ERASE1 stores the block and page address */
	case NAND_CMD_ERASE1:
		spinand_erase_block(info->spi, page);
		break;
	/* ERASE2 uses the block and page address from ERASE1 */
	case NAND_CMD_ERASE2:
		break;
	/* SEQIN sets up the addr buffer and all registers except the length */
	case NAND_CMD_SEQIN:
		state->col = column;
		state->row = page;
		state->buf_ptr = 0;
		break;
	/* PAGEPROG reuses all of the setup from SEQIN and adds the length */
	case NAND_CMD_PAGEPROG:
		spinand_program_page(info->spi, state->row, state->col, state->buf_ptr, state->buf);
		break;
	case NAND_CMD_STATUS:
		spinand_get_otp(info->spi, state->buf);
		if (!(state->buf[0] & 0x80))
			state->buf[0] = 0x80;
		state->buf_ptr = 0;
		break;
	/* RESET command */
	case NAND_CMD_RESET:
		if (wait_till_ready(info->spi))
			dev_err(&info->spi->dev, "WAIT timedout!!!\n");
		/* a minimum of 250us must elapse before issuing RESET cmd*/
		udelay(250);
		spinand_reset(info->spi);
		break;
	default:
		dev_err(&mtd->dev, "Unknown CMD: 0x%x\n", command);
		break;
	}
}

/**
 * spinand_lock_block- send write register 0x1f command to the Nand device
 *
 * Description:
 *    After power up, all the Nand blocks are locked.  This function allows
 *    one to unlock the blocks, and so it can be written or erased.
 */
static int spinand_lock_block(struct spi_device *spi_nand, u8 lock)
{
	int ret;
	struct spinand_cmd cmd;

	memset(&cmd, 0, sizeof(struct spinand_cmd));

	cmd.cmd = CMD_WRITE_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_BLOCK_LOCK;
	cmd.n_tx = 1;
	cmd.tx_buf = &lock;

	ret = spinand_cmd(spi_nand, &cmd);
	if (ret < 0)
		dev_err(&spi_nand->dev, "error %d lock block\n", ret);

	return ret;
}

/*
 * spinand_probe - [spinand Interface]
 * @spi_nand: registered device driver.
 *
 * Description:
 *   To set up the device driver parameters to make the device available.
 */
static int spinand_probe(struct spi_device *spi_nand)
{
	struct mtd_info *mtd;
	struct nand_chip *chip;
	struct spinand_info *info;
	struct spinand_state *state;
	struct mtd_part_parser_data ppdata;
	struct nand_ecc_info *ecc_info;
	u8 flash_id[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }, otp = 0x19;
	int i = 0, id_len = 0;

	info = devm_kzalloc(&spi_nand->dev, sizeof(struct spinand_info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	info->spi = spi_nand;

	state = devm_kzalloc(&spi_nand->dev, sizeof(struct spinand_state), GFP_KERNEL);
	if (!state)
		return -ENOMEM;

	info->priv = state;
	state->buf_ptr = 0;
	state->buf = devm_kzalloc(&spi_nand->dev, BUFSIZE, GFP_KERNEL);
	if (!state->buf)
		return -ENOMEM;

	chip = devm_kzalloc(&spi_nand->dev, sizeof(struct nand_chip), GFP_KERNEL);
	if (!chip)
		return -ENOMEM;

	spinand_lock_block(info->spi, BL_ALL_UNLOCKED);
	spinand_read_id(info->spi, flash_id);
	spinand_set_otp(info->spi, &otp);
	ecc_info = get_ecc_info(flash_id[0], flash_id[1], flash_id[2]);

	if (!ecc_info)
		return -ENOMEM;

	id_len = spinand_id_len(flash_id, 8);
	for (i = 0; i < id_len; i++) {
		printk("%X ", flash_id[i]);
	}
	printk("%X\n", otp);

#ifdef CONFIG_MTD_SPINAND_ONDIEECC
	chip->ecc.mode = NAND_ECC_HW;
	chip->ecc.size = 0x200;
	chip->ecc.steps = ecc_info->ecc_steps;
	chip->ecc.bytes = ecc_info->ecc_bytes;
	chip->ecc.layout = ecc_info->ecc_layout;
	chip->ecc.strength = 1;
	chip->ecc.total = chip->ecc.steps * chip->ecc.bytes;
	chip->ecc.read_page = spinand_read_page_hwecc;
	chip->ecc.write_page = spinand_write_page_hwecc;
#else
	chip->ecc.mode = NAND_ECC_SOFT;
	//if (spinand_disable_ecc(spi_nand) < 0)
	if (0)
		pr_info("%s: disable ecc failed!\n", __func__);
#endif
	chip->priv = info;
	chip->read_buf = spinand_read_buf;
	chip->write_buf = spinand_write_buf;
	chip->read_byte = spinand_read_byte;
	chip->cmdfunc = spinand_cmdfunc;
	chip->waitfunc = spinand_wait;
	chip->options |= (NAND_CACHEPRG | NAND_NO_SUBPAGE_WRITE);
	chip->select_chip = spinand_select_chip;

	mtd = devm_kzalloc(&spi_nand->dev, sizeof(struct mtd_info), GFP_KERNEL);
	if (!mtd)
		return -ENOMEM;

	dev_set_drvdata(&spi_nand->dev, mtd);

	mtd->priv = chip;
	mtd->name = "nand_flash";
	mtd->owner = THIS_MODULE;
	mtd->oobsize = ecc_info->oobsize;

	if (nand_scan(mtd, 1))
		return -ENXIO;

	ppdata.of_node = spi_nand->dev.of_node;

	chip_ver = get_chip_ver();

	return mtd_device_parse_register(mtd, NULL, &ppdata, NULL, 0);
}

/*
 * spinand_remove: Remove the device driver
 * @spi: the spi device.
 *
 * Description:
 *   To remove the device driver parameters and free up allocated memories.
 */
static int spinand_remove(struct spi_device *spi)
{
	mtd_device_unregister(dev_get_drvdata(&spi->dev));
	return 0;
}

static const struct of_device_id spinand_dt[] = {
	{ .compatible = "augentix,spinand", },
	{}
};
/*
 * Device name structure description
 */
static struct spi_driver spinand_driver = {
	.driver = {
		.name		= "hc18xx-spinand",
		.bus		= &spi_bus_type,
		.owner		= THIS_MODULE,
		.of_match_table	= spinand_dt,
	},
	.probe		= spinand_probe,
	.remove		= spinand_remove,
};

module_spi_driver(spinand_driver);

MODULE_DESCRIPTION("SPI NAND driver for Augentix");
MODULE_AUTHOR("Nick Lin <nick.lin@augentix.com>");
MODULE_LICENSE("GPL v2");
