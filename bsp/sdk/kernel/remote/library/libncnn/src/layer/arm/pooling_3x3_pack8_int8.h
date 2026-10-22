// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

static void pooling3x3s2_max_pack8_int8_neon(const Mat& bottom_blob, Mat& top_blob, const Option& opt)
{
    int w = bottom_blob.w;
    int inch = bottom_blob.c;

    int outw = top_blob.w;
    int outh = top_blob.h;

    const int tailstep = (w - 2 * outw + w) * 8;

    #pragma omp parallel for num_threads(opt.num_threads)
    for (int q = 0; q < inch; q++)
    {
        const Mat img0 = bottom_blob.channel(q);
        signed char* outptr = top_blob.channel(q);

        const signed char* r0 = (const signed char*)img0.row(0);
        const signed char* r1 = (const signed char*)img0.row(1);
        const signed char* r2 = (const signed char*)img0.row(2);

        for (int i = 0; i < outh; i++)
        {
            int j = 0;

//            for (; j + 3 < outw; j += 4)
//            {
//
//            }
//            for (; j + 1 < outw; j += 2)
//            {
//
//            }
            for (; j < outw; j++)
            {
                int8x8_t _r00 = vld1_s8(r0);
                int8x8_t _r01 = vld1_s8(r0 + 8);
                int8x8_t _r02 = vld1_s8(r0 + 16);
                int8x8_t _r10 = vld1_s8(r1);
                int8x8_t _r11 = vld1_s8(r1 + 8);
                int8x8_t _r12 = vld1_s8(r1 + 16);
                int8x8_t _r20 = vld1_s8(r2);
                int8x8_t _r21 = vld1_s8(r2 + 8);
                int8x8_t _r22 = vld1_s8(r2 + 16);

                int8x8_t _max0 = vmax_s8(vmax_s8(_r00, _r01), _r02);
                int8x8_t _max1 = vmax_s8(vmax_s8(_r10, _r11), _r12);
                int8x8_t _max2 = vmax_s8(vmax_s8(_r20, _r21), _r22);

                int8x8_t _max = vmax_s8(vmax_s8(_max0, _max1), _max2);

                vst1_s8(outptr, _max);

                r0 += 16;
                r1 += 16;
                r2 += 16;
                outptr += 8;
            }

            r0 += tailstep;
            r1 += tailstep;
            r2 += tailstep;
        }
    }
}
