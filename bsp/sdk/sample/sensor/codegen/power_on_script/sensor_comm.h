#ifndef SENSOR_COMM_H_
#define SENSOR_COMM_H_

#include <stdint.h>

typedef struct {
	unsigned reg;
	unsigned val;
} SensCmd;

// GPIO
void gpio_direction_output(int gpio_id, int level);
void gpio_set_value(int gpio_id, int level);

// Delay/sleep
void mdelay(unsigned long msec);
void udelay(unsigned long usec);

// I2C
int i2c_set_bus_num(unsigned int bus);
int i2c_write_seq(int slave_addr, const SensCmd *cmd, int num_of_write, int addr_len, int data_len);

#endif
