# Host g++ (Ubuntu 16.04) default is gnu++98; GCC 10 libcpp needs C++11
export BUILD_CXXFLAGS
BUILD_CXXFLAGS_append = " -std=gnu++11"

export CXXFLAGS_FOR_BUILD
CXXFLAGS_FOR_BUILD_append = " -std=gnu++11"

#CXXFLAGS_append = " -std=gnu++11"

# C headers dir inside the nativesdk sysroot
GCC_NSDK_C_HDRS = "${STAGING_DIR_HOST}${SDKPATHNATIVE}/usr/include"

#remove original isystem and add idirafter
CPPFLAGS_remove        = "-isystem${GCC_NSDK_C_HDRS}"
CFLAGS_remove          = "-isystem${GCC_NSDK_C_HDRS}"
CXXFLAGS_remove        = "-isystem${GCC_NSDK_C_HDRS}"
BUILD_CPPFLAGS_remove  = "-isystem${GCC_NSDK_C_HDRS}"
BUILD_CFLAGS_remove    = "-isystem${GCC_NSDK_C_HDRS}"
BUILD_CXXFLAGS_remove  = "-isystem${GCC_NSDK_C_HDRS}"

CPPFLAGS_append        = " -idirafter ${GCC_NSDK_C_HDRS}"
CFLAGS_append          = " -idirafter ${GCC_NSDK_C_HDRS}"
CXXFLAGS_append        = " -idirafter ${GCC_NSDK_C_HDRS}"
BUILD_CPPFLAGS_append  = " -idirafter ${GCC_NSDK_C_HDRS}"
BUILD_CFLAGS_append    = " -idirafter ${GCC_NSDK_C_HDRS}"
BUILD_CXXFLAGS_append  = " -idirafter ${GCC_NSDK_C_HDRS}"

EXTRA_OEMAKE_append = " \
  BUILD_CPPFLAGS='${BUILD_CPPFLAGS}' \
  BUILD_CFLAGS='${BUILD_CFLAGS}' \
  BUILD_CXXFLAGS='${BUILD_CXXFLAGS}' \
  CPPFLAGS='${CPPFLAGS}' \
  CFLAGS='${CFLAGS}' \
  CXXFLAGS='${CXXFLAGS}' \
"

EXTRA_OECONF_remove = " \
    --enable-lto \
    --enable-nls \
    --enable-multilib \
    --with-linker-hash-style=gnu \
    --enable-linker-build-id \
    --enable-poison-system-directories \
"

EXTRA_OECONF_append = " \
    --disable-lto \
    --disable-plugin \
    --disable-nls \
    --disable-multilib \
    --enable-target-optspace \
    --without-zstd \
    --with-mode=thumb \
    --disable-libmudflap \
    --disable-libgomp \
    --disable-libquadmath \
    --disable-libquadmath-support \
    --disable-libsanitizer \
    --disable-libmpx \
    --disable-libstdcxx-verbose \
    --enable-__cxa_atexit \
"

EXTRA_OECONF_append = " ${@bb.utils.contains('QTI_IPCAM_FLOATABI','hard',' --with-cpu=cortex-a7 --with-fpu=neon-vfpv4 --with-float=hard','',d)}"

do_install_append() {
    d="${D}${libdir}/gcc/${TARGET_SYS}/${BINV}/include-fixed/openssl"
    bbnote "Check include-fixed openssl dir: $d"
    if [ -d "$d" ]; then
        bbnote "Remove GCC include-fixed OpenSSL headers: $d"
        rm -rf "$d"
    fi
}
