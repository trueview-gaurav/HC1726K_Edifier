#include "uart.h"
#include "printf.h"
#include "address_map.h"
#include "csr_bank_peri.h"
#include "csr_bank_pioc.h"

static inline void write_csr(uint32_t base, uint32_t offset, uint32_t value)
{
	long ptr = base + offset;
	*((volatile uint32_t *)(ptr)) = value;
}

static inline void read_csr(uint32_t base, uint32_t offset, uint32_t *value)
{
	long ptr = base + offset;
	*value = *((volatile uint32_t *)(ptr));
}

void uart_transmit(struct uart_dev *dev, uint32_t tx_byte_count, uint8_t *tx_buffer)
{
	uint32_t csr;
	uint32_t i;
	uint32_t *IIR;

	while (tx_byte_count > 0) {
		/* Wait until TX FIFO empty */
		do {
			read_csr(dev->base_addr, UART_LSR_OFFSET, &csr);
		} while ((csr & UART_LSR__THRE__UMASK) == 0);

		/* Transmit at most UART_TX_FIFO_SIZE bytes at a time */
		i = (tx_byte_count > UART_TX_FIFO_SIZE) ? UART_TX_FIFO_SIZE : tx_byte_count;
		tx_byte_count -= i;
		for (; i > 0; i--) {
			write_csr(dev->base_addr, UART_THR_OFFSET, *tx_buffer);
			tx_buffer++;
		}
	}
}
