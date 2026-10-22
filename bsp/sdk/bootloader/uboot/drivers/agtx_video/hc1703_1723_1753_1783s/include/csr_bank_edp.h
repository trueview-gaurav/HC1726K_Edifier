#ifndef CSR_BANK_EDP_H_
#define CSR_BANK_EDP_H_

#include <linux/types.h>

/***  C struct generated from edp  ***/
typedef struct csr_bank_edp {
	/* WORD_FRAME_START 9'h000 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 9'h004 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 9'h008 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 9'h00C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DOUBLE_BUF_UPDATE 9'h010 */
	union {
		uint32_t word_double_buf_update; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESOLUTION 9'h014 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORD_MODE 9'h018 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 4;
			uint32_t : 4; // padding bits
			uint32_t target : 1;
			uint32_t : 7; // padding bits
			uint32_t broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SWITCH_OFFSET 9'h01C */
	union {
		uint32_t word_switch_offset; // word name
		struct {
			uint32_t switch_offset : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SELECTION 9'h020 */
	union {
		uint32_t selection; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROI0_CROP_X 9'h024 */
	union {
		uint32_t roi0_crop_x; // word name
		struct {
			uint32_t roi0_crop_x_start : 16;
			uint32_t roi0_crop_x_end : 16;
		};
	};
	/* ROI0_CROP_Y 9'h028 */
	union {
		uint32_t roi0_crop_y; // word name
		struct {
			uint32_t roi0_crop_y_start : 16;
			uint32_t roi0_crop_y_end : 16;
		};
	};
	/* ROI1_CROP_X 9'h02C */
	union {
		uint32_t roi1_crop_x; // word name
		struct {
			uint32_t roi1_crop_x_start : 16;
			uint32_t roi1_crop_x_end : 16;
		};
	};
	/* ROI1_CROP_Y 9'h030 */
	union {
		uint32_t roi1_crop_y; // word name
		struct {
			uint32_t roi1_crop_y_start : 16;
			uint32_t roi1_crop_y_end : 16;
		};
	};
	/* EFUSE_VIOLATION0 9'h034 */
	union {
		uint32_t efuse_violation0; // word name
		struct {
			uint32_t efuse_dis_hdr_tab_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t efuse_dis_hdr_sbs_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t efuse_dis_hdr_lc_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t efuse_dis_hdr_li_violation : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* EFUSE_VIOLATION1 9'h038 */
	union {
		uint32_t efuse_violation1; // word name
		struct {
			uint32_t efuse_dis_hdr_pc_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t efuse_dis_hdr_pi_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankEdp;

#endif