#######################################
# Wrapper script to Manage make files #
#######################################


#Currently supported functionality
################################################################
# Find any directory of the form ExX_* that contains a .c file #
# and generate a makefile for it.                              #
################################################################

if [ $# -ne 1 ]; then
    printf "Error: Usage %s search_directory\n" "$0" >&2
    exit 1
fi

directory=$1
createMakeScript="createMakeFile.sh"
createMakeScriptPath="$( dirname -- "${BASH_SOURCE[0]}" )/${createMakeScript}"
regex=".*[Ex|Program][0-9]+_[0-9]+[^\s\/]*\/[^\s\/]*\.c"

if [ ! -d "${directory}" ]; then
    printf "Error: %s is not a directory\n" "$directory" >&2
    exit 1
fi

find $directory -regex ${regex} -print0 | xargs -0 dirname | xargs ./createMakeFile.sh