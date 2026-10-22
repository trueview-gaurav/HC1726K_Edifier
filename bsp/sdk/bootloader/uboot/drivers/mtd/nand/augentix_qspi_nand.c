#include <common.h>
#include <malloc.h>

#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/partitions.h>

#include <nand.h>
#include <errno.h>
#include <asm/io.h>
#include <spi.h>

#define SUPPORT_HW_ECC
#define BUFSIZE (10 * 64 * 2048)
#define CACHE_BUF 2112

/* cmd */
#define CMD_RESET 0xFF
#define CMD_READ_ID 0x9f
#define CMD_READ_REG 0x0f
#define CMD_WRITE_REG 0x1f
#define CMD_WR_ENABLE 0x06
#define CMD_WR_DISABLE 0x04
#define CMD_ERASE_BLK 0xD8
#define CMD_PROG_PAGE_CLRCACHE 0x02
#define CMD_PROG_PAGE 0x84
#define CMD_PROG_PAGE_QUAD_CLRCACHE 0x32
#define CMD_PROG_PAGE_QUAD 0x34
#define CMD_PROG_PAGE_EXC 0x10
#define CMD_READ 0x13
#define CMD_READ_RDM 0x0B
#define CMD_READ_DRDM 0x3B
#define CMD_READ_QRDM 0x6B
#define AGTX_SINGLE_WRITE 0
#define AGTX_QUAD_WRITE 1

/* feature/ status reg */
#define REG_BLOCK_LOCK 0xa0
#define REG_OTP 0xb0
#define REG_STATUS 0xc0 /* timing */

/* status */
#define STATUS_OIP_MASK 0x01
#define STATUS_READY (0 << 0)
#define STATUS_BUSY (1 << 0)

#define STATUS_E_FAIL_MASK 0x04
#define STATUS_E_FAIL (1 << 2)

#define STATUS_P_FAIL_MASK 0x08
#define STATUS_P_FAIL (1 << 3)

#define STATUS_ECC_MASK 0x30
#define STATUS_ECC_1BIT_CORRECTED (1 << 4)
#define STATUS_ECC_ERROR (2 << 4)
#define STATUS_ECC_RESERVED (3 << 4)

/*ECC enable defines*/
#define OTP_ECC_MASK 0x10
#define OTP_ECC_OFF 0
#define OTP_ECC_ON 1

/*block lock*/
#define BL_ALL_UNLOCKED 0

#define NAND_CMD_TIMEOUT_MS 10

#define OOB_OFFSET 0x800
#define PAGES_OFFSET_64 6 //64

struct nand_ecc_info {
	char *name;
	u8 id_len;
	u8 flash_id[3];
	u8 oobsize;
	u8 ecc_steps;
	u8 ecc_bytes;
	struct nand_ecclayout *ecc_layout;
};

#define AUGENTIX_ECC_SPINAND(nm, len, id_0, id_1, id_2, oob_size, steps, bytes, layout)                           \
	{                                                                                                         \
		.name = (nm), .id_len = len, .flash_id[0] = (id_0), .flash_id[1] = (id_1), .flash_id[2] = (id_2), \
		.oobsize = (oob_size), .ecc_steps = (steps), .ecc_bytes = (bytes), .ecc_layout = (layout)         \
	}

struct nand_ecc_info *get_ecc_info(u8 id0, u8 id1, u8 id2);

struct hc_qspi_nand {
	struct mtd_info *mtd;
	struct nand_chip chip;
	struct spi_slave *slave;
	struct nand_ecclayout *ecclayout;
	uint32_t col;
	uint32_t row;
	int buf_ptr;
	u8 *buf;
};

#define get_hc_qspi_nand(_mtd) (struct hc_qspi_nand *)((struct nand_chip *)_mtd->priv)->priv

struct spinand_cmd {
	u8 cmd;
	u32 n_addr; /* Number of address */
	u8 addr[4]; /* Reg Offset */
	u32 n_dummy; /* Dummy use */
	u32 n_tx; /* Number of tx bytes */
	u8 *tx_buf; /* Tx buf */
	u32 n_rx; /* Number of rx bytes */
	u8 *rx_buf; /* Rx buf */
	u8 bDFS_32; /* 32 bits per word */
};

static struct nand_ecclayout WINBOND_OOB_W25N512GV = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
			.length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout WINBOND_OOB_W25N01GV = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
			.length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout WINBOND_OOB_W25N01GW = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
			.length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};
static struct nand_ecclayout WINBOND_OOB_W25N01KV = { .eccbytes = 32,
	                                              .eccpos = { 8,  9,  10, 11, 12, 13, 14, 15, 24, 25, 26,
	                                                          27, 28, 29, 30, 31, 40, 41, 42, 43, 44, 45,
	                                                          46, 47, 56, 57, 58, 59, 60, 61, 62, 63 },
	                                              .oobavail = 24,
	                                              .oobfree = {
	                                                      { .offset = 2, .length = 6 },
	                                                      { .offset = 18, .length = 6 },
	                                                      { .offset = 34, .length = 6 },
	                                                      { .offset = 50, .length = 6 },
	                                              } };
static struct nand_ecclayout WINBOND_OOB_W25N02KV = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
			.length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout WINBOND_OOB_W25N04KV = { .eccbytes = 52,
	.eccpos = {
		 64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,
		 80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,
		 96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108,
		112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124},
	.oobavail = 48,
	.oobfree = {
			{ .offset = 4, .length = 12 },
			{ .offset = 20, .length = 12 },
			{ .offset = 36, .length = 12 },
			{ .offset = 52, .length = 12 },
	}
};

static struct nand_ecclayout WINBOND_OOB_W25N02LV = { 
	.eccbytes = 52,
	.eccpos = {
		 64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,
		 80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,
		 96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108,
		112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124},
	.oobavail = 48,
	.oobfree = {
			{ .offset = 4, .length = 12 },
			{ .offset = 20, .length = 12 },
			{ .offset = 36, .length = 12 },
			{ .offset = 52, .length = 12 },
	}
};

static struct nand_ecclayout MXIC_OOB_MX35LF1GE4AB = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63 },
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
			.length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout MXIC_OOB_MX35LF2GE4AD = {
	.eccbytes = 48,
	.eccpos = {
		4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63 },
	.oobavail = 8,
	.oobfree = {
		{.offset = 2,
			.length = 2},
		{.offset = 18,
			.length = 2},
		{.offset = 34,
			.length = 2},
		{.offset = 50,
			.length = 2},
	}
};

static struct nand_ecclayout ETRON_OOB_EM73C044SNA_G = {
	.eccbytes = 56,
	.eccpos = {
		2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 ,31,
		34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
		50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 7,
	.oobfree = {
		{.offset = 1,
			.length = 1},
		{.offset = 16,
			.length = 2},
		{.offset = 32,
			.length = 2},
		{.offset = 48,
			.length = 2},
	}
};

static struct nand_ecclayout ETRON_OOB_EM73C044SNB_G = {
	.eccbytes = 56,
	.eccpos = {
		16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
		46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
		76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
		106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119},
	.oobavail = 56,
	.oobfree = {
		{.offset = 2,
		    .length = 14},
		{.offset = 32,
			.length = 14},
		{.offset = 62,
			.length = 14},
		{.offset = 92,
			.length = 14},
	}
};

static struct nand_ecclayout ETRON_OOB_EM73C044SNF_G = {
	.eccbytes = 56,
	.eccpos = {
		18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
		78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91,
		108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121},
	.oobavail = 56,
	.oobfree = {
		{.offset = 4,
		    .length = 14},
		{.offset = 34,
			.length = 14},
		{.offset = 64,
			.length = 14},
		{.offset = 94,
			.length = 14},
	}
};

static struct nand_ecclayout ETRON_OOB_EM73D044VCO_H = {
	.eccbytes = 56,
	.eccpos = {
		72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
		86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
		100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
		114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127},
	.oobavail = 71,
	.oobfree = {
		{.offset = 1,
		    .length = 71},
	}
};

static struct nand_ecclayout ETRON_OOB_EM73B044VCA_H = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
		    .length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout ETRON_OOB_EM73C044VCD_H = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
		    .length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout ETRON_OOB_EM73C044VCF_H = {
	.eccbytes = 32,
	.eccpos = {
		32, 33, 34, 35, 36, 37, 38, 39,
		40, 41, 42, 43, 44, 45, 46, 47,
		48, 49, 50, 51, 52, 53, 54, 55,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 31,
	.oobfree = {
		{.offset = 1,
		    .length = 31},
	}
};

static struct nand_ecclayout GD_OOB_GD5FxxQ4U = {
	.eccbytes = 64,
	.eccpos = {
		64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
		80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
		96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
		112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127},
	.oobavail = 63,
	.oobfree = {
		{.offset = 1,
		    .length = 63},
	}
};

static struct nand_ecclayout GD_OOB_GD5FxxQ5U = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
			.length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout GD_OOB_GD5F2GQ5UYIG = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
			.length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout GD_OOB_GD5F2GM7UEYIGR = {
	.eccbytes = 64,
	.eccpos = {
		64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
		80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
		96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
		112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127},
	.oobavail = 63,
	.oobfree = {
		{.offset = 1,
		    .length = 63},
	}
};

static struct nand_ecclayout GD_OOB_GD5F1GM7UE = {
	.eccbytes = 64,
	.eccpos = {
		64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
		80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
		96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
		112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127},
	.oobavail = 63,
	.oobfree = {
		{.offset = 1,
		    .length = 63},
	}
};

static struct nand_ecclayout ESMT_OOB_F50L1G41LB = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 24,
	.oobfree = {
		{.offset = 2,
		    .length = 6},
		{.offset = 18,
			.length = 6},
		{.offset = 34,
			.length = 6},
		{.offset = 50,
			.length = 6},
	}
};

static struct nand_ecclayout MICRON_OOB_MT29F2G01ABA = {
	.eccbytes = 64,
	.eccpos = {
		64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
		80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
		96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
		112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127},
	.oobavail = 63,
	.oobfree = {
		{.offset = 1,
		    .length = 63},
	}
};

static struct nand_ecclayout KIOXIA_OOB_TC58CVG0S3HRAIJ = { .eccbytes = 64,
	                                                    .eccpos = { 64,  65,  66,  67,  68,  69,  70,  71,
	                                                                72,  73,  74,  75,  76,  77,  78,  79,
	                                                                80,  81,  82,  83,  84,  85,  86,  87,
	                                                                88,  89,  90,  91,  92,  93,  94,  95,
	                                                                96,  97,  98,  99,  100, 101, 102, 103,
	                                                                104, 105, 106, 107, 108, 109, 110, 111,
	                                                                112, 113, 114, 115, 116, 117, 118, 119,
	                                                                120, 121, 122, 123, 124, 125, 126, 127 },
	                                                    .oobavail = 64,
	                                                    .oobfree = {
	                                                            { .offset = 0, .length = 64 },
	                                                    } };

static struct nand_ecclayout KIOXIA_OOB_TC58CVG1S3HRAIJ = { .eccbytes = 64,
	                                                    .eccpos = { 64,  65,  66,  67,  68,  69,  70,  71,
	                                                                72,  73,  74,  75,  76,  77,  78,  79,
	                                                                80,  81,  82,  83,  84,  85,  86,  87,
	                                                                88,  89,  90,  91,  92,  93,  94,  95,
	                                                                96,  97,  98,  99,  100, 101, 102, 103,
	                                                                104, 105, 106, 107, 108, 109, 110, 111,
	                                                                112, 113, 114, 115, 116, 117, 118, 119,
	                                                                120, 121, 122, 123, 124, 125, 126, 127 },
	                                                    .oobavail = 64,
	                                                    .oobfree = {
	                                                            { .offset = 0, .length = 64 },
	                                                    } };

static struct nand_ecclayout XTX_OOB_XT26G01AWSEGA = { .eccbytes = 16,
	                                               .eccpos = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
	                                                           61, 62, 63 },
	                                               .oobavail = 40,
	                                               .oobfree = {
	                                                       { .offset = 8, .length = 40 },
	                                               } };

static struct nand_ecclayout XTX_OOB_XT26G01C = { .eccbytes = 52,
	                                          .eccpos = { 64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,
	                                                      75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,
	                                                      86,  87,  88,  89,  90,  91,  92,  93,  94,  95,  96,
	                                                      97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107,
	                                                      108, 109, 110, 111, 112, 113, 114, 115 },
	                                          .oobavail = 63,
	                                          .oobfree = {
	                                                  { .offset = 1, .length = 63 },
	                                          } };

static struct nand_ecclayout XTX_OOB_XT26G01D = { .eccbytes = 64,
	                                          .eccpos = { 64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,
	                                                      75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,
	                                                      86,  87,  88,  89,  90,  91,  92,  93,  94,  95,  96,
	                                                      97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107,
	                                                      108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
	                                                      119, 120, 121, 122, 123, 124, 125, 126, 127 },
	                                          .oobavail = 63,
	                                          .oobfree = {
	                                                  { .offset = 1, .length = 63 },
	                                          } };

static struct nand_ecclayout XTX_OOB_XT26G02C = {
	.eccbytes = 52,
	.eccpos = {
		64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,
		77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,  88,  89,
		90,  91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102,
		103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115},
	.oobavail = 63,
	.oobfree = {
		{.offset = 1,
		    .length = 63},
	}
};

static struct nand_ecclayout XTX_OOB_XT26G02D = {
	.eccbytes = 64,
	.eccpos = {
		64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,
		80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,
		96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
	   112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127},
	.oobavail = 63,
	.oobfree = {
		{.offset = 1,
		    .length = 63},
	}
};

static struct nand_ecclayout HY_OOB_HYF1GQ4UDACAE = {
	.eccbytes = 32,
	.eccpos = {
		8, 9, 10, 11, 12, 13, 14, 15,
		24, 25, 26, 27, 28, 29, 30, 31,
		40, 41, 42, 43, 44, 45, 46, 47,
		56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 16,
	.oobfree = {
	{.offset = 4,
            .length = 4},
        {.offset = 20,
            .length = 4},
        {.offset = 36,
            .length = 4},
        {.offset = 52,
            .length = 4},
	}
};

static struct nand_ecclayout
        MICRON_OOB_MT29F1G01ABAFDWB = { .eccbytes = 64,
	                                .eccpos = { 64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,
	                                            77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,  88,  89,
	                                            90,  91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102,
	                                            103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
	                                            116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127 },
	                                /* Although 59 bytes are available, the first 27 bytes are not
	 								 * ECC-protected. Avoid storing data in that region by applying an offset.
									 */
	                                .oobavail = 32,
	                                .oobfree = {
	                                        { .offset = 32, .length = 32 },
	                                } };

struct nand_ecc_info nand_flash_list[] = {
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N512GV", 3, NAND_MFR_WINBOND, 0xAA, 0x20, 64, 4, 8,
	                     &WINBOND_OOB_W25N512GV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N01GV", 3, NAND_MFR_WINBOND, 0xAA, 0x21, 64, 4, 8, &WINBOND_OOB_W25N01GV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N01GW", 3, NAND_MFR_WINBOND, 0xBA, 0x21, 64, 4, 8, &WINBOND_OOB_W25N01GW),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N01KV", 3, NAND_MFR_WINBOND, 0xAE, 0x21, 64, 4, 8, &WINBOND_OOB_W25N01KV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N02KV", 3, NAND_MFR_WINBOND, 0xAA, 0x22, 128, 4, 13,
	                     &WINBOND_OOB_W25N02KV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N04KV", 3, NAND_MFR_WINBOND, 0xAA, 0x23, 128, 4, 13,
	                     &WINBOND_OOB_W25N04KV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N02LV", 3, NAND_MFR_WINBOND, 0x8A, 0x22, 128, 4, 13, &WINBOND_OOB_W25N02LV),					 
	AUGENTIX_ECC_SPINAND("MXIC_OOB_MX35LF1GE4AB", 2, NAND_MFR_MACRONIX, 0x12, 0x00, 64, 4, 8,
	                     &MXIC_OOB_MX35LF1GE4AB),
	AUGENTIX_ECC_SPINAND("MXIC_OOB_MX35LF2GE4AD", 3, NAND_MFR_MACRONIX, 0x26, 0x03, 64, 4, 8,
	                     &MXIC_OOB_MX35LF2GE4AD),
	AUGENTIX_ECC_SPINAND("ETRON_OOB_EM73C044SNA_G", 2, NAND_MFR_ETRON, 0x19, 0x00, 64, 4, 14,
	                     &ETRON_OOB_EM73C044SNA_G),
	AUGENTIX_ECC_SPINAND("ETRON_OOB_EM73C044SNB_G", 2, NAND_MFR_ETRON, 0x11, 0x00, 128, 4, 14,
	                     &ETRON_OOB_EM73C044SNB_G),
	AUGENTIX_ECC_SPINAND("ETRON_OOB_EM73C044SNF_G", 2, NAND_MFR_ETRON, 0x09, 0x00, 128, 4, 14,
	                     &ETRON_OOB_EM73C044SNF_G),
	AUGENTIX_ECC_SPINAND("ETRON_OOB_EM73D044VCO_H", 2, NAND_MFR_ETRON, 0x3A, 0x00, 128, 4, 14,
	                     &ETRON_OOB_EM73D044VCO_H),
	AUGENTIX_ECC_SPINAND("ETRON_OOB_EM73B044VCA_H", 2, NAND_MFR_ETRON, 0x01, 0x00, 64, 4, 8,
	                     &ETRON_OOB_EM73B044VCA_H),
	AUGENTIX_ECC_SPINAND("ETRON_OOB_EM73C044VCD_H", 2, NAND_MFR_ETRON, 0x1C, 0x00, 64, 4, 8,
	                     &ETRON_OOB_EM73C044VCD_H),
	AUGENTIX_ECC_SPINAND("ETRON_OOB_EM73C044VCF_H", 2, NAND_MFR_ETRON, 0x25, 0x00, 64, 4, 8,
	                     &ETRON_OOB_EM73C044VCF_H),
	AUGENTIX_ECC_SPINAND("GD_OOB_GD5F1GQ4U", 2, NAND_MFR_GD, 0xD1, 0x00, 128, 4, 16, &GD_OOB_GD5FxxQ4U),
	AUGENTIX_ECC_SPINAND("GD_OOB_GD5F2GQ4U", 2, NAND_MFR_GD, 0xD2, 0x00, 128, 4, 16, &GD_OOB_GD5FxxQ4U),
	AUGENTIX_ECC_SPINAND("GD_OOB_GD5F2GQ5U", 2, NAND_MFR_GD, 0x32, 0x00, 64, 4, 8, &GD_OOB_GD5FxxQ5U),
	AUGENTIX_ECC_SPINAND("GD_OOB_GD5F2GQ5UYIG", 2, NAND_MFR_GD, 0x52, 0x00, 64, 4, 8, &GD_OOB_GD5F2GQ5UYIG),
	AUGENTIX_ECC_SPINAND("GD_OOB_GD5F2GM7UEYIGR", 2, NAND_MFR_GD, 0x92, 0x00, 128, 4, 16, &GD_OOB_GD5F2GM7UEYIGR),
	AUGENTIX_ECC_SPINAND("GD_OOB_GD5F1GM7UE", 2, NAND_MFR_GD, 0x91, 0x00, 128, 4, 16, &GD_OOB_GD5F1GM7UE),
	AUGENTIX_ECC_SPINAND("ESMT_OOB_F50L1G41LB", 2, NAND_MFR_ESMT, 0x01, 0x00, 64, 4, 8, &ESMT_OOB_F50L1G41LB),
	AUGENTIX_ECC_SPINAND("MICRON_OOB_MT29F2G01ABA", 2, NAND_MFR_MICRON, 0x24, 0x00, 128, 4, 16,
	                     &MICRON_OOB_MT29F2G01ABA),
	AUGENTIX_ECC_SPINAND("KIOXIA_OOB_TC58CVG0S3HRAIJ", 3, NAND_MFR_TOSHIBA, 0xE2, 0x40, 128, 4, 16,
	                     &KIOXIA_OOB_TC58CVG0S3HRAIJ),
	AUGENTIX_ECC_SPINAND("KIOXIA_OOB_TC58CVG1S3HRAIJ", 3, NAND_MFR_TOSHIBA, 0xEB, 0x40, 128, 4, 16,
	                     &KIOXIA_OOB_TC58CVG1S3HRAIJ),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G01AWSEGA", 2, NAND_MFR_XTX, 0xE1, 0x00, 64, 4, 4, &XTX_OOB_XT26G01AWSEGA),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G01C", 2, NAND_MFR_XTX, 0x11, 0x00, 116, 4, 13, &XTX_OOB_XT26G01C),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G01D", 2, NAND_MFR_XTX, 0x31, 0x00, 128, 4, 16, &XTX_OOB_XT26G01D),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G02C", 2, NAND_MFR_XTX, 0x12, 0x00, 116, 4, 13, &XTX_OOB_XT26G02C),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G02D", 2, NAND_MFR_XTX, 0x32, 0x00, 128, 4, 16, &XTX_OOB_XT26G02D),
	AUGENTIX_ECC_SPINAND("HY_OOB_HYF1GQ4UDACAE", 2, NAND_MFR_HY, 0x21, 0x00, 64, 4, 8, &HY_OOB_HYF1GQ4UDACAE),
	AUGENTIX_ECC_SPINAND("MICRON_OOB_MT29F1G01ABAFDWB", 2, NAND_MFR_MICRON, 0x14, 0x00, 64, 4, 8,
	                     &MICRON_OOB_MT29F1G01ABAFDWB),
	{ NULL }
};

struct nand_ecc_info *get_ecc_info(u8 id0, u8 id1, u8 id2)
{
	struct nand_ecc_info *info;

	info = nand_flash_list;

	for (; info->name != NULL; info++) {
		if (info->id_len == 3 && info->flash_id[0] == id0 && info->flash_id[1] == id1 &&
		    info->flash_id[2] == id2) {
			return info;
		} else if (info->id_len == 2 && info->flash_id[0] == id0 && info->flash_id[1] == id1) {
			return info;
		}
	}

	return 0;
}

static int spinand_cmd(struct spi_slave *slave, struct spinand_cmd *cmd)
{
	u32 flags = 0;
	u8 dummy = 0xff;
	u32 addr_l = (cmd->n_addr << 1) & 0xFF;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	u32 wait_l = (cmd->n_dummy > 0) ? (cmd->n_dummy << 3) & 0xFF : 0;
#else
	u32 wait_l = (cmd->n_dummy > 0) ? ((cmd->n_dummy << 3) - 1) & 0xFF : 0;
#endif

	//slave->bits_per_word = 8;
	slave->dma_mode = 0;
	slave->frame_format = AGTX_QSPI_FRF__SSPI;
	slave->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	slave->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                  (wait_l << AGTX_QSPI_WAIT_L_OFFSET);

	if (cmd->n_rx) {
		slave->tmode = AGTX_SPI_TMOD_RO;
		slave->ndf = (cmd->n_rx) >> AGTX_QSPI_FRF__SSPI;
	} else {
		slave->tmode = AGTX_SPI_TMOD_TO;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		slave->ndf = (cmd->n_tx) >> AGTX_QSPI_FRF__SSPI;
#else
		slave->ndfw = (cmd->n_tx) >> AGTX_QSPI_FRF__SSPI;
#endif
	}

	spi_claim_bus(slave);

	/* CMD */
	slave->bits_per_word = 8;
	flags = (cmd->n_addr || cmd->n_dummy || cmd->n_tx || cmd->n_rx) ? SPI_XFER_BEGIN : 0;
	spi_xfer(slave, 1, &cmd->cmd, NULL, flags);

	/* ADDR */
	if (cmd->n_addr) {
		if (cmd->n_addr == 3) {
			slave->bits_per_word = 32;
		} else if (cmd->n_addr == 2) {
			slave->bits_per_word = 16;
		} else {
			slave->bits_per_word = 8;
		}
		flags = (cmd->n_dummy || cmd->n_tx || cmd->n_rx) ? SPI_XFER_BEGIN : 0;
		spi_xfer(slave, 1, cmd->addr, NULL, flags);
	}

	/* DUMMY */
	if (cmd->n_dummy) {
		slave->bits_per_word = 8;
		flags = (cmd->n_tx || cmd->n_rx) ? SPI_XFER_BEGIN : 0;
		spi_xfer(slave, cmd->n_dummy, &dummy, NULL, flags);
	}

	/* TX */
	if (cmd->n_tx) {
		slave->bits_per_word = cmd->bDFS_32 ? 32 : 8;
		spi_xfer(slave, cmd->n_tx, cmd->tx_buf, NULL, 0);
	}

	/* RX */
	if (cmd->n_rx) {
		slave->bits_per_word = cmd->bDFS_32 ? 32 : 8;
		spi_xfer(slave, cmd->n_rx, NULL, cmd->rx_buf, 0);
	}

	return 0;
}

static int qspinand_cmd(struct spi_slave *slave, struct spinand_cmd *cmd)
{
	u32 flags = 0;
	u8 dummy = 0xff;
	u32 addr_l = (cmd->n_addr << 1) & 0xFF;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	u32 wait_l = (cmd->n_dummy > 0) ? (cmd->n_dummy << 3) & 0xFF : 0;
#else
	u32 wait_l = (cmd->n_dummy > 0) ? ((cmd->n_dummy << 3) - 1) & 0xFF : 0;
#endif
	u8 agtx_qspi_frf = AGTX_QSPI_FRF__SSPI;

	if ((cmd->cmd == CMD_READ_QRDM) || (cmd->cmd == CMD_PROG_PAGE_QUAD_CLRCACHE) ||
	    (cmd->cmd == CMD_PROG_PAGE_QUAD)) {
		agtx_qspi_frf = AGTX_QSPI_FRF__QSPI;
	} else if (cmd->cmd == CMD_READ_DRDM) {
		agtx_qspi_frf = AGTX_QSPI_FRF__DSPI;
	} else if ((cmd->cmd == CMD_READ_RDM) || (cmd->cmd == CMD_PROG_PAGE_CLRCACHE) || (cmd->cmd == CMD_PROG_PAGE)) {
		agtx_qspi_frf = AGTX_QSPI_FRF__SSPI;
	}

	//slave->bits_per_word = 32;
	slave->dma_mode = 1;
	slave->frame_format = agtx_qspi_frf;
	slave->data_frame_size = AGTX_QSPI_DFS__32_BIT;
	slave->inst_set = (AGTX_QSPI_INST_L__8_BIT << AGTX_QSPI_INST_L_OFFSET) | (addr_l << AGTX_QSPI_ADDR_L_OFFSET) |
	                  (wait_l << AGTX_QSPI_WAIT_L_OFFSET);

	if (cmd->n_rx) {
		slave->tmode = AGTX_SPI_TMOD_RO;
		slave->ndf = (cmd->n_rx) >> agtx_qspi_frf;
	} else {
		slave->tmode = AGTX_SPI_TMOD_TO;
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		slave->ndf = (cmd->n_tx) >> agtx_qspi_frf;
#else
		slave->ndfw = (cmd->n_tx) >> agtx_qspi_frf;
#endif
	}

	spi_claim_bus(slave);

	/*CMD*/
	slave->bits_per_word = 8;
	flags = (cmd->n_addr || cmd->n_dummy || cmd->n_tx || cmd->n_rx) ? SPI_XFER_BEGIN : 0;
	spi_xfer(slave, 1, &cmd->cmd, NULL, flags);

	/*ADDR*/
	if (cmd->n_addr) {
		slave->bits_per_word = 16;
		flags = (cmd->n_dummy || cmd->n_tx || cmd->n_rx) ? SPI_XFER_BEGIN : 0;
		spi_xfer(slave, 1, cmd->addr, NULL, flags);
	}

	/*DUMMY*/
	if (cmd->n_dummy) {
		slave->bits_per_word = 8;
		flags = (cmd->n_tx || cmd->n_rx) ? SPI_XFER_BEGIN : 0;
		spi_xfer(slave, cmd->n_dummy, &dummy, NULL, flags);
	}

	/* TX */
	if (cmd->n_tx) {
		slave->bits_per_word = cmd->bDFS_32 ? 32 : 8;
		spi_xfer(slave, cmd->n_tx, cmd->tx_buf, NULL, 0);
	}

	/* RX */
	if (cmd->n_rx) {
		slave->bits_per_word = cmd->bDFS_32 ? 32 : 8;
		spi_xfer(slave, cmd->n_rx, NULL, cmd->rx_buf, 0);
	}

	return 0;
}

/*
 * spinand_id_has_period - Check if an ID string has a given wraparound period
 * @id_data: the ID string
 * @arrlen: the length of the @id_data array
 * @period: the period of repitition
 *
 * Check if an ID string is repeated within a given sequence of bytes at
 * specific repetition interval period (e.g., {0x20,0x01,0x7F,0x20} has a
 * period of 3). This is a helper function for nand_id_len(). Returns non-zero
 * if the repetition has a period of @period; otherwise, returns zero.
 */
static int spinand_id_has_period(u8 *id_data, int arrlen, int period)
{
	int i, j;
	for (i = 0; i < period; i++)
		for (j = i + period; j < arrlen; j += period)
			if (id_data[i] != id_data[j])
				return 0;
	return 1;
}

/*
 * spinand_id_len - Get the length of an ID string returned by CMD_READID
 * @id_data: the ID string
 * @arrlen: the length of the @id_data array

 * Returns the length of the ID string, according to known wraparound/trailing
 * zero patterns. If no pattern exists, returns the length of the array.
 */
static int spinand_id_len(u8 *id_data, int arrlen)
{
	int last_nonzero, period;

	/* Find last non-zero byte */
	for (last_nonzero = arrlen - 1; last_nonzero >= 0; last_nonzero--)
		if (id_data[last_nonzero])
			break;

	/* All zeros */
	if (last_nonzero < 0)
		return 0;

	/* Filter JEDEC Maker Code Continuation Code, 7Fh */
	if (id_data[0] == 0xC8 && id_data[1] == 0x01) {
		arrlen = 2;
		return arrlen;
	}

	/* Calculate wraparound period */
	for (period = 1; period < arrlen; period++)
		if (spinand_id_has_period(id_data, arrlen, period))
			break;

	/* There's a repeated pattern */
	if (period < arrlen)
		return period;

	/* There are trailing zeros */
	if (last_nonzero < arrlen - 1)
		return last_nonzero + 1;

	/* No pattern detected */
	return arrlen;
}

static int spinand_read_id(struct spi_slave *slave, u8 *id)
{
	int retval;
	u32 nand_id[1] = { 0 };
	struct spinand_cmd cmd = { 0 };
	int i, id_len = 0;

	cmd.cmd = CMD_READ_ID;
	cmd.n_addr = 1;
	cmd.addr[0] = 0x00;
	cmd.n_rx = 4;
	cmd.rx_buf = (u8 *)&nand_id[0];

	retval = spinand_cmd(slave, &cmd);
	if (retval < 0) {
		printf("err: %d reading id\n", retval);
		return retval;
	}

	id_len = spinand_id_len((u8 *)nand_id, 4);
	for (i = 0; i < id_len; i++) {
		id[i] = nand_id[0] & 0xff;
		nand_id[0] = nand_id[0] >> 8;
	}

	return retval;
}

static int spinand_read_status(struct spi_slave *slave, u8 *status)
{
	struct spinand_cmd cmd = { 0 };
	int ret;

	cmd.cmd = CMD_READ_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_STATUS;
	cmd.n_rx = 1;
	cmd.rx_buf = status;

	ret = spinand_cmd(slave, &cmd);
	if (ret < 0)
		printf("err: %d read status register\n", ret);

	return ret;
}

static int spinand_get_otp(struct spi_slave *slave, u8 *otp)
{
	struct spinand_cmd cmd = { 0 };
	int retval;

	cmd.cmd = CMD_READ_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_OTP;
	cmd.n_rx = 1;
	cmd.rx_buf = otp;

	retval = spinand_cmd(slave, &cmd);
	if (retval < 0) {
		printf("error %d get otp\n", retval);
		return retval;
	}

	return retval;
}

static int spinand_set_otp(struct spi_slave *slave, u8 *otp)
{
	int retval;
	struct spinand_cmd cmd = { 0 };

	cmd.cmd = CMD_WRITE_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_OTP;
	cmd.n_tx = 1;
	cmd.tx_buf = otp;

	retval = spinand_cmd(slave, &cmd);
	if (retval < 0)
		printf("error %d set otp\n", retval);

	return retval;
}
#if 0
static int spinand_get_blk_lock(struct spi_slave *slave, u8 *lock)
{
	struct spinand_cmd cmd = {0};
	int retval;

	cmd.cmd = CMD_READ_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_BLOCK_LOCK;
	cmd.n_rx = 1;
	cmd.rx_buf = lock;

	retval = spinand_cmd(slave, &cmd);
	if (retval < 0){
		printf("error %d get blk lock\n", retval);
		return retval;
	}

	return retval;
}
#endif
static int spinand_set_blk_lock(struct spi_slave *slave, u8 *lock)
{
	int retval;
	struct spinand_cmd cmd = { 0 };

	cmd.cmd = CMD_WRITE_REG;
	cmd.n_addr = 1;
	cmd.addr[0] = REG_BLOCK_LOCK;
	cmd.n_tx = 1;
	cmd.tx_buf = lock;

	retval = spinand_cmd(slave, &cmd);
	if (retval < 0)
		printf("error %d set blk lock\n", retval);

	return retval;
}

static int spinand_set_quad_mode(struct spi_slave *slave)
{
	int retval = 0;
	u8 otp = 0;

	spinand_get_otp(slave, &otp);
	otp |= 0x1; // bits 0: QE
	spinand_set_otp(slave, &otp);

	return retval;
}

/**
 * spinand_write_enable- send command 0x06 to enable write or erase the
 * Nand cells
 * Description:
 *   Before write and erase the Nand cells, the write enable has to be set.
 *   After the write or erase, the write enable bit is automatically
 *   cleared (status register bit 2)
 *   Set the bit 2 of the status register has the same effect
 */
static int spinand_write_enable(struct spi_slave *slave)
{
	struct spinand_cmd cmd = { 0 };

	cmd.cmd = CMD_WR_ENABLE;
	return spinand_cmd(slave, &cmd);
}

static int spinand_read_page_to_cache(struct spi_slave *slave, u32 page_id)
{
	struct spinand_cmd cmd = { 0 };
	u32 row;

	row = page_id;
	cmd.cmd = CMD_READ;
	cmd.n_addr = 3;
	cmd.addr[0] = (u8)((row & 0x000000ff) >> 0);
	cmd.addr[1] = (u8)((row & 0x0000ff00) >> 8);
	cmd.addr[2] = (u8)((row & 0x00ff0000) >> 16);

	return spinand_cmd(slave, &cmd);
}

static int wait_till_ready(struct spi_slave *slave)
{
	int retval;
	u8 stat = 0;
	int i = 0;

	for (i = 0; i < NAND_CMD_TIMEOUT_MS * 1000; i++) {
		retval = spinand_read_status(slave, &stat);
		if (retval < 0)
			return -1;
		else if (!(stat & 0x1))
			break;

		udelay(1);
	}

	if ((stat & 0x1) == 0)
		return 0;

	return -1;
}
#ifdef SUPPORT_HW_ECC
static int spinand_write_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip, const uint8_t *buf, int oob_required)
{
	const uint8_t *p = buf;
	int eccsize = chip->ecc.size;
	int eccsteps = chip->ecc.steps;

	chip->write_buf(mtd, p, eccsize * eccsteps);
	return 0;
}

static int spinand_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip, uint8_t *buf, int oob_required,
                                   int page)
{
	u8 retval = 0, status;
	uint8_t *p = buf;
	int eccsize = chip->ecc.size;
	int eccsteps = chip->ecc.steps;
	struct hc_qspi_nand *info = get_hc_qspi_nand(mtd);

	chip->read_buf(mtd, p, eccsize * eccsteps);
	if (oob_required)
		chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);

	while (1) {
		retval = spinand_read_status(info->slave, &status);
		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_ECC_MASK) == STATUS_ECC_ERROR) {
				printf("spinand: ECC error\n");
				mtd->ecc_stats.failed++;
			} else if ((status & STATUS_ECC_MASK) == STATUS_ECC_1BIT_CORRECTED)
				mtd->ecc_stats.corrected++;
			break;
		}
	}
	return retval;
}
#endif

/*
 * spinand_reset- send RESET command "0xff" to the Nand device.
 */
static void spinand_reset(struct spi_slave *slave)
{
	struct spinand_cmd cmd = { 0 };

	cmd.cmd = CMD_RESET;

	if (spinand_cmd(slave, &cmd) < 0)
		printf("spinand reset failed!\n");

	/* elapse 1ms before issuing any other command */
	udelay(1000);

	if (wait_till_ready(slave))
		printf("wait timedout!\n");
}

static int spinand_flash_init(struct spi_slave *slave)
{
	u8 lock = 0;
	u8 otp = 0x18; // bits 4: ECC_EN, bits 3: BUF (Winbond), bits 0: QE
	spinand_set_blk_lock(slave, &lock);
	spinand_set_otp(slave, &otp);

	return 0;
}
static int spinand_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
	u8 status, state = chip->state;
	unsigned long timeo = (state == FL_ERASING ? 400 : 20);
	struct hc_qspi_nand *info = get_hc_qspi_nand(mtd);

	/*
	 * Apply this short delay always to ensure that we do wait tWB in any
	 * case on any machine.
	 */
	ndelay(100);

	u32 timer = (CONFIG_SYS_HZ * timeo) / 1000;
	u32 time_start;

	time_start = get_timer(0);
	while (get_timer(time_start) < timer) {
		spinand_read_status(info->slave, &status);
		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			return 0;
		}
		udelay(10);
	}

	return -1;
}

#if 0
static int spinand_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
	struct spinand_info *info = (struct spinand_info *)chip->priv;

	unsigned long timeo = jiffies;
	int retval, state = chip->state;
	u8 status;

	if (state == FL_ERASING)
		timeo += (HZ * 400) / 1000;
	else
		timeo += (HZ * 20) / 1000;

	while (time_before(jiffies, timeo)) {
		retval = spinand_read_status(info->spi, &status);
		if ((status & STATUS_OIP_MASK) == STATUS_READY)
			return 0;

		cond_resched();
	}
	return 0;
}
#endif

/*
 * spinand_read_from_cache- send command 0x03 to read out the data from the
 * cache register(2112 bytes max)
 * Description:
 *   The read can specify 1 to 2112 bytes of data read at the corresponding
 *   locations.
 *   No tRd delay.
 */
static int spinand_read_from_cache(struct spi_slave *slave, u32 page_id, u32 byte_id, u32 len, u8 *rbuf)
{
	int ret = 0;
	u32 column = byte_id;
	u32 rx_bytes = 0;
	int trans_bytes = len;
	u8 r_cmd = CMD_READ_RDM;
	u8 set_bDFS = 0;

	if (slave->read_cmd == CMD_READ_QRDM) {
		r_cmd = CMD_READ_QRDM;
		set_bDFS = 1;
	} else if (slave->read_cmd == CMD_READ_DRDM) {
		r_cmd = CMD_READ_DRDM;
	}

	while (trans_bytes > 0) {
		struct spinand_cmd cmd = { 0 };
		rx_bytes = (trans_bytes > 512) ? 512 : trans_bytes;

		cmd.cmd = r_cmd;
		cmd.n_addr = 2; //NADDR_RAED_QRDM
		cmd.addr[0] = (u8)((column & 0x00ff) >> 0);
		cmd.addr[1] = (u8)((column & 0xff00) >> 8);
		cmd.n_dummy = 1; //NDUMMY_READ_QRDM
		cmd.n_rx = rx_bytes;
		cmd.rx_buf = rbuf; //DRAM address
		cmd.bDFS_32 = set_bDFS;
		ret = qspinand_cmd(slave, &cmd);
		if (ret)
			return ret;

		column = column + rx_bytes;
		rbuf = rbuf + rx_bytes;
		trans_bytes = trans_bytes - rx_bytes;
	}

	return 0;
}

/*
 * spinand_read_page-to read a page with:
 * @page_id: the physical page number
 * @offset:  the location from 0 to 2111
 * @len:     number of bytes to read
 * @rbuf:    read buffer to hold @len bytes
 *
 * Description:
 *   The read includes two commands to the Nand: 0x13 and 0x03 commands
 *   Poll to read status to wait for tRD time.
 */
static int spinand_read_page(struct spi_slave *slave, u32 page_id, u32 offset, u32 len, u8 *rbuf)
{
	int ret;
	u8 status = 0;

	ret = spinand_read_page_to_cache(slave, page_id);
	if (ret < 0)
		return ret;

	if (wait_till_ready(slave))
		printf("WAIT timedout!!!\n");

	while (1) {
		ret = spinand_read_status(slave, &status);
		if (ret < 0) {
			printf("err %d read status register\n", ret);
			return ret;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if (offset == OOB_OFFSET)
				break;

			if ((status & STATUS_ECC_MASK) == STATUS_ECC_ERROR) {
				printf("ecc error, page=%d\n", page_id);
				//don't return here, This function is called to read OOB
				//Finish the reading, thus mtd layer can get correct OOB info
				//return 0;
			}
			break;
		}
	}

	ret = spinand_read_from_cache(slave, page_id, offset, len, rbuf);
	if (ret < 0) {
		printf("read from cache failed!!\n");
		return ret;
	}
	return ret;
}

static int spinand_program_data_to_cache(struct spi_slave *slave, u32 page_id, u32 byte_id, u32 len, u8 *wbuf)
{
	int ret = 0;
	u8 bIsfisrt = 1;
	u32 column = byte_id;
	u32 tx_bytes = 0;
	int trans_bytes = len;
	u8 w_cmd_clr = 0x02, w_cmd = 0x84;
	u8 set_bDFS = 0;

	if (slave->write_cmd == AGTX_QUAD_WRITE) {
		w_cmd_clr = 0x32;
		w_cmd = 0x34;
		set_bDFS = 1;
	}

	if (trans_bytes % 4 != 0)
		trans_bytes += (4 - (trans_bytes % 4));

	while (trans_bytes > 0) {
		struct spinand_cmd cmd = { 0 };
		tx_bytes = (trans_bytes > 256) ? 256 : trans_bytes;

		cmd.cmd = bIsfisrt ? w_cmd_clr : w_cmd;
		cmd.n_addr = 2;
		cmd.addr[0] = (u8)(column & 0x00ff);
		cmd.addr[1] = (u8)((column & 0xff00) >> 8);
		cmd.n_tx = tx_bytes;
		if (byte_id == 2048)
			cmd.tx_buf = wbuf + column;
		else
			cmd.tx_buf = wbuf;
		cmd.bDFS_32 = set_bDFS;
		ret = qspinand_cmd(slave, &cmd);
		if (ret)
			return ret;

		column = column + tx_bytes;
		wbuf = wbuf + tx_bytes;
		trans_bytes = trans_bytes - tx_bytes;
		bIsfisrt = 0;
	}

	return 0; //qspinand_cmd(spi_nand, &cmd);
}

/**
 * spinand_program_execute--to write a page from cache to the Nand array with
 * @page_id: the physical page location to write the page.
 *
 * Description:
 *   The write command used here is 0x10--indicating the cache is writing to
 *   the Nand array.
 *   Need to wait for tPROG time to finish the transaction.
 */
static int spinand_program_execute(struct spi_slave *slave, u32 page_id)
{
	struct spinand_cmd cmd = { 0 };
	u32 row;

	row = page_id;
	cmd.cmd = CMD_PROG_PAGE_EXC;
	cmd.n_addr = 3;
	cmd.addr[2] = (u8)((row & 0x00ff0000) >> 16);
	cmd.addr[1] = (u8)((row & 0x0000ff00) >> 8);
	cmd.addr[0] = (u8)((row & 0x000000ff) >> 0);

	return spinand_cmd(slave, &cmd);
}

/**
 * spinand_program_page--to write a page with:
 * @page_id: the physical page location to write the page.
 * @offset:  the location from the cache starting from 0 to 2111
 * @len:     the number of bytes to write
 * @wbuf:    the buffer to hold the number of bytes
 *
 * Description:
 *   The commands used here are 0x06, 0x84, and 0x10--indicating that
 *   the write enable is first sent, the write cache command, and the
 *   write execute command.
 *   Poll to wait for the tPROG time to finish the transaction.
 */
static int spinand_program_page(struct spi_slave *slave, u32 page_id, u32 offset, u32 len, u8 *buf)
{
	int retval;
	u8 status = 0;
	u8 *wbuf;
#ifdef SUPPORT_HW_ECC
	unsigned int i, j;

	wbuf = malloc(CACHE_BUF);
	spinand_read_page(slave, page_id, 0, CACHE_BUF, wbuf);
	//printf("page_id=%d len=%d offset= %d\n",page_id,len,offset);

	for (i = offset, j = 0; j < len; i++, j++) {
		wbuf[i] &= buf[j];
	}
#else
	wbuf = buf;
#endif

	//0x06
	retval = spinand_write_enable(slave);
	if (retval < 0) {
		printf("write enable failed!!\n");
		return retval;
	}

	if (wait_till_ready(slave))
		printf("wait timedout!!!\n");

	//0x02/0x82, 0x32/0x34
	retval = spinand_program_data_to_cache(slave, page_id, offset, len, wbuf);
	if (retval < 0)
		return retval;

	//0x10
	retval = spinand_program_execute(slave, page_id);
	if (retval < 0)
		return retval;

	while (1) {
		retval = spinand_read_status(slave, &status);
		if (retval < 0) {
			printf("error %d reading status register\n", retval);
			return retval;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_P_FAIL_MASK) == STATUS_P_FAIL) {
				printf("program error, page %d\n", page_id);
				return -1;
			}
			break;
		}
	}

#ifdef SUPPORT_HW_ECC
	free(wbuf);
#endif
	return 0;
}

/**
 * spinand_erase_block_erase--to erase a page with:
 * @block_id: the physical block location to erase.
 *
 * Description:
 *   The command used here is 0xd8--indicating an erase command to erase
 *   one block--64 pages
 *   Need to wait for tERS.
 */
static int spinand_erase_block_erase(struct spi_slave *slave, u32 block_id)
{
	struct spinand_cmd cmd = { 0 };
	u32 row;

	row = block_id;
	cmd.cmd = CMD_ERASE_BLK;
	cmd.n_addr = 3;
	cmd.addr[2] = (u8)((row & 0x00ff0000) >> 16);
	cmd.addr[1] = (u8)((row & 0x0000ff00) >> 8);
	cmd.addr[0] = (u8)((row & 0x000000ff) >> 0);

	return spinand_cmd(slave, &cmd);
}

/**
 * spinand_erase_block--to erase a page with:
 * @block_id: the physical block location to erase.
 *
 * Description:
 *   The commands used here are 0x06 and 0xd8--indicating an erase
 *   command to erase one block--64 pages
 *   It will first to enable the write enable bit (0x06 command),
 *   and then send the 0xd8 erase command
 *   Poll to wait for the tERS time to complete the tranaction.
 */
static int spinand_erase_block(struct spi_slave *slave, u32 block_id)
{
	int retval;
	u8 status = 0;

	retval = spinand_write_enable(slave);
	if (wait_till_ready(slave))
		printf("wait timedout!!!\n");

	retval = spinand_erase_block_erase(slave, block_id);
	while (1) {
		retval = spinand_read_status(slave, &status);
		if (retval < 0) {
			printf("error %d reading status register\n", (int)retval);
			return retval;
		}

		if ((status & STATUS_OIP_MASK) == STATUS_READY) {
			if ((status & STATUS_E_FAIL_MASK) == STATUS_E_FAIL) {
				printf("erase error, block %d\n", block_id);
				return -1;
			}
			break;
		}
	}
	return 0;
}

static int hc_qspi_nand_dev_ready(struct mtd_info *mtd)
{
	printf("[Nick] %s %s\n", __FILE__, __func__);

	return 1;
}

static void hc_qspi_nand_command(struct mtd_info *mtd, unsigned command, int column, int page)
{
	//printf("[CMD]0x%x column=%d, page=%d\n",command,column,page);
	struct hc_qspi_nand *info = get_hc_qspi_nand(mtd);

	switch (command) {
	case NAND_CMD_READ1:
	case NAND_CMD_READ0:
		info->buf_ptr = 0;
		spinand_read_page(info->slave, page, 0x0, 0x840, info->buf);
		break;
	case NAND_CMD_READOOB:
		info->buf_ptr = 0;
		spinand_read_page(info->slave, page, 0x800, 0x40, info->buf);
		break;
	case NAND_CMD_RNDOUT:
		info->buf_ptr = column;
		break;
	case NAND_CMD_READID:
		info->buf_ptr = 0;
		spinand_read_id(info->slave, (u8 *)info->buf);
		break;
	case NAND_CMD_PARAM:
		info->buf_ptr = 0;
		break;
	case NAND_CMD_ERASE1:
		//printf("[CMD]0x%x column=%d, page=%d\n",command,column,page);
		spinand_erase_block(info->slave, page);
		break;
	case NAND_CMD_PAGEPROG:
		//printf("[CMD]0x%x column=%d, page=%d\n",command,column,page);
		spinand_program_page(info->slave, info->row, info->col, info->buf_ptr, info->buf);
		break;
	case NAND_CMD_STATUS:
		spinand_get_otp(info->slave, info->buf);
		if (!(info->buf[0] & 0x80))
			info->buf[0] = 0x80;
		info->buf_ptr = 0;
		break;
	case NAND_CMD_RESET:
		if (wait_till_ready(info->slave))
			printf("WAIT timedout!!!\n");
		udelay(250);
		spinand_reset(info->slave);
		break;
	case NAND_CMD_SEQIN:
		//printf("[CMD]0x%x column=%d, page=%d\n",command,column,page);
		info->col = column;
		info->row = page;
		info->buf_ptr = 0;
		break;
	default:
		//printf("Unknown CMD: 0x%x\n", command);
		break;
	}
}

static uint8_t hc_qspi_nand_read_byte(struct mtd_info *mtd)
{
	struct hc_qspi_nand *info = get_hc_qspi_nand(mtd);
	u8 data;

	data = info->buf[info->buf_ptr];
	info->buf_ptr++;
	return data;
}

static u16 hc_qspi_nand_read_word(struct mtd_info *mtd)
{
	return 0;
}

static void hc_qspi_nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
	struct hc_qspi_nand *info = get_hc_qspi_nand(mtd);

	memcpy(buf, info->buf + info->buf_ptr, len);
	info->buf_ptr += len;
}

/* Write data to NFC buffers */
static void hc_qspi_nand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
	struct hc_qspi_nand *info = get_hc_qspi_nand(mtd);

	memcpy(info->buf + info->buf_ptr, buf, len);
	info->buf_ptr += len;
}

static void hc_qspi_nand_select_chip(struct mtd_info *mtd, int chip)
{
}

int qspi_nand_flash_init(void)
{
	struct mtd_info *mtd = &nand_info[0];
	struct nand_chip *chip;
	struct spi_slave *slave;
	struct hc_qspi_nand *qspi_nand;
	u8 flash_id[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	struct nand_ecc_info *ecc_info;
	int i = 0, err = 0, id_len = 0;

	qspi_nand = malloc(sizeof(*qspi_nand));
	if (!qspi_nand) {
		printf(KERN_ERR "%s: Memory exhausted!\n", __func__);
		return -ENOMEM;
	}

	chip = &qspi_nand->chip;
	mtd->priv = chip;
	chip->priv = qspi_nand;

	chip->dev_ready = hc_qspi_nand_dev_ready;
	chip->cmdfunc = hc_qspi_nand_command;
	chip->read_byte = hc_qspi_nand_read_byte;
	chip->read_word = hc_qspi_nand_read_word;
	chip->read_buf = hc_qspi_nand_read_buf;
	chip->write_buf = hc_qspi_nand_write_buf;
	chip->select_chip = hc_qspi_nand_select_chip;
	chip->waitfunc = spinand_wait;
	chip->write_page = NULL;
	chip->block_bad = NULL;
	chip->scan_bbt = NULL;
	chip->block_markbad = NULL;
	chip->bbt_options = NAND_BBT_USE_FLASH;
	chip->bbt = NULL;

	chip->options = 0;
	chip->options |= NAND_CACHEPRG | NAND_SKIP_BBTSCAN | NAND_NO_SUBPAGE_WRITE;

	chip->ecc.size = 2048;
	mtd->oobsize = 64;

	qspi_nand->buf_ptr = 0;
	qspi_nand->buf = malloc(BUFSIZE);
	if (!qspi_nand->buf) {
		return -ENOMEM;
	} else {
		memset(qspi_nand->buf, 0, BUFSIZE);
	}

	slave = spi_setup_slave(0, 0, 1000000, 0);
	if (!slave) {
		printf("Invalid device\n");
		return -EINVAL;
	}

	/* Default: Single read, Single write */
	slave->read_cmd = CMD_READ_RDM;
	slave->write_cmd = AGTX_SINGLE_WRITE;
	if (CONFIG_AGTX_QSPI_WIRES == 4) {
		slave->read_cmd = CMD_READ_QRDM;
		slave->write_cmd = AGTX_QUAD_WRITE;
	} else if (CONFIG_AGTX_QSPI_WIRES == 2) { // No Dual write, just set dual read
		slave->read_cmd = CMD_READ_DRDM;
	}

	spinand_flash_init(slave);
	if ((slave->read_cmd == CMD_READ_QRDM) || (slave->write_cmd == AGTX_QUAD_WRITE)) {
		spinand_set_quad_mode(slave);
	}

	qspi_nand->slave = slave;

	spinand_read_id(slave, flash_id);
	id_len = spinand_id_len(flash_id, 8);
	printf("Qspi Nand (ID:");
	for (i = 0; i < id_len; i++) {
		printf(" %02X", flash_id[i]);
	}
	printf(")\n");
	ecc_info = get_ecc_info(flash_id[0], flash_id[1], flash_id[2]);

#ifdef SUPPORT_HW_ECC
	chip->ecc.mode = NAND_ECC_HW;
	chip->ecc.size = 0x200;
	chip->ecc.steps = ecc_info->ecc_steps;
	chip->ecc.bytes = ecc_info->ecc_bytes;
	chip->ecc.layout = ecc_info->ecc_layout;
	chip->ecc.strength = 1;
	chip->ecc.total = chip->ecc.steps * chip->ecc.bytes;
	chip->ecc.read_page = spinand_read_page_hwecc;
	chip->ecc.write_page = spinand_write_page_hwecc;
	chip->ecc.read_page_raw = NULL;
	chip->ecc.write_page_raw = NULL;
	chip->ecc.hwctl = NULL;
	chip->ecc.write_oob = NULL;
	chip->ecc.read_oob = NULL;
#else
	chip->ecc.mode = NAND_ECC_SOFT;
#endif

	/* first scan to find the device and get the page size */
	if (nand_scan_ident(mtd, CONFIG_SYS_MAX_NAND_DEVICE, NULL)) {
		err = -ENXIO;
		printf("error: nand_scan_ident\n");
		goto error;
	}

	/* second phase scan */
	err = nand_scan_tail(mtd);
	if (err) {
		printf("error: nand_scan_tail\n");
		return err;
	}

	err = nand_register(0);
	if (err) {
		printf("error: nand_register\n");
		return err;
	}

	return 0;

error:
	return err;
}

void board_nand_init(void)
{
	/*spi_init();*/
	if (qspi_nand_flash_init()) {
		printf("error: nand_scan_tail\n");
	}
}
