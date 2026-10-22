/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_iva.h
 * @brief MPI for IVA OD (object detection)
 */

#ifndef MPI_IVA_H_
#define MPI_IVA_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <sys/time.h>
#include "mpi_index.h"

#define MPI_IVA_MAX_OBJ_NUM 10 /**< Max object number. */

#define MPI_IVA_OD_MAX_QUA 63 /**< Max OD quality index. */
#define MPI_IVA_OD_MIN_QUA 0 /**< Min OD quality index. */
#define MPI_IVA_OD_MAX_TRACK_REFINE 63 /**< Max OD track refinement index. */
#define MPI_IVA_OD_MIN_TRACK_REFINE 0 /**< Min OD track refinement index. */
#define MPI_IVA_OD_MAX_OBJ_SIZE 255 /**< Max OD object size(percentage in a frame size). */
#define MPI_IVA_OD_MIN_OBJ_SIZE 0 /**< Min OD object size(percentage in a frame size). */
#define MPI_IVA_OD_MAX_SEN 255 /**< Max OD sensitivity. */
#define MPI_IVA_OD_MIN_SEN 0 /**< Min OD sensitivity. */
#define MPI_IVA_OD_MAX_LIFE 160 /**< Max OD life of object. */
#define MPI_IVA_OD_ENABLE_STOP_DET 1 /**< Enable OD stop detect of object. */
#define MPI_IVA_OD_DISABLE_STOP_DET 0 /**< Disable OD stop detect of object. */
#define MPI_IVA_OD_ENABLE_GMV_DET 1 /**< Enable OD global motion vector detection. */
#define MPI_IVA_OD_DISABLE_GMV_DET 0 /**< Disable OD global motion vector detection. */
#define MPI_IVA_OD_MOTOR_ENABLE 1 /**< Enable OD camera motor when gmv detection is enabled. */
#define MPI_IVA_OD_MOTOR_DISABLE 0 /**< Disable OD camera motor when gmv detection is enabled. */

#define MPI_IVA_OD_MAX_CONF 255 /**< Max OD confidience level. */
#define MPI_IVA_OD_MIN_CONF 0 /**< Min OD confidience level. */
#define MPI_IVA_OD_MAX_IOU 255 /**< Max Intersection over Union level of two objects. */
#define MPI_IVA_OD_MIN_IOU 0 /**< Min Intersection over Union level of two objects. */
#define MPI_IVA_OD_SNAPSHOT_Y 0 /**< Snapshot Y only. */
#define MPI_IVA_OD_SNAPSHOT_NV12 1 /**< Snapshot NV12. */
#define MPI_IVA_OD_SNAPSHOT_RGB 2 /**< Snapshot RGB. */
/**
 * @struct MPI_IVA_OD_PARAM_S
 * @brief Structure for the parameters of object detection.
 * @details
 * @see MPI_IVA_setObjParam()
 * @see MPI_IVA_getObjParam()

 * @property UINT8 MPI_IVA_OD_PARAM_S::od_conf_th
 * @arg Range [::MPI_IVA_OD_MIN_CONF, ::MPI_IVA_OD_MAX_CONF]
 * @property UINT8 MPI_IVA_OD_PARAM_S::od_iou_th
 * @arg Range [::MPI_IVA_OD_MIN_IOU, ::MPI_IVA_OD_MAX_IOU]
 * @property UINT16 MPI_IVA_OD_PARAM_S::od_snapshot_w
 * @arg Range [::MPI_CHN_RES_HOR_MINIMUM, ::MPI_CHN_RES_HOR_MAXIMUM]
 * @property UINT16 MPI_IVA_OD_PARAM_S::od_snapshot_h
 * @arg Range [::MPI_CHN_RES_VER_MINIMUM, ::MPI_CHN_RES_VER_MAXIMUM]
 * @property UINT8 MPI_IVA_OD_PARAM_S::od_qual
 * @arg Range [::MPI_IVA_OD_MIN_QUA, ::MPI_IVA_OD_MAX_QUA]
 * @property UINT8 MPI_IVA_OD_PARAM_S::od_track_refine
 * @arg Range [::MPI_IVA_OD_MIN_TRACK_REFINE, ::MPI_IVA_OD_MAX_TRACK_REFINE]
 * @property UINT8 MPI_IVA_OD_PARAM_S::od_size_th
 * @arg Range [::MPI_IVA_OD_MIN_OBJ_SIZE, ::MPI_IVA_OD_MAX_OBJ_SIZE]
 * @property UINT8 MPI_IVA_OD_PARAM_S::od_sen
 * @arg Range [::MPI_IVA_OD_MIN_SEN, ::MPI_IVA_OD_MAX_SEN]
 * @property UINT8 MPI_IVA_OD_PARAM_S::od_life_decay_level
 * @arg Range [0, 16]
 * @property UINT8 MPI_IVA_OD_PARAM_S::en_stop_det
 * @arg Disable: ::MPI_IVA_OD_DISABLE_STOP_DET
 * @arg Enable : ::MPI_IVA_OD_ENABLE_STOP_DET
 * @property UINT8 MPI_IVA_OD_PARAM_S::en_gmv_det
 * @arg Disable: ::MPI_IVA_OD_DISABLE_GMV_DET
 * @arg Enable : ::MPI_IVA_OD_ENABLE_GMV_DET
 * @property UINT8 MPI_IVA_OD_PARAM_S::en_gmv_det
 * @arg Y : ::MPI_IVA_OD_SNAPSHOT_Y
 * @arg NV12 : ::MPI_IVA_OD_SNAPSHOT_NV12
 * @arg RGB : ::MPI_IVA_OD_SNAPSHOT_RGB
 */

typedef struct mpi_iva_od_param {
	UINT32 od_snapshot_w; /**< Snapshot width for OD detect */
	UINT32 od_snapshot_h; /**< Snapshot heigh for OD detect */
	UINT8 od_conf_th; /**< Object confidence threshold. */
	UINT8 od_iou_th; /**< NMS iou threshold. */
	UINT8 od_qual; /**< Quality index of OD performance. */
	UINT8 od_track_refine; /**< Tracking refinement. */
	UINT8 od_size_th; /**< Object size threshold. */
	UINT8 od_sen; /**< Object sensitivity. */
	UINT8 od_life_decay_level; /**< Level of object life decay. */
	UINT8 en_stop_det; /**< Indicate whether stop detect of object is enabled. */
	UINT8 en_gmv_det; /**< Indicate whether global motion vector detection is enabled. */
	UINT8 od_snapshot_type; /**< Snapshot type for OD detect */
} MPI_IVA_OD_PARAM_S;

/**
 * @struct MPI_IVA_OD_MOTOR_PARAM_S
 * @brief Structure for the parameters of camera motor.
 * @details
 * @see MPI_IVA_setObjMotorParam()
 * @see MPI_IVA_getObjMotorParam()
 * @property UINT8 MPI_IVA_OD_MOTOR_PARAM_S::en_motor
 * @arg Disable: ::MPI_IVA_OD_MOTOR_DISABLE
 * @arg Enable : ::MPI_IVA_OD_MOTOR_ENABLE
 */
typedef struct mpi_iva_od_motor_param {
	UINT8 en_motor; /**< Indicate whether camera motor is enabled.*/
} MPI_IVA_OD_MOTOR_PARAM_S;

/**
 * @struct MPI_IVA_OBJ_ATTR_S
 * @brief Struct for object attributes.
 * @details
 * @see MPI_IVA_OBJ_LIST_S
 * @property UINT8 MPI_IVA_OBJ_ATTR_S::id
 * @arg Range [0, INT_MAX)
 * @property UINT8 MPI_IVA_OBJ_ATTR_S::life
 * @arg Range [0, ::MPI_IVA_OD_MAX_LIFE]
 */
typedef struct mpi_iva_obj_attr {
	INT32 id; /**< ID of object. */
	INT16 life; /**< Life of object. */
	MPI_RECT_POINT_S rect; /**< Rectangle point of object. */
	MPI_MOTION_VEC_S mv; /**< Motion vector of object. */
	UINT32 cat; /**< Category ID of the object*/
	UINT8 conf; /**< Confidence score of the object prediction*/
} MPI_IVA_OBJ_ATTR_S;

/**
 * @struct MPI_IVA_OBJ_LIST_S
 * @brief Struct for object list.
 * @details
 * @property UINT8 MPI_IVA_OBJ_LIST_S::obj_num
 * @arg Range [0, ::MPI_IVA_MAX_OBJ_NUM]
 */
typedef struct mpi_iva_obj_list {
	UINT32 timestamp; /**< Time stamp. */
	INT32 obj_num; /**< Number of objects. */
	MPI_IVA_OBJ_ATTR_S obj[MPI_IVA_MAX_OBJ_NUM]; /**< Attributes list of the objects. */
} MPI_IVA_OBJ_LIST_S;

/**
 * @struct MPI_IVA_OD_CTX_S
 * @brief Structure for Object Detection (OD) context.
 *
 * This structure holds the context information needed for the Object Detection (OD) algorithm.
 * It includes parameters for the OD algorithm and a private data pointer for any additional
 * implementation-specific data.
 */
typedef struct mpi_iva_od_ctx {
	/**
     * @brief Pointer to the parameters for the OD algorithm.
     *
     * This member points to a structure containing the parameters required by the OD algorithm.
     */
	MPI_IVA_OD_PARAM_S *param;

	/**
     * @brief Pointer to private data.
     *
     * This member points to private data used internally by the OD algorithm.
     * The content and usage of this data are specific to the implementation of the OD algorithm.
     */
	VOID *priv;
} MPI_IVA_OD_CTX_S;

/**
 * @struct MPI_IVA_OD_CALLBACK_S
 * @brief This structure defines the callback functions for an Object Detection (OD) algorithm.
 *
 * This structure contains pointers to functions that initialize, run, and terminate an OD algorithm.
 */
typedef struct mpi_iva_od_callback {
	/**
     * @brief Initialize the global context of the OD algorithm.
     *
     * This function initializes the global context required by the OD algorithm.
     *
     * @param[in] idx Index of the window.
     * @param[in,out] od_ctx Pointer to the OD context structure.
     * @param[in,out] cb_ctx Pointer to the callback context.
     * @return Integer indicating the success or failure of the initialization.
     * @retval MPI_SUCCESS Initialization was successful.
     * @retval Non-zero Initialization failed.
     */
	INT32 (*init)(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

	/**
     * @brief Run the OD algorithm.
     *
     * This function executes the OD algorithm on the provided image.
     *
     * @param[in] idx Index of the window.
     * @param[in,out] od_ctx Pointer to the OD context structure.
     * @param[in,out] cb_ctx Pointer to the callback context.
     * @param[out] result Pointer to the structure where detection results will be stored.
     * @param[in] img Pointer to the image data.
     * @return Integer indicating the success or failure of the detection.
     * @retval MPI_SUCCESS Detection was successful.
     * @retval Non-zero Detection failed.
     */
	INT32(*detect)(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx, MPI_IVA_OBJ_LIST_S *result, UINT8 *img);

	/**
     * @brief Exit the OD algorithm.
     *
     * This function releases any resources allocated by the OD algorithm and performs cleanup.
     *
     * @param idx[in] Index of the window.
     * @param od_ctx[in,out] Pointer to the OD context structure.
     * @param cb_ctx[in,out] Pointer to the callback context.
     * @return Integer indicating the success or failure of the cleanup.
     * @retval MPI_SUCCESS Cleanup was successful.
     * @retval Non-zero Cleanup failed.
     */
	INT32 (*exit)(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
} MPI_IVA_OD_CALLBACK_S;

/* Interface function prototype */
INT32 MPI_IVA_enableObjDet(MPI_WIN idx);
INT32 MPI_IVA_disableObjDet(MPI_WIN idx);
INT32 MPI_IVA_setObjParam(MPI_WIN idx, const MPI_IVA_OD_PARAM_S *param);
INT32 MPI_IVA_getObjParam(MPI_WIN idx, MPI_IVA_OD_PARAM_S *param);
INT32 MPI_IVA_setObjMotorParam(MPI_WIN idx, const MPI_IVA_OD_MOTOR_PARAM_S *param);
INT32 MPI_IVA_getObjMotorParam(MPI_WIN idx, MPI_IVA_OD_MOTOR_PARAM_S *param);
INT32 MPI_IVA_getBitStreamObjList(MPI_WIN idx, UINT32 timestamp, MPI_IVA_OBJ_LIST_S *list);
INT32 MPI_IVA_regOdCallback(const MPI_WIN idx, const MPI_IVA_OD_CALLBACK_S *cb, void *cb_ctx);

/**
* @cond
*
* code fragment skipped by Doxygen.
*/

/* Deprecated MPI */

__attribute__((error("MPI_IVA_getObjList is deprecated. Please use MPI_IVA_getBitStreamObjList instead."))) INT32
MPI_IVA_getObjList(MPI_WIN idx, MPI_IVA_OBJ_LIST_S *list);

/**
 * @endcond
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MPI_IVA_H_ */
