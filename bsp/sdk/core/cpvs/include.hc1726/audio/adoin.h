/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef _ADOIN_H_
#define _ADOIN_H_

typedef enum adoin_src_bmp {
	ADOIN_SRC_ADC_L = 0x1,
#if defined(CONFIG_SAPPORO)
	ADOIN_SRC_ADC_R = 0x2,
	ADOIN_SRC_DMIC_L = 0x4,
	ADOIN_SRC_DMIC_R = 0x8,
	ADOIN_SRC_I2S = 0x10,
#endif
} AdoinSrcBmp;

#endif /* _ADOIN_H_ */
