/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * 2025 Augentix, Inc.
 */

/*
 *  linux/drivers/serial/pxa.c
 *
 *  Based on drivers/serial/8250.c by Russell King.
 *
 *  Author:	Nicolas Pitre
 *  Created:	Feb 20, 2003
 *  Copyright:	(C) 2003 Monta Vista Software, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Note 1: This driver is made separate from the already too overloaded
 * 8250.c because it needs some kirks of its own and that'll make it
 * easier to add DMA support.
 *
 * Note 2: I'm too sick of device allocation policies for serial ports.
 * If someone else wants to request an "official" allocation of major/minor
 * for this driver please be my guest.  And don't forget that new hardware
 * to come from Intel might have more than 3 or 4 of those UARTs.  Let's
 * hope for a better port registration and dynamic device allocation scheme
 * with the serial core maintainer satisfaction to appear soon.
 */

#if defined(CONFIG_SERIAL_AUGENTIX_CONSOLE)
#define AUGENTIX_CONSOLE
#endif

#include <linux/platform_device.h>
#include <linux/serial.h>
#include <linux/console.h>
#include <linux/serial_core.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/clk.h>
#include <linux/version.h>

#define AUGENTIX_TTY_NAME	    "ttyAS"

#define AUGENTIX_UART_NR_PORTS	6
#define AUGENTIX_UART_NAME_LEN	8

struct uart_augentix_port {
	struct uart_port        port;
	unsigned char           ier;
	unsigned char           lcr;
	unsigned char           mcr;
	unsigned int            lsr_break_flag;
	unsigned int            mode_sel;/*0: two-wires(TX/RX) 1: four-wires(TX/RX/RTS/CTS) */
	void __iomem		   *mode_sel_regs;
	struct clk		       *clk;
	unsigned int            clk_rate;
	char			name[AUGENTIX_UART_NAME_LEN];
};

static inline unsigned int serial_in(struct uart_augentix_port *up, int offset)
{
	return readl_relaxed(up->port.membase + offset);
}

static inline void serial_out(struct uart_augentix_port *up, int offset, int value)
{
	writel_relaxed(value, up->port.membase + offset);
}

static void set_uart_mode(struct uart_augentix_port *up,int mode_sel)
{
    uint32_t value;

	value = readl_relaxed(up->mode_sel_regs) | mode_sel;

	writel_relaxed(value, up->mode_sel_regs);
}

static void serial_augentix_stop_tx(struct uart_port *port);

#define HC_UART_RX  0x00
#define HC_UART_TX  0x00
#define HC_UART_DLL 0x00
#define HC_UART_DLH 0x04
#define HC_UART_IER 0x04
#define HC_UART_IIR 0x08
#define HC_UART_FCR 0x08
#define HC_UART_LCR 0x0C
#define HC_UART_MCR 0x10
#define HC_UART_LSR 0x14
#define HC_UART_MSR 0x18
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define HC_UART_DLF 0xC0
#define HC_UART_TFL 0x80
#endif

/* LSR */
#define HC_UART_LSR_DR   0x01
#define HC_UART_LSR_OE   0x02
#define HC_UART_LSR_PE   0x04
#define HC_UART_LSR_FE   0x08
#define HC_UART_LSR_BI   0x10
#define HC_UART_LSR_THRE 0x20
#define HC_UART_LSR_TEMT 0x40

/* LCR */
#define HC_UART_LCR_WLEN5      0x00
#define HC_UART_LCR_WLEN6      0x01
#define HC_UART_LCR_WLEN7      0x02
#define HC_UART_LCR_WLEN8      0x03
#define HC_UART_LCR_2_STOP_BIT 0x04
#define HC_UART_LCR_PARITY     0x08
#define HC_UART_LCR_EPAR       0x10
#define HC_UART_LCR_BRK        0x40
#define HC_UART_LCR_DLAB       0x80


/* IER */
#define HC_UART_IER_ERBFI 0x01 /* Enable Received Data Available Interrupt */
#define HC_UART_IER_ETBEI 0x02 /* Enable Transmit Holding Empty Interrupt */
#define HC_UART_IER_ELSI  0x04 /* Enable Receiver Line status Interrupt */
#define HC_UART_IER_EDSSI 0x08 /* Enable Modem Status Interrupt */

/* IIR */
#define HC_UART_IIR_NO_INT 0x01

/* FCR */
#define HC_UART_FCR_ENABLE  0x01
#define HC_UART_FCR_XFIFOR  0x02
#define HC_UART_FCR_RFIFOR  0x04

/* MCR */
#define HC_UART_MCR_RTS	0x02 /* Request to send*/
#define HC_UART_MCR_DTR	0x01 /* Data Terminal Ready */

/* MSR */
#define HC_UART_MSR_DCTS 0x01
#define HC_UART_MSR_DDSR 0x02
#define HC_UART_MSR_DDCD 0x08
#define HC_UART_MSR_TERI 0x04

#define HC_UART_MSR_CTS 0x10
#define HC_UART_MSR_DSR 0x20
#define HC_UART_MSR_RI  0x40
#define HC_UART_MSR_DCD 0x80

#define HC_UART_MSR_ANY_DELTA 0x0F
#define BOTH_EMPTY (HC_UART_LSR_THRE | HC_UART_LSR_TEMT)

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define FIFO_SIZE 32
#define TRANSMIT_CHARS_NUM_PER_IRQ 16
#else
#define FIFO_SIZE 16
#define TRANSMIT_CHARS_NUM_PER_IRQ 4
#endif

static inline void check_modem_status(struct uart_augentix_port *up)
{
	int status;

	status = serial_in(up, HC_UART_MSR);

	if ((status & HC_UART_MSR_ANY_DELTA) == 0)
		return;

	spin_lock(&up->port.lock);
	if (status & HC_UART_MSR_TERI)
		up->port.icount.rng++;
	if (status & HC_UART_MSR_DDSR)
		up->port.icount.dsr++;
	if (status & HC_UART_MSR_DDCD)
		uart_handle_dcd_change(&up->port, status & HC_UART_MSR_DCD);
	if (status & HC_UART_MSR_DCTS)
		uart_handle_cts_change(&up->port, status & HC_UART_MSR_CTS);
	spin_unlock(&up->port.lock);

	wake_up_interruptible(&up->port.state->port.delta_msr_wait);

}


static inline void receive_chars(struct uart_augentix_port *up, int *status)
{
	unsigned int ch, flag;
	int max_count = 256;
	//spin_lock(&port->lock);

	do {
		ch = serial_in(up, HC_UART_RX);
		flag = TTY_NORMAL;
		up->port.icount.rx++;


		if (unlikely(*status & (HC_UART_LSR_BI | HC_UART_LSR_PE |
						   HC_UART_LSR_FE | HC_UART_LSR_OE))) {
			/*
			* For statistics only
			*/
			if (*status & HC_UART_LSR_BI) {
				*status &= ~(HC_UART_LSR_FE | HC_UART_LSR_PE);
				up->port.icount.brk++;
				/*
				* We do the SysRQ and SAK checking
				* here because otherwise the break
				* may get masked by ignore_status_mask
				* or read_status_mask.
				*/
				if (uart_handle_break(&up->port))
					goto ignore_char;

			} else if (*status & HC_UART_LSR_PE) {
					up->port.icount.parity++;
			} else if (*status & HC_UART_LSR_FE) {
					up->port.icount.frame++;
			}

			if (*status & HC_UART_LSR_OE) {
				 up->port.icount.overrun++;
			}

			/*
			* Mask off conditions which should be ignored.
			*/
			*status &= up->port.read_status_mask;

#if 0
			if (up->port.line == up->port.cons->index) {
				/* Recover the break flag from console xmit */
				*status |= up->lsr_break_flag;
				up->lsr_break_flag = 0;
			}
#endif
			if (*status & HC_UART_LSR_BI) {
				flag = TTY_BREAK;
			} else if (*status & HC_UART_LSR_PE)
				flag = TTY_PARITY;
			else if (*status & HC_UART_LSR_FE)
				flag = TTY_FRAME;
			}

			if (uart_handle_sysrq_char(&up->port, ch))
				goto ignore_char;

			uart_insert_char(&up->port, *status, HC_UART_LSR_OE, ch, flag);


	ignore_char:
		*status = serial_in(up, HC_UART_LSR);
	} while ((*status & HC_UART_LSR_DR) && (max_count-- > 0));

	//spin_unlock(&port->lock);
	tty_flip_buffer_push(&up->port.state->port);
}

static void transmit_chars(struct uart_augentix_port *up)
{
	struct circ_buf *xmit = &up->port.state->xmit;
	int count;

	if (up->port.x_char) {
		serial_out(up, HC_UART_TX, up->port.x_char);
		up->port.icount.tx++;
		up->port.x_char = 0;
		return;
	}
	if (uart_circ_empty(xmit) || uart_tx_stopped(&up->port)) {
		serial_augentix_stop_tx(&up->port);
		return;
	}

	count = TRANSMIT_CHARS_NUM_PER_IRQ;

	do {
		serial_out(up, HC_UART_TX, xmit->buf[xmit->tail]);
		xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
		up->port.icount.tx++;
		if (uart_circ_empty(xmit))
			break;
	} while (--count > 0);

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(&up->port);


	if (uart_circ_empty(xmit))
		serial_augentix_stop_tx(&up->port);
}

/*
 * This handles the interrupt from one port.
 */
static inline irqreturn_t hc_serial_irq(int irq, void *dev_id)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)dev_id;
	unsigned int iir, lsr;

	iir = serial_in(up,HC_UART_IIR);
	if (iir & HC_UART_IIR_NO_INT) {
		return IRQ_NONE;
	}
	lsr = serial_in(up,HC_UART_LSR);
	if (lsr & HC_UART_LSR_DR)
		receive_chars(up, &lsr);

	check_modem_status(up);

	if (lsr & HC_UART_LSR_THRE)
		transmit_chars(up);
	return IRQ_HANDLED;
}

static unsigned int serial_augentix_tx_empty(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	unsigned long flags;
	unsigned int ret;

	spin_lock_irqsave(&up->port.lock, flags);
	ret = serial_in(up, HC_UART_LSR) & HC_UART_LSR_TEMT ? TIOCSER_TEMT : 0;
	spin_unlock_irqrestore(&up->port.lock, flags);

	return ret;
}

static unsigned int serial_augentix_get_mctrl(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	unsigned char status;
	unsigned int ret;

	status = serial_in(up, HC_UART_MSR);

	ret = 0;
	if (status & HC_UART_MSR_DCD)
		ret |= TIOCM_CAR;
	if (status & HC_UART_MSR_RI)
		ret |= TIOCM_RNG;
	if (status & HC_UART_MSR_DSR)
		ret |= TIOCM_DSR;
	if (status & HC_UART_MSR_CTS)
		ret |= TIOCM_CTS;

	return ret;
}


static void serial_augentix_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	unsigned char mcr = 0;

	if (mctrl & TIOCM_RTS)
		mcr |= HC_UART_MCR_RTS;
	/*if (mctrl & TIOCM_DTR)
		mcr |= HC_UART_MCR_DTR;*/

	mcr |= up->mcr;
    //printk("[%d]mcr: %x\n",up->port.line,mcr);
	serial_out(up, HC_UART_MCR, mcr);
}

static void serial_augentix_stop_tx(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;

	//if (up->ier & AUGE_UART_IER_ETBEI_EN) { //Nick check
		up->ier &= ~HC_UART_IER_ETBEI;
		serial_out(up, HC_UART_IER, up->ier);
	//}
}

static void serial_augentix_stop_rx(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;

	up->ier &= ~HC_UART_IER_ELSI;
	up->port.read_status_mask &= ~HC_UART_LSR_DR;
	serial_out(up, HC_UART_IER, up->ier);
}

static void serial_augentix_start_tx(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;

	if (!(up->ier & HC_UART_IER_ETBEI)) {
		up->ier |= HC_UART_IER_ETBEI;
		serial_out(up, HC_UART_IER, up->ier);
	}
}

static int serial_augentix_startup(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	//unsigned long flags;
	int retval;

	up->mcr = 0;
	/*
	 * Allocate the IRQ
	 */
	retval = request_irq(up->port.irq, hc_serial_irq, 0, up->name, up);
	if (retval)
		return retval;
#if 0
	/*
	 * Clear the FIFO buffers and disable them.
	 * (they will be reenabled in set_termios())
	 */
	serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO);
	serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO |
			UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
	serial_out(up, UART_FCR, 0);

	/*
	 * Clear the interrupt registers.
	 */
	(void) serial_in(up, UART_LSR);
	(void) serial_in(up, UART_RX);
	(void) serial_in(up, UART_IIR);
	(void) serial_in(up, UART_MSR);

	/*
	 * Now, initialize the UART
	 */
	serial_out(up, UART_LCR, UART_LCR_WLEN8);

	spin_lock_irqsave(&up->port.lock, flags);
	up->port.mctrl |= TIOCM_OUT2;
	serial_pxa_set_mctrl(&up->port, up->port.mctrl);
	spin_unlock_irqrestore(&up->port.lock, flags);
#endif

	/*
	 * Finally, enable interrupts.  Note: Modem status interrupts
	 * are set via set_termios(), which will be occurring imminently
	 * anyway, so we don't enable them here.
	 */
	up->ier = HC_UART_IER_ERBFI | HC_UART_IER_ETBEI | HC_UART_IER_ELSI | HC_UART_IER_EDSSI;
	serial_out(up, HC_UART_IER, up->ier);

	/*
	 * And clear the interrupt registers again for luck.
	 */
	(void) serial_in(up, HC_UART_LSR);
	(void) serial_in(up, HC_UART_RX);
	(void) serial_in(up, HC_UART_IIR);
	(void) serial_in(up, HC_UART_MSR);

	return 0;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 1, 0)
static void serial_augentix_set_termios(struct uart_port *port, struct ktermios *termios, struct ktermios *old)
#else
static void serial_augentix_set_termios(struct uart_port *port, struct ktermios *termios, const struct ktermios *old)
#endif
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	unsigned char cval;//, fcr = 0;
	unsigned long flags;
	unsigned int baud;
	//unsigned int dll;
	uint16_t divisor;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	uint16_t divisor_f;
	uint8_t dlf_divided = 16;
#endif

	switch (termios->c_cflag & CSIZE) {
	case CS5:
		cval = HC_UART_LCR_WLEN5;
		break;
	case CS6:
		cval = HC_UART_LCR_WLEN6;
		break;
	case CS7:
		cval = HC_UART_LCR_WLEN7;
		break;
	default:
	case CS8:
		cval = HC_UART_LCR_WLEN8;
		break;
	}

	if (termios->c_cflag & CSTOPB)
		cval |= HC_UART_LCR_2_STOP_BIT;
	if (termios->c_cflag & PARENB)
		cval |= HC_UART_LCR_PARITY;
	if (!(termios->c_cflag & PARODD))
		cval |= HC_UART_LCR_EPAR;

	/*
	 * Ask the core to calculate the divisor for us.
	 */
	baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk / 16);

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	divisor = (port->uartclk) * dlf_divided / (baud * 16);
	divisor_f = divisor % dlf_divided;
	divisor /= dlf_divided;
#else
	divisor = uart_get_divisor(port, baud);
#endif

	/*
	 * Ok, we're now changing the port state.  Do it with
	 * interrupts disabled.
	 */
	spin_lock_irqsave(&up->port.lock, flags);

	/*
	 * Ensure the port will be enabled.
	 * This is required especially for serial console.
	 */

	/*
	 * Update the per-port timeout.
	 */
	uart_update_timeout(port, termios->c_cflag, baud);

	up->port.read_status_mask = HC_UART_LSR_OE | HC_UART_LSR_THRE | HC_UART_LSR_DR;
	if (termios->c_iflag & INPCK)
		up->port.read_status_mask |= HC_UART_LSR_FE | HC_UART_LSR_PE;
	if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
		up->port.read_status_mask |= HC_UART_LSR_BI;

	/*
	 * Characters to ignore
	 */
	up->port.ignore_status_mask = 0;
	if (termios->c_iflag & IGNPAR)
		up->port.ignore_status_mask |= HC_UART_LSR_FE | HC_UART_LSR_PE;
	if (termios->c_iflag & IGNBRK) {
		up->port.ignore_status_mask |= HC_UART_LSR_BI;
		/*
		 * If we're ignoring parity and break indicators,
		 * ignore overruns too (for real raw support).
		 */
		if (termios->c_iflag & IGNPAR)
			up->port.ignore_status_mask |= HC_UART_LSR_OE;
	}

	/*
	 * ignore all characters if CREAD is not set
	 */
	if ((termios->c_cflag & CREAD) == 0)
		up->port.ignore_status_mask |= HC_UART_LSR_DR;

	/*
	 * CTS flow control flag and modem status interrupts
	 */
	up->ier &= ~HC_UART_IER_EDSSI;
	if (UART_ENABLE_MS(&up->port, termios->c_cflag))
		up->ier |= HC_UART_IER_EDSSI;

	serial_out(up, HC_UART_IER, up->ier);

	serial_out(up, HC_UART_LCR, cval | HC_UART_LCR_DLAB);	/* set DLAB */
	serial_out(up, HC_UART_DLL, divisor & 0xff); /* LS of divisor */
	serial_out(up, HC_UART_DLH, divisor >> 8); /* MS of divisor */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	serial_out(up, HC_UART_DLF, divisor_f & 0xF);
#endif
	serial_out(up, HC_UART_LCR, cval);			/* reset DLAB */
	up->lcr = cval;					/* Save LCR */
	//serial_pxa_set_mctrl(&up->port, up->port.mctrl);
	serial_out(up, HC_UART_FCR, HC_UART_FCR_ENABLE); /*enable FIFO*/
	spin_unlock_irqrestore(&up->port.lock, flags);
}

static void serial_augentix_break_ctl(struct uart_port *port, int break_state)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	unsigned long flags;

	spin_lock_irqsave(&up->port.lock, flags);
	if (break_state == -1)
		up->lcr |= HC_UART_LCR_BRK;
	else
		up->lcr &= ~HC_UART_LCR_BRK;
	serial_out(up, HC_UART_LCR, up->lcr);
	spin_unlock_irqrestore(&up->port.lock, flags);
}

static void serial_augentix_shutdown(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	unsigned long flags;

	free_irq(up->port.irq, up);

	/*
	 * Disable interrupts from this port
	 */
	up->ier = 0;
	serial_out(up, HC_UART_IER, 0);

	/*
	 * Disable break condition and FIFOs
	 */
	spin_lock_irqsave(&up->port.lock, flags);
	serial_out(up, HC_UART_LCR, serial_in(up, HC_UART_LCR) & ~HC_UART_LCR_BRK);
	spin_unlock_irqrestore(&up->port.lock, flags);

	serial_out(up, HC_UART_FCR, 0);

}

static const char *
serial_augentix_type(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	return up->name;
}

static void serial_augentix_release_port(struct uart_port *port)
{
}

static int serial_augentix_request_port(struct uart_port *port)
{
	return 0;
}

static void serial_augentix_config_port(struct uart_port *port, int flags)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	if (flags & UART_CONFIG_TYPE)
		up->port.type = PORT_8250;
}

static int
serial_augentix_verify_port(struct uart_port *port, struct serial_struct *ser)
{
	/* we don't want the core code to modify any port params */
	return -EINVAL;
}

static struct uart_augentix_port *serial_augentix_ports[AUGENTIX_UART_NR_PORTS];
static struct uart_driver serial_augentix_reg;

#ifdef AUGENTIX_CONSOLE
/*
 *	Wait for transmitter & holding register to empty
 */
static inline void wait_for_xmitr(struct uart_augentix_port *up)
{
	unsigned int status, tmout = 10000;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	uint32_t fifo_level = 0;
#endif

	/* Wait up to 10ms for the character(s) to be sent. */
	do {
		status = serial_in(up, HC_UART_LSR);
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		fifo_level = serial_in(up, HC_UART_TFL);
#endif
		if (status & HC_UART_LSR_BI)
			up->lsr_break_flag = HC_UART_LSR_BI;

		if (--tmout == 0)
			break;
		udelay(1);
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	} while (fifo_level > 30);
#else
	} while ((status & BOTH_EMPTY) != BOTH_EMPTY);
#endif

	/* Wait up to 1s for flow control if necessary */
	if (up->port.flags & UPF_CONS_FLOW) {
		tmout = 1000000;
		while (--tmout &&
		       ((serial_in(up, HC_UART_MSR) & HC_UART_MSR_CTS) == 0))
			udelay(1);
	}

}

/**
 * serial_augentix_console_putchar - write the character to the FIFO buffer
 * @port: Handle to the uart port structure
 * @ch: Character to be written
 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 18, 0)
static void serial_augentix_console_putchar(struct uart_port *port, int ch)
#else
static void serial_augentix_console_putchar(struct uart_port *port, unsigned char ch)
#endif
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;

	wait_for_xmitr(up);
	serial_out(up, HC_UART_TX, ch);
}

static void auge_early_write(struct console *con, const char *s, unsigned n)
{
	struct earlycon_device *dev = con->data;

	uart_console_write(&dev->port, s, n, serial_augentix_console_putchar);
}

static int __init auge_early_console_setup(struct earlycon_device *device,
					   const char *opt)
{

	if (!device->port.membase)
		return -ENODEV;

	device->con->write = auge_early_write;

	return 0;
}
EARLYCON_DECLARE(auge, auge_early_console_setup);

/**
 * serial_augentix_console_write - perform write operation
 * @co: Console handle
 * @s: Pointer to character array
 * @count: No of characters
 */
static void serial_augentix_console_write(struct console *co, const char *s,
				unsigned int count)
{
	struct uart_augentix_port *up = serial_augentix_ports[co->index];
	struct uart_port *port = &up->port;
	unsigned int ier;
	unsigned long flags;
	int locked = 1;

	if (port->sysrq)
		locked = 0;
	else if (oops_in_progress)
		locked = spin_trylock_irqsave(&port->lock, flags);
	else
		spin_lock_irqsave(&port->lock, flags);

	ier = HC_UART_IER_ERBFI | HC_UART_IER_ETBEI | HC_UART_IER_ELSI | HC_UART_IER_EDSSI;
	serial_out(up, HC_UART_IER, 0x00);

	uart_console_write(port, s, count, serial_augentix_console_putchar);
	wait_for_xmitr(up);

	serial_out(up, HC_UART_IER, ier);

	if (locked)
		spin_unlock_irqrestore(&port->lock, flags);
}

#ifdef CONFIG_CONSOLE_POLL
/*
 * Console polling routines for writing and reading from the uart while
 * in an interrupt or debug context.
 */

static int serial_augentix_get_poll_char(struct uart_port *port)
{
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;
	unsigned char lsr = serial_in(up, HC_UART_LSR);

	while (!(lsr & HC_UART_LSR_DR))
		lsr = serial_in(up, HC_UART_LSR);

	return serial_in(up, HC_UART_RX);
}


static void serial_augentix_put_poll_char(struct uart_port *port,
			 unsigned char c)
{
	unsigned int ier;
	struct uart_augentix_port *up = (struct uart_augentix_port *)port;

	/*
	 *	First save the IER then disable the interrupts
	 */
	ier = serial_in(up, HC_UART_IER);
	serial_out(up, HC_UART_IER, 0x0);

	wait_for_xmitr(up);
	/*
	 *	Send the character out.
	 */
	serial_out(up, HC_UART_TX, c);

	/*
	 *	Finally, wait for transmitter to become empty
	 *	and restore the IER
	 */
	wait_for_xmitr(up);
	serial_out(up, HC_UART_IER, ier);
}

#if 0
static int auge_uart_poll_get_char(struct uart_port *port)
{
	int c;
	/* Disable all interrupts */
	auge_uart_writel(0x00, AUGE_UART_IER_OFFSET);

	/* Check if FIFO is empty */
	if ((auge_uart_readl(AUGE_UART_LSR_OFFSET) & Uart_line_dr) != Uart_line_dr)
		c = NO_POLL_CHAR;
	else /* Read a character */
		c = (unsigned char) auge_uart_readl(AUGE_UART_RBR_OFFSET);


	/* Enable interrupts */
	auge_uart_writel(AUGE_UART_IER_ERBFI_EN | AUGE_UART_IER_ETBEI_EN |
			         AUGE_UART_IER_ELSI_EN | AUGE_UART_IER_EDSSI_EN, AUGE_UART_IER_OFFSET);

	return c;
}

static void auge_uart_poll_put_char(struct uart_port *port, unsigned char c)
{

	/* Disable all interrupts */
	auge_uart_writel(0x00, AUGE_UART_IER_OFFSET);

	/* Wait until FIFO is empty */
	while ((auge_uart_readl(AUGE_UART_LSR_OFFSET) & Uart_line_thre) != Uart_line_thre)
		cpu_relax();

	/* Write a character */
	auge_uart_writel(c, AUGE_UART_THR_OFFSET);

	/* Wait until FIFO is empty */
	while ((auge_uart_readl(AUGE_UART_LSR_OFFSET) & Uart_line_thre) != Uart_line_thre)
		cpu_relax();

	/* Enable interrupts */
	auge_uart_writel(AUGE_UART_IER_ERBFI_EN | AUGE_UART_IER_ETBEI_EN |
			         AUGE_UART_IER_ELSI_EN | AUGE_UART_IER_EDSSI_EN, AUGE_UART_IER_OFFSET);

	return;
}
#endif

#endif

/**
 * serial_augentix_console_setup - Initialize the uart to default config
 * @co: Console handle
 * @options: Initial settings of uart
 *
 * Return: 0 on success, negative errno otherwise.
 */
static int __init serial_augentix_console_setup(struct console *co, char *options)
{
	struct uart_augentix_port *up;
	int baud = 9600;
	int bits = 8;
	int parity = 'n';
	int flow = 'n';

	if (co->index == -1 || co->index >= serial_augentix_reg.nr)
		co->index = 0;
	up = serial_augentix_ports[co->index];
	if (!up)
		return -ENODEV;

	if (options)
		uart_parse_options(options, &baud, &parity, &bits, &flow);

	return uart_set_options(&up->port, co, baud, parity, bits, flow);

}


static struct console serial_augentix_console = {
	.name	= AUGENTIX_TTY_NAME,
	.write	= serial_augentix_console_write,
	.device	= uart_console_device,
	.setup	= serial_augentix_console_setup,
	.flags	= CON_PRINTBUFFER,
	.index	= -1, /* Specified on the cmdline (e.g. console=ttyAS ) */
	.data	= &serial_augentix_reg,
};

/**
 * auge_uart_console_init - Initialization call
 *
 * Return: 0 on success, negative errno otherwise
 */
static int __init auge_uart_console_init(void)
{
	register_console(&serial_augentix_console);
	return 0;
}

console_initcall(auge_uart_console_init);
#endif

/*
 * This structure describes all the operations that can be done on the
 * physical hardware.  See Documentation/serial/driver for details.
 *
 * struct uart_ops {
	  unsigned int	(*tx_empty)(struct uart_port *);
	  void		(*set_mctrl)(struct uart_port *, unsigned int mctrl);
	  unsigned int	(*get_mctrl)(struct uart_port *);
	  void		(*stop_tx)(struct uart_port *);
	  void		(*start_tx)(struct uart_port *);
	  void		(*throttle)(struct uart_port *);
	  void		(*unthrottle)(struct uart_port *);
	  void		(*send_xchar)(struct uart_port *, char ch);
	  void		(*stop_rx)(struct uart_port *);
	  void		(*enable_ms)(struct uart_port *);
	  void		(*break_ctl)(struct uart_port *, int ctl);
	  int		(*startup)(struct uart_port *);
	  void		(*shutdown)(struct uart_port *);
	  void		(*flush_buffer)(struct uart_port *);
	  void		(*set_termios)(struct uart_port *, struct ktermios *new,
				       struct ktermios *old);
	  void		(*set_ldisc)(struct uart_port *, int new);
	  void		(*pm)(struct uart_port *, unsigned int state,
			      unsigned int oldstate);

	  * Return a string describing the type of the port
	  const char	*(*type)(struct uart_port *);

	  * Release IO and memory resources used by the port.
	  * This includes iounmap if necessary.
	  void		(*release_port)(struct uart_port *);

	  * Request IO and memory resources used by the port.
	  * This includes iomapping the port if necessary.
	  int		(*request_port)(struct uart_port *);

	  void		(*config_port)(struct uart_port *, int);
	  int		(*verify_port)(struct uart_port *, struct serial_struct *);
	  int		(*ioctl)(struct uart_port *, unsigned int, unsigned long);

      int		(*poll_init)(struct uart_port *);
	  void		(*poll_put_char)(struct uart_port *, unsigned char);
	  int		(*poll_get_char)(struct uart_port *);
 */
static struct uart_ops serial_augentix_pops = {
	.set_mctrl	= serial_augentix_set_mctrl,
	.get_mctrl	= serial_augentix_get_mctrl,
	.start_tx	= serial_augentix_start_tx,
	.stop_tx	= serial_augentix_stop_tx,
	.stop_rx	= serial_augentix_stop_rx,
	.tx_empty	= serial_augentix_tx_empty,
	.break_ctl	= serial_augentix_break_ctl,
	.set_termios	= serial_augentix_set_termios,
	.startup	= serial_augentix_startup,
	.shutdown	= serial_augentix_shutdown,
	.type		= serial_augentix_type,
	.verify_port	= serial_augentix_verify_port,
	.request_port	= serial_augentix_request_port,
	.release_port	= serial_augentix_release_port,
	.config_port	= serial_augentix_config_port,
#ifdef CONFIG_CONSOLE_POLL
	.poll_get_char	= serial_augentix_get_poll_char,
	.poll_put_char	= serial_augentix_put_poll_char,
#endif
};

static struct uart_driver serial_augentix_reg = {
	.owner = THIS_MODULE,
	.driver_name = "Augentix serial",
	.dev_name = AUGENTIX_TTY_NAME,
	.major = 0,
	.minor = 0,
	.nr = AUGENTIX_UART_NR_PORTS,
#ifdef AUGENTIX_CONSOLE
	.cons = &serial_augentix_console,
#endif
};

#if 0
static int uart_soft_reset(struct uart_augentix_port *up,int id)
{
	// FIXME: Use reset API
	hc18xx_enable_sw_rst(SW_RST_UART0 + id);
	clk_disable_unprepare(up->clk);

	hc18xx_disable_sw_rst(SW_RST_UART0 + id);
	clk_prepare_enable(up->clk);

	return 0;
}
#endif

static int serial_augentix_probe(struct platform_device *pdev)
{
	struct uart_augentix_port *sport;
	struct resource res_0,res_1;
	int id;
	int ret = 0;

	sport = kzalloc(sizeof(struct uart_augentix_port), GFP_KERNEL);
	if (!sport)
		return -ENOMEM;

	ret = of_address_to_resource(pdev->dev.of_node, 0, &res_0);
	if (ret) {
	   dev_err(&pdev->dev, "No resource specified\n");
	   return -ENODEV;
	}

	ret = of_address_to_resource(pdev->dev.of_node, 1, &res_1);
	if (ret) {
	   dev_err(&pdev->dev, "No resource specified\n");
	   return -ENODEV;
	}

	sport->mode_sel_regs = devm_ioremap(&pdev->dev,res_1.start, resource_size(&res_1));

	/*
	 * devm_clk_get(dev, NULL) is same as of_clk_get(np, 0).
	 * If intending to use plural clock source, use of_clk_get(np, index).
	 * Remember not to use clock-names to reduce code size and boot time
	 */
	sport->clk = devm_clk_get(&pdev->dev, NULL);
	if(IS_ERR(sport->clk)) {
		dev_err(&pdev->dev, "cannot get uart clk source");
		return -ENODEV;
	}

	/* enable clk */
	clk_prepare_enable(sport->clk);

	/* get read clock rate */
	if (of_property_read_u32(pdev->dev.of_node, "clock-frequency", &sport->clk_rate)) {
		sport->clk_rate = 125000000;
		dev_info(&pdev->dev, "No found clock-frequency, use the default settings (125000000)\n");
	}

	/* Look for a serialN alias */
	id = of_alias_get_id(pdev->dev.of_node, "serial");
	if (id < 0)
		id = 0;

	/* find out uart mode_sel */
	if (of_property_read_u32(pdev->dev.of_node, "mode_sel",&sport->mode_sel)) {
		dev_info(&pdev->dev,"No found uart mode, use the default settings\n");
		sport->mode_sel = 0;
	}

	/* FIXME: To be added back after sw_rst is ready */
	//uart_soft_reset(sport, id);

	/* set uart mode */
	set_uart_mode(sport,sport->mode_sel<<(8*id));

	spin_lock_init(&sport->port.lock);
	sport->port.type = PORT_8250;
	sport->port.iotype = UPIO_MEM;
	sport->port.iobase  = 1; /* mark port in use */
	sport->port.mapbase = res_0.start;
	sport->port.irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
	sport->port.fifosize = FIFO_SIZE;
	sport->port.ops = &serial_augentix_pops;
	sport->port.dev = &pdev->dev;
	sport->port.flags = UPF_BOOT_AUTOCONF;
	sport->port.uartclk = sport->clk_rate;
	sport->port.line = id;

	snprintf(sport->name, AUGENTIX_UART_NAME_LEN - 1, "UART%d", sport->port.line + 1);

	sport->port.membase = devm_ioremap(&pdev->dev,res_0.start, resource_size(&res_0));
	if (!sport->port.membase) {
		ret = -ENOMEM;
	}

	serial_augentix_ports[sport->port.line] = sport;

	ret = uart_add_one_port(&serial_augentix_reg, &sport->port);
	if (ret) {
		dev_err(&pdev->dev,"uart_add_one_port() failed; err=%i\n", ret);
	}

	platform_set_drvdata(pdev, sport);

	dev_info(&pdev->dev, "Augentix UART driver Initialized\n");

	return ret;
}

static int serial_augentix_remove(struct platform_device *dev)
{
	struct uart_augentix_port *sport = platform_get_drvdata(dev);

	uart_remove_one_port(&serial_augentix_reg, &sport->port);

	kfree(sport);

	return 0;
}

static struct of_device_id serial_augentix_ids[] = {
	{ .compatible = "augentix,uart", },
	{}
};
MODULE_DEVICE_TABLE(of, serial_augentix_ids);

static struct platform_driver serial_augentix_driver = {
	.probe	= serial_augentix_probe,
	.remove	= serial_augentix_remove,
	.driver	= {
		.name	= "augentix-uart",
		.owner	= THIS_MODULE,
		.of_match_table = serial_augentix_ids,
	},
};

static int __init serial_augentix_init(void)
{
	int ret;

	ret = uart_register_driver(&serial_augentix_reg);
	if (ret != 0)
		return ret;

	ret = platform_driver_register(&serial_augentix_driver);
	if (ret != 0)
		uart_unregister_driver(&serial_augentix_reg);

	return ret;
}

static void __exit serial_augentix_exit(void)
{
	platform_driver_unregister(&serial_augentix_driver);
	uart_unregister_driver(&serial_augentix_reg);
}

module_init(serial_augentix_init);
module_exit(serial_augentix_exit);

MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:augentix-uart");
