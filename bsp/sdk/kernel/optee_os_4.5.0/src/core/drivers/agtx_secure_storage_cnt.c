/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <tee_api_defines.h>
#include <kernel/nv_counter.h>
#include <drivers/agtx_mono_cnt.h>

TEE_Result nv_counter_get_ree_fs(uint32_t *value)
{
	*value = cnt_get(SECURE_STORAGE_CNT);
	return TEE_SUCCESS;
}

TEE_Result nv_counter_incr_ree_fs_to(uint32_t value)
{
	return cnt_set(SECURE_STORAGE_CNT, value);
}