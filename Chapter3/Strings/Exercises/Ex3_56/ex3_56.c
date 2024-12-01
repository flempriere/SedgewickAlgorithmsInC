/**
 * @file ex3_56.c
 * @author Felix Lempriere
 * @brief Exercise 3.56
 * 
 * Write a program that takes a string as an argument and
 * prints out a table giving, for each character that appears
 * in the string, the character and frequency of occurence.
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Takes a string as an argument and
 * prints out a table giving, for each character that appears
 * in the string, the character and frequency of occurence.
 * 
 * @param argv[1] string to analyse 
 * @return EXIT_SUCCESS on successful completion else EXIT_FAILURE
 */
int main(int argc, char* argv[argc+1]) {

    if (argc != 2) {
        fprintf(stderr, "Error: Usage %s input_string\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t characters[CHAR_MAX] = {}; //allocates array as all 0
    
    for (unsigned char* p = (unsigned char*) argv[1]; *p; p++) characters[*p]++;

    for (unsigned char i = 0; i < CHAR_MAX; i++) {
        if (characters[i]) printf("%c : %zu\n", i, characters[i]);
    }
    return EXIT_SUCCESS;
}