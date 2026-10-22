/*
 * (C) Copyright 2024
 * Kevin Zhu, Augentix Software Engineering, Kevin.Zhu@augentix.com.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <environment.h>

#ifdef CONFIG_EARLYVIDEO
extern void sensor_set_env(void);
#endif

/**
 * This callback function is specially designed for releasing IR cut GPIOs
 */
static int on_bootargs(const char *name, const char *value, enum env_op op, int flags)
{
#ifdef CONFIG_EARLYVIDEO
	board_early_video_wait_finish();
	sensor_set_env();
#endif

	switch (op) {
#ifdef CONFIG_EARLYVIDEO
	case env_op_create:
		ir_cut_control_idle();
		break;
#endif
	default:
		break;
	}

	return 0;
}
U_BOOT_ENV_CALLBACK(bootargs_h, on_bootargs);
