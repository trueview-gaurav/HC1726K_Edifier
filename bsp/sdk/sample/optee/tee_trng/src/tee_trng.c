#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/provider.h>
#include <openssl/crypto.h>
#include <openssl/core_dispatch.h>
#include <openssl/core_names.h>

#include <pkcs11.h>

struct tee_trng_rand_ctx {
	int state;
	CK_SESSION_HANDLE session;
	CK_SLOT_ID slot_id;
	CK_CHAR_PTR pin;
};

static void *libckteec_rand_newctx(void *provctx, void *parent, const OSSL_DISPATCH *parent_dispatch)
{
	(void)(provctx);
	(void)(parent);
	(void)(parent_dispatch);

	struct tee_trng_rand_ctx *ctx = OPENSSL_zalloc(sizeof(*ctx));
	if (ctx) {
		ctx->state = EVP_RAND_STATE_UNINITIALISED;
		ctx->session = CK_INVALID_HANDLE;
		ctx->slot_id = 0;
		ctx->pin = NULL;
	}

	return ctx;
}

static void libckteec_rand_freectx(void *vctx)
{
	OPENSSL_free(vctx);
}

static int libckteec_rand_instantiate(void *vctx, unsigned int strength, int prediction_resistance,
                                      const unsigned char *pstr, size_t pstr_len, const OSSL_PARAM params[])
{
	(void)(strength);
	(void)(prediction_resistance);
	(void)(pstr);
	(void)(pstr_len);
	(void)(params);

	struct tee_trng_rand_ctx *ctx = (struct tee_trng_rand_ctx *)vctx;
	ctx->state = EVP_RAND_STATE_READY;
	return 1;
}

static int libckteec_rand_uninstantiate(void *vctx)
{
	struct tee_trng_rand_ctx *ctx = (struct tee_trng_rand_ctx *)vctx;
	ctx->state = EVP_RAND_STATE_UNINITIALISED;
	return 1;
}

static int libckteec_rand_generate(void *vctx, unsigned char *out, size_t outlen, unsigned int strength,
                                   int prediction_resistance, const unsigned char *adin, size_t adinlen)
{
	(void)(strength);
	(void)(prediction_resistance);
	(void)(adin);
	(void)(adinlen);

	struct tee_trng_rand_ctx *ctx = (struct tee_trng_rand_ctx *)vctx;
	CK_RV ret;

	const char *slot_id_env = getenv("TEE_TRNG_SLOT_ID");
	if (slot_id_env)
		ctx->slot_id = (CK_SLOT_ID)atoi(slot_id_env);
	const char *pin_env = getenv("TEE_TRNG_PIN");
	if (pin_env)
		ctx->pin = (CK_CHAR_PTR)strdup(pin_env);

	ret = C_OpenSession(ctx->slot_id, CKF_SERIAL_SESSION, NULL, NULL, &ctx->session);
	if (ret != CKR_OK) {
		goto err;
	}

	if (ctx->pin) {
		ret = C_Login(ctx->session, CKU_USER, ctx->pin, strlen(ctx->pin));
		if (ret != CKR_USER_ALREADY_LOGGED_IN && ret != CKR_OK) {
			goto err;
		}
	}

	ret = C_GenerateRandom(ctx->session, (CK_BYTE_PTR)out, (CK_ULONG)outlen);
	if (ret != CKR_OK) {
		goto err;
	}

	if (ctx->session != CK_INVALID_HANDLE) {
		C_CloseSession(ctx->session);
		ctx->session = CK_INVALID_HANDLE;
	}
	ctx->slot_id = 0;
	if (ctx->pin) {
		free(ctx->pin);
	}

	return 1;

err:
	if (ctx->session != CK_INVALID_HANDLE) {
		C_CloseSession(ctx->session);
	}
	ctx->slot_id = 0;
	if (ctx->pin) {
		free(ctx->pin);
	}

	ctx->state = EVP_RAND_STATE_ERROR;
	return 0;
}

static int libckteec_rand_enable_locking(void *vctx)
{
	(void)(vctx);
	return 1;
}

static const OSSL_PARAM *libckteec_rand_gettable_ctx_params(void *vctx, void *provctx)
{
	(void)(vctx);
	(void)(provctx);

	static const OSSL_PARAM gettable_ctx_params[] = { OSSL_PARAM_int(OSSL_RAND_PARAM_STATE, NULL),
		                                          OSSL_PARAM_uint(OSSL_RAND_PARAM_STRENGTH, NULL),
		                                          OSSL_PARAM_size_t(OSSL_RAND_PARAM_MAX_REQUEST, NULL),
		                                          OSSL_PARAM_END };
	return gettable_ctx_params;
}

static int libckteec_rand_get_ctx_params(void *vctx, OSSL_PARAM params[])
{
	struct tee_trng_rand_ctx *ctx = (struct tee_trng_rand_ctx *)vctx;
	OSSL_PARAM *p;

	if ((p = OSSL_PARAM_locate(params, OSSL_RAND_PARAM_STATE)) != NULL && !OSSL_PARAM_set_int(p, ctx->state))
		return 0;
	if ((p = OSSL_PARAM_locate(params, OSSL_RAND_PARAM_STRENGTH)) != NULL && !OSSL_PARAM_set_uint(p, 256))
		return 0;
	if ((p = OSSL_PARAM_locate(params, OSSL_RAND_PARAM_MAX_REQUEST)) != NULL && !OSSL_PARAM_set_size_t(p, INT_MAX))
		return 0;
	return 1;
}

static const OSSL_DISPATCH tee_trng_rand_functions[] = {
	{ OSSL_FUNC_RAND_NEWCTX, (void (*)(void))libckteec_rand_newctx },
	{ OSSL_FUNC_RAND_FREECTX, (void (*)(void))libckteec_rand_freectx },
	{ OSSL_FUNC_RAND_INSTANTIATE, (void (*)(void))libckteec_rand_instantiate },
	{ OSSL_FUNC_RAND_UNINSTANTIATE, (void (*)(void))libckteec_rand_uninstantiate },
	{ OSSL_FUNC_RAND_GENERATE, (void (*)(void))libckteec_rand_generate },
	{ OSSL_FUNC_RAND_ENABLE_LOCKING, (void (*)(void))libckteec_rand_enable_locking },
	{ OSSL_FUNC_RAND_GETTABLE_CTX_PARAMS, (void (*)(void))libckteec_rand_gettable_ctx_params },
	{ OSSL_FUNC_RAND_GET_CTX_PARAMS, (void (*)(void))libckteec_rand_get_ctx_params },
	{ 0, NULL }
};

static const OSSL_ALGORITHM tee_trng_rand_algs[] = { { "CTR-DRBG", "provider=tee_trng", tee_trng_rand_functions, NULL },
	                                             { NULL, NULL, NULL, NULL } };

static void tee_trng_teardown(void *provctx)
{
	C_Finalize(NULL);
}

static const OSSL_ALGORITHM *tee_trng_query_operation(void *provctx, int operation_id, int *no_cache)
{
	(void)(provctx);

	*no_cache = 0;
	switch (operation_id) {
	case OSSL_OP_RAND:
		return tee_trng_rand_algs;
	default:
		return NULL;
	}
}

static const OSSL_PARAM *tee_trng_gettable_params(void *provctx)
{
	(void)(provctx);

	static const OSSL_PARAM provider_gettable_params[] = { OSSL_PARAM_utf8_ptr(OSSL_PROV_PARAM_NAME, NULL, 0),
		                                               OSSL_PARAM_utf8_ptr(OSSL_PROV_PARAM_VERSION, NULL, 0),
		                                               OSSL_PARAM_utf8_ptr(OSSL_PROV_PARAM_BUILDINFO, NULL, 0),
		                                               OSSL_PARAM_END };

	return provider_gettable_params;
}

static int tee_trng_get_params(OSSL_PARAM params[])
{
	OSSL_PARAM *p;

	p = OSSL_PARAM_locate(params, OSSL_PROV_PARAM_NAME);
	if (p != NULL && !OSSL_PARAM_set_utf8_ptr(p, "tee_trng")) {
		return 0;
	}

	p = OSSL_PARAM_locate(params, OSSL_PROV_PARAM_VERSION);
	if (p != NULL && !OSSL_PARAM_set_utf8_ptr(p, "1.0")) {
		return 0;
	}

	p = OSSL_PARAM_locate(params, OSSL_PROV_PARAM_BUILDINFO);
	if (p != NULL && !OSSL_PARAM_set_utf8_ptr(p, "TEE TRNG Provider Build")) {
		return 0;
	}

	return 1;
}

static const OSSL_DISPATCH tee_trng_dispatch_table[] = {
	{ OSSL_FUNC_PROVIDER_TEARDOWN, (void (*)(void))tee_trng_teardown },
	{ OSSL_FUNC_PROVIDER_QUERY_OPERATION, (void (*)(void))tee_trng_query_operation },
	{ OSSL_FUNC_PROVIDER_GETTABLE_PARAMS, (void (*)(void))tee_trng_gettable_params },
	{ OSSL_FUNC_PROVIDER_GET_PARAMS, (void (*)(void))tee_trng_get_params },
	{ 0, NULL }
};

int OSSL_provider_init(const OSSL_CORE_HANDLE *handle, const OSSL_DISPATCH *in, const OSSL_DISPATCH **out,
                       void **provctx)
{
	(void)(handle);
	(void)(in);

	*provctx = NULL;
	*out = tee_trng_dispatch_table;

	CK_RV ret = C_Initialize(NULL);
	if (ret != CKR_OK && ret != CKR_CRYPTOKI_ALREADY_INITIALIZED) {
		return 0;
	}

	return 1;
}