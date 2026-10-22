mod := $(notdir $(subdir))

sample-demo-$(CONFIG_LIBCM) += libcm
PHONY += libcm libcm-clean libcm-distclean
PHONY += libcm-install libcm-uninstall
libcm:
	$(Q)$(MAKE) -C $(LIBCM_PATH) all

libcm-clean:
	$(Q)$(MAKE) -C $(LIBCM_PATH) clean

libcm-distclean:
	$(Q)$(MAKE) -C $(LIBCM_PATH) distclean

libcm-install:
	$(Q)$(MAKE) -C $(LIBCM_PATH) install

libcm-uninstall:
	$(Q)$(MAKE) -C $(LIBCM_PATH) uninstall

sample-demo-$(CONFIG_LIBAGTX) += libagtx
PHONY += libagtx libagtx-clean libagtx-distclean
PHONY += libagtx-install libagtx-uninstall
libagtx:
	$(Q)$(MAKE) -C $(LIBAGTX_PATH)/build all

libagtx-clean:
	$(Q)$(MAKE) -C $(LIBAGTX_PATH)/build clean

libagtx-distclean:
	$(Q)$(MAKE) -C $(LIBAGTX_PATH)/build distclean

libagtx-install:
	$(Q)$(MAKE) -C $(LIBAGTX_PATH)/build install

libagtx-uninstall:
	$(Q)$(MAKE) -C $(LIBAGTX_PATH)/build uninstall

PHONY += libsample libsample-clean libsample-distclean
PHONY += libsample-install libsample-uninstall
sample-demo-$(CONFIG_LIBSAMPLE) += libsample
libsample: libcm libfsink
	$(Q)$(MAKE) -C $(LIBSAMPLE_PATH)/build all

libsample-clean: libcm-clean libfsink-clean
	$(Q)$(MAKE) -C $(LIBSAMPLE_PATH)/build clean

libsample-distclean: libcm-distclean libfsink-distclean
	$(Q)$(MAKE) -C $(LIBSAMPLE_PATH)/build distclean

libsample-install: libcm-install libfsink-install
	$(Q)$(MAKE) -C $(LIBSAMPLE_PATH)/build install

libsample-uninstall: libcm-uninstall libfsink-uninstall
	$(Q)$(MAKE) -C $(LIBSAMPLE_PATH)/build uninstall

sample-demo-$(CONFIG_LIBAVFTR) += libavftr
PHONY += libavftr libavftr-clean libavftr-distclean
PHONY += libavftr-install libavftr-uninstall
libavftr: libeaif
	$(MAKE) -C $(LIBAVFTR_BUILD_PATH) all

libavftr-clean: libeaif-clean
	$(MAKE) -C $(LIBAVFTR_BUILD_PATH) clean

libavftr-distclean: libeaif-distclean
	$(MAKE) -C $(LIBAVFTR_BUILD_PATH) distclean

libavftr-install: libeaif-install
	$(MAKE) -C $(LIBAVFTR_BUILD_PATH) install

libavftr-uninstall: libeaif-uninstall
	$(MAKE) -C $(LIBAVFTR_BUILD_PATH) uninstall


sample-demo-$(CONFIG_LIBOSD) += libosd
PHONY += libosd libosd-clean libosd-distclean
PHONY += libosd-install libosd-uninstall
libosd:
	$(Q)$(MAKE) -C $(LIBOSD_PATH)/build all

libosd-clean:
	$(Q)$(MAKE) -C $(LIBOSD_PATH)/build clean

libosd-distclean:
	$(Q)$(MAKE) -C $(LIBOSD_PATH)/build distclean

libosd-install:
	$(Q)$(MAKE) -C $(LIBOSD_PATH)/build install

libosd-uninstall:
	$(Q)$(MAKE) -C $(LIBOSD_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_CMD_SENDER) += cmd_sender
PHONY += cmd_sender cmd_sender-clean cmd_sender-distclean
PHONY += cmd_sender-install cmd_sender-uninstall
cmd_sender:
	$(Q)$(MAKE) -C $(CMD_SENDER_PATH) all

cmd_sender-clean:
	$(Q)$(MAKE) -C $(CMD_SENDER_PATH) clean

cmd_sender-distclean:
	$(Q)$(MAKE) -C $(CMD_SENDER_PATH) distclean

cmd_sender-install:
	$(Q)$(MAKE) -C $(CMD_SENDER_PATH) install

cmd_sender-uninstall:
	$(Q)$(MAKE) -C $(CMD_SENDER_PATH) uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_MPI_SNAPSHOT) += mpi_snapshot
PHONY += mpi_snapshot mpi_snapshot-clean mpi_snapshot-distclean
PHONY += mpi_snapshot-install mpi_snapshot-uninstall
mpi_snapshot:
	$(Q)$(MAKE) -C $(MPI_SNAPSHOT_PATH) all

mpi_snapshot-clean:
	$(Q)$(MAKE) -C $(MPI_SNAPSHOT_PATH) clean

mpi_snapshot-distclean:
	$(Q)$(MAKE) -C $(MPI_SNAPSHOT_PATH) distclean

mpi_snapshot-install:
	$(Q)$(MAKE) -C $(MPI_SNAPSHOT_PATH) install

mpi_snapshot-uninstall:
	$(Q)$(MAKE) -C $(MPI_SNAPSHOT_PATH) uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_MP4_MUXER) += mp4_muxer
PHONY += mp4_muxer mp4_muxer-clean mp4_muxer-distclean
PHONY += mp4_muxer-install mp4_muxer-uninstall
mp4_muxer:
	$(Q)$(MAKE) -C $(MP4_MUXER_PATH)/build all

mp4_muxer-clean:
	$(Q)$(MAKE) -C $(MP4_MUXER_PATH)/build clean

mp4_muxer-distclean:
	$(Q)$(MAKE) -C $(MP4_MUXER_PATH)/build distclean

mp4_muxer-install:
	$(Q)$(MAKE) -C $(MP4_MUXER_PATH)/build install

mp4_muxer-uninstall:
	$(Q)$(MAKE) -C $(MP4_MUXER_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_MPI_STREAM) += mpi_stream
PHONY += mpi_stream mpi_stream-clean mpi_stream-distclean
PHONY += mpi_stream-install mpi_stream-uninstall
mpi_stream: libsample libfsink
	$(Q)$(MAKE) -C $(MPI_STREAM_PATH)/build all

mpi_stream-clean: libsample-clean libfsink-clean
	$(Q)$(MAKE) -C $(MPI_STREAM_PATH)/build clean

mpi_stream-distclean: libsample-distclean libfsink-distclean
	$(Q)$(MAKE) -C $(MPI_STREAM_PATH)/build distclean

mpi_stream-install: libsample-install libfsink-install
	$(Q)$(MAKE) -C $(MPI_STREAM_PATH)/build install

mpi_stream-uninstall: libsample-uninstall libfsink-uninstall
	$(Q)$(MAKE) -C $(MPI_STREAM_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_OSD_DEMO) += osd_demo
PHONY += osd_demo osd_demo-clean osd_demo-distclean
PHONY += osd_demo-install osd_demo-uninstall
osd_demo: libosd
	$(Q)$(MAKE) -C $(OSD_DEMO_PATH)/build all

osd_demo-clean: libosd-clean
	$(Q)$(MAKE) -C $(OSD_DEMO_PATH)/build clean

osd_demo-distclean: libosd-distclean
	$(Q)$(MAKE) -C $(OSD_DEMO_PATH)/build distclean

osd_demo-install: libosd-install
	$(Q)$(MAKE) -C $(OSD_DEMO_PATH)/build install

osd_demo-uninstall: libosd-uninstall
	$(Q)$(MAKE) -C $(OSD_DEMO_PATH)/build uninstall


sample-demo-$(CONFIG_SAMPLE_DEMO_UNICORN) += unicorn
PHONY += unicorn unicorn-clean unicorn-distclean
PHONY += unicorn-install unicorn-uninstall
unicorn:
	$(Q)$(MAKE) -C $(UNICORN_PATH)/build all

unicorn-clean:
	$(Q)$(MAKE) -C $(UNICORN_PATH)/build clean

unicorn-distclean:
	$(Q)$(MAKE) -C $(UNICORN_PATH)/build distclean

unicorn-install:
	$(Q)$(MAKE) -C $(UNICORN_PATH)/build install

unicorn-uninstall:
	$(Q)$(MAKE) -C $(UNICORN_PATH)/build uninstall

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
