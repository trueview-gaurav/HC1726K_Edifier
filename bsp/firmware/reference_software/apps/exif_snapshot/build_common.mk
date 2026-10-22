# Common build utilities and rules

# install
INSTALL := install -c
INSTALL_PROGRAM := $(INSTALL)
INSTALL_DATA := $(INSTALL) -m 644

# utils
CP := cp
LN := ln
MKDIR := mkdir
MKDIR_P := mkdir -p
MV := mv
RM := rm -f
RM_RF := rm -rf

# some useful pre-defined variables
blank :=
space := $(blank) $(blank)
comma := $(blank),$(blank)

# toolchain
# Allow CROSS_COMPILE to be set from environment or command line
CROSS_COMPILE ?=
AR = $(CROSS_COMPILE)ar
CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
STRIP = $(CROSS_COMPILE)strip

# paths
bindir = $(SYSTEM_BIN)
BIN_OUT_PATH = $(root)/bin
INC_PATH = $(root)/include
OBJ_PATH = $(root)/obj
SRC_PATH = $(root)/src
SRC_INC_PATH = $(root)/src/inc
DEP_PATH = $(root)/.deps
STAMP_PATH = $(root)/.stamps

# compiler/linker flags
CFLAGS += -I"$(INC_PATH)" -iquote"$(SRC_INC_PATH)" -I"$(GEN_INC)"
CXXFLAGS += -I"$(INC_PATH)" -iquote"$(SRC_INC_PATH)" -I"$(GEN_INC)"

# Stamp file for dependency checking
DEPS_CHECKED_STAMP = $(STAMP_PATH)/.deps_checked

# Additional flags for EXIF snapshot
CFLAGS += -I$(MPP_INC) -I$(LIBEXIF_INC)
CXXFLAGS += -I$(MPP_INC) -I$(LIBEXIF_INC)

# Thread support flags
CFLAGS += -pthread -D_REENTRANT
CXXFLAGS += -pthread -D_REENTRANT
LDFLAGS += -pthread

# Library paths
LDFLAGS += -L$(MPP_LIB) -L$(LIBEXIF_LIB)

# Libraries to link
LDLIBS += -lmpp -lexif -lm

# dependency flags
DEPFLAGS = -MT "$@" -MMD -MP -MF "$(DEP_PATH)/$*.d"

# source codes, objects, and dependencies
SRCS = $(wildcard $(SRC_PATH)/*.c)
OBJS = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o,$(SRCS))
DEPS = $(patsubst $(SRC_PATH)/%.c,$(DEP_PATH)/%.d,$(SRCS))

# Binary name and paths
BIN_NAME = exif_snapshot
BIN = $(BIN_OUT_PATH)/$(BIN_NAME)
BIN_TARGET = $(SYSTEM_BIN)/$(BIN_NAME)

# toggle verbose output
V ?= 0
ifeq ($(V),1)
	Q :=
	VOUT :=
else
	Q := @
	VOUT := 2>&1 1>/dev/null
endif

# Create directories if they don't exist
$(OBJ_PATH) $(BIN_OUT_PATH) $(DEP_PATH) $(STAMP_PATH) $(SYSTEM_BIN):
	$(Q)$(MKDIR_P) $@

# Dependency checking rule - runs before any compilation
$(DEPS_CHECKED_STAMP): | $(STAMP_PATH)
	@echo "Checking dependencies..."
	@# Check local project paths
	@if [ ! -d "$(SRC_PATH)" ]; then \
		echo "Error: SRC_PATH does not exist: $(SRC_PATH)" >&2; \
		exit 1; \
	fi
	@# Check external library paths
	@if [ ! -d "$(MPP_INC)" ]; then \
		echo "Error: MPP_INC path does not exist: $(MPP_INC)" >&2; \
		exit 1; \
	fi
	@if [ ! -d "$(MPP_LIB)" ]; then \
		echo "Error: MPP_LIB path does not exist: $(MPP_LIB)" >&2; \
		exit 1; \
	fi
	@if [ ! -d "$(LIBEXIF_INC)" ]; then \
		echo "Error: LIBEXIF_INC path does not exist: $(LIBEXIF_INC)" >&2; \
		exit 1; \
	fi
	@if [ ! -d "$(LIBEXIF_LIB)" ]; then \
		echo "Error: LIBEXIF_LIB path does not exist: $(LIBEXIF_LIB)" >&2; \
		exit 1; \
	fi
	@echo "All dependencies verified."
	@touch $@

# Build binary
$(BIN): $(OBJS) | $(BIN_OUT_PATH)
	@echo "  LD      $@"
	$(Q)$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@echo "Built binary: $@"

# Compile objects - depends on stamp file to ensure dependencies are checked first
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS_CHECKED_STAMP) | $(OBJ_PATH) $(DEP_PATH)
	@echo "  CC      $<"
	$(Q)$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cc $(DEPS_CHECKED_STAMP) | $(OBJ_PATH) $(DEP_PATH)
	@echo "  CXX     $<"
	$(Q)$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(DEPS_CHECKED_STAMP) | $(OBJ_PATH) $(DEP_PATH)
	@echo "  CXX     $<"
	$(Q)$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

# dependencies
$(DEP_PATH)/%.d: ;
.PRECIOUS: $(DEP_PATH)/%.d

# Include dependencies
-include $(DEPS)
