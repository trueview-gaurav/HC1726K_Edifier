#ifndef __AUGENTIX_NAND_ECC_H__
#define __AUGENTIX_NAND_ECC_H__
#include <linux/mtd/nand.h>

struct nand_ecc_info {
	char *name;
	u8 id_len;
	u8 flash_id[3];
	u8 oobsize;
	u8 ecc_steps;
	u8 ecc_bytes;
	struct nand_ecclayout* ecc_layout;
};

#define AUGENTIX_ECC_SPINAND(nm, len, id_0, id_1, id_2, oob_size, steps, bytes, layout) \
 { .name = (nm), .id_len = len, .flash_id[0] = (id_0), .flash_id[1] = (id_1), .flash_id[2] = (id_2), \
   .oobsize = (oob_size), .ecc_steps = (steps), .ecc_bytes = (bytes), \
 .ecc_layout = (layout) }


struct nand_ecc_info* get_ecc_info(u8 id0, u8 id1, u8 id2);

#endif
