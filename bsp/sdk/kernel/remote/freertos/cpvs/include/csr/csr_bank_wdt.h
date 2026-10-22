#ifndef CSR_BANK_WDT_H_
#define CSR_BANK_WDT_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from wdt  ***/
typedef struct csr_bank_wdt {
	/* WDT00 10'h000 */
	union {
		uint32_t wdt00; // word name
		struct {
			uint32_t trigger : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT01 10'h004 */
	union {
		uint32_t wdt01; // word name
		struct {
			uint32_t irq_clear_wdt : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT02 10'h008 */
	union {
		uint32_t wdt02; // word name
		struct {
			uint32_t status_wdt : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT03 10'h00C */
	union {
		uint32_t wdt03; // word name
		struct {
			uint32_t lock_status : 1;
			uint32_t : 7; // padding bits
			uint32_t stage : 2;
			uint32_t : 6; // padding bits
			uint32_t count_value : 16;
		};
	};
	/* WDT04 10'h010 */
	union {
		uint32_t wdt04; // word name
		struct {
			uint32_t unlock_reg : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT05 10'h014 */
	union {
		uint32_t wdt05; // word name
		struct {
			uint32_t sw_disable : 1;
			uint32_t : 7; // padding bits
			uint32_t polarity : 1;
			uint32_t : 7; // padding bits
			uint32_t prescaler_0 : 4;
			uint32_t : 4; // padding bits
			uint32_t prescaler_1 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WDT06 10'h018 */
	union {
		uint32_t wdt06; // word name
		struct {
			uint32_t count_initial : 16;
			uint32_t count_stage1_min : 16;
		};
	};
	/* WDT07 10'h01C */
	union {
		uint32_t wdt07; // word name
		struct {
			uint32_t count_stage1_max : 16;
			uint32_t count_stage2 : 16;
		};
	};
	/* WDT08 10'h020 */
	union {
		uint32_t wdt08; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankWdt;

#endif