#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/reset.h>
#include <linux/err.h>

#define DRV_NAME "reset_user"

static const struct of_device_id hc1703_1723_1753_1783s_reset_user_dt_ids[] = {
	{ .compatible = "augentix,reset-test" },
};

struct hc1703_1723_1753_1783s_test_driver {
	void __iomem *membase;
	struct reset_control *rst;
};

static int hc1703_1723_1753_1783s_test_driver_probe(struct platform_device *pdev)
{
	struct hc1703_1723_1753_1783s_test_driver *my_driver;

	my_driver = devm_kzalloc(&pdev->dev, sizeof(*my_driver), GFP_KERNEL);
	if (!my_driver)
		return -ENOMEM;

	//test case 1
	printk("Test reset SW_RST_APB2\n");
	my_driver->rst = devm_reset_control_get(&pdev->dev, "rst_apb2");
	if (IS_ERR(my_driver->rst))
		return PTR_ERR(my_driver->rst);
	reset_control_reset(my_driver->rst);

	//test case 2
	printk("Test reset SW_RST_USB\n");
	my_driver->rst = devm_reset_control_get(&pdev->dev, "rst_usb");
	if (IS_ERR(my_driver->rst))
		return PTR_ERR(my_driver->rst);
	reset_control_reset(my_driver->rst);

	//test case 3
	printk("Test assert SW_RST_USB_PHY\n");
	my_driver->rst = devm_reset_control_get(&pdev->dev, "rst_usb_phy");
	if (IS_ERR(my_driver->rst))
		return PTR_ERR(my_driver->rst);
	reset_control_assert(my_driver->rst);

	//test case 4
	printk("Test assert SW_RST_EMAC\n");
	my_driver->rst = devm_reset_control_get(&pdev->dev, "rst_emac");
	if (IS_ERR(my_driver->rst))
		return PTR_ERR(my_driver->rst);
	reset_control_assert(my_driver->rst);

	//test case 5
	printk("Test deassert SW_RST_QSPI\n");
	my_driver->rst = devm_reset_control_get(&pdev->dev, "rst_sdc");
	if (IS_ERR(my_driver->rst))
		return PTR_ERR(my_driver->rst);
	reset_control_deassert(my_driver->rst);

	//test case 6
	printk("Test deassert SW_RST_SENSOR\n");
	my_driver->rst = devm_reset_control_get(&pdev->dev, "rst_snsr");
	if (IS_ERR(my_driver->rst))
		return PTR_ERR(my_driver->rst);
	reset_control_deassert(my_driver->rst);

	return 0;
}

static int hc1703_1723_1753_1783s_test_driver_remove(struct platform_device *pdev)
{
	return 0;
}

static struct platform_driver reset_user_driver = {
	.probe	= hc1703_1723_1753_1783s_test_driver_probe,
	.remove	= hc1703_1723_1753_1783s_test_driver_remove,
	.driver = {
		.name		= "hc1703_1723_1753_1783s-reset-user",
		.owner		= THIS_MODULE,
		.of_match_table	= hc1703_1723_1753_1783s_reset_user_dt_ids,
	},
};
module_platform_driver(reset_user_driver);

MODULE_DESCRIPTION("Reset user testing module");
MODULE_AUTHOR("HuanYu Yeh<Dream.Yeh@augentix.com>");
MODULE_LICENSE("GPL");
