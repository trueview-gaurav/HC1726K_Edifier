#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "utils.h"
#include "hw_gic.h"
#include "address_map.h"

/* TODO: error code duplicates hw_qspi.h */
/* error code */
#define ESUCCESS 0x0
#define ETIMEOUT 0x1
#define EFAIL 0x2
#define EPAGE 0x3
#define ECHKSUM 0x4
#define EDATA 0x5

#define IRQ_STACK_SIZE 128
static char __attribute__((aligned(16))) irq_stack[CPU_NUM][IRQ_STACK_SIZE];

static struct irq_dispatch_s g_irq_dispatch[GIC_MAX_INT_CNT];

static void gic_set_irq_stack(uint32_t stack_irq)
{
	asm volatile(".align\n"
	             "mov r0, pc\n"
	             "bx r0\n"
	             ".arm\n"
	             "__f_switch_into_arm:\n"
	             "push {lr}\n" // Save SVC LR
	             "mov r4, sp\n" // Save SVC stack
	             "msr CPSR_c, #(0x12 | 0x80 | 0x40)\n" // Switch to IRQ context:
	             "mov sp, %0\n" //   Set stack_irq
	             "msr CPSR_c, #(0x13 | 0x80 | 0x40)\n" //   Switch to SVC context
	             "mov sp, r4\n" // Restore SVC stack
	             "add r0, pc, #1\n"
	             "bx r0\n"
	             ".thumb\n"
	             "__f_switch_into_thumb:\n"
	             "pop {lr}\n" // Restore SVC LR
	             :
	             : "r"(stack_irq)
	             : "sp", "r4");
}

static inline uint32_t get_cpu_id(void)
{
	uint32_t mpidr;
	/* Read MPIDR to get CPU ID */
	asm("MRC p15, 0, %0, c0, c0, 5" : "=r"(mpidr));

	// Get affinity
	return (mpidr & 0xFF);
}

/* Per-cpu init */
uint32_t gic_init_per_cpu(void)
{
	uint32_t cpu_id;
	uint32_t stack_irq;
	uint32_t ret;

	cpu_id = get_cpu_id();
	stack_irq = (uint32_t)irq_stack[cpu_id];
	gic_set_irq_stack(stack_irq);

	ret = gicc_set_priority_mask(0xFF);
	if (ret != -ESUCCESS) {
		return ret;
	}
	ret = gicc_set_binary_point(0);
	if (ret != -ESUCCESS) {
		return ret;
	}

	return -ESUCCESS;
}

/* Global init by CPU 0 */
uint32_t gic_init(void)
{
	int i;
	volatile uint32_t *regptr;

	memset(g_irq_dispatch, 0x00, sizeof(g_irq_dispatch));

	/* Enable group 0 & 1 interrupts */
	*gicd_ctlr = 3;

	/* Set-enable all SGIs and PPIs - GICD_ISENABLER0 ~ GICD_ISENABLER8 */
	for (regptr = gicd_isenabler0, i = 0; i < 8; ++i) {
		*regptr++ = 0xFFFFFFFF;
	}

	/* Forward all interrupts to core 0 - GICD_ITARGETSR0 ~ GICD_ITARGETSR63 */
	regptr = gicd_itargetsr0;
	for (regptr = gicd_itargetsr0, i = 0; i < 64; ++i) {
		*regptr++ = 0x01010101;
	}

	/* Enable interrupt signalling of the running core */
	*gicc_ctlr = 1;
	/* Set interrupt priority mask of CPU i/f to lowest */
	*gicc_pmr = 0xFF;

	// Enable CPU IRQ interfaces
	asm volatile("mrs r0, cpsr\n\t" // read from CPSR
	             "bic r0, r0, #0xC0\n\t" // Clear I & F bit
	             "msr cpsr_c, r0" // Write back to CPSR control bits [7:0]
	             ::
	                     : "r0", "cc");

	return -ESUCCESS;
}

uint32_t gicd_set_pending_irq(irqid_t irq_id)
{
	uint32_t reg_offset;
	uint32_t reg_bitshift;

	if (irq_id >= GIC_MAX_INT_CNT) {
		return -EFAIL;
	} else if (irq_id < 16) {
		/* 0-15 are SGIs, which are pended in SPENDSGIRn, and are not handled here */
		return -EFAIL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	*(GICD_ISPENDRN_BASE + reg_offset) = (1 << reg_bitshift);
	return -ESUCCESS;
}

uint32_t gicd_clear_pending_irq(irqid_t irq_id)
{
	uint32_t reg_offset;
	uint32_t reg_bitshift;

	if (irq_id >= GIC_MAX_INT_CNT) {
		return -EFAIL;
	} else if (irq_id < 16) {
		/* 0-15 are SGIs, which are pended in CPENDSGIRn, and are not handled here */
		return -EFAIL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	*(GICD_ICPENDRN_BASE + reg_offset) = (1 << reg_bitshift);
	return -ESUCCESS;
}

bool gicd_is_pending_irq(irqid_t irq_id)
{
	uint32_t reg_offset;
	uint32_t reg_bitshift;
	uint32_t ispendrn;

	if (irq_id >= GIC_MAX_INT_CNT) {
		return false;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	ispendrn = *(GICD_ISPENDRN_BASE + reg_offset);
	return (ispendrn & (1 << reg_bitshift)) ? true : false;
}

bool gicd_is_active_irq(irqid_t irq_id)
{
	uint32_t reg_offset;
	uint32_t reg_bitshift;
	uint32_t isactivern;

	if (irq_id >= GIC_MAX_INT_CNT) {
		return false;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	isactivern = *(GICD_ISACTIVERN_BASE + reg_offset);
	return (isactivern & (1 << reg_bitshift)) ? true : false;
}

int gicd_get_priority(irqid_t irq_id)
{
	uint32_t reg_offset;
	uint32_t reg_bitshift;
	uint32_t itargetsrn;

	if (irq_id >= GIC_MAX_INT_CNT) {
		return -EFAIL;
	}

	// Each byte represents an interrupt source
	reg_offset = irq_id >> 2;
	reg_bitshift = (irq_id & 0x03) << 3;
	itargetsrn = *(GICD_IPRIORITYRN_BASE + reg_offset);
	return (itargetsrn >> reg_bitshift) & 0xFF;
}

int gicd_set_priority(irqid_t irq_id, int priority)
{
	uint32_t reg_offset;
	uint32_t reg_bitshift;
	uint32_t itargetsrn;
	uint32_t reg_mask;

	if (irq_id >= GIC_MAX_INT_CNT) {
		return -EFAIL;
	} else if (priority >= 256) {
		return -EFAIL;
	}

	/* Read from the word field */
	reg_offset = irq_id >> 2;
	itargetsrn = *(GICD_IPRIORITYRN_BASE + reg_offset);

	reg_bitshift = (irq_id & 0x03) << 3;
	reg_mask = (0xFF << reg_bitshift);

	itargetsrn = (itargetsrn & ~reg_mask) | (priority << reg_bitshift);
	*(GICD_IPRIORITYRN_BASE + reg_offset) = itargetsrn;

	return -ESUCCESS;
}

/* seems problematic
uint32_t gicd_enable_irq(irqid_t irq_id)
{
	uint32_t reg_offset;
	uint32_t reg_bitshift;
	if (irq_id >= GIC_MAX_INT_CNT) {
		return -EFAIL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = (irq_id & 0x1F) << 3;
}

uint32_t gicd_disable_irq(irqid_t irq_id)
{
	uint32_t reg_offset;
	uint32_t reg_bitshift;
	if (irq_id >= GIC_MAX_INT_CNT) {
		return -EFAIL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = (irq_id & 0x1F) << 3;
}
*/

/* GICC API */

uint32_t gicc_enable_cpu(void)
{
	// GICC_CTLR enable IRQ
	set_bits_word(gicc_ctlr, 0x1);

	// CPU enable IRQ
	asm("CPSIE i");

	return -ESUCCESS;
}

uint32_t gicc_disable_cpu(void)
{
	// GICC_CTLR disable IRQ
	clr_bits_word(gicc_ctlr, 0x1);

	// CPU disable IRQ
	asm("CPSID i");

	return -ESUCCESS;
}

uint32_t gicc_get_priority_mask(void)
{
	return *gicc_pmr;
}

uint32_t gicc_set_priority_mask(uint32_t priority_mask)
{
	*gicc_pmr = priority_mask;
	return -ESUCCESS;
}

uint32_t gicc_get_binary_point(void)
{
	return *gicc_bpr;
}

uint32_t gicc_set_binary_point(uint32_t binary_point)
{
	*gicc_bpr = binary_point;
	return -ESUCCESS;
}

uint32_t gic_register_isr(irqid_t irq_id, isr_cb_t cb, void *ctx)
{
	if (irq_id >= GIC_MAX_INT_CNT) {
		return -EFAIL;
	}

	g_irq_dispatch[irq_id].callback_fn = cb;
	g_irq_dispatch[irq_id].ctx = ctx;
	return -ESUCCESS;
}

uint32_t gic_unregister_isr(irqid_t irq_id)
{
	if (irq_id >= GIC_MAX_INT_CNT) {
		return -EFAIL;
	}

	g_irq_dispatch[irq_id].callback_fn = NULL;
	g_irq_dispatch[irq_id].ctx = NULL;
	return -ESUCCESS;
}

uint32_t gic_request_sgi(uint32_t id, uint32_t cpu)
{
	if (id >= 16 || cpu >= 2)
		return -EFAIL;
	*gicd_sgir = ((0x0 << 24) | (0x01 << (16 + cpu)) | (id << 0));
}

/* IRQ handler for FreeRTOS
 * Reads GICCIAR to get ID, and invokes corresponding IRQ handler callback */
void gic_irq_handler(uint32_t gicc_iar_val)
{
	uint32_t irq_id = GICC_IAR_TO_IRQID(gicc_iar_val);

	if (irq_id < GIC_MAX_INT_CNT) {
		if (g_irq_dispatch[irq_id].callback_fn) {
			g_irq_dispatch[irq_id].callback_fn(gicc_iar_val, g_irq_dispatch[irq_id].ctx);
		} else {
			dprintf("[error]: irq %d not registered!\n", irq_id);
		}
	} else {
		dprintf("[error]: irq %d not registered!\n", irq_id);
	}

	// eoi
	*gicc_eoir = gicc_iar_val;
}

/* Architectural IRQ handler
 * Reads GICCIAR to get ID, and invokes corresponding IRQ handler callback */
void arch_irq_handler(void)
{
	uint32_t irq_id;
	gic_irq_handler(*gicc_iar);
}

void arch_wakeup_secondary_core(void *addr)
{
	volatile uint32_t *sec_boot_addr = (volatile uint32_t *)0x80000814;
	*sec_boot_addr = (uint32_t)addr;
	//	*gicd_sgir = ((0x0 << 24) | (0x2 << 16) | (0x0 << 0));
	gic_request_sgi(0, 1);
}
