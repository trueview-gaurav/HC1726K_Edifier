/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ENC_H_
#define CSR_BANK_ENC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from enc  ***/
typedef struct csr_bank_enc {
	/* ENC001 10'h000 */
	union {
		uint32_t enc001; // word name
		struct {
			uint32_t encoder_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC002 10'h004 */
	union {
		uint32_t enc002; // word name
		struct {
			uint32_t efuse_enc_pix_rate_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC003 10'h008 */
	union {
		uint32_t enc003; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC004 10'h00C */
	union {
		uint32_t enc004; // word name
		struct {
			uint32_t debug_mon_reg : 32;
		};
	};
	/* MEM_CTRL 10'h010 */
	union {
		uint32_t mem_ctrl; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_0 10'h014 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* SRC_PROC_MONO 10'h018 */
	union {
		uint32_t src_proc_mono; // word name
		struct {
			uint32_t mono_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_COVER_ROI_0_EN 10'h01C */
	union {
		uint32_t enc_cover_roi_0_en; // word name
		struct {
			uint32_t cover_roi_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_COVER_ROI_0_START 10'h020 */
	union {
		uint32_t enc_cover_roi_0_start; // word name
		struct {
			uint32_t cover_roi_0_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t cover_roi_0_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ENC_COVER_ROI_0_END 10'h024 */
	union {
		uint32_t enc_cover_roi_0_end; // word name
		struct {
			uint32_t cover_roi_0_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t cover_roi_0_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ENC_COVER_ROI_0_COLOR 10'h028 */
	union {
		uint32_t enc_cover_roi_0_color; // word name
		struct {
			uint32_t cover_roi_0_color_y : 8;
			uint32_t cover_roi_0_color_u : 8;
			uint32_t cover_roi_0_color_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_COVER_ROI_1_EN 10'h02C */
	union {
		uint32_t enc_cover_roi_1_en; // word name
		struct {
			uint32_t cover_roi_1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_COVER_ROI_1_START 10'h030 */
	union {
		uint32_t enc_cover_roi_1_start; // word name
		struct {
			uint32_t cover_roi_1_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t cover_roi_1_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ENC_COVER_ROI_1_END 10'h034 */
	union {
		uint32_t enc_cover_roi_1_end; // word name
		struct {
			uint32_t cover_roi_1_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t cover_roi_1_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ENC_COVER_ROI_1_COLOR 10'h038 */
	union {
		uint32_t enc_cover_roi_1_color; // word name
		struct {
			uint32_t cover_roi_1_color_y : 8;
			uint32_t cover_roi_1_color_u : 8;
			uint32_t cover_roi_1_color_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_COVER_ROI_2_EN 10'h03C */
	union {
		uint32_t enc_cover_roi_2_en; // word name
		struct {
			uint32_t cover_roi_2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_COVER_ROI_2_START 10'h040 */
	union {
		uint32_t enc_cover_roi_2_start; // word name
		struct {
			uint32_t cover_roi_2_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t cover_roi_2_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ENC_COVER_ROI_2_END 10'h044 */
	union {
		uint32_t enc_cover_roi_2_end; // word name
		struct {
			uint32_t cover_roi_2_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t cover_roi_2_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ENC_COVER_ROI_2_COLOR 10'h048 */
	union {
		uint32_t enc_cover_roi_2_color; // word name
		struct {
			uint32_t cover_roi_2_color_y : 8;
			uint32_t cover_roi_2_color_u : 8;
			uint32_t cover_roi_2_color_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_COVER_ROI_3_EN 10'h04C */
	union {
		uint32_t enc_cover_roi_3_en; // word name
		struct {
			uint32_t cover_roi_3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_COVER_ROI_3_START 10'h050 */
	union {
		uint32_t enc_cover_roi_3_start; // word name
		struct {
			uint32_t cover_roi_3_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t cover_roi_3_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ENC_COVER_ROI_3_END 10'h054 */
	union {
		uint32_t enc_cover_roi_3_end; // word name
		struct {
			uint32_t cover_roi_3_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t cover_roi_3_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ENC_COVER_ROI_3_COLOR 10'h058 */
	union {
		uint32_t enc_cover_roi_3_color; // word name
		struct {
			uint32_t cover_roi_3_color_y : 8;
			uint32_t cover_roi_3_color_u : 8;
			uint32_t cover_roi_3_color_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_RESERVED_1 10'h05C */
	union {
		uint32_t enc_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* ENC_RESERVED_2 10'h060 */
	union {
		uint32_t enc_reserved_2; // word name
		struct {
			uint32_t reserved_2 : 32;
		};
	};
} CsrBankEnc;

#endif