/*
Program 1.3 Weighted Quick Union

Improve the speed of find by maintaining an array sz[] containing the sizes
of all the root nodes. When performing a union, the smaller tree is attached
to the larger tree.
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
    char line[MAXLINE];

    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (fgets(line, sizeof(line), stdin) &&
           sscanf(line, "%zu %zu", &p, &q) == 2) {
        size_t i;
        size_t j;
        if (p >= N || q >= N) continue;    // bounds checking
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);

        if (i == j) continue;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];

        printf(" %zu %zu\n", p, q);
    }
    return read_ended_successfully(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}