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

#define AUDIO_PLL_OUT3_CLK 46080000
#define SYS_XTAL_CLK 24000000

/* Region PWM */
#define PWMX_OFFSET 0x10

#define PWM_R0 0x0
#define PWM_R0_TRIG (1 << 0)
#define PWM_R0_INTC (1 << 16)

#define PWM_R1 0x4
#define PWM_R1_BUSY (1 << 0)
#define PWM_R1_ST (1 << 16) /* irq status */

/* XXX_B means bit shift */
#define PWM_R2 0x8
#define PWM_R2_INTM_B 0
#define PWM_R2_MODE_B 16

#define PWM_R3 0xC
#define PWM_R3_PRES_B 0
#define PWM_R3_PERIOD_B 8
#define PWM_R3_HIGH_B 16
#define PWM_R3_NUM_PERIOD_B 24

#define PWM_OUT_SEL_0 0x60
#define PWM_OUT_SEL_1 0x64

#define PWM_NUM 6
#define PWM_PRESCALER_MAX 24
#define PWM_PERIOD_MAX ((1 << 8) - 1)
#define PWM_HIGH_MAX ((1 << 8) - 1)
#define PWM_NUM_PERIOD_MAX ((1 << 8) - 1)
#define NUM_1G 1000000000

#define PWMO_SEL0_OFFSET 0x60
#define PWMO_SEL4_OFFSET 0x64

static inline uint32_t augentix_pwm_get(int idx, uint32_t offset)
{
	return readl(PWM_BASE + (PWMX_OFFSET * idx) + offset);
}
static inline void augentix_pwm_set(int idx, uint32_t offset, uint32_t val)
{
	writel(val, PWM_BASE + (PWMX_OFFSET * idx) + offset);
}

int pwm_init(int pwm_id, int div, int invert)
{
	uint32_t pwm_out_sel0 = PWM_BASE + PWMO_SEL0_OFFSET;
	uint32_t pwm_out_sel4 = PWM_BASE + PWMO_SEL4_OFFSET;

	// set out_sel in order
	writel(((0 << 0) | (1 << 8) | (2 << 16) | (3 << 24)), pwm_out_sel0);
	writel(((4 << 0) | (5 << 8)), pwm_out_sel4);
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

	if (pwm_id == 2 || pwm_id == 3) {
		sys_clk = AUDIO_PLL_OUT3_CLK;
	} else {
		sys_clk = SYS_XTAL_CLK;
	}

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

	augentix_pwm_set(pwm_id, PWM_R3,
	                 (cnt_psc << PWM_R3_PRES_B | (cnt_period << PWM_R3_PERIOD_B) | (cnt_high << PWM_R3_HIGH_B)));

	DBG("(Interger format) requested frquency: %d Hz, provided frquency: %d Hz, duty: %u%%\n", NUM_1G / period_ns,
	    prescaled_freq, cnt_high * 100 / cnt_period);
	DBG("mod = %llu, cnt_psc = %u, cnt_high = %u, cnt_period = %u\n", mod, cnt_psc, cnt_high, cnt_period);

	return 0;
}

int pwm_enable(int pwm_id)
{
	if (augentix_pwm_get(pwm_id, PWM_R1) & PWM_R1_BUSY) {
		DBG("PWM %d is already enabled\n", pwm_id);
		return 0;
	}
	augentix_pwm_set(pwm_id, PWM_R0, (PWM_R0_TRIG | PWM_R0_INTC));
	DBG("Enable PWM %d\n", pwm_id);

	return 0;
}

void pwm_disable(int pwm_id)
{
	if ((augentix_pwm_get(pwm_id, PWM_R1) & PWM_R1_BUSY)) {
		augentix_pwm_set(pwm_id, PWM_R0, (PWM_R0_TRIG | PWM_R0_INTC));
		DBG("Disable PWM kernel %d\n", pwm_id);
	}
}
