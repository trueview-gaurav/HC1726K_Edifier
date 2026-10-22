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
 *       augentix_freertos_rproc.c
 *
 * DESCRIPTION
 *
 *       This file define Xilinx ZynqMP R5 to A53 platform specific 
 *       remoteproc implementation.
 *
 **************************************************************************/

#include <metal/atomic.h>
#include <metal/assert.h>
#include <metal/device.h>
#include <metal/irq.h>
#include <metal/utilities.h>
#include <openamp/rpmsg_virtio.h>
#include "platform_info.h"
#include "intc/hw_gic.h"

#define IPI_ID 1
#define INFO(x, ...) printf("FreeRTOS:" x, ##__VA_ARGS__)

static int augentix_freertos_proc_irq_handler(int vect_id, void *data)
{
	struct remoteproc *rproc = data;
	struct remoteproc_priv *prproc;
	unsigned int ipi_intr_status;

	(void)vect_id;
	if (!rproc)
		return METAL_IRQ_NOT_HANDLED;
	prproc = rproc->priv;
	atomic_flag_clear(&prproc->ipi_nokick);
	return METAL_IRQ_HANDLED;
}

static struct remoteproc *augentix_freertos_proc_init(struct remoteproc *rproc, const struct remoteproc_ops *ops,
                                                      void *arg)
{
	struct remoteproc_priv *prproc = arg;
	unsigned int irq_vect;
	int ret;

	if (!rproc || !prproc || !ops)
		return NULL;
	ret = metal_device_open(prproc->shm_dev_bus_name, prproc->shm_dev_name, &prproc->shm_dev);
	if (ret) {
		INFO("failed to open polling device: %d.\r\n", ret);
		return NULL;
	}
	rproc->priv = prproc;
	prproc->shm_io = metal_device_io_region(prproc->shm_dev, 0);
	if (!prproc->shm_io)
		goto err1;
	atomic_store(&prproc->ipi_nokick, 1);
	/* Register interrupt handler and enable interrupt */
	irq_vect = (uintptr_t)prproc->shm_dev->irq_info;
	metal_irq_register(irq_vect, augentix_freertos_proc_irq_handler, rproc);
	metal_irq_enable(irq_vect);

	rproc->ops = ops;

	return rproc;
err1:
	metal_device_close(prproc->shm_dev);
	return NULL;
}

static void augentix_freertos_proc_remove(struct remoteproc *rproc)
{
	struct remoteproc_priv *prproc;
	struct metal_device *dev;

	if (!rproc)
		return;
	prproc = rproc->priv;
	dev = prproc->shm_dev;
	if (dev) {
		metal_irq_disable((uintptr_t)dev->irq_info);
		metal_irq_unregister((uintptr_t)dev->irq_info);
	}
	metal_device_close(prproc->shm_dev);
}

static void *augentix_freertos_proc_mmap(struct remoteproc *rproc, metal_phys_addr_t *pa, metal_phys_addr_t *da,
                                         size_t size, unsigned int attribute, struct metal_io_region **io)
{
	struct remoteproc_mem *mem;
	metal_phys_addr_t lpa, lda;
	struct metal_io_region *tmpio;
	INFO("augentix_freertos_proc_mmap 0x%x, 0x%x\n", (int)pa, (int)da);

	lpa = *pa;
	lda = *da;

	if (lpa == METAL_BAD_PHYS && lda == METAL_BAD_PHYS)
		return NULL;
	if (lpa == METAL_BAD_PHYS)
		lpa = lda;
	if (lda == METAL_BAD_PHYS)
		lda = lpa;

	mem = metal_allocate_memory(sizeof(*mem));
	if (!mem)
		return NULL;
	tmpio = metal_allocate_memory(sizeof(*tmpio));
	if (!tmpio) {
		metal_free_memory(mem);
		return NULL;
	}
	remoteproc_init_mem(mem, NULL, lpa, lda, size, tmpio);
	/* va is the same as pa in this platform */
	metal_io_init(tmpio, (void *)lpa, &mem->pa, size, sizeof(metal_phys_addr_t) << 3, attribute, NULL);
	remoteproc_add_mem(rproc, mem);
	*pa = lpa;
	*da = lda;
	if (io)
		*io = tmpio;
	return metal_io_phys_to_virt(tmpio, mem->pa);
}

static int augentix_freertos_proc_notify(struct remoteproc *rproc, uint32_t id)
{
	struct remoteproc_priv *prproc;

	(void)id;
	if (!rproc)
		return -1;
	prproc = rproc->priv;
	(void)prproc;

	gic_request_sgi(IPI_ID, 1);
	return 0;
}

/* processor operations from r5 to a53. It defines
 * notification operation and remote processor managementi operations. */
const struct remoteproc_ops augentix_freertos_proc_ops = {
	.init = augentix_freertos_proc_init,
	.remove = augentix_freertos_proc_remove,
	.mmap = augentix_freertos_proc_mmap,
	.notify = augentix_freertos_proc_notify,
	.start = NULL,
	.stop = NULL,
	.shutdown = NULL,
};
