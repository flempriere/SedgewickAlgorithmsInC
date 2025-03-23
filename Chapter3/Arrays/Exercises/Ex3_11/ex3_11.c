/*
Program 3.11
    Suppose that a is declared as int a[99], give the array contents after
    the following statements
    for (i = 0; i < 99; i++) a[i] = 98-i;
    for (i = 0; i < 99; i++) a[i] = a[a[i]];
*/

#include <stdio.h>
#include <stdlib.h>

constexpr size_t size = 99u;

/**
 * @brief Perform one pass over the array a
 * settings a[i] to 98-i, then pass again
 * setting a[i] to a[a[i]]. Then prints
 * the array contents.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    size_t a[size];
    for (register size_t i = 0; i < size; i++) a[i] = size - 1 - i;
    for (register size_t i = 0; i < size; i++) a[i] = a[a[i]];

    for (register size_t i = 0; i < size; i++) { printf("[%zu]", i); }
    printf("\n");

    for (register size_t i = 0; i < size; i++) { printf(" %zu ", a[i]); }
    printf("\n");
    return EXIT_SUCCESS;
}