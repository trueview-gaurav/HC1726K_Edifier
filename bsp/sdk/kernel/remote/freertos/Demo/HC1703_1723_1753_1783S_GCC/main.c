/* Standard includes. */
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* CPVS header includes */
#include "utils/printf.h"
#include "mmu/mmu.h"
#include "cpu/cpu.h"
#include "intc/hw_gic.h"
#include "ca7_timer/ca7_timer.h"
#include "mem_config.h"
#include "amp_driver/amp_driver.h"
#include "amp_early_chann.h"

#include "metal/time.h"
#include <metal/sleep.h>

#define AGTX_TASK_NUM 1
#define AGTX_TASK_STACK_SZ (256 * 1024)
#define AGTX_TOTAL_HEAP_STACK_SZ_KB (configTOTAL_HEAP_SIZE / 1024)
#define AGTX_Q_RECV_TASK_PRI (tskIDLE_PRIORITY + 2)
#define AGTX_Q_SEND_FREQ_MS (30000 / portTICK_PERIOD_MS)
#define AGTX_Q_LEN (1)
#define AGTX_Q_SEND_VAL 100UL
#define AGTX_STATIC_Q_LEN_IN_ITEMS (5)
#define AGTX_CPU_CYCLES_PER_TICKS (configCPU_CLOCK_HZ / configTICK_RATE_HZ)
#define AGTX_PORT_LOWEST_ISR_PRI (portLOWEST_USABLE_INTERRUPT_PRIORITY << portPRIORITY_SHIFT)
#define AGTX_TIMER_IRQ IRQ_ID_CA7_TIMER
#define AGTX_ASCII_LOWER_A 'a'
#define AGTX_ASCII_LOWER_Z 'z'
#define AGTX_CASE_DIFF ('A' - 'a')
#define AGTX_STACK_INIT_BYTE 0xA5
#define AGTX_TASK_NAME_RX "Rx"
#define AGTX_TEST_FLOAT_VAL 1.234f
#define AGTX_TEST_FLOAT_STR "1.234"
#define AGTX_TMP_BUF_SZ 20
#define AGTX_ALIGN_16 16
#define AGTX_ALIGN_32 32

extern int rpmsg_md(int argc, char *argv[]);
extern int rpmsg_echo(int argc, char *argv[]);
extern int rpmsg_echo_ampi();

static void agtx_prv_q_recv_task(void *pvParameters);
static void agtx_prv_q_send_task(void *pvParameters);

static QueueHandle_t agtx_Q = NULL;
static StaticQueue_t agtx_static_Q;
static TaskHandle_t agtx_created_task = NULL;
static StackType_t __attribute__((aligned(AGTX_ALIGN_32))) agtx_stack_buf[AGTX_TASK_NUM][AGTX_TASK_STACK_SZ];
static StaticTask_t agtx_TCB_buf[AGTX_TASK_NUM];
static int agtx_tick_handled = 0;
static uint8_t agtx_Q_storage_area[AGTX_STATIC_Q_LEN_IN_ITEMS * sizeof(uint64_t)];

static void agtx_prv_q_send_task(void *pvParameters)
{
	TickType_t next_wake_t;
	const unsigned long ul_val_to_send = AGTX_Q_SEND_VAL;
	(void)pvParameters;

	printf("SEND: start\n");

	next_wake_t = xTaskGetTickCount();
	while (1) {
		vTaskDelayUntil(&next_wake_t, AGTX_Q_SEND_FREQ_MS);
		printf("SEND: Sends wakeup val\n");
		xQueueSend(agtx_Q, &ul_val_to_send, 0U);
	}
}

static void agtx_prv_q_recv_task(void *pvParameters)
{
	unsigned long ul_recv_val;
	(void)pvParameters;

	printf("RECV: start\n");

	rpmsg_echo_ampi();
	xQueueSend(agtx_Q, &ul_recv_val, 0U);

	while (1) {
		xQueueReceive(agtx_Q, &ul_recv_val, portMAX_DELAY);
		printf("RECV: Value: %d.\n", ul_recv_val);
	}
}

void vAssertCalled(const char *pcFile, unsigned long ulLine)
{
	printf("Assert: failed with file %s, line %d\n", pcFile, ulLine);

	do {
	} while (1);
}

void vClearTickInterrupt(void)
{
	++agtx_tick_handled;
	ca7_timer_set_counter(AGTX_CPU_CYCLES_PER_TICKS);
	ca7_timer_start();
}

void vConfigureTickInterrupt(void)
{
	printf("Tick ISR: Clock %d, cnt %d\n", __func__, configCPU_CLOCK_HZ, AGTX_CPU_CYCLES_PER_TICKS);

	ca7_timer_init(configCPU_CLOCK_HZ);
	ca7_timer_set_counter(AGTX_CPU_CYCLES_PER_TICKS);
	gic_register_isr(AGTX_TIMER_IRQ, (isr_cb_t)FreeRTOS_Tick_Handler, NULL);
	gicd_set_priority(AGTX_TIMER_IRQ, AGTX_PORT_LOWEST_ISR_PRI);
	ca7_timer_start();

	printf("Tick ISR: Initilize timer done\n");
}

void vApplicationTickHook(void)
{
	printf("[vApplicationTickHook]: Not completed yet\n");
#if (mainSELECTED_APPLICATION == 1)
	{
		vTimerPeriodicISRTests();
		vQueueOverwritePeriodicISRDemo();
		vPeriodicEventGroupsProcessing();
		xNotifyTaskFromISR();
		vInterruptSemaphorePeriodicTest();
		vPeriodicStreamBufferProcessing();
		vBasicStreamBufferSendFromISR();

#if (configUSE_QUEUE_SETS == 1)
		{
			vQueueSetAccessQueueSetFromISR();
		}
#endif // configUSE_QUEUE_SETS
#if (configASSERT_DEFINED == 1)
		{
			char tmp_buf[AGTX_TMP_BUF_SZ];
			UBaseType_t ux_saved_isr_status;

			ux_saved_isr_status = portSET_INTERRUPT_MASK_FROM_ISR();
			{
				sprintf(tmp_buf, "%1.3f", AGTX_TEST_FLOAT_VAL);
			}
			portCLEAR_INTERRUPT_MASK_FROM_ISR(ux_saved_isr_status);
			configASSERT(0 == strcmp(tmp_buf, AGTX_TEST_FLOAT_STR));
		}
#endif // configASSERT_DEFINED
	}
#endif // mainSELECTED_APPLICATION
}

uint32_t string_capital(void *data)
{
	char *str = data;

	while (*str) {
		if (*str >= AGTX_ASCII_LOWER_A && *str <= AGTX_ASCII_LOWER_Z) {
			*str += AGTX_CASE_DIFF;
		}
		str++;
	}

	return (uint32_t)(str - (char *)data);
}

void vRegisterIRQHandler(irqid_t ulID, isr_cb_t pxHandlerFunction, void *pvContext)
{
	gic_register_isr(ulID, pxHandlerFunction, pvContext);
}

void vApplicationIRQHandler(uint32_t ulICCIAR)
{
	gic_irq_handler(ulICCIAR);
}

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize)
{
	static StaticTask_t timer_tcb;
	static StackType_t __attribute__((aligned(AGTX_ALIGN_16))) timer_stack[configTIMER_TASK_STACK_DEPTH];

	*ppxTimerTaskTCBBuffer = &timer_tcb;
	*ppxTimerTaskStackBuffer = timer_stack;
	*pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;

	printf("Timer stack: %p, TCB buf: %p\n", &timer_stack, &timer_tcb);
}

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize)
{
	static StaticTask_t idle_tcb;
	static StackType_t __attribute__((aligned(AGTX_ALIGN_16))) idle_stack[configMINIMAL_STACK_SIZE];

	*ppxIdleTaskTCBBuffer = &idle_tcb;
	*ppxIdleTaskStackBuffer = idle_stack;
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;

	printf("Idle stack: %p, TCB buf: %p\n", &idle_stack, &idle_tcb);
}

int main(void)
{
	int i, j;

	gic_init_per_cpu();
	mmu_config();
	dcache_enable();
	gicd_set_priority(0, AGTX_PORT_LOWEST_ISR_PRI);

#if LOW_LEVEL_LOG != 0
	printf("===== Augentix FreeRTOS Port =====\n");
#endif
	amp_drv_init();

	for (i = 0; i < AGTX_TASK_NUM; i++) {
		for (j = 0; j < AGTX_TASK_STACK_SZ; j++) {
			agtx_stack_buf[i][j] = AGTX_STACK_INIT_BYTE;
		}
	}

	printf("Heap SZ (KB): %d\n", AGTX_TOTAL_HEAP_STACK_SZ_KB);
	agtx_Q = xQueueCreateStatic(AGTX_Q_LEN, sizeof(uint32_t), agtx_Q_storage_area, &agtx_static_Q);
	if (NULL != agtx_Q) {
		xTaskCreateStatic(agtx_prv_q_recv_task, AGTX_TASK_NAME_RX, AGTX_TASK_STACK_SZ, NULL,
		                  AGTX_Q_RECV_TASK_PRI, &(agtx_stack_buf[0][0]), &agtx_TCB_buf[0]);
		printf("RX stack: %p, TCB buf: %p\n", &(agtx_stack_buf[0][0]), &agtx_TCB_buf[0]);
		vTaskStartScheduler();
	}

	printf("ERR: Reach main exit entry\n");

	do {
	} while (1);

	return 0;
}

