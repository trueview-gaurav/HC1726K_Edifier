/*
 * AUGENTIX INC. - OPEN-SOURCE UNDER GPL LICENSE
 *
 * spi_hc18xx.h - Tokyo SPI declarations
 * Copyright 2018 ShihChieh Lin, Augentix Inc. <shihchieh.lin@augentix.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, incorporated herein by reference.
 *
 * * Brief: Tokyo SPI register and information
 * *
 * * Author: ShihChieh Lin
 */
#ifndef SPI_HC18XX_H
#define SPI_HC18XX_H

#include <linux/io.h>

/* Register offsets */
#define SPI_CTRLR0    0x00
#define SPI_CTRLR1    0x04
#define SPI_SSIENR    0x08
#define SPI_MWCR      0x0C
#define SPI_SER       0x10
#define SPI_BAUDR     0x14
#define SPI_TXFTLR    0x18
#define SPI_RXFTLR    0x1C
#define SPI_TXFLR     0x20
#define SPI_RXFLR     0x24
#define SPI_SR        0x28
#define SPI_IMR       0x2C
#define SPI_ISR       0x30
#define SPI_RISR      0x34
#define SPI_TXOICR    0x38
#define SPI_RXOICR    0x3C
#define SPI_RXUICR    0x40
#define SPI_MSTICR    0x44
#define SPI_ICR       0x48
#define SPI_DMACR     0x4C
#define SPI_DMATDLR   0x50
#define SPI_DMARDLR   0x54
#define SPI_IDR       0x58
#define SPI_VERSION   0x5C
#define SPI_DR        0x60
#define SPI_RXSAMDLY  0xF0
#define SPI_SPICTRLR0 0xF4
#define SPI_RDR       0x260

#define HW_SSI_FIFO_DEPTH 16

/* SPI register bitfield offsets and masks */

#define SPI_DFS_OFFSET     0
#define SPI_FRF_OFFSET     4
#define SPI_SCPH_OFFSET    6
#define SPI_SCOL_OFFSET    7
#define SPI_TMOD_OFFSET    8
#define SPI_DFS_32_OFFSET  16
#define SPI_SPIFRF_OFFSET  21
#define SPI_MODE_OFFSET    6

//type
#define SPI_FRF_SPI        0x0
#define SPI_FRF_SSP        0x1
#define SPI_FRF_MICROWIRE  0x2
#define SPI_FRF_RESV       0x3

/*
 * CTRLR0
 */

/* FRF */
#define CTRLR0__FRF__SPI (0x0 << SPI_FRF_OFFSET)
#define CTRLR0__FRF__SSP (0x1 << SPI_FRF_OFFSET)
#define CTRLR0__FRF__MW  (0x2 << SPI_FRF_OFFSET)

/* TMOD */
#define CTRLR0__TMOD__TX_RX       (0x0 << SPI_TMOD_OFFSET)
#define CTRLR0__TMOD__TX_ONLY     (0x1 << SPI_TMOD_OFFSET)
#define CTRLR0__TMOD__RX_ONLY     (0x2 << SPI_TMOD_OFFSET)
#define CTRLR0__TMOD__EEPROM_READ (0x3 << SPI_TMOD_OFFSET)

/* DFS */
#define CTRLR0__DFS_32__8_BIT   (0x07 << SPI_DFS_32_OFFSET)
#define CTRLR0__DFS_32__16_BIT  (0x0F << SPI_DFS_32_OFFSET)
#define CTRLR0__DFS_32__32_BIT  (0x1F << SPI_DFS_32_OFFSET)

/* SPIFRF */
#define CTRLR0__SPIFRF__SSPI   (0x0 << SPI_SPIFRF_OFFSET)
#define CTRLR0__SPIFRF__DSPI   (0x1 << SPI_SPIFRF_OFFSET)
#define CTRLR0__SPIFRF__QSPI   (0x2 << SPI_SPIFRF_OFFSET)

/*
 * SPICTRLR0
 */

#define SPICTRLR0__WAIT__0_CYCLE (0x0 << 11)
#define SPICTRLR0__WAIT__8_CYCLE (0x8 << 11)

#define SPICTRLR0__INST_L__8_BIT (0x2 << 8)

#define SPICTRLR0__ADDR_L__24_BIT (0x6 << 2)
#define SPICTRLR0__ADDR_L__16_BIT (0x4 << 2)
#define SPICTRLR0__ADDR_L__8_BIT  (0x2 << 2)

/*
 * SR
 */
#define SR__RFF__UMASK  (1 << 4)
#define SR__TFE__UMASK  (1 << 2)
#define SR__BUSY__UMASK (1 << 0)

#define SPI_RX_FIFO_SIZE 0x10
#define SPI_TX_FIFO_SIZE 0x10

#define RX_SAMPLE_DELAY    1

void spi_set_clkdiv(void __iomem *base, u32 div);
void spi_enable(void __iomem *base);
void spi_disable(void __iomem *base);
void spi_shutdown(void __iomem *base);

void spi_init_ssi(void __iomem *base);
int spi_writeb(void __iomem *base, uint8_t value);

#endif /* SPI_HC18XX_H */
