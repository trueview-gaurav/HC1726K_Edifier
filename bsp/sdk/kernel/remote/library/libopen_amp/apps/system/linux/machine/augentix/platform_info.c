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
#include <metal/alloc.h>
#include <metal/atomic.h>
#include <metal/io.h>
#include <metal/irq.h>
#include <metal/device.h>
#include <metal/utilities.h>
#include <openamp/remoteproc.h>
#include <openamp/rpmsg_virtio.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/un.h>
#include "platform_info.h"
#include "rsc_table.h"

#define DEV_BUS_NAME \
	"platform" /* device bus name. "platform" bus
                                        * is used in Linux kernel for generic
					* devices */
#define SHM_DEV_NAME "augentix_amp" /* shared device name */
#define RSC_TABLE_PA 0x0E000000UL
#define SHARED_BUF_PA 0x0E00C000UL
#define SHARED_BUF_SIZE 0x10000UL

struct remoteproc_priv rproc_priv = {
	.shm_name = SHM_DEV_NAME,
	.shm_bus_name = DEV_BUS_NAME,
	.mut = PTHREAD_MUTEX_INITIALIZER,
	.cond = PTHREAD_COND_INITIALIZER,
};

static struct remoteproc rproc_inst;

/* External functions */
extern int init_system(void);
extern void cleanup_system(void);

#define _rproc_wait() metal_cpu_yield()

/* processor operations from r5 to a53. It defines
 * notification operation and remote processor managementi operations. */
extern const struct remoteproc_ops augentix_linux_proc_ops;

/* RPMsg virtio shared buffer pool */
static struct rpmsg_virtio_shm_pool shpool;

static struct remoteproc *platform_create_proc(int proc_index, int rsc_index)
{
	void *rsc_buf;
	int rsc_size;
	int ret;
	struct metal_io_region *rsc_buf_io;

	(void)proc_index;
	(void)rsc_index;

	rsc_buf = get_resource_table(rsc_index, &rsc_size);

	/* Initialize remoteproc instance */
	if (!remoteproc_init(&rproc_inst, &augentix_linux_proc_ops, &rproc_priv))
		return NULL;
	printf("Successfully initialized remoteproc\r\n");

	rsc_buf_io = remoteproc_get_io_with_pa(&rproc_inst, RSC_TABLE_PA);
	if (!rsc_buf_io)
		goto err1;
	rsc_buf = metal_io_phys_to_virt(rsc_buf_io, RSC_TABLE_PA);

	//memcpy(rsc_buf, rsc_table, rsc_size);

	/* parse resource table to remoteproc */
	ret = remoteproc_set_rsc_table(&rproc_inst, rsc_buf, rsc_size);
	if (ret) {
	err1:
		printf("Failed to initialize remoteproc\r\n");
		remoteproc_remove(&rproc_inst);
		return NULL;
	}
	printf("Successfully set resource table to remoteproc.\r\n");

	return &rproc_inst;
}

int platform_init(int argc, char *argv[], void **platform)
{
	unsigned long proc_id = 0;
	unsigned long rsc_id = 0;
	struct remoteproc *rproc;

	if (!platform) {
		fprintf(stderr, "Failed to initialize platform, NULL pointer"
		                "to store platform data.\r\n");
		return -EINVAL;
	}
	/* Initialize HW system components */
	init_system();

	if (argc >= 2) {
		proc_id = strtoul(argv[1], NULL, 0);
	}

	if (argc >= 3) {
		rsc_id = strtoul(argv[2], NULL, 0);
	}

	rproc = platform_create_proc(proc_id, rsc_id);
	if (!rproc) {
		fprintf(stderr, "Failed to create remoteproc device.\r\n");
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
	void *shbuf;
	struct metal_io_region *shbuf_io;
	int ret;

	rpmsg_vdev = metal_allocate_memory(sizeof(*rpmsg_vdev));
	if (!rpmsg_vdev)
		return NULL;
	shbuf_io = remoteproc_get_io_with_pa(rproc, SHARED_BUF_PA);
	if (!shbuf_io)
		goto err1;
	shbuf = metal_io_phys_to_virt(shbuf_io, SHARED_BUF_PA);

	printf("Creating virtio...\r\n");
	/* TODO: can we have a wrapper for the following two functions? */
	vdev = remoteproc_create_virtio(rproc, vdev_index, role, rst_cb);
	if (!vdev) {
		printf("failed remoteproc_create_virtio\r\n");
		goto err1;
	}
	printf("Successfully created virtio device.\r\n");

	if (role == VIRTIO_DEV_DRIVER) {
		/* Only RPMsg virtio master needs to initialize the shared buffers pool */
		rpmsg_virtio_init_shm_pool(&shpool, shbuf, SHARED_BUF_SIZE);

		/* RPMsg virtio slave can set shared buffers pool argument to NULL */
		ret = rpmsg_init_vdev(rpmsg_vdev, vdev, ns_bind_cb, shbuf_io, &shpool);
	} else {
		ret = rpmsg_init_vdev(rpmsg_vdev, vdev, ns_bind_cb, shbuf_io, NULL);
	}
	if (ret) {
		printf("failed rpmsg_init_vdev\r\n");
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
	int ret;

	prproc = rproc->priv;
	while (1) {
		pthread_mutex_lock(&prproc->mut);
		if (!(atomic_flag_test_and_set(&prproc->ipi_nokick))) {
			pthread_mutex_unlock(&prproc->mut);
			ret = remoteproc_get_notification(rproc, RSC_NOTIFY_ID_ANY);
			if (ret)
				return ret;
			break;
		}
		pthread_cond_wait(&prproc->cond, &prproc->mut);
		pthread_mutex_unlock(&prproc->mut);
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
