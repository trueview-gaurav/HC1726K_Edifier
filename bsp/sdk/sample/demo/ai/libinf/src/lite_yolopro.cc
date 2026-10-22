#ifndef USE_NCNN
#include "lite_yolopro.h"

#include <cstdint>
#include <cstring>
#include <memory>
#include <sys/time.h>

#ifndef USE_MICROLITE
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "tensorflow/lite/interpreter.h"
#pragma GCC diagnostic pop
#endif

#include "inf_types.h"
#include "inf_image.h"
#include "inf_model.h"

#include "inf_log.h"
#include "inf_utils.h"
#include "inf_utils_lite.h"

#include "vftr_dump.h"
#include "eaif_dump_define.h"

#include "inf_adapter.h"


int LiteYoloproBase::LoadModels(const char* model_dir, const InfStrList* model_paths)
{
	SetupVerboseModeFromEnvironment();

	if (model_paths->size != 1) {
		inf_log_warn("Number of model paths do not equal to 1!");
		return -1;
	}

	char net_fname[256] = {};
	snprintf(net_fname, 255, "%s/%s", model_dir, model_paths->data[0]);

	if (m_verbose)
		TIC(start);

	if (!PrepareInterpreter(net_fname)) {
		inf_log_err("Failed to prepare model interpreter!");
		return -1;
	}

	size_t used_bytes = GetArenaUsedBytes();
	if (used_bytes > 0) {
		inf_log_notice("%s had used %zd bytes of arena.", net_fname, used_bytes);
	}

	if (!CollectModelInfo()) {
		inf_log_err("Failed to collect model information!");
		return -1;
	}

	if (m_verbose)
		TOC("Load YoloPro", start);

	inf_log_notice("YoloPro model input dimension is %dx%dx%d (%s), output [%dx%dx%d]",
	               m_input_dim[0], m_input_dim[1], m_input_dim[2], GetDTypeString(m_type),
	               m_output_dim[0], m_output_dim[1], m_output_dim[2]);

	return 0;
}

void LiteYoloproBase::SetupConfig(InfModelInfo* conf)
{
	m_verbose = conf->verbose;
	m_debug = conf->debug;
	m_num_thread = conf->num_threads;
	m_preprocess_mode = conf->preprocess_mode;
}

int LiteYoloproBase::RunNetwork(const InfImage& img, const Shape& size, int chn, InfDataType mtype,
                                const MPI_RECT_POINT_S* roi, const Pads* pads, int verbose)
{
	int ret = 0;
	InfDataType dtype = static_cast<InfDataType>(GetImageType(mtype, chn));
	uint8_t* input_addr;

	if (mtype == Inf8U || mtype == Inf8S) {
		input_addr = static_cast<uint8_t*>(InputTensorBuffer(0));
	} else {
		/* TODO: float32 support requires (1) normalize uint8 → float32 into input buffer,
		 * (2) set m_qinfo.scale=1.0/zero=0 in CollectModelInfo for float32 output tensors */
		inf_log_warn("%s does not support floating point inference", __func__);
		return 0;
	}

	InfImage dst{size.w, size.h, chn, input_addr, 0, dtype};

	if (verbose)
		TIC(start);

	if (m_preprocess_mode == 2) {
		/* roi is always set by TRunNet for mode 2 */
		Inf_ImcropResizeShortAxis(&img, roi->sx, roi->sy, roi->ex, roi->ey, &dst, size.w, size.h);
	} else if (m_preprocess_mode == 1) {
		/* roi is always set by TRunNet for mode 1 */
		Inf_ImcropResizeAspectRatio(&img, roi->sx, roi->sy, roi->ex, roi->ey, &dst, size.w, size.h);
	} else {
		if (!roi)
			Inf_Imresize(&img, size.w, size.h, &dst);
		else if (!pads)
			Inf_ImcropResize(&img, roi->sx, roi->sy, roi->ex, roi->ey, &dst, size.w, size.h);
		else
			Inf_ImcropPadResize(&img, roi->sx, roi->sy, roi->ex, roi->ey,
			                    pads->top, pads->bot, pads->left, pads->right, &dst, size.w, size.h);
	}

	if (verbose)
		TOC("Image preprocess", start);

	if (verbose)
		TIC(start);

	if (Invoke() != kTfLiteOk) {
		ret = -1;
	}

	if (verbose)
		TOC("Invoke", start);

	return ret;
}

void LiteYolopro::SetModelThreads(int nthreads)
{
	m_config->num_threads = nthreads;
	m_num_thread = nthreads;
	inf_tf_adapter::setNumThreads(*m_model, nthreads);
}

bool LiteYolopro::PrepareInterpreter(const std::string& model_path)
{
	if (inf_tf_adapter::LiteYolopro_LoadModel(*this, model_path, m_model, m_model_fb)) {
		inf_log_err("Fail to load %s for %s!", model_path.c_str(), __func__);
		return false;
	}

	if (m_model->AllocateTensors() != kTfLiteOk) {
		inf_log_err("Cannot allocate tensor!");
		return false;
	}

	inf_tf_adapter::setNumThreads(*m_model, m_num_thread);
	return true;
}

bool LiteYolopro::CollectModelInfo()
{
	m_input_dim[0] = m_model->input_tensor(0)->dims->data[1]; // h
	m_input_dim[1] = m_model->input_tensor(0)->dims->data[2]; // w
	m_input_dim[2] = m_model->input_tensor(0)->dims->data[3]; // c

	m_type = utils::lite::GetDataType(m_model->input_tensor(0)->type);

	const TfLiteIntArray* out_dims = m_model->output_tensor(0)->dims;
	if (out_dims->size != 3) {
		inf_log_err("YoloPro output tensor must be 3D [batch, anchors, channels], got %d dims",
		            out_dims->size);
		return false;
	}
	m_output_dim[0] = out_dims->data[0]; // batch
	m_output_dim[1] = out_dims->data[1]; // num_anchors
	m_output_dim[2] = out_dims->data[2]; // num_channels (expected 5)

	const TfLiteQuantizationParams* p = &m_model->output_tensor(0)->params;
	m_qinfo.zero = p->zero_point;
	m_qinfo.scale = p->scale;

	return true;
}

InfImage LiteYolopro::GetInputImage()
{
	return utils::lite::GetInputImage(m_model);
}

template <typename Tbuffer>
int LiteYoloproBase::TRunNet(const InfImage& img, const MPI_RECT_POINT_S* roi,
                              std::vector<FaceBox>& face_list)
{
	const int height = m_input_dim[0];
	const int width = m_input_dim[1];
	const int chn = m_input_dim[2];
	const Shape size{width, height};
	std::vector<FaceBox> feature_list;

	/* Base source rect: use roi if given, otherwise full image */
	int base_sx = roi ? (int)roi->sx : 0;
	int base_sy = roi ? (int)roi->sy : 0;
	int base_ex = roi ? (int)roi->ex : img.w - 1;
	int base_ey = roi ? (int)roi->ey : img.h - 1;

	Scaler scale_factor{};
	int map_sx = base_sx, map_sy = base_sy;
	int ret;

	if (m_preprocess_mode == 1 || m_preprocess_mode == 2) {
		base_sx = std::min(std::max(base_sx, 0), img.w - 1);
		base_sy = std::min(std::max(base_sy, 0), img.h - 1);
		base_ex = std::min(std::max(base_ex, 0), img.w - 1);
		base_ey = std::min(std::max(base_ey, 0), img.h - 1);

		if (base_sx >= base_ex || base_sy >= base_ey)
			return 0;

		int roi_w = base_ex - base_sx + 1;
		int roi_h = base_ey - base_sy + 1;
		map_sx = base_sx;
		map_sy = base_sy;

		if (m_preprocess_mode == 2) {
			/* Short axis crop: scale by binding axis, center-crop the other */
			if (width * roi_h > height * roi_w) {
				int crop_h = height * roi_w / width;
				map_sy += (roi_h - crop_h) / 2;
				scale_factor.w = static_cast<float>(roi_w - 1) / (width - 1);
				scale_factor.h = static_cast<float>(crop_h - 1) / (height - 1);
			} else {
				int crop_w = width * roi_h / height;
				map_sx += (roi_w - crop_w) / 2;
				scale_factor.w = static_cast<float>(crop_w - 1) / (width - 1);
				scale_factor.h = static_cast<float>(roi_h - 1) / (height - 1);
			}
		} else {
			/* Aspect ratio pad: mirror Inf_ImcropResizeAspectRatio's (size-1)/(dst-1) scale */
			int ptop  = (roi_h < roi_w) ? (roi_w - roi_h + 1) / 2 : 0;
			int pleft = (roi_w < roi_h) ? (roi_h - roi_w + 1) / 2 : 0;
			int pad_w = roi_w + 2 * pleft;
			int pad_h = roi_h + 2 * ptop;
			map_sx -= pleft;
			map_sy -= ptop;
			scale_factor.w = static_cast<float>(pad_w - 1) / (width - 1);
			scale_factor.h = static_cast<float>(pad_h - 1) / (height - 1);
		}

		MPI_RECT_POINT_S eff_roi{(short)base_sx, (short)base_sy, (short)base_ex, (short)base_ey};
		ret = RunNetwork(img, size, chn, m_type, &eff_roi, nullptr, m_verbose);
	} else {
		/* Mode 0: resize with optional ROI, supports out-of-bounds via black padding */
		Pads pads{};
		if (roi) {
			if (roi->sx < 0) pads.left = -roi->sx;
			if (roi->sy < 0) pads.top = -roi->sy;
			if (roi->ex >= img.w) pads.right = roi->ex + 1 - img.w;
			if (roi->ey >= img.h) pads.bot = roi->ey + 1 - img.h;
			scale_factor.w = static_cast<float>(roi->ex - roi->sx) / (width - 1);
			scale_factor.h = static_cast<float>(roi->ey - roi->sy) / (height - 1);
		} else {
			scale_factor.w = static_cast<float>(img.w - 1) / (width - 1);
			scale_factor.h = static_cast<float>(img.h - 1) / (height - 1);
		}
		const Pads* ppads = (pads.left || pads.top || pads.right || pads.bot) ? &pads : nullptr;
		ret = RunNetwork(img, size, chn, m_type, roi, ppads, m_verbose);
	}

	if (ret)
		return -1;

	if (m_verbose) TIC(start);

	const Tbuffer* output_ptr = static_cast<Tbuffer*>(OutputTensorBuffer(0));

	YoloProPostProcessConfig conf = {};
	conf.num_anchors = m_output_dim[1];
	conf.num_channels = m_output_dim[2];
	conf.conf_thresh = m_config->conf_thresh.data[0];
	conf.iou_thresh = m_config->iou_thresh;
	conf.input.w = width;
	conf.input.h = height;

	YoloProPostProcess(output_ptr, m_qinfo, conf, feature_list);

	NmsBoxes(feature_list, m_config->iou_thresh, NMS_UNION, face_list);

	for (auto& box : face_list) {
		box.x0 = box.x0 * scale_factor.w + map_sx;
		box.y0 = box.y0 * scale_factor.h + map_sy;
		box.x1 = box.x1 * scale_factor.w + map_sx;
		box.y1 = box.y1 * scale_factor.h + map_sy;
	}

	if (m_debug) {
		MPI_RECT_POINT_S debug_roi{(short)map_sx, (short)map_sy, 0, 0};
		WriteDebugInfo(&debug_roi, scale_factor, face_list);
	}

	if (m_verbose) {
		char msg[64] = {};
		sprintf(msg, "PostProcess (#%d detections)", static_cast<int>(face_list.size()));
		TOC(msg, start);
		for (int i = 0; i < (int)face_list.size(); ++i) {
			const auto& box = face_list[i];
			inf_log_info("  obj-%2d: [%7.2f, %7.2f, %7.2f, %7.2f] conf=%.3f",
			             i, box.x0, box.y0, box.x1, box.y1, box.score);
		}
	}

	return 0;
}

int LiteYoloproBase::FaceDetect(const InfImage* img, std::vector<FaceBox>& face_list)
{
	if (m_type == Inf8U)
		return TRunNet<uint8_t>(*img, nullptr, face_list);
	else if (m_type == Inf8S)
		return TRunNet<int8_t>(*img, nullptr, face_list);
	else if (m_type == Inf32F)
		return TRunNet<float>(*img, nullptr, face_list);
	inf_log_err("Unsupported dtype %d for YoloPro inference!", m_type);
	return -1;
}

int LiteYoloproBase::FaceDetect(const InfImage* img, const MPI_RECT_POINT_S& roi,
                                 std::vector<FaceBox>& face_list)
{
	if (m_type == Inf8U)
		return TRunNet<uint8_t>(*img, &roi, face_list);
	else if (m_type == Inf8S)
		return TRunNet<int8_t>(*img, &roi, face_list);
	else if (m_type == Inf32F)
		return TRunNet<float>(*img, &roi, face_list);
	inf_log_err("Unsupported dtype %d for YoloPro inference!", m_type);
	return -1;
}

int LiteYoloproBase::FaceDetect(const InfImage* img, const MPI_IVA_OBJ_LIST_S* obj_list,
                                 std::vector<FaceBox>& face_list)
{
#define PAD_PIX_SIZE (32)

	retIfNull(img && obj_list);

	MPI_RECT_POINT_S group_roi = {};
	MPI_RECT_POINT_S input_roi = {};

	if (!obj_list->obj_num)
		return 0;

#ifndef _HOST_LINUX
	VFTR_dumpStart();
	VFTR_dumpWithJiffies(obj_list, sizeof(*obj_list),
	  COMPOSE_EAIF_FLAG_VER_1(InfObjList, InfObjList), obj_list->timestamp);
	VFTR_dumpEnd();
#endif

	Grouping(obj_list, group_roi);

	input_roi.sx = (short)std::max(0, (int)group_roi.sx - PAD_PIX_SIZE);
	input_roi.sy = (short)std::max(0, (int)group_roi.sy - PAD_PIX_SIZE);
	input_roi.ex = (short)std::min(img->w - 1, (int)group_roi.ex + PAD_PIX_SIZE);
	input_roi.ey = (short)std::min(img->h - 1, (int)group_roi.ey + PAD_PIX_SIZE);

	FaceDetect(img, input_roi, face_list);

	return 0;

#undef PAD_PIX_SIZE
}

int LiteYoloproBase::Detect(const InfImage* img, InfDetList* result)
{
	std::vector<FaceBox> face_list;
	int ret = FaceDetect(img, face_list);
	TransformResult(face_list, result, 1.0f, m_config->labels.size);

#ifndef _HOST_LINUX
	struct timeval tv;
	gettimeofday(&tv, NULL);
	TIMESPEC_S timespec;
	timespec.tv_sec = tv.tv_sec;
	timespec.tv_nsec = tv.tv_usec * 1000;
	struct tm localtime;
	localtime_r(&timespec.tv_sec, &localtime);
	timespec.tv_sec = mktime(&localtime);

	InfImage wimg = GetInputImage();
	VFTR_dumpStart();
	VFTR_dump(&wimg, sizeof(wimg),
	          COMPOSE_EAIF_FLAG_VER_1(InfImage, InfImage), timespec);
	VFTR_dump(wimg.data, wimg.w * wimg.h * wimg.c,
	          COMPOSE_EAIF_FLAG_VER_1(InfU8Array, InfImage), timespec);
	VFTR_dump(result, sizeof(*result),
	          COMPOSE_EAIF_FLAG_VER_1(InfDetList, InfDetList), timespec);
	VFTR_dumpEnd();
#endif

	return ret;
}

int LiteYoloproBase::Detect(const InfImage* img, const MPI_IVA_OBJ_LIST_S* obj_list,
                             InfDetList* result)
{
	std::vector<FaceBox> face_list;
	int ret = FaceDetect(img, obj_list, face_list);
	TransformResult(face_list, result, 1.0f, m_config->labels.size);

#ifndef _HOST_LINUX
	struct timeval tv;
	gettimeofday(&tv, NULL);
	TIMESPEC_S timespec;
	timespec.tv_sec = tv.tv_sec;
	timespec.tv_nsec = tv.tv_usec * 1000;
	struct tm localtime;
	localtime_r(&timespec.tv_sec, &localtime);
	timespec.tv_sec = mktime(&localtime);

	InfImage wimg = GetInputImage();
	VFTR_dumpStart();
	VFTR_dump(&wimg, sizeof(wimg),
	          COMPOSE_EAIF_FLAG_VER_1(InfImage, InfImage), timespec);
	VFTR_dump(wimg.data, wimg.w * wimg.h * wimg.c,
	          COMPOSE_EAIF_FLAG_VER_1(InfU8Array, InfImage), timespec);
	VFTR_dump(result, sizeof(*result),
	          COMPOSE_EAIF_FLAG_VER_1(InfDetList, InfDetList), timespec);
	VFTR_dumpEnd();
#endif

	return ret;
}

void LiteYoloproBase::WriteDebugInfo(const MPI_RECT_POINT_S* roi, const Scaler& scale_factor,
                                     const std::vector<FaceBox>& face_list)
{
	char snapshot_img_name[256] = {};
	char snapshot_img_log[256] = {};
	char buf[2046] = {};
	InfImage wimg = GetInputImage();
	MPI_RECT_POINT_S t_roi{};
	if (roi) t_roi = *roi;

	sprintf(snapshot_img_name, SNAPSHOT_FD_FORMAT, m_snapshot_prefix,
	        m_snapshot_cnt,
	        (int)face_list.size(),
	        wimg.c == 1 ? "pgm" : "ppm");

	sprintf(snapshot_img_log, SNAPSHOT_FD_FORMAT, m_snapshot_prefix,
	        m_snapshot_cnt,
	        (int)face_list.size(), "log");

	Inf_Imwrite(snapshot_img_name, &wimg);
	m_snapshot_cnt++;

	FILE* fp = fopen(snapshot_img_log, "w");
	if (!fp) {
		inf_log_err("Cannot open %s", snapshot_img_log);
		return;
	}

	int offset = sprintf(buf, "{\"det\":[");
	int i = 0;
	for (const auto& box : face_list) {
		offset += sprintf(&buf[offset], R"({"id":%d,"rect":[%.2f,%.2f,%.2f,%.2f]},)",
		        i++,
		        (float)(box.x0 - t_roi.sx) / scale_factor.w,
		        (float)(box.y0 - t_roi.sy) / scale_factor.h,
		        (float)(box.x1 - t_roi.sx) / scale_factor.w,
		        (float)(box.y1 - t_roi.sy) / scale_factor.h);
	}
	if (!face_list.empty())
		offset--;
	offset += sprintf(&buf[offset], "]}");
	fprintf(fp, "%s\n", buf);
	fclose(fp);
}

#endif // USE_NCNN
