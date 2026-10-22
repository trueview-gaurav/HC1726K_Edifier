/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_VP_H_
#define CSR_BANK_VP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from vp  ***/
typedef struct csr_bank_vp {
	/* WORD_DEBUG_MON_SEL 10'h000 */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MEM_LP_CTRL 10'h004 */
	union {
		uint32_t mem_lp_ctrl; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BUF_UPDATE 10'h008 */
	union {
		uint32_t buf_update; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DHZ_MUX 10'h00C */
	union {
		uint32_t dhz_mux; // word name
		struct {
			uint32_t dhz_mux_sel_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_MUX 10'h010 */
	union {
		uint32_t mcvp_mux; // word name
		struct {
			uint32_t mcvp_mux_sel_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UNPACKER_MUX 10'h014 */
	union {
		uint32_t unpacker_mux; // word name
		struct {
			uint32_t unpacker_mux_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPPUP0_MUX 10'h018 */
	union {
		uint32_t vppup0_mux; // word name
		struct {
			uint32_t vppup0_mux_sel_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW0_MUX 10'h01C */
	union {
		uint32_t vpw0_mux; // word name
		struct {
			uint32_t vpw0_mux_sel_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW1_MUX 10'h020 */
	union {
		uint32_t vpw1_mux; // word name
		struct {
			uint32_t vpw1_mux_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VP0_BC 10'h024 */
	union {
		uint32_t vp0_bc; // word name
		struct {
			uint32_t vp0_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VP1_BC 10'h028 */
	union {
		uint32_t vp1_bc; // word name
		struct {
			uint32_t vp1_bc_enable_buf : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VP2_BC 10'h02C */
	union {
		uint32_t vp2_bc; // word name
		struct {
			uint32_t vp2_bc_enable_buf : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DHZ_BC 10'h030 */
	union {
		uint32_t dhz_bc; // word name
		struct {
			uint32_t dhz_bc_enable_buf : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B2R_BC 10'h034 */
	union {
		uint32_t b2r_bc; // word name
		struct {
			uint32_t b2r_bc_enable_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DHZ_MUX_NSEL 10'h038 */
	union {
		uint32_t dhz_mux_nsel; // word name
		struct {
			uint32_t dhz_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_MUX_NSEL 10'h03C */
	union {
		uint32_t mcvp_mux_nsel; // word name
		struct {
			uint32_t mcvp_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UNPACKER_MUX_NSEL 10'h040 */
	union {
		uint32_t unpacker_mux_nsel; // word name
		struct {
			uint32_t unpacker_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPPUP0_MUX_NSEL 10'h044 */
	union {
		uint32_t vppup0_mux_nsel; // word name
		struct {
			uint32_t vppup0_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW0_MUX_NSEL 10'h048 */
	union {
		uint32_t vpw0_mux_nsel; // word name
		struct {
			uint32_t vpw0_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPW1_MUX_NSEL 10'h04C */
	union {
		uint32_t vpw1_mux_nsel; // word name
		struct {
			uint32_t vpw1_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VP0_BC_NSEL 10'h050 */
	union {
		uint32_t vp0_bc_nsel; // word name
		struct {
			uint32_t vp0_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VP1_BC_NSEL 10'h054 */
	union {
		uint32_t vp1_bc_nsel; // word name
		struct {
			uint32_t vp1_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VP2_BC_NSEL 10'h058 */
	union {
		uint32_t vp2_bc_nsel; // word name
		struct {
			uint32_t vp2_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DHZ_BC_NSEL 10'h05C */
	union {
		uint32_t dhz_bc_nsel; // word name
		struct {
			uint32_t dhz_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B2R_BC_NSEL 10'h060 */
	union {
		uint32_t b2r_bc_nsel; // word name
		struct {
			uint32_t b2r_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankVp;

#endif