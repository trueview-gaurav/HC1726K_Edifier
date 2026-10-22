set (CMAKE_SYSTEM_NAME "Generic"             CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER CACHE STRING "")


string (TOLOWER "FreeRTOS"                PROJECT_SYSTEM)
string (TOUPPER "FreeRTOS"                PROJECT_SYSTEM_UPPER)

set(sdk_dir ../../..)
set(LIBMETAL_LIB ${sdk_dir}/remote/library/libmetal/build/freertos/lib/libmetal.so)
set(LIBMETAL_INCLUDE_DIR ${sdk_dir}/remote/library/libmetal/build/freertos/lib/include)

set(CMAKE_SYSTEM_PROCESSOR arm)
set (MACHINE                "augentix"          CACHE STRING "")
include_directories(${sdk_dir}/remote/freertos/Source/include)
include_directories(${sdk_dir}/remote/freertos/Demo/HC1703_1723_1753_1783S_GCC)
include_directories(${sdk_dir}/remote/freertos/Source/portable/GCC/ARM_CA7)

set(CMAKE_C_COMPILER $ENV{CROSS_COMPILE}gcc)
set(CMAKE_CXX_COMPILER $ENV{CROSS_COMPILE}g++)

set (CMAKE_C_FLAGS          "-g -mcpu=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard -Os" CACHE STRING "")

set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER CACHE STRING "")

