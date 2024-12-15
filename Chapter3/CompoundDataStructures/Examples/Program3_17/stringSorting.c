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
#include <stdint.h>
#include <ctype.h>

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
char* bufp = buf;

/**
 * @brief Used to store input
 * before filtering into buffer
 */
char inputbuf[Mmax];
/**
 * @brief Total number of input characters read
 * so far.
 * 
 */
int M = 0;

/**
 * @brief string comparison function wrapper for qsort
 */
int compare(const void *i, const void *j);

/**
 * @brief Extract a space seperated word
 * for the @src string and copy it into
 * at most @destSize - 1 characters into
 * @dest null terminating the string. Trailing
 * newlines are removed.
 * 
 * @param src source string
 * @param destSize size of the destination buffer
 * @param dest destination buffer
 * 
 * @return number of characters copied, including the null-terminator
 * on success else SIZE_MAX.
 * 
 */
size_t extractWord(char* src, size_t destSize, char dest[destSize]);

int main(int argc, char* argv[argc]) {
    char* a[Nmax];
    size_t N = 0;
    size_t Mremaining = Mmax;
    for (N = 0; N < Nmax && Mremaining;) {
        if(fgets(inputbuf, Mremaining, stdin)) {
            char* inputbufp = inputbuf;
            size_t len;
            while ((len = extractWord(inputbufp, Mremaining, bufp)) 
                != SIZE_MAX) {
                a[N] = bufp;
                inputbufp += len;
                bufp += len;
                Mremaining -= len;
                N++;
                if (N >= Nmax || !Mremaining) break;
            }
        } else break;
    }
    qsort(a, N, sizeof(char*), compare);
    for (size_t i = 0; i < N; i++) printf("%s\n", a[i]);

    return EXIT_SUCCESS;
}

int compare(const void *i, const void* j) {
    return strcmp(*(char **)i, *(char **)j);
}

size_t extractWord(char* src, size_t destSize, char dest[destSize]) {
    if (!(*src)) return SIZE_MAX; //null terminator
    size_t len = 0;
    for (; len < destSize - 1; len++) {
        if (isblank(*src) || *src == '\n') {
            src++;
            break;
        }
        *dest++ = *src++;
    }
    *dest = '\0';
    return len + 1;
}