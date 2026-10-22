/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_DMS_H_
#define KYOTO_DMS_H_

#include "isp_utils.h"
#include "csr_bank_dms.h"

typedef enum isp_dms_mode {
	ISP_DMS_MODE_NORMAL = 0,
	ISP_DMS_MODE_BYPASS = 1,
	ISP_DMS_MODE_MONO = 2,
	ISP_DMS_MODE_NA = 3,
	ISP_DMS_MODE_NUM = 4,
} IspDmsMode;

typedef struct isp_dms_cfg {
	enum isp_dms_mode mode;
	uint8_t g_var_gain;
	uint8_t fcs_threshold;
	uint8_t inter_conf_slope;
	uint8_t fcs_offset;
	uint8_t g_at_m_inter_ratio;
	uint8_t m_at_m_inter_ratio;
	uint8_t m_at_g_inter_ratio;
	uint8_t g_at_m_soft_clip_slope;
	uint8_t m_at_m_soft_clip_slope;
	uint8_t m_at_g_soft_clip_slope;
	uint8_t m_at_g_gradient_src_ratio;
} IspDmsCfg;

/* IRQ mask */
void isp_dms_set_irq_mask_frame_end(volatile CsrBankDms *csr, uint8_t irq_mask_frame_end);
uint8_t isp_dms_get_irq_mask_frame_end(volatile CsrBankDms *csr);

/* Resolution */
void isp_dms_set_res(volatile CsrBankDms *csr, const struct res *res);
void isp_dms_get_res(volatile CsrBankDms *csr, struct res *res);

/* Bayer */
void isp_dms_set_ini_bayer_phase(volatile CsrBankDms *csr, enum ini_bayer_phase bayer);
enum ini_bayer_phase isp_dms_get_ini_bayer_phase(volatile CsrBankDms *csr);

/* DMS */
void isp_dms_set_cfg(volatile CsrBankDms *csr, const struct isp_dms_cfg *cfg);
void isp_dms_get_cfg(volatile CsrBankDms *csr, struct isp_dms_cfg *cfg);

/* Debug */
void isp_dms_set_dbg_mon_sel(volatile CsrBankDms *csr, uint8_t debug_mon_sel);
uint8_t isp_dms_get_dbg_mon_sel(volatile CsrBankDms *csr);

/* Reserved */
void isp_dms_set_reserved(volatile CsrBankDms *csr, uint32_t reserved);
uint32_t isp_dms_get_reserved(volatile CsrBankDms *csr);

#endif /* KYOTO_DMS_H_ */