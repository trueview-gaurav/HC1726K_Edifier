/*
 * Configuration settings for augentix products.
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __AUGENTIX_COMMON_CONFIG_H
#define __AUGENTIX_COMMON_CONFIG_H

/* Kconfig autoconf.h is force-included ahead of this file. */
#ifdef CONFIG_FASTBOOT
#error CONFIG_FASTBOOT conflict with upstream: use CONFIG_AUGENTIX_FASTBOOT
#endif
#ifdef CONFIG_OPTEE
#error CONFIG_OPTEE conflict with upstream: use CONFIG_AUGENTIX_OPTEE
#endif

/* Refers to SDK top-level config */
#ifdef __has_include
#if !__has_include("../../../../top/include/common/config.h")
#error SDK layout missing: this header needs sdk/top/include/common/config.h
#endif
#endif
#include "../../../../top/include/common/config.h"

#undef CONFIG_FASTBOOT
#undef CONFIG_OPTEE

#include <asm/arch/augentix_address_map.h>

#ifdef CONFIG_FPGA
#define UART_CLOCK (12000000)
#elif defined(CONFIG_AUGENTIX_SOC_SAPPORO)
#define UART_CLOCK (199200000)
#elif defined(CONFIG_AUGENTIX_SOC_OSAKA)
#define UART_CLOCK (200000000)
#elif defined(CONFIG_AUGENTIX_SOC_KYOTO)
#define UART_CLOCK (125000000)
#else
#define UART_CLOCK (24000000)
#warning "This UART_CLOCK is not supported"
#endif

#if !defined(CONFIG_AUGENTIX_SOC_KYOTO)
#define CFG_SYS_NS16550_CLK UART_CLOCK
#endif

/* DRAM */
#define CFG_SYS_SDRAM_BASE 0x00000000
#define CFG_SYS_SDRAM_SIZE (CONFIG_DRAM_CAPACITY << 20)

/* Pre-relocation stack ends at the old UBOOT_END_ADDR, 0x00080000 */
#define CFG_SYS_INIT_RAM_ADDR 0x00040000
#define CFG_SYS_INIT_RAM_SIZE 0x00040000

/* Enable U-Boot IRQ support */
#ifndef CFG_STACKSIZE_IRQ
#define CFG_STACKSIZE_IRQ (64 * 1024)
#endif

/* CNTFRQ reads 0 on this silicon.
 * The arch timer rate is stated here.
 * LOOPS_PER_JIFFY is that rate over HZ.
 * nor.env substitutes the value as text, never an expression.
 */
#if defined(CONFIG_CPU_LOW_SPEED)
#define CFG_SYS_HZ_CLOCK 450000000
#define LOOPS_PER_JIFFY 4500000
#elif defined(CONFIG_AUGENTIX_SOC_SAPPORO) || defined(CONFIG_AUGENTIX_SOC_OSAKA)
#define CFG_SYS_HZ_CLOCK 891000000
#define LOOPS_PER_JIFFY 8910000
#elif defined(CONFIG_AUGENTIX_SOC_KYOTO)
#define CFG_SYS_HZ_CLOCK 1008000000
#define LOOPS_PER_JIFFY 10080000
#elif defined(CONFIG_ARCH_AUGENTIX)
#error unhandled AUGENTIX_SOC: state CFG_SYS_HZ_CLOCK and LOOPS_PER_JIFFY
#endif

/* Boot flash layout */
#define FLASH_CAPACITY_MB CONFIG_AUGENTIX_FLASH_CAPACITY_MB

#ifdef CONFIG_AUGENTIX_OPTEE
#define TEE_0_FLASH_START CONFIG_AUGENTIX_TEE_0_OFFSET
#define TEE_1_FLASH_START CONFIG_AUGENTIX_TEE_1_OFFSET
#define TEE_SIZE CONFIG_AUGENTIX_TEE_SIZE
/* The TEE runs in the DRAM hidden from the kernel. */
#define TEE_ADDR ((CONFIG_DRAM_CAPACITY << 20) - CONFIG_SYS_MEM_TOP_HIDE)
#endif

#endif
