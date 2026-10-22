/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <tee_api_defines.h>
#include <drivers/spi/agtx_spi.h>
#include <drivers/spi/agtx_spi_nand.h>
#include <drivers/spi/flash_protect.h>
#include <trace.h>
#include <drivers/agtx_mono_cnt.h>
#include <kernel/panic.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define CNT_SIZE 4
#define SHADOW_CNT_SIZE 8
#if defined(CFG_FLASH_NOR)
#define FLASH_ERASE_UNIT 0x1000
#elif defined(CFG_FLASH_NAND)
#define FLASH_ERASE_UNIT 0x20000
#endif /* defined(CFG_FLASH_NOR) */
#define ERASED_VAL 0xFFFFFFFF

static uint32_t protected_cnts[CFG_NUMBER_OF_CNTS];
struct shadow_cnt {
	uint32_t id;
	uint32_t val;
};

/* Use union to avoid strict aliasing warnings. */
union slot_counter {
	struct {
		uint32_t boot_time : 2; // 2-bit for boot time counting, increase by SPL while boot_success not set.
		uint32_t boot_success : 1; // 1-bit marking boot success, set by optee_os.
		/* set by step-2 or step-4.1.1, changing boot_slot must clear the value of
		 * boot_time and boot_success.
		 */
		uint32_t boot_slot : 1;
		uint32_t reserved : 28; // nothing, increaed when boot_slot 1 -> 0.
	} cnt;
	uint32_t val;
};

static uint32_t cur_wr_addr;

static inline uint32_t get_protect_base(void)
{
	const struct fp_flash_info *selected_flash_info = get_selected_flash_info();
	return selected_flash_info->capacity - selected_flash_info->fp_size;
}

uint32_t cnt_get(uint32_t cnt_id)
{
	return (cnt_id >= CFG_NUMBER_OF_CNTS) ? 0 : protected_cnts[cnt_id];
}

#if defined(CFG_FLASH_NOR)
static TEE_Result cnts_restore_to_shadow(void)
{
	TEE_Result ret = TEE_SUCCESS;
	struct shadow_cnt cnts[CFG_NUMBER_OF_CNTS];
	uint32_t wr_size = SHADOW_CNT_SIZE * CFG_NUMBER_OF_CNTS;
	uint32_t i;

	for (i = 0; i < CFG_NUMBER_OF_CNTS; ++i) {
		cnts[i].id = i;
		cnts[i].val = protected_cnts[i];
	}
	ret = fp_write(cnts, cur_wr_addr, wr_size);
	if (ret == TEE_SUCCESS)
		cur_wr_addr += wr_size;

	return ret;
}

static TEE_Result cnt_update_shadow(struct shadow_cnt *new_cnt)
{
	TEE_Result ret;
	uint32_t protected_base = get_protect_base();
	uint32_t shadow_base = protected_base - FLASH_ERASE_UNIT;

	/* Ensure that at least four shadow counter slots remain writable, as SPL
	 * may write up to four times (setting boot\_time to 1, 2, 3, and updating
	 * boot_slot once).
	 */
	if (cur_wr_addr + (SHADOW_CNT_SIZE << 2) >= protected_base) {
		ret = fp_erase(shadow_base, FLASH_ERASE_UNIT);
		if (ret != TEE_SUCCESS) {
			EMSG("Failed to erase a fully written shadow area.\n");
			goto out;
		}

		cur_wr_addr = shadow_base;

		/* Restore all counters to shadow block for next reboot update */
		ret = cnts_restore_to_shadow();
		goto out;
	}

	ret = fp_write(new_cnt, cur_wr_addr, SHADOW_CNT_SIZE);
	if (ret == TEE_SUCCESS)
		cur_wr_addr += SHADOW_CNT_SIZE;
out:
	return ret;
}
#endif /* CFG_FLASH_NOR */

#if defined(CFG_FLASH_NAND)
static TEE_Result cnt_update_shadow(struct shadow_cnt *new_cnt __attribute__((unused)))
{
	TEE_Result ret = TEE_ERROR_GENERIC;
	struct shadow_cnt cnts[CFG_NUMBER_OF_CNTS];
	uint32_t shadow_base = cur_wr_addr & ~(NAND_FLASH_BLOCK_SIZE - 1);
	uint32_t i;

	/* Ensure that at least four shadow counter slots remain writable, as SPL
	 * may write up to four times (setting boot\_time to 1, 2, 3, and updating
	 * boot_slot once).
	 */
	if (cur_wr_addr + (NAND_FLASH_PAGE_SIZE << 2) >= shadow_base + NAND_FLASH_BLOCK_SIZE) {
		DMSG("Erasing full shadow block: cur_wr_addr=%#x, shadow_base=%#x\n", cur_wr_addr, shadow_base);
		ret = fp_erase(shadow_base, FLASH_ERASE_UNIT);
		if (ret != TEE_SUCCESS) {
			EMSG("Failed to erase fully written block\n");
			goto out;
		}
		cur_wr_addr = shadow_base;
	}

	/* Update shadow block */
	for (i = 0; i < CFG_NUMBER_OF_CNTS; ++i) {
		cnts[i].id = i;
		cnts[i].val = protected_cnts[i];
	}
	DMSG("Set cnt to %#x\n", cur_wr_addr);
	ret = fp_write(&cnts, cur_wr_addr, SHADOW_CNT_SIZE * CFG_NUMBER_OF_CNTS);
	if (ret != TEE_SUCCESS) {
		EMSG("Failed to set counter\n");
		goto out;
	}
	cur_wr_addr += NAND_FLASH_PAGE_SIZE;
out:
	return ret;
}
#endif /* CFG_FLASH_NAND */

TEE_Result cnt_set(uint32_t cnt_id, uint32_t cnt_val)
{
	TEE_Result ret = TEE_ERROR_GENERIC;
	struct shadow_cnt new_cnt __attribute__((unused)) = { cnt_id, cnt_val };

	/* Check if the ID is legal. */
	if (cnt_id >= CFG_NUMBER_OF_CNTS) {
		EMSG("Attempt to set counter with unsupported counter type.");
		goto err_bad_param;
	}

	/* Check if the new counter is not outdated. */
	if (cnt_val < protected_cnts[cnt_id]) {
		EMSG("Attempt to set an outdated counter version.\n");
		goto err_bad_param;
	} else if (cnt_val == protected_cnts[cnt_id]) {
		return TEE_SUCCESS;
	}

	agtx_set_spi_lock_flag();

	/* Update shadow block. */
	protected_cnts[cnt_id] = cnt_val;
	ret = cnt_update_shadow(&new_cnt);
	if (ret != TEE_SUCCESS) {
		EMSG("Failed to set counter.\n");
		goto err_unknown;
	}

	agtx_unset_spi_lock_flag();

	return ret;
err_unknown:
	/* Unmask IRQ */
	agtx_show_spi_csr_status();
	agtx_unset_spi_lock_flag();
	return ret;
err_bad_param:
	return TEE_ERROR_BAD_PARAMETERS;
}

static bool tee_ver_check(void)
{
	bool ret = false;
	union slot_counter slot_cnt;
	slot_cnt.val = protected_cnts[TEE_SLOT_CNT];

#if defined(CFG_TEE_ANTI_ROLLBACK)
	/* Ensure the TEE version counter stored in image is bigger than the
	 * counter stored in protected/shadow block
	 */
	if (CFG_TEE_VERSION < protected_cnts[TEE_VER_CNT]) {
		EMSG("Attempt to use an outdated version of TEE.");
		panic();
	}
#endif // CFG_TEE_ANTI_ROLLBACK

	/* Suppress "comparison of unsigned expression in '< 0' is always false" warning */
#if CFG_TEE_VERSION > 0
	if (CFG_TEE_VERSION > protected_cnts[TEE_VER_CNT]) {
		protected_cnts[TEE_VER_CNT] = CFG_TEE_VERSION;
		ret = true;
	}
#endif

	/* Update the boot_success field of slot counter if it is not set */
	if (slot_cnt.cnt.boot_success == 0) {
		slot_cnt.cnt.boot_time = 0;
		slot_cnt.cnt.boot_success = 1;
		protected_cnts[TEE_SLOT_CNT] = slot_cnt.val;
		ret = true;
	}

	return ret;
}

#if defined(CFG_FLASH_NOR)
static TEE_Result update_from_shadow(bool *update_flag)
{
	struct shadow_cnt rd_cnts[16];
	TEE_Result ret = TEE_SUCCESS;
	uint32_t protected_base;
	uint32_t shadow_base;
	uint32_t rd_addr;
	uint32_t rd_size;
	uint32_t i;

	protected_base = get_protect_base();
	shadow_base = protected_base - FLASH_ERASE_UNIT;
	rd_addr = shadow_base;
	rd_size = SHADOW_CNT_SIZE * 16;
	cur_wr_addr = rd_addr;
	while (rd_addr < protected_base) {
		ret = fp_read(&rd_cnts, rd_addr, rd_size);

		if (ret != TEE_SUCCESS) {
			EMSG("Read shadow counters failed\n");
			goto out;
		}

		/* Retrieve the newest cnt */
		for (i = 0; i < 16; ++i) {
			/* If both id and cnt are 0xFFFFFFFF, it indicates that all cnts 
			 * in the shadow have been read.
			 */
			if (rd_cnts[i].id == ERASED_VAL && rd_cnts[i].val == ERASED_VAL)
				return TEE_SUCCESS;

			/* Counter ID should not bigger than number of counters. If a
			 * counter ID greater than CFG_NUMBER_OF_CNTS is detected, it
			 * indicates that the shadow block is corrupted and needs to be
			 * erased.
			 */
			if (rd_cnts[i].id >= CFG_NUMBER_OF_CNTS) {
				EMSG("Shadow block corruption detected, initiating erase operation.\n");
				ret = fp_erase(shadow_base, FLASH_ERASE_UNIT);

				if (ret != TEE_SUCCESS)
					EMSG("Erase shadow block failed\n");
				else
					cur_wr_addr = shadow_base;

				goto out;
			}

			/* Record the final cnt to be set */
			if (protected_cnts[rd_cnts[i].id] < rd_cnts[i].val) {
				protected_cnts[rd_cnts[i].id] = rd_cnts[i].val;
				*update_flag = true;
			}

			cur_wr_addr += SHADOW_CNT_SIZE;
		}
		rd_addr += rd_size;
	}
out:
	return ret;
}
#endif /* defined(CFG_FLASH_NOR) */

#if defined(CFG_FLASH_NAND)
static TEE_Result update_from_shadow(bool *update_flag)
{
	const struct fp_flash_info *selected_flash_info = get_selected_flash_info();
	struct shadow_cnt rd_cnts[CFG_NUMBER_OF_CNTS];
	TEE_Result ret = TEE_SUCCESS;
	uint32_t protected_base;
	uint32_t shadow_base;
	uint32_t rd_addr;
	uint32_t rd_size;
	uint32_t i;
	int32_t left = 0;
	int32_t right = (1 << PAGES_OFFSET_64) - 1;
	int32_t mid;
	int32_t page_idx = -1;
	bool had_programmed = false;

	protected_base = get_protect_base();
	shadow_base = protected_base - selected_flash_info->fp_size;
	rd_size = SHADOW_CNT_SIZE * CFG_NUMBER_OF_CNTS;

	/* Binary search the first un-programmed page */
	while (left <= right) {
		had_programmed = false;
		mid = left + ((right - left) >> 1);
		rd_addr = shadow_base + NAND_FLASH_PAGE_SIZE * mid;

		/* Check if the mid-th page has been programmed */
		ret = fp_read(&rd_cnts, rd_addr, rd_size);
		if (ret != TEE_SUCCESS) {
			EMSG("Read shadow counters failed\n");
			goto err_unknown;
		}

		if (rd_cnts[0].id != ERASED_VAL || rd_cnts[0].val != ERASED_VAL) {
			had_programmed = true;
			left = mid + 1;
		} else {
			page_idx = mid;
			right = mid - 1;
		}
	}

	/* Case all pages in shadow block are programmed */
	if (page_idx == -1) {
		rd_addr = shadow_base + NAND_FLASH_PAGE_SIZE * ((1 << PAGES_OFFSET_64) - 1);
	} else if (page_idx == 0 && had_programmed == false) {
		/* Case all pages in shadow block are not programmed */
		cur_wr_addr = shadow_base;
		goto out;
	} else {
		rd_addr = shadow_base + NAND_FLASH_PAGE_SIZE * (page_idx - 1);
	}

	/* Get latest shadow counters */
	ret = fp_read(&rd_cnts, rd_addr, rd_size);
	if (ret != TEE_SUCCESS) {
		EMSG("Read shadow counters failed\n");
		goto err_unknown;
	}

	/* Update from shadow counters */
	for (i = 0; i < CFG_NUMBER_OF_CNTS; ++i) {
		if (rd_cnts[i].id == ERASED_VAL && rd_cnts[i].val == ERASED_VAL) {
			rd_cnts[i].id = i;
			rd_cnts[i].val = 0;
		}
		/* Counter ID should not bigger than number of counters. */
		if (rd_cnts[i].id >= CFG_NUMBER_OF_CNTS) {
			EMSG("Shadow block corruption detected, initiating erase operation.\n");
			ret = fp_erase(shadow_base, FLASH_ERASE_UNIT);
			if (ret != TEE_SUCCESS) {
				EMSG("Erase shadow block failed\n");
				goto err_unknown;
			}

			cur_wr_addr = shadow_base;
			goto out;
		}

		/* Record the final cnt to be set */
		if (protected_cnts[i] < rd_cnts[i].val) {
			protected_cnts[i] = rd_cnts[i].val;
			*update_flag = true;
		}
	}

	/* Case all pages are programmed */
	if (page_idx == -1) {
		ret = fp_erase(shadow_base, FLASH_ERASE_UNIT);
		if (ret != TEE_SUCCESS) {
			EMSG("Erase shadow block failed\n");
			goto err_unknown;
		}

		cur_wr_addr = shadow_base;
	} else {
		cur_wr_addr = shadow_base + NAND_FLASH_PAGE_SIZE * page_idx;
	}
	DMSG("cur_wr_addr: %#x, page_idx: %u\n", cur_wr_addr, page_idx);
out:
	return ret;
err_unknown:
	agtx_show_spi_csr_status();
	return ret;
}
#endif /* CFG_FLASH_NAND */

TEE_Result cnt_init(void)
{
	TEE_Result ret;
	bool update_flag = false;
	uint32_t i;
	uint32_t protected_base = get_protect_base();

	/* 1. Read all protected counters */
	ret = fp_read(&protected_cnts, protected_base, CNT_SIZE * CFG_NUMBER_OF_CNTS);
	if (ret != TEE_SUCCESS) {
		EMSG("Read protected counters failed\n");
		panic();
	}

	for (i = 0; i < CFG_NUMBER_OF_CNTS; ++i) {
		protected_cnts[i] = (protected_cnts[i] == ERASED_VAL) ? 0 : protected_cnts[i];
		// DMSG("Protected cnt %u: %#x\n", i, protected_cnts[i]);
	}

	/* 2. Read all shadow counters and determine the final counters to be set. */
	ret = update_from_shadow(&update_flag);
	if (ret != TEE_SUCCESS) {
		EMSG("Failed to initalize counters\n");
		panic();
	}
	update_flag |= tee_ver_check();
	for (i = 0; i < CFG_NUMBER_OF_CNTS; ++i)
		DMSG("Current counter %u: %u\n", i, protected_cnts[i]);

	/* 3. Check if the protected block need to be update */
	/* 3.1. Return early if no update is required. */
	if (update_flag == false) {
		DMSG("No update is required!\n");
#ifndef CFG_BYPASS_LOCK
		goto lock;
#endif // CFG_BYPASS_LOCK
	}

	/* 3.2. Update the counters in protected block. */
#ifndef CFG_BYPASS_LOCK
	/* 3.2.1. Unlock and erase the protected block. */
	ret = fp_unlock();
	if (ret != TEE_SUCCESS) {
		EMSG("Failed to unlock protected area\n");
		panic();
	}
#endif // CFG_BYPASS_LOCK

	ret = fp_erase(protected_base, FLASH_ERASE_UNIT);
	if (ret != TEE_SUCCESS) {
		EMSG("Erase protected area failed\n");
		panic();
	}

	/* 3.2.2. Update the counter stored in the protected block. */
	ret = fp_write(&protected_cnts, protected_base, CNT_SIZE * CFG_NUMBER_OF_CNTS);
	if (ret != TEE_SUCCESS) {
		EMSG("Failed to write counters to protected area\n");
		panic();
	}

#ifndef CFG_BYPASS_LOCK
	/* 3.2.3. Set protected block and lock the setting. */
lock:
	ret = fp_lock();
	if (ret != TEE_SUCCESS) {
		EMSG("Failed to set protected area and lock the setting\n");
		panic();
	}
#endif // CFG_BYPASS_LOCK

	return TEE_SUCCESS;
}
