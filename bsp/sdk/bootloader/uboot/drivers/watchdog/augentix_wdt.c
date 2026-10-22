#include <common.h>
#include <watchdog.h>
#include <asm/io.h>

/* Region AMC */
#define AMC_REG ((volatile void *)AMC_BASE)
#define AON_WDT_IRQ_MSK_OFFSET 0x08
#define AON_WDT_EN_SRC_OFFSET 0x20

/* Region AON_WDT */
#define AON_WDT_REG ((volatile void *)WDT_BASE)
#define AON_WDT_DIS_WDT_OFFSET 0x00
#define AON_WDT_PRE_TH_OFFSET 0x04
#define AON_WDT_CNT_TH0_OFFSET 0x08 // Use PWR_DN stage as STAGE 1
#define AON_WDT_CNT_TH1_OFFSET 0x0C
#define AON_WDT_CNT_TH2_OFFSET 0x10 // Use WAKEUP stage as STAGE 2
#define AON_WDT_CNT_OFFSET 0x14
#define AON_WDT_STAGE_OFFSET 0x18

/* Control Register */
#define AON_WDT_EN_SRC_CIRCUIT 0x0
#define AON_WDT_EN_SRC_CPU 0x1
#define AON_WDT_EN_CSR_ACTIVE (0x1 << 8)

#define AON_WDT_IRQ_MSK ~(0x1 << 9)

/* Time config*/
#define AON_WDT_PRE_VAL 0xFFFF
#define DEFAULT_TIMEOUT 30
#define AON_WDT_CNT_TH1_VAL (DEFAULT_TIMEOUT * (CONFIG_WDT_CLK / (AON_WDT_PRE_VAL + 1)))

static void wdt_set_active(void)
{
	writel(AON_WDT_EN_SRC_CPU | AON_WDT_EN_CSR_ACTIVE, AMC_REG + AON_WDT_EN_SRC_OFFSET);
}

static void wdt_set_inactive(void)
{
	writel(AON_WDT_EN_SRC_CPU & ~AON_WDT_EN_CSR_ACTIVE, AMC_REG + AON_WDT_EN_SRC_OFFSET);
}

void hw_watchdog_reset(void)
{
	wdt_set_inactive();
	while ((readl(AON_WDT_REG + AON_WDT_STAGE_OFFSET) & 0x3) != 0) {
		wdt_set_active();
		wdt_set_inactive();
	}

	wdt_set_active();
	while ((readl(AON_WDT_REG + AON_WDT_STAGE_OFFSET) & 0x3) != 1) {
		wdt_set_inactive();
		wdt_set_active();
	}
}

void hw_watchdog_init(void)
{
	u32 irq_msk;

	irq_msk = readl(AMC_REG + AON_WDT_IRQ_MSK_OFFSET) & AON_WDT_IRQ_MSK;
	writel(irq_msk, AMC_REG + AON_WDT_IRQ_MSK_OFFSET);

	writel(AON_WDT_PRE_VAL, AON_WDT_REG + AON_WDT_PRE_TH_OFFSET);
	writel(AON_WDT_CNT_TH1_VAL, AON_WDT_REG + AON_WDT_CNT_TH0_OFFSET);
	writel(1 << 16, AON_WDT_REG + AON_WDT_CNT_TH2_OFFSET);

	if ((readl(AON_WDT_REG + AON_WDT_DIS_WDT_OFFSET) & 0x1) != 0) {
		writel(0x0, AON_WDT_REG + AON_WDT_DIS_WDT_OFFSET);
	}

	wdt_set_active();
	while ((readl(AON_WDT_REG + AON_WDT_STAGE_OFFSET) & 0x3) != 1) {
		wdt_set_inactive();
		wdt_set_active();
	}
}

void hw_watchdog_reboot(void)
{
	writel(1, AON_WDT_REG + AON_WDT_CNT_TH0_OFFSET);
	writel(1 << 16, AON_WDT_REG + AON_WDT_CNT_TH2_OFFSET);

	hw_watchdog_reset();
	while (1)
		;
}
