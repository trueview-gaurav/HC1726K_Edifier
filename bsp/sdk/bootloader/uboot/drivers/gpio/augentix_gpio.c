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

/*
 * GPIO domain define
 *      PIOC0: 0~31, PIOC1: 32~63, PIOC2: 64~67
 *	AIOC: 68~80, MIPI_TX: 81~90, MIPI_RX0: 91~100, MIPI_RX1: 101~110
 */
#define PIOC0_BASE_NUM 0
#define PIOC1_BASE_NUM 32
#define PIOC2_BASE_NUM 64
#define AIOC_BASE_NUM 68
#define MIPI_TX_BASE_NUM 81
#define MIPI_RX0_BASE_NUM 91
#define MIPI_RX1_BASE_NUM 101
#define GPIO_AMOUNT 111

#define AIOC_O_OFFSET 0x0
#define AIOC_OE_OFFSET 0x4
#define AIOC_I_OFFSET 0x8
#define PIOC0_O_OFFSET 0xC
#define PIOC0_OE_OFFSET 0x10
#define PIOC0_I_OFFSET 0x14
#define PIOC1_O_OFFSET 0x18
#define PIOC1_OE_OFFSET 0x1C
#define PIOC1_I_OFFSET 0x20
#define PIOC2_O_OFFSET 0x24
#define PIOC2_OE_OFFSET 0x28
#define PIOC2_I_OFFSET 0x30

//output only
#define MIPI_TX_OFFSET 0x34

//input only
#define MIPI_RX0_OFFSET 0x38
#define MIPI_RX1_OFFSET 0x3C

typedef enum { PIOC0, PIOC1, PIOC2, AIOC, MIPI_TX, MIPI_RX0, MIPI_RX1, BANK_NUM } AGTX_GPIO_DOMAIN;

typedef struct augentix_gpio_desc {
	AGTX_GPIO_DOMAIN domain;
	uint8_t pin_offset;
	uint32_t i_offset;
	uint32_t o_offset;
	uint32_t oe_offset;
} AGTX_GPIO_DESC;

static AGTX_GPIO_DESC g_gpio_desc[] = {
	{ PIOC0, PIOC0_BASE_NUM, PIOC0_I_OFFSET, PIOC0_O_OFFSET, PIOC0_OE_OFFSET },
	{ PIOC1, PIOC1_BASE_NUM, PIOC1_I_OFFSET, PIOC1_O_OFFSET, PIOC1_OE_OFFSET },
	{ PIOC2, PIOC2_BASE_NUM, PIOC2_I_OFFSET, PIOC2_O_OFFSET, PIOC2_OE_OFFSET },
	{ AIOC, AIOC_BASE_NUM, AIOC_I_OFFSET, AIOC_O_OFFSET, AIOC_OE_OFFSET },
	{ MIPI_TX, MIPI_TX_BASE_NUM, 0xFFFFFFFF, MIPI_TX_OFFSET, 0xFFFFFFFF },
	{ MIPI_RX0, MIPI_RX0_BASE_NUM, MIPI_RX0_OFFSET, 0xFFFFFFFF, 0xFFFFFFFF },
	{ MIPI_RX1, MIPI_RX1_BASE_NUM, MIPI_RX1_OFFSET, 0xFFFFFFFF, 0xFFFFFFFF },
};

static int gpio_to_domain(unsigned gpio)
{
	AGTX_GPIO_DOMAIN domain;

	if (gpio < PIOC1_BASE_NUM) {
		domain = PIOC0;
	} else if ((gpio >= PIOC1_BASE_NUM) && (gpio < PIOC2_BASE_NUM)) {
		domain = PIOC1;
	} else if ((gpio >= PIOC2_BASE_NUM) && (gpio < AIOC_BASE_NUM)) {
		domain = PIOC2;
	} else if ((gpio >= AIOC_BASE_NUM) && (gpio < MIPI_TX_BASE_NUM)) {
		domain = AIOC;
	} else if ((gpio >= MIPI_TX_BASE_NUM) && (gpio < MIPI_RX0_BASE_NUM)) {
		domain = MIPI_TX;
	} else if ((gpio >= MIPI_RX0_BASE_NUM) && (gpio < MIPI_RX1_BASE_NUM)) {
		domain = MIPI_RX0;
	} else if ((gpio >= MIPI_RX1_BASE_NUM) && (gpio < GPIO_AMOUNT)) {
		domain = MIPI_RX1;
	} else {
		return -1;
	}

	return domain;
}

int gpio_get_value(unsigned gpio)
{
	AGTX_GPIO_DESC data;
	uint32_t reg, reg_val, domain;
	uint32_t o_off, oe_off, i_off, pin_off;

	domain = gpio_to_domain(gpio);
	if (domain < 0)
		return -1;

	data = g_gpio_desc[domain];

	o_off = data.o_offset;
	oe_off = data.oe_offset;
	i_off = data.i_offset;
	pin_off = data.pin_offset;

	if (domain == MIPI_RX0 || domain == MIPI_RX1) {
		reg = GPIOC_BASE + i_off;
	} else if (domain == MIPI_TX) {
		reg = GPIOC_BASE + o_off;
	} else {
		reg = GPIOC_BASE + oe_off;
		reg_val = (readl(reg) & (1 << (gpio - pin_off)));
		if (reg_val) {
			reg = GPIOC_BASE + o_off;
		} else {
			reg = GPIOC_BASE + i_off;
		}
	}
	reg_val = (readl(reg) & (1 << (gpio - pin_off)));

	DBG("In %s, pin %u, pin_off %u, o_off 0x%x, oe_off 0x%x, i_off 0x%x, val %u\n", __func__, gpio, pin_off, o_off,
	    oe_off, i_off, !!reg_val);

	return !!reg_val;
}

int gpio_set_value(unsigned gpio, int value)
{
	AGTX_GPIO_DESC data;
	uint32_t reg, reg_val, domain, o_off, pin_off;

	domain = gpio_to_domain(gpio);
	if (domain < 0 || domain == MIPI_RX0 || domain == MIPI_RX1)
		return -1;

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

	domain = gpio_to_domain(gpio);
	if (domain < 0)
		return -1;

	data = g_gpio_desc[domain];

	oe_off = data.oe_offset;
	pin_off = data.pin_offset;

	// prevent unused warning, return here
	if (domain == MIPI_TX || domain == MIPI_RX0 || domain == MIPI_RX1)
		return 0;

	oe_val = readl(GPIOC_BASE + oe_off);
	oe_val &= ~(1 << (gpio - pin_off));

	if (flags == GPIOD_IS_OUT) {
		oe_val |= (1 << (gpio - pin_off));
	}
	writel(oe_val, GPIOC_BASE + oe_off);

	DBG("In %s, pin %u, pin_off %u, oe_off 0x%x, oe_val 0x%x\n", __func__, gpio, pin_off, oe_off, oe_val);
	return 0;
}

#if 0 // can be used when needed
static int gpio_get_direction(unsigned gpio)
{
	AGTX_GPIO_DESC data;
	uint32_t reg, reg_val, domain, oe_off, pin_off;

	domain = gpio_to_domain(gpio);
	if (domain < 0) {
		return -1;
	} else if (domain == MIPI_TX) {
		return GPIOD_IS_OUT;
	} else if (domain == MIPI_RX0 || domain == MIPI_RX1) {
		return GPIOD_IS_IN;
	}

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

/*
 * get_gpio_csr is for RTOS for get gpio_o address and pin offset
 * currently only gpio driver v1 use this function in agtx_early_amp.c
 */
int get_gpio_csr(uint32_t gpio_id, uint32_t **csr, uint32_t *bit)
{
	uint32_t domain;
	AGTX_GPIO_DESC data;

	domain = gpio_to_domain(gpio_id);

	if (domain < 0)
		return -1;

	data = g_gpio_desc[domain];

	*csr = (uint32_t *)(GPIOC_BASE + data.o_offset);
	*bit = 0x01 << (gpio_id - data.pin_offset);
	return 0;
}
