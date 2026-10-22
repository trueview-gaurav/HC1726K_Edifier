/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef LIB_IR_CONTROL_H_
#define LIB_IR_CONTROL_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <pthread.h>
#include <syslog.h>

typedef enum { IR_UNKNOWN = 0, IR_AUTO, IR_ON, IR_OFF, _IR_MAX } IR_Mode;
typedef enum { DAY, NIGHT } DayNIghtMode;
typedef enum { IR_MODE_UNKNOWN = 0, IR_NIGHT, IR_DAY, IR_FORCE_DAY } IrModeReturn;

#define ir_control_log_debug(fmt, args...) syslog(LOG_LOCAL7 | LOG_DEBUG, "[IR control][Debug] " fmt, ##args)
#define ir_control_log_err(fmt, args...) syslog(LOG_LOCAL7 | LOG_ERR, "[IR control][Error] " fmt, ##args)

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define CLAMP(val, min, max) (((val) < (min)) ? (min) : (((val) > (max)) ? (max) : (val)))

#define IIR_PRC (8)
#define IIR_UNIT (1 << IIR_PRC)

typedef int (*IR_INIT_CB)(void *data);
typedef int (*IR_UNINIT_CB)(void *data);
typedef int (*IR_SWITCH_MODE_CB)(IR_Mode mode, void *data);
typedef int (*IR_SWITCH_IR_CUT_CB)(int enabled, void* data);
typedef int (*IR_ENABLE_LIGHT_CB)(int enabled, void* data);
typedef int (*IR_CHANGE_IR_LIGHT_CB)(int strength, void *data);
typedef int (*IR_SWITCH_DAY_NIGHT_CB)(DayNIghtMode mode, void *data);
typedef IrModeReturn (*IR_EXTRA_NIGHT_TO_DAY_CB)(void *data);
typedef int (*IR_CAL_SCENE_LUMA_CB)(int dev, int path, int *pscene_luma, void* data);


/* for paramters tuning*/
typedef struct {
	int sleepIntervalus;
	int force_day_th;
	int day_th;
	int night_th;
	int day_delay;
	int night_delay;
	int iir_current_weight;
	int ir_amplitude_ratio; /*uint = 1/ 1024 , default: 44*/
	int ir_led_luma_ratio_thr;
	int total_luma_delta_thr;
	int check_ir_sur_luma_thr;
	int cloth_thr;
	int ev_responce_us;
	int first_night_ev_response_us;
	int ir_light_strength[5]; /*you can give 5 differnt strength to your ir light*/
} IRConfig;

typedef struct {
	IR_INIT_CB initCb;
	IR_UNINIT_CB uninitCb;
	IR_SWITCH_MODE_CB switchModeCb;
	IR_SWITCH_IR_CUT_CB switchIRcutCb;
	IR_ENABLE_LIGHT_CB enabledLightCb;
	IR_CHANGE_IR_LIGHT_CB
	        switchIRStrengthCb; /*can't change after init, if your ir light can't change , please don't assign this*/
	IR_SWITCH_DAY_NIGHT_CB switchDayNightCb;
	IR_EXTRA_NIGHT_TO_DAY_CB extraNighttoDayCb;
	IR_CAL_SCENE_LUMA_CB calSceneLumaCb;
	IR_Mode mode;
	IRConfig conf;
	void *pData; /* this data ptr will pass to all cb*/
} IrControl;

int IR_init(void);
int IR_exit(void);
int IR_setConfig(IrControl *p_ir_cfg);
int IR_getConfig(IrControl *p_ir_cfg);
int IR_run(void);
int IR_setSwitchDayNightCb(IR_SWITCH_DAY_NIGHT_CB cb);
int IR_setSwitchIrModeCb(IR_SWITCH_MODE_CB cb);
int IR_setMode(IR_Mode mode);
int IR_getMode(IR_Mode *pMode);
int IR_getDayNightMode(DayNIghtMode *mode);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
