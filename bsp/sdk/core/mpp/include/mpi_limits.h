/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_limits.h
 * @brief Limits of MPI properties
 */

#ifndef MPI_LIMITS_H_
#define MPI_LIMITS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MPI_MAX_INPUT_PATH_NUM (4) /**< Maximum number of input path. */
#define MPI_MAX_VIDEO_DEV_NUM (1) /**< Maximum number of video device. */
#define MPI_MAX_VIDEO_CHN_NUM (8) /**< Maximum number of video channel. */
#define MPI_MAX_VIDEO_WIN_NUM (4) /**< Maximum number of video window. */
#define MPI_MAX_ENC_CHN_NUM (8) /**< Maximum number of encoder channel. */
#define MPI_MAX_DISP_CHN_NUM (1) /**< Maximum number of display channel. */
#define MPI_MAX_MODLE_NUM (1) /**< Maximum number of module */
#define MPI_MAX_DATA_LANE_NUM (4) /**< Maximum number of LVDS data lane number. */
#define MPI_MAX_LVDSRX_LANE_NUM (MPI_MAX_DATA_LANE_NUM + 1) /**< Maximum number of LVDS receiver lane number. */

/**
* @cond
*
* code fragment skipped by Doxygen.
*/

/* Deprecated MPI */

#define MPI_MAX_MV_CHN_NUM _Pragma("GCC error \"MPI_MAX_MV_CHN_NUM is deprecated.\"")(1)

#define MPI_MAX_CHIP_CHN_NUM                                                                                         \
	_Pragma("GCC error \"MPI_MAX_CHIP_CHN_NUM is deprecated.\"")(MPI_MAX_VIDEO_DEV_NUM * MPI_MAX_VIDEO_CHN_NUM * \
	                                                             MPI_MAX_VIDEO_WIN_NUM)

/**
 * @endcond
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MPI_LIMITS_H_ */
