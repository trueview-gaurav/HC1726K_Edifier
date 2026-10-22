/**
 * @file hw_gic.h
 * @brief GIC400
 */

#ifndef HW_GIC_H_
#define HW_GIC_H_

#ifndef __KERNEL__
#include <stdint.h>
#include <stdbool.h>
#else
#include <linux/types.h>
#endif

#include "address_map.h"
#include "irqs.h"

#define KYOTO_CPU_NUM 2
#define CPU_NUM KYOTO_CPU_NUM

#define KYOTO_GIC_MAX_INT_CNT (16 + 16 + 144) /* SGI + PPI + SPI(up to 144) */
#define GIC_MAX_INT_CNT (KYOTO_GIC_MAX_INT_CNT)

#define GICD_BASE (uint32_t)(GIC_BASE + 0x1000)
#define GICC_BASE (uint32_t)(GIC_BASE + 0x2000)

#define gicd_ctlr (volatile uint32_t *)(GICD_BASE + 0x0)
#define gicd_typer (volatile uint32_t *)(GICD_BASE + 0x4)
#define gicd_sgir (volatile uint32_t *)(GICD_BASE + 0xF00)

#define GICD_IGROUPRN_BASE (volatile uint32_t *)(GICD_BASE + 0x80)
#define GICD_IGROUPRN_OFFSET 4
#define gicd_igroupr0 (volatile uint32_t *)(GICD_BASE + 0x80)
#define gicd_igroupr1 (volatile uint32_t *)(GICD_BASE + 0x84)
#define gicd_igroupr2 (volatile uint32_t *)(GICD_BASE + 0x88)
#define gicd_igroupr3 (volatile uint32_t *)(GICD_BASE + 0x8C)
#define gicd_igroupr4 (volatile uint32_t *)(GICD_BASE + 0x90)
#define gicd_igroupr5 (volatile uint32_t *)(GICD_BASE + 0x94)
#define gicd_igroupr6 (volatile uint32_t *)(GICD_BASE + 0x98)
#define gicd_igroupr7 (volatile uint32_t *)(GICD_BASE + 0x9C)

#define GICD_ISENABLERN_BASE (volatile uint32_t *)(GICD_BASE + 0x100)
#define GICD_ISENABLERN_OFFSET 4
#define gicd_isenabler0 (volatile uint32_t *)(GICD_BASE + 0x100)
#define gicd_isenabler1 (volatile uint32_t *)(GICD_BASE + 0x104)
#define gicd_isenabler2 (volatile uint32_t *)(GICD_BASE + 0x108)
#define gicd_isenabler3 (volatile uint32_t *)(GICD_BASE + 0x10C)
#define gicd_isenabler4 (volatile uint32_t *)(GICD_BASE + 0x110)
#define gicd_isenabler5 (volatile uint32_t *)(GICD_BASE + 0x114)
#define gicd_isenabler6 (volatile uint32_t *)(GICD_BASE + 0x118)
#define gicd_isenabler7 (volatile uint32_t *)(GICD_BASE + 0x11C)
#define gicd_isenabler8 (volatile uint32_t *)(GICD_BASE + 0x120)

#define GICD_SPISRN_BASE (volatile uint32_t *)(GICD_BASE + 0xD04)
#define GICD_SPISRN_OFFSET 4
#define gicd_spisr0 (volatile uint32_t *)(GICD_BASE + 0xD04)
#define gicd_spisr1 (volatile uint32_t *)(GICD_BASE + 0xD08)
#define gicd_spisr2 (volatile uint32_t *)(GICD_BASE + 0xD0C)
#define gicd_spisr3 (volatile uint32_t *)(GICD_BASE + 0xD10)
#define gicd_spisr4 (volatile uint32_t *)(GICD_BASE + 0xD14)
#define gicd_spisr5 (volatile uint32_t *)(GICD_BASE + 0xD18)
#define gicd_spisr6 (volatile uint32_t *)(GICD_BASE + 0xD1C)
#define gicd_spisr7 (volatile uint32_t *)(GICD_BASE + 0xD20)

#define GICD_ISPENDRN_BASE (volatile uint32_t *)(GICD_BASE + 0x200)
#define GICD_ISPENDRN_OFFSET 4
#define gicd_ispendr0 (volatile uint32_t *)(GICD_BASE + 0x200)
#define gicd_ispendr1 (volatile uint32_t *)(GICD_BASE + 0x204)
#define gicd_ispendr2 (volatile uint32_t *)(GICD_BASE + 0x208)
#define gicd_ispendr3 (volatile uint32_t *)(GICD_BASE + 0x20C)
#define gicd_ispendr4 (volatile uint32_t *)(GICD_BASE + 0x210)
#define gicd_ispendr5 (volatile uint32_t *)(GICD_BASE + 0x214)
#define gicd_ispendr6 (volatile uint32_t *)(GICD_BASE + 0x218)
#define gicd_ispendr7 (volatile uint32_t *)(GICD_BASE + 0x21C)

#define GICD_ICPENDRN_BASE (volatile uint32_t *)(GICD_BASE + 0x280)
#define GICD_ICPENDRN_OFFSET 4
#define gicd_icpendr0 (volatile uint32_t *)(GICD_BASE + 0x200)
#define gicd_icpendr1 (volatile uint32_t *)(GICD_BASE + 0x204)
#define gicd_icpendr2 (volatile uint32_t *)(GICD_BASE + 0x208)
#define gicd_icpendr3 (volatile uint32_t *)(GICD_BASE + 0x20C)
#define gicd_icpendr4 (volatile uint32_t *)(GICD_BASE + 0x210)
#define gicd_icpendr5 (volatile uint32_t *)(GICD_BASE + 0x214)
#define gicd_icpendr6 (volatile uint32_t *)(GICD_BASE + 0x218)
#define gicd_icpendr7 (volatile uint32_t *)(GICD_BASE + 0x21C)

#define GICD_ISACTIVERN_BASE (volatile uint32_t *)(GICD_BASE + 0x300)
#define GICD_ISACTIVERN_OFFSET 4
#define gicd_isactiver0 (volatile uint32_t *)(GICD_BASE + 0x300)
#define gicd_isactiver1 (volatile uint32_t *)(GICD_BASE + 0x304)
#define gicd_isactiver2 (volatile uint32_t *)(GICD_BASE + 0x308)
#define gicd_isactiver3 (volatile uint32_t *)(GICD_BASE + 0x30C)
#define gicd_isactiver4 (volatile uint32_t *)(GICD_BASE + 0x310)
#define gicd_isactiver5 (volatile uint32_t *)(GICD_BASE + 0x314)
#define gicd_isactiver6 (volatile uint32_t *)(GICD_BASE + 0x318)
#define gicd_isactiver7 (volatile uint32_t *)(GICD_BASE + 0x31C)

#define GICD_IPRIORITYRN_BASE (volatile uint32_t *)(GICD_BASE + 0x400)

#define GICD_ITARGETSRN_BASE (volatile uint32_t *)(GICD_BASE + 0x820)
#define GICD_ITARGETSRN_OFFSET 4
#define gicd_itargetsr0 (volatile uint32_t *)(GICD_BASE + 0x820)
#define gicd_itargetsr1 (volatile uint32_t *)(GICD_BASE + 0x824)
#define gicd_itargetsr2 (volatile uint32_t *)(GICD_BASE + 0x828)
#define gicd_itargetsr3 (volatile uint32_t *)(GICD_BASE + 0x82C)
#define gicd_itargetsr4 (volatile uint32_t *)(GICD_BASE + 0x830)
#define gicd_itargetsr5 (volatile uint32_t *)(GICD_BASE + 0x834)
#define gicd_itargetsr6 (volatile uint32_t *)(GICD_BASE + 0x838)
#define gicd_itargetsr7 (volatile uint32_t *)(GICD_BASE + 0x83C)
#define gicd_itargetsr8 (volatile uint32_t *)(GICD_BASE + 0x840)
#define gicd_itargetsr9 (volatile uint32_t *)(GICD_BASE + 0x844)
#define gicd_itargetsr10 (volatile uint32_t *)(GICD_BASE + 0x848)
#define gicd_itargetsr11 (volatile uint32_t *)(GICD_BASE + 0x84C)
#define gicd_itargetsr12 (volatile uint32_t *)(GICD_BASE + 0x850)
#define gicd_itargetsr13 (volatile uint32_t *)(GICD_BASE + 0x854)
#define gicd_itargetsr14 (volatile uint32_t *)(GICD_BASE + 0x858)
#define gicd_itargetsr15 (volatile uint32_t *)(GICD_BASE + 0x85C)
#define gicd_itargetsr16 (volatile uint32_t *)(GICD_BASE + 0x860)
#define gicd_itargetsr17 (volatile uint32_t *)(GICD_BASE + 0x864)
#define gicd_itargetsr18 (volatile uint32_t *)(GICD_BASE + 0x868)
#define gicd_itargetsr19 (volatile uint32_t *)(GICD_BASE + 0x86C)
#define gicd_itargetsr20 (volatile uint32_t *)(GICD_BASE + 0x870)
#define gicd_itargetsr21 (volatile uint32_t *)(GICD_BASE + 0x874)
#define gicd_itargetsr22 (volatile uint32_t *)(GICD_BASE + 0x878)
#define gicd_itargetsr23 (volatile uint32_t *)(GICD_BASE + 0x87C)
#define gicd_itargetsr24 (volatile uint32_t *)(GICD_BASE + 0x880)
#define gicd_itargetsr25 (volatile uint32_t *)(GICD_BASE + 0x884)
#define gicd_itargetsr26 (volatile uint32_t *)(GICD_BASE + 0x888)
#define gicd_itargetsr27 (volatile uint32_t *)(GICD_BASE + 0x88C)
#define gicd_itargetsr28 (volatile uint32_t *)(GICD_BASE + 0x890)
#define gicd_itargetsr29 (volatile uint32_t *)(GICD_BASE + 0x894)
#define gicd_itargetsr30 (volatile uint32_t *)(GICD_BASE + 0x898)
#define gicd_itargetsr31 (volatile uint32_t *)(GICD_BASE + 0x89C)
#define gicd_itargetsr32 (volatile uint32_t *)(GICD_BASE + 0x8A0)
#define gicd_itargetsr33 (volatile uint32_t *)(GICD_BASE + 0x8A4)
#define gicd_itargetsr34 (volatile uint32_t *)(GICD_BASE + 0x8A8)
#define gicd_itargetsr35 (volatile uint32_t *)(GICD_BASE + 0x8AC)
#define gicd_itargetsr36 (volatile uint32_t *)(GICD_BASE + 0x8B0)
#define gicd_itargetsr37 (volatile uint32_t *)(GICD_BASE + 0x8B4)
#define gicd_itargetsr38 (volatile uint32_t *)(GICD_BASE + 0x8B8)
#define gicd_itargetsr39 (volatile uint32_t *)(GICD_BASE + 0x8BC)
#define gicd_itargetsr40 (volatile uint32_t *)(GICD_BASE + 0x8C0)
#define gicd_itargetsr41 (volatile uint32_t *)(GICD_BASE + 0x8C4)
#define gicd_itargetsr42 (volatile uint32_t *)(GICD_BASE + 0x8C8)
#define gicd_itargetsr43 (volatile uint32_t *)(GICD_BASE + 0x8CC)
#define gicd_itargetsr44 (volatile uint32_t *)(GICD_BASE + 0x8D0)
#define gicd_itargetsr45 (volatile uint32_t *)(GICD_BASE + 0x8D4)
#define gicd_itargetsr46 (volatile uint32_t *)(GICD_BASE + 0x8D8)
#define gicd_itargetsr47 (volatile uint32_t *)(GICD_BASE + 0x8DC)
#define gicd_itargetsr48 (volatile uint32_t *)(GICD_BASE + 0x8E0)
#define gicd_itargetsr49 (volatile uint32_t *)(GICD_BASE + 0x8E4)
#define gicd_itargetsr50 (volatile uint32_t *)(GICD_BASE + 0x8E8)
#define gicd_itargetsr51 (volatile uint32_t *)(GICD_BASE + 0x8EC)
#define gicd_itargetsr52 (volatile uint32_t *)(GICD_BASE + 0x8F0)
#define gicd_itargetsr53 (volatile uint32_t *)(GICD_BASE + 0x8F4)
#define gicd_itargetsr54 (volatile uint32_t *)(GICD_BASE + 0x8F8)
#define gicd_itargetsr55 (volatile uint32_t *)(GICD_BASE + 0x8FC)
#define gicd_itargetsr56 (volatile uint32_t *)(GICD_BASE + 0x900)
#define gicd_itargetsr57 (volatile uint32_t *)(GICD_BASE + 0x904)
#define gicd_itargetsr58 (volatile uint32_t *)(GICD_BASE + 0x908)
#define gicd_itargetsr59 (volatile uint32_t *)(GICD_BASE + 0x90C)
#define gicd_itargetsr60 (volatile uint32_t *)(GICD_BASE + 0x910)
#define gicd_itargetsr61 (volatile uint32_t *)(GICD_BASE + 0x914)
#define gicd_itargetsr62 (volatile uint32_t *)(GICD_BASE + 0x918)
#define gicd_itargetsr63 (volatile uint32_t *)(GICD_BASE + 0x91C)

#define gicc_ctlr (volatile uint32_t *)(GICC_BASE + 0x0)
#define gicc_pmr (volatile uint32_t *)(GICC_BASE + 0x4)
#define gicc_bpr (volatile uint32_t *)(GICC_BASE + 0x8)
#define gicc_iar (volatile uint32_t *)(GICC_BASE + 0xC)
#define gicc_eoir (volatile uint32_t *)(GICC_BASE + 0x10)

typedef uint32_t irqid_t;

typedef enum irq_trig_e { IRQ_TRIGGER_LEVEL = 0, IRQ_TRIGGER_EDGE = 1 } irq_trig_t;

typedef enum sgi_trgt_policy_e {
	SGI_TARGET_LIST = 0,
	SGI_TARGET_ALL_EXCL_SENDER = 1,
	SGI_TARGET_SELF = 2
} sgi_trgt_policy_t;

uint32_t gic_init(void);
uint32_t gic_init_per_cpu(void);

uint32_t gicd_set_pending_irq(irqid_t irq_id);
uint32_t gicd_clear_pending_irq(irqid_t irq_id);
bool gicd_is_pending_irq(irqid_t irq_id);

bool gicd_is_active_irq(irqid_t irq_id);

/* -1 if not valid */
int gicd_get_priority(irqid_t irq_id);
int gicd_set_priority(irqid_t irq_id, int priority);

int gicd_get_target(irqid_t irq_id);
int gicd_set_target(irqid_t irq_id, int target);

irq_trig_t gicd_get_trigger(irqid_t irq_id);
int gicd_set_trigger(irqid_t irq_id, irq_trig_t trigger_type);

/* Trigger an SGI to target CPU */
uint32_t gic_issue_sgi(irqid_t irq_id, sgi_trgt_policy_t target_filter, int cpu_id);

/* GICD API*/
uint32_t gicd_enable_irq(irqid_t irq_id);
uint32_t gicd_disable_irq(irqid_t irq_id);

/* GICC API */

uint32_t gicc_enable_cpu(void);
uint32_t gicc_disable_cpu(void);

uint32_t gicc_get_priority_mask(void);
uint32_t gicc_set_priority_mask(uint32_t priority_mask);

/* Secure binary point functions */
uint32_t gicc_get_binary_point(void);
uint32_t gicc_set_binary_point(uint32_t binary_point);

// IRQ handling callback function type
typedef void (*isr_cb_t)(uint32_t iar, void *context);

#define GICC_IAR_TO_CPUID(iar) ((iar >> 10) & 0x7)
#define GICC_IAR_TO_IRQID(iar) ((iar >> 0) & 0x3FF)

/** struct irq_dispatch_s: IRQ dispatcher struct
 *
 *  @callback_fn: callback function
 *  @ctx:         user-defined context
 *  @impl_flag:   whether the interrupt is supported by H/W
 */
struct irq_dispatch_s {
	isr_cb_t callback_fn;
	void *ctx;
};

uint32_t gic_register_isr(irqid_t irq_id, isr_cb_t cb, void *ctx);
uint32_t gic_unregister_isr(irqid_t irq_id);

uint32_t gic_request_sgi(uint32_t id, uint32_t cpu);

void gic_irq_handler(uint32_t gicc_iar_val);
void arch_irq_handler(void);
void arch_wakeup_secondary_core(void *addr);

#endif
