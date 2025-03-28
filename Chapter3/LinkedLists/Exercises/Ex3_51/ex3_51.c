/*
Exercise 3.51

Run empirical studies comparing the running time of the
memory allocation functions in Program 3.14 with malloc
and free (Ex3.50) for Program 3.13 with M = 2 and
N = 10^3, 10^4, 10^5, 10^6.

This program will output the timings
*/

#ifdef USE_V2_INTERFACE
    #include "../Ex3_47/List_v3.h"
    constexpr bool new_interface = true;
#else
    #include "../../Examples/Program3_12-14_ListImplementation/List.h"
    constexpr bool new_interface = false; 
#endif

#include <stdio.h>
#include <stdlib.h>
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"

/**
 * @brief First value of N for test cases,
 * each successive case is 10x larger
 * 
 */
constexpr size_t INIT_N = 10000u;

/**
 * @brief Number of N cases to test
 * 
 * @see INIT_N
 * 
 */
constexpr size_t N_CASES = 4u;

/**
 * @brief Value of M for test case
 * 
 */
constexpr size_t DEFAULT_M = 2u;

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

    register size_t const M = DEFAULT_M;
    register size_t N = INIT_N;
    
    RAND_SEED_TIME;

    printf("Running with %s list\n", (new_interface) ? "ex3.50" : "program3_14");
    
    for (register size_t i = 0; i < N_CASES; i++, N *= 10) {
    
    printf("Test Case: M: %zu, N: %zu", M, N);
    register clock_t tic = clock();
    #ifndef USE_V2_INTERFACE
        LISTinit_nodes(N); //needed for the original allocation
    #endif
        register LISTNode* x = LISTnew_node(1);
        for (register size_t i = 2; i <= N; i++) {
            LISTNode* t = LISTnew_node(i);
            LISTinsert_next(x, t);
            x = t;
        }
        while(x != LISTnext(x)) {
            for (register size_t i = 1; i < M; i++) x = LISTnext(x);
            LISTfree_node(LISTdelete_next(x));
        }
        register clock_t toc = clock();
        printf("\t Time: %Lg\n", CAST(long double)(toc - tic) / CLOCKS_PER_SEC);

        #ifndef USE_V2_INTERFACE
            LISTdeinit_list();
        #else 
            LISTfree_all_nodes();
        #endif
    }

    return EXIT_SUCCESS;
}