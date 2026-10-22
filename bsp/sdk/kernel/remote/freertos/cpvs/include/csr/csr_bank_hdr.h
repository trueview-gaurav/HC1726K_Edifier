#ifndef CSR_BANK_HDR_H_
#define CSR_BANK_HDR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from hdr  ***/
typedef struct csr_bank_hdr {
	/* HDR00 9'h000 */
	union {
		uint32_t hdr00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR01 9'h004 */
	union {
		uint32_t hdr01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR02 9'h008 */
	union {
		uint32_t hdr02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR03 9'h00C */
	union {
		uint32_t hdr03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR04 9'h010 [Unused] */
	uint32_t empty_word_hdr04;
	/* HDR05 9'h014 */
	union {
		uint32_t hdr05; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* HDR06 9'h018 */
	union {
		uint32_t hdr06; // word name
		struct {
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t bayer_ini_phase_i : 2;
			uint32_t : 6; // padding bits
			uint32_t exp_long_early : 1;
			uint32_t : 7; // padding bits
			uint32_t hdr_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR07 9'h01C */
	union {
		uint32_t hdr07; // word name
		struct {
			uint32_t exp_ratio : 9;
			uint32_t : 7; // padding bits
			uint32_t exp_ratio_inv : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* HDR08 9'h020 */
	union {
		uint32_t hdr08; // word name
		struct {
			uint32_t se_anti_gamma_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t le_anti_gamma_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR09 9'h024 */
	union {
		uint32_t hdr09; // word name
		struct {
			uint32_t se_weight_th_min : 13;
			uint32_t : 3; // padding bits
			uint32_t se_weight_slope : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR10 9'h028 */
	union {
		uint32_t hdr10; // word name
		struct {
			uint32_t se_weight_min : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t se_weight_max : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR11 9'h02C */
	union {
		uint32_t hdr11; // word name
		struct {
			uint32_t le_weight_th_max : 13;
			uint32_t : 3; // padding bits
			uint32_t le_weight_slope : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR12 9'h030 */
	union {
		uint32_t hdr12; // word name
		struct {
			uint32_t le_weight_min : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t le_weight_max : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR13 9'h034 */
	union {
		uint32_t hdr13; // word name
		struct {
			uint32_t mismatch_var_gain_2s : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR14 9'h038 */
	union {
		uint32_t hdr14; // word name
		struct {
			uint32_t local_fb_th : 12;
			uint32_t : 4; // padding bits
			uint32_t local_fb_slope : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR15 9'h03C */
	union {
		uint32_t hdr15; // word name
		struct {
			uint32_t local_fb_min : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t local_fb_max : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR16 9'h040 */
	union {
		uint32_t hdr16; // word name
		struct {
			uint32_t frame_fb_strength : 5;
			uint32_t : 3; // padding bits
			uint32_t fb_target : 1;
			uint32_t : 7; // padding bits
			uint32_t fb_alpha : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR17 9'h044 */
	union {
		uint32_t hdr17; // word name
		struct {
			uint32_t se_exp_ratio_min_int : 5;
			uint32_t : 3; // padding bits
			uint32_t tm_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR18 9'h048 */
	union {
		uint32_t hdr18; // word name
		struct {
			uint32_t tone_curve_1 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_2 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR19 9'h04C */
	union {
		uint32_t hdr19; // word name
		struct {
			uint32_t tone_curve_3 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_4 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR20 9'h050 */
	union {
		uint32_t hdr20; // word name
		struct {
			uint32_t tone_curve_5 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_6 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR21 9'h054 */
	union {
		uint32_t hdr21; // word name
		struct {
			uint32_t tone_curve_7 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_8 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR22 9'h058 */
	union {
		uint32_t hdr22; // word name
		struct {
			uint32_t tone_curve_9 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_10 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR23 9'h05C */
	union {
		uint32_t hdr23; // word name
		struct {
			uint32_t tone_curve_11 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_12 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR24 9'h060 */
	union {
		uint32_t hdr24; // word name
		struct {
			uint32_t tone_curve_13 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_14 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR25 9'h064 */
	union {
		uint32_t hdr25; // word name
		struct {
			uint32_t tone_curve_15 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_16 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR26 9'h068 */
	union {
		uint32_t hdr26; // word name
		struct {
			uint32_t tone_curve_17 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_18 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR27 9'h06C */
	union {
		uint32_t hdr27; // word name
		struct {
			uint32_t tone_curve_19 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_20 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR28 9'h070 */
	union {
		uint32_t hdr28; // word name
		struct {
			uint32_t tone_curve_21 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_22 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR29 9'h074 */
	union {
		uint32_t hdr29; // word name
		struct {
			uint32_t tone_curve_23 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_24 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR30 9'h078 */
	union {
		uint32_t hdr30; // word name
		struct {
			uint32_t tone_curve_25 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_26 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR31 9'h07C */
	union {
		uint32_t hdr31; // word name
		struct {
			uint32_t tone_curve_27 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_28 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR32 9'h080 */
	union {
		uint32_t hdr32; // word name
		struct {
			uint32_t tone_curve_29 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_30 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR33 9'h084 */
	union {
		uint32_t hdr33; // word name
		struct {
			uint32_t tone_curve_31 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_32 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR34 9'h088 */
	union {
		uint32_t hdr34; // word name
		struct {
			uint32_t tone_curve_33 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_34 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR35 9'h08C */
	union {
		uint32_t hdr35; // word name
		struct {
			uint32_t tone_curve_35 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_36 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR36 9'h090 */
	union {
		uint32_t hdr36; // word name
		struct {
			uint32_t tone_curve_37 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_38 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR37 9'h094 */
	union {
		uint32_t hdr37; // word name
		struct {
			uint32_t tone_curve_39 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_40 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR38 9'h098 */
	union {
		uint32_t hdr38; // word name
		struct {
			uint32_t tone_curve_41 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_42 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR39 9'h09C */
	union {
		uint32_t hdr39; // word name
		struct {
			uint32_t tone_curve_43 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_44 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR40 9'h0A0 */
	union {
		uint32_t hdr40; // word name
		struct {
			uint32_t tone_curve_45 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_46 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR41 9'h0A4 */
	union {
		uint32_t hdr41; // word name
		struct {
			uint32_t tone_curve_47 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_48 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR42 9'h0A8 */
	union {
		uint32_t hdr42; // word name
		struct {
			uint32_t tone_curve_49 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_50 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR43 9'h0AC */
	union {
		uint32_t hdr43; // word name
		struct {
			uint32_t tone_curve_51 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_52 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR44 9'h0B0 */
	union {
		uint32_t hdr44; // word name
		struct {
			uint32_t tone_curve_53 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_54 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR45 9'h0B4 */
	union {
		uint32_t hdr45; // word name
		struct {
			uint32_t tone_curve_55 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_56 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR46 9'h0B8 */
	union {
		uint32_t hdr46; // word name
		struct {
			uint32_t tone_curve_57 : 14;
			uint32_t : 2; // padding bits
			uint32_t tone_curve_58 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* HDR47 9'h0BC */
	union {
		uint32_t hdr47; // word name
		struct {
			uint32_t awb_gain_0 : 12;
			uint32_t : 4; // padding bits
			uint32_t awb_gain_1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* HDR48 9'h0C0 */
	union {
		uint32_t hdr48; // word name
		struct {
			uint32_t awb_gain_2 : 12;
			uint32_t : 4; // padding bits
			uint32_t awb_gain_3 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* HDR49 9'h0C4 */
	union {
		uint32_t hdr49; // word name
		struct {
			uint32_t gamma_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR50 9'h0C8 */
	union {
		uint32_t hdr50; // word name
		struct {
			uint32_t efuse_dis_hdr_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR51 9'h0CC */
	union {
		uint32_t hdr51; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* HDR52 9'h0D0 */
	union {
		uint32_t hdr52; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* HDR53 9'h0D4 */
	union {
		uint32_t hdr53; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AWB_EN 9'h0D8 */
	union {
		uint32_t awb_en; // word name
		struct {
			uint32_t awb_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankHdr;

#endif