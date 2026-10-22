/**
 * @file cm_memory.c
 * @brief OSAKA W33 CM0/CM4 Baremetal Memory Testing
 * 
 * Memory test functions for available CM0/CM4 shared memory regions
 * 
 * AVAILABLE MEMORY REGIONS (from memory_map.h):
 * - D-RAM (CM4D_RAM):  0x0F0008000 (32KB) - CM0/CM4 shared data memory
 * - SYSRAM (CM4S_RAM): 0x0F0010000 (32KB) - CM0/CM4 shared system memory
 * - fw.bin location:   0x00000000 (32KB)  - Firmware location (via hardware remap)
 * 
 * 
 * Core Status Values (from memory_map.h):
 * - CORE_STATUS_INITIALIZING (0x10000000): Core initializing
 * - CORE_STATUS_READY (0x20000000): Core initialized and ready
 * - CORE_STATUS_ERROR (0xFEFEFEFE): Core error or unknown type
 * 
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <stdint.h>
#include "memory_map.h"

/**
 * @brief Safe memory read with compiler warning suppression
 * @param addr Memory address to read from
 * @return 32-bit value read from memory
 */
uint32_t mem_read(uint32_t addr)
{
	volatile uint32_t *ptr = (volatile uint32_t *)addr;
	return *ptr;
}

/**
 * @brief Safe memory write operation
 * @param addr Memory address to write to
 * @param value 32-bit value to write
 */
void mem_write(uint32_t addr, uint32_t value)
{
	volatile uint32_t *ptr = (volatile uint32_t *)addr;
	*ptr = value;
}

/**
 * @brief Byte-by-byte memory comparison
 * @param addr Memory address to read from
 * @param expected_value Expected 32-bit value
 * @return 1 if match, 0 if no match
 */
int mem_cmp(uint32_t addr, uint32_t expected_value)
{
	volatile uint8_t *mem_ptr = (volatile uint8_t *)addr;
	uint8_t *expected_ptr = (uint8_t *)&expected_value;

	for (int i = 0; i < 4; i++) {
		if (mem_ptr[i] != expected_ptr[i]) {
			return i + 1;
		}
	}
	return 0;
}

/**
 * @brief Reset CM4S RAM region to zero
 * @param base_addr Base address of CM4S RAM region
 * @param size Size of memory region to reset (0x8000 = 32KB)
 */
void reset_CM4S_RAM(void)
{
	volatile uint32_t *ptr = (volatile uint32_t *)OSAKA_CM4S_RAM_BASE;
	uint32_t word_count = CM_MEMORY_REGION_SIZE >> 2;

	for (uint32_t i = 0; i < word_count; i++) {
		ptr[i] = 0;
	}
}

/**
 * @brief Reset CM4D RAM region to zero  
 * @param base_addr Base address of CM4D RAM region
 * @param size Size of memory region to reset (0x8000 = 32KB)
 */
void reset_CM4D_RAM(void)
{
	volatile uint32_t *ptr = (volatile uint32_t *)OSAKA_CM4D_RAM_BASE;
	uint32_t word_count = CM_MEMORY_REGION_SIZE >> 2;

	for (uint32_t i = 0; i < word_count; i++) {
		ptr[i] = 0;
	}
}
