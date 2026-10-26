// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2026 Augentix Inc.
 *
 * Ported from drivers/gpio/gpio-augentix-v2.c (osaka, sapporo) and
 * gpio-augentix.c (kyoto) of linux_6.1.102. PIOC0 and PIOC1 only; the higher
 * banks are not carried.
 */

#include <dm.h>
#include <asm/gpio.h>
#include <linux/bitops.h>
#include <linux/io.h>

struct augentix_gpio_bank {
	u32 base_num;
	u32 o_offset;
	u32 oe_offset;
	u32 i_offset;
	u32 ie_offset;
};

struct augentix_gpio_variant {
	const struct augentix_gpio_bank *banks;
	u32 pins;
	bool has_ie;
};

#if defined(CONFIG_AUGENTIX_SOC_OSAKA)
static const struct augentix_gpio_bank augentix_gpio_banks[] = {
	{ 0,  0x18, 0x1c, 0x20, 0 },
	{ 32, 0x24, 0x28, 0x2c, 0 },
};

static const struct augentix_gpio_variant augentix_gpio_variant = {
	.banks = augentix_gpio_banks,
	.pins = 64,
	.has_ie = false,
};
#elif defined(CONFIG_AUGENTIX_SOC_SAPPORO)
static const struct augentix_gpio_bank augentix_gpio_banks[] = {
	{ 0,  0x10, 0x14, 0x18, 0x1c },
	{ 32, 0x20, 0x24, 0x28, 0x2c },
};

static const struct augentix_gpio_variant augentix_gpio_variant = {
	.banks = augentix_gpio_banks,
	.pins = 49,
	.has_ie = true,
};
#else
static const struct augentix_gpio_bank augentix_gpio_banks[] = {
	{ 0,  0x0c, 0x10, 0x14, 0 },
	{ 32, 0x18, 0x1c, 0x20, 0 },
};

static const struct augentix_gpio_variant augentix_gpio_variant = {
	.banks = augentix_gpio_banks,
	.pins = 64,
	.has_ie = false,
};
#endif

struct augentix_gpio_priv {
	void __iomem *base;
	const struct augentix_gpio_variant *variant;
};

static const struct augentix_gpio_bank *
augentix_gpio_bank(struct augentix_gpio_priv *priv, unsigned int offset)
{
	if (offset >= priv->variant->pins)
		return NULL;

	if (offset >= priv->variant->banks[1].base_num)
		return &priv->variant->banks[1];

	return &priv->variant->banks[0];
}

static int augentix_gpio_set_value(struct udevice *dev, unsigned int offset,
				   int value)
{
	struct augentix_gpio_priv *priv = dev_get_priv(dev);
	const struct augentix_gpio_bank *bank = augentix_gpio_bank(priv, offset);
	u32 val;

	if (!bank)
		return -EINVAL;

	val = readl(priv->base + bank->o_offset) & ~BIT(offset - bank->base_num);
	if (value)
		val |= BIT(offset - bank->base_num);
	writel(val, priv->base + bank->o_offset);

	return 0;
}

static int augentix_gpio_set_direction(struct udevice *dev, unsigned int offset,
				       bool output)
{
	struct augentix_gpio_priv *priv = dev_get_priv(dev);
	const struct augentix_gpio_bank *bank = augentix_gpio_bank(priv, offset);
	u32 mask, val;

	if (!bank)
		return -EINVAL;

	mask = BIT(offset - bank->base_num);

	val = readl(priv->base + bank->oe_offset) & ~mask;
	if (output)
		val |= mask;
	writel(val, priv->base + bank->oe_offset);

	/* v1 has no input-enable register; its 0x1c is PIOC1's oe. */
	if (!priv->variant->has_ie)
		return 0;

	/* An input also needs its buffer enabled here, or it reads back zero. */
	val = readl(priv->base + bank->ie_offset) & ~mask;
	if (!output)
		val |= mask;
	writel(val, priv->base + bank->ie_offset);

	return 0;
}

static int augentix_gpio_direction_input(struct udevice *dev,
					 unsigned int offset)
{
	return augentix_gpio_set_direction(dev, offset, false);
}

static int augentix_gpio_direction_output(struct udevice *dev,
					  unsigned int offset, int value)
{
	int ret;

	ret = augentix_gpio_set_value(dev, offset, value);
	if (ret)
		return ret;

	return augentix_gpio_set_direction(dev, offset, true);
}

static int augentix_gpio_get_value(struct udevice *dev, unsigned int offset)
{
	struct augentix_gpio_priv *priv = dev_get_priv(dev);
	const struct augentix_gpio_bank *bank = augentix_gpio_bank(priv, offset);
	u32 mask, reg;

	if (!bank)
		return -EINVAL;

	mask = BIT(offset - bank->base_num);
	reg = (readl(priv->base + bank->oe_offset) & mask) ? bank->o_offset :
							     bank->i_offset;

	return !!(readl(priv->base + reg) & mask);
}

static int augentix_gpio_get_function(struct udevice *dev, unsigned int offset)
{
	struct augentix_gpio_priv *priv = dev_get_priv(dev);
	const struct augentix_gpio_bank *bank = augentix_gpio_bank(priv, offset);

	if (!bank)
		return -EINVAL;

	if (readl(priv->base + bank->oe_offset) & BIT(offset - bank->base_num))
		return GPIOF_OUTPUT;

	return GPIOF_INPUT;
}

static int augentix_gpio_probe(struct udevice *dev)
{
	struct augentix_gpio_priv *priv = dev_get_priv(dev);
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);

	/* Every SoC names the controller "augentix,gpio", so the layout comes
	 * from the SoC symbol, as linux_6.1.102 selects its driver.
	 */
	priv->variant = &augentix_gpio_variant;

	priv->base = dev_read_addr_ptr(dev);
	if (!priv->base)
		return -EINVAL;

	uc_priv->bank_name = "gpio";
	uc_priv->gpio_count = priv->variant->pins;

	return 0;
}

static const struct dm_gpio_ops augentix_gpio_ops = {
	.direction_input	= augentix_gpio_direction_input,
	.direction_output	= augentix_gpio_direction_output,
	.get_value		= augentix_gpio_get_value,
	.set_value		= augentix_gpio_set_value,
	.get_function		= augentix_gpio_get_function,
};

static const struct udevice_id augentix_gpio_ids[] = {
	{ .compatible = "augentix,gpio" },
	{ }
};

U_BOOT_DRIVER(augentix_gpio) = {
	.name		= "augentix_gpio",
	.id		= UCLASS_GPIO,
	.of_match	= augentix_gpio_ids,
	.ops		= &augentix_gpio_ops,
	.probe		= augentix_gpio_probe,
	.priv_auto	= sizeof(struct augentix_gpio_priv),
};
