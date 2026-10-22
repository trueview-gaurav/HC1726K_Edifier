#ifndef NCNN_UTILS_H_
#define NCNN_UTILS_H_

#include <stdint.h>

typedef struct ncnn_remote_ctx {
	void *img; // pointer to origin image
	void *pimg; // pointer to origin image
	void *arena; // pointer to input/output buffer
	void *model_data_param; // pointer to model param
	void *model_data_bin; // pointer to model bin
	int m_input_dim[3];
	int m_output_dim[4];
	int rect_pos[4]; // rect position: sx sy ex ey
	int roi_size;
	int window_size[2]; // window_w window_h
	uint32_t img_paddr_offset; // offset to Chrominance's physical address
	uint8_t use_int8_inference;
	uint8_t use_winograd_convolution;
	uint8_t use_sgemm_convolution;
	uint8_t use_packing_layout;
	uint8_t flexible_input;
} NCNN_REMOTE_CTX;

#endif // NCNN_UTILS_H_