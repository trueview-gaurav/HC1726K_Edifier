#ifdef USE_NCNN
#include "resize_neon.h"

#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)<(b)?(b):(a))

const int COEFF_Y     = 64;
const int COEFF_R_V   = 101;
const int COEFF_G_U   = -11;
const int COEFF_G_V   = -29;
const int COEFF_B_U   = 119;
const int CONST_R = -12868;
const int CONST_G = 5401;
const int CONST_B = -15169;
const int OFFSET_Y = 0;
const int BITSFT = 6;

inline uint8_t saturate_u8(int val) {
	return static_cast<uint8_t>(MAX(0, MIN(val, 255)));
}

/**
 * @brief Efficiently crop, bi-linear resize and convert NV12 image ROI to RGB with enhanced boundary checking.
 * @param y_plane Pointer to source Y plane
 * @param uv_plane Pointer to source UV plane (NV12, U/V interleaved)
 * @param src_width Width of source image
 * @param src_height Height of source image
 * @param crop_x X coordinate of crop region top-left corner
 * @param crop_y Y coordinate of crop region top-left corner
 * @param crop_w Width of crop region
 * @param crop_h Height of crop region
 * @param dst_rgb_buffer Pointer to destination RGB buffer
 * @param dst_w Width of destination image
 * @param dst_h Height of destination image
 * @return true if successful, false if invalid parameters or boundary violations
 */
bool yuv_cropped_bilinear_resized_to_rgb(
		const uint8_t* y_plane, const uint8_t* uv_plane,
		int src_width, int src_height,
		int crop_x, int crop_y, int crop_w, int crop_h,
		uint8_t* dst_rgb_buffer, int dst_w, int dst_h) {

	crop_x &= ~1; crop_y &= ~1;
	crop_w &= ~1; crop_h &= ~1;
	if (crop_y + crop_h > src_height) crop_h = (src_height - crop_y) & ~1;
	if (crop_x + crop_w > src_width) crop_w = (src_width - crop_x) & ~1;

	// boundary check
	if (dst_w <= 0 || dst_h <= 0 || crop_w < 2 || crop_h < 2 || crop_x < 0 || crop_y < 0) return false;

	const float x_scale = static_cast<float>(crop_w) / dst_w;
	const float y_scale = static_cast<float>(crop_h) / dst_h;

	for (int dy = 0; dy < dst_h; ++dy) {
		uint8_t* row_ptr = dst_rgb_buffer + dy * dst_w * 3;
		for (int dx = 0; dx < dst_w; ++dx) {

			// calculate the floating-point coordinates in the source "cropped" image.
			// using (dx + 0.5) * scale - 0.5 aligns pixel centers for better quality.
			float src_x_f = (dx + 0.5f) * x_scale - 0.5f;
			float src_y_f = (dy + 0.5f) * y_scale - 0.5f;

			// Clamp coordinates to the crop area.
			src_x_f = MAX(0.0f, MIN(src_x_f, static_cast<float>(crop_w - 1)));
			src_y_f = MAX(0.0f, MIN(src_y_f, static_cast<float>(crop_h - 1)));

			// calculate interpolation parameters for the Y plane.
			int y_sx1 = static_cast<int>(src_x_f);
			int y_sy1 = static_cast<int>(src_y_f);
			int y_sx2 = MIN(y_sx1 + 1, crop_w - 1);
			int y_sy2 = MIN(y_sy1 + 1, crop_h - 1);

			float x_weight = src_x_f - y_sx1;
			float y_weight = src_y_f - y_sy1;

			// add the absolute offset of the crop area.
			int abs_y_sx1 = crop_x + y_sx1; int abs_y_sy1 = crop_y + y_sy1;
			int abs_y_sx2 = crop_x + y_sx2; int abs_y_sy2 = crop_y + y_sy2;

			// get the four adjacent pixels from the Y plane.
			float y_tl = y_plane[abs_y_sy1 * src_width + abs_y_sx1];
			float y_tr = y_plane[abs_y_sy1 * src_width + abs_y_sx2];
			float y_bl = y_plane[abs_y_sy2 * src_width + abs_y_sx1];
			float y_br = y_plane[abs_y_sy2 * src_width + abs_y_sx2];

			// calculate the final Y value using bilinear interpolation.
			float y_top = y_tl * (1.0f - x_weight) + y_tr * x_weight;
			float y_bottom = y_bl * (1.0f - x_weight) + y_br * x_weight;
			int y = static_cast<int>(y_top * (1.0f - y_weight) + y_bottom * y_weight + 0.5f);

			// calculate interpolation for the UV plane
			// the UV plane has half the resolution of the Y plane.
			float src_uv_x_f = src_x_f / 2.0f;
			float src_uv_y_f = src_y_f / 2.0f;
			int uv_sx1 = static_cast<int>(src_uv_x_f);
			int uv_sy1 = static_cast<int>(src_uv_y_f);
			int uv_sx2 = MIN(uv_sx1 + 1, (crop_w / 2) - 1);
			int uv_sy2 = MIN(uv_sy1 + 1, (crop_h / 2) - 1);

			float uv_x_weight = src_uv_x_f - uv_sx1;
			float uv_y_weight = src_uv_y_f - uv_sy1;

			// get the absolute coordinates of the four adjacent pixel pairs (U,V) in the UV plane.
			const uint8_t* uv_tl_ptr = uv_plane + ((crop_y/2 + uv_sy1) * src_width) + ((crop_x/2 + uv_sx1) * 2);
			const uint8_t* uv_tr_ptr = uv_plane + ((crop_y/2 + uv_sy1) * src_width) + ((crop_x/2 + uv_sx2) * 2);
			const uint8_t* uv_bl_ptr = uv_plane + ((crop_y/2 + uv_sy2) * src_width) + ((crop_x/2 + uv_sx1) * 2);
			const uint8_t* uv_br_ptr = uv_plane + ((crop_y/2 + uv_sy2) * src_width) + ((crop_x/2 + uv_sx2) * 2);

			// perform bilinear interpolation separately for U and V channels.
			float u_top = uv_tl_ptr[0] * (1.0f - uv_x_weight) + uv_tr_ptr[0] * uv_x_weight;
			float u_bottom = uv_bl_ptr[0] * (1.0f - uv_x_weight) + uv_br_ptr[0] * uv_x_weight;
			int u = static_cast<int>(u_top * (1.0f - uv_y_weight) + u_bottom * uv_y_weight + 0.5f);

			float v_top = uv_tl_ptr[1] * (1.0f - uv_x_weight) + uv_tr_ptr[1] * uv_x_weight;
			float v_bottom = uv_bl_ptr[1] * (1.0f - uv_x_weight) + uv_br_ptr[1] * uv_x_weight;
			int v = static_cast<int>(v_top * (1.0f - uv_y_weight) + v_bottom * uv_y_weight + 0.5f);

			// convert to RGB using the interpolated Y, U, and V values.
			int y_prime = MAX(OFFSET_Y, y);
			int u_prime = u;
			int v_prime = v;

			int r = (COEFF_Y * y_prime + COEFF_R_V * v_prime + CONST_R) >> BITSFT;
			int g = (COEFF_Y * y_prime + COEFF_G_V * v_prime + COEFF_G_U * u_prime + CONST_G) >> BITSFT;
			int b = (COEFF_Y * y_prime + COEFF_B_U * u_prime + CONST_B) >> BITSFT;

			// write to the destination buffer.
			uint8_t* pixel_ptr = row_ptr + dx * 3;
			pixel_ptr[0] = saturate_u8(r);
			pixel_ptr[1] = saturate_u8(g);
			pixel_ptr[2] = saturate_u8(b);
		}
	}
	return true;
}

void hwc_to_padded_chw(const uint8_t* resize_buf, float* inputBuffer, int width, int height, int roi_width, int roi_height,
					   float norm, float pad) {
	int area = roi_width * roi_height;
	int x_offset = (roi_width - width) / 2;
	int y_offset = (roi_height - height) / 2;

	for (int y = 0; y < roi_height; ++y) {
		for (int x = 0; x < roi_width; ++x) {
			int src_x = x - x_offset;
			int src_y = y - y_offset;
			if (src_y >= 0 && src_y < height && src_x >= 0 && src_x < width) {
				// Origin area
				int src_idx = (src_y * width + src_x) * 3;
				int dst_idx = y * roi_width + x;

				inputBuffer[dst_idx] = static_cast<float>(resize_buf[src_idx]) / norm;
				inputBuffer[area + dst_idx] = static_cast<float>(resize_buf[src_idx + 1]) / norm;
				inputBuffer[2 * area + dst_idx] = static_cast<float>(resize_buf[src_idx + 2]) / norm;
			} else {
				// Padding area
				int dst_idx = y * roi_width + x;
				inputBuffer[dst_idx] = pad;
				inputBuffer[area + dst_idx] = pad;
				inputBuffer[2 * area + dst_idx] = pad;
			}
		}
	}
}
#endif