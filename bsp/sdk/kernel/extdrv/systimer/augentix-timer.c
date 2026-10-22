#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/irqreturn.h>
#include <linux/clocksource.h>
#include <linux/clockchips.h>
#include <linux/sched_clock.h>
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_address.h>
#include <linux/version.h>

#include <asm/cputype.h>

#define TIMERX_TRIG 0x00
#define TIMERX_IRQ_CLR 0x04
#define TIMERX_IRQ_STA 0x08
#define TIMERX_IRQ_MASK 0x0C
#define TIMERX_STATUS 0x10
#define TIMERX_COUNT_VAL 0x14
#define TIMERX_MODE 0x18
#define TIMERX_COUNT_LOAD 0x1C

#define TIMERX_OFFSET 0x20

enum { TIMER0_HANDLE = BIT(0),
       TIMER1_HANDLE = BIT(1),
       TIMER2_HANDLE = BIT(2),
       TIMER3_HANDLE = BIT(3),
};

static volatile void __iomem *systimer_base;

int __handle_to_index(int handle)
{
	if (handle == TIMER0_HANDLE) {
		return 0;
	} else if (handle == TIMER1_HANDLE) {
		return 1;
	} else if (handle == TIMER2_HANDLE) {
		return 2;
	} else if (handle == TIMER3_HANDLE) {
		return 3;
	} else {
		return -EINVAL;
	}
}

static int agtx_timer_used = 0;
int agtx_timer_request(int timer_index)
{
	int handle;

	if (timer_index == 0) {
		handle = TIMER0_HANDLE;
	} else if (timer_index == 1) {
		handle = TIMER1_HANDLE;
	} else if (timer_index == 2) {
		handle = TIMER2_HANDLE;
	} else if (timer_index == 3) {
		handle = TIMER3_HANDLE;
	} else {
		return -EINVAL;
	}

	if ((agtx_timer_used & handle) != 0) {
		return -EBUSY;
	} else {
		agtx_timer_used |= handle;
		return handle;
	}
}
EXPORT_SYMBOL(agtx_timer_request);

void agtx_timer_free(int handle)
{
	if (handle == TIMER0_HANDLE) {
		agtx_timer_used &= ~TIMER0_HANDLE;
	} else if (handle == TIMER1_HANDLE) {
		agtx_timer_used &= ~TIMER1_HANDLE;
	} else if (handle == TIMER2_HANDLE) {
		agtx_timer_used &= ~TIMER2_HANDLE;
	} else if (handle == TIMER3_HANDLE) {
		agtx_timer_used &= ~TIMER3_HANDLE;
	}
}
EXPORT_SYMBOL(agtx_timer_free);

int agtx_timer_set_period(int handle, unsigned int count_value)
{
	/*
	Let prescaler = 63
	Counting_time(s) = (count_value + 1) (prescaler + 1) /24M  
	                 = (count_value + 1)/375000
	Range: 11453s > period(sec) > 2.66*10 us
	*/
	const int mode = 1; //Periodic mode
	const int prescaler = 63;
	int timer_index;

	if (count_value > 3750000 || count_value < 38) //10s ~ 0.1013ms
		return -EINVAL;

	timer_index = __handle_to_index(handle);
	if (timer_index < 0)
		return -EINVAL;

	writel_relaxed(count_value - 1, systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_COUNT_LOAD);
	writel_relaxed((prescaler << 16) | (mode), systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_MODE);

	return 0;
}
EXPORT_SYMBOL(agtx_timer_set_period);

void agtx_timer_start(int handle) //start timer
{
	int timer_index;

	timer_index = __handle_to_index(handle);
	if (timer_index < 0)
		return;

	if (readl_relaxed(systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_STATUS) != 0) //if counting
		return;
	writel_relaxed(0, systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_IRQ_MASK);
	writel_relaxed(1, systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_TRIG);
}
EXPORT_SYMBOL(agtx_timer_start);

void agtx_timer_stop(int handle) //stop timer
{
	int timer_index;

	timer_index = __handle_to_index(handle);
	if (timer_index < 0)
		return;

	if (readl_relaxed(systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_STATUS) == 0) //not counting
		return;
	writel_relaxed(1, systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_IRQ_MASK);
	writel_relaxed(1, systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_TRIG);
	while (readl_relaxed(systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_STATUS) != 0) {
		;
	}
}
EXPORT_SYMBOL(agtx_timer_stop);

irqreturn_t agtx_timer_clear_IRQ(int handle)
{
	int timer_index;

	timer_index = __handle_to_index(handle);
	if (timer_index < 0)
		return IRQ_NONE;

	while (readl_relaxed(systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_IRQ_STA) == 0) {
	}

	do {
		writel_relaxed(1, systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_IRQ_CLR);
	} while (readl_relaxed(systimer_base + (TIMERX_OFFSET * timer_index) + TIMERX_IRQ_STA) != 0);

	return IRQ_HANDLED;
}
EXPORT_SYMBOL(agtx_timer_clear_IRQ);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 20, 0)
static void __init augentix_timer_of_register(struct device_node *np)
{
	systimer_base = of_iomap(np, 0);
	if (!systimer_base) {
		pr_err("augentix_timer: invalid base address\n");
		return;
	}

	return;
}
CLOCKSOURCE_OF_DECLARE(augentix_timer, "augentix,augentix-timer", augentix_timer_of_register);
#else
static int __init augentix_timer_of_register(struct device_node *np)
{
	systimer_base = of_iomap(np, 0);
	if (!systimer_base) {
		pr_err("augentix_timer: invalid base address\n");
		return -ENXIO;
	}

	return 0;
}
TIMER_OF_DECLARE(augentix_timer, "augentix,augentix-timer", augentix_timer_of_register);
#endif
