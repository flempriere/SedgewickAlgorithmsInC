/*
Exercise 3_4 implementation utilising num.c and num.h from Program 3.2
based on the implementations in exercise 3.2 and exercise 3.3
*/
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"
#include "src/Number_v2.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Number of test cases for N
 *
 */
constexpr size_t N_CASES = 4u;
/**
 * @brief Number of test cases for r
 *
 */
constexpr size_t R_CASES = 3u;

/**
 * @brief Starting value for N
 *
 */
constexpr size_t N_INIT = 10000u;

/**
 * @brief Starting value for R
 *
 */
constexpr Number R_INIT = 2u;

constexpr size_t RESULTS_ARR_SIZE = N_CASES * R_CASES;

/**
 * @brief prints the statistics in a common format.
 *
 * @param s header string to print.
 * @param n Number of Numbers to generate.
 * @param r Upper bound on numbers to generate.
 * @param avg average
 * @param sd standard deviation
 */
void printStatistics(char s[static 1], size_t n, Number r, double avg,
                     double sd);

/**
 * @brief Calculate the statistics using a given rng. Bool flag notes if
 * we want to add this to our stats array or subtract it if we want to
 * calculate the difference.
 *
 * @param rng Number generation function.
 * @param Aavg array to store the avg results in,
 * @param Astd_dev array to store the std_dev results in,
 * @param subtract Marks if we subtract the results from existing statistics
 * in the array.
 */
void calculateStatistics(Number rng(Number ub),
                         double Aavg[static RESULTS_ARR_SIZE],
                         double Astd_dev[static RESULTS_ARR_SIZE],
                         bool subtract);
/**
 * @brief Test the random number generator
 * using both the methods given in Exercise 3.2
 * and Exercise 3.3.
 *
 * Starts and R = R_INIT, and N = N_INIT, and
 * each successive N case is 10x larger. Each
 * successive R case is squared.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t n = N_INIT;
    register Number r = R_INIT;

    double Davg[RESULTS_ARR_SIZE];
    double Dstd_dev[RESULTS_ARR_SIZE];

    RAND_SEED_TIME;

    printf("Testing rand() with modulus\n");
    calculateStatistics(NUMBERrandom_modulus, Davg, Dstd_dev, false);

    printf("Testing rand() via rescaled doubles\n");
    calculateStatistics(NUMBERrandom_truncate, Davg, Dstd_dev, true);

    printf("Comparing the difference: \n");

    n = N_INIT;
    for (register size_t i = 0; i < N_CASES; i++, n *= 10) {
        r = R_INIT;
        for (register size_t j = 0; j < R_CASES; j++, r *= r) {
            printStatistics("Difference for", n, r,
                            Davg[ARRAY_2D_IDX(i, j, R_CASES)],
                            Dstd_dev[ARRAY_2D_IDX(i, j, R_CASES)]);
        }
    }

    return EXIT_SUCCESS;
}

void printStatistics(char s[static 1], size_t n, Number r, double avg,
                     double sd) {
    printf("%s N: %zu, R: %u\n", s, n, r);
    printf("       Average: %f\n", avg);
    printf("Std. deviation: %f\n", sd);
}

void calculateStatistics(Number rng(Number ub),
                         double Aavg[static RESULTS_ARR_SIZE],
                         double Astd_dev[static RESULTS_ARR_SIZE],
                         bool subtract) {
    register size_t n = N_INIT;
    for (register size_t i = 0; i < N_CASES;
         n *= 10, i++) {    // iterate over N values
        register Number r = R_INIT;

        for (register size_t j = 0; j < R_CASES;
             r *= r, j++) {    // iterate over r values
            register double m1 = 0.0;
            register double m2 = 0.0;

            for (register size_t k = 0; k < n; k++) {
                register Number x = rng(r);
                m1 += (x) / CAST(double) n;
                m2 += ((double) x * x) / CAST(double) n;
            }
            register double std_dev = sqrt(m2 - m1 * m1);
            printStatistics("Results for", n, r, m1, std_dev);
            if (subtract) {
                Aavg[ARRAY_2D_IDX(i, j, R_CASES)] -= m1;
                Astd_dev[ARRAY_2D_IDX(i, j, R_CASES)] -= std_dev;
            } else {
                Aavg[ARRAY_2D_IDX(i, j, R_CASES)] = m1;
                Astd_dev[ARRAY_2D_IDX(i, j, R_CASES)] = std_dev;
            }
        }
        printf("\n");
        r = R_INIT;
    }
}