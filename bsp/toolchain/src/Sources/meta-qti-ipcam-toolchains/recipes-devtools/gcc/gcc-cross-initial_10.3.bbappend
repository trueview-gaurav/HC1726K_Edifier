
DEPENDS_append = " patchelf-native"

fix_cc1_rpath() {
    local destdir="${SYSROOT_DESTDIR}${STAGING_DIR_NATIVE}/usr/libexec/${TARGET_SYS}.${PN}/gcc/${TARGET_SYS}/${PV}"
    for exe in cc1 cc1plus; do
        if [ -f "${destdir}/${exe}" ]; then
            bbnote "fix rpath: ${destdir}/${exe}"
            patchelf --set-rpath "${STAGING_LIBDIR_NATIVE}:${STAGING_BASE_LIBDIR_NATIVE}" "${destdir}/${exe}"
        else
            bbnote "not found, skip: ${destdir}/${exe}"
        fi
    done
}


do_populate_sysroot[postfuncs] += "fix_cc1_rpath"

