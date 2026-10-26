/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2026 Augentix Inc.
 *
 * Compat for the SDK-generated sensor adaption files, v2026.07 tree.
 */

#ifndef __AGTX_SENSOR_COMPAT_COMMON_H
#define __AGTX_SENSOR_COMPAT_COMMON_H
#include <config.h>
#include <env.h>
#include <stdio.h>
#include <vsprintf.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/string.h>
#include <asm/io.h>
#include <linux/errno.h>

#define getenv env_get
#define setenv env_set
#endif
