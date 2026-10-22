#ifndef AMPI_DEF_SVC_H_
#define AMPI_DEF_SVC_H_

#include "ampi.h"

#define AMPI_SYSTEM_SERVICE "system"

typedef enum {
	SYS_MALLOC,
	SYS_FREE,
	SYS_CMD_NUM,
} SYS_SERVICE_CMD_t;

typedef struct sys_service_req {
	SYS_SERVICE_CMD_t command;
	uint32_t data[4]; //reserve 16 bytes for data exchange
} sys_service_req_t;

typedef struct sys_service_resp {
	int result;
	uint32_t data[4]; //reserve 16 bytes for data exchange
} sys_service_resp_t;

//this function is only called by FreeRTOS
void create_freertos_sys_service(ampi_dev dev);
#endif
