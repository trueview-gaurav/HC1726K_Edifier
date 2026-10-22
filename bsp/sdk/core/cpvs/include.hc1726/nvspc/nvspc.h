/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __NVSPC_H_
#define __NVSPC_H_

#include "uart/uart.h"

int prog_init(struct uart_dev);
void conf_load(void);

#endif //__NVSPC_H_
