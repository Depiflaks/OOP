#!/bin/bash

#set -e

if [ $# -ne 1 ]; then
    echo "Usage: $0 <path_to_radix_executable>"
    exit 1
fi

RADIX_EXE="$1"
if [ ! -x "$RADIX_EXE" ]; then
    echo "Error: $RADIX_EXE is not executable"
    exit 1
fi

total_positive=0
passed_positive=0
total_negative=0
passed_negative=0

run_positive_test() {
    local src_radix="$1"
    local dest_radix="$2"
    local value="$3"
    local expected="$4"
    local description="$5"

    ((total_positive++))
    echo -n "TEST: $description ... "

    local output
    output=$("$RADIX_EXE" "$src_radix" "$dest_radix" "$value" 2>&1)
    local exit_code=$?

    if [ $exit_code -ne 0 ]; then
        echo "FAIL (non-zero exit code: $exit_code)"
        return
    fi

    if [ "$output" = "$expected" ]; then
        echo "PASS"
        ((passed_positive++))
    else
        echo "FAIL (expected '$expected', got '$output')"
    fi
}

run_negative_test() {
    local src_radix="$1"
    local dest_radix="$2"
    local value="$3"
    local expected_error="$4"
    local description="$5"

    ((total_negative++))
    echo -n "TEST: $description ... "

    local output
    output=$("$RADIX_EXE" "$src_radix" "$dest_radix" "$value" 2>&1)
    local exit_code=$?

    if [ $exit_code -eq 0 ]; then
        echo "FAIL (expected non-zero exit code)"
        return
    fi

    echo "PASS"
    ((passed_negative++))
}

echo "==================== POSITIVE TESTS ===================="

run_positive_test 10 10 "123" "123" "Decimal to decimal"
run_positive_test 16 10 "1F" "31" "Hex to decimal"
run_positive_test 2 10 "101" "5" "Binary to decimal"
run_positive_test 36 10 "Z" "35" "Base36 to decimal"
run_positive_test 10 16 "31" "1F" "Decimal to hex"
run_positive_test 10 36 "35" "Z" "Decimal to base36"
run_positive_test 16 2 "F" "1111" "Hex to binary"
run_positive_test 2 16 "1111" "F" "Binary to hex"
run_positive_test 20 15 "A" "A" "Base20 to base15 (same digit)"
run_positive_test 10 35 "34" "Y" "Decimal to base35"

run_positive_test 10 10 "-123" "-123" "Negative decimal"
run_positive_test 16 10 "-1F" "-31" "Negative hex"
run_positive_test 36 10 "-Z" "-35" "Negative base36"
run_positive_test 10 16 "-31" "-1F" "Negative to hex"
run_positive_test 10 36 "-35" "-Z" "Negative to base36"

MAX_INT="2147483647"
MIN_INT="-2147483648"
run_positive_test 10 16 "$MAX_INT" "7FFFFFFF" "MAX_INT to hex"
run_positive_test 16 10 "7FFFFFFF" "$MAX_INT" "Hex to MAX_INT"
run_positive_test 10 16 "$MIN_INT" "-80000000" "MIN_INT to hex"
run_positive_test 16 10 "-80000000" "$MIN_INT" "Hex to MIN_INT"
run_positive_test 10 36 "$MAX_INT" "ZIK0ZJ" "MAX_INT to base36"
run_positive_test 36 10 "ZIK0ZJ" "$MAX_INT" "Base36 to MAX_INT"
run_positive_test 10 36 "$MIN_INT" "-ZIK0ZK" "MIN_INT to base36"
run_positive_test 36 10 "-ZIK0ZK" "$MIN_INT" "Base36 to MIN_INT"

echo "==================== NEGATIVE TESTS ===================="

# Недопустимые основания СС
run_negative_test 1 10 "123" "Invalid radix" "Invalid source radix (1)"
run_negative_test 37 10 "123" "Invalid radix" "Invalid source radix (37)"
run_negative_test 10 1 "123" "Invalid radix" "Invalid dest radix (1)"
run_negative_test 10 37 "123" "Invalid radix" "Invalid dest radix (37)"

# Переполнение положительных чисел
run_negative_test 10 10 "2147483648" "Overflow" "Positive overflow (MAX_INT+1)"
run_negative_test 10 10 "9999999999" "Overflow" "Large positive overflow"
run_negative_test 16 10 "80000000" "Overflow" "Hex positive overflow"

# Переполнение отрицательных чисел
run_negative_test 10 10 "-2147483649" "Overflow" "Negative overflow (MIN_INT-1)"
run_negative_test 10 10 "-9999999999" "Overflow" "Large negative overflow"
run_negative_test 16 10 "-80000001" "Overflow" "Hex negative overflow"

# Некорректные символы в числах
run_negative_test 10 10 "12A3" "Invalid character" "Invalid char in decimal"
run_negative_test 16 10 "1G" "Digit exceeds radix" "Invalid char in hex"
run_negative_test 10 10 "12_3" "Invalid character" "Underscore in number"
run_negative_test 10 10 "" "Empty string" "Empty input string"

echo "===================== TEST SUMMARY ====================="
echo "Positive tests: $passed_positive/$total_positive passed"
echo "Negative tests: $passed_negative/$total_negative passed"
echo "Total tests: $((total_positive + total_negative))"
echo "Total passed: $((passed_positive + passed_negative))"

# Возвращаем код ошибки, если есть непройденные тесты
if [ $passed_positive -ne $total_positive ] || [ $passed_negative -ne $total_negative ]; then
    exit 1
fi