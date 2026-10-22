/*
 * U-Boot eFuse Auto-Burn Finite State Machine
 * eFuse Burning Process Optimization
 *
 * Copyright (C) 2025 AugenTix Corp.
 */

#ifndef __EFUSE_BURN_FSM_H__
#define __EFUSE_BURN_FSM_H__

#include <common.h>
#include <command.h>
#include <environment.h>
#include <linux/arm-smccc.h>

/* SMC path: requires both SMCCC library and OP-TEE */
#if defined(CONFIG_ARM_SMCCC) && defined(CONFIG_OPTEE)
#define CONFIG_EB_SMC
#endif

#define NVSPC_HEADER_OFFSET 0x60
#define NVSPC_HEADER_MAGIC 0x99272327
#define NVSPC_API_VERSION 0x00020000
#define NVSPC_LOAD_ADDRESS 0xFFE00800

#define NVSPC_MAX_SIZE 0x7800 /* Max size: 0xFFE00800 to 0xFFE08000 */

typedef enum { SDC_SUCCESS = 0, SDC_ERROR = 1 } sdc_result_t;

typedef enum {
	VALIDATION_OK = 0,
	VALIDATION_NOT_FOUND,
	VALIDATION_INVALID_SIZE,
	VALIDATION_INVALID_HEADER,
	VALIDATION_READ_ERROR,
	VALIDATION_STATUS_MAX
} file_validation_status_t;

typedef struct {
	file_validation_status_t nvspc_status;
	file_validation_status_t rot_status;
	file_validation_status_t semi_prod_status;
	file_validation_status_t full_prod_status;
} sd_validation_result_t;

typedef enum {
	EFUSE_STATE_FSM_START = 0,
	EFUSE_STATE_CHECK_SDCARD_FOR_TEST_FILE,
	EFUSE_STATE_CHECK_DEBUG_PORT_STATUS,
	EFUSE_STATE_DISABLE_DEBUG_PORT,
	EFUSE_STATE_VERIFY_DEBUG_PORT_DISABLE,
	EFUSE_STATE_RETRY_DEBUG_PORT_DISABLE,
	EFUSE_STATE_CHECK_SECURE_BOOT_STATUS,
	EFUSE_STATE_READ_ROT_FROM_SDCARD,
	EFUSE_STATE_READ_ROT_FROM_SOC,
	EFUSE_STATE_COMPARE_ROT,
	EFUSE_STATE_BURN_ROT,
	EFUSE_STATE_VERIFY_ROT_BURN,
	EFUSE_STATE_RETRY_ROT_BURN,
	EFUSE_STATE_ENABLE_SECURE_BOOT,
	EFUSE_STATE_VERIFY_SECURE_BOOT_ENABLE,
	EFUSE_STATE_RETRY_SECURE_BOOT_ENABLE,
	EFUSE_STATE_HANDLE_NG_ERROR,
	EFUSE_STATE_REBOOT_SYSTEM,
	EFUSE_STATE_BOOT_TO_LINUX,
#ifdef CONFIG_EB_SMC
	EFUSE_STATE_SMC_ERROR,
#endif
	EFUSE_STATE_MAX
} efuse_fsm_state_t;

typedef enum {
	EFUSE_FSM_SUCCESS = 0,
	EFUSE_FSM_CONTINUE,
	EFUSE_FSM_REBOOT,
	EFUSE_FSM_ABORT,
	EFUSE_FSM_ERROR
} efuse_fsm_result_t;

#define EFUSE_API_SUCCESS 0x00
#define EFUSE_API_FAILURE 0x01
#define EFUSE_API_TIMEOUT 0x02
#define EFUSE_API_INVALID_PARAM 0x03
#define EFUSE_API_NOT_READY 0x04
#define EFUSE_API_WRITE_PROTECT 0x05

#define EFUSE_ERR_SDCARD_READ_FAILED 0x0101
#define EFUSE_ERR_SDCARD_FILE_NOT_FOUND 0x0102
#define EFUSE_ERR_SDCARD_FILE_SIZE_INVALID 0x0103
#define EFUSE_ERR_SOC_READ_FAILED 0x0104
#define EFUSE_ERR_SOC_READ_TIMEOUT 0x0105

#define EFUSE_ERR_ROT_NOT_WRITABLE 0x0201
#define EFUSE_ERR_ROT_BURN_FAILED 0x0202
#define EFUSE_ERR_ROT_VERIFY_FAILED 0x0203
#define EFUSE_ERR_ROT_MAX_RETRIES 0x0204
#define EFUSE_ERR_ROT_HARDWARE_FAULT 0x0205

#define EFUSE_ERR_SECBOOT_ENABLE_FAILED 0x0301
#define EFUSE_ERR_SECBOOT_VERIFY_FAILED 0x0302
#define EFUSE_ERR_SECBOOT_MAX_RETRIES 0x0303
#define EFUSE_ERR_SECBOOT_HARDWARE_FAULT 0x0304

#define EFUSE_ERR_DEBUG_PORT_DISABLE_FAILED 0x0501
#define EFUSE_ERR_DEBUG_PORT_VERIFY_FAILED 0x0502
#define EFUSE_ERR_DEBUG_PORT_MAX_RETRIES 0x0503
#define EFUSE_ERR_DEBUG_PORT_HARDWARE_FAULT 0x0504

#define EFUSE_ERR_NVSPC_LOAD_FAILED 0x0401
#define EFUSE_ERR_NVSPC_INVALID_HEADER 0x0402
#define EFUSE_ERR_MEMORY_CORRUPTION 0x0403
#define EFUSE_ERR_UNEXPECTED_STATE 0x0404

/* NVSPC ABI — SPL efuse ops validation (aligned with otp-agtx.h) */
#define AGTX_ERR_OPS_NOT_INIT 0xFEFEFE10
#define AGTX_ERR_OPS_INVALID_MAGIC 0xFEFEFE11
#define AGTX_ERR_OPS_INVALID_VERSION 0xFEFEFE12
#define AGTX_ERR_PROG_GET_NULL 0xFEFEFE20

#define SPL_CODE_START 0xFFE00868
#define SPL_CODE_END 0xFFE07000
#define IS_VALID_EB_OPS_PTR(ptr) ((uint32_t)(ptr) >= SPL_CODE_START && (uint32_t)(ptr) < SPL_CODE_END)
#define EB_OPS_PTR_COUNT 8 /* core ops only */

#ifdef CONFIG_EB_SMC
/* SMC Return Codes [sdk/kernel/optee_os_4.5.0/src/core/arch/arm/include/sm/optee_smc.h] */
#define OPTEE_SMC_RETURN_OK 0x0
#define OPTEE_SMC_RETURN_ETHREAD_LIMIT 0x1
#define OPTEE_SMC_RETURN_EBUSY 0x2
#define OPTEE_SMC_RETURN_ERESUME 0x3
#define OPTEE_SMC_RETURN_EBADADDR 0x4
#define OPTEE_SMC_RETURN_EBADCMD 0x5
#define OPTEE_SMC_RETURN_ENOMEM 0x6
#define OPTEE_SMC_RETURN_ENOTAVAIL 0x7
#endif
#ifdef CONFIG_HC1703_1723_1753_1783S
#define SHA_LEN 28
#else
#define SHA_LEN 32
#endif

#define MAX_RETRY_COUNT 3
#define RETRY_DELAY_MS 200

#define ROT_STATUS_SAME 0
#define ROT_STATUS_BURNABLE 1
#define ROT_STATUS_ERROR -1

typedef struct {
	efuse_fsm_state_t current_state;
	efuse_fsm_state_t next_state;
	uint32_t rot_retry_count;
	uint32_t sec_retry_count;
	uint32_t error_code;
	char error_msg[128];

	sd_validation_result_t validation_results;

	uint8_t rot_sdcard[32];
	uint8_t rot_soc[32];
	uint8_t rot_length;
	int rot_status;

	bool factory_mode;
	bool secure_boot_enabled;
	bool nvspc_loaded;
	bool is_debug_disabled;
	uint32_t debug_retry_count;
} efuse_fsm_context_t;

#define EFUSE_BURN_OPS_BASE 0xFFE00860
#ifdef CONFIG_EB_SMC
typedef struct {
	uint32_t magic_number;
	uint32_t api_version;
	void (*prog_get)(uint8_t *rot_data, struct arm_smccc_res *res);
	void (*prog_set)(uint8_t *rot_data, struct arm_smccc_res *res);
	void (*prog_enable)(struct arm_smccc_res *res);
	uint8_t (*prog_check)(struct arm_smccc_res *res);
	void (*debug_disable)(struct arm_smccc_res *res);
	uint8_t (*debug_check)(struct arm_smccc_res *res);
	void (*otp_set)(uint8_t *otp_data, struct arm_smccc_res *res);
	void (*otp_get)(uint8_t *otp_data, struct arm_smccc_res *res);
	uint8_t reserved[24];
} efuse_burn_ops_t;

extern efuse_burn_ops_t eb_smc_ops;
#define efuse_burn_ops (&eb_smc_ops)
#else
typedef struct {
	uint32_t magic_number;
	uint32_t api_version;
	void (*prog_get)(uint8_t *rot_data, volatile void *eb_ctrl);
	void (*prog_set)(uint8_t *rot_data, volatile void *eb_ctrl);
	void (*prog_enable)(volatile void *eb_ctrl);
	uint8_t (*prog_check)(volatile void *eb_ctrl);
	void (*debug_disable)(volatile void *eb_ctrl);
	uint8_t (*debug_check)(volatile void *eb_ctrl);
	void (*otp_set)(uint8_t *otp_data, volatile void *eb_ctrl);
	void (*otp_get)(uint8_t *otp_data, volatile void *eb_ctrl);
	uint8_t reserved[24];
} efuse_burn_ops_t;

#ifdef CONFIG_SAPPORO
#define EB_CTRL_BASE ((volatile void *)0x80100000)
#else
#define EB_CTRL_BASE ((volatile void *)0x80090000)
#endif

#define efuse_burn_ops ((efuse_burn_ops_t *)EFUSE_BURN_OPS_BASE)
#endif

/* Validate efuse_burn_ops structure (aligned with otp-agtx.h) */
static inline uint32_t check_ops_valid(efuse_burn_ops_t *ops)
{
	uint32_t *fp;
	int i;

	if (!ops)
		return AGTX_ERR_OPS_NOT_INIT;
	if (ops->magic_number != NVSPC_HEADER_MAGIC)
		return AGTX_ERR_OPS_INVALID_MAGIC;
	if (ops->api_version < NVSPC_API_VERSION)
		return AGTX_ERR_OPS_INVALID_VERSION;

	fp = (uint32_t *)&ops->prog_get;
	for (i = 0; i < EB_OPS_PTR_COUNT; i++)
		if (!IS_VALID_EB_OPS_PTR(fp[i]))
			return AGTX_ERR_PROG_GET_NULL + i;

	return 0;
}

/* ========================================================================== */
/* Core FSM Functions - Always Available */
/* ========================================================================== */
typedef efuse_fsm_result_t (*eb_state_handler_t)(efuse_fsm_context_t *ctx);

/* Core FSM API */
efuse_fsm_context_t *eb_fsm_get_context(void);
void eb_fsm_init(efuse_fsm_context_t *ctx);
void eb_fsm_reset(efuse_fsm_context_t *ctx);
int eb_fsm_start(void);
void eb_handle_error(efuse_fsm_context_t *ctx, uint32_t error_code, const char *description);
bool eb_is_terminal_state(efuse_fsm_state_t state);
void __weak eb_set_ng_signal(bool ng_status);
int eb_sdc_load_data(void);

/* ========================================================================== */
/* Core FSM Functions - Always Available */
/* ========================================================================== */

#endif /* __EFUSE_BURN_FSM_H__ */
