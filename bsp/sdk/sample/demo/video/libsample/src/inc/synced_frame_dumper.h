#ifndef SYNCED_FRAME_DUMPER_H
#define SYNCED_FRAME_DUMPER_H

#ifdef __cplusplus
extern "C" {
#endif /**< __cplusplus */

#include "sample_publisher.h"
#include <stdint.h>

BitStreamSubscriber *newSyncedFrameDumper(MPI_ECHN encoder_channel, const char *output_path, uint32_t frame_count,
                                          bool repeat, int32_t reservation_level, int32_t recycle_level,
                                          int max_dumped_files);

#ifdef __cplusplus
}
#endif /**< __cplusplus */

#endif //SYNCED_FRAME_DUMPER_H
