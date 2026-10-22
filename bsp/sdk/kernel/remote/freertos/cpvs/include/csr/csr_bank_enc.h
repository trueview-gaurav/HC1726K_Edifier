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
	/* WORD_LAYER_0_OSD_MODE 10'h010 */
	union {
		uint32_t word_layer_0_osd_mode; // word name
		struct {
			uint32_t layer_0_osd_mode : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_0_osd_yuv_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_0_OSD_0_EN 10'h014 */
	union {
		uint32_t layer_0_osd_0_en; // word name
		struct {
			uint32_t layer_0_osd_0_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_0_OSD_0_START 10'h018 */
	union {
		uint32_t layer_0_osd_0_start; // word name
		struct {
			uint32_t layer_0_osd_0_start_x : 16;
			uint32_t layer_0_osd_0_start_y : 16;
		};
	};
	/* LAYER_0_OSD_0_END 10'h01C */
	union {
		uint32_t layer_0_osd_0_end; // word name
		struct {
			uint32_t layer_0_osd_0_end_x : 16;
			uint32_t layer_0_osd_0_end_y : 16;
		};
	};
	/* LAYER_0_OSD_1_EN 10'h020 */
	union {
		uint32_t layer_0_osd_1_en; // word name
		struct {
			uint32_t layer_0_osd_1_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_0_OSD_1_START 10'h024 */
	union {
		uint32_t layer_0_osd_1_start; // word name
		struct {
			uint32_t layer_0_osd_1_start_x : 16;
			uint32_t layer_0_osd_1_start_y : 16;
		};
	};
	/* LAYER_0_OSD_1_END 10'h028 */
	union {
		uint32_t layer_0_osd_1_end; // word name
		struct {
			uint32_t layer_0_osd_1_end_x : 16;
			uint32_t layer_0_osd_1_end_y : 16;
		};
	};
	/* LAYER_0_OSD_2_EN 10'h02C */
	union {
		uint32_t layer_0_osd_2_en; // word name
		struct {
			uint32_t layer_0_osd_2_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_0_OSD_2_START 10'h030 */
	union {
		uint32_t layer_0_osd_2_start; // word name
		struct {
			uint32_t layer_0_osd_2_start_x : 16;
			uint32_t layer_0_osd_2_start_y : 16;
		};
	};
	/* LAYER_0_OSD_2_END 10'h034 */
	union {
		uint32_t layer_0_osd_2_end; // word name
		struct {
			uint32_t layer_0_osd_2_end_x : 16;
			uint32_t layer_0_osd_2_end_y : 16;
		};
	};
	/* LAYER_0_OSD_3_EN 10'h038 */
	union {
		uint32_t layer_0_osd_3_en; // word name
		struct {
			uint32_t layer_0_osd_3_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_0_OSD_3_START 10'h03C */
	union {
		uint32_t layer_0_osd_3_start; // word name
		struct {
			uint32_t layer_0_osd_3_start_x : 16;
			uint32_t layer_0_osd_3_start_y : 16;
		};
	};
	/* LAYER_0_OSD_3_END 10'h040 */
	union {
		uint32_t layer_0_osd_3_end; // word name
		struct {
			uint32_t layer_0_osd_3_end_x : 16;
			uint32_t layer_0_osd_3_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_MODE 10'h044 */
	union {
		uint32_t layer_bb_osd_mode; // word name
		struct {
			uint32_t layer_bb_osd_yuv_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_0_EN 10'h048 */
	union {
		uint32_t layer_bb_osd_0_en; // word name
		struct {
			uint32_t layer_bb_osd_0_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_0_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_0_START 10'h04C */
	union {
		uint32_t layer_bb_osd_0_start; // word name
		struct {
			uint32_t layer_bb_osd_0_start_x : 16;
			uint32_t layer_bb_osd_0_start_y : 16;
		};
	};
	/* LAYER_BB_OSD_0_END 10'h050 */
	union {
		uint32_t layer_bb_osd_0_end; // word name
		struct {
			uint32_t layer_bb_osd_0_end_x : 16;
			uint32_t layer_bb_osd_0_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_0_COLOR 10'h054 */
	union {
		uint32_t layer_bb_osd_0_color; // word name
		struct {
			uint32_t layer_bb_osd_0_y : 8;
			uint32_t layer_bb_osd_0_u : 8;
			uint32_t layer_bb_osd_0_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_0_LINE 10'h058 */
	union {
		uint32_t layer_bb_osd_0_line; // word name
		struct {
			uint32_t layer_bb_osd_0_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_0_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_1_EN 10'h05C */
	union {
		uint32_t layer_bb_osd_1_en; // word name
		struct {
			uint32_t layer_bb_osd_1_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_1_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_1_START 10'h060 */
	union {
		uint32_t layer_bb_osd_1_start; // word name
		struct {
			uint32_t layer_bb_osd_1_start_x : 16;
			uint32_t layer_bb_osd_1_start_y : 16;
		};
	};
	/* LAYER_BB_OSD_1_END 10'h064 */
	union {
		uint32_t layer_bb_osd_1_end; // word name
		struct {
			uint32_t layer_bb_osd_1_end_x : 16;
			uint32_t layer_bb_osd_1_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_1_COLOR 10'h068 */
	union {
		uint32_t layer_bb_osd_1_color; // word name
		struct {
			uint32_t layer_bb_osd_1_y : 8;
			uint32_t layer_bb_osd_1_u : 8;
			uint32_t layer_bb_osd_1_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_1_LINE 10'h06C */
	union {
		uint32_t layer_bb_osd_1_line; // word name
		struct {
			uint32_t layer_bb_osd_1_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_1_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_2_EN 10'h070 */
	union {
		uint32_t layer_bb_osd_2_en; // word name
		struct {
			uint32_t layer_bb_osd_2_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_2_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_2_START 10'h074 */
	union {
		uint32_t layer_bb_osd_2_start; // word name
		struct {
			uint32_t layer_bb_osd_2_start_x : 16;
			uint32_t layer_bb_osd_2_start_y : 16;
		};
	};
	/* LAYER_BB_OSD_2_END 10'h078 */
	union {
		uint32_t layer_bb_osd_2_end; // word name
		struct {
			uint32_t layer_bb_osd_2_end_x : 16;
			uint32_t layer_bb_osd_2_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_2_COLOR 10'h07C */
	union {
		uint32_t layer_bb_osd_2_color; // word name
		struct {
			uint32_t layer_bb_osd_2_y : 8;
			uint32_t layer_bb_osd_2_u : 8;
			uint32_t layer_bb_osd_2_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_2_LINE 10'h080 */
	union {
		uint32_t layer_bb_osd_2_line; // word name
		struct {
			uint32_t layer_bb_osd_2_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_2_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_3_EN 10'h084 */
	union {
		uint32_t layer_bb_osd_3_en; // word name
		struct {
			uint32_t layer_bb_osd_3_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_3_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_3_START 10'h088 */
	union {
		uint32_t layer_bb_osd_3_start; // word name
		struct {
			uint32_t layer_bb_osd_3_start_x : 16;
			uint32_t layer_bb_osd_3_start_y : 16;
		};
	};
	/* LAYER_BB_OSD_3_END 10'h08C */
	union {
		uint32_t layer_bb_osd_3_end; // word name
		struct {
			uint32_t layer_bb_osd_3_end_x : 16;
			uint32_t layer_bb_osd_3_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_3_COLOR 10'h090 */
	union {
		uint32_t layer_bb_osd_3_color; // word name
		struct {
			uint32_t layer_bb_osd_3_y : 8;
			uint32_t layer_bb_osd_3_u : 8;
			uint32_t layer_bb_osd_3_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_3_LINE 10'h094 */
	union {
		uint32_t layer_bb_osd_3_line; // word name
		struct {
			uint32_t layer_bb_osd_3_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_3_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_4_EN 10'h098 */
	union {
		uint32_t layer_bb_osd_4_en; // word name
		struct {
			uint32_t layer_bb_osd_4_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_4_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_4_START 10'h09C */
	union {
		uint32_t layer_bb_osd_4_start; // word name
		struct {
			uint32_t layer_bb_osd_4_start_x : 16;
			uint32_t layer_bb_osd_4_start_y : 16;
		};
	};
	/* LAYER_BB_OSD_4_END 10'h0A0 */
	union {
		uint32_t layer_bb_osd_4_end; // word name
		struct {
			uint32_t layer_bb_osd_4_end_x : 16;
			uint32_t layer_bb_osd_4_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_4_COLOR 10'h0A4 */
	union {
		uint32_t layer_bb_osd_4_color; // word name
		struct {
			uint32_t layer_bb_osd_4_y : 8;
			uint32_t layer_bb_osd_4_u : 8;
			uint32_t layer_bb_osd_4_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_4_LINE 10'h0A8 */
	union {
		uint32_t layer_bb_osd_4_line; // word name
		struct {
			uint32_t layer_bb_osd_4_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_4_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_5_EN 10'h0AC */
	union {
		uint32_t layer_bb_osd_5_en; // word name
		struct {
			uint32_t layer_bb_osd_5_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_5_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_5_START 10'h0B0 */
	union {
		uint32_t layer_bb_osd_5_start; // word name
		struct {
			uint32_t layer_bb_osd_5_start_x : 16;
			uint32_t layer_bb_osd_5_start_y : 16;
		};
	};
	/* LAYER_BB_OSD_5_END 10'h0B4 */
	union {
		uint32_t layer_bb_osd_5_end; // word name
		struct {
			uint32_t layer_bb_osd_5_end_x : 16;
			uint32_t layer_bb_osd_5_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_5_COLOR 10'h0B8 */
	union {
		uint32_t layer_bb_osd_5_color; // word name
		struct {
			uint32_t layer_bb_osd_5_y : 8;
			uint32_t layer_bb_osd_5_u : 8;
			uint32_t layer_bb_osd_5_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_5_LINE 10'h0BC */
	union {
		uint32_t layer_bb_osd_5_line; // word name
		struct {
			uint32_t layer_bb_osd_5_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_5_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_6_EN 10'h0C0 */
	union {
		uint32_t layer_bb_osd_6_en; // word name
		struct {
			uint32_t layer_bb_osd_6_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_6_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_6_START 10'h0C4 */
	union {
		uint32_t layer_bb_osd_6_start; // word name
		struct {
			uint32_t layer_bb_osd_6_start_x : 16;
			uint32_t layer_bb_osd_6_start_y : 16;
		};
	};
	/* LAYER_BB_OSD_6_END 10'h0C8 */
	union {
		uint32_t layer_bb_osd_6_end; // word name
		struct {
			uint32_t layer_bb_osd_6_end_x : 16;
			uint32_t layer_bb_osd_6_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_6_COLOR 10'h0CC */
	union {
		uint32_t layer_bb_osd_6_color; // word name
		struct {
			uint32_t layer_bb_osd_6_y : 8;
			uint32_t layer_bb_osd_6_u : 8;
			uint32_t layer_bb_osd_6_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_6_LINE 10'h0D0 */
	union {
		uint32_t layer_bb_osd_6_line; // word name
		struct {
			uint32_t layer_bb_osd_6_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_6_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_7_EN 10'h0D4 */
	union {
		uint32_t layer_bb_osd_7_en; // word name
		struct {
			uint32_t layer_bb_osd_7_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_7_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_7_START 10'h0D8 */
	union {
		uint32_t layer_bb_osd_7_start; // word name
		struct {
			uint32_t layer_bb_osd_7_start_x : 16;
			uint32_t layer_bb_osd_7_start_y : 16;
		};
	};
	/* LAYER_BB_OSD_7_END 10'h0DC */
	union {
		uint32_t layer_bb_osd_7_end; // word name
		struct {
			uint32_t layer_bb_osd_7_end_x : 16;
			uint32_t layer_bb_osd_7_end_y : 16;
		};
	};
	/* LAYER_BB_OSD_7_COLOR 10'h0E0 */
	union {
		uint32_t layer_bb_osd_7_color; // word name
		struct {
			uint32_t layer_bb_osd_7_y : 8;
			uint32_t layer_bb_osd_7_u : 8;
			uint32_t layer_bb_osd_7_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BB_OSD_7_LINE 10'h0E4 */
	union {
		uint32_t layer_bb_osd_7_line; // word name
		struct {
			uint32_t layer_bb_osd_7_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_7_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* WILDCARD_0 10'h0E8 */
	union {
		uint32_t wildcard_0; // word name
		struct {
			uint32_t wildcard_0_y : 8;
			uint32_t wildcard_0_u : 8;
			uint32_t wildcard_0_v : 8;
			uint32_t wildcard_0_valid : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WILDCARD_1 10'h0EC */
	union {
		uint32_t wildcard_1; // word name
		struct {
			uint32_t wildcard_1_y : 8;
			uint32_t wildcard_1_u : 8;
			uint32_t wildcard_1_v : 8;
			uint32_t wildcard_1_valid : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WILDCARD_2 10'h0F0 */
	union {
		uint32_t wildcard_2; // word name
		struct {
			uint32_t wildcard_2_y : 8;
			uint32_t wildcard_2_u : 8;
			uint32_t wildcard_2_v : 8;
			uint32_t wildcard_2_valid : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WILDCARD_3 10'h0F4 */
	union {
		uint32_t wildcard_3; // word name
		struct {
			uint32_t wildcard_3_y : 8;
			uint32_t wildcard_3_u : 8;
			uint32_t wildcard_3_v : 8;
			uint32_t wildcard_3_valid : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WILDCARD_4 10'h0F8 */
	union {
		uint32_t wildcard_4; // word name
		struct {
			uint32_t wildcard_4_y : 8;
			uint32_t wildcard_4_u : 8;
			uint32_t wildcard_4_v : 8;
			uint32_t wildcard_4_valid : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WILDCARD_5 10'h0FC */
	union {
		uint32_t wildcard_5; // word name
		struct {
			uint32_t wildcard_5_y : 8;
			uint32_t wildcard_5_u : 8;
			uint32_t wildcard_5_v : 8;
			uint32_t wildcard_5_valid : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WILDCARD_6 10'h100 */
	union {
		uint32_t wildcard_6; // word name
		struct {
			uint32_t wildcard_6_y : 8;
			uint32_t wildcard_6_u : 8;
			uint32_t wildcard_6_v : 8;
			uint32_t wildcard_6_valid : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WILDCARD_7 10'h104 */
	union {
		uint32_t wildcard_7; // word name
		struct {
			uint32_t wildcard_7_y : 8;
			uint32_t wildcard_7_u : 8;
			uint32_t wildcard_7_v : 8;
			uint32_t wildcard_7_valid : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MEM_CTRL 10'h108 */
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
	/* WORD_RESERVED_0 10'h10C */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
} CsrBankEnc;

#endif