/*
	Usuage: add dts node as follows, should use existed pinctrl node, or it will hang

	pinctrl_test: pinctrl_test {
		compatible = "augentix,pinctrl-test";
		pinctrl-names = "4b_pwr_on", "4b_pwr_off", "1b_pwr_on", "1b_pwr_off";
		pinctrl-0 = <&pad_sdc0_4b_pwr_on>;
		pinctrl-1 = <&pad_sdc0_4b_pwr_off>;
		pinctrl-2 = <&pad_sdc0_1b_pwr_on>;
		pinctrl-3 = <&pad_sdc0_1b_pwr_off>;
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
#include <linux/pinctrl/consumer.h>

#define DRV_NAME "augentix_pinctrl_test"

static int pinctrl_test_probe(struct platform_device *pdev)
{
	char *test_case[] = { "4b_pwr_on", "4b_pwr_off", "1b_pwr_on", "1b_pwr_off" };
	struct pinctrl *p = NULL;
	struct pinctrl_state *got_state = NULL;
	int ret;
	int i = 0;
	struct device *dev = &pdev->dev;

	dev_err(dev, "Augentix pinctrl consumer test start...\n");

	/* Setup pinctrl */
	p = devm_pinctrl_get(dev);
	if (IS_ERR(p)) {
		dev_err(dev, "Get pinctrl device fail\n");
		return PTR_ERR(p);
	}
	for (i = 0; i < sizeof(test_case) / sizeof(test_case[0]); i++) {
		got_state = pinctrl_lookup_state(p, test_case[i]);
		if (IS_ERR(got_state)) {
			dev_err(dev, "pinctrl_lookup_state failed: %s\n", test_case[i]);
			goto test_case_failed;
		}
		ret = pinctrl_select_state(p, got_state);
		if (ret < 0) {
			dev_err(dev, "pinctrl_select_state failed: %s\n", test_case[i]);
			goto test_case_failed;
		}
	}
	devm_pinctrl_put(p);

	for (i = 0; i < sizeof(test_case) / sizeof(test_case[0]); i++) {
		p = devm_pinctrl_get_select(dev, test_case[0]);
		if (IS_ERR(p)) {
			dev_err(dev, "devm_pinctrl_get_select test failed\n");
			return PTR_ERR(p);
		}
		devm_pinctrl_put(p);
	}

	dev_err(dev, "Augentix pinctrl consumer test ok\n");
	return 0;

test_case_failed:
	return -1;
}

static const struct of_device_id pinctrl_test_dt_ids[] = {
	{ .compatible = "augentix,pinctrl-test" },
	{},
};
MODULE_DEVICE_TABLE(of, pinctrl_test_dt_ids);

static struct platform_driver pinctrl_test_driver = {
	.probe = pinctrl_test_probe,
	.driver =
	{
		.owner = THIS_MODULE,
		.name = DRV_NAME,
		.of_match_table = pinctrl_test_dt_ids,
	},
};
module_platform_driver(pinctrl_test_driver);

MODULE_AUTHOR("Louis Yang, Augentix <louis.yang@augentix.com>");
MODULE_DESCRIPTION("Augentix pinctrl test driver");
MODULE_LICENSE("GPL");
