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

#define I2C_BUS  0x1
#define I2C_ADDR 0x51
#define REG_CTL1  0x00
#define REG_CTL2  0x01
#define REG_SC    0x02
#define REG_MN    0x03
#define REG_HR    0x04
#define REG_DT    0x05
#define REG_DW    0x06
#define REG_MO    0x07
#define REG_YR    0x08
#define RTC_SECTION_LEN 9
#define BCD_TO_BIN(val) (((val)&15) + ((val)>>4)*10)
#define BIN_TO_BCD(val) ((((val)/10)<<4) + (val)%10)

/* linux/i2c-dev.h from i2c-tools overwrites the one from linux uapi
 * and defines symbols already defined by linux/i2c.h.
 * Also, it defines a bunch of static inlines which we would rather NOT
 * inline. What a mess.
 * We need only these definitions from linux/i2c-dev.h:
 */
#define I2C_SLAVE			0x0703
#define I2C_SLAVE_FORCE			0x0706
#define I2C_FUNCS			0x0705
#define I2C_PEC				0x0708
#define I2C_SMBUS			0x0720
#define I2C_RDWR			0x0707
#define I2C_RDWR_IOCTL_MAX_MSGS		42
#define I2C_RDWR_IOCTL_MAX_MSGS_STR	"42"

struct i2c_rdwr_ioctl_data {
	struct i2c_msg *msgs;	/* pointers to i2c_msgs */
	__u32 nmsgs;		/* number of i2c_msgs */
};
/* end linux/i2c-dev.h */

static void i2c_set_slave_addr(int fd, int addr, int force)
{
	ioctl(fd, force ? I2C_SLAVE_FORCE : I2C_SLAVE, &addr);
}

/*
 * Opens the device file associated with given i2c bus.
 *
 * Upstream i2c-tools also support opening devices by i2c bus name
 * but we drop it here for size reduction.
 */
static int i2c_dev_open(int i2cbus)
{
	char filename[sizeof("/dev/i2c-%d") + sizeof(int)*3];
	int fd;

	sprintf(filename, "/dev/i2c-%d", i2cbus);
	fd = open(filename, O_RDWR);
	if (fd < 0) {
			printf("Error : can't open '%s'", filename);
	}

	return fd;
}

int i2c_set_regs(unsigned char reg, unsigned char const buf[], unsigned int len)
{
	int fd, i;
	int nmsgs_sent;
	struct i2c_msg msgs[2];
	struct i2c_rdwr_ioctl_data rdwr;

	fd = i2c_dev_open(I2C_BUS);
	if(fd < 0)
	{
		printf("Error : open i2c %d failed\n", I2C_BUS);
		return -1;
	}
	i2c_set_slave_addr(fd, I2C_ADDR, 0);

	msgs[0].addr = I2C_ADDR;
	msgs[0].flags = 0;
	msgs[0].len = len+1;
	msgs[0].buf = malloc(len + 1);
	msgs[0].buf[0] = reg;
	for(i = 0; i < len; i ++)
		msgs[0].buf[i + 1] = buf[i];

	rdwr.msgs = msgs;
	rdwr.nmsgs = 1;
	nmsgs_sent = ioctl(fd, I2C_RDWR, &rdwr);
	if (nmsgs_sent < 1)
		printf("warning: only %u(1) messages sent", nmsgs_sent);

	close(fd);
	free(msgs[0].buf);

	return 0;
}

int i2c_read_regs(unsigned char reg, unsigned char const buf[], unsigned int len)
{
	int fd;
	int nmsgs_sent;
	struct i2c_msg msgs[2];
	struct i2c_rdwr_ioctl_data rdwr;

	fd = i2c_dev_open(I2C_BUS);
	if(fd < 0)
		{
			printf("open i2c %d failed\n", I2C_BUS);
			return -1;
		}
	i2c_set_slave_addr(fd, I2C_ADDR, 0);

	msgs[0].addr = I2C_ADDR;
	msgs[0].flags = 0;
	msgs[0].len = 1;
	msgs[0].buf = &reg;

	msgs[1].addr = I2C_ADDR;
	msgs[1].flags = I2C_M_RD;
	msgs[1].len = len;
	msgs[1].buf = buf;

	rdwr.msgs = msgs;
	rdwr.nmsgs = 2;
	nmsgs_sent = ioctl(fd, I2C_RDWR, &rdwr);
	if (nmsgs_sent < 2)
		printf("warning: only %u(2) messages sent", nmsgs_sent);

	close(fd);

	return 0;
}

int rtc8563_set(struct rtc_time *tm)
{	
   int sr;
   unsigned char regs[RTC_SECTION_LEN] = { 0 };

   printf("set_time Date(y/m/d):%d/%d/%d Time(h/m/s):%d/%d/%d\n",tm->tm_year,tm->tm_mon,tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);

   regs[REG_SC] = BIN_TO_BCD(tm->tm_sec) & 0x7f;
   regs[REG_MN] = BIN_TO_BCD(tm->tm_min) & 0x7f;
   regs[REG_HR] = BIN_TO_BCD(tm->tm_hour) & 0x3f;

   regs[REG_DT] = BIN_TO_BCD(tm->tm_mday) & 0x3f;
   regs[REG_MO] = BIN_TO_BCD(tm->tm_mon + 1) & 0x1f;
   regs[REG_YR] = BIN_TO_BCD(tm->tm_year % 100);

   regs[REG_DW] = BIN_TO_BCD(tm->tm_wday) & 7;

   /* write RTC registers */
   i2c_set_regs(0, regs, RTC_SECTION_LEN);

   return 0;    	
}

int rtc8563_read(struct rtc_time *tm)
{
   unsigned char regs[RTC_SECTION_LEN] = { 0, };

   i2c_read_regs(0, regs, RTC_SECTION_LEN);

   tm->tm_sec = BCD_TO_BIN(regs[REG_SC] & 0x7f);
   tm->tm_min = BCD_TO_BIN(regs[REG_MN] & 0x7f);
   tm->tm_hour = BCD_TO_BIN(regs[REG_HR] & 0x3f);
   tm->tm_mday = BCD_TO_BIN(regs[REG_DT] & 0x3f);
   tm->tm_mon = BCD_TO_BIN(regs[REG_MO] & 0x1f) - 1; 
   tm->tm_year = BCD_TO_BIN(regs[REG_YR]) + 100;
   tm->tm_wday = BCD_TO_BIN(regs[REG_DW] & 7);
   
   printf("***** read_time Date(y/m/d):%d/%d/%d Time(h/m/s):%d/%d/%d\n",tm->tm_year + 1900,tm->tm_mon + 1,tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);
   return 0;
}
