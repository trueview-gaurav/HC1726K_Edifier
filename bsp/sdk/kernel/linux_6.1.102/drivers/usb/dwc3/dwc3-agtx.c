#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/dma-mapping.h>
#include <linux/clk.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/pm_runtime.h>
#include <linux/reset.h>
#include <linux/sysfs.h>
#include "core.h"

#define USB_CFG_USBC01 0x04
#define USBC_BVALID_SEL (BIT(0) | BIT(1))
#define USBC_BVALID BIT(4)
#define USBC_OTG_VBUS_VALIDSEL BIT(16)
#define USBC_OTG_VBUS_VALID BIT(20)
#define USB2_CFG_USBC21 0x50
#define USB3_CFG_USBC21 0x54
#define USBC_VBUS_VLDEXT_SEL BIT(8)
#define USBC_VBUS_VLDEXT BIT(16)

#define CONFIG_AGTX_USB_HOST BIT(0)
#define CONFIG_AGTX_USB_DEVICE BIT(1)

struct dwc3_agtx {
	struct device *dev;
	struct clk_bulk_data *clks;
	int num_clocks;
	struct reset_control *resets;
	struct platform_device *dwc3;
	enum usb_dr_mode mode;
	void __iomem *usb_cfg_base;
	unsigned char is_usb2_only;
	unsigned char vbus_detect_gpio_idx;
};

static const struct attribute_group agt_usb_attr_group;

static int dwc3_agtx_init(struct platform_device *pdev)
{
	struct dwc3_agtx *agtx = platform_get_drvdata(pdev);
	struct device *dev = &pdev->dev;
	struct resource *regs;
	void __iomem *base;
	u32 config;
	u32 value;
	int ret;

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	base = devm_ioremap_resource(&pdev->dev, regs);
	if (IS_ERR(base)) {
		dev_err(dev, "failed to get usb_cfg!\n");
		return PTR_ERR(base);
	}

	agtx->usb_cfg_base = base;

	agtx->vbus_detect_gpio_idx = 0;
	device_property_read_u8(dev, "vbus-detect-gpio", &agtx->vbus_detect_gpio_idx);

	agtx->is_usb2_only = device_property_read_bool(dev, "usb2-only");
	if (agtx->is_usb2_only) {
		dev_info(dev, "usb2 only !\n");
	}

	agtx->mode = usb_get_dr_mode(&agtx->dwc3->dev);
	dev_info(dev, "usb mode = %d\n", agtx->mode);

	config = 0;
	if (agtx->mode == USB_DR_MODE_PERIPHERAL) {
		config |= CONFIG_AGTX_USB_DEVICE;
	} else if (agtx->mode == USB_DR_MODE_HOST) {
		config |= CONFIG_AGTX_USB_HOST;
	} else if (agtx->mode == USB_DR_MODE_OTG) {
		config |= (CONFIG_AGTX_USB_HOST | CONFIG_AGTX_USB_DEVICE);
	}

	if (config & CONFIG_AGTX_USB_HOST) {
		/* Config for Host */
		value = readl_relaxed(agtx->usb_cfg_base + USB_CFG_USBC01);
		writel_relaxed(value | USBC_OTG_VBUS_VALID | USBC_OTG_VBUS_VALIDSEL,
		               agtx->usb_cfg_base + USB_CFG_USBC01);
	}

	if (config & CONFIG_AGTX_USB_DEVICE) {
		if (agtx->is_usb2_only /* USB2 */) {
			value = readl_relaxed(agtx->usb_cfg_base + USB2_CFG_USBC21);
			writel_relaxed(value | USBC_VBUS_VLDEXT | USBC_VBUS_VLDEXT_SEL,
			               agtx->usb_cfg_base + USB2_CFG_USBC21);
		} else {
			value = readl_relaxed(agtx->usb_cfg_base + USB3_CFG_USBC21);
			writel_relaxed(value | USBC_VBUS_VLDEXT | USBC_VBUS_VLDEXT_SEL,
			               agtx->usb_cfg_base + USB3_CFG_USBC21);
		}

		if (agtx->vbus_detect_gpio_idx) {
			value = (readl_relaxed(agtx->usb_cfg_base + USB_CFG_USBC01) & ~USBC_BVALID_SEL) |
			        0x2 /* from gpio */;
			writel_relaxed(value, agtx->usb_cfg_base + USB_CFG_USBC01);
		}
	}

	ret = sysfs_create_group(&agtx->dev->kobj, &agt_usb_attr_group);
	if (ret) {
		dev_err(agtx->dev, "failed to create sysfs group: %d\n", ret);
	}

	return 0;
}

static int dwc3_agtx_probe(struct platform_device *pdev)
{
	struct dwc3_agtx *agtx;
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node, *dwc3_np;
	int ret;

	agtx = devm_kzalloc(dev, sizeof(*agtx), GFP_KERNEL);
	if (!agtx)
		return -ENOMEM;

	platform_set_drvdata(pdev, agtx);
	agtx->dev = dev;

	agtx->resets = of_reset_control_array_get(np, false, true, true);
	if (IS_ERR(agtx->resets)) {
		dev_info(dev, "failed to get device resets, err=%d\n", ret);
	} else {
		ret = reset_control_deassert(agtx->resets);
		if (ret) {
			reset_control_put(agtx->resets);
			return ret;
		}
	}

	ret = clk_bulk_get_all(agtx->dev, &agtx->clks);
	if (ret < 0) {
		dev_info(dev, "failed to get device clocks, err=%d\n", ret);
	} else {
		agtx->num_clocks = ret;
		ret = clk_bulk_prepare_enable(agtx->num_clocks, agtx->clks);
		if (ret) {
			clk_bulk_put_all(agtx->num_clocks, agtx->clks);
			if (!IS_ERR(agtx->resets)) {
				reset_control_assert(agtx->resets);
				reset_control_put(agtx->resets);
			}
			return ret;
		}
	}

	dwc3_np = of_get_compatible_child(np, "snps,dwc3");
	if (!dwc3_np) {
		dev_err(dev, "failed to find dwc3 core child\n");
		goto err_probe;
	}

	ret = of_platform_populate(np, NULL, NULL, dev);
	if (ret) {
		of_node_put(dwc3_np);
		goto err_probe;
	}

	agtx->dwc3 = of_find_device_by_node(dwc3_np);
	if (!agtx->dwc3) {
		dev_err(dev, "failed to get dwc3 platform device\n");
		of_platform_depopulate(dev);
		of_node_put(dwc3_np);
		goto err_probe;
	}

	dwc3_agtx_init(pdev);
	if (ret) {
		goto err_probe;
	}

	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);
	pm_runtime_get_sync(dev);

	return 0;

err_probe:
	clk_bulk_disable_unprepare(agtx->num_clocks, agtx->clks);
	clk_bulk_put_all(agtx->num_clocks, agtx->clks);
	agtx->num_clocks = 0;

	if (!IS_ERR(agtx->resets)) {
		reset_control_assert(agtx->resets);
		reset_control_put(agtx->resets);
	}

	return ret;
}

static void __dwc3_agtx_teardown(struct dwc3_agtx *agtx)
{
	of_platform_depopulate(agtx->dev);

	clk_bulk_disable_unprepare(agtx->num_clocks, agtx->clks);
	clk_bulk_put_all(agtx->num_clocks, agtx->clks);
	agtx->num_clocks = 0;

	if (!IS_ERR(agtx->resets)) {
		reset_control_assert(agtx->resets);
		reset_control_put(agtx->resets);
	}

	sysfs_remove_group(&agtx->dev->kobj, &agt_usb_attr_group);

	pm_runtime_disable(agtx->dev);
	pm_runtime_put_noidle(agtx->dev);
	pm_runtime_set_suspended(agtx->dev);
}

static int dwc3_agtx_remove(struct platform_device *pdev)
{
	struct dwc3_agtx *agtx = platform_get_drvdata(pdev);

	__dwc3_agtx_teardown(agtx);

	return 0;
}

static void dwc3_agtx_shutdown(struct platform_device *pdev)
{
	struct dwc3_agtx *agtx = platform_get_drvdata(pdev);

	__dwc3_agtx_teardown(agtx);
}

static int __maybe_unused dwc3_agtx_runtime_suspend(struct device *dev)
{
	struct dwc3_agtx *agtx = dev_get_drvdata(dev);

	clk_bulk_disable(agtx->num_clocks, agtx->clks);

	return 0;
}

static int __maybe_unused dwc3_agtx_runtime_resume(struct device *dev)
{
	struct dwc3_agtx *agtx = dev_get_drvdata(dev);

	return clk_bulk_enable(agtx->num_clocks, agtx->clks);
}

static int __maybe_unused dwc3_agtx_suspend(struct device *dev)
{
	/* TODO */

	return 0;
}

static int __maybe_unused dwc3_agtx_resume(struct device *dev)
{
	/* TODO */

	return 0;
}

static ssize_t usb_device_force_vbus_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct dwc3_agtx *agtx = dev_get_drvdata(dev);
	return sysfs_emit(buf, "0x%x\n", (readl_relaxed(agtx->usb_cfg_base + USB_CFG_USBC01) & USBC_BVALID) ? 1 : 0);
}

static ssize_t usb_device_force_vbus_store(struct device *dev, struct device_attribute *attr, const char *buf,
                                           size_t count)
{
	struct dwc3_agtx *agtx = dev_get_drvdata(dev);
	u32 value;
	bool val;
	int ret;

	ret = kstrtobool(buf, &val);
	if (ret) {
		return ret;
	}

	value = (readl_relaxed(agtx->usb_cfg_base + USB_CFG_USBC01) & ~USBC_BVALID_SEL) | 0x1 /* from csr */;

	if (val) {
		value |= USBC_BVALID;
	} else {
		value &= ~USBC_BVALID;
	}

	writel_relaxed(value, agtx->usb_cfg_base + USB_CFG_USBC01);

	return count;
}

static DEVICE_ATTR_RW(usb_device_force_vbus);

static struct attribute *usb_agtx_attrs[] = {
	&dev_attr_usb_device_force_vbus.attr,
	NULL,
};

static const struct attribute_group agt_usb_attr_group = {
	.name = NULL,
	.attrs = usb_agtx_attrs,
};

static const struct dev_pm_ops dwc3_agtx_dev_pm_ops = { SET_SYSTEM_SLEEP_PM_OPS(dwc3_agtx_suspend, dwc3_agtx_resume)
	                                                        SET_RUNTIME_PM_OPS(dwc3_agtx_runtime_suspend,
	                                                                           dwc3_agtx_runtime_resume, NULL) };

static const struct of_device_id of_dwc3_agtx_match[] = { { .compatible = "agtx,usb-dwc3" }, { /* Sentinel */ } };
MODULE_DEVICE_TABLE(of, of_dwc3_agtx_match);

static struct platform_driver dwc3_agtx_driver = {
	.probe		= dwc3_agtx_probe,
	.remove		= dwc3_agtx_remove,
	.shutdown	= dwc3_agtx_shutdown,
	.driver		= {
		.name	= "dwc3-agtx",
		.of_match_table = of_dwc3_agtx_match,
		.pm	= &dwc3_agtx_dev_pm_ops,
	},
};

module_platform_driver(dwc3_agtx_driver);
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("DesignWare DWC3 Augentix Glue Driver");
