/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_VENC_H_
#define CSR_BANK_VENC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from venc  ***/
typedef struct csr_bank_venc {
	/* FRM_START 10'h000 */
	union {
		uint32_t frm_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 10'h004 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_seq_hdr_cont : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 10'h008 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_seq_hdr_cont : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 10'h00C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_seq_hdr_cont : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_FRAME_SIZE 10'h010 */
	union {
		uint32_t venc_frame_size; // word name
		struct {
			uint32_t frm_mb_hor_num_m1 : 12;
			uint32_t : 4; // padding bits
			uint32_t frm_mb_ver_num_m1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_FRAME_TYPE 10'h014 */
	union {
		uint32_t venc_frame_type; // word name
		struct {
			uint32_t slice_type : 2;
			uint32_t : 6; // padding bits
			uint32_t is_seq_header : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_FRAME_BYTE 10'h018 */
	union {
		uint32_t venc_frame_byte; // word name
		struct {
			uint32_t frame_bs_byte_length : 32;
		};
	};
	/* VENC_ENC_TOOL_0 10'h01C */
	union {
		uint32_t venc_enc_tool_0; // word name
		struct {
			uint32_t entropy_coding_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t transform_8x8_mode_flag : 1;
			uint32_t : 7; // padding bits
			uint32_t enable_long_term_ref_frm : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* VENC_ENC_TOOL_1 10'h020 */
	union {
		uint32_t venc_enc_tool_1; // word name
		struct {
			uint32_t enable_sao : 1;
			uint32_t : 7; // padding bits
			uint32_t hevc_seq_rc_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_DEBLK_TOOL 10'h024 */
	union {
		uint32_t venc_deblk_tool; // word name
		struct {
			uint32_t disable_deblocking_filter : 1;
			uint32_t : 7; // padding bits
			uint32_t alpha_c0_offset_div2 : 4;
			uint32_t : 4; // padding bits
			uint32_t beta_offset_div2 : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEF_CUT 10'h028 */
	union {
		uint32_t venc_coef_cut; // word name
		struct {
			uint32_t luma_coef_cost_cut_th : 8;
			uint32_t luma_8x8_coef_cost_cut_th : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MB_STILL 10'h02C */
	union {
		uint32_t venc_mb_still; // word name
		struct {
			uint32_t set_normal_mb_still : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t set_roi_mb_still : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_HDR_SETTING 10'h030 */
	union {
		uint32_t venc_hdr_setting; // word name
		struct {
			uint32_t hdr_data_length : 8;
			uint32_t : 8; // padding bits
			uint32_t hdr_data_last : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_SR_UP_SET 10'h034 */
	union {
		uint32_t venc_sr_up_set; // word name
		struct {
			uint32_t sr_up_mv_range : 3;
			uint32_t : 5; // padding bits
			uint32_t sr_up_mv_disable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_SR_SEARCH_SET 10'h038 */
	union {
		uint32_t venc_sr_search_set; // word name
		struct {
			uint32_t sr_max_hor_range : 8;
			uint32_t sr_max_ver_range : 7;
			uint32_t : 1; // padding bits
			uint32_t sr_max_levelc_ver_range : 7;
			uint32_t : 1; // padding bits
			uint32_t sr_extend_refr : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* VENC_MERGE_MV_CAND 10'h03C */
	union {
		uint32_t venc_merge_mv_cand; // word name
		struct {
			uint32_t max_num_merge_cand : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MV_QUALITY 10'h040 */
	union {
		uint32_t venc_mv_quality; // word name
		struct {
			uint32_t texture_minmax_threshold : 4;
			uint32_t : 4; // padding bits
			uint32_t apply_mv_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_INTER_MODE_PARAM 10'h044 [Unused] */
	uint32_t empty_word_venc_inter_mode_param;
	/* VENC_INTRA_MODE_PARAM 10'h048 */
	union {
		uint32_t venc_intra_mode_param; // word name
		struct {
			uint32_t intra_cip_offset_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_HDR_DATA_0 10'h04C */
	union {
		uint32_t venc_hdr_data_0; // word name
		struct {
			uint32_t hdr_data_0 : 32;
		};
	};
	/* VENC_HDR_DATA_1 10'h050 */
	union {
		uint32_t venc_hdr_data_1; // word name
		struct {
			uint32_t hdr_data_1 : 32;
		};
	};
	/* VENC_HDR_DATA_2 10'h054 */
	union {
		uint32_t venc_hdr_data_2; // word name
		struct {
			uint32_t hdr_data_2 : 32;
		};
	};
	/* VENC_HDR_DATA_3 10'h058 */
	union {
		uint32_t venc_hdr_data_3; // word name
		struct {
			uint32_t hdr_data_3 : 32;
		};
	};
	/* VENC_MINMAX_RATIO_0 10'h05C */
	union {
		uint32_t venc_minmax_ratio_0; // word name
		struct {
			uint32_t minmax_0_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_1_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_2_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_3_ratio : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MINMAX_RATIO_1 10'h060 */
	union {
		uint32_t venc_minmax_ratio_1; // word name
		struct {
			uint32_t minmax_4_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_5_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_6_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_7_ratio : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MINMAX_RATIO_2 10'h064 */
	union {
		uint32_t venc_minmax_ratio_2; // word name
		struct {
			uint32_t minmax_8_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_9_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_10_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_11_ratio : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MINMAX_RATIO_3 10'h068 */
	union {
		uint32_t venc_minmax_ratio_3; // word name
		struct {
			uint32_t minmax_12_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_13_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_14_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_15_ratio : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MINMAX_RATIO_4 10'h06C */
	union {
		uint32_t venc_minmax_ratio_4; // word name
		struct {
			uint32_t minmax_16_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t minmax_other_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_HEVC_INTRA_MODE 10'h070 */
	union {
		uint32_t venc_hevc_intra_mode; // word name
		struct {
			uint32_t hevc_i8_mode_num_m1 : 6;
			uint32_t : 2; // padding bits
			uint32_t hevc_i16_mode_num_m1 : 6;
			uint32_t : 2; // padding bits
			uint32_t hevc_i32_mode_num_m1 : 6;
			uint32_t : 2; // padding bits
			uint32_t hevc_cip_mode_num_m1 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* VENC_ROI_TYPE9 10'h074 */
	union {
		uint32_t venc_roi_type9; // word name
		struct {
			uint32_t roi_type9_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_ENABLE 10'h078 */
	union {
		uint32_t venc_mbrc_enable; // word name
		struct {
			uint32_t mbrc_ink_en : 1;
			uint32_t : 7; // padding bits
			uint32_t mbrc_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_TH 10'h07C */
	union {
		uint32_t venc_mbrc_complex_th; // word name
		struct {
			uint32_t mbrc_spatial_complexity_th : 10;
			uint32_t : 6; // padding bits
			uint32_t mbrc_var_coring_th : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_0_INFO_QP 10'h080 */
	union {
		uint32_t venc_mbrc_complex_level_0_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_0_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_0_INFO_LAMBDA 10'h084 */
	union {
		uint32_t venc_mbrc_complex_level_0_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_0_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_0_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_1_INFO_QP 10'h088 */
	union {
		uint32_t venc_mbrc_complex_level_1_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_1_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_1_INFO_LAMBDA 10'h08C */
	union {
		uint32_t venc_mbrc_complex_level_1_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_1_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_1_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_2_INFO_QP 10'h090 */
	union {
		uint32_t venc_mbrc_complex_level_2_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_2_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_2_INFO_LAMBDA 10'h094 */
	union {
		uint32_t venc_mbrc_complex_level_2_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_2_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_2_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_3_INFO_QP 10'h098 */
	union {
		uint32_t venc_mbrc_complex_level_3_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_3_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_3_INFO_LAMBDA 10'h09C */
	union {
		uint32_t venc_mbrc_complex_level_3_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_3_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_3_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_4_INFO_QP 10'h0A0 */
	union {
		uint32_t venc_mbrc_complex_level_4_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_4_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_4_INFO_LAMBDA 10'h0A4 */
	union {
		uint32_t venc_mbrc_complex_level_4_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_4_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_4_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_5_INFO_QP 10'h0A8 */
	union {
		uint32_t venc_mbrc_complex_level_5_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_5_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_5_INFO_LAMBDA 10'h0AC */
	union {
		uint32_t venc_mbrc_complex_level_5_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_5_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_5_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_6_INFO_QP 10'h0B0 */
	union {
		uint32_t venc_mbrc_complex_level_6_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_6_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_6_INFO_LAMBDA 10'h0B4 */
	union {
		uint32_t venc_mbrc_complex_level_6_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_6_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_6_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_7_INFO_QP 10'h0B8 */
	union {
		uint32_t venc_mbrc_complex_level_7_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_7_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_7_INFO_LAMBDA 10'h0BC */
	union {
		uint32_t venc_mbrc_complex_level_7_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_7_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_7_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_8_INFO_QP 10'h0C0 */
	union {
		uint32_t venc_mbrc_complex_level_8_info_qp; // word name
		struct {
			uint32_t mbrc_complex_level_8_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_LEVEL_8_INFO_LAMBDA 10'h0C4 */
	union {
		uint32_t venc_mbrc_complex_level_8_info_lambda; // word name
		struct {
			uint32_t mbrc_complex_level_8_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t mbrc_complex_level_8_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_MBRC_COMPLEX_ALPHA 10'h0C8 */
	union {
		uint32_t venc_mbrc_complex_alpha; // word name
		struct {
			uint32_t mbrc_complex_alpha_parti_min : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mbrc_complex_alpha_dir_min : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COMPLEX_DIR_TH_I32 10'h0CC */
	union {
		uint32_t venc_md_complex_dir_th_i32; // word name
		struct {
			uint32_t md_mode_dir_th_i32 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COMPLEX_DIR_TH_I16 10'h0D0 */
	union {
		uint32_t venc_md_complex_dir_th_i16; // word name
		struct {
			uint32_t md_mode_dir_th_i16 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COMPLEX_DIR_TH_I8 10'h0D4 */
	union {
		uint32_t venc_md_complex_dir_th_i8; // word name
		struct {
			uint32_t md_mode_dir_th_i8 : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_I32_STRONG_SMOOTH 10'h0D8 */
	union {
		uint32_t venc_md_i32_strong_smooth; // word name
		struct {
			uint32_t strong_intra_smoothing_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I32_DC 10'h0DC */
	union {
		uint32_t venc_md_cost_offset_i32_dc; // word name
		struct {
			uint32_t md_mode_cost_offset_i32_dc : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I32_PLANE 10'h0E0 */
	union {
		uint32_t venc_md_cost_offset_i32_plane; // word name
		struct {
			uint32_t md_mode_cost_offset_i32_plane : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I32_ANG_HV 10'h0E4 */
	union {
		uint32_t venc_md_cost_offset_i32_ang_hv; // word name
		struct {
			uint32_t md_mode_cost_offset_i32_ang_hv : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I32_ANG_SLASH 10'h0E8 */
	union {
		uint32_t venc_md_cost_offset_i32_ang_slash; // word name
		struct {
			uint32_t md_mode_cost_offset_i32_ang_slash : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I16_DC 10'h0EC */
	union {
		uint32_t venc_md_cost_offset_i16_dc; // word name
		struct {
			uint32_t md_mode_cost_offset_i16_dc : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I16_PLANE 10'h0F0 */
	union {
		uint32_t venc_md_cost_offset_i16_plane; // word name
		struct {
			uint32_t md_mode_cost_offset_i16_plane : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I16_ANG_HV 10'h0F4 */
	union {
		uint32_t venc_md_cost_offset_i16_ang_hv; // word name
		struct {
			uint32_t md_mode_cost_offset_i16_ang_hv : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I16_ANG_SLASH 10'h0F8 */
	union {
		uint32_t venc_md_cost_offset_i16_ang_slash; // word name
		struct {
			uint32_t md_mode_cost_offset_i16_ang_slash : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I8_DC 10'h0FC */
	union {
		uint32_t venc_md_cost_offset_i8_dc; // word name
		struct {
			uint32_t md_mode_cost_offset_i8_dc : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I8_PLANE 10'h100 */
	union {
		uint32_t venc_md_cost_offset_i8_plane; // word name
		struct {
			uint32_t md_mode_cost_offset_i8_plane : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I8_ANG_HV 10'h104 */
	union {
		uint32_t venc_md_cost_offset_i8_ang_hv; // word name
		struct {
			uint32_t md_mode_cost_offset_i8_ang_hv : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I8_ANG_SLASH 10'h108 */
	union {
		uint32_t venc_md_cost_offset_i8_ang_slash; // word name
		struct {
			uint32_t md_mode_cost_offset_i8_ang_slash : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I4_DC 10'h10C */
	union {
		uint32_t venc_md_cost_offset_i4_dc; // word name
		struct {
			uint32_t md_mode_cost_offset_i4_dc : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I4_ANG_HV 10'h110 */
	union {
		uint32_t venc_md_cost_offset_i4_ang_hv; // word name
		struct {
			uint32_t md_mode_cost_offset_i4_ang_hv : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_I4_ANG_SLASH 10'h114 */
	union {
		uint32_t venc_md_cost_offset_i4_ang_slash; // word name
		struct {
			uint32_t md_mode_cost_offset_i4_ang_slash : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_P32x32 10'h118 */
	union {
		uint32_t venc_md_cost_offset_p32x32; // word name
		struct {
			uint32_t md_mode_cost_offset_p32x32 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_P32x16 10'h11C */
	union {
		uint32_t venc_md_cost_offset_p32x16; // word name
		struct {
			uint32_t md_mode_cost_offset_p32x16 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_P16x32 10'h120 */
	union {
		uint32_t venc_md_cost_offset_p16x32; // word name
		struct {
			uint32_t md_mode_cost_offset_p16x32 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_P16x16 10'h124 */
	union {
		uint32_t venc_md_cost_offset_p16x16; // word name
		struct {
			uint32_t md_mode_cost_offset_p16x16 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_P16x8 10'h128 */
	union {
		uint32_t venc_md_cost_offset_p16x8; // word name
		struct {
			uint32_t md_mode_cost_offset_p16x8 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_P8x16 10'h12C */
	union {
		uint32_t venc_md_cost_offset_p8x16; // word name
		struct {
			uint32_t md_mode_cost_offset_p8x16 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_P8x8 10'h130 */
	union {
		uint32_t venc_md_cost_offset_p8x8; // word name
		struct {
			uint32_t md_mode_cost_offset_p8x8 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_DIST_BIAS_I32_COST 10'h134 */
	union {
		uint32_t venc_md_dist_bias_i32_cost; // word name
		struct {
			uint32_t md_dist_bias_i32 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_DIST_BIAS_I16_COST 10'h138 */
	union {
		uint32_t venc_md_dist_bias_i16_cost; // word name
		struct {
			uint32_t md_dist_bias_i16 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_DIST_BIAS_I8_COST 10'h13C */
	union {
		uint32_t venc_md_dist_bias_i8_cost; // word name
		struct {
			uint32_t md_dist_bias_i8 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_DIST_BIAS_I4_COST 10'h140 */
	union {
		uint32_t venc_md_dist_bias_i4_cost; // word name
		struct {
			uint32_t md_dist_bias_i4 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_DIST_TRANSFORM_4X4_FALLBACK_OFFSET 10'h144 */
	union {
		uint32_t venc_md_dist_transform_4x4_fallback_offset; // word name
		struct {
			uint32_t md_dist_tr4_fallback_offset : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_MERGE_ALPHA 10'h148 */
	union {
		uint32_t venc_md_cost_merge_alpha; // word name
		struct {
			uint32_t md_mode_cost_merge_alpha_i16 : 7;
			uint32_t : 1; // padding bits
			uint32_t md_mode_cost_merge_alpha_i8 : 7;
			uint32_t : 1; // padding bits
			uint32_t md_mode_cost_merge_alpha_i4 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_SSE_COST_FACTOR 10'h14C */
	union {
		uint32_t venc_md_sse_cost_factor; // word name
		struct {
			uint32_t md_factor_cost_sse : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_WEIGHT_COST_0 10'h150 */
	union {
		uint32_t venc_md_weight_cost_0; // word name
		struct {
			uint32_t md_weight_cost_sse_complex_level_0 : 7;
			uint32_t : 1; // padding bits
			uint32_t md_weight_cost_sse_complex_level_1 : 7;
			uint32_t : 1; // padding bits
			uint32_t md_weight_cost_sse_complex_level_2 : 7;
			uint32_t : 1; // padding bits
			uint32_t md_weight_cost_sse_complex_level_3 : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* VENC_MD_WEIGHT_COST_1 10'h154 */
	union {
		uint32_t venc_md_weight_cost_1; // word name
		struct {
			uint32_t md_weight_cost_sse_complex_level_4 : 7;
			uint32_t : 1; // padding bits
			uint32_t md_weight_cost_sse_complex_level_5 : 7;
			uint32_t : 1; // padding bits
			uint32_t md_weight_cost_sse_complex_level_6 : 7;
			uint32_t : 1; // padding bits
			uint32_t md_weight_cost_sse_complex_level_7 : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* VENC_MD_WEIGHT_COST_2 10'h158 */
	union {
		uint32_t venc_md_weight_cost_2; // word name
		struct {
			uint32_t md_weight_cost_sse_complex_level_8 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_COST_OFFSET_C_OSD 10'h15C */
	union {
		uint32_t venc_md_cost_offset_c_osd; // word name
		struct {
			uint32_t md_mode_cost_offset_chroma_osd : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MD_MODE_COST_OFFSET_MV_NON_VALID 10'h160 */
	union {
		uint32_t venc_md_mode_cost_offset_mv_non_valid; // word name
		struct {
			uint32_t csr_md_mode_cost_offset_mv_non_valid_level_0 : 7;
			uint32_t : 1; // padding bits
			uint32_t csr_md_mode_cost_offset_mv_non_valid_level_1 : 7;
			uint32_t : 1; // padding bits
			uint32_t csr_md_mode_cost_offset_mv_non_valid_level_2 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_RD_FACTOR_C 10'h164 */
	union {
		uint32_t venc_rd_factor_c; // word name
		struct {
			uint32_t rd_factor_offset_c : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_QP_OSD_OFFSET_MINUS 10'h168 */
	union {
		uint32_t venc_qp_osd_offset_minus; // word name
		struct {
			uint32_t qp_osd_offset : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_QP_CHROMA_OFFSET_2S 10'h16C */
	union {
		uint32_t venc_qp_chroma_offset_2s; // word name
		struct {
			uint32_t qp_chroma_offset_2s : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_SCALING_LIST 10'h170 */
	union {
		uint32_t venc_scaling_list; // word name
		struct {
			uint32_t scaling_list_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t scaling_list_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DIST_TH_MV_0 10'h174 */
	union {
		uint32_t venc_coeff_cut_dist_th_mv_0; // word name
		struct {
			uint32_t cut_coef_dist_th_y_blk16_mv_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t cut_coef_dist_th_c_blk16_mv_0 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DIST_TH_Y_TR16 10'h178 */
	union {
		uint32_t venc_coeff_cut_dist_th_y_tr16; // word name
		struct {
			uint32_t cut_coef_dist_th_y_tr16 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DIST_TH_Y_TR8 10'h17C */
	union {
		uint32_t venc_coeff_cut_dist_th_y_tr8; // word name
		struct {
			uint32_t cut_coef_dist_th_y_tr8 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DIST_TH_Y_TR4 10'h180 */
	union {
		uint32_t venc_coeff_cut_dist_th_y_tr4; // word name
		struct {
			uint32_t cut_coef_dist_th_y_tr4 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DIST_TH_C_TR8 10'h184 */
	union {
		uint32_t venc_coeff_cut_dist_th_c_tr8; // word name
		struct {
			uint32_t cut_coef_dist_th_c_tr8 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DIST_TH_C_TR4 10'h188 */
	union {
		uint32_t venc_coeff_cut_dist_th_c_tr4; // word name
		struct {
			uint32_t cut_coef_dist_th_c_tr4 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DC_TH_MV_0 10'h18C */
	union {
		uint32_t venc_coeff_cut_dc_th_mv_0; // word name
		struct {
			uint32_t cut_coef_dc_th_y_blk16_mv_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t cut_coef_dc_th_c_blk16_mv_0 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DC_TH_Y 10'h190 */
	union {
		uint32_t venc_coeff_cut_dc_th_y; // word name
		struct {
			uint32_t cut_coef_dc_th_y_tr16 : 6;
			uint32_t : 2; // padding bits
			uint32_t cut_coef_dc_th_y_tr8 : 6;
			uint32_t : 2; // padding bits
			uint32_t cut_coef_dc_th_y_tr4 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COEFF_CUT_DC_TH_C 10'h194 */
	union {
		uint32_t venc_coeff_cut_dc_th_c; // word name
		struct {
			uint32_t cut_coef_dc_th_c_tr8 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t cut_coef_dc_th_c_tr4 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_SKIP 10'h198 [Unused] */
	uint32_t empty_word_venc_mode_num_skip;
	/* VENC_MODE_NUM_INTER_32x32_SKIP 10'h19C */
	union {
		uint32_t venc_mode_num_inter_32x32_skip; // word name
		struct {
			uint32_t mode_num_inter_32x32_skip : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTER_32X32 10'h1A0 */
	union {
		uint32_t venc_mode_num_inter_32x32; // word name
		struct {
			uint32_t mode_num_inter_32x32 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTER_32X16 10'h1A4 */
	union {
		uint32_t venc_mode_num_inter_32x16; // word name
		struct {
			uint32_t mode_num_inter_32x16 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTER_16X32 10'h1A8 */
	union {
		uint32_t venc_mode_num_inter_16x32; // word name
		struct {
			uint32_t mode_num_inter_16x32 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTER_16x16_SKIP 10'h1AC */
	union {
		uint32_t venc_mode_num_inter_16x16_skip; // word name
		struct {
			uint32_t mode_num_inter_16x16_skip : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTER_16X16 10'h1B0 */
	union {
		uint32_t venc_mode_num_inter_16x16; // word name
		struct {
			uint32_t mode_num_inter_16x16 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTER_16X8 10'h1B4 */
	union {
		uint32_t venc_mode_num_inter_16x8; // word name
		struct {
			uint32_t mode_num_inter_16x8 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTER_8X16 10'h1B8 */
	union {
		uint32_t venc_mode_num_inter_8x16; // word name
		struct {
			uint32_t mode_num_inter_8x16 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTER_8X8 10'h1BC */
	union {
		uint32_t venc_mode_num_inter_8x8; // word name
		struct {
			uint32_t mode_num_inter_8x8 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTRA_32X32 10'h1C0 */
	union {
		uint32_t venc_mode_num_intra_32x32; // word name
		struct {
			uint32_t mode_num_intra_32x32 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTRA_16X16 10'h1C4 */
	union {
		uint32_t venc_mode_num_intra_16x16; // word name
		struct {
			uint32_t mode_num_intra_16x16 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MODE_NUM_INTRA_8X8 10'h1C8 */
	union {
		uint32_t venc_mode_num_intra_8x8; // word name
		struct {
			uint32_t mode_num_intra_8x8 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_0_BIT 10'h1CC */
	union {
		uint32_t venc_roi_0_bit; // word name
		struct {
			uint32_t roi_0_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_1_BIT 10'h1D0 */
	union {
		uint32_t venc_roi_1_bit; // word name
		struct {
			uint32_t roi_1_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_2_BIT 10'h1D4 */
	union {
		uint32_t venc_roi_2_bit; // word name
		struct {
			uint32_t roi_2_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_3_BIT 10'h1D8 */
	union {
		uint32_t venc_roi_3_bit; // word name
		struct {
			uint32_t roi_3_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_4_BIT 10'h1DC */
	union {
		uint32_t venc_roi_4_bit; // word name
		struct {
			uint32_t roi_4_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_5_BIT 10'h1E0 */
	union {
		uint32_t venc_roi_5_bit; // word name
		struct {
			uint32_t roi_5_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_6_BIT 10'h1E4 */
	union {
		uint32_t venc_roi_6_bit; // word name
		struct {
			uint32_t roi_6_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_7_BIT 10'h1E8 */
	union {
		uint32_t venc_roi_7_bit; // word name
		struct {
			uint32_t roi_7_frame_bit_length : 32;
		};
	};
	/* VENC_NORMAL_BIT 10'h1EC */
	union {
		uint32_t venc_normal_bit; // word name
		struct {
			uint32_t nor_frame_bit_length : 32;
		};
	};
	/* VENC_OSD_BIT 10'h1F0 */
	union {
		uint32_t venc_osd_bit; // word name
		struct {
			uint32_t osd_frame_bit_length : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_0_BIT 10'h1F4 */
	union {
		uint32_t venc_complex_level_0_bit; // word name
		struct {
			uint32_t complex_level_0_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_1_BIT 10'h1F8 */
	union {
		uint32_t venc_complex_level_1_bit; // word name
		struct {
			uint32_t complex_level_1_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_2_BIT 10'h1FC */
	union {
		uint32_t venc_complex_level_2_bit; // word name
		struct {
			uint32_t complex_level_2_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_3_BIT 10'h200 */
	union {
		uint32_t venc_complex_level_3_bit; // word name
		struct {
			uint32_t complex_level_3_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_4_BIT 10'h204 */
	union {
		uint32_t venc_complex_level_4_bit; // word name
		struct {
			uint32_t complex_level_4_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_5_BIT 10'h208 */
	union {
		uint32_t venc_complex_level_5_bit; // word name
		struct {
			uint32_t complex_level_5_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_6_BIT 10'h20C */
	union {
		uint32_t venc_complex_level_6_bit; // word name
		struct {
			uint32_t complex_level_6_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_7_BIT 10'h210 */
	union {
		uint32_t venc_complex_level_7_bit; // word name
		struct {
			uint32_t complex_level_7_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_8_BIT 10'h214 */
	union {
		uint32_t venc_complex_level_8_bit; // word name
		struct {
			uint32_t complex_level_8_bit_num : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_0_QP_SUM 10'h218 */
	union {
		uint32_t venc_complex_level_0_qp_sum; // word name
		struct {
			uint32_t complex_level_0_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_1_QP_SUM 10'h21C */
	union {
		uint32_t venc_complex_level_1_qp_sum; // word name
		struct {
			uint32_t complex_level_1_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_2_QP_SUM 10'h220 */
	union {
		uint32_t venc_complex_level_2_qp_sum; // word name
		struct {
			uint32_t complex_level_2_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_3_QP_SUM 10'h224 */
	union {
		uint32_t venc_complex_level_3_qp_sum; // word name
		struct {
			uint32_t complex_level_3_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_4_QP_SUM 10'h228 */
	union {
		uint32_t venc_complex_level_4_qp_sum; // word name
		struct {
			uint32_t complex_level_4_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_5_QP_SUM 10'h22C */
	union {
		uint32_t venc_complex_level_5_qp_sum; // word name
		struct {
			uint32_t complex_level_5_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_6_QP_SUM 10'h230 */
	union {
		uint32_t venc_complex_level_6_qp_sum; // word name
		struct {
			uint32_t complex_level_6_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_7_QP_SUM 10'h234 */
	union {
		uint32_t venc_complex_level_7_qp_sum; // word name
		struct {
			uint32_t complex_level_7_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_8_QP_SUM 10'h238 */
	union {
		uint32_t venc_complex_level_8_qp_sum; // word name
		struct {
			uint32_t complex_level_8_qp_sum : 21;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_0_COMPLEXITY_SUM 10'h23C */
	union {
		uint32_t venc_complex_level_0_complexity_sum; // word name
		struct {
			uint32_t complex_level_0_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_1_COMPLEXITY_SUM 10'h240 */
	union {
		uint32_t venc_complex_level_1_complexity_sum; // word name
		struct {
			uint32_t complex_level_1_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_2_COMPLEXITY_SUM 10'h244 */
	union {
		uint32_t venc_complex_level_2_complexity_sum; // word name
		struct {
			uint32_t complex_level_2_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_3_COMPLEXITY_SUM 10'h248 */
	union {
		uint32_t venc_complex_level_3_complexity_sum; // word name
		struct {
			uint32_t complex_level_3_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_4_COMPLEXITY_SUM 10'h24C */
	union {
		uint32_t venc_complex_level_4_complexity_sum; // word name
		struct {
			uint32_t complex_level_4_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_5_COMPLEXITY_SUM 10'h250 */
	union {
		uint32_t venc_complex_level_5_complexity_sum; // word name
		struct {
			uint32_t complex_level_5_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_6_COMPLEXITY_SUM 10'h254 */
	union {
		uint32_t venc_complex_level_6_complexity_sum; // word name
		struct {
			uint32_t complex_level_6_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_7_COMPLEXITY_SUM 10'h258 */
	union {
		uint32_t venc_complex_level_7_complexity_sum; // word name
		struct {
			uint32_t complex_level_7_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_8_COMPLEXITY_SUM 10'h25C */
	union {
		uint32_t venc_complex_level_8_complexity_sum; // word name
		struct {
			uint32_t complex_level_8_complexity : 32;
		};
	};
	/* VENC_COMPLEX_LEVEL_0_BLK16_NUM 10'h260 */
	union {
		uint32_t venc_complex_level_0_blk16_num; // word name
		struct {
			uint32_t complex_level_0_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_1_BLK16_NUM 10'h264 */
	union {
		uint32_t venc_complex_level_1_blk16_num; // word name
		struct {
			uint32_t complex_level_1_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_2_BLK16_NUM 10'h268 */
	union {
		uint32_t venc_complex_level_2_blk16_num; // word name
		struct {
			uint32_t complex_level_2_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_3_BLK16_NUM 10'h26C */
	union {
		uint32_t venc_complex_level_3_blk16_num; // word name
		struct {
			uint32_t complex_level_3_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_4_BLK16_NUM 10'h270 */
	union {
		uint32_t venc_complex_level_4_blk16_num; // word name
		struct {
			uint32_t complex_level_4_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_5_BLK16_NUM 10'h274 */
	union {
		uint32_t venc_complex_level_5_blk16_num; // word name
		struct {
			uint32_t complex_level_5_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_6_BLK16_NUM 10'h278 */
	union {
		uint32_t venc_complex_level_6_blk16_num; // word name
		struct {
			uint32_t complex_level_6_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_7_BLK16_NUM 10'h27C */
	union {
		uint32_t venc_complex_level_7_blk16_num; // word name
		struct {
			uint32_t complex_level_7_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_COMPLEX_LEVEL_8_BLK16_NUM 10'h280 */
	union {
		uint32_t venc_complex_level_8_blk16_num; // word name
		struct {
			uint32_t complex_level_8_blk16_num : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MV_SCALING 10'h284 */
	union {
		uint32_t venc_mv_scaling; // word name
		struct {
			uint32_t mv_scaling_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t mv_scaling_ratio : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_OSD_0_INFO 10'h288 */
	union {
		uint32_t venc_osd_0_info; // word name
		struct {
			uint32_t osd_0_en_qp : 1;
			uint32_t : 7; // padding bits
			uint32_t osd_0_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t osd_0_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_OSD_0_LAMBDA 10'h28C */
	union {
		uint32_t venc_osd_0_lambda; // word name
		struct {
			uint32_t osd_0_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t osd_0_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_OSD_1_INFO 10'h290 */
	union {
		uint32_t venc_osd_1_info; // word name
		struct {
			uint32_t osd_1_en_qp : 1;
			uint32_t : 7; // padding bits
			uint32_t osd_1_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t osd_1_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_OSD_1_LAMBDA 10'h294 */
	union {
		uint32_t venc_osd_1_lambda; // word name
		struct {
			uint32_t osd_1_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t osd_1_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_OSD_2_INFO 10'h298 */
	union {
		uint32_t venc_osd_2_info; // word name
		struct {
			uint32_t osd_2_en_qp : 1;
			uint32_t : 7; // padding bits
			uint32_t osd_2_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t osd_2_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_OSD_2_LAMBDA 10'h29C */
	union {
		uint32_t venc_osd_2_lambda; // word name
		struct {
			uint32_t osd_2_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t osd_2_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_OSD_3_INFO 10'h2A0 */
	union {
		uint32_t venc_osd_3_info; // word name
		struct {
			uint32_t osd_3_en_qp : 1;
			uint32_t : 7; // padding bits
			uint32_t osd_3_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t osd_3_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_OSD_3_LAMBDA 10'h2A4 */
	union {
		uint32_t venc_osd_3_lambda; // word name
		struct {
			uint32_t osd_3_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t osd_3_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_0_INFO 10'h2A8 */
	union {
		uint32_t venc_roi_0_info; // word name
		struct {
			uint32_t roi_0_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_0_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_0_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_0_X 10'h2AC */
	union {
		uint32_t venc_roi_0_x; // word name
		struct {
			uint32_t roi_0_sx : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_0_ex : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_0_Y 10'h2B0 */
	union {
		uint32_t venc_roi_0_y; // word name
		struct {
			uint32_t roi_0_sy : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_0_ey : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_0_LAMBDA 10'h2B4 */
	union {
		uint32_t venc_roi_0_lambda; // word name
		struct {
			uint32_t roi_0_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t roi_0_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_1_INFO 10'h2B8 */
	union {
		uint32_t venc_roi_1_info; // word name
		struct {
			uint32_t roi_1_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_1_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_1_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_1_X 10'h2BC */
	union {
		uint32_t venc_roi_1_x; // word name
		struct {
			uint32_t roi_1_sx : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_1_ex : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_1_Y 10'h2C0 */
	union {
		uint32_t venc_roi_1_y; // word name
		struct {
			uint32_t roi_1_sy : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_1_ey : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_1_LAMBDA 10'h2C4 */
	union {
		uint32_t venc_roi_1_lambda; // word name
		struct {
			uint32_t roi_1_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t roi_1_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_2_INFO 10'h2C8 */
	union {
		uint32_t venc_roi_2_info; // word name
		struct {
			uint32_t roi_2_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_2_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_2_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_2_X 10'h2CC */
	union {
		uint32_t venc_roi_2_x; // word name
		struct {
			uint32_t roi_2_sx : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_2_ex : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_2_Y 10'h2D0 */
	union {
		uint32_t venc_roi_2_y; // word name
		struct {
			uint32_t roi_2_sy : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_2_ey : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_2_LAMBDA 10'h2D4 */
	union {
		uint32_t venc_roi_2_lambda; // word name
		struct {
			uint32_t roi_2_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t roi_2_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_3_INFO 10'h2D8 */
	union {
		uint32_t venc_roi_3_info; // word name
		struct {
			uint32_t roi_3_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_3_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_3_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_3_X 10'h2DC */
	union {
		uint32_t venc_roi_3_x; // word name
		struct {
			uint32_t roi_3_sx : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_3_ex : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_3_Y 10'h2E0 */
	union {
		uint32_t venc_roi_3_y; // word name
		struct {
			uint32_t roi_3_sy : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_3_ey : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_3_LAMBDA 10'h2E4 */
	union {
		uint32_t venc_roi_3_lambda; // word name
		struct {
			uint32_t roi_3_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t roi_3_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_4_INFO 10'h2E8 */
	union {
		uint32_t venc_roi_4_info; // word name
		struct {
			uint32_t roi_4_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_4_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_4_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_4_X 10'h2EC */
	union {
		uint32_t venc_roi_4_x; // word name
		struct {
			uint32_t roi_4_sx : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_4_ex : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_4_Y 10'h2F0 */
	union {
		uint32_t venc_roi_4_y; // word name
		struct {
			uint32_t roi_4_sy : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_4_ey : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_4_LAMBDA 10'h2F4 */
	union {
		uint32_t venc_roi_4_lambda; // word name
		struct {
			uint32_t roi_4_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t roi_4_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_5_INFO 10'h2F8 */
	union {
		uint32_t venc_roi_5_info; // word name
		struct {
			uint32_t roi_5_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_5_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_5_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_5_X 10'h2FC */
	union {
		uint32_t venc_roi_5_x; // word name
		struct {
			uint32_t roi_5_sx : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_5_ex : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_5_Y 10'h300 */
	union {
		uint32_t venc_roi_5_y; // word name
		struct {
			uint32_t roi_5_sy : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_5_ey : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_5_LAMBDA 10'h304 */
	union {
		uint32_t venc_roi_5_lambda; // word name
		struct {
			uint32_t roi_5_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t roi_5_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_6_INFO 10'h308 */
	union {
		uint32_t venc_roi_6_info; // word name
		struct {
			uint32_t roi_6_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_6_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_6_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_6_X 10'h30C */
	union {
		uint32_t venc_roi_6_x; // word name
		struct {
			uint32_t roi_6_sx : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_6_ex : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_6_Y 10'h310 */
	union {
		uint32_t venc_roi_6_y; // word name
		struct {
			uint32_t roi_6_sy : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_6_ey : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_6_LAMBDA 10'h314 */
	union {
		uint32_t venc_roi_6_lambda; // word name
		struct {
			uint32_t roi_6_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t roi_6_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_7_INFO 10'h318 */
	union {
		uint32_t venc_roi_7_info; // word name
		struct {
			uint32_t roi_7_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_7_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_7_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_7_X 10'h31C */
	union {
		uint32_t venc_roi_7_x; // word name
		struct {
			uint32_t roi_7_sx : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_7_ex : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_7_Y 10'h320 */
	union {
		uint32_t venc_roi_7_y; // word name
		struct {
			uint32_t roi_7_sy : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_7_ey : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_7_LAMBDA 10'h324 */
	union {
		uint32_t venc_roi_7_lambda; // word name
		struct {
			uint32_t roi_7_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t roi_7_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_8_INFO 10'h328 [Unused] */
	uint32_t empty_word_venc_roi_8_info;
	/* VENC_ROI_8_X 10'h32C [Unused] */
	uint32_t empty_word_venc_roi_8_x;
	/* VENC_ROI_8_Y 10'h330 [Unused] */
	uint32_t empty_word_venc_roi_8_y;
	/* VENC_ROI_8_LAMBDA 10'h334 [Unused] */
	uint32_t empty_word_venc_roi_8_lambda;
	/* VENC_SLICE_QP 10'h338 */
	union {
		uint32_t venc_slice_qp; // word name
		struct {
			uint32_t slice_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_SLICE_QP_LAMBDA 10'h33C */
	union {
		uint32_t venc_slice_qp_lambda; // word name
		struct {
			uint32_t slice_qp_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t slice_qp_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_DEBUG_MON_SEL 10'h340 */
	union {
		uint32_t venc_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t atpg_ctrl : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_DEBUG_MON_REG 10'h344 */
	union {
		uint32_t venc_debug_mon_reg; // word name
		struct {
			uint32_t debug_mon_reg : 32;
		};
	};
	/* VENC_RESERVED_0 10'h348 */
	union {
		uint32_t venc_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* VENC_RESERVED_1 10'h34C */
	union {
		uint32_t venc_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* VENC_RESERVED_2 10'h350 */
	union {
		uint32_t venc_reserved_2; // word name
		struct {
			uint32_t reserved_2 : 32;
		};
	};
	/* VENC_RESERVED_3 10'h354 */
	union {
		uint32_t venc_reserved_3; // word name
		struct {
			uint32_t reserved_3 : 32;
		};
	};
} CsrBankVenc;

#endif