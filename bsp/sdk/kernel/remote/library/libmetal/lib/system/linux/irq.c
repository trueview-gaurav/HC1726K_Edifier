/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file	linux/irq.c
 * @brief	Linux libmetal irq operations
 */

#include <pthread.h>
#include <sched.h>
#include <metal/device.h>
#include <metal/irq.h>
#include <metal/irq_controller.h>
#include <metal/sys.h>
#include <metal/mutex.h>
#include <metal/list.h>
#include <metal/utilities.h>
#include <metal/alloc.h>
#include <sys/time.h>
#include <sys/eventfd.h>
#include <sched.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/epoll.h>
#include <unistd.h>

#define MAX_IRQS (FD_SETSIZE - 1) /**< maximum number of irqs */

struct irq_set_info {
	uint16_t reserve; //to make this struct size of 8-bytes to comply with eventfd
	char set;
	char enable;
	int irq;
};

static struct metal_device *irqs_devs[MAX_IRQS]; /**< Linux devices for IRQs */
static int irq_notify_fd; /**< irq handling state change notification file
			    *   descriptor
			    */
static metal_mutex_t irq_lock; /**< irq handling lock */

static bool irq_handling_stop; /**< stop interrupts handling */

static pthread_t irq_pthread; /**< irq handling thread id */
static bool irq_thread_ready = false;

/**< Indicate which IRQ is enabled */
static unsigned long irqs_enabled[metal_div_round_up(MAX_IRQS, METAL_BITS_PER_ULONG)];

static struct metal_irq irqs[MAX_IRQS]; /**< Linux IRQs array */

/* Static functions */
static void metal_linux_irq_set_enable(struct metal_irq_controller *irq_cntr, int irq, unsigned int state);

/**< Linux IRQ controller */
static METAL_IRQ_CONTROLLER_DECLARE(linux_irq_cntr, 0, MAX_IRQS, NULL, metal_linux_irq_set_enable, NULL, irqs);

int metal_linux_irq_ready()
{
	return irq_thread_ready;
}

unsigned int metal_irq_save_disable(void)
{
	/* This is to avoid deadlock if it is called in ISR */
	if (pthread_self() == irq_pthread)
		return 0;
	metal_mutex_acquire(&irq_lock);
	return 0;
}

void metal_irq_restore_enable(unsigned int flags)
{
	(void)flags;
	if (pthread_self() != irq_pthread)
		metal_mutex_release(&irq_lock);
}

static int metal_linux_irq_notify(struct irq_set_info *set)
{
	int ret;

	ret = write(irq_notify_fd, set, sizeof(struct irq_set_info));
	if (ret != sizeof(struct irq_set_info)) {
		metal_log(METAL_LOG_ERROR, "%s failed\n", __func__);
	}
	return ret;
}

static void metal_linux_irq_set_enable(struct metal_irq_controller *irq_cntr, int irq, unsigned int state)
{
	int offset, ret;
	struct irq_set_info irq_set;

	if (irq < irq_cntr->irq_base || irq >= irq_cntr->irq_base + irq_cntr->irq_num) {
		metal_log(METAL_LOG_ERROR, "%s: invalid irq %d\n", __func__, irq);
		return;
	}
	offset = irq - linux_irq_cntr.irq_base;
	irq_set.irq = offset;
	irq_set.set = 1;
	metal_mutex_acquire(&irq_lock);
	if (state == METAL_IRQ_ENABLE) {
		irq_set.enable = 1;
		metal_bitmap_set_bit(irqs_enabled, offset);
	} else {
		irq_set.enable = 0;
		metal_bitmap_clear_bit(irqs_enabled, offset);
	}
	metal_mutex_release(&irq_lock);
	/* Notify IRQ thread that IRQ state has changed */
	ret = metal_linux_irq_notify(&irq_set);
	if (ret < 0) {
		metal_log(METAL_LOG_ERROR, "%s: failed to notify set %d enable\n", __func__, irq);
	}
}

/**
 * @brief       IRQ handler
 * @param[in]   args  not used. required for pthread.
 */
static void *metal_linux_irq_handling(void *args)
{
	struct sched_param param;
	int ret;
	int i, pfds_total;
	struct epoll_event *events;
	struct epoll_event ev;
	int epollfd;
	struct irq_set_info irq_set;
	(void)args;

	events = malloc(FD_SETSIZE * sizeof(struct epoll_event));
	if (!events) {
		metal_log(METAL_LOG_ERROR, "%s: failed to allocate irq event mem.\n", __func__);
		return NULL;
	}
	epollfd = epoll_create(FD_SETSIZE);

	param.sched_priority = sched_get_priority_max(SCHED_FIFO);
	/* Ignore the set scheduler error */
	ret = sched_setscheduler(0, SCHED_FIFO, &param);
	if (ret) {
		metal_log(METAL_LOG_WARNING, "%s: Failed to set scheduler: %s.\n", __func__, strerror(ret));
	}

	metal_mutex_acquire(&irq_lock);

	ev.events = EPOLLIN | EPOLLERR;
	ev.data.fd = irq_notify_fd;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, ev.data.fd, &ev);

	metal_bitmap_for_each_set_bit(irqs_enabled, i, linux_irq_cntr.irq_num)
	{
		ev.events = EPOLLIN;
		ev.data.fd = i;
		epoll_ctl(epollfd, EPOLL_CTL_ADD, ev.data.fd, &ev);
	}

	metal_mutex_release(&irq_lock);

	irq_thread_ready = true;

	while (1) {
		pfds_total = epoll_wait(epollfd, events, FD_SETSIZE, 5000);
		metal_mutex_acquire(&irq_lock);
		if (irq_handling_stop) {
			/* Killing this IRQ handling thread */
			metal_mutex_release(&irq_lock);
			break;
		}

		metal_mutex_release(&irq_lock);

		for (i = 0; i < pfds_total; i++) {
			if ((events[i].data.fd == irq_notify_fd) && (events[i].events & EPOLLIN)) {
				/* IRQ registration change notification */
				if (read(events[i].data.fd, (void *)&irq_set, sizeof(irq_set)) !=
				    sizeof(struct irq_set_info))
					metal_log(METAL_LOG_ERROR, "%s, read irq fd %d failed\n", __func__,
					          events[i].data.fd);
				else if (irq_set.set == 1) {
					metal_mutex_acquire(&irq_lock);
					if (irq_set.enable) {
						ev.events = EPOLLIN;
						ev.data.fd = irq_set.irq;
						epoll_ctl(epollfd, EPOLL_CTL_ADD, ev.data.fd, &ev);
					} else {
						epoll_ctl(epollfd, EPOLL_CTL_DEL, irq_set.irq, NULL);
					}
					metal_mutex_release(&irq_lock);
				}
			} else if ((events[i].events & EPOLLIN)) {
				struct metal_device *dev = NULL;
				int irq_handled = 0;
				int fd;

				fd = events[i].data.fd;
				dev = irqs_devs[fd];
				metal_mutex_acquire(&irq_lock);
				if (metal_irq_handle(&irqs[fd], fd) == METAL_IRQ_HANDLED)
					irq_handled = 1;
				if (irq_handled) {
					if (dev && dev->bus->ops.dev_irq_ack)
						dev->bus->ops.dev_irq_ack(dev->bus, dev, fd);
				}
				metal_mutex_release(&irq_lock);
			} else if (events[i].events) {
				metal_log(METAL_LOG_DEBUG, "%s: poll unexpected. fd %d: %d\n", __func__,
				          events[i].data.fd, events[i].events);
			}
		}
	}
	free(events);
	return NULL;
}

/**
 * @brief irq handling initialization
 * @return 0 on success, non-zero on failure
 */
int metal_linux_irq_init(void)
{
	int ret;

	memset(&irqs, 0, sizeof(irqs));

	irq_notify_fd = eventfd(0, 0);
	if (irq_notify_fd < 0) {
		metal_log(METAL_LOG_ERROR, "Failed to create eventfd for IRQ handling.\n");
		return -EAGAIN;
	}

	metal_mutex_init(&irq_lock);
	irq_handling_stop = false;
	ret = metal_irq_register_controller(&linux_irq_cntr);
	if (ret < 0) {
		metal_log(METAL_LOG_ERROR, "Linux IRQ controller failed to register.\n");
		return -EINVAL;
	}
	ret = pthread_create(&irq_pthread, NULL, metal_linux_irq_handling, NULL);
	if (ret != 0) {
		metal_log(METAL_LOG_ERROR, "Failed to create IRQ thread: %d.\n", ret);
		return -EAGAIN;
	}

	return 0;
}

/**
 * @brief irq handling shutdown
 */
void metal_linux_irq_shutdown(void)
{
	int ret;
	struct irq_set_info irq_set = { 1, 0, 0, 0 };

	metal_log(METAL_LOG_DEBUG, "%s\n", __func__);
	irq_handling_stop = true;
	metal_linux_irq_notify(&irq_set);
	ret = pthread_join(irq_pthread, NULL);
	if (ret) {
		metal_log(METAL_LOG_ERROR, "Failed to join IRQ thread: %d.\n", ret);
	}
	close(irq_notify_fd);

	metal_mutex_deinit(&irq_lock);
}

void metal_linux_irq_register_dev(struct metal_device *dev, int irq)
{
	if (irq > MAX_IRQS) {
		metal_log(METAL_LOG_ERROR, "Failed to register device to irq %d\n", irq);
		return;
	}
	irqs_devs[irq] = dev;
}
