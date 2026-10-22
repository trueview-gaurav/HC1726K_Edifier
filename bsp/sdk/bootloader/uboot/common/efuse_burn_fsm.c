/*
 * U-Boot eFuse Auto-Burn Finite State Machine
 * eFuse Burning Process Optimization
 *
 * Copyright (C) 2025 AugenTix Corp.
 */

#include <common.h>
#include <command.h>
#include <environment.h>
#include <fs.h>
#include <fat.h>
#include <mmc.h>
#include <malloc.h>
#include <stddef.h>
#include "efuse_burn_fsm.h"

#ifdef CONFIG_EB_SMC
#include "../arch/arm/cpu/armv7/sapporo/agtx_smc.h"
#endif
#define FILENAME_NVSPC "nvspc.bin"
#define FILENAME_ROT "pub_key_mod_hash.bin"
#define FILENAME_SEMI_PROD "semi_production_test"
#define FILENAME_FULL_PROD "full_production_test"

#ifndef CONFIG_EB_SMC
#include <asm/armv7.h>
#define ops_barrier() \
	do {          \
		DSB;  \
		ISB;  \
	} while (0)
#endif

#define SDC_ERROR(fmt, ...) printf("SDC ERROR: " fmt, ##__VA_ARGS__)
#define FSM_ERROR(fmt, ...) printf("FSM ERROR: " fmt, ##__VA_ARGS__)
#define DEBUG_EFUSE_FSM

#ifdef DEBUG_EFUSE_FSM
#define FSM_DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define SDC_INFO(fmt, ...) printf("SDC INFO:" fmt, ##__VA_ARGS__)
#define FSM_STATE_ENTRY(ctx) printf("[%d][%s] >>>>>\n", (ctx)->current_state, __func__)
#define FSM_DEBUG_ROT(ctx, label, rot_data, length)                                          \
	do {                                                                                 \
		int i;                                                                       \
		printf("[%d][%s]: %s [%d]:", (ctx)->current_state, __func__, label, length); \
		for (i = 0; i < length; i++) {                                               \
			printf("%02X", rot_data[i]);                                         \
		}                                                                            \
		printf("\n");                                                                \
	} while (0)
#else
#define FSM_DEBUG(...)
#define SDC_INFO(...)
#define FSM_STATE_ENTRY(ctx)
#define FSM_DEBUG_ROT(ctx, label, rot_data, length)
#endif

typedef int (*eb_sdc_handler_t)(efuse_fsm_context_t *ctx);

typedef struct {
	const char *task_name;
	eb_sdc_handler_t handler;
	bool is_critical;
} sdc_task_t;

static efuse_fsm_context_t g_fsm_ctx;

efuse_fsm_context_t *eb_fsm_get_context(void)
{
	return &g_fsm_ctx;
}

static efuse_fsm_result_t eb_state_start(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_check_sdcard(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_check_debug_port(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_disable_debug_port(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_verify_debug_port(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_retry_debug_port(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_check_secure_boot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_read_rot_sdcard(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_read_rot_soc(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_compare_rot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_burn_rot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_verify_rot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_retry_rot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_enable_secure_boot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_verify_secure_boot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_retry_secure_boot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_ng_error(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_reboot(efuse_fsm_context_t *ctx);
static efuse_fsm_result_t eb_state_boot_to_linux(efuse_fsm_context_t *ctx);
#ifdef CONFIG_EB_SMC
static efuse_fsm_result_t eb_state_smc_error(efuse_fsm_context_t *ctx);
#endif

static const eb_state_handler_t state_handlers[EFUSE_STATE_MAX] = {
	[EFUSE_STATE_FSM_START] = eb_state_start,
	[EFUSE_STATE_CHECK_SDCARD_FOR_TEST_FILE] = eb_state_check_sdcard,
	[EFUSE_STATE_CHECK_DEBUG_PORT_STATUS] = eb_state_check_debug_port,
	[EFUSE_STATE_DISABLE_DEBUG_PORT] = eb_state_disable_debug_port,
	[EFUSE_STATE_VERIFY_DEBUG_PORT_DISABLE] = eb_state_verify_debug_port,
	[EFUSE_STATE_RETRY_DEBUG_PORT_DISABLE] = eb_state_retry_debug_port,
	[EFUSE_STATE_CHECK_SECURE_BOOT_STATUS] = eb_state_check_secure_boot,
	[EFUSE_STATE_READ_ROT_FROM_SDCARD] = eb_state_read_rot_sdcard,
	[EFUSE_STATE_READ_ROT_FROM_SOC] = eb_state_read_rot_soc,
	[EFUSE_STATE_COMPARE_ROT] = eb_state_compare_rot,
	[EFUSE_STATE_BURN_ROT] = eb_state_burn_rot,
	[EFUSE_STATE_VERIFY_ROT_BURN] = eb_state_verify_rot,
	[EFUSE_STATE_RETRY_ROT_BURN] = eb_state_retry_rot,
	[EFUSE_STATE_ENABLE_SECURE_BOOT] = eb_state_enable_secure_boot,
	[EFUSE_STATE_VERIFY_SECURE_BOOT_ENABLE] = eb_state_verify_secure_boot,
	[EFUSE_STATE_RETRY_SECURE_BOOT_ENABLE] = eb_state_retry_secure_boot,
	[EFUSE_STATE_HANDLE_NG_ERROR] = eb_state_ng_error,
	[EFUSE_STATE_REBOOT_SYSTEM] = eb_state_reboot,
	[EFUSE_STATE_BOOT_TO_LINUX] = eb_state_boot_to_linux,
#ifdef CONFIG_EB_SMC
	[EFUSE_STATE_SMC_ERROR] = eb_state_smc_error
#endif
};

void eb_fsm_init(efuse_fsm_context_t *ctx)
{
	memset(ctx, 0, sizeof(*ctx));
	ctx->current_state = EFUSE_STATE_FSM_START;
	ctx->factory_mode = true;
	ctx->is_debug_disabled = false;
	ctx->debug_retry_count = 0;
#ifdef CONFIG_HC1703_1723_1753_1783S
	ctx->rot_length = 28;
#else
	ctx->rot_length = 32;
#endif
}

static int eb_compare_rot_bitwise(const uint8_t *target, const uint8_t *current, size_t len)
{
	size_t i;
	uint8_t bits_to_burn = 0;

	for (i = 0; i < len; i++) {
		uint8_t write_mask = target[i] & ~current[i];
		uint8_t impossible_mask = ~target[i] & current[i];

		if (impossible_mask != 0) {
			return ROT_STATUS_ERROR;
		}

		bits_to_burn |= write_mask;
	}

	return (bits_to_burn != 0) ? ROT_STATUS_BURNABLE : ROT_STATUS_SAME;
}

void eb_handle_error(efuse_fsm_context_t *ctx, uint32_t error_code, const char *description)
{
	char error_str[12];

	snprintf(error_str, sizeof(error_str), "0x%08X", error_code);
	setenv("efuse_err_code", error_str);

	printf("eFuse FSM Error: %s (Code: 0x%08X)\n", description, error_code);

	ctx->next_state = EFUSE_STATE_HANDLE_NG_ERROR;
	ctx->error_code = error_code;
	strncpy(ctx->error_msg, description, sizeof(ctx->error_msg) - 1);
	ctx->error_msg[sizeof(ctx->error_msg) - 1] = '\0';
}

#ifdef CONFIG_EB_SMC
static void smc_err_handler(efuse_fsm_context_t *ctx, struct arm_smccc_res *res, const char *func_name)
{
	printf("%s SMC failed: error=0x%lx\n", func_name, res->a0);
	ctx->next_state = EFUSE_STATE_SMC_ERROR;
	eb_handle_error(ctx, res->a0, "U-Boot SMC failed");
}
#endif

bool eb_is_terminal_state(efuse_fsm_state_t state)
{
	return (state == EFUSE_STATE_HANDLE_NG_ERROR || state == EFUSE_STATE_BOOT_TO_LINUX
#ifdef CONFIG_EB_SMC
	        || state == EFUSE_STATE_SMC_ERROR
#endif
	);
}

void __weak eb_set_ng_signal(bool ng_status)
{
	if (ng_status) {
		FSM_DEBUG("Production Line: NG Signal Activated\n");
	} else {
		FSM_DEBUG("Production Line: NG Signal Cleared\n");
	}
}

static efuse_fsm_result_t eb_state_start(efuse_fsm_context_t *ctx)
{
	FSM_STATE_ENTRY(ctx);

	ctx->next_state = EFUSE_STATE_CHECK_SDCARD_FOR_TEST_FILE;

	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_check_sdcard(efuse_fsm_context_t *ctx)
{
	if (ctx->validation_results.semi_prod_status == VALIDATION_OK) {
		ctx->next_state = EFUSE_STATE_CHECK_DEBUG_PORT_STATUS;
	} else {
		ctx->next_state = EFUSE_STATE_BOOT_TO_LINUX;
	}
	FSM_DEBUG("[%d][%s] semi_prod check [%s]\n", ctx->current_state, __func__,
	          ctx->validation_results.semi_prod_status == VALIDATION_OK ? "OK" : "FAIL");

	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_check_debug_port(efuse_fsm_context_t *ctx)
{
	uint8_t debug_status;

#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;

	efuse_burn_ops->debug_check(&res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_debug_check");
		return EFUSE_FSM_ERROR;
	}
	debug_status = (uint8_t)res.a1;
#else
	debug_status = efuse_burn_ops->debug_check(EB_CTRL_BASE);
#endif
	FSM_DEBUG("[%d][%s]: %s\n", ctx->current_state, __func__, (debug_status == 1) ? "Disabled" : "Enabled");

	if (debug_status == 1) {
		ctx->is_debug_disabled = true;
		ctx->next_state = EFUSE_STATE_CHECK_SECURE_BOOT_STATUS;
	} else {
		ctx->is_debug_disabled = false;
		ctx->next_state = EFUSE_STATE_DISABLE_DEBUG_PORT;
	}

	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_disable_debug_port(efuse_fsm_context_t *ctx)
{
	FSM_STATE_ENTRY(ctx);

#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;

	efuse_burn_ops->debug_disable(&res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_debug_disable");
		return EFUSE_FSM_ERROR;
	}
#else
	efuse_burn_ops->debug_disable(EB_CTRL_BASE);
	ops_barrier();
#endif

	ctx->next_state = EFUSE_STATE_VERIFY_DEBUG_PORT_DISABLE;
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_verify_debug_port(efuse_fsm_context_t *ctx)
{
	uint8_t verify_status;

#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;
	efuse_burn_ops->debug_check(&res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_debug_check");
		return EFUSE_FSM_ERROR;
	}
	verify_status = (uint8_t)res.a1;
#else
	verify_status = efuse_burn_ops->debug_check(EB_CTRL_BASE);
#endif

	if (verify_status == 1) {
		FSM_DEBUG("[%d][%s]: Debug port successfully disabled\n", ctx->current_state, __func__);
		ctx->next_state = EFUSE_STATE_CHECK_SECURE_BOOT_STATUS;
	} else {
		FSM_DEBUG("[%d][%s]: Retry disable debug port\n", ctx->current_state, __func__);
		ctx->next_state = EFUSE_STATE_RETRY_DEBUG_PORT_DISABLE;
	}

	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_retry_debug_port(efuse_fsm_context_t *ctx)
{
	ctx->debug_retry_count++;
	FSM_DEBUG("[%d][%s] Retry %d/%d\n", ctx->current_state, __func__, ctx->debug_retry_count, MAX_RETRY_COUNT);

	if (ctx->debug_retry_count < MAX_RETRY_COUNT) {
		udelay(RETRY_DELAY_MS * 1000);
		ctx->next_state = EFUSE_STATE_DISABLE_DEBUG_PORT;
		return EFUSE_FSM_SUCCESS;
	} else {
		eb_handle_error(ctx, EFUSE_ERR_DEBUG_PORT_MAX_RETRIES, "Debug port disable failed after 3 attempts");
		return EFUSE_FSM_ERROR;
	}
}

static efuse_fsm_result_t eb_state_check_secure_boot(efuse_fsm_context_t *ctx)
{
	uint8_t secure_boot_status;

#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;
	efuse_burn_ops->prog_check(&res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_prog_check");
		return EFUSE_FSM_ERROR;
	}
	secure_boot_status = (uint8_t)res.a1;
#else
	secure_boot_status = efuse_burn_ops->prog_check(EB_CTRL_BASE);
#endif
	FSM_DEBUG("[%d][%s]: %s\n", ctx->current_state, __func__, secure_boot_status == 1 ? "Enable" : "Disable");

	if (secure_boot_status == 1) {
		ctx->secure_boot_enabled = true;
		if (ctx->is_debug_disabled) {
			ctx->next_state = EFUSE_STATE_BOOT_TO_LINUX;
		} else {
			ctx->next_state = EFUSE_STATE_REBOOT_SYSTEM;
		}
	} else {
		ctx->secure_boot_enabled = false;
		ctx->next_state = EFUSE_STATE_READ_ROT_FROM_SDCARD;
	}
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_read_rot_sdcard(efuse_fsm_context_t *ctx)
{
	FSM_DEBUG_ROT(ctx, "", ctx->rot_sdcard, ctx->rot_length);
	if (ctx->validation_results.rot_status != VALIDATION_OK) {
		eb_handle_error(ctx, EFUSE_ERR_SDCARD_FILE_NOT_FOUND, "RoT file validation failed");
		return EFUSE_FSM_ERROR;
	}
	ctx->next_state = EFUSE_STATE_READ_ROT_FROM_SOC;
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_read_rot_soc(efuse_fsm_context_t *ctx)
{
#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;
	efuse_burn_ops->prog_get(ctx->rot_soc, &res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_prog_get");
		return EFUSE_FSM_ERROR;
	}
#else
	efuse_burn_ops->prog_get(ctx->rot_soc, EB_CTRL_BASE);
#endif
	FSM_DEBUG_ROT(ctx, "", ctx->rot_soc, ctx->rot_length);

	ctx->next_state = EFUSE_STATE_COMPARE_ROT;
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_compare_rot(efuse_fsm_context_t *ctx)
{
	ctx->rot_status = eb_compare_rot_bitwise(ctx->rot_sdcard, ctx->rot_soc, ctx->rot_length);
	switch (ctx->rot_status) {
	case ROT_STATUS_ERROR:
		ctx->next_state = EFUSE_STATE_HANDLE_NG_ERROR;
		eb_handle_error(ctx, EFUSE_ERR_ROT_NOT_WRITABLE, "RoT mismatch: Cannot burn 1->0");
		break;
	case ROT_STATUS_SAME:
		FSM_DEBUG("[%d][%s] -> EFUSE_STATE_ENABLE_SECURE_BOOT\n", ctx->current_state, __func__);
		ctx->next_state = EFUSE_STATE_ENABLE_SECURE_BOOT;
		break;
	case ROT_STATUS_BURNABLE:
		FSM_DEBUG("[%d][%s] -> EFUSE_STATE_BURN_ROT\n", ctx->current_state, __func__);
		ctx->next_state = EFUSE_STATE_BURN_ROT;
		break;
	}
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_burn_rot(efuse_fsm_context_t *ctx)
{
	FSM_STATE_ENTRY(ctx);

#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;
	efuse_burn_ops->prog_set(ctx->rot_sdcard, &res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_prog_set");
		return EFUSE_FSM_ERROR;
	}
#else
	efuse_burn_ops->prog_set(ctx->rot_sdcard, EB_CTRL_BASE);
	ops_barrier();
#endif

	ctx->next_state = EFUSE_STATE_VERIFY_ROT_BURN;
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_verify_rot(efuse_fsm_context_t *ctx)
{
	uint8_t verify_buffer[ctx->rot_length];
	int verify_result;
	FSM_STATE_ENTRY(ctx);

	if (ctx->rot_length == 0 || ctx->rot_length > sizeof(ctx->rot_sdcard)) {
		eb_handle_error(ctx, EFUSE_ERR_UNEXPECTED_STATE, "Invalid RoT length");
		return EFUSE_FSM_ERROR;
	}

#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;
	efuse_burn_ops->prog_get(verify_buffer, &res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_prog_get");
		return EFUSE_FSM_ERROR;
	}
#else
	efuse_burn_ops->prog_get(verify_buffer, EB_CTRL_BASE);
#endif

	verify_result = eb_compare_rot_bitwise(ctx->rot_sdcard, verify_buffer, ctx->rot_length);

	switch (verify_result) {
	case ROT_STATUS_ERROR:
		ctx->next_state = EFUSE_STATE_HANDLE_NG_ERROR;
		eb_handle_error(ctx, EFUSE_ERR_ROT_HARDWARE_FAULT, "Hardware fault: unexpected bits set after burn");
		break;
	case ROT_STATUS_SAME:
		ctx->next_state = EFUSE_STATE_REBOOT_SYSTEM;
		break;
	case ROT_STATUS_BURNABLE:
		ctx->next_state = EFUSE_STATE_RETRY_ROT_BURN;
		break;
	}
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_retry_rot(efuse_fsm_context_t *ctx)
{
	ctx->rot_retry_count++;
	if (ctx->rot_retry_count < MAX_RETRY_COUNT) {
		udelay(RETRY_DELAY_MS * 1000);
		ctx->next_state = EFUSE_STATE_BURN_ROT;
		return EFUSE_FSM_SUCCESS;
	} else {
		eb_handle_error(ctx, EFUSE_ERR_ROT_MAX_RETRIES, "RoT burn failed after 3 attempts");
		return EFUSE_FSM_ERROR;
	}
}

static efuse_fsm_result_t eb_state_enable_secure_boot(efuse_fsm_context_t *ctx)
{
	FSM_STATE_ENTRY(ctx);

#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;
	efuse_burn_ops->prog_enable(&res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_prog_enable");
		return EFUSE_FSM_ERROR;
	}
#else
	efuse_burn_ops->prog_enable(EB_CTRL_BASE);
	ops_barrier();
#endif

	ctx->next_state = EFUSE_STATE_VERIFY_SECURE_BOOT_ENABLE;
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_verify_secure_boot(efuse_fsm_context_t *ctx)
{
	uint8_t verify_status;
	FSM_STATE_ENTRY(ctx);

#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;
	efuse_burn_ops->prog_check(&res);
	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		smc_err_handler(ctx, &res, "eb_smc_prog_check");
		return EFUSE_FSM_ERROR;
	}
	verify_status = (uint8_t)res.a1;
#else
	verify_status = efuse_burn_ops->prog_check(EB_CTRL_BASE);
#endif

	if (verify_status == 1) {
		ctx->next_state = EFUSE_STATE_REBOOT_SYSTEM;
	} else {
		ctx->next_state = EFUSE_STATE_RETRY_SECURE_BOOT_ENABLE;
	}
	return EFUSE_FSM_SUCCESS;
}

static efuse_fsm_result_t eb_state_retry_secure_boot(efuse_fsm_context_t *ctx)
{
	ctx->sec_retry_count++;
	if (ctx->sec_retry_count < MAX_RETRY_COUNT) {
		udelay(RETRY_DELAY_MS * 1000);
		ctx->next_state = EFUSE_STATE_ENABLE_SECURE_BOOT;
		return EFUSE_FSM_SUCCESS;
	} else {
		eb_handle_error(ctx, EFUSE_ERR_SECBOOT_MAX_RETRIES, "Secure boot enable failed after 3 attempts");
		return EFUSE_FSM_ERROR;
	}
}

static efuse_fsm_result_t eb_state_ng_error(efuse_fsm_context_t *ctx)
{
	FSM_STATE_ENTRY(ctx);
	eb_set_ng_signal(true);
	return EFUSE_FSM_ABORT;
}

#ifdef CONFIG_EB_SMC
static efuse_fsm_result_t eb_state_smc_error(efuse_fsm_context_t *ctx)
{
	FSM_STATE_ENTRY(ctx);
	printf("SMC Error: %s (Code: 0x%04X)\n", ctx->error_msg, ctx->error_code);
	eb_set_ng_signal(true);
	return EFUSE_FSM_ABORT;
}
#endif

static efuse_fsm_result_t eb_state_reboot(efuse_fsm_context_t *ctx)
{
	FSM_STATE_ENTRY(ctx);
	return EFUSE_FSM_REBOOT;
}

static efuse_fsm_result_t eb_state_boot_to_linux(efuse_fsm_context_t *ctx)
{
	FSM_STATE_ENTRY(ctx);
	setenv("factory_mode", "0");
	saveenv();
	FSM_DEBUG("factory_mode cleared after successful FSM completion\n");
	return EFUSE_FSM_SUCCESS;
}

int eb_fsm_start(void)
{
	efuse_fsm_context_t *ctx = &g_fsm_ctx;
	efuse_fsm_result_t result;
	int ret;
#ifdef CONFIG_EB_SMC
	struct arm_smccc_res res;
	eb_smc_clk_enable(&res);
#elif defined(CONFIG_SAPPORO)
	/* Enable eFuse clock: CK_BASE(0x80000000) + CG_SYS(0x14) bit[0] */
	volatile uint32_t *cken_efuse = (volatile uint32_t *)0x80000014;
	uint32_t clk_saved = *cken_efuse;
	if (!clk_saved) {
		*cken_efuse = 1;
		udelay(20);
	}

#endif
	while (!eb_is_terminal_state(ctx->current_state)) {
		if (ctx->current_state >= EFUSE_STATE_MAX) {
			eb_handle_error(ctx, EFUSE_ERR_UNEXPECTED_STATE, "Invalid FSM state");
			break;
		}

		result = state_handlers[ctx->current_state](ctx);
		switch (result) {
		case EFUSE_FSM_SUCCESS:
		case EFUSE_FSM_CONTINUE:
			ctx->current_state = ctx->next_state;
			break;
		case EFUSE_FSM_REBOOT:
			ret = 0;
			goto out;
		case EFUSE_FSM_ABORT:
		case EFUSE_FSM_ERROR:
			ret = 1;
			goto out;
		}
	}
	ret = (ctx->current_state == EFUSE_STATE_HANDLE_NG_ERROR) ? 1 : 0;

out:
#ifdef CONFIG_EB_SMC
	eb_smc_clk_disable(&res);
#elif defined(CONFIG_SAPPORO)
	*cken_efuse = clk_saved;
#endif
	if (result == EFUSE_FSM_REBOOT)
		do_reset(NULL, 0, 0, NULL);
	return ret;
}

static const char *g_sdc_dev_part;

static int eb_sdc_init(void)
{
	static const char *partitions[] = { "0:0", "0:1", NULL };
	const char **p;
	struct mmc *mmc;
	int retry;

	if (g_sdc_dev_part && fs_set_blk_dev("mmc", g_sdc_dev_part, FS_TYPE_FAT) == 0)
		return SDC_SUCCESS;

	for (retry = 0; retry < 3; retry++) {
		if (retry > 0)
			mdelay(200);

		mmc = find_mmc_device(0);
		if (!mmc || mmc_init(mmc) != 0)
			continue;

		for (p = partitions; *p; p++) {
			if (fs_set_blk_dev("mmc", *p, FS_TYPE_FAT) == 0) {
				g_sdc_dev_part = *p;
				FSM_DEBUG("[%s] Using mmc %s\n", __func__, *p);
				return SDC_SUCCESS;
			}
		}
	}

	SDC_ERROR("MMC init failed after 3 retries\n");
	return -SDC_ERROR;
}

static inline int eb_sdc_size(const char *filename, loff_t *size)
{
	if (eb_sdc_init() < 0)
		return -SDC_ERROR;
	return (fs_size(filename, size) == 0) ? SDC_SUCCESS : -SDC_ERROR;
}

static inline int eb_sdc_read(const char *filename, ulong addr, loff_t offset, loff_t len, loff_t *actread)
{
	if (eb_sdc_init() < 0)
		return -SDC_ERROR;
	if (fs_read(filename, addr, offset, len, actread) < 0) {
		SDC_ERROR("Read '%s' failed\n", filename);
		return -SDC_ERROR;
	}
	return SDC_SUCCESS;
}

static int handle_semi_prod_flag(efuse_fsm_context_t *ctx)
{
	loff_t size;
	if (eb_sdc_size(FILENAME_SEMI_PROD, &size) == 0) {
		ctx->validation_results.semi_prod_status = VALIDATION_OK;
	} else {
		ctx->validation_results.semi_prod_status = VALIDATION_NOT_FOUND;
	}
	return SDC_SUCCESS;
}

static int handle_full_prod_flag(efuse_fsm_context_t *ctx)
{
	loff_t size;
	if (eb_sdc_size(FILENAME_FULL_PROD, &size) == 0) {
		ctx->validation_results.full_prod_status = VALIDATION_OK;
	} else {
		ctx->validation_results.full_prod_status = VALIDATION_NOT_FOUND;
	}
	return SDC_SUCCESS;
}

static int handle_rot_file(efuse_fsm_context_t *ctx)
{
	loff_t size;
	void *aligned_buffer;

	if (eb_sdc_size(FILENAME_ROT, &size) < 0) {
		SDC_ERROR("%s not found\n", FILENAME_ROT);
		ctx->validation_results.rot_status = VALIDATION_NOT_FOUND;
		return -SDC_ERROR;
	}

	if (size != 28 && size != 32) {
		SDC_ERROR("Invalid size %lld for %s (expected 28 or 32)\n", size, FILENAME_ROT);
		ctx->validation_results.rot_status = VALIDATION_INVALID_SIZE;
		return -SDC_ERROR;
	}

	aligned_buffer = memalign(ARCH_DMA_MINALIGN, ALIGN(size, ARCH_DMA_MINALIGN));
	if (!aligned_buffer) {
		SDC_ERROR("Failed to allocate aligned buffer for %s\n", FILENAME_ROT);
		return -SDC_ERROR;
	}

	if (eb_sdc_read(FILENAME_ROT, (ulong)aligned_buffer, 0, size, NULL) < 0) {
		free(aligned_buffer);
		ctx->rot_length = 0;
		return -SDC_ERROR;
	}

	memcpy(ctx->rot_sdcard, aligned_buffer, size);
	ctx->rot_length = size;
	ctx->validation_results.rot_status = VALIDATION_OK;
	free(aligned_buffer);

	FSM_DEBUG("[efuse_rot] loaded from SD card (%d bytes)\n", (int)size);
	return SDC_SUCCESS;
}

static void *read_nvspc_from_sdcard(efuse_fsm_context_t *ctx, loff_t *out_size)
{
	loff_t size;
	void *buffer;

	if (eb_sdc_size(FILENAME_NVSPC, &size) < 0) {
		ctx->validation_results.nvspc_status = VALIDATION_NOT_FOUND;
		return NULL;
	}

	if (size < sizeof(efuse_burn_ops_t) + NVSPC_HEADER_OFFSET || size > NVSPC_MAX_SIZE) {
		SDC_ERROR("NVSPC size invalid: %lld\n", size);
		ctx->validation_results.nvspc_status = VALIDATION_INVALID_SIZE;
		return NULL;
	}

	buffer = memalign(ARCH_DMA_MINALIGN, ALIGN(size, ARCH_DMA_MINALIGN));
	if (!buffer) {
		SDC_ERROR("NVSPC buffer alloc failed\n");
		ctx->validation_results.nvspc_status = VALIDATION_READ_ERROR;
		return NULL;
	}

	if (eb_sdc_read(FILENAME_NVSPC, (ulong)buffer, 0, size, NULL) < 0) {
		ctx->validation_results.nvspc_status = VALIDATION_READ_ERROR;
		free(buffer);
		return NULL;
	}

	*out_size = size;
	return buffer;
}

static void cleanup_nvspc_buffer(void *buffer, loff_t size)
{
	if (buffer) {
		memset(buffer, 0, size);
		free(buffer);
	}
}

static int nvspc_success(efuse_fsm_context_t *ctx)
{
	ctx->nvspc_loaded = true;
	ctx->validation_results.nvspc_status = VALIDATION_OK;
	return SDC_SUCCESS;
}

static int handle_nvspc_file(efuse_fsm_context_t *ctx)
{
	efuse_burn_ops_t *header;
	void *buffer;
	loff_t size;

#ifdef CONFIG_EB_SMC
	extern void eb_smc_nvspc_load(void *src, u32 size, struct arm_smccc_res *res);
	struct arm_smccc_res res;

	eb_smc_nvspc_load(NULL, 0, &res);
	if (res.a0 == OPTEE_SMC_RETURN_OK) {
		FSM_DEBUG("[efuse_burn_ops] SPL build-in ABI v%lu.%lu\n", (res.a1 >> 16) & 0xFFFF, res.a1 & 0xFFFF);
		return nvspc_success(ctx);
	}

	buffer = read_nvspc_from_sdcard(ctx, &size);
	if (!buffer)
		return -SDC_ERROR;

	header = (efuse_burn_ops_t *)(buffer + NVSPC_HEADER_OFFSET);
	if (check_ops_valid(header)) {
		SDC_ERROR("NVSPC header invalid: magic=0x%08x ver=0x%08x\n", header->magic_number, header->api_version);
		ctx->validation_results.nvspc_status = VALIDATION_INVALID_HEADER;
		cleanup_nvspc_buffer(buffer, size);
		ctx->nvspc_loaded = false;
		return -SDC_ERROR;
	}

	if (eb_sdc_read(FILENAME_NVSPC, NVSPC_TEMP_BUFFER, 0, size, NULL) < 0) {
		ctx->validation_results.nvspc_status = VALIDATION_READ_ERROR;
		cleanup_nvspc_buffer(buffer, size);
		ctx->nvspc_loaded = false;
		return -SDC_ERROR;
	}

	eb_smc_nvspc_load((void *)NVSPC_TEMP_BUFFER, size, &res);
	cleanup_nvspc_buffer(buffer, size);

	if (res.a0 != OPTEE_SMC_RETURN_OK) {
		SDC_ERROR("SMC nvspc_load failed: 0x%lx\n", res.a0);
		ctx->validation_results.nvspc_status = VALIDATION_READ_ERROR;
		ctx->nvspc_loaded = false;
		return -SDC_ERROR;
	}

	FSM_DEBUG("[efuse_burn_ops] nvspc.bin v%lu.%lu (SMC)\n", (res.a1 >> 16) & 0xFFFF, res.a1 & 0xFFFF);
	return nvspc_success(ctx);

#else
	if (!check_ops_valid((efuse_burn_ops_t *)EFUSE_BURN_OPS_BASE)) {
		efuse_burn_ops_t *ops = (efuse_burn_ops_t *)EFUSE_BURN_OPS_BASE;
		FSM_DEBUG("[efuse_burn_ops] SPL build-in ABI v%u.%u\n", (ops->api_version >> 16) & 0xFFFF,
		          ops->api_version & 0xFFFF);
		return nvspc_success(ctx);
	}

	buffer = read_nvspc_from_sdcard(ctx, &size);
	if (!buffer)
		return -SDC_ERROR;

	header = (efuse_burn_ops_t *)(buffer + NVSPC_HEADER_OFFSET);
	if (check_ops_valid(header)) {
		SDC_ERROR("NVSPC header invalid: magic=0x%08x ver=0x%08x\n", header->magic_number, header->api_version);
		ctx->validation_results.nvspc_status = VALIDATION_INVALID_HEADER;
		cleanup_nvspc_buffer(buffer, size);
		return -SDC_ERROR;
	}

	memcpy((void *)NVSPC_LOAD_ADDRESS, buffer, size);
	flush_dcache_range(NVSPC_LOAD_ADDRESS, NVSPC_LOAD_ADDRESS + size);
	invalidate_icache_all();

	cleanup_nvspc_buffer(buffer, size);
	FSM_DEBUG("[efuse_burn_ops] nvspc.bin v%u.%u\n", (header->api_version >> 16) & 0xFFFF,
	          header->api_version & 0xFFFF);
	return nvspc_success(ctx);
#endif
}

static const sdc_task_t sdc_tasks[] = {
	{ FILENAME_NVSPC, handle_nvspc_file, true },
	{ FILENAME_ROT, handle_rot_file, true },
	{ FILENAME_SEMI_PROD, handle_semi_prod_flag, false },
	{ FILENAME_FULL_PROD, handle_full_prod_flag, false },
};

int eb_sdc_load_data(void)
{
	efuse_fsm_context_t *ctx = eb_fsm_get_context();
	int i;

	for (i = 0; i < ARRAY_SIZE(sdc_tasks); i++) {
		const sdc_task_t *task = &sdc_tasks[i];
		if (task->handler(ctx) < 0) {
			if (task->is_critical) {
				FSM_DEBUG("[%s][%s] load FAIL\n", __func__, task->task_name);
				return -SDC_ERROR;
			}
		}
	}

	FSM_DEBUG("[%s] OK\n", __func__);
	return SDC_SUCCESS;
}

