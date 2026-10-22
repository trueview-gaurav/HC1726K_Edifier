/*
 * Copyright (c) 2014, Mentor Graphics Corporation
 * All rights reserved.
 * Copyright (c) 2016 Xilinx, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* This file populates resource table for BM remote
 * for use by the FreeRTOS Master */

#include <openamp/open_amp.h>
#include "amp_rsc_table.h"

#define RPMSG_IPU_C0_FEATURES 1

/* VirtIO rpmsg device id */
#define VIRTIO_ID_RPMSG_ 7

/* Remote supports Name Service announcement */
#define VIRTIO_RPMSG_F_NS 0

#define NUM_VRINGS 0x02
#define VRING_ALIGN 0x1000

struct remote_resource_table amp_resources = {
	/* Version */
	.version = 1,

	/* NUmber of table entries */
	.num = AMPI_DEV_NUMBER,
	/* reserved fields */
	.reserved = {
	        0,
	        0,
	},

	/* Offsets of rsc entries */
	.offset = {
	        offsetof(struct remote_resource_table, rpmsg_vdev),
	},

	.client_bitmap = 0,
	.client_clean_bitmap = 0,
	.client_mut = {0},
	.rdev_lock = {0},
	.client_tx_idx = 0,

	/* Virtio device entry */
	.rpmsg_vdev = {
	        RSC_VDEV,
	        VIRTIO_ID_RPMSG_,
	        0,
	        RPMSG_IPU_C0_FEATURES,
	        0,
	        0,
	        0,
	        NUM_VRINGS,
	        { 0, 0 },
	},

	/* Vring rsc entry - part of vdev rsc entry */
	.rpmsg_vring0 = { (uint32_t)RING_TX, VRING_ALIGN, VRING_SIZE, 1, 0 },
	.rpmsg_vring1 = { (uint32_t)RING_RX, VRING_ALIGN, VRING_SIZE, 2, 0 },
};

void *amp_get_resource_table(int rsc_id, int *len)
{
	(void)rsc_id;
	*len = sizeof(amp_resources);
	return &amp_resources;
}
