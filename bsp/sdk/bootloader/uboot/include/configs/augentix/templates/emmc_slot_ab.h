/*
* Configuation settings for Augentix reference products with emmc chip.
*
* SPDX-License-Identifier: GPL-2.0+
*/

#ifndef __CONFIG_H
#define __CONFIG_H

#include "augentix/augentix_common.h"
#include "augentix/fastboot_common.h"

/* clang-format off */

/*
* Image locations
*
* Warning: changing CONFIG_SYS_TEXT_BASE requires
* adapting the initial boot program.
* Since the linker has to swallow that define, we must use a pure
* hex number here!
*/
#define CONFIG_SYS_TEXT_BASE 0x00008000

/*
* SPL
*/
#define CONFIG_SPL_TEXT_BASE            0xFFE00800
#define CONFIG_SPL_MAX_SIZE             (32 * 1024)
#define CONFIG_SPL_STACK                0xFFE08000
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_BOARD_INIT

/*
* peripheral settings
*/
#ifdef CONFIG_FASTBOOT
#define CONFIG_BAUDRATE 460800
#else
#define CONFIG_BAUDRATE 115200
#endif

/*
* system settings
*/
#ifdef CONFIG_SECURE_BOOT
#define CONFIG_BOOTDELAY    -2
#else
#define CONFIG_BOOTDELAY    0
#endif
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
#define KERNEL_ADDR     CONFIG_UIMAGE_LOADADDR
#define KERNEL_SIZE     0x00600000

/*
 * eMMC environment settings
 */
#define CONFIG_ENV_IS_IN_MMC    1
#define CONFIG_SYS_MMC_ENV_DEV  0 /* MMC device 0 */
#define CONFIG_ENV_SIZE         0x10000  /* 64K */
#define CONFIG_ENV_OFFSET       0x80000 /* mmcblk0p1 starting addr = LBA 0x400 * 0x200 */
#ifdef CONFIG_SYS_MMC_ENV_PART
#undef CONFIG_SYS_MMC_ENV_PART
#endif

/*
* DRAM settings
*/
#define CONFIG_NR_DRAM_BANKS        1
#define CONFIG_SYS_SDRAM_BASE       0x00000000
#define CONFIG_SYS_SDRAM_SIZE       (CONFIG_DRAM_CAPACITY << 20) /* Maximum size of supported DRAM */

#define CONFIG_SYS_LOAD_ADDR        KERNEL_ADDR /* load address */
#define CONFIG_SYS_MEMTEST_START    CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END      CONFIG_SYS_SDRAM_BASE \
                    + CONFIG_SYS_SDRAM_SIZE

/*
* Initial stack pointer END address before relocation
*/
#define CONFIG_SYS_INIT_SP_ADDR \
    UBOOT_END_ADDR - GENERATED_GBL_DATA_SIZE

#define CONFIG_SYS_MAX_FLASH_BANKS 1
#define CONFIG_ENV_OVERWRITE

/* NOR flash - no real NOR flash on this board */
#define CONFIG_SYS_NO_FLASH 1
#define FLASH_CAPACITY_MB 32

/* SPI */
#define CONFIG_SF_DEFAULT_CS	0


#define CONFIG_ETHADDR "02:00:00:00:00:00"
#define CONFIG_WIFIADDR "02:00:00:00:00:00"
#define CONFIG_AUGENTIX_UARTBOOT_RANDOM_ETHADDR
#define CONFIG_UDP_CHECKSUM

/*
 * eMMC partition layout
 */
#define EMMC_KERNEL_ADDR        "0x01000000"
#define EMMC_KERNEL_LBA_A       "0xC00"    /* Partition 3 Start LBA */
#define EMMC_KERNEL_LBA_B       "0x5C00"    /* Partition 4 Start LBA */
#define EMMC_KERNEL_BLK_CNT     "0x5000"    /* KERNEL_SIZE / 512 */
#define EMMC_ROOTFS_A           "/dev/mmcblk0p5"
#define EMMC_ROOTFS_B           "/dev/mmcblk0p6"

/*
* Boot commands
*/
#define SYSUPD_TYPE "dual"

#define CONFIG_BOOTCOMMAND  "run default_boot"
#define CONFIG_EXTRA_ENV_SETTINGS \
    "initrd_high=0xffffffff\0"\
    "bootcounter=0\0"\
    "sysupd_type="SYSUPD_TYPE"\0"\
    "factory_reset=0\0"\
    "slot_a_active=1\0"\
    "slot_a_bootable=1\0"\
    "slot_a_successful=0\0"\
    "slot_b_active=0\0"\
    "slot_b_bootable=1\0"\
    "slot_b_successful=0\0"\
    "ethaddr="CONFIG_ETHADDR"\0"\
    "wifiaddr="CONFIG_WIFIADDR"\0"\
    "kernel_memaddr="EMMC_KERNEL_ADDR"\0"\
    "kernel_size="TO_STR(KERNEL_SIZE)"\0"\
    "kernel_lba_a="EMMC_KERNEL_LBA_A"\0"\
    "kernel_lba_b="EMMC_KERNEL_LBA_B"\0"\
    "kernel_blk_cnt="EMMC_KERNEL_BLK_CNT"\0"\
    "rootfs_a="EMMC_ROOTFS_A"\0"\
    "rootfs_b="EMMC_ROOTFS_B"\0"\
    "loglevel="TO_STR(CONFIG_LOGLEVEL)"\0"\
    "wdt_log=0\0"\
    "bootargs=\0"\
    "ext4_resized=0\0"\
    "envsaved=0\0"\
    "bootretry=3\0"\
    "prod_config=2\0"\
    FASTBOOT_PAR \
    "set_boot_slot_a="\
        "setenv kernel_lba ${kernel_lba_a}; "\
        "setenv rootfs ${rootfs_a};\0"\
    "set_boot_slot_b="\
        "setenv kernel_lba ${kernel_lba_b}; "\
        "setenv rootfs ${rootfs_b};\0"\
    "set_fallback="\
        "if test ${slot_b_active} = 1; then "\
            "if test ${slot_a_bootable} = 1; then "\
                "setenv slot_a_active 1; "\
                "setenv slot_b_active 0; "\
            "fi; "\
        "else "\
            "if test ${slot_b_bootable} = 1; then "\
                "setenv slot_b_active 1; "\
                "setenv slot_a_active 0; "\
            "fi;  "\
        "fi; "\
        "setenv bootcounter 0;\0"\
    "set_slotargs="\
        "if test ${slot_b_active} = 1; then "\
            "run set_boot_slot_b; "\
        "else "\
            "run set_boot_slot_a; "\
        "fi;\0"\
    "update_bootenv="\
        "if test ${bootcounter} > 2; then "\
            "echo \"bootcounter > 2: Switching boot slot...\" ;"\
            "run set_fallback; "\
        "fi; "\
            "if test ${slot_b_active} = 1; then "\
                "if test ${slot_b_successful} != 1; then "\
                    "setexpr bootcounter ${bootcounter} + 1; "\
                    "saveenv;"\
                "fi; "\
            "else "\
                "if test ${slot_a_successful} != 1; then "\
                    "setexpr bootcounter ${bootcounter} + 1; "\
                    "saveenv;"\
                "fi; "\
        "fi;\0"\
    "default_boot="\
        "if test ${envsaved} = 0; then "\
            "setenv envsaved 1; "\
            "saveenv; "\
        "fi;"\
        "run update_bootenv; "\
        "run set_slotargs; "\
        "run emmc_boot\0"\
    "emmc_boot="\
        "mmc dev 0; mmc read ${kernel_memaddr} ${kernel_lba} ${kernel_blk_cnt}; "\
        SEC_BOOT_SOURCE_ARG \
        "setenv bootargs "\
            "console=ttyAS0,"TO_STR(CONFIG_BAUDRATE)" " \
            "root=${rootfs} rootwait rw prod_config=${prod_config} " \
            "clk_ignore_unused ethaddr=${ethaddr} no_console_suspend=1 lpj="TO_STR(LOOPS_PER_JIFFY)" " \
        FASTBOOT_ARG \
        SEC_BOOT_SET_ARG \
        "loglevel=${loglevel} wdt_log=${wdt_log};" \
        "bootm ${kernel_memaddr}; "\
        "setexpr bootretry ${bootretry} - 1;"\
        "if test ${bootretry} != 0; then run emmc_boot; fi;"\
        "echo FATAL: eMMC boot failed. Resetting...; reset;" BOOT_FAIL_HANDLE "\0"\
    "hardware_id=TB013_EMMC\0"

/*
* define Augentix QSPI wire
*
* SINGLE_WIRE 1
* DUAL_WIRE 2
* QUAD_WIRE 4
*/
#define CONFIG_AGTX_QSPI_WIRES 4
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
