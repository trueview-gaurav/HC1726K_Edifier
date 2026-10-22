// #define DEBUG
// #define pr_fmt(fmt) "%s(): " fmt, __func__

#include <linux/clk.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/watchdog.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <linux/of_irq.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <linux/console.h>

/* Region AMC */
#define AON_WDT_IRQ_CLR_OFFSET 0x04
#define AON_WDT_IRQ_MSK_OFFSET 0x08
#define AON_WDT_STAT_OFFSET 0x0C
#define AON_WDT_SLEEP_OFFSET 0x18
#define AON_WDT_EN_SRC_OFFSET 0x20

/* Region AON_WDT */
#define AON_WDT_DIS_WDT_OFFSET 0x00
#define AON_WDT_PRE_TH_OFFSET 0x04
#define AON_WDT_CNT_TH0_OFFSET 0x08
#define AON_WDT_CNT_TH1_OFFSET 0x0C
#define AON_WDT_CNT_TH2_OFFSET 0x10
#define AON_WDT_CNT_OFFSET 0x14
#define AON_WDT_STAGE_OFFSET 0x18

/* Control Register */
#define AON_WDT_PRE_VAL 0xFFFF
#define AON_WDT_CNT0_VAL 0xFFFF // Use PWR_DN stage as STAGE 1
#define AON_WDT_CNT2_VAL 0x1 // Use WAKEUP stage as STAGE 2

#define AON_WDT_EN_SRC_CIRCUIT 0x0
#define AON_WDT_EN_SRC_CPU 0x1
#define AON_WDT_EN_CSR_ACTIVE (0x1 << 8)

#define AON_WDT_IRQ_CLR (0x1 << 9)
#define AON_WDT_IRQ_MSK ~(0x1 << 9)

#define DEFAULT_TIMEOUT 30
#define MAX_TIMEOUT 90
#define ONE_SEC_CNT 0x16F
#define RESET_PERIOD_MS 100

static bool wdt_log = false;

static DEFINE_SPINLOCK(g_wdt_lock); // Used in arch-level reboot function

static unsigned int timeout = DEFAULT_TIMEOUT;
module_param(timeout, uint, 0);
MODULE_PARM_DESC(timeout, "AON Watchdog timeout in seconds. (>=0, default=" __MODULE_STRING(DEFAULT_TIMEOUT) ")");

static bool nowayout = WATCHDOG_NOWAYOUT;
module_param(nowayout, bool, 0);
MODULE_PARM_DESC(nowayout, "Watchdog cannot be stopped once started(default=" __MODULE_STRING(WATCHDOG_NOWAYOUT) ")");

/* aon wdt device data */
struct aon_wdt_pdata {
	struct watchdog_device wdd;
	int irq;
	void __iomem *wdt_base;
	void __iomem *amc_base;
	struct clk *clk;
	int hz;
};

static struct aon_wdt_pdata *g_aon_wdt;

static __attribute__((unused)) int __init wdt_log_setup(char *str)
{
	if (str[0] == '1') {
		wdt_log = true;
	} else {
		wdt_log = false;
	}
	return 1;
}

__setup("wdt_log=", wdt_log_setup);

static const struct watchdog_info aon_wdt_info = {
	.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT | WDIOF_MAGICCLOSE,
	.identity = "Augentix AON Watchdog",
};

static void direct_console_write(const char *text, size_t len)
{
	struct console *con;

	if (!console_drivers)
		return;

	for_each_console (con) {
		if (!(con->flags & CON_ENABLED))
			continue;
		if (!con->write)
			continue;
		if (!cpu_online(smp_processor_id()) && !(con->flags & CON_ANYTIME))
			continue;
		con->write(con, text, len);
	}
}

static irqreturn_t aon_wdt_irq_handler(int irq, void *dev_id)
{
	struct aon_wdt_pdata *aon_wdt = (struct aon_wdt_pdata *)dev_id;
	void __iomem *amc_off;
	uint32_t t_reg;

	printk(KERN_ALERT "[AON WDT] Watchdog timed out.\n");

	amc_off = aon_wdt->amc_base;
	t_reg = AON_WDT_IRQ_CLR;
	writel_relaxed(t_reg, amc_off + AON_WDT_IRQ_CLR_OFFSET);

	return IRQ_HANDLED;
}

static void __aon_wdt_enable(volatile void *addr)
{
	writel_relaxed(AON_WDT_EN_SRC_CPU | AON_WDT_EN_CSR_ACTIVE, addr);
}

static void __aon_wdt_disable(volatile void *addr)
{
	writel_relaxed(AON_WDT_EN_SRC_CPU & ~AON_WDT_EN_CSR_ACTIVE, addr);
}

static int aon_wdt_ping(struct watchdog_device *wdd)
{
	struct aon_wdt_pdata *aon_wdt = watchdog_get_drvdata(wdd);
	void __iomem *amc_off, *wdt_off;
	uint32_t count;
	char *str = "[AGTX_WDT] ticked\n\r";

	amc_off = aon_wdt->amc_base;
	wdt_off = aon_wdt->wdt_base;

	if (wdt_log) {
		direct_console_write(str, strlen(str));
	}
RETRY:
	spin_lock(&g_wdt_lock);
	__aon_wdt_disable(amc_off + AON_WDT_EN_SRC_OFFSET);
	while ((readl_relaxed(wdt_off + AON_WDT_STAGE_OFFSET) & 0x3) != 0) {
		__aon_wdt_enable(amc_off + AON_WDT_EN_SRC_OFFSET);
		__aon_wdt_disable(amc_off + AON_WDT_EN_SRC_OFFSET);
	}

	__aon_wdt_enable(amc_off + AON_WDT_EN_SRC_OFFSET);
	while ((readl_relaxed(wdt_off + AON_WDT_STAGE_OFFSET) & 0x3) != 1) {
		__aon_wdt_disable(amc_off + AON_WDT_EN_SRC_OFFSET);
		__aon_wdt_enable(amc_off + AON_WDT_EN_SRC_OFFSET);
	}
	count = readl_relaxed(wdt_off + AON_WDT_CNT_OFFSET) & 0xFFFF;
	spin_unlock(&g_wdt_lock);
	if (count > 3) { //3 cycles = 8.1ms
		goto RETRY;
	}

	return 0;
}

static int aon_wdt_start(struct watchdog_device *wdd)
{
	struct aon_wdt_pdata *aon_wdt = watchdog_get_drvdata(wdd);
	void __iomem *wdt_off, *amc_off;
	uint32_t t_reg;

	wdt_off = aon_wdt->wdt_base;
	amc_off = aon_wdt->amc_base;

	spin_lock(&g_wdt_lock);
	if ((readl_relaxed(wdt_off + AON_WDT_DIS_WDT_OFFSET) & 0x1) != 0)
		writel_relaxed(0x0, wdt_off + AON_WDT_DIS_WDT_OFFSET);

	t_reg = *(volatile uint32_t *)(amc_off + AON_WDT_EN_SRC_OFFSET);
	if ((t_reg & 0x101) != 0x101) {
		__aon_wdt_enable(amc_off + AON_WDT_EN_SRC_OFFSET);
		while ((readl_relaxed(wdt_off + AON_WDT_STAGE_OFFSET) & 0x3) != 1) {
			__aon_wdt_disable(amc_off + AON_WDT_EN_SRC_OFFSET);
			__aon_wdt_enable(amc_off + AON_WDT_EN_SRC_OFFSET);
		}
	}
	spin_unlock(&g_wdt_lock);

	return 0;
}

static int aon_wdt_stop(struct watchdog_device *wdd)
{
	struct aon_wdt_pdata *aon_wdt = watchdog_get_drvdata(wdd);
	void __iomem *amc_off, *wdt_off;
	uint32_t t_reg;

	wdt_off = aon_wdt->wdt_base;
	amc_off = aon_wdt->amc_base;

	spin_lock(&g_wdt_lock);
	t_reg = *(volatile uint32_t *)(amc_off + AON_WDT_EN_SRC_OFFSET);
	if ((t_reg & 0x101) != 0x0) {
		__aon_wdt_disable(amc_off + AON_WDT_EN_SRC_OFFSET);
		while ((readl_relaxed(wdt_off + AON_WDT_STAGE_OFFSET) & 0x3) != 0) {
			__aon_wdt_enable(amc_off + AON_WDT_EN_SRC_OFFSET);
			__aon_wdt_disable(amc_off + AON_WDT_EN_SRC_OFFSET);
		}
	}
	spin_unlock(&g_wdt_lock);

	return 0;
}

static int aon_wdt_convert_cnt(struct watchdog_device *wdd, unsigned int timeout)
{
	struct aon_wdt_pdata *aon_wdt = watchdog_get_drvdata(wdd);
	void __iomem *wdt_off;
	uint32_t t_reg;
	uint32_t cnt_tmp;
	int wdt_hz;

	wdt_off = aon_wdt->wdt_base;
	t_reg = *(volatile uint32_t *)(wdt_off + AON_WDT_PRE_TH_OFFSET);
	t_reg &= 0xFFFF;

	wdt_hz = aon_wdt->hz;
	cnt_tmp = timeout * wdt_hz / (t_reg + 1);

	return cnt_tmp;
}

static int aon_wdt_set_timeout(struct watchdog_device *wdd, unsigned int timeout)
{
	struct aon_wdt_pdata *aon_wdt = watchdog_get_drvdata(wdd);
	void __iomem *wdt_off;
	uint32_t cnt_tmp;

	if (timeout < 0 || timeout > MAX_TIMEOUT) {
		pr_err("Timeout value must be 0 <= x <= %d\n", MAX_TIMEOUT);
		return -EINVAL;
	}

	wdt_off = aon_wdt->wdt_base;
	wdd->timeout = timeout;

	/* Set AON WDT register - PWR_DN STAGE (Stage 1) */
	cnt_tmp = (uint32_t)aon_wdt_convert_cnt(wdd, timeout);
	writel_relaxed(cnt_tmp, wdt_off + AON_WDT_CNT_TH0_OFFSET);

	aon_wdt_stop(wdd);
	ndelay(50);
	aon_wdt_start(wdd);

	return 0;
}

static long aon_wdt_ioctl(struct watchdog_device *wdd, unsigned int cmd, unsigned long arg)
{
	void __user *argp = (void __user *)arg;
	int __user *p = argp;
	int new_value;

	switch (cmd) {
	case WDIOC_KEEPALIVE:
		aon_wdt_ping(wdd);
		return 0;
	case WDIOC_SETTIMEOUT:
		if (get_user(new_value, p))
			return -EFAULT;
		aon_wdt_set_timeout(wdd, new_value);
		return 0;
	default:
		return -ENOTTY;
	}
}

// static unsigned int aon_wdt_get_timeleft(struct watchdog_device *wdd)
// {
// 	struct aon_wdt_pdata *aon_wdt = watchdog_get_drvdata(wdd);
// 	void __iomem *wdt_off;
// 	unsigned int cnt, pre;

// 	wdt_off = aon_wdt->wdt_base;
// 	cnt = readl_relaxed(wdt_off + AON_WDT_CNT_OFFSET) & 0xFFFF;
// 	pre = readl_relaxed(wdt_off + AON_WDT_PRE_TH_OFFSET) & 0xFFFF;

// 	return (cnt * (pre + 1) / aon_wdt->hz);
// }

static const struct watchdog_ops aon_wdt_ops = {
	.owner = THIS_MODULE,
	.start = aon_wdt_start,
	.stop = aon_wdt_stop,
	.ping = aon_wdt_ping,
	.ioctl = aon_wdt_ioctl,
	.set_timeout = aon_wdt_set_timeout,
	// .get_timeleft = aon_wdt_get_timeleft,
};

static int aon_wdt_setreg_forssys(struct watchdog_device *wdd, struct platform_device *pdev)
{
	struct aon_wdt_pdata *aon_wdt = watchdog_get_drvdata(wdd);
	void __iomem *wdt_off, *amc_off;
	uint32_t t_reg;
	uint32_t cnt0, cnt2;
	uint32_t dt0, dt2;
	struct device_node *np = pdev->dev.of_node;
	unsigned long flags;

	wdt_off = aon_wdt->wdt_base;
	amc_off = aon_wdt->amc_base;

	/* Set prescaler for all stage */
	t_reg = AON_WDT_PRE_VAL;
	spin_lock_irqsave(&g_wdt_lock, flags);
	writel_relaxed(t_reg, wdt_off + AON_WDT_PRE_TH_OFFSET);
	spin_unlock_irqrestore(&g_wdt_lock, flags);

	/* Set timeout values by device tree */
	if (of_property_read_u32(np, "count0", &dt0)) {
		dev_err(&pdev->dev, "invalid count value for stage 1\n");
		return -ERANGE;
	}

	cnt0 = (uint32_t)aon_wdt_convert_cnt(wdd, dt0);

	if (of_property_read_u32(np, "count2", &dt2)) {
		dev_err(&pdev->dev, "invalid count value for stage 2\n");
		return -ERANGE;
	}

	cnt2 = (uint32_t)aon_wdt_convert_cnt(wdd, dt2) << 16;

	spin_lock_irqsave(&g_wdt_lock, flags);
	writel_relaxed(cnt0, wdt_off + AON_WDT_CNT_TH0_OFFSET);
	writel_relaxed(cnt2, wdt_off + AON_WDT_CNT_TH2_OFFSET);
	t_reg = readl_relaxed(amc_off + AON_WDT_IRQ_MSK_OFFSET) & AON_WDT_IRQ_MSK;
	writel_relaxed(t_reg, amc_off + AON_WDT_IRQ_MSK_OFFSET);
	spin_unlock_irqrestore(&g_wdt_lock, flags);

	return 0;
}

void aon_wdt_reboot(volatile void *wdt_base, volatile void *amc_base)
{
	unsigned long flags;
	pr_debug("[AON WDT] Rebooting...\n");

	spin_lock_irqsave(&g_wdt_lock, flags);
	__aon_wdt_disable(amc_base + AON_WDT_EN_SRC_OFFSET);
	while ((readl_relaxed(wdt_base + AON_WDT_STAGE_OFFSET) & 0x3) != 0) {
		__aon_wdt_enable(amc_base + AON_WDT_EN_SRC_OFFSET);
		__aon_wdt_disable(amc_base + AON_WDT_EN_SRC_OFFSET);
	}

	writel_relaxed(RESET_PERIOD_MS, wdt_base + AON_WDT_CNT_TH0_OFFSET);
	writel_relaxed(0x1 << 16, wdt_base + AON_WDT_CNT_TH2_OFFSET);
	writel_relaxed(g_aon_wdt->hz / 1000, wdt_base + AON_WDT_PRE_TH_OFFSET); //rate = 1 KHz

	__aon_wdt_enable(amc_base + AON_WDT_EN_SRC_OFFSET);
	while ((readl_relaxed(wdt_base + AON_WDT_STAGE_OFFSET) & 0x3) != 1) {
		__aon_wdt_disable(amc_base + AON_WDT_EN_SRC_OFFSET);
		__aon_wdt_enable(amc_base + AON_WDT_EN_SRC_OFFSET);
	}

	//AON sleep to give more reset time for devices.
	writel_relaxed(0x1, amc_base + AON_WDT_SLEEP_OFFSET);

	spin_unlock_irqrestore(&g_wdt_lock, flags);
}
EXPORT_SYMBOL(aon_wdt_reboot);

void aon_wdt_stop_for_suspend(volatile void *wdt_base, volatile void *amc_base)
{
	pr_debug("[AON WDT] Suspending...\n");
	writel_relaxed(0x0, amc_base + AON_WDT_EN_SRC_OFFSET);
	while ((readl_relaxed(wdt_base + AON_WDT_STAGE_OFFSET) & 0x3) != 0) {
		pr_debug("[AON WDT] State mismatch, re-disable\n");
		writel_relaxed(0x101, amc_base + AON_WDT_EN_SRC_OFFSET);
		writel_relaxed(0x0, amc_base + AON_WDT_EN_SRC_OFFSET);
	}

	writel_relaxed(0x1, wdt_base + AON_WDT_DIS_WDT_OFFSET);
	pr_debug("[AON WDT] Switch to circuit control\n");
}
EXPORT_SYMBOL(aon_wdt_stop_for_suspend);

static ssize_t aon_wdt_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct aon_wdt_pdata *aon_wdt = dev_get_drvdata(dev);
	int len;

	len = sprintf(buf,
	              "Watchdog timeout=%d\nValid timeout range:1~%d\nOr set timeout=0 to disable watchdog timer\n",
	              aon_wdt->wdd.timeout, MAX_TIMEOUT);
	if (len <= 0)
		dev_err(dev, "mydrv: Invalid sprintf len: %d\n", len);

	return len;
}

static ssize_t aon_wdt_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct aon_wdt_pdata *aon_wdt = dev_get_drvdata(dev);
	struct watchdog_device *wdd = &aon_wdt->wdd;
	u32 new_timeout;
	int ret;

	ret = kstrtoul(buf, 10, (unsigned long *)&new_timeout);

	if (ret != 0) {
		printk("Invalid parameter %d, %d\n", ret, new_timeout);
		return count;
	}

	printk("new timeout = %d\n", new_timeout);

	if (new_timeout == 0) {
		aon_wdt_stop(wdd);
		printk("Watchdog timer disabled\n");
	} else if (!watchdog_timeout_invalid(wdd, new_timeout)) {
		aon_wdt_set_timeout(wdd, new_timeout);
		printk("Config watchdog timeout=%d\n", wdd->timeout);
	} else {
		printk("Invalid parameter\n");
	}

	return count;
}
static DEVICE_ATTR(timeout, S_IRUGO | S_IWUSR, aon_wdt_show, aon_wdt_store);

static int aon_wdt_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct device *dev = &pdev->dev;
	struct resource *wdt_mem, *amc_mem;
	struct watchdog_device *wdd;
	struct aon_wdt_pdata *aon_wdt;

	aon_wdt = devm_kzalloc(dev, sizeof(*aon_wdt), GFP_KERNEL);
	if (!aon_wdt)
		return -ENOMEM;
	g_aon_wdt = aon_wdt;

	/*
	 * devm_clk_get(dev, NULL) is same as of_clk_get(np, 0).
	 * If intending to use plural clock source, use of_clk_get(np, index).
	 * Remember not to use clock-names to reduce code size and boot time
	 */
	aon_wdt->clk = devm_clk_get(dev, NULL);
	if (WARN_ON(IS_ERR(aon_wdt->clk))) {
		dev_err(dev, "failed to find aon watchdog clock source\n");
		return PTR_ERR(aon_wdt->clk);
	}

	ret = clk_prepare_enable(aon_wdt->clk);
	if (ret < 0) {
		dev_err(dev, "failed to enable clock\n");
		return ret;
	}

	aon_wdt->hz = clk_get_rate(aon_wdt->clk);
	platform_set_drvdata(pdev, aon_wdt);

	wdd = &aon_wdt->wdd;
	wdd->info = &aon_wdt_info;
	wdd->ops = &aon_wdt_ops;
	wdd->max_timeout = MAX_TIMEOUT;
	wdd->timeout = DEFAULT_TIMEOUT;

	watchdog_init_timeout(wdd, timeout, dev);
	watchdog_set_drvdata(wdd, aon_wdt);
	watchdog_set_nowayout(wdd, nowayout);

	wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	aon_wdt->wdt_base = devm_ioremap_resource(dev, wdt_mem);
	if (IS_ERR(aon_wdt->wdt_base))
		return PTR_ERR(aon_wdt->wdt_base);

	amc_mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	aon_wdt->amc_base = devm_ioremap_resource(dev, amc_mem);
	if (IS_ERR(aon_wdt->amc_base))
		return PTR_ERR(aon_wdt->amc_base);

	aon_wdt->irq = irq_of_parse_and_map(pdev->dev.of_node, 0);

	ret = devm_request_irq(&pdev->dev, aon_wdt->irq, aon_wdt_irq_handler, IRQF_SHARED, pdev->name, aon_wdt);
	if (ret != 0) {
		dev_err(dev, "failed to install irq(%d)", ret);
		return -EINVAL;
	}

	ret = watchdog_register_device(wdd);
	if (ret < 0) {
		dev_err(dev, "cannot register aon watchdog(%d)\n", ret);
		return -EINVAL;
	}

	aon_wdt_setreg_forssys(wdd, pdev);

	pr_info("Augentix AON WDT driver probed.\n");

	device_create_file(dev, &dev_attr_timeout);

	return ret;
}

static int aon_wdt_remove(struct platform_device *pdev)
{
	struct aon_wdt_pdata *aon_wdt = platform_get_drvdata(pdev);

	watchdog_unregister_device(&aon_wdt->wdd);
	clk_disable_unprepare(aon_wdt->clk);

	return 0;
}

static const struct of_device_id aon_wdt_of_match[] = {
	{ .compatible = "augentix,aon-wdt" },
	{},
};

MODULE_DEVICE_TABLE(of, aon_wdt_of_match);

static struct platform_driver aon_wdt_driver = {
	.driver = {
		.name = "aon-wdt",
		.owner = THIS_MODULE,
		.of_match_table = aon_wdt_of_match,
	},
	.probe = aon_wdt_probe,
	.remove = aon_wdt_remove,
};

module_platform_driver(aon_wdt_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Augentix Inc.");
