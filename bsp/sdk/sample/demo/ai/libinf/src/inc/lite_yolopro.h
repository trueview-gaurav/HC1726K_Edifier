#ifndef USE_NCNN
#ifndef LITE_YOLOPRO_H_
#define LITE_YOLOPRO_H_

#include <memory>
#include <string>
#include <vector>

#include <cstdint>

#ifndef USE_MICROLITE
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/model.h"
#pragma GCC diagnostic pop
#else
#include "tensorflow/lite/micro/micro_interpreter.h"
#endif

#include "inf_adapter.h"
#include "inf_types.h"
#include "inf_model_internal.h"
#include "inf_face_internal.h"
#include "inf_utils_lite.h"

class LiteYoloproBase : public InfFaceDetect, protected LiteModelTraits
{
public:
	LiteYoloproBase(InfModelInfo* info)
	{
		m_config = info;
		SetupConfig(info);
	}

	~LiteYoloproBase() override
	{
		ReleaseConfig(m_config);
		delete m_config;
	}

	void SetupConfig(InfModelInfo* conf);
	int LoadModels(const char* model_dir, const InfStrList* model_paths) override;

	int FaceDetect(const InfImage* img, std::vector<FaceBox>& result) override;
	int FaceDetect(const InfImage* img, const MPI_IVA_OBJ_LIST_S* obj_list, std::vector<FaceBox>& result) override;
	int Detect(const InfImage* img, InfDetList* result) override;
	int Detect(const InfImage* img, const MPI_IVA_OBJ_LIST_S* obj_list, InfDetList* result) override;

protected:
	int RunNetwork(const InfImage& img, const Shape& size, int chn, InfDataType mtype,
	               const MPI_RECT_POINT_S* roi, const Pads* pads, int verbose);

	int m_input_dim[3];  /* h x w x c */
	int m_output_dim[3]; /* batch x num_anchors x num_channels */
	QuantInfo m_qinfo;
	int m_preprocess_mode = 0; /* 0=resize, 1=aspect_ratio(pad), 2=short_axis(crop) */

private:
	template <typename Tbuffer>
	int TRunNet(const InfImage& img, const MPI_RECT_POINT_S* roi, std::vector<FaceBox>& face_list);
	int FaceDetect(const InfImage* img, const MPI_RECT_POINT_S& roi, std::vector<FaceBox>& result);
	void WriteDebugInfo(const MPI_RECT_POINT_S* roi, const Scaler& scale_factor,
	                    const std::vector<FaceBox>& face_list);
};

class LiteYolopro : public LiteYoloproBase
{
public:
	LiteYolopro(InfModelInfo* info)
	        : LiteYoloproBase(info)
	{
	}

	InfImage GetInputImage() override;
	void SetModelThreads(int nthread) override;

protected:
	bool PrepareInterpreter(const std::string& model_path) override;
	bool CollectModelInfo() override;
	void* InputTensorBuffer(size_t input_index) override
	{
		return m_model->input_tensor(input_index)->data.data;
	}
	void* OutputTensorBuffer(size_t output_index) override
	{
		return m_model->output_tensor(output_index)->data.data;
	}
	TfLiteStatus Invoke() override
	{
		return m_model->Invoke();
	}
	size_t GetArenaUsedBytes() override
	{
		return inf_tf_adapter::getArenaUsedBytes(*m_model);
	}

#ifdef USE_MICROLITE
	friend int inf_tf_adapter::LiteYolopro_LoadModel(LiteYolopro& detector, const std::string& model_path,
	                                                 std::unique_ptr<tflite::MicroInterpreter>& model,
	                                                 std::unique_ptr<unsigned char[]>& model_fb);
	std::unique_ptr<unsigned char[]> m_model_fb;
	std::unique_ptr<tflite::MicroInterpreter> m_model;
	uint8_t m_arena[768 * 1024];
#else
	std::unique_ptr<tflite::Interpreter> m_model;
	std::unique_ptr<tflite::FlatBufferModel> m_model_fb;
#endif
};

#endif /* LITE_YOLOPRO_H_ */
#endif /* USE_NCNN */
