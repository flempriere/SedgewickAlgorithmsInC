/**
 * @file ex3_12.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3-12.
 *
 *Implement the seive of eratosthenes using an array of char and an array of
 *bits. Compare the differences in time and space.
 *
 * Bool has the same size as a char, so we'll only focus on a bit implementation
 *
 * Our bit implementation is slower!
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Utility.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Largest Number we check for primality
 *
 */
constexpr size_t N = 1000000u;

/**
 * @brief Sieve of Eratosthenes array
 *
 */
bool a[N];

/**
 * @brief type used as the building blocks of the
 * bit array. Exercise: change and compare the result.
 *
 */
typedef unsigned int bit_component;
/**
 * @brief Mask for bit implementation.
 *
 */
constexpr bit_component MASK = 0x01u;

/**
 * @brief Number of bits per component of the bit array
 *
 */
constexpr size_t BITS_PER_COMPONENT = (sizeof(typeof(MASK)) * CHAR_BIT);

/**
 * @brief Number of components in bit array.
 *
 */
constexpr size_t NCOMPONENTS =
    N / (BITS_PER_COMPONENT) + ((N % BITS_PER_COMPONENT) ? 1 : 0);
/**
 * @brief Pointer for Bit Sieve array
 *
 */
bit_component BITa[NCOMPONENTS];

/**
 * @brief Perform the Sieve of Erasthothenes calculation
 * using a boolean array.
 *
 * @pre a[i] = 0 for all i < N
 * @pre The indices [0, N) are valid in the array a.
 * @post a[i] = 1 if i is prime else 0.
 */
static inline void sieve_of_erastothenes_bool(void) {
    for (register size_t i = 2; i < N; i++) {
        if (a[i]) {
            for (register size_t j = i; i * j < N; j++) a[i * j] = 0;
        }
    }
}

/**
 * @brief Indicate if the i-th bit of the bit array is set.
 *
 * @param i index of the bit to check.
 * @return true if the bit is set else
 * @return false
 */
static inline bool BITa_ith_bit(size_t i) {
    return BITa[i / BITS_PER_COMPONENT] & (MASK << (i % BITS_PER_COMPONENT));
}

/**
 * @brief Perform the Sieve of Erasthothenes calculation
 * using a bit array.
 *
 * @pre a[i] = 0 for all i < N
 * @pre The indices [0, N) are valid in the array a.
 * @post a[i] = 1 if i is prime else 0.
 */
static inline void sieve_of_erastothenes_bit(void) {
    for (register size_t i = 2; i < N; i++) {
        if (BITa_ith_bit(i)) {
            for (register size_t j = i; i * j < N; j++) {
                BITa[(i * j) / BITS_PER_COMPONENT] &=
                    ~(MASK << ((i * j) % BITS_PER_COMPONENT));
            }
        }
    }
}

/**
 * @brief Time the runtime of a function.
 *
 * @param f
 * @return long double
 */
long double time_function(void (*const f)(void)) {
    register clock_t const tic = clock();
    (*f)();
    register clock_t const toc = clock();

    return CAST(long double)(toc - tic) / CLOCKS_PER_SEC;
}
/**
 * @brief Compares a bit-indexed implementation of
 * the sieve with a bool based implementation.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    // set up bool array
    for (register size_t i = 2; i < N; i++) a[i] = true;
    printf("Time taken for char array: %Lf\n",
           time_function(sieve_of_erastothenes_bool));

    // using bit array

    // turn on all bits
    for (register size_t i = 0; i < NCOMPONENTS; i++) {
        for (register size_t j = 0; j < BITS_PER_COMPONENT; j++) {
            BITa[i] |= MASK << j;
        }
    }
    printf("Time taken for bit implementation array: %Lf\n",
           time_function(sieve_of_erastothenes_bit));

    for (register size_t i = 2; i < N; i++) { assert(a[i] == BITa_ith_bit(i)); }
    printf("=== Approaches Agree===\n");

    return EXIT_SUCCESS;
}
