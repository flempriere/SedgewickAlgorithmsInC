/*
Program 1.2: Quick Union solution to the connectivity problem

- Unions are constant time
- finds are linear time

- Unions achieved by building trees, connect a[p] -> q etc. 
- Find now requires us to traverse the root
- Quick Union is generally faster than Quick Find -> don't need to traverse
- all array.
*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Input pair values must be less than N
 * 
 */
#define N 10000u

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

    for (size_t i = 0; i < N; i++) id[i] = i;
    while(scanf("%zu %zu\n", &p, &q) == 2) {
        if (p >= N || q >= N) continue; //bounds checking
        size_t i, j;

        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) continue;
        id[i] = j;
        printf(" %zu %zu\n", p, q);
    }
    return EXIT_SUCCESS;
}