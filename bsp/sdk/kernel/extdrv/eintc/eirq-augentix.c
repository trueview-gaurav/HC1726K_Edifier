// SPDX-License-Identifier: GPL-2.0-only
/*
* Copyright (c) 2015-2025 Augentix Inc. All rights reserved.
*/

#include <linux/module.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/platform_device.h>

#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/irqchip.h>
#include <linux/irqdomain.h>

#include <linux/slab.h>

#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_device.h>
#include <linux/bitops.h>

#include "irqchip.h"

#define DRV_NAME "hc18xx_intc"

#define EIRQ_STA 0x00
#define EIRQ_MASK 0x04
#define EIRQ_CLR 0x08
#define EIRQ_EN 0x0C
#define EIRQ_MOD 0x10 /* start of eirq[0] */

/* EXTIRQ module requires pinctrl to set correct pinmux */
#define NUM_EXTIRQ_MODULE 8

//#define EINTC_DEBUG

#ifdef EINTC_DEBUG
#define DBG(fmt, args...)                                                                                              \
	do {                                                                                                           \
		printk("[EIRQ] (%d, %s) " fmt, __LINE__, __func__, ##args);                                            \
	} while (0)
#else
#define DBG(fmt, args...)                                                                                              \
	do {                                                                                                           \
		;                                                                                                      \
	} while (0)
#endif /* EINTC_DEBUG */

static void __eirq_switch(void __iomem *base, uint32_t bits, int enabled)
{
	uint32_t en = readl_relaxed(base + EIRQ_EN);
	en = (enabled) ? (en | bits) : (en & ~bits);
	writel_relaxed(en, base + EIRQ_EN);
}

static void __eirq_enable(void __iomem *base, uint32_t bits)
{
	__eirq_switch(base, bits, 1);
}

static void __eirq_disable(void __iomem *base, uint32_t bits)
{
	__eirq_switch(base, bits, 0);
}

static void __eirq_irq_clr(void __iomem *base, uint32_t bits)
{
	writel_relaxed(bits, base + EIRQ_CLR);
}

static void __eirq_set_mask(void __iomem *base, uint32_t bits, int masked)
{
	uint32_t mask = readl_relaxed(base + EIRQ_MASK);

	mask = (masked) ? (mask | bits) : (mask & ~bits);
	writel_relaxed(mask, base + EIRQ_MASK);
}

static void __eirq_mask(void __iomem *base, uint32_t bits)
{
	__eirq_set_mask(base, bits, 1);
}

/*
static void __eirq_unmask(void __iomem *base, uint32_t bits)
{
	__eirq_set_mask(base, bits, 0);
}
*/

struct eirq_attr {
	int en;
	uint8_t src_sel;
	uint8_t pol_sel;
	uint8_t db_en;
	uint8_t db_cnt;
};

/**
 * Platform-specific external interrupt controller chip data
 *
 * @base: base virtual address of EIRQ CSR
 * @irq: IRQ number of external IRQ module
 * @dev: eintc device
 * @domain: hwirq number - linux irq number mapping
 * @eirq: EIRQ submodule attributes
 */
struct eintc_driver_data {
	void __iomem *base;
	int irq;
	struct device *dev;
	struct irq_domain *domain;
	struct eirq_attr eirq[NUM_EXTIRQ_MODULE];
};

void hc18xx_eintc_hw_init(struct eintc_driver_data *eintc)
{
	int i;
	uint32_t val, en = 0;
	__iomem void *base = eintc->base;
	__eirq_mask(base, 0xFF);
	__eirq_irq_clr(base, 0xFF);
	__eirq_disable(base, 0x00);

	/*
	 * init eirq[n] modules; src_sel is fixed.
	 */
	for (i = 0; i < NUM_EXTIRQ_MODULE; ++i) {
		if (eintc->eirq[i].en) {
			en |= (1UL << i);
			val = ((eintc->eirq[i].src_sel << 0) + (eintc->eirq[i].pol_sel << 8) +
			       (eintc->eirq[i].db_en << 16) + (eintc->eirq[i].db_cnt << 24));
			DBG("Init EIRQ[%d], reg = 0x%08x\n", i, val);
			writel_relaxed(val, base + EIRQ_MOD + (i << 2));
		}
	}
	__eirq_enable(base, en);
	__eirq_irq_clr(base, 0xFF);
	while ((val = readl_relaxed(base + EIRQ_STA)) != 0)
		DBG("EIRQ is raised: 0x%08x\n", val);
}

static irqreturn_t hc18xx_eintc_irq_handler(int irq, void *d)
{
	struct eintc_driver_data *eintc = (struct eintc_driver_data *)d;
	void __iomem *base = eintc->base;
	uint32_t irq_stat, irq_mask;
	unsigned long bit = 0, stat = 0;
	uint32_t virq;
	int handled = 0;

	while (1) {
		irq_stat = readl_relaxed(base + EIRQ_STA);
		irq_mask = readl_relaxed(base + EIRQ_MASK);
		stat = (unsigned long)irq_stat & ~irq_mask;
		if (stat == 0)
			break;
		DBG("IRQ 0x%08x: stat 0x%08x, mask 0x%08x\n", (uint32_t)stat & ~irq_mask, irq_stat, irq_mask);
		for_each_set_bit(bit, &stat, NUM_EXTIRQ_MODULE)
		{
			virq = irq_find_mapping(eintc->domain, bit);
			DBG("Bit %lu, IRQ = %d\n", bit, virq);
			generic_handle_irq(virq);
			__eirq_irq_clr(base, 1UL << bit);
		}
		handled = 1;
	}
	return handled ? IRQ_HANDLED : IRQ_NONE;
}

/**
 * Mask/unmask external interrupt
 *
 * @irq_data: Per irq chip data
 * @maksed: 0: unmask, 1: mask
 */
static void hc18xx_eintc_set_mask(struct irq_data *data, int masked)
{
	struct eintc_driver_data *eintc = irq_data_get_irq_chip_data(data);
	unsigned int idx = irqd_to_hwirq(data);
	DBG("EIRQ[%d] mask set to %d\n", idx, masked);
	__eirq_set_mask(eintc->base, (1UL << idx), masked);
}

static void hc18xx_eintc_mask(struct irq_data *d)
{
	hc18xx_eintc_set_mask(d, 1);
}
static void hc18xx_eintc_unmask(struct irq_data *d)
{
	hc18xx_eintc_set_mask(d, 0);
}

/**
 * eintc hardware chip descriptor
 */
static struct irq_chip hc18xx_eintc_chip = {
	.name = "hc18xx_eintc",
	.irq_mask = hc18xx_eintc_mask,
	.irq_unmask = hc18xx_eintc_unmask,
};

int hc18xx_eintc_irq_domain_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
	irq_set_chip_and_handler(irq, &hc18xx_eintc_chip, handle_level_irq);
	irq_set_chip_data(irq, d->host_data);
	irq_set_noprobe(irq);
	DBG("Map HWIRQ %u to IRQ %d\n", (uint32_t)hw, irq);
	return 0;
}

static const struct irq_domain_ops hc18xx_eintc_irq_domain_ops = {
	.map = hc18xx_eintc_irq_domain_map,
	.xlate = irq_domain_xlate_onecell,
};

static const struct of_device_id hc18xx_eintc_dt_ids[] = { {.compatible = "augentix,hc18xx-eintc" }, {} };
MODULE_DEVICE_TABLE(of, hc18xx_eintc_dt_ids);

/**
 * Init eintc attr by device node info
 * The following strings are identified:
 * - reg: HW index
 * - augentix,pol: Polarity
 */
static int hc18xx_eintc_init_dt(struct eintc_driver_data *eintc)
{
	const struct device_node const *np = eintc->dev->of_node;
	struct device_node *child = NULL;
	uint32_t idx;
	/*
	#define MAX_POL_STRLEN 5
	const char *buf;
	*/

	for_each_child_of_node(np, child)
	{
		if (of_property_read_u32(child, "reg", &idx)) {
			dev_err(eintc->dev, "Failed to identify HW index!");
			return -EFAULT;
		}

		if (idx > 7)
			dev_err(eintc->dev, "Invalid HW index!");

		eintc->eirq[idx].en = 1;
		eintc->eirq[idx].src_sel = idx;
		eintc->eirq[idx].pol_sel = 1;
		eintc->eirq[idx].db_en = 0;
		eintc->eirq[idx].db_cnt = 0;

		/*
		DBG("HW %d:\n", idx);
		if (!of_property_read_string(child, "augentix,pol", &buf)) {
			if (!strncmp(buf, "high", MAX_POL_STRLEN)) {
				eintc->eirq[idx].pol_sel = 0;
			} else if (!strncmp(buf, "low", MAX_POL_STRLEN)) {
				eintc->eirq[idx].pol_sel = 1;
			} else {
				dev_err(eintc->dev, "Invalid polarity for EIRQ[%d]!\n", idx);
			}
			DBG("\tPolarity: %s(%d)\n", buf, eintc->eirq[idx].pol_sel);
		}
		*/
	}
	return 0;
}

static int hc18xx_eintc_probe(struct platform_device *pdev)
{
	struct eintc_driver_data *eintc = NULL;
	struct resource *res;
	struct device *dev;
	int ret;

	eintc = devm_kzalloc(&pdev->dev, sizeof(*eintc), GFP_KERNEL);
	if (!eintc)
		return -ENOMEM;
	eintc->dev = &pdev->dev;
	dev = eintc->dev;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	eintc->base = devm_ioremap_resource(dev, res);
	if (IS_ERR(eintc->base)) {
		return PTR_ERR(eintc->base);
	}

	eintc->irq = irq_of_parse_and_map(dev->of_node, 0);
	ret = devm_request_irq(dev, eintc->irq, hc18xx_eintc_irq_handler, IRQF_SHARED, DRV_NAME, eintc);
	if (ret) {
		dev_err(dev, "Failed to request eintc IRQ: %d\n", ret);
		return -EINVAL;
	}
	DBG("Module IRQ number: %d\n", eintc->irq);

	DBG("Mapped PA=0x%08x, VA=%p, size %u\n", res->start, eintc->base, (uint32_t)resource_size(res));

	eintc->domain = irq_domain_add_linear(dev->of_node, NUM_EXTIRQ_MODULE, &hc18xx_eintc_irq_domain_ops, eintc);

	if (!eintc->domain) {
		return -EINVAL;
	}

	ret = hc18xx_eintc_init_dt(eintc);
	if (ret) {
		dev_err(dev, "Failed to probe eintc device node: %d\n", ret);
	}
	hc18xx_eintc_hw_init(eintc);

	platform_set_drvdata(pdev, eintc);

	DBG("Module probed.\n");
	return 0;
}

static struct platform_driver hc18xx_eintc_driver = {
	.probe = hc18xx_eintc_probe,
	.driver =
	        {
	                .name = DRV_NAME,
	                .owner = THIS_MODULE,
	                .of_match_table = hc18xx_eintc_dt_ids,
	        },
};
module_platform_driver(hc18xx_eintc_driver);

MODULE_DESCRIPTION("External interrupt controller module");
MODULE_AUTHOR("<shihchieh.lin@augentix.com>");
MODULE_LICENSE("GPL");
