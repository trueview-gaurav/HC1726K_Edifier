/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_dip_3a.h
 * @brief MPI for DIP 3A algorithm
 */

#ifndef MPI_DIP_3A_H_
#define MPI_DIP_3A_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_dip_types.h"
#include "mpi_dip_sns.h"

#pragma GCC diagnostic error "-Wdeprecated-declarations"

/**
 * @brief Defines the statistics of AWB algorithm.
 */
typedef struct mpi_awb_stat {
	UINT32 white[MPI_AWB_CHN_NUM]; /**< Weighed sum of white point energy. */
	UINT32 white_norm[MPI_AWB_CHN_NUM]; /**< Total sum of white point weight. */
	UINT32 channel_avg[MPI_AWB_CHN_NUM]; /**< Channel average. */
} MPI_AWB_STAT_S;

/********************************  AE  *************************************/
/**
 * @brief Defines the parameters for the AE algorithm.
 */
typedef struct mpi_ae_param {
	INT32 sensor_id; /**< Sensor unique number. */
	FLOAT fps; /**< Default frame rate. */
} MPI_AE_PARAM_S;

/**
 * @struct MPI_AE_RESULT_S
 * @brief Defines the results returned by the AE algorithm to the DIP for configuring registers.
 * @note Attributes with hdr prefix record exposure result from short to long frames.
 * ex. hdr_inttime, hdr_sensor_gain, hdr_isp_gain, hdr_sys_gain.
 * @note Index 0 to MPI_SNS_HDR_MAX_IMAGE_NUM - 1 correspond to recording exposure result from short to long frames.
 * @note If MPI_SNS_HDR_MAX_IMAGE_NUM  =  2.
 * * Index 0 contains short frame exposure result.
 * * Index 1 contains long frame exposure result.
 * @note If MPI_SNS_HDR_MAX_IMAGE_NUM  =  3.
 * * Index 0 contains short frame exposure result.
 * * Index 1 contains medium frame exposure result.
 * * Index 2 contains long frame exposure result.
 * @note and so on.
 */
typedef struct mpi_ae_result {
	UINT32 inttime; /**< Integration time. */
	UINT32 sensor_gain; /**< Sensor gain. */
	UINT32 isp_gain; /**< Digital gain. */
	UINT32 sys_gain; /**< System total gain = (sensor_gain) * (isp_gain). */
	UINT32 hdr_inttime[MPI_SNS_HDR_MAX_IMAGE_NUM]; /**< HDR integration time. */
	UINT32 hdr_sensor_gain[MPI_SNS_HDR_MAX_IMAGE_NUM]; /**< HDR sensor gain. */
	UINT32 hdr_isp_gain[MPI_SNS_HDR_MAX_IMAGE_NUM]; /**< HDR digital gain. */
	UINT32 hdr_sys_gain[MPI_SNS_HDR_MAX_IMAGE_NUM]; /**< HDR system total gain = (sensor_gain) * (isp_gain). */
	UINT32 iso; /**< ISO value. */
	UINT8 frame_delay; /**< Delay frame for next AE execution. */
	UINT8 flicker_free_conf; /**< confidence of anti-flicker. */
	FLOAT fps; /**< Frame rate. */
	UINT32 ratio; /**< Ratio between last expousre value and new expousre value. */
	UINT32 exp_ratio; /**< Exposure ratio under HDR mode. */
} MPI_AE_RESULT_S;

/**
 * @brief Defines the statistics of AE algorithm.
 */
typedef struct mpi_ae_stat_1 {
	UINT16 lum_avg; /**< Luma average. */
	UINT32 lum_hist[MPI_LUM_HIST_ENTRY_NUM]; /**< Luma histogram. */
} MPI_AE_STAT_1_S;

/**
 * @brief Defines the extra statistics of AE algorithm.
 */
typedef struct mpi_ae_stat_2 {
	UINT16 luma_avg_bf_pta; /**< Luma average before post tone enhancement. */
	UINT16 luma_avg_aft_pta; /**< Luma average after post tone enhancement. */
	UINT32 luma_hist[MPI_LUMA_HIST_ENTRY_NUM]; /**< Luma histogram. */
} MPI_AE_STAT_2_S;

/**
 * @brief Defines the statistics of AE algorithm. HC17x2 series not support.
 */
typedef struct mpi_ae_stat_3 {
	UINT16 lum_avg; /**< Luma average. */
	UINT32 lum_hist[MPI_LUM_HIST_ENTRY_NUM]; /**< There are 60 bins for the luma histogram.. */
	UINT8 overflow; /**< If overflow happened in any bin, overflow will set as 1. */
} MPI_AE_STAT_3_S;

/**
 * @brief Defines the extra statistics of AE algorithm. HC17x2 series not support.
 */
typedef struct mpi_ae_stat_4 {
	UINT16 roi_lum_avg[MPI_AE_MAX_LUM_AVG_ROI_NUM]; /**< Luma average in each ROI. */
	UINT32 roi_lum_remainder[MPI_AE_MAX_LUM_AVG_ROI_NUM]; /**< Luma remainder in each ROI. */
} MPI_AE_STAT_4_S;

/**
 * @brief Defines the zoned statistics of AE algorithm. HC17x2 series not support.
 */
typedef struct mpi_ae_stat_5 {
	UINT8 zone_lum_avg[MPI_AE_ZONE_NUM]; /**< Luma average in each zone. */
} MPI_AE_STAT_5_S;

/**
 * @brief Structure of auto exposure information.
 */
typedef struct mpi_ae_info {
	UINT32 frame_cnt; /**< Frame count. */
	MPI_AE_STAT_1_S *ae_stat1; /**< The statistics of AE algorithm.. */
	MPI_AE_STAT_2_S *ae_stat2; /**< The extra statistics of AE algorithm. */
	MPI_AWB_STAT_S *awb_stat; /**< The statistics of AWB algorithm. */
	MPI_AE_STAT_3_S *ae_stat3; /**< The statistics of AE algorithm. */
	MPI_AE_STAT_4_S *ae_stat4; /**< The extra statistics of AE algorithm. */
	MPI_AE_STAT_5_S *ae_stat5; /**< The zoned statistics of AE algorithm. */
} MPI_AE_INFO_S;

/**
 * @brief Defines the AE callback function.
 */
typedef struct mpi_ae_callback {
	INT32(*global_init)(MPI_PATH idx, const MPI_AE_PARAM_S *param); /**< Initialize the global context of AE algorithm. */
	INT32(*init)(MPI_PATH idx, const MPI_AE_PARAM_S *param); /**< Initialize the global context of AE algorithm from sensor default. */
	INT32(*run)(MPI_PATH idx, const MPI_AE_INFO_S *stat, MPI_AE_RESULT_S *result, INT32 rsv); /**< Run AE algorithm. */
	VOID (*exit)(MPI_PATH idx); /**< Exit AE algorithm. */
} MPI_AE_CALLBACK_S;

/********************************  AWB  *************************************/

/**
 * @brief Defines the parameters for the AWB algorithm.
 */
typedef struct mpi_awb_param {
	INT32 sensor_id; /**< Sensor unique number. */
	BAYER_E bayer_phase; /**< Default bayer phase. */
} MPI_AWB_PARAM_S;

/**
 * @brief Defines the statistics of AWB algorithm. HC17x2 series not support.
 */
typedef struct mpi_awb_stat_1 {
	UINT32 white[MPI_AWB_CHN_NUM]; /**< Weighed sum of white point energy. */
	UINT32 white_norm[MPI_AWB_CHN_NUM]; /**< Total sum of white point weight. */
	UINT16 max_pix[MPI_AWB_WHITE_POINT_NUM]
	              [MPI_AWB_CHN_NUM]; /**< Top 15 brightest points without sorting of in each bayer phase */
	UINT8 weight[MPI_AWB_WHITE_POINT_NUM]
	            [MPI_AWB_CHN_NUM]; /**< Top 15 weight of brightest points in each bayer phase */
	UINT8 region_x[MPI_AWB_WHITE_POINT_NUM][MPI_AWB_CHN_NUM]; /**< The region x of brightest points */
	UINT8 region_y[MPI_AWB_WHITE_POINT_NUM][MPI_AWB_CHN_NUM]; /**< The region y of brightest points */
} MPI_AWB_STAT_1_S;

/**
 * @brief Defines the zoned statistics of AWB algorithm. HC17x2 series not support.
 */
typedef struct mpi_awb_stat_2 {
	UINT16 zone_max_pix[MPI_AWB_ZONE_NUM][MPI_AWB_CHN_NUM]; /**< Zone based brightest points in each bayer phase */
	UINT8 zone_weight[MPI_AWB_ZONE_NUM]
	                 [MPI_AWB_CHN_NUM]; /**< Weight of zone based brightest points in each bayer phase */
} MPI_AWB_STAT_2_S;

/**
 * @brief Defines the extra statistics of AWB algorithm. HC17x2 series not support.
 */
typedef struct mpi_awb_stat_3 {
	UINT32 roi_sum[MPI_AWB_MAX_PIX_AVG_ROI_NUM][MPI_AWB_CHN_NUM]; /**< Pixel * weight in ROI for each bayer phase */
	UINT32 roi_norm[MPI_AWB_MAX_PIX_AVG_ROI_NUM][MPI_AWB_CHN_NUM]; /**< Weight sum in ROI for each bayer phase */
	UINT32 roi_pix_num[MPI_AWB_MAX_PIX_AVG_ROI_NUM]; /**< Number of pixels within each ROI */
} MPI_AWB_STAT_3_S;

/**
 * @brief Defines the extra zoned statistics of AWB algorithm. HC17x2 series not support.
 */
typedef struct mpi_awb_stat_4 {
	UINT8 r_avg[MPI_AWB_ZONE_NUM]; /**< Zone based average value of R component */
	UINT8 g_avg[MPI_AWB_ZONE_NUM]; /**< Zone based average value of G component */
	UINT8 b_avg[MPI_AWB_ZONE_NUM]; /**< Zone based average value of B component */
} MPI_AWB_STAT_4_S;

/**
 * @brief Structure of white balance information.
 */
typedef struct mpi_awb_info {
	UINT32 frame_cnt; /**< Frame count. */
	MPI_AWB_STAT_S *stat; /**< The statistics of AWB algorithm. */
	MPI_AWB_STAT_1_S *awb_stat1; /**< The statistics of AWB algorithm. */
	MPI_AWB_STAT_2_S *awb_stat2; /**< The zoned statistics of AWB algorithm. */
	MPI_AWB_STAT_3_S *awb_stat3; /**< The extra statistics of AWB algorithm. */
	MPI_AWB_STAT_4_S *awb_stat4; /**< The extra zoned statistics of AWB algorithm. */
} MPI_AWB_INFO_S;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
/**
 * @brief Defines the results returned by the AWB system path to the DIP for configuring registers.
 */
typedef struct mpi_awb_result {
	UINT16 gain0[MPI_AWB_CHN_NUM]; /**< Main path gain of the Gr, R, B,and Gb color channels obtained from the AWB algorithm. */
	UINT16 gain1[MPI_AWB_CHN_NUM]; /**< Sub path gain of the Gr, R, B,and Gb color channels obtained from the AWB algorithm. */
	MPI_AWB_CCM_DOMAIN_E ccm_domain __attribute__((deprecated(
	        "Error: MPI_AWB_RESULT_S::ccm_domain is deprecated. It has never been used internally and can be safely removed.")));
	INT16 matrix[MPI_COLOR_CHN_NUM * MPI_COLOR_CHN_NUM]; /**< Color Correction Matrix. */
	UINT16 color_temp; /**< Color temperature. */
} MPI_AWB_RESULT_S;
#pragma GCC diagnostic pop

/**
 * @brief Defines the AWB algorithm callback function.
 */
typedef struct mpi_awb_callback {
	INT32(*global_init)(MPI_PATH idx, const MPI_AWB_PARAM_S *param); /**< Initialize the global context of AWB algorithm. */
	INT32(*init)(MPI_PATH idx, const MPI_AWB_PARAM_S *param); /**< Initialize the global context of AWB algorithm from sensor default. */
	INT32(*run)(MPI_PATH idx, const MPI_AWB_INFO_S *awb_info, MPI_AWB_RESULT_S *result, INT32 rsv); /**< Run AWB algorithm. */
	VOID (*exit)(MPI_PATH idx); /**< Exit AWB algorithm. */
} MPI_AWB_CALLBACK_S;

/* Interface function prototype */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !MPI_DIP_3A_H_ */
