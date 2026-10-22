/*
 * Copyright (c) 2017, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* OP-TEE TEE client API (built by optee_client) */
#include <tee_client_api.h>

/* TA API: UUID and command IDs */
#include <user_auth_agtx_ta.h>

/* TEE resources */
struct test_ctx {
	TEEC_Context ctx;
	TEEC_Session sess;
};

void prepare_tee_session(struct test_ctx *ctx)
{
	TEEC_UUID uuid = TA_USER_AUTH_AGTX_UUID;
	uint32_t origin;
	TEEC_Result res;

	/* Initialize a context connecting us to the TEE */
	res = TEEC_InitializeContext(NULL, &ctx->ctx);
	if (res != TEEC_SUCCESS)
		errx(1, "TEEC_InitializeContext failed with code 0x%x", res);

	/* Open a session with the TA */
	res = TEEC_OpenSession(&ctx->ctx, &ctx->sess, &uuid, TEEC_LOGIN_PUBLIC, NULL, NULL, &origin);
	if (res != TEEC_SUCCESS)
		errx(1, "TEEC_Opensession failed with code 0x%x origin 0x%x", res, origin);
}

void terminate_tee_session(struct test_ctx *ctx)
{
	TEEC_CloseSession(&ctx->sess);
	TEEC_FinalizeContext(&ctx->ctx);
}

TEEC_Result check_secure_object(struct test_ctx *ctx, char *id)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	memset(&op, 0, sizeof(op));
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);

	op.params[0].tmpref.buffer = id;
	op.params[0].tmpref.size = strlen(id);

	res = TEEC_InvokeCommand(&ctx->sess, TA_USER_AUTH_AGTX_CMD_CHECK, &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
	case TEEC_ERROR_ITEM_NOT_FOUND:
		break;
	default:
		printf("Command CHECK failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

TEEC_Result reset_secure_object(struct test_ctx *ctx, char *id, char *username, char *password)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	memset(&op, 0, sizeof(op));
	op.paramTypes =
	        TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE);

	op.params[0].tmpref.buffer = id;
	op.params[0].tmpref.size = strlen(id);

	op.params[1].tmpref.buffer = username;
	op.params[1].tmpref.size = strlen(username);

	op.params[2].tmpref.buffer = password;
	op.params[2].tmpref.size = strlen(password);

	res = TEEC_InvokeCommand(&ctx->sess, TA_USER_AUTH_AGTX_CMD_RESET, &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
	case TEEC_ERROR_ITEM_NOT_FOUND:
		break;
	default:
		printf("Command RESET failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

TEEC_Result add_user_secure_object(struct test_ctx *ctx, char *id, char *username, char *password)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	memset(&op, 0, sizeof(op));
	op.paramTypes =
	        TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE);

	op.params[0].tmpref.buffer = id;
	op.params[0].tmpref.size = strlen(id);

	op.params[1].tmpref.buffer = username;
	op.params[1].tmpref.size = strlen(username);

	op.params[2].tmpref.buffer = password;
	op.params[2].tmpref.size = strlen(password);

	res = TEEC_InvokeCommand(&ctx->sess, TA_USER_AUTH_AGTX_CMD_ADD_USER, &op, &origin);
	switch (res) {
	case TEEC_SUCCESS:
		break;
	case TEEC_ERROR_ITEM_NOT_FOUND:
		break;
	default:
		printf("Command ADD_USER failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

TEEC_Result modify_user_secure_object(struct test_ctx *ctx, char *id, char *username, char *password,
                                      char *new_password)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	memset(&op, 0, sizeof(op));
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT,
	                                 TEEC_MEMREF_TEMP_INPUT);

	op.params[0].tmpref.buffer = id;
	op.params[0].tmpref.size = strlen(id);

	op.params[1].tmpref.buffer = username;
	op.params[1].tmpref.size = strlen(username);

	op.params[2].tmpref.buffer = password;
	op.params[2].tmpref.size = strlen(password);

	op.params[3].tmpref.buffer = new_password;
	op.params[3].tmpref.size = strlen(new_password);

	res = TEEC_InvokeCommand(&ctx->sess, TA_USER_AUTH_AGTX_CMD_MODIFY_USER, &op, &origin);
	switch (res) {
	case TEEC_SUCCESS:
		break;
	case TEEC_ERROR_ITEM_NOT_FOUND:
		break;
	default:
		printf("Command MODIFY_USER failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

TEEC_Result verify_user_secure_object(struct test_ctx *ctx, char *id, char *username, char *password)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	memset(&op, 0, sizeof(op));
	op.paramTypes =
	        TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE);

	op.params[0].tmpref.buffer = id;
	op.params[0].tmpref.size = strlen(id);

	op.params[1].tmpref.buffer = username;
	op.params[1].tmpref.size = strlen(username);

	op.params[2].tmpref.buffer = password;
	op.params[2].tmpref.size = strlen(password);

	res = TEEC_InvokeCommand(&ctx->sess, TA_USER_AUTH_AGTX_CMD_VERIFY_USER, &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
		break;
	default:
		printf("Command VERIFY_USER failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

TEEC_Result delete_user_secure_object(struct test_ctx *ctx, char *id, char *username, char *password)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	memset(&op, 0, sizeof(op));
	op.paramTypes =
	        TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE);

	op.params[0].tmpref.buffer = id;
	op.params[0].tmpref.size = strlen(id);

	op.params[1].tmpref.buffer = username;
	op.params[1].tmpref.size = strlen(username);

	op.params[2].tmpref.buffer = password;
	op.params[2].tmpref.size = strlen(password);

	res = TEEC_InvokeCommand(&ctx->sess, TA_USER_AUTH_AGTX_CMD_DELETE_USER, &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
		break;
	default:
		printf("Command DELETE_USER failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

int main(int argc, char *argv[])
{
	char *mode;
	char *object_id;
	char *username;
	char *password;
	char *new_password;
	struct test_ctx ctx;
	TEEC_Result res;

	if (argc < 3) {
		fprintf(stderr, "Usage:\n");
		fprintf(stderr, "  %s -check <object_id>\n", argv[0]);
		fprintf(stderr, "  %s -reset <object_id> <username> <password>\n", argv[0]);
		fprintf(stderr, "  %s -adduser <object_id> <username> <password>\n", argv[0]);
		fprintf(stderr, "  %s -modifyuser <object_id> <username> <password> <new password>\n", argv[0]);
		fprintf(stderr, "  %s -verifyuser <object_id> <username> <password>\n", argv[0]);
		fprintf(stderr, "  %s -deleteuser <object_id> <username> <password>\n", argv[0]);
		return 1;
	}

	mode = argv[1];
	object_id = argv[2];

	printf("Opening session with TEE\n");
	prepare_tee_session(&ctx);

	if (strcmp(mode, "-check") == 0) {
		if (argc != 3) {
			fprintf(stderr, "Usage: %s -check <object_id>\n", argv[0]);
			return 1;
		}

		res = check_secure_object(&ctx, object_id);
		if (res != TEEC_SUCCESS)
			errx(1, "No Object: 0x%x", res);

		printf("Object '%s' exists\n", object_id);
	} else if (strcmp(mode, "-reset") == 0) {
		if (argc != 5) {
			fprintf(stderr, "Usage: %s -reset <object_id> <username> <password>\n", argv[0]);
			return 1;
		}

		username = argv[3];
		password = argv[4];
		res = reset_secure_object(&ctx, object_id, username, password);
		if (res != TEEC_SUCCESS)
			errx(1, "Failed to reset object: 0x%x", res);

		printf("Successfully reset object '%s'\n", object_id);
	} else if (strcmp(mode, "-adduser") == 0) {
		if (argc != 5) {
			fprintf(stderr, "Usage: %s -adduser <object_id> <username> <password>\n", argv[0]);
			return 1;
		}

		username = argv[3];
		password = argv[4];
		res = add_user_secure_object(&ctx, object_id, username, password);
		if (res != TEEC_SUCCESS)
			errx(1, "Failed to add user to object: 0x%x", res);

		printf("Successfully added user %s to object '%s'\n", username, object_id);
	} else if (strcmp(mode, "-modifyuser") == 0) {
		if (argc != 6) {
			fprintf(stderr, "Usage: %s -modifyuser <object_id> <username> <password> <new password>\n",
			        argv[0]);
			return 1;
		}

		username = argv[3];
		password = argv[4];
		new_password = argv[5];
		res = modify_user_secure_object(&ctx, object_id, username, password, new_password);
		if (res != TEEC_SUCCESS)
			errx(1, "Failed to modify user to object: 0x%x", res);

		printf("Successfully modified user %s to object '%s'\n", username, object_id);
	} else if (strcmp(mode, "-verifyuser") == 0) {
		if (argc != 5) {
			fprintf(stderr, "Usage: %s -verifyuser <object_id> <username> <password>\n", argv[0]);
			return 1;
		}

		username = argv[3];
		password = argv[4];
		res = verify_user_secure_object(&ctx, object_id, username, password);
		if (res != TEEC_SUCCESS)
			errx(1, "Invalid username and password");

		printf("Valid user %s in object '%s'\n", username, object_id);
	} else if (strcmp(mode, "-deleteuser") == 0) {
		if (argc != 5) {
			fprintf(stderr, "Usage: %s -deleteuser <object_id> <username> <password>\n", argv[0]);
			return 1;
		}

		username = argv[3];
		password = argv[4];
		res = delete_user_secure_object(&ctx, object_id, username, password);
		if (res != TEEC_SUCCESS)
			errx(1, "Invalid username and password");

		printf("Successfully deleted user %s in object '%s'\n", username, object_id);
	} else {
		errx(1, "Invalid mode: %s", mode);
	}

	terminate_tee_session(&ctx);
	return 0;
}
