/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PWM_H_
#define CSR_BANK_PWM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pwm  ***/
typedef struct csr_bank_pwm {
	/* TRIGGER 16'h00 */
	union {
		uint32_t trigger; // word name
		struct {
			uint32_t trigger_0 : 1;
			uint32_t trigger_1 : 1;
			uint32_t trigger_2 : 1;
			uint32_t trigger_3 : 1;
			uint32_t trigger_4 : 1;
			uint32_t trigger_5 : 1;
			uint32_t trigger_6 : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BUSY 16'h04 */
	union {
		uint32_t busy; // word name
		struct {
			uint32_t status_0 : 1;
			uint32_t status_1 : 1;
			uint32_t status_2 : 1;
			uint32_t status_3 : 1;
			uint32_t status_4 : 1;
			uint32_t status_5 : 1;
			uint32_t status_6 : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLR 16'h08 */
	union {
		uint32_t irq_clr; // word name
		struct {
			uint32_t irq_clear_0 : 1;
			uint32_t irq_clear_1 : 1;
			uint32_t irq_clear_2 : 1;
			uint32_t irq_clear_3 : 1;
			uint32_t irq_clear_4 : 1;
			uint32_t irq_clear_5 : 1;
			uint32_t irq_clear_6 : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_ST 16'h0C */
	union {
		uint32_t irq_st; // word name
		struct {
			uint32_t irq_status_0 : 1;
			uint32_t irq_status_1 : 1;
			uint32_t irq_status_2 : 1;
			uint32_t irq_status_3 : 1;
			uint32_t irq_status_4 : 1;
			uint32_t irq_status_5 : 1;
			uint32_t irq_status_6 : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 16'h10 */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_0 : 1;
			uint32_t irq_mask_1 : 1;
			uint32_t irq_mask_2 : 1;
			uint32_t irq_mask_3 : 1;
			uint32_t irq_mask_4 : 1;
			uint32_t irq_mask_5 : 1;
			uint32_t irq_mask_6 : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MODE 16'h14 */
	union {
		uint32_t mode; // word name
		struct {
			uint32_t mode_0 : 1;
			uint32_t mode_1 : 1;
			uint32_t mode_2 : 1;
			uint32_t mode_3 : 1;
			uint32_t mode_4 : 1;
			uint32_t mode_5 : 1;
			uint32_t mode_6 : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONFIG_0 16'h18 */
	union {
		uint32_t config_0; // word name
		struct {
			uint32_t prescaler_0 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_0 : 8;
			uint32_t count_high_0 : 8;
			uint32_t num_period_0 : 8;
		};
	};
	/* CONFIG_1 16'h1C */
	union {
		uint32_t config_1; // word name
		struct {
			uint32_t prescaler_1 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_1 : 8;
			uint32_t count_high_1 : 8;
			uint32_t num_period_1 : 8;
		};
	};
	/* CONFIG_2 16'h20 */
	union {
		uint32_t config_2; // word name
		struct {
			uint32_t prescaler_2 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_2 : 8;
			uint32_t count_high_2 : 8;
			uint32_t num_period_2 : 8;
		};
	};
	/* CONFIG_3 16'h24 */
	union {
		uint32_t config_3; // word name
		struct {
			uint32_t prescaler_3 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_3 : 8;
			uint32_t count_high_3 : 8;
			uint32_t num_period_3 : 8;
		};
	};
	/* CONFIG_4 16'h28 */
	union {
		uint32_t config_4; // word name
		struct {
			uint32_t prescaler_4 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_4 : 8;
			uint32_t count_high_4 : 8;
			uint32_t num_period_4 : 8;
		};
	};
	/* CONFIG_5 16'h2C */
	union {
		uint32_t config_5; // word name
		struct {
			uint32_t prescaler_5 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_5 : 8;
			uint32_t count_high_5 : 8;
			uint32_t num_period_5 : 8;
		};
	};
	/* CONFIG_6 16'h30 */
	union {
		uint32_t config_6; // word name
		struct {
			uint32_t prescaler_6 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_6 : 8;
			uint32_t count_high_6 : 8;
			uint32_t num_period_6 : 8;
		};
	};
	/* DEBUG 16'h34 */
	union {
		uint32_t debug; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPwm;

#endif