DEBUG ?= 0
OPTIMIZE ?= 1
WARNING ?= 1

GCCVERSION := $(shell expr ` $(CROSS_COMPILE)gcc -dumpversion`)
GCC_10_3 =
ifeq (,$(findstring 10.3,$(GCCVERSION)))
GCC_10_3 = 0
else
GCC_10_3 = 1
endif

CFLAGS_DEBUG = -g -fno-omit-frame-pointer
CFLAGS_OPTIMIZE =
CFLAGS_WARNING = -Wall -Wextra

ifneq ($(strip $(CROSS_COMPILE)),)
ifneq ($(strip $(CC)),gcc)
ifneq ($(strip $(CONFIG_TARGET_CPU)),)
CFLAGS_OPTIMIZE += -mcpu=$(CONFIG_TARGET_CPU)
endif
endif
endif

ifeq ($(strip $(CROSS_COMPILE)),arm-linux-gnueabihf-)
CFLAGS_OPTIMIZE += -mfpu=neon-vfpv4
endif

ifeq ($(GCC_10_3),1)
CFLAGS_OPTIMIZE += -Os
else
CFLAGS_OPTIMIZE += -O2
CFLAGS_WARNING += -Werror
endif

CFLAGS_COMMON = -std=gnu11 -fPIC
CXXFLAGS_COMMON = -std=c++14 -lstdc++ -fPIC

ARFLAGS = rcsD
CFLAGS := $(CFLAGS_COMMON)
CXXFLAGS := $(CXXFLAGS_COMMON)

CPPFLAGS =
LDFLAGS =
LDLIBS =

CXXFLAGS_DEBUG = $(CFLAGS_DEBUG)
CXXFLAGS_OPTIMIZE = $(CFLAGS_OPTIMIZE)
CXXFLAGS_WARNING = $(CFLAGS_WARNING)

ifeq ($(DEBUG),1)
CFLAGS += $(CFLAGS_DEBUG)
CXXFLAGS += $(CXXFLAGS_DEBUG)
endif

ifeq ($(OPTIMIZE),1)
CFLAGS += $(CFLAGS_OPTIMIZE)
CXXFLAGS += $(CXXFLAGS_OPTIMIZE)
endif

ifeq ($(WARNING),1)
CFLAGS += $(CFLAGS_WARNING)
CXXFLAGS += $(CXXFLAGS_WARNING)
endif
