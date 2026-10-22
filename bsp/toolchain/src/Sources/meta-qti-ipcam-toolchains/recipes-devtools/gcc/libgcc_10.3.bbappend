do_populate_sysroot[prefuncs] += "purge_libgcc_initial_from_target_sysroot"

purge_libgcc_initial_from_target_sysroot () {
    case "${PN}" in
        libgcc) ;;
        *) return 0 ;;
    esac

    bbnote "purge: remove libgcc-initial staged files/providers from target sysroot: ${STAGING_DIR_TARGET}"

    sysroot="${STAGING_DIR_TARGET}"

    rm -f "${sysroot}${base_prefix}/sysroot-providers/libgcc-initial" || true

    for trip in ${TARGET_SYS} ${QTI_IPCAM_GNUEABI_SYS}; do
        for f in crtbegin.o crtbeginS.o crtbeginT.o crtend.o crtendS.o crtfastmath.o libgcc.a libgcc_eh.a libgcov.a; do
            rm -f "${sysroot}${libdir}/${trip}/${PV}/${f}" || true
            rm -f "${sysroot}${libdir}/gcc/${trip}/${PV}/${f}" || true
        done
    done
}

EXTRA_OECONF_append = " \
    --disable-libmudflap \
    --disable-libgomp \
    --disable-libquadmath \
    --disable-libquadmath-support \
    --disable-libsanitizer \
    --disable-libmpx \
    --disable-libstdcxx-verbose \
    --enable-__cxa_atexit \
"

