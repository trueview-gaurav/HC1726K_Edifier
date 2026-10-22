# gnome-common-native ships some ax_*.m4 which collide with autoconf-archive-native.
# For this toolchain-only build, drop aclocal macro installation to avoid sysroot overlap.
do_install_append_class-native() {
    rm -f ${D}${datadir}/aclocal/ax_*.m4 || true
}

