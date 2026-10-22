#ifndef CSR_BANK_ME_H_
#define CSR_BANK_ME_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from me  ***/
typedef struct csr_bank_me {
	/* ME000 10'h000 */
	union {
		uint32_t me000; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME001 10'h004 */
	union {
		uint32_t me001; // word name
		struct {
			uint32_t scene_change : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME002 10'h008 */
	union {
		uint32_t me002; // word name
		struct {
			uint32_t gmv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t gmv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME003 10'h00C */
	union {
		uint32_t me003; // word name
		struct {
			uint32_t gmv_cand_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME004 10'h010 */
	union {
		uint32_t me004; // word name
		struct {
			uint32_t bottom_left_dist_x : 4;
			uint32_t : 4; // padding bits
			uint32_t bottom_left_dist_y : 3;
			uint32_t : 5; // padding bits
			uint32_t bottom_right_dist_x : 4;
			uint32_t : 4; // padding bits
			uint32_t bottom_right_dist_y : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME005 10'h014 */
	union {
		uint32_t me005; // word name
		struct {
			uint32_t mode_left_mv_diff_th : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME006 10'h018 */
	union {
		uint32_t me006; // word name
		struct {
			uint32_t mode_top_left_mv_diff_th : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME007 10'h01C */
	union {
		uint32_t me007; // word name
		struct {
			uint32_t mode_top_right_mv_diff_th : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME008 10'h020 */
	union {
		uint32_t me008; // word name
		struct {
			uint32_t search_texture_th : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME009 10'h024 */
	union {
		uint32_t me009; // word name
		struct {
			uint32_t sw_ix : 5;
			uint32_t : 3; // padding bits
			uint32_t sw_iy : 4;
			uint32_t : 4; // padding bits
			uint32_t sw_ix_size : 6;
			uint32_t : 2; // padding bits
			uint32_t sw_iy_size : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* ME010 10'h028 */
	union {
		uint32_t me010; // word name
		struct {
			uint32_t sw_center_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_center_weight : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME011 10'h02C */
	union {
		uint32_t me011; // word name
		struct {
			uint32_t sw_center_x_sw : 10;
			uint32_t : 6; // padding bits
			uint32_t sw_center_y_sw : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME012 10'h030 */
	union {
		uint32_t me012; // word name
		struct {
			uint32_t ime_penalty_gain_x_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t ime_penalty_gain_y_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t ime_penalty_bound_x_ini : 8;
			uint32_t ime_penalty_bound_y_ini : 8;
		};
	};
	/* ME013 10'h034 */
	union {
		uint32_t me013; // word name
		struct {
			uint32_t matching_weight : 2;
			uint32_t : 6; // padding bits
			uint32_t range_weight : 6;
			uint32_t : 2; // padding bits
			uint32_t singularity_weight : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME014 10'h038 */
	union {
		uint32_t me014; // word name
		struct {
			uint32_t m_cost_quarter_gain : 6;
			uint32_t : 2; // padding bits
			uint32_t m_cost_half_gain : 6;
			uint32_t : 2; // padding bits
			uint32_t m_cost_frac_offset : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME015 10'h03C */
	union {
		uint32_t me015; // word name
		struct {
			uint32_t texture_gain_low_th : 13;
			uint32_t : 3; // padding bits
			uint32_t texture_gain_high_th : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* ME016 10'h040 */
	union {
		uint32_t me016; // word name
		struct {
			uint32_t texture_gain_low : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t texture_gain_high : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME017 10'h044 */
	union {
		uint32_t me017; // word name
		struct {
			uint32_t range_min_x_th : 10;
			uint32_t : 6; // padding bits
			uint32_t range_max_x_th : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME018 10'h048 */
	union {
		uint32_t me018; // word name
		struct {
			uint32_t singularity_min_th : 12;
			uint32_t : 4; // padding bits
			uint32_t singularity_max_th : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* ME019 10'h04C */
	union {
		uint32_t me019; // word name
		struct {
			uint32_t non_zero_mv_cost_offset : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME020 10'h050 */
	union {
		uint32_t me020; // word name
		struct {
			uint32_t spatial_cost_offset : 10;
			uint32_t : 6; // padding bits
			uint32_t temporal_cost_offset : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME021 10'h054 */
	union {
		uint32_t me021; // word name
		struct {
			uint32_t search_weak_cost_offset : 10;
			uint32_t : 6; // padding bits
			uint32_t search_cost_offset : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME022 10'h058 */
	union {
		uint32_t me022; // word name
		struct {
			uint32_t refine_cost_offset : 10;
			uint32_t : 6; // padding bits
			uint32_t gmv_cost_offset : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME023 10'h05C */
	union {
		uint32_t me023; // word name
		struct {
			uint32_t valid_true_mv_th : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME024 10'h060 */
	union {
		uint32_t me024; // word name
		struct {
			uint32_t mvr_left_extend_dist : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mvr_right_extend_dist : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME025 10'h064 */
	union {
		uint32_t me025; // word name
		struct {
			uint32_t texture_gain_slope : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME026 10'h068 */
	union {
		uint32_t me026; // word name
		struct {
			uint32_t range_min_y_th : 10;
			uint32_t : 6; // padding bits
			uint32_t range_max_y_th : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME027 10'h06C [Unused] */
	uint32_t empty_word_me027;
	/* ME028 10'h070 [Unused] */
	uint32_t empty_word_me028;
	/* ME029 10'h074 */
	union {
		uint32_t me029; // word name
		struct {
			uint32_t mv_roi_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME030 10'h078 */
	union {
		uint32_t me030; // word name
		struct {
			uint32_t mv_roi_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME031 10'h07C */
	union {
		uint32_t me031; // word name
		struct {
			uint32_t mv_roi_0_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t mv_roi_0_sy : 16;
		};
	};
	/* ME032 10'h080 */
	union {
		uint32_t me032; // word name
		struct {
			uint32_t mv_roi_0_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t mv_roi_0_ey : 16;
		};
	};
	/* ME033 10'h084 */
	union {
		uint32_t me033; // word name
		struct {
			uint32_t mv_roi_0_x_accuracy : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mv_roi_0_y_accuracy : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME034 10'h088 */
	union {
		uint32_t me034; // word name
		struct {
			uint32_t mv_roi_0_step : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME035 10'h08C */
	union {
		uint32_t me035; // word name
		struct {
			uint32_t mv_roi_0_hist_0 : 32;
		};
	};
	/* ME036 10'h090 */
	union {
		uint32_t me036; // word name
		struct {
			uint32_t mv_roi_0_hist_1 : 32;
		};
	};
	/* ME037 10'h094 */
	union {
		uint32_t me037; // word name
		struct {
			uint32_t mv_roi_0_hist_2 : 32;
		};
	};
	/* ME038 10'h098 */
	union {
		uint32_t me038; // word name
		struct {
			uint32_t mv_roi_0_hist_3 : 32;
		};
	};
	/* ME039 10'h09C */
	union {
		uint32_t me039; // word name
		struct {
			uint32_t mv_roi_0_hist_4 : 32;
		};
	};
	/* ME040 10'h0A0 */
	union {
		uint32_t me040; // word name
		struct {
			uint32_t mv_roi_0_hist_5 : 32;
		};
	};
	/* ME041 10'h0A4 */
	union {
		uint32_t me041; // word name
		struct {
			uint32_t mv_roi_0_hist_6 : 32;
		};
	};
	/* ME042 10'h0A8 */
	union {
		uint32_t me042; // word name
		struct {
			uint32_t mv_roi_0_hist_7 : 32;
		};
	};
	/* ME043 10'h0AC */
	union {
		uint32_t me043; // word name
		struct {
			uint32_t mv_roi_0_hist_8 : 32;
		};
	};
	/* ME044 10'h0B0 */
	union {
		uint32_t me044; // word name
		struct {
			uint32_t mv_roi_0_hist_9 : 32;
		};
	};
	/* ME045 10'h0B4 */
	union {
		uint32_t me045; // word name
		struct {
			uint32_t mv_roi_0_hist_10 : 32;
		};
	};
	/* ME046 10'h0B8 */
	union {
		uint32_t me046; // word name
		struct {
			uint32_t mv_roi_0_hist_11 : 32;
		};
	};
	/* ME047 10'h0BC */
	union {
		uint32_t me047; // word name
		struct {
			uint32_t mv_roi_0_hist_12 : 32;
		};
	};
	/* ME048 10'h0C0 */
	union {
		uint32_t me048; // word name
		struct {
			uint32_t mv_roi_0_hist_13 : 32;
		};
	};
	/* ME049 10'h0C4 */
	union {
		uint32_t me049; // word name
		struct {
			uint32_t mv_roi_0_hist_14 : 32;
		};
	};
	/* ME050 10'h0C8 */
	union {
		uint32_t me050; // word name
		struct {
			uint32_t mv_roi_0_hist_15 : 32;
		};
	};
	/* ME051 10'h0CC */
	union {
		uint32_t me051; // word name
		struct {
			uint32_t mv_roi_0_hist_16 : 32;
		};
	};
	/* ME052 10'h0D0 */
	union {
		uint32_t me052; // word name
		struct {
			uint32_t mv_roi_0_hist_17 : 32;
		};
	};
	/* ME053 10'h0D4 */
	union {
		uint32_t me053; // word name
		struct {
			uint32_t mv_roi_0_hist_18 : 32;
		};
	};
	/* ME054 10'h0D8 */
	union {
		uint32_t me054; // word name
		struct {
			uint32_t mv_roi_0_hist_19 : 32;
		};
	};
	/* ME055 10'h0DC */
	union {
		uint32_t me055; // word name
		struct {
			uint32_t mv_roi_0_hist_20 : 32;
		};
	};
	/* ME056 10'h0E0 */
	union {
		uint32_t me056; // word name
		struct {
			uint32_t mv_roi_0_hist_21 : 32;
		};
	};
	/* ME057 10'h0E4 */
	union {
		uint32_t me057; // word name
		struct {
			uint32_t mv_roi_0_hist_22 : 32;
		};
	};
	/* ME058 10'h0E8 */
	union {
		uint32_t me058; // word name
		struct {
			uint32_t mv_roi_0_hist_23 : 32;
		};
	};
	/* ME059 10'h0EC */
	union {
		uint32_t me059; // word name
		struct {
			uint32_t mv_roi_0_hist_24 : 32;
		};
	};
	/* ME060 10'h0F0 */
	union {
		uint32_t me060; // word name
		struct {
			uint32_t mv_roi_0_hist_25 : 32;
		};
	};
	/* ME061 10'h0F4 */
	union {
		uint32_t me061; // word name
		struct {
			uint32_t mv_roi_0_hist_26 : 32;
		};
	};
	/* ME062 10'h0F8 */
	union {
		uint32_t me062; // word name
		struct {
			uint32_t mv_roi_0_hist_27 : 32;
		};
	};
	/* ME063 10'h0FC */
	union {
		uint32_t me063; // word name
		struct {
			uint32_t mv_roi_0_hist_28 : 32;
		};
	};
	/* ME064 10'h100 */
	union {
		uint32_t me064; // word name
		struct {
			uint32_t mv_roi_0_hist_29 : 32;
		};
	};
	/* ME065 10'h104 */
	union {
		uint32_t me065; // word name
		struct {
			uint32_t mv_roi_0_hist_30 : 32;
		};
	};
	/* ME066 10'h108 */
	union {
		uint32_t me066; // word name
		struct {
			uint32_t mv_roi_0_hist_31 : 32;
		};
	};
	/* ME067 10'h10C */
	union {
		uint32_t me067; // word name
		struct {
			uint32_t mv_roi_0_valid_cnt : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME068 10'h110 */
	union {
		uint32_t me068; // word name
		struct {
			uint32_t strip_motion_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_1_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_2_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_3_clear : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ME069 10'h114 */
	union {
		uint32_t me069; // word name
		struct {
			uint32_t strip_motion_4_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_5_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_6_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_7_clear : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ME070 10'h118 */
	union {
		uint32_t me070; // word name
		struct {
			uint32_t strip_motion_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_0_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_0_th : 8;
			uint32_t strip_motion_0_qs : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME071 10'h11C */
	union {
		uint32_t me071; // word name
		struct {
			uint32_t strip_motion_0_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_0_sy : 16;
		};
	};
	/* ME072 10'h120 */
	union {
		uint32_t me072; // word name
		struct {
			uint32_t strip_motion_0_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_0_ey : 16;
		};
	};
	/* ME073 10'h124 */
	union {
		uint32_t me073; // word name
		struct {
			uint32_t strip_motion_1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_1_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_1_th : 8;
			uint32_t strip_motion_1_qs : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME074 10'h128 */
	union {
		uint32_t me074; // word name
		struct {
			uint32_t strip_motion_1_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_1_sy : 16;
		};
	};
	/* ME075 10'h12C */
	union {
		uint32_t me075; // word name
		struct {
			uint32_t strip_motion_1_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_1_ey : 16;
		};
	};
	/* ME076 10'h130 */
	union {
		uint32_t me076; // word name
		struct {
			uint32_t strip_motion_2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_2_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_2_th : 8;
			uint32_t strip_motion_2_qs : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME077 10'h134 */
	union {
		uint32_t me077; // word name
		struct {
			uint32_t strip_motion_2_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_2_sy : 16;
		};
	};
	/* ME078 10'h138 */
	union {
		uint32_t me078; // word name
		struct {
			uint32_t strip_motion_2_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_2_ey : 16;
		};
	};
	/* ME079 10'h13C */
	union {
		uint32_t me079; // word name
		struct {
			uint32_t strip_motion_3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_3_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_3_th : 8;
			uint32_t strip_motion_3_qs : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME080 10'h140 */
	union {
		uint32_t me080; // word name
		struct {
			uint32_t strip_motion_3_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_3_sy : 16;
		};
	};
	/* ME081 10'h144 */
	union {
		uint32_t me081; // word name
		struct {
			uint32_t strip_motion_3_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_3_ey : 16;
		};
	};
	/* ME082 10'h148 */
	union {
		uint32_t me082; // word name
		struct {
			uint32_t strip_motion_4_en : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_4_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_4_th : 8;
			uint32_t strip_motion_4_qs : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME083 10'h14C */
	union {
		uint32_t me083; // word name
		struct {
			uint32_t strip_motion_4_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_4_sy : 16;
		};
	};
	/* ME084 10'h150 */
	union {
		uint32_t me084; // word name
		struct {
			uint32_t strip_motion_4_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_4_ey : 16;
		};
	};
	/* ME085 10'h154 */
	union {
		uint32_t me085; // word name
		struct {
			uint32_t strip_motion_5_en : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_5_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_5_th : 8;
			uint32_t strip_motion_5_qs : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME086 10'h158 */
	union {
		uint32_t me086; // word name
		struct {
			uint32_t strip_motion_5_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_5_sy : 16;
		};
	};
	/* ME087 10'h15C */
	union {
		uint32_t me087; // word name
		struct {
			uint32_t strip_motion_5_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_5_ey : 16;
		};
	};
	/* ME088 10'h160 */
	union {
		uint32_t me088; // word name
		struct {
			uint32_t strip_motion_6_en : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_6_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_6_th : 8;
			uint32_t strip_motion_6_qs : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME089 10'h164 */
	union {
		uint32_t me089; // word name
		struct {
			uint32_t strip_motion_6_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_6_sy : 16;
		};
	};
	/* ME090 10'h168 */
	union {
		uint32_t me090; // word name
		struct {
			uint32_t strip_motion_6_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_6_ey : 16;
		};
	};
	/* ME091 10'h16C */
	union {
		uint32_t me091; // word name
		struct {
			uint32_t strip_motion_7_en : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_7_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_7_th : 8;
			uint32_t strip_motion_7_qs : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ME092 10'h170 */
	union {
		uint32_t me092; // word name
		struct {
			uint32_t strip_motion_7_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_7_sy : 16;
		};
	};
	/* ME093 10'h174 */
	union {
		uint32_t me093; // word name
		struct {
			uint32_t strip_motion_7_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t strip_motion_7_ey : 16;
		};
	};
	/* ME094 10'h178 */
	union {
		uint32_t me094; // word name
		struct {
			uint32_t strip_motion_0_index : 12;
			uint32_t : 4; // padding bits
			uint32_t strip_motion_1_index : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* ME095 10'h17C */
	union {
		uint32_t me095; // word name
		struct {
			uint32_t strip_motion_2_index : 12;
			uint32_t : 4; // padding bits
			uint32_t strip_motion_3_index : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* ME096 10'h180 */
	union {
		uint32_t me096; // word name
		struct {
			uint32_t strip_motion_4_index : 12;
			uint32_t : 4; // padding bits
			uint32_t strip_motion_5_index : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* ME097 10'h184 */
	union {
		uint32_t me097; // word name
		struct {
			uint32_t strip_motion_6_index : 12;
			uint32_t : 4; // padding bits
			uint32_t strip_motion_7_index : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* ME098 10'h188 [Unused] */
	uint32_t empty_word_me098;
	/* ME099 10'h18C [Unused] */
	uint32_t empty_word_me099;
	/* ME100 10'h190 */
	union {
		uint32_t me100; // word name
		struct {
			uint32_t tone_curve_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_1 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME101 10'h194 */
	union {
		uint32_t me101; // word name
		struct {
			uint32_t tone_curve_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME102 10'h198 */
	union {
		uint32_t me102; // word name
		struct {
			uint32_t tone_curve_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_5 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME103 10'h19C */
	union {
		uint32_t me103; // word name
		struct {
			uint32_t tone_curve_6 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_7 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME104 10'h1A0 */
	union {
		uint32_t me104; // word name
		struct {
			uint32_t tone_curve_8 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_9 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME105 10'h1A4 */
	union {
		uint32_t me105; // word name
		struct {
			uint32_t tone_curve_10 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_11 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME106 10'h1A8 */
	union {
		uint32_t me106; // word name
		struct {
			uint32_t tone_curve_12 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_13 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME107 10'h1AC */
	union {
		uint32_t me107; // word name
		struct {
			uint32_t tone_curve_14 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_15 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME108 10'h1B0 */
	union {
		uint32_t me108; // word name
		struct {
			uint32_t tone_curve_16 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_17 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME109 10'h1B4 */
	union {
		uint32_t me109; // word name
		struct {
			uint32_t tone_curve_18 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_19 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME110 10'h1B8 */
	union {
		uint32_t me110; // word name
		struct {
			uint32_t tone_curve_20 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_21 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME111 10'h1BC */
	union {
		uint32_t me111; // word name
		struct {
			uint32_t tone_curve_22 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_23 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME112 10'h1C0 */
	union {
		uint32_t me112; // word name
		struct {
			uint32_t tone_curve_24 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_25 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME113 10'h1C4 */
	union {
		uint32_t me113; // word name
		struct {
			uint32_t tone_curve_26 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_27 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME114 10'h1C8 */
	union {
		uint32_t me114; // word name
		struct {
			uint32_t tone_curve_28 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_29 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME115 10'h1CC */
	union {
		uint32_t me115; // word name
		struct {
			uint32_t tone_curve_30 : 10;
			uint32_t : 6; // padding bits
			uint32_t tone_curve_31 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME116 10'h1D0 */
	union {
		uint32_t me116; // word name
		struct {
			uint32_t tone_curve_32 : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME117 10'h1D4 [Unused] */
	uint32_t empty_word_me117;
	/* ME118 10'h1D8 [Unused] */
	uint32_t empty_word_me118;
	/* ME119 10'h1DC [Unused] */
	uint32_t empty_word_me119;
	/* ME120 10'h1E0 [Unused] */
	uint32_t empty_word_me120;
	/* ME121 10'h1E4 [Unused] */
	uint32_t empty_word_me121;
	/* ME122 10'h1E8 [Unused] */
	uint32_t empty_word_me122;
	/* ME123 10'h1EC [Unused] */
	uint32_t empty_word_me123;
	/* ME124 10'h1F0 */
	union {
		uint32_t me124; // word name
		struct {
			uint32_t y_avg_roi_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME125 10'h1F4 */
	union {
		uint32_t me125; // word name
		struct {
			uint32_t y_avg_roi_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME126 10'h1F8 */
	union {
		uint32_t me126; // word name
		struct {
			uint32_t y_avg_roi_0_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t y_avg_roi_0_sy : 16;
		};
	};
	/* ME127 10'h1FC */
	union {
		uint32_t me127; // word name
		struct {
			uint32_t y_avg_roi_0_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t y_avg_roi_0_ey : 16;
		};
	};
	/* ME128 10'h200 */
	union {
		uint32_t me128; // word name
		struct {
			uint32_t y_avg_roi_0_total_pix_cnt : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* ME129 10'h204 */
	union {
		uint32_t me129; // word name
		struct {
			uint32_t y_avg_roi_0_before_cte : 10;
			uint32_t : 6; // padding bits
			uint32_t y_avg_roi_0_after_cte : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME130 10'h208 */
	union {
		uint32_t me130; // word name
		struct {
			uint32_t texture_roi_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME131 10'h20C */
	union {
		uint32_t me131; // word name
		struct {
			uint32_t texture_roi_0_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t texture_roi_0_sy : 16;
		};
	};
	/* ME132 10'h210 */
	union {
		uint32_t me132; // word name
		struct {
			uint32_t texture_roi_0_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t texture_roi_0_ey : 16;
		};
	};
	/* ME133 10'h214 */
	union {
		uint32_t me133; // word name
		struct {
			uint32_t texture_roi_0_hor : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* ME134 10'h218 */
	union {
		uint32_t me134; // word name
		struct {
			uint32_t texture_roi_0_ver : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* ME135 10'h21C */
	union {
		uint32_t me135; // word name
		struct {
			uint32_t texture_roi_0_hor_ver : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* ME136 10'h220 */
	union {
		uint32_t me136; // word name
		struct {
			uint32_t texture_roi_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME137 10'h224 [Unused] */
	uint32_t empty_word_me137;
	/* ME138 10'h228 [Unused] */
	uint32_t empty_word_me138;
	/* ME139 10'h22C */
	union {
		uint32_t me139; // word name
		struct {
			uint32_t fg_y_roi_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME140 10'h230 */
	union {
		uint32_t me140; // word name
		struct {
			uint32_t fg_y_roi_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME141 10'h234 */
	union {
		uint32_t me141; // word name
		struct {
			uint32_t fg_y_roi_0_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t fg_y_roi_0_sy : 16;
		};
	};
	/* ME142 10'h238 */
	union {
		uint32_t me142; // word name
		struct {
			uint32_t fg_y_roi_0_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t fg_y_roi_0_ey : 16;
		};
	};
	/* ME143 10'h23C */
	union {
		uint32_t me143; // word name
		struct {
			uint32_t fg_y_roi_0_soft_clip_slope : 8;
			uint32_t : 8; // padding bits
			uint32_t fg_y_roi_0_soft_clip_th : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* ME144 10'h240 */
	union {
		uint32_t me144; // word name
		struct {
			uint32_t fg_y_roi_0_gmv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t fg_y_roi_0_gmv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME145 10'h244 */
	union {
		uint32_t me145; // word name
		struct {
			uint32_t fg_y_roi_0_conf : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME146 10'h248 */
	union {
		uint32_t me146; // word name
		struct {
			uint32_t fg_y_roi_0_pix_sum : 32;
		};
	};
	/* ME147 10'h24C */
	union {
		uint32_t me147; // word name
		struct {
			uint32_t fg_y_roi_0_hist_0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME148 10'h250 */
	union {
		uint32_t me148; // word name
		struct {
			uint32_t fg_y_roi_0_hist_1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME149 10'h254 */
	union {
		uint32_t me149; // word name
		struct {
			uint32_t fg_y_roi_0_hist_2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME150 10'h258 */
	union {
		uint32_t me150; // word name
		struct {
			uint32_t fg_y_roi_0_hist_3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME151 10'h25C */
	union {
		uint32_t me151; // word name
		struct {
			uint32_t fg_y_roi_0_hist_4 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME152 10'h260 */
	union {
		uint32_t me152; // word name
		struct {
			uint32_t fg_y_roi_0_hist_5 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME153 10'h264 */
	union {
		uint32_t me153; // word name
		struct {
			uint32_t fg_y_roi_0_hist_6 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME154 10'h268 */
	union {
		uint32_t me154; // word name
		struct {
			uint32_t fg_y_roi_0_hist_7 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME155 10'h26C */
	union {
		uint32_t me155; // word name
		struct {
			uint32_t fg_y_roi_0_hist_8 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME156 10'h270 */
	union {
		uint32_t me156; // word name
		struct {
			uint32_t fg_y_roi_0_hist_9 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME157 10'h274 */
	union {
		uint32_t me157; // word name
		struct {
			uint32_t fg_y_roi_0_hist_10 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME158 10'h278 */
	union {
		uint32_t me158; // word name
		struct {
			uint32_t fg_y_roi_0_hist_11 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME159 10'h27C */
	union {
		uint32_t me159; // word name
		struct {
			uint32_t fg_y_roi_0_hist_12 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME160 10'h280 */
	union {
		uint32_t me160; // word name
		struct {
			uint32_t fg_y_roi_0_hist_13 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME161 10'h284 */
	union {
		uint32_t me161; // word name
		struct {
			uint32_t fg_y_roi_0_hist_14 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME162 10'h288 */
	union {
		uint32_t me162; // word name
		struct {
			uint32_t fg_y_roi_0_hist_15 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME163 10'h28C */
	union {
		uint32_t me163; // word name
		struct {
			uint32_t fg_y_roi_0_hist_16 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME164 10'h290 */
	union {
		uint32_t me164; // word name
		struct {
			uint32_t fg_y_roi_0_hist_17 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME165 10'h294 */
	union {
		uint32_t me165; // word name
		struct {
			uint32_t fg_y_roi_0_hist_18 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME166 10'h298 */
	union {
		uint32_t me166; // word name
		struct {
			uint32_t fg_y_roi_0_hist_19 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME167 10'h29C */
	union {
		uint32_t me167; // word name
		struct {
			uint32_t fg_y_roi_0_hist_20 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME168 10'h2A0 */
	union {
		uint32_t me168; // word name
		struct {
			uint32_t fg_y_roi_0_hist_21 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME169 10'h2A4 */
	union {
		uint32_t me169; // word name
		struct {
			uint32_t fg_y_roi_0_hist_22 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME170 10'h2A8 */
	union {
		uint32_t me170; // word name
		struct {
			uint32_t fg_y_roi_0_hist_23 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME171 10'h2AC */
	union {
		uint32_t me171; // word name
		struct {
			uint32_t fg_y_roi_0_hist_24 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME172 10'h2B0 */
	union {
		uint32_t me172; // word name
		struct {
			uint32_t fg_y_roi_0_hist_25 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME173 10'h2B4 */
	union {
		uint32_t me173; // word name
		struct {
			uint32_t fg_y_roi_0_hist_26 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME174 10'h2B8 */
	union {
		uint32_t me174; // word name
		struct {
			uint32_t fg_y_roi_0_hist_27 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME175 10'h2BC */
	union {
		uint32_t me175; // word name
		struct {
			uint32_t fg_y_roi_0_hist_28 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME176 10'h2C0 */
	union {
		uint32_t me176; // word name
		struct {
			uint32_t fg_y_roi_0_hist_29 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME177 10'h2C4 */
	union {
		uint32_t me177; // word name
		struct {
			uint32_t fg_y_roi_0_hist_30 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME178 10'h2C8 */
	union {
		uint32_t me178; // word name
		struct {
			uint32_t fg_y_roi_0_hist_31 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME179 10'h2CC */
	union {
		uint32_t me179; // word name
		struct {
			uint32_t fg_y_roi_0_hist_32 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME180 10'h2D0 */
	union {
		uint32_t me180; // word name
		struct {
			uint32_t fg_texture_roi_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME181 10'h2D4 */
	union {
		uint32_t me181; // word name
		struct {
			uint32_t fg_texture_roi_0_sx : 9;
			uint32_t : 7; // padding bits
			uint32_t fg_texture_roi_0_sy : 16;
		};
	};
	/* ME182 10'h2D8 */
	union {
		uint32_t me182; // word name
		struct {
			uint32_t fg_texture_roi_0_ex : 9;
			uint32_t : 7; // padding bits
			uint32_t fg_texture_roi_0_ey : 16;
		};
	};
	/* ME183 10'h2DC */
	union {
		uint32_t me183; // word name
		struct {
			uint32_t fg_texture_roi_0_soft_clip_slope : 8;
			uint32_t : 8; // padding bits
			uint32_t fg_texture_roi_0_soft_clip_th : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* ME184 10'h2E0 */
	union {
		uint32_t me184; // word name
		struct {
			uint32_t fg_texture_roi_0_gmv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t fg_texture_roi_0_gmv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME185 10'h2E4 */
	union {
		uint32_t me185; // word name
		struct {
			uint32_t fg_texture_roi_0_conf : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME186 10'h2E8 */
	union {
		uint32_t me186; // word name
		struct {
			uint32_t fg_texture_roi_0_hor : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* ME187 10'h2EC */
	union {
		uint32_t me187; // word name
		struct {
			uint32_t fg_texture_roi_0_ver : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* ME188 10'h2F0 */
	union {
		uint32_t me188; // word name
		struct {
			uint32_t fg_texture_roi_0_hor_ver : 31;
			uint32_t : 1; // padding bits
		};
	};
	/* ME189 10'h2F4 */
	union {
		uint32_t me189; // word name
		struct {
			uint32_t fg_texture_roi_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME190 10'h2F8 */
	union {
		uint32_t me190; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* ME191 10'h2FC */
	union {
		uint32_t me191; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* ME192 10'h300 */
	union {
		uint32_t me192; // word name
		struct {
			uint32_t reserved_2 : 32;
		};
	};
	/* ME193 10'h304 */
	union {
		uint32_t me193; // word name
		struct {
			uint32_t reserved_3 : 32;
		};
	};
	/* ME194 10'h308 */
	union {
		uint32_t me194; // word name
		struct {
			uint32_t mv_ink_range_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME195 10'h30C */
	union {
		uint32_t me195; // word name
		struct {
			uint32_t probe_en : 1;
			uint32_t : 7; // padding bits
			uint32_t probe_debug_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME196 10'h310 */
	union {
		uint32_t me196; // word name
		struct {
			uint32_t probe_x : 9;
			uint32_t : 7; // padding bits
			uint32_t probe_y : 16;
		};
	};
	/* ME197 10'h314 */
	union {
		uint32_t me197; // word name
		struct {
			uint32_t probe_cur_zero_texture : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME198 10'h318 */
	union {
		uint32_t me198; // word name
		struct {
			uint32_t probe_searched_mv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t probe_searched_mv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME199 10'h31C */
	union {
		uint32_t me199; // word name
		struct {
			uint32_t probe_searched_mv_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t probe_searched_mv_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME200 10'h320 */
	union {
		uint32_t me200; // word name
		struct {
			uint32_t probe_searched_ref_texture_clip : 13;
			uint32_t : 3; // padding bits
			uint32_t probe_searched_m_cost_raw : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* ME201 10'h324 */
	union {
		uint32_t me201; // word name
		struct {
			uint32_t probe_spatial_0_mv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t probe_spatial_0_mv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME202 10'h328 */
	union {
		uint32_t me202; // word name
		struct {
			uint32_t probe_spatial_0_mv_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t probe_spatial_0_mv_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME203 10'h32C */
	union {
		uint32_t me203; // word name
		struct {
			uint32_t probe_spatial_0_ref_texture_clip : 13;
			uint32_t : 3; // padding bits
			uint32_t probe_spatial_0_m_cost_raw : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* ME204 10'h330 */
	union {
		uint32_t me204; // word name
		struct {
			uint32_t probe_spatial_1_mv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t probe_spatial_1_mv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME205 10'h334 */
	union {
		uint32_t me205; // word name
		struct {
			uint32_t probe_spatial_1_mv_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t probe_spatial_1_mv_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME206 10'h338 */
	union {
		uint32_t me206; // word name
		struct {
			uint32_t probe_spatial_1_ref_texture_clip : 13;
			uint32_t : 3; // padding bits
			uint32_t probe_spatial_1_m_cost_raw : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* ME207 10'h33C */
	union {
		uint32_t me207; // word name
		struct {
			uint32_t probe_spatial_2_mv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t probe_spatial_2_mv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME208 10'h340 */
	union {
		uint32_t me208; // word name
		struct {
			uint32_t probe_spatial_2_mv_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t probe_spatial_2_mv_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME209 10'h344 */
	union {
		uint32_t me209; // word name
		struct {
			uint32_t probe_spatial_2_ref_texture_clip : 13;
			uint32_t : 3; // padding bits
			uint32_t probe_spatial_2_m_cost_raw : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* ME210 10'h348 */
	union {
		uint32_t me210; // word name
		struct {
			uint32_t probe_temporal_0_mv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t probe_temporal_0_mv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME211 10'h34C */
	union {
		uint32_t me211; // word name
		struct {
			uint32_t probe_temporal_0_mv_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t probe_temporal_0_mv_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME212 10'h350 */
	union {
		uint32_t me212; // word name
		struct {
			uint32_t probe_temporal_0_ref_texture_clip : 13;
			uint32_t : 3; // padding bits
			uint32_t probe_temporal_0_m_cost_raw : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* ME213 10'h354 */
	union {
		uint32_t me213; // word name
		struct {
			uint32_t probe_temporal_1_mv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t probe_temporal_1_mv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME214 10'h358 */
	union {
		uint32_t me214; // word name
		struct {
			uint32_t probe_temporal_1_mv_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t probe_temporal_1_mv_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME215 10'h35C */
	union {
		uint32_t me215; // word name
		struct {
			uint32_t probe_temporal_1_ref_texture_clip : 13;
			uint32_t : 3; // padding bits
			uint32_t probe_temporal_1_m_cost_raw : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* ME216 10'h360 */
	union {
		uint32_t me216; // word name
		struct {
			uint32_t probe_refined_mv_x : 10;
			uint32_t : 6; // padding bits
			uint32_t probe_refined_mv_y : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* ME217 10'h364 */
	union {
		uint32_t me217; // word name
		struct {
			uint32_t probe_refined_mv_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ME218 10'h368 */
	union {
		uint32_t me218; // word name
		struct {
			uint32_t probe_refined_ref_texture_clip : 13;
			uint32_t : 3; // padding bits
			uint32_t probe_refined_m_cost_raw : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* ME219 10'h36C */
	union {
		uint32_t me219; // word name
		struct {
			uint32_t probe_gmv_ref_texture_clip : 13;
			uint32_t : 3; // padding bits
			uint32_t probe_gmv_m_cost_raw : 15;
			uint32_t : 1; // padding bits
		};
	};
} CsrBankMe;

#endif