
#include <linux/version.h>

#include "augentix_nand_hw_ecc.h"

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

static struct nand_ecclayout XTX_OOB_XT26G01AWSEGA = {
	.eccbytes = 16,
	.eccpos = {
		48, 49, 50, 51, 52, 53, 54, 55,
        56, 57, 58, 59, 60, 61, 62, 63},
	.oobavail = 40,
	.oobfree = {
		{.offset = 8,
			.length = 40},
	}
};

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

static struct nand_ecclayout MICRON_OOB_MT29F1G01ABA = {
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

struct nand_ecc_info nand_flash_list[] = {

	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N512GV", 3, NAND_MFR_WINBOND, 0xAA, 0x20, 64, 4, 8,
	                     &WINBOND_OOB_W25N512GV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N01GV", 3, NAND_MFR_WINBOND, 0xAA, 0x21, 64, 4, 8, &WINBOND_OOB_W25N01GV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N01GW", 3, NAND_MFR_WINBOND, 0xBA, 0x21, 64, 4, 8, &WINBOND_OOB_W25N01GW),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N01GV", 3, NAND_MFR_WINBOND, 0xAE, 0x21, 64, 4, 8, &WINBOND_OOB_W25N01KV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N02KV", 3, NAND_MFR_WINBOND, 0xAA, 0x22, 128, 4, 13,
	                     &WINBOND_OOB_W25N02KV),
	AUGENTIX_ECC_SPINAND("WINBOND_OOB_W25N04KV", 3, NAND_MFR_WINBOND, 0xAA, 0x23, 128, 4, 13, &WINBOND_OOB_W25N04KV),
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
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G01AWSEGA", 2, NAND_MFR_XTX, 0xE1, 0x00, 64, 4, 4, &XTX_OOB_XT26G01AWSEGA),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G01C", 2, NAND_MFR_XTX, 0x11, 0x00, 116, 4, 13, &XTX_OOB_XT26G01C),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G01D", 2, NAND_MFR_XTX, 0x31, 0x00, 128, 4, 16, &XTX_OOB_XT26G01D),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G02C", 2, NAND_MFR_XTX, 0x12, 0x00, 116, 4, 13, &XTX_OOB_XT26G02C),
	AUGENTIX_ECC_SPINAND("XTX_OOB_XT26G02D", 2, NAND_MFR_XTX, 0x32, 0x00, 128, 4, 16, &XTX_OOB_XT26G02D),
	AUGENTIX_ECC_SPINAND("MICRON_OOB_MT29F1G01ABA", 2, NAND_MFR_MICRON, 0x14, 0x00, 128, 4, 16,
	                     &MICRON_OOB_MT29F1G01ABA),
	AUGENTIX_ECC_SPINAND("KIOXIA_OOB_TC58CVG0S3HRAIJ", 3, NAND_MFR_TOSHIBA, 0xE2, 0x40, 128, 4, 16,
	                     &KIOXIA_OOB_TC58CVG0S3HRAIJ),
	AUGENTIX_ECC_SPINAND("KIOXIA_OOB_TC58CVG1S3HRAIJ", 3, NAND_MFR_TOSHIBA, 0xEB, 0x40, 128, 4, 16,
	                     &KIOXIA_OOB_TC58CVG1S3HRAIJ),
	AUGENTIX_ECC_SPINAND("HY_OOB_HYF1GQ4UDACAE", 2, NAND_MFR_HY, 0x21, 0x00, 64, 4, 8, &HY_OOB_HYF1GQ4UDACAE),
	{ NULL }
};

struct nand_ecc_info* get_ecc_info(u8 id0, u8 id1, u8 id2){

	struct nand_ecc_info* info;

	info = nand_flash_list;

	for (; info->name != NULL; info++) {
			if( info->id_len == 3 && info->flash_id[0] == id0 &&
				info->flash_id[1] == id1 && info->flash_id[2] == id2 ){
				return info;
			}
			else if( info->id_len == 2 && info->flash_id[0] == id0 &&
					info->flash_id[1] == id1  )
			{
				return info;
			}
	}

	return 0;
}
