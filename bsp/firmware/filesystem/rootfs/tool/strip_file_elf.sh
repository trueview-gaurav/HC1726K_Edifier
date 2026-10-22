#!/bin/bash

strip_folder=$1
objcopy_tool=$2
strip_tool=$3
sstrip_tool=$4
elf_list=$5

strip_elf_files() {
	rm -f $elf_list

	# search elf file
	find "$strip_folder" -type f -not -name "*.ko" -exec file {} \; | grep -i "ELF" > "$elf_list"

	while read -r line; do
		name="$line"
		file_path="$( cut -d ':' -f 1 <<< "$name" )"
		$sstrip_tool -z $file_path $file_path
	done < "$elf_list"
	rm -f $elf_list
}

unset LD_LIBRARY_PATH
strip_elf_files
