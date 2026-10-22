#ifdef USE_ROSA
//#include "net.h" // ncnn
#include "sd_service.h"

//#include "inf_remote.h"
#include "FreeRTOS.h"
#include "task.h"
//#include "resize_neon.h"

#include "Eigen/Core"
#include "Eigen/Dense"
#include <numeric>
#include "librosa.h"
#include "utils/printf.h"

#define __DEBUG__ 0
#define LPRINTF(format, ...) printf("[RTOS SD]: " format, ##__VA_ARGS__)


#if (__DEBUG__)
#define LOG_SECTION(__section_name, __stmts)          \
	printf("<<< Start of " #__section_name "\n"); \
	__stmts;                                      \
	printf(">>> End of " #__section_name "\n")
#else
#define LOG_SECTION(__section_name, __stmts)          \
	__stmts;
#endif

typedef Eigen::Matrix<float, 1, Eigen::Dynamic, Eigen::RowMajor> Vectorf;
typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Matrixf;

typedef struct cd_rtos_ctx {
	void *data;
	size_t size;
	int sample_rate;
	int window_function;
	int window_size;
	int stride;
	bool pad_left;
	bool pad_right;
	float prev_max_log_sp;
} CdRtosCtx;

void sd_rosa_feature_handler(ampi_svc svc, void* data, int len, svc_event_t evn)
{
	if (evn == SVC_CLEAN) {
		LPRINTF("evn == SVC_CLEAN, return!!\n");
		return;
	}
//	LPRINTF("sd_rosa_feature_handler\n");

	auto ctx = static_cast<CdRtosCtx*>(data);

//	LPRINTF("data = %p\n", ctx->data);

	int32_t result = AMPI_SUCCESS;
//	int16_t *input_buf = *(int16_t **)data;

	int sr = ctx->sample_rate;
	int n_fft = N_FFT;
	int frame_length = 2048;
	int n_hop = ctx->stride * (sr / 1000); // default: 512
	int win_length = ctx->window_size * (sr / 1000); // default: 2048
	int win = ctx->window_function;
	char window[5] = { 0 };
	float power = 2.f;
	int n_mfcc = N_MFCC;
	int n_mels = 128;
	int fmin = 0;
	int fmax = sr / 2.0;
	bool norm = true;
	int type = 2;
	float roll_percent = 0.90;
	std::vector<double> ret;
	bool pad_left = ctx->pad_left;
	bool pad_right = ctx->pad_right;
	float curr_max_log_sp = 0.f;
	float prev_max_log_sp = ctx->prev_max_log_sp;

	if (win == 0) {
		strncpy(window, "hamm", 5);
	} else if (win == 1) {
		strncpy(window, "hann", 5);
	} else {
		strncpy(window, "hann", 5);
	}

//	LPRINTF("sr = %d, win = %d : %s\n", sr, win, window);

	size_t num_elements = ctx->size;

	float* input_buffer = reinterpret_cast<float*>(ctx->data);

	std::vector<float> x(input_buffer, input_buffer + num_elements);

	// common used input: _spectrogram, fft_frequencies
	// auto sp_start_time = std::chrono::system_clock::now();
	Matrixf sp = librosa::internal::_spectrogram(x, n_fft, n_hop, win_length, window, pad_left, pad_right, "constant", 1.f).transpose();
	// auto sp_end_time = std::chrono::system_clock::now();
	// auto sp_duration = std::chrono::duration_cast<std::chrono::milliseconds>(sp_end_time - sp_start_time);

	// auto fft_freqs_start_time = std::chrono::system_clock::now();
	Vectorf fft_freqs = librosa::internal::fft_frequencies(sr, n_fft);
	// auto fft_freqs_end_time = std::chrono::system_clock::now();
	// auto fft_freqs_duration = std::chrono::duration_cast<std::chrono::milliseconds>(fft_freqs_end_time - fft_freqs_start_time);

	// zero_crossing_rate
	// auto zero_crossing_rate_start_time = std::chrono::system_clock::now();
	std::vector<float> zero_crossing_rate = librosa::Feature::zeroCrossingRate(x, frame_length, n_hop, 0, pad_left, pad_right);
	double zero_crossing_rate_sum = std::accumulate(zero_crossing_rate.begin(), zero_crossing_rate.end(), 0.0f);
	double zero_crossing_rate_mean = zero_crossing_rate_sum / (double)(zero_crossing_rate.size());
	// auto zero_crossing_rate_end_time = std::chrono::system_clock::now();
	// auto zero_crossing_rate_duration = std::chrono::duration_cast<std::chrono::milliseconds>(zero_crossing_rate_end_time - zero_crossing_rate_start_time);

	// rms
	// auto rms_start_time = std::chrono::system_clock::now();
	std::vector<float> rms = librosa::Feature::rms(x, frame_length, n_hop, pad_left, pad_right);
	double rms_sum = std::accumulate(rms.begin(), rms.end(), 0.0f);
	double rms_mean = rms_sum / (double)(rms.size());
	// auto rms_end_time = std::chrono::system_clock::now();
	// auto rms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(rms_end_time - rms_start_time);

	// mfcc
	// auto mfcc_start_time = std::chrono::system_clock::now();
	std::vector<std::vector<float>> mfcc = librosa::Feature::mfcc(x, sr, n_fft, n_hop, win_length, window, pad_left, pad_right, "constant", power, n_mels, fmin, fmax, n_mfcc, norm, type, prev_max_log_sp, &curr_max_log_sp);
	std::vector<double> mfcc_mean(mfcc.size(), 0.0f);
	for (size_t i = 0; i < mfcc.size(); i++) {
		double sum = 0.0f;
		for (size_t j = 0; j < mfcc[0].size(); j++) {
			sum += mfcc[i][j];
		}
		mfcc_mean[i] = sum / (double)(mfcc[0].size());
	}
	// auto mfcc_end_time = std::chrono::system_clock::now();
	// auto mfcc_duration = std::chrono::duration_cast<std::chrono::milliseconds>(mfcc_end_time - mfcc_start_time);

	// spectral_centroid
	// auto spectral_centroid_start_time = std::chrono::system_clock::now();
	Vectorf centroid = librosa::Feature::spectralCentroid(sp, fft_freqs);
	std::vector<float> spectral_centroid = librosa::internal::convertVectorf(centroid);
	double spectral_centroid_sum = std::accumulate(spectral_centroid.begin(), spectral_centroid.end(), 0.0f);
	double spectral_centroid_mean = spectral_centroid_sum / (double)(spectral_centroid.size());
	// auto spectral_centroid_end_time = std::chrono::system_clock::now();
	// auto spectral_centroid_duration = std::chrono::duration_cast<std::chrono::milliseconds>(spectral_centroid_end_time - spectral_centroid_start_time);

	// // spectral_rolloff
	// auto spectral_rolloff_start_time = std::chrono::system_clock::now();
	std::vector<float> spectral_rolloff = librosa::Feature::spectralRolloff(sp, fft_freqs, roll_percent);
	double spectral_rolloff_sum = std::accumulate(spectral_rolloff.begin(), spectral_rolloff.end(), 0.0f);
	double spectral_rolloff_mean = spectral_rolloff_sum / (double)(spectral_rolloff.size());
	// auto spectral_rolloff_end_time = std::chrono::system_clock::now();
	// auto spectral_rolloff_duration = std::chrono::duration_cast<std::chrono::milliseconds>(spectral_rolloff_end_time - spectral_rolloff_start_time);

	// spectral_bandwidth
	// auto spectral_bandwidth_start_time = std::chrono::system_clock::now();
	std::vector<float> spectral_bandwidth = librosa::Feature::spectralBandwidth(sp, centroid, fft_freqs);
	double spectral_bandwidth_sum = std::accumulate(spectral_bandwidth.begin(), spectral_bandwidth.end(), 0.0f);
	double spectral_bandwidth_mean = spectral_bandwidth_sum / (double)(spectral_bandwidth.size());
	// auto spectral_bandwidth_end_time = std::chrono::system_clock::now();
	// auto spectral_bandwidth_duration = std::chrono::duration_cast<std::chrono::milliseconds>(spectral_bandwidth_end_time - spectral_bandwidth_start_time);

	// LPRINTF("Receive len:%d, addr:%08x, data[0]:%d!\n", len, *(uint16_t **)data, input_buf[0]);
	ret.push_back(zero_crossing_rate_mean);
	ret.push_back(rms_mean);
	for (const auto& val: mfcc_mean) {
		ret.push_back(val);
	}
	ret.push_back(spectral_centroid_mean);
	ret.push_back(spectral_rolloff_mean);
	ret.push_back(spectral_bandwidth_mean);
	ret.push_back(curr_max_log_sp);

	memcpy(ctx->data, ret.data(), ret.size() * sizeof(double));

	ampi_send(svc, &result, sizeof(result), -1);
}

#endif //USE_ROSA
