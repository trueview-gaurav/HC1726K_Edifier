/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PMU_IOC_H_
#define CSR_BANK_PMU_IOC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pmu_ioc  ***/
typedef struct csr_bank_pmu_ioc {
	/* TEST_SEL 10'h000 */
	union {
		uint32_t test_sel; // word name
		struct {
			uint32_t tst_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_RTC_XIN_PCFG 10'h004 */
	union {
		uint32_t word_pad_rtc_xin_pcfg; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_rtc_xin_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PMU_WAKEUP_PCFG 10'h008 */
	union {
		uint32_t word_pad_pmu_wakeup_pcfg; // word name
		struct {
			uint32_t pad_pmu_wakeup_pu : 1;
			uint32_t pad_pmu_wakeup_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pmu_wakeup_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PMU_BUTTON_PCFG 10'h00C */
	union {
		uint32_t word_pad_pmu_button_pcfg; // word name
		struct {
			uint32_t pad_pmu_button_pu : 1;
			uint32_t pad_pmu_button_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pmu_button_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PMU_PWR_CTRL_PCFG 10'h010 */
	union {
		uint32_t word_pad_pmu_pwr_ctrl_pcfg; // word name
		struct {
			uint32_t pad_pmu_pwr_ctrl_pu : 1;
			uint32_t pad_pmu_pwr_ctrl_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pmu_pwr_ctrl_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PMU_RESETB_PCFG 10'h014 */
	union {
		uint32_t word_pad_pmu_resetb_pcfg; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pmu_resetb_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PMU_WAKEUP_IOSEL 10'h018 */
	union {
		uint32_t word_pad_pmu_wakeup_iosel; // word name
		struct {
			uint32_t pad_pmu_wakeup_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PMU_BUTTON_IOSEL 10'h01C */
	union {
		uint32_t word_pad_pmu_button_iosel; // word name
		struct {
			uint32_t pad_pmu_button_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PMU_PWR_CTRL_IOSEL 10'h020 */
	union {
		uint32_t word_pad_pmu_pwr_ctrl_iosel; // word name
		struct {
			uint32_t pad_pmu_pwr_ctrl_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPmu_ioc;

#endif