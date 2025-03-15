#!/bin/bash

if [ $# -lt 1 ]; then
    printf "Usage: %s n_tests\n" "$0" >&2
    exit 1
fi

n_tests=$1
executable=debug/ex3_75

output_file=$executable.dat
touch $output_file

#generate case number
today=$(date +%Y%m%d)
number=0
dirname=$today

while [ -e "tests/$dirname" ];
do
    printf -v dirname '%s-%02d' "$today" "((++number))"
done

for i in $(seq 0 $((n_tests - 1)));
do
    echo Test Case $i >> $output_file
    ./$executable.exe >> $output_file
    sleep 1 #sleep to ensure seed is different enough
done

#clean up
mkdir "tests/$dirname"
mv $output_file "tests/$dirname"