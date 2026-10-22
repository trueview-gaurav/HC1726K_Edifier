// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2019, HiSilicon Technologies Co., Ltd.
 */

#include <console.h>
#include <io.h>
#include <kernel/boot.h>
#include <kernel/misc.h>
#include <kernel/panic.h>
#include <mm/core_mmu.h>
#include <mm/core_memprot.h>
#include <platform_config.h>
#include <stdint.h>
#include <sm/optee_smc.h>
#include <sm/psci.h>
#include <sm/std_smc.h>
#include <tee/entry_std.h>
#include <tee/entry_fast.h>

int psci_features(uint32_t psci_fid)
{
	switch (psci_fid) {
	case ARM_SMCCC_VERSION:
	case PSCI_PSCI_FEATURES:
	case PSCI_VERSION:
	case PSCI_SYSTEM_RESET:
#ifdef CFG_BOOT_SECONDARY_REQUEST
	case PSCI_CPU_ON:
        case PSCI_CPU_OFF:
        case PSCI_AFFINITY_INFO:
#endif
		return PSCI_RET_SUCCESS;
	default:
		return PSCI_RET_NOT_SUPPORTED;
	}
}

uint32_t psci_version(void)
{
	return PSCI_VERSION_1_0;
}

void psci_system_reset(void)
{
	vaddr_t wdt = core_mmu_get_va(CONSOLE_WDT_BASE, MEM_AREA_IO_SEC, 0x100);

	if (!wdt) {
		EMSG("no wdt mapping, hang here");
		panic();
		return;
	}

	io_write32(wdt + 0x10, 0x54);
	io_write32(wdt + 0x10, 0x6F);
	io_write32(wdt + 0x10, 0x6B);
	io_write32(wdt + 0x10, 0x79);
	io_write32(wdt + 0x10, 0x6F);

	io_write32(wdt + 0x14, (1 << 8) | (1));
	io_write32(wdt + 0x18, 0);
	io_write32(wdt + 0x1C, (5 << 16) | (3));
	io_write32(wdt + 0x20, (5 << 16) | (5));
	io_write32(wdt + 0x14, (1 << 8) | (0));

	io_write32(wdt + 0x00, 1);
}

#ifdef CFG_BOOT_SECONDARY_REQUEST
static uint32_t cpu_off_state[CFG_TEE_CORE_NB_CORE];
int psci_cpu_on(uint32_t core_idx, uint32_t entry, uint32_t context_id)
{
	size_t pos = get_core_pos_mpidr(core_idx);
#if defined(CFG_SM_PLATFORM_SUSPEND)
	vaddr_t rst_reg = core_mmu_get_va(CHIP_RESET_GEN_BASE, MEM_AREA_IO_SEC, 0x100);
#endif	
	vaddr_t gicd_reg = core_mmu_get_va(GIC_DIST_BASE, MEM_AREA_IO_SEC, 0x1000);
	vaddr_t wake_reg = core_mmu_get_va(SECONDARY_ENTRY_WAKE_ADDR, MEM_AREA_IO_SEC, 0x1000);

	IMSG("psci_cpu_on\n");

	if ((pos == 0) || (pos >= CFG_TEE_CORE_NB_CORE))
		return PSCI_RET_INVALID_PARAMETERS;

	/* set secondary core's NS entry addresses */
	boot_set_core_ns_entry(pos, entry, context_id);
#ifndef CFG_SM_PLATFORM_SUSPEND
	cpu_off_state[pos] = 0;
#endif			
	IMSG("set entry\n");

	
	/* set secondary entry address and release core */
	io_write32(wake_reg, TEE_LOAD_ADDR);
	IMSG("set wake addr\n");
	dsb();

#if defined(CFG_SM_PLATFORM_SUSPEND)
	if (cpu_off_state[pos]) {
		cpu_off_state[pos] = 0;
		IMSG("hardware reset CPU%zu\n", pos);
		/* Assert CPU1 level reset */
		io_write32(rst_reg + LV_CPU_OFFSET, CPU_CORE1_BIT | CPU_COREPOR1_BIT);
		dsb();
		/* Wait for reset to take effect */
		{
			volatile int d;
			for (d = 0; d < 10000; d++)
				;
		}
		/* De-assert CPU1 level reset */
		io_write32(rst_reg + LV_CPU_OFFSET, 0);
		dsb();
		/* Also send pulse reset */
		io_write32(rst_reg + W1P_CPU_OFFSET, CPU_CORE1_BIT | CPU_COREPOR1_BIT);
		dsb();
		IMSG("CPU%zu reset done\n", pos);
		/* Wait for CPU1 bootrom to reach WFI */
		{
			volatile int d;
			for (d = 0; d < 100000; d++)
				;
		}
	}
#endif
	io_write32(gicd_reg + 0xF00, ((0x01 << (16 + 1)) | (0 << 0)));
	IMSG("wake core1\n");

	return PSCI_RET_SUCCESS;
}


int __noreturn psci_cpu_off(void)
{
        uint32_t core_id = get_core_pos();

        IMSG("psci_cpu_off core %u", core_id);
        cpu_off_state[core_id] = 1;
        dsb();
        while (true)
                wfi();
}

int psci_affinity_info(uint32_t affinity,
                       uint32_t lowest_affinity_level __unused)
{
        size_t pos = get_core_pos_mpidr(affinity);

        if (pos >= CFG_TEE_CORE_NB_CORE)
                return PSCI_RET_INVALID_PARAMETERS;
        if (cpu_off_state[pos])
                return PSCI_AFFINITY_LEVEL_OFF;
        return PSCI_AFFINITY_LEVEL_ON;
}
#endif
