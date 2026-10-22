#include <stdint.h>
#include <string.h>
#include "utils/printf.h"
#include "intc/hw_gic.h"
#include "uart.h"
#include "amp_driver.h"
#include "amp_early_chann.h"

#include "common/config.h"

#define SHM_ADDR AMP_DRIVER_SHM_ADDR
#define PRINT_BUFF_SIZE (2048)

#ifdef CONFIG_FASTBOOT
struct amp_early_handle handles[] = AMP_EARLY_CHANN_HANDLE_LIST;
#endif

struct amp_early_channel {
	int32_t busy;
	int32_t request;
	int32_t response;
	void *data;
};

struct shm_header {
	volatile struct amp_early_channel chann;
	volatile uint32_t print_head;
	volatile uint32_t print_tail;
	volatile uint32_t sync_flag;
	volatile char print_buf[PRINT_BUFF_SIZE];
};

struct shm_header *g_shm_p = (struct shm_header *)SHM_ADDR;
static bool shm_inited = false;
#if LOW_LEVEL_LOG
struct uart_dev uart0 = { .base_addr = UART0_BASE_ADDR };
#endif

void _put_buff(char c)
{
	if (!shm_inited) {
#if LOW_LEVEL_LOG
		uart_transmit(&uart0, 1, (uint8_t *)&c);
#endif
	} else if (((g_shm_p->print_head + 1) & (PRINT_BUFF_SIZE - 1)) != g_shm_p->print_tail) {
		g_shm_p->print_buf[g_shm_p->print_head] = c;
		g_shm_p->print_head++;
		g_shm_p->print_head &= (PRINT_BUFF_SIZE - 1);
	}
}

void _putchar(char character)
{
	if (character == '\n') {
		_put_buff('\r');
		_put_buff('\n');
		if (shm_inited)
			gic_request_sgi(0, 1);
	} else {
		_put_buff(character);
	}
}

#ifdef CONFIG_FASTBOOT
void early_chann_handler(uint32_t iar, void *data)
{
	int32_t ret;

	if (g_shm_p->chann.request < AMP_EARLY_TYPE_NUM) {
		ret = handles[g_shm_p->chann.request].handler(g_shm_p->chann.data);
	} else {
		printf("unknow request\n");
		ret = -1;
	}
	g_shm_p->chann.response = ret;
	g_shm_p->chann.busy = 0;
}
#endif

void amp_drv_init(void)
{
	g_shm_p->print_head = 0;
	g_shm_p->print_tail = 0;
	g_shm_p->sync_flag = 0;
	memset((void *)g_shm_p->print_buf, 0, PRINT_BUFF_SIZE);

#ifdef CONFIG_FASTBOOT
	gic_register_isr(2, early_chann_handler, NULL);
#endif

	// Enable interrupt to receive SGI signal
	gicc_enable_cpu();

	while (g_shm_p->sync_flag != 1) {
	}
	g_shm_p->sync_flag = 2;
	shm_inited = true;
}


