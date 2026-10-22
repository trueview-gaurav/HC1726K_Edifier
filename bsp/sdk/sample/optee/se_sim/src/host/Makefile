SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../../)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/buildroot.mk

CC      ?= $(CROSS_COMPILE)gcc
LD      ?= $(CROSS_COMPILE)ld
AR      ?= $(CROSS_COMPILE)ar
NM      ?= $(CROSS_COMPILE)nm
OBJCOPY ?= $(CROSS_COMPILE)objcopy
OBJDUMP ?= $(CROSS_COMPILE)objdump
READELF ?= $(CROSS_COMPILE)readelf

OBJS = se_sim.o

CFLAGS += -Wall -I$(TEEC_EXPORT)/include -I./include -I$(OPENSSL_INC)
#Add/link other required libraries here
LDADD += -lteec -L$(TEEC_EXPORT)/lib -L$(OPENSSL_LIB) -lcrypto

BINARY = se_sim

.PHONY: all
all: $(BINARY)

$(BINARY): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $< $(LDADD)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINARY)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
