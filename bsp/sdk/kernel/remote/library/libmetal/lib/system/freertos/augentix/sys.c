/*
 * Copyright (c) 2018, Linaro Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	freertos/template/sys.c
 * @brief	machine specific system primitives implementation.
 */

#include <metal/io.h>
#include <metal/sys.h>
#include <metal/utilities.h>
#include <stdint.h>
#include "utils/printf.h"
#include "intc/hw_gic.h"

void aug_log(enum metal_log_level level, const char *format, ...)
{
	char msg[128];
	va_list args;
	static const char *const level_strs[] = {
		"metal: emergency: ", "metal: alert:     ", "metal: critical:  ", "metal: error:     ",
		"metal: warning:   ", "metal: notice:    ", "metal: info:      ", "metal: debug:     ",
	};

	va_start(args, format);
	vsnprintf(msg, sizeof(msg), format, args);
	va_end(args);

	printf(level_strs[level]);
	printf(msg);
}

void metal_machine_cache_flush(void *addr, unsigned int len)
{
	metal_unused(addr);
	metal_unused(len);

	/* Add implementation here */
}

void metal_machine_cache_invalidate(void *addr, unsigned int len)
{
	metal_unused(addr);
	metal_unused(len);

	/* Add implementation here */
}

void *metal_machine_io_mem_map(void *va, metal_phys_addr_t pa, size_t size, unsigned int flags)
{
	metal_unused(pa);
	metal_unused(size);
	metal_unused(flags);

	/* Add implementation here */

	return va;
}
