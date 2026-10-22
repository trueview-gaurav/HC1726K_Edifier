#ifndef __PKG_SEI_SERVER_H__
#define __PKG_SEI_SERVER_H__

#ifdef CONFIG_SAMPLE_DEMO_PKG_SUPPORT_SEI
#include "avftr_conn.h"
#include "avftr_conn.c"
extern AVFTR_VIDEO_CTX_S *vftr_res_shm;

static int findOdCtx(MPI_WIN idx, VIDEO_OD_CTX_S *ctx, int *empty);
static int clearOdCtx(MPI_WIN idx, VIDEO_OD_CTX_S *ctx);
static int findVftrBufCtx(MPI_WIN idx, const AVFTR_VIDEO_BUF_INFO_S *ctx, int *empty);
static int clearVftrBufCtx(MPI_WIN idx, AVFTR_VIDEO_BUF_INFO_S *info);
static int updateBufferIdx(AVFTR_VIDEO_BUF_INFO_S *buf_info, UINT32 timestamp);
static int initSeiServer(MPI_WIN win_idx);
static void exitSeiServer(MPI_WIN idx);

#else

// If that's no need to generated SEI, skips the actions.
static int initSeiServer(MPI_WIN win __attribute__((unused)));
static void exitSeiServer(MPI_WIN idx __attribute__((unused)));

#endif
#include "pkg_sei_server.c"

#endif
