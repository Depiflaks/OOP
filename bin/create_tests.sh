#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <number of test files>"
    exit 1
fi

NUM_TESTS="$1"
FILES_DIR="./files"

mkdir -p "$FILES_DIR"

for i in $(seq 1 "$NUM_TESTS"); do
    mkdir -p "$FILES_DIR/$i"
    touch "$FILES_DIR/$i/input.txt"
    touch "$FILES_DIR/$i/output.txt"
done

echo "Generated $NUM_TESTS test files in '$FILES_DIR'."