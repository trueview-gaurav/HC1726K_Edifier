/*
 * mpi_index.h: A copy of mpp/include/mpi_index.h without redundant headers/functions for uboot.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#ifndef UBOOT_MPI_INDEX_H_
#define UBOOT_MPI_INDEX_H_

#include "mpi_base_types.h"
#include "mpi_limits.h"

typedef union mpi_dev {
	struct {
		UINT8 dev;
		UINT8 dummy2;
		UINT8 dummy1;
		UINT8 dummy0;
	};
	UINT32 value : 8;
} MPI_DEV;

typedef union mpi_path {
	struct {
		UINT8 dev;
		UINT8 path;
		UINT8 dummy1;
		UINT8 dummy0;
	};
	UINT32 value : 16;
} MPI_PATH;

typedef union mpi_chn {
	struct {
		UINT8 dev;
		UINT8 chn;
		UINT8 dummy1;
		UINT8 dummy0;
	};
	UINT32 value : 16;
} MPI_CHN;

typedef union mpi_win {
	struct {
		UINT8 dev;
		UINT8 chn;
		UINT8 win;
		UINT8 dummy0;
	};
	UINT32 value : 24;
} MPI_WIN;

typedef union mpi_echn {
	struct {
		UINT8 chn;
		UINT8 dummy2;
		UINT8 dummy1;
		UINT8 dummy0;
	};
	UINT32 value : 8;
} MPI_ECHN;

typedef union mpi_bchn {
	struct {
		UINT8 chn;
		UINT8 bchn;
		UINT8 dummy1;
		UINT8 dummy0;
	};
	UINT32 value : 16;
} MPI_BCHN;

#define MPI_VALUE_INVALID _Pragma("GCC warning \"'MPI_VALUE_INVALID' macro is deprecated\"") 0x80808080

#define MPI_BYTE_INVALID 0x80

#define MPI_BYTE_ALL _Pragma("GCC warning \"'MPI_BYTE_ALL' macro is deprecated\"") 0xFE

#define MPI_VIDEO_DEV(d) \
	((MPI_DEV){      \
	        { .dev = (d), .dummy2 = MPI_BYTE_INVALID, .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

#define VALID_MPI_VIDEO_DEV(i)                                                                                    \
	(((i).dev != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && ((i).dummy1 == MPI_BYTE_INVALID) && \
	 ((i).dummy2 == MPI_BYTE_INVALID))

#define MPI_INPUT_PATH(d, p) \
	((MPI_PATH){ { .dev = (d), .path = (p), .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

#define VALID_MPI_INPUT_PATH(i)                                                                                 \
	(((i).dev != MPI_BYTE_INVALID) && ((i).path != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && \
	 ((i).dummy1 == MPI_BYTE_INVALID))

#define MPI_VIDEO_CHN(d, c) \
	((MPI_CHN){ { .dev = (d), .chn = (c), .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

#define VALID_MPI_VIDEO_CHN(i)                                                                                 \
	(((i).dev != MPI_BYTE_INVALID) && ((i).chn != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && \
	 ((i).dummy1 == MPI_BYTE_INVALID))

#define MPI_VIDEO_WIN(d, c, w) ((MPI_WIN){ { .dev = (d), .chn = (c), .win = (w), .dummy0 = MPI_BYTE_INVALID } })

#define VALID_MPI_VIDEO_WIN(i)                                                                              \
	(((i).dev != MPI_BYTE_INVALID) && ((i).chn != MPI_BYTE_INVALID) && ((i).win != MPI_BYTE_INVALID) && \
	 ((i).dummy0 == MPI_BYTE_INVALID))

#define MPI_ENC_CHN(c) \
	((MPI_ECHN){   \
	        { .chn = (c), .dummy2 = MPI_BYTE_INVALID, .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

#define VALID_MPI_ENC_CHN(i)                                                                                      \
	(((i).chn != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && ((i).dummy1 == MPI_BYTE_INVALID) && \
	 ((i).dummy2 == MPI_BYTE_INVALID))

#define MPI_ENC_BCHN(c, b) \
	((MPI_BCHN){ { .chn = (c), .bchn = (b), .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

#define VALID_MPI_ENC_BCHN(i)                                                                                   \
	(((i).chn != MPI_BYTE_INVALID) && ((i).bchn != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && \
	 ((i).dummy1 == MPI_BYTE_INVALID))

#define MPI_GET_VIDEO_DEV(idx) ((idx).dev)

#define MPI_GET_INPUT_PATH(idx) ((idx).path)

#define MPI_GET_VIDEO_CHN(idx) ((idx).chn)

#define MPI_GET_VIDEO_WIN(idx) ((idx).win)

#define MPI_GET_ENC_CHN(idx) ((idx).chn)

#define MPI_INVALID_VIDEO_DEV MPI_VIDEO_DEV(MPI_BYTE_INVALID)

#define MPI_INVALID_INPUT_PATH MPI_INPUT_PATH(MPI_BYTE_INVALID, MPI_BYTE_INVALID)

#define MPI_INVALID_VIDEO_CHN MPI_VIDEO_CHN(MPI_BYTE_INVALID, MPI_BYTE_INVALID)

#define MPI_INVALID_VIDEO_WIN MPI_VIDEO_WIN(MPI_BYTE_INVALID, MPI_BYTE_INVALID, MPI_BYTE_INVALID)

#define MPI_INVALID_ENC_CHN MPI_ENC_CHN(MPI_BYTE_INVALID)

#define MPI_INVALID_ENC_BCHN MPI_ENC_BCHN(MPI_BYTE_INVALID, MPI_BYTE_INVALID)

#endif
