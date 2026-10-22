SDKSRC_DIR ?= $(realpath $(CURDIR)/../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

BULDROOT_RECORD_CONFIG = $(BUILDROOT_OUTPUT_PATH)/../build/.config

-include $(BULDROOT_RECORD_CONFIG)

# install
INSTALL := install -c
INSTALL_PROGRAM := $(INSTALL)
INSTALL_DATA := $(INSTALL) -m 644

CD := cd
CP := cp
MAKE := make
LN := ln
RM := rm -f
TAR := tar
NICE := nice

NICENESS := 19
TAR_CHECKPOINT := 8000
NICE_TAR := $(NICE) -n $(NICENESS) $(TAR) --checkpoint=.$(TAR_CHECKPOINT)

# Whether to force installing pre-built image.
#   0: Skip image extraction if the local build exists.
#   1: Force image extraction regardless of the local build.
FORCE_INSTALL ?= 0

ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif

DEFCONFIG ?= $(BUILDROOT_DEFCONFIG)
KCONFIG_CONFIG ?= $(BUILDROOT_OUTPUT_PATH)/.config

BUILDROOT_OPTS := O=$(BUILDROOT_OUTPUT_PATH) -C $(BUILDROOT_SRC_PATH)
MAKE_BUILDROOT := $(MAKE) $(BUILDROOT_OPTS)

LOCAL_TARBALL_FILENAME := output.tgz
LOCAL_TARBALL := $(addprefix $(BUILDROOT_PATH)/, $(LOCAL_TARBALL_FILENAME))
REMOTE_TARBALL_PATH := /tools/buildroot/output

IS_INSIDE_WORK_TREE = $(shell git -C $(BUILDROOT_SRC_PATH) rev-parse --is-inside-work-tree > /dev/null 2>&1; echo $$?)
GIT_STATUS = $(shell git -C $(BUILDROOT_SRC_PATH) status --porcelain 2> /dev/null)
COMMIT_HASH = $(shell git -C $(BUILDROOT_SRC_PATH) rev-parse HEAD 2> /dev/null | cut -c1-8)
PREBUILT_FMT_VERSION ?= v2
TOOLCHAIN_ID = $(shell \
	if [ -n "$(TOOLCHAIN_PATH)" ]; then \
		git -C "$(TOOLCHAIN_PATH)" rev-parse HEAD 2>/dev/null | cut -c1-8; \
	fi)
PREBUILT_KEY := $(PREBUILT_FMT_VERSION)-br$(COMMIT_HASH)-tc$(TOOLCHAIN_ID)

LOCAL_TARBALL_STAT = $(shell stat -c %Y $(LOCAL_TARBALL) 2>/dev/null)
LOCAL_TARBALL_MTIME = $(shell date '+%Y%m%d_%H%M%S' --date=@$(LOCAL_TARBALL_STAT) 2>/dev/null)

ifdef BUILDROOT_DEFCONFIG
BUILDROOT_DEFCONFIG_PREFIX = $(BUILDROOT_DEFCONFIG:%_defconfig=%-)
else
BUILDROOT_DEFCONFIG_PREFIX = $(CROSS_COMPILE)
BUILDROOT_DEFCONFIG = $(CROSS_COMPILE)_defconfig
endif

REMOTE_TARBALL_PATTERN = $(BUILDROOT_DEFCONFIG_PREFIX)$(PREBUILT_KEY)_????????_??????.tgz
REMOTE_TARBALL_FILENAME = $(BUILDROOT_DEFCONFIG_PREFIX)$(PREBUILT_KEY)_$(LOCAL_TARBALL_MTIME).tgz
REMOTE_TARBALL = $(shell ls $(REMOTE_TARBALL_PATH)/$(REMOTE_TARBALL_PATTERN) 2>/dev/null | sort | tail -1)
REMOTE_TARBALL_TARGET = $(addprefix $(REMOTE_TARBALL_PATH)/, $(REMOTE_TARBALL_FILENAME))

# $(call config_written, defconfig)
#  Indicate the configuration file has been written.
define config_written
	@echo \#
	@echo \# configuration written to $(1)
	@echo \#
endef

# $(pack_local_tarball)
define pack_local_tarball
	@printf "Packing pre-built Buildroot" && \
	$(NICE_TAR) -zcf $(LOCAL_TARBALL) -C $(BUILDROOT_PATH) output && \
	echo
endef

# $(unpack_local_tarball)
define unpack_local_tarball
	@printf "Unpacking pre-built Buildroot" && \
	$(NICE_TAR) -xf $(LOCAL_TARBALL) -C $(BUILDROOT_PATH) && \
	echo
endef

# $(install_prebuilt_buildroot)
#   Install corresponding pre-built Buildroot.
#
#   | FORCE_INSTALL | has target dir | install |
#   |---------------|----------------|---------|
#   | 0             | no             | yes     |
#   | 0             | yes            | no      |
#   | 1             | no             | yes     |
#   | 1             | yes            | yes     |
define install_prebuilt_buildroot
	@if [ "$(FORCE_INSTALL)" = 1 ] || \
		[ ! -e "$(BUILDROOT_OUTPUT_PATH)/target" ]; \
	then \
		printf "Installing pre-built Buildroot" && \
		$(NICE_TAR) -xf $(REMOTE_TARBALL) -C $(BUILDROOT_PATH) && \
		echo && \
		echo The pre-built Buildroot has been installed successfully.; \
	else \
		echo The pre-built Buildroot already exists. Skipped installation.; \
	fi
endef

.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all:
	$(Q)$(MAKE_BUILDROOT) $@
	$(Q)$(MAKE) --no-print-directory fix-staging

.PHONY: fix-staging
fix-staging:
	$(Q)$(CD) $(BUILDROOT_OUTPUT_PATH) && \
		$(LN) -nsf \
			$(addsuffix /sysroot, \
				$(addprefix ./host/, \
					$(notdir \
						$(shell \
							find "$(BUILDROOT_OUTPUT_PATH)/host" \
								-type d \
								-name "arm-buildroot-linux-*")))) \
			staging

.PHONY: clean
clean: clean-tarball clean-record-config
	$(Q)$(MAKE_BUILDROOT) $@

.PHONY: distclean
distclean: clean-tarball clean-record-config
	$(Q)$(MAKE_BUILDROOT) distclean
	$(RM) -r $(BUILDROOT_OUTPUT_PATH)

.PHONY: clean-tarball
clean-tarball:
ifneq ("$(wildcard $(LOCAL_TARBALL))", "")
	$(RM) $(LOCAL_TARBALL)
endif

.PHONY: clean-record-config
clean-record-config:
	$(RM) -r $(BULDROOT_RECORD_CONFIG)

.PHONY: busybox-menuconfig busybox-update-defconfig
busybox-menuconfig busybox-update-defconfig:
	$(Q)$(MAKE_BUILDROOT) $@

.PHONY: swupdate-menuconfig swupdate-update-defconfig
swupdate-menuconfig swupdate-update-defconfig:
	$(Q)$(MAKE_BUILDROOT) $@

.PHONY: config nconfig menuconfig oldconfig olddefconfig source
config nconfig menuconfig oldconfig source:
	$(Q)$(MAKE_BUILDROOT) $@

.PHONY: %-dirclean %-rebuild %-reconfigure %-reinstall
%-dirclean %-rebuild %-reconfigure %-reinstall:
	$(Q)$(MAKE_BUILDROOT) $@


.PHONY: pkg-stats
pkg-stats:
	$(BUILDROOT_SRC_PATH)/support/scripts/pkg-stats -c \
		--json $(BUILDROOT_OUTPUT_PATH)/pkg-stats.json \
		--html $(BUILDROOT_OUTPUT_PATH)/pkg-stats.html \
		--nvd-path $(BR2_DL_DIR)/buildroot-nvd

.PHONY: show-info
show-info:
	$(Q)$(MAKE_BUILDROOT) $@

.PHONY: printvars
printvars:
	$(MAKE_BUILDROOT) $@

.PHONY: print-prebuilt-info
print-prebuilt-info:
	@echo "BUILDROOT_HASH=$(COMMIT_HASH)"
	@echo "TOOLCHAIN_ID=$(TOOLCHAIN_ID)"
	@echo "PREBUILT_KEY=$(PREBUILT_KEY)"
	@echo "REMOTE_TARBALL_PATTERN=$(REMOTE_TARBALL_PATTERN)"
	@echo "REMOTE_TARBALL_TARGET=$(REMOTE_TARBALL_TARGET)"

.PHONY:  graph-depends  graph-rdepends
graph-depends  graph-rdepends:
	$(Q)$(MAKE_BUILDROOT) $@

.PHONY:  %-graph-depends  %-graph-rdepends
 %-graph-depends  %-graph-rdepends:
	$(Q)$(MAKE_BUILDROOT) $@

.PHONY: %-show-rdepends %-show-rdepends %-show-recursive-depends
 %-show-rdepends %-show-rdepends %-show-recursive-depends:
	$(Q)$(MAKE_BUILDROOT) $@

.PHONY: defconfig
defconfig:
	$(Q)$(MAKE_BUILDROOT) $(DEFCONFIG)

.PHONY: savedefconfig
savedefconfig:
	$(Q)$(CP) -f $(KCONFIG_CONFIG) $(BUILDROOT_CONFIG_PATH)/$(DEFCONFIG)
	$(call config_written,$(DEFCONFIG))

.PHONY: pack
pack: $(BUILDROOT_OUTPUT_PATH) clean-tarball
	$(pack_local_tarball)

.PHONY: unpack
unpack:
	$(unpack_local_tarball)

.PHONY: install
install:
	$(install_prebuilt_buildroot)

.PHONY: push
push: $(LOCAL_TARBALL)
	@set -e; \
	confirmed=0; \
	if [ "$(YES)" = "1" ]; then \
		echo "[push] skip confirmation (YES=1)"; \
		confirmed=1; \
	else \
		if [ ! -t 0 ]; then \
			echo "[push] No TTY; skip push (use YES=1 to force)."; \
			confirmed=0; \
		else \
			printf "[push] Ready to upload '%s' -> '%s'. Type 'yes' to continue: " "$(LOCAL_TARBALL)" "$(REMOTE_TARBALL_TARGET)"; \
			read -r ans; \
			case "$$ans" in yes|YES|y|Y) confirmed=1;; *) confirmed=0;; esac; \
		fi; \
	fi; \
	if [ "$$confirmed" -ne 1 ]; then \
		echo "[push] Skipped."; \
		exit 0; \
	fi; \
	echo "Uploading pre-built Buildroot..."; \
	$(INSTALL_DATA) "$<" "$(REMOTE_TARBALL_TARGET)"; \
	echo "[push] Done."

.PHONY: build
build:
	$(info buildroot defconfig : $(BUILDROOT_DEFCONFIG))
	@if [ "$(IS_INSIDE_WORK_TREE)" = "0" ] && \
		[ "$(GIT_STATUS)" = "" ] && \
		[ "$(COMMIT_HASH)" != "" ] && \
		[ -f "$(REMOTE_TARBALL)" ]; \
	then \
		echo Download buildroot from ${REMOTE_TARBALL_PATH}; \
		$(MAKE) install; \
	else \
		echo Building initial Buildroot...; \
		$(MAKE) all; \
	fi

%_defconfig: DEFCONFIG=$@
%_defconfig: $(BUILDROOT_CONFIG_PATH)/%_defconfig
	$(Q)DEFCONFIG=$(DEFCONFIG) $(MAKE) V=1 --no-print-directory defconfig
	@echo "BUILDROOT_DEFCONFIG=$(DEFCONFIG)" > $(BULDROOT_RECORD_CONFIG)
