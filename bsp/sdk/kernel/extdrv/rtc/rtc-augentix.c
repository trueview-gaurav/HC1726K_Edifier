/*
 * Augentix RTC Driver
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/rtc.h>
#include <linux/io.h>
#include <linux/interrupt.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/version.h>
#include <linux/pm_runtime.h>

#include "rtc-augentix.h"

#define IRQ_DISABLE	0
#define IRQ_ENABLE	1

struct agtx_rtc {
	void __iomem *base; /* PMU.RTC base */
	void __iomem *ck_base; /* PC.CK.DEF_APB_0 */
#if !defined(CONFIG_OSAKA)
	void __iomem *syscfg_base; /* PC.SYSCFG.PMU_EN */
#endif
	int irq;
	int prep_refcount;
	struct rtc_device *rtc;
	struct clk *clk;
};

struct agtx_rtc_time {
	u32 sec;
	u32 min;
	u32 hour;
	u32 day;
};

static void convert_to_rtc_time(struct agtx_rtc_time *art, struct rtc_time *tm)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 19, 0)
	time64_t total_secs;

	total_secs = (((time64_t)art->day * 24 + art->hour) * 60 + \
		     art->min) * 60 + art->sec;
	rtc_time64_to_tm(total_secs, tm);
#else
	unsigned long total_secs = 0;

	total_secs = ((art->day * 24UL + art->hour) * 60UL + art->min) * \
		     60UL + art->sec;
	rtc_time_to_tm(total_secs, tm);
#endif
}

static void convert_from_rtc_time(struct rtc_time *tm,
				  struct agtx_rtc_time *art)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 19, 0)
	time64_t temp_total_secs = rtc_tm_to_time64(tm);
	uint64_t total_secs = (uint64_t)temp_total_secs;
	u32 remainder;

	remainder = do_div(total_secs, 86400);
	art->day = total_secs;
	art->hour = tm->tm_hour;
	art->min = tm->tm_min;
	art->sec = tm->tm_sec;
#else
	unsigned long total_secs = 0;
	rtc_tm_to_time(tm, &total_secs);

	art->day  = total_secs / 86400UL;
	art->hour = tm->tm_hour;
	art->min = tm->tm_min;
	art->sec = tm->tm_sec;
#endif
}

static inline void unpack_time(struct agtx_rtc_time *art, u32 val)
{
	art->sec  = (val >> TIME_SEC_READ_OFFSET)  & SEC_MASK;
	art->min  = (val >> TIME_MIN_READ_OFFSET)  & MIN_MASK;
	art->hour = (val >> TIME_HOUR_READ_OFFSET) & HOUR_MASK;
	art->day  = (val >> TIME_DAY_READ_OFFSET)  & DAY_MASK;
}

static inline u32 pack_time(const struct agtx_rtc_time *art)
{
	return ((art->sec  & SEC_MASK)  << TIME_SEC_WRITE_OFFSET)  |
	       ((art->min  & MIN_MASK)  << TIME_MIN_WRITE_OFFSET)  |
	       ((art->hour & HOUR_MASK) << TIME_HOUR_WRITE_OFFSET) |
	       ((art->day  & DAY_MASK)  << TIME_DAY_WRITE_OFFSET);
}

static void agtx_rtc_prepare(struct agtx_rtc *ar)
{
	u32 reg;

	if (ar->prep_refcount++ > 0)
		return;

	/* Underclocking */
	reg = readl(ar->ck_base);
#if defined(CONFIG_OSAKA)
	reg |= 0x101;
#else
	reg |= 0x01;
#endif
	writel(reg, ar->ck_base);

#if !defined(CONFIG_OSAKA)
	/* Enable PMU APB */
	writel((1 << PMU_APB_READ_OFFSET) | (1 << PMU_APB_WRITE_OFFSET) |
	       (1 << PMU_APB_IRQ_OFFSET), ar->syscfg_base);
#endif
}

static void agtx_rtc_unprepare(struct agtx_rtc *ar)
{
	u32 reg;

	if (--ar->prep_refcount > 0)
		return;

#if !defined(CONFIG_OSAKA)
	/* Disable PMU APB read / write */
	writel(~((1 << PMU_APB_READ_OFFSET) | (1 << PMU_APB_WRITE_OFFSET)),
	       ar->syscfg_base);
#endif
	/* Disable underclocking */
	reg = readl(ar->ck_base);
#if defined(CONFIG_OSAKA)
	reg &= ~0x101;
#else
	reg &= 0xFFFFFFF8;
#endif
	writel(reg, ar->ck_base);
}

static int agtx_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct agtx_rtc *ar = dev_get_drvdata(dev);
	struct agtx_rtc_time art;
	u32 val = 0;
	u32 state;
	s32 timeout = AGTX_RTC_TIMEOUT_USEC;

	agtx_rtc_prepare(ar);

	/* Trigger read operation */
	writel((1 << READ_OFFSET), ar->base + AGTX_RTC_CTRL);
	/* Delay at least 5T (152us) */
	udelay(200);

	/* Wait for hardware to complete the read */
	state = (readl(ar->base + AGTX_RTC_STATE) >> READ_DONE_OFFSET) & 0x1;
	while (state == RTC_READING) {
		if (--timeout == 0) {
			pr_err("augentix-rtc: Timeout waiting for RTC "
			       "READ_DONE\n");
			goto err_timeout;
		}
		udelay(200);
		state = (readl(ar->base + AGTX_RTC_STATE) >>
			 READ_DONE_OFFSET) & 0x1;
	}

	/* Retrieve and return time value from hardware */
	val = readl(ar->base + AGTX_TIME_READ);
	unpack_time(&art, val);
	convert_to_rtc_time(&art, tm);

	agtx_rtc_unprepare(ar);

	return 0;
err_timeout:
	agtx_rtc_unprepare(ar);
	return -ETIMEDOUT;
}

static int agtx_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct agtx_rtc_time art;
	struct agtx_rtc *ar = dev_get_drvdata(dev);
	u32 val = 0;
	u32 state;
	s32 timeout = AGTX_RTC_TIMEOUT_USEC;

	if (rtc_valid_tm(tm) < 0)
		return -EINVAL;

	agtx_rtc_prepare(ar);

	convert_from_rtc_time(tm, &art);
	val = pack_time(&art);

	/* Load time value to be written */
	writel(val, ar->base + AGTX_TIME_WRITE);

	/* Trigger write operation */
	writel((1 << WRITE_OFFSET), ar->base + AGTX_RTC_CTRL);
	/* At least wait 187us (6T) */
	udelay(200);

	/* Wait until write completion */
	state = (readl(ar->base + AGTX_RTC_STATE) >> WRITE_DONE_OFFSET) & 0x1;
	while (state == RTC_WRITING) {
		if (--timeout == 0) {
			pr_err("augentix-rtc: Timeout waiting for RTC "
			       "WRITE_DONE\n");
			goto err_timeout;
		}
		udelay(200);
		state = (readl(ar->base + AGTX_RTC_STATE) >>
			 WRITE_DONE_OFFSET) & 0x1;
	}

	agtx_rtc_unprepare(ar);

	return 0;
err_timeout:
	agtx_rtc_unprepare(ar);
	return -ETIMEDOUT;
}

static int agtx_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct agtx_rtc_time art;
	struct agtx_rtc *ar = dev_get_drvdata(dev);
	u32 val = 0;
	u32 mask = 0;

	agtx_rtc_prepare(ar);

	val = readl(ar->base + AGTX_ALARM_PMU);
	unpack_time(&art, val);
	convert_to_rtc_time(&art, &alrm->time);

	mask = readl(ar->base + AGTX_IRQ_MASK);
	alrm->enabled = !(mask & (1 << IRQ_MASK_ALARM_PMU_OFFSET));
	alrm->pending = 0;

	agtx_rtc_unprepare(ar);

	return 0;
}

static int agtx_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct agtx_rtc *ar = dev_get_drvdata(dev);
	u32 mask = 0;

	agtx_rtc_prepare(ar);

	/* Get current IRQ mask status */
	mask = readl(ar->base + AGTX_IRQ_MASK);

	/* Set IRQ mask */
	if (enabled == IRQ_ENABLE)
		mask &= ~(1 << IRQ_MASK_ALARM_PMU_OFFSET);
	else
		mask |= (1 << IRQ_MASK_ALARM_PMU_OFFSET);
	writel(mask, ar->base + AGTX_IRQ_MASK);

	agtx_rtc_unprepare(ar);

	return 0;
}

static int agtx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct agtx_rtc_time art;
	struct agtx_rtc *ar = dev_get_drvdata(dev);
	struct rtc_time *tm = &alrm->time;
	u32 status;
	u32 val = 0;
	bool pmu_alarm;

	if (rtc_valid_tm(tm) < 0)
		return -EINVAL;

	agtx_rtc_prepare(ar);

	/* Retrieve time to be set */
	convert_from_rtc_time(tm, &art);
	val = pack_time(&art);

	/* Ensure IRQ status is not set */
	do {
		status = readl(ar->base + AGTX_IRQ_STATUS);
		pmu_alarm = !!(status & (1 << STATUS_MATCH_ALARM_PMU_OFFSET));
		if (pmu_alarm == true) {
			writel((1 << IRQ_CLEAR_ALARM_PMU_OFFSET), ar->base +
			       AGTX_IRQ_CLEAR);
			udelay(200);
		}
	} while (pmu_alarm == true);

	/* Disable IRQ during alarm time setup */
	agtx_rtc_alarm_irq_enable(dev, IRQ_DISABLE);
	writel(val, ar->base + AGTX_ALARM_PMU);
	agtx_rtc_alarm_irq_enable(dev, IRQ_ENABLE);

	agtx_rtc_unprepare(ar);

	return 0;
}

static irqreturn_t agtx_rtc_irq_handler(int irq, void *dev_id)
{
	struct agtx_rtc *ar = dev_id;
	u32 status;
	bool cpu_alarm;
	bool pmu_alarm;

	agtx_rtc_prepare(ar);

	status = readl(ar->base + AGTX_IRQ_STATUS);
	cpu_alarm = !!(status & (1 << STATUS_MATCH_ALARM_CPU_OFFSET));
	pmu_alarm = !!(status & (1 << STATUS_MATCH_ALARM_PMU_OFFSET));
	if (cpu_alarm == false && pmu_alarm == false) {
		pr_err("augentix-rtc: Unexpected IRQ status=0x%x\n", status);
		goto err_irq_none;
	}

	if (cpu_alarm)
		writel((1 << IRQ_CLEAR_ALARM_CPU_OFFSET), ar->base +
		       AGTX_IRQ_CLEAR);
	if (pmu_alarm)
		writel((1 << IRQ_CLEAR_ALARM_PMU_OFFSET), ar->base +
		       AGTX_IRQ_CLEAR);

	/* Inform the RTC subsystem of an RTC interrupt event. */
	rtc_update_irq(ar->rtc, 1, RTC_IRQF | RTC_AF);

	agtx_rtc_unprepare(ar);

	return IRQ_HANDLED;
err_irq_none:
	agtx_rtc_unprepare(ar);
	return IRQ_NONE;
}

static const struct rtc_class_ops agtx_rtc_ops = {
	.read_time = agtx_rtc_read_time,
	.set_time = agtx_rtc_set_time,
	.read_alarm = agtx_rtc_read_alarm,
	.set_alarm = agtx_rtc_set_alarm,
	.alarm_irq_enable = agtx_rtc_alarm_irq_enable,
};

static int agtx_rtc_hw_reset(struct device *dev, struct rtc_time *tm)
{
	struct agtx_rtc *ar = dev_get_drvdata(dev);
	u32 rst_state;
	u32 csr = 0;
	int ret;

	agtx_rtc_prepare(ar);

	/* Check if RTC has been reset */
	rst_state = readl(ar->base + AGTX_RTC_RST_STATE);
	if (rst_state == RTC_RST_MAGIC) {
		dev_info(dev, "RTC reset detected, reinitializing "
			      "time\n");
		ret = agtx_rtc_set_time(dev, tm);
		if (ret)
			goto err_exit;
		writel(0, ar->base + AGTX_RTC_RST_STATE);

		/* Set IRQ mask to 1 to prevent false positives when checking
		 * for active alarms during a read operation.
 		 */
		csr = (1 << IRQ_MASK_ALARM_CPU_OFFSET) | \
		      (1 << IRQ_MASK_ALARM_PMU_OFFSET);
		writel(csr, ar->base + AGTX_IRQ_MASK);
	}

	/* Check if RTC is counting */
	if (((readl(ar->base + AGTX_RTC_STATE) >> COUNTING_BUSY_OFFSET) &
	     0x1) != RTC_COUNTING) {
		writel((1 << RUN_STOP_OFFSET), ar->base + AGTX_RTC_CTRL);
		do {
			udelay(200);
		} while (((readl(ar->base + AGTX_RTC_STATE) >> 
			  COUNTING_BUSY_OFFSET) & 0x1) != RTC_COUNTING);
	}

	agtx_rtc_unprepare(ar);

	return 0;
err_exit:
	agtx_rtc_unprepare(ar);
	return ret;
}

static int agtx_rtc_probe(struct platform_device *pdev)
{
	struct agtx_rtc *ar;
	struct resource *res;
	struct rtc_time tm = { .tm_year = 2025 - 1900, .tm_mon = 0,
			       .tm_mday = 1, .tm_hour = 0, .tm_min = 0,
			       .tm_sec = 0, };
	int ret;

	ar = devm_kzalloc(&pdev->dev, sizeof(*ar), GFP_KERNEL);
	if (!ar)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ar->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ar->base))
		return PTR_ERR(ar->base);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	ar->ck_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ar->ck_base))
		return PTR_ERR(ar->ck_base);

#if !defined(CONFIG_OSAKA)
	res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
	ar->syscfg_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ar->syscfg_base))
		return PTR_ERR(ar->syscfg_base);
#endif

	ar->irq = platform_get_irq(pdev, 0);
	if (ar->irq < 0)
		return ar->irq;
	ret = devm_request_irq(&pdev->dev, ar->irq, agtx_rtc_irq_handler, 0,
			       dev_name(&pdev->dev), ar);
	if (ret)
		dev_err(&pdev->dev, "failed to request IRQ: %d\n", ret);
	else
		dev_info(&pdev->dev, "IRQ %d registered successfully\n",
			 ar->irq);

	platform_set_drvdata(pdev, ar);

	ret = agtx_rtc_hw_reset(&pdev->dev, &tm);
	if (ret)
		return ret;

	dev_info(&pdev->dev, "RTC started.\n");

	device_init_wakeup(&pdev->dev, true);

	ar->rtc = devm_rtc_device_register(&pdev->dev, dev_name(&pdev->dev),
					   &agtx_rtc_ops, THIS_MODULE);
	if (IS_ERR(ar->rtc))
		return PTR_ERR(ar->rtc);

	return 0;
}

#ifdef CONFIG_PM
static int agtx_rtc_suspend(struct device *dev)
{
	struct agtx_rtc *ar = dev_get_drvdata(dev);
#if 0
	u32 val = 0;
	u32 status;
	bool pmu_alarm;
#endif /* 0 */

	if (device_may_wakeup(dev)) {
		enable_irq_wake(ar->irq);

		/* Set alarm to wakeup system if needed */
#if 0
		agtx_rtc_prepare(ar);
		/* Ensure IRQ status is not set */
		do {
			status = readl(ar->base + AGTX_IRQ_STATUS);
			pmu_alarm = !!(status & (1 << STATUS_MATCH_ALARM_PMU_OFFSET));
			if (pmu_alarm == true) {
				writel((1 << IRQ_CLEAR_ALARM_PMU_OFFSET), ar->base +
					AGTX_IRQ_CLEAR);
				udelay(200);
			}
		} while (pmu_alarm == true);

		/* Disable IRQ during alarm time setup */
		agtx_rtc_alarm_irq_enable(dev, IRQ_DISABLE);

		/* Get and set alarm time */
		val = readl(ar->base + AGTX_ALARM_PMU) + 10;
		writel(val, ar->base + AGTX_ALARM_PMU);

		agtx_rtc_alarm_irq_enable(dev, IRQ_ENABLE);

		agtx_rtc_unprepare(ar);
#endif /* 0 */
	}

	return 0;
}

static int agtx_rtc_resume(struct device *dev)
{
	struct agtx_rtc *ar = dev_get_drvdata(dev);

	if (device_may_wakeup(dev))
		disable_irq_wake(ar->irq);

	return 0;
}

static const struct dev_pm_ops agtx_rtc_pm_ops = {
	.suspend = agtx_rtc_suspend,
	.resume  = agtx_rtc_resume,
};
#endif /* CONFIG_PM */

static int agtx_rtc_remove(struct platform_device *pdev)
{
	device_init_wakeup(&pdev->dev, false);
	return 0;
}

static const struct of_device_id agtx_rtc_of_match[] = {
	{ .compatible = "augentix,rtc" },
	{ /* sentinel */ },
};
MODULE_DEVICE_TABLE(of, agtx_rtc_of_match);

static struct platform_driver agtx_rtc_driver = {
	.probe = agtx_rtc_probe,
	.remove = agtx_rtc_remove,
	.driver = {
		.name = "augentix-rtc",
		.of_match_table = agtx_rtc_of_match,
#ifdef CONFIG_PM
		.pm = &agtx_rtc_pm_ops,
#endif
	},
};

static int __init agtx_rtc_driver_init(void)
{
	return platform_driver_register(&agtx_rtc_driver);
}
subsys_initcall(agtx_rtc_driver_init);

static void __exit agtx_rtc_driver_exit(void)
{
	platform_driver_unregister(&agtx_rtc_driver);
}
module_exit(agtx_rtc_driver_exit);

MODULE_AUTHOR("Augentix Inc.");
MODULE_DESCRIPTION("Augentix RTC Driver");
MODULE_LICENSE("GPL");