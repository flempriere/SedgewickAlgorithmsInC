/*
Exercise 3.18

Empirically determine the number of random positive integers less than 1000
that you can expect to generate before getting a repeated value.

This implementation repeats the experiment M times where M is a command line
argument.

*/
#include <tgmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Exclusive upper bound
 * for maximum number we can generate
 * 
 */
#define MAX_NUM 1000

/**
 * @brief Generates a random nonnegative
 * integer less than @ub.
 * 
 * @param ub size_t <= RAND_MAX
 * @return size_t 
 */
size_t randNum(size_t ub);

/**
 * @brief Generates random positive integers
 * up to MAX_NUM until a value is repeated.
 * 
 * This process is repeated @M times and the
 * average and std. dev computed.
 * 
 * @param argv[1] M 
 * @return EXIT_SUCCESS on successful execution else
 * @return EXIT_FAILURE
 * 
 * @see MAX_NUM
 */
int main(int argc, char* argv[argc + 1]) {

    if (argc != 2) {
        fprintf(stderr, "Error: call structure is ./ex3_18 M\n");
        return EXIT_FAILURE;
    }
    size_t a[MAX_NUM];
    size_t M = strtoull(argv[1], NULL, 0);
    srand(time(nullptr));
    double m1 = 0.0;
    double m2 = 0.0;

    for (size_t k = 0; k < M; k++) {
        size_t nGen = 0;
        for (size_t i = 0; i < MAX_NUM; i++) a[i] = 0;
        while(true) {
            size_t i = randNum(MAX_NUM);
            if (a[i]++) {
                break;
            }
            nGen++;
        }
        m1 += ((double) nGen) / M;
        m2 += ((double) nGen * nGen) / M;
    }
    printf("===== Results, M = %zu =====\n", M);
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1*m1));
    return EXIT_SUCCESS;
}

size_t randNum(size_t ub) {
    return rand() % ub;
}