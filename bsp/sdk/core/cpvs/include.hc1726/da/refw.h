/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_REF_H
#define HW_REF_H

#include "da_define.h"

int calc_refwy_buffer_size(const int width, const int height, const struct dram_agent_config *dram_agent);
int calc_refwc_buffer_size(const int width, const int height, const struct dram_agent_config *dram_agent);
#endif