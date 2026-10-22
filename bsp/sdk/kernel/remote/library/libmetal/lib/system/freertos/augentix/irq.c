/*
 * Copyright (c) 2016 - 2017, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	generic/aug_common/irq.c
 * @brief	generic libmetal Xilinx irq controller definitions.
 */

#include <metal/errno.h>
#include <metal/irq_controller.h>
#include <metal/sys.h>
#include <metal/log.h>
#include <metal/mutex.h>
#include <metal/list.h>
#include <metal/utilities.h>
#include <metal/alloc.h>
#include <utils/printf.h>
#include <intc/hw_gic.h>

#define MAX_IRQS 16

static void metal_aug_irq_set_enable(struct metal_irq_controller *irq_cntr, int irq, unsigned int state)
{
	metal_unused(state);
	if (irq < irq_cntr->irq_base || irq >= irq_cntr->irq_base + irq_cntr->irq_num) {
		metal_log(METAL_LOG_ERROR, "%s: invalid irq %d\n", __func__, irq);
	}
}

static int aug_cntr_irq_register(struct metal_irq_controller *irq_cntr, int irq, metal_irq_handler hd, void *arg)
{
	(void)irq_cntr;
	gic_register_isr(irq, (isr_cb_t)hd, arg);
	return 0;
}

/**< Xilinx common platform IRQ controller */
static METAL_IRQ_CONTROLLER_DECLARE(aug_irq_cntr, 0, MAX_IRQS, NULL, metal_aug_irq_set_enable, aug_cntr_irq_register,
                                    NULL);

int metal_aug_irq_init(void)
{
	int ret;

	ret = metal_irq_register_controller(&aug_irq_cntr);
	if (ret < 0) {
		printf("%s: register irq controller failed.\n", __func__);
		return ret;
	}
	return 0;
}
