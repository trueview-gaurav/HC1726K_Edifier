#ifndef CA7_TIMER_H
#define CA7_TIMER_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "intc/hw_gic.h"

#define isb(option) __asm__ __volatile__("isb " #option : : : "memory")
#define dsb(option) __asm__ __volatile__("dsb " #option : : : "memory")
#define dmb(option) __asm__ __volatile__("dmb " #option : : : "memory")

enum ca7_timer_reg {
	CA7_TIMER_REG_TVAL = 0, // PL1 physical timer value register, CNTP_TVAL
	CA7_TIMER_REG_CTRL = 1 // PL1 physical timer control register, CNTP_CTL
};

#define CA7_TIMER_CTRL_ENABLE (1 << 0)
#define CA7_TIMER_CTRL_IMASK (1 << 1)
#define CA7_TIMER_CTRL_ISTATUS (1 << 2)

typedef enum irqreturn_e irqreturn_t;

static __always_inline void ca7_timer_reg_write_cp15(int reg, uint32_t val)
{
	switch (reg) {
	case CA7_TIMER_REG_CTRL:
		asm volatile("mcr p15, 0, %0, c14, c2, 1" : : "r"(val));
		break;
	case CA7_TIMER_REG_TVAL:
		asm volatile("mcr p15, 0, %0, c14, c2, 0" : : "r"(val));
		break;
	}
}

static __always_inline uint32_t ca7_timer_reg_read_cp15(int reg)
{
	uint32_t val = 0;
	switch (reg) {
	case CA7_TIMER_REG_CTRL:
		asm volatile("mrc p15, 0, %0, c14, c2, 1" : "=r"(val));
		break;
	case CA7_TIMER_REG_TVAL:
		asm volatile("mrc p15, 0, %0, c14, c2, 0" : "=r"(val));
		break;
	}
	return val;
}

void ca7_timer_init(uint32_t freq);

void ca7_timer_start(void);
void ca7_timer_stop(void);

bool ca7_timer_is_running(void);

uint32_t ca7_timer_set_counter(uint32_t val);
uint32_t ca7_timer_get_counter(void);

/* IRQ handling functions */
uint32_t ca7_timer_irq_enable(void);
uint32_t ca7_timer_irq_disable(void);

bool ca7_timer_irq_is_enabled(void);

void ca7_timer_irq_handler(uint32_t iar, void *context);

static inline void ca7_timer_set_freq(uint32_t freq)
{
	asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r"(freq));
}

static inline uint32_t ca7_timer_get_freq(void)
{
	uint32_t val;
	asm volatile("mrc p15, 0, %0, c14, c0, 0" : "=r"(val));
	return val;
}

/* Read 64-bit physical count register */
static inline uint64_t ca7_counter_get_cntpct(void)
{
	uint64_t cval;

	isb();
	asm volatile("mrrc p15, 0, %Q0, %R0, c14" : "=r"(cval));
	return cval;
}

static inline uint32_t ca7_timer_get_cntkctl(void)
{
	uint32_t cntkctl;
	asm volatile("mrc p15, 0, %0, c14, c1, 0" : "=r"(cntkctl));
	return cntkctl;
}

static inline void ca7_timer_set_cntkctl(uint32_t cntkctl)
{
	asm volatile("mcr p15, 0, %0, c14, c1, 0" : : "r"(cntkctl));
}

#endif /* CA7_TIMER_H_ */
