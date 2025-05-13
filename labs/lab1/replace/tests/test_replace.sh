#!/bin/bash

executable="./main"

function execute_command {
    local command=$1
    local result
    result=$(eval "$command" 2>&1)
    local exitCode=$?

    if [ $exitCode -ne 0 ]; then
        echo "Command failed with exit code: $exitCode" >&2
        return 1
    fi

    echo "$result"
}


function create_temp_file {
    local content=$1
    local filename
    filename=$(mktemp)
    echo -e "$content" > "$filename"
    echo "$filename"
}


function run_with_files {
    local input=$1
    local output=$2
    local search=$3
    local replace=$4

    local inputFile
    inputFile=$(create_temp_file "$input")
    local outputFile
    outputFile=$(create_temp_file "")

    local command="$executable $inputFile $outputFile \"$search\" \"$replace\""
    execute_command "$command"

    local outputContent
    outputContent=$(cat "$outputFile")

    rm -f "$inputFile" "$outputFile"

    echo "$outputContent"
}


function run_system_stream {
    local input=$1
    local search=$2
    local replace=$3

    local command="echo -e \"$search\n$replace\n$input\" | $executable"
    execute_command "$command"
}


function run_positive_test {
    local input=$1
    local expectedOutput=$2
    local search=$3
    local replace=$4

    local systemOutput
    systemOutput=$(run_system_stream "$input" "$search" "$replace")
    local filesOutput
    filesOutput=$(run_with_files "$input" "" "$search" "$replace")

    if [ "$systemOutput" == "$expectedOutput" ] && [ "$filesOutput" == "$expectedOutput" ]; then
        echo "Test passed"
    else
        echo "Test failed"
        echo "Expected: $expectedOutput"
        echo "System output: $systemOutput"
        echo "Files output: $filesOutput"
    fi
}


echo "Running tests..."


echo "Test 1: Empty search"
run_positive_test "input text" "input text" "" "replacement"


echo "Test 2: Empty replace"
run_positive_test "input text" "input text" "search" ""


echo "Test 3: Unique symbol"
run_positive_test "abc" "adc" "b" "d"


echo "Test 4: Many symbols"
run_positive_test "aabbcc" "aaddcc" "bb" "dd"


echo "Test 5: Symbol in text"
run_positive_test "hello world" "hello there" "world" "there"


echo "Test 6: Empty lines"
run_positive_test "\n\n" "\n\n" "a" "b"

echo "Test 7: Symbol between empty lines"
run_positive_test "\na\n" "\nb\n" "a" "b"

echo "Test 8: Many symbol replace"
run_positive_test "aaa" "bbb" "a" "b"

echo "Test 9: No replace"
run_positive_test "abc" "abc" "x" "y"

echo "Test 10: Replace more than search"
run_positive_test "abc" "def" "abc" "def"

echo "Testing invalid argument count..."
command="$executable arg1 arg2 2>/dev/null"
execute_command "$command" && echo "Test failed" || echo "Test passed"

command="$executable arg1 arg2 arg3 2>/dev/null"
execute_command "$command" && echo "Test failed" || echo "Test passed"

command="$executable arg1 arg2 arg3 arg4 arg5 2>/dev/null"
execute_command "$command" && echo "Test failed" || echo "Test passed"

echo "Testing duplicated files..."
command="$executable file.txt file.txt 2>/dev/null"
execute_command "$command" && echo "Test failed" || echo "Test passed"