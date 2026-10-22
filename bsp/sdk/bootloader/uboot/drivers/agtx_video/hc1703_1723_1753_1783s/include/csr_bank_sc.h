#ifndef CSR_BANK_SC_H_
#define CSR_BANK_SC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from sc  ***/
typedef struct csr_bank_sc {
	/* WORD_FRAME_START 8'h00 */
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
	/* IRQ_CLEAR 8'h04 */
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
	/* STATUS 8'h08 */
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
	/* IRQ_MASK 8'h0C */
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
	/* SCALING_MODE 8'h10 */
	union {
		uint32_t scaling_mode; // word name
		struct {
			uint32_t up_scaling_hor : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t up_scaling_ver : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RES_I 8'h14 */
	union {
		uint32_t res_i; // word name
		struct {
			uint32_t width_i : 16;
			uint32_t height_i : 16;
		};
	};
	/* RES_O 8'h18 */
	union {
		uint32_t res_o; // word name
		struct {
			uint32_t width_o : 16;
			uint32_t height_o : 16;
		};
	};
	/* INI_PHASE_H 8'h1C */
	union {
		uint32_t ini_phase_h; // word name
		struct {
			uint32_t ini_phase_hor : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* INI_PHASE_V 8'h20 */
	union {
		uint32_t ini_phase_v; // word name
		struct {
			uint32_t ini_phase_ver : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PHASE_STEP_H 8'h24 */
	union {
		uint32_t phase_step_h; // word name
		struct {
			uint32_t phase_step_hor : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* PHASE_STEP_V 8'h28 */
	union {
		uint32_t phase_step_v; // word name
		struct {
			uint32_t phase_step_ver : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* INI_PHASE_DS_H 8'h2C */
	union {
		uint32_t ini_phase_ds_h; // word name
		struct {
			uint32_t ini_filt_phase_ds_hor : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* INI_PHASE_DS_V 8'h30 */
	union {
		uint32_t ini_phase_ds_v; // word name
		struct {
			uint32_t ini_filt_phase_ds_ver : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PHASE_STEP_DS_H 8'h34 */
	union {
		uint32_t phase_step_ds_h; // word name
		struct {
			uint32_t filt_phase_step_ds_hor : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PHASE_STEP_DS_V 8'h38 */
	union {
		uint32_t phase_step_ds_v; // word name
		struct {
			uint32_t filt_phase_step_ds_ver : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* INI_CNT_H_0 8'h3C */
	union {
		uint32_t ini_cnt_h_0; // word name
		struct {
			uint32_t ini_cnt_0_hor : 8;
			uint32_t ini_cnt_1_hor : 8;
			uint32_t ini_cnt_2_hor : 8;
			uint32_t ini_cnt_3_hor : 8;
		};
	};
	/* INI_CNT_H_1 8'h40 */
	union {
		uint32_t ini_cnt_h_1; // word name
		struct {
			uint32_t ini_cnt_4_hor : 8;
			uint32_t ini_cnt_5_hor : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* INI_CNT_V_0 8'h44 */
	union {
		uint32_t ini_cnt_v_0; // word name
		struct {
			uint32_t ini_cnt_0_ver : 8;
			uint32_t ini_cnt_1_ver : 8;
			uint32_t ini_cnt_2_ver : 8;
			uint32_t ini_cnt_3_ver : 8;
		};
	};
	/* INI_CNT_V_1 8'h48 */
	union {
		uint32_t ini_cnt_v_1; // word name
		struct {
			uint32_t ini_cnt_4_ver : 8;
			uint32_t ini_cnt_5_ver : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CROP_I_RES 8'h4C */
	union {
		uint32_t crop_i_res; // word name
		struct {
			uint32_t width_i_before_crop : 16;
			uint32_t height_i_before_crop : 16;
		};
	};
	/* CROP_I_LR 8'h50 */
	union {
		uint32_t crop_i_lr; // word name
		struct {
			uint32_t crop_i_left : 16;
			uint32_t crop_i_right : 16;
		};
	};
	/* CROP_I_UD 8'h54 */
	union {
		uint32_t crop_i_ud; // word name
		struct {
			uint32_t crop_i_up : 16;
			uint32_t crop_i_down : 16;
		};
	};
	/* CROP_O_LR 8'h58 */
	union {
		uint32_t crop_o_lr; // word name
		struct {
			uint32_t crop_o_left : 16;
			uint32_t crop_o_right : 16;
		};
	};
	/* CROP_O_UD 8'h5C */
	union {
		uint32_t crop_o_ud; // word name
		struct {
			uint32_t crop_o_up : 16;
			uint32_t crop_o_down : 16;
		};
	};
	/* WORD_DEBUG_MON_SEL 8'h60 */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_0 8'h64 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
} CsrBankSc;

#endif