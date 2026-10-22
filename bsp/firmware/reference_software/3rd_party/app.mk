mod := $(notdir $(subdir))

# 3rd-party paths
TUYA_SERVICE_PATH := $(APP_PATH)/3rd_party/tuya_service
TUYA_IPC_SDK_DIR := $(CONFIG_APP_TUYA_IPC_SDK_PATH)
export TUYA_IPC_SDK_DIR

app-$(CONFIG_APP_TUYA_SERVICE) += tuya_service
PHONY += tuya_service tuya_service-clean tuya_service-distclean
PHONY += tuya_service-install tuya_service-uninstall
tuya_service:
	$(Q)$(MAKE) -C $(EVENTD_PATH)/libledevt all
	$(Q)$(MAKE) -C $(TUYA_SERVICE_PATH) all

tuya_service-clean:
	$(Q)$(MAKE) -C $(TUYA_SERVICE_PATH) clean
	$(Q)$(MAKE) -C $(EVENTD_PATH)/libledevt clean

tuya_service-distclean:
	$(Q)$(MAKE) -C $(TUYA_SERVICE_PATH) distclean
	$(Q)$(MAKE) -C $(EVENTD_PATH)/libledevt distclean

tuya_service-install:
	$(Q)$(MAKE) -C $(TUYA_SERVICE_PATH) install

tuya_service-uninstall:
	$(Q)$(MAKE) -C $(TUYA_SERVICE_PATH) uninstall

TUTK_SERVICE_PATH := $(APP_PATH)/3rd_party/tutk_service
TUTK_SDK_DIR := $(CONFIG_APP_TUTK_SDK_PATH)
export TUTK_SDK_DIR

app-$(CONFIG_APP_TUTK_SERVICE) += tutk_service
PHONY += tutk_service tutk_service-clean tutk_service-distclean
PHONY += tutk_service-install tutk_service-uninstall
tutk_service:
	$(Q)$(MAKE) -C $(TUTK_SERVICE_PATH)/build all

tutk_service-clean:
	$(Q)$(MAKE) -C $(TUTK_SERVICE_PATH)/build clean

tutk_service-distclean:
	$(Q)$(MAKE) -C $(TUTK_SERVICE_PATH)/build distclean

tutk_service-install:
	$(Q)$(MAKE) -C $(TUTK_SERVICE_PATH)/build install

tutk_service-uninstall:
	$(Q)$(MAKE) -C $(TUTK_SERVICE_PATH)/build uninstall


TANGE_CLOUD_PATH := $(APP_PATH)/3rd_party/tange_cloud

app-$(CONFIG_APP_TANGE_CLOUD) += tange_cloud
PHONY += tange_cloud tange_cloud-clean tange_cloud-distclean
PHONY += tange_cloud-install tange_cloud-uninstall
tange_cloud:
	$(Q)$(MAKE) -C $(TANGE_CLOUD_PATH)/build all

tange_cloud-clean:
	$(Q)$(MAKE) -C $(TANGE_CLOUD_PATH)/build clean

tange_cloud-distclean:
	$(Q)$(MAKE) -C $(TANGE_CLOUD_PATH)/build distclean

tange_cloud-install:
	$(Q)$(MAKE) -C $(TANGE_CLOUD_PATH)/build install

tange_cloud-uninstall:
	$(Q)$(MAKE) -C $(TANGE_CLOUD_PATH)/build uninstall

AMAZON_KVS_PATH := $(APP_PATH)/3rd_party/amazon_kvs

app-$(CONFIG_APP_AMAZON_KVS) += amazon_kvs
PHONY += amazon_kvs amazon_kvs-clean amazon_kvs-distclean
PHONY += amazon_kvs-install amazon_kvs-uninstall
amazon_kvs:
	$(Q)$(MAKE) -C $(AMAZON_KVS_PATH) all

amazon_kvs-clean:
	$(Q)$(MAKE) -C $(AMAZON_KVS_PATH) clean

amazon_kvs-distclean:
	$(Q)$(MAKE) -C $(AMAZON_KVS_PATH) distclean

amazon_kvs-install:
	$(Q)$(MAKE) -C $(AMAZON_KVS_PATH) install

amazon_kvs-uninstall:
	$(Q)$(MAKE) -C $(AMAZON_KVS_PATH) uninstall

SE_TRNG_PATH := $(APP_PATH)/3rd_party/se_trng/build

app-$(CONFIG_APP_SE_TRNG_PROVIDER) += se_trng
PHONY += se_trng se_trng-clean se_trng-distclean
PHONY += se_trng-install se_trng-uninstall
se_trng:
	$(Q)$(MAKE) -C $(SE_TRNG_PATH) all

se_trng-clean:
	$(Q)$(MAKE) -C $(SE_TRNG_PATH) clean

se_trng-distclean:
	$(Q)$(MAKE) -C $(SE_TRNG_PATH) distclean

se_trng-install:
	$(Q)$(MAKE) -C $(SE_TRNG_PATH) install

se_trng-uninstall:
	$(Q)$(MAKE) -C $(SE_TRNG_PATH) uninstall

app-$(CONFIG_APP_SECURE_ELEMENT) += secure_element
PHONY += secure_element secure_element_clean secure_element-distclean
PHONY += secure_element-install secure_element-uninstall
secure_element:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_PATH)/build all

secure_element-clean:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_PATH)/build clean

secure_element-distclean:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_PATH)/build distclean

secure_element-install:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_PATH)/build install

secure_element-uninstall:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_PATH)/build uninstall

app-$(CONFIG_APP_SECURE_ELEMENT_DEMO) += secure_element_demo
PHONY += secure_element_demo secure_element_demo-clean secure_element_demo-distclean
PHONY += secure_element_demo-install secure_element_demo-uninstall
secure_element_demo:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_DEMO_PATH)/build all

secure_element_demo-clean:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_DEMO_PATH)/build clean

secure_element_demo-distclean:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_DEMO_PATH)/build distclean

secure_element_demo-install:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_DEMO_PATH)/build install

secure_element_demo-uninstall:
	$(Q)$(MAKE) -C $(SECURE_ELEMENT_DEMO_PATH)/build uninstall

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
