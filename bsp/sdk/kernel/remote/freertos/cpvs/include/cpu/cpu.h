#ifndef CPU_H_
#define CPU_H_

/*
 * AUGENTIX INC. - PROPRIETARY AND CONFIDENTIAL
 *
 * mmu.h - Cortex-A7 CPU management API
 * Copyright (C) 2020 Jerry Wu, Augentix Inc. <jerry.wu@augentix.com>
 *
 * NOTICE: The information contained herein is the property of Augentix Inc.
 * Unauthorized copying and distributing of this file, via any medium,
 * is strictly prohibited.
 *
 */

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
