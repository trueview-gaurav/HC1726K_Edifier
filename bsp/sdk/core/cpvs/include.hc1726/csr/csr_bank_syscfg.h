/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_SYSCFG_H_
#define CSR_BANK_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from syscfg  ***/
typedef struct csr_bank_syscfg {
	/* WORD_CHIP_ID 6'h00 */
	union {
		uint32_t word_chip_id; // word name
		struct {
			uint32_t chip_id : 32;
		};
	};
	/* WORD_CHIP_VERSION 6'h04 */
	union {
		uint32_t word_chip_version; // word name
		struct {
			uint32_t chip_version : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_BOOTSTRAP 6'h08 */
	union {
		uint32_t word_bootstrap; // word name
		struct {
			uint32_t bootstrap : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VERSION 6'h0C */
	union {
		uint32_t version; // word name
		struct {
			uint32_t hardware_version : 16;
			uint32_t software_version : 16;
		};
	};
	/* BOOT_STATUS 6'h10 */
	union {
		uint32_t boot_status; // word name
		struct {
			uint32_t boot_ctrl : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BOOT_ADDR 6'h14 */
	union {
		uint32_t boot_addr; // word name
		struct {
			uint32_t sec_boot_addr : 32;
		};
	};
	/* HRESIZE 6'h18 */
	union {
		uint32_t hresize; // word name
		struct {
			uint32_t hresize_sdc_0_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t hresize_sdc_1_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t hresize_usb_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG_MON_SET 6'h1C */
	union {
		uint32_t debug_mon_set; // word name
		struct {
			uint32_t debug_mon_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t debug_mon_rev : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON 6'h20 */
	union {
		uint32_t word_debug_mon; // word name
		struct {
			uint32_t debug_mon : 32;
		};
	};
	/* TEST_MON 6'h24 */
	union {
		uint32_t test_mon; // word name
		struct {
			uint32_t test_mon_0 : 32;
		};
	};
	/* TC_MODE 6'h28 */
	union {
		uint32_t tc_mode; // word name
		struct {
			uint32_t testchip_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PMU_EN 6'h2C */
	union {
		uint32_t pmu_en; // word name
		struct {
			uint32_t pmu_apb_read_en : 1;
			uint32_t : 7; // padding bits
			uint32_t pmu_apb_write_en : 1;
			uint32_t : 7; // padding bits
			uint32_t pmu_irq_en : 1;
			uint32_t : 7; // padding bits
			uint32_t pmu_gpio_i_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* HW_STRAP 6'h30 */
	union {
		uint32_t hw_strap; // word name
		struct {
			uint32_t normal_mode : 1;
			uint32_t fnct_mode : 1;
			uint32_t dc_scan_mode : 1;
			uint32_t ac_scan_mode : 1;
			uint32_t mbist_mode : 1;
			uint32_t bsd_mode : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankSyscfg;

#endif
