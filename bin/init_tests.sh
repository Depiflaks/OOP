#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <name of test_file without .cpp>"
    exit 1
fi

SOURCE_FILE="$1"
EXECUTABLE="${SOURCE_FILE%.cpp}"
echo "$SOURCE_FILE"
echo "$EXECUTABLE"
g++ "$SOURCE_FILE" -o "$EXECUTABLE" -lgtest -lgtest_main -pthread || { echo "Compilation failed"; exit 1; }

"./$EXECUTABLE"
