/*
Exercise 1-22: Generate random pairs of integers between 0 and N - 1
loop until N - 1 unions are performed. Print the total number of edges

Repeat for N = 10^3, 10^4, 10^5, 10^6
*/

#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @brief Make a cast explicit
 * 
 */
#define CAST(T) (T)
/**
 * @brief max value of a vertex across any run
 * 
 */
#define MAX_VERTEX 1000000u

/**
 * @brief number of different values of N to use
 * 
 */
#define N_CASES 4u

/**
 * @brief generates a random number between 0 and @N
 * @param N unsigned integer <= RAND_MAX 
 * 
 */
#define RAND_SIZE_T(N) (CAST(size_t) rand() % (N))

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
 * @brief ID array for union find of size MAX_VERTEX
 * 
 * @see MAX_VERTEX
 */
size_t id[MAX_VERTEX];
/**
 * @brief sz array for union find of size MAX_VERTEX
 * @see MAX_VERTEX
 */
size_t sz[MAX_VERTEX];


/**
 * @brief Performs a series of tests on Weighted Union Find with Path
 * Compression by halving.
 * 
 * Loops through N = 10^3, 10^4, 10^5, 10^6
 * For each value of N, generates random integers between
 * 0 and N - 1 and loops until N - 1 `unions` are performed.
 * 
 * Prints the total number of edges generated for each test case
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[argc + 1]) {

    //loop through test cases
    for (size_t n = 1000, n_cases = 0u; n_cases < N_CASES; n *= 10, n_cases++) {

        //init array
        for (size_t i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        srand( CAST(unsigned int) time(NULL));
        size_t p = RAND_SIZE_T(n), q = RAND_SIZE_T(n);
        size_t n_edges = 1;
        for (size_t n_unions = 0; n_unions < n - 1; 
            p = RAND_SIZE_T(n), q = RAND_SIZE_T(n), n_edges++) {

            size_t i, j;
            for (i = p; i != id[i]; i = id[i]) {id[i] = id[id[i]];}
            for (j = q; j != id[j]; j = id[j]) {id[j] = id[id[j]];}

            if (i == j) continue;
            n_unions++;

            if (sz[i] < sz[j]) SWAP(i, j);
            id[j] = i;
            sz[i] += sz[j];
        }
        printf("N: %8zu\tEdges: %8zu\n", n, n_edges);
    }
    return EXIT_SUCCESS; 
}