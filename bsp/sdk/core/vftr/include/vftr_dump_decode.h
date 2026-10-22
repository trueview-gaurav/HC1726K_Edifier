/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_dump_decode.h
 * @brief Core feature-lib for decoding messages
 */
#ifndef VFTR_DECODE_H_
#define VFTR_DECODE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "mpi_base_types.h"
#include "vftr_dump_define.h"

/* Function interfaces */
INT32 VFTR_linkDump(const char *path);
VOID VFTR_unlinkDump();
INT32 VFTR_readDump(VOID **buf, UINT32 *flag, TIMESPEC_S *timestamp, PID_T *tid);
INT32 VFTR_showDump(const VOID *buf, size_t count, UINT32 flag, TIMESPEC_S timestamp, PID_T tid);

#ifdef __cplusplus
}
#endif

#endif
