/*
 * uboot_gic.h - U-Boot GIC Driver Header
 * ARMv7 Generic Interrupt Controller Definitions
 * 
 * Copyright (C) 2025 Augentix Inc.
 * Author: Will.Chuang (im327)
 * 
 * This file provides comprehensive GIC hardware definitions, register
 * mappings, and API declarations for the HC1703/1723/1753/1783s platform.
 * Consolidates all SPL GIC functionality into U-Boot with enhanced features.
 */
#ifndef __UBOOT_GIC_H__
#define __UBOOT_GIC_H__

#include <common.h>
#include "address_map.h"

/* === GIC HARDWARE CONFIGURATION === */
#define GICD_BASE (GIC_BASE + 0x1000) /* Distributor base */
#define GICC_BASE (GIC_BASE + 0x2000) /* CPU interface base */

/* Interrupt configuration */
#define GIC_SGI_COUNT 16 /* Software Generated Interrupts (0-15) */
#define GIC_PPI_COUNT 16 /* Private Peripheral Interrupts (16-31) */
#define GIC_SPI_COUNT 144 /* Shared Peripheral Interrupts (32-175) */
#define MAX_IRQS (GIC_SGI_COUNT + GIC_PPI_COUNT + GIC_SPI_COUNT)

/* Control register enable bits */
#define GICD_CTLR_ENABLE (1)
#define GICC_CTLR_ENABLE (1)
#define GIC_DEFAULT_PRIORITY_WORD (0xA0A0A0A0U)

/* === GIC DISTRIBUTOR REGISTERS === */
#define GICD_CTLR (*(volatile uint32_t *)(GICD_BASE + 0x000)) /* Control */
#define GICD_TYPER (*(volatile uint32_t *)(GICD_BASE + 0x004)) /* Type */
#define GICD_IGROUPR_BASE ((volatile uint32_t *)(GICD_BASE + 0x080)) /* Group */
#define GICD_ISENABLER_BASE ((volatile uint32_t *)(GICD_BASE + 0x100)) /* Set-enable */
#define GICD_ICENABLER_BASE ((volatile uint32_t *)(GICD_BASE + 0x180)) /* Clear-enable */
#define GICD_ISPENDR_BASE ((volatile uint32_t *)(GICD_BASE + 0x200)) /* Set-pending */
#define GICD_ICPENDR_BASE ((volatile uint32_t *)(GICD_BASE + 0x280)) /* Clear-pending */
#define GICD_ISACTIVER_BASE ((volatile uint32_t *)(GICD_BASE + 0x300)) /* Set-active */
#define GICD_ICACTIVER_BASE ((volatile uint32_t *)(GICD_BASE + 0x380)) /* Clear-active */
#define GICD_IPRIORITYR_BASE ((volatile uint8_t *)(GICD_BASE + 0x400)) /* Priority */
#define GICD_ITARGETSR_BASE ((volatile uint8_t *)(GICD_BASE + 0x800)) /* Target */
#define GICD_ICFGR_BASE ((volatile uint32_t *)(GICD_BASE + 0xC00)) /* Configuration */
#define GICD_SPISR_BASE ((volatile uint32_t *)(GICD_BASE + 0xD04)) /* SPI status */
#define GICD_SGIR (*(volatile uint32_t *)(GICD_BASE + 0xF00)) /* SGI control */

/* === GIC CPU INTERFACE REGISTERS === */
#define GICC_CTLR (*(volatile uint32_t *)(GICC_BASE + 0x000)) /* Control */
#define GICC_PMR (*(volatile uint32_t *)(GICC_BASE + 0x004)) /* Priority mask */
#define GICC_BPR (*(volatile uint32_t *)(GICC_BASE + 0x008)) /* Binary point */
#define GICC_IAR (*(volatile uint32_t *)(GICC_BASE + 0x00C)) /* Acknowledge */
#define GICC_EOIR (*(volatile uint32_t *)(GICC_BASE + 0x010)) /* End of IRQ */

/* === GIC REGISTER MANIPULATION MACROS === */
#define GIC_REG_OFFSET(irq_id) ((irq_id) / 32)
#define GIC_BIT_MASK(irq_id) (1U << ((irq_id) % 32))
#define GIC_BIT_SHIFT(irq_id) ((irq_id) % 32)

/* IAR (Interrupt Acknowledge Register) field extraction */
#define GICC_IAR_TO_IRQID(iar) ((iar)&0x3FF)
#define GICC_IAR_TO_CPUID(iar) (((iar) >> 10) & 0x7)
#define GICC_IAR_SPURIOUS (1023)

/* Pending register utilities */
#define GIC_PENDING_REG_COUNT ((MAX_IRQS + 31) / 32)
#define GIC_BITS_PER_REG 32

/**
 * @brief IRQ handler callback function pointer
 */
typedef void (*uboot_isr_cb_t)(uint32_t iar, void *context);

/**
 * @brief IRQ handler table entry
 */
typedef struct uboot_irq_entry_s {
	uboot_isr_cb_t callback_fn; /* IRQ handler function */
	void *ctx; /* Handler context */
} uboot_irq_entry_t;

/* === GLOBAL VARIABLES === */
extern uboot_irq_entry_t g_uboot_irq_table[MAX_IRQS];

/* === FUNCTION PROTOTYPES === */

/* IRQ handler management */
int uboot_irq_install_handler(uint32_t irq, uboot_isr_cb_t handler, void *arg);
int uboot_irq_free_handler(uint32_t irq);

/* IRQ control */
int uboot_gic_enable_irq(uint32_t irq_id);
int uboot_gic_disable_irq(uint32_t irq_id);

/* IRQ priority management */
int uboot_gic_get_priority(uint32_t irq_id);
int uboot_gic_set_priority(uint32_t irq_id, uint8_t priority);

/* IRQ pending state management */
int uboot_gic_set_pending(uint32_t irq_id);
int uboot_gic_clear_pending(uint32_t irq_id);
int uboot_gic_is_pending(uint32_t irq_id);
int uboot_gic_is_active(uint32_t irq_id);

/* CPU interface management */
uint32_t uboot_gic_get_priority_mask(void);
int uboot_gic_set_priority_mask(uint32_t priority_mask);
uint32_t uboot_gic_get_binary_point(void);
int uboot_gic_set_binary_point(uint32_t binary_point);
int uboot_gic_enable_cpu(void);
int uboot_gic_disable_cpu(void);

/* Multi-core and SGI support */
int uboot_gic_request_sgi(uint32_t id, uint32_t cpu);
void uboot_gic_wakeup_secondary_core(void *addr);
#endif /* __UBOOT_GIC_H__ */
