#ifndef CSR_BANK_DOSD_H_
#define CSR_BANK_DOSD_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dosd  ***/
typedef struct csr_bank_dosd {
	/* DOSD000 16'h0000 */
	union {
		uint32_t dosd000; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD001 16'h0004 */
	union {
		uint32_t dosd001; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD002 16'h0008 */
	union {
		uint32_t dosd002; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD003 16'h000C */
	union {
		uint32_t dosd003; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD004 16'h0010 */
	union {
		uint32_t dosd004; // word name
		struct {
			uint32_t frame_width : 13;
			uint32_t : 3; // padding bits
			uint32_t frame_height : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD005 16'h0014 */
	union {
		uint32_t dosd005; // word name
		struct {
			uint32_t dosd_format : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t dosd_bypass_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD006 16'h0018 [Unused] */
	uint32_t empty_word_dosd006;
	/* DOSD007 16'h001C [Unused] */
	uint32_t empty_word_dosd007;
	/* DOSD008 16'h0020 [Unused] */
	uint32_t empty_word_dosd008;
	/* DOSD009 16'h0024 [Unused] */
	uint32_t empty_word_dosd009;
	/* DOSD010 16'h0028 */
	union {
		uint32_t dosd010; // word name
		struct {
			uint32_t layer_0_osd_mode : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_0_osd_yuv_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD011 16'h002C */
	union {
		uint32_t dosd011; // word name
		struct {
			uint32_t layer_0_osd_0_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD012 16'h0030 */
	union {
		uint32_t dosd012; // word name
		struct {
			uint32_t layer_0_osd_0_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_0_osd_0_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD013 16'h0034 */
	union {
		uint32_t dosd013; // word name
		struct {
			uint32_t layer_0_osd_0_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_0_osd_0_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD014 16'h0038 */
	union {
		uint32_t dosd014; // word name
		struct {
			uint32_t layer_0_osd_1_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD015 16'h003C */
	union {
		uint32_t dosd015; // word name
		struct {
			uint32_t layer_0_osd_1_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_0_osd_1_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD016 16'h0040 */
	union {
		uint32_t dosd016; // word name
		struct {
			uint32_t layer_0_osd_1_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_0_osd_1_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD017 16'h0044 */
	union {
		uint32_t dosd017; // word name
		struct {
			uint32_t layer_0_osd_2_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD018 16'h0048 */
	union {
		uint32_t dosd018; // word name
		struct {
			uint32_t layer_0_osd_2_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_0_osd_2_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD019 16'h004C */
	union {
		uint32_t dosd019; // word name
		struct {
			uint32_t layer_0_osd_2_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_0_osd_2_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD020 16'h0050 */
	union {
		uint32_t dosd020; // word name
		struct {
			uint32_t layer_0_osd_3_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD021 16'h0054 */
	union {
		uint32_t dosd021; // word name
		struct {
			uint32_t layer_0_osd_3_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_0_osd_3_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD022 16'h0058 */
	union {
		uint32_t dosd022; // word name
		struct {
			uint32_t layer_0_osd_3_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_0_osd_3_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD023 16'h005C [Unused] */
	uint32_t empty_word_dosd023;
	/* DOSD024 16'h0060 [Unused] */
	uint32_t empty_word_dosd024;
	/* DOSD025 16'h0064 [Unused] */
	uint32_t empty_word_dosd025;
	/* DOSD026 16'h0068 [Unused] */
	uint32_t empty_word_dosd026;
	/* DOSD027 16'h006C [Unused] */
	uint32_t empty_word_dosd027;
	/* DOSD028 16'h0070 [Unused] */
	uint32_t empty_word_dosd028;
	/* DOSD029 16'h0074 [Unused] */
	uint32_t empty_word_dosd029;
	/* DOSD030 16'h0078 */
	union {
		uint32_t dosd030; // word name
		struct {
			uint32_t layer_1_osd_mode : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_1_osd_yuv_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD031 16'h007C */
	union {
		uint32_t dosd031; // word name
		struct {
			uint32_t layer_1_osd_0_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD032 16'h0080 */
	union {
		uint32_t dosd032; // word name
		struct {
			uint32_t layer_1_osd_0_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_1_osd_0_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD033 16'h0084 */
	union {
		uint32_t dosd033; // word name
		struct {
			uint32_t layer_1_osd_0_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_1_osd_0_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD034 16'h0088 */
	union {
		uint32_t dosd034; // word name
		struct {
			uint32_t layer_1_osd_1_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD035 16'h008C */
	union {
		uint32_t dosd035; // word name
		struct {
			uint32_t layer_1_osd_1_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_1_osd_1_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD036 16'h0090 */
	union {
		uint32_t dosd036; // word name
		struct {
			uint32_t layer_1_osd_1_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_1_osd_1_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD037 16'h0094 */
	union {
		uint32_t dosd037; // word name
		struct {
			uint32_t layer_1_osd_2_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD038 16'h0098 */
	union {
		uint32_t dosd038; // word name
		struct {
			uint32_t layer_1_osd_2_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_1_osd_2_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD039 16'h009C */
	union {
		uint32_t dosd039; // word name
		struct {
			uint32_t layer_1_osd_2_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_1_osd_2_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD040 16'h00A0 */
	union {
		uint32_t dosd040; // word name
		struct {
			uint32_t layer_1_osd_3_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD041 16'h00A4 */
	union {
		uint32_t dosd041; // word name
		struct {
			uint32_t layer_1_osd_3_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_1_osd_3_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD042 16'h00A8 */
	union {
		uint32_t dosd042; // word name
		struct {
			uint32_t layer_1_osd_3_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_1_osd_3_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD043 16'h00AC [Unused] */
	uint32_t empty_word_dosd043;
	/* DOSD044 16'h00B0 [Unused] */
	uint32_t empty_word_dosd044;
	/* DOSD045 16'h00B4 [Unused] */
	uint32_t empty_word_dosd045;
	/* DOSD046 16'h00B8 [Unused] */
	uint32_t empty_word_dosd046;
	/* DOSD047 16'h00BC [Unused] */
	uint32_t empty_word_dosd047;
	/* DOSD048 16'h00C0 [Unused] */
	uint32_t empty_word_dosd048;
	/* DOSD049 16'h00C4 [Unused] */
	uint32_t empty_word_dosd049;
	/* DOSD050 16'h00C8 */
	union {
		uint32_t dosd050; // word name
		struct {
			uint32_t layer_bb_osd_yuv_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD051 16'h00CC */
	union {
		uint32_t dosd051; // word name
		struct {
			uint32_t layer_bb_osd_0_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_0_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD052 16'h00D0 */
	union {
		uint32_t dosd052; // word name
		struct {
			uint32_t layer_bb_osd_0_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_0_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD053 16'h00D4 */
	union {
		uint32_t dosd053; // word name
		struct {
			uint32_t layer_bb_osd_0_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_0_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD054 16'h00D8 */
	union {
		uint32_t dosd054; // word name
		struct {
			uint32_t layer_bb_osd_0_y : 8;
			uint32_t layer_bb_osd_0_u : 8;
			uint32_t layer_bb_osd_0_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD055 16'h00DC */
	union {
		uint32_t dosd055; // word name
		struct {
			uint32_t layer_bb_osd_0_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_0_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD056 16'h00E0 [Unused] */
	uint32_t empty_word_dosd056;
	/* DOSD057 16'h00E4 [Unused] */
	uint32_t empty_word_dosd057;
	/* DOSD058 16'h00E8 [Unused] */
	uint32_t empty_word_dosd058;
	/* DOSD059 16'h00EC [Unused] */
	uint32_t empty_word_dosd059;
	/* DOSD060 16'h00F0 [Unused] */
	uint32_t empty_word_dosd060;
	/* DOSD061 16'h00F4 */
	union {
		uint32_t dosd061; // word name
		struct {
			uint32_t layer_bb_osd_1_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_1_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD062 16'h00F8 */
	union {
		uint32_t dosd062; // word name
		struct {
			uint32_t layer_bb_osd_1_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_1_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD063 16'h00FC */
	union {
		uint32_t dosd063; // word name
		struct {
			uint32_t layer_bb_osd_1_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_1_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD064 16'h0100 */
	union {
		uint32_t dosd064; // word name
		struct {
			uint32_t layer_bb_osd_1_y : 8;
			uint32_t layer_bb_osd_1_u : 8;
			uint32_t layer_bb_osd_1_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD065 16'h0104 */
	union {
		uint32_t dosd065; // word name
		struct {
			uint32_t layer_bb_osd_1_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_1_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD066 16'h0108 [Unused] */
	uint32_t empty_word_dosd066;
	/* DOSD067 16'h010C [Unused] */
	uint32_t empty_word_dosd067;
	/* DOSD068 16'h0110 [Unused] */
	uint32_t empty_word_dosd068;
	/* DOSD069 16'h0114 [Unused] */
	uint32_t empty_word_dosd069;
	/* DOSD070 16'h0118 [Unused] */
	uint32_t empty_word_dosd070;
	/* DOSD071 16'h011C */
	union {
		uint32_t dosd071; // word name
		struct {
			uint32_t layer_bb_osd_2_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_2_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD072 16'h0120 */
	union {
		uint32_t dosd072; // word name
		struct {
			uint32_t layer_bb_osd_2_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_2_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD073 16'h0124 */
	union {
		uint32_t dosd073; // word name
		struct {
			uint32_t layer_bb_osd_2_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_2_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD074 16'h0128 */
	union {
		uint32_t dosd074; // word name
		struct {
			uint32_t layer_bb_osd_2_y : 8;
			uint32_t layer_bb_osd_2_u : 8;
			uint32_t layer_bb_osd_2_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD075 16'h012C */
	union {
		uint32_t dosd075; // word name
		struct {
			uint32_t layer_bb_osd_2_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_2_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD076 16'h0130 [Unused] */
	uint32_t empty_word_dosd076;
	/* DOSD077 16'h0134 [Unused] */
	uint32_t empty_word_dosd077;
	/* DOSD078 16'h0138 [Unused] */
	uint32_t empty_word_dosd078;
	/* DOSD079 16'h013C [Unused] */
	uint32_t empty_word_dosd079;
	/* DOSD080 16'h0140 [Unused] */
	uint32_t empty_word_dosd080;
	/* DOSD081 16'h0144 */
	union {
		uint32_t dosd081; // word name
		struct {
			uint32_t layer_bb_osd_3_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_3_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD082 16'h0148 */
	union {
		uint32_t dosd082; // word name
		struct {
			uint32_t layer_bb_osd_3_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_3_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD083 16'h014C */
	union {
		uint32_t dosd083; // word name
		struct {
			uint32_t layer_bb_osd_3_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_3_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD084 16'h0150 */
	union {
		uint32_t dosd084; // word name
		struct {
			uint32_t layer_bb_osd_3_y : 8;
			uint32_t layer_bb_osd_3_u : 8;
			uint32_t layer_bb_osd_3_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD085 16'h0154 */
	union {
		uint32_t dosd085; // word name
		struct {
			uint32_t layer_bb_osd_3_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_3_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD086 16'h0158 [Unused] */
	uint32_t empty_word_dosd086;
	/* DOSD087 16'h015C [Unused] */
	uint32_t empty_word_dosd087;
	/* DOSD088 16'h0160 [Unused] */
	uint32_t empty_word_dosd088;
	/* DOSD089 16'h0164 [Unused] */
	uint32_t empty_word_dosd089;
	/* DOSD090 16'h0168 [Unused] */
	uint32_t empty_word_dosd090;
	/* DOSD091 16'h016C */
	union {
		uint32_t dosd091; // word name
		struct {
			uint32_t layer_bb_osd_4_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_4_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD092 16'h0170 */
	union {
		uint32_t dosd092; // word name
		struct {
			uint32_t layer_bb_osd_4_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_4_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD093 16'h0174 */
	union {
		uint32_t dosd093; // word name
		struct {
			uint32_t layer_bb_osd_4_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_4_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD094 16'h0178 */
	union {
		uint32_t dosd094; // word name
		struct {
			uint32_t layer_bb_osd_4_y : 8;
			uint32_t layer_bb_osd_4_u : 8;
			uint32_t layer_bb_osd_4_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD095 16'h017C */
	union {
		uint32_t dosd095; // word name
		struct {
			uint32_t layer_bb_osd_4_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_4_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD096 16'h0180 [Unused] */
	uint32_t empty_word_dosd096;
	/* DOSD097 16'h0184 [Unused] */
	uint32_t empty_word_dosd097;
	/* DOSD098 16'h0188 [Unused] */
	uint32_t empty_word_dosd098;
	/* DOSD099 16'h018C [Unused] */
	uint32_t empty_word_dosd099;
	/* DOSD100 16'h0190 [Unused] */
	uint32_t empty_word_dosd100;
	/* DOSD101 16'h0194 */
	union {
		uint32_t dosd101; // word name
		struct {
			uint32_t layer_bb_osd_5_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_5_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD102 16'h0198 */
	union {
		uint32_t dosd102; // word name
		struct {
			uint32_t layer_bb_osd_5_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_5_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD103 16'h019C */
	union {
		uint32_t dosd103; // word name
		struct {
			uint32_t layer_bb_osd_5_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_5_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD104 16'h01A0 */
	union {
		uint32_t dosd104; // word name
		struct {
			uint32_t layer_bb_osd_5_y : 8;
			uint32_t layer_bb_osd_5_u : 8;
			uint32_t layer_bb_osd_5_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD105 16'h01A4 */
	union {
		uint32_t dosd105; // word name
		struct {
			uint32_t layer_bb_osd_5_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_5_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD106 16'h01A8 [Unused] */
	uint32_t empty_word_dosd106;
	/* DOSD107 16'h01AC [Unused] */
	uint32_t empty_word_dosd107;
	/* DOSD108 16'h01B0 [Unused] */
	uint32_t empty_word_dosd108;
	/* DOSD109 16'h01B4 [Unused] */
	uint32_t empty_word_dosd109;
	/* DOSD110 16'h01B8 [Unused] */
	uint32_t empty_word_dosd110;
	/* DOSD111 16'h01BC */
	union {
		uint32_t dosd111; // word name
		struct {
			uint32_t layer_bb_osd_6_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_6_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD112 16'h01C0 */
	union {
		uint32_t dosd112; // word name
		struct {
			uint32_t layer_bb_osd_6_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_6_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD113 16'h01C4 */
	union {
		uint32_t dosd113; // word name
		struct {
			uint32_t layer_bb_osd_6_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_6_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD114 16'h01C8 */
	union {
		uint32_t dosd114; // word name
		struct {
			uint32_t layer_bb_osd_6_y : 8;
			uint32_t layer_bb_osd_6_u : 8;
			uint32_t layer_bb_osd_6_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD115 16'h01CC */
	union {
		uint32_t dosd115; // word name
		struct {
			uint32_t layer_bb_osd_6_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_6_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD116 16'h01D0 [Unused] */
	uint32_t empty_word_dosd116;
	/* DOSD117 16'h01D4 [Unused] */
	uint32_t empty_word_dosd117;
	/* DOSD118 16'h01D8 [Unused] */
	uint32_t empty_word_dosd118;
	/* DOSD119 16'h01DC [Unused] */
	uint32_t empty_word_dosd119;
	/* DOSD120 16'h01E0 [Unused] */
	uint32_t empty_word_dosd120;
	/* DOSD121 16'h01E4 */
	union {
		uint32_t dosd121; // word name
		struct {
			uint32_t layer_bb_osd_7_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_7_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD122 16'h01E8 */
	union {
		uint32_t dosd122; // word name
		struct {
			uint32_t layer_bb_osd_7_start_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_7_start_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD123 16'h01EC */
	union {
		uint32_t dosd123; // word name
		struct {
			uint32_t layer_bb_osd_7_end_x : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bb_osd_7_end_y : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* DOSD124 16'h01F0 */
	union {
		uint32_t dosd124; // word name
		struct {
			uint32_t layer_bb_osd_7_y : 8;
			uint32_t layer_bb_osd_7_u : 8;
			uint32_t layer_bb_osd_7_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD125 16'h01F4 */
	union {
		uint32_t dosd125; // word name
		struct {
			uint32_t layer_bb_osd_7_line_width : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t layer_bb_osd_7_line_alpha : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD126 16'h01F8 [Unused] */
	uint32_t empty_word_dosd126;
	/* DOSD127 16'h01FC [Unused] */
	uint32_t empty_word_dosd127;
	/* DOSD128 16'h0200 [Unused] */
	uint32_t empty_word_dosd128;
	/* DOSD129 16'h0204 [Unused] */
	uint32_t empty_word_dosd129;
	/* DOSD130 16'h0208 [Unused] */
	uint32_t empty_word_dosd130;
	/* DOSD131 16'h020C */
	union {
		uint32_t dosd131; // word name
		struct {
			uint32_t wildcard_0_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t wildcard_0_y : 8;
			uint32_t wildcard_0_u : 8;
			uint32_t wildcard_0_v : 8;
		};
	};
	/* DOSD132 16'h0210 */
	union {
		uint32_t dosd132; // word name
		struct {
			uint32_t wildcard_1_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t wildcard_1_y : 8;
			uint32_t wildcard_1_u : 8;
			uint32_t wildcard_1_v : 8;
		};
	};
	/* DOSD133 16'h0214 */
	union {
		uint32_t dosd133; // word name
		struct {
			uint32_t wildcard_2_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t wildcard_2_y : 8;
			uint32_t wildcard_2_u : 8;
			uint32_t wildcard_2_v : 8;
		};
	};
	/* DOSD134 16'h0218 */
	union {
		uint32_t dosd134; // word name
		struct {
			uint32_t wildcard_3_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t wildcard_3_y : 8;
			uint32_t wildcard_3_u : 8;
			uint32_t wildcard_3_v : 8;
		};
	};
	/* DOSD135 16'h021C */
	union {
		uint32_t dosd135; // word name
		struct {
			uint32_t wildcard_4_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t wildcard_4_y : 8;
			uint32_t wildcard_4_u : 8;
			uint32_t wildcard_4_v : 8;
		};
	};
	/* DOSD136 16'h0220 */
	union {
		uint32_t dosd136; // word name
		struct {
			uint32_t wildcard_5_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t wildcard_5_y : 8;
			uint32_t wildcard_5_u : 8;
			uint32_t wildcard_5_v : 8;
		};
	};
	/* DOSD137 16'h0224 */
	union {
		uint32_t dosd137; // word name
		struct {
			uint32_t wildcard_6_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t wildcard_6_y : 8;
			uint32_t wildcard_6_u : 8;
			uint32_t wildcard_6_v : 8;
		};
	};
	/* DOSD138 16'h0228 */
	union {
		uint32_t dosd138; // word name
		struct {
			uint32_t wildcard_7_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t wildcard_7_y : 8;
			uint32_t wildcard_7_u : 8;
			uint32_t wildcard_7_v : 8;
		};
	};
	/* DOSD139 16'h022C */
	union {
		uint32_t dosd139; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* DOSD140 16'h0230 */
	union {
		uint32_t dosd140; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* DOSD141 16'h0234 */
	union {
		uint32_t dosd141; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDosd;

#endif