# Install script for directory: /home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/src

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/libteec/cmake_install.cmake")
  include("/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/tee-supplicant/cmake_install.cmake")
  include("/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/libckteec/cmake_install.cmake")
  include("/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/libteeacl/cmake_install.cmake")
  include("/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/libseteec/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/yxy/qualcomm/SDK_R420_rc9_0908_SDK_rel/sdk/sample/optee/optee_client/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
