#include <linux/io.h>
#include <linux/irq.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>

#include <asm/exception.h>
#include <asm/mach/irq.h>
#include <mach/hc18xx.h>

#include "irqchip.h"

#define INTC_STA  0x00
#define INTC_MASK 0x08

#define INTC_STA_L  0x00
#define INTC_STA_H  0x04
#define INTC_MASK_L 0x08
#define INTC_MASK_H 0x0c

#define SW_IRQ_L 0x18
#define SW_IRQ_H 0x1C

#define IRQ_L_CNT 32
#define IRQ_H_CNT 16
#define IRQ_CNT ( IRQ_L_CNT + IRQ_H_CNT )
#define MAX_IRQ_CNT 64

#define IRQTYPE_LEVEL	0
#define IRQTYPE_EINT	1
#define IRQTYPE_SW	2

#define IRQ_EXT		0x00000001
#define IRQ_IS_FE	0x00000002
#define IRQ_IS_TE	0x00000004
#define IRQ_IS_FSC	0x00000008
#define IRQ_IS_FSCW	0x00000010
#define IRQ_IS_TFW	0x00000020
#define IRQ_ISP_TFR	0x00000040
#define IRQ_ISP_DPC	0x00000080
#define IRQ_ISP_DMS	0x00000100
#define IRQ_ISP_SC	0x00000200
#define IRQ_ISP_SCW	0x00000400
#define IRQ_ISP_MCVP	0x00000800
#define IRQ_ISP_SHP	0x00001000
#define IRQ_ISP_GFX	0x00002000
#define IRQ_ENC_JPEG	0x00004000
#define IRQ_ENC_SRCR	0x00008000
#define IRQ_ENC_BSW	0x00010000
#define IRQ_ENC_VENC	0x00020000
#define IRQ_ENC_OSDR	0x00040000
#define IRQ_DARB	0x00080000
#define IRQ_DDR		0x00100000
#define IRQ_USB		0x00200000
#define IRQ_EMAC	0x00400000
#define IRQ_QSPI	0x00800000
#define IRQ_SDC		0x01000000
#define IRQ_TIMER_0	0x02000000
#define IRQ_TIMER_1	0x04000000
#define IRQ_LVDS	0x08000000
#define IRQ_AUDIO_IN	0x10000000
#define IRQ_AUDIO_OUT	0x20000000
#define IRQ_DMA		0x40000000
#define IRQ_I2C_SLAVE	0x80000000
#define IRQ_PWM		0x00000001
#define IRQ_I2C0	0x00000002
#define IRQ_I2C1	0x00000004
#define IRQ_SPI0	0x00000008
#define IRQ_SPI1	0x00000010
#define IRQ_SPI2	0x00000020
#define IRQ_UART0	0x00000040
#define IRQ_UART1	0x00000080
#define IRQ_UART2	0x00000100
#define IRQ_ISP_HDR	0x00000100
#define IRQ_ISP_HDRR	0x00000200
#define IRQ_TIMER_2	0x00000800
#define IRQ_TIMER_3	0x00001000
#define IRQ_IS_SUB_FE	0x00002000
#define IRQ_SUB_LVDS	0x00004000
#define IRQ_WDT		0x80000000

//static inline void __sramfunc __trigger_gpio(u16 pin_id, u16 level)
static inline void __exception_irq_entry __trigger_gpio(u16 pin_id, u16 level)
{
	__raw_writew(((u16)0x0100 | level),
	             ((void *__iomem)(TO_VA(HC18XX_IOC_PA)) + (0x50 + (pin_id << 2))));
}

struct hc18xx_intc {
	void __iomem *base;
	void __iomem *stat_l;
	void __iomem *stat_h;
	void __iomem *mask_l;
	void __iomem *mask_h;
	u32 irq_cnt; /* # of irqs */
	struct irq_domain *domain;
	struct hc18xx_irq_data *irqs;
};

struct hc18xx_irq_data {
	u32 type;
	u32 offset;
	u32 parent_irq;
	struct hc18xx_intc *intc;
};

static struct hc18xx_intc *main_intc;

/* intc handler functions */
asmlinkage void __exception_irq_entry hc18xx_handle_irq(struct pt_regs *regs);
//asmlinkage void __sramfunc hc18xx_handle_irq(struct pt_regs *regs);

/* Get irq mask from HWIRQ ID and set/unset the corresponding bit of interrupt mask*/
static void hc18xx_set_irq_mask(struct irq_data *data, int masked)
{
	struct hc18xx_irq_data *irq_data = irq_data_get_irq_chip_data(data);
	struct hc18xx_intc *intc = irq_data->intc;
	u32 mask;
	u32 offset;

	offset = irq_data->offset;

	if (offset < IRQ_L_CNT) { /* Low bits */
		/*R-M-W*/
		mask = readl_relaxed(intc->mask_l);
		mask = (masked) ? (mask | (1UL << offset))
		       : (mask & ~(1UL << offset));
		writel_relaxed(mask, intc->mask_l);
	} else { /* High bits */
		offset -= IRQ_L_CNT;
		mask = readl_relaxed(intc->mask_h);
		mask = (masked) ? (mask | (1UL << offset))
		       : (mask & ~(1UL << offset));
		writel_relaxed(mask, intc->mask_h);
	}
}

//asmlinkage void __sramfunc hc18xx_handle_irq (struct pt_regs *regs)
asmlinkage void __exception_irq_entry hc18xx_handle_irq(struct pt_regs *regs)
{
	volatile register u32 irq_l;
	volatile register u32 irq_h;
	volatile register u32 group = 0;
	volatile register u32 irqnr;
	volatile register u32 irq;

	/* re-order interrupt priority here if desired */

	asm volatile("next_loop:\n");

	irq_l = __raw_readl(main_intc->stat_l);
	irq_h = __raw_readl(main_intc->stat_h);
	group = 0;

	while (1) {
		if (!(irq_l | irq_h)) {
			break;
		}

		asm volatile(
		    "orrs	%[irq], %[irq_l], %[irq_h]\n"
		    "beq	end\n" /* exit point of the while loop */
		    "cmp	%[group], #1\n"
		    "beq	handle_irq_h\n"
		    "handle_irq_l:\n"
		    "clz	%[irqnr], %[irq_l]\n"
		    "cmp	%[irqnr], #32\n"
		    "moveq	%[group], #1\n"
		    "beq	handle_irq_h\n"
		    "bic	%[irq_l], %[irq_l], %[const0x80000000], LSR %[irqnr]\n"
		    "rsb %[irqnr], %[irqnr], #31\n"
		    "b	invoke_isr\n"
		    "handle_irq_h:\n"
		    "clz	%[irqnr], %[irq_h]\n"
		    "cmp	%[irqnr], #32\n"
		    "moveq	%[group], #0\n"
		    "beq next_loop\n"
		    "bic	%[irq_h], %[irq_h], %[const0x80000000], LSR %[irqnr]\n"
		    "rsb %[irqnr], %[irqnr], #63\n"
		    "b	invoke_isr\n"
		    "invoke_isr:\n"
		    : [irq]   "=r"(irq),
		    [irqnr] "=r"(irqnr),
		    [group] "+r"(group),
		    [irq_l] "+r"(irq_l),
		    [irq_h] "+r"(irq_h)
		    : [const0x80000000] "r"(0x80000000)
		    : "cc", "memory"
		);

		handle_domain_irq(main_intc->domain, irqnr, regs);

	}

	asm volatile("end:\n");
	return;
}

static void hc18xx_irq_mask(struct irq_data *d)
{
	hc18xx_set_irq_mask(d, 1);
}

static void hc18xx_irq_unmask(struct irq_data *d)
{
	hc18xx_set_irq_mask(d, 0);
}

static struct irq_chip hc18xx_intc_chip = {
	.name = "hc18xx_intc",
	.irq_mask = hc18xx_irq_mask,
	.irq_unmask = hc18xx_irq_unmask,
};

static int hc18xx_intc_irq_domain_map(struct irq_domain *domain,
                                      unsigned int virq,
                                      irq_hw_number_t hw)
{
	struct hc18xx_intc *intc = domain->host_data;
	struct hc18xx_irq_data *irq_data;

	/* watchdog IRQ uses bit 63, so we give HW ID 63 to it */
	irq_data = &intc->irqs[hw];

	irq_data->intc = intc;
	irq_data->offset = hw;

	irq_set_chip_and_handler(virq,
	                         &hc18xx_intc_chip,
	                         handle_level_irq);
	irq_set_chip_data(virq, irq_data);
	set_irq_flags(virq, IRQF_VALID);

	return 0;
}

/* xlate function translates device tree information to
 * HW IRQ ID and IRQ type*/
static int hc18xx_irq_domain_xlate(struct irq_domain *d,
                                   struct device_node *controller,
                                   const u32 *intspec, unsigned int intsize,
                                   unsigned long *out_hwirq, unsigned int *out_type)
{
	if (WARN_ON(intsize < 2)) {
		return -EINVAL;
	}

	/*TODO: FIQ in intspec[0] */
	*out_hwirq = intspec[1];
	*out_type = IRQ_TYPE_LEVEL_LOW;
	return 0;
}

static const struct irq_domain_ops hc18xx_intc_irq_domain_ops = {
	.map = hc18xx_intc_irq_domain_map,
	.xlate = hc18xx_irq_domain_xlate,
};

/* Set IRQ handler and irq_domain of hc18xx interrupt controller */
int __init hc18xx_intc_init_base(struct device_node *node,
                                 struct hc18xx_intc *intc)
{
	void __iomem *intc_base = of_iomap(node, 0);

	if (!intc_base) {
		pr_info("Unable to map interrupt controller!\n");
		panic("PANIC at fn:%s\n", __func__);
	}

	intc->base = intc_base;
	intc->stat_l = intc_base + INTC_STA_L;
	intc->stat_h = intc_base + INTC_STA_H;
	intc->mask_l = intc_base + INTC_MASK_L;
	intc->mask_h = intc_base + INTC_MASK_H;
	intc->irq_cnt = MAX_IRQ_CNT;

	intc->irqs = kzalloc(sizeof(*intc->irqs) * (intc->irq_cnt),
	                     GFP_KERNEL);

	if (!intc->irqs) {
		return -ENOMEM;
	}

	intc->domain = irq_domain_add_linear(node,
	                                     intc->irq_cnt,
	                                     &hc18xx_intc_irq_domain_ops,
	                                     intc);

	if (!intc->domain) {
		pr_info("Unable to create IRQ domain\n");
		panic("PANIC at fn:%s\n", __func__);
	}

	/* Initialzed as arch irq handler */
	set_handle_irq(hc18xx_handle_irq);
	return 0;
}

static int __init hc18xx_intc_of_init(struct device_node *node,
                                      struct device_node *parent)
{
	if (WARN_ON(!node)) {
		return -ENODEV;
	}

	main_intc = kzalloc(sizeof(*main_intc), GFP_KERNEL);

	if (!main_intc) {
		return -ENOMEM;
	}

	return hc18xx_intc_init_base(node, main_intc);
}
IRQCHIP_DECLARE(hc18xx_irqchip, "augentix,hc18xx-intc", hc18xx_intc_of_init);
