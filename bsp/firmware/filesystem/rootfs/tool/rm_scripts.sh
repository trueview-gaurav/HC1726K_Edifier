#!/bin/bash


init_ls=$1
rootfs_path=$2
check_path="$(echo -e "${rootfs_path}" | tr -d '[:space:]')" 
init_tmp_folder=$3

if [ ! -d $rootfs_path ]; then
  echo "$rootfs_path does not exist!!!++++++++++++++++++++++++++++++++++++++++++++"

  if [ -e $init_ls ]; then
     echo "remove $init_ls"
     rm -f $init_ls
  fi

  if [ -d $init_tmp_folder ]; then
     echo "remove $init_tmp_folder"
     rm -rf $init_tmp_folder
  fi
fi


if [ ! -e $init_ls ]; then
   echo "$init_ls does not exist"
   exit 0
fi


if [ ! -d $init_tmp_folder ]; then

   echo "$init_tmp_folder does not exist!!!"
   exit 0
fi

if [ ! "$(ls -A $init_tmp_folder)" ]; then
    echo "$init_tmp_folder is empty folder!!!"
    exit 0
fi


if [ -z "$check_path" ] || [ $check_path = "/" ] || [[ $check_path == "//"* ]] || [ $check_path = "./" ] || [[ $check_path == "/."* ]]; then
   echo "wrong rootfs path:$rootfs_path"
   exit 0
fi




rm -rf $rootfs_path/S*
rm -rf $rootfs_path/K*
rm -rf $rootfs_path/audio*

cp -f $init_tmp_folder/* "$rootfs_path"


