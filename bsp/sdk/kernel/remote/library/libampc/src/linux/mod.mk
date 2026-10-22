################################################################################
# [DON'T TOUCH] Traverse directory tree
################################################################################

sp		:= $(sp).x
dirstack_$(sp)	:= $(dir)
dir		:= $(subdir)


################################################################################
# Source files and include directories
################################################################################

SRCS_$(dir) := $(wildcard $(dir)/*.c)
INCS_$(dir) += $(REMOTE_PATH)/amp/ampc/include/
INCS_$(dir) += $(REMOTE_PATH)/amp/ampc/src/linux/inc/
INCS_$(dir) += $(REMOTE_PATH)/amp/libmetal/build/linux/lib/include/
INCS_$(dir) += $(REMOTE_PATH)/amp/openamp/lib/include/
INCS_$(dir) += $(BUILDROOT_HOST_INC)/sysfs/
INCS_$(dir) += $(SDKSRC_DIR)/sdk/top/include/

################################################################################
# Corresponding object files and auto-dependencies
################################################################################

OBJS_$(dir) := $(SRCS_$(dir):.c=.o)
DEPS_$(dir) := $(SRCS_$(dir):.c=.d)

$(OBJS_$(dir)): CFLAGS_LOCAL := $(addprefix -I,$(INCS_$(dir))) -fPIC -D METAL_INTERNAL
-include        $(DEPS_$(dir))

CLEAN_FILES += $(OBJS_$(dir)) $(DEPS_$(dir))

################################################################################
# Targets (Must be placed after "Subdirectories" section)
################################################################################

TARGET_SLIB_$(dir) := $(root)/lib/libampc_linux.a
TARGET_DLIB_$(dir) := $(root)/lib/libampc_linux.so.$(REAL_SUFFIX)
VERSION_SCRIPT_PATH := $(dir)/libampc_linux.map

$(TARGET_SLIB_$(dir)): $(OBJS_$(dir))
	@printf "  %-8s$@\n" "AR"
	$(Q)$(MKDIR) -p $(@D)
	$(Q)$(ARCHIVE_STATIC)

$(TARGET_DLIB_$(dir)): $(OBJS_$(dir))
	@printf "  %-8s$@\n" "CC"
	$(Q)$(MKDIR) -p $(@D)
	$(Q)$(ARCHIVE_SHARED) -Wl,--version-script=$(VERSION_SCRIPT_PATH)
	$(Q)$(LN) -sfT $(notdir $@) $(basename $(basename $(basename $@)))

TARGET_SLIBS += $(TARGET_SLIB_$(dir))
TARGET_DLIBS += $(TARGET_DLIB_$(dir))
CLEAN_FILES += $(TARGET_SLIB_$(dir)) $(TARGET_DLIB_$(dir)) $(basename $(basename $(basename $(TARGET_DLIB_$(dir)))))


################################################################################
# General rules
################################################################################

%.o: %.c
	@printf "  %-8s$@\n" "CC"
	$(Q)$(CC) $(COMPILE) --std=gnu99

%.o: %.cc
	@printf "  %-8s$@\n" "CX"
	$(Q)$(CX) $(COMPILE) --std=c++11

################################################################################
# [DON'T TOUCH] Traverse directory tree
################################################################################

dir		:= $(dirstack_$(sp))
sp		:= $(basename $(sp))

