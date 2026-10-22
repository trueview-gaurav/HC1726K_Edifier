/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_CCQ_H_
#define CSR_BANK_CCQ_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ccq  ***/
typedef struct csr_bank_ccq {
	/* IRQ_CLR 8'h00 */
	union {
		uint32_t irq_clr; // word name
		struct {
			uint32_t irq_clr_csr_check_fail : 1;
			uint32_t irq_clr_receive_unexpect_irq : 1;
			uint32_t irq_clr_csr_bus_conflict : 1;
			uint32_t irq_clr_ccq_sys_timeout : 1;
			uint32_t irq_clr_invalid_instruction : 1;
			uint32_t irq_clr_ccq_issue_irq : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STATUS 8'h04 */
	union {
		uint32_t irq_status; // word name
		struct {
			uint32_t status_csr_check_fail : 1;
			uint32_t status_receive_unexpect_irq : 1;
			uint32_t status_csr_bus_conflict : 1;
			uint32_t status_ccq_sys_timeout : 1;
			uint32_t status_invalid_instruction : 1;
			uint32_t status_ccq_issue_irq : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 8'h08 */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_csr_check_fail : 1;
			uint32_t irq_mask_receive_unexpect_irq : 1;
			uint32_t irq_mask_csr_bus_conflict : 1;
			uint32_t irq_mask_ccq_sys_timeout : 1;
			uint32_t irq_mask_invalid_instruction : 1;
			uint32_t irq_mask_ccq_issue_irq : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MAIN 8'h0C */
	union {
		uint32_t main; // word name
		struct {
			uint32_t ccq_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* INS_LENGTH 8'h10 */
	union {
		uint32_t ins_length; // word name
		struct {
			uint32_t instruction_length : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MODE 8'h14 */
	union {
		uint32_t mode; // word name
		struct {
			uint32_t arbitration_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t bypass_cmd : 1;
			uint32_t : 7; // padding bits
			uint32_t monitor_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SYS_TIMEOUT_TH_LSB 8'h18 */
	union {
		uint32_t sys_timeout_th_lsb; // word name
		struct {
			uint32_t timeout_threshold_lsb : 32;
		};
	};
	/* SYS_TIMEOUT_TH_MSB 8'h1C */
	union {
		uint32_t sys_timeout_th_msb; // word name
		struct {
			uint32_t timeout_threshold_msb : 32;
		};
	};
	/* CCQ_STATUS 8'h20 */
	union {
		uint32_t ccq_status; // word name
		struct {
			uint32_t ccq_idle : 1;
			uint32_t : 7; // padding bits
			uint32_t program_counter : 22;
			uint32_t : 2; // padding bits
		};
	};
	/* CG_EN_CTRL 8'h24 */
	union {
		uint32_t cg_en_ctrl; // word name
		struct {
			uint32_t dis_cg : 1;
			uint32_t : 7; // padding bits
			uint32_t cg_delay_num : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG_SEL 8'h28 */
	union {
		uint32_t debug_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCcq;

#endif