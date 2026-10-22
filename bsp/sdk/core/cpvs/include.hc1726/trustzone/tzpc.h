/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __TZPC_H__
#define __TZPC_H__

#include "address_map.h"

#define tzpc_decprot0stat (volatile uint32_t *)(TZPC_BASE + 0x800)
#define tzpc_decprot0set (volatile uint32_t *)(TZPC_BASE + 0x804)
#define tzpc_decprot0clr (volatile uint32_t *)(TZPC_BASE + 0x808)

#define TRNG_INDEX 0
#define SECURE_DMA_INDEX 1

void tzpc_set_secure(uint32_t index);
void tzpc_set_nonsecure(uint32_t index);
/*
 * @return: 1 is secure, 0 is non-secure
 */
uint32_t tzpc_get_status(uint32_t index);

#endif
