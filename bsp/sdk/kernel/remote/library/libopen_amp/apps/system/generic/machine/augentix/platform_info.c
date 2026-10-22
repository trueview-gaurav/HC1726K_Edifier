/*
 * Copyright (c) 2014, Mentor Graphics Corporation
 * All rights reserved.
 * Copyright (c) 2017 Xilinx, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**************************************************************************
 * FILE NAME
 *
 *       platform_info.c
 *
 * DESCRIPTION
 *
 *       This file define platform specific data and implements APIs to set
 *       platform specific information for OpenAMP.
 *
 **************************************************************************/

#include <metal/atomic.h>
#include <metal/assert.h>
#include <metal/device.h>
#include <metal/irq.h>
#include <metal/utilities.h>
#include <openamp/rpmsg_virtio.h>
#include <errno.h>
#include "platform_info.h"
#include "rsc_table.h"
#include "intc/hw_gic.h"

#define DEV_BUS_NAME "generic"
#define SHM_DEV_NAME "augentix_amp" /* shared device name */
#define RSC_TABLE_PA 0x1E000000UL

#define SHM_BASE_ADDR 0x1E000000
#define SHM_BASE_SIZE (1024 * 1024 * 30)

#define SHARED_MEM_PA 0x1E00C000UL
#define SHARED_MEM_SIZE 0x10000UL

#define _rproc_wait() //asm volatile("wfi")

#define INFO(x, ...) printf("FreeRTOS:" x, ##__VA_ARGS__)

struct remoteproc_priv rproc_priv = {
	.shm_dev_name = SHM_DEV_NAME,
	.shm_dev_bus_name = DEV_BUS_NAME,
};

static struct remoteproc rproc_inst;

/* External functions */
extern int init_system(void);
extern void cleanup_system(void);

/* processor operations from r5 to a53. It defines
 * notification operation and remote processor managementi operations. */
extern const struct remoteproc_ops augentix_freertos_proc_ops;

/* RPMsg virtio shared buffer pool */
static struct rpmsg_virtio_shm_pool shpool;

static struct remoteproc *platform_create_proc(int proc_index, int rsc_index)
{
	void *rsc_table;
	void *rsc_table_share;
	int rsc_size;
	int ret;
	metal_phys_addr_t pa;

	(void)proc_index;
	(void)rsc_index;
	rsc_table = get_resource_table(rsc_index, &rsc_size);
	rsc_table_share = (void *)RSC_TABLE_PA;
	memcpy(rsc_table_share, rsc_table, rsc_size);

	/* Initialize remoteproc instance */
	if (!remoteproc_init(&rproc_inst, &augentix_freertos_proc_ops, &rproc_priv))
		return NULL;

	pa = SHM_BASE_ADDR;
	(void *)remoteproc_mmap(&rproc_inst, &pa, NULL, SHM_BASE_SIZE, 0, NULL);

	/* parse resource table to remoteproc */
	ret = remoteproc_set_rsc_table(&rproc_inst, rsc_table_share, rsc_size);
	if (ret) {
		INFO("Failed to initialize remoteproc\r\n");
		remoteproc_remove(&rproc_inst);
		return NULL;
	}
	INFO("Initialize remoteproc successfully.\r\n");

	return &rproc_inst;
}

int platform_init(int argc, char *argv[], void **platform)
{
	unsigned long proc_id = 0;
	unsigned long rsc_id = 0;
	struct remoteproc *rproc;

	(void)argc;
	(void)argv;

	if (!platform) {
		INFO("Failed to initialize platform,"
		     "NULL pointer to store platform data.\r\n");
		return -EINVAL;
	}
	/* Initialize HW system components */
	init_system();

	rproc = platform_create_proc(proc_id, rsc_id);
	if (!rproc) {
		INFO("Failed to create remoteproc device.\r\n");
		return -EINVAL;
	}
	*platform = rproc;
	return 0;
}

struct rpmsg_device *platform_create_rpmsg_vdev(void *platform, unsigned int vdev_index, unsigned int role,
                                                void (*rst_cb)(struct virtio_device *vdev), rpmsg_ns_bind_cb ns_bind_cb)
{
	struct remoteproc *rproc = platform;
	struct rpmsg_virtio_device *rpmsg_vdev;
	struct virtio_device *vdev;
	struct metal_io_region *shbuf_io;
	void *shbuf;
	int ret;

	rpmsg_vdev = metal_allocate_memory(sizeof(*rpmsg_vdev));
	if (!rpmsg_vdev)
		return NULL;
	shbuf_io = remoteproc_get_io_with_pa(rproc, SHARED_MEM_PA);
	if (!shbuf_io)
		goto err1;
	shbuf = metal_io_phys_to_virt(shbuf_io, SHARED_MEM_PA);

	INFO("creating remoteproc virtio\r\n");
	/* TODO: can we have a wrapper for the following two functions? */
	vdev = remoteproc_create_virtio(rproc, vdev_index, role, rst_cb);
	if (!vdev) {
		INFO("failed remoteproc_create_virtio\r\n");
		goto err1;
	}

	if (role == VIRTIO_DEV_DRIVER) {
		INFO("initializing rpmsg shared buffer pool\r\n");
		/* Only RPMsg virtio master needs to initialize the shared buffers pool */
		rpmsg_virtio_init_shm_pool(&shpool, shbuf, SHARED_MEM_SIZE);

		INFO("initializing rpmsg vdev\r\n");
		/* RPMsg virtio slave can set shared buffers pool argument to NULL */
		ret = rpmsg_init_vdev(rpmsg_vdev, vdev, ns_bind_cb, shbuf_io, &shpool);
	} else {
		ret = rpmsg_init_vdev(rpmsg_vdev, vdev, ns_bind_cb, shbuf_io, NULL);
	}
	if (ret) {
		INFO("failed rpmsg_init_vdev\r\n");
		goto err2;
	}

	return rpmsg_virtio_get_rpmsg_device(rpmsg_vdev);
err2:
	remoteproc_remove_virtio(rproc, vdev);
err1:
	metal_free_memory(rpmsg_vdev);
	return NULL;
}

int platform_poll(void *priv)
{
	struct remoteproc *rproc = priv;
	struct remoteproc_priv *prproc;
	//unsigned int flags;
	int ret;

	prproc = rproc->priv;
	while (1) {
		//flags = metal_irq_save_disable();
		gicc_disable_cpu();
		if (!(atomic_flag_test_and_set(&prproc->ipi_nokick))) {
			//metal_irq_restore_enable(flags);
			gicc_enable_cpu();
			ret = remoteproc_get_notification(rproc, RSC_NOTIFY_ID_ANY);
			if (ret)
				return ret;
			break;
		}
		_rproc_wait();
		//metal_irq_restore_enable(flags);
		gicc_enable_cpu();
	}
	return 0;
}

void platform_release_rpmsg_vdev(struct rpmsg_device *rpdev, void *platform)
{
	struct rpmsg_virtio_device *rpvdev;
	struct remoteproc *rproc;

	rpvdev = metal_container_of(rpdev, struct rpmsg_virtio_device, rdev);
	rproc = platform;

	rpmsg_deinit_vdev(rpvdev);
	remoteproc_remove_virtio(rproc, rpvdev->vdev);
}

void platform_cleanup(void *platform)
{
	struct remoteproc *rproc = platform;

	if (rproc)
		remoteproc_remove(rproc);
	cleanup_system();
}
