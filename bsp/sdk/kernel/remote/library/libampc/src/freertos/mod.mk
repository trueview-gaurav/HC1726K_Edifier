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
INCS_$(dir) += $(AMPC_SRC_PATH)/include/
INCS_$(dir) += $(dir)/inc/
INCS_$(dir) += $(LIBMETAL_SRC_PATH)/build/freertos/lib/include/
INCS_$(dir) += $(OPENAMP_SRC_PATH)/lib/include/
INCS_$(dir) += $(REMOTE_PATH)/freertos/Source/include/
INCS_$(dir) += $(REMOTE_PATH)/freertos/Demo/HC1703_1723_1753_1783S_GCC/
INCS_$(dir) += $(REMOTE_PATH)/freertos/cpvs/include/
INCS_$(dir) += $(REMOTE_PATH)/freertos/Source/portable/GCC/ARM_CA7/
INCS_$(dir) += $(SDKSRC_DIR)/sdk/top/include/

################################################################################
# Corresponding object files and auto-dependencies
################################################################################

OBJS_$(dir) := $(SRCS_$(dir):.c=.o)
DEPS_$(dir) := $(SRCS_$(dir):.c=.d)

$(OBJS_$(dir)): CFLAGS_LOCAL := $(addprefix -I,$(INCS_$(dir))) -fPIC
-include        $(DEPS_$(dir))

CLEAN_FILES += $(OBJS_$(dir)) $(DEPS_$(dir))

################################################################################
# Targets (Must be placed after "Subdirectories" section)
################################################################################

TARGET_LIB_NAME = libampc_freertos.a
TARGET_LIB_PATH := $(root)/lib
TARGET_SLIB_$(dir) := $(TARGET_LIB_PATH)/$(TARGET_LIB_NAME)
TARGET_INSTALL_$(dir) := INSTALL_$(TARGET_LIB_NAME)
TARGET_UNINSTALL_$(dir) := UNINSTALL_$(TARGET_LIB_NAME)

$(TARGET_SLIB_$(dir)): $(OBJS_$(dir))
	@printf "  %-8s$@\n" "AR"
	$(Q)$(MKDIR) -p $(@D)
	$(Q)$(ARCHIVE_STATIC)

$(TARGET_DLIB_$(dir)): $(OBJS_$(dir))
	@printf "  %-8s$@\n" "CC"
	$(Q)$(MKDIR) -p $(@D)
	$(Q)$(ARCHIVE_SHARED)
	$(Q)$(LN) -sfT $(notdir $@) $(basename $(basename $(basename $@)))



TARGET_SLIBS += $(TARGET_SLIB_$(dir))
TARGET_DLIBS += $(TARGET_DLIB_$(dir))
CLEAN_FILES += $(TARGET_SLIB_$(dir)) $(TARGET_DLIB_$(dir)) $(basename $(basename $(basename $(TARGET_DLIB_$(dir)))))
CLEAN_FILES += $(TARGET_LIB_PATH)/$(TARGET_LIB_NAME)


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

