/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include "address_map.h"

/* CM Memory Physical Addresses */
#define OSAKA_CM4I_RAM_BASE 0xF0000000 /* CM4 Instruction RAM (32KB) */
#define OSAKA_CM4D_RAM_BASE 0xF0008000 /* CM4 Data RAM (32KB) */
#define OSAKA_CM4S_RAM_BASE 0xF0010000 /* CM4 Stack RAM (32KB) */
#define OSAKA_CM0_ROM_BASE 0xF0018000 /* CM0 ROM (32KB) */

#define CM_MEMORY_REGION_SIZE 0x8000
#define SYS_RAM_SIZE 0x8000

#define CM0_RESET_CTRL_REG 0x82000488 /* CM0 reset control */
#define CM4_RESET_CTRL_REG 0x82000484 /* CM4 reset control */
#define CM_RESET_RELEASE_MASK 0x00000000 /* BIT(0)=0 && BIT(1)=0 */

#define FIRMWARE_START_ADDR 0x00000000
#define FIRMWARE_MAX_SIZE SYS_RAM_SIZE

/* Shared memory in DRAM - after stack region (stack: 0x20000000-0x20002000) */
#define SHARED_MEM_BASE 0xF000F000
#define SHARED_MEM_CM0CA7 0xF000F800
#define SHARED_MEM_CM4CA7 0xF000F804

/* Status registers using CPU CSR scratch area for faster access */
#define CMX_STATUS_BASE (OSAKA_CM4S_RAM_BASE + 0x800) /* 0xF0010800 */

#define CM0_STATUS_ADDR (CMX_STATUS_BASE + 0x00) /* CM0 status (4 bytes) */
#define CM4_STATUS_ADDR (CMX_STATUS_BASE + 0x04) /* CM4 status (4 bytes) */
#define CM0_INFO_ADDR (CMX_STATUS_BASE + 0x08) /* CM0 info (4 bytes) */
#define CM4_INFO_ADDR (CMX_STATUS_BASE + 0x0C) /* CM4 info (4 bytes) */
#define CM0_LOOP_STATUS (CMX_STATUS_BASE + 0x10) /* CM0 main loop status (4 bytes) */
#define CM4_LOOP_STATUS (CMX_STATUS_BASE + 0x14) /* CM4 main loop status (4 bytes) */
#define CM0_IPC_STATUS (CMX_STATUS_BASE + 0x20) /* IPC status (4 bytes) */
#define CM4_IPC_STATUS (CMX_STATUS_BASE + 0x24) /* IPC status (4 bytes) */

/* CSR Status Test Results - using CPU CSR scratch area */
#define CSR_SYSCFG_RESULT (CMX_STATUS_BASE + 0x40) /* SYSCFG read result */
#define CSR_PIOC_RESULT (CMX_STATUS_BASE + 0x44) /* PIOC read result */
#define CSR_GPIOC_RESULT (CMX_STATUS_BASE + 0x48) /* GPIOC read result */

#endif /* MEMORY_MAP_H_ */
