/*
Exercise 1-22: Generate random pairs of integers between 0 and N - 1
loop until N - 1 unions are performed. Print the total number of edges
*/

#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>

#define MAX_VERTEX 100000

#define RAND_INT(N) rand() % (N)

#define SWAP(x,y) do {  \
    size_t _t = x;      \
    x = y;              \
    y = _t;             \
} while(0)              \


int main(int argc, char *argv[argc + 1]) {

    size_t N;
    printf("argc: %d\n", argc);
    if (argc != 2) {
        printf("Error: call structure is ./ex1_22 N\n");
        return 1;
    }
    N = strtoul(argv[1], NULL, 0);
    N = (N <= MAX_VERTEX) ? N : MAX_VERTEX;
    printf("N: %zu\n", N);

    size_t id[MAX_VERTEX];
    size_t sz[MAX_VERTEX];

    for (size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    srand(time(NULL));
    size_t p = RAND_INT(N), q = RAND_INT(N);
    size_t n_edges = 1;
    for (size_t n_unions = 0; n_unions < N - 1; 
        p = RAND_INT(N), q = RAND_INT(N), n_edges++) {

        size_t i, j;
        for (i = p; i != id[i]; i = id[i]) {id[i] = id[id[i]];}
        for (j = q; j != id[j]; j = id[j]) {id[j] = id[id[j]];}

        if (i == j) continue;
        n_unions++;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        printf(" %zu %zu\n", p, q);
    }
    printf("N edges: %zu\n", n_edges);
    return 0; 
}