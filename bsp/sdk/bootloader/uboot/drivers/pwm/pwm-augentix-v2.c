#include <common.h>
#include <div64.h>
#include <pwm.h>
#include <asm/io.h>

//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)                     \
	do {                                  \
		printf("[PWM] " fmt, ##args); \
	} while (0)
#else
#define DBG(fmt, args...) \
	do {              \
	} while (0)
#endif

#define CPU_PLL_OUT6_CLK 398400000

#define PWM_TRIGGER 0x0
#define PWM_BUSY 0x4
#define PWM_IRQ_CLEAR 0x8
#define PWM_IRQ_ST 0xC
#define PWM_IRQ_MASK 0x10
#define PWM_MODE 0x14

#define PWM_CONFIG(pwm_num) (0x18 + 0x4 * pwm_num)
#define PWM_CONFIG_PRESCALER 0
#define PWM_CONFIG_CNT_PERIOD 8
#define PWM_CONFIG_CNT_HIGH 16
#define PWM_CONFIG_NUM_PERIOD 24

/* General define */
#define PWM_NUM 7
#define PWM_PRESCALER_MAX 24
#define PWM_PERIOD_MAX ((1 << 8) - 1)
#define PWM_HIGH_MAX ((1 << 8) - 1)
#define PWM_NUM_PERIOD_MAX ((1 << 8) - 1)
#define NUM_1G 1000000000

int pwm_init(int pwm_id, int div, int invert)
{
	return 0;
}

int pwm_config(int pwm_id, int duty_ns, int period_ns)
{
	uint32_t sys_clk;
	unsigned long long temp;
	unsigned long long mod;
	uint32_t max_freq;
	uint32_t prescaled_freq;
	uint32_t cnt_high = 0;
	uint32_t cnt_period;
	uint8_t cnt_psc = 0;

	sys_clk = CPU_PLL_OUT6_CLK;

	/* Min frequency is sys_clk / 2^prescaler_max / max_count_period,
	 * if NUM_1G < (min_freq * period_ns),
	 * sys_clk should be larger than NUM_1G * 2^prescaler_max which is impossible for us.
	 *
	 * Max frequency is sys_clk / 2 (at least cnt_high = 1, cnt_period = 2)
	 * (NUM_1G / max_freq) > period_ns is used to prevent overflow
	 */
	max_freq = sys_clk >> 1;
	if ((NUM_1G / max_freq) > period_ns) {
		printf("Augentix PWM %d max frequency is %u Hz, intended setting is %u Hz\n", pwm_id, max_freq,
		       NUM_1G / period_ns);
		return -1;
	}

	prescaled_freq = sys_clk;

	for (;;) {
		/*
		 * period_ns     count_period
		 *----------- = --------------
		 * 10^9           frequency
		 *
		 * frequency = sys_clk / (2^prescaler)
		 * count_period = frequency * period_ns / 10^9
		 */
		temp = (unsigned long long)prescaled_freq * period_ns; /* casting is required */
		mod = do_div(temp, NUM_1G);
		cnt_period = temp;

		if (cnt_period <= PWM_PERIOD_MAX) {
			if (mod > (NUM_1G >> 1))
				cnt_period++;

			prescaled_freq /= cnt_period;
			break;
		}
		cnt_psc++;
		prescaled_freq >>= 1;
	}
	/*    duty_ns       count_high
	 *  ----------- = --------------
	 *   period_ns     count_period
	 *
	 * count_high = count_period * duty_ns / period_ns
	 * To avoid overflow, use unsigned long long here.
	 */
	if (cnt_period != 0 && duty_ns != 0) {
		temp = (unsigned long long)cnt_period * duty_ns;
		do_div(temp, period_ns);
		cnt_high = temp;
	}

	writel((cnt_psc << PWM_CONFIG_PRESCALER) | (cnt_period << PWM_CONFIG_CNT_PERIOD) |
	               (cnt_high << PWM_CONFIG_CNT_HIGH),
	       (uintptr_t)PWM_BASE + PWM_CONFIG(pwm_id));

	DBG("(Interger format) requested frquency: %d Hz, provided frquency: %d Hz, duty: %u%%\n", NUM_1G / period_ns,
	    prescaled_freq, cnt_high * 100 / cnt_period);
	DBG("mod = %llu, cnt_psc = %u, cnt_high = %u, cnt_period = %u\n", mod, cnt_psc, cnt_high, cnt_period);

	return 0;
}

int pwm_enable(int pwm_id)
{
	if (readl(PWM_BASE + PWM_BUSY) & BIT(pwm_id)) {
		DBG("PWM %d is already enabled\n", pwm_id);
		return 0;
	}
	writel(BIT(pwm_id), PWM_BASE + PWM_IRQ_CLEAR);
	writel(BIT(pwm_id), PWM_BASE + PWM_TRIGGER);
	DBG("Enable PWM %d\n", pwm_id);

	return 0;
}

void pwm_disable(int pwm_id)
{
	if (readl(PWM_BASE + PWM_BUSY) & BIT(pwm_id)) {
		writel(BIT(pwm_id), PWM_BASE + PWM_TRIGGER);
		writel(BIT(pwm_id), PWM_BASE + PWM_IRQ_CLEAR);
		DBG("Disable PWM kernel %d\n", pwm_id);
	}
}
