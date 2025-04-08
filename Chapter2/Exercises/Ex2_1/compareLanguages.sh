#!/bin/bash

#Need to supply number of times to run the experiment.
if [ $# -lt 1 ]; then
    printf "Usage: %s n_tests\n" "$0" >&2
    exit 1
fi

n_tests=$1
c_file="../../../Chapter1/Exercises/Ex1_22/debug/ex1_22.exe"
py_file="unionFind.py"

#function to calculate average time
avg_time() {
    test_executable=$1;
    tests=$2;
    echo "=====$test_executable=====" >> results.txt
    for i in $(seq 0 $((tests - 1)));
    do
        echo "Test case $i"
        { time -p $test_executable &>/dev/null; } 2>&1
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

avg_time_python() {
    test_executable=$1;
    tests=$2;
    echo "=====$test_executable=====" >> results.txt
    for i in $(seq 0 $((tests - 1)));
    do
        echo "Test case i"
        { time -p python3 $test_executable &>/dev/null; } 2>&1
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
echo "Executing C code"
avg_time $c_file $n_tests
echo "Executing Python code"
avg_time_python $py_file $n_tests

#move results to storage
today=$(date +%Y%m%d)
number=0

dirname=$today
while [ -e "$dirname" ]; do
    printf -v dirname '%s-%02d' "$today" "((++number))"
done

mkdir "$dirname"
mv *.txt "$dirname"






