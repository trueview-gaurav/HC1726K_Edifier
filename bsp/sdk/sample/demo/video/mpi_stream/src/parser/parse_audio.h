#ifndef PARSE_AUDIO_H_
#define PARSE_AUDIO_H_

#ifdef __cplusplus
extern "C" {
#endif /* !__cplusplus */

#include "mpi_enc.h"
#include "sample_stream.h"

int parse_audio_param(char *tok, SAMPLE_CONF_S *conf);

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !PARSE_AUDIO_H_ */
