/* ------------------------------------------------------------------
* Copyright (C) 2014-2025 Augentix Inc.
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

#include "librosa_feature.h"

#include "Eigen/Core"
#include "Eigen/Dense"

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <cstring>

#include "librosa.h"
#include "cd_log.h"
#include "aftr_cd.h"

using namespace std;

typedef Eigen::Matrix<float, 1, Eigen::Dynamic, Eigen::RowMajor> Vectorf;
typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Matrixf;

/**
 * @brief Implement MFCC by C++.
 * @param[in] x         input audio signal
 * @param[in] param     input parameters
 * @return the mfcc mean matrix.
 * @see None.
 */

std::vector<double> LibrosaFeature(std::vector<float> &x, const AFTR_CD_PARAM_S *param)
{
  int sr = param->sample_rate;
  int n_fft = 2048; // 1024, 2048
  int frame_length = 2048;
  int n_hop = 512; // param->m_param.stride * (sr / 1000), 512
  int win_length = n_fft; // param->m_param.window_size * (sr / 1000), default: n_fft
  int win = param->m_param.window_function;
  char window[5] = { 0 };
  bool center = true;
  // const char *pad_mode = "reflect";
  float power = 2.f;
  int n_mel = 128;
  int fmin = 0;
  int fmax = sr / 2.0;
  int n_mfcc = 13;
  bool norm = true;
  int type = 2;
  float roll_percent = 0.90;
  std::vector<double> ret;

  if (win == 0) {
    strncpy(window, "hamm", 5);
  } else if (win == 1) {
    strncpy(window, "hann", 5);
  } else {
    cd_log_warning("Fail to get window function. Use default value.\n");
    strncpy(window, "hann", 5);
  }

  // common used input: _spectrogram, fft_frequencies
  // auto sp_start_time = std::chrono::system_clock::now();
  Matrixf sp = librosa::internal::_spectrogram(x, sr, n_fft, n_hop, win_length, window, center, "constant", 1.f).transpose();
  // auto sp_end_time = std::chrono::system_clock::now();
  // auto sp_duration = std::chrono::duration_cast<std::chrono::milliseconds>(sp_end_time - sp_start_time);

  // auto fft_freqs_start_time = std::chrono::system_clock::now();
  Vectorf fft_freqs = librosa::internal::fft_frequencies(sr, n_fft);
  // auto fft_freqs_end_time = std::chrono::system_clock::now();
  // auto fft_freqs_duration = std::chrono::duration_cast<std::chrono::milliseconds>(fft_freqs_end_time - fft_freqs_start_time);

  // zero_crossing_rate
  // auto zero_crossing_rate_start_time = std::chrono::system_clock::now();
  std::vector<float> zero_crossing_rate = librosa::Feature::zeroCrossingRate(x, frame_length, n_hop, 0);
  double zero_crossing_rate_sum = std::accumulate(zero_crossing_rate.begin(), zero_crossing_rate.end(), 0.0f);
  double zero_crossing_rate_mean = zero_crossing_rate_sum / (double)(zero_crossing_rate.size());
  // auto zero_crossing_rate_end_time = std::chrono::system_clock::now();
  // auto zero_crossing_rate_duration = std::chrono::duration_cast<std::chrono::milliseconds>(zero_crossing_rate_end_time - zero_crossing_rate_start_time);

  // rms
  // auto rms_start_time = std::chrono::system_clock::now();
  std::vector<float> rms = librosa::Feature::rms(x, frame_length, n_hop);
  double rms_sum = std::accumulate(rms.begin(), rms.end(), 0.0f);
  double rms_mean = rms_sum / (double)(rms.size());
  // auto rms_end_time = std::chrono::system_clock::now();
  // auto rms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(rms_end_time - rms_start_time);

  // mfcc
  // auto mfcc_start_time = std::chrono::system_clock::now();
  std::vector<std::vector<float>> mfcc = librosa::Feature::mfcc(x, sr, n_fft, n_hop, win_length, window, center, "constant", power, n_mel, fmin, fmax, n_mfcc, norm, type);
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


#if 0
  std::cout<<"spectrogram total running time is "<< sp_duration.count() << "ms" <<std::endl;
  std::cout<<"fft_freqs total running time is "<< fft_freqs_duration.count() << "ms" <<std::endl;
  std::cout<<"zero_crossing_rate total running time is "<< zero_crossing_rate_duration.count() << "ms" <<std::endl;
  std::cout<<"rms total running time is "<< rms_duration.count() << "ms" <<std::endl;
  std::cout<<"mfcc total running time is "<< mfcc_duration.count() << "ms" <<std::endl;
  std::cout<<"spectral_centroid total running time is "<< spectral_centroid_duration.count() << "ms" <<std::endl;
  std::cout<<"spectral_rolloff total running time is "<< spectral_rolloff_duration.count() << "ms" <<std::endl;
  std::cout<<"spectral_bandwidth total running time is "<< spectral_bandwidth_duration.count() << "ms" <<std::endl;
#endif


  /* print output info */
#if 0
  std::cout << "zcr shape: (" << zero_crossing_rate.size() << ")" << std::endl;
  for (const auto& val : zero_crossing_rate) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::cout << "rms shape: (" << rms.size() << ")" << std::endl;
  for (const auto& val : rms) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::cout << "mfcc shape: (" << mfcc.size() << ", " << mfcc[0].size() << ")" << std::endl;
  for (const auto& row : mfcc) {
    for (const auto& val : row) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "spectral_centroid shape: (" << spectral_centroid.size() << ")" << std::endl;
  for (const auto& val : spectral_centroid) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::cout << "spectral_rolloff shape: (" << spectral_rolloff.size() << ")" << std::endl;
  for (const auto& val : spectral_rolloff) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::cout << "spectral_bandwidth shape: (" << spectral_bandwidth.size() << ")" << std::endl;
  for (const auto& val : spectral_bandwidth) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
#endif


  /* print output mean info */
#if 0
  std::cout << "mean: \n";
  std::cout << "zcr: " << zero_crossing_rate_mean << std::endl;
  std::cout << "rms: " << rms_mean << std::endl;
  std::cout << "mfcc: ";
  for (const auto& val : mfcc_mean) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
  std::cout << "spectral_centroid: " << spectral_centroid_mean << std::endl;
  std::cout << "spectral_rolloff: " << spectral_rolloff_mean << std::endl;
  std::cout << "spectral_bandwidth: " << spectral_bandwidth_mean << std::endl;
#endif
  
  ret.push_back(zero_crossing_rate_mean);
  ret.push_back(rms_mean);
  for (const auto& val: mfcc_mean) {
    ret.push_back(val);
  }
  ret.push_back(spectral_centroid_mean);
  ret.push_back(spectral_rolloff_mean);
  ret.push_back(spectral_bandwidth_mean);
  return ret;
}
