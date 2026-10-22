/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file efuse_api_wrapper.h
 * @brief eFuse API wrapper functions for U-Boot FSM integration
 * Task: #95352 - eFuse Burning Process Optimization
 */

#ifndef EFUSE_API_WRAPPER_H
#define EFUSE_API_WRAPPER_H

#include <stdint.h>

void eb_prog_get(uint8_t *rot_data, volatile void *eb_ctrl);
void eb_prog_set(uint8_t *rot_data, volatile void *eb_ctrl);
void eb_prog_enable(volatile void *eb_ctrl);
uint8_t eb_prog_check(volatile void *eb_ctrl);
void eb_debug_disable(volatile void *eb_ctrl);
uint8_t eb_debug_check(volatile void *eb_ctrl);
void eb_otp_set(uint8_t *otp_data, volatile void *eb_ctrl);
void eb_otp_get(uint8_t *otp_data, volatile void *eb_ctrl);
/*
 * Canonical eFuse Burn Ops ABI v2.0
 * Placed at 0xFFE00860 via .efuse_burn_ops section (see nvspc.ld / u-boot-spl.lds)
 */
typedef struct {
	uint32_t magic_number;
	uint32_t api_version;
	void (*prog_get)(uint8_t *, volatile void *eb_ctrl);
	void (*prog_set)(uint8_t *, volatile void *eb_ctrl);
	void (*prog_enable)(volatile void *eb_ctrl);
	uint8_t (*prog_check)(volatile void *eb_ctrl);
	void (*debug_disable)(volatile void *eb_ctrl);
	uint8_t (*debug_check)(volatile void *eb_ctrl);
	void (*otp_set)(uint8_t *, volatile void *eb_ctrl);
	void (*otp_get)(uint8_t *, volatile void *eb_ctrl);
	uint32_t reserved[6];
} __attribute__((aligned(4))) eb_ops_t;

extern const eb_ops_t eb_ops;

#endif /* EFUSE_API_WRAPPER_H */
