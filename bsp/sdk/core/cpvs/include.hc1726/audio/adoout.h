/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef _ADOOUT_H_
#define _ADOOUT_H_

#if defined(CONFIG_SAPPORO)
#define CKEN_READ_K (0x20000000)
#define CKEN_READ_K_MASK (~CKEN_READ_K) //(0xDFFFFFFF)
#endif

typedef enum adoout_dst {
	ADOOUT_DST_DAC = 0,
#if defined(CONFIG_SAPPORO)
	ADOOUT_DST_I2S,
#endif
} AdooutDst;

typedef enum adoout_up_mode {
	ADOOUT_UP_X2 = 0,
	ADOOUT_UP_X3,
	ADOOUT_UP_X4,
	ADOOUT_UP_X6,
	ADOOUT_UP_X8,
	ADOOUT_UP_X12,
	ADOOUT_UP_X1,
	ADOOUT_UP_NUM,
} AdooutUpMode;

#endif /* _ADOOUT_H_ */
