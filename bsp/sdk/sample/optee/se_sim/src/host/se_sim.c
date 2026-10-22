#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <openssl/sha.h>

#include <tee_client_api.h>

#include <se_sim.h>

struct cmd_info {
	uint32_t cmd;
	char *data_path;
	char *cipher_path;
	char *mac_path;
	char *out_path;
	char *usr_path;
	char *pwd_path;
	bool out_op;
};
static struct cmd_info cmd_info = {};

#define AES_BLOCK_SIZE 16
#define HASH_SZ 32
#define HMAC_SZ 32
#define HKDF_OKM_SZ 32
#define VALID_USR_PATH "/usrdata/valid_username.bin"
#define VALID_PWD_PATH "/usrdata/valid_password.bin"

static TEEC_Result read_file(const char *path, uint8_t **out_buf, size_t *out_size, bool aligned)
{
	FILE *fp = NULL;
	long file_size = 0;
	size_t read_size = 0;
	uint8_t *buf = NULL;
	size_t padded_size = 0;
	size_t pad_len = 0;

	if (!path || !out_buf || !out_size)
		return TEEC_ERROR_BAD_PARAMETERS;

    	fp = fopen(path, "rb");
    	if (!fp) {
        	perror("fopen");
        	return TEEC_ERROR_ITEM_NOT_FOUND;
    	}

    	/* Get file size */
    	if (fseek(fp, 0, SEEK_END) != 0) {
        	fclose(fp);
        	return TEEC_ERROR_GENERIC;
    	}

    	file_size = ftell(fp);
    	if (file_size < 0) {
        	fclose(fp);
        	return TEEC_ERROR_GENERIC;
    	}
    	rewind(fp);

	if (aligned) {
		/* Calculate padding */
		pad_len = AES_BLOCK_SIZE - (file_size % AES_BLOCK_SIZE);
		padded_size = file_size + pad_len;
	} else {
		pad_len = 0;
		padded_size = file_size;
	}

	/* Allocate buffer */
	buf = malloc(padded_size);
	if (!buf) {
		fclose(fp);
		return TEEC_ERROR_OUT_OF_MEMORY;
	}
	memset(buf, 0x00, padded_size);

	/* Read file */
	read_size = fread(buf, 1, file_size, fp);
	fclose(fp);

	if (read_size != (size_t)file_size) {
        	free(buf);
        	return TEEC_ERROR_GENERIC;
    	}

	if (aligned) {
		/* PKCS#7 padding */
		for (size_t i = 0; i < pad_len; i++) {
			buf[file_size + i] = (uint8_t)pad_len;
		}
	}

	*out_buf = buf;
	*out_size = padded_size;

	return TEEC_SUCCESS;
}

static TEEC_Result write_file(const char *path, const uint8_t *buf, size_t sz)
{
    	FILE *fp = NULL;
	size_t written = 0;

	if (!path || !buf || sz == 0)
		return TEEC_ERROR_BAD_PARAMETERS;

    	fp = fopen(path, "wb");
    	if (!fp) {
        	perror("fopen");
        	return TEEC_ERROR_ACCESS_DENIED;
    	}

    	written = fwrite(buf, 1, sz, fp);
    	fclose(fp);

    	if (written != sz) {
        	return TEEC_ERROR_GENERIC;
    	}

    	return TEEC_SUCCESS;
}

static TEEC_Result compare_OKM(const char *valid_path, const uint8_t *okm)
{
	TEEC_Result res = TEEC_ERROR_GENERIC;
	uint8_t *buf = NULL;
	size_t buf_sz = 0;

	res = read_file(valid_path, &buf, &buf_sz, false);
	if (res != TEEC_SUCCESS) {
		printf("[se_sim] read_file failed\n");
		goto cleanup;
	}

	if (buf_sz != HKDF_OKM_SZ) {
		res = TEEC_ERROR_GENERIC;
		printf("[se_sim] buf size error\n");
		goto cleanup;
	}

	for (int i = 0; i < HKDF_OKM_SZ; i++) {
		if (okm[i] != buf[i]) {
			res = TEEC_ERROR_SECURITY;
			printf("[se_sim] data error\n");
			goto cleanup;
		}
	}

	res = TEEC_SUCCESS;

cleanup:
	if (buf)
		free(buf);
	return res;
}

static TEEC_Result open_sess(TEEC_Context *ctx, TEEC_Session *sess)
{
	TEEC_UUID uuid = SE_SIM_UUID;
	TEEC_Result res = TEEC_SUCCESS;
	uint32_t err_origin = 0;

	/* Initialize a context connecting us to the TEE */
	res = TEEC_InitializeContext(NULL, ctx);
	if (res != TEEC_SUCCESS) {
		printf("[se_sim] TEEC_InitializeContext failed with code 0x%x\n", res);
		return res;
	}

	/* Open a session to the "se_sim" PTA */
	res = TEEC_OpenSession(ctx, sess, &uuid, TEEC_LOGIN_PUBLIC, NULL, NULL, &err_origin);
	if (res != TEEC_SUCCESS) {
		printf("[se_sim] TEEC_Opensession failed with code 0x%x origin 0x%x\n", res, err_origin);
		TEEC_FinalizeContext(ctx);
		return res;
	}

	return res;
}

static TEEC_Result data_enc_aes_ecb_256_no_pad(uint8_t *data, uint8_t *mac, uint8_t *cipher, size_t data_sz, size_t mac_sz, size_t cipher_sz)
{
	TEEC_Result res = TEEC_ERROR_GENERIC;
	TEEC_Context ctx = {};
	TEEC_Session sess = {};
	TEEC_Operation op = {};
	uint32_t origin = 0;

	/* Open session */
	res = open_sess(&ctx, &sess);
	if (res != TEEC_SUCCESS)
		return res;

	/* Clear the TEEC_Operation struct */
	memset(&op, 0, sizeof(op));

	/* Set parameters */
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
	op.params[0].tmpref.buffer = data;
	op.params[0].tmpref.size = data_sz;
	op.params[1].tmpref.buffer = cipher;
	op.params[1].tmpref.size = cipher_sz;

	/* Invoke command */
	res = TEEC_InvokeCommand(&sess, PTA_CMD_DATA_ENC_AES_ECB_256_NO_PAD, &op, &origin);
	if (res != TEEC_SUCCESS) { /* handle error */
		printf("[se_sim] TEEC_InvokeCommand failed with code 0x%x origin 0x%x\n", res, origin);
		TEEC_CloseSession(&sess);
		TEEC_FinalizeContext(&ctx);
		return res;
	}

	/* Clear the TEEC_Operation struct */
	memset(&op, 0, sizeof(op));

	/* Set parameters */
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
	op.params[0].tmpref.buffer = cipher;
	op.params[0].tmpref.size = cipher_sz;
	op.params[1].tmpref.buffer = mac;
	op.params[1].tmpref.size = mac_sz;

	/* Invoke command */
	res = TEEC_InvokeCommand(&sess, PTA_CMD_HMAC_SHA256, &op, &origin);
	if (res != TEEC_SUCCESS) { /* handle error */
		printf("[se_sim] TEEC_InvokeCommand failed with code 0x%x origin 0x%x\n", res, origin);
		TEEC_CloseSession(&sess);
		TEEC_FinalizeContext(&ctx);
		return res;
	}

	/* Close session */
	TEEC_CloseSession(&sess);
	TEEC_FinalizeContext(&ctx);

	return TEEC_SUCCESS;
}

static TEEC_Result data_dec_aes_ecb_256_no_pad(uint8_t *cipher, uint8_t *golden_mac, uint8_t *data, size_t cipher_sz,
                                               size_t mac_sz, size_t data_sz)
{
	TEEC_Result res = TEEC_ERROR_GENERIC;
	TEEC_Context ctx = {};
	TEEC_Session sess = {};
	TEEC_Operation op = {};
	uint32_t origin = 0;
	uint8_t mac[HMAC_SZ] = {};

	/* Open session */
	res = open_sess(&ctx, &sess);
	if (res != TEEC_SUCCESS)
		return res;

	/* Clear the TEEC_Operation struct */
	memset(&op, 0, sizeof(op));

	/* Set parameters */
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
	op.params[0].tmpref.buffer = cipher;
	op.params[0].tmpref.size = cipher_sz;
	op.params[1].tmpref.buffer = mac;
	op.params[1].tmpref.size = mac_sz;

	/* Invoke command */
	res = TEEC_InvokeCommand(&sess, PTA_CMD_HMAC_SHA256, &op, &origin);
	if (res != TEEC_SUCCESS) { /* handle error */
		printf("[se_sim] TEEC_InvokeCommand failed with code 0x%x origin 0x%x\n", res, origin);
		TEEC_CloseSession(&sess);
		TEEC_FinalizeContext(&ctx);
		return res;
	}

	/* MAC comparison */
	for (int i = 0; i < HMAC_SZ; i++) {
		if (mac[i] != golden_mac[i]) {
			printf("[se_sim] MAC comparison failed\n");
			TEEC_CloseSession(&sess);
			TEEC_FinalizeContext(&ctx);
			res = TEE_ERROR_MAC_INVALID;
			return res;
		}
	}

	/* Clear the TEEC_Operation struct */
	memset(&op, 0, sizeof(op));

	/* Set parameters */
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
	op.params[0].tmpref.buffer = cipher;
	op.params[0].tmpref.size = cipher_sz;
	op.params[1].tmpref.buffer = data;
	op.params[1].tmpref.size = data_sz;

	/* Invoke command */
	res = TEEC_InvokeCommand(&sess, PTA_CMD_DATA_DEC_AES_ECB_256_NO_PAD, &op, &origin);
	if (res != TEEC_SUCCESS) { /* handle error */
		printf("[se_sim] TEEC_InvokeCommand failed with code 0x%x origin 0x%x\n", res, origin);
		TEEC_CloseSession(&sess);
		TEEC_FinalizeContext(&ctx);
		return res;
	}

	/* Close session */
	TEEC_CloseSession(&sess);
	TEEC_FinalizeContext(&ctx);

	return TEEC_SUCCESS;
}

static TEEC_Result data_hkdf(uint8_t *data, uint8_t *okm, size_t data_sz, size_t okm_sz)
{
	TEEC_Result res = TEEC_ERROR_GENERIC;
	TEEC_Context ctx = {};
	TEEC_Session sess = {};
	TEEC_Operation op = {};
	uint32_t origin = 0;
	uint8_t hash[HASH_SZ] = {};

	/* Open session */
	res = open_sess(&ctx, &sess);
	if (res != TEEC_SUCCESS)
		return res;

	/* Generate data hash */
	SHA256((unsigned char *)data, data_sz, hash);

	/* Clear the TEEC_Operation struct */
	memset(&op, 0, sizeof(op));

	/* Set parameters */
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
	op.params[0].tmpref.buffer = hash;
	op.params[0].tmpref.size = HASH_SZ;
	op.params[1].tmpref.buffer = okm;
	op.params[1].tmpref.size = okm_sz;

	/* Invoke command */
	res = TEEC_InvokeCommand(&sess, PTA_CMD_DATA_HKDF, &op, &origin);
	if (res != TEEC_SUCCESS) { /* handle error */
		printf("[se_sim] TEEC_InvokeCommand failed with code 0x%x origin 0x%x\n", res, origin);
		TEEC_CloseSession(&sess);
		TEEC_FinalizeContext(&ctx);
		return res;
	}

	/* Close session */
	TEEC_CloseSession(&sess);
	TEEC_FinalizeContext(&ctx);

	return TEEC_SUCCESS;
}

static void help(const char *program_name)
{
	printf("[se_sim] Usage:\n");
	printf("[se_sim]   %s -d <path of data> -m <path of mac> -g <path of cipher>    Encrypt data\n", program_name);
	printf("[se_sim]   %s -t <path of cipher> -m <path of mac> -g <path of data>    Decrypt data\n", program_name);
	printf("[se_sim]   %s -u <path of username> -w <path of password> -o            Save usr and pwd\n",
	       program_name);
	printf("[se_sim]   %s -u <path of username> -w <path of password>               Verify usr and pwd\n",
	       program_name);
	printf("[se_sim]   %s -h                                                        Help message\n", program_name);
}

int main(int argc, char **argv)
{
	TEEC_Result res = TEEC_ERROR_GENERIC;
	int opt = 0;
	uint8_t *input = NULL;
	uint8_t *output = NULL;
	uint8_t *mac = NULL;
	size_t sz = 0;

	/* Parse input parameters */
	while ((opt = getopt(argc, argv, "d:t:m:g:u:w:oh")) != -1) {
		switch (opt) {
		case 'd':
			cmd_info.data_path = optarg;
			break;
		case 't':
			cmd_info.cipher_path = optarg;
			break;
		case 'm':
			cmd_info.mac_path = optarg;
			break;
		case 'g':
			cmd_info.out_path = optarg;
			break;
		case 'u':
			cmd_info.usr_path = optarg;
			break;
		case 'w':
			cmd_info.pwd_path = optarg;
			break;
		case 'o':
			cmd_info.out_op = true;
			break;
		case 'h':
		default:
			help(argv[0]);
			return 0;
		}
	}

	/* Determine the command */
	if (cmd_info.data_path && cmd_info.mac_path && cmd_info.out_path) {
		cmd_info.cmd = PTA_CMD_DATA_ENC_AES_ECB_256_NO_PAD;
	} else if (cmd_info.cipher_path && cmd_info.mac_path && cmd_info.out_path) {
		cmd_info.cmd = PTA_CMD_DATA_DEC_AES_ECB_256_NO_PAD;
	} else if (cmd_info.usr_path && cmd_info.pwd_path) {
		cmd_info.cmd = PTA_CMD_DATA_HKDF;
	}

	/* Switch by command */
	switch (cmd_info.cmd) {
	case PTA_CMD_DATA_ENC_AES_ECB_256_NO_PAD:
    		/* Read data file and align data with 16 bytes */
		res = read_file(cmd_info.data_path, &input, &sz, true);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] read_file failed: 0x%x\n", res);
			goto cleanup;
		}

		/* Allocate cipher buffer */
		output = malloc(sz);
		if (!output) {
			printf("[se_sim] malloc output failed\n");
			res = TEEC_ERROR_OUT_OF_MEMORY;
			goto cleanup;
		}
		memset(output, 0x00, sz);

		/* Allocate MAC buffer */
		mac = malloc(HMAC_SZ);
		if (!mac) {
			printf("[se_sim] malloc mac failed\n");
			res = TEEC_ERROR_OUT_OF_MEMORY;
			goto cleanup;
		}
		memset(mac, 0x00, HMAC_SZ);

		/* Encryption using AES ECB 256 no pad */
		res = data_enc_aes_ecb_256_no_pad(input, mac, output, sz, HMAC_SZ, sz);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] data_enc_aes_ecb_256_no_pad failed: 0x%x\n", res);
			goto cleanup;
		}

		/* Write cipher file */
		res = write_file(cmd_info.out_path, output, sz);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] write_file (output) failed: 0x%x\n", res);
			goto cleanup;
		}

    		/* Write MAC file */
    		res = write_file(cmd_info.mac_path, mac, HMAC_SZ);
    		if (res != TEEC_SUCCESS) {
			printf("[se_sim] write_file (MAC) failed: 0x%x\n", res);
			goto cleanup;
		}

		printf("[se_sim] encrypt data done\n");

		break;
	case PTA_CMD_DATA_DEC_AES_ECB_256_NO_PAD:
		/* Read MAC file */
		res = read_file(cmd_info.mac_path, &mac, &sz, false);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] read_file failed: 0x%x\n", res);
			goto cleanup;
		}
		if (sz != HMAC_SZ) {
			printf("[se_sim] invalid MAC size\n");
			res = TEE_ERROR_MAC_INVALID;
			goto cleanup;
		}

		/* Read cipher file */
		res = read_file(cmd_info.cipher_path, &input, &sz, false);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] read_file failed: 0x%x\n", res);
			goto cleanup;
		}

		/* Allocate data buffer */
		output = malloc(sz);
		if (!output) {
			printf("[se_sim] malloc output failed\n");
			res = TEEC_ERROR_OUT_OF_MEMORY;
			goto cleanup;
		}
		memset(output, 0x00, sz);

		/* Decryption using AES ECB 256 no pad */
		res = data_dec_aes_ecb_256_no_pad(input, mac, output, sz, HMAC_SZ, sz);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] data_dec_aes_ecb_256_no_pad failed: 0x%x\n", res);
			goto cleanup;
		}

		/* Write data file except padding */
		res = write_file(cmd_info.out_path, output, (sz - output[sz - 1]));
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] write_file (output) failed: 0x%x\n", res);
			goto cleanup;
		}

		printf("[se_sim] decrypt data done\n");

		break;
	case PTA_CMD_DATA_HKDF:
		/* Read username file */
		res = read_file(cmd_info.usr_path, &input, &sz, false);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] read_file failed: 0x%x\n", res);
			goto cleanup;
		}

		/* Allocate username OKM buffer */
		output = malloc(HKDF_OKM_SZ);
		if (!output) {
			printf("[se_sim] malloc output failed\n");
			res = TEEC_ERROR_OUT_OF_MEMORY;
			goto cleanup;
		}
		memset(output, 0x00, HKDF_OKM_SZ);

		/* Execute HKDF */
		res = data_hkdf(input, output, sz, HKDF_OKM_SZ);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] data_hkdf failed: 0x%x\n", res);
			goto cleanup;
		}

		if (cmd_info.out_op) {
			/* Write username OKM file */
			res = write_file(VALID_USR_PATH, output, HKDF_OKM_SZ);
			if (res != TEEC_SUCCESS) {
				printf("[se_sim] write_file (output) failed: 0x%x\n", res);
				goto cleanup;
			}
		} else {
			/* Compare username OKM with valid username OKM */
			res = compare_OKM(VALID_USR_PATH, output);
			if (res != TEEC_SUCCESS) {
				printf("[se_sim] invalid username\n");
				goto cleanup;
			}
		}

		/* Free input and output buffer */
		free(input);
		free(output);

		/* Read password file */
		res = read_file(cmd_info.pwd_path, &input, &sz, false);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] read_file failed: 0x%x\n", res);
			goto cleanup;
		}

		/* Allocate password OKM buffer */
		output = malloc(HKDF_OKM_SZ);
		if (!output) {
			printf("[se_sim] malloc output failed\n");
			res = TEEC_ERROR_OUT_OF_MEMORY;
			goto cleanup;
		}
		memset(output, 0x00, HKDF_OKM_SZ);

		/* Execute HKDF */
		res = data_hkdf(input, output, sz, HKDF_OKM_SZ);
		if (res != TEEC_SUCCESS) {
			printf("[se_sim] data_hkdf failed: 0x%x\n", res);
			goto cleanup;
		}

		if (cmd_info.out_op) {
			/* Write password OKM file */
			res = write_file(VALID_PWD_PATH, output, HKDF_OKM_SZ);
			if (res != TEEC_SUCCESS) {
				printf("[se_sim] write_file (output) failed: 0x%x\n", res);
				goto cleanup;
			}
		} else {
			/* Compare password OKM with valid password OKM */
			res = compare_OKM(VALID_PWD_PATH, output);
			if (res != TEEC_SUCCESS) {
				printf("[se_sim] invalid password\n");
				goto cleanup;
			}
		}

		if (cmd_info.out_op) {
			printf("[se_sim] username and password are saved\n");
		} else {
			printf("[se_sim] valid username and password\n");
		}

		break;
	default:
		help(argv[0]);
		break;
	}

cleanup:
	if (input)
		free(input);
	if (output)
		free(output);
	if (mac)
		free(mac);
	if (res != TEEC_SUCCESS) {
		printf("[se_sim] fail\n");
		return -1;
	}

	printf("[se_sim] success\n");
	return 0;
}
