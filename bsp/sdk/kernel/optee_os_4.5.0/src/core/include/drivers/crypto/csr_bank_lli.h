/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_LLI_H_
#define CSR_BANK_LLI_H_

#include <stdint.h>

/***  C struct generated from lli  ***/
typedef struct csr_bank_lli {
	/* LINKED_LISTED_POINTER 10'h000 */
	union {
		uint32_t linked_listed_pointer; // word name
		struct {
			uint32_t : 3; // padding bits
			uint32_t first_lli_addr : 28;
			uint32_t : 1; // padding bits
		};
	};
	/* LLI_CTRL 10'h004 */
	union {
		uint32_t lli_ctrl; // word name
		struct {
			uint32_t lli_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LLI_CFG 10'h008 */
	union {
		uint32_t lli_cfg; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t lli_debug_mon_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* IRQ_CLR 10'h00C */
	union {
		uint32_t irq_clr; // word name
		struct {
			uint32_t irq_clr_csr_check_fail : 1;
			uint32_t irq_clr_receive_unexpect_irq : 1;
			uint32_t irq_clr_all_lli_done : 1;
			uint32_t irq_clr_one_lli_done : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STATUS 10'h010 */
	union {
		uint32_t irq_status; // word name
		struct {
			uint32_t status_csr_check_fail : 1;
			uint32_t status_receive_unexpect_irq : 1;
			uint32_t status_all_lli_done : 1;
			uint32_t status_one_lli_done : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 10'h014 */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_csr_check_fail : 1;
			uint32_t irq_mask_receive_unexpect_irq : 1;
			uint32_t irq_mask_all_lli_done : 1;
			uint32_t irq_mask_one_lli_done : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ARB_MODE 10'h018 */
	union {
		uint32_t arb_mode; // word name
		struct {
			uint32_t arbitration_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV 10'h01C */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* DEBUG_APB_M_ADDR 10'h020 */
	union {
		uint32_t debug_apb_m_addr; // word name
		struct {
			uint32_t status_addr_to_apb_m : 32;
		};
	};
	/* DEBUG_APB_M_DATA 10'h024 */
	union {
		uint32_t debug_apb_m_data; // word name
		struct {
			uint32_t status_data_to_apb_m : 32;
		};
	};
	/* DEBUG_APB_M_IRQ_MASK0 10'h028 */
	union {
		uint32_t debug_apb_m_irq_mask0; // word name
		struct {
			uint32_t internal_irq_mask_0 : 32;
		};
	};
	/* DEBUG_APB_M_IRQ_MASK1 10'h02C */
	union {
		uint32_t debug_apb_m_irq_mask1; // word name
		struct {
			uint32_t internal_irq_mask_1 : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* DEBUG_OP_STATUS 10'h030 */
	union {
		uint32_t debug_op_status; // word name
		struct {
			uint32_t status_op_write : 1;
			uint32_t status_op_check : 1;
			uint32_t status_op_polling : 1;
			uint32_t status_op_wait_irq : 1;
			uint32_t status_op_issue_irq : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LLI_FINISH_NUM 10'h034 */
	union {
		uint32_t lli_finish_num; // word name
		struct {
			uint32_t finish_lli_cnt : 32;
		};
	};
	/* LLI_REG_OFFSET_0 10'h038 */
	union {
		uint32_t lli_reg_offset_0; // word name
		struct {
			uint32_t lli_reg_0 : 32;
		};
	};
	/* LLI_REG_OFFSET_1 10'h03C */
	union {
		uint32_t lli_reg_offset_1; // word name
		struct {
			uint32_t lli_reg_1 : 32;
		};
	};
	/* LLI_REG_OFFSET_2 10'h040 */
	union {
		uint32_t lli_reg_offset_2; // word name
		struct {
			uint32_t lli_reg_2 : 32;
		};
	};
	/* LLI_REG_OFFSET_3 10'h044 */
	union {
		uint32_t lli_reg_offset_3; // word name
		struct {
			uint32_t lli_reg_3 : 32;
		};
	};
	/* LLI_REG_OFFSET_4 10'h048 */
	union {
		uint32_t lli_reg_offset_4; // word name
		struct {
			uint32_t lli_reg_4 : 32;
		};
	};
	/* LLI_REG_OFFSET_5 10'h04C */
	union {
		uint32_t lli_reg_offset_5; // word name
		struct {
			uint32_t lli_reg_5 : 32;
		};
	};
	/* LLI_REG_OFFSET_6 10'h050 */
	union {
		uint32_t lli_reg_offset_6; // word name
		struct {
			uint32_t lli_reg_6 : 32;
		};
	};
	/* LLI_REG_OFFSET_7 10'h054 */
	union {
		uint32_t lli_reg_offset_7; // word name
		struct {
			uint32_t lli_reg_7 : 32;
		};
	};
	/* LLI_REG_OFFSET_8 10'h058 */
	union {
		uint32_t lli_reg_offset_8; // word name
		struct {
			uint32_t lli_reg_8 : 32;
		};
	};
	/* LLI_REG_OFFSET_9 10'h05C */
	union {
		uint32_t lli_reg_offset_9; // word name
		struct {
			uint32_t lli_reg_9 : 32;
		};
	};
	/* LLI_REG_OFFSET_10 10'h060 */
	union {
		uint32_t lli_reg_offset_10; // word name
		struct {
			uint32_t lli_reg_10 : 32;
		};
	};
	/* LLI_REG_OFFSET_11 10'h064 */
	union {
		uint32_t lli_reg_offset_11; // word name
		struct {
			uint32_t lli_reg_11 : 32;
		};
	};
	/* LLI_REG_OFFSET_12 10'h068 */
	union {
		uint32_t lli_reg_offset_12; // word name
		struct {
			uint32_t lli_reg_12 : 32;
		};
	};
	/* LLI_REG_OFFSET_13 10'h06C */
	union {
		uint32_t lli_reg_offset_13; // word name
		struct {
			uint32_t lli_reg_13 : 32;
		};
	};
	/* LLI_REG_OFFSET_14 10'h070 */
	union {
		uint32_t lli_reg_offset_14; // word name
		struct {
			uint32_t lli_reg_14 : 32;
		};
	};
	/* LLI_REG_OFFSET_15 10'h074 */
	union {
		uint32_t lli_reg_offset_15; // word name
		struct {
			uint32_t lli_reg_15 : 32;
		};
	};
} CsrBankLli;

#endif
