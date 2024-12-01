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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Copies src into dest, allocating dest
 * as new memory. a pointer to dest is returned.
 * 
 * @param src string to copy
 * @param dest pointer to memory to be copied into
 * @return char* pointer to new copy
 */
char* my_strcpy(char* dest, char* src);

/**
 * @brief Concatenates the dest and src string. New
 * memory is allocated for the concatenated string
 * and returned as a pointer
 * 
 * @param dest first part of the concatenated string
 * @param src  second part of the concatenated string
 * @return char* pointer to concatenated string
 */
char* my_strcat(char* dest, char* src);
/**
 * @brief Tests implementation of my_strcat and
 * my_strcpy by reading in a string from command line,
 * creating a copy then concatenating the copy and the
 * original.
 * 
 * @param argv[1] string to analyse 
 * @return EXIT_SUCCESS on successful completion else EXIT_FAILURE
 */
int main(int argc, char* argv[argc+1]) {

    if (argc != 2) {
        fprintf(stderr, "Error: Usage %s input_string\n", argv[0]);
        return EXIT_FAILURE;
    }
    printf("Input string: %s\n", argv[1]);
    char* dest = nullptr;
    dest = my_strcpy(dest, argv[1]);
    printf("Copied string: %s\n", dest);
    char* concat = my_strcat(dest, argv[1]);
    printf("Concatenated string: %s\n", concat);

    return EXIT_SUCCESS;
}

char* my_strcpy(char* dest, char* src) {
    dest = malloc((strlen(src) + 1)*sizeof(typeof(*src)));
    char* h = dest;
    while ((*dest++ = *src++));
    return h;
}

char* my_strcat(char* dest, char* src) {

    //allocate string
    size_t len = strlen(dest) + strlen(src) + 1; 
    char* concat_str = malloc(len*sizeof(typeof(*dest)));
    char* h = concat_str;

    //copy strings
    while ((*concat_str++ = *dest++));
    concat_str--;
    while((*concat_str++ = *src++));
    return h;
}