#include <linux/init.h>
#include <linux/mm.h>
#include <linux/kernel.h>
#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <linux/memblock.h>

#include "address.h"

#define EARLY_STR_CONCAT(s1, s2) s1##s2
#define EARLY_UBOOTENV_SETUP(var, value)                                                         \
	static int EARLY_STR_CONCAT(g_ubootenv_, var) = value;                                   \
	static __attribute__((unused)) int __init EARLY_STR_CONCAT(early_setup_, var)(char *str) \
	{                                                                                        \
		sscanf(str, "%i", &EARLY_STR_CONCAT(g_ubootenv_, var));                          \
		return 0;                                                                        \
	}                                                                                        \
	early_param(#var, EARLY_STR_CONCAT(early_setup_, var));

/* Information from Uboot */
EARLY_UBOOTENV_SETUP(early_vb_memaddr, 0);
EARLY_UBOOTENV_SETUP(early_vb_size, 0);
EARLY_UBOOTENV_SETUP(early_audio_buf_addr, 0);
EARLY_UBOOTENV_SETUP(early_audio_buf_kb, 0);

extern void __init augentix_pm_init(void);

unsigned long g_vb_size;
EXPORT_SYMBOL(g_vb_size);

static const char *const augentix_dt_match[] = {
	"augentix,hc1703_1723_1753_1783s",
	"augentix,hc1703_1723_1753_1783s-fpga",
	"augentix,hc1703_1723_1753_1783s-evb-v1",
	"augentix,sapporo",
	"augentix,kamo",
	"augentix,osaka",
	NULL,
};

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
extern void aon_wdt_reboot(volatile void *wdt_base);
extern void aon_wdt_stop_for_suspend(volatile void *wdt_base);
#else
extern void aon_wdt_reboot(volatile void *wdt_base, volatile void *amc_base);
extern void aon_wdt_stop_for_suspend(volatile void *wdt_base, volatile void *amc_base);
#endif

static __initdata struct map_desc augentix_io_desc[] = {
	{
	        .virtual = IO_AIOC_VA,
	        .pfn = __phys_to_pfn(IO_AIOC_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	{
	        .virtual = AON_VA,
	        .pfn = __phys_to_pfn(AON_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = PMU_VA,
	        .pfn = __phys_to_pfn(PMU_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
#if defined(CONFIG_SAPPORO)
	/* SRAM identity mapping (VA == PA) for SPL efuse ops */
	{
	        .virtual = SRAM_VA,
	        .pfn = __phys_to_pfn(SRAM_PA),
	        .length = SRAM_SIZE,
	        .type = MT_MEMORY_RWX_NONCACHED,
	},
#endif
#else
	{
	        .virtual = AON_WDT_VA,
	        .pfn = __phys_to_pfn(AON_WDT_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = AMC_VA,
	        .pfn = __phys_to_pfn(AMC_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	/* SRAM identity mapping (VA == PA) for SPL efuse ops */
	{
	        .virtual = SRAM_VA,
	        .pfn = __phys_to_pfn(SRAM_PA),
	        .length = SRAM_SIZE,
	        .type = MT_MEMORY_RWX_NONCACHED,
	},
#endif
	{
	        .virtual = AGTX_DEBUG_UART_VA,
	        .pfn = __phys_to_pfn(AGTX_DEBUG_UART_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = DRAMC_VA,
	        .pfn = __phys_to_pfn(DRAMC_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = DDRPHY_VA,
	        .pfn = __phys_to_pfn(DDRPHY_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = CASPLL_VA,
	        .pfn = __phys_to_pfn(CASPLL_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = DDRPLL_VA,
	        .pfn = __phys_to_pfn(DDRPLL_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = CPUPLL_VA,
	        .pfn = __phys_to_pfn(CPUPLL_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = SNSPLL_VA,
	        .pfn = __phys_to_pfn(SNSPLL_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = ADOPLL_VA,
	        .pfn = __phys_to_pfn(ADOPLL_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = PC_VA,
	        .pfn = __phys_to_pfn(PC_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
	{
	        .virtual = IO_VA,
	        .pfn = __phys_to_pfn(IO_PA),
	        .length = SZ_4K,
	        .type = MT_DEVICE,
	},
};

void __init augentix_map_io(void)
{
	iotable_init(augentix_io_desc, ARRAY_SIZE(augentix_io_desc));
}

static void __init augentix_reserve(void)
{
	int ret;

	g_vb_size = CONFIG_VB_SIZE_MB > CONFIG_CMA_SIZE_MBYTES ? (CONFIG_CMA_SIZE_MBYTES << 20) :
	                                                         (CONFIG_VB_SIZE_MB << 20);

	/* Reserve early video buffer */
	if (g_ubootenv_early_vb_size) {
		ret = memblock_reserve(g_ubootenv_early_vb_memaddr, g_ubootenv_early_vb_size << 20);
		if (ret == 0)
			pr_info("Reserve early video buffer successful\n");
		else
			pr_err("Fail to reserve early video buffer\n");
	}

	/* Reserve early audio buffer */
	if (g_ubootenv_early_audio_buf_kb) {
		ret = memblock_reserve(g_ubootenv_early_audio_buf_addr, g_ubootenv_early_audio_buf_kb << 10);
		if (ret == 0) {
			pr_info("Reserve early audio buffer successful\n");
		} else {
			pr_err("Fail to reserve early audio buffer\n");
		}
	}
}

static void augentix_restart(enum reboot_mode mode, const char *cmd)
{
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	volatile void *aon_wdt_base = (volatile void *)AON_VA + 0x800;
	aon_wdt_reboot(aon_wdt_base);
#else
	volatile void *aon_wdt_base = (volatile void *)AON_WDT_VA;
	volatile void *amc_base = (volatile void *)AMC_VA;
	aon_wdt_reboot(aon_wdt_base, amc_base);
#endif
}

void augentix_suspend_disable_wdt(void)
{
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	volatile void *aon_wdt_base = (volatile void *)AON_VA + 0x800;
	aon_wdt_stop_for_suspend(aon_wdt_base);
#else
	volatile void *aon_wdt_base = (volatile void *)AON_WDT_VA;
	volatile void *amc_base = (volatile void *)AMC_VA;
	aon_wdt_stop_for_suspend(aon_wdt_base, amc_base);
#endif
}

void augentix_amc_pd_off(void)
{
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	volatile void *pmu_base = (volatile void *)PMU_VA + 0x400;
	volatile void *addr;

	addr = pmu_base + 0x14; // SLEEP_CTRL
	writel_relaxed(0x1, addr);
#else
	volatile void *aon_wdt_base = (volatile void *)AON_WDT_VA;
	volatile void *amc_base = (volatile void *)AMC_VA;
	volatile void *addr;
	aon_wdt_stop_for_suspend(aon_wdt_base, amc_base);

	addr = amc_base + 0x68; // PWR_MODE
	writel_relaxed(0x10000, addr);

	addr = amc_base + 0x18; // SLEEP_AON
	writel_relaxed(1, addr);
#endif
}
EXPORT_SYMBOL(augentix_amc_pd_off);

DT_MACHINE_START(AUGENTIX_DT, "Augentix family")
	.dt_compat		=	augentix_dt_match,
	.restart		= 	augentix_restart,
	.reserve		= 	augentix_reserve,
	.map_io			= 	augentix_map_io,
MACHINE_END
