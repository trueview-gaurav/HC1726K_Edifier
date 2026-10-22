#ifndef CSR_BANK_PWM_H_
#define CSR_BANK_PWM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pwm  ***/
typedef struct csr_bank_pwm {
	/* PWM00 16'h00 */
	union {
		uint32_t pwm00; // word name
		struct {
			uint32_t trigger_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t irq_clear_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM01 16'h04 */
	union {
		uint32_t pwm01; // word name
		struct {
			uint32_t busy_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t status_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM02 16'h08 */
	union {
		uint32_t pwm02; // word name
		struct {
			uint32_t irq_mask_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mode_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM03 16'h0C */
	union {
		uint32_t pwm03; // word name
		struct {
			uint32_t prescaler_0 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_0 : 8;
			uint32_t count_high_0 : 8;
			uint32_t num_period_0 : 8;
		};
	};
	/* PWM04 16'h10 */
	union {
		uint32_t pwm04; // word name
		struct {
			uint32_t trigger_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t irq_clear_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM05 16'h14 */
	union {
		uint32_t pwm05; // word name
		struct {
			uint32_t busy_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t status_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM06 16'h18 */
	union {
		uint32_t pwm06; // word name
		struct {
			uint32_t irq_mask_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mode_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM07 16'h1C */
	union {
		uint32_t pwm07; // word name
		struct {
			uint32_t prescaler_1 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_1 : 8;
			uint32_t count_high_1 : 8;
			uint32_t num_period_1 : 8;
		};
	};
	/* PWM08 16'h20 */
	union {
		uint32_t pwm08; // word name
		struct {
			uint32_t trigger_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t irq_clear_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM09 16'h24 */
	union {
		uint32_t pwm09; // word name
		struct {
			uint32_t busy_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t status_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM10 16'h28 */
	union {
		uint32_t pwm10; // word name
		struct {
			uint32_t irq_mask_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mode_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM11 16'h2C */
	union {
		uint32_t pwm11; // word name
		struct {
			uint32_t prescaler_2 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_2 : 8;
			uint32_t count_high_2 : 8;
			uint32_t num_period_2 : 8;
		};
	};
	/* PWM12 16'h30 */
	union {
		uint32_t pwm12; // word name
		struct {
			uint32_t trigger_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t irq_clear_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM13 16'h34 */
	union {
		uint32_t pwm13; // word name
		struct {
			uint32_t busy_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t status_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM14 16'h38 */
	union {
		uint32_t pwm14; // word name
		struct {
			uint32_t irq_mask_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mode_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM15 16'h3C */
	union {
		uint32_t pwm15; // word name
		struct {
			uint32_t prescaler_3 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_3 : 8;
			uint32_t count_high_3 : 8;
			uint32_t num_period_3 : 8;
		};
	};
	/* PWM16 16'h40 */
	union {
		uint32_t pwm16; // word name
		struct {
			uint32_t trigger_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t irq_clear_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM17 16'h44 */
	union {
		uint32_t pwm17; // word name
		struct {
			uint32_t busy_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t status_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM18 16'h48 */
	union {
		uint32_t pwm18; // word name
		struct {
			uint32_t irq_mask_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mode_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM19 16'h4C */
	union {
		uint32_t pwm19; // word name
		struct {
			uint32_t prescaler_4 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_4 : 8;
			uint32_t count_high_4 : 8;
			uint32_t num_period_4 : 8;
		};
	};
	/* PWM20 16'h50 */
	union {
		uint32_t pwm20; // word name
		struct {
			uint32_t trigger_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t irq_clear_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM21 16'h54 */
	union {
		uint32_t pwm21; // word name
		struct {
			uint32_t busy_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t status_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM22 16'h58 */
	union {
		uint32_t pwm22; // word name
		struct {
			uint32_t irq_mask_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mode_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM23 16'h5C */
	union {
		uint32_t pwm23; // word name
		struct {
			uint32_t prescaler_5 : 5;
			uint32_t : 3; // padding bits
			uint32_t count_period_5 : 8;
			uint32_t count_high_5 : 8;
			uint32_t num_period_5 : 8;
		};
	};
	/* PWM24 16'h60 */
	union {
		uint32_t pwm24; // word name
		struct {
			uint32_t out_sel_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t out_sel_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t out_sel_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t out_sel_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* PWM25 16'h64 */
	union {
		uint32_t pwm25; // word name
		struct {
			uint32_t out_sel_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t out_sel_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM26 16'h68 [Unused] */
	uint32_t empty_word_pwm26;
	/* PWM27 16'h6C */
	union {
		uint32_t pwm27; // word name
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