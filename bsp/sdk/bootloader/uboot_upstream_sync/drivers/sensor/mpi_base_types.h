/*
 * mpi_base_type.h: A copy of mpp/include/mpi_base_type.h without redundant headers/functions for uboot.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#ifndef UBOOT_MPI_BASE_TYPES_H_
#define UBOOT_MPI_BASE_TYPES_H_

#include <linux/types.h>

#define MPI_BLOCKING_TIMEOUT_VALUE (-1)

#define MPI_STATE_NONE 0x0000
#define MPI_STATE_STOP 0x0001
#define MPI_STATE_RUN 0x0002
#define MPI_STATE_SUSPEND 0x0003

#define MPI_STATE_IS_STOP(s) ((s) == MPI_STATE_STOP)
#define MPI_STATE_IS_RUN(s) ((s) == MPI_STATE_RUN)
#define MPI_STATE_IS_SUSPEND(s) ((s) == MPI_STATE_SUSPEND)
#define MPI_STATE_IS_ADDED(s) ((s) > MPI_STATE_NONE)
#define MPI_STATE_IS_ACTIVE(s) ((s) == MPI_STATE_RUN || (s) == MPI_STATE_SUSPEND)
#define MPI_STATE_IS_INACTIVE(s) ((s) == MPI_STATE_NONE || (s) == MPI_STATE_STOP)

#define MPI_SUCCESS (0)
#define MPI_FAILURE (-1)
#define MPI_UNUSED(x) (void)(x)
#define MPI_VOID void

#ifndef VOID
#define VOID void
#endif

#ifndef REMOVE_AGTX_BOOL
#define REMOVE_AGTX_BOOL

typedef bool BOOL;

#endif

#ifndef TRUE

#define TRUE (true)

#endif

#ifndef FALSE

#define FALSE (false)
#endif

typedef uint8_t UINT8;

typedef uint16_t UINT16;

typedef uint32_t UINT32;

typedef uint64_t UINT64;

typedef int8_t INT8;

typedef int16_t INT16;

typedef int32_t INT32;

typedef int64_t INT64;

typedef float FLOAT;

typedef enum mpi_img_type {
	MPI_IMG_TYPE_BAYER = 0,
	MPI_IMG_TYPE_YUV420,
	MPI_IMG_TYPE_YUV422,
	MPI_IMG_TYPE_NRW,
	MPI_IMG_TYPE_MV,
	MPI_IMG_TYPE_VPW,
	MPI_IMG_TYPE_NUM
} MPI_IMG_TYPE_E;

typedef enum mpi_bayer {
	MPI_BAYER_PHASE_G0 = 0,
	MPI_BAYER_PHASE_R,
	MPI_BAYER_PHASE_B,
	MPI_BAYER_PHASE_G1,
	MPI_BAYER_PHASE_NUM,
} MPI_BAYER_E;

typedef enum mpi_pos {
	MPI_POS_NONE = 0,
	MPI_POS_UP,
	MPI_POS_DOWN,
	MPI_POS_LEFT,
	MPI_POS_RIGHT,
	MPI_POS_NUM,
} MPI_POS_E;

typedef enum mpi_rotate_type {
	MPI_ROTATE_0 = 0,
	MPI_ROTATE_90,
	MPI_ROTATE_180,
	MPI_ROTATE_270,
	MPI_ROTATE_TYPE_NUM,
} MPI_ROTATE_TYPE_E;

typedef enum mpi_mode {
	MPI_MODE_ONLINE = 0,
	MPI_MODE_OFFLINE,
	MPI_MODE_NUM,
} MPI_MODE_E;

typedef union mpi_path_bmp {
	UINT32 bmp;
	struct {
		UINT32 path0_en : 1;
		UINT32 path1_en : 1;
	} bit;
} MPI_PATH_BMP_U;

typedef struct mpi_range {
	UINT32 min;
	UINT32 max;
} MPI_RANGE_S;

typedef struct mpi_point {
	UINT16 x;
	UINT16 y;
} MPI_POINT_S;

typedef struct mpi_shift {
	INT16 x;
	INT16 y;
} MPI_SHIFT_S;

typedef struct mpi_porch {
	UINT16 hor;
	UINT16 ver;
} MPI_PORCH_S;

typedef struct mpi_size {
	UINT16 width;
	UINT16 height;
} MPI_SIZE_S;

typedef struct mpi_buf_size {
	UINT16 width;
	UINT16 height;
	UINT16 bit_depth;
	MPI_IMG_TYPE_E img_type;
} MPI_BUF_SIZE_S;

typedef struct mpi_rect {
	UINT16 x;
	UINT16 y;
	UINT16 width;
	UINT16 height;
} MPI_RECT_S;

typedef struct mpi_rect_point {
	INT16 sx;
	INT16 sy;
	INT16 ex;
	INT16 ey;
} MPI_RECT_POINT_S;

typedef struct mpi_motion_vec {
	INT16 x;
	INT16 y;
} MPI_MOTION_VEC_S;

#endif
