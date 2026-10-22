/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_dev.h
 * @brief MPI for video device
 */

#ifndef MPI_DEV_H_
#define MPI_DEV_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_index.h"

#define MPI_STITCH_SENSOR_NUM (2) /**< Number of STITCH sensor. */
#define MPI_STITCH_TABLE_NUM (3) /**< Number of STITCH table. */
#define MPI_CENTER_OFFSET_MIN (-8191) /**< Center offset minimun */
#define MPI_CENTER_OFFSET_MAX (8192) /**< Center offset maximum */
#define MPI_LDC_RATIO_MIN (0) /**< LDC minimal ratio. */
#define MPI_LDC_RATIO_MAX (32767) /**< LDC maximal ratio. */
#define MPI_CIRCLE_RADIUS_MIN (0) /**< Circle radius minimum */
#define MPI_CIRCLE_RADIUS_MAX (65535) /**< Circle radius maximum */
#define MPI_PANORAMA_STRAIGHTEN_MIN (0) /**< Panorama straighten minimum */
#define MPI_PANORAMA_STRAIGHTEN_MAX (4095) /**< Panorama straighten maximum */

#define MPI_MAX_ISP_MV_HIST_BIN_NUM (32) /**< Maximum number of MV histogram bins */
#define MPI_MAX_ISP_MV_HIST_CFG_NUM (1) /**< Maximum number of MV histogram configurations */
#define MPI_MAX_ISP_VAR_CFG_NUM (1) /**< Maximum number of variance configurations */
#define MPI_MAX_ISP_Y_AVG_CFG_NUM (5) /**< Maximum number of Y average configurations */
#define MPI_MIN_ROI_VAL (0) /**< ROI value minimum */
#define MPI_MAX_ROI_VAL (1024) /**< ROI value maximum */

#define MPI_PATH_RES_ALIGN (1) /**< Alignment of path resolution. */
#define MPI_PATH_RES_HOR_MINIMUM (0) /**< Horizontal minimum of path resolution. */
#define MPI_PATH_RES_VER_MINIMUM (0) /**< Vertical minimum of path resolution. */
#define MPI_PATH_RES_HOR_MAXIMUM (65536) /**< Horizontal maximum of path resolution. */
#define MPI_PATH_RES_VER_MAXIMUM (65536) /**< Vertical maximum of path resolution. */
#define MPI_PATH_EIS_STRENGTH_MINIMUM (0) /**< Maximum value of path eis strength. */
#define MPI_PATH_EIS_STRENGTH_MAXIMUM (64) /**< Minimum value of path eis strength. */

#define MPI_CHN_RES_ALIGN (8) /**< Alignment of channel resolution. */
#define MPI_CHN_RES_HOR_MINIMUM (192) /**< Horizontal minimum of channel resolution. */
#define MPI_CHN_RES_VER_MINIMUM (128) /**< Vertical minimum of channel resolution. */
#define MPI_CHN_RES_HOR_MAXIMUM (4096) /**< Horizontal maximum of channel resolution. */
#define MPI_CHN_RES_VER_MAXIMUM (65536) /**< Vertical maximum of channel resolution. */

#define MPI_CHN_LAYOUT_HOR_ALIGN (16) /**< Horizontal alignment of channel layout. */
#define MPI_CHN_LAYOUT_VER_ALIGN (16) /**< Vertical alignment of channel layout. */
#define MPI_CHN_LAYOUT_X_MINIMUM (0) /**< X minimum of channel layout. */
#define MPI_CHN_LAYOUT_Y_MINIMUM (0) /**< Y minimum of channel layout. */

/**
 * @brief marco to transform path index to bitmap.
 * @param[in] i sensor path index.
 */
#define MPI_SENSOR_BMP(i) (0x1 << (i))

/**
 * @brief Enumeration of video channel binding capability.
 */
typedef enum mpi_chn_bind_cap {
	MPI_CHN_BIND_CAP_NONE = 0x0, /**< Video channel binding none. */
	MPI_CHN_BIND_CAP_ENC = 0x1, /**< Video channel binding encoder. */
	MPI_CHN_BIND_CAP_DISP = 0x2, /**< Video channel binding display. */
	MPI_CHN_BIND_CAP_NUM = 0x4,
} MPI_CHN_BIND_CAP_E;

/**
 * @brief Enumeration of HDR mode.
 */
typedef enum mpi_hdr_mode {
	MPI_HDR_MODE_NONE = 0, /**< NO HDR mode. */
	MPI_HDR_MODE_FRAME_PARL, /**< Frame parallel HDR mode. */
	MPI_HDR_MODE_FRAME_ITLV, /**< Frame interleave HDR mode. */
	MPI_HDR_MODE_TOP_N_BTM, /**< TOP and bottom HDR mode. */
	MPI_HDR_MODE_SIDE_BY_SIDE, /**< Side by side HDR mode. */
	MPI_HDR_MODE_LINE_COLOC, /**< Line colocated HDR mode. */
	MPI_HDR_MODE_LINE_ITLV, /**< Line interleave HDR mode. */
	MPI_HDR_MODE_PIX_COLOC, /**< Pixel colocated HDR mode. */
	MPI_HDR_MODE_PIX_ITLV, /**< Pixel interleave HDR mode. */
	MPI_HDR_MODE_FRAME_COMB, /**< Frame combined HDR mode. */
	MPI_HDR_MODE_FRAME_ITLV_ASYNC, /**< Frame interleave HDR mode with async method. */
	MPI_HDR_MODE_FRAME_ITLV_SYNC, /**< Frame interleave HDR mode with sync method. */
	MPI_HDR_MODE_NUM,
} MPI_HDR_MODE_E;

/**
 * @brief Enumeration of LDC mode.
 */
typedef enum mpi_ldc_view_type {
	MPI_LDC_VIEW_TYPE_CROP =
	        0, /**< The corrected picture is cropped and the size of the cropped region is equal to that of the source picture. */
	MPI_LDC_VIEW_TYPE_ALL, /**< The maximum rectangle is obtained based on the edges of the corrected picture. */
	MPI_LDC_VIEW_TYPE_NUM,
} MPI_LDC_VIEW_TYPE_E;

/**
 * @struct MPI_PATH_ATTR_S
 * @brief Struct for input path attributes.
 * @property MPI_SIZE_S MPI_PATH_ATTR_S::res
 * @note
 * @arg `res.width` should be within (::MPI_PATH_RES_HOR_MINIMUM, ::MPI_PATH_RES_HOR_MAXIMUM], ::MPI_PATH_RES_ALIGN N.
 * @arg `res.height` should be within (::MPI_PATH_RES_VER_MINIMUM, ::MPI_PATH_RES_VER_MAXIMUM), ::MPI_PATH_RES_ALIGN N.
 * @property UINT8 MPI_PATH_ATTR_S::eis_strength
 * @note
 * @arg `eis_strength` should be within [::MPI_PATH_EIS_STRENGTH_MINIMUM, ::MPI_PATH_EIS_STRENGTH_MAXIMUM], 1N.
 * @arg suggested `eis_strength` should be within [40, 61], 1N.
 */
typedef struct mpi_path_attr {
	UINT32 sensor_idx; /**< Sensor index. */
	FLOAT fps; /**< Max frame rate (frames per second) of the sensor path. */
	FLOAT max_adv_isp_fps; /**< Max frame rate (frames per second) of the sensor path with advanced isp*/
	MPI_SIZE_S res; /**< Input resolution (pixel) of the sensor path. */
	UINT8 eis_strength; /**< Strength for EIS. */
	INT32 drop_pre_roll_num; /**< The numbers of the pre-roll frames to drop. */
} MPI_PATH_ATTR_S;

/**
 * @brief Struct for early video buffer status
 */
typedef struct mpi_ev_buf_status {
	UINT32 total_alloc_size; /**< Total allocation size in bytes */
	UINT32 curr_used_size; /**< Current used size in bytes */
	UINT8 buf_release; /**< Buffer release status. 0: not-yet, 1: all released */
} MPI_EV_BUF_STATUS_S;

/**
 * @struct MPI_DEV_ATTR_S
 * @brief Struct for the attribute of video device.
 * @note
 * @arg Device attibute cannot be modified when device is running.
 * @see MPI_DEV_startDev()
 */
typedef struct mpi_dev_attr {
	UINT8 stitch_en; /**< Enable stitching. 0: disable, 1: enable */
	UINT8 bit_depth; /**< Bit depth for video streaming */
	MPI_HDR_MODE_E hdr_mode; /**< HDR mode. */
	FLOAT fps; /**< Frame rate per second. \n
				* Should be set to the maximum value required by the video specifications for initializing video pipeline.
				*/
	MPI_BAYER_E bayer; /**< Sensor bayer phase.
						* @note This configuration is currently unused, recommend to set it as bayer for sensor 0.
						*/
	MPI_PATH_BMP_U path; /**< Input path enable bitmap. */
} MPI_DEV_ATTR_S;

/**
 * @struct MPI_CHN_ATTR_S
 * @brief Struct for video channel attributes.
 * @note
 * @arg Output resolution cannot be modified when channel is running.
 * @arg If `MPI_CHN_ATTR_S::fps` is smaller than `MPI_DEV_ATTR_S::fps`,
 *      frames are dropped based on the output to input ratio. 
 * @arg For instance, if `MPI_DEV_ATTR_S::fps` is 30 and `MPI_CHN_ATTR_S::fps`
 *      is 25, then video channel will drop one frame in every six frames.
 * @see MPI_DEV_addChn()
 * @see MPI_DEV_getChnAttr()
 * @see MPI_DEV_setChnAttr()
 * @property MPI_SIZE_S MPI_CHN_ATTR_S::res
 * @note
 * @arg `res.width` should be within [::MPI_CHN_RES_HOR_MINIMUM, ::MPI_CHN_RES_HOR_MAXIMUM], ::MPI_CHN_RES_ALIGN N.
 * @arg `res.height` should be within [::MPI_CHN_RES_VER_MINIMUM, ::MPI_CHN_RES_VER_MAXIMUM), ::MPI_CHN_RES_ALIGN N.
 */
typedef struct mpi_chn_attr {
	MPI_SIZE_S res; /**< Video channel output resolution (pixel). */
	FLOAT fps; /**< Video channel output frame rate. Should be a positive number.
	            * @note Only integer value is supported for now.
	            */
	MPI_CHN_BIND_CAP_E binding_capability; /**< Video channel binding capability. */
} MPI_CHN_ATTR_S;

/**
 * @struct MPI_CHN_STAT_S
 * @brief Struct for channel state.
 * @property UINT32 MPI_CHN_STAT_S::status
 * @arg ::MPI_STATE_NONE: channel does not exists.
 * @arg ::MPI_STATE_STOP: channel is not operating.
 * @arg ::MPI_STATE_RUN: channel is running.
 * @arg ::MPI_STATE_SUSPEND channel is suspended.
 */
typedef struct mpi_chn_stat {
	UINT32 status; /**< Channel status. */
} MPI_CHN_STAT_S;

/**
 * @struct MPI_LDC_ATTR_S
 * @brief Struct for the attribute of LDC(Lens Distortion Correction).
 * @note
 * @arg LDC attribute can be modified when device is running.
 * @arg the parameters is valid when `view_type` is set LDC view
 * @arg The unit of `center_offset` is 1/4 pixel.
 * @see ::MPI_WIN_ATTR_S::view_type
 * @property MPI_SHIFT_S MPI_LDC_ATTR_S::center_offset
 * @arg Range [::MPI_CENTER_OFFSET_MIN, ::MPI_CENTER_OFFSET_MAX]. Default 0.
 */
typedef struct mpi_ldc_attr {
	UINT8 enable; /**< Enable LDC, 0: disable, 1: enable. */
	MPI_LDC_VIEW_TYPE_E
	view_type; /**< LDC mode, only ::MPI_LDC_VIEW_TYPE_CROP is available. See online document for more detail. */
	MPI_SHIFT_S
	center_offset; /**< Horizontal and vertical offset of the distortion center relative to the picture center.
	                * Range [::MPI_CENTER_OFFSET_MIN, ::MPI_CENTER_OFFSET_MAX]. Default 0. */
	INT16 ratio; /**< Distortion ratio. Range [::MPI_LDC_RATIO_MIN, ::MPI_LDC_RATIO_MAX]. Default 0. */
} MPI_LDC_ATTR_S;

/**
 * @struct MPI_PANORAMA_ATTR_S
 * @brief Struct for the attribute of fisheye panorama.
 * @note
 * @arg Panorama attribute can be modified when device is running.
 * @arg The parameters is valid when `view_type` is set Panorama view
 * @arg The unit of `center_offset`, `radius`, `curvature` is 1/4 pixel.
 * @see ::MPI_WIN_ATTR_S::view_type
 */
typedef struct mpi_panorama_attr {
	UINT8 enable; /**< Enable bit. 0: disable, 1: enable */
	MPI_SHIFT_S
	center_offset; /**< Horizontal and vertical offset of the distortion center relative to the picture center.
	                * Range [::MPI_CENTER_OFFSET_MIN, ::MPI_CENTER_OFFSET_MAX]. Default 0. */
	UINT16 radius; /**< Horizontal FOV in image circle. Range [::MPI_CIRCLE_RADIUS_MIN, ::MPI_CIRCLE_RADIUS_MAX]. */
	UINT16 curvature; /**< Virtical FOV in image circle. Range [::MPI_CIRCLE_RADIUS_MIN, ::MPI_CIRCLE_RADIUS_MAX]. */
	UINT16 ldc_ratio; /**< Distortion ratio. Range [::MPI_LDC_RATIO_MIN, ::MPI_LDC_RATIO_MAX]. Default 0. */
	UINT16 straighten; /**< Strength for straighten line. Range [0, 4095]. */
} MPI_PANORAMA_ATTR_S;

/**
 * @struct MPI_PANNING_ATTR_S
 * @brief Struct for the attribute of fisheye panning.
 * @note
 * @arg Panning attribute can be modified when device is running.
 * @arg the parameters is valid when MPI_WIN_ATTR_S::view_type is set Panning view
 * @arg The unit of `center_offset` and `raduis` is 1/4 pixel.
 * @arg It is suggested to be cropped 5% outer area by specifying ROI region in ::MPI_WIN_ATTR_S.
 */
typedef struct mpi_panning_attr {
	UINT8 enable; /**< Enable bit. 0: disable, 1: enable */
	MPI_SHIFT_S
	center_offset; /**< Horizontal and vertical offset of the distortion center relative to the picture center.
	                * Range [::MPI_CENTER_OFFSET_MIN, ::MPI_CENTER_OFFSET_MAX]. Default 0. */
	UINT16 radius; /**< Radius of image circle. Range [::MPI_CIRCLE_RADIUS_MIN, ::MPI_CIRCLE_RADIUS_MAX]. */
	UINT16 hor_strength; /**< Horizontal dewarping strength. Suggested 27. */
	UINT16 ver_strength; /**< Vertical dewarping strength. Suggested 27. */
	UINT16 ldc_ratio; /**< Distortion ratio. Range [::MPI_LDC_RATIO_MIN, ::MPI_LDC_RATIO_MAX]. Default 0. */
} MPI_PANNING_ATTR_S;

/**
 * @struct MPI_SURROUND_ATTR_S
 * @brief Struct for the attribute of fisheye surround.
 * @arg the parameters is valid when ::MPI_WIN_ATTR_S::view_type is set as surround view
 * @arg The unit of `center_offset`, `min_raduis`, and `max_radius` is 1/4 pixel.
 * @arg Note that for buttom-up application such as conference camera. You need to flip the view.
 * @arg `max_radius` should be larger than `min_radius`
 */
typedef struct mpi_surround_attr {
	UINT8 enable; /**< Enable bit. 0: disable, 1: enable */
	MPI_SHIFT_S center_offset; /**< Coordinate shift of circle center. */
	MPI_ROTATE_TYPE_E
	rotate; /**< Rotation of image circle. Decide which direction you want to put in the center of the dewarped image */
	UINT16 min_radius; /**< Inner radius of dewarping area. Range [::MPI_CIRCLE_RADIUS_MIN, ::MPI_CIRCLE_RADIUS_MAX]. */
	UINT16 max_radius; /**< Outer radius of dewarping area. Range [::MPI_CIRCLE_RADIUS_MIN, ::MPI_CIRCLE_RADIUS_MAX]. */
	UINT16 ldc_ratio; /**< Distortion ratio. Range [::MPI_LDC_RATIO_MIN, ::MPI_LDC_RATIO_MAX]. Default 0. */
} MPI_SURROUND_ATTR_S;

/**
 * @struct MPI_STITCH_DIST_S
 * @brief Struct for stitch parmeters at certain distance.
 */
typedef struct mpi_stitch_dist {
	UINT16 dist; /**< Distance in cm. */
	UINT16 ver_disp; /**< Vertical display area. */
	UINT16 straighten; /**< Straighten line level. */
	UINT16 src_zoom; /**< Source image zoom. */
	INT16 theta[MPI_STITCH_SENSOR_NUM]; /**< Rotation angle. */
	UINT16 radius[MPI_STITCH_SENSOR_NUM]; /**< Stitch radius. */
	UINT16 curvature[MPI_STITCH_SENSOR_NUM]; /**< Stitch curvature. */
	UINT16 fov_ratio[MPI_STITCH_SENSOR_NUM]; /**< Horizontal fov ratio. */
	UINT16 ver_scale[MPI_STITCH_SENSOR_NUM]; /**< Vertical scaling. */
	INT16 ver_shift[MPI_STITCH_SENSOR_NUM]; /**< Vertical shift. */
} MPI_STITCH_DIST_S;

/**
 * @struct MPI_STITCH_ATTR_S
 * @brief Struct for the attribute of content adaptive stitching.
 * @details The parameters are generated by the dual-sensor calibration tool.
 * @note
 * @arg User must enable stitching in MPI_DEV_ATTR_S before configuring this attirbute.
 * @arg The parameters is valid when ::MPI_WIN_ATTR_S::view_type is set as stitch view
 */
typedef struct mpi_stitch_attr {
	UINT8 enable; /**< Enable stitch, 0: disable, 1: enable. */
	MPI_POINT_S center[MPI_STITCH_SENSOR_NUM]; /**< Camera optical center */
	INT32 dft_dist; /**< Default distance */
	INT32 table_num; /**< Number of stitch table used */
	MPI_STITCH_DIST_S table[MPI_STITCH_TABLE_NUM]; /**< Stitch tables */
} MPI_STITCH_ATTR_S;

/**
 * @brief Enumeration of window view type.
 */
typedef enum mpi_win_view_type {
	MPI_WIN_VIEW_TYPE_NORMAL = 0, /**< Normal view without GFX. */
	MPI_WIN_VIEW_TYPE_LDC, /**< LDC view. */
	MPI_WIN_VIEW_TYPE_PANORAMA, /**< Panorama view. */
	MPI_WIN_VIEW_TYPE_PANNING, /**< Panning view. */
	MPI_WIN_VIEW_TYPE_SURROUND, /**< Surround view. */
	MPI_WIN_VIEW_TYPE_STITCH, /**< Stitch view. */
	MPI_WIN_VIEW_TYPE_GRAPHICS, /**< Graphics view. */
	MPI_WIN_VIEW_TYPE_NUM,
} MPI_WIN_VIEW_TYPE_E;

/**
 * @struct MPI_WIN_ATTR_S
 * @brief Struct for the video window attributes.
 * @note
 * @arg fps, roi, mirr_en and flip_en can by modified dynamically. Other attributes
 *      cannot be modified when video channel is running.
 * @arg If window attributes are not modified by MPI_DEV_setWindowAttr(),
 * it follows the default value:
 * @code{.c}
 * {
 *     .path.bmp = 0x01,
 *     .fps = 20,
 *     .rotate = MPI_ROTATE_0,
 *     .mirr_en = 0,
 *     .flip_en = 0,
 *     .eis_en = 0,
 *     .view_type = MPI_WIN_VIEW_TYPE_NORMAL,
 *     .prio = 0,
 *     .roi = (MPI_RECT_S){ .x = 0, .y = 0, .width = MPI_MAX_ROI_VAL, .height = MPI_MAX_ROI_VAL }
 * }
 * @endcode
 * @see MPI_DEV_setWindowAttr()
 * @see MPI_DEV_setWindowRoi()
 * @property MPI_RECT_S MPI_WIN_ATTR_S::roi
 * @note
 * @arg The value of `x`, `y`, `x + width` and `x + height` must be in range
 *      [::MPI_MIN_ROI_VAL, ::MPI_MAX_ROI_VAL].
 * @property MPI_RECT_S MPI_WIN_ATTR_S::prio
 * @details The window with larger priority would overlay smaller ones
 */
typedef struct mpi_win_attr {
	MPI_PATH_BMP_U path; /**< Input path enable bitmap. */
	FLOAT fps; /**< Video window output frame rate.
	             *  Should be a positive number, then smaller than or equal to channel FPS
	             */
	MPI_ROTATE_TYPE_E rotate; /**< Rotate type. */
	UINT8 mirr_en; /**< Mirror enable bit. 0: disable, 1: enable */
	UINT8 flip_en; /**< Flip enable bit. 0: disable, 1: enable */
	UINT8 eis_en; /**< EIS enable bit. 0: disable, 1: enable */
	MPI_WIN_VIEW_TYPE_E view_type; /**< Window view type. */
	MPI_RECT_S roi; /**< Display ROI (proportionality) on the coordinate of corrected images. */
	UINT8 prio; /**< Priority of window. */
	MPI_WIN src_id; /**< Should be ::MPI_INVALID_VIDEO_WIN (Internal Use Only). */
	UINT8 const_qual; /**< Should be 1 (Internal Use Only). */
	UINT8 dyn_adj; /**< Should be 0 (Internal Use Only). */
} MPI_WIN_ATTR_S;

/**
 * @struct MPI_CHN_LAYOUT_S
 * @brief Struct for the video channel layout.
 * @details
 * @note
 * @arg Layout cannot be modified when channel is running.
 * @see MPI_DEV_getChnLayout()
 * @see MPI_DEV_setChnLayout()
 * @property MPI_RECT_S MPI_CHN_LAYOUT_S::window[MPI_MAX_VIDEO_WIN_NUM]
 * @note
 * @arg `window[i].x` should be within [::MPI_CHN_LAYOUT_X_MINIMUM, ::MPI_CHN_RES_HOR_MAXIMUM], ::MPI_CHN_LAYOUT_HOR_ALIGN N.
 * @arg `window[i].y` should be within [::MPI_CHN_LAYOUT_Y_MINIMUM, ::MPI_CHN_RES_VER_MAXIMUM), ::MPI_CHN_LAYOUT_VER_ALIGN N.
 * @arg `window[i].width` should be within [::MPI_CHN_RES_HOR_MINIMUM, ::MPI_CHN_RES_HOR_MAXIMUM], ::MPI_CHN_RES_ALIGN N.
 * @arg `window[i].height` should be within [::MPI_CHN_RES_VER_MINIMUM, ::MPI_CHN_RES_VER_MAXIMUM), ::MPI_CHN_RES_ALIGN N.
 * @arg All windows must be in range of associated channel.
 */
typedef struct mpi_chn_layout {
	INT32 window_num; /**< Number of active windows in channel. Range [0, ::MPI_MAX_VIDEO_WIN_NUM] */
	MPI_WIN win_id[MPI_MAX_VIDEO_WIN_NUM]; /**< Window index. */
	MPI_RECT_S window[MPI_MAX_VIDEO_WIN_NUM]; /**< Position from the upper left corner, and size (pixels) of each video window. */
} MPI_CHN_LAYOUT_S;

/**
 * @brief Struct for the configuration of ISP MV hist.
 */
typedef struct mpi_isp_mv_hist_cfg {
	MPI_RECT_POINT_S roi; /**< Region of interest .*/
} MPI_ISP_MV_HIST_CFG_S;

/**
 * @brief Struct for the of ISP MV hist.
 */
typedef struct mpi_isp_mv_hist {
	INT32 bin_x[MPI_MAX_ISP_MV_HIST_BIN_NUM]; /**< The x coordinate of the bin. */
	INT32 bin_y[MPI_MAX_ISP_MV_HIST_BIN_NUM]; /**< The y coordinate of the bin. */
	UINT32 bin_count[MPI_MAX_ISP_MV_HIST_BIN_NUM]; /**< Count of the bin. */
	UINT32 total_cnt; /**< Number of total bin count. */
} MPI_ISP_MV_HIST_S;

/**
 * @brief Struct for the of ISP variance configuration.
 */
typedef struct mpi_isp_var_cfg {
	MPI_RECT_POINT_S roi; /**< Region of interest. */
} MPI_ISP_VAR_CFG_S;

/**
 * @brief Struct for the of ISP variance.
 */
typedef struct mpi_isp_var {
	UINT32 hor_sum; /**< Sum of horizontal variance. */
	UINT32 ver_sum; /**< Sum of vertical variance. */
	UINT32 hor_ver_sum; /**< Sum of horizontal variance and vertical variance. */
} MPI_ISP_VAR_S;

/**
 * @brief Struct for the of ISP variance configuration.
 */
typedef struct mpi_isp_y_avg_cfg {
	MPI_RECT_POINT_S roi; /**< Region of interest. */
	UINT16 diff_thr; /**< Difference threshold. */
} MPI_ISP_Y_AVG_CFG_S;

/**
 * @brief MPI_ISP_Y_AVG is represented by UINT16
 */
typedef UINT16 MPI_ISP_Y_AVG;

/**
* @brief Enumneration of snapshot type.
*/
typedef enum mpi_snapshot_type {
	MPI_SNAPSHOT_Y = 0, /**< Y only */
	MPI_SNAPSHOT_NV12, /**< NV12 snapshot */
	MPI_SNAPSHOT_RGB, /**< RGB snapshot */
	MPI_SNAPSHOT_MAX
} MPI_SNAPSHOT_TYPE;

/**
 * @brief Struct for the video frame information.
 * @details Contains width, height, image type, etc.
 */
typedef struct mpi_video_frame_info {
	void *paddr; /**< Reserved */
	void *uaddr; /**< Address for the video frame */
	void *uaddr_1; /**< Address for the YUV format's chrominance data */
	void *kaddr; /**< Reserved */
	UINT32 width; /**< Width of the video frame. */
	UINT32 height; /**< Height of the video frame. */
	UINT32 depth; /**< Bit-depth of the video frame. */
	UINT32 size; /**< Total size of the video frame. */
	MPI_SNAPSHOT_TYPE type; /**< Snapshot type */
} MPI_VIDEO_FRAME_INFO_S;

/**
 * @cond
 *
 * code fragment skipped by Doxygen.
 */

/**
 * @brief Enumeration of RS cost.
 */
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
	MPI_RS_COST_SCALE_REVERSE, /**< Reverse. */
	MPI_RS_COST_NUM
} MPI_RS_COST_E;

/**
 * @brief Struct for the route synthesis user configuration.
 */
typedef struct mpi_rs_user_attr {
	FLOAT weight[MPI_RS_COST_NUM];
	FLOAT cost_toler[MPI_RS_COST_NUM];
} MPI_RS_USER_ATTR_S;

/**
 * @brief Struct for the route synthesis hw configuration.
 */
typedef struct mpi_rs_hw_attr {
	FLOAT is_drate_limit;
	FLOAT enc_drate_limit;
	FLOAT disp_drate_limit;
	FLOAT isp_limit[MPI_RS_COST_NUM];
} MPI_RS_HW_ATTR_S;

/**
 * @brief Structure of low power motion detection information
 * @details
 * Contains low power motion detection information of the image.
 */
typedef struct mpi_lpmd_info {
	UINT8 status_frame_alarm; /**< Frame alarm by motion detection. The value range is [0, 255]*/
} MPI_LPMD_INFO_S;

/**
 * @endcond
 */

/* Interface function prototype */
INT32 MPI_DEV_addPath(MPI_PATH idx, const MPI_PATH_ATTR_S *p_path_attr);
INT32 MPI_DEV_deletePath(MPI_PATH idx);
INT32 MPI_DEV_setPathAttr(MPI_PATH idx, const MPI_PATH_ATTR_S *p_path_attr);
INT32 MPI_DEV_getPathAttr(MPI_PATH idx, MPI_PATH_ATTR_S *p_path_attr);
INT32 MPI_DEV_getPathEvBufStatus(MPI_PATH idx, MPI_EV_BUF_STATUS_S *p_ev_buf_status);
INT32 MPI_DEV_createDev(MPI_DEV idx, const MPI_DEV_ATTR_S *p_dev_attr);
INT32 MPI_DEV_destroyDev(MPI_DEV idx);
INT32 MPI_DEV_setDevAttr(MPI_DEV idx, const MPI_DEV_ATTR_S *p_dev_attr);
INT32 MPI_DEV_getDevAttr(MPI_DEV idx, MPI_DEV_ATTR_S *p_dev_attr);
INT32 MPI_DEV_startDev(MPI_DEV idx);
INT32 MPI_DEV_stopDev(MPI_DEV idx);
INT32 MPI_DEV_addChn(MPI_CHN idx, const MPI_CHN_ATTR_S *p_chn_attr);
INT32 MPI_DEV_deleteChn(MPI_CHN idx);
INT32 MPI_DEV_setChnAttr(MPI_CHN idx, const MPI_CHN_ATTR_S *p_chn_attr);
INT32 MPI_DEV_getChnAttr(MPI_CHN idx, MPI_CHN_ATTR_S *p_chn_attr);

INT32 MPI_DEV_setChnLayout(MPI_CHN idx, const MPI_CHN_LAYOUT_S *p_chn_layout);
INT32 MPI_DEV_getChnLayout(MPI_CHN idx, MPI_CHN_LAYOUT_S *p_chn_layout);
INT32 MPI_DEV_setWindowAttr(MPI_WIN idx, const MPI_WIN_ATTR_S *p_window_attr);
INT32 MPI_DEV_getWindowAttr(MPI_WIN idx, MPI_WIN_ATTR_S *p_window_attr);
INT32 MPI_DEV_setWindowRoi(MPI_WIN idx, const MPI_RECT_S *p_roi);
INT32 MPI_DEV_getWindowRoi(MPI_WIN idx, MPI_RECT_S *p_roi);

INT32 MPI_DEV_setStitchAttr(MPI_WIN idx, const MPI_STITCH_ATTR_S *p_stitch_attr);
INT32 MPI_DEV_getStitchAttr(MPI_WIN idx, MPI_STITCH_ATTR_S *p_stitch_attr);

INT32 MPI_DEV_setLdcAttr(MPI_WIN idx, const MPI_LDC_ATTR_S *p_ldc_attr);
INT32 MPI_DEV_getLdcAttr(MPI_WIN idx, MPI_LDC_ATTR_S *p_ldc_attr);

INT32 MPI_DEV_setPanoramaAttr(MPI_WIN idx, const MPI_PANORAMA_ATTR_S *p_panorama_attr);
INT32 MPI_DEV_getPanoramaAttr(MPI_WIN idx, MPI_PANORAMA_ATTR_S *p_panorama_attr);

INT32 MPI_DEV_setPanningAttr(MPI_WIN idx, const MPI_PANNING_ATTR_S *p_panning_attr);
INT32 MPI_DEV_getPanningAttr(MPI_WIN idx, MPI_PANNING_ATTR_S *p_panning_attr);

INT32 MPI_DEV_setSurroundAttr(MPI_WIN idx, const MPI_SURROUND_ATTR_S *p_surround_attr);
INT32 MPI_DEV_getSurroundAttr(MPI_WIN idx, MPI_SURROUND_ATTR_S *p_surround_attr);

INT32 MPI_DEV_startAllChn(MPI_DEV idx);
INT32 MPI_DEV_stopAllChn(MPI_DEV idx);
INT32 MPI_DEV_queryChnState(MPI_CHN idx, MPI_CHN_STAT_S *stat);

INT32 MPI_DEV_addIspMvHistCfg(MPI_WIN idx, const MPI_ISP_MV_HIST_CFG_S *cfg, UINT8 *cfg_idx);
INT32 MPI_DEV_rmIspMvHistCfg(MPI_WIN idx, UINT8 cfg_idx);
INT32 MPI_DEV_getIspMvHistCfg(MPI_WIN idx, UINT8 cfg_idx, MPI_ISP_MV_HIST_CFG_S *cfg);
INT32 MPI_DEV_getIspMvHist(MPI_WIN idx, UINT8 roi_idx, MPI_ISP_MV_HIST_S *stat);
INT32 MPI_DEV_addIspVarCfg(MPI_WIN idx, const MPI_ISP_VAR_CFG_S *cfg, UINT8 *cfg_idx);
INT32 MPI_DEV_rmIspVarCfg(MPI_WIN idx, UINT8 cfg_idx);
INT32 MPI_DEV_getIspVarCfg(MPI_WIN idx, UINT8 cfg_idx, MPI_ISP_VAR_CFG_S *cfg);
INT32 MPI_DEV_getIspVar(MPI_WIN idx, UINT8 cfg_idx, MPI_ISP_VAR_S *stat);
INT32 MPI_DEV_addIspYAvgCfg(MPI_WIN idx, const MPI_ISP_Y_AVG_CFG_S *cfg, UINT8 *cfg_idx);
INT32 MPI_DEV_rmIspYAvgCfg(MPI_WIN idx, UINT8 cfg_idx);
INT32 MPI_DEV_getIspYAvgCfg(MPI_WIN idx, UINT8 cfg_idx, MPI_ISP_Y_AVG_CFG_S *cfg);
INT32 MPI_DEV_getIspYAvg(MPI_WIN idx, UINT8 cfg_idx, MPI_ISP_Y_AVG *y_avg);

INT32 MPI_DEV_getWinFrame(MPI_WIN idx, MPI_VIDEO_FRAME_INFO_S *frame_info, INT32 time_ms);
INT32 MPI_DEV_releaseWinFrame(MPI_WIN idx, MPI_VIDEO_FRAME_INFO_S *frame_info);

INT32 MPI_DEV_waitWin(MPI_WIN idx, UINT32 *timestamp, INT32 timeout);

INT32 MPI_DEV_getLpmdInfo(MPI_PATH idx, MPI_LPMD_INFO_S *lpmd_info);

/**
* @cond
*
* code fragment skipped by Doxygen.
*/

/* Deprecated MPI */

#define MPI_SPH_VIDEO_SENSOR_NUM _Pragma("GCC error \"MPI_SPH_VIDEO_SENSOR_NUM is deprecated.\"")(2)

__attribute__((error("MPI_DEV_startChn is not supported yet. Please use MPI_DEV_startAllChn instead."))) INT32
MPI_DEV_startChn(MPI_CHN idx);

__attribute__((error("MPI_DEV_stopChn is not supported yet. Please use MPI_DEV_stopAllChn instead."))) INT32
MPI_DEV_stopChn(MPI_CHN idx);

__attribute__((error("MPI_DEV_setRsUserAttr is deprecated."))) INT32
MPI_DEV_setRsUserAttr(MPI_DEV idx, const MPI_RS_USER_ATTR_S *p_rs_attr);

__attribute__((error("MPI_DEV_getRsUserAttr is deprecated."))) INT32
MPI_DEV_getRsUserAttr(MPI_DEV idx, MPI_RS_USER_ATTR_S *p_rs_attr);

__attribute__((error("MPI_DEV_setRsHwAttr is deprecated."))) INT32
MPI_DEV_setRsHwAttr(MPI_DEV idx, const MPI_RS_HW_ATTR_S *p_rs_attr);

__attribute__((error("MPI_DEV_getRsHwAttr is deprecated."))) INT32 MPI_DEV_getRsHwAttr(MPI_DEV idx,
                                                                                       MPI_RS_HW_ATTR_S *p_rs_attr);

__attribute__((error("MPI_DEV_waitIspStat is deprecated. Please use MPI_DEV_waitWin instead."))) INT32
MPI_DEV_waitIspStat(MPI_WIN idx);

/**
 * @endcond
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !MPI_DEV_H_ */
