/**
 * @file string_search.c
 * @brief Program 3.15
 * Discovers all occurances of a word from the command line in
 * a (presumably) much larger text string. The text string is
 * a fixed-size character array, and is read in from stdin
 * 
 * For each starting position i in the text string we try to
 * match the substring, testing character by character equality.
 * If p is reached successfully, the starting position i is
 * printed out.
 * @version 0.1
 * @date 2024-12-01
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size of the text string
 * 
 */
#define N 10000

/**
 * @brief Discovers all occurances of a word from the command line in
 * a (presumably) much larger text string. The text string is
 * a fixed-size character array, and is read in from stdin
 * 
 * For each starting position i in the text string we try to
 * match the substring, testing character by character equality.
 * If p is reached successfully, the starting position i is
 * printed out.
 * 
 * @param argv[1] substring to match 
 * @return EXIT_SUCCESS on successful exit, else EXIT_FAILURE
 */
int main(int argc, char* argv[argc+1]) {

    if (argc != 2) {
        fprintf(stderr, "Error: Usage is %s substring\n", argv[0]);
        return EXIT_FAILURE;
    }
    char a[N];
    char* p = argv[1];

    //read in string
    char t ;
    size_t i = 0;
    for (; i < N - 1; a[i] = t, i++) {
        if ((t = getchar()) == EOF) break;
    }
    a[i] = 0;
    //find matches
    for (i = 0; a[i]; i++) {
        size_t j = 0;
        for (; p[j]; j++) {
            if (a[i+j] != p[j]) break;
        }
        if (!p[j]) printf("%zu ", i);
    }
    printf("\n");
    return EXIT_SUCCESS;
}