#ifndef CSR_BANK_PMU_WDT_H_
#define CSR_BANK_PMU_WDT_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pmu_wdt  ***/
typedef struct csr_bank_pmu_wdt {
	/* WDT_TRIGGER 10'h00 */
	union {
		uint32_t wdt_trigger; // word name
		struct {
			uint32_t trigger : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CLEAR 10'h04 */
	union {
		uint32_t clear; // word name
		struct {
			uint32_t pmu_wdt_state_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t aon_wdt_state_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL 10'h08 */
	union {
		uint32_t ctrl; // word name
		struct {
			uint32_t pmu_wdt_csr_en : 1;
			uint32_t : 7; // padding bits
			uint32_t aon_wdt_timeout_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PERIOD 10'h0C */
	union {
		uint32_t period; // word name
		struct {
			uint32_t cnt_th : 16;
			uint32_t rst_cnt_th : 16;
		};
	};
	/* STATE 10'h10 */
	union {
		uint32_t state; // word name
		struct {
			uint32_t pmu_wdt_state : 1;
			uint32_t : 7; // padding bits
			uint32_t aon_wdt_state : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMC_CTRL 10'h14 */
	union {
		uint32_t amc_ctrl; // word name
		struct {
			uint32_t shutdown_reset_en : 1;
			uint32_t : 7; // padding bits
			uint32_t shutdown_power_off_en : 1;
			uint32_t : 7; // padding bits
			uint32_t autobootup_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPmu_wdt;

#endif
