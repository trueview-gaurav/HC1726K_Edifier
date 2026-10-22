#ifndef LIBROSA_FEATURE_H_
#define LIBROSA_FEATURE_H_

#include <iostream>
#include <vector>

#include "aftr_cd.h"

using namespace std;

/**
 * @brief Implement MFCC by C++.
 * @param[in] x         input audio signal
 * @param[in] sr        sample rate of 'x'
 * @param[in] win       window function. currently only supports 'hann'
 * @return the mfcc matrix.
 * @see None.
 */
std::vector<double> LibrosaFeature(std::vector<float> &x, const AFTR_CD_PARAM_S *param);

#endif /* LIBROSA_FEATURE_H_ */