#ifndef AGTX_PCM_H_
#define AGTX_PCM_H_

#if defined(MP4_ENABLE) || defined(AUDIO_RECORD_ENABLE)

#include <alsa/asoundlib.h>
#include <alsa/hwdep.h>
#include <alsa/error.h>
#include <pcm_interfaces.h>

typedef struct {
	snd_pcm_t *capture;
	char *buf;
	int buf_len;
	int frames;
	int bytes_per_sample;
	int channel;
	int rate;
	int timestamp_enable;
} AudioStreamInfo;

typedef struct {
	struct timespec start;
	int initialized;
} FanrState;

int checkFANRConverged(FanrState *state, int timeout_ms);
int agtx_pcm_init(snd_pcm_t **pcm_handle, const char *device, snd_pcm_stream_t stream, snd_pcm_format_t format,
                  snd_pcm_uframes_t frame, unsigned int rate, unsigned int channels);
int agtx_pcm_deinit(snd_pcm_t *pcm);
#endif

#endif