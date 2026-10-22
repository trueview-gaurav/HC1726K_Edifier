PV = "1.0.38"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += " \
  file://uclibc-yocto-bootstrap.h \
  file://0001-preinclude-yocto-bootstrap.patch \
  file://0002-unwind-forcedunwind-weak.patch \
  file://0003-upgrade-arm-string-routines.patch \
  file://0004-arm-export-gnu-unwind-find-exidx.patch \
"

SRC_URI_remove = "git://uclibc-ng.org/git/uclibc-ng file://0001-Disable-lrount_tes-function.patch"
SRC_URI_prepend = "https://downloads.uclibc-ng.org/releases/${PV}/uClibc-ng-${PV}.tar.xz "

LIC_FILES_CHKSUM_remove = "file://${S}/test/regex/testregex.c;beginline=1;endline=31;md5=234efb227d0a40677f895e4a1e26e960"


SRC_URI[sha256sum] = "b1a3328330d2c94a2bec8c1436a8f15673f3a9b5895e155efc2e91d4e1882570"

S = "${WORKDIR}/uClibc-ng-${PV}"

# uClibc utilities may be linked without GNU_HASH; allow in short-term bring-up
INSANE_SKIP_${PN} += "ldflags"
INSANE_SKIP_${PN}-utils += "ldflags"
INSANE_SKIP_ldd += "ldflags"

# gcc 5.3 doesn't know this option; ensure it's really removed (no leading spaces)
CFLAGS_remove = "-Wno-nonnull-compare"
TARGET_CFLAGS_remove = "-Wno-nonnull-compare"
TARGET_CPPFLAGS_append = " -D_GNU_SOURCE"

EXTRA_OEMAKE_append = " V=1 "

# uClibc.distro + defconfig => new uClibc.distro
do_configure_prepend() {
    cat ${WORKDIR}/uClibc.distro ${WORKDIR}/defconfig > ${WORKDIR}/uClibc.distro.merged
    mv ${WORKDIR}/uClibc.distro.merged ${WORKDIR}/uClibc.distro
}

do_configure_append () {
    install -m 0644 ${WORKDIR}/uclibc-yocto-bootstrap.h ${S}/include/uclibc-yocto-bootstrap.h
    # uClibc recipe ends up with final config at ${S}/.config (sometimes ${B}/.config)
    cfg="${S}/.config"
    [ -f "${B}/.config" ] && cfg="${B}/.config"

    if [ ! -f "$cfg" ]; then
        bbfatal "uclibc: cannot find .config (checked: ${S}/.config and ${B}/.config)"
    fi

    bbnote "uclibc: force-enable SSP options in $cfg"

    for opt in UCLIBC_HAS_SSP UCLIBC_BUILD_SSP SSP_QUICK_CANARY; do
        # turn '# OPT is not set' into 'OPT=y'
        if grep -q "^# ${opt} is not set" "$cfg"; then
            sed -i "s/^# ${opt} is not set/${opt}=y/" "$cfg"
        fi
        # normalize existing assignment
        if grep -q "^${opt}=" "$cfg"; then
            sed -i "s/^${opt}=.*/${opt}=y/" "$cfg"
        fi
        # if still missing, append
        grep -q "^${opt}=y$" "$cfg" || echo "${opt}=y" >> "$cfg"
    done

    # ----------------------------
    # Code size alignment with original toolchain
    # ----------------------------
    bbnote "uclibc: sanitize UCLIBC_EXTRA_CFLAGS / optimization for size (match original)"

    # Original toolchain had __UCLIBC_EXTRA_CFLAGS__ == ""
    if grep -q '^UCLIBC_EXTRA_CFLAGS=' "$cfg"; then
        sed -i 's/^UCLIBC_EXTRA_CFLAGS=.*/UCLIBC_EXTRA_CFLAGS=""/' "$cfg"
    else
        echo 'UCLIBC_EXTRA_CFLAGS=""' >> "$cfg"
    fi

    # Prefer size inside uClibc build system
    if grep -q '^UCLIBC_BUILD_OPTIMIZATION=' "$cfg"; then
        sed -i 's/^UCLIBC_BUILD_OPTIMIZATION=.*/UCLIBC_BUILD_OPTIMIZATION="-Os"/' "$cfg"
    else
        echo 'UCLIBC_BUILD_OPTIMIZATION="-Os"' >> "$cfg"
    fi

    # These two were different in your header diff (old: unset, new: enabled)
    for opt in UCLIBC_HAS_CONTEXT_FUNCS UCLIBC_HAS_ARGP; do
        if grep -q "^${opt}=" "$cfg"; then
            sed -i "s/^${opt}=.*/# ${opt} is not set/" "$cfg"
        else
            grep -q "^# ${opt} is not set" "$cfg" || echo "# ${opt} is not set" >> "$cfg"
        fi
    done

    egrep '^(UCLIBC_EXTRA_CFLAGS|UCLIBC_BUILD_OPTIMIZATION)=' "$cfg" || true
    egrep '^# UCLIBC_HAS_(CONTEXT_FUNCS|ARGP) is not set' "$cfg" || true

    # re-run oldconfig so generated headers/deps match final settings
    yes "" | oe_runmake oldconfig
}


# make bootstrap stage has crtbegin.o / libgcc
DEPENDS += " libgcc-initial"
do_compile[depends] += "libgcc-initial:do_populate_sysroot"
do_install[depends]  += "libgcc-initial:do_populate_sysroot"

do_compile_prepend() {
    bbnote "uclibc: CC=${CC}"
    bbnote "uclibc: TARGET_SYS=${TARGET_SYS}"
    bbnote "uclibc: TARGET_PREFIX=${TARGET_PREFIX}"

    # For recipe sysroot primary(avoid the tmp file is cleand by rm_work)
    sr="${RECIPE_SYSROOT:-${STAGING_DIR_TARGET}}"
    bbnote "uclibc: sysroot=${sr}"

    # ----------------------------
    # 1) Find libgcc from target
    # ----------------------------
    lgcc="$(${CC} -print-libgcc-file-name 2>/dev/null || true)"

    # It's failed while gcc return "libgcc.a" or path not exist or in nativesdk
    if [ -z "$lgcc" ] || [ "$lgcc" = "libgcc.a" ] || [ ! -e "$lgcc" ] || echo "$lgcc" | grep -q 'nativesdk'; then
        lgcc="$(find "$sr" -type f -name libgcc.a \
            \( -path '*/usr/lib/gcc/*/*/libgcc.a' -o -path '*/lib/gcc/*/*/libgcc.a' \) \
            2>/dev/null | head -n1 || true)"
    fi

    if [ -z "$lgcc" ] || [ ! -e "$lgcc" ] || echo "$lgcc" | grep -q 'nativesdk'; then
        bbfatal "uclibc: target libgcc.a not found in sysroot (got: '$lgcc')"
    fi

    # ----------------------------
    # 2) find libgcc_eh.a from sysroot
    # ----------------------------
    lgcceh="$(find "$sr" -type f -name libgcc_eh.a \
        \( -path '*/usr/lib/gcc/*/*/libgcc_eh.a' -o -path '*/lib/gcc/*/*/libgcc_eh.a' \) \
        2>/dev/null | head -n1 || true)"

    bbnote "uclibc: using libgcc:    $lgcc"
    if [ -n "$lgcceh" ] && [ -e "$lgcceh" ]; then
        bbnote "uclibc: using libgcc_eh: $lgcceh"
    else
        bbnote "uclibc: libgcc_eh.a not found; will try using libgcc.a only"

        # ----------------------------
        # 3) find libgcc_s
        # ----------------------------
        lgccs="$(find "$sr" -type f \( -name 'libgcc_s.so.1' -o -name 'libgcc_s.so' -o -name 'libgcc_s.so.*' \) \
            2>/dev/null | head -n1 || true)"

        have_unwind=0

        # a) find symbol _Unwind_Resume in libgcc.a 
        if command -v ${TARGET_PREFIX}nm >/dev/null 2>&1; then
            if ${TARGET_PREFIX}nm "$lgcc" 2>/dev/null | grep -q '_Unwind_Resume'; then
                have_unwind=1
            fi
        elif command -v nm >/dev/null 2>&1; then
            if nm "$lgcc" 2>/dev/null | grep -q '_Unwind_Resume'; then
                have_unwind=1
            fi
        fi

        # b) find the symbol in libgcc_s.so.* if not found in libgcc.a
        if [ "$have_unwind" -eq 0 ] && [ -n "$lgccs" ] && [ -e "$lgccs" ]; then
            if command -v readelf >/dev/null 2>&1; then
                if readelf -Ws "$lgccs" 2>/dev/null | grep -q '_Unwind_Resume'; then
                    bbnote "uclibc: unwind symbol found in libgcc_s: $lgccs"
                    have_unwind=1
                fi
            fi
        fi

        if [ "$have_unwind" -eq 0 ]; then
            bbwarn "uclibc: unwind symbol not found in libgcc.a nor libgcc_s (early-stage toolchain?)"
        fi

        cp -a "$lgcc" "${B}/libgcc.a"
        return 0
    fi

    : ${AR:=${TARGET_PREFIX}ar}
    : ${RANLIB:=${TARGET_PREFIX}ranlib}

    rm -f "${B}/libgcc.a"
    rm -rf "${B}/.libgcc-merge"
    mkdir -p "${B}/.libgcc-merge"
    cd "${B}/.libgcc-merge"

    ${AR} x "$lgcc"
    ${AR} x "$lgcceh"

    ${AR} cr "${B}/libgcc.a" *.o
    ${RANLIB} "${B}/libgcc.a" || true

    cd "${B}"
    rm -rf "${B}/.libgcc-merge"
}

python __anonymous () {
    import re

    s = d.getVar('do_install', False) or ''

    pat = r'^\s*oe_runmake\s+.*-C\s+utils\s+utils_install\s*$'
    s2, n = re.subn(pat, '\ttrue', s, flags=re.M)

    if not s2.endswith('\n'):
        s2 += '\n'

    d.setVar('do_install', s2)

    if n == 0:
        bb.warn('uclibc: did not find utils_install line inside do_install')
    else:
        bb.note('uclibc: removed utils_install from do_install (%d occurrence(s))' % n)
}

do_install_append() {
    for d in ${D}${base_libdir} ${D}${libdir}; do
        if [ -e "$d/libm.so.0" ] && [ ! -e "$d/libm.so" ]; then
            ln -sf libm.so.0 "$d/libm.so"
        fi
    done
}

FILES_${PN}-dev_append = " ${base_libdir}/libm.so ${libdir}/libm.so"
