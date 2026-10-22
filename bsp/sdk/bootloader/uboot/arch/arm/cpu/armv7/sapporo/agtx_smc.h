/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __UBOOT_AGTX_SMC_H__
#define __UBOOT_AGTX_SMC_H__

#include <common.h>
#include <linux/arm-smccc.h>
#include <efuse_burn_fsm.h>

/* SMC Function IDs - synced with otp-agtx.h */
#define AUGENTIX_SIP_NVSPC_LOAD 0x82010000
#define AUGENTIX_SIP_EB_PROG_GET 0x82010001
#define AUGENTIX_SIP_EB_PROG_SET 0x82010002
#define AUGENTIX_SIP_EB_PROG_ENABLE 0x82010003
#define AUGENTIX_SIP_EB_PROG_CHECK 0x82010004
#define AUGENTIX_SIP_EB_DEBUG_DISABLE 0x82010005
#define AUGENTIX_SIP_EB_DEBUG_CHECK 0x82010006
#define AUGENTIX_SIP_EB_CLK_ENABLE 0x8201000B
#define AUGENTIX_SIP_EB_CLK_DISABLE 0x8201000C

/* Core Error Codes (only what we need for FSM layer) */
#define AUGENTIX_EB_SUCCESS				 	0x0         /* Success */

/* NVSPC Constants */
#define NVSPC_ENTRY                     0xFFE00800
#define NVSPC_ABI_BASE 0xFFE00860 /* SPL offset 0x60 */
#define NVSPC_MAGIC                     0x99272327
#define NVSPC_API_VERSION 0x00020000 /* v2.0.0 */
#define NVSPC_MAX_SIZE                  0x7800      /* 0xFFE00800 to 0xFFE08000 */
#define NVSPC_TEMP_BUFFER               0x00080000  /* use "UBOOT_END_ADDR" as SMC shared buffer */

/* SMC Data Size Constants */
#define ROT_SIZE 32
#define OTP_READ_SIZE 24
#define OTP_WRITE_SIZE 16

/* SMC Return Codes [sdk/kernel/optee_os_4.5.0/src/core/arch/arm/include/sm/optee_smc.h] */
#define OPTEE_SMC_RETURN_OK 0x0
#define OPTEE_SMC_RETURN_ETHREAD_LIMIT 0x1
#define OPTEE_SMC_RETURN_EBUSY 0x2
#define OPTEE_SMC_RETURN_ERESUME 0x3
#define OPTEE_SMC_RETURN_EBADADDR 0x4
#define OPTEE_SMC_RETURN_EBADCMD 0x5
#define OPTEE_SMC_RETURN_ENOMEM 0x6
#define OPTEE_SMC_RETURN_ENOTAVAIL 0x7

void eb_smc_nvspc_load(void *src, u32 size, struct arm_smccc_res *res);
void eb_smc_prog_get(uint8_t *rot_data, struct arm_smccc_res *res);
void eb_smc_prog_set(uint8_t *rot_data, struct arm_smccc_res *res);
void eb_smc_prog_enable(struct arm_smccc_res *res);
uint8_t eb_smc_prog_check(struct arm_smccc_res *res);
void eb_smc_debug_disable(struct arm_smccc_res *res);
uint8_t eb_smc_debug_check(struct arm_smccc_res *res);
void eb_smc_clk_enable(struct arm_smccc_res *res);
void eb_smc_clk_disable(struct arm_smccc_res *res);

#endif /* __UBOOT_AGTX_SMC_H__ */