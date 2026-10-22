#include <string.h>

#include "address_map.h"
#include "checksum.h"
#include "delay.h"

#include "nvspc_define.h"
#include "nvspc_flash.h"

#include "hw_pc.h"
#include "hw_dram.h"
#include "hw_qspi.h"
#include "uart.h"
#include "printf.h"
#include "nvsp_mach.h"
#include "nvspc.h"
#include "pinmux.h"
#include "autoconf.h"

extern struct uart_dev g_uart;
extern uint32_t stack_end;

enum FLAG_ERROR_NUM {
	ERASE_PART_FAIL = 1,
	BAUDRATE_FAIL = 5,
	DDR_INIT_FAIL = 10,
	PARTTBL_CHECKSUM_FAIL = 15,
	SSBL_CHECKSUM_FAIL = 16,
	FLASH_INIT_FAIL = 30,
	EFUSE_DONE = 900,
	BURN_DONE = 1000,
} flag_error_num;

void is_burn_ok(int flag, int index)
{
	if (flag == 0)
		printf("REQ(IMG_OK:%d)\n", index);
	else
		printf("REQ(IMG_FAIL:%d)\n", index);
}

#define LOG_REQ(req_name) printf("REQ(%s)\n", req_name)

#define MAX_BUFFER 65536
#define CHECK_NUM 10
#define UART_DIV 16

#define ENABLE_WRITE_PROGRESS 0x10
#define ENABLE_ERASE_PROGRESS 0x20

#define UART_ERROR "Please check your UART connection and try again\n"
#define DRAM_ERROR "Please check your DRAM and try again\n"
#define FLASH_ERROR "Please check your QSPI connection and flash, then try again\n"

int mainEntry(void)
{
	int i;
	int err = 0;

	BootConfig *boot_config = (BootConfig *)PARTTBL_ADDR;
	uint32_t cal_checksum;
	uint32_t part_table_size;
	uint32_t part_table_checksum;

	uintptr_t img_addr = IMG_OFFSET;
	uintptr_t *image;

	uint32_t flag = 0;
	uint32_t *pattern = &stack_end;
	*pattern = (uint32_t)(0xABCDEF12);

	BaudRateType baudrate_type;
	uint32_t target_baudrate = 115200;

#if !defined(CONFIG_EMMC)
	uint32_t programmer_type;

	int j;
	uint32_t flash_type;
	uint32_t write_progress = 0;
	uint32_t erase_progress = 0;

	uint32_t check_flash_con = 0;
	uint32_t check_flash_enable = 0;
#else
	uint32_t ssbl_size = 0;
	uint32_t ssbl_checksum = 0;
	EmmcBurnConfig *emmc_burn_config = (EmmcBurnConfig *)EMMC_BURN_PARTTBL_ADDR;
#endif

#ifdef CONFIG_FPGA
	const uint32_t uart_ref_clk[] = { 12000000 };
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	const uint32_t uart_ref_clk[] = { 199200000 };
#else
	const uint32_t uart_ref_clk[] = { 126000000, 96000000, 58982400 };
#endif

	if (prog_init(g_uart) == 0) {
		flag = EFUSE_DONE;
		goto Exit_NVSPC;
	}

	//Get target baudrate from UART server
	LOG_REQ("GETBAUDRATE");
	uart_receive(&g_uart, 4, (uint8_t *)(&target_baudrate), 0);
	uart_transmit(&g_uart, 1, (uint8_t *)".");

	if (target_baudrate == 0) {
		printf("[ERROR] GET BAUDRATE = 0\n");
		flag = BAUDRATE_FAIL;
		goto Exit_NVSPC;
	}

	for (i = 0; i < 300; i++)
		delay_ns(1000000);

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO)
	baudrate_type = 0;
#else
	for (baudrate_type = BAUDRATE_TYPE_7875000; baudrate_type < BAUDRATE_MAX; baudrate_type++) {
		if ((uart_ref_clk[baudrate_type] / UART_DIV) % target_baudrate == 0)
			break;
	}
	if (baudrate_type == BAUDRATE_MAX) {
		printf("[ERROR] BAUDRATE %u IS NOT SUPPORTED\n", target_baudrate);
		flag = BAUDRATE_FAIL;
		goto Exit_NVSPC;
	}
#endif

	err = nvsp_mach_nvsp_init(baudrate_type);
	if (err < 0) {
		printf("[ERROR] DRAM INIT FAIL\n");
		flag = DDR_INIT_FAIL;
		goto Exit_NVSPC;
	}

	g_uart.baud_rate = target_baudrate;
	g_uart.ref_clk_rate = uart_ref_clk[baudrate_type];

	uart_init(&g_uart); //re-initialization

	printf("DDR = %s, data rate: %d MT/s\n", DDR_NAME, DDR_DATA_RATE);
	printf("DDR TYPE = %s, capacity: %d MB\n", DDR_TYPE, CONFIG_DRAM_CAPACITY);

	LOG_REQ("PARTTBL_SIZE");
	uart_receive(&g_uart, 4, (uint8_t *)(&part_table_size), 0);
	uart_transmit(&g_uart, 1, (uint8_t *)".");

	LOG_REQ("PARTTBL");
	for (i = 0; i < part_table_size; i += UART_CHUNK_SIZE) {
		if (part_table_size - i >= UART_CHUNK_SIZE) {
			uart_receive(&g_uart, UART_CHUNK_SIZE, (uint8_t *)((uintptr_t)PARTTBL_ADDR + i), 0);
		} else {
			uart_receive(&g_uart, part_table_size - i, (uint8_t *)(((uintptr_t)PARTTBL_ADDR) + i), 0);
		}

		uart_transmit(&g_uart, 1, (uint8_t *)".");
	}

	LOG_REQ("PARTTBL_CHECKSUM");
	uart_receive(&g_uart, 4, (uint8_t *)(&part_table_checksum), 0);
	uart_transmit(&g_uart, 1, (uint8_t *)".");

	cal_checksum = get_checksum((uint32_t *)boot_config, (part_table_size / sizeof(uint32_t)));
	if (cal_checksum != part_table_checksum) {
		printf("partition table checksum error. (0x%x != 0x%x)\n", part_table_checksum, cal_checksum);
		printf(UART_ERROR);
		flag = PARTTBL_CHECKSUM_FAIL;
		goto Exit_NVSPC;
	}

#if !defined(CONFIG_EMMC)
	//To check flash programmer type and init it.
	LOG_REQ("PROG_MODE");
	uart_receive(&g_uart, 4, (uint8_t *)(&programmer_type), 0);
	uart_transmit(&g_uart, 1, (uint8_t *)".");
	printf("programmer_type type=%d\n", programmer_type);
	/*
	 * programmer_type interpretation
	 *
	 * bit[3:0] decides transfer byte. 4b'0000 = 32 bytes per transfer; Non-zero = 65536 bytes per transfer.
	 * bit[4] enables write progress. 1b'0 = disable; 1b'1 = enable.
	 * bit[5] enables erase progress. 1b'0 = disable; 1b'1 = enable.
	 * bit[31:6] reserved.
	 */

	if ((programmer_type & ENABLE_WRITE_PROGRESS) != 0) {
		write_progress = 1; //enable write progress
	}

	if ((programmer_type & ENABLE_ERASE_PROGRESS) != 0) {
		erase_progress = 1; //enalbe erase progress
	}

	//To check flash type and init it.
	LOG_REQ("NVS_TYPE");
	uart_receive(&g_uart, 4, (uint8_t *)(&flash_type), 0);
	uart_transmit(&g_uart, 1, (uint8_t *)".");

	//To check if need to check flash content.
	LOG_REQ("CHECK_FLASH_CON");
	check_flash_enable = uart_receive(&g_uart, 4, (uint8_t *)(&check_flash_con), 2400000);
	uart_transmit(&g_uart, 1, (uint8_t *)".");

	if (check_flash_enable != 4) {
		printf("Unable to receive CHECK_FLASH_CON data\n");
	}

	flag = init_flash(flash_type, boot_config);
	if (flag != ESUCCESS) {
		flag = FLASH_INIT_FAIL;
		goto Exit_NVSPC;
	}

	get_quad_mode_detection(flash_type);
#else
	LOG_REQ("SSBL_SIZE");
	uart_receive(&g_uart, 4, (uint8_t *)(&ssbl_size), 0);
	uart_transmit(&g_uart, 1, (uint8_t *)".");

	LOG_REQ("SSBL");
	for (i = 0; i < ssbl_size; i += UART_CHUNK_SIZE) {
		if (ssbl_size - i >= UART_CHUNK_SIZE) {
			uart_receive(&g_uart, UART_CHUNK_SIZE, (uint8_t *)(((uint32_t)EMMC_BURN_UBOOT_ADDR) + i), 0);
		} else {
			uart_receive(&g_uart, ssbl_size - i, (uint8_t *)(((uint32_t)EMMC_BURN_UBOOT_ADDR) + i), 0);
		}

		uart_transmit(&g_uart, 1, (uint8_t *)".");
	}

	LOG_REQ("SSBL_CHECKSUM");
	uart_receive(&g_uart, 4, (uint8_t *)(&ssbl_checksum), 0);
	uart_transmit(&g_uart, 1, (uint8_t *)".");
	cal_checksum = get_checksum((uint32_t *)(EMMC_BURN_UBOOT_ADDR), (ssbl_size / sizeof(uint32_t)));
	if (cal_checksum != ssbl_checksum) {
		printf("[ERROR] SSBL checksum error\n");
		flag = SSBL_CHECKSUM_FAIL;
		goto Exit_NVSPC;
	}

	emmc_burn_config->part_num = boot_config->part_num;
#endif

	//Parsing Partition Table
	printf("======= Partition Table =======\nnvs_type = %d part_num = %d boot_idx = %d verify = %d\n",
	       boot_config->nvs_type, boot_config->part_num, boot_config->boot_idx, boot_config->verify);
	for (i = 0; i < boot_config->part_num; i++) {
		if (boot_config->pt_list[i].nvs_size == 0)
			continue;
		printf("[Partition %d: %s]\n\tbase = 0x%08x, size = 0x%08x\n", i, boot_config->pt_list[i].pt_label,
		       boot_config->pt_list[i].nvs_start, boot_config->pt_list[i].nvs_size);
#if defined(CONFIG_EMMC)
		memcpy(emmc_burn_config->pt_list[i].pt_name, boot_config->pt_list[i].pt_label, 16);
		emmc_burn_config->pt_list[i].pt_blk_start = boot_config->pt_list[i].nvs_start;
		emmc_burn_config->pt_list[i].pt_blk_size = boot_config->pt_list[i].nvs_size;
		emmc_burn_config->pt_list[i].img_blk_size = BYTES_TO_BLK(boot_config->pt_list[i].img_size);
#endif
	}
	printf("===================\n");

#if !defined(CONFIG_EMMC)
	// Erase all partition before write
	for (i = 0; i < boot_config->part_num; i++) {
		flag = nvspc_erase_partition(boot_config->pt_list[i].nvs_start, boot_config->pt_list[i].nvs_size,
		                             erase_progress, i);
		if (flag != -ESUCCESS) {
			printf("Partition %d erase fail.\n", i);
			flag = ERASE_PART_FAIL;
			goto Exit_NVSPC;
		}
	}
#endif
	//read image i=0->i=part_num from image table
	for (i = 0; i <= boot_config->part_num; i++) {
		if (i == boot_config->part_num) {
			flag = BURN_DONE;
			break;
		}

#if defined(CONFIG_EMMC)
		emmc_burn_config->pt_list[i].img_start = img_addr;
#endif

		image = (uintptr_t *)img_addr;

		/*  The partition without image will be erased here,
                 *  while the partition with image will be erased in write function.
                 *  This implementation is to match the requirement for nand which can't erase bad block.
                 */
		if (boot_config->pt_list[i].img_size == 0) { //no image bin
			is_burn_ok(flag, i);
			continue;
		}

		if (boot_config->pt_list[i].img_size > 0) { //this size is flag
			int retry = CHECK_NUM;
			while (retry > 0) {
				int img_size = boot_config->pt_list[i].img_size;
				int size;
				int offset = 0;
				int max_size = MAX_BUFFER;

				printf("REQ(IMG:%d)\n", i);
				while (img_size > 0) {
					if (img_size >= max_size)
						size = max_size;
					size = img_size;
					uart_receive(&g_uart, size, (uint8_t *)(((uintptr_t)image) + offset), 0);
					offset += size;
					img_size -= size;
				}
				cal_checksum = get_checksum((uint32_t *)image,
				                            (boot_config->pt_list[i].img_size / sizeof(uint32_t)));
				if (cal_checksum == boot_config->pt_list[i].checksum) {
					break;
				}
				retry--;
			}
			if (retry == 0) {
				printf("\nIMG:%d checksum error. (0x%08x != 0x%08x)\n", i, cal_checksum,
				       boot_config->pt_list[i].checksum);
				printf(UART_ERROR);
				printf("REQ(IMG_FAIL:%d)\n", i);
				break;
			}
#if !defined(CONFIG_EMMC)
			//write image table to flash
			flag = write_to_partition(boot_config->pt_list[i].nvs_start, boot_config->pt_list[i].nvs_size,
			                          img_addr, boot_config->pt_list[i].img_size, write_progress);

			//check flash content is enable
			if (check_flash_con == 1) {
				//check image checksum in DRAM again
				cal_checksum = get_checksum((uint32_t *)image,
				                            (boot_config->pt_list[i].img_size / sizeof(uint32_t)));
				if (cal_checksum != boot_config->pt_list[i].checksum) {
					printf("\nDRAM unstable. (0x%08x != 0x%08x)\n", cal_checksum,
					       boot_config->pt_list[i].checksum);
					printf(DRAM_ERROR);
					printf("REQ(IMG_FAIL:%d)\n", i);
					break;
				}

				//read image from flash to verify image
				read_from_partition(boot_config->pt_list[i].nvs_start, boot_config->pt_list[i].nvs_size,
				                    img_addr, boot_config->pt_list[i].img_size);
				cal_checksum = get_checksum((uint32_t *)image,
				                            (boot_config->pt_list[i].img_size / sizeof(uint32_t)));
				if (cal_checksum != boot_config->pt_list[i].checksum) {
					printf("\nFlash programming fail. (0x%08x != 0x%08x)\n", cal_checksum,
					       boot_config->pt_list[i].checksum);
					printf(FLASH_ERROR);
					printf("REQ(IMG_FAIL:%d)\n", i);
					break;
				}

				printf("Flash content check is finished.\n");
			}

			is_burn_ok(flag, i);

			//find repeat image to partition
			for (j = i + 1; j < boot_config->part_num; j++) {
				if (boot_config->pt_list[j].checksum == boot_config->pt_list[i].checksum) {
					printf("REQ(IMG_RE:%d)\n", j);
					//write image table to flash
					flag = write_to_partition(boot_config->pt_list[j].nvs_start,
					                          boot_config->pt_list[j].nvs_size, img_addr,
					                          boot_config->pt_list[j].img_size, write_progress);

					if (check_flash_con == 1) { //check flash content is enable
						//check image checksum in DRAM again
						cal_checksum = get_checksum(
						        (uint32_t *)image,
						        (boot_config->pt_list[j].img_size / sizeof(uint32_t)));
						if (cal_checksum != boot_config->pt_list[j].checksum) {
							printf("\nDRAM unstable. (0x%08x != 0x%08x)\n", cal_checksum,
							       boot_config->pt_list[j].checksum);
							printf(DRAM_ERROR);
							printf("REQ(IMG_FAIL:%d)\n", j);
							break;
						}

						//read image from flash to verify image
						read_from_partition(boot_config->pt_list[j].nvs_start,
						                    boot_config->pt_list[i].nvs_size, img_addr,
						                    boot_config->pt_list[j].img_size);
						cal_checksum = get_checksum(
						        (uint32_t *)image,
						        (boot_config->pt_list[j].img_size / sizeof(uint32_t)));
						if (cal_checksum != boot_config->pt_list[j].checksum) {
							printf("\nFlash programming fail. (0x%08x != 0x%08x)\n",
							       cal_checksum, boot_config->pt_list[j].checksum);
							printf(FLASH_ERROR);
							printf("REQ(IMG_FAIL:%d)\n", j);
							break;
						}

						printf("Flash content check is finished.\n");
					}

					is_burn_ok(flag, j);
					boot_config->pt_list[j].img_size = 0;
				}
			}
#endif
			img_addr += ALIGN_BLK(boot_config->pt_list[i].img_size);
		}
	}

#if defined(CONFIG_EMMC)
	pinmux_set_pinconf(PAD_SD_D2, PINCFG_PU, 1);
	pinmux_set_pinconf(PAD_SD_D3, PINCFG_PU, 1);
	pinmux_set_pinconf(PAD_SD_CMD, PINCFG_PU, 1);
	pinmux_set_pinconf(PAD_SD_D0, PINCFG_PU, 1);
	pinmux_set_pinconf(PAD_SD_D1, PINCFG_PU, 1);

	pinmux_set_pinconf(PAD_SD_D2, PINCFG_DS, 4);
	pinmux_set_pinconf(PAD_SD_D3, PINCFG_DS, 4);
	pinmux_set_pinconf(PAD_SD_CK, PINCFG_DS, 4);
	pinmux_set_pinconf(PAD_SD_CMD, PINCFG_DS, 4);
	pinmux_set_pinconf(PAD_SD_D0, PINCFG_DS, 4);
	pinmux_set_pinconf(PAD_SD_D1, PINCFG_DS, 4);
	image = (uint32_t *)(EMMC_BURN_UBOOT_ADDR);
	asm volatile("bx %[image]\n" : : [image] "r"(image) :);
#endif

Exit_NVSPC:
	exit_flash_program();

	if (*pattern != 0xABCDEF12) {
		printf("\nNVSPC stack overflow\n");
	}

	if (flag == BURN_DONE) {
		printf("\nCongratulations!!! NVPS Program burn success!\n\n");
	}

	printf("REQ(DONE:%d)\n", flag);
	while (1) {
	}
	return 0;
}
