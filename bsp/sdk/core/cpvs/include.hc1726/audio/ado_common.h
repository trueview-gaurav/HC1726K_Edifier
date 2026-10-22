/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef _ADO_COMMON_H_
#define _ADO_COMMON_H_

typedef enum ado_ch_mode {
	ADO_CH_MODE_PASS_ALL = 0,
	ADO_CH_MODE_PASS_NONE = 1,
	ADO_CH_MODE_PASS_EVEN = 2,
	ADO_CH_MODE_PASS_ODD = 3,
	ADO_CH_MODE_DUPLICATE = 4,
} AdoChMode;

typedef enum ado_format {
	ADO_FORMAT_S32_LE = 0,
	ADO_FORMAT_S16_LE = 1,
} AdoFormat;

#endif /* _ADO_COMMON_H_ */
