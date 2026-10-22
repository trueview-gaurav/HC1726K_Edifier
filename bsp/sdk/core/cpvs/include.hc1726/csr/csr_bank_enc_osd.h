/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ENC_OSD_H_
#define CSR_BANK_ENC_OSD_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from enc_osd  ***/
typedef struct csr_bank_enc_osd {
	/* LAYER_SETTING 16'h0000 */
	union {
		uint32_t layer_setting; // word name
		struct {
			uint32_t input_order : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t output_order : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CHROMA_SUB_SAMBLE_MODE 16'h0004 */
	union {
		uint32_t chroma_sub_samble_mode; // word name
		struct {
			uint32_t sub_sample_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WILDCARD_COLOR_0 16'h0008 */
	union {
		uint32_t wildcard_color_0; // word name
		struct {
			uint32_t wildcard_color_0_y : 8;
			uint32_t wildcard_color_0_u : 8;
			uint32_t wildcard_color_0_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* WILDCARD_COLOR_1 16'h000C */
	union {
		uint32_t wildcard_color_1; // word name
		struct {
			uint32_t wildcard_color_1_y : 8;
			uint32_t wildcard_color_1_u : 8;
			uint32_t wildcard_color_1_v : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* WILDCARD_ALPHA 16'h0010 */
	union {
		uint32_t wildcard_alpha; // word name
		struct {
			uint32_t wildcard_alpha_0 : 8;
			uint32_t wildcard_alpha_1 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CST_COEFF_Y_0 16'h0014 */
	union {
		uint32_t cst_coeff_y_0; // word name
		struct {
			uint32_t csr_cst_coeff_r2y_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t csr_cst_coeff_g2y_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CST_COEFF_Y_1 16'h0018 */
	union {
		uint32_t cst_coeff_y_1; // word name
		struct {
			uint32_t csr_cst_coeff_b2y_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t csr_cst_offset_y_2s : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* CST_COEFF_U_0 16'h001C */
	union {
		uint32_t cst_coeff_u_0; // word name
		struct {
			uint32_t csr_cst_coeff_r2u_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t csr_cst_coeff_g2u_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CST_COEFF_U_1 16'h0020 */
	union {
		uint32_t cst_coeff_u_1; // word name
		struct {
			uint32_t csr_cst_coeff_b2u_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t csr_cst_offset_u_2s : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* CST_COEFF_V_0 16'h0024 */
	union {
		uint32_t cst_coeff_v_0; // word name
		struct {
			uint32_t csr_cst_coeff_r2v_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t csr_cst_coeff_g2v_2s : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* CST_COEFF_V_1 16'h0028 */
	union {
		uint32_t cst_coeff_v_1; // word name
		struct {
			uint32_t csr_cst_coeff_b2v_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t csr_cst_offset_v_2s : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* LAYER_IMAGE_0_SETTING 16'h002C */
	union {
		uint32_t layer_image_0_setting; // word name
		struct {
			uint32_t layer_img_0_order_i : 3;
			uint32_t : 5; // padding bits
			uint32_t layer_img_0_order_o : 3;
			uint32_t : 5; // padding bits
			uint32_t layer_img_0_mode : 4;
			uint32_t : 4; // padding bits
			uint32_t layer_img_0_yuv_sel : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* LAYER_IMAGE_0_00_ENABLE 16'h0030 */
	union {
		uint32_t layer_image_0_00_enable; // word name
		struct {
			uint32_t layer_img_0_roi_00_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_0_00_START 16'h0034 */
	union {
		uint32_t layer_image_0_00_start; // word name
		struct {
			uint32_t layer_img_0_roi_00_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_00_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_00_END 16'h0038 */
	union {
		uint32_t layer_image_0_00_end; // word name
		struct {
			uint32_t layer_img_0_roi_00_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_00_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_01_ENABLE 16'h003C */
	union {
		uint32_t layer_image_0_01_enable; // word name
		struct {
			uint32_t layer_img_0_roi_01_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_0_01_START 16'h0040 */
	union {
		uint32_t layer_image_0_01_start; // word name
		struct {
			uint32_t layer_img_0_roi_01_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_01_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_01_END 16'h0044 */
	union {
		uint32_t layer_image_0_01_end; // word name
		struct {
			uint32_t layer_img_0_roi_01_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_01_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_02_ENABLE 16'h0048 */
	union {
		uint32_t layer_image_0_02_enable; // word name
		struct {
			uint32_t layer_img_0_roi_02_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_0_02_START 16'h004C */
	union {
		uint32_t layer_image_0_02_start; // word name
		struct {
			uint32_t layer_img_0_roi_02_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_02_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_02_END 16'h0050 */
	union {
		uint32_t layer_image_0_02_end; // word name
		struct {
			uint32_t layer_img_0_roi_02_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_02_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_03_ENABLE 16'h0054 */
	union {
		uint32_t layer_image_0_03_enable; // word name
		struct {
			uint32_t layer_img_0_roi_03_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_0_03_START 16'h0058 */
	union {
		uint32_t layer_image_0_03_start; // word name
		struct {
			uint32_t layer_img_0_roi_03_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_03_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_03_END 16'h005C */
	union {
		uint32_t layer_image_0_03_end; // word name
		struct {
			uint32_t layer_img_0_roi_03_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_03_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_04_ENABLE 16'h0060 */
	union {
		uint32_t layer_image_0_04_enable; // word name
		struct {
			uint32_t layer_img_0_roi_04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_0_04_START 16'h0064 */
	union {
		uint32_t layer_image_0_04_start; // word name
		struct {
			uint32_t layer_img_0_roi_04_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_04_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_04_END 16'h0068 */
	union {
		uint32_t layer_image_0_04_end; // word name
		struct {
			uint32_t layer_img_0_roi_04_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_04_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_05_ENABLE 16'h006C */
	union {
		uint32_t layer_image_0_05_enable; // word name
		struct {
			uint32_t layer_img_0_roi_05_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_0_05_START 16'h0070 */
	union {
		uint32_t layer_image_0_05_start; // word name
		struct {
			uint32_t layer_img_0_roi_05_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_05_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_05_END 16'h0074 */
	union {
		uint32_t layer_image_0_05_end; // word name
		struct {
			uint32_t layer_img_0_roi_05_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_05_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_06_ENABLE 16'h0078 */
	union {
		uint32_t layer_image_0_06_enable; // word name
		struct {
			uint32_t layer_img_0_roi_06_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_0_06_START 16'h007C */
	union {
		uint32_t layer_image_0_06_start; // word name
		struct {
			uint32_t layer_img_0_roi_06_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_06_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_06_END 16'h0080 */
	union {
		uint32_t layer_image_0_06_end; // word name
		struct {
			uint32_t layer_img_0_roi_06_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_06_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_07_ENABLE 16'h0084 */
	union {
		uint32_t layer_image_0_07_enable; // word name
		struct {
			uint32_t layer_img_0_roi_07_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_0_07_START 16'h0088 */
	union {
		uint32_t layer_image_0_07_start; // word name
		struct {
			uint32_t layer_img_0_roi_07_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_07_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_0_07_END 16'h008C */
	union {
		uint32_t layer_image_0_07_end; // word name
		struct {
			uint32_t layer_img_0_roi_07_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_0_roi_07_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_SETTING 16'h0090 */
	union {
		uint32_t layer_image_1_setting; // word name
		struct {
			uint32_t layer_img_1_order_i : 3;
			uint32_t : 5; // padding bits
			uint32_t layer_img_1_order_o : 3;
			uint32_t : 5; // padding bits
			uint32_t layer_img_1_mode : 4;
			uint32_t : 4; // padding bits
			uint32_t layer_img_1_yuv_sel : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* LAYER_IMAGE_1_00_ENABLE 16'h0094 */
	union {
		uint32_t layer_image_1_00_enable; // word name
		struct {
			uint32_t layer_img_1_roi_00_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_1_00_START 16'h0098 */
	union {
		uint32_t layer_image_1_00_start; // word name
		struct {
			uint32_t layer_img_1_roi_00_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_00_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_00_END 16'h009C */
	union {
		uint32_t layer_image_1_00_end; // word name
		struct {
			uint32_t layer_img_1_roi_00_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_00_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_01_ENABLE 16'h00A0 */
	union {
		uint32_t layer_image_1_01_enable; // word name
		struct {
			uint32_t layer_img_1_roi_01_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_1_01_START 16'h00A4 */
	union {
		uint32_t layer_image_1_01_start; // word name
		struct {
			uint32_t layer_img_1_roi_01_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_01_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_01_END 16'h00A8 */
	union {
		uint32_t layer_image_1_01_end; // word name
		struct {
			uint32_t layer_img_1_roi_01_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_01_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_02_ENABLE 16'h00AC */
	union {
		uint32_t layer_image_1_02_enable; // word name
		struct {
			uint32_t layer_img_1_roi_02_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_1_02_START 16'h00B0 */
	union {
		uint32_t layer_image_1_02_start; // word name
		struct {
			uint32_t layer_img_1_roi_02_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_02_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_02_END 16'h00B4 */
	union {
		uint32_t layer_image_1_02_end; // word name
		struct {
			uint32_t layer_img_1_roi_02_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_02_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_03_ENABLE 16'h00B8 */
	union {
		uint32_t layer_image_1_03_enable; // word name
		struct {
			uint32_t layer_img_1_roi_03_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_1_03_START 16'h00BC */
	union {
		uint32_t layer_image_1_03_start; // word name
		struct {
			uint32_t layer_img_1_roi_03_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_03_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_03_END 16'h00C0 */
	union {
		uint32_t layer_image_1_03_end; // word name
		struct {
			uint32_t layer_img_1_roi_03_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_03_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_04_ENABLE 16'h00C4 */
	union {
		uint32_t layer_image_1_04_enable; // word name
		struct {
			uint32_t layer_img_1_roi_04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_1_04_START 16'h00C8 */
	union {
		uint32_t layer_image_1_04_start; // word name
		struct {
			uint32_t layer_img_1_roi_04_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_04_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_04_END 16'h00CC */
	union {
		uint32_t layer_image_1_04_end; // word name
		struct {
			uint32_t layer_img_1_roi_04_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_04_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_05_ENABLE 16'h00D0 */
	union {
		uint32_t layer_image_1_05_enable; // word name
		struct {
			uint32_t layer_img_1_roi_05_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_1_05_START 16'h00D4 */
	union {
		uint32_t layer_image_1_05_start; // word name
		struct {
			uint32_t layer_img_1_roi_05_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_05_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_05_END 16'h00D8 */
	union {
		uint32_t layer_image_1_05_end; // word name
		struct {
			uint32_t layer_img_1_roi_05_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_05_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_06_ENABLE 16'h00DC */
	union {
		uint32_t layer_image_1_06_enable; // word name
		struct {
			uint32_t layer_img_1_roi_06_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_1_06_START 16'h00E0 */
	union {
		uint32_t layer_image_1_06_start; // word name
		struct {
			uint32_t layer_img_1_roi_06_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_06_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_06_END 16'h00E4 */
	union {
		uint32_t layer_image_1_06_end; // word name
		struct {
			uint32_t layer_img_1_roi_06_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_06_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_07_ENABLE 16'h00E8 */
	union {
		uint32_t layer_image_1_07_enable; // word name
		struct {
			uint32_t layer_img_1_roi_07_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_IMAGE_1_07_START 16'h00EC */
	union {
		uint32_t layer_image_1_07_start; // word name
		struct {
			uint32_t layer_img_1_roi_07_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_07_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_IMAGE_1_07_END 16'h00F0 */
	union {
		uint32_t layer_image_1_07_end; // word name
		struct {
			uint32_t layer_img_1_roi_07_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_img_1_roi_07_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_SETTING 16'h00F4 */
	union {
		uint32_t layer_bbox_0_setting; // word name
		struct {
			uint32_t layer_bbox_0_order_i : 3;
			uint32_t : 5; // padding bits
			uint32_t layer_bbox_0_order_o : 3;
			uint32_t : 5; // padding bits
			uint32_t layer_bbox_0_yuv_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_00_ENABLE 16'h00F8 */
	union {
		uint32_t layer_bbox_0_00_enable; // word name
		struct {
			uint32_t layer_bbox_0_roi_00_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_00_START 16'h00FC */
	union {
		uint32_t layer_bbox_0_00_start; // word name
		struct {
			uint32_t layer_bbox_0_roi_00_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_00_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_00_END 16'h0100 */
	union {
		uint32_t layer_bbox_0_00_end; // word name
		struct {
			uint32_t layer_bbox_0_roi_00_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_00_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_00_INFO 16'h0104 */
	union {
		uint32_t layer_bbox_0_00_info; // word name
		struct {
			uint32_t layer_bbox_0_roi_00_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_0_roi_00_alpha : 8;
			uint32_t layer_bbox_0_roi_00_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_0_00_COLOR 16'h0108 */
	union {
		uint32_t layer_bbox_0_00_color; // word name
		struct {
			uint32_t layer_bbox_0_roi_00_ch_0 : 8;
			uint32_t layer_bbox_0_roi_00_ch_1 : 8;
			uint32_t layer_bbox_0_roi_00_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_01_ENABLE 16'h010C */
	union {
		uint32_t layer_bbox_0_01_enable; // word name
		struct {
			uint32_t layer_bbox_0_roi_01_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_01_START 16'h0110 */
	union {
		uint32_t layer_bbox_0_01_start; // word name
		struct {
			uint32_t layer_bbox_0_roi_01_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_01_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_01_END 16'h0114 */
	union {
		uint32_t layer_bbox_0_01_end; // word name
		struct {
			uint32_t layer_bbox_0_roi_01_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_01_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_01_INFO 16'h0118 */
	union {
		uint32_t layer_bbox_0_01_info; // word name
		struct {
			uint32_t layer_bbox_0_roi_01_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_0_roi_01_alpha : 8;
			uint32_t layer_bbox_0_roi_01_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_0_01_COLOR 16'h011C */
	union {
		uint32_t layer_bbox_0_01_color; // word name
		struct {
			uint32_t layer_bbox_0_roi_01_ch_0 : 8;
			uint32_t layer_bbox_0_roi_01_ch_1 : 8;
			uint32_t layer_bbox_0_roi_01_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_02_ENABLE 16'h0120 */
	union {
		uint32_t layer_bbox_0_02_enable; // word name
		struct {
			uint32_t layer_bbox_0_roi_02_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_02_START 16'h0124 */
	union {
		uint32_t layer_bbox_0_02_start; // word name
		struct {
			uint32_t layer_bbox_0_roi_02_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_02_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_02_END 16'h0128 */
	union {
		uint32_t layer_bbox_0_02_end; // word name
		struct {
			uint32_t layer_bbox_0_roi_02_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_02_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_02_INFO 16'h012C */
	union {
		uint32_t layer_bbox_0_02_info; // word name
		struct {
			uint32_t layer_bbox_0_roi_02_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_0_roi_02_alpha : 8;
			uint32_t layer_bbox_0_roi_02_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_0_02_COLOR 16'h0130 */
	union {
		uint32_t layer_bbox_0_02_color; // word name
		struct {
			uint32_t layer_bbox_0_roi_02_ch_0 : 8;
			uint32_t layer_bbox_0_roi_02_ch_1 : 8;
			uint32_t layer_bbox_0_roi_02_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_03_ENABLE 16'h0134 */
	union {
		uint32_t layer_bbox_0_03_enable; // word name
		struct {
			uint32_t layer_bbox_0_roi_03_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_03_START 16'h0138 */
	union {
		uint32_t layer_bbox_0_03_start; // word name
		struct {
			uint32_t layer_bbox_0_roi_03_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_03_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_03_END 16'h013C */
	union {
		uint32_t layer_bbox_0_03_end; // word name
		struct {
			uint32_t layer_bbox_0_roi_03_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_03_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_03_INFO 16'h0140 */
	union {
		uint32_t layer_bbox_0_03_info; // word name
		struct {
			uint32_t layer_bbox_0_roi_03_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_0_roi_03_alpha : 8;
			uint32_t layer_bbox_0_roi_03_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_0_03_COLOR 16'h0144 */
	union {
		uint32_t layer_bbox_0_03_color; // word name
		struct {
			uint32_t layer_bbox_0_roi_03_ch_0 : 8;
			uint32_t layer_bbox_0_roi_03_ch_1 : 8;
			uint32_t layer_bbox_0_roi_03_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_04_ENABLE 16'h0148 */
	union {
		uint32_t layer_bbox_0_04_enable; // word name
		struct {
			uint32_t layer_bbox_0_roi_04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_04_START 16'h014C */
	union {
		uint32_t layer_bbox_0_04_start; // word name
		struct {
			uint32_t layer_bbox_0_roi_04_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_04_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_04_END 16'h0150 */
	union {
		uint32_t layer_bbox_0_04_end; // word name
		struct {
			uint32_t layer_bbox_0_roi_04_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_04_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_04_INFO 16'h0154 */
	union {
		uint32_t layer_bbox_0_04_info; // word name
		struct {
			uint32_t layer_bbox_0_roi_04_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_0_roi_04_alpha : 8;
			uint32_t layer_bbox_0_roi_04_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_0_04_COLOR 16'h0158 */
	union {
		uint32_t layer_bbox_0_04_color; // word name
		struct {
			uint32_t layer_bbox_0_roi_04_ch_0 : 8;
			uint32_t layer_bbox_0_roi_04_ch_1 : 8;
			uint32_t layer_bbox_0_roi_04_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_05_ENABLE 16'h015C */
	union {
		uint32_t layer_bbox_0_05_enable; // word name
		struct {
			uint32_t layer_bbox_0_roi_05_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_05_START 16'h0160 */
	union {
		uint32_t layer_bbox_0_05_start; // word name
		struct {
			uint32_t layer_bbox_0_roi_05_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_05_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_05_END 16'h0164 */
	union {
		uint32_t layer_bbox_0_05_end; // word name
		struct {
			uint32_t layer_bbox_0_roi_05_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_05_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_05_INFO 16'h0168 */
	union {
		uint32_t layer_bbox_0_05_info; // word name
		struct {
			uint32_t layer_bbox_0_roi_05_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_0_roi_05_alpha : 8;
			uint32_t layer_bbox_0_roi_05_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_0_05_COLOR 16'h016C */
	union {
		uint32_t layer_bbox_0_05_color; // word name
		struct {
			uint32_t layer_bbox_0_roi_05_ch_0 : 8;
			uint32_t layer_bbox_0_roi_05_ch_1 : 8;
			uint32_t layer_bbox_0_roi_05_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_06_ENABLE 16'h0170 */
	union {
		uint32_t layer_bbox_0_06_enable; // word name
		struct {
			uint32_t layer_bbox_0_roi_06_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_06_START 16'h0174 */
	union {
		uint32_t layer_bbox_0_06_start; // word name
		struct {
			uint32_t layer_bbox_0_roi_06_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_06_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_06_END 16'h0178 */
	union {
		uint32_t layer_bbox_0_06_end; // word name
		struct {
			uint32_t layer_bbox_0_roi_06_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_06_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_06_INFO 16'h017C */
	union {
		uint32_t layer_bbox_0_06_info; // word name
		struct {
			uint32_t layer_bbox_0_roi_06_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_0_roi_06_alpha : 8;
			uint32_t layer_bbox_0_roi_06_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_0_06_COLOR 16'h0180 */
	union {
		uint32_t layer_bbox_0_06_color; // word name
		struct {
			uint32_t layer_bbox_0_roi_06_ch_0 : 8;
			uint32_t layer_bbox_0_roi_06_ch_1 : 8;
			uint32_t layer_bbox_0_roi_06_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_07_ENABLE 16'h0184 */
	union {
		uint32_t layer_bbox_0_07_enable; // word name
		struct {
			uint32_t layer_bbox_0_roi_07_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_0_07_START 16'h0188 */
	union {
		uint32_t layer_bbox_0_07_start; // word name
		struct {
			uint32_t layer_bbox_0_roi_07_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_07_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_07_END 16'h018C */
	union {
		uint32_t layer_bbox_0_07_end; // word name
		struct {
			uint32_t layer_bbox_0_roi_07_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_0_roi_07_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_0_07_INFO 16'h0190 */
	union {
		uint32_t layer_bbox_0_07_info; // word name
		struct {
			uint32_t layer_bbox_0_roi_07_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_0_roi_07_alpha : 8;
			uint32_t layer_bbox_0_roi_07_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_0_07_COLOR 16'h0194 */
	union {
		uint32_t layer_bbox_0_07_color; // word name
		struct {
			uint32_t layer_bbox_0_roi_07_ch_0 : 8;
			uint32_t layer_bbox_0_roi_07_ch_1 : 8;
			uint32_t layer_bbox_0_roi_07_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_SETTING 16'h0198 */
	union {
		uint32_t layer_bbox_1_setting; // word name
		struct {
			uint32_t layer_bbox_1_order_i : 3;
			uint32_t : 5; // padding bits
			uint32_t layer_bbox_1_order_o : 3;
			uint32_t : 5; // padding bits
			uint32_t layer_bbox_1_yuv_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_00_ENABLE 16'h019C */
	union {
		uint32_t layer_bbox_1_00_enable; // word name
		struct {
			uint32_t layer_bbox_1_roi_00_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_00_START 16'h01A0 */
	union {
		uint32_t layer_bbox_1_00_start; // word name
		struct {
			uint32_t layer_bbox_1_roi_00_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_00_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_00_END 16'h01A4 */
	union {
		uint32_t layer_bbox_1_00_end; // word name
		struct {
			uint32_t layer_bbox_1_roi_00_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_00_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_00_INFO 16'h01A8 */
	union {
		uint32_t layer_bbox_1_00_info; // word name
		struct {
			uint32_t layer_bbox_1_roi_00_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_1_roi_00_alpha : 8;
			uint32_t layer_bbox_1_roi_00_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_1_00_COLOR 16'h01AC */
	union {
		uint32_t layer_bbox_1_00_color; // word name
		struct {
			uint32_t layer_bbox_1_roi_00_ch_0 : 8;
			uint32_t layer_bbox_1_roi_00_ch_1 : 8;
			uint32_t layer_bbox_1_roi_00_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_01_ENABLE 16'h01B0 */
	union {
		uint32_t layer_bbox_1_01_enable; // word name
		struct {
			uint32_t layer_bbox_1_roi_01_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_01_START 16'h01B4 */
	union {
		uint32_t layer_bbox_1_01_start; // word name
		struct {
			uint32_t layer_bbox_1_roi_01_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_01_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_01_END 16'h01B8 */
	union {
		uint32_t layer_bbox_1_01_end; // word name
		struct {
			uint32_t layer_bbox_1_roi_01_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_01_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_01_INFO 16'h01BC */
	union {
		uint32_t layer_bbox_1_01_info; // word name
		struct {
			uint32_t layer_bbox_1_roi_01_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_1_roi_01_alpha : 8;
			uint32_t layer_bbox_1_roi_01_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_1_01_COLOR 16'h01C0 */
	union {
		uint32_t layer_bbox_1_01_color; // word name
		struct {
			uint32_t layer_bbox_1_roi_01_ch_0 : 8;
			uint32_t layer_bbox_1_roi_01_ch_1 : 8;
			uint32_t layer_bbox_1_roi_01_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_02_ENABLE 16'h01C4 */
	union {
		uint32_t layer_bbox_1_02_enable; // word name
		struct {
			uint32_t layer_bbox_1_roi_02_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_02_START 16'h01C8 */
	union {
		uint32_t layer_bbox_1_02_start; // word name
		struct {
			uint32_t layer_bbox_1_roi_02_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_02_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_02_END 16'h01CC */
	union {
		uint32_t layer_bbox_1_02_end; // word name
		struct {
			uint32_t layer_bbox_1_roi_02_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_02_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_02_INFO 16'h01D0 */
	union {
		uint32_t layer_bbox_1_02_info; // word name
		struct {
			uint32_t layer_bbox_1_roi_02_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_1_roi_02_alpha : 8;
			uint32_t layer_bbox_1_roi_02_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_1_02_COLOR 16'h01D4 */
	union {
		uint32_t layer_bbox_1_02_color; // word name
		struct {
			uint32_t layer_bbox_1_roi_02_ch_0 : 8;
			uint32_t layer_bbox_1_roi_02_ch_1 : 8;
			uint32_t layer_bbox_1_roi_02_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_03_ENABLE 16'h01D8 */
	union {
		uint32_t layer_bbox_1_03_enable; // word name
		struct {
			uint32_t layer_bbox_1_roi_03_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_03_START 16'h01DC */
	union {
		uint32_t layer_bbox_1_03_start; // word name
		struct {
			uint32_t layer_bbox_1_roi_03_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_03_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_03_END 16'h01E0 */
	union {
		uint32_t layer_bbox_1_03_end; // word name
		struct {
			uint32_t layer_bbox_1_roi_03_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_03_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_03_INFO 16'h01E4 */
	union {
		uint32_t layer_bbox_1_03_info; // word name
		struct {
			uint32_t layer_bbox_1_roi_03_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_1_roi_03_alpha : 8;
			uint32_t layer_bbox_1_roi_03_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_1_03_COLOR 16'h01E8 */
	union {
		uint32_t layer_bbox_1_03_color; // word name
		struct {
			uint32_t layer_bbox_1_roi_03_ch_0 : 8;
			uint32_t layer_bbox_1_roi_03_ch_1 : 8;
			uint32_t layer_bbox_1_roi_03_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_04_ENABLE 16'h01EC */
	union {
		uint32_t layer_bbox_1_04_enable; // word name
		struct {
			uint32_t layer_bbox_1_roi_04_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_04_START 16'h01F0 */
	union {
		uint32_t layer_bbox_1_04_start; // word name
		struct {
			uint32_t layer_bbox_1_roi_04_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_04_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_04_END 16'h01F4 */
	union {
		uint32_t layer_bbox_1_04_end; // word name
		struct {
			uint32_t layer_bbox_1_roi_04_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_04_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_04_INFO 16'h01F8 */
	union {
		uint32_t layer_bbox_1_04_info; // word name
		struct {
			uint32_t layer_bbox_1_roi_04_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_1_roi_04_alpha : 8;
			uint32_t layer_bbox_1_roi_04_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_1_04_COLOR 16'h01FC */
	union {
		uint32_t layer_bbox_1_04_color; // word name
		struct {
			uint32_t layer_bbox_1_roi_04_ch_0 : 8;
			uint32_t layer_bbox_1_roi_04_ch_1 : 8;
			uint32_t layer_bbox_1_roi_04_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_05_ENABLE 16'h0200 */
	union {
		uint32_t layer_bbox_1_05_enable; // word name
		struct {
			uint32_t layer_bbox_1_roi_05_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_05_START 16'h0204 */
	union {
		uint32_t layer_bbox_1_05_start; // word name
		struct {
			uint32_t layer_bbox_1_roi_05_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_05_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_05_END 16'h0208 */
	union {
		uint32_t layer_bbox_1_05_end; // word name
		struct {
			uint32_t layer_bbox_1_roi_05_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_05_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_05_INFO 16'h020C */
	union {
		uint32_t layer_bbox_1_05_info; // word name
		struct {
			uint32_t layer_bbox_1_roi_05_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_1_roi_05_alpha : 8;
			uint32_t layer_bbox_1_roi_05_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_1_05_COLOR 16'h0210 */
	union {
		uint32_t layer_bbox_1_05_color; // word name
		struct {
			uint32_t layer_bbox_1_roi_05_ch_0 : 8;
			uint32_t layer_bbox_1_roi_05_ch_1 : 8;
			uint32_t layer_bbox_1_roi_05_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_06_ENABLE 16'h0214 */
	union {
		uint32_t layer_bbox_1_06_enable; // word name
		struct {
			uint32_t layer_bbox_1_roi_06_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_06_START 16'h0218 */
	union {
		uint32_t layer_bbox_1_06_start; // word name
		struct {
			uint32_t layer_bbox_1_roi_06_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_06_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_06_END 16'h021C */
	union {
		uint32_t layer_bbox_1_06_end; // word name
		struct {
			uint32_t layer_bbox_1_roi_06_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_06_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_06_INFO 16'h0220 */
	union {
		uint32_t layer_bbox_1_06_info; // word name
		struct {
			uint32_t layer_bbox_1_roi_06_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_1_roi_06_alpha : 8;
			uint32_t layer_bbox_1_roi_06_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_1_06_COLOR 16'h0224 */
	union {
		uint32_t layer_bbox_1_06_color; // word name
		struct {
			uint32_t layer_bbox_1_roi_06_ch_0 : 8;
			uint32_t layer_bbox_1_roi_06_ch_1 : 8;
			uint32_t layer_bbox_1_roi_06_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_07_ENABLE 16'h0228 */
	union {
		uint32_t layer_bbox_1_07_enable; // word name
		struct {
			uint32_t layer_bbox_1_roi_07_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LAYER_BBOX_1_07_START 16'h022C */
	union {
		uint32_t layer_bbox_1_07_start; // word name
		struct {
			uint32_t layer_bbox_1_roi_07_sx : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_07_sy : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_07_END 16'h0230 */
	union {
		uint32_t layer_bbox_1_07_end; // word name
		struct {
			uint32_t layer_bbox_1_roi_07_ex : 13;
			uint32_t : 3; // padding bits
			uint32_t layer_bbox_1_roi_07_ey : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* LAYER_BBOX_1_07_INFO 16'h0234 */
	union {
		uint32_t layer_bbox_1_07_info; // word name
		struct {
			uint32_t layer_bbox_1_roi_07_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t layer_bbox_1_roi_07_alpha : 8;
			uint32_t layer_bbox_1_roi_07_width : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* LAYER_BBOX_1_07_COLOR 16'h0238 */
	union {
		uint32_t layer_bbox_1_07_color; // word name
		struct {
			uint32_t layer_bbox_1_roi_07_ch_0 : 8;
			uint32_t layer_bbox_1_roi_07_ch_1 : 8;
			uint32_t layer_bbox_1_roi_07_ch_2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG_MONITOR_SEL 16'h023C */
	union {
		uint32_t debug_monitor_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENC_OSD_RESERVED_0 16'h0240 */
	union {
		uint32_t enc_osd_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* ENC_OSD_RESERVED_1 16'h0244 */
	union {
		uint32_t enc_osd_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* ENC_OSD_RESERVED_2 16'h0248 */
	union {
		uint32_t enc_osd_reserved_2; // word name
		struct {
			uint32_t reserved_2 : 32;
		};
	};
} CsrBankEnc_osd;

#endif