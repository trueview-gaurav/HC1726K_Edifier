// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2026 Augentix Inc.
 *
 * Carve-out addresses live in globals, not in gd members.
 */

#define AGTX_GPIO_HELPER_IMPL

#include <config.h>
#include <init.h>
#include <asm/global_data.h>
#include <asm/gpio.h>
#include <linux/errno.h>
#include <mach/early_video.h>
#include <mach/fastboot_common.h>

DECLARE_GLOBAL_DATA_PTR;

/* Written before relocation; BSS is cleared after it */
unsigned long agtx_fb_base __section(".data");
unsigned long agtx_audio_base __section(".data");

/* Pre-reserve hook; reserve_arch runs too late, U-Boot would relocate
 * into the carve and the buffer memsets then wipe the running code.
 */
int arch_setup_dest_addr(void)
{
	gd->relocaddr = agtx_video_setmem(gd->relocaddr);
	agtx_fb_base = gd->relocaddr;
#if IS_ENABLED(CONFIG_EARLYAUDIO)
	gd->relocaddr -= EARLY_AUDIO_BUF_KB << 10;
	agtx_audio_base = gd->relocaddr;
#endif
	return 0;
}

/* DM gpio refuses an unrequested line; the v2016.03 callers never request */
static int agtx_gpio_claim(unsigned int gpio)
{
	int ret = gpio_request(gpio, "agtx_fastboot");

	if (ret && ret != -EBUSY)
		return ret;
	return 0;
}

int agtx_gpio_output(unsigned int gpio, int value)
{
	int ret = agtx_gpio_claim(gpio);

	if (ret)
		return ret;
	return gpio_direction_output(gpio, value);
}

int agtx_gpio_input(unsigned int gpio)
{
	int ret = agtx_gpio_claim(gpio);

	if (ret)
		return ret;
	return gpio_direction_input(gpio);
}
