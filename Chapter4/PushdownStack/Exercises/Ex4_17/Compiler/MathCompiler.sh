#!/bin/bash

#need to supply in_file name and the outfile_name
if [ $# -ne 2 ]; then
    printf "Usage: %s in_file out_file\n" "$0" >&2
    exit 1
fi

cwd=$(pwd)

in_file=$1
out_file=$2

parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd $parent_path

dependencies=dependencies
header=$dependencies/head.partial
tail=$dependencies/tail.partial
executable=$dependencies/transpiler.exe
transpiler=$dependencies/transpiler.c
transpiledfile=out.partial
compile="gcc-14 -std=c23 -O -o"

in_file=$cwd/$in_file
out_file=$cwd/$out_file

#check for the partial header file
if [ ! -f $header ]; then
    printf "Error: missing header file in %s\n" "$header" >&2
    exit 1
fi

#check for the partial tail file
if [ ! -f $tail ]; then
    printf "Error: missing tail file in %s\n" "$tail" >&2
    exit 1
fi

#check that the transpiler is compiled
#if not try to compile it from transpiler.c

if [ ! -f $executable ]; then
    printf "Error: missing executable %s\n" "$executable" >&2
    printf "Attempting to compile\n" >&2
    if [! -f $transpiler]; then
        printf "Error: missing transpilation file in %s\n" "$executable" ? >&2
        exit 1
    fi
    $compile $executable $transpiler
    if [ ! -f $executable ]; then
    printf "Failed to compile\n" >&2
    exit 1
    fi
fi

touch $out_file.c
true > $out_file.c 

if [ ! -f "$out_file.c" ]; then
    echo "Error: failed to create intermediate file $out_file.c" >&2
    exit 1
fi

#attempt to transpile
./$executable $in_file

cat $header >> $out_file.c
cat $transpiledfile >> $out_file.c
cat $tail >> $out_file.c

$compile $out_file $out_file.c -lm

#clean up
rm $transpiledfile $out_file.c