/**
 * @file ex3_59.c
 * @author Felix Lempriere
 * @brief Exercise 3.59
 *
 * Write a program that takes a string as an argument and
 * reads a sequence of words (sequence of characters seperated
 * by blank space) from standard input printing out those that
 * appear as substrings somewhere in the argument string.
 *
 * @version 0.1
 * @date 2024-12-01
 */

#include "../../../../MacroLibrary/Utility.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size of the text string
 *
 */
constexpr size_t N = 10000u;

/**
 * @brief Lists the starting positions for all
 * matches of the substring p in the string a
 *
 * @param a string to be searched
 * @param p pattern to match
 */
void find_matches(char const* const a, char const* const p);
/**
 * @brief Reads a sequence of words (sequence of characters seperated
 * by blank space) from standard input printing out those that
 * appear as substrings somewhere in the argument string.
 *
 * @param argv[1] string to search
 *
 * @return EXIT_SUCCESS on successful exit, else EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Usage is %s input_string\n", argv[0]);
        return EXIT_FAILURE;
    }
    char a[N];
    char const* const p = argv[1];

    // read in string
    register int t;
    register size_t i = 0;
    while ((t = getchar()) != EOF) {
        if (isblank(t) || t == '\n') {    // blank terminated word so search
            a[i] = '\0';
            find_matches(p, a);
            i = 0;
        } else {
            a[i++] = CAST(char) t;
        }
    }
    return EXIT_SUCCESS;
}

void find_matches(char const* const a, char const* const p) {
    printf("Matches for %s\n", p);
    for (register size_t i = 0; a[i]; i++) {
        register size_t j = 0;
        for (; p[j]; j++) {
            if (a[i + j] != p[j]) break;
        }
        if (!p[j]) printf("%zu ", i);
    }
    printf("\n");
}