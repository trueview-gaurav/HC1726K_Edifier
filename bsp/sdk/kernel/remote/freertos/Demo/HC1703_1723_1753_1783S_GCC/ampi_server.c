/*
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* This is a sample demonstration application that showcases usage of rpmsg
This application is meant to run on the remote CPU running baremetal code.
This application echoes back data that was sent to it by the master core. */

#include <stdio.h>
#include <openamp/version.h>
#include <metal/version.h>
#include "metal/alloc.h"
#include "ampi.h"
#include "utils/printf.h"

#define LPRINTF(format, ...) printf("[RTOS]: " format, ##__VA_ARGS__)
//#define LPRINTF(format, ...)
#define LPERROR(format, ...) LPRINTF("ERR: " format, ##__VA_ARGS__)

#ifdef USE_TFLITE_MICRO
extern void create_inf_service(ampi_dev dev);
#endif

#ifdef USE_NCNN
extern void create_od_service(ampi_dev dev);
#endif

#ifdef USE_ROSA
extern void create_sd_service(ampi_dev dev);
#endif

void echo_handler(ampi_svc svc, void *data, int len, svc_event_t evn)
{
	if (evn == SVC_CLEAN)
		return;
	ampi_send(svc, data, len, -1);
}

//int tx_count = 0;

void tx_check_handler(ampi_svc svc, void *data, int len, svc_event_t evn)
{
	int i;
	int *count;
	char *p = (char *)data;

	count = ampi_get_private(svc);
	//count = &tx_count;
	if (count == NULL) {
		count = metal_allocate_memory(sizeof(int));
		*count = 0;
		ampi_set_private(svc, count);
	} else {
		(*count)++;
	}

	if (evn == SVC_CLEAN) {
		metal_free_memory(count);
		return;
	}

	if (len != ((*count & 0xff) + 1)) //1~256
		LPERROR("TX len incorrect, len(%d), count(%d)\n", len, *count);

	for (i = 0; i < len; i++) {
		if (p[i] != (len & 0xff)) {
			LPERROR("TX data incorrect len(%d), err(0x%x), at(%d)\n", len, p[i], i);
			break;
		}
	}

	ampi_send(svc, data, len, -1);
}

/*-----------------------------------------------------------------------------*
 *  Application entry point
 *-----------------------------------------------------------------------------*/
int rpmsg_echo_ampi()
{
	int ret;
	ampi_dev dev;

	LPRINTF("openamp lib version: %s (", openamp_version());
	LPRINTF("Major: %d, ", openamp_version_major());
	LPRINTF("Minor: %d, ", openamp_version_minor());
	LPRINTF("Patch: %d)\r\n", openamp_version_patch());

	LPRINTF("libmetal lib version: %s (", metal_ver());
	LPRINTF("Major: %d, ", metal_ver_major());
	LPRINTF("Minor: %d, ", metal_ver_minor());
	LPRINTF("Patch: %d)\r\n", metal_ver_patch());

	LPRINTF("Starting application...\r\n");

	dev = ampi_init(0);
	if (dev < 0) {
		LPERROR("AMPI init fail\n");
		return -1;
	}

	// ampi_create_service(dev, "hello", echo_handler);
	ampi_create_service(dev, "tx_check", tx_check_handler);

#ifdef USE_TFLITE_MICRO
	create_inf_service(dev);
#endif
#ifdef USE_NCNN
	create_od_service(dev);
#endif
#ifdef USE_ROSA
	create_sd_service(dev);
#endif

	ampi_server_start(&dev, 1);

	LPRINTF("Stopping application...\r\n");

	return ret;
}
