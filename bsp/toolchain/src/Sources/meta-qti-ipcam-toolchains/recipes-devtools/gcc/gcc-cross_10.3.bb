require recipes-devtools/gcc/gcc-${PV}.inc
require gcc-cross.inc

do_configure_append () {
    #install -d ${STAGING_DIR_NATIVE}${SDKPATHNATIVE}/usr/include
    #touch ${STAGING_DIR_NATIVE}${SDKPATHNATIVE}/usr/include/limits.h

    install -d ${B}/gcc
    #echo "NATIVE_SYSTEM_HEADER_DIR = ${SDKPATHNATIVE}/usr/include" > ${B}/gcc/t-oe
}

