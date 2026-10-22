/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "uart.h"
#include "printf.h"
#include "address_map.h"
#include "csr_bank_peri.h"

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

void uart_init(struct uart_dev *dev)
{
	uint16_t divisor;
	uint16_t divisor_i;
	uint16_t divisor_f;
	uint8_t dlf_divided = 16;
	uint32_t csr __attribute__((unused));

#ifdef CONFIG_FPGA
	/* Wait until TX FIFO empty (#73954)*/
	do {
		read_csr(dev->base_addr, UART_TFL_OFFSET, &csr);
	} while (csr != 0);
#endif
	/* Reset core */

	/*
	 * Set baud rate
	 * divisor_i = (uint_32_t)(ref_clk_rate / (baud_rate * 16))
	 * divisor_f = float parts of (ref_clk_rate / (baud_rate * 16)) handled by dlf register
	 */
	divisor = (dev->ref_clk_rate) * dlf_divided / (dev->baud_rate * 16);
	divisor_i = divisor / dlf_divided;
	divisor_f = divisor % dlf_divided;

	write_csr(dev->base_addr, UART_LCR_OFFSET, UART_LCR__DLAB__ENABLE);
	write_csr(dev->base_addr, UART_DLL_OFFSET, divisor_i & 0xFF);
	write_csr(dev->base_addr, UART_DLH_OFFSET, divisor_i >> 8);
	write_csr(dev->base_addr, UART_DLF_OFFSET, divisor_f & 0xF);
	write_csr(dev->base_addr, UART_LCR_OFFSET, UART_LCR__DLAB__DISABLE);

	/* Set line control to 8-N-1 */
	write_csr(dev->base_addr, UART_LCR_OFFSET, UART_LCR__DLS__8_BIT | UART_LCR__PEN__NONE | UART_LCR__STOP__1_BIT);
	//printf("LCR[4:0] = 0b%05b\n", UART_LCR__DLS__8_BIT | UART_LCR__PEN__NONE | UART_LCR__STOP__1_BIT);

	/* Enable TX/RX FIFOs */
	write_csr(dev->base_addr, UART_FCR_OFFSET, UART_FCR__FIFOE__ENABLE);

	/* Set interrupt mask */
	write_csr(dev->base_addr, UART_IER_OFFSET, dev->enabled_interrupts);

	//	read_csr(dev->base_addr, UART_MCR_OFFSET, &csr);
	//	write_csr(dev->base_addr, UART_MCR_OFFSET, (csr | (1 << 5)));
}

void uart_transmit(struct uart_dev *dev, uint32_t tx_byte_count, uint8_t *tx_buffer)
{
	uint32_t csr;
	uint32_t i;

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

uint32_t uart_receive(struct uart_dev *dev, uint32_t rx_byte_count, uint8_t *rx_buffer, uint32_t timeout)
{
	uint32_t csr;
	uint32_t received = 0;
	uint32_t retry = timeout;

	while (received < rx_byte_count) {
		/* Wait until at least one byte in RX FIFO */
		do {
			if (timeout != 0 && retry == 0) {
				return received;
			}
			read_csr(dev->base_addr, UART_LSR_OFFSET, &csr);
			retry--;
		} while ((csr & UART_LSR__DR__UMASK) == 0);

		/* Read one byte */
		read_csr(dev->base_addr, UART_RBR_OFFSET, &csr);
		*rx_buffer = csr; /* MSB will be dropped as expected */
		rx_buffer++;
		received++;
		retry = timeout;
	}

	return received;
}
