
#include "address_map.h"
#include "csr_bank_wdt.h"
#include "platform/hw_pc.h"
#include "dram/hw_dram.h"
#include "dram/hw_dram_setting.h"
#include "wdt/hw_wdt.h"
#include "pll/hw_pll.h"
#include "uart/uart.h"
#include "utils/printf.h"
#include "utils/utils.h"
#include "qspi/hw_qspi.h"
#include "usb/hw_usb.h"
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
#include "pmu/pmu.h"
#include "trustzone/trustzone.h"
#include "trustzone/tzc400.h"
#endif

#include "nvsp_mach.h"

/* default region range is fixed, can not be modify */
#if defined(CONFIG_SAPPORO)
static const struct tzc_region_config default_region = { FILTER_0 + FILTER_1, 0x00000000, 0xFFFFFFFF, TZC_REGION_S_RDWR,
	                                                 0xFFFFFFFF };
#elif defined(CONFIG_OSAKA) //temporarily comment
//static const struct tzc_region_config default_region = { FILTER_0 + FILTER_1 + FILTER_2 + FILTER_3, 0x00000000,
//	                                                 0xFFFFFFFF, TZC_REGION_S_RDWR, 0xFFFFFFFF };
#endif
volatile CsrBankWdt *g_wdt = ((volatile CsrBankWdt *)AON_WDT_BASE);

struct uart_dev g_uart = {
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	.base_addr = UART1_BASE,
#elif defined(CONFIG_HC1703_1723_1753_1783S)
	.base_addr = UART0_BASE,
#endif
	.ref_clk_rate = 12000000,
	.baud_rate = 57600,
	.enabled_interrupts = UART_IER__NONE
};

void disable_i_cache(void)
{
#ifdef __aarch64__
	asm volatile("mrs x1, SCTLR_EL1\n\t"
	             "bic x1, x1, #(1 << 0)\n\t" // M = 0 (MMU disable)
	             "bic x1, x1, #(1 << 12)\n\t" // I = 0 (I-cache disable)
	             "bic x1, x1, #(1 << 2)\n\t" // C = 0 (D-cache disable)
	             "msr SCTLR_EL1, x1\n\t"
	             "isb\n\t"

	             /* Invalidate I-Cache to PoU */
	             "ic iallu\n\t"
	             "dsb sy\n\t"
	             "isb\n\t"

	             /* Invalidate entire TLB (EL1&0) */
	             "tlbi vmalle1\n\t"
	             "dsb sy\n\t"
	             "isb\n\t"
	             :
	             :
	             : "x1", "cc", "memory");
#else
	asm volatile("mrc p15, 0, r1, c1, c0, 0\n\t" // Read System Control Register (SCTLR)
	             "bic r1, r1, #1\n\t" // mmu off
	             "bic r1, r1, #(1 << 12)\n\t" //i-cache off
	             "bic r1, r1, #(1 << 2)\n\t" // d-cache & L2-$ off
	             "mcr p15, 0, r1, c1, c0, 0\n\t" // Write System Control Register (SCTLR)

	             "mov r0, #0\n\t"
	             "mcr p15, 0, r0, c7, c5, 0\n\t" // Invalidate Instruction Cache
	             "mcr p15, 0, r0, c7, c5, 6\n\t" // Invalidate branch prediction array
	             "mcr p15, 0, r0, c8, c7, 0\n\t" // Invalidate entire Unified Main TLB
	             "isb" // instr sync barrier
	             :
	             :
	             : "r0", "r1", "cc");
#endif
}

#ifndef CONFIG_DDR_TYPE_HYPERRAM
void get_dram_setting(struct dram_controller_param *dcp, struct ddr_phy_param *dpp)
{
//Dream: Let's refer to DDR3 JEDEC spec
#ifdef CONFIG_DRAM_GENERIC_DDR3L // generic
#if (CONFIG_DRAM_CAPACITY == 512) //4Gb=512MB
	//t_RFC= 260
	dcp->t_rfc_min = 104;
	dcp->t_rfc_nom_x1_x32 = 97;

	dcp->t_xs_x32 = 0x4; //excel check
	dcp->t_xs_dll_x32 = 0x8;

	//address map for 4Gb
	dcp->addrmap_row_b12 = 0x7;
	dcp->addrmap_row_b13 = 0x7;
	dcp->addrmap_row_b14 = 0x7;
	dcp->addrmap_row_b15 = 0xf;

	dpp->t_DINIT0 = 400000; //Excel check
	dpp->t_DINIT1 = 218;

	dpp->t_AOND = 0; //1:0
	dpp->t_RTW = 0x1; //2
	dpp->t_FAW = 0x1f; //8:3
	dpp->t_MOD = 0; //10:9
	dpp->t_RTODT = 0x1; //11
	dpp->t_RFC = 208; //Excel check
	dpp->t_DQSCK = 0x1; //26:24
	dpp->t_DQSCKMAX = 0x1; //29:27
#elif (CONFIG_DRAM_CAPACITY == 256) //2Gb=256MB
	//t_RFC= 160
	dcp->t_rfc_min = 64;
	dcp->t_rfc_nom_x1_x32 = 97;

	dcp->t_xs_x32 = 0x3;
	dcp->t_xs_dll_x32 = 0x8;

	//address map for 2Gb
	dcp->addrmap_row_b12 = 0x7;
	dcp->addrmap_row_b13 = 0x7;
	dcp->addrmap_row_b14 = 0xf;
	dcp->addrmap_row_b15 = 0xf;

	dpp->t_DINIT0 = 400000; //Excel check
	dpp->t_DINIT1 = 138;

	dpp->t_AOND = 0; //1:0
	dpp->t_RTW = 0x1; //2
	dpp->t_FAW = 0x1f; //8:3
	dpp->t_MOD = 0; //10:9
	dpp->t_RTODT = 0x1; //11
	dpp->t_RFC = 208; //Excel check
	dpp->t_DQSCK = 0x1; //26:24
	dpp->t_DQSCKMAX = 0x1; //29:27
#elif (CONFIG_DRAM_CAPACITY == 128) //1Gb=128MB
	//t_RFC= 110
	dcp->t_rfc_min = 44;
	dcp->t_rfc_nom_x1_x32 = 97;

	dcp->t_xs_x32 = 0x2;
	dcp->t_xs_dll_x32 = 0x8;

	//address map for 1Gb
	dcp->addrmap_row_b12 = 0x7;
	dcp->addrmap_row_b13 = 0xf;
	dcp->addrmap_row_b14 = 0xf;
	dcp->addrmap_row_b15 = 0xf;

	dpp->t_DINIT0 = 400000; //Excel check
	dpp->t_DINIT1 = 98; //Excel check

	dpp->t_AOND = 0; //1:0
	dpp->t_RTW = 0x1; //2
	dpp->t_FAW = 0x1f; //8:3
	dpp->t_MOD = 0; //10:9
	dpp->t_RTODT = 0x1; //11
	dpp->t_RFC = 88; //Excel check
	dpp->t_DQSCK = 0x1; //26:24
	dpp->t_DQSCKMAX = 0x1; //29:27
#endif
#elif defined(CONFIG_DRAM_GENERIC_DDR2) // generic
#else
#error "Please check DDR type"
#endif

//then, if we need to optimize, continue to set
#if defined(CONFIG_DRAM_OPTIMIZE_NT5CC128M16JR)
#elif defined(CONFIG_DRAM_OPTIMIZE_NT5CC64M16GP)
#elif defined(CONFIG_DRAM_OPTIMIZE_M15T2G16128A)
#elif defined(CONFIG_DRAM_OPTIMIZE_M15T1G1664A)
#endif
}
#endif

#define RETRY_TIMES 3
int nvsp_mach_nvsp_init(BaudRateType baudrate_type)
{
	int ret = 0;
	uint32_t count = 0;
#ifndef CONFIG_FPGA
#if defined(CONFIG_DDR_TYPE_DDR2) || defined(CONFIG_DDR_TYPE_DDR3)
	struct dram_controller_param dcp;
	struct ddr_phy_param dpp;
#endif
#endif

	hw_wdt_disable(g_wdt);
#if defined(CONFIG_SAPPORO)
	pmu_prepare();
	pmu_disable_wdt();
	pmu_done();
	tzc_init(TZASC_BASE);
	tzc_disable_filters();
	tzc_configure_region(0, &default_region);
	tzc_enable_filters();
#elif defined(CONFIG_OSAKA)
	set_val(0x84010008, 0xF);
	set_val(0x84010110, 0xC0000000);
	set_val(0x84010114, 0xFFFFFFFF);
#endif
#ifndef CONFIG_FPGA
	pll_all_setting_by_uart_boot(baudrate_type);
	switch_clk_src();
#endif

#ifdef CONFIG_DDR_TYPE_HYPERRAM
	for (; count < RETRY_TIMES; count++) {
		ret = hw_hyperram_init(DDR_DATA_RATE);
		if (ret > 0)
			break;
	}
#elif defined(CONFIG_DDR_TYPE_DDR2) || defined(CONFIG_DDR_TYPE_DDR3)
#ifndef CONFIG_FPGA
	get_dram_setting(&dcp, &dpp);
	for (; count < RETRY_TIMES; count++) {
		ret = hw_dram_init(&dcp, &dpp);
		if (ret > 0)
			break;
	}
#endif
#endif

	hw_darb_init(ROW_ADDR_TYPE, BANK_ADDR_TYPE, COL_ADDR_TYPE);
	return (count == RETRY_TIMES) ? -1 : ret;
}
