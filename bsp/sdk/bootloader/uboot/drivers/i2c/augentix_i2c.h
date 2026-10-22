/*
 * (C) Copyright 2021 Augentix 
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __AGTX_I2C_H_
#define __AGTX_I2C_H_

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
struct i2c_regs {
	u32 i2c_trig;
	u32 i2c_iclr;
	u32 i2c_sr;
	u32 i2c_ier;
	u32 i2c_tmo;
	u32 i2c_tmo2;
	u32 i2c_tmo_abort;
	u32 i2c_trans_sr;
	u32 i2c_deglitch;
	u32 i2c_clk;
	u32 i2c_autoread;
	u32 i2c_addr;
	u32 i2c_bytes;
	u32 i2c_wr0;
	u32 i2c_wr1;
	u32 i2c_wr2;
	u32 i2c_wr3;
	u32 i2c_wr4;
	u32 i2c_wr5;
	u32 i2c_wr6;
	u32 i2c_wr7;
	u32 i2c_rd0;
	u32 i2c_rd1;
	u32 i2c_rd2;
	u32 i2c_rd3;
	u32 i2c_rd4;
	u32 i2c_rd5;
	u32 i2c_rd6;
	u32 i2c_rd7;
	u32 i2c_debug_monitor;
	u32 i2c_reserved;
};
#else
struct i2c_regs {
	u32 i2c_trig;
	u32 i2c_iclr;
	u32 i2c_isr;
	u32 i2c_ier;
	u32 i2c_sr;
	u32 i2c_trans_sr;
	u32 i2c_clk;
	u32 i2c_autoread;
	u32 i2c_addr;
	u32 i2c_bytes;
	u32 i2c_wr0;
	u32 i2c_wr1;
	u32 i2c_wr2;
	u32 i2c_wr3;
	u32 i2c_wr4;
	u32 i2c_wr5;
	u32 i2c_wr6;
	u32 i2c_wr7;
	u32 i2c_rd0;
	u32 i2c_rd1;
};
#endif

/* Region offsets for I2C controller. */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
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
#endif

/* Control register signal difinition */
#define AUGENTIX_I2C_TRIG_SET 0x01 /* Start transmit */
#define AUGENTIX_I2C_ISR_DONE 0x01 /* I2C interrupt*/
#define AUGENTIX_I2C_ADDR_WRITE 0x00 /* I2C write */
#define AUGENTIX_I2C_CLK_DEFAULT ((120 << 16) | 0x00) /* Frquency 100Khz */
#define AUGENTIX_I2C_AUTOREAD_ON ((10 << 16) | 0x01) /* Enable autogenread */
#define AUGENTIX_I2C_AUTOREAD_OFF ((10 << 16) | 0x00) /* Disable autogenread */

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define AUGENTIX_I2C_ICLR_SET 0x01111111 /* Clear irq status */
#define AUGENTIX_I2C_IER_DISABLE 0x01111111 /* Disable interrupt */
#define AUGENTIX_I2C_IER_ENABLE 0x01111110 /* Enable interrupt */
#define AUGENTIX_I2C_SR_BUSY BIT(26) /* Bus busy */
#define AUGENTIX_I2C_ADDR_READ BIT(12) /* I2C read */
#define AUGENTIX_I2C_SR_ERRADDR BIT(27) /* Error address */
#define AUGENTIX_I2C_SR_ERRDATA BIT(28) /* Error data */
#else
#define AUGENTIX_I2C_ICLR_SET 0x01 /* Clear irq status */
#define AUGENTIX_I2C_IER_DISABLE 0x01 /* Disable interrupt */
#define AUGENTIX_I2C_IER_ENABLE 0x00 /* Enable interrupt */
#define AUGENTIX_I2C_SR_BUSY 0x01 /* Bus busy */
#define AUGENTIX_I2C_ADDR_READ BIT(8) /* I2C read */
#define AUGENTIX_I2C_SR_ERRADDR BIT(16) /* Error address */
#define AUGENTIX_I2C_SR_ERRDATA BIT(17) /* Error data */
#endif

/* Define masks */
#define AUGENTIX_I2C_WRLEN_MASK 0xff
#define AUGENTIX_I2C_WRNUM_MASK 0xff00
#define AUGENTIX_I2C_RDLEN_MASK 0xff0000

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define AUGENTIX_I2C_CLK_MASK 0x3ff800
#else
#define AUGENTIX_I2C_CLK_MASK 0xff0000
#endif

/* Shift macros */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define AUGENTIX_I2C_DELAY_CYCLE_SHIFT 0x00
#else
#define AUGENTIX_I2C_DELAY_CYCLE_SHIFT 0x08
#endif
#define AUGENTIX_I2C_RDLEN_SHIFT 0x10

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define AUGENTIX_I2C_CLK_SHIFT 0x0B
#else
#define AUGENTIX_I2C_CLK_SHIFT 0x10
#endif

/* Software definition */
#define AUGENTIX_I2C_DEFAULT_DELAY_CYCLE 0x04
#define AUGENTIX_I2C_DEFAULT_RATE (100 * 1000)
#define AUGENTIX_I2C_MAX_RATE (400 * 1000)
#define AUGENTIX_I2C_MAX_WR_LEN 0x20

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
#define AUGENTIX_I2C_MAX_RD_LEN 0x20
#else
#define AUGENTIX_I2C_MAX_RD_LEN 0x08
#endif

#define AUGENTIX_SYS_24M_HZ (24 * 1000000)
#ifdef CONFIG_FASTBOOT
#define AUGENTIX_I2C_DELAY_CYCLE 0x0F
#else
#define AUGENTIX_I2C_DELAY_CYCLE 0x00
#endif

#define AUGENTIX_I2C0_SDA_IOSEL_OFFSET 0x1FC /* Bit 2:0 PAD_I2C0_SDA_IOSEL */
#define AUGENTIX_I2C0_SCL_IOSEL_OFFSET 0x200 /* Bit 2:0 PAD_I2C0_SCL_IOSEL */
#define AUGENTIX_I2C0_SDA_IOCFG_OFFSET 0xB8 /* Bit 18:16 PAD_I2C0_SDA_PCFG */
#define AUGENTIX_I2C0_SCL_IOCFG_OFFSET 0xBC /* Bit 18:16 PAD_I2C0_SCL_PCFG */
#define AUGENTIX_I2C1_SCL_IOSEL_OFFSET 0x14C /* Bit 2:0 PAD_I2C1_SCL_IOSEL */
#define AUGENTIX_I2C1_SDA_IOSEL_OFFSET 0x150 /* Bit 2:0 PAD_I2C1_SDA_IOSEL */
#define AUGENTIX_I2C1_SCL_IOCFG_OFFSET 0x3C /* Bit 18:16 PAD_I2C1_SCL_PCFG */
#define AUGENTIX_I2C1_SDA_IOCFG_OFFSET 0x40 /* Bit 18:16 PAD_I2C1_SDA_PCFG */

#define CONFIG_SYS_I2C_BUS_MAX 2

#define	CONFIG_AGTX_I2C_SPEED	100000
#define	CONFIG_AGTX_I2C_SPEED1	100000
#define	CONFIG_AGTX_I2C_SLAVE	0x0
#define	CONFIG_AGTX_I2C_SLAVE1	0x0

/* Worst case timeout for 1 byte is kept as 2ms */
#define I2C_BYTE_TO		(CONFIG_SYS_HZ/500)
#define I2C_STOPDET_TO		(CONFIG_SYS_HZ/500)
#define I2C_BYTE_TO_BB		(I2C_BYTE_TO * 16)

#endif /* __AGTX_I2C_H_ */
