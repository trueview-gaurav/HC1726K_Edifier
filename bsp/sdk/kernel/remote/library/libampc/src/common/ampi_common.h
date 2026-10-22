#ifndef AMPI_COMMON_H_
#define AMPI_COMMIN_H_

#define HAND_SHAKE_KEY 0xABCDEF

/* External functions */
extern int amp_init_system(void);
extern void amp_cleanup_system(void);

typedef struct msg_buf {
	void *data;
	size_t len;
	struct msg_buf *next;
} msg_buf_t;

typedef struct link {
	struct rpmsg_endpoint ept;
	uint8_t connected;
	msg_buf_t *msg;
	void *priv;
	int idle_cnt;
} link_t;

typedef struct service {
	char *name;
	uint8_t registed;
	svc_handler handler;
} service_t;

typedef struct ampi_dev_priv {
	struct remoteproc rproc_inst;
	struct rpmsg_virtio_shm_pool shpool;
	struct rpmsg_virtio_device rpmsg_vdev;
	struct remote_resource_table *rsc_table;
	link_t links[AMPI_MAX_LINK_NUMBER];
	service_t services[AMPI_MAX_SERVICE_NUMBER];
} ampi_dev_priv_t;

static ampi_dev_priv_t ampi_handle[AMPI_DEV_NUMBER];

static void __attribute__((unused)) tick_link(ampi_dev_priv_t *ampidev)
{
	int i;
	int dummy;
	service_t *svc;

	for (i = 0; i < AMPI_MAX_LINK_NUMBER; i++) {
		if (ampidev->links[i].connected == 1) {
			ampidev->links[i].idle_cnt++;
			if (ampidev->links[i].idle_cnt == 10) {
				//INFO("Query %d, %s\n", i, ampidev->links[i].ept.name);
				rpmsg_send(&ampidev->links[i].ept, &dummy, 0);
			}
			if (ampidev->links[i].idle_cnt > 20) {
				svc = (service_t *)ampidev->links[i].ept.priv;
				INFO("Timeout %d, %s\n", i, ampidev->links[i].ept.name);
				ampi_unlink_service((ampi_svc)&ampidev->links[i]);
				svc->handler((ampi_svc)&ampidev->links[i], NULL, 0, SVC_CLEAN);
			}
		}
	}
}

static int rpmsg_client_cb(struct rpmsg_endpoint *ept, void *data, size_t len, uint32_t src,
                           void *priv __attribute__((unused)))
{
	link_t *link = metal_container_of(ept, link_t, ept);
	(void)src;

	if (len == 0) {
		//INFO("Response %s\n", ept->name);
		rpmsg_send(ept, data, 0);
		return RPMSG_SUCCESS;
	}

	msg_buf_t *new_msg = metal_allocate_memory(sizeof(msg_buf_t));
	if (!new_msg) {
		ERR("Buffering msg fail\n");
		return RPMSG_SUCCESS;
	}
	new_msg->data = data;
	new_msg->len = len;
	new_msg->next = NULL;
	rpmsg_hold_rx_buffer(ept, data);

	msg_lock();
	msg_buf_t **msg_tail = &link->msg;
	while (*msg_tail != NULL)
		msg_tail = &((*msg_tail)->next);
	*msg_tail = new_msg;
	msg_unlock();

	return RPMSG_SUCCESS;
}

static int rpmsg_server_cb(struct rpmsg_endpoint *ept, void *data, size_t len, uint32_t src, void *priv)
{
	service_t *svc = (service_t *)priv;
	link_t *link = metal_container_of(ept, link_t, ept);
	(void)src;

	link->idle_cnt = 0;
	if (len == 0) {
		return RPMSG_SUCCESS;
	}

	if (svc->registed != 1)
		ERR("Receive msg to unregisted service\n");

	if (svc->handler)
		svc->handler((ampi_svc)link, data, len, SVC_REQUEST);
	else
		ERR("Service without handler\n");

	return RPMSG_SUCCESS;
}

static link_t *find_link_by_name(ampi_dev_priv_t *ampidev, char *name)
{
	int i;
	for (i = 0; i < AMPI_MAX_LINK_NUMBER; i++) {
		if (strncmp(ampidev->links[i].ept.name, name, strlen(name)) == 0)
			return &ampidev->links[i];
	}
	return NULL;
}

static link_t *find_empty_link_and_mark(ampi_dev_priv_t *ampidev)
{
	int i;
	for (i = 0; i < AMPI_MAX_LINK_NUMBER; i++) {
		if (ampidev->links[i].connected == 0) {
			ampidev->links[i].connected = 1;
			ampidev->links[i].priv = NULL;
			return &ampidev->links[i];
		}
	}
	return (link_t *)AMPI_FAILURE;
}

static void rpmsg_service_unbind_cb(struct rpmsg_endpoint *ept)
{
	link_t *link = metal_container_of(ept, link_t, ept);
	struct msg_buf *msg;

	INFO("link disconnected: %s\r\n", (char *)(ept->name));

	msg_lock();
	while (link->msg != NULL) {
		rpmsg_release_rx_buffer(&link->ept, link->msg->data);
		msg = link->msg;
		link->msg = link->msg->next;
		metal_free_memory(msg);
	}
	msg_unlock();

	link->connected = 0;
	rpmsg_destroy_ept(ept);
}

static void rpmsg_service_link_cb(struct rpmsg_device *rdev, const char *name, uint32_t dest)
{
	link_t *link;
	int i;
	int sync = HAND_SHAKE_KEY;
	struct rpmsg_virtio_device *rpvdev = metal_container_of(rdev, struct rpmsg_virtio_device, rdev);
	ampi_dev_priv_t *ampidev = metal_container_of(rpvdev, ampi_dev_priv_t, rpmsg_vdev);
	INFO("new link request is received: %s, dest: %d\r\n", name, dest);

	for (i = 0; i < AMPI_MAX_SERVICE_NUMBER; i++) {
		if (ampidev->services[i].registed == 1) {
			if (strncmp(name, ampidev->services[i].name, strlen(ampidev->services[i].name)) == 0)
				break;
		}
	}
	if (i == AMPI_MAX_SERVICE_NUMBER) {
		ERR("Unknow service name\n");
		return;
	}

	link = find_empty_link_and_mark(ampidev);
	if ((int)link == AMPI_FAILURE) {
		WARN("There %d links exist, no space for new link\n", AMPI_MAX_LINK_NUMBER);
		return;
	}

	rpmsg_create_ept(&link->ept, rdev, name, RPMSG_ADDR_ANY, dest, rpmsg_server_cb, rpmsg_service_unbind_cb);
	link->ept.priv = &ampidev->services[i];
	link->idle_cnt = 0;

	if (rpmsg_send(&link->ept, &sync, sizeof(int)) < 0) {
		ERR("init rpmsg_send failed\r\n");
	}
}

void ampi_deinit(ampi_dev dev)
{
	ampi_dev_priv_t *ampidev = (ampi_dev_priv_t *)dev;
	int i;

	for (i = 0; i < AMPI_MAX_LINK_NUMBER ; i++) {
		if (ampidev->links[i].connected == 1)
			ampi_unlink_service((ampi_svc)&ampidev->links[i]);
	}

	remoteproc_stop(&ampidev->rproc_inst);

	rpmsg_deinit_vdev(&ampidev->rpmsg_vdev);
	remoteproc_remove_virtio(&ampidev->rproc_inst, ampidev->rpmsg_vdev.vdev);
	remoteproc_remove(&ampidev->rproc_inst);

	amp_cleanup_system();
}

int ampi_create_service(ampi_dev dev, char *svc_name, svc_handler handler)
{
	ampi_dev_priv_t *ampidev = (ampi_dev_priv_t *)dev;
	service_t *svc;
	int i;

	for (i = 0; i < AMPI_MAX_SERVICE_NUMBER; i++) {
		if (ampidev->services[i].registed == 0) {
			ampidev->services[i].registed = 1;
			svc = &ampidev->services[i];
			break;
		}
	}
	if (i == AMPI_MAX_SERVICE_NUMBER) {
		ERR("Register service fail, no space left\n");
		return AMPI_FAILURE;
	}

	svc->name = svc_name;
	svc->handler = handler;
	return AMPI_SUCCESS;
}

int ampi_send(ampi_svc svc, void *data, size_t len, int timeout)
{
	(void)timeout;
	link_t *link = (link_t *)svc;
	int ret;
	ret = rpmsg_send(&link->ept, data, len);
	if (ret < 0)
		return AMPI_FAILURE;
	else
		return AMPI_SUCCESS;
}

void *ampi_get_private(ampi_svc service)
{
	link_t *link = (link_t *)service;
	return link->priv;
}

void ampi_set_private(ampi_svc service, void *priv)
{
	link_t *link = (link_t *)service;
	link->priv = priv;
}

#endif
