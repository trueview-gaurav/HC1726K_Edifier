/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_iva_rms.h
 * @brief MPI for IVA RMS (regional motion sensor)
 */

#ifndef MPI_IVA_RMS_H_
#define MPI_IVA_RMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_index.h"

#define MPI_IVA_RMS_MAX_REG_NUM 50 /**< Max RMS region number. */
#define MPI_IVA_RMS_MIN_REG_NUM 1 /**< Min RMS region number. */
#define MPI_IVA_RMS_MAX_SEN 255 /**< Max RMS sensitivity. */
#define MPI_IVA_RMS_MIN_SEN 0 /**< Min RMS sensitivity. */

typedef UINT32 MPI_RMS_CONF_BF; /**< Bit-filed of confidence. */

/**
 * @struct MPI_IVA_RMS_PARAM_S
 * @brief Structure for the parameters of RMS.
 * @details
 * @note split_x * split_y. Range [::MPI_IVA_RMS_MIN_REG_NUM, ::MPI_IVA_RMS_MAX_REG_NUM]
 * @see MPI_IVA_getRegMotSensParam()
 * @see MPI_IVA_setRegMotSensParam()
 * @property UINT8 MPI_IVA_RMS_PARAM_S::sen
 * @arg Range [::MPI_IVA_RMS_MIN_SEN, ::MPI_IVA_RMS_MAX_SEN]
 * @property UINT8 MPI_IVA_RMS_PARAM_S::split_x
 * @arg Range [::MPI_IVA_RMS_MIN_REG_NUM, ::MPI_IVA_RMS_MAX_REG_NUM]
 * @arg Limit: Resolution width % (split_x * 8) == 0.
 * @property UINT8 MPI_IVA_RMS_PARAM_S::split_y
 * @arg Range [::MPI_IVA_RMS_MIN_REG_NUM, ::MPI_IVA_RMS_MAX_REG_NUM]
 * @arg Limit: Resolution height % (split_y * 8) == 0.
 */
typedef struct mpi_iva_rms_param {
	UINT8 sen; /**< Sensitivity. */
	UINT8 split_x; /**< Split on x-axis. */
	UINT8 split_y; /**< Split on y-axis. */
} MPI_IVA_RMS_PARAM_S;

/**
 * @struct MPI_IVA_RMS_REG_ATTR_S
 * @brief Struct for region attributes.
 * @details
 * @see MPI_IVA_RMS_REG_LIST_S
 */
typedef struct mpi_iva_rms_reg_attr {
	MPI_RMS_CONF_BF conf; /**< Confidence level. */
} MPI_IVA_RMS_REG_ATTR_S;

/**
 * @struct MPI_IVA_RMS_REG_LIST_S
 * @brief Struct for region list.
 * @details
 * @see MPI_IVA_getRegMotSens()
 * @see MPI_IVA_RMS_PARAM_S
 * @property UINT32 MPI_IVA_RMS_REG_LIST_S::reg_cnt
 * @arg Equal: MPI_IVA_RMS_PARAM_S::split_x * MPI_IVA_RMS_PARAM_S::split_y
 */
typedef struct mpi_iva_rms_reg_list {
	UINT32 timestamp; /**< Time stamp. */
	UINT32 reg_cnt; /**< Number of region. */
	MPI_IVA_RMS_REG_ATTR_S reg[MPI_IVA_RMS_MAX_REG_NUM]; /**< Attributes of the region. */
} MPI_IVA_RMS_REG_LIST_S;

/* Interface function prototype */
INT32 MPI_IVA_enableRegMotSens(MPI_WIN idx);
INT32 MPI_IVA_disableRegMotSens(MPI_WIN idx);
INT32 MPI_IVA_setRegMotSensParam(MPI_WIN idx, const MPI_IVA_RMS_PARAM_S *param);
INT32 MPI_IVA_getRegMotSensParam(MPI_WIN idx, MPI_IVA_RMS_PARAM_S *param);
INT32 MPI_IVA_getRegMotSens(MPI_WIN idx, MPI_IVA_RMS_REG_LIST_S *list);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !MPI_IVA_RMS_H_ */
