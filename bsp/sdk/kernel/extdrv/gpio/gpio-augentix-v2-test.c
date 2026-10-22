#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>

#include <asm/io.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/gpio/consumer.h>
#include <linux/gpio.h>

#define DRV_NAME "augentix_gpio_test"

#define DBG(fmt, args...)            \
	do {                         \
		pr_err(fmt, ##args); \
	} while (0)

#define MAX_PMUIOC_NUM 3
#define MAX_PIOC_NUM 5
#define MAX_PIOC1_NUM 5

#define PMU_GPI        \
	{              \
		50, 51 \
	}

#define PMU_GPO 49

static struct gpio_desc *pmu_gpio[MAX_PMUIOC_NUM];
static struct gpio_desc *p0_gpio[MAX_PIOC_NUM];
static struct gpio_desc *p1_gpio[MAX_PIOC1_NUM];

typedef enum {
	PMUIOC,
	PIOC0,
	PIOC1,
	GROUP_NUM,
} AGTX_GPIO_DOMAIN;

enum { GPIO_DIR_OUT,
       GPIO_DIR_IN,
};

typedef struct {
	AGTX_GPIO_DOMAIN domain;
	const char *name;
	int num;
	struct gpio_desc **desc;
} AGTX_GPIO_DESC;

static AGTX_GPIO_DESC g_gpio_desc[] = {
	{ PMUIOC, "pmuioc", MAX_PMUIOC_NUM, pmu_gpio },
	{ PIOC0, "pioc0", MAX_PIOC_NUM, p0_gpio },
	{ PIOC1, "pioc1", MAX_PIOC1_NUM, p1_gpio },
};

static int single_gpio_val_test(AGTX_GPIO_DOMAIN domain, struct gpio_desc *desc)
{
	int expect_val = 1;
	int got_val = 0;
	int index = desc_to_gpio(desc);
	int pmu_gpi[] = PMU_GPI;

	if (index != pmu_gpi[0] && index != pmu_gpi[1]) {
	again:
		gpiod_set_value(desc, expect_val);
		got_val = gpiod_get_value(desc);
		if (got_val != expect_val) {
			pr_err("[GPIO val test] Fail.\n"
			       "Group %s, gpio[%d] set as %u, gotten value is %u\n",
			       g_gpio_desc[domain].name, index, expect_val, got_val);
			return -1;
		}
		if (expect_val == 1) {
			expect_val = 0;
			goto again;
		}
		DBG("[GPIO val test] Group %s, gpio[%d] pass\n", g_gpio_desc[domain].name, index);
	}
	return 0;
}
static int gpio_val_test(void)
{
	int i = 0;
	AGTX_GPIO_DOMAIN domain = 0;
	struct gpio_desc **desc;
	int ret = 0;

	DBG("[GPIO val test] Verify output value 0 → 1 and then 1 → 0\n");

	for (domain = 0; domain < GROUP_NUM; domain++) {
		desc = g_gpio_desc[domain].desc;
		for (i = 0; i < g_gpio_desc[domain].num; i++) {
			if (single_gpio_val_test(domain, desc[i]))
				ret = -1;
		}
	}

	return ret;
}

static int single_gpio_dir_test(AGTX_GPIO_DOMAIN domain, struct gpio_desc *desc)
{
	int index = desc_to_gpio(desc);
	int ret = 0;
	int pmu_gpi[] = PMU_GPI;
	int pmu_gpo = PMU_GPO;

	if (index != pmu_gpi[0] && index != pmu_gpi[1]) {
		gpiod_set_value(desc, 1);
		ret = gpiod_direction_output(desc, GPIOF_DIR_OUT);
		if (ret < 0) {
			pr_err("[GPIO dir test] Fail.\n"
			       "Group %s, gpio[%d] can't set as output direction\n",
			       g_gpio_desc[domain].name, index);
			return -1;
		}
		ret = gpiod_get_direction(desc);
		if (ret != GPIO_DIR_OUT) {
			pr_err("[GPIO dir test] Fail.\n"
			       "Group %s, gpio[%d] gotten direction is not GPIO_DIR_OUT\n",
			       g_gpio_desc[domain].name, index);
			return -1;
		}
	}

	if (index != pmu_gpo) {
		ret = gpiod_direction_input(desc);
		if (ret < 0) {
			pr_err("[GPIO dir test] Fail.\n"
			       "Group %s, gpio[%d] can't set as input direction\n",
			       g_gpio_desc[domain].name, index);
			return -1;
		}
		ret = gpiod_get_direction(desc);
		if (ret != GPIO_DIR_IN) {
			pr_err("[GPIO dir test] Fail.\n"
			       "Group %s, gpio[%d] gotten direction is not GPIO_DIR_IN\n",
			       g_gpio_desc[domain].name, index);
			return -1;
		}

		if (gpiod_get_value(desc) == 1) {
			DBG("[GPIO dir test][Warn] Group %s, gpio[%d] Input value asserted.\n",
			    g_gpio_desc[domain].name, index);
		}
	}
	DBG("[GPIO dir test] Group %s, gpio[%d] pass\n", g_gpio_desc[domain].name, index);

	if (index != pmu_gpi[0] && index != pmu_gpi[1]) {
		gpiod_set_value(desc, 0);
	}

	return 0;
}

static int gpio_dir_test(void)
{
	int i = 0;
	AGTX_GPIO_DOMAIN domain = 0;
	struct gpio_desc **desc;
	int ret = 0;

	DBG("[GPIO dir test] Set as output 1 → set as input → read value\n"
	    "[GPIO dir test] Asserted input value may be due to pulled by circuit\n");
	for (domain = 0; domain < GROUP_NUM; domain++) {
		desc = g_gpio_desc[domain].desc;
		for (i = 0; i < g_gpio_desc[domain].num; i++) {
			if (single_gpio_dir_test(domain, desc[i]))
				ret = -1;
		}
	}

	return ret;
}

static int gpio_test_probe(struct platform_device *pdev)
{
	int index = 0;
	AGTX_GPIO_DOMAIN domain = 0;
	struct gpio_desc **target_desc;

	pr_err("-----GPIO consumer test start-----\n");

	/* Setup gpio */
	for (domain = 0; domain < GROUP_NUM; domain++) {
		target_desc = g_gpio_desc[domain].desc;
		for (index = 0; index < g_gpio_desc[domain].num; index++) {
			target_desc[index] =
			        devm_gpiod_get_index(&pdev->dev, g_gpio_desc[domain].name, index, GPIOD_OUT_LOW);
			if (IS_ERR(target_desc[index])) {
				pr_err("Target is invalid from GPIO driver, group: %s[%d]\n", g_gpio_desc[domain].name,
				       index);
			}
		}
	}

	if (gpio_val_test()) {
		pr_err("[GPIO val test] \033[31mFail\033[0m");
	} else {
		pr_err("[GPIO val test] \033[32mPass\033[0m");
	}

	if (gpio_dir_test()) {
		pr_err("[GPIO dir test] \033[31mFail\033[0m");
	} else {
		pr_err("[GPIO dir test] \033[32mPass\033[0m");
	}

	for (domain = 0; domain < GROUP_NUM; domain++) {
		target_desc = g_gpio_desc[domain].desc;
		for (index = 0; index < g_gpio_desc[domain].num; index++)
			devm_gpiod_put(&pdev->dev, target_desc[index]);
	}
	pr_err("-----GPIO consumer test done-----\n");

	return 0;
}

static int gpio_test_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id gpio_test_dt_ids[] = {
	{ .compatible = "augentix,gpio-test" },
	{},
};
MODULE_DEVICE_TABLE(of, gpio_test_dt_ids);

static struct platform_driver gpio_test_driver = {
	.probe = gpio_test_probe,
	.remove = gpio_test_remove,
	.driver = {
		.owner = THIS_MODULE,
		.name = DRV_NAME,
		.of_match_table = gpio_test_dt_ids,
	},
};
module_platform_driver(gpio_test_driver);

MODULE_AUTHOR("Louis Yang, Augentix <louis.yang@augentix.com>");
MODULE_DESCRIPTION("Augentix gpio test driver");
MODULE_LICENSE("GPL");
