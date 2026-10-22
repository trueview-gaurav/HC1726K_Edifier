/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_RTC_H_
#define CSR_TABLE_RTC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_rtc[] = {
	// WORD rtc_ctrl
	{ "run_stop", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "read", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "write", 0x00000000, 16, 16, CSR_W1P, 0x00000000 },
	{ "RTC_CTRL", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD rtc_state
	{ "counting_busy", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "read_done", 0x00000004, 8, 8, CSR_RO, 0x00000000 },
	{ "write_done", 0x00000004, 16, 16, CSR_RO, 0x00000000 },
	{ "RTC_STATE", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD rtc_rst_state
	{ "rst_state", 0x00000008, 31, 0, CSR_RW, 0xB0075CE5 },
	{ "RTC_RST_STATE", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_alarm_cpu", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_alarm_pmu", 0x0000000C, 8, 8, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_alarm_cpu", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_alarm_pmu", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "IRQ_MASK", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_status
	{ "status_match_alarm_cpu", 0x00000014, 0, 0, CSR_RO, 0x00000000 },
	{ "status_match_alarm_pmu", 0x00000014, 8, 8, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD time_write
	{ "time_sec_write", 0x00000018, 5, 0, CSR_RW, 0x00000000 },
	{ "time_min_write", 0x00000018, 11, 6, CSR_RW, 0x00000000 },
	{ "time_hour_write", 0x00000018, 16, 12, CSR_RW, 0x00000000 },
	{ "time_day_write", 0x00000018, 31, 17, CSR_RW, 0x00000000 },
	{ "TIME_WRITE", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD time_read
	{ "time_sec_read", 0x0000001C, 5, 0, CSR_RO, 0x00000000 },
	{ "time_min_read", 0x0000001C, 11, 6, CSR_RO, 0x00000000 },
	{ "time_hour_read", 0x0000001C, 16, 12, CSR_RO, 0x00000000 },
	{ "time_day_read", 0x0000001C, 31, 17, CSR_RO, 0x00000000 },
	{ "TIME_READ", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD alarm_cpu
	{ "alarm_cpu_sec_th", 0x00000020, 5, 0, CSR_RW, 0x0000003B },
	{ "alarm_cpu_min_th", 0x00000020, 11, 6, CSR_RW, 0x0000003B },
	{ "alarm_cpu_hour_th", 0x00000020, 16, 12, CSR_RW, 0x00000017 },
	{ "alarm_cpu_day_th", 0x00000020, 31, 17, CSR_RW, 0x00007FFF },
	{ "ALARM_CPU", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD alarm_pmu
	{ "alarm_pmu_sec_th", 0x00000024, 5, 0, CSR_RW, 0x0000003B },
	{ "alarm_pmu_min_th", 0x00000024, 11, 6, CSR_RW, 0x0000003B },
	{ "alarm_pmu_hour_th", 0x00000024, 16, 12, CSR_RW, 0x00000017 },
	{ "alarm_pmu_day_th", 0x00000024, 31, 17, CSR_RW, 0x00007FFF },
	{ "ALARM_PMU", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_RTC_H_
