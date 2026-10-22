/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_fgd.h
 * @brief Core feature-lib for foreground detection
 * @note Because the feature is still evolving, this module is experimental. No attempt
 * will be made to maintain API and ABI backward compatibility.
 */

#ifndef VFTR_FGD_H_
#define VFTR_FGD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_iva.h"
#include "vftr_dump.h"

#define VFTR_FGD_TIME_BUFFER_SIZE_MIN 16 /**< Minimum size of time buffer. */
#define VFTR_FGD_ROI_AREA_MIN 16 /**< Minimum area of RoI in unit square pixels. */
#define VFTR_FGD_PATH_LEN_MAX 128 /**< Reserved. */

/**
 * @brief Enum for data control
 */
typedef enum {
	VFTR_FGD_DATA_NONE = 0,
	VFTR_FGD_DATA_SAVE,
	VFTR_FGD_DATA_LOAD,
	VFTR_FGD_DATA_CTRL_NUM
} VFTR_FGD_DATA_CTRL_E;

/**
 * @brief Enum for event type
 */
typedef enum vftr_fgd_event_type {
	VFTR_FGD_OBJECT_MONITOR = 0, /**< Operating as an object monitor. */
	VFTR_FGD_EVENT_NUM
} VFTR_FGD_EVENT_TYPE_E;

/**
 * @brief Enum for object monitor event.
 * @see VFTR_FGD_EVENT_TYPE_E
 */
typedef enum vftr_fgd_object_event {
	VFTR_FGD_OBJECT_ABSENT = 0, /**< No foreground object detected. */
	VFTR_FGD_OBJECT_PRESENT, /**< Foreground object detected. */
	VFTR_FGD_OBJECT_BOUNDARY, /**< Foreground object detected near the boundary. */
	VFTR_FGD_OBJECT_ENTERING, /**< Foreground object entering. */
	VFTR_FGD_OBJECT_LEAVING, /**< Foreground object leaving. */
	VFTR_FGD_OBJECT_EVENT_NUM /**< Number of events. */
} VFTR_FGD_OBJECT_EVENT_E;

/**
 * @brief Struct for foreground detection parameter.
 */
typedef struct vftr_fgd_param {
	UINT8 sensitivity; /**< Higher sensitivity leads objects to easier be classified as foreground object.
	                    * It ranges [0, 255].
	                    */
	UINT8 boundary_thickness; /**< The thickness for RoI boundary judgement in pixels.
	                           * It should not be larger than half of shorter side of RoI.
	                           */
	UINT8 quality; /**< Higher quality value leads more frequently update.
	                * It ranges [0, 255].
	                */
	INT16 obj_life_th; /**< Threshold to filter out objects with low confidence.
	                    * It ranges [0, ::MPI_IVA_OD_MAX_LIFE].
	                    */
	UINT32 time_buffer; /**< Number of information to store. Unit: frames.
	                     * It ranges [::VFTR_FGD_TIME_BUFFER_SIZE_MIN, UINT_MAX].
	                     * @note
	                     * @arg Too large buffer might leads memory allocation failure.
	                     * See application note for further information.
	                     */
	MPI_RECT_POINT_S roi; /**< Target RoI to be observed in unit pixel.
	                       * Its size should larger than ::VFTR_FGD_ROI_AREA_MIN.
						   */
	VFTR_FGD_EVENT_TYPE_E event_type; /**< Expect foreground events to be detected. */
	INT32 suppression; /**< Enter/leaving event duration in unit number of frames.
	                    * It ranges [0, INT_MAX].
	                    */
} VFTR_FGD_PARAM_S;

/**
 * @brief Structure for the result of foreground detection.
 */
typedef struct vftr_fgd_status {
	BOOL fg_object; /**< Flag to indicate foreground object detected. */
	INT32 motion_level; /**< Foreground object motion level. */
	INT32 boundary_event; /**< Flag to indicate any object appears near the boundary. */
	VFTR_FGD_OBJECT_EVENT_E event; /**< Current event */
} VFTR_FGD_STATUS_S;

/**
 * @brief Structure for the foreground detection video features.
 */
typedef struct vftr_fgd_input {
	const MPI_IVA_OBJ_LIST_S *obj_list; /**< Pointer to object list
	                                      * @see MPI_IVA_getBitStreamObjList()
	                                      */
	UINT16 y_avg; /**< Y average value of the roi.
	                * @see MPI_DEV_getIspYAvg()
	                */
} VFTR_FGD_INPUT_S;

/**
 * @brief Type alias.
 */
typedef struct vftr_fgd_instance VFTR_FGD_INSTANCE_S;

VFTR_FGD_INSTANCE_S *VFTR_FGD_newInstance(void);
int VFTR_FGD_deleteInstance(VFTR_FGD_INSTANCE_S **instance);

int VFTR_FGD_checkParam(const VFTR_FGD_PARAM_S *param);
int VFTR_FGD_setParam(VFTR_FGD_INSTANCE_S *instance, const VFTR_FGD_PARAM_S *param);
int VFTR_FGD_getParam(const VFTR_FGD_INSTANCE_S *instance, VFTR_FGD_PARAM_S *param);
int _VFTR_FGD_dump(VFTR_FGD_INSTANCE_S *instance, const VFTR_FGD_INPUT_S *input, VFTR_FGD_STATUS_S *status);
int _VFTR_FGD_detect(VFTR_FGD_INSTANCE_S *instance, const VFTR_FGD_INPUT_S *input, VFTR_FGD_STATUS_S *status);
int VFTR_FGD_getStat(const VFTR_FGD_INSTANCE_S *instance, VFTR_FGD_STATUS_S *status);
int VFTR_FGD_reset(VFTR_FGD_INSTANCE_S *instance);

int VFTR_FGD_saveModel(const VFTR_FGD_INSTANCE_S *instance, const char *fpath);
int VFTR_FGD_loadModel(VFTR_FGD_INSTANCE_S *instance, const char *fpath);

/**
 * @brief An inline function. If variable vftr_dump_en is true,
 * then call dump function for debugging.
 * @see _VFTR_FGD_dump()
 * @see _VFTR_FGD_detect()
 */
FORCE_INLINE INT32 VFTR_FGD_detect(VFTR_FGD_INSTANCE_S *instance, const VFTR_FGD_INPUT_S *input,
                                   VFTR_FGD_STATUS_S *status)
{
	INT32 _err = _VFTR_FGD_detect(instance, input, status);
	if (vftr_dump_en) {
		_VFTR_FGD_dump(instance, input, status);
	}
	return _err;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_FGD_H_ */
