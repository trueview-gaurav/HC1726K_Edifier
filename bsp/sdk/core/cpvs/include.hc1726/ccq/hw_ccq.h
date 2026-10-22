/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_CCQ_H_
#define HW_CCQ_H_

#include "da_define.h"
#include "ccq.h"

#if __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#define HW_CCQ_CMD_LEN (8) /* 64 bits = 8 bytes */

typedef struct hw_ccq {
	uint32_t kptr;
	uint32_t instruction_length;
	uint32_t csr_virt_base;
	uint32_t csr_phy_base;
	struct ccq_buffer_setting buf_setting;
} HwCcq;

void hw_ccq_write_command(struct hw_ccq *ccq, void *csr_ptr, u32 data);
void hw_ccq_check_command(struct hw_ccq *ccq, void *csr_ptr, u32 data);
void hw_ccq_wait_command(struct hw_ccq *ccq, u32 cycle);
void hw_ccq_wait_irq_command(struct hw_ccq *ccq, u64 irq_mask);
void hw_ccq_issue_irq_command(struct hw_ccq *ccq);
void hw_ccq_buffer_update(struct hw_ccq *ccq);

#endif /* HW_CCQ_H_ */
