#include "address_map.h"

#include "csr_bank_qspi.h"
#include "csr_bank_qspir.h"
#include "csr_bank_qspiw.h"
#include "hw_qspi.h"
#include "printf.h"
#include "uart.h"

#include "nvspc_define.h"
#include "nvspc_flash.h"
#include "autoconf.h"
#include "pinmux/pinmux.h"

struct qspi_dev g_qspi = { .base_addr = QSPI_BASE };

#define QSPI_PAGE_BASE 0

#include "csr_bank_rst.h"

// #define CONFIG_NOR_UNSET_BP_BITS

static uint32_t user_flash_type = 0; //when we init it, it can't modify
static uint32_t nor_flash_addr_mode = NOR_3BYTE_ADDR_MODE;

static int quad_dual_mode;

__attribute__((unused)) static int write_to_nand_partition(uint32_t block_base, uint32_t block_num, uintptr_t mem_base,
                                                           uint32_t img_size, uint32_t write_progress)
{
	uint8_t *data = (uint8_t *)mem_base;
	int status = -ESUCCESS;
	uint32_t block_addr = block_base;
	uint32_t write_addr = 0;
	uint32_t byte_count = 0;
	uint32_t byte_to_write = img_size;
	uint32_t block_count = block_num;
	int first_flag = 1;
	uint32_t page_base = QSPI_PAGE_BASE;
	int ratio = 0;

	do {
		status = is_bad_block(&g_qspi, block_addr, BYTES_OFFSET_2048, PAGES_OFFSET_64);
		if (status != -ESUCCESS) {
			if (status == -EFAIL) {
				printf("[WARN] Bad block detected, flash address = 0x%08x.\n", (block_addr << 17));
			} else {
				printf("[ERROR] NAND read error while checking bad blocks\n");
				return -EFAIL;
			}
			block_addr += 1;
			if (block_addr >= (block_base + block_num)) {
				printf("[WARN] Bad block: Out of block.\n");
				if (byte_to_write == 0) {
					return -ESUCCESS;
				} else {
					printf("[ERROR] %s: Out of block & byte_to_write != 0\n", __func__);
					return -EFAIL;
				}
			} else {
				continue;
			}
		}

		if (block_addr >= (block_base + block_num)) {
			if (byte_to_write == 0) {
				return -ESUCCESS;
			} else {
				printf("[ERROR] %s: block_addr over range\n", __func__);
				return -EFAIL;
			}
		}

		while (byte_to_write > 0) {
			if (nand_write_enable(&g_qspi) == -ETIMEOUT) {
				printf("exec: WE timeout\n");
			}

			while (write_addr < 2048) {
				/* Kyoto limitation: Do not fill QSPI_FIFO full when writing operation */
				byte_count = (byte_to_write > ((QSPI_TX_FIFO_DEPTH - 2) << 2)) ?
				                     ((QSPI_TX_FIFO_DEPTH - 2) << 2) :
				                     byte_to_write;

				if (write_addr + byte_count > 2048) {
					byte_count = 2048 - write_addr;
				}

				if (quad_dual_mode == QUAD_MODE) {
					status = nand_write(&g_qspi, write_addr, byte_count, (uint32_t *)data,
					                    first_flag, quad_dual_mode);
				} else if (quad_dual_mode == SINGLE_MODE) {
					status = nand_write(&g_qspi, write_addr, byte_count, (uint32_t *)data,
					                    first_flag, quad_dual_mode);
				} else {
					printf("[Err] NAND write: This frame format is not support.\n");
					return -EFAIL;
				}

				if (status != -ESUCCESS) {
					printf("[WARN] Write flash data fail.\n");
				}

				if (first_flag == 1) {
					first_flag = 0;
				}

				data += byte_count;
				byte_to_write -= byte_count;
				write_addr += byte_count;

				if (byte_to_write == 0) {
					break;
				}
			}

			status = nand_program_execute(&g_qspi, (block_addr << PAGES_OFFSET_64) + page_base);

			if (status != -ESUCCESS) {
				printf("[WARN] Execute program fail.\n");
			}

			page_base += 1;
			write_addr = 0;
			first_flag = 1;

			if (write_progress == 1) {
				if ((((img_size - byte_to_write) * 100) / img_size) > ratio) {
					printf("REQ(prog:%d)\n", (((img_size - byte_to_write) * 100) / img_size));
					ratio = (((img_size - byte_to_write) * 100) / img_size);
				}
			}

			if ((page_base % pages_per_blk(PAGES_OFFSET_64)) == 0) {
				page_base = 0;
				break;
			}
		}
		block_count--;
		block_addr += 1;
	} while (block_count > 0);

	return -ESUCCESS;
}

__attribute__((unused)) static int write_to_nor_partition(uint32_t part_addr, uint32_t part_size, uintptr_t mem_addr,
                                                          uint32_t img_size, uint32_t write_progress)
{
	int status = -ESUCCESS;
	uint32_t byte_to_write = img_size;
	uint32_t write_len = 0;
	uint8_t *mem_addr_ptr;
	int ratio = 0;

	mem_addr_ptr = (uint8_t *)mem_addr;

	/* Check partition start address whether align with 4KB or not*/
	if ((part_addr % 4096) != 0) {
		printf("Wrong partition start address");
		return -EFAIL;
	}

	/* Check partition size whether align with 4KB or not*/
	if ((part_size % 4096) != 0) {
		printf("Wrong partition size");
		return -EFAIL;
	}

	while (byte_to_write) {
		if (byte_to_write >= 256) {
			write_len = 256;
		} else {
			write_len = byte_to_write;
		}

		status = nor_write_page(&g_qspi, part_addr, mem_addr_ptr, write_len, nor_flash_addr_mode,
		                        quad_dual_mode);
		if (status != -ESUCCESS) {
			printf("Writing page fail. \n");
			return -EFAIL;
		}

		part_addr += write_len;
		byte_to_write -= write_len;
		mem_addr_ptr += write_len;

		if (write_progress == 1) {
			if ((((img_size - byte_to_write) * 100) / img_size) > ratio) {
				printf("REQ(prog:%d)\n", (((img_size - byte_to_write) * 100) / img_size));
				ratio = (((img_size - byte_to_write) * 100) / img_size);
			}
		}
	}

	return -ESUCCESS;
}

#ifdef CONFIG_NOR_UNSET_BP_BITS
static uint32_t nor_get_sr1(void)
{
	uint32_t status = -ESUCCESS;
	uint32_t sr1 = 0;

	status = nor_read_status(&g_qspi, NOR_FLASH_CMD__READ_SR1, &sr1);
	if (status != -ESUCCESS) {
		printf("Read SR1 failed\n");
		return 0;
	}
	sr1 &= 0xFF;

	return sr1;
}

static int nor_get_sr2(void)
{
	uint32_t status = -ESUCCESS;
	uint32_t sr2 = 0;

	status = nor_read_status(&g_qspi, NOR_FLASH_CMD__READ_SR2, &sr2);
	if (status != -ESUCCESS) {
		printf("Read SR2 failed\n");
		return 0;
	}
	sr2 &= 0xFF;

	return sr2;
}
#endif /* CONFIG_NOR_UNSET_BP_BITS */

int init_flash(uint32_t flash_type, BootConfig *boot_config)
{
	int status = -ESUCCESS;
	int ret = 0;
	uint32_t part_num = boot_config->part_num;
	uint32_t last_pt_start = boot_config->pt_list[part_num - 1].nvs_start;
	uint32_t last_pt_size = boot_config->pt_list[part_num - 1].nvs_size;
	uint32_t sr1 __attribute__((unused)) = 0;
	uint32_t sr2 __attribute__((unused)) = 0;

	if (flash_type == WRITE_TO_NAND) {
		qspi_init(&g_qspi);
		ret = nand_reset(&g_qspi);
		status |= ret;
		ret = nand_init(&g_qspi);
		status |= ret;
	} else if (flash_type == WRITE_TO_NOR) {
		qspi_init(&g_qspi);
		ret = nor_reset(&g_qspi);
		status |= ret;

		//ret = nor_init(&g_qspi); Dream: after discussion, don't to init 2021.05.14
		//printf("nor_init=%d\n", ret);

		if (last_pt_start + last_pt_size > 64 * 1024 * 256) {
			nor_enter_4byte_mode(&g_qspi);
			nor_flash_addr_mode = NOR_4BYTE_ADDR_MODE;
			printf("NOR with 4byte mode\n");
		} else {
			nor_flash_addr_mode = NOR_3BYTE_ADDR_MODE;
			printf("NOR with 3byte mode\n");
		}

		/* #91613 */
#ifdef CONFIG_NOR_UNSET_BP_BITS
		/* Check SR first */
		sr1 = nor_get_sr1();
		printf("SR1: 0x%x\n", sr1);
		sr2 = nor_get_sr2();
		printf("SR2: 0x%x\n", sr2);

		/* Check if any BP bits are set */
		/* If so, unset all set BP bits */
		/* 0x7C: 0111_1100, each 1 indicates a BP bit is set */
		if (sr1 & 0x7C) {
			printf("Unset BP bits\n");
			nor_unlock_blk_prot(&g_qspi);
			wait_nor_flash_ready(&g_qspi, QSPI_TIMEOUT_TIME);

			/* Check write result in non-volatile mode */
			sr1 = nor_get_sr1();
			printf("SR1: 0x%x\n", sr1);
			sr2 = nor_get_sr2();
			printf("SR2: 0x%x\n", sr2);
		}
#endif /* CONFIG_NOR_UNSET_BP_BITS */
	}

	/* Adjust QSPI pin driving strength */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	pinmux_set_pinconf(12, PINCFG_DS, 0x7); // QSPI_CE
	pinmux_set_pinconf(13, PINCFG_DS, 0x7); // QSPI_D1
	pinmux_set_pinconf(14, PINCFG_DS, 0x7); // QSPI_D2
	pinmux_set_pinconf(15, PINCFG_DS, 0x7); // QSPI_D3
	pinmux_set_pinconf(16, PINCFG_DS, 0x7); // QSPI_CK
	pinmux_set_pinconf(17, PINCFG_DS, 0x7); // QSPI_D0
#else
	pinmux_set_pinconf(20, PINCFG_DS, 0x7); // QSPI_CE
	pinmux_set_pinconf(21, PINCFG_DS, 0x7); // QSPI_D1
	pinmux_set_pinconf(22, PINCFG_DS, 0x7); // QSPI_D2
	pinmux_set_pinconf(23, PINCFG_DS, 0x7); // QSPI_D3
	pinmux_set_pinconf(24, PINCFG_DS, 0x7); // QSPI_CK
	pinmux_set_pinconf(25, PINCFG_DS, 0x7); // QSPI_D0
#endif
	user_flash_type = flash_type;

	return status;
}

__attribute__((unused)) static int erase_nand_partition(uint32_t part_base, uint32_t part_size, uint32_t erase_progress,
                                                        uint32_t part_num)
{
	uint32_t block_base = (uint32_t)nand_addr_to_block(part_base, BYTES_OFFSET_2048, PAGES_OFFSET_64);
	uint32_t block_num = (uint32_t)nand_addr_to_block(part_size, BYTES_OFFSET_2048, PAGES_OFFSET_64);

	int status = -ESUCCESS;
	uint32_t block_addr = block_base;
	uint32_t ratio = 0;

	do {
		status = is_bad_block(&g_qspi, block_addr, BYTES_OFFSET_2048, PAGES_OFFSET_64);
		if (status != -ESUCCESS) {
			if (status == -EFAIL) {
				printf("Bad block detected, block_addr = 0x%08x.\n", block_addr);
			} else {
				printf("NAND read error while checking bad blocks\n");
				return status;
			}
		} else {
			status = nand_block_erase(&g_qspi, block_addr << PAGES_OFFSET_64);
			if (status == -EFAIL) {
				printf("Block (0x%08x) erase fail.\n",
				       (block_addr << (BYTES_OFFSET_2048 + PAGES_OFFSET_64)));
				return status;
			}
			if (status == -ETIMEOUT) {
				printf("Block (0x%08x) erase timeout.\n",
				       (block_addr << (BYTES_OFFSET_2048 + PAGES_OFFSET_64)));
				return status;
			}
		}

		block_addr += 1;

		if (erase_progress == 1) {
			if ((((block_addr - block_base) * 100) / block_num) > ratio) {
				printf("REQ(eprog:%d,%d)\n", part_num, (((block_addr - block_base) * 100) / block_num));
				ratio = (((block_addr - block_base) * 100) / block_num);
			}
		}

	} while (block_addr < (block_base + block_num));

	return -ESUCCESS;
}

__attribute__((unused)) static int erase_nor_partition(uint32_t part_base, uint32_t part_size, uint32_t erase_progress,
                                                       uint32_t part_num)
{
	int status = -ESUCCESS;
	uint32_t ratio = 0;
	uint32_t erase_base = part_base;
	uint32_t erase_size = part_size;

	while (erase_size) {
		if ((erase_size >= 65536) && ((erase_base % 65536) == 0)) {
			status = nor_one_block_erase(&g_qspi, erase_base, nor_flash_addr_mode);
			erase_base += 65536;
			erase_size -= 65536;
		} else if ((erase_size >= 32768) && ((erase_base % 32768) == 0) && (erase_base < 0x1000000)) {
			//Because nor 32K erase doesn't support flashsize > 16Mb
			status = nor_half_block_erase(&g_qspi, erase_base, nor_flash_addr_mode);
			erase_base += 32768;
			erase_size -= 32768;
		} else if ((erase_size >= 4096) && ((erase_base % 4096) == 0)) {
			status = nor_sector_erase(&g_qspi, erase_base, nor_flash_addr_mode);
			erase_base += 4096;
			erase_size -= 4096;
		} else {
			printf("Wrong address or size\n");
			return -EFAIL;
		}

		if (status != -ESUCCESS) {
			printf("NOR erase fail\n");
#ifdef CONFIG_OPTEE
			// Skip erase failure for the monotonic counter since it is write-protected
			if (part_num == CONFIG_PT_NUM_MONO_CNT) {
				printf("Monotonic Counter is write-locked. Failed to erase.\n");
				return -ESUCCESS;
			}
#endif // CONFIG_OPTEE
			if (nor_flash_addr_mode == NOR_4BYTE_ADDR_MODE) {
				printf("Check your flash IC, the capacity might be wrong\n");
			}
			return status;
		}

		if (erase_progress == 1) {
			if ((((part_size - erase_size) * 100) / part_size) > ratio) {
				printf("REQ(eprog:%d,%d)\n", part_num, (((part_size - erase_size) * 100) / part_size));
				ratio = (((part_size - erase_size) * 100) / part_size);
			}
		}
	}

	return status;
}

int nvspc_erase_partition(uint32_t part_base, uint32_t part_size, uint32_t erase_progress, uint32_t part_num)
{
	int status = -ESUCCESS;

	if (user_flash_type == WRITE_TO_NAND) {
#if (CONFIG_FLASH_NAND == 1)
		printf("Erase NAND partition %d, base=0x%x size=0x%x\n", part_num, part_base, part_size);
		status = erase_nand_partition(part_base, part_size, erase_progress, part_num);
#else
		printf("NAND Flash is not support in this FW");
		return -EFAIL;
#endif
	} else if (user_flash_type == WRITE_TO_NOR) {
#if (CONFIG_FLASH_NOR == 1)
		printf("Erase NOR partition %d, base=0x%x size=0x%x\n", part_num, part_base, part_size);
		status = erase_nor_partition(part_base, part_size, erase_progress, part_num);
#else
		printf("NOR Flash is not support in this FW");
		return -EFAIL;
#endif
	} else {
		status = -EFAIL;
	}

	return status;
}

int read_from_partition(uint32_t nvs_start, uint32_t nvs_size, uintptr_t img_addr, uint32_t img_size)
{
	int status = -ESUCCESS;
	uint32_t mem_start = img_addr;

	printf("Load from flash base 0x%08x to DRAM 0x%08x, size = 0x%08x\n", nvs_start, mem_start, img_size);

	if (user_flash_type == WRITE_TO_NAND) {
#if (CONFIG_FLASH_NAND == 1)
		nand_read_skip_bad_block(&g_qspi, nvs_start, nvs_size, mem_start, img_size, quad_dual_mode);
#else
		printf("NAND Flash is not support in this FW");
		return -EFAIL;
#endif
	} else if (user_flash_type == WRITE_TO_NOR) {
#if (CONFIG_FLASH_NOR == 1)
		uint32_t *load_addr = (uint32_t *)img_addr;
		nor_normal_read(&g_qspi, load_addr, nvs_start, img_size, nor_flash_addr_mode, quad_dual_mode);
#else
		printf("NOR Flash is not support in this FW");
		return -EFAIL;
#endif
	} else {
		printf("Wrong user_flash_type \n");
		return -EFAIL;
	}

	return status;
}

void get_quad_mode_detection(int flash_type)
{
	uint8_t pattern[8] = { 0 };

	/* address 2040 to 2047 */
	if (flash_type == 0) {
		nand_page_read(&g_qspi, 0);
		nand_read(&g_qspi, 2040, 8, QUAD_MODE);
		qspi_fifo_read(&g_qspi, (uint32_t *)pattern, 8);
	} else {
		nor_read(&g_qspi, 2040, 8, NOR_3BYTE_ADDR_MODE, QUAD_MODE);
		qspi_fifo_read(&g_qspi, (uint32_t *)pattern, 8);
	}

	if (pattern[0] == 0x6A && pattern[1] == 0x6A && pattern[2] == 0xA6 && pattern[3] == 0x6A &&
	    pattern[4] == 0x99 && pattern[5] == 0x95 && pattern[6] == 0x55 && pattern[7] == 0x59) {
		printf("Use QUAD_MODE \n");
		quad_dual_mode = QUAD_MODE;

	} else {
		printf("Use SINGLE_MODE \n");
		quad_dual_mode = SINGLE_MODE;
	}
}

int write_to_partition(uint32_t part_base, uint32_t part_size, uintptr_t mem_base, uint32_t img_size,
                       uint32_t write_progress)
{
	int status = -ESUCCESS;

	if (user_flash_type == WRITE_TO_NAND) {
#if (CONFIG_FLASH_NAND == 1)
		printf("Write mem_address=0x%x to nand. part address=0x%x part size=0x%x, image size=0x%x\n", mem_base,
		       part_base, part_size, img_size);

		status = write_to_nand_partition(
		        (uint32_t)nand_addr_to_block(part_base, BYTES_OFFSET_2048, PAGES_OFFSET_64),
		        (uint32_t)nand_addr_to_block(part_size, BYTES_OFFSET_2048, PAGES_OFFSET_64), (uint32_t)mem_base,
		        (uint32_t)img_size, write_progress);

		if (status != -ESUCCESS) {
			printf("[ERROR] write_to_nand_partition failed\n.");
		}
#else
		printf("NAND Flash is not support in this FW");
		return -EFAIL;
#endif
	} else if (user_flash_type == WRITE_TO_NOR) {
#if (CONFIG_FLASH_NOR == 1)
		printf("Write mem_address=0x%x to nor. part address=0x%x part size=0x%x, image size=0x%x\n", mem_base,
		       part_base, part_size, img_size);

		status = write_to_nor_partition(part_base, part_size, mem_base, img_size, write_progress);
		if (status != -ESUCCESS) {
			printf("[ERROR] write_to_nor_partition failed\n.");
		}
#else
		printf("NOR Flash is not support in this FW");
		return -EFAIL;
#endif
	}
	return status;
}

void exit_flash_program(void)
{
	if ((user_flash_type == WRITE_TO_NOR) && (nor_flash_addr_mode == NOR_4BYTE_ADDR_MODE)) {
		nor_exit_4byte_mode(&g_qspi);
	}
}
