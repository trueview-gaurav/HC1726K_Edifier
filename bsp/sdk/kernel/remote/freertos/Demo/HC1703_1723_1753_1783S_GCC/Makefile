SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(REMOTE_PATH)/internal.mk
-include $(REMOTE_PATH)/.config

CPVS_SRC := $(CPVS_PATH)/..
FREERTOS_DIR := ../..

TENSORFLOW_DIR := $(BUILDROOT_OUTPUT_BUILD_PATH)/tensorflow-2.6.0
MICROLITE_DIR := $(TFLITE_MICRO_PATH)
NCNN_DIR := $(NCNN_PATH)
EIGEN_DIR := $(BUILDROOT_OUTPUT_BUILD_PATH)/eigen-3.4.0
ROSA_DIR := $(ROSA_PATH)


.PHONY: default
default: all

################################################################################
# Build tools
################################################################################

CC := $(CROSS_COMPILE)gcc
CXX := $(CROSS_COMPILE)g++
AS := $(CROSS_COMPILE)as
AR := $(CROSS_COMPILE)ar
NM := $(CROSS_COMPILE)nm
LD := $(CROSS_COMPILE)ld
OBJDUMP := $(CROSS_COMPILE)objdump
OBJCOPY := $(CROSS_COMPILE)objcopy
RANLIB := $(CROSS_COMPILE)ranlib
STRIP := $(CROSS_COMPILE)strip
RM := rm -f
MKDIR := mkdir
RMDIR := rmdir

################################################################################
# Build flags
################################################################################

AFLAGS_ALL := -g -mcpu=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard
COMMON_FLAGS := -g -mcpu=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard \
			  	-fstrict-volatile-bitfields -mno-unaligned-access \
			  	-ffreestanding -ffunction-sections -fdata-sections -fno-short-enums \
				-MMD -DprojCOVERAGE_TEST=0 \
				-DTF_LITE_STATIC_MEMORY \
				-fno-unwind-tables \
				-fmessage-length=0


ifeq ($(CONFIG_LIBNCNN),y)
COMMON_FLAGS += -DUSE_NCNN
endif

ifeq ($(CONFIG_LIBTFLITE_MICRO),y)
COMMON_FLAGS += -DUSE_TFLITE_MICRO
endif

ifeq ($(CONFIG_LIBROSA),y)
COMMON_FLAGS += -DUSE_ROSA
endif

ifeq ($(CONFIG_EARLY_DETECT),y)
COMMON_FLAGS += -DEARLY_DETECT
endif

ifeq ($(CONFIG_EARLY_OD),y)
COMMON_FLAGS += -DUSE_EARLY_OD
endif


CFLAGS_ALL := $(COMMON_FLAGS) -std=gnu99
CFLAGS_ALL += -Os

CXXFLAGS_ALL := $(COMMON_FLAGS) -Os -std=c++11 \
				-fno-rtti \
				-fno-exceptions \
				-fno-threadsafe-statics \
				-fno-use-cxa-atexit

LFLAGS_ALL := --static --gc-sections
LFLAGS_ALL += --warn-unresolved-symbols
LLIBS_ALL := -L$(AMPC_SRC_PATH)/lib -lampc_freertos \
	-L$(OPENAMP_SRC_PATH)/build/freertos/lib -lopen_amp \
	-L$(LIBMETAL_SRC_PATH)/build/freertos/lib -lmetal \

ifeq ($(CONFIG_LIBNCNN),y)
LIBGCC_DIR := $(shell dirname `$(CROSS_COMPILE_1)gcc -print-libgcc-file-name`)
$(info [INFO] Using LIBGCC = $(LIBGCC_DIR))
LLIBS_ALL += -L$(NCNN_DIR)/build/freertos/src -lncnn \
             -L $(LIBGCC_DIR) -lgcc
endif

ifeq ($(CONFIG_LIBTFLITE_MICRO),y)
LLIBS_ALL += -L$(MICROLITE_DIR)/build_microlite/lib -ltensorflow-microlite
endif

################################################################################
# Build commands
################################################################################

ASSEMBLE = $(CC) $(AFLAGS_ALL) $(AFLAGS_LOCAL) -o $@ -c $<
COMPILE = $(CC) $(CFLAGS_ALL) $(CFLAGS_LOCAL) -o $@ -c $<
COMPILE_CXX = $(CXX) $(CXXFLAGS_ALL) $(CXXFLAGS_LOCAL) -o $@ -c $<
LINK = $(LD) $(LFLAGS_ALL) $(LFLAGS_LOCAL) -o $@ $^ $(LLIBS_LOCAL) $(LLIBS_ALL)
ARCHIVE = $(AR) rcs $@ $^

################################################################################
# Quiet options
################################################################################

V ?= 0
ifeq ($(V),1)
        Q :=
        VOUT :=
else
        Q := @
        VOUT := 2>&1 1>/dev/null
endif

################################################################################
# Project-Specific Ruleset
################################################################################

PROJECT         = hc1703_1723_1753_1783s
COMPILER_TYPE   = GCC
PROCESSOR_ARCH  = ARM_CA7
PROCESSOR_TYPE  = HC1703_1723_1753_1783S
PROJECT        := $(PROCESSOR_TYPE)_$(COMPILER_TYPE)

TRGT = freertos

################################################################################
# Common Ruleset
################################################################################

PROCESSOR_PORT_DIR := $(FREERTOS_DIR)/Source/portable/$(COMPILER_TYPE)/$(PROCESSOR_ARCH)

INCLUDE_DIRS := -I.
INCLUDE_DIRS += -I$(FREERTOS_DIR)/Source/include
INCLUDE_DIRS += -I$(PROCESSOR_PORT_DIR)
INCLUDE_DIRS += -I$(FREERTOS_DIR)/Demo/Common
INCLUDE_DIRS += -I$(FREERTOS_DIR)/cpvs/include
INCLUDE_DIRS += -I$(FREERTOS_DIR)/cpvs/include/intc
INCLUDE_DIRS += -I$(FREERTOS_DIR)/cpvs/include/ca7_timer
INCLUDE_DIRS += -I$(FREERTOS_DIR)/cpvs/include/cpu
INCLUDE_DIRS += -I$(FREERTOS_DIR)/cpvs/include/mmu
INCLUDE_DIRS += -I$(FREERTOS_DIR)/cpvs/include/uart
INCLUDE_DIRS += -I$(FREERTOS_DIR)/cpvs/include/utils
INCLUDE_DIRS += -I$(FREERTOS_DIR)/cpvs/include/csr
INCLUDE_DIRS += -I$(LIBMETAL_SRC_PATH)/build/freertos/lib/include/
INCLUDE_DIRS += -I$(OPENAMP_SRC_PATH)/lib/include/
INCLUDE_DIRS += -I$(AMPC_SRC_PATH)/include/
INCLUDE_DIRS += -I$(AMPC_SRC_PATH)/src/
INCLUDE_DIRS += -I$(AMPC_SRC_PATH)/src/common/
INCLUDE_DIRS += -I$(FEATURE_VIDEO_PATH)/include/
INCLUDE_DIRS += -I$(MPP_INC)
INCLUDE_DIRS += -I$(SAMPLE_DEMO_PATH)/ai/libinf/include/
INCLUDE_DIRS += -I$(SDKSRC_DIR)/sdk/top/include/
INCLUDE_DIRS += -I$(TENSORFLOW_DIR)/build_microlite/include/

INCLUDE_DIRS += -I$(ROSA_DIR)/src
INCLUDE_DIRS += -I$(EIGEN_DIR)

INCLUDE_DIRS += -I$(NCNN_DIR)/src/
INCLUDE_DIRS += -I$(NCNN_DIR)/build/freertos/src/

ifeq ($(CONFIG_SYS_MEM_TOP_HIDE), 0x02000000)
LINKER_POST_FIX := _ram_32mb_shm
HEAP_SIZE := 0x1C00000
else ifeq ($(CONFIG_SYS_MEM_TOP_HIDE), 0x01000000)
LINKER_POST_FIX := _ram_16mb_shm
HEAP_SIZE := 0xE00000
else ifeq ($(CONFIG_SYS_MEM_TOP_HIDE), 0x01600000)
LINKER_POST_FIX := _ram_22mb_shm
HEAP_SIZE := 0x1300000
else ifeq ($(CONFIG_SYS_MEM_TOP_HIDE), 0x00A00000)
LINKER_POST_FIX := _ram_10mb_shm
HEAP_SIZE := 0x7BF000
else ifeq ($(CONFIG_SYS_MEM_TOP_HIDE), 0x01800000)
LINKER_POST_FIX := _ram_24mb_shm
HEAP_SIZE := 0x1400000
endif

LDSCRIPT := ./freertos.ld

SOURCE_FILES := $(wildcard *.[cS])
SOURCE_FILES += $(wildcard *.cc)
SOURCE_FILES += $(wildcard md/*.[cS])
SOURCE_FILES += $(wildcard amp_driver/*.[cS])
SOURCE_FILES += $(wildcard $(FREERTOS_DIR)/Source/*.[cS])
SOURCE_FILES += $(wildcard $(FREERTOS_DIR)/cpvs/src/*/*.[cS])
SOURCE_FILES += $(wildcard $(PROCESSOR_PORT_DIR)/*.[cS])

# Memory manager (use malloc() / free())
SOURCE_FILES += $(FREERTOS_DIR)/Source/portable/MemMang/heap_4.c

CFLAGS_LOCAL := $(INCLUDE_DIRS) -DconfigTOTAL_HEAP_SIZE=$(HEAP_SIZE)
LFLAGS_LOCAL := -T $(LDSCRIPT)
CXXFLAGS_LOCAL := $(INCLUDE_DIRS)

# *.[cS] -> *.o
# OBJ_FILES_INTM := $(SOURCE_FILES:.c=.o)
OBJ_FILES_INTM := $(patsubst %.c, %.o, $(patsubst %.cc, %.o, $(SOURCE_FILES)))
OBJ_FILES := $(OBJ_FILES_INTM:.S=_S.o)

DEP_FILES = $(OBJ_FILES:.o=.d)
-include $(DEP_FILES)

CODE_SIZE := 28672

BIN := $(TRGT).bin
ELF := $(BIN:.bin=.elf)
LIB := $(TRGT).a

################################################################################
# General directory independent rules
################################################################################

.PHONY: lib
lib: $(LIB)

%.a: $(OBJ_FILES)
	@echo build static library
	$(Q)$(ARCHIVE)


.PHONY: all
all: $(BIN)



$(ELF) : $(OBJ_FILES)
ifeq ($(CONFIG_DRAM_CAPACITY), 128)
	ln -sf freertos_128mb$(LINKER_POST_FIX).ld freertos.ld
else ifeq ($(CONFIG_DRAM_CAPACITY), 256)
	ln -sf freertos_256mb$(LINKER_POST_FIX).ld freertos.ld
else ifeq ($(CONFIG_DRAM_CAPACITY), 64)
	ln -sf freertos_64mb$(LINKER_POST_FIX).ld freertos.ld
else ifeq ($(CONFIG_DRAM_CAPACITY), 512)
	ln -sf freertos_512mb$(LINKER_POST_FIX).ld freertos.ld
endif
	-@mkdir -p $(@D)
	@printf " LD\t$@\n"
	$(Q)$(LINK)

%.bin: %.elf
	$(Q)$(OBJCOPY) -O binary --strip-all --strip-debug $< $@
	@echo -e "OBJCOPY\t$@"

%.o: %.c
	-@mkdir -p $(@D)
	@printf "  CC\t$@\n"
	$(Q)$(COMPILE)

%.o: %.cc
	-@mkdir -p $(@D)
	@printf "  CXX\t$@\n"
	$(Q)$(COMPILE_CXX)

%_S.o: %.S
	-@mkdir -p $(@D)
	@printf "  AS\t$@\n"
	$(Q)$(ASSEMBLE)

.PHONY: clean

clean:
	-rm -f $(BIN) $(ELF)
	-find $(FREERTOS_DIR) -name "*.[doa]" -delete

.PHONY: install

install:
	@if [ ! -d $(BINPKG_DIR) ]; then mkdir $(BINPKG_DIR); fi
	cp $(BIN) $(BINPKG_DIR)/$(BIN)

.PHONY: uninstall
uninstall:
	$(Q)$(RM) $(BINPKG_DIR)/$(BIN)

.PHONY: distclean
distclean:
	$(Q)$(RM) -rf freertos.ld
