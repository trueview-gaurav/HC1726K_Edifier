require recipes-devtools/gcc/gcc-cross_${PV}.bb
require recipes-devtools/gcc/gcc-crosssdk.inc

do_configure_append () {
    install -d ${STAGING_DIR_NATIVE}${SDKPATHNATIVE}/usr/include
    #touch ${STAGING_DIR_NATIVE}${SDKPATHNATIVE}/usr/include/limits.h
    if [ ! -s ${STAGING_DIR_NATIVE}${SDKPATHNATIVE}/usr/include/limits.h ]; then
        printf '%s\n' \
            '#ifndef __OE_SYSROOT_LIMITS_H__' \
            '#define __OE_SYSROOT_LIMITS_H__' \
            '#ifndef USHRT_MAX' \
            '# define USHRT_MAX __USHRT_MAX__' \
            '#endif' \
            '#ifndef UINT_MAX' \
            '# define UINT_MAX __UINT_MAX__' \
            '#endif' \
            '#ifndef ULONG_MAX' \
            '# define ULONG_MAX __ULONG_MAX__' \
            '#endif' \
            '#ifndef ULLONG_MAX' \
            '# define ULLONG_MAX __ULONG_LONG_MAX__' \
            '#endif' \
            '#endif' \
            > ${STAGING_DIR_NATIVE}${SDKPATHNATIVE}/usr/include/limits.h
    fi

    install -d ${B}/gcc
    echo "NATIVE_SYSTEM_HEADER_DIR = ${SDKPATHNATIVE}/usr/include" > ${B}/gcc/t-oe
}

