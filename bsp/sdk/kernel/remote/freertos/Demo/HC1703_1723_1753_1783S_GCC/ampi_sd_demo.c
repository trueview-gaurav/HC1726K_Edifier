/*
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* This is a sample demonstration application that showcases usage of rpmsg
This application is meant to run on the remote CPU running baremetal code.
This application echoes back data that was sent to it by the master core. */
#ifdef USE_ROSA

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "ampi.h"
#include "utils/printf.h"

#include "sd_service.h"

#define ERR(format, ...) printf("[AMPI SERVICE MD]: " format, ##__VA_ARGS__)

void create_sd_service(ampi_dev dev)
{
	ampi_create_service(dev, "sd-rosa-feature", sd_rosa_feature_handler);
}

#endif //USE_ROSA
