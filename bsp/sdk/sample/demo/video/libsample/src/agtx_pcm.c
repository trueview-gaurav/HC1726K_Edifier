#include "agtx_pcm.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#if defined(MP4_ENABLE) || defined(AUDIO_RECORD_ENABLE)

#define AUDIO_DSP_PROC "/proc/audio_dsp"

static int parseFANRState(const char *line)
{
	int last_val = -1;
	char buf[512];
	strncpy(buf, line, sizeof(buf) - 1);
	buf[sizeof(buf) - 1] = '\0';

	char *token = strtok(buf, " ");
	while (token) {
		// Try parse as base-10 int
		char *endptr = NULL;
		int val = (int)strtol(token, &endptr, 10);
		if (endptr != token) {
			last_val = val;
		}
		token = strtok(NULL, " ");
	}
	return last_val;
}

int checkFANRConverged(FanrState *state, int timeout_ms)
{
	if (!state->initialized) {
		clock_gettime(CLOCK_MONOTONIC, &state->start);
		state->initialized = 1;
	}

	struct timespec now;
	clock_gettime(CLOCK_MONOTONIC, &now);
	long elapsed_ms = (now.tv_sec - state->start.tv_sec) * 1000L + (now.tv_nsec - state->start.tv_nsec) / 1000000L;

	if (elapsed_ms >= timeout_ms) {
		fprintf(stderr, "[FANR] Timeout: FANR not converged in %d ms\n", timeout_ms);
		return 0; // timeout, allow to proceed
	}

	int fd = open(AUDIO_DSP_PROC, O_RDONLY | O_NONBLOCK);
	if (fd < 0) {
		if (errno != ENOENT)
			perror("[FANR] open");
		return -2; // audio_dsp not available yet
	}

	char buf[2048] = { 0 };
	ssize_t len = read(fd, buf, sizeof(buf) - 1);
	close(fd);

	if (len <= 0) {
		fprintf(stderr, "[FANR] Read error or empty\n");
		return -3;
	}

	char *line = strtok(buf, "\n");
	while (line) {
		if (strncmp(line, "FANR", 4) == 0) {
			int last_val = parseFANRState(line);
			if (last_val == 0) {
				printf("[FANR] Converged (state=0). Ready to record.\n");
				return 1;
			} else if (last_val == 1) {
				return -4; // still converging
			} else {
				fprintf(stderr, "[FANR] Unexpected state value: %d\n", last_val);
				return last_val;
			}
		}
		line = strtok(NULL, "\n");
	}

	return -5; // FANR line not found
}

int agtx_pcm_init(snd_pcm_t **pcm_handle, const char *device, snd_pcm_stream_t stream, snd_pcm_format_t format,
                  snd_pcm_uframes_t frame, unsigned int rate, unsigned int channels)
{
	int ret;
	snd_pcm_hw_params_t *params;
	snd_pcm_sw_params_t *swparams;

	/* return error if already initialized */
	ret = snd_pcm_open(pcm_handle, device, stream, SND_PCM_NONBLOCK);
	if (ret < 0) {
		fprintf(stderr, "fail pcm open: %s\n", snd_strerror(ret));
		*pcm_handle = NULL;
		return ret;
	}

	/* configure alsa devicei, including layout, format, channels, sample rate, and periords */
	ret = snd_pcm_hw_params_malloc(&params);
	if (ret != 0) {
		fprintf(stderr, "Failed to Pcm hw param malloc\n");
		return -1;
	}

	ret = snd_pcm_hw_params_any(*pcm_handle, params);
	if (ret != 0) {
		goto handle_error;
	}

	ret = snd_pcm_hw_params_set_access(*pcm_handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
	if (ret != 0) {
		goto handle_error;
	}

	ret = snd_pcm_hw_params_set_format(*pcm_handle, params, format);
	if (ret != 0) {
		goto handle_error;
	}

	ret = snd_pcm_hw_params_set_channels(*pcm_handle, params, channels);
	if (ret != 0) {
		goto handle_error;
	}

	ret = snd_pcm_hw_params_set_rate_near(*pcm_handle, params, &rate, 0);
	if (ret != 0) {
		goto handle_error;
	}

	/* Thit will only follow /etc/asound.conf */
	ret = snd_pcm_hw_params_set_period_size_near(*pcm_handle, params, &frame, 0);
	if (ret != 0) {
		goto handle_error;
	}

	ret = snd_pcm_hw_params(*pcm_handle, params);
	if (ret != 0) {
		goto handle_error;
	}

	snd_pcm_hw_params_free(params);

	snd_pcm_sw_params_alloca(&swparams);
	ret = snd_pcm_sw_params_current(*pcm_handle, swparams);
	if (ret) {
		printf("snd_pcm_sw_params_current %s\n", snd_strerror(ret));
	}

	ret = snd_pcm_sw_params_set_tstamp_mode(*pcm_handle, swparams, SND_PCM_TSTAMP_ENABLE);
	if (ret) {
		printf("set_tstamp_mode %s\n", snd_strerror(ret));
	}

	ret = snd_pcm_sw_params_set_tstamp_type(*pcm_handle, swparams, SND_PCM_TSTAMP_TYPE_MONOTONIC);
	if (ret) {
		printf("set_tstamp_type %s\n", snd_strerror(ret));
	}

	ret = snd_pcm_sw_params(*pcm_handle, swparams);
	if (ret) {
		printf("snd_pcm_sw_params %s\n", snd_strerror(ret));
	}

	return 0;

handle_error:
	snd_pcm_hw_params_free(params);
	perror("configure alsa device failture");
	snd_pcm_close(*pcm_handle);
	*pcm_handle = NULL;
	return ret;
}

int agtx_pcm_deinit(snd_pcm_t *pcm)
{
	int ret = 0;
	if (pcm != NULL) {
		ret = snd_pcm_drop(pcm);
		if (ret < 0) {
			fprintf(stderr, "Failed snd_pcm_drop, %d\n", ret);
			goto err;
		}
		ret = snd_pcm_close(pcm);
		if (ret < 0) {
			fprintf(stderr, "Failed snd_pcm_close, %d\n", ret);
			goto err;
		}

	} else {
		return -EINVAL;
	}

	pcm = NULL;
	return 0;
err:
	return ret;
}

#endif