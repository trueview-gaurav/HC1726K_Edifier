/*
 * U-Boot GIC (Generic Interrupt Controller) Implementation
 * ARMv7 hc1703_1723_1753_1783s Platform
 * 
 * Copyright (C) 2025 Augentix Inc.
 * Author: Will.Chuang (im327)
 * 
 * This file implements a complete GIC driver for U-Boot with all SPL GIC
 * functionality consolidated and enhanced. Provides comprehensive interrupt
 * management including pending/priority control, CPU interface management,
 * and multi-core SGI support.
 */

#include <config.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <irq_func.h>
#include <linux/errno.h>
#include <asm/global_data.h>
#include <asm/proc-armv/ptrace.h>
#include <asm/u-boot-arm.h>
#include <mach/uboot_gic.h>

DECLARE_GLOBAL_DATA_PTR;

#define CONFIG_UBOOT_GIC_IRQ_STACK

#ifdef CONFIG_UBOOT_GIC_IRQ_STACK
#define CPU_NUM 2

/* Per-CPU IRQ stacks */
static char __attribute__((aligned(16))) uboot_irq_stack[CPU_NUM][CFG_STACKSIZE_IRQ];

/* ARM CPU mode definitions */
#define ARM_MODE_IRQ (0x12 | 0x80 | 0x40)
#define ARM_MODE_SVC (0x13 | 0x80 | 0x40)

/**
 * arch_set_irq_stack() - Configure IRQ stack for current CPU
 * @stack_top: Stack top pointer
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
__attribute__((target("arm"))) void arch_set_irq_stack(void *stack_top)
{
	asm volatile("push {r4, lr}\n\t"
	             "mov r4, sp\n\t"
	             "msr CPSR_c, %[irq_mode]\n\t"
	             "mov sp, %[stack_ptr]\n\t"
	             "msr CPSR_c, %[svc_mode]\n\t"
	             "mov sp, r4\n\t"
	             "pop {r4, pc}\n\t"
	             :
	             : [stack_ptr] "r"(stack_top), [irq_mode] "I"(ARM_MODE_IRQ), [svc_mode] "I"(ARM_MODE_SVC)
	             : "memory", "cc");
}
#pragma GCC diagnostic pop
#endif

/* U-Boot IRQ handler table */
static struct gic_irq_entry {
	interrupt_handler_t *handler;
	void *arg;
} gic_irq_table[MAX_IRQS];

static bool gic_ready;

/**
 * arch_get_cpu_id() - Get current CPU ID
 * Return: CPU ID (0-1 for dual-core systems)
 */
static inline uint32_t arch_get_cpu_id(void)
{
	uint32_t mpidr;
	asm("MRC p15, 0, %0, c0, c0, 5" : "=r"(mpidr));
	return (mpidr & 0xFF);
}

/**
 * arch_irq_save() - Disable IRQs and save CPSR
 * Return: CPSR value before disabling IRQs
 */
static inline unsigned long arch_irq_save(void)
{
	unsigned long flags;
	asm volatile("mrs %0, cpsr; cpsid i" : "=r"(flags)::"memory", "cc");
	return flags;
}

/**
 * arch_irq_restore() - Restore CPSR
 * @flags: CPSR value to restore
 */
static inline void arch_irq_restore(unsigned long flags)
{
	asm volatile("msr cpsr_c, %0" : : "r"(flags) : "memory", "cc");
}

/* === IRQ CONTROL FUNCTIONS === */

/**
 * uboot_gic_enable_irq() - Enable IRQ in GIC
 * @irq_id: IRQ number to enable
 * Return: 0 on success, -EINVAL on invalid IRQ
 */
int uboot_gic_enable_irq(uint32_t irq_id)
{
	uint32_t reg_offset, reg_bitshift;

	if (irq_id >= MAX_IRQS) {
		printf("GIC: Invalid IRQ %u for enable\n", irq_id);
		return -EINVAL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	*(GICD_ISENABLER_BASE + reg_offset) = (1 << reg_bitshift);
	return 0;
}

/**
 * uboot_gic_disable_irq() - Disable IRQ in GIC
 * @irq_id: IRQ number to disable
 * Return: 0 on success, -EINVAL on invalid IRQ
 */
int uboot_gic_disable_irq(uint32_t irq_id)
{
	uint32_t reg_offset, reg_bitshift;

	if (irq_id >= MAX_IRQS) {
		printf("GIC: Invalid IRQ %u for disable\n", irq_id);
		return -EINVAL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	*(GICD_ICENABLER_BASE + reg_offset) = (1 << reg_bitshift);
	return 0;
}

/* === GIC INITIALIZATION FUNCTIONS === */

/**
 * uboot_gic_distributor_init() - Initialize GIC distributor
 */
static inline void uboot_gic_distributor_init(void)
{
	uint32_t i = 0, cpu_id = arch_get_cpu_id();
	const uint32_t num_regs_32 = (MAX_IRQS + 31) / 32;
	const uint32_t num_regs_16 = (MAX_IRQS + 15) / 16;

	//printf("GIC: Initializing distributor...\n");

	/* Disable distributor during configuration */
	GICD_CTLR = 0;

	/* Disable all interrupts and clear pending states */
	for (i = 0; i < num_regs_32; i++) {
		*(GICD_ICENABLER_BASE + i) = 0xFFFFFFFF;
		*(GICD_ICPENDR_BASE + i) = 0xFFFFFFFF;
	}

	/* Set default priority (0xA0) for all interrupts */
	for (i = 0; i < MAX_IRQS; i++) {
		*(GICD_IPRIORITYR_BASE + i) = 0xA0;
	}

	/* Route all SPIs to CPU0 | CPU1 */
	for (i = 32; i < MAX_IRQS; i++) {
		*(GICD_ITARGETSR_BASE + i) = (0x1 << cpu_id);
	}

	/* Configure all SPIs as level-triggered */
	for (i = 2; i < num_regs_16; i++) {
		*(GICD_ICFGR_BASE + i) = 0x00000000;
	}

	/* Enable distributor */
	GICD_CTLR = 3;
	//printf("GIC: Distributor initialized\n");
}

/**
 * uboot_gic_per_cpu_init() - Initialize GIC CPU interface
 */
static inline void uboot_gic_per_cpu_init(void)
{
	uint32_t cpu_id = arch_get_cpu_id();
	void *stack_top = &uboot_irq_stack[cpu_id][CFG_STACKSIZE_IRQ];

	/* Setup IRQ stack */
	arch_set_irq_stack(stack_top);
	//printf("GIC: IRQ stack set for CPU %u at 0x%p\n", cpu_id, stack_top);
	/* Disable CPU interface during configuration */
	GICC_CTLR = 0;

	/* Set priority mask to accept all interrupts */
	GICC_PMR = 0xFF;

	/* Set binary point for priority grouping */
	GICC_BPR = 7;

	/* Enable CPU interface */
	GICC_CTLR = 3;
	//printf("GIC: CPU interface initialized for CPU %u\n", cpu_id);
}

/**
 * arch_gic_dispatch_irq() - IRQ dispatch handler
 * @iar_val: Interrupt acknowledge register value
 */
void arch_gic_dispatch_irq(uint32_t iar_val)
{
	uint32_t irq_id = iar_val & 0x3FF;

	if (irq_id >= 1022) {
		printf("GIC: Spurious IRQ %u\n", irq_id);
	} else if (irq_id < MAX_IRQS && gic_irq_table[irq_id].handler) {
		gic_irq_table[irq_id].handler(gic_irq_table[irq_id].arg);
	} else {
		printf("GIC: Unhandled IRQ %u\n", irq_id);
	}

	GICC_EOIR = iar_val;
}

/**
 * do_irq() - Main IRQ handler for the platform
 * @pt_regs: Pointer to register structure
 *
 * This function overrides the weak do_irq in arch/arm/lib/interrupts.c.
 * It reads the interrupt acknowledge register and calls the dispatch function.
 */
void do_irq(struct pt_regs *pt_regs)
{
	uint32_t iar_val;
	uint32_t irq_id;

	iar_val = GICC_IAR;
	irq_id = iar_val & 0x3FF;

	if (irq_id >= 1022) {
		printf("IRQ: Spurious interrupt detected (ID=%u)\n", irq_id);
		return;
	}

	arch_gic_dispatch_irq(iar_val);
}

/**
 * agtx_gic_init() - Initialize interrupt system
 */
void agtx_gic_init(void)
{
	if (gic_ready)
		return;
	gic_ready = true;

	memset(gic_irq_table, 0, sizeof(gic_irq_table));

	uboot_gic_distributor_init();
	uboot_gic_per_cpu_init();

	/* vectors.S scratches two words at IRQ_STACK_START_IN. interrupt_init()
	 * sets it, but runs long after board_init() where FastBoot inits the GIC.
	 */
#ifndef CONFIG_XPL_BUILD
	IRQ_STACK_START_IN = gd->irq_sp + 8;
#endif

	/* Enable IRQs at CPU level */
	asm volatile("mrs r0, cpsr\n\t"
	             "bic r0, r0, #0x80\n\t"
	             "msr cpsr_c, r0"
	             :
	             :
	             : "r0", "cc");

	printf("IRQ:	ready\n");
}

/* === IRQ HANDLER MANAGEMENT === */

/**
 * irq_install_handler() - Install IRQ handler
 * @vec: IRQ number
 * @handler: Handler function
 * @arg: Handler argument
 */
void irq_install_handler(int vec, interrupt_handler_t *handler, void *arg)
{
	unsigned long flags;

	if (vec < 0 || vec >= MAX_IRQS || !handler) {
		printf("GIC: bad install, IRQ %d\n", vec);
		return;
	}

	agtx_gic_init();

	flags = arch_irq_save();
	gic_irq_table[vec].handler = handler;
	gic_irq_table[vec].arg = arg;
	arch_irq_restore(flags);

	uboot_gic_enable_irq(vec);
}

/**
 * irq_free_handler() - Remove IRQ handler
 * @vec: IRQ number
 */
void irq_free_handler(int vec)
{
	unsigned long flags;

	if (vec < 0 || vec >= MAX_IRQS) {
		printf("GIC: IRQ %d out of range\n", vec);
		return;
	}

	uboot_gic_disable_irq(vec);

	flags = arch_irq_save();
	gic_irq_table[vec].handler = NULL;
	gic_irq_table[vec].arg = NULL;
	arch_irq_restore(flags);
}

/* === IRQ PRIORITY MANAGEMENT === */

/**
 * uboot_gic_get_priority() - Get IRQ priority
 * @irq_id: IRQ number
 * Return: Priority (0-255) on success, negative errno on failure
 */
int uboot_gic_get_priority(uint32_t irq_id)
{
	uint32_t reg_offset, reg_bitshift;
	uint32_t ipriorityrn;

	if (irq_id >= MAX_IRQS) {
		printf("GIC: Invalid IRQ %u for get_priority\n", irq_id);
		return -EINVAL;
	}

	reg_offset = irq_id >> 2;
	reg_bitshift = (irq_id & 0x03) << 3;
	ipriorityrn = *(GICD_IPRIORITYR_BASE + reg_offset);

	return (ipriorityrn >> reg_bitshift) & 0xFF;
}

/**
 * uboot_gic_set_priority() - Set IRQ priority
 * @irq_id: IRQ number
 * @priority: Priority (0-255, lower = higher priority)
 * Return: 0 on success, negative errno on failure
 */
int uboot_gic_set_priority(uint32_t irq_id, uint8_t priority)
{
	uint32_t reg_offset, reg_bitshift;
	uint32_t ipriorityrn, reg_mask;

	if (irq_id >= MAX_IRQS) {
		printf("GIC: Invalid IRQ %u for set_priority\n", irq_id);
		return -EINVAL;
	}

	reg_offset = irq_id >> 2;
	ipriorityrn = *(GICD_IPRIORITYR_BASE + reg_offset);

	reg_bitshift = (irq_id & 0x03) << 3;
	reg_mask = (0xFF << reg_bitshift);

	ipriorityrn = (ipriorityrn & ~reg_mask) | (priority << reg_bitshift);
	*(GICD_IPRIORITYR_BASE + reg_offset) = ipriorityrn;

	return 0;
}

/* === IRQ PENDING STATE MANAGEMENT === */

/**
 * uboot_gic_set_pending() - Set IRQ pending
 * @irq_id: IRQ number
 * Return: 0 on success, negative errno on failure
 */
int uboot_gic_set_pending(uint32_t irq_id)
{
	uint32_t reg_offset, reg_bitshift;

	if (irq_id >= MAX_IRQS) {
		printf("GIC: Invalid IRQ %u for set_pending\n", irq_id);
		return -EINVAL;
	} else if (irq_id < 16) {
		printf("GIC: SGI IRQ %u cannot be set pending via ISPENDR\n", irq_id);
		return -EINVAL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	*(GICD_ISPENDR_BASE + reg_offset) = (1 << reg_bitshift);
	return 0;
}

/**
 * uboot_gic_clear_pending() - Clear IRQ pending
 * @irq_id: IRQ number
 * Return: 0 on success, negative errno on failure
 */
int uboot_gic_clear_pending(uint32_t irq_id)
{
	uint32_t reg_offset, reg_bitshift;

	if (irq_id >= MAX_IRQS) {
		printf("GIC: Invalid IRQ %u for clear_pending\n", irq_id);
		return -EINVAL;
	} else if (irq_id < 16) {
		printf("GIC: SGI IRQ %u cannot be cleared pending via ICPENDR\n", irq_id);
		return -EINVAL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	*(GICD_ICPENDR_BASE + reg_offset) = (1 << reg_bitshift);
	return 0;
}

/**
 * uboot_gic_is_pending() - Check if IRQ is pending
 * @irq_id: IRQ number
 * Return: 1 if pending, 0 if not, negative errno on failure
 */
int uboot_gic_is_pending(uint32_t irq_id)
{
	uint32_t reg_offset, reg_bitshift;
	uint32_t ispendrn;

	if (irq_id >= MAX_IRQS) {
		printf("GIC: Invalid IRQ %u for is_pending\n", irq_id);
		return -EINVAL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	ispendrn = *(GICD_ISPENDR_BASE + reg_offset);
	return (ispendrn & (1 << reg_bitshift)) ? 1 : 0;
}

/**
 * uboot_gic_is_active() - Check if IRQ is active
 * @irq_id: IRQ number
 * Return: 1 if active, 0 if not, -EINVAL on invalid IRQ
 */
int uboot_gic_is_active(uint32_t irq_id)
{
	uint32_t reg_offset, reg_bitshift;

	if (irq_id >= MAX_IRQS) {
		printf("GIC: Invalid IRQ %u for is_active\n", irq_id);
		return -EINVAL;
	}

	reg_offset = irq_id >> 5;
	reg_bitshift = irq_id & 0x1F;

	return (*(GICD_ISACTIVER_BASE + reg_offset) >> reg_bitshift) & 1;
}

/* === CPU INTERFACE MANAGEMENT === */

/**
 * uboot_gic_get_priority_mask() - Get CPU priority mask
 * Return: Current priority mask value
 */
uint32_t uboot_gic_get_priority_mask(void)
{
	return GICC_PMR;
}

/**
 * uboot_gic_set_priority_mask() - Set CPU priority mask
 * @priority_mask: Priority mask (0-255)
 * Return: 0 on success
 */
int uboot_gic_set_priority_mask(uint32_t priority_mask)
{
	GICC_PMR = priority_mask;
	return 0;
}

/**
 * uboot_gic_get_binary_point() - Get CPU binary point
 * Return: Current binary point value
 */
uint32_t uboot_gic_get_binary_point(void)
{
	return GICC_BPR;
}

/**
 * uboot_gic_set_binary_point() - Set CPU binary point
 * @binary_point: Binary point value
 * Return: 0 on success
 */
int uboot_gic_set_binary_point(uint32_t binary_point)
{
	GICC_BPR = binary_point;
	return 0;
}

/**
 * uboot_gic_enable_cpu() - Enable CPU interface
 * Return: 0 on success
 */
int uboot_gic_enable_cpu(void)
{
	GICC_CTLR |= GICC_CTLR_ENABLE;
	asm volatile("cpsie i" : : : "memory");
	return 0;
}

/**
 * uboot_gic_disable_cpu() - Disable CPU interface
 * Return: 0 on success
 */
int uboot_gic_disable_cpu(void)
{
	GICC_CTLR &= ~GICC_CTLR_ENABLE;
	asm volatile("cpsid i" : : : "memory");
	return 0;
}

/* === MULTI-CORE AND SGI SUPPORT === */

/**
 * uboot_gic_request_sgi() - Send Software Generated Interrupt
 * @id: SGI ID (0-15)
 * @cpu: Target CPU (0-1)
 * Return: 0 on success, -EINVAL on invalid parameters
 */
int uboot_gic_request_sgi(uint32_t id, uint32_t cpu)
{
	if (id >= 16 || cpu >= 2) {
		printf("GIC: Invalid SGI parameters: id=%u cpu=%u\n", id, cpu);
		return -EINVAL;
	}

	/* Send SGI to target CPU */
	GICD_SGIR = ((0x0 << 24) | (0x01 << (16 + cpu)) | (id << 0));

	return 0;
}

/**
 * uboot_gic_wakeup_secondary_core() - Wake up secondary CPU
 * @addr: Boot address for secondary core
 */
void uboot_gic_wakeup_secondary_core(void *addr)
{
	/* Set secondary CPU boot address */
	volatile uint32_t *sec_boot_addr = (volatile uint32_t *)SEC_BOOT_ADDR;
	*sec_boot_addr = (uint32_t)addr;

	/* Send SGI 0 to CPU 1 */
	uboot_gic_request_sgi(0, 1);
}
