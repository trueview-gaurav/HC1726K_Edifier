/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PMU_H_
#define CSR_TABLE_PMU_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pmu[] = {
	// WORD ck_gen
	{ "cken_amc", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_misc", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "CK_GEN", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD rst_gen
	{ "lv_rst_amc", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_misc", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "RST_GEN", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_button_click_event", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_button_press_event", 0x00000008, 8, 8, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_button_click_event", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_button_press_event", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_status
	{ "status_button_click_event", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "status_button_press_event", 0x00000010, 8, 8, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD sleep_ctrl
	{ "sleep_pulse", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "SLEEP_CTRL", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD power_period
	{ "power_up_cnt", 0x00000018, 4, 0, CSR_RW, 0x00000009 },
	{ "power_down_cnt", 0x00000018, 12, 8, CSR_RW, 0x00000009 },
	{ "POWER_PERIOD", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD pwr_button_period
	{ "pwr_button_on_cnt", 0x0000001C, 3, 0, CSR_RW, 0x00000004 },
	{ "pwr_button_click_cnt", 0x0000001C, 10, 8, CSR_RW, 0x00000001 },
	{ "pwr_button_press_cnt", 0x0000001C, 18, 16, CSR_RW, 0x00000004 },
	{ "wakeup_by_pwr_button_cnt", 0x0000001C, 28, 24, CSR_RW, 0x00000001 },
	{ "PWR_BUTTON_PERIOD", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pwr_wakeup_period
	{ "wakeup_by_pwr_wakeup_cnt", 0x00000020, 2, 0, CSR_RW, 0x00000003 },
	{ "PWR_WAKEUP_PERIOD", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD pwr_wakeup_set
	{ "pwr_wakeup_mode", 0x00000024, 0, 0, CSR_RW, 0x00000001 },
	{ "PWR_WAKEUP_SET", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl_enable
	{ "pwr_button_en", 0x00000028, 0, 0, CSR_RW, 0x00000001 },
	{ "pwr_wakeup_en", 0x00000028, 8, 8, CSR_RW, 0x00000001 },
	{ "rtc2pmu_wakeup_en", 0x00000028, 16, 16, CSR_RW, 0x00000001 },
	{ "CTRL_ENABLE", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD pwr_button_debounce
	{ "pwr_button_debounce_cnt", 0x0000002C, 7, 0, CSR_RW, 0x0000000A },
	{ "pwr_button_debounce_polarity", 0x0000002C, 8, 8, CSR_RW, 0x00000000 },
	{ "pwr_button_debounce_bypass", 0x0000002C, 16, 16, CSR_RW, 0x00000000 },
	{ "PWR_BUTTON_DEBOUNCE", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pwr_wakeup_debounce
	{ "pwr_wakeup_debounce_cnt", 0x00000030, 7, 0, CSR_RW, 0x00000002 },
	{ "pwr_wakeup_debounce_polarity", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "pwr_wakeup_debounce_bypass", 0x00000030, 16, 16, CSR_RW, 0x00000000 },
	{ "PWR_WAKEUP_DEBOUNCE", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdt_state_enable
	{ "pmu_wdt_hw_en_state_on", 0x00000034, 0, 0, CSR_RW, 0x00000001 },
	{ "pmu_wdt_hw_en_state_standby", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "WDT_STATE_ENABLE", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD state_clear
	{ "power_on_method_clear", 0x00000038, 0, 0, CSR_W1P, 0x00000000 },
	{ "power_off_method_clear", 0x00000038, 8, 8, CSR_W1P, 0x00000000 },
	{ "power_lose_flag_clear", 0x00000038, 16, 16, CSR_W1P, 0x00000000 },
	{ "uvlo_state_clear", 0x00000038, 24, 24, CSR_W1P, 0x00000000 },
	{ "STATE_CLEAR", 0x00000038, 31, 0, CSR_W1P, 0x00000000 },
	// WORD state_record
	{ "power_on_method", 0x0000003C, 2, 0, CSR_RO, 0x00000000 },
	{ "power_off_method", 0x0000003C, 9, 8, CSR_RO, 0x00000000 },
	{ "power_lose_flag", 0x0000003C, 16, 16, CSR_RO, 0x00000000 },
	{ "clk_sw_sel", 0x0000003C, 24, 24, CSR_RO, 0x00000000 },
	{ "clk_sw_lock", 0x0000003C, 25, 25, CSR_RO, 0x00000000 },
	{ "STATE_RECORD", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD uvlo_state_recprd
	{ "uvlo_state", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "UVLO_STATE_RECPRD", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_sel
	{ "debug_mon_sel", 0x00000044, 1, 0, CSR_RW, 0x00000000 },
	{ "DEBUG_SEL", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_data
	{ "debug_mon", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_DATA", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD iso_en
	{ "scan_iso_en", 0x0000004C, 0, 0, CSR_RW, 0x00000001 },
	{ "ISO_EN", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PMU_H_
