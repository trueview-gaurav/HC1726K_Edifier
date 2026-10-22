#include "utils/printf.h"
#include "tensorflow/lite/micro/debug_log.h"

extern "C" void DebugLog(const char *s)
{
#ifndef TF_LITE_STRIP_ERROR_STRINGS
	printf("%s", s);
#endif
}
