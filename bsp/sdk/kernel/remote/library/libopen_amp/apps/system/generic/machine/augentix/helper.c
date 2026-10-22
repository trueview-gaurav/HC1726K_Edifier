/******************************************************************************
 *
 * Copyright (C) 2010 - 2017 Xilinx, Inc.  All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 ******************************************************************************/

#include <metal/io.h>
#include <metal/device.h>
#include <metal/sys.h>
#include <metal/irq.h>
#include "platform_info.h"

#define SHM_BASE_ADDR 0x1E000000
#define SHM_BASE_SIZE (1024 * 1024 * 30)

#define SHM_DEV_NAME "augentix_amp"

/* Default generic I/O region page shift */
/* Each I/O region can contain multiple pages.
 * In FreeRTOS system, the memory mapping is flat, there is no
 * virtual memory.
 * We can assume there is only one page in the FreeRTOS system.
 */
#define DEFAULT_PAGE_SHIFT (-1UL)
#define DEFAULT_PAGE_MASK (-1UL)

#define METAL_LOG_DEFAULTS                                           \
	{                                                            \
		.log_handler = aug_log, .log_level = METAL_LOG_INFO, \
	}

#define LPERROR(x, ...) printf("FreeRTOS_err:" x, ##__VA_ARGS__)

static const metal_phys_addr_t metal_phys[] = {
	SHM_BASE_ADDR, /**< shared memory base address */
};

/* Define metal devices table for IPI, shared memory and TTC devices.
 * Linux system uses device tree to describe devices. Unlike Linux,
 * there is no standard device abstraction for FreeRTOS system, we
 * uses libmetal devices structure to describe the devices we used in
 * the example.
 * The IPI, shared memory and TTC devices are memory mapped
 * devices. For this type of devices, it is required to provide
 * accessible memory mapped regions, and interrupt information.
 * In FreeRTOS system, the memory mapping is flat. As you can see
 * in the table before, we set the virtual address "virt" the same
 * as the physical address.
 */
static struct metal_device metal_dev_table[] = {
	{
	        /* Shared memory management device */
	        .name = SHM_DEV_NAME,
	        .bus = NULL,
	        .num_regions = 1,
	        .regions = { {
	                .virt = (void *)SHM_BASE_ADDR,
	                .physmap = &metal_phys[0],
	                .size = SHM_BASE_SIZE,
	                .page_shift = DEFAULT_PAGE_SHIFT,
	                .page_mask = DEFAULT_PAGE_MASK,
	                .mem_flags = NULL,
	                .ops = { NULL },
	        } },
	        .node = { NULL },
	        .irq_num = 1,
	        .irq_info = (void *)1,
	},
};

/**
 * @brief platform_register_metal_device() - Statically Register libmetal
 *        devices.
 *        This function registers the IPI, shared memory and
 *        TTC devices to the libmetal generic bus.
 *        Libmetal uses bus structure to group the devices. Before you can
 *        access the device with libmetal device operation, you will need to
 *        register the device to a libmetal supported bus.
 *        For non-Linux system, libmetal only supports "generic" bus, which is
 *        used to manage the memory mapped devices.
 *
 * @return 0 - succeeded, non-zero for failures.
 */
int augentix_register_metal_device(void)
{
	unsigned int i;
	int ret;
	struct metal_device *dev;

	for (i = 0; i < sizeof(metal_dev_table) / sizeof(struct metal_device); i++) {
		dev = &metal_dev_table[i];
		printf("registering: %d, name=%s\n", i, dev->name);
		ret = metal_register_generic_device(dev);
		if (ret)
			return ret;
	}
	return 0;
}

/**
 * @brief sys_init() - Register libmetal devices.
 *        This function register the libmetal generic bus, and then
 *        register the IPI, shared memory descriptor and shared memory
 *        devices to the libmetal generic bus.
 *
 * @return 0 - succeeded, non-zero for failures.
 */
int init_system()
{
	struct metal_init_params metal_param = METAL_LOG_DEFAULTS;
	int ret;

	/* Initialize libmetal environment */
	metal_init(&metal_param);
	/* Initialize metal Xilinx IRQ controller */
	ret = metal_aug_irq_init();
	if (ret) {
		LPERROR("%s: Xilinx metal IRQ controller init failed.\n", __func__);
		return ret;
	}
	/* Register libmetal devices */
	ret = augentix_register_metal_device();
	if (ret) {
		LPERROR("%s: failed to register devices: %d\n", __func__, ret);
		return ret;
	}

	return 0;
}

/**
 * @brief sys_cleanup() - system cleanup
 *        This function finish the libmetal environment
 *        and disable caches.
 *
 * @return 0 - succeeded, non-zero for failures.
 */
void cleanup_system()
{
	/* Finish libmetal environment */
	metal_finish();
}
