/*
Exercise 1-23: Generate random pairs of integers between 0 and N - 1
loop until N - 1 unions are performed. Print the total number of edges

This program repeats for N = 100 to 1000 and prints the total number of edges
generated each time.
*/

#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>

#define MAX_VERTEX 1000
#define MIN_VERTEX 100

#define RAND_INT(N) rand() % (N)

#define SWAP(x,y) do {  \
    size_t _t = x;      \
    x = y;              \
    y = _t;             \
} while(0)              \

void printGraph(size_t start, size_t len, size_t a[len]);

int main(int argc, char *argv[argc + 1]) {

    size_t id[MAX_VERTEX];
    size_t sz[MAX_VERTEX];
    size_t result[MAX_VERTEX + 1];



    srand(time(NULL));
    printf("N\t # Edges\n");

    for (size_t N = MIN_VERTEX; N <= MAX_VERTEX; N++) {

        for (size_t i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        
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
        }
        result[N] = n_edges;
    }
    printGraph(MIN_VERTEX, MAX_VERTEX + 1, result);
    return 0; 
}

void printGraph(size_t start, size_t len, size_t a[len]) {
    while(start++ < len) printf("%zu : %zu\n", start - 1, a[start - 1]);

}