/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_dip_types.h
 * @brief MPI for DIP common header
 */

#ifndef MPI_DIP_TYPES_H_
#define MPI_DIP_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_index.h"

#pragma GCC diagnostic error "-Wdeprecated-declarations"

#define MPI_AWB_CHN_NUM (4) /**< Number of channels for AWB, bayer domain */
#define MPI_K_TABLE_ENTRY_NUM (8) /**< Number of color temperature in table, this will be used for interpolation */
#define MPI_COLOR_CHN_NUM (3) /**< Number of color channels in RGB domain */
#define MPI_DCC_CHN_NUM (4) /**< Number of channel for DCC, bayer domain */
#define MPI_LUM_HIST_ENTRY_NUM (60) /**< Number of luminance histograms for AE */
#define MPI_AE_MAX_LUM_AVG_ROI_NUM (4) /**< Number of maximum ROI luminance average for AE */
#define MPI_AE_ZONE_ROW (8) /**< Number of row for AE zone to calculate luminance average */
#define MPI_AE_ZONE_COLUMN (8) /**< Number of column for AE zone to calculate luminance average  */
#define MPI_AE_ZONE_NUM ((MPI_AE_ZONE_ROW) * (MPI_AE_ZONE_COLUMN)) /**< Number of zone luminance for AE to calculate luminance average  */
#define MPI_AWB_WHITE_POINT_NUM (15) /**< Number of brightest points for AWB, bayer domain */
#define MPI_AWB_ZONE_NUM ((8) * (8)) /**< Number of zone for AWB to calculate brightest points */
#define MPI_AWB_MAX_PIX_AVG_ROI_NUM (4) /**< Number of maximum ROI pixel average for AWB */
#define MPI_LUMA_HIST_ENTRY_NUM (33) /**< Number of luminance histograms for PTA */
#define MPI_MV_HIST_ENTRY_NUM (32) /**< Number of MV histograms */
#define MPI_GAMMA_CURVE_ENTRY_NUM (60) /**< Number of bins of a GAMMA curve */
#define MPI_TE_CURVE_ENTRY_NUM (60) /**< Number of bins of a TE curve */
#define MPI_PTA_CURVE_ENTRY_NUM (33) /**< Number of bins of a PTA curve */
#define MPI_NR_LUT_ENTRY_NUM (9) /**< Number of entries in NR look up table */
#define MPI_SNS_TABLE_REGS_NUM (32) /**< Number of Sensor table register */
#define MPI_ISO_LUT_ENTRY_NUM (16) /**< Number of entries in ISO look up table */
#define MPI_FNR_ISO_LUT_ENTRY_NUM (13) /**< Number of entries in FRONT NR ISO look up table */
#define MPI_SENSOR_GAIN_LUT_ENTRY_NUM (11) /**< Number of entries in sensor gain look up table */
#define MPI_SYS_GAIN_ENTRY_NUM (16) /**< Number of entries in system gain look up table */
#define MPI_MAX_DIP_DEV_NUM (2) /**< Number of maximum DIP device */
#define MPI_MAX_SNP_DEV_NUM (2) /**< Number of maximum sensor path device */
#define MPI_MAX_ALG_LIB_NAME (32) /**< Number of maximum algorithm libraries */
#define MPI_MIN_DIP_ROI_VAL (0) /**< Minimum value of DIP ROI */
#define MPI_MAX_DIP_ROI_VAL (1024) /**< Maximum value of DIP ROI */
#define MPI_PCA_L_ENTRY_NUM (9) /**< Number of entries in lightness look up table */
#define MPI_PCA_S_ENTRY_NUM (13) /**< Number of entries in saturation look up table */
#define MPI_PCA_H_ENTRY_NUM (28) /**< Number of entries in hue look up table */
#define MPI_DRI_LUT_ENTRY_NUM (9) /**< Number of entries in DRI look up table */
#define MPI_DBC_CHN_NUM (4) /**< Number of channel for DBC, bayer domain */
#define MPI_DHZ_RGL_X_NUM (8) /**< Row (X) number of DHZ regional data. */
#define MPI_DHZ_RGL_Y_NUM (8) /**< Column (Y) Number of DHZ regional data. */
#define MPI_DHZ_RGL_NUM ((MPI_DHZ_RGL_X_NUM) * (MPI_DHZ_RGL_Y_NUM)) /**< Number (X*Y) of DHZ regional data. */

typedef MPI_DEV DIP_DEV; /**< MPI index of video device  */
typedef MPI_PATH SNP_DEV; /**< MPI index of input path  */

typedef MPI_SIZE_S SIZE_S; /**< Struct for an image size */
typedef MPI_RANGE_S RANGE_S; /**< Struct for a range */
typedef MPI_BAYER_E BAYER_E; /**< Enumeration of Bayer phase */

/**
 * @brief Enumration for DIP algorithm operation mode.
 */
typedef enum mpi_alg_opt {
	ALG_OPT_AUTO = 0, /**< Automatic mode. */
	ALG_OPT_HALF_AUTO, /**< Semi-automatic mode. */
	ALG_OPT_MANUAL, /**< Manual mode. */
	ALG_OPT_NUM,
} MPI_ALG_OPT_E;

/**
 * @brief Structure for DIP algorithm library.
 */
typedef struct mpi_alg_lib {
	INT32 id; /**< DIP algorithm id. */
	char name[MPI_MAX_ALG_LIB_NAME]; /**< DIP algorithm name. */
} MPI_ALG_LIB_S;

/**
 * @brief Enumeration of domains on which AWB CCM is calibrated.
 */
typedef enum mpi_awb_ccm_domain {
	AWB_CCM_DOMAIN_GAMMA = 0, /**< Apply CCM under Gamma domain. */
	AWB_CCM_DOMAIN_LINEAR, /**< Apply CCM under Liner domain. */
	AWB_CCM_DOMAIN_NUM,
} MPI_AWB_CCM_DOMAIN_E
        __attribute__((deprecated(
                "Error: MPI_AWB_CCM_DOMAIN_E is deprecated. It has never been used internally and can be safely removed.")));

/**
* @cond
*
* code fragment skipped by Doxygen.
*/

/* Deprecated MPI */

#define MPI_SAD_HIST_ENTRY_NUM _Pragma("GCC error \"MPI_SAD_HIST_ENTRY_NUM is deprecated.\"")(19)
#define MPI_TDIFF_ENTRY_NUM _Pragma("GCC error \"MPI_TDIFF_ENTRY_NUM is deprecated.\"")(4)
#define MPI_SHP_CTRL_POINT_NUM _Pragma("GCC error \"MPI_SHP_CTRL_POINT_NUM is deprecated.\"")(6)
#define DIP_SENSOR_PATH(d, p) _Pragma("GCC error \"DIP_SENSOR_PATH is deprecated.\"") MPI_INPUT_PATH(d, p)
#define DIP_GET_DEV(i) _Pragma("GCC error \"DIP_GET_DEV is deprecated.\"") MPI_GET_VIDEO_DEV(i)
#define DIP_GET_SNP(i) _Pragma("GCC error \"DIP_GET_SNP is deprecated.\"") MPI_GET_INPUT_PATH(i)

/**
 * @endcond
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !MPI_DIP_TYPES_H_ */
