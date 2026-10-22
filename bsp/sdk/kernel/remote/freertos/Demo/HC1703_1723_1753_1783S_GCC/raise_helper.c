// #ifdef USE_ROSA
#include <signal.h>
#include "utils/printf.h"

int raise(int signum)
{
	printf("[RTOS]: RAISE ERROR\n");
	return 0;
}
// #endif //USE_ROSA