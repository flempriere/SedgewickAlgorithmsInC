/**
 * @file ex3_64.c
 * @author Felix Lempriere
 * @brief Reimplements Program 3.17 but dynamically
 * allocates the memory for each string. A fixed
 * size intermediate buffer for 100 chars is used.
 * 
 * We make use of the library function qsort.
 * @version 0.1
 * @date 2024-12-16
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
 * @brief buffer storing the pointers to the
 * strings.
 * 
 */
char* buf[Nmax];

/**
 * @brief Maximum length of any input line
 * including null-terminator.
 *
 */

#define Mmax 100

/**
 * @brief Used to store input
 * before filtering into buffer
 */
char inputbuf[Mmax];
/**
 * @brief pointer to next char to be
 * read in the input buffer
 * 
 */
int M = 0;

/**
 * @brief string comparison function wrapper for qsort
 */
int compare(const void *i, const void *j);

/**
 * @brief Extract a space seperated word
 * from the @src string, copy the at most
 * @destSize - 1 characters into a newly
 * allocated buffer of max size @destSize
 * and store a pointer to the buffer in
 * @dest.
 * 
 * Trailing newlines are removed and @dest is
 * always null-terminated.
 * 
 * @param src source string
 * @param destSize size of the destination buffer
 * @param dest pointer to the newly allocated destination buffer
 * 
 * @return number of characters copied, including the null-terminator
 * on success else SIZE_MAX.
 * 
 */
size_t extractWord(char* src, size_t destSize, char** dest);

int main(int argc, char* argv[argc]) {
    char* a[Nmax];
    size_t N = 0;
    for (N = 0; N < Nmax;) {
        if(fgets(inputbuf, Mmax, stdin)) {

            char* inputbufp = inputbuf;
            size_t Mremaining = Mmax;
            size_t len;

            while ((len = extractWord(inputbufp, Mremaining, &buf[N])) 
                != SIZE_MAX) {
                a[N] = buf[N];
                inputbufp += len;
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

size_t extractWord(char* src, size_t destSize, char** dest) {
    if (!(*src)) return SIZE_MAX; //null terminator
    size_t len = strcspn(src, "  \n");
    *dest = malloc((len + 1)*sizeof(typeof(**dest)));
    strncpy(*dest, src, len);
    (*dest)[len] = '\0';
    return len + 1;
}