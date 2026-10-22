#!/bin/bash

INPUT_FILE=$1
OUTPUT_FILE=$2
VERITY_FORMAT_IMG=$3

PARSE_ITEM=("Data blocks" "Data block size" "Hash block size" "Hash algorithm" "Salt" "Root hash")
UBOOT_ENV=("data_blocks" "data_block_size" "hash_block_size" "hash_algo" "salt" "roothash" "num_sectors" "hash_offset_block" "hash_offset")

if [ -f $OUTPUT_FILE ]; then
	rm $OUTPUT_FILE
fi

for string in ${UBOOT_ENV[@]}; do
	echo "setenv $string " >> $OUTPUT_FILE
done

for string in "${PARSE_ITEM[@]}"; do
	VALUE+=("$(cat $INPUT_FILE | grep "$string" | cut -f2)")
done

DATA_BLOCKS="$(cat $INPUT_FILE | grep "Data blocks" | cut -f2)"
DATA_BLOCK_SIZE="$(cat $INPUT_FILE | grep "Data block size" | cut -f2)"
NUM_SECTORS=$(( $DATA_BLOCKS * $DATA_BLOCK_SIZE / 512 ))

HASH_OFFSET_BLOCK=$(( $DATA_BLOCKS + 1 ))
HASH_OFFSET="$(stat -c "%s" $VERITY_FORMAT_IMG)"

VALUE+=($NUM_SECTORS $HASH_OFFSET_BLOCK $HASH_OFFSET)

i=1
for value in "${VALUE[@]}"; do
	sed -i " $i s/.*/&$value/" $OUTPUT_FILE
	i=$(($i + 1))
done
