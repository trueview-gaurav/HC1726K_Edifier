#ifndef AMP_EARLY_CHANN_H
#define AMP_EARLY_CHANN_H

// Prototypes
typedef uint32_t (*early_handler)(void *data);

struct amp_early_handle {
	uint32_t type;
	early_handler handler;
};

/**************** USE customizations ****************/

// Request types
enum { AMP_EARLY_STRING_CAPITAL,
       AMP_EARLY_FALSE_ALARM,

       AMP_EARLY_TYPE_NUM, //AMP_EARLY_TYPE_NUM always at the end
};

// Handler for each request type
uint32_t string_capital(void *data);

#ifdef __cplusplus
extern "C" {
#endif

uint32_t false_alarm_detect(void *data);

#ifdef __cplusplus
}
#endif

#define AMP_EARLY_CHANN_HANDLE_LIST                                                                          \
	{                                                                                                    \
		{ AMP_EARLY_STRING_CAPITAL, string_capital }, { AMP_EARLY_FALSE_ALARM, false_alarm_detect }, \
	}

#endif
