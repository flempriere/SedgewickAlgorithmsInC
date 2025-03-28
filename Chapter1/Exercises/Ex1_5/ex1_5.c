/*
Exercise 1-5:
    - show that state of the id array at each stage of reading from
    sample_data.dat.
    - count the total number of array accesses (overall and per edge)
    - Using Quick Union algorithm
*/
#include "../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Input pair values must be less than N
 *
 */
constexpr size_t N = 10u;

/**
 * @brief size of the input buffer for fgets.
 *
 */
constexpr size_t MAXLINE = 100u;

/**
 * @brief Prints the first @len elements of an array a
 *
 * @param len size_t type, length of the array
 * @param a size_t type, must be of size at least len.
 */
void printArr(size_t const len, size_t a[len]);

/**
 * @brief Reads input pairs `p,q < N` from
 * standard input and performs a union operation. If
 * `p` and `q` where not already connected they are
 * printed to output.
 *
 * @exception if p or q is not less than N the input
 * pair is ignored
 *
 * @return EXIT_SUCCESS on exit.
 *
 */
int main(void) {
    size_t p;
    size_t q;
    size_t id[N];
    register size_t tot_accesses = 0;
    char line[MAXLINE];

    for (register size_t i = 0; i < N; i++) id[i] = i;

    while (fgets(line, sizeof(line), stdin) &&
           sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;

        register size_t i;
        register size_t j;
        register size_t n_acc = 0;

        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) goto updateArrayAccesses;

        id[i] = j;
        n_acc++;

        printf(" %zu %zu\n", p, q);
        printArr(N, id);
    updateArrayAccesses:
        printf("array acceses for (%zu, %zu): %zu\n", p, q, n_acc);
        tot_accesses += n_acc;
    }
    printf("Number of id array accesses: %zu\n", tot_accesses);
    return read_ended_successfully(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void printArr(size_t const len, size_t a[len]) {
    for (register size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
