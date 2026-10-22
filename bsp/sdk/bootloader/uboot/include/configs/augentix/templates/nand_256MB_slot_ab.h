/*
 * Configuation settings for Augentix reference products with 256MB NAND flash.
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
#define CONFIG_LOGLEVEL		6
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
#define KERNEL_ADDR       CONFIG_UIMAGE_LOADADDR

/* MTD partition related params */
#define MTDIDS_DEFAULT   MTDIDS_DEFAULT_NAND
#define MTDPARTS_DEFAULT MTDPARTS_NAND_256MB_SLOT_AB
#define LINUX_0_FLASH_START 0x00100000 /* linux_0 starting addr*/
#define LINUX_1_FLASH_START 0x07b00000 /* linux_1 starting addr*/
#define ROOTFS_0_MTDID 4
#define ROOTFS_1_MTDID 6
#define ROOTFS_UBI_MTDID 8 /* Only for UBIFS */
#define USRDATAFS_UBI_MTDID 7
/*
 * Environment settings
 * Note that the settings below must also apply to /etc/fw_env.config
 */
#define CONFIG_ENV_SIZE          0x00020000
#define CONFIG_ENV_OFFSET        0x00080000
#define CONFIG_ENV_OFFSET_REDUND 0x000C0000

/*
 * DRAM settings
 */
#define CONFIG_NR_DRAM_BANKS        1
#define CONFIG_SYS_SDRAM_BASE       0x00000000
#define CONFIG_SYS_SDRAM_SIZE       (CONFIG_DRAM_CAPACITY << 20)

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

/* bootenv in NAND */
#define CONFIG_SYS_MAX_NAND_DEVICE 1
#define CONFIG_ENV_IS_IN_NAND
#define BOOT_NAND_DEVID 0

/* NOR flash - no real NOR flash on this board */
#define CONFIG_SYS_NO_FLASH 1
#define FLASH_CAPACITY_MB 256

#define CONFIG_ETHADDR "02:00:00:00:00:00"
#define CONFIG_WIFIADDR "02:00:00:00:00:00"
#define CONFIG_AUGENTIX_UARTBOOT_RANDOM_ETHADDR
#define CONFIG_UDP_CHECKSUM

/*
 * Boot commands
 */
#define SYSUPD_TYPE "dual"
#define NANDROOT_UBIFS_CMD \
"setenv nandroot "\
    "ubi.mtd=${rootfs_mtdid} root=ubi0:rootfs " \
    "rootfstype=ubifs ro rootwait; "
#define NANDROOT_SQUASHFS_CMD \
"setenv nandroot "\
    "ubi.mtd=${rootfs_mtdid} "TO_STR(ROOT_DEVICE)" "\
    "rootfstype=squashfs ro rootwait;"

#define CONFIG_BOOTCOMMAND  "run nandboot"
#define CONFIG_EXTRA_ENV_SETTINGS \
    "mtdids=" MTDIDS_DEFAULT "\0" \
    "mtdparts=" MTDPARTS_DEFAULT "\0" \
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
    "kernel_memaddr="TO_STR(KERNEL_ADDR)"\0"\
    "kernel_0_flashaddr="TO_STR(LINUX_0_FLASH_START)"\0"\
    "kernel_1_flashaddr="TO_STR(LINUX_1_FLASH_START)"\0"\
    "rootfs_0_mtdid="TO_STR(ROOTFS_0_MTDID)"\0"\
    "rootfs_1_mtdid="TO_STR(ROOTFS_1_MTDID)"\0"\
    "rootfs_mtdid=\0"\
    "rootfs_ubi_mtdid="TO_STR(ROOTFS_UBI_MTDID)"\0"\
    "rootfs_ubifs="TO_STR(CONFIG_ROOTFS_UBIFS)"\0"\
    "usrdatafs_mtdid="TO_STR(USRDATAFS_UBI_MTDID)"\0"\
    "loglevel="TO_STR(CONFIG_LOGLEVEL)"\0"\
    "wdt_log=0\0"\
    "nandroot=\0"\
    "envsaved=0\0"\
    "bootargs=\0"\
    FASTBOOT_PAR \
    "set_boot_slot_a="\
        "echo \"Boot from Slot A\"; "\
        "setenv kernel_flashaddr ${kernel_0_flashaddr}; "\
        "setenv rootfs_mtdid ${rootfs_0_mtdid};\0"\
    "set_boot_slot_b="\
        "echo \"Boot from Slot B\"; "\
        "setenv kernel_flashaddr ${kernel_1_flashaddr}; "\
        "setenv rootfs_mtdid ${rootfs_1_mtdid};\0"\
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
    "set_nandargs="\
        "if test ${slot_b_active} = 1; then "\
            "run set_boot_slot_b; "\
        "else "\
            "run set_boot_slot_a; "\
        "fi; "\
        "if test ${rootfs_ubifs} = 1; then "\
            NANDROOT_UBIFS_CMD \
        "else "\
            NANDROOT_SQUASHFS_CMD \
        "fi;\0"\
    "update_bootenv="\
        "if test ${bootcounter} > 2; then "\
            "echo \"Switch boot mode...\" ;"\
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
    "nandboot="\
        "if test ${envsaved} = 0; then setenv envsaved 1; saveenv; fi;"\
        "run update_bootenv; "\
        "run set_nandargs; "\
        "nboot.e ${kernel_memaddr} "TO_STR(BOOT_NAND_DEVID)" ${kernel_flashaddr}; "\
	SEC_BOOT_SOURCE_ARG \
        "setenv bootargs "\
            "${nandroot} ${mtdparts} console=ttyAS0,"TO_STR(CONFIG_BAUDRATE)" clk_ignore_unused "\
            "ethaddr=${ethaddr} no_console_suspend=1 lpj="TO_STR(LOOPS_PER_JIFFY)" ubi.mtd=${usrdatafs_mtdid} " \
	    FASTBOOT_ARG \
	    SEC_BOOT_SET_ARG \
	    "loglevel=${loglevel} wdt_log=${wdt_log}; " \
	"bootm ${kernel_memaddr};" BOOT_FAIL_HANDLE "\0"\
    "hardware_id=Augentix reference product\0"

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
