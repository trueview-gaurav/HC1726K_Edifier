#include "ampi.h"
#include "metal/alloc.h"
#include "ampi_default_service.h"
#include "utils/printf.h"

#define INFO(x, ...) printf("[RTOS AMPI INFO]:" x, ##__VA_ARGS__)
#define ERR(x, ...) printf("[RTOS AMPI ERR]:" x, ##__VA_ARGS__)

typedef struct alloc_block {
	void *addr;
	struct alloc_block *next;
} alloc_block_t;

static void system_service_handler(ampi_svc svc, void *data, int len, svc_event_t evn)
{
	sys_service_req_t *req = (sys_service_req_t *)data;
	sys_service_resp_t resp;
	alloc_block_t *head_p = (alloc_block_t *)ampi_get_private(svc);
	alloc_block_t *tmp;

	if (evn == SVC_CLEAN) {
		while (head_p) {
			tmp = head_p;
			head_p = head_p->next;
			INFO("Free addr: 0x%08x\n", (int)tmp->addr);
			metal_free_memory(tmp->addr);
			metal_free_memory(tmp);
		}
		ampi_set_private(svc, head_p);
	} else {
		if (len != sizeof(sys_service_req_t)) {
			resp.result = AMPI_FAILURE;
			return;
		}

		if (req->command == SYS_FREE) {
			if (!head_p) {
				ERR("Freeing without malloc log\n");
				resp.result = AMPI_FAILURE;
			} else {
				if (head_p->addr == (void *)req->data[0]) {
					ampi_set_private(svc, head_p->next);
					INFO("Free addr: 0x%08x\n", req->data[0]);
					metal_free_memory((void *)req->data[0]);
					metal_free_memory(head_p);
					resp.result = AMPI_SUCCESS;
				} else {
					while (head_p->next->addr != (void *)req->data[0] && head_p->next)
						head_p = head_p->next;
					if (head_p->next->addr != (void *)req->data[0]) {
						ERR("Freeing unknown address\n");
						resp.result = AMPI_FAILURE;
					} else {
						tmp = head_p->next;
						INFO("Free addr: 0x%08x\n", req->data[0]);
						INFO("tmp: 0x%08x, heap: 0x%08x, next: 0x%08x\n", (int)tmp, (int)head_p,
						     (int)head_p->next->next);
						head_p->next = head_p->next->next;
						metal_free_memory((void *)req->data[0]);
						metal_free_memory(tmp);
						resp.result = AMPI_SUCCESS;
					}
				}
			}
		} else {
			resp.data[0] = (uint32_t)metal_allocate_memory((unsigned int)req->data[0]);
			INFO("Malloc size: %d, addr: 0x%08x\n", req->data[0], resp.data[0]);

			if (resp.data[0] != 0) {
				resp.result = AMPI_SUCCESS;
				tmp = (alloc_block_t *)metal_allocate_memory(sizeof(alloc_block_t));
				if (!tmp) {
					metal_free_memory((void*)resp.data[0]);
					resp.result = AMPI_FAILURE;
				} else {
					tmp->addr = (void*)resp.data[0];
					tmp->next = NULL;
					if (!head_p) {
						ampi_set_private(svc, tmp);
					} else {
						while (head_p->next)
							head_p = head_p->next;
						head_p->next = tmp;
					}
				}
			} else {
				resp.result = AMPI_FAILURE;
			}
		}
		ampi_send(svc, &resp, sizeof(resp), -1);
	}
}

void create_freertos_sys_service(ampi_dev dev)
{
	ampi_create_service(dev, AMPI_SYSTEM_SERVICE, system_service_handler);
}
