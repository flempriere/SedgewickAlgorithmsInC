#!/bin/bash

#Need to supply number of test cases to generate
if [ $# -lt 2 ]; then
    printf "Usage: %s n_tests n_lines\n" "$0" >&2
    exit 1
fi

n_tests=$1
n_lines=$2
executable=debug/ex3_17

#generate test files
for i in $(seq 0 $((n_tests - 1)));
do
    shuf -i 0-999 -r -n $n_lines | paste -d ' ' - - > test_$i.testdat
done

output_file=$executable.dat
touch $output_file

# generate case number
today=$(date +%Y%m%d)
number=0
dirname=$today

while [ -e "tests/$dirname" ]; 
do
    printf -v dirname '%s-%02d' "$today" "((++number))"
done

echo "Test Number $number of $today" > $output_file

for i in $(seq 0 $((n_tests - 1)));
do
    echo Test Case $i >> $output_file
    (./$executable.exe < test_$i.testdat) >> $output_file
done

#clean up
mkdir "tests/$dirname"
mkdir "tests/$dirname/test_input"
mv $executable.dat "tests/$dirname"
mv *.testdat "tests/$dirname/test_input"