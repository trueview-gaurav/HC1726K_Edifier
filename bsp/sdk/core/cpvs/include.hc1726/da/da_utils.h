/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_DA_UTILS_H_
#define SAPPORO_DA_UTILS_H_

#include "da_define.h"

#define round_up_div(value, base) ((value) + (base - 1)) / (base)
#define round_up_base(value, base) (((value) + (base - 1)) / (base)) * (base)

// #define ceil(x, y) (((x) + (y)-1) / (y) * (y))
// #define ceil_div(x, y) (((x) + (y)-1) / (y))

#endif /* SAPPORO_DA_UTILS_H_ */
