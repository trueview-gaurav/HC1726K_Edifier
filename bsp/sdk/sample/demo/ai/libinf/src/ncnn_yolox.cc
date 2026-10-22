#ifdef USE_NCNN
#include "ncnn_yolox.h"

#include <cstdint>
#include <cstring>
#include <memory>
#include <sys/time.h>

#include "inf_types.h"
#include "inf_image.h"
#include "inf_model.h"

#include "inf_log.h"
#include "inf_utils.h"
#include "inf_utils_lite.h"

#include "vftr_dump.h"
#include "eaif_dump_define.h"

#include "inf_adapter.h"
#include <fstream>


int NcnnYolox::LoadModels(const char* model_dir, const InfStrList* model_paths)
{
	SetupVerboseModeFromEnvironment();

	// Init model options (can skipped)
	m_model.opt.use_vulkan_compute = false;
	m_model.opt.use_int8_inference = false;
	m_model.opt.use_a53_a55_optimized_kernel = true;
	m_model.opt.use_fp16_packed = false;
	m_model.opt.use_fp16_storage = false;
	m_model.opt.use_fp16_arithmetic = false;
	m_model.opt.num_threads = 1;

	if (model_paths->size != 1) {
		inf_log_warn("Number of model paths do not equal to 1!");
		return -1;
	}

	if (m_verbose)
		TIC(start);

	// Load model files
	const std::string orig_dir = model_dir;
	const std::string orig_path = model_paths->data[0];
	std::string model_path_ = orig_dir + "/" + orig_path + ".param";
	const char* param_path_char = model_path_.c_str();
	if (m_model.load_param(param_path_char)){
		inf_log_err("Cannot find %s for %s!", param_path_char, __func__);
		return -1;
	}

	model_path_ = orig_dir + "/" + orig_path + ".bin";
	const char* bin_path_char = model_path_.c_str();
	if (m_model.load_model(bin_path_char)){
		inf_log_err("Cannot find %s for %s!", bin_path_char, __func__);
		return -1;
	}

	// Init input/output info from config.ini
	m_input_dim[1] = m_config->w; // m_config->w
	m_input_dim[0] = m_config->h; // m_config->h
	m_input_dim[2] = m_config->c; // m_config->c

	// m_config->dtype = Inf8S; // Always Inf8S for ncnn
	m_config->dtype = Inf32F;

	// TODO:: Output size should be hard-coded in ncnn
	// m_output_dim[0] = 1;
	// m_output_dim[1] = m_config->labels.size;
	// m_output_dim[2] = m_config->labels.size;

	// Create and allocate input buffer
	// in_Mat.create(m_input_dim[1], m_input_dim[0], m_input_dim[2], (size_t)1u);
	in_Mat.create(m_input_dim[1], m_input_dim[0], m_input_dim[2]);


	if (m_verbose)
		TOC("Load SCRFD", start);

	inf_log_notice("YOLOX model input dimension (WHC) is %dx%dx%d (%s)",
	               m_input_dim[0], m_input_dim[1], m_input_dim[2], GetDTypeString(m_config->dtype));

	return 0;
}

void NcnnYolox::SetupConfig(InfModelInfo* conf)
{
	m_use_kps = conf->use_kps;
	m_feature_output_pairs = conf->feature_output_pairs;
	m_num_anchors_per_feature = conf->num_anchors_per_feature;
	memcpy(m_feature_stride, conf->feature_stride,
	       sizeof(int) *m_feature_output_pairs * m_num_anchors_per_feature);
	m_verbose = conf->verbose;
	m_debug = conf->debug;
	m_num_thread = conf->num_threads;
}

static void dump_float_image(const float* input_addr, int width, int height, int channels, const std::string& filename) {
    size_t total_size = static_cast<size_t>(width) * height * channels;
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filename.c_str());
        return;
    } else {
		fprintf(stderr, "Dump image to file %s\n", filename.c_str());
	}
    out.write(reinterpret_cast<const char*>(input_addr), total_size * sizeof(float));
    out.close();
}

int NcnnYolox::RunNetwork(const InfImage& img, const Shape& size, int chn, InfDataType mtype,
						  const MPI_RECT_POINT_S* roi, const Pads* pads, int verbose)
{
	/* Get input/output tensor index */
	int ret = 0;
	InfDataType dtype = static_cast<InfDataType>(GetImageType(mtype, chn));
	uint8_t* input_addr;

	if (verbose) {
		fprintf(stderr, "======= input dim = %d %d %d =========\n",
				in_Mat.c, in_Mat.h, in_Mat.w);
		if (roi)
			fprintf(stderr, "roi: [%d %d %d %d], size: [%d %d]\n", roi->sx, roi->sy, roi->ex, roi->ey, size.w, size.h);
		if (pads)
			fprintf(stderr, "pad: [%d %d %d %d]\n", pads->top, pads->bot, pads->left, pads->right);
	}
	// fprintf(stderr, "norm: [%f %f %f], std: [%f %f %f]\n",
	// 		m_config->norm_zeros[0], m_config->norm_zeros[1], m_config->norm_zeros[2],
	// 		m_config->norm_scales[0], m_config->norm_scales[1], m_config->norm_scales[2]);
	// if (mtype == Inf8U || mtype == Inf8S) {
	input_addr = static_cast<uint8_t*>(InputTensorBuffer(0));
	// } else {
	// 	input_addr_32 = static_cast<float*>(InputTensorBuffer(0));
	// 	// inf_log_warn("%s does not support floating point inference", __func__);
	// 	// return 0;
	// }

	InfImage dst{size.w, size.h, chn, input_addr, 0, dtype};

	if (verbose)
		TIC(start);

	if (!roi) {
		Inf_ImresizeNorm(&img, size.w, size.h, &dst, &m_config->norm_zeros[0],
                         &m_config->norm_scales[0], m_config->input_int8_scale);
	} else if (!pads) {
		Inf_ImcropResizeNorm(&img, roi->sx, roi->sy, roi->ex, roi->ey, &dst, size.w, size.h, &m_config->norm_zeros[0],
                         &m_config->norm_scales[0], m_config->input_int8_scale);
	} else {
		Inf_ImcropPadResizeNorm(&img, roi->sx, roi->sy, roi->ex, roi->ey,
		                    pads->top, pads->bot, pads->left, pads->right, &dst, size.w, size.h, &m_config->norm_zeros[0],
                            &m_config->norm_scales[0], m_config->input_int8_scale);
	}

	//TODO:: Check invalid data range of processed image

	if (m_debug)
	{
		static int cnt = 0;
		TOC("Image preprocess", start);
		std::string filename = "/mnt/nfs/ethnfs/dump_float/dump_chw_float32_" + std::to_string(cnt++) + ".bin";
		dump_float_image(static_cast<float*>(InputTensorBuffer(0)), size.w, size.h, chn, filename);
		TIC(start);
	}

	ncnn::Extractor ex = m_model.create_extractor();
	// Insert image to ncnn model
	if(ex.input(0, in_Mat) == -1){
		inf_log_err("ncnn input error");
		return -1;
	}
	// Extract output from ncnn model
	if(ex.extract(m_model.blobs().size()-1, out_Mat) == -1) {
		inf_log_err("ncnn extract error");
		return 0;
	}

	if (verbose)
		fprintf(stderr, "======= output dim = %d %d %d =============\n", out_Mat.c, out_Mat.h, out_Mat.w);

	if (verbose)
		TOC("Invoke", start);

	// TODO: Add out_Mat.release() at somewhere

	return ret;
}

InfImage NcnnYolox::GetInputImage()
{
	InfImage img{};

	img.h = m_input_dim[0];
	img.w = m_input_dim[1];
	img.c = m_input_dim[2];

	int dtype = Inf32F;

	img.buf_owner = 0;
	img.data = static_cast<uint8_t*>(InputTensorBuffer(0));

	img.dtype = static_cast<InfDataType>(dtype | ((img.c - 1) << 3));

	return img;
}


int NcnnYolox::TRunNet(const InfImage& img, const MPI_RECT_POINT_S* roi_, std::vector<FaceBox>& face_list)
{
	const int height = m_input_dim[0];
	const int width = m_input_dim[1];
	const int chn = m_input_dim[2];
	const Shape size{width, height};
	Scaler scale_factor{};
	Pads pads{};
	int need_padding = 0;
	std::vector<FaceBox> feature_list;

	MPI_RECT_POINT_S *roi = nullptr;

	if (roi_) {
		MPI_RECT_POINT_S roi_local {roi_->sx, roi_->sy,roi_->ex, roi_->ey};
		roi = &roi_local;
		// Prevent Padding issue
		roi->sx = std::max(std::min(roi->sx, (short)(img.w-1)), (short)0);
		roi->sy = std::max(std::min(roi->sy, (short)(img.h-1)), (short)0);
		roi->ex = std::max(std::min(roi->ex, (short)(img.w-1)), (short)0);
		roi->ey = std::max(std::min(roi->ey, (short)(img.h-1)), (short)0);

		if (roi->sx < 0) pads.left = -roi->sx;
		if (roi->sy < 0) pads.top = -roi->sy;
		if (roi->ex >= img.w) pads.right = roi->ex + 1 - img.w;
		if (roi->ey >= img.h) pads.bot = roi->ey + 1 - img.h;

		if (pads.left || pads.top || pads.right || pads.bot) {
			need_padding = 1;
		}
		scale_factor.w = static_cast<float>(roi->ex - roi->sx + 1) / width;
		scale_factor.h = static_cast<float>(roi->ey - roi->sy + 1) / height;
	} else {
		scale_factor.w = static_cast<float>(img.w) / width;
		scale_factor.h = static_cast<float>(img.h) / height;
	}

	int ret;
	if (need_padding) {
		ret = RunNetwork(img, size, chn, m_config->dtype, roi, &pads, m_verbose);
	} else {
		ret = RunNetwork(img, size, chn, m_config->dtype, roi, nullptr, m_verbose);
	}

	if (ret) {
		return -1;
	}

	if (m_verbose) TIC(start);

	for (int i = 0; i < m_feature_output_pairs; i++) {
		const int conf_index = m_output_prob_idx[i];
		// const int reg_index = m_output_reg_idx[i];
		const float* output_ptr = static_cast<float*>(OutputTensorBuffer(conf_index));

		std::vector<FaceBox> face_list_local;

		YoloXPostProcessConfig conf = {};
		conf.num_anchors = out_Mat.h;
		conf.num_channels = out_Mat.w;
		conf.conf_thresh = m_config->conf_thresh.data[0];
		conf.iou_thresh = m_config->iou_thresh;
		// conf.input.h = m_input_dim[0];
		// conf.input.w = m_input_dim[1];

		YoloXPostProcess(output_ptr, conf, face_list_local);

		if (!face_list_local.empty())
			feature_list.insert(feature_list.end(), face_list_local.begin(), face_list_local.end());
	}

	NmsBoxes(feature_list, m_config->iou_thresh, NMS_UNION, face_list);

	if (roi) {
		for (auto& box : face_list) {
			box.x0 = std::min(std::max(box.x0 * scale_factor.w + roi->sx,0.0f), (float)img.w);
			box.y0 = std::min(std::max(box.y0 * scale_factor.h + roi->sy,0.0f), (float)img.h);
			box.x1 = std::min(std::max(box.x1 * scale_factor.w + roi->sx,0.0f), (float)img.w);
			box.y1 = std::min(std::max(box.y1 * scale_factor.h + roi->sy,0.0f), (float)img.h);
		}
	} else {
		for (auto& box : face_list) {
			box.x0 = std::min(std::max(box.x0 * scale_factor.w,0.0f), (float)img.w);
			box.y0 = std::min(std::max(box.y0 * scale_factor.h,0.0f), (float)img.h);
			box.x1 = std::min(std::max(box.x1 * scale_factor.w,0.0f), (float)img.w);
			box.y1 = std::min(std::max(box.y1 * scale_factor.h,0.0f), (float)img.h);
		}
	}

	// if (m_debug) {
	// 	// 1. write image
	// 	WriteDebugInfo(roi, scale_factor, face_list);
	// }

	if (m_verbose) {
		char msg[512] = {};
		sprintf(msg, "PostProcess (#%d detections) \n", static_cast<int>(face_list.size()));
		if (!face_list.empty()) {
			// sprintf(&msg[len], "obj-0: [%.2f, %.2f, %.2f, %.2f]",
			// face_list[0].x0, face_list[0].y0, face_list[0].x1, face_list[0].y1);
			for (auto& box : face_list) {
				// sprintf(&msg[len], "[%.2f, %.2f, %.2f, %.2f] [%.2f]\n",
				// 					box.x0, box.y0, box.x1, box.y1, box.score);
				fprintf(stderr, "[%.2f, %.2f, %.2f, %.2f] [%.2f]\n",
									box.x0, box.y0, box.x1, box.y1, box.score);
			}
		}
		TOC(msg, start);
	}
	return 0;
}

int NcnnYolox::FaceDetect(const InfImage* img, std::vector<FaceBox>& face_list)
{
	return TRunNet(*img, nullptr, face_list);
}

int NcnnYolox::FaceDetect(const InfImage* img, const MPI_RECT_POINT_S& roi, std::vector<FaceBox>& face_list)
{
	return TRunNet(*img, &roi, face_list);
}

int NcnnYolox::FaceDetect(const InfImage* img, const MPI_IVA_OBJ_LIST_S* obj_list, std::vector<FaceBox>& face_list)
{
#define PAD_PIX_SIZE (32)

	retIfNull(img && obj_list);

	MPI_RECT_POINT_S group_roi = {};
	MPI_RECT_POINT_S input_roi = {};
	const Shape img_shape{img->w, img->h};
	const Shape input{m_input_dim[1], m_input_dim[0]};

	if (!obj_list->obj_num)
		return 0;

#ifndef _HOST_LINUX
	VFTR_dumpStart();
	VFTR_dumpWithJiffies(obj_list, sizeof(*obj_list), 
						 COMPOSE_EAIF_FLAG_VER_1(InfObjList, InfObjList), obj_list->timestamp);
	VFTR_dumpEnd();
#endif

	Grouping(obj_list, group_roi);

	PadAndRescale(PAD_PIX_SIZE, img_shape, input, group_roi, input_roi);

	FaceDetect(img, input_roi, face_list);

	return 0;

#undef PAD_PIX_SIZE
}

int NcnnYolox::Detect(const InfImage* img, InfDetList* result)
{
	std::vector<FaceBox> face_list;
	int ret = FaceDetect(img, face_list);
	TransformResult(face_list, result, 1.0f, m_config->labels.size);

#ifndef _HOST_LINUX
	// get current timestamp
	struct timeval tv;
	gettimeofday(&tv, NULL);
	TIMESPEC_S timespec;
	timespec.tv_sec = tv.tv_sec;
	timespec.tv_nsec = tv.tv_usec * 1000;
	struct tm localtime;
	localtime_r(&timespec.tv_sec, &localtime);
	timespec.tv_sec = mktime(&localtime);

	// dump InfImage
	InfImage wimg = GetInputImage();
	VFTR_dumpStart();
	VFTR_dump(&wimg, sizeof(wimg),
			COMPOSE_EAIF_FLAG_VER_1(InfImage, InfImage), timespec);
	VFTR_dump(wimg.data, wimg.w * wimg.h * wimg.c,
			COMPOSE_EAIF_FLAG_VER_1(InfU8Array, InfImage), timespec);

	// dump detection result
	VFTR_dump(result, sizeof(*result),
			COMPOSE_EAIF_FLAG_VER_1(InfDetList, InfDetList), timespec);
	VFTR_dumpEnd();

	// for (int i = 0; i < result->size; ++i ) {
	// 	InfDetResult *single_result = &result->data[i];
	//
	// 	// dump face img
	// 	InfImage face_img;
	// 	auto& sx = single_result->rect.sx;
	// 	auto& sy = single_result->rect.sy;
	// 	auto& ex = single_result->rect.ex;
	// 	auto& ey = single_result->rect.ey;
	// 	face_img.w = ex - sx + 1;
	// 	face_img.h = ey - sy + 1;
	// 	face_img.c = wimg.c;
	// 	face_img.buf_owner = 0;
	// 	face_img.dtype = static_cast<InfDataType>(GetImageType(m_config->dtype, wimg.c));
	// 	face_img.data = static_cast<uint8_t*>(InputTensorBuffer(0));
	//
	// 	// hint: roi and margin and padding will effect result img
	// 	Inf_ImcropResizeNorm(img, sx, sy, ex, ey, &face_img, face_img.w, face_img.h, &m_config->norm_zeros[0],
    //                      &m_config->norm_scales[0], m_config->input_int8_scale);
	//
	// 	VFTR_dumpStart();
	// 	VFTR_dump(single_result, sizeof(*single_result),
	// 			COMPOSE_EAIF_FLAG_VER_1(InfDetResult, InfDetList), timespec);
	// 	VFTR_dump(&face_img, sizeof(face_img),
	// 		COMPOSE_EAIF_FLAG_VER_1(InfFaceImage, InfImage), timespec);
	// 	VFTR_dump(face_img.data, face_img.w * face_img.h * face_img.c,
	// 		COMPOSE_EAIF_FLAG_VER_1(InfFaceU8Array, InfFaceImage), timespec);
	// 	VFTR_dumpEnd();
	// }
#endif // _HOST_LINUX

	return ret;
}

int NcnnYolox::Detect(const InfImage* img, const MPI_IVA_OBJ_LIST_S* obj_list, InfDetList* result)
{
	std::vector<FaceBox> face_list;
	int ret = FaceDetect(img, obj_list, face_list);
	TransformResult(face_list, result, 1.0f, m_config->labels.size);

#ifndef _HOST_LINUX
	// get current timestamp
	struct timeval tv;
	gettimeofday(&tv, NULL);
	TIMESPEC_S timespec;
	timespec.tv_sec = tv.tv_sec;
	timespec.tv_nsec = tv.tv_usec * 1000;
	struct tm localtime;
	localtime_r(&timespec.tv_sec, &localtime);
	timespec.tv_sec = mktime(&localtime);

	// dump InfImage
	InfImage wimg = GetInputImage();
	VFTR_dumpStart();
	VFTR_dump(&wimg, sizeof(wimg),
			COMPOSE_EAIF_FLAG_VER_1(InfImage, InfImage), timespec);
	VFTR_dump(wimg.data, wimg.w * wimg.h * wimg.c,
			COMPOSE_EAIF_FLAG_VER_1(InfU8Array, InfImage), timespec);

	// dump detection result
	VFTR_dump(result, sizeof(*result),
			COMPOSE_EAIF_FLAG_VER_1(InfDetList, InfDetList), timespec);
	VFTR_dumpEnd();

	// for (int i = 0; i < result->size; ++i ) {
	// 	InfDetResult *single_result = &result->data[i];
	//
	// 	// dump face img
	// 	InfImage face_img;
	// 	auto& sx = single_result->rect.sx;
	// 	auto& sy = single_result->rect.sy;
	// 	auto& ex = single_result->rect.ex;
	// 	auto& ey = single_result->rect.ey;
	// 	face_img.w = ex - sx + 1;
	// 	face_img.h = ey - sy + 1;
	// 	face_img.c = wimg.c;
	// 	face_img.buf_owner = 0;
	// 	face_img.dtype = static_cast<InfDataType>(GetImageType(m_config->dtype, wimg.c));
	// 	face_img.data = static_cast<uint8_t*>(InputTensorBuffer(0));
	//
	// 	// hint: roi and margin and padding will effect result img
	// 	Inf_ImcropResizeNorm(img, sx, sy, ex, ey, &face_img, face_img.w, face_img.h, &m_config->norm_zeros[0],
    //                      &m_config->norm_scales[0], m_config->input_int8_scale);
	//
	// 	VFTR_dumpStart();
	// 	VFTR_dump(single_result, sizeof(*single_result),
	// 			COMPOSE_EAIF_FLAG_VER_1(InfDetResult, InfDetList), timespec);
	// 	VFTR_dump(&face_img, sizeof(face_img),
	// 		COMPOSE_EAIF_FLAG_VER_1(InfFaceImage, InfImage), timespec);
	// 	VFTR_dump(face_img.data, face_img.w * face_img.h * face_img.c,
	// 		COMPOSE_EAIF_FLAG_VER_1(InfFaceU8Array, InfFaceImage), timespec);
	// 	VFTR_dumpEnd();
	// }
#endif // _HOST_LINUX

	return ret;
}

void NcnnYolox::WriteDebugInfo(const MPI_RECT_POINT_S *roi, const Scaler& scale_factor,
							   const std::vector<FaceBox>& face_list)
{
	inf_log_warn("Please use vftr_dump");
}

#endif // USE_NCNN