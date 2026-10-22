# Install script for directory: /home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/src/tee-supplicant

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/out")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/yxy/qualcomm/r4.1_app-iot_release/toolchain/arm-augentix-linux-uclibcgnueabihf/bin/arm-augentix-linux-uclibcgnueabihf-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/sbin/tee-supplicant" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/sbin/tee-supplicant")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/sbin/tee-supplicant"
         RPATH "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/out/lib/tee-supplicant/plugins/")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sbin" TYPE EXECUTABLE FILES "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/tee-supplicant/tee-supplicant")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/sbin/tee-supplicant" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/sbin/tee-supplicant")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/sbin/tee-supplicant"
         OLD_RPATH "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/libteec::::::::::::::::::"
         NEW_RPATH "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/out/lib/tee-supplicant/plugins/")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/yxy/qualcomm/r4.1_app-iot_release/toolchain/arm-augentix-linux-uclibcgnueabihf/bin/arm-augentix-linux-uclibcgnueabihf-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/sbin/tee-supplicant")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/systemd/system" TYPE FILE FILES "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/tee-supplicant/tee-supplicant@.service")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/etc/udev/rules.d" TYPE FILE FILES "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/tee-supplicant/optee-udev.rules")
endif()

