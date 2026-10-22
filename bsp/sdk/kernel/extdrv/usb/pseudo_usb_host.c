#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include "pseudo_usb_host.h"

#define DEV_NAME "pseudo_usb_host"

static struct cdev pseduo_usb_host_cdev;
static dev_t pseduo_usb_host_dev;
static struct device *pseudo_usb_host_device;

static int lock = 0;
static int enum_done;
static char *state = "suspend";

static struct workqueue_struct *usb_workqueue;
struct work_item {
	struct work_struct work;
};
static struct work_item usb_work_item;

static ssize_t store_removal(struct device *dev, struct device_attribute *attr, const char *buf, size_t len)
{
	int status;
	int removal;

	status = kstrtoint(buf, 0, &removal);
	if (status != 0) {
		return printk("Retry removal\n");
	}
	if (removal != 1) {
		return -EIO;
	}

	enum_done = 0;
	queue_work(usb_workqueue, &usb_work_item.work);
	printk("pseudo_usb_host removed\n");

	return len;
}

static ssize_t show_state(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%s\n", state);
}

static DEVICE_ATTR(state, S_IRUGO, show_state, NULL);
static DEVICE_ATTR(removal, S_IWUSR, NULL, store_removal);

struct attribute *pesudo_usb_host_attrs[] = { &dev_attr_state.attr, &dev_attr_removal.attr, NULL };

struct attribute_group pesudo_usb_host_attr_group = { .attrs = pesudo_usb_host_attrs };

static struct class pseduo_usb_host_class = {
	.name = "pseudo_usb",
	.owner = THIS_MODULE,
};

static const struct file_operations pseduo_usb_host_fops = {
	.owner = THIS_MODULE,
};

static int pseudo_usb_host_create(void)
{
	int ret = 0;

	if (lock == 0) {
		ret = alloc_chrdev_region(&pseduo_usb_host_dev, 0, 1, DEV_NAME);
		if (ret) {
			return ret;
		}

		cdev_init(&pseduo_usb_host_cdev, &pseduo_usb_host_fops);
		pseduo_usb_host_cdev.owner = THIS_MODULE;

		ret = cdev_add(&pseduo_usb_host_cdev, pseduo_usb_host_dev, 1);
		if (ret) {
			unregister_chrdev_region(pseduo_usb_host_dev, 1);
			return ret;
		}

		pseudo_usb_host_device =
		        device_create(&pseduo_usb_host_class, NULL, pseduo_usb_host_dev, NULL, DEV_NAME);
		if (IS_ERR(pseudo_usb_host_device)) {
			cdev_del(&pseduo_usb_host_cdev);
			unregister_chrdev_region(pseduo_usb_host_dev, 1);
			ret = PTR_ERR(pseudo_usb_host_device);
			return ret;
		}

		ret = sysfs_create_group(&pseudo_usb_host_device->kobj, &pesudo_usb_host_attr_group);
		if (ret) {
			device_destroy(&pseduo_usb_host_class, pseduo_usb_host_dev);
			cdev_del(&pseduo_usb_host_cdev);
			unregister_chrdev_region(pseduo_usb_host_dev, 1);
			return ret;
		}

		lock = 1;

		return ret;
	} else {
		return ret;
	}
}

static void pseudo_usb_host_delete(void)
{
	if (lock == 1) {
		device_destroy(&pseduo_usb_host_class, pseduo_usb_host_dev);
		cdev_del(&pseduo_usb_host_cdev);
		unregister_chrdev_region(pseduo_usb_host_dev, 1);

		lock = 0;
	}
}

static void usb_wq_handler(struct work_struct *work)
{
	if (enum_done == 1) {
		pseudo_usb_host_create();
	} else {
		pseudo_usb_host_delete();
	}
}

void pseudo_usb_host_active(void)
{
	enum_done = 1;
	state = "active";
	queue_work(usb_workqueue, &usb_work_item.work);
}
EXPORT_SYMBOL(pseudo_usb_host_active);

void pseudo_usb_host_suspend(void)
{
	state = "suspend";
}
EXPORT_SYMBOL(pseudo_usb_host_suspend);

int pseudo_usb_host_init(void)
{
	int ret = 0;

	ret = class_register(&pseduo_usb_host_class);
	if (ret < 0) {
		return printk("class register failed\n");
	}

	INIT_WORK(&usb_work_item.work, usb_wq_handler);
	usb_workqueue = alloc_workqueue("usb_workqueue", 0, 0);

	return 0;
}

void pseudo_usb_host_exit(void)
{
	class_destroy(&pseduo_usb_host_class);
	destroy_workqueue(usb_workqueue);
}
