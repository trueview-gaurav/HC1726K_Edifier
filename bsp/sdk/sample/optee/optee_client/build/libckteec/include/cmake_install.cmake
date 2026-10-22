# Install script for directory: /home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/src/libckteec/include

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/src/libckteec/include/ck_debug.h"
    "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/src/libckteec/include/pkcs11.h"
    "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/src/libckteec/include/pkcs11_ta.h"
    )
endif()

