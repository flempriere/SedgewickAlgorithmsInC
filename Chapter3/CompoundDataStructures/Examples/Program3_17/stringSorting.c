/**
 * @file stringSorting.c
 * @brief This program illustrates an important
 * string processing-function: rearranging a set of
 * strings into sorted order. We read strings into
 * a buffer large enough to hold them all, maintaining
 * a pointer to each string in an array, then rearrange
 * the the pointers to put the pointer to the smallest
 * string in the first position etc. 
 * 
 * We make use of the library function qsort.
 * @version 0.1
 * @date 2024-12-01
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Maximum number of individual strings
 * 
 */
#define Nmax 1000

/**
 * @brief size of the buffer that stores all the
 * strings. The length of all strings including
 * null-terminators must be <= Mmax
 */
#define Mmax 10000

/**
 * @brief String buffer
 * 
 */
char buf[Mmax];

/**
 * @brief Used to store input
 * before filtering into buffer
 */
char inputbuf[Mmax];

/**
 * @brief First free index in the buffer
 * 
 */
int M = 0;

/**
 * @brief string comparison function wrapper for qsort
 */
int compare(const void *i, const void *j);

int main(int argc, char* argv[argc]) {
    char* a[Nmax];
    size_t N = 0;
    for (N = 0; N < Nmax; N++) {
        a[N] = &buf[M];
        if (scanf("%s", a[N]) == EOF) break;
        M += strlen(a[N]) + 1;
    }
    qsort(a, N, sizeof(char*), compare);
    for (size_t i = 0; i < N; i++) printf("%s\n", a[i]);

    return EXIT_SUCCESS;
}

int compare(const void *i, const void* j) {
    return strcmp(*(char **)i, *(char **)j);
}