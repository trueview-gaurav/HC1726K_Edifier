/*
 * AUGENTIX INC. - OPEN-SOURCE UNDER GPL LICENSE
 *
 * spi_hc18xx.c - SPI hardware operations
 * Copyright 2018 ShihChieh Lin, Augentix Inc. <shihchieh.lin@augentix.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, incorporated herein by reference.
 *
 * * Brief: SPI hardware operations
 * *
 * * Author: ShihChieh Lin
 */

#include "spi_hc18xx.h"

/* Debugging GPIO interface */
extern int hc_trigger_gpio(int pin_id, int level);

inline u32 spi_reg_readl(void __iomem *base, u32 offset)
{
	return __raw_readl(base + offset);
}

inline u16 spi_reg_readw(void __iomem *base, u32 offset)
{
	return __raw_readw(base + offset);
}

inline void spi_reg_writel(void __iomem *base, u32 offset, u32 val)
{
	__raw_writel(val, base + offset);
}

inline void spi_reg_writew(void __iomem *base, u32 offset, u16 val)
{
	__raw_writew(val, base + offset);
}

void spi_set_clkdiv(void __iomem *base, u32 div)
{
	spi_reg_writel(base, SPI_BAUDR, div);
}

static void __spi_switch(void __iomem *base, int enable)
{
	spi_reg_writel(base, SPI_SSIENR, enable);
}

void spi_enable(void __iomem *base)
{
	__spi_switch(base, 1);
}

void spi_disable(void __iomem *base)
{
	__spi_switch(base, 0);
}

void spi_shutdown(void __iomem *base)
{
	spi_disable(base);
	spi_set_clkdiv(base, 0);
}

void spi_init_ssi(void __iomem *base)
{
	spi_disable(base);
	spi_reg_writel(base, SPI_SER,    0);
	spi_reg_writel(base, SPI_BAUDR,  2);
	spi_reg_writel(base, SPI_IMR,    0);
	spi_reg_writel(base, SPI_TXFTLR, SPI_TX_FIFO_SIZE - 1);
	spi_reg_writel(base, SPI_RXFTLR, SPI_RX_FIFO_SIZE - 1);

	spi_reg_writel(base, SPI_CTRLR0,
	        CTRLR0__SPIFRF__SSPI  | CTRLR0__DFS_32__8_BIT |
	        CTRLR0__TMOD__TX_ONLY | CTRLR0__FRF__SPI );
	spi_reg_writel(base, SPI_CTRLR1, 0);
	spi_reg_writel(base, SPI_SPICTRLR0,
	        SPICTRLR0__WAIT__0_CYCLE | SPICTRLR0__INST_L__8_BIT |
		SPICTRLR0__ADDR_L__8_BIT);
	spi_enable(base);
	spi_reg_writel(base, SPI_SER, 1);
}
/*
int spi_writel(void __iomem *base, uint32_t value)
{
	spi_reg_writel(base, SPI_DR, value);
	return 0;
}
*/
int spi_writeb(void __iomem *base, uint8_t value)
{
	spi_reg_writel(base, SPI_DR, value);
	return 0;
}
