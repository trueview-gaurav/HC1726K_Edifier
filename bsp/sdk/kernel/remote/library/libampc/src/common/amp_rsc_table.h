/*
 * Copyright (c) 2014, Mentor Graphics Corporation
 * All rights reserved.
 * Copyright (c) 2016 Xilinx, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* This file populates resource table for BM remote
 * for use by the FreeRTOS Master */

#ifndef RSC_TABLE_H_
#define RSC_TABLE_H_

#include <stddef.h>
#include <openamp/open_amp.h>

#include "common/config.h"

#if defined __cplusplus
extern "C" {
#endif

#define SHM_DEV_NAME "augentix_amp"
#define DEV_BUS_NAME_FREERTOS "generic"
#define DEV_BUS_NAME_LINUX "platform"

#define SHM_BASE_ADDR AMP_AMPC_SHM_ADDR
#define SHM_BASE_SIZE AMP_AMPC_SHM_SIZE

#define RSC_TABLE_PA AMP_AMPC_SHM_ADDR

#define RING_TX (AMP_AMPC_SHM_ADDR + 0x1000)
#define RING_RX (AMP_AMPC_SHM_ADDR + 0x3000)
#define VRING_SIZE 32

#define SHARED_MEM_PA (AMP_AMPC_SHM_ADDR + 0x5000)
#define SHARED_MEM_SIZE 0x8000UL

#define AMPI_DEV_NUMBER 1

#define AMPI_MAX_LINK_NUMBER 16
#define AMPI_MAX_SERVICE_NUMBER 10

#define NO_RESOURCE_ENTRIES 8

/* Resource table for the given remote */
struct remote_resource_table {
	unsigned int version;
	unsigned int num;
	unsigned int reserved[2];
	unsigned int offset[NO_RESOURCE_ENTRIES];
	unsigned long client_bitmap;
	unsigned long client_clean_bitmap;
	metal_mutex_t client_mut;
	metal_mutex_t rdev_lock;
	uint16_t client_tx_idx;
	/* rpmsg vdev entry */
	struct fw_rsc_vdev rpmsg_vdev;
	struct fw_rsc_vdev_vring rpmsg_vring0;
	struct fw_rsc_vdev_vring rpmsg_vring1;
};

void *amp_get_resource_table(int rsc_id, int *len);

#if defined __cplusplus
}
#endif

#endif /* RSC_TABLE_H_ */
