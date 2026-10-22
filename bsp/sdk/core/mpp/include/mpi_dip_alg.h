/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_dip_alg.h
 * @brief MPI for DIP algorithms
 */

#ifndef MPI_DIP_ALG_H
#define MPI_DIP_ALG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_dip_sns.h"

#pragma GCC diagnostic error "-Wdeprecated-declarations"

#define MPI_FOCUS_ZONE_HOR_NUM (8) /**< Maximum number of regions in a row in the focus statistics. */
#define MPI_FOCUS_ZONE_VER_NUM (8) /**< Maximum number of regions in a column in the focus statistics. */

#define MPI_WB_RB_POINT_NUM (5) /**< Number of points in the White Balance statistics setting. */

#define MPI_FOCUS_HOR_WEIGHT_NUM (10) /**< Number of weightings in horizontal focus statistics. */
#define MPI_FOCUS_VER_WEIGHT_NUM (3) /**< Number of weightings in vertical focus statistics. */

#define MPI_SHP_TRANSFER_CURVE_CTRL_POINT_NUM (6) /**< Number of transfer curve control points in Sharpness */
#define MPI_SHP_LUMA_CTRL_GAIN_POINT_NUM (11) /**<  Number of luma control gain points in Sharpness*/

/**
 * @brief Enumeration of AE frame rate mode.
 */
typedef enum mpi_ae_fps_mode {
	AE_FPS_DROP = 0, /**< Frame-rate drops mode in low-light scene (Slow shutter mode). */
	AE_FPS_FIXED, /**< Fixed frame-rate mode. */
	AE_FPS_NUM,
} MPI_AE_FPS_MODE_E;

/**
 * @brief Enumeration of PTA mode.
 */
typedef enum mpi_pta_mode {
	PTA_NORMAL = 0, /**< Normal mode. */
	PTA_MANUAL, /**< Manual mode. */
	PTA_MODE_NUM,
} MPI_PTA_MODE_E;

/**
 * @brief Enumeration of gamma mode.
 */
typedef enum mpi_gamma_mode {
	GAMMA_BT709 = 0, /**< Gamma BT-709. */
	GAMMA_CRT, /**< Gamma 2.2. */
	GAMMA_MANUAL, /**< Manual gamma curve. */
	GAMMA_MODE_NUM,
} MPI_GAMMA_MODE_E;

/**
 * @brief Enumeration of tone enhancement mode.
 */
typedef enum mpi_te_mode {
	TE_NORMAL = 0, /**< Noramal mode. */
	TE_WDR, /**< Todo: TE_WDR should be marked deprecated after update GCC */
	//  __attribute__((deprecated("Error: MPI_TE_MODE_E::TE_WDR is deprecated. Please use MPI_TE_MODE_E::TE_ADAPT instead."))),
	TE_WDR_AUTO, /**< Todo: TE_WDR_AUTO should be marked deprecated after update GCC */
	//  __attribute__((deprecated("Error: MPI_TE_MODE_E::TE_WDR_AUTO is deprecated. Please use MPI_TE_MODE_E::TE_ADAPT instead."))),
	TE_ADAPT, /**< Adaptive tone enhancement mode*/
	TE_MODE_NUM,
} MPI_TE_MODE_E;

/**
 * @brief Enumeration of AE exposure strategy mode.
 */
typedef enum mpi_ae_exp_strategy_mode {
	AE_EXP_NORMAL = 0, /**< Noramal mode. */
	AE_EXP_HIGHLIGHT_PRIOR, /**< Highlight first exposure mode. */
	AE_STRATEGY_NUM,
} MPI_AE_EXP_STRATEGY_MODE_E;

/**
 * @brief Structure for parameters of weight distribution of AE metering.
 */
typedef struct mpi_ae_roi_weight {
	UINT8 luma_weight; /**< Weight of luma histogram metering. The value range is [0, 255]. Default value: 1 */
	UINT8 awb_weight __attribute__((deprecated(
	        "Error: MPI_AE_ROI_WEIGHT_S::awb_weight is deprecated. Please use MPI_AE_ROI_WEIGHT_S::zone_lum_avg_weight instead.")));
	UINT8 zone_lum_avg_weight; /**< Weight of zone luma average metering. The value range is [0, 255]. Default value: 0 */
} MPI_AE_ROI_WEIGHT_S;

/**
 * @brief Structure for parameters of AE delayed.
 */
typedef struct mpi_ae_delay {
	UINT16 black_delay_frame; /**< Delay frame from dark to bright. The value range is [0, 255]. Default value: 2 */
	UINT16 white_delay_frame; /**< Delay frame frome bright to dark. The value range is [0, 255]. Default value: 0 */
} MPI_AE_DELAY_S;

/**
 * @brief Structure for parameters of AE anti-flicker.
 */
typedef struct mpi_ae_anti_flicker {
	BOOL enable; /**< Moudle anti-flicker enable. Default value: false */
	UINT8 frequency; /**< Anti-flicker frequency. The value range is [1, 255]. Default value: 60 */
	UINT16 luma_delta; /**< Anti-flicker luma delta. The value range is [0, 16383]. Default value: 2000 */
} MPI_AE_ANTI_FLICKER_S;

/**
 * @brief Structure for parameters of AE exposure strategy.
 */
typedef struct mpi_ae_exp_strategy {
	INT32 strength; /**< Strength of highlight first mode. The value range is [0, 255]. Default value: 0 */
	MPI_AE_EXP_STRATEGY_MODE_E
	mode; /**< AE strategy mode(Normal mode or highlight first mode). Default value: 0(noraml mode) */
} MPI_AE_EXP_STRATEGY_S;

/**
 * @brief Structure for parameters of AE manual mode.
 */
typedef struct mpi_ae_manual {
	BOOL is_valid; /**< Enable manual control. Default value: false */
	union {
		UINT32 val; /**< Operation mode. Default value: 0 */
		struct {
			UINT32 exp_value : 1; /**< Exposure value operation mode. */
			UINT32 inttime : 1; /**< Exposure time operation mode. */
			UINT32 sensor_gain : 1; /**< Exposure sensor gain operation mode. */
			UINT32 isp_gain : 1; /**< ISP gain operation mode. */
			UINT32 sys_gain : 1; /**< System gain operation mode. */
		} bit;
	} enable; /**< Enable for union. */
	UINT32 exp_value; /**< Exposure value(5-bit decimal precision). The value range is [0, UINT_MAX]. Default value: 0 */
	UINT32 inttime; /**< Integration time(in microsecond). The value range is [0, 10000000]. Default value: 1000 */
	UINT32 sensor_gain; /**< Exposure sensor gain(5-bit decimal precision). The value range is [32, UINT_MAX]. Default value: 32 */
	UINT32 isp_gain; /**< ISP digital gain(5-bit decimal precision). The value range is [32, UINT_MAX]. Default value: 32 */
	UINT32 sys_gain; /**< System gain = isp_gain * sensor_gain (5-bit decimal precision). The value range is [32, UINT_MAX]. Default value: 32 */
} MPI_AE_MANUAL_S;

/**
 * @brief Structure for parameters of AWB color temperature bias.
 */
typedef struct mpi_awb_color_temp_bias {
	UINT16 k; /**< Color temperature. The value range is [0, 15000]. */
	INT8 color_tolerance_bias __attribute__((deprecated(
	        "Error: MPI_AWB_COLOR_TEMP_BIAS_S::color_tolerance_bias is deprecated. It has never been used internally and can be safely removed.")));
	INT8 wht_weight_bias; /**< Bias of wht_weight. The value range is [-127, 127]. */
	INT8 gwd_weight_bias; /**< Bias of gwd_weight. The value range is [-127, 127]. */
	INT8 r_extra_gain_bias; /**< Bias of r_extra_gain. The value range is [-127, 127]. */
	INT8 g_extra_gain_bias; /**< Bias of g_extra_gain. The value range is [-127, 127]. */
	INT8 b_extra_gain_bias; /**< Bias of b_extra_gain. The value range is [-127, 127]. */
} MPI_AWB_COLOR_TEMP_BIAS_S;

/**
 * @struct MPI_ROI_ATTR_S
 * @brief Defines the region of interest(ROI) attribute.
 * @note
 * @arg The default ROI is set to full range, as follow:
 * @code{.c}
 * {
 *     .luma_roi = {
 *         .sx = 0,
 *         .sy = 0,
 *         .ex = 1024,
 *         .ey = 1024,
 *     },
 *     .awb_roi = {
 *         .sx = 0,
 *         .sy = 0,
 *         .ex = 1024,
 *         .ey = 1024,
 *     },
 *     .zone_lum_avg_roi = {
 *         .sx = 0,
 *         .sy = 0,
 *         .ex = 1024,
 *         .ey = 1024,
 *     },
 * }
 * @endcode
 * @see MPI_getRoiAttr()
 * @see MPI_setRoiAttr()
 * @property MPI_RECT_POINT_S MPI_ROI_ATTR_S::luma_roi
 * @note
 * @arg The value of `luma_roi.sx`, `luma_roi.sy`, `luma_roi.ex` and `luma_roi.ey` must be in range [::MPI_MIN_DIP_ROI_VAL, ::MPI_MAX_DIP_ROI_VAL].
 * @arg It is recommended that the luma_roi use default value.
 * @property MPI_RECT_POINT_S MPI_ROI_ATTR_S::awb_roi
 * @note
 * @arg The value of `awb_roi.sx`, `awb_roi.sy`, `awb_roi.ex` and `awb_roi.ey` must be in range [::MPI_MIN_DIP_ROI_VAL, ::MPI_MAX_DIP_ROI_VAL].
 * @arg It is recommended that the awb_roi use default value.
 * @property MPI_RECT_POINT_S MPI_ROI_ATTR_S::awb_roi
 * @note
 * @arg The value of `zone_lum_avg_roi.sx`, `zone_lum_avg_roi.sy`, `zone_lum_avg_roi.ex` and `zone_lum_avg_roi.ey` must be in range [::MPI_MIN_DIP_ROI_VAL, ::MPI_MAX_DIP_ROI_VAL].
 * @arg It is recommended that the zone_lum_avg_roi use default value.
 */
typedef struct mpi_roi_attr {
	MPI_RECT_POINT_S luma_roi; /**< The interesting region is setting by luma ROI. It will affect the statistics of luma histogram. */
	MPI_RECT_POINT_S awb_roi; /**< The interesting region is setting by Awb ROI. It will affect the statistics of luma average. */
	MPI_RECT_POINT_S zone_lum_avg_roi; /**< The interesting region is setting by zone luma average ROI. It will affect the statistics of zone luma average. */
} MPI_ROI_ATTR_S;

/**
 * @brief Enumeration of AE zone weight table mode.
 * @note
 * @arg The ::MPI_AE_ZONE_WEIGHT_TABLE_MODE_AVG as follow:
 * @code{.c}
 * {
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 * }
 * @endcode
 * @arg The ::MPI_AE_ZONE_WEIGHT_TABLE_MODE_CENTRAL as follow:
 * @code{.c}
 * {
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,2,2,1,1,1},
 *     {1,1,2,3,3,2,1,1},
 *     {1,2,3,4,4,3,2,1},
 *     {1,2,3,4,4,3,2,1},
 *     {1,1,2,3,3,2,1,1},
 *     {1,1,1,2,2,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 * }
 * @endcode
 * @arg The ::MPI_AE_ZONE_WEIGHT_TABLE_MODE_SPOT as follow:
 * @code{.c}
 * {
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,2,2,1,1,1},
 *     {1,1,1,2,2,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 *     {1,1,1,1,1,1,1,1},
 * }
 * @endcode
 */
typedef enum mpi_ae_zone_weight_mode {
	MPI_AE_ZONE_WEIGHT_TABLE_MODE_AVG = 0, /**< Using average metering weight table mode. */
	MPI_AE_ZONE_WEIGHT_TABLE_MODE_CENTRAL, /**< Using central metering weight table mode. */
	MPI_AE_ZONE_WEIGHT_TABLE_MODE_SPOT, /**< Using spot metering weight table mdoe. */
	MPI_AE_ZONE_WEIGHT_TABLE_MODE_MANUAL, /**< Using manual zone weight table mode. */
	MPI_AE_ZONE_WEIGHT_TABLE_MODE_NUM,
} MPI_AE_ZONE_WEIGHT_TABLE_MODE_E;

/**
 * @brief Structure for parameters of AE zone weight table.
 */
typedef struct mpi_ae_zone_weight_table {
	MPI_AE_ZONE_WEIGHT_TABLE_MODE_E
	mode; /**< Zone weigtht table mode for zone luma average metering(average, central, spot or manual mode). Default value: 0(average mode) */
	UINT8 manual_table[MPI_AE_ZONE_ROW][MPI_AE_ZONE_COLUMN]; /**< Manual zone weight table if mode is manual. */
} MPI_AE_ZONE_WEIGHT_TABLE_S;

/**
 * @struct MPI_AE_ATTR_S
 * @brief Defines auto exposure(AE) attribute.
 * @see MPI_getAeAttr()
 * @see MPI_setAeAttr()
 * @property MPI_AE_EXP_STRATEGY_S MPI_AE_ATTR_S::strategy
 * @note
 * @arg The default ::MPI_AE_ATTR_S::strategy as follow:
 * @code{.c}
 * {
 *      .mode = AE_EXP_NORMAL,
 *      .strength = 0,
 * }
 * @endcode
 * @property MPI_AE_ROI_WEIGHT_S MPI_AE_ATTR_S::roi
 * @note
 * @arg The default ::MPI_AE_ATTR_S::roi as follow:
 * @code{.c}
 * {
 *     .luma_weight = 1,
 *     .awb_weight = 1,
 * }
 * @endcode
 * @property MPI_AE_DELAY_S MPI_AE_ATTR_S::delay
 * @note
 * @arg The default ::MPI_AE_ATTR_S::delay as follow:
 * @code{.c}
 * {
 *     .black_delay_frame = 2,
 *     .white_delay_frame = 0,
 * }
 * @endcode
 * @property MPI_AE_ANTI_FLICKER_S MPI_AE_ATTR_S::anti_flicker
 * @note
 * @arg The default ::MPI_AE_ATTR_S::anti_flicker as follow:
 * @code{.c}
 * {
 *     .enable = 0,
 *     .frequency = 60,
 *     .luma_delta = 2000,
 * }
 * @endcode
 * @property RANGE_S MPI_AE_ATTR_S::sys_gain_range
 * @note
 * @arg This attribute will be adjusted by the video system if maximum/minimum sensor_gain * isp_gain is lesser/greater than sys_gain.
 * @endcode
 * @property RANGE_S MPI_AE_ATTR_S::sensor_gain_range
 * @note
 * @arg This attribute will be adjusted by the video system with the capability of the sensor.
 */
typedef struct mpi_ae_attr {
	RANGE_S sys_gain_range; /**< Range of system gain (5-bit decimal precision). The acceptable range of the values is [32, UINT_MAX]. */
	RANGE_S sensor_gain_range; /**< Range of sensor gain (5-bit decimal precision). The acceptable range of the values is [32, UINT_MAX]. */
	RANGE_S isp_gain_range; /**< Range of isp gain (5-bit decimal precision). The acceptable range of the values is [32, UINT_MAX]. */
	FLOAT frame_rate; /**< Target FPS. The specific value is related to the sensor. */
	FLOAT slow_frame_rate; /**< Slow frame-rate setting. The specific value is related to the sensor. */
	UINT8 speed; /**< Convergence speed. The value range is [0, 255]. Default value: 128 */
	UINT8 black_speed_bias; /**< Bias of convergence speed from dark to bright. The value range is [0, 255]. Default value: 128 */
	UINT8 interval; /**< Interval between two executions. The value range is [0, 255]. Default value: 0 */
	UINT16 brightness; /**< Target brightness. The value range is [0, 16383]. Default value: 7000 */
	UINT16 tolerance; /**< Brightness tolerance. The value range is [0, 16383]. Default value: 1280 */
	UINT32 gain_thr_up; /**< System gain for increasing frame-rate. It must be less than ::MPI_AE_ATTR_S::gain_thr_down. The value range is [0, ::MPI_AE_ATTR_S::gain_thr_down]. Default value: 96 */
	UINT32 gain_thr_down; /**< System gain for reducing frame-rate. The value range is [0, UINT_MAX]. Default value: 288 */
	MPI_AE_EXP_STRATEGY_S strategy; /**< Exposure strategy parameters. */
	MPI_AE_ROI_WEIGHT_S roi; /**< ROI weight parameters. */
	MPI_AE_DELAY_S delay; /**< Delay parameters. */
	MPI_AE_ANTI_FLICKER_S anti_flicker; /**< Anti-flicker parameters. */
	MPI_AE_FPS_MODE_E fps_mode; /**< Frame-rate mode. (Slow shutter mode or fixed fps mode) Default value: 1 (fixed fps mode) */
	MPI_AE_MANUAL_S manual; /**< Manual setting. */
	MPI_AE_ZONE_WEIGHT_TABLE_S zone_weight; /**< Weight table of zone luma average metering */
	RANGE_S inttime_range; /**< Integration time range. In range [0, 10000000] with some logical constraints related to the sensor. */
} MPI_AE_ATTR_S;

/**
 * @struct MPI_CAL_ATTR_S
 * @brief Defines calibration(CAL) module attribute.
 * @details
 * The value 0 indicates that disable module. Output = Input.
 * The value 1 indicates that enable module. Output = Algotithm(Input).
 * The value 2 indicates that bypass module. The output will not be updated. The last frame setting will be apply.
 * @see MPI_getCalAttr()
 * @see MPI_setCalAttr()
 */
typedef struct mpi_cal_attr {
	UINT8 cal_en; /**< Enable CAL module. The value range is [0, 2]. Default value: 1 */
	UINT8 dbc_en; /**< Enable DBC module. The value range is [0, 2]. Default value: 1 */
	UINT8 dcc_en; /**< Enable DCC module. The value range is [0, 2]. Default value: 1 */
	UINT8 lsc_en; /**< Enable LSC module. The value range is [0, 2]. Default value: 1 */
} MPI_CAL_ATTR_S;

/**
 * @brief Enumeration of device color correction algorithm opreating type.
 */
typedef enum mpi_dcc_type {
	DCC_TYPE = 0, /**<  Use origin gain and offset. */
	DCC_TYPE_EX, /**< Use new manual and auto data structure. */
	DCC_TYPE_NUM,
} MPI_DCC_TYPE_E
        __attribute__((deprecated(
                "Error: MPI_DCC_TYPE_E is deprecated. It has never been used internally and can be safely removed.")));

/**
 * @brief Structure for parameters of DCC line.
 */
typedef struct mpi_dcc_line {
	UINT16 gain[MPI_DCC_CHN_NUM]; /**< Gain value. The value range is [0, 4095]. */
	INT32 offset_2s[MPI_DCC_CHN_NUM]; /**< Offset. The value range is [-65536, 65535]. */
} MPI_DCC_LINE_S;

/**
 * @brief Structure for parameters of manual dcc.
 */
typedef struct mpi_dcc_manual {
	MPI_DCC_LINE_S manual; /**< Manual dcc line. */
} MPI_DCC_MANUAL_S;

/**
 * @brief Structure for parameters of auto dcc.
 */
typedef struct mpi_dcc_auto {
	MPI_DCC_LINE_S auto_table[MPI_SYS_GAIN_ENTRY_NUM]; /**< Auto dcc line. */
} MPI_DCC_AUTO_S;

/**
 * @brief Enumeration of device black-level correction algorithm opreating type.
 */
typedef enum mpi_dbc_type {
	DBC_TYPE_CHN_SAME_BLACK_LEVEL = 0, /**< All channel using same black level. */
	DBC_TYPE_CHN_IND_BLACK_LEVEL, /**< Each channel using independent black level. */
	DEC_TYPE_NUM,
} MPI_DBC_TYPE_E
        __attribute__((deprecated(
                "Error: MPI_DBC_TYPE_E is deprecated. It has never been used internally and can be safely removed.")));

/**
 * @brief Structure for parameters of DBC black level.
 */
typedef struct mpi_dbc_level {
	UINT16 black_level[MPI_DBC_CHN_NUM]; /**< Black level by channel. The value range is [0, 65535].*/
} MPI_DBC_BLACK_LEVLE_S;

/**
 * @brief Structure for parameters of manual dbc.
 */
typedef struct mpi_dbc_manual {
	MPI_DBC_BLACK_LEVLE_S manual; /**< Manual black level. */
} MPI_DBC_MANUAL_S;

/**
 * @brief Structure for parameters of auto dbc.
 */
typedef struct mpi_dbc_auto {
	MPI_DBC_BLACK_LEVLE_S auto_table[MPI_SENSOR_GAIN_LUT_ENTRY_NUM]; /**< Auto black level. */
} MPI_DBC_AUTO_S;

/**
 * @struct MPI_LSC_ATTR_S
 * @brief Defines lens shadding correction(LSC) attribute.
 * @details
 * The default LSC attributes can be obtained through lens-calibration tool.
 * @see MPI_getLscAttr()
 * @see MPI_setLscAttr()
 */
typedef struct mpi_lsc_attr {
	INT32 origin; /**< LSC gain at origin. The value range is [0, INT32_MAX]. */
	UINT32 x_trend_2s; /**< LSC gain trend in X direction. The value range is [0, UINT32_MAX]. */
	UINT32 y_trend_2s; /**< LSC gain trend in Y direction. The value range is [0, UINT32_MAX]. */
	UINT32 x_curvature; /**< LSC gain curvature in X direction. The value range is [0, UINT32_MAX]. */
	UINT32 y_curvature; /**< LSC gain curvature in Y direction. The value range is [0, UINT32_MAX]. */
	INT32 tilt_2s; /**< LSC gain curve tilt extent. The value range is [0, INT32_MAX]. */
} MPI_LSC_ATTR_S;

/**
 * @brief Structure for parameters of automatic effective iso.
 * @details
 * The values of effective_iso imply the strength of raw noises. Higher the iso values are, more noise the sensor produces.
 */
typedef struct mpi_iso_auto {
	INT32 effective_iso[MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic effective iso table. The value range is [0, INT_MAX]. */
} MPI_ISO_AUTO_S;

/**
 * @brief Structure for parameters of manual effective iso.
 * @details The value of effective_iso implies the strength of raw noises. Higher the iso values are, more noise the sensor produces.
 */
typedef struct mpi_iso_manual {
	INT32 effective_iso; /**< Manual effective iso. The value range is [0, INT_MAX]. Default value: 100 */
} MPI_ISO_MANUAL_S;

/**
 * @brief Enumeration of iso definition.
 */
typedef enum mpi_iso_type {
	MPI_ISO_VER_0 = 0, /**< Todo: MPI_ISO_VER_0 should be marked deprecated after update GCC */
	// __attribute__((deprecated("Error: MPI_ISO_TYPE_E::MPI_ISO_VER_0 is deprecated. Please use MPI_ISO_TYPE_E::MPI_ISO_VER_1 instead."))) = 0,
	MPI_ISO_VER_1 = 1, /**< Version 1 of ISO definition (11 entries), usually in range [0, 8192] */
	MPI_ISO_VER_2 = 2, /**< Version 2 of ISO definition (16 entries), usually in range [0, 8192] */
} MPI_ISO_TYPE_E;

/**
 * @brief Structure of attributes for Distortion-aware Adaptation controls.
 * @details Distortion-aware Adaptation can be enabled only if ::MPI_ISO_ATTR_S::iso_type = 1
 */
typedef struct mpi_iso_daa {
	INT32 di_max; /**< Maximum value of the distortion index. In range [0, 3000]. */
	UINT16 di_rising_speed; /**< Adjusting speed while increasing distortion index. In range [0, 256] */
	UINT16 di_fallen_speed; /**< Adjusting speed while decreasing distortion index. In range [0, 256] */
	UINT16 qp_upper_th; /**< QP value which scene is considered as a distorted image. In range [0, 51]. */
	UINT16 qp_lower_th; /**< QP value which scene is considered as a normal image. In range [0, 51]. Should be less than or equal to qp_upper_th. */
	UINT8 enable; /**< Enable distortion-aware scene adaptation. Should be 0 or 1, default value is 0. */
} MPI_ISO_DAA_S __attribute__((deprecated(
        "Error: MPI_ISO_DAA_S is deprecated. It has never been used internally and can be safely removed.")));

/**
 * @brief Structure for paramters of automatic post tone adjustment.
 */
typedef struct mpi_pta_auto {
	UINT32 tone[MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic tone table. The value range is [0, 1024].*/
} MPI_PTA_AUTO_S;

/**
 * @brief Structure for paramters of manual post tone adjustment.
 */
typedef struct mpi_pta_manual {
	UINT32 curve[MPI_PTA_CURVE_ENTRY_NUM]; /**< Manual tone curve. The value range is [0, 1024]. */
} MPI_PTA_MANUAL_S;

/**
 * @struct MPI_PTA_ATTR_S
 * @brief Defines post tone adjustment(PTA) attribute.
 * @see MPI_getPtaAttr()
 * @see MPI_setPtaAttr()
 * @property MPI_PTA_AUTO_S MPI_PTA_ATTR_S::pta_auto
 * @note
 * @arg The default ::MPI_PTA_ATTR_S::pta_auto as follow:
 * @code{.c}
 * .tone = {
 *     1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024,
 * },
 * @endcode
 * @property MPI_PTA_MANUAL_S MPI_PTA_ATTR_S::pta_manual
 * @note
 * @arg The default ::MPI_PTA_ATTR_S::pta_manual as follow:
 * @code{.c}
 * {
 *     .curve = {
 *           0,   32,   64,   96,  128,  160,  192,  224,  256,  288,  320,
 *         352,  384,  416,  448,  480,  512,  544,  576,  608,  640,  672,
 *         704,  736,  768,  800,  832,  864,  896,  928,  960,  992, 1024,
 *     },
 * }
 * @endcode
 */
typedef struct mpi_pta_attr {
	MPI_PTA_MODE_E mode; /**< Post tone adjustment mode(Normal mode or manual mode). Default value: 0(Normal mode) */
	UINT8 brightness; /**< Brightness strength. The value range is [0, 255]. Default value: 128 */
	UINT8 contrast; /**< Contrast strength. The value range is [0, 255]. Default value: 128 */
	UINT8 break_point; /**< The breakpoint of contrast strength. The value range is [0, 255]. Default value: 64 */
	MPI_PTA_AUTO_S pta_auto; /** < Automatic post tone adjustment parameter. */
	MPI_PTA_MANUAL_S pta_manual; /** < Manual post tone adjustment parameter. */
} MPI_PTA_ATTR_S;

/**
 * @brief Structure for paramters of automatic color saturation.
 */
typedef struct mpi_csm_auto {
	UINT8 saturation[MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic saturation. In range [0, 255]. */
} MPI_CSM_AUTO_S;

/**
 * @brief Structure for paramters of manual color saturation.
 */
typedef struct mpi_csm_manual {
	UINT8 saturation; /**< Manual saturation. In range [0, 255]. Default value: 128. */
} MPI_CSM_MANUAL_S;

/**
 * @brief Structure of CST matrix used for convert RGB to YUV
 * @note The CST matrix follows this relation:
 * @code{.c}
 * y = (coeff[0] * r + coeff[1] * g + coeff[2] * b) / 2048 + offset[0]
 * u = (coeff[3] * r + coeff[4] * g + coeff[5] * b) / 2048 + offset[1]
 * v = (coeff[6] * r + coeff[7] * g + coeff[8] * b) / 2048 + offset[2]
 * @endcode
 * Both RGB and YUV values are unsigned 10bit integers in [0, 1023].
 */
typedef struct mpi_cst_matrix_s {
	INT16 coeff[MPI_COLOR_CHN_NUM * MPI_COLOR_CHN_NUM]; /**< Coefficients of the matrix. In range [-8192, 8191]. */
	INT16 offset[MPI_COLOR_CHN_NUM]; /**< Offset of the output color channels. In range [-1024, 1023]. */
} MPI_CST_MATRIX_S;

/**
 * @struct MPI_CSM_ATTR_S
 * @brief Defines color saturation management(CSM) attribute.
 * @see MPI_getCsmAttr()
 * @see MPI_setCsmAttr()
 * @property MPI_CSM_AUTO_S MPI_CSM_ATTR_S::csm_auto
 * @note
 * @arg The default values of ::MPI_CSM_ATTR_S::csm_auto are:
 * @code{.c}
 * {
 *   .saturation = {
 *     128, 128, 120, 115, 100, 95, 90, 75, 32, 16, 0,
 *   },
 * }
 * @endcode
 * @property MPI_CST_MATRIX_S MPI_CSM_ATTR_S::cst_color
 * @note
 * @arg The default values of ::MPI_CSM_ATTR_S::cst_color are:
 * @code{.c}
 * {
 *   .coeff = {
 *      436, 1464,  148,
 *     -240, -807, 1047,
 *     1047, -951,  -96,
 *   },
 *   .offset = {
 *        0,  512,  512,
 *   }
 * }
 * @endcode
 * @property MPI_CST_MATRIX_S MPI_CSM_ATTR_S::cst_bw
 * @note
 * @arg The default values of ::MPI_CSM_ATTR_S::cst_bw are:
 * @code{.c}
 * {
 *   .coeff = {
 *        0, 2048,    0,
 *        0,    0,    0,
 *        0,    0,    0,
 *   },
 *   .offset = {
 *        0,  512,  512,
 *   }
 * }
 * @endcode
 */
typedef struct mpi_csm_attr_s {
	UINT8 bw_en; /**< Enable black-and-white mode. Should either be 0 or 1. Default value: 0. */
	INT16 hue_angle; /**< Hue angle. In range [-240, 240]. Default value: 0. */
	MPI_ALG_OPT_E mode; /**< Operating mode. Should either be 0 (Auto) or 2 (Manual). Default value: 0. */
	MPI_CSM_AUTO_S csm_auto; /**< Automatic saturation parameter. */
	MPI_CSM_MANUAL_S csm_manual; /**< Manual saturation parameter. */
	MPI_CST_MATRIX_S cst_color; /**< Matrix used for converting RGB to YUV when ::MPI_CSM_ATTR_S::bw_en = 0. */
	MPI_CST_MATRIX_S cst_bw; /**< Matrix used for converting RGB to YUV when ::MPI_CSM_ATTR_S::bw_en = 1. */
	UINT8 cst_auto_en; /**< Enable cst matrix adaptive. Should either be 0 or 1. Default value: 0. */
	MPI_CST_MATRIX_S cst_auto[MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic cst matrix. */
} MPI_CSM_ATTR_S;

/**
 * @brief Structure for paramters of automatic sharpness.
 */
typedef struct mpi_shp_auto {
	UINT8 sharpness[MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic sharpness. The value range is [0, 255]. */
} MPI_SHP_AUTO_S;

/**
 * @brief Structure for paramters of manual sharpness.
 */
typedef struct mpi_shp_manual {
	UINT8 sharpness; /**< Manual Sharpness. The value range is [0, 255]. Default value: 0 */
} MPI_SHP_MANUAL_S;

/**
 * @struct MPI_SHP_ATTR_S
 * @brief Defines sharpness(SHP) attribute.
 * @see MPI_getShpAttr()
 * @see MPI_setShpAttr()
 * @property MPI_SHP_AUTO_S MPI_SHP_ATTR_S::shp_auto
 * @note
 * @arg The default ::MPI_SHP_ATTR_S::shp_auto as follow:
 * @code{.c}
 * {
 *     .sharpness = {
 *         128, 128, 120, 115, 100, 95, 90, 75, 32, 16, 0,
 *     },
 * }
 * @endcode
 */
typedef struct mpi_shp_attr {
	MPI_ALG_OPT_E mode; /**< Sharpness mode(Auto mode or manual mode). Default value: 0(Auto mode) */
	MPI_SHP_AUTO_S shp_auto; /**< Manual sharpness parameter. */
	MPI_SHP_MANUAL_S shp_manual; /**< Automatic sharpness parameter. */
} MPI_SHP_ATTR_S
        __attribute__((deprecated("Error: MPI_SHP_ATTR_S is deprecated. Please use MPI_SHP_ATTR_V2_S instead.")));

/**
 * @brief Structure for paramters of automatic sharpness V2.
 */
typedef struct mpi_shp_auto_v2 {
	INT16 sharpness[MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic sharpness V2. The value range is [0, 511]. */
} MPI_SHP_AUTO_V2_S
        __attribute__((deprecated("Error: MPI_SHP_AUTO_V2_S is deprecated. Please use MPI_SHP_EX_AUTO_S instead.")));

/**
 * @brief Structure for paramters of manual sharpness V2.
 */
typedef struct mpi_shp_manual_v2 {
	INT16 sharpness; /**< Manual sharpness V2. The value range is [0, 511]. Default value: 0 */
} MPI_SHP_MANUAL_V2_S __attribute__((
        deprecated("Error: MPI_SHP_MANUAL_V2_S is deprecated. Please use MPI_SHP_EX_MANUAL_S instead.")));

/**
 * @brief Structure for parameters of SHP transfer curve.
 */
typedef struct mpi_shp_transfer_curve {
	INT32 x[MPI_SHP_TRANSFER_CURVE_CTRL_POINT_NUM]; /**< Curve bin. The value range is [0, 1023]. */
	INT32 y[MPI_SHP_TRANSFER_CURVE_CTRL_POINT_NUM]; /**< Curve value. The value range is [0, 1023]. */
} MPI_SHP_TRANSFER_CURVE_S;

/**
 * @brief Structure for parameters of SHP luma control gain.
 */
typedef struct mpi_luma_ctrl_gain {
	INT32 x[MPI_SHP_LUMA_CTRL_GAIN_POINT_NUM]; /**< Curve bin. The value range is [0, 1023]. */
	INT32 y[MPI_SHP_LUMA_CTRL_GAIN_POINT_NUM]; /**< Curve value. The value range is [0, 32]. */
} MPI_SHP_LUMA_CTRL_GAIN_S;

/**
 * @brief Structure for parameters of auto extend type SHP .
 */
typedef struct mpi_shp_ex_auto {
	INT32 hpf_ratio[MPI_ISO_LUT_ENTRY_NUM]; /**< High pass frequency ratio. In range [0, 255]. Default: 0. */
	MPI_SHP_TRANSFER_CURVE_S transfer_curve[MPI_ISO_LUT_ENTRY_NUM]; /**< Sharpness strength transfer curve. */
	MPI_SHP_LUMA_CTRL_GAIN_S luma_ctrl_gain[MPI_ISO_LUT_ENTRY_NUM]; /**< Sharpening strength with pixel brightness. */
	UINT8 soft_clip_slope
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Sharpening control for reducing pixel flashing. In range [0, 31]. default: 16. */
} MPI_SHP_EX_AUTO_S;

/**
 * @brief Structure for parameters of manual extend type SHP.
 */
typedef struct mpi_shp_ex_manual {
	INT32 hpf_ratio; /**< High pass frequency ratio. In range [0, 255]. Default: 0. */
	MPI_SHP_TRANSFER_CURVE_S transfer_curve; /**< Sharpness strength transfer curve. */
	MPI_SHP_LUMA_CTRL_GAIN_S luma_ctrl_gain; /**< Sharpening strength with pixel brightness. */
	UINT8 soft_clip_slope; /**< Sharpening control for reducing pixel flashing. In range [0, 31]. Default: 16. */
} MPI_SHP_EX_MANUAL_S;

/**
 * @brief Enumeration of SHP algorithm operating type.
 */
typedef enum mpi_shp_type {
	SHP_TYPE = 0,
	SHP_TYPE_EX, /**< Second type (extend type) SHP algorithm */
	SHP_TYPE_NUM,
} MPI_SHP_TYPE_E
        __attribute__((deprecated(
                "Error: MPI_SHP_TYPE_E is deprecated. It has never been used internally and can be safely removed.")));

/**
 * @brief Structure for paramters of automatic noise reduction.
 */
typedef struct mpi_nr_auto {
	UINT8 y_level_3d
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic 3d noise reduction luma level. The value range is [0, 255]. */
	UINT8 c_level_3d
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic 3d noise reduction chroma level. The value range is [0, 255]. */
	UINT8 y_level_2d
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic 2d noise reduction luma level. The value range is [0, 255]. */
	UINT8 c_level_2d
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic 2d noise reduction chroma level. The value range is [0, 255]. */
	UINT8 fss_y_level_3d
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic 3d noise reduction luma level when max threshold of full screen
	                                      static ratio. Valid when me_frame_fallback_en = 1. The value range is
	                                      [0, 255]. */
} MPI_NR_AUTO_S;

/**
 * @brief Structure for paramters of manual noise reduction.
 */
typedef struct mpi_nr_manual {
	UINT8 y_level_3d; /**< Manual 3d noise reduction luma level. The value range is [0, 255]. Default value: 128 */
	UINT8 c_level_3d; /**< Manual 3d noise reduction chroma level. The value range is [0, 255]. Default value: 128 */
	UINT8 y_level_2d; /**< Manual 2d noise reduction luma level. The value range is [0, 255]. Default value: 128 */
	UINT8 c_level_2d; /**< Manual 2d noise reduction chroma level. The value range is [0, 255]. Default value: 128 */
	UINT8 fss_y_level_3d; /**< Manual 3d noise reduction luma level when max threshold of full screen static ratio.
	                           Valid when me_frame_fallback_en = 1. The value range is [0, 255]. */
} MPI_NR_MANUAL_S;

/**
 * @brief Enumeration of NR look-up table type.
 */
typedef enum mpi_nr_lut_type {
	NR_LUT_TYPE_0 = 0, /**< First NR look-up table type */
	NR_LUT_TYPE_1, /**< Second NR look-up table type */
	NR_LUT_TYPE_2, /**< Third NR look-up table type */
	NR_LUT_TYPE_3, /**< Fourth NR look-up table type */
	NR_LUT_TYPE_NUM,
} MPI_NR_LUT_TYPE_E;

/**
 * @struct MPI_NR_ATTR_S
 * @brief Defines noise reduction(NR) attribute.
 * @see MPI_getNrAttr()
 * @see MPI_setNrAttr()
 * @property MPI_NR_AUTO_S MPI_NR_ATTR_S::nr_auto
 * @note
 * @arg The default ::MPI_NR_ATTR_S::nr_auto as follow:
 * @code{.c}
 * {
 *     .y_level_3d = {
 *         0, 3, 8, 19, 40, 83, 169, 255, 255, 255, 255,
 *     },
 *     .c_level_3d = {
 *         0, 3, 8, 19, 40, 83, 169, 255, 255, 255, 255,
 *     },
 *     .y_level_2d = {
 *         0, 3, 8, 19, 40, 83, 169, 255, 255, 255, 255,
 *     },
 *     .c_level_2d = {
 *         0, 3, 8, 19, 40, 83, 169, 255, 255, 255, 255,
 *     },
 * }
 * @endcode
 */
typedef struct mpi_nr_attr {
	MPI_ALG_OPT_E mode; /**< Noise reduction mode(Auto mode or manual mode). Default value: 0(Auto mode) */
	MPI_NR_AUTO_S nr_auto; /**< Automatic noise reduction parameter. */
	MPI_NR_MANUAL_S nr_manual; /**< Manual noise reduction parameter. */
	UINT8 motion_comp; /**< Motion compensate. The value range is [0, 31]. Default value: 2 */
	UINT8 trail_suppress __attribute__((deprecated(
	        "Error: MPI_NR_ATTR_S::trail_suppress is deprecated. It has never been used internally and can be safely removed.")));
	UINT8 ghost_remove __attribute__((deprecated(
	        "Error: MPI_NR_ATTR_S::ghost_remove is deprecated. It has never been used internally and can be safely removed.")));
	UINT8 ma_y_strength; /**< 3DNR motion adaptive luma lookup table max ratio value. The value range is [0, 31]. Default value: 26 */
	UINT8 mc_y_strength; /**< 3DNR motion compensate chroma lookup table max ratio value. The value range is [0, 31]. Default value: 30 */
	UINT8 ma_c_strength; /**< 3DNR motion adaptive chroma lookup table max ratio value. The value range is [0, 31]. Default value: 24 */
	UINT8 ratio_3d; /**< 3DNR component ratio. The value range is [0, 4]. Default value: 4 */
	INT16 mc_y_level_offset; /**< 3DNR motion compensate luma level offset. The value range is [-255, 255]. Default value: 0 */
	UINT8 me_frame_fallback_en; /**< Enable ME frame fallback (Enhance 3DNR when full screen static). The value range
	                                 is [0, 1]. Default value: 0 */
	UINT16 fss_ratio_min; /**< Min threshold of full screen static ratio. Valid when me_frame_fallback_en = 1.
	                           The value range is [0, 1024]. Default value: 993 */
	UINT16 fss_ratio_max; /**< Max threshold of full screen static ratio. Valid when me_frame_fallback_en = 1.
	                           The value range is [0, 1024]. Default value: 1014 */
	MPI_NR_LUT_TYPE_E lut_type; /**< Look-up table type. */
} MPI_NR_ATTR_S;

/**
 * @brief Structure for paramters of automatic coring.
 */
typedef struct mpi_coring_auto {
	UINT16 abs_th[MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic coring absolute threshold. The value range is [0, 1023]. */
} MPI_CORING_AUTO_S;

/**
 * @brief Structure for paramters of manual coring.
 */
typedef struct mpi_coring_manual {
	UINT16 abs_th; /**< Manual coring absolute threshold. The value range is [0, 1023]. Default value: 128 */
} MPI_CORING_MANUAL_S;

/**
 * @struct MPI_CORING_ATTR_S
 * @brief Defines coring(CORING) attribute.
 * @see MPI_getCoringAttr()
 * @see MPI_setCoringAttr()
 * @property MPI_CORING_AUTO_S MPI_CORING_ATTR_S::coring_auto
 * @note
 * @arg The default ::MPI_CORING_ATTR_S::coring_auto as follow:
 * @code{.c}
 * .abs_th = {
 *     20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
 * },
 * @endcode
 */
typedef struct mpi_coring_attr {
	MPI_ALG_OPT_E mode; /**< Coring mode(Auto mode or manual mode). Default value: 0(Auto mode). */
	MPI_CORING_AUTO_S coring_auto; /**< Automatic coring parameter. */
	MPI_CORING_MANUAL_S coring_manual; /**< Manual coring parameter. */
	UINT16 coring_slope; /**< Coring slope. The value range is [0, 4095]. Default value: 0 */
} MPI_CORING_ATTR_S;

/**
 * @brief Structure of the gamma curve for manual mode
 */
typedef struct mpi_gamma_curve {
	UINT16 curve[MPI_GAMMA_CURVE_ENTRY_NUM]; /**< Manual curve. The value range is [0, 16384]. */
} MPI_GAMMA_CURVE_S;

/**
 * @struct MPI_GAMMA_ATTR_S
 * @brief Defines gamma(GAMMA) attribute.
 * @see MPI_getGammaAttr()
 * @see MPI_setGammaAttr()
 * @property MPI_GAMMA_CURVE_S MPI_GAMMA_ATTR_S::gma_manual
 * @note
 * @arg The default ::MPI_GAMMA_ATTR_S::gma_manual as follow:
 * @code{.c}
 * .curve = {
 *        0,   288,   576,   864,  1152,  1442,  1704,  1943,  2163,  2563,
 *     2921,  3247,  3549,  3830,  4095,  4346,  4584,  4811,  5030,  5239,
 *     5442,  5637,  5826,  6010,  6188,  6530,  6855,  7166,  7464,  7751,
 *     8027,  8294,  8552,  8803,  9046,  9283,  9514,  9739,  9959, 10173,
 *    10383, 10790, 11182, 11559, 11924, 12277, 12619, 12951, 13275, 13590,
 *    13897, 14198, 14491, 14778, 15059, 15334, 15604, 15869, 16129, 16384,
 * },
 * @endcode
 */
typedef struct mpi_gamma_attr {
	MPI_GAMMA_MODE_E mode; /**< Gamma mode(BT709, CRT, and manual). Default value: 0(BT709) */
	MPI_GAMMA_CURVE_S gma_manual; /**< Manual gamma curve. */
} MPI_GAMMA_ATTR_S;

/**
 * @brief Enumeration of Demosaicing controlling methods.
 */
typedef enum {
	DMS_DEFAULT = 0, /**< Default method. DMS will use a set of default settings. */
	DMS_ISO, /**< ISO method. DMS will use ISO values and dms_auto or dms_manual. */
	DMS_MODE_NUM,
} MPI_DMS_MODE_E
        __attribute__((deprecated(
                "Error: MPI_DMS_MODE_E is deprecated. It has never been used internally and can be safely removed.")));

/**
 * @brief Structure for paramters of automatic demosaicing.
 */
typedef struct mpi_dms_auto {
	INT32 g_at_m_inter_ratio
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto inter ratio for green at red/blue position in bayer pattern. The value range is [0, 63]. Default value: 12 */
	INT32 m_at_m_inter_ratio
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto inter ratio for blue/red at red/blue position in bayer pattern. The value range is [0, 63]. Default value: 24 */
	INT32 m_at_g_inter_ratio
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto inter ratio for red/blue at green position in bayer pattern. The value range is [0, 63]. Default value: 24 */
} MPI_DMS_AUTO_S;

/**
 * @brief Structure for paramters of manual demosaicing.
 */
typedef struct mpi_dms_manual {
	INT32 g_at_m_inter_ratio; /**< Manual inter ratio for green at red/blue position in bayer pattern. The value range is [0, 63]. Default value: 12 */
	INT32 m_at_m_inter_ratio; /**< Manual inter ratio for blue/red at red/blue position in bayer pattern. The value range is [0, 63]. Default value: 24 */
	INT32 m_at_g_inter_ratio; /**< Manual inter ratio for red/blue at green position in bayer pattern. The value range is [0, 63]. Default value: 24 */
} MPI_DMS_MANUAL_S;

/**
 * @brief Structure for paramters of automatic enhancement.
 */
typedef struct mpi_enh_auto {
	INT32 y_txr_strength
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto luma strength for texture (txr = texture). The value range is [0, 65535]. Default value: 0 */
	INT32 y_txr_edge
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto luma edge strength for texture. The value range is [0, 32]. Default value: 32 */
	INT32 y_txr_detail
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto luma detail strength for texture. The value range is [-16, 63]. Default value: 0 */
	INT32 y_zone_strength
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto luma strength for flat zone (zone = flat zone). The value range is [0, 65535]. Default value: 0 */
	INT32 y_zone_edge
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto luma edge strength for flat zone. The value range is [0, 32]. Default value: 32 */
	INT32 y_zone_detail
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto luma detail strength for flat zone. The value range is [-16, 63]. Default value: 0 */
	INT32 y_zone_radius
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto luma radius strength for flat zone. The value range is [0, 2]. Default value: 0 */
	INT32 y_zone_weight
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto weight for blending txr and zone. The value range is [0, 255]. Default value: 0 */
	INT32 c_radius[MPI_ISO_LUT_ENTRY_NUM]; /**< Auto chroma radius. The value range is [0, 3]. Default value: 0 */
	INT32 c_strength
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Auto chroma strength. The value range is [0, 65535]. Default value: 0 */
	INT32 c_edge[MPI_ISO_LUT_ENTRY_NUM]; /**< Auto chroma edge strength. The value range is [0, 32]. Default value: 0 */
} MPI_ENH_AUTO_S;

/**
 * @brief Structure for paramters of manual enhancement.
 */
typedef struct mpi_enh_manual {
	INT32 y_txr_strength; /**< Manual luma strength for texture (txr = texture). The value range is [0, 65535]. Default value: 0 */
	INT32 y_txr_edge; /**< Manual luma edge strength for texture. The value range is [0, 32]. Default value: 32 */
	INT32 y_txr_detail; /**< Manual luma detail strength for texture. The value range is [-16, 63]. Default value: 0 */
	INT32 y_zone_strength; /**< Manual luma strength for flat zone (zone = flat zone). The value range is [0, 65535]. Default value: 0 */
	INT32 y_zone_edge; /**< Manual luma edge strength for flat zone. The value range is [0, 32]. Default value: 32 */
	INT32 y_zone_detail; /**< Manual luma detail strength for flat zone. The value range is [-16, 63]. Default value: 0 */
	INT32 y_zone_radius; /**< Manual luma radius strength for flat zone. The value range is [0, 2]. Default value: 0 */
	INT32 y_zone_weight; /**< Manual weight for blending txr and zone. The value range is [0, 255]. Default value: 0 */
	INT32 c_radius; /**< Manual chroma radius. The value range is [0, 3]. Default value: 0 */
	INT32 c_strength; /**< Manual chroma strength. The value range is [0, 65535]. Default value: 0 */
	INT32 c_edge; /**< Manual chroma edge strength. The value range is [0, 32]. Default value: 0 */
} MPI_ENH_MANUAL_S;

/**
 * @struct MPI_ENH_ATTR_S
 * @brief Defines enhancement(ENH) attribute.
 * @see MPI_getEnhAttr()
 * @see MPI_setEnhAttr()
 */
typedef struct mpi_enh_attr {
	MPI_ALG_OPT_E mode; /**< Enhancement control mode(Auto mode or manual mode). Default value: 0(Auto mode). */
	MPI_ENH_AUTO_S enh_auto; /**< Automatic enhancement control parameters */
	MPI_ENH_MANUAL_S enh_manual; /**< Manual enhancement control parameters */
} MPI_ENH_ATTR_S;

/**
 * @brief Structure for tone enhancement under normal mode.
 */
typedef struct mpi_te_normal {
	UINT32 curve[MPI_TE_CURVE_ENTRY_NUM]; /**< Manual curve. The value range is [0, 16384]. */
} MPI_TE_NORMAL_S;

/**
 * @brief Structure for tone enhancement under WDR mode.
 */
typedef struct mpi_te_wdr {
	UINT16 brightness; /**< Brightness strength.The value range is [0, 16384]. Default value: 3000 */
	UINT16 strength; /**< Enhancement strength.The value range is [0, 1024]. Default value: 512 */
	UINT16 saliency; /**< Non-linear enhancment.The value range is [0, 1024]. Default value: 512 */
	UINT16 noise_cstr[MPI_ISO_LUT_ENTRY_NUM]; /**< Noise constraint.The value range is [0, 1024]. Default value: 30 */
	UINT8 iso_weight; /**< Weighting adjustment of ISO calculation.The value range is [0, 255]. Default value: 128 */
	UINT8 dark_enhance; /**< Dark region enhancing strengthThe value range is [0, 255]. Default value: 0 */
	UINT32 iso_max; /**< Constraint maximal ISO .The value range is [100, 102400]. Default value: 3200 */
	UINT8 interval; /**< Interval between two executions.The value range is [0, 255]. Default value: 0 */
	UINT8 precision; /**< Operational precision.The value range is [0, 2]. Default value: 2 */
} MPI_TE_WDR_S __attribute__((deprecated("Error: MPI_TE_WDR_S is deprecated. Please use MPI_TE_ADAPT_S instead.")));

/**
 * @brief Enumeration of tone enhancement dynamic range index type.
 */
typedef enum mpi_te_dri_type {
	TE_DRI_TYPE_GAMMA_DOMAIN_HIST_CV =
	        0, /**< Coefficient of variation under gamma domain. The mean value is the average value of gamma histogram. */
	TE_DRI_TYPE_LINEAR_DOMAIN_HIST_CV, /**< Coefficient of variation under linear domain. The mean value is the average value of liner histogram. */
	TE_DRI_TYPE_NUM,
} MPI_TE_DRI_TYPE_E
        __attribute__((deprecated(
                "Error: MPI_TE_DRI_TYPE_E is deprecated. It has never been used internally and can be safely removed.")));

/**
 * @brief Enumeration of methods for determining attributes in the Adaptive Mode of TE.
 */
typedef enum mpi_te_based_type {
	TE_ADAPT_NL_BASED = 0, /**< Determine attributes for the Adaptive Mode based on noise level. */
	TE_ADAPT_INTTIME_BASED, /**< Determine attributes for the Adaptive Mode based on integration time. */
	TE_ADAPT_EV_BASED, /**< Determine attributes for the Adaptive Mode based on exposure value (inttime * system gain). */
	TE_ADAPT_BASED_TYPE_RSV, /**< Reserved TE Adaptive type setting. */
	TE_ADAPT_BASED_TYPE_NUM, /**< Total number of TE adaptive type settings, not a valid option. */
} MPI_TE_ADAPT_BASED_TYPE_E;

/**
 * @brief Structure for tone enhancement under the Adaptive Mode.
 */
typedef struct mpi_te_adapt {
	INT32 strength __attribute__((deprecated(
	        "Error: MPI_TE_ADAPT_S::strength is deprecated. Please use MPI_TE_ADAPT_S::str_auto instead.")));
	INT32 dark_enhance
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Level of additional boosts for pixels in dark regions. In range[0, 31]. Default: 8. */
	MPI_TE_ADAPT_BASED_TYPE_E
	te_adapt_based_type; /**< Method for looking up the attributes. Default: 0 (TE_ADAPT_NL_BASED). */
	INT32 str_auto_en __attribute__((deprecated(
	        "Error: MPI_TE_ADAPT_S::str_auto_en is deprecated. Please use MPI_TE_ADAPT_S::str_auto instead.")));
	INT32 str_auto[MPI_ISO_LUT_ENTRY_NUM]; /**< Strength of tone enhancement. In range[0, 1024]. Default: 16. */
	INT32 speed; /**< Converging speed of the tone enhancement curve between frames. In range[0, 255]. Default: 95. */
	INT32 white_th
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< The brightness threshold of pixels in bright regions that TE will not affect in. In range[0, 16384]. Default: 15040. */
	INT32 black_th
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< The brightness threshold of pixels in dark regions that TE will not affect in. In range[0, 16384]. Default: 512. */
	INT32 max_str[MPI_ISO_LUT_ENTRY_NUM]; /**< Maximum boost strength for pixels in dark regions. In range[0, 1024]. Default: 7. */
	INT32 dark_protect_smooth
	        [MPI_ISO_LUT_ENTRY_NUM]; /** Smooth region before and after black_th. In range[0, 8]. Default: 0 */
	INT32 dark_protect_str[MPI_ISO_LUT_ENTRY_NUM]; /** Strength in the black_th range. In range[0, 64]. Default: 0 */
	INT32 max_str_prec_sel; /**< Determine whether the max_str function uses max_str or max_str_8x. In range[0, 1]. Default: 0. */
	INT32 dark_enhance_th
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Determine the size of the area affected by dark_enhance. In range[0, 16384]. Default: 2048. */
} MPI_TE_ADAPT_S;

/**
 * @brief Structure for high dynamic range synthesis weight.
 */
typedef struct mpi_hdr_synth_weight {
	UINT16 se_weight_th_min; /**< Short exposure weighting threshold minimum. The value range is [0, 4095]. Default value: 240 */
	UINT16 se_weight_slope; /**< Short exposure weighting slope. The value range is [0, 127]. Default value: 56 */
	UINT16 se_weight_min; /**< Short exposure weighting minimum. The value range is [1, 63]. Default value: 1 */
	UINT16 se_weight_max; /**< Short exposure weighting maximum. The value range is [1, 63]. Default value: 63 */
	UINT16 le_weight_th_max; /**< Long exposure weighting threshold maximum. The value range is [0, 4095]. Default value: 3840 */
	UINT16 le_weight_slope; /**< Long exposure weighting slope. The value range is [0, 127]. Default value: 14 */
	UINT16 le_weight_min; /**< Long exposure weighting minimum. The value range is [1, 63]. Default value: 1 */
	UINT16 le_weight_max; /**< Long exposure weighting maximum. The value range is [1, 63]. Default value: 63 */
} MPI_HDR_SYNTH_WEIGHT_S;

/**
 * @struct MPI_HDR_SYNTH_ATTR_S
 * @brief Defines high dynamic range synthesis(HDR_SYNTH) attribute.
 * @see MPI_getHdrSynthAttr()
 * @see MPI_setHdrSynthAttr()
 */
typedef struct mpi_hdr_synth_attr {
	MPI_HDR_SYNTH_WEIGHT_S weight; /**< HDR synthesis weight. */
	UINT16 local_fb_th; /**< Local fallback threshold. The value range is [0, 255]. Default value: 44 */
	UINT16 frame_fb_strength; /**< Frame fallback strength. The value range is [0, 16]. Default value: 0 */
} MPI_HDR_SYNTH_ATTR_S;

/**
 * @struct MPI_DIP_ATTR_S
 * @brief Defines DIP module attribute.
 * @details
 * The value 0 indicates that disable module. Output = Input.
 * The value 1 indicates that enable module. Output = Algotithm(Input).
 * The value 2 indicates that bypass module. The output will not be updated. The last frame setting will be apply.
 * @see MPI_getDipAttr()
 * @see MPI_setDipAttr()
 */
typedef struct mpi_dip_attr {
	UINT8 is_dip_en; /**< Enable DIP module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_ae_en; /**< Enable AE module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_iso_en; /**< Enable DIP_ISO module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_awb_en; /**< Enable AWB module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_nr_en; /**< Enable NR module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_te_en; /**< Enable TE module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_pta_en; /**< Enable PTA module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_csm_en; /**< Enable CSM module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_shp_en; /**< Enable SHP module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_gamma_en; /**< Enable GAMMA module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_dpc_en; /**< Enable DPC module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_dms_en; /**< Enable DMS module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_me_en; /**< Enable ME module. The value range is [0, 2]. Default value: 1 */
	union {
		UINT8 is_enh_en; /**< Enable ENH module. The value range is [0, 2]. Default value: 1 */
		UINT8 is_nr2d_en; /**< Enable NR2D module. The value range is [0, 2]. Default value: 1 */
	};
	UINT8 is_coring_en; /**< Enable CORING module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_fcs_en; /**< Enable FCS module. The value range is [0, 2]. Default value: 1 */
	UINT8 is_dhz_en; /**< Enable DHZ module. The value range is [0, 2]. Default value: 1 */
} MPI_DIP_ATTR_S;

/**
 * @struct MPI_EXPOSURE_INFO_S
 * @brief Defines the internal exposure status information.
 * @see MPI_queryExposureInfo()
 * @note Attributes with hdr prefix record exposure info from short to long frames
 * ex. hdr_inttime, hdr_sensor_gain, hdr_isp_gain, hdr_sys_gain
 * @note Index 0 to MPI_SNS_HDR_MAX_IMAGE_NUM - 1 correspond to recording exposure info from short to long frames.
 * @note
 * If MPI_SNS_HDR_MAX_IMAGE_NUM  =  2.
 * * Index 0 contains short frame exposure info.
 * * Index 1 contains long frame exposure info.
 * @note If MPI_SNS_HDR_MAX_IMAGE_NUM  =  3.
 * * Index 0 contains short frame exposure info.
 * * Index 1 contains medium frame exposure info.
 * * Index 2 contains long frame exposure info.
 * @note and so on.
 */
typedef struct mpi_exposure_info {
	UINT32 inttime; /**< Read-only. Integration time(in microsecond). The value range is [0, 10000000]. */
	UINT32 sensor_gain; /**< Read-only. Sensor gain(5-bit decimal precision). The value range is [0, UINT_MAX]. */
	UINT32 isp_gain; /**< Read-only. Digital gain(10-bit decimal precision). The value range is [0, UINT_MAX]. */
	UINT32 sys_gain; /**< Read-only. System gain(5-bit decimal precision). The value range is [0, UINT_MAX]. (sys_gain = 32 * [(sensor_gain / 32) * (isp_gain / 1024)] */
	UINT32 hdr_inttime
	        [MPI_SNS_HDR_MAX_IMAGE_NUM]; /**< Read-only. HDR integration time(in microsecond). The value range is [0, 10000000]. */
	UINT32 hdr_sensor_gain
	        [MPI_SNS_HDR_MAX_IMAGE_NUM]; /**< Read-only. HDR sensor gain(5-bit decimal precision). The value range is [0, UINT_MAX]. */
	UINT32 hdr_isp_gain
	        [MPI_SNS_HDR_MAX_IMAGE_NUM]; /**< Read-only. HDR digital gain(10-bit decimal precision). The value range is [0, UINT_MAX]. */
	UINT32 hdr_sys_gain
	        [MPI_SNS_HDR_MAX_IMAGE_NUM]; /**< Read-only. HDR system gain(5-bit decimal precision). The value range is [0, UINT_MAX]. (sys_gain = 32 * [(sensor_gain / 32) * (isp_gain / 1024)] */
	INT32 iso; /**< Read-only. ISO value. The value range is [100, 102400] when MPI_ISO_ATTR_S::iso_type = 0, [0, 8192] when MPI_ISO_ATTR_S::iso_type = 1. */
	UINT8 frame_delay; /**< Read-only. Delay frame for next AE execution. The value range is [0, 255]. */
	UINT8 flicker_free_conf; /**< Read-only. Confidence of anti-flicker. The value range is [0, 8]. */
	FLOAT fps; /**< Read-only. Frame rate. The value range is [0.1, 255].*/
	UINT32 ratio; /**< Read-only. Ratio between last expousre value and new expousre value(10-bit decimal precision). The value range is [0, UINT_MAX]. */
	UINT16 luma_avg; /**< Read-only. Luma average. The value range is [0, 16383]. */
} MPI_EXPOSURE_INFO_S;

/**
 * @struct MPI_WHITE_BALANCE_INFO_S
 * @brief Defines the internal white balance status information.
 * @see MPI_queryWhiteBalanceInfo()
 */
typedef struct mpi_white_balance_info {
	UINT16 gain0[MPI_AWB_CHN_NUM]; /**< Read-only. Main path gain of the Gr, R, B,and Gb color channels obtained from the AWB algorithm. The value range is [0, 2047]. */
	UINT16 gain1[MPI_AWB_CHN_NUM]; /**< Read-only. Sub path gain of the Gr, R, B,and Gb color channels obtained from the AWB algorithm. The value range is [0, 2047]. */
	INT16 matrix[MPI_COLOR_CHN_NUM *
	             MPI_COLOR_CHN_NUM]; /**< Read-only. Color Correction Matrix. The value range is [-32768, 32767]. */
	UINT16 color_temp; /**< Read-only. Color temperature. The value range is [0, 16383]. */
} MPI_WHITE_BALANCE_INFO_S;

/**
 * @struct MPI_TE_INFO_S
 * @brief Defines the internal tone enhancement status information.
 * @see MPI_queryTeInfo()
 */
typedef struct mpi_te_info {
	UINT8 tm_enable; /**< Read-only. Tone enhancement enable. The value range is [0, 1]. */
	UINT32 tm_curve[MPI_TE_CURVE_ENTRY_NUM]; /**< Read-only. Current tone mapping curve */
} MPI_TE_INFO_S;

/**
 * @brief Structure for focus statistics.
 * @details
 * Contains focus information of the image.
 */
typedef struct mpi_focus_stat {
	UINT16 hor_var_sum; /**< Read-only. ROI horizontal variance statistics. Range: [0, 16383] */
	UINT16 ver_var_sum; /**< Read-only. ROI vertical variance statistics. Range: [0, 16383] */
	UINT16 zone_hor_var
	        [MPI_FOCUS_ZONE_VER_NUM]
	        [MPI_FOCUS_ZONE_HOR_NUM]; /**< Read-only. Zone horizontal variance statistics. Range: [0, 16383] */
	UINT16 zone_ver_var[MPI_FOCUS_ZONE_VER_NUM]
	                   [MPI_FOCUS_ZONE_HOR_NUM]; /**< Read-only. Zone vertical variance statistics. Range: [0, 16383] */
	UINT8 zone_x_num; /**< Read-only. Valid regions in a row in the zone statistics. Range: [1, ::MPI_FOCUS_ZONE_HOR_NUM] */
	UINT8 zone_y_num; /**< Read-only. Valid regions in a column in the zone statistics. Range: [1, ::MPI_FOCUS_ZONE_VER_NUM] */
} MPI_FOCUS_STAT_S;

/**
 * @brief Structure of white balance statistics
 * @details
 * Contains white balance/color information of the image.
 * There are 2 kinds of the statistics:
 * 1. global - the average rgb values among all pixels within a configurable ROI
 * 2. zone - the average rgb values among all pixels within fixed "zones"
 * Zones devide the whole picture into 8x8 identical areas and number the areas in the following order:
 *  00 01 02 03 04 05 06 07
 *  08 09 10 11 12 13 14 15
 *  ...
 *  56 57 58 59 60 61 62 63
 *
 * HC1702, HC1722, HC1752, HC1772, HC1782 only provide ROI0 in global statistics
 * and do not support zone statistics
 */
typedef struct mpi_wb_stat {
	UINT16 global_r_avg
	        [MPI_AWB_MAX_PIX_AVG_ROI_NUM]; /**< Read-only. Average R channel value of every ROI. The value range is [0, 16383]. */
	UINT16 global_g_avg
	        [MPI_AWB_MAX_PIX_AVG_ROI_NUM]; /**< Read-only. Average G channel value of every ROI. The value range is [0, 16383]. */
	UINT16 global_b_avg
	        [MPI_AWB_MAX_PIX_AVG_ROI_NUM]; /**< Read-only. Average B channel value of every ROI. The value range is [0, 16383]. */
	UINT16 zone_r_avg
	        [MPI_AWB_ZONE_NUM]; /**< Read-only. Average R channel values of every zone. The value range is [0, 255]. */
	UINT16 zone_g_avg
	        [MPI_AWB_ZONE_NUM]; /**< Read-only. Average G channel values of every zone. The value range is [0, 255]. */
	UINT16 zone_b_avg
	        [MPI_AWB_ZONE_NUM]; /**< Read-only. Average B channel values of every zone. The value range is [0, 255]. */
} MPI_WB_STAT_S;

/**
 * @brief Structure of auto exposure statistics
 * @details
 * Contains auto exposure information of the image.
 */
typedef struct mpi_ae_stat {
	UINT32 lum_hist[MPI_LUM_HIST_ENTRY_NUM]; /**< There are 60 bins for the luma histogram. */
} MPI_AE_STAT_S;

/**
 * @struct MPI_DIP_STAT_S
 * @brief Defines DIP statistics.
 * @details
 * Can be got from MPI_getStatistics() function to have some information
 * about the current scene in the applications.
 * @see MPI_getStatistics()
 */
typedef struct mpi_dip_stat {
	MPI_FOCUS_STAT_S focus_stat; /**< Focus statistics */
	MPI_WB_STAT_S wb_stat; /**< White balance statistics */
	MPI_AE_STAT_S ae_stat; /**< Auto exposure statistics */
} MPI_DIP_STAT_S;

/**
 * @brief Structure of GWD auto luma threshold parameters
 */
typedef struct mpi_gwd_auto_lum_thd_param {
	uint16_t lum_max_degree; /**< Degree of luma max. In range [0, 32] */
	uint64_t indoor_ev_thd; /**< Threshold of exposure value in an indoor scene. In range [0, 163830000000]. */
	uint64_t outdoor_ev_thd; /**< Threshold of exposure value in an outdoor scene. In range [0, 163830000000]. */
	uint16_t indoor_lum_range; /**< Range of luma in an indoor scene. In range [0, 16383]. */
	uint16_t outdoor_lum_range; /**< Range of luma in an outdoor scene. In range [0, 16383]. */
	uint16_t min_lum_bnd; /**< Lower bound of luma. In range [0, 16383]. */
} MPI_GWD_AUTO_LUM_THD_PARAM_S;

/**
 * @struct MPI_WB_STAT_CFG_S
 * @brief Structure of white balance statistics configurations
 * @details
 * For color filter related settings, please see the application note.
 */
typedef struct mpi_wb_stat_cfg {
	uint16_t lum_max; /**< Maximum brightness of a pixel that will be counted in WB statistics. In range[0, 16383] */
	uint16_t lum_min; /**< Minimum brightness of a pixel that will be counted in WB statistics. In range[0, 16383] */
	uint16_t lum_slope; /**< Slope of the margin in the brightness filter. In range [0, 31], suggest range [16, 20] */
	uint16_t rb_point_x[MPI_WB_RB_POINT_NUM]; /**< X axis of the coordinates of the color filter. In range[0, 511] */
	uint16_t rb_point_y[MPI_WB_RB_POINT_NUM]; /**< Y axis of the coordinates of the color filter. In range[0, 511] */
	uint16_t rb_rgn_th[MPI_WB_RB_POINT_NUM - 1]; /**< Color filtering region threshold. In range [0, 127] */
	uint16_t rb_rgn_slope[MPI_WB_RB_POINT_NUM - 1]; /**< Slope of the margin in the color filter region. In range [0, 31] */
	uint16_t gwd_auto_lum_thd_enable; /**< Enable GWD auto luma threshold. In range [0, 1] */
	MPI_GWD_AUTO_LUM_THD_PARAM_S gwd_auto_lum_thd_param; /**< GWD auto luma threshold parameters. */
} MPI_WB_STAT_CFG_S;

/**
 * @struct MPI_FOCUS_STAT_CFG_S
 * @brief Strucutre of focus statistics configurations.
 */
typedef struct mpi_focus_stat_cfg {
	INT16 hor_weight[MPI_FOCUS_HOR_WEIGHT_NUM]; /**< Weightings of horizontal focus statistics. Range: [-128, 127] */
	INT16 ver_weight[MPI_FOCUS_VER_WEIGHT_NUM]; /**< Weightings of vertical focus statistics. Range: [-256, 255] */
} MPI_FOCUS_STAT_CFG_S;

/**
 * @struct MPI_STAT_CFG_S
 * @brief Structure of different MPI statistics configurations.
 */
typedef struct mpi_stat_cfg {
	MPI_WB_STAT_CFG_S wb; /**< White balance statistics configurations. */
	MPI_FOCUS_STAT_CFG_S focus; /**< Focus statistics configurations. */
} MPI_STAT_CFG_S;

/**
 * @struct MPI_PCA_TABLE_S
 * @brief Defines preference color adjustment(PCA) table.
 * @see MPI_getPcaTable()
 * @see MPI_setPcaTable()
 */
typedef struct mpi_pca_table {
	INT16 h[MPI_PCA_L_ENTRY_NUM][MPI_PCA_S_ENTRY_NUM][MPI_PCA_H_ENTRY_NUM]; /**< Hue lookup table. */
	INT16 s[MPI_PCA_L_ENTRY_NUM][MPI_PCA_S_ENTRY_NUM][MPI_PCA_H_ENTRY_NUM]; /**< Saturation lookup table. */
	INT16 l[MPI_PCA_L_ENTRY_NUM][MPI_PCA_S_ENTRY_NUM][MPI_PCA_H_ENTRY_NUM]; /**< Lightness lookup table. */
} MPI_PCA_TABLE_S;

/**
 * @brief Structure for paramters of automatic false color suppression.
 */
typedef struct mpi_fcs_auto {
	UINT16 strength
	        [MPI_ISO_LUT_ENTRY_NUM]; /**< Automatic strength of false color suppression. The value range is [0, 255]. */
	UINT16 threshold[MPI_ISO_LUT_ENTRY_NUM] __attribute__((deprecated(
	        "Error: MPI_FCS_AUTO_S::threshold[MPI_ISO_LUT_ENTRY_NUM] is deprecated. It has never been used internally and can be safely removed.")));
	UINT16 offset[MPI_ISO_LUT_ENTRY_NUM] __attribute__((deprecated(
	        "Error: MPI_FCS_AUTO_S::offset[MPI_ISO_LUT_ENTRY_NUM] is deprecated. It has never been used internally and can be safely removed.")));
} MPI_FCS_AUTO_S;

/**
 * @brief Structure for paramters of manual sharpness.
 */
typedef struct mpi_fcs_manual {
	UINT16 strength; /**< Manual strength of false color suppression. The value range is [0, 255]. Default value: 0 */
	UINT16 threshold __attribute__((deprecated(
	        "Error: MPI_FCS_MANUAL_S::threshold is deprecated. It has never been used internally and can be safely removed.")));
	UINT16 offset __attribute__((deprecated(
	        "Error: MPI_FCS_MANUAL_S::threshold is deprecated. It has never been used internally and can be safely removed.")));
} MPI_FCS_MANUAL_S;

/**
 * @struct MPI_FCS_ATTR_S
 * @brief Defines false color suppression(FCS) attribute.
 * @see MPI_getFcsAttr()
 * @see MPI_setFcsAttr()
 */
typedef struct mpi_fcs_attr {
	MPI_ALG_OPT_E mode; /**< False color suppression mode(Auto mode or manual mode). Default value: 0(Auto mode) */
	MPI_FCS_AUTO_S fcs_auto; /**< Manual false color suppression parameter. */
	MPI_FCS_MANUAL_S fcs_manual; /**< Automatic false color suppression parameter. */
} MPI_FCS_ATTR_S;

/**
 * @brief Structure for paramters of automatic dehaze.
 */
typedef struct mpi_dhz_auto {
	UINT16 y_gain_max[MPI_ISO_LUT_ENTRY_NUM]; /**< Y channel gain maximum. Set the value as ROUNDING(N * 256), where
	                                               N (float) = [0, 4). Range: [0, 1023]. Default: 512 (N=2). */
	UINT16 c_gain_max[MPI_ISO_LUT_ENTRY_NUM]; /**< UV channel gain maximum. Set the value as ROUNDING(N * 256), where
	                                               N (float) = [0, 4). Range: [0, 1023]. Default: 340 (N=1.33). */
} MPI_DHZ_AUTO_S;

/**
 * @brief Structure for paramters of manual dehaze.
 */
typedef struct mpi_dhz_manual {
	UINT16 y_gain_max; /**< Y channel gain maximum. Set the value as ROUNDING(N * 256), where N (float) = [0, 4).
	                        Range: [0, 1023]. Default: 512 (N=2). */
	UINT16 c_gain_max; /**< UV channel gain maximum. Set the value as ROUNDING(N * 256), where N (float) = [0, 4).
	                        Range: [0, 1023]. Default: 340 (N=1.33). */
} MPI_DHZ_MANUAL_S;

/**
 * @struct MPI_DHZ_ATTR_S
 * @brief Define Dehaze (DHZ) attributes.
 * @see MPI_getDhzAttr()
 * @see MPI_setDhzAttr()
 */
typedef struct mpi_dhz_attr {
	MPI_ALG_OPT_E mode; /**< Dehaze mode (Auto mode or manual mode). Default: 0(Auto mode) */
	MPI_DHZ_AUTO_S dhz_auto; /**< Automatic Dehaze parameter. */
	MPI_DHZ_MANUAL_S dhz_manual; /**< Manual Dehaze parameter. */
	UINT16 dc_iir_weight; /**< Update rate of luma direct-current (y_dc) value. Range: [0, 256]. Default: 32. */
	UINT16 gain_step_th; /**<  Regional gain step threshold. Range: [0, 1023]. Default: 10. */
} MPI_DHZ_ATTR_S;

/* Ignore deprecated errors */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

/**
 * @struct MPI_DBC_ATTR_S
 * @brief Defines device black-level correction(DBC) attribute.
 * @details
 * The default DBC attributes can be obtained through lens-calibration tool.
 * @see MPI_getDbcAttr()
 * @see MPI_setDbcAttr()
 */
typedef struct mpi_dbc_attr {
	MPI_ALG_OPT_E mode; /**< Algorithm opration mode(Auto mode or manual mode). */
	UINT16 dbc_level __attribute__((deprecated(
	        "Error: MPI_DBC_ATTR_S::dbc_level is deprecated. Please use MPI_DBC_ATTR_S::dbc_manual or MPI_DBC_ATTR_S::dbc_auto instead.")));
	MPI_DBC_TYPE_E type __attribute__((deprecated(
	        "Error: MPI_DBC_ATTR_S::type is deprecated. Please use MPI_DBC_ATTR_S::dbc_manual or MPI_DBC_ATTR_S::dbc_auto instead.")));
	MPI_DBC_MANUAL_S dbc_manual; /**< Manual black current subtraction. */
	MPI_DBC_AUTO_S dbc_auto; /**< Automatic black current subtraction. */
} MPI_DBC_ATTR_S;

/**
 * @struct MPI_DCC_ATTR_S
 * @brief Defines device color correction(DCC) attribute.
 * @details
 * The default DCC attributes can be obtained through lens-calibration tool.
 * @see MPI_getDccAttr()
 * @see MPI_setDccAttr()
 */
typedef struct mpi_dcc_attr {
	MPI_ALG_OPT_E mode; /**< Algorithm operation mode(Auto mode or manual mode). */
	MPI_DCC_TYPE_E type __attribute__((deprecated(
	        "Error: MPI_DCC_ATTR_S::type is deprecated. Please use MPI_DCC_ATTR_S::dcc_manual or MPI_DCC_ATTR_S::dcc_auto instead.")));
	UINT16 gain[MPI_DCC_CHN_NUM] __attribute__((deprecated(
	        "Error: MPI_DCC_ATTR_S::gain[MPI_DCC_CHN_NUM] is deprecated. Please use MPI_DCC_ATTR_S::dcc_manual::manual::gain or MPI_DCC_ATTR_S::dcc_auto::auto_table::gain instead.")));
	INT32 offset_2s[MPI_DCC_CHN_NUM] __attribute__((deprecated(
	        "Error: MPI_DCC_ATTR_S::offset_2s[MPI_DCC_CHN_NUM] is deprecated. Please use MPI_DCC_ATTR_S::dcc_manual::manual::offset_2s or MPI_DCC_ATTR_S::dcc_auto::auto_table::offset_2s instead.")));
	MPI_DCC_MANUAL_S dcc_manual; /** Manual device color correction. */
	MPI_DCC_AUTO_S dcc_auto; /** Auto device color correction. */
} MPI_DCC_ATTR_S;

/**
 * @struct MPI_ISO_ATTR_S
 * @brief Defines effective iso attribute.
 * @see MPI_getIsoAttr()
 * @see MPI_setIsoAttr()
 * @property MPI_ISO_AUTO_S MPI_ISO_ATTR_S::iso_auto
 * @note
 * @arg The default ::MPI_ISO_ATTR_S::iso_auto as follow:
 * @code{.c}
 * {
 *     .effective_iso = {
 *         100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 51200, 102400,
 *     },
 * }
 * @endcode
 */
typedef struct mpi_iso_attr {
	MPI_ALG_OPT_E mode; /**< Effective iso mode(Auto mode or manual mode). Default value: 0(Auto mode) */
	MPI_ISO_AUTO_S iso_auto; /**< Automatic effective iso parameter. */
	MPI_ISO_MANUAL_S iso_manual; /**< Manual effective iso parameter. */
	MPI_ISO_TYPE_E iso_type; /**< Determine the definition of ISO values. Default value: 0 */
	MPI_ISO_DAA_S daa __attribute__((deprecated(
	        "Error: MPI_ISO_ATTR_S::daa is deprecated. It has never been used internally and can be safely removed.")));
} MPI_ISO_ATTR_S;

/**
 * @struct MPI_AWB_ATTR_S
 * @brief Defines auto white balance(AWB) attribure.
 * @see MPI_getAwbAttr()
 * @see MPI_setAwbAttr()
 * @property MPI_AWB_COLOR_TEMP_S MPI_AWB_ATTR_S::k_table
 * @note
 * @arg The default ::MPI_AWB_ATTR_S::k_table can be obtained through lens-calibration tool.
 * @property MPI_AWB_COLOR_TEMP_BIAS_S MPI_AWB_ATTR_S::bias_table
 * @note
 * @arg After lens calibration is done, awb performance is not as accurate as you expect.
 * You can adjust the ::MPI_AWB_ATTR_S::bias_table under each color temperature points to achieve your goal.
 * @property MPI_AWB_COLOR_DELTA_S MPI_AWB_ATTR_S::delta_table
 * @note
 * @arg The default ::MPI_AWB_ATTR_S::delta_table can be obtained through lens-calibration tool.
 */
typedef struct mpi_awb_attr {
	UINT8 speed; /**< Convergence speed. The value range is [0, 255]. Default value: 1 */
	UINT8 wht_density __attribute__((deprecated(
	        "Error: MPI_AWB_ATTR_S::wht_density is deprecated. It has never been used internally and can be safely removed.")));
	UINT8 color_tolerance __attribute__((deprecated(
	        "Error: MPI_AWB_ATTR_S::color_tolerance is deprecated. It has never been used internally and can be safely removed.")));
	UINT8 wht_weight; /**< White point confidence weight. The value range is [0, 255]. Default value: 64 */
	UINT8 gwd_weight; /**< Gray world confidence weight. The value range is [0, 255]. Default value: 64 */
	UINT8 r_extra_gain; /**< Extra red channel gain. The value range is [0, 255]. Default value: 128 */
	UINT8 b_extra_gain; /**< Extra blue channel gain. The value range is [0, 255]. Default value: 128 */
	UINT8 g_extra_gain; /**< Extra green channel gain. The value range is [0, 255]. Default value: 128 */
	UINT8 max_lum_gain __attribute__((deprecated(
	        "Error: MPI_AWB_ATTR_S::max_lum_gain is deprecated. It has never been used internally and can be safely removed.")));
	UINT8 k_table_valid_size; /**< Valid size of color temperature information. The value range is [0, ::MPI_K_TABLE_ENTRY_NUM]. Default value: 4 */
	UINT16 low_k; /**< Lower color temperature. The value range is [2000, 15000]. Default value: 2700 */
	UINT16 high_k; /**< High color temperature. The value range is [::MPI_AWB_ATTR_S::low_k, 15000]. Default value: 11000 */
	UINT16 over_exp_th; /**< over exposure threshold for bright pixel finding. The value range is [0, 32767]. Default value: 13000 */
	MPI_AWB_CCM_DOMAIN_E ccm_domain __attribute__((deprecated(
	        "Error: MPI_AWB_ATTR_S::ccm_domain is deprecated. It has never been used internally and can be safely removed.")));
	MPI_AWB_COLOR_TEMP_S k_table[MPI_K_TABLE_ENTRY_NUM]; /**< Color temperature information. */
	MPI_AWB_COLOR_TEMP_BIAS_S bias_table[MPI_K_TABLE_ENTRY_NUM]; /**< Bias control of color temperature. */
	MPI_AWB_COLOR_DELTA_S delta_table[MPI_K_TABLE_ENTRY_NUM]; /**< Color delta information. */
} MPI_AWB_ATTR_S;

/**
 * @brief Structure for tone enhancement under WDR auto mode.
 */
typedef struct mpi_te_wdr_auto {
	MPI_TE_DRI_TYPE_E dri_type; /**< Dynamic range index type. Default value: 0 (GAMMA_DOMAIN) */
	INT32 dri_gain[MPI_ISO_LUT_ENTRY_NUM]; /**< DRI normalization gain. Default value: 1024 */
	INT32 dri_offset[MPI_ISO_LUT_ENTRY_NUM]; /**< DRI normalization offset. Default value: 0 */
	UINT16 strength[MPI_DRI_LUT_ENTRY_NUM]; /**< Enhancement strength.The value range is [0, 1024]. Default value: 512 */
	UINT16 brightness
	        [MPI_DRI_LUT_ENTRY_NUM]; /**< Brightness strength.The value range is [0, 16384]. Default value: 3000 */
	UINT32 iso_max; /**< Constraint maximal ISO .The value range is [100, 102400]. Default value: 3200 */
	UINT16 saliency
	        [MPI_DRI_LUT_ENTRY_NUM]; /**< Non-linear enhancment.The value range is [0, 1024]. Default value: 512 */
	UINT16 noise_cstr[MPI_ISO_LUT_ENTRY_NUM]; /**< Noise constraint.The value range is [0, 1024]. Default value: 30 */
	UINT8 dark_enhance
	        [MPI_DRI_LUT_ENTRY_NUM]; /**< Dark region enhancing strengthThe value range is [0, 255]. Default value: 0 */
	UINT8 iso_weight; /**< Weighting adjustment of ISO calculation.The value range is [0, 255]. Default value: 128 */
	UINT8 interval; /**< Interval between two executions.The value range is [0, 255]. Default value: 0 */
	UINT8 precision; /**< Operational precision.The value range is [0, 2]. Default value: 2 */
} MPI_TE_WDR_AUTO_S
        __attribute__((deprecated("Error: MPI_TE_WDR_AUTO_S is deprecated. Please use MPI_TE_ADAPT_S instead.")));

/**
 * @struct MPI_TE_ATTR_S
 * @brief Defines tone enhancement(TE) attribute.
 * @see MPI_getTeAttr()
 * @see MPI_setTeAttr()
 * @property MPI_TE_NORMAL_S MPI_TE_ATTR_S::te_normal
 * @note
 * @arg The default ::MPI_TE_ATTR_S::te_normal as follow:
 * @code{.c}
 * .curve = {
 *         0,    64,    128,    192,    256,    320,    384,    448,    512,    640,    768,    896,   1024,  1152,  1280,
 *      1408,  1536,   1664,   1792,   1920,   2048,   2176,   2304,   2432,   2560,   2816,   3072,   3328,  3584,  3840,
 *      4096,  4352,   4608,   4864,   5120,   5376,   5632,   5888,   6144,   6400,   6656,   7168,   7680,  8192,  8704,
 *      9216,  9728,  10240,  10752,  11264,  11776,  12288,  12800,  13312,  13824,  14336,  14848,  15360, 15872, 16384,
 * },
 * @endcode
 */
typedef struct mpi_te_attr {
	MPI_TE_MODE_E mode; /**< Tone enhancement mode(Normal, WDR, WDR auto). Default value: 0(Normal mode) */
	MPI_TE_NORMAL_S te_normal; /**< Parameter of tone enhancement under normal mode. */
	MPI_TE_WDR_S te_wdr __attribute__((
	        deprecated("Error: MPI_TE_ATTR_S::te_wdr is deprecated. Please use MPI_TE_ATTR_S::te_adapt instead.")));
	MPI_TE_WDR_AUTO_S te_wdr_auto __attribute__((deprecated(
	        "Error: MPI_TE_ATTR_S::te_wdr_auto is deprecated. Please use MPI_TE_ATTR_S::te_adapt instead.")));
	MPI_TE_ADAPT_S te_adapt; /**< Parameter of tone enhancement under ADAPT mode */
} MPI_TE_ATTR_S;

/**
 * @struct MPI_LTM_ATTR_S
 * @brief Defines local tone mapping (LTM) attribute.
 * @see MPI_getLtmAttr()
 * @see MPI_setLtmAttr()
 */
typedef struct mpi_wdr_attr {
	UINT8 wdr_en; /**< WDR operating mode. */
	UINT16 wdr_strength; /**< Strength of WDR mode. */
} MPI_WDR_ATTR_S;

/**
 * @struct MPI_DMS_ATTR_S
 * @brief Defines demosaicing(dms) attribute.
 * @see MPI_getDmsAttr()
 * @see MPI_setDmsAttr()
 */
typedef struct mpi_dms_attr {
	MPI_ALG_OPT_E mode; /**< Demosaicing mode(Auto mode or manual mode). Default value: 0(Auto mode). */
	MPI_DMS_AUTO_S dms_auto; /**< Automatic demosaicing control parameters */
	MPI_DMS_MANUAL_S dms_manual; /**< Manual demosaicing control parameters */
	MPI_DMS_MODE_E dms_ctrl_method __attribute__((deprecated(
	        "Error: MPI_DMS_ATTR_S::dms_ctrl_method is deprecated. Please use MPI_DMS_ATTR_S::dms_auto or MPI_DMS_ATTR_S::dms_manual instead.")));

} MPI_DMS_ATTR_S;

/**
 * @struct MPI_SHP_ATTR_V2_S
 * @brief Define sharpness V2(SHP_V2) attribute.
 * @see MPI_getShpAttrV2()
 * @see MPI_setShpAttrV2()
 * @property MPI_SHP_AUTO_V2_S MPI_SHP_ATTR_V2_S::shp_auto_v2
 * @note
 * @arg The default ::MPI_SHP_ATTR_V2_S::shp_auto_v2 as follow:
 * @code{.c}
 * {
 *     .sharpness = {
 *         128, 128, 120, 115, 100, 95, 90, 75, 32, 16, 0,
 *     },
 * }
 * @endcode
 */
typedef struct mpi_shp_attr_v2 {
	MPI_ALG_OPT_E mode; /**< Sharpness V2 mode(Auto mode or manual mode). Default value: 0(Auto mode) */
	MPI_SHP_AUTO_V2_S shp_auto_v2 __attribute__((deprecated(
	        "Error: MPI_SHP_ATTR_V2_S::shp_auto_v2 is deprecated. Please use MPI_SHP_ATTR_V2_S::shp_ex_auto instead.")));
	MPI_SHP_MANUAL_V2_S shp_manual_v2 __attribute__((deprecated(
	        "Error: MPI_SHP_ATTR_V2_S::shp_manual_v2 is deprecated. Please use MPI_SHP_ATTR_V2_S::shp_ex_manual instead.")));
	MPI_SHP_TYPE_E shp_type __attribute__((deprecated(
	        "Error: MPI_SHP_ATTR_V2_S::shp_type is deprecated. Please use MPI_SHP_ATTR_V2_S::shp_ex_manual or MPI_SHP_ATTR_V2_S::shp_ex_auto instead.")));
	MPI_SHP_EX_AUTO_S shp_ex_auto; /**< Second type (extend type) automatic sharpness  parameter.  */
	MPI_SHP_EX_MANUAL_S shp_ex_manual; /**< Second type (extend type) manual sharpness parameter.*/
	UINT8 motion_adaptive_en; /**< Enable Motion Adaptive SHP control. In range [0, 3]. Default: 0. */
	UINT8 ma_weak_shp_ratio; /**< Proportion of the SHP strength for weak SHP settings. In range [0, 100]. Default: 85. */
	UINT16 ma_conf_low_th; /**< Likelihood that there isn't a great motion in the scene. In range [0, 1024]. Default: 640. */
	UINT16 ma_conf_high_th; /**< Likelihood that there is a significant motion in the scene. In range [0, 1024]. Default: 720. */
	UINT16 strength; /**< Weighted coefficient of sharpness. The final sharpness strength is the sharpness of operating on SHP_TYPE or SHP_TYPE_EX
							multiplied by the weighted coefficient. In range [0, 256]. Default: 128. */
} MPI_SHP_ATTR_V2_S;

#pragma GCC diagnostic pop

/* Interface function prototype */
INT32 MPI_updateSnsParam(MPI_PATH idx);
INT32 MPI_regAeDftLib(MPI_PATH idx);
INT32 MPI_regAwbDftLib(MPI_PATH idx);
INT32 MPI_deregAeDftLib(MPI_PATH idx);
INT32 MPI_deregAwbDftLib(MPI_PATH idx);

INT32 MPI_getDipExtendFile(MPI_PATH idx, const char *filepath);
INT32 MPI_setDipExtendFile(MPI_PATH idx, const char *filepath);

INT32 MPI_getRoiAttr(MPI_PATH idx, MPI_ROI_ATTR_S *attr);
INT32 MPI_getAeAttr(MPI_PATH idx, MPI_AE_ATTR_S *attr);
INT32 MPI_getNrAttr(MPI_PATH idx, MPI_NR_ATTR_S *attr);
INT32 MPI_getTeAttr(MPI_PATH idx, MPI_TE_ATTR_S *attr);
INT32 MPI_getAwbAttr(MPI_PATH idx, MPI_AWB_ATTR_S *attr);
INT32 MPI_getPtaAttr(MPI_PATH idx, MPI_PTA_ATTR_S *attr);
INT32 MPI_getCsmAttr(MPI_PATH idx, MPI_CSM_ATTR_S *attr);
INT32 MPI_getShpAttrV2(MPI_PATH idx, MPI_SHP_ATTR_V2_S *attr);
INT32 MPI_getDipAttr(MPI_PATH idx, MPI_DIP_ATTR_S *attr);
INT32 MPI_getIsoAttr(MPI_PATH idx, MPI_ISO_ATTR_S *attr);
INT32 MPI_getEnhAttr(MPI_PATH idx, MPI_ENH_ATTR_S *attr);
INT32 MPI_getCoringAttr(MPI_PATH idx, MPI_CORING_ATTR_S *attr);
INT32 MPI_getHdrSynthAttr(MPI_PATH idx, MPI_HDR_SYNTH_ATTR_S *attr);
INT32 MPI_getFcsAttr(MPI_PATH idx, MPI_FCS_ATTR_S *attr);
INT32 MPI_getDhzAttr(MPI_PATH idx, MPI_DHZ_ATTR_S *attr);
INT32 MPI_getDmsAttr(MPI_PATH idx, MPI_DMS_ATTR_S *attr);

INT32 MPI_setRoiAttr(MPI_PATH idx, const MPI_ROI_ATTR_S *attr);
INT32 MPI_setAeAttr(MPI_PATH idx, const MPI_AE_ATTR_S *attr);
INT32 MPI_setTeAttr(MPI_PATH idx, const MPI_TE_ATTR_S *attr);
INT32 MPI_setNrAttr(MPI_PATH idx, const MPI_NR_ATTR_S *attr);
INT32 MPI_setAwbAttr(MPI_PATH idx, const MPI_AWB_ATTR_S *attr);
INT32 MPI_setPtaAttr(MPI_PATH idx, const MPI_PTA_ATTR_S *attr);
INT32 MPI_setCsmAttr(MPI_PATH idx, const MPI_CSM_ATTR_S *attr);
INT32 MPI_setShpAttrV2(MPI_PATH idx, const MPI_SHP_ATTR_V2_S *attr);
INT32 MPI_setDipAttr(MPI_PATH idx, const MPI_DIP_ATTR_S *attr);
INT32 MPI_setIsoAttr(MPI_PATH idx, const MPI_ISO_ATTR_S *attr);
INT32 MPI_setEnhAttr(MPI_PATH idx, const MPI_ENH_ATTR_S *attr);
INT32 MPI_setCoringAttr(MPI_PATH idx, const MPI_CORING_ATTR_S *attr);
INT32 MPI_setHdrSynthAttr(MPI_PATH idx, const MPI_HDR_SYNTH_ATTR_S *attr);
INT32 MPI_setFcsAttr(MPI_PATH idx, const MPI_FCS_ATTR_S *attr);
INT32 MPI_setDhzAttr(MPI_PATH idx, const MPI_DHZ_ATTR_S *attr);
INT32 MPI_setDmsAttr(MPI_PATH idx, const MPI_DMS_ATTR_S *attr);

INT32 MPI_getDbcAttr(MPI_PATH idx, MPI_DBC_ATTR_S *attr);
INT32 MPI_getDccAttr(MPI_PATH idx, MPI_DCC_ATTR_S *attr);
INT32 MPI_getLscAttr(MPI_PATH idx, MPI_LSC_ATTR_S *attr);
INT32 MPI_getCalAttr(MPI_PATH idx, MPI_CAL_ATTR_S *attr);
INT32 MPI_setDbcAttr(MPI_PATH idx, const MPI_DBC_ATTR_S *attr);
INT32 MPI_setDccAttr(MPI_PATH idx, const MPI_DCC_ATTR_S *attr);
INT32 MPI_setLscAttr(MPI_PATH idx, const MPI_LSC_ATTR_S *attr);
INT32 MPI_setCalAttr(MPI_PATH idx, const MPI_CAL_ATTR_S *attr);

INT32 MPI_queryExposureInfo(MPI_PATH idx, MPI_EXPOSURE_INFO_S *info);
INT32 MPI_queryWhiteBalanceInfo(MPI_PATH idx, MPI_WHITE_BALANCE_INFO_S *info);
INT32 MPI_queryTeInfo(MPI_PATH idx, MPI_TE_INFO_S *info);

INT32 MPI_getStatistics(MPI_PATH idx, MPI_DIP_STAT_S *stat);
INT32 MPI_getStatisticsConfig(MPI_PATH idx, MPI_STAT_CFG_S *stat_config);
INT32 MPI_setStatisticsConfig(MPI_PATH idx, const MPI_STAT_CFG_S *stat_config);

INT32 MPI_getPcaTable(MPI_PATH idx, MPI_PCA_TABLE_S *table);
INT32 MPI_setPcaTable(MPI_PATH idx, const MPI_PCA_TABLE_S *table);

INT32 MPI_getWdrAttr(MPI_PATH idx, MPI_WDR_ATTR_S *attr);
INT32 MPI_setWdrAttr(MPI_PATH idx, const MPI_WDR_ATTR_S *attr);

/* Get/Set by window */
INT32 MPI_getWinShpAttrV2(MPI_WIN idx, MPI_SHP_ATTR_V2_S *attr);
INT32 MPI_getWinNrAttr(MPI_WIN idx, MPI_NR_ATTR_S *attr);
INT32 MPI_getWinEnhAttr(MPI_WIN idx, MPI_ENH_ATTR_S *attr);

INT32 MPI_setWinShpAttrV2(MPI_WIN idx, const MPI_SHP_ATTR_V2_S *attr);
INT32 MPI_setWinNrAttr(MPI_WIN idx, const MPI_NR_ATTR_S *attr);
INT32 MPI_setWinEnhAttr(MPI_WIN idx, const MPI_ENH_ATTR_S *attr);

/**
* @cond
*
* code fragment skipped by Doxygen.
*/

/* Deprecated MPI */

#define AE_MANUAL_ENABLE_EXP_VALUE _Pragma("GCC error \"AE_MANUAL_ENABLE_EXP_VALUE is deprecated.\"")(0x1)
#define AE_MANUAL_ENABLE_INTTIME _Pragma("GCC error \"AE_MANUAL_ENABLE_INTTIME is deprecated.\"")(0x2)
#define AE_MANUAL_ENABLE_SENSOR_GAIN _Pragma("GCC error \"AE_MANUAL_ENABLE_SENSOR_GAIN is deprecated.\"")(0x4)
#define AE_MANUAL_ENABLE_ISP_GAIN _Pragma("GCC error \"AE_MANUAL_ENABLE_ISP_GAIN is deprecated.\"")(0x8)
#define AE_MANUAL_ENABLE_SYS_GAIN _Pragma("GCC error \"AE_MANUAL_ENABLE_SYS_GAIN is deprecated.\"")(0x10)

__attribute__((error("MPI_setAeFps is deprecated. Please use MPI_setAeAttr instead."))) INT32
MPI_setAeFps(MPI_PATH idx, const FLOAT fps, FLOAT *fps_out);
__attribute__((error("MPI_getGammaAttr is not supported yet."))) INT32 MPI_getGammaAttr(MPI_PATH idx,
                                                                                        MPI_GAMMA_ATTR_S *attr);
__attribute__((error("MPI_setGammaAttr is not supported yet."))) INT32 MPI_setGammaAttr(MPI_PATH idx,
                                                                                        const MPI_GAMMA_ATTR_S *attr);

/* Ignore deprecated errors */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

__attribute__((error("MPI_getShpAttr is obsoleted. Please use MPI_setShpAttrV2 instead."))) INT32
MPI_getShpAttr(MPI_PATH idx, MPI_SHP_ATTR_S *attr);
__attribute__((error("MPI_setShpAttr is obsoleted. Please use MPI_setShpAttrV2 instead."))) INT32
MPI_setShpAttr(MPI_PATH idx, const MPI_SHP_ATTR_S *attr);
__attribute__((error("MPI_getWinShpAttr is obsoleted. Please use MPI_getWinShpAttrV2 instead."))) INT32
MPI_getWinShpAttr(MPI_WIN idx, MPI_SHP_ATTR_S *attr);
__attribute__((error("MPI_setWinShpAttr is obsoleted. Please use MPI_setWinShpAttrV2 instead."))) INT32
MPI_setWinShpAttr(MPI_WIN idx, const MPI_SHP_ATTR_S *attr);

#pragma GCC diagnostic pop

/**
 * @endcond
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !MPI_DIP_ALG_H */
