#ifndef __CPU_TIME__
#define __CPU_TIME__

#include <configs/augentix/augentix_common.h>
#include <linux/types.h>

#ifdef CONFIG_SAPPORO
#if defined(CONFIG_CPU_LOW_SPEED)
#define CPU_CLK_PLL 450000
#else
#define CPU_CLK_PLL 891000
#endif // CONFIG_CPU_LOW_SPEED
#define CK_RESV0 0x800000E8
#else
#define CPU_CLK_PLL 1008000
#define CK_RESV0 0x8000009C
#define CK_RESV2 0x800000A4
#endif

static inline uint32_t get_cpu_time(void)
{
	uint32_t cvall, cvalh;
	uint32_t val;
	uint32_t ret;

	asm volatile("mrrc p15, 0, %0, %1, c14" : "=r"(cvall), "=r"(cvalh));
#ifdef CONFIG_SAPPORO
	val = *(uint32_t *)CK_RESV0;
#else
	val = *(uint32_t *)CK_RESV0 + (*(uint32_t *)CK_RESV2 << 16);
#endif

	ret = (cvall / CPU_CLK_PLL) + val;

	return ret; // unit: ms
}

#endif
