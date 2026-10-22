SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

include $(ROOTFS_PATH)/fs/ubifs/system_ubifs.mk
include $(ROOTFS_PATH)/fs/ubifs/rootfs_ubifs.mk

MAKEFLAGS += --no-print-directory

ASSETS_PATH = $(ROOTFS_PATH)/assets
MODULE_PATH = /lib/modules/$(SDK_KERNEL_VERSION)/
TEST_PATH = $(ROOTFS_PATH)/test
TOOL_PATH = $(ROOTFS_PATH)/tool
TEMP_PATH = $(ROOTFS_OUTPUT_PATH)/generated
SYSROOT_LIB_PATH = $(SYSROOT_DBG)/usr/lib
ASSETS_EXPANSION_PATH = $(ROOTFS_PATH)/add.list.d/$(CONFIG_MACH)/assets
INITRAMFS_PATH = $(ROOTFS_PATH)/initramfs.list.d
INITRAMFS_OUTPUT_PATH = $(ROOTFS_OUTPUT_PATH)/initramfs
BINPKG_SIGN_ROOTFS=$(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_DIR)

ifneq ($(BUILDROOT_HOST_LIB), $(filter $(LD_LIBRARY_PATH), $(BUILDROOT_HOST_LIB)))
LD_LIBRARY_PATH += $(BUILDROOT_HOST_LIB)
export LD_LIBRARY_PATH
endif

MKSQUASHFS = $(BUILDROOT_HOST_BIN)/mksquashfs
UNSQUASHFS = $(BUILDROOT_HOST_BIN)/unsquashfs
VERITYSETUP = $(BUILDROOT_HOST_SBIN)/veritysetup
ifeq ($(CONFIG_KERNEL_ARM64), y)
OBJCOPY_KO = $(CROSS_COMPILE_5)objcopy
OBJCOPY_ELF = $(CROSS_COMPILE)objcopy
STRIP_KO = $(CROSS_COMPILE_5)strip
STRIP_ELF = $(CROSS_COMPILE)strip
else
OBJCOPY_KO = $(CROSS_COMPILE)objcopy
OBJCOPY_ELF = $(CROSS_COMPILE)objcopy
STRIP_KO = $(CROSS_COMPILE)strip
STRIP_ELF = $(CROSS_COMPILE)strip
endif
BATS = $(TOOL_PATH)/bats/bin/bats
COPY_ASSETS = $(TOOL_PATH)/copy_assets.sh
SSTRIP = $(TOOL_PATH)/sstrip
DEPMOD = depmod
SHRINK = $(TOOL_PATH)/shrink.sh
CHECK_DEPS = $(TOOL_PATH)/check_deps.sh
# Fail the build on unresolved DT_NEEDED when set to y; otherwise warn only.
ROOTFS_CHECK_DEPS_STRICT ?= n
VERITY_PARSING_TOOL = $(TOOL_PATH)/verity_format_parsing.sh
EXTERN_COLLECT_DATA = $(TOOL_PATH)/extern_collect_data_tool.sh
CONFIG_CHIP=$(shell cat ${SDKSRC_DIR}/firmware/build/.config | grep "CONFIG_CHIP" | awk 'BEGIN {FS="="} {print $$2}')
IS_UCLIBC=$(shell cat ${SDKSRC_DIR}/firmware/build/.config | grep "CONFIG_UCLIBC" | awk 'BEGIN {FS="="} {print $$2}')
SDK_VER=$(shell cat ${ROOTFS_OUTPUT_PATH}/target/etc/sdk-version |grep "SDK version" | awk 'BEGIN{FS=": "} {print $$2}')
EXTERN_COLLECT_DATA_PACKAGE_NAME="extern_collect_data_${CONFIG_CHIP}-${CROSS_COMPILE}${SDK_VER}.tgz"
ifeq ($(IS_UCLIBC), y)
# CROSS_COMPILE2 is uclibc toolchain name
EXTERN_COLLECT_DATA_PACKAGE_NAME="extern_collect_data_${CONFIG_CHIP}-${CROSS_COMPILE_2}${SDK_VER}.tgz"
endif
EXTERN_COLLECT_DATA_PACKAGE = $(ROOTFS_OUTPUT_PATH)/${EXTERN_COLLECT_DATA_PACKAGE_NAME}
EXTERN_COLLECT_DATA_PACKAGE_OUTPUT = $(addprefix $(SDKSRC_DIR)/firmware/build/, ${EXTERN_COLLECT_DATA_PACKAGE_NAME})

GLOBAL_ADD_LIST = $(ROOTFS_PATH)/add.list
PROD_ADD_LIST = $(wildcard $(ROOTFS_PATH)/add.list.d/$(CONFIG_MACH)/*.list)
PROD_ADD_EXPANSION_LIST = $(wildcard $(ROOTFS_PATH)/add.list.d/$(CONFIG_MACH)/assets/add.list)
PROD_INITRAMFS_ADD_LIST = $(wildcard $(INITRAMFS_PATH)/$(CONFIG_MACH)/*.list)

GLOBAL_RM_LIST = $(ROOTFS_PATH)/rm.list
PROD_RM_LIST = $(wildcard $(ROOTFS_PATH)/rm.list.d/$(CONFIG_MACH)/*.list)

#New SSV6x5x (L.SMAC.19Q3.2038.01)
SSV6X5X_KO := $(KERNEL_PATH)/drivers/net/wireless/ssv6x5x/
SSV6X5X_CFG := $(SYSROOT_DBG)/lib/modules/$(SDK_KERNEL_VERSION)/kernel/drivers/net/wireless/ssv6x5x/

#New SSV6158
SSV6158_KO := $(KERNEL_PATH)/drivers/net/wireless/ssv6158/
SSV6158_CFG := $(SYSROOT_DBG)/lib/modules/$(SDK_KERNEL_VERSION)/kernel/drivers/net/wireless/ssv6158/

#New ZT9101
ZT9101_KO := $(KERNEL_PATH)/drivers/net/wireless/zt9101
ZT9101_CFG := $(SYSROOT_DBG)/lib/modules/$(SDK_KERNEL_VERSION)/kernel/drivers/net/wireless/zt9101

#New AIC8800
AIC8800_DC_KO := $(KERNEL_PATH)/drivers/net/wireless/aic8800_dc
AIC8800_D80_KO := $(KERNEL_PATH)/drivers/net/wireless/aic8800_d80
AIC8800_CFG := $(SYSROOT_DBG)/lib/modules/$(SDK_KERNEL_VERSION)/kernel/drivers/net/wireless

#New rtl8723du
RTL8723_KO := $(KERNEL_PATH)/drivers/net/wireless/realtek/rtl8723du
RTL8723_CFG := $(SYSROOT_DBG)/lib/firmware/rtl_bt/

.PHONY: default
default: all

.PHONY: all
all:
	$(Q)$(MAKE) rootfs-dbg
	$(Q)$(MAKE) rootfs-rel
	$(Q)$(MAKE) post-build

.PHONY: post-build
post-build:
	@echo "Make finished at `date`"

########################################################################
# rootfs debugging/release build rules
########################################################################

.PHONY: test
test:
	$(Q)$(BATS) $(TEST_PATH)/

.PHONY: prepare
prepare:
	$(Q)$(MAKE) clean-sysroot
	$(Q)$(MAKE) init-sysroot
	$(Q)$(MAKE) copy-assets-global
	$(Q)$(MAKE) shrink-global

.PHONY: init-sysroot
init-sysroot:
	@echo - Copying rootfs from Buildroot...
	$(Q)mkdir -p $(SYSROOT)
	$(Q)mkdir -p $(SYSTEMFS)/factory_default $(USRDATAFS)/active_setting
	$(Q)cp -a $(BUILDROOT_OUTPUT_PATH)/target/* $(SYSROOT)
	$(Q)mkdir -p $(SYSROOT)/$(MODULE_PATH)
	$(Q)cp -Ppv --remove-destination $(ASSETS_PATH)/$(MODULE_PATH)/mpp $(SYSROOT)/$(MODULE_PATH)/

.PHONY: copy-assets-global
copy-assets-global:
	@echo - Copying assets to rootfs...
	$(Q)$(COPY_ASSETS) $(ASSETS_PATH) $(SYSROOT) $(GLOBAL_ADD_LIST)

.PHONY: copy-assets-product
copy-assets-product:
ifneq ("$(PROD_ADD_LIST)","")
	@echo - Copying assets to rootfs for \'$(CONFIG_MACH)\'...
	$(Q)$(COPY_ASSETS) $(ASSETS_PATH) $(SYSROOT) $(PROD_ADD_LIST)
else
	@echo No rule to copy assets to rootfs for \'$(CONFIG_MACH)\'. Skip.
endif

.PHONY: copy-assets-product-expansion
copy-assets-product-expansion:
ifneq ("$(PROD_ADD_EXPANSION_LIST)","")
	@echo - Copying assets expansion to rootfs for \'$(CONFIG_MACH)\'...
	$(Q)$(COPY_ASSETS) $(ASSETS_EXPANSION_PATH) $(SYSROOT) $(PROD_ADD_EXPANSION_LIST)
else
	@echo No rule to copy assets expansion to rootfs for \'$(CONFIG_MACH)\'. Skip.
endif

ifeq ($(CONFIG_INITRAMFS), y)
.PHONY: copy-initramfs-product
copy-initramfs-product:
ifneq ("$(PROD_INITRAMFS_ADD_LIST)","")
	@echo - Copying rootfs to initramfs for \'$(CONFIG_MACH)\'...
ifeq ($(CONFIG_SECURE_BOOT), y)
# secure boot related file will be removed from SYSROOT after first build, so copy from buildroot instead
	$(Q)$(COPY_ASSETS) $(BUILDROOT_OUTPUT_PATH)/target  $(INITRAMFS_OUTPUT_PATH) $(PROD_INITRAMFS_ADD_LIST)
endif
	$(Q)$(COPY_ASSETS) $(SYSROOT) $(INITRAMFS_OUTPUT_PATH) $(PROD_INITRAMFS_ADD_LIST)
ifneq (,$(filter y,$(CONFIG_FASTBOOT) $(CONFIG_INITRAMFS_MPI_STREAM)))
#ifeq ($(CONFIG_FASTBOOT),y)
# Due to limitation of copy_assets, cp mpp directory manually instead of using add.list
# Add CONFIG_INITRAMFS_MPI_STREAM temporarily for Project DFN202-113002
	$(Q)mkdir -p $(INITRAMFS_OUTPUT_PATH)$(MODULE_PATH)
	$(Q)rm -rf $(INITRAMFS_OUTPUT_PATH)$(MODULE_PATH)mpp
	$(Q)ln -nsf ../../../system/lib $(INITRAMFS_OUTPUT_PATH)$(MODULE_PATH)mpp
	$(Q)$(DEPMOD) -b $(INITRAMFS_OUTPUT_PATH) $(SDK_KERNEL_VERSION)
endif
	$(Q)cp $(INITRAMFS_PATH)/$(CONFIG_MACH)/init $(INITRAMFS_OUTPUT_PATH)
else
	@echo No rule to copy rootfs to initramfs for \'$(CONFIG_MACH)\'. Skip.
endif
endif # CONFIG_INITRAMFS

.PHONY: shrink-global
shrink-global:
	@echo - Shrinking rootfs template...
	$(Q)$(SHRINK) $(SYSROOT) $(GLOBAL_RM_LIST)

.PHONY: shrink-product
shrink-product:
ifneq ("$(PROD_RM_LIST)","")
	@echo - Shrinking rootfs for \'$(CONFIG_MACH)\'...
	$(Q)$(SHRINK) $(SYSROOT) $(PROD_RM_LIST)
else
	@echo No rule to shrink rootfs for \'$(CONFIG_MACH)\'. Skip.
endif

# Verify every ELF's DT_NEEDED resolves within the final (post-shrink) rootfs.
# Turns the device-side opaque "internal error" (uClibc has no LD_DEBUG) into a
# named "MISSING: <consumer> needs <soname>" at build time.
.PHONY: check-deps
check-deps:
	@echo - Checking shared-library dependencies in rootfs...
	$(Q)$(CHECK_DEPS) $(SYSROOT) $(CROSS_COMPILE)readelf $(ROOTFS_CHECK_DEPS_STRICT)

.PHONY: collect-data collect-data-cleaning collect-data-install collect-data-uninstall
collect-data:
	@echo "Run ${EXTERN_COLLECT_DATA}"
	$(Q) ${EXTERN_COLLECT_DATA} ${SDKSRC_DIR}

collect-data-clean: collect-data-uninstall
	@echo "Remove ${EXTERN_COLLECT_DATA_PACKAGE}"
	$(Q) rm -rf ${EXTERN_COLLECT_DATA_PACKAGE}


collect-data-install:
	$(Q) cp -rf ${EXTERN_COLLECT_DATA_PACKAGE} ${EXTERN_COLLECT_DATA_PACKAGE_OUTPUT}

collect-data-uninstall:
	$(Q) rm -rf ${EXTERN_COLLECT_DATA_PACKAGE_OUTPUT}


# Generate basic fakeroot rules, excluding rootfs build method
.PHONY: init-fakeroot
init-fakeroot:
	$(Q)rm -rf $(TEMP_PATH)
	$(Q)mkdir -p $(TEMP_PATH)
	$(Q)touch $(TEMP_PATH)/_fakeroot.fs && \
		chmod a+x $(TEMP_PATH)/_fakeroot.fs
	$(Q)echo "set -e" >> $(TEMP_PATH)/_fakeroot.fs
	$(Q)echo "chown -h -R 0:0 $(SYSROOT)" >> $(TEMP_PATH)/_fakeroot.fs
	$(Q)printf '' >> $(TEMP_PATH)/_users_table.txt
	$(Q)$(BUILD_UTILS_PATH)/mkusers \
		$(TEMP_PATH)/_users_table.txt $(SYSROOT) >> \
		$(TEMP_PATH)/_fakeroot.fs
	$(Q)cat $(ROOTFS_PATH)/device_table.txt > \
		$(TEMP_PATH)/_device_table.txt
	$(Q)printf '/bin/busybox				f	4755	0	0	-	-	-	-	-\n/dev/console				c	622	0	0	5	1	-	-	-\n' >> $(TEMP_PATH)/_device_table.txt
	$(Q)echo "$(BUILD_UTILS_PATH)/makedevs -d $(TEMP_PATH)/_device_table.txt $(SYSROOT)" >> $(TEMP_PATH)/_fakeroot.fs
	$(Q)echo "cd $(SYSROOT) && find . | cpio --quiet -o -H newc > $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_FILE)" >> $(TEMP_PATH)/_fakeroot.fs

.PHONY: init-fakeroot-pack
init-fakeroot-pack: $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp
	$(Q)touch $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs && \
		chmod a+x $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs
	$(Q)echo "set -e" >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs
	$(Q)echo "chown -h -R 0:0 $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir" >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs
	$(Q)printf '' >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/users_table.txt
	$(Q)$(BUILD_UTILS_PATH)/mkusers \
		$(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/users_table.txt $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir >> \
		$(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs
	$(Q)cat $(ROOTFS_PATH)/device_table.txt > \
		$(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/device_table.txt
	$(Q)printf '/bin/busybox				f	4755	0	0	-	-	-	-	-\n/dev/console				c	622	0	0	5	1	-	-	-\n' >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/device_table.txt
	$(Q)echo "$(BUILD_UTILS_PATH)/makedevs -d $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/device_table.txt $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir" >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs

ifeq ($(CONFIG_INITRAMFS), y)
.PHONY: init-fakeroot-initramfs
init-fakeroot-initramfs:
	$(Q)rm -rf $(TEMP_PATH)
	$(Q)mkdir -p $(TEMP_PATH)
	$(Q)touch $(TEMP_PATH)/_fakeroot.fs && \
		chmod a+x $(TEMP_PATH)/_fakeroot.fs
	$(Q)echo "set -e" >> $(TEMP_PATH)/_fakeroot.fs
	$(Q)echo "chown -h -R 0:0 $(INITRAMFS_OUTPUT_PATH)" >> $(TEMP_PATH)/_fakeroot.fs
	$(Q)touch $(TEMP_PATH)/_device_table.txt
	$(Q)printf '/bin/busybox				f	4755	0	0	-	-	-	-	-\n/dev/console				c	622	0	0	5	1	-	-	-\n/init				f	4755	0	0	-	-	-	-	-\n' >> $(TEMP_PATH)/_device_table.txt
	$(Q)echo "$(BUILD_UTILS_PATH)/makedevs -d $(TEMP_PATH)/_device_table.txt $(INITRAMFS_OUTPUT_PATH)" >> $(TEMP_PATH)/_fakeroot.fs
	$(Q)echo "cd $(INITRAMFS_OUTPUT_PATH) && find . | cpio --quiet -o -H newc > $(KERNEL_PATH)/usr/$(ROOTFS_CPIO_FILE)" >> $(TEMP_PATH)/_fakeroot.fs
endif

.PHONY: fakeroot-dbg fakeroot-rel
ifeq ($(CONFIG_ROOTFS_INITRAMFS), y)
fakeroot-dbg: fakeroot-ramdisk-dbg
fakeroot-rel: fakeroot-ramdisk-rel
else ifeq ($(CONFIG_ROOTFS_SQUASHFS), y)
fakeroot-dbg: fakeroot-squashfs-dbg
fakeroot-rel: fakeroot-squashfs-rel
else
fakeroot-dbg: fakeroot-ubifs-dbg
fakeroot-rel: fakeroot-ubifs-rel
endif

ROOTFS_LOADADDR := 0x01100000
.PHONY: fakeroot-ramdisk-dbg
fakeroot-ramdisk-dbg: init-fakeroot
	$(Q)cp -f $(TEMP_PATH)/_fakeroot.fs $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)echo "cd $(ROOTFS_IMAGE_PATH)" >> $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)echo "gzip -9 -c $(ROOTFS_CPIO_FILE) > $(ROOTFS_CPIO_FILE).gz" >> $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)echo "mkimage -A arm -T ramdisk -C gzip -a $(ROOTFS_LOADADDR) -d $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_FILE).gz \
			$(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_DBG)" >> $(TEMP_PATH)/_fakeroot_dbg.fs

fakeroot-ramdisk-rel: init-fakeroot
	$(Q)cp -f $(TEMP_PATH)/_fakeroot.fs $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)echo "cd $(ROOTFS_IMAGE_PATH)" >> $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)echo "gzip -9 -c $(ROOTFS_CPIO_FILE) > $(ROOTFS_CPIO_FILE).gz" >> $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)echo "mkimage -A arm -T ramdisk -C gzip -a $(ROOTFS_LOADADDR) -d $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_FILE).gz \
			$(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_REL)" >> $(TEMP_PATH)/_fakeroot_rel.fs

.PHONY: fakeroot-squashfs-dbg
fakeroot-squashfs-dbg: init-fakeroot $(ROOTFS_IMAGE_PATH)/dbg
	$(Q)cp -f $(TEMP_PATH)/_fakeroot.fs $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)echo "cd $(ROOTFS_IMAGE_PATH)" >> $(TEMP_PATH)/_fakeroot_dbg.fs
ifeq ($(CONFIG_ROOTFS_SQUASHFS_OVER_UBI), y)
ifeq ($(CONFIG_ROOTFS_SQUASHFS_XZ), y)
	$(Q)echo "$(MKSQUASHFS) $(SYSROOT_DBG) $(ROOTFS_IMAGE_PATH)/dbg/rootfs.ubifs -no-xattrs -comp xz -noX" >> $(TEMP_PATH)/_fakeroot_dbg.fs
else
	$(Q)echo "$(MKSQUASHFS) $(SYSROOT_DBG) $(ROOTFS_IMAGE_PATH)/dbg/rootfs.ubifs -no-xattrs" >> $(TEMP_PATH)/_fakeroot_dbg.fs
endif # CONFIG_ROOTFS_SQUASHFS_XZ
ifneq ($(CONFIG_SECURE_BOOT), y)
	$(Q)echo "cd $(ROOTFS_IMAGE_PATH)/dbg" >> $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)echo "ubinize -o $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_DBG) $(ROOTFS_UBI_UBINIZE_OPTS) $(ROOTFS_PATH)/fs/ubifs/rootfs_ubinize.cfg" >> $(TEMP_PATH)/_fakeroot_dbg.fs
endif
	$(Q)rm -f $(ROOTFS_IMAGE_PATH)/dbg/rootfs.ubifs
else # !CONFIG_ROOTFS_SQUASHFS_OVER_UBI
ifeq ($(CONFIG_ROOTFS_SQUASHFS_XZ), y)
	$(Q)echo "$(MKSQUASHFS) $(SYSROOT_DBG) $(ROOTFS_IMAGE_PATH)/dbg/rootfs.squashfs -no-xattrs -comp xz -noX" >> $(TEMP_PATH)/_fakeroot_dbg.fs
else
	$(Q)echo "$(MKSQUASHFS) $(SYSROOT_DBG) $(ROOTFS_IMAGE_PATH)/dbg/rootfs.squashfs -no-xattrs" >> $(TEMP_PATH)/_fakeroot_dbg.fs
endif # CONFIG_ROOTFS_SQUASHFS_XZ
ifneq ($(CONFIG_SECURE_BOOT), y)
	$(Q)echo "mv $(ROOTFS_IMAGE_PATH)/dbg/rootfs.squashfs $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_DBG)" >> $(TEMP_PATH)/_fakeroot_dbg.fs
endif
	$(Q)rm -f $(ROOTFS_IMAGE_PATH)/dbg/rootfs.squashfs
endif # CONFIG_ROOTFS_SQUASHFS_OVER_UBI

.PHONY: fakeroot-squashfs-rel
fakeroot-squashfs-rel: init-fakeroot $(ROOTFS_IMAGE_PATH)/rel
	$(Q)cp -f $(TEMP_PATH)/_fakeroot.fs $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)sed -i 's|$(SYSROOT)|$(SYSROOT_REL)|g' $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)echo "cd $(ROOTFS_IMAGE_PATH)" >> $(TEMP_PATH)/_fakeroot_rel.fs
ifeq ($(CONFIG_ROOTFS_SQUASHFS_OVER_UBI), y)
ifeq ($(CONFIG_ROOTFS_SQUASHFS_XZ), y)
	$(Q)echo "$(MKSQUASHFS) $(SYSROOT_REL) $(ROOTFS_IMAGE_PATH)/rel/rootfs.ubifs -no-xattrs -comp xz -noX" >> $(TEMP_PATH)/_fakeroot_rel.fs
else
	$(Q)echo "$(MKSQUASHFS) $(SYSROOT_REL) $(ROOTFS_IMAGE_PATH)/rel/rootfs.ubifs -no-xattrs" >> $(TEMP_PATH)/_fakeroot_rel.fs
endif # CONFIG_ROOTFS_SQUASHFS_XZ
ifneq ($(CONFIG_SECURE_BOOT), y)
	$(Q)echo "cd $(ROOTFS_IMAGE_PATH)/rel" >> $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)echo "ubinize -o $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_REL) $(ROOTFS_UBI_UBINIZE_OPTS) $(ROOTFS_PATH)/fs/ubifs/rootfs_ubinize.cfg" >> $(TEMP_PATH)/_fakeroot_rel.fs
endif
	$(Q)rm -f $(ROOTFS_IMAGE_PATH)/rel/rootfs.ubifs
else # !CONFIG_ROOTFS_SQUASHFS_OVER_UBI
ifeq ($(CONFIG_ROOTFS_SQUASHFS_XZ), y)
	$(Q)echo "$(MKSQUASHFS) $(SYSROOT_REL) $(ROOTFS_IMAGE_PATH)/rel/rootfs.squashfs -no-xattrs -comp xz -noX" >> $(TEMP_PATH)/_fakeroot_rel.fs
else
	$(Q)echo "$(MKSQUASHFS) $(SYSROOT_REL) $(ROOTFS_IMAGE_PATH)/rel/rootfs.squashfs -no-xattrs" >> $(TEMP_PATH)/_fakeroot_rel.fs
endif # CONFIG_ROOTFS_SQUASHFS_XZ
ifneq ($(CONFIG_SECURE_BOOT), y)
	$(Q)echo "mv $(ROOTFS_IMAGE_PATH)/rel/rootfs.squashfs $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_REL)" >> $(TEMP_PATH)/_fakeroot_rel.fs
endif
	$(Q)rm -f $(ROOTFS_IMAGE_PATH)/rel/rootfs.squashfs
endif # CONFIG_ROOTFS_SQUASHFS_OVER_UBI

.PHONY: fakeroot-ubifs-dbg
fakeroot-ubifs-dbg: init-fakeroot
	$(Q)cp -f $(TEMP_PATH)/_fakeroot.fs $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)echo "mkfs.ubifs -d $(SYSROOT_DBG) $(ROOTFS_UBIFS_OPTS) -o $(ROOTFS_IMAGE_PATH)/rootfs.ubifs" >> $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)echo "cd $(ROOTFS_IMAGE_PATH)" >> $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)echo "ubinize -o $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_DBG) $(ROOTFS_UBI_UBINIZE_OPTS) $(ROOTFS_PATH)/fs/ubifs/rootfs_ubinize.cfg" >> $(TEMP_PATH)/_fakeroot_dbg.fs
	$(Q)rm -f $(ROOTFS_IMAGE_PATH)/rootfs.ubifs

.PHONY: fakeroot-ubifs-rel
fakeroot-ubifs-rel: init-fakeroot
	$(Q)cp -f $(TEMP_PATH)/_fakeroot.fs $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)sed -i 's|$(SYSROOT)|$(SYSROOT_REL)|g' $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)echo "mkfs.ubifs -d $(SYSROOT_REL) $(ROOTFS_UBIFS_OPTS) -o $(ROOTFS_IMAGE_PATH)/rootfs.ubifs" >> $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)echo "cd $(ROOTFS_IMAGE_PATH)" >> $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)echo "ubinize -o $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_REL) $(ROOTFS_UBI_UBINIZE_OPTS) $(ROOTFS_PATH)/fs/ubifs/rootfs_ubinize.cfg" >> $(TEMP_PATH)/_fakeroot_rel.fs
	$(Q)rm -f $(ROOTFS_IMAGE_PATH)/rootfs.ubifs

ifeq ($(CONFIG_INITRAMFS), y)
.PHONY: fakeroot-kernel-initramfs
fakeroot-kernel-initramfs: init-fakeroot-initramfs \
$(INITRAMFS_OUTPUT_PATH)/dev \
$(INITRAMFS_OUTPUT_PATH)/proc \
$(INITRAMFS_OUTPUT_PATH)/root \
$(INITRAMFS_OUTPUT_PATH)/tmp \
$(INITRAMFS_OUTPUT_PATH)/sys
	$(Q)$(MAKE) copy-initramfs-product
	$(Q)$(TOOL_PATH)/strip_file_ko.sh $(INITRAMFS_OUTPUT_PATH) $(OBJCOPY_KO) \
		$(STRIP_KO) $(SSTRIP) ko_list_rootfs.txt
	$(Q)$(TOOL_PATH)/strip_file_elf.sh $(INITRAMFS_OUTPUT_PATH) $(OBJCOPY_ELF) \
		$(STRIP_ELF) $(SSTRIP) elf_list_rootfs.txt
endif

# Generate release-version root filesystem source
.PHONY: init-rootfs-rel
init-rootfs-rel:
	$(Q)rm -rf $(SYSROOT_REL)
	$(Q)cp -rf $(SYSROOT_DBG) $(SYSROOT_REL)
	$(Q)$(TOOL_PATH)/strip_file_ko.sh $(SYSROOT_REL) $(OBJCOPY_KO) \
		$(STRIP_KO) $(SSTRIP) ko_list_rootfs.txt
	$(Q)$(TOOL_PATH)/strip_file_elf.sh $(SYSROOT_REL) $(OBJCOPY_ELF) \
		$(STRIP_ELF) $(SSTRIP) elf_list_rootfs.txt

ifeq ($(CONFIG_INITRAMFS), y)
.PHONY: kernel-initramfs
kernel-initramfs: $(ROOTFS_OUTPUT_PATH) $(ROOTFS_IMAGE_PATH) $(TEMP_PATH)
	@echo - Building kernel initramfs...
	$(Q)$(MAKE) fakeroot-kernel-initramfs
	$(Q)fakeroot -- $(TEMP_PATH)/_fakeroot.fs $(VOUT)
endif

# Generate debugging-version root filesystem image
.PHONY: rootfs-dbg
rootfs-dbg: $(SYSROOT_DBG) \
$(SYSROOT_DBG)/mnt/nfs/ethnfs \
$(SYSROOT_DBG)/mnt/sdcard \
$(SYSROOT_DBG)/mnt/usb \
$(SYSROOT_DBG)/usrdata \
$(SYSROOT_DBG)/calib \
$(SYSROOT_DBG)/usrdata \
$(SYSROOT_DBG)/system \
$(ROOTFS_OUTPUT_PATH) \
$(ROOTFS_IMAGE_PATH) \
$(TEMP_PATH)
	$(Q)$(MAKE) fakeroot-dbg
	$(Q)$(MAKE) scripts-install
	$(Q)rm -f $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_DBG)
	$(Q)rm -rf $(SYSROOT_DBG)/system/*
	$(Q)cp -rf $(SYSTEMFS)/* $(SYSROOT_DBG)/system/
	$(Q)$(MAKE) copy-assets-product
	$(Q)$(MAKE) copy-assets-product-expansion
	$(Q)$(DEPMOD) -b $(SYSROOT_DBG) $(SDK_KERNEL_VERSION)
	$(Q)$(MAKE) shrink-product
	$(Q)$(MAKE) check-deps
	$(Q)fakeroot -- $(TEMP_PATH)/_fakeroot_dbg.fs $(VOUT)

# Generate release-version root filesystem image
.PHONY: rootfs-rel
rootfs-rel: $(SYSROOT_REL) \
$(ROOTFS_OUTPUT_PATH) \
$(ROOTFS_IMAGE_PATH) \
$(TEMP_PATH)
	$(Q)$(MAKE) init-rootfs-rel
	$(Q)$(MAKE) fakeroot-rel
	$(Q)rm -f $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_REL)
	$(Q)fakeroot -- $(TEMP_PATH)/_fakeroot_rel.fs $(VOUT)

ifeq ($(CONFIG_SECURE_BOOT), y)
.PHONY: squashfs-unpack
squashfs-unpack:
	echo "Unpacking $(USRDATAFS_IMAGE_BIN) with unsquashfs..."
ifeq ($(CONFIG_ROOTFS_SQUASHFS_OVER_UBI), y)
	$(Q)$(UNSQUASHFS) -d $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.ubifs || true
	$(Q)rm -f $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.ubifs
else # !CONFIG_ROOTFS_SQUASHFS_OVER_UBI
	$(Q)$(UNSQUASHFS) -d $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.squashfs || true
	$(Q)rm -f $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.squashfs
endif # CONFIG_ROOTFS_SQUASHFS_OVER_UBI

.PHONY: squashfs-pack
squashfs-pack: init-fakeroot-pack
ifeq ($(CONFIG_ROOTFS_SQUASHFS_OVER_UBI), y)
ifeq ($(CONFIG_ROOTFS_SQUASHFS_XZ), y)
	$(Q)echo "$(MKSQUASHFS) $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.ubifs -no-xattrs -comp xz -noX" >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs
else
	$(Q)echo "$(MKSQUASHFS) $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.ubifs -no-xattrs" >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs
endif # CONFIG_ROOTFS_SQUASHFS_XZ
else # !CONFIG_ROOTFS_SQUASHFS_OVER_UBI
ifeq ($(CONFIG_ROOTFS_SQUASHFS_XZ), y)
	$(Q)echo "$(MKSQUASHFS) $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.squashfs -no-xattrs -comp xz -noX" >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs
else
	$(Q)echo "$(MKSQUASHFS) $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/rootfs_dir $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.squashfs -no-xattrs" >> $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs
endif # CONFIG_ROOTFS_SQUASHFS_XZ
endif # CONFIG_ROOTFS_SQUASHFS_OVER_UBI
	$(Q)fakeroot -- $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp/fakeroot.fs $(VOUT)
	$(Q)rm -rf $(BINPKG_SIGN_ROOTFS)/$(VER)/tmp $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs_dir

.PHONY: squashfs-sign
squashfs-sign:
ifeq ($(CONFIG_ROOTFS_SQUASHFS_OVER_UBI), y)
	$(Q)$(VERITYSETUP) format --salt=$(ROOTFS_SALT) $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.ubifs $(BINPKG_SIGN_ROOTFS)/$(VER)/hash_$(VER).img > $(BINPKG_SIGN_ROOTFS)/$(VER)/verity_format_$(VER)
	$(Q)$(VERITY_PARSING_TOOL) $(BINPKG_SIGN_ROOTFS)/$(VER)/verity_format_$(VER) $(BINPKG_SIGN_DIR)/verity_script_$(VER) $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.ubifs
	$(Q)cat $(BINPKG_SIGN_ROOTFS)/$(VER)/hash_$(VER).img >> $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.ubifs
	$(Q)cd $(BINPKG_SIGN_ROOTFS)/$(VER); \
		ubinize -o $(BINPKG_SIGN_ROOTFS)/$(VER)/$(ROOTFS_CPIO_UBOOT_FILE) $(ROOTFS_UBI_UBINIZE_OPTS) $(ROOTFS_PATH)/fs/ubifs/rootfs_ubinize.cfg
else # !CONFIG_ROOTFS_SQUASHFS_OVER_UBI
	$(Q)$(VERITYSETUP) format --salt=$(ROOTFS_SALT) $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.squashfs $(BINPKG_SIGN_ROOTFS)/$(VER)/hash_$(VER).img > $(BINPKG_SIGN_ROOTFS)/$(VER)/verity_format_$(VER)
	$(Q)$(VERITY_PARSING_TOOL) $(BINPKG_SIGN_ROOTFS)/$(VER)/verity_format_$(VER) $(BINPKG_SIGN_DIR)/verity_script_$(VER) $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.squashfs
	$(Q)cat $(BINPKG_SIGN_ROOTFS)/$(VER)/hash_$(VER).img >> $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.squashfs
	$(Q)mv $(BINPKG_SIGN_ROOTFS)/$(VER)/rootfs.squashfs $(BINPKG_SIGN_ROOTFS)/$(VER)/$(ROOTFS_CPIO_UBOOT_FILE)
endif

.PHONY: secure-unpack
secure-unpack:
	$(Q)$(MAKE) squashfs-unpack VER=dbg
	$(Q)$(MAKE) squashfs-unpack VER=rel

.PHONY: secure-pack
secure-pack:
	$(Q)$(MAKE) squashfs-pack VER=dbg
	$(Q)$(MAKE) squashfs-pack VER=rel

.PHONY: secure-sign
secure-sign:
	$(Q)$(MAKE) squashfs-sign VER=dbg
	$(Q)$(MAKE) squashfs-sign VER=rel
	$(Q)mv $(BINPKG_SIGN_ROOTFS)/dbg/$(ROOTFS_CPIO_UBOOT_FILE) $(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_FILE_DBG).bin
	$(Q)mv $(BINPKG_SIGN_ROOTFS)/rel/$(ROOTFS_CPIO_UBOOT_FILE) $(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin
	$(Q)rm -rf $(BINPKG_SIGN_ROOTFS)
endif # CONFIG_SECURE_BOOT

########################################################################
# Target init and demo script
########################################################################

.PHONY: scripts-install
scripts-install:
	@echo - Installing init scripts to filesystem
	$(Q)$(MAKE) -C $(SCRIPTS_PATH) install
	@if [ -f $(SSV6X5X_KO)/ssv6x5x.ko ]; then \
		mkdir -p $(SSV6X5X_CFG) ; \
		cp -f $(SSV6X5X_KO)/ssv6x5x-wifi.cfg $(SSV6X5X_CFG)/ssv6x5x-wifi-usb.cfg ; \
		cp -f $(SSV6X5X_KO)/ssv6x5x-wifi.cfg $(SSV6X5X_CFG)/ssv6x5x-wifi-sdio.cfg ; \
		sed -e 's/xtal_clock = 40/xtal_clock = 24/g' -i $(SSV6X5X_CFG)/ssv6x5x-wifi-sdio.cfg ; \
	fi
	@if [ -f $(SSV6158_KO)/ssv6x5x.ko ]; then \
		mkdir -p $(SSV6158_CFG) ; \
		cp -f $(SSV6158_KO)/ssv6x5x-wifi.cfg $(SSV6158_CFG)/ssv6x5x-wifi-usb.cfg ; \
		cp -f $(SSV6158_KO)/ssv6x5x-wifi.cfg $(SSV6158_CFG)/ssv6x5x-wifi-sdio.cfg ; \
		sed -e 's/xtal_clock = 40/xtal_clock = 24/g' -i $(SSV6158_CFG)/ssv6x5x-wifi-sdio.cfg ; \
	fi
	@if [ -f $(ZT9101_KO)/ZT9101xV20.ko ]; then \
		mkdir -p $(ZT9101_CFG) ; \
		cp -f $(ZT9101_KO)/wifi.cfg $(ZT9101_CFG)/wifi.cfg ; \
		cp -f $(ZT9101_KO)/fw/ZT9101_fw_r2636.bin $(ZT9101_CFG)/ZT9101_fw_r2636.bin ; \
	fi
	@if [ -f $(AIC8800_DC_KO)/aic_load_fw_dc/aic_load_fw_dc.ko ]; then \
		echo "hello aic8800 dc" ; \
		mkdir -p $(AIC8800_CFG) ; \
		cp -rf $(AIC8800_DC_KO)/aic8800DC/* $(AIC8800_CFG)/ ; \
	fi
	@if [ -f $(AIC8800_D80_KO)/aic_load_fw_d80/aic_load_fw_d80.ko ]; then \
		echo "hello aic8800 d80" ; \
		mkdir -p $(AIC8800_CFG) ; \
		cp -rf $(AIC8800_D80_KO)/aic8800D80/* $(AIC8800_CFG)/ ; \
	fi
	@if [ -f $(RTL8723_KO)/rtl8723du.ko ]; then \
		echo "hello rtl8723" ; \
		mkdir -p $(RTL8723_CFG) ; \
		cp -rf $(RTL8723_KO)/firmware/* $(RTL8723_CFG)/ ; \
	fi

.PHONY: scripts-clean
scripts-clean:
	@echo - Removing init scripts from filesystem
	$(Q)$(MAKE) -C $(SCRIPTS_PATH) clean

.PHONY: install
install: $(BINPKG_DIR)
ifeq ($(CONFIG_SECURE_BOOT), y)
	@echo Copying filesystem to $(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_DIR)
	$(Q)install -d $(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_DIR)
	$(Q)cp -r $(ROOTFS_IMAGE_PATH)/rel $(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_DIR)
	$(Q)cp -r $(ROOTFS_IMAGE_PATH)/dbg $(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_DIR)
else # !CONFIG_SECURE_BOOT
	@echo Copying filesystem to $(BINPKG_DIR)
	$(Q)cp $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE) \
		$(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin
endif # CONFIG_SECURE_BOOT

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin

.PHONY: clean
clean: clean-sysroot clean-image scripts-clean clean-kernel-initramfs
	$(Q)rm -rf $(TEMP_PATH)/_*

.PHONY: clean-sysroot
clean-sysroot:
	@echo - Cleaning up rootfs...
	$(Q)rm -rf $(SYSROOT_DBG)
	$(Q)rm -rf $(SYSROOT_REL)

.PHONY: clean-image
clean-image:
	@echo - Cleaning up rootfs image...
	$(Q)rm -rf $(ROOTFS_IMAGE_PATH)

.PHONY: clean-kernel-initramfs
clean-kernel-initramfs:
ifeq ($(CONFIG_INITRAMFS), y)
	@echo - Cleaning up kernel initramfs...
	$(Q)rm -rf $(INITRAMFS_OUTPUT_PATH)
endif

.PHONY: distclean
distclean: uninstall clean
	$(Q)rm -rf $(ROOTFS_OUTPUT_PATH)

$(TEMP_PATH) \
$(SYSTEMFS) \
$(BINPKG_DIR) \
$(BINPKG_SIGN_DIR) \
$(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_DIR) \
$(BINPKG_SIGN_ROOTFS)/$(VER)/tmp \
$(ROOTFS_OUTPUT_PATH) \
$(ROOTFS_IMAGE_PATH) \
$(ROOTFS_IMAGE_PATH)/dbg \
$(ROOTFS_IMAGE_PATH)/rel \
$(SYSROOT_DBG) \
$(SYSROOT_REL) \
$(SYSROOT)/mnt/nfs/ethnfs \
$(SYSROOT)/mnt/sdcard \
$(SYSROOT)/mnt/usb \
$(SYSROOT)/usrdata \
$(SYSROOT)/calib \
$(SYSROOT)/system \
$(INITRAMFS_OUTPUT_PATH)/dev \
$(INITRAMFS_OUTPUT_PATH)/proc \
$(INITRAMFS_OUTPUT_PATH)/root \
$(INITRAMFS_OUTPUT_PATH)/tmp \
$(INITRAMFS_OUTPUT_PATH)/sys:
	$(Q)install -d $@
