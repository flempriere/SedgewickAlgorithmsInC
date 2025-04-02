/*
Exercise 1-7:
    - show that state of the id array at each stage of reading from
    sample_data.dat.
    - count the total number of array accesses (overall and per edge)
    - Using Weighted Quick Union algorithm
*/

#include "MacroLibrary/Generic.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Input pair values must be less than N
 *
 */
constexpr size_t N = 10000u;

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
int main(int argc, char* argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q;
    register size_t tot_acc = 0;
    char line[MAXLINE];

    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (fgets(line, sizeof(line), stdin) &&
           sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;

        register size_t n_acc = 0;

        size_t i;
        size_t j;
        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) goto updateArrayAccesses;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        n_acc += 5;
        printf(" %zu %zu\n", p, q);
        printArr(N, id);
    updateArrayAccesses:
        printf("array acceses for (%zu, %zu): %zu\n", p, q, n_acc);
        tot_acc += n_acc;
    }
    printf("Total accesses: %zu\n", tot_acc);
    return read_ended_successfully(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void printArr(size_t const len, size_t a[len]) {
    for (register size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
