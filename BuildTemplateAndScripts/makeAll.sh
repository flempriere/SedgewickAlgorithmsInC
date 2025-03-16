#!/bin/bash

###############################################
# Simple Script to find and fun all Makefiles #
# Usage: ./makeAll buildMode                  #    
###############################################

validModes=("debug" "release")

usage_output () {
    printf "Usage: %s [-clean] [buildMode=debug]\n" "$0" >&$1
    printf "Valid builds are %s\n" "$validModes"
    printf "Use argument help to see this message again\n"
}

buildMode="debug"
clean=""

if [ $# -eq 1 ]; then
    if [[ ! $1 == "-clean" ]]; then
        buildMode=$1
    else
        clean="clean"
    fi  
elif [ $# -eq 2 ]; then
    if [[ ! $1 == "-clean" ]]; then
        usage_output 2
        exit 1
    fi
    clean="clean"
    buildMode=$2
fi

if [[ "$buildMode" == "help" ]]; then
    usage_output 1
    exit 0
fi

if [[ ! " ${validModes[*]} " =~ [[:space:]]${buildMode}[[:space:]] ]]; then
    printf "Invalid buildMode %s encountered\n" "$buildMode" >&2
    usage_output 2
    exit 1
fi

printf "=== Building with Mode: %s ===\n" "$buildMode" >&1 
find "$( dirname -- "${BASH_SOURCE[0]}" )"/.. -type d -name BuildTemplateAndScripts -prune -o -name Makefile -print -execdir make ${clean} BUILD=${buildMode} \;