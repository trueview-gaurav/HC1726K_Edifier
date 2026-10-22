/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_FCS_H_
#define KYOTO_FCS_H_

#include "isp_utils.h"
#include "csr_bank_fcs.h"

typedef enum isp_fcs_mode {
	ISP_FCS_MODE_NORMAL = 0,
	ISP_FCS_MODE_DISABLE,
	ISP_FCS_MODE_NUM,
} IspFcsMode;

typedef enum isp_cac_mode {
	ISP_CAC_MODE_NORMAL = 0,
	ISP_CAC_MODE_DISABLE,
	ISP_CAC_MODE_NUM,
} IspCacMode;

typedef struct isp_fcs_cfg {
	enum isp_fcs_mode fcs_mode;
	enum isp_cac_mode cac_mode;
	struct trans_lv_det {
		uint8_t diff_level_max;
		uint8_t gain;
	} trans; /**< Transition level detection */
	struct grid_lv_det {
		uint8_t cnt_th_high;
		uint8_t cnt_th_low;
		uint8_t cnt_raw_th;
		uint16_t trans_level_th;
		uint8_t trans_round_bit_high;
		uint8_t trans_round_bit_low;
	} grid; /**< Grid level detection */
	struct color_type_det {
		uint8_t diff_self_th;
		uint8_t diff_neighbor_th;
		uint8_t coring_th;
	} color; /**< Color type detection */
	struct false_color_corr {
		uint8_t correction_gain;
		uint16_t target_bg_ratio;
		uint16_t target_rg_ratio;
	} corr; /**< False color correction */
	struct arbitration {
		uint16_t c_constraint_r;
		uint16_t c_constraint_b;
		uint16_t func_param; //?
	} arbitration; /** < arbitration */
	struct lcac {
		uint16_t achromatic_th;
		uint16_t achroma_conf_slope;
		uint16_t r_g_diff_alpha;
		uint16_t b_g_diff_alpha;
		uint16_t m_g_diff_soft_clip_slope;
		uint16_t lcac_r_level;
		uint16_t lcac_b_level;
		uint16_t luma_coeff_r_y;
		uint16_t luma_coeff_g_y;
		uint16_t luma_coeff_b_y;
	} lcac; /** < lcac */
	struct ti_hpf {
		uint16_t coeff_0_b_2s;
		uint16_t coeff_1_b_2s;
		uint16_t coeff_2_b_2s;
		uint16_t coeff_0_g_2s;
		uint16_t coeff_1_g_2s;
		uint16_t coeff_2_g_2s;
		uint16_t coeff_0_r_2s;
		uint16_t coeff_1_r_2s;
		uint16_t coeff_2_r_2s;
	} hpf; /** < ti high pass filter*/

	uint16_t alpha_lcac_fcs;
} IspFcsCfg;

/* IRQ mask */
void isp_fcs_set_irq_mask_frame_end(volatile CsrBankFcs *csr, uint8_t irq_mask_frame_end);
uint8_t isp_fcs_get_irq_mask_frame_end(volatile CsrBankFcs *csr);

/* Resolution */
void isp_fcs_set_res(volatile CsrBankFcs *csr, const struct res *res);
void isp_fcs_get_res(volatile CsrBankFcs *csr, struct res *res);

/* FCS */
void isp_fcs_set_cfg(volatile CsrBankFcs *csr, const struct isp_fcs_cfg *cfg);
void isp_fcs_get_cfg(volatile CsrBankFcs *csr, struct isp_fcs_cfg *cfg);

/* Debug */
void isp_fcs_set_dbg_mon_sel(volatile CsrBankFcs *csr, uint8_t debug_mon_sel);
uint8_t isp_fcs_get_dbg_mon_sel(volatile CsrBankFcs *csr);

/* Reserved */
void isp_fcs_set_reserved(volatile CsrBankFcs *csr, uint32_t reserved);
uint32_t isp_fcs_get_reserved(volatile CsrBankFcs *csr);

/* ATPG */
void isp_fcs_set_atpg_test_enable_0(volatile CsrBankFcs *csr, uint8_t atpg_test_enable_0);
uint8_t isp_fcs_get_atpg_test_enable_0(volatile CsrBankFcs *csr);
void isp_fcs_set_atpg_test_enable_1(volatile CsrBankFcs *csr, uint8_t atpg_test_enable_1);
uint8_t isp_fcs_get_atpg_test_enable_1(volatile CsrBankFcs *csr);

#endif /* SAPPORO_FCS_H_ */
