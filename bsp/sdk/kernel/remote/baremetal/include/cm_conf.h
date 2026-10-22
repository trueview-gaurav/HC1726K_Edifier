/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CM_CONF_H
#define CM_CONF_H

#include <stdint.h>
#include "memory_map.h"

/* CMSIS System Control Block */
#define SCB_CPUID_ADDR 0xE000ED00 /* CPUID register */
#define SCB_VTOR_ADDR 0xE000ED08 /* Vector Table Offset Register */

#define CORTEX_M0_PARTNO 0xC20 /* CM0 part number */
#define CORTEX_M4_PARTNO 0xC24 /* CM4 part number */

#define SCB_CPUID (*(volatile uint32_t *)SCB_CPUID_ADDR)
#define SCB_CPUID_PARTNO_Pos 4U
#define SCB_CPUID_PARTNO_Msk (0xFFF << SCB_CPUID_PARTNO_Pos)

/* CM0/CM4 Core Status */
#define CORE_STATUS_RESET 0x00000000
#define CORE_STATUS_INITIALIZING 0x10000000
#define CORE_STATUS_READY 0x20000000
#define CORE_STATUS_ERROR 0xDEADBEEF

/* CSR Test Register Addresses */
#define CSR_SYSCFG_BASE 0x82000800 /* SYSCFG - System configuration register */
#define CSR_PIOC_BASE 0x82010000 /* PIOC - PIO control register */
#define CSR_GPIOC_BASE 0x82010400 /* GPIOC - GPIO control register */

/* Shared Memory Magic Number */
#define CA7_IPC_MAGIC 0xCA70CA74

/* Error Status Encoding */
#define ERROR_STATUS_BASE 0xEFEFEFE0 /* Error status base pattern */
#define ERROR_MEM_BIT 0 /* Memory test result bit */
#define ERROR_CSR_BIT 1 /* CSR test result bit */
#define ERROR_FW_BIT 2 /* Firmware test result bit */
#define ERROR_CORE_BIT 3 /* Core type bits (3 bits) */

uint32_t core_detect(void);
uint32_t get_cpuid_raw(void);
void update_cpuinfo(void);

void cm_delay(uint32_t slots);

/* Memory Access Functions */
uint32_t mem_read(uint32_t addr);
void mem_write(uint32_t addr, uint32_t value);
int mem_cmp(uint32_t addr, uint32_t expected_value);

/* Memory Reset Functions */
void reset_CM4S_RAM(void);
void reset_CM4D_RAM(void);

/* Core Status Management */
void update_core_status(uint32_t status);
uint32_t get_core_status(void);

/* CSR Functions */
uint32_t csr_read(uint32_t addr);
void csr_write(uint32_t addr, uint32_t value);
void test_csr(void);

#endif /* CM_CONF_H */