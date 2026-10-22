#!/bin/bash

strip_folder=$1
objcopy_tool=$2
strip_tool=$3
sstrip_tool=$4
ko_list=$5

strip_ko_files() {
	rm -f $ko_list

	# search ko file
	find $strip_folder -name "*.ko" > $ko_list

	while read -r line; do
		name="$line"
		$strip_tool --strip-debug "$name"
		$objcopy_tool  -R .comment -R .note.ABI-tag -R .gnu.version "$name"

	done < "$ko_list"
	rm -f $ko_list

}

unset LD_LIBRARY_PATH
strip_ko_files
