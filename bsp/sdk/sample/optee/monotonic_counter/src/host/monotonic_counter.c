#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* OP-TEE TEE client API (built by optee_client) */
#include <tee_client_api.h>
#include <monotonic_counter.h>

struct cmd_info {
	uint32_t cmd;
	uint32_t cnt_id;
	uint32_t cnt_val;
};
static struct cmd_info cmd_info;

static TEEC_Result open_sess(TEEC_Context *ctx, TEEC_Session *sess)
{
	TEEC_UUID uuid = MONOTONIC_CNT_UUID;
	TEEC_Result res = TEEC_SUCCESS;
	uint32_t err_origin;

	/* Initialize a context connecting us to the TEE */
	res = TEEC_InitializeContext(NULL, ctx);
	if (res != TEEC_SUCCESS) {
		warn("TEEC_InitializeContext failed with code 0x%x", res);
		return res;
	}

	/* Open a session to the "monotonic counter" PTA */
	res = TEEC_OpenSession(ctx, sess, &uuid, TEEC_LOGIN_PUBLIC, NULL, NULL, &err_origin);
	if (res != TEEC_SUCCESS) {
		warn("TEEC_Opensession failed with code 0x%x origin 0x%x", res, err_origin);
		TEEC_FinalizeContext(ctx);
		return res;
	}

	return res;
}

static TEEC_Result set_cnt(void)
{
	TEEC_Result res = TEEC_ERROR_GENERIC;
	TEEC_Context ctx = {};
	TEEC_Session sess = {};
	TEEC_Operation op = {};
	uint32_t err_origin;

	res = open_sess(&ctx, &sess);
	if (res != TEEC_SUCCESS)
		return res;

	/* Clear the TEEC_Operation struct */
	memset(&op, 0, sizeof(op));

	/* Prepare the argument. Pass a value in the first parameter,
     * the remaining three parameters are unused.
     */
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_VALUE_INPUT, TEEC_NONE, TEEC_NONE);
	op.params[0].value.a = cmd_info.cnt_id;
	op.params[1].value.a = cmd_info.cnt_val;

	/* PTA_CMD_CNT_SET is the actual function in the PTA to be called. */
	res = TEEC_InvokeCommand(&sess, cmd_info.cmd, &op, &err_origin);

	TEEC_CloseSession(&sess);
	TEEC_FinalizeContext(&ctx);

	if (res != TEEC_SUCCESS)
		warn("TEEC_InvokeCommand failed with code %#x origin %#x", res, err_origin);
	else
		printf("Set counter %u with value %u success!\n", cmd_info.cnt_id, cmd_info.cnt_val);

	return res;
}

static TEEC_Result get_cnt(void)
{
	TEEC_Result res = TEEC_ERROR_GENERIC;
	TEEC_Context ctx = {};
	TEEC_Session sess = {};
	TEEC_Operation op = {};
	uint32_t err_origin;

	res = open_sess(&ctx, &sess);
	if (res != TEEC_SUCCESS)
		return res;

	/* Clear the TEEC_Operation struct */
	memset(&op, 0, sizeof(op));

	/* Prepare the argument. Pass a value in the first parameter,
     * the remaining three parameters are unused.
     */
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_VALUE_OUTPUT, TEEC_NONE, TEEC_NONE);
	op.params[0].value.a = cmd_info.cnt_id;

	/* PTA_CMD_CNT_SET is the actual function in the PTA to be called. */
	res = TEEC_InvokeCommand(&sess, cmd_info.cmd, &op, &err_origin);

	TEEC_CloseSession(&sess);
	TEEC_FinalizeContext(&ctx);

	if (res != TEEC_SUCCESS)
		warn("TEEC_InvokeCommand failed with code %#x origin %#x", res, err_origin);
	else
		printf("Get counter %u with value %u\n", cmd_info.cnt_id, op.params[1].value.a);

	return res;
}

static void help(const char *program_name)
{
	printf("Usage:\n");
	printf("  %s -s <Counter ID> -v <value>         Set counter <ID> to <value>\n", program_name);
	printf("  %s -g <Counter ID>                    Get counter <ID> value\n", program_name);
	printf("  %s -h\n", program_name);
}

int main(int argc, char **argv)
{
	TEEC_Result res = 0;
	int opt;

	while ((opt = getopt(argc, argv, "s:v:g:h")) != -1) {
		switch (opt) {
		case 's':
			cmd_info.cmd = PTA_CMD_CNT_SET;
			cmd_info.cnt_id = atoi(optarg);
			break;
		case 'v':
			cmd_info.cnt_val = atoi(optarg);
			break;
		case 'g':
			cmd_info.cmd = PTA_CMD_CNT_GET;
			cmd_info.cnt_id = atoi(optarg);
			break;
		case 'h':
		default:
			help(argv[0]);
			return 0;
		}
	}

	switch (cmd_info.cmd) {
	case PTA_CMD_CNT_SET:
		res = set_cnt();
		break;
	case PTA_CMD_CNT_GET:
		res = get_cnt();
		break;
	default:
		help(argv[0]);
		break;
	}

	return res;
}
