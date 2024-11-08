#!/bin/bash

#Need to supply number of test cases to generate
if [ $# -lt 1 ]; then
    printf "Usage: %s n_tests\n" "$0" >&2
    exit 1
fi

n_tests=$1
sz_file="../../Ex1_7/ex1_7.exe"
hgt_file="../ex1_20.exe"

for i in $(seq 0 $((n_tests - 1)));
do
    shuf -i 0-9999 -r -n 10000 | paste -d ' ' - - > test_$i.testdat
done

#function to calculate average time
avg_time() {
    test_executable=$1;
    echo "=====$test_executable=====" >> results.txt
    for i in $(seq 0 9);
    do
        { time -p $test_executable < test_$i.testdat  &>/dev/null; } 2>&1
    done | awk '
        /real/ { real = real + $2; nr++ }
        /user/ { user = user + $2; nu++ }
        /sys/  { sys  = sys  + $2; ns++}
        END    {
                 if (nr>0) printf("real %f\n", real/nr);
                 if (nu>0) printf("user %f\n", user/nu);
                 if (ns>0) printf("sys %f\n",  sys/ns)
               }' >> results.txt
}

touch results.txt
avg_time $sz_file
avg_time $hgt_file

#move results to storage
today=$(date +%Y%m%d)
number=0

dirname=$today
while [ -e "$fname" ]; do
    printf -v dirname '%s-%02d' "$today" "((++number))"
done

mkdir "$dirname"
mkdir "$dirname/test_input"
mv *.txt "$dirname"
mv *.testdat "$dirname/test_input"






