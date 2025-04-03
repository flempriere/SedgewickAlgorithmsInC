/*
Program 1.2: Quick Union solution to the connectivity problem

- Unions are constant time
- finds are linear time

- Unions achieved by building trees, connect a[p] -> q etc.
- Find now requires us to traverse the root
- Quick Union is generally faster than Quick Find -> don't need to traverse
- all array.
*/

#include "MacroLibrary/Defaultfgets.h"
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
int main(void) {
    size_t p;
    size_t q;
    size_t id[N];
    char line[MAXLINE];

    for (register size_t i = 0; i < N; i++) id[i] = i;
    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;    // bounds checking
        register size_t i;
        register size_t j;

        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) continue;
        id[i] = j;

        printf(" %zu %zu\n", p, q);
    }
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}