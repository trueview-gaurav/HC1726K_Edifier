/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __DRIVERS_AGTX_MONOTONIC_CNT_H
#define __DRIVERS_AGTX_MONOTONIC_CNT_H

/* Command IDs */
#define PTA_CMD_CNT_GET 0x0
#define PTA_CMD_CNT_SET 0x1

/* Counter Indices */
#define TEE_VER_CNT 0x0
#define ROOTFS_VER_CNT 0x1
#define TEE_SLOT_CNT 0x2
#define SECURE_STORAGE_CNT 0x3

uint32_t cnt_get(uint32_t cnt_id);
TEE_Result cnt_set(uint32_t cnt_id, uint32_t cnt_val);
TEE_Result cnt_init(void);

#endif /* __DRIVERS_AGTX_MONOTONIC_CNT_H */