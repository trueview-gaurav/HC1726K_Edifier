/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __DRIVERS_AGTX_AES_KEY_EXPANSION_H
#define __DRIVERS_AGTX_AES_KEY_EXPANSION_H

#include <stdint.h>

typedef enum { AES_CIPHER_128, AES_CIPHER_256 } AES_CIPHER_T;

extern int g_aes_rounds[];
extern int g_aes_nk[];
extern int g_aes_nb[];

uint8_t aes_sub_sbox(uint8_t val);
uint32_t aes_sub_dword(uint32_t val);
uint32_t aes_rot_dword(uint32_t val);
uint32_t aes_swap_dword(uint32_t val);
void aes_key_expansion(AES_CIPHER_T mode, uint32_t *key, uint32_t *result);

#endif /* __DRIVERS_AGTX_AES_KEY_EXPANSION_H */
