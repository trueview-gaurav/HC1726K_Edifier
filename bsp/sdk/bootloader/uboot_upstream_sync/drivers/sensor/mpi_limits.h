/*
 * mpi_limits.h: A copy of mpp/include/mpi_limits.h without redundant headers/functions for uboot.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#ifndef UBOOT_MPI_LIMITS_H_
#define UBOOT_MPI_LIMITS_H_

#define MPI_MAX_INPUT_PATH_NUM (2)
#define MPI_MAX_VIDEO_DEV_NUM (1)
#define MPI_MAX_VIDEO_CHN_NUM (4)
#define MPI_MAX_VIDEO_WIN_NUM (4)
#define MPI_MAX_ENC_CHN_NUM (4)
#define MPI_MAX_DISP_CHN_NUM (1)
#define MPI_MAX_MV_CHN_NUM (1)
#define MPI_MAX_CHIP_CHN_NUM (MPI_MAX_VIDEO_DEV_NUM * MPI_MAX_VIDEO_CHN_NUM * MPI_MAX_VIDEO_WIN_NUM)
#define MPI_MAX_MODLE_NUM (1)
#define MPI_MAX_DATA_LANE_NUM (4)
#define MPI_MAX_LVDSRX_LANE_NUM (MPI_MAX_DATA_LANE_NUM + 1)

#endif
