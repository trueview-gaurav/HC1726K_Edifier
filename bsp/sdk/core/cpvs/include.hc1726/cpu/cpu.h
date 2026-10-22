/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CPU_H_
#define CPU_H_

/*
 * The following page mapping description and attributes conform to ARMv7 A,R ARM. B3.5.
 *
 * Here we only apply short-descriptor first-level descriptor format, where PXN = 0.
 */

/* the MMU must be enabled before enable D-cache */
void dcache_enable(void);

void dcache_diable(void);

void icache_enable(void);

void icache_disable(void);

#endif /* CPU_H */
