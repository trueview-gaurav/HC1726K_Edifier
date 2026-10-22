#include "parse_audio.h"

#include <stdio.h>
#include <string.h>

#include "sample_stream.h"

#include "parse_utils.h"

static int parse_audio_record_param(char *tok, CONF_AUDIO_RECORDING_PARAM_S *p)
{
	int hit = 1;

	if (!strcmp(tok, "audio_sample_rate")) {
		get_value((void *)&p->audio_sample_rate, TYPE_INT32);
	} else if (!strcmp(tok, "audio_frame_size")) {
		get_value((void *)&p->audio_frame_size, TYPE_INT32);
	} else if (!strcmp(tok, "format")) {
		get_value((void *)&p->format, TYPE_INT32);
	} else if (!strcmp(tok, "audio_output_file")) {
		char *val = strtok(NULL, " =\n");
		snprintf(p->fname, sizeof(p->fname), "%s", val);
	} else if (!strcmp(tok, "audio_max_dumped_files")) {
		get_value((void *)&p->max_dumped_files, TYPE_INT32);
	} else if (!strcmp(tok, "audio_max_frame_count")) {
		get_value((void *)&p->audio_max_frame_count, TYPE_INT32);
	} else {
		hit = 0;
	}

	return hit;
}

int parse_audio_param(char *tok, SAMPLE_CONF_S *conf)
{
	int hit = 1;
	if (!strcmp(tok, "audio_record_enable")) {
		get_value((void *)&conf->audio.enable, TYPE_UINT8);
		goto end;
	}

	hit = parse_audio_record_param(tok, &conf->audio.record);
	if (hit) {
		goto end;
	}

end:
	return hit;
}