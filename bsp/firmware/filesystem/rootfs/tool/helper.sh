#!/usr/bin/env bash

touch_s() {
	local files=("$@")

	for file in "${files[@]}"; do
		mkdir -p "$(dirname "$file")"
		touch "$file"
	done
}

generate_mock_file() {
	local argv=("$@")
	touch_s "${argv[@]}"
}

expand_regular_rule() {
	local sysroot="$1"
	local file="$2"

	awk -v sysroot="$sysroot" '
		/^[^!#]/ {
			cmd="find " sysroot $1 " 2>/dev/null";
			system(cmd);
		}
	' "$file"
}

expand_exclude_rule() {
	local sysroot="$1"
	local file="$2"

	awk -v sysroot="$sysroot" '
		/^!/ {
			cmd="find " sysroot substr($1,2) " 2>/dev/null";
			system(cmd);
		}
	' "$file"
}

expand_file_list() {
	local sysroot="$1"
	shift
	local files=("$@")
	local output

	for file in "${files[@]}"; do
		# expand regular rules
		output=$(expand_regular_rule "$sysroot" "$file")

		# apply exclude rules if needed
		if [ -n "$output" ]; then
			grep -xvf <(expand_exclude_rule "$sysroot" "$file") \
				<<< "$output"
		fi
	done
}

shrink_rootfs() {
	local list="$1"

	echo "$list" | xargs --no-run-if-empty rm -rfv
}

copy_assets() {
	local src_dir="$1"
	local dest_dir="$2"
	local list="$3"
	local target

	for line in $list; do
		target="${line//$src_dir/$dest_dir}"
		if [ -d "$line" ]; then
			mkdir -p "$target"
		else
			mkdir -p "$(dirname "$target")"
			cp -Ppv --remove-destination "$line" "$target"
		fi
	done
}
