#ifndef NVSPC_COMMON_DEFINE_H_
#define NVSPC_COMMON_DEFINE_H_

/* functions that is only called once in fsbl_s1 */
#define __common __attribute__((section(".common.text")))
#define __common_data __attribute__((section(".common.data")))

#include <stdint.h>

//#define DEBUG
//#define DISPLAY_CLKINFO
#define VERBOSE

/* feature */
#define VERIFY_EFUSE 0

typedef enum flash_type {
	WRITE_TO_NAND,
	WRITE_TO_NOR,
	WRITE_TO_EMMC,
} FlashType;

typedef enum part_type {
	BOOT_PARTITION,
	USER_PARTITION,
} PartitionType;

#define UART_CHUNK_SIZE 32

#define EMMC_BURN_PARTTBL_ADDR 0x3000000
#define EMMC_BURN_UBOOT_ADDR 0x3000400
#define PARTTBL_ADDR 0x8000
#define IMG_OFFSET 0x80000

#define MMC_BLK_SIZE 0x200
#define MMC_BLK_SHIFT 9
#define ALIGN_UP(x, a) (((x) + ((a)-1)) & ~((a)-1))
#define ALIGN_BLK(size) (ALIGN_UP(size, MMC_BLK_SIZE))
#define BYTES_TO_BLK(size) (ALIGN_UP(size, MMC_BLK_SIZE) >> MMC_BLK_SHIFT)

/*********** boot record ********************/
#define SHA224_LEN 28 // (224bit / 8bit) for each byte
#define MODULUS_LEN 256 // 2048-bit modulus
#define SSL_SIGN_LEN 256 // length of signature
typedef struct __attribute__((packed)) boot_record {
	uint8_t br_magic[6];
	uint16_t br_version;
	uint32_t page_offset; //Page offset of FSBL for NAND flash.
	uint32_t address_offset; //Address offset of FSBL for NOR flash.
	uint32_t size;
	uint32_t fsbl_checksum;
	uint8_t fsbl_sign[SSL_SIGN_LEN]; // RSA signature
	uint8_t pubkey1_mod[MODULUS_LEN]; //require hard-coded pubexp 65537
	uint8_t pubkey2_mod[MODULUS_LEN]; //require hard-coded pubexp 65537
	uint8_t pubkey2_mod_sign[SSL_SIGN_LEN]; // RSA signature
	uint32_t br_checksum;
} BootRecord;

typedef struct __attribute__((packed)) partition_table {
	char pt_label[16];
	uint32_t nvs_start;
	uint32_t nvs_size;

	char img_label[12];
	uint32_t memory_address;
	uint32_t img_size;
	uint32_t checksum;
} PartTable;

typedef struct __attribute__((packed)) boot_config {
	uint32_t nvs_type; //0: nand, 1: nor, 2: emmc
	uint32_t part_num; //Number of defined partitions
	uint32_t boot_idx; //Index of the partition that contains image to be executed by FSBL
	uint32_t verify; //Whether to verify images during booting

	PartTable pt_list[20];
} BootConfig;

typedef struct __attribute__((packed)) emmc_burn_partition_table {
	char pt_name[16];
	uint32_t pt_blk_start;
	uint32_t pt_blk_size;
	uint32_t img_start;
	uint32_t img_blk_size;
} EmmcBurnPartTable;

typedef struct __attribute__((packed)) emmc_burn_config {
	uint32_t part_num; //Number of defined partitions
	EmmcBurnPartTable pt_list[20];
} EmmcBurnConfig;

#endif // NVSPC_COMMON_DEFINE_H_
