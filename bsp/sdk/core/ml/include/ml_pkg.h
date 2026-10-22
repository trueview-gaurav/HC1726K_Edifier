/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef LIB_ML_PKG_H_
#define LIB_ML_PKG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#include "mpi_base_types.h"
#include "mpi_index.h"
#include "mpi_dev.h"
#include "mpi_iva.h"

#define ML_PKG_ROI_AREA_MIN 16 /**< Minimum area of RoI in unit square pixels. */
#define ML_PKG_MAX_NOISE_LEVEL 7
#define ML_PKG_MAX_DIFF_TH 1023
#define ML_PKG_MAX_REG_NUM (MPI_MAX_ISP_VAR_CFG_NUM <= 10 ? MPI_MAX_ISP_VAR_CFG_NUM : 10)

/**
 * @brief Enum for event type
 */
typedef enum ml_pkg_event_type {
	ML_PKG_EVENT_LEFT_OBJECT = 0, /**< detect left-object event. */
	ML_PKG_EVENT_PACKAGE = 1, /**< detect package event. */
	ML_PKG_EVENT_NUM = 2
} ML_PKG_EVENT_TYPE_E;

/**
 * @brief Enum ML_PKG_RETURN_TYPE
 */
typedef enum ml_pkg_return_type {
	ML_PKG_MPI_SUCCESS = 0, /**< detect left-object event. */
	ML_PKG_INSTANCE_EMPTY = 1,
	ML_PKG_ROI_EMPTY = 2,
	ML_PKG_INPUT_EMPTY = 3,
	ML_PKG_STATUS_EMPTY = 4,
	ML_PKG_CAM_READY_FOR_SLEEP = 5
} ML_PKG_RETURN_TYPE;

/**
 * @brief Enum for package detection result.
 */
typedef enum ml_pkg_det_result {
	ML_PKG_DET_IDLE = 0, /**< No package detected. */
	ML_PKG_DET_IN = 1, /**< Package detected. */
	ML_PKG_DET_OUT = 2, /**< Package leaving. */
	ML_PKG_DET_NUM = 3 /**< Number of enum ML_PKG_DET_RESULT_E. */
} ML_PKG_DET_RESULT_E;

/**
 * @brief Enum for Camera status
 */
typedef enum ml_pkg_cam_event {
	ML_PKG_CAM_NORMAL = 0, /**< Camera Normal, no special event*/
	ML_PKG_CAM_ASLEEP = 1, /**< Make Camera asleep */
} ML_PKG_CAM_EVENT;

typedef struct {
	INT32 motion_level; /**< Motion level in RoI. */
	ML_PKG_DET_RESULT_E result; /**< Detection result */
	INT32 life_counter; // debug purpose
} ML_PKG_REG_STAT_S;

/**
 * @brief Struct for left-object detection parameter.
 */
typedef struct ml_pkg_param {
	UINT16 pkg_snapshot_w;
	UINT16 pkg_snapshot_h;
	UINT16 idle2in_th; /**< The threshold to judge the status transition from IDLE to IN.
	                       * Lower idle2in_th makes it easier for objects to be detected as package.
	                       * It ranges [0, 1023].
	                       */
	UINT16 in2idle_th; /**< The threshold to judge the status transition from IN to IDLE.
	                       * Lower in2idle_th makes it easier to return to idle status.
	                       * It ranges [0, 1023].
						   */
	INT32 region_num; /**< Number of config, which represents RoI.
	                   * It ranges [1, 10].
	                   */
	MPI_RECT_POINT_S roi[ML_PKG_MAX_REG_NUM]; /**< Target RoI to be observed in unit pixel.
	                                             * Its size should larger than ::ML_PKG_ROI_AREA_MIN.
	                                             */
	ML_PKG_EVENT_TYPE_E event_type; /**< Expect left-object / package events to be detected. */
	INT32 duration; /**< Duration threshold for an object to be considered "left object"
	                 * Unit: milliseconds. It ranges [0, 34000].
	                 */
	INT32 background_merge_delay; /**< Time after which left object is merged into background.
	                               * Unit: seconds. It ranges [0, INT_MAX / fps].
	                               */
} ML_PKG_PARAM_S;

/**
 * @brief Structure for the result of left-object detection.
 */
typedef struct ml_pkg_status {
	INT32 region_num;
	ML_PKG_REG_STAT_S stat[ML_PKG_MAX_REG_NUM];
} ML_PKG_STATUS_S;

/**
 * @brief Structure for the left-object detection video features.
 */
typedef struct ml_pkg_input {
	const MPI_IVA_OBJ_LIST_S *obj_list; /**< Pointer to object list
	                                     * @see MPI_IVA_getBitStreamObjList()
	                                     */
	INT32 region_num; /**< Number of config, which represents RoI.
	                   * It ranges [1, 5].
	                   */
	UINT16 frame_y_avg; /**< Y average value of the frame.
	                                         * @see MPI_DEV_getIspYAvg()
	                                         */
	UINT16 roi_y_avg[ML_PKG_MAX_REG_NUM]; /**< Y average value of the roi.
	                                       * @see MPI_DEV_getIspYAvg()
	                                       */
	MPI_ISP_VAR_S texture_var[ML_PKG_MAX_REG_NUM]; /**< Texture variance value of roi.
	                                                * @see MPI_DEV_getIspVar()
	                                                */
	ML_PKG_CAM_EVENT camera_event;	// New update, need to report
									/**
									 * It have three kinds of type, awake, asleep and normal(running).
									*/
} ML_PKG_INPUT_S;

/**
 * @brief Type alias.
 */
typedef struct ml_pkg_instance ML_PKG_INSTANCE_S;

ML_PKG_INSTANCE_S *ML_PKG_newInstance(const MPI_WIN idx);
INT32 ML_PKG_deleteInstance(ML_PKG_INSTANCE_S **instance);

INT32 ML_PKG_checkParam(const ML_PKG_PARAM_S *param);
INT32 ML_PKG_setParam(ML_PKG_INSTANCE_S *instance, const ML_PKG_PARAM_S *param);
INT32 ML_PKG_getParam(const ML_PKG_INSTANCE_S *instance, ML_PKG_PARAM_S *param);
ML_PKG_RETURN_TYPE ML_PKG_detect(ML_PKG_INSTANCE_S *instance, const ML_PKG_INPUT_S *input, ML_PKG_STATUS_S *status);

INT32 ML_PKG_reset(ML_PKG_INSTANCE_S *instance);
#ifdef __cplusplus
}
#endif

#endif /* LIB_ML_PKG_H_ */
