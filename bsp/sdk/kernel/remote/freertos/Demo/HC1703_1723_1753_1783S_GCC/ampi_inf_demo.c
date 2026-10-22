/*
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* This is a sample demonstration application that showcases usage of rpmsg
This application is meant to run on the remote CPU running baremetal code.
This application echoes back data that was sent to it by the master core. */
#ifdef USE_TFLITE_MICRO

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "ampi.h"
#include "utils/printf.h"

#include "inf_service.h"

#define ERR(format, ...) printf("[AMPI SERVICE MD]: " format, ##__VA_ARGS__)

void create_inf_service(ampi_dev dev)
{
	ampi_create_service(dev, "inf-load-model", inf_load_model_handler);
	ampi_create_service(dev, "inf-model-forward", inf_model_forward_handler);
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

#endif
