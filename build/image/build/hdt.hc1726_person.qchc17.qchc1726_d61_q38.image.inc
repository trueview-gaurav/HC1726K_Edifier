
# 被引用的打包脚本需要按照Makefile语法实现这些目标.
# update_fs -- 更新文件系统中的文件.
# mkimg_fs -- 制作文件系统的镜像文件.

FIELNAME:=${buildyear}${buildmonth}${buildday}-${SHORTNAME_NAME}-${PROJECT_NAME}-${HARDWARE_NAME}-${SENSORMODEL_NAME}

HWID_OPTB=$(patsubst %,-b %,${HWID_NAME})

init_fs:
	@echo "Cleaning fs.";
	@rm -rf fs;

update_fs: init_fs update_fs_uboot update_fs_kernel update_fs_other update_fs_appfs

mkimg_fs:
	@cd fs; \
	${MKFLASHFS} -f uboot.bin 384 -f factory.bin 64 -f env.bin 64 -f config.bin 512 -f fitImage.bin 3072 -f rootfs.bin 2048 -f custom_ro.bin 9216 -f tee.bin 896 -f rest.bin 128 -o ${RELEASE_COPY_PATH}/${FIELNAME}.flash; \
	${MKFLASHFS} -f uboot.bin 384 -f factory.bin 64 -f env.bin 64 -f config.bin 512 -f fitImage.bin 3072 -f rootfs.bin 2048 -f custom_rw.bin 9216 -f tee.bin 896 -f rest.bin 128 -o ${RELEASE_COPY_PATH}/${FIELNAME}_debug.flash; \
	${MKFLASHFS} ${HWID_OPTB} -p custom_ro.bin 6144 9216 -o ${RELEASE_COPY_PATH}/${FIELNAME}.update; \
	${MKFLASHFS} ${HWID_OPTB} -p uboot.bin 0 384 -p fitImage.bin 1024 3072 -p rootfs.bin 4096 2048 -p custom_ro.bin 6144 9216 -o ${RELEASE_COPY_PATH}/${FIELNAME}.rpu.update; \
	${MKFLASHFS} ${HWID_OPTB} -p uboot.bin 0 384 -p fitImage.bin 1024 3072 -p rootfs.bin 4096 2048 -p custom_rw.bin 6144 9216 -o ${RELEASE_COPY_PATH}/${FIELNAME}_debug.rpu.update; \
	cd - > /dev/null;

update_fs_uboot:
	@mkdir -p fs;
	@cp ${ROOT}/bsp/out/uboot.bin fs/uboot.bin

update_fs_kernel:
	@mkdir -p fs;
	@cp ${ROOT}/bsp/out/fitImage.bin fs/fitImage.bin
	@cp ${ROOT}/bsp/out/rootfs.bin fs/rootfs.bin

update_fs_other:
	@mkdir -p fs;
	@cp ${ROOT}/bsp/out/tee.bin fs/tee.bin
	@touch fs/env.bin
	@touch fs/rest.bin

update_fs_appfs:
	@cp -af ${APPFS_PATH}/fs/factory.bin fs/factory.bin;
	@cp -af ${APPFS_PATH}/fs/config.bin fs/config.bin;
	@cp -af ${APPFS_PATH}/fs/custom_rw.bin fs/custom_rw.bin;
	@cp -af ${APPFS_PATH}/fs/custom_ro.bin fs/custom_ro.bin;