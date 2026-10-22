# Workaround: uClibc ldso fails to compile in Thumb2 with GCC 10.3
TARGET_CFLAGS_append_pn-uclibc = " -marm"
TARGET_CPPFLAGS_append_pn-uclibc = " -marm"
TARGET_CFLAGS_remove_pn-uclibc = " -Wno-nonnull-compare"
do_install_append_pn-uclibc = ""

# make sure libthread_db exist
#ALLOW_EMPTY_${PN}-thread-db = "1"
ALLOW_EMPTY_uclibc-thread-db = "1"

# modified libdir
FILES_uclibc-thread-db_append = " ${libdir}/libthread_db*.so*"
#FILES_${PN}-thread-db_append = " ${libdir}/libthread_db*.so*"
#FILES_${PN}-thread-db_append = " ${libdir}/libthread_db*.so* ${base_libdir}/libthread_db*.so*"

# Add defconfig to SRC_URI
FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += " \
    file://defconfig \
    file://defconfig.soft \
"

QTI_IPCAM_FLOATABI ?= "hard"

qti_ipcam_select_defconfig() {
    bbnote "uclibc: QTI_IPCAM_FLOATABI='${QTI_IPCAM_FLOATABI}'"
    if [ "${QTI_IPCAM_FLOATABI}" = "soft" ]; then
        bbnote "uclibc: select defconfig.soft -> defconfig"
        cp -f ${WORKDIR}/defconfig.soft ${WORKDIR}/defconfig
    else
        bbnote "uclibc: use defconfig (hard default)"
    fi
}

do_configure[prefuncs] += "qti_ipcam_select_defconfig"

do_install_append() {
    install -d ${D}${includedir}

    if [ -f ${S}/include/iconv.h ]; then
        install -m 0644 ${S}/include/iconv.h ${D}${includedir}/iconv.h
    else
        bbfatal "uclibc-ng iconv.h not found at ${S}/include/iconv.h"
    fi
}
