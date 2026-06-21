#!/bin/bash

echo "================ APC TEST START ================"

run_test() {
    expected="Result: $1"
    shift
    output=$(./apc "$@" 2>&1)

    if [ "$output" == "$expected" ]; then
        echo "✅ PASS: ./apc $* → $output"
    else
        echo "❌ FAIL: ./apc $* → Got: $output | Expected: $expected"
    fi
}

echo "---- BASIC ----"
run_test "15" 10 + 5
run_test "5" 10 - 5
run_test "50" 10 x 5
run_test "2" 10 / 5

echo "---- ZERO ----"
run_test "0" 0 + 0
run_test "123" 0 + 123
run_test "123" 123 + 0
run_test "-123" 0 - 123
run_test "123" 123 - 0
run_test "0" 0 x 999
run_test "0" 999 x 0
run_test "0" 0 / 5

echo "---- DIVISION ----"
run_test "3" 10 / 3
run_test "0" 3 / 10
run_test "10" 100 / 10
run_test "14" 100 / 7

echo "---- SAME NUM ----"
run_test "200" 100 + 100
run_test "0" 100 - 100
run_test "10000" 100 x 100
run_test "1" 100 / 100

echo "---- NEGATIVE ----"
run_test "-5" -10 + 5
run_test "5" 10 + -5
run_test "-15" -10 + -5

run_test "-15" -10 - 5
run_test "15" 10 - -5
run_test "-5" -10 - -5

run_test "-50" -10 x 5
run_test "-50" 10 x -5
run_test "50" -10 x -5

run_test "-2" -10 / 5
run_test "-2" 10 / -5
run_test "2" -10 / -5

echo "---- BORROW ----"
run_test "999" 1000 - 1
run_test "1" 1000 - 999
run_test "1" 100 - 99
run_test "9999" 10000 - 1

echo "---- CARRY ----"
run_test "1000" 999 + 1
run_test "10008" 9999 + 9
run_test "10000" 1 + 9999

echo "---- MULTIPLY ----"
run_test "9801" 99 x 99
run_test "56088" 123 x 456
run_test "1000000" 1000 x 1000

echo "---- LARGE ----"
run_test "1000000000000000000" 999999999999999999 + 1
run_test "999999999999999998" 999999999999999999 - 1
run_test "1111111102111111101" 123456789123456789 x 9
run_test "333333333333333333" 999999999999999999 / 3

echo "---- LEADING ZERO ----"
run_test "130" 000123 + 0007
run_test "99" 00100 - 0001

echo "================ APC TEST END ================"