/**
 * @file ex3_60.c
 * @author Felix Lempriere
 * @brief Write a program that replaces substrings of more
 * than one blank in a given string by exactly one blank;
 * @version 0.1
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Replace all repeated blank substrings by
 * a single blank string.
 *
 * @param s
 */
void condense_multiple_blanks(char* s);
/**
 * @brief Replaces substrings of blanks by a single blank.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Usage %s input_string\n", argv[0]);
        return EXIT_FAILURE;
    }
    // scan backwards, this reduces the number of copies
    // performed for successive long blanks
    printf("Input string: %s\n", argv[1]);
    condense_multiple_blanks(argv[1]);
    printf("Condensed string: %s\n", argv[1]);
    return EXIT_SUCCESS;
}

void condense_multiple_blanks(char* s) {
    register char* sp = s;
    while (*s != '\0') {
        while (isblank(*s) && isblank(*(s + 1))) s++;
        *sp++ = *s++;
    }    // ignore all but the last blank.
    *sp = '\0';
}