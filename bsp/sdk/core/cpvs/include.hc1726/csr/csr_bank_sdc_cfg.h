/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_SDC_CFG_H_
#define CSR_BANK_SDC_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from sdc_cfg  ***/
typedef struct csr_bank_sdc_cfg {
	/* CFG_00 16'h000 */
	union {
		uint32_t cfg_00; // word name
		struct {
			uint32_t cken_sdc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_01 16'h004 */
	union {
		uint32_t cfg_01; // word name
		struct {
			uint32_t sdc_spl_phase_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t sdc_drv_phase_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_02 16'h008 */
	union {
		uint32_t cfg_02; // word name
		struct {
			uint32_t sd2_wp_from_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t sd_wp_from_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t sd2_cd_from_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t sd_cd_from_csr : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CFG_03 16'h00C */
	union {
		uint32_t cfg_03; // word name
		struct {
			uint32_t en_sd2_wp_from_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t en_sd_wp_from_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t en_sd2_cd_from_csr : 1;
			uint32_t : 7; // padding bits
			uint32_t en_sd_cd_from_csr : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CFG_04 16'h010 [Unused] */
	uint32_t empty_word_cfg_04;
	/* CFG_05 16'h014 [Unused] */
	uint32_t empty_word_cfg_05;
	/* CFG_06 16'h018 [Unused] */
	uint32_t empty_word_cfg_06;
	/* CFG_07 16'h01C [Unused] */
	uint32_t empty_word_cfg_07;
	/* CFG_08 16'h020 [Unused] */
	uint32_t empty_word_cfg_08;
	/* CFG_09 16'h024 [Unused] */
	uint32_t empty_word_cfg_09;
	/* CFG_10 16'h028 [Unused] */
	uint32_t empty_word_cfg_10;
	/* CFG_11 16'h02C [Unused] */
	uint32_t empty_word_cfg_11;
	/* CFG_12 16'h030 [Unused] */
	uint32_t empty_word_cfg_12;
	/* CFG_13 16'h034 [Unused] */
	uint32_t empty_word_cfg_13;
	/* MEM_WRAPPER 16'h038 */
	union {
		uint32_t mem_wrapper; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankSdc_cfg;

#endif