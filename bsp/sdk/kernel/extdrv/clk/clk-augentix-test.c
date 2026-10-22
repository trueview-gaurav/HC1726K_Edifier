/*
   Usage: add dts node as follows
          the first PARENT_NUM nodes will be gotten as parent clock (use the last one as parent clock)
	  and try to set parent for every folloing clock

	clk_test: clk_test {
		compatible = "augentix,clk-test";
		         //parent1       parent2
		clocks = <&sys_clk>, <&ado_pll_dclk6>,
			// tested clk ...
			<&clkc 0>, <&clkc 1>, <&clkc 2>, <&clkc 3>, <&clkc 4>, <&clkc 5>, <&clkc 6>, <&clkc 7>, <&clkc 8>, <&clkc 9>, <&clkc 10>, <&clkc 11>, <&clkc 12>, <&clkc 13>, <&clkc 14>, <&clkc 15>, <&clkc 16>, <&clkc 17>, <&clkc 18>, <&clkc 19>, <&clkc 20>, <&clkc 21>, <&clkc 22>, <&clkc 23>, <&clkc 24>, <&clkc 25>, <&clkc 26>, <&clkc 27>, <&clkc 28>, <&clkc 29>, <&clkc 30>, <&clkc 31>, <&clkc 32>, <&clkc 33>, <&clkc 34>, <&clkc 35>, <&clkc 36>, <&clkc 37>, <&clkc 38>, <&clkc 39>, <&clkc 40>, <&clkc 41>, <&clkc 42>, <&clkc 43>, <&clkc 44>, <&clkc 45>, <&clkc 46>, <&clkc 47>, <&clkc 48>, <&clkc 49>, <&clkc 50>, <&clkc 51>, <&clkc 52>, <&clkc 53>;
		status = "okay";
	};
*/

#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>

#include <asm/io.h>
#include <linux/slab.h>
#include <linux/clk.h>
#include <linux/of.h>
#include <linux/of_address.h>

#define DRV_NAME "clk_test"

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#warning SAPPORO
#define MAX_CLK_NUM (43)
#define GATE_TEST_START_NUM (10)
#define PARENT_NUM 2
#else
#warning KYOTO
#define MAX_CLK_NUM (53)
#define GATE_TEST_START_NUM (21)
#define PARENT_NUM 0
#endif

static int clk_test_probe(struct platform_device *pdev)
{
	struct clk *clk;
	int ret, i;
	unsigned long rate;
	struct clk *target_parent;
	struct clk *current_parent;

	for (i = 0; i < PARENT_NUM; i++) {
		target_parent = of_clk_get(pdev->dev.of_node, i);
		if (IS_ERR(target_parent)) {
			pr_err("Fail to get parent clock\n");
			goto clk_test_fail;
		}

		rate = clk_get_rate(target_parent);
		pr_err("parent clk_get_rate = %lu\n", rate);
	}

	for (i = PARENT_NUM; i < MAX_CLK_NUM; i++) {
		clk = of_clk_get(pdev->dev.of_node, i);

		if (IS_ERR(clk)) {
			pr_err("Fail to get clock\n");
			goto clk_test_fail;
		}

		if ((ret = clk_prepare(clk))) {
			pr_err("Fail to prepare clock\n");
			goto clk_test_fail;
		}

		if ((ret = clk_enable(clk))) {
			pr_err("Fail to enable clock\n");
			goto clk_test_fail;
		}

		if (i >= GATE_TEST_START_NUM) {
			// disabling some of clk cause system hang, ex DRAM, Bus clk
			clk_disable(clk);

			if ((ret = clk_enable(clk))) {
				pr_err("Fail to reenable clock\n");
				goto clk_test_fail;
			}
		}
		rate = clk_get_rate(clk);
		pr_err("clk_get_rate = %lu\n", rate);
		if ((ret = clk_set_rate(clk, rate))) {
			pr_err("clk_set_rate failed\n");
			goto clk_test_fail;
		}

		current_parent = clk_get_parent(clk);
		if (current_parent == target_parent)
			pr_err("Target parent is current parent\n");
		if ((ret = clk_set_parent(clk, target_parent))) {
			pr_err("clk_set_parent failed\n");
		} else {
			pr_err("clk_set_parent succeed\n");
			rate = clk_get_rate(clk);
			pr_err("clk_get_rate = %lu\n", rate);
			current_parent = clk_get_parent(clk);
			if (current_parent == target_parent)
				pr_err("Target parent is current parent after set parent\n");
		}

		clk_put(clk);
		clk_put(current_parent);
		pr_err("Test for clk[%d] OK\n", i);
	}
	clk_put(target_parent);

	pr_err("Test for clk all passed\n");
	return 0;

clk_test_fail:
	pr_err("Test for clk[%d] Failed\n", i);
	clk_put(clk);
	return ret;
}

static int clk_test_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct of_device_id clk_test_dt_ids[] = {
	{ .compatible = "augentix,clk-test" },
	{},
};
MODULE_DEVICE_TABLE(of, clk_test_dt_ids);

static struct platform_driver clk_test_driver = {
	.probe = clk_test_probe,
	.remove = clk_test_remove,
	.driver =
	        {
	                .owner = THIS_MODULE,
	                .name = DRV_NAME,
	                .of_match_table = clk_test_dt_ids,
	        },
};
module_platform_driver(clk_test_driver);

MODULE_AUTHOR("Eddie Lee, Augentix <eddie.lee@augentix.com>");
MODULE_DESCRIPTION("Augentix clock driver");
MODULE_LICENSE("GPL");
