#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <metal/atomic.h>
#include <metal/assert.h>
#include <metal/device.h>
#include <metal/mutex.h>
#include <metal/irq.h>
#include <metal/utilities.h>
#include <openamp/rpmsg_virtio.h>
#include <openamp/remoteproc.h>
#include <openamp/virtio.h>
#include <openamp/rpmsg.h>
#include "amp_rsc_table.h"
#include "augentix_linux_rproc.h"
#include "ampi_default_service.h"

#include "ampi.h"

#define INFO(x, ...) printf("[AMPI INFO]:" x, ##__VA_ARGS__)
#define ERR(x, ...) printf("[AMPI ERR]:" x, ##__VA_ARGS__)
#define WARN(x, ...) printf("[AMPI WARN]:" x, ##__VA_ARGS__)

void msg_lock();
void msg_unlock();

#include "ampi_common.h"

static uint32_t client_ept_get_add(ampi_dev_priv_t *ampidev);
static void client_ept_release_add(ampi_dev_priv_t *ampidev, uint32_t add);

/* External functions */
extern const struct remoteproc_ops amp_augentix_linux_rproc_ops;
pthread_mutex_t meg_mut;
uint16_t vq_available_idx[2];

void msg_lock()
{
	pthread_mutex_lock(&meg_mut);
}

void msg_unlock()
{
	pthread_mutex_unlock(&meg_mut);
}

static struct remoteproc_priv amp_rproc_priv = {
	.shm_dev_name = SHM_DEV_NAME,
	.shm_dev_bus_name = DEV_BUS_NAME_LINUX,
	.mut = PTHREAD_MUTEX_INITIALIZER,
	.cond = PTHREAD_COND_INITIALIZER,
};

ampi_dev ampi_init(int ampi_id)
{
	ampi_dev_priv_t *ampidev;
	void *rsc_buf;
	int rsc_size;
	int ret;
	struct metal_io_region *shbuf_io;
	void *shbuf;
	struct metal_io_region *rsc_buf_io;
	struct virtio_device *vdev;
	unsigned int role = VIRTIO_DEV_DEVICE;

	if (ampi_id >= AMPI_DEV_NUMBER) {
		ERR("inccorrect ampc_id\n");
		return AMPI_FAILURE;
	}

	ampidev = &ampi_handle[ampi_id];

	memset(ampidev, 0, sizeof(ampi_dev_priv_t));

	/* Initialize HW system components */
	if (amp_init_system() != AMPI_SUCCESS)
		return AMPI_FAILURE;

	rsc_size = sizeof(struct remote_resource_table);

	/* Initialize remoteproc instance */
	if (!remoteproc_init(&ampidev->rproc_inst, &amp_augentix_linux_rproc_ops, &amp_rproc_priv))
		return AMPI_FAILURE;

	rsc_buf_io = remoteproc_get_io_with_pa(&ampidev->rproc_inst, RSC_TABLE_PA);
	if (!rsc_buf_io)
		goto ERR1;
	rsc_buf = metal_io_phys_to_virt(rsc_buf_io, RSC_TABLE_PA);
	ampidev->rsc_table = (struct remote_resource_table *)rsc_buf;

	/* parse resource table to remoteproc */
	ret = remoteproc_set_rsc_table(&ampidev->rproc_inst, rsc_buf, rsc_size);
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

	//make linux process using same lock in shared-memory.
	ampidev->rpmsg_vdev.rdev.lock = &ampidev->rsc_table->rdev_lock;
	vdev->vrings_info[0].vq->vq_available_idx = &ampidev->rsc_table->client_tx_idx;
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

	remoteproc_start(&ampidev->rproc_inst);
	INFO("Initialize AMPI successfully.\r\n");
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
	char svc_pid[64];
	uint32_t client_add;
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

	snprintf(svc_pid, sizeof(svc_pid), "%s_%d", svc_name, (int)getpid());

	client_add = client_ept_get_add(ampidev);
	if (client_add == RPMSG_ADDR_ANY)
		goto ERR;

	ret = rpmsg_create_ept(&link->ept, &ampidev->rpmsg_vdev.rdev, svc_pid, client_add, RPMSG_ADDR_ANY,
	                       rpmsg_client_cb, rpmsg_service_unbind_cb);
	if (ret)
		goto ERR;

	link->ept.priv = (void *)ampidev;

	ret = ampi_receive((ampi_svc)link, &sync, sizeof(sync), timeout);
	if (ret == AMPI_FAILURE || sync != HAND_SHAKE_KEY) {
		ERR("Link handshake fail\n");
		ampi_unlink_service((ampi_svc)link);
		return AMPI_FAILURE;
	}

	return (ampi_svc)link;
ERR:
	ERR("Fail to link service: %s\n", svc_name);
	link->connected = 0;
	return AMPI_FAILURE;
}

void ampi_unlink_service(ampi_svc service)
{
	link_t *link = (link_t *)service;
	rpmsg_service_unbind_cb(&link->ept);
	client_ept_release_add((ampi_dev_priv_t *)link->ept.priv, link->ept.addr);
}

void ampi_server_start(ampi_dev dev[] __attribute__((unused)), int dev_num)
{
	//ampi_dev_priv_t *ampidev;
	int i;

	while (1) {
		if (remoteproc_wait(&amp_rproc_priv, NULL)) {
			for (i = 0; i < dev_num; i++) {
				//ampidev = (ampi_dev_priv_t *)dev[i];
				//it's done in IRQ thread
				//remoteproc_get_notification(&ampidev->rproc_inst, RSC_NOTIFY_ID_ANY);
			}
		}
	}
}

int ampi_receive(ampi_svc svc, void *data, size_t len, int timeout)
{
	link_t *link = (link_t *)svc;
	int copy_len;
	//ampi_dev_priv_t *ampidev = (ampi_dev_priv_t *)link->ept.priv;
	struct msg_buf *msg;
	struct timespec waittime;
	struct timespec *waittime_p;
	struct timeval now;
	int nsec;

	if (timeout == -1) {
		waittime_p = NULL;
	} else {
		gettimeofday(&now, NULL);
		nsec = now.tv_usec * 1000 + (timeout % 1000) * 1000000;
		waittime.tv_nsec = nsec % 1000000000;
		waittime.tv_sec = now.tv_sec + nsec / 1000000000 + timeout / 1000;
		waittime_p = &waittime;
	}

	while (link->msg == NULL) {
		if (remoteproc_wait(&amp_rproc_priv, waittime_p)) {
			//it's done in IRQ thread
			//remoteproc_get_notification(&ampidev->rproc_inst, RSC_NOTIFY_ID_ANY);
		} else if (link->msg == NULL) {
			return AMPI_FAILURE;
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
	ampi_dev_priv_t *ampidev = (ampi_dev_priv_t *)dev;
	uint32_t phys;
	struct metal_io_region *mem_io;
	mem_io = remoteproc_get_io_with_va(&ampidev->rproc_inst, virt_addr);
	if (mem_io == NULL)
		return 0;
	phys = metal_io_virt_to_phys(mem_io, virt_addr);
	return phys;
}

void *ampi_malloc(ampi_dev dev, size_t size)
{
	ampi_svc sys_svc;
	ampi_dev_priv_t *ampidev = (ampi_dev_priv_t *)dev;
	sys_service_req_t req;
	sys_service_resp_t resp;
	struct metal_io_region *mem_io;
	void *ret;
	INFO("malloc(%d)\n", (int)getpid());
	sys_svc = ampi_link_service(dev, AMPI_SYSTEM_SERVICE, -1);
	req.command = SYS_MALLOC;
	req.data[0] = size;
	ampi_send(sys_svc, &req, sizeof(req), -1);
	ampi_receive(sys_svc, &resp, sizeof(resp), 10000);

	if (resp.result == AMPI_SUCCESS) {
		mem_io = remoteproc_get_io_with_pa(&ampidev->rproc_inst, resp.data[0]);
		if (!mem_io) {
			ERR("The allocated space is not correctly mapped\n");
			return NULL;
		}
		ret = metal_io_phys_to_virt(mem_io, resp.data[0]);
		INFO("malloc end(%d)\n", (int)getpid());
		return ret;
	} else {
		INFO("malloc NULL(%d)\n", (int)getpid());
		return NULL;
	}
}

void ampi_free(ampi_dev dev, void *virt_addr)
{
	ampi_svc sys_svc;
	sys_service_req_t req;
	sys_service_resp_t resp;
	sys_svc = ampi_link_service(dev, AMPI_SYSTEM_SERVICE, -1);
	req.command = SYS_FREE;
	req.data[0] = ampi_virt_to_phys(dev, virt_addr);

	ampi_send(sys_svc, &req, sizeof(req), -1);
	ampi_receive(sys_svc, &resp, sizeof(resp), -1);
}

static uint32_t client_ept_get_add(ampi_dev_priv_t *ampidev)
{
	unsigned int addr = RPMSG_ADDR_ANY;
	unsigned int nextbit;
	metal_mutex_t *mut = &ampidev->rsc_table->client_mut;
	metal_mutex_acquire(mut);

	if (ampidev->rsc_table->client_clean_bitmap) {
		ampidev->rsc_table->client_bitmap &= ~(ampidev->rsc_table->client_clean_bitmap);
		ampidev->rsc_table->client_clean_bitmap = 0;
	}

	nextbit = metal_bitmap_next_clear_bit(&ampidev->rsc_table->client_bitmap, 0, 32);
	if (nextbit < 32) {
		addr = RPMSG_RESERVED_ADDRESSES + nextbit;
		metal_bitmap_set_bit(&ampidev->rsc_table->client_bitmap, nextbit);
	}

	metal_mutex_release(mut);

	return addr;
}

static void client_ept_release_add(ampi_dev_priv_t *ampidev, uint32_t add)
{
	metal_mutex_t *mut = &ampidev->rsc_table->client_mut;
	metal_mutex_acquire(mut);

	add -= RPMSG_RESERVED_ADDRESSES;
	if (add < 32) {
		metal_bitmap_clear_bit(&ampidev->rsc_table->client_bitmap, add);
	}

	metal_mutex_release(mut);
}
