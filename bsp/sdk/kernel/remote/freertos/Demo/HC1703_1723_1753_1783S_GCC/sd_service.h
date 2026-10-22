#ifndef SD_SERVICE_H_
#define SD_SERVICE_H_

#include "ampi.h"

#ifdef __cplusplus
extern "C" {
#endif

void sd_rosa_feature_handler(ampi_svc svc, void *data, int len, svc_event_t evn);

#ifdef __cplusplus
}
#endif
#endif //OD_SERVICE_H_
