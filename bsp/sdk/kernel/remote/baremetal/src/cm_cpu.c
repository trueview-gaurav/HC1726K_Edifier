/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "cm_conf.h"

uint32_t core_detect(void)
{
	uint32_t cpuid = SCB_CPUID;
	uint16_t partno = (cpuid >> 4) & 0xFFF;

	switch (partno) {
	case CORTEX_M0_PARTNO:
		return 0;
	case CORTEX_M4_PARTNO:
		return 4;
	default:
		return 0xFF;
	}
}

uint32_t get_cpuid_raw(void)
{
	return SCB_CPUID;
}

void update_cpuinfo(void)
{
	uint32_t cpuid = SCB_CPUID;
	uint32_t core_type = core_detect();
	uint32_t status_base = (core_type == 0) ? CM0_INFO_ADDR : CM4_INFO_ADDR;

	mem_write(status_base, cpuid);
}

void cm_delay(uint32_t slots)
{
	volatile uint32_t total = slots * 1000000;
	for (volatile uint32_t i = 0; i < total; i++) {
	}
}