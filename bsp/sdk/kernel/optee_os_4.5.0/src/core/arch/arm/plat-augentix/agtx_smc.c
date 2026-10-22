/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <arm.h>
#include <kernel/misc.h>
#include <mm/core_mmu.h>
#include <mm/core_mmu_arch.h>
#include <mm/core_memprot.h>
#include <mm/tee_mmu_types.h>
#include <kernel/cache_helpers.h>
#include <kernel/tlb_helpers.h>
#include <kernel/spinlock.h>
#include <arm32.h>
#include <platform_config.h>
#include <trace.h>
#include <sm/sm.h>
#include <sm/optee_smc.h>
#include <io.h>
#include <string.h>
#include <stdlib.h>
#include "agtx_smc.h"
#include <inttypes.h>

static efuse_burn_ops_t *g_eb_smc_ops = NULL;
static void *g_agtx_sram_base = NULL;
static void *g_nvspc_temp = NULL;
static void *eb_ctrl_vaddr = NULL;

static void *ck_base = NULL;
static void *chip_id_bak = NULL;

static bool check_idmap_valid(uint32_t *a0) {
    return check_id_mapping(a0, g_agtx_sram_base, SYSCONF_BASE, AGTX_ERR_MMU_SRAM_MAP_FAILED) &&
           check_id_mapping(a0, eb_ctrl_vaddr, EB_CONTROL_BASE, AGTX_ERR_MMU_EBMAP_FAILED) &&
           check_id_mapping(a0, ck_base, PLATFORM_CONTROL_BASE, AGTX_ERR_MMU_CKMAP_FAILED) &&
           check_id_mapping(a0, chip_id_bak, CHIPID_BACKUP, AGTX_ERR_MMU_CIDBAK_MAP_FAILED) &&
           check_id_mapping(a0, g_nvspc_temp, NVSPC_TEMP_BUFFER, AGTX_ERR_MMU_NVSPC_MAP_FAILED);
}

TEE_Result idmap_init(void)
{
#ifdef CFG_IDENTITY_MAPPING
	uint32_t err_code = 0;

	g_agtx_sram_base = core_mmu_add_id_mapping(MEM_AREA_TEE_COHERENT, SYSCONF_BASE, SYSRAM_MAX_SIZE);
	if (!check_id_mapping(&err_code, g_agtx_sram_base, SYSCONF_BASE, AGTX_ERR_MMU_SRAM_MAP_FAILED))
		return err_code;

	eb_ctrl_vaddr = core_mmu_add_id_mapping(MEM_AREA_IO_SEC, EB_CONTROL_BASE, SMALL_PAGE_SIZE);
	if (!check_id_mapping(&err_code, eb_ctrl_vaddr, EB_CONTROL_BASE, AGTX_ERR_MMU_EBMAP_FAILED))
		return err_code;

	ck_base = core_mmu_add_id_mapping(MEM_AREA_IO_SEC, PLATFORM_CONTROL_BASE, CORE_MMU_PGDIR_SIZE);
	if (!check_id_mapping(&err_code, ck_base, PLATFORM_CONTROL_BASE, AGTX_ERR_MMU_CKMAP_FAILED))
		return err_code;

	chip_id_bak = core_mmu_add_id_mapping(MEM_AREA_RAM_SEC, CHIPID_BACKUP, SMALL_PAGE_SIZE);
	if (!check_id_mapping(&err_code, chip_id_bak, CHIPID_BACKUP, AGTX_ERR_MMU_CIDBAK_MAP_FAILED))
		return err_code;


	g_nvspc_temp = core_mmu_add_id_mapping(MEM_AREA_RAM_NSEC, NVSPC_TEMP_BUFFER, NVSPC_MAX_SIZE);
	if (!check_id_mapping(&err_code, g_nvspc_temp, NVSPC_TEMP_BUFFER, AGTX_ERR_MMU_NVSPC_MAP_FAILED))
		return err_code;

	efuse_burn_ops_t *ops = (efuse_burn_ops_t *)NVSPC_ABI_BASE;
	if (ops->magic_number == NVSPC_MAGIC && ops->api_version == NVSPC_API_VERSION)
		g_eb_smc_ops = ops;

	return TEE_SUCCESS;
#else
	return TEE_ERROR_OUT_OF_MEMORY;
#endif
}

bool is_sysconf_mapped(void)
{
#ifdef CFG_IDENTITY_MAPPING
	return (g_agtx_sram_base != NULL && (vaddr_t)g_agtx_sram_base == SYSCONF_BASE);
#else
	return false;
#endif
}

static void cache_memcpy(void *dst, void *src, size_t size, int direction, buffer_type_t type)
{
	if (direction == 0) {
		cache_op_barrier(DCACHE_AREA_INVALIDATE, src, size);
		memcpy(dst, src, size);
	} else {
		memcpy(dst, src, size);
		cache_op_barrier(DCACHE_AREA_CLEAN, dst, size);
	}

	if (type == BUFFER_TYPE_NVSPC) {
		if (direction == 1) {
			cache_op_barrier(ICACHE_AREA_INVALIDATE, dst, size);
		} else {
			cache_op_barrier(DCACHE_AREA_CLEAN, dst, size);
			cache_op_barrier(ICACHE_AREA_INVALIDATE, dst, size);
		}
	}
}

static void agtx_wxn_control(bool enable)
{
	uint32_t sctlr = read_sctlr();

	if (enable)
		sctlr &= ~(SCTLR_WXN | SCTLR_UWXN);
	else
		sctlr |= (SCTLR_WXN | SCTLR_UWXN);

	write_sctlr(sctlr);
	tlbi_all();
	isb();
}

static enum sm_handler_ret eb_smc_debug_disable(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;

	g_eb_smc_ops->debug_disable(eb_ctrl_vaddr);
	ops_barrier();

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_debug_check(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint8_t dis_debug = io_read8((vaddr_t)g_agtx_sram_base + CONF_OFS_DIS_DEBUG);
	uint8_t result = (dis_debug == 0) ? g_eb_smc_ops->debug_check(eb_ctrl_vaddr) : dis_debug;

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	nsec_r0[1] = result;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_prog_get(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint8_t rot_data[ROT_SIZE] = {0};

	g_eb_smc_ops->prog_get(rot_data, eb_ctrl_vaddr);
	cache_memcpy(g_nvspc_temp, rot_data, ROT_SIZE, 1, BUFFER_TYPE_ROT);

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_prog_set(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint8_t rot_data[ROT_SIZE] = {0};

	cache_memcpy(rot_data, g_nvspc_temp, ROT_SIZE, 0, BUFFER_TYPE_ROT);
	g_eb_smc_ops->prog_set(rot_data, eb_ctrl_vaddr);
	ops_barrier();

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_prog_get_linux(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint32_t offset = nsec_r0[1];
	uint8_t rot_data[ROT_SIZE] = { 0 };

	if (offset != 0 && offset != 16)
		return SM_HANDLER_SMC_HANDLED;

	g_eb_smc_ops->prog_get(rot_data, eb_ctrl_vaddr);

	uint8_t *src = &rot_data[offset ? 16 : 0];
	nsec_r0[0] = *((uint32_t *)&src[0]);
	nsec_r0[1] = *((uint32_t *)&src[4]);
	nsec_r0[2] = *((uint32_t *)&src[8]);
	nsec_r0[3] = *((uint32_t *)&src[12]);

	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_prog_set_linux(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint32_t offset = nsec_r0[1];
	static uint8_t rot_data[ROT_SIZE] = { 0 };

	if (offset != 0 && offset != 16)
		return SM_HANDLER_SMC_HANDLED;

	uint8_t *dst = &rot_data[offset ? 16 : 0];
	*((uint32_t *)&dst[0]) = nsec_r0[2];
	*((uint32_t *)&dst[4]) = nsec_r0[3];
	*((uint32_t *)&dst[8]) = nsec_r0[4];
	*((uint32_t *)&dst[12]) = nsec_r0[5];

	if (offset) {
		g_eb_smc_ops->prog_set(rot_data, eb_ctrl_vaddr);
		ops_barrier();
		memset(rot_data, 0, ROT_SIZE);
	}

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_prog_enable(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;

	g_eb_smc_ops->prog_enable(eb_ctrl_vaddr);
	ops_barrier();

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_prog_check(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint8_t sec_boot = io_read8((vaddr_t)g_agtx_sram_base + CONF_OFS_SEC_BOOT);
	uint8_t result = (sec_boot == 0) ? g_eb_smc_ops->prog_check(eb_ctrl_vaddr) : (sec_boot == 3 || sec_boot == 5);

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	nsec_r0[1] = result;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_otp_get(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint32_t otp_type = nsec_r0[1];
	uint32_t data[4] = { 0 };
	int i;

	if (otp_type == OTP_TYPE_VENDOR_ID) {
		uint8_t sram_data[8] = { 0 };
		cache_memcpy(sram_data, (void *)SYSCONF_BASE, 8, 0, BUFFER_TYPE_OTP_R);

		nsec_r0[0] = OPTEE_SMC_RETURN_OK;
		nsec_r0[1] = *((uint32_t *)&sram_data[0]);
		nsec_r0[2] = *((uint32_t *)&sram_data[4]);
		nsec_r0[3] = 0;
	} else if (otp_type == OTP_TYPE_READ_USER) {
		for (i = 0; i < 4; i++)
			data[i] = io_read32((vaddr_t)g_agtx_sram_base + CONF_OFS_HUK + i * 4);

		if ((data[0] | data[1] | data[2] | data[3]) == 0) {
			uint8_t otp_data[OTP_SIZE] = { 0 };
			g_eb_smc_ops->otp_get(otp_data, eb_ctrl_vaddr);
			for (i = 0; i < 4; i++)
				data[i] = *((uint32_t *)&otp_data[i * 4]);
		}

		for (i = 0; i < 4; i++)
			nsec_r0[i] = data[i];
	}

	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_otp_set(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint8_t otp_data[OTP_SIZE] = {0};

	*((uint32_t *)&otp_data[0]) = nsec_r0[2];
	*((uint32_t *)&otp_data[4]) = nsec_r0[3];
	*((uint32_t *)&otp_data[8]) = nsec_r0[4];
	*((uint32_t *)&otp_data[12]) = nsec_r0[5];

	g_eb_smc_ops->otp_set(otp_data, eb_ctrl_vaddr);
	ops_barrier();

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_nvspc_load(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint32_t size = nsec_r0[2];

	/* SPL built-in efuse ops already available */
	if (g_eb_smc_ops != NULL) {
		DMSG("[efuse_burn_ops] SPL build-in ABI v%u.%u", (g_eb_smc_ops->api_version >> 16) & 0xFFFF,
		     g_eb_smc_ops->api_version & 0xFFFF);
		nsec_r0[0] = OPTEE_SMC_RETURN_OK;
		nsec_r0[1] = g_eb_smc_ops->api_version;
		return SM_HANDLER_SMC_HANDLED;
	}

	/* Query mode (size=0): check if ops exist, return error if not */
	if (size == 0) {
		nsec_r0[0] = AGTX_ERR_OPS_NOT_INIT;
		return SM_HANDLER_SMC_HANDLED;
	}

	/* Load nvspc.bin from shared buffer */
	cache_memcpy((void *)NVSPC_ENTRY, g_nvspc_temp, size, 0, BUFFER_TYPE_NVSPC);
	memset(g_nvspc_temp, 0, size);

	g_eb_smc_ops = (efuse_burn_ops_t *)(NVSPC_ABI_BASE);
	uint32_t ops_err = check_ops_valid(g_eb_smc_ops);
	if (ops_err) {
		nsec_r0[0] = ops_err;
		g_eb_smc_ops = NULL;
		return SM_HANDLER_SMC_HANDLED;
	}

	DMSG("[efuse_burn_ops] nvspc.bin v%u.%u", (g_eb_smc_ops->api_version >> 16) & 0xFFFF,
	     g_eb_smc_ops->api_version & 0xFFFF);
	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	nsec_r0[1] = g_eb_smc_ops->api_version;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_clk_enable(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint32_t val = io_read32((vaddr_t)ck_base + CG_SYS_OFS);

	if (!(val & (1U << CG_SYS_EB_CLK_BIT))) {
		val |= (1U << CG_SYS_EB_CLK_BIT);
		io_write32((vaddr_t)ck_base + CG_SYS_OFS, val);
		ops_barrier();
	}

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	return SM_HANDLER_SMC_HANDLED;
}

static enum sm_handler_ret eb_smc_clk_disable(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)&ctx->nsec.r0;
	uint32_t val = io_read32((vaddr_t)ck_base + CG_SYS_OFS);

	if (val & (1U << CG_SYS_EB_CLK_BIT)) {
		val &= ~(1U << CG_SYS_EB_CLK_BIT);
		io_write32((vaddr_t)ck_base + CG_SYS_OFS, val);
		ops_barrier();
	}

	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	return SM_HANDLER_SMC_HANDLED;
}

#if defined(CFG_SM_PLATFORM_SUSPEND)
extern int augentix_sram_resume(unsigned long par1, unsigned long par2, unsigned long par3);
extern enum sm_handler_ret agtx_smc_aov_handler(struct sm_ctx *ctx); 

enum sm_handler_ret agtx_smc_aov_handler(struct sm_ctx *ctx)
{
        uint32_t *nsec_r0 = (uint32_t *)(&ctx->nsec.r0);
        uint8_t *sram_dst = (uint8_t *)(SYSCONF_BASE + 0x800);
        int (*sram_fn)(unsigned long, unsigned long, unsigned long);
        uint32_t sctlr_val;
	
	/* === Compute aon_va for both SMC-path fallback + SRAM === */
	
	vaddr_t aon_va;
	{
		struct io_pa_va aon_pv = { .pa = 0x80300408, .va = 0 };
		aon_va = (vaddr_t)io_pa_or_va(&aon_pv, CORE_MMU_PGDIR_SIZE);
	}
	vaddr_t dphy_va;
	{
		struct io_pa_va dphy_pv = { .pa = 0x81840000, .va = 0 };
		dphy_va = (vaddr_t)io_pa_or_va(&dphy_pv, CORE_MMU_PGDIR_SIZE);
	}
	vaddr_t pc_va;
	{
		struct io_pa_va pc_pv  = { .pa = 0x80000000, .va = 0 };
		pc_va = (vaddr_t)io_pa_or_va(&pc_pv, CORE_MMU_PGDIR_SIZE);
	}

	/* === SMC-path AON gate (known working) === */
	
	asm volatile("dsb" ::: "memory");
	
	/* === wxn(true): expand inline === */

	sctlr_val = read_sctlr();
	sctlr_val &= ~(SCTLR_WXN | SCTLR_UWXN);
	write_sctlr(sctlr_val);
        tlbi_all();
        isb();
        
	/* cache_memcpy: MUST clear Thumb bit from src (memcpy reads bytes, not executes) */

	cache_memcpy(sram_dst, (void *)((uintptr_t)augentix_sram_resume & ~(uintptr_t)1), 4096, 0, BUFFER_TYPE_NVSPC);
	
        /* === Calculate sram_fn (KEEP Thumb bit for blx) === */

        sram_fn = (int (*)(unsigned long, unsigned long, unsigned long))
                  ((uintptr_t)sram_dst | ((uintptr_t)augentix_sram_resume & 1));    

	/* === blx to SRAM (pass va) === */
	{
		uint8_t *sram_stack_top = sram_dst + 4096 + 4096;

		asm volatile("mov r4, sp\n"
		             "mov sp, %0\n"
		             "mov r0, %2\n"
		             "mov r1, %3\n"
		             "mov r2, %4\n"
		             "blx %1\n"
		             "mov sp, r4\n"
		             :
		             : "r"(sram_stack_top), "r"(sram_fn), "r"(aon_va), "r"(dphy_va), "r"(pc_va)
		             : "r0", "r1", "r2", "r3", "r4", "lr", "memory");
	}
	/* back from SRAM Code */	
    /* === wxn(false): expand inline === */

        sctlr_val = read_sctlr();
        sctlr_val |= (SCTLR_WXN | SCTLR_UWXN);
        write_sctlr(sctlr_val);
        tlbi_all();
        isb();
        
	/* === Return === */
	nsec_r0[0] = OPTEE_SMC_RETURN_OK;
	
        return SM_HANDLER_SMC_HANDLED;

}
#endif /* CFG_SM_PLATFORM_SUSPEND */

static enum sm_handler_ret agtx_sip_handler(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)(&ctx->nsec.r0);
	uint32_t smc_fid;
	uint16_t sip_func;
	enum sm_handler_ret result;

	if (!check_idmap_valid(nsec_r0))
		return SM_HANDLER_SMC_HANDLED;

	smc_fid = *nsec_r0;
	sip_func = OPTEE_SMC_FUNC_NUM(smc_fid);
	if (!check_smc_para_valid(ctx, sip_func))
		return SM_HANDLER_SMC_HANDLED;

	if (IS_EB_OPS(sip_func)) {
		uint32_t ops_err = check_ops_valid(g_eb_smc_ops);
		if (ops_err) {
			nsec_r0[0] = ops_err;
			return SM_HANDLER_SMC_HANDLED;
		}
		agtx_wxn_control(true);
	}

	switch (sip_func) {
	case 0x0000:
		return eb_smc_nvspc_load(ctx);
	case 0x0001:
		result = eb_smc_prog_get(ctx);
		break;
	case 0x0002:
		result = eb_smc_prog_set(ctx);
		break;
	case 0x0009:
		result = eb_smc_prog_get_linux(ctx);
		break;
	case 0x000A:
		result = eb_smc_prog_set_linux(ctx);
		break;
	case 0x0003:
		result = eb_smc_prog_enable(ctx);
		break;
	case 0x0004:
		result = eb_smc_prog_check(ctx);
		break;
	case 0x0005:
		result = eb_smc_debug_disable(ctx);
		break;
	case 0x0006:
		result = eb_smc_debug_check(ctx);
		break;
	case 0x0007:
		result = eb_smc_otp_set(ctx);
		break;
	case 0x0008:
		result = eb_smc_otp_get(ctx);
		break;
	case 0x000B:
		return eb_smc_clk_enable(ctx);
	case 0x000C:
		return eb_smc_clk_disable(ctx);
#if defined(CFG_SM_PLATFORM_SUSPEND)
	case 0x000D:
		return agtx_smc_aov_handler(ctx);
#endif		
	default:
		nsec_r0[0] = OPTEE_SMC_RETURN_EBADCMD;
		result = SM_HANDLER_SMC_HANDLED;
		break;
	}

	if (IS_EB_OPS(sip_func))
		agtx_wxn_control(false);

	return result;
}

enum sm_handler_ret sm_platform_handler(struct sm_ctx *ctx)
{
	uint32_t *nsec_r0 = (uint32_t *)(&ctx->nsec.r0);
	uint16_t smc_owner;

	smc_owner = OPTEE_SMC_OWNER_NUM(*nsec_r0);

	switch (smc_owner) {
	case OPTEE_SMC_OWNER_SIP:
		return agtx_sip_handler(ctx);
	default:
		return SM_HANDLER_PENDING_SMC;
	}
}

enum sm_handler_ret sm_platform_handler_from_sec(struct sm_ctx *ctx)
{
	uint32_t saved[8];
	uint32_t *nsec_r = (uint32_t *)&ctx->nsec.r0;
	uint32_t *sec_r = (uint32_t *)&ctx->sec.r0;
	enum sm_handler_ret ret;

	memcpy(saved, nsec_r, sizeof(saved));
	memcpy(nsec_r, sec_r, sizeof(saved));

	ret = sm_platform_handler(ctx);

	memcpy(sec_r, nsec_r, 4 * sizeof(uint32_t));
	memcpy(nsec_r, saved, sizeof(saved));

	return ret;
}
