#ifndef CSR_BANK_VP_H_
#define CSR_BANK_VP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from vp  ***/
typedef struct csr_bank_vp {
	/* VP000 10'h000 [Unused] */
	uint32_t empty_word_vp000;
	/* WORD_DEBUG_MON_SEL 10'h004 */
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
	/* VP002 10'h00C [Unused] */
	uint32_t empty_word_vp002;
	/* VP003 10'h010 [Unused] */
	uint32_t empty_word_vp003;
	/* VP004 10'h014 [Unused] */
	uint32_t empty_word_vp004;
	/* ISP1_BROADCAST 10'h018 */
	union {
		uint32_t isp1_broadcast; // word name
		struct {
			uint32_t isp1_broadcast_yuv420to444 : 1;
			uint32_t : 7; // padding bits
			uint32_t isp1_broadcast_vpwrite0 : 1;
			uint32_t : 7; // padding bits
			uint32_t isp1_broadcast_vpwrite1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISP2_BROADCAST 10'h01C */
	union {
		uint32_t isp2_broadcast; // word name
		struct {
			uint32_t isp2_broadcast_yuv420to444 : 1;
			uint32_t : 7; // padding bits
			uint32_t isp2_broadcast_vpwrite0 : 1;
			uint32_t : 7; // padding bits
			uint32_t isp2_broadcast_vpwrite1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B2R_BROADCAST 10'h020 */
	union {
		uint32_t b2r_broadcast; // word name
		struct {
			uint32_t b2r_broadcast_yuv420to444 : 1;
			uint32_t : 7; // padding bits
			uint32_t b2r_broadcast_vpwrite0 : 1;
			uint32_t : 7; // padding bits
			uint32_t b2r_broadcast_vpwrite1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* YV444_BROADCAST 10'h024 */
	union {
		uint32_t yv444_broadcast; // word name
		struct {
			uint32_t yuv444_broadcast_sc : 1;
			uint32_t : 7; // padding bits
			uint32_t yuv444_broadcast_vpcst : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SCALER_BROADCAST 10'h028 */
	union {
		uint32_t scaler_broadcast; // word name
		struct {
			uint32_t scaler_broadcast_vpwrite0 : 1;
			uint32_t : 7; // padding bits
			uint32_t scaler_broadcast_vpwrite1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPCST_BROADCAST 10'h02C */
	union {
		uint32_t vpcst_broadcast; // word name
		struct {
			uint32_t vpcst_broadcast_vplp : 1;
			uint32_t : 7; // padding bits
			uint32_t vpcst_broadcast_vpcfa : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPCFA_BROADCAST 10'h030 */
	union {
		uint32_t vpcfa_broadcast; // word name
		struct {
			uint32_t vpcfa_broadcast_vpwrite0 : 1;
			uint32_t : 7; // padding bits
			uint32_t vpcfa_broadcast_vpwrite1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VPLP_BROADCAST 10'h034 */
	union {
		uint32_t vplp_broadcast; // word name
		struct {
			uint32_t vplp_broadcast_vpwrite0 : 1;
			uint32_t : 7; // padding bits
			uint32_t vplp_broadcast_vpwrite1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SEL_UNPACKER 10'h038 */
	union {
		uint32_t sel_unpacker; // word name
		struct {
			uint32_t unpacker_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SEL_YUV420TO444 10'h03C */
	union {
		uint32_t sel_yuv420to444; // word name
		struct {
			uint32_t yuv420to444_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SEL_VPWRITE0 10'h040 */
	union {
		uint32_t sel_vpwrite0; // word name
		struct {
			uint32_t vpwrite0_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SEL_VPWRITE1 10'h044 */
	union {
		uint32_t sel_vpwrite1; // word name
		struct {
			uint32_t vpwrite1_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESERVED1 10'h048 [Unused] */
	uint32_t empty_word_reserved1;
	/* ACK_NOT_ISP1 10'h04C */
	union {
		uint32_t ack_not_isp1; // word name
		struct {
			uint32_t isp1_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_ISP2 10'h050 */
	union {
		uint32_t ack_not_isp2; // word name
		struct {
			uint32_t isp2_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_B2R 10'h054 */
	union {
		uint32_t ack_not_b2r; // word name
		struct {
			uint32_t b2r_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_SCALER 10'h058 */
	union {
		uint32_t ack_not_scaler; // word name
		struct {
			uint32_t scaler_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_UNPACKER 10'h05C */
	union {
		uint32_t ack_not_unpacker; // word name
		struct {
			uint32_t unpacker_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_YUV420TO444 10'h060 */
	union {
		uint32_t ack_not_yuv420to444; // word name
		struct {
			uint32_t yuv420to444_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_VPWRITE0 10'h064 */
	union {
		uint32_t ack_not_vpwrite0; // word name
		struct {
			uint32_t vpwrite0_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_VPWRITE1 10'h068 */
	union {
		uint32_t ack_not_vpwrite1; // word name
		struct {
			uint32_t vpwrite1_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_YUV444 10'h06C */
	union {
		uint32_t ack_not_yuv444; // word name
		struct {
			uint32_t yuv444_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_VPCST 10'h070 */
	union {
		uint32_t ack_not_vpcst; // word name
		struct {
			uint32_t vpcst_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_VPCFA 10'h074 */
	union {
		uint32_t ack_not_vpcfa; // word name
		struct {
			uint32_t vpcfa_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_VPLP 10'h078 */
	union {
		uint32_t ack_not_vplp; // word name
		struct {
			uint32_t vplp_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESERVED6 10'h07C [Unused] */
	uint32_t empty_word_reserved6;
	/* MEM_LP_CTRL 10'h080 */
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
} CsrBankVp;

#endif