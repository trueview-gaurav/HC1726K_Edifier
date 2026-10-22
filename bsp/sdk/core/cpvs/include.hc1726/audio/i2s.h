/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef _I2S_H_
#define _I2S_H_

typedef enum i2s_dir {
	I2S_DIR_IN = 0,
	I2S_DIR_OUT,
} I2sDir;

typedef enum i2s_mode {
	I2S_MODE_SLAVE = 0,
	I2S_MODE_MASTER,
} I2sMode;

typedef enum i2s_src {
	I2S_SRC_INTRA = 0,
	I2S_SRC_INTER,
} I2sSrc;

typedef enum i2s_dst {
	I2S_DST_INTRA = 0,
	I2S_DST_INTER,
} I2sDst;

#endif /* _I2S_H_ */
