/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "cm_conf.h"
#include "uart.h"
#include "printf.h"

void SystemInit(void);

void SystemInit(void)
{
	uint32_t core_type = core_detect();
	uint32_t status_addr = (core_type == 0) ? CM0_STATUS_ADDR : CM4_STATUS_ADDR;

	mem_write(status_addr, CORE_STATUS_READY);

	if (core_type == 0)
		printf("\n\n====== Baremetal CM0 Boot UP ======\n\n");
	else if (core_type == 4)
		printf("\n\n====== Baremetal CM4 Boot UP ======\n\n");
}

/**
 * @brief Main baremetal test loop
 * Tests: CPU status write + SRAM test + DRAM test
 * @return Never returns (infinite loop)
 */
void main(void)
{
	uint32_t core_type = core_detect();
	uint32_t shm_data_addr = (core_type == 0) ? SHARED_MEM_CM0CA7 : SHARED_MEM_CM4CA7;
	uint32_t ipc_status_addr = (core_type == 0) ? CM0_IPC_STATUS : CM4_IPC_STATUS;
	uint32_t loop_status_addr = (core_type == 0) ? CM0_LOOP_STATUS : CM4_LOOP_STATUS;

	SystemInit();

	printf("Checking CSR reading...\n");
	test_csr();

	printf("Writing 0x12345678 to Shared Memory...\n");
	mem_write(shm_data_addr, 0x12345678);

	printf("Polling Shared Memory...\n");

	while (1) {
		static uint32_t loop_cnt = 0;
		loop_cnt++;
		mem_write(loop_status_addr, loop_cnt);

		if (!mem_cmp(shm_data_addr, CA7_IPC_MAGIC)) {
			mem_write(ipc_status_addr, 1);
			if (core_type == 0)
				printf("CM0 got 0xCA70CA74 from Shared Memory\n");
			else if (core_type == 4)
				printf("CM4 got 0xCA70CA74 from Shared Memory\n");
			break;
		} else {
			mem_write(ipc_status_addr, 0);
		}

		if ((loop_cnt & 0xFFFF) == 0) {
			if (core_type == 0)
				printf("CM0 looping...\n");
			else if (core_type == 4)
				printf("CM4 looping...\n");
		}
	}

	/* Safe infinite loop to prevent CPU from executing random memory content */
	while (1) {
		/* Keep CPU in a safe state */
	}
}
