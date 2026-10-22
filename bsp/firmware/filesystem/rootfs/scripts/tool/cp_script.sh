#!/bin/bash

init_folder=$1
out_folder=$2

for path in "$init_folder"/*; do
	filename="$(echo "$path" | awk -F"/" '{print $NF}')"
	if [ ! -d "$path" ]; then
		new_path="${out_folder}/${filename}"
		if [ ! -f "$new_path" ]; then
			cp -f $path $new_path
		fi
	fi
done



