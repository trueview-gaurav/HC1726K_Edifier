#include "mp4_muxer.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#include <lame.h>
#include <mp4v2/mp4v2.h>

struct mp4_mux_context {
	MP4FileHandle mp4;
	MP4TrackId video_track;
	MP4TrackId audio_track;
	uint32_t video_time_scale;
	uint32_t video_frame_duration;
	uint32_t audio_time_scale;
	uint32_t audio_frame_size;
	int fps;
	int sample_rate;
};

static int writeMp4AudioFrame(struct mp4_mux_context *ctx, const uint8_t *frame, size_t size)
{
	return MP4WriteSample(ctx->mp4, ctx->audio_track, frame, size, ctx->audio_frame_size, 0, 1) ? 0 : -1;
}

static int writeMp4VideoFrame(struct mp4_mux_context *ctx, const uint8_t *frame, size_t size, bool is_keyframe)
{
	return MP4WriteSample(ctx->mp4, ctx->video_track, frame, size, ctx->video_frame_duration, 0, is_keyframe) ? 0 :
	                                                                                                            -1;
}

#define START_CODE_LEN 4
static bool isStartCode(const uint8_t *buf)
{
	return buf[0] == 0x00 && buf[1] == 0x00 && buf[2] == 0x00 && buf[3] == 0x01;
}

static int findNextStartCode(FILE *fp, long *next_start_offset)
{
	uint8_t buf[START_CODE_LEN];
	while (fread(buf, 1, START_CODE_LEN, fp) == START_CODE_LEN) {
		if (isStartCode(buf)) {
			*next_start_offset = ftell(fp) - START_CODE_LEN;
			return 1;
		}
		fseek(fp, -3, SEEK_CUR); // Slide window
	}
	fseek(fp, 0, SEEK_END);
	*next_start_offset = ftell(fp);
	return 0;
}

static int parseH264AccessUnit(FILE *fp, uint8_t **out_buf, size_t *out_size, bool *is_keyframe)
{
	if (!fp || !out_buf || !out_size || !is_keyframe)
		return -1;

	*out_buf = NULL;
	*out_size = 0;
	*is_keyframe = false;

	uint8_t *sps = NULL, *pps = NULL, *idr = NULL;
	size_t sps_len = 0, pps_len = 0, idr_len = 0;

	uint8_t *pframe = NULL;
	size_t pframe_len = 0;

	uint8_t start_code[4];
	long next_nalu_offset = 0;

	while (fread(start_code, 1, 4, fp) == 4) {
		if (!isStartCode(start_code))
			return -1;
		long nalu_start = ftell(fp);

		if (findNextStartCode(fp, &next_nalu_offset) < 0)
			return -1;

		size_t nalu_size = next_nalu_offset - nalu_start;
		if (nalu_size <= 0)
			break;

		fseek(fp, nalu_start, SEEK_SET);
		uint8_t nal_header;
		fread(&nal_header, 1, 1, fp);
		uint8_t nal_type = nal_header & 0x1F;

		// read completed NALU + AVCC prefix
		uint8_t *nalu = malloc(nalu_size + 4);
		if (!nalu)
			return -1;
		uint32_t len_be = htonl(nalu_size);
		memcpy(nalu, &len_be, 4);
		fseek(fp, nalu_start, SEEK_SET);
		fread(nalu + 4, 1, nalu_size, fp);

		if (nal_type == 7) { // SPS
			if (sps)
				free(sps);
			sps = nalu;
			sps_len = nalu_size + 4;
		} else if (nal_type == 8) { // PPS
			if (pps)
				free(pps);
			pps = nalu;
			pps_len = nalu_size + 4;
		} else if (nal_type == 5) { // IDR
			if (idr)
				free(idr);
			idr = nalu;
			idr_len = nalu_size + 4;
			*is_keyframe = true;
			break; // get Access Unit（SPS+PPS+IDR）
		} else if (nal_type == 1) { // P-frame
			if (pframe)
				free(pframe);
			pframe = nalu;
			pframe_len = nalu_size + 4;
			break; // uni frame
		} else {
			free(nalu); // SEI / AUD ignored
		}

		fseek(fp, next_nalu_offset, SEEK_SET);
	}

	// combine same time frames
	size_t total = sps_len + pps_len + idr_len + pframe_len;
	if (total == 0)
		return 0;

	*out_buf = malloc(total);
	if (!*out_buf) {
		free(sps);
		free(pps);
		free(idr);
		free(pframe);
		return -1;
	}

	size_t offset = 0;
	if (idr_len) {
		if (sps) {
			memcpy(*out_buf + offset, sps, sps_len);
			offset += sps_len;
			free(sps);
		}
		if (pps) {
			memcpy(*out_buf + offset, pps, pps_len);
			offset += pps_len;
			free(pps);
		}
		memcpy(*out_buf + offset, idr, idr_len);
		offset += idr_len;
		free(idr);
	} else if (pframe_len) {
		memcpy(*out_buf + offset, pframe, pframe_len);
		offset += pframe_len;
		free(pframe);
	}

	*out_size = offset;
	return 1;
}

static int getBit(const uint8_t *data, int bit_offset)
{
	return (data[bit_offset / 8] >> (7 - (bit_offset % 8))) & 0x01;
}

static uint32_t readUE(const uint8_t *data, int *bit_offset)
{
	int zero_bits = 0;
	while (getBit(data, *bit_offset) == 0) {
		zero_bits++;
		(*bit_offset)++;
	}
	(*bit_offset)++;
	uint32_t result = 1;
	for (int i = 0; i < zero_bits; i++) {
		result <<= 1;
		result |= getBit(data, *bit_offset);
		(*bit_offset)++;
	}
	return result - 1;
}

static int getResolutionFromSps(const uint8_t *sps, size_t sps_len, int *width, int *height)
{
	if (!sps || sps_len < 7 || !width || !height)
		return -EINVAL;

	// Skip NAL header (1 byte)
	const uint8_t *rbsp = sps + 1;
	size_t rbsp_len = sps_len - 1;
	(void)(rbsp_len);

	int bit_offset = 8 * 3; /** Skip profile_idc, constraint flags, and level_idc. */
	readUE(rbsp, &bit_offset); /** Parse seq_parameter_set_id. */
	uint32_t log2_max_frame_num = readUE(rbsp, &bit_offset); // usused
	(void)(log2_max_frame_num);
	uint32_t pic_order_cnt_type = readUE(rbsp, &bit_offset);
	if (pic_order_cnt_type == 0) {
		readUE(rbsp, &bit_offset); // log2_max_pic_order_cnt_lsb_minus4
	} else if (pic_order_cnt_type == 1) {
		bit_offset += 1; // delta_pic_order_always_zero_flag
		readUE(rbsp, &bit_offset); // offset_for_non_ref_pic
		readUE(rbsp, &bit_offset); // offset_for_top_to_bottom_field
		uint32_t num_ref_frames_in_pic_order_cnt_cycle = readUE(rbsp, &bit_offset);
		for (uint32_t i = 0; i < num_ref_frames_in_pic_order_cnt_cycle; i++)
			readUE(rbsp, &bit_offset);
	}
	readUE(rbsp, &bit_offset);
	bit_offset++; // gaps_in_frame_num_value_allowed_flag
	uint32_t pic_width_in_mbs_minus1 = readUE(rbsp, &bit_offset);
	uint32_t pic_height_in_map_units_minus1 = readUE(rbsp, &bit_offset);
	int frame_mbs_only_flag = getBit(rbsp, bit_offset);
	bit_offset++;
	if (!frame_mbs_only_flag) {
		bit_offset++; /** Parse gaps_in_frame_num_value_allowed_flag. */
	}
	bit_offset++; /** Parse direct_8x8_inference_flag. */

	int frame_crop_left = 0, frame_crop_right = 0, frame_crop_top = 0, frame_crop_bottom = 0;
	int frame_cropping_flag = getBit(rbsp, bit_offset);
	bit_offset++;
	if (frame_cropping_flag) {
		frame_crop_left = readUE(rbsp, &bit_offset);
		frame_crop_right = readUE(rbsp, &bit_offset);
		frame_crop_top = readUE(rbsp, &bit_offset);
		frame_crop_bottom = readUE(rbsp, &bit_offset);
	}

	int crop_unit_x = 1;
	int crop_unit_y = 2 - frame_mbs_only_flag;

	*width = ((pic_width_in_mbs_minus1 + 1) * 16) - (frame_crop_left + frame_crop_right) * crop_unit_x;
	*height = ((pic_height_in_map_units_minus1 + 1) * 16 * (2 - frame_mbs_only_flag)) -
	          (frame_crop_top + frame_crop_bottom) * crop_unit_y;

	return 0;
}

static int extractSerialFromFilename(const char *filename)
{
	/** Find the last dot (.) in the filename */
	const char *last_dot = strrchr(filename, '.');
	if (!last_dot || *(last_dot + 1) == '\0')
		return -1;

	/** Validate that the suffix after the last dot is all digits */
	const char *p = last_dot + 1;
	while (*p) {
		if (*p < '0' || *p > '9')
			return -1;
		p++;
	}

	/** Convert the numeric suffix to integer */
	int serial = atoi(last_dot + 1);
	return serial;
}

static int countH264Frames(FILE *fp)
{
	int count = 0;
	uint8_t *tmp_frame = NULL;
	size_t tmp_size = 0;
	bool tmp_key = false;

	while (parseH264AccessUnit(fp, &tmp_frame, &tmp_size, &tmp_key) > 0) {
		count++;
		free(tmp_frame);
	}
	rewind(fp);
	return count;
}

/**
 * @brief Muxes raw H.264 video and PCM audio into an MP4 container.
 *
 * This function performs audio-video muxing using libmp4v2. It handles:
 * - Parsing SPS to get video resolution
 * - Creating H.264 and AAC tracks in MP4
 * - Adjusting audio based on timestamp difference
 * - Encoding PCM into AAC frames using FDK-AAC
 * - Writing interleaved video and audio frames into the MP4 output
 *
 * @param h264_file   Path to input raw H.264 file
 * @param fps         Frames per second of the video
 * @param pcm_buf     Pointer to raw PCM audio buffer (S16_LE, mono)
 * @param pcm_samples Total number of audio samples
 * @param sample_rate Audio sampling rate (Hz)
 * @param sps         Pointer to SPS (sequence parameter set) data
 * @param sps_len     Length of SPS data
 * @param pps         Pointer to PPS (picture parameter set) data
 * @param pps_len     Length of PPS data
 * @param output_file Path to output MP4 file
 *
 * @return the execution result
 * @retval  0 success
 * @retval -1 failure
 */
int muxAudioVideoToMp4(const char *h264_file, int fps, const int16_t *pcm_buf, int pcm_samples, int sample_rate,
                       uint8_t *sps, size_t sps_len, uint8_t *pps, size_t pps_len, const char *output_file)
{
	struct mp4_mux_context ctx = {
		.video_time_scale = 90000, .audio_time_scale = sample_rate, .fps = fps, .sample_rate = sample_rate
	};
	ctx.video_frame_duration = ctx.video_time_scale / fps;

	int width = 0, height = 0;
	if (getResolutionFromSps(sps, sps_len, &width, &height) != 0) {
		fprintf(stderr, "Failed to parse resolution from SPS. Using default 1920x1080.\n");
		width = 1920;
		height = 1080;
	}

	ctx.mp4 = MP4Create(output_file, 0);
	if (!ctx.mp4)
		return -1;

	ctx.video_track = MP4AddH264VideoTrack(ctx.mp4, ctx.video_time_scale, ctx.video_frame_duration, width, height,
	                                       sps[1], sps[2], sps[3], 3);
	MP4AddH264SequenceParameterSet(ctx.mp4, ctx.video_track, sps, sps_len);
	MP4AddH264PictureParameterSet(ctx.mp4, ctx.video_track, pps, pps_len);

	ctx.audio_track = MP4AddAudioTrack(ctx.mp4, sample_rate, MP4_INVALID_DURATION, MP4_MP3_AUDIO_TYPE);
	if (ctx.audio_track == MP4_INVALID_TRACK_ID) {
		fprintf(stderr, "Failed to add audio track\n");
		return -1;
	}

	MP4SetAudioProfileLevel(ctx.mp4, 0x0F); // MPEG Audio profile

	FILE *fp = fopen(h264_file, "rb");
	if (!fp)
		return -1;

	int serial = extractSerialFromFilename(h264_file);

	int video_frame_count = countH264Frames(fp);

	int16_t *adjusted_pcm_buf = (int16_t *)pcm_buf;
	int adjusted_pcm_samples = pcm_samples;

	if (serial == 0) {
		double video_sec = (double)video_frame_count / fps;
		double audio_sec = (double)pcm_samples / sample_rate;

		if (audio_sec < video_sec) {
			int pad_samples = (int)((video_sec - audio_sec) * sample_rate);
			int total = pcm_samples + pad_samples;
			printf("[i] Serial=0: padding %d samples (%.2fs)\n", pad_samples,
			       (float)pad_samples / sample_rate);

			int16_t *padded = calloc(total, sizeof(int16_t));
			if (!padded) {
				fclose(fp);
				return -1;
			}
			memcpy(padded + pad_samples, pcm_buf, pcm_samples * sizeof(int16_t));
			adjusted_pcm_buf = padded;
			adjusted_pcm_samples = total;
		}
	}

	/* MP3 encode init */
	lame_global_flags *lame = lame_init();
	if (!lame) {
		fprintf(stderr, "Failed to initailize MP3 encoder\n");
		fclose(fp);
		return -1;
	}

	/* MP3 encode init parameters */
	lame_set_in_samplerate(lame, sample_rate);
	lame_set_num_channels(lame, 1);
	lame_set_brate(lame, 48); // Fixed bit rate 48kbps for 8K or 16K
	lame_set_mode(lame, 3);
	lame_set_quality(lame, 2);

	lame_set_out_samplerate(lame, sample_rate);
	if (lame_init_params(lame) < 0) {
		fprintf(stderr, "Failed to initailize MP3 parameters\n");
		lame_close(lame);
		fclose(fp);
		return -1;
	}

	ctx.audio_frame_size = lame_get_framesize(lame);

	/* mp3buffer_size (in bytes) = 1.25*num_samples + 7200. */
	int mp3_buf_size = (adjusted_pcm_samples * 1.25) + 7200;
	unsigned char *mp3_buf = malloc(sizeof(unsigned char) * mp3_buf_size);
	if (!mp3_buf) {
		fprintf(stderr, "Unable to allocate MP3 buffer\n");
		lame_close(lame);
		fclose(fp);
		return -1;
	}

	/* MP3 encode */
	int encoded_bytes = lame_encode_buffer(lame, (short int *)adjusted_pcm_buf, NULL, adjusted_pcm_samples, mp3_buf,
	                                       mp3_buf_size);
	if (encoded_bytes < 0) {
		fprintf(stderr, "MP3 encoding error: %d\n", encoded_bytes);
		free(mp3_buf);
		lame_close(lame);
		fclose(fp);
		return -1;
	}

	encoded_bytes += lame_encode_flush(lame, &mp3_buf[encoded_bytes], mp3_buf_size - encoded_bytes);

	uint8_t *video_frame = NULL;
	size_t video_size = 0;
	int frame_index = 0;
	bool is_keyframe = false;
	int mp3_size = ctx.audio_frame_size;

	while (parseH264AccessUnit(fp, &video_frame, &video_size, &is_keyframe) > 0) {
		writeMp4VideoFrame(&ctx, video_frame, video_size, is_keyframe);
		free(video_frame);

		if (encoded_bytes > 0) {
			if (encoded_bytes < mp3_size) {
				mp3_size = encoded_bytes;
			}
			writeMp4AudioFrame(&ctx, &mp3_buf[mp3_size * frame_index], mp3_size);
			encoded_bytes -= mp3_size;
		}

		frame_index++;
	}

	fclose(fp);

	/* MP3 encode uninit */
	if (mp3_buf) {
		free(mp3_buf);
		mp3_buf = NULL;
	}
	if (lame) {
		lame_close(lame);
	}

	if (serial == 0 && adjusted_pcm_buf != pcm_buf)
		free(adjusted_pcm_buf);

	MP4Close(ctx.mp4, 0);
	return 0;
}
