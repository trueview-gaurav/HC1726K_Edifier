SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

CXX = $(CROSS_COMPILE)g++
CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
AR = $(CROSS_COMPILE)ar
NM = $(CROSS_COMPILE)nm
LD = $(CROSS_COMPILE)ld
OBJDUMP = $(CROSS_COMPILE)objdump
OBJCOPY = $(CROSS_COMPILE)objcopy
RANLIB = $(CROSS_COMPILE)ranlib
STRIP = $(CROSS_COMPILE)strip

SFLAGS := -g
CFLAGS := -g -Os -Wall -Werror -I$(SDK_INC) -I$(CPVS_INC) -I$(CPVS_INC)/csr -I$(CPVS_INC)/dram \
	-I$(CPVS_INC)/pll -I$(CPVS_INC)/platform -I$(CPVS_INC)/qspi -I$(CPVS_INC)/sdc -I$(CPVS_INC)/uart \
	-I$(CPVS_INC)/utils -I$(CPVS_INC)/wdt -I$(CPVS_INC)/nvspc -I$(CPVS_INC)/pinmux -I$(GEN_INC)
CFLAGS += -fdata-sections -ffunction-sections -fno-short-enums -Wno-address-of-packed-member
PIC_CFLAGS := -g -Os -Wall -I$(SDK_INC) -I$(CPVS_INC) -I$(CPVS_INC)/csr -I$(CPVS_INC)/dram \
	-I$(CPVS_INC)/pll -I$(CPVS_INC)/platform -I$(CPVS_INC)/qspi -I$(CPVS_INC)/sdc -I$(CPVS_INC)/uart \
	-I$(CPVS_INC)/utils -I$(CPVS_INC)/wdt -I$(CPVS_INC)/nvspc -I$(GEN_INC) \
	-fdata-sections -ffunction-sections -fno-short-enums -fPIC \
	-I$(CPVS_INC)/efuse -I$(CPVS_INC)/nvspc \
	-Wno-unused-function -Wno-parentheses -Wno-return-type

ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
CFLAGS += -mstrict-align -mcpu=cortex-a55
PIC_CFLAGS += -mstrict-align -mcpu=cortex-a55
else
CFLAGS += -mcpu=cortex-a7
PIC_CFLAGS += -mcpu=cortex-a7
endif

LDFLAGS += --gc-sections -L$(CPVS_LIB) -static -lpid -lutil

# Normal compilation (no PIC)
NORMAL_SRCDIRS := ./
NORMAL_SRCS := $(wildcard $(NORMAL_SRCDIRS)/*.[c]) $(wildcard $(NORMAL_SRCDIRS)/**/*. [c])
NORMAL_OBJS := $(NORMAL_SRCS:.c=.o)

ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
NORMAL_OBJS += nvspc_entry64.s
else
NORMAL_OBJS += nvspc_entry.s
endif

NORMAL_OBJS := $(NORMAL_OBJS:.s=.o)

# PIC compilation for core/cpvs/ files
PIC_SRCDIRS := $(CPVS_SRC)/efuse \
	$(CPVS_SRC)/nvspc \
	$(CPVS_SRC)/utils
PIC_SRCS := $(wildcard $(addsuffix /*.[cs], $(PIC_SRCDIRS)))
PIC_OBJS := $(patsubst %.c, %.pic.o, $(PIC_SRCS:.s=.c))

# All objects
OBJS := $(NORMAL_OBJS) $(PIC_OBJS)

TRGT_NVSPC := nvspc

ifeq ($(CONFIG_KAMO), y)
LD_SCRIPT := nvspc_kamo.ld
else ifeq ($(CONFIG_OSAKA), y)
LD_SCRIPT := nvspc_osaka.ld
else
LD_SCRIPT := nvspc.ld
endif
OUTPUT_DIR := ../bin

.PHONY: default
default: all

.PHONY: all
all: $(TRGT_NVSPC).hex $(TRGT_NVSPC).asm $(TRGT_NVSPC).bin

.PHONY: install
install: all
	@mkdir -p $(OUTPUT_DIR)
	$(Q)install -m 777 *.bin $(OUTPUT_DIR)/

%.hex: %.bin
	$(Q)hexdump -v -e '4/4 "%08x " "\n"' $< | awk -F'[ ]' '{print $$4$$3$$2$$1}' > $@
	@echo -e "HEXDUMP\t$@"

%.bin: %.elf
	$(Q)$(OBJCOPY) -O binary --strip-all --strip-debug $< $@
	$(Q)truncate -s %64 $@
	@echo -e "OBJCOPY\t$@"

%.asm: %.elf
	$(Q)$(OBJDUMP) -D $< > $@
	@echo -e "OBJDUMP\t$@"

$(TRGT_NVSPC).elf: $(LD_SCRIPT) $(OBJS)
	$(Q)$(LD) -T $(LD_SCRIPT) $(OBJS) $(LDFLAGS) -o $@
	@echo -e "LD\t$@"

%.o: %.s
	$(Q)$(AS) $(SFLAGS) $< -o $@
	@echo -e "AS\t$@"

%.o: %.c
	$(Q)$(CC) -c $(CFLAGS) $< -o $@
	@echo -e "CC\t$@"

%.pic.o: %.c
	$(Q)$(CC) -c $(PIC_CFLAGS) $< -o $@
	@echo -e "CC(PIC)\t$@"

.PHONY: clean
clean:
	@rm -f *.hash *.[do] *.bin *.hex *.asm *.elf *.pic.o
	@rm -rf $(OUTPUT_DIR)

# Quiet options
V ?= 0
ifeq ($(V),1)
	Q :=
	VOUT :=
else
	Q := @
	VOUT := 2>&1 1>/dev/null
endif

