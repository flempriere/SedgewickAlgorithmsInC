#!/bin/bash

##########################################################
# Simple Script to find and run all Makefiles            #
# Usage: ./makeAll [directory] [--target] [--buildMode]  #    
##########################################################

# Constants
USAGE_STRING="[[[ -d, --dir, --directory directory ] [-i, --interactive] [-t, --target]] | [-h]]"

# functions

# generic help output
usage_output () {
    printf "Usage: %s ${USAGE_STRING}\n" "$0" >&$1
    printf "Valid builds are %s\n" "${validModes[*]}"
    printf "Valid targets are %s\n" "${validTargets[*]}"
    printf "Use argument --help or -h to see this message again\n"
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

display_invalid_target_option () {
    printf "Invalid target mode %s encountered\n" "$target" >&2
    usage_output 2
}

#checks that input build mode is valid and exits if not.
validate_build_option ( ) {
    [[ " ${validModes[*]} " =~ [[:space:]]${buildMode}[[:space:]] ]]
}

validate_target_option () {
    [[ -z "$target" || " ${validTargets[*]} " =~ [[:space:]]${target}[[:space:]] ]]
}

#find the makefiles and execute the build
find_and_build () {
    printf "=== Building with Mode: %s ===\n" "$buildMode" >&1 
    find $directory -type d -name BuildTemplateAndScripts -prune -o -name Makefile -print -execdir make ${target} BUILD=${buildMode} \;
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

request_target () {
    response=
    read -p "Enter target [$target] >" response
    if [ -n $response ]; then
        target=$response
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

validTargets=("clean" "distribute" "diff")
target= #indicates the build target
directory="$( dirname -- "${BASH_SOURCE[0]}" )"/.. #default directory


# Process command line arguments

while [ "$1" != "" ]; do
    case $1 in
        -d | --dir | --directory )  shift
                                    directory=$1
                                    ;;
        -t | --target )             shift
                                    target=$1
                                    ;;
        -i | --interactive )        interactive=1
                                    ;;
        -h | --help )               display_help
                                    ;;
        * )                         usage_output 2
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
    else
        echo "Directory does not exist"
        echo "Exiting Program"
        exit 1
    fi
    request_build_mode
    if  validate_build_option ; then
        check_proceed "Valid Build Mode selected"
    else
        display_invalid_build_option  
        echo "Exiting Program"
        exit 1
    fi
    request_target
    if validate_target_option; then
        check_proceed "Valid Target selected"
    else
        display_invalid_target_option
        echo "Exiting Program"
        exit 1
    fi
else
    if ! validate_build_option || ! validate_target_option; then
        usage_output 2
        exit 1
    fi
fi

find_and_build
