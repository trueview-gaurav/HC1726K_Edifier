/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __DRIVERS_AGTX_UART_H
#define __DRIVERS_AGTX_UART_H

#include <types_ext.h>
#include <drivers/serial.h>

struct agtx_uart_data {
	struct io_pa_va base;
	struct serial_chip chip;
};

void agtx_uart_init(struct agtx_uart_data *pd, paddr_t base);

#endif /* __DRIVERS_AGTX_UART_H */
