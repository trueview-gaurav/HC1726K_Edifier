#ifdef USE_NCNN
#include <FreeRTOS.h>
#include <task.h>
#include <stdlib.h>

/* Defining malloc/free should overwrite the
	standard versions provided by the compiler. */
void* malloc (size_t size)
{
	/* Call the FreeRTOS version of malloc. */
	return pvPortMalloc( size );
}
void free (void* ptr)
{
	/* Call the FreeRTOS version of free. */
	vPortFree( ptr );
}
#endif