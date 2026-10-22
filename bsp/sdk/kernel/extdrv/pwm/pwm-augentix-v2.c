#include <linux/clk.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/pwm.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/of_irq.h>
#include <linux/spinlock.h>
#include <linux/suspend.h>
#include <linux/version.h>

//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)                     \
	do {                                  \
		pr_err("[PWM] " fmt, ##args); \
	} while (0)
#else
#define DBG(fmt, args...) \
	do {              \
	} while (0)
#endif

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
#if defined(CONFIG_OSAKA)
#define PWM_NUM 12
#else
#define PWM_NUM 7
#endif
#define PWM_PRESCALER_MAX 24
#define PWM_PERIOD_MAX ((1 << 8) - 1)
#define PWM_HIGH_MAX ((1 << 8) - 1)
#define PWM_NUM_PERIOD_MAX ((1 << 8) - 1)
#define NUM_1G 1000000000

#define DEBUG_LOG 0

struct augentix_pwm_chip {
	struct pwm_chip chip;
	struct device *dev;
	spinlock_t lock;

	void __iomem *base;

	/* use these in order of pin */
	int irq[PWM_NUM];
	struct clk *clk[PWM_NUM];
	uint32_t sys_clk[PWM_NUM];
	int pin_to_kernel[PWM_NUM];
};

static struct augentix_pwm_chip *g_augentix_pwm_chip;
struct augentix_pwm_snapshot {
	bool enabled;
};
static struct augentix_pwm_snapshot g_augentix_pwm_snapshot[PWM_NUM];

static inline struct augentix_pwm_chip *to_augentix_pwm_chip(struct pwm_chip *chip)
{
	return container_of(chip, struct augentix_pwm_chip, chip);
}

static irqreturn_t augentix_pwm_irq_handler(int irq, void *dev_id)
{
	struct augentix_pwm_chip *agtx_pwm = (struct augentix_pwm_chip *)dev_id;
	u32 reg;
	int i = 0;
	void __iomem *base = agtx_pwm->base;

	for (i = 0; i < PWM_NUM; i++) {
		if (irq != agtx_pwm->irq[i])
			continue;
		reg = readl(base + PWM_IRQ_ST);
		if (reg & BIT(i)) {
			writel(BIT(i), base + PWM_IRQ_CLEAR);
			return IRQ_HANDLED;
		}
	}
	return IRQ_NONE;
}

static int augentix_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm, int duty_ns, int period_ns)
{
	int index = pwm->hwpwm;
	struct augentix_pwm_chip *agtx_pwm = to_augentix_pwm_chip(chip);
	void __iomem *base = agtx_pwm->base;
	struct device *dev = agtx_pwm->dev;
	uint32_t sys_clk = agtx_pwm->sys_clk[index];
	unsigned long long temp;
	unsigned long long mod;
	uint32_t prescaled_freq;
	uint32_t max_freq;
	uint32_t cnt_high = 0;
	uint32_t cnt_period;
	uint8_t cnt_psc = 0;
	unsigned long flags;

	DBG("Set PWM %d, duty_ns = %d ns, period_ns = %d ns\n", index, duty_ns, period_ns);

	/* Min frequency is sys_clk / 2^prescaler_max / max_count_period,
	 * if NUM_1G < (min_freq * period_ns),
	 * sys_clk should be larger than NUM_1G * 2^prescaler_max which is impossible for us.
	 *
	 * Max frequency is sys_clk / 2 (at least cnt_high = 1, cnt_period = 2)
	 * (NUM_1G / max_freq) > period_ns is used to prevent overflow
	 */
	max_freq = sys_clk >> 1;
	if ((NUM_1G / max_freq) > period_ns) {
		dev_err(dev, "Augentix PWM %d max frequency is %u Hz, intended setting is %u Hz\n", index, max_freq,
                       NUM_1G / period_ns);
		return -ERANGE;
	}

	prescaled_freq = sys_clk;
	for (;;) {
		/*   period_ns     count_period
		 *  ----------- = --------------
		 *     10^9         frequency
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

	spin_lock_irqsave(&agtx_pwm->lock, flags);
	writel((cnt_psc << PWM_CONFIG_PRESCALER) | (cnt_period << PWM_CONFIG_CNT_PERIOD) |
	               (cnt_high << PWM_CONFIG_CNT_HIGH),
	       base + PWM_CONFIG(index));
	spin_unlock_irqrestore(&agtx_pwm->lock, flags);
#if DEBUG_LOG
	dev_info(dev, "(Interger format) requested frquency: %u Hz, provided frquency: %u Hz, duty: %u%%\n",
              NUM_1G / period_ns, prescaled_freq, cnt_high * 100 / cnt_period);
#endif
	DBG("mod = %llu, cnt_psc = %u, cnt_high = %u, cnt_period = %u\n", mod, cnt_psc, cnt_high, cnt_period);

	return 0;
}

static int __augentix_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct augentix_pwm_chip *agtx_pwm = to_augentix_pwm_chip(chip);
	int index = pwm->hwpwm;
	void __iomem *base = agtx_pwm->base;

	if (readl(base + PWM_BUSY) & BIT(index)) {
		dev_warn(agtx_pwm->dev, "PWM %d is already enabled\n", index);
		return 0;
	}
	writel(BIT(index), base + PWM_IRQ_CLEAR);
	writel(BIT(index), base + PWM_TRIGGER);
#if DEBUG_LOG
	dev_info(agtx_pwm->dev, "Enable PWM %d\n", index);
#endif

	return 0;
}

static int augentix_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	int index = pwm->hwpwm;

	/* Update the PWM channel snapshot. This is effective only when executed in normal mode.*/
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
	if (pm_suspend_target_state == PM_SUSPEND_ON)
		g_augentix_pwm_snapshot[index].enabled = true;
#else
	g_augentix_pwm_snapshot[index].enabled = true;
#endif

	__augentix_pwm_enable(chip, pwm);
	return 0;
}

static void __augentix_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct augentix_pwm_chip *agtx_pwm = to_augentix_pwm_chip(chip);
	/* pwm->hwpwm = X of pwmX in sysfs, see it as pin */
	int index = pwm->hwpwm;
	void __iomem *base = agtx_pwm->base;

	if (readl(base + PWM_BUSY) & BIT(index)) {
		writel(BIT(index), base + PWM_TRIGGER);
		writel(BIT(index), base + PWM_IRQ_CLEAR);
#if DEBUG_LOG
		dev_info(agtx_pwm->dev, "Disable PWM %d\n", index);
#endif
	}

}

static void augentix_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	int index = pwm->hwpwm;

	/* Update the PWM channel snapshot. This is effective only when executed in normal mode.*/
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
	if (pm_suspend_target_state == PM_SUSPEND_ON)
		g_augentix_pwm_snapshot[index].enabled = false;
#else
	g_augentix_pwm_snapshot[index].enabled = false;
#endif
	__augentix_pwm_disable(chip, pwm);

}



#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 7, 0)
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 0, 0)
static int augentix_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm, const struct pwm_state *state)
#else
static int augentix_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm, struct pwm_state *state)
#endif //LINUX_VERSION_CODE >= KERNEL_VERSION(6, 0, 0)
{
	int ret = 0;

	if (state->enabled) {
		ret = augentix_pwm_config(chip, pwm, state->duty_cycle, state->period);
		if (ret)
			return ret;

		ret = augentix_pwm_enable(chip, pwm);
		if (ret)
			return ret;
	} else {
		augentix_pwm_disable(chip, pwm);
	}
	return 0;
}
#endif //LINUX_VERSION_CODE >= KERNEL_VERSION(4, 7, 0)

static const struct pwm_ops augentix_pwm_ops = {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 6, 0) && LINUX_VERSION_CODE < KERNEL_VERSION(6, 0, 0)
	.config = augentix_pwm_config,
	.enable = augentix_pwm_enable,
	.disable = augentix_pwm_disable,
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 7, 0)
	.apply = augentix_pwm_apply,
/* get_state is optional ops, will be used when export is called from sysfs */
//.get_state = augentix_pwm_get_state,
#endif
	.owner = THIS_MODULE,
};

static int augentix_pwm_probe(struct platform_device *pdev)
{
	struct augentix_pwm_chip *agtx_pwm;
	struct resource *r;
	struct device_node *np = pdev->dev.of_node;
	struct device *dev = &pdev->dev;
	int ret;
	int i = 0;

	agtx_pwm = devm_kzalloc(dev, sizeof(*agtx_pwm), GFP_KERNEL);
	if (!agtx_pwm) {
		dev_err(dev, "Allocating drvdata failed\n");
		return -ENOMEM;
	}

	platform_set_drvdata(pdev, agtx_pwm);

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	agtx_pwm->base = devm_ioremap_resource(dev, r);
	if (IS_ERR(agtx_pwm->base)) {
		dev_err(dev, "Failed to ioremap\n");
		return PTR_ERR(agtx_pwm->base);
	}

	agtx_pwm->dev = dev;
	agtx_pwm->chip.dev = dev;
	agtx_pwm->chip.ops = &augentix_pwm_ops;
	agtx_pwm->chip.base = -1; /* dynamic number for pwmchipX */
	agtx_pwm->chip.npwm = PWM_NUM;
	spin_lock_init(&agtx_pwm->lock);

	/* get system clock and interrupt */
	for (i = 0; i < PWM_NUM; i++) {
		agtx_pwm->clk[i] = of_clk_get(np, i);
		if (IS_ERR(agtx_pwm->clk[i])) {
			dev_err(dev, "Failed to get PWM %d clock\n", i);
			return -ENODEV;
		}
		ret = clk_prepare_enable(agtx_pwm->clk[i]);
		if (ret < 0) {
			dev_err(dev, "Failed to enable clock for PWM %d\n", i);
			return ret;
		}

		agtx_pwm->sys_clk[i] = clk_get_rate(agtx_pwm->clk[i]);

		agtx_pwm->irq[i] = irq_of_parse_and_map(pdev->dev.of_node, i);
		ret = devm_request_irq(dev, agtx_pwm->irq[i], augentix_pwm_irq_handler, IRQF_SHARED, pdev->name,
		                       agtx_pwm);
		if (ret != 0) {
			dev_err(dev, "Failed to request irq for PWM %d", i);
			return -EINVAL;
		}

		dev_info(dev, "PWM %d clock freq = %d Hz, intr %d\n", i, agtx_pwm->sys_clk[i], agtx_pwm->irq[i]);
	}

	ret = pwmchip_add(&agtx_pwm->chip);
	if (ret < 0) {
		dev_err(dev, "Failed to add pwmchip: %d\n", ret);
		return ret;
	}

	g_augentix_pwm_chip = agtx_pwm;
	dev_info(dev, "Augentix PWM driver probed: npwm=%u.\n", agtx_pwm->chip.npwm);

	return 0;
}

static int augentix_pwm_remove(struct platform_device *pdev)
{
	struct augentix_pwm_chip *agtx_pwm = platform_get_drvdata(pdev);
	int i = 0;

	dev_info(&pdev->dev, "Augentix PWM driver removed.\n");
	for (i = 0; i < PWM_NUM; i++) {
		clk_disable_unprepare(agtx_pwm->clk[i]);
		clk_put(agtx_pwm->clk[i]);
	}

	pwmchip_remove(&agtx_pwm->chip);

	return 0;
}

int augentix_pwm_aov_suspend_prepare(void)
{
	struct augentix_pwm_chip *agtx_pwm = g_augentix_pwm_chip;
	struct pwm_device pwm = { 0 };
	unsigned int i;

	if (!agtx_pwm)
		return -ENODEV;

#if DEBUG_LOG
	dev_info(agtx_pwm->dev, "aov pwm v2: suspend_prepare\n");
#endif

	for (i = 0; i < agtx_pwm->chip.npwm; i++) {
		pwm.hwpwm = i;
		__augentix_pwm_disable(&agtx_pwm->chip, &pwm);
	}

	return 0;
}

EXPORT_SYMBOL_GPL(augentix_pwm_aov_suspend_prepare);

int augentix_pwm_aov_resume_restore(void)
{
	struct augentix_pwm_chip *agtx_pwm = g_augentix_pwm_chip;
	struct pwm_device pwm = { 0 };
	unsigned int i;
	int first_err = 0;

	if (!agtx_pwm)
		return -ENODEV;

#if DEBUG_LOG
	dev_info(agtx_pwm->dev, "aov pwm v2: resume_restore\n");
#endif

	for (i = 0; i < agtx_pwm->chip.npwm; i++) {
		int ret;

		if (!g_augentix_pwm_snapshot[i].enabled)
			continue;

		pwm.hwpwm = i;
		ret = __augentix_pwm_enable(&agtx_pwm->chip, &pwm);
		if (ret && !first_err)
			first_err = ret;
	}

	return first_err;
}
EXPORT_SYMBOL_GPL(augentix_pwm_aov_resume_restore);

static const struct of_device_id augentix_pwm_of_match[] = {
	{ .compatible = "augentix,pwm" },
	{},
};

MODULE_DEVICE_TABLE(of, augentix_pwm_of_match);

static struct platform_driver augentix_pwm_driver = {
	.driver = {
		.name = "augentix_pwm",
		.owner = THIS_MODULE,
		.of_match_table = augentix_pwm_of_match,
	},
	.probe = augentix_pwm_probe,
	.remove = augentix_pwm_remove,
};

module_platform_driver(augentix_pwm_driver);

MODULE_DESCRIPTION("Augentix PWM driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eddie Lee, Augentix <eddie.lee@augentix.com>");
