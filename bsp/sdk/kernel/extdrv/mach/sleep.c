#include <asm/io.h>
#include <linux/linkage.h>

#include "address.h"

#define CK_OFFSET 0x0
#define RST_OFFSET 0x400

volatile int g_cpu_highspeed;

unsigned int __attribute__((section(".sram_code")))
get_cpu_cnt(void)
{
	unsigned int cvall, cvalh;
	asm volatile("mrrc p15, 0, %0, %1, c14" : "=r"(cvall), "=r"(cvalh));
	return cvall;
}

void __attribute__((section(".sram_code")))
delay_ns(unsigned int ns)
{
	unsigned int start = get_cpu_cnt();
	unsigned int cpu_freq = (g_cpu_highspeed == 1) ? 891 : 24; /* MHz */
	unsigned int cycles;

	if (ns > 1000000) {
		unsigned int ms = ns / 1000000;
		unsigned int remaining_ns = ns % 1000000;

		cycles = (ms * cpu_freq * 1000) + (remaining_ns * cpu_freq / 1000) + 1;
	} else {
		cycles = ns * cpu_freq / 1000 + 1; /* ns <= 1ms */
	}

	/* Leverage the two's complement subtraction property of unsigned integers to handle counter wrap-around */
	while ((get_cpu_cnt() - start) < cycles) {
		asm volatile("" : : : "memory");
	}
}

int __attribute__((section(".sram_code")))
augentix_cpu_suspend_sram(unsigned long input)
{
	uint32_t pll_va[] = { ADOPLL_VA, SNSPLL_VA, CPUPLL_VA, CASPLL_VA };
	uint32_t rdata = 0;
	int i;

	g_cpu_highspeed = 1;

	/* Wait 4us to ensure the DRAM is in self-refresh mode */
	delay_ns(4000);

	/* Power down DDRPHY I/O - DXCCR[3:2] = 2'b3 */
	rdata = readl((volatile void *)(DDRPHY_VA + 0x28));
	rdata = (rdata & 0xFFFFFFF3) | (0x3 << 2);
	writel(rdata, (volatile void *)(DDRPHY_VA + 0x28));

	/* Disable PLLs */
	for (i = 0; i < sizeof(pll_va) / sizeof(pll_va[0]); i++) {
		if (pll_va[i] == SNSPLL_VA) {
			/* Switch CPU clock source to XTAL */
			rdata = readl((volatile void *)(PC_VA + 0x68));
			rdata = (rdata & 0xfffffff0) | 0x1;
			writel(rdata, (volatile void *)(PC_VA + 0x68));
			asm volatile("dsb sy");
			asm volatile("isb");
			g_cpu_highspeed = 0;
			delay_ns(50);
		}
		writel(readl((volatile void *)pll_va[i]) & ~0x100, (volatile void *)pll_va[i]);
	}

	/* AON gating PD domain XTAL */
	writel(0x1, (volatile void *)(AON_VA + 0x400 + 0x008));

	/* Enable PLLs */
	for (i = ((sizeof(pll_va) / sizeof(pll_va[0])) - 1); i >= 0; i--) {
		writel(readl((volatile void *)pll_va[i]) | 0x100, (volatile void *)pll_va[i]);
		delay_ns(110 * 1000);
		if (pll_va[i] == SNSPLL_VA) {
			/* Switch CPU clock source to sensor PLL */
			rdata = readl((volatile void *)(PC_VA + 0x68));
			rdata = (rdata & 0xfffffff0) | 0x8;
			writel(rdata, (volatile void *)(PC_VA + 0x68));
			asm volatile("dsb sy");
			asm volatile("isb");
			g_cpu_highspeed = 1;
			delay_ns(1000);
		}
	}

	/* Power up DDRPHY I/O - DXCCR[3:2] = 2'b0 */
	rdata = readl((volatile void *)(DDRPHY_VA + 0x28));
	rdata &= 0xFFFFFFF3;
	writel(rdata, (volatile void *)(DDRPHY_VA + 0x28));

	return 0;
}
