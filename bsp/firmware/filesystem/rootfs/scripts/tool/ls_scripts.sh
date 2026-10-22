#!/bin/bash


buildroot_init_folder=$1
script_list=$2
out_file=$3
init_tmp_folder=$4


if [ -e $out_file ]; then
 rm -f $out_file
fi

mkdir -p $init_tmp_folder

for entry in "$buildroot_init_folder"/*
do
  file_name="$(echo "$entry" | awk -F"/" '{print $NF}')"
  #echo "$file_name"

  if ! grep -Fxq "$file_name" $script_list
  then
     
      echo "$file_name"
      echo "$file_name" >> $out_file
      cp -f "$buildroot_init_folder/$file_name" "$init_tmp_folder/$file_name"
  fi

done

