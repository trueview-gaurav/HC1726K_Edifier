#ifndef CSR_BANK_TIMER_H_
#define CSR_BANK_TIMER_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from timer  ***/
typedef struct csr_bank_timer {
	/* TIMER00 10'h000 */
	union {
		uint32_t timer00; // word name
		struct {
			uint32_t trigger_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER01 10'h004 */
	union {
		uint32_t timer01; // word name
		struct {
			uint32_t irq_clear_match_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER02 10'h008 */
	union {
		uint32_t timer02; // word name
		struct {
			uint32_t status_match_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER03 10'h00C */
	union {
		uint32_t timer03; // word name
		struct {
			uint32_t irq_mask_match_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER04 10'h010 */
	union {
		uint32_t timer04; // word name
		struct {
			uint32_t status_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER05 10'h014 */
	union {
		uint32_t timer05; // word name
		struct {
			uint32_t count_value_0 : 32;
		};
	};
	/* TIMER06 10'h018 */
	union {
		uint32_t timer06; // word name
		struct {
			uint32_t mode_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t prescaler_0 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER07 10'h01C */
	union {
		uint32_t timer07; // word name
		struct {
			uint32_t count_load_0 : 32;
		};
	};
	/* TIMER08 10'h020 */
	union {
		uint32_t timer08; // word name
		struct {
			uint32_t trigger_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER09 10'h024 */
	union {
		uint32_t timer09; // word name
		struct {
			uint32_t irq_clear_match_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER10 10'h028 */
	union {
		uint32_t timer10; // word name
		struct {
			uint32_t status_match_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER11 10'h02C */
	union {
		uint32_t timer11; // word name
		struct {
			uint32_t irq_mask_match_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER12 10'h030 */
	union {
		uint32_t timer12; // word name
		struct {
			uint32_t status_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER13 10'h034 */
	union {
		uint32_t timer13; // word name
		struct {
			uint32_t count_value_1 : 32;
		};
	};
	/* TIMER14 10'h038 */
	union {
		uint32_t timer14; // word name
		struct {
			uint32_t mode_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t prescaler_1 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER15 10'h03C */
	union {
		uint32_t timer15; // word name
		struct {
			uint32_t count_load_1 : 32;
		};
	};
	/* TIMER16 10'h040 */
	union {
		uint32_t timer16; // word name
		struct {
			uint32_t trigger_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER17 10'h044 */
	union {
		uint32_t timer17; // word name
		struct {
			uint32_t irq_clear_match_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER18 10'h048 */
	union {
		uint32_t timer18; // word name
		struct {
			uint32_t status_match_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER19 10'h04C */
	union {
		uint32_t timer19; // word name
		struct {
			uint32_t irq_mask_match_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER20 10'h050 */
	union {
		uint32_t timer20; // word name
		struct {
			uint32_t status_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER21 10'h054 */
	union {
		uint32_t timer21; // word name
		struct {
			uint32_t count_value_2 : 32;
		};
	};
	/* TIMER22 10'h058 */
	union {
		uint32_t timer22; // word name
		struct {
			uint32_t mode_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t prescaler_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER23 10'h05C */
	union {
		uint32_t timer23; // word name
		struct {
			uint32_t count_load_2 : 32;
		};
	};
	/* TIMER24 10'h060 */
	union {
		uint32_t timer24; // word name
		struct {
			uint32_t trigger_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER25 10'h064 */
	union {
		uint32_t timer25; // word name
		struct {
			uint32_t irq_clear_match_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER26 10'h068 */
	union {
		uint32_t timer26; // word name
		struct {
			uint32_t status_match_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER27 10'h06C */
	union {
		uint32_t timer27; // word name
		struct {
			uint32_t irq_mask_match_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER28 10'h070 */
	union {
		uint32_t timer28; // word name
		struct {
			uint32_t status_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER29 10'h074 */
	union {
		uint32_t timer29; // word name
		struct {
			uint32_t count_value_3 : 32;
		};
	};
	/* TIMER30 10'h078 */
	union {
		uint32_t timer30; // word name
		struct {
			uint32_t mode_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t prescaler_3 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* TIMER31 10'h07C */
	union {
		uint32_t timer31; // word name
		struct {
			uint32_t count_load_3 : 32;
		};
	};
} CsrBankTimer;

#endif