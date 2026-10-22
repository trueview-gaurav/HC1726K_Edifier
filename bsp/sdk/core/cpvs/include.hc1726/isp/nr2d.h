/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_NR2D_H_
#define SAPPORO_NR2D_H_

#include "isp_utils.h"
#include "csr_bank_nr2d.h"

typedef enum isp_nr2d_mode {
	ISP_NR2D_NORMAL = 0,
	ISP_NR2D_DISABLE,
	ISP_NR2D_BYPASS,
	ISP_NR2D_INK,
	ISP_NR2D_MODE_NUM,
} IspNr2dMode;

typedef enum isp_nr2d_guided_filter_mode {
	ISP_NR2D_GUIDEED_FILTER_MODE_NORMAL = 0,
	ISP_NR2D_GUIDEED_FILTER_MODE_DISABLE
} IspNr2dGuidedFilterMode;

typedef struct isp_nr2d_cfg {
	enum isp_nr2d_guided_filter_mode y_mode;
	enum isp_nr2d_guided_filter_mode c_mode;
	enum isp_nr2d_mode mode;

	struct chroma_control_gain {
		uint16_t x[NR2D_CHROMA_CTRL_GAIN_ENTRY_NUM];
		uint16_t y[NR2D_CHROMA_CTRL_GAIN_ENTRY_NUM];
		uint16_t m; // TO-DO: 2s?
	} c_ctrl_gain;

	struct luma_lut {
		uint16_t x[NR2D_LUMA_LUT_ENTRTY_NUM];
		uint16_t y[NR2D_LUMA_LUT_ENTRTY_NUM];
		uint16_t m_2s[NR2D_LUMA_LUT_ENTRTY_NUM - 1];
	} luma_lut;

	struct edge_confidence {
		uint16_t x[NR2D_EDGE_CONFIDENCE_ENTRY_NUM];
		uint16_t y[NR2D_EDGE_CONFIDENCE_ENTRY_NUM];
		uint16_t m; // TO-DO: 2s?
	} edge_conf;

	struct nlm_cfg {
		uint16_t l_weight_th;
		uint16_t c_weight_th;
		uint8_t lut_x[NR2D_NLM_LUT_ENTRY_NUM];
		uint8_t lut_y[NR2D_NLM_LUT_ENTRY_NUM];
		uint16_t l_mean_candidate_th;
		uint16_t l_cnt_fallback_ratio;
		uint16_t l_cnt_th;
		uint16_t l_fallback_min;
		uint16_t l_fallback_max;
		uint16_t l_nl_ctrl;
		uint16_t l_global_fallback_alpha;
		uint16_t c_mean_candidate_th;
		uint16_t c_cnt_fallback_ratio;
		uint16_t c_cnt_th;
		uint16_t c_fallback_min;
		uint16_t c_fallback_max;
		uint16_t c_nl_ctrl;
		uint16_t c_global_fallback_alpha;
	} nlm;
} IspNr2dCfg;

typedef struct isp_nr2d_demo {
	uint8_t enable;
	uint16_t x_min;
	uint16_t x_max;
	uint16_t y_min;
	uint16_t y_max;
} IspNr2dDemo;

/* IRQ mask */
void isp_nr2d_set_irq_mask_frame_end(volatile CsrBankNr2d *csr, uint8_t irq_mask_frame_end);
uint8_t isp_nr2d_get_irq_mask_frame_end(volatile CsrBankNr2d *csr);

/* Resolution */
void isp_nr2d_set_res(volatile CsrBankNr2d *csr, const struct res *res);
void isp_nr2d_get_res(volatile CsrBankNr2d *csr, struct res *res);

/* NR2D */
void isp_nr2d_set_cfg(volatile CsrBankNr2d *csr, const struct isp_nr2d_cfg *cfg);
void isp_nr2d_get_cfg(volatile CsrBankNr2d *csr, struct isp_nr2d_cfg *cfg);

/* Debug */
void isp_nr2d_set_dbg_mon_sel(volatile CsrBankNr2d *csr, uint8_t debug_mon_sel);
uint8_t isp_nr2d_get_dbg_mon_sel(volatile CsrBankNr2d *csr);

/* ATPG */
void isp_nr2d_set_atpg_ctrl(volatile CsrBankNr2d *csr, uint8_t atpg_ctrl);
uint8_t isp_nr2d_get_atpg_ctrl(volatile CsrBankNr2d *csr);

/* Reserved */
void isp_nr2d_set_reserved(volatile CsrBankNr2d *csr, uint8_t reserved);
uint8_t isp_nr2d_get_reserved(volatile CsrBankNr2d *csr);

/* Ink */
void isp_nr2d_set_ink_num(volatile CsrBankNr2d *csr, uint8_t ink_num);
uint8_t isp_nr2d_get_ink_num(volatile CsrBankNr2d *csr);

/* Demo */
void isp_nr2d_set_demo(volatile CsrBankNr2d *csr, const struct isp_nr2d_demo *demo);
void isp_nr2d_get_demo(volatile CsrBankNr2d *csr, struct isp_nr2d_demo *demo);

#endif /* NR2D_ENH_H_ */
