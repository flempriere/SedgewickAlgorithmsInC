#!/bin/bash

compiler=../MathCompiler.sh
tests_passed=true

for i in $(seq 1 5);
do
    in_file="Test$i/test$i.math"
    out_exec="Test$i/test$i.exe"
    out_file="Test$i/test$i.out"
    comparison_file="Test$i/test$i.answer"

    $compiler $in_file $out_exec
    ./$out_exec > $out_file

    if cmp --silent -- "$out_file" "$comparison_file"; then
        echo "Test $i passed: files identical"
    else
        echo "Test $i failed: files differ"
        tests_passed=false
    fi
done

if [ "$tests_passed" = true ]; then
    echo "Tests passed"
else
    echo "Tests failed"
fi
