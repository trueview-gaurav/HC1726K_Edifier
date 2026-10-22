/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <mm/core_memprot.h>
#include <platform_config.h>
#include <tee_api_defines.h>
#include <mm/core_mmu.h>
#include <trace.h>
#include <drivers/spi/agtx_spi.h>
#include <drivers/spi/flash_protect.h>
#include <drivers/spi/agtx_spi_nor.h>
#include <drivers/spi/agtx_spi_nand.h>
#include "../../arch/arm/plat-augentix/agtx_smc.h"

/*****************************/
/* Flash Information Related */
/*****************************/

#define FLASH_LIST_LEN (sizeof(flash_info_list) / sizeof(flash_info_list[0]))
#define WR_SR_TIMEOUT 0xFFFFF

const struct fp_flash_info flash_info_list[] = {
#if defined(CFG_SPI_FLASH_BY25Q64ES)
	{ 0x684017, 0x800000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_BY25Q64ES) */
#if defined(CFG_SPI_FLASH_BY25Q128ES)
	{ 0x684018, 0x1000000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_BY25Q128ES) */
#if defined(CFG_SPI_FLASH_GM25Q64A)
	{ 0x1C4017, 0x800000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_GM25Q64A) */
#if defined(CFG_SPI_FLASH_GM25Q128A)
	{ 0x1C4018, 0x1000000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_GM25Q128A) */
#if defined(CFG_SPI_FLASH_FM25Q128A_SOB_T_G)
	{ 0xA14018, 0x1000000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_FM25Q128A_SOB_T_G) */
#if defined(CFG_SPI_FLASH_PY25Q64HA)
	{ 0x852017, 0x800000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_PY25Q64HA) */
#if defined(CFG_SPI_FLASH_W25Q64JV)
	{ 0xEF4017, 0x800000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_W25Q64JV) */
#if defined(CFG_SPI_FLASH_W25Q128JV)
	{ 0xEF4018, 0x1000000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_W25Q128JV) */
#if defined(CFG_SPI_FLASH_W25Q256JV)
	{ 0xEF4019, 0x2000000, 0x10000, 0x04, 8 },
#endif /* defined(CFG_SPI_FLASH_W25Q256JV) */
#if defined(CFG_SPI_FLASH_XM25QH64C) || defined(CFG_SPI_FLASH_XM25QH64D)
	{ 0x204017, 0x800000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_XM25QH64C) */
#if defined(CFG_SPI_FLASH_NM25Q128EVB)
	{ 0x522118, 0x1000000, 0x1000, 0x44, 9 },
#endif /* defined(CFG_SPI_FLASH_NM25Q128EVB) */
#if defined(CFG_SPI_FLASH_ZB25VQ64A)
	{ 0x5E4017, 0x800000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_ZB25VQ64A) */
#if defined(CFG_SPI_FLASH_ZB25VQ128A)
	/* Read ID in SPI mode, the JEDEC ID should be 0x5E4018 */
	{ 0x5E4018, 0x1000000, 0x1000, 0x44, 8 },
#endif /* defined(CFG_SPI_FLASH_ZB25VQ128A) */
#if defined(CFG_SPI_FLASH_W25N01GV)
	{ 0xEFAA21, 0x8000000, NAND_FLASH_BLOCK_SIZE * CFG_PROTECTED_BLOCK_NUM, 0x08, 0 },
#endif /* defined(CFG_SPI_FLASH_W25N01GV) */
#if defined(CFG_SPI_FLASH_W25N02KV)
	{ 0xEFAA22, 0x10000000, NAND_FLASH_BLOCK_SIZE * CFG_PROTECTED_BLOCK_NUM, 0x08, 0 },
#endif /* defined(CFG_SPI_FLASH_W25N02KV) */
#if defined(CFG_SPI_FLASH_W25N04KVZEIR)
	{ 0xEFAA23, 0x20000000, NAND_FLASH_BLOCK_SIZE * CFG_PROTECTED_BLOCK_NUM, 0x08, 0 },
#endif /* defined(CFG_SPI_FLASH_W25N04KVZEIR) */
#if defined(CFG_SPI_FLASH_F50L1G41LB)
	{ 0xC8017F, 0x8000000, NAND_FLASH_BLOCK_SIZE * CFG_PROTECTED_BLOCK_NUM, 0x08, 0 },
#endif /* defined(CFG_SPI_FLASH_F50L1G41LB) */
#if defined(CFG_SPI_FLASH_EN25QX128A_104HIP2V)
	{ 0x1C7118, 0x1000000, 0x1000 },
#endif /* defined(CFG_SPI_FLASH_EN25QX128A_104HIP2V) */
#if defined(CFG_SPI_FLASH_MX35LF1G)
	{ 0xC212C2, 0x8000000, NAND_FLASH_BLOCK_SIZE * CFG_PROTECTED_BLOCK_NUM, 0x08, 0 },
#endif /* defined(CFG_SPI_FLASH_MX35LF1G) */
#if defined(CFG_SPI_FLASH_MX25L12805D)
		{ 0xC22018, 0x1000000, 0x1000 },
#endif /* defined(CFG_SPI_FLASH_MX25L12805D) */
#if defined(CFG_SPI_FLASH_PY25Q129HA)
		{ 0x852018, 0x1000000, 0x1000 },
#endif /* defined(CFG_SPI_FLASH_MX25L12805D) */
	{ 0 },
};

const struct fp_flash_info *selected_flash_info;

struct fp_ops {
	TEE_Result (*read)(void *output, uint32_t addr, uint32_t size);
	TEE_Result (*write)(const void *data, uint32_t addr, uint32_t size);
	TEE_Result (*erase)(uint32_t addr, uint32_t size);
#ifndef CFG_BYPASS_LOCK
	TEE_Result (*lock)(void);
	TEE_Result (*unlock)(void);
#endif // CFG_BYPASS_LOCK
};
struct fp_ops fp_ops;

static bool check_sec_en(void)
{
	uint8_t *sec_boot = NULL;
	
#ifdef CFG_IDENTITY_MAPPING
	if (is_sysconf_mapped() == false) {
		EMSG("SYSCONF_BASE did not initialize");
		return false;
	}	
	sec_boot = (uint8_t *)SYSCONF_BASE + 2;
#else
	struct io_pa_va p = { .pa = SYSCONF_BASE, .va = 0 };
	sec_boot = (uint8_t *)io_pa_or_va(&p, 1) + 2;
#endif
	
	if (!sec_boot)
		return false;
		
	return ((*sec_boot == 3) || (*sec_boot == 5));
}

TEE_Result fp_read(void *output, uint32_t addr, uint32_t size)
{
	return fp_ops.read(output, addr, size);
}

TEE_Result fp_write(const void *data, uint32_t addr, uint32_t size)
{
	return fp_ops.write(data, addr, size);
}

TEE_Result fp_erase(uint32_t addr, uint32_t size)
{
	return fp_ops.erase(addr, size);
}

#ifndef CFG_BYPASS_LOCK
TEE_Result fp_lock(void)
{
	if (check_sec_en()) {
		return fp_ops.lock();
	} else {
		return TEE_SUCCESS;
	}
}

TEE_Result fp_unlock(void)
{
	return fp_ops.unlock();
}
#endif // CFG_BYPASS_LOCK

const struct fp_flash_info *get_selected_flash_info(void)
{
	return selected_flash_info;
}

#if defined(CFG_FLASH_NOR)
/**
 * @data: data to be write
 * @addr: flash address to be write
 * @size: size of written data
 */
static TEE_Result fp_nor_write(const void *data, uint32_t addr, uint32_t size)
{
	uint32_t i;
	uint32_t status;
	uint32_t unread_bytes;
	uint32_t rd_addr;
	uint32_t rd_size;
	uint32_t rd_buf[20] = { 0 };
	uint8_t *rd_ptr = (uint8_t *)rd_buf;

	/* Check if data already exists at the range [addr, addr + size)
	 * Read max(size, 80 bytes) at a time to avoid allocating a large read 
	 * buffer.
	 */
	unread_bytes = size;
	rd_addr = addr;

	if (agtx_wait_nor_flash_ready(QSPI_TIMEOUT_TIME) == ETIMEOUT) {
		EMSG("Wait NOR ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	while (unread_bytes > 0) {
		/* Read max(size, 80 bytes) */
		rd_size = unread_bytes > 80 ? 80 : unread_bytes;

		agtx_nor_normal_read(rd_buf, rd_addr, rd_size);

		/* Check if data already exists (rd_buf[i] != 0xFF) */
		for (i = 0; i < rd_size; ++i) {
			if (rd_ptr[i] != 0xFF) {
				EMSG("Address 0x%x has already been programmed with %#x, rewriting is not allowed\n",
				     rd_addr, rd_ptr[i]);
				return EFAIL;
			}
		}

		unread_bytes -= rd_size;
		rd_addr += rd_size;
	}

	/* Write data */
	status = agtx_nor_normal_write(addr, size, (uint32_t *)data);
	if (status != ESUCCESS) {
		EMSG("Write failed\n");
		return TEE_ERROR_GENERIC;
	}

	return TEE_SUCCESS;
}

static TEE_Result fp_nor_erase(uint32_t addr, uint32_t size)
{
	uint32_t status = agtx_nor_erase_partition(addr, size);

	if (agtx_wait_nor_flash_ready(QSPI_TIMEOUT_TIME) == ETIMEOUT) {
		EMSG("Wait NOR ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	if (status != ESUCCESS)
		return TEE_ERROR_GENERIC;
	return TEE_SUCCESS;
}

static TEE_Result fp_nor_read(void *output, uint32_t addr, uint32_t size)
{
	uint32_t status;

	if (agtx_wait_nor_flash_ready(QSPI_TIMEOUT_TIME) == ETIMEOUT) {
		EMSG("Wait NOR ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	status = agtx_nor_normal_read((uint32_t *)output, addr, size);
	if (status != ESUCCESS) {
		EMSG("Read failed\n");
		return TEE_ERROR_GENERIC;
	}

	return TEE_SUCCESS;
}

#ifndef CFG_BYPASS_LOCK
static TEE_Result fp_nor_unlock(void)
{
	uint32_t status;
	uint32_t sr = 0;
	uint32_t cmd;

	switch (selected_flash_info->srl_offset >> 3) {
	case 0:
		cmd = NOR_FLASH_CMD__READ_SR1;
		break;
	case 1:
		cmd = NOR_FLASH_CMD__READ_SR2;
		break;
	case 2:
		cmd = NOR_FLASH_CMD__READ_SR3;
		break;
	default:
		EMSG("Unknown SRL offset setting\n");
		return TEE_ERROR_GENERIC;
	}

	/* Check if SRP1 / SRL bit is set */
	status = agtx_nor_read_status(cmd, &sr);
	if (status != ESUCCESS) {
		EMSG("Read flash SR2 failed\n");
		return TEE_ERROR_GENERIC;
	}
	if (sr & (1 << (selected_flash_info->srl_offset & 0x7))) {
		EMSG("Cannot unset BP bits: status register is locked\n");
		return TEE_ERROR_ACCESS_CONFLICT;
	}

	/* Unset all BP bits */
	status = agtx_nor_read_status(NOR_FLASH_CMD__READ_SR1, &sr);
	if (status != ESUCCESS) {
		EMSG("Read BP bits failed\n");
		return TEE_ERROR_GENERIC;
	}
	sr &= 0x83; /* 0x83: 1000_0011 */
	status = agtx_nor_write_enable();
	if (status != ESUCCESS) {
		EMSG("Write enable for SR failed\n");
		return TEE_ERROR_GENERIC;
	}
	status = agtx_nor_write_status(NOR_FLASH_CMD__WRITE_SR1, sr);
	if (status != ESUCCESS) {
		EMSG("Unset BP bits failed\n");
		return TEE_ERROR_GENERIC;
	}

	/* Wait until complete writing status register */
	if (agtx_wait_nor_flash_ready(WR_SR_TIMEOUT) == ETIMEOUT) {
		EMSG("Wait NOR ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	return TEE_SUCCESS;
}

/* Set SR1 to decide the region of protection area, SRL to lock SR1 */
static TEE_Result fp_nor_lock(void)
{
	uint32_t status;
	uint32_t sr = 0;
	uint32_t srl_mask;
	uint32_t cmd;

	/* Get current SR1 state */
	status = agtx_nor_read_status(NOR_FLASH_CMD__READ_SR1, &sr);
	if (status != ESUCCESS) {
		EMSG("Read flash SR1 failed\n");
		return TEE_ERROR_GENERIC;
	}
	sr = (sr | selected_flash_info->bp_mask) & 0xFF;

	status = agtx_nor_write_enable();
	if (status != ESUCCESS) {
		EMSG("Write enable for SR failed\n");
		return TEE_ERROR_GENERIC;
	}
	status = agtx_nor_write_status(NOR_FLASH_CMD__WRITE_SR1, sr);
	if (status != ESUCCESS) {
		EMSG("Write flash SR1 failed\n");
		return TEE_ERROR_GENERIC;
	}

	/* Wait until complete writing status register */
	if (agtx_wait_nor_flash_ready(WR_SR_TIMEOUT) == ETIMEOUT) {
		EMSG("Wait NOR ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	/* set SRL for power cycle lock down */
	cmd = (selected_flash_info->srl_offset >= 8) ? NOR_FLASH_CMD__READ_SR2 : NOR_FLASH_CMD__READ_SR1;
	srl_mask = 1 << (selected_flash_info->srl_offset & 0x7);
	status = agtx_nor_read_status(cmd, &sr);
	if (status != ESUCCESS) {
		EMSG("Read flash SR fail.\n");
		return TEE_ERROR_GENERIC;
	}
	sr = (sr | srl_mask) & 0xFF;

	status = agtx_nor_write_enable();
	if (status != ESUCCESS) {
		EMSG("WE for SR fail.\n");
		return TEE_ERROR_GENERIC;
	}

	status = agtx_nor_write_status(cmd, sr);
	if (status != ESUCCESS) {
		EMSG("Write flash SR failed\n");
		return TEE_ERROR_GENERIC;
	}

	/* Wait until complete writing status register */
	if (agtx_wait_nor_flash_ready(WR_SR_TIMEOUT) == ETIMEOUT) {
		EMSG("Wait NOR ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	return TEE_SUCCESS;
}
#endif // CFG_BYPASS_LOCK

static inline void register_fp_ops_nor(void)
{
	fp_ops.read = &fp_nor_read;
	fp_ops.write = &fp_nor_write;
	fp_ops.erase = &fp_nor_erase;
#ifndef CFG_BYPASS_LOCK
	fp_ops.lock = &fp_nor_lock;
	fp_ops.unlock = &fp_nor_unlock;
#endif // CFG_BYPASS_LOCK
}
#endif /* CFG_FLASH_NOR */

#if defined(CFG_FLASH_NAND)

#define GET_OFFSET_ADDRESS(x, y) ((x) + NAND_FLASH_BLOCK_SIZE * (y))

static uint32_t g_protected_block_offset = 0;
static uint32_t g_shadow_block_offset = 0;

static void get_block_info(uint32_t addr, uint32_t **block_offset, uint32_t *block_limit)
{
	uint32_t protected_base;

	protected_base = selected_flash_info->capacity - selected_flash_info->fp_size;
	if (addr >= protected_base) {
		*block_offset = &g_protected_block_offset;
		*block_limit = selected_flash_info->capacity;
	} else {
		*block_offset = &g_shadow_block_offset;
		*block_limit = protected_base;
	}
}

static uint32_t bad_block_handle(uint32_t addr, uint32_t *block_offset, uint32_t block_limit)
{
	uint32_t status = EFAIL;
	uint32_t block_base;

	++(*block_offset);
	if (GET_OFFSET_ADDRESS(addr, *block_offset) >= block_limit) {
		EMSG("Device locked: all NAND monotonic counter blocks are bad, security features unavailable\n");
		goto err_unknown;
	}

	/* Erase new block */
	block_base = (addr & ~(NAND_FLASH_BLOCK_SIZE - 1)) + NAND_FLASH_BLOCK_SIZE * (*block_offset);
	status = agtx_nand_normal_erase(block_base, NAND_FLASH_BLOCK_SIZE);
	if (status != ESUCCESS)
		goto err_unknown;

	return ESUCCESS;
err_unknown:
	return status;
}

static uint32_t restore_page_data(const void *data, uint32_t addr, uint32_t size)
{
	const uint32_t *pBuf = data;
	uint32_t status;
	uint32_t byte_addr;
	uint32_t byte_unwrite;
	uint32_t chunk_size;
	uint32_t byte_remain;
	uint32_t byte_count;
	uint32_t page_base;
	uint32_t page_limit;
	uint32_t wr_page;
	bool had_written;

	DMSG("Restore page data when program page at %#x\n", addr);
	status = agtx_nand_write_enable();
	if (status != ESUCCESS)
		goto err_unknown;

	/* Set NAND data buffer */
	byte_unwrite = size;
	byte_addr = addr & (NAND_FLASH_PAGE_SIZE - 1);
	had_written = false;
	while (byte_unwrite && byte_addr < NAND_FLASH_PAGE_SIZE) {
		chunk_size = (byte_unwrite > QSPI_TX_FIFO_SIZE) ? QSPI_TX_FIFO_SIZE : byte_unwrite;
		byte_remain = NAND_FLASH_PAGE_SIZE - byte_addr;
		byte_count = (chunk_size > byte_remain) ? byte_remain : chunk_size;
		status = agtx_nand_write(pBuf, byte_addr, byte_count, had_written);
		if (status != ESUCCESS)
			goto err_unknown;

		if (had_written == false)
			had_written = true;

		pBuf += (byte_count >> 2);
		byte_addr += byte_count;
		byte_unwrite -= byte_count;
	}

	/* Program current and all preceding pages */
	page_base = nand_addr_to_page(addr & ~(NAND_FLASH_BLOCK_SIZE - 1), BYTES_OFFSET_2048);
	page_limit = nand_addr_to_page(addr, BYTES_OFFSET_2048);
	DMSG("Restore data from %#x to %#x\n", (page_base << BYTES_OFFSET_2048), (page_limit << BYTES_OFFSET_2048));
	for (wr_page = page_base; wr_page <= page_limit; ++wr_page) {
		status = agtx_nand_write_enable();
		if (status != ESUCCESS)
			goto err_unknown;

		status = agtx_nand_program(wr_page);
		if (status != ESUCCESS)
			goto err_unknown;
	}

	return ESUCCESS;

err_unknown:
	return status;
}

/**
 * @data: data to be write
 * @addr: flash address to be write
 * @size: size of written data
 */
static TEE_Result fp_nand_write(const void *data, uint32_t addr, uint32_t size)
{
	const uint8_t *data_ptr = data;
	uint8_t rd_buf[size];
	uint32_t status;
	uint32_t block_base_idx;
	uint32_t block_limit;
	uint32_t *block_offset;
	uint32_t i;

	status = agtx_wait_nand_ready(QSPI_TIMEOUT_TIME);
	if (status != ESUCCESS)
		goto err_unknown;

	get_block_info(addr, &block_offset, &block_limit);
	if (GET_OFFSET_ADDRESS(addr, *block_offset) >= block_limit) {
		EMSG("Device locked: all NAND monotonic counter blocks are bad, security features unavailable\n");
		goto err_unknown;
	}
	DMSG("Write %d bytes to %#x\n", size, GET_OFFSET_ADDRESS(addr, *block_offset));
	status = agtx_nand_normal_write((uint32_t *)data, GET_OFFSET_ADDRESS(addr, *block_offset), size);
	if (status != ESUCCESS)
		goto err_unknown;

	/* Check bad block */
	block_base_idx = nand_addr_to_block(addr, BYTES_OFFSET_2048, PAGES_OFFSET_64);
	status = agtx_nand_is_bad_block(block_base_idx + *block_offset, BYTES_OFFSET_2048, PAGES_OFFSET_64);
	if (status == EBADBLOCK) {
		status = bad_block_handle(addr, block_offset, block_limit);
		if (status != ESUCCESS)
			goto err_unknown;
		else
			status = restore_page_data(data, GET_OFFSET_ADDRESS(addr, *block_offset), size);
	}

	if (status != ESUCCESS)
		goto err_unknown;

	/* Check write result */
	status = agtx_nand_normal_read((void *)rd_buf, GET_OFFSET_ADDRESS(addr, *block_offset), size);
	if (status != ESUCCESS)
		goto err_unknown;

	for (i = 0; i < size; ++i) {
		if (data_ptr[i] != rd_buf[i]) {
			EMSG("Write verification failed: data mismatch\n");
			goto err_unknown;
		}
	}
	return TEE_SUCCESS;
err_unknown:
	return TEE_ERROR_GENERIC;
}

static TEE_Result fp_nand_erase(uint32_t addr, uint32_t size)
{
	uint32_t status;
	uint32_t block_base_idx;
	uint32_t block_limit;
	uint32_t *block_offset;

	status = agtx_wait_nand_ready(QSPI_TIMEOUT_TIME);
	if (status != ESUCCESS)
		goto err_unknown;

	get_block_info(addr, &block_offset, &block_limit);
	if (GET_OFFSET_ADDRESS(addr, *block_offset) >= block_limit) {
		EMSG("Device locked: all NAND monotonic counter blocks are bad, security features unavailable\n");
		goto err_unknown;
	}
	DMSG("Erase %#x\n", GET_OFFSET_ADDRESS(addr, *block_offset));
	status = agtx_nand_normal_erase(GET_OFFSET_ADDRESS(addr, *block_offset), size);
	if (status != ESUCCESS)
		goto err_unknown;

	/* Check bad block */
	block_base_idx = nand_addr_to_block(addr, BYTES_OFFSET_2048, PAGES_OFFSET_64);
	status = agtx_nand_is_bad_block(block_base_idx + *block_offset, BYTES_OFFSET_2048, PAGES_OFFSET_64);
	if (status == EBADBLOCK)
		status = bad_block_handle(addr, block_offset, block_limit);
	if (status != ESUCCESS)
		goto err_unknown;

	return TEE_SUCCESS;
err_unknown:
	return TEE_ERROR_GENERIC;
}

static TEE_Result fp_nand_read(void *output, uint32_t addr, uint32_t size)
{
	uint32_t status;
	uint32_t block_base_idx;
	uint32_t block_limit;
	uint32_t *block_offset;

	status = agtx_wait_nand_ready(QSPI_TIMEOUT_TIME);
	if (status != ESUCCESS)
		goto err_unknown;

	/* Skip bad block */
	get_block_info(addr, &block_offset, &block_limit);
	if (addr + NAND_FLASH_BLOCK_SIZE * (*block_offset) >= block_limit) {
		EMSG("Device locked: all NAND monotonic counter blocks are bad, security features unavailable\n");
		goto err_unknown;
	}
	block_base_idx = nand_addr_to_block(addr, BYTES_OFFSET_2048, PAGES_OFFSET_64);
	do {
		status = agtx_nand_is_bad_block(block_base_idx + *block_offset, BYTES_OFFSET_2048, PAGES_OFFSET_64);
		if (status == EBADBLOCK)
			++(*block_offset);
		else if (status != ESUCCESS)
			goto err_unknown;

		/* Case all block in protected/shadow block is bad */
		if (addr + (*block_offset) * NAND_FLASH_BLOCK_SIZE >= block_limit) {
			EMSG("Device locked: all NAND monotonic counter blocks are bad, security features "
			     "unavailable\n");
			goto err_unknown;
		}
	} while (status == EBADBLOCK);

	status = agtx_nand_normal_read((uint32_t *)output, addr + (*block_offset) * NAND_FLASH_BLOCK_SIZE, size);
	if (status != ESUCCESS)
		goto err_unknown;

	return TEE_SUCCESS;
err_unknown:
	return TEE_ERROR_GENERIC;
}

#ifndef CFG_BYPASS_LOCK
static TEE_Result fp_nand_unlock(void)
{
	uint32_t status;
	uint32_t sr = 0;
	uint32_t srl_addr;

	status = agtx_wait_nand_ready(QSPI_TIMEOUT_TIME);
	if (status != ESUCCESS)
		return TEE_ERROR_GENERIC;

	switch (selected_flash_info->srl_offset >> 3) {
	case 0:
		srl_addr = NAND_SR1_ADDR;
		break;
	case 1:
		srl_addr = NAND_SR2_ADDR;
		break;
	case 2:
		srl_addr = NAND_SR3_ADDR;
		break;
	default:
		EMSG("Unknown SRL offset setting\n");
		return TEE_ERROR_GENERIC;
	}

	/* Check if SRP1 / SRL bit is set */
	status = agtx_nand_read_status(srl_addr, &sr);
	if (status != ESUCCESS) {
		EMSG("Failed to get SRP1 / SRL status\n");
		return TEE_ERROR_GENERIC;
	}
	if (sr & (1 << (selected_flash_info->srl_offset & 0x7))) {
		EMSG("Cannot unset BP bits: status register is locked\n");
		return TEE_ERROR_ACCESS_CONFLICT;
	}

	/* Unset all BP bits */
	sr = 0;
	status = agtx_nand_write_enable();
	if (status != ESUCCESS) {
		EMSG("Write enable for SR1 failed\n");
		return TEE_ERROR_GENERIC;
	}
	status = agtx_nand_write_status(NAND_SR1_ADDR, sr);
	if (status != ESUCCESS) {
		EMSG("Unset BP bits failed\n");
		return TEE_ERROR_GENERIC;
	}

	/* Wait until complete writing status register */
	if (agtx_wait_nand_ready(WR_SR_TIMEOUT) == ETIMEOUT) {
		EMSG("Wait NAND ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	return TEE_SUCCESS;
}

static TEE_Result fp_nand_lock(void)
{
	uint32_t status;
	uint32_t sr = 0;
	uint32_t srl_addr;

	status = agtx_wait_nand_ready(QSPI_TIMEOUT_TIME);
	if (status != ESUCCESS)
		return TEE_ERROR_GENERIC;

	/* Get current BP bits state */
	status = agtx_nand_read_status(NAND_SR1_ADDR, &sr);
	if (status != ESUCCESS) {
		EMSG("Read BP bits failed\n");
		return TEE_ERROR_GENERIC;
	}
	sr = (sr | selected_flash_info->bp_mask) & 0xFF;

	status = agtx_nand_write_enable();
	if (status != ESUCCESS) {
		EMSG("Write enable for SR1 failed\n");
		return TEE_ERROR_GENERIC;
	}
	status = agtx_nand_write_status(NAND_SR1_ADDR, sr);
	if (status != ESUCCESS) {
		EMSG("Set BP bits failed\n");
		return TEE_ERROR_GENERIC;
	}

	/* Wait until complete writing status register */
	if (agtx_wait_nand_ready(WR_SR_TIMEOUT) == ETIMEOUT) {
		EMSG("Wait NAND ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	/* set SRL for power cycle lock down */
	switch (selected_flash_info->srl_offset >> 3) {
	case 0:
		srl_addr = NAND_SR1_ADDR;
		break;
	case 1:
		srl_addr = NAND_SR2_ADDR;
		break;
	case 2:
		srl_addr = NAND_SR3_ADDR;
		break;
	default:
		EMSG("Unknown SRL offset setting\n");
		return TEE_ERROR_GENERIC;
	}

	status = agtx_nand_read_status(srl_addr, &sr);
	if (status != ESUCCESS) {
		EMSG("Read SRL fail.\n");
		return TEE_ERROR_GENERIC;
	}
	sr = (sr | (1 << (selected_flash_info->srl_offset & 0x7))) & 0xFF;

	status = agtx_nand_write_enable();
	if (status != ESUCCESS) {
		EMSG("WE for SR fail.\n");
		return TEE_ERROR_GENERIC;
	}

	status = agtx_nand_write_status(srl_addr, sr);
	if (status != ESUCCESS) {
		EMSG("Write SRL bit failed\n");
		return TEE_ERROR_GENERIC;
	}

	/* Wait until complete writing status register */
	if (agtx_wait_nand_ready(WR_SR_TIMEOUT) == ETIMEOUT) {
		EMSG("Wait NAND ready timeout\n");
		return TEE_ERROR_TIMEOUT;
	}

	return TEE_SUCCESS;
}
#endif // CFG_BYPASS_LOCK

static inline void register_fp_ops_nand(void)
{
	fp_ops.read = &fp_nand_read;
	fp_ops.write = &fp_nand_write;
	fp_ops.erase = &fp_nand_erase;
#ifndef CFG_BYPASS_LOCK
	fp_ops.lock = &fp_nand_lock;
	fp_ops.unlock = &fp_nand_unlock;
#endif // CFG_BYPASS_LOCK
}
#endif /* CFG_FLASH_NAND */

/* Read the JEDEC ID and check if the flash is supported */
TEE_Result fp_check_support(void)
{
	uint32_t i;
	uint32_t flash_id = 0;
	uint32_t status = ESUCCESS;

	/* Read JEDEC ID */
#if defined(CFG_FLASH_NOR)
	register_fp_ops_nor();

	status = agtx_nor_read_id((uint8_t *)&flash_id);
#elif defined(CFG_FLASH_NAND)
	register_fp_ops_nand();

	status = agtx_nand_read_id((uint8_t *)&flash_id);
#endif /* defined(CFG_FLASH_NOR) */
	DMSG("Flash ID: %#x\n", flash_id);

	if (status != ESUCCESS) {
		EMSG("Read Flash ID failed\n");
		return TEE_ERROR_GENERIC;
	}

	/* Check NOR flash support list */
	for (i = 0; i < FLASH_LIST_LEN; ++i) {
		if (flash_info_list[i].id == 0) {
			EMSG("Unsupported flash\n");
			return TEE_ERROR_NOT_SUPPORTED;
		}

		if (flash_info_list[i].id == flash_id) {
			selected_flash_info = &flash_info_list[i];

			DMSG("Using flash with following information:\n");
			DMSG("\tID: %#x\n", selected_flash_info->id);
			DMSG("\tCapacity: %#x\n", selected_flash_info->capacity);
			DMSG("\tProtection area size: %#x\n", selected_flash_info->fp_size);
			DMSG("\tBlock protection bits mask: %#x\n", selected_flash_info->bp_mask);
			DMSG("\tStatus register lock (SRL) bit offset: %#x\n", selected_flash_info->srl_offset);

			break;
		}
	}

	return TEE_SUCCESS;
}
