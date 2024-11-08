/*
Program 1.4

Improves Weighted Quick Union by implementing path compression by halving
for find operations.

Path compression by halving: During find operations every node touched is has
its parent replaced by its grandparent.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Input pair values must be less than N
 * 
 */
#define N 10000

/**
 * @brief swap's x and y
 * 
 * @param x first item to be swapped
 * @param y first item to be swapped
 * 
 * Uses C23 typeof_unqual operator to
 * determine types of @x and @y for
 * temporary variable _t.
 */
#define SWAP(x,y) do {  \
    typeof_unqual(x) _t = x;      \
    x = y;              \
    y = _t;             \
} while(0)              \


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
int main(int argc, char *argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q;

    for (size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%zu %zu\n", &p , &q) == 2) {

        if (p >= N || q >= N) continue;

        size_t i, j;
        for (i = p; i != id[i]; i = id[i]) {id[i] = id[id[i]];}
        for (j = q; j != id[j]; j = id[j]) {id[j] = id[id[j]];}

        if (i == j) continue;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        printf(" %zu %zu\n", p, q);
    }
    return EXIT_SUCCESS; 
}