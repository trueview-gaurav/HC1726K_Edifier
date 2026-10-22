#include "sample_publisher.h"

#include <asm-generic/errno-base.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#include "frame_dumper.h"
#include "synced_frame_dumper.h"
#include "mp4_dumper.h"
#include "audio_dumper.h"
#include "udp_cast.h"
#include "agtx_pcm.h"
#include "agtx_cpu_time.h"
#include <unistd.h>

static pthread_t g_bsb_tid[MPI_MAX_ENC_CHN_NUM] = { 0 };
static char g_bsb_run[MPI_MAX_ENC_CHN_NUM] = { 0 };
static pthread_t g_asb_tid = 0;
static char g_asb_run = 0;

#define AE_STARTUP_SKIP_MAX 50
typedef struct ae_startup_skip_ctrl  {

	/* Enable or disable AE startup skip */
	bool enable;

	/* Indicates whether startup skip has completed */
	bool skip_done;

	/* Number of startup outputs to skip */
	uint8_t skip_count;

	/* Current skipped output count */
	uint8_t current_count;

} AeStartupSkipCtrl;
static AeStartupSkipCtrl g_ae_skip_ctrl;
static bool g_ae_skip_initialized  = false;


typedef struct publisher_info {
	MPI_ECHN encoder_channel;
	MPI_BCHN stream_channel;
	BitStreamSubscriber *subscriber;
	bool should_request_idr;
} PublisherInfo;

#if defined(MP4_ENABLE) || defined(AUDIO_RECORD_ENABLE)
typedef struct audio_publisher_info {
	AudioStreamInfo audio;
	BitStreamSubscriber *subscriber;
} AudioPublisherInfo;
#endif // AUDIO_RECORD_ENABLE
 
#ifdef AUDIO_RECORD_ENABLE
static const char *g_device[] = { "default", "hw:0,0" }; /* sound device */
#endif // AUDIO_RECORD_ENABLE

static BitStreamSubscriber *newNullSubscriber(void);
static BitStreamSubscriber *buildTeeSubscriber(BitStreamSubscriber *subscriber1,
                                               BitStreamSubscriber *subscriber2);

static uint64_t timespec2Msec(const struct timespec *ts)
{
	return (uint64_t)(ts->tv_sec) * 1000ULL + ts->tv_nsec / 1000000ULL;
}


/*
 * Drop initial encoder outputs during AE convergence stage.
 *
 * NOTE:
 * This mechanism does not check frame type.
 * All encoder outputs may be skipped, including:
 * SPS / PPS / SEI / I / P frames.
 *
 * The purpose is to avoid recording unstable frames
 * during AE convergence at stream startup.
 */
static bool ae_drop_initial_bitstream(MPI_STREAM_PARAMS_V2_S *params,
	MPI_BCHN stream_channel)
{
	/*
	* AE skip already completed.
	* Allow normal frame delivery.
	*/
	if (g_ae_skip_ctrl.skip_done) {
		return false;
	}

	/*
	* AE skip feature disabled.
	*/
	if (!g_ae_skip_ctrl.enable) {
		return false;
	}

	if (g_ae_skip_ctrl.skip_count == 0) {
		return false;
	}

	g_ae_skip_ctrl.current_count++;

	/*
	* AE convergence completed.
	* Start normal frame delivery.
	*/
	if (g_ae_skip_ctrl.current_count > g_ae_skip_ctrl.skip_count) {
		g_ae_skip_ctrl.skip_done = true;
		fprintf(stderr, "[AE SKIP] completed\n");
		return false;
	}

	fprintf(stderr, "[AE SKIP] drop frame %u/%u\n", g_ae_skip_ctrl.current_count, g_ae_skip_ctrl.skip_count);

	/*
	* Drop encoder outputs during AE convergence stage.
	*/
	MPI_releaseBitStreamV2(stream_channel, params);

	return true;
}

void init_ae_startup_skip_ctrl(const CONF_BITSTREAM_PARAM_S *conf)
{
	g_ae_skip_ctrl.enable = conf->record.enable;
	g_ae_skip_ctrl.skip_done = false;
	g_ae_skip_ctrl.skip_count = 0;

	if (conf->record.startup_skip_count >= AE_STARTUP_SKIP_MAX)
		g_ae_skip_ctrl.skip_count = AE_STARTUP_SKIP_MAX;
	else
		g_ae_skip_ctrl.skip_count = conf->record.startup_skip_count;

	g_ae_skip_ctrl.current_count = 0;

	g_ae_skip_initialized = true;
}


/**
 * @brief Thread routine to get bit stream data to publish/delivery.
 * @details The function will create channel to get bit stream at first, then
 * call MPIs to get the parameters of bit stream. With these parameter, we can
 * read bit stream data at the address of stream buffer and deliver to subscriber.
 * After that, the bit stream buffer could be released.
 */
static void *SAMPLE_runStreamPublisher(void *p)
{
	PublisherInfo *info = p;
	MPI_BCHN stream_channel = info->stream_channel;

	uint32_t frame_count = 0;
	uint32_t total_bytes = 0;
	bool has_seen_first_frame = false;
	MPI_STREAM_PARAMS_V2_S params;
	memset(&params, 0, sizeof(params));
	BitStreamSubscriber *subscriber = info->subscriber;
	if (subscriber->deliveryWillStart(subscriber->context)) {
		printf("Stream subscriber is NOT ready! Abort stream delivery.\n");
		goto exit_bit_stream_channel;
	}

	time_t last_time_mark = time(NULL);
	while (g_bsb_run[stream_channel.chn]) {
		int ret = MPI_getBitStreamV2(stream_channel, &params, 1200);
		time_t now = time(NULL);
		if (ret == MPI_SUCCESS) {
			if (!has_seen_first_frame) {
				if (info->should_request_idr && params.seg[0].type != MPI_FRAME_TYPE_SPS) {
					// Request I-frame first
					if (MPI_ENC_requestIdr(info->encoder_channel) != MPI_SUCCESS) {
						printf("Failed to MPI_ENC_requestIdr.\n");
						// do nothing
					}
					MPI_releaseBitStreamV2(stream_channel, &params);
					continue;
				}

				/*
				* Drop initial bitstream outputs while AE is converging.
				*/
				if (ae_drop_initial_bitstream(&params, stream_channel))
					continue;

				has_seen_first_frame = true;

				if (stream_channel.chn == 0) {
					// Info message for QA to test fast boot and get first frame.
					fprintf(stderr, "[%s][bchn.chn %d][%u] Get first frame success !!!\n", __func__,
					        stream_channel.chn, get_cpu_time());
					fflush(stderr);
				}
			}
			for (UINT32 i = 0; i < params.seg_cnt; ++i) {
				total_bytes += params.seg[i].size;
			}
			if (params.seg->type >= MPI_FRAME_TYPE_I) {
				++frame_count;
				if (now != last_time_mark) {
					printf("stream %d, fps %u, bps %u Kbps\n", stream_channel.chn, frame_count,
					       (total_bytes + 64) >> 7);
					last_time_mark = now;
					frame_count = 0;
					total_bytes = 0;
				}
			}
			if (subscriber->receiveFrame(subscriber->context, (void *)&params, total_bytes,
			                             timespec2Msec(&params.timestamp))) {
				g_bsb_run[stream_channel.chn] = 0;
			}
			MPI_releaseBitStreamV2(stream_channel, &params);
		} else if (ret == -ETIMEDOUT || ret == -EAGAIN) {
			/* Request frame again if timeout occurred */
			continue;
		} else if (ret == -ENODATA) {
			/**
			 * Wait encoder run again.
			 * In some scenarios, you might temporary stop encoder to modify some
			 * static configurations (Ex. OSD, codec type), process must not exit
			 * in these cases.
			 */
			frame_count = 0;
			total_bytes = 0;
			continue;
		} else {
			printf("FAILED to get parameters of stream %d.\n", stream_channel.chn);
			g_bsb_run[stream_channel.chn] = 0;
		}
	}
	subscriber->deliveryDidEnd(subscriber->context, timespec2Msec(&params.timestamp));

exit_bit_stream_channel:
	MPI_destroyBitStreamChn(stream_channel);
	free(info->subscriber);
	free(info);
	return NULL;
}

/**
 * @brief Start a thread to publish bit stream data to subscriber.
 * @param[in] encoder_channel  Target encoder index
 * @param[in] conf pointer to streaming configuration
 * @return The execution result.
 * @retval 0         success
 * @retval others    unexpected failure
 * @see SAMPLE_shutdownStreamPublisher()
 */
int SAMPLE_startStreamPublisher(MPI_ECHN encoder_channel, const CONF_BITSTREAM_PARAM_S *conf, INT32 reservation_level,
                                INT32 recycle_level, UINT8 sync_with_audio)
{
	MPI_VENC_ATTR_S venc_attr;
	MPI_ENC_getVencAttr(encoder_channel, &venc_attr);

	PublisherInfo *info = malloc(sizeof(*info));
	info->subscriber = NULL;
	info->encoder_channel = encoder_channel;
	info->should_request_idr = (venc_attr.type == MPI_VENC_TYPE_H264 || venc_attr.type == MPI_VENC_TYPE_H265);
	int ret = 0;

	printf("%s record %d sync %d\n", __func__, conf->record.enable, sync_with_audio);

	if (!g_ae_skip_initialized)
		init_ae_startup_skip_ctrl(conf);

	if (conf->record.enable) {
		if (strstr(conf->record.fname, ".mp4") != NULL) {
#ifdef MP4_ENABLE
			MPI_ENC_CHN_ATTR_S enc_attr;
			MPI_ENC_getChnAttr(encoder_channel, &enc_attr);

			if (venc_attr.type != MPI_VENC_TYPE_H264) {
				printf("MP4 dumper only support h264 format, venc type: %d\n", venc_attr.type);
				ret = -EINVAL;
				goto exit;
			}

			info->subscriber = buildTeeSubscriber(
			        info->subscriber,
			        newMp4Dumper(encoder_channel, conf->record.fname, abs(conf->record.frame_num),
			                     conf->record.frame_num < 0, reservation_level, recycle_level,
			                     conf->record.max_dumped_files, enc_attr.res.width, enc_attr.res.height,
			                     venc_attr.h264.rc.frm_rate_o));
#endif
		} else if (sync_with_audio) {
			printf("%s create Synced dumper\n", __func__);
			info->subscriber = buildTeeSubscriber(
			        info->subscriber,
			        newSyncedFrameDumper(encoder_channel, conf->record.fname, abs(conf->record.frame_num),
			                             conf->record.frame_num < 0, reservation_level, recycle_level,
			                             conf->record.max_dumped_files));
		} else {
			info->subscriber = buildTeeSubscriber(
			        info->subscriber,
			        newFrameDumper(encoder_channel, conf->record.fname, abs(conf->record.frame_num),
			                       conf->record.frame_num < 0, reservation_level, recycle_level,
			                       conf->record.max_dumped_files, conf->record.file_mode));
		}
	}
	if (conf->stream.enable) {
		info->subscriber = buildTeeSubscriber(
		        newUdpLiveStream(conf->stream.client_ip, conf->stream.client_port), info->subscriber);
	}

	/* Create BCHN outside the thread to avoid race conditions */
	info->stream_channel = MPI_createBitStreamChn(info->encoder_channel);
	if (!VALID_MPI_ENC_BCHN(info->stream_channel)) {
		printf("FAILED to create bit-stream channel.\n");
		ret = -EINVAL;
		goto exit;
	}

	/* We want publisher always doing its job, so attach a NullSubscriber (it never unsubscribe). */
	info->subscriber = buildTeeSubscriber(info->subscriber, newNullSubscriber());
	g_bsb_run[encoder_channel.chn] = 1;
	ret = pthread_create(&g_bsb_tid[encoder_channel.chn], NULL, SAMPLE_runStreamPublisher, info);
	if (ret) {
		printf("FAILED to create thread to get stream data of channel %d! err: %d\n", encoder_channel.chn, ret);
		g_bsb_run[encoder_channel.chn] = 0;
		goto exit_bit_stream_channel;
	}

	return 0;

exit_bit_stream_channel:
	MPI_destroyBitStreamChn(info->stream_channel);
	free(info->subscriber);
exit:
	free(info);
	return ret;
}

/**
 * @brief Stop publisher thread(thus stop consuming bit stream data).
 * @see SAMPLE_startStreamPublisher()
 */
void SAMPLE_shutdownStreamPublisher(MPI_ECHN idx)
{
	g_bsb_run[MPI_GET_ENC_CHN(idx)] = 0;
	pthread_join(g_bsb_tid[MPI_GET_ENC_CHN(idx)], NULL);
}

bool SAMPLE_hasAnyPublisherThreadActive(void)
{
	for (int i = 0; i < MPI_MAX_ENC_CHN_NUM; ++i) {
		if (g_bsb_run[i]) {
			return true;
		}
	}
	return false;
}

void SAMPLE_signalAllStreamThreadToShutdown(void)
{
	for (int i = 0; i < MPI_MAX_ENC_CHN_NUM; ++i) {
		g_bsb_run[i] = 0;
	}
}

#ifdef AUDIO_RECORD_ENABLE
static int estimatePcmBufferEndTimeMs(snd_pcm_t *handler, unsigned int sample_rate, snd_pcm_uframes_t frames_read,
                                      uint64_t *end_ts_ms)
{
	snd_pcm_uframes_t avail_after;
	struct timespec avail_ts;
	int ret = 0;

	ret = snd_pcm_htimestamp(handler, &avail_after, &avail_ts);
	if (ret < 0) {
		fprintf(stderr, "Failed to get pcm buffer timestamp: %s\n", snd_strerror(ret));
		return -1; /** htimestamp failed */
	}

	/** Total time offset in seconds */
	double frame_duration_sec = 1.0 / (double)sample_rate;
	double offset_sec = (avail_after + frames_read) * frame_duration_sec;

	/** Convert avail_ts to seconds */
	double base_sec = avail_ts.tv_sec + avail_ts.tv_nsec / 1e9;

	/** Back-calculate buffer end time in seconds */
	double end_sec = base_sec - offset_sec;
	if (end_sec < 0)
		end_sec = 0;

	/** Convert to milliseconds */
	*end_ts_ms = (uint64_t)(end_sec * 1000.0);

	return 0;
}
#endif // AUDIO_RECORD_ENABLE

#ifdef AUDIO_RECORD_ENABLE

static void *SAMPLE_runAudioStreamPublisher(void *p)
{
	AudioPublisherInfo *info = p;
	BitStreamSubscriber *subscriber = info->subscriber;
	if (subscriber->deliveryWillStart(subscriber->context)) {
		fprintf(stderr, "Audio subscriber is NOT ready! Abort stream delivery.\n");
		goto exit_pcm;
	}

	int ret = 0;
	uint64_t timestamp = 0;

	while (g_asb_run) {
		ret = agtx_pcm_init(&info->audio.capture, g_device[0], SND_PCM_STREAM_CAPTURE, SND_PCM_FORMAT_S16_LE,
		                    info->audio.frames, info->audio.rate, info->audio.channel);

		if (ret == 0) {
			break;
		} else if (ret == -EBUSY || ret == -ENODEV || ret == -ENOENT) {
			usleep(20000);
			continue;
		} else {
			fprintf(stderr, "failed to init audio, ret; %d\n", ret);
			goto exit_pcm;
		}
	}

	while (g_asb_run) {
		ret = snd_pcm_readi((snd_pcm_t *)info->audio.capture, info->audio.buf, info->audio.frames);
		if (ret == -EPIPE) {
			snd_pcm_prepare((snd_pcm_t *)info->audio.capture);
			//fprintf(stderr, "snd -EPIPE\n");
			continue;
		} else if (ret == -EAGAIN) {
			//fprintf(stderr, "snd -EAGAIN\n");
			/* Sleep 1/100 period_time to get early audio data faster */
			usleep((10000 / info->audio.rate) * info->audio.frames);
			continue;
		}

		if (estimatePcmBufferEndTimeMs((snd_pcm_t *)info->audio.capture, info->audio.rate, ret, &timestamp) <
		    0) {
			timestamp = 0;
		}

		if (subscriber->receiveFrame(subscriber->context, (void *)info->audio.buf, ret, timestamp)) {
			g_asb_run = 0;
		}

		/* Sleep 1/100 period_time to get early audio data faster */
		usleep((10000 / info->audio.rate) * info->audio.frames);
	}

	subscriber->deliveryDidEnd(subscriber->context, timestamp);

exit_pcm:
	agtx_pcm_deinit(info->audio.capture);
	free(info->audio.buf);
	free(info->subscriber);
	free(info);
	return NULL;
}
#endif // AUDIO_RECORD_ENABLE

int SAMPLE_startAudioPublisher(const CONF_AUDIO_PARAM_S *conf, INT32 reservation_level, INT32 recycle_level)
{
	int ret = 0;
#ifdef AUDIO_RECORD_ENABLE
	AudioPublisherInfo *info = malloc(sizeof(*info));
	info->subscriber = NULL;
	info->audio.rate = conf->record.audio_sample_rate;
	info->audio.capture = NULL;
	info->audio.buf_len = conf->record.audio_frame_size * 2 /*byte per sample*/ * 1 /*MONO only*/;
	info->audio.buf = malloc(info->audio.buf_len);
	info->audio.channel = 1; /** S16LE only */
	info->audio.bytes_per_sample = 2; /** S16LE only */
	info->audio.frames = conf->record.audio_frame_size;

	if (conf->enable) {
		info->subscriber = buildTeeSubscriber(
		        info->subscriber, newAudioDumper(conf->record.fname, conf->record.audio_max_frame_count,
		                                         conf->record.max_dumped_files > 0, reservation_level,
		                                         recycle_level, abs(conf->record.max_dumped_files)));
	}

	g_asb_run = 1;
	pthread_create(&g_asb_tid, NULL, SAMPLE_runAudioStreamPublisher, info);
	if (ret) {
		printf("FAILED to create thread to get audio data  err: %d\n", ret);
		g_asb_run = 0;
		goto exit_audio;
	}

	return 0;

exit_audio:
	free(info->subscriber);
	free(info->audio.buf);
	free(info);
	return ret;
#else
	(void)(conf);
	(void)(reservation_level);
	(void)(recycle_level);
	return ret;
#endif
}

void SAMPLE_shutdownAudioPublisher()
{
	if (g_asb_run != 0) {
		g_asb_run = 0;
		pthread_join(g_asb_tid, NULL);
	}
}

void SAMPLE_signalAllAudioThreadToShutdown(void)
{
	SAMPLE_shutdownAudioPublisher();
}

bool SAMPLE_hasAnyAudioPublisherThreadActive(void)
{
	if (g_asb_run) {
		return true;
	}

	return false;
}

static bool NULLSUBSCRIBER_deliveryWillStart(__attribute__((unused)) void *context)
{
	return false;
}

static bool NULLSUBSCRIBER_receiveFrame(__attribute__((unused)) void *context,
                                        __attribute__((unused)) const void *frame_data,
                                        __attribute__((unused)) uint32_t data_len,
                                        __attribute__((unused)) uint64_t timestamp)
{
	return false;
}

static void NULLSUBSCRIBER_deliveryDidEnd(__attribute__((unused)) void *context,
                                          __attribute__((unused)) uint64_t timestamp)
{
}

static BitStreamSubscriber *newNullSubscriber(void)
{
	BitStreamSubscriber *subscriber = malloc(sizeof(*subscriber));
	subscriber->context = NULL;
	subscriber->deliveryWillStart = NULLSUBSCRIBER_deliveryWillStart;
	subscriber->receiveFrame = NULLSUBSCRIBER_receiveFrame;
	subscriber->deliveryDidEnd = NULLSUBSCRIBER_deliveryDidEnd;
	return subscriber;
}

typedef struct subscriber_tee {
	BitStreamSubscriber base_part;
	BitStreamSubscriber *left_branch;
	BitStreamSubscriber *right_branch;
} SubscriberTee;

static bool SUBSCRIBERTEE_deliveryWillStart(void *context)
{
	SubscriberTee *T = context;
	bool left_result = T->left_branch->deliveryWillStart(T->left_branch->context);
	bool right_result = T->right_branch->deliveryWillStart(T->right_branch->context);
	if (left_result) {
		free(T->left_branch);
		T->left_branch = NULL;
	}
	if (right_result) {
		free(T->right_branch);
		T->right_branch = NULL;
	}
	return left_result && right_result;
}

static bool SUBSCRIBERTEE_receiveFrame(void *context, const void *frame_data, uint32_t data_len, uint64_t timestamp)
{
	const MPI_STREAM_PARAMS_V2_S *frame = (MPI_STREAM_PARAMS_V2_S *)frame_data;

	SubscriberTee *T = context;
	BitStreamSubscriber *left_branch = T->left_branch;
	bool left_result = true;
	if (left_branch != NULL) {
		left_result = left_branch->receiveFrame(left_branch->context, frame, data_len, timestamp);
		if (left_result) {
			T->left_branch = NULL;
			left_branch->deliveryDidEnd(left_branch->context, timestamp);
			free(left_branch);
		}
	}

	BitStreamSubscriber *right_branch = T->right_branch;
	bool right_result = true;
	if (right_branch != NULL) {
		right_result = right_branch->receiveFrame(right_branch->context, frame, data_len, timestamp);
		if (right_result) {
			T->right_branch = NULL;
			right_branch->deliveryDidEnd(right_branch->context, timestamp);
			free(right_branch);
		}
	}
	return left_result && right_result;
}

static void SUBSCRIBERTEE_deliveryDidEnd(void *context, uint64_t timestamp)
{
	SubscriberTee *T = context;
	if (T->left_branch != NULL) {
		T->left_branch->deliveryDidEnd(T->left_branch->context, timestamp);
		free(T->left_branch);
		T->left_branch = NULL;
	}
	if (T->right_branch != NULL) {
		T->right_branch->deliveryDidEnd(T->right_branch->context, timestamp);
		free(T->right_branch);
		T->right_branch = NULL;
	}
}

static BitStreamSubscriber *buildTeeSubscriber(BitStreamSubscriber *subscriber1,
                                               BitStreamSubscriber *subscriber2)
{
	if (subscriber1 == NULL) {
		return subscriber2;
	} else if (subscriber2 == NULL) {
		return subscriber1;
	} else {
		SubscriberTee *tee = malloc(sizeof(*tee));
		tee->left_branch = subscriber1;
		tee->right_branch = subscriber2;
		BitStreamSubscriber *base = &tee->base_part;
		base->context = tee;
		base->deliveryWillStart = SUBSCRIBERTEE_deliveryWillStart;
		base->receiveFrame = SUBSCRIBERTEE_receiveFrame;
		base->deliveryDidEnd = SUBSCRIBERTEE_deliveryDidEnd;

		return base;
	}
}
