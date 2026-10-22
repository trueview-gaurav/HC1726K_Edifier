/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/* sensor_cal.h - Built-in IQ settings inside the library. */

#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
    32,     64,    128,    256,     512,
  1024,   2048,   4096,   8192,   16384,
 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft[MPI_MAX_SNP_DEV_NUM] = {
	{
		.dbc = {
			.dbc_level = 0,
		},
		.dcc = {
			.gain = { 1024, 1024, 1024, 1024 },
			.offset_2s = {0, 0, 0, 0},
		},
		.lsc = {
			.origin = 65536,
			.x_trend_2s = 0,
			.y_trend_2s = 0,
			.x_curvature = 0,
			.y_curvature = 0,
			.tilt_2s = 0,
		},
	},
};

// ...

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
