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
#include <secure_storage_agtx_ta.h>

#define MAX_BUF_SIZE 1024

/* TEE resources */
struct test_ctx {
	TEEC_Context ctx;
	TEEC_Session sess;
};

void prepare_tee_session(struct test_ctx *ctx)
{
	TEEC_UUID uuid = TA_SECURE_STORAGE_AGTX_UUID;
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

TEEC_Result read_secure_object(struct test_ctx *ctx, char *id, char **data, size_t *data_len)
{
	TEEC_Operation op;
	uint32_t origin;
	size_t id_len = strlen(id);
	TEEC_Result res;

	/* Step 1: Get object size */
	memset(&op, 0, sizeof(op));
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_VALUE_OUTPUT, TEEC_NONE, TEEC_NONE);

	op.params[0].tmpref.buffer = (char *)id;
	op.params[0].tmpref.size = id_len;

	res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_AGTX_CMD_GET_SIZE, &op, &origin);
	if (res != TEEC_SUCCESS) {
		printf("GET_SIZE failed: 0x%x\n", res);
		return res;
	}

	*data_len = op.params[1].value.a;
	*data = malloc(*data_len);
	if (!*data)
		return TEEC_ERROR_OUT_OF_MEMORY;

	/* Step 2: Read object */
	memset(&op, 0, sizeof(op));
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);

	op.params[0].tmpref.buffer = (char *)id;
	op.params[0].tmpref.size = id_len;

	op.params[1].tmpref.buffer = *data;
	op.params[1].tmpref.size = *data_len;

	res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_AGTX_CMD_READ_RAW, &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
		*data_len = op.params[1].tmpref.size;
		break;
	case TEEC_ERROR_SHORT_BUFFER:
	case TEEC_ERROR_ITEM_NOT_FOUND:
	default:
		printf("Command READ_RAW failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

TEEC_Result write_secure_object(struct test_ctx *ctx, char *id, char *data, size_t data_len)
{
	TEEC_Operation op;
	uint32_t origin;
	size_t id_len = strlen(id);
	TEEC_Result res;

	memset(&op, 0, sizeof(op));
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE);

	op.params[0].tmpref.buffer = (char *)id;
	op.params[0].tmpref.size = id_len;

	op.params[1].tmpref.buffer = data;
	op.params[1].tmpref.size = data_len;

	res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_AGTX_CMD_WRITE_RAW, &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
		break;
	default:
		printf("Command WRITE_RAW failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

TEEC_Result delete_secure_object(struct test_ctx *ctx, char *id)
{
	TEEC_Operation op;
	uint32_t origin;
	size_t id_len = strlen(id);
	TEEC_Result res;

	memset(&op, 0, sizeof(op));
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);

	op.params[0].tmpref.buffer = (char *)id;
	op.params[0].tmpref.size = id_len;

	res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_AGTX_CMD_DELETE, &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
		break;
	case TEEC_ERROR_ITEM_NOT_FOUND:
	default:
		printf("Command DELETE failed: 0x%x / %u\n", res, origin);
	}

	return res;
}

int main(int argc, char *argv[])
{
	char *mode;
	char *object_id;
	char *input_str;
	char *file_path;
	char *buffer = NULL;
	size_t size = 0;
	struct test_ctx ctx;
	TEEC_Result res;

	if (argc < 3) {
		fprintf(stderr, "Usage:\n");
		fprintf(stderr, "  %s -readstr <object_id>\n", argv[0]);
		fprintf(stderr, "  %s -writestr <object_id> <input_str>\n", argv[0]);
		fprintf(stderr, "  %s -readfile <object_id> <file_path>\n", argv[0]);
		fprintf(stderr, "  %s -writefile <object_id> <file_path>\n", argv[0]);
		fprintf(stderr, "  %s -delete <object_id>\n", argv[0]);
		return 1;
	}

	mode = argv[1];
	object_id = argv[2];

	printf("Opening session with TEE\n");
	prepare_tee_session(&ctx);

	if (strcmp(mode, "-readstr") == 0) {
		if (argc != 3) {
			fprintf(stderr, "Usage: %s -readstr <object_id>\n", argv[0]);
			return 1;
		}

		res = read_secure_object(&ctx, object_id, &buffer, &size);
		if (res != TEEC_SUCCESS)
			errx(1, "Failed to read object: 0x%x", res);

		printf("Read object '%s': %.*s\n", object_id, (int)size, buffer);
		free(buffer);
	} else if (strcmp(mode, "-writestr") == 0) {
		if (argc != 4) {
			fprintf(stderr, "Usage: %s -writestr <object_id> <input_str>\n", argv[0]);
			return 1;
		}

		input_str = argv[3];
		res = write_secure_object(&ctx, object_id, input_str, strlen(input_str));
		if (res != TEEC_SUCCESS)
			errx(1, "Failed to write object: 0x%x", res);

		printf("Successfully wrote string to object '%s'\n", object_id);
	} else if (strcmp(mode, "-readfile") == 0) {
		if (argc != 4) {
			fprintf(stderr, "Usage: %s -readfile <object_id> <file_path>\n", argv[0]);
			return 1;
		}

		file_path = argv[3];
		res = read_secure_object(&ctx, object_id, &buffer, &size);
		if (res != TEEC_SUCCESS)
			errx(1, "Failed to read object: 0x%x", res);

		FILE *fp = fopen(file_path, "wb");
		if (!fp)
			err(1, "Failed to open file for writing: %s", file_path);

		fwrite(buffer, 1, size, fp);
		fclose(fp);
		free(buffer);

		printf("Successfully saved object '%s' to file '%s'\n", object_id, file_path);
	} else if (strcmp(mode, "-writefile") == 0) {
		if (argc != 4) {
			fprintf(stderr, "Usage: %s -writefile <object_id> <file_path>\n", argv[0]);
			return 1;
		}

		file_path = argv[3];
		FILE *fp = fopen(file_path, "rb");
		if (!fp)
			err(1, "Failed to open file for reading: %s", file_path);

		fseek(fp, 0, SEEK_END);
		size = ftell(fp);
		rewind(fp);

		buffer = malloc(size);
		if (!buffer)
			err(1, "Memory allocation failed");

		if (fread(buffer, 1, size, fp) != size)
			err(1, "Failed to read file content: %s", file_path);
		fclose(fp);

		res = write_secure_object(&ctx, object_id, buffer, size);
		free(buffer);

		if (res != TEEC_SUCCESS)
			errx(1, "Failed to write object: 0x%x", res);

		printf("Successfully wrote file '%s' (%zu bytes) to object '%s'\n", file_path, size, object_id);
	} else if (strcmp(mode, "-delete") == 0) {
		if (argc != 3) {
			fprintf(stderr, "Usage: %s -delete <object_id>\n", argv[0]);
			return 1;
		}

		res = delete_secure_object(&ctx, object_id);
		if (res != TEEC_SUCCESS)
			errx(1, "Failed to delete object: 0x%x", res);

		printf("Successfully deleted object '%s'\n", object_id);
	} else {
		errx(1, "Invalid mode: %s", mode);
	}

	terminate_tee_session(&ctx);
	return 0;
}
