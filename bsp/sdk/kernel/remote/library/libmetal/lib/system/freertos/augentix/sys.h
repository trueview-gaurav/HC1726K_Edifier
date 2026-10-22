/*
 * Copyright (c) 2018, Linaro Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	freertos/template/sys.h
 * @brief	freertos template system primitives for libmetal.
 */

#ifndef __METAL_FREERTOS_SYS__H__
#error "Include metal/sys.h instead of metal/freertos/@PROJECT_MACHINE@/sys.h"
#endif

#ifndef __METAL_FREERTOS_TEMPLATE_SYS__H__
#define __METAL_FREERTOS_TEMPLATE_SYS__H__

#ifdef __cplusplus
extern "C" {
#endif

extern void aug_log(enum metal_log_level level, const char *format, ...);

#define METAL_INIT_DEFAULTS                                          \
	{                                                            \
		.log_handler = aug_log, .log_level = METAL_LOG_INFO, \
	}

#define METAL_MAX_DEVICE_REGIONS 2

int metal_aug_irq_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __METAL_FREERTOS_SYS__H__ */
