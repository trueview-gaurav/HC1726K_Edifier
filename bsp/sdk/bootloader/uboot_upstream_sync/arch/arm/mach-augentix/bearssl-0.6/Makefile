# SPDX-License-Identifier: MIT
#
# BearSSL 0.6, sources taken from buildroot. Only the objects the SPL resolves
# are carried.

subdir-ccflags-y := -I$(srctree)/arch/arm/mach-augentix/bearssl-0.6/inc \
		    -I$(srctree)/arch/arm/mach-augentix/bearssl-0.6/src

# The board config.mk forces -mfpu=neon-vfpv4 to match hard-float CPVS, which
# lets GCC vectorise the context memsets. The SPL runs with the FPU off, so a
# single emitted NEON instruction faults with no handler.
subdir-ccflags-y += -mgeneral-regs-only

obj-y += src/codec/
obj-y += src/hash/
obj-y += src/int/
obj-y += src/rsa/
