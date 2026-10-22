/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __DRIVERS_AGTX_SPI_H
#define __DRIVERS_AGTX_SPI_H

#include <initcall.h>
#include <types_ext.h>
#include <drivers/spi/agtx_spi_nor.h>
#include <drivers/spi/agtx_spi_nand.h>
#include <drivers/spi/csr_bank_qspi.h>
#include <drivers/spi/csr_bank_qspir.h>

struct agtx_qspi_data {
	vaddr_t qspi_base;
	vaddr_t qspir_base;
	// vaddr_t qspiw_base;
	/* Word 4 (QSPI_IRQ_MASK) */
	uint32_t irq_mask;
	/* Word 7 (QSPI_TRANS_CTRL_0) fields */
	// uint8_t tmode;
	// uint8_t dma_mode;
	uint8_t frame_format;
	/* Word 9 (QSPI_DATA_FORMAT) fields */
	// uint8_t addr_l;
};

#define QSPI_BASE 0x83610000
#define QSPI_SIZE 0x00001000
#define QSPIR_BASE 0x83620000
#define QSPIR_SIZE 0x00001000
#define QSPIW_BASE 0x83630000
#define QSPIW_SIZE 0x00001000

/* error code */
#define ESUCCESS 0x0
#define ETIMEOUT 0x1
#define EFAIL 0x2
#define EPAGE 0x3
#define ECHKSUM 0x4
#define EDATA 0x5
#define EBADBLOCK 0x6

/* transfer mode */
#define QSPI_TMOD__READ 0
#define QSPI_TMOD__WRITE 1

/* frame format */
#define QSPI_FRF__SSPI 0x0
#define QSPI_FRF__DSPI 0x1
#define QSPI_FRF__QSPI 0x2

/* data frame size */
#define QSPI_DFS__4_BIT 0x3
#define QSPI_DFS__8_BIT 0x7
#define QSPI_DFS__16_BIT 0xF
#define QSPI_DFS__24_BIT 0x17
#define QSPI_DFS__32_BIT 0x1F

/* msb first */
#define QSPI_FMT__LSB_FIRST 0
#define QSPI_FMT__MSB_FIRST 1

/* endian sel */
#define QSPI_SEL__L_ENDIAN 0
#define QSPI_SEL__B_ENDIAN 1

/* transfer type */
#define QSPI_TTYPE__SPI_SPI 0x0
#define QSPI_TTYPE__SPI_FRF 0x1
#define QSPI_TTYPE__FRF_FRF 0x2

/* instruction length */
#define QSPI_INST_L__4_BIT 0x1
#define QSPI_INST_L__8_BIT 0x2
#define QSPI_INST_L__16_BIT 0x3

/* address length */
#define QSPI_ADDR_L__0_BIT 0x0
#define QSPI_ADDR_L__4_BIT 0x1
#define QSPI_ADDR_L__8_BIT 0x2
#define QSPI_ADDR_L__12_BIT 0x3
#define QSPI_ADDR_L__16_BIT 0x4
#define QSPI_ADDR_L__20_BIT 0x5
#define QSPI_ADDR_L__24_BIT 0x6
#define QSPI_ADDR_L__28_BIT 0x7
#define QSPI_ADDR_L__32_BIT 0x8

/* wait length */
#define QSPI_WAIT_L__0_CYCLE 0x0
#define QSPI_WAIT_L__8_CYCLE 0x8

/* dma mode selection */
#define QSPI_DMA_M__DIS 0
#define QSPI_DMA_M__EN 1

#define QSPI_WAIT_DONE 0x01

#define QSPI_IRQ_MASK 0x10
#define QSPI_SCK_GATING_FUNC_CTRL U(0x48)
/* Bit fields in QSPI_SCK_GATING_FUNC_CTRL (#91613) */
#define OFFSET_SCK_WR_STATE_GATING_EN 0
#define SPI_LOCK_FLAG_OPTEE 0x1

#define QSPI_DEBUG_MON_SEL U(0x4C)
/* Bit fields in QSPI_DEBUG_MON_SEL (#91613) */
#define SPI_LOCK_FLAG_LINUX 0x1

#define QSPIR_RESERVED U(0x34)
/* Bit field in QSPIR LR032_13 */
#define SPI_LOCK_TURN_OPTEE 0x0
#define SPI_LOCK_TURN_LINUX 0x1

/* IP definition */
/* FIFO size in byte */
#define QSPI_RX_FIFO_DEPTH 16
/* instruction (1-byte) + address (4-byte) == 5 bytes ===> 2 word */
#define QSPI_TX_FIFO_DEPTH (16 - 2)
#define QSPI_RX_FIFO_SIZE (QSPI_RX_FIFO_DEPTH << 2) /* FIFO_DEPTH x 4Bytes */
#define QSPI_TX_FIFO_SIZE (QSPI_TX_FIFO_DEPTH << 2)

#define pages_per_blk(x) (1 << (x))
#define pages_per_sector(x) pages_per_blk(x)
#define nand_addr_to_block(x, y, z) ((x) >> ((y) + (z)))
#define nand_addr_to_page(x, y) ((x) >> (y))

#define QSPI_TIMEOUT_TIME 1048576

#define SINGLE_MODE 1
#define DUAL_MODE 2
#define QUAD_MODE 4

TEE_Result agtx_qspi_init(void);
struct agtx_qspi_data *agtx_get_qspi_data(void);
uint32_t agtx_set_spi_lock_flag(void);
uint32_t agtx_unset_spi_lock_flag(void);
uint32_t agtx_wait_qspi_transfer(uint32_t timeout, uint32_t cond_flag);
uint32_t agtx_qspi_fifo_read(uint32_t *dst, uint32_t byte_count);
void agtx_show_spi_csr_status(void);
void agtx_clear_done_irq(void);
bool agtx_spi_is_busy(void);
bool agtx_spi_rx_fifo_empty(void);
bool agtx_spi_tx_fifo_empty(void);

#endif /* __DRIVERS_AGTX_SPI_H */
