/*
 * (C) Copyright 2010
 * Reinhard Meyer, reinhard.meyer@emk-elektronik.de
 * (C) Copyright 2009
 * Jean-Christophe PLAGNIOL-VILLARD <plagnioj@jcrosoft.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/global_data.h>
#include <asm/armv8/mmu.h>
#include "address_map.h"
#include "wdt/hw_wdt.h"

#ifndef CONFIG_SYS_AUGENTIX_MAIN_CLOCK
#define CONFIG_SYS_AUGENTIX_MAIN_CLOCK 24000000
#endif

/* Minimum size unit is 2MB, or it will hang when enalbe mmu */
static struct mm_region osaka_mem_map[] = {
	{ .base = CONFIG_SYS_SDRAM_BASE,
	  .size = CONFIG_SYS_SDRAM_SIZE,
	  .attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_INNER_SHARE },
	/* module region */
	{ .base = 0x80000000UL,
	  .size = 0x10000000UL,
	  .attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN },
	/* GIC region */
	{ .base = 0xA0000000UL,
	  .size = 0x10000000UL,
	  .attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN },
	/* SYSRAM region */
	{ .base = 0xF0000000UL, .size = 0x10000000UL, .attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_INNER_SHARE },
	{
	        /* List terminator */
	        0,
	}
};
struct mm_region *mem_map = osaka_mem_map;

void tlb_init(void)
{
	DECLARE_GLOBAL_DATA_PTR;
	gd->arch.tlb_size = PGTABLE_SIZE;
	gd->arch.tlb_addr = 0x1FFF0000;
}

void enable_caches(void)
{
	tlb_init();
#ifndef CONFIG_SYS_ICACHE_OFF
	icache_enable();
#endif
#ifndef CONFIG_SYS_DCACHE_OFF
	dcache_enable();
#endif
}

int arch_cpu_init(void)
{
	return 0;
}

void arch_preboot_os(void)
{
}

#ifdef CONFIG_SPL_BUILD
void panic(const char *fmt, ...)
{
	while (1)
		;
}

void hang(void)
{
	while (1)
		;
}

#else
extern void hw_watchdog_reboot(void);
void reset_cpu(ulong ignored)
{
	hw_watchdog_reboot();
	/* never reached */
	while (1)
		;
}
#endif

#if defined(CONFIG_DISPLAY_CPUINFO)
int print_cpuinfo(void)
{
	return 0;
}
#endif
