/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "cm_conf.h"
#include "printf.h"

uint32_t csr_read(uint32_t addr)
{
	volatile uint32_t *ptr = (volatile uint32_t *)addr;
	return *ptr;
}

void csr_write(uint32_t addr, uint32_t value)
{
	volatile uint32_t *ptr = (volatile uint32_t *)addr;
	*ptr = value;
}

/**
 * @brief Test CSR (Control and Status Register) accessibility
 * Tests basic register read operations and stores results in DRAM
 */
void test_csr(void)
{
	uint32_t syscfg_val, pioc_val, gpioc_val;

	/* Test SYSCFG register and print result */
	syscfg_val = csr_read(CSR_SYSCFG_BASE);
	mem_write(CSR_SYSCFG_RESULT, syscfg_val);
	printf("SYSCFG : OK\n");

	/* Test PIOC register and print result */
	pioc_val = csr_read(CSR_PIOC_BASE);
	mem_write(CSR_PIOC_RESULT, pioc_val);
	printf("PIOC   : OK\n");

	/* Test GPIOC register and print result */
	gpioc_val = csr_read(CSR_GPIOC_BASE);
	mem_write(CSR_GPIOC_RESULT, gpioc_val);
	printf("GPIOC  : OK\n");
}