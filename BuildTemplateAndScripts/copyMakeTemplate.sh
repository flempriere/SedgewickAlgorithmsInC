#!/bin/bash

#need to supply exe, project and extra c files
if [$# -ne 3 ]; then
    printf "Usage %s exe project \" extra c files\"" "$0" >&2
    exit 1
fi

cwd=$(pwd)
script_name="$01"
script_full_path=$(dirname "$0")

exe=$1
project=$2