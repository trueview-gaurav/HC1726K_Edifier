#ifdef USE_NCNN
#ifndef LIB_RESIZE_NEON_H_
#define LIB_RESIZE_NEON_H_

#include <stdlib.h>
//#include <vector> // already define in ncnn simplestl
//#include <queue> // already define in ncnn simplestl
#include <cstring>
#include <arm_neon.h>

#ifdef __cplusplus
extern "C" {
#endif

bool yuv_cropped_bilinear_resized_to_rgb(
		const uint8_t* y_plane, const uint8_t* uv_plane,
		int src_width, int src_height,
		int crop_x, int crop_y, int crop_w, int crop_h,
		uint8_t* dst_rgb_buffer, int dst_w, int dst_h);
void hwc_to_padded_chw(const uint8_t *resize_buf, float *inputBuffer, int width, int height, int roi_width,
                       int roi_height, float norm=255.0, float pad=0);

#ifdef __cplusplus
}
#endif

#endif //LIB_RESIZE_NEON_H_
#endif