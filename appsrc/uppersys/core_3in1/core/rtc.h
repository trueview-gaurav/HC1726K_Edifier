#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <linux/rtc.h>
#include <linux/i2c.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

extern "C"
{
int rtc8563_set(struct rtc_time *tm);
int rtc8563_read(struct rtc_time *tm);
}