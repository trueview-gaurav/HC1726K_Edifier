/*
 * Configuation settings for Augentix reference products with 32MB NOR flash.
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include "augentix/augentix_common.h"

/* clang-format off */

/*
 * Image locations
 *
 * Warning: changing CONFIG_SYS_TEXT_BASE requires
 * adapting the initial boot program.
 * Since the linker has to swallow that define, we must use a pure
 * hex number here!
 */
#define CONFIG_SYS_TEXT_BASE 0x03000400

/*
 * peripheral settings
 */
#define CONFIG_BAUDRATE 115200

/*
 * system settings
 */
#define CONFIG_BOOTDELAY    0
#define CONFIG_SYS_CBSIZE       256
#define CONFIG_SYS_MAXARGS      64
#define CONFIG_SYS_LONGHELP     1
#define CONFIG_CMDLINE_EDITING  1
#define CONFIG_AUTO_COMPLETE
#define CONFIG_LOGLEVEL                6
#define CONFIG_BOARD_LATE_INIT  1

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN   0x400000

/*
 * Image layout in main memory
 */
#define UBOOT_START_ADDR  0x00008000
#define UBOOT_END_ADDR    0x00080000

/*
 * Environment settings
 * Note that the settings below must also apply to /etc/fw_env.config
 */
#define CONFIG_ENV_SIZE    0x00010000
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV  0 /* MMC device 0 */
#define CONFIG_SYS_NO_FLASH

/*
 * DRAM settings
 */
#define CONFIG_NR_DRAM_BANKS        1
#define CONFIG_SYS_SDRAM_BASE       0x00000000
#define CONFIG_SYS_SDRAM_SIZE       (CONFIG_DRAM_CAPACITY << 20) /* Maximum size of supported DRAM */

#define KERNEL_ADDR     CONFIG_UIMAGE_LOADADDR
#define CONFIG_SYS_LOAD_ADDR        KERNEL_ADDR /* load address */
#define CONFIG_SYS_MEMTEST_START    CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END      CONFIG_SYS_SDRAM_BASE \
                    + CONFIG_SYS_SDRAM_SIZE

/*
 * Initial stack pointer END address before relocation
 */
#define CONFIG_SYS_INIT_SP_ADDR \
    UBOOT_END_ADDR - GENERATED_GBL_DATA_SIZE

/*
 * Boot commands
 */

#define CONFIG_BOOTCOMMAND  "run default_boot"

#define CONFIG_EXTRA_ENV_SETTINGS \
    "emmc_partition_check="\
    "if test -z \"$partitions\"; then " \
        "echo partitions is empty; " \
        "else " \
            "echo partitions exist; " \
            "if gpt verify mmc 0 $partitions; then " \
                "echo GPT OK; mmc part; " \
            "else " \
                "echo GPT fail, fixing...; " \
                "mmc erase 0 22; gpt write mmc 0 $partitions; mmc rescan; run emmc_partition_check;" \
            "fi;" \
    "fi;\0" \
    "default_boot=" \
	"mmc info || req_fail; " \
	"parse_tbl || req_fail; printenv; mmc dev 0 0 || req_fail; " \
	"parse_mmc_part || run emmc_partition_check;" \
        "emmc_part_burn || req_fail; " \
        "req_done 100\0"

/*
 * GPT
 */
#define CONFIG_CMD_GPT
#define CONFIG_EFI_PARTITION
#define CONFIG_PARTITION_UUIDS
#define CONFIG_RANDOM_UUID

/*
 * define Augentix QSPI wire
 *
 * SINGLE_WIRE 1
 * DUAL_WIRE 2
 * QUAD_WIRE 4
 */
#define CONFIG_AGTX_QSPI_WIRES 2
/*
 * define Augentix QSPI TX FIFO depth
 */
#define CONFIG_AGTX_QSPI_TX_FIFO 15
/*
 * define Augentix QSPI frequency
 * QSPI_IF_CLK_46875KHZ = 46875000 (46.875 MHz)
 * QSPI_IF_CLK_93750KHZ = 93750000 (93.75 MHz)
 */
#define CONFIG_AGTX_QSPI_FREQ 80000000
/*
 * define Augentix MMC bit mode
 *
 * 1-bit mode 1
 * 4-bit mode 4
 */

#define CONFIG_AGTX_MMC_BMODE 4

/* clang-format on */
#endif
