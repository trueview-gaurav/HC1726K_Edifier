set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set (MACHINE                "augentix"          CACHE STRING "")

set(sdk_dir ../../../../..)
set(libmetal_dir ${sdk_dir}/sdk/sample/ampc/library/libmetal)

set(LIBMETAL_LIB ${libmetal_dir}/lib/libmetal.so.1)
set(LIBMETAL_INCLUDE_DIR ${libmetal_dir}/include)

if ($ENV{CROSS_COMPILE} STREQUAL "arm-linux-gnueabihf-")
	set(LIBSYSFS_LIBRARY ${sdk_dir}/buildroot/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/lib/libsysfs.so)
	set(LIBSYSFS_INCLUDE_DIR ${sdk_dir}/buildroot/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/sysfs)
elseif ($ENV{CROSS_COMPILE} STREQUAL "arm-augentix-linux-uclibcgnueabi-")
	set(LIBSYSFS_LIBRARY ${sdk_dir}/buildroot/output/host/arm-buildroot-linux-uclibcgnueabi/sysroot/usr/lib/libsysfs.so)
	set(LIBSYSFS_INCLUDE_DIR ${sdk_dir}/buildroot/output/host/arm-buildroot-linux-uclibcgnueabi/sysroot/usr/include/sysfs)
elseif ($ENV{CROSS_COMPILE} STREQUAL "arm-augentix-linux-uclibcgnueabihf-")
	set(LIBSYSFS_LIBRARY ${sdk_dir}/buildroot/output/host/arm-buildroot-linux-uclibcgnueabihf/sysroot/usr/lib/libsysfs.so)
	set(LIBSYSFS_INCLUDE_DIR ${sdk_dir}/buildroot/output/host/arm-buildroot-linux-uclibcgnueabihf/sysroot/usr/include/sysfs)
else ()
	set(LIBSYSFS_LIBRARY ${sdk_dir}/buildroot/output/host/arm-buildroot-linux-gnueabi/sysroot/usr/lib/libsysfs.so)
	set(LIBSYSFS_INCLUDE_DIR ${sdk_dir}/buildroot/output/host/arm-buildroot-linux-gnueabi/sysroot/usr/include/sysfs)
endif()

set(CMAKE_C_COMPILER $ENV{CROSS_COMPILE}gcc)
set(CMAKE_CXX_COMPILER $ENV{CROSS_COMPILE}g++)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER CACHE STRING "")
