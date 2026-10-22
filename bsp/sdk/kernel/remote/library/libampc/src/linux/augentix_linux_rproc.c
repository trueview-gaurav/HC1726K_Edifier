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
 *    platform_info.c
 *
 * DESCRIPTION
 *
 *    This file define Xilinx ZynqMP R5 to A53 platform specific
 *    remoteproc implementation.
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
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/un.h>
#include "augentix_linux_rproc.h"

/* IPI registers offset */
#define IPI_TRIG_OFFSET 0xF00 /* IPI trigger reg offset */
#define IPI_OBS_OFFSET 0x4 /* IPI observation reg offset */
#define IPI_ISR_OFFSET 0x10 /* IPI interrupt status reg offset */
#define IPI_IMR_OFFSET 0x14 /* IPI interrupt mask reg offset */
#define IPI_IER_OFFSET 0x100 /* IPI interrupt enable reg offset */
#define IPI_IDR_OFFSET 0x180 /* IPI interrupt disable reg offset */
#define IPI_MASK 0x2 /* IPI mask for kick from RPU. */

#define INFO(x, ...) printf("[AMPI INFO]:" x, ##__VA_ARGS__)

void trigger_ipi(struct metal_io_region *ipi_io)
{
	uint32_t sgi;
	sgi = ((0x0 << 24) | (0x01 << (16 + 0)) | 1);
	metal_io_write32(ipi_io, IPI_TRIG_OFFSET, sgi);
}

static int augentix_linux_rproc_irq_handler(int vect_id, void *data)
{
	struct remoteproc *rproc = data;
	struct remoteproc_priv *prproc;

	(void)vect_id;
	if (!rproc)
		return METAL_IRQ_NOT_HANDLED;

	remoteproc_get_notification(rproc, RSC_NOTIFY_ID_ANY);

	prproc = rproc->priv;
	pthread_mutex_lock(&prproc->mut);
	atomic_flag_clear(&prproc->ipi_nokick);
	pthread_cond_signal(&prproc->cond);
	pthread_mutex_unlock(&prproc->mut);
	return METAL_IRQ_HANDLED;
}

static struct remoteproc *augentix_linux_rproc_init(struct remoteproc *rproc, const struct remoteproc_ops *ops,
                                                    void *arg)
{
	struct remoteproc_priv *prproc = arg;
	struct metal_device *dev;
	unsigned int irq_vect;
	metal_phys_addr_t mem_pa;
	int ret;

	if (!rproc || !prproc || !ops)
		return NULL;
	rproc->priv = prproc;
	rproc->ops = ops;
	prproc->shm_dev = NULL;
	/* Get shared memory device */
	ret = metal_device_open(prproc->shm_dev_bus_name, prproc->shm_dev_name, &dev);
	if (ret) {
		fprintf(stderr, "ERROR: failed to open shm device: %d.\r\n", ret);
		goto err1;
	}
	INFO("Successfully open shm device.\r\n");
	prproc->shm_dev = dev;
	prproc->shm_io = metal_device_io_region(dev, 0);
	prproc->ipi_io = metal_device_io_region(dev, 1);
	if (!prproc->shm_io || !prproc->ipi_io)
		goto err2;

	mem_pa = metal_io_phys(prproc->shm_io, 0);
	remoteproc_init_mem(&prproc->shm_mem, "shm", mem_pa, mem_pa, metal_io_region_size(prproc->shm_io),
	                    prproc->shm_io);
	remoteproc_add_mem(rproc, &prproc->shm_mem);
	INFO("Successfully added shared memory\r\n");

	atomic_store(&prproc->ipi_nokick, 1);

	/* Register interrupt handler and enable interrupt */
	irq_vect = (uintptr_t)dev->irq_info;
	metal_irq_register(irq_vect, augentix_linux_rproc_irq_handler, rproc);

	rproc->state = RPROC_READY;

	INFO("Successfully initialized Linux remoteproc.\r\n");
	return rproc;
err2:
	metal_device_close(prproc->shm_dev);
err1:
	return NULL;
}

static void augentix_linux_rproc_remove(struct remoteproc *rproc)
{
	struct remoteproc_priv *prproc;
	struct metal_device *dev;

	if (!rproc)
		return;
	prproc = rproc->priv;
	dev = prproc->shm_dev;
	if (dev) {
		metal_irq_unregister((uintptr_t)dev->irq_info);
		metal_device_close(dev);
	}
}

static int augentix_linux_rproc_start(struct remoteproc *rproc)
{
	struct remoteproc_priv *prproc;
	struct metal_device *dev;

	if (!rproc)
		return -EBADR;
	prproc = rproc->priv;
	dev = prproc->shm_dev;
	metal_irq_enable((uintptr_t)dev->irq_info);

	INFO("AMP IRQ ENABLED\n");
	while (!metal_linux_irq_ready())
		usleep(1000);
	return 0;
}

static int augentix_linux_rproc_stop(struct remoteproc *rproc)
{
	struct remoteproc_priv *prproc;
	struct metal_device *dev;

	if (!rproc)
		return -EBADR;
	prproc = rproc->priv;
	dev = prproc->shm_dev;
	metal_irq_disable((uintptr_t)dev->irq_info);
	INFO("AMP IRQ DISABLED\n");

	return 0;
}

static void *augentix_linux_rproc_mmap(struct remoteproc *rproc, metal_phys_addr_t *pa, metal_phys_addr_t *da,
                                       size_t size, unsigned int attribute, struct metal_io_region **io)
{
	struct remoteproc_priv *prproc;
	metal_phys_addr_t lpa, lda;
	struct metal_io_region *tmpio;

	(void)attribute;
	(void)size;
	if (!rproc)
		return NULL;
	prproc = rproc->priv;
	lpa = *pa;
	lda = *da;

	if (lpa == METAL_BAD_PHYS && lda == METAL_BAD_PHYS)
		return NULL;
	if (lpa == METAL_BAD_PHYS)
		lpa = lda;
	if (lda == METAL_BAD_PHYS)
		lda = lpa;
	tmpio = prproc->shm_io;
	if (!tmpio)
		return NULL;

	*pa = lpa;
	*da = lda;
	if (io)
		*io = tmpio;
	return metal_io_phys_to_virt(tmpio, lpa);
}

static int augentix_linux_rproc_notify(struct remoteproc *rproc, uint32_t id)
{
	struct remoteproc_priv *prproc;

	(void)id;
	if (!rproc)
		return -1;
	prproc = rproc->priv;

	trigger_ipi(prproc->ipi_io);

	return 0;
}

/* processor operations from Linux to FreeRTOS. It defines
 * notification operation and remote processor managementi operations. */
const struct remoteproc_ops amp_augentix_linux_rproc_ops = {
	.init = augentix_linux_rproc_init,
	.remove = augentix_linux_rproc_remove,
	.mmap = augentix_linux_rproc_mmap,
	.notify = augentix_linux_rproc_notify,
	.start = augentix_linux_rproc_start,
	.stop = augentix_linux_rproc_stop,
	.shutdown = NULL,
};

int remoteproc_wait(struct remoteproc_priv *rproc, const struct timespec *restrict abstime)
{
	pthread_mutex_lock(&rproc->mut);

	while (1) {
		if (!(atomic_flag_test_and_set(&rproc->ipi_nokick))) {
			pthread_mutex_unlock(&rproc->mut);
			return 1;
		}
		if (abstime) {
			if (pthread_cond_timedwait(&rproc->cond, &rproc->mut, abstime) == ETIMEDOUT) {
				pthread_mutex_unlock(&rproc->mut);
				return 0;
			}
		} else {
			pthread_cond_wait(&rproc->cond, &rproc->mut);
		}
	}
}
