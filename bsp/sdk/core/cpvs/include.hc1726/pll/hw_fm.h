/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file hw_fm.h
 * @brief frequency meter 
 */

#ifndef HW_FM_H
#define HW_FM_H

#include "csr_bank_fm.h"
#include "address_map.h"

#define XTAL_FREQ 24000000
#define FM_LIMITATION_FREQ 300000000

void fm_print_result(uintptr_t fm_base, char *str);
int fm_set_and_start(uintptr_t fm_base, uint32_t target_freq, uint32_t tolerance);
int fm_analyze_jitter(uintptr_t fm_base, unsigned int dram_mts);

#endif
