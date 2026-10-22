mod := $(notdir $(subdir))

app-$(CONFIG_APP_AIC8800_M40) += aic8800_m40
PHONY += aic8800_m40 aic8800_m40-clean aic8800_m40-distclean
PHONY += aic8800_m40-install aic8800_m40-uninstall
aic8800_m40:
	$(Q)$(MAKE) -C $(AIC8800M40_PATH) all

aic8800_m40-clean:
	$(Q)$(MAKE) -C $(AIC8800M40_PATH) clean

aic8800_m40-distclean:
	$(Q)$(MAKE) -C $(AIC8800M40_PATH) distclean

aic8800_m40-install:
	$(Q)$(MAKE) -C $(AIC8800M40_PATH) install

aic8800_m40-uninstall:
	$(Q)$(MAKE) -C $(AIC8800M40_PATH) uninstall

app-$(CONFIG_APP_CONNSEL) += connsel
PHONY += connsel connsel-clean connsel-distclean
PHONY += connsel-install connsel-uninstall
connsel:
	$(Q)$(MAKE) -C $(CONNSEL_PATH) all

connsel-clean:
	$(Q)$(MAKE) -C $(CONNSEL_PATH) clean

connsel-distclean:
	$(Q)$(MAKE) -C $(CONNSEL_PATH) distclean

connsel-install:
	$(Q)$(MAKE) -C $(CONNSEL_PATH) install

connsel-uninstall:
	$(Q)$(MAKE) -C $(CONNSEL_PATH) uninstall

app-$(CONFIG_APP_EAIF_SERVER) += eaif_server
PHONY += eaif_server eaif_server-clean eaif_server-distclean
PHONY += eaif_server-install eaif_server-uninstall
eaif_server:
	$(Q)$(MAKE) -C $(EAIF_SERV_BUILD_PATH) all

eaif_server-clean:
	$(Q)$(MAKE) -C $(EAIF_SERV_BUILD_PATH) clean

eaif_server-distclean:
	$(Q)$(MAKE) -C $(EAIF_SERV_BUILD_PATH) distclean

eaif_server-install:
	$(Q)$(MAKE) -C $(EAIF_SERV_BUILD_PATH) install

eaif_server-uninstall:
	$(Q)$(MAKE) -C $(EAIF_SERV_BUILD_PATH) uninstall

app-$(CONFIG_APP_IP_ASSIGN) += ip_assign
PHONY += ip_assign ip_assign-clean ip_assign-distclean
PHONY += ip_assign-install ip_assign-uninstall
ip_assign:
	$(Q)$(MAKE) -C $(IPASSIGN_PATH) all

ip_assign-clean:
	$(Q)$(MAKE) -C $(IPASSIGN_PATH) clean

ip_assign-distclean:
	$(Q)$(MAKE) -C $(IPASSIGN_PATH) distclean

ip_assign-install:
	$(Q)$(MAKE) -C $(IPASSIGN_PATH) install

ip_assign-uninstall:
	$(Q)$(MAKE) -C $(IPASSIGN_PATH) uninstall

app-$(CONFIG_APP_STAMEN) += stamen
PHONY += stamen stamen-clean stamen-distclean
PHONY += stamen-install stamen-uninstall
stamen:
	$(Q)$(MAKE) -C $(STAMEN_PATH)/build all

stamen-clean:
	$(Q)$(MAKE) -C $(STAMEN_PATH)/build clean

stamen-distclean:
	$(Q)$(MAKE) -C $(STAMEN_PATH)/build distclean

stamen-install:
	$(Q)$(MAKE) -C $(STAMEN_PATH)/build install

stamen-uninstall:
	$(Q)$(MAKE) -C $(STAMEN_PATH)/build uninstall

app-$(CONFIG_APP_SE_AUTH) += se_auth
PHONY += se_auth se_auth-clean se_auth-distclean
PHONY += se_auth-install se_auth-uninstall
se_auth:
	$(Q)$(MAKE) -C $(SE_AUTH_PATH) all

se_auth-clean:
	$(Q)$(MAKE) -C $(SE_AUTH_PATH) clean

se_auth-distclean:
	$(Q)$(MAKE) -C $(SE_AUTH_PATH) distclean

se_auth-install:
	$(Q)$(MAKE) -C $(SE_AUTH_PATH) install

se_auth-uninstall:
	$(Q)$(MAKE) -C $(SE_AUTH_PATH) uninstall

app-$(CONFIG_APP_TEE_AUTH) += tee_auth
PHONY += tee_auth tee_auth-clean tee_auth-distclean
PHONY += tee_auth-install tee_auth-uninstall
tee_auth:
	$(Q)$(MAKE) -C $(TEE_AUTH_PATH) all

tee_auth-clean:
	$(Q)$(MAKE) -C $(TEE_AUTH_PATH) clean

tee_auth-distclean:
	$(Q)$(MAKE) -C $(TEE_AUTH_PATH) distclean

tee_auth-install:
	$(Q)$(MAKE) -C $(TEE_AUTH_PATH) install

tee_auth-uninstall:
	$(Q)$(MAKE) -C $(TEE_AUTH_PATH) uninstall

app-$(CONFIG_APP_WIFI) += wifi
PHONY += wifi wifi-clean wifi-distclean
PHONY += wifi-install wifi-uninstall
wifi:
	$(Q)$(MAKE) -C $(WIFI_PATH) all

wifi-clean:
	$(Q)$(MAKE) -C $(WIFI_PATH) clean

wifi-distclean:
	$(Q)$(MAKE) -C $(WIFI_PATH) distclean

wifi-install:
	$(Q)$(MAKE) -C $(WIFI_PATH) install

wifi-uninstall:
	$(Q)$(MAKE) -C $(WIFI_PATH) uninstall

####################

app-$(CONFIG_APP_FLV_SERVER) += flv_server
PHONY += flv_server flv_server-clean flv_server-distclean
PHONY += flv_server-install flv_server-uninstall
flv_server:
	$(Q)$(MAKE) -C $(FLV_PATH)/build all

flv_server-clean:
	$(Q)$(MAKE) -C $(FLV_PATH)/build clean

flv_server-distclean:
	$(Q)$(MAKE) -C $(FLV_PATH)/build distclean

flv_server-install:
	$(Q)$(MAKE) -C $(FLV_PATH)/build install

flv_server-uninstall:
	$(Q)$(MAKE) -C $(FLV_PATH)/build uninstall

app-$(CONFIG_APP_MP4_RECORDER) += mp4_recorder
PHONY += mp4_recorder mp4_recorder-clean mp4_recorder-distclean
PHONY += mp4_recorder-install mp4_recorder-uninstall
mp4_recorder:
	$(Q)$(MAKE) -C $(MP4_RECORDER_PATH)/build all

mp4_recorder-clean:
	$(Q)$(MAKE) -C $(MP4_RECORDER_PATH)/build clean

mp4_recorder-distclean:
	$(Q)$(MAKE) -C $(MP4_RECORDER_PATH)/build distclean

mp4_recorder-install:
	$(Q)$(MAKE) -C $(MP4_RECORDER_PATH)/build install

mp4_recorder-uninstall:
	$(Q)$(MAKE) -C $(MP4_RECORDER_PATH)/build uninstall

app-$(CONFIG_APP_EXIF_SNAPSHOT) += exif_snapshot
PHONY += exif_snapshot exif_snapshot-clean exif_snapshot-distclean
PHONY += exif_snapshot-install exif_snapshot-uninstall
exif_snapshot:
	$(Q)$(MAKE) -C $(EXIF_SNAPSHOT_PATH) all

exif_snapshot-clean:
	$(Q)$(MAKE) -C $(EXIF_SNAPSHOT_PATH) clean

exif_snapshot-distclean:
	$(Q)$(MAKE) -C $(EXIF_SNAPSHOT_PATH) distclean

exif_snapshot-install:
	$(Q)$(MAKE) -C $(EXIF_SNAPSHOT_PATH) install

exif_snapshot-uninstall:
	$(Q)$(MAKE) -C $(EXIF_SNAPSHOT_PATH) uninstall

app-$(CONFIG_APP_GST_RTSP_SERVER) += gst_rtsp_server
PHONY += gst_rtsp_server gst_rtsp_server-clean gst_rtsp_server-distclean
PHONY += gst_rtsp_server-install gst_rtsp_server-uninstall
gst_rtsp_server:
	$(Q)$(MAKE) -C $(GST_RTSP_SERVER_PATH) all
	
gst_rtsp_server-clean:
	$(Q)$(MAKE) -C $(GST_RTSP_SERVER_PATH) clean

gst_rtsp_server-distclean:
	$(Q)$(MAKE) -C $(GST_RTSP_SERVER_PATH) distclean

gst_rtsp_server-install:
	$(Q)$(MAKE) -C $(GST_RTSP_SERVER_PATH) install

gst_rtsp_server-uninstall:
	$(Q)$(MAKE) -C $(GST_RTSP_SERVER_PATH) uninstall

PHONY += $(mod) $(mod)-clean $(mod)-distclean
PHONY += $(mod)-install $(mod)-uninstall
$(mod): $(app-y)
$(mod)-clean: $(addsuffix -clean,$(app-y))
$(mod)-distclean: $(addsuffix -distclean,$(app-y))
$(mod)-install: $(addsuffix -install,$(app-y))
$(mod)-uninstall: $(addsuffix -uninstall,$(app-y))

APP_BUILD_DEPS += $(mod)
APP_CLEAN_DEPS += $(mod)-clean
APP_DISTCLEAN_DEPS += $(mod)-distclean
APP_INTALL_DEPS += $(mod)-install
APP_UNINTALL_DEPS += $(mod)-uninstall
