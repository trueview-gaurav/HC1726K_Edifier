#ifndef SENSOR_LVDS_H_
#define SENSOR_LVDS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_dip_sns.h"

static const MPI_PARL_LANE_INFO_S k_parl_lane[1] = {
	/* For sensor 0 */
	{ .clock_delay = MPI_LANE_DELAY_0 },
};

static const MPI_SERL_LANE_INFO_S k_serl_lane[1][MPI_MAX_LVDSRX_LANE_NUM] = {
	/* For sensor 0 */
	{
	        { .lane_type = MPI_LANE_TYPE_CLOCK,
	          .lane_idx = 1,
	          .data_delay = MPI_LANE_DELAY_0,
	          .clock_delay = MPI_LANE_DELAY_0,
	          .impd_sel = MPI_IMPD_SEL_ON_CHIP },
	        { .lane_type = MPI_LANE_TYPE_DATA_0,
	          .lane_idx = 0,
	          .data_delay = MPI_LANE_DELAY_0,
	          .clock_delay = MPI_LANE_DELAY_0,
	          .impd_sel = MPI_IMPD_SEL_ON_CHIP },
	        { .lane_type = MPI_LANE_TYPE_DATA_1,
	          .lane_idx = 2,
	          .data_delay = MPI_LANE_DELAY_0,
	          .clock_delay = MPI_LANE_DELAY_0,
	          .impd_sel = MPI_IMPD_SEL_ON_CHIP },
	        { .lane_type = MPI_LANE_TYPE_UNUSED,
	          .lane_idx = -1,
	          .data_delay = MPI_LANE_DELAY_0,
	          .clock_delay = MPI_LANE_DELAY_0,
	          .impd_sel = MPI_IMPD_SEL_ON_CHIP },
	        { .lane_type = MPI_LANE_TYPE_UNUSED,
	          .lane_idx = -1,
	          .data_delay = MPI_LANE_DELAY_0,
	          .clock_delay = MPI_LANE_DELAY_0,
	          .impd_sel = MPI_IMPD_SEL_ON_CHIP },

	},
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !SENSOR_LVDS_H_ */
