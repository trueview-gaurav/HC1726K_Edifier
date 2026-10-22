FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://disable-gets-warn.patch"

do_install_append() {
    rm -f ${D}${includedir}/iconv.h
}

do_install_append_class_nativesdk() {
    rm -f ${D}${includedir}/iconv.h
}
