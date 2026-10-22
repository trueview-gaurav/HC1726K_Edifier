#ifndef OD_SERVICE_H_
#define OD_SERVICE_H_

#include "ampi.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_EARLY_OD
void od_load_early_handler(ampi_svc svc, void *data, int len, svc_event_t evn);
void od_early_forward_handler(ampi_svc svc, void *data, int len, svc_event_t evn);
void od_debug_roi_handler(ampi_svc svc, void *data, int len, svc_event_t evn);
#else
void od_load_model_handler(ampi_svc svc, void *data, int len, svc_event_t evn);
void od_model_forward_handler(ampi_svc svc, void *data, int len, svc_event_t evn);
#endif // USE_EARLY_OD

#ifdef __cplusplus
}
#endif
#endif //OD_SERVICE_H_
