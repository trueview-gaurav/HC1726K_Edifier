/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <arm32.h>
#include <console.h>
#include <kernel/tee_common_otp.h>
#include <drivers/agtx_uart.h>
#include <drivers/gic.h>
#include <drivers/tzc400.h>
#include <io.h>
#include <kernel/boot.h>
#include <kernel/misc.h>
#include <kernel/panic.h>
#include <mm/core_mmu.h>
#include <mm/core_memprot.h>
#include <platform_config.h>
#include <stdint.h>
#include "agtx_smc.h"
#include <drivers/spi/agtx_spi.h>
//static struct cdns_uart_data console_data;

register_phys_mem_pgdir(MEM_AREA_IO_NSEC, CONSOLE_UART_BASE, CORE_MMU_PGDIR_SIZE);
register_phys_mem_pgdir(MEM_AREA_IO_NSEC, CONSOLE_WDT_BASE, CORE_MMU_PGDIR_SIZE);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, GIC_BASE, CORE_MMU_PGDIR_SIZE);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, TZASC_BASE, CORE_MMU_PGDIR_SIZE);
#if defined(CFG_SM_PLATFORM_SUSPEND)
register_phys_mem_pgdir(MEM_AREA_IO_SEC, DDRPHY_BASE, CORE_MMU_PGDIR_SIZE);
#endif
#ifndef CFG_IDENTITY_MAPPING
register_phys_mem_pgdir(MEM_AREA_IO_SEC, PLATFORM_CONTROL_BASE, CORE_MMU_PGDIR_SIZE);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, SYSCONF_BASE, CORE_MMU_PGDIR_SIZE);
#else
early_init_late(idmap_init);
#endif

TEE_Result check_huk_nonzero(struct tee_hw_unique_key *pthuk);
bool check_secure_enable_ready(void);

struct agtx_uart_data console_data;

void plat_primary_init_early(void)
{
	struct tzc_region_config cfg = {
		.filters = BIT(0) | BIT(1),
		.base = 0x00000000,
		.top = (TEE_RAM_START - 1),
		.sec_attr = TZC_REGION_S_RDWR,
		.ns_device_access = 0xFFFFFFFF,
	};
	asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r"(CPU_FREQ));

	// config TZASC
	// region0 was configured as secure for all address in SPL phase
	// we only need to config region1 for Linux, and region2 for SHM
	tzc_init(TZASC_BASE);
	tzc_configure_region(1, &cfg);
	cfg.base = TEE_SHMEM_START;
	cfg.top = TEE_SHMEM_START + TEE_SHMEM_SIZE - 1;
	tzc_configure_region(2, &cfg);
	// set TZPC...?
}

void plat_console_init(void)
{
	agtx_uart_init(&console_data, CONSOLE_UART_BASE);
	register_serial_console(&console_data.chip);
}

void boot_primary_init_intc(void)
{
	gic_init(GIC_CPU_BASE, GIC_DIST_BASE);
}

void boot_secondary_init_intc(void)
{
	gic_init_per_cpu();
}

TEE_Result tee_otp_get_hw_unique_key(struct tee_hw_unique_key *hwkey)
{
	uint8_t *huk = NULL;
#ifdef CFG_IDENTITY_MAPPING
	if (is_sysconf_mapped() == false) {
		EMSG("SYSCONF_BASE did not initialize");
		return TEE_ERROR_SECURITY;
	}
	huk = (uint8_t *)(SYSCONF_BASE + 8);
#else
	struct io_pa_va p = { .pa = SYSCONF_BASE, .va = 0 };
	huk = (uint8_t *)io_pa_or_va(&p, sizeof(hwkey->data)) + 8;
#endif
	
	if (!huk) {
		EMSG("\nH/W Unique key is not fetched from the platform.");
		return TEE_ERROR_SECURITY;
	}
	memcpy(&hwkey->data[0], huk, sizeof(hwkey->data));
	if (check_huk_nonzero(hwkey) != TEE_SUCCESS) {
		if (check_secure_enable_ready()) {
			EMSG("NoHUK !");
			return TEE_ERROR_NO_DATA;
		}
	}
	return TEE_SUCCESS;
}
