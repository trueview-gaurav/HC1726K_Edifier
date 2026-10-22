/*
 * I2C bus driver for Augentix I2C controller
 *
 * Copyright (C) 2015 - 2020 Augentix Inc.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any
 * later version.
 */

#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/clk.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/semaphore.h>
#include <linux/reset.h>

/* Region offsets for I2C controller. */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define AUGENTIX_I2C_TRIG_OFFSET 0x00 /* Trigger I2C transfer, W1P */
#define AUGENTIX_I2C_ICLR_OFFSET 0x04 /* Clear irq state, W1P */
#define AUGENTIX_I2C_SR_OFFSET 0x08 /* Status register, RO */
#define AUGENTIX_I2C_IER_OFFSET 0x0C /* Enable irq, RW */
#define AUGENTIX_I2C_TMO_OFFSET 0x10 /* Timeout number, RW */
#define AUGENTIX_I2C_TMO2_OFFSET 0x14 /* Timeout max number, RW */
#define AUGENTIX_I2C_TMO_ABORT_OFFSET 0x18 /* Timeout abort, RW */
#define AUGENTIX_I2C_TRANS_SR_OFFSET 0x1C /* Transaction status, RO */
#define AUGENTIX_I2C_DEGLITCH_OFFSET 0x20 /* Clock deglitch, RW */
#define AUGENTIX_I2C_CLK_OFFSET 0x24 /* Clock delay and rate, RW */
#define AUGENTIX_I2C_AUTOREAD_OFFSET 0x28 /* Control register, RW */
#define AUGENTIX_I2C_ADDR_OFFSET 0x2C /* I2C address register, RW */
#define AUGENTIX_I2C_BYTES_OFFSET 0x30 /* Read or write data length, RW */
#define AUGENTIX_I2C_WR0_OFFSET 0x34 /* Register for write data, RW */
#define AUGENTIX_I2C_WR1_OFFSET 0x38 /* Register for write data, RW */
#define AUGENTIX_I2C_WR2_OFFSET 0x3C /* Register for write data, RW */
#define AUGENTIX_I2C_WR3_OFFSET 0x40 /* Register for write data, RW */
#define AUGENTIX_I2C_WR4_OFFSET 0x44 /* Register for write data, RW */
#define AUGENTIX_I2C_WR5_OFFSET 0x48 /* Register for write data, RW */
#define AUGENTIX_I2C_WR6_OFFSET 0x4C /* Register for write data, RW */
#define AUGENTIX_I2C_WR7_OFFSET 0x50 /* Register for write data, RW */
#define AUGENTIX_I2C_RD0_OFFSET 0x54 /* Register for read data, RO */
#define AUGENTIX_I2C_RD1_OFFSET 0x58 /* Register for read data, RO */
#define AUGENTIX_I2C_RD2_OFFSET 0x5C /* Register for read data, RO */
#define AUGENTIX_I2C_RD3_OFFSET 0x60 /* Register for read data, RO */
#define AUGENTIX_I2C_RD4_OFFSET 0x64 /* Register for read data, RO */
#define AUGENTIX_I2C_RD5_OFFSET 0x68 /* Register for read data, RO */
#define AUGENTIX_I2C_RD6_OFFSET 0x6C /* Register for read data, RO */
#define AUGENTIX_I2C_RD7_OFFSET 0x70 /* Register for read data, RO */
#define AUGENTIX_I2C_DEBUG_MONITOR_OFFSET 0x74 /* Debug monitor selection, RW */
#define AUGENTIX_I2C_RESERVED_OFFSET 0x78 /* Reserved, RW */

#else
#define AUGENTIX_I2C_TRIG_OFFSET 0x00 /* Trigger I2C transfer, RO */
#define AUGENTIX_I2C_ICLR_OFFSET 0x04 /* Clear irq state, RO */
#define AUGENTIX_I2C_ISR_OFFSET 0x08 /* Irq status, RO */
#define AUGENTIX_I2C_IER_OFFSET 0x0C /* Enable irq, RW */
#define AUGENTIX_I2C_SR_OFFSET 0x10 /* Status register, RO */
#define AUGENTIX_I2C_TRANS_SR_OFFSET 0x14 /* Transaction status, RO */
#define AUGENTIX_I2C_CLK_OFFSET 0x18 /* Clock cycle, RW */
#define AUGENTIX_I2C_AUTOREAD_OFFSET 0x1C /* Control register, RW */
#define AUGENTIX_I2C_ADDR_OFFSET 0x20 /* I2C address register, RW */
#define AUGENTIX_I2C_BYTES_OFFSET 0x24 /* Read or write data length, RW */
#define AUGENTIX_I2C_WR0_OFFSET 0x28 /* Register for write data, RW */
#define AUGENTIX_I2C_WR1_OFFSET 0x2C /* Register for write data, RW */
#define AUGENTIX_I2C_WR2_OFFSET 0x30 /* Register for write data, RW */
#define AUGENTIX_I2C_WR3_OFFSET 0x34 /* Register for write data, RW */
#define AUGENTIX_I2C_WR4_OFFSET 0x38 /* Register for write data, RW */
#define AUGENTIX_I2C_WR5_OFFSET 0x3C /* Register for write data, RW */
#define AUGENTIX_I2C_WR6_OFFSET 0x40 /* Register for write data, RW */
#define AUGENTIX_I2C_WR7_OFFSET 0x44 /* Register for write data, RW */
#define AUGENTIX_I2C_RD0_OFFSET 0x48 /* Register for read data, RO */
#define AUGENTIX_I2C_RD1_OFFSET 0x4C /* Register for read data, RO */
#endif //CONFIG_SAPPORO

/* Control register signal difinition */
#define AUGENTIX_I2C_TRIG_SET 0x01 /* Start transmit */
#define AUGENTIX_I2C_ISR_DONE 0x01 /* I2C interrupt*/
#define AUGENTIX_I2C_ADDR_WRITE 0x00 /* I2C write */
#define AUGENTIX_I2C_CLK_DEFAULT ((120 << 16) | 0x00) /* Frquency 100Khz */
#define AUGENTIX_I2C_AUTOREAD_ON 0x01 /* Enable autogenread */
#define AUGENTIX_I2C_AUTOREAD_OFF 0x00 /* Disable autogenread */

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define AUGENTIX_I2C_ICLR_SET 0x01111111 /* Clear irq status */
#define AUGENTIX_I2C_IER_DISABLE 0x01111111 /* Disable interrupt */
#define AUGENTIX_I2C_IER_ENABLE 0x01111110 /* Enable frame end interrupt */
#define AUGENTIX_I2C_SR_FRAME_END 0x1 /* Frame end */
#define AUGENTIX_I2C_SR_BUSY 0x02000000 /* Bus busy */
#define AUGENTIX_I2C_ADDR_READ BIT(12) /* I2C read */
#define AUGENTIX_I2C_SR_ERRADDR BIT(27) /* Error address */
#define AUGENTIX_I2C_SR_ERRDATA BIT(28) /* Error data */
#define AUGENTIX_I2C_SR_ERRPEC 0x0C000000 /* Error PEC */
#define AUGENTIX_I2C_RESTART_ON (1 << 8) /* Enable restart */
#define AUGENTIX_I2C_RESTART_OFF (0 << 8) /* Disable restart */
#else
#define AUGENTIX_I2C_ICLR_SET 0x01 /* Clear irq status */
#define AUGENTIX_I2C_IER_DISABLE 0x01 /* Disable interrupt */
#define AUGENTIX_I2C_IER_ENABLE 0x00 /* Enable interrupt */
#define AUGENTIX_I2C_SR_BUSY 0x01 /* Bus busy */
#define AUGENTIX_I2C_ADDR_READ BIT(8) /* I2C read */
#define AUGENTIX_I2C_SR_ERRADDR BIT(16) /* Error address */
#define AUGENTIX_I2C_SR_ERRDATA BIT(17) /* Error data */
#define AUGENTIX_I2C_RESTART_ON (1 << 16) /* Enable restart */
#define AUGENTIX_I2C_RESTART_OFF (0 << 16) /* Disable restart */
#endif

/* Define masks */
#define AUGENTIX_I2C_WRLEN_MASK 0xff
#define AUGENTIX_I2C_WRNUM_MASK 0xff00
#define AUGENTIX_I2C_RDLEN_MASK 0xff0000

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define AUGENTIX_I2C_CLK_MASK 0x3ff800
#else
#define AUGENTIX_I2C_CLK_MASK 0xff0000
#endif

/* Shift macros */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define AUGENTIX_I2C_DELAY_CYCLE_SHIFT 0x00
#else
#define AUGENTIX_I2C_DELAY_CYCLE_SHIFT 0x08
#endif
#define AUGENTIX_I2C_RDLEN_SHIFT 0x10

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define AUGENTIX_I2C_CLK_SHIFT 0x0B
#else
#define AUGENTIX_I2C_CLK_SHIFT 0x10
#endif

/* Software definition */
#define AUGENTIX_I2C_DEFAULT_DELAY_CYCLE 0x04
#define AUGENTIX_I2C_DEFAULT_RATE (100 * 1000)
#define AUGENTIX_I2C_MAX_RATE (400 * 1000)
#define AUGENTIX_I2C_MAX_WR_LEN 0x20

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define AUGENTIX_I2C_MAX_RD_LEN 0x20
#else
#define AUGENTIX_I2C_MAX_RD_LEN 0x08
#endif

#define AUGENTIX_I2C_TIMEOUT msecs_to_jiffies(1000)

/* Register read/write macro */
#define augentix_readreg(offset) readl_relaxed(id->membase + offset)
#define augentix_writereg(val, offset) writel_relaxed(val, id->membase + offset)

/* Driver name */
#define DRIVER_NAME "augentix_i2c"

/* Driver private data */
struct augentix_i2c {
	void __iomem *membase;
	struct i2c_adapter adap;
	struct i2c_msg *p_msg;
	u32 state_status;
	struct completion xfer_done;
	struct semaphore sem;
	int irq;
	struct clk *sclk;
	u32 sclk_rate;
	u32 i2c_rate;
	u32 delay_cycle;
#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
	struct reset_control *rst;
#endif
};

static int augentix_i2c_setclk(u32 rate, struct augentix_i2c *id)
{
	u32 sclk_rate = id->sclk_rate;
	u32 cycle = 0;
	/* calculate clock division */
	cycle = sclk_rate / (rate << 1) - 1;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	cycle -= 3; /* issue #86821 */
#endif
	/* write div to i2c */
	augentix_writereg((cycle << AUGENTIX_I2C_CLK_SHIFT) | (id->delay_cycle << AUGENTIX_I2C_DELAY_CYCLE_SHIFT),
	                  AUGENTIX_I2C_CLK_OFFSET);
	return 0;
}

static void augentix_i2c_reset(struct augentix_i2c *id)
{
	/* setting clock division */
	augentix_i2c_setclk(id->i2c_rate, id);
	/* clear irq bit */
	augentix_writereg(AUGENTIX_I2C_IER_DISABLE, AUGENTIX_I2C_IER_OFFSET);
	augentix_writereg(AUGENTIX_I2C_ICLR_SET, AUGENTIX_I2C_ICLR_OFFSET);
	/* diable autogenread */
	augentix_writereg(AUGENTIX_I2C_AUTOREAD_OFF, AUGENTIX_I2C_AUTOREAD_OFFSET);
	/* set slave addr to 0 */
	augentix_writereg(0x00, AUGENTIX_I2C_ADDR_OFFSET);
	/* default configuration */
	augentix_writereg(0x20002, AUGENTIX_I2C_BYTES_OFFSET);
	augentix_writereg(0x00, AUGENTIX_I2C_WR0_OFFSET);
	augentix_writereg(0x00, AUGENTIX_I2C_WR1_OFFSET);
	augentix_writereg(0x00, AUGENTIX_I2C_WR2_OFFSET);
	augentix_writereg(0x00, AUGENTIX_I2C_WR3_OFFSET);
	augentix_writereg(0x00, AUGENTIX_I2C_WR4_OFFSET);
	augentix_writereg(0x00, AUGENTIX_I2C_WR5_OFFSET);
	augentix_writereg(0x00, AUGENTIX_I2C_WR6_OFFSET);
	augentix_writereg(0x00, AUGENTIX_I2C_WR7_OFFSET);
	/* interrupt enable */
	augentix_writereg(AUGENTIX_I2C_IER_ENABLE, AUGENTIX_I2C_IER_OFFSET);
}

static irqreturn_t augentix_i2c_isr(int irq, void *dev_id)
{
	struct augentix_i2c *id = (struct augentix_i2c *)dev_id;
	u32 reg;

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	reg = augentix_readreg(AUGENTIX_I2C_SR_OFFSET);
	if ((reg & AUGENTIX_I2C_SR_FRAME_END) != AUGENTIX_I2C_ISR_DONE) {
#else
	reg = augentix_readreg(AUGENTIX_I2C_ISR_OFFSET);
	if (reg != AUGENTIX_I2C_ISR_DONE) {
#endif
		return IRQ_NONE;
	}

	/* clear interrupt status */
	augentix_writereg(AUGENTIX_I2C_ICLR_SET, AUGENTIX_I2C_ICLR_OFFSET);
	/* read state status */
	id->state_status = augentix_readreg(AUGENTIX_I2C_SR_OFFSET);
	/* print isr info */
	pr_debug("augentix_i2c_isr: isr status %x, state status %x\n", reg, id->state_status);
	/* wake up xfer_done */
	complete(&id->xfer_done);
	return IRQ_HANDLED;
}

static int augentix_i2c_msend(struct augentix_i2c *id)
{
	struct i2c_msg *msg = id->p_msg;
	int count = 0;
	int ret = 0;
	int it = 0;
	u32 reg = 0;
	u32 buf = 0;
	u8 *data_ptr = msg->buf;
	u8 len = msg->len;

	if (msg->len > AUGENTIX_I2C_MAX_WR_LEN) {
		return -EINVAL;
	}

	/* set addr and read flags */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	augentix_writereg((msg->addr & 0x7f), AUGENTIX_I2C_ADDR_OFFSET);
	augentix_writereg(AUGENTIX_I2C_ADDR_WRITE, AUGENTIX_I2C_AUTOREAD_OFFSET);
#else
	augentix_writereg(AUGENTIX_I2C_ADDR_WRITE | (msg->addr & 0x7f), AUGENTIX_I2C_ADDR_OFFSET);
#endif

	if (msg->flags & I2C_M_NOSTART) {
		--len;
		reg = ((len / msg->buf[0] - 1) << 8) | (msg->buf[0] - 1);
		++data_ptr;
	} else {
		reg = len - 1;
	}

	augentix_writereg(reg, AUGENTIX_I2C_BYTES_OFFSET);

	/* fill data to register */
	while (it < len) {
		reg = 0;

		for (count = it; count < len; ++count) {
			buf = *(data_ptr + count);
			reg += (buf << ((count - it) << 3));

			if ((count - it) >= 3) {
				break;
			}
		}

		pr_debug("wd_data = %x\n", reg);
		augentix_writereg(reg, AUGENTIX_I2C_WR0_OFFSET + it);
		it += 4;
	}

	/* clear interrupt status and trigger once */
	augentix_writereg(AUGENTIX_I2C_TRIG_SET, AUGENTIX_I2C_TRIG_OFFSET);

	/* wait for work completion */
	ret = wait_for_completion_timeout(&id->xfer_done, id->adap.timeout);

	if (ret == 0) {
		augentix_i2c_reset(id);
		dev_err(id->adap.dev.parent, "timeout waiting on completion\n");
		return -ETIMEDOUT;
	}

	return 0;
}

static int augentix_i2c_mrecv(struct augentix_i2c *id)
{
	struct i2c_msg *msg = id->p_msg;
	int count = 0;
	int ret = 0;
	int len = 0;
	int it = 0;
	u32 reg = 0;

	if (msg->len > AUGENTIX_I2C_MAX_RD_LEN) {
		return -EINVAL;
	}

	/* set addr and read flags */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	augentix_writereg((msg->addr & 0x7f), AUGENTIX_I2C_ADDR_OFFSET);
	augentix_writereg(AUGENTIX_I2C_ADDR_READ, AUGENTIX_I2C_AUTOREAD_OFFSET);
#else
	augentix_writereg(AUGENTIX_I2C_ADDR_READ | (msg->addr & 0x7f), AUGENTIX_I2C_ADDR_OFFSET);
#endif

	/* set read length */
	augentix_writereg((msg->len - 1) << AUGENTIX_I2C_RDLEN_SHIFT, AUGENTIX_I2C_BYTES_OFFSET);

	/* clear interrupt status and trigger once */
	augentix_writereg(AUGENTIX_I2C_TRIG_SET, AUGENTIX_I2C_TRIG_OFFSET);

	/* wait for work completion */
	ret = wait_for_completion_timeout(&id->xfer_done, id->adap.timeout);

	if (ret == 0) {
		augentix_i2c_reset(id);
		dev_err(id->adap.dev.parent, "timeout waiting on completion\n");
		return -ETIMEDOUT;
	}

	/* error */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	if (id->state_status & AUGENTIX_I2C_SR_ERRADDR || id->state_status & AUGENTIX_I2C_SR_ERRDATA ||
	    id->state_status & AUGENTIX_I2C_SR_ERRPEC) {
		ret = -ENXIO;
		return 0;
	}
#else
	if (id->state_status) {
		return 0;
	}
#endif

	/* fill data to register */
	len = msg->len;

	while (len > 0) {
		reg = augentix_readreg(AUGENTIX_I2C_RD0_OFFSET + (it << 2));
		pr_debug("rd_data = %x\n", reg);

		for (count = 0; count < len; ++count) {
			*(msg->buf + count + (it << 2)) = reg & 0xff;
			reg = reg >> 8;

			if (count >= 3) {
				break;
			}
		}

		len -= 4;
		++it;
	}

	return 0;
}

static int augentix_i2c_process_msg(struct augentix_i2c *id, struct i2c_msg *msg)
{
	int ret = 0;
	id->p_msg = msg;
	id->state_status = 0;
	/* init waitqueue tasks */
	reinit_completion(&id->xfer_done);

	/* wrong input messages */
	if (msg->flags & I2C_M_TEN) {
		return -EINVAL;
	}

	/* read or write i2c */
	if (msg->flags & I2C_M_RD) {
		ret = augentix_i2c_mrecv(id);
	} else {
		ret = augentix_i2c_msend(id);
	}

	return ret;
}

static int augentix_i2c_master_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
	int ret, count;
	struct augentix_i2c *id = adap->algo_data;

	pr_debug("augentix_i2c_master_xfer, num msgs %d addr %x len %x flags %x.\n", num, msgs->addr, msgs->len,
	         msgs->flags);

	/* check if bus is not busy */
	if (down_interruptible(&id->sem)) {
		return -ERESTARTSYS;
	}

	if (augentix_readreg(AUGENTIX_I2C_SR_OFFSET) & AUGENTIX_I2C_SR_BUSY) {
		up(&id->sem);
		return -EAGAIN;
	}

	/* Set READ_MODE & RESTART_MODE for default general */
	augentix_writereg(AUGENTIX_I2C_AUTOREAD_OFF | AUGENTIX_I2C_RESTART_OFF, AUGENTIX_I2C_AUTOREAD_OFFSET);

	for (count = 0; count < num; ++count, ++msgs) {
		/* if timeout or invalid input */
		ret = augentix_i2c_process_msg(id, msgs);

		if (ret) {
			goto error;
		}

		/* check error status */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		if (id->state_status & AUGENTIX_I2C_SR_ERRADDR || id->state_status & AUGENTIX_I2C_SR_ERRDATA ||
		    id->state_status & AUGENTIX_I2C_SR_ERRPEC) {
			ret = -ENXIO;
			goto error;
		}
#else
		if (id->state_status) {
			if (id->state_status & AUGENTIX_I2C_SR_ERRADDR) {
				ret = -ENXIO;
				goto error;
			}
			ret = -EIO;
			goto error;
		}
#endif
	}

	/* release lock */
	up(&id->sem);
	return num;
error:
	up(&id->sem);
	return ret;
}

/*	
 * execute SMBus protocol operations
 * Parameters
 * 
 * adapter:		Handle to I2C bus
 * addr:		Address of SMBus slave on that bus
 * flags:		I2C_CLIENT_* flags (usually zero or I2C_CLIENT_PEC)
 * read_write:		I2C_SMBUS_READ or I2C_SMBUS_WRITE
 * command:		Byte interpreted by slave, for protocols which use such bytes
 * size:		SMBus protocol operation to execute, such as I2C_SMBUS_PROC_CALL
 * data:		Data to be read or written
 * 
 * Description
 * This executes an SMBus protocol operation, and returns a negative errno code else zero on success.
 */
static s32 augentix_i2c_smbus_xfer(struct i2c_adapter *adap, u16 addr, unsigned short flags, char read_write,
                                   u8 command, int size, union i2c_smbus_data *data)
{
	struct augentix_i2c *id = adap->algo_data;
	int write_len = 0, read_len = 0;
	int it = 0;
	int ret = 0;
	u32 reg = 0;
	int len = 0;
	int count = 0;
	u32 buf = 0;
	u8 tmp_blk[32];
	int blk_cnt = 0;

	switch (size) {
	case I2C_SMBUS_BYTE_DATA:
		if (read_write == I2C_SMBUS_READ) {
			write_len = 1;
			read_len = 1;
		} else {
			write_len = 2;
			read_len = 1;
		}
		break;
	case I2C_SMBUS_I2C_BLOCK_DATA:
		if (read_write == I2C_SMBUS_READ) {
			write_len = 1;
			read_len = 8; // limitation
		} else {
			write_len = 8; // align size with RDATA WIDTH
			read_len = 1;
		}
		break;
	default:
		return -EOPNOTSUPP;
	}

	/* check if bus is not busy */
	if (down_interruptible(&id->sem)) {
		return -ERESTARTSYS;
	}

	if (augentix_readreg(AUGENTIX_I2C_SR_OFFSET) & AUGENTIX_I2C_SR_BUSY) {
		up(&id->sem);
		return -EAGAIN;
	}

	reinit_completion(&id->xfer_done);

	/* Set READ_MODE & RESTART_MODE for SMBUS READ*/
	if (read_write == I2C_SMBUS_READ) {
		augentix_writereg(AUGENTIX_I2C_AUTOREAD_ON | AUGENTIX_I2C_RESTART_ON, AUGENTIX_I2C_AUTOREAD_OFFSET);
	} else {
		augentix_writereg(AUGENTIX_I2C_AUTOREAD_OFF | AUGENTIX_I2C_RESTART_OFF, AUGENTIX_I2C_AUTOREAD_OFFSET);
	}

	/* Set slave_addr and RW flags */
	augentix_writereg((read_write << 8) | (addr & 0x7f),
	                  AUGENTIX_I2C_ADDR_OFFSET); //determine RW status by read_write

	/* set RW length */
	augentix_writereg((read_len - 1) << AUGENTIX_I2C_RDLEN_SHIFT | (write_len - 1), AUGENTIX_I2C_BYTES_OFFSET);

	/* Set internal address from command, maybe need to combine it */
	if (read_write == I2C_SMBUS_READ) {
		augentix_writereg(command, AUGENTIX_I2C_WR0_OFFSET); // command only take u8 here
	} else {
		tmp_blk[0] = command;
		for (blk_cnt = 0; blk_cnt < 8; blk_cnt++) {
			tmp_blk[blk_cnt + 1] = data->block[blk_cnt];
		}

		/* fill data to register */
		while (it < write_len) {
			reg = 0;

			for (count = it; count < write_len; ++count) {
				buf = tmp_blk[count];
				reg += (buf << ((count - it) << 3));

				if ((count - it) >= 3) {
					break;
				}
			}

			augentix_writereg(reg, AUGENTIX_I2C_WR0_OFFSET + it);
			it += 4;
		}
	}


	/* clear interrupt status and trigger once */
	augentix_writereg(AUGENTIX_I2C_TRIG_SET, AUGENTIX_I2C_TRIG_OFFSET);

	/* wait for work completion */
	ret = wait_for_completion_timeout(&id->xfer_done, id->adap.timeout);

	if (ret == 0) {
		augentix_i2c_reset(id);
		dev_err(id->adap.dev.parent, "timeout waiting on completion\n");
		return -ETIMEDOUT;
	}

	/* error */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	if (id->state_status & AUGENTIX_I2C_SR_ERRADDR || id->state_status & AUGENTIX_I2C_SR_ERRDATA ||
	    id->state_status & AUGENTIX_I2C_SR_ERRPEC) {
#else
	if (id->state_status) {
#endif
		return 0;
	}

	if (read_write == I2C_SMBUS_READ) {
		/* fill data to register */
		len = read_len;

		while (len > 0) {
			reg = augentix_readreg(AUGENTIX_I2C_RD0_OFFSET + (it << 2));

			for (count = 0; count < len; ++count) {
				data->block[count + (it<<2)] = reg & 0xff;
				reg = reg >> 8;

				if (count >= 3) {
					break;
				}
			}

			len -= 4;
			++it;
		}
	}

	/* release lock */
	up(&id->sem);
	return 0;
}

static u32 augentix_i2c_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

static const struct i2c_algorithm augentix_i2c_algo = {
	.master_xfer = augentix_i2c_master_xfer,
	//.smbus_xfer = augentix_i2c_smbus_xfer,
	.functionality = augentix_i2c_func,
};

static int augentix_i2c_probe(struct platform_device *pdev)
{
	struct resource *r_mem;
	struct augentix_i2c *id;
	int ret;
#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
	const char *rst_names;
#endif

	/* allocate memory */
	id = devm_kzalloc(&pdev->dev, sizeof(struct augentix_i2c), GFP_KERNEL);

	if (id == NULL) {
		return -ENOMEM;
	}

	/* set platform data */
	platform_set_drvdata(pdev, id);
	/* get memory region */
	r_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	id->membase = devm_ioremap_resource(&pdev->dev, r_mem);

	if (IS_ERR(id->membase)) {
		return PTR_ERR(id->membase);
	}

	/* init semaphor */
	sema_init(&id->sem, 1);

	/*
	 * devm_clk_get(dev, NULL) is same as of_clk_get(np, 0).
	 * If intending to use plural clock source, use of_clk_get(np, index).
	 * Remember not to use clock-names to reduce code size and boot time
	 */
	id->sclk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(id->sclk)) {
		dev_err(&pdev->dev, "input clock not found.\n");
		return PTR_ERR(id->sclk);
	}

	id->sclk_rate = clk_get_rate(id->sclk);

	/* prepare clock (empty function - fixed clock) */
	ret = clk_prepare_enable(id->sclk);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable clock.\n");
		return ret;
	}

	/* read irq from device tree */
	id->irq = platform_get_irq(pdev, 0);
	ret = devm_request_irq(&pdev->dev, id->irq, augentix_i2c_isr, IRQF_SHARED | IRQF_NO_SUSPEND, pdev->name, id);

	if (ret < 0) {
		dev_err(&pdev->dev, "request irq fail %d\n", id->irq);
		return -EINVAL;
	}

#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
	if (of_property_read_string(pdev->dev.of_node, "reset-names", &rst_names)) {
		dev_err(&pdev->dev, "request reset-names fail\n");
		return -EINVAL;
	}
	id->rst = devm_reset_control_get(&pdev->dev, rst_names);
#endif

	/* setting i2c_adapter structure definition */
	id->adap.dev.of_node = pdev->dev.of_node;
	id->adap.algo = &augentix_i2c_algo;
	id->adap.timeout = AUGENTIX_I2C_TIMEOUT;
	id->adap.retries = 3;
	id->adap.algo_data = id;
	id->adap.dev.parent = &pdev->dev;
	init_completion(&id->xfer_done);
	snprintf(id->adap.name, sizeof(id->adap.name), "Augentix I2C at %08lx", (unsigned long)r_mem->start);

	/* set clock divsion */
	if (of_property_read_u32(pdev->dev.of_node, "clock-frequency", &id->i2c_rate)) {
		id->i2c_rate = AUGENTIX_I2C_DEFAULT_RATE;
	}

	/* read clock delay */
	if (of_property_read_u32(pdev->dev.of_node, "clock-delay", &id->delay_cycle)) {
		id->delay_cycle = AUGENTIX_I2C_DEFAULT_DELAY_CYCLE;
	}

#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
	/* software reset */
	reset_control_reset(id->rst);
#endif

	/* register reset */
	augentix_i2c_reset(id);

	/* register adapter */
	ret = i2c_add_adapter(&id->adap);

	if (ret < 0) {
		dev_err(&pdev->dev, "register adaptor failed: %d\n", ret);
		return ret;
	}

	pr_info("augentix-i2c: probing %s, <0x%x 0x%x>, irq %d.\n", pdev->name, r_mem->start, r_mem->end - r_mem->start,
	        id->irq);
	return 0;
}

static int augentix_i2c_remove(struct platform_device *pdev)
{
	struct augentix_i2c *id = platform_get_drvdata(pdev);
	i2c_del_adapter(&id->adap);
	platform_set_drvdata(pdev, NULL);
	/* unprepare close (empty function - fixed clock) */
	clk_disable_unprepare(id->sclk);
	pr_info("augentix-i2c: %s removed.\n", pdev->name);
	return 0;
}

static const struct of_device_id augentix_i2c_of_match[] = {
	{
	        .compatible = "augentix,i2c",
	},
	{},
};
MODULE_DEVICE_TABLE(of, augentix_i2c_of_match);

static struct platform_driver augentix_i2c_drv = {
	.driver =
	        {
	                .name = DRIVER_NAME,
	                .of_match_table = augentix_i2c_of_match,
	        },
	.probe = augentix_i2c_probe,
	.remove = augentix_i2c_remove,
};

module_platform_driver(augentix_i2c_drv);

MODULE_AUTHOR("Rowan Lin <rowan.lin@augentix.com");
MODULE_DESCRIPTION("Augentix I2C bus driver");
MODULE_LICENSE("GPL");
