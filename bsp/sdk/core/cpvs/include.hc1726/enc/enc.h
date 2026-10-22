/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_ENCODER_H_
#define KYOTO_ENCODER_H_

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#include "printf.h"
#endif /* __KERNEL__ */

#include "da_define.h"
// #include "hw_dram.h"

#define u64 uint64_t
#define u32 uint32_t
#define s32 int
#define s16 short
#define u16 unsigned short
#define u8 uint8_t

#define MAX_GOP_SIZE 1024
#define MAX_BOUNDING_BOX 8
#define MAX_ROI_REGION 8
#define MAX_OSD_REGION 4
#define ENC_DRAM_AGENT_ENC_NUM 6

#define NUMBER_OF_MB_WIDTH(x) (((x) + (MACRO_BLOCK_WIDTH - 1)) / MACRO_BLOCK_WIDTH)
#define NUMBER_OF_MB_HEIGHT(x) (((x) + (MACRO_BLOCK_WIDTH - 1)) / MACRO_BLOCK_WIDTH)

#ifndef __KERNEL__
#if 1
#define enc_print(format, args...) printf("[%s:%d] " format, __func__, __LINE__, ##args)
#define enc_dump_print(format, args...) printf("[%s:%d] " format, __func__, __LINE__, ##args, ##args)
#else
#define enc_print(format, args...) ;
#define enc_dump_print(format, args...) ;
#endif
#endif /* __KERNEL__ */

typedef enum enc_codec {
	ENC_CODEC_H264 = 0,
	ENC_CODEC_H265,
	ENC_CODEC_MJPEG,
	ENC_CODEC_JPEG,
	ENC_CODEC_MAX,
} EncCodec;

typedef enum enc_seg_type {
	ENC_SPS_FRAME = 0,
	ENC_PPS_FRAME,
	ENC_I_FRAME,
	ENC_P_FRAME,
	ENC_B_FRAME,
	ENC_SEG_TYPE_NUM
} EncSegType;

typedef enum enc_irq_flag {
	ENC_IRQ_FLAG_JPEG,
	ENC_IRQ_FLAG_SRCR,
	ENC_IRQ_FLAG_BSW,
	ENC_IRQ_FLAG_OSDR,
	ENC_IRQ_FLAG_VENC,
	ENC_IRQ_FLAG_MV4R,
	ENC_IRQ_FLAG_REFR,
	ENC_IRQ_FLAG_REFW,
	ENC_IRQ_FLAG_BSW_BUFFER_FULL_0,
	ENC_IRQ_FLAG_BSW_BUFFER_FULL_1,
} EncIrqFlag;

typedef enum enc_osd_yuv_sel {
	ENC_OSD_YUV_DISABLE = 0,
	ENC_OSD_YUV_Y_ENABLE = 1,
	ENC_OSD_YUV_U_ENABLE = 2,
	ENC_OSD_YUV_V_ENABLE = 4,
	ENC_OSD_YUV_UV_ENABLE = 6,
	ENC_OSD_YUV_YUV_ENABLE = 7,
} EncOsdYuvSel;

typedef enum enc_buffer_type {
	ENC_BUFEER_TYPE_SRCR,
	ENC_BUFEER_TYPE_MVR,
	ENC_BUFEER_TYPE_REFW_Y,
	ENC_BUFEER_TYPE_REFW_C,
	ENC_BUFEER_TYPE_REFR_Y,
	ENC_BUFEER_TYPE_REFR_C,
} EncBufferType;

/**
 * @brief Enumeration of video codec profile.
 */
typedef enum enc_profile {
	ENC_PROFILE_BASELINE, /**< Baseline profile. */
	ENC_PROFILE_MAIN, /**< Main profile. */
	ENC_PROFILE_HIGH, /**< High profile. */
	ENC_NUM, /**< Number of video codec profile. */
} EncProfile;

typedef enum srcr_yuv_mode {
	SRCR_BLOCK_16x16,
	SRCR_BLOCK_8x8,
	SRCR_BLOCK_NUM,
} SrcrYuvMode;

typedef enum osd_mode {
	OSD_PALETTE_16BIT_MODE,
	OSD_AYUV_3554_MODE,
	OSD_ALPHA_MODE = 8,
	OSD_PALETTE_8IT_MODE = 9,
} OsdMode;

typedef enum osd_yuv_sel {
	OSD_YUV_DISABLE = 0,
	OSD_Y_ENABLE = 1,
	OSD_U_ENABLE = 2,
	OSD_V_ENABLE = 4,
	OSD_UV_ENABLE = 6,
	OSD_YUV_ENABLE = 7,
} OsdYuvSel;

typedef enum enc_dump_reg {
	ENC_DUMP_REG_SYSCFG = 0,
	ENC_DUMP_REG_SRCR = 1,
	ENC_DUMP_REG_ENC = 2,
	ENC_DUMP_REG_OSDR = 3,
	ENC_DUMP_REG_BSW = 4,
	ENC_DUMP_REG_JPEG = 5,
	ENC_DUMP_REG_REFW = 6,
	ENC_DUMP_REG_REFR = 7,
	ENC_DUMP_REG_VENC = 8,
	ENC_DUMP_REG_MVR = 9,
	ENC_DUMP_REG_ALL = 10,
} EncDumpReg;

typedef struct enc_dram_config {
	u32 bank_number;
	u32 col_addr_type;
	u32 bank_interleave_type;
	u32 bank_group_type;
	u32 target_burst_len;
	u32 target_fifo_level;
	u32 access_end_sel;
} EncDramConfig;

typedef struct enc_roi_attr {
	u32 enable;
	u32 start_mb_x;
	u32 start_mb_y;
	u32 end_mb_x;
	u32 end_mb_y;
} EncRoiAttr;

typedef struct enc_roi_config {
	EncRoiAttr roi_attr[MAX_ROI_REGION];
} EncRoiConfig;

typedef struct enc_bounding_box_attr {
	u32 enable;
	u32 mask; /*fill bounding box rectangle region*/
	u32 start_x;
	u32 start_y;
	u32 end_x;
	u32 end_y;
	u32 yuv_y;
	u32 yuv_u;
	u32 yuv_v;
	u32 line_width;
	u32 line_alpha;
} EncBoundingBoxAttr;

typedef struct enc_bounding_box_config {
	u32 bb_num;
	u32 yuv_select; //0:disable, 1:Y Enable, 2:U Enable 3:V Enable, 6:UV enable, 7:YUV Enable
	EncBoundingBoxAttr bb_attr[MAX_BOUNDING_BOX];
} EncBoundingBoxConfig;

typedef struct enc_osd_attr {
	u32 enable;
	u32 start_x;
	u32 start_y;
	u32 end_x;
	u32 end_y;
} EncOsdAttr;

typedef struct enc_osd_config {
	u32 osd_num;
	u32 osd_mode;
	u32 osd_yuv_sel;
	EncOsdAttr osd_attr[MAX_OSD_REGION];
} EncOsdConfig;

typedef struct enc_buffer_setting {
	u32 osdr_phy_addr;
	u32 osdr_size;
	u32 srcr_phy_addr;
	u32 srcr_size;
	u32 bsw_phy_addr;
	u32 bsw_size;
	u32 mvr_phy_addr;
	u32 mvr_size;
	u32 refr_phy_addr_y;
	u32 refr_phy_addr_c;
	u32 refw_phy_addr_y;
	u32 refw_phy_addr_c;
} EncBufferSetting;

typedef struct enc_frame_quality {
	u32 slice_qp;
	u32 enable_sao;
	u32 q_factor; //for jpeg
} EncFrameQuality;

typedef struct enc_frame_config {
	u32 width;
	u32 height;
	u32 mb_width;
	u32 mb_height;
	u32 code_type;
	u32 code_profile;
	u32 srcr_block_size;
	u32 osd_en;
	u32 fps;
	u32 gop;
	EncFrameQuality quality;
} EncFrameConfig;

// void hw_enc_debug_monitor(EncDumpReg bank);
// void hw_enc_dump_reg(EncDumpReg bank);
// u32 hw_enc_get_frame_size(u32 frame_type);
// u32 hw_enc_get_irq_flag(EncFrameConfig *frame_cfg);
// u32 hw_enc_check_venc_irq();
// u32 hw_enc_check_jpeg_irq();
// void hw_enc_check_osdr_irq();
// u32 hw_enc_check_srcr_irq();
// u32 hw_enc_check_bsw_irq();
// void hw_enc_set_irq_mask(EncFrameConfig *frame_cfg);
// void hw_enc_dram_config();
// void hw_enc_frame_jpeg_configuration(EncFrameConfig *frame_cfg);
// u32 hw_enc_gen_h2645_header(EncFrameConfig *frame_cfg, u8 *buf);
// void hw_enc_frame_h2645_quality(EncFrameQuality *quality);
// void hw_enc_frame_h2645_update_slice_header(EncFrameConfig *frame_cfg, EncFrameQuality *quality, u32 frame_type, u32 frame_cnt);
// void hw_enc_frame_h2645_configuration(EncFrameConfig *frame_cfg, int frame_type);
// void hw_enc_bounding_box(EncBoundingBoxConfig *bb_cfg);
// void hw_enc_set_osd(EncOsdConfig *osd_cfg);
// void hw_enc_roi(EncRoiConfig *roi_cfg);
// void hw_enc_mv_setting();
// void hw_enc_srcr_setting(EncFrameConfig *frame_cfg);
// void hw_enc_bsw_setting();
// void hw_enc_mvr_setting(EncFrameConfig *frame_cfg);
// void hw_enc_refr_setting(EncFrameConfig *frame_cfg);
// void hw_enc_refw_setting(EncFrameConfig *frame_cfg);
// u32 hw_enc_get_buffer_size(EncFrameConfig *frame_cfg, u32 buffer_type);
// void hw_enc_frame_buffer_setting(EncBufferSetting *buffer_setting, EncFrameConfig *frame_cfg);
// void hw_enc_frame_start(EncFrameConfig *frame_cfg, u32 frame_type);
// void hw_enc_sleep();
// void hw_enc_clk_en(u32 enable);
// void hw_enc_reset();
// void hw_enc_init();

#endif /* KYOTO_ENCODER_H_ */
