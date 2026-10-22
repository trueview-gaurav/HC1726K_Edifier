/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_osd.h
 * @brief MPI for OSD (On-Screen Display)
 */

#ifndef MPI_OSD_H_
#define MPI_OSD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_index.h"
#ifdef __KERNEL__
#include <linux/time.h>
#else
#include <time.h>
#endif

/*====================================*
 *            OSD SETTING             *
 =====================================*/

#define MPI_OSD_MAX_HANDLE (128) /**< Maximun number of OSD handle. */
#define MPI_OSD_MAX_BIND_CHANNEL (4) /**< Maximum nubmer of canvas OSDs can be bound in encoder channel. */
#define MPI_OSD_MAX_POLYGON_POINT_NUM (32) /**< Maximum number of points in OSD polygon. */
#define MPI_OSD_MAX_LINE_POINT_NUM (2) /**< Number of points in OSD line. */

#define MPI_OSD_MAX_WIDTH (8192) /**< OSD region max width. */
#define MPI_OSD_MAX_HEIGHT (8192) /**< OSD region max height. */
#define MPI_OSD_QP_OFFSET_MAX (51) /**< OSD max qp offset. */
#define MPI_OSD_QP_OFFSET_MIN (-51) /**< OSD min qp offset. */
#define MPI_OSD_THICKNESS_MIN (2) /**< OSD min thickness. */
#define MPI_OSD_THICKNESS_MAX (8) /**< OSD max thickness. */
#define MPI_OSD_MAX_TIMESTAMP_FORMAT (128) /**< OSD max timestamp format length. */

/**
 * @brief a typedef for OSD handle.
 */
typedef INT32 OSD_HANDLE;
/**
 * @brief a typedef for OSD bind module.
 */
typedef INT32 OSD_MODULE;

/**
 * @brief OSD color format.
 * @details
 * @arg AYUV format represents color in 16bits for a pixel.
 * 3 bits for alpha, 5 bits for Y, 4 bits for U and 4 bits for V.
 */
typedef enum mpi_osd_color_format {
	MPI_OSD_COLOR_FORMAT_AYUV_3544 = 0, /**< AYUV 3544 color format. */
	MPI_OSD_COLOR_FORMAT_PALETTE_16, /**< Palette 16 bits color format. */
	MPI_OSD_COLOR_FORMAT_PALETTE_8, /**< Palette 8 bits color format. */
	MPI_OSD_COLOR_FORMAT_NUM,
} MPI_OSD_COLOR_FORMAT_E;

/**
 * @brief OSD overlay type.
 */
typedef enum mpi_osd_overlay {
	MPI_OSD_OVERLAY_POLYGON = 0, /**< Overlay polygon. */
	MPI_OSD_OVERLAY_LINE, /**< Overlay line. */
	MPI_OSD_OVERLAY_BITMAP, /**< Overlay bitmap. */
	MPI_OSD_OVERLAY_BITMAP_BYPASS, /**< Overlay bitmap. */
	MPI_OSD_OVERLAY_U1_POLYGON, /**< Overlay polygon by hardware on upper layer 1.*/
	MPI_OSD_OVERLAY_L10_BITMAP, /**< Overlay bitmap on lower layer 10.*/
	MPI_OSD_OVERLAY_L40_BITMAP, /**< Overlay bitmap on layer 40.*/
	MPI_OSD_OVERLAY_L30_TIMESTAMP, /**< Overlay timestamp on layer 30.*/
	MPI_OSD_OVERLAY_NUM,
	MPI_OSD_OVERLAY_L50_POLYGON = MPI_OSD_OVERLAY_U1_POLYGON,
	MPI_OSD_OVERLAY_L30_POLYGON = MPI_OSD_OVERLAY_POLYGON,
	MPI_OSD_OVERLAY_L30_LINE = MPI_OSD_OVERLAY_LINE,
	MPI_OSD_OVERLAY_L30_BITMAP = MPI_OSD_OVERLAY_BITMAP,
} MPI_OSD_OVERLAY_E;

/**
 * @brief Structure for the attribute of OSD polygon.
 */
typedef struct mpi_osd_polygon_attr {
	UINT16 color; /**< Color value in format AYUV3544. */
	UINT8 line_width; /**< Line width. Range [::MPI_OSD_THICKNESS_MIN, ::MPI_OSD_THICKNESS_MAX] */
	UINT8 fill; /**< Fill polygon. 0: disable, 1: enable. */
	UINT8 point_nums; /**< The number of used point. Range [0, ::MPI_OSD_MAX_POLYGON_POINT_NUM]  */
	MPI_POINT_S point[MPI_OSD_MAX_POLYGON_POINT_NUM]; /**< Polygon points. */
} MPI_OSD_POLYGON_ATTR_S;

/**
 * @brief Structure for the attribute of OSD line.
 */
typedef struct mpi_osd_line_attr {
	UINT16 color; /**< Color value in format AYUV3544. */
	UINT8 line_width; /**< Line width. Range [::MPI_OSD_THICKNESS_MIN, ::MPI_OSD_THICKNESS_MAX] */
	MPI_POINT_S point[MPI_OSD_MAX_LINE_POINT_NUM]; /**< Line point. */
} MPI_OSD_LINE_ATTR_S;

/**
 * @brief Structure for the attribute of OSD timestamp.
 */
typedef struct mpi_osd_timestamp_attr {
	char timestamp_format[MPI_OSD_MAX_TIMESTAMP_FORMAT]; /**< Timestamp format */
	INT32 std_offset; /**< Std time offset in seconds */
	INT32 has_dst; /**< Has dst */
	INT32 dst_offset; /**< Dst time offset in seconds */
	INT64 dst_start_utc; /**< Dst start timestamp in utc */
	INT64 dst_end_utc; /**< Dst end timestamp in utc */
} MPI_OSD_TIMESTAMP_ATTR_S;

/**
 * @brief Structure for the attribute of OSD bind.
 */
typedef struct mpi_osd_bind_attr {
	MPI_POINT_S point; /**< OSD region starting point. */
	OSD_MODULE module; /**< OSD binding module. */
	MPI_ECHN idx; /**< Target encoder channel to bind. */
} MPI_OSD_BIND_ATTR_S;

/**
 * @brief Structure for the attribute of canvas information.
 */
typedef struct mpi_osd_canvas_attr {
	UINT32 canvas_addr; /**< Virtual memory address of the canvas. */
} MPI_OSD_CANVAS_ATTR_S;

/**
 * @struct MPI_OSD_RGN_ATTR_S
 * @brief Structure for the attribute of OSD region.
 * @note
 * @arg Expect specific fields mentioned below, OSD region can not be modified
 *      when video pipeline is running.
 * @property MPI_OSD_RGN_ATTR_S::show
 * This attribute can be modified when video pipeline is running.
 * @property MPI_OSD_RGN_ATTR_S::priority
 * This attribute can be modified when video pipeline is running.
 * @property MPI_OSD_RGN_ATTR_S::polygon
 * This attribute can be modified when video pipeline is running
 * if the corresponding OSD region is a polygon.
 * @property MPI_OSD_RGN_ATTR_S::line
 * This attribute can be modified when video pipeline is running
 * if the corresponding OSD region is a line.
 * @property MPI_OSD_RGN_ATTR_S::timestamp
 * This attribute can be modified when video pipeline is running
 * if the corresponding OSD region is a timestamp.
 */
typedef struct mpi_osd_rgn_attr {
	MPI_OSD_OVERLAY_E osd_type; /**< OSD graphic type. */
	MPI_OSD_COLOR_FORMAT_E color_format; /**< OSD color format. */
	MPI_SIZE_S size; /**< Size of OSD. Width and heigth should alignment to 16. Static attribute. */
	UINT8 show; /**< Show OSD or not, 0: disable, 1: enable. */
	UINT8 priority; /**< OSD priority. For MPI_OSD_OVERLAY_U1_POLYGON Range [0, ::MPI_OSD_MAX_U1_POLYGON_BIND_CHANNEL - 1], others Range [0, ::MPI_OSD_MAX_BIND_CHANNEL - 1]. */
	UINT8 qp_enable; /**< Enable OSD quantization or not, support H264 and H265. */
	INT8 qp_offset; /**< Quantization parameter offset. Range [::MPI_OSD_QP_OFFSET_MIN, ::MPI_OSD_QP_OFFSET_MAX]. */
	union {
		MPI_OSD_POLYGON_ATTR_S polygon; /**< Polygon attribute. */
		MPI_OSD_LINE_ATTR_S line; /**< Line attribute. */
		MPI_OSD_TIMESTAMP_ATTR_S timestamp; /**< Timestamp attribute. */
	};
} MPI_OSD_RGN_ATTR_S;

/**
 * @brief Structure for the attribute of OSD character.
 */
typedef struct osd_character_attr {
	UINT32 code_point; /**< Code point of ASCII 32 ~ 126 */
	UINT32 bitmap_offset; /**< Offset in bitmap */
	UINT32 image_bytes; /**< Bytes of character image */
	UINT32 image_width; /**< Width of character image (pixel) */
	UINT32 image_height; /**< Height of character image (pixel) */
} MPI_OSD_CHARACTER_ATTR_S;

/**
 * @brief Structure for the attribute of OSD font.
 */
typedef struct osd_font_attr {
	MPI_OSD_COLOR_FORMAT_E color_format; /* Bitmap color format */
	UINT32 characters_count; /**< Count of character attr array */
	MPI_OSD_CHARACTER_ATTR_S *characters; /**< Character attr array */
	UINT32 bitmap_bytes; /**< Bytes of bitmap */
	VOID *bitmap_data; /**< Bitmap data */
} MPI_OSD_FONT_ATTR_S;

/* Interface function prototype */
INT32 MPI_createOsdRgn(OSD_HANDLE *handle, const MPI_OSD_RGN_ATTR_S *p_osd_attr);
INT32 MPI_destroyOsdRgn(OSD_HANDLE handle);
INT32 MPI_bindOsdToChn(OSD_HANDLE handle, const MPI_OSD_BIND_ATTR_S *p_osd_bind);
INT32 MPI_unbindOsdFromChn(OSD_HANDLE handle, const MPI_OSD_BIND_ATTR_S *p_osd_bind);
INT32 MPI_getOsdBindAttr(OSD_HANDLE handle, MPI_OSD_BIND_ATTR_S *p_osd_bind);
INT32 MPI_setOsdBindAttr(OSD_HANDLE handle, const MPI_OSD_BIND_ATTR_S *p_osd_bind);
INT32 MPI_getOsdRgnAttr(OSD_HANDLE handle, MPI_OSD_RGN_ATTR_S *p_osd_attr);
INT32 MPI_setOsdRgnAttr(OSD_HANDLE handle, const MPI_OSD_RGN_ATTR_S *p_osd_attr);
INT32 MPI_getOsdCanvas(OSD_HANDLE handle, MPI_OSD_CANVAS_ATTR_S *p_canvas_attr);
INT32 MPI_updateOsdCanvas(OSD_HANDLE handle);
INT32 MPI_updateOsdCanvasAtTimeV2(OSD_HANDLE handle, struct timespec *update_time, INT32 timed_out_ms);
INT32 MPI_createOsdFont(MPI_ECHN chn, const MPI_OSD_FONT_ATTR_S *p_osd_font);
INT32 MPI_destroyOsdFont(MPI_ECHN chn);

/**
* @cond
*
* code fragment skipped by Doxygen.
*/

/* Deprecated MPI */

#define MPI_OSD_MAX_U1_POLYGON_BIND_CHANNEL \
	_Pragma("GCC error \"MPI_OSD_MAX_U1_POLYGON_BIND_CHANNEL is deprecated.\"")(8)
#define MPI_OSD_MAX_TOTAL_BIND_CHANNEL                                                                    \
	_Pragma("GCC error \"MPI_OSD_MAX_TOTAL_BIND_CHANNEL is deprecated.\"")(MPI_OSD_MAX_BIND_CHANNEL + \
	                                                                       MPI_OSD_MAX_U1_POLYGON_BIND_CHANNEL)
#define MPI_OSD_MODE2_MAX_L10_BIND_CHANNEL _Pragma("GCC error \"MPI_OSD_MODE2_MAX_L10_BIND_CHANNEL is deprecated.\"")(8)
#define MPI_OSD_MODE2_MAX_L30_BIND_CHANNEL \
	_Pragma("GCC error \"MPI_OSD_MODE2_MAX_L30_BIND_CHANNEL is deprecated.\"")(16)
#define MPI_OSD_MODE2_MAX_L50_BIND_CHANNEL _Pragma("GCC error \"MPI_OSD_MODE2_MAX_L50_BIND_CHANNEL is deprecated.\"")(8)
#define MPI_OSD_MODE2_MAX_TOTAL_BIND_CHANNEL                                              \
	_Pragma("GCC error \"MPI_OSD_MODE2_MAX_TOTAL_BIND_CHANNEL is deprecated.\"")(     \
	        MPI_OSD_MODE2_MAX_L10_BIND_CHANNEL + MPI_OSD_MODE2_MAX_L30_BIND_CHANNEL + \
	        MPI_OSD_MODE2_MAX_L50_BIND_CHANNEL) /

__attribute__((error("MPI_updateOsdCanvasAtTime is deprecated. Please use MPI_updateOsdCanvasAtTimeV2 instead."))) INT32
MPI_updateOsdCanvasAtTime(OSD_HANDLE handle, struct timespec *update_time);

/**
 * @endcond
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !MPI_OSD_H_ */
