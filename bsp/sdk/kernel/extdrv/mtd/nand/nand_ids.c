/*
 *  drivers/mtd/nandids.c
 *
 *  Copyright (C) 2002 Thomas Gleixner (tglx@linutronix.de)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */
#include <linux/module.h>
#include <linux/mtd/nand.h>
#include <linux/sizes.h>

#define LP_OPTIONS NAND_SAMSUNG_LP_OPTIONS
#define LP_OPTIONS16 (LP_OPTIONS | NAND_BUSWIDTH_16)

#define SP_OPTIONS NAND_NEED_READRDY
#define SP_OPTIONS16 (SP_OPTIONS | NAND_BUSWIDTH_16)

/*
 * The chip ID list:
 *    name, device ID, page size, chip size in MiB, eraseblock size, options
 *
 * If page size and eraseblock size are 0, the sizes are taken from the
 * extended chip ID.
 */
struct nand_flash_dev nand_flash_ids[] = {
	/*
	 * Some incompatible NAND chips share device ID's and so must be
	 * listed by full ID. We list them first so that we can easily identify
	 * the most specific match.
	 */
	{ "TC58NVG2S0F 4G 3.3V 8-bit",
	  { .id = { 0x98, 0xdc, 0x90, 0x26, 0x76, 0x15, 0x01, 0x08 } },
	  SZ_4K,
	  SZ_512,
	  SZ_256K,
	  0,
	  8,
	  224,
	  NAND_ECC_INFO(4, SZ_512) },
	{ "TC58NVG3S0F 8G 3.3V 8-bit",
	  { .id = { 0x98, 0xd3, 0x90, 0x26, 0x76, 0x15, 0x02, 0x08 } },
	  SZ_4K,
	  SZ_1K,
	  SZ_256K,
	  0,
	  8,
	  232,
	  NAND_ECC_INFO(4, SZ_512) },
	{ "TC58NVG5D2 32G 3.3V 8-bit",
	  { .id = { 0x98, 0xd7, 0x94, 0x32, 0x76, 0x56, 0x09, 0x00 } },
	  SZ_8K,
	  SZ_4K,
	  SZ_1M,
	  0,
	  8,
	  640,
	  NAND_ECC_INFO(40, SZ_1K) },
	{ "TC58NVG6D2 64G 3.3V 8-bit",
	  { .id = { 0x98, 0xde, 0x94, 0x82, 0x76, 0x56, 0x04, 0x20 } },
	  SZ_8K,
	  SZ_8K,
	  SZ_2M,
	  0,
	  8,
	  640,
	  NAND_ECC_INFO(40, SZ_1K) },
	{ "SDTNRGAMA 64G 3.3V 8-bit",
	  { .id = { 0x45, 0xde, 0x94, 0x93, 0x76, 0x50 } },
	  SZ_16K,
	  SZ_8K,
	  SZ_4M,
	  0,
	  6,
	  1280,
	  NAND_ECC_INFO(40, SZ_1K) },
	{ "H27UCG8T2ATR-BC 64G 3.3V 8-bit",
	  { .id = { 0xad, 0xde, 0x94, 0xda, 0x74, 0xc4 } },
	  SZ_8K,
	  SZ_8K,
	  SZ_2M,
	  0,
	  6,
	  640,
	  NAND_ECC_INFO(40, SZ_1K),
	  4 },
	{ "W25N512GV 64MiB 3.3V 8-bit",
	  { .id = { 0xEF, 0xAA, 0x20 } }, //Winbond W25N512GV
	  SZ_2K,
	  64,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  64 },
	{ "W25N01GV 128MiB 3.3V 8-bit",
	  { .id = { 0xEF, 0xAA, 0x21 } }, //Winbond W25N01GV
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  64 },
	{ "W25N01GW 128MiB 1.8V 8-bit",
	  { .id = { 0xEF, 0xBA, 0x21 } }, //Winbond W25N01GW
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  64 },
	{ "W25N01KV 128MiB 3.3V 8-bit",
	  { .id = { 0xEF, 0xAE, 0x21 } }, //Winbond W25N01KV
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  64 },
	{ "W25N02KV 256MiB 3.3V 8-bit",
	  { .id = { 0xEF, 0xAA, 0x22 } }, //Winbond W25N02KV
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  128 },
	{ "W25N04KV 512MiB 3.3V 8-bit",
	  { .id = { 0xEF, 0xAA, 0x23 } }, //Winbond W25N04KV
	  SZ_2K,
	  512,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  128 },
	{ "W25N02LV 256MiB 3.3V 8-bit",
	  { .id = { 0xEF, 0x8A, 0x22 } }, //Winbond W25N02LV
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  128 },
	{ "MX35LF1GE4AB 128MiB 3.3V 8-bit",
	  { .id = { 0xC2, 0x12 } }, //MXIC MX35LF1GE4AB
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "MX35LF2GE4AD 256MiB 3.3V 8-bit",
	  { .id = { 0xC2, 0x26, 0x03 } }, //MXIC MX35LF1GE4AB
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  64 },
	{ "EM73C044SNA 128MiB 3.3V 8-bit",
	  { .id = { 0xD5, 0x19 } }, //Etron EM73C044SNA
	  SZ_2K,
	  128,
	  SZ_256K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "EM73C044SNB 128MiB 3.3V 8-bit",
	  { .id = { 0xD5, 0x11 } }, //Etron EM73C044SNB
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "EM73C044SNF 128MiB 3.3V 8-bit",
	  { .id = { 0xD5, 0x09 } }, //Etron EM73C044SNF
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "EM73D044VCO 256MiB 3.3V 8-bit",
	  { .id = { 0xD5, 0x3A } }, //Etron EM73D044VCO
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "EM73B044VCA 64MiB 3.3V 8-bit",
	  { .id = { 0xD5, 0x01 } }, //Etron EM73B044VCA
	  SZ_2K,
	  64,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "EM73C044VCD 128MiB 3.3V 8-bit",
	  { .id = { 0xD5, 0x1C } }, //Etron EM73C044VCD
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "EM73C044VCF 128MiB 3.3V 8-bit",
	  { .id = { 0xD5, 0x25 } }, //Etron EM73C044VCF
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "GD5F1GQ4U 128MiB 3.3V 8-bit",
	  { .id = { 0xC8, 0xD1 } }, //GD GD5F1GQ4U
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "GD5F2GQ4U 256MiB 3.3V 8-bit",
	  { .id = { 0xC8, 0xD2 } }, //GD GD5F2GQ4U
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "GD5F2GQ5U 256MiB 3.3V 8-bit",
	  { .id = { 0xC8, 0x32 } }, //GD GD5F2GQ5U
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "GD5F2GQ5UYIG 256MiB 3.3V 8-bit",
	  { .id = { 0xC8, 0x52 } }, //GD GD5F2GQ5UYIG
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "GD5F2GM7UEYIGR 256MiB 3.3V 8-bit",
	  { .id = { 0xC8, 0x92 } }, //GD GD5F2GM7UEYIGR
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "GD5F1GM7UE 128MiB 3.3V 8-bit",
	  { .id = { 0xC8, 0x91 } }, //GD GD5F2GM7UEYIGR
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	 128 },
	{ "F50L1G41LB 128MiB 3.3V 8-bit",
	  { .id = { 0xC8, 0x01 } }, //ESMT F50L1G41LB
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "XT26G01AWSEGA 128MiB 3.3V 8-bit",
	  { .id = { 0x0B, 0xE1 } }, //XTX XT26G01AWSEGA
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  64 },
	{ "XT26G01C 1GMiB 3.3V 8-bit",
	  { .id = { 0x0B, 0x11 } }, //XTX XT26G01C
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  116 },
	{ "XT26G01D 1GMiB 3.3V 8-bit",
	  { .id = { 0x0B, 0x31 } }, //XTX XT26G01D
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "XT26G02C 256MiB 3.3V 8-bit",
	  { .id = { 0x0B, 0x12 } }, //XTX XT26G02C
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  116 },
	{ "XT26G02D 256MiB 3.3V 8-bit",
	  { .id = { 0x0B, 0x32 } }, //XTX XT26G02D
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "MT29F1G01ABA 128MiB 3.3V 8-bit",
	  { .id = { 0x2C, 0x14 } }, //MICRON MT29F1G01ABA
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  2,
	  128 },
	{ "TC58CVG0S3HRAIJ 1GMiB 3.3V 8-bit",
	  { .id = { 0x98, 0xE2, 0x40 } }, //KIOXIA TC58CVG0S3HRAIJ
	  SZ_2K,
	  128,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  128 },
	{ "TC58CVG1S3HRAIJ 2GMiB 3.3V 8-bit",
	  { .id = { 0x98, 0xEB, 0x40 } }, //KIOXIA TC58CVG1S3HRAIJ
	  SZ_2K,
	  256,
	  SZ_128K,
	  NAND_CACHEPRG,
	  3,
	  128 },
        { "HYF1GQ4UDACAE 2GMiB 3.3V 8-bit",
         { .id = { 0xC9, 0x21 } }, //KIOXIA TC58CVG1S3HRAIJ
         SZ_2K,
         128,
         SZ_128K,
         NAND_CACHEPRG,
         2,
         64 },

	LEGACY_ID_NAND("NAND 4MiB 5V 8-bit", 0x6B, 4, SZ_8K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 4MiB 3,3V 8-bit", 0xE3, 4, SZ_8K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 4MiB 3,3V 8-bit", 0xE5, 4, SZ_8K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 8MiB 3,3V 8-bit", 0xD6, 8, SZ_8K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 8MiB 3,3V 8-bit", 0xE6, 8, SZ_8K, SP_OPTIONS),

	LEGACY_ID_NAND("NAND 16MiB 1,8V 8-bit", 0x33, 16, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 16MiB 3,3V 8-bit", 0x73, 16, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 16MiB 1,8V 16-bit", 0x43, 16, SZ_16K, SP_OPTIONS16),
	LEGACY_ID_NAND("NAND 16MiB 3,3V 16-bit", 0x53, 16, SZ_16K, SP_OPTIONS16),

	LEGACY_ID_NAND("NAND 32MiB 1,8V 8-bit", 0x35, 32, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 32MiB 3,3V 8-bit", 0x75, 32, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 32MiB 1,8V 16-bit", 0x45, 32, SZ_16K, SP_OPTIONS16),
	LEGACY_ID_NAND("NAND 32MiB 3,3V 16-bit", 0x55, 32, SZ_16K, SP_OPTIONS16),

	LEGACY_ID_NAND("NAND 64MiB 1,8V 8-bit", 0x36, 64, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 64MiB 3,3V 8-bit", 0x76, 64, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 64MiB 1,8V 16-bit", 0x46, 64, SZ_16K, SP_OPTIONS16),
	LEGACY_ID_NAND("NAND 64MiB 3,3V 16-bit", 0x56, 64, SZ_16K, SP_OPTIONS16),

	LEGACY_ID_NAND("NAND 128MiB 1,8V 8-bit", 0x78, 128, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 128MiB 1,8V 8-bit", 0x39, 128, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 128MiB 3,3V 8-bit", 0x79, 128, SZ_16K, SP_OPTIONS),
	LEGACY_ID_NAND("NAND 128MiB 1,8V 16-bit", 0x72, 128, SZ_16K, SP_OPTIONS16),
	LEGACY_ID_NAND("NAND 128MiB 1,8V 16-bit", 0x49, 128, SZ_16K, SP_OPTIONS16),
	LEGACY_ID_NAND("NAND 128MiB 3,3V 16-bit", 0x74, 128, SZ_16K, SP_OPTIONS16),
	LEGACY_ID_NAND("NAND 128MiB 3,3V 16-bit", 0x59, 128, SZ_16K, SP_OPTIONS16),

	LEGACY_ID_NAND("NAND 256MiB 3,3V 8-bit", 0x71, 256, SZ_16K, SP_OPTIONS),

	/*
	 * These are the new chips with large page size. Their page size and
	 * eraseblock size are determined from the extended ID bytes.
	 */

	/* 512 Megabit */
	EXTENDED_ID_NAND("NAND 64MiB 1,8V 8-bit", 0xA2, 64, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 64MiB 1,8V 8-bit", 0xA0, 64, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 64MiB 3,3V 8-bit", 0xF2, 64, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 64MiB 3,3V 8-bit", 0xD0, 64, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 64MiB 3,3V 8-bit", 0xF0, 64, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 64MiB 1,8V 16-bit", 0xB2, 64, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 64MiB 1,8V 16-bit", 0xB0, 64, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 64MiB 3,3V 16-bit", 0xC2, 64, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 64MiB 3,3V 16-bit", 0xC0, 64, LP_OPTIONS16),

	/* 1 Gigabit */
	EXTENDED_ID_NAND("NAND 128MiB 1,8V 8-bit", 0xA1, 128, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 128MiB 3,3V 8-bit", 0xF1, 128, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 128MiB 3,3V 8-bit", 0xD1, 128, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 128MiB 1,8V 16-bit", 0xB1, 128, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 128MiB 3,3V 16-bit", 0xC1, 128, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 128MiB 1,8V 16-bit", 0xAD, 128, LP_OPTIONS16),

	/* 2 Gigabit */
	EXTENDED_ID_NAND("NAND 256MiB 1,8V 8-bit", 0xAA, 256, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 256MiB 3,3V 8-bit", 0xDA, 256, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 256MiB 1,8V 16-bit", 0xBA, 256, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 256MiB 3,3V 16-bit", 0xCA, 256, LP_OPTIONS16),

	/* 4 Gigabit */
	EXTENDED_ID_NAND("NAND 512MiB 1,8V 8-bit", 0xAC, 512, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 512MiB 3,3V 8-bit", 0xDC, 512, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 512MiB 1,8V 16-bit", 0xBC, 512, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 512MiB 3,3V 16-bit", 0xCC, 512, LP_OPTIONS16),

	/* 8 Gigabit */
	EXTENDED_ID_NAND("NAND 1GiB 1,8V 8-bit", 0xA3, 1024, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 1GiB 3,3V 8-bit", 0xD3, 1024, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 1GiB 1,8V 16-bit", 0xB3, 1024, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 1GiB 3,3V 16-bit", 0xC3, 1024, LP_OPTIONS16),

	/* 16 Gigabit */
	EXTENDED_ID_NAND("NAND 2GiB 1,8V 8-bit", 0xA5, 2048, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 2GiB 3,3V 8-bit", 0xD5, 2048, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 2GiB 1,8V 16-bit", 0xB5, 2048, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 2GiB 3,3V 16-bit", 0xC5, 2048, LP_OPTIONS16),

	/* 32 Gigabit */
	EXTENDED_ID_NAND("NAND 4GiB 1,8V 8-bit", 0xA7, 4096, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 4GiB 3,3V 8-bit", 0xD7, 4096, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 4GiB 1,8V 16-bit", 0xB7, 4096, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 4GiB 3,3V 16-bit", 0xC7, 4096, LP_OPTIONS16),

	/* 64 Gigabit */
	EXTENDED_ID_NAND("NAND 8GiB 1,8V 8-bit", 0xAE, 8192, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 8GiB 3,3V 8-bit", 0xDE, 8192, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 8GiB 1,8V 16-bit", 0xBE, 8192, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 8GiB 3,3V 16-bit", 0xCE, 8192, LP_OPTIONS16),

	/* 128 Gigabit */
	EXTENDED_ID_NAND("NAND 16GiB 1,8V 8-bit", 0x1A, 16384, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 16GiB 3,3V 8-bit", 0x3A, 16384, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 16GiB 1,8V 16-bit", 0x2A, 16384, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 16GiB 3,3V 16-bit", 0x4A, 16384, LP_OPTIONS16),

	/* 256 Gigabit */
	EXTENDED_ID_NAND("NAND 32GiB 1,8V 8-bit", 0x1C, 32768, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 32GiB 3,3V 8-bit", 0x3C, 32768, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 32GiB 1,8V 16-bit", 0x2C, 32768, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 32GiB 3,3V 16-bit", 0x4C, 32768, LP_OPTIONS16),

	/* 512 Gigabit */
	EXTENDED_ID_NAND("NAND 64GiB 1,8V 8-bit", 0x1E, 65536, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 64GiB 3,3V 8-bit", 0x3E, 65536, LP_OPTIONS),
	EXTENDED_ID_NAND("NAND 64GiB 1,8V 16-bit", 0x2E, 65536, LP_OPTIONS16),
	EXTENDED_ID_NAND("NAND 64GiB 3,3V 16-bit", 0x4E, 65536, LP_OPTIONS16),

	{ NULL }
};

/* Manufacturer IDs */
struct nand_manufacturers nand_manuf_ids[] = { { NAND_MFR_TOSHIBA, "Toshiba" },
	                                       { NAND_MFR_SAMSUNG, "Samsung" },
	                                       { NAND_MFR_FUJITSU, "Fujitsu" },
	                                       { NAND_MFR_NATIONAL, "National" },
	                                       { NAND_MFR_RENESAS, "Renesas" },
	                                       { NAND_MFR_STMICRO, "ST Micro" },
	                                       { NAND_MFR_HYNIX, "Hynix" },
	                                       { NAND_MFR_MICRON, "Micron" },
	                                       { NAND_MFR_AMD, "AMD/Spansion" },
	                                       { NAND_MFR_MACRONIX, "Macronix" },
	                                       { NAND_MFR_EON, "Eon" },
	                                       { NAND_MFR_SANDISK, "SanDisk" },
	                                       { NAND_MFR_INTEL, "Intel" },
	                                       { NAND_MFR_WINBOND, "Winbond" },
	                                       { NAND_MFR_ETRON, "Etron" },
	                                       { NAND_MFR_GD, "GD" },
	                                       { NAND_MFR_ESMT, "ESMT" },
	                                       { NAND_MFR_XTX, "XTX" },
					       { NAND_MFR_HY, "HY" },
	                                       { 0x0, "Unknown" } };

EXPORT_SYMBOL(nand_manuf_ids);
EXPORT_SYMBOL(nand_flash_ids);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Thomas Gleixner <tglx@linutronix.de>");
MODULE_DESCRIPTION("Nand device & manufacturer IDs");
