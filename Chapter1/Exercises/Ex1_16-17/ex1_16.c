/*
Exercise 1-16 and 1-17
    - Implement full path compression
    - show that state of the id array at each stage of reading from
    sample_data.dat.
    - count the total number of array accesses (overall and for each edge)
*/

#include "../../../MacroLibrary/Generic.h"
#include "../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Input pair values must be less than N
 *
 */
constexpr size_t N = 16u;

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
    register size_t tot_access = 0;    // counter for number of array accesses.
    char line[MAXLINE];

    // array initialisation
    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    while (fgets(line, sizeof(line), stdin) &&
           sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;
        register size_t i;
        register size_t j;
        register size_t n_access = 0;
        // find the root
        for (i = p; n_access += 1, i != id[i]; i = id[i], n_access += 1);

        // traverse tree and compress
        for (register size_t k = p; k != i;) {
            register size_t nk = id[k];
            id[k] = i;
            n_access += 2;
            k = nk;
        }
        // repeat for other value
        for (j = q; n_access += 1, j != id[j]; j = id[j], n_access += 1);

        for (register size_t l = q; l != j;) {
            register size_t nl = id[l];
            id[l] = j;
            n_access += 2;
            l = nl;
        }
        if (i == j) { goto updateArrayAccesses; }

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        n_access += 5;
        printf(" %zu %zu\n", p, q);
        printArr(N, id);
    updateArrayAccesses:
        printf("array acceses for (%zu, %zu): %zu\n", p, q, n_access);
        tot_access += n_access;
    }
    printf("id array accesses: %zu\n", tot_access);
    return read_ended_successfully(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void printArr(size_t const len, size_t a[len]) {
    for (register size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
