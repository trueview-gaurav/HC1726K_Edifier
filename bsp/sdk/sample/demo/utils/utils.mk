mod := $(notdir $(subdir))

sample-demo-$(CONFIG_LIBLPW) += liblpw
PHONY += liblpw liblpw-clean liblpw-distclean
PHONY += liblpw-install liblpw-uninstall
liblpw:
	$(MAKE) -C $(LIBLPW_BUILD_PATH) all

liblpw-clean:
	$(MAKE) -C $(LIBLPW_BUILD_PATH) clean

liblpw-distclean:
	$(MAKE) -C $(LIBLPW_BUILD_PATH) distclean

liblpw-install:
	$(MAKE) -C $(LIBLPW_BUILD_PATH) install

liblpw-uninstall:
	$(MAKE) -C $(LIBLPW_BUILD_PATH) uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_LPW) += lpw
PHONY += lpw lpw-clean lpw-distclean
PHONY += lpw-install lpw-uninstall
lpw lpw-clean lpw-distclean lpw-install lpw-uninstall:
	$(error LPW Controller feature is not supported. Please ask FAE for help.)

sample-demo-$(CONFIG_SAMPLE_DEMO_LPW_SUPP) += lpw_supp
PHONY += lpw_supp lpw_supp-clean lpw_supp-distclean
PHONY += lpw_supp-install lpw_supp-uninstall
lpw_supp:
	$(Q)$(MAKE) -C $(LPW_SUPP_PATH)/build all

lpw_supp-clean:
	$(Q)$(MAKE) -C $(LPW_SUPP_PATH)/build clean

lpw_supp-distclean:
	$(Q)$(MAKE) -C $(LPW_SUPP_PATH)/build distclean

lpw_supp-install:
	$(Q)$(MAKE) -C $(LPW_SUPP_PATH)/build install

lpw_supp-uninstall:
	$(Q)$(MAKE) -C $(LPW_SUPP_PATH)/build uninstall


sample-demo-$(CONFIG_SAMPLE_DEMO_HIBER_DEMO) += hiber_demo
PHONY += hiber_demo hiber_demo-clean hiber_demo-distclean
PHONY += hiber_demo-install hiber_demo-uninstall
hiber_demo:
	$(Q)$(MAKE) -C $(HIBER_DEMO_PATH)/build all

hiber_demo-clean:
	$(Q)$(MAKE) -C $(HIBER_DEMO_PATH)/build clean

hiber_demo-distclean:
	$(Q)$(MAKE) -C $(HIBER_DEMO_PATH)/build distclean

hiber_demo-install:
	$(Q)$(MAKE) -C $(HIBER_DEMO_PATH)/build install

hiber_demo-uninstall:
	$(Q)$(MAKE) -C $(HIBER_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_LPW_FW_UPG) += lpw_fw_upg
PHONY += lpw_fw_upg lpw_fw_upg-clean lpw_fw_upg-distclean
PHONY += lpw_fw_upg-install lpw_fw_upg-uninstall
lpw_fw_upg:
	$(Q)$(MAKE) -C $(LPW_FW_UPG_PATH)/build all

lpw_fw_upg-clean:
	$(Q)$(MAKE) -C $(LPW_FW_UPG_PATH)/build clean

lpw_fw_upg-distclean:
	$(Q)$(MAKE) -C $(LPW_FW_UPG_PATH)/build distclean

lpw_fw_upg-install:
	$(Q)$(MAKE) -C $(LPW_FW_UPG_PATH)/build install

lpw_fw_upg-uninstall:
	$(Q)$(MAKE) -C $(LPW_FW_UPG_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_LPWIO) += lpwio
PHONY += lpwio lpwio-clean lpwio-distclean
PHONY += lpwio-install lpwio-uninstall
lpwio:
	$(Q)$(MAKE) -C $(LPWIO_PATH)/build all

lpwio-clean:
	$(Q)$(MAKE) -C $(LPWIO_PATH)/build clean

lpwio-distclean:
	$(Q)$(MAKE) -C $(LPWIO_PATH)/build distclean

lpwio-install:
	$(Q)$(MAKE) -C $(LPWIO_PATH)/build install

lpwio-uninstall:
	$(Q)$(MAKE) -C $(LPWIO_PATH)/build uninstall


sample-demo-$(CONFIG_SAMPLE_DEMO_MPI_SCRIPT) += mpi_script
PHONY += mpi_script mpi_script-clean mpi_script-distclean
PHONY += mpi_script-install mpi_script-uninstall
mpi_script:
	$(Q)$(MAKE) -C $(MPI_SCRIPT_PATH) all

mpi_script-clean:
	$(Q)$(MAKE) -C $(MPI_SCRIPT_PATH) clean

mpi_script-distclean:
	$(Q)$(MAKE) -C $(MPI_SCRIPT_PATH) distclean

mpi_script-install:
	$(Q)$(MAKE) -C $(MPI_SCRIPT_PATH) install

mpi_script-uninstall:
	$(Q)$(MAKE) -C $(MPI_SCRIPT_PATH) uninstall

sample-demo-$(CONFIG_LIBFSINK) += libfsink
PHONY += libfsink libfsink-clean libfsink-distclean
PHONY += libfsink-install libfsink-uninstall
libfsink:
	$(Q)$(MAKE) -C $(FILE_PATH) all
	$(Q)$(MAKE) -C $(UDPS_PATH) all

libfsink-clean:
	$(Q)$(MAKE) -C $(UDPS_PATH) clean
	$(Q)$(MAKE) -C $(FILE_PATH) clean

libfsink-distclean:
	$(Q)$(MAKE) -C $(UDPS_PATH) distclean
	$(Q)$(MAKE) -C $(FILE_PATH) distclean

libfsink-install:
	$(Q)$(MAKE) -C $(FILE_PATH) install
	$(Q)$(MAKE) -C $(UDPS_PATH) install

libfsink-uninstall:
	$(Q)$(MAKE) -C $(UDPS_PATH) uninstall
	$(Q)$(MAKE) -C $(FILE_PATH) uninstall


sample-demo-$(CONFIG_LIBMETAL) += libmetal
PHONY += libmetal libmetal-clean libmetal-distclean
PHONY += libmetal-install libmetal-uninstall
libmetal:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) all

libmetal-clean:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) clean

libmetal-distclean:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) distclean

libmetal-install:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) install

libmetal-uninstall:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) uninstall

PHONY += libmotor libmotor-clean libmotor-distclean
PHONY += libmotor-install libmotor-uninstall
sample-demo-$(CONFIG_LIBMOTOR) += libmotor
libmotor: libsample
	$(Q)$(MAKE) -C $(LIBMOTOR_PATH)/build all

libmotor-clean: libsample-clean
	$(Q)$(MAKE) -C $(LIBMOTOR_PATH)/build clean

libmotor-distclean: libsample-distclean
	$(Q)$(MAKE) -C $(LIBMOTOR_PATH)/build distclean

libmotor-install: libsample-install
	$(Q)$(MAKE) -C $(LIBMOTOR_PATH)/build install

libmotor-uninstall: libsample-uninstall
	$(Q)$(MAKE) -C $(LIBMOTOR_PATH)/build uninstall


sample-demo-$(CONFIG_FOO) += libfoo
PHONY += libfoo libfoo-clean libfoo-distclean
PHONY += libfoo-install libfoo-uninstall
libfoo:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build all

libfoo-clean:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build clean

libfoo-distclean:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build distclean

libfoo-install:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build install

libfoo-uninstall:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build uninstall


PHONY += $(mod) $(mod)-clean $(mod)-distclean
PHONY += $(mod)-install $(mod)-uninstall
$(mod): $(sample-demo-y)
$(mod)-clean: $(addsuffix -clean,$(sample-demo-y))
$(mod)-distclean: $(addsuffix -distclean,$(sample-demo-y))
$(mod)-install: $(addsuffix -install,$(sample-demo-y))
$(mod)-uninstall: $(addsuffix -uninstall,$(sample-demo-y))

SAMPLE_DEMO_BUILD_DEPS += $(mod)
SAMPLE_DEMO_CLEAN_DEPS += $(mod)-clean
SAMPLE_DEMO_DISTCLEAN_DEPS += $(mod)-distclean
SAMPLE_DEMO_INTALL_DEPS += $(mod)-install
SAMPLE_DEMO_UNINTALL_DEPS += $(mod)-uninstall
