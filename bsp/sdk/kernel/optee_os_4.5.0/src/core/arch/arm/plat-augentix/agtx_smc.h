/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __OPTEE_AGTX_SMC_H__
#define __OPTEE_AGTX_SMC_H__

#include <tee_api_types.h>
#include <tee_api_defines.h>
#include <sm/sm.h>
#include <sm/optee_smc.h>

typedef enum { BUFFER_TYPE_ROT = 0, BUFFER_TYPE_OTP_R = 1, BUFFER_TYPE_OTP_W = 2, BUFFER_TYPE_NVSPC = 3 } buffer_type_t;

typedef struct {
	uint32_t magic_number;
	uint32_t api_version;
	void (*prog_get)(uint8_t *, volatile void *);
	void (*prog_set)(uint8_t *, volatile void *);
	void (*prog_enable)(volatile void *);
	uint8_t (*prog_check)(volatile void *);
	void (*debug_disable)(volatile void *);
	uint8_t (*debug_check)(volatile void *);
	void (*otp_set)(uint8_t *, volatile void *);
	void (*otp_get)(uint8_t *, volatile void *);
	uint32_t reserved[6];
} __attribute__((aligned(4))) efuse_burn_ops_t;

TEE_Result idmap_init(void);
bool is_sysconf_mapped(void);

#define NVSPC_ENTRY                     	0xFFE00800
#define NVSPC_ABI_BASE 0xFFE00860
#define NVSPC_MAGIC                     	0x99272327
#define NVSPC_API_VERSION 0x00020000
#define NVSPC_MAX_SIZE 0x7800
#define NVSPC_TEMP_BUFFER 0x00080000

/* NVSPC ABI — SPL efuse ops validation (aligned with otp-agtx.h) */
#define SPL_CODE_START 0xFFE00868
#define SPL_CODE_END 0xFFE07000
#define IS_VALID_EB_OPS_PTR(ptr) ((uint32_t)(ptr) >= SPL_CODE_START && (uint32_t)(ptr) < SPL_CODE_END)
#define EB_OPS_PTR_COUNT 8

#define ROT_SIZE                            32
#define OTP_SIZE                   			16
#define OTP_READ_ID_SIZE         			8
#define SMC_OTP_READ_SIZE            		(OTP_SIZE + OTP_READ_ID_SIZE)
#define OTP_TYPE_VENDOR_ID             		0x0
#define OTP_TYPE_READ_USER		 			0x1
#define OTP_TYPE_WRITE_USER		 			0x2

#define CONF_OFS_CHIP_ID 0
#define CONF_OFS_CUSTOM_ID 1
#define CONF_OFS_SEC_BOOT 2
#define CONF_OFS_CPU_CLK_RATE 3
#define CONF_OFS_EMMC_CLK_RATE 4
#define CONF_OFS_DIS_TRUSTZONE 5
#define CONF_OFS_DIS_DEBUG 6
#define CONF_OFS_RESERVED 7
#define CONF_OFS_HUK 8

#define IS_EB_OPS(func_id) ((func_id) >= 0x0001 && (func_id) <= 0x000A)
#define AUGENTIX_SIP_NVSPC_LOAD 0x82010000
#define AUGENTIX_SIP_EB_PROG_GET        	0x82010001
#define AUGENTIX_SIP_EB_PROG_SET        	0x82010002
#define AUGENTIX_SIP_EB_PROG_ENABLE     	0x82010003
#define AUGENTIX_SIP_EB_PROG_CHECK      	0x82010004
#define AUGENTIX_SIP_EB_DEBUG_DISABLE   	0x82010005
#define AUGENTIX_SIP_EB_DEBUG_CHECK     	0x82010006
#define AUGENTIX_SIP_EB_OTP_SET         	0x82010007
#define AUGENTIX_SIP_EB_OTP_GET         	0x82010008
#define AUGENTIX_SIP_EB_PROG_GET_LINUX 0x82010009
#define AUGENTIX_SIP_EB_PROG_SET_LINUX 0x8201000A
#define AUGENTIX_SIP_EB_CLK_ENABLE 0x8201000B
#define AUGENTIX_SIP_EB_CLK_DISABLE 0x8201000C

#define CG_SYS_OFS 0x14
#define CG_SYS_EB_CLK_BIT 0

#define AGTX_ERR_MMU_SRAM_MAP_FAILED 0xFEFEFE01
#define AGTX_ERR_MMU_NVSPC_MAP_FAILED 0xFEFEFE02
#define AGTX_ERR_MMU_CKMAP_FAILED 0xFEFEFE03
#define AGTX_ERR_MMU_EBMAP_FAILED 0xFEFEFE04
#define AGTX_ERR_MMU_CIDBAK_MAP_FAILED 0xFEFEFE05

#define AGTX_ERR_OPS_NOT_INIT 0xFEFEFE10
#define AGTX_ERR_OPS_INVALID_MAGIC      	0xFEFEFE11
#define AGTX_ERR_OPS_INVALID_VERSION    	0xFEFEFE12
#define AGTX_ERR_PROG_GET_NULL          	0xFEFEFE13
#define AGTX_ERR_PROG_SET_NULL          	0xFEFEFE14
#define AGTX_ERR_PROG_ENABLE_NULL       	0xFEFEFE15
#define AGTX_ERR_PROG_CHECK_NULL        	0xFEFEFE16
#define AGTX_ERR_DEBUG_DISABLE_NULL     	0xFEFEFE17
#define AGTX_ERR_DEBUG_CHECK_NULL       	0xFEFEFE18
#define AGTX_ERR_OTP_SET_NULL           	0xFEFEFE19
#define AGTX_ERR_OTP_GET_NULL           	0xFEFEFE1A
#define AGTX_ERR_NVSPC_SA_INVALID 0xFEFEFE22
#define AGTX_ERR_ROT_SA_INVALID 0xFEFEFE23
#define AGTX_ERR_NVSPC_SIZE_INVALID 0xFEFEFE25
#define AGTX_ERR_ROT_SIZE_INVALID 0xFEFEFE26
#define AGTX_ERR_OTP_INVALID_OPERATION 0xFEFEFE28

#define ops_barrier() do { dsb(); isb(); } while(0)

static void cache_op_barrier(uint32_t op, void *addr, size_t size)
{
	dsb();
	cache_op_inner(op, addr, size);
	dsb();
	if (op == ICACHE_AREA_INVALIDATE) isb();
}

static inline uint32_t check_ops_valid(efuse_burn_ops_t *ops)
{
	uint32_t *fp;
	int i;

	if (!ops)
		return AGTX_ERR_OPS_NOT_INIT;
	if (ops->magic_number != NVSPC_MAGIC)
		return AGTX_ERR_OPS_INVALID_MAGIC;
	if (ops->api_version < NVSPC_API_VERSION)
		return AGTX_ERR_OPS_INVALID_VERSION;

	fp = (uint32_t *)&ops->prog_get;
	for (i = 0; i < EB_OPS_PTR_COUNT; i++)
		if (!IS_VALID_EB_OPS_PTR(fp[i]))
			return AGTX_ERR_PROG_GET_NULL + i;

	return 0;
}

static inline bool check_id_mapping(uint32_t *a0, void *ptr, paddr_t expected_pa, uint32_t err_code) {
    if (!ptr || (vaddr_t)ptr != expected_pa) {
        *a0 = err_code;
        return false;
    }
    return true;
}

static inline bool check_smc_para_valid(struct sm_ctx *ctx, uint16_t sip_func) {
    uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;

    switch (sip_func) {
    case 0x0000:
	    /* size=0 is a query to check if SPL efuse ops already exist */
	    if (nsec_r0[2] == 0)
		    return true;
	    if (nsec_r0[1] != NVSPC_TEMP_BUFFER) {
		    *nsec_r0 = AGTX_ERR_NVSPC_SA_INVALID;
		    return false;
	    }
	    if (nsec_r0[2] > NVSPC_MAX_SIZE) {
		    *nsec_r0 = AGTX_ERR_NVSPC_SIZE_INVALID;
		    return false;
	    }
	    return true;

    case 0x0001:
    case 0x0002:
	    if (nsec_r0[1] != NVSPC_TEMP_BUFFER) {
		    *nsec_r0 = AGTX_ERR_ROT_SA_INVALID;
		    return false;
	    }
	    if (nsec_r0[2] != ROT_SIZE) {
		    *nsec_r0 = AGTX_ERR_ROT_SIZE_INVALID;
		    return false;
	    }
	    return true;

    case 0x0009:
    case 0x000A:
	    if (nsec_r0[1] != 0 && nsec_r0[1] != 16) {
		    *nsec_r0 = AGTX_ERR_ROT_SA_INVALID;
		    return false;
	    }
	    return true;

    case 0x0007:
	    if (nsec_r0[1] != OTP_TYPE_WRITE_USER) {
		    *nsec_r0 = AGTX_ERR_OTP_INVALID_OPERATION;
		    return false;
	    }
	    return true;

    case 0x0008:
	    if (nsec_r0[1] != OTP_TYPE_VENDOR_ID && nsec_r0[1] != OTP_TYPE_READ_USER) {
		    *nsec_r0 = AGTX_ERR_OTP_INVALID_OPERATION;
		    return false;
	    }
	    return true;

    case 0x0003:
    case 0x0004:
    case 0x0005:
    case 0x0006:
    case 0x000B:
    case 0x000C:
#if defined(CFG_SM_PLATFORM_SUSPEND)
    case 0x000D:
#endif
	    return true;

    default:
        *nsec_r0 = OPTEE_SMC_RETURN_EBADCMD;
        return false;
    }
}

#endif /* __OPTEE_AGTX_SMC_H__ */
