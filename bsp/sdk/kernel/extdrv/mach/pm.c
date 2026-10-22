/*
 * Copyright 2021 AUGENTIX
 * Dream Yeh <dream.yeh@augentix.com>
 *
 * augentix common power management (suspend to ram) support.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/suspend.h>
#include <linux/syscore_ops.h>
#include <linux/time64.h>
#include <linux/watchdog.h>
#include <linux/version.h>

#include <asm/cacheflush.h>
#include <asm/fncpy.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <asm/suspend.h>
#ifdef CONFIG_ARM_PSCI
#include <linux/arm-smccc.h>   
#endif
#define AGTX_SMC_AOV_SUSPEND 0x8200000D 


#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
#include "address.h"
#include "pm_csr_bank.h"
#endif

#define DRAM_SAFE_OFFS 0x20000000 /* 256MB DRAM capacity margin for vmalloc offset */
#define VA_OFFS (0xC0000000 - 0x80000000) + (DRAM_SAFE_OFFS)
#define TO_VA(pa) (pa + VA_OFFS)

#define IO_AIOC_PA (0x80001000)
#define AON_WDT_PA (0x80550000)
#define AMC_PA (0x80530000)

//AON Register=================================
#define HC1703_1723_1753_1783S_GSTATUS2 0x8053000C //Status  Bit[18]
#define HC1703_1723_1753_1783S_GSTATUS2_OFFRESET 0x00040000
#define HC1703_1723_1753_1783S_GSTATUS3 0x80550020 //-> do_resume
#define HC1703_1723_1753_1783S_GSTATUS4_lo 0x80530098 //-> sp
#define HC1703_1723_1753_1783S_GSTATUS4_hi 0x8053009c //-> sp

/* for get_cpu_time() use */
#ifdef CONFIG_OSAKA
#define CPU_CLK_PLL 891000
#define AUGENTIX_CK_GEN 0x82000000
#define CK_RESV0_OFFSET 0xE8
#elif defined(CONFIG_SAPPORO)
#if defined(CONFIG_CPU_LOW_SPEED)
#define CPU_CLK_PLL 450000
#else
#define CPU_CLK_PLL 891000
#endif // CPU_450M
#define AUGENTIX_CK_GEN 0x80000000
#define CK_RESV0_OFFSET 0xE8
#define AUGENTIX_SRAM 0xFFE00000
#define AUGENTIX_IO_PD_CONTROL 0x80001000
#else
#define CPU_CLK_PLL 1008000
#define AUGENTIX_CK_GEN 0x80000000
#define CK_RESV0_OFFSET 0x9C
#define CK_RESV2_OFFSET 0xA4
#endif

//#define PM_DEBUG

static volatile void __iomem *augentix_ck_gen_base;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
static volatile CsrBankCk *agtx_ck;
static volatile CsrBankCk agtx_ck_bank;
static volatile void __iomem *augentix_io_pd_control_base;
#endif

enum wakeup_source_type { WAKE_UP_SOURCE_RTC, WAKE_UP_SOURCE_EIRQ, WAKE_UP_SOURCE_MAX };

#define MAX_ARGS 4
#define MAX_ARG_SIZE 10
#define MAX_BUF_SIZE (MAX_ARGS * MAX_ARG_SIZE)

#define WAKE_UP_SOURCE_RTC_BIT BIT(WAKE_UP_SOURCE_RTC)
#define WAKE_UP_SOURCE_EIRQ_BIT BIT(WAKE_UP_SOURCE_EIRQ)

#ifdef PM_DEBUG
static int g_pm_dbg_level = 0;

#define PM_DBG_WARN(fmt, args...)            \
	do {                                 \
		if (g_pm_dbg_level >= 1)     \
			pr_err(fmt, ##args); \
	} while (0)
#define PM_DBG_INFO(fmt, args...)            \
	do {                                 \
		if (g_pm_dbg_level >= 2)     \
			pr_err(fmt, ##args); \
	} while (0)
#else
#define PM_DBG_WARN(fmt, args...) \
	do {                      \
	} while (0)
#define PM_DBG_INFO(fmt, args...) \
	do {                      \
	} while (0)
#endif

struct aov_ioctrl {
	unsigned int num;
	unsigned int mode;
	unsigned int act_lvl;
} g_aov_io;


#define EIRQ4_OFFSET 0xC8
struct eirq_ctrl {
	char trig[5];
	unsigned int backup;
	unsigned int num;
	bool request_successful;
};

struct aov_wake {
	unsigned int source_bitmap;
	unsigned int video_check_mode[WAKE_UP_SOURCE_MAX];
	unsigned int period;
	struct eirq_ctrl eirq;
} g_aov_wake;
// struct aov_info aov_eirq[5];

extern char __sram_code_start[];
extern char __sram_code_end[];

extern int augentix_cpu_suspend_asm(unsigned long);

static struct timespec64 ts;

#define SRAM_CODE_OFFSET 0x800
#define SRAM_STACK_SIZE (4 * 1024)

typedef int (*AovCb)(void);
AovCb video_get_one_frame;

#define any_allowed(mask, allow) (((mask) & (allow)) != (allow))

extern void augentix_suspend_disable_wdt(void);
extern void augentix_aon_rtc_set_alarm(int);
extern void augentix_aon_rtc_set_time(struct timespec64 *);
extern void augentix_aon_rtc_read_time(struct timespec64 *);
extern void augentix_rtc_read_time(struct timespec64 *);
extern void augentix_rtc_set_time(struct timespec64 *);
extern int augentix_pwm_aov_suspend_prepare(void);
extern int augentix_pwm_aov_resume_restore(void);

#define DEBUG_LOG 0

static void augentix_aov_pwm_before_sleep(void)
{
	int ret;

	ret = augentix_pwm_aov_suspend_prepare();
#if DEBUG_LOG
	if (ret)
		pr_notice("aov pwm suspend prepare failed: %d\n", ret);
#endif
}

static void augentix_aov_pwm_after_wakeup(void)
{
	int ret;

	ret = augentix_pwm_aov_resume_restore();
#if DEBUG_LOG
	if (ret)
		pr_notice("aov pwm resume restore failed: %d\n", ret);
#endif
}


#if defined(CONFIG_PM_SLEEP)

static char *wake_ops[] = { "rtc", "eirq", "clear" };
static char *wake_clear[] = { "rtc", "eirq", "all" };
//static char *eirq_list[] = { "high", "low", "rise", "fall" };

static int (*augentix_cpu_suspend_asm_ptr)(unsigned long, unsigned long) = NULL;
static void *sram_stack_top_ptr = NULL;

#if defined(CONFIG_SAPPORO)
enum { CAS_OFF = 0x0, DDR_OFF = 0x1000, CPU_OFF = 0x2000, SEN_OFF = 0x5000, ADO_OFF = 0x7000 };
static void __iomem *augentix_sram_base;

static int is_eirq_wakeup(struct aov_wake wake)
{
	uint32_t temp_pinctrl;

	if (wake.source_bitmap & WAKE_UP_SOURCE_EIRQ_BIT) {
		temp_pinctrl = readl(augentix_io_pd_control_base + EIRQ4_OFFSET);
		writel(0, augentix_io_pd_control_base + EIRQ4_OFFSET);
		if (gpio_get_value(0)) {
			writel(temp_pinctrl, augentix_io_pd_control_base + EIRQ4_OFFSET);
			return 1;
		}
		writel(temp_pinctrl, augentix_io_pd_control_base + EIRQ4_OFFSET);
	}

	return 0;
}

void augentix_pm_save_clock(void)
{
	memcpy((void *)&agtx_ck_bank, (void *)agtx_ck, sizeof(CsrBankCk));
}

void augentix_pm_gate_clock(void)
{
	agtx_ck->cg_sys = 0;
	agtx_ck->cg_timer = 0;
	agtx_ck->cg_trng = 0;
	agtx_ck->cg_i2cm = 0;
	agtx_ck->cg_spi = 0;
	agtx_ck->cg_pwm = 0;
#if defined(PM_DEBUG)
	agtx_ck->cg_uart = 0;
#endif
	agtx_ck->cg_qspi = 0;
	agtx_ck->cg_sdc = 0;
	agtx_ck->cg_emac = 0;
	agtx_ck->cg_usb = 0;
	agtx_ck->cg_sensor = 0;
	agtx_ck->cg_mipi_chop = 0;
	agtx_ck->cg_is = 0;
	agtx_ck->cg_isp_vp = 0;
	agtx_ck->cg_enc = 0;
	agtx_ck->cg_audio = 0;
	agtx_ck->cg_fm = 0;
	//	agtx_ck->axi_dramc_src_sel = 0;
	//	agtx_ck->cken_axi_rom = 0;
	//	agtx_ck->cken_axi_dramc = 0;
	//	agtx_ck->cg_dram = 0;
}

void augentix_pm_restore_clock(void)
{
	memcpy((void *)agtx_ck, (void *)&agtx_ck_bank, sizeof(CsrBankCk));
}

int augentix_cpu_suspend(unsigned long input)
{
	do {
#if defined(CONFIG_PWM_AUGENTIX_V2)
		augentix_aov_pwm_before_sleep();
#endif
		// deactivate GPIO
		if (g_aov_io.mode)
			gpio_set_value(g_aov_io.num, g_aov_io.act_lvl ? 0 : 1);
		if (g_aov_wake.source_bitmap & WAKE_UP_SOURCE_RTC_BIT)
			augentix_aon_rtc_set_alarm(g_aov_wake.period);

		augentix_pm_save_clock();
		augentix_pm_gate_clock();
#ifdef CONFIG_ARM_PSCI
		{
			struct arm_smccc_res res;
			arm_smccc_smc(AGTX_SMC_AOV_SUSPEND, 0, 0, 0, 0, 0, 0, 0, &res);
		}
#else
		augentix_cpu_suspend_asm_ptr((unsigned long)sram_stack_top_ptr, 0x87);
#endif
		augentix_pm_restore_clock();

		// local_irq_enable();
		// local_irq_disable();

		// activate GPIO
		if (g_aov_io.mode)
			gpio_set_value(g_aov_io.num, g_aov_io.act_lvl ? 1 : 0);

#if defined(CONFIG_PWM_AUGENTIX_V2)
		augentix_aov_pwm_after_wakeup();
#endif
		if (is_eirq_wakeup(g_aov_wake)) {
			if (!g_aov_wake.video_check_mode[WAKE_UP_SOURCE_EIRQ]) {
				pr_notice("EIRQ%u: Direct wakeup\n", g_aov_wake.eirq.num);
				break;
			}
			pr_notice("EIRQ%u: Wakeup triggered, entering AoV flow\n", g_aov_wake.eirq.num);
		} else { /* wake up by rtc */
			if (!g_aov_wake.video_check_mode[WAKE_UP_SOURCE_RTC]) {
				pr_notice("RTC: Direct wakeup\n");
				break;
			}
		}

	} while (video_get_one_frame && video_get_one_frame() == 0);
	return 0;
}

#endif /* CONFIG_SAPPORO */

/* augentix_pm_enter
 *
 * central control for sleep/resume process
*/

static int augentix_pm_enter(suspend_state_t state)
{
	static void __iomem *audioldo_va = NULL;
	uint32_t rdata;

	/* One-shot: install suspend code into SRAM on first entry.
	 * Deferred from init to preserve SPL efuse ops ABI until suspend. */
#ifndef CONFIG_ARM_PSCI
	if (!augentix_cpu_suspend_asm_ptr) {
		size_t sram_code_size = __sram_code_end - __sram_code_start;
		unsigned long asm_offset;

		memcpy(augentix_sram_base + SRAM_CODE_OFFSET, __sram_code_start, sram_code_size);
		asm_offset = (unsigned long)&augentix_cpu_suspend_asm - (unsigned long)__sram_code_start;
		augentix_cpu_suspend_asm_ptr = (augentix_sram_base + SRAM_CODE_OFFSET) + asm_offset;
		sram_stack_top_ptr = (augentix_sram_base + SRAM_CODE_OFFSET) + sram_code_size + SRAM_STACK_SIZE;
		pr_info("augentix_pm: SRAM suspend code installed\n");
	}
#endif

	/* Disable the LDO of AUDIO and ADC */
	audioldo_va = ioremap(0x80250000UL, 4UL);
	rdata = readl(audioldo_va);
	writel(0x00000000, audioldo_va);

	ktime_get_real_ts64(&ts);
	augentix_rtc_set_time(&ts);

	PM_DBG_INFO("pm_enter, ts.sec=%u\r\n", ts.tv_sec);

	/* Deactivate GPIO */
	if (g_aov_io.num)
		gpio_set_value(g_aov_io.num, g_aov_io.act_lvl ? 0 : 1);

	/* Acquire EIRQ for waking up */
	if (g_aov_wake.source_bitmap & WAKE_UP_SOURCE_EIRQ_BIT) {
		if (gpio_request(0, "resume_eirq4")) {
			pr_notice("Failed to acquire GPIO 0 (EIRQ4) as wake-up source\n");
		} else {
			gpio_direction_input(0);
			g_aov_wake.eirq.backup = readl(augentix_io_pd_control_base + EIRQ4_OFFSET);
			writel(0x4, augentix_io_pd_control_base + EIRQ4_OFFSET);
			g_aov_wake.eirq.request_successful = true;
		}
	}

	/* flush cache back to ram */
	flush_cache_all();

	/* this will also act as our return point from when
	 * we resume as it saves its own register state and restores it
	 * during the resume.  */
	cpu_suspend(0, augentix_cpu_suspend);

	/* read rtc time then set kernel time */
	augentix_rtc_read_time(&ts);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 19, 0)
	do_settimeofday64(&ts);
#else
	{
		struct timespec ts_tmp;
		ts_tmp = timespec64_to_timespec(ts);
		do_settimeofday(&ts_tmp);
	}
#endif

	/* Restore GPIO setting after resuming */
	if (g_aov_wake.eirq.request_successful) {
		writel(g_aov_wake.eirq.backup, augentix_io_pd_control_base + EIRQ4_OFFSET);
		gpio_free(0);
		g_aov_wake.eirq.request_successful = false;
	}

	/* Activate GPIO */
	if (g_aov_io.num)
		gpio_set_value(g_aov_io.num, g_aov_io.act_lvl ? 1 : 0);

	/* Enable the LDO of AUDIO and ADC */
	writel(rdata, audioldo_va);
	iounmap(audioldo_va);

	PM_DBG_INFO("pm leave, ts.sec=%u\r\n", ts.tv_sec);

	return 0;
}

static const struct platform_suspend_ops augentix_pm_ops = {
	.enter = augentix_pm_enter,
	.valid = suspend_valid_only_mem,
};

/* augentix_pm_init
 *
 * Attach the power management functions. This should be called
 * from the board specific initialisation if the board supports
 * it.
*/

static int __init augentix_pm_init(void)
{
	augentix_sram_base = __arm_ioremap_exec(AUGENTIX_SRAM, 0x8000, false);
	if (!augentix_sram_base) {
		pr_err("Failed to ioremap for AUGENTIX_SRAM\n");
		return -ENOMEM;
	}

	/* SRAM code installation deferred to first suspend entry,
	 * preserving SPL efuse ops ABI until then. */
	suspend_set_ops(&augentix_pm_ops);
	return 0;
}
#if defined(CONFIG_SAPPORO)
late_initcall(augentix_pm_init);
#endif

static ssize_t rosc_div_th_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	pr_notice("%u\n", readl((volatile void *)AON_VA + 0x400 + 0x014) & 0xff);
	return 0;
}

static ssize_t rosc_div_th_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
	int old_value = readl((volatile void *)AON_VA + 0x400 + 0x014);
	int value = simple_strtol(buf, NULL, 0);
	writel((old_value & (0xFFFFFF00)) | value, (volatile void *)AON_VA + 0x400 + 0x014);
	writel(0x1, (volatile void *)AON_VA + 0x400 + 0x018);
	return size;
}

static DEVICE_ATTR_RW(rosc_div_th);

static ssize_t rosc_freqctrl_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	pr_notice("%u\n", (readl((volatile void *)AON_VA + 0x400 + 0x014) >> 16) & 0xf);
	return 0;
}

static ssize_t rosc_freqctrl_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
	int old_value = readl((volatile void *)AON_VA + 0x400 + 0x014);
	int value = simple_strtol(buf, NULL, 0);
	writel((old_value & (0xFFF0FFFF)) | (value << 16), (volatile void *)AON_VA + 0x400 + 0x014);
	writel(0x1, (volatile void *)AON_VA + 0x400 + 0x018);
	return size;
}

static DEVICE_ATTR_RW(rosc_freqctrl);

static struct attribute *rosc_trim_attrs[] = {
	&dev_attr_rosc_div_th.attr,
	&dev_attr_rosc_freqctrl.attr,
	NULL,
};

static struct attribute_group rosc_trim_attr_group = {
	.attrs = rosc_trim_attrs,
};

static ssize_t io_control_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	pr_notice("%d,%d,%d\n", g_aov_io.num, g_aov_io.mode, g_aov_io.act_lvl);
	return 0;
}

static ssize_t io_control_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
	unsigned int cnt;
	char *token, *s;
	char buffer[MAX_BUF_SIZE] = { 0 };
	char args[MAX_ARGS][MAX_ARG_SIZE] = { 0 };

	if (size < 5 || size > MAX_BUF_SIZE) {
		pr_notice("Input size is incorrect\n");
		return size;
	}

	strncpy(buffer, buf, MAX_BUF_SIZE);
	buffer[strcspn(buffer, "\n")] = '\0';
	s = &buffer[0];
	for (cnt = 0; cnt < MAX_ARGS; cnt++) {
		token = strsep(&s, ",");
		if (token == NULL)
			break;
		strncpy(&args[cnt][0], token, MAX_ARG_SIZE - 1);
	}

	if (!strcmp(&args[0][0], "clear")) {
		if (cnt != 2) {
			pr_notice("clear format is incorrect\n");
			return size;
		}
		gpio_set_value(g_aov_io.num, g_aov_io.act_lvl ? 0 : 1);
		gpio_free(g_aov_io.num);
		memset(&g_aov_io, 0, sizeof(g_aov_io));
	} else {
		if (cnt != 3) {
			pr_notice("io control format is incorrect\n");
			return size;
		}
		if (g_aov_io.num) {
			gpio_set_value(g_aov_io.num, g_aov_io.act_lvl ? 0 : 1);
			gpio_free(g_aov_io.num);
		}
		g_aov_io.num = simple_strtol(&args[0][0], NULL, 10);
		g_aov_io.mode = simple_strtol(&args[1][0], NULL, 10);
		g_aov_io.act_lvl = simple_strtol(&args[2][0], NULL, 10);
		gpio_request(g_aov_io.num, "suspend_gpio");
		gpio_direction_output(g_aov_io.num, g_aov_io.act_lvl ? 1 : 0);
	}

	return size;
}

static DEVICE_ATTR_RW(io_control);

static struct attribute *io_control_attrs[] = {
	&dev_attr_io_control.attr,
	NULL,
};

static struct attribute_group io_control_attr_group = {
	.attrs = io_control_attrs,
};

static ssize_t wake_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	if (g_aov_wake.source_bitmap == 0) {
		pr_notice("No wake source set\n");
		return 0;
	}

	if (g_aov_wake.source_bitmap & WAKE_UP_SOURCE_RTC_BIT)
		pr_notice("rtc,%d,%d\n", g_aov_wake.video_check_mode[WAKE_UP_SOURCE_RTC], g_aov_wake.period);
	if (g_aov_wake.source_bitmap & WAKE_UP_SOURCE_EIRQ_BIT)
		pr_notice("eirq,%d,%d,%s\n", g_aov_wake.video_check_mode[WAKE_UP_SOURCE_EIRQ], g_aov_wake.eirq.num,
		          g_aov_wake.eirq.trig);

	return 0;
}

static ssize_t wake_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
	unsigned int cnt, idx;
	unsigned int match = 0;
	char *token, *s;
	char buffer[MAX_BUF_SIZE] = { 0 };
	char args[MAX_ARGS][MAX_ARG_SIZE] = { 0 };

	if (size < 7 || size > MAX_BUF_SIZE) {
		pr_notice("Input size is incorrect\n");
		return size;
	}

	strncpy(buffer, buf, MAX_BUF_SIZE);
	buffer[strcspn(buffer, "\n")] = '\0';
	s = &buffer[0];
	for (cnt = 0; cnt < MAX_ARGS; cnt++) {
		token = strsep(&s, ",");
		if (token == NULL)
			break;
		strncpy(&args[cnt][0], token, MAX_ARG_SIZE - 1);
	}

	for (idx = 0; idx < sizeof(wake_ops)/sizeof(char *); idx++) {
		if (!strcmp(&args[0][0], wake_ops[idx])) {
			match = 1;
			break;
		}
	}
	if (match) {
		switch (idx) {
		case WAKE_UP_SOURCE_RTC:
			if (cnt != 3) {
				pr_notice("rtc format is incorrect\n");
				return size;
			}
			g_aov_wake.source_bitmap |= WAKE_UP_SOURCE_RTC_BIT;
			g_aov_wake.video_check_mode[WAKE_UP_SOURCE_RTC] = simple_strtol(&args[1][0], NULL, 10);
			g_aov_wake.period = simple_strtol(&args[2][0], NULL, 10);
			if (g_aov_wake.period % 1000)
				pr_notice("The RTC precision is in seconds, milliseconds will be truncated\n");
			break;
		case WAKE_UP_SOURCE_EIRQ:
#if defined(CONFIG_SAPPORO)
			if (cnt != 4) {
				pr_notice("eirq format is incorrect\n");
				return size;
			}
			if (strcmp(&args[2][0], "4")) {
				pr_notice("only eirq4 is supported for waking up AoV\n");
				return size;
			}
			if (strcmp(&args[3][0], "rise")) {
				pr_notice("eirq only support rising edge\n");
				return size;
			}
#endif
			g_aov_wake.source_bitmap |= WAKE_UP_SOURCE_EIRQ_BIT;
			g_aov_wake.video_check_mode[WAKE_UP_SOURCE_EIRQ] = simple_strtol(&args[1][0], NULL, 10);
			g_aov_wake.eirq.num = simple_strtol(&args[2][0], NULL, 10);
			strlcpy(g_aov_wake.eirq.trig, &args[3][0], sizeof(g_aov_wake.eirq.trig));
			break;
		/* Handle global or specific source clear requests */
		case WAKE_UP_SOURCE_MAX:
			if (cnt < 2 || cnt > 3) {
				pr_notice("clear format is incorrect\n");
				return size;
			}
			match = 0;
			for (idx = 0; idx < sizeof(wake_clear) / sizeof(char *); idx++) {
				if (!strcmp(&args[1][0], wake_clear[idx])) {
					match = 1;
					if (idx == WAKE_UP_SOURCE_MAX)
						memset(&g_aov_wake, 0, sizeof(g_aov_wake));
					else
						g_aov_wake.source_bitmap &= ~(1 << idx);

					if (idx == WAKE_UP_SOURCE_EIRQ)
						memset(&g_aov_wake.eirq, 0, sizeof(g_aov_wake.eirq));
					break;
				}
			}
			if (!match)
				pr_notice("clear %s is not supported\n", &args[1][0]);
			break;
		}
	} else {
		pr_notice("wake source %s is not supported\n", &args[0][0]);
	}

	return size;
}

static DEVICE_ATTR_RW(wake);

static struct attribute *wake_attrs[] = {
	&dev_attr_wake.attr,
	NULL,
};

static struct attribute_group wake_attr_group = {
	.attrs = wake_attrs,
};

#ifdef PM_DEBUG
static ssize_t pm_debug_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	pr_err("debug level : %u\n", g_pm_dbg_level);

	return 0;
}

static ssize_t pm_debug_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
	unsigned int cnt;
	char *token, *s;
	char buffer[MAX_BUF_SIZE] = { 0 };
	char args[MAX_ARGS][MAX_ARG_SIZE] = { 0 };

	if (size < 5 || size > MAX_BUF_SIZE) {
		pr_notice("Input size is incorrect\n");
		return size;
	}

	strncpy(buffer, buf, MAX_BUF_SIZE);
	buffer[strcspn(buffer, "\n")] = '\0';
	s = &buffer[0];
	for (cnt = 0; cnt < MAX_ARGS; cnt++) {
		token = strsep(&s, ",");
		if (token == NULL)
			break;
		strncpy(&args[cnt][0], token, MAX_ARG_SIZE - 1);
	}

	if (!strcmp(&args[0][0], "dbl")) {
		g_pm_dbg_level = simple_strtol(&args[1][0], NULL, 10);
	}

	return size;
}

static DEVICE_ATTR_RW(pm_debug);

static struct attribute *pm_debug_attrs[] = {
	&dev_attr_pm_debug.attr,
	NULL,
};

static struct attribute_group pm_debug_attr_group = {
	.attrs = pm_debug_attrs,
};
#endif // #ifdef PM_DEBUG

#endif /* CONFIG_PM_SLEEP */

uint32_t get_cpu_time(void)
{
	uint32_t cvall, cvalh;
	uint32_t val;
	uint32_t ret;

	asm volatile("mrrc p15, 0, %0, %1, c14" : "=r"(cvall), "=r"(cvalh));
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
	val = agtx_ck->reserved0;
#else
	val = readl(augentix_ck_gen_base + CK_RESV0_OFFSET) + (readl(augentix_ck_gen_base + CK_RESV2_OFFSET) << 16);
#endif

	ret = (cvall / CPU_CLK_PLL) + val;

	return ret; // unit: ms
}
EXPORT_SYMBOL(get_cpu_time);

static ssize_t cpu_time_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%5u", get_cpu_time());
}
static DEVICE_ATTR_RO(cpu_time);

static struct attribute *cpu_time_attrs[] = {
	&dev_attr_cpu_time.attr,
	NULL,
};

static struct attribute_group cpu_time_attr_group = {
	.attrs = cpu_time_attrs,
};

static const struct attribute_group *core_attr_groups[] = {
#if defined(CONFIG_PM_SLEEP)
	&wake_attr_group, &io_control_attr_group, &rosc_trim_attr_group,
#ifdef PM_DEBUG
	&pm_debug_attr_group,
#endif
#endif
	&cpu_time_attr_group,  NULL,
};

struct bus_type augentix_subsys = {
	.name = "augentix-core",
	.dev_name = "augentix-core",
};

static int __init augentix_core_init(void)
{
	memset(&g_aov_wake, 0, sizeof(g_aov_wake));
	memset(&g_aov_io, 0, sizeof(g_aov_io));
	augentix_ck_gen_base = ioremap(AUGENTIX_CK_GEN, 0x100);
	if (!augentix_ck_gen_base) {
		pr_err("Failed to ioremap for AUGENTIX_CK_GEN\n");
	}
#if defined(CONFIG_SAPPORO)
	augentix_io_pd_control_base = ioremap(AUGENTIX_IO_PD_CONTROL, 0x400);
	agtx_ck = (volatile CsrBankCk *)augentix_ck_gen_base;
#endif
	return subsys_system_register(&augentix_subsys, core_attr_groups);
}
core_initcall(augentix_core_init);

void register_aov_cb(AovCb func)
{
	video_get_one_frame = func;
}
EXPORT_SYMBOL(register_aov_cb);
