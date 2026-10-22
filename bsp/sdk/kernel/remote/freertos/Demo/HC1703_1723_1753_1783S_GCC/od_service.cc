#ifdef USE_NCNN
#include "net.h" // ncnn
#include "od_service.h"
#include "ncnn_utils.h"
#include "utils/printf.h"
#include "inf_remote.h"
#include "FreeRTOS.h"
#include "task.h"
#include "resize_neon.h"

#define __DEBUG__ 0
#define LPRINTF(format, ...) printf("[RTOS OD]: " format, ##__VA_ARGS__)


#if (__DEBUG__)
#define LOG_SECTION(__section_name, __stmts)          \
	printf("<<< Start of " #__section_name "\n"); \
	__stmts;                                      \
	printf(">>> End of " #__section_name "\n")
#else
#define LOG_SECTION(__section_name, __stmts)          \
	__stmts;
#endif

static ncnn::Net *g_net;
static ncnn::Mat *in_Mat;
static ncnn::UnlockedPoolAllocator *g_blob_pool_allocator;
static ncnn::PoolAllocator *g_workspace_pool_allocator;

static uint8_t *resize_buf;

static unsigned char *model_data_param;
static unsigned char *model_data_bin;
static int init_ = 0;

static int update_od_model_shape(ncnn::Net* net, int target_width, int target_height) {
	/* NOTE: the INDICES and VALUES are dedicated for ODv5.2 */
	int _h, _w, _d, _c;
	int total = 0;

	// Precomputed constants
	int wxh = (target_width >> 3) * (target_height >> 3);
	int head_w = target_width >> 5;
	int head_h = target_height >> 5;

	// Helper lambda to update layer dimensions
	auto update_layer = [&](int layer_index, int new_w, int new_h = -1) {
		net->mutable_layers()[layer_index]->get_attr(_h, _w, _d, _c);
		net->mutable_layers()[layer_index]->set_attr(new_h == -1 ? _h : new_h, new_w, _d, _c);
	};

	std::vector<int> layer_indices_1(2);
	layer_indices_1[0] = 251;
	layer_indices_1[1] = 252;
	for (int layer_index : layer_indices_1) {
		update_layer(layer_index, wxh);
		total += wxh;
		wxh >>= 2; // Divide wxh by 4
	}

	total += wxh;
	std::vector<int> layer_indices_2(3);
	layer_indices_2[0] = 253;
	layer_indices_2[1] = 105;
	layer_indices_2[2] = 125;
	for (int layer_index : layer_indices_2) {
		update_layer(layer_index, wxh);
	}

	// Update layers 256 and 260 with tota
	std::vector<int> layer_indices_3(2);
	layer_indices_3[0] = 256;
	layer_indices_3[1] = 260;
	for (int layer_index : layer_indices_3) {
		update_layer(layer_index, total);
	}

	// Update tensor dimensions in layers
	std::vector<int> layer_indices_4(4);
	layer_indices_4[0] = 113;
	layer_indices_4[1] = 114;
	layer_indices_4[2] = 133;
	layer_indices_4[3] = 134;
	for (int layer_index : layer_indices_4) {
		update_layer(layer_index, head_w, head_h);
	}

	return 0;
}

void od_load_model_handler(ampi_svc svc, void* data, int len, svc_event_t evn)
{
	if (evn == SVC_CLEAN) {
		return;
	}

	int32_t result = AMPI_SUCCESS;

	if (init_) {
		LPRINTF("Model initializaed in RTOS, delete old parameters... \n");
		delete in_Mat; in_Mat = nullptr;
		delete g_net; g_net = nullptr;
		delete g_workspace_pool_allocator; g_workspace_pool_allocator = nullptr;
		delete g_blob_pool_allocator; g_blob_pool_allocator = nullptr;
		free(resize_buf); resize_buf = nullptr;
	} else {
		LPRINTF("Model initializing in RTOS... \n");
	}

	auto ncnn_ctx = static_cast<NCNN_REMOTE_CTX*>(data);

	g_net = new ncnn::Net;
	if (!g_net) {
	    LPRINTF("g_net init failed \n");
		result = AMPI_FAILURE;
		ampi_send(svc, &result, sizeof(result), -1);
		return;
	}

	g_blob_pool_allocator = new ncnn::UnlockedPoolAllocator;
	g_workspace_pool_allocator = new ncnn::PoolAllocator;

	if (!g_blob_pool_allocator || !g_workspace_pool_allocator) {
	    if (!g_blob_pool_allocator) LPRINTF("g_blob_pool_allocator init failed \n");
	    if (!g_workspace_pool_allocator) LPRINTF("g_blob_pool_allocator init failed \n");
		result = AMPI_FAILURE;
		ampi_send(svc, &result, sizeof(result), -1);
		return;
	}
	g_blob_pool_allocator->set_size_compare_ratio(0.f);
	g_workspace_pool_allocator->set_size_compare_ratio(0.f);

	g_net->opt.use_local_pool_allocator = false;
	g_net->opt.lightmode = true;
	g_net->opt.blob_allocator = g_blob_pool_allocator;
	g_net->opt.workspace_allocator = g_workspace_pool_allocator;

	g_net->opt.use_winograd_convolution = ncnn_ctx->use_winograd_convolution;
	g_net->opt.use_sgemm_convolution = ncnn_ctx->use_sgemm_convolution;
	g_net->opt.use_int8_inference = ncnn_ctx->use_int8_inference;
	g_net->opt.use_packing_layout = ncnn_ctx->use_packing_layout;

	model_data_param = (unsigned char*)ncnn_ctx->model_data_param;
	model_data_bin = (unsigned char*)ncnn_ctx->model_data_bin;

	int sizeOfParam = g_net->load_param(model_data_param);
	// LPRINTF("size of param : %d\n", sizeOfParam);
	int sizeOfBin = g_net->load_model(model_data_bin);
	// LPRINTF("size of bin : %d\n", sizeOfBin);

	if (sizeOfParam == 0 || sizeOfBin == 0) {
		LPRINTF("model load failed \n");
		result = AMPI_FAILURE;
		ampi_send(svc, &result, sizeof(result), -1);
		return;
	}

	in_Mat = new ncnn::Mat(ncnn_ctx->m_input_dim[1], ncnn_ctx->m_input_dim[0], ncnn_ctx->m_input_dim[2],
						   ncnn_ctx->arena);
	if (!in_Mat) {
	    LPRINTF("in_Mat init failed \n");
		result = AMPI_FAILURE;
		ampi_send(svc, &result, sizeof(result), -1);
		return;
	}

	resize_buf = nullptr;
	resize_buf = (uint8_t*)malloc(ncnn_ctx->roi_size*ncnn_ctx->roi_size*3);
	if (resize_buf == nullptr) {
		LPRINTF("resize buffer init failed \n");
		result = AMPI_FAILURE;
		ampi_send(svc, &result, sizeof(result), -1);
		return;
	}

	if (ncnn_ctx->flexible_input) {
		update_od_model_shape(g_net, ncnn_ctx->roi_size, ncnn_ctx->roi_size);
	}
	ampi_send(svc, &result, sizeof(result), -1);
	init_ = 1;
	LPRINTF("Model initialization success in RTOS\n");
}

void od_model_forward_handler(ampi_svc svc, void* data, int len, svc_event_t evn)
{
	if (evn == SVC_CLEAN) {
	    LPRINTF("evn == SVC_CLEAN, return!!\n");
	    return;
	}
	int32_t result = AMPI_SUCCESS;
	if (data == nullptr || g_net == nullptr) {
	    if (!data) LPRINTF("data is null, return\n");
	    if (!g_net) LPRINTF("g_net is null, return\n");
	    result = AMPI_FAILURE;
	    ampi_send(svc, &result, sizeof(result), -1);
	    return;
	}
	auto ncnn_ctx = static_cast<NCNN_REMOTE_CTX*>(data);

	const uint8_t *y_uptr = (uint8_t*)ncnn_ctx->pimg;
	const uint8_t *c_uptr = (uint8_t*)((uint32_t)y_uptr + (uint32_t)ncnn_ctx->img_paddr_offset);

	const int crop_width = ncnn_ctx->rect_pos[2] - ncnn_ctx->rect_pos[0] + 1;
	const int crop_height = ncnn_ctx->rect_pos[3] - ncnn_ctx->rect_pos[1] + 1;

	float scale = static_cast<float>(ncnn_ctx->roi_size) / std::max(crop_width, crop_height);
	int resized_w = round(crop_width * scale);
	int resized_h = round(crop_height * scale);

	resized_w = std::min(resized_w, ncnn_ctx->roi_size);
	resized_h = std::min(resized_h, ncnn_ctx->roi_size);

	bool ret = yuv_cropped_bilinear_resized_to_rgb(
			y_uptr,
			c_uptr,
			ncnn_ctx->window_size[0],
			ncnn_ctx->window_size[1],
			ncnn_ctx->rect_pos[0],
			ncnn_ctx->rect_pos[1],
			crop_width,
			crop_height,
			resize_buf,
			resized_w,
			resized_h
	);

	// Notify linux to free the ISP snapshot to reduce the blocking time
	ampi_send(svc, &result, sizeof(result), -1);

	float *inputBuffer =  (float *)in_Mat->data;
	hwc_to_padded_chw(resize_buf, inputBuffer, resized_w, resized_h, ncnn_ctx->roi_size, ncnn_ctx->roi_size,
					  1.0, 114.0);

	ncnn::Extractor ex = g_net->create_extractor();
	if(ex.input(0, *in_Mat) == -1){
	    LPRINTF("ncnn input error\n");
	    result = AMPI_FAILURE;
	    ampi_send(svc, &result, sizeof(result), -1);
	    return;
	}

	// Extract output from ncnn model
	ncnn::Mat out_Mat;
	if(ex.extract((int)g_net->blobs().size()-1, out_Mat) == -1) {
	    LPRINTF("ncnn extract error\n");
	    result = AMPI_FAILURE;
	    ampi_send(svc, &result, sizeof(result), -1);
	    return;
	}
	// TickType_t end_mark = xTaskGetTickCount();

//	ncnn_ctx->m_output_dim[0] = out_Mat.c;
//	ncnn_ctx->m_output_dim[1] = out_Mat.h;
//	ncnn_ctx->m_output_dim[2] = out_Mat.w;

	size_t size = (size_t)out_Mat.w * out_Mat.h * out_Mat.c * out_Mat.elemsize;
	// LPRINTF("output c: %d\n", (int)out_Mat.c);
	// LPRINTF("output h: %d\n", (int)out_Mat.h);
	// LPRINTF("output w: %d\n", (int)out_Mat.w);
	// LPRINTF("output size: %d\n", size);

	memcpy(ncnn_ctx->arena, out_Mat.data, size);

//	TickType_t duration_ms = (end_mark - start_mark) * 1000 / configTICK_RATE_HZ;
//	LPRINTF("{%X} forwarding model network in %d ms => %d\n", svc, duration_ms, result);
	ampi_send(svc, &result, sizeof(result), -1);
}

#endif //USE_NCNN
