/*
 * (C) Copyright 2021 DreamYeh, Inc. Augentix
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include "address_map.h"
#include "config.h"

#ifdef CONFIG_SECURE_BOOT
#include "bearssl_hash.h"
#include "bearssl_rsa.h"
#include "spl_pub_key_mod.h"
#include <efuse/efuse_api_wrapper.h>
#else
typedef __UINTPTR_TYPE__ uintptr_t;
#endif

#include "spl_define.h"
#include "dram/hw_dram.h"
#include "machine.h" //it have to below hw_draw.h
#include "csr_bank_syscfg.h"
#include "csr_bank_qspi.h"
#include "csr_bank_qspir.h"
#include "csr_bank_qspiw.h"
#include "qspi/hw_qspi.h"
#include "pll/hw_pll.h"
#include "pinmux/pinmux.h"
#include "printf.h"
#include "string.h"
#include "uart.h"
#include "delay.h"

#ifdef CONFIG_EMMC
#include "mmc/agtx_mmc.h"
#endif

void spl_board_init(void);
struct qspi_dev g_qspi = { .base_addr = QSPI_BASE, .qspir_base = QSPIR_BASE, .qspiw_base = QSPIW_BASE };

#ifdef CONFIG_SECURE_BOOT
__attribute__((used)) static const eb_ops_t *const spl_eb_ops = &eb_ops;
#endif

#define IMG_TABLE_SIZE 0x148
#define BYTE_MODE_CHK_SIZE 0x01000000 // 16MB

#if defined(SPL_DEBUG)
#define print_fw_load(name, part, addr, size) printf("LD %s 0x%08x->0x%08x 0x%08x\n", name, part, addr, size)
#else
#define print_fw_load(name, part, addr, size)
#endif

//SPL code==================================================
void board_init_f(unsigned long bootflag)
{
	int err;

	err = machine_init();

	printf("== AGT SPL v1 ==\n");
#ifndef CONFIG_FPGA
	printf("%s, %d MT/s, %d MB\n", DDR_NAME, err, CONFIG_DRAM_CAPACITY);
	if (err < 0) {
		printf("spl-err-1\n");
	} else {
		printf("DRAM INIT PASS\n\n");
	}
#endif
	enable_caches();
#if defined(SPL_DEBUG)
	hw_pll_print_info();
#endif

/* armv8 crt0.S doesn't run board_init_r(), which calls spl_board_init(), in SPL */
#if defined(__aarch64__)
	spl_board_init();
#endif
}

/***************************************************************************************************************

 ***************************************************************************************************************/

int qspi_quad_mode_detection(int flash_type)
{
	uint8_t pattern[8] = { 0 };
	uint32_t id;
	/* address 2040 to 2047 */
	if (flash_type == 0) {
#ifdef CONFIG_FLASH_NAND
		nand_page_read(&g_qspi, 0);
		nand_read(&g_qspi, 2040, 8, QUAD_MODE);
		qspi_fifo_read(&g_qspi, (uint32_t *)pattern, 8);
#endif
	} else {
#ifdef CONFIG_FLASH_NOR
		nor_read(&g_qspi, 2040, 8, NOR_3BYTE_ADDR_MODE, QUAD_MODE);
		qspi_fifo_read(&g_qspi, (uint32_t *)pattern, 8);
#endif
	}

	qspi_read_id(&g_qspi, &id);
	if (id == 0x52211852)
		return DUAL_MODE;

	if (pattern[0] == 0x6A && pattern[1] == 0x6A && pattern[2] == 0xA6 && pattern[3] == 0x6A &&
	    pattern[4] == 0x99 && pattern[5] == 0x95 && pattern[6] == 0x55 && pattern[7] == 0x59) {
		return QUAD_MODE;
	} else {
		return DUAL_MODE;
	}
}
//=======================================================================

#ifdef CONFIG_SPL_BOARD_INIT
/*
	it's spl board init functon, we use it for original FSBL process.
*/
#define OFFSET_BR_SIZE 0x0800 // 2 KB
#define OFFSET_UBOOT_ADDR 0x8000
#define OFFSET_UBOOT_SIZE UBOOT_FILESIZE

#ifdef CONFIG_SECURE_BOOT
#define OFFSET_SPL_SIZE 0x7000 // align SPL_TRUNCATE_SIZE in <SDK>/build/Makefile
#define OFFSET_UBOOT_BR_ADDR ((CONFIG_DRAM_CAPACITY << 20) - 1024)
#define OFFSET_UBOOT_BR_SIZE SSL_SIGN_LEN
#define OFFSET_UBOOT_BR_PART (OFFSET_BR_SIZE + OFFSET_SPL_SIZE)
#define OFFSET_UBOOT_PART (OFFSET_UBOOT_BR_PART + OFFSET_UBOOT_BR_SIZE)
enum { OFFSET_TEE_BR_SIZE = sizeof(struct boot_record) };
#define OFFSET_TEE_BR_ADDR (OFFSET_UBOOT_BR_ADDR + OFFSET_UBOOT_BR_SIZE)
#define OFFSET_TEE_0_BR_PART TEE_0_FLASH_START
#define OFFSET_TEE_1_BR_PART TEE_1_FLASH_START
#define PUBEXP_LEN 3
#else
#define OFFSET_SPL_SIZE 0x5800 // align SPL_TRUNCATE_SIZE in <SDK>/build/Makefile
#define OFFSET_UBOOT_PART (OFFSET_BR_SIZE + OFFSET_SPL_SIZE)
#endif // CONFIG_SECURE_BOOT

#ifdef CONFIG_AMP
#ifdef CONFIG_SECURE_BOOT
enum { OFFSET_FREERTOS_BR_SIZE = sizeof(struct boot_record) }; // see #92078-29
#define OFFSET_FREERTOS_BR_ADDR (OFFSET_UBOOT_BR_ADDR + OFFSET_UBOOT_BR_SIZE)
#define OFFSET_FREERTOS_BR_PART FREERTOS_ADDR
#define OFFSET_FREERTOS_PART (FREERTOS_ADDR + OFFSET_FREERTOS_BR_SIZE)
#define OFFSET_FREERTOS_SIZE (FREERTOS_SIZE - OFFSET_FREERTOS_BR_SIZE)
#else
#define OFFSET_FREERTOS_PART FREERTOS_ADDR
#define OFFSET_FREERTOS_SIZE FREERTOS_SIZE
#endif // CONFIG_SECURE_BOOT
#define OFFSET_FREERTOS_ADDR AMP_FREERTOS_START_ADDR

#if !defined(OFFSET_FREERTOS_ADDR) || !defined(OFFSET_FREERTOS_SIZE) || !defined(OFFSET_FREERTOS_PART)
#error incorrect FREERTOS address setting
#endif

#endif // CONFIG_AMP

/* secure boot image signature address */
#ifdef CONFIG_SECURE_BOOT
#ifdef CONFIG_AMP
#define OFFSET_HASH (OFFSET_UBOOT_BR_ADDR + OFFSET_UBOOT_BR_SIZE + OFFSET_FREERTOS_BR_SIZE)
#elif defined CONFIG_OPTEE
#define OFFSET_HASH (OFFSET_UBOOT_BR_ADDR + OFFSET_UBOOT_BR_SIZE + OFFSET_TEE_BR_SIZE)
#else
#define OFFSET_HASH (OFFSET_UBOOT_BR_ADDR + OFFSET_UBOOT_BR_SIZE)
#endif
#define OFFSET_HASH_GOLD (OFFSET_HASH + SHA256_LEN)
#endif

#ifdef CONFIG_OPTEE
#define OFFSET_TEE_0_PART (TEE_0_FLASH_START + OFFSET_TEE_BR_SIZE)
#define OFFSET_TEE_1_PART (TEE_1_FLASH_START + OFFSET_TEE_BR_SIZE)
#define OFFSET_TEE_ADDR TEE_ADDR
#define OFFSET_TEE_SIZE (TEE_SIZE - OFFSET_TEE_BR_SIZE)
#endif

#ifdef CONFIG_SECURE_BOOT
/* public exponent set to 65537 (0x10001) */
unsigned char g_pubexp[PUBEXP_LEN] = { 0x01, 0x00, 0x01 };

/* memcmp is used by br_rsa */
int memcmp(const void *cs, const void *ct, size_t count)
{
	const unsigned char *su1 = cs, *su2 = ct, *end = su1 + count;
	int res = 0;

	while (su1 < end) {
		res = *su1++ - *su2++;
		if (res)
			break;
	}
	return res;
}

/* memmove is used by br_rsa */
void *memmove(void *dest, const void *src, size_t count)
{
	char *tmp, *s;

	if (dest <= src || (src + count) <= dest) {
		memcpy(dest, src, count);
	} else {
		tmp = (char *)dest + count;
		s = (char *)src + count;
		while (count--)
			*--tmp = *--s;
	}

	return dest;
}

static int validate_img(uint32_t img_sign_addr, uint32_t img_addr)
{
	struct boot_record *br = (struct boot_record *)img_sign_addr;
	uint32_t *img = (uint32_t *)img_addr;

	uint32_t img_size = 0;
	if (img_sign_addr == OFFSET_UBOOT_BR_ADDR) {
		img_size = OFFSET_UBOOT_SIZE;
	} else {
#if defined(CONFIG_AMP)
		if (img_sign_addr == OFFSET_FREERTOS_BR_ADDR) {
			img_size = br->size;
		}
#elif defined(CONFIG_OPTEE)
		if (img_sign_addr == OFFSET_TEE_BR_ADDR) {
			img_size = br->size;
		}
#endif
	}

	uint8_t *hash = (uint8_t *)OFFSET_HASH;
	uint8_t *hash_gold = (uint8_t *)OFFSET_HASH_GOLD;
	int ret;
	br_sha256_context ctx;
	br_rsa_public_key pk;

	if (img_size == 0)
		return -1;

	br_sha256_init(&ctx);
	br_sha256_update(&ctx, img, img_size);
	br_sha256_out(&ctx, hash);

	pk.n = pkm;
	pk.nlen = MODULUS_LEN;
	pk.e = g_pubexp;
	pk.elen = PUBEXP_LEN;

	ret = br_rsa_i31_pkcs1_vrfy(br->img_sign, SSL_SIGN_LEN, BR_HASH_OID_SHA256, SHA256_LEN, &pk, hash_gold);
	if (ret == 0)
		return -1;

	ret = memcmp(hash, hash_gold, SHA256_LEN);
	if (ret != 0)
		return -1;

	return 0;
}
#endif

#ifdef CONFIG_FLASH_NAND
void nand_load_image(uint32_t part_addr, uint32_t *load_addr, uint32_t load_len, uint32_t spi_mode)
{
	uint32_t flash_addr_current = part_addr;
	uint32_t unread_size = load_len;
	uint32_t shift_cnt = part_addr - ((part_addr >> BYTES_OFFSET_2048) << BYTES_OFFSET_2048);
	uint32_t read_byte;
	uint32_t status;

	while (unread_size) {
		/* check if the next block (1 block = 128 Kb) */
		if ((flash_addr_current & 0x0001FFFF) == 0) {
			/* Check bad block */
			status = is_bad_block(
			        &g_qspi, nand_addr_to_block(flash_addr_current, BYTES_OFFSET_2048, PAGES_OFFSET_64),
			        BYTES_OFFSET_2048, PAGES_OFFSET_64);
			if (status != -ESUCCESS) {
				if (status == -EFAIL) {
					printf("[WARN] Bad block detected @ 0x%08x.\n", flash_addr_current);
					flash_addr_current += 0x00020000;
					continue;
				} else {
					printf("spl-err-2\n");
					break;
				}
			}
		}

		read_byte = (unread_size > NAND_FLASH_PAGE_SIZE) ? NAND_FLASH_PAGE_SIZE : unread_size;
		read_byte -= shift_cnt;

		nand_dma_read(&g_qspi, (uintptr_t)load_addr, (flash_addr_current >> BYTES_OFFSET_2048), read_byte,
		              spi_mode, shift_cnt);

		shift_cnt = 0;
		load_addr += read_byte / sizeof(int);
		unread_size -= read_byte;
		flash_addr_current += read_byte;
	}
}
#endif /* CONFIG_FLASH_NAND */

#ifdef CONFIG_OPTEE
#ifdef CONFIG_FLASH_NOR
#if (FLASH_CAPACITY_MB < 32)
#define FLASH_PROTECTED_ADDR ((FLASH_CAPACITY_MB << 20) - 0x1000)
#else
#define FLASH_PROTECTED_ADDR ((FLASH_CAPACITY_MB << 20) - 0x10000)
#endif /* (FLASH_CAPACITY_MB < 32) */
#define FLASH_ERASE_UNIT 0x1000
#elif defined(CONFIG_FLASH_NAND)
#define FLASH_PROTECTED_SIZE (NAND_FLASH_BLOCK_SIZE * CONFIG_PROTECTED_BLOCK_NUM)
#define FLASH_PROTECTED_ADDR ((FLASH_CAPACITY_MB << 20) - FLASH_PROTECTED_SIZE)
#define FLASH_ERASE_UNIT NAND_FLASH_BLOCK_SIZE
#endif /* CONFIG_FLASH_NOR */

/* Counter information */
#define MONOTONIC_CNT_SLOT 0x2
#define ERASED_VAL 0xFFFFFFFF
#define CNT_SIZE 4
#define SHADOW_CNT_SIZE 8

struct shadow_cnt {
	uint32_t id;
	uint32_t val;
};
/* Use union to avoid strict aliasing warnings. */
union slot_counter {
	struct {
		uint32_t boot_time : 2; // 2-bit for boot time counting, increase by SPL while boot_success not set.
		uint32_t boot_success : 1; // 1-bit marking boot success, set by optee_os.
		// set by step-2 or step-4.1.1, changing boot_slot must clear the value of boot_time and boot_success.
		uint32_t boot_slot : 1;
		uint32_t reserved : 28; // nothing, increaed when boot_slot 1 -> 0.
	} cnt;
	uint32_t val;
};

static uint32_t cur_wr_addr;

#if defined(CONFIG_FLASH_NAND)
struct shadow_cnt g_cnts[CONFIG_NUMBER_OF_CNTS];

static uint32_t skip_bad_block(uint32_t cur_addr, uint32_t block_limit)
{
	uint32_t status = -ESUCCESS;
	uint32_t bad_block_cnt = 0;

	while (cur_addr < block_limit) {
		status = is_bad_block(&g_qspi, nand_addr_to_block(cur_addr, BYTES_OFFSET_2048, PAGES_OFFSET_64),
		                      BYTES_OFFSET_2048, PAGES_OFFSET_64);
		if (status != -ESUCCESS) {
			if (status == -EFAIL) {
				printf("Bad block detected at 0x%08x.\n", cur_addr);
				++bad_block_cnt;
			} else {
				printf("tee-err-bb\n");
				goto loop;
			}
		} else {
			break;
		}
	}
	if (status != -ESUCCESS) {
		printf("Device locked: get counter failed\n");
		goto loop;
	}

	return bad_block_cnt;
loop:
	while (1) {
	}
}

static void update_from_shadow_nand(uint32_t quad_dual_mode)
{
	int32_t left = 0;
	int32_t right = (1 << PAGES_OFFSET_64) - 1;
	int32_t mid;
	int32_t page_idx = -1;
	uint32_t bad_block_cnt;
	uint32_t shadow_base;
	uint32_t page_base;
	uint32_t rd_size;
	uint32_t byte_offset = 0;
	uint32_t i;
	uint8_t had_programmed = 0;
	/* Use the DRAM region that will be occupied by the TEE image, since the
	 * counter is read before loading the TEE image.
	 */
	struct shadow_cnt *rd_cnts = (struct shadow_cnt *)(OFFSET_TEE_ADDR);
	shadow_base = FLASH_PROTECTED_ADDR - FLASH_PROTECTED_SIZE;

	/* Skip bad block */
	bad_block_cnt = skip_bad_block(shadow_base, FLASH_PROTECTED_ADDR);
	if (bad_block_cnt > 0)
		shadow_base += NAND_FLASH_BLOCK_SIZE * bad_block_cnt;

	page_base = nand_addr_to_page(shadow_base, BYTES_OFFSET_2048);

	/* 2. Get newest slot counter in shadow block */
	rd_size = SHADOW_CNT_SIZE * CONFIG_NUMBER_OF_CNTS;

	/* 2.1. Binary search the first un-programmed page */
	while (left <= right) {
		had_programmed = 0;
		mid = left + ((right - left) >> 1);

		/* Check if the mid-th page has been programmed */
		nand_normal_read(&g_qspi, (uint32_t *)rd_cnts, page_base + mid, rd_size, quad_dual_mode, byte_offset);
		if (rd_cnts->id != ERASED_VAL || rd_cnts->val != ERASED_VAL) {
			had_programmed = 1;
			left = mid + 1;
		} else {
			page_idx = mid;
			right = mid - 1;
		}
	}

	/* Case all pages in shadow block are not programmed */
	if (page_idx == 0 && had_programmed == 0) {
		cur_wr_addr = shadow_base;
		goto out;
	} else {
		cur_wr_addr = shadow_base + NAND_FLASH_PAGE_SIZE * page_idx;
	}

	nand_normal_read(&g_qspi, (uint32_t *)rd_cnts, page_base + (page_idx - 1), rd_size, quad_dual_mode,
	                 byte_offset);

	for (i = 0; i < CONFIG_NUMBER_OF_CNTS; ++i) {
		if (rd_cnts[i].val != ERASED_VAL && rd_cnts[i].val > g_cnts[i].val)
			g_cnts[i].val = rd_cnts[i].val;
	}
out:
	return;
}

static uint32_t slot_cnt_get_nand(uint32_t quad_dual_mode)
{
	/* Use the DRAM region that will be occupied by the TEE image, since the
	 * counter is read before loading the TEE image.
	 */
	uint32_t *protected_slot_cnt = (uint32_t *)OFFSET_TEE_ADDR;
	uint32_t bad_block_cnt;
	uint32_t rd_addr;
	uint32_t rd_size;
	uint32_t byte_offset = 0;
	uint32_t i;

	rd_addr = FLASH_PROTECTED_ADDR;
	/* 1. Get slot cnt in protected block */
	/* Update read address when encountering bad block */
	bad_block_cnt = skip_bad_block(rd_addr, (FLASH_CAPACITY_MB << 20));
	rd_addr += NAND_FLASH_BLOCK_SIZE * bad_block_cnt;

	rd_size = CNT_SIZE * CONFIG_NUMBER_OF_CNTS;
	nand_normal_read(&g_qspi, protected_slot_cnt, nand_addr_to_page(rd_addr, BYTES_OFFSET_2048), rd_size,
	                 quad_dual_mode, byte_offset);
	for (i = 0; i < CONFIG_NUMBER_OF_CNTS; ++i) {
		g_cnts[i].id = i;

		if (protected_slot_cnt[i] == ERASED_VAL) {
			g_cnts[i].val = 0;
		} else {
			g_cnts[i].val = protected_slot_cnt[i];
		}
	}

	/* 2. Get newest slot counter in shadow block */
	update_from_shadow_nand(quad_dual_mode);

	return g_cnts[MONOTONIC_CNT_SLOT].val;
}
#endif /* CONFIG_FLASH_NAND */

#if defined(CONFIG_FLASH_NOR)
static uint32_t slot_cnt_get_nor(uint32_t quad_dual_mode, uint32_t byte_mode)
{
	uint32_t i;
	uint32_t shadow_base;
	uint32_t rd_addr;
	uint32_t rd_size = CNT_SIZE;
	uint32_t rd_amount;
	uint32_t protected_slot_cnt;
	/* Use the DRAM region that will be occupied by the TEE image, since the
	 * counter is read before loading the TEE image.
	 */
	struct shadow_cnt *rd_cnts = (struct shadow_cnt *)OFFSET_TEE_ADDR;

	/* Only get the slot counter, which is the third counter */
	rd_addr = FLASH_PROTECTED_ADDR + CNT_SIZE * MONOTONIC_CNT_SLOT;

	/* 1. Get slot cnt in protected block */
	nor_normal_read(&g_qspi, &protected_slot_cnt, rd_addr, rd_size, byte_mode, quad_dual_mode);
	protected_slot_cnt = (protected_slot_cnt == ERASED_VAL) ? 0 : protected_slot_cnt;

	/* 2. Get newest slot counter in shadow block */
	shadow_base = FLASH_PROTECTED_ADDR - FLASH_ERASE_UNIT;
	rd_addr = shadow_base;
	cur_wr_addr = rd_addr;
	rd_amount = 16;
	rd_size = SHADOW_CNT_SIZE * rd_amount;

	while (rd_addr < FLASH_PROTECTED_ADDR) {
		/* NOR read speed > 20MB/s ===> 128bytes cost at most 6.104 us = 128 / (20 * 1024 * 1024) * 1000 * 1000 */
		nor_dma_read(&g_qspi, (uint32_t)rd_cnts, rd_addr, rd_size, byte_mode, quad_dual_mode);
		invalidate_dcache_range((unsigned long)rd_cnts & ~(CONFIG_SYS_CACHELINE_SIZE - 1),
		                        ((unsigned long)rd_cnts + rd_size + CONFIG_SYS_CACHELINE_SIZE + 1) &
		                                ~(CONFIG_SYS_CACHELINE_SIZE - 1));

		for (i = 0; i < rd_amount; ++i) {
			/* If both id and cnt are 0xFFFFFFFF, it indicates that all cnts 
             		 * in the shadow have been read.
             		 */
			if (rd_cnts[i].id == ERASED_VAL && rd_cnts[i].val == ERASED_VAL)
				goto done;

			/* Assume the shadow block will not be corrupted in this stage, so
			 * the counter ID is not checked against CONFIG_NUMBER_OF_CNTS.
			 */

			/* Record the final cnt to be set */
			if (rd_cnts[i].id == MONOTONIC_CNT_SLOT && rd_cnts[i].val > protected_slot_cnt)
				protected_slot_cnt = rd_cnts[i].val;

			cur_wr_addr += SHADOW_CNT_SIZE;
		}

		rd_addr += rd_size;
	}

done:
	return protected_slot_cnt;
}
#endif /* CONFIG_FLASH_NOR */

static void slot_cnt_set(struct shadow_cnt *new_cnt, uint32_t quad_dual_mode,
                         uint32_t byte_mode __attribute__((unused)))
{
#if defined(CONFIG_FLASH_NAND)
	uint32_t wr_size = SHADOW_CNT_SIZE * CONFIG_NUMBER_OF_CNTS;

	g_cnts[MONOTONIC_CNT_SLOT].val = new_cnt->val;
	nand_normal_write(&g_qspi, nand_addr_to_page(cur_wr_addr, BYTES_OFFSET_2048), (uint32_t)g_cnts, wr_size,
	                  quad_dual_mode);
#elif defined(CONFIG_FLASH_NOR)
	nor_write(&g_qspi, cur_wr_addr, SHADOW_CNT_SIZE, (uint32_t *)new_cnt, byte_mode, quad_dual_mode);
#endif /* CONFIG_FLASH_NAND */
}

static union slot_counter slot_cnt_update(uint32_t quad_dual_mode, uint32_t byte_mode __attribute__((unused)))
{
	struct shadow_cnt shadow_cnt = { MONOTONIC_CNT_SLOT, 0 };
	union slot_counter slot_cnt;

	/* 1. Get the newest slot counter in shadow block */
#if defined(CONFIG_FLASH_NOR)
	slot_cnt.val = slot_cnt_get_nor(quad_dual_mode, byte_mode);
#elif defined(CONFIG_FLASH_NAND)
	slot_cnt.val = slot_cnt_get_nand(quad_dual_mode);
#endif /* CONFIG_FLASH_NOR */
	/* 2. Check the boot_success field to determine which slot to boot from. */
	/* 2.1. boot_success == 0 */
	if (slot_cnt.cnt.boot_success == 0) {
		/* 2.1.1. boot_time < 3 */
		if (slot_cnt.cnt.boot_time < 3) {
			/* 2.1.1.1. add boot_time by 1 */
			++(slot_cnt.cnt.boot_time);
		} else { /* 2.1.2. boot_time == 3 */
			/* 2.1.2.1. Set slot_cnt.to another one, and reset boot_time and boot_success */
			slot_cnt.cnt.boot_time = 1;
			slot_cnt.cnt.boot_success = 0;
			if (slot_cnt.cnt.boot_slot == 1) {
				slot_cnt.cnt.boot_slot = 0;
				++slot_cnt.cnt.reserved;
			} else {
				slot_cnt.cnt.boot_slot = 1;
			}
		}

		/* 2.2. Set shadow counter */
		shadow_cnt.val = slot_cnt.val;
		slot_cnt_set(&shadow_cnt, quad_dual_mode, byte_mode);
	}

	return slot_cnt;
}
#endif /* CONFIG_OPTEE */

void spl_board_init(void)
{
	uint32_t *img;
#ifdef CONFIG_OPTEE
	union slot_counter slot_cnt;
#endif /* CONFIG_OPTEE */

#ifdef CONFIG_EMMC
	struct sdc_dev sdc = {
		.sdc_base_addr = SDC0_BASE,
		.sdc_cfg_base_addr = SDC_CFG0_BASE,
		.ref_clk_rate = MMC_REF_CLK_49_8M,
		.sdc_emmc_clk_rate = 49800000,
	};

	mmc_boot_init(&sdc);
	printf("eMMC LD u-boot from boot partition 1, part=0x%08x to 0x%08x size=0x%08x\n", OFFSET_UBOOT_PART,
	       OFFSET_UBOOT_ADDR, OFFSET_UBOOT_SIZE);
	mmc_boot_dma_read(sdc.sdc_base_addr, OFFSET_UBOOT_PART, OFFSET_UBOOT_ADDR, OFFSET_UBOOT_SIZE,
	                  MMC_PARTITION_BOOT_1);
#else
	uint32_t flash_mode = 0;
	uint32_t quad_dual_mode = DUAL_MODE;
	uint32_t byte_mode __attribute__((unused));
#ifdef CONFIG_FLASH_NOR
	flash_mode = 1;
	quad_dual_mode = qspi_quad_mode_detection(flash_mode);
#if defined(CONFIG_AMP) && (OFFSET_FREERTOS_PART + OFFSET_FREERTOS_SIZE > BYTE_MODE_CHK_SIZE)
	byte_mode = NOR_4BYTE_ADDR_MODE;
#elif defined(CONFIG_OPTEE) && (OFFSET_TEE_1_PART + OFFSET_TEE_SIZE > BYTE_MODE_CHK_SIZE)
	byte_mode = NOR_4BYTE_ADDR_MODE;
#else
	byte_mode = NOR_3BYTE_ADDR_MODE;
#endif
	/* SPI mode: N=None, S=Single, D=Dual, T=Triple, Q=Quad */
	printf("NOR [%c] %dB\n", "NSDTQ"[quad_dual_mode], byte_mode + 2);
#else
	flash_mode = 0;
	quad_dual_mode = qspi_quad_mode_detection(flash_mode);
	/* SPI mode: N=None, S=Single, D=Dual, T=Triple, Q=Quad */
	printf("NAND [%c]\n", "NSDTQ"[quad_dual_mode]);
#endif // CONFIG_FLASH_NOR

#ifdef CONFIG_OPTEE
	slot_cnt = slot_cnt_update(quad_dual_mode, byte_mode);
#endif /* CONFIG_OPTEE */

#ifndef CONFIG_FLASH_NOR
	if (flash_mode == 0) {
		// read image signatrure
#ifdef CONFIG_SECURE_BOOT
		nand_load_image(OFFSET_UBOOT_BR_PART, (uint32_t *)OFFSET_UBOOT_BR_ADDR, OFFSET_UBOOT_BR_SIZE,
		                quad_dual_mode);
#ifdef CONFIG_AMP
		nand_load_image(OFFSET_FREERTOS_BR_PART, (uint32_t *)OFFSET_FREERTOS_BR_ADDR, OFFSET_FREERTOS_BR_SIZE,
		                quad_dual_mode);
#endif
#ifdef CONFIG_OPTEE
		nand_load_image((slot_cnt.cnt.boot_slot == 0) ? OFFSET_TEE_0_BR_PART : OFFSET_TEE_1_BR_PART,
		                (uint32_t *)OFFSET_TEE_BR_ADDR, OFFSET_TEE_BR_SIZE, quad_dual_mode);
#endif
#endif /* CONFIG_SECURE_BOOT */
		// read image
		print_fw_load("u-boot", OFFSET_UBOOT_PART, OFFSET_UBOOT_ADDR, OFFSET_UBOOT_SIZE);
		nand_load_image(OFFSET_UBOOT_PART, (uint32_t *)OFFSET_UBOOT_ADDR, OFFSET_UBOOT_SIZE, quad_dual_mode);
#ifdef CONFIG_AMP
		print_fw_load("FreeRTOS", OFFSET_FREERTOS_PART, OFFSET_FREERTOS_ADDR, OFFSET_FREERTOS_SIZE);
		nand_load_image(OFFSET_FREERTOS_PART, (uint32_t *)OFFSET_FREERTOS_ADDR, OFFSET_FREERTOS_SIZE,
		                quad_dual_mode);
#endif
#ifdef CONFIG_OPTEE
		print_fw_load("TEE", (slot_cnt.cnt.boot_slot == 0) ? OFFSET_TEE_0_PART : OFFSET_TEE_1_PART,
		              OFFSET_TEE_ADDR, OFFSET_TEE_SIZE);
		flush_dcache_range((unsigned long)OFFSET_TEE_ADDR & ~(CONFIG_SYS_CACHELINE_SIZE - 1),
		                   ((unsigned long)OFFSET_TEE_ADDR + OFFSET_TEE_SIZE + CONFIG_SYS_CACHELINE_SIZE + 1) &
		                           ~(CONFIG_SYS_CACHELINE_SIZE - 1));
		nand_load_image((slot_cnt.cnt.boot_slot == 0) ? OFFSET_TEE_0_PART : OFFSET_TEE_1_PART,
		                (uint32_t *)OFFSET_TEE_ADDR, OFFSET_TEE_SIZE, quad_dual_mode);
		invalidate_dcache_range((unsigned long)OFFSET_TEE_ADDR & ~(CONFIG_SYS_CACHELINE_SIZE - 1),
		                        ((unsigned long)OFFSET_TEE_ADDR + OFFSET_TEE_SIZE + CONFIG_SYS_CACHELINE_SIZE +
		                         1) & ~(CONFIG_SYS_CACHELINE_SIZE - 1));
#endif
	}
#else /* CONFIG_FLASH_NOR */
	if (flash_mode == 1) {
#ifdef CONFIG_SECURE_BOOT
		// read image signature
		nor_dma_read(&g_qspi, OFFSET_UBOOT_BR_ADDR, OFFSET_UBOOT_BR_PART, OFFSET_UBOOT_BR_SIZE, byte_mode,
		             quad_dual_mode);
#ifdef CONFIG_AMP
		nor_dma_read(&g_qspi, OFFSET_FREERTOS_BR_ADDR, OFFSET_FREERTOS_BR_PART, OFFSET_FREERTOS_BR_SIZE,
		             byte_mode, quad_dual_mode);
#endif
#ifdef CONFIG_OPTEE
		nor_dma_read(&g_qspi, OFFSET_TEE_BR_ADDR,
		             (slot_cnt.cnt.boot_slot == 0) ? OFFSET_TEE_0_BR_PART : OFFSET_TEE_1_BR_PART,
		             OFFSET_TEE_BR_SIZE, byte_mode, quad_dual_mode);
#endif
#endif

		// read image
		print_fw_load("u-boot", OFFSET_UBOOT_PART, OFFSET_UBOOT_ADDR, OFFSET_UBOOT_SIZE);
		nor_dma_read(&g_qspi, OFFSET_UBOOT_ADDR, OFFSET_UBOOT_PART, OFFSET_UBOOT_SIZE, byte_mode,
		             quad_dual_mode);
#ifdef CONFIG_AMP
		print_fw_load("FreeRTOS", OFFSET_FREERTOS_PART, OFFSET_FREERTOS_ADDR, OFFSET_FREERTOS_SIZE);
		nor_dma_read(&g_qspi, OFFSET_FREERTOS_ADDR, OFFSET_FREERTOS_PART, OFFSET_FREERTOS_SIZE, byte_mode,
		             quad_dual_mode);
#endif
#ifdef CONFIG_OPTEE
		print_fw_load("TEE", (slot_cnt.cnt.boot_slot == 0) ? OFFSET_TEE_0_PART : OFFSET_TEE_1_PART,
		              OFFSET_TEE_ADDR, OFFSET_TEE_SIZE);
		flush_dcache_range((unsigned long)OFFSET_TEE_ADDR & ~(CONFIG_SYS_CACHELINE_SIZE - 1),
		                   ((unsigned long)OFFSET_TEE_ADDR + OFFSET_TEE_SIZE + CONFIG_SYS_CACHELINE_SIZE + 1) &
		                           ~(CONFIG_SYS_CACHELINE_SIZE - 1));
		nor_dma_read(&g_qspi, OFFSET_TEE_ADDR,
		             (slot_cnt.cnt.boot_slot == 0) ? OFFSET_TEE_0_PART : OFFSET_TEE_1_PART, OFFSET_TEE_SIZE,
		             byte_mode, quad_dual_mode);
		invalidate_dcache_range((unsigned long)OFFSET_TEE_ADDR & ~(CONFIG_SYS_CACHELINE_SIZE - 1),
		                        ((unsigned long)OFFSET_TEE_ADDR + OFFSET_TEE_SIZE + CONFIG_SYS_CACHELINE_SIZE +
		                         1) & ~(CONFIG_SYS_CACHELINE_SIZE - 1));
#endif
	}
#endif /* !CONFIG_FLASH_NOR */
#endif /* CONFIG_EMMC */
	img = (uint32_t *)OFFSET_UBOOT_ADDR;

	// verify image signature
#ifdef CONFIG_SECURE_BOOT
	/* [Stack Pivot] Relocate SP to DRAM before RSA validation.
	 * Issue: SRAM stack (~2.3KB) insufficient for RSA-2048.
	 * Solution: Move SP to KERNEL_START (0x01000000).
	 * Safety: Stack grows DOWN towards UBOOT_END (0x00080000), ~15MB gap.
	 * Note: One-way operation - SPL never returns after this point.
	 */
	__asm__ __volatile__("" : : : "memory");
	__asm__ __volatile__("mov sp, %0" : : "r"(0x01000000) : "memory");

	if (validate_img(OFFSET_UBOOT_BR_ADDR, OFFSET_UBOOT_ADDR) != 0) {
		printf("spl-err-3\n");
		goto loop;
	}
	printf("SEC Uboot\n");
#endif // CONFIG_SECURE_BOOT

#ifdef CONFIG_AMP
	gic_init_per_cpu();
	gic_init();

	memset((void *)AMP_DRIVER_SHM_ADDR, 0, 16); //reset early amp shared memory

	// printf("CPU0 jump to 0x%08x, CPU1 jump to 0x%08x\n", OFFSET_FREERTOS_ADDR, OFFSET_UBOOT_ADDR);
	// run uboot on CPU1
	arch_wakeup_secondary_core(img);

	gicc_disable_cpu();

#ifdef CONFIG_SECURE_BOOT
	if (validate_img(OFFSET_FREERTOS_BR_ADDR, OFFSET_FREERTOS_ADDR) != 0) {
		printf("spl-err-4\n");
		goto loop;
	}
	printf("SEC FreeRTOS\n");
#endif /* CONFIG_SECURE_BOOT */

	// run FreeRTOS on CPU0
	img = (uint32_t *)OFFSET_FREERTOS_ADDR;
#endif
#ifdef CONFIG_OPTEE
	if (validate_img(OFFSET_TEE_BR_ADDR, OFFSET_TEE_ADDR) != 0) {
		printf("spl-err-5\n");
		goto loop;
	}
	printf("TEE %u\n", slot_cnt.cnt.boot_slot);
#endif /* CONFIG_OPTEE */
	disable_caches(); // should before setting r14
#ifdef CONFIG_OPTEE
	/* 3. Boot by slot boot_slot */
	asm volatile("mov r14, %[img]\n" : : [img] "r"(img) :);

	img = (uint32_t *)OFFSET_TEE_ADDR;
#endif /* CONFIG_OPTEE */

#if defined(__aarch64__)
	asm volatile("br %0" : : "r"(img) :);
#else
	asm volatile("bx %[img]\n" : : [img] "r"(img) :);
#endif

#ifdef CONFIG_SECURE_BOOT
loop:
#endif
	while (1) {
		//halt at infinite loop
	}
}
#endif

//=========================================================================
unsigned int spl_boot_device(void)
{
	return 0;
}

#ifdef CONFIG_SPL_MMC_SUPPORT
u32 spl_boot_mode(void)
{
	return MMCSD_MODE_FS;
}
#endif

#ifdef CONFIG_SPL_OS_BOOT
int spl_start_uboot(void)
{
	/* boot linux */
	return 0;
}
#endif
