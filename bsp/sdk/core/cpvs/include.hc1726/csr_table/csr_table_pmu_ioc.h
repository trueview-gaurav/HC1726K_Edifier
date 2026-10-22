/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PMU_IOC_H_
#define CSR_TABLE_PMU_IOC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pmu_ioc[] = {
	// WORD test_sel
	{ "tst_sel", 0x00000000, 2, 0, CSR_RW, 0x00000000 },
	{ "TEST_SEL", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_rtc_xin_pcfg
	{ "pad_rtc_xin_pcfg", 0x00000004, 18, 16, CSR_RW, 0x00000001 },
	{ "WORD_PAD_RTC_XIN_PCFG", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pmu_wakeup_pcfg
	{ "pad_pmu_wakeup_pu", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_pmu_wakeup_pd", 0x00000008, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_pmu_wakeup_pcfg", 0x00000008, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_PMU_WAKEUP_PCFG", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pmu_button_pcfg
	{ "pad_pmu_button_pu", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_pmu_button_pd", 0x0000000C, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_pmu_button_pcfg", 0x0000000C, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_PMU_BUTTON_PCFG", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pmu_pwr_ctrl_pcfg
	{ "pad_pmu_pwr_ctrl_pu", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "pad_pmu_pwr_ctrl_pd", 0x00000010, 1, 1, CSR_RW, 0x00000000 },
	{ "pad_pmu_pwr_ctrl_pcfg", 0x00000010, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_PMU_PWR_CTRL_PCFG", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pmu_resetb_pcfg
	{ "pad_pmu_resetb_pcfg", 0x00000014, 21, 16, CSR_RW, 0x0000000C },
	{ "WORD_PAD_PMU_RESETB_PCFG", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pmu_wakeup_iosel
	{ "pad_pmu_wakeup_iosel", 0x00000018, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_PMU_WAKEUP_IOSEL", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pmu_button_iosel
	{ "pad_pmu_button_iosel", 0x0000001C, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_PMU_BUTTON_IOSEL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_pad_pmu_pwr_ctrl_iosel
	{ "pad_pmu_pwr_ctrl_iosel", 0x00000020, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_PAD_PMU_PWR_CTRL_IOSEL", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PMU_IOC_H_
