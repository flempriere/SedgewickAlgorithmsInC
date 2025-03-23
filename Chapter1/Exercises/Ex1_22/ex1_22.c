/*
Exercise 1-22: Generate random pairs of integers between 0 and N - 1
loop until N - 1 unions are performed. Print the total number of edges

Repeat for N = 10^3, 10^4, 10^5, 10^6
*/

#include "../../../MacroLibrary/Generic.h"
#include "../../../MacroLibrary/Random.h"
#include "../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief max value of a vertex across any run
 *
 */
constexpr size_t MAX_VERTEX = 1000000u;

/**
 * @brief number of different values of N to use
 *
 */
constexpr size_t N_CASES = 4u;

/**
 * @brief ID array for union find of size MAX_VERTEX
 *
 * @see MAX_VERTEX
 */
static size_t id[MAX_VERTEX];
/**
 * @brief sz array for union find of size MAX_VERTEX
 * @see MAX_VERTEX
 */
static size_t sz[MAX_VERTEX];

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
int main(int argc, char* argv[argc + 1]) {
    // loop through test cases
    for (register size_t n = 1000, n_cases = 0u; n_cases < N_CASES;
         n *= 10, n_cases++) {
        // init array
        for (register size_t i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        RAND_SEED_TIME;

        register size_t p = RAND_SIZE_T(n);
        register size_t q = RAND_SIZE_T(n);

        register size_t n_edges = 1;
        for (register size_t n_unions = 0; n_unions < n - 1;
             p = RAND_SIZE_T(n), q = RAND_SIZE_T(n), n_edges++) {
            register size_t i;
            register size_t j;
            for (i = p; i != id[i]; i = id[i]) { id[i] = id[id[i]]; }
            for (j = q; j != id[j]; j = id[j]) { id[j] = id[id[j]]; }

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