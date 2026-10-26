/*
 * (C) Copyright 2017-2018  Augentix Inc.
 * ShihChieh Lin, Augentix Inc., <shihchieh.lin@augentix.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <bootm.h>
#include <config.h>
#include <stdio.h>
#include <vsprintf.h>
#include <env.h>
#include <init.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <mach/audio.h>
#include <mach/early_video.h>
#include <mach/fastboot_common.h>
#include <mach/uboot_gic.h>
#ifdef CONFIG_EFUSE_FSM_AUTOBURN
#include <linux/string.h>
#include <efuse_burn_fsm.h>
#endif

DECLARE_GLOBAL_DATA_PTR;

/* ------------------------------------------------------------------------- */
/*
 * Miscelaneous platform dependent initialisations
 */

int board_early_init_f(void)
{
	return 0;
}

int board_init(void)
{
	/* adress of boot parameters */
	gd->bd->bi_boot_params = CFG_SYS_SDRAM_BASE + 0x100;
	agtx_gic_init();
#if IS_ENABLED(CONFIG_AUGENTIX_FASTBOOT) && \
	IS_ENABLED(CONFIG_AUGENTIX_LOCK_PARAM_TO_SPEED_UP)
#if IS_ENABLED(CONFIG_EARLYAUDIO)
	audio_init();
	if (EARLY_AUDIO_BEFORE_VIDEO)
		earlyaudio_init();
#endif
	board_early_video_init();
#if IS_ENABLED(CONFIG_EARLYAUDIO)
	if (!EARLY_AUDIO_BEFORE_VIDEO)
		earlyaudio_init();
#endif
#endif
	return 0;
}

int dram_init(void)
{
	gd->ram_size = get_ram_size((void *)CFG_SYS_SDRAM_BASE, CFG_SYS_SDRAM_SIZE);
	return 0;
}

/* The weak version runs before setup_ram_config() takes MEM_TOP_HIDE off ram_size. */
int dram_init_banksize(void)
{
	gd->dram[0].start = gd->ram_base;
	gd->dram[0].size = gd->ram_size;
#if CONFIG_VAL(SYS_MEM_TOP_HIDE)
	gd->dram[0].size -= CONFIG_SYS_MEM_TOP_HIDE;
#endif
	return 0;
}

#ifdef CONFIG_EFUSE_FSM_AUTOBURN
int efuse_burn_init(void)
{
	const char *factory_mode = env_get("factory_mode");

	if (!factory_mode) {
		printf("factory_mode not found, auto-set to 1\n");
		env_set("factory_mode", "1");
		env_save();
		factory_mode = "1";
	}

	if (strcmp(factory_mode, "1") == 0) {
		efuse_fsm_context_t *ctx = eb_fsm_get_context();
		eb_fsm_init(ctx);

		if (eb_sdc_load_data() == 0) {
			int ret = eb_fsm_start();
			if (ret != 0) {
				printf("eFuse FSM Failed (ret=%d)\n", ret);
			}
		}
	}

	return 0;
}
#endif

#if CONFIG_IS_ENABLED(BOARD_LATE_INIT)
int board_late_init(void)
{
#if IS_ENABLED(CONFIG_AUGENTIX_UARTBOOT_RANDOM_ETHADDR)
	volatile unsigned int *boot = (volatile unsigned int *)0x8001000C; /* This should be removed in the future */

	/* This should be removed in the future */
	if (((*boot >> 2) & 0x3) == 0x1)
		env_set("ethaddr", NULL);
#endif

#if IS_ENABLED(CONFIG_AUGENTIX_FASTBOOT) && \
	!IS_ENABLED(CONFIG_AUGENTIX_LOCK_PARAM_TO_SPEED_UP)
#if IS_ENABLED(CONFIG_EARLYAUDIO)
	audio_init();
	if (EARLY_AUDIO_BEFORE_VIDEO)
		earlyaudio_init();
#endif
	board_early_video_init();
#if IS_ENABLED(CONFIG_EARLYAUDIO)
	if (!EARLY_AUDIO_BEFORE_VIDEO)
		earlyaudio_init();
#endif
#endif

#if IS_ENABLED(CONFIG_AUGENTIX_FASTBOOT)
	agtx_video_set_env();
#endif
#if IS_ENABLED(CONFIG_EARLYAUDIO)
	earlyaudio_set_env();
#elif defined(CONFIG_AUGENTIX_SOC_OSAKA)
#else
	audio_init();
#endif
#ifdef CONFIG_EFUSE_FSM_AUTOBURN
	efuse_burn_init();
#endif
	return 0;
}
#endif
