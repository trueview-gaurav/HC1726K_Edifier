/*
 * Configuation settings for augentix products.
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __AUGENTIX_COMMON_CONFIG_H
#define __AUGENTIX_COMMON_CONFIG_H

/* Refers to SDK top-level config */
#include "../../../../../../sdk/top/include/common/config.h"
#include "augentix_address_map.h"

/*
 * Two-pass stringify precompilation procedure is required
 */
#define STR(str) #str
#define TO_STR(str) STR(str)

#ifndef CONFIG_ROOTFS_UBIFS
#define CONFIG_ROOTFS_UBIFS 0
#endif

/* clang-format off */
/* memory system */
#define CONFIG_SYS_CACHELINE_SIZE 64

/* commands to include */
#define CONFIG_CMD_CACHE

/* MTD support */
#define CONFIG_CMD_MTDPARTS
#define CONFIG_CMD_MTD_DEVICE
#define CONFIG_CMD_MTD_PARTITIONS
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS

/*
 * SoC must be defined first, before hardware.h is included.
 * In this case SoC is defined in boards.cfg.
 */
#define CONFIG_MACH_TYPE MACH_TYPE_HC1703_1723_1753_1783S
#if defined(CONFIG_KAMO)
#define CONFIG_SPL_TEXT_BASE            0xFFE00000
#elif defined(CONFIG_OSAKA)
#define CONFIG_SPL_TEXT_BASE		0xFFFE8000
#define CONFIG_SPL_TEXT_SIZE             0x6000
#define CONFIG_SPL_BSS_START_ADDR	(CONFIG_SPL_TEXT_BASE + CONFIG_SPL_TEXT_SIZE)
#define CONFIG_SPL_BSS_MAX_SIZE		0x1000
#else
#define CONFIG_SPL_TEXT_BASE            0xFFE00800
#endif

#define CONFIG_WDT_CLK              24000000

/* ethernet definitions */
#if defined(CONFIG_OSAKA)
#define PHY_RESET_GPIO 110
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define PHY_RESET_GPIO 18
#else
#define PHY_RESET_GPIO 26
#endif

#ifdef CONFIG_FPGA
#define SYS_CLK_FREQ CONFIG_CPU_FREQUENCY
#define UART_CLOCK (12000000)
#else
#define UART_CLOCK (125000000)
#if defined(CONFIG_CPU_LOW_SPEED)
#define SYS_CLK_FREQ 450000000
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
#define SYS_CLK_FREQ 891000000
#elif defined(CONFIG_KAMO)
#define SYS_CLK_FREQ 798000000
#else
#define SYS_CLK_FREQ 1008000000
#endif
#endif
#define LOOPS_PER_JIFFY (SYS_CLK_FREQ / 100)

/* ARM archetectural optimization */
#if !defined(CONFIG_OSAKA)
#define CONFIG_USE_ARCH_MEMCPY
#define CONFIG_USE_ARCH_MEMSET
#endif

/* Enable U-Boot IRQ support */
#define CONFIG_USE_IRQ                           
#ifndef CONFIG_STACKSIZE_IRQ
#define CONFIG_STACKSIZE_IRQ (64 * 1024)
#endif
#ifndef CONFIG_STACKSIZE_FIQ
#define CONFIG_STACKSIZE_FIQ 64
#endif

#define CONFIG_SYS_ARCH_TIMER
#define CONFIG_SYS_HZ_CLOCK   SYS_CLK_FREQ

/* Misc CPU related */
#define CONFIG_CMDLINE_TAG      /* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_SYS_GENERIC_GLOBAL_DATA 1

/*
 * Skip low level CPU, PLL and DRAM init function,
 * since ROM code and FSBL have handled this part
 */
#define CONFIG_SKIP_LOWLEVEL_INIT

/* MTD partition preset of Augentix reference products */

#define MTDIDS_DEFAULT_NAND "nand0=nand_flash"
#define MTDIDS_DEFAULT_NOR "nor0=nor_flash"

#define MTDPARTS_NAND_128MB_AMP_SLOT_AB "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),8m(linux_0),48m(rootfs_0),8m(linux_1),48m(rootfs_1),8m(usrdata),5m(calib),2m(rtos)"

#define MTDPARTS_NAND_128MB_SLOT_AB "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),8m(linux_0),48m(rootfs_0),8m(linux_1),48m(rootfs_1),8m(usrdata),7m(calib)"

#define MTDPARTS_NAND_128MB_TEE_SLOT_AB "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),7m(linux_0),47m(rootfs_0),7m(linux_1),47m(rootfs_1),8m(usrdata),8m(calib),1m(tee_0),1m(tee_1)"

#define MTDPARTS_NAND_512MB_SLOT_AB "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),8m(linux_0),48m(rootfs_0),8m(linux_1),48m(rootfs_1),392m(usrdata),7m(calib)"

#define MTDPARTS_NAND_128MB_ROOTFS_SINGLE "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),8m(linux),109m(rootfs_0),8m(usrdata),-(calib)"

#define MTDPARTS_NAND_256MB_SLOT_AB "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),5m(linux_0),117m(rootfs_0),5m(linux_1),117m(rootfs_1),8m(usrdata)"

#define MTDPARTS_NAND_32MB_ROOTFS_AB "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),2560k(linux),11m(rootfs_0),11m(rootfs_1),6656k(usrdata)"

#define MTDPARTS_NAND_32MB_ROOTFS_SINGLE "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),2560k(linux),22m(rootfs_0),6656k(usrdata)"

#define MTDPARTS_NOR_8MB "mtdparts=nor_flash:256k(boot),64k(bootenv),1664k(linux),5568k(rootfs),640k(usrdata)"

#define MTDPARTS_NOR_8MB_V2 "mtdparts=nor_flash:256k(boot),64k(bootenv),1856k(linux),5504k(rootfs),512k(usrdata)"

#define MTDPARTS_NOR_16MB "mtdparts=nor_flash:256k(boot),64k(bootenv),2560k(linux),11m(rootfs),2240k(usrdata)"

#define MTDPARTS_NOR_16MB_V2 "mtdparts=nor_flash:256k(boot),64k(bootenv),2112k(linux),12224k(rootfs),1728k(usrdata)"

#define MTDPARTS_NOR_16MB_V3 "mtdparts=nor_flash:256k(boot),64k(bootenv),3584k(linux),10m(rootfs),2240k(usrdata)"

#define MTDPARTS_NOR_32MB "mtdparts=nor_flash:256k(boot),64k(bootenv),2560k(linux),27m(rootfs),2240k(usrdata)"

#define MTDPARTS_NOR_32MB_V2 "mtdparts=nor_flash:256k(boot),64k(bootenv),4096k(linux),26112k(rootfs),2240k(usrdata)"

#define MTDPARTS_NOR_32MB_V4 "mtdparts=nor_flash:960k(boot),64k(bootenv),6m(linux),20m(rootfs),5m(usrdata)"

#define MTDPARTS_NOR_32MB_AMP "mtdparts=nor_flash:256k(boot),64k(bootenv),2560k(linux),25m(rootfs),2240k(usrdata),2m(rtos)" 

#define MTDPARTS_NOR_32MB_AMP_SEC "mtdparts=nor_flash:320k(boot),64k(bootenv),9024k(linux),18048k(rootfs),2240k(usrdata),3m(rtos)"

#define MTDPARTS_NOR_32MB_AMP_SEC_SLOT_AB "mtdparts=nor_flash:320k(boot),64k(bootenv),5824k(linux_0),7680k(rootfs_0),5824k(linux_1),7680k(rootfs_1),2304k(usrdata),3m(rtos)"

#define MTDPARTS_NOR_32MB_SLOT_AB "mtdparts=nor_flash:960k(boot),64k(bootenv),6m(linux_0),8m(rootfs_0),6m(linux_1),8m(rootfs_1),3m(usrdata)"

#define MTDPARTS_NOR_32MB_TEE_SLOT_AB "mtdparts=nor_flash:960k(boot),64k(bootenv),3m(linux_0),10752k(rootfs_0),3m(linux_1),10752k(rootfs_1),2m(usrdata),960k(tee_0),960k(tee_1)"

#define MTDPARTS_NOR_32MB_TEE "mtdparts=nor_flash:960k(boot),64k(bootenv),6m(linux),22m(rootfs),2m(usrdata),896k(tee)"

#define MTDPARTS_AGT100_22 "mtdparts=nor_flash:320k(boot),64k(bootenv),2496k(linux),27m(rootfs),2240k(usrdata)"

#define MTDPARTS_AGT300_29 "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),2688k(linux_0),11m(rootfs_0),2688k(linux_1),11m(rootfs_1)"

#define MTDPARTS_AGT705_3 "mtdparts=nor_flash:960k(boot),64k(bootenv),6m(linux),20m(rootfs),5m(usrdata)"

#define MTDPARTS_AGT705_4 "mtdparts=nor_flash:960k(boot),64k(bootenv),3m(linux_0),12m(rootfs_0),3m(linux_1),12m(rootfs_1),1m(usrdata)"

#define MTDPARTS_AGT705_6 "mtdparts=nor_flash:960k(boot),64k(bootenv),3m(linux_0),12m(rootfs_0),3m(linux_1),12m(rootfs_1),1m(usrdata)"

#define MTDPARTS_AGT705_7 "mtdparts=nor_flash:960k(boot),64k(bootenv),3m(linux_0),12m(rootfs_0),3m(linux_1),12m(rootfs_1),1m(usrdata)"

#define MTDPARTS_AGT725_12 "mtdparts=nor_flash:256k(boot),64k(bootenv),4096k(linux),24064k(rootfs),2240k(usrdata),2m(rtos)"

#define MTDPARTS_AGT301_20 "mtdparts=nor_flash:256k(boot),64k(bootenv),3584k(linux),24m(rootfs),2240k(usrdata),2m(rtos)"

#define MTDPARTS_AGT301_23 "mtdparts=nor_flash:256k(boot),64k(bootenv),4096k(linux),24064k(rootfs),2240k(usrdata),2m(rtos)"

#define MTDPARTS_AGT725_11 "mtdparts=nor_flash:320k(boot),64k(bootenv),5120k(linux),16384k(rootfs),6784k(usrdata),4m(rtos)"

#define MTDPARTS_AGT785_1 "mtdparts=nor_flash:128k(bl2),512k(fip),64k(bootenv),9m(linux),17m(rootfs),4m(usrdata),64k(baremetal),64k(dtb)"

#define MTDPARTS_NOR_16MB_TEE "mtdparts=nor_flash:384k(boot),64k(factory),64k(bootenv),512k(config),3m(linux),2m(rootfs),9216k(appfs),896k(tee)"

#define MTDPARTS_DFN202_113002 "mtdparts=nand_flash:512k(boot),256k(bootenv_0),256k(bootenv_1),12544k(linux_0),44m(rootfs_0),12544k(linux_1),44m(rootfs_1),5888k(usrdata),5888k(calib),1m(tee_0),1m(tee_1)"

/* FAT */
#define CONFIG_FS_FAT
#define CONFIG_FAT_WRITE
#define CONFIG_CMD_FAT
#define CONFIG_CMD_FS_GENERIC
#define CONFIG_SUPPORT_VFAT
#define CONFIG_PARTITION_UUIDS
#define CONFIG_DOS_PARTITION
#define CONFIG_CMD_PART

/* rootfs mtd id configuration */
#ifdef CONFIG_FLASH_NOR
#define ROOTFS_MTDID "/dev/mtdblock${rootfs_mtdid}"
#elif defined(CONFIG_FLASH_NAND)
#if defined(CONFIG_ROOTFS_SQUASHFS_OVER_UBI) && defined (CONFIG_KERNEL_V6_1)
#define ROOTFS_MTDID "/dev/ubiblock0_0"
#else
#define ROOTFS_MTDID "/dev/mtdblock${rootfs_ubi_mtdid}"
#endif
#endif

#if defined(CONFIG_ROOTFS_SQUASHFS_OVER_UBI) && defined (CONFIG_KERNEL_V6_1)
#define UBI_BLKDEV "ubi.block=0,0"
#else
#define UBI_BLKDEV ""
#endif

/* Secure boot*/
#ifdef CONFIG_SECURE_BOOT

#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_WRITEABLE_LIST
#define CONFIG_ENV_APPEND
#define CONFIG_CMD_ENV_FLAGS
#define CONFIG_ENV_FLAGS_LIST_DEFAULT \
       "ethaddr:mw," \
       "bootcounter:dw," \
       "slot_a_successful:dw,slot_b_successful:dw," \
       "slot_a_active:dw,slot_b_active:dw," \
       "slot_a_bootable:dw,slot_b_bootable:dw," \
       "fal_alarm_debug:dw," \
       "fal_alarm_frame_num:dw," \
       "fal_alarm_type:dw," \
       "fal_alarm_thre:dw," \
       "factory_mode:dw," \
       "envsaved:dw"
#define CONFIG_ENV_FLAGS_LIST_STATIC CONFIG_ENV_FLAGS_LIST_DEFAULT
#define BOOT_FAIL_HANDLE "echo invalid image;loop 0 4"
#define SEC_BOOT_SOURCE_ARG \
	"source ${kernel_memaddr}:script-1; "

#if defined(CONFIG_KERNEL_V6_1) && defined(CONFIG_DM_INIT)
#define SEC_BOOT_SET_ARG \
	"dm-mod.create=\\\\\"\"rootfs,,,ro, 0 ${num_sectors} verity 1 "TO_STR(ROOTFS_MTDID)" "TO_STR(ROOTFS_MTDID)" ${data_block_size} ${hash_block_size} ${data_blocks} ${hash_offset_block} ${hash_algo} ${roothash} ${salt}\"\\\\\" "
#define ROOT_DEVICE ""TO_STR(UBI_BLKDEV)" root=/dev/dm-0"
#else /* !CONFIG_KERNEL_V6_1 && !CONFIG_DM_INIT */
#define SEC_BOOT_SET_ARG \
	"hash_offset=${hash_offset} roothash=${roothash} "
#define ROOT_DEVICE ""TO_STR(UBI_BLKDEV)" root="TO_STR(ROOTFS_MTDID)""
#endif

#else /* !CONFIG_SECURE_BOOT */
#define BOOT_FAIL_HANDLE ""
#define SEC_BOOT_SOURCE_ARG ""
#define SEC_BOOT_SET_ARG ""
#define ROOT_DEVICE ""TO_STR(UBI_BLKDEV)" root="TO_STR(ROOTFS_MTDID)""
#endif

/* clang-format on */
#endif
