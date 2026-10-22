#include <common.h>
#include <watchdog.h>
#include <asm/io.h>

/* Region AON_WDT */
#define AON_WDT_REG ((volatile void *)WDT_BASE)
#define AON_WDT_TRIGGER_OFFSET 0x00
#define AON_WDT_IRQ_CLR_OFFSET 0x04
#define AON_WDT_IRQ_STATUS_OFFSET 0x08
#define AON_WDT_STATUS_OFFSET 0x0C
#define AON_WDT_UNLOCK_OFFSET 0x10
#define AON_WDT_CTRL_OFFSET 0x14
#define AON_WDT_CNT_TH_INIT_OFFSET 0x18
#define AON_WDT_CNT_TH_NORMAL_OFFSET 0x1C
#define AON_WDT_CNT_TH_TIMEOUT_OFFSET 0x20
#define AON_WDT_RESERVED_OFFSET 0x24

/* Control Register */
#define AON_WDT_IRQ_CLR 0x1
#define AON_WDT_EN 0x0
#define AON_WDT_DIS 0x1
#define AON_WDT_TRIGGER 0x1

/* Time config*/
#define DEFAULT_TIMEOUT 30
#define MAX_TIMEOUT 90
#define DFLT_PRE_VAL 0xF
#define DFLT_INIT_VAL 0x5521
#define DFLT_NORM_MIN_VAL 0x1C9C
#define DFLT_NORM_MAX_VAL 0x55D5
#define DFLT_TOUT_1_VAL 0x5B8
#define DFLT_TOUT_2_VAL 0x2DC
#define RST_PRE_CNT 0
#define RST_INIT_CNT 0
#define RST_NORM_MIN_CNT 3
#define RST_NORM_MAX_CNT 5
#define RST_TOUT_1_CNT 5
#define RST_TOUT_2_CNT 5

static void aon_wdt_unlock(void)
{
	writel(0x54, AON_WDT_REG + AON_WDT_UNLOCK_OFFSET);
	writel(0x6F, AON_WDT_REG + AON_WDT_UNLOCK_OFFSET);
	writel(0x6B, AON_WDT_REG + AON_WDT_UNLOCK_OFFSET);
	writel(0x79, AON_WDT_REG + AON_WDT_UNLOCK_OFFSET);
	writel(0x6F, AON_WDT_REG + AON_WDT_UNLOCK_OFFSET);
}

static void aon_wdt_lock(void)
{
	writel(0x0, AON_WDT_REG + AON_WDT_UNLOCK_OFFSET);
}

static void wdt_set_active(void)
{
	unsigned long t_reg;

	if (readl(AON_WDT_REG + AON_WDT_CTRL_OFFSET) & AON_WDT_DIS) {
		t_reg = readl(AON_WDT_REG + AON_WDT_CTRL_OFFSET);
		t_reg &= ~AON_WDT_DIS;
		writel(t_reg, AON_WDT_REG + AON_WDT_CTRL_OFFSET);
	}
}

static void wdt_set_inactive(void)
{
	unsigned long t_reg;

	if (!(readl(AON_WDT_REG + AON_WDT_CTRL_OFFSET) & AON_WDT_DIS)) {
		t_reg = readl(AON_WDT_REG + AON_WDT_CTRL_OFFSET);
		t_reg |= AON_WDT_DIS;
		writel(t_reg, AON_WDT_REG + AON_WDT_CTRL_OFFSET);
	}
}

/* Feed the watchdog */
void hw_watchdog_reset(void)
{
	writel(AON_WDT_TRIGGER, AON_WDT_REG + AON_WDT_TRIGGER_OFFSET);
}

void hw_watchdog_init(void)
{
	unsigned long t_reg;

	aon_wdt_unlock();
	t_reg = readl(AON_WDT_REG + AON_WDT_CTRL_OFFSET);
	t_reg |= (DFLT_PRE_VAL << 16);
	writel(t_reg, AON_WDT_REG + AON_WDT_CTRL_OFFSET);
	writel(DFLT_INIT_VAL, AON_WDT_REG + AON_WDT_CNT_TH_INIT_OFFSET);
	writel(DFLT_NORM_MIN_VAL | (DFLT_NORM_MAX_VAL << 16), AON_WDT_REG + AON_WDT_CNT_TH_NORMAL_OFFSET);
	writel(DFLT_TOUT_1_VAL | (DFLT_TOUT_2_VAL << 16), AON_WDT_REG + AON_WDT_CNT_TH_TIMEOUT_OFFSET);
	wdt_set_active();
	aon_wdt_lock();

	writel(AON_WDT_TRIGGER, AON_WDT_REG + AON_WDT_TRIGGER_OFFSET);
}

void hw_watchdog_reboot(void)
{
	aon_wdt_unlock();
	writel((RST_PRE_CNT << 16) | (1 << 8) | (AON_WDT_DIS << 0), AON_WDT_REG + AON_WDT_CTRL_OFFSET);
	writel(RST_INIT_CNT, AON_WDT_REG + AON_WDT_CNT_TH_INIT_OFFSET);
	writel((RST_NORM_MAX_CNT << 16) | (RST_NORM_MIN_CNT << 0), AON_WDT_REG + AON_WDT_CNT_TH_NORMAL_OFFSET);
	writel((RST_TOUT_2_CNT << 16) | (RST_TOUT_1_CNT << 0), AON_WDT_REG + AON_WDT_CNT_TH_TIMEOUT_OFFSET);
	writel((RST_PRE_CNT << 16) | (1 << 8) | (AON_WDT_EN << 0), AON_WDT_REG + AON_WDT_CTRL_OFFSET);
	aon_wdt_lock();
	writel(AON_WDT_TRIGGER, AON_WDT_REG + AON_WDT_TRIGGER_OFFSET);
	while (1)
		;
}
