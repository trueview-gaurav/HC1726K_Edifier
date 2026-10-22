/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <drivers/agtx_uart.h>
#include <io.h>
#include <keep.h>
#include <util.h>

/* Register definitions */
#define HC_UART_RX 0x00
#define HC_UART_TX 0x00
#define HC_UART_LSR 0x14
#define HC_UART_TFL 0x80

#define HC_UART_LSR_DR 0x01

#define HC_UART_TX_FIFO_DEPTH 32

#define AGTX_UART_SIZE 0x01000

static vaddr_t chip_to_base(struct serial_chip *chip)
{
	struct agtx_uart_data *pd = container_of(chip, struct agtx_uart_data, chip);

	return io_pa_or_va(&pd->base, AGTX_UART_SIZE);
}

static void agtx_uart_flush(struct serial_chip *chip)
{
	vaddr_t base = chip_to_base(chip);

	while (io_read32(base + HC_UART_TFL))
		;
}

static int agtx_uart_getchar(struct serial_chip *chip)
{
	vaddr_t base = chip_to_base(chip);

	while (io_read32(base + HC_UART_LSR) & HC_UART_LSR_DR)
		;

	return io_read32(base + HC_UART_RX);
}

static void agtx_uart_putc(struct serial_chip *chip, int ch)
{
	vaddr_t base = chip_to_base(chip);

	while ((io_read32(base + HC_UART_TFL) >= (HC_UART_TX_FIFO_DEPTH - 1)))
		;

	io_write32(base + HC_UART_TX, ch);
}

static const struct serial_ops agtx_uart_ops = {
	.flush = agtx_uart_flush,
	.getchar = agtx_uart_getchar,
	.putc = agtx_uart_putc,
};

void agtx_uart_init(struct agtx_uart_data *pd, paddr_t base)
{
	pd->base.pa = base;
	pd->chip.ops = &agtx_uart_ops;

	/*
	 * Do nothing, debug uart share with normal world,
	 * everything for uart initialization is done in bootloader.
	 */
}
