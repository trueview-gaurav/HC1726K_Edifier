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

static inline struct augentix_pwm_chip *to_augentix_pwm_chip(struct pwm_chip *chip)
{
	return container_of(chip, struct augentix_pwm_chip, chip);
}

static inline u32 augentix_pwm_get(void __iomem *base, int idx, u32 offset)
{
	return readl(base + (PWMX_OFFSET * idx) + offset);
}
static inline void augentix_pwm_set(void __iomem *base, int idx, u32 offset, u32 val)
{
	writel(val, base + (PWMX_OFFSET * idx) + offset);
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
		reg = augentix_pwm_get(base, agtx_pwm->pin_to_kernel[i], PWM_R1);
		if (reg & PWM_R1_ST) {
			augentix_pwm_set(base, agtx_pwm->pin_to_kernel[i], PWM_R0, PWM_R0_INTC);
			return IRQ_HANDLED;
		}
	}
	return IRQ_NONE;
}

static int augentix_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm, int duty_ns, int period_ns)
{
	/* pwm->hwpwm = X of pwmX in sysfs, see it as pin */
	int index = pwm->hwpwm;
	struct augentix_pwm_chip *agtx_pwm = to_augentix_pwm_chip(chip);
	void __iomem *base = agtx_pwm->base;
	int kernel = agtx_pwm->pin_to_kernel[index];
	struct device *dev = agtx_pwm->dev;
	uint32_t sys_clk = agtx_pwm->sys_clk[index];
	unsigned long long temp;
	unsigned long long mod;
	uint32_t max_freq;
	uint32_t prescaled_freq;
	uint32_t cnt_high = 0;
	uint32_t cnt_period;
	uint8_t cnt_psc = 0;
	unsigned long flags;

	DBG("Set Kernel %d, duty_ns = %d ns, period_ns = %d ns\n", kernel, duty_ns, period_ns);

	/* Min frequency is sys_clk / 2^prescaler_max / max_count_period,
	 * if NUM_1G < (min_freq * period_ns),
	 * sys_clk should be larger than NUM_1G * 2^prescaler_max which is impossible for us.
	 *
	 * Max frequency is sys_clk / 2 (at least cnt_high = 1, cnt_period = 2)
	 * (NUM_1G / max_freq) > period_ns is used to prevent overflow
	 */
	max_freq = sys_clk >> 1;
	if ((NUM_1G / max_freq) > period_ns) {
		dev_err(dev, "Augentix PWM kernel %d max frequency is %u Hz, intended setting is %u Hz\n", kernel,
		        max_freq, NUM_1G / period_ns);
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
	augentix_pwm_set(base, kernel, PWM_R3,
	                 (cnt_psc << PWM_R3_PRES_B | (cnt_period << PWM_R3_PERIOD_B) | (cnt_high << PWM_R3_HIGH_B)));
	spin_unlock_irqrestore(&agtx_pwm->lock, flags);

	dev_info(dev, "(Interger format) requested frquency: %d Hz, provided frquency: %d Hz, duty: %u%%\n",
	         NUM_1G / period_ns, prescaled_freq, cnt_high * 100 / cnt_period);
	DBG("mod = %llu, cnt_psc = %u, cnt_high = %u, cnt_period = %u\n", mod, cnt_psc, cnt_high, cnt_period);

	return 0;
}

static int augentix_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct augentix_pwm_chip *agtx_pwm = to_augentix_pwm_chip(chip);
	/* pwm->hwpwm = X of pwmX in sysfs, see it as pin */
	int kernel = agtx_pwm->pin_to_kernel[pwm->hwpwm];
	void __iomem *base = agtx_pwm->base;

	if (augentix_pwm_get(base, kernel, PWM_R1) & PWM_R1_BUSY) {
		dev_warn(agtx_pwm->dev, "PWM kernel %d is already enabled\n", kernel);
		return 0;
	}
	augentix_pwm_set(base, kernel, PWM_R0, (PWM_R0_TRIG | PWM_R0_INTC));
	dev_info(agtx_pwm->dev, "Enable PWM kernel %d\n", kernel);

	return 0;
}

static void augentix_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct augentix_pwm_chip *agtx_pwm = to_augentix_pwm_chip(chip);
	/* pwm->hwpwm = X of pwmX in sysfs, see it as pin */
	int kernel = agtx_pwm->pin_to_kernel[pwm->hwpwm];
	void __iomem *base = agtx_pwm->base;

	if ((augentix_pwm_get(base, kernel, PWM_R1) & PWM_R1_BUSY)) {
		augentix_pwm_set(base, kernel, PWM_R0, (PWM_R0_TRIG | PWM_R0_INTC));
		dev_info(agtx_pwm->dev, "Disable PWM kernel %d\n", kernel);
	}
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
	u32 val_out_sel_0 = 0;
	u32 val_out_sel_1 = 0;
	int kernel_to_pin[PWM_NUM];
	int index;

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

	ret = of_property_read_u32_array(np, "outsel", kernel_to_pin, PWM_NUM);
	for (i = 0; i < PWM_NUM; i++) {
		if (ret) {
			/* When "outsel" is not used in dts, make kernel X to pin X */
			dev_info(dev, "Property \"outsel\" is not found in dts, set out_sel in order\n");
			agtx_pwm->pin_to_kernel[i] = i;
		} else {
			/* the dts property "outsel" used before means kernel_to_pin
			 * to keep forward compatibility, this won't be changed
			 * when using pwmX on sysfs, X follows the pin logic, don't care with kenrel
			 * reverse logic here to simplify logic for ops and setting csr out_sel*/
			index = kernel_to_pin[i];
			agtx_pwm->pin_to_kernel[index] = i;
		}
	}

	/* get system clock and interrupt */
	for (i = 0; i < PWM_NUM; i++) {
		/* i is used as kernel num, index is used as pin num*/
		index = kernel_to_pin[i];

		agtx_pwm->clk[index] = of_clk_get(np, i);
		if (IS_ERR(agtx_pwm->clk[index])) {
			dev_err(dev, "Failed to get PWM %d clock\n", index);
			return -ENODEV;
		}
		ret = clk_prepare_enable(agtx_pwm->clk[i]);
		if (ret < 0) {
			dev_err(dev, "Failed to enable clock for PWM kernel %d\n", i);
			return ret;
		}

		agtx_pwm->sys_clk[index] = clk_get_rate(agtx_pwm->clk[index]);

		agtx_pwm->irq[index] = irq_of_parse_and_map(pdev->dev.of_node, i);
		ret = devm_request_irq(dev, agtx_pwm->irq[index], augentix_pwm_irq_handler, IRQF_SHARED, pdev->name,
		                       agtx_pwm);
		if (ret != 0) {
			dev_err(dev, "Failed to request irq for PWM %d", i);
			return -EINVAL;
		}

		/* out_sel 0~3 in PWM_OUT_SEL_0, out_sel 4~5 in PWM_OUT_SEL_1 
		 * csr out_sel here means pin_to_kernel, see i as pin here 
		 * This loop can't move to loop above */
		if (index < 4)
			val_out_sel_0 |= (i << (8 * index));
		else
			val_out_sel_1 |= (i << (8 * (index - 4)));

		dev_info(dev, "PWM %d clock freq = %d Hz, from PWM kernel %d, intr %d\n", index,
		         agtx_pwm->sys_clk[index], agtx_pwm->pin_to_kernel[index], agtx_pwm->irq[index]);
	}

	writel(val_out_sel_0, agtx_pwm->base + PWM_OUT_SEL_0);
	writel(val_out_sel_1, agtx_pwm->base + PWM_OUT_SEL_1);
	DBG("[PWM] out_sel_0 = 0x%08X, out_sel_1 = 0x%08X\n", val_out_sel_0, val_out_sel_1);

	ret = pwmchip_add(&agtx_pwm->chip);
	if (ret < 0) {
		dev_err(dev, "Failed to add pwmchip: %d\n", ret);
		return ret;
	}

	dev_info(dev, "Augentix PWM driver probed.\n");

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
MODULE_AUTHOR("Augentix Inc.");
