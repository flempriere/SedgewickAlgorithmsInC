# SedgewickAlgorithmsInC

A collection of exercises to Sedgewicks Algorithms in C, Third Edition.

## Motivation

These solutions have been written for my own learning and interest. They
have been made public in the case that others may find them useful.

Additionally they have been written with the C23 standard in mind to
explore the new standard, though they should not heavily rely on the
features provided.

## Structure

This code base has been broken down by Chapter, and further subdivided
into

1. Examples - Code fragments provided by the author
2. Exercises - Solutions to Exercises

Each Chapter has a markdown file `index.md` to describe the exercises
contained within. This file may also contain solutions to mathematical
exercises. Where useful each chapter may be further subdivided
into different sections such as `Chapter 3`, where `Arrays`, `Linked Lists`
and `Strings` are treated as their own components.

In addition there are the following extra folders
1. [Tools](./Tools/) - Contains extra tooling for managing the project. This includes scripts and make files used for building and maintaining the project.
2. [MacroLibrary](./MacroLibrary/) - Contains useful repeated code fragments and macro features that are used
across the exercises. For example we typically use the `CAST()` macro from `Utility.h` to make casts explicit
and hence easier to search for.
3. [Interfaces](./Interfaces/) - Contains symbolic links to the interfaces and implementations of various Data Types. This makes it easier to find headers and implementations both in the build and when writing since they
can be buried in various different exercises.
### Contents

#### Fundamentals

1. [Chapter 1](./Chapter1/index.md) Introduction
2. [Chapter 2](./Chapter2/index.md) Principles of Algorithm Analysis

#### Data Structures

3. [Chapter 3](./Chapter3/index.md) Elementary Data Structures
4. [Chapter 4](./Chapter4/index.md) Abstract Data Types

## Portability and Building Solutions

These programs have been compiled on Ubuntu LTS 24.04 using GCC 14.

All programs have been compiled with the C23 standard and may make use of
some features unique to that standard. Most commonly this is through the
use of `nullptr` in place of `NULL` and the keywords `bool`, `false` and
`true` without the use of the header `stdbool.h`. Programs may require
modification to run on older standards.

Most of the examples and exercises have a makefile that I used to compile
the programs on my computer. Most of these were generated and with
a series of makefiles based off a [template](./Tools/Build/Templates/1.0.0/MakefileTemplate).
These makefiles were also maintained with a series of scripts, the most useful of
which is probably [makeAll](./Tools/Build/makeAll.sh) which can be used to build
all of the exercises at once. As I add needed functionality to these scripts I may consider
a [README.md](./BuildTemplateAndScripts/README.md) to document them, otherwise just read the script.

All the scripts and Templates are in the folder [Build](./Tools/Build).

## Code Conventions and Style

The coding convention style we use largely follows that of [Modern C](https://gustedt.gitlabpages.inria.fr/modern-c/) by Jens Gustedt. This style guide was chosen for its emphasis on modern, safe, and maintainable practices in C programming, which align well with the goals of this project. The main considerations being:

### Style Conventions
1. Prefix notation for code blocks ( an opening `{` is at the end of the line.)
2. We bind type modifiers and qualifiers to the left. (e.g. `char const* const u`) is
   a constant pointer to a constant char.
3. Functions are written with no space between the function and the brackets e.g. `function()` while keywords have a space e.g. `if ()`.
4. A ternary expression has a space around the `?` and `:`.
5. Punctuation, (:, ;, and ,) have no space before and one or a newline after.
6. We avoid continued declarations due to issues of the form `int* a, b` (here `a` is an `int*` but `b` is an `int`)
7. We favour `constexpr` and `inline` functions over Macros where possible.
    1. `inline` function parameters must be `namespaced` by their header to prevent collisions e.g. `inline HEADERf(int HEADERx)`.
8. We use `const` where relevant for *read-only* features.
9. We declare global variables and local functions in implementation files with the `static` keyword.
10. We use the following syntax for functions that receive array/pointer parameters.
    - `f(int x[static 1])` indicates `f` receives a
    valid pointer `x` and will access at least one element.
    - `f(int len, int x[len+1])` indicates `f` receives a pointer to an array of length `len+1` that may be null.
11. We use function notation for function pointers.
    - For non-null function pointers write `f(void handler(void))`
    - if potentially null: `f(void (*handler) (void))`.
12. We declare non-array local variables as `register` where we do not need their address. 

### Naming
We use the following naming conventions:

1. We do not used **reserved** names given by the following rules of the `C` standard.
    1. Names starting with an underscore following by a second underscore or a capital letter.
        - These are reserved for language extensions or internal use.
    2. Names starting with an underscore are reserved for file scope identifiers and for `enum`, `struct` and `union` tags.
    3. Macros and `constexpr` constants have all-caps names
    4. All identifiers with predefined meaning, are reserved and cannot be used in file scope. This includes:
        - `C` library functions,
        - all identifiers starting with `str`
        - all identifiers starting with `E` (reserved for error codes)
        - identifers ending in `_t`
            - Critically this means we do not follow the convention of labelling structs as `struct x_t` etc.
        - For a complete list see [here](https://www.gnu.org/software/libc/manual/html_node/Reserved-Names.html).
2. We prefix functions, types, enum values and macros with the name of the header or enum in all upper case. e.g. `Queue.h -> QUEUEinit.
    1. An exception is for Macros that provide default argument interfaces to existing standard library functions, in this case the Macro must be an all capitals one-to-one copy of the name. e.g. the default arguments version
    of `calloc` is `CALLOC`.
3. functions and variables are named according to
    1. *small* functions and local variables have **short** names, or abbreviations, e.g. `i` not `loop_counter`.
    2. *large* or important functions and global variables have **descriptive** names.
    3. `snake_case` is used for variables and functions.
4. `enum` values are written in all caps as they are *constants*.
5. `Struct` are written in `CamelCase` with all words initialised.
6. For an Abstract Data Type (ADT) the interface `.h` will be named as for the type in `CamelCase`.
    - Where we use a struct to implement the ADT it should be typedefed to have the same name as the interface.
    - Implementations `.c` should have the same name as the ADT a description of the implementation, and any extra factors in the format `ADT_ImplementationType_ExtraFactors`. 
        - e.g. An Index Set Queue implemented using a List and a forget the Old duplicates policy should use the name `IndexSetQueue_List_ForgetOldDuplicates.c` even if it uses the `IndexSetQueue.h` interface. But the resulting IndexSetQueue ADT would be typedefed as `IndexSetQueue`. 

## Use of A.I Tools

Github Copilot has been used sparingly in this project. It's use has been restricted to the following cases
1. Autocomplete of short code fragments
2. Assistance generating Doxygen comment blocks

Since the whole point of this project is to learn Data Structures and Algorithms from first principles, there's
not much value in getting an A.I to do all the hard work!
