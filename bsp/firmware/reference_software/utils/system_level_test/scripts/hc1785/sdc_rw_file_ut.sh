#!/bin/sh

# --- File Path Definitions ---
INPUT_FILE="/mnt/sdcard/sdc_test_pattern.bin"     # Source file to be read (input pattern)
OUTPUT_FILE="/mnt/sdcard/sdc_test_result.bin"    # Destination file for the write operation (result)
COUNT="100"                                      # Number of blocks to copy

# --- Block Size Assignment ---
# Check if the first positional argument ($1) is provided.
# If $1 is empty, default the BLOCK_SIZE to 512B.
# Otherwise, use the provided argument as the block size.
BLOCK_SIZE=${1:-512}

# --- Color Definitions (Red for Failure messages) ---
RED='\033[0;31m'  # ANSI code for Red color
NC='\033[0m'      # ANSI code for No Color (reset)

# --- Function: Check if the Input Test File Exists ---
check_file() {
    # Check if the input file does NOT exist (-f check for regular file)
    if [ ! -f "$INPUT_FILE" ]; then
        # Print failure message in Red if the input file is missing
        echo -e "${RED}Test Failed:${NC} Input test file $INPUT_FILE does not exist! Please create it or verify the path."
        # Note: You may need to create this file manually for the script to run.
        exit 1 # Exit the script with an error code
    fi
}

# --- Execute Pre-check ---
check_file

echo "--- File I/O Test Start ---"
echo "Input File: $INPUT_FILE"
echo "Output File: $OUTPUT_FILE"
echo "Block Size (bs): $BLOCK_SIZE" # Display the determined block size

# ----------------------------------------------------
# 1. Write Operation (Reading from Input and Writing to Output)
# ----------------------------------------------------
echo -e "\n[1/3] Starting Write Operation..."

# Use /usr/bin/time (with custom format "%e" for elapsed time) to measure the write duration.
WRITE_TIME=$(/usr/bin/time -f "%e" dd if="$INPUT_FILE" of="$OUTPUT_FILE" bs="$BLOCK_SIZE" status=none 2>&1)

WRITE_STATUS=$? # Capture the exit status of the dd command
if [ $WRITE_STATUS -ne 0 ]; then
    # Print failure message if the dd command itself failed
    echo -e "${RED}Test Failed:${NC} Write command (dd) failed with exit code $WRITE_STATUS."
    exit 1
fi

# ----------------------------------------------------
# 2. Read Operation (Reading the Output File for Timing)
# ----------------------------------------------------
echo "[2/3] Starting Readback Operation and Timing..."
# Use /usr/bin/time to measure the read duration.
READ_TIME=$(/usr/bin/time -f "%e" dd if="$OUTPUT_FILE" of=/dev/null bs="$BLOCK_SIZE" status=none 2>&1)

READ_STATUS=$? # Capture the exit status of the read dd command
if [ $READ_STATUS -ne 0 ]; then
    # Print failure message if the read dd command failed
    echo -e "${RED}Test Failed:${NC} Read command (dd) failed with exit code $READ_STATUS."
    exit 1
fi

# ----------------------------------------------------
# 3. Content Check (Verification)
# ----------------------------------------------------
echo "[3/3] Checking file content consistency..."
# Use cmp (compare) to check if the input and output files are identical byte-for-byte.
cmp "$INPUT_FILE" "$OUTPUT_FILE"

CMP_STATUS=$? # Capture the exit status of the cmp command

if [ $CMP_STATUS -eq 0 ]; then
    # cmp exit code 0 means the files are identical (Test Passed)
    echo -e "\n--- Test Passed ---"
    echo "Content Verification: Correct and consistent."
    echo "Total elapsed time for Write operation (seconds): $WRITE_TIME"
    echo "Total elapsed time for Read operation (seconds): $READ_TIME"
else
    # cmp exit code non-zero means the files are different (Test Failed)
    echo -e "\n${RED}Test Failed${NC}"
    echo "Reason: Content mismatch between $INPUT_FILE and $OUTPUT_FILE."
fi