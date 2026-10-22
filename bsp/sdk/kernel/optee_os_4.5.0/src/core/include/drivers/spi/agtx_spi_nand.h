#ifndef __DRIVERS_AGTX_SPI_NAND_H
#define __DRIVERS_AGTX_SPI_NAND_H

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
#define PAGES_OFFSET_64 6
#define PAGES_OFFSET_128 7

#define NAND_SECTOR_SIZE 512

#define NAND_SR1_ADDR 0xA0
#define NAND_SR2_ADDR 0xB0
#define NAND_SR3_ADDR 0xC0

#define NAND_MAX_PART_PROG_TIMES 4

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

uint32_t agtx_wait_nand_ready(uint32_t timeout);
uint32_t agtx_nand_is_bad_block(uint32_t block_addr, uint32_t b_ofst, uint32_t p_ofst);
uint32_t agtx_nand_page_read(uint32_t page_addr);
uint32_t agtx_nand_read(uint32_t byte_offset, uint32_t byte_count);
uint32_t agtx_nand_normal_read(uint32_t *dst, uint32_t addr, uint32_t data_size);
uint32_t agtx_nand_read_id(uint8_t *id);
uint32_t agtx_nand_read_status(uint8_t sr_addr, uint32_t *value_ptr);
uint32_t agtx_nand_write_status(uint8_t sr_addr, uint32_t value);
uint32_t agtx_nand_write_enable(void);
uint32_t agtx_nand_normal_erase(uint32_t addr, uint32_t size);
uint32_t agtx_nand_write(const uint32_t *data, uint32_t byte_offset, uint32_t byte_count, bool had_written);
uint32_t agtx_nand_program(uint32_t page_addr);
uint32_t agtx_nand_normal_write(const uint32_t *data, uint32_t addr, uint32_t byte_count);

#endif /* __DRIVERS_AGTX_SPI_NAND_H */
