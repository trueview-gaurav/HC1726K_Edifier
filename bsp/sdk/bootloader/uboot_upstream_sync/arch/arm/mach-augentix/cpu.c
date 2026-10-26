/*
 * (C) Copyright 2010
 * Reinhard Meyer, reinhard.meyer@emk-elektronik.de
 * (C) Copyright 2009
 * Jean-Christophe PLAGNIOL-VILLARD <plagnioj@jcrosoft.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/cache.h>
#include <asm/global_data.h>
#include "address_map.h"

#ifndef CONFIG_SYS_AUGENTIX_MAIN_CLOCK
#define CONFIG_SYS_AUGENTIX_MAIN_CLOCK 24000000
#endif

#ifdef CONFIG_SPL_BUILD
void hang(void)
{
	while (1)
		;
}
#endif

void dram_bank_mmu_setup(int bank)
{
	unsigned int i;

	/* Enable SDRAM dcache */
	for (i = (CFG_SYS_SDRAM_BASE >> MMU_SECTION_SHIFT);
	     i < (unsigned int)((CFG_SYS_SDRAM_BASE + CFG_SYS_SDRAM_SIZE) >> MMU_SECTION_SHIFT); i++) {
		set_section_dcache(i, DCACHE_WRITEBACK);
	}

	/* Enable SYSRAM dcache */
	set_section_dcache(SYSRAM_BASE >> MMU_SECTION_SHIFT, DCACHE_WRITEBACK);
}

void enable_caches(void)
{
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
	icache_enable();
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
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

extern void hw_watchdog_reboot(void);

void reset_cpu(void)
{
	hw_watchdog_reboot();
	/* never reached */
	while (1)
		;
}

#if defined(CONFIG_DISPLAY_CPUINFO)
int print_cpuinfo(void)
{
	return 0;
}
#endif
/*
 * These function are for non-secure boot needed, but we only use one core for now
 * so just declare function without content.
 */
#if !defined(CONFIG_SMP_PEN_ADDR) && defined(CONFIG_CPU_V7_HAS_NONSEC)
void smp_kick_all_cpus(void)
{
}

void smp_set_core_boot_addr(unsigned long addr, int corenr)
{
}

void smp_waitloop(unsigned previous_address)
{
}
#endif
