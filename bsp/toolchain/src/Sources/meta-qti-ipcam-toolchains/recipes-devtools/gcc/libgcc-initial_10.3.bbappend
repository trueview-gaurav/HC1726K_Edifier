FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://limits-bootstrap.h"

export BUILD_CPPFLAGS
BUILD_CPPFLAGS_append = " -include ${B}/limits-bootstrap.h"

BOOTSTRAP_HDRS = "${B}/bootstrap-headers"


do_configure_prepend () {
    install -d ${B}
    src="${WORKDIR}/limits-bootstrap.h"
    if [ ! -f "$src" ]; then
        src="${THISDIR}/files/limits-bootstrap.h"
    fi

    install -m 0644 "$src" ${B}/limits-bootstrap.h

    install -d ${BOOTSTRAP_HDRS}

    cat >${BOOTSTRAP_HDRS}/limits.h <<'EOF'
#ifndef _LIMITS_H
#define _LIMITS_H 1
#ifndef CHAR_BIT
# define CHAR_BIT __CHAR_BIT__
#endif
#ifndef USHRT_MAX
# define USHRT_MAX __USHRT_MAX__
#endif
#ifndef UINT_MAX
# define UINT_MAX __UINT_MAX__
#endif
#ifndef ULONG_MAX
# define ULONG_MAX __ULONG_MAX__
#endif
#ifndef ULLONG_MAX
# define ULLONG_MAX __ULONG_LONG_MAX__
#endif
#endif
EOF
}

EXTRA_OECONF_append = " \
  CPP='${CC} -E -idirafter ${BOOTSTRAP_HDRS}' \
  CPPFLAGS='-idirafter ${BOOTSTRAP_HDRS}' \
  CFLAGS='${CFLAGS} -idirafter ${BOOTSTRAP_HDRS}' \
"

do_configure[depends] += "gcc-cross-${TARGET_ARCH}:do_compile"

do_install_append() {
    dest="${D}${libdir}/gcc/${TARGET_SYS}/${PV}"
    install -d "$dest"

    lgcc="$(find ${B} -type f -name libgcc.a 2>/dev/null | head -n1 || true)"
    if [ -n "$lgcc" ]; then
        install -m 0644 "$lgcc" "$dest/"
    else
        bbfatal "libgcc.a not found in ${B}"
    fi

    for f in crtbegin.o crtend.o crtbeginS.o crtendS.o; do
        p="$(find ${B} -type f -name $f 2>/dev/null | head -n1 || true)"
        if [ -n "$p" ]; then
            install -m 0644 "$p" "$dest/"
        fi
    done
}

