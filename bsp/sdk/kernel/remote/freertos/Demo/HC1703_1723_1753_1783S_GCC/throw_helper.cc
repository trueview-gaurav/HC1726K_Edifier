#ifdef USE_ROSA
#include "utils/printf.h"

namespace std {
	void __throw_bad_alloc()
	{
//		Serial.println("Unable to allocate memory");
		while (true) {
			printf("[RTOS]: BAD ALLOC\n");
		};
	}

	void __throw_length_error( char const*e )
	{
//		Serial.print("Length Error :");
//		Serial.println(e);
		while (true) {
			printf("[RTOS]: LENGTH ERROR %s\n", e);
		};
	}
}
#endif //USE_ROSA
