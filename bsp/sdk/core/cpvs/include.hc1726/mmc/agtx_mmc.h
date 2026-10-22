/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef AGTX_MMC_H_
#define AGTX_MMC_H_

#include <stdint.h>
#include "dwmmc_uboot.h"

#define CMDARG_PRE_IDLE 0xF0F0F0F0 // with CMD0
#define CMDARG_OP_COND 0x40FF8080
#define MMC_BLK_SIZE 0x200

#define GENERAL_SET (MMC_CMD_RESP_EXP | MMC_CMD_CHECK_CRC | MMC_CMD_PRV_DAT_WAIT | MMC_CMD_USE_HOLD_REG | MMC_CMD_START)

#define CMD_GO_IDLE (MMC_CMD_SEND_INIT | MMC_CMD_USE_HOLD_REG | MMC_CMD_START)
#define CMD_BOOT_DEINIT (MMC_CMD_DISABLE_BOOT | MMC_CMD_START)
#define CMD_BOOT_INIT (MMC_CMD_DATA_EXP | MMC_CMD_EN_BOOT | MMC_CMD_BOOT_ACK_EXP | MMC_CMD_START)

#define CMD_SEND_OP_COND (MMC_CMD_SEND_OP_COND | MMC_CMD_RESP_EXP | MMC_CMD_USE_HOLD_REG | MMC_CMD_START)
#define CMD_SEND_CID (MMC_CMD_ALL_SEND_CID | GENERAL_SET | MMC_CMD_RESP_LENGTH)
#define CMD_SET_RELA_ADDR (MMC_CMD_SET_RELATIVE_ADDR | GENERAL_SET)
#define CMD_SELECT_CARD (MMC_CMD_SELECT_CARD | GENERAL_SET)

#define CMD_UPDATE_CLOCK (MMC_CMD_PRV_DAT_WAIT | MMC_CMD_UPD_CLK | MMC_CMD_START)
#define CMD_SWITCH (MMC_CMD_SWITCH | GENERAL_SET)
#define CMD_SWITCH_ARG(access, index, value, cmd_set) (((access) << 24) | ((index) << 16) | ((value) << 8) | (cmd_set))
#define PART_CONF_VAL(boot_ack, boot_partition_enable, boot_partition_access) \
	((boot_ack << 6) | (boot_partition_enable << 3) | (boot_partition_access))

#define CMD_GET_EXT_CSD (MMC_CMD_SEND_EXT_CSD | MMC_CMD_DATA_EXP | GENERAL_SET)
#define CMD_SEND_ST (MMC_CMD_SEND_STATUS | GENERAL_SET)

#define CMD_SET_BLKLEN (MMC_CMD_SET_BLOCKLEN | GENERAL_SET)
#define CMD_READ_MULTI_BLK (MMC_CMD_READ_MULTIPLE_BLOCK | MMC_CMD_DATA_EXP | GENERAL_SET)
#define CMD_STOP                                                                                                 \
	(MMC_CMD_STOP_TRANSMISSION | MMC_CMD_ABORT_STOP | MMC_CMD_RESP_EXP | MMC_CMD_CHECK_CRC | MMC_CMD_START | \
	 MMC_CMD_USE_HOLD_REG)

#define RINTS_DTO_CD (MMC_INTMSK_CDONE | MMC_INTMSK_DTO)

#define MMC_TGT_CLK_400K 400000
#define MMC_TGT_CLK_3M 3000000
#define MMC_TGT_CLK_25M 25000000
#define MMC_TGT_CLK_50M 50000000
#define MMC_REF_CLK_49_8M 49800000
#define MMC_REF_CLK_12M 12000000
#define MMC_REF_CLK_12_5M 12500000
#define MMC_FIFO_DEPTH 256
#define HW_MMC_RCA (1)
#define BOOT_BUS_OFFSET 177
#define HW_MMC_READ_TIMEOUT_CYCLE 200000

/* DMA descriptor should locates in dram, starts from 0x0 to set dma descriptor */
#define MMC_DMA_DESC_BASE 0x0

typedef enum mmc_boot_ack {
	MMC_BOOT_ACK_DISABLE = 0,
	MMC_BOOT_ACK_ENABLE,
} MmcBootAck;

typedef enum mmc_card_state {
	MMC_CARD_STATE_IDLE = 0,
	MMC_CARD_STATE_READY,
	MMC_CARD_STATE_IDENT,
	MMC_CARD_STATE_STBY,
	MMC_CARD_STATE_TRAN,
	MMC_CARD_STATE_DATA,
	MMC_CARD_STATE_RCV,
	MMC_CARD_STATE_PRG,
	MMC_CARD_STATE_DIS,
	MMC_CARD_STATE_BTST,
	MMC_CARD_STATE_SLP,
} MmcCardState;

typedef enum mmc_boot_partition_enable {
	MMC_BOOT_PARTITION_DISABLE = 0,
	MMC_BOOT_PARTITION_1_ENABLE,
	MMC_BOOT_PARTITION_2_ENABLE,
	MMC_BOOT_PARTITION_USER_ENABLE = 7,
} MmcBootPartitionEnable;

typedef enum mmc_boot_partition_access {
	MMC_BOOT_PARTITION_ACCESS_DISABLE = 0,
	MMC_BOOT_PARTITION_ACCESS_1,
	MMC_BOOT_PARTITION_ACCESS_2,
	MMC_BOOT_PARTITION_ACCESS_RPMB,
	MMC_BOOT_PARTITION_ACCESS_GP_1,
	MMC_BOOT_PARTITION_ACCESS_GP_2,
	MMC_BOOT_PARTITION_ACCESS_GP_3,
	MMC_BOOT_PARTITION_ACCESS_GP_4,
} MmcBootPartitionAccess;

typedef enum mmc_boot_bus_width {
	MMC_BOOT_BUS_WIDTH_1X = 0,
	MMC_BOOT_BUS_WIDTH_4X = 1,
	MMC_BOOT_BUS_WIDTH_8X = 2,
} MmcBootBusWidth;

typedef enum mmc_reset_boot_bus_width {
	MMC_RESET_BOOT_BUS_WIDTH = 0,
	MMC_RETAIN_BOOT_BUS_WIDTH,
} MmcResetBootBusWidth;

typedef enum mmc_boot_mode {
	MMC_BOOT_MODE_SINGLE_BACKWARD = 0,
	MMC_BOOT_MODE_SINGLE_HS = 1,
	MMC_BOOT_MODE_DUAL = 2,
} MmcBootMode;

typedef union boot_bus_condition {
	uint8_t boot_bus_condition; // word name
	struct {
		uint32_t boot_bus_width : 2;
		uint32_t reset_boot_bus_width : 1;
		uint32_t boot_mode : 2;
		uint32_t : 3; // padding bits
	};
} BootBusCond;

typedef enum mmc_partition {
	MMC_PARTITION_USER = 0,
	MMC_PARTITION_BOOT_1 = 1,
	MMC_PARTITION_BOOT_2 = 2,
} MmcPartition;

typedef struct sdc_dev {
	uintptr_t sdc_base_addr;
	uintptr_t sdc_cfg_base_addr;
	uint32_t ref_clk_rate;
	uint32_t sdc_emmc_clk_rate;
} SdcDev;

typedef enum load_image_state {
	LOAD_UNTIL_OFFSET = 0,
	LOAD_IMAGE = 1,
	LOAD_UNTIL_DONE = 2,
} LoadImgState;

int hw_mmc_go_idle_state(uint32_t base);
void hw_mmc_switch_bus_width(uint32_t base, MmcBootBusWidth width);
int hw_mmc_read_boot_data(struct sdc_dev *dev, uint32_t *dest, uint32_t img_offset, uint32_t img_size);
void hw_mmc_boot_operation_init(struct sdc_dev *dev);
int hw_mmc_boot_operation(struct sdc_dev *dev);
int hw_mmc_set_boot_bus_width(uint32_t base, enum mmc_reset_boot_bus_width reset_boot_bus_width,
                              enum mmc_boot_bus_width boot_bus_width, enum mmc_boot_mode boot_mode);
int hw_mmc_go_pre_idle_state(uint32_t base);
void mmc_set_boot_bus(struct sdc_dev *dev);
int mmc_boot_init(struct sdc_dev *dev);
int mmc_boot_dma_read(uint32_t base, uint32_t blk_base, uint32_t mem_base, uint32_t size, enum mmc_partition part);

#endif
