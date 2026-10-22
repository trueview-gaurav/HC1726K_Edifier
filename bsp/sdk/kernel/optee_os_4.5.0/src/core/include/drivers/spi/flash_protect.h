/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __DRIVERS_AGTX_FP_H
#define __DRIVERS_AGTX_FP_H

#include <types_ext.h>

struct fp_flash_info {
	uint32_t id;
	uint32_t capacity;
	uint32_t fp_size;
#ifndef CFG_BYPASS_LOCK
	uint8_t bp_mask; /* Block protection bits mask */
	/* Status register lock (SRL) / status register protection 1 (SRP1) bit mask */
	uint8_t srl_offset;
#endif // CFG_BYPASS_LOCK
};

const struct fp_flash_info *get_selected_flash_info(void);
TEE_Result fp_check_support(void);
TEE_Result fp_read(void *output, uint32_t addr, uint32_t size);
TEE_Result fp_write(const void *data, uint32_t addr, uint32_t size);
TEE_Result fp_erase(uint32_t addr, uint32_t size);
#ifndef CFG_BYPASS_LOCK
TEE_Result fp_lock(void);
TEE_Result fp_unlock(void);
#endif // CFG_BYPASS_LOCK

#endif /* !__DRIVERS_AGTX_FP_H */
