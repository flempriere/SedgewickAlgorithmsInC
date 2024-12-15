#!/bin/bash

if [ $# -lt 2 ]; then
    printf "Usage: %s n_tests n_points\n" "$0" >&2
    exit 1
fi

n_tests=$1
n_points=$2
executable=program3_20

output_file=$executable.dat
touch $output_file


for i in $(seq 1 $((n_tests)));
do
    d=$(echo "1/($i)" | bc -l)
    echo "Test Case $i: N = $n_points, d = $d" >> $output_file
    (./$executable.exe $n_points $d) >> $output_file
done