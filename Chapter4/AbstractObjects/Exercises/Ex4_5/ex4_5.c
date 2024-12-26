/**
 * @file ex4_5.c
 * @author Felix Lempriere
 * @brief Reimplements Program 3.2 to use a generic
 * object interface allowing the same .c file to be
 * used for any Item supporting + and / operations
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <tgmath.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>
#include "Item.h"


/**
 * @brief Calculate the average and standard deviation
 * of a collection of random numbers. 
 * 
 * @param argv[1] number of random numbers to generate
 * 
 * @return EXIT_SUCCESS on success, else EXIT_FAILURE
 * 
 */
int main(int argc, char* argv[argc + 1]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./app N\n");
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], nullptr, 0);
    double m1 = 0.0;
    double m2 = 0.0;

    Item x;
    srand(time(nullptr));

    for (size_t i = 0; i < N; i++) {
        x = ITEMrand();
        m1 += ((double) x)/N;
        m2 += ((double) x*x) / N; 
    }
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1*m1));

    return EXIT_SUCCESS;
}