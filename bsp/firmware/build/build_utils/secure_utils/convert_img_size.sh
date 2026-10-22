#!/bin/bash

# Ensure an input file is provided
if [ -z "$1" ]; then
  echo "Error: Please provide an input file as an argument."
  exit 1
fi

# Ensure an output file name is provided
if [ -z "$2" ]; then
  echo "Error: Please provide an output file name."
  exit 1
fi

# Read the input file and output file name
input_file=$1
output_file=$2

# Check if the input file exists
if [ ! -f "$input_file" ]; then
  echo "Error: The input file does not exist."
  exit 1
fi

# Get the size of the input file in bytes
file_size=$(stat -c %s "$input_file")

# Convert the file size to 32-bit hexadecimal representation
hex=$(printf "%08x" $file_size)

# Convert the hexadecimal string to little-endian format
little_endian=$(echo $hex | sed -E 's/(..)(..)(..)(..)/\4\3\2\1/')

# Output the little-endian result to the specified file
echo -n -e "\x${little_endian:0:2}\x${little_endian:2:2}\x${little_endian:4:2}\x${little_endian:6:2}" > $output_file
# Padding to 8 bytes alignment
truncate -s %8 $output_file

echo "Result has been written to $output_file"

