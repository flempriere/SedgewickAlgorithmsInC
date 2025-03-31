/*
Exercise 3.10: Define a datatype for triangles in the unit square, including
a function that computes the area of a triangle. Then write a client program
that generates random triples of pairs of floats between 0 and 1 and computes
empircally the average area of the triangles generated.

*/
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Statistics.h"
#include "src/Triangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Number of N values to test over.
 *
 */
constexpr size_t N_CASES = 5u;

/**
 * @brief Initial value of N for test cases
 *
 */
constexpr size_t N_INIT = 10u;

/**
 * @brief Generate a random triangle and return its area.
 *
 * Wrapper interface suitable for the Statistics calculate_statistics method.
 * @return double
 */
static inline double rand_triangle_area(void);
/**
 * @brief For N = N_INIT, 10(N_INIT), 100(N_INIT)
 * Generates N random triangles, calculates their
 * area, and determines the avg and std.dev statistics.
 *
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t N = N_INIT;

    RAND_SEED_TIME;

    for (register size_t j = 0; j < N_CASES; N *= 10, j++) {
        register STATSmeasures sm =
            STATScalculate_statistics(rand_triangle_area, N);

        STATSsummary_print(sm, "Running using N: %zu", N);
    }

    return EXIT_SUCCESS;
}

static inline double rand_triangle_area(void) {
    return TRIANGLEarea(TRIANGLErandom());
}