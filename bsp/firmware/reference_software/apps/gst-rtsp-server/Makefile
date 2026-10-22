SDKSRC_DIR = $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/internal.mk
include $(APP_PATH)/.config

APP_GST_RTSP_SERVER_ENABLE_IVA := $(CONFIG_APP_GST_RTSP_SERVER_ENABLE_IVA)
$(warning APP_GST_RTSP_SERVER_ENABLE_IVA=$(APP_GST_RTSP_SERVER_ENABLE_IVA))

CC  = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++

PKG_CONFIG ?= $(BUILDROOT_HOST_BIN)/pkg-config
PKG_CONFIG_ENV = \
	PKG_CONFIG_SYSROOT_DIR=$(BUILDROOT_OUTPUT_STAGING_PATH) \
	PKG_CONFIG_LIBDIR=$(BUILDROOT_OUTPUT_STAGING_PATH)/usr/lib/pkgconfig:$(BUILDROOT_OUTPUT_STAGING_PATH)/usr/share/pkgconfig

GST_RTSP_SERVER_PKGS = gstreamer-rtsp-server-1.0 gstreamer-app-1.0 gstreamer-video-1.0 gio-2.0
GST_RTSP_SERVER_CFLAGS := $(shell $(PKG_CONFIG_ENV) $(PKG_CONFIG) --cflags $(GST_RTSP_SERVER_PKGS))
GST_RTSP_SERVER_PKG_LDLIBS := $(shell $(PKG_CONFIG_ENV) $(PKG_CONFIG) --libs $(GST_RTSP_SERVER_PKGS))
GST_RTSP_SERVER_LDLIBS := $(patsubst -L$(BUILDROOT_OUTPUT_STAGING_PATH)/usr/lib,-L$(BUILDROOT_TARGET_LIB),$(GST_RTSP_SERVER_PKG_LDLIBS))


BIN := agtx-rtsp-server
OBJ := $(BIN).o

TARGETS = $(BIN) 
DEST = $(SYSTEM_BIN)
INSTALL_TRGTS := $(addprefix $(DEST)/, $(TARGETS))


INC:=-I"$(INC_PATH)"
INC+=-Iquote"$(SRC_INC_PATH)"
INC+=-I$(MPP_INC)
INC+=-I$(AUDIO_INC)
INC+=-I$(ALSA_INC)
INC+=-I$(APP_INC)
INC+=$(GST_RTSP_SERVER_CFLAGS)
ifeq ($(APP_GST_RTSP_SERVER_ENABLE_IVA),y)
INC += -I$(LIBAVFTR_INC) -I$(LIBEAIF_INC) $(addprefix -I, $(FEATURE_INC_PATHS))
INC += -I$(FEATURE_AUDIO_INC_PATH) -I$(FEATURE_VIDEO_INC_PATH)
endif

# CFLAGS 
# CFLAGS := -Wall -g -D_GNU_SOURCE -O2 -fno-omit-frame-pointer -std=gnu99 -MMD -MP -Wno-unused-variable -Wno-unused-function
CFLAGS += $(INC)
CFLAGS += $(COMPILE_OPTS) $(CFLAGS_COMMON) -Wl,--gc-sections -Wl,-unresolved-symbols=ignore-in-shared-libs
ifeq ($(APP_GST_RTSP_SERVER_ENABLE_IVA),y)
CFLAGS += -DGST_RTSP_SERVER_ENABLE_IVA
endif

# # library paths
LDFLAGS := -L$(GST1_RTSP_SERVER_LIB)/build/gst/rtsp-server
ifeq ($(APP_GST_RTSP_SERVER_ENABLE_IVA),y)
LDFLAGS += -L$(LIBAVFTR_LIB) -L$(LIBEAIF_LIB) -L$(NCNN_COMPACT_LIB) -L$(FEATURE_AUDIO_LIB_PATH) -L$(FEATURE_VIDEO_LIB_PATH) -L$(TFLITE_LIB)
LDFLAGS += -L$(LIBADO_LIB) -L$(LIBINF_LIB)
endif
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/app
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/rtsp
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/sdp
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/rtp
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/video
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/pbutils
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/audio
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/fft
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/gl
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/riff
LDFLAGS += -L$(GST1_PLUGINS_BASE_LIB)/build/gst-libs/gst/tag
LDFLAGS += -L$(GSTREAMER1_LIB)/build/libs/gst/base
LDFLAGS += -L$(GSTREAMER1_LIB)/build/libs/gst/net
LDFLAGS += -L$(GSTREAMER1_LIB)/build/gst/
LDFLAGS += -L$(LIBGLIB2_LIB)
LDFLAGS += -L$(LIBGLIB2_GIO_LIB)
LDFLAGS += -L$(LIBGLIB2_GOBJECT_LIB)
LDFLAGS += -L$(LIBGLIB2_GMODULE_LIB)
LDFLAGS += -L$(LIBFFI_LIB)
LDFLAGS += -L$(LIBPCRE_LIB)
LDFLAGS += -L$(MPP_LIB)
LDFLAGS += -L$(APP_LIB)
LDFLAGS += -L$(ALSA_LIB)
LDFLAGS += -L$(FDKAAC_LIB)
LDFLAGS += -L$(JSON_LIB)
LDFLAGS += -L$(LIBEV_LIB)
LDFLAGS += -L$(OPENSSL_LIB)
LDFLAGS += -L$(ZLIB_LIB)

ifeq ($(APP_GST_RTSP_SERVER_ENABLE_IVA),y)
LDLIBS += -l:libavftr.a
LDLIBS += -l:libaftr.a -l:libvftr.a
# LDLIBS += -l:libeaif.a -l:libinf.a -ltensorflow-lite -l:libncnn-compact.a
LDLIBS += -lado
endif
LDLIBS += $(GST_RTSP_SERVER_LDLIBS)
LDLIBS += -lgstrtspserver-1.0
LDLIBS += -lgstrtsp-1.0
LDLIBS += -lgstsdp-1.0
LDLIBS += -lgstrtp-1.0
LDLIBS += -lgstbase-1.0
LDLIBS += -lgstnet-1.0
LDLIBS += -lgstreamer-1.0
LDLIBS += -lglib-2.0
LDLIBS += -lgio-2.0
LDLIBS += -lgobject-2.0
LDLIBS += -lgstapp-1.0
LDLIBS += -lgmodule-2.0
LDLIBS += -lpcre
LDLIBS += -lz
LDLIBS += -lffi
LDLIBS += -lmpp
LDLIBS += -lasound
LDLIBS += -lgstvideo-1.0

.PHONY: all
all: $(BIN)

$(BIN): $(OBJ)
	$(Q)$(CXX) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

%.o: %.c
	$(Q)$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.cc
	$(Q)$(CXX) -c $(CFLAGS) -o $@ $<

.PHONY: install
install: all $(DEST) $(INSTALL_TRGTS)

$(DEST):
	$(Q)install -d $@

$(DEST)/%: %
	$(Q)install -m 777 $< $@

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(INSTALL_TRGTS)

.PHONY: clean
clean:
	$(Q)rm -f *.o *.d $(BIN)

.PHONY: distclean
distclean: uninstall clean
