#ifndef AMP_DRIVER_H
#define AMP_DRIVER_H

/* If LOW_LEVEL_LOG enabled(1), the early logs will be direct to
 * UART debug port before Linux AMP driver ready. After Linux AMP
 * driver ready, the RTOS log printed by Linux AMP driver. 
 * If LOW_LEVEL_LOG disabled(0), the early logs will be ignored.
 * */
#define LOW_LEVEL_LOG 0

void amp_drv_init(void);

#endif
