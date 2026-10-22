/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_DA_DEFINE_H_
#define SAPPORO_DA_DEFINE_H_

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif /* __KERNEL__ */

#include "dram/hw_dram.h"
#include "csr_bank_darb.h"

/***** Depend on DRAM *****/
#define BITWIDTH_BANK (MIN_BITWIDTH_BANK + BANK_ADDR_TYPE)
#define BITWIDTH_ROW (MIN_BITWIDTH_ROW + ROW_ADDR_TYPE)
#define BITWIDTH_COL (MIN_BITWIDTH_COL + COL_ADDR_TYPE)
#define DRAM_BANK_NUM (1 << BITWIDTH_BANK)
#define DRAM_ROW_NUM (1 << BITWIDTH_ROW)
#define DRAM_COL_NUM (1 << BITWIDTH_COL)
#define DRAM_PAGE_SIZE DRAM_COL_NUM

/***** Depend on Chip (Hardware design) *****/
#define MAX_TILE_NUM (60)
#define MSB_BIT_NUM (8)
#define LSB_BIT_NUM (2)
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define DA_FIFO_WORD (64)
#define WORD_ADDR_BW (3) /* (DA_FIFO_WORD / 8) byte -> need 3 bit */
#elif defined(CONFIG_OSAKA)
#define DA_FIFO_WORD (128)
#define WORD_ADDR_BW (4) /* (DA_FIFO_WORD / 8) byte -> need 4 bit */
#endif
#define PPW_MSB (DA_FIFO_WORD / MSB_BIT_NUM) /* PPW: Pixel per word */
#define PPW_LSB (DA_FIFO_WORD / LSB_BIT_NUM)

/*
 * MV Word: 64bit, each MV: 24bit
 * +---------+---+-------+-------+---------+---+-------+-------+
 * |  63:53  | 52| 51:42 | 41:32 |  31:21  | 20| 19:10 |  9:0  |
 * +---------+---+-------+-------+---------+---+-------+-------+
 * |    0    |tmv|  mvy  |  mvx  |    0    |tmv|  mvy  |  mvx  |
 * +---------+---+-------+-------+---------+---+-------+-------+
 * |    0    |        mv1        |    0    |        mv0        |
 * +---------+-------------------+---------+-------------------+
 */
#ifdef CONFIG_OSAKA
#define MV_PER_WORD (4)
#else
#define MV_PER_WORD (2)
#endif

#define BLOCK_WIDTH (8)
#define BLOCK_HEIGHT (8)
#define MV_BLOCK_WIDTH (8)
#define MV_BLOCK_HEIGHT (8)
#define SUBBLOCK_WIDTH (8)
#define SUBBLOCK_HEIGHT (8)
#define MACRO_BLOCK_WIDTH (16)
#define MACRO_BLOCK_HEIGHT (16)
#define LCU32_WIDTH (32)
#define LCU32_HEIGHT (32)
#define SB_PER_MB (MACRO_BLOCK_WIDTH / SUBBLOCK_WIDTH)

/***** Depend on Application *****/
#define INI_ADDR_BANK_OFFSET (0) /* Start with which bank */

#define ISR_BIT_NUM (8) /* 8 or 10 bit */
#define ISW_BIT_NUM (8) /* 8 or 10 bit */
#define NRW_BIT_NUM (8) /* 8 or 10 bit */
#define SNAPSHOT_BIT_NUM (8) /* 8 or 10 bit */
#define SCW_BIT_NUM (8) /* 8 or 10 bit */

#define SEARCH_RANGE (128) /* for ME, MER */

#define DEFAULT_TARGET_BURST_LEN (16)

enum is_dram_agent_item {
	DRAM_AGENT_ISW = 0,
	DRAM_AGENT_ISW_LINEAR,
	DRAM_AGENT_ISR,
	DRAM_AGENT_IS_CCQR,
	DRAM_AGENT_IS_CCQW,
	DRAM_AGENT_IS_END,
};

/*
 * A single DA may have multiple items due to its specific purpose or
 * functionality. Please follow the naming convention:
 * DRAM_AGENT_<MODULE>_<PURPOSE>.
 */
enum isp_dram_agent_item {
	DRAM_AGENT_NRW = DRAM_AGENT_IS_END,
	DRAM_AGENT_MER,
	DRAM_AGENT_VENC_MVW,
	DRAM_AGENT_MV8W,
	DRAM_AGENT_MV8R,
	DRAM_AGENT_SCW, // VPW0 from SC
	DRAM_AGENT_SCW_10B,
	DRAM_AGENT_VPW, // VPW0 from B2R
	DRAM_AGENT_SNAPSHOT, // VPW1, default to Y-only
	DRAM_AGENT_YUV_SNAPSHOT, // YUV snapshot's setting is different than Y-only's
	DRAM_AGENT_ISPR8B,
	DRAM_AGENT_ISPR10B,
	DRAM_AGENT_ISPR16B,
	DRAM_AGENT_COORDR,
	DRAM_AGENT_ISP_CCQR,
	DRAM_AGENT_ISP_CCQW,
	DRAM_AGENT_VPW0_LINEAR,
	DRAM_AGENT_VPW1_LINEAR,
	DRAM_AGENT_YUV420D_8B,
	DRAM_AGENT_YUV420D_10B,
	DRAM_AGENT_YUV422,
	DRAM_AGENT_ISP_END,
};

enum enc_dram_agent_item {
	DRAM_AGENT_SRCR = DRAM_AGENT_ISP_END,
	DRAM_AGENT_REFW,
	DRAM_AGENT_REFR,
	DRAM_AGENT_MVR,
	DRAM_AGENT_BSW,
	DRAM_AGENT_OSDR,
	DRAM_AGENT_ENC_END,
};

/* Embedded compression mode */
typedef enum {
	EC_OFF = 0,
	EC_SC, /* Scaling mode */
	EC_RD_64x11, /* Rounding mode 0 */
	EC_RD_64x10, /*  Rounding mode 1 */
	EC_RD_64x9, /* Rounding mode 2 */
	EC_NUM, /* The max numbers of embedded compression mode. */
} EcMode;

#define DRAM_AGENT_IS_NUM DRAM_AGENT_IS_END
#define DRAM_AGENT_ISP_NUM (DRAM_AGENT_ISP_END - DRAM_AGENT_IS_END)
#define DRAM_AGENT_ENC_NUM (DRAM_AGENT_ENC_END - DRAM_AGENT_ISP_END)

typedef struct frame_info {
	uint16_t width;
	uint16_t height;
	uint8_t bit_depth;
} FrameInfo;

typedef struct tile_info {
	uint16_t first_x;
	uint16_t first_out_x;
	uint16_t last_out_x;
	uint16_t last_x;
	uint16_t tile_in_width;
	uint16_t tile_out_width;
} TileInfo;

/*
 * Some of the DA settings do not change throughout the entire frame (or
 * even the entire streaming session!). Therefore, we separate those
 * "frame-based" settings from the "tile-based" ones.
 */
typedef struct dram_agent_config {
	uint8_t type;
	/* DRAM setting */
	uint8_t col_addr_type;
	uint8_t bank_interleave_type;
	uint8_t bank_group_type;
	uint8_t phy_to_linear_shift;

	/* Efficiency setting */
	uint8_t target_burst_len;
	uint16_t target_fifo_level;
	uint16_t fifo_full_level;
	uint8_t access_end_sel;
	uint8_t allow_stall;

	/* Data format and package */
	uint8_t msb_only;
	uint8_t y_only; /* for pixel DA, this means y_only_e */
	uint8_t y_only_o;

	/* Block agent specific */
	uint8_t fifo_per_block;

	/* Pixel agent specific */
	uint8_t pixel_per_package;
	uint8_t pwe_prd_enable;
	uint8_t package_size;
	uint8_t package_size_last;
	uint8_t flip_mode;
	uint8_t mirror_mode;
	uint16_t crop_x;
	uint16_t crop_y;
	uint16_t crop_width;
	uint16_t crop_height;

	/* MER specific */
	uint8_t search_range;

#ifdef CONFIG_KAMO
	EcMode ec_mode;
#endif
} DramAgentConfig;

/*
 * These are the so-called "tile-based" settings. Since different types of
 * DA have slightly different CSRs, we create separate C struct for each
 * type. Note that it is possible to combine these separate C struct into a
 * single, more general "tile-based" struct.
 */
typedef struct da_pixel_tile {
	uint16_t width;
#if defined(CONFIG_SAPPORO)
	uint16_t h_start_0;
	uint16_t h_end_0;
#elif defined(CONFIG_KAMO)
	uint16_t h_start;
	uint16_t h_end;
#endif
	uint16_t fifo_flush_len;
	uint16_t pixel_flush_len;
	uint16_t flush_addr_skip_e;
	uint16_t flush_addr_skip_o;

	uint8_t fifo_start_phase;
	uint8_t fifo_end_phase;
	uint8_t fifo_flush_len_last;

	uint32_t ini_addr_linear_e_add;
	uint32_t ini_addr_linear_o_add;
	uint8_t phy_to_linear_shift;
} DaPixelTile;

typedef struct da_block_tile {
	uint16_t width;
	uint16_t block_cnt_hor;
	uint32_t fifo_flush_len;
	uint32_t pixel_flush_len;
	uint32_t flush_addr_skip;

	uint32_t addr_add;
	uint8_t phy_to_linear_shift;

	uint16_t h_start;
	uint16_t h_end;
} DaBlockTile;

typedef struct da_linear_tile {
	uint16_t width;
	uint32_t pixel_flush_len;
	uint32_t fifo_flush_len;
	uint32_t flush_addr_skip;

	uint8_t fifo_start_phase;
	uint8_t fifo_end_phase;

	uint32_t addr_add;
	uint8_t phy_to_linear_shift;

	uint16_t h_start;
	uint16_t h_end;
} DaLinearTile;

typedef struct da_sample_tile {
	uint16_t width;
	uint32_t pixel_flush_len;
	uint32_t fifo_flush_len;
	uint32_t flush_addr_skip;

	uint8_t fifo_start_phase;

	uint32_t addr_add;
	uint8_t phy_to_linear_shift;

	uint16_t h_start;
	uint16_t h_end;
} DaSampleTile;

#endif /* SAPPORO_DA_DEFINE_H_ */
