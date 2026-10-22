// SPDX-License-Identifier: BSD-2-Clause

/*
 * AOV SRAM Code : PLL off/on + DDRPHY + AON Gate.
 *
 * Suspend flow:
 *   1. DDRPHY I/O down
 *   2. ADOPLL off
 *   3. CPU clock: PLL -> XTAL
 *   4. SNSPLL off
 *   5. CPUPLL off
 *   6. CASPLL off
 *   7. AON gate  (CPU sleeps)
  * Resume flow:
 *   1. CASPLL on
 *   2. CPUPLL on
 *   3. SNSPLL on
 *   4. CPU clock: XTAL -> PLL
 *   5. ADOPLL on
 *   6. DDRPHY I/O up
 *
 * Deviations (OP-TEE ):
 *   - sram_delay_ns/sram_get_cpu_cnt inlined 
 *   - cpu_highspeed local 
 *
 * SMC handler VA Using:
 *   aon_va = PA 0x80300408, dphy_va = PA 0x81840000, pc_va = PA 0x80000000
 */

#if defined(CFG_SM_PLATFORM_SUSPEND)

#define REG32(addr)  (*(volatile unsigned int *)(addr))

/* Equivalent to Linux writel(): store followed by dsb sy */

#define WRITEL(addr, val) do {                             \
    REG32(addr) = (val);                                   \
    asm volatile("dsb sy" ::: "memory");                   \
} while (0)

static inline __attribute__((always_inline))
unsigned int sram_get_cpu_cnt(void)
{
    unsigned int cvall, cvalh;
    asm volatile("mrrc p15, 0, %0, %1, c14" : "=r"(cvall), "=r"(cvalh));
	
    return cvall;
}

static inline __attribute__((always_inline))
void sram_delay_ns(unsigned int ns, int cpu_highspeed)
{
    unsigned int start = sram_get_cpu_cnt();
    unsigned int cpu_freq = (cpu_highspeed == 1) ? 891 : 24;
    unsigned int cycles;

    if (ns > 1000000) {
        unsigned int ms = ns / 1000000;
        unsigned int remaining_ns = ns % 1000000;
        cycles = (ms * cpu_freq * 1000) + (remaining_ns * cpu_freq / 1000) + 1;
    } else {
        cycles = ns * cpu_freq / 1000 + 1;
    }
    while ((sram_get_cpu_cnt() - start) < cycles) {
        asm volatile("" : : : "memory");
    }
}

int augentix_sram_resume(unsigned long aon_va,
                         unsigned long dphy_va,
                         unsigned long pc_va)
{
    unsigned long pll_va[4];
    unsigned int rdata;
    int cpu_highspeed;
    int i;

    /* ADO, SNS, CPU, CAS */
    pll_va[0] = pc_va + 0x17000;
    pll_va[1] = pc_va + 0x15000;
    pll_va[2] = pc_va + 0x12000;
    pll_va[3] = pc_va + 0x10000;

    /* TLB pre-warm due to DRAM off path  */
    (void)REG32(aon_va);
    (void)REG32(dphy_va + 0x28);
    (void)REG32(pc_va + 0x68);
    (void)REG32(pll_va[0]);
    (void)REG32(pll_va[1]);
    (void)REG32(pll_va[2]);
    (void)REG32(pll_va[3]);
    asm volatile("dsb sy" ::: "memory");

    sram_delay_ns(6000, 1);

    /* DDRPHY I/O down */
    rdata = REG32(dphy_va + 0x28);
    rdata = (rdata & 0xFFFFFFF3) | (0x3 << 2);
    WRITEL(dphy_va + 0x28, rdata);

    /* Disable PLLs (order: ADO, SNS, CPU, CAS) */
    for (i = 0; i < 4; i++) {
        if (i == 1) {
            /* CPU -> XTAL before SNSPLL off */
            rdata = REG32(pc_va + 0x68);
            rdata = (rdata & 0xfffffff0) | 0x1;
            WRITEL(pc_va + 0x68, rdata);
	    asm volatile("dsb sy");
	    asm volatile("isb");
	    sram_delay_ns(50, 0);
	}
	if (i == 2) {
		//sram_delay_ns(1 * 1200 * 1000, 0);
	}
	WRITEL(pll_va[i], REG32(pll_va[i]) & ~0x100);
    }

    /* AON gate — CPU sleeps here; RTC wakes it */

    WRITEL(aon_va, 0x1);

    /* Enable PLLs (reverse order: CAS, CPU, SNS, ADO) */

    for (i = 3; i >= 0; i--) {
        WRITEL(pll_va[i], REG32(pll_va[i]) | 0x100);
	sram_delay_ns(110 * 1000, cpu_highspeed);
	if (i == 1) {
		/* CPU -> PLL after SNSPLL lock */
		rdata = REG32(pc_va + 0x68);
		rdata = (rdata & 0xfffffff0) | 0x8;
		WRITEL(pc_va + 0x68, rdata);
		asm volatile("dsb sy");
		asm volatile("isb");
		cpu_highspeed = 1;
		sram_delay_ns(1000, cpu_highspeed);
	}
    }

    /* DDRPHY I/O up */

    rdata = REG32(dphy_va + 0x28);
    rdata &= 0xFFFFFFF3;
    WRITEL(dphy_va + 0x28, rdata);

    return 0;
    
}

#endif /* CFG_SM_PLATFORM_SUSPEND */
