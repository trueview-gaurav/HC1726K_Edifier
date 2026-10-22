/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_base_types.h
 * @brief MPI basic data types
 */

#ifndef MPI_BASE_TYPES_H_
#define MPI_BASE_TYPES_H_

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdbool.h>
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MPI_BLOCKING_TIMEOUT_VALUE (-1) /**< Definition of blocking timeout value. */

#define MPI_STATE_NONE 0x0000 /**< Definition of none state. */
#define MPI_STATE_STOP 0x0001 /**< Definition of stop state. */
#define MPI_STATE_RUN 0x0002 /**< Definition of run state. */
#define MPI_STATE_SUSPEND 0x0003 /**< Definition of suspend state. */

#define MPI_STATE_IS_STOP(s) ((s) == MPI_STATE_STOP) /**< To check whether state is stop. */
#define MPI_STATE_IS_RUN(s) ((s) == MPI_STATE_RUN) /**< To check whether state is run. */
#define MPI_STATE_IS_SUSPEND(s) ((s) == MPI_STATE_SUSPEND) /**< To check whether state is suspend. */
#define MPI_STATE_IS_ADDED(s) ((s) > MPI_STATE_NONE) /**< To check whether state is added. */
#define MPI_STATE_IS_ACTIVE(s) \
	((s) == MPI_STATE_RUN || (s) == MPI_STATE_SUSPEND) /**< To check whether state is active. */
#define MPI_STATE_IS_INACTIVE(s) \
	((s) == MPI_STATE_NONE || (s) == MPI_STATE_STOP) /**< To check whether state is inactive. */

#define MPI_SUCCESS (0) /**< Definition of success in MPI. */
#define MPI_FAILURE (-1) /**< Definition of failure in MPI. */

#ifndef VOID
#define VOID void /**< Definition of void. */
#endif /* VOID */

/**
 * @brief a macro to remove type BOOL.
 * @details User should define self BOOL (sized 1 byte) before
 * removing Augentix defined BOOL.
 */
#ifndef REMOVE_AGTX_BOOL
#define REMOVE_AGTX_BOOL

/**
 * @brief a typedef for stdbool
 */
typedef bool BOOL;

#endif /* REMOVE_AGTX_BOOL */

#ifndef TRUE

/**
 * @brief a typedef for true
 */
#define TRUE (true)

#endif /* TRUE */

#ifndef FALSE

/**
 * @brief a typedef for false
 */

#define FALSE (false)
#endif /* FALSE */

/**
 * @brief a typedef for UINT8.
 */
typedef uint8_t UINT8;

/**
 * @brief a typedef for UINT16.
 */
typedef uint16_t UINT16;

/**
 * @brief a typedef for UINT32.
 */
typedef uint32_t UINT32;

/**
 * @brief a typedef for UINT64.
 */
typedef uint64_t UINT64;

/**
 * @brief a typedef for INT8.
 */
typedef int8_t INT8;

/**
 * @brief a typedef for INT16.
 */
typedef int16_t INT16;

/**
 * @brief a typedef for INT32.
 */
typedef int32_t INT32;

/**
 * @brief a typedef for INT64.
 */
typedef int64_t INT64;

/**
 * @brief a typedef for FLOAT.
 */
typedef float FLOAT;

/**
 * @brief Image type
 */
typedef enum mpi_img_type {
	MPI_IMG_TYPE_BAYER = 0,
	MPI_IMG_TYPE_YUV420,
	MPI_IMG_TYPE_YUV422,
	MPI_IMG_TYPE_NRW, /**< Image type format for ENC. */
	MPI_IMG_TYPE_MV, /**< Image type format for MV. */
	MPI_IMG_TYPE_VPW, /**< Image type format for DISP. */
	MPI_IMG_TYPE_NUM
} MPI_IMG_TYPE_E;

/**
 * @brief Enumeration of Bayer phase.
 */
typedef enum mpi_bayer {
	MPI_BAYER_PHASE_G0 = 0, /**< Bayer phase G0. */
	MPI_BAYER_PHASE_R, /**< Bayer phase R. */
	MPI_BAYER_PHASE_B, /**< Bayer phase B. */
	MPI_BAYER_PHASE_G1, /**< Bayer phase G1. */
	MPI_BAYER_PHASE_NUM,
} MPI_BAYER_E;

/**
 * @brief Enumeration of position.
 */
typedef enum mpi_pos {
	MPI_POS_NONE = 0, /**< Un-defined. */
	MPI_POS_UP, /**< Up. */
	MPI_POS_DOWN, /**< Down. */
	MPI_POS_LEFT, /**< Left. */
	MPI_POS_RIGHT, /**< Right. */
	MPI_POS_NUM,
} MPI_POS_E;

/**
 * @brief Enumeration of rotation type.
 */
typedef enum mpi_rotate_type {
	MPI_ROTATE_0 = 0, /**< No rotate. */
	MPI_ROTATE_90, /**< Rotate 90 degrees clockwise. */
	MPI_ROTATE_180, /**< Rotate 180 degrees clockwise. */
	MPI_ROTATE_270, /**< Rotate 270 degrees clockwise. */
	MPI_ROTATE_TYPE_NUM,
} MPI_ROTATE_TYPE_E;

/**
 * @brief Enumeration of device/channel mode.
 */
typedef enum mpi_mode {
	MPI_MODE_ONLINE = 0, /**< Online mode. */
	MPI_MODE_OFFLINE, /**< Offline mode. */
	MPI_MODE_NUM,
} MPI_MODE_E;

/**
 * @brief Union for the sensor path bitmap.
 */
typedef union mpi_path_bmp {
	UINT32 bmp; /**< Path bitmap. */
	struct {
		UINT32 path0_en : 1; /**< Enable bit for path 0. 0: disable, 1: enable */
		UINT32 path1_en : 1; /**< Enable bit for path 1. 0: disable, 1: enable */
		UINT32 path2_en : 1; /**< Enable bit for path 2. 0: disable, 1: enable */
		UINT32 path3_en : 1; /**< Enable bit for path 3. 0: disable, 1: enable */
	} bit; /**< Enable word */
} MPI_PATH_BMP_U;

/**
* @brief Struct for a range.
*/
typedef struct mpi_range {
	UINT32 min; /**< Minimum value of the range. */
	UINT32 max; /**< Maximum value of the range. */
} MPI_RANGE_S;

/**
 * @brief Struct for a pixel position.
 */
typedef struct mpi_point {
	UINT16 x; /**< X coordinate of left corner corresponding to input. */
	UINT16 y; /**< Y coordinate of left corner corresponding to input. */
} MPI_POINT_S;

/**
 * @brief Struct for a pixel shift from a reference point.
 */
typedef struct mpi_shift {
	INT16 x; /**< X coordinate offset corresponding to a reference point. */
	INT16 y; /**< Y coordinate offset corresponding to a reference point. */
} MPI_SHIFT_S;

/**
 * @brief Struct for a porch.
 */
typedef struct mpi_porch {
	UINT16 hor; /**< Porch in horizontal direction. */
	UINT16 ver; /**< Porch in vertical direction. */
} MPI_PORCH_S;

/**
 * @brief Struct for an image size.
 */
typedef struct mpi_size {
	UINT16 width; /**< Image width. */
	UINT16 height; /**< Image height. */
} MPI_SIZE_S;

/**
 * @brief Struct for an buffer size.
 */
typedef struct mpi_buf_size {
	UINT16 width; /**< Image width. */
	UINT16 height; /**< Image height. */
	UINT16 bit_depth; /**< Bit depth. */
	MPI_IMG_TYPE_E img_type; /**< Image type. */
} MPI_BUF_SIZE_S;

/**
 * @brief Struct for an rectangle.
 */
typedef struct mpi_rect {
	UINT16 x; /**< X coordinate of left corner corresponding to input. */
	UINT16 y; /**< Y coordinate of left corner corresponding to input. */
	UINT16 width; /**< Image width. */
	UINT16 height; /**< Image height. */
} MPI_RECT_S;

/**
 * @brief Struct for a rectangle start and end point.
 */
typedef struct mpi_rect_point {
	INT16 sx; /**< X coordinate of start point corresponding to input. */
	INT16 sy; /**< Y coordinate of start point corresponding to input. */
	INT16 ex; /**< X coordinate of end point corresponding to input. */
	INT16 ey; /**< Y coordinate of end point corresponding to input. */
} MPI_RECT_POINT_S;

/**
 * @brief Struct for a motion vector.
 */
typedef struct mpi_motion_vec {
	INT16 x; /**< X component of motion vector. */
	INT16 y; /**< Y component of motion vector. */
} MPI_MOTION_VEC_S;

/**
* @cond
*
* code fragment skipped by Doxygen.
*/

/* Deprecated MPI */

#define MPI_UNUSED(x) _Pragma("GCC error \"MPI_UNUSED is deprecated.\"")(void)(x)
#define MPI_VOID _Pragma("GCC error \"MPI_VOID is deprecated.\"") void

/**
 * @endcond
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !MPI_BASE_TYPES_H_ */
