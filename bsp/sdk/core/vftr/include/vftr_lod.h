/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_lod.h
 * @brief Core feature-lib for left-object detection
 * @note Because the feature is still evolving, this module is experimental. No attempt
 * will be made to maintain API and ABI backward compatibility.
 */

#ifndef VFTR_LOD_H_
#define VFTR_LOD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_iva.h"
#include "mpi_dev.h"
#include "vftr_dump.h"

#define VFTR_LOD_ROI_AREA_MIN 16 /**< Minimum area of RoI in unit square pixels. */
#define VFTR_LOD_MAX_NOISE_LEVEL 7
#define VFTR_LOD_MAX_REG_NUM 10

/**
 * @brief Enum for event type
 */
typedef enum vftr_lod_event_type {
	VFTR_LOD_OBJECT_MONITOR = 0, /**< Operating as an object monitor. */
	VFTR_LOD_EVENT_NUM
} VFTR_LOD_EVENT_TYPE_E;

/**
 * @brief Enum for object monitor event.
 * @see VFTR_LOD_EVENT_TYPE_E
 */
typedef enum vftr_lod_object_event {
	VFTR_LOD_OBJECT_IDLE = 0, /**< No left object detected. */
	VFTR_LOD_OBJECT_IN, /**< Left object detected. */
	VFTR_LOD_OBJECT_OUT, /**< Left object leaving. */
	VFTR_LOD_OBJECT_EVENT_NUM /**< Number of events. */
} VFTR_LOD_OBJECT_EVENT_E;

typedef struct {
	BOOL lft_object; /**< Flag to indicate left object detected. */
	INT32 motion_level; /**< Left object motion level. */
	VFTR_LOD_OBJECT_EVENT_E event; /**< Current event */
} VFTR_LOD_REG_STAT_S;

/**
 * @brief Struct for left-object detection parameter.
 */
typedef struct vftr_lod_param {
	UINT8 noise_level; /**< Higher noise_level makes it easier for objects to be classified as left objects.
	                    * It ranges [0, 7].
	                    */
	INT32 region_num; /**< Number of config, which represents RoI.
	                   * It ranges [1, 10].
	                   */
	MPI_RECT_POINT_S roi[VFTR_LOD_MAX_REG_NUM]; /**< Target RoI to be observed in unit pixel.
	                                             * Its size should larger than ::VFTR_LOD_ROI_AREA_MIN.
	                                             */
	VFTR_LOD_EVENT_TYPE_E event_type; /**< Expect left-object events to be detected. */
	INT32 duration; /**< Duration threshold for an object to be considered "left object"
	                 * Unit: milliseconds. It ranges [0, INT_MAX].
	                 */
	INT32 background_merge_delay; /**< Time after which left object is merged into background.
	                               * Unit: milliseconds. It ranges [0, INT_MAX].
	                               */
} VFTR_LOD_PARAM_S;

/**
 * @brief Structure for the result of left-object detection.
 */
typedef struct vftr_lod_status {
	INT32 region_num;
	VFTR_LOD_REG_STAT_S stat[VFTR_LOD_MAX_REG_NUM];
} VFTR_LOD_STATUS_S;

/**
 * @brief Structure for the left-object detection video features.
 */
typedef struct vftr_lod_input {
	const MPI_IVA_OBJ_LIST_S *obj_list; /**< Pointer to object list
	                                     * @see MPI_IVA_getBitStreamObjList()
	                                     */
	INT32 region_num; /**< Number of config, which represents RoI.
	                   * It ranges [1, 10].
	                   */
	UINT16 y_avg[VFTR_LOD_MAX_REG_NUM]; /**< Y average value of the roi.
	                                     * @see MPI_DEV_getIspYAvg()
	                                     */
	MPI_ISP_VAR_S texture_var[VFTR_LOD_MAX_REG_NUM]; /**< Texture variance value of roi.
	                                                  * @see MPI_DEV_getIspVar()
	                                                  */

} VFTR_LOD_INPUT_S;

/**
 * @brief Type alias.
 */
typedef struct vftr_lod_instance VFTR_LOD_INSTANCE_S;

VFTR_LOD_INSTANCE_S *VFTR_LOD_newInstance(void);
int VFTR_LOD_deleteInstance(VFTR_LOD_INSTANCE_S **instance);

int VFTR_LOD_checkParam(const VFTR_LOD_PARAM_S *param);
int VFTR_LOD_setParam(VFTR_LOD_INSTANCE_S *instance, const VFTR_LOD_PARAM_S *param);
int VFTR_LOD_getParam(const VFTR_LOD_INSTANCE_S *instance, VFTR_LOD_PARAM_S *param);
int _VFTR_LOD_dump(VFTR_LOD_INSTANCE_S *instance, const VFTR_LOD_INPUT_S *input, VFTR_LOD_STATUS_S *status);
int _VFTR_LOD_detect(VFTR_LOD_INSTANCE_S *instance, const VFTR_LOD_INPUT_S *input, VFTR_LOD_STATUS_S *status);
int VFTR_LOD_getStat(const VFTR_LOD_INSTANCE_S *instance, VFTR_LOD_STATUS_S *status);
int VFTR_LOD_reset(VFTR_LOD_INSTANCE_S *instance);

/**
 * @brief An inline function. If variable vftr_dump_en is true,
 * then call dump function for debugging.
 * @see _VFTR_LOD_dump()
 * @see _VFTR_LOD_detect()
 */
FORCE_INLINE INT32 VFTR_LOD_detect(VFTR_LOD_INSTANCE_S *instance, const VFTR_LOD_INPUT_S *input,
                                   VFTR_LOD_STATUS_S *status)
{
	INT32 _err = _VFTR_LOD_detect(instance, input, status);
	if (vftr_dump_en) {
		_VFTR_LOD_dump(instance, input, status);
	}
	return _err;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_LOD_H_ */
