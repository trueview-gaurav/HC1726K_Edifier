#include <common.h>
#include <malloc.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/bitops.h>
#include <asm-generic/gpio.h>

//#define DEBUG
#ifdef DEBUG
#define DBG(fmt, args...)            \
	do {                         \
		printf(fmt, ##args); \
	} while (0)
#else
#define DBG(fmt, args...)
#endif

#if defined(CONFIG_OSAKA)
#define PIOC0_BASE_NUM 0
#define PIOC1_BASE_NUM 32
#define PIOC2_BASE_NUM 54
#define PIOC3_BASE_NUM 86
#define GPIO_AMOUNT 111

#define PMU_IOC_O_OFFSET 0x0
#define PMU_IOC_OE_OFFSET 0x4
#define PMU_IOC_I_OFFSET 0x8

#define AIOC0_O_OFFSET 0xC
#define AIOC0_OE_OFFSET 0x10
#define AIOC0_I_OFFSET 0x14

#define PIOC0_O_OFFSET 0x18
#define PIOC0_OE_OFFSET 0x1C
#define PIOC0_I_OFFSET 0x20
#define PIOC0_IE_OFFSET 0x24
#define PIOC1_O_OFFSET 0x28
#define PIOC1_OE_OFFSET 0x2C
#define PIOC1_I_OFFSET 0x30
#define PIOC1_IE_OFFSET 0x34
#define PIOC2_O_OFFSET 0x38
#define PIOC2_OE_OFFSET 0x3C
#define PIOC2_I_OFFSET 0x40
#define PIOC2_IE_OFFSET 0x44
#define PIOC3_O_OFFSET 0x48
#define PIOC3_OE_OFFSET 0x4C
#define PIOC3_I_OFFSET 0x50
#define PIOC3_IE_OFFSET 0x54
#else
/*
 * GPIO domain define
 *      PIOC0: 0~31, PIOC1: 32~48, PMU_IOC: 49~51
 */
#define PIOC0_BASE_NUM 0
#define PIOC1_BASE_NUM 32

#define PMU_IOC_BASE_NUM 49
#define GPIO_AMOUNT 52
#define PMU_IOC_GPO 49
#define PMU_IOC_GPI    \
	{              \
		50, 51 \
	}

#define PMU_IOC_O_OFFSET 0x0
#define PMU_IOC_OE_OFFSET 0x4
#define PMU_IOC_I_OFFSET 0x8
#define PIOC0_O_OFFSET 0x10
#define PIOC0_OE_OFFSET 0x14
#define PIOC0_I_OFFSET 0x18
#define PIOC0_IE_OFFSET 0x1C
#define PIOC1_O_OFFSET 0x20
#define PIOC1_OE_OFFSET 0x24
#define PIOC1_I_OFFSET 0x28
#define PIOC1_IE_OFFSET 0x2C
#endif

#if defined(CONFIG_OSAKA)
typedef enum { PIOC0, PIOC1, PIOC2, PIOC3, BANK_NUM } AGTX_GPIO_DOMAIN;

static int gpio_to_domain(unsigned gpio)
{
	AGTX_GPIO_DOMAIN domain;

	if (gpio < PIOC1_BASE_NUM) {
		domain = PIOC0;
	} else if ((gpio >= PIOC1_BASE_NUM) && (gpio < PIOC2_BASE_NUM)) {
		domain = PIOC1;
	} else if ((gpio >= PIOC2_BASE_NUM) && (gpio < PIOC3_BASE_NUM)) {
		domain = PIOC2;
	} else if ((gpio >= PIOC3_BASE_NUM) && (gpio < GPIO_AMOUNT)) {
		domain = PIOC3;
	} else {
		return -1;
	}

	return domain;
}
#else
typedef enum { PIOC0, PIOC1, PMU_IOC, BANK_NUM } AGTX_GPIO_DOMAIN;

static int gpio_to_domain(unsigned gpio)
{
	AGTX_GPIO_DOMAIN domain;

	if (gpio < PIOC1_BASE_NUM) {
		domain = PIOC0;
	} else if ((gpio >= PIOC1_BASE_NUM) && (gpio < PMU_IOC_BASE_NUM)) {
		domain = PIOC1;
	} else if ((gpio >= PMU_IOC_BASE_NUM) && (gpio < GPIO_AMOUNT)) {
		domain = PMU_IOC;
	} else {
		return -1;
	}

	return domain;
}
#endif

typedef struct augentix_gpio_desc {
	AGTX_GPIO_DOMAIN domain;
	uint8_t pin_offset;
	uint32_t i_offset;
	uint32_t ie_offset;
	uint32_t o_offset;
	uint32_t oe_offset;
} AGTX_GPIO_DESC;

#if defined(CONFIG_OSAKA)
static AGTX_GPIO_DESC g_gpio_desc[] = {
	{ PIOC0, PIOC0_BASE_NUM, PIOC0_I_OFFSET, PIOC0_IE_OFFSET, PIOC0_O_OFFSET, PIOC0_OE_OFFSET },
	{ PIOC1, PIOC1_BASE_NUM, PIOC1_I_OFFSET, PIOC1_IE_OFFSET, PIOC1_O_OFFSET, PIOC1_OE_OFFSET },
	{ PIOC2, PIOC2_BASE_NUM, PIOC2_I_OFFSET, PIOC2_IE_OFFSET, PIOC2_O_OFFSET, PIOC2_OE_OFFSET },
	{ PIOC3, PIOC3_BASE_NUM, PIOC3_I_OFFSET, PIOC3_IE_OFFSET, PIOC3_O_OFFSET, PIOC3_OE_OFFSET },
};
#else
static AGTX_GPIO_DESC g_gpio_desc[] = {
	{ PIOC0, PIOC0_BASE_NUM, PIOC0_I_OFFSET, PIOC0_IE_OFFSET, PIOC0_O_OFFSET, PIOC0_OE_OFFSET },
	{ PIOC1, PIOC1_BASE_NUM, PIOC1_I_OFFSET, PIOC1_IE_OFFSET, PIOC1_O_OFFSET, PIOC1_OE_OFFSET },
	{ PMU_IOC, PMU_IOC_BASE_NUM, PMU_IOC_I_OFFSET, 0xFFFFFFFF, PMU_IOC_O_OFFSET, PMU_IOC_OE_OFFSET },
};
#endif

int gpio_get_value(unsigned gpio)
{
	AGTX_GPIO_DESC data;
	uintptr_t reg;
	uint32_t reg_val, domain;
	uint32_t o_off, oe_off, i_off, pin_off;

	domain = gpio_to_domain(gpio);
	if (domain < 0)
		return -1;

	data = g_gpio_desc[domain];

	o_off = data.o_offset;
	oe_off = data.oe_offset;
	i_off = data.i_offset;
	pin_off = data.pin_offset;

	reg = GPIOC_BASE + oe_off;
	reg_val = (readl(reg) & (1 << (gpio - pin_off)));
	if (reg_val) {
		reg = GPIOC_BASE + o_off;
	} else {
		reg = GPIOC_BASE + i_off;
	}
	reg_val = (readl(reg) & (1 << (gpio - pin_off)));

	DBG("In %s, pin %u, pin_off %u, o_off 0x%x, oe_off 0x%x, i_off 0x%x, val %u\n", __func__, gpio, pin_off, o_off,
	    oe_off, i_off, !!reg_val);

	return !!reg_val;
}

int gpio_set_value(unsigned gpio, int value)
{
	AGTX_GPIO_DESC data;
	uintptr_t reg;
	uint32_t reg_val, domain, o_off, pin_off;

#if defined(CONFIG_OSAKA)
	domain = gpio_to_domain(gpio);
	if (domain < 0)
		return -1;
#else
	uint8_t pmu_gpi[] = PMU_IOC_GPI;

	domain = gpio_to_domain(gpio);
	if (domain < 0 || gpio == pmu_gpi[0] || gpio == pmu_gpi[1])
		return -1;
#endif

	data = g_gpio_desc[domain];

	o_off = data.o_offset;
	pin_off = data.pin_offset;
	reg = GPIOC_BASE + o_off;

	reg_val = readl(reg);
	reg_val &= ~(1 << (gpio - pin_off));
	if (value)
		reg_val |= (1 << (gpio - pin_off));
	writel(reg_val, reg);
	DBG("In %s, pin %u, pin_off %u, o_off 0x%x, reg_val 0x%x\n", __func__, gpio, pin_off, o_off, reg_val);
	return 0;
}

static int gpio_set_direction(unsigned gpio, unsigned long flags)
{
	AGTX_GPIO_DESC data;
	uint32_t oe_val, domain, oe_off, pin_off;
	uint32_t ie_val, ie_off;

#if defined(CONFIG_OSAKA)
	domain = gpio_to_domain(gpio);
	if (domain < 0)
		return -1;
#else
	domain = gpio_to_domain(gpio);
	if (domain < 0 || domain == PMU_IOC) //Fixed pmu gpio direction
		return -1;
#endif
	data = g_gpio_desc[domain];

	oe_off = data.oe_offset;
	pin_off = data.pin_offset;
	ie_off = data.ie_offset;

	oe_val = readl((uintptr_t)(GPIOC_BASE + oe_off));
	oe_val &= ~(1 << (gpio - pin_off));
	ie_val = readl((uintptr_t)(GPIOC_BASE + ie_off));
	ie_val &= ~(1 << (gpio - pin_off));

	if (flags == GPIOD_IS_OUT) {
		oe_val |= (1 << (gpio - pin_off));
	} else {
		ie_val |= (1 << (gpio - pin_off));
	}
	writel(oe_val, (uintptr_t)(GPIOC_BASE + oe_off));
	writel(ie_val, (uintptr_t)(GPIOC_BASE + ie_off));

	DBG("In %s, pin %u, pin_off %u, ie_off 0x%x, ie_val 0x%x, oe_off 0x%x, oe_val 0x%x\n", __func__, gpio, pin_off,
	    ie_off, ie_val, oe_off, oe_val);
	return 0;
}

#if 0 // can be used when needed
static int gpio_get_direction(unsigned gpio)
{
	AGTX_GPIO_DESC data;
	uintptr_t reg;
	uint32_t reg_val, domain, oe_off, pin_off;

	domain = gpio_to_domain(gpio);
	if (domain < 0)
		return -1;

	data = g_gpio_desc[domain];

	oe_off = data.oe_offset;
	pin_off = data.pin_offset;
	reg = GPIOC_BASE + oe_off;

	reg_val = readl(reg);
	DBG("In %s, pin %u, pin_off %u, oe_off 0x%x, val 0x%x\n", __func__, gpio, pin_off, oe_off,
	    reg_val & (1 << (gpio - pin_off)));

	if (reg_val & (1 << (gpio - pin_off)))
		return GPIOD_IS_OUT;

	return GPIOD_IS_IN;
}
#endif

int gpio_direction_input(unsigned gpio)
{
	DBG("In %s\n", __func__);
	return gpio_set_direction(gpio, GPIOD_IS_IN);
}

int gpio_direction_output(unsigned gpio, int value)
{
	DBG("In %s\n", __func__);
	gpio_set_value(gpio, value);
	return gpio_set_direction(gpio, GPIOD_IS_OUT);
}
