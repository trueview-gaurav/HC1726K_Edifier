#include <linux/delay.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/time64.h>
#include <linux/types.h>
#include <linux/version.h>
#include <asm/mach/time.h>
#include <linux/rtc.h>

#include "address.h"

#define AGTX_ROSC_BASE_OFFSET 0x400

#define AGTX_ROSC_TRIM 0x14
#define AGTX_ROSC_WRITE 0x18

#define AGTX_RTC_CTRL					0x00
#define AGTX_RTC_STATE					0x04
#define AGTX_RTC_RST_STATE				0x08
#define AGTX_IRQ_CLEAR					0x0C
#define AGTX_IRQ_MASK					0x10
#define AGTX_IRQ_STATUS					0x14
#define AGTX_TIME_WRITE					0x18
#define AGTX_TIME_READ					0x1C
#define AGTX_ALARM_PMU					0x24

/* RTC_CTRL (0x00) */
#define RUN_STOP_OFFSET					0
#define READ_OFFSET						8
#define WRITE_OFFSET					16
/* RTC_STATE (0x04) */
#define COUNTING_BUSY_OFFSET			0
#define READ_DONE_OFFSET				8
#define WRITE_DONE_OFFSET				16
/* IRQ_CLEAR (0x0C) */
#define IRQ_CLEAR_ALARM_CPU_OFFSET		0
#define IRQ_CLEAR_ALARM_PMU_OFFSET		8
/* IRQ_MASK (0x10) */
#define IRQ_MASK_ALARM_CPU_OFFSET		0
#define IRQ_MASK_ALARM_PMU_OFFSET		8
/* IRQ_STATUS (0x14) */
#define STATUS_MATCH_ALARM_CPU_OFFSET	0
#define STATUS_MATCH_ALARM_PMU_OFFSET	8
/* TIME_WRITE (0x18) */
#define TIME_SEC_WRITE_OFFSET			0
#define TIME_MIN_WRITE_OFFSET			6
#define TIME_HOUR_WRITE_OFFSET			12
#define TIME_DAY_WRITE_OFFSET			17
/* TIME_READ (0x1C) */
#define TIME_SEC_READ_OFFSET			0
#define TIME_MIN_READ_OFFSET			6
#define TIME_HOUR_READ_OFFSET			12
#define TIME_DAY_READ_OFFSET			17

/* ROSC_TRIM (0x14) */
#define ROSC_TRIM_DIV_TH 0
#define ROSC_TRIM_FREQCTRL 16
/* ROSC_WRITE (0x18) */
#define ROSC_TRIM_PULSE 0

#define RTC_RST_MAGIC					0xb0075ce5
#define RTC_TIMEOUT_USEC 				1000000

#define RTC_NOT_COUNTING				0
#define RTC_COUNTING					1
#define RTC_READING						0
#define RTC_NOT_READING					1
#define RTC_WRITING						0
#define RTC_NOT_WRITING					1

#define SEC_MASK						GENMASK(5, 0)
#define MIN_MASK   						GENMASK(5, 0)
#define HOUR_MASK						GENMASK(4, 0)
#define DAY_MASK						GENMASK(14, 0)

#define ROSC_TRIM_DIV_TH_MASK GENMASK(7, 0)
#define ROSC_TRIM_FREQCTRL_MASK GENMASK(19, 16)
#define ROSC_TRIM_PULSE_MASK GENMASK(0, 0)

#define SYNC_TIME_SOURCE_AON_RTC 0
#define SYNC_TIME_SOURCE_NOT_AON_RTC 1

volatile void *aon_rtc_base = (volatile void *)AON_VA;

struct augentix_aon_rtc_time {
	u32 sec;
	u32 min;
	u32 hour;
	u32 day;
};

struct rtc_time_sync {
	struct rtc_device *rtc;
	unsigned char time_source;
	unsigned char has_checked;
} g_rtc_time_sync;

static inline void unpack_time(struct augentix_aon_rtc_time *time, u32 val)
{
	time->sec  = (val >> TIME_SEC_READ_OFFSET)  & SEC_MASK;
	time->min  = (val >> TIME_MIN_READ_OFFSET)  & MIN_MASK;
	time->hour = (val >> TIME_HOUR_READ_OFFSET) & HOUR_MASK;
	time->day  = (val >> TIME_DAY_READ_OFFSET)  & DAY_MASK;
}

static inline u32 pack_time(const struct augentix_aon_rtc_time *time)
{
	return	((time->sec  & SEC_MASK)  << TIME_SEC_WRITE_OFFSET)  |
			((time->min  & MIN_MASK)  << TIME_MIN_WRITE_OFFSET)  |
			((time->hour & HOUR_MASK) << TIME_HOUR_WRITE_OFFSET) |
			((time->day  & DAY_MASK)  << TIME_DAY_WRITE_OFFSET);
}

static u32 calculate_alarm_time(u32 current_packed_time, u32 seconds_to_add)
{
	struct augentix_aon_rtc_time time;
	u64 total_secs = 0;
	u32 new_packed_time, secs_of_day;

	unpack_time(&time, current_packed_time);

	total_secs += time.day * 86400ULL;
	total_secs += time.hour * 3600ULL;
	total_secs += time.min * 60ULL;
	total_secs += time.sec;

	total_secs += seconds_to_add;

	secs_of_day = do_div(total_secs, 86400);
	time.day = total_secs;
	time.hour = secs_of_day / 3600;
	secs_of_day %= 3600;
	time.min = secs_of_day / 60;
	time.sec = secs_of_day % 60;

	new_packed_time = pack_time(&time);
	return new_packed_time;
}

static void augentix_aon_rtc_alarm_irq_enable(bool enabled)
{
	u32 mask;

	/* Get current IRQ mask status */
	mask = readl(aon_rtc_base + AGTX_IRQ_MASK);

	/* Set IRQ mask */
	if (enabled)
		mask &= ~(1 << IRQ_MASK_ALARM_PMU_OFFSET);
	else
		mask |= (1 << IRQ_MASK_ALARM_PMU_OFFSET);
	writel(mask, aon_rtc_base + AGTX_IRQ_MASK);
}

void augentix_aon_rtc_set_alarm(int time_in_ms)
{
	bool pmu_alarm;
	u32 status, state, val;
	s32 timeout = RTC_TIMEOUT_USEC;

	/* Ensure IRQ status is not set */
	do {
		status = readl(aon_rtc_base + AGTX_IRQ_STATUS);
		pmu_alarm = !!(status & (1 << STATUS_MATCH_ALARM_PMU_OFFSET));
		if (pmu_alarm == true) {
			writel((1 << IRQ_CLEAR_ALARM_PMU_OFFSET), aon_rtc_base + AGTX_IRQ_CLEAR);
			udelay(200);
		}
	} while (pmu_alarm == true);

	/* Disable IRQ during alarm time setup */
	augentix_aon_rtc_alarm_irq_enable(false);

	/* Trigger read operation */
	writel((1 << READ_OFFSET), aon_rtc_base + AGTX_RTC_CTRL);
	/* Delay at least 5T (152us) */
	udelay(200);

	/* Wait for hardware to complete the read */
	state = (readl(aon_rtc_base + AGTX_RTC_STATE) >> READ_DONE_OFFSET) & 0x1;
	while (state == RTC_READING) {
		if (--timeout == 0) {
			pr_err("augentix-rtc: Timeout waiting for RTC READ_DONE\n");
			return;
		}
		udelay(200);
		state = (readl(aon_rtc_base + AGTX_RTC_STATE) >> READ_DONE_OFFSET) & 0x1;
	}

	val = readl(aon_rtc_base + AGTX_TIME_READ);
	val = calculate_alarm_time(val, time_in_ms / 1000);
	writel(val, aon_rtc_base + AGTX_ALARM_PMU);

	augentix_aon_rtc_alarm_irq_enable(true);
}
EXPORT_SYMBOL(augentix_aon_rtc_set_alarm);

void augentix_aon_rtc_read_time(struct timespec64 *ts)
{
	struct augentix_aon_rtc_time time;
	u64 total_secs = 0;
	u32 state;
	s32 timeout = RTC_TIMEOUT_USEC;

	/* Trigger read operation */
	writel((1 << READ_OFFSET), aon_rtc_base + AGTX_RTC_CTRL);
	/* Delay at least 5T (152us) */
	udelay(200);

	/* Wait for hardware to complete the read */
	state = (readl(aon_rtc_base + AGTX_RTC_STATE) >> READ_DONE_OFFSET) & 0x1;
	while (state == RTC_READING) {
		if (--timeout == 0) {
			pr_err("augentix-rtc: Timeout waiting for RTC READ_DONE\n");
			return;
		}
		udelay(200);
		state = (readl(aon_rtc_base + AGTX_RTC_STATE) >> READ_DONE_OFFSET) & 0x1;
	}

	unpack_time(&time, readl(aon_rtc_base + AGTX_TIME_READ));

	total_secs += time.day * 86400ULL;
	total_secs += time.hour * 3600ULL;
	total_secs += time.min * 60ULL;
	total_secs += time.sec;

	ts->tv_sec = total_secs;
	ts->tv_nsec = 0;
}
EXPORT_SYMBOL(augentix_aon_rtc_read_time);

void augentix_rtc_read_time(struct timespec64 *ts)
{
#if defined(CONFIG_RTC_DRV_AGTX)
	struct rtc_time tm;

	if (!g_rtc_time_sync.has_checked && !g_rtc_time_sync.rtc) {
		g_rtc_time_sync.rtc = rtc_class_open(CONFIG_RTC_HCTOSYS_DEVICE);
		if (!g_rtc_time_sync.rtc)
			g_rtc_time_sync.time_source = SYNC_TIME_SOURCE_AON_RTC;
		else
			g_rtc_time_sync.time_source = SYNC_TIME_SOURCE_NOT_AON_RTC;
		g_rtc_time_sync.has_checked = 1;
	}

	if (g_rtc_time_sync.rtc) {
		if (rtc_read_time(g_rtc_time_sync.rtc, &tm)) {
			pr_notice("Failed to read non-AON RTC time\n");
		}

		ts->tv_sec = rtc_tm_to_time64(&tm);
		ts->tv_nsec = 0;
	} else {
		augentix_aon_rtc_read_time(ts);
	}
#else
	augentix_aon_rtc_read_time(ts);
#endif
}
EXPORT_SYMBOL(augentix_rtc_read_time);

void augentix_aon_rtc_set_time(struct timespec64 *ts)
{
	struct augentix_aon_rtc_time time;
	u64 total_secs = ts->tv_sec;
	u32 secs_of_day, state;
	s32 timeout = RTC_TIMEOUT_USEC;

	secs_of_day = do_div(total_secs, 86400);
	time.day = total_secs;
	time.hour = secs_of_day / 3600;
	secs_of_day %= 3600;
	time.min = secs_of_day / 60;
	time.sec = secs_of_day % 60;

	/* Load time value to be written */
	writel(pack_time(&time), aon_rtc_base + AGTX_TIME_WRITE);

	/* Trigger write operation */
	writel((1 << WRITE_OFFSET), aon_rtc_base + AGTX_RTC_CTRL);
	/* At least wait 187us (6T) */
	udelay(200);

	/* Wait until write completion */
	state = (readl(aon_rtc_base + AGTX_RTC_STATE) >> WRITE_DONE_OFFSET) & 0x1;
	while (state == RTC_WRITING) {
		if (--timeout == 0) {
			pr_err("augentix-rtc: Timeout waiting for RTC WRITE_DONE\n");
			return;
		}
		udelay(200);
		state = (readl(aon_rtc_base + AGTX_RTC_STATE) >> WRITE_DONE_OFFSET) & 0x1;
	}
}
EXPORT_SYMBOL(augentix_aon_rtc_set_time);

void augentix_rtc_set_time(struct timespec64 *ts)
{
#if defined(CONFIG_RTC_DRV_AGTX)
	if (!g_rtc_time_sync.has_checked && !g_rtc_time_sync.rtc) {
		g_rtc_time_sync.rtc = rtc_class_open(CONFIG_RTC_HCTOSYS_DEVICE);
		if (!g_rtc_time_sync.rtc)
			g_rtc_time_sync.time_source = SYNC_TIME_SOURCE_AON_RTC;
		else
			g_rtc_time_sync.time_source = SYNC_TIME_SOURCE_NOT_AON_RTC;
		g_rtc_time_sync.has_checked = 1;
	}

	/* With rtc0 present, don't write time back (avoids AoV time drift);
	 * fall back to AON RTC only when rtc0 is absent. */
	if (!g_rtc_time_sync.rtc)
		augentix_aon_rtc_set_time(ts);
#else
	augentix_aon_rtc_set_time(ts);
#endif
}
EXPORT_SYMBOL(augentix_rtc_set_time);

static int __init augentix_aon_rtc_init(void)
{
	u32 rst_state, csr;
	int ret;
	struct device_node *node;

	/* Check if RTC has been reset */
	rst_state = readl(aon_rtc_base + AGTX_RTC_RST_STATE);
	if (rst_state == RTC_RST_MAGIC) {
		pr_info("augentix-rtc: RTC reset detected, reinitializing time\n");
		writel(0, aon_rtc_base + AGTX_RTC_RST_STATE);

		/* Set IRQ mask to 1 to prevent false positives when checking
		 * for active alarms during a read operation.
 		 */
		csr = (1 << IRQ_MASK_ALARM_CPU_OFFSET) | \
		      (1 << IRQ_MASK_ALARM_PMU_OFFSET);
		writel(csr, aon_rtc_base + AGTX_IRQ_MASK);
	}

	/* Check if RTC is counting */
	if (((readl(aon_rtc_base + AGTX_RTC_STATE) >> COUNTING_BUSY_OFFSET) & 0x1) != RTC_COUNTING) {
		writel((1 << RUN_STOP_OFFSET), aon_rtc_base + AGTX_RTC_CTRL);
		do {
			udelay(200);
		} while (((readl(aon_rtc_base + AGTX_RTC_STATE) >> COUNTING_BUSY_OFFSET) & 0x1) != RTC_COUNTING);
	}

	/* Set ROSC frequency and div to make it close to 32.768 KHz */
	writel(((0x4C << ROSC_TRIM_DIV_TH) & ROSC_TRIM_DIV_TH_MASK) |
	               ((0x8 << ROSC_TRIM_FREQCTRL) & ROSC_TRIM_FREQCTRL_MASK),
	       aon_rtc_base + AGTX_ROSC_BASE_OFFSET + AGTX_ROSC_TRIM);
	writel((0x1 << ROSC_TRIM_PULSE) & ROSC_TRIM_PULSE_MASK, aon_rtc_base + AGTX_ROSC_BASE_OFFSET + AGTX_ROSC_WRITE);

	memset(&g_rtc_time_sync, 0, sizeof(g_rtc_time_sync));

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 19, 0)
	register_persistent_clock(augentix_aon_rtc_read_time);
#else
	register_persistent_clock(NULL, augentix_aon_rtc_read_time);
#endif
	return 0;
}
device_initcall(augentix_aon_rtc_init)
