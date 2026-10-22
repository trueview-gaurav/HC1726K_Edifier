#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#define UART0_BASE_ADDR 0x80820000
#define UART1_BASE_ADDR 0x80830000
#define UART2_BASE_ADDR 0x80840000
#define UART3_BASE_ADDR 0x80850000
#define UART4_BASE_ADDR 0x80860000
#define UART5_BASE_ADDR 0x80870000

#define UART_MODE_SEL_ADDR 0x80020000

#define FPGA_CFG_ADDR 0x80FF0000

#define UART0_TXD_IOSEL 0x01D8
#define UART0_RXD_IOSEL 0x01DC
#define UART0_RTS_IOSEL 0x01E0
#define UART0_CTS_IOSEL 0x01E4

#define UART_THR_OFFSET 0x00
#define UART_RBR_OFFSET 0x00
#define UART_DLL_OFFSET 0x00
#define UART_DLH_OFFSET 0x04
#define UART_IER_OFFSET 0x04
#define UART_FCR_OFFSET 0x08
#define UART_IIR_OFFSET 0x08
#define UART_LCR_OFFSET 0x0C
#define UART_MCR_OFFSET 0x10
#define UART_LSR_OFFSET 0x14
#define UART_MSR_OFFSET 0x18

#define UART_IER__NONE 0x00
#define UART_IER__ERBFI 0x01
#define UART_IER__ETBEI 0x02
#define UART_IER__ELSI 0x04
#define UART_IER__EDSSI 0x08

#define UART_FCR__FIFOE__ENABLE 0x01

#define UART_LCR__DLAB__DISABLE 0x00
#define UART_LCR__DLAB__ENABLE 0x80
#define UART_LCR__DLS__8_BIT 0x03
#define UART_LCR__DLS__7_BIT 0x02
#define UART_LCR__PEN__NONE 0x00
#define UART_LCR__PEN__ODD 0x08 // 01XXX, LCR[4:3] = 01
#define UART_LCR__PEN__EVEN 0x18 // 11XXX, LCR[4:3] = 11
#define UART_LCR__STOP__2_BIT 0x04 // XX1XX, LCR[2] = 1
#define UART_LCR__STOP__1_BIT 0x00

#define UART_IIR__IID__UMASK 0xF
#define UART_IIR__IID__THRE_EVENT 0x2
#define UART_IIR__IID__RDA_EVENT 0x4
#define UART_IIR__IID__RCTI_EVENT 0xC

#define UART_LSR__THRE__UMASK (1 << 5)
#define UART_LSR__DR__UMASK (1 << 0)

#define UART_BAUD_57600 57600
#define UART_BAUD_115200 115200
#define UART_REF_CLK_24MHZ 24000000
#define UART_REF_CLK_125MHZ 125000000

#define UART_RX_FIFO_SIZE 32
#define UART_TX_FIFO_SIZE 32

#define UART__2_WIRE 0x0
#define UART__4_WIRE 0x1

typedef struct uart_dev {
	uint32_t base_addr;
	uint32_t ref_clk_rate;
	uint32_t baud_rate;
	uint32_t enabled_interrupts;
	uint8_t mode;
} UartDev;

void uart_transmit(struct uart_dev *dev, uint32_t tx_byte_count, uint8_t *tx_buffer);

#endif /* UART_H_ */
