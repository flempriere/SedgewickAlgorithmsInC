/**
 * @file ex3_58.c
 * @author Felix Lempriere
 * @brief Exercise 3.58
 *
 * Assuming that memory for strings is individually allocated.
 * Write a version of `strcpy` and `strcat` that allocate
 * memory and return a pointer to the new string for the result
 * @version 0.1
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Copies src into dest, allocating dest
 * as new memory. a pointer to dest is returned.
 *
 * @param src string to copy
 * @param dest pointer to memory to be copied into
 * @return char* pointer to new copy
 */
char* my_strcpy(char* dest, char const* src);

/**
 * @brief Concatenates the s1 and s2 string. New
 * memory is allocated for the concatenated string
 * and returned as a pointer
 *
 * @param s1 first part of the concatenated string
 * @param s2  second part of the concatenated string
 * @return char* pointer to concatenated string
 */
char* my_strcat(char const* s1, char const* s2);
/**
 * @brief Tests implementation of my_strcat and
 * my_strcpy by reading in a string from command line,
 * creating a copy then concatenating the copy and the
 * original.
 *
 * @param argv[1] string to analyse
 * @return EXIT_SUCCESS on successful completion else EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Usage %s input_string\n", argv[0]);
        return EXIT_FAILURE;
    }
    printf("Input string: %s\n", argv[1]);
    register char* dest = nullptr;
    dest = my_strcpy(dest, argv[1]);
    printf("Copied string: %s\n", dest);
    register char* concat = my_strcat(dest, argv[1]);
    printf("Concatenated string: %s\n", concat);

    free(dest);
    free(concat);

    return EXIT_SUCCESS;
}

char* my_strcpy(char* dest, char const* src) {
    dest = calloc(strlen(src) + 1, SIZEOF_VARTYPE(*src));
    char* h = dest;
    while ((*dest++ = *src++));
    return h;
}

char* my_strcat(char const* s1, char const* s2) {
    // allocate string
    register size_t len = strlen(s1) + strlen(s2) + 1;
    register char* concat_str = calloc(len, SIZEOF_VARTYPE(*s1));
    register char* h = concat_str;

    // copy strings
    while ((*concat_str++ = *s1++));
    concat_str--;    // overwrite the s1 null-terminator
    while ((*concat_str++ = *s2++));
    return h;
}