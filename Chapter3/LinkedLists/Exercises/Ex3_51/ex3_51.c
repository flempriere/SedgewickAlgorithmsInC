/*
Exercise 3.51

Run empirical studies comparing the running time of the
memory allocation functions in Program 3.14 with malloc
and free (Ex3.50) for Program 3.13 with M = 2 and
N = 10^3, 10^4, 10^5, 10^6.

This program will output the timings
*/

#ifdef USE_V2_INTERFACE
    #include "../Ex3_50/List_v2.h"
    constexpr bool new_interface = true;
#else
    #include "../../Examples/Program3_12-14_ListImplementation/List.h"
    constexpr bool new_interface = false; 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Defines which interface is in use
 * set to 1 for original program 3.14 interface
 * else 0 for updated interface.
 * 
 */
#define LIST_MODE 0

/**
 * @brief First value of N for test cases,
 * each successive case is 10x larger
 * 
 */
#define INIT_N 10000

/**
 * @brief Number of N cases to test
 * 
 * @see INIT_N
 * 
 */
#define N_CASES 4

/**
 * @brief Value of M for test case
 * 
 */
#define DEFAULT_M 2

/**
 * @brief Test the runtime for various memory allocation
 * methods using a list interface. 
 * 
 * Runs the Josephus problem for a set M considering N_CASES
 * where starting from INIT_N each case is then 10x larger
 * than the previous.
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc+1]) {

    size_t M = DEFAULT_M;
    size_t N = INIT_N;
    srand(time(nullptr));
    printf("Running with %s list\n", (new_interface) ? "ex3.50" : "program3_14");
    for (size_t i = 0; i < N_CASES; i++, N *= 10) {
    printf("Test Case: M: %zu, N: %zu", M, N);
    clock_t tic = clock();
    #ifndef USE_V2_INTERFACE
        LISTinitNodes(N); //needed for the original allocation
    #endif
        LISTNode* x = LISTnewNode(1);
        for (size_t i = 2; i <= N; i++) {
            LISTNode* t = LISTnewNode(i);
            LISTinsertNext(x, t);
            x = t;
        }
        while(x != LISTnext(x)) {
            for (size_t i = 1; i < M; i++) x = LISTnext(x);
            LISTfreeNode(LISTdeleteNext(x));
        }
        clock_t toc = clock();
        printf("\t Time: %g\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    }
    return EXIT_SUCCESS;
}