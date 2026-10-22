#include "ampi.h"

#include <metal/atomic.h>
#include <metal/assert.h>
#include <metal/device.h>
#include <metal/irq.h>
#include <metal/time.h>
#include <metal/utilities.h>
#include <openamp/rpmsg_virtio.h>
#include <openamp/remoteproc.h>
#include <openamp/virtio.h>
#include <openamp/rpmsg.h>
#include "utils/printf.h"
#include "intc/hw_gic.h"
#include "amp_rsc_table.h"
#include "augentix_freertos_rproc.h"
#include "ampi_default_service.h"


#define INFO(x, ...) printf("[RTOS AMPI INFO]:" x, ##__VA_ARGS__)
#define ERR(x, ...) printf("[RTOS AMPI ERR]:" x, ##__VA_ARGS__)
#define WARN(x, ...) printf("[RTOS AMPI WARN]:" x, ##__VA_ARGS__)

#define msg_lock()
#define msg_unlock()

#include "ampi_common.h"

#define _rproc_wait() //asm volatile("wfi")

/* External functions */
extern const struct remoteproc_ops amp_augentix_freertos_proc_ops;

static struct remoteproc_priv amp_rproc_priv = {
	.shm_dev_name = SHM_DEV_NAME,
	.shm_dev_bus_name = DEV_BUS_NAME_FREERTOS,
};

static metal_mutex_t rdev_lock;
uint16_t vq_available_idx[2];

ampi_dev ampi_init(int ampi_id)
{
	ampi_dev_priv_t *ampidev;
	void *rsc_buf, *rsc_table_share;
	int rsc_size;
	int ret;
	metal_phys_addr_t pa;
	struct metal_io_region *shbuf_io;
	void *shbuf;
	struct virtio_device *vdev;
	unsigned int role = VIRTIO_DEV_DRIVER;

	if (ampi_id >= AMPI_DEV_NUMBER) {
		ERR("inccorrect ampc_id\n");
		return AMPI_FAILURE;
	}

	ampidev = &ampi_handle[ampi_id];

	memset(ampidev, 0, sizeof(ampi_dev_priv_t));

	/* Initialize HW system components */
	if (amp_init_system() != AMPI_SUCCESS)
		return AMPI_FAILURE;

	rsc_buf = amp_get_resource_table(ampi_id, &rsc_size);
	rsc_table_share = (void *)RSC_TABLE_PA;
	memcpy(rsc_table_share, rsc_buf, rsc_size);
	ampidev->rsc_table = (struct remote_resource_table *)rsc_table_share;

	/* Initialize remoteproc instance */
	if (!remoteproc_init(&ampidev->rproc_inst, &amp_augentix_freertos_proc_ops, &amp_rproc_priv))
		return AMPI_FAILURE;

	pa = SHM_BASE_ADDR;
	(void *)remoteproc_mmap(&ampidev->rproc_inst, &pa, NULL, SHM_BASE_SIZE, 0, NULL);

	/* parse resource table to remoteproc */
	ret = remoteproc_set_rsc_table(&ampidev->rproc_inst, rsc_table_share, rsc_size);
	if (ret) {
		ERR("Failed to initialize remoteproc\r\n");
		goto ERR1;
	}

	shbuf_io = remoteproc_get_io_with_pa(&ampidev->rproc_inst, SHARED_MEM_PA);
	if (!shbuf_io)
		goto ERR1;
	shbuf = metal_io_phys_to_virt(shbuf_io, SHARED_MEM_PA);

	vdev = remoteproc_create_virtio(&ampidev->rproc_inst, ampi_id, role, NULL);
	if (!vdev) {
		ERR("failed remoteproc_create_virtio\r\n");
		goto ERR1;
	}

	metal_mutex_init(&rdev_lock);
	ampidev->rpmsg_vdev.rdev.lock = &rdev_lock;
	vdev->vrings_info[0].vq->vq_available_idx = &vq_available_idx[0];
	vdev->vrings_info[1].vq->vq_available_idx = &vq_available_idx[1];

	if (role == VIRTIO_DEV_DRIVER) {
		/* Only RPMsg virtio master needs to initialize the shared buffers pool */
		rpmsg_virtio_init_shm_pool(&ampidev->shpool, shbuf, SHARED_MEM_SIZE);

		/* RPMsg virtio slave can set shared buffers pool argument to NULL */
		ret = rpmsg_init_vdev(&ampidev->rpmsg_vdev, vdev, rpmsg_service_link_cb, shbuf_io, &ampidev->shpool);
	} else {
		ret = rpmsg_init_vdev(&ampidev->rpmsg_vdev, vdev, rpmsg_service_link_cb, shbuf_io, NULL);
	}
	if (ret) {
		ERR("failed rpmsg_init_vdev\r\n");
		goto ERR2;
	}

	ampidev->rpmsg_vdev.rdev.support_ns = false;

	INFO("Initialize AMPI successfully.\r\n");

	create_freertos_sys_service((ampi_dev)ampidev);

	return (ampi_dev)ampidev;
ERR2:
	remoteproc_remove_virtio(&ampidev->rproc_inst, vdev);
ERR1:
	remoteproc_remove(&ampidev->rproc_inst);
	return AMPI_FAILURE;
}

ampi_svc ampi_link_service(ampi_dev dev, char *svc_name, int timeout)
{
	int ret;
	int sync;
	ampi_dev_priv_t *ampidev = (ampi_dev_priv_t *)dev;
	link_t *link;
	link = find_link_by_name(ampidev, svc_name);
	if (link != NULL)
		return (ampi_svc)link;
	link = find_empty_link_and_mark(ampidev);
	if ((int)link == AMPI_FAILURE) {
		WARN("There %d links exist, no space for new link\n", AMPI_MAX_LINK_NUMBER);
		return AMPI_FAILURE;
	}

	ret = rpmsg_create_ept(&link->ept, &ampidev->rpmsg_vdev.rdev, svc_name, RPMSG_ADDR_ANY, RPMSG_ADDR_ANY,
	                       rpmsg_client_cb, rpmsg_service_unbind_cb);
	if (ret) {
		ERR("Fail to link service: %s\n", svc_name);
		link->connected = 0;
		return AMPI_FAILURE;
	}
	link->ept.priv = (void *)ampidev;

	ampi_receive((ampi_svc)link, &sync, sizeof(sync), timeout);
	if (sync != HAND_SHAKE_KEY) {
		ERR("Link handshake fail\n");
		ampi_unlink_service((ampi_svc)link);
		return AMPI_FAILURE;
	}

	return (ampi_svc)link;
}

void ampi_unlink_service(ampi_svc service)
{
	link_t *link = (link_t *)service;
	rpmsg_service_unbind_cb(&link->ept);
}

void ampi_server_start(ampi_dev dev[], int dev_num)
{
	ampi_dev_priv_t *ampidev;
	int i;
	TickType_t last;

	last = xTaskGetTickCount();

	while (1) {
		if (remoteproc_nitofied(&amp_rproc_priv)) {
			for (i = 0; i < dev_num; i++) {
				ampidev = (ampi_dev_priv_t *)dev[i];
				remoteproc_get_notification(&ampidev->rproc_inst, RSC_NOTIFY_ID_ANY);
			}
		}

		if ((xTaskGetTickCount() - last) > configTICK_RATE_HZ) {
			last = xTaskGetTickCount();
			for (i = 0; i < dev_num; i++) {
				ampidev = (ampi_dev_priv_t *)dev[i];
				tick_link(ampidev);
			}
		}
	}
}

int ampi_receive(ampi_svc svc, void *data, size_t len, int timeout)
{
	link_t *link = (link_t *)svc;
	int copy_len;
	ampi_dev_priv_t *ampidev = (ampi_dev_priv_t *)link->ept.priv;
	long long expire;
	struct msg_buf *msg;

	if (timeout != -1) {
		expire = metal_get_timestamp() + (timeout * 1000);
	}

	while (link->msg == NULL) {
		if (timeout != -1 && metal_get_timestamp() > expire)
			return AMPI_FAILURE;
		if (remoteproc_nitofied(&amp_rproc_priv)) {
			remoteproc_get_notification(&ampidev->rproc_inst, RSC_NOTIFY_ID_ANY);
		}
	}

	copy_len = (len > link->msg->len) ? link->msg->len : len;
	memcpy(data, link->msg->data, copy_len);
	rpmsg_release_rx_buffer(&link->ept, link->msg->data);
	msg = link->msg;
	msg_lock();
	link->msg = link->msg->next;
	msg_unlock();

	metal_free_memory(msg);

	return copy_len;
}

uint32_t ampi_virt_to_phys(ampi_dev dev, void *virt_addr)
{
	return (uint32_t)virt_addr;
}

void *ampi_malloc(ampi_dev dev, size_t size)
{
	ERR("calling ampi_malloc from FreeRTOS is not allowed\n");
	return 0;
}

void ampi_free(ampi_dev dev, void *virt_addr)
{
	ERR("calling ampi_free from FreeRTOS is not allowed\n");
}
