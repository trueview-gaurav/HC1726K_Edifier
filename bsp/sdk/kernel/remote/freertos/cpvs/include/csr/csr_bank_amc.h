#ifndef CSR_BANK_AMC_H_
#define CSR_BANK_AMC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from amc  ***/
typedef struct csr_bank_amc {
	/* ACM00 10'h000 [Unused] */
	uint32_t empty_word_acm00;
	/* IRQ_CLEAR 10'h004 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_psd_sync_code_error_event : 1;
			uint32_t irq_clear_psd_out_overrun_error_event : 1;
			uint32_t irq_clear_psd_fifo_over_error_event : 1;
			uint32_t irq_clear_psd_frame_size_error_event : 1;
			uint32_t irq_clear_psd_eol_error_event : 1;
			uint32_t irq_clear_psd_sol_error_event : 1;
			uint32_t irq_clear_psd_eof_error_event : 1;
			uint32_t irq_clear_psd_sof_error_event : 1;
			uint32_t irq_clear_lpmd_missing_pixel_error_event : 1;
			uint32_t irq_clear_wdt_timeout_error_event : 1;
			uint32_t irq_clear_psd_eol_alarm_event : 1;
			uint32_t irq_clear_psd_sol_alarm_event : 1;
			uint32_t irq_clear_psd_eof_alarm_event : 1;
			uint32_t irq_clear_psd_sof_alarm_event : 1;
			uint32_t irq_clear_lpmd_detect_motion_alarm_event : 1;
			uint32_t irq_clear_lpmd_frame_end_alarm_event : 1;
			uint32_t irq_clear_rtc_periodic_time_alarm_event : 1;
			uint32_t irq_clear_external_wakeup_alarm_event : 1;
			uint32_t irq_clear_external_button_alarm_event : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 10'h008 */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_psd_sync_code_error_event : 1;
			uint32_t irq_mask_psd_out_overrun_error_event : 1;
			uint32_t irq_mask_psd_fifo_over_error_event : 1;
			uint32_t irq_mask_psd_frame_size_error_event : 1;
			uint32_t irq_mask_psd_eol_error_event : 1;
			uint32_t irq_mask_psd_sol_error_event : 1;
			uint32_t irq_mask_psd_eof_error_event : 1;
			uint32_t irq_mask_psd_sof_error_event : 1;
			uint32_t irq_mask_lpmd_missing_pixel_error_event : 1;
			uint32_t irq_mask_wdt_timeout_error_event : 1;
			uint32_t irq_mask_psd_eol_alarm_event : 1;
			uint32_t irq_mask_psd_sol_alarm_event : 1;
			uint32_t irq_mask_psd_eof_alarm_event : 1;
			uint32_t irq_mask_psd_sof_alarm_event : 1;
			uint32_t irq_mask_lpmd_detect_motion_alarm_event : 1;
			uint32_t irq_mask_lpmd_frame_end_alarm_event : 1;
			uint32_t irq_mask_rtc_periodic_time_alarm_event : 1;
			uint32_t irq_mask_external_wakeup_alarm_event : 1;
			uint32_t irq_mask_external_button_alarm_event : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STATUS 10'h00C */
	union {
		uint32_t irq_status; // word name
		struct {
			uint32_t status_psd_sync_code_error_event : 1;
			uint32_t status_psd_out_overrun_error_event : 1;
			uint32_t status_psd_fifo_over_error_event : 1;
			uint32_t status_psd_frame_size_error_event : 1;
			uint32_t status_psd_eol_error_event : 1;
			uint32_t status_psd_sol_error_event : 1;
			uint32_t status_psd_eof_error_event : 1;
			uint32_t status_psd_sof_error_event : 1;
			uint32_t status_lpmd_missing_pixel_error_event : 1;
			uint32_t status_wdt_timeout_error_event : 1;
			uint32_t status_psd_eol_alarm_event : 1;
			uint32_t status_psd_sol_alarm_event : 1;
			uint32_t status_psd_eof_alarm_event : 1;
			uint32_t status_psd_sof_alarm_event : 1;
			uint32_t status_lpmd_detect_motion_alarm_event : 1;
			uint32_t status_lpmd_frame_end_alarm_event : 1;
			uint32_t status_rtc_periodic_time_alarm_event : 1;
			uint32_t status_external_wakeup_alarm_event : 1;
			uint32_t status_external_button_alarm_event : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMC04 10'h010 [Unused] */
	uint32_t empty_word_amc04;
	/* AMC05 10'h014 [Unused] */
	uint32_t empty_word_amc05;
	/* SLEEP_AON 10'h018 */
	union {
		uint32_t sleep_aon; // word name
		struct {
			uint32_t sleep_aon_pluse : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMC07 10'h01C [Unused] */
	uint32_t empty_word_amc07;
	/* WDT_EN 10'h020 */
	union {
		uint32_t wdt_en; // word name
		struct {
			uint32_t wdt_en_src : 1;
			uint32_t : 7; // padding bits
			uint32_t wdt_en_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMC09 10'h024 [Unused] */
	uint32_t empty_word_amc09;
	/* WORD_PWR1P8_CHARGING_PERIOD 10'h028 */
	union {
		uint32_t word_pwr1p8_charging_period; // word name
		struct {
			uint32_t pwr1p8_charging_period : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWR3P3_CHARGING_PERIOD 10'h02C */
	union {
		uint32_t word_pwr3p3_charging_period; // word name
		struct {
			uint32_t pwr3p3_charging_period : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWR1P8_CHARGING_TIMING_SCALER 10'h030 */
	union {
		uint32_t word_pwr1p8_charging_timing_scaler; // word name
		struct {
			uint32_t pwr1p8_charging_timing_scaler : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWR3P3_CHARGING_TIMING_SCALER 10'h034 */
	union {
		uint32_t word_pwr3p3_charging_timing_scaler; // word name
		struct {
			uint32_t pwr3p3_charging_timing_scaler : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWR_SWITCHING_BLANKING_PERIOD 10'h038 */
	union {
		uint32_t word_pwr_switching_blanking_period; // word name
		struct {
			uint32_t pwr_switching_blanking_period : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWR_SWITCHING_BLANKING_TIMING_SCALER 10'h03C */
	union {
		uint32_t word_pwr_switching_blanking_timing_scaler; // word name
		struct {
			uint32_t pwr_switching_blanking_timing_scaler : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWRON_WAKEUP_PERIOD 10'h040 */
	union {
		uint32_t word_pwron_wakeup_period; // word name
		struct {
			uint32_t pwron_wakeup_period : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWROFF_BUTTON_PERIOD 10'h044 */
	union {
		uint32_t word_pwroff_button_period; // word name
		struct {
			uint32_t pwroff_button_period : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWRON_BUTTON_PERIOD 10'h048 */
	union {
		uint32_t word_pwron_button_period; // word name
		struct {
			uint32_t pwron_button_period : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWROFF_BUTTON_TIMING_SCALER 10'h04C */
	union {
		uint32_t word_pwroff_button_timing_scaler; // word name
		struct {
			uint32_t pwroff_button_timing_scaler : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWRON_BUTTON_TIMING_SCALER 10'h050 */
	union {
		uint32_t word_pwron_button_timing_scaler; // word name
		struct {
			uint32_t pwron_button_timing_scaler : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWROFF_BUTTON_EXTRA_PERIOD 10'h054 */
	union {
		uint32_t word_pwroff_button_extra_period; // word name
		struct {
			uint32_t pwroff_button_extra_period : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PWRON_BUTTON_EXTRA_PERIOD 10'h058 */
	union {
		uint32_t word_pwron_button_extra_period; // word name
		struct {
			uint32_t pwron_button_extra_period : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMC23 10'h05C [Unused] */
	uint32_t empty_word_amc23;
	/* AMC24 10'h060 [Unused] */
	uint32_t empty_word_amc24;
	/* AMC25 10'h064 [Unused] */
	uint32_t empty_word_amc25;
	/* PWR_MODE 10'h068 */
	union {
		uint32_t pwr_mode; // word name
		struct {
			uint32_t pwr_wakeup_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t pwr_button_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t pwd_wakeup_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AMC27 10'h06C [Unused] */
	uint32_t empty_word_amc27;
	/* AMC28 10'h070 [Unused] */
	uint32_t empty_word_amc28;
	/* AMC29 10'h074 [Unused] */
	uint32_t empty_word_amc29;
	/* EVENT_ERROR_MASK 10'h078 */
	union {
		uint32_t event_error_mask; // word name
		struct {
			uint32_t psd_sync_code_error_mask : 1;
			uint32_t psd_out_overrun_error_mask : 1;
			uint32_t psd_fifo_over_error_mask : 1;
			uint32_t psd_frame_size_error_mask : 1;
			uint32_t psd_eol_error_mask : 1;
			uint32_t psd_sol_error_mask : 1;
			uint32_t psd_eof_error_mask : 1;
			uint32_t psd_sof_error_mask : 1;
			uint32_t lpmd_missing_pixel_error_mask : 1;
			uint32_t wdt_timeout_error_mask : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EVENT_ALARM_MASK 10'h07C */
	union {
		uint32_t event_alarm_mask; // word name
		struct {
			uint32_t psd_eol_alarm_mask : 1;
			uint32_t psd_sol_alarm_mask : 1;
			uint32_t psd_eof_alarm_mask : 1;
			uint32_t psd_sof_alarm_mask : 1;
			uint32_t lpmd_detect_motion_alarm_mask : 1;
			uint32_t lpmd_frame_end_alarm_mask : 1;
			uint32_t rtc_periodic_time_alarm_mask : 1;
			uint32_t pwr_wakeup_alarm_mask : 1;
			uint32_t pwr_button_alarm_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_EVENT_CLEAR 10'h080 */
	union {
		uint32_t word_event_clear; // word name
		struct {
			uint32_t event_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG_SEL 10'h084 */
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
	/* DEBUG_DATA 10'h088 */
	union {
		uint32_t debug_data; // word name
		struct {
			uint32_t debug_mon : 32;
		};
	};
	/* AMC35 10'h08C [Unused] */
	uint32_t empty_word_amc35;
	/* AMC36 10'h090 [Unused] */
	uint32_t empty_word_amc36;
	/* AMC37 10'h094 [Unused] */
	uint32_t empty_word_amc37;
	/* WORD_RESERVED_0 10'h098 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_1 10'h09C */
	union {
		uint32_t word_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAmc;

#endif