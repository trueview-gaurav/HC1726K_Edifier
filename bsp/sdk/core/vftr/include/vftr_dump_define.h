/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_dump_define.h
 * @brief The definitions of message content
 */
#ifndef VFTR_DUMP_DEFINE_H_
#define VFTR_DUMP_DEFINE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>
#include <time.h>
#include "mpi_base_types.h"

#define VFTR_DUMP_ENABLE_PATH "/tmp/augentix/vftr_dump"

/**
 * @brief This is the field definition of the UINT32 flag
 */
typedef union vftr_dump_flag_v1 {
	UINT32 val;
	struct {
		UINT32 id : 10; /**< Data identy, i.e., ID_MPI_IVA_OBJ_LIST_S */

#define FLAG_TYPE_INPUT 0x1 /**< Input data */
#define FLAG_TYPE_OUTPUT 0x2 /**< Output data */
#define FLAG_TYPE_CTRL 0x4 /**< Control data including module parameters */
#define FLAG_TYPE_DEBUG 0x8 /**< Debugging data including module instance */
#define FLAG_TYPE_IMG 0x10 /**< Image data, often very large */
#define FLAG_TYPE_CUSTOM 0x20 /**< User specific data */
		UINT32 type : 6; /**< Data type, i.e., input, output, etc */

#define FLAG_CAT_VFTR 0x0 /**< VFTR category */
		UINT32 category : 3; /**< Data category, i.e, VFTR, EAIF etc. */

#define FLAG_PARENT_ID_NONE 0x3ff
		UINT32 group : 10; /**< Group id */
		UINT32 reserved : 1; /**< Reserved */

#define FLAG_VER_1 0x0 /**< Constant value for version 1 flag */
		UINT32 ver : 2; /**< Specify flag field version. See FLAG_VER_1 */
	} field;
} VFTR_DUMP_FLAG_V1_U;

#define FLAG_MASK_ID 0x3ff /**< Mask of id field */
#define FLAG_MASK_TYPE 0xfc00 /**< Mask of type field */
#define FLAG_MASK_CAT 0x70000 /**< Mask of catgory field */
#define FLAG_MASK_GROUP 0x1ff80000 /**< Mask of catgory field */
#define FLAG_MASK_VER 0xc0000000

#define FLAG_LENGTH_ID 10 /**< Bit length of id field */
#define FLAG_LENGTH_TYPE 6 /**< Bit length of type field */
#define FLAG_LENGTH_GROUP 10 /**< Bit length of category field */
#define FLAG_LENGTH_CAT 3 /**< Bit length of category field */

#define FLAG_MAX_ID_VALUE (1 << FLAG_LENGTH_ID) /**< Maximum id value */
#define FLAG_MAX_TYPE_VALUE (1 << FLAG_LENGTH_TYPE) /**< Maximum type value */
#define FLAG_MAX_GROUP_VALUE (1 << FLAG_LENGTH_GROUP) /**< Maximum category value */
#define FLAG_MAX_CAT_VALUE (1 << FLAG_LENGTH_CAT) /**< Maximum category value */

/* Array of structures for debugging */
#define EXPORT_VFTR_DUMP_ARRAY                             \
	EXPORT_DUMP(MPI_IVA_OBJ_LIST_S, FLAG_TYPE_INPUT)   \
	EXPORT_DUMP(MPI_ISP_VAR_S, FLAG_TYPE_INPUT)        \
	EXPORT_DUMP(MPI_ISP_MV_HIST_S, FLAG_TYPE_INPUT)    \
	EXPORT_DUMP(MPI_DIP_STAT_S, FLAG_TYPE_INPUT)       \
	EXPORT_DUMP(VFTR_MD_INSTANCE_S, FLAG_TYPE_DEBUG)   \
	EXPORT_DUMP(VFTR_MD_PARAM_S, FLAG_TYPE_CTRL)       \
	EXPORT_DUMP(VFTR_MD_STATUS_S, FLAG_TYPE_OUTPUT)    \
	EXPORT_DUMP(VFTR_EF_INSTANCE_S, FLAG_TYPE_DEBUG)   \
	EXPORT_DUMP(VFTR_EF_PARAM_S, FLAG_TYPE_CTRL)       \
	EXPORT_DUMP(VFTR_EF_STATUS_S, FLAG_TYPE_OUTPUT)    \
	EXPORT_DUMP(VFTR_AROI_INSTANCE_S, FLAG_TYPE_DEBUG) \
	EXPORT_DUMP(VFTR_AROI_PARAM_S, FLAG_TYPE_CTRL)     \
	EXPORT_DUMP(VFTR_AROI_STATUS_S, FLAG_TYPE_OUTPUT)  \
	EXPORT_DUMP(VFTR_SHD_INSTANCE_S, FLAG_TYPE_DEBUG)  \
	EXPORT_DUMP(VFTR_SHD_PARAM_S, FLAG_TYPE_CTRL)      \
	EXPORT_DUMP(VFTR_SHD_STATUS_S, FLAG_TYPE_OUTPUT)   \
	EXPORT_DUMP(VFTR_TD_MPI_INPUT_S, FLAG_TYPE_INPUT)  \
	EXPORT_DUMP(VFTR_TD_INSTANCE_S, FLAG_TYPE_DEBUG)   \
	EXPORT_DUMP(VFTR_TD_PARAM_S, FLAG_TYPE_CTRL)       \
	EXPORT_DUMP(VFTR_TD_STATUS_S, FLAG_TYPE_OUTPUT)    \
	EXPORT_DUMP(VFTR_DK_INSTANCE_S, FLAG_TYPE_DEBUG)   \
	EXPORT_DUMP(VFTR_DK_PARAM_S, FLAG_TYPE_CTRL)       \
	EXPORT_DUMP(VFTR_DK_STATUS_S, FLAG_TYPE_OUTPUT)    \
	EXPORT_DUMP(VFTR_LD_INSTANCE_S, FLAG_TYPE_DEBUG)   \
	EXPORT_DUMP(VFTR_LD_PARAM_S, FLAG_TYPE_CTRL)       \
	EXPORT_DUMP(VFTR_LD_STATUS_S, FLAG_TYPE_OUTPUT)    \
	EXPORT_DUMP(VFTR_FLD_INSTANCE_S, FLAG_TYPE_DEBUG)  \
	EXPORT_DUMP(VFTR_FLD_PARAM_S, FLAG_TYPE_CTRL)      \
	EXPORT_DUMP(VFTR_FLD_STATUS_S, FLAG_TYPE_OUTPUT)   \
	EXPORT_DUMP(VFTR_FGD_INSTANCE_S, FLAG_TYPE_DEBUG)  \
	EXPORT_DUMP(VFTR_FGD_INPUT_S, FLAG_TYPE_INPUT)     \
	EXPORT_DUMP(VFTR_FGD_PARAM_S, FLAG_TYPE_CTRL)      \
	EXPORT_DUMP(VFTR_FGD_STATUS_S, FLAG_TYPE_OUTPUT)   \
	EXPORT_DUMP(VFTR_PFM_INSTANCE_S, FLAG_TYPE_DEBUG)  \
	EXPORT_DUMP(VFTR_PFM_INPUT_S, FLAG_TYPE_INPUT)     \
	EXPORT_DUMP(VFTR_PFM_PARAM_S, FLAG_TYPE_CTRL)      \
	EXPORT_DUMP(VFTR_PFM_STATUS_S, FLAG_TYPE_OUTPUT)   \
	EXPORT_DUMP(VFTR_OSC_INSTANCE_S, FLAG_TYPE_DEBUG)  \
	EXPORT_DUMP(VFTR_OSC_PARAM_S, FLAG_TYPE_CTRL)      \
	EXPORT_DUMP(VFTR_OSC_STATUS_S, FLAG_TYPE_OUTPUT)   \
	EXPORT_DUMP(VFTR_LOD_INSTANCE_S, FLAG_TYPE_DEBUG)  \
	EXPORT_DUMP(VFTR_LOD_INPUT_S, FLAG_TYPE_INPUT)     \
	EXPORT_DUMP(VFTR_LOD_PARAM_S, FLAG_TYPE_CTRL)      \
	EXPORT_DUMP(VFTR_LOD_STATUS_S, FLAG_TYPE_OUTPUT)
/**<
 * @brief An array macro to collect all data structures for debugging
 * @note Maintain the following array if new VFTR structure added
 * PLEASE ADD NEW ELEMENT AT LAST
 */

#define EXPORT_DUMP(name, type) VFTR_ID_##name,
#define DECLARE_ENUM_ID(name, array) enum name { array MAX_VFTR_DUMP_ID_NUM };
/**<
 * @brief The following code generates structure ids
 * @details Produce the code like:
 * enum vftr_dump_id  {
 *      ID_MPI_IVA_OBJ_LIST_S,
 *      ID_VFTR_MD_INSTANCE_S,
 *      ID_VFTR_MD_PARAM_S,
 *      ID_VFTR_MD_STATUS_S,
 *      ...
 *      MAX_VFTR_DUMP_ID_NUM
 * };
 */

DECLARE_ENUM_ID(vftr_dump_id, EXPORT_VFTR_DUMP_ARRAY);

#undef EXPORT_DUMP
#undef DECLARE_ENUM_ID

#define EXPORT_DUMP(name, type) VFTR_TYPE_##name = (type),
#define DECLARE_ENUM_TYPE(name, array) enum name { array MAX_VFTR_DUMP_TYPE_NUM };
/**<
 * @brief The following code generates structure types
 * @details Produce the code like:
 * enum vfre_dump_type  {
 *      TYPE_MPI_IVA_OBJ_LIST_S = type,
 *      TYPE_VFTR_MD_INSTANCE_S = type,
 *      TYPE_VFTR_MD_PARAM_S = type,
 *      TYPE_VFTR_MD_STATUS_S = type,
 *      ...
 *      MAX_VFTR_DUMP_TYPE_NUM
 * };
 */

DECLARE_ENUM_TYPE(vftr_dump_type, EXPORT_VFTR_DUMP_ARRAY);

#undef EXPORT_DUMP
#undef DECLARE_ENUM_TYPE

#include "mpi_enc.h"

typedef pid_t PID_T;

/**
 * @brief Byte stream header for trasmitting dat through a FIFO
 * @details This header can be used to store data stream to a 
 * file. Use header to seperate different data instance.
 */
typedef struct vftr_dump_header_v1 {
#define VFTR_HEADER_INITCODE 0x4741 /**< 0x4741 = "AG" */
	UINT32 init_code : 16; /**< Should be 0x4741 */

#define VFTR_HEADER_VER_1 0x0
	UINT32 ver : 3; /**< Header version */
	UINT32 payload_len; /**< Size of data structure in bytes */
	VFTR_DUMP_FLAG_V1_U flag; /**< Flag */
	TIMESPEC_S timestamp; /**< Timestamp in wall clock */
	PID_T tid; /**< Thread id */
} VFTR_DUMP_HEADER_V1_S;

#ifdef __cplusplus
}
#endif

#endif /* VFTR_DUMP_DEFINE_H_ */
