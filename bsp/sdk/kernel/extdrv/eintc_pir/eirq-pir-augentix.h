#include <linux/ioctl.h>
#include <linux/types.h>

#define PIR_IOCTL_BASE 'k'
#define IOC_PIR_SETTIMEOUT _IO(PIR_IOCTL_BASE, 0)
#define IOC_PIR_SENSITIVITY _IO(PIR_IOCTL_BASE, 1)
