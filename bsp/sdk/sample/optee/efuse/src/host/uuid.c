/*
 * Copyright Augentix Inc. Proprietary and confidential.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <tee_client_api.h>
#include <efuse.h>

static TEEC_Result open_sess(TEEC_Context *ctx, TEEC_Session *sess)
{
	TEEC_UUID uuid = EFUSE_PTA_UUID;
	uint32_t err_origin;
	TEEC_Result res;

	res = TEEC_InitializeContext(NULL, ctx);
	if (res != TEEC_SUCCESS)
		return res;

	res = TEEC_OpenSession(ctx, sess, &uuid, TEEC_LOGIN_PUBLIC, NULL, NULL, &err_origin);
	if (res != TEEC_SUCCESS) {
		TEEC_FinalizeContext(ctx);
		return res;
	}

	return res;
}

static TEEC_Result uuid_read(void)
{
	TEEC_Context ctx = {};
	TEEC_Session sess = {};
	TEEC_Operation op = {};
	uint32_t err_origin;
	TEEC_Result res;

	res = open_sess(&ctx, &sess);
	if (res != TEEC_SUCCESS)
		return res;

	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_OUTPUT, TEEC_VALUE_OUTPUT, TEEC_NONE, TEEC_NONE);

	res = TEEC_InvokeCommand(&sess, PTA_CMD_EB_OTP_GET, &op, &err_origin);

	TEEC_CloseSession(&sess);
	TEEC_FinalizeContext(&ctx);

	if (res != TEEC_SUCCESS) {
		printf("[FAIL] uuid read (0x%x)\n", res);
		return res;
	}

	printf("[OK] %08x-%08x-%08x-%08x\n", op.params[0].value.a, op.params[0].value.b, op.params[1].value.a,
	       op.params[1].value.b);

	return res;
}

static TEEC_Result uuid_write(uint32_t d0, uint32_t d1, uint32_t d2, uint32_t d3)
{
	TEEC_Context ctx = {};
	TEEC_Session sess = {};
	TEEC_Operation op = {};
	uint32_t err_origin;
	TEEC_Result res;

	res = open_sess(&ctx, &sess);
	if (res != TEEC_SUCCESS)
		return res;

	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_VALUE_INPUT, TEEC_NONE, TEEC_NONE);
	op.params[0].value.a = d0;
	op.params[0].value.b = d1;
	op.params[1].value.a = d2;
	op.params[1].value.b = d3;

	res = TEEC_InvokeCommand(&sess, PTA_CMD_EB_OTP_SET, &op, &err_origin);

	TEEC_CloseSession(&sess);
	TEEC_FinalizeContext(&ctx);

	if (res != TEEC_SUCCESS)
		printf("[FAIL] uuid write (0x%x)\n", res);
	else
		printf("[OK] uuid write\n");

	return res;
}

static TEEC_Result secure_check(void)
{
	TEEC_Context ctx = {};
	TEEC_Session sess = {};
	TEEC_Operation op = {};
	uint32_t err_origin;
	TEEC_Result res;

	res = open_sess(&ctx, &sess);
	if (res != TEEC_SUCCESS)
		return res;

	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_OUTPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);

	res = TEEC_InvokeCommand(&sess, PTA_CMD_EB_PROG_CHECK, &op, &err_origin);

	TEEC_CloseSession(&sess);
	TEEC_FinalizeContext(&ctx);

	if (res != TEEC_SUCCESS) {
		printf("[FAIL] secure check (0x%x)\n", res);
		return res;
	}

	printf("[OK] secure_enable = %u\n", op.params[0].value.a);

	return res;
}

static void usage(const char *prog)
{
	printf("Usage:\n");
	printf("  %s read                         Read UUID(DeviceID) from efuse\n", prog);
	printf("  %s write <d0> <d1> <d2> <d3>    Write HUK to efuse(the four inputs are no matter)\n", prog);
	printf("  %s check                        Check secure_enable status\n", prog);
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		usage(argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "read") == 0) {
		return uuid_read();
	} else if (strcmp(argv[1], "check") == 0) {
		return secure_check();
	} else if (strcmp(argv[1], "write") == 0) {
		if (argc < 6) {
			fprintf(stderr, "Error: write requires 4 hex values\n");
			usage(argv[0]);
			return 1;
		}
		return uuid_write(strtoul(argv[2], NULL, 16), strtoul(argv[3], NULL, 16), strtoul(argv[4], NULL, 16),
		                  strtoul(argv[5], NULL, 16));
	} else {
		usage(argv[0]);
		return 1;
	}
}
