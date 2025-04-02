/*
Program 1.1: Quick-find solution to connectivity problem

Reads a sequence of pairs of no-negative integers less than N
from standard input.

The pair p q means connect p to q

arr[N] has the property that id[p] and id[q] are equal iff p and q are
connected

Complexity: - Each union is linear in length since
we have to update all entries
            - Each find is constant time, we just test
            equality.
*/

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
    char line[MAXLINE];    // input buffer

    for (register size_t i = 0; i < N; i++) id[i] = i;
    while (fgets(line, sizeof(line), stdin) &&
           sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;    // bounds checking
        if (id[p] == id[q]) continue;
        register size_t t = id[p];
        for (register size_t i = 0; i < N; i++) {
            if (id[i] == t) id[i] = id[q];
        }

        printf(" %zu %zu\n", p, q);
    }
    return read_ended_successfully(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}