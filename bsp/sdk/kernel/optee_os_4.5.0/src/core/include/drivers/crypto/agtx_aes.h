/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __DRIVERS_AGTX_AES_H
#define __DRIVERS_AGTX_AES_H

#define ENABLE 1
#define DISABLE 0

enum AES_ALGO { ECB = 0, CBC, CTR };
enum AES_ACTION { ENCODE = 0, DECODE };
enum AES_KEY_MODE { KEY_128 = 0, KEY_256 };

struct agtx_cipher_ctx {
	enum AES_ALGO algo;
	enum AES_KEY_MODE key_mode;
	bool encrypt;
	uint8_t key_len;
	uint32_t *key;
	uint32_t *iv;
};

#endif /* __DRIVERS_AGTX_AES_H */
