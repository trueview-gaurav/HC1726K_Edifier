#ifndef CSR_BANK_PMU_H_
#define CSR_BANK_PMU_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pmu  ***/
typedef struct csr_bank_pmu {
	/* CK_GEN 10'h000 */
	union {
		uint32_t ck_gen; // word name
		struct {
			uint32_t cken_amc : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_misc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_GEN 10'h004 */
	union {
		uint32_t rst_gen; // word name
		struct {
			uint32_t lv_rst_amc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_misc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 10'h008 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_button_click_event : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_button_press_event : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 10'h00C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_button_click_event : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_button_press_event : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STATUS 10'h010 */
	union {
		uint32_t irq_status; // word name
		struct {
			uint32_t status_button_click_event : 1;
			uint32_t : 7; // padding bits
			uint32_t status_button_press_event : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SLEEP_CTRL 10'h014 */
	union {
		uint32_t sleep_ctrl; // word name
		struct {
			uint32_t sleep_pulse : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* POWER_PERIOD 10'h018 */
	union {
		uint32_t power_period; // word name
		struct {
			uint32_t power_up_cnt : 5;
			uint32_t : 3; // padding bits
			uint32_t power_down_cnt : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWR_BUTTON_PERIOD 10'h01C */
	union {
		uint32_t pwr_button_period; // word name
		struct {
			uint32_t pwr_button_on_cnt : 4;
			uint32_t : 4; // padding bits
			uint32_t pwr_button_click_cnt : 3;
			uint32_t : 5; // padding bits
			uint32_t pwr_button_press_cnt : 3;
			uint32_t : 5; // padding bits
			uint32_t wakeup_by_pwr_button_cnt : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* PWR_WAKEUP_PERIOD 10'h020 */
	union {
		uint32_t pwr_wakeup_period; // word name
		struct {
			uint32_t wakeup_by_pwr_wakeup_cnt : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWR_WAKEUP_SET 10'h024 */
	union {
		uint32_t pwr_wakeup_set; // word name
		struct {
			uint32_t pwr_wakeup_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL_ENABLE 10'h028 */
	union {
		uint32_t ctrl_enable; // word name
		struct {
			uint32_t pwr_button_en : 1;
			uint32_t : 7; // padding bits
			uint32_t pwr_wakeup_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rtc2pmu_wakeup_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWR_BUTTON_DEBOUNCE 10'h02C */
	union {
		uint32_t pwr_button_debounce; // word name
		struct {
			uint32_t pwr_button_debounce_cnt : 8;
			uint32_t pwr_button_debounce_polarity : 1;
			uint32_t : 7; // padding bits
			uint32_t pwr_button_debounce_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWR_WAKEUP_DEBOUNCE 10'h030 */
	union {
		uint32_t pwr_wakeup_debounce; // word name
		struct {
			uint32_t pwr_wakeup_debounce_cnt : 8;
			uint32_t pwr_wakeup_debounce_polarity : 1;
			uint32_t : 7; // padding bits
			uint32_t pwr_wakeup_debounce_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_STATE_ENABLE 10'h034 */
	union {
		uint32_t wdt_state_enable; // word name
		struct {
			uint32_t pmu_wdt_hw_en_state_on : 1;
			uint32_t : 7; // padding bits
			uint32_t pmu_wdt_hw_en_state_standby : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATE_CLEAR 10'h038 */
	union {
		uint32_t state_clear; // word name
		struct {
			uint32_t power_on_method_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t power_off_method_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t power_lose_flag_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t uvlo_state_clear : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* STATE_RECORD 10'h03C */
	union {
		uint32_t state_record; // word name
		struct {
			uint32_t power_on_method : 3;
			uint32_t : 5; // padding bits
			uint32_t power_off_method : 2;
			uint32_t : 6; // padding bits
			uint32_t power_lose_flag : 1;
			uint32_t : 7; // padding bits
			uint32_t clk_sw_sel : 1;
			uint32_t clk_sw_lock : 1;
			uint32_t : 6; // padding bits
		};
	};
	/* UVLO_STATE_RECPRD 10'h040 */
	union {
		uint32_t uvlo_state_recprd; // word name
		struct {
			uint32_t uvlo_state : 32;
		};
	};
	/* DEBUG_SEL 10'h044 */
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
	/* DEBUG_DATA 10'h048 */
	union {
		uint32_t debug_data; // word name
		struct {
			uint32_t debug_mon : 32;
		};
	};
	/* ISO_EN 10'h04C */
	union {
		uint32_t iso_en; // word name
		struct {
			uint32_t scan_iso_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPmu;

#endif
