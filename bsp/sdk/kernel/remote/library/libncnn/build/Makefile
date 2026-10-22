SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

# utils
MAKE := make
CP := cp
LN := ln
MKDIR := mkdir
MKDIR_P := $(MKDIR) -p
MV := mv
RM := rm -f

.PHONY: default
default: all


.PHONY: rtos-build
rtos-build:
ifeq ("$(wildcard ./freertos/Makefile)","")
	cmake -B ./freertos -DCMAKE_CXX_FLAGS="-w" -DCMAKE_C_FLAGS="-w" -DCMAKE_BUILD_TYPE=Release -DNCNN_VERSION=0 -DNCNN_OPENMP=OFF -DNCNN_BUILD_EXAMPLES=OFF -DNCNN_SIMPLEOCV=OFF -DNCNN_SIMPLESTL=ON -DNCNN_SIMPLEMATH=ON -DNCNN_STDIO=OFF -DNCNN_STRING=OFF -DNCNN_C_API=OFF -DNCNN_PLATFORM_API=OFF -DNCNN_SHARED_LIB=OFF -DNCNN_VULKAN=OFF -DNCNN_RUNTIME_CPU=OFF -DNCNN_THREADS=OFF -DNCNN_BF16=OFF -DNCNN_INT8=ON -DNCNN_AVX2=OFF -DNCNN_ARM82=OFF -DNCNN_PIXEL=OFF -DNCNN_PIXEL_ROTATE=OFF -DNCNN_PIXEL_AFFINE=OFF -DNCNN_BUILD_BENCHMARK=OFF -DNCNN_BUILD_TESTS=OFF -DNCNN_BUILD_TOOLS=OFF -DNCNN_PIXEL_DRAWING=OFF -DNCNN_DISABLE_RTTI=ON -DNCNN_DISABLE_EXCEPTION=ON -DCMAKE_TOOLCHAIN_FILE=../toolchains/rtos.toolchain.cmake -DNCNN_CMAKE_VERBOSE=OFF -DWITH_LAYER_einsum=OFF -DWITH_LAYER_absval=OFF -DWITH_LAYER_argmax=OFF -DWITH_LAYER_batchnorm=OFF -DWITH_LAYER_bnll=OFF -DWITH_LAYER_deconvolution=OFF -DWITH_LAYER_dropout=OFF -DWITH_LAYER_eltwise=OFF -DWITH_LAYER_elu=OFF -DWITH_LAYER_embed=OFF -DWITH_LAYER_exp=OFF -DWITH_LAYER_log=OFF -DWITH_LAYER_lrn=OFF -DWITH_LAYER_memorydata=ON -DWITH_LAYER_mvn=OFF -DWITH_LAYER_power=OFF -DWITH_LAYER_prelu=OFF -DWITH_LAYER_proposal=OFF -DWITH_LAYER_roipooling=OFF -DWITH_LAYER_slice=ON -DWITH_LAYER_softmax=ON -DWITH_LAYER_spp=OFF -DWITH_LAYER_tanh=OFF -DWITH_LAYER_threshold=OFF -DWITH_LAYER_tile=OFF -DWITH_LAYER_rnn=OFF -DWITH_LAYER_lstm=OFF -DWITH_LAYER_unaryop=ON -DWITH_LAYER_squeeze=OFF -DWITH_LAYER_expanddims=OFF -DWITH_LAYER_normalize=OFF -DWITH_LAYER_permute=ON -DWITH_LAYER_priorbox=OFF -DWITH_LAYER_detectionoutput=OFF -DWITH_LAYER_interp=ON -DWITH_LAYER_deconvolutiondepthwise=OFF -DWITH_LAYER_instancenorm=OFF -DWITH_LAYER_clip=OFF -DWITH_LAYER_reorg=OFF -DWITH_LAYER_yolodetectionoutput=OFF -DWITH_LAYER_yolov3detectionoutput=OFF -DWITH_LAYER_psroipooling=OFF -DWITH_LAYER_roialign=OFF -DWITH_LAYER_cast=OFF -DWITH_LAYER_hardsigmoid=OFF -DWITH_LAYER_selu=OFF -DWITH_LAYER_hardswish=OFF -DWITH_LAYER_noop=OFF -DWITH_LAYER_pixelshuffle=OFF -DWITH_LAYER_deepcopy=OFF -DWITH_LAYER_mish=OFF -DWITH_LAYER_statisticspooling=OFF -DWITH_LAYER_swish=ON -DWITH_LAYER_gemm=ON -DWITH_LAYER_groupnorm=OFF -DWITH_LAYER_layernorm=OFF -DWITH_LAYER_softplus=OFF -DWITH_LAYER_gru=OFF -DWITH_LAYER_multiheadattention=OFF -DWITH_LAYER_gelu=OFF -DWITH_LAYER_convolution1d=OFF -DWITH_LAYER_pooling1d=OFF -DWITH_LAYER_convolutiondepthwise1d=OFF -DWITH_LAYER_convolution3d=OFF -DWITH_LAYER_convolutiondepthwise3d=OFF -DWITH_LAYER_pooling3d=OFF -DWITH_LAYER_matmul=ON -DWITH_LAYER_deconvolution1d=OFF -DWITH_LAYER_deconvolutiondepthwise1d=OFF -DWITH_LAYER_deconvolution3d=OFF -DWITH_LAYER_deconvolutiondepthwise3d=OFF -DWITH_LAYER_deformableconv2d=OFF -DWITH_LAYER_glu=OFF -DWITH_LAYER_fold=OFF -DWITH_LAYER_unfold=OFF -DWITH_LAYER_gridsample=OFF -DWITH_LAYER_cumulativesum=OFF -DWITH_LAYER_copyto=OFF -DWITH_LAYER_erf=OFF -DWITH_LAYER_diag=OFF -DWITH_LAYER_celu=OFF -DWITH_LAYER_shrink=OFF ..
endif
	@echo build libncnn for FreeRTOS environment
	$(Q)$(MAKE) -C freertos

.PHONY: rtos-clean
rtos-clean:
ifneq ("$(wildcard ./freertos/Makefile)","")
	@echo clean libncnn for FreeRTOS environment
	$(Q)$(MAKE) -C freertos -j clean
endif



.PHONY: all
all: rtos-build

.PHONY: clean
clean: rtos-clean

.PHONY: install
install: all

.PHONY: uninstall
uninstall:


.PHONY: distclean
distclean: clean uninstall
	$(Q)$(RM) -r freertos
