#ifndef AGTX_VIDEO_DA_DEFINE_H_
#define AGTX_VIDEO_DA_DEFINE_H_
/************************************/
/* Temp dram agent define for kyoto */
/************************************/

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif
#include "hw_dram.h"

/**** Depend on DRAM ****/
#define BITWIDTH_BANK (BANK_ADDR_TYPE + 2)
#define BITWIDTH_COL (COL_ADDR_TYPE + 9)
#define DRAM_BANK_NUM (1 << BITWIDTH_BANK)
#define DRAM_ROW_NUM (1 << BITWIDTH_ROW)
#define DRAM_COL_NUM (1 << BITWIDTH_COL)
#define DRAM_PAGE_SIZE (1 << BITWIDTH_COL)

/**** Depend on Chip (Hardware design) ****/
#define MSB_BIT_NUM (8)
#define LSB_BIT_NUM (2)
#define DA_FIFO_WORD (64)
#define WORD_ADDR_BW (3) /* (DA_FIFO_WORD / 8) byte -> need 3 bit */
/* PPW: Pixel per Word */
#define MV_PER_WORD (2)
#define BLOCK_WIDTH (8)
#define BLOCK_HEIGHT (8)
#define MV_BLOCK_WIDTH (8)
#define MV_BLOCK_HEIGHT (8)
#define SUBBLOCK_WIDTH (8)
#define SUBBLOCK_HEIGHT (8)
#define MACRO_BLOCK_WIDTH (16)
#define MACRO_BLOCK_HEIGHT (16)
#define SB_PER_MB (MACRO_BLOCK_WIDTH / SUBBLOCK_WIDTH)
#define PPW_MSB (DA_FIFO_WORD / MSB_BIT_NUM)
#define PPW_LSB (DA_FIFO_WORD / LSB_BIT_NUM)
#define LCU32_WIDTH (32)
#define ME_FIXED_MVR_EXTEND_DIST (8)

#define SEARCH_RANGE (128) /* for ME, MER */

/**** Depend on Application ****/
#define INI_ADDR_BANK_OFFSET (0) /* Start with which bank */

enum earlyvideo_dram_agent_item {
	DRAM_AGENT_ISW = 0,
	DRAM_AGENT_ISPR, /* The DA config for ISPR of the first ISP pass */
	DRAM_AGENT_INTER, /* The DA config for VPW of the first ISP pass and ISPR of the second ISP pass */
	DRAM_AGENT_VPW, /* The DA config for VPW of the second ISP pass */
	DRAM_AGENT_NRW,
	DRAM_AGENT_MER,
	DRAM_AGENT_VENC_MVW,
	DRAM_AGENT_MV8W,
	DRAM_AGENT_MV8R,
	DRAM_AGENT_EARLYVIDEO_NUM,
};

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

typedef struct dram_agent_config {
	/* Depend on dram */
	uint8_t col_addr_type;
	uint8_t bank_interleave_type;
	uint8_t bank_group_type;
	/* Depend on bank_num, axi_word_addr_bw and bank_interleave_type */
	uint8_t phy_to_linear_shift;

	/* Depend on da type */
	uint8_t target_burst_len;
	uint16_t target_fifo_level;
	uint16_t fifo_full_level;
	uint8_t access_end_sel;
	uint8_t allow_stall;
	/* Depend on Application */
	uint8_t msb_only;
	uint8_t y_only;
	uint8_t y_only_o;
	uint8_t fifo_per_block; /* Depend on msb_only/y_only/msb/lsb */
	uint8_t pixel_per_package;
	uint8_t package_size;
	uint8_t package_size_last;
	uint8_t search_range;
} DramAgentConfig;

typedef struct da_pixel_tile {
	uint16_t width;
	uint16_t ini_addr_linear_o_add;
	uint32_t ini_addr_linear_e_add;
	uint16_t fifo_flush_len;
	uint16_t pixel_flush_len;
	uint16_t flush_addr_skip_e;
	uint16_t flush_addr_skip_o;
	uint8_t fifo_start_phase;
	uint8_t fifo_end_phase;
	uint8_t fifo_flush_len_last;
	uint8_t phy_to_linear_shift;
} DaPixelTile;

typedef struct da_block_tile {
	uint16_t width;
	uint16_t block_cnt_hor;
	uint32_t addr_add;
	uint32_t fifo_flush_len;
	uint32_t pixel_flush_len;
	uint32_t flush_addr_skip;
	uint8_t phy_to_linear_shift;
} DaBlockTile;

typedef struct da_linear_tile {
	uint16_t width;
	uint8_t fifo_start_phase;
	uint8_t fifo_end_phase;
	uint32_t addr_add;
	uint32_t pixel_flush_len;
	uint32_t fifo_flush_len;
	uint32_t flush_addr_skip;
	uint8_t phy_to_linear_shift;
} DaLinearTile;

#endif /* AGTX_VIDEO_DA_DEFINE_H_ */
