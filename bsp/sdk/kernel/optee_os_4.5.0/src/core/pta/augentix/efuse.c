/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <stdbool.h>
#include <io.h>
#include <kernel/pseudo_ta.h>
#include <kernel/thread_arch.h>
#include <kernel/tee_common_otp.h>
#include <string_ext.h>
#include <sm/optee_smc.h>
#include <tee_api_defines.h>
#include <trace.h>
#include <rng_support.h>
#include <tee/tee_cryp_utl.h>

#define EFUSE_PTA_UUID                                                 \
	{                                                              \
		0xb3514255, 0x08bc, 0x4643,                            \
		{                                                      \
			0xb2, 0x5a, 0x57, 0x8e, 0x0d, 0x6e, 0x99, 0x48 \
		}                                                      \
	}

#define EFUSE_PTA_NAME "efuse.pta"

#define AUGENTIX_SIP_EB_PROG_CHECK 0x82010004
#define AUGENTIX_SIP_EB_OTP_SET 0x82010007
#define AUGENTIX_SIP_EB_OTP_GET 0x82010008
#define AUGENTIX_SIP_EB_CLK_ENABLE 0x8201000B
#define AUGENTIX_SIP_EB_CLK_DISABLE 0x8201000C

#define OTP_TYPE_READ_USER 0x1
#define OTP_TYPE_WRITE_USER 0x2

#define PTA_CMD_EB_OTP_SET 0
#define PTA_CMD_EB_OTP_GET 1
#define PTA_CMD_EB_PROG_CHECK 2
#define DEVICE_ID_LEN (16)

static bool eb_huk_writed = false;

/* if HUK is not all-zero return TEE_SUCCESS*/
TEE_Result check_huk_nonzero(struct tee_hw_unique_key *pthuk)
{
	const struct tee_hw_unique_key zerohuk = {};

	if (consttime_memcmp(pthuk->data, zerohuk.data, sizeof(zerohuk.data)) == 0) {
		EMSG("all zero");
		return TEE_ERROR_SECURITY;
	}

	return TEE_SUCCESS;
}

static void sip_smc_call(uint32_t fid, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5,
                         struct thread_smc_args *result)
{
	struct thread_smc_args args = {
		.a0 = fid,
		.a1 = a1,
		.a2 = a2,
		.a3 = a3,
		.a4 = a4,
		.a5 = a5,
	};

	thread_smccc(&args);
	*result = args;
}

bool check_secure_enable_ready(void)
{
	struct thread_smc_args res = {};

	sip_smc_call(AUGENTIX_SIP_EB_PROG_CHECK, 0, 0, 0, 0, 0, &res);

	DMSG("SecureEnable: %d", res.a1);

	if (res.a1)
		return true;

	return false;
}

static TEE_Result eb_pta_otp_get(uint32_t ptypes, TEE_Param params[TEE_NUM_PARAMS])
{
	struct thread_smc_args res = {};

	if (ptypes != TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_OUTPUT, TEE_PARAM_TYPE_VALUE_OUTPUT, TEE_PARAM_TYPE_NONE,
	                              TEE_PARAM_TYPE_NONE))
		return TEE_ERROR_BAD_PARAMETERS;

	sip_smc_call(AUGENTIX_SIP_EB_OTP_GET, OTP_TYPE_READ_USER, 0, 0, 0, 0, &res);

	params[0].value.a = res.a0;
	params[0].value.b = res.a1;
	params[1].value.a = res.a2;
	params[1].value.b = res.a3;

	return TEE_SUCCESS;
}

static TEE_Result eb_pta_uuid_get(uint32_t ptypes, TEE_Param params[TEE_NUM_PARAMS])
{
	TEE_Result rc = TEE_SUCCESS;
	struct thread_smc_args res = {};
	struct tee_hw_unique_key huk = { };
	uint8_t hash256[TEE_SHA256_HASH_SIZE] = { 0 };
	uint8_t deviceid[16] = { 0 };

	if (ptypes != TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_OUTPUT, TEE_PARAM_TYPE_VALUE_OUTPUT, TEE_PARAM_TYPE_NONE,
	                              TEE_PARAM_TYPE_NONE))
		return TEE_ERROR_BAD_PARAMETERS;

	rc = tee_otp_get_hw_unique_key(&huk);
	if (rc && rc != TEE_ERROR_NO_DATA)
		goto out;

	rc = check_huk_nonzero(&huk);
	if (rc) {
		EMSG("failed to get ID because HUK all-zero");
		goto out;
	}

	rc = tee_hash_createdigest(TEE_ALG_SHA256, huk.data, sizeof(huk.data), hash256, sizeof(hash256));
	if (rc)
		goto out;

	memcpy(deviceid, hash256, DEVICE_ID_LEN);

	params[0].value.a = get_unaligned_le32(&deviceid[0]);
	params[0].value.b = get_unaligned_le32(&deviceid[4]);
	params[1].value.a = get_unaligned_le32(&deviceid[8]);
	params[1].value.b = get_unaligned_le32(&deviceid[12]);

	DMSG("Get UUID (Device ID): %08" PRIx32 "%08" PRIx32 "%08" PRIx32 "%08" PRIx32, params[0].value.a, params[0].value.b, params[1].value.a, params[1].value.b);

out:
	memzero_explicit(&huk, sizeof(huk));
	memzero_explicit(hash256, sizeof(hash256));

	return rc;
}

static TEE_Result eb_pta_otp_set(uint32_t ptypes, TEE_Param params[TEE_NUM_PARAMS])
{
	struct thread_smc_args res = {};

	if (ptypes != TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_INPUT, TEE_PARAM_TYPE_VALUE_INPUT, TEE_PARAM_TYPE_NONE,
	                              TEE_PARAM_TYPE_NONE))
		return TEE_ERROR_BAD_PARAMETERS;

	sip_smc_call(AUGENTIX_SIP_EB_OTP_SET, OTP_TYPE_WRITE_USER, params[0].value.a, params[0].value.b,
	             params[1].value.a, params[1].value.b, &res);

	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		EMSG("otp_set failed: 0x%lx", res.a0);
		return TEE_ERROR_GENERIC;
	}

	return TEE_SUCCESS;
}

static TEE_Result eb_pta_huk_set(uint32_t ptypes, TEE_Param params[TEE_NUM_PARAMS])
{
	TEE_Result rc = TEE_SUCCESS;
	struct thread_smc_args res = {};
	struct tee_hw_unique_key huk = { };
	struct tee_hw_unique_key huk_rng = { };

	if (ptypes != TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_INPUT, TEE_PARAM_TYPE_VALUE_INPUT, TEE_PARAM_TYPE_NONE,
	                              TEE_PARAM_TYPE_NONE))
		return TEE_ERROR_BAD_PARAMETERS;

	if (eb_huk_writed) {
		EMSG("not allow to set HUK twice a time");
		rc = TEE_ERROR_ACCESS_CONFLICT;
		goto out;
	}

	if (!check_secure_enable_ready()) {
		EMSG("not allow to set HUK because secure-enable is off");
		rc = TEE_ERROR_ACCESS_DENIED;
		goto out;
	}

	rc = tee_otp_get_hw_unique_key(&huk);
	if (rc && rc != TEE_ERROR_NO_DATA)
		goto out;

	rc = check_huk_nonzero(&huk);
	if (!rc) {
		EMSG("failed to write because the value is non-zero");
		rc = TEE_ERROR_ACCESS_CONFLICT;
		goto out;
	}

	rc = hw_get_random_bytes(huk_rng.data, sizeof(huk_rng.data));
	if (rc)
		goto out;

	rc = check_huk_nonzero(&huk_rng);
	if (rc) {
		EMSG("get an all-zero random number form TRNG, please re-run again");
		goto out;
	}

	params[0].value.a = get_unaligned_le32(&huk_rng.data[0]);
	params[0].value.b = get_unaligned_le32(&huk_rng.data[4]);
	params[1].value.a = get_unaligned_le32(&huk_rng.data[8]);
	params[1].value.b = get_unaligned_le32(&huk_rng.data[12]);

	DMSG("Set HUK words: %08" PRIx32 "%08" PRIx32 "%08" PRIx32 "%08" PRIx32, params[0].value.a, params[0].value.b, params[1].value.a, params[1].value.b);

	sip_smc_call(AUGENTIX_SIP_EB_OTP_SET, OTP_TYPE_WRITE_USER, params[0].value.a, params[0].value.b,
	             params[1].value.a, params[1].value.b, &res);

	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		EMSG("otp_set failed: 0x%lx", res.a0);
		rc = TEE_ERROR_GENERIC;
		goto out;
	} else {
		DMSG("otp_set OK: 0x%lx", res.a0);
		eb_huk_writed = true;
	}

out:
	memzero_explicit(&huk, sizeof(huk));
	memzero_explicit(&huk_rng, sizeof(huk_rng));

	return rc;
}

static TEE_Result eb_pta_prog_check(uint32_t ptypes, TEE_Param params[TEE_NUM_PARAMS])
{
	struct thread_smc_args res = {};

	if (ptypes !=
	    TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_OUTPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE))
		return TEE_ERROR_BAD_PARAMETERS;

	sip_smc_call(AUGENTIX_SIP_EB_PROG_CHECK, 0, 0, 0, 0, 0, &res);

	params[0].value.a = res.a1;

	return TEE_SUCCESS;
}

static bool g_secure_enabled;
static bool g_huk_programmed;

static TEE_Result pta_efuse_init(void)
{
	struct thread_smc_args res = {};

	sip_smc_call(AUGENTIX_SIP_EB_CLK_ENABLE, 0, 0, 0, 0, 0, &res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		EMSG("efuse clk_enable failed: 0x%lx", res.a0);
		return TEE_ERROR_GENERIC;
	}

	sip_smc_call(AUGENTIX_SIP_EB_PROG_CHECK, 0, 0, 0, 0, 0, &res);
	g_secure_enabled = (res.a1 != 0);

	sip_smc_call(AUGENTIX_SIP_EB_OTP_GET, OTP_TYPE_READ_USER, 0, 0, 0, 0, &res);
	g_huk_programmed = (res.a0 || res.a1 || res.a2 || res.a3);

	if (g_secure_enabled && !g_huk_programmed)
		EMSG("secure_enable=1 but HUK not programmed");

	return TEE_SUCCESS;
}
driver_init_late(pta_efuse_init);

static TEE_Result close_session(uint32_t ptypes __unused,
					TEE_Param par[TEE_NUM_PARAMS] __unused,
					void **session __unused)
{
	struct thread_smc_args res = {};

	sip_smc_call(AUGENTIX_SIP_EB_CLK_DISABLE, 0, 0, 0, 0, 0, &res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		EMSG("efuse clk_disable failed: 0x%lx", res.a0);
		return TEE_ERROR_GENERIC;
	}

	return TEE_SUCCESS;
}

static TEE_Result open_session(uint32_t ptypes __unused,
					TEE_Param par[TEE_NUM_PARAMS] __unused,
					void **session __unused)
{
	struct thread_smc_args res = {};

	sip_smc_call(AUGENTIX_SIP_EB_CLK_ENABLE, 0, 0, 0, 0, 0, &res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		EMSG("efuse clk_enable failed: 0x%lx", res.a0);
		return TEE_ERROR_GENERIC;
	}

	return TEE_SUCCESS;
}

static TEE_Result invoke_cmd(void *sess __unused, uint32_t cmd, uint32_t ptypes, TEE_Param params[TEE_NUM_PARAMS])
{
	switch (cmd) {
	case PTA_CMD_EB_OTP_SET:
		return eb_pta_huk_set(ptypes, params);
	case PTA_CMD_EB_OTP_GET:
		return eb_pta_uuid_get(ptypes, params);
	case PTA_CMD_EB_PROG_CHECK:
		return eb_pta_prog_check(ptypes, params);
	default:
		return TEE_ERROR_NOT_IMPLEMENTED;
	}
}

pseudo_ta_register(.uuid = EFUSE_PTA_UUID, .name = EFUSE_PTA_NAME, .flags = PTA_DEFAULT_FLAGS,
				   .open_session_entry_point = open_session,
				   .close_session_entry_point = close_session,
                   .invoke_command_entry_point = invoke_cmd);
