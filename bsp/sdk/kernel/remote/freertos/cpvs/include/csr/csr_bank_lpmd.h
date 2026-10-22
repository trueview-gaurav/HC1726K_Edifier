#ifndef CSR_BANK_LPMD_H_
#define CSR_BANK_LPMD_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from lpmd  ***/
typedef struct csr_bank_lpmd {
	/* START 10'h000 [Unused] */
	uint32_t empty_word_start;
	/* IRQ_CLEAR 10'h004 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t irq_clear_frame_alarm : 1;
			uint32_t irq_clear_pix_cnt_mismatch : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STATUS 10'h008 */
	union {
		uint32_t irq_status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t status_frame_alarm : 1;
			uint32_t status_pix_cnt_mismatch : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 10'h00C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t irq_mask_frame_alarm : 1;
			uint32_t irq_mask_pix_cnt_mismatch : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_MODE 10'h010 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FRAME_CNT_TH 10'h014 */
	union {
		uint32_t word_frame_cnt_th; // word name
		struct {
			uint32_t frame_cnt_th : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PIX_NUM 10'h018 */
	union {
		uint32_t pix_num; // word name
		struct {
			uint32_t frame_pix_num : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* RESOLUTION 10'h01C */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width_i : 16;
			uint32_t height_i : 16;
		};
	};
	/* CROP_X 10'h020 */
	union {
		uint32_t crop_x; // word name
		struct {
			uint32_t crop_left : 16;
			uint32_t crop_right : 16;
		};
	};
	/* CROP_Y 10'h024 */
	union {
		uint32_t crop_y; // word name
		struct {
			uint32_t crop_up : 16;
			uint32_t crop_down : 16;
		};
	};
	/* DET_RESOLUTION 10'h028 */
	union {
		uint32_t det_resolution; // word name
		struct {
			uint32_t det_width : 12;
			uint32_t : 4; // padding bits
			uint32_t det_height : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* RGL_CONFIG 10'h02C */
	union {
		uint32_t rgl_config; // word name
		struct {
			uint32_t region_x_num_m1 : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t region_pix_num : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* RGL_RESOLUTION 10'h030 */
	union {
		uint32_t rgl_resolution; // word name
		struct {
			uint32_t region_width : 8;
			uint32_t : 8; // padding bits
			uint32_t region_height : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* IIR_WEIGHT 10'h034 */
	union {
		uint32_t iir_weight; // word name
		struct {
			uint32_t apl_iir_weight : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* APL_CONFIG 10'h038 */
	union {
		uint32_t apl_config; // word name
		struct {
			uint32_t apl_coring_th : 6;
			uint32_t : 2; // padding bits
			uint32_t apl_step_shift_bw : 3;
			uint32_t : 5; // padding bits
			uint32_t apl_alarm_max : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS_CONFIG 10'h03C */
	union {
		uint32_t status_config; // word name
		struct {
			uint32_t status_dec : 4;
			uint32_t : 4; // padding bits
			uint32_t status_max : 5;
			uint32_t : 3; // padding bits
			uint32_t status_th_high : 5;
			uint32_t : 3; // padding bits
			uint32_t status_th_low : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* FRAME_ALARM_CONFIG 10'h040 */
	union {
		uint32_t frame_alarm_config; // word name
		struct {
			uint32_t frame_alarm_th : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_0 10'h044 */
	union {
		uint32_t region_weight_set_0; // word name
		struct {
			uint32_t region_weight_0 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_1 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_2 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_3 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_1 10'h048 */
	union {
		uint32_t region_weight_set_1; // word name
		struct {
			uint32_t region_weight_4 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_5 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_6 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_7 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_2 10'h04C */
	union {
		uint32_t region_weight_set_2; // word name
		struct {
			uint32_t region_weight_8 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_9 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_10 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_11 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_3 10'h050 */
	union {
		uint32_t region_weight_set_3; // word name
		struct {
			uint32_t region_weight_12 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_13 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_14 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_15 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_4 10'h054 */
	union {
		uint32_t region_weight_set_4; // word name
		struct {
			uint32_t region_weight_16 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_17 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_18 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_19 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_5 10'h058 */
	union {
		uint32_t region_weight_set_5; // word name
		struct {
			uint32_t region_weight_20 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_21 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_22 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_23 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_6 10'h05C */
	union {
		uint32_t region_weight_set_6; // word name
		struct {
			uint32_t region_weight_24 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_25 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_26 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_27 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_7 10'h060 */
	union {
		uint32_t region_weight_set_7; // word name
		struct {
			uint32_t region_weight_28 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_29 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_30 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_31 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_8 10'h064 */
	union {
		uint32_t region_weight_set_8; // word name
		struct {
			uint32_t region_weight_32 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_33 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_34 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_35 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_9 10'h068 */
	union {
		uint32_t region_weight_set_9; // word name
		struct {
			uint32_t region_weight_36 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_37 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_38 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_39 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_10 10'h06C */
	union {
		uint32_t region_weight_set_10; // word name
		struct {
			uint32_t region_weight_40 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_41 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_42 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_43 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_11 10'h070 */
	union {
		uint32_t region_weight_set_11; // word name
		struct {
			uint32_t region_weight_44 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_45 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_46 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_47 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_12 10'h074 */
	union {
		uint32_t region_weight_set_12; // word name
		struct {
			uint32_t region_weight_48 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_49 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_50 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_51 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_13 10'h078 */
	union {
		uint32_t region_weight_set_13; // word name
		struct {
			uint32_t region_weight_52 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_53 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_54 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_55 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_14 10'h07C */
	union {
		uint32_t region_weight_set_14; // word name
		struct {
			uint32_t region_weight_56 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_57 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_58 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_59 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_15 10'h080 */
	union {
		uint32_t region_weight_set_15; // word name
		struct {
			uint32_t region_weight_60 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_61 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_62 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_63 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_16 10'h084 */
	union {
		uint32_t region_weight_set_16; // word name
		struct {
			uint32_t region_weight_64 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_65 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_66 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_67 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_17 10'h088 */
	union {
		uint32_t region_weight_set_17; // word name
		struct {
			uint32_t region_weight_68 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_69 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_70 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_71 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_18 10'h08C */
	union {
		uint32_t region_weight_set_18; // word name
		struct {
			uint32_t region_weight_72 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_73 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_74 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_75 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_19 10'h090 */
	union {
		uint32_t region_weight_set_19; // word name
		struct {
			uint32_t region_weight_76 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_77 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_78 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_79 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_20 10'h094 */
	union {
		uint32_t region_weight_set_20; // word name
		struct {
			uint32_t region_weight_80 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_81 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_82 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_83 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_21 10'h098 */
	union {
		uint32_t region_weight_set_21; // word name
		struct {
			uint32_t region_weight_84 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_85 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_86 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_87 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_22 10'h09C */
	union {
		uint32_t region_weight_set_22; // word name
		struct {
			uint32_t region_weight_88 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_89 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_90 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_91 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_23 10'h0A0 */
	union {
		uint32_t region_weight_set_23; // word name
		struct {
			uint32_t region_weight_92 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_93 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_94 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_95 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_24 10'h0A4 */
	union {
		uint32_t region_weight_set_24; // word name
		struct {
			uint32_t region_weight_96 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_97 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_98 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_99 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_25 10'h0A8 */
	union {
		uint32_t region_weight_set_25; // word name
		struct {
			uint32_t region_weight_100 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_101 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_102 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_103 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_26 10'h0AC */
	union {
		uint32_t region_weight_set_26; // word name
		struct {
			uint32_t region_weight_104 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_105 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_106 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_107 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_27 10'h0B0 */
	union {
		uint32_t region_weight_set_27; // word name
		struct {
			uint32_t region_weight_108 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_109 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_110 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_111 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_28 10'h0B4 */
	union {
		uint32_t region_weight_set_28; // word name
		struct {
			uint32_t region_weight_112 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_113 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_114 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_115 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_29 10'h0B8 */
	union {
		uint32_t region_weight_set_29; // word name
		struct {
			uint32_t region_weight_116 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_117 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_118 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_119 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_30 10'h0BC */
	union {
		uint32_t region_weight_set_30; // word name
		struct {
			uint32_t region_weight_120 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_121 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_122 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_123 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_31 10'h0C0 */
	union {
		uint32_t region_weight_set_31; // word name
		struct {
			uint32_t region_weight_124 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_125 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_126 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_127 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_32 10'h0C4 */
	union {
		uint32_t region_weight_set_32; // word name
		struct {
			uint32_t region_weight_128 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_129 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_130 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_131 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_33 10'h0C8 */
	union {
		uint32_t region_weight_set_33; // word name
		struct {
			uint32_t region_weight_132 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_133 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_134 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_135 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_34 10'h0CC */
	union {
		uint32_t region_weight_set_34; // word name
		struct {
			uint32_t region_weight_136 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_137 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_138 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_139 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_35 10'h0D0 */
	union {
		uint32_t region_weight_set_35; // word name
		struct {
			uint32_t region_weight_140 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_141 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_142 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_143 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_36 10'h0D4 */
	union {
		uint32_t region_weight_set_36; // word name
		struct {
			uint32_t region_weight_144 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_145 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_146 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_147 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_37 10'h0D8 */
	union {
		uint32_t region_weight_set_37; // word name
		struct {
			uint32_t region_weight_148 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_149 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_150 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_151 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_38 10'h0DC */
	union {
		uint32_t region_weight_set_38; // word name
		struct {
			uint32_t region_weight_152 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_153 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_154 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_155 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_39 10'h0E0 */
	union {
		uint32_t region_weight_set_39; // word name
		struct {
			uint32_t region_weight_156 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_157 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_158 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_159 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_40 10'h0E4 */
	union {
		uint32_t region_weight_set_40; // word name
		struct {
			uint32_t region_weight_160 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_161 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_162 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_163 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_41 10'h0E8 */
	union {
		uint32_t region_weight_set_41; // word name
		struct {
			uint32_t region_weight_164 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_165 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_166 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_167 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_42 10'h0EC */
	union {
		uint32_t region_weight_set_42; // word name
		struct {
			uint32_t region_weight_168 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_169 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_170 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_171 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_43 10'h0F0 */
	union {
		uint32_t region_weight_set_43; // word name
		struct {
			uint32_t region_weight_172 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_173 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_174 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_175 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_44 10'h0F4 */
	union {
		uint32_t region_weight_set_44; // word name
		struct {
			uint32_t region_weight_176 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_177 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_178 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_179 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_45 10'h0F8 */
	union {
		uint32_t region_weight_set_45; // word name
		struct {
			uint32_t region_weight_180 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_181 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_182 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_183 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_46 10'h0FC */
	union {
		uint32_t region_weight_set_46; // word name
		struct {
			uint32_t region_weight_184 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_185 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_186 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_187 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_47 10'h100 */
	union {
		uint32_t region_weight_set_47; // word name
		struct {
			uint32_t region_weight_188 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_189 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_190 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_191 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_48 10'h104 */
	union {
		uint32_t region_weight_set_48; // word name
		struct {
			uint32_t region_weight_192 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_193 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_194 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_195 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_49 10'h108 */
	union {
		uint32_t region_weight_set_49; // word name
		struct {
			uint32_t region_weight_196 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_197 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_198 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_199 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_50 10'h10C */
	union {
		uint32_t region_weight_set_50; // word name
		struct {
			uint32_t region_weight_200 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_201 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_202 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_203 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_51 10'h110 */
	union {
		uint32_t region_weight_set_51; // word name
		struct {
			uint32_t region_weight_204 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_205 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_206 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_207 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_52 10'h114 */
	union {
		uint32_t region_weight_set_52; // word name
		struct {
			uint32_t region_weight_208 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_209 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_210 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_211 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_53 10'h118 */
	union {
		uint32_t region_weight_set_53; // word name
		struct {
			uint32_t region_weight_212 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_213 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_214 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_215 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_54 10'h11C */
	union {
		uint32_t region_weight_set_54; // word name
		struct {
			uint32_t region_weight_216 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_217 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_218 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_219 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_55 10'h120 */
	union {
		uint32_t region_weight_set_55; // word name
		struct {
			uint32_t region_weight_220 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_221 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_222 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_223 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_56 10'h124 */
	union {
		uint32_t region_weight_set_56; // word name
		struct {
			uint32_t region_weight_224 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_225 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_226 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_227 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_57 10'h128 */
	union {
		uint32_t region_weight_set_57; // word name
		struct {
			uint32_t region_weight_228 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_229 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_230 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_231 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_58 10'h12C */
	union {
		uint32_t region_weight_set_58; // word name
		struct {
			uint32_t region_weight_232 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_233 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_234 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_235 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_59 10'h130 */
	union {
		uint32_t region_weight_set_59; // word name
		struct {
			uint32_t region_weight_236 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_237 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_238 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_239 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_60 10'h134 */
	union {
		uint32_t region_weight_set_60; // word name
		struct {
			uint32_t region_weight_240 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_241 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_242 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_243 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_61 10'h138 */
	union {
		uint32_t region_weight_set_61; // word name
		struct {
			uint32_t region_weight_244 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_245 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_246 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_247 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_62 10'h13C */
	union {
		uint32_t region_weight_set_62; // word name
		struct {
			uint32_t region_weight_248 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_249 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_250 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_251 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* REGION_WEIGHT_SET_63 10'h140 */
	union {
		uint32_t region_weight_set_63; // word name
		struct {
			uint32_t region_weight_252 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_253 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_254 : 2;
			uint32_t : 6; // padding bits
			uint32_t region_weight_255 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 10'h144 */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_0 10'h148 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
} CsrBankLpmd;

#endif