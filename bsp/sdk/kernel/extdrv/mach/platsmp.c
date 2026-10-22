#include <linux/delay.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/memory.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/smp.h>

#define SYSCFG_SEC_BOOT_ADDR_REG 0x14

static void __iomem *syscfg_base;
DEFINE_SPINLOCK(cpu_lock);

static void __init augentix_smp_prepare_cpus(unsigned int max_cpus)
{
	struct device_node *node;

	node = of_find_compatible_node(NULL, NULL, "augentix,syscfg");
	if (!node) {
		pr_err("Failed to find SYSCFG node in device tree\n");
		return;
	}

	syscfg_base = of_iomap(node, 0);
	if (!syscfg_base)
		pr_err("Failed to map SYSCFG registers\n");
}

static int augentix_smp_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
	if (!syscfg_base)
		return -EFAULT;

	spin_lock(&cpu_lock);
	/* Set CPU boot address */
	writel(virt_to_phys(secondary_startup), syscfg_base + SYSCFG_SEC_BOOT_ADDR_REG);
	spin_unlock(&cpu_lock);
	arch_send_wakeup_ipi_mask(cpumask_of(cpu));
	return 0;
}

#ifdef CONFIG_HOTPLUG_CPU
static void augentix_cpu_die(unsigned int cpu)
{
	asm volatile("wfi" : : : "memory");
}
#endif

struct smp_operations augentix_smp_ops __initdata = {
	.smp_prepare_cpus = augentix_smp_prepare_cpus,
	.smp_boot_secondary = augentix_smp_boot_secondary,
#ifdef CONFIG_HOTPLUG_CPU
	.cpu_die = augentix_cpu_die,
#endif
};
CPU_METHOD_OF_DECLARE(augentix_smp, "augentix,hc1703_1723_1753_1783s-smp",
                      &augentix_smp_ops);
