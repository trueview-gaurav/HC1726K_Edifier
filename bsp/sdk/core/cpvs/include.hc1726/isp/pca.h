/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_PCA_H_
#define SAPPORO_PCA_H_

#include "autoconf.h"

#include "isp_utils.h"
#include "csr_bank_pca.h"

typedef enum isp_pca_mode {
	ISP_PCA_MODE_NORMAL = 0,
	ISP_PCA_MODE_BYPASS,
	ISP_PCA_MODE_NUM,
} IspPcaMode;

typedef enum isp_pca_ink_mode {
	ISP_PCA_INK_MODE_INPUT_HUE = 0,
	ISP_PCA_INK_MODE_INPUT_SATURATION,
	ISP_PCA_INK_MODE_INPUT_LIGHTNESS,
	ISP_PCA_INK_MODE_DELTA_HUE,
	ISP_PCA_INK_MODE_DELTA_SATURATION,
	ISP_PCA_INK_MODE_DELTA_LIGHTNESS,
	ISP_PCA_INK_MODE_DELTA_FLAG,
	ISP_PCA_INK_MODE_DISABLE,
	ISP_PCA_INK_MODE_NUM
} IspPcaInkMode;

typedef struct isp_pca_coeff_cfg {
	struct rgb_to_hsl {
		uint16_t h_prime_from_rgb_shift;
		uint16_t h_prime_r_redefined;
		uint16_t h_prime_g_redefined;
		uint16_t h_prime_b_redefined;
		uint16_t h_prime_r_pos_60degree;
		uint16_t h_prime_r_neg_60degree;
		uint16_t h_prime_g_pos_60degree;
		uint16_t h_prime_g_neg_60degree;
		uint16_t h_prime_b_pos_60degree;
		uint16_t h_prime_b_neg_60degree;
		uint16_t h_prime_correction_term;
		uint16_t h_cal_60_degree;
	} rgb2hsl;
	struct hsl_to_rgb {
		uint16_t h_prime_shift;
	} hsl2rgb;
} IspPcaCoeffCfg;

typedef struct isp_pca_table_cfg {
	int eee[PCA_EEE_WORD_NUM];
	int eoe[PCA_EOE_WORD_NUM];
	int oee[PCA_OEE_WORD_NUM];
	int ooe[PCA_OOE_WORD_NUM];
	int eeo[PCA_EEO_WORD_NUM];
	int eoo[PCA_EOO_WORD_NUM];
	int oeo[PCA_OEO_WORD_NUM];
	int ooo[PCA_OOO_WORD_NUM];
} IspPcaTableCfg;

typedef struct isp_pca_cfg {
	enum isp_pca_mode mode;
	enum isp_pca_ink_mode ink_mode;
	uint8_t ink_delta_sum_th;
} IspPcaCfg;

#ifdef CONFIG_KAMO
typedef struct isp_pca_cfg {
	uint8_t yuv2rgb_mode;
} IspPcaCfg;
#endif

void isp_pca_set_coeff_cfg(volatile CsrBankPca *csr, const struct isp_pca_coeff_cfg *cfg);
void isp_pca_get_coeff_cfg(volatile CsrBankPca *csr, struct isp_pca_coeff_cfg *cfg);

void isp_pca_set_table_cfg(volatile CsrBankPca *csr, const struct isp_pca_table_cfg *cfg);
void isp_pca_get_table_cfg(volatile CsrBankPca *csr, struct isp_pca_table_cfg *cfg);

void isp_pca_set_cfg(volatile CsrBankPca *csr, const struct isp_pca_cfg *cfg);
void isp_pca_get_cfg(volatile CsrBankPca *csr, struct isp_pca_cfg *cfg);

#ifdef CONFIG_KAMO
void isp_pca_set_cfg(volatile CsrBankPca *csr, const struct isp_pca_cfg *cfg);
void isp_pca_get_cfg(volatile CsrBankPca *csr, struct isp_pca_cfg *cfg);
#endif

#endif /* SAPPORO_PCA_H_ */
