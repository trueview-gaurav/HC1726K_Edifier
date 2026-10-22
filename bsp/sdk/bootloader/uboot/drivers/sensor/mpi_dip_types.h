/*
 * mpi_dip_types.h: A copy of mpp/include/mpi_dip_types.h without redundant headers/functions for uboot.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#ifndef UBOOT_MPI_DIP_TYPES_H_
#define UBOOT_MPI_DIP_TYPES_H_

#include "mpi_index.h"

#define MPI_AWB_CHN_NUM (4)
#define MPI_K_TABLE_ENTRY_NUM (8)
#define MPI_COLOR_CHN_NUM (3)
#define MPI_DCC_CHN_NUM (4)
#define MPI_LUM_HIST_ENTRY_NUM (60)
#define MPI_AE_MAX_LUM_AVG_ROI_NUM (4)
#define MPI_AE_ZONE_ROW (8)
#define MPI_AE_ZONE_COLUMN (8)
#define MPI_AE_ZONE_NUM ((MPI_AE_ZONE_ROW) * (MPI_AE_ZONE_COLUMN))
#define MPI_AWB_WHITE_POINT_NUM (15)
#define MPI_AWB_ZONE_NUM ((8) * (8))
#define MPI_AWB_MAX_PIX_AVG_ROI_NUM (4)
#define MPI_LUMA_HIST_ENTRY_NUM (33)
#define MPI_MV_HIST_ENTRY_NUM (32)
#define MPI_SAD_HIST_ENTRY_NUM (19)
#define MPI_TDIFF_ENTRY_NUM (4)
#define MPI_GAMMA_CURVE_ENTRY_NUM (60)
#define MPI_TE_CURVE_ENTRY_NUM (60)
#define MPI_PTA_CURVE_ENTRY_NUM (33)
#define MPI_SHP_CTRL_POINT_NUM (6)
#define MPI_NR_LUT_ENTRY_NUM (9)
#define MPI_SNS_TABLE_REGS_NUM (32)
#define MPI_ISO_LUT_ENTRY_NUM (16)
#define MPI_SENSOR_GAIN_LUT_ENTRY_NUM (11)
#define MPI_MAX_DIP_DEV_NUM (2)
#define MPI_MAX_SNP_DEV_NUM (2)
#define MPI_MAX_ALG_LIB_NAME (32)
#define MPI_MIN_DIP_ROI_VAL (0)
#define MPI_MAX_DIP_ROI_VAL (1024)
#define MPI_PCA_L_ENTRY_NUM (9)
#define MPI_PCA_S_ENTRY_NUM (13)
#define MPI_PCA_H_ENTRY_NUM (28)
#define MPI_DRI_LUT_ENTRY_NUM (9)
#define MPI_DBC_CHN_NUM (4)
#define MPI_DHZ_RGL_X_NUM (8)
#define MPI_DHZ_RGL_Y_NUM (8)
#define MPI_DHZ_RGL_NUM ((MPI_DHZ_RGL_X_NUM) * (MPI_DHZ_RGL_Y_NUM))

#define DIP_SENSOR_PATH(d, p) MPI_INPUT_PATH(d, p)
#define DIP_GET_DEV(i) MPI_GET_VIDEO_DEV(i)
#define DIP_GET_SNP(i) MPI_GET_INPUT_PATH(i)

typedef MPI_DEV DIP_DEV;
typedef MPI_PATH SNP_DEV;

typedef MPI_SIZE_S SIZE_S;
typedef MPI_RANGE_S RANGE_S;
typedef MPI_BAYER_E BAYER_E;

typedef enum mpi_alg_opt {
	ALG_OPT_AUTO = 0,
	ALG_OPT_HALF_AUTO,
	ALG_OPT_MANUAL,
	ALG_OPT_NUM,
} MPI_ALG_OPT_E;

typedef struct mpi_alg_lib {
	INT32 id;
	char name[MPI_MAX_ALG_LIB_NAME];
} MPI_ALG_LIB_S;

#endif
