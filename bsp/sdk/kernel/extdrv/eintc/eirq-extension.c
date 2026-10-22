#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/io.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/types.h>
#include <linux/irq.h>

/* 
 * ===== Debug (needs to undefine when releasing) =====
 * EIRQ_EXT_DEBUG enables extra logs and pinmux to EIRQ for development
 * efficiency. Not intended for users due to verbose output and pinmux
 * functionality.
 */
// #define EIRQ_EXT_DEBUG

#ifdef EIRQ_EXT_DEBUG
#define DBG(fmt, ...)                                                                  \
	do {                                                                           \
		printk("[EIRQ_EXT] (%d, %s) " fmt, __LINE__, __func__, ##__VA_ARGS__); \
	} while (0)
#else
#define DBG(fmt, ...) \
	do {          \
	} while (0)
#endif /* EIRQ_EXT_DEBUG */

/* ===== Register address ===== */
#define RST_BASE 0x80000400
#define LV_SYS 0x64

#define EIRQ_BASE 0x80002000
#define EIRQ_IRQ_CLR 0x0
#define EIRQ_STATUS 0x4
#define EIRQ_IRQ_MASK 0x8
#define EIRQ_EDGE_EN 0xC
#define EIRQ_DBNC_EN 0x10
#define EIRQ_SENS_NUM0 0x14
#define EIRQ_HOLD_NUM0 0x18
#define EIRQ_SENS_NUM1 0x1C
#define EIRQ_HOLD_NUM1 0x20
#define EIRQ_SENS_NUM2 0x24
#define EIRQ_HOLD_NUM2 0x28
#define EIRQ_SENS_NUM3 0x2C
#define EIRQ_HOLD_NUM3 0x30
#define EIRQ_SENS_NUM4 0x34
#define EIRQ_HOLD_NUM4 0x38
#define EIRQ_LVL_TRIG_INV_EN 0x3C

#ifdef EIRQ_EXT_DEBUG
#define EIRQ0_IOMUX_BASE 0x800010DC
#define EIRQ1_IOMUX_BASE 0x80001110
#define EIRQ2_IOMUX_BASE 0x80001188
#define EIRQ3_IOMUX_BASE 0x80001104
#define EIRQ4_IOMUX_BASE 0x800010C8

#define EIRQ0_IOMUX_VAL 0x2
#define EIRQ1_IOMUX_VAL 0x1
#define EIRQ2_IOMUX_VAL 0x4
#define EIRQ3_IOMUX_VAL 0x2
#define EIRQ4_IOMUX_VAL 0x2
#endif /* EIRQ_EXT_DEBUG */

#define DEFAULT_SENS_NUM 300000
#define DEFAULT_HOLD_NUM 300000
#define MAX_SENS_NUM 0xFFFFF
#define MAX_HOLD_NUM 0xFFFFF

#define DRV_NAME "eirq_ext"
#define MAX_EIRQ_PINS 5

static struct eirq_dev *g_edev;

struct eirq_pin {
#ifdef EIRQ_EXT_DEBUG
	void __iomem *iomux_base;
	u32 iomux_val;
#endif // EIRQ_EXT_DEBUG
	bool used;
	u32 id;
	u32 trigger_mode;
	u32 debounce;
	u32 sens_num;
	u32 hold_num;
};

struct eirq_dev {
	struct device *dev;
	void __iomem *eirq_base;
	void __iomem *rst_base;
	u32 num_pins;
	struct eirq_pin pins[MAX_EIRQ_PINS];
};

struct eirq_pin_status {
	bool pos;
	bool neg;
};

struct trigger_map {
	u32 mode;
	u8 pos;
	u8 neg;
	bool lvl_inv; /* true represents LVL_TRIG_INV_EN */
};

static const struct trigger_map trigger_table[] = {
	{ IRQ_TYPE_EDGE_RISING, 1, 0, false }, { IRQ_TYPE_EDGE_FALLING, 0, 1, false },
	{ IRQ_TYPE_EDGE_BOTH, 1, 1, false },   { IRQ_TYPE_LEVEL_HIGH, 0, 0, false },
	{ IRQ_TYPE_LEVEL_LOW, 0, 0, true },
};

#ifdef EIRQ_EXT_DEBUG
struct eirq_iomux_map {
	phys_addr_t phy_addr;
	u32 val;
};

static const struct eirq_iomux_map eirq_iomux_table[MAX_EIRQ_PINS] = {
	{ EIRQ0_IOMUX_BASE, EIRQ0_IOMUX_VAL }, { EIRQ1_IOMUX_BASE, EIRQ1_IOMUX_VAL },
	{ EIRQ2_IOMUX_BASE, EIRQ2_IOMUX_VAL }, { EIRQ3_IOMUX_BASE, EIRQ3_IOMUX_VAL },
	{ EIRQ4_IOMUX_BASE, EIRQ4_IOMUX_VAL },
};
#endif // EIRQ_EXT_DEBUG

static bool eirq_is_trig_valid(u32 trigger)
{
	switch (trigger) {
	case IRQ_TYPE_EDGE_RISING:
	case IRQ_TYPE_EDGE_FALLING:
	case IRQ_TYPE_EDGE_BOTH:
	case IRQ_TYPE_LEVEL_HIGH:
	case IRQ_TYPE_LEVEL_LOW:
		return true;
	default:
		return false;
	}
}

static inline u32 eirq_get_sens_num_ofs(u32 id)
{
	switch (id) {
	case 0:
		return EIRQ_SENS_NUM0;
	case 1:
		return EIRQ_SENS_NUM1;
	case 2:
		return EIRQ_SENS_NUM2;
	case 3:
		return EIRQ_SENS_NUM3;
	case 4:
	default:
		return EIRQ_SENS_NUM4;
	}
}

static inline u32 eirq_get_hold_num_ofs(u32 id)
{
	switch (id) {
	case 0:
		return EIRQ_HOLD_NUM0;
	case 1:
		return EIRQ_HOLD_NUM1;
	case 2:
		return EIRQ_HOLD_NUM2;
	case 3:
		return EIRQ_HOLD_NUM3;
	case 4:
	default:
		return EIRQ_HOLD_NUM4;
	}
}

static inline void eirq_reg_write(void __iomem *base, u32 ofs, u32 val)
{
	writel(val, base + ofs);
}

static inline u32 eirq_reg_read(void __iomem *base, u32 ofs)
{
	return readl(base + ofs);
}

/*
 * Expectation usage
static irqreturn_t my_handler(int irq, void *data)
{
	struct eirq_pin_status s;

	s = eirq_get_pin_status(3);  // eirq3

	if (s.pos || s.neg) {
		if (s.pos) {
			eirq_clear_irq_pos(3);
		}

		if (s.neg) {
			eirq_clear_irq_neg(3);
		}
		pr_info("Pin 3 triggered! POS=%d NEG=%d\n", s.pos, s.neg);
	}

	return IRQ_HANDLED;
}
 */
u32 eirq_get_status(void)
{
	if (!g_edev) {
		return 0;
	}

	return eirq_reg_read(g_edev->eirq_base, EIRQ_STATUS);
}
EXPORT_SYMBOL(eirq_get_status);

void eirq_clear_irq_pos(u32 pin_id)
{
	if (!g_edev) {
		return;
	}

	eirq_reg_write(g_edev->eirq_base, EIRQ_IRQ_CLR, BIT(pin_id));
}
EXPORT_SYMBOL(eirq_clear_irq_pos);

void eirq_clear_irq_neg(u32 pin_id)
{
	if (!g_edev) {
		return;
	}

	eirq_reg_write(g_edev->eirq_base, EIRQ_IRQ_CLR, BIT(pin_id + MAX_EIRQ_PINS));
}
EXPORT_SYMBOL(eirq_clear_irq_neg);

struct eirq_pin_status eirq_get_pin_status(u32 pin_id)
{
	struct eirq_pin_status s = { 0 };
	u32 status;

	if (!g_edev)
		return s;

	status = eirq_get_status();
	s.pos = status & BIT(pin_id);
	s.neg = status & BIT(pin_id + MAX_EIRQ_PINS);

	return s;
}
EXPORT_SYMBOL(eirq_get_pin_status);

static void eirq_mask_irq(struct eirq_dev *edev, u32 pin_id, bool mask)
{
	u32 tmp = eirq_reg_read(edev->eirq_base, EIRQ_IRQ_MASK);

	if (mask) {
		tmp |= BIT(pin_id) | BIT(pin_id + MAX_EIRQ_PINS);
	} else {
		tmp &= ~(BIT(pin_id) | BIT(pin_id + MAX_EIRQ_PINS));
	}
	eirq_reg_write(edev->eirq_base, EIRQ_IRQ_MASK, tmp);
}

static void eirq_set_trigger(struct eirq_dev *edev, struct eirq_pin *pin)
{
	u32 pos = 0, neg = 0, i, val;
	u32 edge;
	bool lvl_inv = false;

	eirq_mask_irq(edev, pin->id, true);

	for (i = 0; i < ARRAY_SIZE(trigger_table); i++) {
		if (trigger_table[i].mode == pin->trigger_mode) {
			pos = trigger_table[i].pos;
			neg = trigger_table[i].neg;
			lvl_inv = trigger_table[i].lvl_inv;
			break;
		}
	}

	if (lvl_inv) {
		val = eirq_reg_read(edev->eirq_base, EIRQ_LVL_TRIG_INV_EN);
		val |= BIT(pin->id);
		eirq_reg_write(edev->eirq_base, EIRQ_LVL_TRIG_INV_EN, val);
	}

	edge = eirq_reg_read(edev->eirq_base, EIRQ_EDGE_EN);
	if (pos) {
		edge |= BIT(pin->id);
	} else {
		edge &= ~BIT(pin->id);
	}

	if (neg) {
		edge |= BIT(pin->id + MAX_EIRQ_PINS);
	} else {
		edge &= ~BIT(pin->id + MAX_EIRQ_PINS);
	}
	eirq_reg_write(edev->eirq_base, EIRQ_EDGE_EN, edge);

	eirq_mask_irq(edev, pin->id, false);
}

static void eirq_set_debounce(struct eirq_dev *edev, struct eirq_pin *pin)
{
	u32 dbnc;

	if (!pin->debounce) {
		return;
	}

	eirq_mask_irq(edev, pin->id, true);

	dbnc = eirq_reg_read(edev->eirq_base, EIRQ_DBNC_EN);
	dbnc |= BIT(pin->id);
	eirq_reg_write(edev->eirq_base, EIRQ_DBNC_EN, dbnc);

	eirq_reg_write(edev->eirq_base, eirq_get_sens_num_ofs(pin->id), pin->sens_num);
	eirq_reg_write(edev->eirq_base, eirq_get_hold_num_ofs(pin->id), pin->hold_num);

	eirq_mask_irq(edev, pin->id, false);
}

#ifdef EIRQ_EXT_DEBUG
static void eirq_init_pin_iomux(struct eirq_pin *pin)
{
	if (pin->id >= MAX_EIRQ_PINS) {
		DBG("Invalid EIRQ pin id %u\n", pin->id);
		return;
	}

	pin->iomux_base = ioremap(eirq_iomux_table[pin->id].phy_addr, 0x4);
	if (!pin->iomux_base) {
		DBG("ioremap EIRQ%d IOMUX failed\n", pin->id);
		return;
	}
	pin->iomux_val = eirq_iomux_table[pin->id].val;

	writel(pin->iomux_val, pin->iomux_base);
}
#endif // EIRQ_EXT_DEBUG

static void eirq_hw_reset(struct eirq_dev *edev)
{
	u32 i, tmp;

	if (!edev->eirq_base) {
		dev_err(edev->dev, "eirq_base not mapped\n");
		return;
	}
	if (!edev->rst_base) {
		dev_err(edev->dev, "rst_base not mapped\n");
		return;
	}

	/* Prevent EIRQ from producing interrupt due to glitch */
	eirq_reg_write(edev->eirq_base, EIRQ_IRQ_MASK, 0xFFFFFFFF);

	tmp = readl(edev->rst_base + LV_SYS);
	tmp |= BIT(1);
	writel(tmp, edev->rst_base + LV_SYS);

	eirq_reg_write(edev->eirq_base, EIRQ_IRQ_CLR, 0xFFFFFFFF);
	eirq_reg_write(edev->eirq_base, EIRQ_EDGE_EN, 0x0);
	eirq_reg_write(edev->eirq_base, EIRQ_DBNC_EN, 0x0);
	eirq_reg_write(edev->eirq_base, EIRQ_LVL_TRIG_INV_EN, 0x0);

	for (i = 0; i < MAX_EIRQ_PINS; i++) {
		eirq_reg_write(edev->eirq_base, eirq_get_sens_num_ofs(i), DEFAULT_SENS_NUM);
		eirq_reg_write(edev->eirq_base, eirq_get_hold_num_ofs(i), DEFAULT_HOLD_NUM);
	}

	udelay(1);

	tmp = readl(edev->rst_base + LV_SYS);
	tmp &= ~BIT(1);
	writel(tmp, edev->rst_base + LV_SYS);
}

static void eirq_hw_unmask(struct eirq_dev *edev)
{
	u32 i;

	for (i = 0; i < MAX_EIRQ_PINS; i++) {
		if (edev->pins[i].used) {
			eirq_mask_irq(edev, i, false);
		}
	}
}

static int eirq_parse_dt(struct device *dev, struct eirq_dev *edev)
{
	struct device_node *np = dev->of_node;
	struct device_node *child;
	u32 eirq_settings[3] = { 0 };
	u32 id = 0, cnt = 0;

	for_each_child_of_node (np, child) {
		if (sscanf(child->name, "eirq%u", &id) != 1) {
			dev_warn(dev, "Invalid EIRQ node name: %s\n", child->name);
			continue;
		}

		if (id >= MAX_EIRQ_PINS) {
			dev_warn(dev, "Invalid eirq id %u (max %u)\n", id, MAX_EIRQ_PINS);
			continue;
		}

		edev->pins[id].id = id;

#ifdef EIRQ_EXT_DEBUG
		eirq_init_pin_iomux(&edev->pins[id]);
#endif // EIRQ_EXT_DEBUG

		if (of_property_read_u32(child, "trigger-mode", &edev->pins[id].trigger_mode)) {
			edev->pins[id].trigger_mode = IRQ_TYPE_NONE;
		}

		if (!eirq_is_trig_valid(edev->pins[id].trigger_mode)) {
			dev_err(dev, "Invalid mode %u\n", edev->pins[id].trigger_mode);
			return -EINVAL;
		}

		if (!of_property_read_u32_array(child, "eirq-settings", eirq_settings, 3)) {
			edev->pins[id].debounce = eirq_settings[0];
			edev->pins[id].sens_num = eirq_settings[1];
			edev->pins[id].hold_num = eirq_settings[2];
		} else {
			edev->pins[id].debounce = 0;
			edev->pins[id].sens_num = DEFAULT_SENS_NUM;
			edev->pins[id].hold_num = DEFAULT_HOLD_NUM;
		}

		if (edev->pins[id].sens_num > MAX_SENS_NUM) {
			edev->pins[id].sens_num = MAX_SENS_NUM;
			dev_warn(dev, "Set pin %u sens num to max %u\n", id, MAX_SENS_NUM);
		}

		if (edev->pins[id].hold_num > MAX_HOLD_NUM) {
			edev->pins[id].hold_num = MAX_HOLD_NUM;
			dev_warn(dev, "Set pin %u hold num to max %u\n", id, MAX_HOLD_NUM);
		}

		edev->pins[id].used = true;
		cnt++;
		DBG("Valid cnt:%u, id:%u, used:%u, trigger_mode: %u, "
		    "debounce: %u, sens_num: %u, hold_num: %u\n",
		    cnt, edev->pins[id].id, edev->pins[id].used, edev->pins[id].trigger_mode, edev->pins[id].debounce,
		    edev->pins[id].sens_num, edev->pins[id].hold_num);
	}

	edev->num_pins = cnt;
	return 0;
}

static int eirq_probe(struct platform_device *pdev)
{
	struct eirq_dev *edev;
	int ret = 0;
	u32 i;

	edev = devm_kzalloc(&pdev->dev, sizeof(*edev), GFP_KERNEL);
	if (!edev) {
		dev_err(&pdev->dev, "Failed to allocate eirq_dev\n");
		return -ENOMEM;
	}
	g_edev = edev;
	edev->dev = &pdev->dev;

	edev->eirq_base = ioremap(EIRQ_BASE, 0x40);
	if (!edev->eirq_base) {
		dev_err(&pdev->dev, "Failed to ioremap eirq_base\n");
		ret = -ENOMEM;
		goto err_exit;
	}

	edev->rst_base = ioremap(RST_BASE, 0x4);
	if (!edev->rst_base) {
		dev_err(&pdev->dev, "Failed to ioremap rst_base\n");
		ret = -ENOMEM;
		goto err_iounmap_eirq;
	}

	eirq_hw_reset(edev);

	ret = eirq_parse_dt(&pdev->dev, edev);
	if (ret) {
		dev_err(&pdev->dev, "Failed to parse device tree\n");
		goto err_iounmap_rst;
	}

	for (i = 0; i < MAX_EIRQ_PINS; i++) {
		if (!edev->pins[i].used) {
			continue;
		}
		eirq_set_trigger(edev, &edev->pins[i]);
		eirq_set_debounce(edev, &edev->pins[i]);
	}

	eirq_hw_unmask(edev);

	platform_set_drvdata(pdev, edev);
	dev_info(&pdev->dev, "EIRQ driver probed successfully\n");
	return 0;

err_iounmap_rst:
	iounmap(edev->rst_base);
err_iounmap_eirq:
	iounmap(edev->eirq_base);
err_exit:
	g_edev = NULL;
	return ret;
}

static int eirq_remove(struct platform_device *pdev)
{
	struct eirq_dev *edev = platform_get_drvdata(pdev);
	u32 i;

	if (!edev) {
		goto remove_exit;
	}

	eirq_hw_reset(edev);

#ifdef EIRQ_EXT_DEBUG
	for (i = 0; i < MAX_EIRQ_PINS; i++) {
		if (edev->pins[i].iomux_base) {
			iounmap(edev->pins[i].iomux_base);
			edev->pins[i].iomux_base = NULL;
		}
	}
#endif // EIRQ_EXT_DEBUG

	if (edev->eirq_base) {
		iounmap(edev->eirq_base);
		edev->eirq_base = NULL;
	}

	if (edev->rst_base) {
		iounmap(edev->rst_base);
		edev->rst_base = NULL;
	}
	platform_set_drvdata(pdev, NULL);

remove_exit:
	g_edev = NULL;
	dev_info(&pdev->dev, "EIRQ driver removed successfully\n");
	return 0;
}

static struct of_device_id eirq_of_match[] = {
	{ .compatible = "augentix,eirq-ext" },
	{},
};
MODULE_DEVICE_TABLE(of, eirq_of_match);

static struct platform_driver eirq_platform_driver = {
	.probe  = eirq_probe,
	.remove = eirq_remove,
	.driver = {
		.name = DRV_NAME,
		.of_match_table = eirq_of_match,
	},
};

static int __init eirq_init(void)
{
	return platform_driver_register(&eirq_platform_driver);
}

static void __exit eirq_exit(void)
{
	platform_driver_unregister(&eirq_platform_driver);
}

module_init(eirq_init);
module_exit(eirq_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yan Chen <Yan.Chen@augentix.com>");
MODULE_DESCRIPTION("Augentix EIRQ Extension Driver");