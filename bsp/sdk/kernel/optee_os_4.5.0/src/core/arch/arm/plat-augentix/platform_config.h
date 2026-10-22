/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

#include <mm/generic_ram_layout.h>

#define STACK_ALIGNMENT 64

#define CPU_FREQ 996000000

#define TZASC_BASE 0x80271000

#define SYSCONF_BASE 0xFFE00000
#define SYSRAM_MAX_SIZE 0x8000
#define EB_CONTROL_BASE 0x80100000

#define GIC_BASE 0x84000000
#define GICC_OFFSET 0x2000
#define GICD_OFFSET 0x1000
#define GIC_CPU_BASE (GIC_BASE + GICC_OFFSET)
#define GIC_DIST_BASE (GIC_BASE + GICD_OFFSET)

#define CONSOLE_UART_BASE 0x80830000

#define CONSOLE_WDT_BASE 0x80300800

#define PLATFORM_CONTROL_BASE 0x80000000
#define DDRPHY_BASE 0x81840000

/* chip_reset_gen registers (base = PLATFORM_CONTROL_BASE + 0x400) */
#define CHIP_RESET_GEN_BASE    (PLATFORM_CONTROL_BASE + 0x400)
#define W1P_CPU_OFFSET         0x10
#define LV_CPU_OFFSET          0x74
#define CPU_COREPOR1_BIT       (1 << 2)
#define CPU_CORE1_BIT          (1 << 6)

#define SECONDARY_ENTRY_WAKE_ADDR 0x80000814
#define CHIPID_BACKUP 0x83630034
#ifdef CFG_TEE_LOAD_ADDR
#define TEE_LOAD_ADDR CFG_TEE_LOAD_ADDR
#else
#define TEE_LOAD_ADDR TEE_RAM_START
#endif

#endif /*PLATFORM_CONFIG_H*/
