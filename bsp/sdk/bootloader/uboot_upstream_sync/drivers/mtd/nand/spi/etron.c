// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2026 Augentix Inc.
 */

#ifndef __UBOOT__
#include <linux/device.h>
#include <linux/kernel.h>
#endif
#include <linux/mtd/spinand.h>

#define SPINAND_MFR_ETRON		0xD5

static SPINAND_OP_VARIANTS(read_cache_variants,
		SPINAND_PAGE_READ_FROM_CACHE_1S_1S_4S_OP(0, 1, NULL, 0, 0),
		SPINAND_PAGE_READ_FROM_CACHE_1S_1S_2S_OP(0, 1, NULL, 0, 0),
		SPINAND_PAGE_READ_FROM_CACHE_FAST_1S_1S_1S_OP(0, 1, NULL, 0, 0),
		SPINAND_PAGE_READ_FROM_CACHE_1S_1S_1S_OP(0, 1, NULL, 0, 0));

static SPINAND_OP_VARIANTS(write_cache_variants,
		SPINAND_PROG_LOAD_1S_1S_4S_OP(true, 0, NULL, 0),
		SPINAND_PROG_LOAD_1S_1S_1S_OP(true, 0, NULL, 0));

static SPINAND_OP_VARIANTS(update_cache_variants,
		SPINAND_PROG_LOAD_1S_1S_4S_OP(false, 0, NULL, 0),
		SPINAND_PROG_LOAD_1S_1S_1S_OP(false, 0, NULL, 0));

static int em73c044sna_ooblayout_ecc(struct mtd_info *mtd, int section,
				     struct mtd_oob_region *region)
{
	if (section > 3)
		return -ERANGE;

	region->offset = (16 * section) + 2;
	region->length = 14;

	return 0;
}

static int em73c044sna_ooblayout_free(struct mtd_info *mtd, int section,
				      struct mtd_oob_region *region)
{
	if (section > 3)
		return -ERANGE;

	if (!section) {
		region->offset = 1;
		region->length = 1;
	} else {
		region->offset = 16 * section;
		region->length = 2;
	}

	return 0;
}

static const struct mtd_ooblayout_ops em73c044sna_ooblayout = {
	.ecc = em73c044sna_ooblayout_ecc,
	.rfree = em73c044sna_ooblayout_free,
};

static int em73c044snb_ooblayout_ecc(struct mtd_info *mtd, int section,
				     struct mtd_oob_region *region)
{
	if (section > 3)
		return -ERANGE;

	region->offset = (30 * section) + 16;
	region->length = 14;

	return 0;
}

static int em73c044snb_ooblayout_free(struct mtd_info *mtd, int section,
				      struct mtd_oob_region *region)
{
	if (section > 3)
		return -ERANGE;

	region->offset = (30 * section) + 2;
	region->length = 14;

	return 0;
}

static const struct mtd_ooblayout_ops em73c044snb_ooblayout = {
	.ecc = em73c044snb_ooblayout_ecc,
	.rfree = em73c044snb_ooblayout_free,
};

static int em73c044snf_ooblayout_ecc(struct mtd_info *mtd, int section,
				     struct mtd_oob_region *region)
{
	if (section > 3)
		return -ERANGE;

	region->offset = (30 * section) + 18;
	region->length = 14;

	return 0;
}

static int em73c044snf_ooblayout_free(struct mtd_info *mtd, int section,
				      struct mtd_oob_region *region)
{
	if (section > 3)
		return -ERANGE;

	region->offset = (30 * section) + 4;
	region->length = 14;

	return 0;
}

static const struct mtd_ooblayout_ops em73c044snf_ooblayout = {
	.ecc = em73c044snf_ooblayout_ecc,
	.rfree = em73c044snf_ooblayout_free,
};

static int em73d044vco_ooblayout_ecc(struct mtd_info *mtd, int section,
				     struct mtd_oob_region *region)
{
	if (section)
		return -ERANGE;

	region->offset = 72;
	region->length = 56;

	return 0;
}

static int em73d044vco_ooblayout_free(struct mtd_info *mtd, int section,
				      struct mtd_oob_region *region)
{
	if (section)
		return -ERANGE;

	region->offset = 1;
	region->length = 71;

	return 0;
}

static const struct mtd_ooblayout_ops em73d044vco_ooblayout = {
	.ecc = em73d044vco_ooblayout_ecc,
	.rfree = em73d044vco_ooblayout_free,
};

static int em73b044vca_ooblayout_ecc(struct mtd_info *mtd, int section,
				     struct mtd_oob_region *region)
{
	if (section > 3)
		return -ERANGE;

	region->offset = (16 * section) + 8;
	region->length = 8;

	return 0;
}

static int em73b044vca_ooblayout_free(struct mtd_info *mtd, int section,
				     struct mtd_oob_region *region)
{
	if (section > 3)
		return -ERANGE;

	region->offset = (16 * section) + 2;
	region->length = 6;

	return 0;
}

static const struct mtd_ooblayout_ops em73b044vca_ooblayout = {
	.ecc = em73b044vca_ooblayout_ecc,
	.rfree = em73b044vca_ooblayout_free,
};

static int em73c044vcf_ooblayout_ecc(struct mtd_info *mtd, int section,
				     struct mtd_oob_region *region)
{
	if (section)
		return -ERANGE;

	region->offset = 32;
	region->length = 32;

	return 0;
}

static int em73c044vcf_ooblayout_free(struct mtd_info *mtd, int section,
				      struct mtd_oob_region *region)
{
	if (section)
		return -ERANGE;

	region->offset = 1;
	region->length = 31;

	return 0;
}

static const struct mtd_ooblayout_ops em73c044vcf_ooblayout = {
	.ecc = em73c044vcf_ooblayout_ecc,
	.rfree = em73c044vcf_ooblayout_free,
};

static const struct spinand_info etron_spinand_table[] = {
	SPINAND_INFO("EM73C044SNA-G",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x19),
		     NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&em73c044sna_ooblayout, NULL)),
	SPINAND_INFO("EM73C044SNB-G",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x11),
		     NAND_MEMORG(1, 2048, 128, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&em73c044snb_ooblayout, NULL)),
	SPINAND_INFO("EM73C044SNF-G",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x09),
		     NAND_MEMORG(1, 2048, 128, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&em73c044snf_ooblayout, NULL)),
	SPINAND_INFO("EM73D044VCO-H",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x3A),
		     NAND_MEMORG(1, 2048, 128, 64, 2048, 40, 1, 1, 1),
		     NAND_ECCREQ(8, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&em73d044vco_ooblayout, NULL)),
	SPINAND_INFO("EM73B044VCA-H",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x01),
		     NAND_MEMORG(1, 2048, 64, 64, 512, 10, 1, 1, 1),
		     NAND_ECCREQ(4, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&em73b044vca_ooblayout, NULL)),
	SPINAND_INFO("EM73C044VCD-H",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x1C),
		     NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(4, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&em73b044vca_ooblayout, NULL)),
	SPINAND_INFO("EM73C044VCF-H",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x25),
		     NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(4, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&em73c044vcf_ooblayout, NULL)),
};

static const struct spinand_manufacturer_ops etron_spinand_manuf_ops = {
};

const struct spinand_manufacturer etron_spinand_manufacturer = {
	.id = SPINAND_MFR_ETRON,
	.name = "Etron",
	.chips = etron_spinand_table,
	.nchips = ARRAY_SIZE(etron_spinand_table),
	.ops = &etron_spinand_manuf_ops,
};
