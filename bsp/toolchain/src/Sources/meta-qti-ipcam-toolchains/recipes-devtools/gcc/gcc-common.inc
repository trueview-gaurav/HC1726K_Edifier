SUMMARY = "GNU cc and gcc C compilers"
HOMEPAGE = "http://www.gnu.org/software/gcc/"
DESCRIPTION = "The GNU Compiler Collection includes front ends for C, C++, Objective-C, Fortran, Ada, Go, and D, as well as libraries for these languages (libstdc++,...). GCC was originally written as the compiler for the GNU operating system."
SECTION = "devel"
LICENSE = "GPL"

NATIVEDEPS = ""

CVE_PRODUCT = "gcc"

inherit autotools gettext texinfo

BPN = "gcc"
COMPILERDEP = "virtual/${MLPREFIX}${TARGET_PREFIX}gcc:do_gcc_stash_builddir"
COMPILERDEP_class-nativesdk = "virtual/${TARGET_PREFIX}gcc-crosssdk:do_gcc_stash_builddir"
# hardknott backport uses this; krogoth doesn't define it
COMPONENTS_DIR ?= "${TMPDIR}/components"


python extract_stashed_builddir () {
    import os

    src = d.expand("${COMPONENTS_DIR}/${BUILD_ARCH}/gcc-stashed-builddir-${TARGET_SYS}")
    dest = d.getVar("B", True)

    if not os.path.exists(src):
        bb.note("No stashed gcc builddir at %s; skip extract_stashed_builddir and continue normal configure." % src)
        return

    oe.path.copyhardlinktree(src, dest)
    fixme = os.path.join(src, "fixmepath")
    if os.path.exists(fixme):
        try:
            staging_processfixme([fixme], dest,
                                 d.getVar("RECIPE_SYSROOT", True),
                                 d.getVar("RECIPE_SYSROOT_NATIVE", True), d)
        except NameError:
            bb.note("staging_processfixme not available in this Yocto; skip fixmepath processing")
}

def get_gcc_float_setting(bb, d):
    if d.getVar('ARMPKGSFX_EABI', True) == "hf" and d.getVar('TRANSLATED_TARGET_ARCH', True) == "arm":
        return "--with-float=hard"
    if d.getVar('TARGET_FPU', True) in [ 'soft' ]:
        return "--with-float=soft"
    if d.getVar('TARGET_FPU', True) in [ 'ppc-efd' ]:
        return "--enable-e500_double"
    return ""

get_gcc_float_setting[vardepvalue] = "${@get_gcc_float_setting(bb, d)}"

def get_gcc_mips_plt_setting(bb, d):
    if d.getVar('TRANSLATED_TARGET_ARCH', True) in [ 'mips', 'mipsel' ] and bb.utils.contains('DISTRO_FEATURES', 'mplt', True, False, d):
        return "--with-mips-plt"
    return ""

def get_gcc_ppc_plt_settings(bb, d):
    if d.getVar('TRANSLATED_TARGET_ARCH', True) in [ 'powerpc', 'powerpc64' ] and not bb.utils.contains('DISTRO_FEATURES', 'bssplt', True, False, d):
        return "--enable-secureplt"
    return ""

def get_gcc_multiarch_setting(bb, d):
    target_arch = d.getVar('TRANSLATED_TARGET_ARCH', True)
    multiarch_options = {
        "i586":    "--enable-targets=all",
        "i686":    "--enable-targets=all",
        "powerpc": "--enable-targets=powerpc64",
        "powerpc64le": "--enable-targets=powerpcle",
        "mips":    "--enable-targets=all",
        "sparc":   "--enable-targets=all",
    }

    if bb.utils.contains('DISTRO_FEATURES', 'multiarch', True, False, d):
        if target_arch in multiarch_options :
            return multiarch_options[target_arch]
    return ""

# this is used by the multilib setup of gcc
def get_tune_parameters(tune, d):
    availtunes = d.getVar('AVAILTUNES', True)
    if tune not in availtunes.split():
        bb.error('The tune: %s is not one of the available tunes: %s' % (tune or None, availtunes))

    localdata = bb.data.createCopy(d)
    override = ':tune-' + tune
    localdata.setVar('OVERRIDES', localdata.getVar('OVERRIDES', False) + override)

    retdict = {}
    retdict['tune'] = tune
    retdict['ccargs'] = localdata.getVar('TUNE_CCARGS')
    retdict['features'] = localdata.getVar('TUNE_FEATURES')
    # BASELIB is used by the multilib code to change library paths
    retdict['baselib'] = localdata.getVar('BASE_LIB') or localdata.getVar('BASELIB')
    retdict['arch'] = localdata.getVar('TUNE_ARCH')
    retdict['abiextension'] = localdata.getVar('ABIEXTENSION')
    retdict['target_fpu'] = localdata.getVar('TARGET_FPU')
    retdict['pkgarch'] = localdata.getVar('TUNE_PKGARCH')
    retdict['package_extra_archs'] = localdata.getVar('PACKAGE_EXTRA_ARCHS')
    return retdict

get_tune_parameters[vardepsexclude] = "AVAILTUNES TUNE_CCARGS OVERRIDES TUNE_FEATURES BASE_LIB BASELIB TUNE_ARCH ABIEXTENSION TARGET_FPU TUNE_PKGARCH PACKAGE_EXTRA_ARCHS"

DEBIANNAME_${MLPREFIX}libgcc = "libgcc1"

MIRRORS =+ "\
${GNU_MIRROR}/gcc    ftp://gcc.gnu.org/pub/gcc/releases/ \n \
${GNU_MIRROR}/gcc	ftp://gd.tuwien.ac.at/gnu/gcc/ \n \
${GNU_MIRROR}/gcc	http://mirrors.rcn.net/pub/sourceware/gcc/releases/ \n \
${GNU_MIRROR}/gcc   http://gcc.get-software.com/releases/ \n \
${GNU_MIRROR}/gcc	http://gcc.get-software.com/releases/ \n \
"
#
# Set some default values
#
gcclibdir = "${libdir}/gcc"
BINV = "${PV}"
#S = "${WORKDIR}/gcc-${PV}"
S = "${TMPDIR}/work-shared/gcc-${PV}-${PR}/gcc-${PV}"

B = "${WORKDIR}/gcc-${PV}/build.${HOST_SYS}.${TARGET_SYS}"

target_includedir ?= "${includedir}"
target_libdir ?= "${libdir}"
target_base_libdir ?= "${base_libdir}"
target_prefix ?= "${prefix}"

# We need to ensure that for the shared work directory, the do_patch signatures match
# The real WORKDIR location isn't a dependency for the shared workdir.
src_patches[vardepsexclude] = "WORKDIR"
should_apply[vardepsexclude] += "PN"
