#ifndef _EARLYAUDIO_H_
#define _EARLYAUDIO_H_

#include <linux/types.h>

struct early_audio_args {
	/* early audio buffer */
	unsigned long addr;
	uint32_t size;
};

void early_audio_free(void);
void early_audio_retrieve_args(struct early_audio_args *args);

#endif /* _EARLYAUDIO_H_ */
