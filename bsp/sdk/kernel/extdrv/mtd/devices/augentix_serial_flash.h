#ifndef __LINUX_SPI_AGTX_SPI_H
#define __LINUX_SPI_AGTX_SPI_H

#define AGTX_SPI_TMOD_RO 0x0 /* recv only */
#define AGTX_SPI_TMOD_TO 0x1 /* xmit only */

#define AGTX_QSPI_FRF__SSPI 0x0
#define AGTX_QSPI_FRF__DSPI 0x1
#define AGTX_QSPI_FRF__QSPI 0x2

#define AGTX_QSPI_DFS__4_BIT 0x3
#define AGTX_QSPI_DFS__8_BIT 0x7
#define AGTX_QSPI_DFS__16_BIT 0xF
#define AGTX_QSPI_DFS__32_BIT 0x1F

#define AGTX_SPI_NDF_OFFSET 0
#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
#define AGTX_SPI_NDFW_OFFSET 16
#endif

#define AGTX_QSPI_DMA_M__DIS 0
#define AGTX_QSPI_DMA_M__EN 1

#if defined(CONFIG_OSAKA)
#define AGTX_QSPI_INST_L_OFFSET 0
#define AGTX_QSPI_ADDR_L_OFFSET 8
#define AGTX_QSPI_WAIT_1_L_OFFSET 16
#define AGTX_QSPI_WAIT_L_OFFSET 24
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define AGTX_QSPI_INST_L_OFFSET 0
#define AGTX_QSPI_ADDR_L_OFFSET 8
#define AGTX_QSPI_WAIT_L_OFFSET 16
#else
#define AGTX_QSPI_INST_L_OFFSET 16
#define AGTX_QSPI_ADDR_L_OFFSET 18
#define AGTX_QSPI_WAIT_L_OFFSET 24
#endif // CONFIG_SAPPORO

#define AGTX_QSPI_INST_L__8_BIT 0x2

/* Slave spi_dev related */
struct chip_data {
#define SPI_TMOD_TR 0x0 /* xmit & recv */
#define SPI_TMOD_TO 0x1 /* xmit only */
#define SPI_TMOD_RO 0x2 /* recv only */
#define SPI_TMOD_EPROMREAD 0x3 /* eeprom read mode */
	u8 bDFS_32; /*default 0*/
	u8 bQualSPI; /*default 0*/
	u32 rx_sample_dly; /*default = 1*/
	u32 cr1;
	u32 spi_cr0;
	u32 clk_div; /* baud rate divider */
	u32 speed_hz; /* baud rate */
	void (*cs_control)(u32 command);
	u8 poll_mode; /* 1 means use poll mode */
	u32 enable_ssi_controller;
	u8 data_frame_size;
	u8 dma_mode;
	u8 tmode;
	u8 frame_format;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	u32 ndf;
#else
	u16 ndf;
	u16 ndfw;
#endif
	u32 bits_per_word;
	u32 inst_set;
};
#endif /* __LINUX_SPI_AGTX_SPI_H */
