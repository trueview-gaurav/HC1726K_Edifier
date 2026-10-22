#ifndef MP4_MUXER_H_
#define MP4_MUXER_H_

#include <stdint.h>
#include <stddef.h>

int muxAudioVideoToMp4(const char *h264_file, int fps, const int16_t *pcm_buf, int pcm_samples, int sample_rate,
                       uint8_t *sps, size_t sps_len, uint8_t *pps, size_t pps_len, const char *output_file);

#endif
