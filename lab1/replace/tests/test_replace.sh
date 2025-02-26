#!/bin/bash

executable="./main"
expectedParams=("$input" "$output" "$search" "$replace")

function run_positive_test {
    local filePath=$1
    local paramsMap
    paramsMap=$(parse_test_file "$filePath" "${expectedParams[@]}")
    local params
    params=$(replace_params "$paramsMap")

    local systemOutput
    systemOutput=$(run_system_stream "$params")
    local filesOutput
    filesOutput=$(run_with_files "$params")

    if [ "$systemOutput" == "$(echo -e "$(echo "$params" | grep 'output=' | cut -d'=' -f2-)")" ] && \
       [ "$filesOutput" == "$(echo -e "$(echo "$params" | grep 'output=' | cut -d'=' -f2-)")" ]; then
        echo "Test passed: $filePath"
    else
        echo "Test failed: $filePath"
    fi
}

function parse_test_file {
    local fileName=$1
    shift
    local names=("$@")
    declare -A parameters

    if [ ! -f "$fileName" ]; then
        echo "Error: cannot open file $fileName" >&2
        return
    fi

    local currentParam=""
    while IFS= read -r line; do
        if [[ " ${names[@]} " =~ " ${line} " ]]; then
            currentParam=$line
            IFS= read -r line
            parameters["$currentParam"]=$line
        elif [ -n "$currentParam" ]; then
            parameters["$currentParam"]+="\n$line"
        fi
    done < "$fileName"

    declare -p parameters
}

function replace_params {
    local paramsMap=$1
    eval "$paramsMap"

    local input=${parameters["\$input"]}
    local output=${parameters["\$output"]}
    local search=${parameters["\$search"]}
    local replace=${parameters["\$replace"]}

    echo "input=$input output=$output search=$search replace=$replace"
}

function run_system_stream {
    local params=$1
    eval "$params"

    local command="echo -e \"$search\n$replace\n$input\" | $executable"
    execute_command "$command"
}

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

function run_with_files {
    local params=$1
    eval "$params"

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

function create_temp_file {
    local content=$1
    local filename
    filename=$(mktemp)
    write_to_file "$filename" "$content"
    echo "$filename"
}

function write_to_file {
    local filename=$1
    local content=$2

    echo -e "$content" > "$filename"
    if [ $? -ne 0 ]; then
        echo "Failed to write to file $filename" >&2
        return 1
    fi
}

# Main execution
run_positive_test "./files/empty_search.txt"
run_positive_test "./files/empty_replace.txt"
run_positive_test "./files/empty_input.txt"
run_positive_test "./files/unique_symbol.txt"
run_positive_test "./files/many_symbols.txt"
run_positive_test "./files/symbol_in_text.txt"
run_positive_test "./files/empty_lines.txt"
run_positive_test "./files/symbol_between_empty_lines.txt"
run_positive_test "./files/many_symbol_replace.txt"
run_positive_test "./files/no_replace.txt"
run_positive_test "./files/replace_more_than_search.txt"

# Negative tests
echo "Testing invalid argument count..."
command="$executable arg1 arg2 2>/dev/null"
execute_command "$command" && echo "Test failed" || echo "Test passed"

command="$executable arg1 arg2 arg3 2>/dev/null"
execute_command "$command" && echo "Test failed" || echo "Test passed"

command="$executable arg1 arg2 arg3 arg4 arg5 2>/dev/null"
execute_command "$command" && echo "Test failed" || echo "Test passed"

echo "Testing duplicated files..."
command="$executable file.txt file.txt 2>/dev/null"
execute_command "$command" && echo "Test failed" || echo "Test passed"xecute_command "$command" && echo "Test failed" || echo "Test passed"