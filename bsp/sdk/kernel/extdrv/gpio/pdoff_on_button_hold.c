#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/pwm.h>

#include <asm/io.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/gpio/consumer.h>

#define DRV_NAME "pdoff_on_button_hold"
#define KTHREAD_NAME "PMC_TH"
#define GPIP_GROUP "trigger"
#define DTS_TRIG_TIME "trigger-time"
#define IO_SAMPLE_FRQ 10

#define IO_AIOC_VA (0xE0800000)
#define AON_WDT_VA (0xE0801000)
#define AMC_VA (0xE0802000)

#define POWER_MANAGEMENT_DEBUG (1)

#ifdef POWER_MANAGEMENT_DEBUG
#define DBG(fmt, args...)                                                  \
	do {                                                               \
		printk("[PBH] (%d, %s) " fmt, __LINE__, __func__, ##args); \
	} while (0)
#endif

struct pdoff_on_button_hold_data {
	int pin;
	int trigger_time;
	int press_count;
	struct device *dev;
	struct gpio_desc *gpio;
	struct task_struct *thread;
	spinlock_t lock;
	struct pinctrl *p;
	struct pinctrl_state *pwm_iomux;
};

extern void hc1703_1723_1753_1783s_amc_pd_off(void);

static void pd_off_command(void)
{
	char cmdPath[] = "/sbin/poweroff";
	char *cmdArgv[] = { cmdPath, NULL };
	char *cmdEnvp[] = { "HOME=/", NULL };

	call_usermodehelper(cmdPath, cmdArgv, cmdEnvp, UMH_WAIT_PROC);
}

static int pdoff_on_button_hold_thread(void *data)
{
	int val;
	struct pdoff_on_button_hold_data *pmc = (struct pdoff_on_button_hold_data *)data;

	while (1) {
		val = gpiod_get_value(pmc->gpio);
		if (val != 0) {
			pmc->press_count++;
			if (pmc->press_count > pmc->trigger_time * IO_SAMPLE_FRQ) {
				printk("System going to sleep\n");
				while (gpiod_get_value(pmc->gpio)) {
				} //wait untill button release
				printk("System sleep\n");
				mdelay(100);

				pmc->pwm_iomux = pinctrl_lookup_state(pmc->p, "sleep");
				pinctrl_select_state(pmc->p, pmc->pwm_iomux);

				pm_power_off = hc1703_1723_1753_1783s_amc_pd_off;
				pd_off_command();
				pmc->press_count = 0;
			}
		} else {
			pmc->press_count = 0;
		}
		msleep(1000 / IO_SAMPLE_FRQ);
	}

	return 0;
}

int pdoff_on_button_hold_enable_detect(struct pdoff_on_button_hold_data *pmc)
{
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&pmc->lock, flags);

	pmc->thread = kthread_create(pdoff_on_button_hold_thread, pmc, KTHREAD_NAME);
	if (pmc->thread == NULL) {
		DBG("Create kthread fail\n");
		ret = -ENOMEM;
		goto END;
	}
	pmc->press_count = 0;
	wake_up_process(pmc->thread);

END:
	spin_unlock_irqrestore(&pmc->lock, flags);
	return ret;
}

int pdoff_on_button_hold_disable_detect(struct pdoff_on_button_hold_data *pmc)
{
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&pmc->lock, flags);

	ret = kthread_stop(pmc->thread);
	if (ret < 0) {
		DBG("Fail to disable\n");
		ret = -EINVAL;
		goto END;
	}

END:
	spin_unlock_irqrestore(&pmc->lock, flags);
	return ret;
}

static int pdoff_on_button_hold_probe(struct platform_device *pdev)
{
	struct pdoff_on_button_hold_data *pmc;
	int ret;
	struct device_node *np = pdev->dev.of_node;

	pmc = devm_kzalloc(&pdev->dev, sizeof(struct pdoff_on_button_hold_data), GFP_KERNEL);
	if (!pmc) {
		ret = -ENOMEM;
		goto ERR;
	}
	pmc->dev = &pdev->dev;

	spin_lock_init(&pmc->lock);

	ret = of_property_read_u32(np, DTS_TRIG_TIME, &pmc->trigger_time);
	if (ret < 0) {
		DBG("dts no trigger-time propert\n");
		ret = -ENODEV;
		goto ERR;
	}

	pmc->gpio = devm_gpiod_get(pmc->dev, GPIP_GROUP, GPIOD_IN);

	if (IS_ERR(pmc->gpio)) {
		DBG("fail to get GPIO\n");
		ret = -ENODEV;
		goto ERR;
	}

	pmc->p = devm_pinctrl_get(&pdev->dev);
	if (!pmc->p) {
		dev_err(&pdev->dev, "Fail to get pinctrl settings\n");
		ret = -ENODEV;
		goto ERR;
	}

	/* checking pinctrl property*/
	pmc->pwm_iomux = pinctrl_lookup_state(pmc->p, "sleep");
	if (IS_ERR(pmc->pwm_iomux)) {
		dev_err(&pdev->dev, "Fail to find default pinctrl setting\n");
		ret = -ENODEV;
		goto ERR;
	}

	if (pinctrl_select_state(pmc->p, pmc->pwm_iomux)) {
		dev_err(&pdev->dev, "Fail to set pinctrl setting\n");
		ret = -ENODEV;
		goto ERR;
	}

	pmc->pwm_iomux = pinctrl_lookup_state(pmc->p, "default");
	if (IS_ERR(pmc->pwm_iomux)) {
		dev_err(&pdev->dev, "Fail to find default pinctrl setting\n");
		ret = -ENODEV;
		goto ERR;
	}

	if (pinctrl_select_state(pmc->p, pmc->pwm_iomux)) {
		dev_err(&pdev->dev, "Fail to set pinctrl setting\n");
		ret = -ENODEV;
		goto ERR;
	}

	pdoff_on_button_hold_enable_detect(pmc);

	platform_set_drvdata(pdev, pmc);

	return ret;
ERR:
	devm_kfree(&pdev->dev, pmc);
	return ret;
}

static int pdoff_on_button_hold_remove(struct platform_device *pdev)
{
	struct pdoff_on_button_hold_data *pmc = platform_get_drvdata(pdev);

	pdoff_on_button_hold_disable_detect(pmc);
	devm_kfree(&pdev->dev, pmc);
	platform_set_drvdata(pdev, NULL);

	return 0;
}

static const struct of_device_id pdoff_on_button_hold_dt_ids[] = {
	{ .compatible = "augentix,pdoff-on-button-hold" },
	{},
};
MODULE_DEVICE_TABLE(of, pdoff_on_button_hold_dt_ids);

static struct platform_driver pdoff_on_button_hold_driver = {
	.probe = pdoff_on_button_hold_probe,
	.remove = pdoff_on_button_hold_remove,
	.driver =
	        {
	                .owner = THIS_MODULE,
	                .name = DRV_NAME,
	                .of_match_table = pdoff_on_button_hold_dt_ids,
	        },
};
module_platform_driver(pdoff_on_button_hold_driver);

MODULE_AUTHOR("Jerry Wu, Augentix <jerry.wu@augentix.com>");
MODULE_DESCRIPTION("pdoff on button hold driver");
MODULE_LICENSE("GPL");
