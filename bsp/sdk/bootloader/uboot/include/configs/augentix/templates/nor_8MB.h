/*
 * Configuation settings for Augentix reference products with 8MB NOR flash.
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
#define KERNEL_ADDR     0x00080000
#define KERNEL_SIZE     0x00280000

/* MTD partition related params */
#define MTDIDS_DEFAULT   MTDIDS_DEFAULT_NOR
#define MTDPARTS_DEFAULT MTDPARTS_NOR_8MB
#define LINUX_0_FLASH_START 0x00050000 /* linux_0 starting addr*/
#define ROOTFS_0_MTDID 3
/*
 * Environment settings
 * Note that the settings below must also apply to /etc/fw_env.config
 */
#define CONFIG_ENV_SIZE    0x00010000
#define CONFIG_ENV_OFFSET  0x00040000 /* bootenv_0 starting addr */

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
#define FLASH_CAPACITY_MB 8

/* SPI */
#define CONFIG_SF_DEFAULT_CS	0

/* bootenv in NOR 8MB */
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_SYS_MAX_FLASH_BANKS    1       /* max number of memory banks		*/
#define CONFIG_SYS_MAX_FLASH_SECT     128    /* max number of sectors on one chip	*/
#define CONFIG_ENV_SECT_SIZE  0x00001000     /* size of one complete sector	*/
#define CONFIG_SYS_FLASH_BASE 0x0            /* start of FLASH	*/
#define BOOT_NOR_DEVID 0

#define CONFIG_ETHADDR "02:00:00:00:00:00"
#define CONFIG_WIFIADDR "02:00:00:00:00:00"
#define CONFIG_AUGENTIX_UARTBOOT_RANDOM_ETHADDR
#define CONFIG_UDP_CHECKSUM

/*
 * Boot commands
 */

#define CONFIG_BOOTCOMMAND  "run default_boot"
#define CONFIG_EXTRA_ENV_SETTINGS \
    "mtdids=" MTDIDS_DEFAULT "\0" \
    "mtdparts=" MTDPARTS_DEFAULT "\0" \
    "initrd_high=0xffffffff\0"\
    "factory_reset=0\0"\
    "ethaddr="CONFIG_ETHADDR"\0"\
    "wifiaddr="CONFIG_WIFIADDR"\0"\
    "kernel_memaddr="TO_STR(KERNEL_ADDR)"\0"\
    "kernel_size="TO_STR(KERNEL_SIZE)"\0"\
    "kernel_flashaddr="TO_STR(LINUX_0_FLASH_START)"\0"\
    "rootfs_mtdid="TO_STR(ROOTFS_0_MTDID)"\0"\
    "loglevel="TO_STR(CONFIG_LOGLEVEL)"\0"\
    "wdt_log=0\0"\
    "norroot=\0"\
    "bootargs=\0"\
    "envsaved=0\0"\
    "bootretry=3\0"\
    FASTBOOT_PAR \
    "default_boot="\
        "setenv norroot "\
            ""TO_STR(ROOT_DEVICE)" rootfstype=squashfs ro rootwait;"\
	"if test ${envsaved} = 0; then setenv envsaved 1; saveenv; fi;"\
        "sf probe; "\
	"run norboot\0"\
    "norboot="\
        "sf read ${kernel_memaddr} ${kernel_flashaddr} ${kernel_size}; "\
	SEC_BOOT_SOURCE_ARG \
        "setenv bootargs "\
            "${mtdparts} ${norroot} console=ttyAS0,"TO_STR(CONFIG_BAUDRATE)" clk_ignore_unused ethaddr=${ethaddr} no_console_suspend=1 lpj="TO_STR(LOOPS_PER_JIFFY)" " \
	    FASTBOOT_ARG \
	    SEC_BOOT_SET_ARG \
	    "loglevel=${loglevel} wdt_log=${wdt_log};" \
        "bootm ${kernel_memaddr}; "\
	"setexpr bootretry ${bootretry} - 1;"\
	"if test ${bootretry} != 0; then run norboot; fi;"\
	"bootm ${kernel_memaddr};" BOOT_FAIL_HANDLE "\0"\
    "hardware_id=TB008_NOR\0"

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
