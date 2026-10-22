# Packaging / image features
PACKAGE_CLASSES ?= "package_rpm"
EXTRA_IMAGE_FEATURES ?= "debug-tweaks"

# libc policy
TCLIBC = "uclibc"

# prune distro features
DISTRO_FEATURES_remove = "x11 wayland gobject-introspection-data"

# skip unwanted toolchain extras
BBMASK += ".*/libgfortran_.*\.bb"
BBMASK += ".*/libgfortran\.inc"
BBMASK += ".*/binutils-cross-testsuite_.*\.bb$"
BBMASK += "meta-qti-ipcam-toolchains/recipes-devtools/binutils/binutils-cross-testsuite_.*\.bb"

# GCC 10.3 selection
GCCVERSION = "10.3%"
SDKGCCVERSION = "10.3%"

PREFERRED_VERSION_gcc = "10.3.%"
PREFERRED_VERSION_gcc-runtime = "10.3.%"
PREFERRED_VERSION_libgcc = "10.3.%"

PREFERRED_VERSION_gcc-cross-${TARGET_ARCH} = "10.3.%"
PREFERRED_VERSION_gcc-cross-initial-${TARGET_ARCH} = "10.3.%"
PREFERRED_VERSION_gcc-crosssdk-${SDK_ARCH} = "10.3.%"

# SDK bootstrap stays on 5.3 to avoid loops
PREFERRED_VERSION_gcc-crosssdk-initial-${SDK_ARCH} = "5.3.%"
PREFERRED_VERSION_nativesdk-libgcc-initial = "5.3.%"

# SDK/package pruning
SDKIMAGE_FEATURES_remove = "dbg-pkgs src-pkgs doc-pkgs"
SDKIMAGE_FEATURES_remove = " dbg-pkgs tools-debug"
EXTRA_IMAGE_FEATURES_remove = " dbg-pkgs tools-debug debug-tweaks"
TOOLCHAIN_TARGET_TASK_remove = "packagegroup-core-standalone-sdk-target-dbg"

# ensure uclibc staticdev shipped
TOOLCHAIN_TARGET_TASK_append = " uclibc-staticdev"
TOOLCHAIN_TARGET_TASK_append = " libiconv libiconv-dev"
TOOLCHAIN_HOST_TASK_append = " nativesdk-isl"

BINUVERSION = "2.36%"
