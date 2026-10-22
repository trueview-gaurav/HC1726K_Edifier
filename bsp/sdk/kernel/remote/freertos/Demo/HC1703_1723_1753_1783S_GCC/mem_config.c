#include <stdint.h>

#include "mmu/mmu.h"
#include "cpu/cpu.h"
#include "utils/printf.h"

static struct mmu_mem_region g_regions[] = {
	// DRAM: Cacheable, 256MiB
	{ .va = (void *)0x00000000,
	  .pa = (void *)0x00000000,
	  .size = 0x1C000000,
	  .access = MMU_AP_FULL_ACCESS,
	  .attributes = MMU_ATTR_WB,
	  .shareable = MMU_TTB_S_NON_SHAREABLE,
	  .xn = MMU_TTB_XN_DISABLE,
	  .ns = MMU_TTB_NS_SECURE },
	// DRAM: Non-Cacheable, TBD

	// DRAM: Cacheable, 256MiB
	{ .va = (void *)0x1C000000,
	  .pa = (void *)0x1C000000,
	  .size = 0x04000000,
	  .access = MMU_AP_FULL_ACCESS,
	  .attributes = MMU_ATTR_WB,
	  .shareable = MMU_TTB_S_NON_SHAREABLE,
	  .xn = MMU_TTB_XN_DISABLE,
	  .ns = MMU_TTB_NS_SECURE },
	// DRAM: Non-Cacheable, TBD

	// Device CSR
	{ .va = (void *)0x80000000,
	  .pa = (void *)0x80000000,
	  .size = 0x05000000,
	  .access = MMU_AP_FULL_ACCESS,
	  .attributes = MMU_ATTR_DEVICE,
	  .shareable = MMU_TTB_S_SHAREABLE,
	  .xn = MMU_TTB_XN_DISABLE,
	  .ns = MMU_TTB_NS_SECURE },

	// SYSRAM
	{ .va = (void *)0xFFE00000,
	  .pa = (void *)0xFFE00000,
	  .size = 0x00100000,
	  .access = MMU_AP_FULL_ACCESS,
	  .attributes = MMU_ATTR_WBA,
	  .shareable = MMU_TTB_S_NON_SHAREABLE,
	  .xn = MMU_TTB_XN_DISABLE,
	  .ns = MMU_TTB_NS_SECURE },

};

uint8_t TTB_Table[MMU_TTB1_SIZE] __attribute__((aligned(0x4000)));

void mmu_config(void)
{
	int ret;

	//printf("TTB_Table@ 0x%x\n", TTB_Table);
	ret = mmu_init((uint32_t *)TTB_Table, g_regions, sizeof(g_regions) / sizeof(struct mmu_mem_region));

	if (ret != 0) {
		printf("\n\nMMU init fail\n\n");
	}
}
