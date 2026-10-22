/*
	adc_test: adc_test {
		compatible = "augentix,iio-test";
		io-channels = <&adc 0>, <&adc 1>, <&adc 2>;
		io-channel-names = "adc0", "adc1", "adc2";
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
#include <linux/iio/consumer.h>

#define DRV_NAME "augentix_iio_test"

static int iio_test_probe(struct platform_device *pdev)
{
	char *test_case[] = { "adc0", "adc1", "adc2" };
	struct iio_channel *chan;
	int ret;
	int i = 0;
	struct device *dev = &pdev->dev;
	uint32_t val;

	dev_err(dev, "Augentix iio consumer test start...\n");

	/* Setup iio */
	for (i = 0; i < sizeof(test_case) / sizeof(test_case[0]); i++) {
		chan = iio_channel_get(dev, test_case[i]);
		if (IS_ERR(chan)) {
			dev_err(dev, "Get iio device fail\n");
			return PTR_ERR(chan);
		}
		ret = iio_read_channel_raw(chan, &val);
		if (ret < 0) {
			dev_err(dev, "Read raw fail\n");
			return ret;
		}

		dev_err(dev, "ch %u raw value = %u\n", i, val);
	}
	iio_channel_release(chan);

	dev_err(dev, "Augentix iio consumer test ok\n");
	return 0;
}

static const struct of_device_id iio_test_dt_ids[] = {
	{ .compatible = "augentix,iio-test" },
	{},
};
MODULE_DEVICE_TABLE(of, iio_test_dt_ids);

static struct platform_driver iio_test_driver = {
	.probe = iio_test_probe,
	.driver =
	{
		.owner = THIS_MODULE,
		.name = DRV_NAME,
		.of_match_table = iio_test_dt_ids,
	},
};
module_platform_driver(iio_test_driver);

MODULE_AUTHOR("Eddie Lee, Augentix <eddie.lee@augentix.com>");
MODULE_DESCRIPTION("Augentix iio test driver");
MODULE_LICENSE("GPL");
