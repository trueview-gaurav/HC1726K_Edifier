/* Usage in dts:
 *	pwm: pwm@80060000 {
		status = "okay";
		pwm-names = "pwm1";
		#pwm-cells = <2>;
	};
	pwm_test: pwm_test {
		compatible = "augentix,pwm-test";
		pwms = <&pwm 0 0>;
		status = "okay";
	};
*/

#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>

#include <asm/io.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/pwm.h>
#include <linux/version.h>

#define DRV_NAME "augentix_pwm_test"

#define PWM_TEST_DEBUG

#ifdef PWM_TEST_DEBUG
#define DBG(fmt, args...)            \
	do {                         \
		pr_err(fmt, ##args); \
	} while (0)
#else
#define DBG(fmt, args...) \
	do {              \
	} while (0)
#endif

#define TEST_FAIL "\033[1;31mFAIL\033[0m"
#define TEST_OK "\033[1;32mOK\033[0m"

static int pwm_test_probe(struct platform_device *pdev)
{
	struct pwm_device *pwm_dev;
	int duty_ns = 1000000000;
	int period_ns = 2000000000;
	int fail_duty_ns = 2;
	int fail_period_ns = 4;
	int ret1 = 0;
	int ret2 = 0;

	pr_err("-----PWM consumer test start-----\n");
	pwm_dev = pwm_request(0, NULL);
	if (IS_ERR(pwm_dev)) {
		pr_err("Failed to request PWM device\n");
		return PTR_ERR(pwm_dev);
	}
	/* ret1 & ret2 should be handled separately because behavior varies on different kernel version */
	ret1 = pwm_config(pwm_dev, fail_duty_ns, fail_period_ns);
	ret2 = pwm_enable(pwm_dev);
	if (!ret1 && !ret2) {
		pr_err("Enable PWM with wrong parameter succeed\n");
		pr_err("[1] fail case for pwm_request, pwm_config, pwm_enable...%s\n", TEST_FAIL);
		return -EINVAL;
	}
	pr_err("[1] fail case for pwm_request, pwm_config, pwm_enable...%s\n", TEST_OK);

	ret1 = pwm_config(pwm_dev, duty_ns, period_ns);
	ret2 = pwm_enable(pwm_dev);
	if (ret1 && ret2) {
		pr_err("Enable PWM failed, duty_ns = %d, period_ns = %d\n", duty_ns, period_ns);
		pr_err("[2] success case for pwm_request, pwm_config, pwm_enable...%s\n", TEST_FAIL);
		return -EINVAL;
	}
	pr_err("[2] success case for pwm_request, pwm_config, pwm_enable...%s\n", TEST_OK);
	pwm_disable(pwm_dev);
	pwm_free(pwm_dev);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 7, 0)
	struct pwm_state state = { 0 };
	pr_err("test for linux version >= 4.7\n");

	pwm_dev = pwm_get(&pdev->dev, NULL);
	if (IS_ERR(pwm_dev)) {
		pr_err("pwm_get failed\n");
		return -EINVAL;
	}

	state.period = fail_period_ns;
	state.duty_cycle = fail_duty_ns;
	state.enabled = 1;
	ret1 = pwm_apply_state(pwm_dev, &state);
	if (!ret1) {
		pr_err("Apply PWM state with wrong parameter succeed\n");
		pr_err("[3] fail case for pwm_get, pwm_apply_state with enable...%s\n", TEST_FAIL);
		return -EINVAL;
	}
	pr_err("[3] fail case for pwm_get, pwm_apply_state with enable...%s\n", TEST_OK);

	state.period = period_ns;
	state.duty_cycle = duty_ns;
	ret1 = pwm_apply_state(pwm_dev, &state);
	if (ret1) {
		pr_err("Apply PWM state failed, duty_ns = %llu, period_ns = %llu\n", state.duty_cycle, state.period);
		pr_err("[4] success case for pwm_get, pwm_apply_state with enable...%s\n", TEST_FAIL);
		return -EINVAL;
	}
	pr_err("[4] success case for pwm_get, pwm_apply_state with enable...%s\n", TEST_OK);
	state.enabled = 0;
	ret1 = pwm_apply_state(pwm_dev, &state);
	if (ret1) {
		pr_err("Apply PWM state failed, duty_ns = %llu, period_ns = %llu\n", state.duty_cycle, state.period);
		pr_err("[5] success case for pwm_get, pwm_apply_state with disable...%s\n", TEST_FAIL);
		return -EINVAL;
	}
	pr_err("[5] success case for pwm_get, pwm_apply_state with disable...%s\n", TEST_OK);
	pwm_put(pwm_dev);
#endif
	pr_err("-----PWM consumer test done-----\n");

	return 0;
}

static int pwm_test_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id pwm_test_dt_ids[] = {
	{ .compatible = "augentix,pwm-test" },
	{},
};
MODULE_DEVICE_TABLE(of, pwm_test_dt_ids);

static struct platform_driver pwm_test_driver = {
	.probe = pwm_test_probe,
	.remove = pwm_test_remove,
	.driver = {
		.owner = THIS_MODULE,
		.name = DRV_NAME,
		.of_match_table = pwm_test_dt_ids,
	},
};
module_platform_driver(pwm_test_driver);

MODULE_AUTHOR("Eddie Lee, Augentix <eddie.lee@augentix.com>");
MODULE_DESCRIPTION("Augentix pwm test driver");
MODULE_LICENSE("GPL");
