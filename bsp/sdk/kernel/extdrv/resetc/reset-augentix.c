// SPDX-License-Identifier: GPL-2.0-only
/*
* Copyright (c) 2015-2025 Augentix Inc. All rights reserved.
*/

#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/reset-controller.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/types.h>

#define OFFSET_LV_RST 0x104

struct augentix_reset_data {
	spinlock_t lock;
	void __iomem *membase;
	struct reset_controller_dev rcdev;
	unsigned int physical_address;
};
enum { SW_RST_AXI_CPU,
       SW_RST_AXI_SYS,
       SW_RST_AXI_DRAMC,
       SW_RST_APB_0,
       SW_RST_APB_1,
       SW_RST_APB_2,
       SW_RST_APB_3,
       SW_RST_APB_USB,
       SW_RST_USB_UTMI,
       SW_RST_USB_PHY,
       SW_RST_DRAMC_HDR,
       SW_RST_DDRPHY,
       SW_RST_DDRPHY_DLL,
       SW_RST_DDRPHY_HDR,
       SW_RST_APB_EMAC,
       SW_RST_SDC_0,
       SW_RST_SDC_1,
       SW_RST_QSPI,
       SW_RST_APB_SDC_0,
       SW_RST_APB_SDC_1,
       SW_RST_SENSOR,
       SW_RST_SENIF,
       SW_RST_ENC,
       SW_RST_IS,
       SW_RST_DMA,
       SW_RST_ISP,
       SW_RST_VP,
       SW_RST_DISP,
       SW_RST_APB_DRAMC,
       SW_RST_APB_DDRPHY,
       SW_RST_AUDIO_IN,
       SW_RST_AUDIO_OUT,
       SW_RST_I2C_0,
       SW_RST_I2C_1,
       SW_RST_SPI_0,
       SW_RST_SPI_1,
       SW_RST_UART_0,
       SW_RST_UART_1,
       SW_RST_UART_2,
       SW_RST_UART_3,
       SW_RST_UART_4,
       SW_RST_UART_5,
       SW_RST_TIMER_0,
       SW_RST_TIMER_1,
       SW_RST_TIMER_2,
       SW_RST_TIMER_3,
       SW_RST_PWM_0,
       SW_RST_PWM_1,
       SW_RST_PWM_2,
       SW_RST_PWM_3,
       SW_RST_PWM_4,
       SW_RST_PWM_5,
       SW_RST_EIRQ,
       SW_RST_MAX,
};

//mem = membase 0x80000400 + (8bit)*offset[index]  0-52
int reset_offset[] = {
	//RST_AXI
	0, //SW_RST_AXI_CPU
	1, //SW_RST_AXI_SYS
	2, //SW_RST_AXI_DRAMC
	//RST_APB
	4, //SW_RST_APB_0
	5, //SW_RST_APB_1
	6, //SW_RST_APB_2
	7, //SW_RST_APB_3
	//RST_USB
	8, //SW_RST_APB_USB
	9, //SW_RST_USB_UTMI
	10, //SW_RST_USB_PHY
	//RST_DDR
	12, //SW_RST_DRAMC_HDR
	13, //SW_RST_DDRPHY
	14, //SW_RST_DDRPHY_DLL
	15, //SW_RST_DDRPHY_HDR
	//RST_EMAC
	16, //SW_RST_APB_EMAC
	//RST_SDC
	20, //SW_RST_SDC_0
	21, //SW_RST_SDC_1
	22, //SW_RST_QSPI
	//RST_SDC_1
	24, //SW_RST_APB_SDC_0
	25, //SW_RST_APB_SDC_1
	//RST_SNSR
	28, //SW_RST_SENSOR
	29, //SW_RST_SENIF
	//RST_ENC
	32, //SW_RST_ENC
	//RST_IS
	36, //SW_RST_IS
	//RST_DMA
	40, //SW_RST_DMA
	//RST_ISPVP
	44, //SW_RST_ISP
	45, //SW_RST_VP
	//RST_DISP
	48, //SW_RST_DISP
	//RST_DDR_1
	52, //SW_RST_APB_DRAMC
	53, //SW_RST_APB_DDRPHY
	//RST_AUDIO
	56, //SW_RST_AUDIO_IN
	57, //SW_RST_AUDIO_OUT
	//RST_PLAT0
	60, //SW_RST_I2C_0
	61, //SW_RST_I2C_1
	62, //SW_RST_SPI_0
	63, //SW_RST_SPI_1
	//RST_PLAT1
	64, //SW_RST_UART_0
	65, //SW_RST_UART_1
	66, //SW_RST_UART_2
	67, //SW_RST_UART_3
	//RST_PLAT2
	68, //SW_RST_UART_4
	69, //SW_RST_UART_5
	70, //SW_RST_TIMER_0
	71, //SW_RST_TIMER_1
	//RST_PLAT3
	72, //SW_RST_TIMER_2
	73, //SW_RST_TIMER_3
	74, //SW_RST_PWM_0
	75, //SW_RST_PWM_1
	//RST_PLAT4
	76, //SW_RST_PWM_2
	77, //SW_RST_PWM_3
	78, //SW_RST_PWM_4
	79, //SW_RST_PWM_5
	//RST_EIRQ
	100, //SW_RST_EIRQ -> 0x80000500/0x80000554
};

static int augentix_reset_reset(struct reset_controller_dev *rcdev, unsigned long id)
{
	struct augentix_reset_data *data = container_of(rcdev, struct augentix_reset_data, rcdev);
	int offset = reset_offset[id];

	/* Dream: now we want write 0x8000408 409 40a 40b
	   1.4byte align offset -> offset & 0xfc or 0b11111100
	   2.(1<<((offset&0x03)<<3)) 8->0->0->1    9->1->8-> 0x0100   a->2->10->0x10000
	   */
	
	if (id == SW_RST_EIRQ) {
		writel(1, data->membase + 0x100);
	} else {
		writel((1 << ((offset & 0x03) << 3)), data->membase + (offset & 0xfc));
	}
	return 0;
}

static int augentix_reset_assert(struct reset_controller_dev *rcdev, unsigned long id)
{
	struct augentix_reset_data *data = container_of(rcdev, struct augentix_reset_data, rcdev);
	int offset = reset_offset[id];
	unsigned long flags;

	/* Dream: now we want write 0x8000408 409 40a 40b
	   1.4byte align offset -> offset & 0xfc or 0b11111100
	   2.(1<<((offset&0x03)<<3)) 8->0->0->1    9->1->8-> 0x0100   a->2->10->0x10000
	   */
#if 0
	printk("Assert: Word address:0x%08x  Bit=%d\n", data->physical_address + (offset & 0xfc) + OFFSET_LV_RST,
	       ((offset & 0x03) << 3));
#endif
	if (id == SW_RST_EIRQ) { //LVRST_EIRQ = 0x80000554
		writel(1, data->membase + 0x154);
	} else {
		uint32_t reg_val;

		spin_lock_irqsave(&data->lock, flags);
		reg_val = readl(data->membase + (offset & 0xfc) + OFFSET_LV_RST);
		reg_val |= (1 << ((offset & 0x03) << 3));
		writel(reg_val, data->membase + (offset & 0xfc) + OFFSET_LV_RST);
		spin_unlock_irqrestore(&data->lock, flags);
	}
	return 0;
}

static int augentix_reset_deassert(struct reset_controller_dev *rcdev, unsigned long id)
{
	struct augentix_reset_data *data = container_of(rcdev, struct augentix_reset_data, rcdev);
	int offset = reset_offset[id];
	unsigned long flags;

	/* Dream: now we want write 0x8000408 409 40a 40b
	   1.4byte align offset -> offset & 0xfc or 0b11111100
	   2.(1<<((offset&0x03)<<3)) 8->0->0->1    9->1->8-> 0x0100   a->2->10->0x10000
	   */
#if 0
	printk("Deassert: Word address:0x%x  Bit=%d\n", data->physical_address + (offset & 0xfc) + OFFSET_LV_RST,
	       ((offset & 0x03) << 3));
#endif
	if (id == SW_RST_EIRQ) { //LVRST_EIRQ = 0x80000554
		writel(1, data->membase + 0x154);
	} else {
		uint32_t reg_val;

		spin_lock_irqsave(&data->lock, flags);
		reg_val = readl(data->membase + (offset & 0xfc) + OFFSET_LV_RST);
		reg_val &= ~(1 << ((offset & 0x03) << 3));
		writel(reg_val, data->membase + (offset & 0xfc) + OFFSET_LV_RST);
		spin_unlock_irqrestore(&data->lock, flags);
	}
	return 0;
}

static struct reset_control_ops augentix_reset_ops = {
	.reset = augentix_reset_reset,
	.assert = augentix_reset_assert,
	.deassert = augentix_reset_deassert,
};

/*
 * And these are the controllers we can register through the regular
 * device model.
 */
static const struct of_device_id augentix_reset_dt_ids[] = {
	{
	        .compatible = "augentix,reset",
	},
};
MODULE_DEVICE_TABLE(of, augentix_reset_dt_ids);

static int augentix_reset_probe(struct platform_device *pdev)
{
	struct augentix_reset_data *data;
	struct resource *res;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	data->membase = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(data->membase))
		return PTR_ERR(data->membase);
	data->physical_address = res->start;

	spin_lock_init(&data->lock);

	data->rcdev.owner = THIS_MODULE;
	data->rcdev.nr_resets = SW_RST_MAX;
	data->rcdev.ops = &augentix_reset_ops;
	data->rcdev.of_node = pdev->dev.of_node;

	return reset_controller_register(&data->rcdev);
}

static int augentix_reset_remove(struct platform_device *pdev)
{
	struct augentix_reset_data *data = platform_get_drvdata(pdev);

	reset_controller_unregister(&data->rcdev);

	return 0;
}

static struct platform_driver augentix_reset_driver = {
	.probe	= augentix_reset_probe,
	.remove	= augentix_reset_remove,
	.driver = {
		.name		= "augentix-reset",
		.owner		= THIS_MODULE,
		.of_match_table	= augentix_reset_dt_ids,
	},
};
module_platform_driver(augentix_reset_driver);

MODULE_AUTHOR("HuanYu Yeh <dream.yehd@augentix.com");
MODULE_DESCRIPTION("Augentix SoCs Reset Controller Driver");
MODULE_LICENSE("GPL");
