
# 被引用的打包脚本需要按照Makefile语法实现这些目标.
# update_fs -- 更新文件系统中的文件.
# update_ver -- 更新文件系统的版本.
# mkimg_fs -- 制作文件系统的镜像文件.


init_fs:
	@echo "Cleaning fs.";
	@rm -rf fs && mkdir -p fs/custom;

update_fs: init_fs update_fs_config mkimg_fs_config \
	update_fs_ko tar_fs_ko update_fs_bin tar_fs_bin update_fs_lib tar_fs_lib \
	update_fs_custom_smart

update_ver: edit_fs_config mkimg_fs_config
	@[ -d $(shell dirname ${CUSTOM_PATH}) ] || mkdir -p $(shell dirname ${CUSTOM_PATH});
	@echo "SwVersion=\"V4.3\"" > ${CUSTOM_PATH}/version;
	@echo "HwVersion=\"V4.0\"" >> ${CUSTOM_PATH}/version;
	@echo "Hardware=\"${HARDWARE_NAME}\"" >> ${CUSTOM_PATH}/version;
	@echo "BuildDate=\"${buildyear}${buildmonth}${buildday}\"" >> ${CUSTOM_PATH}/version;
#   @echo "ProductDate=\"${buildyear}${buildmonth}${buildday}\"" >> ${CUSTOM_PATH}/version;
	@echo "LensSupport=${AUTOLENS_SUPPORT}" >> ${CUSTOM_PATH}/version;
	@echo "LensDrvType=\"${AUTOLENS_DRIVE}\"" >> ${CUSTOM_PATH}/version;
	@echo "LensType=\"${AUTOLENS_TYPE}\"" >> ${CUSTOM_PATH}/version;
	
	@cat fs/config/factoryinfo.json | sed 's/,/\n/g' | grep "ProductDate" | sed 's/"ProductDate"/\ProductDate/g' | sed 's/:/\=/g' | sed 's/[[:space:]]//g' >> ${CUSTOM_PATH}/version;

mkimg_fs: mkimg_fs_config tar_fs_ko tar_fs_bin tar_fs_lib mkimg_fs_custom_smart tar_appfs finish_fs

KO_PATH:=fs/ko

BIN_PATH:=fs/bin

LIB_PATH:=fs/lib

CUSTOM_PATH:=fs/custom

#### 更新config,factory目录文件 ############
load_fs_config:
	@echo "Preparing fs/config";
	@mkdir -p fs/config;
	@cp ${ROOT}/ovfs/shscript/factoryinfo.json fs/config
	@sed -i -e 's#\("LensSupport":\).*[0-9]#\1 ${AUTOLENS_SUPPORT}#g' \
	-e 's#\("LensDrvType":\).*\"#\1"'${AUTOLENS_DRIVE}'"#g' \
	-e 's#\("LensType":\).*\"#\1"'${AUTOLENS_TYPE}'"#g' \
	-e 's#\("Customer":\).*\"#\1"'${CUSTOMER_NAME}'"#g' \
	-e 's#\("Project":\).*\"#\1"'${PROJECT_NAME}'"#g' \
	-e 's#\("Hardware":\).*\"#\1"'${HARDWARE_NAME}'"#g' \
	-e 's#\("SensorModel":\).*\"#\1"'${SENSORMODEL_NAME}'"#g' \
	-e 's#\("Platform":\).*#\1"'${PLATFORM_NAME}'",#g' fs/config/factoryinfo.json;

	@cp ${ROOT}/ovfs/shscript/savetime.txt fs/config/savetime.txt
update_productdate:
	@sed -i -e 's#\("ProductDate":\).*\"#\1"'${buildyear}${buildmonth}${buildday}-m'"#g' fs/config/factoryinfo.json;

edit_fs_config:
	@sed -i -e 's#\("BuildDate":\).*#\1"'${buildyear}${buildmonth}${buildday}'",#g' \
	-e 's#\("SensorModel":\).*\"#\1"'${SENSORMODEL_NAME}'"#g' fs/config/factoryinfo.json;
	
update_fs_config: load_fs_config edit_fs_config update_productdate

mkimg_fs_config:
	${MKJFFS2IMG} -l -e 0x10000 -d fs/config -o fs/config.bin;
	@mkdir -p fs/factory && touch fs/factory/demo.txt
	${MKJFFS2IMG} -l -e 0x10000 -d fs/factory -o fs/factory.bin;
	
#### 更新ko目录文件 ############
update_fs_ko:
	@echo "Preparing ${KO_PATH}";
	@mkdir -p ${KO_PATH};
	@cp ${ROOT}/ovfs/ko/audio_machine.ko ${KO_PATH}/audio_machine.ko
	@cp ${ROOT}/ovfs/ko/audio_pcm.ko ${KO_PATH}/audio_pcm.ko
	@cp ${ROOT}/ovfs/ko/mpp.ko ${KO_PATH}/mpp.ko
	@cp ${ROOT}/ovfs/ko/otp-agtx.ko ${KO_PATH}/otp-agtx.ko
	@cp ${ROOT}/ovfs/ko/otp-ep.ko ${KO_PATH}/otp-ep.ko
	@cp ${ROOT}/ovfs/ko/sensor.ko ${KO_PATH}/sensor.ko
	@mkdir -p ${KO_PATH}/ourdrv;
	@cp ${ROOT}/ovfs/shscript/load_mpp.sh ${KO_PATH}/load_mpp.sh
	@chmod a+x ${KO_PATH}/load_mpp.sh;

tar_fs_ko:
	cp -afT ${KO_PATH} ${CUSTOM_PATH}/ko;

#### 更新bin目录文件 ############
update_fs_bin:
	@echo "Preparing ${BIN_PATH}";
	@mkdir -p ${BIN_PATH};
	@cp ${ROOT}/appsrc/pub/hc1726/bin/ntpclient ${BIN_PATH}/ntpclient
	@cp ${ROOT}/ovfs/bin/ovfs_boardsystem ${BIN_PATH}/ovfs_boardsystem

	@cp ${ROOT}/appsrc/pub/hc1726/bin/ovfs_core_2063 ${BIN_PATH}/ovfs_core
	@cp ${ROOT}/appsrc/pub/hc1726/bin/ovfs_mediaserver ${BIN_PATH}/ovfs_mediaserver
	@cp ${ROOT}/appsrc/pub/hc1726/bin/ovfs_network ${BIN_PATH}/ovfs_network
	@cp ${ROOT}/appsrc/pub/hc1726/bin/ovfs_record ${BIN_PATH}/ovfs_record

	@cp ${ROOT}/ovfs/bin/mkfs.ext4 ${BIN_PATH}/mkfs.ext4

	@cp ${ROOT}/appsrc/pub/hc1726/bin/pureupdate ${BIN_PATH}/update
	@cp ${ROOT}/appsrc/pub/hc1726/bin/ovfs_webserver ${BIN_PATH}/ovfs_webserver
	@cp ${ROOT}/appsrc/pub/hc1726/bin/uritool ${BIN_PATH}/uritool

	@cp ${ROOT}/appsrc/pub/hc1726/bin/ovfs_eventlog ${BIN_PATH}/ovfs_eventlog

	@cp ${ROOT}/appsrc/pub/hc1726/bin/sysinit ${BIN_PATH}/sysinit

	@cp ${ROOT}/ovfs/shscript/udhcpc.script ${BIN_PATH}/udhcpc.script
	@cp ${ROOT}/ovfs/shscript/udhcpc6.script ${BIN_PATH}/udhcpc6.script

	@cp ${ROOT}/appsrc/pub/hc1726/bin/wtdgops ${BIN_PATH}/wtdgops

	@chmod a+x -R fs/bin;
	@chmod a+x -R fs/bin/*;

tar_fs_bin:
	@cp -af fs/bin ${CUSTOM_PATH}/;
	
#### 更新lib目录文件 ############
update_fs_lib:
	@echo "Preparing ${LIB_PATH}";
	@mkdir -p ${LIB_PATH};
	@cp ${ROOT}/appsrc/pub/hc1726/lib/libaccess.so ${LIB_PATH}/libaccess.so
	@cp ${ROOT}/appsrc/pub/hc1726/lib/libcommon.so ${LIB_PATH}/libcommon.so
	@cp ${ROOT}/appsrc/pub/hc1726/lib/libcurl.so ${LIB_PATH}/libcurl.so
	@cp -r ${ROOT}/appsrc/pub/hc1726/lib/libssl.s* ${LIB_PATH}/.
	@cp -r ${ROOT}/appsrc/pub/hc1726/lib/libcrypto.s* ${LIB_PATH}/.
	@cp ${ROOT}/appsrc/pub/hc1726/lib/libsqlite3.so ${LIB_PATH}/libsqlite3.so
	@cp ${ROOT}/appsrc/pub/hc1726/lib/libmodule.so ${LIB_PATH}/libmodule.so
	@cp -r ${ROOT}/appsrc/pub/hc1726/lib/libmxml* ${LIB_PATH}/.

	@cp ${ROOT}/ovfs/lib/libasound.so ${LIB_PATH}/libasound.so
	@cp ${ROOT}/ovfs/lib/libmpp.so ${LIB_PATH}/libmpp.so
	@cp ${ROOT}/ovfs/lib/libvftr.so ${LIB_PATH}/libvftr.so
	@cp ${ROOT}/ovfs/lib/libsensor_0_sc4336p.so ${LIB_PATH}/libsensor_0_sc4336p.so
	@cp ${ROOT}/ovfs/lib/libncnn-compact.so ${LIB_PATH}/libncnn-compact.so
	@cp ${ROOT}/ovfs/lib/libml_peoplevehiclepet_lite.so ${LIB_PATH}/libml_peoplevehiclepet_lite.so
	@cp ${ROOT}/ovfs/lib/libstdc++.so.6.0.28 ${LIB_PATH}/libstdc++.so.6.0.28

	@cp ${ROOT}/ovfs/lib/libboardsys_smart.so ${LIB_PATH}/libboardsys_smart.so
	@cp ${ROOT}/ovfs/lib/libfont.so ${LIB_PATH}/libfont.so

	@cp ${ROOT}/appsrc/pub/hc1726/lib/librestcomm.so ${LIB_PATH}/librestcomm.so
	@cp ${ROOT}/appsrc/pub/hc1726/lib/librtspserver_v2.so ${LIB_PATH}/librtspserver_v2.so

	@cp ${ROOT}/appsrc/pub/hc1726/lib/libonvif.so ${LIB_PATH}/libonvif.so

#	@cp ${ROOT}/appsrc/pub/hc1726/lib/libjpeg.so ${LIB_PATH}/libjpeg.so
	@cp ${ROOT}/appsrc/pub/hc1726/lib/librawstorage.so ${LIB_PATH}/librawstorage.so
	@cp ${ROOT}/appsrc/pub/hc1726/lib/libstreamqueue.so ${LIB_PATH}/libstreamqueue.so
	@cp ${ROOT}/appsrc/pub/hc1726/lib/libz.so ${LIB_PATH}/libz.so

	@ln -sf libasound.so					${LIB_PATH}/libasound.so.2;
	@ln -sf libmpp.so						${LIB_PATH}/libmpp.so.3;
	@ln -sf libvftr.so						${LIB_PATH}/libvftr.so.3;
	@ln -sf libsensor_0_sc4336p.so			${LIB_PATH}/libsensor_0.so;
	@ln -sf libncnn-compact.so				${LIB_PATH}/libncnn-compact.so.1;
	@ln -sf libml_peoplevehiclepet_lite.so	${LIB_PATH}/libml_peoplevehiclepet_lite.so.3;
	@ln -sf libcurl.so						${LIB_PATH}/libcurl.so.4;
	@ln -sf libz.so							${LIB_PATH}/libz.so.1;
	@ln -sf libstdc++.so.6.0.28					${LIB_PATH}/libstdc++.so.6;
	@ln -sf libstdc++.so.6					${LIB_PATH}/libstdc++.so;

tar_fs_lib:
	@cp -af fs/lib ${CUSTOM_PATH}/;

#### 更新custom目录文件 ############
update_fs_custom_smart:
	@echo "Preparing ${CUSTOM_PATH}";
	@mkdir -p ${CUSTOM_PATH};
	@cp ${ROOT}/ovfs/shscript/appinstall ${CUSTOM_PATH}/appinstall
	@cp ${ROOT}/ovfs/shscript/update_factoryinfo.sh ${CUSTOM_PATH}/update_factoryinfo.sh
	@cp ${ROOT}/ovfs/shscript/mount_mmc_raw ${CUSTOM_PATH}/mount_mmc
	@cp ${ROOT}/ovfs/shscript/update_pre ${CUSTOM_PATH}/update_pre

	@cp ${ROOT}/ovfs/lib/libisp_sc4336p.so ${CUSTOM_PATH}/libisp_sc4336p.so

	@mkdir -p ${CUSTOM_PATH}/sensor/;
	@cp -ar ${ROOT}/ovfs/sensor/sc4336p/* ${CUSTOM_PATH}/sensor/

	@cp -ar ${ROOT}/ovfs/nginx ${CUSTOM_PATH}/
	@cp ${ROOT}/appsrc/pub/hc1726/bin/nginx ${CUSTOM_PATH}/nginx/sbin/nginx;
	@mv ${CUSTOM_PATH}/nginx/html/static/images/logo.png ${CUSTOM_PATH}/nginx/html/static/images/logo_default.png;
	@ln -sf /usr/etc/logo.png ${CUSTOM_PATH}/nginx/html/static/images/logo.png
	@ln -sf /tmp/nginx/logs ${CUSTOM_PATH}/nginx/logs
	@ln -sf /tmp/nginx/proxy_temp ${CUSTOM_PATH}/nginx/proxy_temp
	@ln -sf /tmp/nginx/fastcgi_temp ${CUSTOM_PATH}/nginx/fastcgi_temp
	@ln -sf /dev/exportcfg.tgz ${CUSTOM_PATH}/nginx/html/exportcfg.tgz
	@ln -sf /tmp/mmc/mmc1/log/AlarmPic ${CUSTOM_PATH}/nginx/html/AlarmPic

	@mkdir -p ${CUSTOM_PATH}/model_file;
	@cp ${ROOT}/ovfs/model/model.bin ${CUSTOM_PATH}/model_file/model.bin
	@cp ${ROOT}/ovfs/model/model.param.bin ${CUSTOM_PATH}/model_file/model.param.bin

	@mkdir -p ${CUSTOM_PATH}/font;
	@cp ${ROOT}/ovfs/font/servicestatus ${CUSTOM_PATH}/font/servicestatus
	@cp ${ROOT}/ovfs/font/simkai_U16.bin ${CUSTOM_PATH}/font/simkai_U16.bin

	@mkdir -p ${CUSTOM_PATH}/res/custom
	@mkdir -p ${CUSTOM_PATH}/res/default
	@cp ${ROOT}/ovfs/custom/* ${CUSTOM_PATH}/res/custom/
	@cp ${ROOT}/ovfs/cfgfiles/* ${CUSTOM_PATH}/res/default/
	@cp -af fs/config/factoryinfo.json ${CUSTOM_PATH}/res;
	cp -af fs/config/factoryinfo.json ${CUSTOM_PATH}/res;

	@cp -ar ${ROOT}/ovfs/soundfile ${CUSTOM_PATH}/

	@mkdir -p ${CUSTOM_PATH}/ssl/;
	@cp ${ROOT}/appsrc/pub/hc1726/ssl/etc/ssl/openssl.cnf ${CUSTOM_PATH}/ssl/openssl.cnf;
	@cp ${ROOT}/appsrc/pub/hc1726/ssl/etc/ssl/x509v3.cnf ${CUSTOM_PATH}/ssl/x509v3.cnf;

	@chmod a+x -R fs/custom;

mkimg_fs_custom_smart:
	rm -rf fs/custom_rw.bin; ${MKJFFS2IMG} -l -e 0x10000 -d fs/custom -o fs/custom_rw.bin;
	rm -rf fs/custom_ro.bin; ${MKSQUASHFSIMG} fs/custom fs/custom_ro.bin -b 64k -comp xz -no-xattrs;

tar_appfs:
	@cp -a fs/custom fs/update && rm -fr fs/update/soundFile && tar -czf fs/appfs.tgz -C fs update && rm -fr fs/update;

finish_fs:
	@printf "finish fs\n"
	@mkdir -p ${IMAGE_PATH}/fs;
	@cp -af fs/appfs.tgz ${IMAGE_PATH}/fs/appfs.tgz;
	@cp -af fs/factory.bin ${IMAGE_PATH}/fs/factory.bin;
	@cp -af fs/config.bin ${IMAGE_PATH}/fs/config.bin;
	@cp -af fs/custom_rw.bin ${IMAGE_PATH}/fs/custom_rw.bin;
	@cp -af fs/custom_ro.bin ${IMAGE_PATH}/fs/custom_ro.bin;
