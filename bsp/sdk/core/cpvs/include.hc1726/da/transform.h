/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef DA_TRANSFORM_H_
#define DA_TRANSFORM_H_

#include "da_utils.h"

typedef struct ptr_10b {
	uint32_t pkg_id;
	uint32_t pkg_ptr;
} Ptr10b;

typedef struct yuv {
	uint8_t *y;
	uint8_t *u;
	uint8_t *v;
} Yuv;

void dram2raster_8b(DramInfo *di, FrameInfo *fi, uint8_t *out_buf);
void dram2raster_10b(DramInfo *di, FrameInfo *fi, uint8_t *out_buf);
void dram2raster_16b(DramInfo *di, FrameInfo *fi, uint8_t *out_buf);
void raster2dram_8b(DramInfo *di, FrameInfo *fi, const uint8_t *in_buf);
void raster2dram_10b(DramInfo *di, FrameInfo *fi, const uint8_t *in_buf);
void raster2dram_16b(DramInfo *di, FrameInfo *fi, const uint8_t *in_buf);

void dram2planar_8b(DramInfo *di, FrameInfo *fi, Yuv *yuv);
void dram2planar_10b(DramInfo *di, FrameInfo *fi, Yuv *yuv);
void planar2dram_8b(DramInfo *di, FrameInfo *fi, Yuv *yuv);
void planar2dram_10b(DramInfo *di, FrameInfo *fi, Yuv *yuv);

#endif