/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file hw_qspi.h
 * @brief qspi
 */

#ifndef HW_QSPI_H_
#define HW_QSPI_H_

//extern volatile struct csr_bank_qspi *qspi_reg;

/* error code */
#define ESUCCESS 0x0
#define ETIMEOUT 0x1
#define EFAIL 0x2
#define EPAGE 0x3
#define ECHKSUM 0x4
#define EDATA 0x5

/* Register alias */

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

/* IP definition */
/* FIFO size in byte */
#if defined(CONFIG_OSAKA)
#define QSPI_RX_FIFO_DEPTH 18
#define QSPI_TX_FIFO_DEPTH 16
#else
#define QSPI_RX_FIFO_DEPTH 16
#define QSPI_TX_FIFO_DEPTH 13 //NEED FIX (#61633)
#endif /* CONFIG_OSAKA */
#define QSPI_RX_FIFO_SIZE (QSPI_RX_FIFO_DEPTH << 2) /* FIFO_DEPTH x 4Bytes */
#define QSPI_TX_FIFO_SIZE (QSPI_TX_FIFO_DEPTH << 2)

#define pages_per_blk(x) (1 << (x))
#define pages_per_sector(x) pages_per_blk(x)
#define nand_addr_to_block(x, y, z) ((x) >> ((y) + (z)))
#define nand_addr_to_page(x, y) (x >> y)

#define QSPI_TIMEOUT_TIME 1048576

#define SINGLE_MODE 1
#define DUAL_MODE 2
#define QUAD_MODE 4

/* NAND Flash ops */

#define FLASH_SLAVE_ID 0x0

#define NAND_FLASH_A0__SP__UMASK 0x1 //Solid Protection Bit
#define NAND_FLASH_A0__CMP__UMASK 0x2 //complement bit
#define NAND_FLASH_A0__INV__UMASK 0x4 //including Inverse bit
#define NAND_FLASH_A0__BP0__UMASK 0x8 //Block Protection Bits
#define NAND_FLASH_A0__BP1__UMASK 0x10
#define NAND_FLASH_A0__BP2__UMASK 0x20
#define NAND_FLASH_A0__BP3__UMASK 0x40
#define NAND_FLASH_A0__BPRWD__UMASK 0x80 //Block Protection Register Write Disable

#define NAND_FLASH_B0__QUAD_ENABLE__UMASK 0x1
#define NAND_FLASH_B0__BUF_MODE__UMASK 0x8
#define NAND_FLASH_B0__ECC_ENABLE__UMASK 0x10
#define NAND_FLASH_B0__SR1_LOCK__UMASK 0x20
#define NAND_FLASH_B0__OTP_ENABLE__UMASK 0x40 //One Time Program
#define NAND_FLASH_B0__OTP_LOCK__UMASK 0x80

#define NAND_FLASH_C0__BUSY__UMASK 0x1
#define NAND_FLASH_C0__WEL__UMASK 0x2
#define NAND_FLASH_C0__ERASE_FAIL__UMASK 0x4
#define NAND_FLASH_C0__PROGRAM_FAIL__UMASK 0x8
#define NAND_FLASH_C0__ECC_FLAG__UMASK 0x30
#define NAND_FLASH_C0__ECC_FLAG__OK 0x00
#define NAND_FLASH_C0__ECC_FLAG__CORRECTED 0x10
#define NAND_FLASH_C0__ECC_FLAG__ERROR_SINGLE_PAGE 0x20
#define NAND_FLASH_C0__ECC_FLAG__ERROR_MULTIPLE_PAGE 0x30

#define NAND_FLASH_PAGE_SIZE 2048
#define NAND_FLASH_BLOCK_SIZE (NAND_FLASH_PAGE_SIZE * 64)

#define FLASH_ECC_SIZE 64

#define BYTES_OFFSET_2048 11
#define PAGES_OFFSET_64 6 //64
#define PAGES_OFFSET_128 7 //128

/* NAND Flash CMD */

#define NAND_FLASH_CMD__READ_ID 0x9F
#define NAND_FLASH_CMD__DEVICE_RESET 0xFF
#define NAND_FLASH_CMD__READ_STA_REG 0x0F
#define NAND_FLASH_CMD__WRITE_STA_REG 0x1F
#define NAND_FLASH_CMD__WRITE_ENABLE 0x06
#define NAND_FLASH_CMD__BLOCK_ERASE 0xD8
#define NAND_FLASH_CMD__PAGE_READ 0x13
#define NAND_FLASH_CMD__SINGLE_READ 0x0B
#define NAND_FLASH_CMD__DUAL_READ 0x3B
#define NAND_FLASH_CMD__QUAD_READ 0x6B
#define NAND_FLASH_CMD__PROG_EXEC 0x10
#define NAND_FLASH_CMD__SINGLE_PROG_PAGE_0x02 0x02
#define NAND_FLASH_CMD__SINGLE_PROG_PAGE_0x84 0x84
#define NAND_FLASH_CMD__QUAD_PROG_PAGE_0x32 0x32
#define NAND_FLASH_CMD__QUAD_PROG_PAGE_0x34 0x34

/* NOR Flash ops */

#define NOR_FLASH_SR1__BUSY__UMASK 0x1
#define NOR_FLASH_SR1__WEL__UMASK 0x2
#define NOR_FLASH_SR1__BP0__UMASK 0x4 //Block Protection Bits
#define NOR_FLASH_SR1__BP1__UMASK 0x8
#define NOR_FLASH_SR1__BP2__UMASK 0x10
#define NOR_FLASH_SR1__BP3__UMASK 0x20
#define NOR_FLASH_SR1__TB__UMASK 0x40 //Top/Bottom Block Protect
#define NOR_FLASH_SR1__SRP__UMASK 0x80

#define NOR_FLASH_SR2__SRL__UMASK 0x1
#define NOR_FLASH_SR2__QUAD_ENABLE__UMASK 0x2
#define NOR_FLASH_SR2__LB1__UMASK 0x8 //Security Register Lock Bits
#define NOR_FLASH_SR2__LB2__UMASK 0x10
#define NOR_FLASH_SR2__LB3__UMASK 0x20
#define NOR_FLASH_SR2__CMP__UMASK 0x40 //complement bit
#define NOR_FLASH_SR2__SUS__UMASK 0x80 //Suspend Status

#define NOR_FLASH_SR3__ADS__UMASK 0x1 //Current Address Mode
#define NOR_FLASH_SR3__ADP__UMASK 0x2 //Power-Up Address Mode
#define NOR_FLASH_SR3__WPS__UMASK 0x4 //Write Protect Selection

#define NOR_FLASH_PAGE_SIZE 256
#define NOR_FLASH_SECTOR_SIZE (NOR_FLASH_PAGE_SIZE * 16)
#define NOR_FLASH_BLOCK_SIZE (NOR_FLASH_SECTOR_SIZE * 16)

#define BYTES_OFFSET_4096 12
#define SECTORS_OFFSET_16 4
#define PAGES_OFFSET_256 8
#define BYTES_OFFSET_65536 16

#define NOR_3BYTE_ADDR_MODE 1
#define NOR_4BYTE_ADDR_MODE 2

/* NOR Flash CMD */

#define NOR_FLASH_CMD__READ_ID 0x9F
#define NOR_FLASH_CMD__ENABLE_RESET 0x66
#define NOR_FLASH_CMD__RESET_DEVICE 0x99
#define NOR_FLASH_CMD__WRITE_ENABLE 0x06
#define NOR_FLASH_CMD__WRITE_ENABLE_FOR_VSR 0x50
#define NOR_FLASH_CMD__READ_SR1 0x05
#define NOR_FLASH_CMD__READ_SR2 0x35
#define NOR_FLASH_CMD__READ_SR3 0x15
#define NOR_FLASH_CMD__WRITE_SR1 0x01
#define NOR_FLASH_CMD__WRITE_SR2 0x31
#define NOR_FLASH_CMD__WRITE_SR3 0x11
#define NOR_FLASH_CMD__ENTER_4BYTE 0xB7
#define NOR_FLASH_CMD__EXIT_4BYTE 0xE9
#define NOR_FLASH_CMD__SECTOR_ERASE 0x20
#define NOR_FLASH_CMD__SECTOR_ERASE_4B 0x21
#define NOR_FLASH_CMD__HALF_BLOCK_ERASE 0x52
#define NOR_FLASH_CMD__BLOCK_ERASE 0xD8
#define NOR_FLASH_CMD__BLOCK_ERASE_4B 0xDC
#define NOR_FLASH_CMD__CHIP_ERASE 0xC7
#define NOR_FLASH_CMD__SINGLE_READ 0x0B
#define NOR_FLASH_CMD__DUAL_READ 0x3B
#define NOR_FLASH_CMD__QUAD_READ 0x6B
#define NOR_FLASH_CMD__SINGLE_READ_4B 0x0C
#define NOR_FLASH_CMD__DUAL_READ_4B 0x3C
#define NOR_FLASH_CMD__QUAD_READ_4B 0x6C
#define NOR_FLASH_CMD__SINGLE_PROG_PAGE 0x02
#define NOR_FLASH_CMD__SINGLE_PROG_PAGE_4B 0x12
#define NOR_FLASH_CMD__QUAD_PROG_PAGE 0x32
#define NOR_FLASH_CMD__QUAD_PROG_PAGE_4B 0x34

#define QSPI_REF_CLK_24MHZ 24000000
#define QSPI_REF_CLK_200MHZ 200000000
#define QSPI_REF_CLK_187500KHZ 187500000
#define QSPI_IF_CLK_12MHZ 12000000
#define QSPI_IF_CLK_25MHZ 25000000
#define QSPI_IF_CLK_50MHZ 50000000
#define QSPI_IF_CLK_100MHZ 100000000
#define QSPI_IF_CLK_23437KHZ 23437500
#define QSPI_IF_CLK_46875KHZ 46875000
#define QSPI_IF_CLK_93750KHZ 93750000

typedef struct qspi_dev {
	uintptr_t base_addr;
	uint32_t ref_clk_rate;
	uint32_t qspi_clk_rate;
	uintptr_t qspir_base;
	uintptr_t qspiw_base;
} QspiDev;

uint32_t wait_qspi_transfer(struct qspi_dev *dev, uint32_t timeout, uint32_t cond_flag);

uint32_t wait_rx_fifo_ready(struct qspi_dev *dev, uint32_t timeout);

uint32_t qspi_init(struct qspi_dev *dev);

uint32_t qspi_sw_reset(struct qspi_dev *dev);

uint32_t qspi_read_id(struct qspi_dev *dev, uint32_t *id); // Opcode - 9Fh

uint32_t wait_nand_flash_ready(struct qspi_dev *dev, uint32_t timeout);

uint32_t wait_nand_flash_wel(struct qspi_dev *dev, uint32_t timeout);

uint32_t is_bad_block(struct qspi_dev *dev, uint32_t block_addr, uint32_t b_ofst, uint32_t p_ofst);

uint32_t nand_init(struct qspi_dev *dev);

uint32_t nand_reset(struct qspi_dev *dev); // Opcode - FFh

uint32_t nand_read_status(struct qspi_dev *dev, uint32_t addr, uint32_t *value_ptr); // Opcode - 0Fh

uint32_t nand_write_status(struct qspi_dev *dev, uint32_t addr, uint32_t value); // Opcode - 1Fh

uint32_t nand_write_enable(struct qspi_dev *dev); // Opcode - 06h

uint32_t nand_block_erase(struct qspi_dev *dev, uint32_t page_addr); // Opcode - D8h

uint32_t nand_normal_read(struct qspi_dev *dev, uint32_t *mem_base, uint32_t page_addr, uint32_t data_size,
                          uint32_t frame_format, uint32_t cur_pos); // normal mode - single/dual/quad read

uint32_t nand_page_read(struct qspi_dev *dev, uint32_t page); // Opcode - 13h

uint32_t nand_read(struct qspi_dev *dev, uint32_t addr, uint32_t byte_count,
                   uint32_t frame_format); // Opcode - 0B/3B/6Bh

uint32_t qspi_fifo_read(struct qspi_dev *dev, uint32_t *dst, uint32_t byte_count);

uint32_t nand_normal_write(struct qspi_dev *dev, uint32_t page_addr, uintptr_t mem_base, uint32_t data_size,
                           uint32_t frame_format); // normal mode - single/quad write

uint32_t nand_program_execute(struct qspi_dev *dev, uint32_t page); // Opcode - 10h

uint32_t nand_write(struct qspi_dev *dev, uint32_t addr, uint32_t byte_count, uint32_t *data, uint32_t flag,
                    uint32_t frame_format); // Opcode - 02/84 / 32/34h

/*nvsp use*/
uint32_t nand_normal_program(struct qspi_dev *dev, uint32_t block_base, uint32_t block_num, uint32_t page_base,
                             uintptr_t mem_base, uint32_t byte_to_write, uint32_t frame_format);

uint32_t nand_normal_erase(struct qspi_dev *dev, uint32_t block_base, uint32_t block_num);

/* dma mode */
uint32_t qspi_pre_dma_read(struct qspi_dev *dev, uint32_t dram_addr, uint32_t byte_count);

uint32_t qspi_pre_dma_write(struct qspi_dev *dev, uint32_t dram_addr, uint32_t byte_count);

uint32_t nand_dma_read(struct qspi_dev *dev, uint32_t dst, uint32_t page, uint32_t data_size, uint32_t frame_format,
                       uint32_t cur_pos); // dma mode

uint32_t nand_read_dma_en(struct qspi_dev *dev, uint32_t addr, uint32_t byte_count, uint32_t frame_format);

uint32_t nand_dma_write(struct qspi_dev *dev, uint32_t block_base, uint32_t block_num, uint32_t page_base,
                        uintptr_t mem_base, uint32_t byte_to_write, uint32_t pages_per_blk_shift,
                        uint32_t frame_format); // dma mode

uint32_t nand_write_dma_en(struct qspi_dev *dev, uint32_t addr, uint32_t byte_count, uint32_t *data, uint32_t flag,
                           uint32_t frame_format);

//==============================
//========== For  NOR ==========
//==============================

uint32_t wait_nor_flash_ready(struct qspi_dev *dev, uint32_t timeout);

uint32_t wait_nor_flash_wel(struct qspi_dev *dev, uint32_t timeout);

uint32_t nor_init(struct qspi_dev *dev);

uint32_t nor_unlock_blk_prot(struct qspi_dev *dev);

uint32_t nor_reset(struct qspi_dev *dev); // Opcode - 66h + 99h

uint32_t nor_enable_reset(struct qspi_dev *dev); // Opcode - 66h

uint32_t nor_reset_device(struct qspi_dev *dev); // Opcode - 99h

uint32_t nor_read_status(struct qspi_dev *dev, uint32_t sr_opcode,
                         uint32_t *value_ptr); // Opcode - 05h, 35h, 15h

uint32_t nor_write_status(struct qspi_dev *dev, uint32_t sr_opcode,
                          uint32_t value); // Opcode - 01h, 31h, 11h

uint32_t nor_write_enable(struct qspi_dev *dev); // Opcode - 06h

uint32_t nor_we_for_vsr(struct qspi_dev *dev); // Opcode - 50h

uint32_t nor_is_support_4byte_mode(struct qspi_dev *dev);

uint32_t nor_enter_4byte_mode(struct qspi_dev *dev); // Opcode - B7h

uint32_t nor_exit_4byte_mode(struct qspi_dev *dev); // Opcode - E9h

uint32_t nor_sector_erase(struct qspi_dev *dev, uint32_t addr, uint32_t addr_mode); // Opcode - 20h

uint32_t nor_half_block_erase(struct qspi_dev *dev, uint32_t addr,
                              uint32_t addr_mode); // Opcode - 52h

uint32_t nor_one_block_erase(struct qspi_dev *dev, uint32_t addr,
                             uint32_t addr_mode); // Opcode - D8h

uint32_t nor_chip_erase(struct qspi_dev *dev); // Opcode - C7h

uint32_t nor_normal_read(struct qspi_dev *dev, uint32_t *dst, uint32_t addr, uint32_t data_size, uint32_t addr_mode,
                         uint32_t frame_format);

uint32_t nor_read(struct qspi_dev *dev, uint32_t addr, uint32_t byte_count, uint32_t addr_mode,
                  uint32_t frame_format); // Opcode - 0B/3B/6Bh

uint32_t nor_normal_write_sector(struct qspi_dev *dev, uint32_t sector_base, uint32_t page_base, uintptr_t mem_base,
                                 uint32_t byte_to_write, uint32_t pages_per_sector_shift, uint32_t addr_mode,
                                 uint32_t frame_format); // normal mode - single/quad write

uint32_t nor_normal_write_block(struct qspi_dev *dev, uint32_t block_base, uint32_t page_base, uintptr_t mem_base,
                                uint32_t byte_to_write, uint32_t pages_per_blk_shift, uint32_t addr_mode,
                                uint32_t frame_format); // normal mode - single/quad write

uint32_t nor_write(struct qspi_dev *dev, uint32_t addr, uint32_t byte_count, uint32_t *data, uint32_t addr_mode,
                   uint32_t frame_format); // Opcode - 02/32h

/* dma mode */
uint32_t nor_dma_read(struct qspi_dev *dev, uint32_t dst, uint32_t addr, uint32_t data_size, uint32_t addr_mode,
                      uint32_t frame_format);

uint32_t nor_read_dma_en(struct qspi_dev *dev, uint32_t addr, uint32_t byte_count, uint32_t addr_mode,
                         uint32_t frame_format); // Opcode - 0B/3B/6Bh

uint32_t nor_dma_write_sector(struct qspi_dev *dev, uint32_t sector_base, uint32_t page_base, uintptr_t mem_base,
                              uint32_t byte_to_write, uint32_t pages_per_sector_shift, uint32_t addr_mode,
                              uint32_t frame_format); // dma mode

uint32_t nor_dma_write_block(struct qspi_dev *dev, uint32_t block_base, uint32_t page_base, uintptr_t mem_base,
                             uint32_t byte_to_write, uint32_t pages_per_blk_shift, uint32_t addr_mode,
                             uint32_t frame_format); // dma mode

uint32_t nor_write_dma_en(struct qspi_dev *dev, uint32_t addr, uint32_t byte_count, uint32_t *data, uint32_t addr_mode,
                          uint32_t frame_format);

void qspi_set_clk(uint32_t target_clk);

int nor_write_partition(struct qspi_dev *dev, uint32_t part_addr, uint32_t part_size, uintptr_t mem_addr,
                        uint32_t write_len, uint32_t addr_mode, uint32_t frame_format, uint32_t erase);

int nor_erase_partition(struct qspi_dev *dev, uint32_t part_addr, uint32_t part_size, uint32_t addr_mode);

int nor_write_page(struct qspi_dev *dev, uint32_t program_addr, uint8_t *mem_addr_ptr, uint32_t write_len,
                   uint32_t addr_mode, uint32_t frame_format);

int nand_read_skip_bad_block(struct qspi_dev *dev, uint32_t flash_addr, uint32_t part_size, uintptr_t mem_addr,
                             uint32_t image_size, uint32_t frame_format);

#endif
