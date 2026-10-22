SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/internal.mk

CC=$(CROSS_COMPILE)gcc

# FIXME: 'json_object_object_get' is deprecated. Please fix it in 'main.c'.

PRODUCT ?= $(shell echo $(CONFIG_PROD) | cut -d"_" -f1)
SKU     ?= $(shell echo $(CONFIG_PROD) | cut -d"_" -f2-)

PRODUCT := $(shell echo $(PRODUCT) | tr '[A-Z]' '[a-z]')

# To be removed after modifying CONFIG_PROD for EVB
ifeq ($(PRODUCT), hc1703)
	PRODUCT := tb
	SKU := hc1703_tb
else ifeq ($(PRODUCT), hc1723)
	PRODUCT := tb
	SKU := hc1723_tb
else ifeq ($(PRODUCT), hc1753)
	PRODUCT := tb
	SKU := hc1753_tb
else ifeq ($(PRODUCT), hc1783s)
	PRODUCT := tb
	SKU := hc1783s_tb
else ifeq ($(PRODUCT), hc1705)
	PRODUCT := tb
	SKU := hc1705_tb
else ifeq ($(PRODUCT), hc1715)
	PRODUCT := tb
	SKU := hc1715_tb
else ifeq ($(PRODUCT), hc1725)
	PRODUCT := tb
	SKU := hc1725_tb
else ifeq ($(PRODUCT), hc1725s)
	PRODUCT := tb
	SKU := hc1725s_tb
else ifeq ($(PRODUCT), hc1753s)
	PRODUCT := tb
	SKU := hc1753s_tb
else ifeq ($(PRODUCT), hc1706)
	PRODUCT := tb
	SKU := hc1706_tb
else ifeq ($(PRODUCT), hc1706h)
	PRODUCT := tb
	SKU := hc1706h_tb
else ifeq ($(PRODUCT), hc1706k)
	PRODUCT := tb
	SKU := hc1706k_tb
else ifeq ($(PRODUCT), hc1726)
	PRODUCT := tb
	SKU := hc1726_tb
else
	SKU := sku_$(SKU)
endif

DFT_PATH := $(SQLAPP_PATH)/dftdata
COMM_DFT_PATH := $(DFT_PATH)/common
PROJ_DFT_PATH := $(DFT_PATH)/$(PRODUCT)
PROD_DFT_PATH := $(PROJ_DFT_PATH)/$(SKU)
SQLITE3_PATH := $(SQLITE3_ROOT)
SQLITE3_LIB_PATH := $(SQLITE3_LIB)
JSONC_PATH := $(JSON_ROOT)
JSONC_LIB_PATH := $(JSON_LIB)
TARGET_LIB := $(BUILDROOT_TARGET_LIB)
LD_LIBRARY_PATH := $(TARGET_LIB):$(LD_LIBRARY_PATH)
export LD_LIBRARY_PATH

ifeq ($(CROSS_COMPILE), arm-linux-gnueabi-)
	TOOLCHAIN_LIB := $(TOOLCHAIN_PATH)/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi/arm-linux-gnueabi/libc
else ifeq ($(CROSS_COMPILE), arm-linux-gnueabihf-)
	TOOLCHAIN_LIB := $(TOOLCHAIN_PATH)/gcc-linaro-4.9-2016.02-x86_64_arm-linux-gnueabihf/arm-linux-gnueabihf/libc
else ifeq ($(CROSS_COMPILE), arm-augentix-linux-uclibcgnueabihf-)
	TOOLCHAIN_LIB := $(TOOLCHAIN_PATH)/arm-augentix-linux-uclibcgnueabihf/arm-augentix-linux-uclibcgnueabihf/sysroot
else ifeq ($(CROSS_COMPILE), arm-augentix-linux-uclibcgnueabi-)
	TOOLCHAIN_LIB := $(TOOLCHAIN_PATH)/arm-augentix-linux-uclibcgnueabi/arm-augentix-linux-uclibcgnueabi/sysroot
else
$(error Cannot build sqlapp using Toolchain: $(CROSS_COMPILE), please check your product config!)
endif

BIN=sqlapp

INC := -I$(APP_INC) -I$(DFT_PATH) -I$(PROJ_DFT_PATH) -I$(PROD_DFT_PATH) -I$(LIBCM_INC) -I$(CENTCTRL_INC) -I$(SQLAPP_INC) -I$(SQLITE3_PATH) -I$(JSONC_PATH)

OBJS := main.o sqllib.o shared_mutex.o cc_data.o cc_utils.o
DEPS := $(OBJS:.o=.d)
CFLAGS += -Wno-deprecated-declarations -Wno-missing-field-initializers -MMD $(INC)
LDFLAGS := -L$(SQLITE3_LIB_PATH) -L$(JSONC_LIB_PATH) -L$(SQLAPP_PATH) -L$(LIBCM_PATH)
LDLIBS := -pthread -lrt -lsqlite3 -ljson-c -l:libcm.a

TARGETS = $(BIN)
SYSTEM_DEST = $(SYSTEMFS)/factory_default/
USRDATA_DEST = $(USRDATAFS_PATH)/usrdata/active_setting/


.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	$(Q)$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

%.o: %.c
	$(Q)$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: install
install:
	$(Q)rm -f ini.db
	$(Q)qemu-arm -L $(TOOLCHAIN_LIB) ./sqlapp 1
	$(Q)qemu-arm -L $(TOOLCHAIN_LIB) ./sqlapp 3 $(SQLAPP_PATH)/dftdata/common/
	$(Q)qemu-arm -L $(TOOLCHAIN_LIB) ./sqlapp 3 $(PROJ_DFT_PATH)/
	$(Q)qemu-arm -L $(TOOLCHAIN_LIB) ./sqlapp 3 $(PROD_DFT_PATH)/
	@mkdir -p $(SYSTEM_DEST)
	$(Q)cp -f  ini.db $(SYSTEM_DEST)
	@mkdir -p $(USRDATA_DEST)
	$(Q)cp -f  ini.db $(USRDATA_DEST)

$(DEST):
	$(Q)install -d $@

$(DEST)/%: %
	$(Q)install -m 777 $< $@

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(SYSTEM_DEST)/ini.db
	$(Q)rm -f $(USRDATA_DEST)/ini.db


.PHONY: clean
clean:
	$(Q)find . -type f -name "*.[doa]" -exec rm -f {} \;
	$(Q)rm -f ini.db
	$(Q)rm -f $(BIN) $(OBJS) $(DEPS)

.PHONY: distclean
distclean: uninstall clean

sinclude $(DEPS)
