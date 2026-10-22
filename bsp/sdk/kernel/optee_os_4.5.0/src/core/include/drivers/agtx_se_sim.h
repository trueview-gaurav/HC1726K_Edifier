/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __DRIVERS_AGTX_SE_SIM_H
#define __DRIVERS_AGTX_SE_SIM_H

#include <tee_api_types.h>

/* Command IDs */
#define PTA_CMD_DATA_HMAC_SHA256 0x0
#define PTA_CMD_DATA_ENC_AES_ECB_256_NO_PAD 0x1
#define PTA_CMD_DATA_DEC_AES_ECB_256_NO_PAD 0x2
#define PTA_CMD_DATA_HKDF 0x3

/* Data config */
#define SHA256_BYTE 32
#define AES_ECB_BLOCK_BYTE 16
#define KEY_BYTE 32

TEE_Result get_huk_subkey_derive(uint8_t *derived_key, size_t derived_key_sz);
TEE_Result data_hmac_sha256(const uint8_t *data, uint8_t *mac, size_t data_sz, size_t mac_sz);
TEE_Result data_enc_aes_ecb_256_no_pad(const uint8_t *data, uint8_t *cipher, size_t data_sz, size_t cipher_sz);
TEE_Result data_dec_aes_ecb_256_no_pad(const uint8_t *cipher, uint8_t *data, size_t cipher_sz, size_t data_sz);
TEE_Result hkdf_sha256(const uint8_t *salt, size_t salt_len, uint8_t *okm, size_t okm_len);

#endif /* __DRIVERS_AGTX_SE_SIM_H */
