set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER $ENV{CROSS_COMPILE}gcc)
set(CMAKE_CXX_COMPILER $ENV{CROSS_COMPILE}g++)

# set(CMAKE_C_COMPILER /users/imXXX/gcc-arm-10.3-2021.07-x86_64-arm-none-eabi/bin/arm-none-eabi-gcc)
# set(CMAKE_CXX_COMPILER /users/imXXX/gcc-arm-10.3-2021.07-x86_64-arm-none-eabi/bin/arm-none-eabi-g++)
# set(CMAKE_FIND_ROOT_PATH /users/imXXX/gcc-arm-10.3-2021.07-x86_64-arm-none-eabi/arm-none-eabi)

# set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_C_FLAGS "-march=armv7-a -mfpu=neon -mfloat-abi=hard" CACHE STRING "c flags")
set(CMAKE_CXX_FLAGS "-march=armv7-a -mfpu=neon -mfloat-abi=hard" CACHE STRING "c++ flags")

set(sdk_dir ../../../..)
include_directories(${sdk_dir}/remote/freertos/Demo/HC1703_1723_1753_1783S_GCC)

set(MACHINE "augentix" CACHE STRING "")