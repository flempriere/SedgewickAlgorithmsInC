#!/bin/bash

##########################################################
# Simple Script to find and run all Makefiles            #
# Usage: ./makeAll [directory] [--target] [--buildMode]  #    
##########################################################

# Constants
USAGE_STRING="[[[ -d, --dir, --directory directory ] [-i, --interactive] [-c, --clean]] | [-h]]"

# functions

# generic help output
usage_output () {
    printf "Usage: %s ${USAGE_STRING}\n" "$0" >&$1
    printf "Valid builds are %s\n" "$validModes"
    printf "Use argument help to see this message again\n"
}

# help on stdout
display_help () {
    usage_output 1
    exit 0
}

#display invalid build mode option
display_invalid_build_option () {
    printf "Invalid build mode %s encountered\n" "$buildMode" >&2
    usage_output 2
}

#checks that input build mode is valid and exits if not.
validate_build_option ( ) {
    if [[ ! " ${validModes[*]} " =~ [[:space:]]${buildMode}[[:space:]] ]]; then
        display_invalid_build_option
    fi    
}

#find the makefiles and execute the build
find_and_build () {
    printf "=== Building with Mode: %s ===\n" "$buildMode" >&1 
    find $directory -type d -name BuildTemplateAndScripts -prune -o -name Makefile -print -execdir make ${clean} BUILD=${buildMode} \;
}



request_search_directory () {
    response=
    read -p " Enter Top-level Search Directory [$directory] > " response
    if [ -n "$response" ]; then
        directory="$response"
    fi
}

request_build_mode () {
    response=
    read -p " Enter buildMode [$buildMode] > " response
    if [ -n "$response" ]; then
        buildMode="$response"
    fi
}

request_clean () {
    response=
    read -p "Clean? [Enter clean or y, otherwise script will build] >" response
    if [ -n $response ]; then
        case $response in
            Clean | clean | y | yes )   clean=clean
                                        ;;
            *   )                       clean=
                                        ;;
        esac
        check_proceed
    fi
}           

check_proceed () {
    proceed=
    printf "%s. Proceed (y/n) > " "$1"
    read proceed
    if [ "$proceed" != "y" ]; then
        echo "Exiting Program."
        exit 1
    fi
}

########
# Main #
########

# Settings up some variables
validModes=("debug" "release") #valid options for setting the build mode
buildMode="debug"  # default build mode
interactive= #indicates if shell to be called in interactive mode
clean= #indicates if cleaning or not
directory="$( dirname -- "${BASH_SOURCE[0]}" )"/.. #default directory


# Process command line arguments

while [ "$1" != "" ]; do
    case $1 in
        -d | --dir | --directory )  shift
                                    directory=$1
                                    ;;
        -c | --clean )              clean=clean
                                    ;;
        -i | --interactive )        interactive=1
                                    ;;
        -h | --help )               display_help
                                    ;;
        * )                         usage_output
                                    exit 1
                                    ;;
    esac
    shift
done

if [[ "$buildMode" == "help" ]]; then
    display_help
fi

if [ "$interactive" == "1" ]; then
    request_search_directory
    if [ -d "$directory" ]; then
        check_proceed "Directory exists"
    fi
    request_build_mode
    if validate_build_option; then
        check_proceed "Valid Build Mode selected"
    fi
    request_clean
fi

if ! validate_build_option; then
    exit 
fi

find_and_build
