#!/bin/bash

buildroot_init_folder=$1
config_script=$2
common_init_folder=$3

find_init_script(){
	local flag=0
	local filename="$1"

	exec < $filename
	while read line; do
		if [[ ${line} == "$2" ]];then
			flag=$((flag+1))
		break
		fi
	done
	echo $flag
}


find_init_file()
{
	local flag=0
	local file_name=""

	for path in "$1"/*; do
		file_name="$(echo "$path" | awk -F"/" '{print $NF}')"
		if [[ $2 == "$file_name" ]];then
			flag=$((flag+1))
			break
		fi
	done
	echo $flag
}


for common_old_path in "$common_init_folder"/*; do
	common_file_name="$(echo "$common_old_path" | awk -F"/" '{print $NF}')"
	if [[ ${common_file_name} == "S"* ]] || [[ ${common_file_name} == "K"* ]]; then
		new_common_filename=$(echo $common_file_name | cut -c4-)
		new_common_path="${buildroot_init_folder}/${new_common_filename}"
		old_common_path="${buildroot_init_folder}/${common_file_name}"
		mv -f $old_common_path $new_common_path
		if [ -f $old_common_path ]; then
			rm -f $old_common_path
		fi
		ln -s $new_common_filename $old_common_path
	fi
done

for old_path in "$buildroot_init_folder"/*; do
	file_name="$(echo "$old_path" | awk -F"/" '{print $NF}')"
	if [[ ${file_name} == "S"* ]] || [[ ${file_name} == "K"* ]]; then
		if [[ $(find_init_file $common_init_folder $file_name) -eq 0 ]]; then
			new_filename=$(echo $file_name | cut -c4-)
			new_path="${buildroot_init_folder}/${new_filename}"
			mv -f $old_path $new_path
			if [[ $(find_init_script $config_script $file_name) -eq 1 ]]; then
				if [ -f $old_path ]; then
					rm -f $old_path
				fi
				ln -s $new_filename $old_path 
			fi
		fi
	fi
done



