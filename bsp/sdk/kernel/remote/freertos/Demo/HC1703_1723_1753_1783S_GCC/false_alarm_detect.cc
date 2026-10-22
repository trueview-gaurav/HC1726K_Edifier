#ifdef EARLY_DETECT
#include <stdint.h>

#include "utils/printf.h"

#include "false_alarm_detect_utils.h"

#include "ncnn_utils.h"
#include "FreeRTOS.h"
#include "task.h"
#include "resize_neon.h"
#include "m_early_detect.mem.h"

#include "od_service.h"

// #include "net.h" // ncnn
// #include "inf_remote.h"

#if FALSE_ALARM_SIMULATE
// #include "rgb_chw_data.h"
// #include "model_output.h"
#endif

struct csr_control {
	uint32_t *csr;
	uint32_t mask;
	uint32_t value;
};

struct detect {
	volatile uint32_t type;
	volatile uint32_t threshold;
	volatile void *data;

	volatile struct csr_control alarm_on;
	volatile struct csr_control alarm_off;
};

static inline void write_csr(uint32_t *csr, uint32_t value)
{
	*((volatile uint32_t *)(csr)) = value;
}

static inline uint32_t read_csr(uint32_t *csr)
{
	return *((volatile uint32_t *)(csr));
}

static void run_csr_control(volatile struct csr_control *control)
{
	uint32_t tmp;
	if (control->csr != NULL) {
		tmp = (read_csr(control->csr) & ~(control->mask));
		write_csr(control->csr, tmp | control->value);
	} else {
	}
}

typedef struct early_detect_ctx {
	UbootMvInfo mv_info;
	UbootSnapshotInfo snapshot_info;
	uint8_t is_used; /* Flag indicating whether this snapshot has been used and can be freed. */
} EARLY_DETECT_CTX;

static ncnn::Net *g_net;
static ncnn::Mat *in_Mat;
static ncnn::UnlockedPoolAllocator *g_blob_pool_allocator;
static ncnn::PoolAllocator *g_workspace_pool_allocator;

static uint8_t *resize_buf;

static unsigned char *model_data_param;
static unsigned char *model_data_bin;
static MovObjAttr roi_debug;

static int init_ = 0;

#ifdef USE_EARLY_OD
void od_debug_roi_handler(ampi_svc svc, void* data, int len, svc_event_t evn)
{
	if (evn == SVC_CLEAN) {
		return;
	}
	ampi_send(svc, &roi_debug, sizeof(roi_debug), -1);
	return;
}

void od_load_early_handler(ampi_svc svc, void* data, int len, svc_event_t evn)
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

	model_data_param = (unsigned char*)m_early_detect_param_bin;
	model_data_bin = (unsigned char*)m_early_detect_bin;

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

	ampi_send(svc, &result, sizeof(result), -1);
	init_ = 1;

	update_model_shape(*g_net, ncnn_ctx->roi_size, ncnn_ctx->roi_size);
}

void od_early_forward_handler(ampi_svc svc, void* data, int len, svc_event_t evn)
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
	// Insert image to ncnn model
	//	LPRINTF("input c: %d\n", (int)in_Mat->c);
	//	LPRINTF("input h: %d\n", (int)in_Mat->h);
	//	LPRINTF("input w: %d\n", (int)in_Mat->w);

	//	TickType_t start_mark = xTaskGetTickCount();

	float *inputBuffer =  (float *)in_Mat->data;
	hwc_to_padded_chw(resize_buf, inputBuffer, resized_w, resized_h, ncnn_ctx->roi_size, ncnn_ctx->roi_size);

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
	TickType_t end_mark = xTaskGetTickCount();

//	ncnn_ctx->m_output_dim[0] = out_Mat.c;
//	ncnn_ctx->m_output_dim[1] = out_Mat.h;
//	ncnn_ctx->m_output_dim[2] = out_Mat.w;

	size_t size = (size_t)out_Mat.w * out_Mat.h * out_Mat.c * out_Mat.elemsize;
//	LPRINTF("output c: %d\n", (int)out_Mat.c);
//	LPRINTF("output h: %d\n", (int)out_Mat.h);
//	LPRINTF("output w: %d\n", (int)out_Mat.w);
//	LPRINTF("output size: %d\n", size);

	memcpy(ncnn_ctx->arena, out_Mat.data, size);

//	TickType_t duration_ms = (end_mark - start_mark) * 1000 / configTICK_RATE_HZ;
//	LPRINTF("{%X} forwarding model network in %d ms => %d\n", svc, duration_ms, result);
	ampi_send(svc, &result, sizeof(result), -1);
}
#endif	// USE_EARLY_OD

static int detect(uint32_t type, uint32_t sensitivity, void *data)
{
	auto early_ai_ctx = static_cast<EARLY_DETECT_CTX*>(data);
	early_ai_ctx->is_used = 1;
	return 0;
// #if FALSE_ALARM_DEBUG
// 	LPRINTF("type: %d, sensitivity: %d\n", type, sensitivity);
// #endif
// 	uint32_t result = 0;	// switch to power off by default
// 	float threshold = 0;
// 
// 	// convert sensibility to map probability
// 	threshold = 100 - std::min(std::max(0, static_cast<int>(sensitivity)), 100);
// 	threshold = threshold / 100.f;
// 
// 	/* load model */
// 
// 	auto early_ai_ctx = static_cast<EARLY_DETECT_CTX*>(data);
// 	UbootMvInfo early_ai_mv_info = early_ai_ctx->mv_info;
// 	UbootSnapshotInfo early_ai_snapshot_info = early_ai_ctx->snapshot_info;
// 
// 	// --------- SAMPLE FOR ROI DETECT -----------
// 	static CurrMovObjList roi_list;
// 	memset(&roi_list, 0, sizeof(CurrMovObjList));
// 	int roi_exist = false;
// 	getROIsFromMV(&early_ai_mv_info, &roi_list);
// 
// 	RECT_POINT_S roi_max;
// 	int roi_max_idx;
// 	if (roi_list.obj_cnt > 0) {
// 		// refine and enlarge 1.2 times first, then pick the max ROI, to prevent boundary event
// 		for (int i = 0; i < roi_list.obj_cnt; i++) {
// 			refineROI(roi_list.obj[i].rect, ROI_MIN_SIZE, early_ai_mv_info.win_width, early_ai_mv_info.win_height);
// 		}
// 		getMaxROIFromList(&roi_list, &roi_max, &roi_max_idx);
// 		roi_exist = true;
// 	} else {
// 		// shut down DUT if there is no motion
// 		return 0;
// 	}
// 	roi_debug.rect = roi_max;
// 	roi_debug.mv = roi_list.obj[roi_max_idx].mv;
// 
// 	g_net = new ncnn::Net;
// 	if (!g_net) {
// 		LPRINTF("g_net init failed \n");
// 		return 0;
// 	}
// 
// 	g_blob_pool_allocator = new ncnn::UnlockedPoolAllocator;
// 	g_workspace_pool_allocator = new ncnn::PoolAllocator;
// 
// 	if (!g_blob_pool_allocator || !g_workspace_pool_allocator) {
// 		if (!g_blob_pool_allocator) LPRINTF("g_blob_pool_allocator init failed \n");
// 		if (!g_workspace_pool_allocator) LPRINTF("g_blob_pool_allocator init failed \n");
// 		return 0;
// 	}
// 	g_blob_pool_allocator->set_size_compare_ratio(0.f);
// 	g_workspace_pool_allocator->set_size_compare_ratio(0.f);
// 
// 	g_net->opt.use_local_pool_allocator = false;
// 	g_net->opt.lightmode = true;
// 	g_net->opt.blob_allocator = g_blob_pool_allocator;
// 	g_net->opt.workspace_allocator = g_workspace_pool_allocator;
// 
// 	g_net->opt.use_winograd_convolution = use_winograd_convolution;
// 	g_net->opt.use_sgemm_convolution = use_sgemm_convolution;
// 	g_net->opt.use_int8_inference = use_int8_inference;
// 	g_net->opt.use_packing_layout = use_packing_layout;
// 
// 	model_data_param = (unsigned char*)m_early_detect_param_bin;
// 	model_data_bin = (unsigned char*)m_early_detect_bin;
// 
// 	int sizeOfParam = g_net->load_param(model_data_param);
// 	int sizeOfBin = g_net->load_model(model_data_bin);
// #if FALSE_ALARM_DEBUG
// 	LPRINTF("size of param : %d\n", sizeOfParam);
// 	LPRINTF("size of bin : %d\n", sizeOfBin);
// #endif
// 
// 	if (sizeOfParam == 0 || sizeOfBin == 0) {
// 		LPRINTF("model load failed \n");
// 		return 0;
// 	}
// 
// 	in_Mat = new ncnn::Mat(m_input_dim[1], m_input_dim[0], m_input_dim[2]);
// 	if (!in_Mat) {
// 		LPRINTF("in_Mat init failed \n");
// 		return 0;
// 	}
// 
// 	/* model forward */
// 
// #if !(FALSE_ALARM_SIMULATE)
// 	uint16_t window_size[2];
// #if FALSE_ALARM_DEBUG
// 	LPRINTF("input width: %d\n", (int)early_ai_snapshot_info.width);
// 	LPRINTF("input height: %d\n", (int)early_ai_snapshot_info.height);
// #endif
// 	window_size[0] = early_ai_snapshot_info.width;
// 	window_size[1] = early_ai_snapshot_info.height;
// 
// 	const uint8_t *y_uptr = (uint8_t*)early_ai_snapshot_info.phy_addr_y;
// 	const uint8_t *c_uptr = (uint8_t*)early_ai_snapshot_info.phy_addr_c;
// 
// #if FALSE_ALARM_DEBUG
// 	// Insert image to ncnn model
// 	LPRINTF("input c: %d\n", (int)in_Mat->c);
// 	LPRINTF("input h: %d\n", (int)in_Mat->h);
// 	LPRINTF("input w: %d\n", (int)in_Mat->w);
// #endif
// 
// 	const int crop_width = roi_max.ex - roi_max.sx + 1;
// 	const int crop_height = roi_max.ey - roi_max.sy + 1;
// 	const int dst_stride = crop_width * 3;
// 	int roi_size = m_input_dim[0];	// 256
// 
// 	float scale = static_cast<float>(roi_size) / std::max(crop_width, crop_height);
// 	int resized_w = round(crop_width * scale);
// 	int resized_h = round(crop_height * scale);
// 
// 	resized_w = std::min(resized_w, roi_size);
// 	resized_h = std::min(resized_h, roi_size);
// 
// 	int hpad = (m_input_dim[0] - resized_h) / 2;
// 	int wpad = (m_input_dim[1] - resized_w) / 2;
// 
// 	uint8_t* resize_image = (uint8_t*)malloc(resized_w * resized_h * 3);
// 	if (resize_image == nullptr) {
// 	    LPRINTF("resize_image init failed\n");
// 	    return 0;
// 	}
// 
// 	bool ret = yuv_cropped_bilinear_resized_to_rgb(
// 		y_uptr,
// 		c_uptr,
// 		window_size[0],
// 		window_size[1],
// 		roi_max.sx,
// 		roi_max.sy,
// 		crop_width,
// 		crop_height,
// 		resize_image,
// 		resized_w,
// 		resized_h
// 	);
// 
// 	// Notify linux to free the ISP snapshot to reduce the blocking time
// 	early_ai_ctx->is_used = 1;
// 
// 	float *inputBuffer =  (float *)in_Mat->data;
// 	hwc_to_padded_chw(resize_image, inputBuffer, resized_w, resized_h, roi_size, roi_size);
// 	free(resize_image);
// 	resize_image = nullptr;
// 
// 	// // write inputBuffer back to phy_addr_y, then dump to see result of model input
// 	// memcpy(early_ai_snapshot_info.phy_addr_y, inputBuffer, roi_size * roi_size * 3 * sizeof(float));
// 
// #else
// 	// memcpy(in_Mat->data, rgb_chw_data, RGB_WIDTH * RGB_HEIGHT * RGB_CHANNELS * sizeof(float));
// #endif	// FALSE_ALARM_SIMULATE
// 
// 	update_model_shape(*g_net, m_input_dim[1], m_input_dim[0]);
// 
// 	ncnn::Extractor ex = g_net->create_extractor();
// 	if(ex.input(0, *in_Mat) == -1){
// 		LPRINTF("ncnn input error\n");
// 		return 0;
// 	}
// 
// 	// Extract output from ncnn model
// 	ncnn::Mat out_Mat;
// 	if(ex.extract((int)g_net->blobs().size()-1, out_Mat) == -1) {
// 		LPRINTF("ncnn extract error\n");
// 		return 0;
// 	}
// 
// #if FALSE_ALARM_DEBUG
// 	size_t size = (size_t)out_Mat.w * out_Mat.h * out_Mat.c * out_Mat.elemsize;
// 	LPRINTF("output c: %d\n", (int)out_Mat.c);
// 	LPRINTF("output h: %d\n", (int)out_Mat.h);
// 	LPRINTF("output w: %d\n", (int)out_Mat.w);
// 	LPRINTF("output size: %d\n", size);
// #endif
// 
// #if FALSE_ALARM_SIMULATE
// 	// float diff = 0;
// 	// for(int i = 0; i < out_Mat.h * out_Mat.w * out_Mat.c; i++){
// 	// 	diff += out_Mat[i] - model_output[i];
// 	// }
// 	// LPRINTF("model output total diff: %d\n", (int)diff);
// #endif
// 
// 	/* decode model output */
// 
// 	bool detect_human = false;
// 	bool detect_vehicle = false;
// 
// 	if (type == 1 || type == 3) {
// 		detect_human = true;
// 	}
// 	if (type == 2 || type == 3) {
// 		detect_vehicle = true;
// 	}
// 
// #if FALSE_ALARM_DEBUG
// 	std::vector<DetBox> feature_list;
// 	std::vector<DetBox> roi_output;
// #endif
// 
// 	bool obj_in = false;
// 	std::vector<int> base_offset;
// 	/*Calculate the offset values of each channel*/
// 	/*x1, y1, x2, y2, cat_1, cat_2, cat3*/
// 	int temp = 0;
// 	for (int i = 0; i < class_num + 4; i++) {
// 		base_offset.push_back(temp);
// 		temp += out_Mat.w;
// 	}
// 
// 	int step = 0;
// 	float g_max_prob = -1;
// 	for (int stride = 8; stride <= 32 && !obj_in; stride <<= 1) {
// 		int head_width = m_input_dim[1] / stride;
// 		int head_height = m_input_dim[0] / stride;
// 		DetBox box;
// 		for (int y = 0; y < head_height && !obj_in; y++) {
// 			for (int x = 0; x < head_width; x++) {
// 				float max_prob = -1;
// 				int cat = 0;
// 				float prob_human = -1;
// 				float prob_vehicle = -1;
// 				if (detect_human) {
// 					int idx = step + base_offset[4];
// 					if (out_Mat[idx] > max_prob) {
// 						max_prob = out_Mat[idx];
// 						cat = 0;
// 						box.conf = max_prob * 255;
// 						box.cat = cat;
// 					}
// 				}
// 				if (detect_vehicle) {
// 					int idx = step + base_offset[5];
// 					if (out_Mat[idx] > max_prob) {
// 						max_prob = out_Mat[idx];
// 						cat = 1;
// 						box.conf = max_prob * 255;
// 						box.cat = cat;
// 					}
// 				}
// 
// 				if (max_prob > threshold) {
// #if FALSE_ALARM_DEBUG
// 					float sx = (x + 0.5f - out_Mat[base_offset[0] + step]) * stride;
// 					float sy = (y + 0.5f - out_Mat[base_offset[1] + step]) * stride;
// 					float ex = (x + 0.5f + out_Mat[base_offset[2] + step]) * stride;
// 					float ey = (y + 0.5f + out_Mat[base_offset[3] + step]) * stride;
// 
// 					sx = (sx - wpad) / scale;
// 					sy = (sy - hpad) / scale;
// 					ex = (ex - wpad) / scale;
// 					ey = (ey - wpad) / scale;
// 
// 					box.rect.sx = std::min(std::max(0, static_cast<int>(sx)), crop_width - 1);
// 					box.rect.sy = std::min(std::max(0, static_cast<int>(sy)), crop_height - 1);
// 					box.rect.ex = std::min(std::max(0, static_cast<int>(ex)), crop_width - 1);
// 					box.rect.ey = std::min(std::max(0, static_cast<int>(ey)), crop_height - 1);
// 
// 					feature_list.push_back(box);
// 					if (max_prob > g_max_prob) {
// 						g_max_prob = max_prob;
// 						roi_debug.conf = g_max_prob * 255;
// 						roi_debug.cat = box.cat;
// 					}
// #else
// 					obj_in = true;
// 					roi_debug.conf = max_prob * 255;
// 					roi_debug.cat = box.cat;
// 					break;
// #endif	// FALSE_ALARM_DEBUG
// 				}
// 				step++;
// 			}
// 		}
// 	}
// 
// #if FALSE_ALARM_DEBUG
// 	NmsBoxes(feature_list, (float)od_iou_th/100.0, MPI_IVA_MAX_OBJ_NUM, roi_output);
// 
// 	LPRINTF("roi_output size: %u\n", roi_output.size());
// 	if (!roi_output.empty()) {
// 		for (uint i = 0; i < roi_output.size(); i++) {
// 			LPRINTF("number %u obj (cat: %d) (conf: 0.%u) in [%d, %d, %d, %d]\n", i, roi_output[i].cat, roi_output[i].conf, roi_output[i].rect.sx, roi_output[i].rect.sy, roi_output[i].rect.ex, roi_output[i].rect.ey);
// 		}
// 	}
// #endif	// FALSE_ALARM_DEBUG
// 
// 	/* determine if it's a false alarm or not */
// 
// #if FALSE_ALARM_DEBUG
// 	if (feature_list.empty()) {
// 		result = 0;
// 	} else {
// 		result = 1;
// 	}
// 	LPRINTF("result of false_alarm_detect: %d\n", result);
// #else
// 	if (!obj_in) {
// 		result = 0;
// 	} else {
// 		result = 1;
// 	}
// #endif	// FALSE_ALARM_DEBUG
// 
// 	/* Release memory */
// 	out_Mat.release();
// 	ex.clear();
// 	delete in_Mat; in_Mat = nullptr;
// 	delete g_net; g_net = nullptr;
// 	delete g_workspace_pool_allocator; g_workspace_pool_allocator = nullptr;
// 	delete g_blob_pool_allocator; g_blob_pool_allocator = nullptr;
// 
// 	return result;
}

extern "C" uint32_t false_alarm_detect(void *data)
{
	struct detect *det = (struct detect *)data;

	if (detect((uint32_t)det->type, (uint32_t)det->threshold, (void *)det->data) == 0) {
		// object not detected, false alarm
		run_csr_control(&det->alarm_on);
	} else {
		run_csr_control(&det->alarm_off);
	}

	return 0;
}


#endif	// EARLY_DETECT
