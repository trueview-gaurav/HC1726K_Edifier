#ifndef INF_SERVICE_H_
#define INF_SERVICE_H_

#include "ampi.h"

#ifdef __cplusplus
extern "C" {
#endif

void inf_load_model_handler(ampi_svc svc, void *data, int len, svc_event_t evn);
void inf_model_forward_handler(ampi_svc svc, void *data, int len, svc_event_t evn);

#ifdef __cplusplus
}
#endif
#endif //INF_SERVICE_H_
