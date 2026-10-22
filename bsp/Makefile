.PHONY: all

none:help

help:
	@printf "\n"
	@printf "make install .\n"
	@printf "make all .\n"
	@printf "make clean .\n"

all: build install

build:
	@cd firmware/build/;./set_env_var.sh HC1726 && make hc1726-agt726-4_defconfig && make clean all signature;

install:
	mkdir -p out;
	@cp firmware/build/output/boot_flash.bin out/uboot.bin;
	@cp firmware/build/output/fitImage.bin out/fitImage.bin;
	@cp firmware/build/output/rootfs.cpio.uboot.bin out/rootfs.bin;
	@cp firmware/build/output/tee.bin out/tee.bin


clean: 
	@cd firmware/build/; make clean;
	rm -fr out
