/*
 * (C) Copyright 2024
 * Kevin Zhu, Augentix Software Engineering, Kevin.Zhu@augentix.com.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <env.h>
#include <env_callback.h>
#include <mach/early_video.h>

/**
 * This callback function is specially designed for releasing IR cut GPIOs
 */
static int on_bootargs(const char *name, const char *value, enum env_op op, int flags)
{
	board_early_video_wait_finish();
	sensor_set_env();

	switch (op) {
	case env_op_create:
		ir_cut_control_idle();
		break;
	default:
		break;
	}

	return 0;
}
U_BOOT_ENV_CALLBACK(bootargs_h, on_bootargs);
