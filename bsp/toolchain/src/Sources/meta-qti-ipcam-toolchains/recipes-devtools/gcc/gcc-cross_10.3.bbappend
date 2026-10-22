# Make sure gcc-cross does NOT try to touch host /usr/include.
EXTRA_OECONF_remove = "--with-native-system-header-dir=/usr/include"
EXTRA_OECONF_append = " --with-native-system-header-dir=${STAGING_DIR_NATIVE}/usr/include "

# Keep any legacy stub task (no graph wiring)
# Where hardknott backport expects the stashed builddir
COMPONENTS_DIR ?= "${TMPDIR}/components"

# Re-introduce stash task, but nuke any legacy depends that caused cycles
do_gcc_stash_builddir[depends] = ""
do_gcc_stash_builddir[nostamp] = "1"

# krogoth's chrpath.process_dir() doesn't accept keyword "break_hardlinks"
python gcc_stash_builddir_fixrpaths() {
    stash = d.getVar("BUILDDIRSTASH", True)

    # Newer signature (hardknott-ish): process_dir("/", stash, d, break_hardlinks=True)
    try:
        process_dir("/", stash, d, break_hardlinks=True)
        return
    except TypeError:
        pass

    # Older signature may accept 4th positional arg (no keyword support)
    try:
        process_dir("/", stash, d, True)
        return
    except TypeError:
        pass

    # Oldest: only 3 args
    process_dir("/", stash, d)
}


do_gcc_stash_builddir() {
    dst="${COMPONENTS_DIR}/${BUILD_ARCH}/gcc-stashed-builddir-${TARGET_SYS}"
    bbnote "Stash gcc builddir: ${B} -> ${dst}"
    rm -rf "${dst}"
    install -d "${dst}"

    # Copy build tree (tar keeps links/perm decently and is portable)
    ( cd "${B}" && tar -cf - . ) | ( cd "${dst}" && tar -xf - )

    # Optional marker used by staging_processfixme in some backports
    : > "${dst}/fixmepath"
}


# Some sub-make invocations ignore exported env and use BUILD_CXXFLAGS/CXXFLAGS from Makefile.
# Force C++11 at make invocation level so both lex.o commands get it.
EXTRA_OEMAKE_append = " \
  BUILD_CXXFLAGS='${BUILD_CXXFLAGS} -std=gnu++11' \
  CXXFLAGS_FOR_BUILD='${CXXFLAGS_FOR_BUILD} -std=gnu++11' \
  CXXFLAGS='${CXXFLAGS} -std=gnu++11' \
"

# Force C++11 for gcc build tools on Ubuntu 16.04 (g++5 defaults to gnu++98)
do_configure_prepend() {
    # krogoth 沒有 RECIPE_SYSROOT/RECIPE_SYSROOT_NATIVE 這種變數
    # hardknott backport 的 gcc recipe 會用它來 touch ${RECIPE_SYSROOT}/usr/include/limits.h
    # 如果是空字串，就會變成 /usr/include/limits.h -> permission denied
    export RECIPE_SYSROOT="${STAGING_DIR_TARGET}"
    export RECIPE_SYSROOT_NATIVE="${STAGING_DIR_NATIVE}"
    export CXXFLAGS_FOR_BUILD="${CXXFLAGS_FOR_BUILD} -std=gnu++11"
    export BOOT_CXXFLAGS="${BOOT_CXXFLAGS} -std=gnu++11"
    export CXXFLAGS="${CXXFLAGS} -std=gnu++11"
}

do_compile_prepend() {
    export CXXFLAGS_FOR_BUILD="${CXXFLAGS_FOR_BUILD} -std=gnu++11"
    export BOOT_CXXFLAGS="${BOOT_CXXFLAGS} -std=gnu++11"
    export CXXFLAGS="${CXXFLAGS} -std=gnu++11"
    do_gcc_stash_builddir
}

