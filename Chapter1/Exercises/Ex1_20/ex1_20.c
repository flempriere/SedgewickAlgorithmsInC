/*
Exercise 1-20:
    - Modify Weighted Union to use the 'height' of the tree
    - Compare the timing of this with Program 1.3
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
    register size_t n_acc = 0;    // number of array accesses.
    char line[MAXLINE];

    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 0;
    }
    while (fgets(line, sizeof(line), stdin) &&
           sscanf(line, "%zu %zu", &p, &q) == 2) {
        size_t i;
        size_t j;
        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) continue;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] = MAX(sz[i], sz[j] + 1);
        n_acc++;
        printf(" %zu %zu\n", p, q);
        // printArr(N, id);
    }
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void printArr(size_t const len, size_t a[len]) {
    for (register size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
