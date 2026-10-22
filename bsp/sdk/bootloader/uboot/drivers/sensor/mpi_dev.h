/*
 * mpi_dev.h: A copy of mpp/include/mpi_dev.h without redundant headers/functions for uboot.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#ifndef UBOOT_MPI_DEV_H_
#define UBOOT_MPI_DEV_H_

#include "mpi_index.h"

#define MPI_VENC_ROI_NUM (8)
#define MPI_SPH_VIDEO_SENSOR_NUM (2)
#define MPI_STITCH_SENSOR_NUM (2)
#define MPI_STITCH_TABLE_NUM (3)
#define MPI_CENTER_OFFSET_MIN (-8191)
#define MPI_CENTER_OFFSET_MAX (8192)
#define MPI_LDC_RATIO_MIN (0)
#define MPI_LDC_RATIO_MAX (32767)
#define MPI_CIRCLE_RADIUS_MIN (0)
#define MPI_CIRCLE_RADIUS_MAX (65535)
#define MPI_PANORAMA_STRAIGHTEN_MIN (0)
#define MPI_PANORAMA_STRAIGHTEN_MAX (4095)

#define MPI_MAX_ISP_MV_HIST_BIN_NUM (32)
#define MPI_MAX_ISP_MV_HIST_CFG_NUM (1)
#define MPI_MAX_ISP_VAR_CFG_NUM (1)
#define MPI_MAX_ISP_Y_AVG_CFG_NUM (5)
#define MPI_MIN_ROI_VAL (0)
#define MPI_MAX_ROI_VAL (1024)

#define MPI_PATH_RES_ALIGN (1)
#define MPI_PATH_RES_HOR_MINIMUM (0)
#define MPI_PATH_RES_VER_MINIMUM (0)
#define MPI_PATH_RES_HOR_MAXIMUM (65536)
#define MPI_PATH_RES_VER_MAXIMUM (65536)

#define MPI_CHN_RES_ALIGN (8)
#define MPI_CHN_RES_HOR_MINIMUM (192)
#define MPI_CHN_RES_VER_MINIMUM (128)
#define MPI_CHN_RES_HOR_MAXIMUM (4096)
#define MPI_CHN_RES_VER_MAXIMUM (65536)

#define MPI_CHN_LAYOUT_HOR_ALIGN (16)
#define MPI_CHN_LAYOUT_VER_ALIGN (32)
#define MPI_CHN_LAYOUT_X_MINIMUM (0)
#define MPI_CHN_LAYOUT_Y_MINIMUM (0)

#define MPI_SENSOR_BMP(i) (0x1 << (i))

typedef enum mpi_chn_bind_cap {
	MPI_CHN_BIND_CAP_NONE = 0x0,
	MPI_CHN_BIND_CAP_ENC = 0x1,
	MPI_CHN_BIND_CAP_DISP = 0x2,
	MPI_CHN_BIND_CAP_NUM = 0x4,
} MPI_CHN_BIND_CAP_E;

typedef enum mpi_hdr_mode {
	MPI_HDR_MODE_NONE = 0,
	MPI_HDR_MODE_FRAME_PARL,
	MPI_HDR_MODE_FRAME_ITLV,
	MPI_HDR_MODE_TOP_N_BTM,
	MPI_HDR_MODE_SIDE_BY_SIDE,
	MPI_HDR_MODE_LINE_COLOC,
	MPI_HDR_MODE_LINE_ITLV,
	MPI_HDR_MODE_PIX_COLOC,
	MPI_HDR_MODE_PIX_ITLV,
	MPI_HDR_MODE_FRAME_COMB,
	MPI_HDR_MODE_FRAME_ITLV_ASYNC,
	MPI_HDR_MODE_FRAME_ITLV_SYNC,
	MPI_HDR_MODE_NUM,
} MPI_HDR_MODE_E;

typedef enum mpi_ldc_view_type {
	MPI_LDC_VIEW_TYPE_CROP = 0,
	MPI_LDC_VIEW_TYPE_ALL,
	MPI_LDC_VIEW_TYPE_NUM,
} MPI_LDC_VIEW_TYPE_E;

typedef struct mpi_path_attr {
	UINT32 sensor_idx;
	MPI_SIZE_S res;
} MPI_PATH_ATTR_S;

typedef struct mpi_dev_attr {
	UINT8 stitch_en;
	UINT8 eis_en;
	MPI_HDR_MODE_E hdr_mode;
	FLOAT fps;
	MPI_BAYER_E bayer;
	MPI_PATH_BMP_U path;
} MPI_DEV_ATTR_S;

typedef struct mpi_chn_attr {
	MPI_SIZE_S res;
	FLOAT fps;
	MPI_CHN_BIND_CAP_E binding_capability;
} MPI_CHN_ATTR_S;

typedef struct mpi_chn_stat {
	UINT32 status;
} MPI_CHN_STAT_S;

typedef struct mpi_crop_info {
	UINT8 en;
	MPI_RECT_S rect;
} MPI_CROP_INFO_S;

typedef struct mpi_roi_info {
	UINT32 idx;
	MPI_RECT_S rect;
} MPI_ROI_INFO_S;

typedef struct mpi_mirror_flip {
	UINT8 mirr_en;
	UINT8 flip_en;
} MPI_MIRROR_FLIP_S;

typedef struct mpi_sph_video_attr {
	UINT8 sph_video_en;
	INT32 x_cent_offs[MPI_SPH_VIDEO_SENSOR_NUM];
	INT32 y_cent_offs[MPI_SPH_VIDEO_SENSOR_NUM];
	INT32 radius[MPI_SPH_VIDEO_SENSOR_NUM];
	INT32 h_scaling_str[MPI_SPH_VIDEO_SENSOR_NUM];
	INT32 v_scaling_str[MPI_SPH_VIDEO_SENSOR_NUM];
	INT32 h_shearing[MPI_SPH_VIDEO_SENSOR_NUM];
	INT32 v_shearing[MPI_SPH_VIDEO_SENSOR_NUM];
} MPI_SPH_VIDEO_ATTR_S;

typedef struct mpi_ldc_attr {
	UINT8 enable;
	MPI_LDC_VIEW_TYPE_E
	view_type;
	MPI_SHIFT_S
	center_offset;
	INT16 ratio;
} MPI_LDC_ATTR_S;

typedef struct mpi_panorama_attr {
	UINT8 enable;
	MPI_SHIFT_S
	center_offset;
	UINT16 radius;
	UINT16 curvature;
	UINT16 ldc_ratio;
	UINT16 straighten;
} MPI_PANORAMA_ATTR_S;

typedef struct mpi_panning_attr {
	UINT8 enable;
	MPI_SHIFT_S
	center_offset;
	UINT16 radius;
	UINT16 hor_strength;
	UINT16 ver_strength;
	UINT16 ldc_ratio;
} MPI_PANNING_ATTR_S;

typedef struct mpi_surround_attr {
	UINT8 enable;
	MPI_SHIFT_S center_offset;
	MPI_ROTATE_TYPE_E
	rotate;
	UINT16 min_radius;
	UINT16 max_radius;
	UINT16 ldc_ratio;
} MPI_SURROUND_ATTR_S;

typedef struct mpi_stitch_dist {
	UINT16 dist;
	UINT16 ver_disp;
	UINT16 straighten;
	UINT16 src_zoom;
	INT16 theta[MPI_STITCH_SENSOR_NUM];
	UINT16 radius[MPI_STITCH_SENSOR_NUM];
	UINT16 curvature[MPI_STITCH_SENSOR_NUM];
	UINT16 fov_ratio[MPI_STITCH_SENSOR_NUM];
	UINT16 ver_scale[MPI_STITCH_SENSOR_NUM];
	INT16 ver_shift[MPI_STITCH_SENSOR_NUM];
} MPI_STITCH_DIST_S;

typedef struct mpi_stitch_attr {
	UINT8 enable;
	MPI_POINT_S center[MPI_STITCH_SENSOR_NUM];
	INT32 dft_dist;
	INT32 table_num;
	MPI_STITCH_DIST_S table[MPI_STITCH_TABLE_NUM];
} MPI_STITCH_ATTR_S;

typedef enum mpi_win_view_type {
	MPI_WIN_VIEW_TYPE_NORMAL = 0,
	MPI_WIN_VIEW_TYPE_LDC,
	MPI_WIN_VIEW_TYPE_PANORAMA,
	MPI_WIN_VIEW_TYPE_PANNING,
	MPI_WIN_VIEW_TYPE_SURROUND,
	MPI_WIN_VIEW_TYPE_STITCH,
	MPI_WIN_VIEW_TYPE_GRAPHICS,
	MPI_WIN_VIEW_TYPE_NUM,
} MPI_WIN_VIEW_TYPE_E;

typedef struct mpi_win_attr {
	MPI_PATH_BMP_U path;
	FLOAT fps;
	MPI_ROTATE_TYPE_E rotate;
	UINT8 mirr_en;
	UINT8 flip_en;
	MPI_WIN_VIEW_TYPE_E view_type;
	MPI_RECT_S roi;
	UINT8 prio;
	MPI_WIN src_id;
	UINT8 const_qual;
	UINT8 dyn_adj;
} MPI_WIN_ATTR_S;

typedef struct mpi_chn_layout {
	INT32 window_num;
	MPI_WIN win_id[MPI_MAX_VIDEO_WIN_NUM];
	MPI_RECT_S window[MPI_MAX_VIDEO_WIN_NUM];
} MPI_CHN_LAYOUT_S;

typedef struct mpi_isp_mv_hist_cfg {
	MPI_RECT_POINT_S roi;
} MPI_ISP_MV_HIST_CFG_S;

typedef struct mpi_isp_mv_hist {
	INT32 bin_x[MPI_MAX_ISP_MV_HIST_BIN_NUM];
	INT32 bin_y[MPI_MAX_ISP_MV_HIST_BIN_NUM];
	UINT32 bin_count[MPI_MAX_ISP_MV_HIST_BIN_NUM];
	UINT32 total_cnt;
} MPI_ISP_MV_HIST_S;

typedef struct mpi_isp_var_cfg {
	MPI_RECT_POINT_S roi;
} MPI_ISP_VAR_CFG_S;

typedef struct mpi_isp_var {
	UINT32 hor_sum;
	UINT32 ver_sum;
} MPI_ISP_VAR_S;

typedef struct mpi_isp_y_avg_cfg {
	MPI_RECT_POINT_S roi;
	UINT16 diff_thr;
} MPI_ISP_Y_AVG_CFG_S;

typedef UINT16 MPI_ISP_Y_AVG;

typedef enum mpi_snapshot_type {
	MPI_SNAPSHOT_Y = 0,
	MPI_SNAPSHOT_NV12,
	MPI_SNAPSHOT_RGB,
	MPI_SNAPSHOT_MAX
} MPI_SNAPSHOT_TYPE;

typedef struct mpi_video_frame_info {
	void *paddr;
	void *uaddr;
	void *uaddr_1;
	void *kaddr;
	UINT32 width;
	UINT32 height;
	UINT32 depth;
	UINT32 size;
	MPI_SNAPSHOT_TYPE type;
} MPI_VIDEO_FRAME_INFO_S;

typedef enum mpi_rs_cost {
	MPI_RS_COST_BW = 0,
	MPI_RS_COST_DRATE,
	MPI_RS_COST_DRAM_SIZE,
	MPI_RS_COST_SCALE_UP_X,
	MPI_RS_COST_SCALE_UP_Y,
	MPI_RS_COST_SCALE_UP_ACC,
	MPI_RS_COST_SCALE_DOWN_X,
	MPI_RS_COST_SCALE_DOWN_Y,
	MPI_RS_COST_SCALE_DOWN_ACC,
	MPI_RS_COST_SCALE_REVERSE,
	MPI_RS_COST_NUM
} MPI_RS_COST_E;

typedef struct mpi_rs_user_attr {
	UINT8 enc_bitrate;
	UINT16 audio_sample_rate;
	FLOAT weight[MPI_RS_COST_NUM];
	FLOAT cost_toler[MPI_RS_COST_NUM];
} MPI_RS_USER_ATTR_S;

typedef struct mpi_rs_hw_attr {
	UINT8 msb_bw;
	UINT8 lsb_bw;
	UINT8 mv_bw;
	UINT8 osd_bw;
	UINT8 audio_bw;
	UINT8 audio_ch;
	UINT8 frc_bw;
	UINT8 dram_bank_num;
	UINT16 dram_col_byte_num;
	FLOAT is_drate_limit;
	FLOAT enc_drate_limit;
	FLOAT disp_drate_limit;
	FLOAT isp_limit[MPI_RS_COST_NUM];
} MPI_RS_HW_ATTR_S;

typedef struct mpi_dev_bit_depth_attr {
	UINT8 tfw_bit_depth;
	UINT8 fscw_bit_depth;
	UINT8 nrw_bit_depth;
	UINT8 scw_bit_depth;
	UINT8 mv4w_bit_depth;
	UINT8 mv8w_bit_depth;
	UINT8 refw_bit_depth;
	UINT8 osdr_bit_depth;
} MPI_DEV_BIT_DEPTH_ATTR_S;

#endif
