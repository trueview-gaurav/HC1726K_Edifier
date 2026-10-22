/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_DA_H_
#define SAPPORO_DA_H_

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#include "da_define.h"

int gen_da_setting(DramAgentConfig *da_table, const uint8_t start_item, const uint8_t end_item);
int modify_da_setting(DramAgentConfig *dram_agent, uint8_t bitdepth, uint8_t bank_group_type);
void set_start_end_addr(volatile uint32_t *start_addr, volatile uint32_t *end_addr, uint32_t init_addr,
                        uint32_t buffer_size);

void print_da_config(struct dram_agent_config *da);
void print_pixel_tile(struct da_pixel_tile *da, int t);
void print_block_tile(struct da_block_tile *da, int t);
void print_linear_tile(struct da_linear_tile *da, int t);

#endif /* SAPPORO_DA_H_ */
