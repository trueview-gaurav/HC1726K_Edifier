#ifndef __DRIVERS_AGTX_SPI_NOR_H
#define __DRIVERS_AGTX_SPI_NOR_H

#include <drivers/spi/agtx_spi.h>

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
#define NOR_FLASH_CMD__WRITE_DISABLE 0x04
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

uint32_t agtx_wait_nor_flash_ready(uint32_t timeout);
uint32_t agtx_nor_read_status(uint32_t sr_opcode, uint32_t *value_ptr);
uint32_t agtx_nor_read_id(uint8_t *id);
uint32_t agtx_nor_erase_partition(uint32_t addr, uint32_t size);
uint32_t agtx_nor_normal_read(uint32_t *dst, uint32_t addr, uint32_t data_size);
uint32_t agtx_nor_write_enable(void);
uint32_t agtx_nor_normal_write(uint32_t addr, uint32_t byte_count, const uint32_t *data);
uint32_t agtx_nor_write_status(uint32_t sr_opcode, uint32_t value);

#endif /* __DRIVERS_AGTX_SPI_NOR_H */
