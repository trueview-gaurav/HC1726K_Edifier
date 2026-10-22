SDKSRC_DIR ?= $(realpath $(CURDIR)/..)
include $(FIRMWARE_BUILD_PATH)/sdksrc.mk

MAJOR := $(strip $(shell cat $(ABIVER_FILE) | grep -P "major:" | sed "s/major://"))
MINOR := $(strip $(shell cat $(ABIVER_FILE) | grep -P "minor:" | sed "s/minor://"))
PATCH := $(strip $(shell cat $(ABIVER_FILE) | grep -P "patch:" | sed "s/patch://"))

# Parsing major number
# Notes: To update the major version, you should modify the field major in
#        .version manually

ifeq ($(shell echo $(MAJOR) | grep -wP "[0-9]+"),)
    $(error Major number should be an integer!)
endif
ABI_VER := $(MAJOR)

# Parsing minor number
# See: make target 'update-builddate' in Makefile

ifeq ($(shell echo $(MINOR) | grep -wP "[0-9]+"),)
    $(error Minor number should be an integer!)
endif
ifneq ($(CONFIG_RELEASE), y)
    # In SDK manifest, the minor version equals to SDK build date.
    ABI_VER := $(ABI_VER).$(shell date '+%Y%m%d')
else
    # In APP manifest, the minor version can be parsed from $(ABIVER_FILE)
    ABI_VER := $(ABI_VER).$(MINOR)
endif

# Parsing patch number
# See: make target 'version-bump' in Makefile

ifeq ($(shell echo $(PATCH) | grep -wP "[0-9]+"),)
    $(error Patch number should be an integer!)
endif
ifneq ($(CONFIG_RELEASE), y)
    # In SDK manifest, we are developing libraries for next version.
    ABI_VER := $(ABI_VER).$(shell expr $(PATCH) + 1)
else
    # In APP manifest, the patch version can be parsed from $(ABIVER_FILE)
    ABI_VER := $(ABI_VER).$(shell expr $(PATCH))
endif


# Provide macros to externel makefiles

SONAME_SUFFIX := $(MAJOR)
REAL_SUFFIX := $(ABI_VER)
