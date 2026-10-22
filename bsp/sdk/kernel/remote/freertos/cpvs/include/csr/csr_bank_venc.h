#ifndef CSR_BANK_VENC_H_
#define CSR_BANK_VENC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from venc  ***/
typedef struct csr_bank_venc {
	/* VENC00 10'h00 */
	union {
		uint32_t venc00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC01 10'h04 */
	union {
		uint32_t venc01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t irq_clear_mvr_frame_end : 1;
			uint32_t irq_clear_mvr_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_mvr_access_violation : 1;
			uint32_t irq_clear_refr_frame_end : 1;
			uint32_t irq_clear_refr_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_refr_access_violation : 1;
			uint32_t irq_clear_refw_frame_end : 1;
			uint32_t irq_clear_refw_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_refw_access_violation : 1;
			uint32_t irq_clear_seq_hdr_cont : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC02 10'h08 */
	union {
		uint32_t venc02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t status_mvr_frame_end : 1;
			uint32_t status_mvr_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t status_mvr_access_violation : 1;
			uint32_t status_refr_frame_end : 1;
			uint32_t status_refr_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t status_refr_access_violation : 1;
			uint32_t status_refw_frame_end : 1;
			uint32_t status_refw_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t status_refw_access_violation : 1;
			uint32_t status_seq_hdr_cont : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC03 10'h0C */
	union {
		uint32_t venc03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t irq_mask_mvr_frame_end : 1;
			uint32_t irq_mask_mvr_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_mvr_access_violation : 1;
			uint32_t irq_mask_refr_frame_end : 1;
			uint32_t irq_mask_refr_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_refr_access_violation : 1;
			uint32_t irq_mask_refw_frame_end : 1;
			uint32_t irq_mask_refw_bw_insufficient : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_refw_access_violation : 1;
			uint32_t irq_mask_seq_hdr_cont : 1;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC04 10'h10 [Unused] */
	uint32_t empty_word_venc04;
	/* VENC05 10'h14 [Unused] */
	uint32_t empty_word_venc05;
	/* VENC06 10'h18 [Unused] */
	uint32_t empty_word_venc06;
	/* VENC_FRAME_SIZE 10'h1C */
	union {
		uint32_t venc_frame_size; // word name
		struct {
			uint32_t frm_mb_hor_num_m1 : 12;
			uint32_t : 4; // padding bits
			uint32_t frm_mb_ver_num_m1 : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_FRAME_TYPE 10'h20 */
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
	/* VENC_ENC_TOOL_0 10'h24 */
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
	/* VENC_ENC_TOOL_1 10'h28 */
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
	/* VENC_DEBLK_TOOL 10'h2C */
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
	/* VENC_QP_MODE 10'h30 */
	union {
		uint32_t venc_qp_mode; // word name
		struct {
			uint32_t frm_qp_change_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t qp_change_var_th : 17;
			uint32_t : 7; // padding bits
		};
	};
	/* VENC_QP_CHG_AXIS 10'h34 */
	union {
		uint32_t venc_qp_chg_axis; // word name
		struct {
			uint32_t mb_qp_change_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t mb_qp_change_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_COEF_CUT 10'h38 */
	union {
		uint32_t venc_coef_cut; // word name
		struct {
			uint32_t luma_coef_cost_cut_th : 8;
			uint32_t luma_8x8_coef_cost_cut_th : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_MB_STILL 10'h3C */
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
	/* VENC_OSD_QP_SEL 10'h40 */
	union {
		uint32_t venc_osd_qp_sel; // word name
		struct {
			uint32_t osd_qp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_ROI_ENABLE_0 10'h44 */
	union {
		uint32_t venc_roi_enable_0; // word name
		struct {
			uint32_t roi_0_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_1_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_2_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_3_enable : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* VENC_ROI_ENABLE_1 10'h48 */
	union {
		uint32_t venc_roi_enable_1; // word name
		struct {
			uint32_t roi_4_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_5_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_6_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_7_enable : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* VENC_ROI_0_START_AXIS 10'h4C */
	union {
		uint32_t venc_roi_0_start_axis; // word name
		struct {
			uint32_t roi_0_start_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_0_start_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_0_END_AXIS 10'h50 */
	union {
		uint32_t venc_roi_0_end_axis; // word name
		struct {
			uint32_t roi_0_end_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_0_end_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_1_START_AXIS 10'h54 */
	union {
		uint32_t venc_roi_1_start_axis; // word name
		struct {
			uint32_t roi_1_start_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_1_start_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_1_END_AXIS 10'h58 */
	union {
		uint32_t venc_roi_1_end_axis; // word name
		struct {
			uint32_t roi_1_end_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_1_end_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_2_START_AXIS 10'h5C */
	union {
		uint32_t venc_roi_2_start_axis; // word name
		struct {
			uint32_t roi_2_start_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_2_start_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_2_END_AXIS 10'h60 */
	union {
		uint32_t venc_roi_2_end_axis; // word name
		struct {
			uint32_t roi_2_end_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_2_end_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_3_START_AXIS 10'h64 */
	union {
		uint32_t venc_roi_3_start_axis; // word name
		struct {
			uint32_t roi_3_start_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_3_start_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_3_END_AXIS 10'h68 */
	union {
		uint32_t venc_roi_3_end_axis; // word name
		struct {
			uint32_t roi_3_end_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_3_end_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_4_START_AXIS 10'h6C */
	union {
		uint32_t venc_roi_4_start_axis; // word name
		struct {
			uint32_t roi_4_start_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_4_start_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_4_END_AXIS 10'h70 */
	union {
		uint32_t venc_roi_4_end_axis; // word name
		struct {
			uint32_t roi_4_end_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_4_end_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_5_START_AXIS 10'h74 */
	union {
		uint32_t venc_roi_5_start_axis; // word name
		struct {
			uint32_t roi_5_start_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_5_start_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_5_END_AXIS 10'h78 */
	union {
		uint32_t venc_roi_5_end_axis; // word name
		struct {
			uint32_t roi_5_end_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_5_end_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_6_START_AXIS 10'h7C */
	union {
		uint32_t venc_roi_6_start_axis; // word name
		struct {
			uint32_t roi_6_start_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_6_start_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_6_END_AXIS 10'h80 */
	union {
		uint32_t venc_roi_6_end_axis; // word name
		struct {
			uint32_t roi_6_end_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_6_end_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_7_START_AXIS 10'h84 */
	union {
		uint32_t venc_roi_7_start_axis; // word name
		struct {
			uint32_t roi_7_start_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_7_start_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_7_END_AXIS 10'h88 */
	union {
		uint32_t venc_roi_7_end_axis; // word name
		struct {
			uint32_t roi_7_end_mb_x : 12;
			uint32_t : 4; // padding bits
			uint32_t roi_7_end_mb_y : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* VENC_ROI_QP_SEL_0 10'h8C */
	union {
		uint32_t venc_roi_qp_sel_0; // word name
		struct {
			uint32_t roi_0_qp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_1_qp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_2_qp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_3_qp_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* VENC_ROI_QP_SEL_1 10'h90 */
	union {
		uint32_t venc_roi_qp_sel_1; // word name
		struct {
			uint32_t roi_4_qp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_5_qp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_6_qp_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t roi_7_qp_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* VENC_QP_IDX_TABLE 10'h94 */
	union {
		uint32_t venc_qp_idx_table; // word name
		struct {
			uint32_t slice_qp : 6;
			uint32_t : 2; // padding bits
			uint32_t qp_1 : 6;
			uint32_t : 2; // padding bits
			uint32_t qp_2 : 6;
			uint32_t : 2; // padding bits
			uint32_t qp_3 : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* VENC_QP_IDX_0_LAMBDA 10'h98 */
	union {
		uint32_t venc_qp_idx_0_lambda; // word name
		struct {
			uint32_t slice_qp_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t slice_qp_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_QP_IDX_1_LAMBDA 10'h9C */
	union {
		uint32_t venc_qp_idx_1_lambda; // word name
		struct {
			uint32_t qp_1_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t qp_1_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_QP_IDX_2_LAMBDA 10'hA0 */
	union {
		uint32_t venc_qp_idx_2_lambda; // word name
		struct {
			uint32_t qp_2_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t qp_2_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_QP_IDX_3_LAMBDA 10'hA4 */
	union {
		uint32_t venc_qp_idx_3_lambda; // word name
		struct {
			uint32_t qp_3_lambda : 9;
			uint32_t : 7; // padding bits
			uint32_t qp_3_sao_lambda : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* VENC_ROI_QP_7 10'hA8 [Unused] */
	uint32_t empty_word_venc_roi_qp_7;
	/* VENC_HDR_SETTING 10'hAC */
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
	/* VENC_FRAME_BYTE 10'hB0 */
	union {
		uint32_t venc_frame_byte; // word name
		struct {
			uint32_t frame_bs_byte_length : 32;
		};
	};
	/* VENC_ROI_0_BIT 10'hB4 */
	union {
		uint32_t venc_roi_0_bit; // word name
		struct {
			uint32_t roi_0_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_1_BIT 10'hB8 */
	union {
		uint32_t venc_roi_1_bit; // word name
		struct {
			uint32_t roi_1_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_2_BIT 10'hBC */
	union {
		uint32_t venc_roi_2_bit; // word name
		struct {
			uint32_t roi_2_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_3_BIT 10'hC0 */
	union {
		uint32_t venc_roi_3_bit; // word name
		struct {
			uint32_t roi_3_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_4_BIT 10'hC4 */
	union {
		uint32_t venc_roi_4_bit; // word name
		struct {
			uint32_t roi_4_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_5_BIT 10'hC8 */
	union {
		uint32_t venc_roi_5_bit; // word name
		struct {
			uint32_t roi_5_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_6_BIT 10'hCC */
	union {
		uint32_t venc_roi_6_bit; // word name
		struct {
			uint32_t roi_6_frame_bit_length : 32;
		};
	};
	/* VENC_ROI_7_BIT 10'hD0 */
	union {
		uint32_t venc_roi_7_bit; // word name
		struct {
			uint32_t roi_7_frame_bit_length : 32;
		};
	};
	/* VENC_NORMAL_BIT 10'hD4 */
	union {
		uint32_t venc_normal_bit; // word name
		struct {
			uint32_t nor_frame_bit_length : 32;
		};
	};
	/* VENC_OSD_BIT 10'hD8 */
	union {
		uint32_t venc_osd_bit; // word name
		struct {
			uint32_t osd_frame_bit_length : 32;
		};
	};
	/* VENC_SR_UP_SET 10'hDC */
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
	/* VENC_SR_SEARCH_SET 10'hE0 */
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
	/* VENC_MERGE_MV_CAND 10'hE4 */
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
	/* VENC_MV_QUALITY 10'hE8 */
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
	/* VENC_INTER_MODE_PARAM 10'hEC */
	union {
		uint32_t venc_inter_mode_param; // word name
		struct {
			uint32_t inter_2nx2n_offset_ratio : 7;
			uint32_t : 1; // padding bits
			uint32_t inter_2nxn_offset_ratio : 7;
			uint32_t : 1; // padding bits
			uint32_t inter_nx2n_offset_ratio : 7;
			uint32_t : 1; // padding bits
			uint32_t inter_nxn_offset_ratio : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* VENC_INTRA_MODE_PARAM 10'hF0 */
	union {
		uint32_t venc_intra_mode_param; // word name
		struct {
			uint32_t intra_2nx2n_offset_ratio : 7;
			uint32_t : 1; // padding bits
			uint32_t intra_nxn_offset_ratio : 7;
			uint32_t : 1; // padding bits
			uint32_t intra_cip_offset_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_HDR_DATA_0 10'hF4 */
	union {
		uint32_t venc_hdr_data_0; // word name
		struct {
			uint32_t hdr_data_0 : 32;
		};
	};
	/* VENC_HDR_DATA_1 10'hF8 */
	union {
		uint32_t venc_hdr_data_1; // word name
		struct {
			uint32_t hdr_data_1 : 32;
		};
	};
	/* VENC_HDR_DATA_2 10'hFC */
	union {
		uint32_t venc_hdr_data_2; // word name
		struct {
			uint32_t hdr_data_2 : 32;
		};
	};
	/* VENC_HDR_DATA_3 10'h100 */
	union {
		uint32_t venc_hdr_data_3; // word name
		struct {
			uint32_t hdr_data_3 : 32;
		};
	};
	/* VENC_MINMAX_RATIO_0 10'h104 */
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
	/* VENC_MINMAX_RATIO_1 10'h108 */
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
	/* VENC_MINMAX_RATIO_2 10'h10C */
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
	/* VENC_MINMAX_RATIO_3 10'h110 */
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
	/* VENC_MINMAX_RATIO_4 10'h114 */
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
	/* VENC_HEVC_INTRA_MODE_0 10'h118 */
	union {
		uint32_t venc_hevc_intra_mode_0; // word name
		struct {
			uint32_t hevc_i8_mode_num_m1 : 6;
			uint32_t : 2; // padding bits
			uint32_t hevc_i16_mode_num_m1 : 6;
			uint32_t : 2; // padding bits
			uint32_t hevc_cip_mode_num_m1 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_HEVC_INTRA_MODE_1 10'h11C */
	union {
		uint32_t venc_hevc_intra_mode_1; // word name
		struct {
			uint32_t hevc_intra_i8_mode_dir_th : 14;
			uint32_t : 2; // padding bits
			uint32_t hevc_intra_i16_mode_dir_th : 16;
		};
	};
	/* VENC_SKIP_CU_NUM 10'h120 */
	union {
		uint32_t venc_skip_cu_num; // word name
		struct {
			uint32_t skip_cu_num : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_INTER_2NX2N_CU_NUM 10'h124 */
	union {
		uint32_t venc_inter_2nx2n_cu_num; // word name
		struct {
			uint32_t inter_2nx2n_cu_num : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_INTER_2NXN_CU_NUM 10'h128 */
	union {
		uint32_t venc_inter_2nxn_cu_num; // word name
		struct {
			uint32_t inter_2nxn_cu_num : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_INTER_NX2N_CU_NUM 10'h12C */
	union {
		uint32_t venc_inter_nx2n_cu_num; // word name
		struct {
			uint32_t inter_nx2n_cu_num : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_INTER_NXN_CU_NUM 10'h130 */
	union {
		uint32_t venc_inter_nxn_cu_num; // word name
		struct {
			uint32_t inter_nxn_cu_num : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_INTRA_2Nx2N_CU_NUM 10'h134 */
	union {
		uint32_t venc_intra_2nx2n_cu_num; // word name
		struct {
			uint32_t intra_2nx2n_cu_num : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_INTRA_NXN_CU_NUM 10'h138 */
	union {
		uint32_t venc_intra_nxn_cu_num; // word name
		struct {
			uint32_t intra_nxn_cu_num : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_DEBUG_MON_SEL 10'h13C */
	union {
		uint32_t venc_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VENC_DEBUG_MON_REG 10'h140 */
	union {
		uint32_t venc_debug_mon_reg; // word name
		struct {
			uint32_t debug_mon_reg : 32;
		};
	};
	/* VENC_RESERVED_0 10'h144 */
	union {
		uint32_t venc_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* VENC_RESERVED_1 10'h148 */
	union {
		uint32_t venc_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* VENC_RESERVED_2 10'h14C */
	union {
		uint32_t venc_reserved_2; // word name
		struct {
			uint32_t reserved_2 : 32;
		};
	};
	/* VENC_RESERVED_3 10'h150 */
	union {
		uint32_t venc_reserved_3; // word name
		struct {
			uint32_t reserved_3 : 32;
		};
	};
} CsrBankVenc;

#endif