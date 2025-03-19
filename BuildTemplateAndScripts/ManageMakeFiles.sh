#!/bin/bash

# A shell script to manage the following:
# Make a make file in a given directory 
# TODO: Update a variable for all make files in a dir
# TODO: Update the template for all make files in a directory
# preserving current variable settings.
replace_variables () {
    sed -e "s@{%HEADER_DIR%}@$HEADER_DIR@g" \
    -e "s@{%SOURCE_DIRS%}@$SOURCE_DIR@g" \
    -e "s@{%SOURCE_VPATHS%}@$SOURCE_VPATH@g" \
    -e "s@{%PROJECT%}@$PROJECT@g" \
    -e "s@{%EXE%}@$EXE@g" \
    -e "s@{%CEXTRA%}@$CEXTRA@g" \
    -e "s@{%COMPILER%}@$COMPILER@g" \
    -e "s@{%STANDARD%}@$STD@g" \
    -e "s@{%OPT_debug%}@$OPT_debug@g" \
    -e "s@{%OPT_release%}@$OPT_release@g" \
    -e "s@{%FLAGS_warning%}@$FLAGS_warning@g" \
    -e "s@{%FLAGS_address%}@$FLAGS_address@g" \
    -e "s@{%FLAGS_dependencies%}@$FLAGS_dependencies@g" \
    -e "s@{%FLAGS_release%}@$FLAGS_release@g" \
    -e "s@{%FLAGS_debug%}@$FLAGS_debug@g" \
    -e "s@{%FLAGS_linker%}@$FLAGS_linker@g" \
    "$templatePath" > "${directory}/Makefile"
}

if [ $# -ne 1 ]; then
    printf "Usage: %s directory\n" "$0" >&2
    exit 1
fi

directory=$1
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
templateFile="MakefileTemplate"
templatePath="${SCRIPT_DIR}/${templateFile}"

tmpdir="${directory%/}" 
baseDirectory="${tmpdir##*/}"

if [ ! -d "$directory" ]; then
    printf "Error: ${directory} is not a directory\n"
    exit 1
fi

#set variables

HEADER_DIR=". ./includes"
SOURCE_DIR=". ./src"
SOURCE_VPATHS=

PROJECT="$baseDirectory" 
EXE="$PROJECT.exe"
CEXTRA=

COMPILER="gcc-14"
STD="-std=c23"

OPT_debug="-O"
OPT_release="-O2"

FLAGS_warning="-Wall -Werror -Wextra -Wpedantic -Wno-unused-parameter\
    -Wconversion"
FLAGS_address="-fsanitize=address,undefined"

FLAGS_dependencies="-MP -MD"

FLAGS_release="-g -march=native"
FLAGS_debug="-g3"

FLAGS_linker=

# use sed to perform variable replacement
# get script directory
replace_variables
