#include <stdint.h>

#include "ca7_timer.h"
#include "intc/hw_gic.h"

/* TODO: error code duplicates hw_qspi.h */
/* error code */
#define ESUCCESS 0x0
#define ETIMEOUT 0x1
#define EFAIL 0x2
#define EPAGE 0x3
#define ECHKSUM 0x4
#define EDATA 0x5

void ca7_timer_irq_handler(uint32_t iar, void *context)
{
	uint32_t ctrl;

	ctrl = ca7_timer_reg_read_cp15(CA7_TIMER_REG_CTRL);
	// Mask timer interrupt until set by next event
	if (ctrl & CA7_TIMER_CTRL_ISTATUS) {
		ctrl |= CA7_TIMER_CTRL_IMASK;
		ca7_timer_reg_write_cp15(CA7_TIMER_REG_CTRL, ctrl);
	}
}

void ca7_timer_start(void)
{
	uint32_t ctrl;
	ctrl = ca7_timer_reg_read_cp15(CA7_TIMER_REG_CTRL);
	// De-assert IMASK
	ctrl &= ~CA7_TIMER_CTRL_IMASK;
	// Assert ENABLE
	ctrl |= CA7_TIMER_CTRL_ENABLE;
	ca7_timer_reg_write_cp15(CA7_TIMER_REG_CTRL, ctrl);
}

void ca7_timer_stop(void)
{
	uint32_t ctrl;
	ctrl = ca7_timer_reg_read_cp15(CA7_TIMER_REG_CTRL);
	// Assert IMASK
	ctrl |= CA7_TIMER_CTRL_IMASK;
	// De-assert ENABLE
	ctrl &= ~CA7_TIMER_CTRL_ENABLE;
	ca7_timer_reg_write_cp15(CA7_TIMER_REG_CTRL, ctrl);
}

void ca7_timer_init(uint32_t freq)
{
	ca7_timer_stop();
	ca7_timer_set_freq(freq);
}

bool ca7_timer_is_running(void)
{
	uint32_t ctrl;
	ctrl = ca7_timer_reg_read_cp15(CA7_TIMER_REG_CTRL);
	return (ctrl & CA7_TIMER_CTRL_ENABLE) ? true : false;
}

uint32_t ca7_timer_set_counter(uint32_t val)
{
	ca7_timer_stop();
	ca7_timer_reg_write_cp15(CA7_TIMER_REG_TVAL, val);
	return -ESUCCESS;
}

uint32_t ca7_timer_get_counter(void)
{
	uint32_t tval;
	tval = ca7_timer_reg_read_cp15(CA7_TIMER_REG_TVAL);
	return -ESUCCESS;
}

uint32_t ca7_timer_irq_enable(void)
{
	uint32_t ctrl;
	ctrl = ca7_timer_reg_read_cp15(CA7_TIMER_REG_CTRL);
	// De-assert IMASK
	ctrl &= CA7_TIMER_CTRL_IMASK;
	ca7_timer_reg_write_cp15(CA7_TIMER_REG_CTRL, ctrl);
}

uint32_t ca7_timer_irq_disable(void)
{
	uint32_t ctrl;
	ctrl = ca7_timer_reg_read_cp15(CA7_TIMER_REG_CTRL);
	// Assert IMASK
	ctrl |= CA7_TIMER_CTRL_IMASK;
	ca7_timer_reg_write_cp15(CA7_TIMER_REG_CTRL, ctrl);
}

bool ca7_timer_irq_is_enabled(void)
{
	uint32_t ctrl;
	ctrl = ca7_timer_reg_read_cp15(CA7_TIMER_REG_CTRL);
	return (ctrl & CA7_TIMER_CTRL_IMASK) ? true : false;
}
