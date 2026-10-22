#ifdef USE_TFLITE_MICRO
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "inf_service.h"
#include "utils/printf.h"
#include "inf_remote.h"
#include "FreeRTOS.h"
#include "task.h"

#define __DEBUG__ 0
#define LPRINTF(format, ...) printf("[RTOS INF]: " format, ##__VA_ARGS__)


#define REGISTER_STATIC_OP_RESOLVER(micro_op_resolver)               \
	static int op_registered = 0;                                \
	static tflite::MicroMutableOpResolver<20> micro_op_resolver; \
	if (!op_registered) {                                        \
		micro_op_resolver.AddConcatenation();                \
		micro_op_resolver.AddConv2D();                       \
		micro_op_resolver.AddDepthwiseConv2D();              \
		micro_op_resolver.AddFullyConnected();               \
		micro_op_resolver.AddMaxPool2D();                    \
		micro_op_resolver.AddMean();                         \
		micro_op_resolver.AddPad();                          \
		micro_op_resolver.AddQuantize();                     \
		micro_op_resolver.AddRelu();                         \
		micro_op_resolver.AddReshape();                      \
		micro_op_resolver.AddStridedSlice();                 \
		micro_op_resolver.AddTranspose();                    \
		/*------------*/                                     \
		micro_op_resolver.AddAveragePool2D();                \
		micro_op_resolver.AddSoftmax();                      \
		micro_op_resolver.AddAdd();                          \
		micro_op_resolver.AddLogistic();                     \
		micro_op_resolver.AddPack();                         \
		micro_op_resolver.AddResizeNearestNeighbor();        \
		micro_op_resolver.AddShape();                        \
		micro_op_resolver.AddMul();                          \
		op_registered = 1;                                   \
  }

#if (__DEBUG__)
#define LOG_SECTION(__section_name, __stmts)          \
	printf("<<< Start of " #__section_name "\n"); \
	__stmts;                                      \
	printf(">>> End of " #__section_name "\n")
#else
#define LOG_SECTION(__section_name, __stmts)          \
	__stmts;
#endif

static tflite::MicroErrorReporter _error_reporter;

static void collect_tensor_info(InfTensorInfo& info, TfLiteTensor& tensor, const uint8_t* arena, bool verbose)
{
	info.type = tensor.type;
	info.nums_dims = tensor.dims->size;
	for (int i = 0; i < std::min(info.nums_dims, TENSOR_DIMENSION_MAX); ++i) {
		info.dims[i] = tensor.dims->data[i];
	}
	info.zero_point = tensor.params.zero_point;
	info.scale = tensor.params.scale;
	info.bytes = tensor.bytes;
	info.arena_offset = tensor.data.uint8 - arena;

	if (verbose) {
		char buf[256];
		char* cursor = buf;
		cursor += sprintf(cursor, "tensor{type=%d, dims=%d", info.type, info.dims[0]);
		for (int i = 1; i < info.nums_dims; ++i) {
			cursor += sprintf(cursor, "x%d", info.dims[i]);
		}
		cursor += sprintf(cursor, ", zero_point=%d, scale(x1M)=%d}", info.zero_point,
		                  static_cast<int>(info.scale * 1000000));
		LPRINTF("%s\n", buf);
	}
}

void inf_load_model_handler(ampi_svc svc, void* data, int len, svc_event_t evn)
{
	if (evn == SVC_CLEAN) {
		return;
	}

	auto params = static_cast<InfLoadModelParams*>(data);
	InfRemoteModelContext* context = params->context;

	if (context->verbose) {
		LPRINTF("{%X} === Start of %s ===\n", svc, __func__);
	}

	int32_t result = AMPI_SUCCESS;
	LOG_SECTION(create op-resolver,
	            REGISTER_STATIC_OP_RESOLVER(resolver));

	const tflite::Model* model;
	LOG_SECTION(decode model,
	            model = tflite::GetModel(params->model_data));

	if (model->version() != TFLITE_SCHEMA_VERSION) {
		TF_LITE_REPORT_ERROR(&_error_reporter,
		                     "Model provided is schema version %d not equal "
		                     "to supported version %d.",
		                     model->version(), TFLITE_SCHEMA_VERSION);
		result = AMPI_FAILURE;
		ampi_send(svc, &result, sizeof(result), -1);
		return;
	}
	context->model = model;
	
	size_t interpreter_size = sizeof(tflite::MicroInterpreter);
	LOG_SECTION(create interpreter,
	            auto interpreter = new (params->arena) tflite::MicroInterpreter(
	                    model, resolver, params->arena + interpreter_size,
	                    params->arena_size - interpreter_size, &_error_reporter));
	
	LOG_SECTION(allocate tensors,
	            TfLiteStatus status = interpreter->AllocateTensors());
	if (status != kTfLiteOk) {
		TF_LITE_REPORT_ERROR(&_error_reporter, "AllocateTensors() FAILED!!!");
		result = AMPI_FAILURE;
		ampi_send(svc, &result, sizeof(result), -1);
		return;
	}
	context->interpreter = interpreter;

	InfRemoteModelInfo& info = *params->model_info;
	info.nums_input_tensor = interpreter->inputs_size();
	info.nums_output_tensor = interpreter->outputs_size();
	info.operators_size = interpreter->operators_size();
	info.arena_used_bytes = interpreter->arena_used_bytes() - interpreter_size;

	for (size_t i = 0; i < std::min<size_t>(info.nums_input_tensor, MAX_INPUT_TENSOR); ++i) {
		if (context->verbose) {
			LPRINTF("collecting input tensor#%d info.\n", i);
		}
		collect_tensor_info(info.input_tensors[i], *interpreter->input_tensor(i), params->arena,
		                    context->verbose);
	}

	for (size_t i = 0; i < std::min<size_t>(info.nums_output_tensor, MAX_OUTPUT_TENSOR); ++i) {
		if (context->verbose) {
			LPRINTF("collecting output tensor#%d info.\n", i);
		}
		collect_tensor_info(info.output_tensors[i], *interpreter->output_tensor(i), params->arena,
		                    context->verbose);
	}

	ampi_send(svc, &result, sizeof(result), -1);

	if (context->verbose) {
		LPRINTF("{%X} === End of %s ===\n", svc, __func__);
	}
}

void inf_model_forward_handler(ampi_svc svc, void* data, int len, svc_event_t evn)
{
	if (evn == SVC_CLEAN) {
		return;
	}

	auto context = static_cast<InfRemoteModelContext*>(data);
	auto interpreter = static_cast<tflite::MicroInterpreter*>(context->interpreter);

	int32_t result;

	TickType_t start_mark = xTaskGetTickCount();
	TfLiteStatus status = interpreter->Invoke();
	TickType_t end_mark = xTaskGetTickCount();
	result = static_cast<int32_t>(status);

	if (context->verbose) {
		TickType_t duration_ms = (end_mark - start_mark) * 1000 / configTICK_RATE_HZ;
		LPRINTF("{%X} forwarding model network in %d ms => %d\n", svc, duration_ms, result);
	}
	ampi_send(svc, &result, sizeof(result), -1);
}
#endif
