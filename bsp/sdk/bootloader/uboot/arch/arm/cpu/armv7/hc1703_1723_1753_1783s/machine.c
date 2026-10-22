//Get SDK config from common header
#include <configs/augentix/augentix_common.h>

#include "address_map.h"
typedef unsigned long uintptr_t;

#include "csr/csr_bank_wdt.h"
#include "csr/csr_bank_ck.h"
#include "platform/hw_pc.h"
#include "dram/hw_dram.h"
#include "dram/hw_dram_setting.h"

#include "nvspc/nvspc.h"
#include "wdt/hw_wdt.h"
#include "pll/hw_pll.h"
#include "uart/uart.h"
#include "utils/printf.h"
#include "utils/utils.h"
#include "qspi/hw_qspi.h"
#include "usb/hw_usb.h"
#include "board_pinmux.h"

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
#include "pmu/pmu.h"
#include "trustzone/trustzone.h"
#include "trustzone/tzc400.h"
#include "trustzone/tzpc.h"
#endif

#ifdef CONFIG_FPGA
#include "fpga_pinmux/fpga_pinmux.h"
#endif

#if defined(CONFIG_SAPPORO)
static const struct tzc_region_config secure_region = { FILTER_0 + FILTER_1, 0x00000000, 0xFFFFFFFF, TZC_REGION_S_RDWR,
	                                                0x00000000 };
#elif defined(CONFIG_OSAKA)
/* temporary open permissions for all modules to read/write dram for FPGA testing */
static const struct tzc_region_config secure_region = { FILTER_0 + FILTER_1 + FILTER_2 + FILTER_3, 0x00000000,
	                                                0xFFFFFFFF, TZC_REGION_S_RDWR, 0xFFFFFFFF };
#endif
volatile CsrBankWdt *g_wdt = ((volatile CsrBankWdt *)AON_WDT_BASE);

struct uart_dev g_uart = {
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	.base_addr = UART1_BASE,
#ifdef CONFIG_FPGA
	.ref_clk_rate = 12000000,
#else
	.ref_clk_rate = 199200000,
#endif //CONFIG_FPGA
#else
	.ref_clk_rate = UART_REF_CLK_125MHZ, //CPU=1G then APB0=125M
	.base_addr = UART0_BASE,
#endif //CONFIG_SAPPORO
	.baud_rate = CONFIG_BAUDRATE,
	.enabled_interrupts = UART_IER__NONE
};

extern struct qspi_dev g_qspi;

void disable_caches(void)
{
	flush_dcache_all();
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
	dpp->t_DINIT1 = 216;

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
	dpp->t_DINIT1 = 136;

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
	dpp->t_DINIT1 = 96; //Excel check

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
#endif /* !CONFIG_DDR_TYPE_HYPERRAM */

#define RETRY_TIMES 100
int machine_init(void)
{
	int ret = 0;
	uint32_t count = 0;

#ifdef CONFIG_FPGA
//	fpga_pinmux_init();
#endif

#ifndef CONFIG_FPGA
#if defined(CONFIG_DDR_TYPE_DDR2) || defined(CONFIG_DDR_TYPE_DDR3)
	struct dram_controller_param dcp;
	struct ddr_phy_param dpp;
#endif
#if defined(CONFIG_SAPPORO)
#if defined(CONFIG_CPU_LOW_SPEED)
	config_cpu_low_speed(1);
#else
	config_cpu_low_speed(0);
#endif // CONFIG_CPU_LOW_SPEED
#endif // CONFIG_SAPPORO
	pll_all_setting_new_v2(DDR_DATA_RATE);
#endif // !CONFIG_FPGA

	qspi_init(&g_qspi);

#if defined(CONFIG_SAPPORO)
	/* init tzasc regions */
	tzc_init(TZASC_BASE);
	tzc_set_action(TZC_ACTION_ERR_INT);
	tzc_configure_region(0, &secure_region);
	tzc_enable_filters();

	/* init tzpc */
	tzpc_set_secure(TRNG_INDEX);
	tzpc_set_secure(SECURE_DMA_INDEX);
#elif defined(CONFIG_OSAKA)
	/* tz init */
	set_val(TZASC_BASE + 0x8, 0xF);
	set_val(TZASC_BASE + 0x110, 0xC0000000);
	set_val(TZASC_BASE + 0x114, 0xFFFFFFFF);
	set_val(TZPC_BASE + 0x804, 0xFF);
	set_val(TZPC_BASE + 0x810, 0xFF);
	set_val(TZPC_BASE + 0x81C, 0xFF);
	/* power up gic */
	set_val(GIC_BASE + 0x40024, 0);
	set_val(GIC_BASE + 0x40014, 0);
	/* set gic group non secure */
	for (ret = 1; ret < 16; ret++) {
		set_val(GIC_BASE + 0x80 + (ret << 2), 0xFFFFFFFF);
		set_val(GIC_BASE + 0xD00 + (ret << 2), 0);
	}
#elif defined(CONFIG_HC1703_1723_1753_1783S)
	conf_load();
#endif

#ifndef CONFIG_FPGA
	qspi_set_clk(CONFIG_AGTX_QSPI_FREQ);
	switch_clk_src();
#endif

#if defined(CONFIG_SAPPORO)
	cken_init();
#if defined(CONFIG_AGTX_EMAC_CLK_O_50M)
	volatile CsrBankCk *ck = ((volatile CsrBankCk *)CK_BASE);
	/* must after switch_clk_src() */
	ck->emac_div_num = 9;
#endif
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
		ret = hw_dram_init_v2(&dcp, &dpp, DDR_DATA_RATE);
		if (ret > 0)
			break;
	}
#endif
#endif

	hw_darb_init(ROW_ADDR_TYPE, BANK_ADDR_TYPE, COL_ADDR_TYPE);

#ifndef CONFIG_FPGA
#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_OSAKA) && !defined(CONFIG_KAMO)
	hw_dram_agent_init(ROW_ADDR_TYPE, BANK_INTERLEAVE_TYPE, BANK_ADDR_TYPE, COL_ADDR_TYPE);
#endif
	hw_axiqos_init();

	hw_usb_phy_init();
#endif

	hw_wdt_disable(g_wdt);

	uart_init(&g_uart);

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
	pmu_prepare();
	pmu_disable_wdt();
#endif
	//pmu related io setting must be set between pmu_prepare() & pmu_done()
	pinmux_board_init();

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
	pmu_done();
#endif

	return (count == RETRY_TIMES) ? -1 : ret;
}
