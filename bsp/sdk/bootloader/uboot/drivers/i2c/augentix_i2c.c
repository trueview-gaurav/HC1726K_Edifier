/*
 * (C) Copyright 2021 Augentix 
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <i2c.h>
#include <asm/io.h>
#include "augentix_i2c.h"

static struct i2c_regs *i2c_get_base(struct i2c_adapter *adap)
{
	switch (adap->hwadapnr) {
#if CONFIG_SYS_I2C_BUS_MAX >= 2
	case 1:
		return (struct i2c_regs *)I2CM1_BASE;
#endif
	case 0:
		return (struct i2c_regs *)I2CM0_BASE;
	default:
		printf("Wrong I2C-adapter number %d\n", adap->hwadapnr);
	}

	return NULL;
}

static int wait_for_i2c_isr(struct i2c_adapter *adap)
{
	struct i2c_regs *i2c_base = i2c_get_base(adap);
	unsigned int status;

	do {
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
		status = readl(&i2c_base->i2c_sr);
#else
		status = readl(&i2c_base->i2c_isr);
#endif
		if ((status & 0x01) == AUGENTIX_I2C_ISR_DONE) {
			break;
		}
		barrier();
	} while (1);

	/* clear interrupt status */
	writel(AUGENTIX_I2C_ICLR_SET, &i2c_base->i2c_iclr);

	return 0;
}

/*
 * i2c_set_bus_speed - Set the i2c speed
 * @speed:	required i2c speed
 *
 * Set the i2c speed.
 */
static unsigned int agtx_i2c_set_bus_speed(struct i2c_adapter *adap,
					 unsigned int speed)
{
	struct i2c_regs *i2c_base = i2c_get_base(adap);
	unsigned int cycle = 0;

	/* calculate clock division */
	cycle = AUGENTIX_SYS_24M_HZ / (speed << 1) - 1;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	cycle -= 3; /* issue #86821 */
#endif
	/* write div to i2c */
	writel((cycle << AUGENTIX_I2C_CLK_SHIFT) | (AUGENTIX_I2C_DELAY_CYCLE << AUGENTIX_I2C_DELAY_CYCLE_SHIFT),
	       &i2c_base->i2c_clk);

	return 0;
}

/*
 * i2c_init - Init function
 * @speed:	required i2c speed
 * @slaveaddr:	slave address for the device
 *
 * Initialization function.
 */
static void agtx_i2c_init(struct i2c_adapter *adap, int speed,
			int slaveaddr)
{
	struct i2c_regs *i2c_base = i2c_get_base(adap);

	/* setting clock division */
	agtx_i2c_set_bus_speed(adap, speed);
	/* clear irq bit */
	writel(AUGENTIX_I2C_IER_DISABLE, &i2c_base->i2c_ier);
	writel(AUGENTIX_I2C_ICLR_SET, &i2c_base->i2c_iclr);
	/* diable autogenread */
	writel(AUGENTIX_I2C_AUTOREAD_OFF, &i2c_base->i2c_autoread);
	/* set slave addr to 0 */
	writel(0x00, &i2c_base->i2c_addr);
	/* default configuration */
	writel(0x00, &i2c_base->i2c_bytes);
	writel(0x00, &i2c_base->i2c_wr0);
	writel(0x00, &i2c_base->i2c_wr1);
	writel(0x00, &i2c_base->i2c_wr2);
	writel(0x00, &i2c_base->i2c_wr3);
	writel(0x00, &i2c_base->i2c_wr4);
	writel(0x00, &i2c_base->i2c_wr5);
	writel(0x00, &i2c_base->i2c_wr6);
	writel(0x00, &i2c_base->i2c_wr7);
	/* interrupt enable */
	writel(AUGENTIX_I2C_IER_ENABLE, &i2c_base->i2c_ier);
}

/*
 * i2c_wait_for_bb - Waits for bus busy
 *
 * Waits for bus busy
 */
static int i2c_wait_for_bb(struct i2c_adapter *adap)
{
	struct i2c_regs *i2c_base = i2c_get_base(adap);
	unsigned long start_time_bb = get_timer(0);

	while (readl(&i2c_base->i2c_sr) & AUGENTIX_I2C_SR_BUSY) {
		/* Evaluate timeout */
		if (get_timer(start_time_bb) > (unsigned long)(I2C_BYTE_TO_BB))
			return 1;
	}

	return 0;
}

/*
 * i2c_read - Read from i2c memory
 * @chip:	target i2c address
 * @addr:	address to read from
 * @alen:
 * @buffer:	buffer for read data
 * @len:	no of bytes to be read
 *
 * Read from i2c memory.
 */
static int agtx_i2c_read(struct i2c_adapter *adap, u8 dev, uint addr,
		       int alen, u8 *buffer, int len)
{
	struct i2c_regs *i2c_base = i2c_get_base(adap);
	int count = 0, rd_cnt = 0, rd_loop = 0;
	int isr_ret = 0;
	unsigned int sr_ret = 0;
	unsigned int reg;

	if ((alen < 0) || (alen > 2)) {
		printf("[%s] bogus address length %x\n", __func__, alen);
		return 1;
	}

	if (len > AUGENTIX_I2C_MAX_RD_LEN) {
		printf("[%s] data length over limit\n", __func__);
		return 1;
	}

	/* check if bus is not busy */
	if (i2c_wait_for_bb(adap))
		return 1;

	/* set addr and read flags */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	writel((dev & 0x7f), &i2c_base->i2c_addr);
	writel(AUGENTIX_I2C_ADDR_READ, &i2c_base->i2c_autoread);
#else
	writel(AUGENTIX_I2C_ADDR_READ | (dev & 0x7f), &i2c_base->i2c_addr);
#endif

	/* set read length */
	writel((len - 1) << AUGENTIX_I2C_RDLEN_SHIFT, &i2c_base->i2c_bytes);

	/* clear interrupt status and trigger once */
	writel(AUGENTIX_I2C_TRIG_SET, &i2c_base->i2c_trig);

	isr_ret = wait_for_i2c_isr(adap);
	if (isr_ret != 0) {
		agtx_i2c_init(adap, adap->speed, adap->slaveaddr);
		printf("[%s] timeout waiting on ISR\n", __func__);
		return 1;
	}

	/* read error status */
	sr_ret = readl(&i2c_base->i2c_sr);
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	if (sr_ret & AUGENTIX_I2C_SR_ERRADDR || sr_ret & AUGENTIX_I2C_SR_ERRDATA) {
		printf("[%s] (After IRQ) Error status %x\n", __func__, sr_ret);
		return 0;
	}
#else
	if (sr_ret) {
		printf("[%s] (After IRQ) Error status %x\n", __func__, sr_ret);
		return 0;
	}
#endif

	/* fill data to buffer */
	while (len > 0) {
		reg = readl(&i2c_base->i2c_rd0 + rd_loop);

		for (count = 0; count < len; count++) {
			*(buffer + rd_cnt) = reg & 0xff;
			reg = reg >> 8;
			rd_cnt++;

			if (count >= 3) {
				count++;
				break;
			}
		}

		len -= count;
		rd_loop++;
	}

	return 0;
}

/*
 * i2c_write - Write to i2c memory
 * @chip:	target i2c address
 * @addr:	address to read from
 * @alen:
 * @buffer:	buffer for read data
 * @len:	no of bytes to be read
 *
 * Write to i2c memory.
 */
static int agtx_i2c_write(struct i2c_adapter *adap, u8 dev, uint addr,
			int alen, u8 *buffer, int len)
{
	struct i2c_regs *i2c_base = i2c_get_base(adap);
	int count = 0, wd0_cnt = 0, data_cnt = 0, wd_cnt = 0, wd_loop = 0;
	int isr_ret = 0;
	unsigned int sr_ret = 0;
	unsigned int reg = 0;
	unsigned int buf = 0;

	if ((alen < 0) || (alen > 2)) {
		printf("[%s] bogus address length %x\n", __func__, alen);
		return 1;
	}

	if (alen + len > AUGENTIX_I2C_MAX_WR_LEN) {
		printf("[%s] address length + data length over limit\n", __func__);
		return 1;
	}

	if (i2c_wait_for_bb(adap))
		return 1;

	/* set addr and write flags */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	writel((dev & 0x7f), &i2c_base->i2c_addr);
	writel(AUGENTIX_I2C_ADDR_WRITE, &i2c_base->i2c_autoread);
#else
	writel(AUGENTIX_I2C_ADDR_WRITE | (dev & 0x7f), &i2c_base->i2c_addr);
#endif
	writel(alen + len - 1, &i2c_base->i2c_bytes);

	/* fill data to register */
	/* addr section */
	for (count = 0; count < alen; count++) {
		buf = (addr >> (count << 3)) & 0xff;
		reg = (reg << (count << 3)) + buf;
	}
	/* data section */
	/* (a) wr0 = addr + data */
	wd0_cnt = (len > (4 - count)) ? (4 - count) : len;
	for (data_cnt = 0; data_cnt < wd0_cnt; data_cnt++) {
		buf = *(buffer + (len - data_cnt - 1));
		reg += (buf << (count << 3));
		count++;
	}
	writel(reg, &i2c_base->i2c_wr0);
	/* (b) fill in remain data */
	while (count < alen + len) {
		reg = 0;
		for (wd_cnt = 0; data_cnt < len; wd_cnt++) {
			buf = *(buffer + (len - data_cnt - 1));
			reg += (buf << (wd_cnt << 3));
			count++;
			data_cnt++;

			if (wd_cnt >= 3) {
				break;
			}
		}
		writel(reg, &i2c_base->i2c_wr1 + wd_loop);
		wd_loop++;
	}

	/* clear interrupt status and trigger once */
	writel(AUGENTIX_I2C_TRIG_SET, &i2c_base->i2c_trig);

	/* wait for work completion */
	isr_ret = wait_for_i2c_isr(adap);
	if (isr_ret != 0) {
		agtx_i2c_init(adap, adap->speed, adap->slaveaddr);
		printf("[%s] timeout waiting on ISR\n", __func__);
		return 1;
	}

	/* read error status */
	sr_ret = readl(&i2c_base->i2c_sr);
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	if (sr_ret & AUGENTIX_I2C_SR_ERRADDR || sr_ret & AUGENTIX_I2C_SR_ERRDATA) {
		printf("[%s] (After IRQ) Error status %x\n", __func__, sr_ret);
		return 0;
	}
#else
	if (sr_ret) {
		printf("[%s] (After IRQ) Error status %x\n", __func__, sr_ret);
		return 0;
	}
#endif

	return 0;
}

/*
 * i2c_probe - Probe the i2c chip
 */
static int agtx_i2c_probe(struct i2c_adapter *adap, u8 dev)
{
	agtx_i2c_init(adap, adap->speed, adap->slaveaddr);

	return 0;
}

U_BOOT_I2C_ADAP_COMPLETE(agtx_i2cm0, agtx_i2c_init, agtx_i2c_probe, agtx_i2c_read, agtx_i2c_write,
                         agtx_i2c_set_bus_speed, AUGENTIX_I2C_DEFAULT_RATE, CONFIG_AGTX_I2C_SLAVE, 0)

#if CONFIG_SYS_I2C_BUS_MAX >= 2
U_BOOT_I2C_ADAP_COMPLETE(agtx_i2cm1, agtx_i2c_init, agtx_i2c_probe, agtx_i2c_read, agtx_i2c_write,
                         agtx_i2c_set_bus_speed, AUGENTIX_I2C_DEFAULT_RATE, CONFIG_AGTX_I2C_SLAVE1, 1)
#endif

