/* ------------------------------------------------------------------
* Copyright (C) 2020 ewan xu<ewan_xu@outlook.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied.
* See the License for the specific language governing permissions
* and limitations under the License.
* -------------------------------------------------------------------
*/

#ifndef LIBROSA_H_
#define LIBROSA_H_

#include "Eigen/Core"
#include "Eigen/Dense"
#include "unsupported/Eigen/FFT"

#include <vector>
#include <complex>
#include <iostream>
#include <chrono>
#include <cmath>

#define N_FFT 2048
#define N_MFCC 13

///
/// @brief c++ implemention of librosa
///
namespace librosa
{
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

typedef Eigen::Matrix<float, 1, Eigen::Dynamic, Eigen::RowMajor> Vectorf;
typedef Eigen::Matrix<std::complex<float>, 1, Eigen::Dynamic, Eigen::RowMajor> Vectorcf;
typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Matrixf;
typedef Eigen::Matrix<std::complex<float>, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Matrixcf;

namespace internal
{
static Vectorf eigenPad(Vectorf &x, int left, int right, const char *mode, float value)
{
	Vectorf x_paded = Vectorf::Constant(left + x.size() + right, value);
	x_paded.segment(left, x.size()) = x;

	if (strcmp(mode, "reflect") == 0) {
		for (int i = 0; i < left; ++i) {
			x_paded[i] = x[left - i];
		}
		for (int i = left; i < left + right; ++i) {
			x_paded[i + x.size()] = x[x.size() - 2 - i + left];
		}
	}

	if (strcmp(mode, "symmetric") == 0) {
		for (int i = 0; i < left; ++i) {
			x_paded[i] = x[left - i - 1];
		}
		for (int i = left; i < left + right; ++i) {
			x_paded[i + x.size()] = x[x.size() - 1 - i + left];
		}
	}

	if (strcmp(mode, "edge") == 0) {
		for (int i = 0; i < left; ++i) {
			x_paded[i] = x[0];
		}
		for (int i = left; i < left + right; ++i) {
			x_paded[i + x.size()] = x[x.size() - 1];
		}
	}

	if (strcmp(mode, "constant") == 0) {
		for (int i = 0; i < left; ++i) {
			x_paded[i] = 0;
		}
		for (int i = left; i < left + right; ++i) {
			x_paded[i + x.size()] = 0;
		}
	}

	return x_paded;
}

static Matrixcf stft(Vectorf &x, int n_fft, int n_hop, int window_length, const char *win, bool pad_left,
                     bool pad_right, const char *mode)
{
	Vectorf window = Vectorf::Zero(window_length);
	if (strcmp(win, "hamm") == 0) {
		window = 0.54f - 0.46f * (Vectorf::LinSpaced(n_fft, 0.f, static_cast<float>(n_fft - 1)) * 2.f * M_PI /
		                          window_length)
		                                 .array()
		                                 .cos();
	} else {
		window = 0.5f - 0.5f * (Vectorf::LinSpaced(n_fft, 0.f, static_cast<float>(n_fft - 1)) * 2.f * M_PI /
		                        window_length)
		                                .array()
		                                .cos();
	}

	if (window_length > n_fft) {
		//		throw std::invalid_argument("Window length cannot be greater than n_fft");
	}

	int window_pad_left = (n_fft - window_length) / 2;
	// int pad_right = n_fft - window_length - pad_left;
	Vectorf window_padded = Vectorf::Zero(n_fft);
	window_padded.segment(window_pad_left, window_length) = window.segment(0, window_length);

	int pad_left_len = pad_left ? n_fft / 2 : 0;
	int pad_right_len = pad_right ? n_fft / 2 : 0;
	Vectorf x_padded = eigenPad(x, pad_left_len, pad_right_len, mode, 0.f);

	int n_f = n_fft / 2 + 1;
	int n_frames = 1 + (x_padded.size() - n_fft) / n_hop;
	Matrixcf X(n_frames, n_fft);
	Eigen::FFT<float> fft;

	for (int i = 0; i < n_frames; ++i) {
		Vectorf x_frame = window_padded.array() * x_padded.segment(i * n_hop, n_fft).array();
		X.row(i) = fft.fwd(x_frame);
	}
	return X.leftCols(n_f);
}

static Matrixf spectrogram(Matrixcf &X, float power = 1.f)
{
	return X.cwiseAbs().array().pow(power);
}

static Matrixf melfilter(int sr, int n_fft, int n_mels, int fmin, int fmax)
{
	int n_f = n_fft / 2 + 1;
	Vectorf fft_freqs = (Vectorf::LinSpaced(n_f, 0.f, static_cast<float>(n_f - 1)) * sr) / n_fft;

	float f_min = 0.f;
	float f_sp = 200.f / 3.f;
	float min_log_hz = 1000.f;
	float min_log_mel = (min_log_hz - f_min) / f_sp;
	float logstep = logf(6.4f) / 27.f;

	auto hz_to_mel = [=](int hz, bool htk = false) -> float {
		if (htk) {
			return 2595.0f * log10f(1.0f + hz / 700.0f);
		}
		float mel = (hz - f_min) / f_sp;
		if (hz >= min_log_hz) {
			mel = min_log_mel + logf(hz / min_log_hz) / logstep;
		}
		return mel;
	};
	auto mel_to_hz = [=](Vectorf &mels, bool htk = false) -> Vectorf {
		if (htk) {
			return 700.0f *
			       (Vectorf::Constant(n_mels + 2, 10.f).array().pow(mels.array() / 2595.0f) - 1.0f);
		}
		return (mels.array() > min_log_mel)
		        .select(((mels.array() - min_log_mel) * logstep).exp() * min_log_hz,
		                (mels * f_sp).array() + f_min);
	};

	float min_mel = hz_to_mel(fmin);
	float max_mel = hz_to_mel(fmax);
	Vectorf mels = Vectorf::LinSpaced(n_mels + 2, min_mel, max_mel);
	Vectorf mel_f = mel_to_hz(mels);
	Vectorf fdiff = mel_f.segment(1, mel_f.size() - 1) - mel_f.segment(0, mel_f.size() - 1);
	Matrixf ramps = mel_f.replicate(n_f, 1).transpose().array() - fft_freqs.replicate(n_mels + 2, 1).array();

	Matrixf lower = -ramps.topRows(n_mels).array() / fdiff.segment(0, n_mels).transpose().replicate(1, n_f).array();
	Matrixf upper =
	        ramps.bottomRows(n_mels).array() / fdiff.segment(1, n_mels).transpose().replicate(1, n_f).array();
	Matrixf weights = (lower.array() < upper.array()).select(lower, upper).cwiseMax(0);

	auto enorm =
	        (2.0 / (mel_f.segment(2, n_mels) - mel_f.segment(0, n_mels)).array()).transpose().replicate(1, n_f);
	weights = weights.array() * enorm;

	return weights;
}

static Matrixf melspectrogram(Vectorf &x, int sr, int n_fft, int n_hop, int window_length, const char *win,
                              bool pad_left, bool pad_right, const char *mode, float power, int n_mels, int fmin,
                              int fmax)
{
	Matrixcf X = stft(x, n_fft, n_hop, window_length, win, pad_left, pad_right, mode);
	Matrixf mel_basis = melfilter(sr, n_fft, n_mels, fmin, fmax);
	Matrixf sp = spectrogram(X, power);
	Matrixf mel = mel_basis * sp.transpose();
	return mel;
}

static Matrixf power2db(Matrixf &x, float prev_max, float *new_max)
{
	auto log_sp = 10.0f * x.array().max(1e-10).log10();
	*new_max = log_sp.maxCoeff();
	return log_sp.cwiseMax(std::max(*new_max, prev_max) - 80.0f);
}

static Matrixf createDCTMatrix(int N)
{
	Matrixf dct(N, N);
	float scale = sqrtf(2.0 / N);
	float sqrtN_inv = 1.0 / sqrtf(N);

	for (int k = 0; k < N; ++k) {
		for (int n = 0; n < N; ++n) {
			if (k == 0) {
				dct(k, n) = sqrtN_inv;
			} else {
				dct(k, n) = scale * cosf(M_PI * (n + 0.5) * k / N);
			}
		}
	}

	return dct;
}

static Matrixf dct(const Matrixf &S, int n_mfcc)
{
	int N = S.rows();
	Matrixf dctMatrix = createDCTMatrix(N);
	Matrixf mfcc = dctMatrix.topRows(n_mfcc) * S;
	return mfcc;
}

static Matrixf normalize(const Matrixf &S)
{
	Matrixf normS = S;
	for (int i = 0; i < S.cols(); ++i) {
		float sum = S.col(i).sum();
		if (sum != 0) {
			normS.col(i) /= sum;
		}
	}
	return normS;
}

static Matrixf expand_to(const Vectorf &freqs, int rows, int mode)
{
	if (mode == 1) {
		Matrixf expanded(freqs.size(), rows);
		for (int i = 0; i < rows; ++i) {
			expanded.col(i) = freqs.transpose();
		}
		return expanded;
	} else {
		Matrixf expanded(1, freqs.size());
		expanded.row(0) = freqs.transpose();
		return expanded;
	}
}

static Matrixf _spectrogram(std::vector<float> &x, int n_fft, int n_hop, int window_length, const char *win,
                            bool pad_left, bool pad_right, const char *mode, float power)
{
	Vectorf map_x = Eigen::Map<Vectorf>(x.data(), x.size());
	Matrixcf X = stft(map_x, n_fft, n_hop, window_length, win, pad_left, pad_right, mode);
	Matrixf sp = spectrogram(X, power);
	return sp;
}

static Vectorf fft_frequencies(int sr, int n_fft)
{
	int n_f = n_fft / 2 + 1;
	Vectorf fft_freqs = (Vectorf::LinSpaced(n_f, 0.f, static_cast<float>(n_f - 1)) * sr) / n_fft;
	return fft_freqs;
}

static Matrixf subtractOuter(const Vectorf &a, const Vectorf &b)
{
	int rows = a.size();
	int cols = b.size();
	Matrixf result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result(i, j) = a(i) - b(j);
		}
	}
	return result;
}

static std::vector<float> convertVectorf(const Vectorf &eigen_vector)
{
	std::vector<float> std_vector(eigen_vector.size());
	Eigen::Map<Vectorf>(std_vector.data(), eigen_vector.size()) = eigen_vector;
	return std_vector;
}

static std::vector<std::vector<float> > convertMatrixf(const Matrixf &eigen_matrix)
{
	std::vector<std::vector<float> > std_matrix(eigen_matrix.rows(), std::vector<float>(eigen_matrix.cols(), 0.f));
	for (int i = 0; i < eigen_matrix.rows(); ++i) {
		auto &row = std_matrix[i];
		Eigen::Map<Vectorf>(row.data(), row.size()) = eigen_matrix.row(i);
	}
	return std_matrix;
}

static Matrixf cumSum(const Matrixf &matrix)
{
	Matrixf result(matrix.rows(), matrix.cols());
	result(0, 0) = matrix(0, 0);
	for (int i = 0; i < matrix.rows(); ++i) {
		for (int j = 0; j < matrix.cols(); ++j) {
			if (i == 0) {
				result(i, j) = matrix(i, j);
			} else {
				result(i, j) = result(i - 1, j) + matrix(i, j);
			}
		}
	}
	return result;
}

static std::vector<float> stdPad(std::vector<float> &array, int frame_length, bool pad_left, bool pad_right,
                                 const char *pad_mode)
{
	int original_size = array.size();
	int pad_left_len = pad_left ? frame_length / 2 : 0;
	int pad_right_len = pad_right ? frame_length / 2 : 0;
	int new_size = original_size + pad_left_len + pad_right_len;
	std::vector<float> padded_array(new_size, 0.f);
	if (pad_left) {
		std::copy(array.begin(), array.end(), padded_array.begin() + pad_left_len);
	} else {
		std::copy(array.begin(), array.end(), padded_array.begin());
	}

	if (strcmp(pad_mode, "edge") == 0) {
		if (pad_left) {
			for (int i = 0; i < pad_left_len; i++) {
				padded_array[i] = padded_array[pad_left_len];
			}
		}
		if (pad_right) {
			for (int i = 0; i < pad_right_len; i++) {
				padded_array[original_size + pad_left_len + i] =
				        padded_array[original_size + pad_left_len];
			}
		}
	} else if (strcmp(pad_mode, "constant") == 0) {
		;
	}
	return padded_array;
}

static std::vector<std::vector<float> > frame(std::vector<float> &array, int frame_length, int hop_length, int size)
{
	int row = frame_length;
	int col = (size - frame_length) / hop_length + 1;
	std::vector<std::vector<float> > framed_x(row, std::vector<float>(col, 0.f));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			framed_x[i][j] = array[i + j * hop_length];
		}
	}
	return framed_x;
}

static std::vector<float> calZcr(std::vector<std::vector<float> > &x, int pad)
{
	int row = x.size();
	int col = x[0].size();
	float threshold = 1e-10;
	std::vector<float> zcr(col, 0.f);
	for (int j = 0; j < col; j++) {
		for (int i = 1; i < row; i++) {
			if (x[i][j] >= -threshold && x[i][j] <= threshold) {
				x[i][j] = 0;
			}
			if (x[i - 1][j] >= -threshold && x[i - 1][j] <= threshold) {
				x[i - 1][j] = 0;
			}
			bool curr_pos = x[i][j] >= 0;
			bool prev_pos = x[i - 1][j] >= 0;
			zcr[j] += curr_pos != prev_pos;
		}
	}
	for (int i = 0; i < col; i++) {
		zcr[i] += pad;
	}

	for (int i = 0; i < col; i++) {
		zcr[i] /= row;
	}
	return zcr;
}

static std::vector<float> calRms(std::vector<std::vector<float> > &x)
{
	int row = x.size();
	int col = x[0].size();
	std::vector<float> output(col, 0.f);
	for (int j = 0; j < col; j++) {
		double rms_of_cols = 0.f;
		for (int i = 0; i < row; i++) {
			rms_of_cols += x[i][j] * x[i][j];
		}
		rms_of_cols /= row;
		rms_of_cols = sqrtf(rms_of_cols);
		output[j] = (float)rms_of_cols;
	}
	return output;
}

static Matrixf applyThreshold(const Matrixf &total_energy, const Matrixf &threshold)
{
	assert(threshold.rows() == 1 && threshold.cols() == total_energy.cols());

	Matrixf result(total_energy.rows(), total_energy.cols());
	for (int i = 0; i < total_energy.rows(); ++i) {
		for (int j = 0; j < total_energy.cols(); ++j) {
			if (total_energy(i, j) < threshold(0, j)) {
				result(i, j) = 0.0;
			} else {
				result(i, j) = 1.0;
			}
		}
	}
	return result;
}

static std::vector<float> nullMin(const Matrixf &matrix)
{
	std::vector<float> rolloff;
	for (int j = 0; j < matrix.cols(); ++j) {
		float min_val = std::numeric_limits<float>::infinity();
		for (int i = 0; i < matrix.rows(); ++i) {
			float val = matrix(i, j);
			if (val != 0.0 && val < min_val) {
				min_val = val;
			}
		}
		rolloff.push_back(min_val);
	}
	return rolloff;
}

} // namespace internal

class Feature {
    public:
	/**
	* @brief      short-time fourier transform similar with librosa.feature.stft
	* @param      x             input audio signal
	* @param      n_fft         length of the FFT size
	* @param      n_hop         number of samples between successive frames
	* @param      win           window function. currently only supports 'hann'
	* @param      center        same as librosa
	* @param      mode          pad mode. support "reflect","symmetric","edge"
	* @return     complex-valued matrix of short-time fourier transform coefficients.
	*/
	static std::vector<std::vector<std::complex<float> > > stft(std::vector<float> &x, int n_fft, int n_hop,
	                                                            int window_length, const char *win, bool pad_left,
	                                                            bool pad_right, const char *mode)
	{
		Vectorf map_x = Eigen::Map<Vectorf>(x.data(), x.size());
		Matrixcf X = internal::stft(map_x, n_fft, n_hop, window_length, win, pad_left, pad_right, mode);
		std::vector<std::vector<std::complex<float> > > X_vector(
		        X.rows(), std::vector<std::complex<float> >(X.cols(), 0));
		for (int i = 0; i < X.rows(); ++i) {
			auto &row = X_vector[i];
			Eigen::Map<Vectorcf>(row.data(), row.size()) = X.row(i);
		}
		return X_vector;
	}

	/**
	* @brief      compute mel spectrogram similar with librosa.feature.melspectrogram
	* @param      x             input audio signal
	* @param      sr            sample rate of 'x'
	* @param      n_fft         length of the FFT size
	* @param      n_hop         number of samples between successive frames
	* @param      win           window function. currently only supports 'hann'
	* @param      center        same as librosa
	* @param      mode          pad mode. support "reflect","symmetric","edge"
	* @param      power         exponent for the magnitude melspectrogram
	* @param      n_mels        number of mel bands
	* @param      f_min         lowest frequency (in Hz)
	* @param      f_max         highest frequency (in Hz)
	* @return     mel spectrogram matrix
	*/
	static std::vector<std::vector<float> > melspectrogram(std::vector<float> &x, Matrixf &sp, int sr, int n_fft,
	                                                       int n_hop, int window_length, const char *win,
	                                                       bool pad_left, bool pad_right, const char *mode,
	                                                       float power, int n_mels, int fmin, int fmax)
	{
		Vectorf map_x = Eigen::Map<Vectorf>(x.data(), x.size());
		Matrixf mel = internal::melspectrogram(map_x, sr, n_fft, n_hop, window_length, win, pad_left, pad_right,
		                                       mode, power, n_mels, fmin, fmax);
		std::vector<std::vector<float> > mel_vector = internal::convertMatrixf(mel);
		// std::vector<std::vector<float> > mel_vector(mel.rows(), std::vector<float>(mel.cols(), 0.f));
		// for (int i = 0; i < mel.rows(); ++i) {
		// 	auto &row = mel_vector[i];
		// 	Eigen::Map<Vectorf>(row.data(), row.size()) = mel.row(i);
		// }
		return mel_vector;
	}

	static std::vector<float> zeroCrossingRate(std::vector<float> &x, int frame_length, int hop_length, int pad,
	                                           bool pad_left, bool pad_right)
	{
		std::vector<float> padded_x = internal::stdPad(x, frame_length, pad_left, pad_right, "edge");
		std::vector<std::vector<float> > framed_x =
		        internal::frame(padded_x, frame_length, hop_length, padded_x.size());
		std::vector<float> zero_crossing_rate = internal::calZcr(framed_x, pad);
		return zero_crossing_rate;
	}

	static std::vector<float> rms(std::vector<float> &x, int frame_length, int hop_length, bool pad_left,
	                              bool pad_right)
	{
		std::vector<float> padded_x = internal::stdPad(x, frame_length, pad_left, pad_right, "constant");
		std::vector<std::vector<float> > framed_x =
		        internal::frame(padded_x, frame_length, hop_length, padded_x.size());
		std::vector<float> rms = internal::calRms(framed_x);
		return rms;
	}

	/**
	* @brief      compute mfcc similar with librosa.feature.mfcc
	* @param      x             input audio signal
	* @param      sr            sample rate of 'x'
	* @param      n_fft         length of the FFT size
	* @param      n_hop         number of samples between successive frames
	* @param      win           window function. currently only supports 'hann'
	* @param      center        same as librosa
	* @param      mode          pad mode. support "reflect","symmetric","edge"
	* @param      power         exponent for the magnitude melspectrogram
	* @param      n_mels        number of mel bands
	* @param      f_min         lowest frequency (in Hz)
	* @param      f_max         highest frequency (in Hz)
	* @param      n_mfcc        number of mfccs
	* @param      norm          ortho-normal dct basis
	* @param      type          dct type. currently only supports 'type-II'
	* @return     mfcc matrix
	*/
	static std::vector<std::vector<float> > mfcc(std::vector<float> &x, int sr, int n_fft, int n_hop,
	                                             int window_length, const char *win, bool pad_left, bool pad_right,
	                                             const char *mode, float power, int n_mels, int fmin, int fmax,
	                                             int n_mfcc, bool norm, int type, float prev_max_log_sp,
	                                             float *curr_max_log_sp)
	{
		Vectorf map_x = Eigen::Map<Vectorf>(x.data(), x.size());
		Matrixf mel = internal::melspectrogram(map_x, sr, n_fft, n_hop, window_length, win, pad_left, pad_right,
		                                       mode, power, n_mels, fmin, fmax);
		Matrixf mel_db = internal::power2db(mel, prev_max_log_sp, curr_max_log_sp);
		Matrixf dct = internal::dct(mel_db, n_mfcc);

		std::vector<std::vector<float> > mfcc_vector = internal::convertMatrixf(dct);
		// std::vector<std::vector<float> > mfcc_vector(dct.rows(), std::vector<float>(dct.cols(), 0.f));
		// for (int i = 0; i < dct.rows(); ++i) {
		// 	auto &row = mfcc_vector[i];
		// 	Eigen::Map<Vectorf>(row.data(), row.size()) = dct.row(i);
		// }
		return mfcc_vector;
	}

	static Vectorf spectralCentroid(Matrixf &sp, Vectorf &fft_freqs)
	{
		Matrixf norm_sp = internal::normalize(sp);
		Matrixf expanded_freqs = internal::expand_to(fft_freqs, sp.cols(), 1);
		Vectorf centroid = (expanded_freqs.cwiseProduct(norm_sp)).colwise().sum();

		return centroid;
	}

	static std::vector<float> spectralRolloff(Matrixf &sp, Vectorf &fft_freqs, float roll_percent)
	{
		// Matrixf expanded_freqs = internal::expand_to(fft_freqs, sp.cols(), 1);
		Matrixf broadcasted_freqs = fft_freqs.transpose().replicate(1, sp.cols());
		Matrixf total_energy = internal::cumSum(sp);
		Vectorf threshold = roll_percent * sp.colwise().sum();
		Matrixf expanded_thr = internal::expand_to(threshold, 1, 2);
		Matrixf ind = internal::applyThreshold(total_energy, expanded_thr);
		Matrixf rolloff = ind.cwiseProduct(broadcasted_freqs);
		std::vector<float> spectral_rolloff = internal::nullMin(rolloff);
		return spectral_rolloff;
	}

	static std::vector<float> spectralBandwidth(Matrixf &sp, Vectorf &centroid, Vectorf &fft_freqs)
	{
		// deviation = np.abs(np.subtract.outer(centroid[..., 0, :], freq).swapaxes(-2, -1))
		Matrixf subtract_outer = internal::subtractOuter(centroid, fft_freqs);
		Matrixf deviation = subtract_outer.transpose();
		deviation = deviation.cwiseAbs();

		Matrixf norm_sp = internal::normalize(sp);

		// bw: np.ndarray = np.sum(S * deviation**p, axis=-2, keepdims=True) ** (1.0 / p)
		Matrixf deviation_squared = deviation.array().square();
		Matrixf product = norm_sp.array() * deviation_squared.array();
		Matrixf sum = product.colwise().sum();
		Matrixf bw = sum.array().sqrt();
		Eigen::Map<Vectorf> bandwidth(bw.data(), bw.cols());
		std::vector<float> spectral_bandwidth = internal::convertVectorf(bandwidth);
		return spectral_bandwidth;
	}
};

} // namespace librosa

#endif
