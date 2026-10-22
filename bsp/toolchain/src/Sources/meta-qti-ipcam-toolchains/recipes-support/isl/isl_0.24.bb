SUMMARY = "Integer Set Library (ISL)"
DESCRIPTION = "ISL is a library for manipulating sets and relations of integer points bounded by linear constraints."
HOMEPAGE = "https://libisl.sourceforge.io/"
SECTION = "libs"
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://LICENSE;md5=0c7c9ea0d2ff040ba4a25afa0089624b"

SRC_URI = "https://libisl.sourceforge.io/isl-${PV}.tar.xz"
SRC_URI[sha256sum] = "043105cc544f416b48736fff8caf077fb0663a717d06b1113f16e391ac99ebad"

S = "${WORKDIR}/isl-${PV}"

DEPENDS = "gmp"
DEPENDS_append_class-nativesdk = " nativesdk-glibc"

inherit autotools pkgconfig

EXTRA_OECONF += " --enable-shared --disable-static "
FILES_${PN} += "${libdir}/libisl.so.*"
FILES_${PN}-dev += "${libdir}/libisl.so"

BBCLASSEXTEND = "native nativesdk"

# nativesdk-isl: avoid breaking libstdc++ <cstdlib>'s #include_next <stdlib.h>
# Removing redundant -isystem ${STAGING_INCDIR} so that stdlib.h is found via the builtin sysroot include chain.
CPPFLAGS_remove_class-nativesdk = "-isystem${STAGING_INCDIR}"
CFLAGS_remove_class-nativesdk   = "-isystem${STAGING_INCDIR}"
CXXFLAGS_remove_class-nativesdk = "-isystem${STAGING_INCDIR}"
