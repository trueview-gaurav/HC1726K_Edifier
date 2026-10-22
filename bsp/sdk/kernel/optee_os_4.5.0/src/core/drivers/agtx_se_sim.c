/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <tee_api_defines.h>
#include <trace.h>
#include <drivers/agtx_se_sim.h>
#include <kernel/panic.h>
#include <kernel/huk_subkey.h>
#include <crypto/crypto.h>
#include <string.h>

TEE_Result data_hmac_sha256(const uint8_t *data, uint8_t *mac, size_t data_sz, size_t mac_sz)
{
	TEE_Result res = TEE_SUCCESS;
	struct crypto_cipher_ctx *ctx = NULL;
	uint8_t derived_key[KEY_BYTE] = {};

	if (!data || !mac || data_sz == 0 || mac_sz != SHA256_BYTE)
		return TEE_ERROR_BAD_PARAMETERS;

	/* Get HUK derived key */
	res = huk_subkey_derive(1, NULL, 0, derived_key, sizeof(derived_key));
	if (res != TEE_SUCCESS)
		return res;

	/* MAC initilization */
	res = crypto_mac_alloc_ctx(&ctx, TEE_ALG_HMAC_SHA256);
	if (res != TEE_SUCCESS)
		return res;

	res = crypto_mac_init(ctx, derived_key, sizeof(derived_key));
	if (res != TEE_SUCCESS)
		goto cleanup;

	res = crypto_mac_update(ctx, data, data_sz);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/* MAC finalization */
	res = crypto_mac_final(ctx, mac, mac_sz);
	if (res != TEE_SUCCESS)
		goto cleanup;

cleanup:
	if (ctx)
		crypto_mac_free_ctx(ctx);

	return res;
}

TEE_Result data_enc_aes_ecb_256_no_pad(const uint8_t *data, uint8_t *cipher, size_t data_sz, size_t cipher_sz)
{
	TEE_Result res = TEE_SUCCESS;
	struct crypto_cipher_ctx *ctx = NULL;
	uint8_t derived_key[KEY_BYTE] = {};

	if (!data || !cipher || data_sz == 0 || cipher_sz != data_sz || (data_sz % AES_ECB_BLOCK_BYTE))
		return TEE_ERROR_BAD_PARAMETERS;

	/* Get HUK derived key */
	res = huk_subkey_derive(1, NULL, 0, derived_key, sizeof(derived_key));
	if (res != TEE_SUCCESS)
		return res;

	/* Crypto initialization */
	res = crypto_cipher_alloc_ctx(&ctx, TEE_ALG_AES_ECB_NOPAD);
	if (res != TEE_SUCCESS)
		return res;

	res = crypto_cipher_init(ctx, TEE_MODE_ENCRYPT, (const uint8_t *)derived_key, KEY_BYTE, NULL, 0, NULL, 0);
	if (res != TEE_SUCCESS)
		goto cleanup;

	res = crypto_cipher_update(ctx, TEE_MODE_ENCRYPT, true, (const uint8_t *)data, data_sz, (uint8_t *)cipher);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/* Crypto finalization */
	crypto_cipher_final(ctx);

cleanup:
	if (ctx)
		crypto_cipher_free_ctx(ctx);

	return res;
}

TEE_Result data_dec_aes_ecb_256_no_pad(const uint8_t *cipher, uint8_t *data, size_t cipher_sz, size_t data_sz)
{
	TEE_Result res = TEE_SUCCESS;
	struct crypto_cipher_ctx *ctx = NULL;
	uint8_t derived_key[KEY_BYTE] = {};

	if (!cipher || !data || cipher_sz == 0 || cipher_sz != data_sz || (cipher_sz % 16))
		return TEE_ERROR_BAD_PARAMETERS;

	/* Get HUK derived key */
	res = huk_subkey_derive(1, NULL, 0, derived_key, sizeof(derived_key));
	if (res != TEE_SUCCESS)
		return res;

	/* Crypto initialization */
	res = crypto_cipher_alloc_ctx(&ctx, TEE_ALG_AES_ECB_NOPAD);
	if (res)
		return res;

	res = crypto_cipher_init(ctx, TEE_MODE_DECRYPT, (const uint8_t *)derived_key, KEY_BYTE, NULL, 0, NULL, 0);
	if (res)
		goto cleanup;

	res = crypto_cipher_update(ctx, TEE_MODE_DECRYPT, true, (const uint8_t *)cipher, cipher_sz, (uint8_t *)data);
	if (res)
		goto cleanup;

	/* Crypto finalization */
	crypto_cipher_final(ctx);

cleanup:
	if (ctx)
		crypto_cipher_free_ctx(ctx);

	return res;
}

TEE_Result hkdf_sha256(const uint8_t *salt, size_t salt_len, uint8_t *okm, size_t okm_len)
{
	TEE_Result res = TEE_ERROR_GENERIC;
	void *ctx = NULL;
	uint8_t ikm[KEY_BYTE] = {};
	uint8_t prk[KEY_BYTE] = {};
	uint8_t t[KEY_BYTE] = {};
	uint8_t counter = 1;
	size_t done = 0;
	const size_t hlen = KEY_BYTE;

	/* Get HUK derived key */
	res = huk_subkey_derive(1, NULL, 0, ikm, sizeof(ikm));
	if (res != TEE_SUCCESS)
		return res;

	/* Extract: PRK = HMAC-SHA256(salt, IKM) */
	res = crypto_mac_alloc_ctx(&ctx, TEE_ALG_HMAC_SHA256);
	if (res != TEE_SUCCESS)
		return res;

	if (!salt || !salt_len) {
		uint8_t zero_salt[KEY_BYTE] = { 0 };
		res = crypto_mac_init(ctx, zero_salt, hlen);
	} else {
		res = crypto_mac_init(ctx, salt, salt_len);
	}

	if (res == TEE_SUCCESS)
		res = crypto_mac_update(ctx, ikm, sizeof(ikm));

	if (res == TEE_SUCCESS)
		res = crypto_mac_final(ctx, prk, hlen);

	crypto_mac_free_ctx(ctx);
	if (res != TEE_SUCCESS)
		return res;

	/* Expand: T(i) = HMAC-SHA256(PRK, T(i-1) | i) */
	while (done < okm_len) {
		res = crypto_mac_alloc_ctx(&ctx, TEE_ALG_HMAC_SHA256);
		if (res != TEE_SUCCESS)
			return res;

		res = crypto_mac_init(ctx, prk, hlen);
		if (res != TEE_SUCCESS)
			goto cleanup;

		if (done != 0) {
			res = crypto_mac_update(ctx, t, hlen);
			if (res != TEE_SUCCESS)
				goto cleanup;
		}

		res = crypto_mac_update(ctx, &counter, 1);
		if (res != TEE_SUCCESS)
			goto cleanup;

		res = crypto_mac_final(ctx, t, hlen);
		if (res != TEE_SUCCESS)
			goto cleanup;

		size_t to_copy = (okm_len - done) < hlen ? (okm_len - done) : hlen;
		memcpy(okm + done, t, to_copy);

		done += to_copy;
		counter++;
		crypto_mac_free_ctx(ctx);

		if (counter == 0 && done < okm_len)
			return TEE_ERROR_BAD_PARAMETERS;
		continue;
	cleanup:
		crypto_mac_free_ctx(ctx);
		return res;
	}

	return TEE_SUCCESS;
}
