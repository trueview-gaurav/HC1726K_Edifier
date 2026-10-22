/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <common.h>
#include <linux/arm-smccc.h>
#include <linux/string.h>
#include "agtx_smc.h"

static void eb_smc_otp_set(uint8_t *otp_data, struct arm_smccc_res *res)
{
	res->a0 = OPTEE_SMC_RETURN_ENOTAVAIL;
}

static void eb_smc_otp_get(uint8_t *otp_data, struct arm_smccc_res *res)
{
	res->a0 = OPTEE_SMC_RETURN_ENOTAVAIL;
}

/* Global eFuse burn operations structure */
efuse_burn_ops_t eb_smc_ops = { .magic_number = NVSPC_MAGIC,
	                        .api_version = NVSPC_API_VERSION,
	                        .prog_get = eb_smc_prog_get,
	                        .prog_set = eb_smc_prog_set,
	                        .prog_enable = eb_smc_prog_enable,
	                        .prog_check = eb_smc_prog_check,
	                        .debug_disable = eb_smc_debug_disable,
	                        .debug_check = eb_smc_debug_check,
	                        .otp_set = eb_smc_otp_set,
	                        .otp_get = eb_smc_otp_get,
	                        .reserved = { 0 } };

#define CACHE_LINE_SIZE 64
#define CACHE_ALIGN(x) (((x) + CACHE_LINE_SIZE - 1) & ~(CACHE_LINE_SIZE - 1))

static void cache_memcpy(void *dest, const void *src, size_t size, int direction)
{
	size_t aligned_size = CACHE_ALIGN(size);

	if (direction == 0) {
		invalidate_dcache_range((uintptr_t)src, (uintptr_t)src + aligned_size);
		memcpy(dest, src, size);
	} else {
		memcpy(dest, src, size);
		flush_dcache_range((uintptr_t)dest, (uintptr_t)dest + aligned_size);
	}
}


void eb_smc_prog_get(uint8_t *rot_data, struct arm_smccc_res *res)
{
	uint8_t *shared_buf = (uint8_t *)NVSPC_TEMP_BUFFER;

	memset(shared_buf, 0, NVSPC_MAX_SIZE);
	arm_smccc_smc(AUGENTIX_SIP_EB_PROG_GET, NVSPC_TEMP_BUFFER, ROT_SIZE, 0, 0, 0, 0, 0, res);

	if (res->a0 == OPTEE_SMC_RETURN_OK) {
		cache_memcpy(rot_data, shared_buf, ROT_SIZE, 0);
	}
}

void eb_smc_prog_set(uint8_t *rot_data, struct arm_smccc_res *res)
{
	uint8_t *shared_buf = (uint8_t *)NVSPC_TEMP_BUFFER;

	memset(shared_buf, 0, NVSPC_MAX_SIZE);
	cache_memcpy(shared_buf, rot_data, ROT_SIZE, 1);
	arm_smccc_smc(AUGENTIX_SIP_EB_PROG_SET, NVSPC_TEMP_BUFFER, ROT_SIZE, 0, 0, 0, 0, 0, res);
}

void eb_smc_prog_enable(struct arm_smccc_res *res)
{
	arm_smccc_smc(AUGENTIX_SIP_EB_PROG_ENABLE, 0, 0, 0, 0, 0, 0, 0, res);
}

uint8_t eb_smc_prog_check(struct arm_smccc_res *res)
{
	arm_smccc_smc(AUGENTIX_SIP_EB_PROG_CHECK, 0, 0, 0, 0, 0, 0, 0, res);
	return (uint8_t)res->a1;
}

void eb_smc_debug_disable(struct arm_smccc_res *res)
{
	arm_smccc_smc(AUGENTIX_SIP_EB_DEBUG_DISABLE, 0, 0, 0, 0, 0, 0, 0, res);
}

uint8_t eb_smc_debug_check(struct arm_smccc_res *res)
{
	arm_smccc_smc(AUGENTIX_SIP_EB_DEBUG_CHECK, 0, 0, 0, 0, 0, 0, 0, res);
	return (uint8_t)res->a1;
}

void eb_smc_nvspc_load(void *src, u32 size, struct arm_smccc_res *res)
{
	arm_smccc_smc(AUGENTIX_SIP_NVSPC_LOAD, (uintptr_t)src, size, 0, 0, 0, 0, 0, res);
}

void eb_smc_clk_enable(struct arm_smccc_res *res)
{
	arm_smccc_smc(AUGENTIX_SIP_EB_CLK_ENABLE, 0, 0, 0, 0, 0, 0, 0, res);
}

void eb_smc_clk_disable(struct arm_smccc_res *res)
{
	arm_smccc_smc(AUGENTIX_SIP_EB_CLK_DISABLE, 0, 0, 0, 0, 0, 0, 0, res);
}
