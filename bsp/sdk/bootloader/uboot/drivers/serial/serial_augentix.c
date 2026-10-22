/*
 * Copyright (C) 2016 Nick Lin <nick.lin@augentix.com>
 *
 */
#include <common.h>
#include <watchdog.h>
#include <asm/io.h>
#include <linux/compiler.h>
#include <serial.h>
//#include <asm/arch/clk.h>
//#include <asm/arch/hardware.h>

DECLARE_GLOBAL_DATA_PTR;

struct uart_auge {
	u32 reg00; /* 0x00*/
	u32 reg04; /* 0x04*/
	u32 reg08; /* 0x08*/
	u32 reg0C; /* 0x0C*/
	u32 reg10; /* 0x10*/
	u32 reg14; /* 0x14*/
};

static struct uart_auge *uart_auge_ports[1] = {
	[0] = (struct uart_auge *)CONSOLE_BASE,
};

/* Set up the baud rate in gd struct */
static void uart_auge_serial_setbrg(const int port)
{

	struct uart_auge *regs = uart_auge_ports[port];
	unsigned long baud = gd->baudrate;
	unsigned long clock = UART_CLOCK; //get_uart_clk(port);//Need to setup clk
	unsigned int div __attribute__((unused)) = 0;

	/*set baud rate*/
	div =  clock/(baud*16); //get clock ??

	writel(0x80, &regs->reg0C);

	writel(0x0, &regs->reg0C);
}

/* Initialize the UART, with...some settings. */
static int uart_auge_serial_init(const int port)
{
	struct uart_auge *regs = uart_auge_ports[port];
	if (!regs)
		return -1;

	uart_auge_serial_setbrg(port);

    /*set 8 data bits,1 stop bit,no parity*/
	writel(0x03 , &regs->reg0C);

	/*enable FIFO*/
	writel(0x01, &regs->reg08);

	return 0;
}

static void uart_auge_serial_putc(const char c, const int port)
{
	struct uart_auge *regs = uart_auge_ports[port];

	while ((readl(&regs->reg14) & 0x20) != 0x20)
		WATCHDOG_RESET();

	if (c == '\n') {
		writel('\r', &regs->reg00);
		while ((readl(&regs->reg14) & 0x20) != 0x20)
			WATCHDOG_RESET();
	}
	writel(c, &regs->reg00);
}

static void uart_auge_serial_puts(const char *s, const int port)
{
	while (*s)
		uart_auge_serial_putc(*s++, port);
}

static int uart_auge_serial_tstc(const int port)
{
	struct uart_auge *regs = uart_auge_ports[port];

	return (readl(&regs->reg14) & 0x01) == 0x01;
}

static int uart_auge_serial_getc(const int port)
{
	struct uart_auge *regs = uart_auge_ports[port];
	while (!uart_auge_serial_tstc(port))
		WATCHDOG_RESET();
	return readl(&regs->reg00);
}

/* Multi serial device functions */

#define DECLARE_PSSERIAL_FUNCTIONS(port) \
	static int uart_auge##port##_init(void) \
				{ return uart_auge_serial_init(port); } \
	static void uart_auge##port##_setbrg(void) \
				{ return uart_auge_serial_setbrg(port); } \
	static int uart_auge##port##_getc(void) \
				{ return uart_auge_serial_getc(port); } \
	static int uart_auge##port##_tstc(void) \
				{ return uart_auge_serial_tstc(port); } \
	static void uart_auge##port##_putc(const char c) \
				{ uart_auge_serial_putc(c, port); } \
	static void uart_auge##port##_puts(const char *s) \
				{ uart_auge_serial_puts(s, port); }

/* Serial device descriptor */
#define INIT_PSSERIAL_STRUCTURE(port, __name) {	\
	  .name   = __name,			\
	  .start  = uart_auge##port##_init,	\
	  .stop   = NULL,			\
	  .setbrg = uart_auge##port##_setbrg,	\
	  .getc   = uart_auge##port##_getc,	\
	  .tstc   = uart_auge##port##_tstc,	\
	  .putc   = uart_auge##port##_putc,	\
	  .puts   = uart_auge##port##_puts,	\
}

DECLARE_PSSERIAL_FUNCTIONS(0);
static struct serial_device uart_auge_serial0_device =
	INIT_PSSERIAL_STRUCTURE(0, "ttyAS0");



__weak struct serial_device *default_serial_console(void)
{
	//if (uart_auge_ports[0])
		return &uart_auge_serial0_device;

	//return NULL;
}

void auge_serial_initialize(void)
{
	serial_register(&uart_auge_serial0_device);
}
