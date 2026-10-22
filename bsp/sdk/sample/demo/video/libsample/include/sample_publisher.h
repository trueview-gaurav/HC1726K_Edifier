#ifndef SAMPLE_PUBLISHER_H
#define SAMPLE_PUBLISHER_H

#ifdef __cplusplus
extern "C" {
#endif /**< __cplusplus */

#include <stdbool.h>
#include "mpi_index.h"
#include "sample_stream.h"

typedef struct bit_stream_subscriber {
  void *context;
  /* return true means abort delivery */
  bool (*deliveryWillStart)(void *context);
  /* return true means subscriber want to unsubscribe */
  bool (*receiveFrame)(void *context, const void *frame_data, uint32_t data_len, uint64_t timestamp);
  void (*deliveryDidEnd)(void *context, uint64_t timestamp);
} BitStreamSubscriber;

extern volatile bool g_audio_dumper_should_flush;

int SAMPLE_startStreamPublisher(MPI_ECHN encoder_channel, const CONF_BITSTREAM_PARAM_S *conf, INT32 reservation_level,
                                INT32 recycle_level, UINT8 sync_with_audio);
void SAMPLE_shutdownStreamPublisher(MPI_ECHN idx);
void SAMPLE_signalAllStreamThreadToShutdown(void);
bool SAMPLE_hasAnyPublisherThreadActive(void);

int SAMPLE_startAudioPublisher(const CONF_AUDIO_PARAM_S *conf, INT32 reservation_level, INT32 recycle_level);
void SAMPLE_shutdownAudioPublisher();
void SAMPLE_signalAllAudioThreadToShutdown(void);
bool SAMPLE_hasAnyAudioPublisherThreadActive(void);

#ifdef __cplusplus
}
#endif /**< __cplusplus */

#endif //SAMPLE_PUBLISHER_H
