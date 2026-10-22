/*
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* This is a sample demonstration application that showcases usage of rpmsg
This application is meant to run on the remote CPU running baremetal code.
This application echoes back data that was sent to it by the master core. */
#ifdef USE_NCNN

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "ampi.h"
#include "utils/printf.h"

#include "od_service.h"

#define ERR(format, ...) printf("[AMPI SERVICE MD]: " format, ##__VA_ARGS__)

void create_od_service(ampi_dev dev)
{
#ifdef USE_EARLY_OD
	ampi_create_service(dev, "od-load-early", od_load_early_handler);
	ampi_create_service(dev, "od-early-forward", od_early_forward_handler);
	ampi_create_service(dev, "od-debug-roi", od_debug_roi_handler);
#else
	ampi_create_service(dev, "od-load-model", od_load_model_handler);
	ampi_create_service(dev, "od-model-forward", od_model_forward_handler);
#endif // USE_EARLY_OD
}

extern void abort(void)
{
	ERR("*** abort ***\n");
	while (1)
		;
}

extern int atexit(void (*func)(void))
{
	return 0;
}

extern void __assert_fail(const char *assertion, const char *file, unsigned int line, const char *function)
{
	printf("%s FAILED in function %s of %s::%d\n", assertion, function, file, line);
	while (1)
		;
}

extern void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
	printf("[ERROR] Task: `%s` stack overflow detected!\n", pcTaskName);
}

#endif //USE_NCNN