#!/bin/bash

# A shell script which given a list of directories
# generates a make file in that directory set to
# build the exe directory.exe and given the project
# title directory.


get_dirname () {
    tmpDir=$( cd "$1"; pwd)
    tmpDir="${tmpDir%/}" 
    echo "${tmpDir##*/}"
}

set_default_makefile_variables ( ) {
    today=$(date +%Y-%m-%d)
    HEADER_DIR=". ./includes"
    SOURCE_DIR=". ./src"
    SOURCE_VPATHS=
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
}

create_from_template () {
    sed -e "s@{%DATE_GENERATED%}@$today@g" \
    -e "s@{%HEADER_DIR%}@$HEADER_DIR@g" \
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

if [ $# -lt 1 ]; then
    printf "Usage: %s directory1 directory2 ... \n" "$0" >&2
    exit 1
fi

version="1.0.0"
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
templateFile="MakefileTemplate"
templatePath="${SCRIPT_DIR}/Templates/${version}/${templateFile}"

# set variables that don't change per file.
set_default_makefile_variables

while [ "$1" != "" ]; do
    directory="$1"
    shift

    if [ ! -d "$directory" ]; then
        printf "Error: ${directory} is not a directory\n" >&2
        continue
    fi
    baseDirectory=$( get_dirname ${directory} )
    echo "${baseDirectory}"

    #set file and project name
    PROJECT="${baseDirectory,,}" #make lower case 
    EXE="$PROJECT.exe"

    # use sed to perform variable replacement
    create_from_template
done