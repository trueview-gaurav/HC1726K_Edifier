/*
 * (C) Copyright 2021 Augentix 
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include "agtx_early_amp.h"
#include <asm-generic/gpio.h>

#ifndef CONFIG_AMP
#error "agtx_early_amp feature is only supported in AMP products"
#endif

#define gicd_sgir (volatile uint32_t *)(GIC_BASE + 0x1F00)

/* GPIO definitions */
#define OUTPUT 1
#define GPIO_OFFS 0xC /* Offset between each gpio register */

extern int get_gpio_csr(uint32_t gpio_id, uint32_t **csr, uint32_t *bit);

struct csr_control {
	uint32_t *csr;
	uint32_t mask;
	uint32_t value;
};

struct detect {
	volatile uint32_t type;
	volatile uint32_t threshold;
	volatile void *data;

	volatile struct csr_control alarm_on;
	volatile struct csr_control alarm_off;
};


static void init_alarm_csr(struct detect *det, uint32_t type, uint32_t id)
{
	switch (type) {
	case 0: // SoC PD sleep
		det->alarm_on.csr = (uint32_t *)0x80530018;
		det->alarm_on.mask = 0x01;
		det->alarm_on.value = 0x01;
		break;
	case 1: // GPIO active high
	case 2: // GPIO active low
		gpio_set_value(id, (type == 1) ? 0 : 1);
		gpio_direction_output(id, OUTPUT);
		get_gpio_csr(id, (uint32_t **)&det->alarm_on.csr, (uint32_t *)&det->alarm_on.mask);
		det->alarm_on.value = (type == 1) ? det->alarm_on.mask : 0;
	}
	det->alarm_off.csr = (uint32_t *)0;
	det->alarm_off.mask = 0;
	det->alarm_off.value = 0;
}

struct amp_early_channel {
	int32_t busy;
	int32_t request;
	int32_t response;
	void *data;
};

volatile struct amp_early_channel *g_chann = (void *)AMP_DRIVER_SHM_ADDR;

static void gic_request_sgi(uint32_t id, uint32_t cpu)
{
	*gicd_sgir = ((0x0 << 24) | (0x01 << (16 + cpu)) | (id << 0));
}
/**
 * amp_early_request() - Send a request to RTOS core
 *
 * This this API is only used in AMP product
 *
 * @request:	Request type
 * @data:	Pointer to data to be proccessed, if there is.
 */
void amp_early_request(int32_t request, void *data)
{
	dcache_enable();
	while (g_chann->busy != 0) {
	}

	g_chann->request = request;
	g_chann->data = data;
	g_chann->busy = 1;

	gic_request_sgi(2, 0);
}

/**
 * amp_early_get_response() - Get the response of previous request
 *
 * This this API is only used in AMP product
 * The response value always over write by new one, only the response 
 * of the last request exist.
 *
 * @request:	Request type
 * @response:	Pointer to response variable
 *
 * @return 0 on success, nagtive value on fail when there is no response
 * of currect request type.
 */
int amp_early_get_response(int32_t request, int32_t *response)
{
	if (g_chann->request != request)
		return -1;

	while (g_chann->busy != 0) {
	}

	*response = g_chann->response;

	return 0;
}

/**
 * amp_early_get_shm() - Get a shared memory between Dual cores
 *
 * There is a 1KB shared memory reserved for Dual-core applications.
 * This function didn't provide any memory management machenism, instead,
 * it just return the address of same shared memory.
 *
 * @return: the pointer to 1KB shared memory.
 */
void *amp_early_get_shm(void)
{
	return (void *)(AMP_DRIVER_SHM_ADDR + (3 * 1024));
}

/**
 * amp_false_alarm_detect() - Request a false alarm detection
 *
 * Sends a false alarm detection request to RTOS.
 *
 * @type: detection type: bit[0]: human, bit[1]: car
 * @threshold: the threshold of judgement.
 * @data: the information of YUV snapshot.
 *
 */
void amp_false_alarm_detect(uint32_t type, uint32_t threshold, void *data)
{
	struct detect *det;
	det = amp_early_get_shm();
	init_alarm_csr(det, FALSE_ALARM_SLEEP_TYPE, FALSE_ALARM_SLEEP_IO);
	det->type = type;
	det->threshold = threshold;
	det->data = data;
	amp_early_request(AMP_EARLY_FALSE_ALARM, det);
}
