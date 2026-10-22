/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef LIB_ML_H_
#define LIB_ML_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#include "mpi_base_types.h"
#include "mpi_index.h"
#include "mpi_dev.h"
#include "mpi_iva.h"

typedef struct ml_cb_ctx {
	void *m_model;
	void *in_Mat;
	void *img_buf;
	uint32_t label_hyst;
} ML_CB_CTX_S;

int ML_OD_Init_PeopleVehiclePet(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
int ML_OD_Detect_PeopleVehiclePet(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx, MPI_IVA_OBJ_LIST_S *result,
                                  UINT8 *img);
int ML_OD_Exit_PeopleVehiclePet(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

int ML_OD_Init_PeopleVehiclePet_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
int ML_OD_Detect_PeopleVehiclePet_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx,
                                       MPI_IVA_OBJ_LIST_S *result, UINT8 *img);
int ML_OD_Exit_PeopleVehiclePet_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

int ML_OD_Init_PeopleVehicle(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
int ML_OD_Detect_PeopleVehicle(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx, MPI_IVA_OBJ_LIST_S *result,
                               UINT8 *img);
int ML_OD_Exit_PeopleVehicle(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

int ML_OD_Init_PeopleVehicle_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
int ML_OD_Detect_PeopleVehicle_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx,
                                    MPI_IVA_OBJ_LIST_S *result, UINT8 *img);
int ML_OD_Exit_PeopleVehicle_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

int ML_OD_Init_PeoplePet(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
int ML_OD_Detect_PeoplePet(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx, MPI_IVA_OBJ_LIST_S *result,
                           UINT8 *img);
int ML_OD_Exit_PeoplePet(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

int ML_OD_Init_PeoplePet_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
int ML_OD_Detect_PeoplePet_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx, MPI_IVA_OBJ_LIST_S *result,
                                UINT8 *img);
int ML_OD_Exit_PeoplePet_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

int ML_OD_Init_People(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
int ML_OD_Detect_People(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx, MPI_IVA_OBJ_LIST_S *result,
                        UINT8 *img);
int ML_OD_Exit_People(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

int ML_OD_Init_People_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);
int ML_OD_Detect_People_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx, MPI_IVA_OBJ_LIST_S *result,
                             UINT8 *img);
int ML_OD_Exit_People_Lite(const MPI_WIN idx, MPI_IVA_OD_CTX_S *od_ctx, void *cb_ctx);

#ifdef __cplusplus
}
#endif

#endif /* LIB_ML_H_ */
