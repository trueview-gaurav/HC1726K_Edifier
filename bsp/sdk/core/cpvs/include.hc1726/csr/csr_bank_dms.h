/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DMS_H_
#define CSR_BANK_DMS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dms  ***/
typedef struct csr_bank_dms {
	/* DMS00 6'h00 */
	union {
		uint32_t dms00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMS01 6'h04 */
	union {
		uint32_t dms01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMS02 6'h08 */
	union {
		uint32_t dms02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMS03 6'h0C */
	union {
		uint32_t dms03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMS04 6'h10 */
	union {
		uint32_t dms04; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* DMS05 6'h14 */
	union {
		uint32_t dms05; // word name
		struct {
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_bayer_phase : 2;
			uint32_t : 6; // padding bits
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMS06 6'h18 */
	union {
		uint32_t dms06; // word name
		struct {
			uint32_t g_var_gain : 4;
			uint32_t : 4; // padding bits
			uint32_t fcs_threshold : 5;
			uint32_t : 3; // padding bits
			uint32_t inter_conf_slope : 6;
			uint32_t : 2; // padding bits
			uint32_t fcs_offset : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* DMS07 6'h1C */
	union {
		uint32_t dms07; // word name
		struct {
			uint32_t g_at_m_inter_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t m_at_m_inter_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t m_at_g_inter_ratio : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMS08 6'h20 */
	union {
		uint32_t dms08; // word name
		struct {
			uint32_t g_at_m_soft_clip_slope : 5;
			uint32_t : 3; // padding bits
			uint32_t m_at_m_soft_clip_slope : 5;
			uint32_t : 3; // padding bits
			uint32_t m_at_g_soft_clip_slope : 5;
			uint32_t : 3; // padding bits
			uint32_t m_at_g_gradient_src_ratio : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* DMS09 6'h24 */
	union {
		uint32_t dms09; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* DMS10 6'h28 [Unused] */
	uint32_t empty_word_dms10;
	/* DMS11 6'h2C [Unused] */
	uint32_t empty_word_dms11;
	/* DMS12 6'h30 [Unused] */
	uint32_t empty_word_dms12;
	/* DMS13 6'h34 [Unused] */
	uint32_t empty_word_dms13;
	/* DMS14 6'h38 [Unused] */
	uint32_t empty_word_dms14;
	/* DMS15 6'h3C [Unused] */
	uint32_t empty_word_dms15;
} CsrBankDms;

#endif