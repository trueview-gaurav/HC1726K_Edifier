#include <string.h>
#include <stdint.h>

#include "cpu.h"

#define nop() __asm__ __volatile__("mov\tr0,r0\t@ nop\n\t");

static void cp_delay(void)
{
	volatile int i;

	/* copro seems to need some delay between reading and writing */
	for (i = 0; i < 100; i++)
		nop();
	asm volatile("" : : : "memory");
}

void dcache_enable(void)
{
	unsigned int val;

	asm volatile("mrc p15, 0, %0, c1, c0, 0 @ get CR" : "=r"(val) : : "cc");
	cp_delay();
	val |= 0x01 << 2;
	asm volatile("mcr p15, 0, %0, c1, c0, 0 @ set CR" : : "r"(val) : "cc");
}

void dcache_disable(void)
{
	unsigned int val;

	asm volatile("mrc p15, 0, %0, c1, c0, 0 @ get CR" : "=r"(val) : : "cc");
	cp_delay();
	val &= ~(0x01 << 2);
	asm volatile("mcr p15, 0, %0, c1, c0, 0 @ set CR" : : "r"(val) : "cc");
}

void icache_enable(void)
{
	unsigned int val;

	asm volatile("mrc p15, 0, %0, c1, c0, 0 @ get CR" : "=r"(val) : : "cc");
	cp_delay();
	val |= 0x01 << 12;
	asm volatile("mcr p15, 0, %0, c1, c0, 0 @ set CR" : : "r"(val) : "cc");
}

void icache_disable(void)
{
	unsigned int val;

	asm volatile("mrc p15, 0, %0, c1, c0, 0 @ get CR" : "=r"(val) : : "cc");
	cp_delay();
	val &= ~(0x01 << 12);
	asm volatile("mcr p15, 0, %0, c1, c0, 0 @ set CR" : : "r"(val) : "cc");
}
