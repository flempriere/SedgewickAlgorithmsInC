/*
Exercise 1-23: Generate random pairs of integers between 0 and N - 1
loop until N - 1 unions are performed. Print the total number of edges

This program repeats for N = 100 to 1000 and prints the total number of edges
generated each time.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @brief maximum value of a vertex across all runs
 * 
 */
#define MAX_VERTEX 1000
/**
 * @brief smallest maximum value for any run.
 * @see MAX_VERTEX
 * 
 */
#define MIN_VERTEX 100

/**
 * @brief generates a random number between 0 and @N
 * @param N unsigned integer <= RAND_MAX 
 * 
 */
#define RAND_INT(N) rand() % (N)

/**
 * @brief swap's x and y
 * 
 * @param x first item to be swapped
 * @param y second item to be swapped
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
 * @brief Plots the number of edges needed to connect N items
 * for start <= N < len
 * 
 * @param start min value of N
 * @param len  max value of N
 * @param a array storing results, indexes start -> len must be
 * valid
 */
void printGraph(size_t start, size_t len, size_t a[len]);


/**
 * @brief Generates a table of the number of edges needed to connect
 * N items for 100 <= N <= 1000 using Weighted Union with path compression
 * by halving assuming random input pairs.
 * 
 * @return EXIT_SUCCESS
 */
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
    return EXIT_SUCCESS; 
}

void printGraph(size_t start, size_t len, size_t a[len]) {
    while(start++ < len) printf("%zu : %zu\n", start - 1, a[start - 1]);
}