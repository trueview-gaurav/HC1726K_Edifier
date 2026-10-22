#ifndef FRAME_DUMPER_H
#define FRAME_DUMPER_H

#ifdef __cplusplus
extern "C" {
#endif /**< __cplusplus */

#include "sample_publisher.h"
#include <stdint.h>

/* RecordFileMode is removed; file_mode uses UINT8 with the following values: */
#define RECORD_FILE_BLOCKING_RETRY    0 /**< Default. Busy-wait until target path becomes available */
#define RECORD_FILE_NONBLOCK_REDIRECT 1 /**< Redirect to fallback immediately if target is unavailable */

BitStreamSubscriber *newFrameDumper(MPI_ECHN encoder_channel, const char *output_path, uint32_t frame_count,
                                    bool repeat, int32_t reservation_level, int32_t recycle_level,
                                    int max_dumped_files, UINT8 file_mode);

#ifdef __cplusplus
}
#endif /**< __cplusplus */

#endif //FRAME_DUMPER_H
